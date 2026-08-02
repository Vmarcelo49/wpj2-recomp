#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80076B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076B4C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076B50: nop

    // 0x80076B54: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80076B58: nop

    // 0x80076B5C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076B60: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076B64: jr          $ra
    // 0x80076B68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076B68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076B6C: jr          $ra
    // 0x80076B70: nop

    return;
    // 0x80076B70: nop

    // 0x80076B74: jr          $ra
    // 0x80076B78: nop

    return;
    // 0x80076B78: nop

;}
RECOMP_FUNC void func_80014C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014C70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014C78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80014C7C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014C80: nop

    // 0x80014C84: lw          $t7, 0x20C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20C);
    // 0x80014C88: nop

    // 0x80014C8C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80014C90: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80014C94: nop

    // 0x80014C98: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x80014C9C: nop

    // 0x80014CA0: addiu       $t0, $t9, -0x4000
    ctx->r8 = ADD32(ctx->r25, -0X4000);
    // 0x80014CA4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80014CA8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80014CAC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80014CB0: nop

    // 0x80014CB4: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
    // 0x80014CB8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80014CBC: nop

    // 0x80014CC0: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80014CC4: nop

    // 0x80014CC8: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80014CCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80014CD0: jal         0x80099E2C
    // 0x80014CD4: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x80014CD4: nop

    after_0:
    // 0x80014CD8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80014CDC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80014CE0: lwc1        $f4, 0x1B0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X1B0);
    // 0x80014CE4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80014CE8: nop

    // 0x80014CEC: swc1        $f4, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f4.u32l;
    // 0x80014CF0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80014CF4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80014CF8: lwc1        $f6, 0x1B4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1B4);
    // 0x80014CFC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80014D00: nop

    // 0x80014D04: swc1        $f6, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f6.u32l;
    // 0x80014D08: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80014D0C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80014D10: lwc1        $f8, 0x1B8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1B8);
    // 0x80014D14: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80014D18: nop

    // 0x80014D1C: swc1        $f8, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f8.u32l;
    // 0x80014D20: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80014D24: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80014D28: lw          $t5, 0x1AC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1AC);
    // 0x80014D2C: nop

    // 0x80014D30: beq         $t5, $at, L_80014D44
    if (ctx->r13 == ctx->r1) {
        // 0x80014D34: nop
    
            goto L_80014D44;
    }
    // 0x80014D34: nop

    // 0x80014D38: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80014D3C: bne         $t5, $at, L_80014DA0
    if (ctx->r13 != ctx->r1) {
        // 0x80014D40: nop
    
            goto L_80014DA0;
    }
    // 0x80014D40: nop

L_80014D44:
    // 0x80014D44: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80014D48: lwc1        $f10, -0x2A70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2A70);
    // 0x80014D4C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80014D50: nop

    // 0x80014D54: swc1        $f10, 0x1B0($t6)
    MEM_W(0X1B0, ctx->r14) = ctx->f10.u32l;
    // 0x80014D58: lui         $at, 0x4479
    ctx->r1 = S32(0X4479 << 16);
    // 0x80014D5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80014D60: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80014D64: nop

    // 0x80014D68: swc1        $f16, 0x1B4($t7)
    MEM_W(0X1B4, ctx->r15) = ctx->f16.u32l;
    // 0x80014D6C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80014D70: nop

    // 0x80014D74: sh          $zero, 0x118($t8)
    MEM_H(0X118, ctx->r24) = 0;
    // 0x80014D78: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80014D7C: nop

    // 0x80014D80: sh          $zero, 0x11A($t9)
    MEM_H(0X11A, ctx->r25) = 0;
    // 0x80014D84: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80014D88: nop

    // 0x80014D8C: sh          $zero, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = 0;
    // 0x80014D90: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80014D94: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80014D98: b           L_80014F20
    // 0x80014D9C: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
        goto L_80014F20;
    // 0x80014D9C: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
L_80014DA0:
    // 0x80014DA0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80014DA4: nop

    // 0x80014DA8: lw          $t4, 0x1AC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1AC);
    // 0x80014DAC: nop

    // 0x80014DB0: slti        $at, $t4, 0x6000
    ctx->r1 = SIGNED(ctx->r12) < 0X6000 ? 1 : 0;
    // 0x80014DB4: beq         $at, $zero, L_80014F20
    if (ctx->r1 == 0) {
        // 0x80014DB8: nop
    
            goto L_80014F20;
    }
    // 0x80014DB8: nop

    // 0x80014DBC: jal         0x8000D164
    // 0x80014DC0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    TempHeap_Alloc(rdram, ctx);
        goto after_1;
    // 0x80014DC0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x80014DC4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80014DC8: nop

    // 0x80014DCC: sw          $v0, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r2;
    // 0x80014DD0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80014DD4: nop

    // 0x80014DD8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80014DDC: nop

    // 0x80014DE0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80014DE4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80014DE8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80014DEC: lw          $t9, 0x1AC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1AC);
    // 0x80014DF0: nop

    // 0x80014DF4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80014DF8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80014DFC: lw          $t1, -0x4EC4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4EC4);
    // 0x80014E00: nop

    // 0x80014E04: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80014E08: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80014E0C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80014E10: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80014E14: nop

    // 0x80014E18: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80014E1C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80014E20: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80014E24: nop

    // 0x80014E28: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x80014E2C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80014E30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80014E34: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80014E38: jal         0x800AFB70
    // 0x80014E3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_2;
    // 0x80014E3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80014E40: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80014E44: nop

    // 0x80014E48: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
    // 0x80014E4C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80014E50: nop

    // 0x80014E54: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x80014E58: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80014E5C: nop

    // 0x80014E60: addiu       $t1, $t0, 0x24
    ctx->r9 = ADD32(ctx->r8, 0X24);
    // 0x80014E64: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80014E68: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80014E6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80014E70: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80014E74: nop

    // 0x80014E78: beq         $t3, $at, L_80014F20
    if (ctx->r11 == ctx->r1) {
        // 0x80014E7C: nop
    
            goto L_80014F20;
    }
    // 0x80014E7C: nop

L_80014E80:
    // 0x80014E80: jal         0x800BC6EC
    // 0x80014E84: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80014E84: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x80014E88: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80014E8C: nop

    // 0x80014E90: sw          $v0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r2;
    // 0x80014E94: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80014E98: nop

    // 0x80014E9C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80014EA0: nop

    // 0x80014EA4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80014EA8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80014EAC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80014EB0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80014EB4: nop

    // 0x80014EB8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80014EBC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80014EC0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80014EC4: nop

    // 0x80014EC8: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80014ECC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80014ED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80014ED4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80014ED8: jal         0x800AFB70
    // 0x80014EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800AFB70(rdram, ctx);
        goto after_4;
    // 0x80014EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80014EE0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80014EE4: nop

    // 0x80014EE8: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // 0x80014EEC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80014EF0: nop

    // 0x80014EF4: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
    // 0x80014EF8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80014EFC: nop

    // 0x80014F00: addiu       $t6, $t5, 0x24
    ctx->r14 = ADD32(ctx->r13, 0X24);
    // 0x80014F04: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80014F08: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80014F0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80014F10: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80014F14: nop

    // 0x80014F18: bne         $t8, $at, L_80014E80
    if (ctx->r24 != ctx->r1) {
        // 0x80014F1C: nop
    
            goto L_80014E80;
    }
    // 0x80014F1C: nop

L_80014F20:
    // 0x80014F20: b           L_80014F28
    // 0x80014F24: nop

        goto L_80014F28;
    // 0x80014F24: nop

L_80014F28:
    // 0x80014F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014F2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014F30: jr          $ra
    // 0x80014F34: nop

    return;
    // 0x80014F34: nop

;}
RECOMP_FUNC void func_800805C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800805C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800805C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800805CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800805D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800805D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800805D8: jal         0x80080698
    // 0x800805DC: nop

    func_80080698(rdram, ctx);
        goto after_0;
    // 0x800805DC: nop

    after_0:
    // 0x800805E0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800805E4: nop

    // 0x800805E8: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x800805EC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800805F0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800805F4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800805F8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800805FC: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80080600: nop

    // 0x80080604: beq         $t9, $at, L_8008063C
    if (ctx->r25 == ctx->r1) {
        // 0x80080608: nop
    
            goto L_8008063C;
    }
    // 0x80080608: nop

    // 0x8008060C: beq         $t9, $zero, L_8008063C
    if (ctx->r25 == 0) {
        // 0x80080610: nop
    
            goto L_8008063C;
    }
    // 0x80080610: nop

L_80080614:
    // 0x80080614: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80080618: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008061C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80080620: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80080624: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80080628: nop

    // 0x8008062C: beq         $t2, $at, L_8008063C
    if (ctx->r10 == ctx->r1) {
        // 0x80080630: nop
    
            goto L_8008063C;
    }
    // 0x80080630: nop

    // 0x80080634: bne         $t2, $zero, L_80080614
    if (ctx->r10 != 0) {
        // 0x80080638: nop
    
            goto L_80080614;
    }
    // 0x80080638: nop

L_8008063C:
    // 0x8008063C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80080640: nop

    // 0x80080644: bltz        $t3, L_80080674
    if (SIGNED(ctx->r11) < 0) {
        // 0x80080648: nop
    
            goto L_80080674;
    }
    // 0x80080648: nop

L_8008064C:
    // 0x8008064C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80080650: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80080654: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x80080658: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008065C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80080660: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80080664: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80080668: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008066C: bgez        $t7, L_8008064C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80080670: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8008064C;
    }
    // 0x80080670: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80080674:
    // 0x80080674: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80080678: nop

    // 0x8008067C: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x80080680: b           L_80080688
    // 0x80080684: nop

        goto L_80080688;
    // 0x80080684: nop

L_80080688:
    // 0x80080688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008068C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80080690: jr          $ra
    // 0x80080694: nop

    return;
    // 0x80080694: nop

;}
RECOMP_FUNC void func_800654C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800654C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800654C8: jal         0x80061488
    // 0x800654CC: addiu       $a0, $zero, 0x74C
    ctx->r4 = ADD32(0, 0X74C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800654CC: addiu       $a0, $zero, 0x74C
    ctx->r4 = ADD32(0, 0X74C);
    after_0:
    // 0x800654D0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800654D4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800654D8: b           L_800654E8
    // 0x800654DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800654E8;
    // 0x800654DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800654E0: b           L_800654E8
    // 0x800654E4: nop

        goto L_800654E8;
    // 0x800654E4: nop

L_800654E8:
    // 0x800654E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800654EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800654F0: jr          $ra
    // 0x800654F4: nop

    return;
    // 0x800654F4: nop

;}
RECOMP_FUNC void func_80076518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076518: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007651C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076520: nop

    // 0x80076524: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80076528: nop

    // 0x8007652C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80076530: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80076534: jr          $ra
    // 0x80076538: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076538: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007653C: jr          $ra
    // 0x80076540: nop

    return;
    // 0x80076540: nop

    // 0x80076544: jr          $ra
    // 0x80076548: nop

    return;
    // 0x80076548: nop

;}
RECOMP_FUNC void func_80091E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091E34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80091E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091E3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80091E40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80091E44: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80091E48:
    // 0x80091E48: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80091E4C: lw          $t6, 0x6BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA0);
    // 0x80091E50: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80091E54: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80091E58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091E5C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80091E60: lwc1        $f8, -0x4CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4CBC);
    // 0x80091E64: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80091E68: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80091E6C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80091E70: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80091E74: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80091E78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80091E7C: lw          $t8, 0x6B98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6B98);
    // 0x80091E80: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80091E84: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80091E88: lw          $t9, 0x6C14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C14);
    // 0x80091E8C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80091E90: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80091E94: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80091E98: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80091E9C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80091EA0: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80091EA4: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80091EA8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80091EAC: nop

    // 0x80091EB0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80091EB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80091EB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80091EBC: nop

    // 0x80091EC0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80091EC4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80091EC8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80091ECC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80091ED0: nop

    // 0x80091ED4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80091ED8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80091EDC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80091EE0: lw          $t7, -0x790($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X790);
    // 0x80091EE4: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x80091EE8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80091EEC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80091EF0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80091EF4: lbu         $t9, -0x400($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0X400);
    // 0x80091EF8: nop

    // 0x80091EFC: sb          $t9, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r25;
    // 0x80091F00: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091F04: nop

    // 0x80091F08: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80091F0C: beq         $t1, $zero, L_80091F3C
    if (ctx->r9 == 0) {
        // 0x80091F10: nop
    
            goto L_80091F3C;
    }
    // 0x80091F10: nop

    // 0x80091F14: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091F18: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091F1C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091F20: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091F24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091F28: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091F2C: jal         0x80090784
    // 0x80091F30: nop

    func_80090784(rdram, ctx);
        goto after_0;
    // 0x80091F30: nop

    after_0:
    // 0x80091F34: b           L_80091F5C
    // 0x80091F38: nop

        goto L_80091F5C;
    // 0x80091F38: nop

L_80091F3C:
    // 0x80091F3C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091F40: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091F44: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091F48: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091F4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091F50: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091F54: jal         0x80090784
    // 0x80091F58: nop

    func_80090784(rdram, ctx);
        goto after_1;
    // 0x80091F58: nop

    after_1:
L_80091F5C:
    // 0x80091F5C: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091F60: nop

    // 0x80091F64: andi        $t4, $t2, 0x40
    ctx->r12 = ctx->r10 & 0X40;
    // 0x80091F68: beq         $t4, $zero, L_80091F98
    if (ctx->r12 == 0) {
        // 0x80091F6C: nop
    
            goto L_80091F98;
    }
    // 0x80091F6C: nop

    // 0x80091F70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091F74: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091F78: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091F7C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091F80: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091F84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091F88: jal         0x80090784
    // 0x80091F8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_2;
    // 0x80091F8C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x80091F90: b           L_80091FB8
    // 0x80091F94: nop

        goto L_80091FB8;
    // 0x80091F94: nop

L_80091F98:
    // 0x80091F98: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091F9C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091FA0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091FA4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091FA8: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80091FAC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091FB0: jal         0x80090784
    // 0x80091FB4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_80090784(rdram, ctx);
        goto after_3;
    // 0x80091FB4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_3:
L_80091FB8:
    // 0x80091FB8: lbu         $t3, 0x1F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1F);
    // 0x80091FBC: nop

    // 0x80091FC0: andi        $t5, $t3, 0x20
    ctx->r13 = ctx->r11 & 0X20;
    // 0x80091FC4: beq         $t5, $zero, L_80091FF4
    if (ctx->r13 == 0) {
        // 0x80091FC8: nop
    
            goto L_80091FF4;
    }
    // 0x80091FC8: nop

    // 0x80091FCC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091FD0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091FD4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80091FD8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80091FDC: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80091FE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80091FE4: jal         0x80090784
    // 0x80091FE8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_4;
    // 0x80091FE8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_4:
    // 0x80091FEC: b           L_80092014
    // 0x80091FF0: nop

        goto L_80092014;
    // 0x80091FF0: nop

L_80091FF4:
    // 0x80091FF4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80091FF8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80091FFC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092000: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092004: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092008: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009200C: jal         0x80090784
    // 0x80092010: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80090784(rdram, ctx);
        goto after_5;
    // 0x80092010: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_5:
L_80092014:
    // 0x80092014: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80092018: nop

    // 0x8009201C: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80092020: beq         $t7, $zero, L_80092050
    if (ctx->r15 == 0) {
        // 0x80092024: nop
    
            goto L_80092050;
    }
    // 0x80092024: nop

    // 0x80092028: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009202C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092030: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092034: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092038: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x8009203C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092040: jal         0x80090784
    // 0x80092044: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_6;
    // 0x80092044: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_6:
    // 0x80092048: b           L_80092070
    // 0x8009204C: nop

        goto L_80092070;
    // 0x8009204C: nop

L_80092050:
    // 0x80092050: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092054: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092058: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009205C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092060: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092064: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092068: jal         0x80090784
    // 0x8009206C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    func_80090784(rdram, ctx);
        goto after_7;
    // 0x8009206C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    after_7:
L_80092070:
    // 0x80092070: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x80092074: nop

    // 0x80092078: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8009207C: beq         $t9, $zero, L_800920AC
    if (ctx->r25 == 0) {
        // 0x80092080: nop
    
            goto L_800920AC;
    }
    // 0x80092080: nop

    // 0x80092084: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092088: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009208C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092090: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092094: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092098: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009209C: jal         0x80090784
    // 0x800920A0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_8;
    // 0x800920A0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_8:
    // 0x800920A4: b           L_800920CC
    // 0x800920A8: nop

        goto L_800920CC;
    // 0x800920A8: nop

L_800920AC:
    // 0x800920AC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800920B0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800920B4: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800920B8: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800920BC: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800920C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800920C4: jal         0x80090784
    // 0x800920C8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_80090784(rdram, ctx);
        goto after_9;
    // 0x800920C8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_9:
L_800920CC:
    // 0x800920CC: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x800920D0: nop

    // 0x800920D4: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x800920D8: beq         $t1, $zero, L_80092108
    if (ctx->r9 == 0) {
        // 0x800920DC: nop
    
            goto L_80092108;
    }
    // 0x800920DC: nop

    // 0x800920E0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800920E4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800920E8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800920EC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800920F0: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800920F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800920F8: jal         0x80090784
    // 0x800920FC: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_10;
    // 0x800920FC: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_10:
    // 0x80092100: b           L_80092128
    // 0x80092104: nop

        goto L_80092128;
    // 0x80092104: nop

L_80092108:
    // 0x80092108: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009210C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092110: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092114: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092118: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009211C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092120: jal         0x80090784
    // 0x80092124: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    func_80090784(rdram, ctx);
        goto after_11;
    // 0x80092124: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    after_11:
L_80092128:
    // 0x80092128: lbu         $t2, 0x1F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1F);
    // 0x8009212C: nop

    // 0x80092130: andi        $t4, $t2, 0x2
    ctx->r12 = ctx->r10 & 0X2;
    // 0x80092134: beq         $t4, $zero, L_80092164
    if (ctx->r12 == 0) {
        // 0x80092138: nop
    
            goto L_80092164;
    }
    // 0x80092138: nop

    // 0x8009213C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092140: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092144: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092148: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009214C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092150: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092154: jal         0x80090784
    // 0x80092158: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_12;
    // 0x80092158: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_12:
    // 0x8009215C: b           L_80092184
    // 0x80092160: nop

        goto L_80092184;
    // 0x80092160: nop

L_80092164:
    // 0x80092164: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092168: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8009216C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092170: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092174: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x80092178: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009217C: jal         0x80090784
    // 0x80092180: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    func_80090784(rdram, ctx);
        goto after_13;
    // 0x80092180: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_13:
L_80092184:
    // 0x80092184: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80092188: beq         $zero, $t3, L_800921E0
    if (0 == ctx->r11) {
        // 0x8009218C: nop
    
            goto L_800921E0;
    }
    // 0x8009218C: nop

    // 0x80092190: b           L_80092268
    // 0x80092194: nop

        goto L_80092268;
    // 0x80092194: nop

    // 0x80092198: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009219C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800921A0: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800921A4: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800921A8: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x800921AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800921B0: jal         0x80090784
    // 0x800921B4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_14;
    // 0x800921B4: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_14:
    // 0x800921B8: b           L_800921E0
    // 0x800921BC: nop

        goto L_800921E0;
    // 0x800921BC: nop

    // 0x800921C0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800921C4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800921C8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800921CC: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800921D0: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800921D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800921D8: jal         0x80090784
    // 0x800921DC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_15;
    // 0x800921DC: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_15:
L_800921E0:
    // 0x800921E0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800921E4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800921E8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800921EC: lw          $t1, -0x790($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X790);
    // 0x800921F0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800921F4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800921F8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800921FC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80092200: lbu         $t4, -0x3FF($t2)
    ctx->r12 = MEM_BU(ctx->r10, -0X3FF);
    // 0x80092204: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80092208: beq         $t4, $zero, L_80092268
    if (ctx->r12 == 0) {
        // 0x8009220C: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_80092268;
    }
    // 0x8009220C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80092210: sltiu       $t1, $t4, 0x9
    ctx->r9 = ctx->r12 < 0X9 ? 1 : 0;
    // 0x80092214: beq         $t1, $zero, L_80092268
    if (ctx->r9 == 0) {
        // 0x80092218: nop
    
            goto L_80092268;
    }
    // 0x80092218: nop

    // 0x8009221C: b           L_80092268
    // 0x80092220: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_80092268;
    // 0x80092220: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80092224: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092228: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8009222C: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092230: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092238: jal         0x80090784
    // 0x8009223C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_16;
    // 0x8009223C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_16:
    // 0x80092240: b           L_80092268
    // 0x80092244: nop

        goto L_80092268;
    // 0x80092244: nop

    // 0x80092248: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009224C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092250: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092254: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x80092258: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x8009225C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092260: jal         0x80090784
    // 0x80092264: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80090784(rdram, ctx);
        goto after_17;
    // 0x80092264: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_17:
L_80092268:
    // 0x80092268: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8009226C: nop

    // 0x80092270: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80092274: beq         $t8, $zero, L_800922A4
    if (ctx->r24 == 0) {
        // 0x80092278: nop
    
            goto L_800922A4;
    }
    // 0x80092278: nop

    // 0x8009227C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80092280: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80092284: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80092288: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x8009228C: lw          $a0, -0x4CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CD8);
    // 0x80092290: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80092294: jal         0x80090784
    // 0x80092298: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_18;
    // 0x80092298: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_18:
    // 0x8009229C: b           L_800922C4
    // 0x800922A0: nop

        goto L_800922C4;
    // 0x800922A0: nop

L_800922A4:
    // 0x800922A4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800922A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800922AC: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x800922B0: lw          $a2, -0x44BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44BC);
    // 0x800922B4: lw          $a0, -0x4CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CE0);
    // 0x800922B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800922BC: jal         0x80090784
    // 0x800922C0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    func_80090784(rdram, ctx);
        goto after_19;
    // 0x800922C0: addiu       $a3, $a3, 0x7
    ctx->r7 = ADD32(ctx->r7, 0X7);
    after_19:
L_800922C4:
    // 0x800922C4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800922C8: nop

    // 0x800922CC: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800922D0: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x800922D4: bne         $at, $zero, L_80091E48
    if (ctx->r1 != 0) {
        // 0x800922D8: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_80091E48;
    }
    // 0x800922D8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800922DC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800922E0: lw          $t0, 0x6B98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6B98);
    // 0x800922E4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800922E8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800922EC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800922F0: sw          $t2, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r10;
    // 0x800922F4: b           L_800922FC
    // 0x800922F8: nop

        goto L_800922FC;
    // 0x800922F8: nop

L_800922FC:
    // 0x800922FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80092304: jr          $ra
    // 0x80092308: nop

    return;
    // 0x80092308: nop

;}
RECOMP_FUNC void func_80062968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006296C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062970: jal         0x8005F064
    // 0x80062974: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062974: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    after_0:
    // 0x80062978: b           L_80062988
    // 0x8006297C: nop

        goto L_80062988;
    // 0x8006297C: nop

    // 0x80062980: b           L_80062988
    // 0x80062984: nop

        goto L_80062988;
    // 0x80062984: nop

L_80062988:
    // 0x80062988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006298C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062990: jr          $ra
    // 0x80062994: nop

    return;
    // 0x80062994: nop

;}
RECOMP_FUNC void func_80083F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80083F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083F30: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80083F34: addiu       $t6, $t6, 0x4C0C
    ctx->r14 = ADD32(ctx->r14, 0X4C0C);
    // 0x80083F38: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80083F3C: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80083F40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083F44: beq         $t7, $at, L_80083FB8
    if (ctx->r15 == ctx->r1) {
        // 0x80083F48: nop
    
            goto L_80083FB8;
    }
    // 0x80083F48: nop

L_80083F4C:
    // 0x80083F4C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80083F50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083F54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80083F58: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80083F5C: lh          $a0, 0x4C0C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4C0C);
    // 0x80083F60: jal         0x8005F064
    // 0x80083F64: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80083F64: nop

    after_0:
    // 0x80083F68: beq         $v0, $zero, L_80083F94
    if (ctx->r2 == 0) {
        // 0x80083F6C: nop
    
            goto L_80083F94;
    }
    // 0x80083F6C: nop

    // 0x80083F70: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80083F74: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083F78: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80083F7C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80083F80: lh          $v0, 0x4C0E($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4C0E);
    // 0x80083F84: b           L_80083FC8
    // 0x80083F88: nop

        goto L_80083FC8;
    // 0x80083F88: nop

    // 0x80083F8C: b           L_80083FB8
    // 0x80083F90: nop

        goto L_80083FB8;
    // 0x80083F90: nop

L_80083F94:
    // 0x80083F94: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80083F98: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80083F9C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80083FA0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80083FA4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80083FA8: lh          $t5, 0x4C0C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X4C0C);
    // 0x80083FAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083FB0: bne         $t5, $at, L_80083F4C
    if (ctx->r13 != ctx->r1) {
        // 0x80083FB4: sw          $t3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r11;
            goto L_80083F4C;
    }
    // 0x80083FB4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
L_80083FB8:
    // 0x80083FB8: b           L_80083FC8
    // 0x80083FBC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80083FC8;
    // 0x80083FBC: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x80083FC0: b           L_80083FC8
    // 0x80083FC4: nop

        goto L_80083FC8;
    // 0x80083FC4: nop

L_80083FC8:
    // 0x80083FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083FCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083FD0: jr          $ra
    // 0x80083FD4: nop

    return;
    // 0x80083FD4: nop

;}
RECOMP_FUNC void func_800631F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800631F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800631FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063200: jal         0x8005F064
    // 0x80063204: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063204: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x80063208: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006320C: b           L_8006321C
    // 0x80063210: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006321C;
    // 0x80063210: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063214: b           L_8006321C
    // 0x80063218: nop

        goto L_8006321C;
    // 0x80063218: nop

L_8006321C:
    // 0x8006321C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063224: jr          $ra
    // 0x80063228: nop

    return;
    // 0x80063228: nop

;}
RECOMP_FUNC void MtxUtil_CopyCurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1A84: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C1A88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1A8C: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x800C1A90: nop

    // 0x800C1A94: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x800C1A98: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800C1A9C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800C1AA0: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800C1AA4:
    // 0x800C1AA4: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C1AA8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800C1AAC: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C1AB0: nop

    // 0x800C1AB4: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x800C1AB8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800C1ABC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800C1AC0: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800C1AC4: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800C1AC8: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800C1ACC: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // 0x800C1AD0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C1AD4: nop

    // 0x800C1AD8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800C1ADC: bgtz        $t5, L_800C1AA4
    if (SIGNED(ctx->r13) > 0) {
        // 0x800C1AE0: sw          $t5, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r13;
            goto L_800C1AA4;
    }
    // 0x800C1AE0: sw          $t5, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r13;
    // 0x800C1AE4: b           L_800C1AEC
    // 0x800C1AE8: nop

        goto L_800C1AEC;
    // 0x800C1AE8: nop

L_800C1AEC:
    // 0x800C1AEC: jr          $ra
    // 0x800C1AF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C1AF0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80072AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072AA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072AAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072AB0: nop

    // 0x80072AB4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072AB8: nop

    // 0x80072ABC: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80072AC0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072AC4: jr          $ra
    // 0x80072AC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072AC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072ACC: jr          $ra
    // 0x80072AD0: nop

    return;
    // 0x80072AD0: nop

    // 0x80072AD4: jr          $ra
    // 0x80072AD8: nop

    return;
    // 0x80072AD8: nop

;}
RECOMP_FUNC void func_800767D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800767D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800767D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800767DC: nop

    // 0x800767E0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800767E4: nop

    // 0x800767E8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800767EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800767F0: jr          $ra
    // 0x800767F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800767F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800767F8: jr          $ra
    // 0x800767FC: nop

    return;
    // 0x800767FC: nop

    // 0x80076800: jr          $ra
    // 0x80076804: nop

    return;
    // 0x80076804: nop

;}
RECOMP_FUNC void func_80063C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063C18: jal         0x8005F064
    // 0x80063C1C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063C1C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063C20: b           L_80063C30
    // 0x80063C24: nop

        goto L_80063C30;
    // 0x80063C24: nop

    // 0x80063C28: b           L_80063C30
    // 0x80063C2C: nop

        goto L_80063C30;
    // 0x80063C2C: nop

L_80063C30:
    // 0x80063C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063C34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063C38: jr          $ra
    // 0x80063C3C: nop

    return;
    // 0x80063C3C: nop

;}
RECOMP_FUNC void alSndpNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9E14: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C9E18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9E1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C9E20: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C9E24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C9E28: addiu       $t8, $zero, 0x3E80
    ctx->r24 = ADD32(0, 0X3E80);
    // 0x800C9E2C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800C9E30: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    // 0x800C9E34: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800C9E38: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800C9E3C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800C9E40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C9E44: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x800C9E48: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800C9E4C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x800C9E50: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800C9E54: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C9E58: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800C9E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C9E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C9E64: jal         0x800C7950
    // 0x800C9E68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800C9E68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800C9E6C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9E70: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x800C9E74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C9E78: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800C9E7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C9E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C9E84: beq         $t2, $zero, L_800C9EA8
    if (ctx->r10 == 0) {
        // 0x800C9E88: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800C9EA8;
    }
    // 0x800C9E88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C9E8C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
L_800C9E90:
    // 0x800C9E90: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800C9E94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C9E98: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800C9E9C: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800C9EA0: bnel        $at, $zero, L_800C9E90
    if (ctx->r1 != 0) {
        // 0x800C9EA4: sw          $zero, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = 0;
            goto L_800C9E90;
    }
    goto skip_0;
    // 0x800C9EA4: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    skip_0:
L_800C9EA8:
    // 0x800C9EA8: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x800C9EAC: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x800C9EB0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800C9EB4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C9EB8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C9EBC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800C9EC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C9EC4: jal         0x800C7950
    // 0x800C9EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800C9EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800C9ECC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9ED0: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800C9ED4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C9ED8: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x800C9EDC: jal         0x800D3BDC
    // 0x800C9EE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    alEvtqNew(rdram, ctx);
        goto after_2;
    // 0x800C9EE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x800C9EE4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800C9EE8: lw          $a0, -0x33E0($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X33E0);
    // 0x800C9EEC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800C9EF0: addiu       $t7, $t7, -0x6734
    ctx->r15 = ADD32(ctx->r15, -0X6734);
    // 0x800C9EF4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800C9EF8: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x800C9EFC: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x800C9F00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C9F04: jal         0x800D3C50
    // 0x800C9F08: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    alSynAddPlayer(rdram, ctx);
        goto after_3;
    // 0x800C9F08: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    after_3:
    // 0x800C9F0C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800C9F10: sh          $t8, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r24;
    // 0x800C9F14: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x800C9F18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C9F1C: jal         0x800D3A2C
    // 0x800C9F20: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x800C9F20: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x800C9F24: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C9F28: jal         0x800D3B50
    // 0x800C9F2C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    alEvtqNextEvent(rdram, ctx);
        goto after_5;
    // 0x800C9F2C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x800C9F30: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x800C9F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9F38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9F3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C9F40: jr          $ra
    // 0x800C9F44: nop

    return;
    // 0x800C9F44: nop

;}
RECOMP_FUNC void func_8000B194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B19C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000B1A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000B1A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B1A8: nop

    // 0x8000B1AC: bltz        $t6, L_8000B240
    if (SIGNED(ctx->r14) < 0) {
        // 0x8000B1B0: nop
    
            goto L_8000B240;
    }
    // 0x8000B1B0: nop

    // 0x8000B1B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000B1B8: lw          $t7, 0x129C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X129C);
    // 0x8000B1BC: nop

    // 0x8000B1C0: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8000B1C4: bne         $t8, $zero, L_8000B1D4
    if (ctx->r24 != 0) {
        // 0x8000B1C8: nop
    
            goto L_8000B1D4;
    }
    // 0x8000B1C8: nop

    // 0x8000B1CC: b           L_8000B250
    // 0x8000B1D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000B250;
    // 0x8000B1D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000B1D4:
    // 0x8000B1D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8000B1D8: lbu         $t9, 0x127C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X127C);
    // 0x8000B1DC: nop

    // 0x8000B1E0: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8000B1E4: bne         $t0, $zero, L_8000B1F4
    if (ctx->r8 != 0) {
        // 0x8000B1E8: nop
    
            goto L_8000B1F4;
    }
    // 0x8000B1E8: nop

    // 0x8000B1EC: b           L_8000B250
    // 0x8000B1F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000B250;
    // 0x8000B1F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000B1F4:
    // 0x8000B1F4: jal         0x800AE580
    // 0x8000B1F8: nop

    ContPak_GetAvailableSlots(rdram, ctx);
        goto after_0;
    // 0x8000B1F8: nop

    after_0:
    // 0x8000B1FC: bne         $v0, $zero, L_8000B20C
    if (ctx->r2 != 0) {
        // 0x8000B200: nop
    
            goto L_8000B20C;
    }
    // 0x8000B200: nop

    // 0x8000B204: b           L_8000B250
    // 0x8000B208: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000B250;
    // 0x8000B208: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000B20C:
    // 0x8000B20C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8000B210: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8000B214: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000B218: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x8000B21C: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x8000B220: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8000B224: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8000B228: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8000B22C: and         $t6, $t5, $t3
    ctx->r14 = ctx->r13 & ctx->r11;
    // 0x8000B230: beq         $t6, $zero, L_8000B240
    if (ctx->r14 == 0) {
        // 0x8000B234: nop
    
            goto L_8000B240;
    }
    // 0x8000B234: nop

    // 0x8000B238: b           L_8000B250
    // 0x8000B23C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000B250;
    // 0x8000B23C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000B240:
    // 0x8000B240: b           L_8000B250
    // 0x8000B244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B250;
    // 0x8000B244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000B248: b           L_8000B250
    // 0x8000B24C: nop

        goto L_8000B250;
    // 0x8000B24C: nop

L_8000B250:
    // 0x8000B250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B258: jr          $ra
    // 0x8000B25C: nop

    return;
    // 0x8000B25C: nop

;}
RECOMP_FUNC void func_80076ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076AE4: jal         0x80061488
    // 0x80076AE8: addiu       $a0, $zero, 0x477
    ctx->r4 = ADD32(0, 0X477);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076AE8: addiu       $a0, $zero, 0x477
    ctx->r4 = ADD32(0, 0X477);
    after_0:
    // 0x80076AEC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076AF0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076AF4: b           L_80076B04
    // 0x80076AF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076B04;
    // 0x80076AF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076AFC: b           L_80076B04
    // 0x80076B00: nop

        goto L_80076B04;
    // 0x80076B00: nop

L_80076B04:
    // 0x80076B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076B0C: jr          $ra
    // 0x80076B10: nop

    return;
    // 0x80076B10: nop

;}
RECOMP_FUNC void Scheduler_RemoveClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009731C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80097320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097324: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80097328: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8009732C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80097330: nop

    // 0x80097334: lw          $t7, 0x280($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X280);
    // 0x80097338: nop

    // 0x8009733C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80097340: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80097344: jal         0x800C41A0
    // 0x80097348: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80097348: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8009734C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80097350: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80097354: nop

    // 0x80097358: beq         $t8, $zero, L_800973E4
    if (ctx->r24 == 0) {
        // 0x8009735C: nop
    
            goto L_800973E4;
    }
    // 0x8009735C: nop

L_80097360:
    // 0x80097360: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80097364: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80097368: nop

    // 0x8009736C: bne         $t9, $t0, L_800973B4
    if (ctx->r25 != ctx->r8) {
        // 0x80097370: nop
    
            goto L_800973B4;
    }
    // 0x80097370: nop

    // 0x80097374: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80097378: nop

    // 0x8009737C: beq         $t1, $zero, L_80097398
    if (ctx->r9 == 0) {
        // 0x80097380: nop
    
            goto L_80097398;
    }
    // 0x80097380: nop

    // 0x80097384: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80097388: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8009738C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80097390: b           L_800973AC
    // 0x80097394: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_800973AC;
    // 0x80097394: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80097398:
    // 0x80097398: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8009739C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800973A0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800973A4: nop

    // 0x800973A8: sw          $t6, 0x280($t7)
    MEM_W(0X280, ctx->r15) = ctx->r14;
L_800973AC:
    // 0x800973AC: b           L_800973E4
    // 0x800973B0: nop

        goto L_800973E4;
    // 0x800973B0: nop

L_800973B4:
    // 0x800973B4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800973B8: nop

    // 0x800973BC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800973C0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800973C4: nop

    // 0x800973C8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800973CC: nop

    // 0x800973D0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800973D4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800973D8: nop

    // 0x800973DC: bne         $t1, $zero, L_80097360
    if (ctx->r9 != 0) {
        // 0x800973E0: nop
    
            goto L_80097360;
    }
    // 0x800973E0: nop

L_800973E4:
    // 0x800973E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800973E8: jal         0x800C41A0
    // 0x800973EC: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800973EC: nop

    after_1:
    // 0x800973F0: b           L_800973F8
    // 0x800973F4: nop

        goto L_800973F8;
    // 0x800973F4: nop

L_800973F8:
    // 0x800973F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800973FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097400: jr          $ra
    // 0x80097404: nop

    return;
    // 0x80097404: nop

;}
RECOMP_FUNC void AudioGeneral_PlayBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021ED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021EDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80021EE0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021EE4: sw          $t6, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r14;
    // 0x80021EE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021EEC: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    // 0x80021EF0: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    // 0x80021EF4: jal         0x800BB52C
    // 0x80021EF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    AudioDriver_ConfigSeqPlayerVolume(rdram, ctx);
        goto after_0;
    // 0x80021EF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80021EFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80021F00: jal         0x800BB3D4
    // 0x80021F04: nop

    AudioDriver_UpdateSeqID(rdram, ctx);
        goto after_1;
    // 0x80021F04: nop

    after_1:
    // 0x80021F08: b           L_80021F10
    // 0x80021F0C: nop

        goto L_80021F10;
    // 0x80021F0C: nop

L_80021F10:
    // 0x80021F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021F18: jr          $ra
    // 0x80021F1C: nop

    return;
    // 0x80021F1C: nop

;}
RECOMP_FUNC void func_80067AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AF8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067AFC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067B00: nop

    // 0x80067B04: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80067B08: nop

    // 0x80067B0C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067B10: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067B14: jr          $ra
    // 0x80067B18: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067B18: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067B1C: jr          $ra
    // 0x80067B20: nop

    return;
    // 0x80067B20: nop

    // 0x80067B24: jr          $ra
    // 0x80067B28: nop

    return;
    // 0x80067B28: nop

;}
RECOMP_FUNC void func_800BE068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE068: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BE06C: lw          $t6, 0x2528($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2528);
    // 0x800BE070: nop

    // 0x800BE074: bne         $t6, $zero, L_800BE07C
    if (ctx->r14 != 0) {
        // 0x800BE078: nop
    
            goto L_800BE07C;
    }
    // 0x800BE078: nop

L_800BE07C:
    // 0x800BE07C: jr          $ra
    // 0x800BE080: nop

    return;
    // 0x800BE080: nop

    // 0x800BE084: jr          $ra
    // 0x800BE088: nop

    return;
    // 0x800BE088: nop

;}
RECOMP_FUNC void func_80070E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070E28: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80070E2C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80070E30: nop

    // 0x80070E34: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80070E38: nop

    // 0x80070E3C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80070E40: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80070E44: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070E48: beq         $v0, $zero, L_80070E64
    if (ctx->r2 == 0) {
        // 0x80070E4C: nop
    
            goto L_80070E64;
    }
    // 0x80070E4C: nop

    // 0x80070E50: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80070E54: nop

    // 0x80070E58: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80070E5C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80070E60: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80070E64:
    // 0x80070E64: jr          $ra
    // 0x80070E68: nop

    return;
    // 0x80070E68: nop

    // 0x80070E6C: jr          $ra
    // 0x80070E70: nop

    return;
    // 0x80070E70: nop

    // 0x80070E74: jr          $ra
    // 0x80070E78: nop

    return;
    // 0x80070E78: nop

;}
RECOMP_FUNC void func_800AFB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFB28: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AFB2C: sh          $zero, -0x778($at)
    MEM_H(-0X778, ctx->r1) = 0;
    // 0x800AFB30: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AFB34: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800AFB38: lh          $t7, -0x490($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X490);
    // 0x800AFB3C: lhu         $t6, 0x24FC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X24FC);
    // 0x800AFB40: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800AFB44: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFB48: lw          $t0, -0x784($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X784);
    // 0x800AFB4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800AFB50: mflo        $t8
    ctx->r24 = lo;
    // 0x800AFB54: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800AFB58: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800AFB5C: sw          $t1, -0x77C($at)
    MEM_W(-0X77C, ctx->r1) = ctx->r9;
    // 0x800AFB60: jr          $ra
    // 0x800AFB64: nop

    return;
    // 0x800AFB64: nop

    // 0x800AFB68: jr          $ra
    // 0x800AFB6C: nop

    return;
    // 0x800AFB6C: nop

;}
RECOMP_FUNC void func_8006BDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BDC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BDC8: jal         0x8005F064
    // 0x8006BDCC: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BDCC: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_0:
    // 0x8006BDD0: b           L_8006BDE0
    // 0x8006BDD4: nop

        goto L_8006BDE0;
    // 0x8006BDD4: nop

    // 0x8006BDD8: b           L_8006BDE0
    // 0x8006BDDC: nop

        goto L_8006BDE0;
    // 0x8006BDDC: nop

L_8006BDE0:
    // 0x8006BDE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BDE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BDE8: jr          $ra
    // 0x8006BDEC: nop

    return;
    // 0x8006BDEC: nop

;}
RECOMP_FUNC void func_8008B18C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B18C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008B198: jal         0x800C1754
    // 0x8008B19C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x8008B19C: nop

    after_0:
    // 0x8008B1A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008B1A4: jal         0x8009A14C
    // 0x8008B1A8: nop

    func_8009A14C(rdram, ctx);
        goto after_1;
    // 0x8008B1A8: nop

    after_1:
    // 0x8008B1AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008B1B0: jal         0x800997D8
    // 0x8008B1B4: nop

    func_800997D8(rdram, ctx);
        goto after_2;
    // 0x8008B1B4: nop

    after_2:
    // 0x8008B1B8: jal         0x800C1A28
    // 0x8008B1BC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x8008B1BC: nop

    after_3:
    // 0x8008B1C0: b           L_8008B1C8
    // 0x8008B1C4: nop

        goto L_8008B1C8;
    // 0x8008B1C4: nop

L_8008B1C8:
    // 0x8008B1C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B1CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B1D0: jr          $ra
    // 0x8008B1D4: nop

    return;
    // 0x8008B1D4: nop

;}
RECOMP_FUNC void Thread_GetPtr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0E04: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C0E08: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800C0E0C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C0E10: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C0E14: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800C0E18: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800C0E1C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C0E20: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C0E24: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800C0E28: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0E2C: lbu         $t7, -0x63C8($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X63C8);
    // 0x800C0E30: nop

    // 0x800C0E34: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x800C0E38: bne         $t8, $zero, L_800C0E48
    if (ctx->r24 != 0) {
        // 0x800C0E3C: nop
    
            goto L_800C0E48;
    }
    // 0x800C0E3C: nop

    // 0x800C0E40: jr          $ra
    // 0x800C0E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C0E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0E48:
    // 0x800C0E48: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x800C0E4C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800C0E50: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C0E54: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800C0E58: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800C0E5C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800C0E60: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C0E64: addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // 0x800C0E68: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C0E6C: jr          $ra
    // 0x800C0E70: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    return;
    // 0x800C0E70: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800C0E74: jr          $ra
    // 0x800C0E78: nop

    return;
    // 0x800C0E78: nop

    // 0x800C0E7C: jr          $ra
    // 0x800C0E80: nop

    return;
    // 0x800C0E80: nop

;}
RECOMP_FUNC void alSynNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7ED0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800C7ED4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C7ED8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C7EDC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C7EE0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C7EE4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C7EE8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C7EEC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C7EF0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C7EF4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C7EF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C7EFC: lw          $s7, 0x14($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X14);
    // 0x800C7F00: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800C7F04: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800C7F08: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800C7F0C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800C7F10: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x800C7F14: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x800C7F18: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x800C7F1C: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800C7F20: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x800C7F24: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x800C7F28: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800C7F2C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800C7F30: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x800C7F34: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x800C7F38: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C7F3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7F44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C7F48: jal         0x800C7950
    // 0x800C7F4C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800C7F4C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x800C7F50: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800C7F54: jal         0x800CF840
    // 0x800C7F58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    alSaveNew(rdram, ctx);
        goto after_1;
    // 0x800C7F58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800C7F5C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800C7F60: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x800C7F64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7F68: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x800C7F6C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C7F70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7F74: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800C7F78: jal         0x800C7950
    // 0x800C7F7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800C7F7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800C7F80: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C7F84: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x800C7F88: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x800C7F8C: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800C7F90: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C7F94: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C7F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7FA0: jal         0x800C7950
    // 0x800C7FA4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x800C7FA4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x800C7FA8: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x800C7FAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C7FB0: jal         0x800CF8D8
    // 0x800C7FB4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    alAuxBusNew(rdram, ctx);
        goto after_4;
    // 0x800C7FB4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_4:
    // 0x800C7FB8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800C7FBC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C7FC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7FC8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800C7FCC: jal         0x800C7950
    // 0x800C7FD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x800C7FD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800C7FD4: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x800C7FD8: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800C7FDC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800C7FE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C7FE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7FE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C7FEC: jal         0x800C7950
    // 0x800C7FF0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x800C7FF0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_6:
    // 0x800C7FF4: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x800C7FF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C7FFC: jal         0x800CF884
    // 0x800C8000: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    alMainBusNew(rdram, ctx);
        goto after_7;
    // 0x800C8000: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_7:
    // 0x800C8004: lbu         $t7, 0x1C($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1C);
    // 0x800C8008: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800C800C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800C8010: beq         $t7, $zero, L_800C802C
    if (ctx->r15 == 0) {
        // 0x800C8014: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_800C802C;
    }
    // 0x800C8014: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C8018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C801C: jal         0x800CFFE0
    // 0x800C8020: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    alSynAllocFX(rdram, ctx);
        goto after_8;
    // 0x800C8020: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_8:
    // 0x800C8024: b           L_800C803C
    // 0x800C8028: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
        goto L_800C803C;
    // 0x800C8028: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_800C802C:
    // 0x800C802C: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x800C8030: jal         0x800D0080
    // 0x800C8034: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    alMainBusParam(rdram, ctx);
        goto after_9;
    // 0x800C8034: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    after_9:
    // 0x800C8038: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_800C803C:
    // 0x800C803C: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x800C8040: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x800C8044: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x800C8048: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x800C804C: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x800C8050: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800C8054: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x800C8058: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C805C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C8060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C8064: jal         0x800C7950
    // 0x800C8068: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x800C8068: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_10:
    // 0x800C806C: lw          $t9, 0x4($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X4);
    // 0x800C8070: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C8074: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C8078: blez        $t9, L_800C8138
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800C807C: addiu       $a1, $s6, 0x4
        ctx->r5 = ADD32(ctx->r22, 0X4);
            goto L_800C8138;
    }
    // 0x800C807C: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x800C8080: addiu       $s1, $v0, 0x8C
    ctx->r17 = ADD32(ctx->r2, 0X8C);
    // 0x800C8084: addiu       $s2, $v0, 0x58
    ctx->r18 = ADD32(ctx->r2, 0X58);
    // 0x800C8088: addiu       $s3, $v0, 0x10
    ctx->r19 = ADD32(ctx->r2, 0X10);
    // 0x800C808C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
L_800C8090:
    // 0x800C8090: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800C8094: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x800C8098: jal         0x800C78C0
    // 0x800C809C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alLink(rdram, ctx);
        goto after_11;
    // 0x800C809C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800C80A0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800C80A4: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x800C80A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C80AC: jal         0x800CF9B4
    // 0x800C80B0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alLoadNew(rdram, ctx);
        goto after_12;
    // 0x800C80B0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x800C80B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C80B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C80BC: jal         0x800D01D0
    // 0x800C80C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alLoadParam(rdram, ctx);
        goto after_13;
    // 0x800C80C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x800C80C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C80C8: jal         0x800CF92C
    // 0x800C80CC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alResampleNew(rdram, ctx);
        goto after_14;
    // 0x800C80CC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_14:
    // 0x800C80D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C80D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C80D8: jal         0x800D0D20
    // 0x800C80DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alResampleParam(rdram, ctx);
        goto after_15;
    // 0x800C80DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x800C80E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C80E4: jal         0x800CFA5C
    // 0x800C80E8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alEnvmixerNew(rdram, ctx);
        goto after_16;
    // 0x800C80E8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x800C80EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C80F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C80F4: jal         0x800D1134
    // 0x800C80F8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    alEnvmixerParam(rdram, ctx);
        goto after_17;
    // 0x800C80F8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_17:
    // 0x800C80FC: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x800C8100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C8104: jal         0x800D1C80
    // 0x800C8108: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    alAuxBusParam(rdram, ctx);
        goto after_18;
    // 0x800C8108: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_18:
    // 0x800C810C: addiu       $t0, $s5, 0x8C
    ctx->r8 = ADD32(ctx->r21, 0X8C);
    // 0x800C8110: sw          $t0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r8;
    // 0x800C8114: lw          $t1, 0x4($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X4);
    // 0x800C8118: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C811C: addiu       $s0, $s0, 0xDC
    ctx->r16 = ADD32(ctx->r16, 0XDC);
    // 0x800C8120: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800C8124: addiu       $s1, $s1, 0xDC
    ctx->r17 = ADD32(ctx->r17, 0XDC);
    // 0x800C8128: addiu       $s2, $s2, 0xDC
    ctx->r18 = ADD32(ctx->r18, 0XDC);
    // 0x800C812C: bne         $at, $zero, L_800C8090
    if (ctx->r1 != 0) {
        // 0x800C8130: addiu       $s3, $s3, 0xDC
        ctx->r19 = ADD32(ctx->r19, 0XDC);
            goto L_800C8090;
    }
    // 0x800C8130: addiu       $s3, $s3, 0xDC
    ctx->r19 = ADD32(ctx->r19, 0XDC);
    // 0x800C8134: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800C8138:
    // 0x800C8138: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800C813C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C8140: jal         0x800D1D90
    // 0x800C8144: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    alSaveParam(rdram, ctx);
        goto after_19;
    // 0x800C8144: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    after_19:
    // 0x800C8148: lw          $a3, 0x8($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X8);
    // 0x800C814C: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800C8150: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C8154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C8158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C815C: jal         0x800C7950
    // 0x800C8160: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_20;
    // 0x800C8160: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_20:
    // 0x800C8164: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x800C8168: lw          $t3, 0x8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8);
    // 0x800C816C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C8170: blezl       $t3, L_800C81A0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800C8174: sw          $s7, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r23;
            goto L_800C81A0;
    }
    goto skip_0;
    // 0x800C8174: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    skip_0:
    // 0x800C8178: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
L_800C817C:
    // 0x800C817C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C8180: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800C8184: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x800C8188: lw          $t5, 0x8($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X8);
    // 0x800C818C: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x800C8190: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C8194: bnel        $at, $zero, L_800C817C
    if (ctx->r1 != 0) {
        // 0x800C8198: lw          $t4, 0x2C($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X2C);
            goto L_800C817C;
    }
    goto skip_1;
    // 0x800C8198: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
    skip_1:
    // 0x800C819C: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
L_800C81A0:
    // 0x800C81A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C81A4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C81A8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C81AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C81B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C81B4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C81B8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C81BC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C81C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C81C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C81C8: jr          $ra
    // 0x800C81CC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800C81CC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
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
RECOMP_FUNC void func_8007325C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007325C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073260: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073264: nop

    // 0x80073268: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8007326C: nop

    // 0x80073270: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073274: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073278: jr          $ra
    // 0x8007327C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007327C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073280: jr          $ra
    // 0x80073284: nop

    return;
    // 0x80073284: nop

    // 0x80073288: jr          $ra
    // 0x8007328C: nop

    return;
    // 0x8007328C: nop

;}
RECOMP_FUNC void func_800732F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800732F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800732FC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073300: nop

    // 0x80073304: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80073308: nop

    // 0x8007330C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073310: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073314: jr          $ra
    // 0x80073318: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073318: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007331C: jr          $ra
    // 0x80073320: nop

    return;
    // 0x80073320: nop

    // 0x80073324: jr          $ra
    // 0x80073328: nop

    return;
    // 0x80073328: nop

;}
RECOMP_FUNC void func_80073470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073478: jal         0x8005F064
    // 0x8007347C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8007347C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_0:
    // 0x80073480: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80073484: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073488: bne         $v0, $zero, L_800734A0
    if (ctx->r2 != 0) {
        // 0x8007348C: nop
    
            goto L_800734A0;
    }
    // 0x8007348C: nop

    // 0x80073490: jal         0x80061488
    // 0x80073494: addiu       $a0, $zero, 0x63F
    ctx->r4 = ADD32(0, 0X63F);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80073494: addiu       $a0, $zero, 0x63F
    ctx->r4 = ADD32(0, 0X63F);
    after_1:
    // 0x80073498: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007349C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800734A0:
    // 0x800734A0: b           L_800734B0
    // 0x800734A4: nop

        goto L_800734B0;
    // 0x800734A4: nop

    // 0x800734A8: b           L_800734B0
    // 0x800734AC: nop

        goto L_800734B0;
    // 0x800734AC: nop

L_800734B0:
    // 0x800734B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800734B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800734B8: jr          $ra
    // 0x800734BC: nop

    return;
    // 0x800734BC: nop

;}
RECOMP_FUNC void func_8006B644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B64C: jal         0x80061348
    // 0x8006B650: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006B650: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    after_0:
    // 0x8006B654: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006B658: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006B65C: beq         $v0, $zero, L_8006B680
    if (ctx->r2 == 0) {
        // 0x8006B660: nop
    
            goto L_8006B680;
    }
    // 0x8006B660: nop

    // 0x8006B664: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8006B668: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8006B66C: nop

    // 0x8006B670: lh          $v0, 0x2E($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2E);
    // 0x8006B674: nop

    // 0x8006B678: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006B67C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006B680:
    // 0x8006B680: b           L_8006B690
    // 0x8006B684: nop

        goto L_8006B690;
    // 0x8006B684: nop

    // 0x8006B688: b           L_8006B690
    // 0x8006B68C: nop

        goto L_8006B690;
    // 0x8006B68C: nop

L_8006B690:
    // 0x8006B690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006B698: jr          $ra
    // 0x8006B69C: nop

    return;
    // 0x8006B69C: nop

;}
RECOMP_FUNC void func_800A4ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4ED8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800A4EDC: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800A4EE0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4EE4: nop

    // 0x800A4EE8: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800A4EEC: lw          $t7, 0xC0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC0);
    // 0x800A4EF0: nop

    // 0x800A4EF4: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x800A4EF8: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4EFC: nop

    // 0x800A4F00: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A4F04: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800A4F08: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x800A4F0C: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x800A4F10: lui         $t0, 0x104
    ctx->r8 = S32(0X104 << 16);
    // 0x800A4F14: ori         $t0, $t0, 0x40
    ctx->r8 = ctx->r8 | 0X40;
    // 0x800A4F18: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A4F1C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A4F20: lw          $t2, 0x70E4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70E4);
    // 0x800A4F24: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A4F28: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x800A4F2C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800A4F30: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x800A4F34: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A4F38: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800A4F3C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A4F40: lw          $t7, 0xDC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XDC);
    // 0x800A4F44: nop

    // 0x800A4F48: beq         $t7, $zero, L_800A4F88
    if (ctx->r15 == 0) {
        // 0x800A4F4C: nop
    
            goto L_800A4F88;
    }
    // 0x800A4F4C: nop

    // 0x800A4F50: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4F54: nop

    // 0x800A4F58: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A4F5C: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800A4F60: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x800A4F64: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800A4F68: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x800A4F6C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A4F70: lw          $t2, 0xDC($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XDC);
    // 0x800A4F74: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A4F78: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800A4F7C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A4F80: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800A4F84: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_800A4F88:
    // 0x800A4F88: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4F8C: nop

    // 0x800A4F90: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A4F94: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800A4F98: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x800A4F9C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4FA0: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x800A4FA4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A4FA8: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4FAC: addiu       $t9, $zero, 0x2205
    ctx->r25 = ADD32(0, 0X2205);
    // 0x800A4FB0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A4FB4: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800A4FB8: nop

    // 0x800A4FBC: andi        $t2, $t1, 0x800
    ctx->r10 = ctx->r9 & 0X800;
    // 0x800A4FC0: beq         $t2, $zero, L_800A4FF4
    if (ctx->r10 == 0) {
        // 0x800A4FC4: nop
    
            goto L_800A4FF4;
    }
    // 0x800A4FC4: nop

    // 0x800A4FC8: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4FCC: nop

    // 0x800A4FD0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A4FD4: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x800A4FD8: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x800A4FDC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800A4FE0: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x800A4FE4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A4FE8: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800A4FEC: addiu       $t7, $zero, 0x3000
    ctx->r15 = ADD32(0, 0X3000);
    // 0x800A4FF0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_800A4FF4:
    // 0x800A4FF4: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4FF8: nop

    // 0x800A4FFC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A5000: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800A5004: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800A5008: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800A500C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x800A5010: ori         $t1, $t1, 0x201
    ctx->r9 = ctx->r9 | 0X201;
    // 0x800A5014: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A5018: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800A501C: nop

    // 0x800A5020: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A5024: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x800A5028: nop

    // 0x800A502C: andi        $t5, $t4, 0x2000
    ctx->r13 = ctx->r12 & 0X2000;
    // 0x800A5030: bne         $t5, $zero, L_800A5240
    if (ctx->r13 != 0) {
        // 0x800A5034: nop
    
            goto L_800A5240;
    }
    // 0x800A5034: nop

    // 0x800A5038: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A503C: nop

    // 0x800A5040: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A5044: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A5048: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800A504C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800A5050: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800A5054: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x800A5058: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A505C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800A5060: nop

    // 0x800A5064: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800A5068: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800A506C: nop

    // 0x800A5070: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x800A5074: bne         $t2, $zero, L_800A51D0
    if (ctx->r10 != 0) {
        // 0x800A5078: nop
    
            goto L_800A51D0;
    }
    // 0x800A5078: nop

    // 0x800A507C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x800A5080: nop

    // 0x800A5084: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x800A5088: bne         $t4, $zero, L_800A5100
    if (ctx->r12 != 0) {
        // 0x800A508C: nop
    
            goto L_800A5100;
    }
    // 0x800A508C: nop

    // 0x800A5090: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5094: nop

    // 0x800A5098: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A509C: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800A50A0: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x800A50A4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800A50A8: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x800A50AC: ori         $t7, $t7, 0xFE24
    ctx->r15 = ctx->r15 | 0XFE24;
    // 0x800A50B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A50B4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800A50B8: lui         $t9, 0xFF30
    ctx->r25 = S32(0XFF30 << 16);
    // 0x800A50BC: ori         $t9, $t9, 0xF3FF
    ctx->r25 = ctx->r25 | 0XF3FF;
    // 0x800A50C0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A50C4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800A50C8: nop

    // 0x800A50CC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A50D0: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x800A50D4: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x800A50D8: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800A50DC: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x800A50E0: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x800A50E4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A50E8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800A50EC: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x800A50F0: ori         $t5, $t5, 0x2078
    ctx->r13 = ctx->r13 | 0X2078;
    // 0x800A50F4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A50F8: b           L_800A51C8
    // 0x800A50FC: nop

        goto L_800A51C8;
    // 0x800A50FC: nop

L_800A5100:
    // 0x800A5100: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5104: nop

    // 0x800A5108: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A510C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x800A5110: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800A5114: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800A5118: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800A511C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5120: lh          $t1, 0xCC($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XCC);
    // 0x800A5124: lh          $t4, 0xCE($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XCE);
    // 0x800A5128: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800A512C: lh          $t8, 0xD0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XD0);
    // 0x800A5130: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x800A5134: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A5138: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800A513C: lh          $t2, 0xD2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XD2);
    // 0x800A5140: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800A5144: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800A5148: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x800A514C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800A5150: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x800A5154: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x800A5158: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x800A515C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800A5160: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5164: nop

    // 0x800A5168: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x800A516C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x800A5170: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800A5174: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A5178: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800A517C: ori         $t9, $t9, 0x97FF
    ctx->r25 = ctx->r25 | 0X97FF;
    // 0x800A5180: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800A5184: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800A5188: lui         $t0, 0xFF2C
    ctx->r8 = S32(0XFF2C << 16);
    // 0x800A518C: ori         $t0, $t0, 0xFE7F
    ctx->r8 = ctx->r8 | 0XFE7F;
    // 0x800A5190: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x800A5194: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5198: nop

    // 0x800A519C: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x800A51A0: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x800A51A4: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800A51A8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A51AC: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x800A51B0: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x800A51B4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800A51B8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800A51BC: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x800A51C0: ori         $t6, $t6, 0x4A50
    ctx->r14 = ctx->r14 | 0X4A50;
    // 0x800A51C4: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
L_800A51C8:
    // 0x800A51C8: b           L_800A5238
    // 0x800A51CC: nop

        goto L_800A5238;
    // 0x800A51CC: nop

L_800A51D0:
    // 0x800A51D0: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A51D4: nop

    // 0x800A51D8: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x800A51DC: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A51E0: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x800A51E4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800A51E8: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x800A51EC: ori         $t0, $t0, 0xFE24
    ctx->r8 = ctx->r8 | 0XFE24;
    // 0x800A51F0: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800A51F4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800A51F8: lui         $t1, 0xFF30
    ctx->r9 = S32(0XFF30 << 16);
    // 0x800A51FC: ori         $t1, $t1, 0xF3FF
    ctx->r9 = ctx->r9 | 0XF3FF;
    // 0x800A5200: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800A5204: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5208: nop

    // 0x800A520C: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x800A5210: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800A5214: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800A5218: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800A521C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x800A5220: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x800A5224: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800A5228: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A522C: lui         $t9, 0xF0A
    ctx->r25 = S32(0XF0A << 16);
    // 0x800A5230: ori         $t9, $t9, 0x233
    ctx->r25 = ctx->r25 | 0X233;
    // 0x800A5234: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_800A5238:
    // 0x800A5238: b           L_800A5474
    // 0x800A523C: nop

        goto L_800A5474;
    // 0x800A523C: nop

L_800A5240:
    // 0x800A5240: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5244: nop

    // 0x800A5248: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x800A524C: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x800A5250: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800A5254: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800A5258: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x800A525C: ori         $t1, $t1, 0x1402
    ctx->r9 = ctx->r9 | 0X1402;
    // 0x800A5260: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800A5264: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A5268: lui         $t5, 0x10
    ctx->r13 = S32(0X10 << 16);
    // 0x800A526C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800A5270: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800A5274: nop

    // 0x800A5278: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x800A527C: bne         $t8, $zero, L_800A5380
    if (ctx->r24 != 0) {
        // 0x800A5280: nop
    
            goto L_800A5380;
    }
    // 0x800A5280: nop

    // 0x800A5284: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5288: nop

    // 0x800A528C: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x800A5290: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A5294: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800A5298: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800A529C: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x800A52A0: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800A52A4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800A52A8: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x800A52AC: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800A52B0: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800A52B4: nop

    // 0x800A52B8: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x800A52BC: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800A52C0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800A52C4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800A52C8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A52CC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800A52D0: lh          $t9, 0xCC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XCC);
    // 0x800A52D4: lh          $t2, 0xCE($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XCE);
    // 0x800A52D8: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800A52DC: lh          $t3, 0xD0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XD0);
    // 0x800A52E0: sll         $t0, $t7, 24
    ctx->r8 = S32(ctx->r15 << 24);
    // 0x800A52E4: andi        $t1, $t2, 0xFF
    ctx->r9 = ctx->r10 & 0XFF;
    // 0x800A52E8: sll         $t4, $t1, 16
    ctx->r12 = S32(ctx->r9 << 16);
    // 0x800A52EC: lh          $t7, 0xD2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XD2);
    // 0x800A52F0: or          $t5, $t0, $t4
    ctx->r13 = ctx->r8 | ctx->r12;
    // 0x800A52F4: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x800A52F8: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800A52FC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800A5300: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x800A5304: andi        $t2, $t7, 0xFF
    ctx->r10 = ctx->r15 & 0XFF;
    // 0x800A5308: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x800A530C: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x800A5310: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5314: nop

    // 0x800A5318: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x800A531C: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800A5320: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x800A5324: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800A5328: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x800A532C: ori         $t6, $t6, 0x18C3
    ctx->r14 = ctx->r14 | 0X18C3;
    // 0x800A5330: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x800A5334: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800A5338: lui         $t8, 0xFFCF
    ctx->r24 = S32(0XFFCF << 16);
    // 0x800A533C: ori         $t8, $t8, 0xFE38
    ctx->r24 = ctx->r24 | 0XFE38;
    // 0x800A5340: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x800A5344: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5348: nop

    // 0x800A534C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800A5350: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x800A5354: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A5358: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A535C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x800A5360: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x800A5364: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800A5368: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800A536C: lui         $t4, 0xC811
    ctx->r12 = S32(0XC811 << 16);
    // 0x800A5370: ori         $t4, $t4, 0x2078
    ctx->r12 = ctx->r12 | 0X2078;
    // 0x800A5374: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A5378: b           L_800A5474
    // 0x800A537C: nop

        goto L_800A5474;
    // 0x800A537C: nop

L_800A5380:
    // 0x800A5380: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5384: nop

    // 0x800A5388: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x800A538C: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800A5390: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800A5394: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5398: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x800A539C: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800A53A0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800A53A4: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800A53A8: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800A53AC: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800A53B0: nop

    // 0x800A53B4: addiu       $t0, $t1, 0x8
    ctx->r8 = ADD32(ctx->r9, 0X8);
    // 0x800A53B8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800A53BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800A53C0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A53C4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800A53C8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A53CC: lh          $t6, 0xCC($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XCC);
    // 0x800A53D0: lh          $t7, 0xCE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XCE);
    // 0x800A53D4: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x800A53D8: lh          $t0, 0xD0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XD0);
    // 0x800A53DC: sll         $t8, $t5, 24
    ctx->r24 = S32(ctx->r13 << 24);
    // 0x800A53E0: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800A53E4: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800A53E8: lh          $t5, 0xD2($a1)
    ctx->r13 = MEM_H(ctx->r5, 0XD2);
    // 0x800A53EC: or          $t1, $t8, $t2
    ctx->r9 = ctx->r24 | ctx->r10;
    // 0x800A53F0: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x800A53F4: sll         $t3, $t4, 8
    ctx->r11 = S32(ctx->r12 << 8);
    // 0x800A53F8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800A53FC: or          $t6, $t1, $t3
    ctx->r14 = ctx->r9 | ctx->r11;
    // 0x800A5400: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x800A5404: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800A5408: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800A540C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5410: nop

    // 0x800A5414: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A5418: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800A541C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800A5420: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800A5424: lui         $t4, 0xFC12
    ctx->r12 = S32(0XFC12 << 16);
    // 0x800A5428: ori         $t4, $t4, 0x18C3
    ctx->r12 = ctx->r12 | 0X18C3;
    // 0x800A542C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800A5430: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800A5434: lui         $t3, 0xFFCF
    ctx->r11 = S32(0XFFCF << 16);
    // 0x800A5438: ori         $t3, $t3, 0xFE38
    ctx->r11 = ctx->r11 | 0XFE38;
    // 0x800A543C: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x800A5440: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5444: nop

    // 0x800A5448: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A544C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A5450: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800A5454: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A5458: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x800A545C: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x800A5460: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x800A5464: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A5468: lui         $t2, 0xC810
    ctx->r10 = S32(0XC810 << 16);
    // 0x800A546C: ori         $t2, $t2, 0x4A50
    ctx->r10 = ctx->r10 | 0X4A50;
    // 0x800A5470: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
L_800A5474:
    // 0x800A5474: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5478: nop

    // 0x800A547C: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x800A5480: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800A5484: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A5488: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800A548C: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A5490: ori         $t3, $t3, 0x1301
    ctx->r11 = ctx->r11 | 0X1301;
    // 0x800A5494: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800A5498: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A549C: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800A54A0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A54A4: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A54A8: nop

    // 0x800A54AC: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800A54B0: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x800A54B4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A54B8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800A54BC: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x800A54C0: ori         $t2, $t2, 0x1102
    ctx->r10 = ctx->r10 | 0X1102;
    // 0x800A54C4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A54C8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A54CC: lui         $t4, 0x4
    ctx->r12 = S32(0X4 << 16);
    // 0x800A54D0: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x800A54D4: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800A54D8: nop

    // 0x800A54DC: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x800A54E0: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800A54E4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A54E8: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800A54EC: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x800A54F0: ori         $t6, $t6, 0x1001
    ctx->r14 = ctx->r14 | 0X1001;
    // 0x800A54F4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A54F8: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800A54FC: nop

    // 0x800A5500: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A5504: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5508: nop

    // 0x800A550C: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x800A5510: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x800A5514: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A5518: lw          $t4, 0x10($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10);
    // 0x800A551C: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x800A5520: ori         $t0, $t0, 0xE02
    ctx->r8 = ctx->r8 | 0XE02;
    // 0x800A5524: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800A5528: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x800A552C: nop

    // 0x800A5530: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A5534: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5538: nop

    // 0x800A553C: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x800A5540: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800A5544: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x800A5548: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800A554C: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x800A5550: ori         $t6, $t6, 0xC02
    ctx->r14 = ctx->r14 | 0XC02;
    // 0x800A5554: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A5558: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800A555C: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800A5560: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800A5564: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5568: nop

    // 0x800A556C: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A5570: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800A5574: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x800A5578: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800A557C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800A5580: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800A5584: lw          $t3, 0xD8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XD8);
    // 0x800A5588: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A558C: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800A5590: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5594: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800A5598: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A559C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800A55A0: nop

    // 0x800A55A4: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800A55A8: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800A55AC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800A55B0: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800A55B4: lui         $t8, 0xBD00
    ctx->r24 = S32(0XBD00 << 16);
    // 0x800A55B8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800A55BC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800A55C0: nop

    // 0x800A55C4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800A55C8: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800A55CC: nop

    // 0x800A55D0: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x800A55D4: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800A55D8: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x800A55DC: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800A55E0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800A55E4: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800A55E8: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800A55EC: nop

    // 0x800A55F0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A55F4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800A55F8: nop

    // 0x800A55FC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A5600: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800A5604: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5608: sw          $t9, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = ctx->r25;
    // 0x800A560C: b           L_800A561C
    // 0x800A5610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A561C;
    // 0x800A5610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A5614: b           L_800A561C
    // 0x800A5618: nop

        goto L_800A561C;
    // 0x800A5618: nop

L_800A561C:
    // 0x800A561C: jr          $ra
    // 0x800A5620: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800A5620: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void MathUtil_Cosf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3338: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C333C: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800C3340: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x800C3344: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C3348: nop

    // 0x800C334C: sra         $t8, $t7, 22
    ctx->r24 = S32(SIGNED(ctx->r15) >> 22);
    // 0x800C3350: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800C3354: slti        $at, $t9, 0x136
    ctx->r1 = SIGNED(ctx->r25) < 0X136 ? 1 : 0;
    // 0x800C3358: beq         $at, $zero, L_800C3634
    if (ctx->r1 == 0) {
        // 0x800C335C: nop
    
            goto L_800C3634;
    }
    // 0x800C335C: nop

    // 0x800C3360: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3364: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3368: nop

    // 0x800C336C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800C3370: nop

    // 0x800C3374: bc1f        L_800C3384
    if (!c1cs) {
        // 0x800C3378: nop
    
            goto L_800C3384;
    }
    // 0x800C3378: nop

    // 0x800C337C: b           L_800C3390
    // 0x800C3380: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
        goto L_800C3390;
    // 0x800C3380: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
L_800C3384:
    // 0x800C3384: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3388: nop

    // 0x800C338C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_800C3390:
    // 0x800C3390: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x800C3394: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3398: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800C339C: swc1        $f11, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
    // 0x800C33A0: lwc1        $f5, 0x30($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C33A4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C33A8: lwc1        $f7, -0x5580($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C33AC: lwc1        $f6, -0x557C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C33B0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C33B4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C33B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C33BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C33C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C33C4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800C33C8: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x800C33CC: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x800C33D0: nop

    // 0x800C33D4: bc1f        L_800C3474
    if (!c1cs) {
        // 0x800C33D8: nop
    
            goto L_800C3474;
    }
    // 0x800C33D8: nop

    // 0x800C33DC: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C33E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C33E4: nop

    // 0x800C33E8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800C33EC: nop

    // 0x800C33F0: bc1f        L_800C3400
    if (!c1cs) {
        // 0x800C33F4: nop
    
            goto L_800C3400;
    }
    // 0x800C33F4: nop

    // 0x800C33F8: b           L_800C340C
    // 0x800C33FC: mov.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = ctx->f8.fl;
        goto L_800C340C;
    // 0x800C33FC: mov.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = ctx->f8.fl;
L_800C3400:
    // 0x800C3400: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3404: nop

    // 0x800C3408: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
L_800C340C:
    // 0x800C340C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800C3410: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3414: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800C3418: swc1        $f5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x800C341C: lwc1        $f7, 0x30($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C3420: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3424: lwc1        $f11, -0x5580($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C3428: lwc1        $f10, -0x557C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C342C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C3430: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800C3434: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C3438: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C343C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3440: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C3444: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x800C3448: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800C344C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C3450: nop

    // 0x800C3454: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800C3458: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C345C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C3460: nop

    // 0x800C3464: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C3468: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C346C: b           L_800C350C
    // 0x800C3470: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
        goto L_800C350C;
    // 0x800C3470: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
L_800C3474:
    // 0x800C3474: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C3478: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C347C: nop

    // 0x800C3480: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800C3484: nop

    // 0x800C3488: bc1f        L_800C3498
    if (!c1cs) {
        // 0x800C348C: nop
    
            goto L_800C3498;
    }
    // 0x800C348C: nop

    // 0x800C3490: b           L_800C34A4
    // 0x800C3494: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
        goto L_800C34A4;
    // 0x800C3494: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
L_800C3498:
    // 0x800C3498: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C349C: nop

    // 0x800C34A0: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_800C34A4:
    // 0x800C34A4: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800C34A8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C34AC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800C34B0: swc1        $f9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800C34B4: lwc1        $f5, 0x30($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C34B8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C34BC: lwc1        $f11, -0x5580($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X5580);
    // 0x800C34C0: lwc1        $f10, -0x557C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X557C);
    // 0x800C34C4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C34C8: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800C34CC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C34D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C34D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C34D8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800C34DC: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x800C34E0: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x800C34E4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800C34E8: nop

    // 0x800C34EC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800C34F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C34F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C34F8: nop

    // 0x800C34FC: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800C3500: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800C3504: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C3508: nop

L_800C350C:
    // 0x800C350C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800C3510: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800C3514: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800C3518: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800C351C: cvt.d.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.d = CVT_D_W(ctx->f4.u32l);
    // 0x800C3520: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3524: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3528: lwc1        $f5, -0x5578($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X5578);
    // 0x800C352C: lwc1        $f4, -0x5574($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5574);
    // 0x800C3530: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800C3534: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3538: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x800C353C: lwc1        $f7, 0x30($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C3540: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3544: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800C3548: swc1        $f9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800C354C: sub.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d - ctx->f10.d;
    // 0x800C3550: lwc1        $f6, -0x556C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X556C);
    // 0x800C3554: lwc1        $f7, -0x5570($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X5570);
    // 0x800C3558: nop

    // 0x800C355C: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x800C3560: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x800C3564: mul.d       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f8.d);
    // 0x800C3568: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800C356C: swc1        $f9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800C3570: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800C3574: swc1        $f7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x800C3578: lwc1        $f5, 0x30($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800C357C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C3580: lwc1        $f11, 0x28($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800C3584: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C3588: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C358C: addiu       $t3, $t3, -0x5568
    ctx->r11 = ADD32(ctx->r11, -0X5568);
    // 0x800C3590: mul.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800C3594: lwc1        $f7, 0x18($t3)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r11, 0X18);
    // 0x800C3598: lwc1        $f6, 0x1C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800C359C: swc1        $f5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x800C35A0: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800C35A4: mul.d       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800C35A8: lwc1        $f4, 0x14($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X14);
    // 0x800C35AC: lwc1        $f5, 0x10($t3)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r11, 0X10);
    // 0x800C35B0: nop

    // 0x800C35B4: add.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f6.d + ctx->f4.d;
    // 0x800C35B8: mul.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800C35BC: lwc1        $f6, 0xC($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800C35C0: lwc1        $f7, 0x8($t3)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r11, 0X8);
    // 0x800C35C4: nop

    // 0x800C35C8: add.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d + ctx->f6.d;
    // 0x800C35CC: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800C35D0: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800C35D4: lwc1        $f5, 0x0($t3)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r11, 0X0);
    // 0x800C35D8: nop

    // 0x800C35DC: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x800C35E0: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800C35E4: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800C35E8: lwc1        $f5, 0x0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800C35EC: nop

    // 0x800C35F0: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800C35F4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800C35F8: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x800C35FC: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800C3600: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800C3604: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800C3608: nop

    // 0x800C360C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800C3610: beq         $t5, $zero, L_800C3624
    if (ctx->r13 == 0) {
        // 0x800C3614: nop
    
            goto L_800C3624;
    }
    // 0x800C3614: nop

    // 0x800C3618: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C361C: b           L_800C362C
    // 0x800C3620: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_800C362C;
    // 0x800C3620: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_800C3624:
    // 0x800C3624: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3628: nop

L_800C362C:
    // 0x800C362C: b           L_800C3648
    // 0x800C3630: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_800C3648;
    // 0x800C3630: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_800C3634:
    // 0x800C3634: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C3638: b           L_800C3648
    // 0x800C363C: nop

        goto L_800C3648;
    // 0x800C363C: nop

    // 0x800C3640: b           L_800C3648
    // 0x800C3644: nop

        goto L_800C3648;
    // 0x800C3644: nop

L_800C3648:
    // 0x800C3648: jr          $ra
    // 0x800C364C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C364C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80066B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066B1C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80066B20: nop

    // 0x80066B24: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80066B28: nop

    // 0x80066B2C: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80066B30: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80066B34: jr          $ra
    // 0x80066B38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80066B38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066B3C: jr          $ra
    // 0x80066B40: nop

    return;
    // 0x80066B40: nop

    // 0x80066B44: jr          $ra
    // 0x80066B48: nop

    return;
    // 0x80066B48: nop

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
RECOMP_FUNC void func_80001F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001F54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001F5C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80001F60: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80001F64: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80001F68: nop

    // 0x80001F6C: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80001F70: bne         $t8, $zero, L_80001FC8
    if (ctx->r24 != 0) {
        // 0x80001F74: nop
    
            goto L_80001FC8;
    }
    // 0x80001F74: nop

    // 0x80001F78: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x80001F7C: nop

    // 0x80001F80: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80001F84: beq         $t0, $zero, L_80001FC8
    if (ctx->r8 == 0) {
        // 0x80001F88: nop
    
            goto L_80001FC8;
    }
    // 0x80001F88: nop

    // 0x80001F8C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80001F90: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80001F94: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x80001F98: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80001F9C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80001FA0: sh          $t3, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r11;
    // 0x80001FA4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80001FA8: lw          $t4, -0x33BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X33BC);
    // 0x80001FAC: nop

    // 0x80001FB0: bltz        $t4, L_80001FC8
    if (SIGNED(ctx->r12) < 0) {
        // 0x80001FB4: nop
    
            goto L_80001FC8;
    }
    // 0x80001FB4: nop

    // 0x80001FB8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80001FBC: lw          $a0, -0x33BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33BC);
    // 0x80001FC0: jal         0x80021ED0
    // 0x80001FC4: nop

    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_0;
    // 0x80001FC4: nop

    after_0:
L_80001FC8:
    // 0x80001FC8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80001FCC: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80001FD0: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x80001FD4: nop

    // 0x80001FD8: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x80001FDC: bne         $t8, $zero, L_80001FEC
    if (ctx->r24 != 0) {
        // 0x80001FE0: nop
    
            goto L_80001FEC;
    }
    // 0x80001FE0: nop

    // 0x80001FE4: b           L_80002098
    // 0x80001FE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80002098;
    // 0x80001FE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80001FEC:
    // 0x80001FEC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80001FF0: lw          $t6, -0x73CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73CC);
    // 0x80001FF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80001FF8: bne         $t6, $at, L_80002020
    if (ctx->r14 != ctx->r1) {
        // 0x80001FFC: nop
    
            goto L_80002020;
    }
    // 0x80001FFC: nop

    // 0x80002000: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80002004: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80002008: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8000200C: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x80002010: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x80002014: sh          $t2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r10;
    // 0x80002018: b           L_80002098
    // 0x8000201C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80002098;
    // 0x8000201C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80002020:
    // 0x80002020: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80002024: lw          $a0, -0x73CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73CC);
    // 0x80002028: jal         0x80016074
    // 0x8000202C: nop

    func_80016074(rdram, ctx);
        goto after_1;
    // 0x8000202C: nop

    after_1:
    // 0x80002030: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80002034: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80002038: nop

    // 0x8000203C: bne         $t3, $zero, L_8000204C
    if (ctx->r11 != 0) {
        // 0x80002040: nop
    
            goto L_8000204C;
    }
    // 0x80002040: nop

    // 0x80002044: b           L_80002098
    // 0x80002048: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80002098;
    // 0x80002048: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000204C:
    // 0x8000204C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80002050: nop

    // 0x80002054: lw          $t4, 0x1A8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X1A8);
    // 0x80002058: nop

    // 0x8000205C: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x80002060: beq         $t5, $zero, L_80002070
    if (ctx->r13 == 0) {
        // 0x80002064: nop
    
            goto L_80002070;
    }
    // 0x80002064: nop

    // 0x80002068: b           L_80002098
    // 0x8000206C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80002098;
    // 0x8000206C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80002070:
    // 0x80002070: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80002074: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80002078: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000207C: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x80002080: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x80002084: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80002088: b           L_80002098
    // 0x8000208C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80002098;
    // 0x8000208C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002090: b           L_80002098
    // 0x80002094: nop

        goto L_80002098;
    // 0x80002094: nop

L_80002098:
    // 0x80002098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000209C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800020A0: jr          $ra
    // 0x800020A4: nop

    return;
    // 0x800020A4: nop

;}
RECOMP_FUNC void func_8005EF24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EF24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005EF28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005EF2C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005EF30: addiu       $t6, $t6, 0x28E4
    ctx->r14 = ADD32(ctx->r14, 0X28E4);
    // 0x8005EF34: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8005EF38: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8005EF3C: nop

    // 0x8005EF40: beq         $t7, $zero, L_8005EFFC
    if (ctx->r15 == 0) {
        // 0x8005EF44: nop
    
            goto L_8005EFFC;
    }
    // 0x8005EF44: nop

L_8005EF48:
    // 0x8005EF48: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005EF4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8005EF50: addiu       $t0, $t0, 0x28E4
    ctx->r8 = ADD32(ctx->r8, 0X28E4);
    // 0x8005EF54: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8005EF58: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8005EF5C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8005EF60: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8005EF64: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8005EF68: nop

    // 0x8005EF6C: bne         $t2, $t3, L_8005EFD8
    if (ctx->r10 != ctx->r11) {
        // 0x8005EF70: nop
    
            goto L_8005EFD8;
    }
    // 0x8005EF70: nop

    // 0x8005EF74: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8005EF78: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x8005EF7C: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x8005EF80: nop

    // 0x8005EF84: bne         $t4, $t5, L_8005EFD8
    if (ctx->r12 != ctx->r13) {
        // 0x8005EF88: nop
    
            goto L_8005EFD8;
    }
    // 0x8005EF88: nop

    // 0x8005EF8C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005EF90: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005EF94: addiu       $t8, $t8, 0x28E4
    ctx->r24 = ADD32(ctx->r24, 0X28E4);
    // 0x8005EF98: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8005EF9C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005EFA0: lh          $t0, 0x6($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X6);
    // 0x8005EFA4: lh          $t2, 0x8($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X8);
    // 0x8005EFA8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8005EFAC: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8005EFB0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005EFB4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8005EFB8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8005EFBC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005EFC0: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x8005EFC4: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x8005EFC8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8005EFCC: lh          $a2, 0x4($t9)
    ctx->r6 = MEM_H(ctx->r25, 0X4);
    // 0x8005EFD0: jal         0x800298A4
    // 0x8005EFD4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800298A4(rdram, ctx);
        goto after_0;
    // 0x8005EFD4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
L_8005EFD8:
    // 0x8005EFD8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8005EFDC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8005EFE0: addiu       $t1, $t3, 0x5
    ctx->r9 = ADD32(ctx->r11, 0X5);
    // 0x8005EFE4: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8005EFE8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005EFEC: lh          $t5, 0x28E4($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X28E4);
    // 0x8005EFF0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8005EFF4: bne         $t5, $zero, L_8005EF48
    if (ctx->r13 != 0) {
        // 0x8005EFF8: nop
    
            goto L_8005EF48;
    }
    // 0x8005EFF8: nop

L_8005EFFC:
    // 0x8005EFFC: b           L_8005F00C
    // 0x8005F000: nop

        goto L_8005F00C;
    // 0x8005F000: nop

    // 0x8005F004: b           L_8005F00C
    // 0x8005F008: nop

        goto L_8005F00C;
    // 0x8005F008: nop

L_8005F00C:
    // 0x8005F00C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005F014: jr          $ra
    // 0x8005F018: nop

    return;
    // 0x8005F018: nop

;}
RECOMP_FUNC void func_8001635C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001635C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016364: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80016368:
    // 0x80016368: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001636C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80016370: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80016374: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80016378: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x8001637C: nop

    // 0x80016380: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80016384: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80016388: nop

    // 0x8001638C: beq         $t9, $zero, L_80016400
    if (ctx->r25 == 0) {
        // 0x80016390: nop
    
            goto L_80016400;
    }
    // 0x80016390: nop

    // 0x80016394: lw          $t0, 0x1A0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A0);
    // 0x80016398: nop

    // 0x8001639C: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x800163A0: beq         $t1, $zero, L_80016400
    if (ctx->r9 == 0) {
        // 0x800163A4: nop
    
            goto L_80016400;
    }
    // 0x800163A4: nop

    // 0x800163A8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800163AC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800163B0: lw          $t3, 0x1A4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A4);
    // 0x800163B4: nop

    // 0x800163B8: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800163BC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800163C0: lw          $t5, -0x248C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X248C);
    // 0x800163C4: nop

    // 0x800163C8: bne         $t5, $zero, L_800163D8
    if (ctx->r13 != 0) {
        // 0x800163CC: nop
    
            goto L_800163D8;
    }
    // 0x800163CC: nop

    // 0x800163D0: b           L_80016400
    // 0x800163D4: nop

        goto L_80016400;
    // 0x800163D4: nop

L_800163D8:
    // 0x800163D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800163DC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800163E0: lw          $t7, 0x1A4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A4);
    // 0x800163E4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800163E8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800163EC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800163F0: lw          $t9, -0x248C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X248C);
    // 0x800163F4: nop

    // 0x800163F8: jalr        $t9
    // 0x800163FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800163FC: nop

    after_0:
L_80016400:
    // 0x80016400: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80016404: nop

    // 0x80016408: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001640C: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x80016410: bne         $at, $zero, L_80016368
    if (ctx->r1 != 0) {
        // 0x80016414: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_80016368;
    }
    // 0x80016414: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80016418: b           L_80016420
    // 0x8001641C: nop

        goto L_80016420;
    // 0x8001641C: nop

L_80016420:
    // 0x80016420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016428: jr          $ra
    // 0x8001642C: nop

    return;
    // 0x8001642C: nop

;}
RECOMP_FUNC void func_80070998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007099C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800709A0: jal         0x80061348
    // 0x800709A4: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800709A4: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x800709A8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800709AC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800709B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800709B4: beq         $v0, $zero, L_80070A08
    if (ctx->r2 == 0) {
        // 0x800709B8: nop
    
            goto L_80070A08;
    }
    // 0x800709B8: nop

    // 0x800709BC: jal         0x80061348
    // 0x800709C0: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800709C0: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_1:
    // 0x800709C4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800709C8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800709CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800709D0: beq         $v0, $zero, L_80070A08
    if (ctx->r2 == 0) {
        // 0x800709D4: nop
    
            goto L_80070A08;
    }
    // 0x800709D4: nop

    // 0x800709D8: jal         0x80061348
    // 0x800709DC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800709DC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x800709E0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800709E4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800709E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800709EC: beq         $v0, $zero, L_80070A08
    if (ctx->r2 == 0) {
        // 0x800709F0: nop
    
            goto L_80070A08;
    }
    // 0x800709F0: nop

    // 0x800709F4: jal         0x80061348
    // 0x800709F8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800709F8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x800709FC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070A00: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070A04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070A08:
    // 0x80070A08: b           L_80070A18
    // 0x80070A0C: nop

        goto L_80070A18;
    // 0x80070A0C: nop

    // 0x80070A10: b           L_80070A18
    // 0x80070A14: nop

        goto L_80070A18;
    // 0x80070A14: nop

L_80070A18:
    // 0x80070A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070A20: jr          $ra
    // 0x80070A24: nop

    return;
    // 0x80070A24: nop

;}
RECOMP_FUNC void func_80077F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077F48: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077F4C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077F50: nop

    // 0x80077F54: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80077F58: nop

    // 0x80077F5C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077F60: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077F64: jr          $ra
    // 0x80077F68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077F68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077F6C: jr          $ra
    // 0x80077F70: nop

    return;
    // 0x80077F70: nop

    // 0x80077F74: jr          $ra
    // 0x80077F78: nop

    return;
    // 0x80077F78: nop

;}
RECOMP_FUNC void func_80073528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073528: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007352C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073530: nop

    // 0x80073534: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80073538: nop

    // 0x8007353C: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80073540: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073544: jr          $ra
    // 0x80073548: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073548: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007354C: jr          $ra
    // 0x80073550: nop

    return;
    // 0x80073550: nop

    // 0x80073554: jr          $ra
    // 0x80073558: nop

    return;
    // 0x80073558: nop

;}
RECOMP_FUNC void func_800741BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800741BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800741C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800741C4: jal         0x80061348
    // 0x800741C8: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800741C8: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_0:
    // 0x800741CC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800741D0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800741D4: b           L_800741E4
    // 0x800741D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800741E4;
    // 0x800741D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800741DC: b           L_800741E4
    // 0x800741E0: nop

        goto L_800741E4;
    // 0x800741E0: nop

L_800741E4:
    // 0x800741E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800741E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800741EC: jr          $ra
    // 0x800741F0: nop

    return;
    // 0x800741F0: nop

;}
RECOMP_FUNC void func_80077E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077E48: jal         0x8005F064
    // 0x80077E4C: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80077E4C: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_0:
    // 0x80077E50: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077E54: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077E58: beq         $v0, $zero, L_80077E70
    if (ctx->r2 == 0) {
        // 0x80077E5C: nop
    
            goto L_80077E70;
    }
    // 0x80077E5C: nop

    // 0x80077E60: jal         0x8005F064
    // 0x80077E64: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_1;
    // 0x80077E64: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x80077E68: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80077E6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80077E70:
    // 0x80077E70: b           L_80077E80
    // 0x80077E74: nop

        goto L_80077E80;
    // 0x80077E74: nop

    // 0x80077E78: b           L_80077E80
    // 0x80077E7C: nop

        goto L_80077E80;
    // 0x80077E7C: nop

L_80077E80:
    // 0x80077E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077E88: jr          $ra
    // 0x80077E8C: nop

    return;
    // 0x80077E8C: nop

;}
RECOMP_FUNC void func_8009A084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A084: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8009A088: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x8009A08C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8009A090: nop

    // 0x8009A094: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8009A098: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8009A09C: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8009A0A0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8009A0A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009A0A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8009A0AC: nop

    // 0x8009A0B0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8009A0B4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8009A0B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8009A0BC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8009A0C0: nop

    // 0x8009A0C4: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8009A0C8: nop

    // 0x8009A0CC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8009A0D0: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x8009A0D4: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8009A0D8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8009A0DC: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x8009A0E0: ori         $t1, $t1, 0x201
    ctx->r9 = ctx->r9 | 0X201;
    // 0x8009A0E4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8009A0E8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8009A0EC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8009A0F0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8009A0F4: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8009A0F8: nop

    // 0x8009A0FC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8009A100: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8009A104: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x8009A108: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8009A10C: lui         $t7, 0xEE00
    ctx->r15 = S32(0XEE00 << 16);
    // 0x8009A110: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009A114: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8009A118: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x8009A11C: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8009A120: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8009A124: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8009A128: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8009A12C: nop

    // 0x8009A130: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8009A134: b           L_8009A144
    // 0x8009A138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009A144;
    // 0x8009A138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009A13C: b           L_8009A144
    // 0x8009A140: nop

        goto L_8009A144;
    // 0x8009A140: nop

L_8009A144:
    // 0x8009A144: jr          $ra
    // 0x8009A148: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8009A148: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80059D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059D88: addiu       $t6, $zero, 0x33
    ctx->r14 = ADD32(0, 0X33);
    // 0x80059D8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80059D90: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
    // 0x80059D94: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80059D98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80059D9C: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
    // 0x80059DA0: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x80059DA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80059DA8: sh          $t8, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r24;
    // 0x80059DAC: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80059DB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80059DB4: sw          $t9, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r25;
    // 0x80059DB8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80059DBC: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80059DC0: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x80059DC4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80059DC8: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80059DCC: sh          $t2, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r10;
    // 0x80059DD0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80059DD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80059DD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80059DDC: swc1        $f4, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f4.u32l;
    // 0x80059DE0: addiu       $t3, $zero, 0xFE
    ctx->r11 = ADD32(0, 0XFE);
    // 0x80059DE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059DE8: sb          $t3, 0xD94($at)
    MEM_B(0XD94, ctx->r1) = ctx->r11;
    // 0x80059DEC: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x80059DF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80059DF4: sh          $t4, 0xDA4($at)
    MEM_H(0XDA4, ctx->r1) = ctx->r12;
    // 0x80059DF8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80059DFC: sw          $zero, -0x794($at)
    MEM_W(-0X794, ctx->r1) = 0;
    // 0x80059E00: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80059E04: sh          $zero, -0x498($at)
    MEM_H(-0X498, ctx->r1) = 0;
    // 0x80059E08: jal         0x80031914
    // 0x80059E0C: nop

    func_80031914(rdram, ctx);
        goto after_0;
    // 0x80059E0C: nop

    after_0:
    // 0x80059E10: b           L_80059E18
    // 0x80059E14: nop

        goto L_80059E18;
    // 0x80059E14: nop

L_80059E18:
    // 0x80059E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80059E20: jr          $ra
    // 0x80059E24: nop

    return;
    // 0x80059E24: nop

;}
RECOMP_FUNC void func_80054690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054690: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80054694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80054698: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8005469C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x800546A0: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800546A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800546A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800546AC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800546B0: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x800546B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800546B8: bne         $t6, $at, L_80054700
    if (ctx->r14 != ctx->r1) {
        // 0x800546BC: nop
    
            goto L_80054700;
    }
    // 0x800546BC: nop

    // 0x800546C0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800546C4: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x800546C8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800546CC: bne         $t7, $at, L_80054700
    if (ctx->r15 != ctx->r1) {
        // 0x800546D0: nop
    
            goto L_80054700;
    }
    // 0x800546D0: nop

    // 0x800546D4: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800546D8: nop

    // 0x800546DC: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800546E0: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800546E4: nop

    // 0x800546E8: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800546EC: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800546F0: nop

    // 0x800546F4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800546F8: b           L_80055134
    // 0x800546FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055134;
    // 0x800546FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054700:
    // 0x80054700: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054704: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80054708: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8005470C: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80054710: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80054714: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80054718: bne         $t4, $zero, L_80054728
    if (ctx->r12 != 0) {
        // 0x8005471C: and         $t5, $t3, $at
        ctx->r13 = ctx->r11 & ctx->r1;
            goto L_80054728;
    }
    // 0x8005471C: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80054720: beq         $t5, $zero, L_8005475C
    if (ctx->r13 == 0) {
        // 0x80054724: nop
    
            goto L_8005475C;
    }
    // 0x80054724: nop

L_80054728:
    // 0x80054728: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005472C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80054730: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054734: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80054738: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005473C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80054740: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x80054744: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80054748: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x8005474C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80054750: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80054754: b           L_80054EE4
    // 0x80054758: nop

        goto L_80054EE4;
    // 0x80054758: nop

L_8005475C:
    // 0x8005475C: jal         0x80057960
    // 0x80054760: nop

    func_80057960(rdram, ctx);
        goto after_0;
    // 0x80054760: nop

    after_0:
    // 0x80054764: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80054768: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8005476C: nop

    // 0x80054770: beq         $t7, $zero, L_800547D8
    if (ctx->r15 == 0) {
        // 0x80054774: nop
    
            goto L_800547D8;
    }
    // 0x80054774: nop

    // 0x80054778: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8005477C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054780: nop

    // 0x80054784: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054788: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005478C: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054790: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054794: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80054798: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8005479C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800547A0: addiu       $at, $zero, -0x6001
    ctx->r1 = ADD32(0, -0X6001);
    // 0x800547A4: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800547A8: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800547AC: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800547B0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800547B4: lw          $t5, 0x480($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X480);
    // 0x800547B8: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800547BC: nop

    // 0x800547C0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800547C4: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x800547C8: nop

    // 0x800547CC: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800547D0: b           L_80055134
    // 0x800547D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055134;
    // 0x800547D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800547D8:
    // 0x800547D8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800547DC: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800547E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800547E4: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x800547E8: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800547EC: bne         $t0, $zero, L_800547FC
    if (ctx->r8 != 0) {
        // 0x800547F0: andi        $t1, $t9, 0x1000
        ctx->r9 = ctx->r25 & 0X1000;
            goto L_800547FC;
    }
    // 0x800547F0: andi        $t1, $t9, 0x1000
    ctx->r9 = ctx->r25 & 0X1000;
    // 0x800547F4: beq         $t1, $zero, L_80054860
    if (ctx->r9 == 0) {
        // 0x800547F8: nop
    
            goto L_80054860;
    }
    // 0x800547F8: nop

L_800547FC:
    // 0x800547FC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80054800: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80054804: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054808: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8005480C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80054810: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80054814: addiu       $at, $zero, -0x1001
    ctx->r1 = ADD32(0, -0X1001);
    // 0x80054818: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8005481C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80054820: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80054824: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80054828: lw          $t2, 0x488($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X488);
    // 0x8005482C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80054830: nop

    // 0x80054834: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80054838: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8005483C: lw          $t9, 0x488($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X488);
    // 0x80054840: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80054844: nop

    // 0x80054848: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8005484C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x80054850: nop

    // 0x80054854: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80054858: b           L_80055134
    // 0x8005485C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x8005485C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054860:
    // 0x80054860: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054864: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054868: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8005486C: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80054870: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80054874: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80054878: bne         $t2, $zero, L_80054888
    if (ctx->r10 != 0) {
        // 0x8005487C: and         $t3, $t7, $at
        ctx->r11 = ctx->r15 & ctx->r1;
            goto L_80054888;
    }
    // 0x8005487C: and         $t3, $t7, $at
    ctx->r11 = ctx->r15 & ctx->r1;
    // 0x80054880: beq         $t3, $zero, L_80054914
    if (ctx->r11 == 0) {
        // 0x80054884: nop
    
            goto L_80054914;
    }
    // 0x80054884: nop

L_80054888:
    // 0x80054888: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005488C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80054890: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054894: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80054898: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8005489C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800548A0: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x800548A4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800548A8: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800548AC: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x800548B0: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x800548B4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800548B8: lw          $t4, 0x648($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X648);
    // 0x800548BC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800548C0: lh          $t6, 0x3C($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X3C);
    // 0x800548C4: lw          $t2, 0x5A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5A8);
    // 0x800548C8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800548CC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800548D0: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800548D4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800548D8: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x800548DC: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800548E0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800548E4: lw          $t9, 0x5A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5A8);
    // 0x800548E8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800548EC: nop

    // 0x800548F0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800548F4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800548F8: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x800548FC: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x80054900: lh          $t5, 0x3C($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X3C);
    // 0x80054904: nop

    // 0x80054908: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x8005490C: b           L_80055134
    // 0x80054910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054914:
    // 0x80054914: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054918: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005491C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80054920: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80054924: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80054928: bne         $t8, $zero, L_80054938
    if (ctx->r24 != 0) {
        // 0x8005492C: andi        $t9, $t3, 0x2000
        ctx->r25 = ctx->r11 & 0X2000;
            goto L_80054938;
    }
    // 0x8005492C: andi        $t9, $t3, 0x2000
    ctx->r25 = ctx->r11 & 0X2000;
    // 0x80054930: beq         $t9, $zero, L_8005499C
    if (ctx->r25 == 0) {
        // 0x80054934: nop
    
            goto L_8005499C;
    }
    // 0x80054934: nop

L_80054938:
    // 0x80054938: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005493C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80054940: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80054944: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80054948: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8005494C: and         $t4, $t0, $at
    ctx->r12 = ctx->r8 & ctx->r1;
    // 0x80054950: addiu       $at, $zero, -0x2001
    ctx->r1 = ADD32(0, -0X2001);
    // 0x80054954: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80054958: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8005495C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x80054960: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054964: lw          $t6, 0x63C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63C);
    // 0x80054968: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8005496C: addiu       $t2, $t6, 0x24
    ctx->r10 = ADD32(ctx->r14, 0X24);
    // 0x80054970: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054974: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054978: lw          $t8, 0x63C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63C);
    // 0x8005497C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80054980: nop

    // 0x80054984: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054988: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8005498C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80054990: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80054994: b           L_80055134
    // 0x80054998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005499C:
    // 0x8005499C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800549A0: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800549A4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800549A8: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800549AC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800549B0: bne         $t2, $zero, L_800549C0
    if (ctx->r10 != 0) {
        // 0x800549B4: andi        $t3, $t7, 0x4000
        ctx->r11 = ctx->r15 & 0X4000;
            goto L_800549C0;
    }
    // 0x800549B4: andi        $t3, $t7, 0x4000
    ctx->r11 = ctx->r15 & 0X4000;
    // 0x800549B8: beq         $t3, $zero, L_80054A60
    if (ctx->r11 == 0) {
        // 0x800549BC: nop
    
            goto L_80054A60;
    }
    // 0x800549BC: nop

L_800549C0:
    // 0x800549C0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800549C4: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x800549C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800549CC: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x800549D0: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x800549D4: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800549D8: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x800549DC: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800549E0: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x800549E4: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x800549E8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800549EC: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x800549F0: nop

    // 0x800549F4: lbu         $a0, 0x8($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X8);
    // 0x800549F8: jal         0x80060E24
    // 0x800549FC: nop

    func_80060E24(rdram, ctx);
        goto after_1;
    // 0x800549FC: nop

    after_1:
    // 0x80054A00: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80054A04: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054A08: lw          $t7, 0x63C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63C);
    // 0x80054A0C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80054A10: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054A14: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80054A18: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80054A1C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054A20: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054A24: lw          $t8, 0x63C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63C);
    // 0x80054A28: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80054A2C: nop

    // 0x80054A30: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054A34: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80054A38: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80054A3C: nop

    // 0x80054A40: lbu         $a0, 0x8($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X8);
    // 0x80054A44: jal         0x80060E24
    // 0x80054A48: nop

    func_80060E24(rdram, ctx);
        goto after_2;
    // 0x80054A48: nop

    after_2:
    // 0x80054A4C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x80054A50: nop

    // 0x80054A54: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80054A58: b           L_80055134
    // 0x80054A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054A60:
    // 0x80054A60: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054A64: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80054A68: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80054A6C: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x80054A70: lw          $t5, 0x4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4);
    // 0x80054A74: bne         $t6, $zero, L_80054A84
    if (ctx->r14 != 0) {
        // 0x80054A78: andi        $t7, $t5, 0x8000
        ctx->r15 = ctx->r13 & 0X8000;
            goto L_80054A84;
    }
    // 0x80054A78: andi        $t7, $t5, 0x8000
    ctx->r15 = ctx->r13 & 0X8000;
    // 0x80054A7C: beq         $t7, $zero, L_80054C88
    if (ctx->r15 == 0) {
        // 0x80054A80: nop
    
            goto L_80054C88;
    }
    // 0x80054A80: nop

L_80054A84:
    // 0x80054A84: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80054A88: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80054A8C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80054A90: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x80054A94: nop

    // 0x80054A98: lh          $t8, 0x0($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X0);
    // 0x80054A9C: nop

    // 0x80054AA0: beq         $t8, $at, L_80054B34
    if (ctx->r24 == ctx->r1) {
        // 0x80054AA4: nop
    
            goto L_80054B34;
    }
    // 0x80054AA4: nop

    // 0x80054AA8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80054AAC: beq         $t8, $at, L_80054B34
    if (ctx->r24 == ctx->r1) {
        // 0x80054AB0: nop
    
            goto L_80054B34;
    }
    // 0x80054AB0: nop

    // 0x80054AB4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80054AB8: beq         $t8, $at, L_80054B34
    if (ctx->r24 == ctx->r1) {
        // 0x80054ABC: nop
    
            goto L_80054B34;
    }
    // 0x80054ABC: nop

    // 0x80054AC0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80054AC4: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80054AC8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80054ACC: lw          $t0, 0x5C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X5C);
    // 0x80054AD0: lw          $t5, 0x478($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X478);
    // 0x80054AD4: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80054AD8: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80054ADC: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x80054AE0: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x80054AE4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80054AE8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80054AEC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80054AF0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80054AF4: lw          $t2, 0x478($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X478);
    // 0x80054AF8: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80054AFC: nop

    // 0x80054B00: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054B04: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054B08: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x80054B0C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x80054B10: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x80054B14: nop

    // 0x80054B18: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80054B1C: nop

    // 0x80054B20: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80054B24: b           L_80055134
    // 0x80054B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80054B2C: b           L_80054C88
    // 0x80054B30: nop

        goto L_80054C88;
    // 0x80054B30: nop

L_80054B34:
    // 0x80054B34: jal         0x8005A578
    // 0x80054B38: nop

    func_8005A578(rdram, ctx);
        goto after_3;
    // 0x80054B38: nop

    after_3:
    // 0x80054B3C: bne         $v0, $zero, L_80054C1C
    if (ctx->r2 != 0) {
        // 0x80054B40: nop
    
            goto L_80054C1C;
    }
    // 0x80054B40: nop

    // 0x80054B44: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054B48: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054B4C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80054B50: lw          $t5, 0x5C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X5C);
    // 0x80054B54: nop

    // 0x80054B58: lh          $s0, 0x0($t5)
    ctx->r16 = MEM_H(ctx->r13, 0X0);
    // 0x80054B5C: nop

    // 0x80054B60: beq         $s0, $at, L_80054B88
    if (ctx->r16 == ctx->r1) {
        // 0x80054B64: nop
    
            goto L_80054B88;
    }
    // 0x80054B64: nop

    // 0x80054B68: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80054B6C: beq         $s0, $at, L_80054BD8
    if (ctx->r16 == ctx->r1) {
        // 0x80054B70: nop
    
            goto L_80054BD8;
    }
    // 0x80054B70: nop

    // 0x80054B74: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80054B78: beq         $s0, $at, L_80054BB0
    if (ctx->r16 == ctx->r1) {
        // 0x80054B7C: nop
    
            goto L_80054BB0;
    }
    // 0x80054B7C: nop

    // 0x80054B80: b           L_80054C00
    // 0x80054B84: nop

        goto L_80054C00;
    // 0x80054B84: nop

L_80054B88:
    // 0x80054B88: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80054B8C: lw          $t6, 0x478($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X478);
    // 0x80054B90: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80054B94: addiu       $t7, $t6, 0x306
    ctx->r15 = ADD32(ctx->r14, 0X306);
    // 0x80054B98: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80054B9C: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80054BA0: addiu       $t3, $zero, 0x2B
    ctx->r11 = ADD32(0, 0X2B);
    // 0x80054BA4: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054BA8: b           L_80054C00
    // 0x80054BAC: nop

        goto L_80054C00;
    // 0x80054BAC: nop

L_80054BB0:
    // 0x80054BB0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80054BB4: lw          $t9, 0x478($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X478);
    // 0x80054BB8: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80054BBC: addiu       $t0, $t9, 0x318
    ctx->r8 = ADD32(ctx->r25, 0X318);
    // 0x80054BC0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80054BC4: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80054BC8: addiu       $t4, $zero, 0x2C
    ctx->r12 = ADD32(0, 0X2C);
    // 0x80054BCC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80054BD0: b           L_80054C00
    // 0x80054BD4: nop

        goto L_80054C00;
    // 0x80054BD4: nop

L_80054BD8:
    // 0x80054BD8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80054BDC: lw          $t6, 0x478($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X478);
    // 0x80054BE0: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80054BE4: addiu       $t7, $t6, 0x32A
    ctx->r15 = ADD32(ctx->r14, 0X32A);
    // 0x80054BE8: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80054BEC: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80054BF0: addiu       $t3, $zero, 0x2D
    ctx->r11 = ADD32(0, 0X2D);
    // 0x80054BF4: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054BF8: b           L_80054C00
    // 0x80054BFC: nop

        goto L_80054C00;
    // 0x80054BFC: nop

L_80054C00:
    // 0x80054C00: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80054C04: lw          $t9, 0x478($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X478);
    // 0x80054C08: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80054C0C: nop

    // 0x80054C10: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80054C14: b           L_80055134
    // 0x80054C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054C1C:
    // 0x80054C1C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054C20: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80054C24: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80054C28: lw          $t4, 0x5C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X5C);
    // 0x80054C2C: lw          $t7, 0x478($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X478);
    // 0x80054C30: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80054C34: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054C38: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80054C3C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80054C40: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80054C44: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80054C48: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054C4C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80054C50: lw          $t8, 0x478($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X478);
    // 0x80054C54: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80054C58: nop

    // 0x80054C5C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054C60: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80054C64: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x80054C68: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80054C6C: lw          $t1, 0x5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X5C);
    // 0x80054C70: nop

    // 0x80054C74: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    // 0x80054C78: nop

    // 0x80054C7C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80054C80: b           L_80055134
    // 0x80054C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054C88:
    // 0x80054C88: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054C8C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x80054C90: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80054C94: lw          $t3, 0x4($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X4);
    // 0x80054C98: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80054C9C: lw          $t2, 0x0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X0);
    // 0x80054CA0: bne         $t8, $zero, L_80054CB0
    if (ctx->r24 != 0) {
        // 0x80054CA4: and         $t9, $t3, $at
        ctx->r25 = ctx->r11 & ctx->r1;
            goto L_80054CB0;
    }
    // 0x80054CA4: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80054CA8: beq         $t9, $zero, L_80054D60
    if (ctx->r25 == 0) {
        // 0x80054CAC: nop
    
            goto L_80054D60;
    }
    // 0x80054CAC: nop

L_80054CB0:
    // 0x80054CB0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054CB4: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80054CB8: nop

    // 0x80054CBC: lw          $a0, 0x58($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X58);
    // 0x80054CC0: jal         0x80056C60
    // 0x80054CC4: nop

    func_80056C60(rdram, ctx);
        goto after_4;
    // 0x80054CC4: nop

    after_4:
    // 0x80054CC8: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80054CCC: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80054CD0: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80054CD4: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x80054CD8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80054CDC: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x80054CE0: lh          $t4, 0x2C52($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2C52);
    // 0x80054CE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054CE8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80054CEC: lw          $t6, 0x630($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X630);
    // 0x80054CF0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80054CF4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054CF8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80054CFC: addu        $t2, $t5, $t6
    ctx->r10 = ADD32(ctx->r13, ctx->r14);
    // 0x80054D00: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054D04: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80054D08: lw          $t8, 0x630($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X630);
    // 0x80054D0C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80054D10: nop

    // 0x80054D14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054D18: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054D1C: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80054D20: nop

    // 0x80054D24: lw          $a0, 0x58($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X58);
    // 0x80054D28: jal         0x80056C60
    // 0x80054D2C: nop

    func_80056C60(rdram, ctx);
        goto after_5;
    // 0x80054D2C: nop

    after_5:
    // 0x80054D30: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80054D34: sra         $t0, $s1, 16
    ctx->r8 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80054D38: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x80054D3C: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x80054D40: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80054D44: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x80054D48: lh          $t4, 0x2C52($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X2C52);
    // 0x80054D4C: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80054D50: nop

    // 0x80054D54: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80054D58: b           L_80055134
    // 0x80054D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054D60:
    // 0x80054D60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80054D64: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80054D68: nop

    // 0x80054D6C: lh          $t2, 0x0($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X0);
    // 0x80054D70: nop

    // 0x80054D74: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x80054D78: beq         $at, $zero, L_80054DBC
    if (ctx->r1 == 0) {
        // 0x80054D7C: nop
    
            goto L_80054DBC;
    }
    // 0x80054D7C: nop

    // 0x80054D80: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80054D84: lw          $t3, 0x638($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X638);
    // 0x80054D88: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80054D8C: nop

    // 0x80054D90: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054D94: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80054D98: lw          $t9, 0x638($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X638);
    // 0x80054D9C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80054DA0: nop

    // 0x80054DA4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80054DA8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80054DAC: nop

    // 0x80054DB0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80054DB4: b           L_80055134
    // 0x80054DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054DBC:
    // 0x80054DBC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054DC0: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80054DC4: nop

    // 0x80054DC8: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80054DCC: nop

    // 0x80054DD0: slti        $at, $t4, 0x3D
    ctx->r1 = SIGNED(ctx->r12) < 0X3D ? 1 : 0;
    // 0x80054DD4: beq         $at, $zero, L_80054E18
    if (ctx->r1 == 0) {
        // 0x80054DD8: nop
    
            goto L_80054E18;
    }
    // 0x80054DD8: nop

    // 0x80054DDC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054DE0: lw          $t5, 0x638($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X638);
    // 0x80054DE4: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80054DE8: addiu       $t6, $t5, 0x12
    ctx->r14 = ADD32(ctx->r13, 0X12);
    // 0x80054DEC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80054DF0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80054DF4: lw          $t3, 0x638($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X638);
    // 0x80054DF8: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80054DFC: nop

    // 0x80054E00: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054E04: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80054E08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80054E0C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80054E10: b           L_80055134
    // 0x80054E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054E18:
    // 0x80054E18: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80054E1C: lw          $t0, 0x648($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X648);
    // 0x80054E20: nop

    // 0x80054E24: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80054E28: nop

    // 0x80054E2C: slti        $at, $t1, 0x384
    ctx->r1 = SIGNED(ctx->r9) < 0X384 ? 1 : 0;
    // 0x80054E30: bne         $at, $zero, L_80054E74
    if (ctx->r1 != 0) {
        // 0x80054E34: nop
    
            goto L_80054E74;
    }
    // 0x80054E34: nop

    // 0x80054E38: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054E3C: lw          $t4, 0x638($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X638);
    // 0x80054E40: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80054E44: addiu       $t5, $t4, 0x24
    ctx->r13 = ADD32(ctx->r12, 0X24);
    // 0x80054E48: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80054E4C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80054E50: lw          $t2, 0x638($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X638);
    // 0x80054E54: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80054E58: nop

    // 0x80054E5C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054E60: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80054E64: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80054E68: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80054E6C: b           L_80055134
    // 0x80054E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054E70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054E74:
    // 0x80054E74: jal         0x80061F08
    // 0x80054E78: nop

    func_80061F08(rdram, ctx);
        goto after_6;
    // 0x80054E78: nop

    after_6:
    // 0x80054E7C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80054E80: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80054E84: nop

    // 0x80054E88: beq         $t7, $zero, L_80054EE4
    if (ctx->r15 == 0) {
        // 0x80054E8C: nop
    
            goto L_80054EE4;
    }
    // 0x80054E8C: nop

    // 0x80054E90: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80054E94: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80054E98: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80054E9C: lw          $t4, 0x470($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X470);
    // 0x80054EA0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80054EA4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80054EA8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80054EAC: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80054EB0: addiu       $t6, $t5, -0x1B0
    ctx->r14 = ADD32(ctx->r13, -0X1B0);
    // 0x80054EB4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80054EB8: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80054EBC: lw          $t3, 0x470($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X470);
    // 0x80054EC0: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80054EC4: nop

    // 0x80054EC8: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x80054ECC: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80054ED0: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80054ED4: addiu       $t7, $t9, -0x18
    ctx->r15 = ADD32(ctx->r25, -0X18);
    // 0x80054ED8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80054EDC: b           L_80055134
    // 0x80054EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80055134;
    // 0x80054EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054EE4:
    // 0x80054EE4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80054EE8: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80054EEC: nop

    // 0x80054EF0: lw          $t4, 0xB8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0XB8);
    // 0x80054EF4: nop

    // 0x80054EF8: beq         $t4, $zero, L_80054F78
    if (ctx->r12 == 0) {
        // 0x80054EFC: nop
    
            goto L_80054F78;
    }
    // 0x80054EFC: nop

    // 0x80054F00: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80054F04: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80054F08: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80054F0C: lw          $t6, 0xB8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XB8);
    // 0x80054F10: lw          $t3, 0x468($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X468);
    // 0x80054F14: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x80054F18: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x80054F1C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80054F20: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80054F24: addu        $t8, $t2, $t3
    ctx->r24 = ADD32(ctx->r10, ctx->r11);
    // 0x80054F28: addiu       $t9, $t8, -0x12
    ctx->r25 = ADD32(ctx->r24, -0X12);
    // 0x80054F2C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80054F30: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80054F34: lw          $t0, 0x468($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X468);
    // 0x80054F38: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80054F3C: nop

    // 0x80054F40: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80054F44: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80054F48: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80054F4C: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80054F50: lw          $t5, 0xB8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XB8);
    // 0x80054F54: nop

    // 0x80054F58: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80054F5C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80054F60: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80054F64: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80054F68: nop

    // 0x80054F6C: sw          $zero, 0xB8($t3)
    MEM_W(0XB8, ctx->r11) = 0;
    // 0x80054F70: b           L_80055134
    // 0x80054F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80054F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80054F78:
    // 0x80054F78: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80054F7C: jal         0x80055E40
    // 0x80054F80: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_80055E40(rdram, ctx);
        goto after_7;
    // 0x80054F80: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_7:
    // 0x80054F84: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80054F88: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80054F8C: nop

    // 0x80054F90: beq         $t8, $zero, L_80054FA0
    if (ctx->r24 == 0) {
        // 0x80054F94: nop
    
            goto L_80054FA0;
    }
    // 0x80054F94: nop

    // 0x80054F98: b           L_80055084
    // 0x80054F9C: nop

        goto L_80055084;
    // 0x80054F9C: nop

L_80054FA0:
    // 0x80054FA0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80054FA4: lw          $t9, 0x670($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X670);
    // 0x80054FA8: nop

    // 0x80054FAC: slti        $at, $t9, 0x12C
    ctx->r1 = SIGNED(ctx->r25) < 0X12C ? 1 : 0;
    // 0x80054FB0: beq         $at, $zero, L_80055028
    if (ctx->r1 == 0) {
        // 0x80054FB4: nop
    
            goto L_80055028;
    }
    // 0x80054FB4: nop

    // 0x80054FB8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80054FBC: lw          $t7, 0x258C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X258C);
    // 0x80054FC0: nop

    // 0x80054FC4: andi        $t0, $t7, 0x7
    ctx->r8 = ctx->r15 & 0X7;
    // 0x80054FC8: srl         $t1, $t0, 1
    ctx->r9 = S32(U32(ctx->r8) >> 1);
    // 0x80054FCC: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80054FD0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x80054FD4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80054FD8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80054FDC: lw          $t6, 0x468($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X468);
    // 0x80054FE0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80054FE4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80054FE8: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80054FEC: addu        $t2, $t5, $t6
    ctx->r10 = ADD32(ctx->r13, ctx->r14);
    // 0x80054FF0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80054FF4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80054FF8: lw          $t8, 0x468($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X468);
    // 0x80054FFC: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80055000: nop

    // 0x80055004: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80055008: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8005500C: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80055010: nop

    // 0x80055014: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80055018: b           L_80055134
    // 0x8005501C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x8005501C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80055020: b           L_8005512C
    // 0x80055024: nop

        goto L_8005512C;
    // 0x80055024: nop

L_80055028:
    // 0x80055028: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005502C: lw          $t1, 0x670($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X670);
    // 0x80055030: nop

    // 0x80055034: slti        $at, $t1, 0x15E
    ctx->r1 = SIGNED(ctx->r9) < 0X15E ? 1 : 0;
    // 0x80055038: beq         $at, $zero, L_80055084
    if (ctx->r1 == 0) {
        // 0x8005503C: nop
    
            goto L_80055084;
    }
    // 0x8005503C: nop

    // 0x80055040: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80055044: lw          $t4, 0x468($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X468);
    // 0x80055048: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8005504C: addiu       $t5, $t4, 0x120
    ctx->r13 = ADD32(ctx->r12, 0X120);
    // 0x80055050: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80055054: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80055058: lw          $t2, 0x468($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X468);
    // 0x8005505C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80055060: nop

    // 0x80055064: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80055068: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8005506C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80055070: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80055074: b           L_80055134
    // 0x80055078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80055078: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005507C: b           L_8005512C
    // 0x80055080: nop

        goto L_8005512C;
    // 0x80055080: nop

L_80055084:
    // 0x80055084: jal         0x80055CC4
    // 0x80055088: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_80055CC4(rdram, ctx);
        goto after_8;
    // 0x80055088: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x8005508C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80055090: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80055094: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80055098: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8005509C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800550A0: lw          $t1, -0x2A60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2A60);
    // 0x800550A4: nop

    // 0x800550A8: bne         $t1, $zero, L_800550DC
    if (ctx->r9 != 0) {
        // 0x800550AC: nop
    
            goto L_800550DC;
    }
    // 0x800550AC: nop

    // 0x800550B0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800550B4: jal         0x80055E40
    // 0x800550B8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80055E40(rdram, ctx);
        goto after_9;
    // 0x800550B8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_9:
    // 0x800550BC: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800550C0: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800550C4: nop

    // 0x800550C8: beq         $t4, $zero, L_800550DC
    if (ctx->r12 == 0) {
        // 0x800550CC: nop
    
            goto L_800550DC;
    }
    // 0x800550CC: nop

    // 0x800550D0: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800550D4: nop

    // 0x800550D8: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
L_800550DC:
    // 0x800550DC: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800550E0: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800550E4: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x800550E8: lw          $t3, 0x468($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X468);
    // 0x800550EC: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x800550F0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800550F4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800550F8: addu        $t8, $t2, $t3
    ctx->r24 = ADD32(ctx->r10, ctx->r11);
    // 0x800550FC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80055100: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80055104: lw          $t7, 0x468($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X468);
    // 0x80055108: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8005510C: nop

    // 0x80055110: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80055114: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80055118: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x8005511C: nop

    // 0x80055120: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x80055124: b           L_80055134
    // 0x80055128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80055134;
    // 0x80055128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005512C:
    // 0x8005512C: b           L_80055134
    // 0x80055130: nop

        goto L_80055134;
    // 0x80055130: nop

L_80055134:
    // 0x80055134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80055138: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005513C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80055140: jr          $ra
    // 0x80055144: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80055144: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800993AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800993AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800993B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800993B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800993B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800993BC:
    // 0x800993BC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800993C0: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800993C4: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800993C8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800993CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800993D0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800993D4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800993D8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800993DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800993E0: addiu       $t8, $t8, 0x1950
    ctx->r24 = ADD32(ctx->r24, 0X1950);
    // 0x800993E4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800993E8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800993EC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800993F0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800993F4: ori         $at, $zero, 0x80B0
    ctx->r1 = 0 | 0X80B0;
    // 0x800993F8: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x800993FC: bne         $t1, $t2, L_8009940C
    if (ctx->r9 != ctx->r10) {
        // 0x80099400: nop
    
            goto L_8009940C;
    }
    // 0x80099400: nop

    // 0x80099404: b           L_80099424
    // 0x80099408: nop

        goto L_80099424;
    // 0x80099408: nop

L_8009940C:
    // 0x8009940C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80099410: nop

    // 0x80099414: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80099418: slti        $at, $t4, 0xC
    ctx->r1 = SIGNED(ctx->r12) < 0XC ? 1 : 0;
    // 0x8009941C: bne         $at, $zero, L_800993BC
    if (ctx->r1 != 0) {
        // 0x80099420: sw          $t4, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r12;
            goto L_800993BC;
    }
    // 0x80099420: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
L_80099424:
    // 0x80099424: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80099428: jal         0x800C10AC
    // 0x8009942C: nop

    Thread_GetPriority(rdram, ctx);
        goto after_0;
    // 0x8009942C: nop

    after_0:
    // 0x80099430: b           L_80099440
    // 0x80099434: nop

        goto L_80099440;
    // 0x80099434: nop

    // 0x80099438: b           L_80099440
    // 0x8009943C: nop

        goto L_80099440;
    // 0x8009943C: nop

L_80099440:
    // 0x80099440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80099448: jr          $ra
    // 0x8009944C: nop

    return;
    // 0x8009944C: nop

;}
RECOMP_FUNC void func_80066DBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066DBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066DC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066DC4: jal         0x80061348
    // 0x80066DC8: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066DC8: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066DCC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066DD0: b           L_80066DE0
    // 0x80066DD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066DE0;
    // 0x80066DD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066DD8: b           L_80066DE0
    // 0x80066DDC: nop

        goto L_80066DE0;
    // 0x80066DDC: nop

L_80066DE0:
    // 0x80066DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066DE8: jr          $ra
    // 0x80066DEC: nop

    return;
    // 0x80066DEC: nop

;}
RECOMP_FUNC void func_800867F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800867F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800867F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800867FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80086800: jal         0x8008B4EC
    // 0x80086804: nop

    func_8008B4EC(rdram, ctx);
        goto after_0;
    // 0x80086804: nop

    after_0:
    // 0x80086808: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008680C: jal         0x8008B600
    // 0x80086810: nop

    func_8008B600(rdram, ctx);
        goto after_1;
    // 0x80086810: nop

    after_1:
    // 0x80086814: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80086818: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008681C: lh          $t7, 0xBE8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XBE8);
    // 0x80086820: addiu       $t0, $t0, 0x7AE8
    ctx->r8 = ADD32(ctx->r8, 0X7AE8);
    // 0x80086824: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80086828: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008682C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80086830: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80086834: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80086838: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x8008683C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x80086840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086844: jal         0x8008B738
    // 0x80086848: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8008B738(rdram, ctx);
        goto after_2;
    // 0x80086848: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x8008684C: b           L_80086854
    // 0x80086850: nop

        goto L_80086854;
    // 0x80086850: nop

L_80086854:
    // 0x80086854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008685C: jr          $ra
    // 0x80086860: nop

    return;
    // 0x80086860: nop

;}
RECOMP_FUNC void func_800627E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800627E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800627EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800627F0: jal         0x8005F064
    // 0x800627F4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800627F4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_0:
    // 0x800627F8: b           L_80062808
    // 0x800627FC: nop

        goto L_80062808;
    // 0x800627FC: nop

    // 0x80062800: b           L_80062808
    // 0x80062804: nop

        goto L_80062808;
    // 0x80062804: nop

L_80062808:
    // 0x80062808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006280C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062810: jr          $ra
    // 0x80062814: nop

    return;
    // 0x80062814: nop

;}
