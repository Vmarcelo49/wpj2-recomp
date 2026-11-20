#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80017B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017B00: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80017B04: lw          $t6, 0x1A0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A0);
    // 0x80017B08: nop

    // 0x80017B0C: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80017B10: sw          $t7, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->r15;
    // 0x80017B14: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80017B18: sw          $zero, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = 0;
    // 0x80017B1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017B20: nop

    // 0x80017B24: swc1        $f4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f4.u32l;
    // 0x80017B28: lwc1        $f6, 0x1EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80017B2C: nop

    // 0x80017B30: swc1        $f6, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f6.u32l;
    // 0x80017B34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80017B38: nop

    // 0x80017B3C: swc1        $f8, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->f8.u32l;
    // 0x80017B40: lwc1        $f10, 0x1F4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1F4);
    // 0x80017B44: nop

    // 0x80017B48: swc1        $f10, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f10.u32l;
    // 0x80017B4C: sw          $zero, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = 0;
    // 0x80017B50: sw          $zero, 0x210($a0)
    MEM_W(0X210, ctx->r4) = 0;
    // 0x80017B54: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80017B58: lw          $t8, -0x4538($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4538);
    // 0x80017B5C: nop

    // 0x80017B60: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x80017B64: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80017B68: b           L_80017B78
    // 0x80017B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80017B78;
    // 0x80017B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017B70: b           L_80017B78
    // 0x80017B74: nop

        goto L_80017B78;
    // 0x80017B74: nop

L_80017B78:
    // 0x80017B78: jr          $ra
    // 0x80017B7C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80017B7C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80017B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017B80: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80017B84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80017B88: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80017B8C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80017B90: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80017B94: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80017B98: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80017B9C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80017BA0: jal         0x80016074
    // 0x80017BA4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80017BA4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x80017BA8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80017BAC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80017BB0: nop

    // 0x80017BB4: bne         $t6, $zero, L_80017BC4
    if (ctx->r14 != 0) {
        // 0x80017BB8: nop

            goto L_80017BC4;
    }
    // 0x80017BB8: nop

    // 0x80017BBC: b           L_80018364
    // 0x80017BC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80018364;
    // 0x80017BC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017BC4:
    // 0x80017BC4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80017BC8: nop

    // 0x80017BCC: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80017BD0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80017BD4: nop

    // 0x80017BD8: lw          $t9, 0x1A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A8);
    // 0x80017BDC: nop

    // 0x80017BE0: andi        $t0, $t9, 0x7
    ctx->r8 = ctx->r25 & 0X7;
    // 0x80017BE4: bne         $t0, $zero, L_80017BF8
    if (ctx->r8 != 0) {
        // 0x80017BE8: nop

            goto L_80017BF8;
    }
    // 0x80017BE8: nop

    // 0x80017BEC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80017BF0: jal         0x800198F8
    // 0x80017BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800198F8(rdram, ctx);
        goto after_1;
    // 0x80017BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80017BF8:
    // 0x80017BF8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80017BFC: nop

    // 0x80017C00: lw          $t2, 0x1A8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1A8);
    // 0x80017C04: nop

    // 0x80017C08: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80017C0C: sw          $t3, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r11;
    // 0x80017C10: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C14: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x80017C18: lw          $t5, 0x1A8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A8);
    // 0x80017C1C: nop

    // 0x80017C20: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80017C24: sw          $t6, 0x1A8($t4)
    MEM_W(0X1A8, ctx->r12) = ctx->r14;
    // 0x80017C28: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80017C2C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C30: nop

    // 0x80017C34: sw          $t7, 0x1AC($t8)
    MEM_W(0X1AC, ctx->r24) = ctx->r15;
    // 0x80017C38: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80017C3C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C40: nop

    // 0x80017C44: swc1        $f4, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f4.u32l;
    // 0x80017C48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80017C4C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C50: nop

    // 0x80017C54: swc1        $f6, 0x1EC($t0)
    MEM_W(0X1EC, ctx->r8) = ctx->f6.u32l;
    // 0x80017C58: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80017C5C: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80017C60: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80017C64: nop

    // 0x80017C68: andi        $t1, $t3, 0x2000
    ctx->r9 = ctx->r11 & 0X2000;
    // 0x80017C6C: beq         $t1, $zero, L_80017CF8
    if (ctx->r9 == 0) {
        // 0x80017C70: nop

            goto L_80017CF8;
    }
    // 0x80017C70: nop

    // 0x80017C74: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80017C78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017C7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017C80: swc1        $f8, -0x59A0($at)
    MEM_W(-0X59A0, ctx->r1) = ctx->f8.u32l;
    // 0x80017C84: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80017C88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017C8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017C90: swc1        $f10, -0x599C($at)
    MEM_W(-0X599C, ctx->r1) = ctx->f10.u32l;
    // 0x80017C94: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80017C98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017C9C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CA0: swc1        $f16, -0x5998($at)
    MEM_W(-0X5998, ctx->r1) = ctx->f16.u32l;
    // 0x80017CA4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80017CA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017CAC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CB0: swc1        $f18, -0x5994($at)
    MEM_W(-0X5994, ctx->r1) = ctx->f18.u32l;
    // 0x80017CB4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80017CB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017CBC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CC0: swc1        $f4, -0x5990($at)
    MEM_W(-0X5990, ctx->r1) = ctx->f4.u32l;
    // 0x80017CC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80017CC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017CCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CD0: swc1        $f6, -0x598C($at)
    MEM_W(-0X598C, ctx->r1) = ctx->f6.u32l;
    // 0x80017CD4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80017CD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017CDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CE0: swc1        $f8, -0x5988($at)
    MEM_W(-0X5988, ctx->r1) = ctx->f8.u32l;
    // 0x80017CE4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80017CE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017CEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017CF0: b           L_80017D78
    // 0x80017CF4: swc1        $f10, -0x5984($at)
    MEM_W(-0X5984, ctx->r1) = ctx->f10.u32l;
        goto L_80017D78;
    // 0x80017CF4: swc1        $f10, -0x5984($at)
    MEM_W(-0X5984, ctx->r1) = ctx->f10.u32l;
L_80017CF8:
    // 0x80017CF8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80017CFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017D00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D04: swc1        $f16, -0x59A0($at)
    MEM_W(-0X59A0, ctx->r1) = ctx->f16.u32l;
    // 0x80017D08: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80017D0C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017D10: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D14: swc1        $f18, -0x599C($at)
    MEM_W(-0X599C, ctx->r1) = ctx->f18.u32l;
    // 0x80017D18: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80017D1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017D20: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D24: swc1        $f4, -0x5998($at)
    MEM_W(-0X5998, ctx->r1) = ctx->f4.u32l;
    // 0x80017D28: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80017D2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017D30: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D34: swc1        $f6, -0x5994($at)
    MEM_W(-0X5994, ctx->r1) = ctx->f6.u32l;
    // 0x80017D38: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80017D3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017D40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D44: swc1        $f8, -0x5990($at)
    MEM_W(-0X5990, ctx->r1) = ctx->f8.u32l;
    // 0x80017D48: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80017D4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017D50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D54: swc1        $f10, -0x598C($at)
    MEM_W(-0X598C, ctx->r1) = ctx->f10.u32l;
    // 0x80017D58: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80017D5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017D60: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D64: swc1        $f16, -0x5988($at)
    MEM_W(-0X5988, ctx->r1) = ctx->f16.u32l;
    // 0x80017D68: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x80017D6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017D70: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017D74: swc1        $f18, -0x5984($at)
    MEM_W(-0X5984, ctx->r1) = ctx->f18.u32l;
L_80017D78:
    // 0x80017D78: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80017D7C: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x80017D80: addiu       $t6, $t5, 0x618
    ctx->r14 = ADD32(ctx->r13, 0X618);
    // 0x80017D84: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80017D88: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80017D8C: addiu       $t4, $t4, 0x61D8
    ctx->r12 = ADD32(ctx->r12, 0X61D8);
    // 0x80017D90: addiu       $t7, $t4, 0x750
    ctx->r15 = ADD32(ctx->r12, 0X750);
    // 0x80017D94: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80017D98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017D9C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80017DA0: addiu       $t8, $t8, -0x59C0
    ctx->r24 = ADD32(ctx->r24, -0X59C0);
    // 0x80017DA4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80017DA8: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x80017DAC: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x80017DB0: lwc1        $f22, 0xC($t9)
    ctx->f22.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80017DB4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80017DB8: addiu       $t0, $t0, -0x59C0
    ctx->r8 = ADD32(ctx->r8, -0X59C0);
    // 0x80017DBC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80017DC0: swc1        $f22, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f22.u32l;
    // 0x80017DC4: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80017DC8: swc1        $f20, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f20.u32l;
    // 0x80017DCC: addiu       $t2, $t2, -0x59C0
    ctx->r10 = ADD32(ctx->r10, -0X59C0);
    // 0x80017DD0: swc1        $f20, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f20.u32l;
    // 0x80017DD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80017DD8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80017DDC: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x80017DE0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80017DE4: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80017DE8: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
    // 0x80017DEC: lwc1        $f22, 0x1C($t1)
    ctx->f22.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80017DF0: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80017DF4: addiu       $t5, $t5, -0x59C0
    ctx->r13 = ADD32(ctx->r13, -0X59C0);
    // 0x80017DF8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80017DFC: swc1        $f22, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f22.u32l;
    // 0x80017E00: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80017E04: swc1        $f20, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f20.u32l;
    // 0x80017E08: addiu       $t6, $t6, -0x59C0
    ctx->r14 = ADD32(ctx->r14, -0X59C0);
    // 0x80017E0C: swc1        $f20, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f20.u32l;
    // 0x80017E10: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017E14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017E18: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80017E1C: nop

    // 0x80017E20: swc1        $f8, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f8.u32l;
    // 0x80017E24: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017E28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017E2C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80017E30: nop

    // 0x80017E34: swc1        $f10, 0x100($t7)
    MEM_W(0X100, ctx->r15) = ctx->f10.u32l;
    // 0x80017E38: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017E3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017E40: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80017E44: nop

    // 0x80017E48: swc1        $f16, 0xFC($t8)
    MEM_W(0XFC, ctx->r24) = ctx->f16.u32l;
    // 0x80017E4C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017E50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017E54: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80017E58: nop

    // 0x80017E5C: swc1        $f18, 0x104($t9)
    MEM_W(0X104, ctx->r25) = ctx->f18.u32l;
    // 0x80017E60: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017E64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017E68: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80017E6C: nop

    // 0x80017E70: swc1        $f4, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f4.u32l;
    // 0x80017E74: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017E78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017E7C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80017E80: nop

    // 0x80017E84: swc1        $f6, 0x100($t2)
    MEM_W(0X100, ctx->r10) = ctx->f6.u32l;
    // 0x80017E88: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017E8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017E90: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80017E94: nop

    // 0x80017E98: swc1        $f8, 0xFC($t3)
    MEM_W(0XFC, ctx->r11) = ctx->f8.u32l;
    // 0x80017E9C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017EA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80017EA4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80017EA8: nop

    // 0x80017EAC: swc1        $f10, 0x104($t1)
    MEM_W(0X104, ctx->r9) = ctx->f10.u32l;
    // 0x80017EB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017EB4: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80017EB8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80017EBC: nop

    // 0x80017EC0: swc1        $f16, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f16.u32l;
    // 0x80017EC4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017EC8: lwc1        $f18, -0x599C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80017ECC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80017ED0: nop

    // 0x80017ED4: swc1        $f18, 0x114($t6)
    MEM_W(0X114, ctx->r14) = ctx->f18.u32l;
    // 0x80017ED8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017EDC: lwc1        $f4, -0x5998($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80017EE0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80017EE4: nop

    // 0x80017EE8: swc1        $f4, 0x118($t4)
    MEM_W(0X118, ctx->r12) = ctx->f4.u32l;
    // 0x80017EEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017EF0: lwc1        $f6, -0x5994($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80017EF4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80017EF8: nop

    // 0x80017EFC: swc1        $f6, 0x11C($t7)
    MEM_W(0X11C, ctx->r15) = ctx->f6.u32l;
    // 0x80017F00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017F04: lwc1        $f8, -0x59A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80017F08: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80017F0C: nop

    // 0x80017F10: swc1        $f8, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->f8.u32l;
    // 0x80017F14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017F18: lwc1        $f10, -0x599C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80017F1C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80017F20: nop

    // 0x80017F24: swc1        $f10, 0x114($t9)
    MEM_W(0X114, ctx->r25) = ctx->f10.u32l;
    // 0x80017F28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017F2C: lwc1        $f16, -0x5998($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80017F30: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80017F34: nop

    // 0x80017F38: swc1        $f16, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f16.u32l;
    // 0x80017F3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80017F40: lwc1        $f18, -0x5994($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80017F44: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80017F48: nop

    // 0x80017F4C: swc1        $f18, 0x11C($t2)
    MEM_W(0X11C, ctx->r10) = ctx->f18.u32l;
    // 0x80017F50: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80017F54: nop

    // 0x80017F58: lw          $t1, 0x1AC($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X1AC);
    // 0x80017F5C: nop

    // 0x80017F60: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x80017F64: beq         $at, $zero, L_80018354
    if (ctx->r1 == 0) {
        // 0x80017F68: nop

            goto L_80018354;
    }
    // 0x80017F68: nop

    // 0x80017F6C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80017F70: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80017F74: addu        $at, $at, $t1
    gpr jr_addend_80017F80 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80017F78: lw          $t1, -0x2A40($at)
    ctx->r9 = ADD32(ctx->r1, -0X2A40);
    // 0x80017F7C: nop

    // 0x80017F80: jr          $t1
    // 0x80017F84: nop

    switch (jr_addend_80017F80 >> 2) {
        case 0: goto L_80018214; break;
        case 1: goto L_80018054; break;
        case 2: goto L_80018054; break;
        case 3: goto L_80018054; break;
        case 4: goto L_800182B4; break;
        case 5: goto L_80018134; break;
        case 6: goto L_80018134; break;
        case 7: goto L_80018134; break;
        case 8: goto L_80017FB4; break;
        case 9: goto L_80017F88; break;
        default: switch_error(__func__, 0x80017F80, 0x800ED5C0);
    }
    // 0x80017F84: nop

L_80017F88:
    // 0x80017F88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80017F8C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80017F90: nop

    // 0x80017F94: swc1        $f4, 0x114($t5)
    MEM_W(0X114, ctx->r13) = ctx->f4.u32l;
    // 0x80017F98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80017F9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80017FA0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80017FA4: nop

    // 0x80017FA8: swc1        $f6, 0x11C($t6)
    MEM_W(0X11C, ctx->r14) = ctx->f6.u32l;
    // 0x80017FAC: b           L_80018354
    // 0x80017FB0: nop

        goto L_80018354;
    // 0x80017FB0: nop

L_80017FB4:
    // 0x80017FB4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80017FB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017FBC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80017FC0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80017FC4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80017FC8: addiu       $t4, $t4, -0x59C0
    ctx->r12 = ADD32(ctx->r12, -0X59C0);
    // 0x80017FCC: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x80017FD0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80017FD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80017FD8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80017FDC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80017FE0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80017FE4: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x80017FE8: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x80017FEC: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x80017FF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80017FF4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80017FF8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80017FFC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80018000: addiu       $t8, $t8, -0x59C0
    ctx->r24 = ADD32(ctx->r24, -0X59C0);
    // 0x80018004: swc1        $f16, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f16.u32l;
    // 0x80018008: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x8001800C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018010: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018014: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80018018: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001801C: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x80018020: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
    // 0x80018024: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018028: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001802C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80018030: nop

    // 0x80018034: swc1        $f8, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->f8.u32l;
    // 0x80018038: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001803C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018040: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80018044: nop

    // 0x80018048: swc1        $f10, 0x104($t2)
    MEM_W(0X104, ctx->r10) = ctx->f10.u32l;
    // 0x8001804C: b           L_80018354
    // 0x80018050: nop

        goto L_80018354;
    // 0x80018050: nop

L_80018054:
    // 0x80018054: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x80018058: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001805C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018060: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80018064: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80018068: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x8001806C: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x80018070: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018074: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018078: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001807C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018080: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80018084: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018088: swc1        $f10, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f10.u32l;
    // 0x8001808C: lui         $at, 0x4420
    ctx->r1 = S32(0X4420 << 16);
    // 0x80018090: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018094: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80018098: nop

    // 0x8001809C: swc1        $f16, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f16.u32l;
    // 0x800180A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800180A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800180A8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800180AC: nop

    // 0x800180B0: swc1        $f18, 0x100($t6)
    MEM_W(0X100, ctx->r14) = ctx->f18.u32l;
    // 0x800180B4: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x800180B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800180BC: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800180C0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800180C4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800180C8: addiu       $t4, $t4, -0x59C0
    ctx->r12 = ADD32(ctx->r12, -0X59C0);
    // 0x800180CC: swc1        $f8, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f8.u32l;
    // 0x800180D0: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x800180D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800180D8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800180DC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800180E0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800180E4: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x800180E8: swc1        $f18, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f18.u32l;
    // 0x800180EC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800180F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800180F4: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x800180F8: nop

    // 0x800180FC: bne         $t9, $at, L_8001810C
    if (ctx->r25 != ctx->r1) {
        // 0x80018100: nop

            goto L_8001810C;
    }
    // 0x80018100: nop

    // 0x80018104: b           L_80018214
    // 0x80018108: nop

        goto L_80018214;
    // 0x80018108: nop

L_8001810C:
    // 0x8001810C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80018110: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80018114: lw          $t2, 0x1AC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1AC);
    // 0x80018118: nop

    // 0x8001811C: bne         $t2, $at, L_8001812C
    if (ctx->r10 != ctx->r1) {
        // 0x80018120: nop

            goto L_8001812C;
    }
    // 0x80018120: nop

    // 0x80018124: b           L_800182B4
    // 0x80018128: nop

        goto L_800182B4;
    // 0x80018128: nop

L_8001812C:
    // 0x8001812C: b           L_80018354
    // 0x80018130: nop

        goto L_80018354;
    // 0x80018130: nop

L_80018134:
    // 0x80018134: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018138: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001813C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018140: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80018144: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018148: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x8001814C: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x80018150: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018154: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018158: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001815C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018160: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80018164: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018168: swc1        $f18, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f18.u32l;
    // 0x8001816C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018170: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018174: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80018178: nop

    // 0x8001817C: swc1        $f4, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f4.u32l;
    // 0x80018180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018184: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018188: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8001818C: nop

    // 0x80018190: swc1        $f6, 0x100($t6)
    MEM_W(0X100, ctx->r14) = ctx->f6.u32l;
    // 0x80018194: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018198: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001819C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800181A0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800181A4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800181A8: addiu       $t4, $t4, -0x59C0
    ctx->r12 = ADD32(ctx->r12, -0X59C0);
    // 0x800181AC: swc1        $f16, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f16.u32l;
    // 0x800181B0: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x800181B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800181B8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800181BC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800181C0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800181C4: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x800181C8: swc1        $f6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f6.u32l;
    // 0x800181CC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800181D0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800181D4: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x800181D8: nop

    // 0x800181DC: bne         $t9, $at, L_800181EC
    if (ctx->r25 != ctx->r1) {
        // 0x800181E0: nop

            goto L_800181EC;
    }
    // 0x800181E0: nop

    // 0x800181E4: b           L_80018214
    // 0x800181E8: nop

        goto L_80018214;
    // 0x800181E8: nop

L_800181EC:
    // 0x800181EC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800181F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800181F4: lw          $t2, 0x1AC($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1AC);
    // 0x800181F8: nop

    // 0x800181FC: bne         $t2, $at, L_8001820C
    if (ctx->r10 != ctx->r1) {
        // 0x80018200: nop

            goto L_8001820C;
    }
    // 0x80018200: nop

    // 0x80018204: b           L_800182B4
    // 0x80018208: nop

        goto L_800182B4;
    // 0x80018208: nop

L_8001820C:
    // 0x8001820C: b           L_80018354
    // 0x80018210: nop

        goto L_80018354;
    // 0x80018210: nop

L_80018214:
    // 0x80018214: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018218: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001821C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018220: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80018224: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80018228: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x8001822C: swc1        $f16, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f16.u32l;
    // 0x80018230: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018234: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018238: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001823C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018240: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80018244: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018248: swc1        $f6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f6.u32l;
    // 0x8001824C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018250: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018254: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80018258: nop

    // 0x8001825C: swc1        $f8, 0xFC($t5)
    MEM_W(0XFC, ctx->r13) = ctx->f8.u32l;
    // 0x80018260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018264: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018268: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8001826C: nop

    // 0x80018270: swc1        $f10, 0x104($t6)
    MEM_W(0X104, ctx->r14) = ctx->f10.u32l;
    // 0x80018274: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018278: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001827C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018280: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80018284: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80018288: addiu       $t4, $t4, -0x59C0
    ctx->r12 = ADD32(ctx->r12, -0X59C0);
    // 0x8001828C: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    // 0x80018290: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x80018294: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018298: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001829C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800182A0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800182A4: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x800182A8: swc1        $f10, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f10.u32l;
    // 0x800182AC: b           L_80018354
    // 0x800182B0: nop

        goto L_80018354;
    // 0x800182B0: nop

L_800182B4:
    // 0x800182B4: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x800182B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800182BC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800182C0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800182C4: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800182C8: addiu       $t8, $t8, -0x59C0
    ctx->r24 = ADD32(ctx->r24, -0X59C0);
    // 0x800182CC: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x800182D0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800182D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800182D8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800182DC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800182E0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800182E4: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x800182E8: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
    // 0x800182EC: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x800182F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800182F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800182F8: nop

    // 0x800182FC: swc1        $f16, 0xFC($t0)
    MEM_W(0XFC, ctx->r8) = ctx->f16.u32l;
    // 0x80018300: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018304: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018308: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8001830C: nop

    // 0x80018310: swc1        $f18, 0x104($t2)
    MEM_W(0X104, ctx->r10) = ctx->f18.u32l;
    // 0x80018314: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x80018318: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001831C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80018320: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80018324: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018328: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x8001832C: swc1        $f8, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f8.u32l;
    // 0x80018330: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x80018334: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018338: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001833C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018340: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80018344: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018348: swc1        $f18, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f18.u32l;
    // 0x8001834C: b           L_80018354
    // 0x80018350: nop

        goto L_80018354;
    // 0x80018350: nop

L_80018354:
    // 0x80018354: b           L_80018364
    // 0x80018358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80018364;
    // 0x80018358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001835C: b           L_80018364
    // 0x80018360: nop

        goto L_80018364;
    // 0x80018360: nop

L_80018364:
    // 0x80018364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80018368: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001836C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80018370: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80018374: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80018378: jr          $ra
    // 0x8001837C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001837C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80018380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80018384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018388: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001838C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80018390: nop

    // 0x80018394: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80018398: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001839C: nop

    // 0x800183A0: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x800183A4: nop

    // 0x800183A8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800183AC: beq         $t9, $zero, L_80019898
    if (ctx->r25 == 0) {
        // 0x800183B0: nop

            goto L_80019898;
    }
    // 0x800183B0: nop

    // 0x800183B4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800183B8: addiu       $t0, $t0, 0x61D8
    ctx->r8 = ADD32(ctx->r8, 0X61D8);
    // 0x800183BC: addiu       $t1, $t0, 0x618
    ctx->r9 = ADD32(ctx->r8, 0X618);
    // 0x800183C0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800183C4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800183C8: addiu       $t2, $t2, 0x61D8
    ctx->r10 = ADD32(ctx->r10, 0X61D8);
    // 0x800183CC: addiu       $t3, $t2, 0x750
    ctx->r11 = ADD32(ctx->r10, 0X750);
    // 0x800183D0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800183D4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800183D8: nop

    // 0x800183DC: lw          $t5, 0x1A8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A8);
    // 0x800183E0: nop

    // 0x800183E4: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x800183E8: beq         $t6, $zero, L_800183F8
    if (ctx->r14 == 0) {
        // 0x800183EC: nop

            goto L_800183F8;
    }
    // 0x800183EC: nop

    // 0x800183F0: b           L_80019890
    // 0x800183F4: nop

        goto L_80019890;
    // 0x800183F4: nop

L_800183F8:
    // 0x800183F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800183FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80018400: lwc1        $f4, 0x1E8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1E8);
    // 0x80018404: nop

    // 0x80018408: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8001840C: nop

    // 0x80018410: bc1f        L_80019720
    if (!c1cs) {
        // 0x80018414: nop

            goto L_80019720;
    }
    // 0x80018414: nop

    // 0x80018418: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001841C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80018420: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018424: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018428: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001842C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80018430: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80018434: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80018438: nop

    // 0x8001843C: lwc1        $f4, 0x1E8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1E8);
    // 0x80018440: nop

    // 0x80018444: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80018448: sub.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = ctx->f6.d - ctx->f18.d;
    // 0x8001844C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80018450: swc1        $f8, 0x1E8($t8)
    MEM_W(0X1E8, ctx->r24) = ctx->f8.u32l;
    // 0x80018454: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80018458: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x8001845C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018460: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018464: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80018468: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001846C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80018470: lwc1        $f18, 0xF8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x80018474: nop

    // 0x80018478: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8001847C: swc1        $f10, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f10.u32l;
    // 0x80018480: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018484: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018488: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001848C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018490: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80018494: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80018498: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001849C: lwc1        $f18, 0x100($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X100);
    // 0x800184A0: nop

    // 0x800184A4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800184A8: swc1        $f6, 0x100($t2)
    MEM_W(0X100, ctx->r10) = ctx->f6.u32l;
    // 0x800184AC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800184B0: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x800184B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800184B8: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800184BC: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800184C0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800184C4: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800184C8: lwc1        $f18, 0xFC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XFC);
    // 0x800184CC: nop

    // 0x800184D0: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800184D4: swc1        $f4, 0xFC($t4)
    MEM_W(0XFC, ctx->r12) = ctx->f4.u32l;
    // 0x800184D8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800184DC: addiu       $t5, $t5, -0x59C0
    ctx->r13 = ADD32(ctx->r13, -0X59C0);
    // 0x800184E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800184E4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800184E8: lwc1        $f6, 0xC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800184EC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800184F0: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800184F4: lwc1        $f18, 0x104($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X104);
    // 0x800184F8: nop

    // 0x800184FC: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80018500: swc1        $f16, 0x104($t6)
    MEM_W(0X104, ctx->r14) = ctx->f16.u32l;
    // 0x80018504: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80018508: addiu       $t7, $t7, -0x59C0
    ctx->r15 = ADD32(ctx->r15, -0X59C0);
    // 0x8001850C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018510: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018514: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80018518: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001851C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018520: lwc1        $f18, 0xF8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x80018524: nop

    // 0x80018528: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8001852C: swc1        $f8, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f8.u32l;
    // 0x80018530: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80018534: addiu       $t9, $t9, -0x59C0
    ctx->r25 = ADD32(ctx->r25, -0X59C0);
    // 0x80018538: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001853C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018540: lwc1        $f16, 0x14($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80018544: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80018548: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8001854C: lwc1        $f18, 0x100($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X100);
    // 0x80018550: nop

    // 0x80018554: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80018558: swc1        $f10, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->f10.u32l;
    // 0x8001855C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80018560: addiu       $t1, $t1, -0x59C0
    ctx->r9 = ADD32(ctx->r9, -0X59C0);
    // 0x80018564: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018568: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001856C: lwc1        $f8, 0x18($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80018570: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018574: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80018578: lwc1        $f18, 0xFC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XFC);
    // 0x8001857C: nop

    // 0x80018580: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80018584: swc1        $f6, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->f6.u32l;
    // 0x80018588: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001858C: addiu       $t3, $t3, -0x59C0
    ctx->r11 = ADD32(ctx->r11, -0X59C0);
    // 0x80018590: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80018594: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80018598: lwc1        $f10, 0x1C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x8001859C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800185A0: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800185A4: lwc1        $f18, 0x104($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X104);
    // 0x800185A8: nop

    // 0x800185AC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800185B0: swc1        $f4, 0x104($t4)
    MEM_W(0X104, ctx->r12) = ctx->f4.u32l;
    // 0x800185B4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800185B8: nop

    // 0x800185BC: lw          $t6, 0x1AC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1AC);
    // 0x800185C0: nop

    // 0x800185C4: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x800185C8: beq         $at, $zero, L_800196F0
    if (ctx->r1 == 0) {
        // 0x800185CC: nop

            goto L_800196F0;
    }
    // 0x800185CC: nop

    // 0x800185D0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800185D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800185D8: addu        $at, $at, $t6
    gpr jr_addend_800185E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800185DC: lw          $t6, -0x2A18($at)
    ctx->r14 = ADD32(ctx->r1, -0X2A18);
    // 0x800185E0: nop

    // 0x800185E4: jr          $t6
    // 0x800185E8: nop

    switch (jr_addend_800185E4 >> 2) {
        case 0: goto L_800191D8; break;
        case 1: goto L_80018C40; break;
        case 2: goto L_80018C40; break;
        case 3: goto L_80018C40; break;
        case 4: goto L_80019448; break;
        case 5: goto L_80018F28; break;
        case 6: goto L_80018F28; break;
        case 7: goto L_80018F28; break;
        case 8: goto L_800186B8; break;
        case 9: goto L_800185EC; break;
        default: switch_error(__func__, 0x800185E4, 0x800ED5E8);
    }
    // 0x800185E8: nop

L_800185EC:
    // 0x800185EC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800185F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800185F4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800185F8: nop

    // 0x800185FC: swc1        $f6, 0xF8($t7)
    MEM_W(0XF8, ctx->r15) = ctx->f6.u32l;
    // 0x80018600: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018604: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018608: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8001860C: nop

    // 0x80018610: swc1        $f10, 0x100($t8)
    MEM_W(0X100, ctx->r24) = ctx->f10.u32l;
    // 0x80018614: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001861C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80018620: nop

    // 0x80018624: swc1        $f8, 0xFC($t9)
    MEM_W(0XFC, ctx->r25) = ctx->f8.u32l;
    // 0x80018628: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001862C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018630: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018634: nop

    // 0x80018638: swc1        $f18, 0x104($t0)
    MEM_W(0X104, ctx->r8) = ctx->f18.u32l;
    // 0x8001863C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018640: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018644: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80018648: nop

    // 0x8001864C: swc1        $f16, 0x110($t1)
    MEM_W(0X110, ctx->r9) = ctx->f16.u32l;
    // 0x80018650: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018654: lwc1        $f4, -0x599C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018658: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8001865C: nop

    // 0x80018660: swc1        $f4, 0x114($t2)
    MEM_W(0X114, ctx->r10) = ctx->f4.u32l;
    // 0x80018664: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018668: lwc1        $f6, -0x5998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x8001866C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80018670: nop

    // 0x80018674: swc1        $f6, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->f6.u32l;
    // 0x80018678: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001867C: lwc1        $f10, -0x5994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018680: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80018684: nop

    // 0x80018688: swc1        $f10, 0x11C($t4)
    MEM_W(0X11C, ctx->r12) = ctx->f10.u32l;
    // 0x8001868C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80018690: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80018694: nop

    // 0x80018698: swc1        $f8, 0x114($t5)
    MEM_W(0X114, ctx->r13) = ctx->f8.u32l;
    // 0x8001869C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800186A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800186A4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800186A8: nop

    // 0x800186AC: swc1        $f18, 0x11C($t6)
    MEM_W(0X11C, ctx->r14) = ctx->f18.u32l;
    // 0x800186B0: b           L_800196F0
    // 0x800186B4: nop

        goto L_800196F0;
    // 0x800186B4: nop

L_800186B8:
    // 0x800186B8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800186BC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800186C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800186C4: lwc1        $f16, 0x100($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X100);
    // 0x800186C8: nop

    // 0x800186CC: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x800186D0: nop

    // 0x800186D4: bc1f        L_800186F0
    if (!c1cs) {
        // 0x800186D8: nop

            goto L_800186F0;
    }
    // 0x800186D8: nop

    // 0x800186DC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800186E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800186E4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800186E8: nop

    // 0x800186EC: swc1        $f6, 0x100($t8)
    MEM_W(0X100, ctx->r24) = ctx->f6.u32l;
L_800186F0:
    // 0x800186F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800186F4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800186F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800186FC: lwc1        $f10, 0x104($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X104);
    // 0x80018700: nop

    // 0x80018704: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80018708: nop

    // 0x8001870C: bc1f        L_80018728
    if (!c1cs) {
        // 0x80018710: nop

            goto L_80018728;
    }
    // 0x80018710: nop

    // 0x80018714: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018718: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001871C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018720: nop

    // 0x80018724: swc1        $f18, 0x104($t0)
    MEM_W(0X104, ctx->r8) = ctx->f18.u32l;
L_80018728:
    // 0x80018728: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8001872C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018730: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018734: lwc1        $f16, 0x100($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X100);
    // 0x80018738: nop

    // 0x8001873C: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80018740: nop

    // 0x80018744: bc1f        L_80018760
    if (!c1cs) {
        // 0x80018748: nop

            goto L_80018760;
    }
    // 0x80018748: nop

    // 0x8001874C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018750: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018754: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018758: nop

    // 0x8001875C: swc1        $f6, 0x100($t2)
    MEM_W(0X100, ctx->r10) = ctx->f6.u32l;
L_80018760:
    // 0x80018760: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80018764: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018768: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001876C: lwc1        $f10, 0x104($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X104);
    // 0x80018770: nop

    // 0x80018774: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80018778: nop

    // 0x8001877C: bc1f        L_80018798
    if (!c1cs) {
        // 0x80018780: nop

            goto L_80018798;
    }
    // 0x80018780: nop

    // 0x80018784: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018788: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001878C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80018790: nop

    // 0x80018794: swc1        $f18, 0x104($t4)
    MEM_W(0X104, ctx->r12) = ctx->f18.u32l;
L_80018798:
    // 0x80018798: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8001879C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800187A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800187A4: lwc1        $f4, -0x5990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x800187A8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800187AC: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800187B0: lwc1        $f10, 0x100($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X100);
    // 0x800187B4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800187B8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800187BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800187C0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800187C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800187C8: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800187CC: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800187D0: swc1        $f6, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f6.u32l;
    // 0x800187D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800187D8: lwc1        $f10, -0x5988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800187DC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800187E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800187E4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800187E8: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800187EC: lwc1        $f4, 0x100($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X100);
    // 0x800187F0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800187F4: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800187F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800187FC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80018800: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018804: div.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80018808: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8001880C: swc1        $f18, 0x118($t6)
    MEM_W(0X118, ctx->r14) = ctx->f18.u32l;
    // 0x80018810: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018814: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018818: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001881C: lwc1        $f16, -0x598C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x80018820: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80018824: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80018828: lwc1        $f10, 0x104($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X104);
    // 0x8001882C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018830: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80018834: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018838: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8001883C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018840: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80018844: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80018848: swc1        $f6, 0x114($t7)
    MEM_W(0X114, ctx->r15) = ctx->f6.u32l;
    // 0x8001884C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018850: lwc1        $f10, -0x5984($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x80018854: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018858: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001885C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80018860: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80018864: lwc1        $f16, 0x104($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X104);
    // 0x80018868: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001886C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80018870: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018874: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018878: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001887C: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018880: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80018884: swc1        $f18, 0x11C($t8)
    MEM_W(0X11C, ctx->r24) = ctx->f18.u32l;
    // 0x80018888: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8001888C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018890: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018894: lwc1        $f4, -0x5990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x80018898: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8001889C: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800188A0: lwc1        $f10, 0x100($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X100);
    // 0x800188A4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800188A8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800188AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800188B0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800188B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800188B8: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800188BC: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800188C0: swc1        $f6, 0x110($t9)
    MEM_W(0X110, ctx->r25) = ctx->f6.u32l;
    // 0x800188C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800188C8: lwc1        $f10, -0x5988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800188CC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800188D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800188D4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800188D8: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800188DC: lwc1        $f4, 0x100($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X100);
    // 0x800188E0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800188E4: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800188E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800188EC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800188F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800188F4: div.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800188F8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800188FC: swc1        $f18, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f18.u32l;
    // 0x80018900: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018904: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018908: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001890C: lwc1        $f16, -0x598C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x80018910: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80018914: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80018918: lwc1        $f10, 0x104($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X104);
    // 0x8001891C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80018920: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80018924: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018928: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8001892C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018930: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80018934: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80018938: swc1        $f6, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->f6.u32l;
    // 0x8001893C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018940: lwc1        $f10, -0x5984($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x80018944: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018948: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001894C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018950: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80018954: lwc1        $f16, 0x104($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X104);
    // 0x80018958: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001895C: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80018960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018964: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80018968: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001896C: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018970: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80018974: swc1        $f18, 0x11C($t2)
    MEM_W(0X11C, ctx->r10) = ctx->f18.u32l;
    // 0x80018978: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001897C: nop

    // 0x80018980: lwc1        $f16, 0x110($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X110);
    // 0x80018984: lwc1        $f4, 0x118($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X118);
    // 0x80018988: nop

    // 0x8001898C: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x80018990: nop

    // 0x80018994: bc1f        L_800189B8
    if (!c1cs) {
        // 0x80018998: nop

            goto L_800189B8;
    }
    // 0x80018998: nop

    // 0x8001899C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800189A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800189A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800189A8: lwc1        $f6, 0x118($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X118);
    // 0x800189AC: nop

    // 0x800189B0: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800189B4: swc1        $f8, 0x110($t4)
    MEM_W(0X110, ctx->r12) = ctx->f8.u32l;
L_800189B8:
    // 0x800189B8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800189BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800189C0: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800189C4: lwc1        $f18, 0x110($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X110);
    // 0x800189C8: nop

    // 0x800189CC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800189D0: nop

    // 0x800189D4: bc1f        L_800189F0
    if (!c1cs) {
        // 0x800189D8: nop

            goto L_800189F0;
    }
    // 0x800189D8: nop

    // 0x800189DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800189E0: lwc1        $f4, -0x59A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800189E4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800189E8: nop

    // 0x800189EC: swc1        $f4, 0x110($t6)
    MEM_W(0X110, ctx->r14) = ctx->f4.u32l;
L_800189F0:
    // 0x800189F0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800189F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800189F8: lwc1        $f10, -0x5998($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x800189FC: lwc1        $f6, 0x118($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X118);
    // 0x80018A00: nop

    // 0x80018A04: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80018A08: nop

    // 0x80018A0C: bc1f        L_80018A28
    if (!c1cs) {
        // 0x80018A10: nop

            goto L_80018A28;
    }
    // 0x80018A10: nop

    // 0x80018A14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018A18: lwc1        $f8, -0x5998($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018A1C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80018A20: nop

    // 0x80018A24: swc1        $f8, 0x118($t8)
    MEM_W(0X118, ctx->r24) = ctx->f8.u32l;
L_80018A28:
    // 0x80018A28: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80018A2C: nop

    // 0x80018A30: lwc1        $f18, 0x114($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X114);
    // 0x80018A34: lwc1        $f16, 0x11C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X11C);
    // 0x80018A38: nop

    // 0x80018A3C: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80018A40: nop

    // 0x80018A44: bc1f        L_80018A68
    if (!c1cs) {
        // 0x80018A48: nop

            goto L_80018A68;
    }
    // 0x80018A48: nop

    // 0x80018A4C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018A50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018A54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018A58: lwc1        $f4, 0x11C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X11C);
    // 0x80018A5C: nop

    // 0x80018A60: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80018A64: swc1        $f10, 0x114($t0)
    MEM_W(0X114, ctx->r8) = ctx->f10.u32l;
L_80018A68:
    // 0x80018A68: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80018A6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018A70: lwc1        $f18, -0x599C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018A74: lwc1        $f8, 0x114($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X114);
    // 0x80018A78: nop

    // 0x80018A7C: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80018A80: nop

    // 0x80018A84: bc1f        L_80018AA0
    if (!c1cs) {
        // 0x80018A88: nop

            goto L_80018AA0;
    }
    // 0x80018A88: nop

    // 0x80018A8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018A90: lwc1        $f16, -0x599C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018A94: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80018A98: nop

    // 0x80018A9C: swc1        $f16, 0x114($t2)
    MEM_W(0X114, ctx->r10) = ctx->f16.u32l;
L_80018AA0:
    // 0x80018AA0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80018AA4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018AA8: lwc1        $f6, -0x5994($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018AAC: lwc1        $f4, 0x11C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X11C);
    // 0x80018AB0: nop

    // 0x80018AB4: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80018AB8: nop

    // 0x80018ABC: bc1f        L_80018AD8
    if (!c1cs) {
        // 0x80018AC0: nop

            goto L_80018AD8;
    }
    // 0x80018AC0: nop

    // 0x80018AC4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018AC8: lwc1        $f10, -0x5994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018ACC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80018AD0: nop

    // 0x80018AD4: swc1        $f10, 0x11C($t4)
    MEM_W(0X11C, ctx->r12) = ctx->f10.u32l;
L_80018AD8:
    // 0x80018AD8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80018ADC: nop

    // 0x80018AE0: lwc1        $f8, 0x110($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X110);
    // 0x80018AE4: lwc1        $f18, 0x118($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X118);
    // 0x80018AE8: nop

    // 0x80018AEC: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x80018AF0: nop

    // 0x80018AF4: bc1f        L_80018B18
    if (!c1cs) {
        // 0x80018AF8: nop

            goto L_80018B18;
    }
    // 0x80018AF8: nop

    // 0x80018AFC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80018B00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018B04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018B08: lwc1        $f16, 0x118($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X118);
    // 0x80018B0C: nop

    // 0x80018B10: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80018B14: swc1        $f6, 0x110($t6)
    MEM_W(0X110, ctx->r14) = ctx->f6.u32l;
L_80018B18:
    // 0x80018B18: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80018B1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018B20: lwc1        $f8, -0x59A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018B24: lwc1        $f10, 0x110($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X110);
    // 0x80018B28: nop

    // 0x80018B2C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80018B30: nop

    // 0x80018B34: bc1f        L_80018B50
    if (!c1cs) {
        // 0x80018B38: nop

            goto L_80018B50;
    }
    // 0x80018B38: nop

    // 0x80018B3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018B40: lwc1        $f18, -0x59A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018B44: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80018B48: nop

    // 0x80018B4C: swc1        $f18, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->f18.u32l;
L_80018B50:
    // 0x80018B50: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80018B54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018B58: lwc1        $f4, -0x5998($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018B5C: lwc1        $f16, 0x118($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X118);
    // 0x80018B60: nop

    // 0x80018B64: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80018B68: nop

    // 0x80018B6C: bc1f        L_80018B88
    if (!c1cs) {
        // 0x80018B70: nop

            goto L_80018B88;
    }
    // 0x80018B70: nop

    // 0x80018B74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018B78: lwc1        $f6, -0x5998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018B7C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80018B80: nop

    // 0x80018B84: swc1        $f6, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f6.u32l;
L_80018B88:
    // 0x80018B88: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80018B8C: nop

    // 0x80018B90: lwc1        $f10, 0x114($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X114);
    // 0x80018B94: lwc1        $f8, 0x11C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X11C);
    // 0x80018B98: nop

    // 0x80018B9C: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80018BA0: nop

    // 0x80018BA4: bc1f        L_80018BC8
    if (!c1cs) {
        // 0x80018BA8: nop

            goto L_80018BC8;
    }
    // 0x80018BA8: nop

    // 0x80018BAC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018BB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018BB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018BB8: lwc1        $f18, 0x11C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X11C);
    // 0x80018BBC: nop

    // 0x80018BC0: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80018BC4: swc1        $f4, 0x114($t2)
    MEM_W(0X114, ctx->r10) = ctx->f4.u32l;
L_80018BC8:
    // 0x80018BC8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80018BCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018BD0: lwc1        $f10, -0x599C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018BD4: lwc1        $f6, 0x114($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X114);
    // 0x80018BD8: nop

    // 0x80018BDC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80018BE0: nop

    // 0x80018BE4: bc1f        L_80018C00
    if (!c1cs) {
        // 0x80018BE8: nop

            goto L_80018C00;
    }
    // 0x80018BE8: nop

    // 0x80018BEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018BF0: lwc1        $f8, -0x599C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80018BF4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80018BF8: nop

    // 0x80018BFC: swc1        $f8, 0x114($t4)
    MEM_W(0X114, ctx->r12) = ctx->f8.u32l;
L_80018C00:
    // 0x80018C00: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80018C04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018C08: lwc1        $f16, -0x5994($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018C0C: lwc1        $f18, 0x11C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X11C);
    // 0x80018C10: nop

    // 0x80018C14: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80018C18: nop

    // 0x80018C1C: bc1f        L_80018C38
    if (!c1cs) {
        // 0x80018C20: nop

            goto L_80018C38;
    }
    // 0x80018C20: nop

    // 0x80018C24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018C28: lwc1        $f4, -0x5994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80018C2C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80018C30: nop

    // 0x80018C34: swc1        $f4, 0x11C($t6)
    MEM_W(0X11C, ctx->r14) = ctx->f4.u32l;
L_80018C38:
    // 0x80018C38: b           L_800196F0
    // 0x80018C3C: nop

        goto L_800196F0;
    // 0x80018C3C: nop

L_80018C40:
    // 0x80018C40: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80018C44: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018C48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018C4C: lwc1        $f6, 0xF8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XF8);
    // 0x80018C50: nop

    // 0x80018C54: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80018C58: nop

    // 0x80018C5C: bc1f        L_80018C78
    if (!c1cs) {
        // 0x80018C60: nop

            goto L_80018C78;
    }
    // 0x80018C60: nop

    // 0x80018C64: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018C68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018C6C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80018C70: nop

    // 0x80018C74: swc1        $f8, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f8.u32l;
L_80018C78:
    // 0x80018C78: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80018C7C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018C80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018C84: lwc1        $f18, 0x100($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X100);
    // 0x80018C88: nop

    // 0x80018C8C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80018C90: nop

    // 0x80018C94: bc1f        L_80018CB0
    if (!c1cs) {
        // 0x80018C98: nop

            goto L_80018CB0;
    }
    // 0x80018C98: nop

    // 0x80018C9C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018CA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018CA4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018CA8: nop

    // 0x80018CAC: swc1        $f4, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->f4.u32l;
L_80018CB0:
    // 0x80018CB0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80018CB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018CB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018CBC: lwc1        $f6, 0xF8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x80018CC0: nop

    // 0x80018CC4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80018CC8: nop

    // 0x80018CCC: bc1f        L_80018CE8
    if (!c1cs) {
        // 0x80018CD0: nop

            goto L_80018CE8;
    }
    // 0x80018CD0: nop

    // 0x80018CD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018CD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018CDC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80018CE0: nop

    // 0x80018CE4: swc1        $f8, 0xF8($t2)
    MEM_W(0XF8, ctx->r10) = ctx->f8.u32l;
L_80018CE8:
    // 0x80018CE8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80018CEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018CF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018CF4: lwc1        $f18, 0x100($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X100);
    // 0x80018CF8: nop

    // 0x80018CFC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80018D00: nop

    // 0x80018D04: bc1f        L_80018D20
    if (!c1cs) {
        // 0x80018D08: nop

            goto L_80018D20;
    }
    // 0x80018D08: nop

    // 0x80018D0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018D10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018D14: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80018D18: nop

    // 0x80018D1C: swc1        $f4, 0x100($t4)
    MEM_W(0X100, ctx->r12) = ctx->f4.u32l;
L_80018D20:
    // 0x80018D20: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80018D24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018D28: lwc1        $f6, -0x5990($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x80018D2C: lwc1        $f10, 0x100($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X100);
    // 0x80018D30: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018D34: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80018D38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018D3C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80018D40: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80018D44: lwc1        $f4, 0x100($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X100);
    // 0x80018D48: nop

    // 0x80018D4C: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80018D50: swc1        $f6, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f6.u32l;
    // 0x80018D54: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80018D58: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018D5C: lwc1        $f10, -0x5988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x80018D60: lwc1        $f8, 0x100($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X100);
    // 0x80018D64: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018D68: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018D6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018D70: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80018D74: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80018D78: lwc1        $f6, 0x100($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X100);
    // 0x80018D7C: nop

    // 0x80018D80: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80018D84: swc1        $f10, 0x118($t7)
    MEM_W(0X118, ctx->r15) = ctx->f10.u32l;
    // 0x80018D88: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80018D8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018D90: lwc1        $f18, -0x5990($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x80018D94: lwc1        $f8, 0x100($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X100);
    // 0x80018D98: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018D9C: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80018DA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018DA4: nop

    // 0x80018DA8: div.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80018DAC: swc1        $f16, 0x110($t9)
    MEM_W(0X110, ctx->r25) = ctx->f16.u32l;
    // 0x80018DB0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80018DB4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018DB8: lwc1        $f8, -0x5988($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x80018DBC: lwc1        $f10, 0x100($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X100);
    // 0x80018DC0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018DC4: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018DC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018DCC: nop

    // 0x80018DD0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80018DD4: swc1        $f6, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f6.u32l;
    // 0x80018DD8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80018DDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018DE0: lwc1        $f10, -0x5998($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018DE4: lwc1        $f16, 0x110($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X110);
    // 0x80018DE8: nop

    // 0x80018DEC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80018DF0: nop

    // 0x80018DF4: bc1f        L_80018E10
    if (!c1cs) {
        // 0x80018DF8: nop

            goto L_80018E10;
    }
    // 0x80018DF8: nop

    // 0x80018DFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E00: lwc1        $f8, -0x5998($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018E04: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80018E08: nop

    // 0x80018E0C: swc1        $f8, 0x110($t2)
    MEM_W(0X110, ctx->r10) = ctx->f8.u32l;
L_80018E10:
    // 0x80018E10: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E14: lwc1        $f4, -0x5998($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018E18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018E1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018E20: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80018E24: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80018E28: lwc1        $f18, 0x118($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X118);
    // 0x80018E2C: nop

    // 0x80018E30: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80018E34: nop

    // 0x80018E38: bc1f        L_80018E5C
    if (!c1cs) {
        // 0x80018E3C: nop

            goto L_80018E5C;
    }
    // 0x80018E3C: nop

    // 0x80018E40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E44: lwc1        $f10, -0x5998($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80018E48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018E4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018E50: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80018E54: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80018E58: swc1        $f4, 0x118($t4)
    MEM_W(0X118, ctx->r12) = ctx->f4.u32l;
L_80018E5C:
    // 0x80018E5C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E60: lwc1        $f18, -0x59A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018E64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018E68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80018E6C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80018E70: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80018E74: lwc1        $f6, 0x110($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X110);
    // 0x80018E78: nop

    // 0x80018E7C: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80018E80: nop

    // 0x80018E84: bc1f        L_80018EA8
    if (!c1cs) {
        // 0x80018E88: nop

            goto L_80018EA8;
    }
    // 0x80018E88: nop

    // 0x80018E8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018E90: lwc1        $f8, -0x59A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018E94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018E98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018E9C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80018EA0: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80018EA4: swc1        $f18, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f18.u32l;
L_80018EA8:
    // 0x80018EA8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80018EAC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018EB0: lwc1        $f6, -0x59A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018EB4: lwc1        $f16, 0x118($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X118);
    // 0x80018EB8: nop

    // 0x80018EBC: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80018EC0: nop

    // 0x80018EC4: bc1f        L_80018EE0
    if (!c1cs) {
        // 0x80018EC8: nop

            goto L_80018EE0;
    }
    // 0x80018EC8: nop

    // 0x80018ECC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018ED0: lwc1        $f10, -0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80018ED4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80018ED8: nop

    // 0x80018EDC: swc1        $f10, 0x118($t7)
    MEM_W(0X118, ctx->r15) = ctx->f10.u32l;
L_80018EE0:
    // 0x80018EE0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80018EE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018EE8: lw          $t0, 0x1AC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1AC);
    // 0x80018EEC: nop

    // 0x80018EF0: bne         $t0, $at, L_80018F00
    if (ctx->r8 != ctx->r1) {
        // 0x80018EF4: nop

            goto L_80018F00;
    }
    // 0x80018EF4: nop

    // 0x80018EF8: b           L_800191D8
    // 0x80018EFC: nop

        goto L_800191D8;
    // 0x80018EFC: nop

L_80018F00:
    // 0x80018F00: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80018F04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80018F08: lw          $t2, 0x1AC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1AC);
    // 0x80018F0C: nop

    // 0x80018F10: bne         $t2, $at, L_80018F20
    if (ctx->r10 != ctx->r1) {
        // 0x80018F14: nop

            goto L_80018F20;
    }
    // 0x80018F14: nop

    // 0x80018F18: b           L_80019448
    // 0x80018F1C: nop

        goto L_80019448;
    // 0x80018F1C: nop

L_80018F20:
    // 0x80018F20: b           L_800196F0
    // 0x80018F24: nop

        goto L_800196F0;
    // 0x80018F24: nop

L_80018F28:
    // 0x80018F28: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80018F2C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018F30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018F34: lwc1        $f8, 0xF8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XF8);
    // 0x80018F38: nop

    // 0x80018F3C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80018F40: nop

    // 0x80018F44: bc1f        L_80018F60
    if (!c1cs) {
        // 0x80018F48: nop

            goto L_80018F60;
    }
    // 0x80018F48: nop

    // 0x80018F4C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018F50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018F54: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80018F58: nop

    // 0x80018F5C: swc1        $f18, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f18.u32l;
L_80018F60:
    // 0x80018F60: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80018F64: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018F68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018F6C: lwc1        $f16, 0x100($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X100);
    // 0x80018F70: nop

    // 0x80018F74: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80018F78: nop

    // 0x80018F7C: bc1f        L_80018F98
    if (!c1cs) {
        // 0x80018F80: nop

            goto L_80018F98;
    }
    // 0x80018F80: nop

    // 0x80018F84: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018F88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018F8C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80018F90: nop

    // 0x80018F94: swc1        $f10, 0x100($t5)
    MEM_W(0X100, ctx->r13) = ctx->f10.u32l;
L_80018F98:
    // 0x80018F98: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80018F9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018FA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018FA4: lwc1        $f8, 0x100($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X100);
    // 0x80018FA8: nop

    // 0x80018FAC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80018FB0: nop

    // 0x80018FB4: bc1f        L_80018FD0
    if (!c1cs) {
        // 0x80018FB8: nop

            goto L_80018FD0;
    }
    // 0x80018FB8: nop

    // 0x80018FBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018FC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80018FC4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80018FC8: nop

    // 0x80018FCC: swc1        $f18, 0x100($t7)
    MEM_W(0X100, ctx->r15) = ctx->f18.u32l;
L_80018FD0:
    // 0x80018FD0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80018FD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80018FD8: lwc1        $f6, -0x5990($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x80018FDC: lwc1        $f16, 0x100($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X100);
    // 0x80018FE0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80018FE4: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80018FE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018FEC: nop

    // 0x80018FF0: div.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018FF4: swc1        $f4, 0x110($t9)
    MEM_W(0X110, ctx->r25) = ctx->f4.u32l;
    // 0x80018FF8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018FFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019000: lwc1        $f16, -0x5988($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x80019004: lwc1        $f18, 0x100($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X100);
    // 0x80019008: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8001900C: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80019010: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019014: nop

    // 0x80019018: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001901C: swc1        $f8, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f8.u32l;
    // 0x80019020: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80019024: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019028: lwc1        $f4, -0x5990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5990);
    // 0x8001902C: lwc1        $f18, 0x100($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X100);
    // 0x80019030: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019034: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80019038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001903C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80019040: div.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80019044: lwc1        $f8, 0x100($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X100);
    // 0x80019048: nop

    // 0x8001904C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80019050: swc1        $f4, 0x110($t1)
    MEM_W(0X110, ctx->r9) = ctx->f4.u32l;
    // 0x80019054: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80019058: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001905C: lwc1        $f18, -0x5988($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x80019060: lwc1        $f16, 0x100($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X100);
    // 0x80019064: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019068: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8001906C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019070: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80019074: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80019078: lwc1        $f4, 0x100($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X100);
    // 0x8001907C: nop

    // 0x80019080: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80019084: swc1        $f18, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->f18.u32l;
    // 0x80019088: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001908C: lwc1        $f6, -0x59A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80019090: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019094: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019098: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001909C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800190A0: lwc1        $f16, 0x110($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X110);
    // 0x800190A4: nop

    // 0x800190A8: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800190AC: nop

    // 0x800190B0: bc1f        L_800190D4
    if (!c1cs) {
        // 0x800190B4: nop

            goto L_800190D4;
    }
    // 0x800190B4: nop

    // 0x800190B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800190BC: lwc1        $f10, -0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800190C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800190C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800190C8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800190CC: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800190D0: swc1        $f6, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f6.u32l;
L_800190D4:
    // 0x800190D4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800190D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800190DC: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800190E0: lwc1        $f8, 0x118($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X118);
    // 0x800190E4: nop

    // 0x800190E8: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800190EC: nop

    // 0x800190F0: bc1f        L_8001910C
    if (!c1cs) {
        // 0x800190F4: nop

            goto L_8001910C;
    }
    // 0x800190F4: nop

    // 0x800190F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800190FC: lwc1        $f4, -0x59A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80019100: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80019104: nop

    // 0x80019108: swc1        $f4, 0x118($t7)
    MEM_W(0X118, ctx->r15) = ctx->f4.u32l;
L_8001910C:
    // 0x8001910C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80019110: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019114: lwc1        $f18, -0x5998($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80019118: lwc1        $f10, 0x110($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X110);
    // 0x8001911C: nop

    // 0x80019120: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80019124: nop

    // 0x80019128: bc1f        L_80019144
    if (!c1cs) {
        // 0x8001912C: nop

            goto L_80019144;
    }
    // 0x8001912C: nop

    // 0x80019130: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019134: lwc1        $f6, -0x5998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80019138: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001913C: nop

    // 0x80019140: swc1        $f6, 0x110($t0)
    MEM_W(0X110, ctx->r8) = ctx->f6.u32l;
L_80019144:
    // 0x80019144: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019148: lwc1        $f16, -0x5998($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x8001914C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019150: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80019154: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80019158: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8001915C: lwc1        $f8, 0x118($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X118);
    // 0x80019160: nop

    // 0x80019164: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80019168: nop

    // 0x8001916C: bc1f        L_80019190
    if (!c1cs) {
        // 0x80019170: nop

            goto L_80019190;
    }
    // 0x80019170: nop

    // 0x80019174: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019178: lwc1        $f18, -0x5998($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x8001917C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019180: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80019184: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80019188: add.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8001918C: swc1        $f16, 0x118($t1)
    MEM_W(0X118, ctx->r9) = ctx->f16.u32l;
L_80019190:
    // 0x80019190: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80019194: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80019198: lw          $t3, 0x1AC($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X1AC);
    // 0x8001919C: nop

    // 0x800191A0: bne         $t3, $at, L_800191B0
    if (ctx->r11 != ctx->r1) {
        // 0x800191A4: nop

            goto L_800191B0;
    }
    // 0x800191A4: nop

    // 0x800191A8: b           L_800191D8
    // 0x800191AC: nop

        goto L_800191D8;
    // 0x800191AC: nop

L_800191B0:
    // 0x800191B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800191B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800191B8: lw          $t5, 0x1AC($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X1AC);
    // 0x800191BC: nop

    // 0x800191C0: bne         $t5, $at, L_800191D0
    if (ctx->r13 != ctx->r1) {
        // 0x800191C4: nop

            goto L_800191D0;
    }
    // 0x800191C4: nop

    // 0x800191C8: b           L_80019448
    // 0x800191CC: nop

        goto L_80019448;
    // 0x800191CC: nop

L_800191D0:
    // 0x800191D0: b           L_800196F0
    // 0x800191D4: nop

        goto L_800196F0;
    // 0x800191D4: nop

L_800191D8:
    // 0x800191D8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800191DC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800191E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800191E4: lwc1        $f4, 0xFC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XFC);
    // 0x800191E8: nop

    // 0x800191EC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800191F0: nop

    // 0x800191F4: bc1f        L_80019210
    if (!c1cs) {
        // 0x800191F8: nop

            goto L_80019210;
    }
    // 0x800191F8: nop

    // 0x800191FC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019200: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019204: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80019208: nop

    // 0x8001920C: swc1        $f10, 0xFC($t7)
    MEM_W(0XFC, ctx->r15) = ctx->f10.u32l;
L_80019210:
    // 0x80019210: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80019214: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019218: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001921C: lwc1        $f18, 0x104($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X104);
    // 0x80019220: nop

    // 0x80019224: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80019228: nop

    // 0x8001922C: bc1f        L_80019248
    if (!c1cs) {
        // 0x80019230: nop

            goto L_80019248;
    }
    // 0x80019230: nop

    // 0x80019234: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019238: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001923C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80019240: nop

    // 0x80019244: swc1        $f16, 0x104($t0)
    MEM_W(0X104, ctx->r8) = ctx->f16.u32l;
L_80019248:
    // 0x80019248: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8001924C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019250: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019254: lwc1        $f4, 0x104($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X104);
    // 0x80019258: nop

    // 0x8001925C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80019260: nop

    // 0x80019264: bc1f        L_80019280
    if (!c1cs) {
        // 0x80019268: nop

            goto L_80019280;
    }
    // 0x80019268: nop

    // 0x8001926C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019270: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019274: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80019278: nop

    // 0x8001927C: swc1        $f10, 0x104($t1)
    MEM_W(0X104, ctx->r9) = ctx->f10.u32l;
L_80019280:
    // 0x80019280: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80019284: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019288: lwc1        $f6, -0x598C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x8001928C: lwc1        $f18, 0x104($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X104);
    // 0x80019290: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019294: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80019298: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001929C: nop

    // 0x800192A0: div.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800192A4: swc1        $f8, 0x114($t4)
    MEM_W(0X114, ctx->r12) = ctx->f8.u32l;
    // 0x800192A8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800192AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800192B0: lwc1        $f18, -0x5984($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800192B4: lwc1        $f10, 0x104($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X104);
    // 0x800192B8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800192BC: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800192C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800192C4: nop

    // 0x800192C8: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800192CC: swc1        $f4, 0x11C($t3)
    MEM_W(0X11C, ctx->r11) = ctx->f4.u32l;
    // 0x800192D0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800192D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800192D8: lwc1        $f8, -0x598C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x800192DC: lwc1        $f10, 0x104($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X104);
    // 0x800192E0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800192E4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800192E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800192EC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800192F0: div.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800192F4: lwc1        $f4, 0x104($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X104);
    // 0x800192F8: nop

    // 0x800192FC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80019300: swc1        $f8, 0x114($t6)
    MEM_W(0X114, ctx->r14) = ctx->f8.u32l;
    // 0x80019304: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80019308: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001930C: lwc1        $f10, -0x5984($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x80019310: lwc1        $f18, 0x104($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X104);
    // 0x80019314: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019318: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8001931C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80019320: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80019324: div.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80019328: lwc1        $f8, 0x104($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X104);
    // 0x8001932C: nop

    // 0x80019330: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80019334: swc1        $f10, 0x11C($t8)
    MEM_W(0X11C, ctx->r24) = ctx->f10.u32l;
    // 0x80019338: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001933C: lwc1        $f6, -0x599C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80019340: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019344: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80019348: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001934C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80019350: lwc1        $f18, 0x114($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X114);
    // 0x80019354: nop

    // 0x80019358: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8001935C: nop

    // 0x80019360: bc1f        L_80019384
    if (!c1cs) {
        // 0x80019364: nop

            goto L_80019384;
    }
    // 0x80019364: nop

    // 0x80019368: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001936C: lwc1        $f16, -0x599C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80019370: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019374: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019378: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001937C: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80019380: swc1        $f6, 0x114($t0)
    MEM_W(0X114, ctx->r8) = ctx->f6.u32l;
L_80019384:
    // 0x80019384: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80019388: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001938C: lwc1        $f18, -0x599C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x80019390: lwc1        $f4, 0x11C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X11C);
    // 0x80019394: nop

    // 0x80019398: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8001939C: nop

    // 0x800193A0: bc1f        L_800193BC
    if (!c1cs) {
        // 0x800193A4: nop

            goto L_800193BC;
    }
    // 0x800193A4: nop

    // 0x800193A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800193AC: lwc1        $f8, -0x599C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800193B0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800193B4: nop

    // 0x800193B8: swc1        $f8, 0x11C($t1)
    MEM_W(0X11C, ctx->r9) = ctx->f8.u32l;
L_800193BC:
    // 0x800193BC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800193C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800193C4: lwc1        $f10, -0x5994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x800193C8: lwc1        $f16, 0x114($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X114);
    // 0x800193CC: nop

    // 0x800193D0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800193D4: nop

    // 0x800193D8: bc1f        L_800193F4
    if (!c1cs) {
        // 0x800193DC: nop

            goto L_800193F4;
    }
    // 0x800193DC: nop

    // 0x800193E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800193E4: lwc1        $f6, -0x5994($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x800193E8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800193EC: nop

    // 0x800193F0: swc1        $f6, 0x114($t3)
    MEM_W(0X114, ctx->r11) = ctx->f6.u32l;
L_800193F4:
    // 0x800193F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800193F8: lwc1        $f18, -0x5994($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x800193FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019404: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80019408: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8001940C: lwc1        $f4, 0x11C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X11C);
    // 0x80019410: nop

    // 0x80019414: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80019418: nop

    // 0x8001941C: bc1f        L_80019440
    if (!c1cs) {
        // 0x80019420: nop

            goto L_80019440;
    }
    // 0x80019420: nop

    // 0x80019424: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019428: lwc1        $f10, -0x5994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x8001942C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80019434: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80019438: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8001943C: swc1        $f18, 0x11C($t6)
    MEM_W(0X11C, ctx->r14) = ctx->f18.u32l;
L_80019440:
    // 0x80019440: b           L_800196F0
    // 0x80019444: nop

        goto L_800196F0;
    // 0x80019444: nop

L_80019448:
    // 0x80019448: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001944C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019450: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80019454: lwc1        $f8, 0xFC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x80019458: nop

    // 0x8001945C: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80019460: nop

    // 0x80019464: bc1f        L_80019480
    if (!c1cs) {
        // 0x80019468: nop

            goto L_80019480;
    }
    // 0x80019468: nop

    // 0x8001946C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019470: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80019474: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80019478: nop

    // 0x8001947C: swc1        $f16, 0xFC($t8)
    MEM_W(0XFC, ctx->r24) = ctx->f16.u32l;
L_80019480:
    // 0x80019480: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80019484: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019488: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001948C: lwc1        $f10, 0x104($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X104);
    // 0x80019490: nop

    // 0x80019494: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80019498: nop

    // 0x8001949C: bc1f        L_800194B8
    if (!c1cs) {
        // 0x800194A0: nop

            goto L_800194B8;
    }
    // 0x800194A0: nop

    // 0x800194A4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800194A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800194AC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800194B0: nop

    // 0x800194B4: swc1        $f18, 0x104($t0)
    MEM_W(0X104, ctx->r8) = ctx->f18.u32l;
L_800194B8:
    // 0x800194B8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800194BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800194C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800194C4: lwc1        $f8, 0xFC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XFC);
    // 0x800194C8: nop

    // 0x800194CC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800194D0: nop

    // 0x800194D4: bc1f        L_800194F0
    if (!c1cs) {
        // 0x800194D8: nop

            goto L_800194F0;
    }
    // 0x800194D8: nop

    // 0x800194DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800194E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800194E4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800194E8: nop

    // 0x800194EC: swc1        $f16, 0xFC($t1)
    MEM_W(0XFC, ctx->r9) = ctx->f16.u32l;
L_800194F0:
    // 0x800194F0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800194F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800194F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800194FC: lwc1        $f10, 0x104($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X104);
    // 0x80019500: nop

    // 0x80019504: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80019508: nop

    // 0x8001950C: bc1f        L_80019528
    if (!c1cs) {
        // 0x80019510: nop

            goto L_80019528;
    }
    // 0x80019510: nop

    // 0x80019514: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019518: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001951C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80019520: nop

    // 0x80019524: swc1        $f18, 0x104($t3)
    MEM_W(0X104, ctx->r11) = ctx->f18.u32l;
L_80019528:
    // 0x80019528: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8001952C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019530: lwc1        $f8, -0x598C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x80019534: lwc1        $f4, 0x104($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X104);
    // 0x80019538: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001953C: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80019540: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019544: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80019548: div.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8001954C: lwc1        $f18, 0x104($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X104);
    // 0x80019550: nop

    // 0x80019554: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80019558: swc1        $f8, 0x114($t5)
    MEM_W(0X114, ctx->r13) = ctx->f8.u32l;
    // 0x8001955C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80019560: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019564: lwc1        $f4, -0x5984($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x80019568: lwc1        $f16, 0x104($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X104);
    // 0x8001956C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80019570: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80019574: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80019578: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001957C: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80019580: lwc1        $f8, 0x104($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X104);
    // 0x80019584: nop

    // 0x80019588: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001958C: swc1        $f4, 0x11C($t7)
    MEM_W(0X11C, ctx->r15) = ctx->f4.u32l;
    // 0x80019590: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80019594: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019598: lwc1        $f10, -0x598C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X598C);
    // 0x8001959C: lwc1        $f16, 0x104($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X104);
    // 0x800195A0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800195A4: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800195A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800195AC: nop

    // 0x800195B0: div.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800195B4: swc1        $f6, 0x114($t9)
    MEM_W(0X114, ctx->r25) = ctx->f6.u32l;
    // 0x800195B8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800195BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800195C0: lwc1        $f16, -0x5984($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800195C4: lwc1        $f4, 0x104($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X104);
    // 0x800195C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800195CC: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800195D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800195D4: nop

    // 0x800195D8: div.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800195DC: swc1        $f8, 0x11C($t0)
    MEM_W(0X11C, ctx->r8) = ctx->f8.u32l;
    // 0x800195E0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800195E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800195E8: lwc1        $f4, -0x5994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x800195EC: lwc1        $f6, 0x114($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X114);
    // 0x800195F0: nop

    // 0x800195F4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800195F8: nop

    // 0x800195FC: bc1f        L_80019618
    if (!c1cs) {
        // 0x80019600: nop

            goto L_80019618;
    }
    // 0x80019600: nop

    // 0x80019604: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019608: lwc1        $f16, -0x5994($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x8001960C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80019610: nop

    // 0x80019614: swc1        $f16, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->f16.u32l;
L_80019618:
    // 0x80019618: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001961C: lwc1        $f18, -0x5994($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80019620: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019624: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019628: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8001962C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80019630: lwc1        $f10, 0x11C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X11C);
    // 0x80019634: nop

    // 0x80019638: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8001963C: nop

    // 0x80019640: bc1f        L_80019664
    if (!c1cs) {
        // 0x80019644: nop

            goto L_80019664;
    }
    // 0x80019644: nop

    // 0x80019648: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001964C: lwc1        $f4, -0x5994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80019650: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019654: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80019658: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001965C: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80019660: swc1        $f18, 0x11C($t3)
    MEM_W(0X11C, ctx->r11) = ctx->f18.u32l;
L_80019664:
    // 0x80019664: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019668: lwc1        $f10, -0x599C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x8001966C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019670: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80019674: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80019678: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8001967C: lwc1        $f8, 0x114($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X114);
    // 0x80019680: nop

    // 0x80019684: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80019688: nop

    // 0x8001968C: bc1f        L_800196B0
    if (!c1cs) {
        // 0x80019690: nop

            goto L_800196B0;
    }
    // 0x80019690: nop

    // 0x80019694: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019698: lwc1        $f16, -0x599C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x8001969C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800196A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800196A4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800196A8: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800196AC: swc1        $f10, 0x114($t5)
    MEM_W(0X114, ctx->r13) = ctx->f10.u32l;
L_800196B0:
    // 0x800196B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800196B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800196B8: lwc1        $f8, -0x599C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800196BC: lwc1        $f6, 0x11C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X11C);
    // 0x800196C0: nop

    // 0x800196C4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800196C8: nop

    // 0x800196CC: bc1f        L_800196E8
    if (!c1cs) {
        // 0x800196D0: nop

            goto L_800196E8;
    }
    // 0x800196D0: nop

    // 0x800196D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800196D8: lwc1        $f4, -0x599C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800196DC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800196E0: nop

    // 0x800196E4: swc1        $f4, 0x11C($t7)
    MEM_W(0X11C, ctx->r15) = ctx->f4.u32l;
L_800196E8:
    // 0x800196E8: b           L_800196F0
    // 0x800196EC: nop

        goto L_800196F0;
    // 0x800196EC: nop

L_800196F0:
    // 0x800196F0: jal         0x800C1754
    // 0x800196F4: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x800196F4: nop

    after_0:
    // 0x800196F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800196FC: jal         0x8009A14C
    // 0x80019700: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x80019700: nop

    after_1:
    // 0x80019704: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80019708: jal         0x800997D8
    // 0x8001970C: nop

    func_800997D8(rdram, ctx);
        goto after_2;
    // 0x8001970C: nop

    after_2:
    // 0x80019710: jal         0x800C1A28
    // 0x80019714: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x80019714: nop

    after_3:
    // 0x80019718: b           L_80019890
    // 0x8001971C: nop

        goto L_80019890;
    // 0x8001971C: nop

L_80019720:
    // 0x80019720: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80019724: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80019728: lw          $t0, 0x1A8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A8);
    // 0x8001972C: nop

    // 0x80019730: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x80019734: sw          $t2, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = ctx->r10;
    // 0x80019738: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001973C: nop

    // 0x80019740: lw          $t4, 0x1A8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X1A8);
    // 0x80019744: nop

    // 0x80019748: ori         $t3, $t4, 0x2
    ctx->r11 = ctx->r12 | 0X2;
    // 0x8001974C: sw          $t3, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r11;
    // 0x80019750: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019754: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80019758: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001975C: nop

    // 0x80019760: swc1        $f16, 0xF8($t6)
    MEM_W(0XF8, ctx->r14) = ctx->f16.u32l;
    // 0x80019764: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019768: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001976C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80019770: nop

    // 0x80019774: swc1        $f18, 0x100($t5)
    MEM_W(0X100, ctx->r13) = ctx->f18.u32l;
    // 0x80019778: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8001977C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019780: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80019784: nop

    // 0x80019788: swc1        $f10, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f10.u32l;
    // 0x8001978C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80019790: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80019794: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80019798: nop

    // 0x8001979C: swc1        $f6, 0x100($t7)
    MEM_W(0X100, ctx->r15) = ctx->f6.u32l;
    // 0x800197A0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800197A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800197A8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800197AC: nop

    // 0x800197B0: swc1        $f8, 0xFC($t0)
    MEM_W(0XFC, ctx->r8) = ctx->f8.u32l;
    // 0x800197B4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800197B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800197BC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800197C0: nop

    // 0x800197C4: swc1        $f4, 0x104($t2)
    MEM_W(0X104, ctx->r10) = ctx->f4.u32l;
    // 0x800197C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800197CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800197D0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800197D4: nop

    // 0x800197D8: swc1        $f16, 0xFC($t9)
    MEM_W(0XFC, ctx->r25) = ctx->f16.u32l;
    // 0x800197DC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800197E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800197E4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800197E8: nop

    // 0x800197EC: swc1        $f18, 0x104($t4)
    MEM_W(0X104, ctx->r12) = ctx->f18.u32l;
    // 0x800197F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800197F4: lwc1        $f10, -0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800197F8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800197FC: nop

    // 0x80019800: swc1        $f10, 0x110($t3)
    MEM_W(0X110, ctx->r11) = ctx->f10.u32l;
    // 0x80019804: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019808: lwc1        $f6, -0x599C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x8001980C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80019810: nop

    // 0x80019814: swc1        $f6, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->f6.u32l;
    // 0x80019818: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001981C: lwc1        $f8, -0x5998($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80019820: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80019824: nop

    // 0x80019828: swc1        $f8, 0x118($t6)
    MEM_W(0X118, ctx->r14) = ctx->f8.u32l;
    // 0x8001982C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019830: lwc1        $f4, -0x5994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80019834: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80019838: nop

    // 0x8001983C: swc1        $f4, 0x11C($t5)
    MEM_W(0X11C, ctx->r13) = ctx->f4.u32l;
    // 0x80019840: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019844: lwc1        $f16, -0x59A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x80019848: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001984C: nop

    // 0x80019850: swc1        $f16, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->f16.u32l;
    // 0x80019854: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019858: lwc1        $f18, -0x599C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x8001985C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80019860: nop

    // 0x80019864: swc1        $f18, 0x114($t7)
    MEM_W(0X114, ctx->r15) = ctx->f18.u32l;
    // 0x80019868: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001986C: lwc1        $f10, -0x5998($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5998);
    // 0x80019870: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80019874: nop

    // 0x80019878: swc1        $f10, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->f10.u32l;
    // 0x8001987C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80019880: lwc1        $f6, -0x5994($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5994);
    // 0x80019884: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80019888: nop

    // 0x8001988C: swc1        $f6, 0x11C($t2)
    MEM_W(0X11C, ctx->r10) = ctx->f6.u32l;
L_80019890:
    // 0x80019890: b           L_800198D8
    // 0x80019894: nop

        goto L_800198D8;
    // 0x80019894: nop

L_80019898:
    // 0x80019898: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001989C: nop

    // 0x800198A0: lw          $t4, 0x1A8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X1A8);
    // 0x800198A4: nop

    // 0x800198A8: andi        $t3, $t4, 0x2
    ctx->r11 = ctx->r12 & 0X2;
    // 0x800198AC: beq         $t3, $zero, L_800198D8
    if (ctx->r11 == 0) {
        // 0x800198B0: nop

            goto L_800198D8;
    }
    // 0x800198B0: nop

    // 0x800198B4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800198B8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800198BC: lw          $t6, 0x1A8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X1A8);
    // 0x800198C0: nop

    // 0x800198C4: and         $t5, $t6, $at
    ctx->r13 = ctx->r14 & ctx->r1;
    // 0x800198C8: sw          $t5, 0x1A8($t1)
    MEM_W(0X1A8, ctx->r9) = ctx->r13;
    // 0x800198CC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800198D0: jal         0x80019F4C
    // 0x800198D4: nop

    func_80019F4C(rdram, ctx);
        goto after_4;
    // 0x800198D4: nop

    after_4:
L_800198D8:
    // 0x800198D8: b           L_800198E8
    // 0x800198DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800198E8;
    // 0x800198DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800198E0: b           L_800198E8
    // 0x800198E4: nop

        goto L_800198E8;
    // 0x800198E4: nop

L_800198E8:
    // 0x800198E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800198EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800198F0: jr          $ra
    // 0x800198F4: nop

    return;
    // 0x800198F4: nop

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
RECOMP_FUNC void func_80019C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019C20: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80019C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019C28: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80019C2C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80019C30: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80019C34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80019C38: jal         0x80099E2C
    // 0x80019C3C: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x80019C3C: nop

    after_0:
    // 0x80019C40: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80019C44: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80019C48: sh          $t6, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r14;
    // 0x80019C4C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80019C50: nop

    // 0x80019C54: lw          $t9, 0xC0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC0);
    // 0x80019C58: nop

    // 0x80019C5C: ori         $t0, $t9, 0x1108
    ctx->r8 = ctx->r25 | 0X1108;
    // 0x80019C60: sw          $t0, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r8;
    // 0x80019C64: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80019C68: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80019C6C: sh          $t1, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r9;
    // 0x80019C70: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80019C74: nop

    // 0x80019C78: bne         $t3, $zero, L_80019CAC
    if (ctx->r11 != 0) {
        // 0x80019C7C: nop

            goto L_80019CAC;
    }
    // 0x80019C7C: nop

    // 0x80019C80: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x80019C84: jal         0x800BC6EC
    // 0x80019C88: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x80019C88: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    after_1:
    // 0x80019C8C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80019C90: nop

    // 0x80019C94: sw          $v0, 0x12C($t4)
    MEM_W(0X12C, ctx->r12) = ctx->r2;
    // 0x80019C98: jal         0x800BC6EC
    // 0x80019C9C: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80019C9C: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    after_2:
    // 0x80019CA0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80019CA4: b           L_80019CF0
    // 0x80019CA8: sw          $v0, 0x128($t5)
    MEM_W(0X128, ctx->r13) = ctx->r2;
        goto L_80019CF0;
    // 0x80019CA8: sw          $v0, 0x128($t5)
    MEM_W(0X128, ctx->r13) = ctx->r2;
L_80019CAC:
    // 0x80019CAC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80019CB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80019CB4: bne         $t6, $at, L_80019CE8
    if (ctx->r14 != ctx->r1) {
        // 0x80019CB8: nop

            goto L_80019CE8;
    }
    // 0x80019CB8: nop

    // 0x80019CBC: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x80019CC0: jal         0x800BC918
    // 0x80019CC4: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_3;
    // 0x80019CC4: ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    after_3:
    // 0x80019CC8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80019CCC: nop

    // 0x80019CD0: sw          $v0, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = ctx->r2;
    // 0x80019CD4: jal         0x800BC918
    // 0x80019CD8: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_4;
    // 0x80019CD8: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    after_4:
    // 0x80019CDC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80019CE0: b           L_80019CF0
    // 0x80019CE4: sw          $v0, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r2;
        goto L_80019CF0;
    // 0x80019CE4: sw          $v0, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r2;
L_80019CE8:
    // 0x80019CE8: b           L_80019F3C
    // 0x80019CEC: nop

        goto L_80019F3C;
    // 0x80019CEC: nop

L_80019CF0:
    // 0x80019CF0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80019CF4: nop

    // 0x80019CF8: lw          $t8, 0x12C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X12C);
    // 0x80019CFC: nop

    // 0x80019D00: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80019D04: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80019D08: lui         $a2, 0x2
    ctx->r6 = S32(0X2 << 16);
    // 0x80019D0C: lw          $t2, 0x12C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X12C);
    // 0x80019D10: ori         $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 | 0X7FFF;
    // 0x80019D14: addiu       $a0, $t2, 0x1
    ctx->r4 = ADD32(ctx->r10, 0X1);
    // 0x80019D18: jal         0x800BCFCC
    // 0x80019D1C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x80019D1C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_5:
    // 0x80019D20: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80019D24: nop

    // 0x80019D28: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80019D2C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80019D30: nop

    // 0x80019D34: lw          $t5, 0x12C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X12C);
    // 0x80019D38: nop

    // 0x80019D3C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80019D40: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80019D44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80019D48: sltu        $at, $t6, $at
    ctx->r1 = ctx->r14 < ctx->r1 ? 1 : 0;
    // 0x80019D4C: bne         $at, $zero, L_80019D64
    if (ctx->r1 != 0) {
        // 0x80019D50: nop

            goto L_80019D64;
    }
    // 0x80019D50: nop

    // 0x80019D54: lui         $at, 0x8040
    ctx->r1 = S32(0X8040 << 16);
    // 0x80019D58: sltu        $at, $t6, $at
    ctx->r1 = ctx->r14 < ctx->r1 ? 1 : 0;
    // 0x80019D5C: bne         $at, $zero, L_80019D70
    if (ctx->r1 != 0) {
        // 0x80019D60: nop

            goto L_80019D70;
    }
    // 0x80019D60: nop

L_80019D64:
    // 0x80019D64: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80019D68: nop

    // 0x80019D6C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80019D70:
    // 0x80019D70: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80019D74: nop

    // 0x80019D78: lw          $t0, 0x128($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X128);
    // 0x80019D7C: nop

    // 0x80019D80: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80019D84: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80019D88:
    // 0x80019D88: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80019D8C:
    // 0x80019D8C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80019D90: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80019D94: sll         $t1, $t8, 6
    ctx->r9 = S32(ctx->r24 << 6);
    // 0x80019D98: addiu       $t2, $t1, -0xA0
    ctx->r10 = ADD32(ctx->r9, -0XA0);
    // 0x80019D9C: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x80019DA0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80019DA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80019DA8: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80019DAC: addiu       $t6, $t5, -0x78
    ctx->r14 = ADD32(ctx->r13, -0X78);
    // 0x80019DB0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80019DB4: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80019DB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019DBC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80019DC0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80019DC4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80019DC8: nop

    // 0x80019DCC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80019DD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80019DD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80019DD8: nop

    // 0x80019DDC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80019DE0: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80019DE4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80019DE8: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80019DEC: nop

    // 0x80019DF0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80019DF4: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80019DF8: sh          $t8, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r24;
    // 0x80019DFC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80019E00: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80019E04: sh          $t2, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r10;
    // 0x80019E08: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80019E0C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80019E10: nop

    // 0x80019E14: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
    // 0x80019E18: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80019E1C: nop

    // 0x80019E20: addiu       $t7, $t6, 0xC
    ctx->r15 = ADD32(ctx->r14, 0XC);
    // 0x80019E24: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80019E28: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80019E2C:
    // 0x80019E2C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80019E30: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80019E34: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80019E38: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x80019E3C: slti        $at, $t1, 0xF0
    ctx->r1 = SIGNED(ctx->r9) < 0XF0 ? 1 : 0;
    // 0x80019E40: bne         $at, $zero, L_80019E50
    if (ctx->r1 != 0) {
        // 0x80019E44: nop

            goto L_80019E50;
    }
    // 0x80019E44: nop

    // 0x80019E48: b           L_80019EEC
    // 0x80019E4C: nop

        goto L_80019EEC;
    // 0x80019E4C: nop

L_80019E50:
    // 0x80019E50: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80019E54:
    // 0x80019E54: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80019E58: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80019E5C: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80019E60: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80019E64: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80019E68: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80019E6C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80019E70: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x80019E74: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x80019E78: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80019E7C: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80019E80: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80019E84: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x80019E88: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80019E8C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80019E90: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80019E94: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80019E98: addu        $t3, $t5, $t4
    ctx->r11 = ADD32(ctx->r13, ctx->r12);
    // 0x80019E9C: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x80019EA0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80019EA4: nop

    // 0x80019EA8: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80019EAC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80019EB0: nop

    // 0x80019EB4: addiu       $t8, $t9, 0x2
    ctx->r24 = ADD32(ctx->r25, 0X2);
    // 0x80019EB8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80019EBC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80019EC0: nop

    // 0x80019EC4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80019EC8: slti        $at, $t1, 0x40
    ctx->r1 = SIGNED(ctx->r9) < 0X40 ? 1 : 0;
    // 0x80019ECC: bne         $at, $zero, L_80019E54
    if (ctx->r1 != 0) {
        // 0x80019ED0: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_80019E54;
    }
    // 0x80019ED0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80019ED4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80019ED8: nop

    // 0x80019EDC: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x80019EE0: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x80019EE4: bne         $at, $zero, L_80019E2C
    if (ctx->r1 != 0) {
        // 0x80019EE8: sw          $t5, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r13;
            goto L_80019E2C;
    }
    // 0x80019EE8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
L_80019EEC:
    // 0x80019EEC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80019EF0: nop

    // 0x80019EF4: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80019EF8: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x80019EFC: bne         $at, $zero, L_80019D8C
    if (ctx->r1 != 0) {
        // 0x80019F00: sw          $t3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r11;
            goto L_80019D8C;
    }
    // 0x80019F00: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80019F04: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80019F08: nop

    // 0x80019F0C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80019F10: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80019F14: bne         $at, $zero, L_80019D88
    if (ctx->r1 != 0) {
        // 0x80019F18: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_80019D88;
    }
    // 0x80019F18: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80019F1C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80019F20: addiu       $t9, $zero, -0x8000
    ctx->r25 = ADD32(0, -0X8000);
    // 0x80019F24: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
    // 0x80019F28: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80019F2C: addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // 0x80019F30: sh          $t0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r8;
    // 0x80019F34: b           L_80019F3C
    // 0x80019F38: nop

        goto L_80019F3C;
    // 0x80019F38: nop

L_80019F3C:
    // 0x80019F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019F40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80019F44: jr          $ra
    // 0x80019F48: nop

    return;
    // 0x80019F48: nop

;}
RECOMP_FUNC void func_80019F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019F54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019F58: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80019F5C: nop

    // 0x80019F60: lw          $a0, 0x12C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X12C);
    // 0x80019F64: jal         0x800BCB10
    // 0x80019F68: nop

    func_800BCB10(rdram, ctx);
        goto after_0;
    // 0x80019F68: nop

    after_0:
    // 0x80019F6C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80019F70: nop

    // 0x80019F74: lw          $a0, 0x128($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X128);
    // 0x80019F78: jal         0x800BCB10
    // 0x80019F7C: nop

    func_800BCB10(rdram, ctx);
        goto after_1;
    // 0x80019F7C: nop

    after_1:
    // 0x80019F80: b           L_80019F88
    // 0x80019F84: nop

        goto L_80019F88;
    // 0x80019F84: nop

L_80019F88:
    // 0x80019F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019F90: jr          $ra
    // 0x80019F94: nop

    return;
    // 0x80019F94: nop

    // 0x80019F98: nop

    // 0x80019F9C: nop

;}
RECOMP_FUNC void func_80019FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019FA0: lw          $t6, 0x1A0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1A0);
    // 0x80019FA4: nop

    // 0x80019FA8: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80019FAC: sw          $t7, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->r15;
    // 0x80019FB0: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80019FB4: sw          $zero, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = 0;
    // 0x80019FB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80019FBC: nop

    // 0x80019FC0: swc1        $f4, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = ctx->f4.u32l;
    // 0x80019FC4: lwc1        $f6, 0x1EC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1EC);
    // 0x80019FC8: nop

    // 0x80019FCC: swc1        $f6, 0x1E8($a0)
    MEM_W(0X1E8, ctx->r4) = ctx->f6.u32l;
    // 0x80019FD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80019FD4: nop

    // 0x80019FD8: swc1        $f8, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->f8.u32l;
    // 0x80019FDC: lwc1        $f10, 0x1F4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1F4);
    // 0x80019FE0: nop

    // 0x80019FE4: swc1        $f10, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f10.u32l;
    // 0x80019FE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80019FEC: nop

    // 0x80019FF0: swc1        $f16, 0x1FC($a0)
    MEM_W(0X1FC, ctx->r4) = ctx->f16.u32l;
    // 0x80019FF4: lwc1        $f18, 0x1FC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1FC);
    // 0x80019FF8: nop

    // 0x80019FFC: swc1        $f18, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->f18.u32l;
    // 0x8001A000: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001A004: nop

    // 0x8001A008: swc1        $f4, 0x204($a0)
    MEM_W(0X204, ctx->r4) = ctx->f4.u32l;
    // 0x8001A00C: lwc1        $f6, 0x204($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X204);
    // 0x8001A010: nop

    // 0x8001A014: swc1        $f6, 0x200($a0)
    MEM_W(0X200, ctx->r4) = ctx->f6.u32l;
    // 0x8001A018: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8001A01C: lw          $t8, -0x4538($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4538);
    // 0x8001A020: nop

    // 0x8001A024: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x8001A028: jr          $ra
    // 0x8001A02C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001A02C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A030: jr          $ra
    // 0x8001A034: nop

    return;
    // 0x8001A034: nop

    // 0x8001A038: jr          $ra
    // 0x8001A03C: nop

    return;
    // 0x8001A03C: nop

;}
RECOMP_FUNC void func_8001A040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A040: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001A044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A048: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001A04C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001A050: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001A054: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001A058: jal         0x80016074
    // 0x8001A05C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x8001A05C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x8001A060: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8001A064: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001A068: nop

    // 0x8001A06C: bne         $t6, $zero, L_8001A07C
    if (ctx->r14 != 0) {
        // 0x8001A070: nop

            goto L_8001A07C;
    }
    // 0x8001A070: nop

    // 0x8001A074: b           L_8001A200
    // 0x8001A078: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001A200;
    // 0x8001A078: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001A07C:
    // 0x8001A07C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001A080: nop

    // 0x8001A084: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8001A088: nop

    // 0x8001A08C: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x8001A090: bne         $t9, $zero, L_8001A0A4
    if (ctx->r25 != 0) {
        // 0x8001A094: nop

            goto L_8001A0A4;
    }
    // 0x8001A094: nop

    // 0x8001A098: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001A09C: jal         0x800198F8
    // 0x8001A0A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800198F8(rdram, ctx);
        goto after_1;
    // 0x8001A0A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8001A0A4:
    // 0x8001A0A4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001A0A8: nop

    // 0x8001A0AC: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8001A0B0: nop

    // 0x8001A0B4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8001A0B8: sw          $t2, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r10;
    // 0x8001A0BC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001A0C0: addiu       $at, $zero, -0x7
    ctx->r1 = ADD32(0, -0X7);
    // 0x8001A0C4: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x8001A0C8: nop

    // 0x8001A0CC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8001A0D0: sw          $t5, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = ctx->r13;
    // 0x8001A0D4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A0D8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001A0DC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001A0E0: nop

    // 0x8001A0E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001A0E8: swc1        $f6, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f6.u32l;
    // 0x8001A0EC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A0F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001A0F4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8001A0F8: nop

    // 0x8001A0FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001A100: swc1        $f10, 0x1EC($t9)
    MEM_W(0X1EC, ctx->r25) = ctx->f10.u32l;
    // 0x8001A104: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001A108: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001A10C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001A110: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8001A114: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8001A118: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8001A11C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8001A120: addiu       $t0, $t0, 0x61D8
    ctx->r8 = ADD32(ctx->r8, 0X61D8);
    // 0x8001A124: addu        $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
    // 0x8001A128: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8001A12C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A130: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001A134: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8001A138: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x8001A13C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8001A140: subu        $t3, $t3, $t5
    ctx->r11 = SUB32(ctx->r11, ctx->r13);
    // 0x8001A144: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8001A148: addiu       $t6, $t6, 0x61D8
    ctx->r14 = ADD32(ctx->r14, 0X61D8);
    // 0x8001A14C: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8001A150: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001A154: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001A158: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001A15C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001A160: nop

    // 0x8001A164: swc1        $f16, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f16.u32l;
    // 0x8001A168: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001A16C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A170: nop

    // 0x8001A174: swc1        $f18, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f18.u32l;
    // 0x8001A178: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001A17C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8001A180: nop

    // 0x8001A184: swc1        $f4, 0x1F0($t1)
    MEM_W(0X1F0, ctx->r9) = ctx->f4.u32l;
    // 0x8001A188: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001A18C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8001A190: nop

    // 0x8001A194: swc1        $f6, 0x1F4($t2)
    MEM_W(0X1F4, ctx->r10) = ctx->f6.u32l;
    // 0x8001A198: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001A19C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001A1A0: nop

    // 0x8001A1A4: swc1        $f8, 0x1F8($t0)
    MEM_W(0X1F8, ctx->r8) = ctx->f8.u32l;
    // 0x8001A1A8: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x8001A1AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001A1B0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001A1B4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8001A1B8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001A1BC: swc1        $f18, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f18.u32l;
    // 0x8001A1C0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001A1C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001A1C8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001A1CC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A1D0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001A1D4: swc1        $f8, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f8.u32l;
    // 0x8001A1D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001A1DC: jal         0x800AD774
    // 0x8001A1E0: nop

    func_800AD774(rdram, ctx);
        goto after_2;
    // 0x8001A1E0: nop

    after_2:
    // 0x8001A1E4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001A1E8: nop

    // 0x8001A1EC: sh          $v0, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r2;
    // 0x8001A1F0: b           L_8001A200
    // 0x8001A1F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001A200;
    // 0x8001A1F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A1F8: b           L_8001A200
    // 0x8001A1FC: nop

        goto L_8001A200;
    // 0x8001A1FC: nop

L_8001A200:
    // 0x8001A200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001A208: jr          $ra
    // 0x8001A20C: nop

    return;
    // 0x8001A20C: nop

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
RECOMP_FUNC void func_8001A690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A690: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001A694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A698: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001A69C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001A6A0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8001A6A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6A8: nop

    // 0x8001A6AC: sw          $zero, 0x1A8($t6)
    MEM_W(0X1A8, ctx->r14) = 0;
    // 0x8001A6B0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6B4: nop

    // 0x8001A6B8: sw          $zero, 0x1AC($t7)
    MEM_W(0X1AC, ctx->r15) = 0;
    // 0x8001A6BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001A6C0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6C4: nop

    // 0x8001A6C8: swc1        $f4, 0x1EC($t8)
    MEM_W(0X1EC, ctx->r24) = ctx->f4.u32l;
    // 0x8001A6CC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6D0: nop

    // 0x8001A6D4: lwc1        $f6, 0x1EC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1EC);
    // 0x8001A6D8: nop

    // 0x8001A6DC: swc1        $f6, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f6.u32l;
    // 0x8001A6E0: jal         0x800BC6EC
    // 0x8001A6E4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8001A6E4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x8001A6E8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6EC: nop

    // 0x8001A6F0: sw          $v0, 0x20C($t0)
    MEM_W(0X20C, ctx->r8) = ctx->r2;
    // 0x8001A6F4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8001A6F8: nop

    // 0x8001A6FC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8001A700: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001A704: jal         0x80099E2C
    // 0x8001A708: nop

    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x8001A708: nop

    after_1:
    // 0x8001A70C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001A710: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A714: nop

    // 0x8001A718: swc1        $f8, 0xD4($t2)
    MEM_W(0XD4, ctx->r10) = ctx->f8.u32l;
    // 0x8001A71C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8001A720: nop

    // 0x8001A724: lwc1        $f20, 0xD4($t3)
    ctx->f20.u32l = MEM_W(ctx->r11, 0XD4);
    // 0x8001A728: nop

    // 0x8001A72C: swc1        $f20, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f20.u32l;
    // 0x8001A730: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001A734: nop

    // 0x8001A738: swc1        $f20, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f20.u32l;
    // 0x8001A73C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001A740: nop

    // 0x8001A744: sw          $zero, 0x108($t5)
    MEM_W(0X108, ctx->r13) = 0;
    // 0x8001A748: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A74C: nop

    // 0x8001A750: lw          $t7, 0x108($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X108);
    // 0x8001A754: nop

    // 0x8001A758: sw          $t7, 0x104($t6)
    MEM_W(0X104, ctx->r14) = ctx->r15;
    // 0x8001A75C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001A760: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A764: nop

    // 0x8001A768: swc1        $f10, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f10.u32l;
    // 0x8001A76C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001A770: nop

    // 0x8001A774: lwc1        $f20, 0xF0($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x8001A778: nop

    // 0x8001A77C: swc1        $f20, 0xEC($t9)
    MEM_W(0XEC, ctx->r25) = ctx->f20.u32l;
    // 0x8001A780: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001A784: nop

    // 0x8001A788: swc1        $f20, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f20.u32l;
    // 0x8001A78C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A790: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001A794: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001A798: nop

    // 0x8001A79C: swc1        $f16, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f16.u32l;
    // 0x8001A7A0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7A4: nop

    // 0x8001A7A8: lwc1        $f18, 0xF8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XF8);
    // 0x8001A7AC: nop

    // 0x8001A7B0: swc1        $f18, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f18.u32l;
    // 0x8001A7B4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7B8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8001A7BC: sh          $t3, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r11;
    // 0x8001A7C0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001A7C8: sh          $t5, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r13;
    // 0x8001A7CC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7D0: lui         $t6, 0x7FFF
    ctx->r14 = S32(0X7FFF << 16);
    // 0x8001A7D4: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x8001A7D8: sw          $t6, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r14;
    // 0x8001A7DC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7E0: addiu       $t9, $zero, 0x84C
    ctx->r25 = ADD32(0, 0X84C);
    // 0x8001A7E4: sw          $t9, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r25;
    // 0x8001A7E8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7EC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8001A7F0: sh          $t1, 0x114($t2)
    MEM_H(0X114, ctx->r10) = ctx->r9;
    // 0x8001A7F4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001A7F8: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8001A7FC: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001A800: nop

    // 0x8001A804: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x8001A808: beq         $t5, $zero, L_8001A8E4
    if (ctx->r13 == 0) {
        // 0x8001A80C: nop

            goto L_8001A8E4;
    }
    // 0x8001A80C: nop

    // 0x8001A810: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8001A814: nop

    // 0x8001A818: lw          $t6, 0x1A8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X1A8);
    // 0x8001A81C: nop

    // 0x8001A820: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x8001A824: sw          $t8, 0x1A8($t7)
    MEM_W(0X1A8, ctx->r15) = ctx->r24;
    // 0x8001A828: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001A82C: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x8001A830: sh          $t9, 0x100($t0)
    MEM_H(0X100, ctx->r8) = ctx->r25;
    // 0x8001A834: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A838: addiu       $t1, $zero, 0xE0
    ctx->r9 = ADD32(0, 0XE0);
    // 0x8001A83C: sh          $t1, 0x102($t2)
    MEM_H(0X102, ctx->r10) = ctx->r9;
    // 0x8001A840: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8001A844: nop

    // 0x8001A848: lh          $t4, 0x100($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X100);
    // 0x8001A84C: lh          $t5, 0x102($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X102);
    // 0x8001A850: nop

    // 0x8001A854: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A858: mflo        $a0
    ctx->r4 = lo;
    // 0x8001A85C: jal         0x800BC6EC
    // 0x8001A860: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8001A860: nop

    after_2:
    // 0x8001A864: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A868: nop

    // 0x8001A86C: sw          $v0, 0x128($t6)
    MEM_W(0X128, ctx->r14) = ctx->r2;
    // 0x8001A870: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A874: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8001A878: lh          $t9, 0x102($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X102);
    // 0x8001A87C: lh          $t7, 0x100($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X100);
    // 0x8001A880: nop

    // 0x8001A884: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A888: mflo        $t0
    ctx->r8 = lo;
    // 0x8001A88C: blez        $t0, L_8001A8DC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001A890: nop

            goto L_8001A8DC;
    }
    // 0x8001A890: nop

L_8001A894:
    // 0x8001A894: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001A898: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A89C: lw          $t2, 0x128($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X128);
    // 0x8001A8A0: nop

    // 0x8001A8A4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A8A8: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x8001A8AC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A8B0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A8B4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001A8B8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8001A8BC: lh          $t9, 0x102($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X102);
    // 0x8001A8C0: lh          $t7, 0x100($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X100);
    // 0x8001A8C4: nop

    // 0x8001A8C8: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A8CC: mflo        $t0
    ctx->r8 = lo;
    // 0x8001A8D0: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001A8D4: bne         $at, $zero, L_8001A894
    if (ctx->r1 != 0) {
        // 0x8001A8D8: nop

            goto L_8001A894;
    }
    // 0x8001A8D8: nop

L_8001A8DC:
    // 0x8001A8DC: b           L_8001AA28
    // 0x8001A8E0: nop

        goto L_8001AA28;
    // 0x8001A8E0: nop

L_8001A8E4:
    // 0x8001A8E4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001A8E8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8001A8EC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8001A8F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001A8F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001A8F8: lwc1        $f4, 0x1B0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X1B0);
    // 0x8001A8FC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001A900: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001A904: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8001A908: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001A90C: sh          $t3, 0x100($t4)
    MEM_H(0X100, ctx->r12) = ctx->r11;
    // 0x8001A910: nop

    // 0x8001A914: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001A918: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8001A91C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001A920: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001A924: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001A928: lwc1        $f8, 0x1B4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1B4);
    // 0x8001A92C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001A930: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001A934: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8001A938: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001A93C: sh          $t7, 0x102($t9)
    MEM_H(0X102, ctx->r25) = ctx->r15;
    // 0x8001A940: nop

    // 0x8001A944: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001A948: nop

    // 0x8001A94C: lh          $t0, 0x100($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X100);
    // 0x8001A950: lh          $t1, 0x102($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X102);
    // 0x8001A954: nop

    // 0x8001A958: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A95C: mflo        $a0
    ctx->r4 = lo;
    // 0x8001A960: jal         0x800BC6EC
    // 0x8001A964: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x8001A964: nop

    after_3:
    // 0x8001A968: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001A96C: nop

    // 0x8001A970: sw          $v0, 0x12C($t2)
    MEM_W(0X12C, ctx->r10) = ctx->r2;
    // 0x8001A974: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8001A978: nop

    // 0x8001A97C: lh          $t4, 0x100($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X100);
    // 0x8001A980: lh          $t5, 0x102($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X102);
    // 0x8001A984: nop

    // 0x8001A988: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A98C: mflo        $a0
    ctx->r4 = lo;
    // 0x8001A990: jal         0x800BC6EC
    // 0x8001A994: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8001A994: nop

    after_4:
    // 0x8001A998: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001A99C: nop

    // 0x8001A9A0: sw          $v0, 0x130($t8)
    MEM_W(0X130, ctx->r24) = ctx->r2;
    // 0x8001A9A4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001A9A8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8001A9AC: lh          $t6, 0x102($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X102);
    // 0x8001A9B0: lh          $t9, 0x100($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X100);
    // 0x8001A9B4: nop

    // 0x8001A9B8: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A9BC: mflo        $t0
    ctx->r8 = lo;
    // 0x8001A9C0: blez        $t0, L_8001AA28
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001A9C4: nop

            goto L_8001AA28;
    }
    // 0x8001A9C4: nop

L_8001A9C8:
    // 0x8001A9C8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001A9CC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A9D0: lw          $t2, 0x12C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X12C);
    // 0x8001A9D4: nop

    // 0x8001A9D8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8001A9DC: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x8001A9E0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001A9E4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A9E8: lw          $t8, 0x130($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X130);
    // 0x8001A9EC: nop

    // 0x8001A9F0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8001A9F4: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8001A9F8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A9FC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA00: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8001AA04: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8001AA08: lh          $t3, 0x102($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X102);
    // 0x8001AA0C: lh          $t2, 0x100($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X100);
    // 0x8001AA10: nop

    // 0x8001AA14: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AA18: mflo        $t4
    ctx->r12 = lo;
    // 0x8001AA1C: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001AA20: bne         $at, $zero, L_8001A9C8
    if (ctx->r1 != 0) {
        // 0x8001AA24: nop

            goto L_8001A9C8;
    }
    // 0x8001AA24: nop

L_8001AA28:
    // 0x8001AA28: jal         0x800BC6EC
    // 0x8001AA2C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x8001AA2C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_5:
    // 0x8001AA30: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA34: nop

    // 0x8001AA38: sw          $v0, 0x138($t5)
    MEM_W(0X138, ctx->r13) = ctx->r2;
    // 0x8001AA3C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA40: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8001AA44: lw          $a0, 0x138($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X138);
    // 0x8001AA48: jal         0x80090A38
    // 0x8001AA4C: nop

    func_80090A38(rdram, ctx);
        goto after_6;
    // 0x8001AA4C: nop

    after_6:
    // 0x8001AA50: jal         0x80096474
    // 0x8001AA54: nop

    func_80096474(rdram, ctx);
        goto after_7;
    // 0x8001AA54: nop

    after_7:
    // 0x8001AA58: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA5C: nop

    // 0x8001AA60: lw          $a0, 0x128($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X128);
    // 0x8001AA64: jal         0x8008ECCC
    // 0x8001AA68: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_8;
    // 0x8001AA68: nop

    after_8:
    // 0x8001AA6C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA70: nop

    // 0x8001AA74: lh          $t6, 0x100($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X100);
    // 0x8001AA78: lh          $t1, 0x102($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X102);
    // 0x8001AA7C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8001AA80: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8001AA84: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001AA88: jal         0x8008EC8C
    // 0x8001AA8C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_8008EC8C(rdram, ctx);
        goto after_9;
    // 0x8001AA8C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_9:
    // 0x8001AA90: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001AA94: nop

    // 0x8001AA98: lh          $t3, 0x100($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X100);
    // 0x8001AA9C: lh          $t0, 0x102($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X102);
    // 0x8001AAA0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8001AAA4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8001AAA8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001AAAC: jal         0x8008ECAC
    // 0x8001AAB0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_8008ECAC(rdram, ctx);
        goto after_10;
    // 0x8001AAB0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_10:
    // 0x8001AAB4: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8001AAB8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8001AABC: sw          $t4, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r12;
    // 0x8001AAC0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8001AAC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8001AAC8: sw          $t5, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r13;
    // 0x8001AACC: jal         0x80090754
    // 0x8001AAD0: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    func_80090754(rdram, ctx);
        goto after_11;
    // 0x8001AAD0: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    after_11:
    // 0x8001AAD4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8001AAD8: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x8001AADC: lhu         $t7, 0x0($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X0);
    // 0x8001AAE0: nop

    // 0x8001AAE4: andi        $t6, $t7, 0x800
    ctx->r14 = ctx->r15 & 0X800;
    // 0x8001AAE8: beq         $t6, $zero, L_8001AB00
    if (ctx->r14 == 0) {
        // 0x8001AAEC: nop

            goto L_8001AB00;
    }
    // 0x8001AAEC: nop

    // 0x8001AAF0: jal         0x80090728
    // 0x8001AAF4: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    func_80090728(rdram, ctx);
        goto after_12;
    // 0x8001AAF4: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    after_12:
    // 0x8001AAF8: b           L_8001AB08
    // 0x8001AAFC: nop

        goto L_8001AB08;
    // 0x8001AAFC: nop

L_8001AB00:
    // 0x8001AB00: jal         0x80090728
    // 0x8001AB04: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80090728(rdram, ctx);
        goto after_13;
    // 0x8001AB04: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_13:
L_8001AB08:
    // 0x8001AB08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AB0C: jal         0x8008EAA8
    // 0x8001AB10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_14;
    // 0x8001AB10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8001AB14: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8001AB18: nop

    // 0x8001AB1C: lw          $a0, 0x20C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20C);
    // 0x8001AB20: jal         0x80096374
    // 0x8001AB24: nop

    func_80096374(rdram, ctx);
        goto after_15;
    // 0x8001AB24: nop

    after_15:
    // 0x8001AB28: jal         0x800967D8
    // 0x8001AB2C: nop

    func_800967D8(rdram, ctx);
        goto after_16;
    // 0x8001AB2C: nop

    after_16:
    // 0x8001AB30: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001AB34: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8001AB38: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8001AB3C: nop

    // 0x8001AB40: andi        $t2, $t3, 0x800
    ctx->r10 = ctx->r11 & 0X800;
    // 0x8001AB44: beq         $t2, $zero, L_8001AB60
    if (ctx->r10 == 0) {
        // 0x8001AB48: nop

            goto L_8001AB60;
    }
    // 0x8001AB48: nop

    // 0x8001AB4C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8001AB50: lw          $t4, -0x4538($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4538);
    // 0x8001AB54: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001AB58: nop

    // 0x8001AB5C: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
L_8001AB60:
    // 0x8001AB60: b           L_8001AB70
    // 0x8001AB64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AB70;
    // 0x8001AB64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AB68: b           L_8001AB70
    // 0x8001AB6C: nop

        goto L_8001AB70;
    // 0x8001AB6C: nop

L_8001AB70:
    // 0x8001AB70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AB74: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001AB78: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001AB7C: jr          $ra
    // 0x8001AB80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001AB80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001AB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AB84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001AB88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AB8C: jal         0x80016074
    // 0x8001AB90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x8001AB90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001AB94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001AB98: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AB9C: nop

    // 0x8001ABA0: bne         $t6, $zero, L_8001ABB0
    if (ctx->r14 != 0) {
        // 0x8001ABA4: nop

            goto L_8001ABB0;
    }
    // 0x8001ABA4: nop

    // 0x8001ABA8: b           L_8001ABDC
    // 0x8001ABAC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001ABDC;
    // 0x8001ABAC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001ABB0:
    // 0x8001ABB0: jal         0x80096474
    // 0x8001ABB4: nop

    func_80096474(rdram, ctx);
        goto after_1;
    // 0x8001ABB4: nop

    after_1:
    // 0x8001ABB8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ABBC: nop

    // 0x8001ABC0: lw          $a0, 0x20C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X20C);
    // 0x8001ABC4: jal         0x800962B0
    // 0x8001ABC8: nop

    func_800962B0(rdram, ctx);
        goto after_2;
    // 0x8001ABC8: nop

    after_2:
    // 0x8001ABCC: b           L_8001ABDC
    // 0x8001ABD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001ABDC;
    // 0x8001ABD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001ABD4: b           L_8001ABDC
    // 0x8001ABD8: nop

        goto L_8001ABDC;
    // 0x8001ABD8: nop

L_8001ABDC:
    // 0x8001ABDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ABE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001ABE4: jr          $ra
    // 0x8001ABE8: nop

    return;
    // 0x8001ABE8: nop

;}
RECOMP_FUNC void func_8001ABEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ABEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001ABF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ABF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001ABF8: jal         0x80096474
    // 0x8001ABFC: nop

    func_80096474(rdram, ctx);
        goto after_0;
    // 0x8001ABFC: nop

    after_0:
    // 0x8001AC00: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001AC04: nop

    // 0x8001AC08: lw          $a0, 0x20C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X20C);
    // 0x8001AC0C: jal         0x800962B0
    // 0x8001AC10: nop

    func_800962B0(rdram, ctx);
        goto after_1;
    // 0x8001AC10: nop

    after_1:
    // 0x8001AC14: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001AC18: lhu         $t8, 0x24FC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X24FC);
    // 0x8001AC1C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8001AC20: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001AC24: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8001AC28: lw          $a0, 0x12C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X12C);
    // 0x8001AC2C: jal         0x8008ECCC
    // 0x8001AC30: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_2;
    // 0x8001AC30: nop

    after_2:
    // 0x8001AC34: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001AC38: lhu         $t2, 0x24FC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X24FC);
    // 0x8001AC3C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8001AC40: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001AC44: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8001AC48: lw          $t5, 0x12C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X12C);
    // 0x8001AC4C: nop

    // 0x8001AC50: sw          $t5, 0x128($t1)
    MEM_W(0X128, ctx->r9) = ctx->r13;
    // 0x8001AC54: b           L_8001AC64
    // 0x8001AC58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AC64;
    // 0x8001AC58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AC5C: b           L_8001AC64
    // 0x8001AC60: nop

        goto L_8001AC64;
    // 0x8001AC60: nop

L_8001AC64:
    // 0x8001AC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001AC6C: jr          $ra
    // 0x8001AC70: nop

    return;
    // 0x8001AC70: nop

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
RECOMP_FUNC void func_8001AD24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AD24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001AD28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AD2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001AD30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001AD34: jal         0x80016074
    // 0x8001AD38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x8001AD38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001AD3C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001AD40: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AD44: nop

    // 0x8001AD48: bne         $t6, $zero, L_8001AD58
    if (ctx->r14 != 0) {
        // 0x8001AD4C: nop

            goto L_8001AD58;
    }
    // 0x8001AD4C: nop

    // 0x8001AD50: b           L_8001AD88
    // 0x8001AD54: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001AD88;
    // 0x8001AD54: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001AD58:
    // 0x8001AD58: lhu         $t7, 0x22($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X22);
    // 0x8001AD5C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AD60: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8001AD64: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x8001AD68: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001AD6C: sra         $t9, $t7, 15
    ctx->r25 = S32(SIGNED(ctx->r15) >> 15);
    // 0x8001AD70: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8001AD74: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x8001AD78: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8001AD7C: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
    // 0x8001AD80: b           L_8001AD88
    // 0x8001AD84: nop

        goto L_8001AD88;
    // 0x8001AD84: nop

L_8001AD88:
    // 0x8001AD88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AD8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001AD90: jr          $ra
    // 0x8001AD94: nop

    return;
    // 0x8001AD94: nop

;}
RECOMP_FUNC void func_8001AD98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AD98: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8001AD9C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8001ADA0: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x8001ADA4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001ADA8: sh          $a1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r5;
    // 0x8001ADAC: jr          $ra
    // 0x8001ADB0: nop

    return;
    // 0x8001ADB0: nop

    // 0x8001ADB4: jr          $ra
    // 0x8001ADB8: nop

    return;
    // 0x8001ADB8: nop

;}
RECOMP_FUNC void func_8001ADBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ADBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001ADC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ADC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001ADC8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001ADCC: nop

    // 0x8001ADD0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8001ADD4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8001ADD8: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8001ADDC: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8001ADE0: nop

    // 0x8001ADE4: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8001ADE8: bne         $t9, $zero, L_8001AE0C
    if (ctx->r25 != 0) {
        // 0x8001ADEC: nop

            goto L_8001AE0C;
    }
    // 0x8001ADEC: nop

    // 0x8001ADF0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001ADF4: nop

    // 0x8001ADF8: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8001ADFC: nop

    // 0x8001AE00: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8001AE04: bne         $t2, $zero, L_8001AE70
    if (ctx->r10 != 0) {
        // 0x8001AE08: nop

            goto L_8001AE70;
    }
    // 0x8001AE08: nop

L_8001AE0C:
    // 0x8001AE0C: jal         0x800C1754
    // 0x8001AE10: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8001AE10: nop

    after_0:
    // 0x8001AE14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE18: jal         0x8009A14C
    // 0x8001AE1C: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x8001AE1C: nop

    after_1:
    // 0x8001AE20: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE24: nop

    // 0x8001AE28: lwc1        $f12, 0xF0($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XF0);
    // 0x8001AE2C: jal         0x800C2780
    // 0x8001AE30: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8001AE30: nop

    after_2:
    // 0x8001AE34: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE38: nop

    // 0x8001AE3C: lwc1        $f12, 0xEC($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XEC);
    // 0x8001AE40: jal         0x800C25B8
    // 0x8001AE44: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8001AE44: nop

    after_3:
    // 0x8001AE48: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE4C: nop

    // 0x8001AE50: lwc1        $f12, 0xE8($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XE8);
    // 0x8001AE54: jal         0x800C23E8
    // 0x8001AE58: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8001AE58: nop

    after_4:
    // 0x8001AE5C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE60: jal         0x800997D8
    // 0x8001AE64: nop

    func_800997D8(rdram, ctx);
        goto after_5;
    // 0x8001AE64: nop

    after_5:
    // 0x8001AE68: jal         0x800C1A28
    // 0x8001AE6C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x8001AE6C: nop

    after_6:
L_8001AE70:
    // 0x8001AE70: b           L_8001AE80
    // 0x8001AE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AE80;
    // 0x8001AE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AE78: b           L_8001AE80
    // 0x8001AE7C: nop

        goto L_8001AE80;
    // 0x8001AE7C: nop

L_8001AE80:
    // 0x8001AE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AE84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001AE88: jr          $ra
    // 0x8001AE8C: nop

    return;
    // 0x8001AE8C: nop

;}
RECOMP_FUNC void func_8001AE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001AE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AE98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001AE9C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001AEA0: nop

    // 0x8001AEA4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8001AEA8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8001AEAC: nop

    // 0x8001AEB0: lw          $t8, 0x20C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20C);
    // 0x8001AEB4: nop

    // 0x8001AEB8: beq         $t8, $zero, L_8001AEE0
    if (ctx->r24 == 0) {
        // 0x8001AEBC: nop

            goto L_8001AEE0;
    }
    // 0x8001AEBC: nop

    // 0x8001AEC0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8001AEC4: nop

    // 0x8001AEC8: lw          $a0, 0x20C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20C);
    // 0x8001AECC: jal         0x800BC980
    // 0x8001AED0: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x8001AED0: nop

    after_0:
    // 0x8001AED4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001AED8: nop

    // 0x8001AEDC: sw          $zero, 0x20C($t0)
    MEM_W(0X20C, ctx->r8) = 0;
L_8001AEE0:
    // 0x8001AEE0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AEE4: nop

    // 0x8001AEE8: lw          $t2, 0x12C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X12C);
    // 0x8001AEEC: nop

    // 0x8001AEF0: beq         $t2, $zero, L_8001AF18
    if (ctx->r10 == 0) {
        // 0x8001AEF4: nop

            goto L_8001AF18;
    }
    // 0x8001AEF4: nop

    // 0x8001AEF8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AEFC: nop

    // 0x8001AF00: lw          $a0, 0x12C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X12C);
    // 0x8001AF04: jal         0x800BC980
    // 0x8001AF08: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x8001AF08: nop

    after_1:
    // 0x8001AF0C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF10: nop

    // 0x8001AF14: sw          $zero, 0x12C($t4)
    MEM_W(0X12C, ctx->r12) = 0;
L_8001AF18:
    // 0x8001AF18: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF1C: nop

    // 0x8001AF20: lw          $t6, 0x130($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X130);
    // 0x8001AF24: nop

    // 0x8001AF28: beq         $t6, $zero, L_8001AF50
    if (ctx->r14 == 0) {
        // 0x8001AF2C: nop

            goto L_8001AF50;
    }
    // 0x8001AF2C: nop

    // 0x8001AF30: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF34: nop

    // 0x8001AF38: lw          $a0, 0x130($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X130);
    // 0x8001AF3C: jal         0x800BC980
    // 0x8001AF40: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x8001AF40: nop

    after_2:
    // 0x8001AF44: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF48: nop

    // 0x8001AF4C: sw          $zero, 0x130($t8)
    MEM_W(0X130, ctx->r24) = 0;
L_8001AF50:
    // 0x8001AF50: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF54: nop

    // 0x8001AF58: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x8001AF5C: nop

    // 0x8001AF60: beq         $t0, $zero, L_8001AF88
    if (ctx->r8 == 0) {
        // 0x8001AF64: nop

            goto L_8001AF88;
    }
    // 0x8001AF64: nop

    // 0x8001AF68: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF6C: nop

    // 0x8001AF70: lw          $a0, 0x138($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X138);
    // 0x8001AF74: jal         0x800BC980
    // 0x8001AF78: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x8001AF78: nop

    after_3:
    // 0x8001AF7C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF80: nop

    // 0x8001AF84: sw          $zero, 0x138($t2)
    MEM_W(0X138, ctx->r10) = 0;
L_8001AF88:
    // 0x8001AF88: b           L_8001AF90
    // 0x8001AF8C: nop

        goto L_8001AF90;
    // 0x8001AF8C: nop

L_8001AF90:
    // 0x8001AF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001AF98: jr          $ra
    // 0x8001AF9C: nop

    return;
    // 0x8001AF9C: nop

;}
RECOMP_FUNC void func_8001AFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AFA0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8001AFA4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001AFA8: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x8001AFAC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001AFB0: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001AFB4: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8001AFB8: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8001AFBC: nop

    // 0x8001AFC0: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8001AFC4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8001AFC8: nop

    // 0x8001AFCC: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8001AFD0: nop

    // 0x8001AFD4: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8001AFD8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001AFDC: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8001AFE0: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8001AFE4: nop

    // 0x8001AFE8: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x8001AFEC: beq         $t1, $zero, L_8001B08C
    if (ctx->r9 == 0) {
        // 0x8001AFF0: nop

            goto L_8001B08C;
    }
    // 0x8001AFF0: nop

    // 0x8001AFF4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8001AFF8: addiu       $t2, $t2, 0x7340
    ctx->r10 = ADD32(ctx->r10, 0X7340);
    // 0x8001AFFC: addiu       $t3, $t2, 0x1080
    ctx->r11 = ADD32(ctx->r10, 0X1080);
    // 0x8001B000: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x8001B004: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B00C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001B010: nop

    // 0x8001B014: swc1        $f4, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f4.u32l;
    // 0x8001B018: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001B01C: nop

    // 0x8001B020: lwc1        $f6, 0xF8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x8001B024: nop

    // 0x8001B028: swc1        $f6, 0xF4($t5)
    MEM_W(0XF4, ctx->r13) = ctx->f6.u32l;
    // 0x8001B02C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001B030: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001B034: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8001B038: nop

    // 0x8001B03C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8001B040: sw          $t8, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r24;
    // 0x8001B044: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001B048: nop

    // 0x8001B04C: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x8001B050: nop

    // 0x8001B054: ori         $t1, $t0, 0x810
    ctx->r9 = ctx->r8 | 0X810;
    // 0x8001B058: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
    // 0x8001B05C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001B060: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001B064: nop

    // 0x8001B068: swc1        $f8, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f8.u32l;
    // 0x8001B06C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001B070: nop

    // 0x8001B074: lwc1        $f20, 0xF0($t3)
    ctx->f20.u32l = MEM_W(ctx->r11, 0XF0);
    // 0x8001B078: nop

    // 0x8001B07C: swc1        $f20, 0xEC($t3)
    MEM_W(0XEC, ctx->r11) = ctx->f20.u32l;
    // 0x8001B080: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001B084: nop

    // 0x8001B088: swc1        $f20, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f20.u32l;
L_8001B08C:
    // 0x8001B08C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
    // 0x8001B090: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001B094: nop

    // 0x8001B098: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x8001B09C: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
L_8001B0A0:
    // 0x8001B0A0: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8001B0A4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8001B0A8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8001B0AC: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8001B0B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001B0B4: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8001B0B8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8001B0BC: addiu       $t8, $t8, -0x5980
    ctx->r24 = ADD32(ctx->r24, -0X5980);
    // 0x8001B0C0: jal         0x80099E2C
    // 0x8001B0C4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x8001B0C4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8001B0C8: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8001B0CC: nop

    // 0x8001B0D0: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8001B0D4: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x8001B0D8: bne         $at, $zero, L_8001B0A0
    if (ctx->r1 != 0) {
        // 0x8001B0DC: sw          $t0, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r8;
            goto L_8001B0A0;
    }
    // 0x8001B0DC: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x8001B0E0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001B0E4: addiu       $a1, $a1, -0x5980
    ctx->r5 = ADD32(ctx->r5, -0X5980);
    // 0x8001B0E8: jal         0x800A6670
    // 0x8001B0EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_1;
    // 0x8001B0EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8001B0F0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001B0F4: addiu       $a1, $a1, -0x5980
    ctx->r5 = ADD32(ctx->r5, -0X5980);
    // 0x8001B0F8: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8001B0FC: jal         0x800A6670
    // 0x8001B100: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_2;
    // 0x8001B100: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x8001B104: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001B108: addiu       $t1, $t1, -0x4E80
    ctx->r9 = ADD32(ctx->r9, -0X4E80);
    // 0x8001B10C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8001B110: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B114: jal         0x80099E2C
    // 0x8001B118: nop

    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x8001B118: nop

    after_3:
    // 0x8001B11C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001B120: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B124: swc1        $f16, -0x4DAC($at)
    MEM_W(-0X4DAC, ctx->r1) = ctx->f16.u32l;
    // 0x8001B128: swc1        $f16, -0x4DB0($at)
    MEM_W(-0X4DB0, ctx->r1) = ctx->f16.u32l;
    // 0x8001B12C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B130: swc1        $f16, -0x4DB4($at)
    MEM_W(-0X4DB4, ctx->r1) = ctx->f16.u32l;
    // 0x8001B134: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B138: sw          $zero, -0x4D78($at)
    MEM_W(-0X4D78, ctx->r1) = 0;
    // 0x8001B13C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B140: sw          $zero, -0x4D7C($at)
    MEM_W(-0X4D7C, ctx->r1) = 0;
    // 0x8001B144: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001B148: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B14C: swc1        $f18, -0x4D90($at)
    MEM_W(-0X4D90, ctx->r1) = ctx->f18.u32l;
    // 0x8001B150: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B154: swc1        $f18, -0x4D94($at)
    MEM_W(-0X4D94, ctx->r1) = ctx->f18.u32l;
    // 0x8001B158: swc1        $f18, -0x4D98($at)
    MEM_W(-0X4D98, ctx->r1) = ctx->f18.u32l;
    // 0x8001B15C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B160: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B164: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B168: swc1        $f4, -0x4D88($at)
    MEM_W(-0X4D88, ctx->r1) = ctx->f4.u32l;
    // 0x8001B16C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B170: swc1        $f4, -0x4D8C($at)
    MEM_W(-0X4D8C, ctx->r1) = ctx->f4.u32l;
    // 0x8001B174: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8001B178: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B17C: sh          $t9, -0x4D62($at)
    MEM_H(-0X4D62, ctx->r1) = ctx->r25;
    // 0x8001B180: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001B184: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B188: sh          $t2, -0x4D6A($at)
    MEM_H(-0X4D6A, ctx->r1) = ctx->r10;
    // 0x8001B18C: addiu       $t3, $zero, 0x854
    ctx->r11 = ADD32(0, 0X854);
    // 0x8001B190: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B194: sw          $t3, -0x4DC0($at)
    MEM_W(-0X4DC0, ctx->r1) = ctx->r11;
    // 0x8001B198: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001B19C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1A0: sh          $t4, -0x4D6C($at)
    MEM_H(-0X4D6C, ctx->r1) = ctx->r12;
    // 0x8001B1A4: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    // 0x8001B1A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1AC: sh          $t5, -0x4D80($at)
    MEM_H(-0X4D80, ctx->r1) = ctx->r13;
    // 0x8001B1B0: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x8001B1B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1B8: sh          $t7, -0x4D7E($at)
    MEM_H(-0X4D7E, ctx->r1) = ctx->r15;
    // 0x8001B1BC: jal         0x800BC6EC
    // 0x8001B1C0: ori         $a0, $zero, 0xF000
    ctx->r4 = 0 | 0XF000;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8001B1C0: ori         $a0, $zero, 0xF000
    ctx->r4 = 0 | 0XF000;
    after_4:
    // 0x8001B1C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1C8: sw          $v0, -0x4D44($at)
    MEM_W(-0X4D44, ctx->r1) = ctx->r2;
    // 0x8001B1CC: jal         0x800BC6EC
    // 0x8001B1D0: ori         $a0, $zero, 0xF000
    ctx->r4 = 0 | 0XF000;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x8001B1D0: ori         $a0, $zero, 0xF000
    ctx->r4 = 0 | 0XF000;
    after_5:
    // 0x8001B1D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1D8: sw          $v0, -0x4D40($at)
    MEM_W(-0X4D40, ctx->r1) = ctx->r2;
    // 0x8001B1DC: jal         0x800BC6EC
    // 0x8001B1E0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_6;
    // 0x8001B1E0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_6:
    // 0x8001B1E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B1E8: sw          $v0, -0x4D48($at)
    MEM_W(-0X4D48, ctx->r1) = ctx->r2;
    // 0x8001B1EC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001B1F0: lw          $a0, -0x4D48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D48);
    // 0x8001B1F4: jal         0x80090A38
    // 0x8001B1F8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    func_80090A38(rdram, ctx);
        goto after_7;
    // 0x8001B1F8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_7:
    // 0x8001B1FC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8001B200: addiu       $t8, $t8, -0x44B8
    ctx->r24 = ADD32(ctx->r24, -0X44B8);
    // 0x8001B204: lhu         $t6, 0x0($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X0);
    // 0x8001B208: nop

    // 0x8001B20C: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
    // 0x8001B210: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8001B214: addiu       $t1, $t1, -0x44B8
    ctx->r9 = ADD32(ctx->r9, -0X44B8);
    // 0x8001B218: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B21C: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x8001B220: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001B224: lw          $t9, -0x4D44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D44);
    // 0x8001B228: nop

    // 0x8001B22C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8001B230: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001B234: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001B238: lh          $t3, -0x4D7E($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4D7E);
    // 0x8001B23C: lh          $t2, -0x4D80($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4D80);
    // 0x8001B240: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x8001B244: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B248: mflo        $t4
    ctx->r12 = lo;
    // 0x8001B24C: blez        $t4, L_8001B298
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8001B250: nop

            goto L_8001B298;
    }
    // 0x8001B250: nop

L_8001B254:
    // 0x8001B254: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8001B258: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8001B25C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001B260: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8001B264: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8001B268: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001B26C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001B270: lh          $t2, -0x4D7E($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4D7E);
    // 0x8001B274: lh          $t9, -0x4D80($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4D80);
    // 0x8001B278: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x8001B27C: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B280: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001B284: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
    // 0x8001B288: mflo        $t3
    ctx->r11 = lo;
    // 0x8001B28C: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001B290: bne         $at, $zero, L_8001B254
    if (ctx->r1 != 0) {
        // 0x8001B294: nop

            goto L_8001B254;
    }
    // 0x8001B294: nop

L_8001B298:
    // 0x8001B298: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001B29C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001B2A0: lw          $a1, -0x4D44($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4D44);
    // 0x8001B2A4: lw          $a0, -0x4D40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D40);
    // 0x8001B2A8: jal         0x800BCFCC
    // 0x8001B2AC: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    SysMem_Copy8(rdram, ctx);
        goto after_8;
    // 0x8001B2AC: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_8:
    // 0x8001B2B0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8001B2B4: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8001B2B8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8001B2BC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8001B2C0: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x8001B2C4: nop

    // 0x8001B2C8: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8001B2CC: beq         $t8, $zero, L_8001B2E4
    if (ctx->r24 == 0) {
        // 0x8001B2D0: nop

            goto L_8001B2E4;
    }
    // 0x8001B2D0: nop

    // 0x8001B2D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8001B2D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B2DC: b           L_8001B2F4
    // 0x8001B2E0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
        goto L_8001B2F4;
    // 0x8001B2E0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_8001B2E4:
    // 0x8001B2E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001B2E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001B2EC: nop

    // 0x8001B2F0: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_8001B2F4:
    // 0x8001B2F4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8001B2F8: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x8001B2FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001B300: sh          $t5, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r13;
    // 0x8001B304: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8001B308: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x8001B30C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001B310: sh          $t6, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r14;
    // 0x8001B314: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8001B318: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001B31C: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8001B320: lhu         $t9, 0x0($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X0);
    // 0x8001B324: nop

    // 0x8001B328: andi        $t2, $t9, 0x4
    ctx->r10 = ctx->r25 & 0X4;
    // 0x8001B32C: bne         $t2, $zero, L_8001B344
    if (ctx->r10 != 0) {
        // 0x8001B330: nop

            goto L_8001B344;
    }
    // 0x8001B330: nop

    // 0x8001B334: jal         0x80098820
    // 0x8001B338: nop

    func_80098820(rdram, ctx);
        goto after_9;
    // 0x8001B338: nop

    after_9:
    // 0x8001B33C: jal         0x80098868
    // 0x8001B340: nop

    func_80098868(rdram, ctx);
        goto after_10;
    // 0x8001B340: nop

    after_10:
L_8001B344:
    // 0x8001B344: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8001B348: nop

    // 0x8001B34C: bne         $t1, $zero, L_8001C044
    if (ctx->r9 != 0) {
        // 0x8001B350: nop

            goto L_8001C044;
    }
    // 0x8001B350: nop

L_8001B354:
    // 0x8001B354: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8001B358: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8001B35C: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x8001B360: jal         0x800C143C
    // 0x8001B364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_11;
    // 0x8001B364: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x8001B368: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8001B36C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001B370: lh          $s0, 0x0($t4)
    ctx->r16 = MEM_H(ctx->r12, 0X0);
    // 0x8001B374: nop

    // 0x8001B378: beq         $s0, $at, L_8001B3AC
    if (ctx->r16 == ctx->r1) {
        // 0x8001B37C: nop

            goto L_8001B3AC;
    }
    // 0x8001B37C: nop

    // 0x8001B380: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001B384: beq         $s0, $at, L_8001BD80
    if (ctx->r16 == ctx->r1) {
        // 0x8001B388: nop

            goto L_8001BD80;
    }
    // 0x8001B388: nop

    // 0x8001B38C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001B390: beq         $s0, $at, L_8001C014
    if (ctx->r16 == ctx->r1) {
        // 0x8001B394: nop

            goto L_8001C014;
    }
    // 0x8001B394: nop

    // 0x8001B398: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x8001B39C: beq         $s0, $at, L_8001BF18
    if (ctx->r16 == ctx->r1) {
        // 0x8001B3A0: nop

            goto L_8001BF18;
    }
    // 0x8001B3A0: nop

    // 0x8001B3A4: b           L_8001C02C
    // 0x8001B3A8: nop

        goto L_8001C02C;
    // 0x8001B3A8: nop

L_8001B3AC:
    // 0x8001B3AC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8001B3B0: nop

    // 0x8001B3B4: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x8001B3B8: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x8001B3BC: nop

    // 0x8001B3C0: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8001B3C4: beq         $at, $zero, L_8001BD78
    if (ctx->r1 == 0) {
        // 0x8001B3C8: nop

            goto L_8001BD78;
    }
    // 0x8001B3C8: nop

    // 0x8001B3CC: jal         0x80099768
    // 0x8001B3D0: nop

    func_80099768(rdram, ctx);
        goto after_12;
    // 0x8001B3D0: nop

    after_12:
    // 0x8001B3D4: jal         0x800AFB28
    // 0x8001B3D8: nop

    func_800AFB28(rdram, ctx);
        goto after_13;
    // 0x8001B3D8: nop

    after_13:
    // 0x8001B3DC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8001B3E0: lw          $t6, -0x4CC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CC4);
    // 0x8001B3E4: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8001B3E8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8001B3EC: lw          $t5, -0x4CCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4CCC);
    // 0x8001B3F0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001B3F4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8001B3F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B3FC: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x8001B400: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8001B404: jal         0x800BE510
    // 0x8001B408: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_800BE510(rdram, ctx);
        goto after_14;
    // 0x8001B408: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_14:
    // 0x8001B40C: jal         0x80032604
    // 0x8001B410: nop

    func_80032604(rdram, ctx);
        goto after_15;
    // 0x8001B410: nop

    after_15:
    // 0x8001B414: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001B418: lhu         $t0, 0x24FC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X24FC);
    // 0x8001B41C: nop

    // 0x8001B420: beq         $t0, $zero, L_8001B43C
    if (ctx->r8 == 0) {
        // 0x8001B424: nop

            goto L_8001B43C;
    }
    // 0x8001B424: nop

    // 0x8001B428: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001B42C: lw          $t9, -0x4D44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D44);
    // 0x8001B430: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B434: b           L_8001B44C
    // 0x8001B438: sw          $t9, -0x4D58($at)
    MEM_W(-0X4D58, ctx->r1) = ctx->r25;
        goto L_8001B44C;
    // 0x8001B438: sw          $t9, -0x4D58($at)
    MEM_W(-0X4D58, ctx->r1) = ctx->r25;
L_8001B43C:
    // 0x8001B43C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001B440: lw          $t2, -0x4D40($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4D40);
    // 0x8001B444: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001B448: sw          $t2, -0x4D58($at)
    MEM_W(-0X4D58, ctx->r1) = ctx->r10;
L_8001B44C:
    // 0x8001B44C: jal         0x80096474
    // 0x8001B450: nop

    func_80096474(rdram, ctx);
        goto after_16;
    // 0x8001B450: nop

    after_16:
    // 0x8001B454: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001B458: lw          $a0, -0x4D58($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D58);
    // 0x8001B45C: jal         0x8008ECCC
    // 0x8001B460: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_17;
    // 0x8001B460: nop

    after_17:
    // 0x8001B464: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8001B468: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001B46C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001B470: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001B474: jal         0x8008EC8C
    // 0x8001B478: nop

    func_8008EC8C(rdram, ctx);
        goto after_18;
    // 0x8001B478: nop

    after_18:
    // 0x8001B47C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8001B480: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001B484: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8001B488: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001B48C: jal         0x8008ECAC
    // 0x8001B490: nop

    func_8008ECAC(rdram, ctx);
        goto after_19;
    // 0x8001B490: nop

    after_19:
    // 0x8001B494: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001B498: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8001B49C: sw          $t1, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r9;
    // 0x8001B4A0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8001B4A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8001B4A8: sw          $t3, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r11;
    // 0x8001B4AC: jal         0x80090754
    // 0x8001B4B0: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    func_80090754(rdram, ctx);
        goto after_20;
    // 0x8001B4B0: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    after_20:
    // 0x8001B4B4: jal         0x80090728
    // 0x8001B4B8: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    func_80090728(rdram, ctx);
        goto after_21;
    // 0x8001B4B8: addiu       $a0, $zero, 0x600
    ctx->r4 = ADD32(0, 0X600);
    after_21:
    // 0x8001B4BC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8001B4C0: nop

    // 0x8001B4C4: bne         $t4, $zero, L_8001B974
    if (ctx->r12 != 0) {
        // 0x8001B4C8: nop

            goto L_8001B974;
    }
    // 0x8001B4C8: nop

    // 0x8001B4CC: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B4D0: addiu       $t7, $zero, 0x3F
    ctx->r15 = ADD32(0, 0X3F);
    // 0x8001B4D4: lw          $t5, 0x138($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X138);
    // 0x8001B4D8: nop

    // 0x8001B4DC: sh          $t7, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r15;
    // 0x8001B4E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B4E4: addiu       $t6, $t6, -0x4E60
    ctx->r14 = ADD32(ctx->r14, -0X4E60);
    // 0x8001B4E8: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8001B4EC: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8001B4F0: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x8001B4F4: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
L_8001B4F8:
    // 0x8001B4F8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8001B4FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B500: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8001B504: nop

    // 0x8001B508: bne         $t9, $at, L_8001B518
    if (ctx->r25 != ctx->r1) {
        // 0x8001B50C: nop

            goto L_8001B518;
    }
    // 0x8001B50C: nop

    // 0x8001B510: b           L_8001B6BC
    // 0x8001B514: nop

        goto L_8001B6BC;
    // 0x8001B514: nop

L_8001B518:
    // 0x8001B518: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8001B51C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B520: lw          $t1, 0xC($t2)
    ctx->r9 = MEM_W(ctx->r10, 0XC);
    // 0x8001B524: nop

    // 0x8001B528: beq         $t1, $at, L_8001B564
    if (ctx->r9 == ctx->r1) {
        // 0x8001B52C: nop

            goto L_8001B564;
    }
    // 0x8001B52C: nop

    // 0x8001B530: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8001B534: nop

    // 0x8001B538: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8001B53C: lw          $a1, 0xC($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC);
    // 0x8001B540: jal         0x8008EAA8
    // 0x8001B544: nop

    func_8008EAA8(rdram, ctx);
        goto after_22;
    // 0x8001B544: nop

    after_22:
    // 0x8001B548: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8001B54C: nop

    // 0x8001B550: lw          $t8, 0xC($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC);
    // 0x8001B554: nop

    // 0x8001B558: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8001B55C: b           L_8001B580
    // 0x8001B560: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
        goto L_8001B580;
    // 0x8001B560: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
L_8001B564:
    // 0x8001B564: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8001B568: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x8001B56C: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x8001B570: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8001B574: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x8001B578: jal         0x8008EAA8
    // 0x8001B57C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_23;
    // 0x8001B57C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_23:
L_8001B580:
    // 0x8001B580: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8001B584: nop

    // 0x8001B588: lw          $t2, 0x10($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X10);
    // 0x8001B58C: nop

    // 0x8001B590: beq         $t2, $zero, L_8001B68C
    if (ctx->r10 == 0) {
        // 0x8001B594: nop

            goto L_8001B68C;
    }
    // 0x8001B594: nop

    // 0x8001B598: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B59C: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8001B5A0: nop

    // 0x8001B5A4: bne         $t1, $t3, L_8001B634
    if (ctx->r9 != ctx->r11) {
        // 0x8001B5A8: nop

            goto L_8001B634;
    }
    // 0x8001B5A8: nop

    // 0x8001B5AC: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8001B5B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B5B4: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    // 0x8001B5B8: jal         0x8008ECE4
    // 0x8001B5BC: addiu       $a0, $a0, -0x28AC
    ctx->r4 = ADD32(ctx->r4, -0X28AC);
    func_8008ECE4(rdram, ctx);
        goto after_24;
    // 0x8001B5BC: addiu       $a0, $a0, -0x28AC
    ctx->r4 = ADD32(ctx->r4, -0X28AC);
    after_24:
    // 0x8001B5C0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8001B5C4: nop

    // 0x8001B5C8: lw          $t7, 0x14($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X14);
    // 0x8001B5CC: nop

    // 0x8001B5D0: beq         $t7, $zero, L_8001B5F4
    if (ctx->r15 == 0) {
        // 0x8001B5D4: nop

            goto L_8001B5F4;
    }
    // 0x8001B5D4: nop

    // 0x8001B5D8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8001B5DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001B5E0: lw          $t9, 0x14($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X14);
    // 0x8001B5E4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8001B5E8: jalr        $t9
    // 0x8001B5EC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_25;
    // 0x8001B5EC: nop

    after_25:
    // 0x8001B5F0: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
L_8001B5F4:
    // 0x8001B5F4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8001B5F8: nop

    // 0x8001B5FC: beq         $t6, $zero, L_8001B62C
    if (ctx->r14 == 0) {
        // 0x8001B600: nop

            goto L_8001B62C;
    }
    // 0x8001B600: nop

    // 0x8001B604: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8001B608: nop

    // 0x8001B60C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8001B610: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8001B614: nop

    // 0x8001B618: lw          $t1, 0x18($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X18);
    // 0x8001B61C: nop

    // 0x8001B620: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x8001B624: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B628: sw          $zero, 0x25E4($at)
    MEM_W(0X25E4, ctx->r1) = 0;
L_8001B62C:
    // 0x8001B62C: b           L_8001B678
    // 0x8001B630: nop

        goto L_8001B678;
    // 0x8001B630: nop

L_8001B634:
    // 0x8001B634: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8001B638: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B63C: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    // 0x8001B640: jal         0x8008ECE4
    // 0x8001B644: addiu       $a0, $a0, -0x28A8
    ctx->r4 = ADD32(ctx->r4, -0X28A8);
    func_8008ECE4(rdram, ctx);
        goto after_26;
    // 0x8001B644: addiu       $a0, $a0, -0x28A8
    ctx->r4 = ADD32(ctx->r4, -0X28A8);
    after_26:
    // 0x8001B648: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8001B64C: nop

    // 0x8001B650: lw          $t8, 0x14($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X14);
    // 0x8001B654: nop

    // 0x8001B658: beq         $t8, $zero, L_8001B678
    if (ctx->r24 == 0) {
        // 0x8001B65C: nop

            goto L_8001B678;
    }
    // 0x8001B65C: nop

    // 0x8001B660: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8001B664: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8001B668: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x8001B66C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8001B670: jalr        $t9
    // 0x8001B674: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_27;
    // 0x8001B674: nop

    after_27:
L_8001B678:
    // 0x8001B678: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8001B67C: nop

    // 0x8001B680: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001B684: b           L_8001B6A0
    // 0x8001B688: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
        goto L_8001B6A0;
    // 0x8001B688: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
L_8001B68C:
    // 0x8001B68C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8001B690: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B694: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x8001B698: jal         0x8008ECE4
    // 0x8001B69C: addiu       $a0, $a0, -0x28A4
    ctx->r4 = ADD32(ctx->r4, -0X28A4);
    func_8008ECE4(rdram, ctx);
        goto after_28;
    // 0x8001B69C: addiu       $a0, $a0, -0x28A4
    ctx->r4 = ADD32(ctx->r4, -0X28A4);
    after_28:
L_8001B6A0:
    // 0x8001B6A0: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x8001B6A4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8001B6A8: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8001B6AC: addiu       $t4, $t3, 0x28
    ctx->r12 = ADD32(ctx->r11, 0X28);
    // 0x8001B6B0: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x8001B6B4: b           L_8001B4F8
    // 0x8001B6B8: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
        goto L_8001B4F8;
    // 0x8001B6B8: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
L_8001B6BC:
    // 0x8001B6BC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001B6C0: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001B6C4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001B6C8: lhu         $t9, 0xE68($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XE68);
    // 0x8001B6CC: lhu         $t7, 0x8($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X8);
    // 0x8001B6D0: nop

    // 0x8001B6D4: and         $t5, $t7, $t9
    ctx->r13 = ctx->r15 & ctx->r25;
    // 0x8001B6D8: beq         $t5, $zero, L_8001B6F0
    if (ctx->r13 == 0) {
        // 0x8001B6DC: nop

            goto L_8001B6F0;
    }
    // 0x8001B6DC: nop

    // 0x8001B6E0: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B6E4: nop

    // 0x8001B6E8: addiu       $t0, $t6, -0x1
    ctx->r8 = ADD32(ctx->r14, -0X1);
    // 0x8001B6EC: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
L_8001B6F0:
    // 0x8001B6F0: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001B6F4: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8001B6F8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001B6FC: lhu         $t3, 0xE74($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XE74);
    // 0x8001B700: lhu         $t1, 0x8($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X8);
    // 0x8001B704: nop

    // 0x8001B708: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x8001B70C: beq         $t4, $zero, L_8001B724
    if (ctx->r12 == 0) {
        // 0x8001B710: nop

            goto L_8001B724;
    }
    // 0x8001B710: nop

    // 0x8001B714: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B718: nop

    // 0x8001B71C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8001B720: sw          $t7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r15;
L_8001B724:
    // 0x8001B724: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B728: nop

    // 0x8001B72C: bgez        $t9, L_8001B744
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001B730: nop

            goto L_8001B744;
    }
    // 0x8001B730: nop

    // 0x8001B734: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x8001B738: nop

    // 0x8001B73C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8001B740: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
L_8001B744:
    // 0x8001B744: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x8001B748: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8001B74C: nop

    // 0x8001B750: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001B754: bne         $at, $zero, L_8001B760
    if (ctx->r1 != 0) {
        // 0x8001B758: nop

            goto L_8001B760;
    }
    // 0x8001B758: nop

    // 0x8001B75C: sw          $zero, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = 0;
L_8001B760:
    // 0x8001B760: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8001B764: nop

    // 0x8001B768: beq         $t1, $zero, L_8001B950
    if (ctx->r9 == 0) {
        // 0x8001B76C: nop

            goto L_8001B950;
    }
    // 0x8001B76C: nop

    // 0x8001B770: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001B774: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8001B778: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001B77C: nop

    // 0x8001B780: andi        $t8, $t4, 0x4
    ctx->r24 = ctx->r12 & 0X4;
    // 0x8001B784: beq         $t8, $zero, L_8001B830
    if (ctx->r24 == 0) {
        // 0x8001B788: nop

            goto L_8001B830;
    }
    // 0x8001B788: nop

    // 0x8001B78C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001B790: jal         0x8008EAA8
    // 0x8001B794: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8008EAA8(rdram, ctx);
        goto after_29;
    // 0x8001B794: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_29:
    // 0x8001B798: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001B79C: lw          $t7, 0x251C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X251C);
    // 0x8001B7A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001B7A4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8001B7A8: lwc1        $f6, -0x249C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X249C);
    // 0x8001B7AC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001B7B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001B7B4: lw          $t5, 0x258C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X258C);
    // 0x8001B7B8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001B7BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B7C0: addiu       $a0, $a0, -0x28A0
    ctx->r4 = ADD32(ctx->r4, -0X28A0);
    // 0x8001B7C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8001B7C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001B7CC: nop

    // 0x8001B7D0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001B7D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001B7D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001B7DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B7E0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001B7E4: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001B7E8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001B7EC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8001B7F0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001B7F4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8001B7F8: mfc1        $a2, $f19
    ctx->r6 = (int32_t)ctx->f_odd[(19 - 1) * 2];
    // 0x8001B7FC: jal         0x8008ECE4
    // 0x8001B800: nop

    func_8008ECE4(rdram, ctx);
        goto after_30;
    // 0x8001B800: nop

    after_30:
    // 0x8001B804: jal         0x800BCEBC
    // 0x8001B808: nop

    SysMem_GetFreeSpace(rdram, ctx);
        goto after_31;
    // 0x8001B808: nop

    after_31:
    // 0x8001B80C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001B810: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B814: lui         $a2, 0x1B
    ctx->r6 = S32(0X1B << 16);
    // 0x8001B818: ori         $a2, $a2, 0x5000
    ctx->r6 = ctx->r6 | 0X5000;
    // 0x8001B81C: addiu       $a0, $a0, -0x2880
    ctx->r4 = ADD32(ctx->r4, -0X2880);
    // 0x8001B820: jal         0x8008ECE4
    // 0x8001B824: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8008ECE4(rdram, ctx);
        goto after_32;
    // 0x8001B824: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_32:
    // 0x8001B828: b           L_8001B8FC
    // 0x8001B82C: nop

        goto L_8001B8FC;
    // 0x8001B82C: nop

L_8001B830:
    // 0x8001B830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001B834: jal         0x8008EAA8
    // 0x8001B838: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008EAA8(rdram, ctx);
        goto after_33;
    // 0x8001B838: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_33:
    // 0x8001B83C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8001B840: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B844: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001B848: nop

    // 0x8001B84C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8001B850: nop

    // 0x8001B854: bc1f        L_8001B87C
    if (!c1cs) {
        // 0x8001B858: nop

            goto L_8001B87C;
    }
    // 0x8001B858: nop

    // 0x8001B85C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B860: jal         0x8008ECE4
    // 0x8001B864: addiu       $a0, $a0, -0x2860
    ctx->r4 = ADD32(ctx->r4, -0X2860);
    func_8008ECE4(rdram, ctx);
        goto after_34;
    // 0x8001B864: addiu       $a0, $a0, -0x2860
    ctx->r4 = ADD32(ctx->r4, -0X2860);
    after_34:
    // 0x8001B868: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B86C: jal         0x8008ECE4
    // 0x8001B870: addiu       $a0, $a0, -0x2838
    ctx->r4 = ADD32(ctx->r4, -0X2838);
    func_8008ECE4(rdram, ctx);
        goto after_35;
    // 0x8001B870: addiu       $a0, $a0, -0x2838
    ctx->r4 = ADD32(ctx->r4, -0X2838);
    after_35:
    // 0x8001B874: b           L_8001B8C8
    // 0x8001B878: nop

        goto L_8001B8C8;
    // 0x8001B878: nop

L_8001B87C:
    // 0x8001B87C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8001B880: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001B884: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001B888: nop

    // 0x8001B88C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8001B890: nop

    // 0x8001B894: bc1f        L_8001B8BC
    if (!c1cs) {
        // 0x8001B898: nop

            goto L_8001B8BC;
    }
    // 0x8001B898: nop

    // 0x8001B89C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B8A0: jal         0x8008ECE4
    // 0x8001B8A4: addiu       $a0, $a0, -0x2810
    ctx->r4 = ADD32(ctx->r4, -0X2810);
    func_8008ECE4(rdram, ctx);
        goto after_36;
    // 0x8001B8A4: addiu       $a0, $a0, -0x2810
    ctx->r4 = ADD32(ctx->r4, -0X2810);
    after_36:
    // 0x8001B8A8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B8AC: jal         0x8008ECE4
    // 0x8001B8B0: addiu       $a0, $a0, -0x27E8
    ctx->r4 = ADD32(ctx->r4, -0X27E8);
    func_8008ECE4(rdram, ctx);
        goto after_37;
    // 0x8001B8B0: addiu       $a0, $a0, -0x27E8
    ctx->r4 = ADD32(ctx->r4, -0X27E8);
    after_37:
    // 0x8001B8B4: b           L_8001B8C8
    // 0x8001B8B8: nop

        goto L_8001B8C8;
    // 0x8001B8B8: nop

L_8001B8BC:
    // 0x8001B8BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001B8C0: nop

    // 0x8001B8C4: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
L_8001B8C8:
    // 0x8001B8C8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001B8CC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001B8D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B8D4: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001B8D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001B8DC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001B8E0: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8001B8E4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001B8E8: nop

    // 0x8001B8EC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001B8F0: add.d       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = ctx->f16.d + ctx->f8.d;
    // 0x8001B8F4: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8001B8F8: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
L_8001B8FC:
    // 0x8001B8FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B900: lw          $t6, 0x4CA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4CA4);
    // 0x8001B904: nop

    // 0x8001B908: beq         $t6, $zero, L_8001B928
    if (ctx->r14 == 0) {
        // 0x8001B90C: nop

            goto L_8001B928;
    }
    // 0x8001B90C: nop

    // 0x8001B910: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8001B914: jal         0x8008EAA8
    // 0x8001B918: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008EAA8(rdram, ctx);
        goto after_38;
    // 0x8001B918: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_38:
    // 0x8001B91C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B920: jal         0x8008ECE4
    // 0x8001B924: addiu       $a0, $a0, -0x27C0
    ctx->r4 = ADD32(ctx->r4, -0X27C0);
    func_8008ECE4(rdram, ctx);
        goto after_39;
    // 0x8001B924: addiu       $a0, $a0, -0x27C0
    ctx->r4 = ADD32(ctx->r4, -0X27C0);
    after_39:
L_8001B928:
    // 0x8001B928: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001B92C: jal         0x8008EAA8
    // 0x8001B930: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_40;
    // 0x8001B930: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_40:
    // 0x8001B934: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001B938: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8001B93C: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8001B940: addiu       $a2, $a2, -0x2788
    ctx->r6 = ADD32(ctx->r6, -0X2788);
    // 0x8001B944: addiu       $a1, $a1, -0x2794
    ctx->r5 = ADD32(ctx->r5, -0X2794);
    // 0x8001B948: jal         0x8008ECE4
    // 0x8001B94C: addiu       $a0, $a0, -0x27AC
    ctx->r4 = ADD32(ctx->r4, -0X27AC);
    func_8008ECE4(rdram, ctx);
        goto after_41;
    // 0x8001B94C: addiu       $a0, $a0, -0x27AC
    ctx->r4 = ADD32(ctx->r4, -0X27AC);
    after_41:
L_8001B950:
    // 0x8001B950: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8001B954: nop

    // 0x8001B958: beq         $t0, $zero, L_8001B96C
    if (ctx->r8 == 0) {
        // 0x8001B95C: nop

            goto L_8001B96C;
    }
    // 0x8001B95C: nop

    // 0x8001B960: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B964: jal         0x8001C1F4
    // 0x8001B968: nop

    func_8001C1F4(rdram, ctx);
        goto after_42;
    // 0x8001B968: nop

    after_42:
L_8001B96C:
    // 0x8001B96C: b           L_8001BA44
    // 0x8001B970: nop

        goto L_8001BA44;
    // 0x8001B970: nop

L_8001B974:
    // 0x8001B974: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B978: nop

    // 0x8001B97C: lw          $t1, 0x138($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X138);
    // 0x8001B980: nop

    // 0x8001B984: sh          $zero, 0x2($t1)
    MEM_H(0X2, ctx->r9) = 0;
    // 0x8001B988: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8001B98C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8001B990: jalr        $t9
    // 0x8001B994: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_43;
    // 0x8001B994: nop

    after_43:
    // 0x8001B998: bgez        $v0, L_8001B9B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001B99C: nop

            goto L_8001B9B0;
    }
    // 0x8001B99C: nop

    // 0x8001B9A0: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8001B9A4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001B9A8: jal         0x8001C1F4
    // 0x8001B9AC: nop

    func_8001C1F4(rdram, ctx);
        goto after_44;
    // 0x8001B9AC: nop

    after_44:
L_8001B9B0:
    // 0x8001B9B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001B9B4: lw          $t3, 0x25E4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X25E4);
    // 0x8001B9B8: nop

    // 0x8001B9BC: bne         $t3, $zero, L_8001B9D8
    if (ctx->r11 != 0) {
        // 0x8001B9C0: nop

            goto L_8001B9D8;
    }
    // 0x8001B9C0: nop

    // 0x8001B9C4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001B9C8: lw          $t4, 0x25E4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X25E4);
    // 0x8001B9CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001B9D0: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x8001B9D4: sw          $t8, 0x25E4($at)
    MEM_W(0X25E4, ctx->r1) = ctx->r24;
L_8001B9D8:
    // 0x8001B9D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001B9DC: jal         0x8008EAA8
    // 0x8001B9E0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_8008EAA8(rdram, ctx);
        goto after_45;
    // 0x8001B9E0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_45:
    // 0x8001B9E4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001B9E8: lw          $t7, 0x251C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X251C);
    // 0x8001B9EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001B9F0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001B9F4: lwc1        $f16, -0x2498($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2498);
    // 0x8001B9F8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001B9FC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001BA00: addiu       $a0, $a0, -0x277C
    ctx->r4 = ADD32(ctx->r4, -0X277C);
    // 0x8001BA04: div.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001BA08: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8001BA0C: nop

    // 0x8001BA10: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8001BA14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001BA18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001BA1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001BA20: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001BA24: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001BA28: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8001BA2C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8001BA30: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8001BA34: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8001BA38: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x8001BA3C: jal         0x8008ECE4
    // 0x8001BA40: nop

    func_8008ECE4(rdram, ctx);
        goto after_46;
    // 0x8001BA40: nop

    after_46:
L_8001BA44:
    // 0x8001BA44: jal         0x800967D8
    // 0x8001BA48: nop

    func_800967D8(rdram, ctx);
        goto after_47;
    // 0x8001BA48: nop

    after_47:
    // 0x8001BA4C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BA50: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001BA54: nop

    // 0x8001BA58: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8001BA5C: nop

    // 0x8001BA60: bc1t        L_8001BA84
    if (c1cs) {
        // 0x8001BA64: nop

            goto L_8001BA84;
    }
    // 0x8001BA64: nop

    // 0x8001BA68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BA6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001BA70: nop

    // 0x8001BA74: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x8001BA78: nop

    // 0x8001BA7C: bc1f        L_8001BAB8
    if (!c1cs) {
        // 0x8001BA80: nop

            goto L_8001BAB8;
    }
    // 0x8001BA80: nop

L_8001BA84:
    // 0x8001BA84: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BA88: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8001BA8C: lw          $t0, 0xC0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0XC0);
    // 0x8001BA90: nop

    // 0x8001BA94: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8001BA98: sw          $t2, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r10;
    // 0x8001BA9C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BAA0: nop

    // 0x8001BAA4: lw          $t9, 0xC0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC0);
    // 0x8001BAA8: nop

    // 0x8001BAAC: ori         $t3, $t9, 0x8
    ctx->r11 = ctx->r25 | 0X8;
    // 0x8001BAB0: b           L_8001BB34
    // 0x8001BAB4: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
        goto L_8001BB34;
    // 0x8001BAB4: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
L_8001BAB8:
    // 0x8001BAB8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8001BABC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8001BAC0: lhu         $t8, 0x0($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X0);
    // 0x8001BAC4: nop

    // 0x8001BAC8: andi        $t7, $t8, 0x4
    ctx->r15 = ctx->r24 & 0X4;
    // 0x8001BACC: beq         $t7, $zero, L_8001BB04
    if (ctx->r15 == 0) {
        // 0x8001BAD0: nop

            goto L_8001BB04;
    }
    // 0x8001BAD0: nop

    // 0x8001BAD4: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001BAD8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001BADC: lw          $t0, 0xC0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC0);
    // 0x8001BAE0: nop

    // 0x8001BAE4: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x8001BAE8: sw          $t2, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r10;
    // 0x8001BAEC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8001BAF0: nop

    // 0x8001BAF4: lw          $t9, 0xC0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC0);
    // 0x8001BAF8: nop

    // 0x8001BAFC: ori         $t3, $t9, 0x10
    ctx->r11 = ctx->r25 | 0X10;
    // 0x8001BB00: sw          $t3, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r11;
L_8001BB04:
    // 0x8001BB04: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BB08: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001BB0C: lw          $t4, 0xC0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XC0);
    // 0x8001BB10: nop

    // 0x8001BB14: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x8001BB18: sw          $t8, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r24;
    // 0x8001BB1C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BB20: nop

    // 0x8001BB24: lw          $t0, 0xC0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC0);
    // 0x8001BB28: nop

    // 0x8001BB2C: ori         $t2, $t0, 0x10
    ctx->r10 = ctx->r8 | 0X10;
    // 0x8001BB30: sw          $t2, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r10;
L_8001BB34:
    // 0x8001BB34: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8001BB38: nop

    // 0x8001BB3C: bne         $t5, $zero, L_8001BBA0
    if (ctx->r13 != 0) {
        // 0x8001BB40: nop

            goto L_8001BBA0;
    }
    // 0x8001BB40: nop

    // 0x8001BB44: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BB48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001BB4C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BB50: nop

    // 0x8001BB54: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8001BB58: nop

    // 0x8001BB5C: bc1f        L_8001BB88
    if (!c1cs) {
        // 0x8001BB60: nop

            goto L_8001BB88;
    }
    // 0x8001BB60: nop

    // 0x8001BB64: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BB68: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8001BB6C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001BB70: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001BB74: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8001BB78: add.d       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f16.d + ctx->f10.d;
    // 0x8001BB7C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8001BB80: b           L_8001BB98
    // 0x8001BB84: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
        goto L_8001BB98;
    // 0x8001BB84: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
L_8001BB88:
    // 0x8001BB88: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BB8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001BB90: nop

    // 0x8001BB94: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
L_8001BB98:
    // 0x8001BB98: b           L_8001BC0C
    // 0x8001BB9C: nop

        goto L_8001BC0C;
    // 0x8001BB9C: nop

L_8001BBA0:
    // 0x8001BBA0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BBA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001BBA8: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BBAC: nop

    // 0x8001BBB0: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x8001BBB4: nop

    // 0x8001BBB8: bc1f        L_8001BC00
    if (!c1cs) {
        // 0x8001BBBC: nop

            goto L_8001BC00;
    }
    // 0x8001BBBC: nop

    // 0x8001BBC0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8001BBC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001BBC8: nop

    // 0x8001BBCC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8001BBD0: nop

    // 0x8001BBD4: bc1f        L_8001BC00
    if (!c1cs) {
        // 0x8001BBD8: nop

            goto L_8001BC00;
    }
    // 0x8001BBD8: nop

    // 0x8001BBDC: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BBE0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8001BBE4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001BBE8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001BBEC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8001BBF0: add.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = ctx->f4.d + ctx->f18.d;
    // 0x8001BBF4: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8001BBF8: b           L_8001BC0C
    // 0x8001BBFC: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
        goto L_8001BC0C;
    // 0x8001BBFC: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_8001BC00:
    // 0x8001BC00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001BC04: nop

    // 0x8001BC08: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
L_8001BC0C:
    // 0x8001BC0C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001BC10: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8001BC14: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x8001BC18: nop

    // 0x8001BC1C: andi        $t6, $t3, 0x4
    ctx->r14 = ctx->r11 & 0X4;
    // 0x8001BC20: beq         $t6, $zero, L_8001BC94
    if (ctx->r14 == 0) {
        // 0x8001BC24: nop

            goto L_8001BC94;
    }
    // 0x8001BC24: nop

    // 0x8001BC28: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BC2C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC30: nop

    // 0x8001BC34: swc1        $f8, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f8.u32l;
    // 0x8001BC38: jal         0x800C1754
    // 0x8001BC3C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_48;
    // 0x8001BC3C: nop

    after_48:
    // 0x8001BC40: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC44: jal         0x8009A14C
    // 0x8001BC48: nop

    func_8009A14C(rdram, ctx);
        goto after_49;
    // 0x8001BC48: nop

    after_49:
    // 0x8001BC4C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC50: nop

    // 0x8001BC54: lwc1        $f12, 0xF0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8001BC58: jal         0x800C2780
    // 0x8001BC5C: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_50;
    // 0x8001BC5C: nop

    after_50:
    // 0x8001BC60: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC64: nop

    // 0x8001BC68: lwc1        $f12, 0xEC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XEC);
    // 0x8001BC6C: jal         0x800C25B8
    // 0x8001BC70: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_51;
    // 0x8001BC70: nop

    after_51:
    // 0x8001BC74: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC78: nop

    // 0x8001BC7C: lwc1        $f12, 0xE8($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x8001BC80: jal         0x800C23E8
    // 0x8001BC84: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_52;
    // 0x8001BC84: nop

    after_52:
    // 0x8001BC88: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8001BC8C: jal         0x800997D8
    // 0x8001BC90: nop

    func_800997D8(rdram, ctx);
        goto after_53;
    // 0x8001BC90: nop

    after_53:
L_8001BC94:
    // 0x8001BC94: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BC98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001BC9C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BCA0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCA4: sub.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8001BCA8: swc1        $f16, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f16.u32l;
    // 0x8001BCAC: jal         0x800C1850
    // 0x8001BCB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_54;
    // 0x8001BCB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
    // 0x8001BCB4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCB8: jal         0x8009A14C
    // 0x8001BCBC: nop

    func_8009A14C(rdram, ctx);
        goto after_55;
    // 0x8001BCBC: nop

    after_55:
    // 0x8001BCC0: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCC4: nop

    // 0x8001BCC8: lwc1        $f12, 0xF0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XF0);
    // 0x8001BCCC: jal         0x800C2780
    // 0x8001BCD0: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_56;
    // 0x8001BCD0: nop

    after_56:
    // 0x8001BCD4: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCD8: nop

    // 0x8001BCDC: lwc1        $f12, 0xEC($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XEC);
    // 0x8001BCE0: jal         0x800C25B8
    // 0x8001BCE4: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_57;
    // 0x8001BCE4: nop

    after_57:
    // 0x8001BCE8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BCEC: nop

    // 0x8001BCF0: lwc1        $f12, 0xE8($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0XE8);
    // 0x8001BCF4: jal         0x800C23E8
    // 0x8001BCF8: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_58;
    // 0x8001BCF8: nop

    after_58:
    // 0x8001BCFC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8001BD00: jal         0x800997D8
    // 0x8001BD04: nop

    func_800997D8(rdram, ctx);
        goto after_59;
    // 0x8001BD04: nop

    after_59:
    // 0x8001BD08: jal         0x800C1A28
    // 0x8001BD0C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_60;
    // 0x8001BD0C: nop

    after_60:
    // 0x8001BD10: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8001BD14: jal         0x8009A664
    // 0x8001BD18: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_61;
    // 0x8001BD18: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_61:
    // 0x8001BD1C: jal         0x800BE610
    // 0x8001BD20: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_62;
    // 0x8001BD20: nop

    after_62:
    // 0x8001BD24: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8001BD28: lw          $t3, 0x1B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B4C);
    // 0x8001BD2C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8001BD30: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x8001BD34: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8001BD38: jal         0x8009908C
    // 0x8001BD3C: subu        $a1, $t6, $t3
    ctx->r5 = SUB32(ctx->r14, ctx->r11);
    CreateGfxTask(rdram, ctx);
        goto after_63;
    // 0x8001BD3C: subu        $a1, $t6, $t3
    ctx->r5 = SUB32(ctx->r14, ctx->r11);
    after_63:
    // 0x8001BD40: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8001BD44: nop

    // 0x8001BD48: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x8001BD4C: jal         0x80098D24
    // 0x8001BD50: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_64;
    // 0x8001BD50: nop

    after_64:
    // 0x8001BD54: jal         0x80099450
    // 0x8001BD58: nop

    func_80099450(rdram, ctx);
        goto after_65;
    // 0x8001BD58: nop

    after_65:
    // 0x8001BD5C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8001BD60: nop

    // 0x8001BD64: addiu       $t1, $t8, 0x7FFF
    ctx->r9 = ADD32(ctx->r24, 0X7FFF);
    // 0x8001BD68: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x8001BD6C: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x8001BD70: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8001BD74: sw          $t0, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r8;
L_8001BD78:
    // 0x8001BD78: b           L_8001C034
    // 0x8001BD7C: nop

        goto L_8001C034;
    // 0x8001BD7C: nop

L_8001BD80:
    // 0x8001BD80: jal         0x80099520
    // 0x8001BD84: nop

    func_80099520(rdram, ctx);
        goto after_66;
    // 0x8001BD84: nop

    after_66:
    // 0x8001BD88: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8001BD8C: nop

    // 0x8001BD90: addiu       $t7, $t2, 0x7FFF
    ctx->r15 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001BD94: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x8001BD98: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001BD9C: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x8001BDA0: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
    // 0x8001BDA4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001BDA8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001BDAC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001BDB0: lhu         $t3, 0x1038($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1038);
    // 0x8001BDB4: lhu         $t6, 0x6($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X6);
    // 0x8001BDB8: nop

    // 0x8001BDBC: and         $t4, $t6, $t3
    ctx->r12 = ctx->r14 & ctx->r11;
    // 0x8001BDC0: beq         $t4, $zero, L_8001BE38
    if (ctx->r12 == 0) {
        // 0x8001BDC4: nop

            goto L_8001BE38;
    }
    // 0x8001BDC4: nop

    // 0x8001BDC8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8001BDCC: nop

    // 0x8001BDD0: bne         $t1, $zero, L_8001BE38
    if (ctx->r9 != 0) {
        // 0x8001BDD4: nop

            goto L_8001BE38;
    }
    // 0x8001BDD4: nop

    // 0x8001BDD8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8001BDDC: nop

    // 0x8001BDE0: bne         $t0, $zero, L_8001BE38
    if (ctx->r8 != 0) {
        // 0x8001BDE4: nop

            goto L_8001BE38;
    }
    // 0x8001BDE4: nop

    // 0x8001BDE8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BDEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001BDF0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BDF4: nop

    // 0x8001BDF8: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x8001BDFC: nop

    // 0x8001BE00: bc1f        L_8001BE38
    if (!c1cs) {
        // 0x8001BE04: nop

            goto L_8001BE38;
    }
    // 0x8001BE04: nop

    // 0x8001BE08: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8001BE0C: nop

    // 0x8001BE10: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8001BE14: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x8001BE18: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BE1C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8001BE20: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001BE24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001BE28: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8001BE2C: add.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = ctx->f4.d + ctx->f18.d;
    // 0x8001BE30: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8001BE34: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_8001BE38:
    // 0x8001BE38: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8001BE3C: nop

    // 0x8001BE40: beq         $t5, $zero, L_8001BF10
    if (ctx->r13 == 0) {
        // 0x8001BE44: nop

            goto L_8001BF10;
    }
    // 0x8001BE44: nop

    // 0x8001BE48: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001BE4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001BE50: nop

    // 0x8001BE54: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x8001BE58: nop

    // 0x8001BE5C: bc1t        L_8001BE80
    if (c1cs) {
        // 0x8001BE60: nop

            goto L_8001BE80;
    }
    // 0x8001BE60: nop

    // 0x8001BE64: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001BE68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001BE6C: nop

    // 0x8001BE70: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x8001BE74: nop

    // 0x8001BE78: bc1f        L_8001BF10
    if (!c1cs) {
        // 0x8001BE7C: nop

            goto L_8001BF10;
    }
    // 0x8001BE7C: nop

L_8001BE80:
    // 0x8001BE80: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001BE84: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x8001BE88: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x8001BE8C: nop

    // 0x8001BE90: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x8001BE94: beq         $t6, $zero, L_8001BEFC
    if (ctx->r14 == 0) {
        // 0x8001BE98: nop

            goto L_8001BEFC;
    }
    // 0x8001BE98: nop

    // 0x8001BE9C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8001BEA0: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8001BEA4: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x8001BEA8: nop

    // 0x8001BEAC: and         $t1, $t4, $at
    ctx->r9 = ctx->r12 & ctx->r1;
    // 0x8001BEB0: sw          $t1, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r9;
    // 0x8001BEB4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8001BEB8: nop

    // 0x8001BEBC: lw          $t8, 0xC0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC0);
    // 0x8001BEC0: nop

    // 0x8001BEC4: ori         $t7, $t8, 0x8
    ctx->r15 = ctx->r24 | 0X8;
    // 0x8001BEC8: sw          $t7, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r15;
    // 0x8001BECC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001BED0: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8001BED4: nop

    // 0x8001BED8: swc1        $f18, 0xF0($t5)
    MEM_W(0XF0, ctx->r13) = ctx->f18.u32l;
    // 0x8001BEDC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8001BEE0: nop

    // 0x8001BEE4: lwc1        $f20, 0xF0($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0XF0);
    // 0x8001BEE8: nop

    // 0x8001BEEC: swc1        $f20, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f20.u32l;
    // 0x8001BEF0: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8001BEF4: nop

    // 0x8001BEF8: swc1        $f20, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f20.u32l;
L_8001BEFC:
    // 0x8001BEFC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001BF00: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x8001BF04: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8001BF08: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001BF0C: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
L_8001BF10:
    // 0x8001BF10: b           L_8001C034
    // 0x8001BF14: nop

        goto L_8001C034;
    // 0x8001BF14: nop

L_8001BF18:
    // 0x8001BF18: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8001BF1C: nop

    // 0x8001BF20: addiu       $t8, $t3, 0x7FFF
    ctx->r24 = ADD32(ctx->r11, 0X7FFF);
    // 0x8001BF24: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x8001BF28: nop

    // 0x8001BF2C: blez        $t8, L_8001BFB0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001BF30: nop

            goto L_8001BFB0;
    }
    // 0x8001BF30: nop

L_8001BF34:
    // 0x8001BF34: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8001BF38: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8001BF3C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8001BF40: jal         0x800C143C
    // 0x8001BF44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_67;
    // 0x8001BF44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_67:
    // 0x8001BF48: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8001BF4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001BF50: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x8001BF54: nop

    // 0x8001BF58: bne         $t5, $at, L_8001BF94
    if (ctx->r13 != ctx->r1) {
        // 0x8001BF5C: nop

            goto L_8001BF94;
    }
    // 0x8001BF5C: nop

    // 0x8001BF60: b           L_8001BF68
    // 0x8001BF64: nop

        goto L_8001BF68;
    // 0x8001BF64: nop

L_8001BF68:
    // 0x8001BF68: jal         0x80099520
    // 0x8001BF6C: nop

    func_80099520(rdram, ctx);
        goto after_68;
    // 0x8001BF6C: nop

    after_68:
    // 0x8001BF70: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8001BF74: nop

    // 0x8001BF78: addiu       $t9, $t2, 0x7FFF
    ctx->r25 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001BF7C: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x8001BF80: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001BF84: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8001BF88: sw          $t6, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r14;
    // 0x8001BF8C: b           L_8001BF94
    // 0x8001BF90: nop

        goto L_8001BF94;
    // 0x8001BF90: nop

L_8001BF94:
    // 0x8001BF94: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8001BF98: nop

    // 0x8001BF9C: addiu       $t1, $t4, 0x7FFF
    ctx->r9 = ADD32(ctx->r12, 0X7FFF);
    // 0x8001BFA0: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x8001BFA4: nop

    // 0x8001BFA8: bgtz        $t1, L_8001BF34
    if (SIGNED(ctx->r9) > 0) {
        // 0x8001BFAC: nop

            goto L_8001BF34;
    }
    // 0x8001BFAC: nop

L_8001BFB0:
    // 0x8001BFB0: jal         0x80098820
    // 0x8001BFB4: nop

    func_80098820(rdram, ctx);
        goto after_69;
    // 0x8001BFB4: nop

    after_69:
    // 0x8001BFB8: jal         0x80098868
    // 0x8001BFBC: nop

    func_80098868(rdram, ctx);
        goto after_70;
    // 0x8001BFBC: nop

    after_70:
    // 0x8001BFC0: jal         0x80005460
    // 0x8001BFC4: nop

    func_80005460(rdram, ctx);
        goto after_71;
    // 0x8001BFC4: nop

    after_71:
    // 0x8001BFC8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001BFCC: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001BFD0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8001BFD4: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    // 0x8001BFD8: jal         0x80005124
    // 0x8001BFDC: nop

    func_80005124(rdram, ctx);
        goto after_72;
    // 0x8001BFDC: nop

    after_72:
    // 0x8001BFE0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8001BFE4: nop

    // 0x8001BFE8: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x8001BFEC: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x8001BFF0: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8001BFF4: nop

    // 0x8001BFF8: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8001BFFC: jal         0x800C13B8
    // 0x8001C000: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_73;
    // 0x8001C000: nop

    after_73:
    // 0x8001C004: jal         0x80098820
    // 0x8001C008: nop

    func_80098820(rdram, ctx);
        goto after_74;
    // 0x8001C008: nop

    after_74:
    // 0x8001C00C: b           L_8001C034
    // 0x8001C010: nop

        goto L_8001C034;
    // 0x8001C010: nop

L_8001C014:
    // 0x8001C014: jal         0x800029BC
    // 0x8001C018: nop

    func_800029BC(rdram, ctx);
        goto after_75;
    // 0x8001C018: nop

    after_75:
L_8001C01C:
    // 0x8001C01C: b           L_8001C01C
    pause_self(rdram);
    // 0x8001C020: nop

    // 0x8001C024: b           L_8001C034
    // 0x8001C028: nop

        goto L_8001C034;
    // 0x8001C028: nop

L_8001C02C:
    // 0x8001C02C: b           L_8001C034
    // 0x8001C030: nop

        goto L_8001C034;
    // 0x8001C030: nop

L_8001C034:
    // 0x8001C034: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8001C038: nop

    // 0x8001C03C: beq         $t0, $zero, L_8001B354
    if (ctx->r8 == 0) {
        // 0x8001C040: nop

            goto L_8001B354;
    }
    // 0x8001C040: nop

L_8001C044:
    // 0x8001C044: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001C048: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x8001C04C: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x8001C050: nop

    // 0x8001C054: andi        $t6, $t9, 0x4
    ctx->r14 = ctx->r25 & 0X4;
    // 0x8001C058: bne         $t6, $zero, L_8001C108
    if (ctx->r14 != 0) {
        // 0x8001C05C: nop

            goto L_8001C108;
    }
    // 0x8001C05C: nop

    // 0x8001C060: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8001C064: nop

    // 0x8001C068: addiu       $t4, $t2, 0x7FFF
    ctx->r12 = ADD32(ctx->r10, 0X7FFF);
    // 0x8001C06C: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x8001C070: nop

    // 0x8001C074: blez        $t4, L_8001C0F8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8001C078: nop

            goto L_8001C0F8;
    }
    // 0x8001C078: nop

L_8001C07C:
    // 0x8001C07C: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8001C080: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8001C084: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x8001C088: jal         0x800C143C
    // 0x8001C08C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_76;
    // 0x8001C08C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_76:
    // 0x8001C090: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8001C094: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C098: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x8001C09C: nop

    // 0x8001C0A0: bne         $t8, $at, L_8001C0DC
    if (ctx->r24 != ctx->r1) {
        // 0x8001C0A4: nop

            goto L_8001C0DC;
    }
    // 0x8001C0A4: nop

    // 0x8001C0A8: b           L_8001C0B0
    // 0x8001C0AC: nop

        goto L_8001C0B0;
    // 0x8001C0AC: nop

L_8001C0B0:
    // 0x8001C0B0: jal         0x80099520
    // 0x8001C0B4: nop

    func_80099520(rdram, ctx);
        goto after_77;
    // 0x8001C0B4: nop

    after_77:
    // 0x8001C0B8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8001C0BC: nop

    // 0x8001C0C0: addiu       $t0, $t7, 0x7FFF
    ctx->r8 = ADD32(ctx->r15, 0X7FFF);
    // 0x8001C0C4: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x8001C0C8: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x8001C0CC: addiu       $t5, $t0, -0x1
    ctx->r13 = ADD32(ctx->r8, -0X1);
    // 0x8001C0D0: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
    // 0x8001C0D4: b           L_8001C0DC
    // 0x8001C0D8: nop

        goto L_8001C0DC;
    // 0x8001C0D8: nop

L_8001C0DC:
    // 0x8001C0DC: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8001C0E0: nop

    // 0x8001C0E4: addiu       $t6, $t9, 0x7FFF
    ctx->r14 = ADD32(ctx->r25, 0X7FFF);
    // 0x8001C0E8: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x8001C0EC: nop

    // 0x8001C0F0: bgtz        $t6, L_8001C07C
    if (SIGNED(ctx->r14) > 0) {
        // 0x8001C0F4: nop

            goto L_8001C07C;
    }
    // 0x8001C0F4: nop

L_8001C0F8:
    // 0x8001C0F8: jal         0x80098820
    // 0x8001C0FC: nop

    func_80098820(rdram, ctx);
        goto after_78;
    // 0x8001C0FC: nop

    after_78:
    // 0x8001C100: jal         0x80098868
    // 0x8001C104: nop

    func_80098868(rdram, ctx);
        goto after_79;
    // 0x8001C104: nop

    after_79:
L_8001C108:
    // 0x8001C108: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001C10C: addiu       $a1, $a1, -0x5980
    ctx->r5 = ADD32(ctx->r5, -0X5980);
    // 0x8001C110: jal         0x800A6670
    // 0x8001C114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_80;
    // 0x8001C114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_80:
    // 0x8001C118: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001C11C: addiu       $a1, $a1, -0x5980
    ctx->r5 = ADD32(ctx->r5, -0X5980);
    // 0x8001C120: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8001C124: jal         0x800A6670
    // 0x8001C128: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_81;
    // 0x8001C128: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_81:
    // 0x8001C12C: jal         0x80005460
    // 0x8001C130: nop

    func_80005460(rdram, ctx);
        goto after_82;
    // 0x8001C130: nop

    after_82:
    // 0x8001C134: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8001C138: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x8001C13C: jal         0x800A6670
    // 0x8001C140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_83;
    // 0x8001C140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_83:
    // 0x8001C144: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8001C148: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x8001C14C: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8001C150: jal         0x800A6670
    // 0x8001C154: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_84;
    // 0x8001C154: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_84:
    // 0x8001C158: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001C15C: lw          $a0, -0x4D48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D48);
    // 0x8001C160: jal         0x800BC980
    // 0x8001C164: nop

    SysMem_Free(rdram, ctx);
        goto after_85;
    // 0x8001C164: nop

    after_85:
    // 0x8001C168: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001C16C: lw          $a0, -0x4D40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D40);
    // 0x8001C170: jal         0x800BC980
    // 0x8001C174: nop

    SysMem_Free(rdram, ctx);
        goto after_86;
    // 0x8001C174: nop

    after_86:
    // 0x8001C178: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8001C17C: lw          $a0, -0x4D44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4D44);
    // 0x8001C180: jal         0x800BC980
    // 0x8001C184: nop

    SysMem_Free(rdram, ctx);
        goto after_87;
    // 0x8001C184: nop

    after_87:
    // 0x8001C188: lhu         $t2, 0x56($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X56);
    // 0x8001C18C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8001C190: addiu       $t4, $t4, -0x44B8
    ctx->r12 = ADD32(ctx->r12, -0X44B8);
    // 0x8001C194: sh          $t2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r10;
    // 0x8001C198: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001C19C: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8001C1A0: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8001C1A4: nop

    // 0x8001C1A8: andi        $t8, $t3, 0x4
    ctx->r24 = ctx->r11 & 0X4;
    // 0x8001C1AC: bne         $t8, $zero, L_8001C1D4
    if (ctx->r24 != 0) {
        // 0x8001C1B0: nop

            goto L_8001C1D4;
    }
    // 0x8001C1B0: nop

    // 0x8001C1B4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8001C1B8: lh          $t0, 0x7320($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7320);
    // 0x8001C1BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C1C0: sh          $t0, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r8;
    // 0x8001C1C4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8001C1C8: lh          $t5, 0x7338($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7338);
    // 0x8001C1CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C1D0: sh          $t5, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r13;
L_8001C1D4:
    // 0x8001C1D4: b           L_8001C1DC
    // 0x8001C1D8: nop

        goto L_8001C1DC;
    // 0x8001C1D8: nop

L_8001C1DC:
    // 0x8001C1DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C1E0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001C1E4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001C1E8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001C1EC: jr          $ra
    // 0x8001C1F0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8001C1F0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8001C1F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C1F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001C1F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C1FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001C200: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001C204: nop

    // 0x8001C208: lw          $t7, 0x13C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X13C);
    // 0x8001C20C: nop

    // 0x8001C210: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001C214: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001C218: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8001C21C: lh          $t0, 0x102($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X102);
    // 0x8001C220: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x8001C224: nop

    // 0x8001C228: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C22C: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C230: blez        $t1, L_8001C27C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C234: nop

            goto L_8001C27C;
    }
    // 0x8001C234: nop

L_8001C238:
    // 0x8001C238: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8001C23C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C240: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001C244: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8001C248: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8001C24C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C250: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001C254: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001C258: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001C25C: lh          $t0, 0x102($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X102);
    // 0x8001C260: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x8001C264: nop

    // 0x8001C268: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C26C: mflo        $t1
    ctx->r9 = lo;
    // 0x8001C270: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C274: bne         $at, $zero, L_8001C238
    if (ctx->r1 != 0) {
        // 0x8001C278: nop

            goto L_8001C238;
    }
    // 0x8001C278: nop

L_8001C27C:
    // 0x8001C27C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8001C280: addiu       $a2, $zero, 0x1E00
    ctx->r6 = ADD32(0, 0X1E00);
    // 0x8001C284: lw          $a0, 0x140($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X140);
    // 0x8001C288: lw          $a1, 0x13C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X13C);
    // 0x8001C28C: jal         0x800BD110
    // 0x8001C290: nop

    SysMem_Copy64(rdram, ctx);
        goto after_0;
    // 0x8001C290: nop

    after_0:
    // 0x8001C294: b           L_8001C29C
    // 0x8001C298: nop

        goto L_8001C29C;
    // 0x8001C298: nop

L_8001C29C:
    // 0x8001C29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C2A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001C2A4: jr          $ra
    // 0x8001C2A8: nop

    return;
    // 0x8001C2A8: nop

;}
RECOMP_FUNC void func_8001C2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C2AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C2B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C2B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001C2B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001C2BC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C2C0: nop

    // 0x8001C2C4: bltz        $t6, L_8001C500
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001C2C8: nop

            goto L_8001C500;
    }
    // 0x8001C2C8: nop

    // 0x8001C2CC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C2D0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C2D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C2D8: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001C2DC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001C2E0: nop

    // 0x8001C2E4: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C2E8: beq         $t0, $zero, L_8001C304
    if (ctx->r8 == 0) {
        // 0x8001C2EC: nop

            goto L_8001C304;
    }
    // 0x8001C2EC: nop

    // 0x8001C2F0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8001C2F4: lh          $t1, 0x7320($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7320);
    // 0x8001C2F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C2FC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001C300: sh          $t2, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r10;
L_8001C304:
    // 0x8001C304: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C308: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C30C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C310: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001C314: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001C318: nop

    // 0x8001C31C: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C320: beq         $t6, $zero, L_8001C33C
    if (ctx->r14 == 0) {
        // 0x8001C324: nop

            goto L_8001C33C;
    }
    // 0x8001C324: nop

    // 0x8001C328: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8001C32C: lh          $t7, 0x7320($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7320);
    // 0x8001C330: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C334: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001C338: sh          $t8, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r24;
L_8001C33C:
    // 0x8001C33C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001C340: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001C344: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001C348: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001C34C: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001C350: nop

    // 0x8001C354: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001C358: beq         $t2, $zero, L_8001C374
    if (ctx->r10 == 0) {
        // 0x8001C35C: nop

            goto L_8001C374;
    }
    // 0x8001C35C: nop

    // 0x8001C360: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8001C364: lh          $t3, 0x7338($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7338);
    // 0x8001C368: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C36C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8001C370: sh          $t4, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r12;
L_8001C374:
    // 0x8001C374: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001C378: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001C37C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001C380: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001C384: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8001C388: nop

    // 0x8001C38C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001C390: beq         $t8, $zero, L_8001C3AC
    if (ctx->r24 == 0) {
        // 0x8001C394: nop

            goto L_8001C3AC;
    }
    // 0x8001C394: nop

    // 0x8001C398: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8001C39C: lh          $t9, 0x7338($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7338);
    // 0x8001C3A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C3A4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8001C3A8: sh          $t0, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r8;
L_8001C3AC:
    // 0x8001C3AC: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001C3B0: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001C3B4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001C3B8: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8001C3BC: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001C3C0: nop

    // 0x8001C3C4: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001C3C8: beq         $t4, $zero, L_8001C3E4
    if (ctx->r12 == 0) {
        // 0x8001C3CC: nop

            goto L_8001C3E4;
    }
    // 0x8001C3CC: nop

    // 0x8001C3D0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8001C3D4: lh          $t5, 0x7338($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7338);
    // 0x8001C3D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C3DC: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x8001C3E0: sh          $t6, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r14;
L_8001C3E4:
    // 0x8001C3E4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C3E8: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C3EC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C3F0: lhu         $t9, 0x11AC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X11AC);
    // 0x8001C3F4: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001C3F8: nop

    // 0x8001C3FC: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C400: beq         $t0, $zero, L_8001C41C
    if (ctx->r8 == 0) {
        // 0x8001C404: nop

            goto L_8001C41C;
    }
    // 0x8001C404: nop

    // 0x8001C408: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8001C40C: lh          $t1, 0x7338($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7338);
    // 0x8001C410: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C414: addiu       $t2, $t1, -0xA
    ctx->r10 = ADD32(ctx->r9, -0XA);
    // 0x8001C418: sh          $t2, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r10;
L_8001C41C:
    // 0x8001C41C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C420: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C424: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C428: lhu         $t5, 0x10F2($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X10F2);
    // 0x8001C42C: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8001C430: nop

    // 0x8001C434: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C438: beq         $t6, $zero, L_8001C450
    if (ctx->r14 == 0) {
        // 0x8001C43C: nop

            goto L_8001C450;
    }
    // 0x8001C43C: nop

    // 0x8001C440: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C444: sh          $zero, 0x7248($at)
    MEM_H(0X7248, ctx->r1) = 0;
    // 0x8001C448: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C44C: sh          $zero, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = 0;
L_8001C450:
    // 0x8001C450: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C454: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C458: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C45C: lhu         $t9, 0xEC0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEC0);
    // 0x8001C460: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x8001C464: nop

    // 0x8001C468: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C46C: beq         $t0, $zero, L_8001C48C
    if (ctx->r8 == 0) {
        // 0x8001C470: nop

            goto L_8001C48C;
    }
    // 0x8001C470: nop

    // 0x8001C474: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8001C478: lw          $t1, 0x72DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72DC);
    // 0x8001C47C: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8001C480: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8001C484: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C488: sw          $t2, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r10;
L_8001C48C:
    // 0x8001C48C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C490: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C494: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C498: lhu         $t5, 0xEEC($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEEC);
    // 0x8001C49C: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8001C4A0: nop

    // 0x8001C4A4: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C4A8: beq         $t6, $zero, L_8001C4C4
    if (ctx->r14 == 0) {
        // 0x8001C4AC: nop

            goto L_8001C4C4;
    }
    // 0x8001C4AC: nop

    // 0x8001C4B0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8001C4B4: lw          $t7, 0x72DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72DC);
    // 0x8001C4B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C4BC: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8001C4C0: sw          $t8, 0x72DC($at)
    MEM_W(0X72DC, ctx->r1) = ctx->r24;
L_8001C4C4:
    // 0x8001C4C4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001C4C8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001C4CC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001C4D0: lhu         $t1, 0x1042($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1042);
    // 0x8001C4D4: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8001C4D8: nop

    // 0x8001C4DC: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001C4E0: beq         $t2, $zero, L_8001C500
    if (ctx->r10 == 0) {
        // 0x8001C4E4: nop

            goto L_8001C500;
    }
    // 0x8001C4E4: nop

    // 0x8001C4E8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8001C4EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C4F0: sh          $t3, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r11;
    // 0x8001C4F4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001C4F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C4FC: sh          $t4, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r12;
L_8001C500:
    // 0x8001C500: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001C504: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x8001C508: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8001C50C: nop

    // 0x8001C510: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8001C514: beq         $t7, $zero, L_8001C564
    if (ctx->r15 == 0) {
        // 0x8001C518: nop

            goto L_8001C564;
    }
    // 0x8001C518: nop

    // 0x8001C51C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8001C520: lh          $t8, 0x7320($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7320);
    // 0x8001C524: nop

    // 0x8001C528: bgtz        $t8, L_8001C53C
    if (SIGNED(ctx->r24) > 0) {
        // 0x8001C52C: nop

            goto L_8001C53C;
    }
    // 0x8001C52C: nop

    // 0x8001C530: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001C534: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C538: sh          $t9, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r25;
L_8001C53C:
    // 0x8001C53C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8001C540: lh          $t0, 0x7338($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7338);
    // 0x8001C544: nop

    // 0x8001C548: bgtz        $t0, L_8001C55C
    if (SIGNED(ctx->r8) > 0) {
        // 0x8001C54C: nop

            goto L_8001C55C;
    }
    // 0x8001C54C: nop

    // 0x8001C550: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001C554: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C558: sh          $t1, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r9;
L_8001C55C:
    // 0x8001C55C: b           L_8001C59C
    // 0x8001C560: nop

        goto L_8001C59C;
    // 0x8001C560: nop

L_8001C564:
    // 0x8001C564: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8001C568: lh          $t2, 0x7320($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7320);
    // 0x8001C56C: nop

    // 0x8001C570: bgtz        $t2, L_8001C580
    if (SIGNED(ctx->r10) > 0) {
        // 0x8001C574: nop

            goto L_8001C580;
    }
    // 0x8001C574: nop

    // 0x8001C578: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C57C: sh          $zero, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = 0;
L_8001C580:
    // 0x8001C580: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8001C584: lh          $t3, 0x7338($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7338);
    // 0x8001C588: nop

    // 0x8001C58C: bgtz        $t3, L_8001C59C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8001C590: nop

            goto L_8001C59C;
    }
    // 0x8001C590: nop

    // 0x8001C594: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001C598: sh          $zero, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = 0;
L_8001C59C:
    // 0x8001C59C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8001C5A0: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8001C5A4: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x8001C5A8: lh          $a3, 0x7268($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7268);
    // 0x8001C5AC: lh          $a2, 0x7338($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7338);
    // 0x8001C5B0: lh          $a1, 0x7320($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7320);
    // 0x8001C5B4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001C5B8: jal         0x8008ECE4
    // 0x8001C5BC: addiu       $a0, $a0, -0x2764
    ctx->r4 = ADD32(ctx->r4, -0X2764);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001C5BC: addiu       $a0, $a0, -0x2764
    ctx->r4 = ADD32(ctx->r4, -0X2764);
    after_0:
    // 0x8001C5C0: b           L_8001C5D0
    // 0x8001C5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001C5D0;
    // 0x8001C5C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001C5C8: b           L_8001C5D0
    // 0x8001C5CC: nop

        goto L_8001C5D0;
    // 0x8001C5CC: nop

L_8001C5D0:
    // 0x8001C5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C5D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C5D8: jr          $ra
    // 0x8001C5DC: nop

    return;
    // 0x8001C5DC: nop

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
RECOMP_FUNC void func_8001C94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C94C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C954: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001C958: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001C95C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C960: nop

    // 0x8001C964: bltz        $t6, L_8001CB14
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001C968: nop

            goto L_8001CB14;
    }
    // 0x8001C968: nop

    // 0x8001C96C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001C970: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001C974: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001C978: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001C97C: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001C980: nop

    // 0x8001C984: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001C988: beq         $t0, $zero, L_8001C9A4
    if (ctx->r8 == 0) {
        // 0x8001C98C: nop

            goto L_8001C9A4;
    }
    // 0x8001C98C: nop

    // 0x8001C990: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001C994: lh          $t1, -0x7290($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7290);
    // 0x8001C998: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C99C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001C9A0: sh          $t2, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r10;
L_8001C9A4:
    // 0x8001C9A4: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001C9A8: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001C9AC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001C9B0: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001C9B4: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001C9B8: nop

    // 0x8001C9BC: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001C9C0: beq         $t6, $zero, L_8001C9DC
    if (ctx->r14 == 0) {
        // 0x8001C9C4: nop

            goto L_8001C9DC;
    }
    // 0x8001C9C4: nop

    // 0x8001C9C8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8001C9CC: lh          $t7, -0x7290($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X7290);
    // 0x8001C9D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001C9D4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001C9D8: sh          $t8, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r24;
L_8001C9DC:
    // 0x8001C9DC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001C9E0: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001C9E4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001C9E8: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001C9EC: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001C9F0: nop

    // 0x8001C9F4: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001C9F8: beq         $t2, $zero, L_8001CA14
    if (ctx->r10 == 0) {
        // 0x8001C9FC: nop

            goto L_8001CA14;
    }
    // 0x8001C9FC: nop

    // 0x8001CA00: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001CA04: lh          $t3, -0x7288($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X7288);
    // 0x8001CA08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CA0C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8001CA10: sh          $t4, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = ctx->r12;
L_8001CA14:
    // 0x8001CA14: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001CA18: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001CA1C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001CA20: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001CA24: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8001CA28: nop

    // 0x8001CA2C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001CA30: beq         $t8, $zero, L_8001CA4C
    if (ctx->r24 == 0) {
        // 0x8001CA34: nop

            goto L_8001CA4C;
    }
    // 0x8001CA34: nop

    // 0x8001CA38: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001CA3C: lh          $t9, -0x7288($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X7288);
    // 0x8001CA40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CA44: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8001CA48: sh          $t0, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = ctx->r8;
L_8001CA4C:
    // 0x8001CA4C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001CA50: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001CA54: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001CA58: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8001CA5C: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001CA60: nop

    // 0x8001CA64: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001CA68: beq         $t4, $zero, L_8001CA84
    if (ctx->r12 == 0) {
        // 0x8001CA6C: nop

            goto L_8001CA84;
    }
    // 0x8001CA6C: nop

    // 0x8001CA70: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001CA74: lh          $t5, -0x7280($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X7280);
    // 0x8001CA78: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CA7C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001CA80: sh          $t6, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = ctx->r14;
L_8001CA84:
    // 0x8001CA84: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CA88: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001CA8C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CA90: lhu         $t9, 0x11AC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X11AC);
    // 0x8001CA94: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001CA98: nop

    // 0x8001CA9C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001CAA0: beq         $t0, $zero, L_8001CABC
    if (ctx->r8 == 0) {
        // 0x8001CAA4: nop

            goto L_8001CABC;
    }
    // 0x8001CAA4: nop

    // 0x8001CAA8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001CAAC: lh          $t1, -0x7280($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7280);
    // 0x8001CAB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CAB4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8001CAB8: sh          $t2, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = ctx->r10;
L_8001CABC:
    // 0x8001CABC: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001CAC0: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001CAC4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001CAC8: lhu         $t5, 0x1042($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1042);
    // 0x8001CACC: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8001CAD0: nop

    // 0x8001CAD4: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001CAD8: beq         $t6, $zero, L_8001CB14
    if (ctx->r14 == 0) {
        // 0x8001CADC: nop

            goto L_8001CB14;
    }
    // 0x8001CADC: nop

    // 0x8001CAE0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8001CAE4: lh          $t7, -0x7290($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X7290);
    // 0x8001CAE8: nop

    // 0x8001CAEC: slti        $at, $t7, 0x1F4
    ctx->r1 = SIGNED(ctx->r15) < 0X1F4 ? 1 : 0;
    // 0x8001CAF0: beq         $at, $zero, L_8001CB08
    if (ctx->r1 == 0) {
        // 0x8001CAF4: nop

            goto L_8001CB08;
    }
    // 0x8001CAF4: nop

    // 0x8001CAF8: addiu       $t8, $zero, 0x1F4
    ctx->r24 = ADD32(0, 0X1F4);
    // 0x8001CAFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB00: b           L_8001CB14
    // 0x8001CB04: sh          $t8, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r24;
        goto L_8001CB14;
    // 0x8001CB04: sh          $t8, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r24;
L_8001CB08:
    // 0x8001CB08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001CB0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB10: sh          $t9, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r25;
L_8001CB14:
    // 0x8001CB14: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001CB18: lh          $t0, -0x7290($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X7290);
    // 0x8001CB1C: nop

    // 0x8001CB20: bgez        $t0, L_8001CB30
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001CB24: nop

            goto L_8001CB30;
    }
    // 0x8001CB24: nop

    // 0x8001CB28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB2C: sh          $zero, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = 0;
L_8001CB30:
    // 0x8001CB30: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001CB34: lh          $t1, -0x7288($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7288);
    // 0x8001CB38: nop

    // 0x8001CB3C: bgez        $t1, L_8001CB4C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001CB40: nop

            goto L_8001CB4C;
    }
    // 0x8001CB40: nop

    // 0x8001CB44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB48: sh          $zero, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = 0;
L_8001CB4C:
    // 0x8001CB4C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8001CB50: lh          $t2, -0x7280($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X7280);
    // 0x8001CB54: nop

    // 0x8001CB58: bgez        $t2, L_8001CB68
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8001CB5C: nop

            goto L_8001CB68;
    }
    // 0x8001CB5C: nop

    // 0x8001CB60: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001CB64: sh          $zero, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = 0;
L_8001CB68:
    // 0x8001CB68: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8001CB6C: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x8001CB70: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x8001CB74: lh          $a3, -0x7280($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X7280);
    // 0x8001CB78: lh          $a2, -0x7288($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X7288);
    // 0x8001CB7C: lh          $a1, -0x7290($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X7290);
    // 0x8001CB80: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CB84: jal         0x8008ECE4
    // 0x8001CB88: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001CB88: addiu       $a0, $a0, -0x26F8
    ctx->r4 = ADD32(ctx->r4, -0X26F8);
    after_0:
    // 0x8001CB8C: b           L_8001CB9C
    // 0x8001CB90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CB9C;
    // 0x8001CB90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CB94: b           L_8001CB9C
    // 0x8001CB98: nop

        goto L_8001CB9C;
    // 0x8001CB98: nop

L_8001CB9C:
    // 0x8001CB9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CBA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CBA4: jr          $ra
    // 0x8001CBA8: nop

    return;
    // 0x8001CBA8: nop

;}
RECOMP_FUNC void func_8001CBAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CBAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CBB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CBB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001CBB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001CBBC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CBC0: nop

    // 0x8001CBC4: bltz        $t6, L_8001CC20
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001CBC8: nop

            goto L_8001CC20;
    }
    // 0x8001CBC8: nop

    // 0x8001CBCC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CBD0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001CBD4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CBD8: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001CBDC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001CBE0: nop

    // 0x8001CBE4: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001CBE8: bne         $t0, $zero, L_8001CC08
    if (ctx->r8 != 0) {
        // 0x8001CBEC: nop

            goto L_8001CC08;
    }
    // 0x8001CBEC: nop

    // 0x8001CBF0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001CBF4: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001CBF8: nop

    // 0x8001CBFC: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001CC00: beq         $t2, $zero, L_8001CC20
    if (ctx->r10 == 0) {
        // 0x8001CC04: nop

            goto L_8001CC20;
    }
    // 0x8001CC04: nop

L_8001CC08:
    // 0x8001CC08: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001CC0C: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8001CC10: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001CC14: nop

    // 0x8001CC18: xori        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 ^ 0X8;
    // 0x8001CC1C: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
L_8001CC20:
    // 0x8001CC20: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8001CC24: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8001CC28: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8001CC2C: nop

    // 0x8001CC30: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x8001CC34: beq         $t9, $zero, L_8001CC50
    if (ctx->r25 == 0) {
        // 0x8001CC38: nop

            goto L_8001CC50;
    }
    // 0x8001CC38: nop

    // 0x8001CC3C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CC40: jal         0x8008ECE4
    // 0x8001CC44: addiu       $a0, $a0, -0x26E4
    ctx->r4 = ADD32(ctx->r4, -0X26E4);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001CC44: addiu       $a0, $a0, -0x26E4
    ctx->r4 = ADD32(ctx->r4, -0X26E4);
    after_0:
    // 0x8001CC48: b           L_8001CC5C
    // 0x8001CC4C: nop

        goto L_8001CC5C;
    // 0x8001CC4C: nop

L_8001CC50:
    // 0x8001CC50: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CC54: jal         0x8008ECE4
    // 0x8001CC58: addiu       $a0, $a0, -0x26DC
    ctx->r4 = ADD32(ctx->r4, -0X26DC);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001CC58: addiu       $a0, $a0, -0x26DC
    ctx->r4 = ADD32(ctx->r4, -0X26DC);
    after_1:
L_8001CC5C:
    // 0x8001CC5C: b           L_8001CC6C
    // 0x8001CC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CC6C;
    // 0x8001CC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CC64: b           L_8001CC6C
    // 0x8001CC68: nop

        goto L_8001CC6C;
    // 0x8001CC68: nop

L_8001CC6C:
    // 0x8001CC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CC70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CC74: jr          $ra
    // 0x8001CC78: nop

    return;
    // 0x8001CC78: nop

;}
RECOMP_FUNC void func_8001CC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CC7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CC80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CC84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001CC88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001CC8C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CC90: nop

    // 0x8001CC94: bltz        $t6, L_8001CCF0
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001CC98: nop

            goto L_8001CCF0;
    }
    // 0x8001CC98: nop

    // 0x8001CC9C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CCA0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001CCA4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CCA8: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001CCAC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001CCB0: nop

    // 0x8001CCB4: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001CCB8: bne         $t0, $zero, L_8001CCD8
    if (ctx->r8 != 0) {
        // 0x8001CCBC: nop

            goto L_8001CCD8;
    }
    // 0x8001CCBC: nop

    // 0x8001CCC0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001CCC4: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001CCC8: nop

    // 0x8001CCCC: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001CCD0: beq         $t2, $zero, L_8001CCF0
    if (ctx->r10 == 0) {
        // 0x8001CCD4: nop

            goto L_8001CCF0;
    }
    // 0x8001CCD4: nop

L_8001CCD8:
    // 0x8001CCD8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8001CCDC: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x8001CCE0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001CCE4: nop

    // 0x8001CCE8: xori        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 ^ 0X4000;
    // 0x8001CCEC: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
L_8001CCF0:
    // 0x8001CCF0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8001CCF4: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8001CCF8: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8001CCFC: nop

    // 0x8001CD00: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x8001CD04: beq         $t9, $zero, L_8001CD20
    if (ctx->r25 == 0) {
        // 0x8001CD08: nop

            goto L_8001CD20;
    }
    // 0x8001CD08: nop

    // 0x8001CD0C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CD10: jal         0x8008ECE4
    // 0x8001CD14: addiu       $a0, $a0, -0x26D4
    ctx->r4 = ADD32(ctx->r4, -0X26D4);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001CD14: addiu       $a0, $a0, -0x26D4
    ctx->r4 = ADD32(ctx->r4, -0X26D4);
    after_0:
    // 0x8001CD18: b           L_8001CD2C
    // 0x8001CD1C: nop

        goto L_8001CD2C;
    // 0x8001CD1C: nop

L_8001CD20:
    // 0x8001CD20: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CD24: jal         0x8008ECE4
    // 0x8001CD28: addiu       $a0, $a0, -0x26CC
    ctx->r4 = ADD32(ctx->r4, -0X26CC);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001CD28: addiu       $a0, $a0, -0x26CC
    ctx->r4 = ADD32(ctx->r4, -0X26CC);
    after_1:
L_8001CD2C:
    // 0x8001CD2C: b           L_8001CD3C
    // 0x8001CD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CD3C;
    // 0x8001CD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CD34: b           L_8001CD3C
    // 0x8001CD38: nop

        goto L_8001CD3C;
    // 0x8001CD38: nop

L_8001CD3C:
    // 0x8001CD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CD40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CD44: jr          $ra
    // 0x8001CD48: nop

    return;
    // 0x8001CD48: nop

;}
RECOMP_FUNC void func_8001CD4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001CD50: bltz        $a1, L_8001CD84
    if (SIGNED(ctx->r5) < 0) {
        // 0x8001CD54: nop

            goto L_8001CD84;
    }
    // 0x8001CD54: nop

    // 0x8001CD58: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001CD5C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8001CD60: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001CD64: lhu         $t8, 0xFF4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XFF4);
    // 0x8001CD68: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x8001CD6C: nop

    // 0x8001CD70: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8001CD74: beq         $t9, $zero, L_8001CD84
    if (ctx->r25 == 0) {
        // 0x8001CD78: nop

            goto L_8001CD84;
    }
    // 0x8001CD78: nop

    // 0x8001CD7C: b           L_8001CD94
    // 0x8001CD80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8001CD94;
    // 0x8001CD80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001CD84:
    // 0x8001CD84: b           L_8001CD94
    // 0x8001CD88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CD94;
    // 0x8001CD88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CD8C: b           L_8001CD94
    // 0x8001CD90: nop

        goto L_8001CD94;
    // 0x8001CD90: nop

L_8001CD94:
    // 0x8001CD94: jr          $ra
    // 0x8001CD98: nop

    return;
    // 0x8001CD98: nop

;}
RECOMP_FUNC void func_8001CD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001CDA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CDA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001CDA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001CDAC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001CDB0: nop

    // 0x8001CDB4: bltz        $t6, L_8001CDF8
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001CDB8: nop

            goto L_8001CDF8;
    }
    // 0x8001CDB8: nop

    // 0x8001CDBC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CDC0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001CDC4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CDC8: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001CDCC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001CDD0: nop

    // 0x8001CDD4: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001CDD8: beq         $t0, $zero, L_8001CDF8
    if (ctx->r8 == 0) {
        // 0x8001CDDC: nop

            goto L_8001CDF8;
    }
    // 0x8001CDDC: nop

    // 0x8001CDE0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8001CDE4: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8001CDE8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8001CDEC: nop

    // 0x8001CDF0: xori        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 ^ 0X10;
    // 0x8001CDF4: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_8001CDF8:
    // 0x8001CDF8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8001CDFC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8001CE00: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8001CE04: nop

    // 0x8001CE08: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x8001CE0C: beq         $t6, $zero, L_8001CE28
    if (ctx->r14 == 0) {
        // 0x8001CE10: nop

            goto L_8001CE28;
    }
    // 0x8001CE10: nop

    // 0x8001CE14: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CE18: jal         0x8008ECE4
    // 0x8001CE1C: addiu       $a0, $a0, -0x26C4
    ctx->r4 = ADD32(ctx->r4, -0X26C4);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001CE1C: addiu       $a0, $a0, -0x26C4
    ctx->r4 = ADD32(ctx->r4, -0X26C4);
    after_0:
    // 0x8001CE20: b           L_8001CE34
    // 0x8001CE24: nop

        goto L_8001CE34;
    // 0x8001CE24: nop

L_8001CE28:
    // 0x8001CE28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CE2C: jal         0x8008ECE4
    // 0x8001CE30: addiu       $a0, $a0, -0x26BC
    ctx->r4 = ADD32(ctx->r4, -0X26BC);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001CE30: addiu       $a0, $a0, -0x26BC
    ctx->r4 = ADD32(ctx->r4, -0X26BC);
    after_1:
L_8001CE34:
    // 0x8001CE34: b           L_8001CE44
    // 0x8001CE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CE44;
    // 0x8001CE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CE3C: b           L_8001CE44
    // 0x8001CE40: nop

        goto L_8001CE44;
    // 0x8001CE40: nop

L_8001CE44:
    // 0x8001CE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CE48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001CE4C: jr          $ra
    // 0x8001CE50: nop

    return;
    // 0x8001CE50: nop

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
RECOMP_FUNC void func_8001CF0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001CF10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001CF14: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001CF18: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8001CF1C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001CF20: lhu         $t8, 0x11A4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X11A4);
    // 0x8001CF24: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x8001CF28: nop

    // 0x8001CF2C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8001CF30: bne         $t9, $zero, L_8001CF50
    if (ctx->r25 != 0) {
        // 0x8001CF34: nop

            goto L_8001CF50;
    }
    // 0x8001CF34: nop

    // 0x8001CF38: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001CF3C: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x8001CF40: nop

    // 0x8001CF44: and         $t1, $t7, $t0
    ctx->r9 = ctx->r15 & ctx->r8;
    // 0x8001CF48: beq         $t1, $zero, L_8001CF58
    if (ctx->r9 == 0) {
        // 0x8001CF4C: nop

            goto L_8001CF58;
    }
    // 0x8001CF4C: nop

L_8001CF50:
    // 0x8001CF50: b           L_8001CF68
    // 0x8001CF54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8001CF68;
    // 0x8001CF54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001CF58:
    // 0x8001CF58: b           L_8001CF68
    // 0x8001CF5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CF68;
    // 0x8001CF5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001CF60: b           L_8001CF68
    // 0x8001CF64: nop

        goto L_8001CF68;
    // 0x8001CF64: nop

L_8001CF68:
    // 0x8001CF68: jr          $ra
    // 0x8001CF6C: nop

    return;
    // 0x8001CF6C: nop

;}
RECOMP_FUNC void func_8001CF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF70: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001CF74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CF78: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8001CF7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001CF80: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001CF84: jal         0x8008EAA8
    // 0x8001CF88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001CF88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8001CF8C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8001CF90: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001CF94: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001CF98: jal         0x8008ECE4
    // 0x8001CF9C: addiu       $a0, $a0, -0x26A4
    ctx->r4 = ADD32(ctx->r4, -0X26A4);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001CF9C: addiu       $a0, $a0, -0x26A4
    ctx->r4 = ADD32(ctx->r4, -0X26A4);
    after_1:
    // 0x8001CFA0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001CFA4: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x8001CFA8: nop

    // 0x8001CFAC: beq         $s0, $zero, L_8001CFC8
    if (ctx->r16 == 0) {
        // 0x8001CFB0: nop

            goto L_8001CFC8;
    }
    // 0x8001CFB0: nop

    // 0x8001CFB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CFB8: beq         $s0, $at, L_8001D1D4
    if (ctx->r16 == ctx->r1) {
        // 0x8001CFBC: nop

            goto L_8001D1D4;
    }
    // 0x8001CFBC: nop

    // 0x8001CFC0: b           L_8001DB3C
    // 0x8001CFC4: nop

        goto L_8001DB3C;
    // 0x8001CFC4: nop

L_8001CFC8:
    // 0x8001CFC8: jal         0x800BC6EC
    // 0x8001CFCC: addiu       $a0, $zero, 0xB00
    ctx->r4 = ADD32(0, 0XB00);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8001CFCC: addiu       $a0, $zero, 0xB00
    ctx->r4 = ADD32(0, 0XB00);
    after_2:
    // 0x8001CFD0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001CFD4: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8001CFD8: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8001CFDC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001CFE0: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001CFE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001CFE8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8001CFEC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001CFF0: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001CFF4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8001CFF8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001CFFC: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001D000: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8001D004: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8001D008: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001D00C: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001D010: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001D014: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8001D018: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D01C: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001D020: sw          $zero, 0x10($t5)
    MEM_W(0X10, ctx->r13) = 0;
    // 0x8001D024: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8001D028:
    // 0x8001D028: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8001D02C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001D030: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001D034: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001D038: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001D03C: addiu       $t6, $t6, 0x2618
    ctx->r14 = ADD32(ctx->r14, 0X2618);
    // 0x8001D040: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001D044: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001D048: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8001D04C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8001D050: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8001D054: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001D058: jal         0x80099E2C
    // 0x8001D05C: nop

    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x8001D05C: nop

    after_3:
    // 0x8001D060: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D064: nop

    // 0x8001D068: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x8001D06C: nop

    // 0x8001D070: ori         $t3, $t2, 0x10C
    ctx->r11 = ctx->r10 | 0X10C;
    // 0x8001D074: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
    // 0x8001D078: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D07C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001D080: sh          $t4, 0x116($t5)
    MEM_H(0X116, ctx->r13) = ctx->r12;
    // 0x8001D084: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8001D088: lw          $t6, -0x4D48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D48);
    // 0x8001D08C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D090: nop

    // 0x8001D094: sw          $t6, 0x138($t8)
    MEM_W(0X138, ctx->r24) = ctx->r14;
    // 0x8001D098: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001D09C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8001D0A0: addiu       $t7, $t7, -0x4B18
    ctx->r15 = ADD32(ctx->r15, -0X4B18);
    // 0x8001D0A4: sw          $t7, 0x128($t9)
    MEM_W(0X128, ctx->r25) = ctx->r15;
    // 0x8001D0A8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D0AC: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x8001D0B0: sw          $t0, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r8;
    // 0x8001D0B4: jal         0x800BC6EC
    // 0x8001D0B8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x8001D0B8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_4:
    // 0x8001D0BC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D0C0: nop

    // 0x8001D0C4: sw          $v0, 0x12C($t3)
    MEM_W(0X12C, ctx->r11) = ctx->r2;
    // 0x8001D0C8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D0CC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8001D0D0: lw          $t4, 0x12C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X12C);
    // 0x8001D0D4: nop

    // 0x8001D0D8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
L_8001D0DC:
    // 0x8001D0DC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001D0E0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001D0E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001D0E8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001D0EC: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x8001D0F0: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x8001D0F4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8001D0F8: nop

    // 0x8001D0FC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8001D100: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8001D104: bne         $at, $zero, L_8001D0DC
    if (ctx->r1 != 0) {
        // 0x8001D108: sw          $t0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r8;
            goto L_8001D0DC;
    }
    // 0x8001D108: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8001D10C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001D110: nop

    // 0x8001D114: bne         $t2, $zero, L_8001D164
    if (ctx->r10 != 0) {
        // 0x8001D118: nop

            goto L_8001D164;
    }
    // 0x8001D118: nop

    // 0x8001D11C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001D120: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D124: nop

    // 0x8001D128: swc1        $f6, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f6.u32l;
    // 0x8001D12C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001D130: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D134: nop

    // 0x8001D138: swc1        $f8, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->f8.u32l;
    // 0x8001D13C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D140: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D144: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8001D148: nop

    // 0x8001D14C: swc1        $f10, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f10.u32l;
    // 0x8001D150: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D154: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001D158: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001D15C: b           L_8001D1B4
    // 0x8001D160: swc1        $f16, 0xE4($t6)
    MEM_W(0XE4, ctx->r14) = ctx->f16.u32l;
        goto L_8001D1B4;
    // 0x8001D160: swc1        $f16, 0xE4($t6)
    MEM_W(0XE4, ctx->r14) = ctx->f16.u32l;
L_8001D164:
    // 0x8001D164: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D168: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D16C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D170: nop

    // 0x8001D174: swc1        $f18, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f18.u32l;
    // 0x8001D178: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D17C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D180: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D184: nop

    // 0x8001D188: swc1        $f4, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f4.u32l;
    // 0x8001D18C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001D190: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D194: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8001D198: nop

    // 0x8001D19C: swc1        $f6, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f6.u32l;
    // 0x8001D1A0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D1A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D1A8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001D1AC: nop

    // 0x8001D1B0: swc1        $f8, 0xE4($t9)
    MEM_W(0XE4, ctx->r25) = ctx->f8.u32l;
L_8001D1B4:
    // 0x8001D1B4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8001D1B8: nop

    // 0x8001D1BC: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8001D1C0: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8001D1C4: bne         $at, $zero, L_8001D028
    if (ctx->r1 != 0) {
        // 0x8001D1C8: sw          $t2, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r10;
            goto L_8001D028;
    }
    // 0x8001D1C8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8001D1CC: b           L_8001DB44
    // 0x8001D1D0: nop

        goto L_8001DB44;
    // 0x8001D1D0: nop

L_8001D1D4:
    // 0x8001D1D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001D1D8: jal         0x8008EAA8
    // 0x8001D1DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_5;
    // 0x8001D1DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8001D1E0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001D1E4: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001D1E8: lw          $a1, 0x10($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X10);
    // 0x8001D1EC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001D1F0: jal         0x8008ECE4
    // 0x8001D1F4: addiu       $a0, $a0, -0x2698
    ctx->r4 = ADD32(ctx->r4, -0X2698);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8001D1F4: addiu       $a0, $a0, -0x2698
    ctx->r4 = ADD32(ctx->r4, -0X2698);
    after_6:
    // 0x8001D1F8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D1FC: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D200: lw          $a1, 0xC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC);
    // 0x8001D204: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x8001D208: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001D20C: jal         0x8008ECE4
    // 0x8001D210: addiu       $a0, $a0, -0x2684
    ctx->r4 = ADD32(ctx->r4, -0X2684);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8001D210: addiu       $a0, $a0, -0x2684
    ctx->r4 = ADD32(ctx->r4, -0X2684);
    after_7:
    // 0x8001D214: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001D218: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8001D21C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D220: lhu         $t5, 0x1042($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1042);
    // 0x8001D224: lhu         $t6, 0x6($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X6);
    // 0x8001D228: nop

    // 0x8001D22C: and         $t8, $t6, $t5
    ctx->r24 = ctx->r14 & ctx->r13;
    // 0x8001D230: beq         $t8, $zero, L_8001D4D8
    if (ctx->r24 == 0) {
        // 0x8001D234: nop

            goto L_8001D4D8;
    }
    // 0x8001D234: nop

    // 0x8001D238: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8001D23C:
    // 0x8001D23C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8001D240: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D244: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8001D248: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8001D24C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001D250: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8001D254: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001D258: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8001D25C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8001D260: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8001D264: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8001D268: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D26C: nop

    // 0x8001D270: lw          $t4, 0x12C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X12C);
    // 0x8001D274: nop

    // 0x8001D278: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8001D27C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001D280: jal         0x80099E2C
    // 0x8001D284: nop

    func_80099E2C(rdram, ctx);
        goto after_8;
    // 0x8001D284: nop

    after_8:
    // 0x8001D288: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001D28C: nop

    // 0x8001D290: lw          $t5, 0xC0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC0);
    // 0x8001D294: nop

    // 0x8001D298: ori         $t8, $t5, 0x10C
    ctx->r24 = ctx->r13 | 0X10C;
    // 0x8001D29C: sw          $t8, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r24;
    // 0x8001D2A0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001D2A8: sh          $t7, 0x116($t0)
    MEM_H(0X116, ctx->r8) = ctx->r15;
    // 0x8001D2AC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8001D2B0: lw          $t9, -0x4D48($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D48);
    // 0x8001D2B4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2B8: nop

    // 0x8001D2BC: sw          $t9, 0x138($t2)
    MEM_W(0X138, ctx->r10) = ctx->r25;
    // 0x8001D2C0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2C4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8001D2C8: addiu       $t3, $t3, -0x4B18
    ctx->r11 = ADD32(ctx->r11, -0X4B18);
    // 0x8001D2CC: sw          $t3, 0x128($t1)
    MEM_W(0X128, ctx->r9) = ctx->r11;
    // 0x8001D2D0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2D4: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x8001D2D8: sw          $t4, 0xC8($t5)
    MEM_W(0XC8, ctx->r13) = ctx->r12;
    // 0x8001D2DC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8001D2E0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2E4: nop

    // 0x8001D2E8: sw          $t8, 0x12C($t6)
    MEM_W(0X12C, ctx->r14) = ctx->r24;
    // 0x8001D2EC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8001D2F0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8001D2F4: lw          $t0, 0x12C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X12C);
    // 0x8001D2F8: nop

    // 0x8001D2FC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_8001D300:
    // 0x8001D300: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8001D304: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001D308: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001D30C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001D310: addu        $t1, $t9, $t3
    ctx->r9 = ADD32(ctx->r25, ctx->r11);
    // 0x8001D314: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x8001D318: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8001D31C: nop

    // 0x8001D320: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8001D324: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x8001D328: bne         $at, $zero, L_8001D300
    if (ctx->r1 != 0) {
        // 0x8001D32C: sw          $t5, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r13;
            goto L_8001D300;
    }
    // 0x8001D32C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x8001D330: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D334: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D338: lw          $t6, 0x10($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X10);
    // 0x8001D33C: nop

    // 0x8001D340: bne         $t6, $zero, L_8001D3F8
    if (ctx->r14 != 0) {
        // 0x8001D344: nop

            goto L_8001D3F8;
    }
    // 0x8001D344: nop

    // 0x8001D348: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8001D34C: nop

    // 0x8001D350: bne         $t7, $zero, L_8001D3A0
    if (ctx->r15 != 0) {
        // 0x8001D354: nop

            goto L_8001D3A0;
    }
    // 0x8001D354: nop

    // 0x8001D358: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001D35C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D360: nop

    // 0x8001D364: swc1        $f16, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f16.u32l;
    // 0x8001D368: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001D36C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D370: nop

    // 0x8001D374: swc1        $f18, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f18.u32l;
    // 0x8001D378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D37C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D380: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001D384: nop

    // 0x8001D388: swc1        $f4, 0xEC($t9)
    MEM_W(0XEC, ctx->r25) = ctx->f4.u32l;
    // 0x8001D38C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D390: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D394: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D398: b           L_8001D3F0
    // 0x8001D39C: swc1        $f6, 0xE4($t3)
    MEM_W(0XE4, ctx->r11) = ctx->f6.u32l;
        goto L_8001D3F0;
    // 0x8001D39C: swc1        $f6, 0xE4($t3)
    MEM_W(0XE4, ctx->r11) = ctx->f6.u32l;
L_8001D3A0:
    // 0x8001D3A0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D3A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D3A8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D3AC: nop

    // 0x8001D3B0: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    // 0x8001D3B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D3B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D3BC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8001D3C0: nop

    // 0x8001D3C4: swc1        $f10, 0xF0($t4)
    MEM_W(0XF0, ctx->r12) = ctx->f10.u32l;
    // 0x8001D3C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001D3CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001D3D0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D3D4: nop

    // 0x8001D3D8: swc1        $f16, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f16.u32l;
    // 0x8001D3DC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D3E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D3E4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D3E8: nop

    // 0x8001D3EC: swc1        $f18, 0xE4($t8)
    MEM_W(0XE4, ctx->r24) = ctx->f18.u32l;
L_8001D3F0:
    // 0x8001D3F0: b           L_8001D490
    // 0x8001D3F4: nop

        goto L_8001D490;
    // 0x8001D3F4: nop

L_8001D3F8:
    // 0x8001D3F8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8001D3FC: nop

    // 0x8001D400: bne         $t6, $zero, L_8001D44C
    if (ctx->r14 != 0) {
        // 0x8001D404: nop

            goto L_8001D44C;
    }
    // 0x8001D404: nop

    // 0x8001D408: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001D40C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8001D410: nop

    // 0x8001D414: swc1        $f4, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f4.u32l;
    // 0x8001D418: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001D41C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D420: nop

    // 0x8001D424: swc1        $f6, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f6.u32l;
    // 0x8001D428: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D42C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D430: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D434: nop

    // 0x8001D438: swc1        $f8, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f8.u32l;
    // 0x8001D43C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001D440: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001D444: b           L_8001D490
    // 0x8001D448: swc1        $f10, 0xE4($t9)
    MEM_W(0XE4, ctx->r25) = ctx->f10.u32l;
        goto L_8001D490;
    // 0x8001D448: swc1        $f10, 0xE4($t9)
    MEM_W(0XE4, ctx->r25) = ctx->f10.u32l;
L_8001D44C:
    // 0x8001D44C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001D450: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D454: nop

    // 0x8001D458: swc1        $f16, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f16.u32l;
    // 0x8001D45C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001D460: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001D464: nop

    // 0x8001D468: swc1        $f18, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->f18.u32l;
    // 0x8001D46C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001D470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D474: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8001D478: nop

    // 0x8001D47C: swc1        $f4, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f4.u32l;
    // 0x8001D480: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001D484: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D488: nop

    // 0x8001D48C: swc1        $f6, 0xE4($t5)
    MEM_W(0XE4, ctx->r13) = ctx->f6.u32l;
L_8001D490:
    // 0x8001D490: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8001D494: nop

    // 0x8001D498: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8001D49C: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8001D4A0: bne         $at, $zero, L_8001D23C
    if (ctx->r1 != 0) {
        // 0x8001D4A4: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8001D23C;
    }
    // 0x8001D4A4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8001D4A8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001D4AC: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001D4B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001D4B4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8001D4B8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001D4BC: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001D4C0: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x8001D4C4: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x8001D4C8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D4CC: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D4D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001D4D4: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
L_8001D4D8:
    // 0x8001D4D8: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001D4DC: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8001D4E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D4E4: lhu         $t8, 0xFF4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XFF4);
    // 0x8001D4E8: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8001D4EC: nop

    // 0x8001D4F0: and         $t6, $t5, $t8
    ctx->r14 = ctx->r13 & ctx->r24;
    // 0x8001D4F4: beq         $t6, $zero, L_8001D514
    if (ctx->r14 == 0) {
        // 0x8001D4F8: nop

            goto L_8001D514;
    }
    // 0x8001D4F8: nop

    // 0x8001D4FC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D500: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001D504: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8001D508: nop

    // 0x8001D50C: xori        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 ^ 0X1;
    // 0x8001D510: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
L_8001D514:
    // 0x8001D514: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001D518: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001D51C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D520: lhu         $t1, 0x126C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X126C);
    // 0x8001D524: lhu         $t3, 0x6($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X6);
    // 0x8001D528: nop

    // 0x8001D52C: and         $t4, $t3, $t1
    ctx->r12 = ctx->r11 & ctx->r9;
    // 0x8001D530: beq         $t4, $zero, L_8001D550
    if (ctx->r12 == 0) {
        // 0x8001D534: nop

            goto L_8001D550;
    }
    // 0x8001D534: nop

    // 0x8001D538: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D53C: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001D540: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x8001D544: nop

    // 0x8001D548: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8001D54C: sw          $t6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r14;
L_8001D550:
    // 0x8001D550: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001D554: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8001D558: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D55C: lhu         $t7, 0x11AC($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X11AC);
    // 0x8001D560: lhu         $t2, 0x6($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X6);
    // 0x8001D564: nop

    // 0x8001D568: and         $t9, $t2, $t7
    ctx->r25 = ctx->r10 & ctx->r15;
    // 0x8001D56C: beq         $t9, $zero, L_8001D58C
    if (ctx->r25 == 0) {
        // 0x8001D570: nop

            goto L_8001D58C;
    }
    // 0x8001D570: nop

    // 0x8001D574: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001D578: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001D57C: lw          $t1, 0x8($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X8);
    // 0x8001D580: nop

    // 0x8001D584: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x8001D588: sw          $t4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r12;
L_8001D58C:
    // 0x8001D58C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001D590: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001D594: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D598: lhu         $t5, 0x1258($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1258);
    // 0x8001D59C: lhu         $t6, 0x6($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X6);
    // 0x8001D5A0: nop

    // 0x8001D5A4: and         $t0, $t6, $t5
    ctx->r8 = ctx->r14 & ctx->r13;
    // 0x8001D5A8: beq         $t0, $zero, L_8001D5C8
    if (ctx->r8 == 0) {
        // 0x8001D5AC: nop

            goto L_8001D5C8;
    }
    // 0x8001D5AC: nop

    // 0x8001D5B0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001D5B4: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001D5B8: lw          $t7, 0xC($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XC);
    // 0x8001D5BC: nop

    // 0x8001D5C0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8001D5C4: sw          $t9, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r25;
L_8001D5C8:
    // 0x8001D5C8: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001D5CC: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001D5D0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001D5D4: lhu         $t3, 0x1260($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1260);
    // 0x8001D5D8: lhu         $t4, 0x6($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X6);
    // 0x8001D5DC: nop

    // 0x8001D5E0: and         $t8, $t4, $t3
    ctx->r24 = ctx->r12 & ctx->r11;
    // 0x8001D5E4: beq         $t8, $zero, L_8001D604
    if (ctx->r24 == 0) {
        // 0x8001D5E8: nop

            goto L_8001D604;
    }
    // 0x8001D5E8: nop

    // 0x8001D5EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001D5F0: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001D5F4: lw          $t5, 0xC($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC);
    // 0x8001D5F8: nop

    // 0x8001D5FC: addiu       $t0, $t5, -0x1
    ctx->r8 = ADD32(ctx->r13, -0X1);
    // 0x8001D600: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
L_8001D604:
    // 0x8001D604: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D608: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001D60C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8001D610: nop

    // 0x8001D614: bgez        $t9, L_8001D628
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001D618: nop

            goto L_8001D628;
    }
    // 0x8001D618: nop

    // 0x8001D61C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001D620: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001D624: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
L_8001D628:
    // 0x8001D628: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D62C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D630: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x8001D634: nop

    // 0x8001D638: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8001D63C: bne         $at, $zero, L_8001D654
    if (ctx->r1 != 0) {
        // 0x8001D640: nop

            goto L_8001D654;
    }
    // 0x8001D640: nop

    // 0x8001D644: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D648: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D64C: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8001D650: sw          $t3, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r11;
L_8001D654:
    // 0x8001D654: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D658: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001D65C: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x8001D660: nop

    // 0x8001D664: bgtz        $t0, L_8001D67C
    if (SIGNED(ctx->r8) > 0) {
        // 0x8001D668: nop

            goto L_8001D67C;
    }
    // 0x8001D668: nop

    // 0x8001D66C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001D670: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001D674: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D678: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
L_8001D67C:
    // 0x8001D67C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001D680: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001D684: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x8001D688: nop

    // 0x8001D68C: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x8001D690: bne         $at, $zero, L_8001D6A8
    if (ctx->r1 != 0) {
        // 0x8001D694: nop

            goto L_8001D6A8;
    }
    // 0x8001D694: nop

    // 0x8001D698: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001D69C: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001D6A0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8001D6A4: sw          $t1, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r9;
L_8001D6A8:
    // 0x8001D6A8: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001D6AC: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001D6B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D6B4: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001D6B8: lhu         $t8, 0x6($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X6);
    // 0x8001D6BC: nop

    // 0x8001D6C0: and         $t0, $t8, $t5
    ctx->r8 = ctx->r24 & ctx->r13;
    // 0x8001D6C4: beq         $t0, $zero, L_8001D6E4
    if (ctx->r8 == 0) {
        // 0x8001D6C8: nop

            goto L_8001D6E4;
    }
    // 0x8001D6C8: nop

    // 0x8001D6CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001D6D0: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001D6D4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8001D6D8: nop

    // 0x8001D6DC: xori        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 ^ 0X1;
    // 0x8001D6E0: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
L_8001D6E4:
    // 0x8001D6E4: jal         0x800C1680
    // 0x8001D6E8: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_9;
    // 0x8001D6E8: nop

    after_9:
    // 0x8001D6EC: jal         0x8009A22C
    // 0x8001D6F0: nop

    func_8009A22C(rdram, ctx);
        goto after_10;
    // 0x8001D6F0: nop

    after_10:
    // 0x8001D6F4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001D6F8: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8001D6FC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001D700: lhu         $t4, 0x10F2($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X10F2);
    // 0x8001D704: lhu         $t1, 0x4($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X4);
    // 0x8001D708: nop

    // 0x8001D70C: and         $t3, $t1, $t4
    ctx->r11 = ctx->r9 & ctx->r12;
    // 0x8001D710: bne         $t3, $zero, L_8001D758
    if (ctx->r11 != 0) {
        // 0x8001D714: nop

            goto L_8001D758;
    }
    // 0x8001D714: nop

    // 0x8001D718: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D71C: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D720: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8001D724: nop

    // 0x8001D728: beq         $t5, $zero, L_8001D750
    if (ctx->r13 == 0) {
        // 0x8001D72C: nop

            goto L_8001D750;
    }
    // 0x8001D72C: nop

    // 0x8001D730: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8001D734: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001D738: jal         0x800C25B8
    // 0x8001D73C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_11;
    // 0x8001D73C: nop

    after_11:
    // 0x8001D740: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8001D744: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001D748: jal         0x800C23E8
    // 0x8001D74C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_12;
    // 0x8001D74C: nop

    after_12:
L_8001D750:
    // 0x8001D750: b           L_8001D780
    // 0x8001D754: nop

        goto L_8001D780;
    // 0x8001D754: nop

L_8001D758:
    // 0x8001D758: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001D75C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8001D760: lwc1        $f12, 0x14($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8001D764: jal         0x800C25B8
    // 0x8001D768: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_13;
    // 0x8001D768: nop

    after_13:
    // 0x8001D76C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001D770: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001D774: lwc1        $f12, 0x10($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8001D778: jal         0x800C23E8
    // 0x8001D77C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_14;
    // 0x8001D77C: nop

    after_14:
L_8001D780:
    // 0x8001D780: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8001D784:
    // 0x8001D784: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001D788: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001D78C: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8001D790: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x8001D794: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8001D798: addiu       $t9, $t9, 0x2618
    ctx->r25 = ADD32(ctx->r25, 0X2618);
    // 0x8001D79C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8001D7A0: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x8001D7A4: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x8001D7A8: addu        $t4, $t6, $t1
    ctx->r12 = ADD32(ctx->r14, ctx->r9);
    // 0x8001D7AC: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8001D7B0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D7B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001D7B8: lwc1        $f8, 0xF0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XF0);
    // 0x8001D7BC: nop

    // 0x8001D7C0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8001D7C4: nop

    // 0x8001D7C8: bc1t        L_8001D7F0
    if (c1cs) {
        // 0x8001D7CC: nop

            goto L_8001D7F0;
    }
    // 0x8001D7CC: nop

    // 0x8001D7D0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D7D4: nop

    // 0x8001D7D8: lwc1        $f16, 0xF0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF0);
    // 0x8001D7DC: lwc1        $f18, 0xEC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XEC);
    // 0x8001D7E0: nop

    // 0x8001D7E4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001D7E8: b           L_8001D800
    // 0x8001D7EC: swc1        $f4, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f4.u32l;
        goto L_8001D800;
    // 0x8001D7EC: swc1        $f4, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f4.u32l;
L_8001D7F0:
    // 0x8001D7F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001D7F4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001D7F8: nop

    // 0x8001D7FC: swc1        $f6, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f6.u32l;
L_8001D800:
    // 0x8001D800: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D804: nop

    // 0x8001D808: lw          $t7, 0x12C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X12C);
    // 0x8001D80C: nop

    // 0x8001D810: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8001D814: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8001D818: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001D81C: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8001D820: nop

    // 0x8001D824: swc1        $f8, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f8.u32l;
    // 0x8001D828: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D82C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D830: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x8001D834: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001D838: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x8001D83C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8001D840: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001D844: jal         0x800BCFCC
    // 0x8001D848: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    SysMem_Copy8(rdram, ctx);
        goto after_15;
    // 0x8001D848: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    after_15:
    // 0x8001D84C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8001D850: nop

    // 0x8001D854: bne         $t3, $zero, L_8001D934
    if (ctx->r11 != 0) {
        // 0x8001D858: nop

            goto L_8001D934;
    }
    // 0x8001D858: nop

    // 0x8001D85C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001D860: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001D864: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8001D868: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x8001D86C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8001D870: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8001D874: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8001D878: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001D87C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8001D880: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8001D884: nop

    // 0x8001D888: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8001D88C: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x8001D890: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001D894: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001D898: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x8001D89C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001D8A0: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8001D8A4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8001D8A8: addu        $t0, $t6, $t3
    ctx->r8 = ADD32(ctx->r14, ctx->r11);
    // 0x8001D8AC: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8001D8B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D8B4: nop

    // 0x8001D8B8: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8001D8BC: nop

    // 0x8001D8C0: bc1f        L_8001D8E0
    if (!c1cs) {
        // 0x8001D8C4: nop

            goto L_8001D8E0;
    }
    // 0x8001D8C4: nop

    // 0x8001D8C8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D8CC: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D8D0: lw          $t7, 0xC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XC);
    // 0x8001D8D4: nop

    // 0x8001D8D8: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x8001D8DC: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
L_8001D8E0:
    // 0x8001D8E0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001D8E4: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001D8E8: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8001D8EC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001D8F0: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8001D8F4: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8001D8F8: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x8001D8FC: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8001D900: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D904: nop

    // 0x8001D908: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8001D90C: nop

    // 0x8001D910: bc1f        L_8001D92C
    if (!c1cs) {
        // 0x8001D914: nop

            goto L_8001D92C;
    }
    // 0x8001D914: nop

    // 0x8001D918: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001D91C: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001D920: lw          $t0, 0xC($t3)
    ctx->r8 = MEM_W(ctx->r11, 0XC);
    // 0x8001D924: nop

    // 0x8001D928: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
L_8001D92C:
    // 0x8001D92C: b           L_8001D958
    // 0x8001D930: nop

        goto L_8001D958;
    // 0x8001D930: nop

L_8001D934:
    // 0x8001D934: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001D938: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001D93C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8001D940: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8001D944: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001D948: lwc1        $f18, 0xE8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x8001D94C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8001D950: addu        $t2, $t5, $t1
    ctx->r10 = ADD32(ctx->r13, ctx->r9);
    // 0x8001D954: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
L_8001D958:
    // 0x8001D958: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8001D95C: nop

    // 0x8001D960: beq         $t4, $zero, L_8001D9F0
    if (ctx->r12 == 0) {
        // 0x8001D964: nop

            goto L_8001D9F0;
    }
    // 0x8001D964: nop

    // 0x8001D968: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001D96C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001D970: lwc1        $f4, 0xD0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8001D974: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001D978: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001D97C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001D980: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8001D984: nop

    // 0x8001D988: bc1f        L_8001D9B4
    if (!c1cs) {
        // 0x8001D98C: nop

            goto L_8001D9B4;
    }
    // 0x8001D98C: nop

    // 0x8001D990: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001D994: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001D998: lwc1        $f16, 0xD0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x8001D99C: lwc1        $f19, -0x2490($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2490);
    // 0x8001D9A0: lwc1        $f18, -0x248C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X248C);
    // 0x8001D9A4: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8001D9A8: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8001D9AC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001D9B0: swc1        $f6, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f6.u32l;
L_8001D9B4:
    // 0x8001D9B4: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001D9B8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001D9BC: lwc1        $f8, 0xD0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8001D9C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001D9C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001D9C8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8001D9CC: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8001D9D0: nop

    // 0x8001D9D4: bc1f        L_8001D9F0
    if (!c1cs) {
        // 0x8001D9D8: nop

            goto L_8001D9F0;
    }
    // 0x8001D9D8: nop

    // 0x8001D9DC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001D9E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D9E4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8001D9E8: nop

    // 0x8001D9EC: swc1        $f18, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f18.u32l;
L_8001D9F0:
    // 0x8001D9F0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8001D9F4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001D9F8: lwc1        $f4, 0xE4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XE4);
    // 0x8001D9FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001DA00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001DA04: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001DA08: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8001DA0C: nop

    // 0x8001DA10: bc1f        L_8001DA3C
    if (!c1cs) {
        // 0x8001DA14: nop

            goto L_8001DA3C;
    }
    // 0x8001DA14: nop

    // 0x8001DA18: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8001DA20: lwc1        $f16, 0xE4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XE4);
    // 0x8001DA24: lwc1        $f19, -0x2488($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X2488);
    // 0x8001DA28: lwc1        $f18, -0x2484($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2484);
    // 0x8001DA2C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8001DA30: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8001DA34: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001DA38: swc1        $f6, 0xE4($t9)
    MEM_W(0XE4, ctx->r25) = ctx->f6.u32l;
L_8001DA3C:
    // 0x8001DA3C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA40: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001DA44: lwc1        $f8, 0xE4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XE4);
    // 0x8001DA48: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001DA4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001DA50: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8001DA54: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8001DA58: nop

    // 0x8001DA5C: bc1f        L_8001DA78
    if (!c1cs) {
        // 0x8001DA60: nop

            goto L_8001DA78;
    }
    // 0x8001DA60: nop

    // 0x8001DA64: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001DA68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001DA6C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA70: nop

    // 0x8001DA74: swc1        $f18, 0xE4($t1)
    MEM_W(0XE4, ctx->r9) = ctx->f18.u32l;
L_8001DA78:
    // 0x8001DA78: jal         0x800C1680
    // 0x8001DA7C: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_16;
    // 0x8001DA7C: nop

    after_16:
    // 0x8001DA80: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA84: nop

    // 0x8001DA88: lwc1        $f12, 0xF0($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XF0);
    // 0x8001DA8C: jal         0x800C2780
    // 0x8001DA90: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_17;
    // 0x8001DA90: nop

    after_17:
    // 0x8001DA94: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8001DA98: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8001DA9C: lwc1        $f14, 0xD0($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8001DAA0: jal         0x800C2304
    // 0x8001DAA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_18;
    // 0x8001DAA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_18:
    // 0x8001DAA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001DAAC: jal         0x800997D8
    // 0x8001DAB0: nop

    func_800997D8(rdram, ctx);
        goto after_19;
    // 0x8001DAB0: nop

    after_19:
    // 0x8001DAB4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001DAB8: nop

    // 0x8001DABC: lwc1        $f12, 0xE8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8001DAC0: jal         0x800C2780
    // 0x8001DAC4: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_20;
    // 0x8001DAC4: nop

    after_20:
    // 0x8001DAC8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8001DACC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8001DAD0: lwc1        $f14, 0xE4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0XE4);
    // 0x8001DAD4: jal         0x800C2304
    // 0x8001DAD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_21;
    // 0x8001DAD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_21:
    // 0x8001DADC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8001DAE0: nop

    // 0x8001DAE4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8001DAE8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8001DAEC: nop

    // 0x8001DAF0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001DAF4: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x8001DAF8: bne         $at, $zero, L_8001D784
    if (ctx->r1 != 0) {
        // 0x8001DAFC: sw          $t8, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r24;
            goto L_8001D784;
    }
    // 0x8001DAFC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8001DB00: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8001DB04: nop

    // 0x8001DB08: blez        $t9, L_8001DB2C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001DB0C: nop

            goto L_8001DB2C;
    }
    // 0x8001DB0C: nop

L_8001DB10:
    // 0x8001DB10: jal         0x800C1A28
    // 0x8001DB14: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_22;
    // 0x8001DB14: nop

    after_22:
    // 0x8001DB18: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8001DB1C: nop

    // 0x8001DB20: addiu       $t1, $t5, -0x1
    ctx->r9 = ADD32(ctx->r13, -0X1);
    // 0x8001DB24: bgtz        $t1, L_8001DB10
    if (SIGNED(ctx->r9) > 0) {
        // 0x8001DB28: sw          $t1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r9;
            goto L_8001DB10;
    }
    // 0x8001DB28: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_8001DB2C:
    // 0x8001DB2C: jal         0x800C1A28
    // 0x8001DB30: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_23;
    // 0x8001DB30: nop

    after_23:
    // 0x8001DB34: b           L_8001DB44
    // 0x8001DB38: nop

        goto L_8001DB44;
    // 0x8001DB38: nop

L_8001DB3C:
    // 0x8001DB3C: b           L_8001DB44
    // 0x8001DB40: nop

        goto L_8001DB44;
    // 0x8001DB40: nop

L_8001DB44:
    // 0x8001DB44: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001DB48: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8001DB4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DB50: lhu         $t6, 0x11A4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X11A4);
    // 0x8001DB54: lhu         $t4, 0x6($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X6);
    // 0x8001DB58: nop

    // 0x8001DB5C: and         $t0, $t4, $t6
    ctx->r8 = ctx->r12 & ctx->r14;
    // 0x8001DB60: beq         $t0, $zero, L_8001DBE0
    if (ctx->r8 == 0) {
        // 0x8001DB64: nop

            goto L_8001DBE0;
    }
    // 0x8001DB64: nop

    // 0x8001DB68: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8001DB6C:
    // 0x8001DB6C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8001DB70: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DB74: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001DB78: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001DB7C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001DB80: addiu       $t3, $t3, 0x2618
    ctx->r11 = ADD32(ctx->r11, 0X2618);
    // 0x8001DB84: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8001DB88: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001DB8C: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8001DB90: addu        $t5, $t7, $t9
    ctx->r13 = ADD32(ctx->r15, ctx->r25);
    // 0x8001DB94: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8001DB98: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001DB9C: nop

    // 0x8001DBA0: lw          $a0, 0x12C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X12C);
    // 0x8001DBA4: jal         0x800BC980
    // 0x8001DBA8: nop

    SysMem_Free(rdram, ctx);
        goto after_24;
    // 0x8001DBA8: nop

    after_24:
    // 0x8001DBAC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001DBB0: nop

    // 0x8001DBB4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8001DBB8: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8001DBBC: bne         $at, $zero, L_8001DB6C
    if (ctx->r1 != 0) {
        // 0x8001DBC0: sw          $t4, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r12;
            goto L_8001DB6C;
    }
    // 0x8001DBC0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x8001DBC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DBC8: addiu       $t6, $t6, 0x2618
    ctx->r14 = ADD32(ctx->r14, 0X2618);
    // 0x8001DBCC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8001DBD0: jal         0x800BC980
    // 0x8001DBD4: nop

    SysMem_Free(rdram, ctx);
        goto after_25;
    // 0x8001DBD4: nop

    after_25:
    // 0x8001DBD8: b           L_8001DBF0
    // 0x8001DBDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001DBF0;
    // 0x8001DBDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001DBE0:
    // 0x8001DBE0: b           L_8001DBF0
    // 0x8001DBE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001DBF0;
    // 0x8001DBE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001DBE8: b           L_8001DBF0
    // 0x8001DBEC: nop

        goto L_8001DBF0;
    // 0x8001DBEC: nop

L_8001DBF0:
    // 0x8001DBF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DBF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DBF8: jr          $ra
    // 0x8001DBFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001DBFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8001DC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001DC04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DC08: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001DC0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DC10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001DC14: jal         0x8008EAA8
    // 0x8001DC18: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001DC18: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8001DC1C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001DC20: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DC24: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001DC28: jal         0x8008ECE4
    // 0x8001DC2C: addiu       $a0, $a0, -0x2660
    ctx->r4 = ADD32(ctx->r4, -0X2660);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001DC2C: addiu       $a0, $a0, -0x2660
    ctx->r4 = ADD32(ctx->r4, -0X2660);
    after_1:
    // 0x8001DC30: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001DC34: lw          $t7, 0x6B98($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6B98);
    // 0x8001DC38: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DC3C: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DC40: sw          $t7, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r15;
    // 0x8001DC44: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001DC48: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x8001DC4C: nop

    // 0x8001DC50: beq         $s0, $zero, L_8001DC6C
    if (ctx->r16 == 0) {
        // 0x8001DC54: nop

            goto L_8001DC6C;
    }
    // 0x8001DC54: nop

    // 0x8001DC58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001DC5C: beq         $s0, $at, L_8001DCC8
    if (ctx->r16 == ctx->r1) {
        // 0x8001DC60: nop

            goto L_8001DCC8;
    }
    // 0x8001DC60: nop

    // 0x8001DC64: b           L_8001E2E8
    // 0x8001DC68: nop

        goto L_8001E2E8;
    // 0x8001DC68: nop

L_8001DC6C:
    // 0x8001DC6C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001DC70: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001DC74: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001DC78: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8001DC7C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001DC80: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x8001DC84: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001DC88: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8001DC8C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DC90: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001DC94: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    // 0x8001DC98: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001DC9C: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001DCA0: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
    // 0x8001DCA4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8001DCA8: lw          $t5, -0x4DB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4DB8);
    // 0x8001DCAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DCB0: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001DCB4: sw          $t5, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r13;
    // 0x8001DCB8: lui         $t7, 0x7FFF
    ctx->r15 = S32(0X7FFF << 16);
    // 0x8001DCBC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8001DCC0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001DCC4: sw          $t7, -0x4DB8($at)
    MEM_W(-0X4DB8, ctx->r1) = ctx->r15;
L_8001DCC8:
    // 0x8001DCC8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001DCCC: jal         0x8008EAA8
    // 0x8001DCD0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008EAA8(rdram, ctx);
        goto after_2;
    // 0x8001DCD0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8001DCD4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DCD8: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DCDC: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8001DCE0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001DCE4: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8001DCE8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001DCEC: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001DCF0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8001DCF4: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x8001DCF8: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x8001DCFC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DD00: jal         0x8008ECE4
    // 0x8001DD04: addiu       $a0, $a0, -0x2654
    ctx->r4 = ADD32(ctx->r4, -0X2654);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001DD04: addiu       $a0, $a0, -0x2654
    ctx->r4 = ADD32(ctx->r4, -0X2654);
    after_3:
    // 0x8001DD08: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001DD0C: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001DD10: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DD14: lhu         $t3, 0x101C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X101C);
    // 0x8001DD18: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001DD1C: nop

    // 0x8001DD20: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001DD24: beq         $t4, $zero, L_8001DD44
    if (ctx->r12 == 0) {
        // 0x8001DD28: nop

            goto L_8001DD44;
    }
    // 0x8001DD28: nop

    // 0x8001DD2C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001DD30: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001DD34: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x8001DD38: nop

    // 0x8001DD3C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8001DD40: sw          $t7, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r15;
L_8001DD44:
    // 0x8001DD44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001DD48: jal         0x8008EAA8
    // 0x8001DD4C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_8008EAA8(rdram, ctx);
        goto after_4;
    // 0x8001DD4C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_4:
    // 0x8001DD50: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DD54: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DD58: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8001DD5C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001DD60: sw          $t9, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r25;
    // 0x8001DD64: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001DD68: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001DD6C: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8001DD70: nop

    // 0x8001DD74: bne         $t1, $zero, L_8001DE08
    if (ctx->r9 != 0) {
        // 0x8001DD78: nop

            goto L_8001DE08;
    }
    // 0x8001DD78: nop

    // 0x8001DD7C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DD80: jal         0x8008ECE4
    // 0x8001DD84: addiu       $a0, $a0, -0x2640
    ctx->r4 = ADD32(ctx->r4, -0X2640);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8001DD84: addiu       $a0, $a0, -0x2640
    ctx->r4 = ADD32(ctx->r4, -0X2640);
    after_5:
    // 0x8001DD88: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001DD8C: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8001DD90: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001DD94: lhu         $t4, 0x1260($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1260);
    // 0x8001DD98: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x8001DD9C: nop

    // 0x8001DDA0: and         $t6, $t3, $t4
    ctx->r14 = ctx->r11 & ctx->r12;
    // 0x8001DDA4: beq         $t6, $zero, L_8001DDC4
    if (ctx->r14 == 0) {
        // 0x8001DDA8: nop

            goto L_8001DDC4;
    }
    // 0x8001DDA8: nop

    // 0x8001DDAC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001DDB0: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001DDB4: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x8001DDB8: nop

    // 0x8001DDBC: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8001DDC0: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
L_8001DDC4:
    // 0x8001DDC4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001DDC8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001DDCC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001DDD0: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001DDD4: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001DDD8: nop

    // 0x8001DDDC: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001DDE0: beq         $t2, $zero, L_8001DE00
    if (ctx->r10 == 0) {
        // 0x8001DDE4: nop

            goto L_8001DE00;
    }
    // 0x8001DDE4: nop

    // 0x8001DDE8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DDEC: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001DDF0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8001DDF4: nop

    // 0x8001DDF8: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8001DDFC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
L_8001DE00:
    // 0x8001DE00: b           L_8001DE8C
    // 0x8001DE04: nop

        goto L_8001DE8C;
    // 0x8001DE04: nop

L_8001DE08:
    // 0x8001DE08: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DE0C: jal         0x8008ECE4
    // 0x8001DE10: addiu       $a0, $a0, -0x2634
    ctx->r4 = ADD32(ctx->r4, -0X2634);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8001DE10: addiu       $a0, $a0, -0x2634
    ctx->r4 = ADD32(ctx->r4, -0X2634);
    after_6:
    // 0x8001DE14: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001DE18: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001DE1C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001DE20: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001DE24: lhu         $t8, 0x8($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X8);
    // 0x8001DE28: nop

    // 0x8001DE2C: and         $t9, $t8, $t7
    ctx->r25 = ctx->r24 & ctx->r15;
    // 0x8001DE30: beq         $t9, $zero, L_8001DE50
    if (ctx->r25 == 0) {
        // 0x8001DE34: nop

            goto L_8001DE50;
    }
    // 0x8001DE34: nop

    // 0x8001DE38: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001DE3C: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001DE40: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8001DE44: nop

    // 0x8001DE48: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8001DE4C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
L_8001DE50:
    // 0x8001DE50: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001DE54: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8001DE58: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001DE5C: lhu         $t3, 0x1258($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1258);
    // 0x8001DE60: lhu         $t6, 0x8($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X8);
    // 0x8001DE64: nop

    // 0x8001DE68: and         $t5, $t6, $t3
    ctx->r13 = ctx->r14 & ctx->r11;
    // 0x8001DE6C: beq         $t5, $zero, L_8001DE8C
    if (ctx->r13 == 0) {
        // 0x8001DE70: nop

            goto L_8001DE8C;
    }
    // 0x8001DE70: nop

    // 0x8001DE74: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DE78: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DE7C: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8001DE80: nop

    // 0x8001DE84: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8001DE88: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
L_8001DE8C:
    // 0x8001DE8C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001DE90: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001DE94: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001DE98: nop

    // 0x8001DE9C: bgtz        $t2, L_8001DEB4
    if (SIGNED(ctx->r10) > 0) {
        // 0x8001DEA0: nop

            goto L_8001DEB4;
    }
    // 0x8001DEA0: nop

    // 0x8001DEA4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001DEA8: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001DEAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001DEB0: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
L_8001DEB4:
    // 0x8001DEB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DEB8: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001DEBC: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x8001DEC0: nop

    // 0x8001DEC4: bgtz        $t3, L_8001DEDC
    if (SIGNED(ctx->r11) > 0) {
        // 0x8001DEC8: nop

            goto L_8001DEDC;
    }
    // 0x8001DEC8: nop

    // 0x8001DECC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001DED0: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001DED4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001DED8: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
L_8001DEDC:
    // 0x8001DEDC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001DEE0: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001DEE4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001DEE8: lhu         $t1, 0xFF4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XFF4);
    // 0x8001DEEC: lhu         $t8, 0x8($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X8);
    // 0x8001DEF0: nop

    // 0x8001DEF4: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001DEF8: beq         $t2, $zero, L_8001DF18
    if (ctx->r10 == 0) {
        // 0x8001DEFC: nop

            goto L_8001DF18;
    }
    // 0x8001DEFC: nop

    // 0x8001DF00: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001DF04: lbu         $a0, 0x1918($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1918);
    // 0x8001DF08: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8001DF0C: addiu       $a1, $a1, -0x820
    ctx->r5 = ADD32(ctx->r5, -0X820);
    // 0x8001DF10: jal         0x800C1264
    // 0x8001DF14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_7;
    // 0x8001DF14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
L_8001DF18:
    // 0x8001DF18: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001DF1C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8001DF20: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001DF24: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8001DF28: lhu         $t4, 0x6($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X6);
    // 0x8001DF2C: nop

    // 0x8001DF30: and         $t3, $t4, $t6
    ctx->r11 = ctx->r12 & ctx->r14;
    // 0x8001DF34: beq         $t3, $zero, L_8001DF54
    if (ctx->r11 == 0) {
        // 0x8001DF38: nop

            goto L_8001DF54;
    }
    // 0x8001DF38: nop

    // 0x8001DF3C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001DF40: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001DF44: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8001DF48: nop

    // 0x8001DF4C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8001DF50: sw          $t9, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r25;
L_8001DF54:
    // 0x8001DF54: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DF58: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001DF5C: lw          $t1, 0x8($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X8);
    // 0x8001DF60: nop

    // 0x8001DF64: bgez        $t1, L_8001DF78
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001DF68: andi        $t2, $t1, 0x3
        ctx->r10 = ctx->r9 & 0X3;
            goto L_8001DF78;
    }
    // 0x8001DF68: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8001DF6C: beq         $t2, $zero, L_8001DF78
    if (ctx->r10 == 0) {
        // 0x8001DF70: nop

            goto L_8001DF78;
    }
    // 0x8001DF70: nop

    // 0x8001DF74: addiu       $t2, $t2, -0x4
    ctx->r10 = ADD32(ctx->r10, -0X4);
L_8001DF78:
    // 0x8001DF78: sw          $t2, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r10;
    // 0x8001DF7C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8001DF80: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8001DF84: nop

    // 0x8001DF88: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8001DF8C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8001DF90:
    // 0x8001DF90: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001DF94: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8001DF98: lw          $t6, 0xC0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC0);
    // 0x8001DF9C: nop

    // 0x8001DFA0: and         $t3, $t6, $at
    ctx->r11 = ctx->r14 & ctx->r1;
    // 0x8001DFA4: beq         $t3, $zero, L_8001E2C8
    if (ctx->r11 == 0) {
        // 0x8001DFA8: nop

            goto L_8001E2C8;
    }
    // 0x8001DFA8: nop

    // 0x8001DFAC: jal         0x800C1754
    // 0x8001DFB0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_8;
    // 0x8001DFB0: nop

    after_8:
    // 0x8001DFB4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001DFB8: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001DFBC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8001DFC0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DFC4: nop

    // 0x8001DFC8: bne         $t9, $t5, L_8001E298
    if (ctx->r25 != ctx->r13) {
        // 0x8001DFCC: nop

            goto L_8001E298;
    }
    // 0x8001DFCC: nop

    // 0x8001DFD0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001DFD4: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001DFD8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001DFDC: lhu         $t8, 0x126C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X126C);
    // 0x8001DFE0: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8001DFE4: nop

    // 0x8001DFE8: and         $t0, $t2, $t8
    ctx->r8 = ctx->r10 & ctx->r24;
    // 0x8001DFEC: beq         $t0, $zero, L_8001E00C
    if (ctx->r8 == 0) {
        // 0x8001DFF0: nop

            goto L_8001E00C;
    }
    // 0x8001DFF0: nop

    // 0x8001DFF4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001DFF8: nop

    // 0x8001DFFC: lw          $t6, 0xC0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC0);
    // 0x8001E000: nop

    // 0x8001E004: xori        $t3, $t6, 0x8
    ctx->r11 = ctx->r14 ^ 0X8;
    // 0x8001E008: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
L_8001E00C:
    // 0x8001E00C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E010: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001E014: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E018: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x8001E01C: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8001E020: nop

    // 0x8001E024: and         $t1, $t9, $t5
    ctx->r9 = ctx->r25 & ctx->r13;
    // 0x8001E028: beq         $t1, $zero, L_8001E06C
    if (ctx->r9 == 0) {
        // 0x8001E02C: nop

            goto L_8001E06C;
    }
    // 0x8001E02C: nop

    // 0x8001E030: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E034: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8001E038: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E03C: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E040: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001E044: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E048: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8001E04C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001E050: nop

    // 0x8001E054: lwc1        $f16, 0xCC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x8001E058: nop

    // 0x8001E05C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E060: sub.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f18.d - ctx->f10.d;
    // 0x8001E064: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8001E068: swc1        $f4, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f4.u32l;
L_8001E06C:
    // 0x8001E06C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001E070: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001E074: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001E078: lhu         $t6, 0xEEC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XEEC);
    // 0x8001E07C: lhu         $t0, 0x4($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X4);
    // 0x8001E080: nop

    // 0x8001E084: and         $t3, $t0, $t6
    ctx->r11 = ctx->r8 & ctx->r14;
    // 0x8001E088: beq         $t3, $zero, L_8001E0CC
    if (ctx->r11 == 0) {
        // 0x8001E08C: nop

            goto L_8001E0CC;
    }
    // 0x8001E08C: nop

    // 0x8001E090: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E094: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001E098: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E09C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E0A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001E0A4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E0A8: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8001E0AC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001E0B0: nop

    // 0x8001E0B4: lwc1        $f6, 0xCC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8001E0B8: nop

    // 0x8001E0BC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E0C0: add.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f4.d + ctx->f10.d;
    // 0x8001E0C4: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8001E0C8: swc1        $f8, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f8.u32l;
L_8001E0CC:
    // 0x8001E0CC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E0D0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001E0D4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E0D8: lhu         $t5, 0xE68($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XE68);
    // 0x8001E0DC: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8001E0E0: nop

    // 0x8001E0E4: and         $t1, $t9, $t5
    ctx->r9 = ctx->r25 & ctx->r13;
    // 0x8001E0E8: beq         $t1, $zero, L_8001E12C
    if (ctx->r9 == 0) {
        // 0x8001E0EC: nop

            goto L_8001E12C;
    }
    // 0x8001E0EC: nop

    // 0x8001E0F0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E0F4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001E0F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E0FC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E100: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001E104: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E108: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8001E10C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001E110: nop

    // 0x8001E114: lwc1        $f16, 0xD0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8001E118: nop

    // 0x8001E11C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E120: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x8001E124: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8001E128: swc1        $f18, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f18.u32l;
L_8001E12C:
    // 0x8001E12C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001E130: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001E134: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001E138: lhu         $t6, 0xE74($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XE74);
    // 0x8001E13C: lhu         $t0, 0x4($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X4);
    // 0x8001E140: nop

    // 0x8001E144: and         $t3, $t0, $t6
    ctx->r11 = ctx->r8 & ctx->r14;
    // 0x8001E148: beq         $t3, $zero, L_8001E18C
    if (ctx->r11 == 0) {
        // 0x8001E14C: nop

            goto L_8001E18C;
    }
    // 0x8001E14C: nop

    // 0x8001E150: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E154: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8001E158: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E15C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E160: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001E164: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E168: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8001E16C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001E170: nop

    // 0x8001E174: lwc1        $f6, 0xD0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8001E178: nop

    // 0x8001E17C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E180: sub.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f18.d - ctx->f10.d;
    // 0x8001E184: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8001E188: swc1        $f4, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f4.u32l;
L_8001E18C:
    // 0x8001E18C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E190: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001E194: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E198: lhu         $t5, 0x1038($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1038);
    // 0x8001E19C: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x8001E1A0: nop

    // 0x8001E1A4: and         $t1, $t9, $t5
    ctx->r9 = ctx->r25 & ctx->r13;
    // 0x8001E1A8: beq         $t1, $zero, L_8001E1EC
    if (ctx->r9 == 0) {
        // 0x8001E1AC: nop

            goto L_8001E1EC;
    }
    // 0x8001E1AC: nop

    // 0x8001E1B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E1B4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001E1B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E1BC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E1C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001E1C4: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E1C8: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8001E1CC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001E1D0: nop

    // 0x8001E1D4: lwc1        $f16, 0xD4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XD4);
    // 0x8001E1D8: nop

    // 0x8001E1DC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E1E0: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x8001E1E4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8001E1E8: swc1        $f8, 0xD4($t2)
    MEM_W(0XD4, ctx->r10) = ctx->f8.u32l;
L_8001E1EC:
    // 0x8001E1EC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001E1F0: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x8001E1F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001E1F8: lhu         $t6, 0x1042($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1042);
    // 0x8001E1FC: lhu         $t0, 0x4($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X4);
    // 0x8001E200: nop

    // 0x8001E204: and         $t3, $t0, $t6
    ctx->r11 = ctx->r8 & ctx->r14;
    // 0x8001E208: beq         $t3, $zero, L_8001E24C
    if (ctx->r11 == 0) {
        // 0x8001E20C: nop

            goto L_8001E24C;
    }
    // 0x8001E20C: nop

    // 0x8001E210: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001E214: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001E218: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E21C: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8001E220: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001E224: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8001E228: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8001E22C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001E230: nop

    // 0x8001E234: lwc1        $f6, 0xD4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XD4);
    // 0x8001E238: nop

    // 0x8001E23C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001E240: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8001E244: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8001E248: swc1        $f18, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f18.u32l;
L_8001E24C:
    // 0x8001E24C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001E250: nop

    // 0x8001E254: lh          $t9, 0x11E($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X11E);
    // 0x8001E258: nop

    // 0x8001E25C: bgez        $t9, L_8001E270
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001E260: nop

            goto L_8001E270;
    }
    // 0x8001E260: nop

    // 0x8001E264: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8001E268: nop

    // 0x8001E26C: sh          $zero, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = 0;
L_8001E270:
    // 0x8001E270: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001E274: nop

    // 0x8001E278: lh          $t2, 0x11E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X11E);
    // 0x8001E27C: nop

    // 0x8001E280: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    // 0x8001E284: bne         $at, $zero, L_8001E298
    if (ctx->r1 != 0) {
        // 0x8001E288: nop

            goto L_8001E298;
    }
    // 0x8001E288: nop

    // 0x8001E28C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001E290: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001E294: sh          $t8, 0x11E($t0)
    MEM_H(0X11E, ctx->r8) = ctx->r24;
L_8001E298:
    // 0x8001E298: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001E29C: jal         0x800A7230
    // 0x8001E2A0: nop

    func_800A7230(rdram, ctx);
        goto after_9;
    // 0x8001E2A0: nop

    after_9:
    // 0x8001E2A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001E2A8: jal         0x800997D8
    // 0x8001E2AC: nop

    func_800997D8(rdram, ctx);
        goto after_10;
    // 0x8001E2AC: nop

    after_10:
    // 0x8001E2B0: jal         0x800C1A28
    // 0x8001E2B4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_11;
    // 0x8001E2B4: nop

    after_11:
    // 0x8001E2B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8001E2BC: nop

    // 0x8001E2C0: addiu       $t3, $t6, 0x160
    ctx->r11 = ADD32(ctx->r14, 0X160);
    // 0x8001E2C4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_8001E2C8:
    // 0x8001E2C8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E2CC: nop

    // 0x8001E2D0: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x8001E2D4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8001E2D8: bne         $at, $zero, L_8001DF90
    if (ctx->r1 != 0) {
        // 0x8001E2DC: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_8001DF90;
    }
    // 0x8001E2DC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8001E2E0: b           L_8001E2E8
    // 0x8001E2E4: nop

        goto L_8001E2E8;
    // 0x8001E2E4: nop

L_8001E2E8:
    // 0x8001E2E8: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001E2EC: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001E2F0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001E2F4: lhu         $t1, 0x11A4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X11A4);
    // 0x8001E2F8: lhu         $t5, 0x6($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X6);
    // 0x8001E2FC: nop

    // 0x8001E300: and         $t2, $t5, $t1
    ctx->r10 = ctx->r13 & ctx->r9;
    // 0x8001E304: beq         $t2, $zero, L_8001E328
    if (ctx->r10 == 0) {
        // 0x8001E308: nop

            goto L_8001E328;
    }
    // 0x8001E308: nop

    // 0x8001E30C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001E310: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001E314: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x8001E318: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8001E31C: sw          $t0, -0x4DB8($at)
    MEM_W(-0X4DB8, ctx->r1) = ctx->r8;
    // 0x8001E320: b           L_8001E338
    // 0x8001E324: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001E338;
    // 0x8001E324: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001E328:
    // 0x8001E328: b           L_8001E338
    // 0x8001E32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001E338;
    // 0x8001E32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E330: b           L_8001E338
    // 0x8001E334: nop

        goto L_8001E338;
    // 0x8001E334: nop

L_8001E338:
    // 0x8001E338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E33C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E340: jr          $ra
    // 0x8001E344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001E344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001E348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E348: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001E34C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E350: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001E354: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E358: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001E35C: jal         0x8008EAA8
    // 0x8001E360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001E360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8001E364: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8001E368: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E36C: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001E370: jal         0x8008ECE4
    // 0x8001E374: addiu       $a0, $a0, -0x2628
    ctx->r4 = ADD32(ctx->r4, -0X2628);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001E374: addiu       $a0, $a0, -0x2628
    ctx->r4 = ADD32(ctx->r4, -0X2628);
    after_1:
    // 0x8001E378: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001E37C: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x8001E380: nop

    // 0x8001E384: beq         $s0, $zero, L_8001E3AC
    if (ctx->r16 == 0) {
        // 0x8001E388: nop

            goto L_8001E3AC;
    }
    // 0x8001E388: nop

    // 0x8001E38C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E390: beq         $s0, $at, L_8001E3C0
    if (ctx->r16 == ctx->r1) {
        // 0x8001E394: nop

            goto L_8001E3C0;
    }
    // 0x8001E394: nop

    // 0x8001E398: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001E39C: beq         $s0, $at, L_8001E574
    if (ctx->r16 == ctx->r1) {
        // 0x8001E3A0: nop

            goto L_8001E574;
    }
    // 0x8001E3A0: nop

    // 0x8001E3A4: b           L_8001E600
    // 0x8001E3A8: nop

        goto L_8001E600;
    // 0x8001E3A8: nop

L_8001E3AC:
    // 0x8001E3AC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001E3B0: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001E3B4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001E3B8: b           L_8001E608
    // 0x8001E3BC: nop

        goto L_8001E608;
    // 0x8001E3BC: nop

L_8001E3C0:
    // 0x8001E3C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001E3C4: jal         0x8008EAA8
    // 0x8001E3C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EAA8(rdram, ctx);
        goto after_2;
    // 0x8001E3C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x8001E3CC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E3D0: jal         0x8008ECE4
    // 0x8001E3D4: addiu       $a0, $a0, -0x261C
    ctx->r4 = ADD32(ctx->r4, -0X261C);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001E3D4: addiu       $a0, $a0, -0x261C
    ctx->r4 = ADD32(ctx->r4, -0X261C);
    after_3:
    // 0x8001E3D8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001E3DC: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001E3E0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001E3E4: nop

    // 0x8001E3E8: bne         $t9, $zero, L_8001E428
    if (ctx->r25 != 0) {
        // 0x8001E3EC: nop

            goto L_8001E428;
    }
    // 0x8001E3EC: nop

    // 0x8001E3F0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E3F4: jal         0x8008EAA8
    // 0x8001E3F8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8008EAA8(rdram, ctx);
        goto after_4;
    // 0x8001E3F8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x8001E3FC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E400: jal         0x8008ECE4
    // 0x8001E404: addiu       $a0, $a0, -0x25F0
    ctx->r4 = ADD32(ctx->r4, -0X25F0);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8001E404: addiu       $a0, $a0, -0x25F0
    ctx->r4 = ADD32(ctx->r4, -0X25F0);
    after_5:
    // 0x8001E408: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E40C: jal         0x8008EAA8
    // 0x8001E410: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8008EAA8(rdram, ctx);
        goto after_6;
    // 0x8001E410: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x8001E414: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E418: jal         0x8008ECE4
    // 0x8001E41C: addiu       $a0, $a0, -0x25E8
    ctx->r4 = ADD32(ctx->r4, -0X25E8);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8001E41C: addiu       $a0, $a0, -0x25E8
    ctx->r4 = ADD32(ctx->r4, -0X25E8);
    after_7:
    // 0x8001E420: b           L_8001E458
    // 0x8001E424: nop

        goto L_8001E458;
    // 0x8001E424: nop

L_8001E428:
    // 0x8001E428: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E42C: jal         0x8008EAA8
    // 0x8001E430: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8008EAA8(rdram, ctx);
        goto after_8;
    // 0x8001E430: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
    // 0x8001E434: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E438: jal         0x8008ECE4
    // 0x8001E43C: addiu       $a0, $a0, -0x25E0
    ctx->r4 = ADD32(ctx->r4, -0X25E0);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8001E43C: addiu       $a0, $a0, -0x25E0
    ctx->r4 = ADD32(ctx->r4, -0X25E0);
    after_9:
    // 0x8001E440: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E444: jal         0x8008EAA8
    // 0x8001E448: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8008EAA8(rdram, ctx);
        goto after_10;
    // 0x8001E448: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_10:
    // 0x8001E44C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E450: jal         0x8008ECE4
    // 0x8001E454: addiu       $a0, $a0, -0x25D8
    ctx->r4 = ADD32(ctx->r4, -0X25D8);
    func_8008ECE4(rdram, ctx);
        goto after_11;
    // 0x8001E454: addiu       $a0, $a0, -0x25D8
    ctx->r4 = ADD32(ctx->r4, -0X25D8);
    after_11:
L_8001E458:
    // 0x8001E458: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001E45C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8001E460: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001E464: lhu         $t2, 0xE68($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XE68);
    // 0x8001E468: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x8001E46C: nop

    // 0x8001E470: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8001E474: bne         $t3, $zero, L_8001E494
    if (ctx->r11 != 0) {
        // 0x8001E478: nop

            goto L_8001E494;
    }
    // 0x8001E478: nop

    // 0x8001E47C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001E480: lhu         $t4, 0xE74($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XE74);
    // 0x8001E484: nop

    // 0x8001E488: and         $t5, $t1, $t4
    ctx->r13 = ctx->r9 & ctx->r12;
    // 0x8001E48C: beq         $t5, $zero, L_8001E4AC
    if (ctx->r13 == 0) {
        // 0x8001E490: nop

            goto L_8001E4AC;
    }
    // 0x8001E490: nop

L_8001E494:
    // 0x8001E494: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001E498: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x8001E49C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001E4A0: nop

    // 0x8001E4A4: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x8001E4A8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_8001E4AC:
    // 0x8001E4AC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001E4B0: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001E4B4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001E4B8: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x8001E4BC: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8001E4C0: nop

    // 0x8001E4C4: and         $t3, $t0, $t2
    ctx->r11 = ctx->r8 & ctx->r10;
    // 0x8001E4C8: beq         $t3, $zero, L_8001E528
    if (ctx->r11 == 0) {
        // 0x8001E4CC: nop

            goto L_8001E528;
    }
    // 0x8001E4CC: nop

    // 0x8001E4D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001E4D4: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001E4D8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8001E4DC: nop

    // 0x8001E4E0: bne         $t4, $zero, L_8001E528
    if (ctx->r12 != 0) {
        // 0x8001E4E4: nop

            goto L_8001E528;
    }
    // 0x8001E4E4: nop

    // 0x8001E4E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8001E4EC: lw          $a0, 0x648($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X648);
    // 0x8001E4F0: jal         0x800BCB10
    // 0x8001E4F4: nop

    func_800BCB10(rdram, ctx);
        goto after_12;
    // 0x8001E4F4: nop

    after_12:
    // 0x8001E4F8: jal         0x8005D2B0
    // 0x8001E4FC: nop

    func_8005D2B0(rdram, ctx);
        goto after_13;
    // 0x8001E4FC: nop

    after_13:
    // 0x8001E500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E504: sw          $v0, 0x648($at)
    MEM_W(0X648, ctx->r1) = ctx->r2;
    // 0x8001E508: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E50C: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x8001E510: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8001E514: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001E518: lw          $t7, 0x25E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25E4);
    // 0x8001E51C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E520: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001E524: sw          $t8, 0x25E4($at)
    MEM_W(0X25E4, ctx->r1) = ctx->r24;
L_8001E528:
    // 0x8001E528: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001E52C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8001E530: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001E534: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x8001E538: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x8001E53C: nop

    // 0x8001E540: and         $t2, $t9, $t0
    ctx->r10 = ctx->r25 & ctx->r8;
    // 0x8001E544: beq         $t2, $zero, L_8001E56C
    if (ctx->r10 == 0) {
        // 0x8001E548: nop

            goto L_8001E56C;
    }
    // 0x8001E548: nop

    // 0x8001E54C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001E550: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001E554: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x8001E558: nop

    // 0x8001E55C: beq         $t1, $zero, L_8001E56C
    if (ctx->r9 == 0) {
        // 0x8001E560: nop

            goto L_8001E56C;
    }
    // 0x8001E560: nop

    // 0x8001E564: b           L_8001E644
    // 0x8001E568: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001E644;
    // 0x8001E568: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001E56C:
    // 0x8001E56C: b           L_8001E608
    // 0x8001E570: nop

        goto L_8001E608;
    // 0x8001E570: nop

L_8001E574:
    // 0x8001E574: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001E578: jal         0x8008EAA8
    // 0x8001E57C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EAA8(rdram, ctx);
        goto after_14;
    // 0x8001E57C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x8001E580: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E584: jal         0x8008ECE4
    // 0x8001E588: addiu       $a0, $a0, -0x25D0
    ctx->r4 = ADD32(ctx->r4, -0X25D0);
    func_8008ECE4(rdram, ctx);
        goto after_15;
    // 0x8001E588: addiu       $a0, $a0, -0x25D0
    ctx->r4 = ADD32(ctx->r4, -0X25D0);
    after_15:
    // 0x8001E58C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E590: jal         0x8008EAA8
    // 0x8001E594: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8008EAA8(rdram, ctx);
        goto after_16;
    // 0x8001E594: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_16:
    // 0x8001E598: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E59C: jal         0x8008ECE4
    // 0x8001E5A0: addiu       $a0, $a0, -0x25A4
    ctx->r4 = ADD32(ctx->r4, -0X25A4);
    func_8008ECE4(rdram, ctx);
        goto after_17;
    // 0x8001E5A0: addiu       $a0, $a0, -0x25A4
    ctx->r4 = ADD32(ctx->r4, -0X25A4);
    after_17:
    // 0x8001E5A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8001E5A8: jal         0x8008EAA8
    // 0x8001E5AC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8008EAA8(rdram, ctx);
        goto after_18;
    // 0x8001E5AC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_18:
    // 0x8001E5B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E5B4: jal         0x8008ECE4
    // 0x8001E5B8: addiu       $a0, $a0, -0x259C
    ctx->r4 = ADD32(ctx->r4, -0X259C);
    func_8008ECE4(rdram, ctx);
        goto after_19;
    // 0x8001E5B8: addiu       $a0, $a0, -0x259C
    ctx->r4 = ADD32(ctx->r4, -0X259C);
    after_19:
    // 0x8001E5BC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001E5C0: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001E5C4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8001E5C8: nop

    // 0x8001E5CC: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8001E5D0: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8001E5D4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001E5D8: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001E5DC: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x8001E5E0: nop

    // 0x8001E5E4: slti        $at, $t6, 0x79
    ctx->r1 = SIGNED(ctx->r14) < 0X79 ? 1 : 0;
    // 0x8001E5E8: bne         $at, $zero, L_8001E5F8
    if (ctx->r1 != 0) {
        // 0x8001E5EC: nop

            goto L_8001E5F8;
    }
    // 0x8001E5EC: nop

    // 0x8001E5F0: b           L_8001E644
    // 0x8001E5F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001E644;
    // 0x8001E5F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001E5F8:
    // 0x8001E5F8: b           L_8001E608
    // 0x8001E5FC: nop

        goto L_8001E608;
    // 0x8001E5FC: nop

L_8001E600:
    // 0x8001E600: b           L_8001E608
    // 0x8001E604: nop

        goto L_8001E608;
    // 0x8001E604: nop

L_8001E608:
    // 0x8001E608: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001E60C: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001E610: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8001E614: lhu         $t2, 0x11A4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X11A4);
    // 0x8001E618: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8001E61C: nop

    // 0x8001E620: and         $t3, $t0, $t2
    ctx->r11 = ctx->r8 & ctx->r10;
    // 0x8001E624: beq         $t3, $zero, L_8001E634
    if (ctx->r11 == 0) {
        // 0x8001E628: nop

            goto L_8001E634;
    }
    // 0x8001E628: nop

    // 0x8001E62C: b           L_8001E644
    // 0x8001E630: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001E644;
    // 0x8001E630: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001E634:
    // 0x8001E634: b           L_8001E644
    // 0x8001E638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001E644;
    // 0x8001E638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E63C: b           L_8001E644
    // 0x8001E640: nop

        goto L_8001E644;
    // 0x8001E640: nop

L_8001E644:
    // 0x8001E644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E648: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E64C: jr          $ra
    // 0x8001E650: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001E650: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001E654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E654: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001E658: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E65C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001E660: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E664: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001E668: jal         0x8008EAA8
    // 0x8001E66C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001E66C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8001E670: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8001E674: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E678: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001E67C: jal         0x8008ECE4
    // 0x8001E680: addiu       $a0, $a0, -0x2594
    ctx->r4 = ADD32(ctx->r4, -0X2594);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001E680: addiu       $a0, $a0, -0x2594
    ctx->r4 = ADD32(ctx->r4, -0X2594);
    after_1:
    // 0x8001E684: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001E688: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x8001E68C: nop

    // 0x8001E690: beq         $s0, $zero, L_8001E6AC
    if (ctx->r16 == 0) {
        // 0x8001E694: nop

            goto L_8001E6AC;
    }
    // 0x8001E694: nop

    // 0x8001E698: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E69C: beq         $s0, $at, L_8001E6B8
    if (ctx->r16 == ctx->r1) {
        // 0x8001E6A0: nop

            goto L_8001E6B8;
    }
    // 0x8001E6A0: nop

    // 0x8001E6A4: b           L_8001E934
    // 0x8001E6A8: nop

        goto L_8001E934;
    // 0x8001E6A8: nop

L_8001E6AC:
    // 0x8001E6AC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001E6B0: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8001E6B4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_8001E6B8:
    // 0x8001E6B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001E6BC: jal         0x8008EAA8
    // 0x8001E6C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EAA8(rdram, ctx);
        goto after_2;
    // 0x8001E6C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x8001E6C4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001E6C8: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8001E6CC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001E6D0: nop

    // 0x8001E6D4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8001E6D8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8001E6DC: addiu       $t0, $t0, -0x4C08
    ctx->r8 = ADD32(ctx->r8, -0X4C08);
    // 0x8001E6E0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8001E6E4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8001E6E8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8001E6EC:
    // 0x8001E6EC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8001E6F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E6F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001E6F8: nop

    // 0x8001E6FC: bne         $t2, $at, L_8001E70C
    if (ctx->r10 != ctx->r1) {
        // 0x8001E700: nop

            goto L_8001E70C;
    }
    // 0x8001E700: nop

    // 0x8001E704: b           L_8001E878
    // 0x8001E708: nop

        goto L_8001E878;
    // 0x8001E708: nop

L_8001E70C:
    // 0x8001E70C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8001E710: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001E714: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8001E718: nop

    // 0x8001E71C: beq         $t4, $at, L_8001E758
    if (ctx->r12 == ctx->r1) {
        // 0x8001E720: nop

            goto L_8001E758;
    }
    // 0x8001E720: nop

    // 0x8001E724: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8001E728: nop

    // 0x8001E72C: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x8001E730: lw          $a1, 0xC($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC);
    // 0x8001E734: jal         0x8008EAA8
    // 0x8001E738: nop

    func_8008EAA8(rdram, ctx);
        goto after_3;
    // 0x8001E738: nop

    after_3:
    // 0x8001E73C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8001E740: nop

    // 0x8001E744: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8001E748: nop

    // 0x8001E74C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001E750: b           L_8001E774
    // 0x8001E754: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_8001E774;
    // 0x8001E754: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_8001E758:
    // 0x8001E758: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8001E75C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001E760: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x8001E764: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001E768: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8001E76C: jal         0x8008EAA8
    // 0x8001E770: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_4;
    // 0x8001E770: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_4:
L_8001E774:
    // 0x8001E774: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8001E778: nop

    // 0x8001E77C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x8001E780: nop

    // 0x8001E784: beq         $t3, $zero, L_8001E848
    if (ctx->r11 == 0) {
        // 0x8001E788: nop

            goto L_8001E848;
    }
    // 0x8001E788: nop

    // 0x8001E78C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8001E790: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E794: nop

    // 0x8001E798: bne         $t4, $t5, L_8001E7F0
    if (ctx->r12 != ctx->r13) {
        // 0x8001E79C: nop

            goto L_8001E7F0;
    }
    // 0x8001E79C: nop

    // 0x8001E7A0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8001E7A4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E7A8: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001E7AC: jal         0x8008ECE4
    // 0x8001E7B0: addiu       $a0, $a0, -0x2588
    ctx->r4 = ADD32(ctx->r4, -0X2588);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8001E7B0: addiu       $a0, $a0, -0x2588
    ctx->r4 = ADD32(ctx->r4, -0X2588);
    after_5:
    // 0x8001E7B4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8001E7B8: nop

    // 0x8001E7BC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8001E7C0: nop

    // 0x8001E7C4: beq         $t8, $zero, L_8001E7E8
    if (ctx->r24 == 0) {
        // 0x8001E7C8: nop

            goto L_8001E7E8;
    }
    // 0x8001E7C8: nop

    // 0x8001E7CC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8001E7D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001E7D4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001E7D8: lw          $t9, 0x14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X14);
    // 0x8001E7DC: nop

    // 0x8001E7E0: jalr        $t9
    // 0x8001E7E4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8001E7E4: nop

    after_6:
L_8001E7E8:
    // 0x8001E7E8: b           L_8001E834
    // 0x8001E7EC: nop

        goto L_8001E834;
    // 0x8001E7EC: nop

L_8001E7F0:
    // 0x8001E7F0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001E7F4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E7F8: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x8001E7FC: jal         0x8008ECE4
    // 0x8001E800: addiu       $a0, $a0, -0x2584
    ctx->r4 = ADD32(ctx->r4, -0X2584);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8001E800: addiu       $a0, $a0, -0x2584
    ctx->r4 = ADD32(ctx->r4, -0X2584);
    after_7:
    // 0x8001E804: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8001E808: nop

    // 0x8001E80C: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8001E810: nop

    // 0x8001E814: beq         $t2, $zero, L_8001E834
    if (ctx->r10 == 0) {
        // 0x8001E818: nop

            goto L_8001E834;
    }
    // 0x8001E818: nop

    // 0x8001E81C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8001E820: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8001E824: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x8001E828: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8001E82C: jalr        $t9
    // 0x8001E830: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8001E830: nop

    after_8:
L_8001E834:
    // 0x8001E834: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E838: nop

    // 0x8001E83C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8001E840: b           L_8001E85C
    // 0x8001E844: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
        goto L_8001E85C;
    // 0x8001E844: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_8001E848:
    // 0x8001E848: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8001E84C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001E850: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8001E854: jal         0x8008ECE4
    // 0x8001E858: addiu       $a0, $a0, -0x2580
    ctx->r4 = ADD32(ctx->r4, -0X2580);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8001E858: addiu       $a0, $a0, -0x2580
    ctx->r4 = ADD32(ctx->r4, -0X2580);
    after_9:
L_8001E85C:
    // 0x8001E85C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8001E860: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8001E864: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001E868: addiu       $t1, $t0, 0x28
    ctx->r9 = ADD32(ctx->r8, 0X28);
    // 0x8001E86C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8001E870: b           L_8001E6EC
    // 0x8001E874: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_8001E6EC;
    // 0x8001E874: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_8001E878:
    // 0x8001E878: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8001E87C: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8001E880: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001E884: lhu         $t9, 0xE68($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XE68);
    // 0x8001E888: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x8001E88C: nop

    // 0x8001E890: and         $t4, $t3, $t9
    ctx->r12 = ctx->r11 & ctx->r25;
    // 0x8001E894: beq         $t4, $zero, L_8001E8AC
    if (ctx->r12 == 0) {
        // 0x8001E898: nop

            goto L_8001E8AC;
    }
    // 0x8001E898: nop

    // 0x8001E89C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8001E8A0: nop

    // 0x8001E8A4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8001E8A8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8001E8AC:
    // 0x8001E8AC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E8B0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001E8B4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001E8B8: lhu         $t0, 0xE74($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XE74);
    // 0x8001E8BC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001E8C0: nop

    // 0x8001E8C4: and         $t1, $t8, $t0
    ctx->r9 = ctx->r24 & ctx->r8;
    // 0x8001E8C8: beq         $t1, $zero, L_8001E8E0
    if (ctx->r9 == 0) {
        // 0x8001E8CC: nop

            goto L_8001E8E0;
    }
    // 0x8001E8CC: nop

    // 0x8001E8D0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8001E8D4: nop

    // 0x8001E8D8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8001E8DC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_8001E8E0:
    // 0x8001E8E0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001E8E4: nop

    // 0x8001E8E8: bgez        $t9, L_8001E900
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001E8EC: nop

            goto L_8001E900;
    }
    // 0x8001E8EC: nop

    // 0x8001E8F0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E8F4: nop

    // 0x8001E8F8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8001E8FC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8001E900:
    // 0x8001E900: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001E904: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E908: nop

    // 0x8001E90C: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001E910: bne         $at, $zero, L_8001E91C
    if (ctx->r1 != 0) {
        // 0x8001E914: nop

            goto L_8001E91C;
    }
    // 0x8001E914: nop

    // 0x8001E918: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8001E91C:
    // 0x8001E91C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8001E920: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001E924: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001E928: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8001E92C: b           L_8001E934
    // 0x8001E930: nop

        goto L_8001E934;
    // 0x8001E930: nop

L_8001E934:
    // 0x8001E934: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001E938: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001E93C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001E940: lhu         $t3, 0x11A4($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X11A4);
    // 0x8001E944: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8001E948: nop

    // 0x8001E94C: and         $t9, $t2, $t3
    ctx->r25 = ctx->r10 & ctx->r11;
    // 0x8001E950: beq         $t9, $zero, L_8001E960
    if (ctx->r25 == 0) {
        // 0x8001E954: nop

            goto L_8001E960;
    }
    // 0x8001E954: nop

    // 0x8001E958: b           L_8001E970
    // 0x8001E95C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8001E970;
    // 0x8001E95C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8001E960:
    // 0x8001E960: b           L_8001E970
    // 0x8001E964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001E970;
    // 0x8001E964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E968: b           L_8001E970
    // 0x8001E96C: nop

        goto L_8001E970;
    // 0x8001E96C: nop

L_8001E970:
    // 0x8001E970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E974: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E978: jr          $ra
    // 0x8001E97C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001E97C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8001E980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001E984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E988: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001E98C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001E990: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E994: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E998: nop

    // 0x8001E99C: bltz        $t6, L_8001EA64
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001E9A0: nop

            goto L_8001EA64;
    }
    // 0x8001E9A0: nop

    // 0x8001E9A4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E9A8: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001E9AC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001E9B0: lhu         $t9, 0xEC0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEC0);
    // 0x8001E9B4: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001E9B8: nop

    // 0x8001E9BC: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001E9C0: beq         $t0, $zero, L_8001E9DC
    if (ctx->r8 == 0) {
        // 0x8001E9C4: nop

            goto L_8001E9DC;
    }
    // 0x8001E9C4: nop

    // 0x8001E9C8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001E9CC: lw          $t1, 0x1680($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1680);
    // 0x8001E9D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001E9D4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8001E9D8: sw          $t2, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r10;
L_8001E9DC:
    // 0x8001E9DC: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001E9E0: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001E9E4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001E9E8: lhu         $t5, 0xEEC($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEEC);
    // 0x8001E9EC: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001E9F0: nop

    // 0x8001E9F4: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001E9F8: beq         $t6, $zero, L_8001EA14
    if (ctx->r14 == 0) {
        // 0x8001E9FC: nop

            goto L_8001EA14;
    }
    // 0x8001E9FC: nop

    // 0x8001EA00: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001EA04: lw          $t7, 0x1680($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1680);
    // 0x8001EA08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001EA0C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001EA10: sw          $t8, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r24;
L_8001EA14:
    // 0x8001EA14: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EA18: lw          $t9, 0x1680($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1680);
    // 0x8001EA1C: nop

    // 0x8001EA20: bgez        $t9, L_8001EA30
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001EA24: nop

            goto L_8001EA30;
    }
    // 0x8001EA24: nop

    // 0x8001EA28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001EA2C: sw          $zero, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = 0;
L_8001EA30:
    // 0x8001EA30: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001EA34: lw          $t0, 0x1680($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1680);
    // 0x8001EA38: nop

    // 0x8001EA3C: sltiu       $at, $t0, 0x4
    ctx->r1 = ctx->r8 < 0X4 ? 1 : 0;
    // 0x8001EA40: bne         $at, $zero, L_8001EA54
    if (ctx->r1 != 0) {
        // 0x8001EA44: nop

            goto L_8001EA54;
    }
    // 0x8001EA44: nop

    // 0x8001EA48: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8001EA4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001EA50: sw          $t1, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r9;
L_8001EA54:
    // 0x8001EA54: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8001EA58: lw          $a0, 0x1680($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1680);
    // 0x8001EA5C: jal         0x800BD9D0
    // 0x8001EA60: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800BD9D0(rdram, ctx);
        goto after_0;
    // 0x8001EA60: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
L_8001EA64:
    // 0x8001EA64: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001EA68: lw          $s0, 0x1680($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X1680);
    // 0x8001EA6C: nop

    // 0x8001EA70: beq         $s0, $zero, L_8001EAA4
    if (ctx->r16 == 0) {
        // 0x8001EA74: nop

            goto L_8001EAA4;
    }
    // 0x8001EA74: nop

    // 0x8001EA78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001EA7C: beq         $s0, $at, L_8001EAB8
    if (ctx->r16 == ctx->r1) {
        // 0x8001EA80: nop

            goto L_8001EAB8;
    }
    // 0x8001EA80: nop

    // 0x8001EA84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001EA88: beq         $s0, $at, L_8001EACC
    if (ctx->r16 == ctx->r1) {
        // 0x8001EA8C: nop

            goto L_8001EACC;
    }
    // 0x8001EA8C: nop

    // 0x8001EA90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001EA94: beq         $s0, $at, L_8001EAE0
    if (ctx->r16 == ctx->r1) {
        // 0x8001EA98: nop

            goto L_8001EAE0;
    }
    // 0x8001EA98: nop

    // 0x8001EA9C: b           L_8001EAF4
    // 0x8001EAA0: nop

        goto L_8001EAF4;
    // 0x8001EAA0: nop

L_8001EAA4:
    // 0x8001EAA4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EAA8: jal         0x8008ECE4
    // 0x8001EAAC: addiu       $a0, $a0, -0x257C
    ctx->r4 = ADD32(ctx->r4, -0X257C);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001EAAC: addiu       $a0, $a0, -0x257C
    ctx->r4 = ADD32(ctx->r4, -0X257C);
    after_1:
    // 0x8001EAB0: b           L_8001EAF4
    // 0x8001EAB4: nop

        goto L_8001EAF4;
    // 0x8001EAB4: nop

L_8001EAB8:
    // 0x8001EAB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EABC: jal         0x8008ECE4
    // 0x8001EAC0: addiu       $a0, $a0, -0x255C
    ctx->r4 = ADD32(ctx->r4, -0X255C);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001EAC0: addiu       $a0, $a0, -0x255C
    ctx->r4 = ADD32(ctx->r4, -0X255C);
    after_2:
    // 0x8001EAC4: b           L_8001EAF4
    // 0x8001EAC8: nop

        goto L_8001EAF4;
    // 0x8001EAC8: nop

L_8001EACC:
    // 0x8001EACC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EAD0: jal         0x8008ECE4
    // 0x8001EAD4: addiu       $a0, $a0, -0x253C
    ctx->r4 = ADD32(ctx->r4, -0X253C);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001EAD4: addiu       $a0, $a0, -0x253C
    ctx->r4 = ADD32(ctx->r4, -0X253C);
    after_3:
    // 0x8001EAD8: b           L_8001EAF4
    // 0x8001EADC: nop

        goto L_8001EAF4;
    // 0x8001EADC: nop

L_8001EAE0:
    // 0x8001EAE0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EAE4: jal         0x8008ECE4
    // 0x8001EAE8: addiu       $a0, $a0, -0x251C
    ctx->r4 = ADD32(ctx->r4, -0X251C);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8001EAE8: addiu       $a0, $a0, -0x251C
    ctx->r4 = ADD32(ctx->r4, -0X251C);
    after_4:
    // 0x8001EAEC: b           L_8001EAF4
    // 0x8001EAF0: nop

        goto L_8001EAF4;
    // 0x8001EAF0: nop

L_8001EAF4:
    // 0x8001EAF4: b           L_8001EB04
    // 0x8001EAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EB04;
    // 0x8001EAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EAFC: b           L_8001EB04
    // 0x8001EB00: nop

        goto L_8001EB04;
    // 0x8001EB00: nop

L_8001EB04:
    // 0x8001EB04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EB08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001EB0C: jr          $ra
    // 0x8001EB10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001EB10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001EB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EB14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EB18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EB1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001EB20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001EB24: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EB28: nop

    // 0x8001EB2C: bltz        $t6, L_8001EBA0
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001EB30: nop

            goto L_8001EBA0;
    }
    // 0x8001EB30: nop

    // 0x8001EB34: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EB38: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EB3C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EB40: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001EB44: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001EB48: nop

    // 0x8001EB4C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001EB50: bne         $t0, $zero, L_8001EB70
    if (ctx->r8 != 0) {
        // 0x8001EB54: nop

            goto L_8001EB70;
    }
    // 0x8001EB54: nop

    // 0x8001EB58: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001EB5C: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001EB60: nop

    // 0x8001EB64: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001EB68: beq         $t2, $zero, L_8001EBA0
    if (ctx->r10 == 0) {
        // 0x8001EB6C: nop

            goto L_8001EBA0;
    }
    // 0x8001EB6C: nop

L_8001EB70:
    // 0x8001EB70: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001EB74: lw          $t3, 0x168C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X168C);
    // 0x8001EB78: nop

    // 0x8001EB7C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8001EB80: beq         $t4, $zero, L_8001EB98
    if (ctx->r12 == 0) {
        // 0x8001EB84: nop

            goto L_8001EB98;
    }
    // 0x8001EB84: nop

    // 0x8001EB88: jal         0x800BDA58
    // 0x8001EB8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800BDA58(rdram, ctx);
        goto after_0;
    // 0x8001EB8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8001EB90: b           L_8001EBA0
    // 0x8001EB94: nop

        goto L_8001EBA0;
    // 0x8001EB94: nop

L_8001EB98:
    // 0x8001EB98: jal         0x800BDA58
    // 0x8001EB9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BDA58(rdram, ctx);
        goto after_1;
    // 0x8001EB9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_8001EBA0:
    // 0x8001EBA0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001EBA4: lw          $t5, 0x168C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X168C);
    // 0x8001EBA8: nop

    // 0x8001EBAC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8001EBB0: beq         $t6, $zero, L_8001EBCC
    if (ctx->r14 == 0) {
        // 0x8001EBB4: nop

            goto L_8001EBCC;
    }
    // 0x8001EBB4: nop

    // 0x8001EBB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EBBC: jal         0x8008ECE4
    // 0x8001EBC0: addiu       $a0, $a0, -0x24FC
    ctx->r4 = ADD32(ctx->r4, -0X24FC);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001EBC0: addiu       $a0, $a0, -0x24FC
    ctx->r4 = ADD32(ctx->r4, -0X24FC);
    after_2:
    // 0x8001EBC4: b           L_8001EBD8
    // 0x8001EBC8: nop

        goto L_8001EBD8;
    // 0x8001EBC8: nop

L_8001EBCC:
    // 0x8001EBCC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EBD0: jal         0x8008ECE4
    // 0x8001EBD4: addiu       $a0, $a0, -0x24F4
    ctx->r4 = ADD32(ctx->r4, -0X24F4);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001EBD4: addiu       $a0, $a0, -0x24F4
    ctx->r4 = ADD32(ctx->r4, -0X24F4);
    after_3:
L_8001EBD8:
    // 0x8001EBD8: b           L_8001EBE8
    // 0x8001EBDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EBE8;
    // 0x8001EBDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EBE0: b           L_8001EBE8
    // 0x8001EBE4: nop

        goto L_8001EBE8;
    // 0x8001EBE4: nop

L_8001EBE8:
    // 0x8001EBE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EBEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001EBF0: jr          $ra
    // 0x8001EBF4: nop

    return;
    // 0x8001EBF4: nop

;}
RECOMP_FUNC void func_8001EBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EBF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EBFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EC00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001EC04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001EC08: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EC0C: nop

    // 0x8001EC10: bltz        $t6, L_8001EC84
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001EC14: nop

            goto L_8001EC84;
    }
    // 0x8001EC14: nop

    // 0x8001EC18: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EC1C: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EC20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EC24: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001EC28: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001EC2C: nop

    // 0x8001EC30: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001EC34: bne         $t0, $zero, L_8001EC54
    if (ctx->r8 != 0) {
        // 0x8001EC38: nop

            goto L_8001EC54;
    }
    // 0x8001EC38: nop

    // 0x8001EC3C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001EC40: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001EC44: nop

    // 0x8001EC48: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001EC4C: beq         $t2, $zero, L_8001EC84
    if (ctx->r10 == 0) {
        // 0x8001EC50: nop

            goto L_8001EC84;
    }
    // 0x8001EC50: nop

L_8001EC54:
    // 0x8001EC54: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001EC58: lw          $t3, 0x168C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X168C);
    // 0x8001EC5C: nop

    // 0x8001EC60: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x8001EC64: beq         $t4, $zero, L_8001EC7C
    if (ctx->r12 == 0) {
        // 0x8001EC68: nop

            goto L_8001EC7C;
    }
    // 0x8001EC68: nop

    // 0x8001EC6C: jal         0x800BDA58
    // 0x8001EC70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800BDA58(rdram, ctx);
        goto after_0;
    // 0x8001EC70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x8001EC74: b           L_8001EC84
    // 0x8001EC78: nop

        goto L_8001EC84;
    // 0x8001EC78: nop

L_8001EC7C:
    // 0x8001EC7C: jal         0x800BDA58
    // 0x8001EC80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800BDA58(rdram, ctx);
        goto after_1;
    // 0x8001EC80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
L_8001EC84:
    // 0x8001EC84: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001EC88: lw          $t5, 0x168C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X168C);
    // 0x8001EC8C: nop

    // 0x8001EC90: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x8001EC94: beq         $t6, $zero, L_8001ECB0
    if (ctx->r14 == 0) {
        // 0x8001EC98: nop

            goto L_8001ECB0;
    }
    // 0x8001EC98: nop

    // 0x8001EC9C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001ECA0: jal         0x8008ECE4
    // 0x8001ECA4: addiu       $a0, $a0, -0x24EC
    ctx->r4 = ADD32(ctx->r4, -0X24EC);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001ECA4: addiu       $a0, $a0, -0x24EC
    ctx->r4 = ADD32(ctx->r4, -0X24EC);
    after_2:
    // 0x8001ECA8: b           L_8001ECBC
    // 0x8001ECAC: nop

        goto L_8001ECBC;
    // 0x8001ECAC: nop

L_8001ECB0:
    // 0x8001ECB0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001ECB4: jal         0x8008ECE4
    // 0x8001ECB8: addiu       $a0, $a0, -0x24E4
    ctx->r4 = ADD32(ctx->r4, -0X24E4);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001ECB8: addiu       $a0, $a0, -0x24E4
    ctx->r4 = ADD32(ctx->r4, -0X24E4);
    after_3:
L_8001ECBC:
    // 0x8001ECBC: b           L_8001ECCC
    // 0x8001ECC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001ECCC;
    // 0x8001ECC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001ECC4: b           L_8001ECCC
    // 0x8001ECC8: nop

        goto L_8001ECCC;
    // 0x8001ECC8: nop

L_8001ECCC:
    // 0x8001ECCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ECD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001ECD4: jr          $ra
    // 0x8001ECD8: nop

    return;
    // 0x8001ECD8: nop

;}
RECOMP_FUNC void func_8001ECDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ECDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001ECE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ECE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001ECE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001ECEC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ECF0: nop

    // 0x8001ECF4: bltz        $t6, L_8001ED68
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001ECF8: nop

            goto L_8001ED68;
    }
    // 0x8001ECF8: nop

    // 0x8001ECFC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001ED00: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001ED04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001ED08: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001ED0C: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001ED10: nop

    // 0x8001ED14: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001ED18: bne         $t0, $zero, L_8001ED38
    if (ctx->r8 != 0) {
        // 0x8001ED1C: nop

            goto L_8001ED38;
    }
    // 0x8001ED1C: nop

    // 0x8001ED20: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001ED24: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x8001ED28: nop

    // 0x8001ED2C: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8001ED30: beq         $t2, $zero, L_8001ED68
    if (ctx->r10 == 0) {
        // 0x8001ED34: nop

            goto L_8001ED68;
    }
    // 0x8001ED34: nop

L_8001ED38:
    // 0x8001ED38: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001ED3C: lw          $t3, 0x168C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X168C);
    // 0x8001ED40: nop

    // 0x8001ED44: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x8001ED48: beq         $t4, $zero, L_8001ED60
    if (ctx->r12 == 0) {
        // 0x8001ED4C: nop

            goto L_8001ED60;
    }
    // 0x8001ED4C: nop

    // 0x8001ED50: jal         0x800BDA58
    // 0x8001ED54: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800BDA58(rdram, ctx);
        goto after_0;
    // 0x8001ED54: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x8001ED58: b           L_8001ED68
    // 0x8001ED5C: nop

        goto L_8001ED68;
    // 0x8001ED5C: nop

L_8001ED60:
    // 0x8001ED60: jal         0x800BDA58
    // 0x8001ED64: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800BDA58(rdram, ctx);
        goto after_1;
    // 0x8001ED64: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
L_8001ED68:
    // 0x8001ED68: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001ED6C: lw          $t5, 0x168C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X168C);
    // 0x8001ED70: nop

    // 0x8001ED74: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x8001ED78: beq         $t6, $zero, L_8001ED94
    if (ctx->r14 == 0) {
        // 0x8001ED7C: nop

            goto L_8001ED94;
    }
    // 0x8001ED7C: nop

    // 0x8001ED80: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001ED84: jal         0x8008ECE4
    // 0x8001ED88: addiu       $a0, $a0, -0x24DC
    ctx->r4 = ADD32(ctx->r4, -0X24DC);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001ED88: addiu       $a0, $a0, -0x24DC
    ctx->r4 = ADD32(ctx->r4, -0X24DC);
    after_2:
    // 0x8001ED8C: b           L_8001EDA0
    // 0x8001ED90: nop

        goto L_8001EDA0;
    // 0x8001ED90: nop

L_8001ED94:
    // 0x8001ED94: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001ED98: jal         0x8008ECE4
    // 0x8001ED9C: addiu       $a0, $a0, -0x24D4
    ctx->r4 = ADD32(ctx->r4, -0X24D4);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001ED9C: addiu       $a0, $a0, -0x24D4
    ctx->r4 = ADD32(ctx->r4, -0X24D4);
    after_3:
L_8001EDA0:
    // 0x8001EDA0: b           L_8001EDB0
    // 0x8001EDA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EDB0;
    // 0x8001EDA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EDA8: b           L_8001EDB0
    // 0x8001EDAC: nop

        goto L_8001EDB0;
    // 0x8001EDAC: nop

L_8001EDB0:
    // 0x8001EDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EDB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001EDB8: jr          $ra
    // 0x8001EDBC: nop

    return;
    // 0x8001EDBC: nop

;}
RECOMP_FUNC void func_8001EDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EDC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EDC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001EDCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001EDD0: jal         0x800BDA58
    // 0x8001EDD4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800BDA58(rdram, ctx);
        goto after_0;
    // 0x8001EDD4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x8001EDD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001EDDC: lw          $t6, 0x168C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X168C);
    // 0x8001EDE0: nop

    // 0x8001EDE4: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8001EDE8: beq         $t7, $zero, L_8001EE04
    if (ctx->r15 == 0) {
        // 0x8001EDEC: nop

            goto L_8001EE04;
    }
    // 0x8001EDEC: nop

    // 0x8001EDF0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EDF4: jal         0x8008ECE4
    // 0x8001EDF8: addiu       $a0, $a0, -0x24CC
    ctx->r4 = ADD32(ctx->r4, -0X24CC);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001EDF8: addiu       $a0, $a0, -0x24CC
    ctx->r4 = ADD32(ctx->r4, -0X24CC);
    after_1:
    // 0x8001EDFC: b           L_8001EE10
    // 0x8001EE00: nop

        goto L_8001EE10;
    // 0x8001EE00: nop

L_8001EE04:
    // 0x8001EE04: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001EE08: jal         0x8008ECE4
    // 0x8001EE0C: addiu       $a0, $a0, -0x24C4
    ctx->r4 = ADD32(ctx->r4, -0X24C4);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x8001EE0C: addiu       $a0, $a0, -0x24C4
    ctx->r4 = ADD32(ctx->r4, -0X24C4);
    after_2:
L_8001EE10:
    // 0x8001EE10: b           L_8001EE20
    // 0x8001EE14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001EE20;
    // 0x8001EE14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001EE18: b           L_8001EE20
    // 0x8001EE1C: nop

        goto L_8001EE20;
    // 0x8001EE1C: nop

L_8001EE20:
    // 0x8001EE20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EE24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001EE28: jr          $ra
    // 0x8001EE2C: nop

    return;
    // 0x8001EE2C: nop

;}
RECOMP_FUNC void func_8001EE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EE30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001EE34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EE38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001EE3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001EE40: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001EE44: nop

    // 0x8001EE48: bltz        $t6, L_8001F098
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001EE4C: nop

            goto L_8001F098;
    }
    // 0x8001EE4C: nop

    // 0x8001EE50: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EE54: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EE58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EE5C: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001EE60: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001EE64: nop

    // 0x8001EE68: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001EE6C: beq         $t0, $zero, L_8001EE88
    if (ctx->r8 == 0) {
        // 0x8001EE70: nop

            goto L_8001EE88;
    }
    // 0x8001EE70: nop

    // 0x8001EE74: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8001EE78: lw          $t1, -0x4A0C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4A0C);
    // 0x8001EE7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EE80: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001EE84: sw          $t2, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r10;
L_8001EE88:
    // 0x8001EE88: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001EE8C: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001EE90: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001EE94: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001EE98: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001EE9C: nop

    // 0x8001EEA0: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001EEA4: beq         $t6, $zero, L_8001EEC0
    if (ctx->r14 == 0) {
        // 0x8001EEA8: nop

            goto L_8001EEC0;
    }
    // 0x8001EEA8: nop

    // 0x8001EEAC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8001EEB0: lw          $t7, -0x4A0C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4A0C);
    // 0x8001EEB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EEB8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001EEBC: sw          $t8, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r24;
L_8001EEC0:
    // 0x8001EEC0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001EEC4: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001EEC8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001EECC: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001EED0: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001EED4: nop

    // 0x8001EED8: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001EEDC: beq         $t2, $zero, L_8001EEF8
    if (ctx->r10 == 0) {
        // 0x8001EEE0: nop

            goto L_8001EEF8;
    }
    // 0x8001EEE0: nop

    // 0x8001EEE4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8001EEE8: lw          $t3, -0x4A0C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4A0C);
    // 0x8001EEEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EEF0: addiu       $t4, $t3, 0xA
    ctx->r12 = ADD32(ctx->r11, 0XA);
    // 0x8001EEF4: sw          $t4, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r12;
L_8001EEF8:
    // 0x8001EEF8: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001EEFC: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001EF00: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001EF04: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001EF08: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8001EF0C: nop

    // 0x8001EF10: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001EF14: beq         $t8, $zero, L_8001EF30
    if (ctx->r24 == 0) {
        // 0x8001EF18: nop

            goto L_8001EF30;
    }
    // 0x8001EF18: nop

    // 0x8001EF1C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001EF20: lw          $t9, -0x4A0C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4A0C);
    // 0x8001EF24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EF28: addiu       $t0, $t9, -0xA
    ctx->r8 = ADD32(ctx->r25, -0XA);
    // 0x8001EF2C: sw          $t0, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r8;
L_8001EF30:
    // 0x8001EF30: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001EF34: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001EF38: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001EF3C: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8001EF40: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001EF44: nop

    // 0x8001EF48: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001EF4C: beq         $t4, $zero, L_8001EF68
    if (ctx->r12 == 0) {
        // 0x8001EF50: nop

            goto L_8001EF68;
    }
    // 0x8001EF50: nop

    // 0x8001EF54: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8001EF58: lw          $t5, -0x4A0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4A0C);
    // 0x8001EF5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EF60: addiu       $t6, $t5, 0x64
    ctx->r14 = ADD32(ctx->r13, 0X64);
    // 0x8001EF64: sw          $t6, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r14;
L_8001EF68:
    // 0x8001EF68: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EF6C: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EF70: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EF74: lhu         $t9, 0x11AC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X11AC);
    // 0x8001EF78: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001EF7C: nop

    // 0x8001EF80: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001EF84: beq         $t0, $zero, L_8001EFA0
    if (ctx->r8 == 0) {
        // 0x8001EF88: nop

            goto L_8001EFA0;
    }
    // 0x8001EF88: nop

    // 0x8001EF8C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8001EF90: lw          $t1, -0x4A0C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4A0C);
    // 0x8001EF94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EF98: addiu       $t2, $t1, -0x64
    ctx->r10 = ADD32(ctx->r9, -0X64);
    // 0x8001EF9C: sw          $t2, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r10;
L_8001EFA0:
    // 0x8001EFA0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8001EFA4: lw          $t3, -0x4A0C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4A0C);
    // 0x8001EFA8: nop

    // 0x8001EFAC: bgtz        $t3, L_8001EFC0
    if (SIGNED(ctx->r11) > 0) {
        // 0x8001EFB0: nop

            goto L_8001EFC0;
    }
    // 0x8001EFB0: nop

    // 0x8001EFB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001EFB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EFBC: sw          $t4, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r12;
L_8001EFC0:
    // 0x8001EFC0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8001EFC4: lw          $t5, -0x4A0C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4A0C);
    // 0x8001EFC8: nop

    // 0x8001EFCC: slti        $at, $t5, 0x201
    ctx->r1 = SIGNED(ctx->r13) < 0X201 ? 1 : 0;
    // 0x8001EFD0: bne         $at, $zero, L_8001EFE4
    if (ctx->r1 != 0) {
        // 0x8001EFD4: nop

            goto L_8001EFE4;
    }
    // 0x8001EFD4: nop

    // 0x8001EFD8: addiu       $t6, $zero, 0x200
    ctx->r14 = ADD32(0, 0X200);
    // 0x8001EFDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001EFE0: sw          $t6, -0x4A0C($at)
    MEM_W(-0X4A0C, ctx->r1) = ctx->r14;
L_8001EFE4:
    // 0x8001EFE4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001EFE8: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001EFEC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001EFF0: lhu         $t9, 0x10F2($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X10F2);
    // 0x8001EFF4: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x8001EFF8: nop

    // 0x8001EFFC: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001F000: beq         $t0, $zero, L_8001F048
    if (ctx->r8 == 0) {
        // 0x8001F004: nop

            goto L_8001F048;
    }
    // 0x8001F004: nop

    // 0x8001F008: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F00C: lw          $a0, -0x4A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A0C);
    // 0x8001F010: jal         0x8005F064
    // 0x8001F014: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8001F014: nop

    after_0:
    // 0x8001F018: beq         $v0, $zero, L_8001F038
    if (ctx->r2 == 0) {
        // 0x8001F01C: nop

            goto L_8001F038;
    }
    // 0x8001F01C: nop

    // 0x8001F020: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F024: lw          $a0, -0x4A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A0C);
    // 0x8001F028: jal         0x8005F268
    // 0x8001F02C: nop

    func_8005F268(rdram, ctx);
        goto after_1;
    // 0x8001F02C: nop

    after_1:
    // 0x8001F030: b           L_8001F048
    // 0x8001F034: nop

        goto L_8001F048;
    // 0x8001F034: nop

L_8001F038:
    // 0x8001F038: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F03C: lw          $a0, -0x4A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A0C);
    // 0x8001F040: jal         0x8005F0DC
    // 0x8001F044: nop

    func_8005F0DC(rdram, ctx);
        goto after_2;
    // 0x8001F044: nop

    after_2:
L_8001F048:
    // 0x8001F048: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001F04C: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001F050: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F054: lhu         $t3, 0x1042($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1042);
    // 0x8001F058: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001F05C: nop

    // 0x8001F060: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001F064: beq         $t4, $zero, L_8001F098
    if (ctx->r12 == 0) {
        // 0x8001F068: nop

            goto L_8001F098;
    }
    // 0x8001F068: nop

    // 0x8001F06C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001F070: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
L_8001F074:
    // 0x8001F074: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F078: jal         0x8005F268
    // 0x8001F07C: nop

    func_8005F268(rdram, ctx);
        goto after_3;
    // 0x8001F07C: nop

    after_3:
    // 0x8001F080: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F084: nop

    // 0x8001F088: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001F08C: slti        $at, $t7, 0x201
    ctx->r1 = SIGNED(ctx->r15) < 0X201 ? 1 : 0;
    // 0x8001F090: bne         $at, $zero, L_8001F074
    if (ctx->r1 != 0) {
        // 0x8001F094: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8001F074;
    }
    // 0x8001F094: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8001F098:
    // 0x8001F098: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8001F09C: lw          $a1, -0x4A0C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4A0C);
    // 0x8001F0A0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F0A4: jal         0x8008ECE4
    // 0x8001F0A8: addiu       $a0, $a0, -0x24BC
    ctx->r4 = ADD32(ctx->r4, -0X24BC);
    func_8008ECE4(rdram, ctx);
        goto after_4;
    // 0x8001F0A8: addiu       $a0, $a0, -0x24BC
    ctx->r4 = ADD32(ctx->r4, -0X24BC);
    after_4:
    // 0x8001F0AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F0B0: lw          $a0, -0x4A0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A0C);
    // 0x8001F0B4: jal         0x8005F064
    // 0x8001F0B8: nop

    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x8001F0B8: nop

    after_5:
    // 0x8001F0BC: beq         $v0, $zero, L_8001F0D8
    if (ctx->r2 == 0) {
        // 0x8001F0C0: nop

            goto L_8001F0D8;
    }
    // 0x8001F0C0: nop

    // 0x8001F0C4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F0C8: jal         0x8008ECE4
    // 0x8001F0CC: addiu       $a0, $a0, -0x24B0
    ctx->r4 = ADD32(ctx->r4, -0X24B0);
    func_8008ECE4(rdram, ctx);
        goto after_6;
    // 0x8001F0CC: addiu       $a0, $a0, -0x24B0
    ctx->r4 = ADD32(ctx->r4, -0X24B0);
    after_6:
    // 0x8001F0D0: b           L_8001F0E4
    // 0x8001F0D4: nop

        goto L_8001F0E4;
    // 0x8001F0D4: nop

L_8001F0D8:
    // 0x8001F0D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F0DC: jal         0x8008ECE4
    // 0x8001F0E0: addiu       $a0, $a0, -0x24AC
    ctx->r4 = ADD32(ctx->r4, -0X24AC);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8001F0E0: addiu       $a0, $a0, -0x24AC
    ctx->r4 = ADD32(ctx->r4, -0X24AC);
    after_7:
L_8001F0E4:
    // 0x8001F0E4: b           L_8001F0F4
    // 0x8001F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F0F4;
    // 0x8001F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F0EC: b           L_8001F0F4
    // 0x8001F0F0: nop

        goto L_8001F0F4;
    // 0x8001F0F0: nop

L_8001F0F4:
    // 0x8001F0F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F0F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001F0FC: jr          $ra
    // 0x8001F100: nop

    return;
    // 0x8001F100: nop

;}
RECOMP_FUNC void func_8001F104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F104: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001F108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F10C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001F110: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001F114: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001F118: nop

    // 0x8001F11C: bltz        $t6, L_8001F350
    if (SIGNED(ctx->r14) < 0) {
        // 0x8001F120: nop

            goto L_8001F350;
    }
    // 0x8001F120: nop

    // 0x8001F124: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001F128: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001F12C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F130: lhu         $t9, 0xFF4($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XFF4);
    // 0x8001F134: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001F138: nop

    // 0x8001F13C: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001F140: beq         $t0, $zero, L_8001F15C
    if (ctx->r8 == 0) {
        // 0x8001F144: nop

            goto L_8001F15C;
    }
    // 0x8001F144: nop

    // 0x8001F148: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F14C: lw          $t1, 0x15D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X15D4);
    // 0x8001F150: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F154: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001F158: sw          $t2, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r10;
L_8001F15C:
    // 0x8001F15C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001F160: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001F164: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F168: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x8001F16C: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001F170: nop

    // 0x8001F174: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001F178: beq         $t6, $zero, L_8001F194
    if (ctx->r14 == 0) {
        // 0x8001F17C: nop

            goto L_8001F194;
    }
    // 0x8001F17C: nop

    // 0x8001F180: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001F184: lw          $t7, 0x15D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X15D4);
    // 0x8001F188: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F18C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001F190: sw          $t8, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r24;
L_8001F194:
    // 0x8001F194: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001F198: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001F19C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F1A0: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x8001F1A4: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001F1A8: nop

    // 0x8001F1AC: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001F1B0: beq         $t2, $zero, L_8001F1CC
    if (ctx->r10 == 0) {
        // 0x8001F1B4: nop

            goto L_8001F1CC;
    }
    // 0x8001F1B4: nop

    // 0x8001F1B8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F1BC: lw          $t3, 0x15D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X15D4);
    // 0x8001F1C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F1C4: addiu       $t4, $t3, 0xA
    ctx->r12 = ADD32(ctx->r11, 0XA);
    // 0x8001F1C8: sw          $t4, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r12;
L_8001F1CC:
    // 0x8001F1CC: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8001F1D0: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8001F1D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001F1D8: lhu         $t7, 0x1260($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1260);
    // 0x8001F1DC: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8001F1E0: nop

    // 0x8001F1E4: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001F1E8: beq         $t8, $zero, L_8001F204
    if (ctx->r24 == 0) {
        // 0x8001F1EC: nop

            goto L_8001F204;
    }
    // 0x8001F1EC: nop

    // 0x8001F1F0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F1F4: lw          $t9, 0x15D4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X15D4);
    // 0x8001F1F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F1FC: addiu       $t0, $t9, -0xA
    ctx->r8 = ADD32(ctx->r25, -0XA);
    // 0x8001F200: sw          $t0, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r8;
L_8001F204:
    // 0x8001F204: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001F208: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8001F20C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F210: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8001F214: lhu         $t2, 0x8($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X8);
    // 0x8001F218: nop

    // 0x8001F21C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8001F220: beq         $t4, $zero, L_8001F23C
    if (ctx->r12 == 0) {
        // 0x8001F224: nop

            goto L_8001F23C;
    }
    // 0x8001F224: nop

    // 0x8001F228: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F22C: lw          $t5, 0x15D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X15D4);
    // 0x8001F230: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F234: addiu       $t6, $t5, 0x64
    ctx->r14 = ADD32(ctx->r13, 0X64);
    // 0x8001F238: sw          $t6, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r14;
L_8001F23C:
    // 0x8001F23C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001F240: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8001F244: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F248: lhu         $t9, 0x11AC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X11AC);
    // 0x8001F24C: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8001F250: nop

    // 0x8001F254: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8001F258: beq         $t0, $zero, L_8001F274
    if (ctx->r8 == 0) {
        // 0x8001F25C: nop

            goto L_8001F274;
    }
    // 0x8001F25C: nop

    // 0x8001F260: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F264: lw          $t1, 0x15D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X15D4);
    // 0x8001F268: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F26C: addiu       $t2, $t1, -0x64
    ctx->r10 = ADD32(ctx->r9, -0X64);
    // 0x8001F270: sw          $t2, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r10;
L_8001F274:
    // 0x8001F274: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001F278: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8001F27C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F280: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x8001F284: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x8001F288: nop

    // 0x8001F28C: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8001F290: beq         $t6, $zero, L_8001F2AC
    if (ctx->r14 == 0) {
        // 0x8001F294: nop

            goto L_8001F2AC;
    }
    // 0x8001F294: nop

    // 0x8001F298: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8001F29C: lw          $t7, 0x70E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E8);
    // 0x8001F2A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001F2A4: addiu       $t8, $t7, 0x1388
    ctx->r24 = ADD32(ctx->r15, 0X1388);
    // 0x8001F2A8: sw          $t8, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r24;
L_8001F2AC:
    // 0x8001F2AC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001F2B0: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8001F2B4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F2B8: lhu         $t1, 0xEEC($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XEEC);
    // 0x8001F2BC: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8001F2C0: nop

    // 0x8001F2C4: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8001F2C8: beq         $t2, $zero, L_8001F2E4
    if (ctx->r10 == 0) {
        // 0x8001F2CC: nop

            goto L_8001F2E4;
    }
    // 0x8001F2CC: nop

    // 0x8001F2D0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8001F2D4: lw          $t3, 0x70E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70E8);
    // 0x8001F2D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8001F2DC: addiu       $t4, $t3, 0x1388
    ctx->r12 = ADD32(ctx->r11, 0X1388);
    // 0x8001F2E0: sw          $t4, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r12;
L_8001F2E4:
    // 0x8001F2E4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001F2E8: lw          $t5, 0x15D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X15D4);
    // 0x8001F2EC: nop

    // 0x8001F2F0: bgez        $t5, L_8001F300
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8001F2F4: nop

            goto L_8001F300;
    }
    // 0x8001F2F4: nop

    // 0x8001F2F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F2FC: sw          $zero, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = 0;
L_8001F300:
    // 0x8001F300: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001F304: lw          $t6, 0x15D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X15D4);
    // 0x8001F308: nop

    // 0x8001F30C: slti        $at, $t6, 0x1388
    ctx->r1 = SIGNED(ctx->r14) < 0X1388 ? 1 : 0;
    // 0x8001F310: bne         $at, $zero, L_8001F324
    if (ctx->r1 != 0) {
        // 0x8001F314: nop

            goto L_8001F324;
    }
    // 0x8001F314: nop

    // 0x8001F318: addiu       $t7, $zero, 0x1387
    ctx->r15 = ADD32(0, 0X1387);
    // 0x8001F31C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8001F320: sw          $t7, 0x15D4($at)
    MEM_W(0X15D4, ctx->r1) = ctx->r15;
L_8001F324:
    // 0x8001F324: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001F328: lw          $t8, 0x15D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X15D4);
    // 0x8001F32C: nop

    // 0x8001F330: beq         $t8, $zero, L_8001F350
    if (ctx->r24 == 0) {
        // 0x8001F334: nop

            goto L_8001F350;
    }
    // 0x8001F334: nop

    // 0x8001F338: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F33C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8001F340: lw          $t0, 0x480($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X480);
    // 0x8001F344: lw          $t9, 0x15D4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X15D4);
    // 0x8001F348: nop

    // 0x8001F34C: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
L_8001F350:
    // 0x8001F350: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8001F354: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8001F358: lw          $a2, 0x70E8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X70E8);
    // 0x8001F35C: lw          $a1, 0x15D4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X15D4);
    // 0x8001F360: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F364: jal         0x8008ECE4
    // 0x8001F368: addiu       $a0, $a0, -0x24A8
    ctx->r4 = ADD32(ctx->r4, -0X24A8);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8001F368: addiu       $a0, $a0, -0x24A8
    ctx->r4 = ADD32(ctx->r4, -0X24A8);
    after_0:
    // 0x8001F36C: b           L_8001F37C
    // 0x8001F370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F37C;
    // 0x8001F370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F374: b           L_8001F37C
    // 0x8001F378: nop

        goto L_8001F37C;
    // 0x8001F378: nop

L_8001F37C:
    // 0x8001F37C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001F384: jr          $ra
    // 0x8001F388: nop

    return;
    // 0x8001F388: nop

;}
RECOMP_FUNC void func_8001F38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F38C: nop

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
RECOMP_FUNC void ObjectCheckDebugMenu_DrawUI(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F6B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001F6BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001F6C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001F6C4: addiu       $t6, $t6, 0x2618
    ctx->r14 = ADD32(ctx->r14, 0X2618);
    // 0x8001F6C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001F6CC: nop

    // 0x8001F6D0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8001F6D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8001F6D8: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x8001F6DC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8001F6E0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8001F6E4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8001F6E8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8001F6EC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8001F6F0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8001F6F4: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x8001F6F8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8001F6FC: nop

    // 0x8001F700: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8001F704: beq         $t5, $zero, L_8001F718
    if (ctx->r13 == 0) {
        // 0x8001F708: nop

            goto L_8001F718;
    }
    // 0x8001F708: nop

    // 0x8001F70C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F710: b           L_8001F71C
    // 0x8001F714: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
        goto L_8001F71C;
    // 0x8001F714: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_8001F718:
    // 0x8001F718: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8001F71C:
    // 0x8001F71C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001F720: jal         0x8008EAA8
    // 0x8001F724: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x8001F724: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8001F728: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001F72C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8001F730: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001F734: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001F738: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8001F73C: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x8001F740: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F744: addiu       $a0, $a0, -0x2474
    ctx->r4 = ADD32(ctx->r4, -0X2474);
    // 0x8001F748: srl         $a1, $t9, 16
    ctx->r5 = S32(U32(ctx->r25) >> 16);
    // 0x8001F74C: andi        $a2, $t9, 0xFFFF
    ctx->r6 = ctx->r25 & 0XFFFF;
    // 0x8001F750: jal         0x8008ECE4
    // 0x8001F754: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8001F754: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8001F758: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001F75C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x8001F760: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8001F764: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F768: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001F76C: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8001F770: lh          $a0, -0x4A00($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4A00);
    // 0x8001F774: jal         0x8008EAA8
    // 0x8001F778: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_2;
    // 0x8001F778: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8001F77C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F780: jal         0x8008ECE4
    // 0x8001F784: addiu       $a0, $a0, -0x2448
    ctx->r4 = ADD32(ctx->r4, -0X2448);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x8001F784: addiu       $a0, $a0, -0x2448
    ctx->r4 = ADD32(ctx->r4, -0X2448);
    after_3:
    // 0x8001F788: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001F78C: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8001F790: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x8001F794: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001F798: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001F79C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8001F7A0: lh          $a0, -0x49FE($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X49FE);
    // 0x8001F7A4: jal         0x8008EAA8
    // 0x8001F7A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_4;
    // 0x8001F7A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8001F7AC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F7B0: jal         0x8008ECE4
    // 0x8001F7B4: addiu       $a0, $a0, -0x2444
    ctx->r4 = ADD32(ctx->r4, -0X2444);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8001F7B4: addiu       $a0, $a0, -0x2444
    ctx->r4 = ADD32(ctx->r4, -0X2444);
    after_5:
    // 0x8001F7B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F7BC: jal         0x8008EAA8
    // 0x8001F7C0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8008EAA8(rdram, ctx);
        goto after_6;
    // 0x8001F7C0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_6:
    // 0x8001F7C4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F7C8: jal         0x8008ECE4
    // 0x8001F7CC: addiu       $a0, $a0, -0x2440
    ctx->r4 = ADD32(ctx->r4, -0X2440);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8001F7CC: addiu       $a0, $a0, -0x2440
    ctx->r4 = ADD32(ctx->r4, -0X2440);
    after_7:
    // 0x8001F7D0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F7D4: jal         0x8008ECE4
    // 0x8001F7D8: addiu       $a0, $a0, -0x241C
    ctx->r4 = ADD32(ctx->r4, -0X241C);
    func_8008ECE4(rdram, ctx);
        goto after_8;
    // 0x8001F7D8: addiu       $a0, $a0, -0x241C
    ctx->r4 = ADD32(ctx->r4, -0X241C);
    after_8:
    // 0x8001F7DC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8001F7E0: jal         0x8008ECE4
    // 0x8001F7E4: addiu       $a0, $a0, -0x23F0
    ctx->r4 = ADD32(ctx->r4, -0X23F0);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x8001F7E4: addiu       $a0, $a0, -0x23F0
    ctx->r4 = ADD32(ctx->r4, -0X23F0);
    after_9:
    // 0x8001F7E8: b           L_8001F7F0
    // 0x8001F7EC: nop

        goto L_8001F7F0;
    // 0x8001F7EC: nop

L_8001F7F0:
    // 0x8001F7F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F7F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001F7F8: jr          $ra
    // 0x8001F7FC: nop

    return;
    // 0x8001F7FC: nop

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
RECOMP_FUNC void func_80020720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020720: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80020724: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80020728: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8002072C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80020730: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80020734: jal         0x8008EAA8
    // 0x80020738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x80020738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8002073C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80020740: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020744: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x80020748: jal         0x8008ECE4
    // 0x8002074C: addiu       $a0, $a0, -0x2390
    ctx->r4 = ADD32(ctx->r4, -0X2390);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8002074C: addiu       $a0, $a0, -0x2390
    ctx->r4 = ADD32(ctx->r4, -0X2390);
    after_1:
    // 0x80020750: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80020754: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x80020758: nop

    // 0x8002075C: beq         $s0, $zero, L_80020778
    if (ctx->r16 == 0) {
        // 0x80020760: nop

            goto L_80020778;
    }
    // 0x80020760: nop

    // 0x80020764: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020768: beq         $s0, $at, L_80020918
    if (ctx->r16 == ctx->r1) {
        // 0x8002076C: nop

            goto L_80020918;
    }
    // 0x8002076C: nop

    // 0x80020770: b           L_80021514
    // 0x80020774: nop

        goto L_80021514;
    // 0x80020774: nop

L_80020778:
    // 0x80020778: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002077C: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x80020780: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80020784: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80020788: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x8002078C: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80020790: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020794: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80020798: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8002079C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x800207A0: jal         0x800BC6EC
    // 0x800207A4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800207A4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_2:
    // 0x800207A8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800207AC: addiu       $t1, $t1, 0x2618
    ctx->r9 = ADD32(ctx->r9, 0X2618);
    // 0x800207B0: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x800207B4: jal         0x800BC6EC
    // 0x800207B8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x800207B8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x800207BC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800207C0: addiu       $t2, $t2, 0x2618
    ctx->r10 = ADD32(ctx->r10, 0X2618);
    // 0x800207C4: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x800207C8: jal         0x800BC6EC
    // 0x800207CC: addiu       $a0, $zero, 0x1600
    ctx->r4 = ADD32(0, 0X1600);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800207CC: addiu       $a0, $zero, 0x1600
    ctx->r4 = ADD32(0, 0X1600);
    after_4:
    // 0x800207D0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800207D4: addiu       $t3, $t3, 0x2618
    ctx->r11 = ADD32(ctx->r11, 0X2618);
    // 0x800207D8: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // 0x800207DC: jal         0x800BC6EC
    // 0x800207E0: addiu       $a0, $zero, 0x1600
    ctx->r4 = ADD32(0, 0X1600);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x800207E0: addiu       $a0, $zero, 0x1600
    ctx->r4 = ADD32(0, 0X1600);
    after_5:
    // 0x800207E4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800207E8: addiu       $t4, $t4, 0x2618
    ctx->r12 = ADD32(ctx->r12, 0X2618);
    // 0x800207EC: sw          $v0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r2;
    // 0x800207F0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800207F4: addiu       $t5, $t5, 0x2618
    ctx->r13 = ADD32(ctx->r13, 0X2618);
    // 0x800207F8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800207FC: nop

    // 0x80020800: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80020804: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80020808: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8002080C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80020810: nop

    // 0x80020814: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80020818: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8002081C:
    // 0x8002081C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80020820: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80020824: nop

    // 0x80020828: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002082C: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80020830: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80020834: nop

    // 0x80020838: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8002083C: slti        $at, $t3, 0x11
    ctx->r1 = SIGNED(ctx->r11) < 0X11 ? 1 : 0;
    // 0x80020840: bne         $at, $zero, L_8002081C
    if (ctx->r1 != 0) {
        // 0x80020844: sw          $t3, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r11;
            goto L_8002081C;
    }
    // 0x80020844: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80020848: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002084C: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x80020850: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80020854: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80020858: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8002085C: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x80020860: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80020864: addiu       $t8, $zero, 0x2C
    ctx->r24 = ADD32(0, 0X2C);
    // 0x80020868: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
    // 0x8002086C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80020870: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x80020874: sb          $t0, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r8;
    // 0x80020878: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8002087C: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80020880: sb          $t2, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r10;
    // 0x80020884: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80020888: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x8002088C: sb          $t4, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r12;
    // 0x80020890: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80020894: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x80020898: sb          $t6, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r14;
    // 0x8002089C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800208A0: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800208A4: sb          $t8, 0x7($t9)
    MEM_B(0X7, ctx->r25) = ctx->r24;
    // 0x800208A8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800208AC:
    // 0x800208AC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800208B0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800208B4: nop

    // 0x800208B8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800208BC: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x800208C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800208C4: nop

    // 0x800208C8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800208CC: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x800208D0: bne         $at, $zero, L_800208AC
    if (ctx->r1 != 0) {
        // 0x800208D4: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_800208AC;
    }
    // 0x800208D4: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800208D8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800208DC:
    // 0x800208DC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800208E0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800208E4: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x800208E8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800208EC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800208F0: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800208F4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800208F8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800208FC: nop

    // 0x80020900: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80020904: slti        $at, $t1, 0x1600
    ctx->r1 = SIGNED(ctx->r9) < 0X1600 ? 1 : 0;
    // 0x80020908: bne         $at, $zero, L_800208DC
    if (ctx->r1 != 0) {
        // 0x8002090C: sw          $t1, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r9;
            goto L_800208DC;
    }
    // 0x8002090C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80020910: b           L_80021514
    // 0x80020914: nop

        goto L_80021514;
    // 0x80020914: nop

L_80020918:
    // 0x80020918: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002091C: addiu       $t2, $t2, 0x2618
    ctx->r10 = ADD32(ctx->r10, 0X2618);
    // 0x80020920: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80020924: nop

    // 0x80020928: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8002092C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80020930: addiu       $t4, $t4, 0x2618
    ctx->r12 = ADD32(ctx->r12, 0X2618);
    // 0x80020934: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80020938: nop

    // 0x8002093C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80020940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80020944: jal         0x8008EAA8
    // 0x80020948: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EAA8(rdram, ctx);
        goto after_6;
    // 0x80020948: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x8002094C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80020950: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x80020954: nop

    // 0x80020958: andi        $t5, $t8, 0x1
    ctx->r13 = ctx->r24 & 0X1;
    // 0x8002095C: beq         $t5, $zero, L_80020978
    if (ctx->r13 == 0) {
        // 0x80020960: nop

            goto L_80020978;
    }
    // 0x80020960: nop

    // 0x80020964: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020968: jal         0x8008ECE4
    // 0x8002096C: addiu       $a0, $a0, -0x2384
    ctx->r4 = ADD32(ctx->r4, -0X2384);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8002096C: addiu       $a0, $a0, -0x2384
    ctx->r4 = ADD32(ctx->r4, -0X2384);
    after_7:
    // 0x80020970: b           L_80020984
    // 0x80020974: nop

        goto L_80020984;
    // 0x80020974: nop

L_80020978:
    // 0x80020978: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002097C: jal         0x8008ECE4
    // 0x80020980: addiu       $a0, $a0, -0x2368
    ctx->r4 = ADD32(ctx->r4, -0X2368);
    func_8008ECE4(rdram, ctx);
        goto after_8;
    // 0x80020980: addiu       $a0, $a0, -0x2368
    ctx->r4 = ADD32(ctx->r4, -0X2368);
    after_8:
L_80020984:
    // 0x80020984: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80020988: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x8002098C: nop

    // 0x80020990: andi        $t9, $t6, 0x2
    ctx->r25 = ctx->r14 & 0X2;
    // 0x80020994: beq         $t9, $zero, L_800209B8
    if (ctx->r25 == 0) {
        // 0x80020998: nop

            goto L_800209B8;
    }
    // 0x80020998: nop

    // 0x8002099C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800209A0: lw          $a1, 0x1638($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1638);
    // 0x800209A4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800209A8: jal         0x8008ECE4
    // 0x800209AC: addiu       $a0, $a0, -0x234C
    ctx->r4 = ADD32(ctx->r4, -0X234C);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x800209AC: addiu       $a0, $a0, -0x234C
    ctx->r4 = ADD32(ctx->r4, -0X234C);
    after_9:
    // 0x800209B0: b           L_800209C4
    // 0x800209B4: nop

        goto L_800209C4;
    // 0x800209B4: nop

L_800209B8:
    // 0x800209B8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800209BC: jal         0x8008ECE4
    // 0x800209C0: addiu       $a0, $a0, -0x2324
    ctx->r4 = ADD32(ctx->r4, -0X2324);
    func_8008ECE4(rdram, ctx);
        goto after_10;
    // 0x800209C0: addiu       $a0, $a0, -0x2324
    ctx->r4 = ADD32(ctx->r4, -0X2324);
    after_10:
L_800209C4:
    // 0x800209C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800209C8: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x800209CC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800209D0: nop

    // 0x800209D4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800209D8: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x800209DC: beq         $at, $zero, L_80021220
    if (ctx->r1 == 0) {
        // 0x800209E0: nop

            goto L_80021220;
    }
    // 0x800209E0: nop

    // 0x800209E4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800209E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800209EC: addu        $at, $at, $t2
    gpr jr_addend_800209F8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800209F0: lw          $t2, -0x1E84($at)
    ctx->r10 = ADD32(ctx->r1, -0X1E84);
    // 0x800209F4: nop

    // 0x800209F8: jr          $t2
    // 0x800209FC: nop

    switch (jr_addend_800209F8 >> 2) {
        case 0: goto L_80020A00; break;
        case 1: goto L_80020BD0; break;
        case 2: goto L_80020D4C; break;
        case 3: goto L_80020EAC; break;
        case 4: goto L_80021090; break;
        default: switch_error(__func__, 0x800209F8, 0x800EE17C);
    }
    // 0x800209FC: nop

L_80020A00:
    // 0x80020A00: jal         0x800AEA0C
    // 0x80020A04: nop

    ContPak_GetOpenFileResult(rdram, ctx);
        goto after_11;
    // 0x80020A04: nop

    after_11:
    // 0x80020A08: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80020A0C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020A10: nop

    // 0x80020A14: slti        $at, $t3, 0x1001
    ctx->r1 = SIGNED(ctx->r11) < 0X1001 ? 1 : 0;
    // 0x80020A18: bne         $at, $zero, L_80020B7C
    if (ctx->r1 != 0) {
        // 0x80020A1C: nop

            goto L_80020B7C;
    }
    // 0x80020A1C: nop

    // 0x80020A20: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80020A24: nop

    // 0x80020A28: addiu       $t7, $t4, -0x1000
    ctx->r15 = ADD32(ctx->r12, -0X1000);
    // 0x80020A2C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80020A30: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80020A34: nop

    // 0x80020A38: addiu       $t5, $t8, -0x1
    ctx->r13 = ADD32(ctx->r24, -0X1);
    // 0x80020A3C: sltiu       $at, $t5, 0x9
    ctx->r1 = ctx->r13 < 0X9 ? 1 : 0;
    // 0x80020A40: beq         $at, $zero, L_80020B44
    if (ctx->r1 == 0) {
        // 0x80020A44: nop

            goto L_80020B44;
    }
    // 0x80020A44: nop

    // 0x80020A48: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80020A4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020A50: addu        $at, $at, $t5
    gpr jr_addend_80020A5C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80020A54: lw          $t5, -0x1E70($at)
    ctx->r13 = ADD32(ctx->r1, -0X1E70);
    // 0x80020A58: nop

    // 0x80020A5C: jr          $t5
    // 0x80020A60: nop

    switch (jr_addend_80020A5C >> 2) {
        case 0: goto L_80020AE0; break;
        case 1: goto L_80020AF4; break;
        case 2: goto L_80020B08; break;
        case 3: goto L_80020A64; break;
        case 4: goto L_80020A78; break;
        case 5: goto L_80020B44; break;
        case 6: goto L_80020B30; break;
        case 7: goto L_80020B1C; break;
        case 8: goto L_80020A8C; break;
        default: switch_error(__func__, 0x80020A5C, 0x800EE190);
    }
    // 0x80020A60: nop

L_80020A64:
    // 0x80020A64: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020A68: jal         0x8008ECE4
    // 0x80020A6C: addiu       $a0, $a0, -0x22FC
    ctx->r4 = ADD32(ctx->r4, -0X22FC);
    func_8008ECE4(rdram, ctx);
        goto after_12;
    // 0x80020A6C: addiu       $a0, $a0, -0x22FC
    ctx->r4 = ADD32(ctx->r4, -0X22FC);
    after_12:
    // 0x80020A70: b           L_80020B5C
    // 0x80020A74: nop

        goto L_80020B5C;
    // 0x80020A74: nop

L_80020A78:
    // 0x80020A78: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020A7C: jal         0x8008ECE4
    // 0x80020A80: addiu       $a0, $a0, -0x22E4
    ctx->r4 = ADD32(ctx->r4, -0X22E4);
    func_8008ECE4(rdram, ctx);
        goto after_13;
    // 0x80020A80: addiu       $a0, $a0, -0x22E4
    ctx->r4 = ADD32(ctx->r4, -0X22E4);
    after_13:
    // 0x80020A84: b           L_80020B5C
    // 0x80020A88: nop

        goto L_80020B5C;
    // 0x80020A88: nop

L_80020A8C:
    // 0x80020A8C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020A90: jal         0x8008ECE4
    // 0x80020A94: addiu       $a0, $a0, -0x22CC
    ctx->r4 = ADD32(ctx->r4, -0X22CC);
    func_8008ECE4(rdram, ctx);
        goto after_14;
    // 0x80020A94: addiu       $a0, $a0, -0x22CC
    ctx->r4 = ADD32(ctx->r4, -0X22CC);
    after_14:
    // 0x80020A98: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80020A9C: nop

    // 0x80020AA0: lbu         $t9, 0x8($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X8);
    // 0x80020AA4: nop

    // 0x80020AA8: bne         $t9, $zero, L_80020AC0
    if (ctx->r25 != 0) {
        // 0x80020AAC: nop

            goto L_80020AC0;
    }
    // 0x80020AAC: nop

    // 0x80020AB0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80020AB4: addiu       $t0, $zero, 0x1A
    ctx->r8 = ADD32(0, 0X1A);
    // 0x80020AB8: b           L_80020AD8
    // 0x80020ABC: sb          $t0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r8;
        goto L_80020AD8;
    // 0x80020ABC: sb          $t0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r8;
L_80020AC0:
    // 0x80020AC0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80020AC4: nop

    // 0x80020AC8: lbu         $t3, 0x8($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X8);
    // 0x80020ACC: nop

    // 0x80020AD0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80020AD4: sb          $t4, 0x8($t2)
    MEM_B(0X8, ctx->r10) = ctx->r12;
L_80020AD8:
    // 0x80020AD8: b           L_80020B5C
    // 0x80020ADC: nop

        goto L_80020B5C;
    // 0x80020ADC: nop

L_80020AE0:
    // 0x80020AE0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020AE4: jal         0x8008ECE4
    // 0x80020AE8: addiu       $a0, $a0, -0x22B4
    ctx->r4 = ADD32(ctx->r4, -0X22B4);
    func_8008ECE4(rdram, ctx);
        goto after_15;
    // 0x80020AE8: addiu       $a0, $a0, -0x22B4
    ctx->r4 = ADD32(ctx->r4, -0X22B4);
    after_15:
    // 0x80020AEC: b           L_80020B5C
    // 0x80020AF0: nop

        goto L_80020B5C;
    // 0x80020AF0: nop

L_80020AF4:
    // 0x80020AF4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020AF8: jal         0x8008ECE4
    // 0x80020AFC: addiu       $a0, $a0, -0x229C
    ctx->r4 = ADD32(ctx->r4, -0X229C);
    func_8008ECE4(rdram, ctx);
        goto after_16;
    // 0x80020AFC: addiu       $a0, $a0, -0x229C
    ctx->r4 = ADD32(ctx->r4, -0X229C);
    after_16:
    // 0x80020B00: b           L_80020B5C
    // 0x80020B04: nop

        goto L_80020B5C;
    // 0x80020B04: nop

L_80020B08:
    // 0x80020B08: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B0C: jal         0x8008ECE4
    // 0x80020B10: addiu       $a0, $a0, -0x2284
    ctx->r4 = ADD32(ctx->r4, -0X2284);
    func_8008ECE4(rdram, ctx);
        goto after_17;
    // 0x80020B10: addiu       $a0, $a0, -0x2284
    ctx->r4 = ADD32(ctx->r4, -0X2284);
    after_17:
    // 0x80020B14: b           L_80020B5C
    // 0x80020B18: nop

        goto L_80020B5C;
    // 0x80020B18: nop

L_80020B1C:
    // 0x80020B1C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B20: jal         0x8008ECE4
    // 0x80020B24: addiu       $a0, $a0, -0x226C
    ctx->r4 = ADD32(ctx->r4, -0X226C);
    func_8008ECE4(rdram, ctx);
        goto after_18;
    // 0x80020B24: addiu       $a0, $a0, -0x226C
    ctx->r4 = ADD32(ctx->r4, -0X226C);
    after_18:
    // 0x80020B28: b           L_80020B5C
    // 0x80020B2C: nop

        goto L_80020B5C;
    // 0x80020B2C: nop

L_80020B30:
    // 0x80020B30: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B34: jal         0x8008ECE4
    // 0x80020B38: addiu       $a0, $a0, -0x2254
    ctx->r4 = ADD32(ctx->r4, -0X2254);
    func_8008ECE4(rdram, ctx);
        goto after_19;
    // 0x80020B38: addiu       $a0, $a0, -0x2254
    ctx->r4 = ADD32(ctx->r4, -0X2254);
    after_19:
    // 0x80020B3C: b           L_80020B5C
    // 0x80020B40: nop

        goto L_80020B5C;
    // 0x80020B40: nop

L_80020B44:
    // 0x80020B44: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B48: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020B4C: jal         0x8008ECE4
    // 0x80020B50: addiu       $a0, $a0, -0x223C
    ctx->r4 = ADD32(ctx->r4, -0X223C);
    func_8008ECE4(rdram, ctx);
        goto after_20;
    // 0x80020B50: addiu       $a0, $a0, -0x223C
    ctx->r4 = ADD32(ctx->r4, -0X223C);
    after_20:
    // 0x80020B54: b           L_80020B5C
    // 0x80020B58: nop

        goto L_80020B5C;
    // 0x80020B58: nop

L_80020B5C:
    // 0x80020B5C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80020B60: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x80020B64: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80020B68: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80020B6C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020B70: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020B74: b           L_80020BC8
    // 0x80020B78: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
        goto L_80020BC8;
    // 0x80020B78: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_80020B7C:
    // 0x80020B7C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80020B80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020B84: beq         $t6, $at, L_80020BC8
    if (ctx->r14 == ctx->r1) {
        // 0x80020B88: nop

            goto L_80020BC8;
    }
    // 0x80020B88: nop

    // 0x80020B8C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020B90: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020B94: jal         0x8008ECE4
    // 0x80020B98: addiu       $a0, $a0, -0x2224
    ctx->r4 = ADD32(ctx->r4, -0X2224);
    func_8008ECE4(rdram, ctx);
        goto after_21;
    // 0x80020B98: addiu       $a0, $a0, -0x2224
    ctx->r4 = ADD32(ctx->r4, -0X2224);
    after_21:
    // 0x80020B9C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020BA0: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80020BA4: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80020BA8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80020BAC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80020BB0: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80020BB4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80020BB8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020BBC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80020BC0: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x80020BC4: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
L_80020BC8:
    // 0x80020BC8: b           L_8002150C
    // 0x80020BCC: nop

        goto L_8002150C;
    // 0x80020BCC: nop

L_80020BD0:
    // 0x80020BD0: jal         0x800AEBF4
    // 0x80020BD4: nop

    ContPak_GetFindFileResult(rdram, ctx);
        goto after_22;
    // 0x80020BD4: nop

    after_22:
    // 0x80020BD8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80020BDC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80020BE0: nop

    // 0x80020BE4: slti        $at, $t2, 0x1001
    ctx->r1 = SIGNED(ctx->r10) < 0X1001 ? 1 : 0;
    // 0x80020BE8: bne         $at, $zero, L_80020CF8
    if (ctx->r1 != 0) {
        // 0x80020BEC: nop

            goto L_80020CF8;
    }
    // 0x80020BEC: nop

    // 0x80020BF0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80020BF4: nop

    // 0x80020BF8: addiu       $t8, $t7, -0x1000
    ctx->r24 = ADD32(ctx->r15, -0X1000);
    // 0x80020BFC: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80020C00: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80020C04: nop

    // 0x80020C08: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80020C0C: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x80020C10: beq         $at, $zero, L_80020CC0
    if (ctx->r1 == 0) {
        // 0x80020C14: nop

            goto L_80020CC0;
    }
    // 0x80020C14: nop

    // 0x80020C18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80020C1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020C20: addu        $at, $at, $t6
    gpr jr_addend_80020C2C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80020C24: lw          $t6, -0x1E4C($at)
    ctx->r14 = ADD32(ctx->r1, -0X1E4C);
    // 0x80020C28: nop

    // 0x80020C2C: jr          $t6
    // 0x80020C30: nop

    switch (jr_addend_80020C2C >> 2) {
        case 0: goto L_80020C70; break;
        case 1: goto L_80020C84; break;
        case 2: goto L_80020C98; break;
        case 3: goto L_80020C34; break;
        case 4: goto L_80020C48; break;
        case 5: goto L_80020CC0; break;
        case 6: goto L_80020CC0; break;
        case 7: goto L_80020CAC; break;
        case 8: goto L_80020C5C; break;
        default: switch_error(__func__, 0x80020C2C, 0x800EE1B4);
    }
    // 0x80020C30: nop

L_80020C34:
    // 0x80020C34: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C38: jal         0x8008ECE4
    // 0x80020C3C: addiu       $a0, $a0, -0x220C
    ctx->r4 = ADD32(ctx->r4, -0X220C);
    func_8008ECE4(rdram, ctx);
        goto after_23;
    // 0x80020C3C: addiu       $a0, $a0, -0x220C
    ctx->r4 = ADD32(ctx->r4, -0X220C);
    after_23:
    // 0x80020C40: b           L_80020CD8
    // 0x80020C44: nop

        goto L_80020CD8;
    // 0x80020C44: nop

L_80020C48:
    // 0x80020C48: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C4C: jal         0x8008ECE4
    // 0x80020C50: addiu       $a0, $a0, -0x21F4
    ctx->r4 = ADD32(ctx->r4, -0X21F4);
    func_8008ECE4(rdram, ctx);
        goto after_24;
    // 0x80020C50: addiu       $a0, $a0, -0x21F4
    ctx->r4 = ADD32(ctx->r4, -0X21F4);
    after_24:
    // 0x80020C54: b           L_80020CD8
    // 0x80020C58: nop

        goto L_80020CD8;
    // 0x80020C58: nop

L_80020C5C:
    // 0x80020C5C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C60: jal         0x8008ECE4
    // 0x80020C64: addiu       $a0, $a0, -0x21DC
    ctx->r4 = ADD32(ctx->r4, -0X21DC);
    func_8008ECE4(rdram, ctx);
        goto after_25;
    // 0x80020C64: addiu       $a0, $a0, -0x21DC
    ctx->r4 = ADD32(ctx->r4, -0X21DC);
    after_25:
    // 0x80020C68: b           L_80020CD8
    // 0x80020C6C: nop

        goto L_80020CD8;
    // 0x80020C6C: nop

L_80020C70:
    // 0x80020C70: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C74: jal         0x8008ECE4
    // 0x80020C78: addiu       $a0, $a0, -0x21C4
    ctx->r4 = ADD32(ctx->r4, -0X21C4);
    func_8008ECE4(rdram, ctx);
        goto after_26;
    // 0x80020C78: addiu       $a0, $a0, -0x21C4
    ctx->r4 = ADD32(ctx->r4, -0X21C4);
    after_26:
    // 0x80020C7C: b           L_80020CD8
    // 0x80020C80: nop

        goto L_80020CD8;
    // 0x80020C80: nop

L_80020C84:
    // 0x80020C84: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C88: jal         0x8008ECE4
    // 0x80020C8C: addiu       $a0, $a0, -0x21AC
    ctx->r4 = ADD32(ctx->r4, -0X21AC);
    func_8008ECE4(rdram, ctx);
        goto after_27;
    // 0x80020C8C: addiu       $a0, $a0, -0x21AC
    ctx->r4 = ADD32(ctx->r4, -0X21AC);
    after_27:
    // 0x80020C90: b           L_80020CD8
    // 0x80020C94: nop

        goto L_80020CD8;
    // 0x80020C94: nop

L_80020C98:
    // 0x80020C98: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020C9C: jal         0x8008ECE4
    // 0x80020CA0: addiu       $a0, $a0, -0x2194
    ctx->r4 = ADD32(ctx->r4, -0X2194);
    func_8008ECE4(rdram, ctx);
        goto after_28;
    // 0x80020CA0: addiu       $a0, $a0, -0x2194
    ctx->r4 = ADD32(ctx->r4, -0X2194);
    after_28:
    // 0x80020CA4: b           L_80020CD8
    // 0x80020CA8: nop

        goto L_80020CD8;
    // 0x80020CA8: nop

L_80020CAC:
    // 0x80020CAC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020CB0: jal         0x8008ECE4
    // 0x80020CB4: addiu       $a0, $a0, -0x217C
    ctx->r4 = ADD32(ctx->r4, -0X217C);
    func_8008ECE4(rdram, ctx);
        goto after_29;
    // 0x80020CB4: addiu       $a0, $a0, -0x217C
    ctx->r4 = ADD32(ctx->r4, -0X217C);
    after_29:
    // 0x80020CB8: b           L_80020CD8
    // 0x80020CBC: nop

        goto L_80020CD8;
    // 0x80020CBC: nop

L_80020CC0:
    // 0x80020CC0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020CC4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020CC8: jal         0x8008ECE4
    // 0x80020CCC: addiu       $a0, $a0, -0x2164
    ctx->r4 = ADD32(ctx->r4, -0X2164);
    func_8008ECE4(rdram, ctx);
        goto after_30;
    // 0x80020CCC: addiu       $a0, $a0, -0x2164
    ctx->r4 = ADD32(ctx->r4, -0X2164);
    after_30:
    // 0x80020CD0: b           L_80020CD8
    // 0x80020CD4: nop

        goto L_80020CD8;
    // 0x80020CD4: nop

L_80020CD8:
    // 0x80020CD8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020CDC: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80020CE0: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80020CE4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80020CE8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80020CEC: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80020CF0: b           L_80020D44
    // 0x80020CF4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
        goto L_80020D44;
    // 0x80020CF4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_80020CF8:
    // 0x80020CF8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020CFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020D00: beq         $t3, $at, L_80020D44
    if (ctx->r11 == ctx->r1) {
        // 0x80020D04: nop

            goto L_80020D44;
    }
    // 0x80020D04: nop

    // 0x80020D08: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020D0C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020D10: jal         0x8008ECE4
    // 0x80020D14: addiu       $a0, $a0, -0x214C
    ctx->r4 = ADD32(ctx->r4, -0X214C);
    func_8008ECE4(rdram, ctx);
        goto after_31;
    // 0x80020D14: addiu       $a0, $a0, -0x214C
    ctx->r4 = ADD32(ctx->r4, -0X214C);
    after_31:
    // 0x80020D18: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80020D1C: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x80020D20: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x80020D24: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80020D28: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80020D2C: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x80020D30: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80020D34: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80020D38: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020D3C: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020D40: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
L_80020D44:
    // 0x80020D44: b           L_8002150C
    // 0x80020D48: nop

        goto L_8002150C;
    // 0x80020D48: nop

L_80020D4C:
    // 0x80020D4C: jal         0x800AEDE8
    // 0x80020D50: nop

    ContPak_GetWriteFileResult(rdram, ctx);
        goto after_32;
    // 0x80020D50: nop

    after_32:
    // 0x80020D54: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80020D58: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80020D5C: nop

    // 0x80020D60: slti        $at, $t6, 0x1001
    ctx->r1 = SIGNED(ctx->r14) < 0X1001 ? 1 : 0;
    // 0x80020D64: bne         $at, $zero, L_80020E60
    if (ctx->r1 != 0) {
        // 0x80020D68: nop

            goto L_80020E60;
    }
    // 0x80020D68: nop

    // 0x80020D6C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80020D70: nop

    // 0x80020D74: addiu       $t0, $t9, -0x1000
    ctx->r8 = ADD32(ctx->r25, -0X1000);
    // 0x80020D78: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80020D7C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80020D80: nop

    // 0x80020D84: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x80020D88: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x80020D8C: beq         $at, $zero, L_80020E28
    if (ctx->r1 == 0) {
        // 0x80020D90: nop

            goto L_80020E28;
    }
    // 0x80020D90: nop

    // 0x80020D94: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80020D98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020D9C: addu        $at, $at, $t3
    gpr jr_addend_80020DA8 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80020DA0: lw          $t3, -0x1E28($at)
    ctx->r11 = ADD32(ctx->r1, -0X1E28);
    // 0x80020DA4: nop

    // 0x80020DA8: jr          $t3
    // 0x80020DAC: nop

    switch (jr_addend_80020DA8 >> 2) {
        case 0: goto L_80020DD8; break;
        case 1: goto L_80020DEC; break;
        case 2: goto L_80020E00; break;
        case 3: goto L_80020DB0; break;
        case 4: goto L_80020DC4; break;
        case 5: goto L_80020E14; break;
        default: switch_error(__func__, 0x80020DA8, 0x800EE1D8);
    }
    // 0x80020DAC: nop

L_80020DB0:
    // 0x80020DB0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020DB4: jal         0x8008ECE4
    // 0x80020DB8: addiu       $a0, $a0, -0x2134
    ctx->r4 = ADD32(ctx->r4, -0X2134);
    func_8008ECE4(rdram, ctx);
        goto after_33;
    // 0x80020DB8: addiu       $a0, $a0, -0x2134
    ctx->r4 = ADD32(ctx->r4, -0X2134);
    after_33:
    // 0x80020DBC: b           L_80020E40
    // 0x80020DC0: nop

        goto L_80020E40;
    // 0x80020DC0: nop

L_80020DC4:
    // 0x80020DC4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020DC8: jal         0x8008ECE4
    // 0x80020DCC: addiu       $a0, $a0, -0x211C
    ctx->r4 = ADD32(ctx->r4, -0X211C);
    func_8008ECE4(rdram, ctx);
        goto after_34;
    // 0x80020DCC: addiu       $a0, $a0, -0x211C
    ctx->r4 = ADD32(ctx->r4, -0X211C);
    after_34:
    // 0x80020DD0: b           L_80020E40
    // 0x80020DD4: nop

        goto L_80020E40;
    // 0x80020DD4: nop

L_80020DD8:
    // 0x80020DD8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020DDC: jal         0x8008ECE4
    // 0x80020DE0: addiu       $a0, $a0, -0x2104
    ctx->r4 = ADD32(ctx->r4, -0X2104);
    func_8008ECE4(rdram, ctx);
        goto after_35;
    // 0x80020DE0: addiu       $a0, $a0, -0x2104
    ctx->r4 = ADD32(ctx->r4, -0X2104);
    after_35:
    // 0x80020DE4: b           L_80020E40
    // 0x80020DE8: nop

        goto L_80020E40;
    // 0x80020DE8: nop

L_80020DEC:
    // 0x80020DEC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020DF0: jal         0x8008ECE4
    // 0x80020DF4: addiu       $a0, $a0, -0x20EC
    ctx->r4 = ADD32(ctx->r4, -0X20EC);
    func_8008ECE4(rdram, ctx);
        goto after_36;
    // 0x80020DF4: addiu       $a0, $a0, -0x20EC
    ctx->r4 = ADD32(ctx->r4, -0X20EC);
    after_36:
    // 0x80020DF8: b           L_80020E40
    // 0x80020DFC: nop

        goto L_80020E40;
    // 0x80020DFC: nop

L_80020E00:
    // 0x80020E00: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020E04: jal         0x8008ECE4
    // 0x80020E08: addiu       $a0, $a0, -0x20D4
    ctx->r4 = ADD32(ctx->r4, -0X20D4);
    func_8008ECE4(rdram, ctx);
        goto after_37;
    // 0x80020E08: addiu       $a0, $a0, -0x20D4
    ctx->r4 = ADD32(ctx->r4, -0X20D4);
    after_37:
    // 0x80020E0C: b           L_80020E40
    // 0x80020E10: nop

        goto L_80020E40;
    // 0x80020E10: nop

L_80020E14:
    // 0x80020E14: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020E18: jal         0x8008ECE4
    // 0x80020E1C: addiu       $a0, $a0, -0x20BC
    ctx->r4 = ADD32(ctx->r4, -0X20BC);
    func_8008ECE4(rdram, ctx);
        goto after_38;
    // 0x80020E1C: addiu       $a0, $a0, -0x20BC
    ctx->r4 = ADD32(ctx->r4, -0X20BC);
    after_38:
    // 0x80020E20: b           L_80020E40
    // 0x80020E24: nop

        goto L_80020E40;
    // 0x80020E24: nop

L_80020E28:
    // 0x80020E28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020E2C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020E30: jal         0x8008ECE4
    // 0x80020E34: addiu       $a0, $a0, -0x20A4
    ctx->r4 = ADD32(ctx->r4, -0X20A4);
    func_8008ECE4(rdram, ctx);
        goto after_39;
    // 0x80020E34: addiu       $a0, $a0, -0x20A4
    ctx->r4 = ADD32(ctx->r4, -0X20A4);
    after_39:
    // 0x80020E38: b           L_80020E40
    // 0x80020E3C: nop

        goto L_80020E40;
    // 0x80020E3C: nop

L_80020E40:
    // 0x80020E40: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80020E44: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x80020E48: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x80020E4C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80020E50: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80020E54: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x80020E58: b           L_80020EA4
    // 0x80020E5C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
        goto L_80020EA4;
    // 0x80020E5C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_80020E60:
    // 0x80020E60: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80020E64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020E68: beq         $t8, $at, L_80020EA4
    if (ctx->r24 == ctx->r1) {
        // 0x80020E6C: nop

            goto L_80020EA4;
    }
    // 0x80020E6C: nop

    // 0x80020E70: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020E74: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020E78: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    // 0x80020E7C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020E80: jal         0x8008ECE4
    // 0x80020E84: addiu       $a0, $a0, -0x208C
    ctx->r4 = ADD32(ctx->r4, -0X208C);
    func_8008ECE4(rdram, ctx);
        goto after_40;
    // 0x80020E84: addiu       $a0, $a0, -0x208C
    ctx->r4 = ADD32(ctx->r4, -0X208C);
    after_40:
    // 0x80020E88: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80020E8C: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x80020E90: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80020E94: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80020E98: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020E9C: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80020EA0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80020EA4:
    // 0x80020EA4: b           L_8002150C
    // 0x80020EA8: nop

        goto L_8002150C;
    // 0x80020EA8: nop

L_80020EAC:
    // 0x80020EAC: jal         0x800AEFD4
    // 0x80020EB0: nop

    ContPak_GetReadFileResult(rdram, ctx);
        goto after_41;
    // 0x80020EB0: nop

    after_41:
    // 0x80020EB4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80020EB8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80020EBC: nop

    // 0x80020EC0: slti        $at, $t1, 0x1001
    ctx->r1 = SIGNED(ctx->r9) < 0X1001 ? 1 : 0;
    // 0x80020EC4: bne         $at, $zero, L_80020FC0
    if (ctx->r1 != 0) {
        // 0x80020EC8: nop

            goto L_80020FC0;
    }
    // 0x80020EC8: nop

    // 0x80020ECC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020ED0: nop

    // 0x80020ED4: addiu       $t4, $t3, -0x1000
    ctx->r12 = ADD32(ctx->r11, -0X1000);
    // 0x80020ED8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x80020EDC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80020EE0: nop

    // 0x80020EE4: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x80020EE8: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80020EEC: beq         $at, $zero, L_80020F88
    if (ctx->r1 == 0) {
        // 0x80020EF0: nop

            goto L_80020F88;
    }
    // 0x80020EF0: nop

    // 0x80020EF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80020EF8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80020EFC: addu        $at, $at, $t7
    gpr jr_addend_80020F08 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80020F00: lw          $t7, -0x1E10($at)
    ctx->r15 = ADD32(ctx->r1, -0X1E10);
    // 0x80020F04: nop

    // 0x80020F08: jr          $t7
    // 0x80020F0C: nop

    switch (jr_addend_80020F08 >> 2) {
        case 0: goto L_80020F38; break;
        case 1: goto L_80020F4C; break;
        case 2: goto L_80020F60; break;
        case 3: goto L_80020F10; break;
        case 4: goto L_80020F24; break;
        case 5: goto L_80020F74; break;
        default: switch_error(__func__, 0x80020F08, 0x800EE1F0);
    }
    // 0x80020F0C: nop

L_80020F10:
    // 0x80020F10: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F14: jal         0x8008ECE4
    // 0x80020F18: addiu       $a0, $a0, -0x2070
    ctx->r4 = ADD32(ctx->r4, -0X2070);
    func_8008ECE4(rdram, ctx);
        goto after_42;
    // 0x80020F18: addiu       $a0, $a0, -0x2070
    ctx->r4 = ADD32(ctx->r4, -0X2070);
    after_42:
    // 0x80020F1C: b           L_80020FA0
    // 0x80020F20: nop

        goto L_80020FA0;
    // 0x80020F20: nop

L_80020F24:
    // 0x80020F24: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F28: jal         0x8008ECE4
    // 0x80020F2C: addiu       $a0, $a0, -0x2058
    ctx->r4 = ADD32(ctx->r4, -0X2058);
    func_8008ECE4(rdram, ctx);
        goto after_43;
    // 0x80020F2C: addiu       $a0, $a0, -0x2058
    ctx->r4 = ADD32(ctx->r4, -0X2058);
    after_43:
    // 0x80020F30: b           L_80020FA0
    // 0x80020F34: nop

        goto L_80020FA0;
    // 0x80020F34: nop

L_80020F38:
    // 0x80020F38: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F3C: jal         0x8008ECE4
    // 0x80020F40: addiu       $a0, $a0, -0x2040
    ctx->r4 = ADD32(ctx->r4, -0X2040);
    func_8008ECE4(rdram, ctx);
        goto after_44;
    // 0x80020F40: addiu       $a0, $a0, -0x2040
    ctx->r4 = ADD32(ctx->r4, -0X2040);
    after_44:
    // 0x80020F44: b           L_80020FA0
    // 0x80020F48: nop

        goto L_80020FA0;
    // 0x80020F48: nop

L_80020F4C:
    // 0x80020F4C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F50: jal         0x8008ECE4
    // 0x80020F54: addiu       $a0, $a0, -0x2028
    ctx->r4 = ADD32(ctx->r4, -0X2028);
    func_8008ECE4(rdram, ctx);
        goto after_45;
    // 0x80020F54: addiu       $a0, $a0, -0x2028
    ctx->r4 = ADD32(ctx->r4, -0X2028);
    after_45:
    // 0x80020F58: b           L_80020FA0
    // 0x80020F5C: nop

        goto L_80020FA0;
    // 0x80020F5C: nop

L_80020F60:
    // 0x80020F60: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F64: jal         0x8008ECE4
    // 0x80020F68: addiu       $a0, $a0, -0x2010
    ctx->r4 = ADD32(ctx->r4, -0X2010);
    func_8008ECE4(rdram, ctx);
        goto after_46;
    // 0x80020F68: addiu       $a0, $a0, -0x2010
    ctx->r4 = ADD32(ctx->r4, -0X2010);
    after_46:
    // 0x80020F6C: b           L_80020FA0
    // 0x80020F70: nop

        goto L_80020FA0;
    // 0x80020F70: nop

L_80020F74:
    // 0x80020F74: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F78: jal         0x8008ECE4
    // 0x80020F7C: addiu       $a0, $a0, -0x1FF8
    ctx->r4 = ADD32(ctx->r4, -0X1FF8);
    func_8008ECE4(rdram, ctx);
        goto after_47;
    // 0x80020F7C: addiu       $a0, $a0, -0x1FF8
    ctx->r4 = ADD32(ctx->r4, -0X1FF8);
    after_47:
    // 0x80020F80: b           L_80020FA0
    // 0x80020F84: nop

        goto L_80020FA0;
    // 0x80020F84: nop

L_80020F88:
    // 0x80020F88: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80020F8C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80020F90: jal         0x8008ECE4
    // 0x80020F94: addiu       $a0, $a0, -0x1FE0
    ctx->r4 = ADD32(ctx->r4, -0X1FE0);
    func_8008ECE4(rdram, ctx);
        goto after_48;
    // 0x80020F94: addiu       $a0, $a0, -0x1FE0
    ctx->r4 = ADD32(ctx->r4, -0X1FE0);
    after_48:
    // 0x80020F98: b           L_80020FA0
    // 0x80020F9C: nop

        goto L_80020FA0;
    // 0x80020F9C: nop

L_80020FA0:
    // 0x80020FA0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80020FA4: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80020FA8: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80020FAC: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80020FB0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80020FB4: addiu       $t6, $t6, 0x25F0
    ctx->r14 = ADD32(ctx->r14, 0X25F0);
    // 0x80020FB8: b           L_80021088
    // 0x80020FBC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
        goto L_80021088;
    // 0x80020FBC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
L_80020FC0:
    // 0x80020FC0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80020FC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020FC8: beq         $t9, $at, L_80021088
    if (ctx->r25 == ctx->r1) {
        // 0x80020FCC: nop

            goto L_80021088;
    }
    // 0x80020FCC: nop

    // 0x80020FD0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80020FD4:
    // 0x80020FD4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80020FD8: addiu       $t0, $t0, 0x2618
    ctx->r8 = ADD32(ctx->r8, 0X2618);
    // 0x80020FDC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80020FE0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80020FE4: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x80020FE8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80020FEC: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x80020FF0: lbu         $t5, 0x0($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X0);
    // 0x80020FF4: lbu         $t2, 0x0($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X0);
    // 0x80020FF8: nop

    // 0x80020FFC: beq         $t2, $t5, L_8002100C
    if (ctx->r10 == ctx->r13) {
        // 0x80021000: nop

            goto L_8002100C;
    }
    // 0x80021000: nop

    // 0x80021004: b           L_80021024
    // 0x80021008: nop

        goto L_80021024;
    // 0x80021008: nop

L_8002100C:
    // 0x8002100C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80021010: nop

    // 0x80021014: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80021018: slti        $at, $t9, 0x1600
    ctx->r1 = SIGNED(ctx->r25) < 0X1600 ? 1 : 0;
    // 0x8002101C: bne         $at, $zero, L_80020FD4
    if (ctx->r1 != 0) {
        // 0x80021020: sw          $t9, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r25;
            goto L_80020FD4;
    }
    // 0x80021020: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_80021024:
    // 0x80021024: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80021028: addiu       $at, $zero, 0x1600
    ctx->r1 = ADD32(0, 0X1600);
    // 0x8002102C: bne         $t1, $at, L_80021054
    if (ctx->r9 != ctx->r1) {
        // 0x80021030: nop

            goto L_80021054;
    }
    // 0x80021030: nop

    // 0x80021034: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80021038: addiu       $t4, $t4, 0x25F0
    ctx->r12 = ADD32(ctx->r12, 0X25F0);
    // 0x8002103C: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x80021040: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021044: jal         0x8008ECE4
    // 0x80021048: addiu       $a0, $a0, -0x1FC8
    ctx->r4 = ADD32(ctx->r4, -0X1FC8);
    func_8008ECE4(rdram, ctx);
        goto after_49;
    // 0x80021048: addiu       $a0, $a0, -0x1FC8
    ctx->r4 = ADD32(ctx->r4, -0X1FC8);
    after_49:
    // 0x8002104C: b           L_8002106C
    // 0x80021050: nop

        goto L_8002106C;
    // 0x80021050: nop

L_80021054:
    // 0x80021054: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021058: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x8002105C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x80021060: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021064: jal         0x8008ECE4
    // 0x80021068: addiu       $a0, $a0, -0x1FAC
    ctx->r4 = ADD32(ctx->r4, -0X1FAC);
    func_8008ECE4(rdram, ctx);
        goto after_50;
    // 0x80021068: addiu       $a0, $a0, -0x1FAC
    ctx->r4 = ADD32(ctx->r4, -0X1FAC);
    after_50:
L_8002106C:
    // 0x8002106C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80021070: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x80021074: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80021078: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x8002107C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021080: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x80021084: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_80021088:
    // 0x80021088: b           L_8002150C
    // 0x8002108C: nop

        goto L_8002150C;
    // 0x8002108C: nop

L_80021090:
    // 0x80021090: jal         0x800AE7FC
    // 0x80021094: nop

    ContPak_GetDeleteFileResult(rdram, ctx);
        goto after_51;
    // 0x80021094: nop

    after_51:
    // 0x80021098: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8002109C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800210A0: nop

    // 0x800210A4: slti        $at, $t2, 0x1001
    ctx->r1 = SIGNED(ctx->r10) < 0X1001 ? 1 : 0;
    // 0x800210A8: bne         $at, $zero, L_800211CC
    if (ctx->r1 != 0) {
        // 0x800210AC: nop

            goto L_800211CC;
    }
    // 0x800210AC: nop

    // 0x800210B0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800210B4: nop

    // 0x800210B8: addiu       $t6, $t5, -0x1000
    ctx->r14 = ADD32(ctx->r13, -0X1000);
    // 0x800210BC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800210C0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800210C4: nop

    // 0x800210C8: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x800210CC: sltiu       $at, $t1, 0x9
    ctx->r1 = ctx->r9 < 0X9 ? 1 : 0;
    // 0x800210D0: beq         $at, $zero, L_80021194
    if (ctx->r1 == 0) {
        // 0x800210D4: nop

            goto L_80021194;
    }
    // 0x800210D4: nop

    // 0x800210D8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800210DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800210E0: addu        $at, $at, $t1
    gpr jr_addend_800210EC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800210E4: lw          $t1, -0x1DF8($at)
    ctx->r9 = ADD32(ctx->r1, -0X1DF8);
    // 0x800210E8: nop

    // 0x800210EC: jr          $t1
    // 0x800210F0: nop

    switch (jr_addend_800210EC >> 2) {
        case 0: goto L_80021130; break;
        case 1: goto L_80021144; break;
        case 2: goto L_80021158; break;
        case 3: goto L_800210F4; break;
        case 4: goto L_80021108; break;
        case 5: goto L_80021194; break;
        case 6: goto L_80021180; break;
        case 7: goto L_8002116C; break;
        case 8: goto L_8002111C; break;
        default: switch_error(__func__, 0x800210EC, 0x800EE208);
    }
    // 0x800210F0: nop

L_800210F4:
    // 0x800210F4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800210F8: jal         0x8008ECE4
    // 0x800210FC: addiu       $a0, $a0, -0x1F90
    ctx->r4 = ADD32(ctx->r4, -0X1F90);
    func_8008ECE4(rdram, ctx);
        goto after_52;
    // 0x800210FC: addiu       $a0, $a0, -0x1F90
    ctx->r4 = ADD32(ctx->r4, -0X1F90);
    after_52:
    // 0x80021100: b           L_800211AC
    // 0x80021104: nop

        goto L_800211AC;
    // 0x80021104: nop

L_80021108:
    // 0x80021108: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002110C: jal         0x8008ECE4
    // 0x80021110: addiu       $a0, $a0, -0x1F78
    ctx->r4 = ADD32(ctx->r4, -0X1F78);
    func_8008ECE4(rdram, ctx);
        goto after_53;
    // 0x80021110: addiu       $a0, $a0, -0x1F78
    ctx->r4 = ADD32(ctx->r4, -0X1F78);
    after_53:
    // 0x80021114: b           L_800211AC
    // 0x80021118: nop

        goto L_800211AC;
    // 0x80021118: nop

L_8002111C:
    // 0x8002111C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021120: jal         0x8008ECE4
    // 0x80021124: addiu       $a0, $a0, -0x1F60
    ctx->r4 = ADD32(ctx->r4, -0X1F60);
    func_8008ECE4(rdram, ctx);
        goto after_54;
    // 0x80021124: addiu       $a0, $a0, -0x1F60
    ctx->r4 = ADD32(ctx->r4, -0X1F60);
    after_54:
    // 0x80021128: b           L_800211AC
    // 0x8002112C: nop

        goto L_800211AC;
    // 0x8002112C: nop

L_80021130:
    // 0x80021130: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021134: jal         0x8008ECE4
    // 0x80021138: addiu       $a0, $a0, -0x1F48
    ctx->r4 = ADD32(ctx->r4, -0X1F48);
    func_8008ECE4(rdram, ctx);
        goto after_55;
    // 0x80021138: addiu       $a0, $a0, -0x1F48
    ctx->r4 = ADD32(ctx->r4, -0X1F48);
    after_55:
    // 0x8002113C: b           L_800211AC
    // 0x80021140: nop

        goto L_800211AC;
    // 0x80021140: nop

L_80021144:
    // 0x80021144: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021148: jal         0x8008ECE4
    // 0x8002114C: addiu       $a0, $a0, -0x1F30
    ctx->r4 = ADD32(ctx->r4, -0X1F30);
    func_8008ECE4(rdram, ctx);
        goto after_56;
    // 0x8002114C: addiu       $a0, $a0, -0x1F30
    ctx->r4 = ADD32(ctx->r4, -0X1F30);
    after_56:
    // 0x80021150: b           L_800211AC
    // 0x80021154: nop

        goto L_800211AC;
    // 0x80021154: nop

L_80021158:
    // 0x80021158: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002115C: jal         0x8008ECE4
    // 0x80021160: addiu       $a0, $a0, -0x1F18
    ctx->r4 = ADD32(ctx->r4, -0X1F18);
    func_8008ECE4(rdram, ctx);
        goto after_57;
    // 0x80021160: addiu       $a0, $a0, -0x1F18
    ctx->r4 = ADD32(ctx->r4, -0X1F18);
    after_57:
    // 0x80021164: b           L_800211AC
    // 0x80021168: nop

        goto L_800211AC;
    // 0x80021168: nop

L_8002116C:
    // 0x8002116C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021170: jal         0x8008ECE4
    // 0x80021174: addiu       $a0, $a0, -0x1F00
    ctx->r4 = ADD32(ctx->r4, -0X1F00);
    func_8008ECE4(rdram, ctx);
        goto after_58;
    // 0x80021174: addiu       $a0, $a0, -0x1F00
    ctx->r4 = ADD32(ctx->r4, -0X1F00);
    after_58:
    // 0x80021178: b           L_800211AC
    // 0x8002117C: nop

        goto L_800211AC;
    // 0x8002117C: nop

L_80021180:
    // 0x80021180: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021184: jal         0x8008ECE4
    // 0x80021188: addiu       $a0, $a0, -0x1EE8
    ctx->r4 = ADD32(ctx->r4, -0X1EE8);
    func_8008ECE4(rdram, ctx);
        goto after_59;
    // 0x80021188: addiu       $a0, $a0, -0x1EE8
    ctx->r4 = ADD32(ctx->r4, -0X1EE8);
    after_59:
    // 0x8002118C: b           L_800211AC
    // 0x80021190: nop

        goto L_800211AC;
    // 0x80021190: nop

L_80021194:
    // 0x80021194: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021198: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8002119C: jal         0x8008ECE4
    // 0x800211A0: addiu       $a0, $a0, -0x1ED0
    ctx->r4 = ADD32(ctx->r4, -0X1ED0);
    func_8008ECE4(rdram, ctx);
        goto after_60;
    // 0x800211A0: addiu       $a0, $a0, -0x1ED0
    ctx->r4 = ADD32(ctx->r4, -0X1ED0);
    after_60:
    // 0x800211A4: b           L_800211AC
    // 0x800211A8: nop

        goto L_800211AC;
    // 0x800211A8: nop

L_800211AC:
    // 0x800211AC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800211B0: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x800211B4: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x800211B8: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x800211BC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800211C0: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x800211C4: b           L_80021218
    // 0x800211C8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
        goto L_80021218;
    // 0x800211C8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_800211CC:
    // 0x800211CC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800211D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800211D4: beq         $t3, $at, L_80021218
    if (ctx->r11 == ctx->r1) {
        // 0x800211D8: nop

            goto L_80021218;
    }
    // 0x800211D8: nop

    // 0x800211DC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800211E0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800211E4: jal         0x8008ECE4
    // 0x800211E8: addiu       $a0, $a0, -0x1EB8
    ctx->r4 = ADD32(ctx->r4, -0X1EB8);
    func_8008ECE4(rdram, ctx);
        goto after_61;
    // 0x800211E8: addiu       $a0, $a0, -0x1EB8
    ctx->r4 = ADD32(ctx->r4, -0X1EB8);
    after_61:
    // 0x800211EC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800211F0: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x800211F4: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x800211F8: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x800211FC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021200: addiu       $t5, $t5, 0x25F0
    ctx->r13 = ADD32(ctx->r13, 0X25F0);
    // 0x80021204: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x80021208: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002120C: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x80021210: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80021214: sw          $t6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r14;
L_80021218:
    // 0x80021218: b           L_8002150C
    // 0x8002121C: nop

        goto L_8002150C;
    // 0x8002121C: nop

L_80021220:
    // 0x80021220: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80021224: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x80021228: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002122C: lhu         $t0, 0x10F2($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X10F2);
    // 0x80021230: lhu         $t4, 0x6($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X6);
    // 0x80021234: nop

    // 0x80021238: and         $t7, $t4, $t0
    ctx->r15 = ctx->r12 & ctx->r8;
    // 0x8002123C: beq         $t7, $zero, L_8002124C
    if (ctx->r15 == 0) {
        // 0x80021240: nop

            goto L_8002124C;
    }
    // 0x80021240: nop

    // 0x80021244: jal         0x800AE348
    // 0x80021248: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ContPak_SetPakInitializationAttempts(rdram, ctx);
        goto after_62;
    // 0x80021248: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_62:
L_8002124C:
    // 0x8002124C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80021250: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80021254: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021258: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x8002125C: lhu         $t8, 0x6($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X6);
    // 0x80021260: nop

    // 0x80021264: and         $t5, $t8, $t2
    ctx->r13 = ctx->r24 & ctx->r10;
    // 0x80021268: beq         $t5, $zero, L_80021298
    if (ctx->r13 == 0) {
        // 0x8002126C: nop

            goto L_80021298;
    }
    // 0x8002126C: nop

    // 0x80021270: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80021274: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80021278: jal         0x800AE880
    // 0x8002127C: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    ContPak_SetOpenFileParams(rdram, ctx);
        goto after_63;
    // 0x8002127C: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    after_63:
    // 0x80021280: bne         $v0, $zero, L_80021298
    if (ctx->r2 != 0) {
        // 0x80021284: nop

            goto L_80021298;
    }
    // 0x80021284: nop

    // 0x80021288: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002128C: addiu       $t9, $t9, 0x25F0
    ctx->r25 = ADD32(ctx->r25, 0X25F0);
    // 0x80021290: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80021294: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
L_80021298:
    // 0x80021298: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8002129C: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x800212A0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800212A4: lhu         $t0, 0x101C($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X101C);
    // 0x800212A8: lhu         $t4, 0x6($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X6);
    // 0x800212AC: nop

    // 0x800212B0: and         $t7, $t4, $t0
    ctx->r15 = ctx->r12 & ctx->r8;
    // 0x800212B4: beq         $t7, $zero, L_800212E4
    if (ctx->r15 == 0) {
        // 0x800212B8: nop

            goto L_800212E4;
    }
    // 0x800212B8: nop

    // 0x800212BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800212C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800212C4: jal         0x800AEA98
    // 0x800212C8: nop

    ContPak_SetFileFindParams(rdram, ctx);
        goto after_64;
    // 0x800212C8: nop

    after_64:
    // 0x800212CC: bne         $v0, $zero, L_800212E4
    if (ctx->r2 != 0) {
        // 0x800212D0: nop

            goto L_800212E4;
    }
    // 0x800212D0: nop

    // 0x800212D4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800212D8: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x800212DC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800212E0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
L_800212E4:
    // 0x800212E4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800212E8: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x800212EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800212F0: lhu         $t6, 0x1258($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1258);
    // 0x800212F4: lhu         $t5, 0x6($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X6);
    // 0x800212F8: nop

    // 0x800212FC: and         $t9, $t5, $t6
    ctx->r25 = ctx->r13 & ctx->r14;
    // 0x80021300: beq         $t9, $zero, L_8002135C
    if (ctx->r25 == 0) {
        // 0x80021304: nop

            goto L_8002135C;
    }
    // 0x80021304: nop

    // 0x80021308: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002130C: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80021310: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x80021314: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021318: beq         $t4, $at, L_8002135C
    if (ctx->r12 == ctx->r1) {
        // 0x8002131C: nop

            goto L_8002135C;
    }
    // 0x8002131C: nop

    // 0x80021320: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021324: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80021328: addiu       $t7, $t7, 0x2618
    ctx->r15 = ADD32(ctx->r15, 0X2618);
    // 0x8002132C: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80021330: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x80021334: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x80021338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002133C: jal         0x800AEC80
    // 0x80021340: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    ContPak_SetFileWriteParams(rdram, ctx);
        goto after_65;
    // 0x80021340: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    after_65:
    // 0x80021344: bne         $v0, $zero, L_8002135C
    if (ctx->r2 != 0) {
        // 0x80021348: nop

            goto L_8002135C;
    }
    // 0x80021348: nop

    // 0x8002134C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021350: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x80021354: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80021358: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
L_8002135C:
    // 0x8002135C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80021360: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x80021364: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80021368: lhu         $t6, 0x1260($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1260);
    // 0x8002136C: lhu         $t5, 0x6($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X6);
    // 0x80021370: nop

    // 0x80021374: and         $t9, $t5, $t6
    ctx->r25 = ctx->r13 & ctx->r14;
    // 0x80021378: beq         $t9, $zero, L_80021418
    if (ctx->r25 == 0) {
        // 0x8002137C: nop

            goto L_80021418;
    }
    // 0x8002137C: nop

    // 0x80021380: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80021384: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80021388: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x8002138C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021390: beq         $t4, $at, L_80021418
    if (ctx->r12 == ctx->r1) {
        // 0x80021394: nop

            goto L_80021418;
    }
    // 0x80021394: nop

    // 0x80021398: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8002139C:
    // 0x8002139C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800213A0: addiu       $t0, $t0, 0x2618
    ctx->r8 = ADD32(ctx->r8, 0X2618);
    // 0x800213A4: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x800213A8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800213AC: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x800213B0: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x800213B4: lbu         $t2, 0x0($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X0);
    // 0x800213B8: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x800213BC: xori        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 ^ 0XFF;
    // 0x800213C0: sb          $t5, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r13;
    // 0x800213C4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800213C8: nop

    // 0x800213CC: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x800213D0: slti        $at, $t4, 0x1600
    ctx->r1 = SIGNED(ctx->r12) < 0X1600 ? 1 : 0;
    // 0x800213D4: bne         $at, $zero, L_8002139C
    if (ctx->r1 != 0) {
        // 0x800213D8: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_8002139C;
    }
    // 0x800213D8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800213DC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800213E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800213E4: addiu       $t8, $t8, 0x2618
    ctx->r24 = ADD32(ctx->r24, 0X2618);
    // 0x800213E8: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x800213EC: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x800213F0: lw          $a3, 0xC($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XC);
    // 0x800213F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800213F8: jal         0x800AEE6C
    // 0x800213FC: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    ContPak_SetFileReadParams(rdram, ctx);
        goto after_66;
    // 0x800213FC: addiu       $a2, $zero, 0x1600
    ctx->r6 = ADD32(0, 0X1600);
    after_66:
    // 0x80021400: bne         $v0, $zero, L_80021418
    if (ctx->r2 != 0) {
        // 0x80021404: nop

            goto L_80021418;
    }
    // 0x80021404: nop

    // 0x80021408: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002140C: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80021410: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80021414: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_80021418:
    // 0x80021418: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8002141C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80021420: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021424: lhu         $t5, 0x126C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X126C);
    // 0x80021428: lhu         $t3, 0x6($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0X6);
    // 0x8002142C: nop

    // 0x80021430: and         $t9, $t3, $t5
    ctx->r25 = ctx->r11 & ctx->r13;
    // 0x80021434: beq         $t9, $zero, L_80021480
    if (ctx->r25 == 0) {
        // 0x80021438: nop

            goto L_80021480;
    }
    // 0x80021438: nop

    // 0x8002143C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80021440: addiu       $t1, $t1, 0x25F0
    ctx->r9 = ADD32(ctx->r9, 0X25F0);
    // 0x80021444: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x80021448: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002144C: beq         $t4, $at, L_80021480
    if (ctx->r12 == ctx->r1) {
        // 0x80021450: nop

            goto L_80021480;
    }
    // 0x80021450: nop

    // 0x80021454: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80021458: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x8002145C: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    // 0x80021460: jal         0x800AE5F0
    // 0x80021464: nop

    ContPak_SetFileDeleteParams(rdram, ctx);
        goto after_67;
    // 0x80021464: nop

    after_67:
    // 0x80021468: bne         $v0, $zero, L_80021480
    if (ctx->r2 != 0) {
        // 0x8002146C: nop

            goto L_80021480;
    }
    // 0x8002146C: nop

    // 0x80021470: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021474: addiu       $t2, $t2, 0x25F0
    ctx->r10 = ADD32(ctx->r10, 0X25F0);
    // 0x80021478: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8002147C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80021480:
    // 0x80021480: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021484: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80021488: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x8002148C: nop

    // 0x80021490: bne         $t6, $zero, L_800214AC
    if (ctx->r14 != 0) {
        // 0x80021494: nop

            goto L_800214AC;
    }
    // 0x80021494: nop

    // 0x80021498: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002149C: jal         0x8008ECE4
    // 0x800214A0: addiu       $a0, $a0, -0x1E9C
    ctx->r4 = ADD32(ctx->r4, -0X1E9C);
    func_8008ECE4(rdram, ctx);
        goto after_68;
    // 0x800214A0: addiu       $a0, $a0, -0x1E9C
    ctx->r4 = ADD32(ctx->r4, -0X1E9C);
    after_68:
    // 0x800214A4: b           L_80021504
    // 0x800214A8: nop

        goto L_80021504;
    // 0x800214A8: nop

L_800214AC:
    // 0x800214AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800214B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800214B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800214B8: addiu       $t3, $t3, 0x25F0
    ctx->r11 = ADD32(ctx->r11, 0X25F0);
    // 0x800214BC: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x800214C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800214C4: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800214C8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800214CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800214D0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800214D4: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800214D8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800214DC: nop

    // 0x800214E0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800214E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800214E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800214EC: nop

    // 0x800214F0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800214F4: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800214F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800214FC: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x80021500: nop

L_80021504:
    // 0x80021504: b           L_8002150C
    // 0x80021508: nop

        goto L_8002150C;
    // 0x80021508: nop

L_8002150C:
    // 0x8002150C: b           L_80021514
    // 0x80021510: nop

        goto L_80021514;
    // 0x80021510: nop

L_80021514:
    // 0x80021514: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80021518: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8002151C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021520: lhu         $t8, 0x11A4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X11A4);
    // 0x80021524: lhu         $t7, 0x6($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X6);
    // 0x80021528: nop

    // 0x8002152C: and         $t2, $t7, $t8
    ctx->r10 = ctx->r15 & ctx->r24;
    // 0x80021530: beq         $t2, $zero, L_80021578
    if (ctx->r10 == 0) {
        // 0x80021534: nop

            goto L_80021578;
    }
    // 0x80021534: nop

    // 0x80021538: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8002153C:
    // 0x8002153C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80021540: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80021544: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80021548: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8002154C: lw          $a0, 0x2618($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2618);
    // 0x80021550: jal         0x800BC980
    // 0x80021554: nop

    SysMem_Free(rdram, ctx);
        goto after_69;
    // 0x80021554: nop

    after_69:
    // 0x80021558: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8002155C: nop

    // 0x80021560: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80021564: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80021568: bne         $at, $zero, L_8002153C
    if (ctx->r1 != 0) {
        // 0x8002156C: sw          $t9, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r25;
            goto L_8002153C;
    }
    // 0x8002156C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80021570: b           L_80021588
    // 0x80021574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80021588;
    // 0x80021574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80021578:
    // 0x80021578: b           L_80021588
    // 0x8002157C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021588;
    // 0x8002157C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021580: b           L_80021588
    // 0x80021584: nop

        goto L_80021588;
    // 0x80021584: nop

L_80021588:
    // 0x80021588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002158C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021590: jr          $ra
    // 0x80021594: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80021594: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80021598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021598: nop

    // 0x8002159C: nop

;}
RECOMP_FUNC void SoundDebugMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800215A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800215A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800215A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800215AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800215B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800215B4: jal         0x8008EAA8
    // 0x800215B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_0;
    // 0x800215B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800215BC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800215C0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800215C4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x800215C8: jal         0x8008ECE4
    // 0x800215CC: addiu       $a0, $a0, -0x1D3C
    ctx->r4 = ADD32(ctx->r4, -0X1D3C);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x800215CC: addiu       $a0, $a0, -0x1D3C
    ctx->r4 = ADD32(ctx->r4, -0X1D3C);
    after_1:
    // 0x800215D0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800215D4: lw          $s0, 0x25E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X25E4);
    // 0x800215D8: nop

    // 0x800215DC: beq         $s0, $zero, L_800215F8
    if (ctx->r16 == 0) {
        // 0x800215E0: nop

            goto L_800215F8;
    }
    // 0x800215E0: nop

    // 0x800215E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800215E8: beq         $s0, $at, L_80021604
    if (ctx->r16 == ctx->r1) {
        // 0x800215EC: nop

            goto L_80021604;
    }
    // 0x800215EC: nop

    // 0x800215F0: b           L_80021880
    // 0x800215F4: nop

        goto L_80021880;
    // 0x800215F4: nop

L_800215F8:
    // 0x800215F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800215FC: addiu       $t7, $t7, 0x25F0
    ctx->r15 = ADD32(ctx->r15, 0X25F0);
    // 0x80021600: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_80021604:
    // 0x80021604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80021608: jal         0x8008EAA8
    // 0x8002160C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008EAA8(rdram, ctx);
        goto after_2;
    // 0x8002160C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80021610: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021614: addiu       $t8, $t8, 0x25F0
    ctx->r24 = ADD32(ctx->r24, 0X25F0);
    // 0x80021618: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002161C: nop

    // 0x80021620: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80021624: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80021628: addiu       $t0, $t0, -0x49F0
    ctx->r8 = ADD32(ctx->r8, -0X49F0);
    // 0x8002162C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80021630: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80021634: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80021638:
    // 0x80021638: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8002163C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021640: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80021644: nop

    // 0x80021648: bne         $t2, $at, L_80021658
    if (ctx->r10 != ctx->r1) {
        // 0x8002164C: nop

            goto L_80021658;
    }
    // 0x8002164C: nop

    // 0x80021650: b           L_800217C4
    // 0x80021654: nop

        goto L_800217C4;
    // 0x80021654: nop

L_80021658:
    // 0x80021658: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8002165C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021660: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80021664: nop

    // 0x80021668: beq         $t4, $at, L_800216A4
    if (ctx->r12 == ctx->r1) {
        // 0x8002166C: nop

            goto L_800216A4;
    }
    // 0x8002166C: nop

    // 0x80021670: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80021674: nop

    // 0x80021678: lw          $a0, 0x8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8);
    // 0x8002167C: lw          $a1, 0xC($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC);
    // 0x80021680: jal         0x8008EAA8
    // 0x80021684: nop

    func_8008EAA8(rdram, ctx);
        goto after_3;
    // 0x80021684: nop

    after_3:
    // 0x80021688: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8002168C: nop

    // 0x80021690: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80021694: nop

    // 0x80021698: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002169C: b           L_800216C0
    // 0x800216A0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_800216C0;
    // 0x800216A0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_800216A4:
    // 0x800216A4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800216A8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800216AC: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x800216B0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800216B4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800216B8: jal         0x8008EAA8
    // 0x800216BC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_4;
    // 0x800216BC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_4:
L_800216C0:
    // 0x800216C0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800216C4: nop

    // 0x800216C8: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x800216CC: nop

    // 0x800216D0: beq         $t3, $zero, L_80021794
    if (ctx->r11 == 0) {
        // 0x800216D4: nop

            goto L_80021794;
    }
    // 0x800216D4: nop

    // 0x800216D8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800216DC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800216E0: nop

    // 0x800216E4: bne         $t4, $t5, L_8002173C
    if (ctx->r12 != ctx->r13) {
        // 0x800216E8: nop

            goto L_8002173C;
    }
    // 0x800216E8: nop

    // 0x800216EC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800216F0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800216F4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x800216F8: jal         0x8008ECE4
    // 0x800216FC: addiu       $a0, $a0, -0x1D30
    ctx->r4 = ADD32(ctx->r4, -0X1D30);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x800216FC: addiu       $a0, $a0, -0x1D30
    ctx->r4 = ADD32(ctx->r4, -0X1D30);
    after_5:
    // 0x80021700: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80021704: nop

    // 0x80021708: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8002170C: nop

    // 0x80021710: beq         $t8, $zero, L_80021734
    if (ctx->r24 == 0) {
        // 0x80021714: nop

            goto L_80021734;
    }
    // 0x80021714: nop

    // 0x80021718: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8002171C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021720: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80021724: lw          $t9, 0x14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X14);
    // 0x80021728: nop

    // 0x8002172C: jalr        $t9
    // 0x80021730: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80021730: nop

    after_6:
L_80021734:
    // 0x80021734: b           L_80021780
    // 0x80021738: nop

        goto L_80021780;
    // 0x80021738: nop

L_8002173C:
    // 0x8002173C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80021740: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021744: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x80021748: jal         0x8008ECE4
    // 0x8002174C: addiu       $a0, $a0, -0x1D2C
    ctx->r4 = ADD32(ctx->r4, -0X1D2C);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x8002174C: addiu       $a0, $a0, -0x1D2C
    ctx->r4 = ADD32(ctx->r4, -0X1D2C);
    after_7:
    // 0x80021750: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80021754: nop

    // 0x80021758: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8002175C: nop

    // 0x80021760: beq         $t2, $zero, L_80021780
    if (ctx->r10 == 0) {
        // 0x80021764: nop

            goto L_80021780;
    }
    // 0x80021764: nop

    // 0x80021768: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8002176C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80021770: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x80021774: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80021778: jalr        $t9
    // 0x8002177C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8002177C: nop

    after_8:
L_80021780:
    // 0x80021780: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80021784: nop

    // 0x80021788: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002178C: b           L_800217A8
    // 0x80021790: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
        goto L_800217A8;
    // 0x80021790: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_80021794:
    // 0x80021794: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80021798: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002179C: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x800217A0: jal         0x8008ECE4
    // 0x800217A4: addiu       $a0, $a0, -0x1D28
    ctx->r4 = ADD32(ctx->r4, -0X1D28);
    func_8008ECE4(rdram, ctx);
        goto after_9;
    // 0x800217A4: addiu       $a0, $a0, -0x1D28
    ctx->r4 = ADD32(ctx->r4, -0X1D28);
    after_9:
L_800217A8:
    // 0x800217A8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800217AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800217B0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800217B4: addiu       $t1, $t0, 0x28
    ctx->r9 = ADD32(ctx->r8, 0X28);
    // 0x800217B8: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800217BC: b           L_80021638
    // 0x800217C0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80021638;
    // 0x800217C0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800217C4:
    // 0x800217C4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800217C8: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x800217CC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800217D0: lhu         $t9, 0xE68($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XE68);
    // 0x800217D4: lhu         $t3, 0x8($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X8);
    // 0x800217D8: nop

    // 0x800217DC: and         $t4, $t3, $t9
    ctx->r12 = ctx->r11 & ctx->r25;
    // 0x800217E0: beq         $t4, $zero, L_800217F8
    if (ctx->r12 == 0) {
        // 0x800217E4: nop

            goto L_800217F8;
    }
    // 0x800217E4: nop

    // 0x800217E8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800217EC: nop

    // 0x800217F0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800217F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_800217F8:
    // 0x800217F8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800217FC: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80021800: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021804: lhu         $t0, 0xE74($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XE74);
    // 0x80021808: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8002180C: nop

    // 0x80021810: and         $t1, $t8, $t0
    ctx->r9 = ctx->r24 & ctx->r8;
    // 0x80021814: beq         $t1, $zero, L_8002182C
    if (ctx->r9 == 0) {
        // 0x80021818: nop

            goto L_8002182C;
    }
    // 0x80021818: nop

    // 0x8002181C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80021820: nop

    // 0x80021824: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80021828: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_8002182C:
    // 0x8002182C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80021830: nop

    // 0x80021834: bgez        $t9, L_8002184C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80021838: nop

            goto L_8002184C;
    }
    // 0x80021838: nop

    // 0x8002183C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80021840: nop

    // 0x80021844: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80021848: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8002184C:
    // 0x8002184C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80021850: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80021854: nop

    // 0x80021858: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002185C: bne         $at, $zero, L_80021868
    if (ctx->r1 != 0) {
        // 0x80021860: nop

            goto L_80021868;
    }
    // 0x80021860: nop

    // 0x80021864: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80021868:
    // 0x80021868: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002186C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021870: addiu       $t0, $t0, 0x25F0
    ctx->r8 = ADD32(ctx->r8, 0X25F0);
    // 0x80021874: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80021878: b           L_80021880
    // 0x8002187C: nop

        goto L_80021880;
    // 0x8002187C: nop

L_80021880:
    // 0x80021880: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80021884: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x80021888: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002188C: lhu         $t3, 0x11A4($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X11A4);
    // 0x80021890: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x80021894: nop

    // 0x80021898: and         $t9, $t2, $t3
    ctx->r25 = ctx->r10 & ctx->r11;
    // 0x8002189C: beq         $t9, $zero, L_800218AC
    if (ctx->r25 == 0) {
        // 0x800218A0: nop

            goto L_800218AC;
    }
    // 0x800218A0: nop

    // 0x800218A4: b           L_800218BC
    // 0x800218A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800218BC;
    // 0x800218A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800218AC:
    // 0x800218AC: b           L_800218BC
    // 0x800218B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800218BC;
    // 0x800218B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800218B4: b           L_800218BC
    // 0x800218B8: nop

        goto L_800218BC;
    // 0x800218B8: nop

L_800218BC:
    // 0x800218BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800218C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800218C4: jr          $ra
    // 0x800218C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800218C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void SoundDebugMenu_BGMTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800218CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800218D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800218D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800218D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800218DC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800218E0: nop

    // 0x800218E4: bltz        $t6, L_80021A9C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800218E8: nop

            goto L_80021A9C;
    }
    // 0x800218E8: nop

    // 0x800218EC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800218F0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x800218F4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800218F8: lhu         $t9, 0xEEC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEEC);
    // 0x800218FC: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80021900: nop

    // 0x80021904: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80021908: beq         $t0, $zero, L_80021924
    if (ctx->r8 == 0) {
        // 0x8002190C: nop

            goto L_80021924;
    }
    // 0x8002190C: nop

    // 0x80021910: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80021914: lw          $t1, -0x33BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33BC);
    // 0x80021918: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002191C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80021920: sw          $t2, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r10;
L_80021924:
    // 0x80021924: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80021928: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8002192C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021930: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x80021934: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x80021938: nop

    // 0x8002193C: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80021940: beq         $t6, $zero, L_8002195C
    if (ctx->r14 == 0) {
        // 0x80021944: nop

            goto L_8002195C;
    }
    // 0x80021944: nop

    // 0x80021948: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8002194C: lw          $t7, -0x33BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33BC);
    // 0x80021950: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021954: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80021958: sw          $t8, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r24;
L_8002195C:
    // 0x8002195C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80021960: lw          $t9, -0x33BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33BC);
    // 0x80021964: nop

    // 0x80021968: bgez        $t9, L_80021978
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002196C: nop

            goto L_80021978;
    }
    // 0x8002196C: nop

    // 0x80021970: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021974: sw          $zero, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = 0;
L_80021978:
    // 0x80021978: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8002197C: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80021980: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021984: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x80021988: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x8002198C: nop

    // 0x80021990: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80021994: beq         $t3, $zero, L_800219AC
    if (ctx->r11 == 0) {
        // 0x80021998: nop

            goto L_800219AC;
    }
    // 0x80021998: nop

    // 0x8002199C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800219A0: lw          $a0, -0x33BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33BC);
    // 0x800219A4: jal         0x80021ED0
    // 0x800219A8: nop

    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_0;
    // 0x800219A8: nop

    after_0:
L_800219AC:
    // 0x800219AC: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800219B0: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x800219B4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800219B8: lhu         $t6, 0x101C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X101C);
    // 0x800219BC: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800219C0: nop

    // 0x800219C4: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x800219C8: beq         $t7, $zero, L_800219D8
    if (ctx->r15 == 0) {
        // 0x800219CC: nop

            goto L_800219D8;
    }
    // 0x800219CC: nop

    // 0x800219D0: jal         0x800B8FA8
    // 0x800219D4: nop

    AudioMgr_StopMusic(rdram, ctx);
        goto after_1;
    // 0x800219D4: nop

    after_1:
L_800219D8:
    // 0x800219D8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800219DC: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x800219E0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800219E4: lhu         $t0, 0x1258($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X1258);
    // 0x800219E8: lhu         $t9, 0x8($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X8);
    // 0x800219EC: nop

    // 0x800219F0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800219F4: beq         $t1, $zero, L_80021A10
    if (ctx->r9 == 0) {
        // 0x800219F8: nop

            goto L_80021A10;
    }
    // 0x800219F8: nop

    // 0x800219FC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80021A00: lh          $t2, -0x48A8($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X48A8);
    // 0x80021A04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021A08: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80021A0C: sh          $t3, -0x48A8($at)
    MEM_H(-0X48A8, ctx->r1) = ctx->r11;
L_80021A10:
    // 0x80021A10: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80021A14: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80021A18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80021A1C: lhu         $t6, 0x1260($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X1260);
    // 0x80021A20: lhu         $t5, 0x8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X8);
    // 0x80021A24: nop

    // 0x80021A28: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x80021A2C: beq         $t7, $zero, L_80021A48
    if (ctx->r15 == 0) {
        // 0x80021A30: nop

            goto L_80021A48;
    }
    // 0x80021A30: nop

    // 0x80021A34: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80021A38: lh          $t8, -0x48A8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X48A8);
    // 0x80021A3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021A40: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80021A44: sh          $t9, -0x48A8($at)
    MEM_H(-0X48A8, ctx->r1) = ctx->r25;
L_80021A48:
    // 0x80021A48: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80021A4C: lh          $t0, -0x48A8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X48A8);
    // 0x80021A50: nop

    // 0x80021A54: bgez        $t0, L_80021A68
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80021A58: nop

            goto L_80021A68;
    }
    // 0x80021A58: nop

    // 0x80021A5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80021A60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021A64: sh          $t1, -0x48A8($at)
    MEM_H(-0X48A8, ctx->r1) = ctx->r9;
L_80021A68:
    // 0x80021A68: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80021A6C: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x80021A70: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80021A74: lhu         $t4, 0x126C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X126C);
    // 0x80021A78: lhu         $t3, 0x6($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X6);
    // 0x80021A7C: nop

    // 0x80021A80: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x80021A84: beq         $t5, $zero, L_80021A9C
    if (ctx->r13 == 0) {
        // 0x80021A88: nop

            goto L_80021A9C;
    }
    // 0x80021A88: nop

    // 0x80021A8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80021A90: lh          $a0, -0x48A8($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X48A8);
    // 0x80021A94: jal         0x80021F20
    // 0x80021A98: nop

    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_2;
    // 0x80021A98: nop

    after_2:
L_80021A9C:
    // 0x80021A9C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80021AA0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80021AA4: lh          $a2, -0x48A8($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X48A8);
    // 0x80021AA8: lw          $a1, -0x33BC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X33BC);
    // 0x80021AAC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021AB0: jal         0x8008ECE4
    // 0x80021AB4: addiu       $a0, $a0, -0x1D24
    ctx->r4 = ADD32(ctx->r4, -0X1D24);
    func_8008ECE4(rdram, ctx);
        goto after_3;
    // 0x80021AB4: addiu       $a0, $a0, -0x1D24
    ctx->r4 = ADD32(ctx->r4, -0X1D24);
    after_3:
    // 0x80021AB8: b           L_80021AC8
    // 0x80021ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021AC8;
    // 0x80021ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021AC0: b           L_80021AC8
    // 0x80021AC4: nop

        goto L_80021AC8;
    // 0x80021AC4: nop

L_80021AC8:
    // 0x80021AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021ACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021AD0: jr          $ra
    // 0x80021AD4: nop

    return;
    // 0x80021AD4: nop

;}
RECOMP_FUNC void SoundDebugMenu_SfxTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021AE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021AE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80021AE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80021AEC: nop

    // 0x80021AF0: bltz        $t6, L_80021D3C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80021AF4: nop

            goto L_80021D3C;
    }
    // 0x80021AF4: nop

    // 0x80021AF8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80021AFC: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80021B00: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80021B04: lhu         $t9, 0xEEC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEEC);
    // 0x80021B08: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80021B0C: nop

    // 0x80021B10: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80021B14: beq         $t0, $zero, L_80021B30
    if (ctx->r8 == 0) {
        // 0x80021B18: nop

            goto L_80021B30;
    }
    // 0x80021B18: nop

    // 0x80021B1C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80021B20: lw          $t1, -0x33B8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33B8);
    // 0x80021B24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021B28: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80021B2C: sw          $t2, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = ctx->r10;
L_80021B30:
    // 0x80021B30: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80021B34: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80021B38: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021B3C: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x80021B40: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x80021B44: nop

    // 0x80021B48: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80021B4C: beq         $t6, $zero, L_80021B68
    if (ctx->r14 == 0) {
        // 0x80021B50: nop

            goto L_80021B68;
    }
    // 0x80021B50: nop

    // 0x80021B54: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80021B58: lw          $t7, -0x33B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33B8);
    // 0x80021B5C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021B60: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80021B64: sw          $t8, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = ctx->r24;
L_80021B68:
    // 0x80021B68: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80021B6C: lw          $t9, -0x33B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33B8);
    // 0x80021B70: nop

    // 0x80021B74: bgez        $t9, L_80021B84
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80021B78: nop

            goto L_80021B84;
    }
    // 0x80021B78: nop

    // 0x80021B7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021B80: sw          $zero, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = 0;
L_80021B84:
    // 0x80021B84: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80021B88: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80021B8C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021B90: lhu         $t2, 0x1258($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1258);
    // 0x80021B94: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x80021B98: nop

    // 0x80021B9C: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80021BA0: beq         $t3, $zero, L_80021BD4
    if (ctx->r11 == 0) {
        // 0x80021BA4: nop

            goto L_80021BD4;
    }
    // 0x80021BA4: nop

    // 0x80021BA8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80021BAC: lh          $t4, -0x48B0($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X48B0);
    // 0x80021BB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021BB4: addiu       $t5, $t4, 0x64
    ctx->r13 = ADD32(ctx->r12, 0X64);
    // 0x80021BB8: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80021BBC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80021BC0: bgtz        $t7, L_80021BD4
    if (SIGNED(ctx->r15) > 0) {
        // 0x80021BC4: sh          $t5, -0x48B0($at)
        MEM_H(-0X48B0, ctx->r1) = ctx->r13;
            goto L_80021BD4;
    }
    // 0x80021BC4: sh          $t5, -0x48B0($at)
    MEM_H(-0X48B0, ctx->r1) = ctx->r13;
    // 0x80021BC8: addiu       $t8, $zero, 0x7FFF
    ctx->r24 = ADD32(0, 0X7FFF);
    // 0x80021BCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021BD0: sh          $t8, -0x48B0($at)
    MEM_H(-0X48B0, ctx->r1) = ctx->r24;
L_80021BD4:
    // 0x80021BD4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80021BD8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80021BDC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80021BE0: lhu         $t1, 0x1260($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1260);
    // 0x80021BE4: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x80021BE8: nop

    // 0x80021BEC: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x80021BF0: beq         $t2, $zero, L_80021C20
    if (ctx->r10 == 0) {
        // 0x80021BF4: nop

            goto L_80021C20;
    }
    // 0x80021BF4: nop

    // 0x80021BF8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80021BFC: lh          $t3, -0x48B0($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X48B0);
    // 0x80021C00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021C04: addiu       $t4, $t3, -0x64
    ctx->r12 = ADD32(ctx->r11, -0X64);
    // 0x80021C08: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80021C0C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80021C10: bgez        $t6, L_80021C20
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80021C14: sh          $t4, -0x48B0($at)
        MEM_H(-0X48B0, ctx->r1) = ctx->r12;
            goto L_80021C20;
    }
    // 0x80021C14: sh          $t4, -0x48B0($at)
    MEM_H(-0X48B0, ctx->r1) = ctx->r12;
    // 0x80021C18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021C1C: sh          $zero, -0x48B0($at)
    MEM_H(-0X48B0, ctx->r1) = 0;
L_80021C20:
    // 0x80021C20: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80021C24: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80021C28: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80021C2C: lhu         $t9, 0x126C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X126C);
    // 0x80021C30: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80021C34: nop

    // 0x80021C38: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80021C3C: beq         $t0, $zero, L_80021C78
    if (ctx->r8 == 0) {
        // 0x80021C40: nop

            goto L_80021C78;
    }
    // 0x80021C40: nop

    // 0x80021C44: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80021C48: lh          $t1, -0x48AC($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X48AC);
    // 0x80021C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021C50: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80021C54: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80021C58: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80021C5C: sh          $t2, -0x48AC($at)
    MEM_H(-0X48AC, ctx->r1) = ctx->r10;
    // 0x80021C60: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x80021C64: bne         $at, $zero, L_80021C78
    if (ctx->r1 != 0) {
        // 0x80021C68: nop

            goto L_80021C78;
    }
    // 0x80021C68: nop

    // 0x80021C6C: addiu       $t5, $zero, 0x7F
    ctx->r13 = ADD32(0, 0X7F);
    // 0x80021C70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021C74: sh          $t5, -0x48AC($at)
    MEM_H(-0X48AC, ctx->r1) = ctx->r13;
L_80021C78:
    // 0x80021C78: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80021C7C: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80021C80: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80021C84: lhu         $t8, 0x11AC($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X11AC);
    // 0x80021C88: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x80021C8C: nop

    // 0x80021C90: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80021C94: beq         $t9, $zero, L_80021CC4
    if (ctx->r25 == 0) {
        // 0x80021C98: nop

            goto L_80021CC4;
    }
    // 0x80021C98: nop

    // 0x80021C9C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80021CA0: lh          $t0, -0x48AC($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X48AC);
    // 0x80021CA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021CA8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80021CAC: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80021CB0: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80021CB4: bgez        $t3, L_80021CC4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80021CB8: sh          $t1, -0x48AC($at)
        MEM_H(-0X48AC, ctx->r1) = ctx->r9;
            goto L_80021CC4;
    }
    // 0x80021CB8: sh          $t1, -0x48AC($at)
    MEM_H(-0X48AC, ctx->r1) = ctx->r9;
    // 0x80021CBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80021CC0: sh          $zero, -0x48AC($at)
    MEM_H(-0X48AC, ctx->r1) = 0;
L_80021CC4:
    // 0x80021CC4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80021CC8: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80021CCC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80021CD0: lhu         $t6, 0xFF4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XFF4);
    // 0x80021CD4: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80021CD8: nop

    // 0x80021CDC: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x80021CE0: beq         $t7, $zero, L_80021D08
    if (ctx->r15 == 0) {
        // 0x80021CE4: nop

            goto L_80021D08;
    }
    // 0x80021CE4: nop

    // 0x80021CE8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80021CEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80021CF0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80021CF4: lh          $a2, -0x48AC($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X48AC);
    // 0x80021CF8: lh          $a1, -0x48B0($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X48B0);
    // 0x80021CFC: lw          $a0, -0x33B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33B8);
    // 0x80021D00: jal         0x8002206C
    // 0x80021D04: nop

    func_8002206C(rdram, ctx);
        goto after_0;
    // 0x80021D04: nop

    after_0:
L_80021D08:
    // 0x80021D08: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80021D0C: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x80021D10: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80021D14: lhu         $t0, 0x101C($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X101C);
    // 0x80021D18: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x80021D1C: nop

    // 0x80021D20: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x80021D24: beq         $t1, $zero, L_80021D3C
    if (ctx->r9 == 0) {
        // 0x80021D28: nop

            goto L_80021D3C;
    }
    // 0x80021D28: nop

    // 0x80021D2C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80021D30: lw          $a0, -0x33B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33B8);
    // 0x80021D34: jal         0x800220F4
    // 0x80021D38: nop

    func_800220F4(rdram, ctx);
        goto after_1;
    // 0x80021D38: nop

    after_1:
L_80021D3C:
    // 0x80021D3C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80021D40: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80021D44: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80021D48: lh          $a3, -0x48AC($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X48AC);
    // 0x80021D4C: lh          $a2, -0x48B0($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X48B0);
    // 0x80021D50: lw          $a1, -0x33B8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X33B8);
    // 0x80021D54: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021D58: jal         0x8008ECE4
    // 0x80021D5C: addiu       $a0, $a0, -0x1D10
    ctx->r4 = ADD32(ctx->r4, -0X1D10);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x80021D5C: addiu       $a0, $a0, -0x1D10
    ctx->r4 = ADD32(ctx->r4, -0X1D10);
    after_2:
    // 0x80021D60: b           L_80021D70
    // 0x80021D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021D70;
    // 0x80021D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021D68: b           L_80021D70
    // 0x80021D6C: nop

        goto L_80021D70;
    // 0x80021D6C: nop

L_80021D70:
    // 0x80021D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021D78: jr          $ra
    // 0x80021D7C: nop

    return;
    // 0x80021D7C: nop

;}
