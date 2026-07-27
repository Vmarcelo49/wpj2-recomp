#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8007713C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007713C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077144: jal         0x80061488
    // 0x80077148: addiu       $a0, $zero, 0x55C
    ctx->r4 = ADD32(0, 0X55C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077148: addiu       $a0, $zero, 0x55C
    ctx->r4 = ADD32(0, 0X55C);
    after_0:
    // 0x8007714C: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80077150: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80077154: b           L_80077164
    // 0x80077158: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077164;
    // 0x80077158: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007715C: b           L_80077164
    // 0x80077160: nop

        goto L_80077164;
    // 0x80077160: nop

L_80077164:
    // 0x80077164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007716C: jr          $ra
    // 0x80077170: nop

    return;
    // 0x80077170: nop

;}
RECOMP_FUNC void alSndpStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9780: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9788: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800C978C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C9790: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800C9794: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800C9798: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800C979C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800C97A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C97A4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800C97A8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800C97AC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C97B0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800C97B4: jal         0x800D3A2C
    // 0x800C97B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C97B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C97BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C97C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C97C4: jr          $ra
    // 0x800C97C8: nop

    return;
    // 0x800C97C8: nop

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
RECOMP_FUNC void func_80077FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077FB8: jal         0x8005F064
    // 0x80077FBC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80077FBC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_0:
    // 0x80077FC0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077FC4: b           L_80077FD4
    // 0x80077FC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077FD4;
    // 0x80077FC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077FCC: b           L_80077FD4
    // 0x80077FD0: nop

        goto L_80077FD4;
    // 0x80077FD0: nop

L_80077FD4:
    // 0x80077FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077FDC: jr          $ra
    // 0x80077FE0: nop

    return;
    // 0x80077FE0: nop

;}
RECOMP_FUNC void func_80072C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072C7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072C80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072C84: nop

    // 0x80072C88: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80072C8C: nop

    // 0x80072C90: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072C94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072C98: jr          $ra
    // 0x80072C9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072C9C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072CA0: jr          $ra
    // 0x80072CA4: nop

    return;
    // 0x80072CA4: nop

    // 0x80072CA8: jr          $ra
    // 0x80072CAC: nop

    return;
    // 0x80072CAC: nop

;}
RECOMP_FUNC void func_8006D124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D124: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D128: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D12C: nop

    // 0x8006D130: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D134: nop

    // 0x8006D138: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x8006D13C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D140: jr          $ra
    // 0x8006D144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D148: jr          $ra
    // 0x8006D14C: nop

    return;
    // 0x8006D14C: nop

    // 0x8006D150: jr          $ra
    // 0x8006D154: nop

    return;
    // 0x8006D154: nop

;}
RECOMP_FUNC void func_80062F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062F54: jal         0x8005F064
    // 0x80062F58: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062F58: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_0:
    // 0x80062F5C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80062F60: b           L_80062F70
    // 0x80062F64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80062F70;
    // 0x80062F64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80062F68: b           L_80062F70
    // 0x80062F6C: nop

        goto L_80062F70;
    // 0x80062F6C: nop

L_80062F70:
    // 0x80062F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062F78: jr          $ra
    // 0x80062F7C: nop

    return;
    // 0x80062F7C: nop

;}
RECOMP_FUNC void func_8007A0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A0B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007A0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A0B8: jal         0x800317E4
    // 0x8007A0BC: nop

    func_800317E4(rdram, ctx);
        goto after_0;
    // 0x8007A0BC: nop

    after_0:
    // 0x8007A0C0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007A0C4: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007A0C8: nop

    // 0x8007A0CC: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x8007A0D0: nop

    // 0x8007A0D4: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x8007A0D8: sw          $t8, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r24;
    // 0x8007A0DC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8007A0E0: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x8007A0E4: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8007A0E8: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x8007A0EC: nop

    // 0x8007A0F0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8007A0F4: sw          $t1, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r9;
    // 0x8007A0F8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_8007A0FC:
    // 0x8007A0FC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8007A100: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8007A104: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8007A108: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007A10C: lw          $t4, -0x3914($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3914);
    // 0x8007A110: nop

    // 0x8007A114: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8007A118: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007A11C: lwc1        $f8, -0x3890($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3890);
    // 0x8007A120: lwc1        $f10, -0x388C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X388C);
    // 0x8007A124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007A128: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007A12C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007A130: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007A134: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x8007A138: nop

    // 0x8007A13C: bc1f        L_8007A190
    if (!c1cs) {
        // 0x8007A140: nop
    
            goto L_8007A190;
    }
    // 0x8007A140: nop

L_8007A144:
    // 0x8007A144: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007A148: nop

    // 0x8007A14C: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x8007A150: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A154: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8007A158: lwc1        $f8, -0x3890($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3890);
    // 0x8007A15C: lwc1        $f10, -0x388C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X388C);
    // 0x8007A160: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007A164: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8007A168: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007A16C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007A170: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007A174: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8007A178: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007A17C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8007A180: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8007A184: nop

    // 0x8007A188: bc1t        L_8007A144
    if (c1cs) {
        // 0x8007A18C: nop
    
            goto L_8007A144;
    }
    // 0x8007A18C: nop

L_8007A190:
    // 0x8007A190: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A194: nop

    // 0x8007A198: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8007A19C: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8007A1A0: bne         $at, $zero, L_8007A0FC
    if (ctx->r1 != 0) {
        // 0x8007A1A4: sw          $t9, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r25;
            goto L_8007A0FC;
    }
    // 0x8007A1A4: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007A1A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A1AC: sh          $zero, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = 0;
    // 0x8007A1B0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8007A1B4: lw          $t2, 0x7100($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7100);
    // 0x8007A1B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A1BC: bne         $t2, $at, L_8007A210
    if (ctx->r10 != ctx->r1) {
        // 0x8007A1C0: nop
    
            goto L_8007A210;
    }
    // 0x8007A1C0: nop

    // 0x8007A1C4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007A1C8: lw          $t3, 0x7104($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7104);
    // 0x8007A1CC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007A1D0: bne         $t3, $at, L_8007A210
    if (ctx->r11 != ctx->r1) {
        // 0x8007A1D4: nop
    
            goto L_8007A210;
    }
    // 0x8007A1D4: nop

    // 0x8007A1D8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007A1DC: lh          $t4, 0x72AC($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X72AC);
    // 0x8007A1E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A1E4: bne         $t4, $at, L_8007A210
    if (ctx->r12 != ctx->r1) {
        // 0x8007A1E8: nop
    
            goto L_8007A210;
    }
    // 0x8007A1E8: nop

    // 0x8007A1EC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A1F0: lh          $t5, 0x72B4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X72B4);
    // 0x8007A1F4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007A1F8: bne         $t5, $at, L_8007A210
    if (ctx->r13 != ctx->r1) {
        // 0x8007A1FC: nop
    
            goto L_8007A210;
    }
    // 0x8007A1FC: nop

    // 0x8007A200: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007A204: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007A208: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A20C: sb          $t7, 0x7141($at)
    MEM_B(0X7141, ctx->r1) = ctx->r15;
L_8007A210:
    // 0x8007A210: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A214: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x8007A218: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A21C: bne         $t6, $at, L_8007A290
    if (ctx->r14 != ctx->r1) {
        // 0x8007A220: nop
    
            goto L_8007A290;
    }
    // 0x8007A220: nop

    // 0x8007A224: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007A228: lw          $t0, 0x7104($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7104);
    // 0x8007A22C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007A230: bne         $t0, $at, L_8007A290
    if (ctx->r8 != ctx->r1) {
        // 0x8007A234: nop
    
            goto L_8007A290;
    }
    // 0x8007A234: nop

    // 0x8007A238: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A23C: lh          $t8, 0x72AC($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X72AC);
    // 0x8007A240: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A244: bne         $t8, $at, L_8007A290
    if (ctx->r24 != ctx->r1) {
        // 0x8007A248: nop
    
            goto L_8007A290;
    }
    // 0x8007A248: nop

    // 0x8007A24C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007A250: lh          $t1, 0x72B4($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X72B4);
    // 0x8007A254: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007A258: bne         $t1, $at, L_8007A290
    if (ctx->r9 != ctx->r1) {
        // 0x8007A25C: nop
    
            goto L_8007A290;
    }
    // 0x8007A25C: nop

    // 0x8007A260: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007A264: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007A268: nop

    // 0x8007A26C: andi        $t2, $t9, 0x100
    ctx->r10 = ctx->r25 & 0X100;
    // 0x8007A270: beq         $t2, $zero, L_8007A284
    if (ctx->r10 == 0) {
        // 0x8007A274: nop
    
            goto L_8007A284;
    }
    // 0x8007A274: nop

    // 0x8007A278: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A27C: b           L_8007A290
    // 0x8007A280: sh          $zero, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = 0;
        goto L_8007A290;
    // 0x8007A280: sh          $zero, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = 0;
L_8007A284:
    // 0x8007A284: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007A288: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A28C: sh          $t3, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r11;
L_8007A290:
    // 0x8007A290: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007A294: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007A298: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A29C: bne         $t4, $at, L_8007A2C8
    if (ctx->r12 != ctx->r1) {
        // 0x8007A2A0: nop
    
            goto L_8007A2C8;
    }
    // 0x8007A2A0: nop

    // 0x8007A2A4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A2A8: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007A2AC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8007A2B0: bne         $t5, $at, L_8007A2C8
    if (ctx->r13 != ctx->r1) {
        // 0x8007A2B4: nop
    
            goto L_8007A2C8;
    }
    // 0x8007A2B4: nop

    // 0x8007A2B8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007A2BC: lb          $t7, 0x7142($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X7142);
    // 0x8007A2C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A2C4: sh          $t7, 0x7132($at)
    MEM_H(0X7132, ctx->r1) = ctx->r15;
L_8007A2C8:
    // 0x8007A2C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A2CC: lh          $t6, 0x72AC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72AC);
    // 0x8007A2D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A2D4: sw          $t6, 0x7100($at)
    MEM_W(0X7100, ctx->r1) = ctx->r14;
    // 0x8007A2D8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8007A2DC: lh          $t0, 0x72B4($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X72B4);
    // 0x8007A2E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A2E4: sw          $t0, 0x7104($at)
    MEM_W(0X7104, ctx->r1) = ctx->r8;
    // 0x8007A2E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A2EC: sb          $zero, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = 0;
    // 0x8007A2F0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A2F4: lw          $t8, 0x7100($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7100);
    // 0x8007A2F8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A2FC: bne         $t8, $at, L_8007A35C
    if (ctx->r24 != ctx->r1) {
        // 0x8007A300: nop
    
            goto L_8007A35C;
    }
    // 0x8007A300: nop

    // 0x8007A304: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007A308: lw          $t1, 0x7104($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7104);
    // 0x8007A30C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007A310: bne         $t1, $at, L_8007A35C
    if (ctx->r9 != ctx->r1) {
        // 0x8007A314: nop
    
            goto L_8007A35C;
    }
    // 0x8007A314: nop

    // 0x8007A318: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007A31C: jal         0x8007A514
    // 0x8007A320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8007A514(rdram, ctx);
        goto after_1;
    // 0x8007A320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8007A324: bne         $v0, $zero, L_8007A344
    if (ctx->r2 != 0) {
        // 0x8007A328: nop
    
            goto L_8007A344;
    }
    // 0x8007A328: nop

    // 0x8007A32C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007A330: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x8007A334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A338: ori         $t2, $t9, 0x100
    ctx->r10 = ctx->r25 | 0X100;
    // 0x8007A33C: b           L_8007A35C
    // 0x8007A340: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
        goto L_8007A35C;
    // 0x8007A340: sh          $t2, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r10;
L_8007A344:
    // 0x8007A344: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007A348: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x8007A34C: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x8007A350: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8007A354: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A358: sh          $t4, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r12;
L_8007A35C:
    // 0x8007A35C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A360: lw          $t5, 0x7100($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7100);
    // 0x8007A364: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A368: bne         $t5, $at, L_8007A3BC
    if (ctx->r13 != ctx->r1) {
        // 0x8007A36C: nop
    
            goto L_8007A3BC;
    }
    // 0x8007A36C: nop

    // 0x8007A370: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8007A374: lw          $t7, 0x7104($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7104);
    // 0x8007A378: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8007A37C: bne         $t7, $at, L_8007A3BC
    if (ctx->r15 != ctx->r1) {
        // 0x8007A380: nop
    
            goto L_8007A3BC;
    }
    // 0x8007A380: nop

    // 0x8007A384: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A388: lb          $t6, 0x7141($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X7141);
    // 0x8007A38C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A390: sb          $t6, 0x7142($at)
    MEM_B(0X7142, ctx->r1) = ctx->r14;
    // 0x8007A394: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007A398: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A39C: sb          $t0, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = ctx->r8;
    // 0x8007A3A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007A3A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007A3A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A3AC: swc1        $f16, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f16.u32l;
    // 0x8007A3B0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8007A3B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A3B8: sb          $t8, 0x7143($at)
    MEM_B(0X7143, ctx->r1) = ctx->r24;
L_8007A3BC:
    // 0x8007A3BC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8007A3C0: lw          $t1, 0x7100($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7100);
    // 0x8007A3C4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A3C8: bne         $t1, $at, L_8007A40C
    if (ctx->r9 != ctx->r1) {
        // 0x8007A3CC: nop
    
            goto L_8007A40C;
    }
    // 0x8007A3CC: nop

    // 0x8007A3D0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007A3D4: lw          $t9, 0x7104($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7104);
    // 0x8007A3D8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8007A3DC: bne         $t9, $at, L_8007A40C
    if (ctx->r25 != ctx->r1) {
        // 0x8007A3E0: nop
    
            goto L_8007A40C;
    }
    // 0x8007A3E0: nop

    // 0x8007A3E4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8007A3E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A3EC: sb          $t2, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = ctx->r10;
    // 0x8007A3F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007A3F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007A3F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A3FC: swc1        $f18, 0x713C($at)
    MEM_W(0X713C, ctx->r1) = ctx->f18.u32l;
    // 0x8007A400: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8007A404: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A408: sb          $t3, 0x7143($at)
    MEM_B(0X7143, ctx->r1) = ctx->r11;
L_8007A40C:
    // 0x8007A40C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007A410: lw          $t4, 0x7100($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7100);
    // 0x8007A414: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007A418: bne         $t4, $at, L_8007A440
    if (ctx->r12 != ctx->r1) {
        // 0x8007A41C: nop
    
            goto L_8007A440;
    }
    // 0x8007A41C: nop

    // 0x8007A420: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8007A424: lw          $t5, 0x7104($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7104);
    // 0x8007A428: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8007A42C: bne         $t5, $at, L_8007A440
    if (ctx->r13 != ctx->r1) {
        // 0x8007A430: nop
    
            goto L_8007A440;
    }
    // 0x8007A430: nop

    // 0x8007A434: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8007A438: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A43C: sb          $t7, 0x7134($at)
    MEM_B(0X7134, ctx->r1) = ctx->r15;
L_8007A440:
    // 0x8007A440: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8007A444: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x8007A448: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8007A44C: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x8007A450: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A454: sh          $t0, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r8;
    // 0x8007A458: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007A45C: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007A460: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x8007A464: and         $t1, $t8, $at
    ctx->r9 = ctx->r24 & ctx->r1;
    // 0x8007A468: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007A46C: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x8007A470: b           L_8007A478
    // 0x8007A474: nop

        goto L_8007A478;
    // 0x8007A474: nop

L_8007A478:
    // 0x8007A478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A47C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007A480: jr          $ra
    // 0x8007A484: nop

    return;
    // 0x8007A484: nop

;}
RECOMP_FUNC void func_800707F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800707F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800707FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070800: jal         0x80061348
    // 0x80070804: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070804: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070808: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007080C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070810: beq         $v0, $zero, L_80070860
    if (ctx->r2 == 0) {
        // 0x80070814: nop
    
            goto L_80070860;
    }
    // 0x80070814: nop

    // 0x80070818: jal         0x80061348
    // 0x8007081C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007081C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070820: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070824: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070828: beq         $v0, $zero, L_80070860
    if (ctx->r2 == 0) {
        // 0x8007082C: nop
    
            goto L_80070860;
    }
    // 0x8007082C: nop

    // 0x80070830: jal         0x80061348
    // 0x80070834: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070834: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070838: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007083C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070840: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070844: beq         $v0, $zero, L_80070860
    if (ctx->r2 == 0) {
        // 0x80070848: nop
    
            goto L_80070860;
    }
    // 0x80070848: nop

    // 0x8007084C: jal         0x80061348
    // 0x80070850: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070850: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070854: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070858: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007085C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070860:
    // 0x80070860: b           L_80070870
    // 0x80070864: nop

        goto L_80070870;
    // 0x80070864: nop

    // 0x80070868: b           L_80070870
    // 0x8007086C: nop

        goto L_80070870;
    // 0x8007086C: nop

L_80070870:
    // 0x80070870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070878: jr          $ra
    // 0x8007087C: nop

    return;
    // 0x8007087C: nop

;}
RECOMP_FUNC void SysMem_Copy8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCFCC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BCFD0: bne         $a2, $zero, L_800BCFE0
    if (ctx->r6 != 0) {
        // 0x800BCFD4: nop
    
            goto L_800BCFE0;
    }
    // 0x800BCFD4: nop

    // 0x800BCFD8: b           L_800BD030
    // 0x800BCFDC: nop

        goto L_800BD030;
    // 0x800BCFDC: nop

L_800BCFE0:
    // 0x800BCFE0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BCFE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BCFE8: blez        $a2, L_800BD028
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BCFEC: nop
    
            goto L_800BD028;
    }
    // 0x800BCFEC: nop

L_800BCFF0:
    // 0x800BCFF0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BCFF4: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BCFF8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800BCFFC: nop

    // 0x800BD000: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800BD004: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800BD008: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800BD00C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800BD010: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800BD014: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x800BD018: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x800BD01C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800BD020: bgtz        $a2, L_800BCFF0
    if (SIGNED(ctx->r6) > 0) {
        // 0x800BD024: nop
    
            goto L_800BCFF0;
    }
    // 0x800BD024: nop

L_800BD028:
    // 0x800BD028: b           L_800BD030
    // 0x800BD02C: nop

        goto L_800BD030;
    // 0x800BD02C: nop

L_800BD030:
    // 0x800BD030: jr          $ra
    // 0x800BD034: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD034: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006DFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DFE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DFE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DFEC: jal         0x80061348
    // 0x8006DFF0: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DFF0: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_0:
    // 0x8006DFF4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DFF8: b           L_8006E008
    // 0x8006DFFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006E008;
    // 0x8006DFFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006E000: b           L_8006E008
    // 0x8006E004: nop

        goto L_8006E008;
    // 0x8006E004: nop

L_8006E008:
    // 0x8006E008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E00C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E010: jr          $ra
    // 0x8006E014: nop

    return;
    // 0x8006E014: nop

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
RECOMP_FUNC void func_8007272C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007272C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072730: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072734: nop

    // 0x80072738: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8007273C: nop

    // 0x80072740: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80072744: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072748: jr          $ra
    // 0x8007274C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007274C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072750: jr          $ra
    // 0x80072754: nop

    return;
    // 0x80072754: nop

    // 0x80072758: jr          $ra
    // 0x8007275C: nop

    return;
    // 0x8007275C: nop

;}
RECOMP_FUNC void func_80031C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80031C94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031C98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80031C9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80031CA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80031CA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80031CA8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80031CAC: nop

    // 0x80031CB0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80031CB4: bne         $t7, $zero, L_80031D10
    if (ctx->r15 != 0) {
        // 0x80031CB8: nop
    
            goto L_80031D10;
    }
    // 0x80031CB8: nop

    // 0x80031CBC: jal         0x80004654
    // 0x80031CC0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80004654(rdram, ctx);
        goto after_0;
    // 0x80031CC0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80031CC4: bgez        $v0, L_80031CD4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80031CC8: nop
    
            goto L_80031CD4;
    }
    // 0x80031CC8: nop

    // 0x80031CCC: b           L_80031D84
    // 0x80031CD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80031D84;
    // 0x80031CD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80031CD4:
    // 0x80031CD4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80031CD8: lw          $t8, 0x6C10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6C10);
    // 0x80031CDC: nop

    // 0x80031CE0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80031CE4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80031CE8: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80031CEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80031CF0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80031CF4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80031CF8: andi        $t9, $a1, 0xFF00
    ctx->r25 = ctx->r5 & 0XFF00;
    // 0x80031CFC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80031D00: jal         0x80031E3C
    // 0x80031D04: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80031E3C(rdram, ctx);
        goto after_1;
    // 0x80031D04: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x80031D08: b           L_80031D84
    // 0x80031D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80031D84;
    // 0x80031D0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80031D10:
    // 0x80031D10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80031D14: nop

    // 0x80031D18: andi        $t2, $t1, 0x100
    ctx->r10 = ctx->r9 & 0X100;
    // 0x80031D1C: bne         $t2, $zero, L_80031D74
    if (ctx->r10 != 0) {
        // 0x80031D20: nop
    
            goto L_80031D74;
    }
    // 0x80031D20: nop

    // 0x80031D24: jal         0x800045AC
    // 0x80031D28: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800045AC(rdram, ctx);
        goto after_2;
    // 0x80031D28: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_2:
    // 0x80031D2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80031D30: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80031D34: nop

    // 0x80031D38: bne         $t3, $zero, L_80031D48
    if (ctx->r11 != 0) {
        // 0x80031D3C: nop
    
            goto L_80031D48;
    }
    // 0x80031D3C: nop

    // 0x80031D40: b           L_80031D84
    // 0x80031D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031D84;
    // 0x80031D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031D48:
    // 0x80031D48: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80031D4C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80031D50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80031D54: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80031D58: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80031D5C: andi        $t4, $a1, 0xFF00
    ctx->r12 = ctx->r5 & 0XFF00;
    // 0x80031D60: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80031D64: jal         0x80031E3C
    // 0x80031D68: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_80031E3C(rdram, ctx);
        goto after_3;
    // 0x80031D68: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x80031D6C: b           L_80031D84
    // 0x80031D70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80031D84;
    // 0x80031D70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80031D74:
    // 0x80031D74: b           L_80031D84
    // 0x80031D78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031D84;
    // 0x80031D78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031D7C: b           L_80031D84
    // 0x80031D80: nop

        goto L_80031D84;
    // 0x80031D80: nop

L_80031D84:
    // 0x80031D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031D88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80031D8C: jr          $ra
    // 0x80031D90: nop

    return;
    // 0x80031D90: nop

;}
RECOMP_FUNC void func_80064E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064E88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80064E8C: nop

    // 0x80064E90: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80064E94: nop

    // 0x80064E98: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80064E9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064EA0: jr          $ra
    // 0x80064EA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80064EA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064EA8: jr          $ra
    // 0x80064EAC: nop

    return;
    // 0x80064EAC: nop

    // 0x80064EB0: jr          $ra
    // 0x80064EB4: nop

    return;
    // 0x80064EB4: nop

;}
RECOMP_FUNC void SysMem_Copy64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD110: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD114: bne         $a2, $zero, L_800BD124
    if (ctx->r6 != 0) {
        // 0x800BD118: nop
    
            goto L_800BD124;
    }
    // 0x800BD118: nop

    // 0x800BD11C: b           L_800BD178
    // 0x800BD120: nop

        goto L_800BD178;
    // 0x800BD120: nop

L_800BD124:
    // 0x800BD124: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BD128: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BD12C: blez        $a2, L_800BD170
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BD130: nop
    
            goto L_800BD170;
    }
    // 0x800BD130: nop

L_800BD134:
    // 0x800BD134: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800BD138: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800BD13C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800BD140: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800BD144: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800BD148: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800BD14C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800BD150: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800BD154: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800BD158: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800BD15C: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800BD160: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800BD164: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800BD168: bgtz        $a2, L_800BD134
    if (SIGNED(ctx->r6) > 0) {
        // 0x800BD16C: nop
    
            goto L_800BD134;
    }
    // 0x800BD16C: nop

L_800BD170:
    // 0x800BD170: b           L_800BD178
    // 0x800BD174: nop

        goto L_800BD178;
    // 0x800BD174: nop

L_800BD178:
    // 0x800BD178: jr          $ra
    // 0x800BD17C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD17C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006CEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CEE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CEEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CEF0: nop

    // 0x8006CEF4: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x8006CEF8: nop

    // 0x8006CEFC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CF00: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CF04: jr          $ra
    // 0x8006CF08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CF08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CF0C: jr          $ra
    // 0x8006CF10: nop

    return;
    // 0x8006CF10: nop

    // 0x8006CF14: jr          $ra
    // 0x8006CF18: nop

    return;
    // 0x8006CF18: nop

;}
RECOMP_FUNC void func_800749EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800749EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800749F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800749F4: jal         0x80061348
    // 0x800749F8: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800749F8: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x800749FC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074A00: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074A04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074A08: beq         $v0, $zero, L_80074A5C
    if (ctx->r2 == 0) {
        // 0x80074A0C: nop
    
            goto L_80074A5C;
    }
    // 0x80074A0C: nop

    // 0x80074A10: jal         0x80061348
    // 0x80074A14: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074A14: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074A18: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074A1C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074A20: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074A24: beq         $v0, $zero, L_80074A5C
    if (ctx->r2 == 0) {
        // 0x80074A28: nop
    
            goto L_80074A5C;
    }
    // 0x80074A28: nop

    // 0x80074A2C: jal         0x80061348
    // 0x80074A30: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074A30: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074A34: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074A38: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074A3C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074A40: beq         $v0, $zero, L_80074A5C
    if (ctx->r2 == 0) {
        // 0x80074A44: nop
    
            goto L_80074A5C;
    }
    // 0x80074A44: nop

    // 0x80074A48: jal         0x80061348
    // 0x80074A4C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074A4C: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074A50: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074A54: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074A58: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074A5C:
    // 0x80074A5C: b           L_80074A6C
    // 0x80074A60: nop

        goto L_80074A6C;
    // 0x80074A60: nop

    // 0x80074A64: b           L_80074A6C
    // 0x80074A68: nop

        goto L_80074A6C;
    // 0x80074A68: nop

L_80074A6C:
    // 0x80074A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074A74: jr          $ra
    // 0x80074A78: nop

    return;
    // 0x80074A78: nop

;}
RECOMP_FUNC void func_80072D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072D1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072D20: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072D24: nop

    // 0x80072D28: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072D2C: nop

    // 0x80072D30: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80072D34: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072D38: jr          $ra
    // 0x80072D3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072D3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072D40: jr          $ra
    // 0x80072D44: nop

    return;
    // 0x80072D44: nop

    // 0x80072D48: jr          $ra
    // 0x80072D4C: nop

    return;
    // 0x80072D4C: nop

;}
RECOMP_FUNC void func_80079CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079CCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079CD4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80079CD8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079CDC: lh          $t6, 0x713A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X713A);
    // 0x80079CE0: nop

    // 0x80079CE4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80079CE8: beq         $t7, $zero, L_80079CF8
    if (ctx->r15 == 0) {
        // 0x80079CEC: nop
    
            goto L_80079CF8;
    }
    // 0x80079CEC: nop

    // 0x80079CF0: b           L_80079F24
    // 0x80079CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079CF8:
    // 0x80079CF8: jal         0x8007C54C
    // 0x80079CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8007C54C(rdram, ctx);
        goto after_0;
    // 0x80079CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80079D00: beq         $v0, $zero, L_80079D10
    if (ctx->r2 == 0) {
        // 0x80079D04: nop
    
            goto L_80079D10;
    }
    // 0x80079D04: nop

    // 0x80079D08: b           L_80079F24
    // 0x80079D0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079D0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079D10:
    // 0x80079D10: jal         0x8007D538
    // 0x80079D14: nop

    func_8007D538(rdram, ctx);
        goto after_1;
    // 0x80079D14: nop

    after_1:
    // 0x80079D18: jal         0x8007B710
    // 0x80079D1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8007B710(rdram, ctx);
        goto after_2;
    // 0x80079D1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80079D20: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80079D24: jal         0x8007DF3C
    // 0x80079D28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8007DF3C(rdram, ctx);
        goto after_3;
    // 0x80079D28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80079D2C: beq         $v0, $zero, L_80079D3C
    if (ctx->r2 == 0) {
        // 0x80079D30: nop
    
            goto L_80079D3C;
    }
    // 0x80079D30: nop

    // 0x80079D34: b           L_80079F24
    // 0x80079D38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079D38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079D3C:
    // 0x80079D3C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80079D40: nop

    // 0x80079D44: beq         $t8, $zero, L_80079D54
    if (ctx->r24 == 0) {
        // 0x80079D48: nop
    
            goto L_80079D54;
    }
    // 0x80079D48: nop

    // 0x80079D4C: b           L_80079F24
    // 0x80079D50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079D50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079D54:
    // 0x80079D54: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80079D58: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x80079D5C: nop

    // 0x80079D60: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x80079D64: beq         $t0, $zero, L_80079D98
    if (ctx->r8 == 0) {
        // 0x80079D68: nop
    
            goto L_80079D98;
    }
    // 0x80079D68: nop

    // 0x80079D6C: andi        $t1, $t9, 0x10
    ctx->r9 = ctx->r25 & 0X10;
    // 0x80079D70: bne         $t1, $zero, L_80079D98
    if (ctx->r9 != 0) {
        // 0x80079D74: nop
    
            goto L_80079D98;
    }
    // 0x80079D74: nop

    // 0x80079D78: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80079D7C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80079D80: lh          $a1, 0x7138($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7138);
    // 0x80079D84: lh          $a0, 0x7136($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7136);
    // 0x80079D88: jal         0x8007A488
    // 0x80079D8C: nop

    func_8007A488(rdram, ctx);
        goto after_4;
    // 0x80079D8C: nop

    after_4:
    // 0x80079D90: b           L_80079F24
    // 0x80079D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079D98:
    // 0x80079D98: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079D9C: lh          $t2, 0x7130($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7130);
    // 0x80079DA0: nop

    // 0x80079DA4: beq         $t2, $zero, L_80079DBC
    if (ctx->r10 == 0) {
        // 0x80079DA8: nop
    
            goto L_80079DBC;
    }
    // 0x80079DA8: nop

    // 0x80079DAC: jal         0x8007FA64
    // 0x80079DB0: nop

    func_8007FA64(rdram, ctx);
        goto after_5;
    // 0x80079DB0: nop

    after_5:
    // 0x80079DB4: b           L_80079F24
    // 0x80079DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079DBC:
    // 0x80079DBC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80079DC0: lh          $t3, 0x713A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X713A);
    // 0x80079DC4: nop

    // 0x80079DC8: andi        $t4, $t3, 0x200
    ctx->r12 = ctx->r11 & 0X200;
    // 0x80079DCC: bne         $t4, $zero, L_80079DF4
    if (ctx->r12 != 0) {
        // 0x80079DD0: nop
    
            goto L_80079DF4;
    }
    // 0x80079DD0: nop

    // 0x80079DD4: jal         0x80031AC8
    // 0x80079DD8: nop

    func_80031AC8(rdram, ctx);
        goto after_6;
    // 0x80079DD8: nop

    after_6:
    // 0x80079DDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80079DE0: bne         $v0, $at, L_80079DF4
    if (ctx->r2 != ctx->r1) {
        // 0x80079DE4: nop
    
            goto L_80079DF4;
    }
    // 0x80079DE4: nop

    // 0x80079DE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80079DEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80079DF0: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
L_80079DF4:
    // 0x80079DF4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079DF8: lh          $t5, 0x713A($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X713A);
    // 0x80079DFC: nop

    // 0x80079E00: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80079E04: beq         $t6, $zero, L_80079E94
    if (ctx->r14 == 0) {
        // 0x80079E08: nop
    
            goto L_80079E94;
    }
    // 0x80079E08: nop

    // 0x80079E0C: jal         0x80031AC8
    // 0x80079E10: nop

    func_80031AC8(rdram, ctx);
        goto after_7;
    // 0x80079E10: nop

    after_7:
    // 0x80079E14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80079E18: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80079E1C: lh          $t7, 0x713A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X713A);
    // 0x80079E20: nop

    // 0x80079E24: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x80079E28: beq         $t8, $zero, L_80079E4C
    if (ctx->r24 == 0) {
        // 0x80079E2C: nop
    
            goto L_80079E4C;
    }
    // 0x80079E2C: nop

    // 0x80079E30: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80079E34: nop

    // 0x80079E38: beq         $t0, $zero, L_80079E4C
    if (ctx->r8 == 0) {
        // 0x80079E3C: nop
    
            goto L_80079E4C;
    }
    // 0x80079E3C: nop

    // 0x80079E40: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80079E44: bne         $t0, $at, L_80079E8C
    if (ctx->r8 != ctx->r1) {
        // 0x80079E48: nop
    
            goto L_80079E8C;
    }
    // 0x80079E48: nop

L_80079E4C:
    // 0x80079E4C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80079E50: lh          $t9, 0x713A($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X713A);
    // 0x80079E54: addiu       $at, $zero, -0x211
    ctx->r1 = ADD32(0, -0X211);
    // 0x80079E58: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x80079E5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80079E60: sh          $t1, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r9;
    // 0x80079E64: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80079E68: lh          $t2, 0x713A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X713A);
    // 0x80079E6C: nop

    // 0x80079E70: andi        $t3, $t2, 0x104
    ctx->r11 = ctx->r10 & 0X104;
    // 0x80079E74: beq         $t3, $zero, L_80079E84
    if (ctx->r11 == 0) {
        // 0x80079E78: nop
    
            goto L_80079E84;
    }
    // 0x80079E78: nop

    // 0x80079E7C: b           L_80079F24
    // 0x80079E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079E84:
    // 0x80079E84: jal         0x8007B710
    // 0x80079E88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8007B710(rdram, ctx);
        goto after_8;
    // 0x80079E88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
L_80079E8C:
    // 0x80079E8C: b           L_80079F24
    // 0x80079E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80079E94:
    // 0x80079E94: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80079E98: jal         0x80080948
    // 0x80079E9C: addiu       $a0, $a0, 0x70F0
    ctx->r4 = ADD32(ctx->r4, 0X70F0);
    func_80080948(rdram, ctx);
        goto after_9;
    // 0x80079E9C: addiu       $a0, $a0, 0x70F0
    ctx->r4 = ADD32(ctx->r4, 0X70F0);
    after_9:
    // 0x80079EA0: jal         0x8007A8B8
    // 0x80079EA4: nop

    func_8007A8B8(rdram, ctx);
        goto after_10;
    // 0x80079EA4: nop

    after_10:
    // 0x80079EA8: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80079EAC: lhu         $t4, 0x26($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X26);
    // 0x80079EB0: nop

    // 0x80079EB4: beq         $t4, $zero, L_80079F14
    if (ctx->r12 == 0) {
        // 0x80079EB8: nop
    
            goto L_80079F14;
    }
    // 0x80079EB8: nop

    // 0x80079EBC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80079EC0: lw          $t5, 0x70F8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70F8);
    // 0x80079EC4: nop

    // 0x80079EC8: beq         $t5, $zero, L_80079EDC
    if (ctx->r13 == 0) {
        // 0x80079ECC: nop
    
            goto L_80079EDC;
    }
    // 0x80079ECC: nop

    // 0x80079ED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80079ED4: bne         $t5, $at, L_80079EE8
    if (ctx->r13 != ctx->r1) {
        // 0x80079ED8: nop
    
            goto L_80079EE8;
    }
    // 0x80079ED8: nop

L_80079EDC:
    // 0x80079EDC: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x80079EE0: jal         0x8007ECB0
    // 0x80079EE4: nop

    func_8007ECB0(rdram, ctx);
        goto after_11;
    // 0x80079EE4: nop

    after_11:
L_80079EE8:
    // 0x80079EE8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80079EEC: lw          $t6, 0x70F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70F8);
    // 0x80079EF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80079EF4: beq         $t6, $at, L_80079F08
    if (ctx->r14 == ctx->r1) {
        // 0x80079EF8: nop
    
            goto L_80079F08;
    }
    // 0x80079EF8: nop

    // 0x80079EFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80079F00: bne         $t6, $at, L_80079F14
    if (ctx->r14 != ctx->r1) {
        // 0x80079F04: nop
    
            goto L_80079F14;
    }
    // 0x80079F04: nop

L_80079F08:
    // 0x80079F08: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x80079F0C: jal         0x8007F878
    // 0x80079F10: nop

    func_8007F878(rdram, ctx);
        goto after_12;
    // 0x80079F10: nop

    after_12:
L_80079F14:
    // 0x80079F14: b           L_80079F24
    // 0x80079F18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80079F24;
    // 0x80079F18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80079F1C: b           L_80079F24
    // 0x80079F20: nop

        goto L_80079F24;
    // 0x80079F20: nop

L_80079F24:
    // 0x80079F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079F28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80079F2C: jr          $ra
    // 0x80079F30: nop

    return;
    // 0x80079F30: nop

;}
RECOMP_FUNC void func_8004975C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004975C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80049760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049764: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80049768: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8004976C: nop

    // 0x80049770: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    // 0x80049774: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80049778:
    // 0x80049778: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8004977C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80049780: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80049784: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80049788: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8004978C: addiu       $t9, $t9, 0xEF8
    ctx->r25 = ADD32(ctx->r25, 0XEF8);
    // 0x80049790: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80049794: lbu         $t1, 0x20($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X20);
    // 0x80049798: nop

    // 0x8004979C: beq         $t1, $zero, L_800497E0
    if (ctx->r9 == 0) {
        // 0x800497A0: nop
    
            goto L_800497E0;
    }
    // 0x800497A0: nop

    // 0x800497A4: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800497A8: lbu         $t3, 0x1B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1B);
    // 0x800497AC: nop

    // 0x800497B0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800497B4: beq         $at, $zero, L_800497E0
    if (ctx->r1 == 0) {
        // 0x800497B8: nop
    
            goto L_800497E0;
    }
    // 0x800497B8: nop

    // 0x800497BC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800497C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800497C4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800497C8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800497CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800497D0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800497D4: lbu         $t6, 0xEF8($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0XEF8);
    // 0x800497D8: nop

    // 0x800497DC: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
L_800497E0:
    // 0x800497E0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800497E4: nop

    // 0x800497E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800497EC: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x800497F0: bne         $at, $zero, L_80049778
    if (ctx->r1 != 0) {
        // 0x800497F4: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80049778;
    }
    // 0x800497F4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800497F8: lbu         $t9, 0x1B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1B);
    // 0x800497FC: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x80049800: nop

    // 0x80049804: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80049808: beq         $at, $zero, L_8004982C
    if (ctx->r1 == 0) {
        // 0x8004980C: nop
    
            goto L_8004982C;
    }
    // 0x8004980C: nop

    // 0x80049810: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x80049814: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80049818: addiu       $a1, $a1, 0x3E30
    ctx->r5 = ADD32(ctx->r5, 0X3E30);
    // 0x8004981C: jal         0x800C1264
    // 0x80049820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_0;
    // 0x80049820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80049824: b           L_8004983C
    // 0x80049828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004983C;
    // 0x80049828: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004982C:
    // 0x8004982C: b           L_8004983C
    // 0x80049830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004983C;
    // 0x80049830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80049834: b           L_8004983C
    // 0x80049838: nop

        goto L_8004983C;
    // 0x80049838: nop

L_8004983C:
    // 0x8004983C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80049844: jr          $ra
    // 0x80049848: nop

    return;
    // 0x80049848: nop

;}
RECOMP_FUNC void func_8007410C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007410C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074114: jal         0x80061348
    // 0x80074118: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074118: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x8007411C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074120: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074124: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074128: beq         $v0, $zero, L_80074144
    if (ctx->r2 == 0) {
        // 0x8007412C: nop
    
            goto L_80074144;
    }
    // 0x8007412C: nop

    // 0x80074130: jal         0x80061348
    // 0x80074134: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074134: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074138: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007413C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074140: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074144:
    // 0x80074144: b           L_80074154
    // 0x80074148: nop

        goto L_80074154;
    // 0x80074148: nop

    // 0x8007414C: b           L_80074154
    // 0x80074150: nop

        goto L_80074154;
    // 0x80074150: nop

L_80074154:
    // 0x80074154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007415C: jr          $ra
    // 0x80074160: nop

    return;
    // 0x80074160: nop

;}
RECOMP_FUNC void func_8005274C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005274C: jr          $ra
    // 0x80052750: nop

    return;
    // 0x80052750: nop

    // 0x80052754: jr          $ra
    // 0x80052758: nop

    return;
    // 0x80052758: nop

;}
RECOMP_FUNC void func_800638EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800638EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800638F0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800638F4: nop

    // 0x800638F8: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x800638FC: nop

    // 0x80063900: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80063904: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063908: jr          $ra
    // 0x8006390C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006390C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063910: jr          $ra
    // 0x80063914: nop

    return;
    // 0x80063914: nop

    // 0x80063918: jr          $ra
    // 0x8006391C: nop

    return;
    // 0x8006391C: nop

;}
RECOMP_FUNC void func_8006F834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F83C: jal         0x80061348
    // 0x8006F840: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F840: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006F844: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F848: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F84C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F850: beq         $v0, $zero, L_8006F8A4
    if (ctx->r2 == 0) {
        // 0x8006F854: nop
    
            goto L_8006F8A4;
    }
    // 0x8006F854: nop

    // 0x8006F858: jal         0x80061348
    // 0x8006F85C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006F85C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006F860: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006F864: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006F868: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F86C: beq         $v0, $zero, L_8006F8A4
    if (ctx->r2 == 0) {
        // 0x8006F870: nop
    
            goto L_8006F8A4;
    }
    // 0x8006F870: nop

    // 0x8006F874: jal         0x80061348
    // 0x8006F878: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006F878: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006F87C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006F880: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006F884: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006F888: beq         $v0, $zero, L_8006F8A4
    if (ctx->r2 == 0) {
        // 0x8006F88C: nop
    
            goto L_8006F8A4;
    }
    // 0x8006F88C: nop

    // 0x8006F890: jal         0x80061348
    // 0x8006F894: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006F894: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006F898: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006F89C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006F8A0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006F8A4:
    // 0x8006F8A4: b           L_8006F8B4
    // 0x8006F8A8: nop

        goto L_8006F8B4;
    // 0x8006F8A8: nop

    // 0x8006F8AC: b           L_8006F8B4
    // 0x8006F8B0: nop

        goto L_8006F8B4;
    // 0x8006F8B0: nop

L_8006F8B4:
    // 0x8006F8B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F8B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F8BC: jr          $ra
    // 0x8006F8C0: nop

    return;
    // 0x8006F8C0: nop

;}
RECOMP_FUNC void func_80064E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064E5C: jal         0x8005F064
    // 0x80064E60: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064E60: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_0:
    // 0x80064E64: b           L_80064E74
    // 0x80064E68: nop

        goto L_80064E74;
    // 0x80064E68: nop

    // 0x80064E6C: b           L_80064E74
    // 0x80064E70: nop

        goto L_80064E74;
    // 0x80064E70: nop

L_80064E74:
    // 0x80064E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064E7C: jr          $ra
    // 0x80064E80: nop

    return;
    // 0x80064E80: nop

;}
RECOMP_FUNC void func_800AD1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD1E4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AD1E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AD1EC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800AD1F0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800AD1F4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800AD1F8: nop

    // 0x800AD1FC: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800AD200: bne         $at, $zero, L_800AD210
    if (ctx->r1 != 0) {
        // 0x800AD204: nop
    
            goto L_800AD210;
    }
    // 0x800AD204: nop

    // 0x800AD208: b           L_800AD5DC
    // 0x800AD20C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AD5DC;
    // 0x800AD20C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AD210:
    // 0x800AD210: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800AD214: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800AD218: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AD21C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800AD220: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD224: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800AD228: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD22C: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x800AD230: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD234: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800AD238: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800AD23C: nop

    // 0x800AD240: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800AD244: nop

    // 0x800AD248: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800AD24C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AD250: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800AD254: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AD258: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD25C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD260: lwc1        $f4, 0x100($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X100);
    // 0x800AD264: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800AD268: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD26C: lw          $t7, 0x70E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E4);
    // 0x800AD270: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800AD274: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800AD278: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AD27C: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x800AD280: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800AD284: sh          $t6, 0x80($t9)
    MEM_H(0X80, ctx->r25) = ctx->r14;
    // 0x800AD288: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AD28C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800AD290: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AD294: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD298: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD29C: lwc1        $f8, 0x104($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X104);
    // 0x800AD2A0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800AD2A4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AD2A8: lw          $t5, 0x70E4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70E4);
    // 0x800AD2AC: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800AD2B0: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x800AD2B4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AD2B8: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x800AD2BC: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x800AD2C0: sh          $t4, 0x82($t3)
    MEM_H(0X82, ctx->r11) = ctx->r12;
    // 0x800AD2C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AD2C8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800AD2CC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AD2D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD2D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD2D8: lwc1        $f16, 0xF8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x800AD2DC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800AD2E0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AD2E4: lw          $t2, 0x70E4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70E4);
    // 0x800AD2E8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800AD2EC: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x800AD2F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AD2F4: addu        $t0, $t8, $t5
    ctx->r8 = ADD32(ctx->r24, ctx->r13);
    // 0x800AD2F8: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800AD2FC: sh          $t1, 0x88($t0)
    MEM_H(0X88, ctx->r8) = ctx->r9;
    // 0x800AD300: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AD304: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800AD308: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AD30C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD310: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD314: lwc1        $f4, 0xFC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x800AD318: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800AD31C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD320: lw          $t9, 0x70E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70E4);
    // 0x800AD324: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800AD328: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x800AD32C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AD330: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x800AD334: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800AD338: sh          $t6, 0x8A($t8)
    MEM_H(0X8A, ctx->r24) = ctx->r14;
    // 0x800AD33C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800AD340: lw          $t1, 0x70E4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70E4);
    // 0x800AD344: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800AD348: sll         $t0, $t1, 6
    ctx->r8 = S32(ctx->r9 << 6);
    // 0x800AD34C: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    // 0x800AD350: jal         0x800C2D6C
    // 0x800AD354: addiu       $a0, $t5, 0xA0
    ctx->r4 = ADD32(ctx->r13, 0XA0);
    MtxUtil_MtxFToMtx(rdram, ctx);
        goto after_0;
    // 0x800AD354: addiu       $a0, $t5, 0xA0
    ctx->r4 = ADD32(ctx->r13, 0XA0);
    after_0:
    // 0x800AD358: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD35C: nop

    // 0x800AD360: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x800AD364: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800AD368: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x800AD36C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800AD370: lui         $t9, 0x380
    ctx->r25 = S32(0X380 << 16);
    // 0x800AD374: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800AD378: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800AD37C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800AD380: lw          $t6, 0x70E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70E4);
    // 0x800AD384: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800AD388: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800AD38C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800AD390: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800AD394: addiu       $t5, $t1, 0x80
    ctx->r13 = ADD32(ctx->r9, 0X80);
    // 0x800AD398: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800AD39C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AD3A0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800AD3A4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AD3A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD3AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD3B0: lwc1        $f8, 0x110($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X110);
    // 0x800AD3B4: addiu       $a0, $t4, 0x120
    ctx->r4 = ADD32(ctx->r12, 0X120);
    // 0x800AD3B8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AD3BC: addiu       $a1, $t4, 0x124
    ctx->r5 = ADD32(ctx->r12, 0X124);
    // 0x800AD3C0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AD3C4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AD3C8: addiu       $a2, $t4, 0x128
    ctx->r6 = ADD32(ctx->r12, 0X128);
    // 0x800AD3CC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AD3D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AD3D4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AD3D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD3DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD3E0: lwc1        $f16, 0x114($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X114);
    // 0x800AD3E4: addiu       $a3, $t4, 0x12C
    ctx->r7 = ADD32(ctx->r12, 0X12C);
    // 0x800AD3E8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AD3EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AD3F0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800AD3F4: nop

    // 0x800AD3F8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AD3FC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800AD400: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AD404: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD408: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD40C: lwc1        $f4, 0x118($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X118);
    // 0x800AD410: nop

    // 0x800AD414: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD418: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AD41C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800AD420: nop

    // 0x800AD424: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AD428: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800AD42C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AD430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD438: lwc1        $f8, 0x11C($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X11C);
    // 0x800AD43C: nop

    // 0x800AD440: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AD444: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800AD448: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AD44C: jal         0x800AC254
    // 0x800AD450: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    func_800AC254(rdram, ctx);
        goto after_1;
    // 0x800AD450: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_1:
    // 0x800AD454: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD458: nop

    // 0x800AD45C: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AD460: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800AD464: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800AD468: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800AD46C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AD470: lw          $t7, 0x120($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X120);
    // 0x800AD474: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD478: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AD47C: lw          $t5, 0x124($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X124);
    // 0x800AD480: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AD484: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800AD488: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AD48C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AD490: nop

    // 0x800AD494: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AD498: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD49C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD4A0: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800AD4A4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AD4A8: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x800AD4AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AD4B0: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x800AD4B4: sll         $t4, $t8, 12
    ctx->r12 = S32(ctx->r24 << 12);
    // 0x800AD4B8: or          $t1, $t4, $at
    ctx->r9 = ctx->r12 | ctx->r1;
    // 0x800AD4BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AD4C0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AD4C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AD4C8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800AD4CC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AD4D0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AD4D4: nop

    // 0x800AD4D8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800AD4DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD4E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD4E4: nop

    // 0x800AD4E8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD4EC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800AD4F0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AD4F4: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x800AD4F8: or          $t6, $t1, $t7
    ctx->r14 = ctx->r9 | ctx->r15;
    // 0x800AD4FC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800AD500: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800AD504: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AD508: lw          $t4, 0x128($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X128);
    // 0x800AD50C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AD510: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800AD514: lw          $t1, 0x12C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X12C);
    // 0x800AD518: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AD51C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800AD520: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AD524: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AD528: nop

    // 0x800AD52C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AD530: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD534: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD538: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AD53C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AD540: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AD544: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AD548: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800AD54C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AD550: andi        $t0, $t5, 0xFFF
    ctx->r8 = ctx->r13 & 0XFFF;
    // 0x800AD554: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800AD558: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AD55C: sll         $t3, $t0, 12
    ctx->r11 = S32(ctx->r8 << 12);
    // 0x800AD560: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AD564: nop

    // 0x800AD568: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AD56C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD570: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD574: nop

    // 0x800AD578: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AD57C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800AD580: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AD584: andi        $t2, $t6, 0xFFF
    ctx->r10 = ctx->r14 & 0XFFF;
    // 0x800AD588: or          $t4, $t3, $t2
    ctx->r12 = ctx->r11 | ctx->r10;
    // 0x800AD58C: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x800AD590: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD594: nop

    // 0x800AD598: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800AD59C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800AD5A0: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800AD5A4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800AD5A8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AD5AC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800AD5B0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800AD5B4: nop

    // 0x800AD5B8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800AD5BC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD5C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800AD5C4: nop

    // 0x800AD5C8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800AD5CC: b           L_800AD5DC
    // 0x800AD5D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD5DC;
    // 0x800AD5D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD5D4: b           L_800AD5DC
    // 0x800AD5D8: nop

        goto L_800AD5DC;
    // 0x800AD5D8: nop

L_800AD5DC:
    // 0x800AD5DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AD5E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800AD5E4: jr          $ra
    // 0x800AD5E8: nop

    return;
    // 0x800AD5E8: nop

;}
RECOMP_FUNC void alSndpGetState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C97D0: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800C97D4: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x800C97D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C97DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C97E0: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C97E4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C97E8: jr          $ra
    // 0x800C97EC: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
    return;
    // 0x800C97EC: lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X28);
;}
RECOMP_FUNC void func_8006CDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CDC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CDC8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CDCC: nop

    // 0x8006CDD0: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x8006CDD4: nop

    // 0x8006CDD8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006CDDC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CDE0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CDE4: bne         $v0, $zero, L_8006CE00
    if (ctx->r2 != 0) {
        // 0x8006CDE8: nop
    
            goto L_8006CE00;
    }
    // 0x8006CDE8: nop

    // 0x8006CDEC: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006CDF0: nop

    // 0x8006CDF4: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006CDF8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006CDFC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006CE00:
    // 0x8006CE00: jr          $ra
    // 0x8006CE04: nop

    return;
    // 0x8006CE04: nop

    // 0x8006CE08: jr          $ra
    // 0x8006CE0C: nop

    return;
    // 0x8006CE0C: nop

    // 0x8006CE10: jr          $ra
    // 0x8006CE14: nop

    return;
    // 0x8006CE14: nop

;}
RECOMP_FUNC void func_80076EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076EB8: jal         0x80061488
    // 0x80076EBC: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076EBC: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076EC0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076EC4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076EC8: b           L_80076ED8
    // 0x80076ECC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076ED8;
    // 0x80076ECC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076ED0: b           L_80076ED8
    // 0x80076ED4: nop

        goto L_80076ED8;
    // 0x80076ED4: nop

L_80076ED8:
    // 0x80076ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076EDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076EE0: jr          $ra
    // 0x80076EE4: nop

    return;
    // 0x80076EE4: nop

;}
RECOMP_FUNC void func_8006C540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C548: jal         0x8005F064
    // 0x8006C54C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C54C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_0:
    // 0x8006C550: b           L_8006C560
    // 0x8006C554: nop

        goto L_8006C560;
    // 0x8006C554: nop

    // 0x8006C558: b           L_8006C560
    // 0x8006C55C: nop

        goto L_8006C560;
    // 0x8006C55C: nop

L_8006C560:
    // 0x8006C560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C568: jr          $ra
    // 0x8006C56C: nop

    return;
    // 0x8006C56C: nop

;}
RECOMP_FUNC void func_80087B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80087B8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087B90: jal         0x8008B4EC
    // 0x80087B94: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80087B94: nop

    after_0:
    // 0x80087B98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087B9C: jal         0x8008BC70
    // 0x80087BA0: nop

    func_8008BC70(rdram, ctx);
        goto after_1;
    // 0x80087BA0: nop

    after_1:
    // 0x80087BA4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80087BA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80087BAC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80087BB0: jal         0x8008B738
    // 0x80087BB4: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80087BB4: addiu       $a1, $t6, 0x10
    ctx->r5 = ADD32(ctx->r14, 0X10);
    after_2:
    // 0x80087BB8: addiu       $t7, $zero, 0xE1
    ctx->r15 = ADD32(0, 0XE1);
    // 0x80087BBC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80087BC0: sw          $t7, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r15;
    // 0x80087BC4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80087BC8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80087BCC: sw          $t8, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r24;
    // 0x80087BD0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80087BD4: nop

    // 0x80087BD8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80087BDC: nop

    // 0x80087BE0: andi        $t1, $t0, 0x400
    ctx->r9 = ctx->r8 & 0X400;
    // 0x80087BE4: beq         $t1, $zero, L_80087C04
    if (ctx->r9 == 0) {
        // 0x80087BE8: nop
    
            goto L_80087C04;
    }
    // 0x80087BE8: nop

    // 0x80087BEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087BF0: addiu       $a1, $zero, 0x4003
    ctx->r5 = ADD32(0, 0X4003);
    // 0x80087BF4: jal         0x8008B2FC
    // 0x80087BF8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_3;
    // 0x80087BF8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_3:
    // 0x80087BFC: b           L_80087C14
    // 0x80087C00: nop

        goto L_80087C14;
    // 0x80087C00: nop

L_80087C04:
    // 0x80087C04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80087C08: addiu       $a1, $zero, 0x4004
    ctx->r5 = ADD32(0, 0X4004);
    // 0x80087C0C: jal         0x8008B2FC
    // 0x80087C10: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8008B2FC(rdram, ctx);
        goto after_4;
    // 0x80087C10: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_4:
L_80087C14:
    // 0x80087C14: b           L_80087C1C
    // 0x80087C18: nop

        goto L_80087C1C;
    // 0x80087C18: nop

L_80087C1C:
    // 0x80087C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087C24: jr          $ra
    // 0x80087C28: nop

    return;
    // 0x80087C28: nop

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
RECOMP_FUNC void alCSeqNewMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA850: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x800CA854: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CA858: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CA85C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800CA860: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x800CA864: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800CA868: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800CA86C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800CA870: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CA874: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CA878: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CA87C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800CA880: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800CA884: jal         0x800CA73C
    // 0x800CA888: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    alCSeqNew(rdram, ctx);
        goto after_0;
    // 0x800CA888: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800CA88C: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800CA890: addiu       $s4, $sp, 0x140
    ctx->r20 = ADD32(ctx->r29, 0X140);
    // 0x800CA894: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800CA898: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_800CA89C:
    // 0x800CA89C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800CA8A0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CA8A4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800CA8A8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800CA8AC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800CA8B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CA8B4: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x800CA8B8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8BC: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_800CA8C0:
    // 0x800CA8C0: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x800CA8C4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CA8C8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CA8CC: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
    // 0x800CA8D0: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x800CA8D4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800CA8D8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CA8DC: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800CA8E0: lbu         $t2, 0x94($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X94);
    // 0x800CA8E4: sb          $t2, 0x88($a1)
    MEM_B(0X88, ctx->r5) = ctx->r10;
    // 0x800CA8E8: lbu         $t3, 0xA4($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA4);
    // 0x800CA8EC: sb          $t3, 0x98($a1)
    MEM_B(0X98, ctx->r5) = ctx->r11;
    // 0x800CA8F0: lw          $t4, 0xA8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA8);
    // 0x800CA8F4: sw          $t4, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r12;
    // 0x800CA8F8: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800CA8FC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800CA900: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x800CA904: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x800CA908: lbu         $t7, 0x95($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X95);
    // 0x800CA90C: sb          $t7, 0x89($a1)
    MEM_B(0X89, ctx->r5) = ctx->r15;
    // 0x800CA910: lbu         $t8, 0xA5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA5);
    // 0x800CA914: sb          $t8, 0x99($a1)
    MEM_B(0X99, ctx->r5) = ctx->r24;
    // 0x800CA918: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x800CA91C: sw          $t9, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r25;
    // 0x800CA920: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x800CA924: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CA928: lw          $t1, 0x50($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X50);
    // 0x800CA92C: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x800CA930: lbu         $t2, 0x96($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X96);
    // 0x800CA934: sb          $t2, 0x8A($a1)
    MEM_B(0X8A, ctx->r5) = ctx->r10;
    // 0x800CA938: lbu         $t3, 0xA6($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA6);
    // 0x800CA93C: sb          $t3, 0x9A($a1)
    MEM_B(0X9A, ctx->r5) = ctx->r11;
    // 0x800CA940: lw          $t4, 0xB0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XB0);
    // 0x800CA944: sw          $t4, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r12;
    // 0x800CA948: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x800CA94C: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800CA950: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x800CA954: sw          $t6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r14;
    // 0x800CA958: lbu         $t7, 0x97($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X97);
    // 0x800CA95C: sb          $t7, 0x8B($a1)
    MEM_B(0X8B, ctx->r5) = ctx->r15;
    // 0x800CA960: lbu         $t8, 0xA7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA7);
    // 0x800CA964: sb          $t8, 0x9B($a1)
    MEM_B(0X9B, ctx->r5) = ctx->r24;
    // 0x800CA968: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x800CA96C: bne         $a0, $s0, L_800CA8C0
    if (ctx->r4 != ctx->r16) {
        // 0x800CA970: sw          $t9, 0xA8($v0)
        MEM_W(0XA8, ctx->r2) = ctx->r25;
            goto L_800CA8C0;
    }
    // 0x800CA970: sw          $t9, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r25;
    // 0x800CA974: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800CA978: jal         0x800CA444
    // 0x800CA97C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alCSeqNextEvent(rdram, ctx);
        goto after_1;
    // 0x800CA97C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x800CA980: lh          $t0, 0x140($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X140);
    // 0x800CA984: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800CA988: beq         $t0, $s5, L_800CA998
    if (ctx->r8 == ctx->r21) {
        // 0x800CA98C: sltu        $at, $t1, $s2
        ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
            goto L_800CA998;
    }
    // 0x800CA98C: sltu        $at, $t1, $s2
    ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x800CA990: bnel        $at, $zero, L_800CA89C
    if (ctx->r1 != 0) {
        // 0x800CA994: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_800CA89C;
    }
    goto skip_0;
    // 0x800CA994: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_800CA998:
    // 0x800CA998: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA99C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CA9A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CA9A4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA9A8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CA9AC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800CA9B0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800CA9B4: jr          $ra
    // 0x800CA9B8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x800CA9B8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void func_80070D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070D10: jal         0x80061348
    // 0x80070D14: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070D14: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_0:
    // 0x80070D18: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070D1C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070D20: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070D24: beq         $v0, $zero, L_80070D78
    if (ctx->r2 == 0) {
        // 0x80070D28: nop
    
            goto L_80070D78;
    }
    // 0x80070D28: nop

    // 0x80070D2C: jal         0x80061348
    // 0x80070D30: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070D30: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070D34: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070D38: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070D3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070D40: beq         $v0, $zero, L_80070D78
    if (ctx->r2 == 0) {
        // 0x80070D44: nop
    
            goto L_80070D78;
    }
    // 0x80070D44: nop

    // 0x80070D48: jal         0x80061348
    // 0x80070D4C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070D4C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070D50: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070D54: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070D58: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070D5C: beq         $v0, $zero, L_80070D78
    if (ctx->r2 == 0) {
        // 0x80070D60: nop
    
            goto L_80070D78;
    }
    // 0x80070D60: nop

    // 0x80070D64: jal         0x80061348
    // 0x80070D68: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070D68: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070D6C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070D70: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070D74: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070D78:
    // 0x80070D78: b           L_80070D88
    // 0x80070D7C: nop

        goto L_80070D88;
    // 0x80070D7C: nop

    // 0x80070D80: b           L_80070D88
    // 0x80070D84: nop

        goto L_80070D88;
    // 0x80070D84: nop

L_80070D88:
    // 0x80070D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070D90: jr          $ra
    // 0x80070D94: nop

    return;
    // 0x80070D94: nop

;}
RECOMP_FUNC void AudioDriver_UpdateSounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9F10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B9F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9F18: jal         0x800B9A18
    // 0x800B9F1C: nop

    AudioDriver_ProcessSoundDeallocRequests(rdram, ctx);
        goto after_0;
    // 0x800B9F1C: nop

    after_0:
    // 0x800B9F20: jal         0x800B9DD4
    // 0x800B9F24: nop

    func_800B9DD4(rdram, ctx);
        goto after_1;
    // 0x800B9F24: nop

    after_1:
    // 0x800B9F28: jal         0x800B9E88
    // 0x800B9F2C: nop

    func_800B9E88(rdram, ctx);
        goto after_2;
    // 0x800B9F2C: nop

    after_2:
    // 0x800B9F30: b           L_800B9F38
    // 0x800B9F34: nop

        goto L_800B9F38;
    // 0x800B9F34: nop

L_800B9F38:
    // 0x800B9F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B9F3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B9F40: jr          $ra
    // 0x800B9F44: nop

    return;
    // 0x800B9F44: nop

;}
RECOMP_FUNC void func_80080698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080698: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008069C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800806A0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800806A4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800806A8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800806AC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800806B0: beq         $t7, $at, L_8008071C
    if (ctx->r15 == ctx->r1) {
        // 0x800806B4: nop
    
            goto L_8008071C;
    }
    // 0x800806B4: nop

    // 0x800806B8: beq         $t7, $zero, L_8008071C
    if (ctx->r15 == 0) {
        // 0x800806BC: nop
    
            goto L_8008071C;
    }
    // 0x800806BC: nop

L_800806C0:
    // 0x800806C0: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800806C4: nop

    // 0x800806C8: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800806CC: nop

    // 0x800806D0: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800806D4: bne         $at, $zero, L_800806EC
    if (ctx->r1 != 0) {
        // 0x800806D8: nop
    
            goto L_800806EC;
    }
    // 0x800806D8: nop

    // 0x800806DC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800806E0: nop

    // 0x800806E4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800806E8: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
L_800806EC:
    // 0x800806EC: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800806F0: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800806F4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800806F8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800806FC: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80080700: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x80080704: lbu         $t6, 0x0($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X0);
    // 0x80080708: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008070C: beq         $t6, $at, L_8008071C
    if (ctx->r14 == ctx->r1) {
        // 0x80080710: nop
    
            goto L_8008071C;
    }
    // 0x80080710: nop

    // 0x80080714: bne         $t6, $zero, L_800806C0
    if (ctx->r14 != 0) {
        // 0x80080718: nop
    
            goto L_800806C0;
    }
    // 0x80080718: nop

L_8008071C:
    // 0x8008071C: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x80080720: b           L_80080730
    // 0x80080724: nop

        goto L_80080730;
    // 0x80080724: nop

    // 0x80080728: b           L_80080730
    // 0x8008072C: nop

        goto L_80080730;
    // 0x8008072C: nop

L_80080730:
    // 0x80080730: jr          $ra
    // 0x80080734: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80080734: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80035D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035D78: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80035D7C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80035D80: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80035D84: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80035D88: addiu       $t7, $t7, -0x3F60
    ctx->r15 = ADD32(ctx->r15, -0X3F60);
    // 0x80035D8C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80035D90: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x80035D94: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80035D98: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80035D9C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80035DA0: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80035DA4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80035DA8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80035DAC: lw          $t0, 0x7298($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7298);
    // 0x80035DB0: nop

    // 0x80035DB4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80035DB8: sh          $zero, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = 0;
    // 0x80035DBC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80035DC0: nop

    // 0x80035DC4: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80035DC8: nop

    // 0x80035DCC: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80035DD0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80035DD4: nop

    // 0x80035DD8: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80035DDC: nop

    // 0x80035DE0: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x80035DE4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80035DE8: nop

    // 0x80035DEC: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80035DF0: nop

    // 0x80035DF4: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x80035DF8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80035DFC: nop

    // 0x80035E00: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80035E04: nop

    // 0x80035E08: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
    // 0x80035E0C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80035E10: nop

    // 0x80035E14: lwc1        $f16, 0x10($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X10);
    // 0x80035E18: nop

    // 0x80035E1C: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x80035E20: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80035E24: nop

    // 0x80035E28: lwc1        $f18, 0x14($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X14);
    // 0x80035E2C: nop

    // 0x80035E30: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
    // 0x80035E34: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80035E38: nop

    // 0x80035E3C: lwc1        $f4, 0x18($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80035E40: nop

    // 0x80035E44: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x80035E48: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80035E4C: nop

    // 0x80035E50: lwc1        $f6, 0x20($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80035E54: nop

    // 0x80035E58: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x80035E5C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80035E60: nop

    // 0x80035E64: lwc1        $f8, 0x1C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80035E68: nop

    // 0x80035E6C: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x80035E70: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80035E74: nop

    // 0x80035E78: lbu         $t1, 0x2C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2C);
    // 0x80035E7C: nop

    // 0x80035E80: sh          $t1, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r9;
    // 0x80035E84: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80035E88: nop

    // 0x80035E8C: lwc1        $f10, 0x28($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X28);
    // 0x80035E90: nop

    // 0x80035E94: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x80035E98: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80035E9C: nop

    // 0x80035EA0: lwc1        $f16, 0x24($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X24);
    // 0x80035EA4: nop

    // 0x80035EA8: swc1        $f16, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f16.u32l;
    // 0x80035EAC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80035EB0: nop

    // 0x80035EB4: lbu         $t5, 0x2E($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2E);
    // 0x80035EB8: nop

    // 0x80035EBC: sh          $t5, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r13;
    // 0x80035EC0: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80035EC4: nop

    // 0x80035EC8: lbu         $t6, 0x2F($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X2F);
    // 0x80035ECC: nop

    // 0x80035ED0: sh          $t6, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r14;
    // 0x80035ED4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80035ED8: lw          $t7, 0x7278($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7278);
    // 0x80035EDC: nop

    // 0x80035EE0: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80035EE4: nop

    // 0x80035EE8: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x80035EEC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80035EF0: lw          $t9, 0x7278($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7278);
    // 0x80035EF4: nop

    // 0x80035EF8: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80035EFC: nop

    // 0x80035F00: swc1        $f4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f4.u32l;
    // 0x80035F04: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80035F08: lw          $t0, 0x7278($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7278);
    // 0x80035F0C: nop

    // 0x80035F10: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80035F14: nop

    // 0x80035F18: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    // 0x80035F1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80035F20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80035F24: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80035F28: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80035F2C: lwc1        $f16, 0xC0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80035F30: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80035F34: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80035F38: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80035F3C: lui         $a3, 0x44BB
    ctx->r7 = S32(0X44BB << 16);
    // 0x80035F40: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80035F44: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80035F48: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80035F4C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80035F50: jal         0x800C3C80
    // 0x80035F54: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_0;
    // 0x80035F54: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80035F58: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x80035F5C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80035F60: nop

    // 0x80035F64: lbu         $t2, 0x2D($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2D);
    // 0x80035F68: nop

    // 0x80035F6C: bne         $t2, $zero, L_800361FC
    if (ctx->r10 != 0) {
        // 0x80035F70: sh          $t2, 0xA0($sp)
        MEM_H(0XA0, ctx->r29) = ctx->r10;
            goto L_800361FC;
    }
    // 0x80035F70: sh          $t2, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r10;
    // 0x80035F74: jal         0x800C4240
    // 0x80035F78: nop

    guRandom(rdram, ctx);
        goto after_1;
    // 0x80035F78: nop

    after_1:
    // 0x80035F7C: bgez        $v0, L_80035F90
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80035F80: andi        $t3, $v0, 0x1
        ctx->r11 = ctx->r2 & 0X1;
            goto L_80035F90;
    }
    // 0x80035F80: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x80035F84: beq         $t3, $zero, L_80035F90
    if (ctx->r11 == 0) {
        // 0x80035F88: nop
    
            goto L_80035F90;
    }
    // 0x80035F88: nop

    // 0x80035F8C: addiu       $t3, $t3, -0x2
    ctx->r11 = ADD32(ctx->r11, -0X2);
L_80035F90:
    // 0x80035F90: sh          $t3, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r11;
    // 0x80035F94: jal         0x800C1850
    // 0x80035F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_2;
    // 0x80035F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80035F9C: lwc1        $f12, 0xC8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80035FA0: lwc1        $f14, 0xC4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80035FA4: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80035FA8: jal         0x800C2304
    // 0x80035FAC: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_3;
    // 0x80035FAC: nop

    after_3:
    // 0x80035FB0: lhu         $t4, 0x9E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X9E);
    // 0x80035FB4: nop

    // 0x80035FB8: beq         $t4, $zero, L_8003603C
    if (ctx->r12 == 0) {
        // 0x80035FBC: nop
    
            goto L_8003603C;
    }
    // 0x80035FBC: nop

    // 0x80035FC0: jal         0x800C4240
    // 0x80035FC4: nop

    guRandom(rdram, ctx);
        goto after_4;
    // 0x80035FC4: nop

    after_4:
    // 0x80035FC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80035FCC: addiu       $at, $zero, 0xB5
    ctx->r1 = ADD32(0, 0XB5);
    // 0x80035FD0: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x80035FD4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80035FD8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80035FDC: lw          $t8, 0x7278($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7278);
    // 0x80035FE0: lwc1        $f9, -0x1630($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1630);
    // 0x80035FE4: lwc1        $f8, -0x162C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X162C);
    // 0x80035FE8: lwc1        $f16, 0x10($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80035FEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80035FF0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80035FF4: mfhi        $t5
    ctx->r13 = hi;
    // 0x80035FF8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80035FFC: nop

    // 0x80036000: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80036004: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80036008: lwc1        $f6, -0x1624($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1624);
    // 0x8003600C: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x80036010: lwc1        $f7, -0x1628($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1628);
    // 0x80036014: nop

    // 0x80036018: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8003601C: jal         0x800C25B8
    // 0x80036020: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    MtxUtil_RotateY(rdram, ctx);
        goto after_5;
    // 0x80036020: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_5:
    // 0x80036024: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80036028: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8003602C: jal         0x800C2304
    // 0x80036030: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_6;
    // 0x80036030: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    after_6:
    // 0x80036034: b           L_80036070
    // 0x80036038: nop

        goto L_80036070;
    // 0x80036038: nop

L_8003603C:
    // 0x8003603C: jal         0x800C4240
    // 0x80036040: nop

    guRandom(rdram, ctx);
        goto after_7;
    // 0x80036040: nop

    after_7:
    // 0x80036044: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80036048: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x8003604C: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x80036050: mfhi        $t6
    ctx->r14 = hi;
    // 0x80036054: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80036058: jal         0x800C25B8
    // 0x8003605C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    MtxUtil_RotateY(rdram, ctx);
        goto after_8;
    // 0x8003605C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_8:
    // 0x80036060: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80036064: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80036068: jal         0x800C2304
    // 0x8003606C: lui         $a2, 0x44AF
    ctx->r6 = S32(0X44AF << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_9;
    // 0x8003606C: lui         $a2, 0x44AF
    ctx->r6 = S32(0X44AF << 16);
    after_9:
L_80036070:
    // 0x80036070: jal         0x800B1844
    // 0x80036074: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800B1844(rdram, ctx);
        goto after_10;
    // 0x80036074: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_10:
    // 0x80036078: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x8003607C: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80036080: nop

    // 0x80036084: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80036088: jal         0x800C4240
    // 0x8003608C: nop

    guRandom(rdram, ctx);
        goto after_11;
    // 0x8003608C: nop

    after_11:
    // 0x80036090: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x80036094: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80036098: mfhi        $t9
    ctx->r25 = hi;
    // 0x8003609C: addiu       $t0, $t9, -0x50
    ctx->r8 = ADD32(ctx->r25, -0X50);
    // 0x800360A0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800360A4: nop

    // 0x800360A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800360AC: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x800360B0: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800360B4: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800360B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800360BC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800360C0: lwc1        $f19, -0x1620($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1620);
    // 0x800360C4: lwc1        $f18, -0x161C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X161C);
    // 0x800360C8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800360CC: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x800360D0: swc1        $f16, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f16.u32l;
    // 0x800360D4: bc1t        L_800360FC
    if (c1cs) {
        // 0x800360D8: nop
    
            goto L_800360FC;
    }
    // 0x800360D8: nop

    // 0x800360DC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800360E0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800360E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800360E8: nop

    // 0x800360EC: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x800360F0: nop

    // 0x800360F4: bc1f        L_80036114
    if (!c1cs) {
        // 0x800360F8: nop
    
            goto L_80036114;
    }
    // 0x800360F8: nop

L_800360FC:
    // 0x800360FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80036100: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036104: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80036108: nop

    // 0x8003610C: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80036110: swc1        $f16, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f16.u32l;
L_80036114:
    // 0x80036114: lwc1        $f18, 0xF0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036118: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8003611C: nop

    // 0x80036120: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80036124: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x80036128: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x8003612C: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80036130: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036134: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80036138: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8003613C: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    // 0x80036140: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80036144: jal         0x80034CA0
    // 0x80036148: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    func_80034CA0(rdram, ctx);
        goto after_12;
    // 0x80036148: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x8003614C: bne         $v0, $zero, L_800361F4
    if (ctx->r2 != 0) {
        // 0x80036150: nop
    
            goto L_800361F4;
    }
    // 0x80036150: nop

    // 0x80036154: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80036158: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003615C: lwc1        $f16, 0xF0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036160: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80036164: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80036168: jal         0x80034CA0
    // 0x8003616C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    func_80034CA0(rdram, ctx);
        goto after_13;
    // 0x8003616C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_13:
    // 0x80036170: bne         $v0, $zero, L_800361F4
    if (ctx->r2 != 0) {
        // 0x80036174: nop
    
            goto L_800361F4;
    }
    // 0x80036174: nop

    // 0x80036178: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8003617C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036180: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036184: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80036188: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x8003618C: jal         0x80034CA0
    // 0x80036190: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    func_80034CA0(rdram, ctx);
        goto after_14;
    // 0x80036190: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    after_14:
    // 0x80036194: bne         $v0, $zero, L_800361F4
    if (ctx->r2 != 0) {
        // 0x80036198: nop
    
            goto L_800361F4;
    }
    // 0x80036198: nop

    // 0x8003619C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800361A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800361A4: nop

    // 0x800361A8: swc1        $f6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f6.u32l;
    // 0x800361AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800361B0: nop

    // 0x800361B4: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
    // 0x800361B8: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x800361BC: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x800361C0: sh          $zero, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = 0;
    // 0x800361C4: sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
    // 0x800361C8: jal         0x800C4240
    // 0x800361CC: nop

    guRandom(rdram, ctx);
        goto after_15;
    // 0x800361CC: nop

    after_15:
    // 0x800361D0: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800361D4: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800361D8: mfhi        $t2
    ctx->r10 = hi;
    // 0x800361DC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800361E0: nop

    // 0x800361E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800361E8: swc1        $f18, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f18.u32l;
    // 0x800361EC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800361F0: sh          $t3, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r11;
L_800361F4:
    // 0x800361F4: b           L_800371DC
    // 0x800361F8: nop

        goto L_800371DC;
    // 0x800361F8: nop

L_800361FC:
    // 0x800361FC: jal         0x800C1850
    // 0x80036200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_16;
    // 0x80036200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x80036204: lwc1        $f12, 0xE4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80036208: jal         0x800C25B8
    // 0x8003620C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_17;
    // 0x8003620C: nop

    after_17:
    // 0x80036210: lwc1        $f12, 0xE8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80036214: jal         0x800C23E8
    // 0x80036218: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_18;
    // 0x80036218: nop

    after_18:
    // 0x8003621C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80036220: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80036224: jal         0x800C2304
    // 0x80036228: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_19;
    // 0x80036228: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_19:
    // 0x8003622C: jal         0x800B1844
    // 0x80036230: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800B1844(rdram, ctx);
        goto after_20;
    // 0x80036230: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_20:
    // 0x80036234: addiu       $t4, $sp, 0x4C
    ctx->r12 = ADD32(ctx->r29, 0X4C);
    // 0x80036238: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003623C: nop

    // 0x80036240: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x80036244: addiu       $t5, $sp, 0x4C
    ctx->r13 = ADD32(ctx->r29, 0X4C);
    // 0x80036248: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8003624C: nop

    // 0x80036250: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x80036254: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x80036258: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8003625C: nop

    // 0x80036260: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x80036264: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80036268: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003626C: lwc1        $f8, 0xD0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80036270: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036274: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80036278: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8003627C: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80036280: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80036284: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036288: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8003628C: nop

    // 0x80036290: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80036294: nop

    // 0x80036298: bc1f        L_800362BC
    if (!c1cs) {
        // 0x8003629C: nop
    
            goto L_800362BC;
    }
    // 0x8003629C: nop

    // 0x800362A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800362A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800362A8: nop

    // 0x800362AC: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
    // 0x800362B0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800362B4: b           L_800362FC
    // 0x800362B8: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
        goto L_800362FC;
    // 0x800362B8: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_800362BC:
    // 0x800362BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800362C0: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800362C4: lwc1        $f7, -0x1618($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1618);
    // 0x800362C8: lwc1        $f6, -0x1614($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1614);
    // 0x800362CC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800362D0: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800362D4: nop

    // 0x800362D8: bc1f        L_800362FC
    if (!c1cs) {
        // 0x800362DC: nop
    
            goto L_800362FC;
    }
    // 0x800362DC: nop

    // 0x800362E0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800362E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800362E8: nop

    // 0x800362EC: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x800362F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800362F4: nop

    // 0x800362F8: swc1        $f16, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f16.u32l;
L_800362FC:
    // 0x800362FC: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80036300: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80036304: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036308: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8003630C: c.eq.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d == ctx->f4.d;
    // 0x80036310: nop

    // 0x80036314: bc1f        L_80036384
    if (!c1cs) {
        // 0x80036318: nop
    
            goto L_80036384;
    }
    // 0x80036318: nop

    // 0x8003631C: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80036320: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80036324: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80036328: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003632C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80036330: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x80036334: nop

    // 0x80036338: bc1f        L_80036384
    if (!c1cs) {
        // 0x8003633C: nop
    
            goto L_80036384;
    }
    // 0x8003633C: nop

    // 0x80036340: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80036344: lwc1        $f19, -0x1610($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1610);
    // 0x80036348: lwc1        $f18, -0x160C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X160C);
    // 0x8003634C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80036350: sub.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f8.d - ctx->f18.d;
    // 0x80036354: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80036358: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8003635C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036360: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80036364: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x80036368: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
    // 0x8003636C: bc1f        L_80036384
    if (!c1cs) {
        // 0x80036370: nop
    
            goto L_80036384;
    }
    // 0x80036370: nop

    // 0x80036374: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80036378: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003637C: nop

    // 0x80036380: swc1        $f8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f8.u32l;
L_80036384:
    // 0x80036384: lhu         $t6, 0x9E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X9E);
    // 0x80036388: nop

    // 0x8003638C: beq         $t6, $zero, L_80036614
    if (ctx->r14 == 0) {
        // 0x80036390: nop
    
            goto L_80036614;
    }
    // 0x80036390: nop

    // 0x80036394: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80036398: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003639C: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800363A0: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800363A4: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800363A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800363AC: lwc1        $f16, 0xD0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800363B0: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800363B4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800363B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800363BC: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800363C0: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800363C4: lwc1        $f8, 0xEC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800363C8: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800363CC: add.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800363D0: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800363D4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800363D8: jal         0x80034CA0
    // 0x800363DC: nop

    func_80034CA0(rdram, ctx);
        goto after_21;
    // 0x800363DC: nop

    after_21:
    // 0x800363E0: sh          $v0, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r2;
    // 0x800363E4: lh          $t7, 0xA4($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XA4);
    // 0x800363E8: nop

    // 0x800363EC: beq         $t7, $zero, L_8003648C
    if (ctx->r15 == 0) {
        // 0x800363F0: nop
    
            goto L_8003648C;
    }
    // 0x800363F0: nop

    // 0x800363F4: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800363F8: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800363FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036400: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80036404: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80036408: nop

    // 0x8003640C: bc1f        L_8003648C
    if (!c1cs) {
        // 0x80036410: nop
    
            goto L_8003648C;
    }
    // 0x80036410: nop

    // 0x80036414: lwc1        $f16, 0xD0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80036418: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003641C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80036420: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80036424: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80036428: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8003642C: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036430: nop

    // 0x80036434: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80036438: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x8003643C: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x80036440: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x80036444: jal         0x800C4240
    // 0x80036448: nop

    guRandom(rdram, ctx);
        goto after_22;
    // 0x80036448: nop

    after_22:
    // 0x8003644C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80036450: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80036454: mfhi        $t9
    ctx->r25 = hi;
    // 0x80036458: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x8003645C: bne         $at, $zero, L_80036474
    if (ctx->r1 != 0) {
        // 0x80036460: nop
    
            goto L_80036474;
    }
    // 0x80036460: nop

    // 0x80036464: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x80036468: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003646C: b           L_80036484
    // 0x80036470: swc1        $f18, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f18.u32l;
        goto L_80036484;
    // 0x80036470: swc1        $f18, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f18.u32l;
L_80036474:
    // 0x80036474: lui         $at, 0xC2B8
    ctx->r1 = S32(0XC2B8 << 16);
    // 0x80036478: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003647C: nop

    // 0x80036480: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
L_80036484:
    // 0x80036484: b           L_8003660C
    // 0x80036488: nop

        goto L_8003660C;
    // 0x80036488: nop

L_8003648C:
    // 0x8003648C: lh          $t0, 0xA4($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA4);
    // 0x80036490: nop

    // 0x80036494: bne         $t0, $zero, L_8003660C
    if (ctx->r8 != 0) {
        // 0x80036498: nop
    
            goto L_8003660C;
    }
    // 0x80036498: nop

    // 0x8003649C: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800364A0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800364A4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800364A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800364AC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800364B0: c.eq.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d == ctx->f16.d;
    // 0x800364B4: nop

    // 0x800364B8: bc1f        L_80036510
    if (!c1cs) {
        // 0x800364BC: nop
    
            goto L_80036510;
    }
    // 0x800364BC: nop

    // 0x800364C0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800364C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800364C8: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800364CC: nop

    // 0x800364D0: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x800364D4: nop

    // 0x800364D8: bc1f        L_80036510
    if (!c1cs) {
        // 0x800364DC: nop
    
            goto L_80036510;
    }
    // 0x800364DC: nop

    // 0x800364E0: jal         0x800C4240
    // 0x800364E4: nop

    guRandom(rdram, ctx);
        goto after_23;
    // 0x800364E4: nop

    after_23:
    // 0x800364E8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800364EC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800364F0: mfhi        $t1
    ctx->r9 = hi;
    // 0x800364F4: slti        $at, $t1, 0x5F
    ctx->r1 = SIGNED(ctx->r9) < 0X5F ? 1 : 0;
    // 0x800364F8: bne         $at, $zero, L_80036510
    if (ctx->r1 != 0) {
        // 0x800364FC: nop
    
            goto L_80036510;
    }
    // 0x800364FC: nop

    // 0x80036500: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80036504: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036508: nop

    // 0x8003650C: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
L_80036510:
    // 0x80036510: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80036514: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80036518: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003651C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036520: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80036524: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80036528: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x8003652C: bc1f        L_80036568
    if (!c1cs) {
        // 0x80036530: nop
    
            goto L_80036568;
    }
    // 0x80036530: nop

    // 0x80036534: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80036538: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8003653C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80036540: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036544: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80036548: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8003654C: nop

    // 0x80036550: bc1f        L_80036568
    if (!c1cs) {
        // 0x80036554: nop
    
            goto L_80036568;
    }
    // 0x80036554: nop

    // 0x80036558: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003655C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80036560: nop

    // 0x80036564: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
L_80036568:
    // 0x80036568: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8003656C: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80036570: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80036574: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80036578: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8003657C: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80036580: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80036584: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80036588: lwc1        $f18, 0xF0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8003658C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80036590: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80036594: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x80036598: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8003659C: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800365A0: lwc1        $f18, 0xEC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800365A4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800365A8: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800365AC: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x800365B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800365B4: nop

    // 0x800365B8: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
    // 0x800365BC: jal         0x800C4240
    // 0x800365C0: nop

    guRandom(rdram, ctx);
        goto after_24;
    // 0x800365C0: nop

    after_24:
    // 0x800365C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800365C8: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x800365CC: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x800365D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800365D4: lwc1        $f19, -0x1608($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1608);
    // 0x800365D8: lwc1        $f18, -0x1604($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1604);
    // 0x800365DC: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800365E0: nop

    // 0x800365E4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x800365E8: mfhi        $t2
    ctx->r10 = hi;
    // 0x800365EC: addiu       $t3, $t2, -0xA
    ctx->r11 = ADD32(ctx->r10, -0XA);
    // 0x800365F0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800365F4: nop

    // 0x800365F8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800365FC: mul.d       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x80036600: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x80036604: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80036608: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
L_8003660C:
    // 0x8003660C: b           L_80036B98
    // 0x80036610: nop

        goto L_80036B98;
    // 0x80036610: nop

L_80036614:
    // 0x80036614: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80036618: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003661C: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80036620: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80036624: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80036628: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003662C: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80036630: lwc1        $f16, 0xF0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036634: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80036638: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003663C: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80036640: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80036644: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80036648: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003664C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80036650: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80036654: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80036658: jal         0x80034CA0
    // 0x8003665C: nop

    func_80034CA0(rdram, ctx);
        goto after_25;
    // 0x8003665C: nop

    after_25:
    // 0x80036660: sh          $v0, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r2;
    // 0x80036664: lh          $t4, 0xA4($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XA4);
    // 0x80036668: nop

    // 0x8003666C: beq         $t4, $zero, L_8003672C
    if (ctx->r12 == 0) {
        // 0x80036670: nop
    
            goto L_8003672C;
    }
    // 0x80036670: nop

    // 0x80036674: lwc1        $f16, 0xDC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80036678: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8003667C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80036680: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80036684: c.eq.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d == ctx->f10.d;
    // 0x80036688: nop

    // 0x8003668C: bc1f        L_8003672C
    if (!c1cs) {
        // 0x80036690: nop
    
            goto L_8003672C;
    }
    // 0x80036690: nop

    // 0x80036694: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036698: nop

    // 0x8003669C: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x800366A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800366A4: nop

    // 0x800366A8: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
    // 0x800366AC: lwc1        $f18, 0xD0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800366B0: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800366B4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800366B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800366BC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800366C0: mul.d       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x800366C4: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800366C8: nop

    // 0x800366CC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800366D0: sub.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d - ctx->f10.d;
    // 0x800366D4: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x800366D8: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
    // 0x800366DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800366E0: sh          $t5, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r13;
    // 0x800366E4: jal         0x800C4240
    // 0x800366E8: nop

    guRandom(rdram, ctx);
        goto after_26;
    // 0x800366E8: nop

    after_26:
    // 0x800366EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800366F0: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800366F4: mfhi        $t8
    ctx->r24 = hi;
    // 0x800366F8: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x800366FC: bne         $at, $zero, L_80036714
    if (ctx->r1 != 0) {
        // 0x80036700: nop
    
            goto L_80036714;
    }
    // 0x80036700: nop

    // 0x80036704: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x80036708: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003670C: b           L_80036724
    // 0x80036710: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
        goto L_80036724;
    // 0x80036710: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
L_80036714:
    // 0x80036714: lui         $at, 0xC2B8
    ctx->r1 = S32(0XC2B8 << 16);
    // 0x80036718: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003671C: nop

    // 0x80036720: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
L_80036724:
    // 0x80036724: b           L_80036B98
    // 0x80036728: nop

        goto L_80036B98;
    // 0x80036728: nop

L_8003672C:
    // 0x8003672C: lhu         $s0, 0xA0($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0XA0);
    // 0x80036730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80036734: beq         $s0, $at, L_80036750
    if (ctx->r16 == ctx->r1) {
        // 0x80036738: nop
    
            goto L_80036750;
    }
    // 0x80036738: nop

    // 0x8003673C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80036740: beq         $s0, $at, L_80036848
    if (ctx->r16 == ctx->r1) {
        // 0x80036744: nop
    
            goto L_80036848;
    }
    // 0x80036744: nop

    // 0x80036748: b           L_80036B98
    // 0x8003674C: nop

        goto L_80036B98;
    // 0x8003674C: nop

L_80036750:
    // 0x80036750: lh          $t6, 0xA4($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XA4);
    // 0x80036754: nop

    // 0x80036758: bne         $t6, $zero, L_80036840
    if (ctx->r14 != 0) {
        // 0x8003675C: nop
    
            goto L_80036840;
    }
    // 0x8003675C: nop

    // 0x80036760: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80036764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80036768: nop

    // 0x8003676C: swc1        $f6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f6.u32l;
    // 0x80036770: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80036774: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80036778: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003677C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036780: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80036784: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80036788: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    // 0x8003678C: bc1f        L_800367C8
    if (!c1cs) {
        // 0x80036790: nop
    
            goto L_800367C8;
    }
    // 0x80036790: nop

    // 0x80036794: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80036798: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8003679C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800367A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800367A4: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800367A8: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800367AC: nop

    // 0x800367B0: bc1f        L_800367C8
    if (!c1cs) {
        // 0x800367B4: nop
    
            goto L_800367C8;
    }
    // 0x800367B4: nop

    // 0x800367B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800367BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800367C0: nop

    // 0x800367C4: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
L_800367C8:
    // 0x800367C8: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800367CC: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800367D0: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800367D4: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800367D8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800367DC: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x800367E0: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800367E4: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800367E8: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800367EC: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800367F0: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800367F4: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x800367F8: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800367FC: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80036800: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80036804: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80036808: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8003680C: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x80036810: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80036814: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80036818: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8003681C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80036820: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036824: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80036828: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8003682C: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x80036830: bc1f        L_80036840
    if (!c1cs) {
        // 0x80036834: nop
    
            goto L_80036840;
    }
    // 0x80036834: nop

    // 0x80036838: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003683C: sh          $t7, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r15;
L_80036840:
    // 0x80036840: b           L_80036B98
    // 0x80036844: nop

        goto L_80036B98;
    // 0x80036844: nop

L_80036848:
    // 0x80036848: jal         0x800C1850
    // 0x8003684C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_27;
    // 0x8003684C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x80036850: lwc1        $f12, 0xE4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80036854: jal         0x800C25B8
    // 0x80036858: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_28;
    // 0x80036858: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_28:
    // 0x8003685C: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80036860: lwc1        $f16, 0xC8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80036864: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80036868: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8003686C: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80036870: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036874: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80036878: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8003687C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80036880: jal         0x800C2304
    // 0x80036884: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_29;
    // 0x80036884: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    after_29:
    // 0x80036888: jal         0x800B1844
    // 0x8003688C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800B1844(rdram, ctx);
        goto after_30;
    // 0x8003688C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_30:
    // 0x80036890: addiu       $t9, $sp, 0x4C
    ctx->r25 = ADD32(ctx->r29, 0X4C);
    // 0x80036894: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80036898: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003689C: nop

    // 0x800368A0: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800368A4: nop

    // 0x800368A8: bc1f        L_800368D4
    if (!c1cs) {
        // 0x800368AC: nop
    
            goto L_800368D4;
    }
    // 0x800368AC: nop

    // 0x800368B0: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800368B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800368B8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800368BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800368C0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800368C4: add.d       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f10.d + ctx->f4.d;
    // 0x800368C8: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x800368CC: b           L_80036960
    // 0x800368D0: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
        goto L_80036960;
    // 0x800368D0: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
L_800368D4:
    // 0x800368D4: addiu       $t0, $sp, 0x4C
    ctx->r8 = ADD32(ctx->r29, 0X4C);
    // 0x800368D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800368DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800368E0: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800368E4: nop

    // 0x800368E8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800368EC: nop

    // 0x800368F0: bc1f        L_8003691C
    if (!c1cs) {
        // 0x800368F4: nop
    
            goto L_8003691C;
    }
    // 0x800368F4: nop

    // 0x800368F8: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800368FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80036900: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80036904: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80036908: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8003690C: sub.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f4.d - ctx->f18.d;
    // 0x80036910: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x80036914: b           L_80036960
    // 0x80036918: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
        goto L_80036960;
    // 0x80036918: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
L_8003691C:
    // 0x8003691C: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x80036920: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80036924: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80036928: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8003692C: nop

    // 0x80036930: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80036934: nop

    // 0x80036938: bc1f        L_80036960
    if (!c1cs) {
        // 0x8003693C: nop
    
            goto L_80036960;
    }
    // 0x8003693C: nop

    // 0x80036940: lwc1        $f4, 0xE4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80036944: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80036948: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8003694C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036950: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80036954: add.d       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f18.d + ctx->f16.d;
    // 0x80036958: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8003695C: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
L_80036960:
    // 0x80036960: addiu       $t2, $sp, 0x4C
    ctx->r10 = ADD32(ctx->r29, 0X4C);
    // 0x80036964: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80036968: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003696C: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80036970: nop

    // 0x80036974: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80036978: nop

    // 0x8003697C: bc1f        L_800369D0
    if (!c1cs) {
        // 0x80036980: nop
    
            goto L_800369D0;
    }
    // 0x80036980: nop

    // 0x80036984: lwc1        $f18, 0xE8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80036988: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003698C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80036990: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80036994: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80036998: add.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f16.d + ctx->f8.d;
    // 0x8003699C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800369A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800369A4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800369A8: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800369AC: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
    // 0x800369B0: bc1f        L_800369C8
    if (!c1cs) {
        // 0x800369B4: nop
    
            goto L_800369C8;
    }
    // 0x800369B4: nop

    // 0x800369B8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800369BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800369C0: nop

    // 0x800369C4: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_800369C8:
    // 0x800369C8: b           L_80036B10
    // 0x800369CC: nop

        goto L_80036B10;
    // 0x800369CC: nop

L_800369D0:
    // 0x800369D0: addiu       $t3, $sp, 0x4C
    ctx->r11 = ADD32(ctx->r29, 0X4C);
    // 0x800369D4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800369D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800369DC: lwc1        $f16, 0x4($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800369E0: nop

    // 0x800369E4: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800369E8: nop

    // 0x800369EC: bc1f        L_80036A40
    if (!c1cs) {
        // 0x800369F0: nop
    
            goto L_80036A40;
    }
    // 0x800369F0: nop

    // 0x800369F4: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800369F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800369FC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80036A00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036A04: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80036A08: sub.d       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f10.d - ctx->f4.d;
    // 0x80036A0C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80036A10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036A14: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80036A18: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80036A1C: swc1        $f16, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f16.u32l;
    // 0x80036A20: bc1f        L_80036A38
    if (!c1cs) {
        // 0x80036A24: nop
    
            goto L_80036A38;
    }
    // 0x80036A24: nop

    // 0x80036A28: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80036A2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80036A30: nop

    // 0x80036A34: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
L_80036A38:
    // 0x80036A38: b           L_80036B10
    // 0x80036A3C: nop

        goto L_80036B10;
    // 0x80036A3C: nop

L_80036A40:
    // 0x80036A40: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80036A44: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80036A48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80036A4C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80036A50: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80036A54: nop

    // 0x80036A58: bc1f        L_80036AAC
    if (!c1cs) {
        // 0x80036A5C: nop
    
            goto L_80036AAC;
    }
    // 0x80036A5C: nop

    // 0x80036A60: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80036A64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80036A68: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80036A6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036A70: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80036A74: sub.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d - ctx->f6.d;
    // 0x80036A78: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036A7C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80036A80: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80036A84: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80036A88: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x80036A8C: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
    // 0x80036A90: bc1f        L_80036AA4
    if (!c1cs) {
        // 0x80036A94: nop
    
            goto L_80036AA4;
    }
    // 0x80036A94: nop

    // 0x80036A98: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80036A9C: nop

    // 0x80036AA0: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
L_80036AA4:
    // 0x80036AA4: b           L_80036B10
    // 0x80036AA8: nop

        goto L_80036B10;
    // 0x80036AA8: nop

L_80036AAC:
    // 0x80036AAC: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80036AB0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80036AB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036AB8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80036ABC: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x80036AC0: nop

    // 0x80036AC4: bc1f        L_80036B10
    if (!c1cs) {
        // 0x80036AC8: nop
    
            goto L_80036B10;
    }
    // 0x80036AC8: nop

    // 0x80036ACC: lwc1        $f18, 0xE8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80036AD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80036AD4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80036AD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80036ADC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80036AE0: add.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f16.d + ctx->f8.d;
    // 0x80036AE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80036AE8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80036AEC: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80036AF0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80036AF4: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80036AF8: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
    // 0x80036AFC: bc1f        L_80036B10
    if (!c1cs) {
        // 0x80036B00: nop
    
            goto L_80036B10;
    }
    // 0x80036B00: nop

    // 0x80036B04: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036B08: nop

    // 0x80036B0C: swc1        $f16, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f16.u32l;
L_80036B10:
    // 0x80036B10: jal         0x800C1850
    // 0x80036B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_31;
    // 0x80036B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x80036B18: lwc1        $f12, 0xE4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80036B1C: jal         0x800C25B8
    // 0x80036B20: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_32;
    // 0x80036B20: nop

    after_32:
    // 0x80036B24: lwc1        $f12, 0xE8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80036B28: jal         0x800C23E8
    // 0x80036B2C: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_33;
    // 0x80036B2C: nop

    after_33:
    // 0x80036B30: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80036B34: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80036B38: jal         0x800C2304
    // 0x80036B3C: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_34;
    // 0x80036B3C: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    after_34:
    // 0x80036B40: jal         0x800B1844
    // 0x80036B44: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800B1844(rdram, ctx);
        goto after_35;
    // 0x80036B44: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_35:
    // 0x80036B48: addiu       $t4, $sp, 0x4C
    ctx->r12 = ADD32(ctx->r29, 0X4C);
    // 0x80036B4C: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80036B50: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80036B54: nop

    // 0x80036B58: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80036B5C: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    // 0x80036B60: addiu       $t5, $sp, 0x4C
    ctx->r13 = ADD32(ctx->r29, 0X4C);
    // 0x80036B64: lwc1        $f18, 0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80036B68: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036B6C: nop

    // 0x80036B70: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80036B74: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
    // 0x80036B78: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x80036B7C: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80036B80: lwc1        $f8, 0xEC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80036B84: nop

    // 0x80036B88: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80036B8C: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    // 0x80036B90: b           L_80036B98
    // 0x80036B94: nop

        goto L_80036B98;
    // 0x80036B94: nop

L_80036B98:
    // 0x80036B98: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80036B9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036BA0: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80036BA4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80036BA8: sub.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80036BAC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036BB0: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80036BB4: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80036BB8: swc1        $f16, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f16.u32l;
    // 0x80036BBC: bc1f        L_80036BD0
    if (!c1cs) {
        // 0x80036BC0: nop
    
            goto L_80036BD0;
    }
    // 0x80036BC0: nop

    // 0x80036BC4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80036BC8: nop

    // 0x80036BCC: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
L_80036BD0:
    // 0x80036BD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80036BD4: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80036BD8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80036BDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036BE0: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80036BE4: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80036BE8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80036BEC: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80036BF0: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    // 0x80036BF4: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x80036BF8: nop

    // 0x80036BFC: bc1f        L_80036C30
    if (!c1cs) {
        // 0x80036C00: nop
    
            goto L_80036C30;
    }
    // 0x80036C00: nop

    // 0x80036C04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036C08: nop

    // 0x80036C0C: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x80036C10: lhu         $t6, 0xA2($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XA2);
    // 0x80036C14: nop

    // 0x80036C18: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80036C1C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80036C20: slti        $at, $t9, 0xC
    ctx->r1 = SIGNED(ctx->r25) < 0XC ? 1 : 0;
    // 0x80036C24: bne         $at, $zero, L_80036C30
    if (ctx->r1 != 0) {
        // 0x80036C28: sh          $t7, 0xA2($sp)
        MEM_H(0XA2, ctx->r29) = ctx->r15;
            goto L_80036C30;
    }
    // 0x80036C28: sh          $t7, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r15;
    // 0x80036C2C: sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
L_80036C30:
    // 0x80036C30: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80036C34: nop

    // 0x80036C38: swc1        $f18, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f18.u32l;
    // 0x80036C3C: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80036C40: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80036C44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036C48: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80036C4C: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x80036C50: nop

    // 0x80036C54: bc1t        L_80036D5C
    if (c1cs) {
        // 0x80036C58: nop
    
            goto L_80036D5C;
    }
    // 0x80036C58: nop

    // 0x80036C5C: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80036C60: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80036C64: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80036C68: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80036C6C: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80036C70: nop

    // 0x80036C74: bc1f        L_80036CF0
    if (!c1cs) {
        // 0x80036C78: nop
    
            goto L_80036CF0;
    }
    // 0x80036C78: nop

    // 0x80036C7C: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80036C80: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80036C84: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80036C88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036C8C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80036C90: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x80036C94: nop

    // 0x80036C98: bc1f        L_80036CB8
    if (!c1cs) {
        // 0x80036C9C: nop
    
            goto L_80036CB8;
    }
    // 0x80036C9C: nop

    // 0x80036CA0: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80036CA4: nop

    // 0x80036CA8: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x80036CAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036CB0: b           L_80036CE8
    // 0x80036CB4: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
        goto L_80036CE8;
    // 0x80036CB4: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
L_80036CB8:
    // 0x80036CB8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80036CBC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80036CC0: nop

    // 0x80036CC4: swc1        $f18, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f18.u32l;
    // 0x80036CC8: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80036CCC: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80036CD0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80036CD4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036CD8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80036CDC: sub.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f6.d - ctx->f16.d;
    // 0x80036CE0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80036CE4: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
L_80036CE8:
    // 0x80036CE8: b           L_80036D5C
    // 0x80036CEC: nop

        goto L_80036D5C;
    // 0x80036CEC: nop

L_80036CF0:
    // 0x80036CF0: lwc1        $f18, 0xDC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80036CF4: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x80036CF8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80036CFC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036D00: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80036D04: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80036D08: nop

    // 0x80036D0C: bc1f        L_80036D2C
    if (!c1cs) {
        // 0x80036D10: nop
    
            goto L_80036D2C;
    }
    // 0x80036D10: nop

    // 0x80036D14: lwc1        $f16, 0xDC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80036D18: nop

    // 0x80036D1C: swc1        $f16, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f16.u32l;
    // 0x80036D20: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80036D24: b           L_80036D5C
    // 0x80036D28: swc1        $f10, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f10.u32l;
        goto L_80036D5C;
    // 0x80036D28: swc1        $f10, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f10.u32l;
L_80036D2C:
    // 0x80036D2C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80036D30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036D34: nop

    // 0x80036D38: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80036D3C: lwc1        $f18, 0xDC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80036D40: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80036D44: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80036D48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036D4C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80036D50: add.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
    // 0x80036D54: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80036D58: swc1        $f10, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f10.u32l;
L_80036D5C:
    // 0x80036D5C: lwc1        $f4, 0xE4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80036D60: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80036D64: nop

    // 0x80036D68: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80036D6C: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    // 0x80036D70: jal         0x800C1850
    // 0x80036D74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_36;
    // 0x80036D74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x80036D78: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80036D7C: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036D80: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80036D84: jal         0x800C2304
    // 0x80036D88: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_37;
    // 0x80036D88: nop

    after_37:
    // 0x80036D8C: jal         0x800C2070
    // 0x80036D90: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800C2070(rdram, ctx);
        goto after_38;
    // 0x80036D90: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_38:
    // 0x80036D94: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x80036D98: lwc1        $f12, 0x30($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X30);
    // 0x80036D9C: lwc1        $f14, 0x34($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80036DA0: lw          $a2, 0x38($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X38);
    // 0x80036DA4: jal         0x800AF1F0
    // 0x80036DA8: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800AF1F0(rdram, ctx);
        goto after_39;
    // 0x80036DA8: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_39:
    // 0x80036DAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80036DB0: beq         $v0, $at, L_80036E20
    if (ctx->r2 == ctx->r1) {
        // 0x80036DB4: nop
    
            goto L_80036E20;
    }
    // 0x80036DB4: nop

    // 0x80036DB8: lwc1        $f12, 0xE4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80036DBC: jal         0x800C25B8
    // 0x80036DC0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_40;
    // 0x80036DC0: nop

    after_40:
    // 0x80036DC4: lwc1        $f12, 0xE8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80036DC8: jal         0x800C23E8
    // 0x80036DCC: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_41;
    // 0x80036DCC: nop

    after_41:
    // 0x80036DD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80036DD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80036DD8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80036DDC: jal         0x800C2948
    // 0x80036DE0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_42;
    // 0x80036DE0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_42:
    // 0x80036DE4: lhu         $t2, 0x9E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X9E);
    // 0x80036DE8: lhu         $t8, 0xA2($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XA2);
    // 0x80036DEC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80036DF0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80036DF4: addu        $t6, $sp, $t8
    ctx->r14 = ADD32(ctx->r29, ctx->r24);
    // 0x80036DF8: lbu         $t6, 0x38($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X38);
    // 0x80036DFC: lw          $t1, 0x722C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X722C);
    // 0x80036E00: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80036E04: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80036E08: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80036E0C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80036E10: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x80036E14: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80036E18: jal         0x800A42C8
    // 0x80036E1C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800A42C8(rdram, ctx);
        goto after_43;
    // 0x80036E1C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_43:
L_80036E20:
    // 0x80036E20: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80036E24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80036E28: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80036E2C: nop

    // 0x80036E30: c.eq.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl == ctx->f16.fl;
    // 0x80036E34: nop

    // 0x80036E38: bc1f        L_80036E48
    if (!c1cs) {
        // 0x80036E3C: nop
    
            goto L_80036E48;
    }
    // 0x80036E3C: nop

    // 0x80036E40: b           L_80036F60
    // 0x80036E44: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
        goto L_80036F60;
    // 0x80036E44: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
L_80036E48:
    // 0x80036E48: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80036E4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036E50: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80036E54: nop

    // 0x80036E58: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80036E5C: nop

    // 0x80036E60: bc1f        L_80036F60
    if (!c1cs) {
        // 0x80036E64: nop
    
            goto L_80036F60;
    }
    // 0x80036E64: nop

    // 0x80036E68: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80036E6C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80036E70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036E74: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80036E78: c.eq.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d == ctx->f6.d;
    // 0x80036E7C: nop

    // 0x80036E80: bc1f        L_80036F60
    if (!c1cs) {
        // 0x80036E84: nop
    
            goto L_80036F60;
    }
    // 0x80036E84: nop

    // 0x80036E88: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80036E8C: lhu         $t0, 0x728E($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X728E);
    // 0x80036E90: nop

    // 0x80036E94: andi        $t2, $t0, 0x8
    ctx->r10 = ctx->r8 & 0X8;
    // 0x80036E98: bne         $t2, $zero, L_80036F60
    if (ctx->r10 != 0) {
        // 0x80036E9C: nop
    
            goto L_80036F60;
    }
    // 0x80036E9C: nop

    // 0x80036EA0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80036EA4: nop

    // 0x80036EA8: swc1        $f16, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f16.u32l;
    // 0x80036EAC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80036EB0: sh          $t3, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r11;
    // 0x80036EB4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80036EB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80036EBC: nop

    // 0x80036EC0: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x80036EC4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80036EC8: lw          $t1, 0x7278($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7278);
    // 0x80036ECC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80036ED0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80036ED4: lwc1        $f4, 0x10($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X10);
    // 0x80036ED8: jal         0x80033CF0
    // 0x80036EDC: sub.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f18.fl;
    func_80033CF0(rdram, ctx);
        goto after_44;
    // 0x80036EDC: sub.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f18.fl;
    after_44:
    // 0x80036EE0: swc1        $f0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f0.u32l;
    // 0x80036EE4: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80036EE8: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80036EEC: nop

    // 0x80036EF0: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80036EF4: swc1        $f16, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f16.u32l;
    // 0x80036EF8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80036EFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80036F00: nop

    // 0x80036F04: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    // 0x80036F08: jal         0x800B9000
    // 0x80036F0C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800B9000(rdram, ctx);
        goto after_45;
    // 0x80036F0C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_45:
    // 0x80036F10: jal         0x80035CF8
    // 0x80036F14: nop

    func_80035CF8(rdram, ctx);
        goto after_46;
    // 0x80036F14: nop

    after_46:
    // 0x80036F18: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80036F1C: lw          $t4, 0x7278($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7278);
    // 0x80036F20: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80036F24: lhu         $t8, 0x1C($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X1C);
    // 0x80036F28: nop

    // 0x80036F2C: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80036F30: sh          $t6, 0x1C($t4)
    MEM_H(0X1C, ctx->r12) = ctx->r14;
    // 0x80036F34: lw          $t5, 0x7278($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7278);
    // 0x80036F38: nop

    // 0x80036F3C: lhu         $t7, 0x1C($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X1C);
    // 0x80036F40: nop

    // 0x80036F44: bne         $t7, $zero, L_80036F58
    if (ctx->r15 != 0) {
        // 0x80036F48: nop
    
            goto L_80036F58;
    }
    // 0x80036F48: nop

    // 0x80036F4C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80036F50: b           L_80036F60
    // 0x80036F54: sh          $t9, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r25;
        goto L_80036F60;
    // 0x80036F54: sh          $t9, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r25;
L_80036F58:
    // 0x80036F58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80036F5C: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
L_80036F60:
    // 0x80036F60: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80036F64: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80036F68: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80036F6C: jal         0x80034E9C
    // 0x80036F70: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    func_80034E9C(rdram, ctx);
        goto after_47;
    // 0x80036F70: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    after_47:
    // 0x80036F74: beq         $v0, $zero, L_8003707C
    if (ctx->r2 == 0) {
        // 0x80036F78: nop
    
            goto L_8003707C;
    }
    // 0x80036F78: nop

    // 0x80036F7C: lhu         $t2, 0x9E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X9E);
    // 0x80036F80: nop

    // 0x80036F84: beq         $t2, $zero, L_80036F9C
    if (ctx->r10 == 0) {
        // 0x80036F88: nop
    
            goto L_80036F9C;
    }
    // 0x80036F88: nop

    // 0x80036F8C: jal         0x800B9000
    // 0x80036F90: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_800B9000(rdram, ctx);
        goto after_48;
    // 0x80036F90: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_48:
    // 0x80036F94: b           L_80036FA4
    // 0x80036F98: nop

        goto L_80036FA4;
    // 0x80036F98: nop

L_80036F9C:
    // 0x80036F9C: jal         0x800B9000
    // 0x80036FA0: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    func_800B9000(rdram, ctx);
        goto after_49;
    // 0x80036FA0: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_49:
L_80036FA4:
    // 0x80036FA4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80036FA8: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x80036FAC: nop

    // 0x80036FB0: lh          $t1, 0x4A($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X4A);
    // 0x80036FB4: nop

    // 0x80036FB8: addiu       $t8, $t1, 0x3C
    ctx->r24 = ADD32(ctx->r9, 0X3C);
    // 0x80036FBC: sh          $t8, 0x4A($t3)
    MEM_H(0X4A, ctx->r11) = ctx->r24;
    // 0x80036FC0: sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
    // 0x80036FC4: jal         0x8005F064
    // 0x80036FC8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_8005F064(rdram, ctx);
        goto after_50;
    // 0x80036FC8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_50:
    // 0x80036FCC: beq         $v0, $zero, L_8003707C
    if (ctx->r2 == 0) {
        // 0x80036FD0: nop
    
            goto L_8003707C;
    }
    // 0x80036FD0: nop

    // 0x80036FD4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80036FD8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80036FDC: nop

    // 0x80036FE0: addiu       $t4, $t6, 0x4C
    ctx->r12 = ADD32(ctx->r14, 0X4C);
    // 0x80036FE4: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x80036FE8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80036FEC: lw          $t5, 0x64C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X64C);
    // 0x80036FF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80036FF4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80036FF8: sw          $t7, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = ctx->r15;
    // 0x80036FFC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80037000: nop

    // 0x80037004: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80037008: nop

    // 0x8003700C: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80037010: sh          $t2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r10;
    // 0x80037014: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80037018: nop

    // 0x8003701C: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x80037020: nop

    // 0x80037024: slti        $at, $t8, 0x33
    ctx->r1 = SIGNED(ctx->r24) < 0X33 ? 1 : 0;
    // 0x80037028: bne         $at, $zero, L_8003707C
    if (ctx->r1 != 0) {
        // 0x8003702C: nop
    
            goto L_8003707C;
    }
    // 0x8003702C: nop

    // 0x80037030: jal         0x8005F064
    // 0x80037034: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_8005F064(rdram, ctx);
        goto after_51;
    // 0x80037034: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_51:
    // 0x80037038: bne         $v0, $zero, L_80037070
    if (ctx->r2 != 0) {
        // 0x8003703C: nop
    
            goto L_80037070;
    }
    // 0x8003703C: nop

    // 0x80037040: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80037044: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80037048: sb          $t3, 0x7256($at)
    MEM_B(0X7256, ctx->r1) = ctx->r11;
    // 0x8003704C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80037050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037054: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80037058: swc1        $f4, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f4.u32l;
    // 0x8003705C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80037060: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80037064: sh          $t6, 0x654($at)
    MEM_H(0X654, ctx->r1) = ctx->r14;
    // 0x80037068: jal         0x8005F0DC
    // 0x8003706C: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_8005F0DC(rdram, ctx);
        goto after_52;
    // 0x8003706C: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_52:
L_80037070:
    // 0x80037070: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80037074: addiu       $t4, $zero, 0x33
    ctx->r12 = ADD32(0, 0X33);
    // 0x80037078: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
L_8003707C:
    // 0x8003707C: lwc1        $f12, 0xE4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80037080: jal         0x80033CF0
    // 0x80037084: nop

    func_80033CF0(rdram, ctx);
        goto after_53;
    // 0x80037084: nop

    after_53:
    // 0x80037088: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    // 0x8003708C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80037090: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80037094: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80037098: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8003709C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800370A0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800370A4: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800370A8: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x800370AC: bc1f        L_800371DC
    if (!c1cs) {
        // 0x800370B0: nop
    
            goto L_800371DC;
    }
    // 0x800370B0: nop

    // 0x800370B4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x800370B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800370BC: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800370C0: nop

    // 0x800370C4: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x800370C8: nop

    // 0x800370CC: bc1f        L_800370E4
    if (!c1cs) {
        // 0x800370D0: nop
    
            goto L_800370E4;
    }
    // 0x800370D0: nop

    // 0x800370D4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x800370D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800370DC: nop

    // 0x800370E0: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
L_800370E4:
    // 0x800370E4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x800370E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800370EC: lwc1        $f6, 0xA8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800370F0: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x800370F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800370F8: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800370FC: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80037100: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80037104: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80037108: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003710C: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80037110: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80037114: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80037118: nop

    // 0x8003711C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80037120: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80037124: nop

    // 0x80037128: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x8003712C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80037130: beq         $t0, $zero, L_80037184
    if (ctx->r8 == 0) {
        // 0x80037134: nop
    
            goto L_80037184;
    }
    // 0x80037134: nop

    // 0x80037138: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8003713C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037140: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80037144: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80037148: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003714C: nop

    // 0x80037150: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037154: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80037158: nop

    // 0x8003715C: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x80037160: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80037164: bne         $t0, $zero, L_8003717C
    if (ctx->r8 != 0) {
        // 0x80037168: nop
    
            goto L_8003717C;
    }
    // 0x80037168: nop

    // 0x8003716C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80037170: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80037174: b           L_80037194
    // 0x80037178: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80037194;
    // 0x80037178: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8003717C:
    // 0x8003717C: b           L_80037194
    // 0x80037180: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80037194;
    // 0x80037180: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80037184:
    // 0x80037184: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80037188: nop

    // 0x8003718C: bltz        $t0, L_8003717C
    if (SIGNED(ctx->r8) < 0) {
        // 0x80037190: nop
    
            goto L_8003717C;
    }
    // 0x80037190: nop

L_80037194:
    // 0x80037194: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x80037198: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003719C: slt         $at, $t2, $at
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800371A0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800371A4: bne         $at, $zero, L_800371B4
    if (ctx->r1 != 0) {
        // 0x800371A8: sh          $t0, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r8;
            goto L_800371B4;
    }
    // 0x800371A8: sh          $t0, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r8;
    // 0x800371AC: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x800371B0: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
L_800371B4:
    // 0x800371B4: jal         0x800220F4
    // 0x800371B8: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    func_800220F4(rdram, ctx);
        goto after_54;
    // 0x800371B8: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    after_54:
    // 0x800371BC: lhu         $a2, 0x9A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X9A);
    // 0x800371C0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x800371C4: addiu       $a1, $zero, 0x7E
    ctx->r5 = ADD32(0, 0X7E);
    // 0x800371C8: jal         0x80031C90
    // 0x800371CC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80031C90(rdram, ctx);
        goto after_55;
    // 0x800371CC: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_55:
    // 0x800371D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800371D4: nop

    // 0x800371D8: swc1        $f16, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f16.u32l;
L_800371DC:
    // 0x800371DC: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800371E0: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800371E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800371E8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800371EC: c.eq.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d == ctx->f18.d;
    // 0x800371F0: nop

    // 0x800371F4: bc1t        L_80037230
    if (c1cs) {
        // 0x800371F8: nop
    
            goto L_80037230;
    }
    // 0x800371F8: nop

    // 0x800371FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80037200: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80037204: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80037208: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8003720C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80037210: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80037214: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80037218: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x8003721C: bc1f        L_80037230
    if (!c1cs) {
        // 0x80037220: nop
    
            goto L_80037230;
    }
    // 0x80037220: nop

    // 0x80037224: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80037228: nop

    // 0x8003722C: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
L_80037230:
    // 0x80037230: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80037234: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80037238: nop

    // 0x8003723C: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80037240: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80037244: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80037248: nop

    // 0x8003724C: swc1        $f8, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f8.u32l;
    // 0x80037250: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80037254: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80037258: nop

    // 0x8003725C: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x80037260: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80037264: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80037268: nop

    // 0x8003726C: swc1        $f16, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f16.u32l;
    // 0x80037270: lwc1        $f4, 0xE4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80037274: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80037278: nop

    // 0x8003727C: swc1        $f4, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f4.u32l;
    // 0x80037280: lwc1        $f18, 0xE0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80037284: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80037288: nop

    // 0x8003728C: swc1        $f18, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f18.u32l;
    // 0x80037290: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80037294: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80037298: nop

    // 0x8003729C: swc1        $f10, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f10.u32l;
    // 0x800372A0: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800372A4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800372A8: nop

    // 0x800372AC: swc1        $f8, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f8.u32l;
    // 0x800372B0: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800372B4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800372B8: nop

    // 0x800372BC: swc1        $f6, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f6.u32l;
    // 0x800372C0: lwc1        $f16, 0xB0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800372C4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800372C8: nop

    // 0x800372CC: swc1        $f16, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f16.u32l;
    // 0x800372D0: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800372D4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800372D8: nop

    // 0x800372DC: swc1        $f4, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f4.u32l;
    // 0x800372E0: lhu         $t8, 0xA2($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XA2);
    // 0x800372E4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800372E8: nop

    // 0x800372EC: sb          $t8, 0x2C($t3)
    MEM_B(0X2C, ctx->r11) = ctx->r24;
    // 0x800372F0: lhu         $t6, 0xA0($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XA0);
    // 0x800372F4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800372F8: nop

    // 0x800372FC: sb          $t6, 0x2D($t4)
    MEM_B(0X2D, ctx->r12) = ctx->r14;
    // 0x80037300: lhu         $t5, 0x9E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X9E);
    // 0x80037304: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80037308: nop

    // 0x8003730C: sb          $t5, 0x2E($t7)
    MEM_B(0X2E, ctx->r15) = ctx->r13;
    // 0x80037310: lhu         $t0, 0x9C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X9C);
    // 0x80037314: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80037318: nop

    // 0x8003731C: sb          $t0, 0x2F($t2)
    MEM_B(0X2F, ctx->r10) = ctx->r8;
    // 0x80037320: lh          $v0, 0xA6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XA6);
    // 0x80037324: b           L_80037334
    // 0x80037328: nop

        goto L_80037334;
    // 0x80037328: nop

    // 0x8003732C: b           L_80037334
    // 0x80037330: nop

        goto L_80037334;
    // 0x80037330: nop

L_80037334:
    // 0x80037334: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80037338: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003733C: jr          $ra
    // 0x80037340: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80037340: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_80080948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080948: b           L_80080964
    // 0x8008094C: nop

        goto L_80080964;
    // 0x8008094C: nop

    // 0x80080950: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80080954: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80080958: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x8008095C: b           L_80080A78
    // 0x80080960: sh          $t7, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r15;
        goto L_80080A78;
    // 0x80080960: sh          $t7, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r15;
L_80080964:
    // 0x80080964: sh          $zero, 0x56($a0)
    MEM_H(0X56, ctx->r4) = 0;
    // 0x80080968: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8008096C: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x80080970: lwc1        $f4, 0x10($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80080974: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80080978: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8008097C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80080980: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80080984: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80080988: nop

    // 0x8008098C: bc1f        L_800809AC
    if (!c1cs) {
        // 0x80080990: nop
    
            goto L_800809AC;
    }
    // 0x80080990: nop

    // 0x80080994: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80080998: lhu         $t0, 0xEEC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XEEC);
    // 0x8008099C: lhu         $t9, 0x56($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X56);
    // 0x800809A0: nop

    // 0x800809A4: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800809A8: sh          $t1, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r9;
L_800809AC:
    // 0x800809AC: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800809B0: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x800809B4: lwc1        $f10, 0x10($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800809B8: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800809BC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800809C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800809C4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800809C8: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x800809CC: nop

    // 0x800809D0: bc1f        L_800809F0
    if (!c1cs) {
        // 0x800809D4: nop
    
            goto L_800809F0;
    }
    // 0x800809D4: nop

    // 0x800809D8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800809DC: lhu         $t4, 0xEC0($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XEC0);
    // 0x800809E0: lhu         $t3, 0x56($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X56);
    // 0x800809E4: nop

    // 0x800809E8: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800809EC: sh          $t5, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r13;
L_800809F0:
    // 0x800809F0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800809F4: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x800809F8: lwc1        $f4, 0x14($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X14);
    // 0x800809FC: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80080A00: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80080A04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80080A08: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80080A0C: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80080A10: nop

    // 0x80080A14: bc1f        L_80080A34
    if (!c1cs) {
        // 0x80080A18: nop
    
            goto L_80080A34;
    }
    // 0x80080A18: nop

    // 0x80080A1C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80080A20: lhu         $t8, 0xE68($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XE68);
    // 0x80080A24: lhu         $t7, 0x56($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X56);
    // 0x80080A28: nop

    // 0x80080A2C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80080A30: sh          $t9, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r25;
L_80080A34:
    // 0x80080A34: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80080A38: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80080A3C: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80080A40: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x80080A44: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80080A48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80080A4C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80080A50: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80080A54: nop

    // 0x80080A58: bc1f        L_80080A78
    if (!c1cs) {
        // 0x80080A5C: nop
    
            goto L_80080A78;
    }
    // 0x80080A5C: nop

    // 0x80080A60: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80080A64: lhu         $t2, 0xE74($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XE74);
    // 0x80080A68: lhu         $t1, 0x56($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X56);
    // 0x80080A6C: nop

    // 0x80080A70: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80080A74: sh          $t3, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r11;
L_80080A78:
    // 0x80080A78: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80080A7C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80080A80: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80080A84: nop

    // 0x80080A88: sh          $t5, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r13;
    // 0x80080A8C: jr          $ra
    // 0x80080A90: nop

    return;
    // 0x80080A90: nop

    // 0x80080A94: jr          $ra
    // 0x80080A98: nop

    return;
    // 0x80080A98: nop

    // 0x80080A9C: nop

;}
RECOMP_FUNC void func_80084D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084D60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80084D64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80084D68: jal         0x8008B600
    // 0x80084D6C: nop

    func_8008B600(rdram, ctx);
        goto after_0;
    // 0x80084D6C: nop

    after_0:
    // 0x80084D70: b           L_80084D78
    // 0x80084D74: nop

        goto L_80084D78;
    // 0x80084D74: nop

L_80084D78:
    // 0x80084D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80084D80: jr          $ra
    // 0x80084D84: nop

    return;
    // 0x80084D84: nop

;}
RECOMP_FUNC void func_8006DB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DB60: jal         0x80061348
    // 0x8006DB64: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006DB64: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006DB68: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006DB70: beq         $v0, $zero, L_8006DBA0
    if (ctx->r2 == 0) {
        // 0x8006DB74: nop
    
            goto L_8006DBA0;
    }
    // 0x8006DB74: nop

    // 0x8006DB78: jal         0x80061348
    // 0x8006DB7C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006DB7C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x8006DB80: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006DB88: beq         $v0, $zero, L_8006DBA0
    if (ctx->r2 == 0) {
        // 0x8006DB8C: nop
    
            goto L_8006DBA0;
    }
    // 0x8006DB8C: nop

    // 0x8006DB90: jal         0x80061348
    // 0x8006DB94: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006DB94: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    after_2:
    // 0x8006DB98: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006DB9C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006DBA0:
    // 0x8006DBA0: b           L_8006DBB0
    // 0x8006DBA4: nop

        goto L_8006DBB0;
    // 0x8006DBA4: nop

    // 0x8006DBA8: b           L_8006DBB0
    // 0x8006DBAC: nop

        goto L_8006DBB0;
    // 0x8006DBAC: nop

L_8006DBB0:
    // 0x8006DBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DBB8: jr          $ra
    // 0x8006DBBC: nop

    return;
    // 0x8006DBBC: nop

;}
RECOMP_FUNC void Thread_SendMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C152C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C1534: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1538: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C153C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1540: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1544: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C1548: jal         0x800C4AA0
    // 0x800C154C: nop

    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C154C: nop

    after_0:
    // 0x800C1550: b           L_800C1560
    // 0x800C1554: nop

        goto L_800C1560;
    // 0x800C1554: nop

    // 0x800C1558: b           L_800C1560
    // 0x800C155C: nop

        goto L_800C1560;
    // 0x800C155C: nop

L_800C1560:
    // 0x800C1560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1568: jr          $ra
    // 0x800C156C: nop

    return;
    // 0x800C156C: nop

;}
RECOMP_FUNC void func_8006BF10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BF18: jal         0x8005F064
    // 0x8006BF1C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BF1C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_0:
    // 0x8006BF20: b           L_8006BF30
    // 0x8006BF24: nop

        goto L_8006BF30;
    // 0x8006BF24: nop

    // 0x8006BF28: b           L_8006BF30
    // 0x8006BF2C: nop

        goto L_8006BF30;
    // 0x8006BF2C: nop

L_8006BF30:
    // 0x8006BF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BF38: jr          $ra
    // 0x8006BF3C: nop

    return;
    // 0x8006BF3C: nop

;}
RECOMP_FUNC void vsprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EDA4: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x8008EDA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008EDAC: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    // 0x8008EDB0: sw          $a1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r5;
    // 0x8008EDB4: sw          $a2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r6;
    // 0x8008EDB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008EDBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8008EDC0: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x8008EDC4: nop

    // 0x8008EDC8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x8008EDCC: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EDD0: nop

    // 0x8008EDD4: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8008EDD8: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x8008EDDC: nop

    // 0x8008EDE0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
    // 0x8008EDE4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8008EDE8: nop

    // 0x8008EDEC: beq         $t9, $zero, L_800906D0
    if (ctx->r25 == 0) {
        // 0x8008EDF0: nop
    
            goto L_800906D0;
    }
    // 0x8008EDF0: nop

L_8008EDF4:
    // 0x8008EDF4: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x8008EDF8: nop

    // 0x8008EDFC: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8008EE00: nop

    // 0x8008EE04: slti        $at, $t1, 0xE0
    ctx->r1 = SIGNED(ctx->r9) < 0XE0 ? 1 : 0;
    // 0x8008EE08: bne         $at, $zero, L_8008EFF4
    if (ctx->r1 != 0) {
        // 0x8008EE0C: nop
    
            goto L_8008EFF4;
    }
    // 0x8008EE0C: nop

    // 0x8008EE10: slti        $at, $t1, 0xE1
    ctx->r1 = SIGNED(ctx->r9) < 0XE1 ? 1 : 0;
    // 0x8008EE14: beq         $at, $zero, L_8008EFF4
    if (ctx->r1 == 0) {
        // 0x8008EE18: nop
    
            goto L_8008EFF4;
    }
    // 0x8008EE18: nop

    // 0x8008EE1C: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008EE20: nop

    // 0x8008EE24: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008EE28: sw          $t3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r11;
    // 0x8008EE2C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x8008EE30: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8008EE34: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8008EE38: addiu       $t8, $t8, -0x38B8
    ctx->r24 = ADD32(ctx->r24, -0X38B8);
    // 0x8008EE3C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8008EE40: addiu       $t7, $t6, -0x10
    ctx->r15 = ADD32(ctx->r14, -0X10);
    // 0x8008EE44: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8008EE48: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8008EE4C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EE50: nop

    // 0x8008EE54: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8008EE58: nop

    // 0x8008EE5C: bne         $t1, $zero, L_8008EE6C
    if (ctx->r9 != 0) {
        // 0x8008EE60: nop
    
            goto L_8008EE6C;
    }
    // 0x8008EE60: nop

    // 0x8008EE64: b           L_800906B0
    // 0x8008EE68: nop

        goto L_800906B0;
    // 0x8008EE68: nop

L_8008EE6C:
    // 0x8008EE6C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EE70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008EE74: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8008EE78: nop

    // 0x8008EE7C: bne         $t3, $at, L_8008EEAC
    if (ctx->r11 != ctx->r1) {
        // 0x8008EE80: nop
    
            goto L_8008EEAC;
    }
    // 0x8008EE80: nop

    // 0x8008EE84: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EE88: nop

    // 0x8008EE8C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8008EE90: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x8008EE94: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8008EE98: jal         0x80096E58
    // 0x8008EE9C: nop

    func_80096E58(rdram, ctx);
        goto after_0;
    // 0x8008EE9C: nop

    after_0:
    // 0x8008EEA0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EEA4: nop

    // 0x8008EEA8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_8008EEAC:
    // 0x8008EEAC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EEB0: nop

    // 0x8008EEB4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8008EEB8: nop

    // 0x8008EEBC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
    // 0x8008EEC0: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EEC4: nop

    // 0x8008EEC8: beq         $t9, $zero, L_8008EFE4
    if (ctx->r25 == 0) {
        // 0x8008EECC: nop
    
            goto L_8008EFE4;
    }
    // 0x8008EECC: nop

    // 0x8008EED0: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EED4: nop

    // 0x8008EED8: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8008EEDC: nop

    // 0x8008EEE0: beq         $t1, $zero, L_8008EFB8
    if (ctx->r9 == 0) {
        // 0x8008EEE4: nop
    
            goto L_8008EFB8;
    }
    // 0x8008EEE4: nop

L_8008EEE8:
    // 0x8008EEE8: lw          $t2, 0xD4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EEEC: nop

    // 0x8008EEF0: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8008EEF4: nop

    // 0x8008EEF8: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x8008EEFC: bne         $at, $zero, L_8008EF74
    if (ctx->r1 != 0) {
        // 0x8008EF00: nop
    
            goto L_8008EF74;
    }
    // 0x8008EF00: nop

    // 0x8008EF04: lw          $a1, 0xD4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EF08: jal         0x80095E78
    // 0x8008EF0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_1;
    // 0x8008EF0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8008EF10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008EF14: jal         0x80095F9C
    // 0x8008EF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_2;
    // 0x8008EF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008EF1C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008EF20: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008EF24: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF28: srl         $t4, $t5, 8
    ctx->r12 = S32(U32(ctx->r13) >> 8);
    // 0x8008EF2C: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
    // 0x8008EF30: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF34: nop

    // 0x8008EF38: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008EF3C: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x8008EF40: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008EF44: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF48: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8008EF4C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x8008EF50: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF54: nop

    // 0x8008EF58: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008EF5C: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x8008EF60: lw          $t5, 0xD4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EF64: nop

    // 0x8008EF68: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008EF6C: b           L_8008EF98
    // 0x8008EF70: sw          $t4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r12;
        goto L_8008EF98;
    // 0x8008EF70: sw          $t4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r12;
L_8008EF74:
    // 0x8008EF74: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EF78: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF7C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8008EF80: nop

    // 0x8008EF84: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008EF88: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008EF8C: nop

    // 0x8008EF90: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008EF94: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
L_8008EF98:
    // 0x8008EF98: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8008EF9C: nop

    // 0x8008EFA0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008EFA4: sw          $t2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r10;
    // 0x8008EFA8: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8008EFAC: nop

    // 0x8008EFB0: bne         $t3, $zero, L_8008EEE8
    if (ctx->r11 != 0) {
        // 0x8008EFB4: nop
    
            goto L_8008EEE8;
    }
    // 0x8008EFB4: nop

L_8008EFB8:
    // 0x8008EFB8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EFBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008EFC0: lw          $t4, 0xC($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XC);
    // 0x8008EFC4: nop

    // 0x8008EFC8: beq         $t4, $at, L_8008EFE4
    if (ctx->r12 == ctx->r1) {
        // 0x8008EFCC: nop
    
            goto L_8008EFE4;
    }
    // 0x8008EFCC: nop

    // 0x8008EFD0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8008EFD4: nop

    // 0x8008EFD8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8008EFDC: jal         0x800BC980
    // 0x8008EFE0: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x8008EFE0: nop

    after_3:
L_8008EFE4:
    // 0x8008EFE4: b           L_800906B0
    // 0x8008EFE8: nop

        goto L_800906B0;
    // 0x8008EFE8: nop

    // 0x8008EFEC: b           L_8008F0FC
    // 0x8008EFF0: nop

        goto L_8008F0FC;
    // 0x8008EFF0: nop

L_8008EFF4:
    // 0x8008EFF4: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8008EFF8: nop

    // 0x8008EFFC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8008F000: nop

    // 0x8008F004: slti        $at, $t8, 0xE1
    ctx->r1 = SIGNED(ctx->r24) < 0XE1 ? 1 : 0;
    // 0x8008F008: bne         $at, $zero, L_8008F0FC
    if (ctx->r1 != 0) {
        // 0x8008F00C: nop
    
            goto L_8008F0FC;
    }
    // 0x8008F00C: nop

    // 0x8008F010: slti        $at, $t8, 0xF0
    ctx->r1 = SIGNED(ctx->r24) < 0XF0 ? 1 : 0;
    // 0x8008F014: beq         $at, $zero, L_8008F0FC
    if (ctx->r1 == 0) {
        // 0x8008F018: nop
    
            goto L_8008F0FC;
    }
    // 0x8008F018: nop

    // 0x8008F01C: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F020: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F024: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8008F028: nop

    // 0x8008F02C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x8008F030: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F034: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F038: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008F03C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8008F040: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x8008F044: sw          $t4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r12;
    // 0x8008F048: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F04C: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F050: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8008F054: nop

    // 0x8008F058: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F05C: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F060: nop

    // 0x8008F064: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F068: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8008F06C: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F070: addiu       $at, $zero, 0xE2
    ctx->r1 = ADD32(0, 0XE2);
    // 0x8008F074: lbu         $t2, -0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, -0X1);
    // 0x8008F078: nop

    // 0x8008F07C: bne         $t2, $at, L_8008F0F4
    if (ctx->r10 != ctx->r1) {
        // 0x8008F080: nop
    
            goto L_8008F0F4;
    }
    // 0x8008F080: nop

    // 0x8008F084: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8008F088: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8008F08C: bne         $t3, $at, L_8008F0F4
    if (ctx->r11 != ctx->r1) {
        // 0x8008F090: nop
    
            goto L_8008F0F4;
    }
    // 0x8008F090: nop

    // 0x8008F094: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F098: nop

    // 0x8008F09C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008F0A0: sw          $t4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r12;
    // 0x8008F0A4: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F0A8: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F0AC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8008F0B0: nop

    // 0x8008F0B4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F0B8: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F0BC: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F0C0: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8008F0C4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F0C8: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8008F0CC: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
    // 0x8008F0D0: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F0D4: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F0D8: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x8008F0DC: nop

    // 0x8008F0E0: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x8008F0E4: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F0E8: nop

    // 0x8008F0EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008F0F0: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
L_8008F0F4:
    // 0x8008F0F4: b           L_800906B0
    // 0x8008F0F8: nop

        goto L_800906B0;
    // 0x8008F0F8: nop

L_8008F0FC:
    // 0x8008F0FC: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F100: nop

    // 0x8008F104: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8008F108: nop

    // 0x8008F10C: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x8008F110: bne         $at, $zero, L_8008F284
    if (ctx->r1 != 0) {
        // 0x8008F114: nop
    
            goto L_8008F284;
    }
    // 0x8008F114: nop

    // 0x8008F118: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008F11C: lh          $t0, -0x4CC8($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4CC8);
    // 0x8008F120: nop

    // 0x8008F124: andi        $t2, $t0, 0x200
    ctx->r10 = ctx->r8 & 0X200;
    // 0x8008F128: bne         $t2, $zero, L_8008F210
    if (ctx->r10 != 0) {
        // 0x8008F12C: nop
    
            goto L_8008F210;
    }
    // 0x8008F12C: nop

    // 0x8008F130: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8008F134: lh          $t1, -0x4CC8($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CC8);
    // 0x8008F138: nop

    // 0x8008F13C: andi        $t3, $t1, 0x10
    ctx->r11 = ctx->r9 & 0X10;
    // 0x8008F140: beq         $t3, $zero, L_8008F19C
    if (ctx->r11 == 0) {
        // 0x8008F144: nop
    
            goto L_8008F19C;
    }
    // 0x8008F144: nop

    // 0x8008F148: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F14C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F150: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008F154: nop

    // 0x8008F158: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
    // 0x8008F15C: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F160: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F164: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F168: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008F16C: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x8008F170: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8008F174: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F178: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F17C: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x8008F180: nop

    // 0x8008F184: sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
    // 0x8008F188: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F18C: nop

    // 0x8008F190: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008F194: b           L_8008F208
    // 0x8008F198: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
        goto L_8008F208;
    // 0x8008F198: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
L_8008F19C:
    // 0x8008F19C: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F1A0: jal         0x80095E78
    // 0x8008F1A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_4;
    // 0x8008F1A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8008F1A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008F1AC: jal         0x80095F9C
    // 0x8008F1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_5;
    // 0x8008F1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8008F1B4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008F1B8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008F1BC: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F1C0: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x8008F1C4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F1C8: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F1CC: nop

    // 0x8008F1D0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F1D4: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8008F1D8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008F1DC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F1E0: andi        $t1, $t2, 0xFF
    ctx->r9 = ctx->r10 & 0XFF;
    // 0x8008F1E4: sb          $t1, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r9;
    // 0x8008F1E8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F1EC: nop

    // 0x8008F1F0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008F1F4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x8008F1F8: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F1FC: nop

    // 0x8008F200: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008F204: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_8008F208:
    // 0x8008F208: b           L_8008F27C
    // 0x8008F20C: nop

        goto L_8008F27C;
    // 0x8008F20C: nop

L_8008F210:
    // 0x8008F210: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F214: jal         0x80095E78
    // 0x8008F218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_6;
    // 0x8008F218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8008F21C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008F220: jal         0x80095F9C
    // 0x8008F224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_7;
    // 0x8008F224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8008F228: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008F22C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008F230: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F234: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x8008F238: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8008F23C: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F240: nop

    // 0x8008F244: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8008F248: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x8008F24C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008F250: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F254: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x8008F258: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x8008F25C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F260: nop

    // 0x8008F264: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8008F268: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x8008F26C: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F270: nop

    // 0x8008F274: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008F278: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
L_8008F27C:
    // 0x8008F27C: b           L_800906B0
    // 0x8008F280: nop

        goto L_800906B0;
    // 0x8008F280: nop

L_8008F284:
    // 0x8008F284: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F288: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8008F28C: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x8008F290: nop

    // 0x8008F294: beq         $t2, $at, L_8008F2C8
    if (ctx->r10 == ctx->r1) {
        // 0x8008F298: nop
    
            goto L_8008F2C8;
    }
    // 0x8008F298: nop

    // 0x8008F29C: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F2A0: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F2A4: lbu         $t3, 0x0($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X0);
    // 0x8008F2A8: nop

    // 0x8008F2AC: sb          $t3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r11;
    // 0x8008F2B0: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F2B4: nop

    // 0x8008F2B8: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8008F2BC: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x8008F2C0: b           L_800906B0
    // 0x8008F2C4: nop

        goto L_800906B0;
    // 0x8008F2C4: nop

L_8008F2C8:
    // 0x8008F2C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008F2CC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8008F2D0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8008F2D4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8008F2D8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8008F2DC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8008F2E0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F2E4: nop

    // 0x8008F2E8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008F2EC: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
    // 0x8008F2F0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8008F2F4: nop

    // 0x8008F2F8: beq         $t0, $zero, L_800906B0
    if (ctx->r8 == 0) {
        // 0x8008F2FC: nop
    
            goto L_800906B0;
    }
    // 0x8008F2FC: nop

L_8008F300:
    // 0x8008F300: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F304: nop

    // 0x8008F308: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x8008F30C: nop

    // 0x8008F310: addiu       $t3, $t1, -0x2E
    ctx->r11 = ADD32(ctx->r9, -0X2E);
    // 0x8008F314: sltiu       $at, $t3, 0x4B
    ctx->r1 = ctx->r11 < 0X4B ? 1 : 0;
    // 0x8008F318: beq         $at, $zero, L_800906A0
    if (ctx->r1 == 0) {
        // 0x8008F31C: nop
    
            goto L_800906A0;
    }
    // 0x8008F31C: nop

    // 0x8008F320: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008F324: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008F328: addu        $at, $at, $t3
    gpr jr_addend_8008F334 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8008F32C: lw          $t3, -0x9EC($at)
    ctx->r11 = ADD32(ctx->r1, -0X9EC);
    // 0x8008F330: nop

    // 0x8008F334: jr          $t3
    // 0x8008F338: nop

    switch (jr_addend_8008F334 >> 2) {
        case 0: goto L_8008F42C; break;
        case 1: goto L_800906A0; break;
        case 2: goto L_8008F33C; break;
        case 3: goto L_8008F398; break;
        case 4: goto L_8008F398; break;
        case 5: goto L_8008F398; break;
        case 6: goto L_8008F398; break;
        case 7: goto L_8008F398; break;
        case 8: goto L_8008F398; break;
        case 9: goto L_8008F398; break;
        case 10: goto L_8008F398; break;
        case 11: goto L_8008F398; break;
        case 12: goto L_800906A0; break;
        case 13: goto L_800906A0; break;
        case 14: goto L_800906A0; break;
        case 15: goto L_800906A0; break;
        case 16: goto L_800906A0; break;
        case 17: goto L_800906A0; break;
        case 18: goto L_800906A0; break;
        case 19: goto L_800906A0; break;
        case 20: goto L_800906A0; break;
        case 21: goto L_800906A0; break;
        case 22: goto L_8008F478; break;
        case 23: goto L_800906A0; break;
        case 24: goto L_8008FE1C; break;
        case 25: goto L_800906A0; break;
        case 26: goto L_800906A0; break;
        case 27: goto L_800906A0; break;
        case 28: goto L_800906A0; break;
        case 29: goto L_800906A0; break;
        case 30: goto L_800906A0; break;
        case 31: goto L_800906A0; break;
        case 32: goto L_800906A0; break;
        case 33: goto L_800906A0; break;
        case 34: goto L_800906A0; break;
        case 35: goto L_800906A0; break;
        case 36: goto L_800906A0; break;
        case 37: goto L_800906A0; break;
        case 38: goto L_800906A0; break;
        case 39: goto L_800906A0; break;
        case 40: goto L_800906A0; break;
        case 41: goto L_800906A0; break;
        case 42: goto L_8008F780; break;
        case 43: goto L_800906A0; break;
        case 44: goto L_800906A0; break;
        case 45: goto L_800906A0; break;
        case 46: goto L_800906A0; break;
        case 47: goto L_800906A0; break;
        case 48: goto L_800906A0; break;
        case 49: goto L_800906A0; break;
        case 50: goto L_800906A0; break;
        case 51: goto L_80090588; break;
        case 52: goto L_800904B0; break;
        case 53: goto L_800906A0; break;
        case 54: goto L_8008F478; break;
        case 55: goto L_800906A0; break;
        case 56: goto L_8008FE1C; break;
        case 57: goto L_8009051C; break;
        case 58: goto L_800906A0; break;
        case 59: goto L_800906A0; break;
        case 60: goto L_800906A0; break;
        case 61: goto L_800906A0; break;
        case 62: goto L_80090444; break;
        case 63: goto L_800906A0; break;
        case 64: goto L_80090614; break;
        case 65: goto L_800906A0; break;
        case 66: goto L_800906A0; break;
        case 67: goto L_800906A0; break;
        case 68: goto L_800906A0; break;
        case 69: goto L_8008FB50; break;
        case 70: goto L_800903D8; break;
        case 71: goto L_800906A0; break;
        case 72: goto L_800906A0; break;
        case 73: goto L_800906A0; break;
        case 74: goto L_8008F780; break;
        default: switch_error(__func__, 0x8008F334, 0x800EF614);
    }
    // 0x8008F338: nop

L_8008F33C:
    // 0x8008F33C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8008F340: nop

    // 0x8008F344: bne         $t5, $zero, L_8008F398
    if (ctx->r13 != 0) {
        // 0x8008F348: nop
    
            goto L_8008F398;
    }
    // 0x8008F348: nop

    // 0x8008F34C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008F350: nop

    // 0x8008F354: bne         $t4, $zero, L_8008F398
    if (ctx->r12 != 0) {
        // 0x8008F358: nop
    
            goto L_8008F398;
    }
    // 0x8008F358: nop

    // 0x8008F35C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8008F360: nop

    // 0x8008F364: bne         $t6, $zero, L_8008F398
    if (ctx->r14 != 0) {
        // 0x8008F368: nop
    
            goto L_8008F398;
    }
    // 0x8008F368: nop

    // 0x8008F36C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F370: nop

    // 0x8008F374: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8008F378: nop

    // 0x8008F37C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8008F380: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F384: nop

    // 0x8008F388: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F38C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8008F390: b           L_800906A0
    // 0x8008F394: nop

        goto L_800906A0;
    // 0x8008F394: nop

L_8008F398:
    // 0x8008F398: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8008F39C: nop

    // 0x8008F3A0: bne         $t2, $zero, L_8008F3E4
    if (ctx->r10 != 0) {
        // 0x8008F3A4: nop
    
            goto L_8008F3E4;
    }
    // 0x8008F3A4: nop

    // 0x8008F3A8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8008F3AC: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F3B0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8008F3B4: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008F3B8: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8008F3BC: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8008F3C0: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8008F3C4: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8008F3C8: addiu       $t8, $t7, -0x30
    ctx->r24 = ADD32(ctx->r15, -0X30);
    // 0x8008F3CC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8008F3D0: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F3D4: nop

    // 0x8008F3D8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F3DC: b           L_8008F424
    // 0x8008F3E0: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
        goto L_8008F424;
    // 0x8008F3E0: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
L_8008F3E4:
    // 0x8008F3E4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8008F3E8: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F3EC: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8008F3F0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8008F3F4: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x8008F3F8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8008F3FC: addu        $t1, $t5, $t4
    ctx->r9 = ADD32(ctx->r13, ctx->r12);
    // 0x8008F400: addu        $t6, $t2, $t1
    ctx->r14 = ADD32(ctx->r10, ctx->r9);
    // 0x8008F404: addiu       $t7, $t6, -0x30
    ctx->r15 = ADD32(ctx->r14, -0X30);
    // 0x8008F408: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8008F40C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008F410: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8008F414: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F418: nop

    // 0x8008F41C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F420: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
L_8008F424:
    // 0x8008F424: b           L_800906A0
    // 0x8008F428: nop

        goto L_800906A0;
    // 0x8008F428: nop

L_8008F42C:
    // 0x8008F42C: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F430: nop

    // 0x8008F434: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8008F438: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
    // 0x8008F43C: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F440: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8008F444: lbu         $t1, 0x0($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X0);
    // 0x8008F448: nop

    // 0x8008F44C: addu        $t6, $t4, $t1
    ctx->r14 = ADD32(ctx->r12, ctx->r9);
    // 0x8008F450: addiu       $t7, $t6, -0x30
    ctx->r15 = ADD32(ctx->r14, -0X30);
    // 0x8008F454: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8008F458: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008F45C: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8008F460: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F464: nop

    // 0x8008F468: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F46C: sw          $t0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r8;
    // 0x8008F470: b           L_800906A0
    // 0x8008F474: nop

        goto L_800906A0;
    // 0x8008F474: nop

L_8008F478:
    // 0x8008F478: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8008F47C: sb          $t3, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r11;
    // 0x8008F480: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8008F484: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008F488: addiu       $t2, $t5, 0x3
    ctx->r10 = ADD32(ctx->r13, 0X3);
    // 0x8008F48C: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8008F490: addiu       $t1, $t4, 0x4
    ctx->r9 = ADD32(ctx->r12, 0X4);
    // 0x8008F494: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x8008F498: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8008F49C: nop

    // 0x8008F4A0: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x8008F4A4: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F4A8: nop

    // 0x8008F4AC: bgez        $t7, L_8008F4CC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8008F4B0: nop
    
            goto L_8008F4CC;
    }
    // 0x8008F4B0: nop

    // 0x8008F4B4: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8008F4B8: sb          $t8, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r24;
    // 0x8008F4BC: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F4C0: nop

    // 0x8008F4C4: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8008F4C8: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
L_8008F4CC:
    // 0x8008F4CC: lui         $t3, 0x3B9A
    ctx->r11 = S32(0X3B9A << 16);
    // 0x8008F4D0: ori         $t3, $t3, 0xCA00
    ctx->r11 = ctx->r11 | 0XCA00;
    // 0x8008F4D4: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8008F4D8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008F4DC:
    // 0x8008F4DC: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F4E0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8008F4E4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008F4E8: div         $zero, $t5, $t2
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r10)));
    // 0x8008F4EC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8008F4F0: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x8008F4F4: bne         $t2, $zero, L_8008F500
    if (ctx->r10 != 0) {
        // 0x8008F4F8: nop
    
            goto L_8008F500;
    }
    // 0x8008F4F8: nop

    // 0x8008F4FC: break       7
    do_break(2148070652);
L_8008F500:
    // 0x8008F500: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008F504: bne         $t2, $at, L_8008F518
    if (ctx->r10 != ctx->r1) {
        // 0x8008F508: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008F518;
    }
    // 0x8008F508: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008F50C: bne         $t5, $at, L_8008F518
    if (ctx->r13 != ctx->r1) {
        // 0x8008F510: nop
    
            goto L_8008F518;
    }
    // 0x8008F510: nop

    // 0x8008F514: break       6
    do_break(2148070676);
L_8008F518:
    // 0x8008F518: mflo        $t1
    ctx->r9 = lo;
    // 0x8008F51C: sw          $t1, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->r9;
    // 0x8008F520: nop

    // 0x8008F524: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F528: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8008F52C: nop

    // 0x8008F530: div         $zero, $t8, $t9
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r25)));
    // 0x8008F534: bne         $t9, $zero, L_8008F540
    if (ctx->r25 != 0) {
        // 0x8008F538: nop
    
            goto L_8008F540;
    }
    // 0x8008F538: nop

    // 0x8008F53C: break       7
    do_break(2148070716);
L_8008F540:
    // 0x8008F540: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008F544: bne         $t9, $at, L_8008F558
    if (ctx->r25 != ctx->r1) {
        // 0x8008F548: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008F558;
    }
    // 0x8008F548: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008F54C: bne         $t8, $at, L_8008F558
    if (ctx->r24 != ctx->r1) {
        // 0x8008F550: nop
    
            goto L_8008F558;
    }
    // 0x8008F550: nop

    // 0x8008F554: break       6
    do_break(2148070740);
L_8008F558:
    // 0x8008F558: mfhi        $t0
    ctx->r8 = hi;
    // 0x8008F55C: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    // 0x8008F560: nop

    // 0x8008F564: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8008F568: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008F56C: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8008F570: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8008F574: nop

    // 0x8008F578: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8008F57C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8008F580: mflo        $t5
    ctx->r13 = lo;
    // 0x8008F584: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x8008F588: bgtz        $t5, L_8008F4DC
    if (SIGNED(ctx->r13) > 0) {
        // 0x8008F58C: nop
    
            goto L_8008F4DC;
    }
    // 0x8008F58C: nop

    // 0x8008F590: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8008F594: nop

    // 0x8008F598: addiu       $t6, $t1, -0xB
    ctx->r14 = ADD32(ctx->r9, -0XB);
    // 0x8008F59C: blez        $t6, L_8008F5DC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8008F5A0: sw          $t6, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r14;
            goto L_8008F5DC;
    }
    // 0x8008F5A0: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_8008F5A4:
    // 0x8008F5A4: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F5A8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8008F5AC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F5B0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F5B4: nop

    // 0x8008F5B8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8008F5BC: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8008F5C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008F5C4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008F5C8: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x8008F5CC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8008F5D0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8008F5D4: bgtz        $t2, L_8008F5A4
    if (SIGNED(ctx->r10) > 0) {
        // 0x8008F5D8: sw          $t2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r10;
            goto L_8008F5A4;
    }
    // 0x8008F5D8: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
L_8008F5DC:
    // 0x8008F5DC: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008F5E0:
    // 0x8008F5E0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008F5E4: nop

    // 0x8008F5E8: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8008F5EC: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x8008F5F0: lw          $t7, 0x4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4C);
    // 0x8008F5F4: nop

    // 0x8008F5F8: bne         $t7, $zero, L_8008F674
    if (ctx->r15 != 0) {
        // 0x8008F5FC: nop
    
            goto L_8008F674;
    }
    // 0x8008F5FC: nop

    // 0x8008F600: lbu         $t8, 0xC7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F604: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008F608: beq         $t8, $at, L_8008F650
    if (ctx->r24 == ctx->r1) {
        // 0x8008F60C: nop
    
            goto L_8008F650;
    }
    // 0x8008F60C: nop

    // 0x8008F610: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008F614: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8008F618: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8008F61C: subu        $t4, $t3, $t0
    ctx->r12 = SUB32(ctx->r11, ctx->r8);
    // 0x8008F620: slt         $at, $t9, $t4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008F624: bne         $at, $zero, L_8008F648
    if (ctx->r1 != 0) {
        // 0x8008F628: nop
    
            goto L_8008F648;
    }
    // 0x8008F628: nop

    // 0x8008F62C: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F630: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x8008F634: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x8008F638: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F63C: nop

    // 0x8008F640: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F644: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
L_8008F648:
    // 0x8008F648: b           L_8008F66C
    // 0x8008F64C: nop

        goto L_8008F66C;
    // 0x8008F64C: nop

L_8008F650:
    // 0x8008F650: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F654: addiu       $t7, $zero, 0x30
    ctx->r15 = ADD32(0, 0X30);
    // 0x8008F658: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x8008F65C: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F660: nop

    // 0x8008F664: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x8008F668: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
L_8008F66C:
    // 0x8008F66C: b           L_8008F6EC
    // 0x8008F670: nop

        goto L_8008F6EC;
    // 0x8008F670: nop

L_8008F674:
    // 0x8008F674: lbu         $t9, 0xC7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F678: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008F67C: beq         $t9, $at, L_8008F6BC
    if (ctx->r25 == ctx->r1) {
        // 0x8008F680: nop
    
            goto L_8008F6BC;
    }
    // 0x8008F680: nop

    // 0x8008F684: lbu         $t4, 0xC7($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F688: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8008F68C: bne         $t4, $at, L_8008F6B4
    if (ctx->r12 != ctx->r1) {
        // 0x8008F690: nop
    
            goto L_8008F6B4;
    }
    // 0x8008F690: nop

    // 0x8008F694: lbu         $t5, 0xC7($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F698: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F69C: nop

    // 0x8008F6A0: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x8008F6A4: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F6A8: nop

    // 0x8008F6AC: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F6B0: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
L_8008F6B4:
    // 0x8008F6B4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8008F6B8: sb          $t7, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r15;
L_8008F6BC:
    // 0x8008F6BC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008F6C0: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F6C4: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8008F6C8: addu        $t0, $sp, $t3
    ctx->r8 = ADD32(ctx->r29, ctx->r11);
    // 0x8008F6CC: lw          $t0, 0x4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4C);
    // 0x8008F6D0: nop

    // 0x8008F6D4: addiu       $t9, $t0, 0x30
    ctx->r25 = ADD32(ctx->r8, 0X30);
    // 0x8008F6D8: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
    // 0x8008F6DC: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F6E0: nop

    // 0x8008F6E4: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x8008F6E8: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
L_8008F6EC:
    // 0x8008F6EC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008F6F0: nop

    // 0x8008F6F4: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F6F8: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x8008F6FC: bne         $at, $zero, L_8008F5E0
    if (ctx->r1 != 0) {
        // 0x8008F700: sw          $t6, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r14;
            goto L_8008F5E0;
    }
    // 0x8008F700: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8008F704: lbu         $t7, 0xC7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F708: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008F70C: beq         $t7, $at, L_8008F744
    if (ctx->r15 == ctx->r1) {
        // 0x8008F710: nop
    
            goto L_8008F744;
    }
    // 0x8008F710: nop

    // 0x8008F714: lbu         $t8, 0xC7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F718: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8008F71C: bne         $t8, $at, L_8008F744
    if (ctx->r24 != ctx->r1) {
        // 0x8008F720: nop
    
            goto L_8008F744;
    }
    // 0x8008F720: nop

    // 0x8008F724: lbu         $t3, 0xC7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F728: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F72C: nop

    // 0x8008F730: sb          $t3, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r11;
    // 0x8008F734: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F738: nop

    // 0x8008F73C: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8008F740: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
L_8008F744:
    // 0x8008F744: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008F748: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F74C: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8008F750: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x8008F754: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x8008F758: nop

    // 0x8008F75C: addiu       $t6, $t1, 0x30
    ctx->r14 = ADD32(ctx->r9, 0X30);
    // 0x8008F760: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8008F764: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F768: nop

    // 0x8008F76C: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8008F770: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x8008F774: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8008F778: b           L_800906A0
    // 0x8008F77C: nop

        goto L_800906A0;
    // 0x8008F77C: nop

L_8008F780:
    // 0x8008F780: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8008F784: sb          $t0, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r8;
    // 0x8008F788: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8008F78C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008F790: addiu       $t4, $t9, 0x3
    ctx->r12 = ADD32(ctx->r25, 0X3);
    // 0x8008F794: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8008F798: addiu       $t2, $t5, 0x4
    ctx->r10 = ADD32(ctx->r13, 0X4);
    // 0x8008F79C: sw          $t2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r10;
    // 0x8008F7A0: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x8008F7A4: nop

    // 0x8008F7A8: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
    // 0x8008F7AC: lui         $t6, 0x1000
    ctx->r14 = S32(0X1000 << 16);
    // 0x8008F7B0: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8008F7B4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008F7B8:
    // 0x8008F7B8: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F7BC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8008F7C0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008F7C4: divu        $zero, $t7, $t8
    lo = S32(U32(ctx->r15) / U32(ctx->r24)); hi = S32(U32(ctx->r15) % U32(ctx->r24));
    // 0x8008F7C8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8008F7CC: addu        $t4, $sp, $t9
    ctx->r12 = ADD32(ctx->r29, ctx->r25);
    // 0x8008F7D0: bne         $t8, $zero, L_8008F7DC
    if (ctx->r24 != 0) {
        // 0x8008F7D4: nop
    
            goto L_8008F7DC;
    }
    // 0x8008F7D4: nop

    // 0x8008F7D8: break       7
    do_break(2148071384);
L_8008F7DC:
    // 0x8008F7DC: mflo        $t3
    ctx->r11 = lo;
    // 0x8008F7E0: sw          $t3, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->r11;
    // 0x8008F7E4: nop

    // 0x8008F7E8: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8008F7EC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8008F7F0: nop

    // 0x8008F7F4: divu        $zero, $t2, $t5
    lo = S32(U32(ctx->r10) / U32(ctx->r13)); hi = S32(U32(ctx->r10) % U32(ctx->r13));
    // 0x8008F7F8: bne         $t5, $zero, L_8008F804
    if (ctx->r13 != 0) {
        // 0x8008F7FC: nop
    
            goto L_8008F804;
    }
    // 0x8008F7FC: nop

    // 0x8008F800: break       7
    do_break(2148071424);
L_8008F804:
    // 0x8008F804: mfhi        $t1
    ctx->r9 = hi;
    // 0x8008F808: sw          $t1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r9;
    // 0x8008F80C: nop

    // 0x8008F810: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008F814: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008F818: bgez        $t6, L_8008F828
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008F81C: sra         $t7, $t6, 4
        ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
            goto L_8008F828;
    }
    // 0x8008F81C: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x8008F820: addiu       $at, $t6, 0xF
    ctx->r1 = ADD32(ctx->r14, 0XF);
    // 0x8008F824: sra         $t7, $at, 4
    ctx->r15 = S32(SIGNED(ctx->r1) >> 4);
L_8008F828:
    // 0x8008F828: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8008F82C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8008F830: bgtz        $t7, L_8008F7B8
    if (SIGNED(ctx->r15) > 0) {
        // 0x8008F834: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_8008F7B8;
    }
    // 0x8008F834: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8008F838: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8008F83C: nop

    // 0x8008F840: addiu       $t9, $t3, -0x9
    ctx->r25 = ADD32(ctx->r11, -0X9);
    // 0x8008F844: blez        $t9, L_8008F8B4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8008F848: sw          $t9, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r25;
            goto L_8008F8B4;
    }
    // 0x8008F848: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_8008F84C:
    // 0x8008F84C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8008F850: nop

    // 0x8008F854: beq         $t4, $zero, L_8008F87C
    if (ctx->r12 == 0) {
        // 0x8008F858: nop
    
            goto L_8008F87C;
    }
    // 0x8008F858: nop

    // 0x8008F85C: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F860: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x8008F864: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8008F868: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F86C: nop

    // 0x8008F870: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F874: b           L_8008F898
    // 0x8008F878: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
        goto L_8008F898;
    // 0x8008F878: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
L_8008F87C:
    // 0x8008F87C: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F880: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8008F884: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x8008F888: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F88C: nop

    // 0x8008F890: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x8008F894: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
L_8008F898:
    // 0x8008F898: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008F89C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8008F8A0: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x8008F8A4: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x8008F8A8: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8008F8AC: bgtz        $t4, L_8008F84C
    if (SIGNED(ctx->r12) > 0) {
        // 0x8008F8B0: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_8008F84C;
    }
    // 0x8008F8B0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_8008F8B4:
    // 0x8008F8B4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008F8B8:
    // 0x8008F8B8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008F8BC: nop

    // 0x8008F8C0: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8008F8C4: addu        $t8, $sp, $t6
    ctx->r24 = ADD32(ctx->r29, ctx->r14);
    // 0x8008F8C8: lw          $t8, 0x4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C);
    // 0x8008F8CC: nop

    // 0x8008F8D0: bne         $t8, $zero, L_8008F97C
    if (ctx->r24 != 0) {
        // 0x8008F8D4: nop
    
            goto L_8008F97C;
    }
    // 0x8008F8D4: nop

    // 0x8008F8D8: lbu         $t0, 0xC7($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XC7);
    // 0x8008F8DC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8008F8E0: beq         $t0, $at, L_8008F958
    if (ctx->r8 == ctx->r1) {
        // 0x8008F8E4: nop
    
            goto L_8008F958;
    }
    // 0x8008F8E4: nop

    // 0x8008F8E8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008F8EC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8008F8F0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8008F8F4: subu        $t2, $t9, $t3
    ctx->r10 = SUB32(ctx->r25, ctx->r11);
    // 0x8008F8F8: slt         $at, $t7, $t2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008F8FC: bne         $at, $zero, L_8008F950
    if (ctx->r1 != 0) {
        // 0x8008F900: nop
    
            goto L_8008F950;
    }
    // 0x8008F900: nop

    // 0x8008F904: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8008F908: nop

    // 0x8008F90C: beq         $t5, $zero, L_8008F934
    if (ctx->r13 == 0) {
        // 0x8008F910: nop
    
            goto L_8008F934;
    }
    // 0x8008F910: nop

    // 0x8008F914: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F918: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x8008F91C: sb          $t4, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r12;
    // 0x8008F920: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F924: nop

    // 0x8008F928: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8008F92C: b           L_8008F950
    // 0x8008F930: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
        goto L_8008F950;
    // 0x8008F930: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
L_8008F934:
    // 0x8008F934: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F938: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8008F93C: sb          $t0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r8;
    // 0x8008F940: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F944: nop

    // 0x8008F948: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x8008F94C: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
L_8008F950:
    // 0x8008F950: b           L_8008F974
    // 0x8008F954: nop

        goto L_8008F974;
    // 0x8008F954: nop

L_8008F958:
    // 0x8008F958: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F95C: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x8008F960: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8008F964: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F968: nop

    // 0x8008F96C: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8008F970: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
L_8008F974:
    // 0x8008F974: b           L_8008FA58
    // 0x8008F978: nop

        goto L_8008FA58;
    // 0x8008F978: nop

L_8008F97C:
    // 0x8008F97C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008F980: sb          $t6, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r14;
    // 0x8008F984: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008F988: nop

    // 0x8008F98C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8008F990: addu        $t9, $sp, $t0
    ctx->r25 = ADD32(ctx->r29, ctx->r8);
    // 0x8008F994: lw          $t9, 0x4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4C);
    // 0x8008F998: nop

    // 0x8008F99C: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8008F9A0: beq         $at, $zero, L_8008F9DC
    if (ctx->r1 == 0) {
        // 0x8008F9A4: nop
    
            goto L_8008F9DC;
    }
    // 0x8008F9A4: nop

    // 0x8008F9A8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8008F9AC: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F9B0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8008F9B4: addu        $t2, $sp, $t7
    ctx->r10 = ADD32(ctx->r29, ctx->r15);
    // 0x8008F9B8: lw          $t2, 0x4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4C);
    // 0x8008F9BC: nop

    // 0x8008F9C0: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x8008F9C4: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x8008F9C8: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F9CC: nop

    // 0x8008F9D0: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008F9D4: b           L_8008FA58
    // 0x8008F9D8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
        goto L_8008FA58;
    // 0x8008F9D8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
L_8008F9DC:
    // 0x8008F9DC: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8008F9E0: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8008F9E4: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x8008F9E8: nop

    // 0x8008F9EC: bne         $t0, $at, L_8008FA28
    if (ctx->r8 != ctx->r1) {
        // 0x8008F9F0: nop
    
            goto L_8008FA28;
    }
    // 0x8008F9F0: nop

    // 0x8008F9F4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008F9F8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008F9FC: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8008FA00: addu        $t7, $sp, $t3
    ctx->r15 = ADD32(ctx->r29, ctx->r11);
    // 0x8008FA04: lw          $t7, 0x4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4C);
    // 0x8008FA08: nop

    // 0x8008FA0C: addiu       $t2, $t7, 0x57
    ctx->r10 = ADD32(ctx->r15, 0X57);
    // 0x8008FA10: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8008FA14: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FA18: nop

    // 0x8008FA1C: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8008FA20: b           L_8008FA58
    // 0x8008FA24: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
        goto L_8008FA58;
    // 0x8008FA24: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
L_8008FA28:
    // 0x8008FA28: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008FA2C: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FA30: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8008FA34: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x8008FA38: lw          $t0, 0x4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4C);
    // 0x8008FA3C: nop

    // 0x8008FA40: addiu       $t9, $t0, 0x37
    ctx->r25 = ADD32(ctx->r8, 0X37);
    // 0x8008FA44: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
    // 0x8008FA48: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FA4C: nop

    // 0x8008FA50: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8008FA54: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
L_8008FA58:
    // 0x8008FA58: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8008FA5C: nop

    // 0x8008FA60: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008FA64: slti        $at, $t4, 0x7
    ctx->r1 = SIGNED(ctx->r12) < 0X7 ? 1 : 0;
    // 0x8008FA68: bne         $at, $zero, L_8008F8B8
    if (ctx->r1 != 0) {
        // 0x8008FA6C: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_8008F8B8;
    }
    // 0x8008FA6C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8008FA70: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008FA74: nop

    // 0x8008FA78: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8008FA7C: addu        $t8, $sp, $t6
    ctx->r24 = ADD32(ctx->r29, ctx->r14);
    // 0x8008FA80: lw          $t8, 0x4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C);
    // 0x8008FA84: nop

    // 0x8008FA88: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x8008FA8C: beq         $at, $zero, L_8008FAC8
    if (ctx->r1 == 0) {
        // 0x8008FA90: nop
    
            goto L_8008FAC8;
    }
    // 0x8008FA90: nop

    // 0x8008FA94: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008FA98: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FA9C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8008FAA0: addu        $t3, $sp, $t9
    ctx->r11 = ADD32(ctx->r29, ctx->r25);
    // 0x8008FAA4: lw          $t3, 0x4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4C);
    // 0x8008FAA8: nop

    // 0x8008FAAC: addiu       $t7, $t3, 0x30
    ctx->r15 = ADD32(ctx->r11, 0X30);
    // 0x8008FAB0: sb          $t7, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r15;
    // 0x8008FAB4: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FAB8: nop

    // 0x8008FABC: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008FAC0: b           L_8008FB44
    // 0x8008FAC4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
        goto L_8008FB44;
    // 0x8008FAC4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
L_8008FAC8:
    // 0x8008FAC8: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x8008FACC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8008FAD0: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x8008FAD4: nop

    // 0x8008FAD8: bne         $t6, $at, L_8008FB14
    if (ctx->r14 != ctx->r1) {
        // 0x8008FADC: nop
    
            goto L_8008FB14;
    }
    // 0x8008FADC: nop

    // 0x8008FAE0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008FAE4: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FAE8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8008FAEC: addu        $t9, $sp, $t0
    ctx->r25 = ADD32(ctx->r29, ctx->r8);
    // 0x8008FAF0: lw          $t9, 0x4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4C);
    // 0x8008FAF4: nop

    // 0x8008FAF8: addiu       $t3, $t9, 0x57
    ctx->r11 = ADD32(ctx->r25, 0X57);
    // 0x8008FAFC: sb          $t3, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r11;
    // 0x8008FB00: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FB04: nop

    // 0x8008FB08: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8008FB0C: b           L_8008FB44
    // 0x8008FB10: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
        goto L_8008FB44;
    // 0x8008FB10: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
L_8008FB14:
    // 0x8008FB14: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008FB18: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FB1C: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8008FB20: addu        $t6, $sp, $t1
    ctx->r14 = ADD32(ctx->r29, ctx->r9);
    // 0x8008FB24: lw          $t6, 0x4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4C);
    // 0x8008FB28: nop

    // 0x8008FB2C: addiu       $t8, $t6, 0x37
    ctx->r24 = ADD32(ctx->r14, 0X37);
    // 0x8008FB30: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x8008FB34: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FB38: nop

    // 0x8008FB3C: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x8008FB40: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
L_8008FB44:
    // 0x8008FB44: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8008FB48: b           L_800906A0
    // 0x8008FB4C: nop

        goto L_800906A0;
    // 0x8008FB4C: nop

L_8008FB50:
    // 0x8008FB50: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8008FB54: lh          $t7, -0x4CC8($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4CC8);
    // 0x8008FB58: nop

    // 0x8008FB5C: andi        $t2, $t7, 0x200
    ctx->r10 = ctx->r15 & 0X200;
    // 0x8008FB60: bne         $t2, $zero, L_8008FD0C
    if (ctx->r10 != 0) {
        // 0x8008FB64: nop
    
            goto L_8008FD0C;
    }
    // 0x8008FB64: nop

    // 0x8008FB68: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8008FB6C: lh          $t5, -0x4CC8($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X4CC8);
    // 0x8008FB70: nop

    // 0x8008FB74: andi        $t4, $t5, 0x10
    ctx->r12 = ctx->r13 & 0X10;
    // 0x8008FB78: beq         $t4, $zero, L_8008FC00
    if (ctx->r12 == 0) {
        // 0x8008FB7C: nop
    
            goto L_8008FC00;
    }
    // 0x8008FB7C: nop

    // 0x8008FB80: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FB84: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008FB88: addiu       $t6, $t1, 0x3
    ctx->r14 = ADD32(ctx->r9, 0X3);
    // 0x8008FB8C: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8008FB90: addiu       $t0, $t8, 0x4
    ctx->r8 = ADD32(ctx->r24, 0X4);
    // 0x8008FB94: sw          $t0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r8;
    // 0x8008FB98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008FB9C: nop

    // 0x8008FBA0: sw          $t9, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r25;
    // 0x8008FBA4: lbu         $t3, 0x0($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X0);
    // 0x8008FBA8: nop

    // 0x8008FBAC: beq         $t3, $zero, L_8008FBF8
    if (ctx->r11 == 0) {
        // 0x8008FBB0: nop
    
            goto L_8008FBF8;
    }
    // 0x8008FBB0: nop

L_8008FBB4:
    // 0x8008FBB4: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FBB8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FBBC: lbu         $t2, 0x0($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X0);
    // 0x8008FBC0: nop

    // 0x8008FBC4: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8008FBC8: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FBCC: nop

    // 0x8008FBD0: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8008FBD4: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x8008FBD8: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FBDC: nop

    // 0x8008FBE0: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8008FBE4: sw          $t0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r8;
    // 0x8008FBE8: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x8008FBEC: nop

    // 0x8008FBF0: bne         $t8, $zero, L_8008FBB4
    if (ctx->r24 != 0) {
        // 0x8008FBF4: nop
    
            goto L_8008FBB4;
    }
    // 0x8008FBF4: nop

L_8008FBF8:
    // 0x8008FBF8: b           L_8008FD04
    // 0x8008FBFC: nop

        goto L_8008FD04;
    // 0x8008FBFC: nop

L_8008FC00:
    // 0x8008FC00: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FC04: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008FC08: addiu       $t3, $t9, 0x3
    ctx->r11 = ADD32(ctx->r25, 0X3);
    // 0x8008FC0C: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8008FC10: addiu       $t2, $t7, 0x4
    ctx->r10 = ADD32(ctx->r15, 0X4);
    // 0x8008FC14: sw          $t2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r10;
    // 0x8008FC18: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x8008FC1C: nop

    // 0x8008FC20: sw          $t5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r13;
    // 0x8008FC24: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008FC28: nop

    // 0x8008FC2C: beq         $t4, $zero, L_8008FD04
    if (ctx->r12 == 0) {
        // 0x8008FC30: nop
    
            goto L_8008FD04;
    }
    // 0x8008FC30: nop

L_8008FC34:
    // 0x8008FC34: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FC38: nop

    // 0x8008FC3C: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x8008FC40: nop

    // 0x8008FC44: slti        $at, $t6, 0x80
    ctx->r1 = SIGNED(ctx->r14) < 0X80 ? 1 : 0;
    // 0x8008FC48: bne         $at, $zero, L_8008FCC0
    if (ctx->r1 != 0) {
        // 0x8008FC4C: nop
    
            goto L_8008FCC0;
    }
    // 0x8008FC4C: nop

    // 0x8008FC50: lw          $a1, 0xD4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FC54: jal         0x80095E78
    // 0x8008FC58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_8;
    // 0x8008FC58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8008FC5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008FC60: jal         0x80095F9C
    // 0x8008FC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_9;
    // 0x8008FC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8008FC68: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008FC6C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008FC70: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FC74: srl         $t8, $t0, 8
    ctx->r24 = S32(U32(ctx->r8) >> 8);
    // 0x8008FC78: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8008FC7C: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FC80: nop

    // 0x8008FC84: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8008FC88: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x8008FC8C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8008FC90: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FC94: andi        $t5, $t7, 0xFF
    ctx->r13 = ctx->r15 & 0XFF;
    // 0x8008FC98: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x8008FC9C: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FCA0: nop

    // 0x8008FCA4: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008FCA8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x8008FCAC: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FCB0: nop

    // 0x8008FCB4: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x8008FCB8: b           L_8008FCE4
    // 0x8008FCBC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_8008FCE4;
    // 0x8008FCBC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_8008FCC0:
    // 0x8008FCC0: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FCC4: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FCC8: lbu         $t3, 0x0($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X0);
    // 0x8008FCCC: nop

    // 0x8008FCD0: sb          $t3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r11;
    // 0x8008FCD4: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FCD8: nop

    // 0x8008FCDC: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8008FCE0: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
L_8008FCE4:
    // 0x8008FCE4: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FCE8: nop

    // 0x8008FCEC: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8008FCF0: sw          $t1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r9;
    // 0x8008FCF4: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x8008FCF8: nop

    // 0x8008FCFC: bne         $t6, $zero, L_8008FC34
    if (ctx->r14 != 0) {
        // 0x8008FD00: nop
    
            goto L_8008FC34;
    }
    // 0x8008FD00: nop

L_8008FD04:
    // 0x8008FD04: b           L_8008FE10
    // 0x8008FD08: nop

        goto L_8008FE10;
    // 0x8008FD08: nop

L_8008FD0C:
    // 0x8008FD0C: lw          $t0, 0xF8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FD10: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008FD14: addiu       $t8, $t0, 0x3
    ctx->r24 = ADD32(ctx->r8, 0X3);
    // 0x8008FD18: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8008FD1C: addiu       $t3, $t9, 0x4
    ctx->r11 = ADD32(ctx->r25, 0X4);
    // 0x8008FD20: sw          $t3, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r11;
    // 0x8008FD24: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8008FD28: nop

    // 0x8008FD2C: sw          $t2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r10;
    // 0x8008FD30: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
    // 0x8008FD34: nop

    // 0x8008FD38: beq         $t7, $zero, L_8008FE10
    if (ctx->r15 == 0) {
        // 0x8008FD3C: nop
    
            goto L_8008FE10;
    }
    // 0x8008FD3C: nop

L_8008FD40:
    // 0x8008FD40: lw          $t5, 0xD4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FD44: nop

    // 0x8008FD48: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008FD4C: nop

    // 0x8008FD50: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x8008FD54: bne         $at, $zero, L_8008FDCC
    if (ctx->r1 != 0) {
        // 0x8008FD58: nop
    
            goto L_8008FDCC;
    }
    // 0x8008FD58: nop

    // 0x8008FD5C: lw          $a1, 0xD4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FD60: jal         0x80095E78
    // 0x8008FD64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80095E78(rdram, ctx);
        goto after_10;
    // 0x8008FD64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8008FD68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008FD6C: jal         0x80095F9C
    // 0x8008FD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095F9C(rdram, ctx);
        goto after_11;
    // 0x8008FD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8008FD74: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008FD78: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8008FD7C: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FD80: srl         $t6, $t1, 8
    ctx->r14 = S32(U32(ctx->r9) >> 8);
    // 0x8008FD84: sb          $t6, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r14;
    // 0x8008FD88: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FD8C: nop

    // 0x8008FD90: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8008FD94: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x8008FD98: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008FD9C: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FDA0: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x8008FDA4: sb          $t2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r10;
    // 0x8008FDA8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FDAC: nop

    // 0x8008FDB0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8008FDB4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x8008FDB8: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FDBC: nop

    // 0x8008FDC0: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x8008FDC4: b           L_8008FDF0
    // 0x8008FDC8: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
        goto L_8008FDF0;
    // 0x8008FDC8: sw          $t6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r14;
L_8008FDCC:
    // 0x8008FDCC: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FDD0: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FDD4: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x8008FDD8: nop

    // 0x8008FDDC: sb          $t8, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r24;
    // 0x8008FDE0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008FDE4: nop

    // 0x8008FDE8: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8008FDEC: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
L_8008FDF0:
    // 0x8008FDF0: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x8008FDF4: nop

    // 0x8008FDF8: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8008FDFC: sw          $t5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r13;
    // 0x8008FE00: lbu         $t4, 0x0($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X0);
    // 0x8008FE04: nop

    // 0x8008FE08: bne         $t4, $zero, L_8008FD40
    if (ctx->r12 != 0) {
        // 0x8008FE0C: nop
    
            goto L_8008FD40;
    }
    // 0x8008FE0C: nop

L_8008FE10:
    // 0x8008FE10: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8008FE14: b           L_800906A0
    // 0x8008FE18: nop

        goto L_800906A0;
    // 0x8008FE18: nop

L_8008FE1C:
    // 0x8008FE1C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8008FE20: nop

    // 0x8008FE24: bne         $t1, $zero, L_8008FE34
    if (ctx->r9 != 0) {
        // 0x8008FE28: nop
    
            goto L_8008FE34;
    }
    // 0x8008FE28: nop

    // 0x8008FE2C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8008FE30: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_8008FE34:
    // 0x8008FE34: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8008FE38: sb          $t0, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r8;
    // 0x8008FE3C: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FE40: nop

    // 0x8008FE44: andi        $t3, $t8, 0x1
    ctx->r11 = ctx->r24 & 0X1;
    // 0x8008FE48: beq         $t3, $zero, L_8008FE60
    if (ctx->r11 == 0) {
        // 0x8008FE4C: nop
    
            goto L_8008FE60;
    }
    // 0x8008FE4C: nop

    // 0x8008FE50: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x8008FE54: sw          $t9, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r25;
    // 0x8008FE58: b           L_8008FEA4
    // 0x8008FE5C: addiu       $s0, $t9, -0x16
    ctx->r16 = ADD32(ctx->r25, -0X16);
        goto L_8008FEA4;
    // 0x8008FE5C: addiu       $s0, $t9, -0x16
    ctx->r16 = ADD32(ctx->r25, -0X16);
L_8008FE60:
    // 0x8008FE60: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FE64: nop

    // 0x8008FE68: andi        $t7, $t2, 0x2
    ctx->r15 = ctx->r10 & 0X2;
    // 0x8008FE6C: beq         $t7, $zero, L_8008FE84
    if (ctx->r15 == 0) {
        // 0x8008FE70: nop
    
            goto L_8008FE84;
    }
    // 0x8008FE70: nop

    // 0x8008FE74: addiu       $t5, $t2, 0xA
    ctx->r13 = ADD32(ctx->r10, 0XA);
    // 0x8008FE78: sw          $t5, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r13;
    // 0x8008FE7C: b           L_8008FEA0
    // 0x8008FE80: addiu       $s1, $t5, -0x28
    ctx->r17 = ADD32(ctx->r13, -0X28);
        goto L_8008FEA0;
    // 0x8008FE80: addiu       $s1, $t5, -0x28
    ctx->r17 = ADD32(ctx->r13, -0X28);
L_8008FE84:
    // 0x8008FE84: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x8008FE88: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8008FE8C: addiu       $t1, $t4, 0x7
    ctx->r9 = ADD32(ctx->r12, 0X7);
    // 0x8008FE90: and         $t6, $t1, $at
    ctx->r14 = ctx->r9 & ctx->r1;
    // 0x8008FE94: addiu       $t0, $t6, 0x8
    ctx->r8 = ADD32(ctx->r14, 0X8);
    // 0x8008FE98: sw          $t0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r8;
    // 0x8008FE9C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
L_8008FEA0:
    // 0x8008FEA0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8008FEA4:
    // 0x8008FEA4: lwc1        $f5, -0x8($s0)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r16, -0X8);
    // 0x8008FEA8: lwc1        $f4, -0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X4);
    // 0x8008FEAC: swc1        $f5, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x8008FEB0: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x8008FEB4: lwc1        $f7, 0xE0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x8008FEB8: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8008FEBC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8008FEC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008FEC4: nop

    // 0x8008FEC8: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8008FECC: nop

    // 0x8008FED0: bc1f        L_8008FEF8
    if (!c1cs) {
        // 0x8008FED4: nop
    
            goto L_8008FEF8;
    }
    // 0x8008FED4: nop

    // 0x8008FED8: addiu       $t3, $zero, 0x2D
    ctx->r11 = ADD32(0, 0X2D);
    // 0x8008FEDC: sb          $t3, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r11;
    // 0x8008FEE0: lwc1        $f11, 0xE0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x8008FEE4: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8008FEE8: nop

    // 0x8008FEEC: neg.d       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = -ctx->f10.d;
    // 0x8008FEF0: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x8008FEF4: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
L_8008FEF8:
    // 0x8008FEF8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8008FEFC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8008FF00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8008FF04: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8008FF08: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8008FF0C: swc1        $f19, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x8008FF10: blez        $t8, L_8008FF50
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8008FF14: swc1        $f18, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->f18.u32l;
            goto L_8008FF50;
    }
    // 0x8008FF14: swc1        $f18, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f18.u32l;
L_8008FF18:
    // 0x8008FF18: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8008FF1C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8008FF20: lwc1        $f5, 0xD8($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x8008FF24: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8008FF28: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008FF2C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008FF30: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8008FF34: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8008FF38: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8008FF3C: slt         $at, $t7, $t2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008FF40: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8008FF44: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x8008FF48: bne         $at, $zero, L_8008FF18
    if (ctx->r1 != 0) {
        // 0x8008FF4C: swc1        $f9, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
            goto L_8008FF18;
    }
    // 0x8008FF4C: swc1        $f9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
L_8008FF50:
    // 0x8008FF50: lwc1        $f11, 0xE0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x8008FF54: lwc1        $f10, 0xE4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8008FF58: lwc1        $f17, 0xD8($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x8008FF5C: lwc1        $f16, 0xDC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8008FF60: nop

    // 0x8008FF64: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8008FF68: swc1        $f18, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f18.u32l;
    // 0x8008FF6C: swc1        $f19, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x8008FF70: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008FF74: lwc1        $f5, -0x8C0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X8C0);
    // 0x8008FF78: lwc1        $f4, -0x8BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X8BC);
    // 0x8008FF7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008FF80: lwc1        $f7, -0x8B8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X8B8);
    // 0x8008FF84: lwc1        $f6, -0x8B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X8B4);
    // 0x8008FF88: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8008FF8C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8008FF90: swc1        $f5, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x8008FF94: bc1f        L_80090060
    if (!c1cs) {
        // 0x8008FF98: swc1        $f4, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
            goto L_80090060;
    }
    // 0x8008FF98: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
L_8008FF9C:
    // 0x8008FF9C: lwc1        $f9, 0xE0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x8008FFA0: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8008FFA4: lwc1        $f11, 0xD8($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x8008FFA8: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8008FFAC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008FFB0: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8008FFB4: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8008FFB8: addu        $t6, $sp, $t1
    ctx->r14 = ADD32(ctx->r29, ctx->r9);
    // 0x8008FFBC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8008FFC0: nop

    // 0x8008FFC4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8008FFC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008FFCC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008FFD0: nop

    // 0x8008FFD4: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x8008FFD8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8008FFDC: swc1        $f18, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f18.u32l;
    // 0x8008FFE0: nop

    // 0x8008FFE4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8008FFE8: lwc1        $f9, 0xD8($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x8008FFEC: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8008FFF0: addu        $t8, $sp, $t3
    ctx->r24 = ADD32(ctx->r29, ctx->r11);
    // 0x8008FFF4: lw          $t8, 0x4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C);
    // 0x8008FFF8: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8008FFFC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80090000: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x80090004: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80090008: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8009000C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80090010: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x80090014: swc1        $f18, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f18.u32l;
    // 0x80090018: swc1        $f19, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x8009001C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80090020: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80090024: lwc1        $f5, 0xD8($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD8);
    // 0x80090028: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8009002C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80090030: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80090034: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80090038: lwc1        $f17, -0x8B0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X8B0);
    // 0x8009003C: lwc1        $f16, -0x8AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X8AC);
    // 0x80090040: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80090044: nop

    // 0x80090048: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8009004C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80090050: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x80090054: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x80090058: bc1t        L_8008FF9C
    if (c1cs) {
        // 0x8009005C: swc1        $f9, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
            goto L_8008FF9C;
    }
    // 0x8009005C: swc1        $f9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
L_80090060:
    // 0x80090060: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80090064: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x80090068: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x8009006C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80090070: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80090074:
    // 0x80090074: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80090078: nop

    // 0x8009007C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80090080: addu        $t0, $sp, $t6
    ctx->r8 = ADD32(ctx->r29, ctx->r14);
    // 0x80090084: lw          $t0, 0x4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4C);
    // 0x80090088: nop

    // 0x8009008C: blez        $t0, L_800900A8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80090090: nop
    
            goto L_800900A8;
    }
    // 0x80090090: nop

    // 0x80090094: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x80090098: beq         $at, $zero, L_800900A8
    if (ctx->r1 == 0) {
        // 0x8009009C: nop
    
            goto L_800900A8;
    }
    // 0x8009009C: nop

    // 0x800900A0: b           L_800900D8
    // 0x800900A4: nop

        goto L_800900D8;
    // 0x800900A4: nop

L_800900A8:
    // 0x800900A8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800900AC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800900B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800900B4: addu        $t7, $sp, $t9
    ctx->r15 = ADD32(ctx->r29, ctx->r25);
    // 0x800900B8: sw          $t3, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->r11;
    // 0x800900BC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800900C0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800900C4: addiu       $t5, $t2, -0x1
    ctx->r13 = ADD32(ctx->r10, -0X1);
    // 0x800900C8: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x800900CC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800900D0: bgtz        $t5, L_80090074
    if (SIGNED(ctx->r13) > 0) {
        // 0x800900D4: sw          $t5, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r13;
            goto L_80090074;
    }
    // 0x800900D4: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800900D8:
    // 0x800900D8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800900DC: nop

    // 0x800900E0: addiu       $t0, $t6, -0xB
    ctx->r8 = ADD32(ctx->r14, -0XB);
    // 0x800900E4: blez        $t0, L_80090124
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800900E8: sw          $t0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r8;
            goto L_80090124;
    }
    // 0x800900E8: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
L_800900EC:
    // 0x800900EC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800900F0: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800900F4: sb          $t8, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r24;
    // 0x800900F8: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800900FC: nop

    // 0x80090100: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80090104: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80090108: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8009010C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80090110: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x80090114: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x80090118: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8009011C: bgtz        $t4, L_800900EC
    if (SIGNED(ctx->r12) > 0) {
        // 0x80090120: sw          $t4, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r12;
            goto L_800900EC;
    }
    // 0x80090120: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_80090124:
    // 0x80090124: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80090128:
    // 0x80090128: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8009012C: nop

    // 0x80090130: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80090134: addu        $t8, $sp, $t0
    ctx->r24 = ADD32(ctx->r29, ctx->r8);
    // 0x80090138: lw          $t8, 0x4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C);
    // 0x8009013C: nop

    // 0x80090140: bne         $t8, $zero, L_800901BC
    if (ctx->r24 != 0) {
        // 0x80090144: nop
    
            goto L_800901BC;
    }
    // 0x80090144: nop

    // 0x80090148: lbu         $t3, 0xC7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XC7);
    // 0x8009014C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80090150: beq         $t3, $at, L_80090198
    if (ctx->r11 == ctx->r1) {
        // 0x80090154: nop
    
            goto L_80090198;
    }
    // 0x80090154: nop

    // 0x80090158: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8009015C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80090160: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80090164: subu        $t1, $t2, $t7
    ctx->r9 = SUB32(ctx->r10, ctx->r15);
    // 0x80090168: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8009016C: bne         $at, $zero, L_80090190
    if (ctx->r1 != 0) {
        // 0x80090170: nop
    
            goto L_80090190;
    }
    // 0x80090170: nop

    // 0x80090174: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80090178: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x8009017C: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x80090180: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80090184: nop

    // 0x80090188: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8009018C: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
L_80090190:
    // 0x80090190: b           L_800901B4
    // 0x80090194: nop

        goto L_800901B4;
    // 0x80090194: nop

L_80090198:
    // 0x80090198: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8009019C: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800901A0: sb          $t8, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r24;
    // 0x800901A4: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x800901A8: nop

    // 0x800901AC: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x800901B0: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
L_800901B4:
    // 0x800901B4: b           L_80090234
    // 0x800901B8: nop

        goto L_80090234;
    // 0x800901B8: nop

L_800901BC:
    // 0x800901BC: lbu         $t9, 0xC7($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XC7);
    // 0x800901C0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800901C4: beq         $t9, $at, L_80090204
    if (ctx->r25 == ctx->r1) {
        // 0x800901C8: nop
    
            goto L_80090204;
    }
    // 0x800901C8: nop

    // 0x800901CC: lbu         $t1, 0xC7($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XC7);
    // 0x800901D0: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800901D4: bne         $t1, $at, L_800901FC
    if (ctx->r9 != ctx->r1) {
        // 0x800901D8: nop
    
            goto L_800901FC;
    }
    // 0x800901D8: nop

    // 0x800901DC: lbu         $t5, 0xC7($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XC7);
    // 0x800901E0: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800901E4: nop

    // 0x800901E8: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x800901EC: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800901F0: nop

    // 0x800901F4: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x800901F8: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
L_800901FC:
    // 0x800901FC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80090200: sb          $t8, 0xC7($sp)
    MEM_B(0XC7, ctx->r29) = ctx->r24;
L_80090204:
    // 0x80090204: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80090208: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8009020C: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80090210: addu        $t7, $sp, $t2
    ctx->r15 = ADD32(ctx->r29, ctx->r10);
    // 0x80090214: lw          $t7, 0x4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4C);
    // 0x80090218: nop

    // 0x8009021C: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80090220: sb          $t9, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r25;
    // 0x80090224: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x80090228: nop

    // 0x8009022C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80090230: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
L_80090234:
    // 0x80090234: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80090238: nop

    // 0x8009023C: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x80090240: slti        $at, $t0, 0x9
    ctx->r1 = SIGNED(ctx->r8) < 0X9 ? 1 : 0;
    // 0x80090244: bne         $at, $zero, L_80090128
    if (ctx->r1 != 0) {
        // 0x80090248: sw          $t0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r8;
            goto L_80090128;
    }
    // 0x80090248: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8009024C: lbu         $t8, 0xC7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XC7);
    // 0x80090250: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80090254: beq         $t8, $at, L_8009028C
    if (ctx->r24 == ctx->r1) {
        // 0x80090258: nop
    
            goto L_8009028C;
    }
    // 0x80090258: nop

    // 0x8009025C: lbu         $t3, 0xC7($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XC7);
    // 0x80090260: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80090264: bne         $t3, $at, L_8009028C
    if (ctx->r11 != ctx->r1) {
        // 0x80090268: nop
    
            goto L_8009028C;
    }
    // 0x80090268: nop

    // 0x8009026C: lbu         $t2, 0xC7($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XC7);
    // 0x80090270: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80090274: nop

    // 0x80090278: sb          $t2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r10;
    // 0x8009027C: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80090280: nop

    // 0x80090284: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80090288: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
L_8009028C:
    // 0x8009028C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80090290: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80090294: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80090298: addu        $t6, $sp, $t4
    ctx->r14 = ADD32(ctx->r29, ctx->r12);
    // 0x8009029C: lw          $t6, 0x4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4C);
    // 0x800902A0: nop

    // 0x800902A4: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x800902A8: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    // 0x800902AC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800902B0: nop

    // 0x800902B4: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x800902B8: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x800902BC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800902C0: nop

    // 0x800902C4: beq         $t7, $zero, L_800903CC
    if (ctx->r15 == 0) {
        // 0x800902C8: nop
    
            goto L_800903CC;
    }
    // 0x800902C8: nop

    // 0x800902CC: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x800902D0: addiu       $t9, $zero, 0x2E
    ctx->r25 = ADD32(0, 0X2E);
    // 0x800902D4: sb          $t9, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r25;
    // 0x800902D8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800902DC: nop

    // 0x800902E0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800902E4: sw          $t4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r12;
    // 0x800902E8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800902EC: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_800902F0:
    // 0x800902F0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800902F4: nop

    // 0x800902F8: bgtz        $t0, L_80090308
    if (SIGNED(ctx->r8) > 0) {
        // 0x800902FC: nop
    
            goto L_80090308;
    }
    // 0x800902FC: nop

    // 0x80090300: b           L_80090380
    // 0x80090304: nop

        goto L_80090380;
    // 0x80090304: nop

L_80090308:
    // 0x80090308: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8009030C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80090310: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80090314: addu        $t2, $sp, $t3
    ctx->r10 = ADD32(ctx->r29, ctx->r11);
    // 0x80090318: lw          $t2, 0x4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4C);
    // 0x8009031C: nop

    // 0x80090320: bne         $t2, $at, L_80090330
    if (ctx->r10 != ctx->r1) {
        // 0x80090324: nop
    
            goto L_80090330;
    }
    // 0x80090324: nop

    // 0x80090328: b           L_80090380
    // 0x8009032C: nop

        goto L_80090380;
    // 0x8009032C: nop

L_80090330:
    // 0x80090330: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80090334: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80090338: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8009033C: addu        $t1, $sp, $t9
    ctx->r9 = ADD32(ctx->r29, ctx->r25);
    // 0x80090340: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80090344: nop

    // 0x80090348: addiu       $t5, $t1, 0x30
    ctx->r13 = ADD32(ctx->r9, 0X30);
    // 0x8009034C: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x80090350: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80090354: nop

    // 0x80090358: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8009035C: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x80090360: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80090364: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80090368: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8009036C: slti        $at, $t3, 0x13
    ctx->r1 = SIGNED(ctx->r11) < 0X13 ? 1 : 0;
    // 0x80090370: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x80090374: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80090378: bne         $at, $zero, L_800902F0
    if (ctx->r1 != 0) {
        // 0x8009037C: sw          $t3, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r11;
            goto L_800902F0;
    }
    // 0x8009037C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
L_80090380:
    // 0x80090380: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80090384: nop

    // 0x80090388: blez        $t9, L_800903CC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8009038C: nop
    
            goto L_800903CC;
    }
    // 0x8009038C: nop

L_80090390:
    // 0x80090390: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x80090394: addiu       $t1, $zero, 0x30
    ctx->r9 = ADD32(0, 0X30);
    // 0x80090398: sb          $t1, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r9;
    // 0x8009039C: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800903A0: nop

    // 0x800903A4: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800903A8: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x800903AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800903B0: nop

    // 0x800903B4: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x800903B8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800903BC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800903C0: nop

    // 0x800903C4: bgtz        $t2, L_80090390
    if (SIGNED(ctx->r10) > 0) {
        // 0x800903C8: nop
    
            goto L_80090390;
    }
    // 0x800903C8: nop

L_800903CC:
    // 0x800903CC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800903D0: b           L_800906A0
    // 0x800903D4: nop

        goto L_800906A0;
    // 0x800903D4: nop

L_800903D8:
    // 0x800903D8: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x800903DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800903E0: addiu       $t3, $t7, 0x3
    ctx->r11 = ADD32(ctx->r15, 0X3);
    // 0x800903E4: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x800903E8: addiu       $t1, $t9, 0x4
    ctx->r9 = ADD32(ctx->r25, 0X4);
    // 0x800903EC: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x800903F0: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x800903F4: nop

    // 0x800903F8: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
    // 0x800903FC: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80090400: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80090404: sb          $t4, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r12;
    // 0x80090408: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x8009040C: nop

    // 0x80090410: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x80090414: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80090418: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x8009041C: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80090420: nop

    // 0x80090424: sb          $t2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r10;
    // 0x80090428: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8009042C: nop

    // 0x80090430: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x80090434: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x80090438: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8009043C: b           L_800906A0
    // 0x80090440: nop

        goto L_800906A0;
    // 0x80090440: nop

L_80090444:
    // 0x80090444: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x80090448: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8009044C: addiu       $t5, $t9, 0x3
    ctx->r13 = ADD32(ctx->r25, 0X3);
    // 0x80090450: and         $t4, $t5, $at
    ctx->r12 = ctx->r13 & ctx->r1;
    // 0x80090454: addiu       $t6, $t4, 0x4
    ctx->r14 = ADD32(ctx->r12, 0X4);
    // 0x80090458: sw          $t6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r14;
    // 0x8009045C: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x80090460: nop

    // 0x80090464: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    // 0x80090468: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8009046C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80090470: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x80090474: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80090478: nop

    // 0x8009047C: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x80090480: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x80090484: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x80090488: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8009048C: nop

    // 0x80090490: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
    // 0x80090494: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x80090498: nop

    // 0x8009049C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800904A0: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x800904A4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800904A8: b           L_800906A0
    // 0x800904AC: nop

        goto L_800906A0;
    // 0x800904AC: nop

L_800904B0:
    // 0x800904B0: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x800904B4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800904B8: addiu       $t0, $t4, 0x3
    ctx->r8 = ADD32(ctx->r12, 0X3);
    // 0x800904BC: and         $t8, $t0, $at
    ctx->r24 = ctx->r8 & ctx->r1;
    // 0x800904C0: addiu       $t2, $t8, 0x4
    ctx->r10 = ADD32(ctx->r24, 0X4);
    // 0x800904C4: sw          $t2, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r10;
    // 0x800904C8: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800904CC: nop

    // 0x800904D0: sw          $t7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r15;
    // 0x800904D4: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x800904D8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800904DC: sb          $t3, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r11;
    // 0x800904E0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800904E4: nop

    // 0x800904E8: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x800904EC: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
    // 0x800904F0: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x800904F4: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800904F8: nop

    // 0x800904FC: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
    // 0x80090500: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x80090504: nop

    // 0x80090508: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8009050C: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x80090510: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80090514: b           L_800906A0
    // 0x80090518: nop

        goto L_800906A0;
    // 0x80090518: nop

L_8009051C:
    // 0x8009051C: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x80090520: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80090524: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x80090528: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x8009052C: addiu       $t1, $t3, 0x4
    ctx->r9 = ADD32(ctx->r11, 0X4);
    // 0x80090530: sw          $t1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r9;
    // 0x80090534: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x80090538: nop

    // 0x8009053C: sw          $t9, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r25;
    // 0x80090540: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80090544: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80090548: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x8009054C: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80090550: nop

    // 0x80090554: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x80090558: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8009055C: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x80090560: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80090564: nop

    // 0x80090568: sb          $t2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r10;
    // 0x8009056C: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80090570: nop

    // 0x80090574: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80090578: sw          $t1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r9;
    // 0x8009057C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80090580: b           L_800906A0
    // 0x80090584: nop

        goto L_800906A0;
    // 0x80090584: nop

L_80090588:
    // 0x80090588: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8009058C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80090590: addiu       $t9, $t3, 0x3
    ctx->r25 = ADD32(ctx->r11, 0X3);
    // 0x80090594: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x80090598: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8009059C: sw          $t6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r14;
    // 0x800905A0: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x800905A4: nop

    // 0x800905A8: sw          $t4, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r12;
    // 0x800905AC: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x800905B0: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800905B4: sb          $t0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r8;
    // 0x800905B8: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x800905BC: nop

    // 0x800905C0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800905C4: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x800905C8: lw          $t1, 0xEC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XEC);
    // 0x800905CC: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800905D0: sra         $t3, $t1, 8
    ctx->r11 = S32(SIGNED(ctx->r9) >> 8);
    // 0x800905D4: sb          $t3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r11;
    // 0x800905D8: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800905DC: nop

    // 0x800905E0: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x800905E4: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
    // 0x800905E8: lw          $t4, 0xEC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XEC);
    // 0x800905EC: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x800905F0: nop

    // 0x800905F4: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
    // 0x800905F8: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x800905FC: nop

    // 0x80090600: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x80090604: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80090608: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8009060C: b           L_800906A0
    // 0x80090610: nop

        goto L_800906A0;
    // 0x80090610: nop

L_80090614:
    // 0x80090614: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x80090618: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8009061C: addiu       $t1, $t7, 0x3
    ctx->r9 = ADD32(ctx->r15, 0X3);
    // 0x80090620: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80090624: addiu       $t9, $t3, 0x4
    ctx->r25 = ADD32(ctx->r11, 0X4);
    // 0x80090628: sw          $t9, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r25;
    // 0x8009062C: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80090630: nop

    // 0x80090634: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x80090638: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8009063C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80090640: sb          $t5, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r13;
    // 0x80090644: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x80090648: nop

    // 0x8009064C: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80090650: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x80090654: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x80090658: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x8009065C: sra         $t7, $t8, 8
    ctx->r15 = S32(SIGNED(ctx->r24) >> 8);
    // 0x80090660: sb          $t7, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r15;
    // 0x80090664: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80090668: nop

    // 0x8009066C: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80090670: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x80090674: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x80090678: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8009067C: nop

    // 0x80090680: sb          $t6, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r14;
    // 0x80090684: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x80090688: nop

    // 0x8009068C: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x80090690: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x80090694: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80090698: b           L_800906A0
    // 0x8009069C: nop

        goto L_800906A0;
    // 0x8009069C: nop

L_800906A0:
    // 0x800906A0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800906A4: nop

    // 0x800906A8: bne         $t2, $zero, L_8008F300
    if (ctx->r10 != 0) {
        // 0x800906AC: nop
    
            goto L_8008F300;
    }
    // 0x800906AC: nop

L_800906B0:
    // 0x800906B0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x800906B4: nop

    // 0x800906B8: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800906BC: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x800906C0: lbu         $t1, 0x0($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X0);
    // 0x800906C4: nop

    // 0x800906C8: bne         $t1, $zero, L_8008EDF4
    if (ctx->r9 != 0) {
        // 0x800906CC: nop
    
            goto L_8008EDF4;
    }
    // 0x800906CC: nop

L_800906D0:
    // 0x800906D0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800906D4: nop

    // 0x800906D8: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800906DC: b           L_800906E4
    // 0x800906E0: nop

        goto L_800906E4;
    // 0x800906E0: nop

L_800906E4:
    // 0x800906E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800906E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800906EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800906F0: jr          $ra
    // 0x800906F4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x800906F4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_80066D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066D8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066D90: jal         0x80061348
    // 0x80066D94: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066D94: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    after_0:
    // 0x80066D98: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066D9C: b           L_80066DAC
    // 0x80066DA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066DAC;
    // 0x80066DA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066DA4: b           L_80066DAC
    // 0x80066DA8: nop

        goto L_80066DAC;
    // 0x80066DA8: nop

L_80066DAC:
    // 0x80066DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066DB4: jr          $ra
    // 0x80066DB8: nop

    return;
    // 0x80066DB8: nop

;}
RECOMP_FUNC void func_8005A578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A578: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8005A57C: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8005A580: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A584: bne         $t6, $at, L_8005A5AC
    if (ctx->r14 != ctx->r1) {
        // 0x8005A588: nop
    
            goto L_8005A5AC;
    }
    // 0x8005A588: nop

    // 0x8005A58C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8005A590: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8005A594: nop

    // 0x8005A598: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8005A59C: beq         $at, $zero, L_8005A5AC
    if (ctx->r1 == 0) {
        // 0x8005A5A0: nop
    
            goto L_8005A5AC;
    }
    // 0x8005A5A0: nop

    // 0x8005A5A4: jr          $ra
    // 0x8005A5A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005A5A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A5AC:
    // 0x8005A5AC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8005A5B0: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x8005A5B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005A5B8: bne         $t8, $at, L_8005A5DC
    if (ctx->r24 != ctx->r1) {
        // 0x8005A5BC: nop
    
            goto L_8005A5DC;
    }
    // 0x8005A5BC: nop

    // 0x8005A5C0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8005A5C4: lh          $t9, 0x723C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X723C);
    // 0x8005A5C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005A5CC: bne         $t9, $at, L_8005A5DC
    if (ctx->r25 != ctx->r1) {
        // 0x8005A5D0: nop
    
            goto L_8005A5DC;
    }
    // 0x8005A5D0: nop

    // 0x8005A5D4: jr          $ra
    // 0x8005A5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005A5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A5DC:
    // 0x8005A5DC: jr          $ra
    // 0x8005A5E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8005A5E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800177D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800177D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800177DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800177E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800177E4: jal         0x80016074
    // 0x800177E8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80016074(rdram, ctx);
        goto after_0;
    // 0x800177E8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x800177EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800177F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800177F4: nop

    // 0x800177F8: bne         $t6, $zero, L_80017808
    if (ctx->r14 != 0) {
        // 0x800177FC: nop
    
            goto L_80017808;
    }
    // 0x800177FC: nop

    // 0x80017800: b           L_800178C4
    // 0x80017804: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800178C4;
    // 0x80017804: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017808:
    // 0x80017808: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8001780C: nop

    // 0x80017810: sw          $zero, 0x150($t7)
    MEM_W(0X150, ctx->r15) = 0;
    // 0x80017814: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80017818: nop

    // 0x8001781C: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x80017820: nop

    // 0x80017824: bne         $t9, $zero, L_8001783C
    if (ctx->r25 != 0) {
        // 0x80017828: nop
    
            goto L_8001783C;
    }
    // 0x80017828: nop

    // 0x8001782C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80017830: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80017834: b           L_800178B4
    // 0x80017838: sw          $t0, 0x20C($t1)
    MEM_W(0X20C, ctx->r9) = ctx->r8;
        goto L_800178B4;
    // 0x80017838: sw          $t0, 0x20C($t1)
    MEM_W(0X20C, ctx->r9) = ctx->r8;
L_8001783C:
    // 0x8001783C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80017840: nop

    // 0x80017844: lw          $t3, 0x20C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X20C);
    // 0x80017848: nop

    // 0x8001784C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80017850: lw          $t4, 0x150($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X150);
    // 0x80017854: nop

    // 0x80017858: beq         $t4, $zero, L_800178A4
    if (ctx->r12 == 0) {
        // 0x8001785C: nop
    
            goto L_800178A4;
    }
    // 0x8001785C: nop

L_80017860:
    // 0x80017860: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80017864: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80017868: lw          $t6, 0x150($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X150);
    // 0x8001786C: nop

    // 0x80017870: bne         $t6, $t7, L_80017880
    if (ctx->r14 != ctx->r15) {
        // 0x80017874: nop
    
            goto L_80017880;
    }
    // 0x80017874: nop

    // 0x80017878: b           L_800178C4
    // 0x8001787C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800178C4;
    // 0x8001787C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80017880:
    // 0x80017880: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80017884: nop

    // 0x80017888: lw          $t9, 0x150($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X150);
    // 0x8001788C: nop

    // 0x80017890: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80017894: lw          $t0, 0x150($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X150);
    // 0x80017898: nop

    // 0x8001789C: bne         $t0, $zero, L_80017860
    if (ctx->r8 != 0) {
        // 0x800178A0: nop
    
            goto L_80017860;
    }
    // 0x800178A0: nop

L_800178A4:
    // 0x800178A4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800178A8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800178AC: nop

    // 0x800178B0: sw          $t1, 0x150($t2)
    MEM_W(0X150, ctx->r10) = ctx->r9;
L_800178B4:
    // 0x800178B4: b           L_800178C4
    // 0x800178B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800178C4;
    // 0x800178B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800178BC: b           L_800178C4
    // 0x800178C0: nop

        goto L_800178C4;
    // 0x800178C0: nop

L_800178C4:
    // 0x800178C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800178C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800178CC: jr          $ra
    // 0x800178D0: nop

    return;
    // 0x800178D0: nop

;}
RECOMP_FUNC void func_80071D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071D38: jal         0x80061348
    // 0x80071D3C: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071D3C: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x80071D40: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071D44: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071D48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071D4C: beq         $v0, $zero, L_80071D84
    if (ctx->r2 == 0) {
        // 0x80071D50: nop
    
            goto L_80071D84;
    }
    // 0x80071D50: nop

    // 0x80071D54: jal         0x80061348
    // 0x80071D58: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071D58: addiu       $a0, $zero, 0x531
    ctx->r4 = ADD32(0, 0X531);
    after_1:
    // 0x80071D5C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071D60: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071D64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071D68: beq         $v0, $zero, L_80071D84
    if (ctx->r2 == 0) {
        // 0x80071D6C: nop
    
            goto L_80071D84;
    }
    // 0x80071D6C: nop

    // 0x80071D70: jal         0x80061348
    // 0x80071D74: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071D74: addiu       $a0, $zero, 0x4BC
    ctx->r4 = ADD32(0, 0X4BC);
    after_2:
    // 0x80071D78: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071D7C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071D80: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80071D84:
    // 0x80071D84: b           L_80071D94
    // 0x80071D88: nop

        goto L_80071D94;
    // 0x80071D88: nop

    // 0x80071D8C: b           L_80071D94
    // 0x80071D90: nop

        goto L_80071D94;
    // 0x80071D90: nop

L_80071D94:
    // 0x80071D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071D9C: jr          $ra
    // 0x80071DA0: nop

    return;
    // 0x80071DA0: nop

;}
RECOMP_FUNC void func_80075C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075C9C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80075CA0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80075CA4: nop

    // 0x80075CA8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80075CAC: nop

    // 0x80075CB0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80075CB4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80075CB8: jr          $ra
    // 0x80075CBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80075CBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075CC0: jr          $ra
    // 0x80075CC4: nop

    return;
    // 0x80075CC4: nop

    // 0x80075CC8: jr          $ra
    // 0x80075CCC: nop

    return;
    // 0x80075CCC: nop

;}
RECOMP_FUNC void func_8006785C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006785C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067864: jal         0x80061348
    // 0x80067868: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067868: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006786C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80067870: b           L_80067880
    // 0x80067874: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067880;
    // 0x80067874: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067878: b           L_80067880
    // 0x8006787C: nop

        goto L_80067880;
    // 0x8006787C: nop

L_80067880:
    // 0x80067880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067888: jr          $ra
    // 0x8006788C: nop

    return;
    // 0x8006788C: nop

;}
