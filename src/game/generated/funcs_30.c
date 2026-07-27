#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void AudioDriver_InitSeqPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9890: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B9894: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B9898: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x800B989C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B98A0: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800B98A4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800B98A8: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800B98AC: sb          $t8, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r24;
    // 0x800B98B0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800B98B4: addiu       $t9, $t9, -0x3078
    ctx->r25 = ADD32(ctx->r25, -0X3078);
    // 0x800B98B8: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800B98BC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800B98C0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800B98C4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800B98C8: jal         0x800BC4CC
    // 0x800B98CC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    AudioDriver_SetupOsc(rdram, ctx);
        goto after_0;
    // 0x800B98CC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800B98D0: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800B98D4: sb          $t0, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r8;
    // 0x800B98D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B98DC: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B98E0: addiu       $t1, $zero, 0x7C
    ctx->r9 = ADD32(0, 0X7C);
    // 0x800B98E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800B98E8: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B98EC: addiu       $a0, $a0, -0x340
    ctx->r4 = ADD32(ctx->r4, -0X340);
    // 0x800B98F0: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x800B98F4: jal         0x800C7950
    // 0x800B98F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800B98F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800B98FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9900: sw          $v0, -0x17DC($at)
    MEM_W(-0X17DC, ctx->r1) = ctx->r2;
    // 0x800B9904: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B9908: lw          $a0, -0x17DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X17DC);
    // 0x800B990C: jal         0x800C95F0
    // 0x800B9910: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    alCSPNew(rdram, ctx);
        goto after_2;
    // 0x800B9910: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x800B9914: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9918: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B991C: addiu       $t2, $zero, 0x3000
    ctx->r10 = ADD32(0, 0X3000);
    // 0x800B9920: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800B9924: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9928: addiu       $a0, $a0, -0x330
    ctx->r4 = ADD32(ctx->r4, -0X330);
    // 0x800B992C: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x800B9930: jal         0x800C7950
    // 0x800B9934: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800B9934: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x800B9938: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B993C: sw          $v0, -0x17D4($at)
    MEM_W(-0X17D4, ctx->r1) = ctx->r2;
    // 0x800B9940: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B9944: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x800B9948: addiu       $t3, $zero, 0xF8
    ctx->r11 = ADD32(0, 0XF8);
    // 0x800B994C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800B9950: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x800B9954: addiu       $a0, $a0, -0x320
    ctx->r4 = ADD32(ctx->r4, -0X320);
    // 0x800B9958: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x800B995C: jal         0x800C7950
    // 0x800B9960: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x800B9960: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x800B9964: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9968: sw          $v0, -0x17D8($at)
    MEM_W(-0X17D8, ctx->r1) = ctx->r2;
    // 0x800B996C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B9970: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9974: sw          $t4, -0x17C8($at)
    MEM_W(-0X17C8, ctx->r1) = ctx->r12;
    // 0x800B9978: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B997C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B9980: sw          $t5, -0x7310($at)
    MEM_W(-0X7310, ctx->r1) = ctx->r13;
    // 0x800B9984: addiu       $t6, $zero, 0x7FFF
    ctx->r14 = ADD32(0, 0X7FFF);
    // 0x800B9988: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B998C: sw          $t6, -0x17C0($at)
    MEM_W(-0X17C0, ctx->r1) = ctx->r14;
    // 0x800B9990: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B9994: sw          $zero, -0x17BC($at)
    MEM_W(-0X17BC, ctx->r1) = 0;
    // 0x800B9998: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x800B999C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B99A0: sw          $t7, -0x17B4($at)
    MEM_W(-0X17B4, ctx->r1) = ctx->r15;
    // 0x800B99A4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B99A8: sw          $zero, -0x17B8($at)
    MEM_W(-0X17B8, ctx->r1) = 0;
    // 0x800B99AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B99B0: sw          $zero, -0x7308($at)
    MEM_W(-0X7308, ctx->r1) = 0;
    // 0x800B99B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B99B8: sw          $zero, -0x7304($at)
    MEM_W(-0X7304, ctx->r1) = 0;
    // 0x800B99BC: b           L_800B99C4
    // 0x800B99C0: nop

        goto L_800B99C4;
    // 0x800B99C0: nop

L_800B99C4:
    // 0x800B99C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B99C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B99CC: jr          $ra
    // 0x800B99D0: nop

    return;
    // 0x800B99D0: nop

;}
RECOMP_FUNC void func_8006CF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CF88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CF8C: nop

    // 0x8006CF90: lh          $v0, 0x26($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X26);
    // 0x8006CF94: nop

    // 0x8006CF98: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CF9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CFA0: jr          $ra
    // 0x8006CFA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CFA4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CFA8: jr          $ra
    // 0x8006CFAC: nop

    return;
    // 0x8006CFAC: nop

    // 0x8006CFB0: jr          $ra
    // 0x8006CFB4: nop

    return;
    // 0x8006CFB4: nop

;}
RECOMP_FUNC void func_80029538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029538: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002953C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80029540: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80029544: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80029548: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8002954C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80029550: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80029554: sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // 0x80029558: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8002955C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80029560: lbu         $t7, 0x10($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X10);
    // 0x80029564: nop

    // 0x80029568: bne         $t7, $at, L_80029578
    if (ctx->r15 != ctx->r1) {
        // 0x8002956C: nop
    
            goto L_80029578;
    }
    // 0x8002956C: nop

    // 0x80029570: b           L_800296E8
    // 0x80029574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800296E8;
    // 0x80029574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029578:
    // 0x80029578: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8002957C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80029580: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x80029584: addiu       $t1, $t1, 0x24D8
    ctx->r9 = ADD32(ctx->r9, 0X24D8);
    // 0x80029588: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8002958C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80029590: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80029594: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x80029598: nop

    // 0x8002959C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800295A0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800295A4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800295A8: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800295AC: nop

    // 0x800295B0: bne         $t5, $at, L_800295E4
    if (ctx->r13 != ctx->r1) {
        // 0x800295B4: nop
    
            goto L_800295E4;
    }
    // 0x800295B4: nop

    // 0x800295B8: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x800295BC: addiu       $at, $zero, 0x164
    ctx->r1 = ADD32(0, 0X164);
    // 0x800295C0: bne         $t6, $at, L_800295E4
    if (ctx->r14 != ctx->r1) {
        // 0x800295C4: nop
    
            goto L_800295E4;
    }
    // 0x800295C4: nop

    // 0x800295C8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800295CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800295D0: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x800295D4: nop

    // 0x800295D8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800295DC: b           L_8002961C
    // 0x800295E0: sb          $t9, 0x3084($at)
    MEM_B(0X3084, ctx->r1) = ctx->r25;
        goto L_8002961C;
    // 0x800295E0: sb          $t9, 0x3084($at)
    MEM_B(0X3084, ctx->r1) = ctx->r25;
L_800295E4:
    // 0x800295E4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800295E8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800295EC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800295F0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800295F4: addiu       $s0, $zero, 0x0
    ctx->r16 = ADD32(0, 0X0);
    // 0x800295F8: addiu       $at, $zero, 0x0
    ctx->r1 = ADD32(0, 0X0);
    // 0x800295FC: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x80029600: xor         $s0, $s0, $t5
    ctx->r16 = ctx->r16 ^ ctx->r13;
    // 0x80029604: xor         $at, $at, $t4
    ctx->r1 = ctx->r1 ^ ctx->r12;
    // 0x80029608: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
    // 0x8002960C: sltiu       $s0, $s0, 0x1
    ctx->r16 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80029610: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029614: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80029618: sb          $s0, 0x3084($at)
    MEM_B(0X3084, ctx->r1) = ctx->r16;
L_8002961C:
    // 0x8002961C: lhu         $t1, 0x52($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X52);
    // 0x80029620: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80029624: beq         $t1, $at, L_800296E0
    if (ctx->r9 == ctx->r1) {
        // 0x80029628: nop
    
            goto L_800296E0;
    }
    // 0x80029628: nop

    // 0x8002962C: lhu         $t6, 0x52($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X52);
    // 0x80029630: nop

    // 0x80029634: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80029638: beq         $t7, $zero, L_80029648
    if (ctx->r15 == 0) {
        // 0x8002963C: nop
    
            goto L_80029648;
    }
    // 0x8002963C: nop

    // 0x80029640: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80029644: sh          $t8, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r24;
L_80029648:
    // 0x80029648: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8002964C: nop

    // 0x80029650: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80029654: nop

    // 0x80029658: sh          $t0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r8;
    // 0x8002965C: lhu         $t2, 0x52($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X52);
    // 0x80029660: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80029664: andi        $t3, $t2, 0x7FFF
    ctx->r11 = ctx->r10 & 0X7FFF;
    // 0x80029668: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x8002966C: lhu         $a0, 0x46($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X46);
    // 0x80029670: jal         0x800294D4
    // 0x80029674: nop

    func_800294D4(rdram, ctx);
        goto after_0;
    // 0x80029674: nop

    after_0:
    // 0x80029678: lhu         $t6, 0x46($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X46);
    // 0x8002967C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80029680: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80029684: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80029688: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8002968C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80029690: lbu         $t7, -0x471D($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X471D);
    // 0x80029694: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80029698: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002969C: lw          $a1, 0x1C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1C);
    // 0x800296A0: lbu         $t3, 0x3084($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3084);
    // 0x800296A4: lhu         $t4, 0x44($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X44);
    // 0x800296A8: sra         $t5, $s1, 16
    ctx->r13 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800296AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800296B0: lhu         $t0, 0x4E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4E);
    // 0x800296B4: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800296B8: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x800296BC: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x800296C0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800296C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800296C8: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800296CC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800296D0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800296D4: or          $a2, $t9, $t0
    ctx->r6 = ctx->r25 | ctx->r8;
    // 0x800296D8: jal         0x800B1F0C
    // 0x800296DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_1;
    // 0x800296DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
L_800296E0:
    // 0x800296E0: b           L_800296E8
    // 0x800296E4: nop

        goto L_800296E8;
    // 0x800296E4: nop

L_800296E8:
    // 0x800296E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800296EC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800296F0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800296F4: jr          $ra
    // 0x800296F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800296F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80063830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063838: jal         0x80061488
    // 0x8006383C: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006383C: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    after_0:
    // 0x80063840: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063844: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063848: b           L_80063858
    // 0x8006384C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063858;
    // 0x8006384C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063850: b           L_80063858
    // 0x80063854: nop

        goto L_80063858;
    // 0x80063854: nop

L_80063858:
    // 0x80063858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006385C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063860: jr          $ra
    // 0x80063864: nop

    return;
    // 0x80063864: nop

;}
RECOMP_FUNC void func_8004BA04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BA04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004BA08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004BA0C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004BA10: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004BA14: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8004BA18: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004BA1C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004BA20: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x8004BA24: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BA28: nop

    // 0x8004BA2C: bne         $t6, $t7, L_8004BA44
    if (ctx->r14 != ctx->r15) {
        // 0x8004BA30: nop
    
            goto L_8004BA44;
    }
    // 0x8004BA30: nop

    // 0x8004BA34: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004BA38: addiu       $t8, $t8, 0xEC8
    ctx->r24 = ADD32(ctx->r24, 0XEC8);
    // 0x8004BA3C: b           L_8004BA68
    // 0x8004BA40: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_8004BA68;
    // 0x8004BA40: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8004BA44:
    // 0x8004BA44: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BA48: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8004BA4C: lbu         $t0, 0x7E($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7E);
    // 0x8004BA50: addiu       $t2, $t2, 0xEF8
    ctx->r10 = ADD32(ctx->r10, 0XEF8);
    // 0x8004BA54: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8004BA58: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8004BA5C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8004BA60: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8004BA64: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_8004BA68:
    // 0x8004BA68: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BA6C: nop

    // 0x8004BA70: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x8004BA74: jal         0x800989BC
    // 0x8004BA78: nop

    func_800989BC(rdram, ctx);
        goto after_0;
    // 0x8004BA78: nop

    after_0:
    // 0x8004BA7C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8004BA80: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BA84: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BA88: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x8004BA8C: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    // 0x8004BA90: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8004BA94: addiu       $a1, $a1, -0x448C
    ctx->r5 = ADD32(ctx->r5, -0X448C);
    // 0x8004BA98: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004BA9C: jal         0x80049230
    // 0x8004BAA0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_80049230(rdram, ctx);
        goto after_1;
    // 0x8004BAA0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_1:
    // 0x8004BAA4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BAA8: nop

    // 0x8004BAAC: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x8004BAB0: jal         0x800C13B8
    // 0x8004BAB4: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_2;
    // 0x8004BAB4: nop

    after_2:
    // 0x8004BAB8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004BABC: lw          $t8, 0x6C4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6C4);
    // 0x8004BAC0: nop

    // 0x8004BAC4: beq         $t8, $zero, L_8004BB1C
    if (ctx->r24 == 0) {
        // 0x8004BAC8: nop
    
            goto L_8004BB1C;
    }
    // 0x8004BAC8: nop

L_8004BACC:
    // 0x8004BACC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BAD0: jal         0x80049544
    // 0x8004BAD4: nop

    func_80049544(rdram, ctx);
        goto after_3;
    // 0x8004BAD4: nop

    after_3:
    // 0x8004BAD8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BADC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8004BAE0: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8004BAE4: jal         0x800C143C
    // 0x8004BAE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_4;
    // 0x8004BAE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8004BAEC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8004BAF0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004BAF4: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8004BAF8: nop

    // 0x8004BAFC: bne         $t1, $at, L_8004BB0C
    if (ctx->r9 != ctx->r1) {
        // 0x8004BB00: nop
    
            goto L_8004BB0C;
    }
    // 0x8004BB00: nop

    // 0x8004BB04: b           L_8004BB14
    // 0x8004BB08: nop

        goto L_8004BB14;
    // 0x8004BB08: nop

L_8004BB0C:
    // 0x8004BB0C: b           L_8004BACC
    // 0x8004BB10: nop

        goto L_8004BACC;
    // 0x8004BB10: nop

L_8004BB14:
    // 0x8004BB14: b           L_8004BB28
    // 0x8004BB18: nop

        goto L_8004BB28;
    // 0x8004BB18: nop

L_8004BB1C:
    // 0x8004BB1C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BB20: jal         0x80032410
    // 0x8004BB24: nop

    func_80032410(rdram, ctx);
        goto after_5;
    // 0x8004BB24: nop

    after_5:
L_8004BB28:
    // 0x8004BB28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BB2C: jal         0x80049438
    // 0x8004BB30: nop

    func_80049438(rdram, ctx);
        goto after_6;
    // 0x8004BB30: nop

    after_6:
    // 0x8004BB34: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BB38: nop

    // 0x8004BB3C: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x8004BB40: jal         0x80098754
    // 0x8004BB44: nop

    func_80098754(rdram, ctx);
        goto after_7;
    // 0x8004BB44: nop

    after_7:
    // 0x8004BB48: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8004BB4C: nop

    // 0x8004BB50: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x8004BB54: jal         0x800C13B8
    // 0x8004BB58: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_8;
    // 0x8004BB58: nop

    after_8:
    // 0x8004BB5C: b           L_8004BB64
    // 0x8004BB60: nop

        goto L_8004BB64;
    // 0x8004BB60: nop

L_8004BB64:
    // 0x8004BB64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004BB68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004BB6C: jr          $ra
    // 0x8004BB70: nop

    return;
    // 0x8004BB70: nop

;}
RECOMP_FUNC void func_800701E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800701E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800701EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800701F0: jal         0x80061348
    // 0x800701F4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800701F4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800701F8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800701FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070200: beq         $v0, $zero, L_80070250
    if (ctx->r2 == 0) {
        // 0x80070204: nop
    
            goto L_80070250;
    }
    // 0x80070204: nop

    // 0x80070208: jal         0x80061348
    // 0x8007020C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007020C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070210: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070218: beq         $v0, $zero, L_80070250
    if (ctx->r2 == 0) {
        // 0x8007021C: nop
    
            goto L_80070250;
    }
    // 0x8007021C: nop

    // 0x80070220: jal         0x80061348
    // 0x80070224: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070224: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070228: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007022C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070230: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070234: beq         $v0, $zero, L_80070250
    if (ctx->r2 == 0) {
        // 0x80070238: nop
    
            goto L_80070250;
    }
    // 0x80070238: nop

    // 0x8007023C: jal         0x80061348
    // 0x80070240: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070240: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070244: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070248: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007024C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070250:
    // 0x80070250: b           L_80070260
    // 0x80070254: nop

        goto L_80070260;
    // 0x80070254: nop

    // 0x80070258: b           L_80070260
    // 0x8007025C: nop

        goto L_80070260;
    // 0x8007025C: nop

L_80070260:
    // 0x80070260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070268: jr          $ra
    // 0x8007026C: nop

    return;
    // 0x8007026C: nop

;}
RECOMP_FUNC void Thread_DestroyThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0B78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C0B7C: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0B80: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0B84: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0B88: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0B8C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0B90: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0B94: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0B98: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0B9C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0BA0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0BA4: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0BA8: nop

    // 0x800C0BAC: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0BB0: bne         $t9, $zero, L_800C0BC0
    if (ctx->r25 != 0) {
        // 0x800C0BB4: nop
    
            goto L_800C0BC0;
    }
    // 0x800C0BB4: nop

    // 0x800C0BB8: b           L_800C0C7C
    // 0x800C0BBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0C7C;
    // 0x800C0BBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C0BC0:
    // 0x800C0BC0: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0BC4: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x800C0BC8: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C0BCC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0BD0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C0BD4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C0BD8: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C0BDC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C0BE0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C0BE4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C0BE8: lbu         $t2, -0x63C8($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X63C8);
    // 0x800C0BEC: nop

    // 0x800C0BF0: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800C0BF4: beq         $t3, $zero, L_800C0C08
    if (ctx->r11 == 0) {
        // 0x800C0BF8: nop
    
            goto L_800C0C08;
    }
    // 0x800C0BF8: nop

    // 0x800C0BFC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0C00: jal         0x800989BC
    // 0x800C0C04: nop

    func_800989BC(rdram, ctx);
        goto after_0;
    // 0x800C0C04: nop

    after_0:
L_800C0C08:
    // 0x800C0C08: lbu         $t4, 0x1B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0C0C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C0C10: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x800C0C14: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C0C18: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800C0C1C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C0C20: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x800C0C24: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800C0C28: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800C0C2C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800C0C30: sb          $zero, -0x63C8($at)
    MEM_B(-0X63C8, ctx->r1) = 0;
    // 0x800C0C34: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C0C38: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C0C3C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0C40: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0C44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0C48: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0C4C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0C50: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0C54: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0C58: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C0C5C: addiu       $t9, $t9, 0x1950
    ctx->r25 = ADD32(ctx->r25, 0X1950);
    // 0x800C0C60: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800C0C64: jal         0x800CB840
    // 0x800C0C68: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    osDestroyThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800C0C68: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x800C0C6C: b           L_800C0C7C
    // 0x800C0C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0C7C;
    // 0x800C0C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0C74: b           L_800C0C7C
    // 0x800C0C78: nop

        goto L_800C0C7C;
    // 0x800C0C78: nop

L_800C0C7C:
    // 0x800C0C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0C84: jr          $ra
    // 0x800C0C88: nop

    return;
    // 0x800C0C88: nop

;}
RECOMP_FUNC void func_80023C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023C60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80023C64: lh          $t6, 0xFF6($t6)
    ctx->r14 = MEM_H(ctx->r14, 0XFF6);
    // 0x80023C68: nop

    // 0x80023C6C: beq         $t6, $zero, L_80023C88
    if (ctx->r14 == 0) {
        // 0x80023C70: nop
    
            goto L_80023C88;
    }
    // 0x80023C70: nop

    // 0x80023C74: addiu       $t7, $zero, 0x3E7
    ctx->r15 = ADD32(0, 0X3E7);
    // 0x80023C78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023C7C: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x80023C80: jr          $ra
    // 0x80023C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80023C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80023C88:
    // 0x80023C88: jr          $ra
    // 0x80023C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80023C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800B1C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1C10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B1C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B1C18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B1C1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B1C20: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B1C24: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B1C28: nop

    // 0x800B1C2C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B1C30: bltz        $t7, L_800B1CBC
    if (SIGNED(ctx->r15) < 0) {
        // 0x800B1C34: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_800B1CBC;
    }
    // 0x800B1C34: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_800B1C38:
    // 0x800B1C38: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1C3C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B1C40: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800B1C44: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B1C48: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B1C4C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800B1C50: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B1C54: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B1C58: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800B1C5C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800B1C60: sll         $t4, $t0, 6
    ctx->r12 = S32(ctx->r8 << 6);
    // 0x800B1C64: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x800B1C68: jal         0x800B1CD4
    // 0x800B1C6C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    func_800B1CD4(rdram, ctx);
        goto after_0;
    // 0x800B1C6C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_0:
    // 0x800B1C70: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800B1C74: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800B1C78: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B1C7C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B1C80: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B1C84: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B1C88: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800B1C8C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800B1C90: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B1C94: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800B1C98: sll         $t2, $t7, 6
    ctx->r10 = S32(ctx->r15 << 6);
    // 0x800B1C9C: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x800B1CA0: jal         0x800B1E58
    // 0x800B1CA4: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    func_800B1E58(rdram, ctx);
        goto after_1;
    // 0x800B1CA4: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800B1CA8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1CAC: nop

    // 0x800B1CB0: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x800B1CB4: bgez        $t3, L_800B1C38
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B1CB8: sw          $t3, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r11;
            goto L_800B1C38;
    }
    // 0x800B1CB8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_800B1CBC:
    // 0x800B1CBC: b           L_800B1CC4
    // 0x800B1CC0: nop

        goto L_800B1CC4;
    // 0x800B1CC0: nop

L_800B1CC4:
    // 0x800B1CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B1CC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B1CCC: jr          $ra
    // 0x800B1CD0: nop

    return;
    // 0x800B1CD0: nop

;}
RECOMP_FUNC void func_80074B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074B08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074B0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074B10: jal         0x80061348
    // 0x80074B14: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074B14: addiu       $a0, $zero, 0x4DB
    ctx->r4 = ADD32(0, 0X4DB);
    after_0:
    // 0x80074B18: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074B1C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074B20: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074B24: beq         $v0, $zero, L_80074B78
    if (ctx->r2 == 0) {
        // 0x80074B28: nop
    
            goto L_80074B78;
    }
    // 0x80074B28: nop

    // 0x80074B2C: jal         0x80061348
    // 0x80074B30: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074B30: addiu       $a0, $zero, 0x459
    ctx->r4 = ADD32(0, 0X459);
    after_1:
    // 0x80074B34: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80074B38: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074B3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074B40: beq         $v0, $zero, L_80074B78
    if (ctx->r2 == 0) {
        // 0x80074B44: nop
    
            goto L_80074B78;
    }
    // 0x80074B44: nop

    // 0x80074B48: jal         0x80061348
    // 0x80074B4C: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80074B4C: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    after_2:
    // 0x80074B50: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80074B54: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80074B58: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80074B5C: beq         $v0, $zero, L_80074B78
    if (ctx->r2 == 0) {
        // 0x80074B60: nop
    
            goto L_80074B78;
    }
    // 0x80074B60: nop

    // 0x80074B64: jal         0x80061348
    // 0x80074B68: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80074B68: addiu       $a0, $zero, 0x4DE
    ctx->r4 = ADD32(0, 0X4DE);
    after_3:
    // 0x80074B6C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80074B70: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80074B74: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80074B78:
    // 0x80074B78: b           L_80074B88
    // 0x80074B7C: nop

        goto L_80074B88;
    // 0x80074B7C: nop

    // 0x80074B80: b           L_80074B88
    // 0x80074B84: nop

        goto L_80074B88;
    // 0x80074B84: nop

L_80074B88:
    // 0x80074B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074B90: jr          $ra
    // 0x80074B94: nop

    return;
    // 0x80074B94: nop

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
RECOMP_FUNC void func_800655D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800655D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800655D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800655D8: nop

    // 0x800655DC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800655E0: nop

    // 0x800655E4: slti        $t7, $v0, 0x12D
    ctx->r15 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x800655E8: jr          $ra
    // 0x800655EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800655EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800655F0: jr          $ra
    // 0x800655F4: nop

    return;
    // 0x800655F4: nop

    // 0x800655F8: jr          $ra
    // 0x800655FC: nop

    return;
    // 0x800655FC: nop

;}
RECOMP_FUNC void func_80089BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BA4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80089BA8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80089BAC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80089BB0: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80089BB4: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80089BB8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80089BBC: nop

    // 0x80089BC0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80089BC4: nop

    // 0x80089BC8: andi        $t8, $t7, 0x100
    ctx->r24 = ctx->r15 & 0X100;
    // 0x80089BCC: beq         $t8, $zero, L_80089DE4
    if (ctx->r24 == 0) {
        // 0x80089BD0: nop
    
            goto L_80089DE4;
    }
    // 0x80089BD0: nop

    // 0x80089BD4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80089BD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80089BDC: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80089BE0: lwc1        $f4, 0xBE0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XBE0);
    // 0x80089BE4: lwc1        $f10, 0x740($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X740);
    // 0x80089BE8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80089BEC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80089BF0: swc1        $f16, 0x740($t9)
    MEM_W(0X740, ctx->r25) = ctx->f16.u32l;
    // 0x80089BF4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80089BF8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80089BFC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80089C00: lwc1        $f18, 0xBE0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XBE0);
    // 0x80089C04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80089C08: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80089C0C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80089C10: nop

    // 0x80089C14: bc1f        L_80089C58
    if (!c1cs) {
        // 0x80089C18: nop
    
            goto L_80089C58;
    }
    // 0x80089C18: nop

    // 0x80089C1C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80089C20: nop

    // 0x80089C24: lh          $t2, 0xBDA($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XBDA);
    // 0x80089C28: lwc1        $f10, 0x740($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X740);
    // 0x80089C2C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80089C30: nop

    // 0x80089C34: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80089C38: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80089C3C: nop

    // 0x80089C40: bc1f        L_80089C50
    if (!c1cs) {
        // 0x80089C44: nop
    
            goto L_80089C50;
    }
    // 0x80089C44: nop

    // 0x80089C48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80089C4C: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_80089C50:
    // 0x80089C50: b           L_80089C8C
    // 0x80089C54: nop

        goto L_80089C8C;
    // 0x80089C54: nop

L_80089C58:
    // 0x80089C58: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80089C5C: nop

    // 0x80089C60: lh          $t5, 0xBDA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XBDA);
    // 0x80089C64: lwc1        $f18, 0x740($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X740);
    // 0x80089C68: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80089C6C: nop

    // 0x80089C70: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80089C74: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x80089C78: nop

    // 0x80089C7C: bc1f        L_80089C8C
    if (!c1cs) {
        // 0x80089C80: nop
    
            goto L_80089C8C;
    }
    // 0x80089C80: nop

    // 0x80089C84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089C88: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80089C8C:
    // 0x80089C8C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80089C90: nop

    // 0x80089C94: beq         $t7, $zero, L_80089CBC
    if (ctx->r15 == 0) {
        // 0x80089C98: nop
    
            goto L_80089CBC;
    }
    // 0x80089C98: nop

    // 0x80089C9C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80089CA0: nop

    // 0x80089CA4: lh          $t9, 0xBDA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XBDA);
    // 0x80089CA8: nop

    // 0x80089CAC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80089CB0: nop

    // 0x80089CB4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80089CB8: swc1        $f10, 0x740($t8)
    MEM_W(0X740, ctx->r24) = ctx->f10.u32l;
L_80089CBC:
    // 0x80089CBC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80089CC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80089CC4: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80089CC8: lwc1        $f16, 0xBE4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XBE4);
    // 0x80089CCC: lwc1        $f6, 0x744($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X744);
    // 0x80089CD0: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80089CD4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80089CD8: swc1        $f8, 0x744($t0)
    MEM_W(0X744, ctx->r8) = ctx->f8.u32l;
    // 0x80089CDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80089CE0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80089CE4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80089CE8: lwc1        $f10, 0xBE4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XBE4);
    // 0x80089CEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80089CF0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80089CF4: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x80089CF8: nop

    // 0x80089CFC: bc1f        L_80089D40
    if (!c1cs) {
        // 0x80089D00: nop
    
            goto L_80089D40;
    }
    // 0x80089D00: nop

    // 0x80089D04: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80089D08: nop

    // 0x80089D0C: lh          $t3, 0xBDC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XBDC);
    // 0x80089D10: lwc1        $f6, 0x744($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X744);
    // 0x80089D14: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80089D18: nop

    // 0x80089D1C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80089D20: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80089D24: nop

    // 0x80089D28: bc1f        L_80089D38
    if (!c1cs) {
        // 0x80089D2C: nop
    
            goto L_80089D38;
    }
    // 0x80089D2C: nop

    // 0x80089D30: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80089D34: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80089D38:
    // 0x80089D38: b           L_80089D74
    // 0x80089D3C: nop

        goto L_80089D74;
    // 0x80089D3C: nop

L_80089D40:
    // 0x80089D40: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80089D44: nop

    // 0x80089D48: lh          $t6, 0xBDC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBDC);
    // 0x80089D4C: lwc1        $f10, 0x744($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X744);
    // 0x80089D50: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80089D54: nop

    // 0x80089D58: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80089D5C: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x80089D60: nop

    // 0x80089D64: bc1f        L_80089D74
    if (!c1cs) {
        // 0x80089D68: nop
    
            goto L_80089D74;
    }
    // 0x80089D68: nop

    // 0x80089D6C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089D70: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80089D74:
    // 0x80089D74: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80089D78: nop

    // 0x80089D7C: beq         $t9, $zero, L_80089DA4
    if (ctx->r25 == 0) {
        // 0x80089D80: nop
    
            goto L_80089DA4;
    }
    // 0x80089D80: nop

    // 0x80089D84: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80089D88: nop

    // 0x80089D8C: lh          $t0, 0xBDC($t8)
    ctx->r8 = MEM_H(ctx->r24, 0XBDC);
    // 0x80089D90: nop

    // 0x80089D94: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80089D98: nop

    // 0x80089D9C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80089DA0: swc1        $f6, 0x744($t8)
    MEM_W(0X744, ctx->r24) = ctx->f6.u32l;
L_80089DA4:
    // 0x80089DA4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80089DA8: nop

    // 0x80089DAC: beq         $t1, $zero, L_80089DDC
    if (ctx->r9 == 0) {
        // 0x80089DB0: nop
    
            goto L_80089DDC;
    }
    // 0x80089DB0: nop

    // 0x80089DB4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80089DB8: nop

    // 0x80089DBC: beq         $t2, $zero, L_80089DDC
    if (ctx->r10 == 0) {
        // 0x80089DC0: nop
    
            goto L_80089DDC;
    }
    // 0x80089DC0: nop

    // 0x80089DC4: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80089DC8: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x80089DCC: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80089DD0: nop

    // 0x80089DD4: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80089DD8: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
L_80089DDC:
    // 0x80089DDC: b           L_8008A06C
    // 0x80089DE0: nop

        goto L_8008A06C;
    // 0x80089DE0: nop

L_80089DE4:
    // 0x80089DE4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80089DE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80089DEC: lwc1        $f8, 0xC18($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC18);
    // 0x80089DF0: nop

    // 0x80089DF4: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80089DF8: nop

    // 0x80089DFC: bc1f        L_80089E0C
    if (!c1cs) {
        // 0x80089E00: nop
    
            goto L_80089E0C;
    }
    // 0x80089E00: nop

    // 0x80089E04: b           L_80089E20
    // 0x80089E08: mov.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = ctx->f8.fl;
        goto L_80089E20;
    // 0x80089E08: mov.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = ctx->f8.fl;
L_80089E0C:
    // 0x80089E0C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80089E10: nop

    // 0x80089E14: lwc1        $f20, 0xC18($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0XC18);
    // 0x80089E18: nop

    // 0x80089E1C: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80089E20:
    // 0x80089E20: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80089E24: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80089E28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80089E2C: cvt.d.s     $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.d = CVT_D_S(ctx->f20.fl);
    // 0x80089E30: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80089E34: nop

    // 0x80089E38: bc1f        L_80089F28
    if (!c1cs) {
        // 0x80089E3C: nop
    
            goto L_80089F28;
    }
    // 0x80089E3C: nop

    // 0x80089E40: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80089E44: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80089E48: lwc1        $f18, 0xC18($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC18);
    // 0x80089E4C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80089E50: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80089E54: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80089E58: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80089E5C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80089E60: lwc1        $f11, -0xA30($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0XA30);
    // 0x80089E64: lwc1        $f10, -0xA2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XA2C);
    // 0x80089E68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80089E6C: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80089E70: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80089E74: lwc1        $f8, 0x740($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X740);
    // 0x80089E78: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80089E7C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80089E80: mul.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80089E84: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80089E88: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80089E8C: swc1        $f4, 0x740($t9)
    MEM_W(0X740, ctx->r25) = ctx->f4.u32l;
    // 0x80089E90: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80089E94: nop

    // 0x80089E98: lh          $t8, 0x748($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X748);
    // 0x80089E9C: lwc1        $f6, 0x740($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X740);
    // 0x80089EA0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80089EA4: nop

    // 0x80089EA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80089EAC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80089EB0: nop

    // 0x80089EB4: bc1f        L_80089EDC
    if (!c1cs) {
        // 0x80089EB8: nop
    
            goto L_80089EDC;
    }
    // 0x80089EB8: nop

    // 0x80089EBC: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80089EC0: nop

    // 0x80089EC4: lh          $t2, 0x748($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X748);
    // 0x80089EC8: nop

    // 0x80089ECC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80089ED0: nop

    // 0x80089ED4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80089ED8: swc1        $f18, 0x740($t1)
    MEM_W(0X740, ctx->r9) = ctx->f18.u32l;
L_80089EDC:
    // 0x80089EDC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80089EE0: nop

    // 0x80089EE4: lh          $t5, 0x74C($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X74C);
    // 0x80089EE8: lwc1        $f4, 0x740($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X740);
    // 0x80089EEC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80089EF0: nop

    // 0x80089EF4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80089EF8: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80089EFC: nop

    // 0x80089F00: bc1f        L_80089F28
    if (!c1cs) {
        // 0x80089F04: nop
    
            goto L_80089F28;
    }
    // 0x80089F04: nop

    // 0x80089F08: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80089F0C: nop

    // 0x80089F10: lh          $t6, 0x74C($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X74C);
    // 0x80089F14: nop

    // 0x80089F18: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80089F1C: nop

    // 0x80089F20: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80089F24: swc1        $f16, 0x740($t3)
    MEM_W(0X740, ctx->r11) = ctx->f16.u32l;
L_80089F28:
    // 0x80089F28: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80089F2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80089F30: lwc1        $f18, 0xC1C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC1C);
    // 0x80089F34: nop

    // 0x80089F38: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80089F3C: nop

    // 0x80089F40: bc1f        L_80089F50
    if (!c1cs) {
        // 0x80089F44: nop
    
            goto L_80089F50;
    }
    // 0x80089F44: nop

    // 0x80089F48: b           L_80089F64
    // 0x80089F4C: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
        goto L_80089F64;
    // 0x80089F4C: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
L_80089F50:
    // 0x80089F50: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80089F54: nop

    // 0x80089F58: lwc1        $f20, 0xC1C($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XC1C);
    // 0x80089F5C: nop

    // 0x80089F60: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80089F64:
    // 0x80089F64: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80089F68: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80089F6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80089F70: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x80089F74: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80089F78: nop

    // 0x80089F7C: bc1f        L_8008A06C
    if (!c1cs) {
        // 0x80089F80: nop
    
            goto L_8008A06C;
    }
    // 0x80089F80: nop

    // 0x80089F84: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80089F88: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80089F8C: lwc1        $f10, 0xC1C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC1C);
    // 0x80089F90: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80089F94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80089F98: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80089F9C: mul.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80089FA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80089FA4: lwc1        $f5, -0xA28($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0XA28);
    // 0x80089FA8: lwc1        $f4, -0xA24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XA24);
    // 0x80089FAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80089FB0: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x80089FB4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80089FB8: lwc1        $f18, 0x744($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X744);
    // 0x80089FBC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80089FC0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80089FC4: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80089FC8: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80089FCC: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80089FD0: swc1        $f6, 0x744($t0)
    MEM_W(0X744, ctx->r8) = ctx->f6.u32l;
    // 0x80089FD4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80089FD8: nop

    // 0x80089FDC: lh          $t2, 0x74A($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X74A);
    // 0x80089FE0: lwc1        $f16, 0x744($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X744);
    // 0x80089FE4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80089FE8: nop

    // 0x80089FEC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80089FF0: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80089FF4: nop

    // 0x80089FF8: bc1f        L_8008A020
    if (!c1cs) {
        // 0x80089FFC: nop
    
            goto L_8008A020;
    }
    // 0x80089FFC: nop

    // 0x8008A000: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8008A004: nop

    // 0x8008A008: lh          $t4, 0x74A($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X74A);
    // 0x8008A00C: nop

    // 0x8008A010: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8008A014: nop

    // 0x8008A018: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008A01C: swc1        $f10, 0x744($t1)
    MEM_W(0X744, ctx->r9) = ctx->f10.u32l;
L_8008A020:
    // 0x8008A020: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008A024: nop

    // 0x8008A028: lh          $t6, 0x74E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X74E);
    // 0x8008A02C: lwc1        $f6, 0x744($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X744);
    // 0x8008A030: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8008A034: nop

    // 0x8008A038: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008A03C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8008A040: nop

    // 0x8008A044: bc1f        L_8008A06C
    if (!c1cs) {
        // 0x8008A048: nop
    
            goto L_8008A06C;
    }
    // 0x8008A048: nop

    // 0x8008A04C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8008A050: nop

    // 0x8008A054: lh          $t7, 0x74E($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X74E);
    // 0x8008A058: nop

    // 0x8008A05C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8008A060: nop

    // 0x8008A064: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008A068: swc1        $f8, 0x744($t3)
    MEM_W(0X744, ctx->r11) = ctx->f8.u32l;
L_8008A06C:
    // 0x8008A06C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8008A070: nop

    // 0x8008A074: lhu         $t0, 0xC20($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XC20);
    // 0x8008A078: nop

    // 0x8008A07C: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x8008A080: jal         0x80031AC8
    // 0x8008A084: nop

    func_80031AC8(rdram, ctx);
        goto after_0;
    // 0x8008A084: nop

    after_0:
    // 0x8008A088: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8008A08C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8008A090: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008A094: lh          $t2, 0x4($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X4);
    // 0x8008A098: lh          $t5, 0x73C($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X73C);
    // 0x8008A09C: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x8008A0A0: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x8008A0A4: lh          $t1, 0x4664($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X4664);
    // 0x8008A0A8: nop

    // 0x8008A0AC: beq         $t1, $t5, L_8008A0C4
    if (ctx->r9 == ctx->r13) {
        // 0x8008A0B0: nop
    
            goto L_8008A0C4;
    }
    // 0x8008A0B0: nop

    // 0x8008A0B4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A0B8: nop

    // 0x8008A0BC: bne         $t6, $zero, L_8008A118
    if (ctx->r14 != 0) {
        // 0x8008A0C0: nop
    
            goto L_8008A118;
    }
    // 0x8008A0C0: nop

L_8008A0C4:
    // 0x8008A0C4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8008A0C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008A0CC: lh          $t3, 0x4($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X4);
    // 0x8008A0D0: lh          $t2, 0x73C($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X73C);
    // 0x8008A0D4: sll         $t9, $t3, 3
    ctx->r25 = S32(ctx->r11 << 3);
    // 0x8008A0D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8008A0DC: lh          $t0, 0x4664($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X4664);
    // 0x8008A0E0: nop

    // 0x8008A0E4: bne         $t0, $t2, L_8008A0FC
    if (ctx->r8 != ctx->r10) {
        // 0x8008A0E8: nop
    
            goto L_8008A0FC;
    }
    // 0x8008A0E8: nop

    // 0x8008A0EC: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A0F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008A0F4: beq         $t4, $at, L_8008A118
    if (ctx->r12 == ctx->r1) {
        // 0x8008A0F8: nop
    
            goto L_8008A118;
    }
    // 0x8008A0F8: nop

L_8008A0FC:
    // 0x8008A0FC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8008A100: nop

    // 0x8008A104: lhu         $t1, 0x0($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X0);
    // 0x8008A108: nop

    // 0x8008A10C: andi        $t5, $t1, 0x100
    ctx->r13 = ctx->r9 & 0X100;
    // 0x8008A110: beq         $t5, $zero, L_8008A148
    if (ctx->r13 == 0) {
        // 0x8008A114: nop
    
            goto L_8008A148;
    }
    // 0x8008A114: nop

L_8008A118:
    // 0x8008A118: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008A11C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8008A120: lhu         $t3, 0xFF4($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XFF4);
    // 0x8008A124: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8008A128: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008A12C: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x8008A130: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x8008A134: lhu         $t4, 0x42($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X42);
    // 0x8008A138: or          $t0, $t9, $t7
    ctx->r8 = ctx->r25 | ctx->r15;
    // 0x8008A13C: nor         $t2, $t0, $zero
    ctx->r10 = ~(ctx->r8 | 0);
    // 0x8008A140: and         $t8, $t4, $t2
    ctx->r24 = ctx->r12 & ctx->r10;
    // 0x8008A144: sh          $t8, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r24;
L_8008A148:
    // 0x8008A148: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8008A14C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008A150: lhu         $t5, 0xFF4($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XFF4);
    // 0x8008A154: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x8008A158: lhu         $t3, 0x42($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X42);
    // 0x8008A15C: or          $t6, $t1, $t5
    ctx->r14 = ctx->r9 | ctx->r13;
    // 0x8008A160: and         $t9, $t3, $t6
    ctx->r25 = ctx->r11 & ctx->r14;
    // 0x8008A164: beq         $t9, $zero, L_8008A1A4
    if (ctx->r25 == 0) {
        // 0x8008A168: nop
    
            goto L_8008A1A4;
    }
    // 0x8008A168: nop

    // 0x8008A16C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8008A170: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x8008A174: lwc1        $f10, 0x740($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X740);
    // 0x8008A178: ori         $a2, $a2, 0x22A
    ctx->r6 = ctx->r6 | 0X22A;
    // 0x8008A17C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8008A180: lwc1        $f18, 0x744($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X744);
    // 0x8008A184: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008A188: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8008A18C: addiu       $a0, $t7, 0x3C
    ctx->r4 = ADD32(ctx->r15, 0X3C);
    // 0x8008A190: addiu       $a1, $t7, 0x40
    ctx->r5 = ADD32(ctx->r15, 0X40);
    // 0x8008A194: jal         0x800B202C
    // 0x8008A198: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B202C(rdram, ctx);
        goto after_1;
    // 0x8008A198: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8008A19C: b           L_8008A200
    // 0x8008A1A0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
        goto L_8008A200;
    // 0x8008A1A0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_8008A1A4:
    // 0x8008A1A4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8008A1A8: nop

    // 0x8008A1AC: addiu       $a0, $t0, 0x3C
    ctx->r4 = ADD32(ctx->r8, 0X3C);
    // 0x8008A1B0: jal         0x800B2748
    // 0x8008A1B4: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    func_800B2748(rdram, ctx);
        goto after_2;
    // 0x8008A1B4: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    after_2:
    // 0x8008A1B8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8008A1BC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8008A1C0: nop

    // 0x8008A1C4: bgez        $t4, L_8008A200
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8008A1C8: nop
    
            goto L_8008A200;
    }
    // 0x8008A1C8: nop

    // 0x8008A1CC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8008A1D0: lui         $a2, 0x71
    ctx->r6 = S32(0X71 << 16);
    // 0x8008A1D4: lwc1        $f6, 0x740($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X740);
    // 0x8008A1D8: ori         $a2, $a2, 0x229
    ctx->r6 = ctx->r6 | 0X229;
    // 0x8008A1DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8008A1E0: lwc1        $f16, 0x744($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X744);
    // 0x8008A1E4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008A1E8: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8008A1EC: addiu       $a0, $t2, 0x3C
    ctx->r4 = ADD32(ctx->r10, 0X3C);
    // 0x8008A1F0: addiu       $a1, $t2, 0x40
    ctx->r5 = ADD32(ctx->r10, 0X40);
    // 0x8008A1F4: jal         0x800B202C
    // 0x8008A1F8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B202C(rdram, ctx);
        goto after_3;
    // 0x8008A1F8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8008A1FC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_8008A200:
    // 0x8008A200: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8008A204: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8008A208: nop

    // 0x8008A20C: sh          $t8, 0x46($t1)
    MEM_H(0X46, ctx->r9) = ctx->r24;
    // 0x8008A210: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008A214: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8008A218: lw          $t3, 0x3C($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X3C);
    // 0x8008A21C: nop

    // 0x8008A220: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8008A224: lhu         $t6, 0x44($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X44);
    // 0x8008A228: nop

    // 0x8008A22C: blez        $t6, L_8008A28C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8008A230: nop
    
            goto L_8008A28C;
    }
    // 0x8008A230: nop

L_8008A234:
    // 0x8008A234: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8008A238: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8008A23C: lwc1        $f4, 0x740($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X740);
    // 0x8008A240: nop

    // 0x8008A244: swc1        $f4, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f4.u32l;
    // 0x8008A248: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8008A24C: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8008A250: lwc1        $f8, 0x744($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X744);
    // 0x8008A254: nop

    // 0x8008A258: swc1        $f8, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f8.u32l;
    // 0x8008A25C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8008A260: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x8008A264: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008A268: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8008A26C: addiu       $t3, $t1, 0x160
    ctx->r11 = ADD32(ctx->r9, 0X160);
    // 0x8008A270: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8008A274: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x8008A278: lhu         $t6, 0x44($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X44);
    // 0x8008A27C: nop

    // 0x8008A280: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8008A284: bne         $at, $zero, L_8008A234
    if (ctx->r1 != 0) {
        // 0x8008A288: nop
    
            goto L_8008A234;
    }
    // 0x8008A288: nop

L_8008A28C:
    // 0x8008A28C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8008A290: jal         0x8008A518
    // 0x8008A294: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_8008A518(rdram, ctx);
        goto after_4;
    // 0x8008A294: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x8008A298: beq         $v0, $zero, L_8008A328
    if (ctx->r2 == 0) {
        // 0x8008A29C: nop
    
            goto L_8008A328;
    }
    // 0x8008A29C: nop

    // 0x8008A2A0: lhu         $t9, 0x4E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X4E);
    // 0x8008A2A4: nop

    // 0x8008A2A8: andi        $t7, $t9, 0x2
    ctx->r15 = ctx->r25 & 0X2;
    // 0x8008A2AC: bne         $t7, $zero, L_8008A328
    if (ctx->r15 != 0) {
        // 0x8008A2B0: nop
    
            goto L_8008A328;
    }
    // 0x8008A2B0: nop

    // 0x8008A2B4: lh          $t0, 0x46($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X46);
    // 0x8008A2B8: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8008A2BC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8008A2C0: nop

    // 0x8008A2C4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008A2C8: swc1        $f18, 0x114($t4)
    MEM_W(0X114, ctx->r12) = ctx->f18.u32l;
    // 0x8008A2CC: lh          $t2, 0x48($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X48);
    // 0x8008A2D0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8008A2D4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8008A2D8: nop

    // 0x8008A2DC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008A2E0: swc1        $f16, 0x118($t1)
    MEM_W(0X118, ctx->r9) = ctx->f16.u32l;
    // 0x8008A2E4: lh          $t3, 0x4A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X4A);
    // 0x8008A2E8: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x8008A2EC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8008A2F0: subu        $t8, $t3, $t5
    ctx->r24 = SUB32(ctx->r11, ctx->r13);
    // 0x8008A2F4: sh          $t8, 0x148($t6)
    MEM_H(0X148, ctx->r14) = ctx->r24;
    // 0x8008A2F8: lh          $t9, 0x4C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4C);
    // 0x8008A2FC: lh          $t7, 0x48($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X48);
    // 0x8008A300: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8008A304: subu        $t0, $t9, $t7
    ctx->r8 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A308: sh          $t0, 0x14A($t4)
    MEM_H(0X14A, ctx->r12) = ctx->r8;
    // 0x8008A30C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8008A310: nop

    // 0x8008A314: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x8008A318: nop

    // 0x8008A31C: ori         $t3, $t1, 0x4
    ctx->r11 = ctx->r9 | 0X4;
    // 0x8008A320: b           L_8008A340
    // 0x8008A324: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
        goto L_8008A340;
    // 0x8008A324: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
L_8008A328:
    // 0x8008A328: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8008A32C: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8008A330: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x8008A334: nop

    // 0x8008A338: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x8008A33C: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_8008A340:
    // 0x8008A340: lhu         $v0, 0x42($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X42);
    // 0x8008A344: b           L_8008A354
    // 0x8008A348: nop

        goto L_8008A354;
    // 0x8008A348: nop

    // 0x8008A34C: b           L_8008A354
    // 0x8008A350: nop

        goto L_8008A354;
    // 0x8008A350: nop

L_8008A354:
    // 0x8008A354: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A358: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8008A35C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8008A360: jr          $ra
    // 0x8008A364: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008A364: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _filterBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5778: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D577C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5780: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800D5784: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800D5788: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800D578C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800D5790: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800D5794: lui         $t2, 0xB00
    ctx->r10 = S32(0XB00 << 16);
    // 0x800D5798: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x800D579C: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x800D57A0: ori         $t2, $t2, 0x20
    ctx->r10 = ctx->r10 | 0X20;
    // 0x800D57A4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D57A8: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800D57AC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800D57B0: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x800D57B4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800D57B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D57BC: jal         0x800C79C0
    // 0x800D57C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800D57C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800D57C4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800D57C8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D57CC: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x800D57D0: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x800D57D4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800D57D8: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x800D57DC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D57E0: lw          $t4, 0x2C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X2C);
    // 0x800D57E4: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x800D57E8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800D57EC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800D57F0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800D57F4: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D57F8: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x800D57FC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800D5800: lw          $a0, 0x28($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X28);
    // 0x800D5804: jal         0x800C79C0
    // 0x800D5808: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800D5808: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x800D580C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800D5810: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D5814: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800D5818: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x800D581C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5820: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800D5824: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D5828: jr          $ra
    // 0x800D582C: nop

    return;
    // 0x800D582C: nop

;}
RECOMP_FUNC void func_80086B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80086B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086B8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80086B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086B94: jal         0x8008A46C
    // 0x80086B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008A46C(rdram, ctx);
        goto after_0;
    // 0x80086B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80086B9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086BA0: jal         0x8008A46C
    // 0x80086BA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008A46C(rdram, ctx);
        goto after_1;
    // 0x80086BA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80086BA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086BAC: jal         0x8008BFF4
    // 0x80086BB0: nop

    func_8008BFF4(rdram, ctx);
        goto after_2;
    // 0x80086BB0: nop

    after_2:
    // 0x80086BB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086BB8: jal         0x80089170
    // 0x80086BBC: nop

    func_80089170(rdram, ctx);
        goto after_3;
    // 0x80086BBC: nop

    after_3:
    // 0x80086BC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086BC4: jal         0x80089418
    // 0x80086BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80089418(rdram, ctx);
        goto after_4;
    // 0x80086BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80086BCC: b           L_80086BDC
    // 0x80086BD0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80086BDC;
    // 0x80086BD0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80086BD4: b           L_80086BDC
    // 0x80086BD8: nop

        goto L_80086BDC;
    // 0x80086BD8: nop

L_80086BDC:
    // 0x80086BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80086BE4: jr          $ra
    // 0x80086BE8: nop

    return;
    // 0x80086BE8: nop

;}
RECOMP_FUNC void __osPackResetData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6098: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C609C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C60A0:
    // 0x800C60A0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800C60A4: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800C60A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C60AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C60B0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C60B4: sw          $zero, -0x4C0($at)
    MEM_W(-0X4C0, ctx->r1) = 0;
    // 0x800C60B8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C60BC: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800C60C0: bne         $at, $zero, L_800C60A0
    if (ctx->r1 != 0) {
        // 0x800C60C4: sw          $t9, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r25;
            goto L_800C60A0;
    }
    // 0x800C60C4: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x800C60C8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800C60CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C60D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800C60D4: addiu       $t1, $t1, -0x4C0
    ctx->r9 = ADD32(ctx->r9, -0X4C0);
    // 0x800C60D8: sw          $t0, -0x484($at)
    MEM_W(-0X484, ctx->r1) = ctx->r8;
    // 0x800C60DC: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800C60E0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C60E4:
    // 0x800C60E4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C60E8: addiu       $t2, $zero, 0xFD
    ctx->r10 = ADD32(0, 0XFD);
    // 0x800C60EC: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x800C60F0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800C60F4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C60F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C60FC: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800C6100: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C6104: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800C6108: bne         $at, $zero, L_800C60E4
    if (ctx->r1 != 0) {
        // 0x800C610C: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_800C60E4;
    }
    // 0x800C610C: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800C6110: jr          $ra
    // 0x800C6114: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C6114: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800653A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800653A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800653A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800653A8: nop

    // 0x800653AC: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x800653B0: nop

    // 0x800653B4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800653B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800653BC: jr          $ra
    // 0x800653C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800653C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800653C4: jr          $ra
    // 0x800653C8: nop

    return;
    // 0x800653C8: nop

    // 0x800653CC: jr          $ra
    // 0x800653D0: nop

    return;
    // 0x800653D0: nop

;}
RECOMP_FUNC void func_800346E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800346E4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800346E8: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x800346EC: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x800346F0: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x800346F4: sh          $zero, 0x2($sp)
    MEM_H(0X2, ctx->r29) = 0;
    // 0x800346F8: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800346FC: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80034700: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80034704: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80034708: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003470C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80034710: nop

    // 0x80034714: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80034718: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003471C: nop

    // 0x80034720: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80034724: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80034728: beq         $t7, $zero, L_8003477C
    if (ctx->r15 == 0) {
        // 0x8003472C: nop
    
            goto L_8003477C;
    }
    // 0x8003472C: nop

    // 0x80034730: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80034734: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80034738: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003473C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80034740: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80034744: nop

    // 0x80034748: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003474C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80034750: nop

    // 0x80034754: andi        $at, $t7, 0x4
    ctx->r1 = ctx->r15 & 0X4;
    // 0x80034758: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8003475C: bne         $t7, $zero, L_80034774
    if (ctx->r15 != 0) {
        // 0x80034760: nop
    
            goto L_80034774;
    }
    // 0x80034760: nop

    // 0x80034764: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80034768: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003476C: b           L_8003478C
    // 0x80034770: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8003478C;
    // 0x80034770: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80034774:
    // 0x80034774: b           L_8003478C
    // 0x80034778: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8003478C;
    // 0x80034778: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8003477C:
    // 0x8003477C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80034780: nop

    // 0x80034784: bltz        $t7, L_80034774
    if (SIGNED(ctx->r15) < 0) {
        // 0x80034788: nop
    
            goto L_80034774;
    }
    // 0x80034788: nop

L_8003478C:
    // 0x8003478C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80034790: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80034794: sh          $t7, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r15;
    // 0x80034798: bgez        $t8, L_800347AC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003479C: andi        $t9, $t8, 0x1
        ctx->r25 = ctx->r24 & 0X1;
            goto L_800347AC;
    }
    // 0x8003479C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800347A0: beq         $t9, $zero, L_800347AC
    if (ctx->r25 == 0) {
        // 0x800347A4: nop
    
            goto L_800347AC;
    }
    // 0x800347A4: nop

    // 0x800347A8: addiu       $t9, $t9, -0x2
    ctx->r25 = ADD32(ctx->r25, -0X2);
L_800347AC:
    // 0x800347AC: beq         $t9, $zero, L_800347D4
    if (ctx->r25 == 0) {
        // 0x800347B0: nop
    
            goto L_800347D4;
    }
    // 0x800347B0: nop

    // 0x800347B4: lhu         $t0, 0x2($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2);
    // 0x800347B8: nop

    // 0x800347BC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800347C0: sh          $t1, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r9;
    // 0x800347C4: lhu         $t2, 0x6($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X6);
    // 0x800347C8: nop

    // 0x800347CC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800347D0: sh          $t3, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r11;
L_800347D4:
    // 0x800347D4: lhu         $t4, 0x6($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6);
    // 0x800347D8: nop

    // 0x800347DC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800347E0: bgez        $t4, L_800347FC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800347E4: cvt.d.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
            goto L_800347FC;
    }
    // 0x800347E4: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800347E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800347EC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800347F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800347F4: nop

    // 0x800347F8: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_800347FC:
    // 0x800347FC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80034800: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80034804: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034808: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003480C: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80034810: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80034814: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80034818: nop

    // 0x8003481C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x80034820: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80034824: nop

    // 0x80034828: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x8003482C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80034830: beq         $t6, $zero, L_80034888
    if (ctx->r14 == 0) {
        // 0x80034834: nop
    
            goto L_80034888;
    }
    // 0x80034834: nop

    // 0x80034838: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8003483C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80034840: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80034844: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80034848: sub.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d - ctx->f10.d;
    // 0x8003484C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80034850: nop

    // 0x80034854: cvt.w.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_D(ctx->f10.d);
    // 0x80034858: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003485C: nop

    // 0x80034860: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80034864: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80034868: bne         $t6, $zero, L_80034880
    if (ctx->r14 != 0) {
        // 0x8003486C: nop
    
            goto L_80034880;
    }
    // 0x8003486C: nop

    // 0x80034870: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80034874: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80034878: b           L_80034898
    // 0x8003487C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80034898;
    // 0x8003487C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80034880:
    // 0x80034880: b           L_80034898
    // 0x80034884: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80034898;
    // 0x80034884: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80034888:
    // 0x80034888: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8003488C: nop

    // 0x80034890: bltz        $t6, L_80034880
    if (SIGNED(ctx->r14) < 0) {
        // 0x80034894: nop
    
            goto L_80034880;
    }
    // 0x80034894: nop

L_80034898:
    // 0x80034898: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8003489C: sh          $t6, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r14;
    // 0x800348A0: nop

    // 0x800348A4: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800348A8: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800348AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800348B0: div.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800348B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800348B8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800348BC: nop

    // 0x800348C0: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800348C4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800348C8: nop

    // 0x800348CC: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800348D0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800348D4: beq         $t8, $zero, L_80034928
    if (ctx->r24 == 0) {
        // 0x800348D8: nop
    
            goto L_80034928;
    }
    // 0x800348D8: nop

    // 0x800348DC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800348E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800348E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800348E8: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800348EC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800348F0: nop

    // 0x800348F4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800348F8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800348FC: nop

    // 0x80034900: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x80034904: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80034908: bne         $t8, $zero, L_80034920
    if (ctx->r24 != 0) {
        // 0x8003490C: nop
    
            goto L_80034920;
    }
    // 0x8003490C: nop

    // 0x80034910: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80034914: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80034918: b           L_80034938
    // 0x8003491C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80034938;
    // 0x8003491C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80034920:
    // 0x80034920: b           L_80034938
    // 0x80034924: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80034938;
    // 0x80034924: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80034928:
    // 0x80034928: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8003492C: nop

    // 0x80034930: bltz        $t8, L_80034920
    if (SIGNED(ctx->r24) < 0) {
        // 0x80034934: nop
    
            goto L_80034920;
    }
    // 0x80034934: nop

L_80034938:
    // 0x80034938: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003493C: sh          $t8, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r24;
    // 0x80034940: nop

    // 0x80034944: lhu         $t9, 0x4($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X4);
    // 0x80034948: lhu         $t0, 0x1E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X1E);
    // 0x8003494C: lhu         $t2, 0x6($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X6);
    // 0x80034950: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034954: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x80034958: mflo        $t1
    ctx->r9 = lo;
    // 0x8003495C: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x80034960: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80034964: nop

    // 0x80034968: sh          $t5, 0x0($sp)
    MEM_H(0X0, ctx->r29) = ctx->r13;
    // 0x8003496C: lhu         $t6, 0x2($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2);
    // 0x80034970: nop

    // 0x80034974: beq         $t6, $zero, L_80034990
    if (ctx->r14 == 0) {
        // 0x80034978: nop
    
            goto L_80034990;
    }
    // 0x80034978: nop

    // 0x8003497C: lhu         $t7, 0x0($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X0);
    // 0x80034980: nop

    // 0x80034984: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80034988: b           L_800349A4
    // 0x8003498C: sh          $t8, 0x0($sp)
    MEM_H(0X0, ctx->r29) = ctx->r24;
        goto L_800349A4;
    // 0x8003498C: sh          $t8, 0x0($sp)
    MEM_H(0X0, ctx->r29) = ctx->r24;
L_80034990:
    // 0x80034990: lhu         $t9, 0x0($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X0);
    // 0x80034994: nop

    // 0x80034998: andi        $t0, $t9, 0xF0
    ctx->r8 = ctx->r25 & 0XF0;
    // 0x8003499C: sra         $t2, $t0, 4
    ctx->r10 = S32(SIGNED(ctx->r8) >> 4);
    // 0x800349A0: sh          $t2, 0x0($sp)
    MEM_H(0X0, ctx->r29) = ctx->r10;
L_800349A4:
    // 0x800349A4: lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X0);
    // 0x800349A8: b           L_800349B8
    // 0x800349AC: nop

        goto L_800349B8;
    // 0x800349AC: nop

    // 0x800349B0: b           L_800349B8
    // 0x800349B4: nop

        goto L_800349B8;
    // 0x800349B4: nop

L_800349B8:
    // 0x800349B8: jr          $ra
    // 0x800349BC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800349BC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80076808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076808: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007680C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076810: nop

    // 0x80076814: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076818: nop

    // 0x8007681C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076820: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076824: jr          $ra
    // 0x80076828: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076828: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007682C: jr          $ra
    // 0x80076830: nop

    return;
    // 0x80076830: nop

    // 0x80076834: jr          $ra
    // 0x80076838: nop

    return;
    // 0x80076838: nop

;}
RECOMP_FUNC void func_8005151C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005151C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80051520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051524: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80051528: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005152C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80051530: lwc1        $f4, 0xE60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x80051534: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80051538: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005153C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80051540: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80051544: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80051548: bc1f        L_80051560
    if (!c1cs) {
        // 0x8005154C: nop
    
            goto L_80051560;
    }
    // 0x8005154C: nop

    // 0x80051550: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80051554: lwc1        $f16, -0x10B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X10B0);
    // 0x80051558: nop

    // 0x8005155C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
L_80051560:
    // 0x80051560: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80051564: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80051568: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005156C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80051570: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80051574: bne         $t0, $zero, L_80051584
    if (ctx->r8 != 0) {
        // 0x80051578: andi        $t1, $t9, 0x8
        ctx->r9 = ctx->r25 & 0X8;
            goto L_80051584;
    }
    // 0x80051578: andi        $t1, $t9, 0x8
    ctx->r9 = ctx->r25 & 0X8;
    // 0x8005157C: beq         $t1, $zero, L_80051598
    if (ctx->r9 == 0) {
        // 0x80051580: nop
    
            goto L_80051598;
    }
    // 0x80051580: nop

L_80051584:
    // 0x80051584: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80051588: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005158C: nop

    // 0x80051590: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80051594: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
L_80051598:
    // 0x80051598: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005159C: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800515A0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800515A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800515A8: lwc1        $f8, 0x10($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800515AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800515B0: lwc1        $f18, 0xE6C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XE6C);
    // 0x800515B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800515B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800515BC: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800515C0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800515C4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800515C8: bc1f        L_800515E0
    if (!c1cs) {
        // 0x800515CC: nop
    
            goto L_800515E0;
    }
    // 0x800515CC: nop

    // 0x800515D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800515D4: lwc1        $f8, -0x10AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X10AC);
    // 0x800515D8: nop

    // 0x800515DC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
L_800515E0:
    // 0x800515E0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800515E4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800515E8: jal         0x800C3A34
    // 0x800515EC: nop

    func_800C3A34(rdram, ctx);
        goto after_0;
    // 0x800515EC: nop

    after_0:
    // 0x800515F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800515F4: lwc1        $f19, -0x10A8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X10A8);
    // 0x800515F8: lwc1        $f18, -0x10A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X10A4);
    // 0x800515FC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80051600: nop

    // 0x80051604: div.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80051608: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8005160C: nop

    // 0x80051610: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80051614: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80051618: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005161C: nop

    // 0x80051620: cvt.w.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_D(ctx->f16.d);
    // 0x80051624: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80051628: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8005162C: nop

    // 0x80051630: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80051634: nop

    // 0x80051638: slti        $at, $t4, 0xF
    ctx->r1 = SIGNED(ctx->r12) < 0XF ? 1 : 0;
    // 0x8005163C: beq         $at, $zero, L_8005164C
    if (ctx->r1 == 0) {
        // 0x80051640: nop
    
            goto L_8005164C;
    }
    // 0x80051640: nop

    // 0x80051644: b           L_800516F0
    // 0x80051648: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_800516F0;
    // 0x80051648: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_8005164C:
    // 0x8005164C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80051650: nop

    // 0x80051654: slti        $at, $t5, 0x5A
    ctx->r1 = SIGNED(ctx->r13) < 0X5A ? 1 : 0;
    // 0x80051658: beq         $at, $zero, L_80051668
    if (ctx->r1 == 0) {
        // 0x8005165C: nop
    
            goto L_80051668;
    }
    // 0x8005165C: nop

    // 0x80051660: b           L_800516F0
    // 0x80051664: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_800516F0;
    // 0x80051664: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80051668:
    // 0x80051668: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8005166C: nop

    // 0x80051670: slti        $at, $t6, 0xA5
    ctx->r1 = SIGNED(ctx->r14) < 0XA5 ? 1 : 0;
    // 0x80051674: beq         $at, $zero, L_80051684
    if (ctx->r1 == 0) {
        // 0x80051678: nop
    
            goto L_80051684;
    }
    // 0x80051678: nop

    // 0x8005167C: b           L_800516F0
    // 0x80051680: addiu       $v0, $zero, 0x43
    ctx->r2 = ADD32(0, 0X43);
        goto L_800516F0;
    // 0x80051680: addiu       $v0, $zero, 0x43
    ctx->r2 = ADD32(0, 0X43);
L_80051684:
    // 0x80051684: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80051688: nop

    // 0x8005168C: slti        $at, $t7, 0xC3
    ctx->r1 = SIGNED(ctx->r15) < 0XC3 ? 1 : 0;
    // 0x80051690: beq         $at, $zero, L_800516A0
    if (ctx->r1 == 0) {
        // 0x80051694: nop
    
            goto L_800516A0;
    }
    // 0x80051694: nop

    // 0x80051698: b           L_800516F0
    // 0x8005169C: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
        goto L_800516F0;
    // 0x8005169C: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
L_800516A0:
    // 0x800516A0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800516A4: nop

    // 0x800516A8: slti        $at, $t8, 0x10E
    ctx->r1 = SIGNED(ctx->r24) < 0X10E ? 1 : 0;
    // 0x800516AC: beq         $at, $zero, L_800516BC
    if (ctx->r1 == 0) {
        // 0x800516B0: nop
    
            goto L_800516BC;
    }
    // 0x800516B0: nop

    // 0x800516B4: b           L_800516F0
    // 0x800516B8: addiu       $v0, $zero, 0x44
    ctx->r2 = ADD32(0, 0X44);
        goto L_800516F0;
    // 0x800516B8: addiu       $v0, $zero, 0x44
    ctx->r2 = ADD32(0, 0X44);
L_800516BC:
    // 0x800516BC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800516C0: nop

    // 0x800516C4: slti        $at, $t9, 0x159
    ctx->r1 = SIGNED(ctx->r25) < 0X159 ? 1 : 0;
    // 0x800516C8: beq         $at, $zero, L_800516E0
    if (ctx->r1 == 0) {
        // 0x800516CC: nop
    
            goto L_800516E0;
    }
    // 0x800516CC: nop

    // 0x800516D0: b           L_800516F0
    // 0x800516D4: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
        goto L_800516F0;
    // 0x800516D4: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x800516D8: b           L_800516E8
    // 0x800516DC: nop

        goto L_800516E8;
    // 0x800516DC: nop

L_800516E0:
    // 0x800516E0: b           L_800516F0
    // 0x800516E4: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_800516F0;
    // 0x800516E4: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_800516E8:
    // 0x800516E8: b           L_800516F0
    // 0x800516EC: nop

        goto L_800516F0;
    // 0x800516EC: nop

L_800516F0:
    // 0x800516F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800516F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800516F8: jr          $ra
    // 0x800516FC: nop

    return;
    // 0x800516FC: nop

;}
RECOMP_FUNC void func_800C0444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0444: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C0448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C044C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C0450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C0454: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C0458: lw          $t6, 0x42C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X42C);
    // 0x800C045C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800C0460: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x800C0464: bne         $at, $zero, L_800C0474
    if (ctx->r1 != 0) {
        // 0x800C0468: nop
    
            goto L_800C0474;
    }
    // 0x800C0468: nop

    // 0x800C046C: b           L_800C0480
    // 0x800C0470: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
        goto L_800C0480;
    // 0x800C0470: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
L_800C0474:
    // 0x800C0474: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800C0478: lw          $s0, 0x42C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X42C);
    // 0x800C047C: nop

L_800C0480:
    // 0x800C0480: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C0484: nop

    // 0x800C0488: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800C048C: beq         $at, $zero, L_800C0508
    if (ctx->r1 == 0) {
        // 0x800C0490: nop
    
            goto L_800C0508;
    }
    // 0x800C0490: nop

L_800C0494:
    // 0x800C0494: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800C0498: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800C049C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C04A0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800C04A4: lw          $t0, 0x228($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X228);
    // 0x800C04A8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C04AC: nop

    // 0x800C04B0: bne         $t0, $t1, L_800C04C4
    if (ctx->r8 != ctx->r9) {
        // 0x800C04B4: nop
    
            goto L_800C04C4;
    }
    // 0x800C04B4: nop

    // 0x800C04B8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800C04BC: b           L_800C0524
    // 0x800C04C0: nop

        goto L_800C0524;
    // 0x800C04C0: nop

L_800C04C4:
    // 0x800C04C4: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800C04C8: lw          $t4, 0x42C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X42C);
    // 0x800C04CC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800C04D0: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x800C04D4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C04D8: bne         $at, $zero, L_800C04E8
    if (ctx->r1 != 0) {
        // 0x800C04DC: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_800C04E8;
    }
    // 0x800C04DC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800C04E0: b           L_800C04F4
    // 0x800C04E4: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
        goto L_800C04F4;
    // 0x800C04E4: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
L_800C04E8:
    // 0x800C04E8: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800C04EC: lw          $s0, 0x42C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X42C);
    // 0x800C04F0: nop

L_800C04F4:
    // 0x800C04F4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C04F8: nop

    // 0x800C04FC: slt         $at, $t5, $s0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800C0500: bne         $at, $zero, L_800C0494
    if (ctx->r1 != 0) {
        // 0x800C0504: nop
    
            goto L_800C0494;
    }
    // 0x800C0504: nop

L_800C0508:
    // 0x800C0508: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C050C: jal         0x800C055C
    // 0x800C0510: nop

    func_800C055C(rdram, ctx);
        goto after_0;
    // 0x800C0510: nop

    after_0:
    // 0x800C0514: b           L_800C0524
    // 0x800C0518: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C0524;
    // 0x800C0518: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C051C: b           L_800C0524
    // 0x800C0520: nop

        goto L_800C0524;
    // 0x800C0520: nop

L_800C0524:
    // 0x800C0524: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0528: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C052C: jr          $ra
    // 0x800C0530: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C0530: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006CE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CE4C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CE50: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CE54: nop

    // 0x8006CE58: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x8006CE5C: nop

    // 0x8006CE60: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CE64: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CE68: jr          $ra
    // 0x8006CE6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CE6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CE70: jr          $ra
    // 0x8006CE74: nop

    return;
    // 0x8006CE74: nop

    // 0x8006CE78: jr          $ra
    // 0x8006CE7C: nop

    return;
    // 0x8006CE7C: nop

;}
RECOMP_FUNC void func_8006D65C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D65C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D664: jal         0x80061348
    // 0x8006D668: addiu       $a0, $zero, 0x57D
    ctx->r4 = ADD32(0, 0X57D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006D668: addiu       $a0, $zero, 0x57D
    ctx->r4 = ADD32(0, 0X57D);
    after_0:
    // 0x8006D66C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006D670: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006D674: b           L_8006D684
    // 0x8006D678: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006D684;
    // 0x8006D678: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006D67C: b           L_8006D684
    // 0x8006D680: nop

        goto L_8006D684;
    // 0x8006D680: nop

L_8006D684:
    // 0x8006D684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D68C: jr          $ra
    // 0x8006D690: nop

    return;
    // 0x8006D690: nop

;}
RECOMP_FUNC void func_80069094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006909C: jal         0x80061348
    // 0x800690A0: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800690A0: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x800690A4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800690A8: b           L_800690B8
    // 0x800690AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800690B8;
    // 0x800690AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800690B0: b           L_800690B8
    // 0x800690B4: nop

        goto L_800690B8;
    // 0x800690B4: nop

L_800690B8:
    // 0x800690B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800690BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800690C0: jr          $ra
    // 0x800690C4: nop

    return;
    // 0x800690C4: nop

;}
RECOMP_FUNC void func_80069C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069C98: jal         0x80061348
    // 0x80069C9C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80069C9C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_0:
    // 0x80069CA0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069CA4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80069CA8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069CAC: beq         $v0, $zero, L_80069CC8
    if (ctx->r2 == 0) {
        // 0x80069CB0: nop
    
            goto L_80069CC8;
    }
    // 0x80069CB0: nop

    // 0x80069CB4: jal         0x80061348
    // 0x80069CB8: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80069CB8: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    after_1:
    // 0x80069CBC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80069CC0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80069CC4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80069CC8:
    // 0x80069CC8: b           L_80069CD8
    // 0x80069CCC: nop

        goto L_80069CD8;
    // 0x80069CCC: nop

    // 0x80069CD0: b           L_80069CD8
    // 0x80069CD4: nop

        goto L_80069CD8;
    // 0x80069CD4: nop

L_80069CD8:
    // 0x80069CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069CE0: jr          $ra
    // 0x80069CE4: nop

    return;
    // 0x80069CE4: nop

;}
RECOMP_FUNC void func_800B8038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B803C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B8044: jal         0x80031728
    // 0x800B8048: nop

    func_80031728(rdram, ctx);
        goto after_0;
    // 0x800B8048: nop

    after_0:
    // 0x800B804C: ori         $t6, $zero, 0xC00A
    ctx->r14 = 0 | 0XC00A;
    // 0x800B8050: addiu       $t7, $sp, 0x18
    ctx->r15 = ADD32(ctx->r29, 0X18);
    // 0x800B8054: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x800B8058: ori         $t8, $zero, 0xE007
    ctx->r24 = 0 | 0XE007;
    // 0x800B805C: addiu       $t9, $sp, 0x18
    ctx->r25 = ADD32(ctx->r29, 0X18);
    // 0x800B8060: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x800B8064: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x800B8068: addiu       $t1, $sp, 0x18
    ctx->r9 = ADD32(ctx->r29, 0X18);
    // 0x800B806C: sh          $t0, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r8;
    // 0x800B8070: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800B8074: addiu       $t3, $sp, 0x18
    ctx->r11 = ADD32(ctx->r29, 0X18);
    // 0x800B8078: sh          $t2, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r10;
    // 0x800B807C: jal         0x800B77D8
    // 0x800B8080: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800B77D8(rdram, ctx);
        goto after_1;
    // 0x800B8080: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800B8084: b           L_800B8094
    // 0x800B8088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B8094;
    // 0x800B8088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B808C: b           L_800B8094
    // 0x800B8090: nop

        goto L_800B8094;
    // 0x800B8090: nop

L_800B8094:
    // 0x800B8094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B809C: jr          $ra
    // 0x800B80A0: nop

    return;
    // 0x800B80A0: nop

;}
RECOMP_FUNC void func_80073B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073B0C: jal         0x80061348
    // 0x80073B10: addiu       $a0, $zero, 0x558
    ctx->r4 = ADD32(0, 0X558);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80073B10: addiu       $a0, $zero, 0x558
    ctx->r4 = ADD32(0, 0X558);
    after_0:
    // 0x80073B14: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80073B18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073B1C: b           L_80073B2C
    // 0x80073B20: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80073B2C;
    // 0x80073B20: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80073B24: b           L_80073B2C
    // 0x80073B28: nop

        goto L_80073B2C;
    // 0x80073B28: nop

L_80073B2C:
    // 0x80073B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073B34: jr          $ra
    // 0x80073B38: nop

    return;
    // 0x80073B38: nop

;}
RECOMP_FUNC void func_8006BC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BC70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BC78: jal         0x8005F064
    // 0x8006BC7C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BC7C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x8006BC80: b           L_8006BC90
    // 0x8006BC84: nop

        goto L_8006BC90;
    // 0x8006BC84: nop

    // 0x8006BC88: b           L_8006BC90
    // 0x8006BC8C: nop

        goto L_8006BC90;
    // 0x8006BC8C: nop

L_8006BC90:
    // 0x8006BC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BC94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BC98: jr          $ra
    // 0x8006BC9C: nop

    return;
    // 0x8006BC9C: nop

;}
RECOMP_FUNC void func_80075DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075DC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075DD0: jal         0x80061348
    // 0x80075DD4: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80075DD4: addiu       $a0, $zero, 0x46B
    ctx->r4 = ADD32(0, 0X46B);
    after_0:
    // 0x80075DD8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80075DDC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80075DE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80075DE4: beq         $v0, $zero, L_80075E38
    if (ctx->r2 == 0) {
        // 0x80075DE8: nop
    
            goto L_80075E38;
    }
    // 0x80075DE8: nop

    // 0x80075DEC: jal         0x80061348
    // 0x80075DF0: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80075DF0: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_1:
    // 0x80075DF4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80075DF8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80075DFC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80075E00: beq         $v0, $zero, L_80075E38
    if (ctx->r2 == 0) {
        // 0x80075E04: nop
    
            goto L_80075E38;
    }
    // 0x80075E04: nop

    // 0x80075E08: jal         0x80061348
    // 0x80075E0C: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80075E0C: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_2:
    // 0x80075E10: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80075E14: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80075E18: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80075E1C: beq         $v0, $zero, L_80075E38
    if (ctx->r2 == 0) {
        // 0x80075E20: nop
    
            goto L_80075E38;
    }
    // 0x80075E20: nop

    // 0x80075E24: jal         0x80061348
    // 0x80075E28: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80075E28: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    after_3:
    // 0x80075E2C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80075E30: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80075E34: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80075E38:
    // 0x80075E38: b           L_80075E48
    // 0x80075E3C: nop

        goto L_80075E48;
    // 0x80075E3C: nop

    // 0x80075E40: b           L_80075E48
    // 0x80075E44: nop

        goto L_80075E48;
    // 0x80075E44: nop

L_80075E48:
    // 0x80075E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075E50: jr          $ra
    // 0x80075E54: nop

    return;
    // 0x80075E54: nop

;}
RECOMP_FUNC void MathUtil_GetDistance2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3C08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C3C0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3C10: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C3C14: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C3C18: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800C3C1C: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800C3C20: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C3C24: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C3C28: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C3C2C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3C30: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3C34: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C3C38: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C3C3C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C3C40: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800C3C44: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800C3C48: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C3C4C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x800C3C50: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800C3C54: jal         0x800C42A0
    // 0x800C3C58: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C3C58: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_0:
    // 0x800C3C5C: b           L_800C3C6C
    // 0x800C3C60: nop

        goto L_800C3C6C;
    // 0x800C3C60: nop

    // 0x800C3C64: b           L_800C3C6C
    // 0x800C3C68: nop

        goto L_800C3C6C;
    // 0x800C3C68: nop

L_800C3C6C:
    // 0x800C3C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3C70: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C3C74: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C3C78: jr          $ra
    // 0x800C3C7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C3C7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006CE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CE80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CE84: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CE88: nop

    // 0x8006CE8C: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x8006CE90: nop

    // 0x8006CE94: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CE98: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CE9C: jr          $ra
    // 0x8006CEA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CEA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CEA4: jr          $ra
    // 0x8006CEA8: nop

    return;
    // 0x8006CEA8: nop

    // 0x8006CEAC: jr          $ra
    // 0x8006CEB0: nop

    return;
    // 0x8006CEB0: nop

;}
RECOMP_FUNC void func_80077B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B9C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077BA0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077BA4: nop

    // 0x80077BA8: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80077BAC: nop

    // 0x80077BB0: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80077BB4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077BB8: jr          $ra
    // 0x80077BBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077BBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077BC0: jr          $ra
    // 0x80077BC4: nop

    return;
    // 0x80077BC4: nop

    // 0x80077BC8: jr          $ra
    // 0x80077BCC: nop

    return;
    // 0x80077BCC: nop

;}
RECOMP_FUNC void func_80068718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068718: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006871C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068720: nop

    // 0x80068724: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80068728: nop

    // 0x8006872C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80068730: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068734: jr          $ra
    // 0x80068738: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068738: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006873C: jr          $ra
    // 0x80068740: nop

    return;
    // 0x80068740: nop

    // 0x80068744: jr          $ra
    // 0x80068748: nop

    return;
    // 0x80068748: nop

;}
RECOMP_FUNC void MathUtil_Sinf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3070: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C3074: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800C3078: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800C307C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C3080: nop

    // 0x800C3084: sra         $t8, $t7, 22
    ctx->r24 = S32(SIGNED(ctx->r15) >> 22);
    // 0x800C3088: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800C308C: slti        $at, $t9, 0xE6
    ctx->r1 = SIGNED(ctx->r25) < 0XE6 ? 1 : 0;
    // 0x800C3090: beq         $at, $zero, L_800C30A4
    if (ctx->r1 == 0) {
        // 0x800C3094: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_800C30A4;
    }
    // 0x800C3094: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800C3098: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C309C: b           L_800C3330
    // 0x800C30A0: nop

        goto L_800C3330;
    // 0x800C30A0: nop

L_800C30A4:
    // 0x800C30A4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C30A8: nop

    // 0x800C30AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800C30B0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800C30B4: swc1        $f7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x800C30B8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C30BC: nop

    // 0x800C30C0: slti        $at, $t0, 0xFF
    ctx->r1 = SIGNED(ctx->r8) < 0XFF ? 1 : 0;
    // 0x800C30C4: beq         $at, $zero, L_800C3150
    if (ctx->r1 == 0) {
        // 0x800C30C8: nop
    
            goto L_800C3150;
    }
    // 0x800C30C8: nop

    // 0x800C30CC: lwc1        $f9, 0x20($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C30D0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C30D4: nop

    // 0x800C30D8: mul.d       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f8.d);
    // 0x800C30DC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800C30E0: swc1        $f11, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
    // 0x800C30E4: lwc1        $f17, 0x20($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C30E8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C30EC: lwc1        $f19, 0x18($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C30F0: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C30F4: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x800C30F8: addiu       $t1, $t1, -0x5568
    ctx->r9 = ADD32(ctx->r9, -0X5568);
    // 0x800C30FC: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800C3100: lwc1        $f7, 0x18($t1)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r9, 0X18);
    // 0x800C3104: lwc1        $f6, 0x1C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800C3108: lwc1        $f11, 0x10($t1)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r9, 0X10);
    // 0x800C310C: lwc1        $f10, 0x14($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X14);
    // 0x800C3110: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800C3114: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x800C3118: lwc1        $f10, 0xC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800C311C: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800C3120: lwc1        $f11, 0x8($t1)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r9, 0X8);
    // 0x800C3124: nop

    // 0x800C3128: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x800C312C: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x800C3130: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x800C3134: lwc1        $f11, 0x0($t1)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r9, 0X0);
    // 0x800C3138: nop

    // 0x800C313C: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x800C3140: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C3144: add.d       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f18.d + ctx->f16.d;
    // 0x800C3148: b           L_800C3330
    // 0x800C314C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_800C3330;
    // 0x800C314C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_800C3150:
    // 0x800C3150: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800C3154: nop

    // 0x800C3158: slti        $at, $t2, 0x136
    ctx->r1 = SIGNED(ctx->r10) < 0X136 ? 1 : 0;
    // 0x800C315C: beq         $at, $zero, L_800C331C
    if (ctx->r1 == 0) {
        // 0x800C3160: nop
    
            goto L_800C331C;
    }
    // 0x800C3160: nop

    // 0x800C3164: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3168: lwc1        $f5, -0x5580($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C316C: lwc1        $f4, -0x557C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C3170: lwc1        $f11, 0x20($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C3174: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3178: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800C317C: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800C3180: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C3184: nop

    // 0x800C3188: c.le.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d <= ctx->f6.d;
    // 0x800C318C: nop

    // 0x800C3190: bc1f        L_800C31D4
    if (!c1cs) {
        // 0x800C3194: nop
    
            goto L_800C31D4;
    }
    // 0x800C3194: nop

    // 0x800C3198: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C319C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C31A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C31A4: nop

    // 0x800C31A8: add.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f6.d + ctx->f16.d;
    // 0x800C31AC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800C31B0: nop

    // 0x800C31B4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800C31B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C31BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C31C0: nop

    // 0x800C31C4: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C31C8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800C31CC: b           L_800C3228
    // 0x800C31D0: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
        goto L_800C3228;
    // 0x800C31D0: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
L_800C31D4:
    // 0x800C31D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C31D8: lwc1        $f19, -0x5580($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C31DC: lwc1        $f18, -0x557C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C31E0: lwc1        $f5, 0x20($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C31E4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C31E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C31EC: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x800C31F0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C31F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C31F8: nop

    // 0x800C31FC: sub.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f6.d - ctx->f16.d;
    // 0x800C3200: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800C3204: nop

    // 0x800C3208: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800C320C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C3210: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C3214: nop

    // 0x800C3218: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C321C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800C3220: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x800C3224: nop

L_800C3228:
    // 0x800C3228: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C322C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3230: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C3234: lwc1        $f7, -0x5578($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X5578);
    // 0x800C3238: cvt.d.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.d = CVT_D_W(ctx->f4.u32l);
    // 0x800C323C: lwc1        $f6, -0x5574($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5574);
    // 0x800C3240: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3244: mul.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x800C3248: lwc1        $f5, -0x5570($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X5570);
    // 0x800C324C: lwc1        $f4, -0x556C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X556C);
    // 0x800C3250: lwc1        $f9, 0x20($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C3254: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3258: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C325C: sub.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d - ctx->f16.d;
    // 0x800C3260: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800C3264: swc1        $f19, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(19 - 1) * 2];
    // 0x800C3268: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800C326C: mul.d       $f16, $f8, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f8.d);
    // 0x800C3270: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800C3274: swc1        $f9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800C3278: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800C327C: swc1        $f17, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800C3280: lwc1        $f19, 0x20($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800C3284: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3288: lwc1        $f5, 0x18($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800C328C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3290: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C3294: addiu       $t6, $t6, -0x5568
    ctx->r14 = ADD32(ctx->r14, -0X5568);
    // 0x800C3298: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C329C: lwc1        $f7, 0x18($t6)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r14, 0X18);
    // 0x800C32A0: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800C32A4: lwc1        $f17, 0x10($t6)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r14, 0X10);
    // 0x800C32A8: lwc1        $f16, 0x14($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X14);
    // 0x800C32AC: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800C32B0: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x800C32B4: lwc1        $f16, 0xC($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800C32B8: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800C32BC: lwc1        $f17, 0x8($t6)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r14, 0X8);
    // 0x800C32C0: nop

    // 0x800C32C4: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x800C32C8: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800C32CC: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800C32D0: lwc1        $f17, 0x0($t6)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r14, 0X0);
    // 0x800C32D4: nop

    // 0x800C32D8: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x800C32DC: mul.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x800C32E0: add.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f4.d + ctx->f18.d;
    // 0x800C32E4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800C32E8: swc1        $f16, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f16.u32l;
    // 0x800C32EC: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800C32F0: nop

    // 0x800C32F4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C32F8: beq         $t8, $zero, L_800C330C
    if (ctx->r24 == 0) {
        // 0x800C32FC: nop
    
            goto L_800C330C;
    }
    // 0x800C32FC: nop

    // 0x800C3300: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C3304: b           L_800C3314
    // 0x800C3308: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_800C3314;
    // 0x800C3308: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_800C330C:
    // 0x800C330C: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C3310: nop

L_800C3314:
    // 0x800C3314: b           L_800C3330
    // 0x800C3318: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_800C3330;
    // 0x800C3318: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_800C331C:
    // 0x800C331C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C3320: b           L_800C3330
    // 0x800C3324: nop

        goto L_800C3330;
    // 0x800C3324: nop

    // 0x800C3328: b           L_800C3330
    // 0x800C332C: nop

        goto L_800C3330;
    // 0x800C332C: nop

L_800C3330:
    // 0x800C3330: jr          $ra
    // 0x800C3334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C3334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800BD664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD664: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800BD668: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BD66C: lw          $t6, 0x2640($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2640);
    // 0x800BD670: nop

    // 0x800BD674: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800BD678: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BD67C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD680: lw          $t7, 0x2640($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2640);
    // 0x800BD684: xor         $t8, $a0, $at
    ctx->r24 = ctx->r4 ^ ctx->r1;
    // 0x800BD688: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BD68C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x800BD690: sw          $t9, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = ctx->r25;
    // 0x800BD694: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800BD698: b           L_800BD6A8
    // 0x800BD69C: nop

        goto L_800BD6A8;
    // 0x800BD69C: nop

    // 0x800BD6A0: b           L_800BD6A8
    // 0x800BD6A4: nop

        goto L_800BD6A8;
    // 0x800BD6A4: nop

L_800BD6A8:
    // 0x800BD6A8: jr          $ra
    // 0x800BD6AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800BD6AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80063670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063678: jal         0x8005F064
    // 0x8006367C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006367C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_0:
    // 0x80063680: b           L_80063690
    // 0x80063684: nop

        goto L_80063690;
    // 0x80063684: nop

    // 0x80063688: b           L_80063690
    // 0x8006368C: nop

        goto L_80063690;
    // 0x8006368C: nop

L_80063690:
    // 0x80063690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063698: jr          $ra
    // 0x8006369C: nop

    return;
    // 0x8006369C: nop

;}
RECOMP_FUNC void func_80099660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099660: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80099664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099668: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009966C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80099670: nop

    // 0x80099674: beq         $t6, $zero, L_800996D0
    if (ctx->r14 == 0) {
        // 0x80099678: nop
    
            goto L_800996D0;
    }
    // 0x80099678: nop

    // 0x8009967C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80099680:
    // 0x80099680: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80099684: nop

    // 0x80099688: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x8009968C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80099690: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80099694: jal         0x800BC6EC
    // 0x80099698: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80099698: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x8009969C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800996A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800996A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800996A8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800996AC: sw          $v0, 0x30B8($at)
    MEM_W(0X30B8, ctx->r1) = ctx->r2;
    // 0x800996B0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800996B4: nop

    // 0x800996B8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800996BC: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800996C0: bne         $at, $zero, L_80099680
    if (ctx->r1 != 0) {
        // 0x800996C4: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_80099680;
    }
    // 0x800996C4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800996C8: b           L_80099700
    // 0x800996CC: nop

        goto L_80099700;
    // 0x800996CC: nop

L_800996D0:
    // 0x800996D0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800996D4:
    // 0x800996D4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800996D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800996DC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800996E0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800996E4: sw          $zero, 0x30B8($at)
    MEM_W(0X30B8, ctx->r1) = 0;
    // 0x800996E8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800996EC: nop

    // 0x800996F0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800996F4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800996F8: bne         $at, $zero, L_800996D4
    if (ctx->r1 != 0) {
        // 0x800996FC: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800996D4;
    }
    // 0x800996FC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80099700:
    // 0x80099700: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80099704: addiu       $t7, $t7, 0x30B8
    ctx->r15 = ADD32(ctx->r15, 0X30B8);
    // 0x80099708: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8009970C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099710: sw          $t8, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r24;
    // 0x80099714: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099718: sw          $zero, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = 0;
    // 0x8009971C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099720: sw          $zero, 0x7204($at)
    MEM_W(0X7204, ctx->r1) = 0;
    // 0x80099724: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80099728: sw          $zero, -0x727C($at)
    MEM_W(-0X727C, ctx->r1) = 0;
    // 0x8009972C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80099730: sw          $zero, -0x7284($at)
    MEM_W(-0X7284, ctx->r1) = 0;
    // 0x80099734: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80099738: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009973C: swc1        $f4, 0x18E0($at)
    MEM_W(0X18E0, ctx->r1) = ctx->f4.u32l;
    // 0x80099740: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80099744: sw          $zero, -0x73AC($at)
    MEM_W(-0X73AC, ctx->r1) = 0;
    // 0x80099748: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8009974C: sw          $zero, -0x71D0($at)
    MEM_W(-0X71D0, ctx->r1) = 0;
    // 0x80099750: b           L_80099758
    // 0x80099754: nop

        goto L_80099758;
    // 0x80099754: nop

L_80099758:
    // 0x80099758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009975C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80099760: jr          $ra
    // 0x80099764: nop

    return;
    // 0x80099764: nop

;}
RECOMP_FUNC void func_80074A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074A7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80074A80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80074A84: nop

    // 0x80074A88: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x80074A8C: nop

    // 0x80074A90: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80074A94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80074A98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80074A9C: bne         $v0, $zero, L_80074AB8
    if (ctx->r2 != 0) {
        // 0x80074AA0: nop
    
            goto L_80074AB8;
    }
    // 0x80074AA0: nop

    // 0x80074AA4: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x80074AA8: nop

    // 0x80074AAC: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80074AB0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80074AB4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80074AB8:
    // 0x80074AB8: jr          $ra
    // 0x80074ABC: nop

    return;
    // 0x80074ABC: nop

    // 0x80074AC0: jr          $ra
    // 0x80074AC4: nop

    return;
    // 0x80074AC4: nop

    // 0x80074AC8: jr          $ra
    // 0x80074ACC: nop

    return;
    // 0x80074ACC: nop

;}
RECOMP_FUNC void func_80099768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099768: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8009976C: lw          $t6, 0x70E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70E4);
    // 0x80099770: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099774: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80099778: bgez        $t7, L_8009978C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8009977C: andi        $t8, $t7, 0x1
        ctx->r24 = ctx->r15 & 0X1;
            goto L_8009978C;
    }
    // 0x8009977C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80099780: beq         $t8, $zero, L_8009978C
    if (ctx->r24 == 0) {
        // 0x80099784: nop
    
            goto L_8009978C;
    }
    // 0x80099784: nop

    // 0x80099788: addiu       $t8, $t8, -0x2
    ctx->r24 = ADD32(ctx->r24, -0X2);
L_8009978C:
    // 0x8009978C: sw          $t8, 0x70E4($at)
    MEM_W(0X70E4, ctx->r1) = ctx->r24;
    // 0x80099790: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80099794: sw          $zero, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = 0;
    // 0x80099798: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009979C: sw          $zero, 0x7204($at)
    MEM_W(0X7204, ctx->r1) = 0;
    // 0x800997A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800997A4: sw          $zero, -0x7284($at)
    MEM_W(-0X7284, ctx->r1) = 0;
    // 0x800997A8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800997AC: lw          $t9, 0x70E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70E4);
    // 0x800997B0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800997B4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800997B8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800997BC: lw          $t1, 0x30B8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B8);
    // 0x800997C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800997C4: sw          $t1, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r9;
    // 0x800997C8: jr          $ra
    // 0x800997CC: nop

    return;
    // 0x800997CC: nop

    // 0x800997D0: jr          $ra
    // 0x800997D4: nop

    return;
    // 0x800997D4: nop

;}
RECOMP_FUNC void func_800057E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800057E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800057EC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800057F0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800057F4:
    // 0x800057F4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800057F8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800057FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80005800: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80005804: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80005808: lw          $t6, -0x73DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73DC);
    // 0x8000580C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80005810: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80005814: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80005818: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x8000581C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80005820: nop

    // 0x80005824: or          $t2, $t1, $t0
    ctx->r10 = ctx->r9 | ctx->r8;
    // 0x80005828: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8000582C: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x80005830: nop

    // 0x80005834: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80005838: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x8000583C: bne         $at, $zero, L_800057F4
    if (ctx->r1 != 0) {
        // 0x80005840: sw          $t4, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r12;
            goto L_800057F4;
    }
    // 0x80005840: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x80005844: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80005848: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8000584C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80005850: bne         $t7, $zero, L_80005860
    if (ctx->r15 != 0) {
        // 0x80005854: nop
    
            goto L_80005860;
    }
    // 0x80005854: nop

    // 0x80005858: b           L_80005870
    // 0x8000585C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80005870;
    // 0x8000585C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005860:
    // 0x80005860: b           L_80005870
    // 0x80005864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005870;
    // 0x80005864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005868: b           L_80005870
    // 0x8000586C: nop

        goto L_80005870;
    // 0x8000586C: nop

L_80005870:
    // 0x80005870: jr          $ra
    // 0x80005874: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80005874: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800B6B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6B18: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B6B1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B6B20: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B6B24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B6B28: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800B6B2C:
    // 0x800B6B2C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800B6B30: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6B34: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800B6B38: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B6B3C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x800B6B40: sh          $t7, 0x30($t0)
    MEM_H(0X30, ctx->r8) = ctx->r15;
    // 0x800B6B44: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B6B48: nop

    // 0x800B6B4C: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x800B6B50: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800B6B54: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6B58: nop

    // 0x800B6B5C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B6B60: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x800B6B64: bne         $at, $zero, L_800B6B2C
    if (ctx->r1 != 0) {
        // 0x800B6B68: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_800B6B2C;
    }
    // 0x800B6B68: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800B6B6C: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x800B6B70: lhu         $s0, 0x2($t5)
    ctx->r16 = MEM_HU(ctx->r13, 0X2);
    // 0x800B6B74: ori         $at, $zero, 0xE100
    ctx->r1 = 0 | 0XE100;
    // 0x800B6B78: beq         $s0, $at, L_800B6BAC
    if (ctx->r16 == ctx->r1) {
        // 0x800B6B7C: nop
    
            goto L_800B6BAC;
    }
    // 0x800B6B7C: nop

    // 0x800B6B80: ori         $at, $zero, 0xE101
    ctx->r1 = 0 | 0XE101;
    // 0x800B6B84: beq         $s0, $at, L_800B6BE8
    if (ctx->r16 == ctx->r1) {
        // 0x800B6B88: nop
    
            goto L_800B6BE8;
    }
    // 0x800B6B88: nop

    // 0x800B6B8C: ori         $at, $zero, 0xE102
    ctx->r1 = 0 | 0XE102;
    // 0x800B6B90: beq         $s0, $at, L_800B6C30
    if (ctx->r16 == ctx->r1) {
        // 0x800B6B94: nop
    
            goto L_800B6C30;
    }
    // 0x800B6B94: nop

    // 0x800B6B98: ori         $at, $zero, 0xE103
    ctx->r1 = 0 | 0XE103;
    // 0x800B6B9C: beq         $s0, $at, L_800B6C6C
    if (ctx->r16 == ctx->r1) {
        // 0x800B6BA0: nop
    
            goto L_800B6C6C;
    }
    // 0x800B6BA0: nop

    // 0x800B6BA4: b           L_800B6CA8
    // 0x800B6BA8: nop

        goto L_800B6CA8;
    // 0x800B6BA8: nop

L_800B6BAC:
    // 0x800B6BAC: jal         0x800B6CC8
    // 0x800B6BB0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B6CC8(rdram, ctx);
        goto after_0;
    // 0x800B6BB0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x800B6BB4: beq         $v0, $zero, L_800B6BC4
    if (ctx->r2 == 0) {
        // 0x800B6BB8: nop
    
            goto L_800B6BC4;
    }
    // 0x800B6BB8: nop

    // 0x800B6BBC: b           L_800B6CB8
    // 0x800B6BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B6CB8;
    // 0x800B6BC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B6BC4:
    // 0x800B6BC4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800B6BC8: lw          $t6, 0x3068($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3068);
    // 0x800B6BCC: nop

    // 0x800B6BD0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800B6BD4: nop

    // 0x800B6BD8: ori         $t7, $t8, 0x10
    ctx->r15 = ctx->r24 | 0X10;
    // 0x800B6BDC: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
    // 0x800B6BE0: b           L_800B6CA8
    // 0x800B6BE4: nop

        goto L_800B6CA8;
    // 0x800B6BE4: nop

L_800B6BE8:
    // 0x800B6BE8: jal         0x800B6E04
    // 0x800B6BEC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B6E04(rdram, ctx);
        goto after_1;
    // 0x800B6BEC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x800B6BF0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B6BF4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800B6BF8: nop

    // 0x800B6BFC: bgez        $t9, L_800B6C0C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B6C00: nop
    
            goto L_800B6C0C;
    }
    // 0x800B6C00: nop

    // 0x800B6C04: b           L_800B6CB8
    // 0x800B6C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800B6CB8;
    // 0x800B6C08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B6C0C:
    // 0x800B6C0C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800B6C10: lw          $t0, 0x3068($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3068);
    // 0x800B6C14: nop

    // 0x800B6C18: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x800B6C1C: nop

    // 0x800B6C20: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x800B6C24: sh          $t2, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r10;
    // 0x800B6C28: b           L_800B6CA8
    // 0x800B6C2C: nop

        goto L_800B6CA8;
    // 0x800B6C2C: nop

L_800B6C30:
    // 0x800B6C30: jal         0x800B73DC
    // 0x800B6C34: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B73DC(rdram, ctx);
        goto after_2;
    // 0x800B6C34: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x800B6C38: beq         $v0, $zero, L_800B6C48
    if (ctx->r2 == 0) {
        // 0x800B6C3C: nop
    
            goto L_800B6C48;
    }
    // 0x800B6C3C: nop

    // 0x800B6C40: b           L_800B6CB8
    // 0x800B6C44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B6CB8;
    // 0x800B6C44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B6C48:
    // 0x800B6C48: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800B6C4C: lw          $t3, 0x3068($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3068);
    // 0x800B6C50: nop

    // 0x800B6C54: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x800B6C58: nop

    // 0x800B6C5C: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x800B6C60: sh          $t5, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r13;
    // 0x800B6C64: b           L_800B6CA8
    // 0x800B6C68: nop

        goto L_800B6CA8;
    // 0x800B6C68: nop

L_800B6C6C:
    // 0x800B6C6C: jal         0x800B749C
    // 0x800B6C70: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800B749C(rdram, ctx);
        goto after_3;
    // 0x800B6C70: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x800B6C74: beq         $v0, $zero, L_800B6C84
    if (ctx->r2 == 0) {
        // 0x800B6C78: nop
    
            goto L_800B6C84;
    }
    // 0x800B6C78: nop

    // 0x800B6C7C: b           L_800B6CB8
    // 0x800B6C80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B6CB8;
    // 0x800B6C80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B6C84:
    // 0x800B6C84: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800B6C88: lw          $t8, 0x3068($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3068);
    // 0x800B6C8C: nop

    // 0x800B6C90: lhu         $t7, 0x4($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X4);
    // 0x800B6C94: nop

    // 0x800B6C98: ori         $t6, $t7, 0x80
    ctx->r14 = ctx->r15 | 0X80;
    // 0x800B6C9C: sh          $t6, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r14;
    // 0x800B6CA0: b           L_800B6CA8
    // 0x800B6CA4: nop

        goto L_800B6CA8;
    // 0x800B6CA4: nop

L_800B6CA8:
    // 0x800B6CA8: b           L_800B6CB8
    // 0x800B6CAC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_800B6CB8;
    // 0x800B6CAC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800B6CB0: b           L_800B6CB8
    // 0x800B6CB4: nop

        goto L_800B6CB8;
    // 0x800B6CB4: nop

L_800B6CB8:
    // 0x800B6CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B6CBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B6CC0: jr          $ra
    // 0x800B6CC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B6CC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80034F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034F90: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80034F94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80034F98: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x80034F9C: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
    // 0x80034FA0: swc1        $f14, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f14.u32l;
    // 0x80034FA4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80034FA8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80034FAC: addiu       $t7, $t7, -0x3F78
    ctx->r15 = ADD32(ctx->r15, -0X3F78);
    // 0x80034FB0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80034FB4: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x80034FB8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80034FBC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80034FC0: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80034FC4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80034FC8: lhu         $at, 0xC($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0XC);
    // 0x80034FCC: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80034FD0: sh          $at, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r1;
    // 0x80034FD4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80034FD8: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x80034FDC: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80034FE0: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x80034FE4: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80034FE8: lwr         $at, 0x6($t1)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r9, 0X6);
    // 0x80034FEC: nop

    // 0x80034FF0: swr         $at, 0x6($t0)
    do_swr(rdram, 0X6, ctx->r8, ctx->r1);
    // 0x80034FF4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80034FF8: lw          $t4, 0x7220($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7220);
    // 0x80034FFC: nop

    // 0x80035000: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80035004: jal         0x800C1680
    // 0x80035008: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x80035008: nop

    after_0:
    // 0x8003500C: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
L_80035010:
    // 0x80035010: lhu         $t5, 0x9E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X9E);
    // 0x80035014: nop

    // 0x80035018: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x8003501C: addu        $a0, $sp, $t8
    ctx->r4 = ADD32(ctx->r29, ctx->r24);
    // 0x80035020: lhu         $a0, 0x3C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3C);
    // 0x80035024: jal         0x8005F064
    // 0x80035028: nop

    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80035028: nop

    after_1:
    // 0x8003502C: bne         $v0, $zero, L_80035318
    if (ctx->r2 != 0) {
        // 0x80035030: nop
    
            goto L_80035318;
    }
    // 0x80035030: nop

    // 0x80035034: lhu         $t6, 0x9E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X9E);
    // 0x80035038: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8003503C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80035040: addu        $t9, $sp, $t7
    ctx->r25 = ADD32(ctx->r29, ctx->r15);
    // 0x80035044: lhu         $t9, 0x3C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X3C);
    // 0x80035048: nop

    // 0x8003504C: bne         $t9, $at, L_80035064
    if (ctx->r25 != ctx->r1) {
        // 0x80035050: nop
    
            goto L_80035064;
    }
    // 0x80035050: nop

    // 0x80035054: jal         0x8005F064
    // 0x80035058: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8005F064(rdram, ctx);
        goto after_2;
    // 0x80035058: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_2:
    // 0x8003505C: beq         $v0, $zero, L_80035318
    if (ctx->r2 == 0) {
        // 0x80035060: nop
    
            goto L_80035318;
    }
    // 0x80035060: nop

L_80035064:
    // 0x80035064: jal         0x800C1850
    // 0x80035068: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_3;
    // 0x80035068: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8003506C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80035070: nop

    // 0x80035074: lwc1        $f12, 0x0($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80035078: lwc1        $f14, 0x4($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8003507C: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x80035080: jal         0x800C2304
    // 0x80035084: nop

    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_4;
    // 0x80035084: nop

    after_4:
    // 0x80035088: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8003508C: nop

    // 0x80035090: lwc1        $f12, 0xC($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80035094: jal         0x800C25B8
    // 0x80035098: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_5;
    // 0x80035098: nop

    after_5:
    // 0x8003509C: jal         0x800C2070
    // 0x800350A0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800C2070(rdram, ctx);
        goto after_6;
    // 0x800350A0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_6:
    // 0x800350A4: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x800350A8: lwc1        $f12, 0x30($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X30);
    // 0x800350AC: lwc1        $f14, 0x34($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X34);
    // 0x800350B0: lw          $a2, 0x38($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X38);
    // 0x800350B4: jal         0x800AF1F0
    // 0x800350B8: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800AF1F0(rdram, ctx);
        goto after_7;
    // 0x800350B8: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_7:
    // 0x800350BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800350C0: beq         $v0, $at, L_80035120
    if (ctx->r2 == ctx->r1) {
        // 0x800350C4: nop
    
            goto L_80035120;
    }
    // 0x800350C4: nop

    // 0x800350C8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800350CC: lw          $t3, 0x258C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X258C);
    // 0x800350D0: nop

    // 0x800350D4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800350D8: bgez        $t3, L_800350F0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800350DC: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800350F0;
    }
    // 0x800350DC: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800350E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800350E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800350E8: nop

    // 0x800350EC: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_800350F0:
    // 0x800350F0: jal         0x800C25B8
    // 0x800350F4: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_8;
    // 0x800350F4: nop

    after_8:
    // 0x800350F8: lhu         $t5, 0x9E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X9E);
    // 0x800350FC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80035100: addu        $t8, $sp, $t5
    ctx->r24 = ADD32(ctx->r29, ctx->r13);
    // 0x80035104: lbu         $t8, 0x34($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X34);
    // 0x80035108: lw          $t4, 0x722C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X722C);
    // 0x8003510C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80035110: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80035114: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80035118: jal         0x800A42C8
    // 0x8003511C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800A42C8(rdram, ctx);
        goto after_9;
    // 0x8003511C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_9:
L_80035120:
    // 0x80035120: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80035124: nop

    // 0x80035128: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8003512C: nop

    // 0x80035130: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x80035134: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80035138: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003513C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80035140: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80035144: nop

    // 0x80035148: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003514C: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x80035150: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80035154: nop

    // 0x80035158: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8003515C: nop

    // 0x80035160: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x80035164: lwc1        $f12, 0x98($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80035168: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8003516C: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80035170: jal         0x80034E9C
    // 0x80035174: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    func_80034E9C(rdram, ctx);
        goto after_10;
    // 0x80035174: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_10:
    // 0x80035178: bne         $v0, $zero, L_800351D4
    if (ctx->r2 != 0) {
        // 0x8003517C: nop
    
            goto L_800351D4;
    }
    // 0x8003517C: nop

    // 0x80035180: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80035184: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80035188: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8003518C: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80035190: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80035194: lwc1        $f12, 0x98($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80035198: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8003519C: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x800351A0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800351A4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800351A8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800351AC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800351B0: jal         0x800C3C80
    // 0x800351B4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    MathUtil_GetDistanceIfWithinRadius(rdram, ctx);
        goto after_11;
    // 0x800351B4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x800351B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800351BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800351C0: nop

    // 0x800351C4: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x800351C8: nop

    // 0x800351CC: bc1t        L_80035318
    if (c1cs) {
        // 0x800351D0: nop
    
            goto L_80035318;
    }
    // 0x800351D0: nop

L_800351D4:
    // 0x800351D4: lhu         $t1, 0x9E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X9E);
    // 0x800351D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800351DC: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x800351E0: addu        $t5, $sp, $t3
    ctx->r13 = ADD32(ctx->r29, ctx->r11);
    // 0x800351E4: lhu         $t5, 0x3C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X3C);
    // 0x800351E8: nop

    // 0x800351EC: sll         $a0, $t5, 16
    ctx->r4 = S32(ctx->r13 << 16);
    // 0x800351F0: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800351F4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800351F8: jal         0x8005F0DC
    // 0x800351FC: sh          $t5, 0x654($at)
    MEM_H(0X654, ctx->r1) = ctx->r13;
    func_8005F0DC(rdram, ctx);
        goto after_12;
    // 0x800351FC: sh          $t5, 0x654($at)
    MEM_H(0X654, ctx->r1) = ctx->r13;
    after_12:
    // 0x80035200: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80035204: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80035208: sb          $t4, 0x7256($at)
    MEM_B(0X7256, ctx->r1) = ctx->r12;
    // 0x8003520C: jal         0x80031874
    // 0x80035210: nop

    func_80031874(rdram, ctx);
        goto after_13;
    // 0x80035210: nop

    after_13:
    // 0x80035214: bne         $v0, $zero, L_80035318
    if (ctx->r2 != 0) {
        // 0x80035218: nop
    
            goto L_80035318;
    }
    // 0x80035218: nop

    // 0x8003521C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80035220: lh          $s0, 0x654($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X654);
    // 0x80035224: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80035228: beq         $s0, $at, L_80035268
    if (ctx->r16 == ctx->r1) {
        // 0x8003522C: nop
    
            goto L_80035268;
    }
    // 0x8003522C: nop

    // 0x80035230: addiu       $at, $zero, 0xA7
    ctx->r1 = ADD32(0, 0XA7);
    // 0x80035234: beq         $s0, $at, L_80035278
    if (ctx->r16 == ctx->r1) {
        // 0x80035238: nop
    
            goto L_80035278;
    }
    // 0x80035238: nop

    // 0x8003523C: addiu       $at, $zero, 0xA8
    ctx->r1 = ADD32(0, 0XA8);
    // 0x80035240: beq         $s0, $at, L_80035288
    if (ctx->r16 == ctx->r1) {
        // 0x80035244: nop
    
            goto L_80035288;
    }
    // 0x80035244: nop

    // 0x80035248: addiu       $at, $zero, 0xA9
    ctx->r1 = ADD32(0, 0XA9);
    // 0x8003524C: beq         $s0, $at, L_80035298
    if (ctx->r16 == ctx->r1) {
        // 0x80035250: nop
    
            goto L_80035298;
    }
    // 0x80035250: nop

    // 0x80035254: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x80035258: beq         $s0, $at, L_800352A8
    if (ctx->r16 == ctx->r1) {
        // 0x8003525C: nop
    
            goto L_800352A8;
    }
    // 0x8003525C: nop

    // 0x80035260: b           L_800352B8
    // 0x80035264: nop

        goto L_800352B8;
    // 0x80035264: nop

L_80035268:
    // 0x80035268: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8003526C: sh          $t6, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r14;
    // 0x80035270: b           L_800352D4
    // 0x80035274: nop

        goto L_800352D4;
    // 0x80035274: nop

L_80035278:
    // 0x80035278: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8003527C: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    // 0x80035280: b           L_800352D4
    // 0x80035284: nop

        goto L_800352D4;
    // 0x80035284: nop

L_80035288:
    // 0x80035288: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x8003528C: sh          $t9, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r25;
    // 0x80035290: b           L_800352D4
    // 0x80035294: nop

        goto L_800352D4;
    // 0x80035294: nop

L_80035298:
    // 0x80035298: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8003529C: sh          $t2, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r10;
    // 0x800352A0: b           L_800352D4
    // 0x800352A4: nop

        goto L_800352D4;
    // 0x800352A4: nop

L_800352A8:
    // 0x800352A8: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800352AC: sh          $t0, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r8;
    // 0x800352B0: b           L_800352D4
    // 0x800352B4: nop

        goto L_800352D4;
    // 0x800352B4: nop

L_800352B8:
    // 0x800352B8: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x800352BC: sh          $t1, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r9;
    // 0x800352C0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800352C4: lw          $t3, 0x718C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X718C);
    // 0x800352C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800352CC: addiu       $t5, $t3, 0x1388
    ctx->r13 = ADD32(ctx->r11, 0X1388);
    // 0x800352D0: sw          $t5, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = ctx->r13;
L_800352D4:
    // 0x800352D4: jal         0x800B9000
    // 0x800352D8: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    func_800B9000(rdram, ctx);
        goto after_14;
    // 0x800352D8: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    after_14:
    // 0x800352DC: lhu         $t4, 0x9C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X9C);
    // 0x800352E0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800352E4: lw          $t8, 0x7284($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7284);
    // 0x800352E8: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800352EC: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800352F0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800352F4: jal         0x800319B0
    // 0x800352F8: nop

    func_800319B0(rdram, ctx);
        goto after_15;
    // 0x800352F8: nop

    after_15:
    // 0x800352FC: jal         0x80031B6C
    // 0x80035300: nop

    func_80031B6C(rdram, ctx);
        goto after_16;
    // 0x80035300: nop

    after_16:
    // 0x80035304: jal         0x80021F20
    // 0x80035308: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_17;
    // 0x80035308: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_17:
    // 0x8003530C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80035310: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80035314: swc1        $f4, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f4.u32l;
L_80035318:
    // 0x80035318: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8003531C: nop

    // 0x80035320: addiu       $t2, $t9, 0x10
    ctx->r10 = ADD32(ctx->r25, 0X10);
    // 0x80035324: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80035328: lhu         $t0, 0x9E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X9E);
    // 0x8003532C: nop

    // 0x80035330: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80035334: andi        $t3, $t1, 0xFFFF
    ctx->r11 = ctx->r9 & 0XFFFF;
    // 0x80035338: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x8003533C: bne         $at, $zero, L_80035010
    if (ctx->r1 != 0) {
        // 0x80035340: sh          $t1, 0x9E($sp)
        MEM_H(0X9E, ctx->r29) = ctx->r9;
            goto L_80035010;
    }
    // 0x80035340: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    // 0x80035344: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x80035348: lbu         $s0, 0x7256($s0)
    ctx->r16 = MEM_BU(ctx->r16, 0X7256);
    // 0x8003534C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80035350: beq         $s0, $at, L_8003536C
    if (ctx->r16 == ctx->r1) {
        // 0x80035354: nop
    
            goto L_8003536C;
    }
    // 0x80035354: nop

    // 0x80035358: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003535C: beq         $s0, $at, L_80035414
    if (ctx->r16 == ctx->r1) {
        // 0x80035360: nop
    
            goto L_80035414;
    }
    // 0x80035360: nop

    // 0x80035364: b           L_8003545C
    // 0x80035368: nop

        goto L_8003545C;
    // 0x80035368: nop

L_8003536C:
    // 0x8003536C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80035370: lwc1        $f6, 0x50D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x80035374: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80035378: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8003537C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80035380: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80035384: swc1        $f10, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f10.u32l;
    // 0x80035388: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003538C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80035390: nop

    // 0x80035394: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80035398: nop

    // 0x8003539C: bc1f        L_8003540C
    if (!c1cs) {
        // 0x800353A0: nop
    
            goto L_8003540C;
    }
    // 0x800353A0: nop

    // 0x800353A4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800353A8: lbu         $t5, 0x7256($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7256);
    // 0x800353AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800353B0: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800353B4: sb          $t4, 0x7256($at)
    MEM_B(0X7256, ctx->r1) = ctx->r12;
    // 0x800353B8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800353BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800353C0: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
    // 0x800353C4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800353C8: lh          $t8, 0x654($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X654);
    // 0x800353CC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800353D0: bne         $t8, $at, L_800353F4
    if (ctx->r24 != ctx->r1) {
        // 0x800353D4: nop
    
            goto L_800353F4;
    }
    // 0x800353D4: nop

    // 0x800353D8: jal         0x80021ED0
    // 0x800353DC: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_18;
    // 0x800353DC: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_18:
    // 0x800353E0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800353E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800353E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800353EC: b           L_8003540C
    // 0x800353F0: swc1        $f4, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f4.u32l;
        goto L_8003540C;
    // 0x800353F0: swc1        $f4, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f4.u32l;
L_800353F4:
    // 0x800353F4: jal         0x80021ED0
    // 0x800353F8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_19;
    // 0x800353F8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_19:
    // 0x800353FC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80035400: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035404: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80035408: swc1        $f6, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f6.u32l;
L_8003540C:
    // 0x8003540C: b           L_8003545C
    // 0x80035410: nop

        goto L_8003545C;
    // 0x80035410: nop

L_80035414:
    // 0x80035414: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80035418: lwc1        $f8, 0x50D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X50D0);
    // 0x8003541C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80035420: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80035424: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80035428: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003542C: swc1        $f16, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f16.u32l;
    // 0x80035430: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80035434: lwc1        $f18, 0x50D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X50D8);
    // 0x80035438: nop

    // 0x8003543C: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80035440: nop

    // 0x80035444: bc1f        L_8003545C
    if (!c1cs) {
        // 0x80035448: nop
    
            goto L_8003545C;
    }
    // 0x80035448: nop

    // 0x8003544C: jal         0x80021ED0
    // 0x80035450: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_20;
    // 0x80035450: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_20:
    // 0x80035454: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80035458: sb          $zero, 0x7256($at)
    MEM_B(0X7256, ctx->r1) = 0;
L_8003545C:
    // 0x8003545C: jal         0x800C1A28
    // 0x80035460: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_21;
    // 0x80035460: nop

    after_21:
    // 0x80035464: b           L_8003546C
    // 0x80035468: nop

        goto L_8003546C;
    // 0x80035468: nop

L_8003546C:
    // 0x8003546C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80035470: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80035474: jr          $ra
    // 0x80035478: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80035478: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8007762C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007762C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077630: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077634: nop

    // 0x80077638: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x8007763C: nop

    // 0x80077640: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077644: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077648: jr          $ra
    // 0x8007764C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007764C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077650: jr          $ra
    // 0x80077654: nop

    return;
    // 0x80077654: nop

    // 0x80077658: jr          $ra
    // 0x8007765C: nop

    return;
    // 0x8007765C: nop

;}
RECOMP_FUNC void func_80062878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006287C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062880: jal         0x8005F064
    // 0x80062884: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062884: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    after_0:
    // 0x80062888: b           L_80062898
    // 0x8006288C: nop

        goto L_80062898;
    // 0x8006288C: nop

    // 0x80062890: b           L_80062898
    // 0x80062894: nop

        goto L_80062898;
    // 0x80062894: nop

L_80062898:
    // 0x80062898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006289C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800628A0: jr          $ra
    // 0x800628A4: nop

    return;
    // 0x800628A4: nop

;}
RECOMP_FUNC void func_80099FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099FB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80099FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099FB8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80099FBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80099FC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80099FC4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80099FC8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80099FCC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80099FD0: lwc1        $f17, -0x850($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X850);
    // 0x80099FD4: lwc1        $f16, -0x84C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X84C);
    // 0x80099FD8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80099FDC: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80099FE0: jal         0x800C3650
    // 0x80099FE4: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    func_800C3650(rdram, ctx);
        goto after_0;
    // 0x80099FE4: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_0:
    // 0x80099FE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80099FEC: lwc1        $f5, -0x848($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X848);
    // 0x80099FF0: lwc1        $f4, -0x844($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X844);
    // 0x80099FF4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80099FF8: nop

    // 0x80099FFC: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8009A000: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x8009A004: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8009A008: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009A00C: nop

    // 0x8009A010: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8009A014: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8009A018: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8009A01C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8009A020: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009A024: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8009A028: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8009A02C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009A030: swc1        $f8, 0x7218($at)
    MEM_W(0X7218, ctx->r1) = ctx->f8.u32l;
    // 0x8009A034: b           L_8009A03C
    // 0x8009A038: nop

        goto L_8009A03C;
    // 0x8009A038: nop

L_8009A03C:
    // 0x8009A03C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009A040: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009A044: jr          $ra
    // 0x8009A048: nop

    return;
    // 0x8009A048: nop

;}
RECOMP_FUNC void func_80066C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066C58: jal         0x80061348
    // 0x80066C5C: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066C5C: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    after_0:
    // 0x80066C60: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066C64: b           L_80066C74
    // 0x80066C68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066C74;
    // 0x80066C68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066C6C: b           L_80066C74
    // 0x80066C70: nop

        goto L_80066C74;
    // 0x80066C70: nop

L_80066C74:
    // 0x80066C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066C7C: jr          $ra
    // 0x80066C80: nop

    return;
    // 0x80066C80: nop

;}
RECOMP_FUNC void func_800733B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800733B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800733B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800733B8: jal         0x8005F064
    // 0x800733BC: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800733BC: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_0:
    // 0x800733C0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800733C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800733C8: bne         $v0, $zero, L_800733E0
    if (ctx->r2 != 0) {
        // 0x800733CC: nop
    
            goto L_800733E0;
    }
    // 0x800733CC: nop

    // 0x800733D0: jal         0x80061488
    // 0x800733D4: addiu       $a0, $zero, 0x63E
    ctx->r4 = ADD32(0, 0X63E);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x800733D4: addiu       $a0, $zero, 0x63E
    ctx->r4 = ADD32(0, 0X63E);
    after_1:
    // 0x800733D8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800733DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800733E0:
    // 0x800733E0: b           L_800733F0
    // 0x800733E4: nop

        goto L_800733F0;
    // 0x800733E4: nop

    // 0x800733E8: b           L_800733F0
    // 0x800733EC: nop

        goto L_800733F0;
    // 0x800733EC: nop

L_800733F0:
    // 0x800733F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800733F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800733F8: jr          $ra
    // 0x800733FC: nop

    return;
    // 0x800733FC: nop

;}
RECOMP_FUNC void func_80077660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077660: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077664: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077668: nop

    // 0x8007766C: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80077670: nop

    // 0x80077674: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077678: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007767C: jr          $ra
    // 0x80077680: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077680: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077684: jr          $ra
    // 0x80077688: nop

    return;
    // 0x80077688: nop

    // 0x8007768C: jr          $ra
    // 0x80077690: nop

    return;
    // 0x80077690: nop

;}
RECOMP_FUNC void func_8006C270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C278: jal         0x8005F064
    // 0x8006C27C: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C27C: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_0:
    // 0x8006C280: b           L_8006C290
    // 0x8006C284: nop

        goto L_8006C290;
    // 0x8006C284: nop

    // 0x8006C288: b           L_8006C290
    // 0x8006C28C: nop

        goto L_8006C290;
    // 0x8006C28C: nop

L_8006C290:
    // 0x8006C290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C298: jr          $ra
    // 0x8006C29C: nop

    return;
    // 0x8006C29C: nop

;}
RECOMP_FUNC void func_8007001C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007001C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070024: jal         0x80061348
    // 0x80070028: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070028: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x8007002C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070030: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070034: beq         $v0, $zero, L_80070084
    if (ctx->r2 == 0) {
        // 0x80070038: nop
    
            goto L_80070084;
    }
    // 0x80070038: nop

    // 0x8007003C: jal         0x80061348
    // 0x80070040: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070040: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070044: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070048: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007004C: beq         $v0, $zero, L_80070084
    if (ctx->r2 == 0) {
        // 0x80070050: nop
    
            goto L_80070084;
    }
    // 0x80070050: nop

    // 0x80070054: jal         0x80061348
    // 0x80070058: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070058: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x8007005C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070060: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070064: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070068: beq         $v0, $zero, L_80070084
    if (ctx->r2 == 0) {
        // 0x8007006C: nop
    
            goto L_80070084;
    }
    // 0x8007006C: nop

    // 0x80070070: jal         0x80061348
    // 0x80070074: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070074: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070078: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007007C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070080: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070084:
    // 0x80070084: b           L_80070094
    // 0x80070088: nop

        goto L_80070094;
    // 0x80070088: nop

    // 0x8007008C: b           L_80070094
    // 0x80070090: nop

        goto L_80070094;
    // 0x80070090: nop

L_80070094:
    // 0x80070094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007009C: jr          $ra
    // 0x800700A0: nop

    return;
    // 0x800700A0: nop

;}
