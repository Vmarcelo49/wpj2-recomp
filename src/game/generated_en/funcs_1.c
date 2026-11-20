#include "recomp.h"
#include "shims.h"
#include "funcs.h"

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
RECOMP_FUNC void func_8000BDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BDDC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000BDE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BDE4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000BDE8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8000BDEC: nop

    // 0x8000BDF0: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000BDF4: nop

    // 0x8000BDF8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8000BDFC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BE00: nop

    // 0x8000BE04: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000BE08: nop

    // 0x8000BE0C: beq         $t9, $zero, L_8000BE4C
    if (ctx->r25 == 0) {
        // 0x8000BE10: nop

            goto L_8000BE4C;
    }
    // 0x8000BE10: nop

    // 0x8000BE14: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BE18: nop

    // 0x8000BE1C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000BE20: nop

    // 0x8000BE24: lw          $t2, 0x1A0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A0);
    // 0x8000BE28: nop

    // 0x8000BE2C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8000BE30: beq         $t3, $zero, L_8000BE4C
    if (ctx->r11 == 0) {
        // 0x8000BE34: nop

            goto L_8000BE4C;
    }
    // 0x8000BE34: nop

    // 0x8000BE38: andi        $t4, $t2, 0x8
    ctx->r12 = ctx->r10 & 0X8;
    // 0x8000BE3C: bne         $t4, $zero, L_8000BE4C
    if (ctx->r12 != 0) {
        // 0x8000BE40: nop

            goto L_8000BE4C;
    }
    // 0x8000BE40: nop

    // 0x8000BE44: b           L_8000C3A0
    // 0x8000BE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C3A0;
    // 0x8000BE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BE4C:
    // 0x8000BE4C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BE50: nop

    // 0x8000BE54: lhu         $t6, 0x14($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X14);
    // 0x8000BE58: nop

    // 0x8000BE5C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000BE60: bne         $t7, $zero, L_8000BF5C
    if (ctx->r15 != 0) {
        // 0x8000BE64: nop

            goto L_8000BF5C;
    }
    // 0x8000BE64: nop

    // 0x8000BE68: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000BE6C: lh          $t8, -0x73C0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X73C0);
    // 0x8000BE70: nop

    // 0x8000BE74: bltz        $t8, L_8000BF10
    if (SIGNED(ctx->r24) < 0) {
        // 0x8000BE78: nop

            goto L_8000BF10;
    }
    // 0x8000BE78: nop

    // 0x8000BE7C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8000BE80: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8000BE84: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8000BE88: nop

    // 0x8000BE8C: andi        $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 & 0X2000;
    // 0x8000BE90: bne         $t1, $zero, L_8000BEC4
    if (ctx->r9 != 0) {
        // 0x8000BE94: nop

            goto L_8000BEC4;
    }
    // 0x8000BE94: nop

    // 0x8000BE98: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000BE9C: lh          $a1, -0x73C0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73C0);
    // 0x8000BEA0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BEA4: jal         0x8000C584
    // 0x8000BEA8: nop

    func_8000C584(rdram, ctx);
        goto after_0;
    // 0x8000BEA8: nop

    after_0:
    // 0x8000BEAC: bgez        $v0, L_8000BEBC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BEB0: nop

            goto L_8000BEBC;
    }
    // 0x8000BEB0: nop

    // 0x8000BEB4: b           L_8000C3A0
    // 0x8000BEB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000C3A0;
    // 0x8000BEB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000BEBC:
    // 0x8000BEBC: b           L_8000BF08
    // 0x8000BEC0: nop

        goto L_8000BF08;
    // 0x8000BEC0: nop

L_8000BEC4:
    // 0x8000BEC4: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000BEC8: lh          $a1, -0x73C0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73C0);
    // 0x8000BECC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BED0: jal         0x8000C584
    // 0x8000BED4: nop

    func_8000C584(rdram, ctx);
        goto after_1;
    // 0x8000BED4: nop

    after_1:
    // 0x8000BED8: bgez        $v0, L_8000BEF8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BEDC: nop

            goto L_8000BEF8;
    }
    // 0x8000BEDC: nop

    // 0x8000BEE0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000BEE4: lh          $t3, -0x73C0($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X73C0);
    // 0x8000BEE8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000BEEC: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8000BEF0: b           L_8000BF00
    // 0x8000BEF4: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
        goto L_8000BF00;
    // 0x8000BEF4: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
L_8000BEF8:
    // 0x8000BEF8: b           L_8000BF08
    // 0x8000BEFC: nop

        goto L_8000BF08;
    // 0x8000BEFC: nop

L_8000BF00:
    // 0x8000BF00: b           L_8000BEC4
    // 0x8000BF04: nop

        goto L_8000BEC4;
    // 0x8000BF04: nop

L_8000BF08:
    // 0x8000BF08: b           L_8000BF2C
    // 0x8000BF0C: nop

        goto L_8000BF2C;
    // 0x8000BF0C: nop

L_8000BF10:
    // 0x8000BF10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF14: jal         0x8000C778
    // 0x8000BF18: nop

    func_8000C778(rdram, ctx);
        goto after_2;
    // 0x8000BF18: nop

    after_2:
    // 0x8000BF1C: bgez        $v0, L_8000BF2C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BF20: nop

            goto L_8000BF2C;
    }
    // 0x8000BF20: nop

    // 0x8000BF24: b           L_8000C3A0
    // 0x8000BF28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000C3A0;
    // 0x8000BF28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000BF2C:
    // 0x8000BF2C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF30: nop

    // 0x8000BF34: lhu         $t5, 0x14($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X14);
    // 0x8000BF38: nop

    // 0x8000BF3C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8000BF40: sh          $t6, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r14;
    // 0x8000BF44: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF48: nop

    // 0x8000BF4C: lhu         $t8, 0x14($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X14);
    // 0x8000BF50: nop

    // 0x8000BF54: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x8000BF58: sh          $t9, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r25;
L_8000BF5C:
    // 0x8000BF5C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF60: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x8000BF64: lh          $t1, 0x1C($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X1C);
    // 0x8000BF68: nop

    // 0x8000BF6C: sh          $t1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r9;
    // 0x8000BF70: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF74: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x8000BF78: lh          $t5, 0x1E($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X1E);
    // 0x8000BF7C: nop

    // 0x8000BF80: sh          $t5, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r13;
    // 0x8000BF84: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF88: jal         0x8000CC44
    // 0x8000BF8C: nop

    func_8000CC44(rdram, ctx);
        goto after_3;
    // 0x8000BF8C: nop

    after_3:
    // 0x8000BF90: bgez        $v0, L_8000C0DC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000BF94: nop

            goto L_8000C0DC;
    }
    // 0x8000BF94: nop

    // 0x8000BF98: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8000BF9C: nop

    // 0x8000BFA0: lw          $t8, 0x20C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X20C);
    // 0x8000BFA4: nop

    // 0x8000BFA8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8000BFAC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BFB0: nop

    // 0x8000BFB4: beq         $t9, $zero, L_8000BFEC
    if (ctx->r25 == 0) {
        // 0x8000BFB8: nop

            goto L_8000BFEC;
    }
    // 0x8000BFB8: nop

    // 0x8000BFBC: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8000BFC0: nop

    // 0x8000BFC4: beq         $t7, $zero, L_8000BFEC
    if (ctx->r15 == 0) {
        // 0x8000BFC8: nop

            goto L_8000BFEC;
    }
    // 0x8000BFC8: nop

    // 0x8000BFCC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BFD0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000BFD4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000BFD8: nop

    // 0x8000BFDC: lw          $t3, 0x1A0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X1A0);
    // 0x8000BFE0: nop

    // 0x8000BFE4: and         $t2, $t3, $at
    ctx->r10 = ctx->r11 & ctx->r1;
    // 0x8000BFE8: sw          $t2, 0x1A0($t1)
    MEM_W(0X1A0, ctx->r9) = ctx->r10;
L_8000BFEC:
    // 0x8000BFEC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000BFF0: lw          $a0, -0x2828($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2828);
    // 0x8000BFF4: jal         0x800BCCE4
    // 0x8000BFF8: nop

    func_800BCCE4(rdram, ctx);
        goto after_4;
    // 0x8000BFF8: nop

    after_4:
    // 0x8000BFFC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000C000: sw          $zero, -0x2828($at)
    MEM_W(-0X2828, ctx->r1) = 0;
    // 0x8000C004: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000C008: lw          $t5, 0x3070($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3070);
    // 0x8000C00C: nop

    // 0x8000C010: beq         $t5, $zero, L_8000C030
    if (ctx->r13 == 0) {
        // 0x8000C014: nop

            goto L_8000C030;
    }
    // 0x8000C014: nop

    // 0x8000C018: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C01C: lw          $a0, 0x3070($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3070);
    // 0x8000C020: jal         0x800BCCE4
    // 0x8000C024: nop

    func_800BCCE4(rdram, ctx);
        goto after_5;
    // 0x8000C024: nop

    after_5:
    // 0x8000C028: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C02C: sw          $zero, 0x3070($at)
    MEM_W(0X3070, ctx->r1) = 0;
L_8000C030:
    // 0x8000C030: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8000C034: lw          $t6, 0x3078($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3078);
    // 0x8000C038: nop

    // 0x8000C03C: beq         $t6, $zero, L_8000C05C
    if (ctx->r14 == 0) {
        // 0x8000C040: nop

            goto L_8000C05C;
    }
    // 0x8000C040: nop

    // 0x8000C044: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C048: lw          $a0, 0x3078($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3078);
    // 0x8000C04C: jal         0x800BCCE4
    // 0x8000C050: nop

    func_800BCCE4(rdram, ctx);
        goto after_6;
    // 0x8000C050: nop

    after_6:
    // 0x8000C054: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C058: sw          $zero, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = 0;
L_8000C05C:
    // 0x8000C05C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8000C060: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000C064: lw          $t8, 0x1A0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1A0);
    // 0x8000C068: nop

    // 0x8000C06C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000C070: sw          $t9, 0x1A0($t4)
    MEM_W(0X1A0, ctx->r12) = ctx->r25;
    // 0x8000C074: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8000C078: nop

    // 0x8000C07C: lw          $t0, 0x1A0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X1A0);
    // 0x8000C080: nop

    // 0x8000C084: ori         $t3, $t0, 0x8
    ctx->r11 = ctx->r8 | 0X8;
    // 0x8000C088: sw          $t3, 0x1A0($t7)
    MEM_W(0X1A0, ctx->r15) = ctx->r11;
    // 0x8000C08C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000C090: nop

    // 0x8000C094: lw          $t1, 0x1A8($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X1A8);
    // 0x8000C098: nop

    // 0x8000C09C: ori         $t5, $t1, 0x1
    ctx->r13 = ctx->r9 | 0X1;
    // 0x8000C0A0: sw          $t5, 0x1A8($t2)
    MEM_W(0X1A8, ctx->r10) = ctx->r13;
    // 0x8000C0A4: jal         0x80016264
    // 0x8000C0A8: nop

    func_80016264(rdram, ctx);
        goto after_7;
    // 0x8000C0A8: nop

    after_7:
    // 0x8000C0AC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000C0B0: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8000C0B4: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x8000C0B8: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8000C0BC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000C0C0: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x8000C0C4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000C0C8: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000C0CC: lhu         $t0, 0x6($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0X6);
    // 0x8000C0D0: nop

    // 0x8000C0D4: ori         $t3, $t0, 0x4000
    ctx->r11 = ctx->r8 | 0X4000;
    // 0x8000C0D8: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
L_8000C0DC:
    // 0x8000C0DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C0E0: addiu       $t5, $sp, 0x20
    ctx->r13 = ADD32(ctx->r29, 0X20);
    // 0x8000C0E4: lh          $t2, 0x0($t5)
    ctx->r10 = MEM_H(ctx->r13, 0X0);
    // 0x8000C0E8: lh          $t1, 0x1C($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X1C);
    // 0x8000C0EC: nop

    // 0x8000C0F0: bne         $t1, $t2, L_8000C128
    if (ctx->r9 != ctx->r10) {
        // 0x8000C0F4: nop

            goto L_8000C128;
    }
    // 0x8000C0F4: nop

    // 0x8000C0F8: lh          $t8, 0x1E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X1E);
    // 0x8000C0FC: lh          $t9, 0x2($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X2);
    // 0x8000C100: nop

    // 0x8000C104: bne         $t8, $t9, L_8000C128
    if (ctx->r24 != ctx->r25) {
        // 0x8000C108: nop

            goto L_8000C128;
    }
    // 0x8000C108: nop

    // 0x8000C10C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8000C110: nop

    // 0x8000C114: lw          $t0, 0x1A0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X1A0);
    // 0x8000C118: nop

    // 0x8000C11C: andi        $t3, $t0, 0x2
    ctx->r11 = ctx->r8 & 0X2;
    // 0x8000C120: bne         $t3, $zero, L_8000C2D4
    if (ctx->r11 != 0) {
        // 0x8000C124: nop

            goto L_8000C2D4;
    }
    // 0x8000C124: nop

L_8000C128:
    // 0x8000C128: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C12C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C130: lh          $t1, 0x1C($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X1C);
    // 0x8000C134: nop

    // 0x8000C138: sh          $t1, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r9;
    // 0x8000C13C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C140: nop

    // 0x8000C144: lhu         $t7, 0x14($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X14);
    // 0x8000C148: nop

    // 0x8000C14C: andi        $t5, $t7, 0x2
    ctx->r13 = ctx->r15 & 0X2;
    // 0x8000C150: beq         $t5, $zero, L_8000C184
    if (ctx->r13 == 0) {
        // 0x8000C154: nop

            goto L_8000C184;
    }
    // 0x8000C154: nop

    // 0x8000C158: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8000C15C: lh          $t8, 0x7254($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7254);
    // 0x8000C160: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C164: ori         $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 | 0X8000;
    // 0x8000C168: sh          $t9, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r25;
    // 0x8000C16C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C170: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000C174: lhu         $t0, 0x14($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X14);
    // 0x8000C178: nop

    // 0x8000C17C: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8000C180: sh          $t3, 0x14($t6)
    MEM_H(0X14, ctx->r14) = ctx->r11;
L_8000C184:
    // 0x8000C184: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C188: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C18C: lh          $t1, 0x1E($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X1E);
    // 0x8000C190: nop

    // 0x8000C194: sh          $t1, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r9;
    // 0x8000C198: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C19C: sh          $zero, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = 0;
    // 0x8000C1A0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C1A4: nop

    // 0x8000C1A8: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8000C1AC: nop

    // 0x8000C1B0: beq         $t7, $zero, L_8000C1EC
    if (ctx->r15 == 0) {
        // 0x8000C1B4: nop

            goto L_8000C1EC;
    }
    // 0x8000C1B4: nop

    // 0x8000C1B8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8000C1BC: nop

    // 0x8000C1C0: lw          $t8, 0x1A0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000C1C4: nop

    // 0x8000C1C8: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8000C1CC: beq         $t9, $zero, L_8000C1EC
    if (ctx->r25 == 0) {
        // 0x8000C1D0: nop

            goto L_8000C1EC;
    }
    // 0x8000C1D0: nop

    // 0x8000C1D4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8000C1D8: nop

    // 0x8000C1DC: lw          $t3, 0x1A8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X1A8);
    // 0x8000C1E0: nop

    // 0x8000C1E4: ori         $t6, $t3, 0x1
    ctx->r14 = ctx->r11 | 0X1;
    // 0x8000C1E8: sw          $t6, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r14;
L_8000C1EC:
    // 0x8000C1EC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8000C1F0: nop

    // 0x8000C1F4: lw          $t1, 0x1A0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X1A0);
    // 0x8000C1F8: nop

    // 0x8000C1FC: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8000C200: bne         $t2, $zero, L_8000C2BC
    if (ctx->r10 != 0) {
        // 0x8000C204: nop

            goto L_8000C2BC;
    }
    // 0x8000C204: nop

    // 0x8000C208: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8000C20C: lh          $t7, 0x7254($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7254);
    // 0x8000C210: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C214: ori         $t5, $t7, 0x8000
    ctx->r13 = ctx->r15 | 0X8000;
    // 0x8000C218: sh          $t5, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r13;
    // 0x8000C21C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000C220: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8000C224: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x8000C228: nop

    // 0x8000C22C: andi        $t3, $t9, 0x2000
    ctx->r11 = ctx->r25 & 0X2000;
    // 0x8000C230: bne         $t3, $zero, L_8000C248
    if (ctx->r11 != 0) {
        // 0x8000C234: nop

            goto L_8000C248;
    }
    // 0x8000C234: nop

    // 0x8000C238: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x8000C23C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C240: b           L_8000C25C
    // 0x8000C244: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
        goto L_8000C25C;
    // 0x8000C244: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
L_8000C248:
    // 0x8000C248: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000C24C: lh          $t0, -0x73C0($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X73C0);
    // 0x8000C250: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C254: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x8000C258: sh          $t4, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r12;
L_8000C25C:
    // 0x8000C25C: jal         0x80031728
    // 0x8000C260: nop

    func_80031728(rdram, ctx);
        goto after_8;
    // 0x8000C260: nop

    after_8:
    // 0x8000C264: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C268: nop

    // 0x8000C26C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8000C270: nop

    // 0x8000C274: beq         $t2, $zero, L_8000C29C
    if (ctx->r10 == 0) {
        // 0x8000C278: nop

            goto L_8000C29C;
    }
    // 0x8000C278: nop

    // 0x8000C27C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C280: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x8000C284: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x8000C288: nop

    // 0x8000C28C: lw          $t8, 0x1A0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000C290: nop

    // 0x8000C294: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000C298: sw          $t9, 0x1A0($t5)
    MEM_W(0X1A0, ctx->r13) = ctx->r25;
L_8000C29C:
    // 0x8000C29C: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8000C2A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C2A4: sw          $t3, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r11;
    // 0x8000C2A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000C2AC: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8000C2B0: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x8000C2B4: b           L_8000C3A0
    // 0x8000C2B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000C3A0;
    // 0x8000C2B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000C2BC:
    // 0x8000C2BC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000C2C0: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8000C2C4: lhu         $t4, 0x0($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X0);
    // 0x8000C2C8: nop

    // 0x8000C2CC: ori         $t1, $t4, 0x80
    ctx->r9 = ctx->r12 | 0X80;
    // 0x8000C2D0: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
L_8000C2D4:
    // 0x8000C2D4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C2D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C2DC: lh          $t7, 0x16($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X16);
    // 0x8000C2E0: nop

    // 0x8000C2E4: sh          $t7, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r15;
    // 0x8000C2E8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C2EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C2F0: lh          $t9, 0x18($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X18);
    // 0x8000C2F4: nop

    // 0x8000C2F8: sh          $t9, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = ctx->r25;
    // 0x8000C2FC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C300: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C304: lh          $t3, 0x1A($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X1A);
    // 0x8000C308: nop

    // 0x8000C30C: sh          $t3, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = ctx->r11;
    // 0x8000C310: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C314: nop

    // 0x8000C318: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x8000C31C: nop

    // 0x8000C320: beq         $t4, $zero, L_8000C390
    if (ctx->r12 == 0) {
        // 0x8000C324: nop

            goto L_8000C390;
    }
    // 0x8000C324: nop

    // 0x8000C328: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8000C32C: nop

    // 0x8000C330: lw          $t0, 0x1A8($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X1A8);
    // 0x8000C334: nop

    // 0x8000C338: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x8000C33C: bne         $t2, $zero, L_8000C390
    if (ctx->r10 != 0) {
        // 0x8000C340: nop

            goto L_8000C390;
    }
    // 0x8000C340: nop

    // 0x8000C344: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C348: lw          $a0, 0x3068($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3068);
    // 0x8000C34C: jal         0x8000D390
    // 0x8000C350: nop

    TempHeap_Free(rdram, ctx);
        goto after_9;
    // 0x8000C350: nop

    after_9:
    // 0x8000C354: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C358: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
    // 0x8000C35C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C360: nop

    // 0x8000C364: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000C368: nop

    // 0x8000C36C: sw          $zero, 0x1A8($t8)
    MEM_W(0X1A8, ctx->r24) = 0;
    // 0x8000C370: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8000C374: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8000C378: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8000C37C: nop

    // 0x8000C380: lw          $t3, 0x1A0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000C384: nop

    // 0x8000C388: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x8000C38C: sw          $t6, 0x1A0($t5)
    MEM_W(0X1A0, ctx->r13) = ctx->r14;
L_8000C390:
    // 0x8000C390: b           L_8000C3A0
    // 0x8000C394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C3A0;
    // 0x8000C394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C398: b           L_8000C3A0
    // 0x8000C39C: nop

        goto L_8000C3A0;
    // 0x8000C39C: nop

L_8000C3A0:
    // 0x8000C3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C3A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000C3A8: jr          $ra
    // 0x8000C3AC: nop

    return;
    // 0x8000C3AC: nop

;}
RECOMP_FUNC void func_8000C3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C3B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000C3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C3B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000C3BC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000C3C0: nop

    // 0x8000C3C4: bne         $t6, $zero, L_8000C3D4
    if (ctx->r14 != 0) {
        // 0x8000C3C8: nop

            goto L_8000C3D4;
    }
    // 0x8000C3C8: nop

    // 0x8000C3CC: b           L_8000C574
    // 0x8000C3D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C574;
    // 0x8000C3D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C3D4:
    // 0x8000C3D4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000C3D8: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8000C3DC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000C3E0: bne         $t7, $at, L_8000C3F0
    if (ctx->r15 != ctx->r1) {
        // 0x8000C3E4: nop

            goto L_8000C3F0;
    }
    // 0x8000C3E4: nop

    // 0x8000C3E8: b           L_8000C574
    // 0x8000C3EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C574;
    // 0x8000C3EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C3F0:
    // 0x8000C3F0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000C3F4: nop

    // 0x8000C3F8: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x8000C3FC: nop

    // 0x8000C400: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000C404: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C408: nop

    // 0x8000C40C: beq         $t0, $zero, L_8000C438
    if (ctx->r8 == 0) {
        // 0x8000C410: nop

            goto L_8000C438;
    }
    // 0x8000C410: nop

    // 0x8000C414: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000C418: nop

    // 0x8000C41C: beq         $t1, $zero, L_8000C438
    if (ctx->r9 == 0) {
        // 0x8000C420: nop

            goto L_8000C438;
    }
    // 0x8000C420: nop

    // 0x8000C424: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C428: nop

    // 0x8000C42C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8000C430: jal         0x8000DD94
    // 0x8000C434: nop

    func_8000DD94(rdram, ctx);
        goto after_0;
    // 0x8000C434: nop

    after_0:
L_8000C438:
    // 0x8000C438: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000C43C: lw          $a0, -0x2828($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2828);
    // 0x8000C440: jal         0x800BCCE4
    // 0x8000C444: nop

    func_800BCCE4(rdram, ctx);
        goto after_1;
    // 0x8000C444: nop

    after_1:
    // 0x8000C448: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000C44C: sw          $zero, -0x2828($at)
    MEM_W(-0X2828, ctx->r1) = 0;
    // 0x8000C450: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8000C454: lw          $t3, 0x3070($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3070);
    // 0x8000C458: nop

    // 0x8000C45C: beq         $t3, $zero, L_8000C47C
    if (ctx->r11 == 0) {
        // 0x8000C460: nop

            goto L_8000C47C;
    }
    // 0x8000C460: nop

    // 0x8000C464: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C468: lw          $a0, 0x3070($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3070);
    // 0x8000C46C: jal         0x800BCCE4
    // 0x8000C470: nop

    func_800BCCE4(rdram, ctx);
        goto after_2;
    // 0x8000C470: nop

    after_2:
    // 0x8000C474: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C478: sw          $zero, 0x3070($at)
    MEM_W(0X3070, ctx->r1) = 0;
L_8000C47C:
    // 0x8000C47C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8000C480: lw          $t4, 0x3078($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3078);
    // 0x8000C484: nop

    // 0x8000C488: beq         $t4, $zero, L_8000C4A8
    if (ctx->r12 == 0) {
        // 0x8000C48C: nop

            goto L_8000C4A8;
    }
    // 0x8000C48C: nop

    // 0x8000C490: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000C494: lw          $a0, 0x3078($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3078);
    // 0x8000C498: jal         0x800BCCE4
    // 0x8000C49C: nop

    func_800BCCE4(rdram, ctx);
        goto after_3;
    // 0x8000C49C: nop

    after_3:
    // 0x8000C4A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000C4A4: sw          $zero, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = 0;
L_8000C4A8:
    // 0x8000C4A8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8000C4AC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000C4B0: lw          $t6, 0x1A0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000C4B4: nop

    // 0x8000C4B8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8000C4BC: sw          $t7, 0x1A0($t5)
    MEM_W(0X1A0, ctx->r13) = ctx->r15;
    // 0x8000C4C0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000C4C4: nop

    // 0x8000C4C8: lw          $t9, 0x1A0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A0);
    // 0x8000C4CC: nop

    // 0x8000C4D0: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x8000C4D4: sw          $t0, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = ctx->r8;
    // 0x8000C4D8: jal         0x80016264
    // 0x8000C4DC: nop

    func_80016264(rdram, ctx);
        goto after_4;
    // 0x8000C4DC: nop

    after_4:
    // 0x8000C4E0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8000C4E4: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000C4E8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8000C4EC: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x8000C4F0: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8000C4F4: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x8000C4F8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000C4FC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000C500: lhu         $t6, 0x6($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X6);
    // 0x8000C504: nop

    // 0x8000C508: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x8000C50C: sh          $t7, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r15;
    // 0x8000C510: addiu       $t5, $zero, -0x2
    ctx->r13 = ADD32(0, -0X2);
    // 0x8000C514: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000C518: sh          $t5, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r13;
    // 0x8000C51C: jal         0x80031728
    // 0x8000C520: nop

    func_80031728(rdram, ctx);
        goto after_5;
    // 0x8000C520: nop

    after_5:
    // 0x8000C524: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C528: nop

    // 0x8000C52C: beq         $t9, $zero, L_8000C564
    if (ctx->r25 == 0) {
        // 0x8000C530: nop

            goto L_8000C564;
    }
    // 0x8000C530: nop

    // 0x8000C534: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000C538: nop

    // 0x8000C53C: beq         $t0, $zero, L_8000C564
    if (ctx->r8 == 0) {
        // 0x8000C540: nop

            goto L_8000C564;
    }
    // 0x8000C540: nop

    // 0x8000C544: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C548: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x8000C54C: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8000C550: nop

    // 0x8000C554: lw          $t3, 0x1A0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A0);
    // 0x8000C558: nop

    // 0x8000C55C: and         $t1, $t3, $at
    ctx->r9 = ctx->r11 & ctx->r1;
    // 0x8000C560: sw          $t1, 0x1A0($t2)
    MEM_W(0X1A0, ctx->r10) = ctx->r9;
L_8000C564:
    // 0x8000C564: b           L_8000C574
    // 0x8000C568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C574;
    // 0x8000C568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C56C: b           L_8000C574
    // 0x8000C570: nop

        goto L_8000C574;
    // 0x8000C570: nop

L_8000C574:
    // 0x8000C574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C57C: jr          $ra
    // 0x8000C580: nop

    return;
    // 0x8000C580: nop

;}
RECOMP_FUNC void func_8000C584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C584: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000C588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C58C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000C590: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8000C594: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C598: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000C59C: nop

    // 0x8000C5A0: slti        $at, $t6, 0x1F4
    ctx->r1 = SIGNED(ctx->r14) < 0X1F4 ? 1 : 0;
    // 0x8000C5A4: beq         $at, $zero, L_8000C5C8
    if (ctx->r1 == 0) {
        // 0x8000C5A8: nop

            goto L_8000C5C8;
    }
    // 0x8000C5A8: nop

    // 0x8000C5AC: lui         $t7, 0x8099
    ctx->r15 = S32(0X8099 << 16);
    // 0x8000C5B0: addiu       $t7, $t7, 0x20
    ctx->r15 = ADD32(ctx->r15, 0X20);
    // 0x8000C5B4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8000C5B8: lui         $t8, 0x8099
    ctx->r24 = S32(0X8099 << 16);
    // 0x8000C5BC: addiu       $t8, $t8, 0x180
    ctx->r24 = ADD32(ctx->r24, 0X180);
    // 0x8000C5C0: b           L_8000C5E0
    // 0x8000C5C4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_8000C5E0;
    // 0x8000C5C4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_8000C5C8:
    // 0x8000C5C8: lui         $t9, 0x8099
    ctx->r25 = S32(0X8099 << 16);
    // 0x8000C5CC: addiu       $t9, $t9, 0x73B0
    ctx->r25 = ADD32(ctx->r25, 0X73B0);
    // 0x8000C5D0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8000C5D4: lui         $t0, 0x8099
    ctx->r8 = S32(0X8099 << 16);
    // 0x8000C5D8: addiu       $t0, $t0, 0x73D0
    ctx->r8 = ADD32(ctx->r8, 0X73D0);
    // 0x8000C5DC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
L_8000C5E0:
    // 0x8000C5E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000C5E4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000C5E8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000C5EC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000C5F0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8000C5F4: jal         0x800BD1FC
    // 0x8000C5F8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8000C5F8: nop

    after_0:
    // 0x8000C5FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000C604: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8000C608: jal         0x800BD218
    // 0x8000C60C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8000C60C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x8000C610: lh          $t1, 0x38($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X38);
    // 0x8000C614: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000C618: nop

    // 0x8000C61C: bne         $t1, $t2, L_8000C62C
    if (ctx->r9 != ctx->r10) {
        // 0x8000C620: nop

            goto L_8000C62C;
    }
    // 0x8000C620: nop

    // 0x8000C624: b           L_8000C64C
    // 0x8000C628: nop

        goto L_8000C64C;
    // 0x8000C628: nop

L_8000C62C:
    // 0x8000C62C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8000C630: nop

    // 0x8000C634: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8000C638: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8000C63C: lh          $t5, 0x38($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X38);
    // 0x8000C640: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C644: bne         $t5, $at, L_8000C5E0
    if (ctx->r13 != ctx->r1) {
        // 0x8000C648: nop

            goto L_8000C5E0;
    }
    // 0x8000C648: nop

L_8000C64C:
    // 0x8000C64C: lh          $t6, 0x38($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X38);
    // 0x8000C650: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C654: bne         $t6, $at, L_8000C664
    if (ctx->r14 != ctx->r1) {
        // 0x8000C658: nop

            goto L_8000C664;
    }
    // 0x8000C658: nop

    // 0x8000C65C: b           L_8000C768
    // 0x8000C660: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000C768;
    // 0x8000C660: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000C664:
    // 0x8000C664: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C668: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8000C66C: nop

    // 0x8000C670: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8000C674: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8000C678: nop

    // 0x8000C67C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8000C680: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8000C684: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000C688: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000C68C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000C690: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000C694: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8000C698: jal         0x800BD1FC
    // 0x8000C69C: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8000C69C: nop

    after_2:
    // 0x8000C6A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000C6A8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8000C6AC: jal         0x800BD218
    // 0x8000C6B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x8000C6B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x8000C6B4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000C6B8: nop

    // 0x8000C6BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8000C6C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8000C6C4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000C6C8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8000C6CC: nop

    // 0x8000C6D0: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x8000C6D4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8000C6D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8000C6DC: jal         0x8000D164
    // 0x8000C6E0: nop

    TempHeap_Alloc(rdram, ctx);
        goto after_4;
    // 0x8000C6E0: nop

    after_4:
    // 0x8000C6E4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8000C6E8: nop

    // 0x8000C6EC: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    // 0x8000C6F0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8000C6F4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8000C6F8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8000C6FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000C700: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000C704: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000C708: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000C70C: jal         0x800BD1FC
    // 0x8000C710: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8000C710: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    after_5:
    // 0x8000C714: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8000C718: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C71C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8000C720: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x8000C724: jal         0x800BD218
    // 0x8000C728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_6;
    // 0x8000C728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8000C72C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8000C730: nop

    // 0x8000C734: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8000C738: nop

    // 0x8000C73C: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x8000C740: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8000C744: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8000C748: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8000C74C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8000C750: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x8000C754: sw          $t8, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r24;
    // 0x8000C758: b           L_8000C768
    // 0x8000C75C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C768;
    // 0x8000C75C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C760: b           L_8000C768
    // 0x8000C764: nop

        goto L_8000C768;
    // 0x8000C764: nop

L_8000C768:
    // 0x8000C768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C76C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C770: jr          $ra
    // 0x8000C774: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000C774: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
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
RECOMP_FUNC void func_8000CFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CFE4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000CFE8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8000CFEC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8000CFF0:
    // 0x8000CFF0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8000CFF4: nop

    // 0x8000CFF8: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8000CFFC: nop

    // 0x8000D000: bne         $t7, $a1, L_8000D028
    if (ctx->r15 != ctx->r5) {
        // 0x8000D004: nop

            goto L_8000D028;
    }
    // 0x8000D004: nop

    // 0x8000D008: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8000D00C: nop

    // 0x8000D010: blez        $t8, L_8000D020
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8000D014: nop

            goto L_8000D020;
    }
    // 0x8000D014: nop

    // 0x8000D018: b           L_8000D0A0
    // 0x8000D01C: nop

        goto L_8000D0A0;
    // 0x8000D01C: nop

L_8000D020:
    // 0x8000D020: b           L_8000D0B4
    // 0x8000D024: nop

        goto L_8000D0B4;
    // 0x8000D024: nop

L_8000D028:
    // 0x8000D028: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8000D02C: ori         $at, $zero, 0xC002
    ctx->r1 = 0 | 0XC002;
    // 0x8000D030: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8000D034: nop

    // 0x8000D038: bne         $t0, $at, L_8000D058
    if (ctx->r8 != ctx->r1) {
        // 0x8000D03C: nop

            goto L_8000D058;
    }
    // 0x8000D03C: nop

    // 0x8000D040: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8000D044: nop

    // 0x8000D048: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000D04C: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8000D050: b           L_8000D0A0
    // 0x8000D054: nop

        goto L_8000D0A0;
    // 0x8000D054: nop

L_8000D058:
    // 0x8000D058: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x8000D05C: ori         $at, $zero, 0xC004
    ctx->r1 = 0 | 0XC004;
    // 0x8000D060: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000D064: nop

    // 0x8000D068: bne         $t4, $at, L_8000D0A0
    if (ctx->r12 != ctx->r1) {
        // 0x8000D06C: nop

            goto L_8000D0A0;
    }
    // 0x8000D06C: nop

    // 0x8000D070: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8000D074: nop

    // 0x8000D078: bgtz        $t5, L_8000D088
    if (SIGNED(ctx->r13) > 0) {
        // 0x8000D07C: nop

            goto L_8000D088;
    }
    // 0x8000D07C: nop

    // 0x8000D080: b           L_8000D0B4
    // 0x8000D084: nop

        goto L_8000D0B4;
    // 0x8000D084: nop

L_8000D088:
    // 0x8000D088: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8000D08C: nop

    // 0x8000D090: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000D094: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8000D098: b           L_8000D0A0
    // 0x8000D09C: nop

        goto L_8000D0A0;
    // 0x8000D09C: nop

L_8000D0A0:
    // 0x8000D0A0: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8000D0A4: nop

    // 0x8000D0A8: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8000D0AC: b           L_8000CFF0
    // 0x8000D0B0: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
        goto L_8000CFF0;
    // 0x8000D0B0: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
L_8000D0B4:
    // 0x8000D0B4: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x8000D0B8: nop

    // 0x8000D0BC: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x8000D0C0: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x8000D0C4: b           L_8000D0CC
    // 0x8000D0C8: nop

        goto L_8000D0CC;
    // 0x8000D0C8: nop

L_8000D0CC:
    // 0x8000D0CC: jr          $ra
    // 0x8000D0D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000D0D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8000D0D4: nop

    // 0x8000D0D8: nop

    // 0x8000D0DC: nop

;}
RECOMP_FUNC void TempHeap_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D0E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000D0E4: sw          $a0, -0x5B10($at)
    MEM_W(-0X5B10, ctx->r1) = ctx->r4;
    // 0x8000D0E8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000D0EC: lw          $t6, -0x5B10($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5B10);
    // 0x8000D0F0: nop

    // 0x8000D0F4: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    // 0x8000D0F8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8000D0FC: lw          $t9, -0x5B10($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B10);
    // 0x8000D100: srl         $t7, $a1, 4
    ctx->r15 = S32(U32(ctx->r5) >> 4);
    // 0x8000D104: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8000D108: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8000D10C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000D110: lw          $t0, -0x5B10($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5B10);
    // 0x8000D114: nop

    // 0x8000D118: sw          $t0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r8;
    // 0x8000D11C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8000D120: lw          $t1, -0x5B10($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5B10);
    // 0x8000D124: nop

    // 0x8000D128: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8000D12C: nop

    // 0x8000D130: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8000D134: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8000D138: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8000D13C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8000D140: lw          $t5, -0x5B10($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B10);
    // 0x8000D144: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000D148: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8000D14C: nop

    // 0x8000D150: sw          $t6, -0x5B0C($at)
    MEM_W(-0X5B0C, ctx->r1) = ctx->r14;
    // 0x8000D154: jr          $ra
    // 0x8000D158: nop

    return;
    // 0x8000D158: nop

    // 0x8000D15C: jr          $ra
    // 0x8000D160: nop

    return;
    // 0x8000D160: nop

;}
RECOMP_FUNC void TempHeap_Alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D164: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000D168: addiu       $t6, $a0, 0xF
    ctx->r14 = ADD32(ctx->r4, 0XF);
    // 0x8000D16C: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x8000D170: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000D174: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8000D178: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8000D17C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000D180: lw          $t0, -0x5B0C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5B0C);
    // 0x8000D184: lw          $t9, -0x5B10($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B10);
    // 0x8000D188: nop

    // 0x8000D18C: beq         $t9, $t0, L_8000D378
    if (ctx->r25 == ctx->r8) {
        // 0x8000D190: sw          $t9, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r25;
            goto L_8000D378;
    }
    // 0x8000D190: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
L_8000D194:
    // 0x8000D194: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8000D198: nop

    // 0x8000D19C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000D1A0: nop

    // 0x8000D1A4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8000D1A8: beq         $t3, $zero, L_8000D1B8
    if (ctx->r11 == 0) {
        // 0x8000D1AC: nop

            goto L_8000D1B8;
    }
    // 0x8000D1AC: nop

    // 0x8000D1B0: b           L_8000D354
    // 0x8000D1B4: nop

        goto L_8000D354;
    // 0x8000D1B4: nop

L_8000D1B8:
    // 0x8000D1B8: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8000D1BC: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8000D1C0: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8000D1C4: nop

    // 0x8000D1C8: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x8000D1CC: bne         $at, $zero, L_8000D354
    if (ctx->r1 != 0) {
        // 0x8000D1D0: nop

            goto L_8000D354;
    }
    // 0x8000D1D0: nop

    // 0x8000D1D4: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8000D1D8: nop

    // 0x8000D1DC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8000D1E0: nop

    // 0x8000D1E4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8000D1E8: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000D1EC: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8000D1F0: nop

    // 0x8000D1F4: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8000D1F8: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000D1FC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8000D200: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8000D204: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8000D208: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x8000D20C: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8000D210: nop

    // 0x8000D214: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8000D218: nop

    // 0x8000D21C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8000D220: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
    // 0x8000D224: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8000D228: nop

    // 0x8000D22C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8000D230: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8000D234: nop

    // 0x8000D238: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8000D23C: nop

    // 0x8000D240: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x8000D244: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8000D248: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8000D24C: nop

    // 0x8000D250: beq         $t1, $t2, L_8000D348
    if (ctx->r9 == ctx->r10) {
        // 0x8000D254: nop

            goto L_8000D348;
    }
    // 0x8000D254: nop

    // 0x8000D258: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x8000D25C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8000D260: nop

    // 0x8000D264: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8000D268: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8000D26C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8000D270: nop

    // 0x8000D274: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8000D278: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8000D27C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8000D280: nop

    // 0x8000D284: subu        $t9, $t5, $t8
    ctx->r25 = SUB32(ctx->r13, ctx->r24);
    // 0x8000D288: sra         $t0, $t9, 4
    ctx->r8 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8000D28C: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x8000D290: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8000D294: nop

    // 0x8000D298: sw          $zero, 0xC($t1)
    MEM_W(0XC, ctx->r9) = 0;
    // 0x8000D29C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8000D2A0: nop

    // 0x8000D2A4: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8000D2A8: nop

    // 0x8000D2AC: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x8000D2B0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000D2B4: lw          $t6, -0x5B0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5B0C);
    // 0x8000D2B8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x8000D2BC: nop

    // 0x8000D2C0: beq         $t3, $t6, L_8000D348
    if (ctx->r11 == ctx->r14) {
        // 0x8000D2C4: nop

            goto L_8000D348;
    }
    // 0x8000D2C4: nop

    // 0x8000D2C8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8000D2CC: nop

    // 0x8000D2D0: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x8000D2D4: nop

    // 0x8000D2D8: andi        $t9, $t5, 0x1
    ctx->r25 = ctx->r13 & 0X1;
    // 0x8000D2DC: beq         $t9, $zero, L_8000D2F4
    if (ctx->r25 == 0) {
        // 0x8000D2E0: nop

            goto L_8000D2F4;
    }
    // 0x8000D2E0: nop

    // 0x8000D2E4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8000D2E8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8000D2EC: b           L_8000D348
    // 0x8000D2F0: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
        goto L_8000D348;
    // 0x8000D2F0: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_8000D2F4:
    // 0x8000D2F4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8000D2F8: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8000D2FC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8000D300: nop

    // 0x8000D304: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x8000D308: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8000D30C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8000D310: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x8000D314: lw          $t5, 0x8($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X8);
    // 0x8000D318: nop

    // 0x8000D31C: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x8000D320: sw          $t9, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r25;
    // 0x8000D324: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8000D328: nop

    // 0x8000D32C: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x8000D330: nop

    // 0x8000D334: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8000D338: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8000D33C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8000D340: nop

    // 0x8000D344: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_8000D348:
    // 0x8000D348: lw          $v0, 0x8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8);
    // 0x8000D34C: b           L_8000D388
    // 0x8000D350: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
        goto L_8000D388;
    // 0x8000D350: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_8000D354:
    // 0x8000D354: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8000D358: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8000D35C: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x8000D360: lw          $t5, -0x5B0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B0C);
    // 0x8000D364: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8000D368: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8000D36C: nop

    // 0x8000D370: bne         $t6, $t5, L_8000D194
    if (ctx->r14 != ctx->r13) {
        // 0x8000D374: nop

            goto L_8000D194;
    }
    // 0x8000D374: nop

L_8000D378:
    // 0x8000D378: b           L_8000D388
    // 0x8000D37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D388;
    // 0x8000D37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D380: b           L_8000D388
    // 0x8000D384: nop

        goto L_8000D388;
    // 0x8000D384: nop

L_8000D388:
    // 0x8000D388: jr          $ra
    // 0x8000D38C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8000D38C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
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
RECOMP_FUNC void func_8000D57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D57C: nop

;}
RECOMP_FUNC void func_8000D580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D580: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000D584: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8000D588: sw          $t6, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->r14;
    // 0x8000D58C: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x8000D590: b           L_8000D5A0
    // 0x8000D594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D5A0;
    // 0x8000D594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D598: b           L_8000D5A0
    // 0x8000D59C: nop

        goto L_8000D5A0;
    // 0x8000D59C: nop

L_8000D5A0:
    // 0x8000D5A0: jr          $ra
    // 0x8000D5A4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000D5A4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8000D5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D5A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000D5AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D5B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000D5B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8000D5B8:
    // 0x8000D5B8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D5BC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000D5C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D5C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000D5C8: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x8000D5CC: nop

    // 0x8000D5D0: bne         $t8, $zero, L_8000D5E0
    if (ctx->r24 != 0) {
        // 0x8000D5D4: nop

            goto L_8000D5E0;
    }
    // 0x8000D5D4: nop

    // 0x8000D5D8: b           L_8000D5F8
    // 0x8000D5DC: nop

        goto L_8000D5F8;
    // 0x8000D5DC: nop

L_8000D5E0:
    // 0x8000D5E0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D5E4: nop

    // 0x8000D5E8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8000D5EC: slti        $at, $t0, 0x14
    ctx->r1 = SIGNED(ctx->r8) < 0X14 ? 1 : 0;
    // 0x8000D5F0: bne         $at, $zero, L_8000D5B8
    if (ctx->r1 != 0) {
        // 0x8000D5F4: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_8000D5B8;
    }
    // 0x8000D5F4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_8000D5F8:
    // 0x8000D5F8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D5FC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8000D600: bne         $t1, $at, L_8000D610
    if (ctx->r9 != ctx->r1) {
        // 0x8000D604: nop

            goto L_8000D610;
    }
    // 0x8000D604: nop

    // 0x8000D608: b           L_8000D678
    // 0x8000D60C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D678;
    // 0x8000D60C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D610:
    // 0x8000D610: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D614: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8000D618: addiu       $t4, $t4, -0x7E8
    ctx->r12 = ADD32(ctx->r12, -0X7E8);
    // 0x8000D61C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000D620: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8000D624: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000D628: sw          $t5, -0x7F4($at)
    MEM_W(-0X7F4, ctx->r1) = ctx->r13;
    // 0x8000D62C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000D630: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000D634: sw          $t6, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = ctx->r14;
    // 0x8000D638: jal         0x80004654
    // 0x8000D63C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_80004654(rdram, ctx);
        goto after_0;
    // 0x8000D63C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x8000D640: bgez        $v0, L_8000D650
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000D644: nop

            goto L_8000D650;
    }
    // 0x8000D644: nop

    // 0x8000D648: b           L_8000D678
    // 0x8000D64C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D678;
    // 0x8000D64C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D650:
    // 0x8000D650: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000D654: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000D658: lw          $t8, -0x7F4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7F4);
    // 0x8000D65C: lw          $t7, 0x6C10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C10);
    // 0x8000D660: nop

    // 0x8000D664: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000D668: b           L_8000D678
    // 0x8000D66C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D678;
    // 0x8000D66C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D670: b           L_8000D678
    // 0x8000D674: nop

        goto L_8000D678;
    // 0x8000D674: nop

L_8000D678:
    // 0x8000D678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000D67C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000D680: jr          $ra
    // 0x8000D684: nop

    return;
    // 0x8000D684: nop

;}
RECOMP_FUNC void func_8000D688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D688: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000D68C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8000D690:
    // 0x8000D690: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8000D694: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000D698: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D69C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000D6A0: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x8000D6A4: nop

    // 0x8000D6A8: beq         $t8, $zero, L_8000D71C
    if (ctx->r24 == 0) {
        // 0x8000D6AC: nop

            goto L_8000D71C;
    }
    // 0x8000D6AC: nop

    // 0x8000D6B0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8000D6B4: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8000D6B8: addiu       $t1, $t1, -0x7E8
    ctx->r9 = ADD32(ctx->r9, -0X7E8);
    // 0x8000D6BC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8000D6C0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8000D6C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000D6C8: sw          $t2, -0x7F4($at)
    MEM_W(-0X7F4, ctx->r1) = ctx->r10;
    // 0x8000D6CC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8000D6D0: lw          $t3, -0x7F4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7F4);
    // 0x8000D6D4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8000D6D8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8000D6DC: nop

    // 0x8000D6E0: lw          $t5, 0x1AC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1AC);
    // 0x8000D6E4: nop

    // 0x8000D6E8: bne         $t5, $t6, L_8000D71C
    if (ctx->r13 != ctx->r14) {
        // 0x8000D6EC: nop

            goto L_8000D71C;
    }
    // 0x8000D6EC: nop

    // 0x8000D6F0: lw          $t7, 0x1A8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X1A8);
    // 0x8000D6F4: nop

    // 0x8000D6F8: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8000D6FC: bne         $t8, $zero, L_8000D71C
    if (ctx->r24 != 0) {
        // 0x8000D700: nop

            goto L_8000D71C;
    }
    // 0x8000D700: nop

    // 0x8000D704: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8000D708: lw          $t9, -0x7F4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7F4);
    // 0x8000D70C: nop

    // 0x8000D710: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000D714: b           L_8000D744
    // 0x8000D718: nop

        goto L_8000D744;
    // 0x8000D718: nop

L_8000D71C:
    // 0x8000D71C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8000D720: nop

    // 0x8000D724: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000D728: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x8000D72C: bne         $at, $zero, L_8000D690
    if (ctx->r1 != 0) {
        // 0x8000D730: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_8000D690;
    }
    // 0x8000D730: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8000D734: b           L_8000D744
    // 0x8000D738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D744;
    // 0x8000D738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D73C: b           L_8000D744
    // 0x8000D740: nop

        goto L_8000D744;
    // 0x8000D740: nop

L_8000D744:
    // 0x8000D744: jr          $ra
    // 0x8000D748: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000D748: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8000D74C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D74C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000D750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D754: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000D758: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8000D75C:
    // 0x8000D75C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D760: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000D764: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D768: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000D76C: lw          $t8, -0x7E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E8);
    // 0x8000D770: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8000D774: nop

    // 0x8000D778: bne         $t8, $t9, L_8000D8D4
    if (ctx->r24 != ctx->r25) {
        // 0x8000D77C: nop

            goto L_8000D8D4;
    }
    // 0x8000D77C: nop

    // 0x8000D780: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D784: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000D788: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000D78C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000D790: sw          $zero, -0x7E8($at)
    MEM_W(-0X7E8, ctx->r1) = 0;
    // 0x8000D794: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8000D798: nop

    // 0x8000D79C: sw          $zero, 0x1A0($t2)
    MEM_W(0X1A0, ctx->r10) = 0;
    // 0x8000D7A0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8000D7A4: nop

    // 0x8000D7A8: sw          $zero, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = 0;
    // 0x8000D7AC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8000D7B0: nop

    // 0x8000D7B4: lw          $t5, 0x20C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20C);
    // 0x8000D7B8: nop

    // 0x8000D7BC: beq         $t5, $zero, L_8000D894
    if (ctx->r13 == 0) {
        // 0x8000D7C0: nop

            goto L_8000D894;
    }
    // 0x8000D7C0: nop

    // 0x8000D7C4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000D7C8: nop

    // 0x8000D7CC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000D7D0: nop

    // 0x8000D7D4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8000D7D8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000D7DC: nop

    // 0x8000D7E0: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x8000D7E4: nop

    // 0x8000D7E8: slti        $at, $t9, 0x4000
    ctx->r1 = SIGNED(ctx->r25) < 0X4000 ? 1 : 0;
    // 0x8000D7EC: bne         $at, $zero, L_8000D804
    if (ctx->r1 != 0) {
        // 0x8000D7F0: nop

            goto L_8000D804;
    }
    // 0x8000D7F0: nop

    // 0x8000D7F4: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x8000D7F8: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000D7FC: bne         $at, $zero, L_8000D83C
    if (ctx->r1 != 0) {
        // 0x8000D800: nop

            goto L_8000D83C;
    }
    // 0x8000D800: nop

L_8000D804:
    // 0x8000D804: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000D808: nop

    // 0x8000D80C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000D810: nop

    // 0x8000D814: beq         $t1, $zero, L_8000D83C
    if (ctx->r9 == 0) {
        // 0x8000D818: nop

            goto L_8000D83C;
    }
    // 0x8000D818: nop

    // 0x8000D81C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8000D820: nop

    // 0x8000D824: lw          $a0, 0xC($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XC);
    // 0x8000D828: jal         0x8000D390
    // 0x8000D82C: nop

    TempHeap_Free(rdram, ctx);
        goto after_0;
    // 0x8000D82C: nop

    after_0:
    // 0x8000D830: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8000D834: nop

    // 0x8000D838: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
L_8000D83C:
    // 0x8000D83C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8000D840: nop

    // 0x8000D844: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8000D848: nop

    // 0x8000D84C: beq         $t5, $zero, L_8000D874
    if (ctx->r13 == 0) {
        // 0x8000D850: nop

            goto L_8000D874;
    }
    // 0x8000D850: nop

    // 0x8000D854: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8000D858: nop

    // 0x8000D85C: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x8000D860: jal         0x8000D390
    // 0x8000D864: nop

    TempHeap_Free(rdram, ctx);
        goto after_1;
    // 0x8000D864: nop

    after_1:
    // 0x8000D868: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000D86C: nop

    // 0x8000D870: sw          $zero, 0x10($t7)
    MEM_W(0X10, ctx->r15) = 0;
L_8000D874:
    // 0x8000D874: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000D878: nop

    // 0x8000D87C: lw          $a0, 0x20C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X20C);
    // 0x8000D880: jal         0x8000D390
    // 0x8000D884: nop

    TempHeap_Free(rdram, ctx);
        goto after_2;
    // 0x8000D884: nop

    after_2:
    // 0x8000D888: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8000D88C: nop

    // 0x8000D890: sw          $zero, 0x20C($t9)
    MEM_W(0X20C, ctx->r25) = 0;
L_8000D894:
    // 0x8000D894: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8000D898: nop

    // 0x8000D89C: lw          $t1, 0x210($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X210);
    // 0x8000D8A0: nop

    // 0x8000D8A4: beq         $t1, $zero, L_8000D8CC
    if (ctx->r9 == 0) {
        // 0x8000D8A8: nop

            goto L_8000D8CC;
    }
    // 0x8000D8A8: nop

    // 0x8000D8AC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8000D8B0: nop

    // 0x8000D8B4: lw          $a0, 0x210($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X210);
    // 0x8000D8B8: jal         0x8000D390
    // 0x8000D8BC: nop

    TempHeap_Free(rdram, ctx);
        goto after_3;
    // 0x8000D8BC: nop

    after_3:
    // 0x8000D8C0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8000D8C4: nop

    // 0x8000D8C8: sw          $zero, 0x210($t3)
    MEM_W(0X210, ctx->r11) = 0;
L_8000D8CC:
    // 0x8000D8CC: b           L_8000D8FC
    // 0x8000D8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D8FC;
    // 0x8000D8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000D8D4:
    // 0x8000D8D4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D8D8: nop

    // 0x8000D8DC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000D8E0: slti        $at, $t5, 0x14
    ctx->r1 = SIGNED(ctx->r13) < 0X14 ? 1 : 0;
    // 0x8000D8E4: bne         $at, $zero, L_8000D75C
    if (ctx->r1 != 0) {
        // 0x8000D8E8: sw          $t5, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r13;
            goto L_8000D75C;
    }
    // 0x8000D8E8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8000D8EC: b           L_8000D8FC
    // 0x8000D8F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D8FC;
    // 0x8000D8F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000D8F4: b           L_8000D8FC
    // 0x8000D8F8: nop

        goto L_8000D8FC;
    // 0x8000D8F8: nop

L_8000D8FC:
    // 0x8000D8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000D900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000D904: jr          $ra
    // 0x8000D908: nop

    return;
    // 0x8000D908: nop

;}
RECOMP_FUNC void func_8000D90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D90C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000D910: nop

    // 0x8000D914: swc1        $f4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f4.u32l;
    // 0x8000D918: lwc1        $f6, 0x1EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x8000D91C: nop

    // 0x8000D920: swc1        $f6, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f6.u32l;
    // 0x8000D924: jr          $ra
    // 0x8000D928: nop

    return;
    // 0x8000D928: nop

    // 0x8000D92C: jr          $ra
    // 0x8000D930: nop

    return;
    // 0x8000D930: nop

;}
RECOMP_FUNC void func_8000D934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D934: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000D938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D93C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000D940: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000D944: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000D948: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000D94C: jal         0x8000D688
    // 0x8000D950: nop

    func_8000D688(rdram, ctx);
        goto after_0;
    // 0x8000D950: nop

    after_0:
    // 0x8000D954: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000D958: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D95C: nop

    // 0x8000D960: bne         $t6, $zero, L_8000D970
    if (ctx->r14 != 0) {
        // 0x8000D964: nop

            goto L_8000D970;
    }
    // 0x8000D964: nop

    // 0x8000D968: b           L_8000DA34
    // 0x8000D96C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000DA34;
    // 0x8000D96C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D970:
    // 0x8000D970: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000D974: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8000D978: blez        $t7, L_8000DA24
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000D97C: nop

            goto L_8000DA24;
    }
    // 0x8000D97C: nop

L_8000D980:
    // 0x8000D980: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000D984: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D988: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000D98C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000D990: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000D994: lwc1        $f4, 0x1EC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1EC);
    // 0x8000D998: nop

    // 0x8000D99C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000D9A0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8000D9A4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000D9A8: bgez        $t0, L_8000D9BC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8000D9AC: andi        $t1, $t0, 0x7F
        ctx->r9 = ctx->r8 & 0X7F;
            goto L_8000D9BC;
    }
    // 0x8000D9AC: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x8000D9B0: beq         $t1, $zero, L_8000D9BC
    if (ctx->r9 == 0) {
        // 0x8000D9B4: nop

            goto L_8000D9BC;
    }
    // 0x8000D9B4: nop

    // 0x8000D9B8: addiu       $t1, $t1, -0x80
    ctx->r9 = ADD32(ctx->r9, -0X80);
L_8000D9BC:
    // 0x8000D9BC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8000D9C0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D9C4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000D9C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000D9CC: lw          $t5, 0x210($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X210);
    // 0x8000D9D0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000D9D4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000D9D8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8000D9DC: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x8000D9E0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8000D9E4: nop

    // 0x8000D9E8: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x8000D9EC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8000D9F0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D9F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000D9F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000D9FC: lwc1        $f8, 0x1EC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1EC);
    // 0x8000DA00: nop

    // 0x8000DA04: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000DA08: swc1        $f16, 0x1EC($t1)
    MEM_W(0X1EC, ctx->r9) = ctx->f16.u32l;
    // 0x8000DA0C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8000DA10: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DA14: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8000DA18: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000DA1C: bne         $at, $zero, L_8000D980
    if (ctx->r1 != 0) {
        // 0x8000DA20: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_8000D980;
    }
    // 0x8000DA20: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
L_8000DA24:
    // 0x8000DA24: b           L_8000DA34
    // 0x8000DA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DA34;
    // 0x8000DA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DA2C: b           L_8000DA34
    // 0x8000DA30: nop

        goto L_8000DA34;
    // 0x8000DA30: nop

L_8000DA34:
    // 0x8000DA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000DA38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000DA3C: jr          $ra
    // 0x8000DA40: nop

    return;
    // 0x8000DA40: nop

;}
RECOMP_FUNC void func_8000DA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DA44: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000DA48: blez        $a1, L_8000DAFC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000DA4C: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_8000DAFC;
    }
    // 0x8000DA4C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8000DA50:
    // 0x8000DA50: lwc1        $f4, 0x1EC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x8000DA54: lwc1        $f6, 0x1E8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x8000DA58: nop

    // 0x8000DA5C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8000DA60: nop

    // 0x8000DA64: bc1f        L_8000DA74
    if (!c1cs) {
        // 0x8000DA68: nop

            goto L_8000DA74;
    }
    // 0x8000DA68: nop

    // 0x8000DA6C: b           L_8000DB0C
    // 0x8000DA70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000DB0C;
    // 0x8000DA70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000DA74:
    // 0x8000DA74: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000DA78: lwc1        $f8, 0x1E8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x8000DA7C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000DA80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000DA84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000DA88: nop

    // 0x8000DA8C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000DA90: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8000DA94: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000DA98: bgez        $t7, L_8000DAAC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000DA9C: andi        $t8, $t7, 0x7F
        ctx->r24 = ctx->r15 & 0X7F;
            goto L_8000DAAC;
    }
    // 0x8000DA9C: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x8000DAA0: beq         $t8, $zero, L_8000DAAC
    if (ctx->r24 == 0) {
        // 0x8000DAA4: nop

            goto L_8000DAAC;
    }
    // 0x8000DAA4: nop

    // 0x8000DAA8: addiu       $t8, $t8, -0x80
    ctx->r24 = ADD32(ctx->r24, -0X80);
L_8000DAAC:
    // 0x8000DAAC: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8000DAB0: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000DAB4: lw          $t9, 0x210($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X210);
    // 0x8000DAB8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8000DABC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000DAC0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000DAC4: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8000DAC8: sh          $t3, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r11;
    // 0x8000DACC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000DAD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000DAD4: lwc1        $f16, 0x1E8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1E8);
    // 0x8000DAD8: nop

    // 0x8000DADC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000DAE0: swc1        $f4, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f4.u32l;
    // 0x8000DAE4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8000DAE8: nop

    // 0x8000DAEC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000DAF0: slt         $at, $t5, $a1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000DAF4: bne         $at, $zero, L_8000DA50
    if (ctx->r1 != 0) {
        // 0x8000DAF8: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_8000DA50;
    }
    // 0x8000DAF8: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
L_8000DAFC:
    // 0x8000DAFC: b           L_8000DB0C
    // 0x8000DB00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DB0C;
    // 0x8000DB00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DB04: b           L_8000DB0C
    // 0x8000DB08: nop

        goto L_8000DB0C;
    // 0x8000DB08: nop

L_8000DB0C:
    // 0x8000DB0C: jr          $ra
    // 0x8000DB10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000DB10: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8000DB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DB14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000DB18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000DB1C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8000DB20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DB24: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000DB28: lh          $t6, -0x73C0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X73C0);
    // 0x8000DB2C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000DB30: bne         $t6, $at, L_8000DB40
    if (ctx->r14 != ctx->r1) {
        // 0x8000DB34: nop

            goto L_8000DB40;
    }
    // 0x8000DB34: nop

    // 0x8000DB38: b           L_8000DD84
    // 0x8000DB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DB40:
    // 0x8000DB40: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000DB44: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000DB48: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000DB4C: nop

    // 0x8000DB50: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8000DB54: beq         $t9, $zero, L_8000DB64
    if (ctx->r25 == 0) {
        // 0x8000DB58: nop

            goto L_8000DB64;
    }
    // 0x8000DB58: nop

    // 0x8000DB5C: b           L_8000DD84
    // 0x8000DB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DB64:
    // 0x8000DB64: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8000DB68: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x8000DB6C: nop

    // 0x8000DB70: beq         $t0, $zero, L_8000DBAC
    if (ctx->r8 == 0) {
        // 0x8000DB74: nop

            goto L_8000DBAC;
    }
    // 0x8000DB74: nop

    // 0x8000DB78: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x8000DB7C: nop

    // 0x8000DB80: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8000DB84: beq         $t2, $zero, L_8000DBAC
    if (ctx->r10 == 0) {
        // 0x8000DB88: nop

            goto L_8000DBAC;
    }
    // 0x8000DB88: nop

    // 0x8000DB8C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8000DB90: nop

    // 0x8000DB94: lw          $t4, 0x1A0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A0);
    // 0x8000DB98: nop

    // 0x8000DB9C: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x8000DBA0: sw          $t5, 0x1A0($t3)
    MEM_W(0X1A0, ctx->r11) = ctx->r13;
    // 0x8000DBA4: b           L_8000DD84
    // 0x8000DBA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DBA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DBAC:
    // 0x8000DBAC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8000DBB0: nop

    // 0x8000DBB4: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x8000DBB8: nop

    // 0x8000DBBC: bne         $t7, $zero, L_8000DD34
    if (ctx->r15 != 0) {
        // 0x8000DBC0: nop

            goto L_8000DD34;
    }
    // 0x8000DBC0: nop

    // 0x8000DBC4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000DBC8: lh          $t8, -0x7290($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7290);
    // 0x8000DBCC: nop

    // 0x8000DBD0: slti        $at, $t8, 0x1F4
    ctx->r1 = SIGNED(ctx->r24) < 0X1F4 ? 1 : 0;
    // 0x8000DBD4: beq         $at, $zero, L_8000DBF8
    if (ctx->r1 == 0) {
        // 0x8000DBD8: nop

            goto L_8000DBF8;
    }
    // 0x8000DBD8: nop

    // 0x8000DBDC: lui         $t9, 0x8094
    ctx->r25 = S32(0X8094 << 16);
    // 0x8000DBE0: addiu       $t9, $t9, 0x7340
    ctx->r25 = ADD32(ctx->r25, 0X7340);
    // 0x8000DBE4: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8000DBE8: lui         $t0, 0x8095
    ctx->r8 = S32(0X8095 << 16);
    // 0x8000DBEC: addiu       $t0, $t0, -0x6EB0
    ctx->r8 = ADD32(ctx->r8, -0X6EB0);
    // 0x8000DBF0: b           L_8000DC10
    // 0x8000DBF4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
        goto L_8000DC10;
    // 0x8000DBF4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_8000DBF8:
    // 0x8000DBF8: lui         $t1, 0x8099
    ctx->r9 = S32(0X8099 << 16);
    // 0x8000DBFC: addiu       $t1, $t1, 0x3AE0
    ctx->r9 = ADD32(ctx->r9, 0X3AE0);
    // 0x8000DC00: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8000DC04: lui         $t2, 0x8099
    ctx->r10 = S32(0X8099 << 16);
    // 0x8000DC08: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8000DC0C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_8000DC10:
    // 0x8000DC10: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000DC14: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000DC18: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000DC1C: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000DC20: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8000DC24: jal         0x800BD1FC
    // 0x8000DC28: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x8000DC28: nop

    after_0:
    // 0x8000DC2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000DC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000DC34: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8000DC38: jal         0x800BD218
    // 0x8000DC3C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x8000DC3C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_1:
    // 0x8000DC40: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8000DC44: lh          $t5, -0x7290($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X7290);
    // 0x8000DC48: lh          $t4, 0x2C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2C);
    // 0x8000DC4C: nop

    // 0x8000DC50: bne         $t4, $t5, L_8000DCA8
    if (ctx->r12 != ctx->r13) {
        // 0x8000DC54: nop

            goto L_8000DCA8;
    }
    // 0x8000DC54: nop

    // 0x8000DC58: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000DC5C: lh          $t6, -0x7288($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7288);
    // 0x8000DC60: lh          $t3, 0x2E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2E);
    // 0x8000DC64: nop

    // 0x8000DC68: bne         $t3, $t6, L_8000DCA8
    if (ctx->r11 != ctx->r14) {
        // 0x8000DC6C: nop

            goto L_8000DCA8;
    }
    // 0x8000DC6C: nop

    // 0x8000DC70: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000DC74: lh          $t8, -0x7280($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7280);
    // 0x8000DC78: lh          $t7, 0x30($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X30);
    // 0x8000DC7C: nop

    // 0x8000DC80: bne         $t7, $t8, L_8000DCA8
    if (ctx->r15 != ctx->r24) {
        // 0x8000DC84: nop

            goto L_8000DCA8;
    }
    // 0x8000DC84: nop

    // 0x8000DC88: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000DC8C: nop

    // 0x8000DC90: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x8000DC94: nop

    // 0x8000DC98: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8000DC9C: sw          $t1, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = ctx->r9;
    // 0x8000DCA0: b           L_8000DCC8
    // 0x8000DCA4: nop

        goto L_8000DCC8;
    // 0x8000DCA4: nop

L_8000DCA8:
    // 0x8000DCA8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000DCAC: nop

    // 0x8000DCB0: addiu       $t4, $t2, 0xC
    ctx->r12 = ADD32(ctx->r10, 0XC);
    // 0x8000DCB4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8000DCB8: lh          $t5, 0x2C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X2C);
    // 0x8000DCBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000DCC0: bne         $t5, $at, L_8000DC10
    if (ctx->r13 != ctx->r1) {
        // 0x8000DCC4: nop

            goto L_8000DC10;
    }
    // 0x8000DCC4: nop

L_8000DCC8:
    // 0x8000DCC8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8000DCCC: nop

    // 0x8000DCD0: lw          $t6, 0x1A8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X1A8);
    // 0x8000DCD4: nop

    // 0x8000DCD8: bne         $t6, $zero, L_8000DCE8
    if (ctx->r14 != 0) {
        // 0x8000DCDC: nop

            goto L_8000DCE8;
    }
    // 0x8000DCDC: nop

    // 0x8000DCE0: b           L_8000DD84
    // 0x8000DCE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000DD84;
    // 0x8000DCE4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000DCE8:
    // 0x8000DCE8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000DCEC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000DCF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000DCF4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000DCF8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000DCFC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000DD00: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8000DD04: jal         0x800BD1FC
    // 0x8000DD08: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8000DD08: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_2:
    // 0x8000DD0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000DD10: jal         0x800B55B0
    // 0x8000DD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B55B0(rdram, ctx);
        goto after_3;
    // 0x8000DD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000DD18: beq         $v0, $zero, L_8000DD2C
    if (ctx->r2 == 0) {
        // 0x8000DD1C: nop

            goto L_8000DD2C;
    }
    // 0x8000DD1C: nop

    // 0x8000DD20: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8000DD24: nop

    // 0x8000DD28: sw          $zero, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = 0;
L_8000DD2C:
    // 0x8000DD2C: b           L_8000DD84
    // 0x8000DD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DD34:
    // 0x8000DD34: jal         0x800B56F0
    // 0x8000DD38: nop

    func_800B56F0(rdram, ctx);
        goto after_4;
    // 0x8000DD38: nop

    after_4:
    // 0x8000DD3C: beq         $v0, $zero, L_8000DD74
    if (ctx->r2 == 0) {
        // 0x8000DD40: nop

            goto L_8000DD74;
    }
    // 0x8000DD40: nop

    // 0x8000DD44: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000DD48: nop

    // 0x8000DD4C: sw          $zero, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = 0;
    // 0x8000DD50: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8000DD54: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x8000DD58: nop

    // 0x8000DD5C: beq         $t2, $zero, L_8000DD74
    if (ctx->r10 == 0) {
        // 0x8000DD60: nop

            goto L_8000DD74;
    }
    // 0x8000DD60: nop

    // 0x8000DD64: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8000DD68: lw          $t4, 0x3068($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3068);
    // 0x8000DD6C: nop

    // 0x8000DD70: sh          $zero, 0x4($t4)
    MEM_H(0X4, ctx->r12) = 0;
L_8000DD74:
    // 0x8000DD74: b           L_8000DD84
    // 0x8000DD78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DD84;
    // 0x8000DD78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DD7C: b           L_8000DD84
    // 0x8000DD80: nop

        goto L_8000DD84;
    // 0x8000DD80: nop

L_8000DD84:
    // 0x8000DD84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DD88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DD8C: jr          $ra
    // 0x8000DD90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000DD90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
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
RECOMP_FUNC void func_8000DDD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DDD4: nop

    // 0x8000DDD8: nop

    // 0x8000DDDC: nop

;}
RECOMP_FUNC void func_8000DDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DDE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000DDE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000DDE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000DDEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DDF0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000DDF4: nop

    // 0x8000DDF8: sw          $zero, 0x1A8($t6)
    MEM_W(0X1A8, ctx->r14) = 0;
    // 0x8000DDFC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8000DE00: lw          $t7, -0x7FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7FC);
    // 0x8000DE04: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8000DE08: nop

    // 0x8000DE0C: sw          $t7, 0x1AC($t8)
    MEM_W(0X1AC, ctx->r24) = ctx->r15;
    // 0x8000DE10: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000DE14: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x8000DE18: sh          $t9, 0x208($t0)
    MEM_H(0X208, ctx->r8) = ctx->r25;
    // 0x8000DE1C: jal         0x8000D164
    // 0x8000DE20: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    TempHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000DE20: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_0:
    // 0x8000DE24: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000DE28: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000DE2C: bne         $s0, $zero, L_8000DE3C
    if (ctx->r16 != 0) {
        // 0x8000DE30: sw          $s0, 0x210($t1)
        MEM_W(0X210, ctx->r9) = ctx->r16;
            goto L_8000DE3C;
    }
    // 0x8000DE30: sw          $s0, 0x210($t1)
    MEM_W(0X210, ctx->r9) = ctx->r16;
    // 0x8000DE34: b           L_8000DE74
    // 0x8000DE38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000DE74;
    // 0x8000DE38: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000DE3C:
    // 0x8000DE3C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000DE40: nop

    // 0x8000DE44: sw          $zero, 0x20C($t2)
    MEM_W(0X20C, ctx->r10) = 0;
    // 0x8000DE48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000DE4C: jal         0x8000D90C
    // 0x8000DE50: nop

    func_8000D90C(rdram, ctx);
        goto after_1;
    // 0x8000DE50: nop

    after_1:
    // 0x8000DE54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000DE58: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8000DE5C: nop

    // 0x8000DE60: swc1        $f4, 0x1F0($t3)
    MEM_W(0X1F0, ctx->r11) = ctx->f4.u32l;
    // 0x8000DE64: b           L_8000DE74
    // 0x8000DE68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DE74;
    // 0x8000DE68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DE6C: b           L_8000DE74
    // 0x8000DE70: nop

        goto L_8000DE74;
    // 0x8000DE70: nop

L_8000DE74:
    // 0x8000DE74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DE78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DE7C: jr          $ra
    // 0x8000DE80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000DE80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000DE84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DE84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000DE88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DE8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000DE90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000DE94: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8000DE98: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000DE9C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8000DEA0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000DEA4: nop

    // 0x8000DEA8: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x8000DEAC: nop

    // 0x8000DEB0: beq         $t8, $zero, L_8000DF68
    if (ctx->r24 == 0) {
        // 0x8000DEB4: nop

            goto L_8000DF68;
    }
    // 0x8000DEB4: nop

    // 0x8000DEB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000DEBC: nop

    // 0x8000DEC0: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x8000DEC4: nop

    // 0x8000DEC8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8000DECC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DED0: nop

    // 0x8000DED4: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x8000DED8: nop

    // 0x8000DEDC: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8000DEE0: bne         $at, $zero, L_8000DF04
    if (ctx->r1 != 0) {
        // 0x8000DEE4: nop

            goto L_8000DF04;
    }
    // 0x8000DEE4: nop

    // 0x8000DEE8: slti        $at, $t2, 0x2A
    ctx->r1 = SIGNED(ctx->r10) < 0X2A ? 1 : 0;
    // 0x8000DEEC: beq         $at, $zero, L_8000DF04
    if (ctx->r1 == 0) {
        // 0x8000DEF0: nop

            goto L_8000DF04;
    }
    // 0x8000DEF0: nop

    // 0x8000DEF4: lw          $t3, 0x7C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X7C);
    // 0x8000DEF8: nop

    // 0x8000DEFC: bne         $t3, $zero, L_8000DF68
    if (ctx->r11 != 0) {
        // 0x8000DF00: nop

            goto L_8000DF68;
    }
    // 0x8000DF00: nop

L_8000DF04:
    // 0x8000DF04: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DF08: nop

    // 0x8000DF0C: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8000DF10: nop

    // 0x8000DF14: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8000DF18: beq         $t6, $zero, L_8000DF3C
    if (ctx->r14 == 0) {
        // 0x8000DF1C: nop

            goto L_8000DF3C;
    }
    // 0x8000DF1C: nop

    // 0x8000DF20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000DF24: jal         0x8000E524
    // 0x8000DF28: nop

    func_8000E524(rdram, ctx);
        goto after_0;
    // 0x8000DF28: nop

    after_0:
    // 0x8000DF2C: bgez        $v0, L_8000DF3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000DF30: nop

            goto L_8000DF3C;
    }
    // 0x8000DF30: nop

    // 0x8000DF34: b           L_8000E3C4
    // 0x8000DF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E3C4;
    // 0x8000DF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DF3C:
    // 0x8000DF3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000DF40: jal         0x8000E678
    // 0x8000DF44: nop

    func_8000E678(rdram, ctx);
        goto after_1;
    // 0x8000DF44: nop

    after_1:
    // 0x8000DF48: bgez        $v0, L_8000DF58
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000DF4C: nop

            goto L_8000DF58;
    }
    // 0x8000DF4C: nop

    // 0x8000DF50: b           L_8000E3C4
    // 0x8000DF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E3C4;
    // 0x8000DF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DF58:
    // 0x8000DF58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000DF5C: jal         0x8000E9F8
    // 0x8000DF60: nop

    func_8000E9F8(rdram, ctx);
        goto after_2;
    // 0x8000DF60: nop

    after_2:
    // 0x8000DF64: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_8000DF68:
    // 0x8000DF68: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000DF6C: nop

    // 0x8000DF70: bne         $t7, $zero, L_8000E354
    if (ctx->r15 != 0) {
        // 0x8000DF74: nop

            goto L_8000E354;
    }
    // 0x8000DF74: nop

    // 0x8000DF78: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000DF7C: nop

    // 0x8000DF80: beq         $t8, $zero, L_8000E354
    if (ctx->r24 == 0) {
        // 0x8000DF84: nop

            goto L_8000E354;
    }
    // 0x8000DF84: nop

L_8000DF88:
    // 0x8000DF88: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000DF8C: nop

    // 0x8000DF90: lwc1        $f4, 0x1EC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1EC);
    // 0x8000DF94: lwc1        $f6, 0x1E8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1E8);
    // 0x8000DF98: nop

    // 0x8000DF9C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8000DFA0: nop

    // 0x8000DFA4: bc1f        L_8000DFB4
    if (!c1cs) {
        // 0x8000DFA8: nop

            goto L_8000DFB4;
    }
    // 0x8000DFA8: nop

    // 0x8000DFAC: b           L_8000E354
    // 0x8000DFB0: nop

        goto L_8000E354;
    // 0x8000DFB0: nop

L_8000DFB4:
    // 0x8000DFB4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000DFB8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000DFBC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8000DFC0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000DFC4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000DFC8: lwc1        $f8, 0x1E8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1E8);
    // 0x8000DFCC: lw          $t2, 0x210($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X210);
    // 0x8000DFD0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000DFD4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000DFD8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8000DFDC: ori         $at, $at, 0x3FFE
    ctx->r1 = ctx->r1 | 0X3FFE;
    // 0x8000DFE0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000DFE4: bgez        $t3, L_8000DFF8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000DFE8: andi        $t4, $t3, 0x7F
        ctx->r12 = ctx->r11 & 0X7F;
            goto L_8000DFF8;
    }
    // 0x8000DFE8: andi        $t4, $t3, 0x7F
    ctx->r12 = ctx->r11 & 0X7F;
    // 0x8000DFEC: beq         $t4, $zero, L_8000DFF8
    if (ctx->r12 == 0) {
        // 0x8000DFF0: nop

            goto L_8000DFF8;
    }
    // 0x8000DFF0: nop

    // 0x8000DFF4: addiu       $t4, $t4, -0x80
    ctx->r12 = ADD32(ctx->r12, -0X80);
L_8000DFF8:
    // 0x8000DFF8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8000DFFC: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8000E000: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8000E004: nop

    // 0x8000E008: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8000E00C: sltiu       $at, $t8, 0x30
    ctx->r1 = ctx->r24 < 0X30 ? 1 : 0;
    // 0x8000E010: beq         $at, $zero, L_8000E318
    if (ctx->r1 == 0) {
        // 0x8000E014: nop

            goto L_8000E318;
    }
    // 0x8000E014: nop

    // 0x8000E018: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000E01C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000E020: addu        $at, $at, $t8
    gpr jr_addend_8000E02C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8000E024: lw          $t8, -0x2CA0($at)
    ctx->r24 = ADD32(ctx->r1, -0X2CA0);
    // 0x8000E028: nop

    // 0x8000E02C: jr          $t8
    // 0x8000E030: nop

    switch (jr_addend_8000E02C >> 2) {
        case 0: goto L_8000E034; break;
        case 1: goto L_8000E098; break;
        case 2: goto L_8000E0AC; break;
        case 3: goto L_8000E0C0; break;
        case 4: goto L_8000E318; break;
        case 5: goto L_8000E318; break;
        case 6: goto L_8000E318; break;
        case 7: goto L_8000E318; break;
        case 8: goto L_8000E0D4; break;
        case 9: goto L_8000E318; break;
        case 10: goto L_8000E318; break;
        case 11: goto L_8000E318; break;
        case 12: goto L_8000E318; break;
        case 13: goto L_8000E318; break;
        case 14: goto L_8000E144; break;
        case 15: goto L_8000E318; break;
        case 16: goto L_8000E120; break;
        case 17: goto L_8000E318; break;
        case 18: goto L_8000E318; break;
        case 19: goto L_8000E0F8; break;
        case 20: goto L_8000E10C; break;
        case 21: goto L_8000E318; break;
        case 22: goto L_8000E168; break;
        case 23: goto L_8000E17C; break;
        case 24: goto L_8000E190; break;
        case 25: goto L_8000E1A4; break;
        case 26: goto L_8000E1B8; break;
        case 27: goto L_8000E1CC; break;
        case 28: goto L_8000E1E0; break;
        case 29: goto L_8000E1F4; break;
        case 30: goto L_8000E208; break;
        case 31: goto L_8000E21C; break;
        case 32: goto L_8000E240; break;
        case 33: goto L_8000E318; break;
        case 34: goto L_8000E318; break;
        case 35: goto L_8000E254; break;
        case 36: goto L_8000E268; break;
        case 37: goto L_8000E27C; break;
        case 38: goto L_8000E2A0; break;
        case 39: goto L_8000E2B4; break;
        case 40: goto L_8000E318; break;
        case 41: goto L_8000E318; break;
        case 42: goto L_8000E2C8; break;
        case 43: goto L_8000E2DC; break;
        case 44: goto L_8000E318; break;
        case 45: goto L_8000E318; break;
        case 46: goto L_8000E2F0; break;
        case 47: goto L_8000E304; break;
        default: switch_error(__func__, 0x8000E02C, 0x800ED360);
    }
    // 0x8000E030: nop

L_8000E034:
    // 0x8000E034: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000E038: nop

    // 0x8000E03C: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x8000E040: nop

    // 0x8000E044: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8000E048: beq         $t1, $zero, L_8000E070
    if (ctx->r9 == 0) {
        // 0x8000E04C: nop

            goto L_8000E070;
    }
    // 0x8000E04C: nop

    // 0x8000E050: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8000E054: nop

    // 0x8000E058: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000E05C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8000E060: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8000E064: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8000E068: b           L_8000E334
    // 0x8000E06C: nop

        goto L_8000E334;
    // 0x8000E06C: nop

L_8000E070:
    // 0x8000E070: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E074: jal         0x800111E8
    // 0x8000E078: nop

    func_800111E8(rdram, ctx);
        goto after_3;
    // 0x8000E078: nop

    after_3:
    // 0x8000E07C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8000E080: nop

    // 0x8000E084: lw          $t6, 0x20C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X20C);
    // 0x8000E088: nop

    // 0x8000E08C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8000E090: b           L_8000E334
    // 0x8000E094: nop

        goto L_8000E334;
    // 0x8000E094: nop

L_8000E098:
    // 0x8000E098: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E09C: jal         0x8001173C
    // 0x8000E0A0: nop

    func_8001173C(rdram, ctx);
        goto after_4;
    // 0x8000E0A0: nop

    after_4:
    // 0x8000E0A4: b           L_8000E334
    // 0x8000E0A8: nop

        goto L_8000E334;
    // 0x8000E0A8: nop

L_8000E0AC:
    // 0x8000E0AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E0B0: jal         0x80011A0C
    // 0x8000E0B4: nop

    func_80011A0C(rdram, ctx);
        goto after_5;
    // 0x8000E0B4: nop

    after_5:
    // 0x8000E0B8: b           L_8000E334
    // 0x8000E0BC: nop

        goto L_8000E334;
    // 0x8000E0BC: nop

L_8000E0C0:
    // 0x8000E0C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E0C4: jal         0x800131F4
    // 0x8000E0C8: nop

    func_800131F4(rdram, ctx);
        goto after_6;
    // 0x8000E0C8: nop

    after_6:
    // 0x8000E0CC: b           L_8000E334
    // 0x8000E0D0: nop

        goto L_8000E334;
    // 0x8000E0D0: nop

L_8000E0D4:
    // 0x8000E0D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E0D8: jal         0x80011B88
    // 0x8000E0DC: nop

    func_80011B88(rdram, ctx);
        goto after_7;
    // 0x8000E0DC: nop

    after_7:
    // 0x8000E0E0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000E0E4: nop

    // 0x8000E0E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000E0EC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8000E0F0: b           L_8000E334
    // 0x8000E0F4: nop

        goto L_8000E334;
    // 0x8000E0F4: nop

L_8000E0F8:
    // 0x8000E0F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E0FC: jal         0x80011F7C
    // 0x8000E100: nop

    func_80011F7C(rdram, ctx);
        goto after_8;
    // 0x8000E100: nop

    after_8:
    // 0x8000E104: b           L_8000E334
    // 0x8000E108: nop

        goto L_8000E334;
    // 0x8000E108: nop

L_8000E10C:
    // 0x8000E10C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E110: jal         0x80012068
    // 0x8000E114: nop

    func_80012068(rdram, ctx);
        goto after_9;
    // 0x8000E114: nop

    after_9:
    // 0x8000E118: b           L_8000E334
    // 0x8000E11C: nop

        goto L_8000E334;
    // 0x8000E11C: nop

L_8000E120:
    // 0x8000E120: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E124: jal         0x800123AC
    // 0x8000E128: nop

    func_800123AC(rdram, ctx);
        goto after_10;
    // 0x8000E128: nop

    after_10:
    // 0x8000E12C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000E130: nop

    // 0x8000E134: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8000E138: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8000E13C: b           L_8000E334
    // 0x8000E140: nop

        goto L_8000E334;
    // 0x8000E140: nop

L_8000E144:
    // 0x8000E144: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E148: jal         0x80012164
    // 0x8000E14C: nop

    func_80012164(rdram, ctx);
        goto after_11;
    // 0x8000E14C: nop

    after_11:
    // 0x8000E150: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000E154: nop

    // 0x8000E158: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8000E15C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8000E160: b           L_8000E334
    // 0x8000E164: nop

        goto L_8000E334;
    // 0x8000E164: nop

L_8000E168:
    // 0x8000E168: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E16C: jal         0x800124B8
    // 0x8000E170: nop

    func_800124B8(rdram, ctx);
        goto after_12;
    // 0x8000E170: nop

    after_12:
    // 0x8000E174: b           L_8000E334
    // 0x8000E178: nop

        goto L_8000E334;
    // 0x8000E178: nop

L_8000E17C:
    // 0x8000E17C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E180: jal         0x80012634
    // 0x8000E184: nop

    func_80012634(rdram, ctx);
        goto after_13;
    // 0x8000E184: nop

    after_13:
    // 0x8000E188: b           L_8000E334
    // 0x8000E18C: nop

        goto L_8000E334;
    // 0x8000E18C: nop

L_8000E190:
    // 0x8000E190: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E194: jal         0x8001292C
    // 0x8000E198: nop

    func_8001292C(rdram, ctx);
        goto after_14;
    // 0x8000E198: nop

    after_14:
    // 0x8000E19C: b           L_8000E334
    // 0x8000E1A0: nop

        goto L_8000E334;
    // 0x8000E1A0: nop

L_8000E1A4:
    // 0x8000E1A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1A8: jal         0x80013474
    // 0x8000E1AC: nop

    func_80013474(rdram, ctx);
        goto after_15;
    // 0x8000E1AC: nop

    after_15:
    // 0x8000E1B0: b           L_8000E334
    // 0x8000E1B4: nop

        goto L_8000E334;
    // 0x8000E1B4: nop

L_8000E1B8:
    // 0x8000E1B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1BC: jal         0x80012798
    // 0x8000E1C0: nop

    func_80012798(rdram, ctx);
        goto after_16;
    // 0x8000E1C0: nop

    after_16:
    // 0x8000E1C4: b           L_8000E334
    // 0x8000E1C8: nop

        goto L_8000E334;
    // 0x8000E1C8: nop

L_8000E1CC:
    // 0x8000E1CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1D0: jal         0x800129FC
    // 0x8000E1D4: nop

    func_800129FC(rdram, ctx);
        goto after_17;
    // 0x8000E1D4: nop

    after_17:
    // 0x8000E1D8: b           L_8000E334
    // 0x8000E1DC: nop

        goto L_8000E334;
    // 0x8000E1DC: nop

L_8000E1E0:
    // 0x8000E1E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1E4: jal         0x80012E7C
    // 0x8000E1E8: nop

    func_80012E7C(rdram, ctx);
        goto after_18;
    // 0x8000E1E8: nop

    after_18:
    // 0x8000E1EC: b           L_8000E334
    // 0x8000E1F0: nop

        goto L_8000E334;
    // 0x8000E1F0: nop

L_8000E1F4:
    // 0x8000E1F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E1F8: jal         0x80013398
    // 0x8000E1FC: nop

    func_80013398(rdram, ctx);
        goto after_19;
    // 0x8000E1FC: nop

    after_19:
    // 0x8000E200: b           L_8000E334
    // 0x8000E204: nop

        goto L_8000E334;
    // 0x8000E204: nop

L_8000E208:
    // 0x8000E208: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E20C: jal         0x80013624
    // 0x8000E210: nop

    func_80013624(rdram, ctx);
        goto after_20;
    // 0x8000E210: nop

    after_20:
    // 0x8000E214: b           L_8000E334
    // 0x8000E218: nop

        goto L_8000E334;
    // 0x8000E218: nop

L_8000E21C:
    // 0x8000E21C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E220: jal         0x800139B8
    // 0x8000E224: nop

    func_800139B8(rdram, ctx);
        goto after_21;
    // 0x8000E224: nop

    after_21:
    // 0x8000E228: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8000E22C: nop

    // 0x8000E230: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x8000E234: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8000E238: b           L_8000E334
    // 0x8000E23C: nop

        goto L_8000E334;
    // 0x8000E23C: nop

L_8000E240:
    // 0x8000E240: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E244: jal         0x80013AFC
    // 0x8000E248: nop

    func_80013AFC(rdram, ctx);
        goto after_22;
    // 0x8000E248: nop

    after_22:
    // 0x8000E24C: b           L_8000E334
    // 0x8000E250: nop

        goto L_8000E334;
    // 0x8000E250: nop

L_8000E254:
    // 0x8000E254: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E258: jal         0x80013F04
    // 0x8000E25C: nop

    func_80013F04(rdram, ctx);
        goto after_23;
    // 0x8000E25C: nop

    after_23:
    // 0x8000E260: b           L_8000E334
    // 0x8000E264: nop

        goto L_8000E334;
    // 0x8000E264: nop

L_8000E268:
    // 0x8000E268: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E26C: jal         0x800140D8
    // 0x8000E270: nop

    func_800140D8(rdram, ctx);
        goto after_24;
    // 0x8000E270: nop

    after_24:
    // 0x8000E274: b           L_8000E334
    // 0x8000E278: nop

        goto L_8000E334;
    // 0x8000E278: nop

L_8000E27C:
    // 0x8000E27C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E280: jal         0x80014228
    // 0x8000E284: nop

    func_80014228(rdram, ctx);
        goto after_25;
    // 0x8000E284: nop

    after_25:
    // 0x8000E288: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8000E28C: nop

    // 0x8000E290: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000E294: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8000E298: b           L_8000E334
    // 0x8000E29C: nop

        goto L_8000E334;
    // 0x8000E29C: nop

L_8000E2A0:
    // 0x8000E2A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2A4: jal         0x80015C30
    // 0x8000E2A8: nop

    func_80015C30(rdram, ctx);
        goto after_26;
    // 0x8000E2A8: nop

    after_26:
    // 0x8000E2AC: b           L_8000E334
    // 0x8000E2B0: nop

        goto L_8000E334;
    // 0x8000E2B0: nop

L_8000E2B4:
    // 0x8000E2B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2B8: jal         0x800145D4
    // 0x8000E2BC: nop

    func_800145D4(rdram, ctx);
        goto after_27;
    // 0x8000E2BC: nop

    after_27:
    // 0x8000E2C0: b           L_8000E334
    // 0x8000E2C4: nop

        goto L_8000E334;
    // 0x8000E2C4: nop

L_8000E2C8:
    // 0x8000E2C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2CC: jal         0x80015D74
    // 0x8000E2D0: nop

    func_80015D74(rdram, ctx);
        goto after_28;
    // 0x8000E2D0: nop

    after_28:
    // 0x8000E2D4: b           L_8000E334
    // 0x8000E2D8: nop

        goto L_8000E334;
    // 0x8000E2D8: nop

L_8000E2DC:
    // 0x8000E2DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2E0: jal         0x80014A80
    // 0x8000E2E4: nop

    func_80014A80(rdram, ctx);
        goto after_29;
    // 0x8000E2E4: nop

    after_29:
    // 0x8000E2E8: b           L_8000E334
    // 0x8000E2EC: nop

        goto L_8000E334;
    // 0x8000E2EC: nop

L_8000E2F0:
    // 0x8000E2F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E2F4: jal         0x80013C90
    // 0x8000E2F8: nop

    func_80013C90(rdram, ctx);
        goto after_30;
    // 0x8000E2F8: nop

    after_30:
    // 0x8000E2FC: b           L_8000E334
    // 0x8000E300: nop

        goto L_8000E334;
    // 0x8000E300: nop

L_8000E304:
    // 0x8000E304: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E308: jal         0x80013FEC
    // 0x8000E30C: nop

    func_80013FEC(rdram, ctx);
        goto after_31;
    // 0x8000E30C: nop

    after_31:
    // 0x8000E310: b           L_8000E334
    // 0x8000E314: nop

        goto L_8000E334;
    // 0x8000E314: nop

L_8000E318:
    // 0x8000E318: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000E31C: lw          $t7, 0x3DF4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3DF4);
    // 0x8000E320: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000E324: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000E328: sw          $t8, 0x3DF4($at)
    MEM_W(0X3DF4, ctx->r1) = ctx->r24;
    // 0x8000E32C: b           L_8000E334
    // 0x8000E330: nop

        goto L_8000E334;
    // 0x8000E330: nop

L_8000E334:
    // 0x8000E334: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000E338: nop

    // 0x8000E33C: bne         $t9, $zero, L_8000E354
    if (ctx->r25 != 0) {
        // 0x8000E340: nop

            goto L_8000E354;
    }
    // 0x8000E340: nop

    // 0x8000E344: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000E348: nop

    // 0x8000E34C: bne         $t0, $zero, L_8000DF88
    if (ctx->r8 != 0) {
        // 0x8000E350: nop

            goto L_8000DF88;
    }
    // 0x8000E350: nop

L_8000E354:
    // 0x8000E354: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000E358: nop

    // 0x8000E35C: lw          $t3, 0x20C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X20C);
    // 0x8000E360: nop

    // 0x8000E364: beq         $t3, $zero, L_8000E3B0
    if (ctx->r11 == 0) {
        // 0x8000E368: nop

            goto L_8000E3B0;
    }
    // 0x8000E368: nop

    // 0x8000E36C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E370: nop

    // 0x8000E374: lhu         $t2, 0x2($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X2);
    // 0x8000E378: nop

    // 0x8000E37C: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8000E380: bne         $at, $zero, L_8000E3A4
    if (ctx->r1 != 0) {
        // 0x8000E384: nop

            goto L_8000E3A4;
    }
    // 0x8000E384: nop

    // 0x8000E388: slti        $at, $t2, 0x2A
    ctx->r1 = SIGNED(ctx->r10) < 0X2A ? 1 : 0;
    // 0x8000E38C: beq         $at, $zero, L_8000E3A4
    if (ctx->r1 == 0) {
        // 0x8000E390: nop

            goto L_8000E3A4;
    }
    // 0x8000E390: nop

    // 0x8000E394: lw          $t5, 0x7C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X7C);
    // 0x8000E398: nop

    // 0x8000E39C: bne         $t5, $zero, L_8000E3B0
    if (ctx->r13 != 0) {
        // 0x8000E3A0: nop

            goto L_8000E3B0;
    }
    // 0x8000E3A0: nop

L_8000E3A4:
    // 0x8000E3A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000E3A8: jal         0x8000E7E4
    // 0x8000E3AC: nop

    func_8000E7E4(rdram, ctx);
        goto after_32;
    // 0x8000E3AC: nop

    after_32:
L_8000E3B0:
    // 0x8000E3B0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8000E3B4: b           L_8000E3C4
    // 0x8000E3B8: nop

        goto L_8000E3C4;
    // 0x8000E3B8: nop

    // 0x8000E3BC: b           L_8000E3C4
    // 0x8000E3C0: nop

        goto L_8000E3C4;
    // 0x8000E3C0: nop

L_8000E3C4:
    // 0x8000E3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E3C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000E3CC: jr          $ra
    // 0x8000E3D0: nop

    return;
    // 0x8000E3D0: nop

;}
RECOMP_FUNC void func_8000E3D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E3D4: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8000E3D8: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8000E3DC: sh          $t6, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r14;
    // 0x8000E3E0: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x8000E3E4: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x8000E3E8: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8000E3EC: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8000E3F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E3F4: nop

    // 0x8000E3F8: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x8000E3FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E400: nop

    // 0x8000E404: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x8000E408: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000E40C: nop

    // 0x8000E410: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x8000E414: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000E418: nop

    // 0x8000E41C: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x8000E420: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8000E424: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000E428: nop

    // 0x8000E42C: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    // 0x8000E430: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E434: nop

    // 0x8000E438: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x8000E43C: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8000E440: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8000E444: sw          $zero, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = 0;
    // 0x8000E448: sh          $zero, 0x60($a0)
    MEM_H(0X60, ctx->r4) = 0;
    // 0x8000E44C: sh          $zero, 0x62($a0)
    MEM_H(0X62, ctx->r4) = 0;
    // 0x8000E450: sh          $zero, 0x64($a0)
    MEM_H(0X64, ctx->r4) = 0;
    // 0x8000E454: sh          $zero, 0x66($a0)
    MEM_H(0X66, ctx->r4) = 0;
    // 0x8000E458: sh          $zero, 0x68($a0)
    MEM_H(0X68, ctx->r4) = 0;
    // 0x8000E45C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E460: nop

    // 0x8000E464: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8000E468: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E46C: nop

    // 0x8000E470: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8000E474: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000E478: nop

    // 0x8000E47C: swc1        $f8, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f8.u32l;
    // 0x8000E480: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8000E484: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000E488: nop

    // 0x8000E48C: swc1        $f10, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f10.u32l;
    // 0x8000E490: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000E494: nop

    // 0x8000E498: swc1        $f16, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f16.u32l;
    // 0x8000E49C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E4A0: nop

    // 0x8000E4A4: swc1        $f18, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f18.u32l;
    // 0x8000E4A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E4AC: nop

    // 0x8000E4B0: swc1        $f4, 0xA4($a0)
    MEM_W(0XA4, ctx->r4) = ctx->f4.u32l;
    // 0x8000E4B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E4B8: nop

    // 0x8000E4BC: swc1        $f6, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = ctx->f6.u32l;
    // 0x8000E4C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000E4C4: nop

    // 0x8000E4C8: swc1        $f8, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f8.u32l;
    // 0x8000E4CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000E4D0: nop

    // 0x8000E4D4: swc1        $f10, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f10.u32l;
    // 0x8000E4D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000E4DC: nop

    // 0x8000E4E0: swc1        $f16, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f16.u32l;
    // 0x8000E4E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E4E8: nop

    // 0x8000E4EC: swc1        $f18, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f18.u32l;
    // 0x8000E4F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000E4F4: nop

    // 0x8000E4F8: swc1        $f4, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f4.u32l;
    // 0x8000E4FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000E500: nop

    // 0x8000E504: swc1        $f6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f6.u32l;
    // 0x8000E508: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000E50C: nop

    // 0x8000E510: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x8000E514: jr          $ra
    // 0x8000E518: nop

    return;
    // 0x8000E518: nop

    // 0x8000E51C: jr          $ra
    // 0x8000E520: nop

    return;
    // 0x8000E520: nop

;}
RECOMP_FUNC void func_8000E524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E524: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000E528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E52C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000E530: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000E534: nop

    // 0x8000E538: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000E53C: nop

    // 0x8000E540: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8000E544: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000E548: addiu       $a1, $sp, 0x1A
    ctx->r5 = ADD32(ctx->r29, 0X1A);
    // 0x8000E54C: lw          $a0, 0x7C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X7C);
    // 0x8000E550: jal         0x8004A054
    // 0x8000E554: nop

    func_8004A054(rdram, ctx);
        goto after_0;
    // 0x8000E554: nop

    after_0:
    // 0x8000E558: bne         $v0, $zero, L_8000E568
    if (ctx->r2 != 0) {
        // 0x8000E55C: nop

            goto L_8000E568;
    }
    // 0x8000E55C: nop

    // 0x8000E560: b           L_8000E668
    // 0x8000E564: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E668;
    // 0x8000E564: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E568:
    // 0x8000E568: jal         0x80031AC8
    // 0x8000E56C: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x8000E56C: nop

    after_1:
    // 0x8000E570: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000E574: beq         $v0, $at, L_8000E5BC
    if (ctx->r2 == ctx->r1) {
        // 0x8000E578: nop

            goto L_8000E5BC;
    }
    // 0x8000E578: nop

    // 0x8000E57C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000E580: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8000E584: addiu       $a0, $t9, 0xC
    ctx->r4 = ADD32(ctx->r25, 0XC);
    // 0x8000E588: jal         0x800B2CBC
    // 0x8000E58C: addiu       $a1, $t9, 0x10
    ctx->r5 = ADD32(ctx->r25, 0X10);
    func_800B2CBC(rdram, ctx);
        goto after_2;
    // 0x8000E58C: addiu       $a1, $t9, 0x10
    ctx->r5 = ADD32(ctx->r25, 0X10);
    after_2:
    // 0x8000E590: jal         0x80031728
    // 0x8000E594: nop

    func_80031728(rdram, ctx);
        goto after_3;
    // 0x8000E594: nop

    after_3:
    // 0x8000E598: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000E59C: ori         $t0, $zero, 0xE007
    ctx->r8 = 0 | 0XE007;
    // 0x8000E5A0: sh          $t0, 0x62($t1)
    MEM_H(0X62, ctx->r9) = ctx->r8;
    // 0x8000E5A4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000E5A8: nop

    // 0x8000E5AC: lw          $t3, 0x1A8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A8);
    // 0x8000E5B0: nop

    // 0x8000E5B4: ori         $t4, $t3, 0x100
    ctx->r12 = ctx->r11 | 0X100;
    // 0x8000E5B8: sw          $t4, 0x1A8($t2)
    MEM_W(0X1A8, ctx->r10) = ctx->r12;
L_8000E5BC:
    // 0x8000E5BC: lh          $t5, 0x1A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1A);
    // 0x8000E5C0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000E5C4: nop

    // 0x8000E5C8: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x8000E5CC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000E5D0: nop

    // 0x8000E5D4: sw          $zero, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = 0;
    // 0x8000E5D8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000E5DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8000E5E0: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000E5E4: nop

    // 0x8000E5E8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8000E5EC: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x8000E5F0: nop

    // 0x8000E5F4: blez        $t0, L_8000E640
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000E5F8: nop

            goto L_8000E640;
    }
    // 0x8000E5F8: nop

L_8000E5FC:
    // 0x8000E5FC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000E600: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8000E604: lw          $t3, 0x94($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X94);
    // 0x8000E608: nop

    // 0x8000E60C: sw          $t3, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r11;
    // 0x8000E610: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E614: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000E618: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000E61C: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8000E620: addiu       $t7, $t6, 0x160
    ctx->r15 = ADD32(ctx->r14, 0X160);
    // 0x8000E624: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8000E628: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8000E62C: lhu         $t8, 0x6($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X6);
    // 0x8000E630: nop

    // 0x8000E634: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000E638: bne         $at, $zero, L_8000E5FC
    if (ctx->r1 != 0) {
        // 0x8000E63C: nop

            goto L_8000E5FC;
    }
    // 0x8000E63C: nop

L_8000E640:
    // 0x8000E640: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000E644: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000E648: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000E64C: nop

    // 0x8000E650: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x8000E654: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x8000E658: b           L_8000E668
    // 0x8000E65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E668;
    // 0x8000E65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E660: b           L_8000E668
    // 0x8000E664: nop

        goto L_8000E668;
    // 0x8000E664: nop

L_8000E668:
    // 0x8000E668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E66C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000E670: jr          $ra
    // 0x8000E674: nop

    return;
    // 0x8000E674: nop

;}
RECOMP_FUNC void func_8000E678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E678: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E680: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000E684: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000E688: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000E68C: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x8000E690: nop

    // 0x8000E694: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E698: bne         $at, $zero, L_8000E6E8
    if (ctx->r1 != 0) {
        // 0x8000E69C: nop

            goto L_8000E6E8;
    }
    // 0x8000E69C: nop

    // 0x8000E6A0: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x8000E6A4: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E6A8: beq         $at, $zero, L_8000E6E8
    if (ctx->r1 == 0) {
        // 0x8000E6AC: nop

            goto L_8000E6E8;
    }
    // 0x8000E6AC: nop

    // 0x8000E6B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000E6B4: nop

    // 0x8000E6B8: lw          $t9, 0x1A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A8);
    // 0x8000E6BC: nop

    // 0x8000E6C0: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8000E6C4: beq         $t0, $zero, L_8000E6E0
    if (ctx->r8 == 0) {
        // 0x8000E6C8: nop

            goto L_8000E6E0;
    }
    // 0x8000E6C8: nop

    // 0x8000E6CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E6D0: jal         0x8000D74C
    // 0x8000E6D4: nop

    func_8000D74C(rdram, ctx);
        goto after_0;
    // 0x8000E6D4: nop

    after_0:
    // 0x8000E6D8: b           L_8000E7D4
    // 0x8000E6DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E7D4;
    // 0x8000E6DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E6E0:
    // 0x8000E6E0: b           L_8000E7C4
    // 0x8000E6E4: nop

        goto L_8000E7C4;
    // 0x8000E6E4: nop

L_8000E6E8:
    // 0x8000E6E8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8000E6EC: nop

    // 0x8000E6F0: lw          $t2, 0x1AC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1AC);
    // 0x8000E6F4: nop

    // 0x8000E6F8: slti        $at, $t2, 0x4000
    ctx->r1 = SIGNED(ctx->r10) < 0X4000 ? 1 : 0;
    // 0x8000E6FC: bne         $at, $zero, L_8000E758
    if (ctx->r1 != 0) {
        // 0x8000E700: nop

            goto L_8000E758;
    }
    // 0x8000E700: nop

    // 0x8000E704: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000E708: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E70C: beq         $at, $zero, L_8000E758
    if (ctx->r1 == 0) {
        // 0x8000E710: nop

            goto L_8000E758;
    }
    // 0x8000E710: nop

    // 0x8000E714: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8000E718: nop

    // 0x8000E71C: lw          $t4, 0x20C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20C);
    // 0x8000E720: nop

    // 0x8000E724: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8000E728: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E72C: nop

    // 0x8000E730: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8000E734: nop

    // 0x8000E738: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8000E73C: beq         $t7, $zero, L_8000E750
    if (ctx->r15 == 0) {
        // 0x8000E740: nop

            goto L_8000E750;
    }
    // 0x8000E740: nop

    // 0x8000E744: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E748: jal         0x80015BD0
    // 0x8000E74C: nop

    func_80015BD0(rdram, ctx);
        goto after_1;
    // 0x8000E74C: nop

    after_1:
L_8000E750:
    // 0x8000E750: b           L_8000E7C4
    // 0x8000E754: nop

        goto L_8000E7C4;
    // 0x8000E754: nop

L_8000E758:
    // 0x8000E758: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000E75C: nop

    // 0x8000E760: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x8000E764: nop

    // 0x8000E768: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000E76C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E770: nop

    // 0x8000E774: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000E778: nop

    // 0x8000E77C: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x8000E780: beq         $t2, $zero, L_8000E79C
    if (ctx->r10 == 0) {
        // 0x8000E784: nop

            goto L_8000E79C;
    }
    // 0x8000E784: nop

    // 0x8000E788: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E78C: jal         0x8000F53C
    // 0x8000E790: nop

    func_8000F53C(rdram, ctx);
        goto after_2;
    // 0x8000E790: nop

    after_2:
    // 0x8000E794: b           L_8000E7D4
    // 0x8000E798: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E7D4;
    // 0x8000E798: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E79C:
    // 0x8000E79C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E7A0: nop

    // 0x8000E7A4: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000E7A8: nop

    // 0x8000E7AC: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8000E7B0: beq         $t5, $zero, L_8000E7C4
    if (ctx->r13 == 0) {
        // 0x8000E7B4: nop

            goto L_8000E7C4;
    }
    // 0x8000E7B4: nop

    // 0x8000E7B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E7BC: jal         0x8000F598
    // 0x8000E7C0: nop

    func_8000F598(rdram, ctx);
        goto after_3;
    // 0x8000E7C0: nop

    after_3:
L_8000E7C4:
    // 0x8000E7C4: b           L_8000E7D4
    // 0x8000E7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E7D4;
    // 0x8000E7C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E7CC: b           L_8000E7D4
    // 0x8000E7D0: nop

        goto L_8000E7D4;
    // 0x8000E7D0: nop

L_8000E7D4:
    // 0x8000E7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E7D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000E7DC: jr          $ra
    // 0x8000E7E0: nop

    return;
    // 0x8000E7E0: nop

;}
RECOMP_FUNC void func_8000E7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E7E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E7E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E7EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000E7F0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000E7F4: nop

    // 0x8000E7F8: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000E7FC: nop

    // 0x8000E800: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8000E804: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E808: nop

    // 0x8000E80C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8000E810: nop

    // 0x8000E814: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8000E818: beq         $t0, $zero, L_8000E828
    if (ctx->r8 == 0) {
        // 0x8000E81C: nop

            goto L_8000E828;
    }
    // 0x8000E81C: nop

    // 0x8000E820: b           L_8000E9E8
    // 0x8000E824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E9E8;
    // 0x8000E824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E828:
    // 0x8000E828: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E82C: nop

    // 0x8000E830: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8000E834: nop

    // 0x8000E838: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x8000E83C: beq         $t3, $zero, L_8000E850
    if (ctx->r11 == 0) {
        // 0x8000E840: nop

            goto L_8000E850;
    }
    // 0x8000E840: nop

    // 0x8000E844: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E848: jal         0x8000FCD8
    // 0x8000E84C: nop

    func_8000FCD8(rdram, ctx);
        goto after_0;
    // 0x8000E84C: nop

    after_0:
L_8000E850:
    // 0x8000E850: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E854: nop

    // 0x8000E858: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8000E85C: nop

    // 0x8000E860: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x8000E864: beq         $t6, $zero, L_8000E878
    if (ctx->r14 == 0) {
        // 0x8000E868: nop

            goto L_8000E878;
    }
    // 0x8000E868: nop

    // 0x8000E86C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E870: jal         0x80010150
    // 0x8000E874: nop

    func_80010150(rdram, ctx);
        goto after_1;
    // 0x8000E874: nop

    after_1:
L_8000E878:
    // 0x8000E878: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E87C: nop

    // 0x8000E880: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000E884: nop

    // 0x8000E888: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x8000E88C: beq         $t9, $zero, L_8000E8A0
    if (ctx->r25 == 0) {
        // 0x8000E890: nop

            goto L_8000E8A0;
    }
    // 0x8000E890: nop

    // 0x8000E894: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E898: jal         0x80010460
    // 0x8000E89C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80010460(rdram, ctx);
        goto after_2;
    // 0x8000E89C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8000E8A0:
    // 0x8000E8A0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E8A4: nop

    // 0x8000E8A8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000E8AC: nop

    // 0x8000E8B0: andi        $t2, $t1, 0x100
    ctx->r10 = ctx->r9 & 0X100;
    // 0x8000E8B4: beq         $t2, $zero, L_8000E8C8
    if (ctx->r10 == 0) {
        // 0x8000E8B8: nop

            goto L_8000E8C8;
    }
    // 0x8000E8B8: nop

    // 0x8000E8BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E8C0: jal         0x80010460
    // 0x8000E8C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80010460(rdram, ctx);
        goto after_3;
    // 0x8000E8C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_8000E8C8:
    // 0x8000E8C8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E8CC: nop

    // 0x8000E8D0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000E8D4: nop

    // 0x8000E8D8: andi        $t5, $t4, 0x400
    ctx->r13 = ctx->r12 & 0X400;
    // 0x8000E8DC: beq         $t5, $zero, L_8000E8F0
    if (ctx->r13 == 0) {
        // 0x8000E8E0: nop

            goto L_8000E8F0;
    }
    // 0x8000E8E0: nop

    // 0x8000E8E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E8E8: jal         0x80010734
    // 0x8000E8EC: nop

    func_80010734(rdram, ctx);
        goto after_4;
    // 0x8000E8EC: nop

    after_4:
L_8000E8F0:
    // 0x8000E8F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E8F4: nop

    // 0x8000E8F8: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8000E8FC: nop

    // 0x8000E900: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x8000E904: beq         $t8, $zero, L_8000E918
    if (ctx->r24 == 0) {
        // 0x8000E908: nop

            goto L_8000E918;
    }
    // 0x8000E908: nop

    // 0x8000E90C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E910: jal         0x800108B8
    // 0x8000E914: nop

    func_800108B8(rdram, ctx);
        goto after_5;
    // 0x8000E914: nop

    after_5:
L_8000E918:
    // 0x8000E918: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E91C: nop

    // 0x8000E920: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8000E924: nop

    // 0x8000E928: andi        $t1, $t0, 0x200
    ctx->r9 = ctx->r8 & 0X200;
    // 0x8000E92C: beq         $t1, $zero, L_8000E940
    if (ctx->r9 == 0) {
        // 0x8000E930: nop

            goto L_8000E940;
    }
    // 0x8000E930: nop

    // 0x8000E934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E938: jal         0x80011040
    // 0x8000E93C: nop

    func_80011040(rdram, ctx);
        goto after_6;
    // 0x8000E93C: nop

    after_6:
L_8000E940:
    // 0x8000E940: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E944: nop

    // 0x8000E948: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000E94C: nop

    // 0x8000E950: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x8000E954: beq         $t4, $zero, L_8000E9E0
    if (ctx->r12 == 0) {
        // 0x8000E958: nop

            goto L_8000E9E0;
    }
    // 0x8000E958: nop

    // 0x8000E95C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E960: jal         0x8000F624
    // 0x8000E964: nop

    func_8000F624(rdram, ctx);
        goto after_7;
    // 0x8000E964: nop

    after_7:
    // 0x8000E968: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8000E96C: nop

    // 0x8000E970: lw          $t6, 0x1AC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1AC);
    // 0x8000E974: nop

    // 0x8000E978: slti        $at, $t6, 0x4000
    ctx->r1 = SIGNED(ctx->r14) < 0X4000 ? 1 : 0;
    // 0x8000E97C: bne         $at, $zero, L_8000E9A8
    if (ctx->r1 != 0) {
        // 0x8000E980: nop

            goto L_8000E9A8;
    }
    // 0x8000E980: nop

    // 0x8000E984: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000E988: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E98C: beq         $at, $zero, L_8000E9A8
    if (ctx->r1 == 0) {
        // 0x8000E990: nop

            goto L_8000E9A8;
    }
    // 0x8000E990: nop

    // 0x8000E994: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E998: jal         0x80014F38
    // 0x8000E99C: nop

    func_80014F38(rdram, ctx);
        goto after_8;
    // 0x8000E99C: nop

    after_8:
    // 0x8000E9A0: b           L_8000E9E0
    // 0x8000E9A4: nop

        goto L_8000E9E0;
    // 0x8000E9A4: nop

L_8000E9A8:
    // 0x8000E9A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000E9AC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000E9B0: lw          $t8, 0x1AC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1AC);
    // 0x8000E9B4: nop

    // 0x8000E9B8: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E9BC: bne         $at, $zero, L_8000E9D4
    if (ctx->r1 != 0) {
        // 0x8000E9C0: nop

            goto L_8000E9D4;
    }
    // 0x8000E9C0: nop

    // 0x8000E9C4: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x8000E9C8: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000E9CC: bne         $at, $zero, L_8000E9E0
    if (ctx->r1 != 0) {
        // 0x8000E9D0: nop

            goto L_8000E9E0;
    }
    // 0x8000E9D0: nop

L_8000E9D4:
    // 0x8000E9D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000E9D8: jal         0x80010AC8
    // 0x8000E9DC: nop

    func_80010AC8(rdram, ctx);
        goto after_9;
    // 0x8000E9DC: nop

    after_9:
L_8000E9E0:
    // 0x8000E9E0: b           L_8000E9E8
    // 0x8000E9E4: nop

        goto L_8000E9E8;
    // 0x8000E9E4: nop

L_8000E9E8:
    // 0x8000E9E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E9EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000E9F0: jr          $ra
    // 0x8000E9F4: nop

    return;
    // 0x8000E9F4: nop

;}
RECOMP_FUNC void func_8000E9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E9FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000EA00: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000EA04: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000EA08: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000EA0C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8000EA10: nop

    // 0x8000EA14: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000EA18: nop

    // 0x8000EA1C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8000EA20: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EA24: nop

    // 0x8000EA28: lhu         $s0, 0x62($t8)
    ctx->r16 = MEM_HU(ctx->r24, 0X62);
    // 0x8000EA2C: nop

    // 0x8000EA30: slti        $at, $s0, 0x2001
    ctx->r1 = SIGNED(ctx->r16) < 0X2001 ? 1 : 0;
    // 0x8000EA34: bne         $at, $zero, L_8000EA70
    if (ctx->r1 != 0) {
        // 0x8000EA38: nop

            goto L_8000EA70;
    }
    // 0x8000EA38: nop

    // 0x8000EA3C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000EA40: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8000EA44: addu        $t9, $s0, $at
    ctx->r25 = ADD32(ctx->r16, ctx->r1);
    // 0x8000EA48: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x8000EA4C: beq         $at, $zero, L_8000F460
    if (ctx->r1 == 0) {
        // 0x8000EA50: nop

            goto L_8000F460;
    }
    // 0x8000EA50: nop

    // 0x8000EA54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000EA58: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000EA5C: addu        $at, $at, $t9
    gpr jr_addend_8000EA68 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8000EA60: lw          $t9, -0x2BE0($at)
    ctx->r25 = ADD32(ctx->r1, -0X2BE0);
    // 0x8000EA64: nop

    // 0x8000EA68: jr          $t9
    // 0x8000EA6C: nop

    switch (jr_addend_8000EA68 >> 2) {
        case 0: goto L_8000EA84; break;
        case 1: goto L_8000EB0C; break;
        case 2: goto L_8000EBAC; break;
        case 3: goto L_8000EC98; break;
        case 4: goto L_8000F460; break;
        case 5: goto L_8000F460; break;
        case 6: goto L_8000F460; break;
        case 7: goto L_8000EE6C; break;
        case 8: goto L_8000EF34; break;
        case 9: goto L_8000ED84; break;
        case 10: goto L_8000F104; break;
        case 11: goto L_8000F1D8; break;
        case 12: goto L_8000F2AC; break;
        case 13: goto L_8000F380; break;
        case 14: goto L_8000EBAC; break;
        case 15: goto L_8000EC98; break;
        case 16: goto L_8000EF34; break;
        default: switch_error(__func__, 0x8000EA68, 0x800ED420);
    }
    // 0x8000EA6C: nop

L_8000EA70:
    // 0x8000EA70: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x8000EA74: beq         $s0, $at, L_8000EEE8
    if (ctx->r16 == ctx->r1) {
        // 0x8000EA78: nop

            goto L_8000EEE8;
    }
    // 0x8000EA78: nop

    // 0x8000EA7C: b           L_8000F460
    // 0x8000EA80: nop

        goto L_8000F460;
    // 0x8000EA80: nop

L_8000EA84:
    // 0x8000EA84: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EA88: nop

    // 0x8000EA8C: lh          $t1, 0x66($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X66);
    // 0x8000EA90: lwc1        $f4, 0x78($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X78);
    // 0x8000EA94: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8000EA98: nop

    // 0x8000EA9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000EAA0: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8000EAA4: nop

    // 0x8000EAA8: bc1f        L_8000EAC8
    if (!c1cs) {
        // 0x8000EAAC: nop

            goto L_8000EAC8;
    }
    // 0x8000EAAC: nop

    // 0x8000EAB0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EAB4: jal         0x8000F4B0
    // 0x8000EAB8: nop

    func_8000F4B0(rdram, ctx);
        goto after_0;
    // 0x8000EAB8: nop

    after_0:
    // 0x8000EABC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EAC0: b           L_8000EB04
    // 0x8000EAC4: sh          $zero, 0x62($t2)
    MEM_H(0X62, ctx->r10) = 0;
        goto L_8000EB04;
    // 0x8000EAC4: sh          $zero, 0x62($t2)
    MEM_H(0X62, ctx->r10) = 0;
L_8000EAC8:
    // 0x8000EAC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000EACC: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000EAD0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000EAD4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8000EAD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000EADC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8000EAE0: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8000EAE4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EAE8: nop

    // 0x8000EAEC: lwc1        $f4, 0x78($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X78);
    // 0x8000EAF0: nop

    // 0x8000EAF4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8000EAF8: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d);
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8000EAFC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8000EB00: swc1        $f16, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->f16.u32l;
L_8000EB04:
    // 0x8000EB04: b           L_8000F46C
    // 0x8000EB08: nop

        goto L_8000F46C;
    // 0x8000EB08: nop

L_8000EB0C:
    // 0x8000EB0C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EB10: nop

    // 0x8000EB14: lhu         $t5, 0x60($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X60);
    // 0x8000EB18: nop

    // 0x8000EB1C: andi        $t6, $t5, 0xE
    ctx->r14 = ctx->r13 & 0XE;
    // 0x8000EB20: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000EB24: sh          $t7, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r15;
    // 0x8000EB28: lhu         $t8, 0x36($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X36);
    // 0x8000EB2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000EB30: beq         $t8, $at, L_8000EB50
    if (ctx->r24 == ctx->r1) {
        // 0x8000EB34: nop

            goto L_8000EB50;
    }
    // 0x8000EB34: nop

    // 0x8000EB38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000EB3C: beq         $t8, $at, L_8000EB50
    if (ctx->r24 == ctx->r1) {
        // 0x8000EB40: nop

            goto L_8000EB50;
    }
    // 0x8000EB40: nop

    // 0x8000EB44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000EB48: bne         $t8, $at, L_8000EB70
    if (ctx->r24 != ctx->r1) {
        // 0x8000EB4C: nop

            goto L_8000EB70;
    }
    // 0x8000EB4C: nop

L_8000EB50:
    // 0x8000EB50: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EB54: jal         0x8000F4B0
    // 0x8000EB58: nop

    func_8000F4B0(rdram, ctx);
        goto after_1;
    // 0x8000EB58: nop

    after_1:
    // 0x8000EB5C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EB60: nop

    // 0x8000EB64: sh          $zero, 0x62($t9)
    MEM_H(0X62, ctx->r25) = 0;
    // 0x8000EB68: b           L_8000F46C
    // 0x8000EB6C: nop

        goto L_8000F46C;
    // 0x8000EB6C: nop

L_8000EB70:
    // 0x8000EB70: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EB74: nop

    // 0x8000EB78: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000EB7C: nop

    // 0x8000EB80: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8000EB84: bne         $t2, $zero, L_8000EBA4
    if (ctx->r10 != 0) {
        // 0x8000EB88: nop

            goto L_8000EBA4;
    }
    // 0x8000EB88: nop

    // 0x8000EB8C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EB90: jal         0x8000F4B0
    // 0x8000EB94: nop

    func_8000F4B0(rdram, ctx);
        goto after_2;
    // 0x8000EB94: nop

    after_2:
    // 0x8000EB98: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EB9C: nop

    // 0x8000EBA0: sh          $zero, 0x62($t3)
    MEM_H(0X62, ctx->r11) = 0;
L_8000EBA4:
    // 0x8000EBA4: b           L_8000F46C
    // 0x8000EBA8: nop

        goto L_8000F46C;
    // 0x8000EBA8: nop

L_8000EBAC:
    // 0x8000EBAC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EBB0: nop

    // 0x8000EBB4: lh          $t5, 0x66($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X66);
    // 0x8000EBB8: nop

    // 0x8000EBBC: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8000EBC0: nop

    // 0x8000EBC4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000EBC8: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8000EBCC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EBD0: nop

    // 0x8000EBD4: lhu         $t7, 0x68($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X68);
    // 0x8000EBD8: nop

    // 0x8000EBDC: bne         $t7, $zero, L_8000EC1C
    if (ctx->r15 != 0) {
        // 0x8000EBE0: nop

            goto L_8000EC1C;
    }
    // 0x8000EBE0: nop

    // 0x8000EBE4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EBE8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EBEC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000EBF0: nop

    // 0x8000EBF4: lwc1        $f8, 0xCC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x8000EBF8: nop

    // 0x8000EBFC: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8000EC00: nop

    // 0x8000EC04: bc1f        L_8000EC14
    if (!c1cs) {
        // 0x8000EC08: nop

            goto L_8000EC14;
    }
    // 0x8000EC08: nop

    // 0x8000EC0C: b           L_8000F46C
    // 0x8000EC10: nop

        goto L_8000F46C;
    // 0x8000EC10: nop

L_8000EC14:
    // 0x8000EC14: b           L_8000EC4C
    // 0x8000EC18: nop

        goto L_8000EC4C;
    // 0x8000EC18: nop

L_8000EC1C:
    // 0x8000EC1C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC20: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EC24: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000EC28: nop

    // 0x8000EC2C: lwc1        $f10, 0xCC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8000EC30: nop

    // 0x8000EC34: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8000EC38: nop

    // 0x8000EC3C: bc1f        L_8000EC4C
    if (!c1cs) {
        // 0x8000EC40: nop

            goto L_8000EC4C;
    }
    // 0x8000EC40: nop

    // 0x8000EC44: b           L_8000F46C
    // 0x8000EC48: nop

        goto L_8000F46C;
    // 0x8000EC48: nop

L_8000EC4C:
    // 0x8000EC4C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC50: ori         $at, $zero, 0xE002
    ctx->r1 = 0 | 0XE002;
    // 0x8000EC54: lhu         $t3, 0x62($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X62);
    // 0x8000EC58: nop

    // 0x8000EC5C: bne         $t3, $at, L_8000EC78
    if (ctx->r11 != ctx->r1) {
        // 0x8000EC60: nop

            goto L_8000EC78;
    }
    // 0x8000EC60: nop

    // 0x8000EC64: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC68: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EC6C: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8000EC70: nop

    // 0x8000EC74: swc1        $f18, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f18.u32l;
L_8000EC78:
    // 0x8000EC78: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EC7C: jal         0x8000F4B0
    // 0x8000EC80: nop

    func_8000F4B0(rdram, ctx);
        goto after_3;
    // 0x8000EC80: nop

    after_3:
    // 0x8000EC84: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC88: nop

    // 0x8000EC8C: sh          $zero, 0x62($t6)
    MEM_H(0X62, ctx->r14) = 0;
    // 0x8000EC90: b           L_8000F46C
    // 0x8000EC94: nop

        goto L_8000F46C;
    // 0x8000EC94: nop

L_8000EC98:
    // 0x8000EC98: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EC9C: nop

    // 0x8000ECA0: lh          $t8, 0x66($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X66);
    // 0x8000ECA4: nop

    // 0x8000ECA8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8000ECAC: nop

    // 0x8000ECB0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000ECB4: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8000ECB8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ECBC: nop

    // 0x8000ECC0: lhu         $t0, 0x68($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X68);
    // 0x8000ECC4: nop

    // 0x8000ECC8: bne         $t0, $zero, L_8000ED08
    if (ctx->r8 != 0) {
        // 0x8000ECCC: nop

            goto L_8000ED08;
    }
    // 0x8000ECCC: nop

    // 0x8000ECD0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ECD4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000ECD8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000ECDC: nop

    // 0x8000ECE0: lwc1        $f6, 0xD0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8000ECE4: nop

    // 0x8000ECE8: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8000ECEC: nop

    // 0x8000ECF0: bc1f        L_8000ED00
    if (!c1cs) {
        // 0x8000ECF4: nop

            goto L_8000ED00;
    }
    // 0x8000ECF4: nop

    // 0x8000ECF8: b           L_8000F46C
    // 0x8000ECFC: nop

        goto L_8000F46C;
    // 0x8000ECFC: nop

L_8000ED00:
    // 0x8000ED00: b           L_8000ED38
    // 0x8000ED04: nop

        goto L_8000ED38;
    // 0x8000ED04: nop

L_8000ED08:
    // 0x8000ED08: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED0C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000ED10: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8000ED14: nop

    // 0x8000ED18: lwc1        $f16, 0xD0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8000ED1C: nop

    // 0x8000ED20: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8000ED24: nop

    // 0x8000ED28: bc1f        L_8000ED38
    if (!c1cs) {
        // 0x8000ED2C: nop

            goto L_8000ED38;
    }
    // 0x8000ED2C: nop

    // 0x8000ED30: b           L_8000F46C
    // 0x8000ED34: nop

        goto L_8000F46C;
    // 0x8000ED34: nop

L_8000ED38:
    // 0x8000ED38: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED3C: ori         $at, $zero, 0xE003
    ctx->r1 = 0 | 0XE003;
    // 0x8000ED40: lhu         $t6, 0x62($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X62);
    // 0x8000ED44: nop

    // 0x8000ED48: bne         $t6, $at, L_8000ED64
    if (ctx->r14 != ctx->r1) {
        // 0x8000ED4C: nop

            goto L_8000ED64;
    }
    // 0x8000ED4C: nop

    // 0x8000ED50: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED54: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000ED58: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000ED5C: nop

    // 0x8000ED60: swc1        $f4, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f4.u32l;
L_8000ED64:
    // 0x8000ED64: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000ED68: jal         0x8000F4B0
    // 0x8000ED6C: nop

    func_8000F4B0(rdram, ctx);
        goto after_4;
    // 0x8000ED6C: nop

    after_4:
    // 0x8000ED70: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED74: nop

    // 0x8000ED78: sh          $zero, 0x62($t9)
    MEM_H(0X62, ctx->r25) = 0;
    // 0x8000ED7C: b           L_8000F46C
    // 0x8000ED80: nop

        goto L_8000F46C;
    // 0x8000ED80: nop

L_8000ED84:
    // 0x8000ED84: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000ED88: nop

    // 0x8000ED8C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000ED90: nop

    // 0x8000ED94: andi        $t2, $t1, 0x40
    ctx->r10 = ctx->r9 & 0X40;
    // 0x8000ED98: bne         $t2, $zero, L_8000EDC0
    if (ctx->r10 != 0) {
        // 0x8000ED9C: nop

            goto L_8000EDC0;
    }
    // 0x8000ED9C: nop

    // 0x8000EDA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EDA4: jal         0x8000F4B0
    // 0x8000EDA8: nop

    func_8000F4B0(rdram, ctx);
        goto after_5;
    // 0x8000EDA8: nop

    after_5:
    // 0x8000EDAC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EDB0: nop

    // 0x8000EDB4: sh          $zero, 0x62($t3)
    MEM_H(0X62, ctx->r11) = 0;
    // 0x8000EDB8: b           L_8000F46C
    // 0x8000EDBC: nop

        goto L_8000F46C;
    // 0x8000EDBC: nop

L_8000EDC0:
    // 0x8000EDC0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EDC4: nop

    // 0x8000EDC8: lhu         $t5, 0x66($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X66);
    // 0x8000EDCC: nop

    // 0x8000EDD0: sh          $t5, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r13;
    // 0x8000EDD4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EDD8: nop

    // 0x8000EDDC: lhu         $t7, 0x68($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X68);
    // 0x8000EDE0: nop

    // 0x8000EDE4: bne         $t7, $zero, L_8000EE20
    if (ctx->r15 != 0) {
        // 0x8000EDE8: nop

            goto L_8000EE20;
    }
    // 0x8000EDE8: nop

    // 0x8000EDEC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EDF0: lhu         $t1, 0x2E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2E);
    // 0x8000EDF4: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000EDF8: nop

    // 0x8000EDFC: lhu         $t0, 0x11E($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X11E);
    // 0x8000EE00: nop

    // 0x8000EE04: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000EE08: beq         $at, $zero, L_8000EE18
    if (ctx->r1 == 0) {
        // 0x8000EE0C: nop

            goto L_8000EE18;
    }
    // 0x8000EE0C: nop

    // 0x8000EE10: b           L_8000F46C
    // 0x8000EE14: nop

        goto L_8000F46C;
    // 0x8000EE14: nop

L_8000EE18:
    // 0x8000EE18: b           L_8000EE4C
    // 0x8000EE1C: nop

        goto L_8000EE4C;
    // 0x8000EE1C: nop

L_8000EE20:
    // 0x8000EE20: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EE24: lhu         $t5, 0x2E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2E);
    // 0x8000EE28: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8000EE2C: nop

    // 0x8000EE30: lhu         $t4, 0x11E($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X11E);
    // 0x8000EE34: nop

    // 0x8000EE38: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000EE3C: beq         $at, $zero, L_8000EE4C
    if (ctx->r1 == 0) {
        // 0x8000EE40: nop

            goto L_8000EE4C;
    }
    // 0x8000EE40: nop

    // 0x8000EE44: b           L_8000F46C
    // 0x8000EE48: nop

        goto L_8000F46C;
    // 0x8000EE48: nop

L_8000EE4C:
    // 0x8000EE4C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EE50: jal         0x8000F4B0
    // 0x8000EE54: nop

    func_8000F4B0(rdram, ctx);
        goto after_6;
    // 0x8000EE54: nop

    after_6:
    // 0x8000EE58: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EE5C: nop

    // 0x8000EE60: sh          $zero, 0x62($t6)
    MEM_H(0X62, ctx->r14) = 0;
    // 0x8000EE64: b           L_8000F46C
    // 0x8000EE68: nop

        goto L_8000F46C;
    // 0x8000EE68: nop

L_8000EE6C:
    // 0x8000EE6C: jal         0x80031AC8
    // 0x8000EE70: nop

    func_80031AC8(rdram, ctx);
        goto after_7;
    // 0x8000EE70: nop

    after_7:
    // 0x8000EE74: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8000EE78: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EE7C: nop

    // 0x8000EE80: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000EE84: nop

    // 0x8000EE88: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8000EE8C: beq         $t9, $zero, L_8000EEB8
    if (ctx->r25 == 0) {
        // 0x8000EE90: nop

            goto L_8000EEB8;
    }
    // 0x8000EE90: nop

    // 0x8000EE94: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000EE98: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000EE9C: bne         $t0, $at, L_8000EEB8
    if (ctx->r8 != ctx->r1) {
        // 0x8000EEA0: nop

            goto L_8000EEB8;
    }
    // 0x8000EEA0: nop

    // 0x8000EEA4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EEA8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8000EEAC: addiu       $a0, $t1, 0xC
    ctx->r4 = ADD32(ctx->r9, 0XC);
    // 0x8000EEB0: jal         0x800B2CBC
    // 0x8000EEB4: addiu       $a1, $t1, 0x10
    ctx->r5 = ADD32(ctx->r9, 0X10);
    func_800B2CBC(rdram, ctx);
        goto after_8;
    // 0x8000EEB4: addiu       $a1, $t1, 0x10
    ctx->r5 = ADD32(ctx->r9, 0X10);
    after_8:
L_8000EEB8:
    // 0x8000EEB8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000EEBC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000EEC0: bne         $t2, $at, L_8000EEE0
    if (ctx->r10 != ctx->r1) {
        // 0x8000EEC4: nop

            goto L_8000EEE0;
    }
    // 0x8000EEC4: nop

    // 0x8000EEC8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EECC: jal         0x8000F4B0
    // 0x8000EED0: nop

    func_8000F4B0(rdram, ctx);
        goto after_9;
    // 0x8000EED0: nop

    after_9:
    // 0x8000EED4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EED8: nop

    // 0x8000EEDC: sh          $zero, 0x62($t3)
    MEM_H(0X62, ctx->r11) = 0;
L_8000EEE0:
    // 0x8000EEE0: b           L_8000F46C
    // 0x8000EEE4: nop

        goto L_8000F46C;
    // 0x8000EEE4: nop

L_8000EEE8:
    // 0x8000EEE8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EEEC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000EEF0: jal         0x800B334C
    // 0x8000EEF4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800B334C(rdram, ctx);
        goto after_10;
    // 0x8000EEF4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_10:
    // 0x8000EEF8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EEFC: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x8000EF00: lhu         $t5, 0x66($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X66);
    // 0x8000EF04: nop

    // 0x8000EF08: and         $t6, $t5, $s1
    ctx->r14 = ctx->r13 & ctx->r17;
    // 0x8000EF0C: beq         $t6, $zero, L_8000EF2C
    if (ctx->r14 == 0) {
        // 0x8000EF10: nop

            goto L_8000EF2C;
    }
    // 0x8000EF10: nop

    // 0x8000EF14: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000EF18: jal         0x8000F4B0
    // 0x8000EF1C: nop

    func_8000F4B0(rdram, ctx);
        goto after_11;
    // 0x8000EF1C: nop

    after_11:
    // 0x8000EF20: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EF24: nop

    // 0x8000EF28: sh          $zero, 0x62($t7)
    MEM_H(0X62, ctx->r15) = 0;
L_8000EF2C:
    // 0x8000EF2C: b           L_8000F46C
    // 0x8000EF30: nop

        goto L_8000F46C;
    // 0x8000EF30: nop

L_8000EF34:
    // 0x8000EF34: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8000EF38: nop

    // 0x8000EF3C: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x8000EF40: nop

    // 0x8000EF44: slti        $at, $t9, 0x4000
    ctx->r1 = SIGNED(ctx->r25) < 0X4000 ? 1 : 0;
    // 0x8000EF48: bne         $at, $zero, L_8000EF60
    if (ctx->r1 != 0) {
        // 0x8000EF4C: nop

            goto L_8000EF60;
    }
    // 0x8000EF4C: nop

    // 0x8000EF50: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000EF54: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000EF58: bne         $at, $zero, L_8000F030
    if (ctx->r1 != 0) {
        // 0x8000EF5C: nop

            goto L_8000F030;
    }
    // 0x8000EF5C: nop

L_8000EF60:
    // 0x8000EF60: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EF64: nop

    // 0x8000EF68: lh          $t1, 0x66($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X66);
    // 0x8000EF6C: nop

    // 0x8000EF70: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8000EF74: nop

    // 0x8000EF78: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000EF7C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8000EF80: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EF84: nop

    // 0x8000EF88: lhu         $t3, 0x68($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X68);
    // 0x8000EF8C: nop

    // 0x8000EF90: bne         $t3, $zero, L_8000EFC8
    if (ctx->r11 != 0) {
        // 0x8000EF94: nop

            goto L_8000EFC8;
    }
    // 0x8000EF94: nop

    // 0x8000EF98: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EF9C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EFA0: lwc1        $f10, 0x14($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8000EFA4: nop

    // 0x8000EFA8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8000EFAC: nop

    // 0x8000EFB0: bc1f        L_8000EFC0
    if (!c1cs) {
        // 0x8000EFB4: nop

            goto L_8000EFC0;
    }
    // 0x8000EFB4: nop

    // 0x8000EFB8: b           L_8000F46C
    // 0x8000EFBC: nop

        goto L_8000F46C;
    // 0x8000EFBC: nop

L_8000EFC0:
    // 0x8000EFC0: b           L_8000EFF0
    // 0x8000EFC4: nop

        goto L_8000EFF0;
    // 0x8000EFC4: nop

L_8000EFC8:
    // 0x8000EFC8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EFCC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000EFD0: lwc1        $f18, 0x14($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8000EFD4: nop

    // 0x8000EFD8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8000EFDC: nop

    // 0x8000EFE0: bc1f        L_8000EFF0
    if (!c1cs) {
        // 0x8000EFE4: nop

            goto L_8000EFF0;
    }
    // 0x8000EFE4: nop

    // 0x8000EFE8: b           L_8000F46C
    // 0x8000EFEC: nop

        goto L_8000F46C;
    // 0x8000EFEC: nop

L_8000EFF0:
    // 0x8000EFF0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EFF4: ori         $at, $zero, 0xE008
    ctx->r1 = 0 | 0XE008;
    // 0x8000EFF8: lhu         $t7, 0x62($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X62);
    // 0x8000EFFC: nop

    // 0x8000F000: bne         $t7, $at, L_8000F018
    if (ctx->r15 != ctx->r1) {
        // 0x8000F004: nop

            goto L_8000F018;
    }
    // 0x8000F004: nop

    // 0x8000F008: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000F00C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F010: nop

    // 0x8000F014: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
L_8000F018:
    // 0x8000F018: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F01C: jal         0x8000F4B0
    // 0x8000F020: nop

    func_8000F4B0(rdram, ctx);
        goto after_12;
    // 0x8000F020: nop

    after_12:
    // 0x8000F024: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F028: b           L_8000F0FC
    // 0x8000F02C: sh          $zero, 0x62($t9)
    MEM_H(0X62, ctx->r25) = 0;
        goto L_8000F0FC;
    // 0x8000F02C: sh          $zero, 0x62($t9)
    MEM_H(0X62, ctx->r25) = 0;
L_8000F030:
    // 0x8000F030: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F034: nop

    // 0x8000F038: lh          $t1, 0x66($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X66);
    // 0x8000F03C: nop

    // 0x8000F040: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8000F044: nop

    // 0x8000F048: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000F04C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8000F050: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F054: nop

    // 0x8000F058: lhu         $t3, 0x68($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X68);
    // 0x8000F05C: nop

    // 0x8000F060: bne         $t3, $zero, L_8000F0A0
    if (ctx->r11 != 0) {
        // 0x8000F064: nop

            goto L_8000F0A0;
    }
    // 0x8000F064: nop

    // 0x8000F068: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F06C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F070: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8000F074: nop

    // 0x8000F078: lwc1        $f16, 0xD4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XD4);
    // 0x8000F07C: nop

    // 0x8000F080: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8000F084: nop

    // 0x8000F088: bc1f        L_8000F098
    if (!c1cs) {
        // 0x8000F08C: nop

            goto L_8000F098;
    }
    // 0x8000F08C: nop

    // 0x8000F090: b           L_8000F46C
    // 0x8000F094: nop

        goto L_8000F46C;
    // 0x8000F094: nop

L_8000F098:
    // 0x8000F098: b           L_8000F0D0
    // 0x8000F09C: nop

        goto L_8000F0D0;
    // 0x8000F09C: nop

L_8000F0A0:
    // 0x8000F0A0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F0A4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F0A8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8000F0AC: nop

    // 0x8000F0B0: lwc1        $f4, 0xD4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XD4);
    // 0x8000F0B4: nop

    // 0x8000F0B8: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8000F0BC: nop

    // 0x8000F0C0: bc1f        L_8000F0D0
    if (!c1cs) {
        // 0x8000F0C4: nop

            goto L_8000F0D0;
    }
    // 0x8000F0C4: nop

    // 0x8000F0C8: b           L_8000F46C
    // 0x8000F0CC: nop

        goto L_8000F46C;
    // 0x8000F0CC: nop

L_8000F0D0:
    // 0x8000F0D0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F0D4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F0D8: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000F0DC: nop

    // 0x8000F0E0: swc1        $f6, 0xD4($t9)
    MEM_W(0XD4, ctx->r25) = ctx->f6.u32l;
    // 0x8000F0E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F0E8: jal         0x8000F4B0
    // 0x8000F0EC: nop

    func_8000F4B0(rdram, ctx);
        goto after_13;
    // 0x8000F0EC: nop

    after_13:
    // 0x8000F0F0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F0F4: nop

    // 0x8000F0F8: sh          $zero, 0x62($t0)
    MEM_H(0X62, ctx->r8) = 0;
L_8000F0FC:
    // 0x8000F0FC: b           L_8000F46C
    // 0x8000F100: nop

        goto L_8000F46C;
    // 0x8000F100: nop

L_8000F104:
    // 0x8000F104: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F108: nop

    // 0x8000F10C: lh          $t2, 0x66($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X66);
    // 0x8000F110: nop

    // 0x8000F114: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8000F118: nop

    // 0x8000F11C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000F120: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8000F124: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F128: nop

    // 0x8000F12C: lhu         $t4, 0x68($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X68);
    // 0x8000F130: nop

    // 0x8000F134: bne         $t4, $zero, L_8000F174
    if (ctx->r12 != 0) {
        // 0x8000F138: nop

            goto L_8000F174;
    }
    // 0x8000F138: nop

    // 0x8000F13C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F140: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F144: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8000F148: nop

    // 0x8000F14C: lwc1        $f18, 0xE8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8000F150: nop

    // 0x8000F154: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8000F158: nop

    // 0x8000F15C: bc1f        L_8000F16C
    if (!c1cs) {
        // 0x8000F160: nop

            goto L_8000F16C;
    }
    // 0x8000F160: nop

    // 0x8000F164: b           L_8000F46C
    // 0x8000F168: nop

        goto L_8000F46C;
    // 0x8000F168: nop

L_8000F16C:
    // 0x8000F16C: b           L_8000F1A4
    // 0x8000F170: nop

        goto L_8000F1A4;
    // 0x8000F170: nop

L_8000F174:
    // 0x8000F174: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F178: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F17C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000F180: nop

    // 0x8000F184: lwc1        $f8, 0xE8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x8000F188: nop

    // 0x8000F18C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8000F190: nop

    // 0x8000F194: bc1f        L_8000F1A4
    if (!c1cs) {
        // 0x8000F198: nop

            goto L_8000F1A4;
    }
    // 0x8000F198: nop

    // 0x8000F19C: b           L_8000F46C
    // 0x8000F1A0: nop

        goto L_8000F46C;
    // 0x8000F1A0: nop

L_8000F1A4:
    // 0x8000F1A4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F1A8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F1AC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8000F1B0: nop

    // 0x8000F1B4: swc1        $f10, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f10.u32l;
    // 0x8000F1B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F1BC: jal         0x8000F4B0
    // 0x8000F1C0: nop

    func_8000F4B0(rdram, ctx);
        goto after_14;
    // 0x8000F1C0: nop

    after_14:
    // 0x8000F1C4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F1C8: nop

    // 0x8000F1CC: sh          $zero, 0x62($t1)
    MEM_H(0X62, ctx->r9) = 0;
    // 0x8000F1D0: b           L_8000F46C
    // 0x8000F1D4: nop

        goto L_8000F46C;
    // 0x8000F1D4: nop

L_8000F1D8:
    // 0x8000F1D8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F1DC: nop

    // 0x8000F1E0: lh          $t3, 0x66($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X66);
    // 0x8000F1E4: nop

    // 0x8000F1E8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8000F1EC: nop

    // 0x8000F1F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000F1F4: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8000F1F8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F1FC: nop

    // 0x8000F200: lhu         $t5, 0x68($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X68);
    // 0x8000F204: nop

    // 0x8000F208: bne         $t5, $zero, L_8000F248
    if (ctx->r13 != 0) {
        // 0x8000F20C: nop

            goto L_8000F248;
    }
    // 0x8000F20C: nop

    // 0x8000F210: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F214: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F218: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8000F21C: nop

    // 0x8000F220: lwc1        $f4, 0xEC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XEC);
    // 0x8000F224: nop

    // 0x8000F228: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8000F22C: nop

    // 0x8000F230: bc1f        L_8000F240
    if (!c1cs) {
        // 0x8000F234: nop

            goto L_8000F240;
    }
    // 0x8000F234: nop

    // 0x8000F238: b           L_8000F46C
    // 0x8000F23C: nop

        goto L_8000F46C;
    // 0x8000F23C: nop

L_8000F240:
    // 0x8000F240: b           L_8000F278
    // 0x8000F244: nop

        goto L_8000F278;
    // 0x8000F244: nop

L_8000F248:
    // 0x8000F248: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F24C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F250: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000F254: nop

    // 0x8000F258: lwc1        $f6, 0xEC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XEC);
    // 0x8000F25C: nop

    // 0x8000F260: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8000F264: nop

    // 0x8000F268: bc1f        L_8000F278
    if (!c1cs) {
        // 0x8000F26C: nop

            goto L_8000F278;
    }
    // 0x8000F26C: nop

    // 0x8000F270: b           L_8000F46C
    // 0x8000F274: nop

        goto L_8000F46C;
    // 0x8000F274: nop

L_8000F278:
    // 0x8000F278: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F27C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F280: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000F284: nop

    // 0x8000F288: swc1        $f16, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->f16.u32l;
    // 0x8000F28C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F290: jal         0x8000F4B0
    // 0x8000F294: nop

    func_8000F4B0(rdram, ctx);
        goto after_15;
    // 0x8000F294: nop

    after_15:
    // 0x8000F298: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F29C: nop

    // 0x8000F2A0: sh          $zero, 0x62($t2)
    MEM_H(0X62, ctx->r10) = 0;
    // 0x8000F2A4: b           L_8000F46C
    // 0x8000F2A8: nop

        goto L_8000F46C;
    // 0x8000F2A8: nop

L_8000F2AC:
    // 0x8000F2AC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F2B0: nop

    // 0x8000F2B4: lh          $t4, 0x66($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X66);
    // 0x8000F2B8: nop

    // 0x8000F2BC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8000F2C0: nop

    // 0x8000F2C4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000F2C8: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8000F2CC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F2D0: nop

    // 0x8000F2D4: lhu         $t6, 0x68($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X68);
    // 0x8000F2D8: nop

    // 0x8000F2DC: bne         $t6, $zero, L_8000F31C
    if (ctx->r14 != 0) {
        // 0x8000F2E0: nop

            goto L_8000F31C;
    }
    // 0x8000F2E0: nop

    // 0x8000F2E4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F2E8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F2EC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000F2F0: nop

    // 0x8000F2F4: lwc1        $f8, 0xF0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8000F2F8: nop

    // 0x8000F2FC: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8000F300: nop

    // 0x8000F304: bc1f        L_8000F314
    if (!c1cs) {
        // 0x8000F308: nop

            goto L_8000F314;
    }
    // 0x8000F308: nop

    // 0x8000F30C: b           L_8000F46C
    // 0x8000F310: nop

        goto L_8000F46C;
    // 0x8000F310: nop

L_8000F314:
    // 0x8000F314: b           L_8000F34C
    // 0x8000F318: nop

        goto L_8000F34C;
    // 0x8000F318: nop

L_8000F31C:
    // 0x8000F31C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F320: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F324: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8000F328: nop

    // 0x8000F32C: lwc1        $f10, 0xF0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x8000F330: nop

    // 0x8000F334: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8000F338: nop

    // 0x8000F33C: bc1f        L_8000F34C
    if (!c1cs) {
        // 0x8000F340: nop

            goto L_8000F34C;
    }
    // 0x8000F340: nop

    // 0x8000F344: b           L_8000F46C
    // 0x8000F348: nop

        goto L_8000F46C;
    // 0x8000F348: nop

L_8000F34C:
    // 0x8000F34C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F350: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F354: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000F358: nop

    // 0x8000F35C: swc1        $f18, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f18.u32l;
    // 0x8000F360: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F364: jal         0x8000F4B0
    // 0x8000F368: nop

    func_8000F4B0(rdram, ctx);
        goto after_16;
    // 0x8000F368: nop

    after_16:
    // 0x8000F36C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F370: nop

    // 0x8000F374: sh          $zero, 0x62($t3)
    MEM_H(0X62, ctx->r11) = 0;
    // 0x8000F378: b           L_8000F46C
    // 0x8000F37C: nop

        goto L_8000F46C;
    // 0x8000F37C: nop

L_8000F380:
    // 0x8000F380: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F384: nop

    // 0x8000F388: lhu         $a0, 0x66($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X66);
    // 0x8000F38C: jal         0x80014BD4
    // 0x8000F390: nop

    func_80014BD4(rdram, ctx);
        goto after_17;
    // 0x8000F390: nop

    after_17:
    // 0x8000F394: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8000F398: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F39C: nop

    // 0x8000F3A0: lhu         $t6, 0x68($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X68);
    // 0x8000F3A4: nop

    // 0x8000F3A8: bne         $t6, $zero, L_8000F3E8
    if (ctx->r14 != 0) {
        // 0x8000F3AC: nop

            goto L_8000F3E8;
    }
    // 0x8000F3AC: nop

    // 0x8000F3B0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F3B4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F3B8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8000F3BC: nop

    // 0x8000F3C0: lwc1        $f4, 0xF4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x8000F3C4: nop

    // 0x8000F3C8: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8000F3CC: nop

    // 0x8000F3D0: bc1f        L_8000F3E0
    if (!c1cs) {
        // 0x8000F3D4: nop

            goto L_8000F3E0;
    }
    // 0x8000F3D4: nop

    // 0x8000F3D8: b           L_8000F46C
    // 0x8000F3DC: nop

        goto L_8000F46C;
    // 0x8000F3DC: nop

L_8000F3E0:
    // 0x8000F3E0: b           L_8000F418
    // 0x8000F3E4: nop

        goto L_8000F418;
    // 0x8000F3E4: nop

L_8000F3E8:
    // 0x8000F3E8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F3EC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F3F0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8000F3F4: nop

    // 0x8000F3F8: lwc1        $f6, 0xF4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XF4);
    // 0x8000F3FC: nop

    // 0x8000F400: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8000F404: nop

    // 0x8000F408: bc1f        L_8000F418
    if (!c1cs) {
        // 0x8000F40C: nop

            goto L_8000F418;
    }
    // 0x8000F40C: nop

    // 0x8000F410: b           L_8000F46C
    // 0x8000F414: nop

        goto L_8000F46C;
    // 0x8000F414: nop

L_8000F418:
    // 0x8000F418: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F41C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F420: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000F424: nop

    // 0x8000F428: swc1        $f16, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f16.u32l;
    // 0x8000F42C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F430: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F434: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8000F438: nop

    // 0x8000F43C: swc1        $f18, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f18.u32l;
    // 0x8000F440: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F444: jal         0x8000F4B0
    // 0x8000F448: nop

    func_8000F4B0(rdram, ctx);
        goto after_18;
    // 0x8000F448: nop

    after_18:
    // 0x8000F44C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F450: nop

    // 0x8000F454: sh          $zero, 0x62($t5)
    MEM_H(0X62, ctx->r13) = 0;
    // 0x8000F458: b           L_8000F46C
    // 0x8000F45C: nop

        goto L_8000F46C;
    // 0x8000F45C: nop

L_8000F460:
    // 0x8000F460: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F464: nop

    // 0x8000F468: sh          $zero, 0x62($t6)
    MEM_H(0X62, ctx->r14) = 0;
L_8000F46C:
    // 0x8000F46C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F470: nop

    // 0x8000F474: lhu         $t8, 0x62($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X62);
    // 0x8000F478: nop

    // 0x8000F47C: bne         $t8, $zero, L_8000F48C
    if (ctx->r24 != 0) {
        // 0x8000F480: nop

            goto L_8000F48C;
    }
    // 0x8000F480: nop

    // 0x8000F484: b           L_8000F49C
    // 0x8000F488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F49C;
    // 0x8000F488: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000F48C:
    // 0x8000F48C: b           L_8000F49C
    // 0x8000F490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F49C;
    // 0x8000F490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000F494: b           L_8000F49C
    // 0x8000F498: nop

        goto L_8000F49C;
    // 0x8000F498: nop

L_8000F49C:
    // 0x8000F49C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F4A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F4A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F4A8: jr          $ra
    // 0x8000F4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000F4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
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
RECOMP_FUNC void func_8000F53C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F53C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F544: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000F548: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000F54C: nop

    // 0x8000F550: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000F554: nop

    // 0x8000F558: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8000F55C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F560: nop

    // 0x8000F564: lhu         $a2, 0x6($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X6);
    // 0x8000F568: addiu       $a0, $t8, 0xC
    ctx->r4 = ADD32(ctx->r24, 0XC);
    // 0x8000F56C: jal         0x800B1C10
    // 0x8000F570: addiu       $a1, $t8, 0x10
    ctx->r5 = ADD32(ctx->r24, 0X10);
    func_800B1C10(rdram, ctx);
        goto after_0;
    // 0x8000F570: addiu       $a1, $t8, 0x10
    ctx->r5 = ADD32(ctx->r24, 0X10);
    after_0:
    // 0x8000F574: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000F578: jal         0x8000D74C
    // 0x8000F57C: nop

    func_8000D74C(rdram, ctx);
        goto after_1;
    // 0x8000F57C: nop

    after_1:
    // 0x8000F580: b           L_8000F588
    // 0x8000F584: nop

        goto L_8000F588;
    // 0x8000F584: nop

L_8000F588:
    // 0x8000F588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F58C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000F590: jr          $ra
    // 0x8000F594: nop

    return;
    // 0x8000F594: nop

;}
RECOMP_FUNC void func_8000F598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000F59C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F5A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000F5A4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8000F5A8: nop

    // 0x8000F5AC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000F5B0: nop

    // 0x8000F5B4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8000F5B8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F5BC: nop

    // 0x8000F5C0: addiu       $a0, $t8, 0xC
    ctx->r4 = ADD32(ctx->r24, 0XC);
    // 0x8000F5C4: jal         0x800B2748
    // 0x8000F5C8: addiu       $a1, $t8, 0x10
    ctx->r5 = ADD32(ctx->r24, 0X10);
    func_800B2748(rdram, ctx);
        goto after_0;
    // 0x8000F5C8: addiu       $a1, $t8, 0x10
    ctx->r5 = ADD32(ctx->r24, 0X10);
    after_0:
    // 0x8000F5CC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8000F5D0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8000F5D4: nop

    // 0x8000F5D8: bgez        $t9, L_8000F5FC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000F5DC: nop

            goto L_8000F5FC;
    }
    // 0x8000F5DC: nop

    // 0x8000F5E0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F5E4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8000F5E8: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000F5EC: nop

    // 0x8000F5F0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8000F5F4: b           L_8000F60C
    // 0x8000F5F8: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
        goto L_8000F60C;
    // 0x8000F5F8: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
L_8000F5FC:
    // 0x8000F5FC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8000F600: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F604: nop

    // 0x8000F608: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
L_8000F60C:
    // 0x8000F60C: b           L_8000F614
    // 0x8000F610: nop

        goto L_8000F614;
    // 0x8000F610: nop

L_8000F614:
    // 0x8000F614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000F61C: jr          $ra
    // 0x8000F620: nop

    return;
    // 0x8000F620: nop

;}
RECOMP_FUNC void func_8000F624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F624: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000F628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F62C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000F630: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8000F634: jal         0x8000F9D0
    // 0x8000F638: nop

    func_8000F9D0(rdram, ctx);
        goto after_0;
    // 0x8000F638: nop

    after_0:
    // 0x8000F63C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000F640: nop

    // 0x8000F644: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000F648: nop

    // 0x8000F64C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8000F650: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000F654: nop

    // 0x8000F658: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x8000F65C: nop

    // 0x8000F660: slti        $at, $t9, 0x4000
    ctx->r1 = SIGNED(ctx->r25) < 0X4000 ? 1 : 0;
    // 0x8000F664: bne         $at, $zero, L_8000F67C
    if (ctx->r1 != 0) {
        // 0x8000F668: nop

            goto L_8000F67C;
    }
    // 0x8000F668: nop

    // 0x8000F66C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8000F670: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8000F674: bne         $at, $zero, L_8000F7D4
    if (ctx->r1 != 0) {
        // 0x8000F678: nop

            goto L_8000F7D4;
    }
    // 0x8000F678: nop

L_8000F67C:
    // 0x8000F67C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000F680: nop

    // 0x8000F684: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8000F688: lwc1        $f6, 0x74($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X74);
    // 0x8000F68C: nop

    // 0x8000F690: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000F694: swc1        $f8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f8.u32l;
    // 0x8000F698: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000F69C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000F6A0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000F6A4: nop

    // 0x8000F6A8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8000F6AC: lhu         $t3, 0x6($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X6);
    // 0x8000F6B0: nop

    // 0x8000F6B4: blez        $t3, L_8000F7CC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000F6B8: nop

            goto L_8000F7CC;
    }
    // 0x8000F6B8: nop

L_8000F6BC:
    // 0x8000F6BC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8000F6C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F6C4: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F6C8: lwc1        $f10, 0x6C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X6C);
    // 0x8000F6CC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F6D0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000F6D4: lwc1        $f4, 0xCC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8000F6D8: nop

    // 0x8000F6DC: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8000F6E0: swc1        $f6, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f6.u32l;
    // 0x8000F6E4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000F6E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F6EC: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F6F0: lwc1        $f8, 0x70($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X70);
    // 0x8000F6F4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F6F8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000F6FC: lwc1        $f4, 0xD0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x8000F700: nop

    // 0x8000F704: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8000F708: swc1        $f18, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f18.u32l;
    // 0x8000F70C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8000F710: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000F714: lwc1        $f6, 0x74($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X74);
    // 0x8000F718: lwc1        $f11, -0x2B98($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2B98);
    // 0x8000F71C: lwc1        $f10, -0x2B94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B94);
    // 0x8000F720: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000F724: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8000F728: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F72C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F730: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F734: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8000F738: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8000F73C: lwc1        $f8, 0xF4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XF4);
    // 0x8000F740: nop

    // 0x8000F744: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8000F748: add.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d);
    ctx->f16.d = ctx->f10.d + ctx->f6.d;
    // 0x8000F74C: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8000F750: swc1        $f4, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f4.u32l;
    // 0x8000F754: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000F758: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000F75C: lwc1        $f18, 0x74($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X74);
    // 0x8000F760: lwc1        $f11, -0x2B90($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X2B90);
    // 0x8000F764: lwc1        $f10, -0x2B8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B8C);
    // 0x8000F768: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8000F76C: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8000F770: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F774: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F778: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F77C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8000F780: mul.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8000F784: lwc1        $f8, 0xF8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XF8);
    // 0x8000F788: nop

    // 0x8000F78C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8000F790: add.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = ctx->f10.d + ctx->f18.d;
    // 0x8000F794: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8000F798: swc1        $f6, 0xF8($t2)
    MEM_W(0XF8, ctx->r10) = ctx->f6.u32l;
    // 0x8000F79C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8000F7A0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F7A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000F7A8: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8000F7AC: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x8000F7B0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8000F7B4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8000F7B8: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x8000F7BC: nop

    // 0x8000F7C0: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000F7C4: bne         $at, $zero, L_8000F6BC
    if (ctx->r1 != 0) {
        // 0x8000F7C8: nop

            goto L_8000F6BC;
    }
    // 0x8000F7C8: nop

L_8000F7CC:
    // 0x8000F7CC: b           L_8000F9B8
    // 0x8000F7D0: nop

        goto L_8000F9B8;
    // 0x8000F7D0: nop

L_8000F7D4:
    // 0x8000F7D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8000F7D8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000F7DC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000F7E0: nop

    // 0x8000F7E4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000F7E8: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x8000F7EC: nop

    // 0x8000F7F0: blez        $t0, L_8000F8A0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000F7F4: nop

            goto L_8000F8A0;
    }
    // 0x8000F7F4: nop

L_8000F7F8:
    // 0x8000F7F8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000F7FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F800: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F804: lwc1        $f4, 0x6C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X6C);
    // 0x8000F808: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F80C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000F810: lwc1        $f18, 0xCC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8000F814: nop

    // 0x8000F818: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8000F81C: swc1        $f16, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f16.u32l;
    // 0x8000F820: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8000F824: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F828: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F82C: lwc1        $f6, 0x70($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X70);
    // 0x8000F830: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F834: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8000F838: lwc1        $f18, 0xD0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x8000F83C: nop

    // 0x8000F840: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8000F844: swc1        $f10, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f10.u32l;
    // 0x8000F848: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000F84C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F850: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F854: lwc1        $f16, 0x74($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X74);
    // 0x8000F858: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F85C: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000F860: lwc1        $f18, 0xD4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XD4);
    // 0x8000F864: nop

    // 0x8000F868: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8000F86C: swc1        $f8, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f8.u32l;
    // 0x8000F870: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000F874: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F878: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000F87C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000F880: addiu       $t0, $t8, 0x160
    ctx->r8 = ADD32(ctx->r24, 0X160);
    // 0x8000F884: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8000F888: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8000F88C: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x8000F890: nop

    // 0x8000F894: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000F898: bne         $at, $zero, L_8000F7F8
    if (ctx->r1 != 0) {
        // 0x8000F89C: nop

            goto L_8000F7F8;
    }
    // 0x8000F89C: nop

L_8000F8A0:
    // 0x8000F8A0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8000F8A4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8000F8A8: lw          $t5, 0x1AC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1AC);
    // 0x8000F8AC: nop

    // 0x8000F8B0: bne         $t5, $at, L_8000F9B8
    if (ctx->r13 != ctx->r1) {
        // 0x8000F8B4: nop

            goto L_8000F9B8;
    }
    // 0x8000F8B4: nop

    // 0x8000F8B8: lw          $t6, 0x1A8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1A8);
    // 0x8000F8BC: nop

    // 0x8000F8C0: andi        $t3, $t6, 0x40
    ctx->r11 = ctx->r14 & 0X40;
    // 0x8000F8C4: beq         $t3, $zero, L_8000F9B8
    if (ctx->r11 == 0) {
        // 0x8000F8C8: nop

            goto L_8000F9B8;
    }
    // 0x8000F8C8: nop

    // 0x8000F8CC: jal         0x8000D688
    // 0x8000F8D0: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    func_8000D688(rdram, ctx);
        goto after_1;
    // 0x8000F8D0: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_1:
    // 0x8000F8D4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8000F8D8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F8DC: nop

    // 0x8000F8E0: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x8000F8E4: nop

    // 0x8000F8E8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8000F8EC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000F8F0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000F8F4: lw          $t2, 0xC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC);
    // 0x8000F8F8: nop

    // 0x8000F8FC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8000F900: lhu         $t9, 0x6($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X6);
    // 0x8000F904: nop

    // 0x8000F908: blez        $t9, L_8000F9B8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8000F90C: nop

            goto L_8000F9B8;
    }
    // 0x8000F90C: nop

L_8000F910:
    // 0x8000F910: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000F914: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F918: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F91C: lwc1        $f10, 0x6C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x8000F920: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F924: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000F928: lwc1        $f18, 0xCC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8000F92C: nop

    // 0x8000F930: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8000F934: swc1        $f4, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f4.u32l;
    // 0x8000F938: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8000F93C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F940: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F944: lwc1        $f8, 0x70($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X70);
    // 0x8000F948: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F94C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000F950: lwc1        $f18, 0xD0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8000F954: nop

    // 0x8000F958: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8000F95C: swc1        $f6, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f6.u32l;
    // 0x8000F960: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8000F964: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F968: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F96C: lwc1        $f4, 0x74($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X74);
    // 0x8000F970: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F974: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000F978: lwc1        $f18, 0xD4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XD4);
    // 0x8000F97C: nop

    // 0x8000F980: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8000F984: swc1        $f16, 0xD4($t7)
    MEM_W(0XD4, ctx->r15) = ctx->f16.u32l;
    // 0x8000F988: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8000F98C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F990: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000F994: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x8000F998: addiu       $t9, $t0, 0x160
    ctx->r25 = ADD32(ctx->r8, 0X160);
    // 0x8000F99C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000F9A0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8000F9A4: lhu         $t5, 0x6($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X6);
    // 0x8000F9A8: nop

    // 0x8000F9AC: slt         $at, $t2, $t5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000F9B0: bne         $at, $zero, L_8000F910
    if (ctx->r1 != 0) {
        // 0x8000F9B4: nop

            goto L_8000F910;
    }
    // 0x8000F9B4: nop

L_8000F9B8:
    // 0x8000F9B8: b           L_8000F9C0
    // 0x8000F9BC: nop

        goto L_8000F9C0;
    // 0x8000F9BC: nop

L_8000F9C0:
    // 0x8000F9C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F9C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000F9C8: jr          $ra
    // 0x8000F9CC: nop

    return;
    // 0x8000F9CC: nop

;}
RECOMP_FUNC void func_8000F9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F9D0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000F9D4: lw          $t6, 0x20C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20C);
    // 0x8000F9D8: nop

    // 0x8000F9DC: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8000F9E0: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8000F9E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000F9E8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000F9EC: lwc1        $f4, 0xA4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XA4);
    // 0x8000F9F0: lwc1        $f10, 0x6C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x8000F9F4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000F9F8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8000F9FC: swc1        $f16, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f16.u32l;
    // 0x8000FA00: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000FA08: lwc1        $f18, 0xA4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XA4);
    // 0x8000FA0C: nop

    // 0x8000FA10: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8000FA14: nop

    // 0x8000FA18: bc1f        L_8000FA70
    if (!c1cs) {
        // 0x8000FA1C: nop

            goto L_8000FA70;
    }
    // 0x8000FA1C: nop

    // 0x8000FA20: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA24: nop

    // 0x8000FA28: lwc1        $f6, 0x98($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X98);
    // 0x8000FA2C: lwc1        $f10, 0x6C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X6C);
    // 0x8000FA30: nop

    // 0x8000FA34: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8000FA38: nop

    // 0x8000FA3C: bc1f        L_8000FA68
    if (!c1cs) {
        // 0x8000FA40: nop

            goto L_8000FA68;
    }
    // 0x8000FA40: nop

    // 0x8000FA44: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA48: nop

    // 0x8000FA4C: lwc1        $f8, 0x98($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X98);
    // 0x8000FA50: nop

    // 0x8000FA54: swc1        $f8, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f8.u32l;
    // 0x8000FA58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FA5C: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA60: nop

    // 0x8000FA64: swc1        $f16, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->f16.u32l;
L_8000FA68:
    // 0x8000FA68: b           L_8000FAD8
    // 0x8000FA6C: nop

        goto L_8000FAD8;
    // 0x8000FA6C: nop

L_8000FA70:
    // 0x8000FA70: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000FA78: lwc1        $f18, 0xA4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XA4);
    // 0x8000FA7C: nop

    // 0x8000FA80: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8000FA84: nop

    // 0x8000FA88: bc1f        L_8000FAD8
    if (!c1cs) {
        // 0x8000FA8C: nop

            goto L_8000FAD8;
    }
    // 0x8000FA8C: nop

    // 0x8000FA90: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8000FA94: nop

    // 0x8000FA98: lwc1        $f6, 0x98($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X98);
    // 0x8000FA9C: lwc1        $f10, 0x6C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X6C);
    // 0x8000FAA0: nop

    // 0x8000FAA4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8000FAA8: nop

    // 0x8000FAAC: bc1f        L_8000FAD8
    if (!c1cs) {
        // 0x8000FAB0: nop

            goto L_8000FAD8;
    }
    // 0x8000FAB0: nop

    // 0x8000FAB4: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8000FAB8: nop

    // 0x8000FABC: lwc1        $f8, 0x98($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X98);
    // 0x8000FAC0: nop

    // 0x8000FAC4: swc1        $f8, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f8.u32l;
    // 0x8000FAC8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FACC: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8000FAD0: nop

    // 0x8000FAD4: swc1        $f16, 0xA4($t5)
    MEM_W(0XA4, ctx->r13) = ctx->f16.u32l;
L_8000FAD8:
    // 0x8000FAD8: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8000FADC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FAE0: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FAE4: lwc1        $f18, 0xA8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XA8);
    // 0x8000FAE8: lwc1        $f10, 0x70($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X70);
    // 0x8000FAEC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000FAF0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000FAF4: swc1        $f8, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f8.u32l;
    // 0x8000FAF8: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8000FAFC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000FB00: lwc1        $f16, 0xA8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XA8);
    // 0x8000FB04: nop

    // 0x8000FB08: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8000FB0C: nop

    // 0x8000FB10: bc1f        L_8000FB68
    if (!c1cs) {
        // 0x8000FB14: nop

            goto L_8000FB68;
    }
    // 0x8000FB14: nop

    // 0x8000FB18: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB1C: nop

    // 0x8000FB20: lwc1        $f4, 0x9C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X9C);
    // 0x8000FB24: lwc1        $f10, 0x70($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X70);
    // 0x8000FB28: nop

    // 0x8000FB2C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8000FB30: nop

    // 0x8000FB34: bc1f        L_8000FB60
    if (!c1cs) {
        // 0x8000FB38: nop

            goto L_8000FB60;
    }
    // 0x8000FB38: nop

    // 0x8000FB3C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB40: nop

    // 0x8000FB44: lwc1        $f6, 0x9C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X9C);
    // 0x8000FB48: nop

    // 0x8000FB4C: swc1        $f6, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f6.u32l;
    // 0x8000FB50: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FB54: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB58: nop

    // 0x8000FB5C: swc1        $f8, 0xA8($t0)
    MEM_W(0XA8, ctx->r8) = ctx->f8.u32l;
L_8000FB60:
    // 0x8000FB60: b           L_8000FBD0
    // 0x8000FB64: nop

        goto L_8000FBD0;
    // 0x8000FB64: nop

L_8000FB68:
    // 0x8000FB68: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000FB70: lwc1        $f16, 0xA8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XA8);
    // 0x8000FB74: nop

    // 0x8000FB78: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8000FB7C: nop

    // 0x8000FB80: bc1f        L_8000FBD0
    if (!c1cs) {
        // 0x8000FB84: nop

            goto L_8000FBD0;
    }
    // 0x8000FB84: nop

    // 0x8000FB88: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8000FB8C: nop

    // 0x8000FB90: lwc1        $f4, 0x9C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X9C);
    // 0x8000FB94: lwc1        $f10, 0x70($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X70);
    // 0x8000FB98: nop

    // 0x8000FB9C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8000FBA0: nop

    // 0x8000FBA4: bc1f        L_8000FBD0
    if (!c1cs) {
        // 0x8000FBA8: nop

            goto L_8000FBD0;
    }
    // 0x8000FBA8: nop

    // 0x8000FBAC: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8000FBB0: nop

    // 0x8000FBB4: lwc1        $f6, 0x9C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X9C);
    // 0x8000FBB8: nop

    // 0x8000FBBC: swc1        $f6, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f6.u32l;
    // 0x8000FBC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FBC4: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x8000FBC8: nop

    // 0x8000FBCC: swc1        $f8, 0xA8($t4)
    MEM_W(0XA8, ctx->r12) = ctx->f8.u32l;
L_8000FBD0:
    // 0x8000FBD0: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x8000FBD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FBD8: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FBDC: lwc1        $f16, 0xAC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XAC);
    // 0x8000FBE0: lwc1        $f10, 0x74($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X74);
    // 0x8000FBE4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8000FBE8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000FBEC: swc1        $f6, 0x74($t5)
    MEM_W(0X74, ctx->r13) = ctx->f6.u32l;
    // 0x8000FBF0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8000FBF4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FBF8: lwc1        $f8, 0xAC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XAC);
    // 0x8000FBFC: nop

    // 0x8000FC00: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8000FC04: nop

    // 0x8000FC08: bc1f        L_8000FC60
    if (!c1cs) {
        // 0x8000FC0C: nop

            goto L_8000FC60;
    }
    // 0x8000FC0C: nop

    // 0x8000FC10: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC14: nop

    // 0x8000FC18: lwc1        $f18, 0xA0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XA0);
    // 0x8000FC1C: lwc1        $f10, 0x74($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X74);
    // 0x8000FC20: nop

    // 0x8000FC24: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8000FC28: nop

    // 0x8000FC2C: bc1f        L_8000FC58
    if (!c1cs) {
        // 0x8000FC30: nop

            goto L_8000FC58;
    }
    // 0x8000FC30: nop

    // 0x8000FC34: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC38: nop

    // 0x8000FC3C: lwc1        $f4, 0xA0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XA0);
    // 0x8000FC40: nop

    // 0x8000FC44: swc1        $f4, 0x74($t8)
    MEM_W(0X74, ctx->r24) = ctx->f4.u32l;
    // 0x8000FC48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000FC4C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC50: nop

    // 0x8000FC54: swc1        $f6, 0xAC($t9)
    MEM_W(0XAC, ctx->r25) = ctx->f6.u32l;
L_8000FC58:
    // 0x8000FC58: b           L_8000FCC8
    // 0x8000FC5C: nop

        goto L_8000FCC8;
    // 0x8000FC5C: nop

L_8000FC60:
    // 0x8000FC60: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000FC68: lwc1        $f8, 0xAC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XAC);
    // 0x8000FC6C: nop

    // 0x8000FC70: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8000FC74: nop

    // 0x8000FC78: bc1f        L_8000FCC8
    if (!c1cs) {
        // 0x8000FC7C: nop

            goto L_8000FCC8;
    }
    // 0x8000FC7C: nop

    // 0x8000FC80: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x8000FC84: nop

    // 0x8000FC88: lwc1        $f18, 0xA0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XA0);
    // 0x8000FC8C: lwc1        $f10, 0x74($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X74);
    // 0x8000FC90: nop

    // 0x8000FC94: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8000FC98: nop

    // 0x8000FC9C: bc1f        L_8000FCC8
    if (!c1cs) {
        // 0x8000FCA0: nop

            goto L_8000FCC8;
    }
    // 0x8000FCA0: nop

    // 0x8000FCA4: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8000FCA8: nop

    // 0x8000FCAC: lwc1        $f4, 0xA0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XA0);
    // 0x8000FCB0: nop

    // 0x8000FCB4: swc1        $f4, 0x74($t2)
    MEM_W(0X74, ctx->r10) = ctx->f4.u32l;
    // 0x8000FCB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000FCBC: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x8000FCC0: nop

    // 0x8000FCC4: swc1        $f6, 0xAC($t3)
    MEM_W(0XAC, ctx->r11) = ctx->f6.u32l;
L_8000FCC8:
    // 0x8000FCC8: b           L_8000FCD0
    // 0x8000FCCC: nop

        goto L_8000FCD0;
    // 0x8000FCCC: nop

L_8000FCD0:
    // 0x8000FCD0: jr          $ra
    // 0x8000FCD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000FCD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8000FCD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FCD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000FCDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FCE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000FCE4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000FCE8: jal         0x8000FE48
    // 0x8000FCEC: nop

    func_8000FE48(rdram, ctx);
        goto after_0;
    // 0x8000FCEC: nop

    after_0:
    // 0x8000FCF0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000FCF4: nop

    // 0x8000FCF8: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8000FCFC: nop

    // 0x8000FD00: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8000FD04: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000FD08: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000FD0C: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000FD10: nop

    // 0x8000FD14: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000FD18: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x8000FD1C: nop

    // 0x8000FD20: blez        $t0, L_8000FE30
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000FD24: nop

            goto L_8000FE30;
    }
    // 0x8000FD24: nop

L_8000FD28:
    // 0x8000FD28: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000FD2C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000FD30: lwc1        $f4, 0x18($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X18);
    // 0x8000FD34: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8000FD38: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FD3C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000FD40: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8000FD44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FD48: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FD4C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FD50: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8000FD54: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8000FD58: lwc1        $f6, 0xE8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XE8);
    // 0x8000FD5C: nop

    // 0x8000FD60: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000FD64: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x8000FD68: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8000FD6C: swc1        $f10, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f10.u32l;
    // 0x8000FD70: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8000FD74: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000FD78: lwc1        $f18, 0x1C($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x8000FD7C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8000FD80: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FD84: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8000FD88: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8000FD8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FD90: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FD94: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FD98: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8000FD9C: mul.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x8000FDA0: lwc1        $f6, 0xEC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XEC);
    // 0x8000FDA4: nop

    // 0x8000FDA8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000FDAC: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x8000FDB0: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8000FDB4: swc1        $f4, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f4.u32l;
    // 0x8000FDB8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8000FDBC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000FDC0: lwc1        $f10, 0x20($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X20);
    // 0x8000FDC4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8000FDC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000FDCC: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8000FDD0: mul.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8000FDD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000FDD8: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000FDDC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FDE0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8000FDE4: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8000FDE8: lwc1        $f6, 0xF0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XF0);
    // 0x8000FDEC: nop

    // 0x8000FDF0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000FDF4: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8000FDF8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8000FDFC: swc1        $f18, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f18.u32l;
    // 0x8000FE00: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000FE04: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FE08: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000FE0C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000FE10: addiu       $t0, $t8, 0x160
    ctx->r8 = ADD32(ctx->r24, 0X160);
    // 0x8000FE14: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8000FE18: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8000FE1C: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8000FE20: nop

    // 0x8000FE24: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000FE28: bne         $at, $zero, L_8000FD28
    if (ctx->r1 != 0) {
        // 0x8000FE2C: nop

            goto L_8000FD28;
    }
    // 0x8000FE2C: nop

L_8000FE30:
    // 0x8000FE30: b           L_8000FE38
    // 0x8000FE34: nop

        goto L_8000FE38;
    // 0x8000FE34: nop

L_8000FE38:
    // 0x8000FE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FE3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000FE40: jr          $ra
    // 0x8000FE44: nop

    return;
    // 0x8000FE44: nop

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
RECOMP_FUNC void func_80010460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010460: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80010464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010468: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001046C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80010470: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80010474: nop

    // 0x80010478: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001047C: nop

    // 0x80010480: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80010484: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80010488: nop

    // 0x8001048C: bne         $t8, $zero, L_800105DC
    if (ctx->r24 != 0) {
        // 0x80010490: nop

            goto L_800105DC;
    }
    // 0x80010490: nop

    // 0x80010494: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80010498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001049C: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800104A0: lwc1        $f4, 0x30($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X30);
    // 0x800104A4: lwc1        $f10, 0x2C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x800104A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800104AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800104B0: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800104B4: swc1        $f16, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f16.u32l;
    // 0x800104B8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800104BC: lwc1        $f6, -0x2B7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B7C);
    // 0x800104C0: lwc1        $f18, 0x2C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x800104C4: lwc1        $f7, -0x2B80($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2B80);
    // 0x800104C8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800104CC: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800104D0: nop

    // 0x800104D4: bc1f        L_80010500
    if (!c1cs) {
        // 0x800104D8: nop

            goto L_80010500;
    }
    // 0x800104D8: nop

    // 0x800104DC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800104E0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800104E4: lwc1        $f10, 0x2C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x800104E8: lwc1        $f17, -0x2B78($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2B78);
    // 0x800104EC: lwc1        $f16, -0x2B74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B74);
    // 0x800104F0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800104F4: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x800104F8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800104FC: swc1        $f4, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->f4.u32l;
L_80010500:
    // 0x80010500: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80010504: nop

    // 0x80010508: lwc1        $f6, 0x38($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X38);
    // 0x8001050C: nop

    // 0x80010510: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80010514: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80010518: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001051C: lwc1        $f10, 0x2C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x80010520: lwc1        $f17, -0x2B70($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X2B70);
    // 0x80010524: lwc1        $f16, -0x2B6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B6C);
    // 0x80010528: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8001052C: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80010530: jal         0x800C3070
    // 0x80010534: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_0;
    // 0x80010534: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x80010538: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8001053C: nop

    // 0x80010540: lwc1        $f4, 0x34($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X34);
    // 0x80010544: nop

    // 0x80010548: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001054C: swc1        $f6, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f6.u32l;
    // 0x80010550: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80010554: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80010558: lwc1        $f10, 0x38($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X38);
    // 0x8001055C: nop

    // 0x80010560: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80010564: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x80010568: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001056C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80010570: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80010574: nop

    // 0x80010578: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8001057C: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80010580: nop

    // 0x80010584: blez        $t8, L_800105D4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80010588: nop

            goto L_800105D4;
    }
    // 0x80010588: nop

L_8001058C:
    // 0x8001058C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80010590: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80010594: lwc1        $f18, 0xCC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x80010598: nop

    // 0x8001059C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800105A0: swc1        $f6, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f6.u32l;
    // 0x800105A4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800105A8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800105AC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800105B0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800105B4: addiu       $t3, $t2, 0x160
    ctx->r11 = ADD32(ctx->r10, 0X160);
    // 0x800105B8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800105BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800105C0: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800105C4: nop

    // 0x800105C8: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800105CC: bne         $at, $zero, L_8001058C
    if (ctx->r1 != 0) {
        // 0x800105D0: nop

            goto L_8001058C;
    }
    // 0x800105D0: nop

L_800105D4:
    // 0x800105D4: b           L_80010724
    // 0x800105D8: nop

        goto L_80010724;
    // 0x800105D8: nop

L_800105DC:
    // 0x800105DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800105E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800105E4: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800105E8: lwc1        $f10, 0x40($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X40);
    // 0x800105EC: lwc1        $f18, 0x3C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x800105F0: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800105F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800105F8: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800105FC: swc1        $f4, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f4.u32l;
    // 0x80010600: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80010604: lwc1        $f8, -0x2B64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B64);
    // 0x80010608: lwc1        $f6, 0x3C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x8001060C: lwc1        $f9, -0x2B68($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X2B68);
    // 0x80010610: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80010614: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80010618: nop

    // 0x8001061C: bc1f        L_80010648
    if (!c1cs) {
        // 0x80010620: nop

            goto L_80010648;
    }
    // 0x80010620: nop

    // 0x80010624: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80010628: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001062C: lwc1        $f18, 0x3C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x80010630: lwc1        $f5, -0x2B60($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2B60);
    // 0x80010634: lwc1        $f4, -0x2B5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x80010638: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8001063C: sub.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f16.d - ctx->f4.d;
    // 0x80010640: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80010644: swc1        $f10, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f10.u32l;
L_80010648:
    // 0x80010648: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8001064C: nop

    // 0x80010650: lwc1        $f8, 0x48($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X48);
    // 0x80010654: nop

    // 0x80010658: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001065C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80010660: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80010664: lwc1        $f18, 0x3C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x80010668: lwc1        $f5, -0x2B58($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X2B58);
    // 0x8001066C: lwc1        $f4, -0x2B54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x80010670: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80010674: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80010678: jal         0x800C3070
    // 0x8001067C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_1;
    // 0x8001067C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    after_1:
    // 0x80010680: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80010684: nop

    // 0x80010688: lwc1        $f10, 0x44($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X44);
    // 0x8001068C: nop

    // 0x80010690: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80010694: swc1        $f8, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f8.u32l;
    // 0x80010698: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001069C: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800106A0: lwc1        $f18, 0x48($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X48);
    // 0x800106A4: nop

    // 0x800106A8: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800106AC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800106B0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800106B4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800106B8: lw          $t1, 0xC($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XC);
    // 0x800106BC: nop

    // 0x800106C0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800106C4: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800106C8: nop

    // 0x800106CC: blez        $t5, L_8001071C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800106D0: nop

            goto L_8001071C;
    }
    // 0x800106D0: nop

L_800106D4:
    // 0x800106D4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800106D8: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800106DC: lwc1        $f6, 0xD0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x800106E0: nop

    // 0x800106E4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800106E8: swc1        $f8, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f8.u32l;
    // 0x800106EC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800106F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800106F4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800106F8: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800106FC: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80010700: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80010704: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80010708: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x8001070C: nop

    // 0x80010710: slt         $at, $t8, $t3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80010714: bne         $at, $zero, L_800106D4
    if (ctx->r1 != 0) {
        // 0x80010718: nop

            goto L_800106D4;
    }
    // 0x80010718: nop

L_8001071C:
    // 0x8001071C: b           L_80010724
    // 0x80010720: nop

        goto L_80010724;
    // 0x80010720: nop

L_80010724:
    // 0x80010724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010728: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001072C: jr          $ra
    // 0x80010730: nop

    return;
    // 0x80010730: nop

;}
RECOMP_FUNC void func_80010734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010734: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001073C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80010740: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80010744: nop

    // 0x80010748: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x8001074C: nop

    // 0x80010750: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80010754: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80010758: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001075C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80010760: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80010764: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80010768: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001076C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80010770: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80010774: nop

    // 0x80010778: lwc1        $f16, 0x4C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4C);
    // 0x8001077C: nop

    // 0x80010780: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80010784: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80010788: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001078C: swc1        $f6, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = ctx->f6.u32l;
    // 0x80010790: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80010794: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80010798: lwc1        $f8, 0x4C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x8001079C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800107A0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800107A4: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x800107A8: nop

    // 0x800107AC: bc1f        L_800108A0
    if (!c1cs) {
        // 0x800107B0: nop

            goto L_800108A0;
    }
    // 0x800107B0: nop

L_800107B4:
    // 0x800107B4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800107B8: nop

    // 0x800107BC: lhu         $t1, 0x52($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X52);
    // 0x800107C0: addiu       $a0, $t0, 0xC
    ctx->r4 = ADD32(ctx->r8, 0XC);
    // 0x800107C4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800107C8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800107CC: lhu         $a2, 0x54($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X54);
    // 0x800107D0: jal         0x800B3DBC
    // 0x800107D4: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    func_800B3DBC(rdram, ctx);
        goto after_0;
    // 0x800107D4: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    after_0:
    // 0x800107D8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800107DC: nop

    // 0x800107E0: lhu         $t5, 0x50($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X50);
    // 0x800107E4: lwc1        $f10, 0x4C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4C);
    // 0x800107E8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800107EC: bgez        $t5, L_80010804
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800107F0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80010804;
    }
    // 0x800107F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800107F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800107F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800107FC: nop

    // 0x80010800: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80010804:
    // 0x80010804: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80010808: swc1        $f16, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f16.u32l;
    // 0x8001080C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80010810: nop

    // 0x80010814: lhu         $t7, 0x52($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X52);
    // 0x80010818: nop

    // 0x8001081C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80010820: sh          $t8, 0x52($t6)
    MEM_H(0X52, ctx->r14) = ctx->r24;
    // 0x80010824: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80010828: nop

    // 0x8001082C: lhu         $t1, 0x52($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X52);
    // 0x80010830: nop

    // 0x80010834: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80010838: beq         $at, $zero, L_80010870
    if (ctx->r1 == 0) {
        // 0x8001083C: nop

            goto L_80010870;
    }
    // 0x8001083C: nop

    // 0x80010840: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80010844: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80010848: lhu         $t2, 0x52($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X52);
    // 0x8001084C: nop

    // 0x80010850: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80010854: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x80010858: lhu         $t4, 0x54($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X54);
    // 0x8001085C: nop

    // 0x80010860: beq         $t4, $at, L_80010870
    if (ctx->r12 == ctx->r1) {
        // 0x80010864: nop

            goto L_80010870;
    }
    // 0x80010864: nop

    // 0x80010868: b           L_8001087C
    // 0x8001086C: nop

        goto L_8001087C;
    // 0x8001086C: nop

L_80010870:
    // 0x80010870: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80010874: nop

    // 0x80010878: sh          $zero, 0x52($t7)
    MEM_H(0X52, ctx->r15) = 0;
L_8001087C:
    // 0x8001087C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80010880: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80010884: lwc1        $f18, 0x4C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4C);
    // 0x80010888: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001088C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80010890: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80010894: nop

    // 0x80010898: bc1t        L_800107B4
    if (c1cs) {
        // 0x8001089C: nop

            goto L_800107B4;
    }
    // 0x8001089C: nop

L_800108A0:
    // 0x800108A0: b           L_800108A8
    // 0x800108A4: nop

        goto L_800108A8;
    // 0x800108A4: nop

L_800108A8:
    // 0x800108A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800108AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800108B0: jr          $ra
    // 0x800108B4: nop

    return;
    // 0x800108B4: nop

;}
RECOMP_FUNC void func_800108B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800108B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800108BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800108C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800108C4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800108C8: nop

    // 0x800108CC: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800108D0: nop

    // 0x800108D4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800108D8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800108DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800108E0: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800108E4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800108E8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800108EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800108F0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800108F4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800108F8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800108FC: nop

    // 0x80010900: lwc1        $f16, 0x80($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X80);
    // 0x80010904: nop

    // 0x80010908: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001090C: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x80010910: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80010914: swc1        $f6, 0x80($t8)
    MEM_W(0X80, ctx->r24) = ctx->f6.u32l;
    // 0x80010918: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001091C: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80010920: lwc1        $f8, 0x80($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X80);
    // 0x80010924: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80010928: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8001092C: c.le.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d <= ctx->f18.d;
    // 0x80010930: nop

    // 0x80010934: bc1f        L_800109E0
    if (!c1cs) {
        // 0x80010938: nop

            goto L_800109E0;
    }
    // 0x80010938: nop

L_8001093C:
    // 0x8001093C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80010940: nop

    // 0x80010944: lhu         $t1, 0x8E($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8E);
    // 0x80010948: nop

    // 0x8001094C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80010950: sh          $t2, 0x8E($t0)
    MEM_H(0X8E, ctx->r8) = ctx->r10;
    // 0x80010954: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80010958: nop

    // 0x8001095C: lhu         $t4, 0x8E($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8E);
    // 0x80010960: lhu         $t5, 0x8C($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X8C);
    // 0x80010964: nop

    // 0x80010968: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001096C: bne         $at, $zero, L_80010980
    if (ctx->r1 != 0) {
        // 0x80010970: nop

            goto L_80010980;
    }
    // 0x80010970: nop

    // 0x80010974: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80010978: nop

    // 0x8001097C: sh          $zero, 0x8E($t6)
    MEM_H(0X8E, ctx->r14) = 0;
L_80010980:
    // 0x80010980: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80010984: nop

    // 0x80010988: lhu         $t8, 0x84($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X84);
    // 0x8001098C: lwc1        $f10, 0x80($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X80);
    // 0x80010990: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80010994: bgez        $t8, L_800109AC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80010998: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800109AC;
    }
    // 0x80010998: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001099C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800109A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800109A4: nop

    // 0x800109A8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800109AC:
    // 0x800109AC: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800109B0: swc1        $f16, 0x80($t7)
    MEM_W(0X80, ctx->r15) = ctx->f16.u32l;
    // 0x800109B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800109B8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800109BC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800109C0: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800109C4: lwc1        $f18, 0x80($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X80);
    // 0x800109C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800109CC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800109D0: c.le.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d <= ctx->f8.d;
    // 0x800109D4: nop

    // 0x800109D8: bc1t        L_8001093C
    if (c1cs) {
        // 0x800109DC: nop

            goto L_8001093C;
    }
    // 0x800109DC: nop

L_800109E0:
    // 0x800109E0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800109E4: nop

    // 0x800109E8: beq         $t2, $zero, L_80010AB0
    if (ctx->r10 == 0) {
        // 0x800109EC: nop

            goto L_80010AB0;
    }
    // 0x800109EC: nop

    // 0x800109F0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800109F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800109F8: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800109FC: nop

    // 0x80010A00: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80010A04: lhu         $t4, 0x6($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X6);
    // 0x80010A08: nop

    // 0x80010A0C: blez        $t4, L_80010AB0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010A10: nop

            goto L_80010AB0;
    }
    // 0x80010A10: nop

L_80010A14:
    // 0x80010A14: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80010A18: nop

    // 0x80010A1C: lw          $t6, 0x138($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X138);
    // 0x80010A20: nop

    // 0x80010A24: bne         $t6, $zero, L_80010A34
    if (ctx->r14 != 0) {
        // 0x80010A28: nop

            goto L_80010A34;
    }
    // 0x80010A28: nop

    // 0x80010A2C: b           L_80010A80
    // 0x80010A30: nop

        goto L_80010A80;
    // 0x80010A30: nop

L_80010A34:
    // 0x80010A34: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80010A38: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80010A3C: lh          $t5, 0x90($t9)
    ctx->r13 = MEM_H(ctx->r25, 0X90);
    // 0x80010A40: lhu         $t6, 0x8E($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X8E);
    // 0x80010A44: lhu         $t1, 0x86($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X86);
    // 0x80010A48: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80010A4C: lw          $t7, 0x138($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X138);
    // 0x80010A50: lhu         $t3, 0x88($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X88);
    // 0x80010A54: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80010A58: lhu         $a2, 0x8A($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X8A);
    // 0x80010A5C: addu        $a0, $t7, $t2
    ctx->r4 = ADD32(ctx->r15, ctx->r10);
    // 0x80010A60: sll         $t0, $t3, 1
    ctx->r8 = S32(ctx->r11 << 1);
    // 0x80010A64: addu        $t4, $t7, $t0
    ctx->r12 = ADD32(ctx->r15, ctx->r8);
    // 0x80010A68: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x80010A6C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80010A70: mflo        $t8
    ctx->r24 = lo;
    // 0x80010A74: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x80010A78: jal         0x800BCFCC
    // 0x80010A7C: addu        $a1, $t4, $t1
    ctx->r5 = ADD32(ctx->r12, ctx->r9);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x80010A7C: addu        $a1, $t4, $t1
    ctx->r5 = ADD32(ctx->r12, ctx->r9);
    after_0:
L_80010A80:
    // 0x80010A80: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80010A84: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80010A88: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80010A8C: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x80010A90: addiu       $t5, $t0, 0x160
    ctx->r13 = ADD32(ctx->r8, 0X160);
    // 0x80010A94: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80010A98: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80010A9C: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80010AA0: nop

    // 0x80010AA4: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80010AA8: bne         $at, $zero, L_80010A14
    if (ctx->r1 != 0) {
        // 0x80010AAC: nop

            goto L_80010A14;
    }
    // 0x80010AAC: nop

L_80010AB0:
    // 0x80010AB0: b           L_80010AB8
    // 0x80010AB4: nop

        goto L_80010AB8;
    // 0x80010AB4: nop

L_80010AB8:
    // 0x80010AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010ABC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80010AC0: jr          $ra
    // 0x80010AC4: nop

    return;
    // 0x80010AC4: nop

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
RECOMP_FUNC void func_80011040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011040: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011048: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001104C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80011050: nop

    // 0x80011054: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80011058: nop

    // 0x8001105C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80011060: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80011064: nop

    // 0x80011068: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x8001106C: nop

    // 0x80011070: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80011074: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80011078: nop

    // 0x8001107C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80011080: nop

    // 0x80011084: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80011088: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001108C: jal         0x8001ABEC
    // 0x80011090: nop

    func_8001ABEC(rdram, ctx);
        goto after_0;
    // 0x80011090: nop

    after_0:
    // 0x80011094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011098: jal         0x8008EAA8
    // 0x8001109C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_1;
    // 0x8001109C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800110A0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800110A4: nop

    // 0x800110A8: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800110AC: nop

    // 0x800110B0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800110B4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800110B8: nop

    // 0x800110BC: beq         $t4, $zero, L_800111A4
    if (ctx->r12 == 0) {
        // 0x800110C0: nop

            goto L_800111A4;
    }
    // 0x800110C0: nop

L_800110C4:
    // 0x800110C4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800110C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800110CC: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800110D0: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x800110D4: jal         0x800BD218
    // 0x800110D8: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800110D8: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_2:
    // 0x800110DC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800110E0: nop

    // 0x800110E4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800110E8: nop

    // 0x800110EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800110F0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800110F4: nop

    // 0x800110F8: beq         $t9, $zero, L_80011138
    if (ctx->r25 == 0) {
        // 0x800110FC: nop

            goto L_80011138;
    }
    // 0x800110FC: nop

    // 0x80011100: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80011104: beq         $t9, $at, L_80011138
    if (ctx->r25 == ctx->r1) {
        // 0x80011108: nop

            goto L_80011138;
    }
    // 0x80011108: nop

L_8001110C:
    // 0x8001110C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80011110: nop

    // 0x80011114: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80011118: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8001111C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80011120: nop

    // 0x80011124: beq         $t2, $zero, L_80011138
    if (ctx->r10 == 0) {
        // 0x80011128: nop

            goto L_80011138;
    }
    // 0x80011128: nop

    // 0x8001112C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80011130: bne         $t2, $at, L_8001110C
    if (ctx->r10 != ctx->r1) {
        // 0x80011134: nop

            goto L_8001110C;
    }
    // 0x80011134: nop

L_80011138:
    // 0x80011138: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001113C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80011140: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80011144: nop

    // 0x80011148: bne         $t4, $at, L_80011170
    if (ctx->r12 != ctx->r1) {
        // 0x8001114C: nop

            goto L_80011170;
    }
    // 0x8001114C: nop

    // 0x80011150: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80011154: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80011158: lbu         $a1, 0x7208($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7208);
    // 0x8001115C: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x80011160: jal         0x8008ECE4
    // 0x80011164: nop

    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x80011164: nop

    after_3:
    // 0x80011168: b           L_80011184
    // 0x8001116C: nop

        goto L_80011184;
    // 0x8001116C: nop

L_80011170:
    // 0x80011170: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80011174: nop

    // 0x80011178: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8001117C: jal         0x8008ECE4
    // 0x80011180: nop

    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x80011180: nop

    after_4:
L_80011184:
    // 0x80011184: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80011188: nop

    // 0x8001118C: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80011190: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80011194: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80011198: nop

    // 0x8001119C: bne         $t9, $zero, L_800110C4
    if (ctx->r25 != 0) {
        // 0x800111A0: nop

            goto L_800110C4;
    }
    // 0x800111A0: nop

L_800111A4:
    // 0x800111A4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800111A8: nop

    // 0x800111AC: lw          $t1, 0x138($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X138);
    // 0x800111B0: nop

    // 0x800111B4: sh          $zero, 0x20($t1)
    MEM_H(0X20, ctx->r9) = 0;
    // 0x800111B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800111BC: jal         0x8001ACDC
    // 0x800111C0: nop

    func_8001ACDC(rdram, ctx);
        goto after_5;
    // 0x800111C0: nop

    after_5:
    // 0x800111C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800111C8: jal         0x8001ADBC
    // 0x800111CC: nop

    func_8001ADBC(rdram, ctx);
        goto after_6;
    // 0x800111CC: nop

    after_6:
    // 0x800111D0: b           L_800111D8
    // 0x800111D4: nop

        goto L_800111D8;
    // 0x800111D4: nop

L_800111D8:
    // 0x800111D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800111DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800111E0: jr          $ra
    // 0x800111E4: nop

    return;
    // 0x800111E4: nop

;}
RECOMP_FUNC void func_800111E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800111E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800111EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800111F0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800111F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800111F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800111FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80011200: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80011204: jal         0x8000DA44
    // 0x80011208: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80011208: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8001120C: bgez        $v0, L_8001121C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011210: nop

            goto L_8001121C;
    }
    // 0x80011210: nop

    // 0x80011214: b           L_80011728
    // 0x80011218: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011728;
    // 0x80011218: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001121C:
    // 0x8001121C: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80011220: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80011224: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80011228: nop

    // 0x8001122C: sh          $t7, 0x208($t8)
    MEM_H(0X208, ctx->r24) = ctx->r15;
    // 0x80011230: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x80011234: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80011238: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8001123C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80011240: nop

    // 0x80011244: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011248: swc1        $f6, 0x1B0($t1)
    MEM_W(0X1B0, ctx->r9) = ctx->f6.u32l;
    // 0x8001124C: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x80011250: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x80011254: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80011258: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8001125C: nop

    // 0x80011260: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80011264: swc1        $f10, 0x1B4($t4)
    MEM_W(0X1B4, ctx->r12) = ctx->f10.u32l;
    // 0x80011268: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x8001126C: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x80011270: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80011274: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80011278: nop

    // 0x8001127C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80011280: swc1        $f18, 0x1B8($t7)
    MEM_W(0X1B8, ctx->r15) = ctx->f18.u32l;
    // 0x80011284: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80011288: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x8001128C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80011290: nop

    // 0x80011294: sh          $t9, 0x20A($t0)
    MEM_H(0X20A, ctx->r8) = ctx->r25;
    // 0x80011298: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8001129C: nop

    // 0x800112A0: lw          $t2, 0x20C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20C);
    // 0x800112A4: nop

    // 0x800112A8: bne         $t2, $zero, L_800112C4
    if (ctx->r10 != 0) {
        // 0x800112AC: nop

            goto L_800112C4;
    }
    // 0x800112AC: nop

    // 0x800112B0: jal         0x8000D164
    // 0x800112B4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    TempHeap_Alloc(rdram, ctx);
        goto after_1;
    // 0x800112B4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x800112B8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800112BC: nop

    // 0x800112C0: sw          $v0, 0x20C($t3)
    MEM_W(0X20C, ctx->r11) = ctx->r2;
L_800112C4:
    // 0x800112C4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800112C8: nop

    // 0x800112CC: lw          $t5, 0x20C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20C);
    // 0x800112D0: nop

    // 0x800112D4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800112D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800112DC: jal         0x8000E3D4
    // 0x800112E0: nop

    func_8000E3D4(rdram, ctx);
        goto after_2;
    // 0x800112E0: nop

    after_2:
    // 0x800112E4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800112E8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800112EC: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800112F0: nop

    // 0x800112F4: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800112F8: bne         $at, $zero, L_80011424
    if (ctx->r1 != 0) {
        // 0x800112FC: nop

            goto L_80011424;
    }
    // 0x800112FC: nop

    // 0x80011300: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80011304: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011308: beq         $at, $zero, L_80011424
    if (ctx->r1 == 0) {
        // 0x8001130C: nop

            goto L_80011424;
    }
    // 0x8001130C: nop

    // 0x80011310: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80011314: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x80011318: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8001131C: nop

    // 0x80011320: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80011324: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80011328: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001132C: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
    // 0x80011330: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80011334: nop

    // 0x80011338: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    // 0x8001133C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80011340: nop

    // 0x80011344: sw          $zero, 0x10($t4)
    MEM_W(0X10, ctx->r12) = 0;
    // 0x80011348: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001134C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80011350: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80011354: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80011358: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001135C: lw          $t8, 0x1AC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1AC);
    // 0x80011360: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x80011364: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80011368: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001136C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80011370: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80011374: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80011378: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8001137C: lui         $at, 0xFF50
    ctx->r1 = S32(0XFF50 << 16);
    // 0x80011380: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x80011384: addu        $s0, $s0, $at
    ctx->r16 = ADD32(ctx->r16, ctx->r1);
    // 0x80011388: sw          $s0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r16;
    // 0x8001138C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80011390: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80011394: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80011398: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x8001139C: nop

    // 0x800113A0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800113A4: bne         $t4, $zero, L_800113B4
    if (ctx->r12 != 0) {
        // 0x800113A8: nop

            goto L_800113B4;
    }
    // 0x800113A8: nop

    // 0x800113AC: b           L_80011728
    // 0x800113B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011728;
    // 0x800113B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800113B4:
    // 0x800113B4: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800113B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800113BC: lwc1        $f4, 0x1B0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X1B0);
    // 0x800113C0: nop

    // 0x800113C4: swc1        $f4, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f4.u32l;
    // 0x800113C8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800113CC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800113D0: lwc1        $f6, 0x1B4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1B4);
    // 0x800113D4: nop

    // 0x800113D8: swc1        $f6, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f6.u32l;
    // 0x800113DC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800113E0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800113E4: lwc1        $f8, 0x1B8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X1B8);
    // 0x800113E8: nop

    // 0x800113EC: swc1        $f8, 0xD4($t0)
    MEM_W(0XD4, ctx->r8) = ctx->f8.u32l;
    // 0x800113F0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800113F4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800113F8: lhu         $t2, 0x20A($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X20A);
    // 0x800113FC: nop

    // 0x80011400: beq         $t2, $at, L_8001141C
    if (ctx->r10 == ctx->r1) {
        // 0x80011404: nop

            goto L_8001141C;
    }
    // 0x80011404: nop

    // 0x80011408: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8001140C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80011410: lhu         $t4, 0x20A($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X20A);
    // 0x80011414: nop

    // 0x80011418: sh          $t4, 0x124($t5)
    MEM_H(0X124, ctx->r13) = ctx->r12;
L_8001141C:
    // 0x8001141C: b           L_80011700
    // 0x80011420: nop

        goto L_80011700;
    // 0x80011420: nop

L_80011424:
    // 0x80011424: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80011428: nop

    // 0x8001142C: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x80011430: nop

    // 0x80011434: slti        $at, $t7, 0x4000
    ctx->r1 = SIGNED(ctx->r15) < 0X4000 ? 1 : 0;
    // 0x80011438: bne         $at, $zero, L_800114A8
    if (ctx->r1 != 0) {
        // 0x8001143C: nop

            goto L_800114A8;
    }
    // 0x8001143C: nop

    // 0x80011440: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80011444: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011448: beq         $at, $zero, L_800114A8
    if (ctx->r1 == 0) {
        // 0x8001144C: nop

            goto L_800114A8;
    }
    // 0x8001144C: nop

    // 0x80011450: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80011454: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x80011458: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8001145C: nop

    // 0x80011460: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80011464: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80011468: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001146C: sh          $t1, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r9;
    // 0x80011470: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80011474: nop

    // 0x80011478: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    // 0x8001147C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80011480: nop

    // 0x80011484: sw          $zero, 0x10($t4)
    MEM_W(0X10, ctx->r12) = 0;
    // 0x80011488: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001148C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80011490: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x80011494: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80011498: jal         0x80014C70
    // 0x8001149C: nop

    func_80014C70(rdram, ctx);
        goto after_3;
    // 0x8001149C: nop

    after_3:
    // 0x800114A0: b           L_80011700
    // 0x800114A4: nop

        goto L_80011700;
    // 0x800114A4: nop

L_800114A8:
    // 0x800114A8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800114AC: nop

    // 0x800114B0: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x800114B4: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x800114B8: lhu         $s1, 0x2($t8)
    ctx->r17 = MEM_HU(ctx->r24, 0X2);
    // 0x800114BC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800114C0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800114C4: beq         $s1, $at, L_800116D0
    if (ctx->r17 == ctx->r1) {
        // 0x800114C8: sh          $s1, 0x2($t9)
        MEM_H(0X2, ctx->r25) = ctx->r17;
            goto L_800116D0;
    }
    // 0x800114C8: sh          $s1, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r17;
    // 0x800114CC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800114D0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800114D4: lw          $t1, 0x1AC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1AC);
    // 0x800114D8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800114DC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800114E0: lbu         $t2, -0x6230($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X6230);
    // 0x800114E4: nop

    // 0x800114E8: sh          $t2, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r10;
    // 0x800114EC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800114F0: nop

    // 0x800114F4: lhu         $a0, 0x6($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X6);
    // 0x800114F8: nop

    // 0x800114FC: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80011500: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x80011504: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80011508: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8001150C: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80011510: jal         0x8000D164
    // 0x80011514: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    TempHeap_Alloc(rdram, ctx);
        goto after_4;
    // 0x80011514: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_4:
    // 0x80011518: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001151C: nop

    // 0x80011520: sw          $v0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r2;
    // 0x80011524: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80011528: nop

    // 0x8001152C: lhu         $a0, 0x6($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X6);
    // 0x80011530: nop

    // 0x80011534: sll         $t8, $a0, 6
    ctx->r24 = S32(ctx->r4 << 6);
    // 0x80011538: jal         0x8000D164
    // 0x8001153C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    TempHeap_Alloc(rdram, ctx);
        goto after_5;
    // 0x8001153C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_5:
    // 0x80011540: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80011544: nop

    // 0x80011548: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
    // 0x8001154C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80011550: nop

    // 0x80011554: lhu         $a2, 0x6($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X6);
    // 0x80011558: addiu       $a0, $t0, 0xC
    ctx->r4 = ADD32(ctx->r8, 0XC);
    // 0x8001155C: jal         0x800B1B3C
    // 0x80011560: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    func_800B1B3C(rdram, ctx);
        goto after_6;
    // 0x80011560: addiu       $a1, $t0, 0x10
    ctx->r5 = ADD32(ctx->r8, 0X10);
    after_6:
    // 0x80011564: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80011568: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8001156C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80011570: nop

    // 0x80011574: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80011578: lhu         $t3, 0x6($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X6);
    // 0x8001157C: nop

    // 0x80011580: blez        $t3, L_80011684
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80011584: nop

            goto L_80011684;
    }
    // 0x80011584: nop

L_80011588:
    // 0x80011588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001158C: jal         0x80099E2C
    // 0x80011590: nop

    func_80099E2C(rdram, ctx);
        goto after_7;
    // 0x80011590: nop

    after_7:
    // 0x80011594: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80011598: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001159C: lwc1        $f10, 0x1B0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X1B0);
    // 0x800115A0: nop

    // 0x800115A4: swc1        $f10, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f10.u32l;
    // 0x800115A8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800115AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800115B0: lwc1        $f18, -0x71C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x800115B4: lwc1        $f16, 0x1B4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X1B4);
    // 0x800115B8: lwc1        $f8, 0x1B8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1B8);
    // 0x800115BC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800115C0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800115C4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800115C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800115CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800115D0: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800115D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800115D8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800115DC: add.d       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f6.d + ctx->f18.d;
    // 0x800115E0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800115E4: swc1        $f8, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f8.u32l;
    // 0x800115E8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800115EC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800115F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800115F4: lwc1        $f16, 0x1B8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1B8);
    // 0x800115F8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800115FC: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80011600: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80011604: nop

    // 0x80011608: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001160C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011614: nop

    // 0x80011618: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001161C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80011620: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80011624: sw          $t0, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r8;
    // 0x80011628: nop

    // 0x8001162C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80011630: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80011634: nop

    // 0x80011638: swc1        $f4, 0xD4($t1)
    MEM_W(0XD4, ctx->r9) = ctx->f4.u32l;
    // 0x8001163C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80011640: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80011644: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
    // 0x80011648: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001164C: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80011650: sh          $t5, 0xC4($t6)
    MEM_H(0XC4, ctx->r14) = ctx->r13;
    // 0x80011654: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80011658: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001165C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80011660: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80011664: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80011668: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8001166C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80011670: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x80011674: nop

    // 0x80011678: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001167C: bne         $at, $zero, L_80011588
    if (ctx->r1 != 0) {
        // 0x80011680: nop

            goto L_80011588;
    }
    // 0x80011680: nop

L_80011684:
    // 0x80011684: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80011688: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001168C: lhu         $t4, 0x20A($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X20A);
    // 0x80011690: nop

    // 0x80011694: bne         $t4, $at, L_800116B4
    if (ctx->r12 != ctx->r1) {
        // 0x80011698: nop

            goto L_800116B4;
    }
    // 0x80011698: nop

    // 0x8001169C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800116A0: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x800116A4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800116A8: lh          $t6, 0x42($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X42);
    // 0x800116AC: b           L_800116C8
    // 0x800116B0: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
        goto L_800116C8;
    // 0x800116B0: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
L_800116B4:
    // 0x800116B4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800116B8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800116BC: lhu         $t0, 0x20A($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X20A);
    // 0x800116C0: nop

    // 0x800116C4: sh          $t0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r8;
L_800116C8:
    // 0x800116C8: b           L_80011700
    // 0x800116CC: nop

        goto L_80011700;
    // 0x800116CC: nop

L_800116D0:
    // 0x800116D0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800116D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800116D8: sh          $t8, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r24;
    // 0x800116DC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800116E0: nop

    // 0x800116E4: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    // 0x800116E8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800116EC: nop

    // 0x800116F0: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
    // 0x800116F4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800116F8: nop

    // 0x800116FC: sw          $zero, 0x10($t5)
    MEM_W(0X10, ctx->r13) = 0;
L_80011700:
    // 0x80011700: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80011704: nop

    // 0x80011708: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x8001170C: nop

    // 0x80011710: ori         $t9, $t7, 0x1
    ctx->r25 = ctx->r15 | 0X1;
    // 0x80011714: sw          $t9, 0x1A8($t6)
    MEM_W(0X1A8, ctx->r14) = ctx->r25;
    // 0x80011718: b           L_80011728
    // 0x8001171C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011728;
    // 0x8001171C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011720: b           L_80011728
    // 0x80011724: nop

        goto L_80011728;
    // 0x80011724: nop

L_80011728:
    // 0x80011728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001172C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80011730: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80011734: jr          $ra
    // 0x80011738: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80011738: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
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
RECOMP_FUNC void func_80011A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011A0C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80011A10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80011A14: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80011A18: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80011A1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80011A20: jal         0x8000DA44
    // 0x80011A24: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80011A24: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80011A28: bgez        $v0, L_80011A38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011A2C: nop

            goto L_80011A38;
    }
    // 0x80011A2C: nop

    // 0x80011A30: b           L_80011B78
    // 0x80011A34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011B78;
    // 0x80011A34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011A38:
    // 0x80011A38: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80011A3C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80011A40: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x80011A44: nop

    // 0x80011A48: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011A4C: bne         $at, $zero, L_80011A6C
    if (ctx->r1 != 0) {
        // 0x80011A50: nop

            goto L_80011A6C;
    }
    // 0x80011A50: nop

    // 0x80011A54: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x80011A58: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011A5C: beq         $at, $zero, L_80011A6C
    if (ctx->r1 == 0) {
        // 0x80011A60: nop

            goto L_80011A6C;
    }
    // 0x80011A60: nop

    // 0x80011A64: b           L_80011B78
    // 0x80011A68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011B78;
    // 0x80011A68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011A6C:
    // 0x80011A6C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80011A70: lh          $t8, -0x7290($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7290);
    // 0x80011A74: nop

    // 0x80011A78: slti        $at, $t8, 0x1F4
    ctx->r1 = SIGNED(ctx->r24) < 0X1F4 ? 1 : 0;
    // 0x80011A7C: beq         $at, $zero, L_80011ACC
    if (ctx->r1 == 0) {
        // 0x80011A80: nop

            goto L_80011ACC;
    }
    // 0x80011A80: nop

    // 0x80011A84: lui         $t9, 0x8098
    ctx->r25 = S32(0X8098 << 16);
    // 0x80011A88: addiu       $t9, $t9, -0xB30
    ctx->r25 = ADD32(ctx->r25, -0XB30);
    // 0x80011A8C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80011A90: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80011A94: lw          $t0, 0x3070($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3070);
    // 0x80011A98: nop

    // 0x80011A9C: bne         $t0, $zero, L_80011AB4
    if (ctx->r8 != 0) {
        // 0x80011AA0: nop

            goto L_80011AB4;
    }
    // 0x80011AA0: nop

    // 0x80011AA4: lui         $t1, 0x8098
    ctx->r9 = S32(0X8098 << 16);
    // 0x80011AA8: addiu       $t1, $t1, 0x1A00
    ctx->r9 = ADD32(ctx->r9, 0X1A00);
    // 0x80011AAC: b           L_80011AC4
    // 0x80011AB0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
        goto L_80011AC4;
    // 0x80011AB0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80011AB4:
    // 0x80011AB4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80011AB8: lw          $t2, 0x3070($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3070);
    // 0x80011ABC: nop

    // 0x80011AC0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_80011AC4:
    // 0x80011AC4: b           L_80011B0C
    // 0x80011AC8: nop

        goto L_80011B0C;
    // 0x80011AC8: nop

L_80011ACC:
    // 0x80011ACC: lui         $t3, 0x8099
    ctx->r11 = S32(0X8099 << 16);
    // 0x80011AD0: addiu       $t3, $t3, 0x68B0
    ctx->r11 = ADD32(ctx->r11, 0X68B0);
    // 0x80011AD4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80011AD8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80011ADC: lw          $t4, 0x3078($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3078);
    // 0x80011AE0: nop

    // 0x80011AE4: bne         $t4, $zero, L_80011AFC
    if (ctx->r12 != 0) {
        // 0x80011AE8: nop

            goto L_80011AFC;
    }
    // 0x80011AE8: nop

    // 0x80011AEC: lui         $t5, 0x80B0
    ctx->r13 = S32(0X80B0 << 16);
    // 0x80011AF0: addiu       $t5, $t5, 0x4E40
    ctx->r13 = ADD32(ctx->r13, 0X4E40);
    // 0x80011AF4: b           L_80011B0C
    // 0x80011AF8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
        goto L_80011B0C;
    // 0x80011AF8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_80011AFC:
    // 0x80011AFC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80011B00: lw          $t6, 0x3078($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3078);
    // 0x80011B04: nop

    // 0x80011B08: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80011B0C:
    // 0x80011B0C: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x80011B10: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80011B14: addiu       $t8, $sp, 0x3C
    ctx->r24 = ADD32(ctx->r29, 0X3C);
    // 0x80011B18: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x80011B1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80011B20: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80011B24: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80011B28: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80011B2C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80011B30: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80011B34: jal         0x80096B38
    // 0x80011B38: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_80096B38(rdram, ctx);
        goto after_1;
    // 0x80011B38: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x80011B3C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80011B40: jal         0x80031874
    // 0x80011B44: nop

    func_80031874(rdram, ctx);
        goto after_2;
    // 0x80011B44: nop

    after_2:
    // 0x80011B48: beq         $v0, $zero, L_80011B50
    if (ctx->r2 == 0) {
        // 0x80011B4C: nop

            goto L_80011B50;
    }
    // 0x80011B4C: nop

L_80011B50:
    // 0x80011B50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80011B54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80011B58: jal         0x80096C6C
    // 0x80011B5C: nop

    func_80096C6C(rdram, ctx);
        goto after_3;
    // 0x80011B5C: nop

    after_3:
    // 0x80011B60: jal         0x80031B6C
    // 0x80011B64: nop

    func_80031B6C(rdram, ctx);
        goto after_4;
    // 0x80011B64: nop

    after_4:
    // 0x80011B68: b           L_80011B78
    // 0x80011B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011B78;
    // 0x80011B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011B70: b           L_80011B78
    // 0x80011B74: nop

        goto L_80011B78;
    // 0x80011B74: nop

L_80011B78:
    // 0x80011B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011B7C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80011B80: jr          $ra
    // 0x80011B84: nop

    return;
    // 0x80011B84: nop

;}
RECOMP_FUNC void func_80011B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011B88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011B90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80011B94: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80011B98: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80011B9C: jal         0x8000DA44
    // 0x80011BA0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80011BA0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80011BA4: bgez        $v0, L_80011BB4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011BA8: nop

            goto L_80011BB4;
    }
    // 0x80011BA8: nop

    // 0x80011BAC: b           L_80011F6C
    // 0x80011BB0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80011F6C;
    // 0x80011BB0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011BB4:
    // 0x80011BB4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80011BB8: nop

    // 0x80011BBC: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x80011BC0: nop

    // 0x80011BC4: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x80011BC8: sw          $t8, 0x1A8($t6)
    MEM_W(0X1A8, ctx->r14) = ctx->r24;
    // 0x80011BCC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80011BD0: nop

    // 0x80011BD4: lw          $t0, 0x20C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20C);
    // 0x80011BD8: nop

    // 0x80011BDC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80011BE0: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x80011BE4: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x80011BE8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011BEC: nop

    // 0x80011BF0: sh          $t2, 0x62($t3)
    MEM_H(0X62, ctx->r11) = ctx->r10;
    // 0x80011BF4: addiu       $t4, $sp, 0x24
    ctx->r12 = ADD32(ctx->r29, 0X24);
    // 0x80011BF8: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x80011BFC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80011C00: nop

    // 0x80011C04: sh          $t5, 0x64($t7)
    MEM_H(0X64, ctx->r15) = ctx->r13;
    // 0x80011C08: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x80011C0C: lhu         $t6, 0x6($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X6);
    // 0x80011C10: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80011C14: nop

    // 0x80011C18: sh          $t6, 0x66($t9)
    MEM_H(0X66, ctx->r25) = ctx->r14;
    // 0x80011C1C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80011C20: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80011C24: lhu         $t1, 0x62($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X62);
    // 0x80011C28: ori         $at, $at, 0x1FFE
    ctx->r1 = ctx->r1 | 0X1FFE;
    // 0x80011C2C: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x80011C30: sltiu       $at, $t2, 0xF
    ctx->r1 = ctx->r10 < 0XF ? 1 : 0;
    // 0x80011C34: beq         $at, $zero, L_80011F5C
    if (ctx->r1 == 0) {
        // 0x80011C38: nop

            goto L_80011F5C;
    }
    // 0x80011C38: nop

    // 0x80011C3C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80011C40: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80011C44: addu        $at, $at, $t2
    gpr jr_addend_80011C50 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80011C48: lw          $t2, -0x2B38($at)
    ctx->r10 = ADD32(ctx->r1, -0X2B38);
    // 0x80011C4C: nop

    // 0x80011C50: jr          $t2
    // 0x80011C54: nop

    switch (jr_addend_80011C50 >> 2) {
        case 0: goto L_80011C58; break;
        case 1: goto L_80011CA8; break;
        case 2: goto L_80011F5C; break;
        case 3: goto L_80011F5C; break;
        case 4: goto L_80011F5C; break;
        case 5: goto L_80011F5C; break;
        case 6: goto L_80011CF8; break;
        case 7: goto L_80011DC4; break;
        case 8: goto L_80011E0C; break;
        case 9: goto L_80011E5C; break;
        case 10: goto L_80011EAC; break;
        case 11: goto L_80011EFC; break;
        case 12: goto L_80011C58; break;
        case 13: goto L_80011CA8; break;
        case 14: goto L_80011CF8; break;
        default: switch_error(__func__, 0x80011C50, 0x800ED4C8);
    }
    // 0x80011C54: nop

L_80011C58:
    // 0x80011C58: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011C5C: nop

    // 0x80011C60: lh          $t5, 0x66($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X66);
    // 0x80011C64: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80011C68: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80011C6C: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x80011C70: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80011C74: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80011C78: nop

    // 0x80011C7C: bc1f        L_80011C94
    if (!c1cs) {
        // 0x80011C80: nop

            goto L_80011C94;
    }
    // 0x80011C80: nop

    // 0x80011C84: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011C88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80011C8C: b           L_80011CA0
    // 0x80011C90: sh          $t7, 0x68($t8)
    MEM_H(0X68, ctx->r24) = ctx->r15;
        goto L_80011CA0;
    // 0x80011C90: sh          $t7, 0x68($t8)
    MEM_H(0X68, ctx->r24) = ctx->r15;
L_80011C94:
    // 0x80011C94: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80011C98: nop

    // 0x80011C9C: sh          $zero, 0x68($t6)
    MEM_H(0X68, ctx->r14) = 0;
L_80011CA0:
    // 0x80011CA0: b           L_80011F5C
    // 0x80011CA4: nop

        goto L_80011F5C;
    // 0x80011CA4: nop

L_80011CA8:
    // 0x80011CA8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80011CAC: nop

    // 0x80011CB0: lh          $t1, 0x66($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X66);
    // 0x80011CB4: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80011CB8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80011CBC: lwc1        $f10, 0xD0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80011CC0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80011CC4: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80011CC8: nop

    // 0x80011CCC: bc1f        L_80011CE4
    if (!c1cs) {
        // 0x80011CD0: nop

            goto L_80011CE4;
    }
    // 0x80011CD0: nop

    // 0x80011CD4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80011CD8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80011CDC: b           L_80011CF0
    // 0x80011CE0: sh          $t2, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r10;
        goto L_80011CF0;
    // 0x80011CE0: sh          $t2, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r10;
L_80011CE4:
    // 0x80011CE4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011CE8: nop

    // 0x80011CEC: sh          $zero, 0x68($t3)
    MEM_H(0X68, ctx->r11) = 0;
L_80011CF0:
    // 0x80011CF0: b           L_80011F5C
    // 0x80011CF4: nop

        goto L_80011F5C;
    // 0x80011CF4: nop

L_80011CF8:
    // 0x80011CF8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80011CFC: nop

    // 0x80011D00: lw          $t7, 0x1AC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1AC);
    // 0x80011D04: nop

    // 0x80011D08: slti        $at, $t7, 0x4000
    ctx->r1 = SIGNED(ctx->r15) < 0X4000 ? 1 : 0;
    // 0x80011D0C: bne         $at, $zero, L_80011D24
    if (ctx->r1 != 0) {
        // 0x80011D10: nop

            goto L_80011D24;
    }
    // 0x80011D10: nop

    // 0x80011D14: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80011D18: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80011D1C: bne         $at, $zero, L_80011D74
    if (ctx->r1 != 0) {
        // 0x80011D20: nop

            goto L_80011D74;
    }
    // 0x80011D20: nop

L_80011D24:
    // 0x80011D24: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011D28: nop

    // 0x80011D2C: lh          $t6, 0x66($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X66);
    // 0x80011D30: lwc1        $f6, 0x14($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X14);
    // 0x80011D34: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80011D38: nop

    // 0x80011D3C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011D40: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80011D44: nop

    // 0x80011D48: bc1f        L_80011D60
    if (!c1cs) {
        // 0x80011D4C: nop

            goto L_80011D60;
    }
    // 0x80011D4C: nop

    // 0x80011D50: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80011D54: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011D58: b           L_80011D6C
    // 0x80011D5C: sh          $t0, 0x68($t9)
    MEM_H(0X68, ctx->r25) = ctx->r8;
        goto L_80011D6C;
    // 0x80011D5C: sh          $t0, 0x68($t9)
    MEM_H(0X68, ctx->r25) = ctx->r8;
L_80011D60:
    // 0x80011D60: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80011D64: nop

    // 0x80011D68: sh          $zero, 0x68($t1)
    MEM_H(0X68, ctx->r9) = 0;
L_80011D6C:
    // 0x80011D6C: b           L_80011DBC
    // 0x80011D70: nop

        goto L_80011DBC;
    // 0x80011D70: nop

L_80011D74:
    // 0x80011D74: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80011D78: nop

    // 0x80011D7C: lh          $t3, 0x66($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X66);
    // 0x80011D80: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x80011D84: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80011D88: lwc1        $f16, 0xD4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XD4);
    // 0x80011D8C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80011D90: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80011D94: nop

    // 0x80011D98: bc1f        L_80011DB0
    if (!c1cs) {
        // 0x80011D9C: nop

            goto L_80011DB0;
    }
    // 0x80011D9C: nop

    // 0x80011DA0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80011DA4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80011DA8: b           L_80011DBC
    // 0x80011DAC: sh          $t5, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r13;
        goto L_80011DBC;
    // 0x80011DAC: sh          $t5, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r13;
L_80011DB0:
    // 0x80011DB0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011DB4: nop

    // 0x80011DB8: sh          $zero, 0x68($t8)
    MEM_H(0X68, ctx->r24) = 0;
L_80011DBC:
    // 0x80011DBC: b           L_80011F5C
    // 0x80011DC0: nop

        goto L_80011F5C;
    // 0x80011DC0: nop

L_80011DC4:
    // 0x80011DC4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80011DC8: nop

    // 0x80011DCC: lw          $t0, 0xC($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XC);
    // 0x80011DD0: lhu         $t1, 0x66($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X66);
    // 0x80011DD4: lhu         $t9, 0x11E($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X11E);
    // 0x80011DD8: nop

    // 0x80011DDC: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80011DE0: beq         $at, $zero, L_80011DF8
    if (ctx->r1 == 0) {
        // 0x80011DE4: nop

            goto L_80011DF8;
    }
    // 0x80011DE4: nop

    // 0x80011DE8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80011DEC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80011DF0: b           L_80011E04
    // 0x80011DF4: sh          $t4, 0x68($t2)
    MEM_H(0X68, ctx->r10) = ctx->r12;
        goto L_80011E04;
    // 0x80011DF4: sh          $t4, 0x68($t2)
    MEM_H(0X68, ctx->r10) = ctx->r12;
L_80011DF8:
    // 0x80011DF8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011DFC: nop

    // 0x80011E00: sh          $zero, 0x68($t3)
    MEM_H(0X68, ctx->r11) = 0;
L_80011E04:
    // 0x80011E04: b           L_80011F5C
    // 0x80011E08: nop

        goto L_80011F5C;
    // 0x80011E08: nop

L_80011E0C:
    // 0x80011E0C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80011E10: nop

    // 0x80011E14: lh          $t8, 0x66($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X66);
    // 0x80011E18: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x80011E1C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80011E20: lwc1        $f4, 0xE8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x80011E24: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80011E28: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80011E2C: nop

    // 0x80011E30: bc1f        L_80011E48
    if (!c1cs) {
        // 0x80011E34: nop

            goto L_80011E48;
    }
    // 0x80011E34: nop

    // 0x80011E38: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80011E3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011E40: b           L_80011E54
    // 0x80011E44: sh          $t0, 0x68($t6)
    MEM_H(0X68, ctx->r14) = ctx->r8;
        goto L_80011E54;
    // 0x80011E44: sh          $t0, 0x68($t6)
    MEM_H(0X68, ctx->r14) = ctx->r8;
L_80011E48:
    // 0x80011E48: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80011E4C: nop

    // 0x80011E50: sh          $zero, 0x68($t9)
    MEM_H(0X68, ctx->r25) = 0;
L_80011E54:
    // 0x80011E54: b           L_80011F5C
    // 0x80011E58: nop

        goto L_80011F5C;
    // 0x80011E58: nop

L_80011E5C:
    // 0x80011E5C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80011E60: nop

    // 0x80011E64: lh          $t2, 0x66($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X66);
    // 0x80011E68: lw          $t4, 0xC($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC);
    // 0x80011E6C: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80011E70: lwc1        $f10, 0xEC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XEC);
    // 0x80011E74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80011E78: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80011E7C: nop

    // 0x80011E80: bc1f        L_80011E98
    if (!c1cs) {
        // 0x80011E84: nop

            goto L_80011E98;
    }
    // 0x80011E84: nop

    // 0x80011E88: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80011E8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80011E90: b           L_80011EA4
    // 0x80011E94: sh          $t3, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r11;
        goto L_80011EA4;
    // 0x80011E94: sh          $t3, 0x68($t7)
    MEM_H(0X68, ctx->r15) = ctx->r11;
L_80011E98:
    // 0x80011E98: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80011E9C: nop

    // 0x80011EA0: sh          $zero, 0x68($t5)
    MEM_H(0X68, ctx->r13) = 0;
L_80011EA4:
    // 0x80011EA4: b           L_80011F5C
    // 0x80011EA8: nop

        goto L_80011F5C;
    // 0x80011EA8: nop

L_80011EAC:
    // 0x80011EAC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011EB0: nop

    // 0x80011EB4: lh          $t6, 0x66($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X66);
    // 0x80011EB8: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x80011EBC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80011EC0: lwc1        $f6, 0xF0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x80011EC4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011EC8: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80011ECC: nop

    // 0x80011ED0: bc1f        L_80011EE8
    if (!c1cs) {
        // 0x80011ED4: nop

            goto L_80011EE8;
    }
    // 0x80011ED4: nop

    // 0x80011ED8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80011EDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80011EE0: b           L_80011EF4
    // 0x80011EE4: sh          $t9, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r25;
        goto L_80011EF4;
    // 0x80011EE4: sh          $t9, 0x68($t4)
    MEM_H(0X68, ctx->r12) = ctx->r25;
L_80011EE8:
    // 0x80011EE8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80011EEC: nop

    // 0x80011EF0: sh          $zero, 0x68($t1)
    MEM_H(0X68, ctx->r9) = 0;
L_80011EF4:
    // 0x80011EF4: b           L_80011F5C
    // 0x80011EF8: nop

        goto L_80011F5C;
    // 0x80011EF8: nop

L_80011EFC:
    // 0x80011EFC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80011F00: nop

    // 0x80011F04: lhu         $a0, 0x66($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X66);
    // 0x80011F08: jal         0x80014BD4
    // 0x80011F0C: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x80011F0C: nop

    after_1:
    // 0x80011F10: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80011F14: nop

    // 0x80011F18: lw          $t7, 0xC($t3)
    ctx->r15 = MEM_W(ctx->r11, 0XC);
    // 0x80011F1C: nop

    // 0x80011F20: lwc1        $f16, 0xF4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x80011F24: nop

    // 0x80011F28: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80011F2C: nop

    // 0x80011F30: bc1f        L_80011F48
    if (!c1cs) {
        // 0x80011F34: nop

            goto L_80011F48;
    }
    // 0x80011F34: nop

    // 0x80011F38: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80011F3C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80011F40: b           L_80011F54
    // 0x80011F44: sh          $t5, 0x68($t0)
    MEM_H(0X68, ctx->r8) = ctx->r13;
        goto L_80011F54;
    // 0x80011F44: sh          $t5, 0x68($t0)
    MEM_H(0X68, ctx->r8) = ctx->r13;
L_80011F48:
    // 0x80011F48: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80011F4C: nop

    // 0x80011F50: sh          $zero, 0x68($t8)
    MEM_H(0X68, ctx->r24) = 0;
L_80011F54:
    // 0x80011F54: b           L_80011F5C
    // 0x80011F58: nop

        goto L_80011F5C;
    // 0x80011F58: nop

L_80011F5C:
    // 0x80011F5C: b           L_80011F6C
    // 0x80011F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011F6C;
    // 0x80011F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011F64: b           L_80011F6C
    // 0x80011F68: nop

        goto L_80011F6C;
    // 0x80011F68: nop

L_80011F6C:
    // 0x80011F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011F70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80011F74: jr          $ra
    // 0x80011F78: nop

    return;
    // 0x80011F78: nop

;}
RECOMP_FUNC void func_80011F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011F7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011F84: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80011F88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80011F8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80011F90: jal         0x8000DA44
    // 0x80011F94: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80011F94: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80011F98: bgez        $v0, L_80011FA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011F9C: nop

            goto L_80011FA8;
    }
    // 0x80011F9C: nop

    // 0x80011FA0: b           L_80012058
    // 0x80011FA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012058;
    // 0x80011FA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011FA8:
    // 0x80011FA8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80011FAC: nop

    // 0x80011FB0: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80011FB4: nop

    // 0x80011FB8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80011FBC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80011FC0:
    // 0x80011FC0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80011FC4: nop

    // 0x80011FC8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80011FCC: addu        $a0, $sp, $t9
    ctx->r4 = ADD32(ctx->r29, ctx->r25);
    // 0x80011FD0: lhu         $a0, 0x24($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X24);
    // 0x80011FD4: jal         0x80014BD4
    // 0x80011FD8: nop

    func_80014BD4(rdram, ctx);
        goto after_1;
    // 0x80011FD8: nop

    after_1:
    // 0x80011FDC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80011FE0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80011FE4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80011FE8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80011FEC: swc1        $f0, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f0.u32l;
    // 0x80011FF0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80011FF4: nop

    // 0x80011FF8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80011FFC: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80012000: bne         $at, $zero, L_80011FC0
    if (ctx->r1 != 0) {
        // 0x80012004: sw          $t5, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r13;
            goto L_80011FC0;
    }
    // 0x80012004: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80012008: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001200C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80012010: nop

    // 0x80012014: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x80012018: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8001201C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80012020: lw          $t8, 0x1AC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1AC);
    // 0x80012024: nop

    // 0x80012028: bne         $t8, $at, L_80012048
    if (ctx->r24 != ctx->r1) {
        // 0x8001202C: nop

            goto L_80012048;
    }
    // 0x8001202C: nop

    // 0x80012030: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80012034: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80012038: lw          $t1, 0x1A8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1A8);
    // 0x8001203C: nop

    // 0x80012040: and         $t0, $t1, $at
    ctx->r8 = ctx->r9 & ctx->r1;
    // 0x80012044: sw          $t0, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = ctx->r8;
L_80012048:
    // 0x80012048: b           L_80012058
    // 0x8001204C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012058;
    // 0x8001204C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012050: b           L_80012058
    // 0x80012054: nop

        goto L_80012058;
    // 0x80012054: nop

L_80012058:
    // 0x80012058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001205C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80012060: jr          $ra
    // 0x80012064: nop

    return;
    // 0x80012064: nop

;}
RECOMP_FUNC void func_80012068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012068: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001206C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012070: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80012074: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80012078: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001207C: jal         0x8000DA44
    // 0x80012080: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012080: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80012084: bgez        $v0, L_80012094
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012088: nop

            goto L_80012094;
    }
    // 0x80012088: nop

    // 0x8001208C: b           L_80012154
    // 0x80012090: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012154;
    // 0x80012090: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012094:
    // 0x80012094: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80012098: nop

    // 0x8001209C: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x800120A0: nop

    // 0x800120A4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800120A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800120AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800120B0: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800120B4: nop

    // 0x800120B8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800120BC: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x800120C0: nop

    // 0x800120C4: blez        $t0, L_80012144
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800120C8: nop

            goto L_80012144;
    }
    // 0x800120C8: nop

L_800120CC:
    // 0x800120CC: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x800120D0: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x800120D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800120D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800120DC: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800120E0: lwc1        $f4, -0x617C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X617C);
    // 0x800120E4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800120E8: nop

    // 0x800120EC: swc1        $f4, 0xF4($t4)
    MEM_W(0XF4, ctx->r12) = ctx->f4.u32l;
    // 0x800120F0: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x800120F4: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x800120F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800120FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80012100: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80012104: lwc1        $f6, -0x617C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X617C);
    // 0x80012108: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8001210C: nop

    // 0x80012110: swc1        $f6, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f6.u32l;
    // 0x80012114: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80012118: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001211C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80012120: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80012124: addiu       $t2, $t1, 0x160
    ctx->r10 = ADD32(ctx->r9, 0X160);
    // 0x80012128: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8001212C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80012130: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x80012134: nop

    // 0x80012138: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001213C: bne         $at, $zero, L_800120CC
    if (ctx->r1 != 0) {
        // 0x80012140: nop

            goto L_800120CC;
    }
    // 0x80012140: nop

L_80012144:
    // 0x80012144: b           L_80012154
    // 0x80012148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012154;
    // 0x80012148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001214C: b           L_80012154
    // 0x80012150: nop

        goto L_80012154;
    // 0x80012150: nop

L_80012154:
    // 0x80012154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012158: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001215C: jr          $ra
    // 0x80012160: nop

    return;
    // 0x80012160: nop

;}
RECOMP_FUNC void func_80012164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012164: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80012168: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001216C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80012170: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80012174: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80012178: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8001217C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80012180: jal         0x8000DA44
    // 0x80012184: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x80012184: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x80012188: bgez        $v0, L_80012198
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001218C: nop

            goto L_80012198;
    }
    // 0x8001218C: nop

    // 0x80012190: b           L_80012398
    // 0x80012194: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012398;
    // 0x80012194: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012198:
    // 0x80012198: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8001219C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800121A0: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800121A4: nop

    // 0x800121A8: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800121AC: bne         $at, $zero, L_800121CC
    if (ctx->r1 != 0) {
        // 0x800121B0: nop

            goto L_800121CC;
    }
    // 0x800121B0: nop

    // 0x800121B4: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x800121B8: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800121BC: beq         $at, $zero, L_800121CC
    if (ctx->r1 == 0) {
        // 0x800121C0: nop

            goto L_800121CC;
    }
    // 0x800121C0: nop

    // 0x800121C4: b           L_80012398
    // 0x800121C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012398;
    // 0x800121C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800121CC:
    // 0x800121CC: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800121D0: nop

    // 0x800121D4: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x800121D8: nop

    // 0x800121DC: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x800121E0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800121E4: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800121E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800121EC: lhu         $t1, 0x60($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X60);
    // 0x800121F0: nop

    // 0x800121F4: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x800121F8: sra         $t3, $t2, 4
    ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
    // 0x800121FC: bne         $t3, $at, L_80012210
    if (ctx->r11 != ctx->r1) {
        // 0x80012200: nop

            goto L_80012210;
    }
    // 0x80012200: nop

    // 0x80012204: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80012208: b           L_80012260
    // 0x8001220C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_80012260;
    // 0x8001220C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80012210:
    // 0x80012210: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80012214: nop

    // 0x80012218: lhu         $t6, 0x60($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X60);
    // 0x8001221C: nop

    // 0x80012220: andi        $t7, $t6, 0x60
    ctx->r15 = ctx->r14 & 0X60;
    // 0x80012224: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x80012228: bne         $t8, $zero, L_80012238
    if (ctx->r24 != 0) {
        // 0x8001222C: nop

            goto L_80012238;
    }
    // 0x8001222C: nop

    // 0x80012230: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80012234: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80012238:
    // 0x80012238: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8001223C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012240: lhu         $t1, 0x60($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X60);
    // 0x80012244: nop

    // 0x80012248: andi        $t2, $t1, 0x60
    ctx->r10 = ctx->r9 & 0X60;
    // 0x8001224C: sra         $t3, $t2, 5
    ctx->r11 = S32(SIGNED(ctx->r10) >> 5);
    // 0x80012250: bne         $t3, $at, L_80012260
    if (ctx->r11 != ctx->r1) {
        // 0x80012254: nop

            goto L_80012260;
    }
    // 0x80012254: nop

    // 0x80012258: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8001225C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80012260:
    // 0x80012260: addiu       $t5, $sp, 0x4C
    ctx->r13 = ADD32(ctx->r29, 0X4C);
    // 0x80012264: lhu         $t6, 0x4($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X4);
    // 0x80012268: nop

    // 0x8001226C: bne         $t6, $zero, L_800122CC
    if (ctx->r14 != 0) {
        // 0x80012270: nop

            goto L_800122CC;
    }
    // 0x80012270: nop

    // 0x80012274: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x80012278: nop

    // 0x8001227C: bne         $t7, $zero, L_800122CC
    if (ctx->r15 != 0) {
        // 0x80012280: nop

            goto L_800122CC;
    }
    // 0x80012280: nop

    // 0x80012284: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80012288: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001228C: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x80012290: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80012294: lwc1        $f6, 0xCC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x80012298: lwc1        $f4, 0xCC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x8001229C: nop

    // 0x800122A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800122A4: swc1        $f8, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f8.u32l;
    // 0x800122A8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800122AC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800122B0: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x800122B4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800122B8: lwc1        $f16, 0xD0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x800122BC: lwc1        $f10, 0xD0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x800122C0: nop

    // 0x800122C4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800122C8: swc1        $f18, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f18.u32l;
L_800122CC:
    // 0x800122CC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800122D0: nop

    // 0x800122D4: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x800122D8: nop

    // 0x800122DC: lw          $t5, 0xC8($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC8);
    // 0x800122E0: nop

    // 0x800122E4: sw          $t5, 0x94($t4)
    MEM_W(0X94, ctx->r12) = ctx->r13;
    // 0x800122E8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800122EC: nop

    // 0x800122F0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x800122F4: nop

    // 0x800122F8: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x800122FC: nop

    // 0x80012300: andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // 0x80012304: beq         $t9, $zero, L_80012314
    if (ctx->r25 == 0) {
        // 0x80012308: nop

            goto L_80012314;
    }
    // 0x80012308: nop

    // 0x8001230C: b           L_80012318
    // 0x80012310: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_80012318;
    // 0x80012310: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80012314:
    // 0x80012314: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80012318:
    // 0x80012318: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8001231C: addiu       $t3, $sp, 0x4C
    ctx->r11 = ADD32(ctx->r29, 0X4C);
    // 0x80012320: lhu         $t2, 0x6($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X6);
    // 0x80012324: lhu         $a2, 0x2($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X2);
    // 0x80012328: lhu         $a3, 0x4($t3)
    ctx->r7 = MEM_HU(ctx->r11, 0X4);
    // 0x8001232C: lw          $a0, 0xC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC);
    // 0x80012330: lw          $a1, 0x10($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X10);
    // 0x80012334: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80012338: lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X8);
    // 0x8001233C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80012340: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80012344: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80012348: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8001234C: lhu         $t4, 0x4($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X4);
    // 0x80012350: jal         0x80049A00
    // 0x80012354: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    func_80049A00(rdram, ctx);
        goto after_1;
    // 0x80012354: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_1:
    // 0x80012358: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8001235C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80012360: bne         $s0, $zero, L_80012370
    if (ctx->r16 != 0) {
        // 0x80012364: sw          $s0, 0x7C($t7)
        MEM_W(0X7C, ctx->r15) = ctx->r16;
            goto L_80012370;
    }
    // 0x80012364: sw          $s0, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->r16;
    // 0x80012368: b           L_80012398
    // 0x8001236C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80012398;
    // 0x8001236C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80012370:
    // 0x80012370: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80012374: nop

    // 0x80012378: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x8001237C: nop

    // 0x80012380: ori         $t9, $t0, 0x1
    ctx->r25 = ctx->r8 | 0X1;
    // 0x80012384: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
    // 0x80012388: b           L_80012398
    // 0x8001238C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80012398;
    // 0x8001238C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80012390: b           L_80012398
    // 0x80012394: nop

        goto L_80012398;
    // 0x80012394: nop

L_80012398:
    // 0x80012398: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001239C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800123A0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800123A4: jr          $ra
    // 0x800123A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800123A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800123AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800123AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800123B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800123B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800123B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800123BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800123C0: jal         0x8000DA44
    // 0x800123C4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8000DA44(rdram, ctx);
        goto after_0;
    // 0x800123C4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800123C8: bgez        $v0, L_800123D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800123CC: nop

            goto L_800123D8;
    }
    // 0x800123CC: nop

    // 0x800123D0: b           L_800124A8
    // 0x800123D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800124A8;
    // 0x800123D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800123D8:
    // 0x800123D8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800123DC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800123E0: lw          $t7, 0x1AC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1AC);
    // 0x800123E4: nop

    // 0x800123E8: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800123EC: bne         $at, $zero, L_8001240C
    if (ctx->r1 != 0) {
        // 0x800123F0: nop

            goto L_8001240C;
    }
    // 0x800123F0: nop

    // 0x800123F4: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x800123F8: slt         $at, $t7, $at
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800123FC: beq         $at, $zero, L_8001240C
    if (ctx->r1 == 0) {
        // 0x80012400: nop

            goto L_8001240C;
    }
    // 0x80012400: nop

    // 0x80012404: b           L_800124A8
    // 0x80012408: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800124A8;
    // 0x80012408: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001240C:
    // 0x8001240C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80012410: nop

    // 0x80012414: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x80012418: nop

    // 0x8001241C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80012420: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80012424: nop

    // 0x80012428: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8001242C: nop

    // 0x80012430: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80012434: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x80012438: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001243C: nop

    // 0x80012440: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x80012444: nop

    // 0x80012448: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8001244C: bne         $at, $zero, L_80012460
    if (ctx->r1 != 0) {
        // 0x80012450: nop

            goto L_80012460;
    }
    // 0x80012450: nop

    // 0x80012454: slti        $at, $t4, 0x2A
    ctx->r1 = SIGNED(ctx->r12) < 0X2A ? 1 : 0;
    // 0x80012458: bne         $at, $zero, L_80012468
    if (ctx->r1 != 0) {
        // 0x8001245C: nop

            goto L_80012468;
    }
    // 0x8001245C: nop

L_80012460:
    // 0x80012460: b           L_800124A8
    // 0x80012464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800124A8;
    // 0x80012464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012468:
    // 0x80012468: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8001246C: nop

    // 0x80012470: lw          $a0, 0x7C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X7C);
    // 0x80012474: jal         0x80014B5C
    // 0x80012478: nop

    func_80014B5C(rdram, ctx);
        goto after_1;
    // 0x80012478: nop

    after_1:
    // 0x8001247C: beq         $v0, $zero, L_80012498
    if (ctx->r2 == 0) {
        // 0x80012480: nop

            goto L_80012498;
    }
    // 0x80012480: nop

    // 0x80012484: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80012488: nop

    // 0x8001248C: lw          $a0, 0x7C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X7C);
    // 0x80012490: jal         0x800299C4
    // 0x80012494: nop

    func_800299C4(rdram, ctx);
        goto after_2;
    // 0x80012494: nop

    after_2:
L_80012498:
    // 0x80012498: b           L_800124A8
    // 0x8001249C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800124A8;
    // 0x8001249C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800124A0: b           L_800124A8
    // 0x800124A4: nop

        goto L_800124A8;
    // 0x800124A4: nop

L_800124A8:
    // 0x800124A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800124AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800124B0: jr          $ra
    // 0x800124B4: nop

    return;
    // 0x800124B4: nop

;}
