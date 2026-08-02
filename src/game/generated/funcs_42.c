#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void Thread_ResetMqValidCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C13B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C13BC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C13C0: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800C13C4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C13C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C13CC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800C13D0: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800C13D4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C13D8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800C13DC: addiu       $t7, $t7, 0x1950
    ctx->r15 = ADD32(ctx->r15, 0X1950);
    // 0x800C13E0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C13E4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C13E8: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800C13EC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C13F0: nop

    // 0x800C13F4: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x800C13F8: lbu         $t0, 0x2E9($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X2E9);
    // 0x800C13FC: nop

    // 0x800C1400: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x800C1404: bne         $t1, $zero, L_800C1414
    if (ctx->r9 != 0) {
        // 0x800C1408: nop
    
            goto L_800C1414;
    }
    // 0x800C1408: nop

    // 0x800C140C: b           L_800C1434
    // 0x800C1410: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1434;
    // 0x800C1410: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C1414:
    // 0x800C1414: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800C1418: nop

    // 0x800C141C: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x800C1420: sw          $zero, 0x2D9($at)
    MEM_W(0X2D9, ctx->r1) = 0;
    // 0x800C1424: b           L_800C1434
    // 0x800C1428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C1434;
    // 0x800C1428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C142C: b           L_800C1434
    // 0x800C1430: nop

        goto L_800C1434;
    // 0x800C1430: nop

L_800C1434:
    // 0x800C1434: jr          $ra
    // 0x800C1438: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C1438: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006E904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E90C: jal         0x80061348
    // 0x8006E910: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E910: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_0:
    // 0x8006E914: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006E918: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006E91C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E920: beq         $v0, $zero, L_8006E938
    if (ctx->r2 == 0) {
        // 0x8006E924: nop
    
            goto L_8006E938;
    }
    // 0x8006E924: nop

    // 0x8006E928: jal         0x80061348
    // 0x8006E92C: addiu       $a0, $zero, 0x2C6
    ctx->r4 = ADD32(0, 0X2C6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E92C: addiu       $a0, $zero, 0x2C6
    ctx->r4 = ADD32(0, 0X2C6);
    after_1:
    // 0x8006E930: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E934: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006E938:
    // 0x8006E938: b           L_8006E948
    // 0x8006E93C: nop

        goto L_8006E948;
    // 0x8006E93C: nop

    // 0x8006E940: b           L_8006E948
    // 0x8006E944: nop

        goto L_8006E948;
    // 0x8006E944: nop

L_8006E948:
    // 0x8006E948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E94C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E950: jr          $ra
    // 0x8006E954: nop

    return;
    // 0x8006E954: nop

;}
RECOMP_FUNC void func_80065E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065E9C: jal         0x80061348
    // 0x80065EA0: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065EA0: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80065EA4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065EA8: b           L_80065EB8
    // 0x80065EAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065EB8;
    // 0x80065EAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065EB0: b           L_80065EB8
    // 0x80065EB4: nop

        goto L_80065EB8;
    // 0x80065EB4: nop

L_80065EB8:
    // 0x80065EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065EC0: jr          $ra
    // 0x80065EC4: nop

    return;
    // 0x80065EC4: nop

;}
RECOMP_FUNC void func_80063F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063F3C: jal         0x80061488
    // 0x80063F40: addiu       $a0, $zero, 0x5DE
    ctx->r4 = ADD32(0, 0X5DE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063F40: addiu       $a0, $zero, 0x5DE
    ctx->r4 = ADD32(0, 0X5DE);
    after_0:
    // 0x80063F44: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063F48: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063F4C: b           L_80063F5C
    // 0x80063F50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063F5C;
    // 0x80063F50: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063F54: b           L_80063F5C
    // 0x80063F58: nop

        goto L_80063F5C;
    // 0x80063F58: nop

L_80063F5C:
    // 0x80063F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063F64: jr          $ra
    // 0x80063F68: nop

    return;
    // 0x80063F68: nop

;}
RECOMP_FUNC void func_8008E184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E184: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008E188: beq         $a1, $zero, L_8008E228
    if (ctx->r5 == 0) {
        // 0x8008E18C: nop
    
            goto L_8008E228;
    }
    // 0x8008E18C: nop

    // 0x8008E190: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008E194: lhu         $t6, 0x24FC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X24FC);
    // 0x8008E198: nop

    // 0x8008E19C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8008E1A0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8008E1A4: lw          $t9, 0x12C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X12C);
    // 0x8008E1A8: nop

    // 0x8008E1AC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8008E1B0: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8008E1B4: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008E1B8: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008E1BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008E1C0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008E1C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008E1C8: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x8008E1CC: nop

    // 0x8008E1D0: bc1f        L_8008E220
    if (!c1cs) {
        // 0x8008E1D4: nop
    
            goto L_8008E220;
    }
    // 0x8008E1D4: nop

L_8008E1D8:
    // 0x8008E1D8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008E1DC: nop

    // 0x8008E1E0: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8008E1E4: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008E1E8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008E1EC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008E1F0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008E1F4: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008E1F8: sw          $t2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r10;
    // 0x8008E1FC: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008E200: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008E204: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8008E208: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008E20C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008E210: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8008E214: nop

    // 0x8008E218: bc1t        L_8008E1D8
    if (c1cs) {
        // 0x8008E21C: nop
    
            goto L_8008E1D8;
    }
    // 0x8008E21C: nop

L_8008E220:
    // 0x8008E220: b           L_8008E2D8
    // 0x8008E224: nop

        goto L_8008E2D8;
    // 0x8008E224: nop

L_8008E228:
    // 0x8008E228: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
L_8008E22C:
    // 0x8008E22C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8008E230: nop

    // 0x8008E234: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8008E238: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8008E23C: lw          $t8, 0x12C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X12C);
    // 0x8008E240: nop

    // 0x8008E244: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8008E248: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8008E24C: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008E250: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008E254: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8008E258: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008E25C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008E260: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8008E264: nop

    // 0x8008E268: bc1f        L_8008E2B8
    if (!c1cs) {
        // 0x8008E26C: nop
    
            goto L_8008E2B8;
    }
    // 0x8008E26C: nop

L_8008E270:
    // 0x8008E270: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008E274: nop

    // 0x8008E278: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8008E27C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008E280: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8008E284: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008E288: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8008E28C: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8008E290: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x8008E294: lwc1        $f10, 0x1B4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x8008E298: lwc1        $f8, 0x1B0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8008E29C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8008E2A0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008E2A4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008E2A8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8008E2AC: nop

    // 0x8008E2B0: bc1t        L_8008E270
    if (c1cs) {
        // 0x8008E2B4: nop
    
            goto L_8008E270;
    }
    // 0x8008E2B4: nop

L_8008E2B8:
    // 0x8008E2B8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8008E2BC: nop

    // 0x8008E2C0: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8008E2C4: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x8008E2C8: bne         $at, $zero, L_8008E22C
    if (ctx->r1 != 0) {
        // 0x8008E2CC: sw          $t5, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r13;
            goto L_8008E22C;
    }
    // 0x8008E2CC: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x8008E2D0: b           L_8008E2D8
    // 0x8008E2D4: nop

        goto L_8008E2D8;
    // 0x8008E2D4: nop

L_8008E2D8:
    // 0x8008E2D8: jr          $ra
    // 0x8008E2DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008E2DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80010150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010150: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80010154: lw          $t6, 0x20C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20C);
    // 0x80010158: nop

    // 0x8001015C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x80010160: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80010164: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80010168: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001016C: lwc1        $f4, 0x28($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X28);
    // 0x80010170: lwc1        $f10, 0x24($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X24);
    // 0x80010174: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80010178: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001017C: swc1        $f16, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f16.u32l;
    // 0x80010180: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x80010184: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80010188: lwc1        $f18, 0x28($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X28);
    // 0x8001018C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80010190: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80010194: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80010198: nop

    // 0x8001019C: bc1f        L_80010200
    if (!c1cs) {
        // 0x800101A0: nop
    
            goto L_80010200;
    }
    // 0x800101A0: nop

    // 0x800101A4: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800101A8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800101AC: lwc1        $f10, 0x24($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X24);
    // 0x800101B0: lwc1        $f17, -0x2B88($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2B88);
    // 0x800101B4: lwc1        $f16, -0x2B84($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B84);
    // 0x800101B8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800101BC: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x800101C0: nop

    // 0x800101C4: bc1f        L_800101F8
    if (!c1cs) {
        // 0x800101C8: nop
    
            goto L_800101F8;
    }
    // 0x800101C8: nop

    // 0x800101CC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800101D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800101D4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800101D8: nop

    // 0x800101DC: swc1        $f18, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f18.u32l;
    // 0x800101E0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800101E4: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800101E8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800101EC: nop

    // 0x800101F0: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800101F4: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_800101F8:
    // 0x800101F8: b           L_8001024C
    // 0x800101FC: nop

        goto L_8001024C;
    // 0x800101FC: nop

L_80010200:
    // 0x80010200: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x80010204: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80010208: lwc1        $f4, 0x24($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X24);
    // 0x8001020C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80010210: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80010214: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80010218: nop

    // 0x8001021C: bc1f        L_8001024C
    if (!c1cs) {
        // 0x80010220: nop
    
            goto L_8001024C;
    }
    // 0x80010220: nop

    // 0x80010224: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80010228: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8001022C: nop

    // 0x80010230: swc1        $f8, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f8.u32l;
    // 0x80010234: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80010238: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8001023C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80010240: nop

    // 0x80010244: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80010248: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
L_8001024C:
    // 0x8001024C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80010250: lh          $t9, 0x721C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X721C);
    // 0x80010254: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80010258: bne         $t9, $at, L_800103CC
    if (ctx->r25 != ctx->r1) {
        // 0x8001025C: nop
    
            goto L_800103CC;
    }
    // 0x8001025C: nop

    // 0x80010260: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80010264: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80010268: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001026C: lwc1        $f16, 0x24($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80010270: nop

    // 0x80010274: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80010278: nop

    // 0x8001027C: bc1f        L_80010328
    if (!c1cs) {
        // 0x80010280: nop
    
            goto L_80010328;
    }
    // 0x80010280: nop

    // 0x80010284: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x80010288: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8001028C: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80010290: nop

    // 0x80010294: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x80010298: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x8001029C: nop

    // 0x800102A0: blez        $t1, L_80010320
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800102A4: nop
    
            goto L_80010320;
    }
    // 0x800102A4: nop

L_800102A8:
    // 0x800102A8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800102AC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800102B0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800102B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800102B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800102BC: lwc1        $f4, 0x24($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800102C0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800102C4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800102C8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800102CC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800102D0: sh          $t7, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = ctx->r15;
    // 0x800102D4: nop

    // 0x800102D8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800102DC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800102E0: lw          $t9, 0xC0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC0);
    // 0x800102E4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800102E8: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800102EC: sw          $t0, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r8;
    // 0x800102F0: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800102F4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800102F8: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800102FC: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80010300: addiu       $t4, $t1, 0x160
    ctx->r12 = ADD32(ctx->r9, 0X160);
    // 0x80010304: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80010308: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8001030C: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x80010310: nop

    // 0x80010314: slt         $at, $t2, $t7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80010318: bne         $at, $zero, L_800102A8
    if (ctx->r1 != 0) {
        // 0x8001031C: nop
    
            goto L_800102A8;
    }
    // 0x8001031C: nop

L_80010320:
    // 0x80010320: b           L_800103C4
    // 0x80010324: nop

        goto L_800103C4;
    // 0x80010324: nop

L_80010328:
    // 0x80010328: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8001032C: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x80010330: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80010334: nop

    // 0x80010338: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8001033C: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x80010340: nop

    // 0x80010344: blez        $t0, L_800103C4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80010348: nop
    
            goto L_800103C4;
    }
    // 0x80010348: nop

L_8001034C:
    // 0x8001034C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80010350: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x80010354: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80010358: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001035C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80010360: lwc1        $f10, 0x24($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X24);
    // 0x80010364: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80010368: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001036C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80010370: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80010374: sh          $t1, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r9;
    // 0x80010378: nop

    // 0x8001037C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80010380: nop

    // 0x80010384: lw          $t2, 0xC0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0XC0);
    // 0x80010388: nop

    // 0x8001038C: ori         $t7, $t2, 0x8000
    ctx->r15 = ctx->r10 | 0X8000;
    // 0x80010390: sw          $t7, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r15;
    // 0x80010394: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80010398: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8001039C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800103A0: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x800103A4: addiu       $t6, $t0, 0x160
    ctx->r14 = ADD32(ctx->r8, 0X160);
    // 0x800103A8: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800103AC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800103B0: lhu         $t1, 0x6($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X6);
    // 0x800103B4: nop

    // 0x800103B8: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800103BC: bne         $at, $zero, L_8001034C
    if (ctx->r1 != 0) {
        // 0x800103C0: nop
    
            goto L_8001034C;
    }
    // 0x800103C0: nop

L_800103C4:
    // 0x800103C4: b           L_80010450
    // 0x800103C8: nop

        goto L_80010450;
    // 0x800103C8: nop

L_800103CC:
    // 0x800103CC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800103D0: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800103D4: lw          $t2, 0xC($t4)
    ctx->r10 = MEM_W(ctx->r12, 0XC);
    // 0x800103D8: nop

    // 0x800103DC: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800103E0: lhu         $t7, 0x6($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X6);
    // 0x800103E4: nop

    // 0x800103E8: blez        $t7, L_80010450
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800103EC: nop
    
            goto L_80010450;
    }
    // 0x800103EC: nop

L_800103F0:
    // 0x800103F0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800103F4: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800103F8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800103FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80010400: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80010404: lwc1        $f16, 0x24($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X24);
    // 0x80010408: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8001040C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80010410: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80010414: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80010418: sh          $t0, 0x11E($t6)
    MEM_H(0X11E, ctx->r14) = ctx->r8;
    // 0x8001041C: nop

    // 0x80010420: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80010424: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80010428: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8001042C: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x80010430: addiu       $t2, $t1, 0x160
    ctx->r10 = ADD32(ctx->r9, 0X160);
    // 0x80010434: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80010438: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8001043C: lhu         $t7, 0x6($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X6);
    // 0x80010440: nop

    // 0x80010444: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80010448: bne         $at, $zero, L_800103F0
    if (ctx->r1 != 0) {
        // 0x8001044C: nop
    
            goto L_800103F0;
    }
    // 0x8001044C: nop

L_80010450:
    // 0x80010450: b           L_80010458
    // 0x80010454: nop

        goto L_80010458;
    // 0x80010454: nop

L_80010458:
    // 0x80010458: jr          $ra
    // 0x8001045C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001045C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80048C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048C30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80048C34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048C38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80048C3C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80048C40: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80048C44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80048C48: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80048C4C: nop

    // 0x80048C50: beq         $t6, $zero, L_80048C68
    if (ctx->r14 == 0) {
        // 0x80048C54: nop
    
            goto L_80048C68;
    }
    // 0x80048C54: nop

    // 0x80048C58: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80048C5C: nop

    // 0x80048C60: bne         $t7, $zero, L_80048C70
    if (ctx->r15 != 0) {
        // 0x80048C64: nop
    
            goto L_80048C70;
    }
    // 0x80048C64: nop

L_80048C68:
    // 0x80048C68: b           L_80048DB4
    // 0x80048C6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80048DB4;
    // 0x80048C6C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80048C70:
    // 0x80048C70: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80048C74: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80048C78: nop

    // 0x80048C7C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x80048C80: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80048C84: nop

    // 0x80048C88: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80048C8C: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
    // 0x80048C90: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80048C94: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048C98: lhu         $s0, 0x0($t0)
    ctx->r16 = MEM_HU(ctx->r8, 0X0);
    // 0x80048C9C: addiu       $t2, $t0, 0x2
    ctx->r10 = ADD32(ctx->r8, 0X2);
    // 0x80048CA0: xor         $t1, $s0, $at
    ctx->r9 = ctx->r16 ^ ctx->r1;
    // 0x80048CA4: sltu        $t1, $zero, $t1
    ctx->r9 = 0 < ctx->r9 ? 1 : 0;
    // 0x80048CA8: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80048CAC: beq         $s0, $zero, L_80048CE8
    if (ctx->r16 == 0) {
        // 0x80048CB0: sw          $t2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r10;
            goto L_80048CE8;
    }
    // 0x80048CB0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_80048CB4:
    // 0x80048CB4: lhu         $t3, 0x2C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048CB8: nop

    // 0x80048CBC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80048CC0: sh          $t4, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r12;
    // 0x80048CC4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80048CC8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048CCC: lhu         $s0, 0x0($t5)
    ctx->r16 = MEM_HU(ctx->r13, 0X0);
    // 0x80048CD0: addiu       $t7, $t5, 0x2
    ctx->r15 = ADD32(ctx->r13, 0X2);
    // 0x80048CD4: xor         $t6, $s0, $at
    ctx->r14 = ctx->r16 ^ ctx->r1;
    // 0x80048CD8: sltu        $t6, $zero, $t6
    ctx->r14 = 0 < ctx->r14 ? 1 : 0;
    // 0x80048CDC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80048CE0: bne         $s0, $zero, L_80048CB4
    if (ctx->r16 != 0) {
        // 0x80048CE4: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_80048CB4;
    }
    // 0x80048CE4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80048CE8:
    // 0x80048CE8: lhu         $t8, 0x2C($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048CEC: nop

    // 0x80048CF0: bne         $t8, $zero, L_80048D00
    if (ctx->r24 != 0) {
        // 0x80048CF4: nop
    
            goto L_80048D00;
    }
    // 0x80048CF4: nop

    // 0x80048CF8: b           L_80048DB4
    // 0x80048CFC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80048DB4;
    // 0x80048CFC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80048D00:
    // 0x80048D00: lhu         $a0, 0x2C($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048D04: nop

    // 0x80048D08: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80048D0C: jal         0x800BC6EC
    // 0x80048D10: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80048D10: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80048D14: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80048D18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80048D1C: sw          $s0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r16;
    // 0x80048D20: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80048D24: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80048D28: nop

    // 0x80048D2C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80048D30: lhu         $t2, 0x2C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048D34: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80048D38: blez        $t2, L_80048D88
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80048D3C: nop
    
            goto L_80048D88;
    }
    // 0x80048D3C: nop

L_80048D40:
    // 0x80048D40: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80048D44: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80048D48: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80048D4C: nop

    // 0x80048D50: sh          $t4, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r12;
    // 0x80048D54: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80048D58: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80048D5C: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x80048D60: addiu       $t7, $t5, 0x2
    ctx->r15 = ADD32(ctx->r13, 0X2);
    // 0x80048D64: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80048D68: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80048D6C: lhu         $t1, 0x2E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2E);
    // 0x80048D70: lhu         $t3, 0x2C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048D74: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80048D78: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x80048D7C: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80048D80: bne         $at, $zero, L_80048D40
    if (ctx->r1 != 0) {
        // 0x80048D84: sh          $t0, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r8;
            goto L_80048D40;
    }
    // 0x80048D84: sh          $t0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r8;
L_80048D88:
    // 0x80048D88: lhu         $t4, 0x2C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2C);
    // 0x80048D8C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80048D90: nop

    // 0x80048D94: sh          $t4, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r12;
    // 0x80048D98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80048D9C: jal         0x80048F40
    // 0x80048DA0: nop

    func_80048F40(rdram, ctx);
        goto after_1;
    // 0x80048DA0: nop

    after_1:
    // 0x80048DA4: b           L_80048DB4
    // 0x80048DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80048DB4;
    // 0x80048DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80048DAC: b           L_80048DB4
    // 0x80048DB0: nop

        goto L_80048DB4;
    // 0x80048DB0: nop

L_80048DB4:
    // 0x80048DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80048DB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80048DBC: jr          $ra
    // 0x80048DC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80048DC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80028F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028F74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028F78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028F7C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80028F80: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
    // 0x80028F84: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80028F88: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x80028F8C: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80028F90: nop

    // 0x80028F94: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80028F98: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80028F9C: nop

    // 0x80028FA0: addiu       $t9, $t8, 0xA
    ctx->r25 = ADD32(ctx->r24, 0XA);
    // 0x80028FA4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80028FA8: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
L_80028FAC:
    // 0x80028FAC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80028FB0: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x80028FB4: nop

    // 0x80028FB8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80028FBC: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x80028FC0: lh          $t3, 0x2E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2E);
    // 0x80028FC4: nop

    // 0x80028FC8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80028FCC: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80028FD0: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80028FD4: slti        $at, $t6, 0x5A
    ctx->r1 = SIGNED(ctx->r14) < 0X5A ? 1 : 0;
    // 0x80028FD8: bne         $at, $zero, L_80028FAC
    if (ctx->r1 != 0) {
        // 0x80028FDC: sh          $t4, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r12;
            goto L_80028FAC;
    }
    // 0x80028FDC: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80028FE0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80028FE4: nop

    // 0x80028FE8: beq         $t7, $zero, L_8002906C
    if (ctx->r15 == 0) {
        // 0x80028FEC: nop
    
            goto L_8002906C;
    }
    // 0x80028FEC: nop

L_80028FF0:
    // 0x80028FF0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80028FF4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80028FF8: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80028FFC: nop

    // 0x80029000: bne         $t9, $at, L_80029018
    if (ctx->r25 != ctx->r1) {
        // 0x80029004: nop
    
            goto L_80029018;
    }
    // 0x80029004: nop

    // 0x80029008: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x8002900C: nop

    // 0x80029010: beq         $t0, $zero, L_80029020
    if (ctx->r8 == 0) {
        // 0x80029014: nop
    
            goto L_80029020;
    }
    // 0x80029014: nop

L_80029018:
    // 0x80029018: b           L_8002906C
    // 0x8002901C: nop

        goto L_8002906C;
    // 0x8002901C: nop

L_80029020:
    // 0x80029020: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80029024: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80029028: lhu         $t4, 0x2C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2C);
    // 0x8002902C: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80029030: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80029034: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x80029038: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x8002903C: nop

    // 0x80029040: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80029044: sh          $t7, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r15;
    // 0x80029048: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002904C: nop

    // 0x80029050: lw          $t8, 0x18($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X18);
    // 0x80029054: nop

    // 0x80029058: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8002905C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80029060: nop

    // 0x80029064: bne         $t0, $zero, L_80028FF0
    if (ctx->r8 != 0) {
        // 0x80029068: nop
    
            goto L_80028FF0;
    }
    // 0x80029068: nop

L_8002906C:
    // 0x8002906C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80029070: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
L_80029074:
    // 0x80029074: lh          $t3, 0x2E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2E);
    // 0x80029078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002907C: lhu         $a1, 0x2C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2C);
    // 0x80029080: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80029084: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80029088: jal         0x80028DF8
    // 0x8002908C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_80028DF8(rdram, ctx);
        goto after_0;
    // 0x8002908C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x80029090: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x80029094: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80029098: nop

    // 0x8002909C: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x800290A0: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x800290A4: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800290A8: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x800290AC: bne         $at, $zero, L_80029074
    if (ctx->r1 != 0) {
        // 0x800290B0: sh          $t2, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r10;
            goto L_80029074;
    }
    // 0x800290B0: sh          $t2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r10;
    // 0x800290B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800290B8: lhu         $a1, 0x2C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2C);
    // 0x800290BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800290C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800290C4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800290C8: jal         0x80028DF8
    // 0x800290CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80028DF8(rdram, ctx);
        goto after_1;
    // 0x800290CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x800290D0: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x800290D4: b           L_800290DC
    // 0x800290D8: nop

        goto L_800290DC;
    // 0x800290D8: nop

L_800290DC:
    // 0x800290DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800290E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800290E4: jr          $ra
    // 0x800290E8: nop

    return;
    // 0x800290E8: nop

;}
RECOMP_FUNC void func_800B82D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B82D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B82DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B82E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B82E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B82E8: nop

    // 0x800B82EC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800B82F0: nop

    // 0x800B82F4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800B82F8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B82FC: nop

    // 0x800B8300: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x800B8304: nop

    // 0x800B8308: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800B830C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800B8310: nop

    // 0x800B8314: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B8318: jal         0x8001AE90
    // 0x800B831C: nop

    func_8001AE90(rdram, ctx);
        goto after_0;
    // 0x800B831C: nop

    after_0:
    // 0x800B8320: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800B8324: nop

    // 0x800B8328: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800B832C: jal         0x8000D390
    // 0x800B8330: nop

    TempHeap_Free(rdram, ctx);
        goto after_1;
    // 0x800B8330: nop

    after_1:
    // 0x800B8334: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8338: nop

    // 0x800B833C: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x800B8340: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B8344: nop

    // 0x800B8348: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B834C: jal         0x8000D390
    // 0x800B8350: nop

    TempHeap_Free(rdram, ctx);
        goto after_2;
    // 0x800B8350: nop

    after_2:
    // 0x800B8354: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800B8358: nop

    // 0x800B835C: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x800B8360: jal         0x8000D390
    // 0x800B8364: nop

    TempHeap_Free(rdram, ctx);
        goto after_3;
    // 0x800B8364: nop

    after_3:
    // 0x800B8368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B836C: jal         0x8000D390
    // 0x800B8370: nop

    TempHeap_Free(rdram, ctx);
        goto after_4;
    // 0x800B8370: nop

    after_4:
    // 0x800B8374: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8378: nop

    // 0x800B837C: sw          $zero, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = 0;
    // 0x800B8380: b           L_800B8388
    // 0x800B8384: nop

        goto L_800B8388;
    // 0x800B8384: nop

L_800B8388:
    // 0x800B8388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B838C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B8390: jr          $ra
    // 0x800B8394: nop

    return;
    // 0x800B8394: nop

;}
RECOMP_FUNC void func_80065A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065A60: jal         0x80061488
    // 0x80065A64: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065A64: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065A68: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065A6C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065A70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065A74: beq         $v0, $zero, L_80065A9C
    if (ctx->r2 == 0) {
        // 0x80065A78: nop
    
            goto L_80065A9C;
    }
    // 0x80065A78: nop

    // 0x80065A7C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80065A80: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80065A84: nop

    // 0x80065A88: lh          $v0, 0x32($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X32);
    // 0x80065A8C: nop

    // 0x80065A90: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065A94: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80065A98: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065A9C:
    // 0x80065A9C: b           L_80065AAC
    // 0x80065AA0: nop

        goto L_80065AAC;
    // 0x80065AA0: nop

    // 0x80065AA4: b           L_80065AAC
    // 0x80065AA8: nop

        goto L_80065AAC;
    // 0x80065AA8: nop

L_80065AAC:
    // 0x80065AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065AB4: jr          $ra
    // 0x80065AB8: nop

    return;
    // 0x80065AB8: nop

;}
RECOMP_FUNC void func_80076A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076A0C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076A10: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076A14: nop

    // 0x80076A18: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076A1C: nop

    // 0x80076A20: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076A24: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076A28: jr          $ra
    // 0x80076A2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076A2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076A30: jr          $ra
    // 0x80076A34: nop

    return;
    // 0x80076A34: nop

    // 0x80076A38: jr          $ra
    // 0x80076A3C: nop

    return;
    // 0x80076A3C: nop

;}
RECOMP_FUNC void func_80063BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063BAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063BB4: jal         0x8005F064
    // 0x80063BB8: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063BB8: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063BBC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063BC0: b           L_80063BD0
    // 0x80063BC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063BD0;
    // 0x80063BC4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063BC8: b           L_80063BD0
    // 0x80063BCC: nop

        goto L_80063BD0;
    // 0x80063BCC: nop

L_80063BD0:
    // 0x80063BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063BD8: jr          $ra
    // 0x80063BDC: nop

    return;
    // 0x80063BDC: nop

;}
RECOMP_FUNC void func_80062E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062E5C: jal         0x80061488
    // 0x80062E60: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80062E60: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_0:
    // 0x80062E64: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80062E68: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80062E6C: b           L_80062E7C
    // 0x80062E70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062E7C;
    // 0x80062E70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062E74: b           L_80062E7C
    // 0x80062E78: nop

        goto L_80062E7C;
    // 0x80062E78: nop

L_80062E7C:
    // 0x80062E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062E80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062E84: jr          $ra
    // 0x80062E88: nop

    return;
    // 0x80062E88: nop

;}
RECOMP_FUNC void func_8006E018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E020: jal         0x80061348
    // 0x8006E024: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E024: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_0:
    // 0x8006E028: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E02C: b           L_8006E03C
    // 0x8006E030: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E03C;
    // 0x8006E030: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E034: b           L_8006E03C
    // 0x8006E038: nop

        goto L_8006E03C;
    // 0x8006E038: nop

L_8006E03C:
    // 0x8006E03C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E044: jr          $ra
    // 0x8006E048: nop

    return;
    // 0x8006E048: nop

;}
RECOMP_FUNC void MtxUtil_CopyMtxFTranslationRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2BDC: bne         $a1, $zero, L_800C2C44
    if (ctx->r5 != 0) {
        // 0x800C2BE0: nop
    
            goto L_800C2C44;
    }
    // 0x800C2BE0: nop

    // 0x800C2BE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2BE8: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C2BEC: nop

    // 0x800C2BF0: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x800C2BF4: nop

    // 0x800C2BF8: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x800C2BFC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C2C00: lw          $t7, 0xCE4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XCE4);
    // 0x800C2C04: nop

    // 0x800C2C08: lwc1        $f6, 0x34($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X34);
    // 0x800C2C0C: nop

    // 0x800C2C10: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x800C2C14: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C2C18: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C2C1C: nop

    // 0x800C2C20: lwc1        $f8, 0x38($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X38);
    // 0x800C2C24: nop

    // 0x800C2C28: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x800C2C2C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800C2C30: lw          $t9, 0xCE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE4);
    // 0x800C2C34: nop

    // 0x800C2C38: lwc1        $f10, 0x3C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X3C);
    // 0x800C2C3C: b           L_800C2C74
    // 0x800C2C40: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
        goto L_800C2C74;
    // 0x800C2C40: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
L_800C2C44:
    // 0x800C2C44: lwc1        $f16, 0x30($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800C2C48: nop

    // 0x800C2C4C: swc1        $f16, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f16.u32l;
    // 0x800C2C50: lwc1        $f18, 0x34($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800C2C54: nop

    // 0x800C2C58: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x800C2C5C: lwc1        $f4, 0x38($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800C2C60: nop

    // 0x800C2C64: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x800C2C68: lwc1        $f6, 0x3C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800C2C6C: nop

    // 0x800C2C70: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
L_800C2C74:
    // 0x800C2C74: jr          $ra
    // 0x800C2C78: nop

    return;
    // 0x800C2C78: nop

    // 0x800C2C7C: jr          $ra
    // 0x800C2C80: nop

    return;
    // 0x800C2C80: nop

;}
RECOMP_FUNC void func_8008C4AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C4AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008C4B0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008C4B4:
    // 0x8008C4B4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8008C4B8: nop

    // 0x8008C4BC: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8008C4C0: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x8008C4C4: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x8008C4C8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8008C4CC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008C4D0: nop

    // 0x8008C4D4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008C4D8: slti        $at, $t1, 0x7
    ctx->r1 = SIGNED(ctx->r9) < 0X7 ? 1 : 0;
    // 0x8008C4DC: bne         $at, $zero, L_8008C4B4
    if (ctx->r1 != 0) {
        // 0x8008C4E0: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8008C4B4;
    }
    // 0x8008C4E0: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8008C4E4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8008C4E8:
    // 0x8008C4E8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8008C4EC: nop

    // 0x8008C4F0: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8008C4F4: lbu         $t4, 0x9($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X9);
    // 0x8008C4F8: addu        $t5, $a0, $t2
    ctx->r13 = ADD32(ctx->r4, ctx->r10);
    // 0x8008C4FC: sb          $t4, 0x651($t5)
    MEM_B(0X651, ctx->r13) = ctx->r12;
    // 0x8008C500: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8008C504: nop

    // 0x8008C508: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8008C50C: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x8008C510: bne         $at, $zero, L_8008C4E8
    if (ctx->r1 != 0) {
        // 0x8008C514: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_8008C4E8;
    }
    // 0x8008C514: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8008C518: b           L_8008C520
    // 0x8008C51C: nop

        goto L_8008C520;
    // 0x8008C51C: nop

L_8008C520:
    // 0x8008C520: jr          $ra
    // 0x8008C524: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008C524: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80051804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051804: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80051808: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005180C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80051810: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80051814: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80051818: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005181C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051824: lh          $t6, 0x3E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3E);
    // 0x80051828: nop

    // 0x8005182C: andi        $t7, $t6, 0x1FFF
    ctx->r15 = ctx->r14 & 0X1FFF;
    // 0x80051830: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    // 0x80051834: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051838: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8005183C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80051840: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80051844: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051848: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8005184C: bne         $t2, $zero, L_8005185C
    if (ctx->r10 != 0) {
        // 0x80051850: and         $t3, $t1, $at
        ctx->r11 = ctx->r9 & ctx->r1;
            goto L_8005185C;
    }
    // 0x80051850: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80051854: beq         $t3, $zero, L_80051CBC
    if (ctx->r11 == 0) {
        // 0x80051858: nop
    
            goto L_80051CBC;
    }
    // 0x80051858: nop

L_8005185C:
    // 0x8005185C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80051860: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80051864: nop

    // 0x80051868: lw          $a0, 0x58($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X58);
    // 0x8005186C: jal         0x80056C60
    // 0x80051870: nop

    func_80056C60(rdram, ctx);
        goto after_0;
    // 0x80051870: nop

    after_0:
    // 0x80051874: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80051878: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8005187C: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80051880: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051884: beq         $t4, $at, L_8005189C
    if (ctx->r12 == ctx->r1) {
        // 0x80051888: nop
    
            goto L_8005189C;
    }
    // 0x80051888: nop

    // 0x8005188C: lh          $t5, 0x3E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3E);
    // 0x80051890: addiu       $at, $zero, 0x9B
    ctx->r1 = ADD32(0, 0X9B);
    // 0x80051894: beq         $t5, $at, L_800519F0
    if (ctx->r13 == ctx->r1) {
        // 0x80051898: nop
    
            goto L_800519F0;
    }
    // 0x80051898: nop

L_8005189C:
    // 0x8005189C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800518A0: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x800518A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800518A8: beq         $t6, $at, L_800518C0
    if (ctx->r14 == ctx->r1) {
        // 0x800518AC: nop
    
            goto L_800518C0;
    }
    // 0x800518AC: nop

    // 0x800518B0: lh          $t7, 0x3E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3E);
    // 0x800518B4: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x800518B8: beq         $t7, $at, L_800519F0
    if (ctx->r15 == ctx->r1) {
        // 0x800518BC: nop
    
            goto L_800519F0;
    }
    // 0x800518BC: nop

L_800518C0:
    // 0x800518C0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800518C4: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800518C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800518CC: beq         $t8, $at, L_800518E4
    if (ctx->r24 == ctx->r1) {
        // 0x800518D0: nop
    
            goto L_800518E4;
    }
    // 0x800518D0: nop

    // 0x800518D4: lh          $t0, 0x3E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3E);
    // 0x800518D8: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x800518DC: beq         $t0, $at, L_800519F0
    if (ctx->r8 == ctx->r1) {
        // 0x800518E0: nop
    
            goto L_800519F0;
    }
    // 0x800518E0: nop

L_800518E4:
    // 0x800518E4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800518E8: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x800518EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800518F0: beq         $t1, $at, L_80051908
    if (ctx->r9 == ctx->r1) {
        // 0x800518F4: nop
    
            goto L_80051908;
    }
    // 0x800518F4: nop

    // 0x800518F8: lh          $t2, 0x3E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3E);
    // 0x800518FC: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x80051900: beq         $t2, $at, L_800519F0
    if (ctx->r10 == ctx->r1) {
        // 0x80051904: nop
    
            goto L_800519F0;
    }
    // 0x80051904: nop

L_80051908:
    // 0x80051908: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005190C: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80051910: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051914: beq         $t3, $at, L_8005192C
    if (ctx->r11 == ctx->r1) {
        // 0x80051918: nop
    
            goto L_8005192C;
    }
    // 0x80051918: nop

    // 0x8005191C: lh          $t9, 0x3E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3E);
    // 0x80051920: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x80051924: beq         $t9, $at, L_800519F0
    if (ctx->r25 == ctx->r1) {
        // 0x80051928: nop
    
            goto L_800519F0;
    }
    // 0x80051928: nop

L_8005192C:
    // 0x8005192C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80051930: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80051934: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051938: beq         $t4, $at, L_80051950
    if (ctx->r12 == ctx->r1) {
        // 0x8005193C: nop
    
            goto L_80051950;
    }
    // 0x8005193C: nop

    // 0x80051940: lh          $t5, 0x3E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3E);
    // 0x80051944: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x80051948: beq         $t5, $at, L_800519F0
    if (ctx->r13 == ctx->r1) {
        // 0x8005194C: nop
    
            goto L_800519F0;
    }
    // 0x8005194C: nop

L_80051950:
    // 0x80051950: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80051954: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x80051958: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005195C: beq         $t6, $at, L_80051974
    if (ctx->r14 == ctx->r1) {
        // 0x80051960: nop
    
            goto L_80051974;
    }
    // 0x80051960: nop

    // 0x80051964: lh          $t7, 0x3E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3E);
    // 0x80051968: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x8005196C: beq         $t7, $at, L_800519F0
    if (ctx->r15 == ctx->r1) {
        // 0x80051970: nop
    
            goto L_800519F0;
    }
    // 0x80051970: nop

L_80051974:
    // 0x80051974: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80051978: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x8005197C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051980: beq         $t8, $at, L_80051998
    if (ctx->r24 == ctx->r1) {
        // 0x80051984: nop
    
            goto L_80051998;
    }
    // 0x80051984: nop

    // 0x80051988: lh          $t0, 0x3E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3E);
    // 0x8005198C: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x80051990: beq         $t0, $at, L_800519F0
    if (ctx->r8 == ctx->r1) {
        // 0x80051994: nop
    
            goto L_800519F0;
    }
    // 0x80051994: nop

L_80051998:
    // 0x80051998: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x8005199C: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x800519A0: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519A4: nop
    
            goto L_800519F0;
    }
    // 0x800519A4: nop

    // 0x800519A8: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x800519AC: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519B0: nop
    
            goto L_800519F0;
    }
    // 0x800519B0: nop

    // 0x800519B4: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x800519B8: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519BC: nop
    
            goto L_800519F0;
    }
    // 0x800519BC: nop

    // 0x800519C0: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x800519C4: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519C8: nop
    
            goto L_800519F0;
    }
    // 0x800519C8: nop

    // 0x800519CC: addiu       $at, $zero, 0xD3
    ctx->r1 = ADD32(0, 0XD3);
    // 0x800519D0: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519D4: nop
    
            goto L_800519F0;
    }
    // 0x800519D4: nop

    // 0x800519D8: addiu       $at, $zero, 0xD4
    ctx->r1 = ADD32(0, 0XD4);
    // 0x800519DC: beq         $t1, $at, L_800519F0
    if (ctx->r9 == ctx->r1) {
        // 0x800519E0: nop
    
            goto L_800519F0;
    }
    // 0x800519E0: nop

    // 0x800519E4: addiu       $at, $zero, 0xD5
    ctx->r1 = ADD32(0, 0XD5);
    // 0x800519E8: bne         $t1, $at, L_80051A30
    if (ctx->r9 != ctx->r1) {
        // 0x800519EC: nop
    
            goto L_80051A30;
    }
    // 0x800519EC: nop

L_800519F0:
    // 0x800519F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800519F4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800519F8: jal         0x80051804
    // 0x800519FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80051804(rdram, ctx);
        goto after_1;
    // 0x800519FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80051A00: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051A04: jal         0x800507AC
    // 0x80051A08: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800507AC(rdram, ctx);
        goto after_2;
    // 0x80051A08: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x80051A0C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051A10: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80051A14: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80051A18: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80051A1C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80051A20: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x80051A24: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x80051A28: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80051A2C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_80051A30:
    // 0x80051A30: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x80051A34: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80051A38: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x80051A3C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x80051A40: lh          $s0, 0x2C5A($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X2C5A);
    // 0x80051A44: nop

    // 0x80051A48: beq         $s0, $zero, L_80051A70
    if (ctx->r16 == 0) {
        // 0x80051A4C: nop
    
            goto L_80051A70;
    }
    // 0x80051A4C: nop

    // 0x80051A50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051A54: beq         $s0, $at, L_80051AC0
    if (ctx->r16 == ctx->r1) {
        // 0x80051A58: nop
    
            goto L_80051AC0;
    }
    // 0x80051A58: nop

    // 0x80051A5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80051A60: beq         $s0, $at, L_80051B10
    if (ctx->r16 == ctx->r1) {
        // 0x80051A64: nop
    
            goto L_80051B10;
    }
    // 0x80051A64: nop

    // 0x80051A68: b           L_80051B4C
    // 0x80051A6C: nop

        goto L_80051B4C;
    // 0x80051A6C: nop

L_80051A70:
    // 0x80051A70: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051A74: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80051A78: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80051A7C: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80051A80: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80051A84: bne         $t4, $zero, L_80051A94
    if (ctx->r12 != 0) {
        // 0x80051A88: andi        $t5, $t1, 0x8
        ctx->r13 = ctx->r9 & 0X8;
            goto L_80051A94;
    }
    // 0x80051A88: andi        $t5, $t1, 0x8
    ctx->r13 = ctx->r9 & 0X8;
    // 0x80051A8C: beq         $t5, $zero, L_80051AB8
    if (ctx->r13 == 0) {
        // 0x80051A90: nop
    
            goto L_80051AB8;
    }
    // 0x80051A90: nop

L_80051A94:
    // 0x80051A94: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x80051A98: jal         0x80056E88
    // 0x80051A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_3;
    // 0x80051A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80051AA0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80051AA4: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80051AA8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80051AAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051AB0: jal         0x800507AC
    // 0x80051AB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800507AC(rdram, ctx);
        goto after_4;
    // 0x80051AB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_80051AB8:
    // 0x80051AB8: b           L_80051B4C
    // 0x80051ABC: nop

        goto L_80051B4C;
    // 0x80051ABC: nop

L_80051AC0:
    // 0x80051AC0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051AC4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051AC8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80051ACC: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x80051AD0: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80051AD4: bne         $t8, $zero, L_80051B08
    if (ctx->r24 != 0) {
        // 0x80051AD8: andi        $t9, $t3, 0x8
        ctx->r25 = ctx->r11 & 0X8;
            goto L_80051B08;
    }
    // 0x80051AD8: andi        $t9, $t3, 0x8
    ctx->r25 = ctx->r11 & 0X8;
    // 0x80051ADC: bne         $t9, $zero, L_80051B08
    if (ctx->r25 != 0) {
        // 0x80051AE0: nop
    
            goto L_80051B08;
    }
    // 0x80051AE0: nop

    // 0x80051AE4: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x80051AE8: jal         0x80056E88
    // 0x80051AEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_5;
    // 0x80051AEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80051AF0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80051AF4: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80051AF8: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80051AFC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051B00: jal         0x800507AC
    // 0x80051B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800507AC(rdram, ctx);
        goto after_6;
    // 0x80051B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
L_80051B08:
    // 0x80051B08: b           L_80051B4C
    // 0x80051B0C: nop

        goto L_80051B4C;
    // 0x80051B0C: nop

L_80051B10:
    // 0x80051B10: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80051B14: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x80051B18: bne         $t1, $at, L_80051B44
    if (ctx->r9 != ctx->r1) {
        // 0x80051B1C: nop
    
            goto L_80051B44;
    }
    // 0x80051B1C: nop

    // 0x80051B20: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80051B24: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80051B28: nop

    // 0x80051B2C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80051B30: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80051B34: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80051B38: ori         $t3, $t7, 0x8
    ctx->r11 = ctx->r15 | 0X8;
    // 0x80051B3C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80051B40: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
L_80051B44:
    // 0x80051B44: b           L_80051B4C
    // 0x80051B48: nop

        goto L_80051B4C;
    // 0x80051B48: nop

L_80051B4C:
    // 0x80051B4C: lh          $t5, 0x3E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X3E);
    // 0x80051B50: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x80051B54: beq         $t5, $at, L_80051B68
    if (ctx->r13 == ctx->r1) {
        // 0x80051B58: nop
    
            goto L_80051B68;
    }
    // 0x80051B58: nop

    // 0x80051B5C: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x80051B60: bne         $t5, $at, L_80051B74
    if (ctx->r13 != ctx->r1) {
        // 0x80051B64: nop
    
            goto L_80051B74;
    }
    // 0x80051B64: nop

L_80051B68:
    // 0x80051B68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051B6C: jal         0x800507AC
    // 0x80051B70: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    func_800507AC(rdram, ctx);
        goto after_7;
    // 0x80051B70: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    after_7:
L_80051B74:
    // 0x80051B74: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x80051B78: addiu       $at, $zero, 0x9B
    ctx->r1 = ADD32(0, 0X9B);
    // 0x80051B7C: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051B80: nop
    
            goto L_80051C5C;
    }
    // 0x80051B80: nop

    // 0x80051B84: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x80051B88: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051B8C: nop
    
            goto L_80051C5C;
    }
    // 0x80051B8C: nop

    // 0x80051B90: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x80051B94: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051B98: nop
    
            goto L_80051C5C;
    }
    // 0x80051B98: nop

    // 0x80051B9C: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x80051BA0: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BA4: nop
    
            goto L_80051C5C;
    }
    // 0x80051BA4: nop

    // 0x80051BA8: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x80051BAC: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BB0: nop
    
            goto L_80051C5C;
    }
    // 0x80051BB0: nop

    // 0x80051BB4: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x80051BB8: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BBC: nop
    
            goto L_80051C5C;
    }
    // 0x80051BBC: nop

    // 0x80051BC0: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80051BC4: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BC8: nop
    
            goto L_80051C5C;
    }
    // 0x80051BC8: nop

    // 0x80051BCC: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x80051BD0: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BD4: nop
    
            goto L_80051C5C;
    }
    // 0x80051BD4: nop

    // 0x80051BD8: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x80051BDC: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BE0: nop
    
            goto L_80051C5C;
    }
    // 0x80051BE0: nop

    // 0x80051BE4: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x80051BE8: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BEC: nop
    
            goto L_80051C5C;
    }
    // 0x80051BEC: nop

    // 0x80051BF0: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x80051BF4: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051BF8: nop
    
            goto L_80051C5C;
    }
    // 0x80051BF8: nop

    // 0x80051BFC: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x80051C00: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C04: nop
    
            goto L_80051C5C;
    }
    // 0x80051C04: nop

    // 0x80051C08: addiu       $at, $zero, 0xD3
    ctx->r1 = ADD32(0, 0XD3);
    // 0x80051C0C: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C10: nop
    
            goto L_80051C5C;
    }
    // 0x80051C10: nop

    // 0x80051C14: addiu       $at, $zero, 0xD4
    ctx->r1 = ADD32(0, 0XD4);
    // 0x80051C18: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C1C: nop
    
            goto L_80051C5C;
    }
    // 0x80051C1C: nop

    // 0x80051C20: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80051C24: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C28: nop
    
            goto L_80051C5C;
    }
    // 0x80051C28: nop

    // 0x80051C2C: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x80051C30: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C34: nop
    
            goto L_80051C5C;
    }
    // 0x80051C34: nop

    // 0x80051C38: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x80051C3C: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C40: nop
    
            goto L_80051C5C;
    }
    // 0x80051C40: nop

    // 0x80051C44: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x80051C48: beq         $t8, $at, L_80051C5C
    if (ctx->r24 == ctx->r1) {
        // 0x80051C4C: nop
    
            goto L_80051C5C;
    }
    // 0x80051C4C: nop

    // 0x80051C50: addiu       $at, $zero, 0xD5
    ctx->r1 = ADD32(0, 0XD5);
    // 0x80051C54: bne         $t8, $at, L_80051CA0
    if (ctx->r24 != ctx->r1) {
        // 0x80051C58: nop
    
            goto L_80051CA0;
    }
    // 0x80051C58: nop

L_80051C5C:
    // 0x80051C5C: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x80051C60: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80051C64: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80051C68: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80051C6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051C70: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80051C74: lh          $t1, 0x2C56($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2C56);
    // 0x80051C78: nop

    // 0x80051C7C: sw          $t1, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r9;
    // 0x80051C80: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x80051C84: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80051C88: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x80051C8C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80051C90: lh          $t3, 0x2C58($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2C58);
    // 0x80051C94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051C98: b           L_80051CBC
    // 0x80051C9C: sw          $t3, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r11;
        goto L_80051CBC;
    // 0x80051C9C: sw          $t3, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r11;
L_80051CA0:
    // 0x80051CA0: lh          $t4, 0x36($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X36);
    // 0x80051CA4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80051CA8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80051CAC: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x80051CB0: lh          $t8, 0x2C58($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2C58);
    // 0x80051CB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051CB8: sw          $t8, 0xE4C($at)
    MEM_W(0XE4C, ctx->r1) = ctx->r24;
L_80051CBC:
    // 0x80051CBC: lh          $a3, 0x3E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3E);
    // 0x80051CC0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80051CC4: or          $t9, $a3, $at
    ctx->r25 = ctx->r7 | ctx->r1;
    // 0x80051CC8: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80051CCC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80051CD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051CD4: jal         0x800B3230
    // 0x80051CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B3230(rdram, ctx);
        goto after_8;
    // 0x80051CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80051CDC: lhu         $t0, 0x34($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X34);
    // 0x80051CE0: nop

    // 0x80051CE4: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80051CE8: sra         $t6, $t1, 7
    ctx->r14 = S32(SIGNED(ctx->r9) >> 7);
    // 0x80051CEC: bne         $t6, $zero, L_80051DDC
    if (ctx->r14 != 0) {
        // 0x80051CF0: nop
    
            goto L_80051DDC;
    }
    // 0x80051CF0: nop

    // 0x80051CF4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051CF8: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051CFC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80051D00: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x80051D04: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80051D08: bne         $t4, $zero, L_80051D18
    if (ctx->r12 != 0) {
        // 0x80051D0C: andi        $t5, $t3, 0x10
        ctx->r13 = ctx->r11 & 0X10;
            goto L_80051D18;
    }
    // 0x80051D0C: andi        $t5, $t3, 0x10
    ctx->r13 = ctx->r11 & 0X10;
    // 0x80051D10: beq         $t5, $zero, L_80051DDC
    if (ctx->r13 == 0) {
        // 0x80051D14: nop
    
            goto L_80051DDC;
    }
    // 0x80051D14: nop

L_80051D18:
    // 0x80051D18: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051D1C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80051D20: nop

    // 0x80051D24: lh          $a0, 0x4A($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X4A);
    // 0x80051D28: nop

    // 0x80051D2C: andi        $t9, $a0, 0x1FFF
    ctx->r25 = ctx->r4 & 0X1FFF;
    // 0x80051D30: jal         0x800574CC
    // 0x80051D34: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800574CC(rdram, ctx);
        goto after_9;
    // 0x80051D34: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_9:
    // 0x80051D38: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x80051D3C: sra         $t0, $s2, 16
    ctx->r8 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80051D40: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
    // 0x80051D44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80051D48: jal         0x80056E88
    // 0x80051D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_10;
    // 0x80051D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80051D50: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80051D54: sra         $t1, $s1, 16
    ctx->r9 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80051D58: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80051D5C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051D60: jal         0x800507AC
    // 0x80051D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800507AC(rdram, ctx);
        goto after_11;
    // 0x80051D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x80051D68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051D6C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80051D70: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80051D74: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80051D78: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80051D7C: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x80051D80: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80051D84: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80051D88: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80051D8C: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x80051D90: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051D94: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051D98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80051D9C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80051DA0: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80051DA4: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80051DA8: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80051DAC: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80051DB0: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x80051DB4: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x80051DB8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051DBC: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80051DC0: nop

    // 0x80051DC4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80051DC8: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80051DCC: or          $t6, $t4, $zero
    ctx->r14 = ctx->r12 | 0;
    // 0x80051DD0: ori         $t7, $t5, 0x40
    ctx->r15 = ctx->r13 | 0X40;
    // 0x80051DD4: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80051DD8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
L_80051DDC:
    // 0x80051DDC: lhu         $s0, 0x34($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X34);
    // 0x80051DE0: nop

    // 0x80051DE4: andi        $t3, $s0, 0x300
    ctx->r11 = ctx->r16 & 0X300;
    // 0x80051DE8: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80051DEC: sra         $t8, $s0, 8
    ctx->r24 = S32(SIGNED(ctx->r16) >> 8);
    // 0x80051DF0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80051DF4: beq         $s0, $zero, L_80051E10
    if (ctx->r16 == 0) {
        // 0x80051DF8: nop
    
            goto L_80051E10;
    }
    // 0x80051DF8: nop

    // 0x80051DFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051E00: beq         $s0, $at, L_80051EEC
    if (ctx->r16 == ctx->r1) {
        // 0x80051E04: nop
    
            goto L_80051EEC;
    }
    // 0x80051E04: nop

    // 0x80051E08: b           L_80051FC8
    // 0x80051E0C: nop

        goto L_80051FC8;
    // 0x80051E0C: nop

L_80051E10:
    // 0x80051E10: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80051E14: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80051E18: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80051E1C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80051E20: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80051E24: bne         $t4, $zero, L_80051E34
    if (ctx->r12 != 0) {
        // 0x80051E28: andi        $t5, $t1, 0x40
        ctx->r13 = ctx->r9 & 0X40;
            goto L_80051E34;
    }
    // 0x80051E28: andi        $t5, $t1, 0x40
    ctx->r13 = ctx->r9 & 0X40;
    // 0x80051E2C: beq         $t5, $zero, L_80051E90
    if (ctx->r13 == 0) {
        // 0x80051E30: nop
    
            goto L_80051E90;
    }
    // 0x80051E30: nop

L_80051E34:
    // 0x80051E34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051E38: jal         0x800507AC
    // 0x80051E3C: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    func_800507AC(rdram, ctx);
        goto after_12;
    // 0x80051E3C: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_12:
    // 0x80051E40: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051E44: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80051E48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80051E4C: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80051E50: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80051E54: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x80051E58: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80051E5C: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80051E60: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80051E64: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80051E68: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051E6C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051E70: nop

    // 0x80051E74: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80051E78: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80051E7C: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x80051E80: ori         $t5, $t1, 0x20
    ctx->r13 = ctx->r9 | 0X20;
    // 0x80051E84: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80051E88: b           L_80051EE4
    // 0x80051E8C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
        goto L_80051EE4;
    // 0x80051E8C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
L_80051E90:
    // 0x80051E90: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051E94: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80051E98: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80051E9C: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80051EA0: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80051EA4: bne         $t6, $zero, L_80051EE4
    if (ctx->r14 != 0) {
        // 0x80051EA8: andi        $t7, $t9, 0x20
        ctx->r15 = ctx->r25 & 0X20;
            goto L_80051EE4;
    }
    // 0x80051EA8: andi        $t7, $t9, 0x20
    ctx->r15 = ctx->r25 & 0X20;
    // 0x80051EAC: bne         $t7, $zero, L_80051EE4
    if (ctx->r15 != 0) {
        // 0x80051EB0: nop
    
            goto L_80051EE4;
    }
    // 0x80051EB0: nop

    // 0x80051EB4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051EB8: jal         0x800507AC
    // 0x80051EBC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_800507AC(rdram, ctx);
        goto after_13;
    // 0x80051EBC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_13:
    // 0x80051EC0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80051EC4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80051EC8: nop

    // 0x80051ECC: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80051ED0: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80051ED4: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
    // 0x80051ED8: ori         $t5, $t1, 0x20
    ctx->r13 = ctx->r9 | 0X20;
    // 0x80051EDC: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80051EE0: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
L_80051EE4:
    // 0x80051EE4: b           L_80052078
    // 0x80051EE8: nop

        goto L_80052078;
    // 0x80051EE8: nop

L_80051EEC:
    // 0x80051EEC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80051EF0: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80051EF4: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80051EF8: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80051EFC: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80051F00: bne         $t6, $zero, L_80051F10
    if (ctx->r14 != 0) {
        // 0x80051F04: andi        $t7, $t9, 0x20
        ctx->r15 = ctx->r25 & 0X20;
            goto L_80051F10;
    }
    // 0x80051F04: andi        $t7, $t9, 0x20
    ctx->r15 = ctx->r25 & 0X20;
    // 0x80051F08: beq         $t7, $zero, L_80051F6C
    if (ctx->r15 == 0) {
        // 0x80051F0C: nop
    
            goto L_80051F6C;
    }
    // 0x80051F0C: nop

L_80051F10:
    // 0x80051F10: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051F14: jal         0x800507AC
    // 0x80051F18: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    func_800507AC(rdram, ctx);
        goto after_14;
    // 0x80051F18: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    after_14:
    // 0x80051F1C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80051F20: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80051F24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80051F28: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80051F2C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80051F30: and         $t2, $t4, $at
    ctx->r10 = ctx->r12 & ctx->r1;
    // 0x80051F34: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x80051F38: and         $t3, $t5, $at
    ctx->r11 = ctx->r13 & ctx->r1;
    // 0x80051F3C: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80051F40: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80051F44: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80051F48: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80051F4C: nop

    // 0x80051F50: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80051F54: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x80051F58: or          $t6, $t8, $zero
    ctx->r14 = ctx->r24 | 0;
    // 0x80051F5C: ori         $t7, $t9, 0x40
    ctx->r15 = ctx->r25 | 0X40;
    // 0x80051F60: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x80051F64: b           L_80051FC0
    // 0x80051F68: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
        goto L_80051FC0;
    // 0x80051F68: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_80051F6C:
    // 0x80051F6C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80051F70: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80051F74: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051F78: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x80051F7C: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x80051F80: bne         $t0, $zero, L_80051FC0
    if (ctx->r8 != 0) {
        // 0x80051F84: andi        $t1, $t3, 0x40
        ctx->r9 = ctx->r11 & 0X40;
            goto L_80051FC0;
    }
    // 0x80051F84: andi        $t1, $t3, 0x40
    ctx->r9 = ctx->r11 & 0X40;
    // 0x80051F88: bne         $t1, $zero, L_80051FC0
    if (ctx->r9 != 0) {
        // 0x80051F8C: nop
    
            goto L_80051FC0;
    }
    // 0x80051F8C: nop

    // 0x80051F90: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051F94: jal         0x800507AC
    // 0x80051F98: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    func_800507AC(rdram, ctx);
        goto after_15;
    // 0x80051F98: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    after_15:
    // 0x80051F9C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80051FA0: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80051FA4: nop

    // 0x80051FA8: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80051FAC: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x80051FB0: or          $t6, $t8, $zero
    ctx->r14 = ctx->r24 | 0;
    // 0x80051FB4: ori         $t7, $t9, 0x40
    ctx->r15 = ctx->r25 | 0X40;
    // 0x80051FB8: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80051FBC: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_80051FC0:
    // 0x80051FC0: b           L_80052078
    // 0x80051FC4: nop

        goto L_80052078;
    // 0x80051FC4: nop

L_80051FC8:
    // 0x80051FC8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80051FCC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80051FD0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051FD4: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x80051FD8: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x80051FDC: bne         $t0, $zero, L_80051FEC
    if (ctx->r8 != 0) {
        // 0x80051FE0: andi        $t1, $t3, 0x40
        ctx->r9 = ctx->r11 & 0X40;
            goto L_80051FEC;
    }
    // 0x80051FE0: andi        $t1, $t3, 0x40
    ctx->r9 = ctx->r11 & 0X40;
    // 0x80051FE4: beq         $t1, $zero, L_80052020
    if (ctx->r9 == 0) {
        // 0x80051FE8: nop
    
            goto L_80052020;
    }
    // 0x80051FE8: nop

L_80051FEC:
    // 0x80051FEC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80051FF0: jal         0x800507AC
    // 0x80051FF4: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800507AC(rdram, ctx);
        goto after_16;
    // 0x80051FF4: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_16:
    // 0x80051FF8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80051FFC: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052000: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052004: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80052008: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8005200C: and         $t4, $t6, $at
    ctx->r12 = ctx->r14 & ctx->r1;
    // 0x80052010: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80052014: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x80052018: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x8005201C: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
L_80052020:
    // 0x80052020: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80052024: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80052028: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005202C: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x80052030: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80052034: bne         $t0, $zero, L_80052044
    if (ctx->r8 != 0) {
        // 0x80052038: andi        $t1, $t3, 0x20
        ctx->r9 = ctx->r11 & 0X20;
            goto L_80052044;
    }
    // 0x80052038: andi        $t1, $t3, 0x20
    ctx->r9 = ctx->r11 & 0X20;
    // 0x8005203C: beq         $t1, $zero, L_80052078
    if (ctx->r9 == 0) {
        // 0x80052040: nop
    
            goto L_80052078;
    }
    // 0x80052040: nop

L_80052044:
    // 0x80052044: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80052048: jal         0x800507AC
    // 0x8005204C: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    func_800507AC(rdram, ctx);
        goto after_17;
    // 0x8005204C: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_17:
    // 0x80052050: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052054: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80052058: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005205C: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x80052060: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x80052064: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80052068: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8005206C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x80052070: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80052074: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_80052078:
    // 0x80052078: lhu         $t7, 0x34($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X34);
    // 0x8005207C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052080: andi        $t2, $t7, 0x80
    ctx->r10 = ctx->r15 & 0X80;
    // 0x80052084: sra         $t3, $t2, 7
    ctx->r11 = S32(SIGNED(ctx->r10) >> 7);
    // 0x80052088: bne         $t3, $at, L_8005216C
    if (ctx->r11 != ctx->r1) {
        // 0x8005208C: nop
    
            goto L_8005216C;
    }
    // 0x8005208C: nop

    // 0x80052090: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80052094: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80052098: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8005209C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x800520A0: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800520A4: bne         $t8, $zero, L_8005216C
    if (ctx->r24 != 0) {
        // 0x800520A8: andi        $t9, $t5, 0x10
        ctx->r25 = ctx->r13 & 0X10;
            goto L_8005216C;
    }
    // 0x800520A8: andi        $t9, $t5, 0x10
    ctx->r25 = ctx->r13 & 0X10;
    // 0x800520AC: bne         $t9, $zero, L_8005216C
    if (ctx->r25 != 0) {
        // 0x800520B0: nop
    
            goto L_8005216C;
    }
    // 0x800520B0: nop

    // 0x800520B4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800520B8: lh          $t1, 0x7234($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7234);
    // 0x800520BC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800520C0: bne         $t1, $at, L_800520F0
    if (ctx->r9 != ctx->r1) {
        // 0x800520C4: nop
    
            goto L_800520F0;
    }
    // 0x800520C4: nop

    // 0x800520C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800520CC: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x800520D0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800520D4: bne         $t6, $at, L_800520F0
    if (ctx->r14 != ctx->r1) {
        // 0x800520D8: nop
    
            goto L_800520F0;
    }
    // 0x800520D8: nop

    // 0x800520DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800520E0: jal         0x800507AC
    // 0x800520E4: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    func_800507AC(rdram, ctx);
        goto after_18;
    // 0x800520E4: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    after_18:
    // 0x800520E8: b           L_80052148
    // 0x800520EC: nop

        goto L_80052148;
    // 0x800520EC: nop

L_800520F0:
    // 0x800520F0: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x800520F4: jal         0x80056E88
    // 0x800520F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_19;
    // 0x800520F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x800520FC: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80052100: sra         $t7, $s1, 16
    ctx->r15 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80052104: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80052108: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8005210C: jal         0x800507AC
    // 0x80052110: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800507AC(rdram, ctx);
        goto after_20;
    // 0x80052110: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_20:
    // 0x80052114: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80052118: nop

    // 0x8005211C: beq         $t2, $zero, L_80052148
    if (ctx->r10 == 0) {
        // 0x80052120: nop
    
            goto L_80052148;
    }
    // 0x80052120: nop

    // 0x80052124: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80052128: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x8005212C: nop

    // 0x80052130: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80052134: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80052138: ori         $t4, $t0, 0x4
    ctx->r12 = ctx->r8 | 0X4;
    // 0x8005213C: ori         $t5, $t1, 0x0
    ctx->r13 = ctx->r9 | 0X0;
    // 0x80052140: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80052144: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
L_80052148:
    // 0x80052148: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005214C: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80052150: nop

    // 0x80052154: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80052158: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8005215C: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80052160: ori         $t3, $t7, 0x10
    ctx->r11 = ctx->r15 | 0X10;
    // 0x80052164: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80052168: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
L_8005216C:
    // 0x8005216C: b           L_80052174
    // 0x80052170: nop

        goto L_80052174;
    // 0x80052170: nop

L_80052174:
    // 0x80052174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005217C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80052180: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80052184: jr          $ra
    // 0x80052188: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80052188: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800675F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800675F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800675F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800675F8: nop

    // 0x800675FC: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80067600: nop

    // 0x80067604: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067608: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006760C: jr          $ra
    // 0x80067610: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067610: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067614: jr          $ra
    // 0x80067618: nop

    return;
    // 0x80067618: nop

    // 0x8006761C: jr          $ra
    // 0x80067620: nop

    return;
    // 0x80067620: nop

;}
RECOMP_FUNC void func_8006FA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FA50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FA54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FA58: jal         0x80061488
    // 0x8006FA5C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006FA5C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_0:
    // 0x8006FA60: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FA64: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FA68: b           L_8006FA78
    // 0x8006FA6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006FA78;
    // 0x8006FA6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FA70: b           L_8006FA78
    // 0x8006FA74: nop

        goto L_8006FA78;
    // 0x8006FA74: nop

L_8006FA78:
    // 0x8006FA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FA7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FA80: jr          $ra
    // 0x8006FA84: nop

    return;
    // 0x8006FA84: nop

;}
RECOMP_FUNC void func_8006CB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CB60: jal         0x8005F064
    // 0x8006CB64: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CB64: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x8006CB68: b           L_8006CB78
    // 0x8006CB6C: nop

        goto L_8006CB78;
    // 0x8006CB6C: nop

    // 0x8006CB70: b           L_8006CB78
    // 0x8006CB74: nop

        goto L_8006CB78;
    // 0x8006CB74: nop

L_8006CB78:
    // 0x8006CB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CB7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CB80: jr          $ra
    // 0x8006CB84: nop

    return;
    // 0x8006CB84: nop

;}
RECOMP_FUNC void func_8006D880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D888: jal         0x80061488
    // 0x8006D88C: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006D88C: addiu       $a0, $zero, 0x6E3
    ctx->r4 = ADD32(0, 0X6E3);
    after_0:
    // 0x8006D890: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006D894: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006D898: b           L_8006D8A8
    // 0x8006D89C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D8A8;
    // 0x8006D89C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D8A0: b           L_8006D8A8
    // 0x8006D8A4: nop

        goto L_8006D8A8;
    // 0x8006D8A4: nop

L_8006D8A8:
    // 0x8006D8A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D8AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D8B0: jr          $ra
    // 0x8006D8B4: nop

    return;
    // 0x8006D8B4: nop

;}
RECOMP_FUNC void func_80031C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C6C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80031C70: lhu         $v0, -0x6504($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X6504);
    // 0x80031C74: jr          $ra
    // 0x80031C78: nop

    return;
    // 0x80031C78: nop

    // 0x80031C7C: jr          $ra
    // 0x80031C80: nop

    return;
    // 0x80031C80: nop

    // 0x80031C84: jr          $ra
    // 0x80031C88: nop

    return;
    // 0x80031C88: nop

    // 0x80031C8C: nop

;}
RECOMP_FUNC void func_8006DFB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DFB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DFB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DFB8: jal         0x80061348
    // 0x8006DFBC: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DFBC: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x8006DFC0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DFC4: b           L_8006DFD4
    // 0x8006DFC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006DFD4;
    // 0x8006DFC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DFCC: b           L_8006DFD4
    // 0x8006DFD0: nop

        goto L_8006DFD4;
    // 0x8006DFD0: nop

L_8006DFD4:
    // 0x8006DFD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DFD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DFDC: jr          $ra
    // 0x8006DFE0: nop

    return;
    // 0x8006DFE0: nop

;}
RECOMP_FUNC void func_800636A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800636A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800636A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800636A8: nop

    // 0x800636AC: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x800636B0: nop

    // 0x800636B4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800636B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800636BC: jr          $ra
    // 0x800636C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800636C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800636C4: jr          $ra
    // 0x800636C8: nop

    return;
    // 0x800636C8: nop

    // 0x800636CC: jr          $ra
    // 0x800636D0: nop

    return;
    // 0x800636D0: nop

;}
RECOMP_FUNC void func_800A6F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6F20: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800A6F24: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800A6F28: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x800A6F2C: beq         $at, $zero, L_800A6F5C
    if (ctx->r1 == 0) {
        // 0x800A6F30: nop
    
            goto L_800A6F5C;
    }
    // 0x800A6F30: nop

    // 0x800A6F34: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A6F38: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A6F3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A6F40: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A6F44: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x800A6F48: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A6F4C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800A6F50: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A6F54: b           L_800A6FF4
    // 0x800A6F58: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
        goto L_800A6FF4;
    // 0x800A6F58: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
L_800A6F5C:
    // 0x800A6F5C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800A6F60: beq         $at, $zero, L_800A6F94
    if (ctx->r1 == 0) {
        // 0x800A6F64: nop
    
            goto L_800A6F94;
    }
    // 0x800A6F64: nop

    // 0x800A6F68: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800A6F6C: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800A6F70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6F74: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A6F78: lw          $t0, -0x73DC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73DC);
    // 0x800A6F7C: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800A6F80: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800A6F84: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800A6F88: addiu       $t2, $t1, -0x580
    ctx->r10 = ADD32(ctx->r9, -0X580);
    // 0x800A6F8C: b           L_800A6FF4
    // 0x800A6F90: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
        goto L_800A6FF4;
    // 0x800A6F90: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_800A6F94:
    // 0x800A6F94: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x800A6F98: beq         $at, $zero, L_800A6FCC
    if (ctx->r1 == 0) {
        // 0x800A6F9C: nop
    
            goto L_800A6FCC;
    }
    // 0x800A6F9C: nop

    // 0x800A6FA0: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x800A6FA4: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800A6FA8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A6FAC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A6FB0: lw          $t4, -0x73D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73D0);
    // 0x800A6FB4: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800A6FB8: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800A6FBC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A6FC0: addiu       $t6, $t5, -0xB00
    ctx->r14 = ADD32(ctx->r13, -0XB00);
    // 0x800A6FC4: b           L_800A6FF4
    // 0x800A6FC8: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
        goto L_800A6FF4;
    // 0x800A6FC8: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
L_800A6FCC:
    // 0x800A6FCC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A6FD0: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A6FD4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A6FD8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A6FDC: lw          $t8, -0x73C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73C4);
    // 0x800A6FE0: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A6FE4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800A6FE8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A6FEC: addiu       $t0, $t9, -0x1080
    ctx->r8 = ADD32(ctx->r25, -0X1080);
    // 0x800A6FF0: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_800A6FF4:
    // 0x800A6FF4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800A6FF8:
    // 0x800A6FF8: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800A6FFC: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A7000: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x800A7004: nop

    // 0x800A7008: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800A700C: beq         $t3, $zero, L_800A7020
    if (ctx->r11 == 0) {
        // 0x800A7010: nop
    
            goto L_800A7020;
    }
    // 0x800A7010: nop

    // 0x800A7014: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800A7018: nop

    // 0x800A701C: sh          $a1, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r5;
L_800A7020:
    // 0x800A7020: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800A7024: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800A7028: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A702C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800A7030: addiu       $t6, $t5, 0x160
    ctx->r14 = ADD32(ctx->r13, 0X160);
    // 0x800A7034: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800A7038: bne         $at, $zero, L_800A6FF8
    if (ctx->r1 != 0) {
        // 0x800A703C: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_800A6FF8;
    }
    // 0x800A703C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800A7040: b           L_800A7048
    // 0x800A7044: nop

        goto L_800A7048;
    // 0x800A7044: nop

L_800A7048:
    // 0x800A7048: jr          $ra
    // 0x800A704C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800A704C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80072258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007225C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072260: jal         0x80061348
    // 0x80072264: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80072264: addiu       $a0, $zero, 0x44B
    ctx->r4 = ADD32(0, 0X44B);
    after_0:
    // 0x80072268: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007226C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80072270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072274: beq         $v0, $zero, L_800722AC
    if (ctx->r2 == 0) {
        // 0x80072278: nop
    
            goto L_800722AC;
    }
    // 0x80072278: nop

    // 0x8007227C: jal         0x80061348
    // 0x80072280: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80072280: addiu       $a0, $zero, 0x4BE
    ctx->r4 = ADD32(0, 0X4BE);
    after_1:
    // 0x80072284: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80072288: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8007228C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072290: beq         $v0, $zero, L_800722AC
    if (ctx->r2 == 0) {
        // 0x80072294: nop
    
            goto L_800722AC;
    }
    // 0x80072294: nop

    // 0x80072298: jal         0x80061348
    // 0x8007229C: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007229C: addiu       $a0, $zero, 0x4BD
    ctx->r4 = ADD32(0, 0X4BD);
    after_2:
    // 0x800722A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800722A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800722A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800722AC:
    // 0x800722AC: b           L_800722BC
    // 0x800722B0: nop

        goto L_800722BC;
    // 0x800722B0: nop

    // 0x800722B4: b           L_800722BC
    // 0x800722B8: nop

        goto L_800722BC;
    // 0x800722B8: nop

L_800722BC:
    // 0x800722BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800722C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800722C4: jr          $ra
    // 0x800722C8: nop

    return;
    // 0x800722C8: nop

;}
RECOMP_FUNC void func_80012E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012E7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80012E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012E84: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80012E88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80012E8C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80012E90: jal         0x8000DA44
    // 0x80012E94: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012E94: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80012E98: bgez        $v0, L_80012EA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012E9C: nop
    
            goto L_80012EA8;
    }
    // 0x80012E9C: nop

    // 0x80012EA0: b           L_800131E4
    // 0x80012EA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800131E4;
    // 0x80012EA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012EA8:
    // 0x80012EA8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80012EAC: nop

    // 0x80012EB0: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80012EB4: nop

    // 0x80012EB8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80012EBC: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80012EC0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80012EC4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80012EC8: nop

    // 0x80012ECC: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x80012ED0: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80012ED4: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x80012ED8: nop

    // 0x80012EDC: beq         $t2, $zero, L_80012EF4
    if (ctx->r10 == 0) {
        // 0x80012EE0: nop
    
            goto L_80012EF4;
    }
    // 0x80012EE0: nop

    // 0x80012EE4: lhu         $t3, 0x8($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X8);
    // 0x80012EE8: nop

    // 0x80012EEC: bne         $t3, $zero, L_80012F64
    if (ctx->r11 != 0) {
        // 0x80012EF0: nop
    
            goto L_80012F64;
    }
    // 0x80012EF0: nop

L_80012EF4:
    // 0x80012EF4: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x80012EF8: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x80012EFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012F00: beq         $t5, $at, L_80012F10
    if (ctx->r13 == ctx->r1) {
        // 0x80012F04: nop
    
            goto L_80012F10;
    }
    // 0x80012F04: nop

    // 0x80012F08: bne         $t5, $zero, L_80012F28
    if (ctx->r13 != 0) {
        // 0x80012F0C: nop
    
            goto L_80012F28;
    }
    // 0x80012F0C: nop

L_80012F10:
    // 0x80012F10: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80012F14: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80012F18: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80012F1C: nop

    // 0x80012F20: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80012F24: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
L_80012F28:
    // 0x80012F28: addiu       $t9, $sp, 0x20
    ctx->r25 = ADD32(ctx->r29, 0X20);
    // 0x80012F2C: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x80012F30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80012F34: beq         $t0, $at, L_80012F44
    if (ctx->r8 == ctx->r1) {
        // 0x80012F38: nop
    
            goto L_80012F44;
    }
    // 0x80012F38: nop

    // 0x80012F3C: bne         $t0, $zero, L_80012F5C
    if (ctx->r8 != 0) {
        // 0x80012F40: nop
    
            goto L_80012F5C;
    }
    // 0x80012F40: nop

L_80012F44:
    // 0x80012F44: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80012F48: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x80012F4C: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x80012F50: nop

    // 0x80012F54: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80012F58: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
L_80012F5C:
    // 0x80012F5C: b           L_800131E4
    // 0x80012F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800131E4;
    // 0x80012F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012F64:
    // 0x80012F64: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x80012F68: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x80012F6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012F70: beq         $t5, $at, L_80012F80
    if (ctx->r13 == ctx->r1) {
        // 0x80012F74: nop
    
            goto L_80012F80;
    }
    // 0x80012F74: nop

    // 0x80012F78: bne         $t5, $zero, L_8001309C
    if (ctx->r13 != 0) {
        // 0x80012F7C: nop
    
            goto L_8001309C;
    }
    // 0x80012F7C: nop

L_80012F80:
    // 0x80012F80: addiu       $t7, $sp, 0x20
    ctx->r15 = ADD32(ctx->r29, 0X20);
    // 0x80012F84: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x80012F88: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x80012F8C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80012F90: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80012F94: mfhi        $t6
    ctx->r14 = hi;
    // 0x80012F98: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80012F9C: nop

    // 0x80012FA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012FA4: swc1        $f6, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f6.u32l;
    // 0x80012FA8: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    // 0x80012FAC: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x80012FB0: nop

    // 0x80012FB4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80012FB8: bgez        $t1, L_80012FD0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80012FBC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80012FD0;
    }
    // 0x80012FBC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80012FC0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80012FC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80012FC8: nop

    // 0x80012FCC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80012FD0:
    // 0x80012FD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80012FD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80012FD8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80012FDC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80012FE0: lwc1        $f9, -0x2AF8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2AF8);
    // 0x80012FE4: lwc1        $f8, -0x2AF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2AF4);
    // 0x80012FE8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80012FEC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80012FF0: nop

    // 0x80012FF4: div.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f6.d);
    // 0x80012FF8: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80012FFC: swc1        $f10, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->f10.u32l;
    // 0x80013000: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x80013004: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x80013008: nop

    // 0x8001300C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80013010: bgez        $t4, L_8001302C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80013014: cvt.d.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
            goto L_8001302C;
    }
    // 0x80013014: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80013018: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8001301C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80013020: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80013024: nop

    // 0x80013028: add.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f4.d + ctx->f8.d;
L_8001302C:
    // 0x8001302C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80013030: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80013034: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80013038: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001303C: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80013040: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80013044: swc1        $f10, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f10.u32l;
    // 0x80013048: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8001304C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80013050: lwc1        $f18, 0x2C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X2C);
    // 0x80013054: lwc1        $f5, -0x2AF0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2AF0);
    // 0x80013058: lwc1        $f4, -0x2AEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2AEC);
    // 0x8001305C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80013060: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80013064: jal         0x800C3070
    // 0x80013068: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_1;
    // 0x80013068: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_1:
    // 0x8001306C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80013070: nop

    // 0x80013074: lwc1        $f16, 0x34($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X34);
    // 0x80013078: nop

    // 0x8001307C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80013080: swc1        $f10, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f10.u32l;
    // 0x80013084: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80013088: nop

    // 0x8001308C: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x80013090: nop

    // 0x80013094: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80013098: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
L_8001309C:
    // 0x8001309C: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x800130A0: lhu         $t3, 0x4($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X4);
    // 0x800130A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800130A8: beq         $t3, $at, L_800130B8
    if (ctx->r11 == ctx->r1) {
        // 0x800130AC: nop
    
            goto L_800130B8;
    }
    // 0x800130AC: nop

    // 0x800130B0: bne         $t3, $zero, L_800131D4
    if (ctx->r11 != 0) {
        // 0x800130B4: nop
    
            goto L_800131D4;
    }
    // 0x800130B4: nop

L_800130B8:
    // 0x800130B8: addiu       $t2, $sp, 0x20
    ctx->r10 = ADD32(ctx->r29, 0X20);
    // 0x800130BC: lh          $t4, 0xA($t2)
    ctx->r12 = MEM_H(ctx->r10, 0XA);
    // 0x800130C0: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800130C4: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800130C8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800130CC: mfhi        $t5
    ctx->r13 = hi;
    // 0x800130D0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800130D4: nop

    // 0x800130D8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800130DC: swc1        $f8, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f8.u32l;
    // 0x800130E0: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x800130E4: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800130E8: nop

    // 0x800130EC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800130F0: bgez        $t9, L_80013108
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800130F4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80013108;
    }
    // 0x800130F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800130F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800130FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013100: nop

    // 0x80013104: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_80013108:
    // 0x80013108: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001310C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80013110: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80013114: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80013118: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8001311C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80013120: lwc1        $f5, -0x2AE8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2AE8);
    // 0x80013124: lwc1        $f4, -0x2AE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2AE4);
    // 0x80013128: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8001312C: div.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x80013130: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x80013134: swc1        $f6, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f6.u32l;
    // 0x80013138: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x8001313C: lhu         $t1, 0x6($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X6);
    // 0x80013140: nop

    // 0x80013144: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80013148: bgez        $t1, L_80013164
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001314C: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_80013164;
    }
    // 0x8001314C: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x80013150: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80013154: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80013158: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001315C: nop

    // 0x80013160: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_80013164:
    // 0x80013164: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80013168: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001316C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80013170: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80013174: mul.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80013178: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8001317C: swc1        $f6, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f6.u32l;
    // 0x80013180: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80013184: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80013188: lwc1        $f10, 0x3C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X3C);
    // 0x8001318C: lwc1        $f19, -0x2AE0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2AE0);
    // 0x80013190: lwc1        $f18, -0x2ADC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2ADC);
    // 0x80013194: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80013198: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8001319C: jal         0x800C3070
    // 0x800131A0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_2;
    // 0x800131A0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_2:
    // 0x800131A4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800131A8: nop

    // 0x800131AC: lwc1        $f16, 0x44($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X44);
    // 0x800131B0: nop

    // 0x800131B4: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800131B8: swc1        $f6, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f6.u32l;
    // 0x800131BC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800131C0: nop

    // 0x800131C4: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x800131C8: nop

    // 0x800131CC: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x800131D0: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
L_800131D4:
    // 0x800131D4: b           L_800131E4
    // 0x800131D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800131E4;
    // 0x800131D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800131DC: b           L_800131E4
    // 0x800131E0: nop

        goto L_800131E4;
    // 0x800131E0: nop

L_800131E4:
    // 0x800131E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800131E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800131EC: jr          $ra
    // 0x800131F0: nop

    return;
    // 0x800131F0: nop

;}
RECOMP_FUNC void func_800635EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800635EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800635F0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800635F4: nop

    // 0x800635F8: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x800635FC: nop

    // 0x80063600: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063604: jr          $ra
    // 0x80063608: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063608: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006360C: jr          $ra
    // 0x80063610: nop

    return;
    // 0x80063610: nop

    // 0x80063614: jr          $ra
    // 0x80063618: nop

    return;
    // 0x80063618: nop

;}
RECOMP_FUNC void func_80055148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005514C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055150: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80055154: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80055158: nop

    // 0x8005515C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80055160: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80055164: andi        $t0, $t8, 0x8
    ctx->r8 = ctx->r24 & 0X8;
    // 0x80055168: bne         $t0, $zero, L_80055178
    if (ctx->r8 != 0) {
        // 0x8005516C: andi        $t1, $t9, 0x0
        ctx->r9 = ctx->r25 & 0X0;
            goto L_80055178;
    }
    // 0x8005516C: andi        $t1, $t9, 0x0
    ctx->r9 = ctx->r25 & 0X0;
    // 0x80055170: beq         $t1, $zero, L_8005522C
    if (ctx->r9 == 0) {
        // 0x80055174: nop
    
            goto L_8005522C;
    }
    // 0x80055174: nop

L_80055178:
    // 0x80055178: jal         0x8005A768
    // 0x8005517C: nop

    func_8005A768(rdram, ctx);
        goto after_0;
    // 0x8005517C: nop

    after_0:
    // 0x80055180: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80055184: lw          $t7, 0x6CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6CC);
    // 0x80055188: nop

    // 0x8005518C: subu        $t2, $v0, $t7
    ctx->r10 = SUB32(ctx->r2, ctx->r15);
    // 0x80055190: slti        $at, $t2, 0x79
    ctx->r1 = SIGNED(ctx->r10) < 0X79 ? 1 : 0;
    // 0x80055194: bne         $at, $zero, L_80055224
    if (ctx->r1 != 0) {
        // 0x80055198: nop
    
            goto L_80055224;
    }
    // 0x80055198: nop

    // 0x8005519C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800551A0: lh          $t3, 0x6C0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X6C0);
    // 0x800551A4: nop

    // 0x800551A8: bne         $t3, $zero, L_80055224
    if (ctx->r11 != 0) {
        // 0x800551AC: nop
    
            goto L_80055224;
    }
    // 0x800551AC: nop

    // 0x800551B0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800551B4: lbu         $t4, 0x125A($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X125A);
    // 0x800551B8: nop

    // 0x800551BC: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800551C0: bne         $t5, $zero, L_80055224
    if (ctx->r13 != 0) {
        // 0x800551C4: nop
    
            goto L_80055224;
    }
    // 0x800551C4: nop

    // 0x800551C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800551CC: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x800551D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800551D4: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800551D8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800551DC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800551E0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800551E4: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800551E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800551EC: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800551F0: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x800551F4: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x800551F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800551FC: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80055200: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80055204: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80055208: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x8005520C: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x80055210: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x80055214: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80055218: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8005521C: b           L_80055488
    // 0x80055220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055488;
    // 0x80055220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80055224:
    // 0x80055224: b           L_80055488
    // 0x80055228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x80055228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005522C:
    // 0x8005522C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80055230: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80055234: nop

    // 0x80055238: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x8005523C: nop

    // 0x80055240: slti        $at, $t9, 0x384
    ctx->r1 = SIGNED(ctx->r25) < 0X384 ? 1 : 0;
    // 0x80055244: bne         $at, $zero, L_80055254
    if (ctx->r1 != 0) {
        // 0x80055248: nop
    
            goto L_80055254;
    }
    // 0x80055248: nop

    // 0x8005524C: b           L_80055488
    // 0x80055250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x80055250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80055254:
    // 0x80055254: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80055258: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8005525C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80055260: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80055264: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x80055268: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8005526C: bne         $t2, $zero, L_8005527C
    if (ctx->r10 != 0) {
        // 0x80055270: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_8005527C;
    }
    // 0x80055270: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x80055274: beq         $t3, $zero, L_80055338
    if (ctx->r11 == 0) {
        // 0x80055278: nop
    
            goto L_80055338;
    }
    // 0x80055278: nop

L_8005527C:
    // 0x8005527C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80055280: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80055284: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055288: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8005528C: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x80055290: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80055294: lui         $at, 0xDFFF
    ctx->r1 = S32(0XDFFF << 16);
    // 0x80055298: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8005529C: and         $t9, $t5, $at
    ctx->r25 = ctx->r13 & ctx->r1;
    // 0x800552A0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800552A4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800552A8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800552AC: lw          $t0, 0x5A8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5A8);
    // 0x800552B0: nop

    // 0x800552B4: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800552B8: nop

    // 0x800552BC: bne         $t6, $zero, L_800552F4
    if (ctx->r14 != 0) {
        // 0x800552C0: nop
    
            goto L_800552F4;
    }
    // 0x800552C0: nop

    // 0x800552C4: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x800552C8: nop

    // 0x800552CC: bne         $t7, $zero, L_800552F4
    if (ctx->r15 != 0) {
        // 0x800552D0: nop
    
            goto L_800552F4;
    }
    // 0x800552D0: nop

    // 0x800552D4: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x800552D8: nop

    // 0x800552DC: bne         $t2, $zero, L_800552F4
    if (ctx->r10 != 0) {
        // 0x800552E0: nop
    
            goto L_800552F4;
    }
    // 0x800552E0: nop

    // 0x800552E4: lh          $t3, 0x6($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X6);
    // 0x800552E8: nop

    // 0x800552EC: beq         $t3, $zero, L_80055330
    if (ctx->r11 == 0) {
        // 0x800552F0: nop
    
            goto L_80055330;
    }
    // 0x800552F0: nop

L_800552F4:
    // 0x800552F4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800552F8: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800552FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80055300: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80055304: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80055308: or          $t6, $t8, $zero
    ctx->r14 = ctx->r24 | 0;
    // 0x8005530C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80055310: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80055314: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80055318: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005531C: sw          $zero, 0x6CC($at)
    MEM_W(0X6CC, ctx->r1) = 0;
    // 0x80055320: b           L_80055488
    // 0x80055324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055488;
    // 0x80055324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80055328: b           L_80055338
    // 0x8005532C: nop

        goto L_80055338;
    // 0x8005532C: nop

L_80055330:
    // 0x80055330: b           L_80055488
    // 0x80055334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x80055334: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80055338:
    // 0x80055338: jal         0x8005A578
    // 0x8005533C: nop

    func_8005A578(rdram, ctx);
        goto after_1;
    // 0x8005533C: nop

    after_1:
    // 0x80055340: beq         $v0, $zero, L_80055478
    if (ctx->r2 == 0) {
        // 0x80055344: nop
    
            goto L_80055478;
    }
    // 0x80055344: nop

    // 0x80055348: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005534C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80055350: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80055354: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x80055358: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8005535C: bne         $t0, $zero, L_80055478
    if (ctx->r8 != 0) {
        // 0x80055360: andi        $t1, $t3, 0x1000
        ctx->r9 = ctx->r11 & 0X1000;
            goto L_80055478;
    }
    // 0x80055360: andi        $t1, $t3, 0x1000
    ctx->r9 = ctx->r11 & 0X1000;
    // 0x80055364: bne         $t1, $zero, L_80055478
    if (ctx->r9 != 0) {
        // 0x80055368: nop
    
            goto L_80055478;
    }
    // 0x80055368: nop

    // 0x8005536C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80055370: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x80055374: addiu       $at, $zero, 0xE10
    ctx->r1 = ADD32(0, 0XE10);
    // 0x80055378: lh          $t9, 0x3E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X3E);
    // 0x8005537C: nop

    // 0x80055380: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80055384: mflo        $t6
    ctx->r14 = lo;
    // 0x80055388: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8005538C: beq         $at, $zero, L_800553A4
    if (ctx->r1 == 0) {
        // 0x80055390: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800553A4;
    }
    // 0x80055390: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80055394: lh          $t7, 0x3E($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X3E);
    // 0x80055398: nop

    // 0x8005539C: bgez        $t7, L_800553BC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800553A0: nop
    
            goto L_800553BC;
    }
    // 0x800553A0: nop

L_800553A4:
    // 0x800553A4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800553A8: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800553AC: addiu       $t4, $zero, 0xE10
    ctx->r12 = ADD32(0, 0XE10);
    // 0x800553B0: sh          $t4, 0x3E($t5)
    MEM_H(0X3E, ctx->r13) = ctx->r12;
    // 0x800553B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800553B8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_800553BC:
    // 0x800553BC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800553C0: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x800553C4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800553C8: lh          $t0, 0x3C($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X3C);
    // 0x800553CC: nop

    // 0x800553D0: beq         $t0, $t1, L_80055478
    if (ctx->r8 == ctx->r9) {
        // 0x800553D4: nop
    
            goto L_80055478;
    }
    // 0x800553D4: nop

    // 0x800553D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800553DC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800553E0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800553E4: nop

    // 0x800553E8: sh          $t9, 0x3C($t6)
    MEM_H(0X3C, ctx->r14) = ctx->r25;
    // 0x800553EC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800553F0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800553F4: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x800553F8: lw          $t4, 0x5A8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5A8);
    // 0x800553FC: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80055400: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80055404: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x80055408: lh          $t2, 0x0($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X0);
    // 0x8005540C: nop

    // 0x80055410: bne         $t2, $zero, L_80055448
    if (ctx->r10 != 0) {
        // 0x80055414: nop
    
            goto L_80055448;
    }
    // 0x80055414: nop

    // 0x80055418: lh          $t3, 0x2($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X2);
    // 0x8005541C: nop

    // 0x80055420: bne         $t3, $zero, L_80055448
    if (ctx->r11 != 0) {
        // 0x80055424: nop
    
            goto L_80055448;
    }
    // 0x80055424: nop

    // 0x80055428: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
    // 0x8005542C: nop

    // 0x80055430: bne         $t0, $zero, L_80055448
    if (ctx->r8 != 0) {
        // 0x80055434: nop
    
            goto L_80055448;
    }
    // 0x80055434: nop

    // 0x80055438: lh          $t1, 0x6($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X6);
    // 0x8005543C: nop

    // 0x80055440: beq         $t1, $zero, L_80055478
    if (ctx->r9 == 0) {
        // 0x80055444: nop
    
            goto L_80055478;
    }
    // 0x80055444: nop

L_80055448:
    // 0x80055448: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005544C: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80055450: nop

    // 0x80055454: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80055458: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8005545C: or          $t4, $t9, $zero
    ctx->r12 = ctx->r25 | 0;
    // 0x80055460: ori         $t8, $t6, 0x8
    ctx->r24 = ctx->r14 | 0X8;
    // 0x80055464: ori         $t9, $t7, 0x0
    ctx->r25 = ctx->r15 | 0X0;
    // 0x80055468: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8005546C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80055470: b           L_80055488
    // 0x80055474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x80055474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80055478:
    // 0x80055478: b           L_80055488
    // 0x8005547C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055488;
    // 0x8005547C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80055480: b           L_80055488
    // 0x80055484: nop

        goto L_80055488;
    // 0x80055484: nop

L_80055488:
    // 0x80055488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005548C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80055490: jr          $ra
    // 0x80055494: nop

    return;
    // 0x80055494: nop

;}
RECOMP_FUNC void func_8006CEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CEB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CEB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CEBC: nop

    // 0x8006CEC0: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x8006CEC4: nop

    // 0x8006CEC8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CECC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CED0: jr          $ra
    // 0x8006CED4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CED4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CED8: jr          $ra
    // 0x8006CEDC: nop

    return;
    // 0x8006CEDC: nop

    // 0x8006CEE0: jr          $ra
    // 0x8006CEE4: nop

    return;
    // 0x8006CEE4: nop

;}
RECOMP_FUNC void func_8008D34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D34C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8008D350: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D354: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8008D358: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8008D35C: beq         $t6, $zero, L_8008D42C
    if (ctx->r14 == 0) {
        // 0x8008D360: sw          $t6, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r14;
            goto L_8008D42C;
    }
    // 0x8008D360: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
L_8008D364:
    // 0x8008D364: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8008D368: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D36C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8008D370: nop

    // 0x8008D374: swc1        $f4, 0xE8($t7)
    MEM_W(0XE8, ctx->r15) = ctx->f4.u32l;
    // 0x8008D378: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8008D37C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008D380: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8008D384: nop

    // 0x8008D388: swc1        $f6, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f6.u32l;
    // 0x8008D38C: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008D390: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008D394: lwc1        $f8, 0xE8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XE8);
    // 0x8008D398: lwc1        $f17, -0xA10($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0XA10);
    // 0x8008D39C: lwc1        $f16, -0xA0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XA0C);
    // 0x8008D3A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8008D3A4: nop

    // 0x8008D3A8: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x8008D3AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8008D3B0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8008D3B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008D3B8: nop

    // 0x8008D3BC: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x8008D3C0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8008D3C4: swc1        $f12, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f12.u32l;
    // 0x8008D3C8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8008D3CC: nop

    // 0x8008D3D0: swc1        $f12, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->f12.u32l;
    // 0x8008D3D4: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8008D3D8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8008D3DC: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x8008D3E0: nop

    // 0x8008D3E4: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8008D3E8: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
    // 0x8008D3EC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8008D3F0: nop

    // 0x8008D3F4: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x8008D3F8: nop

    // 0x8008D3FC: ori         $t6, $t5, 0x810
    ctx->r14 = ctx->r13 | 0X810;
    // 0x8008D400: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x8008D404: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8008D408: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8008D40C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008D410: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8008D414: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x8008D418: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x8008D41C: beq         $at, $zero, L_8008D42C
    if (ctx->r1 == 0) {
        // 0x8008D420: sw          $t8, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r24;
            goto L_8008D42C;
    }
    // 0x8008D420: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8008D424: bne         $t0, $zero, L_8008D364
    if (ctx->r8 != 0) {
        // 0x8008D428: nop
    
            goto L_8008D364;
    }
    // 0x8008D428: nop

L_8008D42C:
    // 0x8008D42C: lw          $t2, 0x230($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X230);
    // 0x8008D430: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8008D434: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8008D438: sw          $t3, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r11;
    // 0x8008D43C: lw          $t1, 0x230($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X230);
    // 0x8008D440: nop

    // 0x8008D444: ori         $t5, $t1, 0x810
    ctx->r13 = ctx->r9 | 0X810;
    // 0x8008D448: sw          $t5, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r13;
    // 0x8008D44C: b           L_8008D454
    // 0x8008D450: nop

        goto L_8008D454;
    // 0x8008D450: nop

L_8008D454:
    // 0x8008D454: jr          $ra
    // 0x8008D458: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8008D458: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006A988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A990: jal         0x80061488
    // 0x8006A994: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006A994: addiu       $a0, $zero, 0x3BF
    ctx->r4 = ADD32(0, 0X3BF);
    after_0:
    // 0x8006A998: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006A99C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006A9A0: b           L_8006A9B0
    // 0x8006A9A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006A9B0;
    // 0x8006A9A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006A9A8: b           L_8006A9B0
    // 0x8006A9AC: nop

        goto L_8006A9B0;
    // 0x8006A9AC: nop

L_8006A9B0:
    // 0x8006A9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A9B8: jr          $ra
    // 0x8006A9BC: nop

    return;
    // 0x8006A9BC: nop

;}
RECOMP_FUNC void func_800B7B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7B94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B7B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7B9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B7BA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800B7BA4:
    // 0x800B7BA4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B7BA8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7BAC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B7BB0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7BB4: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B7BB8: sh          $t7, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r15;
    // 0x800B7BBC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800B7BC0: nop

    // 0x800B7BC4: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B7BC8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B7BCC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7BD0: nop

    // 0x800B7BD4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B7BD8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800B7BDC: bne         $at, $zero, L_800B7BA4
    if (ctx->r1 != 0) {
        // 0x800B7BE0: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_800B7BA4;
    }
    // 0x800B7BE0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800B7BE4: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x800B7BE8: lhu         $a0, 0x2($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X2);
    // 0x800B7BEC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800B7BF0: jal         0x8000D934
    // 0x800B7BF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8000D934(rdram, ctx);
        goto after_0;
    // 0x800B7BF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x800B7BF8: bgez        $v0, L_800B7C08
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B7BFC: nop
    
            goto L_800B7C08;
    }
    // 0x800B7BFC: nop

    // 0x800B7C00: b           L_800B7C3C
    // 0x800B7C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B7C3C;
    // 0x800B7C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B7C08:
    // 0x800B7C08: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800B7C0C: lw          $t6, -0x7F4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7F4);
    // 0x800B7C10: nop

    // 0x800B7C14: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800B7C18: nop

    // 0x800B7C1C: lw          $t7, 0x1A8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X1A8);
    // 0x800B7C20: nop

    // 0x800B7C24: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x800B7C28: sw          $t9, 0x1A8($t8)
    MEM_W(0X1A8, ctx->r24) = ctx->r25;
    // 0x800B7C2C: b           L_800B7C3C
    // 0x800B7C30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800B7C3C;
    // 0x800B7C30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800B7C34: b           L_800B7C3C
    // 0x800B7C38: nop

        goto L_800B7C3C;
    // 0x800B7C38: nop

L_800B7C3C:
    // 0x800B7C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7C40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B7C44: jr          $ra
    // 0x800B7C48: nop

    return;
    // 0x800B7C48: nop

;}
RECOMP_FUNC void func_8008DFA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DFA8: lh          $t6, 0x168($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X168);
    // 0x8008DFAC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008DFB0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8008DFB4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8008DFB8: lh          $t8, 0x4C3C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X4C3C);
    // 0x8008DFBC: nop

    // 0x8008DFC0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8008DFC4: nop

    // 0x8008DFC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008DFCC: swc1        $f6, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = ctx->f6.u32l;
    // 0x8008DFD0: lh          $t9, 0x168($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X168);
    // 0x8008DFD4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008DFD8: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8008DFDC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8008DFE0: lh          $t1, 0x4C3E($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4C3E);
    // 0x8008DFE4: nop

    // 0x8008DFE8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8008DFEC: nop

    // 0x8008DFF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008DFF4: swc1        $f10, 0xD8($a0)
    MEM_W(0XD8, ctx->r4) = ctx->f10.u32l;
    // 0x8008DFF8: lh          $t2, 0x168($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X168);
    // 0x8008DFFC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008E000: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8008E004: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8008E008: lh          $t4, 0x4C40($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X4C40);
    // 0x8008E00C: nop

    // 0x8008E010: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8008E014: nop

    // 0x8008E018: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008E01C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8008E020: nop

    // 0x8008E024: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8008E028: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008E02C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008E030: nop

    // 0x8008E034: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8008E038: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8008E03C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8008E040: sh          $t6, 0x108($a0)
    MEM_H(0X108, ctx->r4) = ctx->r14;
    // 0x8008E044: nop

    // 0x8008E048: lh          $t7, 0x168($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X168);
    // 0x8008E04C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008E050: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8008E054: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008E058: lh          $t9, 0x4C42($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X4C42);
    // 0x8008E05C: nop

    // 0x8008E060: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8008E064: nop

    // 0x8008E068: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008E06C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8008E070: nop

    // 0x8008E074: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8008E078: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008E07C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008E080: nop

    // 0x8008E084: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008E088: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8008E08C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8008E090: sh          $t1, 0x10A($a0)
    MEM_H(0X10A, ctx->r4) = ctx->r9;
    // 0x8008E094: nop

    // 0x8008E098: jr          $ra
    // 0x8008E09C: nop

    return;
    // 0x8008E09C: nop

    // 0x8008E0A0: jr          $ra
    // 0x8008E0A4: nop

    return;
    // 0x8008E0A4: nop

;}
RECOMP_FUNC void ObjectCheckDebugMenu_LoadSpriteHeader(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F60C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001F610: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001F614: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001F618: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001F61C: lui         $t6, 0x8041
    ctx->r14 = S32(0X8041 << 16);
    // 0x8001F620: lui         $t7, 0x8040
    ctx->r15 = S32(0X8040 << 16);
    // 0x8001F624: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001F628: addiu       $t7, $t7, 0x0
    ctx->r15 = ADD32(ctx->r15, 0X0);
    // 0x8001F62C: addiu       $t6, $t6, -0x64C0
    ctx->r14 = ADD32(ctx->r14, -0X64C0);
    // 0x8001F630: subu        $s0, $t6, $t7
    ctx->r16 = SUB32(ctx->r14, ctx->r15);
    // 0x8001F634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001F638: jal         0x800BC6EC
    // 0x8001F63C: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8001F63C: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    after_0:
    // 0x8001F640: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8001F644: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001F648: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001F64C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8001F650: lw          $a2, 0xD30($a2)
    ctx->r6 = MEM_W(ctx->r6, 0XD30);
    // 0x8001F654: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x8001F658: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x8001F65C: jal         0x800BD1FC
    // 0x8001F660: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x8001F660: nop

    after_1:
    // 0x8001F664: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001F668: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001F66C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8001F670: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x8001F674: jal         0x800BD218
    // 0x8001F678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x8001F678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8001F67C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001F680: nop

    // 0x8001F684: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8001F688: nop

    // 0x8001F68C: srl         $t2, $t1, 4
    ctx->r10 = S32(U32(ctx->r9) >> 4);
    // 0x8001F690: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8001F694: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8001F698: b           L_8001F6A8
    // 0x8001F69C: nop

        goto L_8001F6A8;
    // 0x8001F69C: nop

    // 0x8001F6A0: b           L_8001F6A8
    // 0x8001F6A4: nop

        goto L_8001F6A8;
    // 0x8001F6A4: nop

L_8001F6A8:
    // 0x8001F6A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F6AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F6B0: jr          $ra
    // 0x8001F6B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001F6B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800292B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800292B0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800292B4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800292B8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800292BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800292C0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800292C4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800292C8: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x800292CC: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x800292D0: nop

    // 0x800292D4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800292D8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800292DC: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x800292E0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800292E4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800292E8: nop

    // 0x800292EC: beq         $t9, $zero, L_80029378
    if (ctx->r25 == 0) {
        // 0x800292F0: nop
    
            goto L_80029378;
    }
    // 0x800292F0: nop

L_800292F4:
    // 0x800292F4: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800292F8: nop

    // 0x800292FC: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80029300: nop

    // 0x80029304: sh          $t1, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r9;
    // 0x80029308: lh          $t2, 0xE($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XE);
    // 0x8002930C: nop

    // 0x80029310: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029314: bne         $at, $zero, L_80029340
    if (ctx->r1 != 0) {
        // 0x80029318: nop
    
            goto L_80029340;
    }
    // 0x80029318: nop

    // 0x8002931C: bne         $t2, $a0, L_80029348
    if (ctx->r10 != ctx->r4) {
        // 0x80029320: nop
    
            goto L_80029348;
    }
    // 0x80029320: nop

    // 0x80029324: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80029328: nop

    // 0x8002932C: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80029330: nop

    // 0x80029334: slt         $at, $a1, $t4
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029338: beq         $at, $zero, L_80029348
    if (ctx->r1 == 0) {
        // 0x8002933C: nop
    
            goto L_80029348;
    }
    // 0x8002933C: nop

L_80029340:
    // 0x80029340: b           L_80029378
    // 0x80029344: nop

        goto L_80029378;
    // 0x80029344: nop

L_80029348:
    // 0x80029348: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8002934C: nop

    // 0x80029350: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80029354: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80029358: nop

    // 0x8002935C: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80029360: nop

    // 0x80029364: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80029368: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8002936C: nop

    // 0x80029370: bne         $t8, $zero, L_800292F4
    if (ctx->r24 != 0) {
        // 0x80029374: nop
    
            goto L_800292F4;
    }
    // 0x80029374: nop

L_80029378:
    // 0x80029378: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8002937C: b           L_8002938C
    // 0x80029380: nop

        goto L_8002938C;
    // 0x80029380: nop

    // 0x80029384: b           L_8002938C
    // 0x80029388: nop

        goto L_8002938C;
    // 0x80029388: nop

L_8002938C:
    // 0x8002938C: jr          $ra
    // 0x80029390: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80029390: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80031D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031D94: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80031D98: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80031D9C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80031DA0: sw          $t6, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = ctx->r14;
    // 0x80031DA4: sh          $zero, 0x208($a0)
    MEM_H(0X208, ctx->r4) = 0;
    // 0x80031DA8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80031DAC:
    // 0x80031DAC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80031DB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80031DB4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80031DB8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80031DBC: swc1        $f4, 0x1EC($t9)
    MEM_W(0X1EC, ctx->r25) = ctx->f4.u32l;
    // 0x80031DC0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80031DC4: nop

    // 0x80031DC8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80031DCC: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80031DD0: lwc1        $f6, 0x1EC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X1EC);
    // 0x80031DD4: addu        $t3, $a0, $t1
    ctx->r11 = ADD32(ctx->r4, ctx->r9);
    // 0x80031DD8: swc1        $f6, 0x1E8($t3)
    MEM_W(0X1E8, ctx->r11) = ctx->f6.u32l;
    // 0x80031DDC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80031DE0: nop

    // 0x80031DE4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80031DE8: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80031DEC: bne         $at, $zero, L_80031DAC
    if (ctx->r1 != 0) {
        // 0x80031DF0: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_80031DAC;
    }
    // 0x80031DF0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80031DF4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80031DF8:
    // 0x80031DF8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80031DFC: nop

    // 0x80031E00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031E04: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80031E08: sw          $zero, 0x20C($t8)
    MEM_W(0X20C, ctx->r24) = 0;
    // 0x80031E0C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80031E10: nop

    // 0x80031E14: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80031E18: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x80031E1C: bne         $at, $zero, L_80031DF8
    if (ctx->r1 != 0) {
        // 0x80031E20: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_80031DF8;
    }
    // 0x80031E20: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80031E24: b           L_80031E34
    // 0x80031E28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031E34;
    // 0x80031E28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031E2C: b           L_80031E34
    // 0x80031E30: nop

        goto L_80031E34;
    // 0x80031E30: nop

L_80031E34:
    // 0x80031E34: jr          $ra
    // 0x80031E38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80031E38: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80068A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068A50: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068A54: nop

    // 0x80068A58: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80068A5C: nop

    // 0x80068A60: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80068A64: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068A68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068A6C: bne         $v0, $zero, L_80068A88
    if (ctx->r2 != 0) {
        // 0x80068A70: nop
    
            goto L_80068A88;
    }
    // 0x80068A70: nop

    // 0x80068A74: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80068A78: nop

    // 0x80068A7C: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80068A80: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80068A84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80068A88:
    // 0x80068A88: jr          $ra
    // 0x80068A8C: nop

    return;
    // 0x80068A8C: nop

    // 0x80068A90: jr          $ra
    // 0x80068A94: nop

    return;
    // 0x80068A94: nop

    // 0x80068A98: jr          $ra
    // 0x80068A9C: nop

    return;
    // 0x80068A9C: nop

;}
RECOMP_FUNC void func_80031C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C24: jr          $ra
    // 0x80031C28: nop

    return;
    // 0x80031C28: nop

    // 0x80031C2C: jr          $ra
    // 0x80031C30: nop

    return;
    // 0x80031C30: nop

;}
RECOMP_FUNC void SysMem_HeapInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC620: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BC624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC628: jal         0x800C41A0
    // 0x800BC62C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800BC62C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800BC630: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BC634: lui         $t6, 0x8022
    ctx->r14 = S32(0X8022 << 16);
    // 0x800BC638: addiu       $t6, $t6, 0x5800
    ctx->r14 = ADD32(ctx->r14, 0X5800);
    // 0x800BC63C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC640: sw          $t6, 0x25DC($at)
    MEM_W(0X25DC, ctx->r1) = ctx->r14;
    // 0x800BC644: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BC648: lw          $t7, 0x25DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25DC);
    // 0x800BC64C: nop

    // 0x800BC650: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    // 0x800BC654: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BC658: lw          $t9, 0x25DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X25DC);
    // 0x800BC65C: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x800BC660: ori         $t8, $t8, 0xB4FF
    ctx->r24 = ctx->r24 | 0XB4FF;
    // 0x800BC664: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x800BC668: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BC66C: lw          $t0, 0x25DC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X25DC);
    // 0x800BC670: nop

    // 0x800BC674: sw          $t0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r8;
    // 0x800BC678: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BC67C: lw          $t1, 0x25DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X25DC);
    // 0x800BC680: lui         $t4, 0x8022
    ctx->r12 = S32(0X8022 << 16);
    // 0x800BC684: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800BC688: addiu       $t4, $t4, 0x5800
    ctx->r12 = ADD32(ctx->r12, 0X5800);
    // 0x800BC68C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800BC690: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BC694: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BC698: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BC69C: lw          $t6, 0x25DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X25DC);
    // 0x800BC6A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC6A4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800BC6A8: nop

    // 0x800BC6AC: sw          $t7, 0x25E8($at)
    MEM_W(0X25E8, ctx->r1) = ctx->r15;
    // 0x800BC6B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC6B4: sw          $zero, 0x2610($at)
    MEM_W(0X2610, ctx->r1) = 0;
    // 0x800BC6B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC6BC: sh          $zero, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = 0;
    // 0x800BC6C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC6C4: sw          $zero, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = 0;
    // 0x800BC6C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC6CC: jal         0x800C41A0
    // 0x800BC6D0: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800BC6D0: nop

    after_1:
    // 0x800BC6D4: b           L_800BC6DC
    // 0x800BC6D8: nop

        goto L_800BC6DC;
    // 0x800BC6D8: nop

L_800BC6DC:
    // 0x800BC6DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BC6E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BC6E4: jr          $ra
    // 0x800BC6E8: nop

    return;
    // 0x800BC6E8: nop

;}
RECOMP_FUNC void func_800719D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800719D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800719D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800719DC: jal         0x80061348
    // 0x800719E0: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800719E0: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    after_0:
    // 0x800719E4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800719E8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800719EC: b           L_800719FC
    // 0x800719F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800719FC;
    // 0x800719F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800719F4: b           L_800719FC
    // 0x800719F8: nop

        goto L_800719FC;
    // 0x800719F8: nop

L_800719FC:
    // 0x800719FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071A04: jr          $ra
    // 0x80071A08: nop

    return;
    // 0x80071A08: nop

;}
RECOMP_FUNC void func_800665A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800665A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800665A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800665A8: jal         0x80061348
    // 0x800665AC: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800665AC: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x800665B0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800665B4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800665B8: beq         $v0, $zero, L_800665D0
    if (ctx->r2 == 0) {
        // 0x800665BC: nop
    
            goto L_800665D0;
    }
    // 0x800665BC: nop

    // 0x800665C0: jal         0x80061348
    // 0x800665C4: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800665C4: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x800665C8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800665CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800665D0:
    // 0x800665D0: b           L_800665E0
    // 0x800665D4: nop

        goto L_800665E0;
    // 0x800665D4: nop

    // 0x800665D8: b           L_800665E0
    // 0x800665DC: nop

        goto L_800665E0;
    // 0x800665DC: nop

L_800665E0:
    // 0x800665E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800665E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800665E8: jr          $ra
    // 0x800665EC: nop

    return;
    // 0x800665EC: nop

;}
RECOMP_FUNC void func_800B5558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5558: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B555C: lbu         $t7, 0x30($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X30);
    // 0x800B5560: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x800B5564: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800B5568: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B556C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B5570: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B5574: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800B5578: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800B557C: nop

    // 0x800B5580: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x800B5584: nop

    // 0x800B5588: sw          $t1, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->r9;
    // 0x800B558C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800B5590: nop

    // 0x800B5594: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x800B5598: nop

    // 0x800B559C: sw          $t3, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->r11;
    // 0x800B55A0: b           L_800B55A8
    // 0x800B55A4: nop

        goto L_800B55A8;
    // 0x800B55A4: nop

L_800B55A8:
    // 0x800B55A8: jr          $ra
    // 0x800B55AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B55AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80073F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073F94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073F98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073F9C: jal         0x80061348
    // 0x80073FA0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073FA0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073FA4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073FA8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073FAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073FB0: beq         $v0, $zero, L_80074004
    if (ctx->r2 == 0) {
        // 0x80073FB4: nop
    
            goto L_80074004;
    }
    // 0x80073FB4: nop

    // 0x80073FB8: jal         0x80061348
    // 0x80073FBC: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80073FBC: addiu       $a0, $zero, 0x4D3
    ctx->r4 = ADD32(0, 0X4D3);
    after_1:
    // 0x80073FC0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80073FC4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80073FC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073FCC: beq         $v0, $zero, L_80074004
    if (ctx->r2 == 0) {
        // 0x80073FD0: nop
    
            goto L_80074004;
    }
    // 0x80073FD0: nop

    // 0x80073FD4: jal         0x80061348
    // 0x80073FD8: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80073FD8: addiu       $a0, $zero, 0x4D4
    ctx->r4 = ADD32(0, 0X4D4);
    after_2:
    // 0x80073FDC: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80073FE0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80073FE4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80073FE8: beq         $v0, $zero, L_80074004
    if (ctx->r2 == 0) {
        // 0x80073FEC: nop
    
            goto L_80074004;
    }
    // 0x80073FEC: nop

    // 0x80073FF0: jal         0x80061348
    // 0x80073FF4: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80073FF4: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    after_3:
    // 0x80073FF8: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80073FFC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074000: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074004:
    // 0x80074004: b           L_80074014
    // 0x80074008: nop

        goto L_80074014;
    // 0x80074008: nop

    // 0x8007400C: b           L_80074014
    // 0x80074010: nop

        goto L_80074014;
    // 0x80074010: nop

L_80074014:
    // 0x80074014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007401C: jr          $ra
    // 0x80074020: nop

    return;
    // 0x80074020: nop

;}
RECOMP_FUNC void func_800678C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800678C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800678CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800678D0: jal         0x80061488
    // 0x800678D4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800678D4: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x800678D8: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800678DC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800678E0: b           L_800678F0
    // 0x800678E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800678F0;
    // 0x800678E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800678E8: b           L_800678F0
    // 0x800678EC: nop

        goto L_800678F0;
    // 0x800678EC: nop

L_800678F0:
    // 0x800678F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800678F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800678F8: jr          $ra
    // 0x800678FC: nop

    return;
    // 0x800678FC: nop

;}
RECOMP_FUNC void Thread_UnkDbgFunc1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0FB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0FBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C0FC0: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C0FC4: jal         0x800C0C8C
    // 0x800C0FC8: nop

    Thread_Start(rdram, ctx);
        goto after_0;
    // 0x800C0FC8: nop

    after_0:
    // 0x800C0FCC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0FD0: jal         0x800C0D34
    // 0x800C0FD4: nop

    Thread_StopThread(rdram, ctx);
        goto after_1;
    // 0x800C0FD4: nop

    after_1:
    // 0x800C0FD8: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x800C0FDC: jal         0x800C0B70
    // 0x800C0FE0: nop

    Thread_DestroyThread(rdram, ctx);
        goto after_2;
    // 0x800C0FE0: nop

    after_2:
    // 0x800C0FE4: b           L_800C0FEC
    // 0x800C0FE8: nop

        goto L_800C0FEC;
    // 0x800C0FE8: nop

L_800C0FEC:
    // 0x800C0FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0FF4: jr          $ra
    // 0x800C0FF8: nop

    return;
    // 0x800C0FF8: nop

;}
RECOMP_FUNC void func_8007796C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007796C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077970: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077974: nop

    // 0x80077978: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x8007797C: nop

    // 0x80077980: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077984: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077988: jr          $ra
    // 0x8007798C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007798C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077990: jr          $ra
    // 0x80077994: nop

    return;
    // 0x80077994: nop

    // 0x80077998: jr          $ra
    // 0x8007799C: nop

    return;
    // 0x8007799C: nop

;}
RECOMP_FUNC void func_800728D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800728D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800728D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800728D8: nop

    // 0x800728DC: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800728E0: nop

    // 0x800728E4: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x800728E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800728EC: jr          $ra
    // 0x800728F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800728F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800728F4: jr          $ra
    // 0x800728F8: nop

    return;
    // 0x800728F8: nop

    // 0x800728FC: jr          $ra
    // 0x80072900: nop

    return;
    // 0x80072900: nop

;}
RECOMP_FUNC void func_8006BCA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BCA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BCA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BCA8: jal         0x8005F064
    // 0x8006BCAC: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BCAC: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_0:
    // 0x8006BCB0: b           L_8006BCC0
    // 0x8006BCB4: nop

        goto L_8006BCC0;
    // 0x8006BCB4: nop

    // 0x8006BCB8: b           L_8006BCC0
    // 0x8006BCBC: nop

        goto L_8006BCC0;
    // 0x8006BCBC: nop

L_8006BCC0:
    // 0x8006BCC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BCC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BCC8: jr          $ra
    // 0x8006BCCC: nop

    return;
    // 0x8006BCCC: nop

;}
RECOMP_FUNC void func_8007B3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B3DC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8007B3E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B3E4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007B3E8: bne         $a1, $zero, L_8007B3F8
    if (ctx->r5 != 0) {
        // 0x8007B3EC: nop
    
            goto L_8007B3F8;
    }
    // 0x8007B3EC: nop

    // 0x8007B3F0: b           L_8007B708
    // 0x8007B3F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007B708;
    // 0x8007B3F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B3F8:
    // 0x8007B3F8: blez        $a1, L_8007B574
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007B3FC: nop
    
            goto L_8007B574;
    }
    // 0x8007B3FC: nop

    // 0x8007B400: sh          $a0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r4;
    // 0x8007B404: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8007B408: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8007B40C: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8007B410: nop

    // 0x8007B414: bltz        $t7, L_8007B56C
    if (SIGNED(ctx->r15) < 0) {
        // 0x8007B418: nop
    
            goto L_8007B56C;
    }
    // 0x8007B418: nop

L_8007B41C:
    // 0x8007B41C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007B420: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8007B424: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8007B428: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B42C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8007B430: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8007B434: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8007B438: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x8007B43C: lw          $t1, 0x144($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X144);
    // 0x8007B440: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8007B444: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8007B448: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x8007B44C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8007B450: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8007B454: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8007B458: nop

    // 0x8007B45C: bne         $t6, $at, L_8007B484
    if (ctx->r14 != ctx->r1) {
        // 0x8007B460: nop
    
            goto L_8007B484;
    }
    // 0x8007B460: nop

    // 0x8007B464: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x8007B468: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8007B46C: bne         $t7, $at, L_8007B484
    if (ctx->r15 != ctx->r1) {
        // 0x8007B470: nop
    
            goto L_8007B484;
    }
    // 0x8007B470: nop

    // 0x8007B474: lh          $a0, 0x6($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6);
    // 0x8007B478: nop

    // 0x8007B47C: b           L_8007B56C
    // 0x8007B480: nop

        goto L_8007B56C;
    // 0x8007B480: nop

L_8007B484:
    // 0x8007B484: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8007B488: addiu       $at, $zero, 0x6319
    ctx->r1 = ADD32(0, 0X6319);
    // 0x8007B48C: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x8007B490: nop

    // 0x8007B494: bne         $t9, $at, L_8007B4B4
    if (ctx->r25 != ctx->r1) {
        // 0x8007B498: nop
    
            goto L_8007B4B4;
    }
    // 0x8007B498: nop

    // 0x8007B49C: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x8007B4A0: nop

    // 0x8007B4A4: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8007B4A8: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x8007B4AC: b           L_8007B558
    // 0x8007B4B0: nop

        goto L_8007B558;
    // 0x8007B4B0: nop

L_8007B4B4:
    // 0x8007B4B4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007B4B8: lw          $t1, 0x7100($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7100);
    // 0x8007B4BC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007B4C0: bne         $t1, $at, L_8007B500
    if (ctx->r9 != ctx->r1) {
        // 0x8007B4C4: nop
    
            goto L_8007B500;
    }
    // 0x8007B4C4: nop

    // 0x8007B4C8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007B4CC: lw          $t3, 0x7104($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7104);
    // 0x8007B4D0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007B4D4: bne         $t3, $at, L_8007B500
    if (ctx->r11 != ctx->r1) {
        // 0x8007B4D8: nop
    
            goto L_8007B500;
    }
    // 0x8007B4D8: nop

    // 0x8007B4DC: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x8007B4E0: bne         $at, $zero, L_8007B500
    if (ctx->r1 != 0) {
        // 0x8007B4E4: nop
    
            goto L_8007B500;
    }
    // 0x8007B4E4: nop

    // 0x8007B4E8: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x8007B4EC: beq         $at, $zero, L_8007B500
    if (ctx->r1 == 0) {
        // 0x8007B4F0: nop
    
            goto L_8007B500;
    }
    // 0x8007B4F0: nop

    // 0x8007B4F4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007B4F8: b           L_8007B56C
    // 0x8007B4FC: nop

        goto L_8007B56C;
    // 0x8007B4FC: nop

L_8007B500:
    // 0x8007B500: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B504: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007B508: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007B50C: bne         $t4, $at, L_8007B558
    if (ctx->r12 != ctx->r1) {
        // 0x8007B510: nop
    
            goto L_8007B558;
    }
    // 0x8007B510: nop

    // 0x8007B514: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B518: lw          $t6, 0x7104($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7104);
    // 0x8007B51C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007B520: bne         $t6, $at, L_8007B558
    if (ctx->r14 != ctx->r1) {
        // 0x8007B524: nop
    
            goto L_8007B558;
    }
    // 0x8007B524: nop

    // 0x8007B528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B52C: bne         $a0, $at, L_8007B558
    if (ctx->r4 != ctx->r1) {
        // 0x8007B530: nop
    
            goto L_8007B558;
    }
    // 0x8007B530: nop

    // 0x8007B534: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007B538: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x8007B53C: nop

    // 0x8007B540: andi        $t7, $t5, 0x100
    ctx->r15 = ctx->r13 & 0X100;
    // 0x8007B544: beq         $t7, $zero, L_8007B558
    if (ctx->r15 == 0) {
        // 0x8007B548: nop
    
            goto L_8007B558;
    }
    // 0x8007B548: nop

    // 0x8007B54C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8007B550: b           L_8007B56C
    // 0x8007B554: nop

        goto L_8007B56C;
    // 0x8007B554: nop

L_8007B558:
    // 0x8007B558: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8007B55C: nop

    // 0x8007B560: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007B564: bgez        $t9, L_8007B41C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007B568: sw          $t9, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r25;
            goto L_8007B41C;
    }
    // 0x8007B568: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
L_8007B56C:
    // 0x8007B56C: b           L_8007B708
    // 0x8007B570: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007B708;
    // 0x8007B570: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B574:
    // 0x8007B574: sh          $a0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r4;
    // 0x8007B578: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8007B57C: subu        $t2, $t0, $a1
    ctx->r10 = SUB32(ctx->r8, ctx->r5);
    // 0x8007B580: bltz        $t2, L_8007B6F8
    if (SIGNED(ctx->r10) < 0) {
        // 0x8007B584: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_8007B6F8;
    }
    // 0x8007B584: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_8007B588:
    // 0x8007B588: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8007B58C: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x8007B590: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8007B594: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B598: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8007B59C: bgez        $a0, L_8007B5B4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8007B5A0: nop
    
            goto L_8007B5B4;
    }
    // 0x8007B5A0: nop

    // 0x8007B5A4: lh          $a0, 0x6($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X6);
    // 0x8007B5A8: nop

    // 0x8007B5AC: b           L_8007B6F8
    // 0x8007B5B0: nop

        goto L_8007B6F8;
    // 0x8007B5B0: nop

L_8007B5B4:
    // 0x8007B5B4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B5B8: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007B5BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007B5C0: bne         $t4, $at, L_8007B5F4
    if (ctx->r12 != ctx->r1) {
        // 0x8007B5C4: nop
    
            goto L_8007B5F4;
    }
    // 0x8007B5C4: nop

    // 0x8007B5C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B5CC: lw          $t6, 0x7104($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7104);
    // 0x8007B5D0: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x8007B5D4: bne         $t6, $at, L_8007B5F4
    if (ctx->r14 != ctx->r1) {
        // 0x8007B5D8: nop
    
            goto L_8007B5F4;
    }
    // 0x8007B5D8: nop

    // 0x8007B5DC: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8007B5E0: beq         $at, $zero, L_8007B5F4
    if (ctx->r1 == 0) {
        // 0x8007B5E4: nop
    
            goto L_8007B5F4;
    }
    // 0x8007B5E4: nop

    // 0x8007B5E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8007B5EC: b           L_8007B6F8
    // 0x8007B5F0: nop

        goto L_8007B6F8;
    // 0x8007B5F0: nop

L_8007B5F4:
    // 0x8007B5F4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8007B5F8: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8007B5FC: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8007B600: lw          $t7, 0x144($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X144);
    // 0x8007B604: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8007B608: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007B60C: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x8007B610: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8007B614: addiu       $at, $zero, 0x6319
    ctx->r1 = ADD32(0, 0X6319);
    // 0x8007B618: lhu         $t1, 0xA($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0XA);
    // 0x8007B61C: nop

    // 0x8007B620: bne         $t1, $at, L_8007B640
    if (ctx->r9 != ctx->r1) {
        // 0x8007B624: nop
    
            goto L_8007B640;
    }
    // 0x8007B624: nop

    // 0x8007B628: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x8007B62C: nop

    // 0x8007B630: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007B634: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
    // 0x8007B638: b           L_8007B6E4
    // 0x8007B63C: nop

        goto L_8007B6E4;
    // 0x8007B63C: nop

L_8007B640:
    // 0x8007B640: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007B644: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x8007B648: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007B64C: bne         $t6, $at, L_8007B68C
    if (ctx->r14 != ctx->r1) {
        // 0x8007B650: nop
    
            goto L_8007B68C;
    }
    // 0x8007B650: nop

    // 0x8007B654: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007B658: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007B65C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007B660: bne         $t5, $at, L_8007B68C
    if (ctx->r13 != ctx->r1) {
        // 0x8007B664: nop
    
            goto L_8007B68C;
    }
    // 0x8007B664: nop

    // 0x8007B668: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x8007B66C: bne         $at, $zero, L_8007B68C
    if (ctx->r1 != 0) {
        // 0x8007B670: nop
    
            goto L_8007B68C;
    }
    // 0x8007B670: nop

    // 0x8007B674: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x8007B678: beq         $at, $zero, L_8007B68C
    if (ctx->r1 == 0) {
        // 0x8007B67C: nop
    
            goto L_8007B68C;
    }
    // 0x8007B67C: nop

    // 0x8007B680: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8007B684: b           L_8007B6F8
    // 0x8007B688: nop

        goto L_8007B6F8;
    // 0x8007B688: nop

L_8007B68C:
    // 0x8007B68C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007B690: lw          $t8, 0x7100($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7100);
    // 0x8007B694: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007B698: bne         $t8, $at, L_8007B6E4
    if (ctx->r24 != ctx->r1) {
        // 0x8007B69C: nop
    
            goto L_8007B6E4;
    }
    // 0x8007B69C: nop

    // 0x8007B6A0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007B6A4: lw          $t7, 0x7104($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7104);
    // 0x8007B6A8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007B6AC: bne         $t7, $at, L_8007B6E4
    if (ctx->r15 != ctx->r1) {
        // 0x8007B6B0: nop
    
            goto L_8007B6E4;
    }
    // 0x8007B6B0: nop

    // 0x8007B6B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B6B8: bne         $a0, $at, L_8007B6E4
    if (ctx->r4 != ctx->r1) {
        // 0x8007B6BC: nop
    
            goto L_8007B6E4;
    }
    // 0x8007B6BC: nop

    // 0x8007B6C0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007B6C4: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007B6C8: nop

    // 0x8007B6CC: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x8007B6D0: beq         $t0, $zero, L_8007B6E4
    if (ctx->r8 == 0) {
        // 0x8007B6D4: nop
    
            goto L_8007B6E4;
    }
    // 0x8007B6D4: nop

    // 0x8007B6D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007B6DC: b           L_8007B6F8
    // 0x8007B6E0: nop

        goto L_8007B6F8;
    // 0x8007B6E0: nop

L_8007B6E4:
    // 0x8007B6E4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8007B6E8: nop

    // 0x8007B6EC: addiu       $t1, $t2, -0x1
    ctx->r9 = ADD32(ctx->r10, -0X1);
    // 0x8007B6F0: bgez        $t1, L_8007B588
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8007B6F4: sw          $t1, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r9;
            goto L_8007B588;
    }
    // 0x8007B6F4: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
L_8007B6F8:
    // 0x8007B6F8: b           L_8007B708
    // 0x8007B6FC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007B708;
    // 0x8007B6FC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007B700: b           L_8007B708
    // 0x8007B704: nop

        goto L_8007B708;
    // 0x8007B704: nop

L_8007B708:
    // 0x8007B708: jr          $ra
    // 0x8007B70C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007B70C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
