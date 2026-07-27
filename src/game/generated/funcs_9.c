#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80021FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80022004: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80022008: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002200C: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x80022010: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80022014: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x80022018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002201C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80022020: bne         $t6, $zero, L_8002202C
    if (ctx->r14 != 0) {
        // 0x80022024: nop
    
            goto L_8002202C;
    }
    // 0x80022024: nop

    // 0x80022028: break       7
    do_break(2147622952);
L_8002202C:
    // 0x8002202C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80022030: bne         $t6, $at, L_80022044
    if (ctx->r14 != ctx->r1) {
        // 0x80022034: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80022044;
    }
    // 0x80022034: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80022038: bne         $t7, $at, L_80022044
    if (ctx->r15 != ctx->r1) {
        // 0x8002203C: nop
    
            goto L_80022044;
    }
    // 0x8002203C: nop

    // 0x80022040: break       6
    do_break(2147622976);
L_80022044:
    // 0x80022044: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80022048: mflo        $a1
    ctx->r5 = lo;
    // 0x8002204C: jal         0x800BB52C
    // 0x80022050: nop

    AudioDriver_ConfigSeqPlayerVolume(rdram, ctx);
        goto after_0;
    // 0x80022050: nop

    after_0:
    // 0x80022054: b           L_8002205C
    // 0x80022058: nop

        goto L_8002205C;
    // 0x80022058: nop

L_8002205C:
    // 0x8002205C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022064: jr          $ra
    // 0x80022068: nop

    return;
    // 0x80022068: nop

;}
RECOMP_FUNC void func_80062750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062750: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80062754: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80062758: nop

    // 0x8006275C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80062760: nop

    // 0x80062764: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80062768: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006276C: jr          $ra
    // 0x80062770: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80062770: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80062774: jr          $ra
    // 0x80062778: nop

    return;
    // 0x80062778: nop

    // 0x8006277C: jr          $ra
    // 0x80062780: nop

    return;
    // 0x80062780: nop

;}
RECOMP_FUNC void AudioDriver_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAD4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BAD50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BAD54: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800BAD58: lw          $t6, -0x17AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X17AC);
    // 0x800BAD5C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800BAD60: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BAD64: sw          $t7, -0x17AC($at)
    MEM_W(-0X17AC, ctx->r1) = ctx->r15;
    // 0x800BAD68: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800BAD6C: lw          $t8, -0x17AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X17AC);
    // 0x800BAD70: nop

    // 0x800BAD74: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BAD78: beq         $t9, $zero, L_800BAD90
    if (ctx->r25 == 0) {
        // 0x800BAD7C: nop
    
            goto L_800BAD90;
    }
    // 0x800BAD7C: nop

    // 0x800BAD80: jal         0x800BA9D4
    // 0x800BAD84: nop

    AudioDriver_UpdateSequence(rdram, ctx);
        goto after_0;
    // 0x800BAD84: nop

    after_0:
    // 0x800BAD88: jal         0x800B9F10
    // 0x800BAD8C: nop

    AudioDriver_UpdateSounds(rdram, ctx);
        goto after_1;
    // 0x800BAD8C: nop

    after_1:
L_800BAD90:
    // 0x800BAD90: b           L_800BAD98
    // 0x800BAD94: nop

        goto L_800BAD98;
    // 0x800BAD94: nop

L_800BAD98:
    // 0x800BAD98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BAD9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BADA0: jr          $ra
    // 0x800BADA4: nop

    return;
    // 0x800BADA4: nop

;}
RECOMP_FUNC void func_80068990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068990: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068994: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068998: nop

    // 0x8006899C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x800689A0: nop

    // 0x800689A4: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x800689A8: jr          $ra
    // 0x800689AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800689AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800689B0: jr          $ra
    // 0x800689B4: nop

    return;
    // 0x800689B4: nop

    // 0x800689B8: jr          $ra
    // 0x800689BC: nop

    return;
    // 0x800689BC: nop

;}
RECOMP_FUNC void func_80077CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077CA4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077CA8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077CAC: nop

    // 0x80077CB0: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80077CB4: nop

    // 0x80077CB8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80077CBC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077CC0: jr          $ra
    // 0x80077CC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077CC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077CC8: jr          $ra
    // 0x80077CCC: nop

    return;
    // 0x80077CCC: nop

    // 0x80077CD0: jr          $ra
    // 0x80077CD4: nop

    return;
    // 0x80077CD4: nop

;}
RECOMP_FUNC void func_8005E908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E908: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005E90C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005E910: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8005E914: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8005E918: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E91C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8005E920: jal         0x800BC6EC
    // 0x8005E924: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x8005E924: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x8005E928: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005E92C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E930: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005E934: nop

    // 0x8005E938: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
    // 0x8005E93C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005E940: nop

    // 0x8005E944: lwc1        $f20, 0x20($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8005E948: nop

    // 0x8005E94C: swc1        $f20, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f20.u32l;
    // 0x8005E950: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005E954: nop

    // 0x8005E958: swc1        $f20, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f20.u32l;
    // 0x8005E95C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005E964: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8005E968: nop

    // 0x8005E96C: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
    // 0x8005E970: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005E974: nop

    // 0x8005E978: lwc1        $f8, 0x1C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8005E97C: nop

    // 0x8005E980: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x8005E984: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8005E988: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8005E98C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005E990: nop

    // 0x8005E994: swc1        $f10, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f10.u32l;
    // 0x8005E998: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E99C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9A0: nop

    // 0x8005E9A4: swc1        $f16, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->f16.u32l;
    // 0x8005E9A8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9AC: nop

    // 0x8005E9B0: lwc1        $f22, 0x30($t3)
    ctx->f22.u32l = MEM_W(ctx->r11, 0X30);
    // 0x8005E9B4: nop

    // 0x8005E9B8: swc1        $f22, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f22.u32l;
    // 0x8005E9BC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9C0: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8005E9C4: swc1        $f20, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f20.u32l;
    // 0x8005E9C8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9CC: nop

    // 0x8005E9D0: swc1        $f20, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f20.u32l;
    // 0x8005E9D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005E9D8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9DC: nop

    // 0x8005E9E0: swc1        $f18, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f18.u32l;
    // 0x8005E9E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E9E8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9EC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8005E9F0: swc1        $f4, 0xA0($t7)
    MEM_W(0XA0, ctx->r15) = ctx->f4.u32l;
    // 0x8005E9F4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005E9F8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8005E9FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005EA00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005EA04: lwc1        $f6, 0xA0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XA0);
    // 0x8005EA08: nop

    // 0x8005EA0C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005EA10: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8005EA14: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8005EA18: sw          $t0, 0x9C($t8)
    MEM_W(0X9C, ctx->r24) = ctx->r8;
    // 0x8005EA1C: nop

    // 0x8005EA20: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA24: nop

    // 0x8005EA28: sw          $zero, 0xB8($t1)
    MEM_W(0XB8, ctx->r9) = 0;
    // 0x8005EA2C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8005EA30: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x8005EA34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8005EA38: bne         $t2, $at, L_8005EA64
    if (ctx->r10 != ctx->r1) {
        // 0x8005EA3C: nop
    
            goto L_8005EA64;
    }
    // 0x8005EA3C: nop

    // 0x8005EA40: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005EA44: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8005EA48: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005EA4C: bne         $t3, $at, L_8005EA64
    if (ctx->r11 != ctx->r1) {
        // 0x8005EA50: nop
    
            goto L_8005EA64;
    }
    // 0x8005EA50: nop

    // 0x8005EA54: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA58: addiu       $t4, $zero, 0x4C
    ctx->r12 = ADD32(0, 0X4C);
    // 0x8005EA5C: b           L_8005EA70
    // 0x8005EA60: sw          $t4, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r12;
        goto L_8005EA70;
    // 0x8005EA60: sw          $t4, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r12;
L_8005EA64:
    // 0x8005EA64: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA68: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x8005EA6C: sw          $t6, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r14;
L_8005EA70:
    // 0x8005EA70: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA74: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8005EA78: sw          $t9, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r25;
    // 0x8005EA7C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA80: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8005EA84: sw          $t8, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r24;
    // 0x8005EA88: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA8C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8005EA90: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8005EA94: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8005EA98: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8005EA9C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8005EAA0: nop

    // 0x8005EAA4: sh          $zero, 0xAC($t5)
    MEM_H(0XAC, ctx->r13) = 0;
    // 0x8005EAA8: jal         0x800BC6EC
    // 0x8005EAAC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x8005EAAC: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_1:
    // 0x8005EAB0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005EAB4: nop

    // 0x8005EAB8: sw          $v0, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r2;
    // 0x8005EABC: jal         0x800BC6EC
    // 0x8005EAC0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x8005EAC0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_2:
    // 0x8005EAC4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8005EAC8: nop

    // 0x8005EACC: sw          $v0, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->r2;
    // 0x8005EAD0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8005EAD4: b           L_8005EAE4
    // 0x8005EAD8: nop

        goto L_8005EAE4;
    // 0x8005EAD8: nop

    // 0x8005EADC: b           L_8005EAE4
    // 0x8005EAE0: nop

        goto L_8005EAE4;
    // 0x8005EAE0: nop

L_8005EAE4:
    // 0x8005EAE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005EAE8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8005EAEC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005EAF0: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005EAF4: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005EAF8: jr          $ra
    // 0x8005EAFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005EAFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006C390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C398: jal         0x8005F064
    // 0x8006C39C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C39C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x8006C3A0: b           L_8006C3B0
    // 0x8006C3A4: nop

        goto L_8006C3B0;
    // 0x8006C3A4: nop

    // 0x8006C3A8: b           L_8006C3B0
    // 0x8006C3AC: nop

        goto L_8006C3B0;
    // 0x8006C3AC: nop

L_8006C3B0:
    // 0x8006C3B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C3B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C3B8: jr          $ra
    // 0x8006C3BC: nop

    return;
    // 0x8006C3BC: nop

;}
RECOMP_FUNC void func_800726C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800726C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800726C8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800726CC: nop

    // 0x800726D0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800726D4: nop

    // 0x800726D8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800726DC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800726E0: jr          $ra
    // 0x800726E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800726E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800726E8: jr          $ra
    // 0x800726EC: nop

    return;
    // 0x800726EC: nop

    // 0x800726F0: jr          $ra
    // 0x800726F4: nop

    return;
    // 0x800726F4: nop

;}
RECOMP_FUNC void func_8006FF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FF80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006FF84: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006FF88: nop

    // 0x8006FF8C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x8006FF90: nop

    // 0x8006FF94: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006FF98: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006FF9C: jr          $ra
    // 0x8006FFA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006FFA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FFA4: jr          $ra
    // 0x8006FFA8: nop

    return;
    // 0x8006FFA8: nop

    // 0x8006FFAC: jr          $ra
    // 0x8006FFB0: nop

    return;
    // 0x8006FFB0: nop

;}
RECOMP_FUNC void func_80070908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007090C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070910: jal         0x80061348
    // 0x80070914: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070914: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x80070918: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007091C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070920: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070924: beq         $v0, $zero, L_80070978
    if (ctx->r2 == 0) {
        // 0x80070928: nop
    
            goto L_80070978;
    }
    // 0x80070928: nop

    // 0x8007092C: jal         0x80061348
    // 0x80070930: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070930: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_1:
    // 0x80070934: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070938: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8007093C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070940: beq         $v0, $zero, L_80070978
    if (ctx->r2 == 0) {
        // 0x80070944: nop
    
            goto L_80070978;
    }
    // 0x80070944: nop

    // 0x80070948: jal         0x80061348
    // 0x8007094C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007094C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070950: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070954: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070958: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007095C: beq         $v0, $zero, L_80070978
    if (ctx->r2 == 0) {
        // 0x80070960: nop
    
            goto L_80070978;
    }
    // 0x80070960: nop

    // 0x80070964: jal         0x80061348
    // 0x80070968: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070968: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x8007096C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070970: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070974: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070978:
    // 0x80070978: b           L_80070988
    // 0x8007097C: nop

        goto L_80070988;
    // 0x8007097C: nop

    // 0x80070980: b           L_80070988
    // 0x80070984: nop

        goto L_80070988;
    // 0x80070984: nop

L_80070988:
    // 0x80070988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007098C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070990: jr          $ra
    // 0x80070994: nop

    return;
    // 0x80070994: nop

;}
RECOMP_FUNC void func_80066AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066AB8: jal         0x80061348
    // 0x80066ABC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066ABC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_0:
    // 0x80066AC0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066AC4: b           L_80066AD4
    // 0x80066AC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066AD4;
    // 0x80066AC8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066ACC: b           L_80066AD4
    // 0x80066AD0: nop

        goto L_80066AD4;
    // 0x80066AD0: nop

L_80066AD4:
    // 0x80066AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066ADC: jr          $ra
    // 0x80066AE0: nop

    return;
    // 0x80066AE0: nop

;}
RECOMP_FUNC void func_8006B920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B920: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006B924: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006B928: nop

    // 0x8006B92C: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x8006B930: nop

    // 0x8006B934: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006B938: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006B93C: jr          $ra
    // 0x8006B940: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006B940: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006B944: jr          $ra
    // 0x8006B948: nop

    return;
    // 0x8006B948: nop

    // 0x8006B94C: jr          $ra
    // 0x8006B950: nop

    return;
    // 0x8006B950: nop

;}
RECOMP_FUNC void func_80048764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048764: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80048768: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004876C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80048770: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80048774: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80048778: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8004877C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80048780: addiu       $t7, $t7, -0x2ADC
    ctx->r15 = ADD32(ctx->r15, -0X2ADC);
    // 0x80048784: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80048788: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8004878C: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x80048790: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80048794: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80048798: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x8004879C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800487A0: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x800487A4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800487A8: jal         0x800AF060
    // 0x800487AC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800AF060(rdram, ctx);
        goto after_0;
    // 0x800487AC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x800487B0: jal         0x800A41B4
    // 0x800487B4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800A41B4(rdram, ctx);
        goto after_1;
    // 0x800487B4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_1:
    // 0x800487B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800487BC: addiu       $a1, $a1, -0x2BF0
    ctx->r5 = ADD32(ctx->r5, -0X2BF0);
    // 0x800487C0: jal         0x800A5624
    // 0x800487C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A5624(rdram, ctx);
        goto after_2;
    // 0x800487C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800487C8: addiu       $t0, $zero, 0x2710
    ctx->r8 = ADD32(0, 0X2710);
    // 0x800487CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800487D0: sw          $t0, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r8;
    // 0x800487D4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800487D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800487DC: sw          $t1, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r9;
    // 0x800487E0: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x800487E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800487E8: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    // 0x800487EC: addiu       $a1, $zero, 0x3E7
    ctx->r5 = ADD32(0, 0X3E7);
    // 0x800487F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800487F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800487F8: jal         0x800A57C4
    // 0x800487FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800A57C4(rdram, ctx);
        goto after_3;
    // 0x800487FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x80048800: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048804: sh          $zero, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = 0;
    // 0x80048808: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004880C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80048810: sh          $t3, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = ctx->r11;
    // 0x80048814: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048818: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8004881C: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x80048820: swc1        $f4, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f4.u32l;
    // 0x80048824: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048828: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004882C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80048830: addiu       $t5, $t5, 0x7158
    ctx->r13 = ADD32(ctx->r13, 0X7158);
    // 0x80048834: swc1        $f6, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f6.u32l;
    // 0x80048838: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004883C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80048840: addiu       $t8, $t8, 0x7158
    ctx->r24 = ADD32(ctx->r24, 0X7158);
    // 0x80048844: swc1        $f8, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f8.u32l;
    // 0x80048848: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004884C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048850: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80048854: addiu       $t6, $t6, 0x7158
    ctx->r14 = ADD32(ctx->r14, 0X7158);
    // 0x80048858: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8004885C: addiu       $t7, $t7, 0x7158
    ctx->r15 = ADD32(ctx->r15, 0X7158);
    // 0x80048860: swc1        $f10, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f10.u32l;
    // 0x80048864: lwc1        $f20, 0x20($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80048868: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8004886C: addiu       $t9, $t9, 0x7158
    ctx->r25 = ADD32(ctx->r25, 0X7158);
    // 0x80048870: swc1        $f20, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f20.u32l;
    // 0x80048874: swc1        $f20, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f20.u32l;
    // 0x80048878: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004887C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048880: swc1        $f16, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f16.u32l;
    // 0x80048884: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048888: swc1        $f16, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f16.u32l;
    // 0x8004888C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80048890: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048894: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048898: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
    // 0x8004889C: jal         0x800BC6EC
    // 0x800488A0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x800488A0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_4:
    // 0x800488A4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800488A8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800488AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800488B0: sw          $t0, 0x7214($at)
    MEM_W(0X7214, ctx->r1) = ctx->r8;
    // 0x800488B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800488B8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800488BC: nop

    // 0x800488C0: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x800488C4: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800488C8: nop

    // 0x800488CC: lwc1        $f22, 0xC($t2)
    ctx->f22.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800488D0: nop

    // 0x800488D4: swc1        $f22, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f22.u32l;
    // 0x800488D8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800488DC: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x800488E0: swc1        $f20, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f20.u32l;
    // 0x800488E4: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800488E8: nop

    // 0x800488EC: swc1        $f20, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f20.u32l;
    // 0x800488F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800488F4: lwc1        $f6, -0x1120($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1120);
    // 0x800488F8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800488FC: nop

    // 0x80048900: swc1        $f6, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f6.u32l;
    // 0x80048904: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80048908: nop

    // 0x8004890C: lwc1        $f22, 0x1C($t8)
    ctx->f22.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80048910: nop

    // 0x80048914: swc1        $f22, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f22.u32l;
    // 0x80048918: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8004891C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80048920: swc1        $f20, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f20.u32l;
    // 0x80048924: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80048928: nop

    // 0x8004892C: swc1        $f20, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f20.u32l;
    // 0x80048930: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80048934: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80048938: nop

    // 0x8004893C: lh          $t0, 0x4A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4A);
    // 0x80048940: nop

    // 0x80048944: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80048948: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8004894C: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80048950: slti        $at, $t3, 0xE43
    ctx->r1 = SIGNED(ctx->r11) < 0XE43 ? 1 : 0;
    // 0x80048954: bne         $at, $zero, L_80048968
    if (ctx->r1 != 0) {
        // 0x80048958: sh          $t1, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r9;
            goto L_80048968;
    }
    // 0x80048958: sh          $t1, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r9;
    // 0x8004895C: addiu       $t4, $zero, 0xE42
    ctx->r12 = ADD32(0, 0XE42);
    // 0x80048960: b           L_80048984
    // 0x80048964: sh          $t4, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r12;
        goto L_80048984;
    // 0x80048964: sh          $t4, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r12;
L_80048968:
    // 0x80048968: lh          $t5, 0x56($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X56);
    // 0x8004896C: nop

    // 0x80048970: slti        $at, $t5, 0x7D0
    ctx->r1 = SIGNED(ctx->r13) < 0X7D0 ? 1 : 0;
    // 0x80048974: beq         $at, $zero, L_80048984
    if (ctx->r1 == 0) {
        // 0x80048978: nop
    
            goto L_80048984;
    }
    // 0x80048978: nop

    // 0x8004897C: addiu       $t8, $zero, 0x7D0
    ctx->r24 = ADD32(0, 0X7D0);
    // 0x80048980: sh          $t8, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r24;
L_80048984:
    // 0x80048984: lh          $t6, 0x56($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X56);
    // 0x80048988: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8004898C: nop

    // 0x80048990: sh          $t6, 0x20($t7)
    MEM_H(0X20, ctx->r15) = ctx->r14;
    // 0x80048994: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80048998: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8004899C: nop

    // 0x800489A0: lh          $t0, 0x4A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4A);
    // 0x800489A4: nop

    // 0x800489A8: addiu       $t1, $t0, 0xB4
    ctx->r9 = ADD32(ctx->r8, 0XB4);
    // 0x800489AC: sh          $t1, 0x4A($t9)
    MEM_H(0X4A, ctx->r25) = ctx->r9;
    // 0x800489B0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800489B4:
    // 0x800489B4: lhu         $t2, 0x54($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X54);
    // 0x800489B8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800489BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800489C0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800489C4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800489C8: lw          $t4, -0x73D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73D0);
    // 0x800489CC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800489D0: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800489D4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800489D8: lw          $t8, 0xC0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC0);
    // 0x800489DC: nop

    // 0x800489E0: ori         $t6, $t8, 0x8240
    ctx->r14 = ctx->r24 | 0X8240;
    // 0x800489E4: sw          $t6, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r14;
    // 0x800489E8: lhu         $t7, 0x54($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X54);
    // 0x800489EC: nop

    // 0x800489F0: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800489F4: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x800489F8: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x800489FC: bne         $at, $zero, L_800489B4
    if (ctx->r1 != 0) {
        // 0x80048A00: sh          $t0, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r8;
            goto L_800489B4;
    }
    // 0x80048A00: sh          $t0, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r8;
    // 0x80048A04: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80048A08: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x80048A0C: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80048A10: lw          $t2, 0xC0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC0);
    // 0x80048A14: nop

    // 0x80048A18: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80048A1C: beq         $t3, $zero, L_80048A88
    if (ctx->r11 == 0) {
        // 0x80048A20: nop
    
            goto L_80048A88;
    }
    // 0x80048A20: nop

    // 0x80048A24: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80048A28: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x80048A2C: nop

    // 0x80048A30: lw          $t8, 0xC0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC0);
    // 0x80048A34: nop

    // 0x80048A38: ori         $t6, $t8, 0x8240
    ctx->r14 = ctx->r24 | 0X8240;
    // 0x80048A3C: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x80048A40: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80048A44: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x80048A48: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80048A4C: sh          $t5, 0xC4($t7)
    MEM_H(0XC4, ctx->r15) = ctx->r13;
    // 0x80048A50: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80048A54: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80048A58: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80048A5C: nop

    // 0x80048A60: andi        $t9, $t1, 0x200
    ctx->r25 = ctx->r9 & 0X200;
    // 0x80048A64: beq         $t9, $zero, L_80048A88
    if (ctx->r25 == 0) {
        // 0x80048A68: nop
    
            goto L_80048A88;
    }
    // 0x80048A68: nop

    // 0x80048A6C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80048A70: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x80048A74: nop

    // 0x80048A78: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x80048A7C: nop

    // 0x80048A80: ori         $t8, $t3, 0x80
    ctx->r24 = ctx->r11 | 0X80;
    // 0x80048A84: sw          $t8, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r24;
L_80048A88:
    // 0x80048A88: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80048A8C: jal         0x800BC6EC
    // 0x80048A90: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x80048A90: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_5:
    // 0x80048A94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048A98: sw          $v0, 0x722C($at)
    MEM_W(0X722C, ctx->r1) = ctx->r2;
    // 0x80048A9C: lhu         $t6, 0x54($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X54);
    // 0x80048AA0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048AA4: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x80048AA8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x80048AAC: lhu         $t5, 0x38($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X38);
    // 0x80048AB0: nop

    // 0x80048AB4: beq         $t5, $at, L_80048B14
    if (ctx->r13 == ctx->r1) {
        // 0x80048AB8: sh          $t5, 0x52($sp)
        MEM_H(0X52, ctx->r29) = ctx->r13;
            goto L_80048B14;
    }
    // 0x80048AB8: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
L_80048ABC:
    // 0x80048ABC: lhu         $a0, 0x52($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X52);
    // 0x80048AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80048AC4: jal         0x800AFB70
    // 0x80048AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_6;
    // 0x80048AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80048ACC: lhu         $t0, 0x54($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X54);
    // 0x80048AD0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80048AD4: lw          $t7, 0x722C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X722C);
    // 0x80048AD8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80048ADC: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80048AE0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80048AE4: lhu         $t3, 0x54($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X54);
    // 0x80048AE8: nop

    // 0x80048AEC: addiu       $t8, $t3, 0x1
    ctx->r24 = ADD32(ctx->r11, 0X1);
    // 0x80048AF0: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80048AF4: lhu         $t2, 0x54($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X54);
    // 0x80048AF8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048AFC: sll         $t6, $t2, 1
    ctx->r14 = S32(ctx->r10 << 1);
    // 0x80048B00: addu        $t4, $sp, $t6
    ctx->r12 = ADD32(ctx->r29, ctx->r14);
    // 0x80048B04: lhu         $t4, 0x38($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X38);
    // 0x80048B08: nop

    // 0x80048B0C: bne         $t4, $at, L_80048ABC
    if (ctx->r12 != ctx->r1) {
        // 0x80048B10: sh          $t4, 0x52($sp)
        MEM_H(0X52, ctx->r29) = ctx->r12;
            goto L_80048ABC;
    }
    // 0x80048B10: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
L_80048B14:
    // 0x80048B14: jal         0x800BC6EC
    // 0x80048B18: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_7;
    // 0x80048B18: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    after_7:
    // 0x80048B1C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80048B20: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80048B24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80048B28: sw          $t5, 0x7240($at)
    MEM_W(0X7240, ctx->r1) = ctx->r13;
    // 0x80048B2C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80048B30:
    // 0x80048B30: lhu         $t0, 0x54($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X54);
    // 0x80048B34: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80048B38: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80048B3C: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80048B40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80048B44: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80048B48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80048B4C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80048B50: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80048B54: addiu       $t1, $t7, 0x9DD
    ctx->r9 = ADD32(ctx->r15, 0X9DD);
    // 0x80048B58: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80048B5C: nop

    // 0x80048B60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80048B64: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x80048B68: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80048B6C: nop

    // 0x80048B70: addiu       $t8, $t3, 0x10
    ctx->r24 = ADD32(ctx->r11, 0X10);
    // 0x80048B74: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80048B78: lhu         $t2, 0x54($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X54);
    // 0x80048B7C: nop

    // 0x80048B80: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x80048B84: andi        $t4, $t6, 0xFFFF
    ctx->r12 = ctx->r14 & 0XFFFF;
    // 0x80048B88: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x80048B8C: bne         $at, $zero, L_80048B30
    if (ctx->r1 != 0) {
        // 0x80048B90: sh          $t6, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r14;
            goto L_80048B30;
    }
    // 0x80048B90: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80048B94: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80048B98: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
L_80048B9C:
    // 0x80048B9C: lhu         $t0, 0x54($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X54);
    // 0x80048BA0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80048BA4: negu        $at, $t0
    ctx->r1 = SUB32(0, ctx->r8);
    // 0x80048BA8: sll         $t7, $at, 2
    ctx->r15 = S32(ctx->r1 << 2);
    // 0x80048BAC: addu        $t7, $t7, $at
    ctx->r15 = ADD32(ctx->r15, ctx->r1);
    // 0x80048BB0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80048BB4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80048BB8: nop

    // 0x80048BBC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80048BC0: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x80048BC4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80048BC8: nop

    // 0x80048BCC: addiu       $t3, $t9, 0x10
    ctx->r11 = ADD32(ctx->r25, 0X10);
    // 0x80048BD0: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80048BD4: lhu         $t8, 0x54($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X54);
    // 0x80048BD8: nop

    // 0x80048BDC: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x80048BE0: andi        $t6, $t2, 0xFFFF
    ctx->r14 = ctx->r10 & 0XFFFF;
    // 0x80048BE4: slti        $at, $t6, 0x12
    ctx->r1 = SIGNED(ctx->r14) < 0X12 ? 1 : 0;
    // 0x80048BE8: bne         $at, $zero, L_80048B9C
    if (ctx->r1 != 0) {
        // 0x80048BEC: sh          $t2, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r10;
            goto L_80048B9C;
    }
    // 0x80048BEC: sh          $t2, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r10;
    // 0x80048BF0: jal         0x80044444
    // 0x80048BF4: nop

    func_80044444(rdram, ctx);
        goto after_8;
    // 0x80048BF4: nop

    after_8:
    // 0x80048BF8: jal         0x80021ED0
    // 0x80048BFC: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_9;
    // 0x80048BFC: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_9:
    // 0x80048C00: b           L_80048C08
    // 0x80048C04: nop

        goto L_80048C08;
    // 0x80048C04: nop

L_80048C08:
    // 0x80048C08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80048C0C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80048C10: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80048C14: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80048C18: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80048C1C: jr          $ra
    // 0x80048C20: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80048C20: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80048C24: nop

    // 0x80048C28: nop

    // 0x80048C2C: nop

;}
RECOMP_FUNC void func_8002C2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C2F8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002C2FC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002C300: swc1        $f29, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002C304: swc1        $f28, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f28.u32l;
    // 0x8002C308: swc1        $f27, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002C30C: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x8002C310: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002C314: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x8002C318: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002C31C: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002C320: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002C324: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002C328: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002C32C: lh          $t6, 0x1630($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1630);
    // 0x8002C330: nop

    // 0x8002C334: bne         $t6, $zero, L_8002C344
    if (ctx->r14 != 0) {
        // 0x8002C338: nop
    
            goto L_8002C344;
    }
    // 0x8002C338: nop

    // 0x8002C33C: b           L_8002D1CC
    // 0x8002C340: nop

        goto L_8002D1CC;
    // 0x8002C340: nop

L_8002C344:
    // 0x8002C344: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002C348: sh          $t7, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = ctx->r15;
    // 0x8002C34C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002C350: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002C354: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8002C358: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002C35C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8002C360: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002C364: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C368: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C36C: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x8002C370: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x8002C374: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    // 0x8002C378: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002C37C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8002C380: jal         0x800B0E88
    // 0x8002C384: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800B0E88(rdram, ctx);
        goto after_0;
    // 0x8002C384: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8002C388: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002C38C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002C390: addiu       $t8, $sp, 0x70
    ctx->r24 = ADD32(ctx->r29, 0X70);
    // 0x8002C394: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x8002C398: swc1        $f10, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f10.u32l;
    // 0x8002C39C: lwc1        $f20, 0x20($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8002C3A0: addiu       $t0, $sp, 0x70
    ctx->r8 = ADD32(ctx->r29, 0X70);
    // 0x8002C3A4: swc1        $f20, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f20.u32l;
    // 0x8002C3A8: swc1        $f20, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f20.u32l;
    // 0x8002C3AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002C3B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002C3B4: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
    // 0x8002C3B8: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x8002C3BC: swc1        $f16, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f16.u32l;
    // 0x8002C3C0: lwc1        $f18, 0x14($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X14);
    // 0x8002C3C4: nop

    // 0x8002C3C8: swc1        $f18, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f18.u32l;
    // 0x8002C3CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002C3D0: addiu       $t3, $sp, 0x70
    ctx->r11 = ADD32(ctx->r29, 0X70);
    // 0x8002C3D4: addiu       $t4, $sp, 0x70
    ctx->r12 = ADD32(ctx->r29, 0X70);
    // 0x8002C3D8: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x8002C3DC: lwc1        $f28, 0x8($t4)
    ctx->f28.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8002C3E0: addiu       $t5, $sp, 0x70
    ctx->r13 = ADD32(ctx->r29, 0X70);
    // 0x8002C3E4: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x8002C3E8: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x8002C3EC: swc1        $f28, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f28.u32l;
    // 0x8002C3F0: swc1        $f26, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f26.u32l;
    // 0x8002C3F4: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x8002C3F8: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x8002C3FC: swc1        $f24, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f24.u32l;
    // 0x8002C400: addiu       $t7, $sp, 0x70
    ctx->r15 = ADD32(ctx->r29, 0X70);
    // 0x8002C404: swc1        $f22, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f22.u32l;
    // 0x8002C408: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8002C40C: addiu       $t8, $sp, 0x70
    ctx->r24 = ADD32(ctx->r29, 0X70);
    // 0x8002C410: swc1        $f20, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f20.u32l;
    // 0x8002C414: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x8002C418: swc1        $f20, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f20.u32l;
    // 0x8002C41C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C420: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C424: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8002C428: jal         0x800B1250
    // 0x8002C42C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_1;
    // 0x8002C42C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8002C430: jal         0x800C1850
    // 0x8002C434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_2;
    // 0x8002C434: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8002C438: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C43C: lwc1        $f6, 0x1618($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1618);
    // 0x8002C440: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C444: lwc1        $f11, -0x18E0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X18E0);
    // 0x8002C448: lwc1        $f10, -0x18DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X18DC);
    // 0x8002C44C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C450: lwc1        $f18, 0x1624($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C454: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C458: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8002C45C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8002C460: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002C464: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C468: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    // 0x8002C46C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002C470: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8002C474: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x8002C478: jal         0x800C2304
    // 0x8002C47C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_3;
    // 0x8002C47C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    after_3:
    // 0x8002C480: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002C484: lh          $t0, 0x163C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X163C);
    // 0x8002C488: nop

    // 0x8002C48C: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8002C490: bne         $at, $zero, L_8002C4A8
    if (ctx->r1 != 0) {
        // 0x8002C494: nop
    
            goto L_8002C4A8;
    }
    // 0x8002C494: nop

    // 0x8002C498: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C49C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C4A0: jal         0x800AD1E4
    // 0x8002C4A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800AD1E4(rdram, ctx);
        goto after_4;
    // 0x8002C4A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
L_8002C4A8:
    // 0x8002C4A8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002C4AC: lh          $t1, 0x163C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X163C);
    // 0x8002C4B0: nop

    // 0x8002C4B4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8002C4B8: sltiu       $at, $t2, 0xD
    ctx->r1 = ctx->r10 < 0XD ? 1 : 0;
    // 0x8002C4BC: beq         $at, $zero, L_8002D190
    if (ctx->r1 == 0) {
        // 0x8002C4C0: nop
    
            goto L_8002D190;
    }
    // 0x8002C4C0: nop

    // 0x8002C4C4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002C4C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C4CC: addu        $at, $at, $t2
    gpr jr_addend_8002C4D8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8002C4D0: lw          $t2, -0x18D8($at)
    ctx->r10 = ADD32(ctx->r1, -0X18D8);
    // 0x8002C4D4: nop

    // 0x8002C4D8: jr          $t2
    // 0x8002C4DC: nop

    switch (jr_addend_8002C4D8 >> 2) {
        case 0: goto L_8002C4E0; break;
        case 1: goto L_8002C6AC; break;
        case 2: goto L_8002C714; break;
        case 3: goto L_8002D190; break;
        case 4: goto L_8002D190; break;
        case 5: goto L_8002D190; break;
        case 6: goto L_8002D190; break;
        case 7: goto L_8002D190; break;
        case 8: goto L_8002D190; break;
        case 9: goto L_8002C984; break;
        case 10: goto L_8002CAE0; break;
        case 11: goto L_8002CE6C; break;
        case 12: goto L_8002CF64; break;
        default: switch_error(__func__, 0x8002C4D8, 0x800EE728);
    }
    // 0x8002C4DC: nop

L_8002C4E0:
    // 0x8002C4E0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C4E4: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C4E8: jal         0x800AD1E4
    // 0x8002C4EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800AD1E4(rdram, ctx);
        goto after_5;
    // 0x8002C4EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x8002C4F0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C4F4: lwc1        $f10, -0x69E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X69E8);
    // 0x8002C4F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C4FC: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C504: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8002C508: lwc1        $f4, 0x1618($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1618);
    // 0x8002C50C: nop

    // 0x8002C510: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8002C514: swc1        $f6, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f6.u32l;
    // 0x8002C518: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C51C: lwc1        $f8, -0x69E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C520: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C524: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C528: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C52C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002C530: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C534: nop

    // 0x8002C538: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8002C53C: swc1        $f18, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f18.u32l;
    // 0x8002C540: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8002C544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002C548: nop

    // 0x8002C54C: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8002C550: nop

    // 0x8002C554: bc1f        L_8002C5BC
    if (!c1cs) {
        // 0x8002C558: nop
    
            goto L_8002C5BC;
    }
    // 0x8002C558: nop

    // 0x8002C55C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8002C560: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002C564: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C568: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8002C56C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002C570: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8002C574: lw          $a3, 0x1618($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1618);
    // 0x8002C578: lh          $a2, 0x1644($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1644);
    // 0x8002C57C: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x8002C580: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x8002C584: jal         0x800298A4
    // 0x8002C588: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800298A4(rdram, ctx);
        goto after_6;
    // 0x8002C588: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8002C58C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C590: sb          $zero, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = 0;
    // 0x8002C594: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C598: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
    // 0x8002C59C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C5A0: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8002C5A4: jal         0x8002C270
    // 0x8002C5A8: nop

    func_8002C270(rdram, ctx);
        goto after_7;
    // 0x8002C5A8: nop

    after_7:
    // 0x8002C5AC: jal         0x800B0E08
    // 0x8002C5B0: nop

    func_800B0E08(rdram, ctx);
        goto after_8;
    // 0x8002C5B0: nop

    after_8:
    // 0x8002C5B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002C5B8: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_8002C5BC:
    // 0x8002C5BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C5C0: lwc1        $f11, -0x18A0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X18A0);
    // 0x8002C5C4: lwc1        $f10, -0x189C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X189C);
    // 0x8002C5C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C5CC: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C5D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C5D4: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C5D8: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8002C5DC: lwc1        $f6, -0x69E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C5E0: nop

    // 0x8002C5E4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C5E8: sub.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f8.d - ctx->f18.d;
    // 0x8002C5EC: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8002C5F0: swc1        $f10, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f10.u32l;
    // 0x8002C5F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C5F8: lwc1        $f7, -0x1898($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1898);
    // 0x8002C5FC: lwc1        $f6, -0x1894($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1894);
    // 0x8002C600: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002C604: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x8002C608: nop

    // 0x8002C60C: bc1f        L_8002C624
    if (!c1cs) {
        // 0x8002C610: nop
    
            goto L_8002C624;
    }
    // 0x8002C610: nop

    // 0x8002C614: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C618: lwc1        $f8, -0x1890($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1890);
    // 0x8002C61C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C620: swc1        $f8, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f8.u32l;
L_8002C624:
    // 0x8002C624: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8002C628: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002C62C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C630: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C634: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002C638: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C63C: mul.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x8002C640: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C644: lwc1        $f6, 0x1354($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x8002C648: nop

    // 0x8002C64C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C650: add.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f8.d + ctx->f16.d;
    // 0x8002C654: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8002C658: swc1        $f18, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f18.u32l;
    // 0x8002C65C: jal         0x800C25B8
    // 0x8002C660: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_9;
    // 0x8002C660: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    after_9:
    // 0x8002C664: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x8002C668: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002C66C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C670: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C674: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002C678: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C67C: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8002C680: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C684: lwc1        $f4, 0x12A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002C688: nop

    // 0x8002C68C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C690: sub.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f18.d - ctx->f16.d;
    // 0x8002C694: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8002C698: swc1        $f10, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f10.u32l;
    // 0x8002C69C: jal         0x800C23E8
    // 0x8002C6A0: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_10;
    // 0x8002C6A0: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    after_10:
    // 0x8002C6A4: b           L_8002D190
    // 0x8002C6A8: nop

        goto L_8002D190;
    // 0x8002C6A8: nop

L_8002C6AC:
    // 0x8002C6AC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C6B0: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C6B4: jal         0x800AD1E4
    // 0x8002C6B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_11;
    // 0x8002C6B8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x8002C6BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C6C0: lwc1        $f8, 0x1650($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1650);
    // 0x8002C6C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C6C8: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C6CC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8002C6D0: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8002C6D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C6D8: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8002C6DC: c.le.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d <= ctx->f6.d;
    // 0x8002C6E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C6E4: bc1f        L_8002C708
    if (!c1cs) {
        // 0x8002C6E8: swc1        $f18, 0x1650($at)
        MEM_W(0X1650, ctx->r1) = ctx->f18.u32l;
            goto L_8002C708;
    }
    // 0x8002C6E8: swc1        $f18, 0x1650($at)
    MEM_W(0X1650, ctx->r1) = ctx->f18.u32l;
    // 0x8002C6EC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8002C6F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C6F4: sh          $t3, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r11;
    // 0x8002C6F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C6FC: lw          $a0, 0x1658($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1658);
    // 0x8002C700: jal         0x800299C4
    // 0x8002C704: nop

    func_800299C4(rdram, ctx);
        goto after_12;
    // 0x8002C704: nop

    after_12:
L_8002C708:
    // 0x8002C708: sh          $zero, 0xAE($sp)
    MEM_H(0XAE, ctx->r29) = 0;
    // 0x8002C70C: b           L_8002D190
    // 0x8002C710: nop

        goto L_8002D190;
    // 0x8002C710: nop

L_8002C714:
    // 0x8002C714: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C718: lwc1        $f11, -0x1888($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1888);
    // 0x8002C71C: lwc1        $f10, -0x1884($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1884);
    // 0x8002C720: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C724: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C728: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C72C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C730: mul.d       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8002C734: lwc1        $f16, 0x15D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002C738: nop

    // 0x8002C73C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C740: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x8002C744: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002C748: swc1        $f10, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f10.u32l;
    // 0x8002C74C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8002C750: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002C754: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C758: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C75C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002C760: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C764: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8002C768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C76C: lwc1        $f8, 0x1354($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x8002C770: nop

    // 0x8002C774: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C778: add.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f10.d + ctx->f18.d;
    // 0x8002C77C: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8002C780: swc1        $f4, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f4.u32l;
    // 0x8002C784: jal         0x800C25B8
    // 0x8002C788: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_13;
    // 0x8002C788: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    after_13:
    // 0x8002C78C: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8002C790: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002C794: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C798: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C79C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C7A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C7A4: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8002C7A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C7AC: lwc1        $f16, 0x12A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002C7B0: nop

    // 0x8002C7B4: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C7B8: sub.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d - ctx->f18.d;
    // 0x8002C7BC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8002C7C0: swc1        $f6, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f6.u32l;
    // 0x8002C7C4: jal         0x800C23E8
    // 0x8002C7C8: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_14;
    // 0x8002C7C8: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    after_14:
    // 0x8002C7CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C7D0: lwc1        $f10, -0x69E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X69E8);
    // 0x8002C7D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C7D8: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C7DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C7E0: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8002C7E4: lwc1        $f18, 0x1618($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1618);
    // 0x8002C7E8: nop

    // 0x8002C7EC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8002C7F0: swc1        $f8, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f8.u32l;
    // 0x8002C7F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C7F8: lwc1        $f6, -0x69E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C7FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C800: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C804: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C808: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002C80C: lwc1        $f18, 0x1624($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C810: nop

    // 0x8002C814: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8002C818: swc1        $f4, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f4.u32l;
    // 0x8002C81C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C820: lwc1        $f8, -0x69E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C824: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002C828: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002C82C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C830: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x8002C834: nop

    // 0x8002C838: bc1f        L_8002C858
    if (!c1cs) {
        // 0x8002C83C: nop
    
            goto L_8002C858;
    }
    // 0x8002C83C: nop

    // 0x8002C840: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C844: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C848: jal         0x800AD1E4
    // 0x8002C84C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800AD1E4(rdram, ctx);
        goto after_15;
    // 0x8002C84C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x8002C850: b           L_8002C868
    // 0x8002C854: nop

        goto L_8002C868;
    // 0x8002C854: nop

L_8002C858:
    // 0x8002C858: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C85C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x8002C860: jal         0x800AD1E4
    // 0x8002C864: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800AD1E4(rdram, ctx);
        goto after_16;
    // 0x8002C864: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_16:
L_8002C868:
    // 0x8002C868: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C86C: lwc1        $f19, -0x1880($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1880);
    // 0x8002C870: lwc1        $f18, -0x187C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X187C);
    // 0x8002C874: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C878: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C87C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C880: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C884: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8002C888: lwc1        $f6, -0x69E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x8002C88C: nop

    // 0x8002C890: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C894: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002C898: sub.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d - ctx->f8.d;
    // 0x8002C89C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8002C8A0: swc1        $f18, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f18.u32l;
    // 0x8002C8A4: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x8002C8A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002C8AC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002C8B0: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8002C8B4: nop

    // 0x8002C8B8: bc1f        L_8002C8D0
    if (!c1cs) {
        // 0x8002C8BC: nop
    
            goto L_8002C8D0;
    }
    // 0x8002C8BC: nop

    // 0x8002C8C0: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8002C8C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002C8C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002C8CC: swc1        $f10, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f10.u32l;
L_8002C8D0:
    // 0x8002C8D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C8D4: lwc1        $f8, 0x1624($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C8D8: lui         $at, 0xC054
    ctx->r1 = S32(0XC054 << 16);
    // 0x8002C8DC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002C8E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002C8E4: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8002C8E8: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8002C8EC: nop

    // 0x8002C8F0: bc1f        L_8002C94C
    if (!c1cs) {
        // 0x8002C8F4: nop
    
            goto L_8002C94C;
    }
    // 0x8002C8F4: nop

    // 0x8002C8F8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002C8FC: lh          $t4, 0x1644($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X1644);
    // 0x8002C900: nop

    // 0x8002C904: beq         $t4, $zero, L_8002C94C
    if (ctx->r12 == 0) {
        // 0x8002C908: nop
    
            goto L_8002C94C;
    }
    // 0x8002C908: nop

    // 0x8002C90C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002C910: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002C914: jal         0x80029C8C
    // 0x8002C918: nop

    func_80029C8C(rdram, ctx);
        goto after_17;
    // 0x8002C918: nop

    after_17:
    // 0x8002C91C: jal         0x80029ED8
    // 0x8002C920: nop

    func_80029ED8(rdram, ctx);
        goto after_18;
    // 0x8002C920: nop

    after_18:
    // 0x8002C924: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C928: sh          $zero, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = 0;
    // 0x8002C92C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002C930: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8002C934: jal         0x8002C270
    // 0x8002C938: nop

    func_8002C270(rdram, ctx);
        goto after_19;
    // 0x8002C938: nop

    after_19:
    // 0x8002C93C: jal         0x800B0E08
    // 0x8002C940: nop

    func_800B0E08(rdram, ctx);
        goto after_20;
    // 0x8002C940: nop

    after_20:
    // 0x8002C944: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002C948: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_8002C94C:
    // 0x8002C94C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C950: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002C954: lui         $at, 0xC05E
    ctx->r1 = S32(0XC05E << 16);
    // 0x8002C958: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002C95C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002C960: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002C964: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8002C968: nop

    // 0x8002C96C: bc1f        L_8002C97C
    if (!c1cs) {
        // 0x8002C970: nop
    
            goto L_8002C97C;
    }
    // 0x8002C970: nop

    // 0x8002C974: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C978: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
L_8002C97C:
    // 0x8002C97C: b           L_8002D190
    // 0x8002C980: nop

        goto L_8002D190;
    // 0x8002C980: nop

L_8002C984:
    // 0x8002C984: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002C988: lwc1        $f9, -0x1878($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1878);
    // 0x8002C98C: lwc1        $f8, -0x1874($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1874);
    // 0x8002C990: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C994: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C998: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C99C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C9A0: mul.d       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x8002C9A4: lwc1        $f6, 0x15D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002C9A8: nop

    // 0x8002C9AC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C9B0: add.d       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f10.d + ctx->f4.d;
    // 0x8002C9B4: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8002C9B8: swc1        $f8, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f8.u32l;
    // 0x8002C9BC: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8002C9C0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002C9C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C9C8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002C9CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002C9D0: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002C9D4: mul.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x8002C9D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002C9DC: lwc1        $f16, 0x1354($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x8002C9E0: nop

    // 0x8002C9E4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002C9E8: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8002C9EC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8002C9F0: swc1        $f18, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f18.u32l;
    // 0x8002C9F4: jal         0x800C25B8
    // 0x8002C9F8: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    MtxUtil_RotateY(rdram, ctx);
        goto after_21;
    // 0x8002C9F8: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    after_21:
    // 0x8002C9FC: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8002CA00: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002CA04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CA08: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002CA0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002CA10: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002CA14: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8002CA18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CA1C: lwc1        $f6, 0x12A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002CA20: nop

    // 0x8002CA24: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002CA28: sub.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f18.d - ctx->f4.d;
    // 0x8002CA2C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8002CA30: swc1        $f10, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = ctx->f10.u32l;
    // 0x8002CA34: jal         0x800C23E8
    // 0x8002CA38: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    MtxUtil_RotateX(rdram, ctx);
        goto after_22;
    // 0x8002CA38: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    after_22:
    // 0x8002CA3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CA40: lwc1        $f8, 0x3088($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3088);
    // 0x8002CA44: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002CA48: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002CA4C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002CA50: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8002CA54: addiu       $a3, $a3, -0x69E8
    ctx->r7 = ADD32(ctx->r7, -0X69E8);
    // 0x8002CA58: addiu       $a2, $a2, 0x1624
    ctx->r6 = ADD32(ctx->r6, 0X1624);
    // 0x8002CA5C: addiu       $a1, $a1, 0x1618
    ctx->r5 = ADD32(ctx->r5, 0X1618);
    // 0x8002CA60: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    // 0x8002CA64: jal         0x800C3F2C
    // 0x8002CA68: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C3F2C(rdram, ctx);
        goto after_23;
    // 0x8002CA68: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_23:
    // 0x8002CA6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CA70: lwc1        $f6, 0x30A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002CA74: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002CA78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CA7C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002CA80: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x8002CA84: nop

    // 0x8002CA88: bc1f        L_8002CAD8
    if (!c1cs) {
        // 0x8002CA8C: nop
    
            goto L_8002CAD8;
    }
    // 0x8002CA8C: nop

    // 0x8002CA90: jal         0x800B9000
    // 0x8002CA94: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800B9000(rdram, ctx);
        goto after_24;
    // 0x8002CA94: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_24:
    // 0x8002CA98: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002CA9C: lh          $t5, 0x163C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X163C);
    // 0x8002CAA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CAA4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8002CAA8: sh          $t6, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r14;
    // 0x8002CAAC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002CAB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002CAB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CAB8: swc1        $f16, 0x1650($at)
    MEM_W(0X1650, ctx->r1) = ctx->f16.u32l;
    // 0x8002CABC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002CAC0: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002CAC4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002CAC8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002CACC: addiu       $a2, $a2, 0x13C8
    ctx->r6 = ADD32(ctx->r6, 0X13C8);
    // 0x8002CAD0: jal         0x8002BD8C
    // 0x8002CAD4: addiu       $a1, $a1, 0x12A0
    ctx->r5 = ADD32(ctx->r5, 0X12A0);
    func_8002BD8C(rdram, ctx);
        goto after_25;
    // 0x8002CAD4: addiu       $a1, $a1, 0x12A0
    ctx->r5 = ADD32(ctx->r5, 0X12A0);
    after_25:
L_8002CAD8:
    // 0x8002CAD8: b           L_8002D190
    // 0x8002CADC: nop

        goto L_8002D190;
    // 0x8002CADC: nop

L_8002CAE0:
    // 0x8002CAE0: jal         0x800C4240
    // 0x8002CAE4: nop

    guRandom(rdram, ctx);
        goto after_26;
    // 0x8002CAE4: nop

    after_26:
    // 0x8002CAE8: bgez        $v0, L_8002CAFC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002CAEC: andi        $t7, $v0, 0xF
        ctx->r15 = ctx->r2 & 0XF;
            goto L_8002CAFC;
    }
    // 0x8002CAEC: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x8002CAF0: beq         $t7, $zero, L_8002CAFC
    if (ctx->r15 == 0) {
        // 0x8002CAF4: nop
    
            goto L_8002CAFC;
    }
    // 0x8002CAF4: nop

    // 0x8002CAF8: addiu       $t7, $t7, -0x10
    ctx->r15 = ADD32(ctx->r15, -0X10);
L_8002CAFC:
    // 0x8002CAFC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8002CB00: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002CB04: cvt.d.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.d = CVT_D_W(ctx->f10.u32l);
    // 0x8002CB08: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002CB0C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002CB10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CB14: sub.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f8.d - ctx->f6.d;
    // 0x8002CB18: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002CB1C: swc1        $f4, 0x7224($at)
    MEM_W(0X7224, ctx->r1) = ctx->f4.u32l;
    // 0x8002CB20: jal         0x800C4240
    // 0x8002CB24: nop

    guRandom(rdram, ctx);
        goto after_27;
    // 0x8002CB24: nop

    after_27:
    // 0x8002CB28: bgez        $v0, L_8002CB3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002CB2C: andi        $t8, $v0, 0xF
        ctx->r24 = ctx->r2 & 0XF;
            goto L_8002CB3C;
    }
    // 0x8002CB2C: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x8002CB30: beq         $t8, $zero, L_8002CB3C
    if (ctx->r24 == 0) {
        // 0x8002CB34: nop
    
            goto L_8002CB3C;
    }
    // 0x8002CB34: nop

    // 0x8002CB38: addiu       $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
L_8002CB3C:
    // 0x8002CB3C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8002CB40: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002CB44: cvt.d.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.d = CVT_D_W(ctx->f16.u32l);
    // 0x8002CB48: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002CB4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002CB50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CB54: sub.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d - ctx->f8.d;
    // 0x8002CB58: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8002CB5C: swc1        $f18, 0x7230($at)
    MEM_W(0X7230, ctx->r1) = ctx->f18.u32l;
    // 0x8002CB60: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002CB64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CB68: lwc1        $f4, 0x61C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x8002CB6C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002CB70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CB74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CB78: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CB7C: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002CB80: lwc1        $f10, 0x61C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x8002CB84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002CB88: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8002CB8C: nop

    // 0x8002CB90: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8002CB94: nop

    // 0x8002CB98: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8002CB9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CBA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CBA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CBA8: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002CBAC: lwc1        $f6, 0x61C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x8002CBB0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8002CBB4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8002CBB8: nop

    // 0x8002CBBC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8002CBC0: nop

    // 0x8002CBC4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8002CBC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CBCC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CBD0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CBD4: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002CBD8: lwc1        $f4, 0x61D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x8002CBDC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8002CBE0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8002CBE4: nop

    // 0x8002CBE8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002CBEC: nop

    // 0x8002CBF0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8002CBF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CBF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CBFC: nop

    // 0x8002CC00: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002CC04: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8002CC08: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002CC0C: jal         0x800AC0A4
    // 0x8002CC10: nop

    func_800AC0A4(rdram, ctx);
        goto after_28;
    // 0x8002CC10: nop

    after_28:
    // 0x8002CC14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC18: lwc1        $f12, 0x13C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x8002CC1C: jal         0x800C2780
    // 0x8002CC20: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_29;
    // 0x8002CC20: nop

    after_29:
    // 0x8002CC24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC28: lwc1        $f12, 0x12A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002CC2C: jal         0x800C23E8
    // 0x8002CC30: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_30;
    // 0x8002CC30: nop

    after_30:
    // 0x8002CC34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC38: lwc1        $f10, 0x1650($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1650);
    // 0x8002CC3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC40: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002CC44: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002CC48: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8002CC4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC50: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x8002CC54: swc1        $f6, 0x1650($at)
    MEM_W(0X1650, ctx->r1) = ctx->f6.u32l;
    // 0x8002CC58: bc1f        L_8002CE64
    if (!c1cs) {
        // 0x8002CC5C: nop
    
            goto L_8002CE64;
    }
    // 0x8002CC5C: nop

    // 0x8002CC60: b           L_8002CE04
    // 0x8002CC64: nop

        goto L_8002CE04;
    // 0x8002CC64: nop

    // 0x8002CC68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002CC6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002CC70: lui         $at, 0xC2A8
    ctx->r1 = S32(0XC2A8 << 16);
    // 0x8002CC74: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002CC78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CC7C: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002CC80: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002CC84: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8002CC88: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002CC8C: addiu       $t3, $t3, 0x3090
    ctx->r11 = ADD32(ctx->r11, 0X3090);
    // 0x8002CC90: lw          $a3, 0x1618($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1618);
    // 0x8002CC94: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8002CC98: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002CC9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002CCA0: jal         0x800C3D70
    // 0x8002CCA4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800C3D70(rdram, ctx);
        goto after_31;
    // 0x8002CCA4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_31:
    // 0x8002CCA8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002CCAC: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002CCB0: jal         0x8002BB04
    // 0x8002CCB4: nop

    func_8002BB04(rdram, ctx);
        goto after_32;
    // 0x8002CCB4: nop

    after_32:
    // 0x8002CCB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CCBC: lwc1        $f10, 0x15D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002CCC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CCC4: sub.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8002CCC8: swc1        $f8, 0x1648($at)
    MEM_W(0X1648, ctx->r1) = ctx->f8.u32l;
    // 0x8002CCCC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CCD0: lwc1        $f6, 0x1648($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1648);
    // 0x8002CCD4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002CCD8: lwc1        $f5, -0x1870($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1870);
    // 0x8002CCDC: lwc1        $f4, -0x186C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X186C);
    // 0x8002CCE0: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002CCE4: nop

    // 0x8002CCE8: div.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x8002CCEC: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8002CCF0: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x8002CCF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CCF8: lwc1        $f8, 0x30A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002CCFC: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002CD00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CD04: div.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002CD08: swc1        $f18, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f18.u32l;
    // 0x8002CD0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CD10: lwc1        $f4, 0x1648($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1648);
    // 0x8002CD14: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002CD18: nop

    // 0x8002CD1C: div.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8002CD20: swc1        $f10, 0x1648($at)
    MEM_W(0X1648, ctx->r1) = ctx->f10.u32l;
    // 0x8002CD24: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8002CD28: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002CD2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002CD30: jal         0x80099F90
    // 0x8002CD34: nop

    func_80099F90(rdram, ctx);
        goto after_33;
    // 0x8002CD34: nop

    after_33:
    // 0x8002CD38: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8002CD3C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CD40: lwc1        $f8, 0x61C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x8002CD44: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002CD48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CD4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CD50: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CD54: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002CD58: lwc1        $f18, 0x61C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x8002CD5C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8002CD60: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8002CD64: nop

    // 0x8002CD68: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002CD6C: nop

    // 0x8002CD70: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002CD74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CD78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CD7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CD80: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8002CD84: lwc1        $f16, 0x61C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x8002CD88: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002CD8C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8002CD90: nop

    // 0x8002CD94: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002CD98: nop

    // 0x8002CD9C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002CDA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CDA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CDA8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CDAC: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002CDB0: lwc1        $f8, 0x61D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x8002CDB4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002CDB8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8002CDBC: nop

    // 0x8002CDC0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002CDC4: nop

    // 0x8002CDC8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002CDCC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CDD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CDD4: nop

    // 0x8002CDD8: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002CDDC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8002CDE0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002CDE4: jal         0x800AC0A4
    // 0x8002CDE8: nop

    func_800AC0A4(rdram, ctx);
        goto after_34;
    // 0x8002CDE8: nop

    after_34:
    // 0x8002CDEC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002CDF0: lh          $t8, 0x163C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X163C);
    // 0x8002CDF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CDF8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002CDFC: b           L_8002CE64
    // 0x8002CE00: sh          $t9, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r25;
        goto L_8002CE64;
    // 0x8002CE00: sh          $t9, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r25;
L_8002CE04:
    // 0x8002CE04: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002CE08: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002CE0C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8002CE10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002CE14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE18: lwc1        $f18, 0x1624($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002CE1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CE20: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8002CE24: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002CE28: addiu       $t0, $t0, 0x3090
    ctx->r8 = ADD32(ctx->r8, 0X3090);
    // 0x8002CE2C: lw          $a3, 0x1618($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1618);
    // 0x8002CE30: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8002CE34: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002CE38: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8002CE3C: jal         0x800C3D70
    // 0x8002CE40: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_35;
    // 0x8002CE40: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_35:
    // 0x8002CE44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002CE48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CE4C: swc1        $f16, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f16.u32l;
    // 0x8002CE50: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002CE54: lh          $t1, 0x163C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X163C);
    // 0x8002CE58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE5C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x8002CE60: sh          $t2, 0x163C($at)
    MEM_H(0X163C, ctx->r1) = ctx->r10;
L_8002CE64:
    // 0x8002CE64: b           L_8002D190
    // 0x8002CE68: nop

        goto L_8002D190;
    // 0x8002CE68: nop

L_8002CE6C:
    // 0x8002CE6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE70: lwc1        $f12, 0x13C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x8002CE74: jal         0x800C2780
    // 0x8002CE78: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_36;
    // 0x8002CE78: nop

    after_36:
    // 0x8002CE7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE80: lwc1        $f12, 0x12A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002CE84: jal         0x800C23E8
    // 0x8002CE88: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_37;
    // 0x8002CE88: nop

    after_37:
    // 0x8002CE8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE90: lwc1        $f10, 0x1648($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1648);
    // 0x8002CE94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CE98: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002CE9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CEA0: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002CEA4: lwc1        $f18, 0x15D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002CEA8: nop

    // 0x8002CEAC: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8002CEB0: swc1        $f4, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f4.u32l;
    // 0x8002CEB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CEB8: lwc1        $f16, 0x3088($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3088);
    // 0x8002CEBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CEC0: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002CEC4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002CEC8: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8002CECC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002CED0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002CED4: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8002CED8: addiu       $a3, $a3, -0x69E8
    ctx->r7 = ADD32(ctx->r7, -0X69E8);
    // 0x8002CEDC: addiu       $a2, $a2, 0x1624
    ctx->r6 = ADD32(ctx->r6, 0X1624);
    // 0x8002CEE0: addiu       $a1, $a1, 0x1618
    ctx->r5 = ADD32(ctx->r5, 0X1618);
    // 0x8002CEE4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8002CEE8: jal         0x800C3F2C
    // 0x8002CEEC: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    func_800C3F2C(rdram, ctx);
        goto after_38;
    // 0x8002CEEC: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    after_38:
    // 0x8002CEF0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CEF4: lwc1        $f18, 0x30A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002CEF8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002CEFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002CF00: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8002CF04: c.eq.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d == ctx->f4.d;
    // 0x8002CF08: nop

    // 0x8002CF0C: bc1f        L_8002CF5C
    if (!c1cs) {
        // 0x8002CF10: nop
    
            goto L_8002CF5C;
    }
    // 0x8002CF10: nop

    // 0x8002CF14: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002CF18: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8002CF1C: jal         0x8002C270
    // 0x8002CF20: nop

    func_8002C270(rdram, ctx);
        goto after_39;
    // 0x8002CF20: nop

    after_39:
    // 0x8002CF24: jal         0x800B0E08
    // 0x8002CF28: nop

    func_800B0E08(rdram, ctx);
        goto after_40;
    // 0x8002CF28: nop

    after_40:
    // 0x8002CF2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CF30: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
    // 0x8002CF34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002CF38: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
    // 0x8002CF3C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002CF40: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002CF44: jal         0x80029C8C
    // 0x8002CF48: nop

    func_80029C8C(rdram, ctx);
        goto after_41;
    // 0x8002CF48: nop

    after_41:
    // 0x8002CF4C: jal         0x80029ED8
    // 0x8002CF50: nop

    func_80029ED8(rdram, ctx);
        goto after_42;
    // 0x8002CF50: nop

    after_42:
    // 0x8002CF54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002CF58: sh          $zero, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = 0;
L_8002CF5C:
    // 0x8002CF5C: b           L_8002D190
    // 0x8002CF60: nop

        goto L_8002D190;
    // 0x8002CF60: nop

L_8002CF64:
    // 0x8002CF64: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8002CF68: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002CF6C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8002CF70: jal         0x80099F90
    // 0x8002CF74: nop

    func_80099F90(rdram, ctx);
        goto after_43;
    // 0x8002CF74: nop

    after_43:
    // 0x8002CF78: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8002CF7C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CF80: lwc1        $f16, 0x61C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x8002CF84: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8002CF88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CF8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CF90: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CF94: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002CF98: lwc1        $f8, 0x61C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x8002CF9C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8002CFA0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8002CFA4: nop

    // 0x8002CFA8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8002CFAC: nop

    // 0x8002CFB0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002CFB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CFB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CFBC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CFC0: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002CFC4: lwc1        $f6, 0x61C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x8002CFC8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8002CFCC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8002CFD0: nop

    // 0x8002CFD4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002CFD8: nop

    // 0x8002CFDC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002CFE0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002CFE4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002CFE8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8002CFEC: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002CFF0: lwc1        $f16, 0x61D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x8002CFF4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002CFF8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8002CFFC: nop

    // 0x8002D000: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002D004: nop

    // 0x8002D008: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002D00C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002D010: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002D014: nop

    // 0x8002D018: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002D01C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8002D020: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002D024: jal         0x800AC0A4
    // 0x8002D028: nop

    func_800AC0A4(rdram, ctx);
        goto after_44;
    // 0x8002D028: nop

    after_44:
    // 0x8002D02C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D030: lwc1        $f12, 0x13C8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x8002D034: jal         0x800C2780
    // 0x8002D038: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_45;
    // 0x8002D038: nop

    after_45:
    // 0x8002D03C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D040: lwc1        $f12, 0x12A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X12A0);
    // 0x8002D044: jal         0x800C23E8
    // 0x8002D048: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_46;
    // 0x8002D048: nop

    after_46:
    // 0x8002D04C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D050: lwc1        $f8, 0x3088($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3088);
    // 0x8002D054: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002D058: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002D05C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002D060: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8002D064: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x8002D068: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D06C: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x8002D070: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002D074: swc1        $f16, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f16.u32l;
    // 0x8002D078: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002D07C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002D080: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8002D084: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8002D088: nop

    // 0x8002D08C: bc1f        L_8002D0A4
    if (!c1cs) {
        // 0x8002D090: nop
    
            goto L_8002D0A4;
    }
    // 0x8002D090: nop

    // 0x8002D094: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8002D098: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002D09C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D0A0: swc1        $f18, 0x3088($at)
    MEM_W(0X3088, ctx->r1) = ctx->f18.u32l;
L_8002D0A4:
    // 0x8002D0A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002D0A8: lh          $t7, 0x1644($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1644);
    // 0x8002D0AC: nop

    // 0x8002D0B0: beq         $t7, $zero, L_8002D100
    if (ctx->r15 == 0) {
        // 0x8002D0B4: nop
    
            goto L_8002D100;
    }
    // 0x8002D0B4: nop

    // 0x8002D0B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D0BC: lwc1        $f6, 0x1624($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x8002D0C0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002D0C4: lwc1        $f17, -0x1868($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1868);
    // 0x8002D0C8: lwc1        $f16, -0x1864($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1864);
    // 0x8002D0CC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8002D0D0: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x8002D0D4: nop

    // 0x8002D0D8: bc1f        L_8002D100
    if (!c1cs) {
        // 0x8002D0DC: nop
    
            goto L_8002D100;
    }
    // 0x8002D0DC: nop

    // 0x8002D0E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002D0E4: lh          $a0, 0x1644($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1644);
    // 0x8002D0E8: jal         0x80029C8C
    // 0x8002D0EC: nop

    func_80029C8C(rdram, ctx);
        goto after_47;
    // 0x8002D0EC: nop

    after_47:
    // 0x8002D0F0: jal         0x80029ED8
    // 0x8002D0F4: nop

    func_80029ED8(rdram, ctx);
        goto after_48;
    // 0x8002D0F4: nop

    after_48:
    // 0x8002D0F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D0FC: sh          $zero, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = 0;
L_8002D100:
    // 0x8002D100: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D104: lwc1        $f10, 0x3088($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3088);
    // 0x8002D108: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D10C: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002D110: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002D114: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002D118: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002D11C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8002D120: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8002D124: addiu       $a3, $a3, -0x69E8
    ctx->r7 = ADD32(ctx->r7, -0X69E8);
    // 0x8002D128: addiu       $a2, $a2, 0x1624
    ctx->r6 = ADD32(ctx->r6, 0X1624);
    // 0x8002D12C: addiu       $a1, $a1, 0x1618
    ctx->r5 = ADD32(ctx->r5, 0X1618);
    // 0x8002D130: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8002D134: jal         0x800C3F2C
    // 0x8002D138: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    func_800C3F2C(rdram, ctx);
        goto after_49;
    // 0x8002D138: addiu       $a0, $a0, 0x3090
    ctx->r4 = ADD32(ctx->r4, 0X3090);
    after_49:
    // 0x8002D13C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D140: lwc1        $f6, 0x30A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X30A8);
    // 0x8002D144: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002D148: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002D14C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8002D150: c.eq.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d == ctx->f16.d;
    // 0x8002D154: nop

    // 0x8002D158: bc1f        L_8002D188
    if (!c1cs) {
        // 0x8002D15C: nop
    
            goto L_8002D188;
    }
    // 0x8002D15C: nop

    // 0x8002D160: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8002D164: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x8002D168: jal         0x8002C270
    // 0x8002D16C: nop

    func_8002C270(rdram, ctx);
        goto after_50;
    // 0x8002D16C: nop

    after_50:
    // 0x8002D170: jal         0x800B0E08
    // 0x8002D174: nop

    func_800B0E08(rdram, ctx);
        goto after_51;
    // 0x8002D174: nop

    after_51:
    // 0x8002D178: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D17C: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
    // 0x8002D180: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002D184: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_8002D188:
    // 0x8002D188: b           L_8002D190
    // 0x8002D18C: nop

        goto L_8002D190;
    // 0x8002D18C: nop

L_8002D190:
    // 0x8002D190: lhu         $t8, 0xAE($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XAE);
    // 0x8002D194: nop

    // 0x8002D198: beq         $t8, $zero, L_8002D1C4
    if (ctx->r24 == 0) {
        // 0x8002D19C: nop
    
            goto L_8002D1C4;
    }
    // 0x8002D19C: nop

    // 0x8002D1A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002D1A4: lwc1        $f10, 0x15D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x8002D1A8: nop

    // 0x8002D1AC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8002D1B0: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x8002D1B4: jal         0x800C2948
    // 0x8002D1B8: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_52;
    // 0x8002D1B8: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    after_52:
    // 0x8002D1BC: jal         0x8002D200
    // 0x8002D1C0: nop

    func_8002D200(rdram, ctx);
        goto after_53;
    // 0x8002D1C0: nop

    after_53:
L_8002D1C4:
    // 0x8002D1C4: b           L_8002D1CC
    // 0x8002D1C8: nop

        goto L_8002D1CC;
    // 0x8002D1C8: nop

L_8002D1CC:
    // 0x8002D1CC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002D1D0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002D1D4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002D1D8: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002D1DC: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002D1E0: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002D1E4: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002D1E8: lwc1        $f27, 0x38($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002D1EC: lwc1        $f26, 0x3C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002D1F0: lwc1        $f29, 0x40($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002D1F4: lwc1        $f28, 0x44($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002D1F8: jr          $ra
    // 0x8002D1FC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8002D1FC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void ContPak_GetWriteFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEDE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEDEC: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEDF0: nop

    // 0x800AEDF4: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800AEDF8: beq         $t7, $zero, L_800AEE08
    if (ctx->r15 == 0) {
        // 0x800AEDFC: nop
    
            goto L_800AEE08;
    }
    // 0x800AEDFC: nop

    // 0x800AEE00: jr          $ra
    // 0x800AEE04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEE04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEE08:
    // 0x800AEE08: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEE0C: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEE10: nop

    // 0x800AEE14: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x800AEE18: beq         $t9, $zero, L_800AEE28
    if (ctx->r25 == 0) {
        // 0x800AEE1C: nop
    
            goto L_800AEE28;
    }
    // 0x800AEE1C: nop

    // 0x800AEE20: jr          $ra
    // 0x800AEE24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEE24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEE28:
    // 0x800AEE28: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEE2C: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AEE30: nop

    // 0x800AEE34: beq         $t0, $zero, L_800AEE54
    if (ctx->r8 == 0) {
        // 0x800AEE38: nop
    
            goto L_800AEE54;
    }
    // 0x800AEE38: nop

    // 0x800AEE3C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEE40: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AEE44: nop

    // 0x800AEE48: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AEE4C: jr          $ra
    // 0x800AEE50: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AEE50: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AEE54:
    // 0x800AEE54: jr          $ra
    // 0x800AEE58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AEE58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AEE5C: jr          $ra
    // 0x800AEE60: nop

    return;
    // 0x800AEE60: nop

    // 0x800AEE64: jr          $ra
    // 0x800AEE68: nop

    return;
    // 0x800AEE68: nop

;}
RECOMP_FUNC void func_800737BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800737BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800737C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800737C4: nop

    // 0x800737C8: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800737CC: nop

    // 0x800737D0: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800737D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800737D8: jr          $ra
    // 0x800737DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800737DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800737E0: jr          $ra
    // 0x800737E4: nop

    return;
    // 0x800737E4: nop

    // 0x800737E8: jr          $ra
    // 0x800737EC: nop

    return;
    // 0x800737EC: nop

;}
RECOMP_FUNC void alFxNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFBA0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800CFBA4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800CFBA8: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800CFBAC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800CFBB0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800CFBB4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800CFBB8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CFBBC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800CFBC0: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800CFBC4: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800CFBC8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800CFBCC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800CFBD0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800CFBD4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800CFBD8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800CFBDC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800CFBE0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800CFBE4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800CFBE8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800CFBEC: addiu       $a2, $a2, 0x5FC4
    ctx->r6 = ADD32(ctx->r6, 0X5FC4);
    // 0x800CFBF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFBF4: jal         0x800D56B0
    // 0x800CFBF8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800CFBF8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x800CFBFC: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x800CFC00: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CFC04: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CFC08: addiu       $t6, $t6, 0x5FDC
    ctx->r14 = ADD32(ctx->r14, 0X5FDC);
    // 0x800CFC0C: addiu       $t7, $t7, 0x5D68
    ctx->r15 = ADD32(ctx->r15, 0X5D68);
    // 0x800CFC10: sw          $t6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r14;
    // 0x800CFC14: sw          $t7, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r15;
    // 0x800CFC18: lbu         $t8, 0x1C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1C);
    // 0x800CFC1C: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC20: addiu       $s3, $s3, -0x3148
    ctx->r19 = ADD32(ctx->r19, -0X3148);
    // 0x800CFC24: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800CFC28: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x800CFC2C: beq         $at, $zero, L_800CFC8C
    if (ctx->r1 == 0) {
        // 0x800CFC30: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800CFC8C;
    }
    // 0x800CFC30: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800CFC34: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CFC38: addu        $at, $at, $t9
    gpr jr_addend_800CFC40 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800CFC3C: lw          $t9, 0x2B0($at)
    ctx->r25 = ADD32(ctx->r1, 0X2B0);
    // 0x800CFC40: jr          $t9
    // 0x800CFC44: nop

    switch (jr_addend_800CFC40 >> 2) {
        case 0: goto L_800CFC48; break;
        case 1: goto L_800CFC54; break;
        case 2: goto L_800CFC6C; break;
        case 3: goto L_800CFC78; break;
        case 4: goto L_800CFC60; break;
        case 5: goto L_800CFC84; break;
        default: switch_error(__func__, 0x800CFC40, 0x800F02B0);
    }
    // 0x800CFC44: nop

L_800CFC48:
    // 0x800CFC48: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC4C: b           L_800CFC8C
    // 0x800CFC50: addiu       $s3, $s3, -0x32B0
    ctx->r19 = ADD32(ctx->r19, -0X32B0);
        goto L_800CFC8C;
    // 0x800CFC50: addiu       $s3, $s3, -0x32B0
    ctx->r19 = ADD32(ctx->r19, -0X32B0);
L_800CFC54:
    // 0x800CFC54: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC58: b           L_800CFC8C
    // 0x800CFC5C: addiu       $s3, $s3, -0x3248
    ctx->r19 = ADD32(ctx->r19, -0X3248);
        goto L_800CFC8C;
    // 0x800CFC5C: addiu       $s3, $s3, -0x3248
    ctx->r19 = ADD32(ctx->r19, -0X3248);
L_800CFC60:
    // 0x800CFC60: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC64: b           L_800CFC8C
    // 0x800CFC68: addiu       $s3, $s3, -0x31C0
    ctx->r19 = ADD32(ctx->r19, -0X31C0);
        goto L_800CFC8C;
    // 0x800CFC68: addiu       $s3, $s3, -0x31C0
    ctx->r19 = ADD32(ctx->r19, -0X31C0);
L_800CFC6C:
    // 0x800CFC6C: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC70: b           L_800CFC8C
    // 0x800CFC74: addiu       $s3, $s3, -0x3198
    ctx->r19 = ADD32(ctx->r19, -0X3198);
        goto L_800CFC8C;
    // 0x800CFC74: addiu       $s3, $s3, -0x3198
    ctx->r19 = ADD32(ctx->r19, -0X3198);
L_800CFC78:
    // 0x800CFC78: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CFC7C: b           L_800CFC8C
    // 0x800CFC80: addiu       $s3, $s3, -0x3170
    ctx->r19 = ADD32(ctx->r19, -0X3170);
        goto L_800CFC8C;
    // 0x800CFC80: addiu       $s3, $s3, -0x3170
    ctx->r19 = ADD32(ctx->r19, -0X3170);
L_800CFC84:
    // 0x800CFC84: b           L_800CFC8C
    // 0x800CFC88: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
        goto L_800CFC8C;
    // 0x800CFC88: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
L_800CFC8C:
    // 0x800CFC8C: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800CFC90: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x800CFC94: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800CFC98: sb          $t0, 0x24($s5)
    MEM_B(0X24, ctx->r21) = ctx->r8;
    // 0x800CFC9C: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x800CFCA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFCA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFCA8: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x800CFCAC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800CFCB0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFCB4: jal         0x800C7950
    // 0x800CFCB8: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800CFCB8: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    after_1:
    // 0x800CFCBC: sw          $v0, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r2;
    // 0x800CFCC0: lw          $a3, 0x1C($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X1C);
    // 0x800CFCC4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800CFCC8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CFCCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFCD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFCD4: jal         0x800C7950
    // 0x800CFCD8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800CFCD8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x800CFCDC: lw          $t4, 0x1C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X1C);
    // 0x800CFCE0: sw          $v0, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r2;
    // 0x800CFCE4: sw          $v0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r2;
    // 0x800CFCE8: beq         $t4, $zero, L_800CFD1C
    if (ctx->r12 == 0) {
        // 0x800CFCEC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800CFD1C;
    }
    // 0x800CFCEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CFCF0: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
L_800CFCF4:
    // 0x800CFCF4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800CFCF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CFCFC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800CFD00: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x800CFD04: lw          $t9, 0x1C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1C);
    // 0x800CFD08: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x800CFD0C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800CFD10: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x800CFD14: bnel        $at, $zero, L_800CFCF4
    if (ctx->r1 != 0) {
        // 0x800CFD18: lw          $t5, 0x14($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X14);
            goto L_800CFCF4;
    }
    goto skip_0;
    // 0x800CFD18: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
    skip_0:
L_800CFD1C:
    // 0x800CFD1C: lbu         $t0, 0x24($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X24);
    // 0x800CFD20: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800CFD24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CFD28: blez        $t0, L_800CFF9C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800CFD2C: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_800CFF9C;
    }
    // 0x800CFD2C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800CFD30: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800CFD34: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800CFD38: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800CFD3C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CFD40: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800CFD44: ldc1        $f20, 0x2C8($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X2C8);
    // 0x800CFD48: addiu       $s7, $zero, 0x28
    ctx->r23 = ADD32(0, 0X28);
L_800CFD4C:
    // 0x800CFD4C: multu       $s4, $s7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CFD50: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800CFD54: lw          $t1, 0x20($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X20);
    // 0x800CFD58: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x800CFD5C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800CFD60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFD64: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x800CFD68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CFD6C: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x800CFD70: addiu       $s1, $t6, 0x1
    ctx->r17 = ADD32(ctx->r14, 0X1);
    // 0x800CFD74: mflo        $t2
    ctx->r10 = lo;
    // 0x800CFD78: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x800CFD7C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800CFD80: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800CFD84: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x800CFD88: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800CFD8C: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800CFD90: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800CFD94: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800CFD98: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x800CFD9C: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x800CFDA0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800CFDA4: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x800CFDA8: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x800CFDAC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800CFDB0: addiu       $s1, $t4, 0x1
    ctx->r17 = ADD32(ctx->r12, 0X1);
    // 0x800CFDB4: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800CFDB8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CFDBC: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x800CFDC0: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x800CFDC4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800CFDC8: addiu       $s1, $t8, 0x1
    ctx->r17 = ADD32(ctx->r24, 0X1);
    // 0x800CFDCC: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x800CFDD0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800CFDD4: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x800CFDD8: sh          $t1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r9;
    // 0x800CFDDC: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800CFDE0: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800CFDE4: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x800CFDE8: beq         $v0, $zero, L_800CFEEC
    if (ctx->r2 == 0) {
        // 0x800CFDEC: addiu       $s1, $t0, 0x2
        ctx->r17 = ADD32(ctx->r8, 0X2);
            goto L_800CFEEC;
    }
    // 0x800CFDEC: addiu       $s1, $t0, 0x2
    ctx->r17 = ADD32(ctx->r8, 0X2);
    // 0x800CFDF0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800CFDF4: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x800CFDF8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800CFDFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CFE00: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x800CFE04: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800CFE08: addiu       $s1, $t2, 0x1
    ctx->r17 = ADD32(ctx->r10, 0X1);
    // 0x800CFE0C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800CFE10: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x800CFE14: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800CFE18: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800CFE1C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800CFE20: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x800CFE24: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800CFE28: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800CFE2C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800CFE30: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800CFE34: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800CFE38: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x800CFE3C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x800CFE40: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x800CFE44: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800CFE48: bgez        $t0, L_800CFE60
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800CFE4C: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_800CFE60;
    }
    // 0x800CFE4C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800CFE50: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800CFE54: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CFE58: nop

    // 0x800CFE5C: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_800CFE60:
    // 0x800CFE60: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800CFE64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFE68: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x800CFE6C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800CFE70: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x800CFE74: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800CFE78: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CFE7C: addiu       $t5, $zero, 0x34
    ctx->r13 = ADD32(0, 0X34);
    // 0x800CFE80: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800CFE84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFE88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFE8C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFE90: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800CFE94: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800CFE98: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x800CFE9C: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800CFEA0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800CFEA4: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x800CFEA8: jal         0x800C7950
    // 0x800CFEAC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800CFEAC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x800CFEB0: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800CFEB4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800CFEB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CFEBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFEC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFEC4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFEC8: jal         0x800C7950
    // 0x800CFECC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x800CFECC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_4:
    // 0x800CFED0: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800CFED4: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x800CFED8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800CFEDC: swc1        $f26, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f26.u32l;
    // 0x800CFEE0: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800CFEE4: b           L_800CFEF8
    // 0x800CFEE8: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
        goto L_800CFEF8;
    // 0x800CFEE8: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
L_800CFEEC:
    // 0x800CFEEC: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x800CFEF0: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x800CFEF4: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
L_800CFEF8:
    // 0x800CFEF8: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x800CFEFC: addu        $s2, $s3, $t2
    ctx->r18 = ADD32(ctx->r19, ctx->r10);
    // 0x800CFF00: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800CFF04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFF08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFF0C: beq         $t3, $zero, L_800CFF74
    if (ctx->r11 == 0) {
        // 0x800CFF10: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_800CFF74;
    }
    // 0x800CFF10: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFF14: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x800CFF18: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800CFF1C: jal         0x800C7950
    // 0x800CFF20: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x800CFF20: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_5:
    // 0x800CFF24: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800CFF28: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800CFF2C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800CFF30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFF34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CFF38: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CFF3C: jal         0x800C7950
    // 0x800CFF40: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x800CFF40: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_6:
    // 0x800CFF44: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800CFF48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFF4C: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x800CFF50: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x800CFF54: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x800CFF58: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800CFF5C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800CFF60: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800CFF64: jal         0x800CFB00
    // 0x800CFF68: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    _init_lpfilter(rdram, ctx);
        goto after_7;
    // 0x800CFF68: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
    // 0x800CFF6C: b           L_800CFF88
    // 0x800CFF70: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
        goto L_800CFF88;
    // 0x800CFF70: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_800CFF74:
    // 0x800CFF74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFF78: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x800CFF7C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800CFF80: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800CFF84: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_800CFF88:
    // 0x800CFF88: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800CFF8C: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x800CFF90: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800CFF94: bne         $at, $zero, L_800CFD4C
    if (ctx->r1 != 0) {
        // 0x800CFF98: or          $s4, $t1, $zero
        ctx->r20 = ctx->r9 | 0;
            goto L_800CFD4C;
    }
    // 0x800CFF98: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
L_800CFF9C:
    // 0x800CFF9C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800CFFA0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800CFFA4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800CFFA8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800CFFAC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800CFFB0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800CFFB4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800CFFB8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800CFFBC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800CFFC0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800CFFC4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800CFFC8: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800CFFCC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800CFFD0: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800CFFD4: jr          $ra
    // 0x800CFFD8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800CFFD8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80068438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068438: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006843C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068440: nop

    // 0x80068444: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80068448: nop

    // 0x8006844C: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80068450: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068454: jr          $ra
    // 0x80068458: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068458: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006845C: jr          $ra
    // 0x80068460: nop

    return;
    // 0x80068460: nop

    // 0x80068464: jr          $ra
    // 0x80068468: nop

    return;
    // 0x80068468: nop

;}
RECOMP_FUNC void func_80072904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072904: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072908: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007290C: nop

    // 0x80072910: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80072914: nop

    // 0x80072918: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x8007291C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072920: jr          $ra
    // 0x80072924: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072924: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072928: jr          $ra
    // 0x8007292C: nop

    return;
    // 0x8007292C: nop

    // 0x80072930: jr          $ra
    // 0x80072934: nop

    return;
    // 0x80072934: nop

;}
RECOMP_FUNC void func_80076220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076220: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076224: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076228: nop

    // 0x8007622C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076230: nop

    // 0x80076234: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80076238: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007623C: jr          $ra
    // 0x80076240: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076240: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076244: jr          $ra
    // 0x80076248: nop

    return;
    // 0x80076248: nop

    // 0x8007624C: jr          $ra
    // 0x80076250: nop

    return;
    // 0x80076250: nop

;}
RECOMP_FUNC void func_80079404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079404: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079408: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007940C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80079410: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80079414: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80079418: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007941C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80079420: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x80079424: jal         0x8007959C
    // 0x80079428: nop

    func_8007959C(rdram, ctx);
        goto after_0;
    // 0x80079428: nop

    after_0:
    // 0x8007942C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80079430: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80079434: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80079438: nop

    // 0x8007943C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80079440: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80079444: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80079448: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8007944C: nop

    // 0x80079450: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x80079454: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80079458: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007945C: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80079460: nop

    // 0x80079464: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x80079468: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8007946C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80079470: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80079474: nop

    // 0x80079478: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
    // 0x8007947C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80079480: nop

    // 0x80079484: addiu       $t5, $t4, 0x20
    ctx->r13 = ADD32(ctx->r12, 0X20);
    // 0x80079488: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8007948C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80079490: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80079494: blez        $t6, L_80079564
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80079498: nop
    
            goto L_80079564;
    }
    // 0x80079498: nop

L_8007949C:
    // 0x8007949C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800794A0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800794A4: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800794A8: nop

    // 0x800794AC: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800794B0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800794B4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800794B8: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x800794BC: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x800794C0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800794C4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800794C8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800794CC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800794D0: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800794D4: nop

    // 0x800794D8: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x800794DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800794E0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800794E4: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800794E8: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800794EC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800794F0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800794F4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800794F8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800794FC: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80079500: nop

    // 0x80079504: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80079508: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8007950C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80079510: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80079514: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80079518: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8007951C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80079520: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80079524: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80079528: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8007952C: nop

    // 0x80079530: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80079534: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80079538: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8007953C: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80079540: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80079544: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80079548: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8007954C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80079550: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80079554: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80079558: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007955C: bne         $at, $zero, L_8007949C
    if (ctx->r1 != 0) {
        // 0x80079560: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_8007949C;
    }
    // 0x80079560: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
L_80079564:
    // 0x80079564: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80079568: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8007956C: nop

    // 0x80079570: sw          $t4, 0xA0($t5)
    MEM_W(0XA0, ctx->r13) = ctx->r12;
    // 0x80079574: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80079578: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007957C: nop

    // 0x80079580: sw          $t6, 0xA4($t7)
    MEM_W(0XA4, ctx->r15) = ctx->r14;
    // 0x80079584: b           L_8007958C
    // 0x80079588: nop

        goto L_8007958C;
    // 0x80079588: nop

L_8007958C:
    // 0x8007958C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079590: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80079594: jr          $ra
    // 0x80079598: nop

    return;
    // 0x80079598: nop

;}
RECOMP_FUNC void func_800630E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800630E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800630E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800630E8: jal         0x80061488
    // 0x800630EC: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800630EC: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_0:
    // 0x800630F0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800630F4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800630F8: b           L_80063108
    // 0x800630FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063108;
    // 0x800630FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063100: b           L_80063108
    // 0x80063104: nop

        goto L_80063108;
    // 0x80063104: nop

L_80063108:
    // 0x80063108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006310C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063110: jr          $ra
    // 0x80063114: nop

    return;
    // 0x80063114: nop

;}
RECOMP_FUNC void func_8002ED14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ED14: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002ED18: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002ED1C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002ED20: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002ED24: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8002ED28: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002ED2C: lh          $t6, -0x6558($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6558);
    // 0x8002ED30: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8002ED34: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002ED38: lw          $t7, -0x73D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73D0);
    // 0x8002ED3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002ED40: swc1        $f6, 0x230($t7)
    MEM_W(0X230, ctx->r15) = ctx->f6.u32l;
    // 0x8002ED44: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8002ED48: lh          $t8, -0x6558($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6558);
    // 0x8002ED4C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002ED50: addiu       $t9, $t8, -0x50
    ctx->r25 = ADD32(ctx->r24, -0X50);
    // 0x8002ED54: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8002ED58: lw          $t0, 0x1688($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1688);
    // 0x8002ED5C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002ED60: swc1        $f10, 0x230($t0)
    MEM_W(0X230, ctx->r8) = ctx->f10.u32l;
    // 0x8002ED64: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8002ED68: lh          $t1, -0x6558($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6558);
    // 0x8002ED6C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002ED70: addiu       $t2, $t1, -0x4A
    ctx->r10 = ADD32(ctx->r9, -0X4A);
    // 0x8002ED74: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8002ED78: lw          $t3, 0x24D8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X24D8);
    // 0x8002ED7C: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002ED80: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002ED84: swc1        $f20, 0x230($t3)
    MEM_W(0X230, ctx->r11) = ctx->f20.u32l;
    // 0x8002ED88: lw          $t4, 0x24D8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X24D8);
    // 0x8002ED8C: nop

    // 0x8002ED90: swc1        $f20, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f20.u32l;
    // 0x8002ED94: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8002ED98: lh          $t5, -0x6558($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X6558);
    // 0x8002ED9C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002EDA0: addiu       $t6, $t5, -0x53
    ctx->r14 = ADD32(ctx->r13, -0X53);
    // 0x8002EDA4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8002EDA8: lw          $t7, 0x29BC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X29BC);
    // 0x8002EDAC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002EDB0: swc1        $f4, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f4.u32l;
    // 0x8002EDB4: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8002EDB8: lh          $t8, -0x6558($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6558);
    // 0x8002EDBC: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002EDC0: addiu       $t9, $t8, -0x5F
    ctx->r25 = ADD32(ctx->r24, -0X5F);
    // 0x8002EDC4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8002EDC8: lw          $t0, 0x49C4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X49C4);
    // 0x8002EDCC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002EDD0: swc1        $f8, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f8.u32l;
    // 0x8002EDD4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002EDD8: lh          $t1, 0x2518($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2518);
    // 0x8002EDDC: nop

    // 0x8002EDE0: slti        $at, $t1, 0x28
    ctx->r1 = SIGNED(ctx->r9) < 0X28 ? 1 : 0;
    // 0x8002EDE4: beq         $at, $zero, L_8002EE00
    if (ctx->r1 == 0) {
        // 0x8002EDE8: nop
    
            goto L_8002EE00;
    }
    // 0x8002EDE8: nop

    // 0x8002EDEC: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8002EDF0: lh          $t2, -0x6558($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X6558);
    // 0x8002EDF4: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8002EDF8: bne         $t2, $at, L_8002EE08
    if (ctx->r10 != ctx->r1) {
        // 0x8002EDFC: nop
    
            goto L_8002EE08;
    }
    // 0x8002EDFC: nop

L_8002EE00:
    // 0x8002EE00: b           L_8002F5AC
    // 0x8002EE04: nop

        goto L_8002F5AC;
    // 0x8002EE04: nop

L_8002EE08:
    // 0x8002EE08: jal         0x800C1754
    // 0x8002EE0C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8002EE0C: nop

    after_0:
    // 0x8002EE10: jal         0x800A7160
    // 0x8002EE14: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800A7160(rdram, ctx);
        goto after_1;
    // 0x8002EE14: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // 0x8002EE18: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002EE1C: addiu       $t3, $t3, 0x7340
    ctx->r11 = ADD32(ctx->r11, 0X7340);
    // 0x8002EE20: lwc1        $f12, 0xD50($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XD50);
    // 0x8002EE24: jal         0x800C2780
    // 0x8002EE28: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8002EE28: nop

    after_2:
    // 0x8002EE2C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002EE30: addiu       $t4, $t4, 0x7340
    ctx->r12 = ADD32(ctx->r12, 0X7340);
    // 0x8002EE34: lwc1        $f12, 0xD4C($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XD4C);
    // 0x8002EE38: jal         0x800C25B8
    // 0x8002EE3C: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x8002EE3C: nop

    after_3:
    // 0x8002EE40: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002EE44: addiu       $t5, $t5, 0x7340
    ctx->r13 = ADD32(ctx->r13, 0X7340);
    // 0x8002EE48: lwc1        $f12, 0xD48($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XD48);
    // 0x8002EE4C: jal         0x800C23E8
    // 0x8002EE50: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x8002EE50: nop

    after_4:
    // 0x8002EE54: jal         0x800A72BC
    // 0x8002EE58: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800A72BC(rdram, ctx);
        goto after_5;
    // 0x8002EE58: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_5:
    // 0x8002EE5C: jal         0x800C1850
    // 0x8002EE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_6;
    // 0x8002EE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8002EE64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EE68: lw          $a0, 0x1688($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1688);
    // 0x8002EE6C: jal         0x8009A14C
    // 0x8002EE70: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    func_8009A14C(rdram, ctx);
        goto after_7;
    // 0x8002EE70: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    after_7:
    // 0x8002EE74: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002EE78: lw          $a0, 0x1688($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1688);
    // 0x8002EE7C: jal         0x800997D8
    // 0x8002EE80: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    func_800997D8(rdram, ctx);
        goto after_8;
    // 0x8002EE80: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    after_8:
    // 0x8002EE84: jal         0x800C1850
    // 0x8002EE88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_9;
    // 0x8002EE88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8002EE8C: jal         0x8002EAF0
    // 0x8002EE90: nop

    func_8002EAF0(rdram, ctx);
        goto after_10;
    // 0x8002EE90: nop

    after_10:
    // 0x8002EE94: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8002EE98: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8002EE9C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002EEA0: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002EEA4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002EEA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002EEAC: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x8002EEB0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002EEB4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8002EEB8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8002EEBC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002EEC0: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x8002EEC4: lh          $t6, -0x6558($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6558);
    // 0x8002EEC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002EECC: lwc1        $f16, 0x7230($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x8002EED0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8002EED4: lui         $at, 0xC054
    ctx->r1 = S32(0XC054 << 16);
    // 0x8002EED8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002EEDC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002EEE0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x8002EEE4: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8002EEE8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8002EEEC: lw          $a2, 0x7218($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7218);
    // 0x8002EEF0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002EEF4: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x8002EEF8: add.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f4.d + ctx->f10.d;
    // 0x8002EEFC: jal         0x800C2304
    // 0x8002EF00: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_11;
    // 0x8002EF00: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    after_11:
    // 0x8002EF04: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8002EF08: sh          $t7, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r15;
    // 0x8002EF0C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002EF10: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002EF14: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002EF18: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EF1C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8002EF20: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8002EF24: nop

    // 0x8002EF28: bc1f        L_8002EF40
    if (!c1cs) {
        // 0x8002EF2C: nop
    
            goto L_8002EF40;
    }
    // 0x8002EF2C: nop

    // 0x8002EF30: lhu         $t8, 0x46($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X46);
    // 0x8002EF34: nop

    // 0x8002EF38: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8002EF3C: sh          $t9, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r25;
L_8002EF40:
    // 0x8002EF40: lhu         $t0, 0x46($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X46);
    // 0x8002EF44: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8002EF48: blez        $t0, L_8002F13C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8002EF4C: nop
    
            goto L_8002F13C;
    }
    // 0x8002EF4C: nop

L_8002EF50:
    // 0x8002EF50: lh          $t1, 0x62($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X62);
    // 0x8002EF54: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8002EF58: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002EF5C: lbu         $t2, -0x6500($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X6500);
    // 0x8002EF60: nop

    // 0x8002EF64: beq         $t2, $zero, L_8002F108
    if (ctx->r10 == 0) {
        // 0x8002EF68: sh          $t2, 0x5E($sp)
        MEM_H(0X5E, ctx->r29) = ctx->r10;
            goto L_8002F108;
    }
    // 0x8002EF68: sh          $t2, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r10;
    // 0x8002EF6C: lh          $t3, 0x62($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X62);
    // 0x8002EF70: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002EF74: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8002EF78: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8002EF7C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8002EF80: lw          $t5, 0x1694($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1694);
    // 0x8002EF84: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8002EF88: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8002EF8C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8002EF90: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8002EF94: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
L_8002EF98:
    // 0x8002EF98: lh          $t7, 0x60($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X60);
    // 0x8002EF9C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002EFA0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002EFA4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002EFA8: lh          $t9, 0x2590($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2590);
    // 0x8002EFAC: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x8002EFB0: nop

    // 0x8002EFB4: bne         $t9, $t0, L_8002EFE8
    if (ctx->r25 != ctx->r8) {
        // 0x8002EFB8: nop
    
            goto L_8002EFE8;
    }
    // 0x8002EFB8: nop

    // 0x8002EFBC: lh          $t1, 0x60($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X60);
    // 0x8002EFC0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002EFC4: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8002EFC8: lw          $t3, 0x7B54($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B54);
    // 0x8002EFCC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002EFD0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8002EFD4: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8002EFD8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8002EFDC: sw          $t4, 0x128($t5)
    MEM_W(0X128, ctx->r13) = ctx->r12;
    // 0x8002EFE0: b           L_8002F008
    // 0x8002EFE4: nop

        goto L_8002F008;
    // 0x8002EFE4: nop

L_8002EFE8:
    // 0x8002EFE8: lh          $t6, 0x60($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X60);
    // 0x8002EFEC: nop

    // 0x8002EFF0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002EFF4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8002EFF8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002EFFC: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8002F000: bne         $at, $zero, L_8002EF98
    if (ctx->r1 != 0) {
        // 0x8002F004: sh          $t7, 0x60($sp)
        MEM_H(0X60, ctx->r29) = ctx->r15;
            goto L_8002EF98;
    }
    // 0x8002F004: sh          $t7, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r15;
L_8002F008:
    // 0x8002F008: lh          $t0, 0x60($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X60);
    // 0x8002F00C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002F010: bne         $t0, $at, L_8002F0FC
    if (ctx->r8 != ctx->r1) {
        // 0x8002F014: nop
    
            goto L_8002F0FC;
    }
    // 0x8002F014: nop

    // 0x8002F018: jal         0x8002A028
    // 0x8002F01C: nop

    func_8002A028(rdram, ctx);
        goto after_12;
    // 0x8002F01C: nop

    after_12:
    // 0x8002F020: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002F024: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002F028: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8002F02C: lh          $t2, 0x5E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5E);
    // 0x8002F030: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x8002F034: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F038: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8002F03C: sh          $s0, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r16;
    // 0x8002F040: sh          $t2, 0x2590($at)
    MEM_H(0X2590, ctx->r1) = ctx->r10;
    // 0x8002F044: lh          $t4, 0x5C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X5C);
    // 0x8002F048: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002F04C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8002F050: lw          $t6, 0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B54);
    // 0x8002F054: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8002F058: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8002F05C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8002F060: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8002F064: sw          $t7, 0x128($t8)
    MEM_W(0X128, ctx->r24) = ctx->r15;
    // 0x8002F068: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8002F06C: addiu       $t9, $t9, 0x5B0
    ctx->r25 = ADD32(ctx->r25, 0X5B0);
    // 0x8002F070: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8002F074: lh          $t0, 0x5E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X5E);
    // 0x8002F078: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8002F07C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002F080: lbu         $t1, -0x46F1($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X46F1);
    // 0x8002F084: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F088: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002F08C: lui         $t3, 0x809B
    ctx->r11 = S32(0X809B << 16);
    // 0x8002F090: addiu       $t3, $t3, 0x3C30
    ctx->r11 = ADD32(ctx->r11, 0X3C30);
    // 0x8002F094: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002F098: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002F09C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8002F0A0: jal         0x800BD1FC
    // 0x8002F0A4: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_13;
    // 0x8002F0A4: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    after_13:
    // 0x8002F0A8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8002F0AC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F0B0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8002F0B4: jal         0x800BD218
    // 0x8002F0B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_14;
    // 0x8002F0B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_14:
    // 0x8002F0BC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8002F0C0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F0C4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8002F0C8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8002F0CC: lui         $t6, 0x809B
    ctx->r14 = S32(0X809B << 16);
    // 0x8002F0D0: addiu       $t6, $t6, 0x1E10
    ctx->r14 = ADD32(ctx->r14, 0X1E10);
    // 0x8002F0D4: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x8002F0D8: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x8002F0DC: jal         0x800BD1FC
    // 0x8002F0E0: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_15;
    // 0x8002F0E0: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    after_15:
    // 0x8002F0E4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8002F0E8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8002F0EC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F0F0: lw          $a2, 0x128($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X128);
    // 0x8002F0F4: jal         0x800BF0B4
    // 0x8002F0F8: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    Spi_DecompressAsset(rdram, ctx);
        goto after_16;
    // 0x8002F0F8: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    after_16:
L_8002F0FC:
    // 0x8002F0FC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F100: jal         0x800997D8
    // 0x8002F104: nop

    func_800997D8(rdram, ctx);
        goto after_17;
    // 0x8002F104: nop

    after_17:
L_8002F108:
    // 0x8002F108: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002F10C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002F110: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002F114: jal         0x800C2304
    // 0x8002F118: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_18;
    // 0x8002F118: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_18:
    // 0x8002F11C: lh          $t8, 0x62($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X62);
    // 0x8002F120: lhu         $t2, 0x46($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X46);
    // 0x8002F124: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002F128: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x8002F12C: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002F130: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002F134: bne         $at, $zero, L_8002EF50
    if (ctx->r1 != 0) {
        // 0x8002F138: sh          $t9, 0x62($sp)
        MEM_H(0X62, ctx->r29) = ctx->r25;
            goto L_8002EF50;
    }
    // 0x8002F138: sh          $t9, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r25;
L_8002F13C:
    // 0x8002F13C: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x8002F140: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8002F144: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F148: lwc1        $f4, -0x7820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002F14C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002F150: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002F154: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002F158: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8002F15C: nop

    // 0x8002F160: bc1f        L_8002F1A0
    if (!c1cs) {
        // 0x8002F164: nop
    
            goto L_8002F1A0;
    }
    // 0x8002F164: nop

    // 0x8002F168: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002F16C: lh          $t3, 0x2588($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2588);
    // 0x8002F170: nop

    // 0x8002F174: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8002F178: bne         $t4, $zero, L_8002F1A0
    if (ctx->r12 != 0) {
        // 0x8002F17C: nop
    
            goto L_8002F1A0;
    }
    // 0x8002F17C: nop

    // 0x8002F180: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002F184: lh          $t5, 0x2588($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2588);
    // 0x8002F188: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F18C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8002F190: sh          $t6, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r14;
    // 0x8002F194: addiu       $t7, $zero, 0x141
    ctx->r15 = ADD32(0, 0X141);
    // 0x8002F198: b           L_8002F210
    // 0x8002F19C: sh          $t7, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r15;
        goto L_8002F210;
    // 0x8002F19C: sh          $t7, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r15;
L_8002F1A0:
    // 0x8002F1A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F1A4: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002F1A8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002F1AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002F1B0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8002F1B4: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8002F1B8: nop

    // 0x8002F1BC: bc1f        L_8002F210
    if (!c1cs) {
        // 0x8002F1C0: nop
    
            goto L_8002F210;
    }
    // 0x8002F1C0: nop

    // 0x8002F1C4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002F1C8: lh          $t8, 0x2588($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2588);
    // 0x8002F1CC: nop

    // 0x8002F1D0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8002F1D4: beq         $t9, $zero, L_8002F210
    if (ctx->r25 == 0) {
        // 0x8002F1D8: nop
    
            goto L_8002F210;
    }
    // 0x8002F1D8: nop

    // 0x8002F1DC: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x8002F1E0: bne         $t0, $zero, L_8002F210
    if (ctx->r8 != 0) {
        // 0x8002F1E4: nop
    
            goto L_8002F210;
    }
    // 0x8002F1E4: nop

    // 0x8002F1E8: andi        $t1, $t8, 0x2
    ctx->r9 = ctx->r24 & 0X2;
    // 0x8002F1EC: bne         $t1, $zero, L_8002F210
    if (ctx->r9 != 0) {
        // 0x8002F1F0: nop
    
            goto L_8002F210;
    }
    // 0x8002F1F0: nop

    // 0x8002F1F4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002F1F8: lh          $t2, 0x2588($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2588);
    // 0x8002F1FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F200: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8002F204: sh          $t3, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r11;
    // 0x8002F208: addiu       $t4, $zero, 0x142
    ctx->r12 = ADD32(0, 0X142);
    // 0x8002F20C: sh          $t4, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r12;
L_8002F210:
    // 0x8002F210: lh          $t5, 0x60($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X60);
    // 0x8002F214: nop

    // 0x8002F218: beq         $t5, $zero, L_8002F270
    if (ctx->r13 == 0) {
        // 0x8002F21C: nop
    
            goto L_8002F270;
    }
    // 0x8002F21C: nop

    // 0x8002F220: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8002F224: lh          $t7, -0x6558($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6558);
    // 0x8002F228: lh          $a2, 0x60($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X60);
    // 0x8002F22C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8002F230: addiu       $t9, $t7, -0x4A
    ctx->r25 = ADD32(ctx->r15, -0X4A);
    // 0x8002F234: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8002F238: or          $t6, $a2, $at
    ctx->r14 = ctx->r6 | ctx->r1;
    // 0x8002F23C: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x8002F240: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002F244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002F248: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F24C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002F250: lw          $a1, 0x24F8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X24F8);
    // 0x8002F254: lw          $a0, 0x24D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D8);
    // 0x8002F258: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8002F25C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8002F260: addiu       $a3, $zero, 0x41
    ctx->r7 = ADD32(0, 0X41);
    // 0x8002F264: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8002F268: jal         0x800B1F0C
    // 0x8002F26C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_19;
    // 0x8002F26C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_19:
L_8002F270:
    // 0x8002F270: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002F274: lh          $t0, 0x2588($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X2588);
    // 0x8002F278: nop

    // 0x8002F27C: andi        $t8, $t0, 0x1
    ctx->r24 = ctx->r8 & 0X1;
    // 0x8002F280: beq         $t8, $zero, L_8002F2E8
    if (ctx->r24 == 0) {
        // 0x8002F284: nop
    
            goto L_8002F2E8;
    }
    // 0x8002F284: nop

    // 0x8002F288: jal         0x800C1850
    // 0x8002F28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_20;
    // 0x8002F28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x8002F290: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F294: lw          $a0, 0x24D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D8);
    // 0x8002F298: jal         0x8009A14C
    // 0x8002F29C: nop

    func_8009A14C(rdram, ctx);
        goto after_21;
    // 0x8002F29C: nop

    after_21:
    // 0x8002F2A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F2A4: lw          $a0, 0x24D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D8);
    // 0x8002F2A8: jal         0x800997D8
    // 0x8002F2AC: nop

    func_800997D8(rdram, ctx);
        goto after_22;
    // 0x8002F2AC: nop

    after_22:
    // 0x8002F2B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F2B4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8002F2B8: lw          $a1, 0x24F8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X24F8);
    // 0x8002F2BC: lw          $a0, 0x24D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24D8);
    // 0x8002F2C0: jal         0x800B26E0
    // 0x8002F2C4: nop

    func_800B26E0(rdram, ctx);
        goto after_23;
    // 0x8002F2C4: nop

    after_23:
    // 0x8002F2C8: bgez        $v0, L_8002F2E8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002F2CC: nop
    
            goto L_8002F2E8;
    }
    // 0x8002F2CC: nop

    // 0x8002F2D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002F2D4: lh          $t1, 0x2588($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2588);
    // 0x8002F2D8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002F2DC: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8002F2E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F2E4: sh          $t2, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r10;
L_8002F2E8:
    // 0x8002F2E8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002F2EC: lw          $t3, 0x24D8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X24D8);
    // 0x8002F2F0: nop

    // 0x8002F2F4: addiu       $t4, $t3, 0x160
    ctx->r12 = ADD32(ctx->r11, 0X160);
    // 0x8002F2F8: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x8002F2FC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002F300: lw          $t5, 0x24F8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X24F8);
    // 0x8002F304: nop

    // 0x8002F308: addiu       $t6, $t5, 0x40
    ctx->r14 = ADD32(ctx->r13, 0X40);
    // 0x8002F30C: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8002F310: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F314: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002F318: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002F31C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002F320: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8002F324: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8002F328: nop

    // 0x8002F32C: bc1f        L_8002F36C
    if (!c1cs) {
        // 0x8002F330: nop
    
            goto L_8002F36C;
    }
    // 0x8002F330: nop

    // 0x8002F334: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002F338: lh          $t7, 0x2588($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2588);
    // 0x8002F33C: nop

    // 0x8002F340: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x8002F344: bne         $t9, $zero, L_8002F36C
    if (ctx->r25 != 0) {
        // 0x8002F348: nop
    
            goto L_8002F36C;
    }
    // 0x8002F348: nop

    // 0x8002F34C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002F350: lh          $t0, 0x2588($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X2588);
    // 0x8002F354: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F358: ori         $t8, $t0, 0x8
    ctx->r24 = ctx->r8 | 0X8;
    // 0x8002F35C: sh          $t8, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r24;
    // 0x8002F360: addiu       $t1, $zero, 0x13F
    ctx->r9 = ADD32(0, 0X13F);
    // 0x8002F364: b           L_8002F3DC
    // 0x8002F368: sh          $t1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r9;
        goto L_8002F3DC;
    // 0x8002F368: sh          $t1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r9;
L_8002F36C:
    // 0x8002F36C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002F370: lwc1        $f4, -0x7820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002F374: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002F378: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002F37C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002F380: c.eq.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d == ctx->f16.d;
    // 0x8002F384: nop

    // 0x8002F388: bc1f        L_8002F3DC
    if (!c1cs) {
        // 0x8002F38C: nop
    
            goto L_8002F3DC;
    }
    // 0x8002F38C: nop

    // 0x8002F390: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002F394: lh          $t2, 0x2588($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2588);
    // 0x8002F398: nop

    // 0x8002F39C: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8002F3A0: beq         $t3, $zero, L_8002F3DC
    if (ctx->r11 == 0) {
        // 0x8002F3A4: nop
    
            goto L_8002F3DC;
    }
    // 0x8002F3A4: nop

    // 0x8002F3A8: andi        $t4, $t2, 0x20
    ctx->r12 = ctx->r10 & 0X20;
    // 0x8002F3AC: bne         $t4, $zero, L_8002F3DC
    if (ctx->r12 != 0) {
        // 0x8002F3B0: nop
    
            goto L_8002F3DC;
    }
    // 0x8002F3B0: nop

    // 0x8002F3B4: andi        $t5, $t2, 0x10
    ctx->r13 = ctx->r10 & 0X10;
    // 0x8002F3B8: bne         $t5, $zero, L_8002F3DC
    if (ctx->r13 != 0) {
        // 0x8002F3BC: nop
    
            goto L_8002F3DC;
    }
    // 0x8002F3BC: nop

    // 0x8002F3C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002F3C4: lh          $t6, 0x2588($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2588);
    // 0x8002F3C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F3CC: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8002F3D0: sh          $t7, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r15;
    // 0x8002F3D4: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x8002F3D8: sh          $t9, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r25;
L_8002F3DC:
    // 0x8002F3DC: lh          $t0, 0x62($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X62);
    // 0x8002F3E0: nop

    // 0x8002F3E4: beq         $t0, $zero, L_8002F434
    if (ctx->r8 == 0) {
        // 0x8002F3E8: nop
    
            goto L_8002F434;
    }
    // 0x8002F3E8: nop

    // 0x8002F3EC: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8002F3F0: lh          $t1, -0x6558($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X6558);
    // 0x8002F3F4: lh          $a2, 0x62($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X62);
    // 0x8002F3F8: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8002F3FC: addiu       $t3, $t1, -0x4A
    ctx->r11 = ADD32(ctx->r9, -0X4A);
    // 0x8002F400: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8002F404: or          $t8, $a2, $at
    ctx->r24 = ctx->r6 | ctx->r1;
    // 0x8002F408: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x8002F40C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002F410: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002F414: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F418: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8002F41C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8002F420: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002F424: addiu       $a3, $zero, 0x41
    ctx->r7 = ADD32(0, 0X41);
    // 0x8002F428: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8002F42C: jal         0x800B1F0C
    // 0x8002F430: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_24;
    // 0x8002F430: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_24:
L_8002F434:
    // 0x8002F434: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002F438: lh          $t4, 0x2588($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2588);
    // 0x8002F43C: nop

    // 0x8002F440: andi        $t2, $t4, 0x8
    ctx->r10 = ctx->r12 & 0X8;
    // 0x8002F444: beq         $t2, $zero, L_8002F49C
    if (ctx->r10 == 0) {
        // 0x8002F448: nop
    
            goto L_8002F49C;
    }
    // 0x8002F448: nop

    // 0x8002F44C: jal         0x800C1850
    // 0x8002F450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_25;
    // 0x8002F450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x8002F454: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F458: jal         0x8009A14C
    // 0x8002F45C: nop

    func_8009A14C(rdram, ctx);
        goto after_26;
    // 0x8002F45C: nop

    after_26:
    // 0x8002F460: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F464: jal         0x800997D8
    // 0x8002F468: nop

    func_800997D8(rdram, ctx);
        goto after_27;
    // 0x8002F468: nop

    after_27:
    // 0x8002F46C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8002F470: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8002F474: jal         0x800B26E0
    // 0x8002F478: nop

    func_800B26E0(rdram, ctx);
        goto after_28;
    // 0x8002F478: nop

    after_28:
    // 0x8002F47C: bgez        $v0, L_8002F49C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002F480: nop
    
            goto L_8002F49C;
    }
    // 0x8002F480: nop

    // 0x8002F484: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002F488: lh          $t5, 0x2588($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2588);
    // 0x8002F48C: addiu       $at, $zero, -0x19
    ctx->r1 = ADD32(0, -0X19);
    // 0x8002F490: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8002F494: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F498: sh          $t6, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r14;
L_8002F49C:
    // 0x8002F49C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002F4A0: lw          $t7, 0x70E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E8);
    // 0x8002F4A4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8002F4A8: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x8002F4AC: sltu        $at, $t7, $at
    ctx->r1 = ctx->r15 < ctx->r1 ? 1 : 0;
    // 0x8002F4B0: bne         $at, $zero, L_8002F4C4
    if (ctx->r1 != 0) {
        // 0x8002F4B4: sw          $t7, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r15;
            goto L_8002F4C4;
    }
    // 0x8002F4B4: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x8002F4B8: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8002F4BC: ori         $t9, $t9, 0x869F
    ctx->r25 = ctx->r25 | 0X869F;
    // 0x8002F4C0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
L_8002F4C4:
    // 0x8002F4C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002F4C8: lw          $t0, 0x25D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X25D4);
    // 0x8002F4CC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8002F4D0: nop

    // 0x8002F4D4: beq         $t0, $t8, L_8002F504
    if (ctx->r8 == ctx->r24) {
        // 0x8002F4D8: nop
    
            goto L_8002F504;
    }
    // 0x8002F4D8: nop

    // 0x8002F4DC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002F4E0: lw          $t1, 0x29BC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X29BC);
    // 0x8002F4E4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8002F4E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F4EC: lw          $a1, 0x128($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X128);
    // 0x8002F4F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8002F4F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8002F4F8: sw          $t3, 0x25D4($at)
    MEM_W(0X25D4, ctx->r1) = ctx->r11;
    // 0x8002F4FC: jal         0x8002D798
    // 0x8002F500: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    func_8002D798(rdram, ctx);
        goto after_29;
    // 0x8002F500: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_29:
L_8002F504:
    // 0x8002F504: jal         0x800C1850
    // 0x8002F508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_30;
    // 0x8002F508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_30:
    // 0x8002F50C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F510: lw          $a0, 0x29BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29BC);
    // 0x8002F514: jal         0x8009A14C
    // 0x8002F518: nop

    func_8009A14C(rdram, ctx);
        goto after_31;
    // 0x8002F518: nop

    after_31:
    // 0x8002F51C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F520: lw          $a0, 0x29BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29BC);
    // 0x8002F524: jal         0x800997D8
    // 0x8002F528: nop

    func_800997D8(rdram, ctx);
        goto after_32;
    // 0x8002F528: nop

    after_32:
    // 0x8002F52C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002F530: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002F534: lbu         $t2, 0x7208($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X7208);
    // 0x8002F538: lh          $t4, 0x25E0($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X25E0);
    // 0x8002F53C: nop

    // 0x8002F540: beq         $t4, $t2, L_8002F574
    if (ctx->r12 == ctx->r10) {
        // 0x8002F544: nop
    
            goto L_8002F574;
    }
    // 0x8002F544: nop

    // 0x8002F548: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002F54C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002F550: lbu         $t6, 0x7208($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7208);
    // 0x8002F554: lw          $t5, 0x49C4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X49C4);
    // 0x8002F558: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002F55C: lw          $a1, 0x128($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X128);
    // 0x8002F560: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002F564: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8002F568: sh          $t6, 0x25E0($at)
    MEM_H(0X25E0, ctx->r1) = ctx->r14;
    // 0x8002F56C: jal         0x8002D798
    // 0x8002F570: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    func_8002D798(rdram, ctx);
        goto after_33;
    // 0x8002F570: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_33:
L_8002F574:
    // 0x8002F574: jal         0x800C1850
    // 0x8002F578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_34;
    // 0x8002F578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x8002F57C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F580: lw          $a0, 0x49C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X49C4);
    // 0x8002F584: jal         0x8009A14C
    // 0x8002F588: nop

    func_8009A14C(rdram, ctx);
        goto after_35;
    // 0x8002F588: nop

    after_35:
    // 0x8002F58C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002F590: lw          $a0, 0x49C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X49C4);
    // 0x8002F594: jal         0x800997D8
    // 0x8002F598: nop

    func_800997D8(rdram, ctx);
        goto after_36;
    // 0x8002F598: nop

    after_36:
    // 0x8002F59C: jal         0x800C1A28
    // 0x8002F5A0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_37;
    // 0x8002F5A0: nop

    after_37:
    // 0x8002F5A4: b           L_8002F5AC
    // 0x8002F5A8: nop

        goto L_8002F5AC;
    // 0x8002F5A8: nop

L_8002F5AC:
    // 0x8002F5AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002F5B0: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002F5B4: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002F5B8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002F5BC: jr          $ra
    // 0x8002F5C0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002F5C0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8006D90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D90C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D910: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D914: nop

    // 0x8006D918: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006D91C: nop

    // 0x8006D920: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D924: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D928: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D92C: beq         $v0, $zero, L_8006D948
    if (ctx->r2 == 0) {
        // 0x8006D930: nop
    
            goto L_8006D948;
    }
    // 0x8006D930: nop

    // 0x8006D934: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x8006D938: nop

    // 0x8006D93C: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006D940: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006D944: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006D948:
    // 0x8006D948: jr          $ra
    // 0x8006D94C: nop

    return;
    // 0x8006D94C: nop

    // 0x8006D950: jr          $ra
    // 0x8006D954: nop

    return;
    // 0x8006D954: nop

    // 0x8006D958: jr          $ra
    // 0x8006D95C: nop

    return;
    // 0x8006D95C: nop

;}
RECOMP_FUNC void func_80077CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077CE0: jal         0x80061488
    // 0x80077CE4: addiu       $a0, $zero, 0x561
    ctx->r4 = ADD32(0, 0X561);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077CE4: addiu       $a0, $zero, 0x561
    ctx->r4 = ADD32(0, 0X561);
    after_0:
    // 0x80077CE8: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077CEC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077CF0: b           L_80077D00
    // 0x80077CF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077D00;
    // 0x80077CF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077CF8: b           L_80077D00
    // 0x80077CFC: nop

        goto L_80077D00;
    // 0x80077CFC: nop

L_80077D00:
    // 0x80077D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077D08: jr          $ra
    // 0x80077D0C: nop

    return;
    // 0x80077D0C: nop

;}
RECOMP_FUNC void func_80073124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073124: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073128: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007312C: nop

    // 0x80073130: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073134: nop

    // 0x80073138: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007313C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073140: jr          $ra
    // 0x80073144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073148: jr          $ra
    // 0x8007314C: nop

    return;
    // 0x8007314C: nop

    // 0x80073150: jr          $ra
    // 0x80073154: nop

    return;
    // 0x80073154: nop

;}
RECOMP_FUNC void func_8006D468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D46C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D470: jal         0x8005F064
    // 0x8006D474: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D474: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    after_0:
    // 0x8006D478: b           L_8006D488
    // 0x8006D47C: nop

        goto L_8006D488;
    // 0x8006D47C: nop

    // 0x8006D480: b           L_8006D488
    // 0x8006D484: nop

        goto L_8006D488;
    // 0x8006D484: nop

L_8006D488:
    // 0x8006D488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D48C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D490: jr          $ra
    // 0x8006D494: nop

    return;
    // 0x8006D494: nop

;}
RECOMP_FUNC void func_80023E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E50: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80023E54: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80023E58: lw          $t6, 0x306C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X306C);
    // 0x80023E5C: nop

    // 0x80023E60: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80023E64: nop

    // 0x80023E68: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80023E6C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80023E70: lh          $t8, 0x1B48($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X1B48);
    // 0x80023E74: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x80023E78: blez        $t8, L_80023EB8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80023E7C: nop
    
            goto L_80023EB8;
    }
    // 0x80023E7C: nop

L_80023E80:
    // 0x80023E80: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80023E84: nop

    // 0x80023E88: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80023E8C: nop

    // 0x80023E90: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x80023E94: lh          $t1, 0x6($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6);
    // 0x80023E98: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80023E9C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80023EA0: lh          $t5, 0x1B48($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X1B48);
    // 0x80023EA4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80023EA8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80023EAC: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80023EB0: bne         $at, $zero, L_80023E80
    if (ctx->r1 != 0) {
        // 0x80023EB4: sh          $t2, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r10;
            goto L_80023E80;
    }
    // 0x80023EB4: sh          $t2, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r10;
L_80023EB8:
    // 0x80023EB8: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80023EBC: b           L_80023ECC
    // 0x80023EC0: nop

        goto L_80023ECC;
    // 0x80023EC0: nop

    // 0x80023EC4: b           L_80023ECC
    // 0x80023EC8: nop

        goto L_80023ECC;
    // 0x80023EC8: nop

L_80023ECC:
    // 0x80023ECC: jr          $ra
    // 0x80023ED0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80023ED0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80068D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D10: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068D14: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068D18: nop

    // 0x80068D1C: lh          $v0, 0x26($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X26);
    // 0x80068D20: nop

    // 0x80068D24: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80068D28: jr          $ra
    // 0x80068D2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068D2C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068D30: jr          $ra
    // 0x80068D34: nop

    return;
    // 0x80068D34: nop

    // 0x80068D38: jr          $ra
    // 0x80068D3C: nop

    return;
    // 0x80068D3C: nop

;}
RECOMP_FUNC void func_80096250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096250: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80096254: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80096258:
    // 0x80096258: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8009625C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096260: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80096264: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80096268: sw          $zero, -0x3EB8($at)
    MEM_W(-0X3EB8, ctx->r1) = 0;
    // 0x8009626C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80096270: nop

    // 0x80096274: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80096278: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8009627C: bne         $at, $zero, L_80096258
    if (ctx->r1 != 0) {
        // 0x80096280: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_80096258;
    }
    // 0x80096280: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80096284: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80096288: addiu       $t0, $t0, -0x28B8
    ctx->r8 = ADD32(ctx->r8, -0X28B8);
    // 0x8009628C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096290: sw          $t0, -0x2878($at)
    MEM_W(-0X2878, ctx->r1) = ctx->r8;
    // 0x80096294: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80096298: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009629C: sw          $t1, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r9;
    // 0x800962A0: b           L_800962A8
    // 0x800962A4: nop

        goto L_800962A8;
    // 0x800962A4: nop

L_800962A8:
    // 0x800962A8: jr          $ra
    // 0x800962AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800962AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80015E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015E94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80015E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015E9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80015EA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80015EA4:
    // 0x80015EA4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80015EA8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80015EAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80015EB0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80015EB4: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x80015EB8: nop

    // 0x80015EBC: bne         $t8, $zero, L_80015ECC
    if (ctx->r24 != 0) {
        // 0x80015EC0: nop
    
            goto L_80015ECC;
    }
    // 0x80015EC0: nop

    // 0x80015EC4: b           L_80015EE4
    // 0x80015EC8: nop

        goto L_80015EE4;
    // 0x80015EC8: nop

L_80015ECC:
    // 0x80015ECC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80015ED0: nop

    // 0x80015ED4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80015ED8: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x80015EDC: bne         $at, $zero, L_80015EA4
    if (ctx->r1 != 0) {
        // 0x80015EE0: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_80015EA4;
    }
    // 0x80015EE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_80015EE4:
    // 0x80015EE4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80015EE8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80015EEC: bne         $t1, $at, L_80015EFC
    if (ctx->r9 != ctx->r1) {
        // 0x80015EF0: nop
    
            goto L_80015EFC;
    }
    // 0x80015EF0: nop

    // 0x80015EF4: b           L_80015FA4
    // 0x80015EF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80015FA4;
    // 0x80015EF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015EFC:
    // 0x80015EFC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80015F00: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80015F04: addiu       $t4, $t4, -0x4530
    ctx->r12 = ADD32(ctx->r12, -0X4530);
    // 0x80015F08: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80015F0C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80015F10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80015F14: sw          $t5, -0x4538($at)
    MEM_W(-0X4538, ctx->r1) = ctx->r13;
    // 0x80015F18: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80015F1C: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80015F20: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80015F24: nop

    // 0x80015F28: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x80015F2C: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80015F30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80015F34: jal         0x80004654
    // 0x80015F38: nop

    func_80004654(rdram, ctx);
        goto after_0;
    // 0x80015F38: nop

    after_0:
    // 0x80015F3C: bgez        $v0, L_80015F64
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80015F40: nop
    
            goto L_80015F64;
    }
    // 0x80015F40: nop

    // 0x80015F44: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80015F48: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80015F4C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80015F50: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80015F54: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80015F58: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x80015F5C: b           L_80015FA4
    // 0x80015F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80015FA4;
    // 0x80015F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80015F64:
    // 0x80015F64: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80015F68: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80015F6C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80015F70: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80015F74: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80015F78: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x80015F7C: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80015F80: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80015F84: lw          $t7, -0x4538($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4538);
    // 0x80015F88: lw          $t5, 0x6C10($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6C10);
    // 0x80015F8C: nop

    // 0x80015F90: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80015F94: b           L_80015FA4
    // 0x80015F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80015FA4;
    // 0x80015F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80015F9C: b           L_80015FA4
    // 0x80015FA0: nop

        goto L_80015FA4;
    // 0x80015FA0: nop

L_80015FA4:
    // 0x80015FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015FA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80015FAC: jr          $ra
    // 0x80015FB0: nop

    return;
    // 0x80015FB0: nop

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
RECOMP_FUNC void func_80022918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022918: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002291C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80022920: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80022924: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80022928: swc1        $f12, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f12.u32l;
    // 0x8002292C: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    // 0x80022930: swc1        $f29, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80022934: swc1        $f28, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f28.u32l;
    // 0x80022938: swc1        $f27, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002293C: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x80022940: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80022944: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x80022948: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002294C: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x80022950: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80022954: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80022958: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002295C: lbu         $t6, 0x11AE($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X11AE);
    // 0x80022960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80022964: bne         $t6, $at, L_80022974
    if (ctx->r14 != ctx->r1) {
        // 0x80022968: nop
    
            goto L_80022974;
    }
    // 0x80022968: nop

    // 0x8002296C: b           L_80022E14
    // 0x80022970: nop

        goto L_80022E14;
    // 0x80022970: nop

L_80022974:
    // 0x80022974: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80022978: lwc1        $f4, -0x7820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002297C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80022980: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022984: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80022988: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8002298C: nop

    // 0x80022990: bc1f        L_80022A3C
    if (!c1cs) {
        // 0x80022994: nop
    
            goto L_80022A3C;
    }
    // 0x80022994: nop

    // 0x80022998: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002299C: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800229A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800229A4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800229A8: c.eq.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d == ctx->f18.d;
    // 0x800229AC: nop

    // 0x800229B0: bc1f        L_80022A3C
    if (!c1cs) {
        // 0x800229B4: nop
    
            goto L_80022A3C;
    }
    // 0x800229B4: nop

    // 0x800229B8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800229BC: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x800229C0: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x800229C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800229C8: nop

    // 0x800229CC: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800229D0: nop

    // 0x800229D4: bc1f        L_800229E4
    if (!c1cs) {
        // 0x800229D8: nop
    
            goto L_800229E4;
    }
    // 0x800229D8: nop

    // 0x800229DC: b           L_800229F8
    // 0x800229E0: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
        goto L_800229F8;
    // 0x800229E0: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
L_800229E4:
    // 0x800229E4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800229E8: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x800229EC: lwc1        $f20, 0x10($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0X10);
    // 0x800229F0: nop

    // 0x800229F4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_800229F8:
    // 0x800229F8: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800229FC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80022A00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80022A04: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x80022A08: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80022A0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80022A10: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x80022A14: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x80022A18: nop

    // 0x80022A1C: bc1t        L_80022A3C
    if (c1cs) {
        // 0x80022A20: nop
    
            goto L_80022A3C;
    }
    // 0x80022A20: nop

    // 0x80022A24: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80022A28: lh          $t9, 0x2588($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2588);
    // 0x80022A2C: nop

    // 0x80022A30: andi        $t0, $t9, 0x9
    ctx->r8 = ctx->r25 & 0X9;
    // 0x80022A34: beq         $t0, $zero, L_80022A4C
    if (ctx->r8 == 0) {
        // 0x80022A38: nop
    
            goto L_80022A4C;
    }
    // 0x80022A38: nop

L_80022A3C:
    // 0x80022A3C: jal         0x800228A8
    // 0x80022A40: nop

    func_800228A8(rdram, ctx);
        goto after_0;
    // 0x80022A40: nop

    after_0:
    // 0x80022A44: b           L_80022E14
    // 0x80022A48: nop

        goto L_80022E14;
    // 0x80022A48: nop

L_80022A4C:
    // 0x80022A4C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80022A50: lbu         $t1, 0x11AE($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X11AE);
    // 0x80022A54: nop

    // 0x80022A58: bne         $t1, $zero, L_80022AEC
    if (ctx->r9 != 0) {
        // 0x80022A5C: nop
    
            goto L_80022AEC;
    }
    // 0x80022A5C: nop

    // 0x80022A60: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80022A64: lw          $t2, 0x307C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X307C);
    // 0x80022A68: nop

    // 0x80022A6C: bne         $t2, $zero, L_80022AE4
    if (ctx->r10 != 0) {
        // 0x80022A70: nop
    
            goto L_80022AE4;
    }
    // 0x80022A70: nop

    // 0x80022A74: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80022A78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022A7C: sb          $t3, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = ctx->r11;
    // 0x80022A80: lhu         $t4, 0xA6($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XA6);
    // 0x80022A84: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80022A88: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80022A8C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80022A90: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80022A94: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80022A98: lhu         $a0, -0x4772($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4772);
    // 0x80022A9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022AA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80022AA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80022AA8: jal         0x800AFB70
    // 0x80022AAC: sh          $t4, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r12;
    func_800AFB70(rdram, ctx);
        goto after_1;
    // 0x80022AAC: sh          $t4, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r12;
    after_1:
    // 0x80022AB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80022AB4: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
    // 0x80022AB8: lhu         $a0, 0xA6($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XA6);
    // 0x80022ABC: jal         0x8002BB50
    // 0x80022AC0: nop

    func_8002BB50(rdram, ctx);
        goto after_2;
    // 0x80022AC0: nop

    after_2:
    // 0x80022AC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022AC8: swc1        $f0, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f0.u32l;
    // 0x80022ACC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80022AD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022AD4: swc1        $f6, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f6.u32l;
    // 0x80022AD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022ADC: b           L_80022AEC
    // 0x80022AE0: swc1        $f6, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f6.u32l;
        goto L_80022AEC;
    // 0x80022AE0: swc1        $f6, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f6.u32l;
L_80022AE4:
    // 0x80022AE4: b           L_80022E14
    // 0x80022AE8: nop

        goto L_80022E14;
    // 0x80022AE8: nop

L_80022AEC:
    // 0x80022AEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022AF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80022AF4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80022AF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022AFC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80022B00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022B04: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80022B08: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80022B0C: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80022B10: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x80022B14: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    // 0x80022B18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80022B1C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80022B20: jal         0x800B0E88
    // 0x80022B24: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    func_800B0E88(rdram, ctx);
        goto after_3;
    // 0x80022B24: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80022B28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022B2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80022B30: addiu       $t8, $sp, 0x68
    ctx->r24 = ADD32(ctx->r29, 0X68);
    // 0x80022B34: addiu       $t9, $sp, 0x68
    ctx->r25 = ADD32(ctx->r29, 0X68);
    // 0x80022B38: swc1        $f16, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f16.u32l;
    // 0x80022B3C: lwc1        $f20, 0x20($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0X20);
    // 0x80022B40: addiu       $t0, $sp, 0x68
    ctx->r8 = ADD32(ctx->r29, 0X68);
    // 0x80022B44: swc1        $f20, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f20.u32l;
    // 0x80022B48: swc1        $f20, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f20.u32l;
    // 0x80022B4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022B50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80022B54: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x80022B58: addiu       $t2, $sp, 0x68
    ctx->r10 = ADD32(ctx->r29, 0X68);
    // 0x80022B5C: swc1        $f18, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f18.u32l;
    // 0x80022B60: lwc1        $f6, 0x14($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80022B64: nop

    // 0x80022B68: swc1        $f6, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f6.u32l;
    // 0x80022B6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022B70: addiu       $t3, $sp, 0x68
    ctx->r11 = ADD32(ctx->r29, 0X68);
    // 0x80022B74: addiu       $t4, $sp, 0x68
    ctx->r12 = ADD32(ctx->r29, 0X68);
    // 0x80022B78: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x80022B7C: lwc1        $f28, 0x8($t4)
    ctx->f28.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80022B80: addiu       $t5, $sp, 0x68
    ctx->r13 = ADD32(ctx->r29, 0X68);
    // 0x80022B84: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x80022B88: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x80022B8C: swc1        $f28, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f28.u32l;
    // 0x80022B90: swc1        $f26, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f26.u32l;
    // 0x80022B94: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80022B98: addiu       $t6, $sp, 0x68
    ctx->r14 = ADD32(ctx->r29, 0X68);
    // 0x80022B9C: swc1        $f24, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f24.u32l;
    // 0x80022BA0: addiu       $t7, $sp, 0x68
    ctx->r15 = ADD32(ctx->r29, 0X68);
    // 0x80022BA4: swc1        $f22, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f22.u32l;
    // 0x80022BA8: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80022BAC: addiu       $t8, $sp, 0x68
    ctx->r24 = ADD32(ctx->r29, 0X68);
    // 0x80022BB0: swc1        $f20, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f20.u32l;
    // 0x80022BB4: addiu       $t9, $sp, 0x68
    ctx->r25 = ADD32(ctx->r29, 0X68);
    // 0x80022BB8: swc1        $f20, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f20.u32l;
    // 0x80022BBC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80022BC0: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80022BC4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80022BC8: jal         0x800B1250
    // 0x80022BCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_4;
    // 0x80022BCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80022BD0: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80022BD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022BD8: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80022BDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022BE0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80022BE4: swc1        $f16, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f16.u32l;
    // 0x80022BE8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80022BEC: lw          $t0, 0x258C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X258C);
    // 0x80022BF0: nop

    // 0x80022BF4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80022BF8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80022BFC: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80022C00: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80022C04: bgez        $t1, L_80022C20
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80022C08: cvt.d.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
            goto L_80022C20;
    }
    // 0x80022C08: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x80022C0C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80022C10: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80022C14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022C18: nop

    // 0x80022C1C: add.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f6.d + ctx->f4.d;
L_80022C20:
    // 0x80022C20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022C24: lwc1        $f9, -0x1CD8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1CD8);
    // 0x80022C28: lwc1        $f8, -0x1CD4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1CD4);
    // 0x80022C2C: nop

    // 0x80022C30: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80022C34: jal         0x800C3070
    // 0x80022C38: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_5;
    // 0x80022C38: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_5:
    // 0x80022C3C: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x80022C40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80022C44: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80022C48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022C4C: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80022C50: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80022C54: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80022C58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022C5C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80022C60: swc1        $f10, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f10.u32l;
    // 0x80022C64: jal         0x800C1850
    // 0x80022C68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_6;
    // 0x80022C68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80022C6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022C70: lwc1        $f16, 0x1618($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1618);
    // 0x80022C74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022C78: lwc1        $f7, -0x1CD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1CD0);
    // 0x80022C7C: lwc1        $f6, -0x1CCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1CCC);
    // 0x80022C80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022C84: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x80022C88: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80022C8C: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80022C90: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80022C94: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80022C98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022C9C: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    // 0x80022CA0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80022CA4: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80022CA8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80022CAC: jal         0x800C2304
    // 0x80022CB0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_7;
    // 0x80022CB0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    after_7:
    // 0x80022CB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022CB8: lwc1        $f7, -0x1CC8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1CC8);
    // 0x80022CBC: lwc1        $f6, -0x1CC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1CC4);
    // 0x80022CC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022CC4: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80022CC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022CCC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80022CD0: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80022CD4: lwc1        $f16, 0x13C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x80022CD8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80022CDC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80022CE0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022CE4: sub.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f18.d - ctx->f10.d;
    // 0x80022CE8: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80022CEC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80022CF0: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x80022CF4: swc1        $f6, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f6.u32l;
    // 0x80022CF8: bc1f        L_80022D28
    if (!c1cs) {
        // 0x80022CFC: nop
    
            goto L_80022D28;
    }
    // 0x80022CFC: nop

    // 0x80022D00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D04: lwc1        $f18, 0x13C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x80022D08: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022D0C: lwc1        $f9, -0x1CC0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1CC0);
    // 0x80022D10: lwc1        $f8, -0x1CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1CBC);
    // 0x80022D14: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80022D18: add.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d + ctx->f8.d;
    // 0x80022D1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D20: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80022D24: swc1        $f4, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f4.u32l;
L_80022D28:
    // 0x80022D28: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80022D2C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80022D30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D34: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80022D38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022D3C: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80022D40: mul.d       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80022D44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D48: lwc1        $f6, 0x1354($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x80022D4C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80022D50: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80022D54: sub.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f4.d - ctx->f8.d;
    // 0x80022D58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80022D5C: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80022D60: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80022D64: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x80022D68: swc1        $f16, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f16.u32l;
    // 0x80022D6C: bc1f        L_80022D9C
    if (!c1cs) {
        // 0x80022D70: nop
    
            goto L_80022D9C;
    }
    // 0x80022D70: nop

    // 0x80022D74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D78: lwc1        $f4, 0x1354($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x80022D7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022D80: lwc1        $f19, -0x1CB8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1CB8);
    // 0x80022D84: lwc1        $f18, -0x1CB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1CB4);
    // 0x80022D88: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80022D8C: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x80022D90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D94: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80022D98: swc1        $f10, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f10.u32l;
L_80022D9C:
    // 0x80022D9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022DA0: lwc1        $f12, 0x1354($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x80022DA4: jal         0x800C25B8
    // 0x80022DA8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_8;
    // 0x80022DA8: nop

    after_8:
    // 0x80022DAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022DB0: lwc1        $f6, 0x13C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x80022DB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022DB8: lwc1        $f9, -0x1CB0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1CB0);
    // 0x80022DBC: lwc1        $f8, -0x1CAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1CAC);
    // 0x80022DC0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80022DC4: mul.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80022DC8: jal         0x800C3070
    // 0x80022DCC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_9;
    // 0x80022DCC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_9:
    // 0x80022DD0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80022DD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80022DD8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80022DDC: mul.s       $f12, $f20, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80022DE0: jal         0x800C2780
    // 0x80022DE4: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_10;
    // 0x80022DE4: nop

    after_10:
    // 0x80022DE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022DEC: lwc1        $f10, 0x15D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x80022DF0: nop

    // 0x80022DF4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80022DF8: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x80022DFC: jal         0x800C2948
    // 0x80022E00: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_11;
    // 0x80022E00: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    after_11:
    // 0x80022E04: jal         0x8002D200
    // 0x80022E08: nop

    func_8002D200(rdram, ctx);
        goto after_12;
    // 0x80022E08: nop

    after_12:
    // 0x80022E0C: b           L_80022E14
    // 0x80022E10: nop

        goto L_80022E14;
    // 0x80022E10: nop

L_80022E14:
    // 0x80022E14: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80022E18: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80022E1C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80022E20: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80022E24: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022E28: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80022E2C: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80022E30: lwc1        $f27, 0x38($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80022E34: lwc1        $f26, 0x3C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80022E38: lwc1        $f29, 0x40($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80022E3C: lwc1        $f28, 0x44($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80022E40: jr          $ra
    // 0x80022E44: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80022E44: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800725E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800725E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800725EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800725F0: jal         0x80061488
    // 0x800725F4: addiu       $a0, $zero, 0x50D
    ctx->r4 = ADD32(0, 0X50D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800725F4: addiu       $a0, $zero, 0x50D
    ctx->r4 = ADD32(0, 0X50D);
    after_0:
    // 0x800725F8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800725FC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80072600: b           L_80072610
    // 0x80072604: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80072610;
    // 0x80072604: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80072608: b           L_80072610
    // 0x8007260C: nop

        goto L_80072610;
    // 0x8007260C: nop

L_80072610:
    // 0x80072610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072618: jr          $ra
    // 0x8007261C: nop

    return;
    // 0x8007261C: nop

;}
RECOMP_FUNC void func_80076C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076C74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076C78: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076C7C: nop

    // 0x80076C80: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x80076C84: nop

    // 0x80076C88: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80076C8C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076C90: jr          $ra
    // 0x80076C94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076C94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076C98: jr          $ra
    // 0x80076C9C: nop

    return;
    // 0x80076C9C: nop

    // 0x80076CA0: jr          $ra
    // 0x80076CA4: nop

    return;
    // 0x80076CA4: nop

;}
RECOMP_FUNC void func_8006EE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EE84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EE88: jal         0x80061348
    // 0x8006EE8C: addiu       $a0, $zero, 0x14F
    ctx->r4 = ADD32(0, 0X14F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006EE8C: addiu       $a0, $zero, 0x14F
    ctx->r4 = ADD32(0, 0X14F);
    after_0:
    // 0x8006EE90: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006EE94: b           L_8006EEA4
    // 0x8006EE98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006EEA4;
    // 0x8006EE98: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006EE9C: b           L_8006EEA4
    // 0x8006EEA0: nop

        goto L_8006EEA4;
    // 0x8006EEA0: nop

L_8006EEA4:
    // 0x8006EEA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EEA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EEAC: jr          $ra
    // 0x8006EEB0: nop

    return;
    // 0x8006EEB0: nop

;}
RECOMP_FUNC void func_8006BD00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BD08: jal         0x8005F064
    // 0x8006BD0C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BD0C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x8006BD10: b           L_8006BD20
    // 0x8006BD14: nop

        goto L_8006BD20;
    // 0x8006BD14: nop

    // 0x8006BD18: b           L_8006BD20
    // 0x8006BD1C: nop

        goto L_8006BD20;
    // 0x8006BD1C: nop

L_8006BD20:
    // 0x8006BD20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BD24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BD28: jr          $ra
    // 0x8006BD2C: nop

    return;
    // 0x8006BD2C: nop

;}
RECOMP_FUNC void func_80071F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071F90: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071F94: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071F98: nop

    // 0x80071F9C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80071FA0: nop

    // 0x80071FA4: slti        $t7, $v0, 0xC9
    ctx->r15 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80071FA8: jr          $ra
    // 0x80071FAC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071FAC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071FB0: jr          $ra
    // 0x80071FB4: nop

    return;
    // 0x80071FB4: nop

    // 0x80071FB8: jr          $ra
    // 0x80071FBC: nop

    return;
    // 0x80071FBC: nop

;}
RECOMP_FUNC void func_800658E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800658E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800658EC: jal         0x8005F064
    // 0x800658F0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800658F0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_0:
    // 0x800658F4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800658F8: b           L_80065908
    // 0x800658FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065908;
    // 0x800658FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065900: b           L_80065908
    // 0x80065904: nop

        goto L_80065908;
    // 0x80065904: nop

L_80065908:
    // 0x80065908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006590C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065910: jr          $ra
    // 0x80065914: nop

    return;
    // 0x80065914: nop

;}
RECOMP_FUNC void Scheduler_Thread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009756C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80097570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097574: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80097578: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009757C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80097580: nop

    // 0x80097584: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80097588:
    // 0x80097588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8009758C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80097590: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80097594: jal         0x800C4C40
    // 0x80097598: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80097598: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    after_0:
    // 0x8009759C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800975A0: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x800975A4: beq         $s0, $at, L_800975D8
    if (ctx->r16 == ctx->r1) {
        // 0x800975A8: nop
    
            goto L_800975D8;
    }
    // 0x800975A8: nop

    // 0x800975AC: addiu       $at, $zero, 0x29B
    ctx->r1 = ADD32(0, 0X29B);
    // 0x800975B0: beq         $s0, $at, L_800975F4
    if (ctx->r16 == ctx->r1) {
        // 0x800975B4: nop
    
            goto L_800975F4;
    }
    // 0x800975B4: nop

    // 0x800975B8: addiu       $at, $zero, 0x29C
    ctx->r1 = ADD32(0, 0X29C);
    // 0x800975BC: beq         $s0, $at, L_80097610
    if (ctx->r16 == ctx->r1) {
        // 0x800975C0: nop
    
            goto L_80097610;
    }
    // 0x800975C0: nop

    // 0x800975C4: addiu       $at, $zero, 0x29D
    ctx->r1 = ADD32(0, 0X29D);
    // 0x800975C8: beq         $s0, $at, L_8009762C
    if (ctx->r16 == ctx->r1) {
        // 0x800975CC: nop
    
            goto L_8009762C;
    }
    // 0x800975CC: nop

    // 0x800975D0: b           L_8009767C
    // 0x800975D4: nop

        goto L_8009767C;
    // 0x800975D4: nop

L_800975D8:
    // 0x800975D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800975DC: jal         0x8009769C
    // 0x800975E0: nop

    Scheduler_HandleVideoMesg(rdram, ctx);
        goto after_1;
    // 0x800975E0: nop

    after_1:
    // 0x800975E4: jal         0x800C4240
    // 0x800975E8: nop

    guRandom(rdram, ctx);
        goto after_2;
    // 0x800975E8: nop

    after_2:
    // 0x800975EC: b           L_8009767C
    // 0x800975F0: nop

        goto L_8009767C;
    // 0x800975F0: nop

L_800975F4:
    // 0x800975F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800975F8: jal         0x80097988
    // 0x800975FC: nop

    Scheduler_HandleRspMesg(rdram, ctx);
        goto after_3;
    // 0x800975FC: nop

    after_3:
    // 0x80097600: jal         0x800C4240
    // 0x80097604: nop

    guRandom(rdram, ctx);
        goto after_4;
    // 0x80097604: nop

    after_4:
    // 0x80097608: b           L_8009767C
    // 0x8009760C: nop

        goto L_8009767C;
    // 0x8009760C: nop

L_80097610:
    // 0x80097610: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80097614: jal         0x80097B0C
    // 0x80097618: nop

    Scheduler_HandleRdpMesg(rdram, ctx);
        goto after_5;
    // 0x80097618: nop

    after_5:
    // 0x8009761C: jal         0x800C4240
    // 0x80097620: nop

    guRandom(rdram, ctx);
        goto after_6;
    // 0x80097620: nop

    after_6:
    // 0x80097624: b           L_8009767C
    // 0x80097628: nop

        goto L_8009767C;
    // 0x80097628: nop

L_8009762C:
    // 0x8009762C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80097630: nop

    // 0x80097634: lw          $t8, 0x280($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X280);
    // 0x80097638: nop

    // 0x8009763C: beq         $t8, $zero, L_80097674
    if (ctx->r24 == 0) {
        // 0x80097640: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_80097674;
    }
    // 0x80097640: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80097644:
    // 0x80097644: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097648: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8009764C: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x80097650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097654: jal         0x800C4AA0
    // 0x80097658: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80097658: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_7:
    // 0x8009765C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097660: nop

    // 0x80097664: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80097668: nop

    // 0x8009766C: bne         $t1, $zero, L_80097644
    if (ctx->r9 != 0) {
        // 0x80097670: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_80097644;
    }
    // 0x80097670: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80097674:
    // 0x80097674: b           L_8009767C
    // 0x80097678: nop

        goto L_8009767C;
    // 0x80097678: nop

L_8009767C:
    // 0x8009767C: b           L_80097588
    // 0x80097680: nop

        goto L_80097588;
    // 0x80097680: nop

    // 0x80097684: b           L_8009768C
    // 0x80097688: nop

        goto L_8009768C;
    // 0x80097688: nop

L_8009768C:
    // 0x8009768C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80097690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80097694: jr          $ra
    // 0x80097698: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80097698: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004FAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FAB0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8004FAB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004FAB8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8004FABC: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8004FAC0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004FAC4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004FAC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004FACC: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8004FAD0: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8004FAD4: addiu       $t7, $zero, 0xA8
    ctx->r15 = ADD32(0, 0XA8);
    // 0x8004FAD8: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8004FADC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004FAE0: nop

    // 0x8004FAE4: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x8004FAE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004FAEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004FAF0: nop

    // 0x8004FAF4: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8004FAF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004FAFC: nop

    // 0x8004FB00: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x8004FB04: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x8004FB08: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x8004FB0C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004FB10: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x8004FB14: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8004FB18: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8004FB1C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004FB20: bne         $t2, $zero, L_8004FB30
    if (ctx->r10 != 0) {
        // 0x8004FB24: andi        $t3, $t1, 0x8000
        ctx->r11 = ctx->r9 & 0X8000;
            goto L_8004FB30;
    }
    // 0x8004FB24: andi        $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 & 0X8000;
    // 0x8004FB28: beq         $t3, $zero, L_8004FE00
    if (ctx->r11 == 0) {
        // 0x8004FB2C: nop
    
            goto L_8004FE00;
    }
    // 0x8004FB2C: nop

L_8004FB30:
    // 0x8004FB30: lh          $t4, 0x76($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X76);
    // 0x8004FB34: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x8004FB38: bne         $t4, $at, L_8004FE00
    if (ctx->r12 != ctx->r1) {
        // 0x8004FB3C: nop
    
            goto L_8004FE00;
    }
    // 0x8004FB3C: nop

    // 0x8004FB40: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004FB44: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x8004FB48: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x8004FB4C: lw          $t6, 0x5C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X5C);
    // 0x8004FB50: nop

    // 0x8004FB54: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8004FB58: nop

    // 0x8004FB5C: beq         $t7, $at, L_8004FB94
    if (ctx->r15 == ctx->r1) {
        // 0x8004FB60: nop
    
            goto L_8004FB94;
    }
    // 0x8004FB60: nop

    // 0x8004FB64: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8004FB68: beq         $t7, $at, L_8004FB94
    if (ctx->r15 == ctx->r1) {
        // 0x8004FB6C: nop
    
            goto L_8004FB94;
    }
    // 0x8004FB6C: nop

    // 0x8004FB70: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x8004FB74: beq         $t7, $at, L_8004FB94
    if (ctx->r15 == ctx->r1) {
        // 0x8004FB78: nop
    
            goto L_8004FB94;
    }
    // 0x8004FB78: nop

    // 0x8004FB7C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8004FB80: beq         $t7, $at, L_8004FB94
    if (ctx->r15 == ctx->r1) {
        // 0x8004FB84: nop
    
            goto L_8004FB94;
    }
    // 0x8004FB84: nop

    // 0x8004FB88: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x8004FB8C: bne         $t7, $at, L_8004FE00
    if (ctx->r15 != ctx->r1) {
        // 0x8004FB90: nop
    
            goto L_8004FE00;
    }
    // 0x8004FB90: nop

L_8004FB94:
    // 0x8004FB94: jal         0x80031B6C
    // 0x8004FB98: nop

    func_80031B6C(rdram, ctx);
        goto after_0;
    // 0x8004FB98: nop

    after_0:
    // 0x8004FB9C: jal         0x80031AC8
    // 0x8004FBA0: nop

    func_80031AC8(rdram, ctx);
        goto after_1;
    // 0x8004FBA0: nop

    after_1:
    // 0x8004FBA4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004FBA8: beq         $v0, $at, L_8004FBD0
    if (ctx->r2 == ctx->r1) {
        // 0x8004FBAC: nop
    
            goto L_8004FBD0;
    }
    // 0x8004FBAC: nop

L_8004FBB0:
    // 0x8004FBB0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FBB4: jal         0x800499B0
    // 0x8004FBB8: nop

    func_800499B0(rdram, ctx);
        goto after_2;
    // 0x8004FBB8: nop

    after_2:
    // 0x8004FBBC: jal         0x80031AC8
    // 0x8004FBC0: nop

    func_80031AC8(rdram, ctx);
        goto after_3;
    // 0x8004FBC0: nop

    after_3:
    // 0x8004FBC4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8004FBC8: bne         $v0, $at, L_8004FBB0
    if (ctx->r2 != ctx->r1) {
        // 0x8004FBCC: nop
    
            goto L_8004FBB0;
    }
    // 0x8004FBCC: nop

L_8004FBD0:
    // 0x8004FBD0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8004FBD4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8004FBD8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8004FBDC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004FBE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004FBE4: nop

    // 0x8004FBE8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8004FBEC: jal         0x80016620
    // 0x8004FBF0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_80016620(rdram, ctx);
        goto after_4;
    // 0x8004FBF0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x8004FBF4: jal         0x80016138
    // 0x8004FBF8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_5;
    // 0x8004FBF8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_5:
    // 0x8004FBFC: beq         $v0, $zero, L_8004FC20
    if (ctx->r2 == 0) {
        // 0x8004FC00: nop
    
            goto L_8004FC20;
    }
    // 0x8004FC00: nop

L_8004FC04:
    // 0x8004FC04: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FC08: jal         0x800499B0
    // 0x8004FC0C: nop

    func_800499B0(rdram, ctx);
        goto after_6;
    // 0x8004FC0C: nop

    after_6:
    // 0x8004FC10: jal         0x80016138
    // 0x8004FC14: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_7;
    // 0x8004FC14: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_7:
    // 0x8004FC18: bne         $v0, $zero, L_8004FC04
    if (ctx->r2 != 0) {
        // 0x8004FC1C: nop
    
            goto L_8004FC04;
    }
    // 0x8004FC1C: nop

L_8004FC20:
    // 0x8004FC20: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004FC24: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x8004FC28: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8004FC2C: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x8004FC30: nop

    // 0x8004FC34: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8004FC38: nop

    // 0x8004FC3C: bne         $t0, $at, L_8004FC50
    if (ctx->r8 != ctx->r1) {
        // 0x8004FC40: nop
    
            goto L_8004FC50;
    }
    // 0x8004FC40: nop

    // 0x8004FC44: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8004FC48: b           L_8004FC74
    // 0x8004FC4C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
        goto L_8004FC74;
    // 0x8004FC4C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_8004FC50:
    // 0x8004FC50: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004FC54: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x8004FC58: nop

    // 0x8004FC5C: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x8004FC60: nop

    // 0x8004FC64: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8004FC68: nop

    // 0x8004FC6C: addiu       $t5, $t4, -0x24
    ctx->r13 = ADD32(ctx->r12, -0X24);
    // 0x8004FC70: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
L_8004FC74:
    // 0x8004FC74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004FC78: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8004FC7C: nop

    // 0x8004FC80: lw          $a0, 0x5C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X5C);
    // 0x8004FC84: jal         0x800299C4
    // 0x8004FC88: nop

    func_800299C4(rdram, ctx);
        goto after_8;
    // 0x8004FC88: nop

    after_8:
    // 0x8004FC8C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004FC90: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8004FC94: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004FC98: lh          $t8, 0x42($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X42);
    // 0x8004FC9C: nop

    // 0x8004FCA0: bne         $t8, $at, L_8004FCB0
    if (ctx->r24 != ctx->r1) {
        // 0x8004FCA4: nop
    
            goto L_8004FCB0;
    }
    // 0x8004FCA4: nop

    // 0x8004FCA8: b           L_8004FCC8
    // 0x8004FCAC: addiu       $s0, $zero, 0x19
    ctx->r16 = ADD32(0, 0X19);
        goto L_8004FCC8;
    // 0x8004FCAC: addiu       $s0, $zero, 0x19
    ctx->r16 = ADD32(0, 0X19);
L_8004FCB0:
    // 0x8004FCB0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8004FCB4: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8004FCB8: nop

    // 0x8004FCBC: lh          $s0, 0x42($t9)
    ctx->r16 = MEM_H(ctx->r25, 0X42);
    // 0x8004FCC0: nop

    // 0x8004FCC4: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
L_8004FCC8:
    // 0x8004FCC8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004FCCC: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004FCD0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8004FCD4: lwc1        $f16, 0x10($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8004FCD8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8004FCDC: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x8004FCE0: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x8004FCE4: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x8004FCE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004FCEC: jal         0x800298A4
    // 0x8004FCF0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800298A4(rdram, ctx);
        goto after_9;
    // 0x8004FCF0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x8004FCF4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8004FCF8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x8004FCFC: nop

    // 0x8004FD00: sw          $v0, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->r2;
    // 0x8004FD04: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FD08: jal         0x80051700
    // 0x8004FD0C: nop

    func_80051700(rdram, ctx);
        goto after_10;
    // 0x8004FD0C: nop

    after_10:
    // 0x8004FD10: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8004FD14: lw          $t3, 0x648($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X648);
    // 0x8004FD18: lh          $s1, 0x3E($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X3E);
    // 0x8004FD1C: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x8004FD20: sra         $t2, $s2, 16
    ctx->r10 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8004FD24: sh          $s1, 0x42($t3)
    MEM_H(0X42, ctx->r11) = ctx->r17;
    // 0x8004FD28: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8004FD2C: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8004FD30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8004FD34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004FD38: jal         0x8004EF90
    // 0x8004FD3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8004EF90(rdram, ctx);
        goto after_11;
    // 0x8004FD3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x8004FD40: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x8004FD44: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
L_8004FD48:
    // 0x8004FD48: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FD4C: jal         0x800499B0
    // 0x8004FD50: nop

    func_800499B0(rdram, ctx);
        goto after_12;
    // 0x8004FD50: nop

    after_12:
    // 0x8004FD54: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8004FD58: nop

    // 0x8004FD5C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8004FD60: bne         $t6, $zero, L_8004FD48
    if (ctx->r14 != 0) {
        // 0x8004FD64: sw          $t6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r14;
            goto L_8004FD48;
    }
    // 0x8004FD64: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8004FD68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004FD6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004FD70: nop

    // 0x8004FD74: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x8004FD78: jal         0x80016620
    // 0x8004FD7C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_80016620(rdram, ctx);
        goto after_13;
    // 0x8004FD7C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_13:
    // 0x8004FD80: jal         0x80016138
    // 0x8004FD84: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_14;
    // 0x8004FD84: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_14:
    // 0x8004FD88: beq         $v0, $zero, L_8004FDAC
    if (ctx->r2 == 0) {
        // 0x8004FD8C: nop
    
            goto L_8004FDAC;
    }
    // 0x8004FD8C: nop

L_8004FD90:
    // 0x8004FD90: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FD94: jal         0x800499B0
    // 0x8004FD98: nop

    func_800499B0(rdram, ctx);
        goto after_15;
    // 0x8004FD98: nop

    after_15:
    // 0x8004FD9C: jal         0x80016138
    // 0x8004FDA0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016138(rdram, ctx);
        goto after_16;
    // 0x8004FDA0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_16:
    // 0x8004FDA4: bne         $v0, $zero, L_8004FD90
    if (ctx->r2 != 0) {
        // 0x8004FDA8: nop
    
            goto L_8004FD90;
    }
    // 0x8004FDA8: nop

L_8004FDAC:
    // 0x8004FDAC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8004FDB0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_8004FDB4:
    // 0x8004FDB4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004FDB8: jal         0x800499B0
    // 0x8004FDBC: nop

    func_800499B0(rdram, ctx);
        goto after_17;
    // 0x8004FDBC: nop

    after_17:
    // 0x8004FDC0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8004FDC4: nop

    // 0x8004FDC8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8004FDCC: bne         $t9, $zero, L_8004FDB4
    if (ctx->r25 != 0) {
        // 0x8004FDD0: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_8004FDB4;
    }
    // 0x8004FDD0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8004FDD4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8004FDD8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x8004FDDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004FDE0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8004FDE4: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8004FDE8: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x8004FDEC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004FDF0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8004FDF4: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8004FDF8: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x8004FDFC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_8004FE00:
    // 0x8004FE00: b           L_8004FE08
    // 0x8004FE04: nop

        goto L_8004FE08;
    // 0x8004FE04: nop

L_8004FE08:
    // 0x8004FE08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004FE0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004FE10: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8004FE14: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004FE18: jr          $ra
    // 0x8004FE1C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8004FE1C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Thread_StopThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0D34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0D40: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0D44: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0D48: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0D4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0D50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0D54: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0D58: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0D5C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0D60: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0D64: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0D68: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0D6C: nop

    // 0x800C0D70: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0D74: bne         $t9, $zero, L_800C0D84
    if (ctx->r25 != 0) {
        // 0x800C0D78: nop
    
            goto L_800C0D84;
    }
    // 0x800C0D78: nop

    // 0x800C0D7C: b           L_800C0DCC
    // 0x800C0D80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0DCC;
    // 0x800C0D80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0D84:
    // 0x800C0D84: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0D88: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C0D8C: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C0D90: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0D94: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C0D98: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C0D9C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C0DA0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0DA4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C0DA8: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C0DAC: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C0DB0: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C0DB4: jal         0x800CB940
    // 0x800C0DB8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C0DB8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x800C0DBC: b           L_800C0DCC
    // 0x800C0DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0DCC;
    // 0x800C0DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0DC4: b           L_800C0DCC
    // 0x800C0DC8: nop

        goto L_800C0DCC;
    // 0x800C0DC8: nop

L_800C0DCC:
    // 0x800C0DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0DD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0DD4: jr          $ra
    // 0x800C0DD8: nop

    return;
    // 0x800C0DD8: nop

;}
RECOMP_FUNC void func_800662DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800662E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800662E4: jal         0x80061348
    // 0x800662E8: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800662E8: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x800662EC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800662F0: b           L_80066300
    // 0x800662F4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066300;
    // 0x800662F4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800662F8: b           L_80066300
    // 0x800662FC: nop

        goto L_80066300;
    // 0x800662FC: nop

L_80066300:
    // 0x80066300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066308: jr          $ra
    // 0x8006630C: nop

    return;
    // 0x8006630C: nop

;}
RECOMP_FUNC void func_8007B12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B12C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8007B130: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8007B134: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8007B138: nop

    // 0x8007B13C: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x8007B140: nop

    // 0x8007B144: bne         $t7, $zero, L_8007B16C
    if (ctx->r15 != 0) {
        // 0x8007B148: nop
    
            goto L_8007B16C;
    }
    // 0x8007B148: nop

    // 0x8007B14C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8007B150: lh          $t8, 0x713A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X713A);
    // 0x8007B154: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007B158: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8007B15C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8007B160: sh          $t9, 0x713A($at)
    MEM_H(0X713A, ctx->r1) = ctx->r25;
    // 0x8007B164: b           L_8007B3D4
    // 0x8007B168: nop

        goto L_8007B3D4;
    // 0x8007B168: nop

L_8007B16C:
    // 0x8007B16C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8007B170: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8007B174: lh          $t3, 0x7132($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7132);
    // 0x8007B178: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8007B17C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8007B180: lw          $t2, 0x144($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X144);
    // 0x8007B184: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8007B188: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8007B18C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8007B190: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8007B194: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8007B198: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x8007B19C: addiu       $t9, $t9, 0x70F0
    ctx->r25 = ADD32(ctx->r25, 0X70F0);
    // 0x8007B1A0: sh          $t8, 0x3C($t9)
    MEM_H(0X3C, ctx->r25) = ctx->r24;
    // 0x8007B1A4: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8007B1A8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8007B1AC: lh          $t3, 0xE($t1)
    ctx->r11 = MEM_H(ctx->r9, 0XE);
    // 0x8007B1B0: addiu       $t4, $t4, 0x70F0
    ctx->r12 = ADD32(ctx->r12, 0X70F0);
    // 0x8007B1B4: sh          $t3, 0x3E($t4)
    MEM_H(0X3E, ctx->r12) = ctx->r11;
    // 0x8007B1B8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007B1BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007B1C0: beq         $t0, $at, L_8007B1DC
    if (ctx->r8 == ctx->r1) {
        // 0x8007B1C4: nop
    
            goto L_8007B1DC;
    }
    // 0x8007B1C4: nop

    // 0x8007B1C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007B1CC: beq         $t0, $at, L_8007B25C
    if (ctx->r8 == ctx->r1) {
        // 0x8007B1D0: nop
    
            goto L_8007B25C;
    }
    // 0x8007B1D0: nop

    // 0x8007B1D4: b           L_8007B2DC
    // 0x8007B1D8: nop

        goto L_8007B2DC;
    // 0x8007B1D8: nop

L_8007B1DC:
    // 0x8007B1DC: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8007B1E0: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007B1E4: lh          $t5, 0xC($t2)
    ctx->r13 = MEM_H(ctx->r10, 0XC);
    // 0x8007B1E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007B1EC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8007B1F0: nop

    // 0x8007B1F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007B1F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007B1FC: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8007B200: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007B204: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x8007B208: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8007B20C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8007B210: lh          $t7, 0xE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XE);
    // 0x8007B214: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007B218: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8007B21C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007B220: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007B224: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8007B228: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8007B22C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8007B230: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x8007B234: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007B23C: nop

    // 0x8007B240: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x8007B244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B248: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007B24C: nop

    // 0x8007B250: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x8007B254: b           L_8007B3CC
    // 0x8007B258: nop

        goto L_8007B3CC;
    // 0x8007B258: nop

L_8007B25C:
    // 0x8007B25C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8007B260: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8007B264: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8007B268: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007B26C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8007B270: nop

    // 0x8007B274: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B278: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8007B27C: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8007B280: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007B284: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8007B288: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8007B28C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8007B290: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x8007B294: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007B298: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8007B29C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007B2A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B2A4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8007B2A8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8007B2AC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8007B2B0: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8007B2B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B2B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007B2BC: nop

    // 0x8007B2C0: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x8007B2C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B2C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B2CC: nop

    // 0x8007B2D0: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8007B2D4: b           L_8007B3CC
    // 0x8007B2D8: nop

        goto L_8007B3CC;
    // 0x8007B2D8: nop

L_8007B2DC:
    // 0x8007B2DC: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x8007B2E0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8007B2E4: lh          $t2, 0x0($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X0);
    // 0x8007B2E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007B2EC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8007B2F0: nop

    // 0x8007B2F4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007B2F8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8007B2FC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8007B300: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007B304: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8007B308: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8007B30C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8007B310: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8007B314: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8007B318: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8007B31C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007B320: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007B324: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8007B328: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8007B32C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8007B330: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8007B334: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8007B338: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8007B33C: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8007B340: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x8007B344: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8007B348: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8007B34C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007B350: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007B354: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007B358: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8007B35C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x8007B360: c.le.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d <= ctx->f10.d;
    // 0x8007B364: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
    // 0x8007B368: bc1f        L_8007B380
    if (!c1cs) {
        // 0x8007B36C: nop
    
            goto L_8007B380;
    }
    // 0x8007B36C: nop

    // 0x8007B370: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B374: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007B378: nop

    // 0x8007B37C: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
L_8007B380:
    // 0x8007B380: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x8007B384: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8007B388: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x8007B38C: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x8007B390: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8007B394: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8007B398: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007B39C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8007B3A0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007B3A4: sub.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8007B3A8: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x8007B3AC: c.le.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d <= ctx->f16.d;
    // 0x8007B3B0: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
    // 0x8007B3B4: bc1f        L_8007B3CC
    if (!c1cs) {
        // 0x8007B3B8: nop
    
            goto L_8007B3CC;
    }
    // 0x8007B3B8: nop

    // 0x8007B3BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007B3C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007B3C4: nop

    // 0x8007B3C8: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_8007B3CC:
    // 0x8007B3CC: b           L_8007B3D4
    // 0x8007B3D0: nop

        goto L_8007B3D4;
    // 0x8007B3D0: nop

L_8007B3D4:
    // 0x8007B3D4: jr          $ra
    // 0x8007B3D8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8007B3D8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80057528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057528: jr          $ra
    // 0x8005752C: nop

    return;
    // 0x8005752C: nop

    // 0x80057530: jr          $ra
    // 0x80057534: nop

    return;
    // 0x80057534: nop

;}
RECOMP_FUNC void func_800A4074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4074: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800A4078: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A407C: lw          $t6, -0x73AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73AC);
    // 0x800A4080: nop

    // 0x800A4084: bne         $t6, $zero, L_800A4098
    if (ctx->r14 != 0) {
        // 0x800A4088: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800A4098;
    }
    // 0x800A4088: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800A408C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A4090: b           L_800A40F4
    // 0x800A4094: sw          $a0, -0x73AC($at)
    MEM_W(-0X73AC, ctx->r1) = ctx->r4;
        goto L_800A40F4;
    // 0x800A4094: sw          $a0, -0x73AC($at)
    MEM_W(-0X73AC, ctx->r1) = ctx->r4;
L_800A4098:
    // 0x800A4098: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800A409C: nop

    // 0x800A40A0: lw          $t8, 0x14C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14C);
    // 0x800A40A4: nop

    // 0x800A40A8: beq         $t8, $zero, L_800A40DC
    if (ctx->r24 == 0) {
        // 0x800A40AC: nop
    
            goto L_800A40DC;
    }
    // 0x800A40AC: nop

L_800A40B0:
    // 0x800A40B0: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800A40B4: nop

    // 0x800A40B8: lw          $t0, 0x14C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14C);
    // 0x800A40BC: nop

    // 0x800A40C0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800A40C4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800A40C8: nop

    // 0x800A40CC: lw          $t2, 0x14C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14C);
    // 0x800A40D0: nop

    // 0x800A40D4: bne         $t2, $zero, L_800A40B0
    if (ctx->r10 != 0) {
        // 0x800A40D8: nop
    
            goto L_800A40B0;
    }
    // 0x800A40D8: nop

L_800A40DC:
    // 0x800A40DC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800A40E0: nop

    // 0x800A40E4: sw          $a0, 0x14C($t3)
    MEM_W(0X14C, ctx->r11) = ctx->r4;
    // 0x800A40E8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800A40EC: nop

    // 0x800A40F0: sw          $t4, 0x148($a0)
    MEM_W(0X148, ctx->r4) = ctx->r12;
L_800A40F4:
    // 0x800A40F4: b           L_800A40FC
    // 0x800A40F8: nop

        goto L_800A40FC;
    // 0x800A40F8: nop

L_800A40FC:
    // 0x800A40FC: jr          $ra
    // 0x800A4100: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800A4100: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8007471C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007471C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074724: jal         0x80061348
    // 0x80074728: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074728: addiu       $a0, $zero, 0x4D7
    ctx->r4 = ADD32(0, 0X4D7);
    after_0:
    // 0x8007472C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074730: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074734: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074738: beq         $v0, $zero, L_8007478C
    if (ctx->r2 == 0) {
        // 0x8007473C: nop
    
            goto L_8007478C;
    }
    // 0x8007473C: nop

    // 0x80074740: jal         0x80061348
    // 0x80074744: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074744: addiu       $a0, $zero, 0x4D8
    ctx->r4 = ADD32(0, 0X4D8);
    after_1:
    // 0x80074748: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007474C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074754: beq         $v0, $zero, L_8007478C
    if (ctx->r2 == 0) {
        // 0x80074758: nop
    
            goto L_8007478C;
    }
    // 0x80074758: nop

    // 0x8007475C: jal         0x80061348
    // 0x80074760: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074760: addiu       $a0, $zero, 0x4D9
    ctx->r4 = ADD32(0, 0X4D9);
    after_2:
    // 0x80074764: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074768: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8007476C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074770: beq         $v0, $zero, L_8007478C
    if (ctx->r2 == 0) {
        // 0x80074774: nop
    
            goto L_8007478C;
    }
    // 0x80074774: nop

    // 0x80074778: jal         0x80061348
    // 0x8007477C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8007477C: addiu       $a0, $zero, 0x4DA
    ctx->r4 = ADD32(0, 0X4DA);
    after_3:
    // 0x80074780: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074784: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074788: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007478C:
    // 0x8007478C: b           L_8007479C
    // 0x80074790: nop

        goto L_8007479C;
    // 0x80074790: nop

    // 0x80074794: b           L_8007479C
    // 0x80074798: nop

        goto L_8007479C;
    // 0x80074798: nop

L_8007479C:
    // 0x8007479C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800747A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800747A4: jr          $ra
    // 0x800747A8: nop

    return;
    // 0x800747A8: nop

;}
RECOMP_FUNC void ContPak_OpenFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE904: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AE908: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AE90C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE910: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE914: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800AE918: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE91C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE920: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE924: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE928: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE92C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE930: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x800AE934: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AE938: jal         0x800AE40C
    // 0x800AE93C: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_0;
    // 0x800AE93C: nop

    after_0:
    // 0x800AE940: bgez        $v0, L_800AE968
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AE944: nop
    
            goto L_800AE968;
    }
    // 0x800AE944: nop

    // 0x800AE948: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE94C: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x800AE950: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800AE954: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AE958: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE95C: sw          $t1, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r9;
    // 0x800AE960: b           L_800AE9FC
    // 0x800AE964: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE9FC;
    // 0x800AE964: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE968:
    // 0x800AE968: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800AE96C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE970: lw          $t3, 0x1674($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1674);
    // 0x800AE974: lw          $t2, 0x1660($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1660);
    // 0x800AE978: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE97C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800AE980: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800AE984: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AE988: addiu       $t4, $t4, 0x167C
    ctx->r12 = ADD32(ctx->r12, 0X167C);
    // 0x800AE98C: lw          $a3, 0x1654($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1654);
    // 0x800AE990: lw          $a2, 0x164C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X164C);
    // 0x800AE994: lhu         $a1, 0x1646($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X1646);
    // 0x800AE998: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE99C: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AE9A0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800AE9A4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AE9A8: jal         0x800AE01C
    // 0x800AE9AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    ContPak_GetPfsFile(rdram, ctx);
        goto after_1;
    // 0x800AE9AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x800AE9B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE9B4: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AE9B8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE9BC: lw          $t5, 0x1684($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1684);
    // 0x800AE9C0: nop

    // 0x800AE9C4: bne         $t5, $zero, L_800AE9D4
    if (ctx->r13 != 0) {
        // 0x800AE9C8: nop
    
            goto L_800AE9D4;
    }
    // 0x800AE9C8: nop

    // 0x800AE9CC: jal         0x800AE40C
    // 0x800AE9D0: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_2;
    // 0x800AE9D0: nop

    after_2:
L_800AE9D4:
    // 0x800AE9D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE9D8: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x800AE9DC: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800AE9E0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE9E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE9E8: sw          $t7, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r15;
    // 0x800AE9EC: b           L_800AE9FC
    // 0x800AE9F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE9FC;
    // 0x800AE9F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE9F4: b           L_800AE9FC
    // 0x800AE9F8: nop

        goto L_800AE9FC;
    // 0x800AE9F8: nop

L_800AE9FC:
    // 0x800AE9FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AEA00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800AEA04: jr          $ra
    // 0x800AEA08: nop

    return;
    // 0x800AEA08: nop

;}
RECOMP_FUNC void func_80074024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007402C: jal         0x80061348
    // 0x80074030: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074030: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x80074034: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074038: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007403C: b           L_8007404C
    // 0x80074040: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007404C;
    // 0x80074040: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074044: b           L_8007404C
    // 0x80074048: nop

        goto L_8007404C;
    // 0x80074048: nop

L_8007404C:
    // 0x8007404C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074054: jr          $ra
    // 0x80074058: nop

    return;
    // 0x80074058: nop

;}
RECOMP_FUNC void func_80067D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D3C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067D40: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067D44: nop

    // 0x80067D48: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x80067D4C: nop

    // 0x80067D50: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067D54: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067D58: jr          $ra
    // 0x80067D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067D5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067D60: jr          $ra
    // 0x80067D64: nop

    return;
    // 0x80067D64: nop

    // 0x80067D68: jr          $ra
    // 0x80067D6C: nop

    return;
    // 0x80067D6C: nop

;}
