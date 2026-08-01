#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80063150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063158: jal         0x80061488
    // 0x8006315C: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006315C: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_0:
    // 0x80063160: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063164: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063168: b           L_80063178
    // 0x8006316C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063178;
    // 0x8006316C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063170: b           L_80063178
    // 0x80063174: nop

        goto L_80063178;
    // 0x80063174: nop

L_80063178:
    // 0x80063178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006317C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063180: jr          $ra
    // 0x80063184: nop

    return;
    // 0x80063184: nop

;}
RECOMP_FUNC void func_800B7788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7788: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B778C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800B7790:
    // 0x800B7790: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800B7794: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800B7798: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B779C: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x800B77A0: sh          $t6, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r14;
    // 0x800B77A4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B77A8: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800B77AC: nop

    // 0x800B77B0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B77B4: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x800B77B8: bne         $at, $zero, L_800B7790
    if (ctx->r1 != 0) {
        // 0x800B77BC: sw          $t1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r9;
            goto L_800B7790;
    }
    // 0x800B77BC: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800B77C0: b           L_800B77D0
    // 0x800B77C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800B77D0;
    // 0x800B77C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800B77C8: b           L_800B77D0
    // 0x800B77CC: nop

        goto L_800B77D0;
    // 0x800B77CC: nop

L_800B77D0:
    // 0x800B77D0: jr          $ra
    // 0x800B77D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B77D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006EEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EEB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EEBC: jal         0x80061348
    // 0x8006EEC0: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EEC0: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    after_0:
    // 0x8006EEC4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EEC8: b           L_8006EED8
    // 0x8006EECC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EED8;
    // 0x8006EECC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EED0: b           L_8006EED8
    // 0x8006EED4: nop

        goto L_8006EED8;
    // 0x8006EED4: nop

L_8006EED8:
    // 0x8006EED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EEDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EEE0: jr          $ra
    // 0x8006EEE4: nop

    return;
    // 0x8006EEE4: nop

;}
RECOMP_FUNC void func_8006C7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C7F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C7F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C7F8: jal         0x8005F064
    // 0x8006C7FC: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C7FC: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    after_0:
    // 0x8006C800: b           L_8006C810
    // 0x8006C804: nop

        goto L_8006C810;
    // 0x8006C804: nop

    // 0x8006C808: b           L_8006C810
    // 0x8006C80C: nop

        goto L_8006C810;
    // 0x8006C80C: nop

L_8006C810:
    // 0x8006C810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C818: jr          $ra
    // 0x8006C81C: nop

    return;
    // 0x8006C81C: nop

;}
RECOMP_FUNC void func_80063B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063B54: jal         0x8005F064
    // 0x80063B58: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063B58: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063B5C: b           L_80063B6C
    // 0x80063B60: nop

        goto L_80063B6C;
    // 0x80063B60: nop

    // 0x80063B64: b           L_80063B6C
    // 0x80063B68: nop

        goto L_80063B6C;
    // 0x80063B68: nop

L_80063B6C:
    // 0x80063B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063B74: jr          $ra
    // 0x80063B78: nop

    return;
    // 0x80063B78: nop

;}
RECOMP_FUNC void ContPak_FindPfsSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADED0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ADED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ADED8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800ADEDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800ADEE0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800ADEE4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800ADEE8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800ADEEC:
    // 0x800ADEEC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADEF0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800ADEF4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800ADEF8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800ADEFC: lw          $t8, 0x15D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X15D8);
    // 0x800ADF00: nop

    // 0x800ADF04: bne         $t8, $zero, L_800ADFE4
    if (ctx->r24 != 0) {
        // 0x800ADF08: nop
    
            goto L_800ADFE4;
    }
    // 0x800ADF08: nop

    // 0x800ADF0C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADF10: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800ADF14: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x800ADF18: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800ADF1C: lhu         $t1, 0x13D8($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X13D8);
    // 0x800ADF20: lhu         $t2, 0x26($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X26);
    // 0x800ADF24: nop

    // 0x800ADF28: beq         $t1, $t2, L_800ADF38
    if (ctx->r9 == ctx->r10) {
        // 0x800ADF2C: nop
    
            goto L_800ADF38;
    }
    // 0x800ADF2C: nop

    // 0x800ADF30: b           L_800ADFE4
    // 0x800ADF34: nop

        goto L_800ADFE4;
    // 0x800ADF34: nop

L_800ADF38:
    // 0x800ADF38: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADF3C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800ADF40: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800ADF44: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800ADF48: lw          $t5, 0x13D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X13D4);
    // 0x800ADF4C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800ADF50: nop

    // 0x800ADF54: beq         $t5, $t6, L_800ADF64
    if (ctx->r13 == ctx->r14) {
        // 0x800ADF58: nop
    
            goto L_800ADF64;
    }
    // 0x800ADF58: nop

    // 0x800ADF5C: b           L_800ADFE4
    // 0x800ADF60: nop

        goto L_800ADFE4;
    // 0x800ADF60: nop

L_800ADF64:
    // 0x800ADF64: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADF68: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800ADF6C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800ADF70: addiu       $t9, $t8, 0xE
    ctx->r25 = ADD32(ctx->r24, 0XE);
    // 0x800ADF74: addiu       $t0, $t0, 0x13D0
    ctx->r8 = ADD32(ctx->r8, 0X13D0);
    // 0x800ADF78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800ADF7C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800ADF80: jal         0x800BD180
    // 0x800ADF84: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_Bcmp(rdram, ctx);
        goto after_0;
    // 0x800ADF84: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x800ADF88: beq         $v0, $zero, L_800ADF98
    if (ctx->r2 == 0) {
        // 0x800ADF8C: nop
    
            goto L_800ADF98;
    }
    // 0x800ADF8C: nop

    // 0x800ADF90: b           L_800ADFE4
    // 0x800ADF94: nop

        goto L_800ADFE4;
    // 0x800ADF94: nop

L_800ADF98:
    // 0x800ADF98: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADF9C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800ADFA0: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800ADFA4: addiu       $t3, $t2, 0xA
    ctx->r11 = ADD32(ctx->r10, 0XA);
    // 0x800ADFA8: addiu       $t4, $t4, 0x13D0
    ctx->r12 = ADD32(ctx->r12, 0X13D0);
    // 0x800ADFAC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800ADFB0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x800ADFB4: jal         0x800BD180
    // 0x800ADFB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Bcmp(rdram, ctx);
        goto after_1;
    // 0x800ADFB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800ADFBC: beq         $v0, $zero, L_800ADFCC
    if (ctx->r2 == 0) {
        // 0x800ADFC0: nop
    
            goto L_800ADFCC;
    }
    // 0x800ADFC0: nop

    // 0x800ADFC4: b           L_800ADFE4
    // 0x800ADFC8: nop

        goto L_800ADFE4;
    // 0x800ADFC8: nop

L_800ADFCC:
    // 0x800ADFCC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADFD0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800ADFD4: nop

    // 0x800ADFD8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800ADFDC: b           L_800AE00C
    // 0x800ADFE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE00C;
    // 0x800ADFE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADFE4:
    // 0x800ADFE4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADFE8: nop

    // 0x800ADFEC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800ADFF0: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x800ADFF4: bne         $at, $zero, L_800ADEEC
    if (ctx->r1 != 0) {
        // 0x800ADFF8: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800ADEEC;
    }
    // 0x800ADFF8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800ADFFC: b           L_800AE00C
    // 0x800AE000: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800AE00C;
    // 0x800AE000: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800AE004: b           L_800AE00C
    // 0x800AE008: nop

        goto L_800AE00C;
    // 0x800AE008: nop

L_800AE00C:
    // 0x800AE00C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE010: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE014: jr          $ra
    // 0x800AE018: nop

    return;
    // 0x800AE018: nop

;}
RECOMP_FUNC void func_80054198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054198: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005419C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800541A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800541A4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800541A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800541AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800541B0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800541B4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800541B8: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800541BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800541C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800541C4: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x800541C8: nop

    // 0x800541CC: bc1f        L_800541DC
    if (!c1cs) {
        // 0x800541D0: nop
    
            goto L_800541DC;
    }
    // 0x800541D0: nop

    // 0x800541D4: b           L_800541E4
    // 0x800541D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
        goto L_800541E4;
    // 0x800541D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800541DC:
    // 0x800541DC: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800541E0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_800541E4:
    // 0x800541E4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800541E8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800541EC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800541F0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800541F4: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800541F8: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800541FC: xor         $t5, $t1, $t3
    ctx->r13 = ctx->r9 ^ ctx->r11;
    // 0x80054200: andi        $t7, $t5, 0x8
    ctx->r15 = ctx->r13 & 0X8;
    // 0x80054204: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x80054208: sra         $t2, $t9, 31
    ctx->r10 = S32(SIGNED(ctx->r25) >> 31);
    // 0x8005420C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80054210: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80054214: beq         $t8, $zero, L_80054240
    if (ctx->r24 == 0) {
        // 0x80054218: xor         $t4, $t0, $t2
        ctx->r12 = ctx->r8 ^ ctx->r10;
            goto L_80054240;
    }
    // 0x80054218: xor         $t4, $t0, $t2
    ctx->r12 = ctx->r8 ^ ctx->r10;
    // 0x8005421C: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x80054220: jal         0x80056E88
    // 0x80054224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80056E88(rdram, ctx);
        goto after_0;
    // 0x80054224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80054228: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8005422C: sra         $t9, $s0, 16
    ctx->r25 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80054230: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80054234: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80054238: jal         0x800507AC
    // 0x8005423C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800507AC(rdram, ctx);
        goto after_1;
    // 0x8005423C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
L_80054240:
    // 0x80054240: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80054244: b           L_80054254
    // 0x80054248: nop

        goto L_80054254;
    // 0x80054248: nop

    // 0x8005424C: b           L_80054254
    // 0x80054250: nop

        goto L_80054254;
    // 0x80054250: nop

L_80054254:
    // 0x80054254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80054258: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005425C: jr          $ra
    // 0x80054260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80054260: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800854B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800854B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800854BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800854C0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800854C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800854C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800854CC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800854D0: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x800854D4: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x800854D8: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x800854DC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800854E0: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x800854E4: beq         $t0, $zero, L_80085688
    if (ctx->r8 == 0) {
        // 0x800854E8: nop
    
            goto L_80085688;
    }
    // 0x800854E8: nop

    // 0x800854EC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800854F0: jal         0x8008A518
    // 0x800854F4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800854F4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800854F8: beq         $v0, $zero, L_80085688
    if (ctx->r2 == 0) {
        // 0x800854FC: nop
    
            goto L_80085688;
    }
    // 0x800854FC: nop

    // 0x80085500: lhu         $s0, 0x2C($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X2C);
    // 0x80085504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085508: beq         $s0, $at, L_8008553C
    if (ctx->r16 == ctx->r1) {
        // 0x8008550C: nop
    
            goto L_8008553C;
    }
    // 0x8008550C: nop

    // 0x80085510: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80085514: beq         $s0, $at, L_8008557C
    if (ctx->r16 == ctx->r1) {
        // 0x80085518: nop
    
            goto L_8008557C;
    }
    // 0x80085518: nop

    // 0x8008551C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085520: beq         $s0, $at, L_800855B8
    if (ctx->r16 == ctx->r1) {
        // 0x80085524: nop
    
            goto L_800855B8;
    }
    // 0x80085524: nop

    // 0x80085528: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008552C: beq         $s0, $at, L_8008563C
    if (ctx->r16 == ctx->r1) {
        // 0x80085530: nop
    
            goto L_8008563C;
    }
    // 0x80085530: nop

    // 0x80085534: b           L_80085688
    // 0x80085538: nop

        goto L_80085688;
    // 0x80085538: nop

L_8008553C:
    // 0x8008553C: jal         0x8008CE48
    // 0x80085540: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80085540: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80085544: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80085548: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8008554C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80085550: nop

    // 0x80085554: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80085558: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x8008555C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80085560: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80085564: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x80085568: nop

    // 0x8008556C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80085570: sh          $t6, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r14;
    // 0x80085574: b           L_800856A4
    // 0x80085578: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_800856A4;
    // 0x80085578: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8008557C:
    // 0x8008557C: jal         0x8008C160
    // 0x80085580: nop

    func_8008C160(rdram, ctx);
        goto after_2;
    // 0x80085580: nop

    after_2:
    // 0x80085584: beq         $v0, $zero, L_8008559C
    if (ctx->r2 == 0) {
        // 0x80085588: nop
    
            goto L_8008559C;
    }
    // 0x80085588: nop

    // 0x8008558C: jal         0x8008CE48
    // 0x80085590: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_3;
    // 0x80085590: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_3:
    // 0x80085594: b           L_800856A4
    // 0x80085598: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_800856A4;
    // 0x80085598: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8008559C:
    // 0x8008559C: jal         0x8008CE48
    // 0x800855A0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_4;
    // 0x800855A0: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_4:
    // 0x800855A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800855A8: jal         0x8008A730
    // 0x800855AC: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    func_8008A730(rdram, ctx);
        goto after_5;
    // 0x800855AC: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_5:
    // 0x800855B0: b           L_80085688
    // 0x800855B4: nop

        goto L_80085688;
    // 0x800855B4: nop

L_800855B8:
    // 0x800855B8: jal         0x8008C160
    // 0x800855BC: nop

    func_8008C160(rdram, ctx);
        goto after_6;
    // 0x800855BC: nop

    after_6:
    // 0x800855C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800855C4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800855C8: nop

    // 0x800855CC: bne         $t7, $zero, L_800855F0
    if (ctx->r15 != 0) {
        // 0x800855D0: nop
    
            goto L_800855F0;
    }
    // 0x800855D0: nop

    // 0x800855D4: jal         0x8008CE48
    // 0x800855D8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_7;
    // 0x800855D8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_7:
    // 0x800855DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800855E0: jal         0x8008A730
    // 0x800855E4: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    func_8008A730(rdram, ctx);
        goto after_8;
    // 0x800855E4: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_8:
    // 0x800855E8: b           L_80085688
    // 0x800855EC: nop

        goto L_80085688;
    // 0x800855EC: nop

L_800855F0:
    // 0x800855F0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800855F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800855F8: bne         $t9, $at, L_8008562C
    if (ctx->r25 != ctx->r1) {
        // 0x800855FC: nop
    
            goto L_8008562C;
    }
    // 0x800855FC: nop

    // 0x80085600: jal         0x8008C1F0
    // 0x80085604: nop

    func_8008C1F0(rdram, ctx);
        goto after_9;
    // 0x80085604: nop

    after_9:
    // 0x80085608: bne         $v0, $zero, L_8008562C
    if (ctx->r2 != 0) {
        // 0x8008560C: nop
    
            goto L_8008562C;
    }
    // 0x8008560C: nop

    // 0x80085610: jal         0x8008CE48
    // 0x80085614: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80085614: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_10:
    // 0x80085618: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008561C: jal         0x8008A730
    // 0x80085620: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    func_8008A730(rdram, ctx);
        goto after_11;
    // 0x80085620: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_11:
    // 0x80085624: b           L_80085688
    // 0x80085628: nop

        goto L_80085688;
    // 0x80085628: nop

L_8008562C:
    // 0x8008562C: jal         0x8008CE48
    // 0x80085630: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_12;
    // 0x80085630: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_12:
    // 0x80085634: b           L_800856A4
    // 0x80085638: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_800856A4;
    // 0x80085638: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_8008563C:
    // 0x8008563C: jal         0x8008CE48
    // 0x80085640: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_13;
    // 0x80085640: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_13:
    // 0x80085644: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80085648: jal         0x8008C0D8
    // 0x8008564C: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    func_8008C0D8(rdram, ctx);
        goto after_14;
    // 0x8008564C: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    after_14:
    // 0x80085650: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80085654: nop

    // 0x80085658: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x8008565C: nop

    // 0x80085660: ori         $t2, $t0, 0x800
    ctx->r10 = ctx->r8 | 0X800;
    // 0x80085664: sh          $t2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r10;
    // 0x80085668: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008566C: nop

    // 0x80085670: lhu         $t1, 0x2($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X2);
    // 0x80085674: nop

    // 0x80085678: ori         $t5, $t1, 0x8
    ctx->r13 = ctx->r9 | 0X8;
    // 0x8008567C: sh          $t5, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r13;
    // 0x80085680: b           L_800856A4
    // 0x80085684: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_800856A4;
    // 0x80085684: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80085688:
    // 0x80085688: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8008568C: nop

    // 0x80085690: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80085694: b           L_800856A4
    // 0x80085698: nop

        goto L_800856A4;
    // 0x80085698: nop

    // 0x8008569C: b           L_800856A4
    // 0x800856A0: nop

        goto L_800856A4;
    // 0x800856A0: nop

L_800856A4:
    // 0x800856A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800856A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800856AC: jr          $ra
    // 0x800856B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800856B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006F6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F6C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F6CC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F6D0: nop

    // 0x8006F6D4: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x8006F6D8: nop

    // 0x8006F6DC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F6E0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F6E4: jr          $ra
    // 0x8006F6E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F6E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F6EC: jr          $ra
    // 0x8006F6F0: nop

    return;
    // 0x8006F6F0: nop

    // 0x8006F6F4: jr          $ra
    // 0x8006F6F8: nop

    return;
    // 0x8006F6F8: nop

;}
RECOMP_FUNC void func_80077798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077798: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007779C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800777A0: nop

    // 0x800777A4: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x800777A8: nop

    // 0x800777AC: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800777B0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800777B4: jr          $ra
    // 0x800777B8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800777B8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800777BC: jr          $ra
    // 0x800777C0: nop

    return;
    // 0x800777C0: nop

    // 0x800777C4: jr          $ra
    // 0x800777C8: nop

    return;
    // 0x800777C8: nop

;}
RECOMP_FUNC void func_8006F288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F288: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F28C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F290: nop

    // 0x8006F294: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F298: nop

    // 0x8006F29C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F2A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F2A4: jr          $ra
    // 0x8006F2A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F2A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F2AC: jr          $ra
    // 0x8006F2B0: nop

    return;
    // 0x8006F2B0: nop

    // 0x8006F2B4: jr          $ra
    // 0x8006F2B8: nop

    return;
    // 0x8006F2B8: nop

;}
RECOMP_FUNC void func_80070270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070278: jal         0x80061488
    // 0x8007027C: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007027C: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    after_0:
    // 0x80070280: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80070284: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80070288: b           L_80070298
    // 0x8007028C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80070298;
    // 0x8007028C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070290: b           L_80070298
    // 0x80070294: nop

        goto L_80070298;
    // 0x80070294: nop

L_80070298:
    // 0x80070298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007029C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800702A0: jr          $ra
    // 0x800702A4: nop

    return;
    // 0x800702A4: nop

;}
RECOMP_FUNC void func_8000C778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C778: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000C77C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C780: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8000C784: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C788: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8000C78C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000C790: lh          $t6, -0x7290($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7290);
    // 0x8000C794: nop

    // 0x8000C798: slti        $at, $t6, 0x1F4
    ctx->r1 = SIGNED(ctx->r14) < 0X1F4 ? 1 : 0;
    // 0x8000C79C: beq         $at, $zero, L_8000C7C0
    if (ctx->r1 == 0) {
        // 0x8000C7A0: nop
    
            goto L_8000C7C0;
    }
    // 0x8000C7A0: nop

    // 0x8000C7A4: lui         $t7, 0x8094
    ctx->r15 = S32(0X8094 << 16);
    // 0x8000C7A8: addiu       $t7, $t7, 0x7340
    ctx->r15 = ADD32(ctx->r15, 0X7340);
    // 0x8000C7AC: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8000C7B0: lui         $t8, 0x8095
    ctx->r24 = S32(0X8095 << 16);
    // 0x8000C7B4: addiu       $t8, $t8, -0x6EB0
    ctx->r24 = ADD32(ctx->r24, -0X6EB0);
    // 0x8000C7B8: b           L_8000C7D8
    // 0x8000C7BC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
        goto L_8000C7D8;
    // 0x8000C7BC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_8000C7C0:
    // 0x8000C7C0: lui         $t9, 0x8099
    ctx->r25 = S32(0X8099 << 16);
    // 0x8000C7C4: addiu       $t9, $t9, 0x3AE0
    ctx->r25 = ADD32(ctx->r25, 0X3AE0);
    // 0x8000C7C8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8000C7CC: lui         $t0, 0x8099
    ctx->r8 = S32(0X8099 << 16);
    // 0x8000C7D0: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8000C7D4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_8000C7D8:
    // 0x8000C7D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000C7DC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000C7E0: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000C7E4: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000C7E8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8000C7EC: jal         0x800BD1FC
    // 0x8000C7F0: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8000C7F0: nop

    after_0:
    // 0x8000C7F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C7F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000C7FC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8000C800: jal         0x800BD218
    // 0x8000C804: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8000C804: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_1:
    // 0x8000C808: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8000C80C: lh          $t2, -0x7290($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X7290);
    // 0x8000C810: lh          $t1, 0x44($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X44);
    // 0x8000C814: nop

    // 0x8000C818: bne         $t1, $t2, L_8000C860
    if (ctx->r9 != ctx->r10) {
        // 0x8000C81C: nop
    
            goto L_8000C860;
    }
    // 0x8000C81C: nop

    // 0x8000C820: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000C824: lh          $t4, -0x7288($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X7288);
    // 0x8000C828: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x8000C82C: nop

    // 0x8000C830: bne         $t3, $t4, L_8000C860
    if (ctx->r11 != ctx->r12) {
        // 0x8000C834: nop
    
            goto L_8000C860;
    }
    // 0x8000C834: nop

    // 0x8000C838: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000C83C: lh          $t6, -0x7280($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7280);
    // 0x8000C840: lh          $t5, 0x48($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X48);
    // 0x8000C844: nop

    // 0x8000C848: bne         $t5, $t6, L_8000C860
    if (ctx->r13 != ctx->r14) {
        // 0x8000C84C: nop
    
            goto L_8000C860;
    }
    // 0x8000C84C: nop

    // 0x8000C850: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000C854: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8000C858: b           L_8000C880
    // 0x8000C85C: nop

        goto L_8000C880;
    // 0x8000C85C: nop

L_8000C860:
    // 0x8000C860: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8000C864: nop

    // 0x8000C868: addiu       $t9, $t8, 0xC
    ctx->r25 = ADD32(ctx->r24, 0XC);
    // 0x8000C86C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8000C870: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x8000C874: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C878: bne         $t0, $at, L_8000C7D8
    if (ctx->r8 != ctx->r1) {
        // 0x8000C87C: nop
    
            goto L_8000C7D8;
    }
    // 0x8000C87C: nop

L_8000C880:
    // 0x8000C880: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8000C884: nop

    // 0x8000C888: bne         $t1, $zero, L_8000C898
    if (ctx->r9 != 0) {
        // 0x8000C88C: nop
    
            goto L_8000C898;
    }
    // 0x8000C88C: nop

    // 0x8000C890: b           L_8000CC34
    // 0x8000C894: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000CC34;
    // 0x8000C894: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000C898:
    // 0x8000C898: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8000C89C: nop

    // 0x8000C8A0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8000C8A4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8000C8A8: nop

    // 0x8000C8AC: addiu       $t4, $t3, 0xC
    ctx->r12 = ADD32(ctx->r11, 0XC);
    // 0x8000C8B0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8000C8B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000C8B8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000C8BC: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000C8C0: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000C8C4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8000C8C8: jal         0x800BD1FC
    // 0x8000C8CC: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8000C8CC: nop

    after_2:
    // 0x8000C8D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C8D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000C8D8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8000C8DC: jal         0x800BD218
    // 0x8000C8E0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x8000C8E0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_3:
    // 0x8000C8E4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8000C8E8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000C8EC: nop

    // 0x8000C8F0: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8000C8F4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8000C8F8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8000C8FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C900: jal         0x8000D164
    // 0x8000C904: nop

    TempHeap_Alloc(rdram, ctx);
        goto after_4;
    // 0x8000C904: nop

    after_4:
    // 0x8000C908: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8000C90C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8000C910: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8000C914: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000C918: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000C91C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000C920: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000C924: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8000C928: jal         0x800BD1FC
    // 0x8000C92C: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8000C92C: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    after_5:
    // 0x8000C930: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C934: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C938: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C93C: jal         0x800BD218
    // 0x8000C940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_6;
    // 0x8000C940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8000C944: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C948: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8000C94C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8000C950: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000C954: nop

    // 0x8000C958: beq         $t3, $at, L_8000C998
    if (ctx->r11 == ctx->r1) {
        // 0x8000C95C: nop
    
            goto L_8000C998;
    }
    // 0x8000C95C: nop

    // 0x8000C960: ori         $at, $zero, 0xC001
    ctx->r1 = 0 | 0XC001;
    // 0x8000C964: beq         $t3, $at, L_8000C998
    if (ctx->r11 == ctx->r1) {
        // 0x8000C968: nop
    
            goto L_8000C998;
    }
    // 0x8000C968: nop

L_8000C96C:
    // 0x8000C96C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8000C970: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8000C974: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x8000C978: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8000C97C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8000C980: nop

    // 0x8000C984: beq         $t6, $at, L_8000C998
    if (ctx->r14 == ctx->r1) {
        // 0x8000C988: nop
    
            goto L_8000C998;
    }
    // 0x8000C988: nop

    // 0x8000C98C: ori         $at, $zero, 0xC001
    ctx->r1 = 0 | 0XC001;
    // 0x8000C990: bne         $t6, $at, L_8000C96C
    if (ctx->r14 != ctx->r1) {
        // 0x8000C994: nop
    
            goto L_8000C96C;
    }
    // 0x8000C994: nop

L_8000C998:
    // 0x8000C998: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000C99C: ori         $at, $zero, 0xC001
    ctx->r1 = 0 | 0XC001;
    // 0x8000C9A0: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000C9A4: nop

    // 0x8000C9A8: bne         $t8, $at, L_8000C9C4
    if (ctx->r24 != ctx->r1) {
        // 0x8000C9AC: nop
    
            goto L_8000C9C4;
    }
    // 0x8000C9AC: nop

    // 0x8000C9B0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C9B4: jal         0x8000D390
    // 0x8000C9B8: nop

    TempHeap_Free(rdram, ctx);
        goto after_7;
    // 0x8000C9B8: nop

    after_7:
    // 0x8000C9BC: b           L_8000CC34
    // 0x8000C9C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000CC34;
    // 0x8000C9C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000C9C4:
    // 0x8000C9C4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000C9C8: nop

    // 0x8000C9CC: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x8000C9D0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8000C9D4: jal         0x8000D164
    // 0x8000C9D8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    TempHeap_Alloc(rdram, ctx);
        goto after_8;
    // 0x8000C9D8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_8:
    // 0x8000C9DC: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8000C9E0: nop

    // 0x8000C9E4: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x8000C9E8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8000C9EC: nop

    // 0x8000C9F0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8000C9F4: nop

    // 0x8000C9F8: sw          $t3, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r11;
    // 0x8000C9FC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8000CA00: ori         $t4, $zero, 0xC000
    ctx->r12 = 0 | 0XC000;
    // 0x8000CA04: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8000CA08: nop

    // 0x8000CA0C: sh          $t4, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r12;
    // 0x8000CA10: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8000CA14: nop

    // 0x8000CA18: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000CA1C: nop

    // 0x8000CA20: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8000CA24: sw          $t9, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r25;
    // 0x8000CA28: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8000CA2C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000CA30: lh          $t0, -0x7290($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X7290);
    // 0x8000CA34: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x8000CA38: nop

    // 0x8000CA3C: sh          $t0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r8;
    // 0x8000CA40: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8000CA44: nop

    // 0x8000CA48: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x8000CA4C: nop

    // 0x8000CA50: addiu       $t4, $t5, 0x2
    ctx->r12 = ADD32(ctx->r13, 0X2);
    // 0x8000CA54: sw          $t4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r12;
    // 0x8000CA58: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8000CA5C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000CA60: lh          $t6, -0x7288($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7288);
    // 0x8000CA64: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000CA68: nop

    // 0x8000CA6C: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x8000CA70: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8000CA74: nop

    // 0x8000CA78: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x8000CA7C: nop

    // 0x8000CA80: addiu       $t0, $t1, 0x2
    ctx->r8 = ADD32(ctx->r9, 0X2);
    // 0x8000CA84: sw          $t0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r8;
    // 0x8000CA88: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8000CA8C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000CA90: lh          $t3, -0x7280($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X7280);
    // 0x8000CA94: lw          $t4, 0xC($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XC);
    // 0x8000CA98: nop

    // 0x8000CA9C: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8000CAA0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8000CAA4: nop

    // 0x8000CAA8: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x8000CAAC: nop

    // 0x8000CAB0: addiu       $t6, $t8, 0x2
    ctx->r14 = ADD32(ctx->r24, 0X2);
    // 0x8000CAB4: sw          $t6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r14;
    // 0x8000CAB8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8000CABC: ori         $t9, $zero, 0xC001
    ctx->r25 = 0 | 0XC001;
    // 0x8000CAC0: lw          $t0, 0xC($t1)
    ctx->r8 = MEM_W(ctx->r9, 0XC);
    // 0x8000CAC4: nop

    // 0x8000CAC8: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x8000CACC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8000CAD0: nop

    // 0x8000CAD4: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x8000CAD8: nop

    // 0x8000CADC: addiu       $t3, $t5, 0x2
    ctx->r11 = ADD32(ctx->r13, 0X2);
    // 0x8000CAE0: sw          $t3, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r11;
    // 0x8000CAE4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8000CAE8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8000CAEC: lhu         $t8, 0x0($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X0);
    // 0x8000CAF0: lw          $t2, 0xC($t6)
    ctx->r10 = MEM_W(ctx->r14, 0XC);
    // 0x8000CAF4: nop

    // 0x8000CAF8: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x8000CAFC: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8000CB00: nop

    // 0x8000CB04: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x8000CB08: nop

    // 0x8000CB0C: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x8000CB10: sw          $t0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r8;
    // 0x8000CB14: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8000CB18: nop

    // 0x8000CB1C: addiu       $t3, $t5, 0x2
    ctx->r11 = ADD32(ctx->r13, 0X2);
    // 0x8000CB20: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8000CB24: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000CB28: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8000CB2C: lhu         $t4, 0x0($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X0);
    // 0x8000CB30: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x8000CB34: nop

    // 0x8000CB38: sh          $t4, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r12;
    // 0x8000CB3C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8000CB40: nop

    // 0x8000CB44: lw          $t9, 0xC($t2)
    ctx->r25 = MEM_W(ctx->r10, 0XC);
    // 0x8000CB48: nop

    // 0x8000CB4C: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x8000CB50: sw          $t0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r8;
    // 0x8000CB54: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000CB58: nop

    // 0x8000CB5C: addiu       $t5, $t1, 0x2
    ctx->r13 = ADD32(ctx->r9, 0X2);
    // 0x8000CB60: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8000CB64: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8000CB68: ori         $t3, $zero, 0xC006
    ctx->r11 = 0 | 0XC006;
    // 0x8000CB6C: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x8000CB70: nop

    // 0x8000CB74: sh          $t3, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r11;
    // 0x8000CB78: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8000CB7C: nop

    // 0x8000CB80: lw          $t8, 0xC($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC);
    // 0x8000CB84: nop

    // 0x8000CB88: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8000CB8C: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
    // 0x8000CB90: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8000CB94: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8000CB98: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8000CB9C: lw          $t1, 0xC($t2)
    ctx->r9 = MEM_W(ctx->r10, 0XC);
    // 0x8000CBA0: nop

    // 0x8000CBA4: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x8000CBA8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8000CBAC: nop

    // 0x8000CBB0: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x8000CBB4: nop

    // 0x8000CBB8: addiu       $t3, $t7, 0x2
    ctx->r11 = ADD32(ctx->r15, 0X2);
    // 0x8000CBBC: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
    // 0x8000CBC0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8000CBC4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8000CBC8: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8000CBCC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000CBD0: nop

    // 0x8000CBD4: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x8000CBD8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8000CBDC: nop

    // 0x8000CBE0: lw          $t2, 0xC($t4)
    ctx->r10 = MEM_W(ctx->r12, 0XC);
    // 0x8000CBE4: nop

    // 0x8000CBE8: addiu       $t0, $t2, 0x2
    ctx->r8 = ADD32(ctx->r10, 0X2);
    // 0x8000CBEC: sw          $t0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r8;
    // 0x8000CBF0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8000CBF4: nop

    // 0x8000CBF8: lw          $t7, 0xC($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XC);
    // 0x8000CBFC: nop

    // 0x8000CC00: sw          $t7, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r15;
    // 0x8000CC04: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8000CC08: nop

    // 0x8000CC0C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8000CC10: nop

    // 0x8000CC14: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x8000CC18: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000CC1C: jal         0x8000D390
    // 0x8000CC20: nop

    TempHeap_Free(rdram, ctx);
        goto after_9;
    // 0x8000CC20: nop

    after_9:
    // 0x8000CC24: b           L_8000CC34
    // 0x8000CC28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000CC34;
    // 0x8000CC28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000CC2C: b           L_8000CC34
    // 0x8000CC30: nop

        goto L_8000CC34;
    // 0x8000CC30: nop

L_8000CC34:
    // 0x8000CC34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000CC38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000CC3C: jr          $ra
    // 0x8000CC40: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000CC40: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80022150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022150: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80022154: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80022158: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8002215C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80022160: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80022164: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80022168: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002216C: swc1        $f4, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f4.u32l;
    // 0x80022170: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80022174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022178: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002217C: swc1        $f6, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f6.u32l;
    // 0x80022180: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80022184: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022188: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002218C: swc1        $f8, 0xE6C($at)
    MEM_W(0XE6C, ctx->r1) = ctx->f8.u32l;
    // 0x80022190: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022194: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
    // 0x80022198: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002219C: sb          $zero, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = 0;
    // 0x800221A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221A4: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x800221A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221AC: sh          $zero, 0x654($at)
    MEM_H(0X654, ctx->r1) = 0;
    // 0x800221B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221B4: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
    // 0x800221B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221BC: sh          $zero, 0x67C($at)
    MEM_H(0X67C, ctx->r1) = 0;
    // 0x800221C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221C4: sb          $zero, 0xE54($at)
    MEM_B(0XE54, ctx->r1) = 0;
    // 0x800221C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221CC: sb          $zero, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = 0;
    // 0x800221D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221D4: sh          $zero, 0x126E($at)
    MEM_H(0X126E, ctx->r1) = 0;
    // 0x800221D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800221DC: addiu       $t6, $t6, 0x1668
    ctx->r14 = ADD32(ctx->r14, 0X1668);
    // 0x800221E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800221E4: addiu       $t7, $t7, 0x1668
    ctx->r15 = ADD32(ctx->r15, 0X1668);
    // 0x800221E8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800221EC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800221F0: nop

    // 0x800221F4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800221F8: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x800221FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022200: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x80022204: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80022208: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002220C: swc1        $f10, 0xD58($at)
    MEM_W(0XD58, ctx->r1) = ctx->f10.u32l;
    // 0x80022210: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022214: swc1        $f10, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f10.u32l;
    // 0x80022218: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002221C: swc1        $f10, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f10.u32l;
    // 0x80022220: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022224: sw          $zero, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = 0;
    // 0x80022228: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002222C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80022230: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x80022234: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x80022238: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002223C: lhu         $t3, 0x11AC($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X11AC);
    // 0x80022240: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80022244: lhu         $t5, 0x1258($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1258);
    // 0x80022248: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002224C: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80022250: lhu         $t8, 0x1260($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1260);
    // 0x80022254: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80022258: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8002225C: lhu         $t9, 0x126C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X126C);
    // 0x80022260: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80022264: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80022268: lhu         $t1, 0x1042($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1042);
    // 0x8002226C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80022270: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80022274: lhu         $t3, 0x10F2($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X10F2);
    // 0x80022278: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8002227C: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80022280: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022284: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x80022288: sh          $t4, 0x6C8($at)
    MEM_H(0X6C8, ctx->r1) = ctx->r12;
    // 0x8002228C: jal         0x800BC6EC
    // 0x80022290: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80022290: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x80022294: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022298: sw          $v0, 0xCDC($at)
    MEM_W(0XCDC, ctx->r1) = ctx->r2;
    // 0x8002229C: jal         0x800BC6EC
    // 0x800222A0: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800222A0: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_1:
    // 0x800222A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800222A8: sw          $v0, 0xCD0($at)
    MEM_W(0XCD0, ctx->r1) = ctx->r2;
    // 0x800222AC: jal         0x800BC6EC
    // 0x800222B0: addiu       $a0, $zero, 0x2C0
    ctx->r4 = ADD32(0, 0X2C0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800222B0: addiu       $a0, $zero, 0x2C0
    ctx->r4 = ADD32(0, 0X2C0);
    after_2:
    // 0x800222B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800222B8: sw          $v0, 0xCE8($at)
    MEM_W(0XCE8, ctx->r1) = ctx->r2;
    // 0x800222BC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800222C0: lw          $t5, 0xCE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE8);
    // 0x800222C4: nop

    // 0x800222C8: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800222CC: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
L_800222D0:
    // 0x800222D0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800222D4: jal         0x80099E2C
    // 0x800222D8: nop

    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x800222D8: nop

    after_3:
    // 0x800222DC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800222E0: addiu       $t6, $zero, -0x28
    ctx->r14 = ADD32(0, -0X28);
    // 0x800222E4: sw          $t6, 0x104($t8)
    MEM_W(0X104, ctx->r24) = ctx->r14;
    // 0x800222E8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800222EC: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x800222F0: sw          $t7, 0x108($t9)
    MEM_W(0X108, ctx->r25) = ctx->r15;
    // 0x800222F4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800222F8: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x800222FC: sw          $t0, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->r8;
    // 0x80022300: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80022304: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x80022308: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
    // 0x8002230C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80022310: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80022314: sh          $t4, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r12;
    // 0x80022318: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002231C: nop

    // 0x80022320: addiu       $t8, $t6, 0x160
    ctx->r24 = ADD32(ctx->r14, 0X160);
    // 0x80022324: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80022328: lh          $t7, 0x4E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4E);
    // 0x8002232C: nop

    // 0x80022330: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80022334: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x80022338: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002233C: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80022340: bne         $at, $zero, L_800222D0
    if (ctx->r1 != 0) {
        // 0x80022344: sh          $t9, 0x4E($sp)
        MEM_H(0X4E, ctx->r29) = ctx->r25;
            goto L_800222D0;
    }
    // 0x80022344: sh          $t9, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r25;
    // 0x80022348: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002234C: nop

    // 0x80022350: addiu       $t3, $t2, -0x160
    ctx->r11 = ADD32(ctx->r10, -0X160);
    // 0x80022354: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80022358: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002235C: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x80022360: sh          $t4, 0x100($t5)
    MEM_H(0X100, ctx->r13) = ctx->r12;
    // 0x80022364: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80022368: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002236C: sh          $t6, 0x102($t8)
    MEM_H(0X102, ctx->r24) = ctx->r14;
    // 0x80022370: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80022374: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80022378: addiu       $t7, $t7, -0x44B8
    ctx->r15 = ADD32(ctx->r15, -0X44B8);
    // 0x8002237C: sw          $t7, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r15;
    // 0x80022380: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80022384: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80022388: sh          $t0, 0x116($t1)
    MEM_H(0X116, ctx->r9) = ctx->r8;
    // 0x8002238C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80022390: addiu       $t2, $t2, 0x5B0
    ctx->r10 = ADD32(ctx->r10, 0X5B0);
    // 0x80022394: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80022398: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002239C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800223A0: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x800223A4: addiu       $a2, $a2, 0x3C30
    ctx->r6 = ADD32(ctx->r6, 0X3C30);
    // 0x800223A8: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800223AC: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800223B0: jal         0x800BD1FC
    // 0x800223B4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x800223B4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_4:
    // 0x800223B8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800223BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800223C0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800223C4: jal         0x800BD218
    // 0x800223C8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x800223C8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x800223CC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800223D0: nop

    // 0x800223D4: addiu       $t4, $t3, -0x160
    ctx->r12 = ADD32(ctx->r11, -0X160);
    // 0x800223D8: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800223DC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800223E0: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x800223E4: sh          $t5, 0x100($t6)
    MEM_H(0X100, ctx->r14) = ctx->r13;
    // 0x800223E8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800223EC: addiu       $t8, $zero, 0x1A
    ctx->r24 = ADD32(0, 0X1A);
    // 0x800223F0: sh          $t8, 0x102($t7)
    MEM_H(0X102, ctx->r15) = ctx->r24;
    // 0x800223F4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800223F8: lw          $t9, 0x1688($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1688);
    // 0x800223FC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80022400: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x80022404: nop

    // 0x80022408: sw          $t0, 0x138($t1)
    MEM_W(0X138, ctx->r9) = ctx->r8;
    // 0x8002240C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80022410: nop

    // 0x80022414: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x80022418: nop

    // 0x8002241C: ori         $t4, $t3, 0x100
    ctx->r12 = ctx->r11 | 0X100;
    // 0x80022420: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
    // 0x80022424: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80022428: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002242C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80022430: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80022434: lui         $t8, 0x809B
    ctx->r24 = S32(0X809B << 16);
    // 0x80022438: addiu       $t8, $t8, 0x1E10
    ctx->r24 = ADD32(ctx->r24, 0X1E10);
    // 0x8002243C: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x80022440: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x80022444: jal         0x800BD1FC
    // 0x80022448: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x80022448: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    after_6:
    // 0x8002244C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80022450: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80022454: jal         0x800BED70
    // 0x80022458: nop

    Spi_GetHeader(rdram, ctx);
        goto after_7;
    // 0x80022458: nop

    after_7:
    // 0x8002245C: sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    // 0x80022460: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80022464: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x80022468: jal         0x800BC6EC
    // 0x8002246C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x8002246C: nop

    after_8:
    // 0x80022470: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80022474: nop

    // 0x80022478: sw          $v0, 0x128($t7)
    MEM_W(0X128, ctx->r15) = ctx->r2;
    // 0x8002247C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80022480: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80022484: lh          $a1, 0x4C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4C);
    // 0x80022488: lw          $a2, 0x128($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X128);
    // 0x8002248C: jal         0x800BF0B4
    // 0x80022490: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_9;
    // 0x80022490: nop

    after_9:
    // 0x80022494: jal         0x800BC6EC
    // 0x80022498: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_10;
    // 0x80022498: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_10:
    // 0x8002249C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800224A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800224A4: sw          $s0, 0x20C($t0)
    MEM_W(0X20C, ctx->r8) = ctx->r16;
    // 0x800224A8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800224AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800224B0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800224B4: nop

    // 0x800224B8: swc1        $f16, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f16.u32l;
    // 0x800224BC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800224C0: nop

    // 0x800224C4: lwc1        $f18, 0x1C($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800224C8: nop

    // 0x800224CC: swc1        $f18, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f18.u32l;
    // 0x800224D0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800224D4: nop

    // 0x800224D8: sh          $zero, 0x22($t4)
    MEM_H(0X22, ctx->r12) = 0;
    // 0x800224DC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800224E0: nop

    // 0x800224E4: sh          $zero, 0x20($t2)
    MEM_H(0X20, ctx->r10) = 0;
    // 0x800224E8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800224EC: nop

    // 0x800224F0: lh          $t6, 0x20($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X20);
    // 0x800224F4: nop

    // 0x800224F8: sh          $t6, 0x24($t5)
    MEM_H(0X24, ctx->r13) = ctx->r14;
    // 0x800224FC: jal         0x800BC6EC
    // 0x80022500: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x80022500: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_11:
    // 0x80022504: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80022508: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002250C: sw          $s0, 0x210($t8)
    MEM_W(0X210, ctx->r24) = ctx->r16;
    // 0x80022510: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80022514: jal         0x800BC6EC
    // 0x80022518: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_12;
    // 0x80022518: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_12:
    // 0x8002251C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80022520: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80022524: sw          $s0, 0x214($t7)
    MEM_W(0X214, ctx->r15) = ctx->r16;
    // 0x80022528: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8002252C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80022530: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80022534: sw          $t9, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r25;
    // 0x80022538: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002253C: lwc1        $f4, 0xE60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x80022540: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80022544: nop

    // 0x80022548: swc1        $f4, 0x1B0($t1)
    MEM_W(0X1B0, ctx->r9) = ctx->f4.u32l;
    // 0x8002254C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022550: lwc1        $f6, 0xE6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE6C);
    // 0x80022554: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80022558: nop

    // 0x8002255C: swc1        $f6, 0x1B4($t3)
    MEM_W(0X1B4, ctx->r11) = ctx->f6.u32l;
    // 0x80022560: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
L_80022564:
    // 0x80022564: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80022568: jal         0x80099E2C
    // 0x8002256C: nop

    func_80099E2C(rdram, ctx);
        goto after_13;
    // 0x8002256C: nop

    after_13:
    // 0x80022570: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022574: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80022578: nop

    // 0x8002257C: swc1        $f8, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f8.u32l;
    // 0x80022580: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80022584: addiu       $t2, $zero, 0x48
    ctx->r10 = ADD32(0, 0X48);
    // 0x80022588: sw          $t2, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r10;
    // 0x8002258C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80022590: addiu       $t5, $zero, 0x5A
    ctx->r13 = ADD32(0, 0X5A);
    // 0x80022594: sw          $t5, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r13;
    // 0x80022598: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002259C: nop

    // 0x800225A0: sw          $zero, 0x140($t7)
    MEM_W(0X140, ctx->r15) = 0;
    // 0x800225A4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800225A8: nop

    // 0x800225AC: lw          $t0, 0x140($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X140);
    // 0x800225B0: nop

    // 0x800225B4: sw          $t0, 0x13C($t9)
    MEM_W(0X13C, ctx->r25) = ctx->r8;
    // 0x800225B8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800225BC: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800225C0: sh          $t1, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r9;
    // 0x800225C4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800225C8: nop

    // 0x800225CC: addiu       $t2, $t4, 0x160
    ctx->r10 = ADD32(ctx->r12, 0X160);
    // 0x800225D0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x800225D4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800225D8: nop

    // 0x800225DC: addiu       $t5, $t6, 0x40
    ctx->r13 = ADD32(ctx->r14, 0X40);
    // 0x800225E0: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800225E4: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x800225E8: nop

    // 0x800225EC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800225F0: sll         $t0, $t7, 16
    ctx->r8 = S32(ctx->r15 << 16);
    // 0x800225F4: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800225F8: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x800225FC: bne         $at, $zero, L_80022564
    if (ctx->r1 != 0) {
        // 0x80022600: sh          $t7, 0x4E($sp)
        MEM_H(0X4E, ctx->r29) = ctx->r15;
            goto L_80022564;
    }
    // 0x80022600: sh          $t7, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r15;
    // 0x80022604: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80022608: nop

    // 0x8002260C: addiu       $t3, $t1, -0x420
    ctx->r11 = ADD32(ctx->r9, -0X420);
    // 0x80022610: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80022614: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80022618: nop

    // 0x8002261C: addiu       $t2, $t4, -0xC0
    ctx->r10 = ADD32(ctx->r12, -0XC0);
    // 0x80022620: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80022624: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80022628: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8002262C: jal         0x800B1B3C
    // 0x80022630: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800B1B3C(rdram, ctx);
        goto after_14;
    // 0x80022630: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_14:
    // 0x80022634: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80022638: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002263C: lwc1        $f10, 0xE60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x80022640: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022644: lh          $a2, 0x22($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X22);
    // 0x80022648: lwc1        $f16, 0xE6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XE6C);
    // 0x8002264C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80022650: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80022654: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80022658: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8002265C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80022660: jal         0x800B202C
    // 0x80022664: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B202C(rdram, ctx);
        goto after_15;
    // 0x80022664: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x80022668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002266C: sh          $v0, 0x11A6($at)
    MEM_H(0X11A6, ctx->r1) = ctx->r2;
    // 0x80022670: b           L_80022680
    // 0x80022674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80022680;
    // 0x80022674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022678: b           L_80022680
    // 0x8002267C: nop

        goto L_80022680;
    // 0x8002267C: nop

L_80022680:
    // 0x80022680: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80022684: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80022688: jr          $ra
    // 0x8002268C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8002268C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800674A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800674A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800674AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800674B0: jal         0x80061488
    // 0x800674B4: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800674B4: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_0:
    // 0x800674B8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800674BC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800674C0: b           L_800674D0
    // 0x800674C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800674D0;
    // 0x800674C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800674C8: b           L_800674D0
    // 0x800674CC: nop

        goto L_800674D0;
    // 0x800674CC: nop

L_800674D0:
    // 0x800674D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800674D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800674D8: jr          $ra
    // 0x800674DC: nop

    return;
    // 0x800674DC: nop

;}
RECOMP_FUNC void func_80034048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034048: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003404C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80034050: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034054: nop

    // 0x80034058: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8003405C: nop

    // 0x80034060: bc1f        L_80034074
    if (!c1cs) {
        // 0x80034064: nop
    
            goto L_80034074;
    }
    // 0x80034064: nop

    // 0x80034068: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003406C: b           L_80034080
    // 0x80034070: nop

        goto L_80034080;
    // 0x80034070: nop

L_80034074:
    // 0x80034074: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80034078: nop

    // 0x8003407C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_80034080:
    // 0x80034080: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80034084: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034088: nop

    // 0x8003408C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80034090: nop

    // 0x80034094: bc1f        L_800340C4
    if (!c1cs) {
        // 0x80034098: nop
    
            goto L_800340C4;
    }
    // 0x80034098: nop

    // 0x8003409C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800340A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800340A4: nop

    // 0x800340A8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800340AC: nop

    // 0x800340B0: bc1f        L_800340C4
    if (!c1cs) {
        // 0x800340B4: nop
    
            goto L_800340C4;
    }
    // 0x800340B4: nop

    // 0x800340B8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800340BC: nop

    // 0x800340C0: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_800340C4:
    // 0x800340C4: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800340C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800340CC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800340D0: nop

    // 0x800340D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800340D8: nop

    // 0x800340DC: bc1f        L_80034120
    if (!c1cs) {
        // 0x800340E0: nop
    
            goto L_80034120;
    }
    // 0x800340E0: nop

    // 0x800340E4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800340E8: lbu         $t6, 0x72AE($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X72AE);
    // 0x800340EC: nop

    // 0x800340F0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800340F4: beq         $t7, $zero, L_80034108
    if (ctx->r15 == 0) {
        // 0x800340F8: nop
    
            goto L_80034108;
    }
    // 0x800340F8: nop

    // 0x800340FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80034100: nop

    // 0x80034104: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_80034108:
    // 0x80034108: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8003410C: lbu         $t8, 0x72AE($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X72AE);
    // 0x80034110: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80034114: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80034118: b           L_80034138
    // 0x8003411C: sb          $t9, 0x72AE($at)
    MEM_B(0X72AE, ctx->r1) = ctx->r25;
        goto L_80034138;
    // 0x8003411C: sb          $t9, 0x72AE($at)
    MEM_B(0X72AE, ctx->r1) = ctx->r25;
L_80034120:
    // 0x80034120: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80034124: lbu         $t0, 0x72AE($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X72AE);
    // 0x80034128: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8003412C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80034130: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80034134: sb          $t1, 0x72AE($at)
    MEM_B(0X72AE, ctx->r1) = ctx->r9;
L_80034138:
    // 0x80034138: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8003413C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80034140: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80034144: nop

    // 0x80034148: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8003414C: nop

    // 0x80034150: bc1f        L_80034194
    if (!c1cs) {
        // 0x80034154: nop
    
            goto L_80034194;
    }
    // 0x80034154: nop

    // 0x80034158: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003415C: lbu         $t2, 0x72AE($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X72AE);
    // 0x80034160: nop

    // 0x80034164: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80034168: beq         $t3, $zero, L_8003417C
    if (ctx->r11 == 0) {
        // 0x8003416C: nop
    
            goto L_8003417C;
    }
    // 0x8003416C: nop

    // 0x80034170: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80034174: nop

    // 0x80034178: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_8003417C:
    // 0x8003417C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80034180: lbu         $t4, 0x72AE($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X72AE);
    // 0x80034184: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80034188: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x8003418C: b           L_800341AC
    // 0x80034190: sb          $t5, 0x72AE($at)
    MEM_B(0X72AE, ctx->r1) = ctx->r13;
        goto L_800341AC;
    // 0x80034190: sb          $t5, 0x72AE($at)
    MEM_B(0X72AE, ctx->r1) = ctx->r13;
L_80034194:
    // 0x80034194: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80034198: lbu         $t6, 0x72AE($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X72AE);
    // 0x8003419C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800341A0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800341A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800341A8: sb          $t7, 0x72AE($at)
    MEM_B(0X72AE, ctx->r1) = ctx->r15;
L_800341AC:
    // 0x800341AC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800341B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800341B4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800341B8: nop

    // 0x800341BC: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800341C0: nop

    // 0x800341C4: bc1f        L_80034208
    if (!c1cs) {
        // 0x800341C8: nop
    
            goto L_80034208;
    }
    // 0x800341C8: nop

    // 0x800341CC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800341D0: lbu         $t8, 0x72AE($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X72AE);
    // 0x800341D4: nop

    // 0x800341D8: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x800341DC: beq         $t9, $zero, L_800341F0
    if (ctx->r25 == 0) {
        // 0x800341E0: nop
    
            goto L_800341F0;
    }
    // 0x800341E0: nop

    // 0x800341E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800341E8: nop

    // 0x800341EC: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_800341F0:
    // 0x800341F0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800341F4: lbu         $t0, 0x72AE($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X72AE);
    // 0x800341F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800341FC: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80034200: b           L_80034220
    // 0x80034204: sb          $t1, 0x72AE($at)
    MEM_B(0X72AE, ctx->r1) = ctx->r9;
        goto L_80034220;
    // 0x80034204: sb          $t1, 0x72AE($at)
    MEM_B(0X72AE, ctx->r1) = ctx->r9;
L_80034208:
    // 0x80034208: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8003420C: lbu         $t2, 0x72AE($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X72AE);
    // 0x80034210: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80034214: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80034218: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8003421C: sb          $t3, 0x72AE($at)
    MEM_B(0X72AE, ctx->r1) = ctx->r11;
L_80034220:
    // 0x80034220: b           L_80034228
    // 0x80034224: nop

        goto L_80034228;
    // 0x80034224: nop

L_80034228:
    // 0x80034228: jr          $ra
    // 0x8003422C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8003422C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80062A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062A90: jal         0x8005F064
    // 0x80062A94: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062A94: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_0:
    // 0x80062A98: b           L_80062AA8
    // 0x80062A9C: nop

        goto L_80062AA8;
    // 0x80062A9C: nop

    // 0x80062AA0: b           L_80062AA8
    // 0x80062AA4: nop

        goto L_80062AA8;
    // 0x80062AA4: nop

L_80062AA8:
    // 0x80062AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062AB0: jr          $ra
    // 0x80062AB4: nop

    return;
    // 0x80062AB4: nop

;}
RECOMP_FUNC void func_8006846C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006846C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068474: jal         0x80061488
    // 0x80068478: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068478: addiu       $a0, $zero, 0x341
    ctx->r4 = ADD32(0, 0X341);
    after_0:
    // 0x8006847C: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80068480: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80068484: b           L_80068494
    // 0x80068488: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068494;
    // 0x80068488: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006848C: b           L_80068494
    // 0x80068490: nop

        goto L_80068494;
    // 0x80068490: nop

L_80068494:
    // 0x80068494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006849C: jr          $ra
    // 0x800684A0: nop

    return;
    // 0x800684A0: nop

;}
RECOMP_FUNC void func_800989BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800989BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800989C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800989C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800989C8: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800989CC: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800989D0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800989D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800989D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800989DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800989E0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800989E4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800989E8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800989EC: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800989F0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800989F4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800989F8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800989FC: nop

    // 0x80098A00: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x80098A04: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x80098A08: nop

    // 0x80098A0C: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80098A10: bne         $t2, $zero, L_80098A20
    if (ctx->r10 != 0) {
        // 0x80098A14: nop
    
            goto L_80098A20;
    }
    // 0x80098A14: nop

    // 0x80098A18: b           L_80098AC8
    // 0x80098A1C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80098AC8;
    // 0x80098A1C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80098A20:
    // 0x80098A20: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80098A24: nop

    // 0x80098A28: addiu       $t4, $t3, 0x7FFF
    ctx->r12 = ADD32(ctx->r11, 0X7FFF);
    // 0x80098A2C: lbu         $t4, 0x2E9($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X2E9);
    // 0x80098A30: nop

    // 0x80098A34: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x80098A38: bne         $t5, $zero, L_80098A48
    if (ctx->r13 != 0) {
        // 0x80098A3C: nop
    
            goto L_80098A48;
    }
    // 0x80098A3C: nop

    // 0x80098A40: b           L_80098AC8
    // 0x80098A44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80098AC8;
    // 0x80098A44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80098A48:
    // 0x80098A48: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80098A4C: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x80098A50: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80098A54: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80098A58: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80098A5C: nop

    // 0x80098A60: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80098A64: nop

    // 0x80098A68: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80098A6C: beq         $t0, $zero, L_80098A8C
    if (ctx->r8 == 0) {
        // 0x80098A70: nop
    
            goto L_80098A8C;
    }
    // 0x80098A70: nop

    // 0x80098A74: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80098A78: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80098A7C: jal         0x8009731C
    // 0x80098A80: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    Scheduler_RemoveClient(rdram, ctx);
        goto after_0;
    // 0x80098A80: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_0:
    // 0x80098A84: b           L_80098A9C
    // 0x80098A88: nop

        goto L_80098A9C;
    // 0x80098A88: nop

L_80098A8C:
    // 0x80098A8C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80098A90: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80098A94: jal         0x8009731C
    // 0x80098A98: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    Scheduler_RemoveClient(rdram, ctx);
        goto after_1;
    // 0x80098A98: addiu       $a0, $a0, 0x3E30
    ctx->r4 = ADD32(ctx->r4, 0X3E30);
    after_1:
L_80098A9C:
    // 0x80098A9C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80098AA0: nop

    // 0x80098AA4: addiu       $t2, $t1, 0x7FFF
    ctx->r10 = ADD32(ctx->r9, 0X7FFF);
    // 0x80098AA8: lbu         $t2, 0x2E9($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X2E9);
    // 0x80098AAC: addiu       $at, $t1, 0x7FFF
    ctx->r1 = ADD32(ctx->r9, 0X7FFF);
    // 0x80098AB0: andi        $t3, $t2, 0xFD
    ctx->r11 = ctx->r10 & 0XFD;
    // 0x80098AB4: sb          $t3, 0x2E9($at)
    MEM_B(0X2E9, ctx->r1) = ctx->r11;
    // 0x80098AB8: b           L_80098AC8
    // 0x80098ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098AC8;
    // 0x80098ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80098AC0: b           L_80098AC8
    // 0x80098AC4: nop

        goto L_80098AC8;
    // 0x80098AC4: nop

L_80098AC8:
    // 0x80098AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098ACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098AD0: jr          $ra
    // 0x80098AD4: nop

    return;
    // 0x80098AD4: nop

;}
RECOMP_FUNC void func_80075914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007591C: jal         0x80061348
    // 0x80075920: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075920: addiu       $a0, $zero, 0x45D
    ctx->r4 = ADD32(0, 0X45D);
    after_0:
    // 0x80075924: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075928: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007592C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075930: beq         $v0, $zero, L_80075984
    if (ctx->r2 == 0) {
        // 0x80075934: nop
    
            goto L_80075984;
    }
    // 0x80075934: nop

    // 0x80075938: jal         0x80061348
    // 0x8007593C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007593C: addiu       $a0, $zero, 0x4E5
    ctx->r4 = ADD32(0, 0X4E5);
    after_1:
    // 0x80075940: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075944: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075948: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007594C: beq         $v0, $zero, L_80075984
    if (ctx->r2 == 0) {
        // 0x80075950: nop
    
            goto L_80075984;
    }
    // 0x80075950: nop

    // 0x80075954: jal         0x80061348
    // 0x80075958: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075958: addiu       $a0, $zero, 0x4E6
    ctx->r4 = ADD32(0, 0X4E6);
    after_2:
    // 0x8007595C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075960: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075964: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075968: beq         $v0, $zero, L_80075984
    if (ctx->r2 == 0) {
        // 0x8007596C: nop
    
            goto L_80075984;
    }
    // 0x8007596C: nop

    // 0x80075970: jal         0x80061348
    // 0x80075974: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075974: addiu       $a0, $zero, 0x4E7
    ctx->r4 = ADD32(0, 0X4E7);
    after_3:
    // 0x80075978: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007597C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075980: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075984:
    // 0x80075984: b           L_80075994
    // 0x80075988: nop

        goto L_80075994;
    // 0x80075988: nop

    // 0x8007598C: b           L_80075994
    // 0x80075990: nop

        goto L_80075994;
    // 0x80075990: nop

L_80075994:
    // 0x80075994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007599C: jr          $ra
    // 0x800759A0: nop

    return;
    // 0x800759A0: nop

;}
RECOMP_FUNC void func_80022EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022EE4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80022EE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80022EEC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80022EF0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80022EF4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80022EF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022EFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022F00: lwc1        $f4, 0x1264($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1264);
    // 0x80022F04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022F08: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80022F0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022F10: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80022F14: swc1        $f8, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->f8.u32l;
    // 0x80022F18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80022F1C: lw          $t6, 0xCE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE8);
    // 0x80022F20: nop

    // 0x80022F24: addiu       $t7, $t6, 0x160
    ctx->r15 = ADD32(ctx->r14, 0X160);
    // 0x80022F28: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80022F2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80022F30: lh          $t8, 0x654($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X654);
    // 0x80022F34: lh          $t9, 0x52($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X52);
    // 0x80022F38: nop

    // 0x80022F3C: beq         $t8, $t9, L_80023128
    if (ctx->r24 == ctx->r25) {
        // 0x80022F40: nop
    
            goto L_80023128;
    }
    // 0x80022F40: nop

    // 0x80022F44: jal         0x80096474
    // 0x80022F48: nop

    func_80096474(rdram, ctx);
        goto after_0;
    // 0x80022F48: nop

    after_0:
    // 0x80022F4C: jal         0x80090754
    // 0x80022F50: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_80090754(rdram, ctx);
        goto after_1;
    // 0x80022F50: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_1:
    // 0x80022F54: jal         0x80090728
    // 0x80022F58: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    func_80090728(rdram, ctx);
        goto after_2;
    // 0x80022F58: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    after_2:
    // 0x80022F5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022F60: jal         0x8008EAA8
    // 0x80022F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_3;
    // 0x80022F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80022F68: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80022F6C: lh          $t0, 0x67C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X67C);
    // 0x80022F70: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80022F74: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80022F78: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80022F7C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80022F80: lw          $t2, 0xCD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCD0);
    // 0x80022F84: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80022F88: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80022F8C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80022F90: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x80022F94: sw          $s0, 0x128($t3)
    MEM_W(0X128, ctx->r11) = ctx->r16;
    // 0x80022F98: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80022F9C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80022FA0: lh          $t4, 0x67C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X67C);
    // 0x80022FA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022FA8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80022FAC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80022FB0: sh          $t6, 0x67C($at)
    MEM_H(0X67C, ctx->r1) = ctx->r14;
    // 0x80022FB4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80022FB8: jal         0x8008ECCC
    // 0x80022FBC: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_4;
    // 0x80022FBC: nop

    after_4:
    // 0x80022FC0: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
L_80022FC4:
    // 0x80022FC4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80022FC8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80022FCC: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80022FD0: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80022FD4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80022FD8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80022FDC: nop

    // 0x80022FE0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80022FE4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80022FE8: lh          $t2, 0x4E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4E);
    // 0x80022FEC: nop

    // 0x80022FF0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80022FF4: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80022FF8: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80022FFC: slti        $at, $t5, 0x64
    ctx->r1 = SIGNED(ctx->r13) < 0X64 ? 1 : 0;
    // 0x80023000: bne         $at, $zero, L_80022FC4
    if (ctx->r1 != 0) {
        // 0x80023004: sh          $t3, 0x4E($sp)
        MEM_H(0X4E, ctx->r29) = ctx->r11;
            goto L_80022FC4;
    }
    // 0x80023004: sh          $t3, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r11;
    // 0x80023008: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8002300C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80023010: sw          $t6, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r14;
    // 0x80023014: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80023018: sw          $zero, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = 0;
    // 0x8002301C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80023020: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80023024: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80023028: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002302C: jal         0x8008ECAC
    // 0x80023030: nop

    func_8008ECAC(rdram, ctx);
        goto after_5;
    // 0x80023030: nop

    after_5:
    // 0x80023034: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80023038: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002303C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80023040: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80023044: jal         0x8008EC8C
    // 0x80023048: nop

    func_8008EC8C(rdram, ctx);
        goto after_6;
    // 0x80023048: nop

    after_6:
    // 0x8002304C: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x80023050: nop

    // 0x80023054: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80023058: beq         $t9, $zero, L_80023070
    if (ctx->r25 == 0) {
        // 0x8002305C: nop
    
            goto L_80023070;
    }
    // 0x8002305C: nop

    // 0x80023060: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80023064: lw          $t7, 0x103C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X103C);
    // 0x80023068: b           L_8002308C
    // 0x8002306C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
        goto L_8002308C;
    // 0x8002306C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_80023070:
    // 0x80023070: lh          $t0, 0x52($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X52);
    // 0x80023074: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80023078: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002307C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80023080: lw          $t2, -0x41F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X41F8);
    // 0x80023084: nop

    // 0x80023088: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_8002308C:
    // 0x8002308C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80023090: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80023094: jal         0x8008ECE4
    // 0x80023098: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x80023098: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    after_7:
    // 0x8002309C: sh          $v0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r2;
    // 0x800230A0: lh          $t3, 0x4E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X4E);
    // 0x800230A4: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800230A8: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800230AC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800230B0: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x800230B4: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800230B8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800230BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800230C0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800230C4: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800230C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800230CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800230D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800230D4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800230D8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800230DC: swc1        $f10, 0xD58($at)
    MEM_W(0XD58, ctx->r1) = ctx->f10.u32l;
    // 0x800230E0: lh          $t6, 0x4E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4E);
    // 0x800230E4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800230E8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800230EC: lwc1        $f5, -0x1CA8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1CA8);
    // 0x800230F0: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800230F4: lwc1        $f4, -0x1CA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1CA4);
    // 0x800230F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800230FC: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80023100: lw          $t8, 0xCE8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE8);
    // 0x80023104: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80023108: swc1        $f8, 0xF4($t8)
    MEM_W(0XF4, ctx->r24) = ctx->f8.u32l;
    // 0x8002310C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023110: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
    // 0x80023114: lh          $t9, 0x52($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X52);
    // 0x80023118: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002311C: sh          $t9, 0x654($at)
    MEM_H(0X654, ctx->r1) = ctx->r25;
    // 0x80023120: jal         0x800967D8
    // 0x80023124: nop

    func_800967D8(rdram, ctx);
        goto after_8;
    // 0x80023124: nop

    after_8:
L_80023128:
    // 0x80023128: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002312C: lh          $t7, 0x65C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X65C);
    // 0x80023130: nop

    // 0x80023134: slti        $at, $t7, 0x78
    ctx->r1 = SIGNED(ctx->r15) < 0X78 ? 1 : 0;
    // 0x80023138: beq         $at, $zero, L_800234C0
    if (ctx->r1 == 0) {
        // 0x8002313C: nop
    
            goto L_800234C0;
    }
    // 0x8002313C: nop

    // 0x80023140: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023144: lwc1        $f10, 0x1264($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1264);
    // 0x80023148: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002314C: lwc1        $f19, -0x1CA0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1CA0);
    // 0x80023150: lwc1        $f18, -0x1C9C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1C9C);
    // 0x80023154: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80023158: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8002315C: jal         0x800C3070
    // 0x80023160: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_9;
    // 0x80023160: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_9:
    // 0x80023164: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80023168: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002316C: nop

    // 0x80023170: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80023174: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80023178: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002317C: lwc1        $f10, 0x1264($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1264);
    // 0x80023180: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80023184: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80023188: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002318C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80023190: lwc1        $f7, -0x1C98($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1C98);
    // 0x80023194: lwc1        $f6, -0x1C94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C94);
    // 0x80023198: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002319C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800231A0: jal         0x800C3070
    // 0x800231A4: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_10;
    // 0x800231A4: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_10:
    // 0x800231A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800231AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800231B0: nop

    // 0x800231B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800231B8: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x800231BC: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800231C0: nop

    // 0x800231C4: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800231C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800231CC: nop

    // 0x800231D0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800231D4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800231D8: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x800231DC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800231E0: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x800231E4: nop

    // 0x800231E8: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800231EC: sw          $t2, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r10;
    // 0x800231F0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800231F4: lh          $t4, 0x664($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X664);
    // 0x800231F8: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x800231FC: bne         $t4, $at, L_80023248
    if (ctx->r12 != ctx->r1) {
        // 0x80023200: nop
    
            goto L_80023248;
    }
    // 0x80023200: nop

    // 0x80023204: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80023208: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x8002320C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80023210: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023214: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80023218: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8002321C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80023220: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80023224: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80023228: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x8002322C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80023230: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023234: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80023238: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8002323C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80023240: b           L_80023328
    // 0x80023244: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
        goto L_80023328;
    // 0x80023244: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
L_80023248:
    // 0x80023248: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002324C: lw          $t3, 0xCE8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XCE8);
    // 0x80023250: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80023254: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80023258: lwc1        $f18, 0xF4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XF4);
    // 0x8002325C: nop

    // 0x80023260: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80023264: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80023268: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002326C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80023270: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023274: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80023278: lwc1        $f5, -0x1C90($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1C90);
    // 0x8002327C: lwc1        $f4, -0x1C8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C8C);
    // 0x80023280: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80023284: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80023288: nop

    // 0x8002328C: bc1f        L_800232B0
    if (!c1cs) {
        // 0x80023290: nop
    
            goto L_800232B0;
    }
    // 0x80023290: nop

    // 0x80023294: lui         $at, 0xC302
    ctx->r1 = S32(0XC302 << 16);
    // 0x80023298: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002329C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800232A0: nop

    // 0x800232A4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800232A8: b           L_80023328
    // 0x800232AC: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
        goto L_80023328;
    // 0x800232AC: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
L_800232B0:
    // 0x800232B0: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800232B4: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800232B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800232BC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800232C0: lwc1        $f9, -0x1C88($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1C88);
    // 0x800232C4: lwc1        $f8, -0x1C84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1C84);
    // 0x800232C8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800232CC: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x800232D0: nop

    // 0x800232D4: bc1f        L_80023328
    if (!c1cs) {
        // 0x800232D8: nop
    
            goto L_80023328;
    }
    // 0x800232D8: nop

    // 0x800232DC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800232E0: lw          $t5, 0xCE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE8);
    // 0x800232E4: nop

    // 0x800232E8: lw          $t6, 0xC0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC0);
    // 0x800232EC: nop

    // 0x800232F0: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x800232F4: sw          $t8, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r24;
    // 0x800232F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800232FC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80023300: lwc1        $f11, -0x1C80($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1C80);
    // 0x80023304: lwc1        $f10, -0x1C7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1C7C);
    // 0x80023308: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002330C: sub.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d - ctx->f18.d;
    // 0x80023310: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80023314: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80023318: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8002331C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023320: nop

    // 0x80023324: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
L_80023328:
    // 0x80023328: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002332C: lwc1        $f10, 0xD58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XD58);
    // 0x80023330: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80023334: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80023338: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8002333C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80023340: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80023344: swc1        $f6, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f6.u32l;
    // 0x80023348: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002334C: lui         $at, 0x403F
    ctx->r1 = S32(0X403F << 16);
    // 0x80023350: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80023354: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023358: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002335C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80023360: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    // 0x80023364: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80023368: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002336C: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x80023370: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80023374: swc1        $f16, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f16.u32l;
    // 0x80023378: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8002337C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80023380: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80023384: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80023388: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8002338C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80023390: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x80023394: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80023398: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8002339C: add.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f6.d + ctx->f16.d;
    // 0x800233A0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800233A4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800233A8: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x800233AC: lw          $t1, 0xCE8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XCE8);
    // 0x800233B0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800233B4: swc1        $f6, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f6.u32l;
    // 0x800233B8: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800233BC: lui         $at, 0x403C
    ctx->r1 = S32(0X403C << 16);
    // 0x800233C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800233C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800233C8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800233CC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800233D0: add.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f4.d + ctx->f10.d;
    // 0x800233D4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800233D8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800233DC: add.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f18.d + ctx->f6.d;
    // 0x800233E0: lw          $t2, 0xCE8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCE8);
    // 0x800233E4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x800233E8: swc1        $f4, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f4.u32l;
    // 0x800233EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800233F0: lwc1        $f10, 0x1264($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1264);
    // 0x800233F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800233F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800233FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023400: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80023404: lwc1        $f17, -0x1C78($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1C78);
    // 0x80023408: lwc1        $f16, -0x1C74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1C74);
    // 0x8002340C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80023410: mul.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80023414: jal         0x800C3070
    // 0x80023418: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_11;
    // 0x80023418: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_11:
    // 0x8002341C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023420: lwc1        $f9, -0x1C70($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1C70);
    // 0x80023424: lwc1        $f8, -0x1C6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1C6C);
    // 0x80023428: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8002342C: mul.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80023430: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80023434: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80023438: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002343C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80023440: add.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f18.d + ctx->f6.d;
    // 0x80023444: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x80023448: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8002344C: swc1        $f4, 0xFC($t0)
    MEM_W(0XFC, ctx->r8) = ctx->f4.u32l;
    // 0x80023450: jal         0x800C1850
    // 0x80023454: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_12;
    // 0x80023454: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80023458: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002345C: lw          $a0, 0xCE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE8);
    // 0x80023460: jal         0x8009A14C
    // 0x80023464: nop

    func_8009A14C(rdram, ctx);
        goto after_13;
    // 0x80023464: nop

    after_13:
    // 0x80023468: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002346C: lw          $a0, 0xCE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE8);
    // 0x80023470: jal         0x800997D8
    // 0x80023474: nop

    func_800997D8(rdram, ctx);
        goto after_14;
    // 0x80023474: nop

    after_14:
    // 0x80023478: jal         0x800C1850
    // 0x8002347C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_15;
    // 0x8002347C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80023480: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80023484: jal         0x8009A14C
    // 0x80023488: nop

    func_8009A14C(rdram, ctx);
        goto after_16;
    // 0x80023488: nop

    after_16:
    // 0x8002348C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80023490: jal         0x800997D8
    // 0x80023494: nop

    func_800997D8(rdram, ctx);
        goto after_17;
    // 0x80023494: nop

    after_17:
    // 0x80023498: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002349C: lh          $t4, 0x65C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X65C);
    // 0x800234A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800234A4: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800234A8: sh          $t3, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = ctx->r11;
    // 0x800234AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800234B0: lbu         $t6, 0x125A($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X125A);
    // 0x800234B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800234B8: ori         $t8, $t6, 0x2
    ctx->r24 = ctx->r14 | 0X2;
    // 0x800234BC: sb          $t8, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = ctx->r24;
L_800234C0:
    // 0x800234C0: b           L_800234C8
    // 0x800234C4: nop

        goto L_800234C8;
    // 0x800234C4: nop

L_800234C8:
    // 0x800234C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800234CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800234D0: jr          $ra
    // 0x800234D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800234D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800A41B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A41B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A41B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A41BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A41C0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A41C4: nop

    // 0x800A41C8: bne         $t6, $zero, L_800A41D8
    if (ctx->r14 != 0) {
        // 0x800A41CC: nop
    
            goto L_800A41D8;
    }
    // 0x800A41CC: nop

    // 0x800A41D0: b           L_800A423C
    // 0x800A41D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A423C;
    // 0x800A41D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A41D8:
    // 0x800A41D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A41DC: nop

    // 0x800A41E0: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800A41E4: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A41E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A41EC: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A41F0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A41F4: jal         0x800BC6EC
    // 0x800A41F8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800A41F8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800A41FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A4200: sw          $v0, -0x728C($at)
    MEM_W(-0X728C, ctx->r1) = ctx->r2;
    // 0x800A4204: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A4208: lw          $t8, -0x728C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X728C);
    // 0x800A420C: nop

    // 0x800A4210: bne         $t8, $zero, L_800A4220
    if (ctx->r24 != 0) {
        // 0x800A4214: nop
    
            goto L_800A4220;
    }
    // 0x800A4214: nop

    // 0x800A4218: b           L_800A423C
    // 0x800A421C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A423C;
    // 0x800A421C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A4220:
    // 0x800A4220: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800A4224: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A4228: sw          $t9, -0x727C($at)
    MEM_W(-0X727C, ctx->r1) = ctx->r25;
    // 0x800A422C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A4230: sw          $zero, -0x7284($at)
    MEM_W(-0X7284, ctx->r1) = 0;
    // 0x800A4234: b           L_800A423C
    // 0x800A4238: nop

        goto L_800A423C;
    // 0x800A4238: nop

L_800A423C:
    // 0x800A423C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4244: jr          $ra
    // 0x800A4248: nop

    return;
    // 0x800A4248: nop

;}
RECOMP_FUNC void alCSeqSecToTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA9C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800CA9C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA9CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CA9D0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800CA9D4: ldc1        $f6, 0x1F0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1F0);
    // 0x800CA9D8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800CA9DC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CA9E0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800CA9E4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800CA9E8: bgez        $t7, L_800CAA00
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CA9EC: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_800CAA00;
    }
    // 0x800CA9EC: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800CA9F0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800CA9F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CA9F8: nop

    // 0x800CA9FC: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_800CAA00:
    // 0x800CAA00: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800CAA04: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800CAA08: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800CAA0C: bgez        $a2, L_800CAA24
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800CAA10: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_800CAA24;
    }
    // 0x800CAA10: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x800CAA14: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800CAA18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CAA1C: nop

    // 0x800CAA20: add.d       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f10.d + ctx->f18.d;
L_800CAA24:
    // 0x800CAA24: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800CAA28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CAA2C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800CAA30: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800CAA34: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800CAA38: nop

    // 0x800CAA3C: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800CAA40: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800CAA44: nop

    // 0x800CAA48: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800CAA4C: beql        $v0, $zero, L_800CAAA8
    if (ctx->r2 == 0) {
        // 0x800CAA50: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_800CAAA8;
    }
    goto skip_0;
    // 0x800CAA50: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x800CAA54: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CAA58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CAA5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CAA60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CAA64: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x800CAA68: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800CAA6C: nop

    // 0x800CAA70: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x800CAA74: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800CAA78: nop

    // 0x800CAA7C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800CAA80: bnel        $v0, $zero, L_800CAA9C
    if (ctx->r2 != 0) {
        // 0x800CAA84: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800CAA9C;
    }
    goto skip_1;
    // 0x800CAA84: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_1:
    // 0x800CAA88: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800CAA8C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CAA90: jr          $ra
    // 0x800CAA94: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x800CAA94: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x800CAA98: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
L_800CAA9C:
    // 0x800CAA9C: jr          $ra
    // 0x800CAAA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800CAAA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800CAAA4: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_800CAAA8:
    // 0x800CAAA8: nop

    // 0x800CAAAC: bltzl       $v0, L_800CAA9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800CAAB0: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800CAA9C;
    }
    goto skip_2;
    // 0x800CAAB0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_2:
    // 0x800CAAB4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CAAB8: jr          $ra
    // 0x800CAABC: nop

    return;
    // 0x800CAABC: nop

;}
RECOMP_FUNC void func_800859DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800859E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800859E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800859E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800859EC: jal         0x8008B4EC
    // 0x800859F0: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x800859F0: nop

    after_0:
    // 0x800859F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800859F8: jal         0x8008B600
    // 0x800859FC: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x800859FC: nop

    after_1:
    // 0x80085A00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085A08: jal         0x8008B738
    // 0x80085A0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80085A0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80085A10: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80085A14: jal         0x8008A518
    // 0x80085A18: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_3;
    // 0x80085A18: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80085A1C: beq         $v0, $zero, L_80085AB4
    if (ctx->r2 == 0) {
        // 0x80085A20: nop
    
            goto L_80085AB4;
    }
    // 0x80085A20: nop

    // 0x80085A24: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x80085A28: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80085A2C: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085A30: bne         $at, $zero, L_80085AB4
    if (ctx->r1 != 0) {
        // 0x80085A34: nop
    
            goto L_80085AB4;
    }
    // 0x80085A34: nop

    // 0x80085A38: ori         $at, $zero, 0x8061
    ctx->r1 = 0 | 0X8061;
    // 0x80085A3C: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80085A40: beq         $at, $zero, L_80085AB4
    if (ctx->r1 == 0) {
        // 0x80085A44: nop
    
            goto L_80085AB4;
    }
    // 0x80085A44: nop

    // 0x80085A48: lhu         $t7, 0x1C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1C);
    // 0x80085A4C: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80085A50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80085A54: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80085A58: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80085A5C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80085A60: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80085A64: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80085A68: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80085A6C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80085A70: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80085A74: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80085A78: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80085A7C: nop

    // 0x80085A80: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80085A84: nop

    // 0x80085A88: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80085A8C: beq         $t4, $zero, L_80085AB4
    if (ctx->r12 == 0) {
        // 0x80085A90: nop
    
            goto L_80085AB4;
    }
    // 0x80085A90: nop

    // 0x80085A94: andi        $t5, $t3, 0x4000
    ctx->r13 = ctx->r11 & 0X4000;
    // 0x80085A98: beq         $t5, $zero, L_80085AB4
    if (ctx->r13 == 0) {
        // 0x80085A9C: nop
    
            goto L_80085AB4;
    }
    // 0x80085A9C: nop

    // 0x80085AA0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80085AA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80085AA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085AAC: jal         0x8008B738
    // 0x80085AB0: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    func_8008B738(rdram, ctx);
        goto after_4;
    // 0x80085AB0: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    after_4:
L_80085AB4:
    // 0x80085AB4: b           L_80085ABC
    // 0x80085AB8: nop

        goto L_80085ABC;
    // 0x80085AB8: nop

L_80085ABC:
    // 0x80085ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085AC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80085AC4: jr          $ra
    // 0x80085AC8: nop

    return;
    // 0x80085AC8: nop

;}
RECOMP_FUNC void func_80077F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077F14: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077F18: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077F1C: nop

    // 0x80077F20: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80077F24: nop

    // 0x80077F28: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077F2C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077F30: jr          $ra
    // 0x80077F34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077F34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077F38: jr          $ra
    // 0x80077F3C: nop

    return;
    // 0x80077F3C: nop

    // 0x80077F40: jr          $ra
    // 0x80077F44: nop

    return;
    // 0x80077F44: nop

;}
RECOMP_FUNC void func_8006BD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BD68: jal         0x8005F064
    // 0x8006BD6C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BD6C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_0:
    // 0x8006BD70: b           L_8006BD80
    // 0x8006BD74: nop

        goto L_8006BD80;
    // 0x8006BD74: nop

    // 0x8006BD78: b           L_8006BD80
    // 0x8006BD7C: nop

        goto L_8006BD80;
    // 0x8006BD7C: nop

L_8006BD80:
    // 0x8006BD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BD84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BD88: jr          $ra
    // 0x8006BD8C: nop

    return;
    // 0x8006BD8C: nop

;}
RECOMP_FUNC void func_800098F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800098F0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800098F4: addiu       $t6, $a0, 0x40
    ctx->r14 = ADD32(ctx->r4, 0X40);
    // 0x800098F8: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800098FC: lw          $t7, 0x34C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34C);
    // 0x80009900: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80009904: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80009908: beq         $t8, $zero, L_80009A30
    if (ctx->r24 == 0) {
        // 0x8000990C: nop
    
            goto L_80009A30;
    }
    // 0x8000990C: nop

    // 0x80009910: lwc1        $f4, 0x1A0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009914: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009918: nop

    // 0x8000991C: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80009920: nop

    // 0x80009924: bc1f        L_800099D0
    if (!c1cs) {
        // 0x80009928: nop
    
            goto L_800099D0;
    }
    // 0x80009928: nop

    // 0x8000992C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009930: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009934: lwc1        $f8, 0x1AC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1AC);
    // 0x80009938: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8000993C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80009940: lwc1        $f18, 0xCC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x80009944: nop

    // 0x80009948: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8000994C: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x80009950: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009954: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009958: lwc1        $f6, 0x1B0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8000995C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009960: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80009964: lwc1        $f18, 0xD0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80009968: nop

    // 0x8000996C: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80009970: swc1        $f16, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f16.u32l;
    // 0x80009974: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009978: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000997C: lwc1        $f4, 0x1B4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x80009980: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80009984: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80009988: lwc1        $f18, 0xFC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XFC);
    // 0x8000998C: nop

    // 0x80009990: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80009994: swc1        $f10, 0xFC($t1)
    MEM_W(0XFC, ctx->r9) = ctx->f10.u32l;
    // 0x80009998: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000999C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800099A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800099A4: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800099A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800099AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800099B0: mul.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x800099B4: lwc1        $f8, 0x1A0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800099B8: nop

    // 0x800099BC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800099C0: sub.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d - ctx->f18.d;
    // 0x800099C4: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x800099C8: b           L_80009A28
    // 0x800099CC: swc1        $f16, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f16.u32l;
        goto L_80009A28;
    // 0x800099CC: swc1        $f16, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f16.u32l;
L_800099D0:
    // 0x800099D0: lwc1        $f6, 0x1A4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1A4);
    // 0x800099D4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800099D8: nop

    // 0x800099DC: swc1        $f6, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f6.u32l;
    // 0x800099E0: lwc1        $f8, 0x1A8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1A8);
    // 0x800099E4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800099E8: nop

    // 0x800099EC: swc1        $f8, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f8.u32l;
    // 0x800099F0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800099F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800099F8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800099FC: nop

    // 0x80009A00: swc1        $f10, 0xFC($t4)
    MEM_W(0XFC, ctx->r12) = ctx->f10.u32l;
    // 0x80009A04: lw          $t5, 0x34C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X34C);
    // 0x80009A08: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x80009A0C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009A10: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80009A14: sw          $t6, 0x34C($a0)
    MEM_W(0X34C, ctx->r4) = ctx->r14;
    // 0x80009A18: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80009A1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80009A20: nop

    // 0x80009A24: swc1        $f18, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f18.u32l;
L_80009A28:
    // 0x80009A28: b           L_80009C54
    // 0x80009A2C: nop

        goto L_80009C54;
    // 0x80009A2C: nop

L_80009A30:
    // 0x80009A30: lw          $t7, 0x34C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34C);
    // 0x80009A34: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80009A38: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80009A3C: beq         $t8, $zero, L_80009BB8
    if (ctx->r24 == 0) {
        // 0x80009A40: nop
    
            goto L_80009BB8;
    }
    // 0x80009A40: nop

    // 0x80009A44: lwc1        $f4, 0x1A0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009A48: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80009A4C: nop

    // 0x80009A50: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80009A54: nop

    // 0x80009A58: bc1f        L_80009B4C
    if (!c1cs) {
        // 0x80009A5C: nop
    
            goto L_80009B4C;
    }
    // 0x80009A5C: nop

    // 0x80009A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009A64: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009A68: lwc1        $f6, 0x1AC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1AC);
    // 0x80009A6C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80009A70: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80009A74: lwc1        $f18, 0xCC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x80009A78: nop

    // 0x80009A7C: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80009A80: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x80009A84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009A88: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009A8C: lwc1        $f16, 0x1B0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x80009A90: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009A94: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80009A98: lwc1        $f18, 0xD0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80009A9C: nop

    // 0x80009AA0: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80009AA4: swc1        $f10, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f10.u32l;
    // 0x80009AA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009AAC: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009AB0: lwc1        $f4, 0x1B8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1B8);
    // 0x80009AB4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80009AB8: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80009ABC: lwc1        $f18, 0xE8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XE8);
    // 0x80009AC0: nop

    // 0x80009AC4: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80009AC8: swc1        $f8, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f8.u32l;
    // 0x80009ACC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009AD0: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009AD4: lwc1        $f10, 0x1BC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1BC);
    // 0x80009AD8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80009ADC: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80009AE0: lwc1        $f18, 0xEC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XEC);
    // 0x80009AE4: nop

    // 0x80009AE8: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80009AEC: swc1        $f6, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f6.u32l;
    // 0x80009AF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009AF4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009AF8: lwc1        $f8, 0x1B4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x80009AFC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80009B00: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80009B04: lwc1        $f18, 0xFC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XFC);
    // 0x80009B08: nop

    // 0x80009B0C: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80009B10: swc1        $f16, 0xFC($t3)
    MEM_W(0XFC, ctx->r11) = ctx->f16.u32l;
    // 0x80009B14: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80009B18: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80009B1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009B20: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009B24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009B28: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80009B2C: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80009B30: lwc1        $f4, 0x1A0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009B34: nop

    // 0x80009B38: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80009B3C: sub.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f16.d - ctx->f18.d;
    // 0x80009B40: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80009B44: b           L_80009BB0
    // 0x80009B48: swc1        $f6, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f6.u32l;
        goto L_80009BB0;
    // 0x80009B48: swc1        $f6, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f6.u32l;
L_80009B4C:
    // 0x80009B4C: lwc1        $f10, 0x1A4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1A4);
    // 0x80009B50: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80009B54: nop

    // 0x80009B58: swc1        $f10, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f10.u32l;
    // 0x80009B5C: lwc1        $f4, 0x1A8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A8);
    // 0x80009B60: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80009B64: nop

    // 0x80009B68: swc1        $f4, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f4.u32l;
    // 0x80009B6C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80009B70: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80009B74: nop

    // 0x80009B78: swc1        $f16, 0xE8($t6)
    MEM_W(0XE8, ctx->r14) = ctx->f16.u32l;
    // 0x80009B7C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80009B80: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80009B84: nop

    // 0x80009B88: swc1        $f18, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f18.u32l;
    // 0x80009B8C: lw          $t8, 0x34C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34C);
    // 0x80009B90: lui         $at, 0xFFF7
    ctx->r1 = S32(0XFFF7 << 16);
    // 0x80009B94: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009B98: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80009B9C: sw          $t9, 0x34C($a0)
    MEM_W(0X34C, ctx->r4) = ctx->r25;
    // 0x80009BA0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80009BA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009BA8: nop

    // 0x80009BAC: swc1        $f8, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f8.u32l;
L_80009BB0:
    // 0x80009BB0: b           L_80009C54
    // 0x80009BB4: nop

        goto L_80009C54;
    // 0x80009BB4: nop

L_80009BB8:
    // 0x80009BB8: lwc1        $f6, 0x1A0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009BBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80009BC0: nop

    // 0x80009BC4: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80009BC8: nop

    // 0x80009BCC: bc1f        L_80009C0C
    if (!c1cs) {
        // 0x80009BD0: nop
    
            goto L_80009C0C;
    }
    // 0x80009BD0: nop

    // 0x80009BD4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80009BD8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80009BDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009BE0: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009BE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80009BE8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80009BEC: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80009BF0: lwc1        $f6, 0x1A0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009BF4: nop

    // 0x80009BF8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80009BFC: sub.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d - ctx->f8.d;
    // 0x80009C00: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80009C04: b           L_80009C54
    // 0x80009C08: swc1        $f4, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f4.u32l;
        goto L_80009C54;
    // 0x80009C08: swc1        $f4, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f4.u32l;
L_80009C0C:
    // 0x80009C0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009C10: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009C14: lwc1        $f18, 0x1B8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1B8);
    // 0x80009C18: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009C1C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80009C20: lwc1        $f8, 0xE8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x80009C24: nop

    // 0x80009C28: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80009C2C: swc1        $f16, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f16.u32l;
    // 0x80009C30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009C34: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009C38: lwc1        $f4, 0x1BC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1BC);
    // 0x80009C3C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80009C40: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80009C44: lwc1        $f8, 0xEC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XEC);
    // 0x80009C48: nop

    // 0x80009C4C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80009C50: swc1        $f10, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->f10.u32l;
L_80009C54:
    // 0x80009C54: b           L_80009C5C
    // 0x80009C58: nop

        goto L_80009C5C;
    // 0x80009C58: nop

L_80009C5C:
    // 0x80009C5C: jr          $ra
    // 0x80009C60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80009C60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void AudioDriver_LoadSequences(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B95D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B95D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B95D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B95DC: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B95E0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800B95E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B95E8: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B95EC: addiu       $a0, $a0, -0x398
    ctx->r4 = ADD32(ctx->r4, -0X398);
    // 0x800B95F0: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    // 0x800B95F4: jal         0x800C7950
    // 0x800B95F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800B95F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800B95FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9600: sw          $v0, -0x17E0($at)
    MEM_W(-0X17E0, ctx->r1) = ctx->r2;
    // 0x800B9604: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B9608: lw          $a1, -0x17E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17E0);
    // 0x800B960C: lui         $a0, 0x73
    ctx->r4 = S32(0X73 << 16);
    // 0x800B9610: addiu       $a0, $a0, 0xE80
    ctx->r4 = ADD32(ctx->r4, 0XE80);
    // 0x800B9614: jal         0x800BC590
    // 0x800B9618: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    AudioDmaCopy(rdram, ctx);
        goto after_1;
    // 0x800B9618: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800B961C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800B9620: lw          $t7, -0x17E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X17E0);
    // 0x800B9624: nop

    // 0x800B9628: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800B962C: nop

    // 0x800B9630: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B9634: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800B9638: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800B963C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B9640: lw          $t1, -0x17E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X17E0);
    // 0x800B9644: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9648: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x800B964C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9650: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800B9654: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x800B9658: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800B965C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9660: addiu       $a0, $a0, -0x388
    ctx->r4 = ADD32(ctx->r4, -0X388);
    // 0x800B9664: addiu       $a1, $zero, 0x9E
    ctx->r5 = ADD32(0, 0X9E);
    // 0x800B9668: jal         0x800C7950
    // 0x800B966C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800B966C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800B9670: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9674: sw          $v0, -0x17E0($at)
    MEM_W(-0X17E0, ctx->r1) = ctx->r2;
    // 0x800B9678: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800B967C: lw          $a1, -0x17E0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X17E0);
    // 0x800B9680: lui         $a0, 0x73
    ctx->r4 = S32(0X73 << 16);
    // 0x800B9684: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800B9688: jal         0x800BC590
    // 0x800B968C: addiu       $a0, $a0, 0xE80
    ctx->r4 = ADD32(ctx->r4, 0XE80);
    AudioDmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B968C: addiu       $a0, $a0, 0xE80
    ctx->r4 = ADD32(ctx->r4, 0XE80);
    after_3:
    // 0x800B9690: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9694: lw          $a0, -0x17E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17E0);
    // 0x800B9698: lui         $a1, 0x73
    ctx->r5 = S32(0X73 << 16);
    // 0x800B969C: jal         0x800C84E8
    // 0x800B96A0: addiu       $a1, $a1, 0xE80
    ctx->r5 = ADD32(ctx->r5, 0XE80);
    alSeqFileNew(rdram, ctx);
        goto after_4;
    // 0x800B96A0: addiu       $a1, $a1, 0xE80
    ctx->r5 = ADD32(ctx->r5, 0XE80);
    after_4:
    // 0x800B96A4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800B96A8: lw          $t5, -0x17E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X17E0);
    // 0x800B96AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B96B0: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x800B96B4: nop

    // 0x800B96B8: sw          $t6, -0x17D0($at)
    MEM_W(-0X17D0, ctx->r1) = ctx->r14;
    // 0x800B96BC: b           L_800B96C4
    // 0x800B96C0: nop

        goto L_800B96C4;
    // 0x800B96C0: nop

L_800B96C4:
    // 0x800B96C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B96C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B96CC: jr          $ra
    // 0x800B96D0: nop

    return;
    // 0x800B96D0: nop

;}
RECOMP_FUNC void func_80098894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098894: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009889C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800988A0: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x800988A4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800988A8: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800988AC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800988B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800988B4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800988B8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800988BC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800988C0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800988C4: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800988C8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800988CC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800988D0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800988D4: nop

    // 0x800988D8: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800988DC: lbu         $t1, 0x2E9($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2E9);
    // 0x800988E0: nop

    // 0x800988E4: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x800988E8: bne         $t2, $zero, L_800988F8
    if (ctx->r10 != 0) {
        // 0x800988EC: nop
    
            goto L_800988F8;
    }
    // 0x800988EC: nop

    // 0x800988F0: b           L_80098918
    // 0x800988F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80098918;
    // 0x800988F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800988F8:
    // 0x800988F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800988FC: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x80098900: jal         0x800972DC
    // 0x80098904: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    func_800972DC(rdram, ctx);
        goto after_0;
    // 0x80098904: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_0:
    // 0x80098908: b           L_80098918
    // 0x8009890C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80098918;
    // 0x8009890C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80098910: b           L_80098918
    // 0x80098914: nop

        goto L_80098918;
    // 0x80098914: nop

L_80098918:
    // 0x80098918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009891C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098920: jr          $ra
    // 0x80098924: nop

    return;
    // 0x80098924: nop

;}
RECOMP_FUNC void func_8006E188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E18C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E190: jal         0x80061348
    // 0x8006E194: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006E194: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006E198: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E19C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E1A0: beq         $v0, $zero, L_8006E1D8
    if (ctx->r2 == 0) {
        // 0x8006E1A4: nop
    
            goto L_8006E1D8;
    }
    // 0x8006E1A4: nop

    // 0x8006E1A8: jal         0x80061348
    // 0x8006E1AC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006E1AC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006E1B0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E1B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006E1B8: beq         $v0, $zero, L_8006E1D8
    if (ctx->r2 == 0) {
        // 0x8006E1BC: nop
    
            goto L_8006E1D8;
    }
    // 0x8006E1BC: nop

    // 0x8006E1C0: jal         0x80061348
    // 0x8006E1C4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006E1C4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_2:
    // 0x8006E1C8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E1CC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006E1D0: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E1D4: nop
    
            goto L_8006E518;
    }
    // 0x8006E1D4: nop

L_8006E1D8:
    // 0x8006E1D8: jal         0x80061348
    // 0x8006E1DC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006E1DC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_3:
    // 0x8006E1E0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E1E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006E1E8: beq         $v0, $zero, L_8006E220
    if (ctx->r2 == 0) {
        // 0x8006E1EC: nop
    
            goto L_8006E220;
    }
    // 0x8006E1EC: nop

    // 0x8006E1F0: jal         0x80061348
    // 0x8006E1F4: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_4;
    // 0x8006E1F4: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_4:
    // 0x8006E1F8: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E1FC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006E200: beq         $v0, $zero, L_8006E220
    if (ctx->r2 == 0) {
        // 0x8006E204: nop
    
            goto L_8006E220;
    }
    // 0x8006E204: nop

    // 0x8006E208: jal         0x80061348
    // 0x8006E20C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_5;
    // 0x8006E20C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_5:
    // 0x8006E210: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E214: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006E218: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E21C: nop
    
            goto L_8006E518;
    }
    // 0x8006E21C: nop

L_8006E220:
    // 0x8006E220: jal         0x80061348
    // 0x8006E224: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x8006E224: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_6:
    // 0x8006E228: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E22C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006E230: beq         $v0, $zero, L_8006E268
    if (ctx->r2 == 0) {
        // 0x8006E234: nop
    
            goto L_8006E268;
    }
    // 0x8006E234: nop

    // 0x8006E238: jal         0x80061348
    // 0x8006E23C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_7;
    // 0x8006E23C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_7:
    // 0x8006E240: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E244: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006E248: beq         $v0, $zero, L_8006E268
    if (ctx->r2 == 0) {
        // 0x8006E24C: nop
    
            goto L_8006E268;
    }
    // 0x8006E24C: nop

    // 0x8006E250: jal         0x80061348
    // 0x8006E254: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_8;
    // 0x8006E254: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_8:
    // 0x8006E258: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E25C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006E260: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E264: nop
    
            goto L_8006E518;
    }
    // 0x8006E264: nop

L_8006E268:
    // 0x8006E268: jal         0x80061348
    // 0x8006E26C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_9;
    // 0x8006E26C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_9:
    // 0x8006E270: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E274: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006E278: beq         $v0, $zero, L_8006E2B0
    if (ctx->r2 == 0) {
        // 0x8006E27C: nop
    
            goto L_8006E2B0;
    }
    // 0x8006E27C: nop

    // 0x8006E280: jal         0x80061348
    // 0x8006E284: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_10;
    // 0x8006E284: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_10:
    // 0x8006E288: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E28C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E290: beq         $v0, $zero, L_8006E2B0
    if (ctx->r2 == 0) {
        // 0x8006E294: nop
    
            goto L_8006E2B0;
    }
    // 0x8006E294: nop

    // 0x8006E298: jal         0x80061348
    // 0x8006E29C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_11;
    // 0x8006E29C: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_11:
    // 0x8006E2A0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E2A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006E2A8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E2AC: nop
    
            goto L_8006E518;
    }
    // 0x8006E2AC: nop

L_8006E2B0:
    // 0x8006E2B0: jal         0x80061348
    // 0x8006E2B4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_12;
    // 0x8006E2B4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_12:
    // 0x8006E2B8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E2BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006E2C0: beq         $v0, $zero, L_8006E2E0
    if (ctx->r2 == 0) {
        // 0x8006E2C4: nop
    
            goto L_8006E2E0;
    }
    // 0x8006E2C4: nop

    // 0x8006E2C8: jal         0x80061348
    // 0x8006E2CC: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_13;
    // 0x8006E2CC: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_13:
    // 0x8006E2D0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E2D4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006E2D8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E2DC: nop
    
            goto L_8006E518;
    }
    // 0x8006E2DC: nop

L_8006E2E0:
    // 0x8006E2E0: jal         0x80061348
    // 0x8006E2E4: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_14;
    // 0x8006E2E4: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_14:
    // 0x8006E2E8: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E2EC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006E2F0: beq         $v0, $zero, L_8006E310
    if (ctx->r2 == 0) {
        // 0x8006E2F4: nop
    
            goto L_8006E310;
    }
    // 0x8006E2F4: nop

    // 0x8006E2F8: jal         0x80061348
    // 0x8006E2FC: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_80061348(rdram, ctx);
        goto after_15;
    // 0x8006E2FC: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_15:
    // 0x8006E300: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E304: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006E308: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E30C: nop
    
            goto L_8006E518;
    }
    // 0x8006E30C: nop

L_8006E310:
    // 0x8006E310: jal         0x80061348
    // 0x8006E314: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_16;
    // 0x8006E314: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_16:
    // 0x8006E318: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E31C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006E320: beq         $v0, $zero, L_8006E340
    if (ctx->r2 == 0) {
        // 0x8006E324: nop
    
            goto L_8006E340;
    }
    // 0x8006E324: nop

    // 0x8006E328: jal         0x80061348
    // 0x8006E32C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_17;
    // 0x8006E32C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_17:
    // 0x8006E330: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E334: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006E338: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E33C: nop
    
            goto L_8006E518;
    }
    // 0x8006E33C: nop

L_8006E340:
    // 0x8006E340: jal         0x80061348
    // 0x8006E344: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_18;
    // 0x8006E344: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_18:
    // 0x8006E348: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E34C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006E350: beq         $v0, $zero, L_8006E370
    if (ctx->r2 == 0) {
        // 0x8006E354: nop
    
            goto L_8006E370;
    }
    // 0x8006E354: nop

    // 0x8006E358: jal         0x80061348
    // 0x8006E35C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_80061348(rdram, ctx);
        goto after_19;
    // 0x8006E35C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_19:
    // 0x8006E360: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E364: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006E368: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E36C: nop
    
            goto L_8006E518;
    }
    // 0x8006E36C: nop

L_8006E370:
    // 0x8006E370: jal         0x80061348
    // 0x8006E374: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_20;
    // 0x8006E374: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_20:
    // 0x8006E378: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E37C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E380: beq         $v0, $zero, L_8006E3A0
    if (ctx->r2 == 0) {
        // 0x8006E384: nop
    
            goto L_8006E3A0;
    }
    // 0x8006E384: nop

    // 0x8006E388: jal         0x80061348
    // 0x8006E38C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_21;
    // 0x8006E38C: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_21:
    // 0x8006E390: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E394: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006E398: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E39C: nop
    
            goto L_8006E518;
    }
    // 0x8006E39C: nop

L_8006E3A0:
    // 0x8006E3A0: jal         0x80061348
    // 0x8006E3A4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_22;
    // 0x8006E3A4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_22:
    // 0x8006E3A8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E3AC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006E3B0: beq         $v0, $zero, L_8006E3D0
    if (ctx->r2 == 0) {
        // 0x8006E3B4: nop
    
            goto L_8006E3D0;
    }
    // 0x8006E3B4: nop

    // 0x8006E3B8: jal         0x80061348
    // 0x8006E3BC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_80061348(rdram, ctx);
        goto after_23;
    // 0x8006E3BC: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_23:
    // 0x8006E3C0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E3C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006E3C8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E3CC: nop
    
            goto L_8006E518;
    }
    // 0x8006E3CC: nop

L_8006E3D0:
    // 0x8006E3D0: jal         0x80061348
    // 0x8006E3D4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_24;
    // 0x8006E3D4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_24:
    // 0x8006E3D8: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E3DC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006E3E0: beq         $v0, $zero, L_8006E400
    if (ctx->r2 == 0) {
        // 0x8006E3E4: nop
    
            goto L_8006E400;
    }
    // 0x8006E3E4: nop

    // 0x8006E3E8: jal         0x80061348
    // 0x8006E3EC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_25;
    // 0x8006E3EC: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_25:
    // 0x8006E3F0: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E3F4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006E3F8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E3FC: nop
    
            goto L_8006E518;
    }
    // 0x8006E3FC: nop

L_8006E400:
    // 0x8006E400: jal         0x80061348
    // 0x8006E404: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_26;
    // 0x8006E404: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_26:
    // 0x8006E408: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E40C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006E410: beq         $v0, $zero, L_8006E430
    if (ctx->r2 == 0) {
        // 0x8006E414: nop
    
            goto L_8006E430;
    }
    // 0x8006E414: nop

    // 0x8006E418: jal         0x80061348
    // 0x8006E41C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_27;
    // 0x8006E41C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_27:
    // 0x8006E420: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E424: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8006E428: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E42C: nop
    
            goto L_8006E518;
    }
    // 0x8006E42C: nop

L_8006E430:
    // 0x8006E430: jal         0x80061348
    // 0x8006E434: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_28;
    // 0x8006E434: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_28:
    // 0x8006E438: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E43C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8006E440: beq         $v0, $zero, L_8006E460
    if (ctx->r2 == 0) {
        // 0x8006E444: nop
    
            goto L_8006E460;
    }
    // 0x8006E444: nop

    // 0x8006E448: jal         0x80061348
    // 0x8006E44C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_29;
    // 0x8006E44C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_29:
    // 0x8006E450: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E454: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8006E458: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E45C: nop
    
            goto L_8006E518;
    }
    // 0x8006E45C: nop

L_8006E460:
    // 0x8006E460: jal         0x80061348
    // 0x8006E464: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_30;
    // 0x8006E464: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_30:
    // 0x8006E468: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E46C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E470: beq         $v0, $zero, L_8006E490
    if (ctx->r2 == 0) {
        // 0x8006E474: nop
    
            goto L_8006E490;
    }
    // 0x8006E474: nop

    // 0x8006E478: jal         0x80061348
    // 0x8006E47C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_31;
    // 0x8006E47C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_31:
    // 0x8006E480: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E484: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006E488: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E48C: nop
    
            goto L_8006E518;
    }
    // 0x8006E48C: nop

L_8006E490:
    // 0x8006E490: jal         0x80061348
    // 0x8006E494: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_32;
    // 0x8006E494: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_32:
    // 0x8006E498: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E49C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006E4A0: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E4A4: nop
    
            goto L_8006E518;
    }
    // 0x8006E4A4: nop

    // 0x8006E4A8: jal         0x80061348
    // 0x8006E4AC: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_33;
    // 0x8006E4AC: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_33:
    // 0x8006E4B0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E4B4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006E4B8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E4BC: nop
    
            goto L_8006E518;
    }
    // 0x8006E4BC: nop

    // 0x8006E4C0: jal         0x80061348
    // 0x8006E4C4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_34;
    // 0x8006E4C4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_34:
    // 0x8006E4C8: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E4CC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8006E4D0: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E4D4: nop
    
            goto L_8006E518;
    }
    // 0x8006E4D4: nop

    // 0x8006E4D8: jal         0x80061348
    // 0x8006E4DC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_35;
    // 0x8006E4DC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_35:
    // 0x8006E4E0: sltiu       $t1, $v0, 0x1
    ctx->r9 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E4E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8006E4E8: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E4EC: nop
    
            goto L_8006E518;
    }
    // 0x8006E4EC: nop

    // 0x8006E4F0: jal         0x80061348
    // 0x8006E4F4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_36;
    // 0x8006E4F4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_36:
    // 0x8006E4F8: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E4FC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8006E500: bne         $v0, $zero, L_8006E518
    if (ctx->r2 != 0) {
        // 0x8006E504: nop
    
            goto L_8006E518;
    }
    // 0x8006E504: nop

    // 0x8006E508: jal         0x80061348
    // 0x8006E50C: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_37;
    // 0x8006E50C: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_37:
    // 0x8006E510: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006E514: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_8006E518:
    // 0x8006E518: b           L_8006E528
    // 0x8006E51C: nop

        goto L_8006E528;
    // 0x8006E51C: nop

    // 0x8006E520: b           L_8006E528
    // 0x8006E524: nop

        goto L_8006E528;
    // 0x8006E524: nop

L_8006E528:
    // 0x8006E528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E52C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E530: jr          $ra
    // 0x8006E534: nop

    return;
    // 0x8006E534: nop

;}
RECOMP_FUNC void func_800727FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800727FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072804: jal         0x80061348
    // 0x80072808: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80072808: addiu       $a0, $zero, 0x50E
    ctx->r4 = ADD32(0, 0X50E);
    after_0:
    // 0x8007280C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80072810: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80072814: b           L_80072824
    // 0x80072818: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072824;
    // 0x80072818: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007281C: b           L_80072824
    // 0x80072820: nop

        goto L_80072824;
    // 0x80072820: nop

L_80072824:
    // 0x80072824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007282C: jr          $ra
    // 0x80072830: nop

    return;
    // 0x80072830: nop

;}
RECOMP_FUNC void func_8008606C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008606C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80086070: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80086074: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80086078: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8008607C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80086080: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80086084: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80086088: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8008608C: lhu         $t9, 0x46($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X46);
    // 0x80086090: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80086094: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80086098: beq         $t0, $zero, L_80086254
    if (ctx->r8 == 0) {
        // 0x8008609C: nop
    
            goto L_80086254;
    }
    // 0x8008609C: nop

    // 0x800860A0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800860A4: jal         0x8008A518
    // 0x800860A8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x800860A8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800860AC: beq         $v0, $zero, L_80086254
    if (ctx->r2 == 0) {
        // 0x800860B0: nop
    
            goto L_80086254;
    }
    // 0x800860B0: nop

    // 0x800860B4: lhu         $t1, 0x34($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X34);
    // 0x800860B8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x800860BC: bne         $t1, $at, L_800860D4
    if (ctx->r9 != ctx->r1) {
        // 0x800860C0: nop
    
            goto L_800860D4;
    }
    // 0x800860C0: nop

    // 0x800860C4: jal         0x8008CE48
    // 0x800860C8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x800860C8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x800860CC: b           L_80086290
    // 0x800860D0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086290;
    // 0x800860D0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_800860D4:
    // 0x800860D4: lhu         $t2, 0x34($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X34);
    // 0x800860D8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800860DC: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800860E0: bne         $at, $zero, L_80086254
    if (ctx->r1 != 0) {
        // 0x800860E4: nop
    
            goto L_80086254;
    }
    // 0x800860E4: nop

    // 0x800860E8: ori         $at, $zero, 0x8003
    ctx->r1 = 0 | 0X8003;
    // 0x800860EC: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800860F0: beq         $at, $zero, L_80086254
    if (ctx->r1 == 0) {
        // 0x800860F4: nop
    
            goto L_80086254;
    }
    // 0x800860F4: nop

    // 0x800860F8: lhu         $t3, 0x34($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X34);
    // 0x800860FC: lui         $at, 0xFFF5
    ctx->r1 = S32(0XFFF5 << 16);
    // 0x80086100: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80086104: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80086108: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008610C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80086110: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80086114: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80086118: addiu       $t6, $t6, 0x7AE8
    ctx->r14 = ADD32(ctx->r14, 0X7AE8);
    // 0x8008611C: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80086120: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80086124: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80086128: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8008612C: nop

    // 0x80086130: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x80086134: nop

    // 0x80086138: andi        $t0, $t8, 0x8000
    ctx->r8 = ctx->r24 & 0X8000;
    // 0x8008613C: beq         $t0, $zero, L_80086240
    if (ctx->r8 == 0) {
        // 0x80086140: nop
    
            goto L_80086240;
    }
    // 0x80086140: nop

    // 0x80086144: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80086148: nop

    // 0x8008614C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80086150: nop

    // 0x80086154: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x80086158: beq         $t3, $zero, L_80086224
    if (ctx->r11 == 0) {
        // 0x8008615C: nop
    
            goto L_80086224;
    }
    // 0x8008615C: nop

    // 0x80086160: jal         0x8008CE48
    // 0x80086164: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80086164: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_2:
    // 0x80086168: lhu         $t4, 0x34($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X34);
    // 0x8008616C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80086170: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80086174: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80086178: sh          $t5, 0xBE8($t6)
    MEM_H(0XBE8, ctx->r14) = ctx->r13;
    // 0x8008617C: lh          $t7, 0x3C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3C);
    // 0x80086180: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80086184: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x80086188: lh          $a2, 0x38($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X38);
    // 0x8008618C: lh          $a3, 0x3A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X3A);
    // 0x80086190: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80086194: jal         0x8008A368
    // 0x80086198: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8008A368(rdram, ctx);
        goto after_3;
    // 0x80086198: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8008619C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800861A0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800861A4: jal         0x800898D8
    // 0x800861A8: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    func_800898D8(rdram, ctx);
        goto after_4;
    // 0x800861A8: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    after_4:
    // 0x800861AC: beq         $v0, $zero, L_800861FC
    if (ctx->r2 == 0) {
        // 0x800861B0: nop
    
            goto L_800861FC;
    }
    // 0x800861B0: nop

    // 0x800861B4: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x800861B8: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x800861BC: lh          $t1, 0x2C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2C);
    // 0x800861C0: lh          $t2, 0x30($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X30);
    // 0x800861C4: addu        $a1, $t9, $t8
    ctx->r5 = ADD32(ctx->r25, ctx->r24);
    // 0x800861C8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    // 0x800861CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800861D0: bgez        $a1, L_800861E0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800861D4: sra         $t0, $a1, 1
        ctx->r8 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800861E0;
    }
    // 0x800861D4: sra         $t0, $a1, 1
    ctx->r8 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800861D8: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
    // 0x800861DC: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_800861E0:
    // 0x800861E0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800861E4: bgez        $a2, L_800861F4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800861E8: sra         $t3, $a2, 1
        ctx->r11 = S32(SIGNED(ctx->r6) >> 1);
            goto L_800861F4;
    }
    // 0x800861E8: sra         $t3, $a2, 1
    ctx->r11 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800861EC: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x800861F0: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800861F4:
    // 0x800861F4: jal         0x80089B04
    // 0x800861F8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    func_80089B04(rdram, ctx);
        goto after_5;
    // 0x800861F8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_5:
L_800861FC:
    // 0x800861FC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80086200: nop

    // 0x80086204: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80086208: nop

    // 0x8008620C: ori         $t6, $t5, 0x200
    ctx->r14 = ctx->r13 | 0X200;
    // 0x80086210: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x80086214: b           L_80086290
    // 0x80086218: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_80086290;
    // 0x80086218: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8008621C: b           L_80086238
    // 0x80086220: nop

        goto L_80086238;
    // 0x80086220: nop

L_80086224:
    // 0x80086224: jal         0x8008CE48
    // 0x80086228: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_6;
    // 0x80086228: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_6:
    // 0x8008622C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80086230: jal         0x8008A730
    // 0x80086234: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_8008A730(rdram, ctx);
        goto after_7;
    // 0x80086234: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_7:
L_80086238:
    // 0x80086238: b           L_80086254
    // 0x8008623C: nop

        goto L_80086254;
    // 0x8008623C: nop

L_80086240:
    // 0x80086240: jal         0x8008CE48
    // 0x80086244: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8008CE48(rdram, ctx);
        goto after_8;
    // 0x80086244: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_8:
    // 0x80086248: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8008624C: jal         0x8008A730
    // 0x80086250: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_8008A730(rdram, ctx);
        goto after_9;
    // 0x80086250: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_9:
L_80086254:
    // 0x80086254: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80086258: lhu         $t9, 0x101C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X101C);
    // 0x8008625C: lhu         $t7, 0x46($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X46);
    // 0x80086260: nop

    // 0x80086264: and         $t8, $t7, $t9
    ctx->r24 = ctx->r15 & ctx->r25;
    // 0x80086268: beq         $t8, $zero, L_80086280
    if (ctx->r24 == 0) {
        // 0x8008626C: nop
    
            goto L_80086280;
    }
    // 0x8008626C: nop

    // 0x80086270: jal         0x8008CE48
    // 0x80086274: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_8008CE48(rdram, ctx);
        goto after_10;
    // 0x80086274: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_10:
    // 0x80086278: b           L_80086290
    // 0x8008627C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80086290;
    // 0x8008627C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80086280:
    // 0x80086280: b           L_80086290
    // 0x80086284: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_80086290;
    // 0x80086284: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80086288: b           L_80086290
    // 0x8008628C: nop

        goto L_80086290;
    // 0x8008628C: nop

L_80086290:
    // 0x80086290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80086294: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80086298: jr          $ra
    // 0x8008629C: nop

    return;
    // 0x8008629C: nop

;}
RECOMP_FUNC void func_800C2070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2070: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C2074: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C2078: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C207C: nop

    // 0x800C2080: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C2084: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800C2088: nop

    // 0x800C208C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800C2090: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C2094: nop

    // 0x800C2098: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800C209C: nop

    // 0x800C20A0: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800C20A4: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C20A8: nop

    // 0x800C20AC: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800C20B0: nop

    // 0x800C20B4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800C20B8: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C20BC: nop

    // 0x800C20C0: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800C20C4: nop

    // 0x800C20C8: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800C20CC: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C20D0: nop

    // 0x800C20D4: lwc1        $f16, 0x14($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800C20D8: nop

    // 0x800C20DC: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x800C20E0: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800C20E4: nop

    // 0x800C20E8: lwc1        $f18, 0x18($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X18);
    // 0x800C20EC: nop

    // 0x800C20F0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x800C20F4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C20F8: nop

    // 0x800C20FC: lwc1        $f4, 0x20($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X20);
    // 0x800C2100: nop

    // 0x800C2104: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800C2108: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C210C: nop

    // 0x800C2110: lwc1        $f6, 0x24($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X24);
    // 0x800C2114: nop

    // 0x800C2118: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800C211C: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C2120: nop

    // 0x800C2124: lwc1        $f8, 0x28($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X28);
    // 0x800C2128: nop

    // 0x800C212C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800C2130: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C2134: nop

    // 0x800C2138: lwc1        $f10, 0x30($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X30);
    // 0x800C213C: nop

    // 0x800C2140: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800C2144: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C2148: nop

    // 0x800C214C: lwc1        $f16, 0x34($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X34);
    // 0x800C2150: nop

    // 0x800C2154: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800C2158: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C215C: nop

    // 0x800C2160: lwc1        $f18, 0x38($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X38);
    // 0x800C2164: nop

    // 0x800C2168: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800C216C: sw          $a0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r4;
    // 0x800C2170: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C2174: lw          $t8, 0xCE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE4);
    // 0x800C2178: nop

    // 0x800C217C: addiu       $t9, $t8, -0x40
    ctx->r25 = ADD32(ctx->r24, -0X40);
    // 0x800C2180: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C2184: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_800C2188:
    // 0x800C2188: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800C218C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C2190: lwc1        $f14, 0x10($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800C2194: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2198: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800C219C: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C21A0: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C21A4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x800C21A8: lwc1        $f4, 0x20($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X20);
    // 0x800C21AC: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800C21B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C21B4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800C21B8: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800C21BC: nop

    // 0x800C21C0: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800C21C4: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800C21C8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800C21CC: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x800C21D0: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C21D4: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C21D8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C21DC: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800C21E0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C21E4: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C21E8: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C21EC: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C21F0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C21F4: nop

    // 0x800C21F8: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800C21FC: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800C2200: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800C2204: swc1        $f4, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f4.u32l;
    // 0x800C2208: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C220C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C2210: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C2214: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C2218: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C221C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2220: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C2224: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800C2228: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C222C: nop

    // 0x800C2230: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C2234: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800C2238: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800C223C: swc1        $f8, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f8.u32l;
    // 0x800C2240: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C2244: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C2248: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C224C: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800C2250: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C2254: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C2258: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x800C225C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800C2260: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C2264: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C2268: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800C226C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C2270: lwc1        $f8, 0x30($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X30);
    // 0x800C2274: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C2278: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800C227C: swc1        $f16, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f16.u32l;
    // 0x800C2280: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C2284: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C2288: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800C228C: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800C2290: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800C2294: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800C2298: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C229C: nop

    // 0x800C22A0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C22A4: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x800C22A8: bne         $at, $zero, L_800C2188
    if (ctx->r1 != 0) {
        // 0x800C22AC: sw          $t1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r9;
            goto L_800C2188;
    }
    // 0x800C22AC: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800C22B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C22B4: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C22B8: nop

    // 0x800C22BC: swc1        $f10, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f10.u32l;
    // 0x800C22C0: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800C22C4: nop

    // 0x800C22C8: lwc1        $f12, 0x20($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X20);
    // 0x800C22CC: nop

    // 0x800C22D0: swc1        $f12, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f12.u32l;
    // 0x800C22D4: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C22D8: nop

    // 0x800C22DC: swc1        $f12, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f12.u32l;
    // 0x800C22E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C22E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C22E8: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800C22EC: nop

    // 0x800C22F0: swc1        $f4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f4.u32l;
    // 0x800C22F4: b           L_800C22FC
    // 0x800C22F8: nop

        goto L_800C22FC;
    // 0x800C22F8: nop

L_800C22FC:
    // 0x800C22FC: jr          $ra
    // 0x800C2300: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C2300: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80065E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065E60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065E64: jal         0x80061488
    // 0x80065E68: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065E68: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_0:
    // 0x80065E6C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065E70: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065E74: b           L_80065E84
    // 0x80065E78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065E84;
    // 0x80065E78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065E7C: b           L_80065E84
    // 0x80065E80: nop

        goto L_80065E84;
    // 0x80065E80: nop

L_80065E84:
    // 0x80065E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065E88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065E8C: jr          $ra
    // 0x80065E90: nop

    return;
    // 0x80065E90: nop

;}
RECOMP_FUNC void func_80066054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066054: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066058: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006605C: nop

    // 0x80066060: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80066064: nop

    // 0x80066068: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006606C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80066070: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066074: beq         $v0, $zero, L_8006608C
    if (ctx->r2 == 0) {
        // 0x80066078: nop
    
            goto L_8006608C;
    }
    // 0x80066078: nop

    // 0x8006607C: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80066080: nop

    // 0x80066084: slti        $t8, $v0, 0x259
    ctx->r24 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
    // 0x80066088: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006608C:
    // 0x8006608C: jr          $ra
    // 0x80066090: nop

    return;
    // 0x80066090: nop

    // 0x80066094: jr          $ra
    // 0x80066098: nop

    return;
    // 0x80066098: nop

    // 0x8006609C: jr          $ra
    // 0x800660A0: nop

    return;
    // 0x800660A0: nop

;}
RECOMP_FUNC void func_8008BC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008BC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BC78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008BC7C: jal         0x80090754
    // 0x8008BC80: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090754(rdram, ctx);
        goto after_0;
    // 0x8008BC80: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x8008BC84: jal         0x80090728
    // 0x8008BC88: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090728(rdram, ctx);
        goto after_1;
    // 0x8008BC88: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x8008BC8C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008BC90: nop

    // 0x8008BC94: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8008BC98: nop

    // 0x8008BC9C: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x8008BCA0: beq         $t8, $zero, L_8008BCB4
    if (ctx->r24 == 0) {
        // 0x8008BCA4: nop
    
            goto L_8008BCB4;
    }
    // 0x8008BCA4: nop

    // 0x8008BCA8: addiu       $t9, $zero, 0x57
    ctx->r25 = ADD32(0, 0X57);
    // 0x8008BCAC: b           L_8008BCB8
    // 0x8008BCB0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_8008BCB8;
    // 0x8008BCB0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8008BCB4:
    // 0x8008BCB4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8008BCB8:
    // 0x8008BCB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008BCBC: addiu       $a0, $a0, -0xA84
    ctx->r4 = ADD32(ctx->r4, -0XA84);
    // 0x8008BCC0: jal         0x8008ECE4
    // 0x8008BCC4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8008BCC4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // 0x8008BCC8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8008BCCC:
    // 0x8008BCCC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8008BCD0:
    // 0x8008BCD0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008BCD4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8008BCD8: bne         $t0, $at, L_8008BCFC
    if (ctx->r8 != ctx->r1) {
        // 0x8008BCDC: nop
    
            goto L_8008BCFC;
    }
    // 0x8008BCDC: nop

    // 0x8008BCE0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8008BCE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008BCE8: beq         $t1, $at, L_8008BD1C
    if (ctx->r9 == ctx->r1) {
        // 0x8008BCEC: nop
    
            goto L_8008BD1C;
    }
    // 0x8008BCEC: nop

    // 0x8008BCF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008BCF4: beq         $t1, $at, L_8008BD1C
    if (ctx->r9 == ctx->r1) {
        // 0x8008BCF8: nop
    
            goto L_8008BD1C;
    }
    // 0x8008BCF8: nop

L_8008BCFC:
    // 0x8008BCFC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008BD00: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8008BD04: bne         $t2, $at, L_8008BD24
    if (ctx->r10 != ctx->r1) {
        // 0x8008BD08: nop
    
            goto L_8008BD24;
    }
    // 0x8008BD08: nop

    // 0x8008BD0C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8008BD10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008BD14: bne         $t3, $at, L_8008BD24
    if (ctx->r11 != ctx->r1) {
        // 0x8008BD18: nop
    
            goto L_8008BD24;
    }
    // 0x8008BD18: nop

L_8008BD1C:
    // 0x8008BD1C: b           L_8008BDC4
    // 0x8008BD20: nop

        goto L_8008BDC4;
    // 0x8008BD20: nop

L_8008BD24:
    // 0x8008BD24: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8008BD28: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BD2C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8008BD30: addiu       $t6, $t5, 0x6
    ctx->r14 = ADD32(ctx->r13, 0X6);
    // 0x8008BD34: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x8008BD38: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008BD3C: nop

    // 0x8008BD40: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x8008BD44: bne         $at, $zero, L_8008BD60
    if (ctx->r1 != 0) {
        // 0x8008BD48: nop
    
            goto L_8008BD60;
    }
    // 0x8008BD48: nop

    // 0x8008BD4C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8008BD50: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x8008BD54: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BD58: addiu       $t9, $t8, 0x56
    ctx->r25 = ADD32(ctx->r24, 0X56);
    // 0x8008BD5C: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
L_8008BD60:
    // 0x8008BD60: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008BD64: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8008BD68: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x8008BD6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8008BD70: mfhi        $t1
    ctx->r9 = hi;
    // 0x8008BD74: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8008BD78: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8008BD7C: addiu       $t3, $t2, 0x5
    ctx->r11 = ADD32(ctx->r10, 0X5);
    // 0x8008BD80: sw          $t3, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r11;
    // 0x8008BD84: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BD88: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008BD8C: addiu       $t6, $t6, 0x4930
    ctx->r14 = ADD32(ctx->r14, 0X4930);
    // 0x8008BD90: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008BD94: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8008BD98: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8008BD9C: jal         0x800BCFCC
    // 0x8008BDA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x8008BDA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x8008BDA4: addiu       $t7, $sp, 0x18
    ctx->r15 = ADD32(ctx->r29, 0X18);
    // 0x8008BDA8: sb          $zero, 0x2($t7)
    MEM_B(0X2, ctx->r15) = 0;
    // 0x8008BDAC: jal         0x8008ECE4
    // 0x8008BDB0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8008BDB0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x8008BDB4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BDB8: nop

    // 0x8008BDBC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008BDC0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8008BDC4:
    // 0x8008BDC4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8008BDC8: nop

    // 0x8008BDCC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008BDD0: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8008BDD4: bne         $at, $zero, L_8008BCD0
    if (ctx->r1 != 0) {
        // 0x8008BDD8: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_8008BCD0;
    }
    // 0x8008BDD8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8008BDDC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008BDE0: nop

    // 0x8008BDE4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008BDE8: slti        $at, $t3, 0x12
    ctx->r1 = SIGNED(ctx->r11) < 0X12 ? 1 : 0;
    // 0x8008BDEC: bne         $at, $zero, L_8008BCCC
    if (ctx->r1 != 0) {
        // 0x8008BDF0: sw          $t3, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r11;
            goto L_8008BCCC;
    }
    // 0x8008BDF0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8008BDF4: b           L_8008BDFC
    // 0x8008BDF8: nop

        goto L_8008BDFC;
    // 0x8008BDF8: nop

L_8008BDFC:
    // 0x8008BDFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BE00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008BE04: jr          $ra
    // 0x8008BE08: nop

    return;
    // 0x8008BE08: nop

;}
RECOMP_FUNC void func_800A6514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6514: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A6518: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A651C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A6520: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A6524: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A6528: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A652C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A6530: jal         0x80099E2C
    // 0x800A6534: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x800A6534: nop

    after_0:
    // 0x800A6538: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800A653C: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A6540: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800A6544: nop

    // 0x800A6548: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800A654C: sw          $t8, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r24;
    // 0x800A6550: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A6554: nop

    // 0x800A6558: sw          $zero, 0x128($t9)
    MEM_W(0X128, ctx->r25) = 0;
    // 0x800A655C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A6560: nop

    // 0x800A6564: sw          $zero, 0x138($t0)
    MEM_W(0X138, ctx->r8) = 0;
    // 0x800A6568: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A656C: nop

    // 0x800A6570: sw          $zero, 0x13C($t1)
    MEM_W(0X13C, ctx->r9) = 0;
    // 0x800A6574: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A6578: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A657C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A6580: nop

    // 0x800A6584: swc1        $f4, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f4.u32l;
    // 0x800A6588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A658C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6590: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800A6594: nop

    // 0x800A6598: swc1        $f6, 0xF8($t3)
    MEM_W(0XF8, ctx->r11) = ctx->f6.u32l;
    // 0x800A659C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A65A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A65A4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A65A8: nop

    // 0x800A65AC: swc1        $f8, 0xFC($t4)
    MEM_W(0XFC, ctx->r12) = ctx->f8.u32l;
    // 0x800A65B0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A65B4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A65B8: sh          $t5, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r13;
    // 0x800A65BC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800A65C0: nop

    // 0x800A65C4: sh          $zero, 0x11C($t8)
    MEM_H(0X11C, ctx->r24) = 0;
    // 0x800A65C8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800A65CC: nop

    // 0x800A65D0: lh          $s0, 0x11C($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X11C);
    // 0x800A65D4: nop

    // 0x800A65D8: sh          $s0, 0x11A($t6)
    MEM_H(0X11A, ctx->r14) = ctx->r16;
    // 0x800A65DC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A65E0: nop

    // 0x800A65E4: sh          $s0, 0x118($t9)
    MEM_H(0X118, ctx->r25) = ctx->r16;
    // 0x800A65E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A65EC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A65F0: nop

    // 0x800A65F4: swc1        $f10, 0xD4($t0)
    MEM_W(0XD4, ctx->r8) = ctx->f10.u32l;
    // 0x800A65F8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A65FC: nop

    // 0x800A6600: lwc1        $f20, 0xD4($t1)
    ctx->f20.u32l = MEM_W(ctx->r9, 0XD4);
    // 0x800A6604: nop

    // 0x800A6608: swc1        $f20, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f20.u32l;
    // 0x800A660C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A6610: nop

    // 0x800A6614: swc1        $f20, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f20.u32l;
    // 0x800A6618: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A661C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800A6620: nop

    // 0x800A6624: swc1        $f16, 0xF0($t3)
    MEM_W(0XF0, ctx->r11) = ctx->f16.u32l;
    // 0x800A6628: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A662C: nop

    // 0x800A6630: lwc1        $f20, 0xF0($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x800A6634: nop

    // 0x800A6638: swc1        $f20, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f20.u32l;
    // 0x800A663C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800A6640: nop

    // 0x800A6644: swc1        $f20, 0xE8($t5)
    MEM_W(0XE8, ctx->r13) = ctx->f20.u32l;
    // 0x800A6648: b           L_800A6658
    // 0x800A664C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A6658;
    // 0x800A664C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A6650: b           L_800A6658
    // 0x800A6654: nop

        goto L_800A6658;
    // 0x800A6654: nop

L_800A6658:
    // 0x800A6658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A665C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A6660: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A6664: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A6668: jr          $ra
    // 0x800A666C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A666C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006361C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006361C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063620: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063624: nop

    // 0x80063628: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006362C: nop

    // 0x80063630: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80063634: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063638: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006363C: beq         $v0, $zero, L_80063658
    if (ctx->r2 == 0) {
        // 0x80063640: nop
    
            goto L_80063658;
    }
    // 0x80063640: nop

    // 0x80063644: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x80063648: nop

    // 0x8006364C: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80063650: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80063654: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80063658:
    // 0x80063658: jr          $ra
    // 0x8006365C: nop

    return;
    // 0x8006365C: nop

    // 0x80063660: jr          $ra
    // 0x80063664: nop

    return;
    // 0x80063664: nop

    // 0x80063668: jr          $ra
    // 0x8006366C: nop

    return;
    // 0x8006366C: nop

;}
RECOMP_FUNC void func_80099F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099F90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099F94: swc1        $f12, 0x7224($at)
    MEM_W(0X7224, ctx->r1) = ctx->f12.u32l;
    // 0x80099F98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099F9C: swc1        $f14, 0x7230($at)
    MEM_W(0X7230, ctx->r1) = ctx->f14.u32l;
    // 0x80099FA0: jr          $ra
    // 0x80099FA4: nop

    return;
    // 0x80099FA4: nop

    // 0x80099FA8: jr          $ra
    // 0x80099FAC: nop

    return;
    // 0x80099FAC: nop

;}
RECOMP_FUNC void func_800168B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800168B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800168B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800168BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800168C0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800168C4: nop

    // 0x800168C8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800168CC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800168D0: nop

    // 0x800168D4: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x800168D8: nop

    // 0x800168DC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800168E0: beq         $t9, $zero, L_80016A38
    if (ctx->r25 == 0) {
        // 0x800168E4: nop
    
            goto L_80016A38;
    }
    // 0x800168E4: nop

    // 0x800168E8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800168EC: nop

    // 0x800168F0: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x800168F4: nop

    // 0x800168F8: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x800168FC: beq         $t2, $zero, L_8001690C
    if (ctx->r10 == 0) {
        // 0x80016900: nop
    
            goto L_8001690C;
    }
    // 0x80016900: nop

    // 0x80016904: b           L_80016A30
    // 0x80016908: nop

        goto L_80016A30;
    // 0x80016908: nop

L_8001690C:
    // 0x8001690C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80016910: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80016914: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80016918: lwc1        $f4, 0x1EC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X1EC);
    // 0x8001691C: lwc1        $f10, 0x1E8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X1E8);
    // 0x80016920: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80016924: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80016928: swc1        $f16, 0x1E8($t3)
    MEM_W(0X1E8, ctx->r11) = ctx->f16.u32l;
    // 0x8001692C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80016930: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80016934: lwc1        $f18, 0x1E8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X1E8);
    // 0x80016938: nop

    // 0x8001693C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80016940: nop

    // 0x80016944: bc1f        L_800169A0
    if (!c1cs) {
        // 0x80016948: nop
    
            goto L_800169A0;
    }
    // 0x80016948: nop

    // 0x8001694C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80016950: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016954: nop

    // 0x80016958: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8001695C: nop

    // 0x80016960: bc1f        L_800169A0
    if (!c1cs) {
        // 0x80016964: nop
    
            goto L_800169A0;
    }
    // 0x80016964: nop

    // 0x80016968: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001696C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80016970: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80016974: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80016978: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001697C: lwc1        $f10, 0x1E8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X1E8);
    // 0x80016980: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016984: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80016988: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001698C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80016990: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80016994: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x80016998: b           L_80016A30
    // 0x8001699C: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
        goto L_80016A30;
    // 0x8001699C: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
L_800169A0:
    // 0x800169A0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800169A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800169A8: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x800169AC: nop

    // 0x800169B0: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800169B4: sw          $t3, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r11;
    // 0x800169B8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800169BC: nop

    // 0x800169C0: lw          $t5, 0x1A8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A8);
    // 0x800169C4: nop

    // 0x800169C8: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x800169CC: sw          $t6, 0x1A8($t4)
    MEM_W(0X1A8, ctx->r12) = ctx->r14;
    // 0x800169D0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800169D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800169D8: lwc1        $f16, 0x1EC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1EC);
    // 0x800169DC: nop

    // 0x800169E0: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800169E4: nop

    // 0x800169E8: bc1f        L_80016A10
    if (!c1cs) {
        // 0x800169EC: nop
    
            goto L_80016A10;
    }
    // 0x800169EC: nop

    // 0x800169F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800169F4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800169F8: nop

    // 0x800169FC: swc1        $f18, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f18.u32l;
    // 0x80016A00: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016A04: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80016A08: b           L_80016A30
    // 0x80016A0C: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
        goto L_80016A30;
    // 0x80016A0C: sh          $t9, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r25;
L_80016A10:
    // 0x80016A10: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80016A14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016A18: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80016A1C: nop

    // 0x80016A20: swc1        $f6, 0x1E8($t2)
    MEM_W(0X1E8, ctx->r10) = ctx->f6.u32l;
    // 0x80016A24: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80016A28: nop

    // 0x80016A2C: sh          $zero, 0x11E($t3)
    MEM_H(0X11E, ctx->r11) = 0;
L_80016A30:
    // 0x80016A30: b           L_80016A6C
    // 0x80016A34: nop

        goto L_80016A6C;
    // 0x80016A34: nop

L_80016A38:
    // 0x80016A38: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80016A3C: nop

    // 0x80016A40: lw          $t5, 0x1A8($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X1A8);
    // 0x80016A44: nop

    // 0x80016A48: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80016A4C: beq         $t6, $zero, L_80016A6C
    if (ctx->r14 == 0) {
        // 0x80016A50: nop
    
            goto L_80016A6C;
    }
    // 0x80016A50: nop

    // 0x80016A54: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80016A58: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80016A5C: lw          $t8, 0x1A8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1A8);
    // 0x80016A60: nop

    // 0x80016A64: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x80016A68: sw          $t7, 0x1A8($t4)
    MEM_W(0X1A8, ctx->r12) = ctx->r15;
L_80016A6C:
    // 0x80016A6C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80016A70: nop

    // 0x80016A74: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x80016A78: nop

    // 0x80016A7C: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x80016A80: bne         $t2, $zero, L_80016AB8
    if (ctx->r10 != 0) {
        // 0x80016A84: nop
    
            goto L_80016AB8;
    }
    // 0x80016A84: nop

    // 0x80016A88: andi        $t3, $t0, 0x2
    ctx->r11 = ctx->r8 & 0X2;
    // 0x80016A8C: bne         $t3, $zero, L_80016AB8
    if (ctx->r11 != 0) {
        // 0x80016A90: nop
    
            goto L_80016AB8;
    }
    // 0x80016A90: nop

    // 0x80016A94: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80016A98: bne         $t1, $zero, L_80016AB8
    if (ctx->r9 != 0) {
        // 0x80016A9C: nop
    
            goto L_80016AB8;
    }
    // 0x80016A9C: nop

    // 0x80016AA0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80016AA4: nop

    // 0x80016AA8: lh          $t6, 0x11E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X11E);
    // 0x80016AAC: nop

    // 0x80016AB0: beq         $t6, $zero, L_80016AE8
    if (ctx->r14 == 0) {
        // 0x80016AB4: nop
    
            goto L_80016AE8;
    }
    // 0x80016AB4: nop

L_80016AB8:
    // 0x80016AB8: jal         0x800C1754
    // 0x80016ABC: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x80016ABC: nop

    after_0:
    // 0x80016AC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80016AC4: jal         0x8009A14C
    // 0x80016AC8: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x80016AC8: nop

    after_1:
    // 0x80016ACC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80016AD0: jal         0x800997D8
    // 0x80016AD4: nop

    func_800997D8(rdram, ctx);
        goto after_2;
    // 0x80016AD4: nop

    after_2:
    // 0x80016AD8: jal         0x800C1A28
    // 0x80016ADC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x80016ADC: nop

    after_3:
    // 0x80016AE0: b           L_80016AE8
    // 0x80016AE4: nop

        goto L_80016AE8;
    // 0x80016AE4: nop

L_80016AE8:
    // 0x80016AE8: b           L_80016AF8
    // 0x80016AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80016AF8;
    // 0x80016AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016AF0: b           L_80016AF8
    // 0x80016AF4: nop

        goto L_80016AF8;
    // 0x80016AF4: nop

L_80016AF8:
    // 0x80016AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016AFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016B00: jr          $ra
    // 0x80016B04: nop

    return;
    // 0x80016B04: nop

    // 0x80016B08: nop

    // 0x80016B0C: nop

;}
RECOMP_FUNC void func_80066108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006610C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066110: jal         0x80061348
    // 0x80066114: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066114: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066118: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006611C: b           L_8006612C
    // 0x80066120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006612C;
    // 0x80066120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066124: b           L_8006612C
    // 0x80066128: nop

        goto L_8006612C;
    // 0x80066128: nop

L_8006612C:
    // 0x8006612C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066134: jr          $ra
    // 0x80066138: nop

    return;
    // 0x80066138: nop

;}
RECOMP_FUNC void func_8005E474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E474: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005E478: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005E47C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E480: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005E484: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8005E488: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_8005E48C:
    // 0x8005E48C: jal         0x8005E908
    // 0x8005E490: nop

    func_8005E908(rdram, ctx);
        goto after_0;
    // 0x8005E490: nop

    after_0:
    // 0x8005E494: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005E49C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005E4A0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8005E4A4: sw          $v0, 0xE80($at)
    MEM_W(0XE80, ctx->r1) = ctx->r2;
    // 0x8005E4A8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E4AC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005E4B0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8005E4B4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8005E4B8: lw          $t2, 0xE80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE80);
    // 0x8005E4BC: addiu       $t0, $t9, -0x8
    ctx->r8 = ADD32(ctx->r25, -0X8);
    // 0x8005E4C0: sb          $t0, 0x7E($t2)
    MEM_B(0X7E, ctx->r10) = ctx->r8;
    // 0x8005E4C4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E4C8: nop

    // 0x8005E4CC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005E4D0: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8005E4D4: bne         $at, $zero, L_8005E48C
    if (ctx->r1 != 0) {
        // 0x8005E4D8: sw          $t4, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r12;
            goto L_8005E48C;
    }
    // 0x8005E4D8: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8005E4DC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005E4E0: addiu       $t5, $t5, 0x2A9C
    ctx->r13 = ADD32(ctx->r13, 0X2A9C);
    // 0x8005E4E4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8005E4E8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8005E4EC: nop

    // 0x8005E4F0: beq         $t6, $zero, L_8005E8EC
    if (ctx->r14 == 0) {
        // 0x8005E4F4: nop
    
            goto L_8005E8EC;
    }
    // 0x8005E4F4: nop

    // 0x8005E4F8: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x8005E4FC: nop

    // 0x8005E500: beq         $t7, $zero, L_8005E8EC
    if (ctx->r15 == 0) {
        // 0x8005E504: nop
    
            goto L_8005E8EC;
    }
    // 0x8005E504: nop

L_8005E508:
    // 0x8005E508: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E50C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8005E510: addiu       $t1, $t1, 0x2A9C
    ctx->r9 = ADD32(ctx->r9, 0X2A9C);
    // 0x8005E514: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005E518: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x8005E51C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005E520: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005E524: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8005E528: nop

    // 0x8005E52C: bne         $t2, $t3, L_8005E8B0
    if (ctx->r10 != ctx->r11) {
        // 0x8005E530: nop
    
            goto L_8005E8B0;
    }
    // 0x8005E530: nop

    // 0x8005E534: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8005E538: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8005E53C: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x8005E540: nop

    // 0x8005E544: bne         $t4, $t6, L_8005E8B0
    if (ctx->r12 != ctx->r14) {
        // 0x8005E548: nop
    
            goto L_8005E8B0;
    }
    // 0x8005E548: nop

    // 0x8005E54C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8005E550: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E554: addiu       $t7, $t7, 0xE80
    ctx->r15 = ADD32(ctx->r15, 0XE80);
    // 0x8005E558: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8005E55C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8005E560: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005E564: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x8005E568: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E56C: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8005E570: bne         $t0, $zero, L_8005E580
    if (ctx->r8 != 0) {
        // 0x8005E574: and         $t1, $t3, $at
        ctx->r9 = ctx->r11 & ctx->r1;
            goto L_8005E580;
    }
    // 0x8005E574: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8005E578: beq         $t1, $zero, L_8005E5C8
    if (ctx->r9 == 0) {
        // 0x8005E57C: nop
    
            goto L_8005E5C8;
    }
    // 0x8005E57C: nop

L_8005E580:
    // 0x8005E580: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005E584: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005E588: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8005E58C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8005E590: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8005E594: lw          $t5, 0xE80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE80);
    // 0x8005E598: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8005E59C: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8005E5A0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005E5A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E5A8: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8005E5AC: bne         $t2, $zero, L_8005E5BC
    if (ctx->r10 != 0) {
        // 0x8005E5B0: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_8005E5BC;
    }
    // 0x8005E5B0: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x8005E5B4: beq         $t3, $zero, L_8005E5C8
    if (ctx->r11 == 0) {
        // 0x8005E5B8: nop
    
            goto L_8005E5C8;
    }
    // 0x8005E5B8: nop

L_8005E5BC:
    // 0x8005E5BC: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8005E5C0: bne         $at, $zero, L_8005E580
    if (ctx->r1 != 0) {
        // 0x8005E5C4: nop
    
            goto L_8005E580;
    }
    // 0x8005E5C4: nop

L_8005E5C8:
    // 0x8005E5C8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005E5CC: nop

    // 0x8005E5D0: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x8005E5D4: beq         $at, $zero, L_8005E8B0
    if (ctx->r1 == 0) {
        // 0x8005E5D8: nop
    
            goto L_8005E8B0;
    }
    // 0x8005E5D8: nop

    // 0x8005E5DC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E5E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005E5E4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8005E5E8: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8005E5EC: lh          $t6, 0x2AA6($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2AA6);
    // 0x8005E5F0: nop

    // 0x8005E5F4: beq         $t6, $zero, L_8005E62C
    if (ctx->r14 == 0) {
        // 0x8005E5F8: nop
    
            goto L_8005E62C;
    }
    // 0x8005E5F8: nop

    // 0x8005E5FC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005E600: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E604: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8005E608: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005E60C: lw          $t9, 0xE80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE80);
    // 0x8005E610: nop

    // 0x8005E614: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8005E618: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8005E61C: or          $t4, $t2, $zero
    ctx->r12 = ctx->r10 | 0;
    // 0x8005E620: ori         $t5, $t3, 0x8
    ctx->r13 = ctx->r11 | 0X8;
    // 0x8005E624: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x8005E628: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
L_8005E62C:
    // 0x8005E62C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005E630: nop

    // 0x8005E634: bgez        $t7, L_8005E648
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8005E638: andi        $t0, $t7, 0x1
        ctx->r8 = ctx->r15 & 0X1;
            goto L_8005E648;
    }
    // 0x8005E638: andi        $t0, $t7, 0x1
    ctx->r8 = ctx->r15 & 0X1;
    // 0x8005E63C: beq         $t0, $zero, L_8005E648
    if (ctx->r8 == 0) {
        // 0x8005E640: nop
    
            goto L_8005E648;
    }
    // 0x8005E640: nop

    // 0x8005E644: addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
L_8005E648:
    // 0x8005E648: beq         $t0, $zero, L_8005E670
    if (ctx->r8 == 0) {
        // 0x8005E64C: nop
    
            goto L_8005E670;
    }
    // 0x8005E64C: nop

    // 0x8005E650: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E654: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8005E658: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005E65C: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8005E660: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005E664: lw          $t6, 0xE80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE80);
    // 0x8005E668: b           L_8005E698
    // 0x8005E66C: swc1        $f6, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f6.u32l;
        goto L_8005E698;
    // 0x8005E66C: swc1        $f6, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f6.u32l;
L_8005E670:
    // 0x8005E670: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8005E674: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x8005E678: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8005E67C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005E680: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005E684: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005E688: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8005E68C: lw          $t4, 0xE80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE80);
    // 0x8005E690: nop

    // 0x8005E694: swc1        $f10, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f10.u32l;
L_8005E698:
    // 0x8005E698: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005E69C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005E6A0: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8005E6A4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8005E6A8: lw          $t0, 0xE80($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE80);
    // 0x8005E6AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E6B0: nop

    // 0x8005E6B4: swc1        $f16, 0xA0($t0)
    MEM_W(0XA0, ctx->r8) = ctx->f16.u32l;
    // 0x8005E6B8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005E6BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005E6C0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8005E6C4: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8005E6C8: lw          $t6, 0xE80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE80);
    // 0x8005E6CC: nop

    // 0x8005E6D0: sw          $zero, 0x88($t6)
    MEM_W(0X88, ctx->r14) = 0;
    // 0x8005E6D4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E6D8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8005E6DC: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x8005E6E0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8005E6E4: lh          $t3, 0x2AA0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2AA0);
    // 0x8005E6E8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8005E6EC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8005E6F0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E6F4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005E6F8: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005E6FC: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8005E700: lw          $t9, 0xE80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE80);
    // 0x8005E704: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E708: swc1        $f20, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f20.u32l;
    // 0x8005E70C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8005E710: nop

    // 0x8005E714: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8005E718: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8005E71C: lw          $t1, 0xE80($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE80);
    // 0x8005E720: nop

    // 0x8005E724: swc1        $f20, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f20.u32l;
    // 0x8005E728: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E72C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8005E730: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8005E734: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8005E738: lh          $t2, 0x2AA2($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2AA2);
    // 0x8005E73C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005E740: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8005E744: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005E748: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005E74C: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005E750: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005E754: lw          $t5, 0xE80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE80);
    // 0x8005E758: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E75C: swc1        $f20, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f20.u32l;
    // 0x8005E760: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005E764: nop

    // 0x8005E768: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005E76C: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8005E770: lw          $t7, 0xE80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE80);
    // 0x8005E774: nop

    // 0x8005E778: swc1        $f20, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f20.u32l;
    // 0x8005E77C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005E780: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E784: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005E788: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005E78C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8005E790: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x8005E794: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x8005E798: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005E79C: lw          $a0, 0xE80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE80);
    // 0x8005E7A0: lh          $a1, 0x2AA4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2AA4);
    // 0x8005E7A4: jal         0x8005EC54
    // 0x8005E7A8: nop

    func_8005EC54(rdram, ctx);
        goto after_1;
    // 0x8005E7A8: nop

    after_1:
    // 0x8005E7AC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E7B0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005E7B4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005E7B8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E7BC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8005E7C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005E7C4: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8005E7C8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005E7CC: lh          $t5, 0x2AA4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2AA4);
    // 0x8005E7D0: lw          $t7, 0xE80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE80);
    // 0x8005E7D4: nop

    // 0x8005E7D8: sh          $t5, 0x7C($t7)
    MEM_H(0X7C, ctx->r15) = ctx->r13;
    // 0x8005E7DC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E7E0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005E7E4: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x8005E7E8: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8005E7EC: lh          $t8, 0x2AA4($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2AA4);
    // 0x8005E7F0: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x8005E7F4: bne         $t8, $at, L_8005E81C
    if (ctx->r24 != ctx->r1) {
        // 0x8005E7F8: nop
    
            goto L_8005E81C;
    }
    // 0x8005E7F8: nop

    // 0x8005E7FC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8005E800: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005E804: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005E808: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8005E80C: lw          $t9, 0xE80($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE80);
    // 0x8005E810: addiu       $t2, $zero, 0x3F
    ctx->r10 = ADD32(0, 0X3F);
    // 0x8005E814: b           L_8005E838
    // 0x8005E818: sw          $t2, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r10;
        goto L_8005E838;
    // 0x8005E818: sw          $t2, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r10;
L_8005E81C:
    // 0x8005E81C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8005E820: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005E824: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8005E828: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8005E82C: lw          $t1, 0xE80($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE80);
    // 0x8005E830: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x8005E834: sw          $t0, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r8;
L_8005E838:
    // 0x8005E838: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8005E83C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005E840: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8005E844: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E848: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x8005E84C: lw          $t3, 0xE80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE80);
    // 0x8005E850: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005E854: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8005E858: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x8005E85C: lw          $a3, 0x44($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X44);
    // 0x8005E860: lh          $a1, 0x2AA4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2AA4);
    // 0x8005E864: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005E868: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005E86C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x8005E870: jal         0x8004F3E8
    // 0x8005E874: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_8004F3E8(rdram, ctx);
        goto after_2;
    // 0x8005E874: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_2:
    // 0x8005E878: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8005E87C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005E880: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8005E884: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8005E888: lw          $t7, 0xE80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE80);
    // 0x8005E88C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005E890: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8005E894: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8005E898: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x8005E89C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005E8A0: or          $t6, $t0, $zero
    ctx->r14 = ctx->r8 | 0;
    // 0x8005E8A4: or          $t7, $t1, $at
    ctx->r15 = ctx->r9 | ctx->r1;
    // 0x8005E8A8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8005E8AC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_8005E8B0:
    // 0x8005E8B0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8005E8B4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8005E8B8: addiu       $t2, $t4, 0x6
    ctx->r10 = ADD32(ctx->r12, 0X6);
    // 0x8005E8BC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8005E8C0: addiu       $t9, $t9, 0x2A9C
    ctx->r25 = ADD32(ctx->r25, 0X2A9C);
    // 0x8005E8C4: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x8005E8C8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8005E8CC: lh          $t0, 0x0($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X0);
    // 0x8005E8D0: nop

    // 0x8005E8D4: beq         $t0, $zero, L_8005E8EC
    if (ctx->r8 == 0) {
        // 0x8005E8D8: nop
    
            goto L_8005E8EC;
    }
    // 0x8005E8D8: nop

    // 0x8005E8DC: lh          $t1, 0x2($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X2);
    // 0x8005E8E0: nop

    // 0x8005E8E4: bne         $t1, $zero, L_8005E508
    if (ctx->r9 != 0) {
        // 0x8005E8E8: nop
    
            goto L_8005E508;
    }
    // 0x8005E8E8: nop

L_8005E8EC:
    // 0x8005E8EC: b           L_8005E8F4
    // 0x8005E8F0: nop

        goto L_8005E8F4;
    // 0x8005E8F0: nop

L_8005E8F4:
    // 0x8005E8F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005E8F8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005E8FC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005E900: jr          $ra
    // 0x8005E904: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005E904: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80068E44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068E4C: jal         0x80061488
    // 0x80068E50: addiu       $a0, $zero, 0xF6
    ctx->r4 = ADD32(0, 0XF6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80068E50: addiu       $a0, $zero, 0xF6
    ctx->r4 = ADD32(0, 0XF6);
    after_0:
    // 0x80068E54: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80068E58: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80068E5C: b           L_80068E6C
    // 0x80068E60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80068E6C;
    // 0x80068E60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80068E64: b           L_80068E6C
    // 0x80068E68: nop

        goto L_80068E6C;
    // 0x80068E68: nop

L_80068E6C:
    // 0x80068E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068E74: jr          $ra
    // 0x80068E78: nop

    return;
    // 0x80068E78: nop

;}
RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x80000404: lui         $t1, 0xC
    ctx->r9 = S32(0XC << 16);
    // 0x80000408: addiu       $t0, $t0, 0x18E0
    ctx->r8 = ADD32(ctx->r8, 0X18E0);
    // 0x8000040C: ori         $t1, $t1, 0x7C0
    ctx->r9 = ctx->r9 | 0X7C0;
L_80000410:
    // 0x80000410: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000414: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000418: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8000041C: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000420: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80000410;
    }
    // 0x80000420: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80000424: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80000428: lui         $sp, 0x8018
    ctx->r29 = S32(0X8018 << 16);
    // 0x8000042C: addiu       $t2, $t2, -0x2910
    ctx->r10 = ADD32(ctx->r10, -0X2910);
    // 0x80000430: jr          $t2
    // 0x80000434: addiu       $sp, $sp, 0x49C0
    ctx->r29 = ADD32(ctx->r29, 0X49C0);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000434: addiu       $sp, $sp, 0x49C0
    ctx->r29 = ADD32(ctx->r29, 0X49C0);
;}
RECOMP_FUNC void func_800738C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800738C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800738CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800738D0: jal         0x80061488
    // 0x800738D4: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800738D4: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x800738D8: slti        $t6, $v0, 0x6
    ctx->r14 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800738DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800738E0: bne         $v0, $zero, L_800738FC
    if (ctx->r2 != 0) {
        // 0x800738E4: nop
    
            goto L_800738FC;
    }
    // 0x800738E4: nop

    // 0x800738E8: jal         0x80061348
    // 0x800738EC: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800738EC: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_1:
    // 0x800738F0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800738F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800738F8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800738FC:
    // 0x800738FC: b           L_8007390C
    // 0x80073900: nop

        goto L_8007390C;
    // 0x80073900: nop

    // 0x80073904: b           L_8007390C
    // 0x80073908: nop

        goto L_8007390C;
    // 0x80073908: nop

L_8007390C:
    // 0x8007390C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073914: jr          $ra
    // 0x80073918: nop

    return;
    // 0x80073918: nop

;}
RECOMP_FUNC void func_80072DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072DEC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072DF0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072DF4: nop

    // 0x80072DF8: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072DFC: nop

    // 0x80072E00: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072E04: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072E08: jr          $ra
    // 0x80072E0C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072E0C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072E10: jr          $ra
    // 0x80072E14: nop

    return;
    // 0x80072E14: nop

    // 0x80072E18: jr          $ra
    // 0x80072E1C: nop

    return;
    // 0x80072E1C: nop

;}
RECOMP_FUNC void func_800654F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800654FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065500: jal         0x80061348
    // 0x80065504: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065504: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_0:
    // 0x80065508: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006550C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065510: bne         $v0, $zero, L_8006552C
    if (ctx->r2 != 0) {
        // 0x80065514: nop
    
            goto L_8006552C;
    }
    // 0x80065514: nop

    // 0x80065518: jal         0x80061348
    // 0x8006551C: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006551C: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_1:
    // 0x80065520: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80065524: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80065528: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006552C:
    // 0x8006552C: b           L_8006553C
    // 0x80065530: nop

        goto L_8006553C;
    // 0x80065530: nop

    // 0x80065534: b           L_8006553C
    // 0x80065538: nop

        goto L_8006553C;
    // 0x80065538: nop

L_8006553C:
    // 0x8006553C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065544: jr          $ra
    // 0x80065548: nop

    return;
    // 0x80065548: nop

;}
RECOMP_FUNC void func_8006ED10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ED14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ED18: jal         0x80061348
    // 0x8006ED1C: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006ED1C: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    after_0:
    // 0x8006ED20: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006ED24: b           L_8006ED34
    // 0x8006ED28: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006ED34;
    // 0x8006ED28: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006ED2C: b           L_8006ED34
    // 0x8006ED30: nop

        goto L_8006ED34;
    // 0x8006ED30: nop

L_8006ED34:
    // 0x8006ED34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ED38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ED3C: jr          $ra
    // 0x8006ED40: nop

    return;
    // 0x8006ED40: nop

;}
RECOMP_FUNC void func_8006FFB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FFB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006FFB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006FFBC: nop

    // 0x8006FFC0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006FFC4: nop

    // 0x8006FFC8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006FFCC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006FFD0: jr          $ra
    // 0x8006FFD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006FFD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FFD8: jr          $ra
    // 0x8006FFDC: nop

    return;
    // 0x8006FFDC: nop

    // 0x8006FFE0: jr          $ra
    // 0x8006FFE4: nop

    return;
    // 0x8006FFE4: nop

;}
RECOMP_FUNC void func_80083FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083FE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80083FE4: jal         0x80083EAC
    // 0x80083FE8: nop

    func_80083EAC(rdram, ctx);
        goto after_0;
    // 0x80083FE8: nop

    after_0:
    // 0x80083FEC: jal         0x800AE348
    // 0x80083FF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    ContPak_SetPakInitializationAttempts(rdram, ctx);
        goto after_1;
    // 0x80083FF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80083FF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80083FF8: nop

    // 0x80083FFC: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
    // 0x80084000: b           L_80084010
    // 0x80084004: nop

        goto L_80084010;
    // 0x80084004: nop

    // 0x80084008: b           L_80084010
    // 0x8008400C: nop

        goto L_80084010;
    // 0x8008400C: nop

L_80084010:
    // 0x80084010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80084018: jr          $ra
    // 0x8008401C: nop

    return;
    // 0x8008401C: nop

;}
