#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800962B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800962B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800962B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962B8: sw          $t6, 0x6B98($at)
    MEM_W(0X6B98, ctx->r1) = ctx->r14;
    // 0x800962BC: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800962C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962C4: sw          $t7, 0x6BA0($at)
    MEM_W(0X6BA0, ctx->r1) = ctx->r15;
    // 0x800962C8: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800962CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962D0: sw          $t8, 0x6BA8($at)
    MEM_W(0X6BA8, ctx->r1) = ctx->r24;
    // 0x800962D4: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x800962D8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962DC: sw          $t9, 0x6BC0($at)
    MEM_W(0X6BC0, ctx->r1) = ctx->r25;
    // 0x800962E0: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x800962E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962E8: sw          $t0, 0x6C08($at)
    MEM_W(0X6C08, ctx->r1) = ctx->r8;
    // 0x800962EC: lw          $t1, 0x14($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14);
    // 0x800962F0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800962F4: sw          $t1, 0x6C14($at)
    MEM_W(0X6C14, ctx->r1) = ctx->r9;
    // 0x800962F8: lw          $t2, 0x18($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X18);
    // 0x800962FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096300: sw          $t2, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r10;
    // 0x80096304: lw          $t3, 0x1C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1C);
    // 0x80096308: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009630C: sw          $t3, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r11;
    // 0x80096310: lw          $t4, 0x20($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X20);
    // 0x80096314: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096318: sw          $t4, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r12;
    // 0x8009631C: lh          $t5, 0x24($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X24);
    // 0x80096320: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096324: sh          $t5, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = ctx->r13;
    // 0x80096328: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8009632C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096330: swc1        $f4, -0x4CBC($at)
    MEM_W(-0X4CBC, ctx->r1) = ctx->f4.u32l;
    // 0x80096334: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80096338: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8009633C: swc1        $f6, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f6.u32l;
    // 0x80096340: lwc1        $f8, 0x30($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80096344: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096348: swc1        $f8, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = ctx->f8.u32l;
    // 0x8009634C: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80096350: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096354: swc1        $f10, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->f10.u32l;
    // 0x80096358: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x8009635C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80096360: sw          $t6, -0x44BC($at)
    MEM_W(-0X44BC, ctx->r1) = ctx->r14;
    // 0x80096364: jr          $ra
    // 0x80096368: nop

    return;
    // 0x80096368: nop

    // 0x8009636C: jr          $ra
    // 0x80096370: nop

    return;
    // 0x80096370: nop

;}
RECOMP_FUNC void func_800526C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800526C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800526C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800526C8: nop

    // 0x800526CC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800526D0: nop

    // 0x800526D4: beq         $t7, $zero, L_800526EC
    if (ctx->r15 == 0) {
        // 0x800526D8: nop
    
            goto L_800526EC;
    }
    // 0x800526D8: nop

    // 0x800526DC: lh          $t8, 0x2($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X2);
    // 0x800526E0: nop

    // 0x800526E4: bne         $t8, $zero, L_800526F4
    if (ctx->r24 != 0) {
        // 0x800526E8: nop
    
            goto L_800526F4;
    }
    // 0x800526E8: nop

L_800526EC:
    // 0x800526EC: jr          $ra
    // 0x800526F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800526F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800526F4:
    // 0x800526F4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800526F8: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x800526FC: nop

    // 0x80052700: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80052704: nop

    // 0x80052708: slti        $at, $t0, 0x3D
    ctx->r1 = SIGNED(ctx->r8) < 0X3D ? 1 : 0;
    // 0x8005270C: beq         $at, $zero, L_8005271C
    if (ctx->r1 == 0) {
        // 0x80052710: nop
    
            goto L_8005271C;
    }
    // 0x80052710: nop

    // 0x80052714: jr          $ra
    // 0x80052718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80052718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005271C:
    // 0x8005271C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80052720: lw          $t1, 0x648($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X648);
    // 0x80052724: nop

    // 0x80052728: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8005272C: nop

    // 0x80052730: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x80052734: beq         $at, $zero, L_80052744
    if (ctx->r1 == 0) {
        // 0x80052738: nop
    
            goto L_80052744;
    }
    // 0x80052738: nop

    // 0x8005273C: jr          $ra
    // 0x80052740: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80052740: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80052744:
    // 0x80052744: jr          $ra
    // 0x80052748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80052748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80088BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80088BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088BD4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80088BD8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80088BDC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80088BE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80088BE4: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80088BE8: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x80088BEC: lhu         $t9, 0x2E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2E);
    // 0x80088BF0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80088BF4: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80088BF8: beq         $t0, $zero, L_80088C3C
    if (ctx->r8 == 0) {
        // 0x80088BFC: nop
    
            goto L_80088C3C;
    }
    // 0x80088BFC: nop

    // 0x80088C00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80088C04: jal         0x8008A518
    // 0x80088C08: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008A518(rdram, ctx);
        goto after_0;
    // 0x80088C08: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80088C0C: beq         $v0, $zero, L_80088C3C
    if (ctx->r2 == 0) {
        // 0x80088C10: nop
    
            goto L_80088C3C;
    }
    // 0x80088C10: nop

    // 0x80088C14: lhu         $t1, 0x1C($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X1C);
    // 0x80088C18: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80088C1C: bne         $t1, $at, L_80088C3C
    if (ctx->r9 != ctx->r1) {
        // 0x80088C20: nop
    
            goto L_80088C3C;
    }
    // 0x80088C20: nop

    // 0x80088C24: b           L_80088C2C
    // 0x80088C28: nop

        goto L_80088C2C;
    // 0x80088C28: nop

L_80088C2C:
    // 0x80088C2C: jal         0x8008CE48
    // 0x80088C30: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_1;
    // 0x80088C30: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80088C34: b           L_80088C84
    // 0x80088C38: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_80088C84;
    // 0x80088C38: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80088C3C:
    // 0x80088C3C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80088C40: lhu         $t3, 0x101C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X101C);
    // 0x80088C44: lhu         $t2, 0x2E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2E);
    // 0x80088C48: nop

    // 0x80088C4C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x80088C50: beq         $t4, $zero, L_80088C68
    if (ctx->r12 == 0) {
        // 0x80088C54: nop
    
            goto L_80088C68;
    }
    // 0x80088C54: nop

    // 0x80088C58: jal         0x8008CE48
    // 0x80088C5C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8008CE48(rdram, ctx);
        goto after_2;
    // 0x80088C5C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_2:
    // 0x80088C60: b           L_80088C84
    // 0x80088C64: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_80088C84;
    // 0x80088C64: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_80088C68:
    // 0x80088C68: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80088C6C: nop

    // 0x80088C70: lh          $v0, 0x4($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X4);
    // 0x80088C74: b           L_80088C84
    // 0x80088C78: nop

        goto L_80088C84;
    // 0x80088C78: nop

    // 0x80088C7C: b           L_80088C84
    // 0x80088C80: nop

        goto L_80088C84;
    // 0x80088C80: nop

L_80088C84:
    // 0x80088C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088C88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80088C8C: jr          $ra
    // 0x80088C90: nop

    return;
    // 0x80088C90: nop

;}
RECOMP_FUNC void func_8006440C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006440C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064414: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80064418: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006441C: nop

    // 0x80064420: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80064424: nop

    // 0x80064428: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006442C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80064430: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064434: beq         $v0, $zero, L_8006444C
    if (ctx->r2 == 0) {
        // 0x80064438: nop
    
            goto L_8006444C;
    }
    // 0x80064438: nop

    // 0x8006443C: jal         0x8005F064
    // 0x80064440: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80064440: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80064444: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80064448: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006444C:
    // 0x8006444C: b           L_8006445C
    // 0x80064450: nop

        goto L_8006445C;
    // 0x80064450: nop

    // 0x80064454: b           L_8006445C
    // 0x80064458: nop

        goto L_8006445C;
    // 0x80064458: nop

L_8006445C:
    // 0x8006445C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064464: jr          $ra
    // 0x80064468: nop

    return;
    // 0x80064468: nop

;}
RECOMP_FUNC void func_800B3EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3EC0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B3EC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B3EC8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B3ECC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B3ED0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B3ED4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B3ED8: lw          $t6, 0xD60($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD60);
    // 0x800B3EDC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3EE0: nop

    // 0x800B3EE4: bne         $t6, $t7, L_800B3F08
    if (ctx->r14 != ctx->r15) {
        // 0x800B3EE8: nop
    
            goto L_800B3F08;
    }
    // 0x800B3EE8: nop

    // 0x800B3EEC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B3EF0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B3EF4: addiu       $a1, $a1, 0xD60
    ctx->r5 = ADD32(ctx->r5, 0XD60);
    // 0x800B3EF8: jal         0x800BCFCC
    // 0x800B3EFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x800B3EFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x800B3F00: b           L_800B406C
    // 0x800B3F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B406C;
    // 0x800B3F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B3F08:
    // 0x800B3F08: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B3F0C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B3F10: lw          $t9, 0xD30($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD30);
    // 0x800B3F14: lw          $t8, 0xD34($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD34);
    // 0x800B3F18: nop

    // 0x800B3F1C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800B3F20: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800B3F24: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B3F28: nop

    // 0x800B3F2C: srl         $t2, $t1, 4
    ctx->r10 = S32(U32(ctx->r9) >> 4);
    // 0x800B3F30: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800B3F34: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B3F38: jal         0x800BC6EC
    // 0x800B3F3C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800B3F3C: nop

    after_1:
    // 0x800B3F40: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800B3F44: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800B3F48: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800B3F4C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800B3F50: lw          $a2, 0xD30($a2)
    ctx->r6 = MEM_W(ctx->r6, 0XD30);
    // 0x800B3F54: lw          $a1, 0x3E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3E28);
    // 0x800B3F58: lw          $a0, 0x3DF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF0);
    // 0x800B3F5C: jal         0x800BD1FC
    // 0x800B3F60: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x800B3F60: nop

    after_2:
    // 0x800B3F64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3F68: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800B3F6C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800B3F70: jal         0x800BD218
    // 0x800B3F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_3;
    // 0x800B3F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800B3F78: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800B3F7C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800B3F80: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x800B3F84: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3F88: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800B3F8C: nop

    // 0x800B3F90: sltu        $at, $t5, $t4
    ctx->r1 = ctx->r13 < ctx->r12 ? 1 : 0;
    // 0x800B3F94: beq         $at, $zero, L_800B3FF0
    if (ctx->r1 == 0) {
        // 0x800B3F98: nop
    
            goto L_800B3FF0;
    }
    // 0x800B3F98: nop

    // 0x800B3F9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B3FA0: nop

    // 0x800B3FA4: blez        $t6, L_800B3FF0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B3FA8: nop
    
            goto L_800B3FF0;
    }
    // 0x800B3FA8: nop

L_800B3FAC:
    // 0x800B3FAC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3FB0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B3FB4: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800B3FB8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B3FBC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800B3FC0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800B3FC4: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800B3FC8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3FCC: nop

    // 0x800B3FD0: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
    // 0x800B3FD4: beq         $at, $zero, L_800B3FF0
    if (ctx->r1 == 0) {
        // 0x800B3FD8: nop
    
            goto L_800B3FF0;
    }
    // 0x800B3FD8: nop

    // 0x800B3FDC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800B3FE0: nop

    // 0x800B3FE4: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B3FE8: bne         $at, $zero, L_800B3FAC
    if (ctx->r1 != 0) {
        // 0x800B3FEC: nop
    
            goto L_800B3FAC;
    }
    // 0x800B3FEC: nop

L_800B3FF0:
    // 0x800B3FF0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3FF4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3FF8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800B3FFC: nop

    // 0x800B4000: bne         $t5, $t6, L_800B402C
    if (ctx->r13 != ctx->r14) {
        // 0x800B4004: nop
    
            goto L_800B402C;
    }
    // 0x800B4004: nop

    // 0x800B4008: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B400C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800B4010: jal         0x800BCFCC
    // 0x800B4014: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x800B4014: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x800B4018: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B401C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800B4020: addiu       $a0, $a0, 0xD60
    ctx->r4 = ADD32(ctx->r4, 0XD60);
    // 0x800B4024: jal         0x800BCFCC
    // 0x800B4028: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x800B4028: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_5:
L_800B402C:
    // 0x800B402C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B4030: jal         0x800BC980
    // 0x800B4034: nop

    SysMem_Free(rdram, ctx);
        goto after_6;
    // 0x800B4034: nop

    after_6:
    // 0x800B4038: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800B403C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800B4040: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800B4044: nop

    // 0x800B4048: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x800B404C: beq         $at, $zero, L_800B405C
    if (ctx->r1 == 0) {
        // 0x800B4050: nop
    
            goto L_800B405C;
    }
    // 0x800B4050: nop

    // 0x800B4054: b           L_800B406C
    // 0x800B4058: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800B406C;
    // 0x800B4058: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B405C:
    // 0x800B405C: b           L_800B406C
    // 0x800B4060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B406C;
    // 0x800B4060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4064: b           L_800B406C
    // 0x800B4068: nop

        goto L_800B406C;
    // 0x800B4068: nop

L_800B406C:
    // 0x800B406C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B4074: jr          $ra
    // 0x800B4078: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B4078: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Thread_SendMesgNoBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C126C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C1270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1274: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C1278: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C127C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C1280: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C1284: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1288: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C128C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C1290: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C1294: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C1298: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C129C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C12A0: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C12A4: nop

    // 0x800C12A8: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C12AC: bne         $t9, $zero, L_800C12BC
    if (ctx->r25 != 0) {
        // 0x800C12B0: nop
    
            goto L_800C12BC;
    }
    // 0x800C12B0: nop

    // 0x800C12B4: b           L_800C1304
    // 0x800C12B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800C1304;
    // 0x800C12B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C12BC:
    // 0x800C12BC: lbu         $t0, 0x1B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1B);
    // 0x800C12C0: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800C12C4: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x800C12C8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C12CC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C12D0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C12D4: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C12D8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C12DC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C12E0: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C12E4: addiu       $t3, $t3, 0x1950
    ctx->r11 = ADD32(ctx->r11, 0X1950);
    // 0x800C12E8: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800C12EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C12F0: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800C12F4: jal         0x800C4AA0
    // 0x800C12F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C12F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C12FC: b           L_800C1304
    // 0x800C1300: nop

        goto L_800C1304;
    // 0x800C1300: nop

L_800C1304:
    // 0x800C1304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C130C: jr          $ra
    // 0x800C1310: nop

    return;
    // 0x800C1310: nop

;}
RECOMP_FUNC void func_80060A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80060A10: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80060A14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80060A18: bne         $t6, $at, L_80060A2C
    if (ctx->r14 != ctx->r1) {
        // 0x80060A1C: nop
    
            goto L_80060A2C;
    }
    // 0x80060A1C: nop

    // 0x80060A20: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80060A24: b           L_80060ABC
    // 0x80060A28: nop

        goto L_80060ABC;
    // 0x80060A28: nop

L_80060A2C:
    // 0x80060A2C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80060A30: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80060A34: nop

    // 0x80060A38: lh          $t8, 0x2E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2E);
    // 0x80060A3C: nop

    // 0x80060A40: slti        $at, $t8, 0x2BC
    ctx->r1 = SIGNED(ctx->r24) < 0X2BC ? 1 : 0;
    // 0x80060A44: beq         $at, $zero, L_80060A58
    if (ctx->r1 == 0) {
        // 0x80060A48: nop
    
            goto L_80060A58;
    }
    // 0x80060A48: nop

    // 0x80060A4C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80060A50: b           L_80060ABC
    // 0x80060A54: nop

        goto L_80060ABC;
    // 0x80060A54: nop

L_80060A58:
    // 0x80060A58: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80060A5C: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80060A60: nop

    // 0x80060A64: lh          $t0, 0x2E($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2E);
    // 0x80060A68: nop

    // 0x80060A6C: slti        $at, $t0, 0x384
    ctx->r1 = SIGNED(ctx->r8) < 0X384 ? 1 : 0;
    // 0x80060A70: beq         $at, $zero, L_80060AA8
    if (ctx->r1 == 0) {
        // 0x80060A74: nop
    
            goto L_80060AA8;
    }
    // 0x80060A74: nop

    // 0x80060A78: jal         0x800C4240
    // 0x80060A7C: nop

    guRandom(rdram, ctx);
        goto after_0;
    // 0x80060A7C: nop

    after_0:
    // 0x80060A80: bgez        $v0, L_80060A94
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80060A84: andi        $t1, $v0, 0x1
        ctx->r9 = ctx->r2 & 0X1;
            goto L_80060A94;
    }
    // 0x80060A84: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80060A88: beq         $t1, $zero, L_80060A94
    if (ctx->r9 == 0) {
        // 0x80060A8C: nop
    
            goto L_80060A94;
    }
    // 0x80060A8C: nop

    // 0x80060A90: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
L_80060A94:
    // 0x80060A94: beq         $t1, $zero, L_80060AA8
    if (ctx->r9 == 0) {
        // 0x80060A98: nop
    
            goto L_80060AA8;
    }
    // 0x80060A98: nop

    // 0x80060A9C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80060AA0: b           L_80060ABC
    // 0x80060AA4: nop

        goto L_80060ABC;
    // 0x80060AA4: nop

L_80060AA8:
    // 0x80060AA8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80060AAC: b           L_80060ABC
    // 0x80060AB0: nop

        goto L_80060ABC;
    // 0x80060AB0: nop

    // 0x80060AB4: b           L_80060ABC
    // 0x80060AB8: nop

        goto L_80060ABC;
    // 0x80060AB8: nop

L_80060ABC:
    // 0x80060ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060AC4: jr          $ra
    // 0x80060AC8: nop

    return;
    // 0x80060AC8: nop

;}
RECOMP_FUNC void Thread_GetCreatedThreadsCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0E84: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800C0E88: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800C0E8C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800C0E90:
    // 0x800C0E90: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800C0E94: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0E98: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0E9C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0EA0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0EA4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0EA8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0EAC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0EB0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0EB4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0EB8: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0EBC: nop

    // 0x800C0EC0: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0EC4: beq         $t9, $zero, L_800C0EDC
    if (ctx->r25 == 0) {
        // 0x800C0EC8: nop
    
            goto L_800C0EDC;
    }
    // 0x800C0EC8: nop

    // 0x800C0ECC: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800C0ED0: nop

    // 0x800C0ED4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C0ED8: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
L_800C0EDC:
    // 0x800C0EDC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800C0EE0: nop

    // 0x800C0EE4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C0EE8: slti        $at, $t3, 0xC
    ctx->r1 = SIGNED(ctx->r11) < 0XC ? 1 : 0;
    // 0x800C0EEC: bne         $at, $zero, L_800C0E90
    if (ctx->r1 != 0) {
        // 0x800C0EF0: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_800C0E90;
    }
    // 0x800C0EF0: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800C0EF4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800C0EF8: b           L_800C0F08
    // 0x800C0EFC: nop

        goto L_800C0F08;
    // 0x800C0EFC: nop

    // 0x800C0F00: b           L_800C0F08
    // 0x800C0F04: nop

        goto L_800C0F08;
    // 0x800C0F04: nop

L_800C0F08:
    // 0x800C0F08: jr          $ra
    // 0x800C0F0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800C0F0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006C480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C488: jal         0x8005F064
    // 0x8006C48C: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C48C: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    after_0:
    // 0x8006C490: b           L_8006C4A0
    // 0x8006C494: nop

        goto L_8006C4A0;
    // 0x8006C494: nop

    // 0x8006C498: b           L_8006C4A0
    // 0x8006C49C: nop

        goto L_8006C4A0;
    // 0x8006C49C: nop

L_8006C4A0:
    // 0x8006C4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C4A8: jr          $ra
    // 0x8006C4AC: nop

    return;
    // 0x8006C4AC: nop

;}
RECOMP_FUNC void func_8008D90C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D90C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8008D910: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8008D914: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8008D918: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8008D91C: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8008D920: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8008D924: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8008D928: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8008D92C: beq         $t8, $zero, L_8008D9B4
    if (ctx->r24 == 0) {
        // 0x8008D930: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_8008D9B4;
    }
    // 0x8008D930: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_8008D934:
    // 0x8008D934: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8008D938: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D93C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008D940: nop

    // 0x8008D944: swc1        $f4, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f4.u32l;
    // 0x8008D948: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8008D94C: nop

    // 0x8008D950: lwc1        $f6, 0xF0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x8008D954: nop

    // 0x8008D958: swc1        $f6, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f6.u32l;
    // 0x8008D95C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8008D960: addiu       $at, $zero, -0x49
    ctx->r1 = ADD32(0, -0X49);
    // 0x8008D964: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x8008D968: nop

    // 0x8008D96C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8008D970: sw          $t3, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r11;
    // 0x8008D974: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8008D978: nop

    // 0x8008D97C: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x8008D980: nop

    // 0x8008D984: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8008D988: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x8008D98C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8008D990: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8008D994: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8008D998: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x8008D99C: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x8008D9A0: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8008D9A4: beq         $at, $zero, L_8008D9B4
    if (ctx->r1 == 0) {
        // 0x8008D9A8: sw          $t8, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r24;
            goto L_8008D9B4;
    }
    // 0x8008D9A8: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8008D9AC: bne         $t0, $zero, L_8008D934
    if (ctx->r8 != 0) {
        // 0x8008D9B0: nop
    
            goto L_8008D934;
    }
    // 0x8008D9B0: nop

L_8008D9B4:
    // 0x8008D9B4: lw          $t2, 0x230($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X230);
    // 0x8008D9B8: addiu       $at, $zero, -0x49
    ctx->r1 = ADD32(0, -0X49);
    // 0x8008D9BC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8008D9C0: sw          $t3, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r11;
    // 0x8008D9C4: lw          $t1, 0x230($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X230);
    // 0x8008D9C8: nop

    // 0x8008D9CC: ori         $t5, $t1, 0x10
    ctx->r13 = ctx->r9 | 0X10;
    // 0x8008D9D0: sw          $t5, 0x230($a0)
    MEM_W(0X230, ctx->r4) = ctx->r13;
    // 0x8008D9D4: b           L_8008D9DC
    // 0x8008D9D8: nop

        goto L_8008D9DC;
    // 0x8008D9D8: nop

L_8008D9DC:
    // 0x8008D9DC: jr          $ra
    // 0x8008D9E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8008D9E0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80064538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006453C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064540: jal         0x80061488
    // 0x80064544: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80064544: addiu       $a0, $zero, 0x5BF
    ctx->r4 = ADD32(0, 0X5BF);
    after_0:
    // 0x80064548: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006454C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80064550: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x80064554: nop
    
            goto L_800645E4;
    }
    // 0x80064554: nop

    // 0x80064558: jal         0x80061488
    // 0x8006455C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x8006455C: addiu       $a0, $zero, 0x629
    ctx->r4 = ADD32(0, 0X629);
    after_1:
    // 0x80064560: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064564: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80064568: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x8006456C: nop
    
            goto L_800645E4;
    }
    // 0x8006456C: nop

    // 0x80064570: jal         0x80061488
    // 0x80064574: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    func_80061488(rdram, ctx);
        goto after_2;
    // 0x80064574: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    after_2:
    // 0x80064578: slt         $t8, $zero, $v0
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006457C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80064580: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x80064584: nop
    
            goto L_800645E4;
    }
    // 0x80064584: nop

    // 0x80064588: jal         0x80061488
    // 0x8006458C: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    func_80061488(rdram, ctx);
        goto after_3;
    // 0x8006458C: addiu       $a0, $zero, 0x633
    ctx->r4 = ADD32(0, 0X633);
    after_3:
    // 0x80064590: slt         $t9, $zero, $v0
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064594: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80064598: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x8006459C: nop
    
            goto L_800645E4;
    }
    // 0x8006459C: nop

    // 0x800645A0: jal         0x80061488
    // 0x800645A4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    func_80061488(rdram, ctx);
        goto after_4;
    // 0x800645A4: addiu       $a0, $zero, 0x638
    ctx->r4 = ADD32(0, 0X638);
    after_4:
    // 0x800645A8: slt         $t0, $zero, $v0
    ctx->r8 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800645AC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800645B0: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x800645B4: nop
    
            goto L_800645E4;
    }
    // 0x800645B4: nop

    // 0x800645B8: jal         0x8005F064
    // 0x800645BC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_5;
    // 0x800645BC: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_5:
    // 0x800645C0: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x800645C4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800645C8: beq         $v0, $zero, L_800645E4
    if (ctx->r2 == 0) {
        // 0x800645CC: nop
    
            goto L_800645E4;
    }
    // 0x800645CC: nop

    // 0x800645D0: jal         0x80061348
    // 0x800645D4: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    func_80061348(rdram, ctx);
        goto after_6;
    // 0x800645D4: addiu       $a0, $zero, 0x6C8
    ctx->r4 = ADD32(0, 0X6C8);
    after_6:
    // 0x800645D8: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800645DC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800645E0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800645E4:
    // 0x800645E4: b           L_800645F4
    // 0x800645E8: nop

        goto L_800645F4;
    // 0x800645E8: nop

    // 0x800645EC: b           L_800645F4
    // 0x800645F0: nop

        goto L_800645F4;
    // 0x800645F0: nop

L_800645F4:
    // 0x800645F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800645F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800645FC: jr          $ra
    // 0x80064600: nop

    return;
    // 0x80064600: nop

;}
RECOMP_FUNC void func_800615C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800615C8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800615CC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800615D0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800615D4: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x800615D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800615DC: lw          $t6, 0x658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X658);
    // 0x800615E0: nop

    // 0x800615E4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800615E8: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800615EC: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800615F0: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800615F4: nop

    // 0x800615F8: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800615FC: bne         $at, $zero, L_800616F0
    if (ctx->r1 != 0) {
        // 0x80061600: nop
    
            goto L_800616F0;
    }
    // 0x80061600: nop

L_80061604:
    // 0x80061604: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80061608: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8006160C: nop

    // 0x80061610: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80061614: bgez        $t2, L_80061624
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80061618: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80061624;
    }
    // 0x80061618: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8006161C: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80061620: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80061624:
    // 0x80061624: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x80061628: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x8006162C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80061630: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80061634: lw          $t4, 0x650($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X650);
    // 0x80061638: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8006163C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80061640: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80061644: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80061648: nop

    // 0x8006164C: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80061650: beq         $at, $zero, L_8006166C
    if (ctx->r1 == 0) {
        // 0x80061654: nop
    
            goto L_8006166C;
    }
    // 0x80061654: nop

    // 0x80061658: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8006165C: nop

    // 0x80061660: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80061664: b           L_800616D8
    // 0x80061668: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
        goto L_800616D8;
    // 0x80061668: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
L_8006166C:
    // 0x8006166C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80061670: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80061674: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80061678: lw          $t1, 0x650($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X650);
    // 0x8006167C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80061680: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80061684: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80061688: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x8006168C: nop

    // 0x80061690: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80061694: beq         $at, $zero, L_800616B0
    if (ctx->r1 == 0) {
        // 0x80061698: nop
    
            goto L_800616B0;
    }
    // 0x80061698: nop

    // 0x8006169C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800616A0: nop

    // 0x800616A4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800616A8: b           L_800616D8
    // 0x800616AC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
        goto L_800616D8;
    // 0x800616AC: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
L_800616B0:
    // 0x800616B0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800616B4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800616B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800616BC: lw          $t0, 0x650($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X650);
    // 0x800616C0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800616C4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800616C8: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x800616CC: lbu         $v0, 0x4($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X4);
    // 0x800616D0: b           L_80061700
    // 0x800616D4: nop

        goto L_80061700;
    // 0x800616D4: nop

L_800616D8:
    // 0x800616D8: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800616DC: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800616E0: nop

    // 0x800616E4: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800616E8: beq         $at, $zero, L_80061604
    if (ctx->r1 == 0) {
        // 0x800616EC: nop
    
            goto L_80061604;
    }
    // 0x800616EC: nop

L_800616F0:
    // 0x800616F0: b           L_80061700
    // 0x800616F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80061700;
    // 0x800616F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800616F8: b           L_80061700
    // 0x800616FC: nop

        goto L_80061700;
    // 0x800616FC: nop

L_80061700:
    // 0x80061700: jr          $ra
    // 0x80061704: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80061704: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8004FAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FAA0: jr          $ra
    // 0x8004FAA4: nop

    return;
    // 0x8004FAA4: nop

    // 0x8004FAA8: jr          $ra
    // 0x8004FAAC: nop

    return;
    // 0x8004FAAC: nop

;}
RECOMP_FUNC void func_80073704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007370C: jal         0x80061488
    // 0x80073710: addiu       $a0, $zero, 0x6CA
    ctx->r4 = ADD32(0, 0X6CA);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073710: addiu       $a0, $zero, 0x6CA
    ctx->r4 = ADD32(0, 0X6CA);
    after_0:
    // 0x80073714: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80073718: b           L_80073728
    // 0x8007371C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073728;
    // 0x8007371C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073720: b           L_80073728
    // 0x80073724: nop

        goto L_80073728;
    // 0x80073724: nop

L_80073728:
    // 0x80073728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007372C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073730: jr          $ra
    // 0x80073734: nop

    return;
    // 0x80073734: nop

;}
RECOMP_FUNC void func_8007424C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007424C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074254: jal         0x80061348
    // 0x80074258: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80074258: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x8007425C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80074260: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80074264: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80074268: beq         $v0, $zero, L_80074284
    if (ctx->r2 == 0) {
        // 0x8007426C: nop
    
            goto L_80074284;
    }
    // 0x8007426C: nop

    // 0x80074270: jal         0x80061348
    // 0x80074274: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80074274: addiu       $a0, $zero, 0x458
    ctx->r4 = ADD32(0, 0X458);
    after_1:
    // 0x80074278: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8007427C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80074280: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80074284:
    // 0x80074284: b           L_80074294
    // 0x80074288: nop

        goto L_80074294;
    // 0x80074288: nop

    // 0x8007428C: b           L_80074294
    // 0x80074290: nop

        goto L_80074294;
    // 0x80074290: nop

L_80074294:
    // 0x80074294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007429C: jr          $ra
    // 0x800742A0: nop

    return;
    // 0x800742A0: nop

;}
RECOMP_FUNC void func_800772E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800772E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800772EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800772F0: jal         0x80061488
    // 0x800772F4: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800772F4: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x800772F8: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800772FC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077300: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077304: beq         $v0, $zero, L_8007732C
    if (ctx->r2 == 0) {
        // 0x80077308: nop
    
            goto L_8007732C;
    }
    // 0x80077308: nop

    // 0x8007730C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80077310: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80077314: nop

    // 0x80077318: lh          $v0, 0x32($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X32);
    // 0x8007731C: nop

    // 0x80077320: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077324: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80077328: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8007732C:
    // 0x8007732C: b           L_8007733C
    // 0x80077330: nop

        goto L_8007733C;
    // 0x80077330: nop

    // 0x80077334: b           L_8007733C
    // 0x80077338: nop

        goto L_8007733C;
    // 0x80077338: nop

L_8007733C:
    // 0x8007733C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077344: jr          $ra
    // 0x80077348: nop

    return;
    // 0x80077348: nop

;}
RECOMP_FUNC void alAdpcmPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D087C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800D0880: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800D0884: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800D0888: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D088C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800D0890: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800D0894: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800D0898: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800D089C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800D08A0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800D08A4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800D08A8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800D08AC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800D08B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800D08B4: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800D08B8: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800D08BC: bne         $a2, $zero, L_800D08CC
    if (ctx->r6 != 0) {
        // 0x800D08C0: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800D08CC;
    }
    // 0x800D08C0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800D08C4: b           L_800D0CEC
    // 0x800D08C8: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
        goto L_800D0CEC;
    // 0x800D08C8: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_800D08CC:
    // 0x800D08CC: lw          $t6, 0x2C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X2C);
    // 0x800D08D0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D08D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D08D8: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x800D08DC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800D08E0: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x800D08E4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800D08E8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D08EC: lw          $t9, 0x28($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X28);
    // 0x800D08F0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800D08F4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D08F8: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x800D08FC: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x800D0900: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D0904: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D0908: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D090C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800D0910: lw          $v1, 0x38($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X38);
    // 0x800D0914: lw          $a0, 0x20($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X20);
    // 0x800D0918: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800D091C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800D0920: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x800D0924: beq         $t1, $zero, L_800D0938
    if (ctx->r9 == 0) {
        // 0x800D0928: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_800D0938;
    }
    // 0x800D0928: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800D092C: lw          $t1, 0x24($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X24);
    // 0x800D0930: sltu        $t6, $zero, $t1
    ctx->r14 = 0 < ctx->r9 ? 1 : 0;
    // 0x800D0934: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_800D0938:
    // 0x800D0938: beq         $t1, $zero, L_800D0948
    if (ctx->r9 == 0) {
        // 0x800D093C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800D0948;
    }
    // 0x800D093C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D0940: b           L_800D0948
    // 0x800D0944: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_800D0948;
    // 0x800D0944: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_800D0948:
    // 0x800D0948: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800D094C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800D0950: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800D0954: beq         $v1, $zero, L_800D0964
    if (ctx->r3 == 0) {
        // 0x800D0958: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800D0964;
    }
    // 0x800D0958: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800D095C: b           L_800D0964
    // 0x800D0960: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
        goto L_800D0964;
    // 0x800D0960: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
L_800D0964:
    // 0x800D0964: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800D0968: bgez        $a0, L_800D0974
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D096C: nop
    
            goto L_800D0974;
    }
    // 0x800D096C: nop

    // 0x800D0970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800D0974:
    // 0x800D0974: beq         $t1, $zero, L_800D0B7C
    if (ctx->r9 == 0) {
        // 0x800D0978: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_800D0B7C;
    }
    // 0x800D0978: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800D097C: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800D0980: sra         $t8, $fp, 4
    ctx->r24 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800D0984: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800D0988: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800D098C: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800D0990: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x800D0994: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800D0998: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800D099C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800D09A0: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800D09A4: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800D09A8: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x800D09AC: jal         0x800D0750
    // 0x800D09B0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_800D0750(rdram, ctx);
        goto after_0;
    // 0x800D09B0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_0:
    // 0x800D09B4: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800D09B8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800D09BC: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D09C0: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800D09C4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800D09C8: beq         $v1, $zero, L_800D09E4
    if (ctx->r3 == 0) {
        // 0x800D09CC: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800D09E4;
    }
    // 0x800D09CC: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800D09D0: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800D09D4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800D09D8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800D09DC: b           L_800D09F0
    // 0x800D09E0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
        goto L_800D09F0;
    // 0x800D09E0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800D09E4:
    // 0x800D09E4: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800D09E8: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800D09EC: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_800D09F0:
    // 0x800D09F0: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x800D09F4: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x800D09F8: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D09FC: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800D0A00: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800D0A04: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D0A08: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x800D0A0C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800D0A10: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800D0A14: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800D0A18: addiu       $t9, $t7, 0x9
    ctx->r25 = ADD32(ctx->r15, 0X9);
    // 0x800D0A1C: sw          $t9, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r25;
    // 0x800D0A20: sw          $v0, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r2;
    // 0x800D0A24: beq         $at, $zero, L_800D0B4C
    if (ctx->r1 == 0) {
        // 0x800D0A28: lh          $a2, 0x0($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X0);
            goto L_800D0B4C;
    }
    // 0x800D0A28: lh          $a2, 0x0($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X0);
    // 0x800D0A2C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_800D0A30:
    // 0x800D0A30: addiu       $t8, $fp, 0x1
    ctx->r24 = ADD32(ctx->r30, 0X1);
    // 0x800D0A34: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x800D0A38: lw          $v0, 0x24($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X24);
    // 0x800D0A3C: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x800D0A40: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800D0A44: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x800D0A48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0A4C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800D0A50: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800D0A54: beq         $v0, $at, L_800D0A68
    if (ctx->r2 == ctx->r1) {
        // 0x800D0A58: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_800D0A68;
    }
    // 0x800D0A58: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800D0A5C: beq         $v0, $zero, L_800D0A68
    if (ctx->r2 == 0) {
        // 0x800D0A60: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800D0A68;
    }
    // 0x800D0A60: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800D0A64: sw          $t9, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r25;
L_800D0A68:
    // 0x800D0A68: lw          $t8, 0x20($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X20);
    // 0x800D0A6C: lw          $t6, 0x1C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X1C);
    // 0x800D0A70: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800D0A74: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800D0A78: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x800D0A7C: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800D0A80: beq         $at, $zero, L_800D0A90
    if (ctx->r1 == 0) {
        // 0x800D0A84: sll         $s5, $a3, 16
        ctx->r21 = S32(ctx->r7 << 16);
            goto L_800D0A90;
    }
    // 0x800D0A84: sll         $s5, $a3, 16
    ctx->r21 = S32(ctx->r7 << 16);
    // 0x800D0A88: b           L_800D0A94
    // 0x800D0A8C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_800D0A94;
    // 0x800D0A8C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_800D0A90:
    // 0x800D0A90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D0A94:
    // 0x800D0A94: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0A98: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x800D0A9C: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x800D0AA0: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x800D0AA4: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800D0AA8: bgez        $a0, L_800D0AB4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D0AAC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800D0AB4;
    }
    // 0x800D0AAC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800D0AB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800D0AB4:
    // 0x800D0AB4: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800D0AB8: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800D0ABC: sra         $t9, $fp, 4
    ctx->r25 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800D0AC0: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800D0AC4: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800D0AC8: ori         $t6, $s4, 0x2
    ctx->r14 = ctx->r20 | 0X2;
    // 0x800D0ACC: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800D0AD0: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800D0AD4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800D0AD8: or          $fp, $t9, $zero
    ctx->r30 = ctx->r25 | 0;
    // 0x800D0ADC: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800D0AE0: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x800D0AE4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800D0AE8: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800D0AEC: jal         0x800D0750
    // 0x800D0AF0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_800D0750(rdram, ctx);
        goto after_1;
    // 0x800D0AF0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_1:
    // 0x800D0AF4: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0AF8: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x800D0AFC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D0B00: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800D0B04: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D0B08: addu        $t8, $t9, $a3
    ctx->r24 = ADD32(ctx->r25, ctx->r7);
    // 0x800D0B0C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800D0B10: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800D0B14: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800D0B18: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800D0B1C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D0B20: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800D0B24: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800D0B28: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800D0B2C: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800D0B30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D0B34: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800D0B38: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800D0B3C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D0B40: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D0B44: bne         $at, $zero, L_800D0A30
    if (ctx->r1 != 0) {
        // 0x800D0B48: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_800D0A30;
    }
    // 0x800D0B48: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_800D0B4C:
    // 0x800D0B4C: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0B50: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800D0B54: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800D0B58: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800D0B5C: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800D0B60: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800D0B64: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800D0B68: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800D0B6C: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800D0B70: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800D0B74: b           L_800D0CEC
    // 0x800D0B78: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800D0CEC;
    // 0x800D0B78: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800D0B7C:
    // 0x800D0B7C: lw          $v0, 0x28($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X28);
    // 0x800D0B80: sra         $t7, $fp, 4
    ctx->r15 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800D0B84: lw          $t9, 0x44($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X44);
    // 0x800D0B88: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x800D0B8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D0B90: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800D0B94: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x800D0B98: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800D0B9C: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800D0BA0: subu        $t6, $t3, $t8
    ctx->r14 = SUB32(ctx->r11, ctx->r24);
    // 0x800D0BA4: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x800D0BA8: bgez        $v1, L_800D0BB4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D0BAC: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_800D0BB4;
    }
    // 0x800D0BAC: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x800D0BB0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D0BB4:
    // 0x800D0BB4: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800D0BB8: mflo        $v0
    ctx->r2 = lo;
    // 0x800D0BBC: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x800D0BC0: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x800D0BC4: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D0BC8: beq         $at, $zero, L_800D0BD4
    if (ctx->r1 == 0) {
        // 0x800D0BCC: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_800D0BD4;
    }
    // 0x800D0BCC: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800D0BD0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_800D0BD4:
    // 0x800D0BD4: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x800D0BD8: subu        $t6, $a0, $t8
    ctx->r14 = SUB32(ctx->r4, ctx->r24);
    // 0x800D0BDC: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D0BE0: beq         $at, $zero, L_800D0C90
    if (ctx->r1 == 0) {
        // 0x800D0BE4: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_800D0C90;
    }
    // 0x800D0BE4: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x800D0BE8: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800D0BEC: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800D0BF0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D0BF4: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800D0BF8: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800D0BFC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800D0C00: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800D0C04: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800D0C08: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800D0C0C: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800D0C10: subu        $s6, $a1, $a0
    ctx->r22 = SUB32(ctx->r5, ctx->r4);
    // 0x800D0C14: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800D0C18: jal         0x800D0750
    // 0x800D0C1C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_800D0750(rdram, ctx);
        goto after_2;
    // 0x800D0C1C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_2:
    // 0x800D0C20: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0C24: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800D0C28: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800D0C2C: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800D0C30: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800D0C34: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800D0C38: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800D0C3C: beq         $v1, $zero, L_800D0C58
    if (ctx->r3 == 0) {
        // 0x800D0C40: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800D0C58;
    }
    // 0x800D0C40: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800D0C44: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800D0C48: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800D0C4C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D0C50: b           L_800D0C64
    // 0x800D0C54: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800D0C64;
    // 0x800D0C54: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800D0C58:
    // 0x800D0C58: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800D0C5C: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x800D0C60: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800D0C64:
    // 0x800D0C64: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800D0C68: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800D0C6C: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800D0C70: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800D0C74: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800D0C78: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800D0C7C: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800D0C80: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800D0C84: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800D0C88: b           L_800D0C98
    // 0x800D0C8C: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800D0C98;
    // 0x800D0C8C: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800D0C90:
    // 0x800D0C90: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800D0C94: sw          $t3, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r11;
L_800D0C98:
    // 0x800D0C98: beq         $a0, $zero, L_800D0CE8
    if (ctx->r4 == 0) {
        // 0x800D0C9C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800D0CE8;
    }
    // 0x800D0C9C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800D0CA0: beq         $t5, $zero, L_800D0CB8
    if (ctx->r13 == 0) {
        // 0x800D0CA4: sw          $zero, 0x3C($s7)
        MEM_W(0X3C, ctx->r23) = 0;
            goto L_800D0CB8;
    }
    // 0x800D0CA4: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800D0CA8: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x800D0CAC: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800D0CB0: b           L_800D0CBC
    // 0x800D0CB4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_800D0CBC;
    // 0x800D0CB4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800D0CB8:
    // 0x800D0CB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D0CBC:
    // 0x800D0CBC: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800D0CC0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800D0CC4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D0CC8: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800D0CCC: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800D0CD0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800D0CD4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D0CD8: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800D0CDC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D0CE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D0CE4: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_800D0CE8:
    // 0x800D0CE8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800D0CEC:
    // 0x800D0CEC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800D0CF0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800D0CF4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800D0CF8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800D0CFC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800D0D00: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800D0D04: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800D0D08: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800D0D0C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800D0D10: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800D0D14: jr          $ra
    // 0x800D0D18: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800D0D18: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8006F0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F0E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F0E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F0E8: jal         0x80061348
    // 0x8006F0EC: addiu       $a0, $zero, 0x2BB
    ctx->r4 = ADD32(0, 0X2BB);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F0EC: addiu       $a0, $zero, 0x2BB
    ctx->r4 = ADD32(0, 0X2BB);
    after_0:
    // 0x8006F0F0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F0F4: b           L_8006F104
    // 0x8006F0F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F104;
    // 0x8006F0F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F0FC: b           L_8006F104
    // 0x8006F100: nop

        goto L_8006F104;
    // 0x8006F100: nop

L_8006F104:
    // 0x8006F104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F10C: jr          $ra
    // 0x8006F110: nop

    return;
    // 0x8006F110: nop

;}
RECOMP_FUNC void func_8006D0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D0BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D0C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D0C4: nop

    // 0x8006D0C8: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006D0CC: nop

    // 0x8006D0D0: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006D0D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D0D8: jr          $ra
    // 0x8006D0DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D0DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D0E0: jr          $ra
    // 0x8006D0E4: nop

    return;
    // 0x8006D0E4: nop

    // 0x8006D0E8: jr          $ra
    // 0x8006D0EC: nop

    return;
    // 0x8006D0EC: nop

;}
RECOMP_FUNC void func_80029E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029E48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80029E4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029E50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80029E54: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80029E58: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80029E5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80029E60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80029E64: jal         0x80029394
    // 0x80029E68: nop

    func_80029394(rdram, ctx);
        goto after_0;
    // 0x80029E68: nop

    after_0:
    // 0x80029E6C: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x80029E70: lh          $a1, 0x32($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X32);
    // 0x80029E74: jal         0x800292B0
    // 0x80029E78: nop

    func_800292B0(rdram, ctx);
        goto after_1;
    // 0x80029E78: nop

    after_1:
    // 0x80029E7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80029E80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80029E84: jal         0x800291B4
    // 0x80029E88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800291B4(rdram, ctx);
        goto after_2;
    // 0x80029E88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80029E8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80029E90: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x80029E94: lh          $a2, 0x32($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X32);
    // 0x80029E98: jal         0x800293EC
    // 0x80029E9C: nop

    func_800293EC(rdram, ctx);
        goto after_3;
    // 0x80029E9C: nop

    after_3:
    // 0x80029EA0: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x80029EA4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80029EA8: nop

    // 0x80029EAC: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x80029EB0: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x80029EB4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80029EB8: nop

    // 0x80029EBC: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x80029EC0: b           L_80029EC8
    // 0x80029EC4: nop

        goto L_80029EC8;
    // 0x80029EC4: nop

L_80029EC8:
    // 0x80029EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029ECC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029ED0: jr          $ra
    // 0x80029ED4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80029ED4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C0A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0A40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C0A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0A48: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800C0A4C:
    // 0x800C0A4C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0A50: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800C0A54: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C0A58: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0A5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C0A60: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C0A64: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800C0A68: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C0A6C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C0A70: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800C0A74: lbu         $t8, -0x63C8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X63C8);
    // 0x800C0A78: nop

    // 0x800C0A7C: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800C0A80: beq         $t9, $zero, L_800C0B40
    if (ctx->r25 == 0) {
        // 0x800C0A84: nop
    
            goto L_800C0B40;
    }
    // 0x800C0A84: nop

    // 0x800C0A88: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x800C0A8C: beq         $t0, $zero, L_800C0B40
    if (ctx->r8 == 0) {
        // 0x800C0A90: nop
    
            goto L_800C0B40;
    }
    // 0x800C0A90: nop

    // 0x800C0A94: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0A98: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x800C0A9C: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800C0AA0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C0AA4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800C0AA8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800C0AAC: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800C0AB0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800C0AB4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800C0AB8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800C0ABC: lbu         $t3, -0x63C8($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X63C8);
    // 0x800C0AC0: nop

    // 0x800C0AC4: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x800C0AC8: beq         $t4, $zero, L_800C0ADC
    if (ctx->r12 == 0) {
        // 0x800C0ACC: nop
    
            goto L_800C0ADC;
    }
    // 0x800C0ACC: nop

    // 0x800C0AD0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0AD4: jal         0x800989BC
    // 0x800C0AD8: nop

    func_800989BC(rdram, ctx);
        goto after_0;
    // 0x800C0AD8: nop

    after_0:
L_800C0ADC:
    // 0x800C0ADC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0AE0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800C0AE4: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800C0AE8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C0AEC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C0AF0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800C0AF4: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800C0AF8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C0AFC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C0B00: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C0B04: sb          $zero, -0x63C8($at)
    MEM_B(-0X63C8, ctx->r1) = 0;
    // 0x800C0B08: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0B0C: ori         $at, $zero, 0x8100
    ctx->r1 = 0 | 0X8100;
    // 0x800C0B10: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x800C0B14: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800C0B18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C0B1C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800C0B20: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800C0B24: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800C0B28: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C0B2C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C0B30: addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // 0x800C0B34: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x800C0B38: jal         0x800CB840
    // 0x800C0B3C: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    osDestroyThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800C0B3C: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    after_1:
L_800C0B40:
    // 0x800C0B40: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0B44: nop

    // 0x800C0B48: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800C0B4C: slti        $at, $t2, 0xC
    ctx->r1 = SIGNED(ctx->r10) < 0XC ? 1 : 0;
    // 0x800C0B50: bne         $at, $zero, L_800C0A4C
    if (ctx->r1 != 0) {
        // 0x800C0B54: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_800C0A4C;
    }
    // 0x800C0B54: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800C0B58: b           L_800C0B60
    // 0x800C0B5C: nop

        goto L_800C0B60;
    // 0x800C0B5C: nop

L_800C0B60:
    // 0x800C0B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0B64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C0B68: jr          $ra
    // 0x800C0B6C: nop

    return;
    // 0x800C0B6C: nop

;}
RECOMP_FUNC void func_800A66DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A66DC: jr          $ra
    // 0x800A66E0: nop

    return;
    // 0x800A66E0: nop

    // 0x800A66E4: jr          $ra
    // 0x800A66E8: nop

    return;
    // 0x800A66E8: nop

;}
RECOMP_FUNC void func_8008B2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2FC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8008B300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B304: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8008B308: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8008B30C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8008B310: lhu         $t6, 0x5E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X5E);
    // 0x8008B314: nop

    // 0x8008B318: slti        $at, $t6, 0x4000
    ctx->r1 = SIGNED(ctx->r14) < 0X4000 ? 1 : 0;
    // 0x8008B31C: bne         $at, $zero, L_8008B33C
    if (ctx->r1 != 0) {
        // 0x8008B320: nop
    
            goto L_8008B33C;
    }
    // 0x8008B320: nop

    // 0x8008B324: jal         0x80090754
    // 0x8008B328: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090754(rdram, ctx);
        goto after_0;
    // 0x8008B328: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x8008B32C: jal         0x80090728
    // 0x8008B330: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090728(rdram, ctx);
        goto after_1;
    // 0x8008B330: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x8008B334: b           L_8008B34C
    // 0x8008B338: nop

        goto L_8008B34C;
    // 0x8008B338: nop

L_8008B33C:
    // 0x8008B33C: jal         0x80090754
    // 0x8008B340: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80090754(rdram, ctx);
        goto after_2;
    // 0x8008B340: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x8008B344: jal         0x80090728
    // 0x8008B348: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090728(rdram, ctx);
        goto after_3;
    // 0x8008B348: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_3:
L_8008B34C:
    // 0x8008B34C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8008B350: lhu         $a2, 0x5E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X5E);
    // 0x8008B354: jal         0x8008B388
    // 0x8008B358: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8008B388(rdram, ctx);
        goto after_4;
    // 0x8008B358: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x8008B35C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B360: lhu         $a1, 0x62($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X62);
    // 0x8008B364: addiu       $a0, $a0, -0xAB8
    ctx->r4 = ADD32(ctx->r4, -0XAB8);
    // 0x8008B368: jal         0x8008ECE4
    // 0x8008B36C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_8008ECE4(rdram, ctx);
        goto after_5;
    // 0x8008B36C: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x8008B370: b           L_8008B378
    // 0x8008B374: nop

        goto L_8008B378;
    // 0x8008B374: nop

L_8008B378:
    // 0x8008B378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B37C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8008B380: jr          $ra
    // 0x8008B384: nop

    return;
    // 0x8008B384: nop

;}
RECOMP_FUNC void func_800C0108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0108: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800C010C: lw          $t6, 0x484($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X484);
    // 0x800C0110: nop

    // 0x800C0114: bne         $t6, $zero, L_800C014C
    if (ctx->r14 != 0) {
        // 0x800C0118: nop
    
            goto L_800C014C;
    }
    // 0x800C0118: nop

    // 0x800C011C: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x800C0120: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800C0124: lw          $t0, 0x43C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X43C);
    // 0x800C0128: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800C012C: andi        $t9, $t8, 0xF0
    ctx->r25 = ctx->r24 & 0XF0;
    // 0x800C0130: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x800C0134: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800C0138: lw          $t1, 0x484($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X484);
    // 0x800C013C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0140: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800C0144: b           L_800C0184
    // 0x800C0148: sw          $t2, 0x484($at)
    MEM_W(0X484, ctx->r1) = ctx->r10;
        goto L_800C0184;
    // 0x800C0148: sw          $t2, 0x484($at)
    MEM_W(0X484, ctx->r1) = ctx->r10;
L_800C014C:
    // 0x800C014C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x800C0150: lw          $t3, 0x43C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X43C);
    // 0x800C0154: andi        $t5, $a0, 0xFF
    ctx->r13 = ctx->r4 & 0XFF;
    // 0x800C0158: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800C015C: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x800C0160: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800C0164: sb          $t7, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r15;
    // 0x800C0168: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800C016C: lw          $t8, 0x43C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X43C);
    // 0x800C0170: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0174: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C0178: sw          $t9, 0x43C($at)
    MEM_W(0X43C, ctx->r1) = ctx->r25;
    // 0x800C017C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800C0180: sw          $zero, 0x484($at)
    MEM_W(0X484, ctx->r1) = 0;
L_800C0184:
    // 0x800C0184: jr          $ra
    // 0x800C0188: nop

    return;
    // 0x800C0188: nop

    // 0x800C018C: jr          $ra
    // 0x800C0190: nop

    return;
    // 0x800C0190: nop

;}
RECOMP_FUNC void func_800717F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800717F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800717F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800717FC: jal         0x80061348
    // 0x80071800: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071800: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071804: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071808: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007180C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071810: beq         $v0, $zero, L_80071864
    if (ctx->r2 == 0) {
        // 0x80071814: nop
    
            goto L_80071864;
    }
    // 0x80071814: nop

    // 0x80071818: jal         0x80061348
    // 0x8007181C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007181C: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x80071820: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071824: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071828: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007182C: beq         $v0, $zero, L_80071864
    if (ctx->r2 == 0) {
        // 0x80071830: nop
    
            goto L_80071864;
    }
    // 0x80071830: nop

    // 0x80071834: jal         0x80061348
    // 0x80071838: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071838: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x8007183C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80071840: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071844: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071848: beq         $v0, $zero, L_80071864
    if (ctx->r2 == 0) {
        // 0x8007184C: nop
    
            goto L_80071864;
    }
    // 0x8007184C: nop

    // 0x80071850: jal         0x80061348
    // 0x80071854: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071854: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x80071858: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007185C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80071860: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071864:
    // 0x80071864: b           L_80071874
    // 0x80071868: nop

        goto L_80071874;
    // 0x80071868: nop

    // 0x8007186C: b           L_80071874
    // 0x80071870: nop

        goto L_80071874;
    // 0x80071870: nop

L_80071874:
    // 0x80071874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007187C: jr          $ra
    // 0x80071880: nop

    return;
    // 0x80071880: nop

;}
RECOMP_FUNC void func_8006BEB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BEB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BEB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BEB8: jal         0x8005F064
    // 0x8006BEBC: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006BEBC: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    after_0:
    // 0x8006BEC0: b           L_8006BED0
    // 0x8006BEC4: nop

        goto L_8006BED0;
    // 0x8006BEC4: nop

    // 0x8006BEC8: b           L_8006BED0
    // 0x8006BECC: nop

        goto L_8006BED0;
    // 0x8006BECC: nop

L_8006BED0:
    // 0x8006BED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BED8: jr          $ra
    // 0x8006BEDC: nop

    return;
    // 0x8006BEDC: nop

;}
RECOMP_FUNC void func_8000B7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B7A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000B7A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000B7A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000B7AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000B7B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000B7B4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000B7B8: lw          $t7, 0x1A0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A0);
    // 0x8000B7BC: nop

    // 0x8000B7C0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8000B7C4: sw          $t8, 0x1A0($t6)
    MEM_W(0X1A0, ctx->r14) = ctx->r24;
    // 0x8000B7C8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8000B7CC: nop

    // 0x8000B7D0: lw          $a0, 0x1A4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1A4);
    // 0x8000B7D4: jal         0x800045AC
    // 0x8000B7D8: nop

    func_800045AC(rdram, ctx);
        goto after_0;
    // 0x8000B7D8: nop

    after_0:
    // 0x8000B7DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8000B7E0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B7E4: nop

    // 0x8000B7E8: beq         $t0, $zero, L_8000B7FC
    if (ctx->r8 == 0) {
        // 0x8000B7EC: nop
    
            goto L_8000B7FC;
    }
    // 0x8000B7EC: nop

    // 0x8000B7F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B7F4: b           L_8000B820
    // 0x8000B7F8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
        goto L_8000B820;
    // 0x8000B7F8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_8000B7FC:
    // 0x8000B7FC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000B800: nop

    // 0x8000B804: lw          $t3, 0x1A0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A0);
    // 0x8000B808: nop

    // 0x8000B80C: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x8000B810: sw          $t4, 0x1A0($t2)
    MEM_W(0X1A0, ctx->r10) = ctx->r12;
    // 0x8000B814: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8000B818: nop

    // 0x8000B81C: sw          $zero, 0x1A8($t5)
    MEM_W(0X1A8, ctx->r13) = 0;
L_8000B820:
    // 0x8000B820: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000B824: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8000B828: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000B82C: bne         $t7, $at, L_8000B83C
    if (ctx->r15 != ctx->r1) {
        // 0x8000B830: nop
    
            goto L_8000B83C;
    }
    // 0x8000B830: nop

    // 0x8000B834: b           L_8000BAF0
    // 0x8000B838: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000BAF0;
    // 0x8000B838: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000B83C:
    // 0x8000B83C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000B840: lw          $t8, -0x2828($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2828);
    // 0x8000B844: nop

    // 0x8000B848: bne         $t8, $zero, L_8000B994
    if (ctx->r24 != 0) {
        // 0x8000B84C: nop
    
            goto L_8000B994;
    }
    // 0x8000B84C: nop

    // 0x8000B850: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8000B854: jal         0x800BC918
    // 0x8000B858: ori         $a0, $a0, 0x5000
    ctx->r4 = ctx->r4 | 0X5000;
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_1;
    // 0x8000B858: ori         $a0, $a0, 0x5000
    ctx->r4 = ctx->r4 | 0X5000;
    after_1:
    // 0x8000B85C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000B860: sw          $v0, -0x2828($at)
    MEM_W(-0X2828, ctx->r1) = ctx->r2;
    // 0x8000B864: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B868: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
    // 0x8000B86C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B870: sw          $zero, 0x3070($at)
    MEM_W(0X3070, ctx->r1) = 0;
    // 0x8000B874: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B878: sw          $zero, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = 0;
    // 0x8000B87C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B880: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B884: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000B888: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000B88C: lui         $a2, 0x8098
    ctx->r6 = S32(0X8098 << 16);
    // 0x8000B890: jal         0x800BD1FC
    // 0x8000B894: addiu       $a2, $a2, 0x1A00
    ctx->r6 = ADD32(ctx->r6, 0X1A00);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8000B894: addiu       $a2, $a2, 0x1A00
    ctx->r6 = ADD32(ctx->r6, 0X1A00);
    after_2:
    // 0x8000B898: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B89C: jal         0x800BED70
    // 0x8000B8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Spi_GetHeader(rdram, ctx);
        goto after_3;
    // 0x8000B8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000B8A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8000B8A8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000B8AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B8B0: beq         $t6, $at, L_8000B904
    if (ctx->r14 == ctx->r1) {
        // 0x8000B8B4: nop
    
            goto L_8000B904;
    }
    // 0x8000B8B4: nop

    // 0x8000B8B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000B8BC: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x8000B8C0: jal         0x800BC918
    // 0x8000B8C4: nop

    SysMem_HeapAllocMark(rdram, ctx);
        goto after_4;
    // 0x8000B8C4: nop

    after_4:
    // 0x8000B8C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B8CC: sw          $v0, 0x3070($at)
    MEM_W(0X3070, ctx->r1) = ctx->r2;
    // 0x8000B8D0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B8D4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B8D8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000B8DC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000B8E0: lui         $a2, 0x8098
    ctx->r6 = S32(0X8098 << 16);
    // 0x8000B8E4: jal         0x800BD1FC
    // 0x8000B8E8: addiu       $a2, $a2, 0x1A00
    ctx->r6 = ADD32(ctx->r6, 0X1A00);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8000B8E8: addiu       $a2, $a2, 0x1A00
    ctx->r6 = ADD32(ctx->r6, 0X1A00);
    after_5:
    // 0x8000B8EC: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8000B8F0: lw          $a2, 0x3070($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3070);
    // 0x8000B8F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B8F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8000B8FC: jal         0x800BF0B4
    // 0x8000B900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Spi_DecompressAsset(rdram, ctx);
        goto after_6;
    // 0x8000B900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_8000B904:
    // 0x8000B904: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B908: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B90C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000B910: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000B914: lui         $a2, 0x8099
    ctx->r6 = S32(0X8099 << 16);
    // 0x8000B918: jal         0x800BD1FC
    // 0x8000B91C: addiu       $a2, $a2, 0x6A20
    ctx->r6 = ADD32(ctx->r6, 0X6A20);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_7;
    // 0x8000B91C: addiu       $a2, $a2, 0x6A20
    ctx->r6 = ADD32(ctx->r6, 0X6A20);
    after_7:
    // 0x8000B920: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B924: jal         0x800BED70
    // 0x8000B928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Spi_GetHeader(rdram, ctx);
        goto after_8;
    // 0x8000B928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8000B92C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8000B930: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000B934: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B938: beq         $t9, $at, L_8000B98C
    if (ctx->r25 == ctx->r1) {
        // 0x8000B93C: nop
    
            goto L_8000B98C;
    }
    // 0x8000B93C: nop

    // 0x8000B940: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000B944: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x8000B948: jal         0x800BC918
    // 0x8000B94C: nop

    SysMem_HeapAllocMark(rdram, ctx);
        goto after_9;
    // 0x8000B94C: nop

    after_9:
    // 0x8000B950: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B954: sw          $v0, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = ctx->r2;
    // 0x8000B958: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B95C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B960: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000B964: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000B968: lui         $a2, 0x8099
    ctx->r6 = S32(0X8099 << 16);
    // 0x8000B96C: jal         0x800BD1FC
    // 0x8000B970: addiu       $a2, $a2, 0x6A20
    ctx->r6 = ADD32(ctx->r6, 0X6A20);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_10;
    // 0x8000B970: addiu       $a2, $a2, 0x6A20
    ctx->r6 = ADD32(ctx->r6, 0X6A20);
    after_10:
    // 0x8000B974: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8000B978: lw          $a2, 0x3078($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3078);
    // 0x8000B97C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B980: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8000B984: jal         0x800BF0B4
    // 0x8000B988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Spi_DecompressAsset(rdram, ctx);
        goto after_11;
    // 0x8000B988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_8000B98C:
    // 0x8000B98C: b           L_8000BA08
    // 0x8000B990: nop

        goto L_8000BA08;
    // 0x8000B990: nop

L_8000B994:
    // 0x8000B994: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000B998: nop

    // 0x8000B99C: lw          $t1, 0x20C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20C);
    // 0x8000B9A0: nop

    // 0x8000B9A4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8000B9A8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8000B9AC: nop

    // 0x8000B9B0: beq         $t3, $zero, L_8000BA08
    if (ctx->r11 == 0) {
        // 0x8000B9B4: nop
    
            goto L_8000BA08;
    }
    // 0x8000B9B4: nop

    // 0x8000B9B8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8000B9BC: nop

    // 0x8000B9C0: beq         $t4, $zero, L_8000BA08
    if (ctx->r12 == 0) {
        // 0x8000B9C4: nop
    
            goto L_8000BA08;
    }
    // 0x8000B9C4: nop

    // 0x8000B9C8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000B9CC: lw          $a0, 0x3068($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3068);
    // 0x8000B9D0: jal         0x8000D390
    // 0x8000B9D4: nop

    TempHeap_Free(rdram, ctx);
        goto after_12;
    // 0x8000B9D4: nop

    after_12:
    // 0x8000B9D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B9DC: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
    // 0x8000B9E0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000B9E4: nop

    // 0x8000B9E8: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8000B9EC: nop

    // 0x8000B9F0: sw          $zero, 0x1A8($t5)
    MEM_W(0X1A8, ctx->r13) = 0;
    // 0x8000B9F4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000B9F8: nop

    // 0x8000B9FC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000BA00: nop

    // 0x8000BA04: sw          $zero, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = 0;
L_8000BA08:
    // 0x8000BA08: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000BA0C: lw          $a0, -0x2828($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2828);
    // 0x8000BA10: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8000BA14: jal         0x8000D0E0
    // 0x8000BA18: ori         $a1, $a1, 0x5000
    ctx->r5 = ctx->r5 | 0X5000;
    TempHeap_Init(rdram, ctx);
        goto after_13;
    // 0x8000BA18: ori         $a1, $a1, 0x5000
    ctx->r5 = ctx->r5 | 0X5000;
    after_13:
    // 0x8000BA1C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8000BA20:
    // 0x8000BA20: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000BA24: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000BA28: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8000BA2C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8000BA30: sw          $zero, -0x7E8($at)
    MEM_W(-0X7E8, ctx->r1) = 0;
    // 0x8000BA34: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000BA38: nop

    // 0x8000BA3C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000BA40: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x8000BA44: bne         $at, $zero, L_8000BA20
    if (ctx->r1 != 0) {
        // 0x8000BA48: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_8000BA20;
    }
    // 0x8000BA48: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8000BA4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000BA50: sw          $zero, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = 0;
    // 0x8000BA54: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8000BA58: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8000BA5C: sw          $t3, 0x1A0($t4)
    MEM_W(0X1A0, ctx->r12) = ctx->r11;
    // 0x8000BA60: jal         0x8000D164
    // 0x8000BA64: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    TempHeap_Alloc(rdram, ctx);
        goto after_14;
    // 0x8000BA64: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_14:
    // 0x8000BA68: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000BA6C: nop

    // 0x8000BA70: sw          $v0, 0x20C($t2)
    MEM_W(0X20C, ctx->r10) = ctx->r2;
    // 0x8000BA74: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8000BA78: nop

    // 0x8000BA7C: lw          $t7, 0x20C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X20C);
    // 0x8000BA80: nop

    // 0x8000BA84: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8000BA88: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8000BA8C: nop

    // 0x8000BA90: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8000BA94: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000BA98: nop

    // 0x8000BA9C: sh          $zero, 0x14($t6)
    MEM_H(0X14, ctx->r14) = 0;
    // 0x8000BAA0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000BAA4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000BAA8: sh          $t9, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r25;
    // 0x8000BAAC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8000BAB0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8000BAB4: sh          $t1, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r9;
    // 0x8000BAB8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000BABC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000BAC0: lhu         $t2, 0x0($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X0);
    // 0x8000BAC4: nop

    // 0x8000BAC8: ori         $t5, $t2, 0x200
    ctx->r13 = ctx->r10 | 0X200;
    // 0x8000BACC: sh          $t5, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r13;
    // 0x8000BAD0: jal         0x8005F268
    // 0x8000BAD4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_8005F268(rdram, ctx);
        goto after_15;
    // 0x8000BAD4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_15:
    // 0x8000BAD8: jal         0x80059D48
    // 0x8000BADC: nop

    func_80059D48(rdram, ctx);
        goto after_16;
    // 0x8000BADC: nop

    after_16:
    // 0x8000BAE0: b           L_8000BAF0
    // 0x8000BAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000BAF0;
    // 0x8000BAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000BAE8: b           L_8000BAF0
    // 0x8000BAEC: nop

        goto L_8000BAF0;
    // 0x8000BAEC: nop

L_8000BAF0:
    // 0x8000BAF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BAF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000BAF8: jr          $ra
    // 0x8000BAFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000BAFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006C300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C308: jal         0x8005F064
    // 0x8006C30C: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C30C: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    after_0:
    // 0x8006C310: b           L_8006C320
    // 0x8006C314: nop

        goto L_8006C320;
    // 0x8006C314: nop

    // 0x8006C318: b           L_8006C320
    // 0x8006C31C: nop

        goto L_8006C320;
    // 0x8006C31C: nop

L_8006C320:
    // 0x8006C320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C328: jr          $ra
    // 0x8006C32C: nop

    return;
    // 0x8006C32C: nop

;}
RECOMP_FUNC void func_80029204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029204: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80029208: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002920C: sh          $t6, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r14;
L_80029210:
    // 0x80029210: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x80029214: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80029218: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002921C: lbu         $t8, -0x6550($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X6550);
    // 0x80029220: nop

    // 0x80029224: bne         $t8, $zero, L_80029234
    if (ctx->r24 != 0) {
        // 0x80029228: nop
    
            goto L_80029234;
    }
    // 0x80029228: nop

    // 0x8002922C: b           L_80029254
    // 0x80029230: nop

        goto L_80029254;
    // 0x80029230: nop

L_80029234:
    // 0x80029234: lh          $t9, 0x6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6);
    // 0x80029238: nop

    // 0x8002923C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80029240: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80029244: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80029248: slti        $at, $t2, 0x46
    ctx->r1 = SIGNED(ctx->r10) < 0X46 ? 1 : 0;
    // 0x8002924C: bne         $at, $zero, L_80029210
    if (ctx->r1 != 0) {
        // 0x80029250: sh          $t0, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r8;
            goto L_80029210;
    }
    // 0x80029250: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
L_80029254:
    // 0x80029254: lh          $t3, 0x6($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X6);
    // 0x80029258: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x8002925C: bne         $t3, $at, L_8002926C
    if (ctx->r11 != ctx->r1) {
        // 0x80029260: nop
    
            goto L_8002926C;
    }
    // 0x80029260: nop

    // 0x80029264: b           L_800292A8
    // 0x80029268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800292A8;
    // 0x80029268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002926C:
    // 0x8002926C: lh          $t5, 0x6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6);
    // 0x80029270: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029274: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80029278: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8002927C: sb          $t4, -0x6550($at)
    MEM_B(-0X6550, ctx->r1) = ctx->r12;
    // 0x80029280: lh          $t6, 0x6($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6);
    // 0x80029284: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80029288: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002928C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80029290: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80029294: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x80029298: b           L_800292A8
    // 0x8002929C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
        goto L_800292A8;
    // 0x8002929C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800292A0: b           L_800292A8
    // 0x800292A4: nop

        goto L_800292A8;
    // 0x800292A4: nop

L_800292A8:
    // 0x800292A8: jr          $ra
    // 0x800292AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800292AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006373C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006373C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063740: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063744: nop

    // 0x80063748: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x8006374C: nop

    // 0x80063750: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80063754: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063758: jr          $ra
    // 0x8006375C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006375C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063760: jr          $ra
    // 0x80063764: nop

    return;
    // 0x80063764: nop

    // 0x80063768: jr          $ra
    // 0x8006376C: nop

    return;
    // 0x8006376C: nop

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
RECOMP_FUNC void func_80046980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046980: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80046984: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80046988: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8004698C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80046990: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80046994: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80046998: jal         0x800AF060
    // 0x8004699C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800AF060(rdram, ctx);
        goto after_0;
    // 0x8004699C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x800469A0: jal         0x800A41B4
    // 0x800469A4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    func_800A41B4(rdram, ctx);
        goto after_1;
    // 0x800469A4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_1:
    // 0x800469A8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800469AC: addiu       $a1, $a1, -0x3FD0
    ctx->r5 = ADD32(ctx->r5, -0X3FD0);
    // 0x800469B0: jal         0x800A5624
    // 0x800469B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A5624(rdram, ctx);
        goto after_2;
    // 0x800469B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800469B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800469BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800469C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800469C4: swc1        $f4, 0x450($at)
    MEM_W(0X450, ctx->r1) = ctx->f4.u32l;
    // 0x800469C8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800469CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800469D0: sw          $t6, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r14;
    // 0x800469D4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800469D8: lh          $t7, 0x7268($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7268);
    // 0x800469DC: nop

    // 0x800469E0: andi        $t8, $t7, 0x7FFF
    ctx->r24 = ctx->r15 & 0X7FFF;
    // 0x800469E4: sh          $t8, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r24;
    // 0x800469E8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800469EC: lh          $t9, 0x7268($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7268);
    // 0x800469F0: nop

    // 0x800469F4: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x800469F8: bgez        $t0, L_80046A08
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800469FC: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80046A08;
    }
    // 0x800469FC: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80046A00: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x80046A04: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80046A08:
    // 0x80046A08: sh          $t1, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r9;
    // 0x80046A0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046A10: sh          $zero, 0x728E($at)
    MEM_H(0X728E, ctx->r1) = 0;
    // 0x80046A14: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
L_80046A18:
    // 0x80046A18: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80046A1C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80046A20: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80046A24: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80046A28: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80046A2C: lw          $t4, -0x73D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73D0);
    // 0x80046A30: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80046A34: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80046A38: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80046A3C: lw          $t6, 0xC0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC0);
    // 0x80046A40: nop

    // 0x80046A44: ori         $t7, $t6, 0x8240
    ctx->r15 = ctx->r14 | 0X8240;
    // 0x80046A48: sw          $t7, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r15;
    // 0x80046A4C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80046A50: nop

    // 0x80046A54: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80046A58: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80046A5C: bne         $at, $zero, L_80046A18
    if (ctx->r1 != 0) {
        // 0x80046A60: sw          $t9, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r25;
            goto L_80046A18;
    }
    // 0x80046A60: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80046A64: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
L_80046A68:
    // 0x80046A68: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80046A6C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80046A70: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80046A74: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80046A78: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80046A7C: lw          $t2, 0x263C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X263C);
    // 0x80046A80: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80046A84: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80046A88: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80046A8C: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x80046A90: nop

    // 0x80046A94: ori         $t6, $t4, 0x8240
    ctx->r14 = ctx->r12 | 0X8240;
    // 0x80046A98: sw          $t6, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r14;
    // 0x80046A9C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80046AA0: nop

    // 0x80046AA4: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x80046AA8: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80046AAC: bne         $at, $zero, L_80046A68
    if (ctx->r1 != 0) {
        // 0x80046AB0: sw          $t5, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r13;
            goto L_80046A68;
    }
    // 0x80046AB0: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x80046AB4: jal         0x800BC6EC
    // 0x80046AB8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80046AB8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
    // 0x80046ABC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046AC0: sw          $v0, 0x71FC($at)
    MEM_W(0X71FC, ctx->r1) = ctx->r2;
    // 0x80046AC4: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80046AC8: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80046ACC: jal         0x800BC6EC
    // 0x80046AD0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x80046AD0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_4:
    // 0x80046AD4: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80046AD8: lw          $t9, 0x71FC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X71FC);
    // 0x80046ADC: nop

    // 0x80046AE0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80046AE4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80046AE8: lw          $t0, 0x71FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X71FC);
    // 0x80046AEC: nop

    // 0x80046AF0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80046AF4: nop

    // 0x80046AF8: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80046AFC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80046B00: lw          $t2, 0x71FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71FC);
    // 0x80046B04: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80046B08: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80046B0C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80046B10: addiu       $a0, $t4, 0x1
    ctx->r4 = ADD32(ctx->r12, 0X1);
    // 0x80046B14: jal         0x800BCFCC
    // 0x80046B18: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x80046B18: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_5:
    // 0x80046B1C: lhu         $t6, 0x64($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X64);
    // 0x80046B20: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80046B24: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80046B28: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80046B2C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80046B30: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80046B34: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80046B38: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80046B3C: lw          $a2, -0x3D4C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3D4C);
    // 0x80046B40: jal         0x800BD1FC
    // 0x80046B44: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x80046B44: nop

    after_6:
    // 0x80046B48: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80046B4C: lw          $t7, 0x71FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X71FC);
    // 0x80046B50: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80046B54: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80046B58: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80046B5C: jal         0x800BD218
    // 0x80046B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_7;
    // 0x80046B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80046B64: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x80046B68: lw          $a3, 0x71FC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X71FC);
    // 0x80046B6C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80046B70: addiu       $a2, $a2, -0x3D2C
    ctx->r6 = ADD32(ctx->r6, -0X3D2C);
    // 0x80046B74: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80046B78: jal         0x80043F14
    // 0x80046B7C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80043F14(rdram, ctx);
        goto after_8;
    // 0x80046B7C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x80046B80: lui         $a0, 0x80A4
    ctx->r4 = S32(0X80A4 << 16);
    // 0x80046B84: jal         0x800AF92C
    // 0x80046B88: addiu       $a0, $a0, -0x412C
    ctx->r4 = ADD32(ctx->r4, -0X412C);
    func_800AF92C(rdram, ctx);
        goto after_9;
    // 0x80046B88: addiu       $a0, $a0, -0x412C
    ctx->r4 = ADD32(ctx->r4, -0X412C);
    after_9:
    // 0x80046B8C: lui         $a0, 0x80A3
    ctx->r4 = S32(0X80A3 << 16);
    // 0x80046B90: jal         0x800AF72C
    // 0x80046B94: addiu       $a0, $a0, 0x67D0
    ctx->r4 = ADD32(ctx->r4, 0X67D0);
    func_800AF72C(rdram, ctx);
        goto after_10;
    // 0x80046B94: addiu       $a0, $a0, 0x67D0
    ctx->r4 = ADD32(ctx->r4, 0X67D0);
    after_10:
    // 0x80046B98: jal         0x800BC6EC
    // 0x80046B9C: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x80046B9C: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_11:
    // 0x80046BA0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80046BA4: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80046BA8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046BAC: sw          $t5, -0x73B8($at)
    MEM_W(-0X73B8, ctx->r1) = ctx->r13;
    // 0x80046BB0: jal         0x800BC6EC
    // 0x80046BB4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_12;
    // 0x80046BB4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_12:
    // 0x80046BB8: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80046BBC: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80046BC0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046BC4: sw          $t8, -0x73B4($at)
    MEM_W(-0X73B4, ctx->r1) = ctx->r24;
    // 0x80046BC8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80046BCC: jal         0x80099E2C
    // 0x80046BD0: nop

    func_80099E2C(rdram, ctx);
        goto after_13;
    // 0x80046BD0: nop

    after_13:
    // 0x80046BD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046BD8: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80046BDC: nop

    // 0x80046BE0: swc1        $f6, 0xD4($t9)
    MEM_W(0XD4, ctx->r25) = ctx->f6.u32l;
    // 0x80046BE4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80046BE8: lui         $t0, 0x4
    ctx->r8 = S32(0X4 << 16);
    // 0x80046BEC: ori         $t0, $t0, 0x4
    ctx->r8 = ctx->r8 | 0X4;
    // 0x80046BF0: sw          $t0, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r8;
    // 0x80046BF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80046BF8: lwc1        $f8, -0x1140($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1140);
    // 0x80046BFC: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80046C00: nop

    // 0x80046C04: swc1        $f8, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->f8.u32l;
    // 0x80046C08: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80046C0C: nop

    // 0x80046C10: sw          $zero, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = 0;
    // 0x80046C14: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80046C18: nop

    // 0x80046C1C: sw          $zero, 0x140($t6)
    MEM_W(0X140, ctx->r14) = 0;
    // 0x80046C20: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80046C24: nop

    // 0x80046C28: lw          $t7, 0x140($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X140);
    // 0x80046C2C: nop

    // 0x80046C30: sw          $t7, 0x13C($t3)
    MEM_W(0X13C, ctx->r11) = ctx->r15;
    // 0x80046C34: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80046C38: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80046C3C: sh          $t5, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r13;
    // 0x80046C40: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80046C44: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80046C48: jal         0x800B1B04
    // 0x80046C4C: nop

    func_800B1B04(rdram, ctx);
        goto after_14;
    // 0x80046C4C: nop

    after_14:
    // 0x80046C50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80046C54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80046C58: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80046C5C: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80046C60: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80046C64: ori         $a2, $a2, 0x27
    ctx->r6 = ctx->r6 | 0X27;
    // 0x80046C68: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80046C6C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80046C70: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80046C74: jal         0x800B1F0C
    // 0x80046C78: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_15;
    // 0x80046C78: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x80046C7C: addiu       $t9, $zero, 0x27
    ctx->r25 = ADD32(0, 0X27);
    // 0x80046C80: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046C84: sh          $t9, 0x70E0($at)
    MEM_H(0X70E0, ctx->r1) = ctx->r25;
    // 0x80046C88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046C8C: sh          $zero, -0x73C8($at)
    MEM_H(-0X73C8, ctx->r1) = 0;
    // 0x80046C90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80046C94: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
    // 0x80046C98: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80046C9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046CA0: swc1        $f18, 0x50D8($at)
    MEM_W(0X50D8, ctx->r1) = ctx->f18.u32l;
    // 0x80046CA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046CA8: swc1        $f18, 0x50D0($at)
    MEM_W(0X50D0, ctx->r1) = ctx->f18.u32l;
    // 0x80046CAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80046CB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046CB4: swc1        $f4, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = ctx->f4.u32l;
    // 0x80046CB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046CBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046CC0: swc1        $f6, 0x733C($at)
    MEM_W(0X733C, ctx->r1) = ctx->f6.u32l;
    // 0x80046CC4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80046CC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046CCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046CD0: swc1        $f8, -0x73E0($at)
    MEM_W(-0X73E0, ctx->r1) = ctx->f8.u32l;
    // 0x80046CD4: lhu         $t0, 0x66($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X66);
    // 0x80046CD8: nop

    // 0x80046CDC: bne         $t0, $zero, L_80046D10
    if (ctx->r8 != 0) {
        // 0x80046CE0: nop
    
            goto L_80046D10;
    }
    // 0x80046CE0: nop

    // 0x80046CE4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80046CE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046CEC: swc1        $f10, 0x7324($at)
    MEM_W(0X7324, ctx->r1) = ctx->f10.u32l;
    // 0x80046CF0: lui         $at, 0x43EB
    ctx->r1 = S32(0X43EB << 16);
    // 0x80046CF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80046CF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046CFC: swc1        $f16, -0x73EC($at)
    MEM_W(-0X73EC, ctx->r1) = ctx->f16.u32l;
    // 0x80046D00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80046D04: lwc1        $f18, -0x113C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X113C);
    // 0x80046D08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046D0C: swc1        $f18, -0x73D4($at)
    MEM_W(-0X73D4, ctx->r1) = ctx->f18.u32l;
L_80046D10:
    // 0x80046D10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80046D14: lwc1        $f4, -0x1138($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1138);
    // 0x80046D18: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80046D1C: swc1        $f4, -0x76B8($at)
    MEM_W(-0X76B8, ctx->r1) = ctx->f4.u32l;
    // 0x80046D20: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046D24: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80046D28: addiu       $t1, $t1, 0x7158
    ctx->r9 = ADD32(ctx->r9, 0X7158);
    // 0x80046D2C: swc1        $f6, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f6.u32l;
    // 0x80046D30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046D34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046D38: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80046D3C: addiu       $t2, $t2, 0x7158
    ctx->r10 = ADD32(ctx->r10, 0X7158);
    // 0x80046D40: swc1        $f8, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f8.u32l;
    // 0x80046D44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80046D48: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80046D4C: addiu       $t4, $t4, 0x7158
    ctx->r12 = ADD32(ctx->r12, 0X7158);
    // 0x80046D50: swc1        $f10, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f10.u32l;
    // 0x80046D54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046D58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80046D5C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80046D60: addiu       $t6, $t6, 0x7158
    ctx->r14 = ADD32(ctx->r14, 0X7158);
    // 0x80046D64: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80046D68: addiu       $t7, $t7, 0x7158
    ctx->r15 = ADD32(ctx->r15, 0X7158);
    // 0x80046D6C: swc1        $f16, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f16.u32l;
    // 0x80046D70: lwc1        $f20, 0x20($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80046D74: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80046D78: addiu       $t3, $t3, 0x7158
    ctx->r11 = ADD32(ctx->r11, 0X7158);
    // 0x80046D7C: swc1        $f20, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f20.u32l;
    // 0x80046D80: swc1        $f20, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f20.u32l;
    // 0x80046D84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046D88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80046D8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046D90: swc1        $f18, 0x720C($at)
    MEM_W(0X720C, ctx->r1) = ctx->f18.u32l;
    // 0x80046D94: lhu         $t5, 0x66($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X66);
    // 0x80046D98: nop

    // 0x80046D9C: bne         $t5, $zero, L_80046DBC
    if (ctx->r13 != 0) {
        // 0x80046DA0: nop
    
            goto L_80046DBC;
    }
    // 0x80046DA0: nop

    // 0x80046DA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80046DA8: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80046DAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80046DB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046DB4: b           L_80046DD8
    // 0x80046DB8: swc1        $f4, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f4.u32l;
        goto L_80046DD8;
    // 0x80046DB8: swc1        $f4, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f4.u32l;
L_80046DBC:
    // 0x80046DBC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80046DC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80046DC4: sh          $t8, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r24;
    // 0x80046DC8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80046DCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046DD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046DD4: swc1        $f6, 0x50C8($at)
    MEM_W(0X50C8, ctx->r1) = ctx->f6.u32l;
L_80046DD8:
    // 0x80046DD8: lhu         $t9, 0x64($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X64);
    // 0x80046DDC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80046DE0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80046DE4: lbu         $t0, -0x3C60($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X3C60);
    // 0x80046DE8: nop

    // 0x80046DEC: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80046DF0: lhu         $t1, 0x64($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X64);
    // 0x80046DF4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80046DF8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80046DFC: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80046E00: lw          $t4, -0x3C58($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3C58);
    // 0x80046E04: nop

    // 0x80046E08: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x80046E0C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80046E10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80046E14: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80046E18: blez        $t7, L_80046E7C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80046E1C: sw          $zero, 0x70($sp)
        MEM_W(0X70, ctx->r29) = 0;
            goto L_80046E7C;
    }
    // 0x80046E1C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
L_80046E20:
    // 0x80046E20: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80046E24: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80046E28: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    // 0x80046E2C: lhu         $a1, 0x2($t3)
    ctx->r5 = MEM_HU(ctx->r11, 0X2);
    // 0x80046E30: lhu         $a2, 0x4($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X4);
    // 0x80046E34: lhu         $a3, 0x6($t3)
    ctx->r7 = MEM_HU(ctx->r11, 0X6);
    // 0x80046E38: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x80046E3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80046E40: jal         0x80044248
    // 0x80046E44: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_80044248(rdram, ctx);
        goto after_16;
    // 0x80046E44: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_16:
    // 0x80046E48: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80046E4C: nop

    // 0x80046E50: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80046E54: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x80046E58: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80046E5C: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80046E60: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80046E64: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80046E68: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80046E6C: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80046E70: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x80046E74: bne         $at, $zero, L_80046E20
    if (ctx->r1 != 0) {
        // 0x80046E78: sw          $t6, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r14;
            goto L_80046E20;
    }
    // 0x80046E78: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_80046E7C:
    // 0x80046E7C: lhu         $t3, 0x66($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X66);
    // 0x80046E80: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80046E84: bne         $t3, $at, L_80046EB0
    if (ctx->r11 != ctx->r1) {
        // 0x80046E88: nop
    
            goto L_80046EB0;
    }
    // 0x80046E88: nop

    // 0x80046E8C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80046E90: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x80046E94: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80046E98: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80046E9C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80046EA0: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    // 0x80046EA4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80046EA8: jal         0x80044248
    // 0x80046EAC: addiu       $a3, $zero, 0x94
    ctx->r7 = ADD32(0, 0X94);
    func_80044248(rdram, ctx);
        goto after_17;
    // 0x80046EAC: addiu       $a3, $zero, 0x94
    ctx->r7 = ADD32(0, 0X94);
    after_17:
L_80046EB0:
    // 0x80046EB0: lhu         $t9, 0x64($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X64);
    // 0x80046EB4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80046EB8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80046EBC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80046EC0: lw          $t1, -0x3C00($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3C00);
    // 0x80046EC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046EC8: sw          $t1, 0x7214($at)
    MEM_W(0X7214, ctx->r1) = ctx->r9;
    // 0x80046ECC: jal         0x800BC6EC
    // 0x80046ED0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_18;
    // 0x80046ED0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_18:
    // 0x80046ED4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80046ED8: sw          $v0, 0x722C($at)
    MEM_W(0X722C, ctx->r1) = ctx->r2;
    // 0x80046EDC: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80046EE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80046EE4: jal         0x800AFB70
    // 0x80046EE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_19;
    // 0x80046EE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80046EEC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80046EF0: lw          $t2, 0x722C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X722C);
    // 0x80046EF4: nop

    // 0x80046EF8: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x80046EFC: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x80046F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80046F04: jal         0x800AFB70
    // 0x80046F08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_20;
    // 0x80046F08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80046F0C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80046F10: lw          $t4, 0x722C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X722C);
    // 0x80046F14: nop

    // 0x80046F18: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80046F1C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x80046F20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80046F24: jal         0x800AFB70
    // 0x80046F28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_21;
    // 0x80046F28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x80046F2C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80046F30: lw          $t6, 0x722C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X722C);
    // 0x80046F34: nop

    // 0x80046F38: sw          $v0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r2;
    // 0x80046F3C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x80046F40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80046F44: jal         0x800AFB70
    // 0x80046F48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_22;
    // 0x80046F48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x80046F4C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80046F50: lw          $t7, 0x722C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X722C);
    // 0x80046F54: nop

    // 0x80046F58: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
    // 0x80046F5C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x80046F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80046F64: jal         0x800AFB70
    // 0x80046F68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_23;
    // 0x80046F68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80046F6C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80046F70: lw          $t3, 0x722C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X722C);
    // 0x80046F74: nop

    // 0x80046F78: sw          $v0, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r2;
    // 0x80046F7C: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x80046F80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80046F84: jal         0x800AFB70
    // 0x80046F88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_24;
    // 0x80046F88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x80046F8C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80046F90: lw          $t5, 0x722C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X722C);
    // 0x80046F94: nop

    // 0x80046F98: sw          $v0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r2;
    // 0x80046F9C: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x80046FA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80046FA4: jal         0x800AFB70
    // 0x80046FA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_25;
    // 0x80046FA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x80046FAC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80046FB0: lw          $t8, 0x722C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X722C);
    // 0x80046FB4: nop

    // 0x80046FB8: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
    // 0x80046FBC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x80046FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80046FC4: jal         0x800AFB70
    // 0x80046FC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800AFB70(rdram, ctx);
        goto after_26;
    // 0x80046FC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_26:
    // 0x80046FCC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80046FD0: lw          $t9, 0x722C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X722C);
    // 0x80046FD4: nop

    // 0x80046FD8: sw          $v0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r2;
    // 0x80046FDC: lhu         $t0, 0x64($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X64);
    // 0x80046FE0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80046FE4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80046FE8: lbu         $t1, -0x2EE0($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2EE0);
    // 0x80046FEC: nop

    // 0x80046FF0: beq         $t1, $zero, L_8004716C
    if (ctx->r9 == 0) {
        // 0x80046FF4: sw          $t1, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r9;
            goto L_8004716C;
    }
    // 0x80046FF4: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x80046FF8: lhu         $t2, 0x64($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X64);
    // 0x80046FFC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80047000: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80047004: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80047008: lw          $t6, -0x2DF4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2DF4);
    // 0x8004700C: nop

    // 0x80047010: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x80047014: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80047018: nop

    // 0x8004701C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80047020: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80047024: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80047028: jal         0x800BC6EC
    // 0x8004702C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_27;
    // 0x8004702C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_27:
    // 0x80047030: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047034: sw          $v0, 0x7220($at)
    MEM_W(0X7220, ctx->r1) = ctx->r2;
    // 0x80047038: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8004703C: lw          $t3, 0x7220($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7220);
    // 0x80047040: nop

    // 0x80047044: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x80047048: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8004704C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80047050: blez        $t5, L_80047160
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80047054: nop
    
            goto L_80047160;
    }
    // 0x80047054: nop

L_80047058:
    // 0x80047058: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8004705C: nop

    // 0x80047060: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80047064: nop

    // 0x80047068: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8004706C: bgez        $t9, L_80047084
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80047070: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80047084;
    }
    // 0x80047070: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80047074: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80047078: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004707C: nop

    // 0x80047080: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80047084:
    // 0x80047084: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80047088: nop

    // 0x8004708C: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x80047090: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80047094: nop

    // 0x80047098: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x8004709C: nop

    // 0x800470A0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800470A4: bgez        $t2, L_800470BC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800470A8: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800470BC;
    }
    // 0x800470A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800470AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800470B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800470B4: nop

    // 0x800470B8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800470BC:
    // 0x800470BC: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800470C0: nop

    // 0x800470C4: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x800470C8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800470CC: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800470D0: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x800470D4: nop

    // 0x800470D8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800470DC: nop

    // 0x800470E0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800470E4: swc1        $f16, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f16.u32l;
    // 0x800470E8: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800470EC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800470F0: lhu         $t8, 0x6($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X6);
    // 0x800470F4: nop

    // 0x800470F8: sh          $t8, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r24;
    // 0x800470FC: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80047100: nop

    // 0x80047104: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    // 0x80047108: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004710C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80047110: nop

    // 0x80047114: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x80047118: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8004711C: nop

    // 0x80047120: addiu       $t4, $t2, 0x18
    ctx->r12 = ADD32(ctx->r10, 0X18);
    // 0x80047124: sw          $t4, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r12;
    // 0x80047128: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8004712C: nop

    // 0x80047130: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80047134: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x80047138: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8004713C: nop

    // 0x80047140: addiu       $t5, $t3, 0x18
    ctx->r13 = ADD32(ctx->r11, 0X18);
    // 0x80047144: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x80047148: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8004714C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80047150: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80047154: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80047158: bne         $at, $zero, L_80047058
    if (ctx->r1 != 0) {
        // 0x8004715C: sw          $t9, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r25;
            goto L_80047058;
    }
    // 0x8004715C: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
L_80047160:
    // 0x80047160: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80047164: nop

    // 0x80047168: sw          $zero, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = 0;
L_8004716C:
    // 0x8004716C: lhu         $t4, 0x64($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X64);
    // 0x80047170: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80047174: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x80047178: lbu         $t2, -0x2DD4($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2DD4);
    // 0x8004717C: nop

    // 0x80047180: beq         $t2, $zero, L_800472CC
    if (ctx->r10 == 0) {
        // 0x80047184: sw          $t2, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r10;
            goto L_800472CC;
    }
    // 0x80047184: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x80047188: lhu         $t6, 0x64($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X64);
    // 0x8004718C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80047190: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80047194: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x80047198: lw          $t3, -0x2C4C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2C4C);
    // 0x8004719C: nop

    // 0x800471A0: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x800471A4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800471A8: nop

    // 0x800471AC: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800471B0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800471B4: jal         0x800BC6EC
    // 0x800471B8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_28;
    // 0x800471B8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_28:
    // 0x800471BC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800471C0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800471C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800471C8: sw          $t8, 0x724C($at)
    MEM_W(0X724C, ctx->r1) = ctx->r24;
    // 0x800471CC: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800471D0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x800471D4: blez        $t9, L_800472BC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800471D8: nop
    
            goto L_800472BC;
    }
    // 0x800471D8: nop

L_800471DC:
    // 0x800471DC: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800471E0: nop

    // 0x800471E4: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x800471E8: nop

    // 0x800471EC: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800471F0: bgez        $t1, L_80047208
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800471F4: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80047208;
    }
    // 0x800471F4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800471F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800471FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047200: nop

    // 0x80047204: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80047208:
    // 0x80047208: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8004720C: nop

    // 0x80047210: swc1        $f6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f6.u32l;
    // 0x80047214: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80047218: nop

    // 0x8004721C: lhu         $t6, 0x2($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X2);
    // 0x80047220: nop

    // 0x80047224: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80047228: bgez        $t6, L_80047240
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8004722C: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80047240;
    }
    // 0x8004722C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80047230: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80047234: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047238: nop

    // 0x8004723C: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_80047240:
    // 0x80047240: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80047244: nop

    // 0x80047248: swc1        $f16, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f16.u32l;
    // 0x8004724C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80047250: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80047254: lh          $t5, 0x4($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X4);
    // 0x80047258: nop

    // 0x8004725C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80047260: nop

    // 0x80047264: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80047268: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8004726C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80047270: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80047274: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x80047278: nop

    // 0x8004727C: addiu       $t1, $t0, 0x6
    ctx->r9 = ADD32(ctx->r8, 0X6);
    // 0x80047280: sb          $t1, 0xC($t4)
    MEM_B(0XC, ctx->r12) = ctx->r9;
    // 0x80047284: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80047288: nop

    // 0x8004728C: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x80047290: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x80047294: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80047298: nop

    // 0x8004729C: addiu       $t3, $t7, 0x10
    ctx->r11 = ADD32(ctx->r15, 0X10);
    // 0x800472A0: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x800472A4: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800472A8: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800472AC: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800472B0: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800472B4: bne         $at, $zero, L_800471DC
    if (ctx->r1 != 0) {
        // 0x800472B8: sw          $t8, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r24;
            goto L_800471DC;
    }
    // 0x800472B8: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
L_800472BC:
    // 0x800472BC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800472C0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800472C4: b           L_800472D4
    // 0x800472C8: sb          $t0, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r8;
        goto L_800472D4;
    // 0x800472C8: sb          $t0, 0xC($t1)
    MEM_B(0XC, ctx->r9) = ctx->r8;
L_800472CC:
    // 0x800472CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800472D0: sw          $zero, 0x724C($at)
    MEM_W(0X724C, ctx->r1) = 0;
L_800472D4:
    // 0x800472D4: lhu         $t4, 0x64($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X64);
    // 0x800472D8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800472DC: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x800472E0: lbu         $t2, -0x4130($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X4130);
    // 0x800472E4: nop

    // 0x800472E8: bne         $t2, $zero, L_800472FC
    if (ctx->r10 != 0) {
        // 0x800472EC: sw          $t2, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r10;
            goto L_800472FC;
    }
    // 0x800472EC: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x800472F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800472F4: b           L_800474FC
    // 0x800472F8: sw          $zero, 0x7240($at)
    MEM_W(0X7240, ctx->r1) = 0;
        goto L_800474FC;
    // 0x800472F8: sw          $zero, 0x7240($at)
    MEM_W(0X7240, ctx->r1) = 0;
L_800472FC:
    // 0x800472FC: lhu         $t6, 0x64($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X64);
    // 0x80047300: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80047304: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80047308: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x8004730C: lw          $t3, -0x40D4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X40D4);
    // 0x80047310: nop

    // 0x80047314: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80047318: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8004731C: nop

    // 0x80047320: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x80047324: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x80047328: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8004732C: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x80047330: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80047334: jal         0x800BC6EC
    // 0x80047338: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_29;
    // 0x80047338: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_29:
    // 0x8004733C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047340: sw          $v0, 0x7240($at)
    MEM_W(0X7240, ctx->r1) = ctx->r2;
    // 0x80047344: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80047348: lw          $t8, 0x7240($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7240);
    // 0x8004734C: nop

    // 0x80047350: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80047354: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80047358: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8004735C: blez        $t9, L_800474F0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80047360: nop
    
            goto L_800474F0;
    }
    // 0x80047360: nop

L_80047364:
    // 0x80047364: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80047368: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8004736C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80047370: nop

    // 0x80047374: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80047378: nop

    // 0x8004737C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80047380: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x80047384: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80047388: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8004738C: lh          $t6, 0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X2);
    // 0x80047390: nop

    // 0x80047394: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80047398: nop

    // 0x8004739C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800473A0: swc1        $f16, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f16.u32l;
    // 0x800473A4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800473A8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800473AC: lh          $t5, 0x4($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X4);
    // 0x800473B0: nop

    // 0x800473B4: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800473B8: nop

    // 0x800473BC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800473C0: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x800473C4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800473C8: jal         0x80099E2C
    // 0x800473CC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80099E2C(rdram, ctx);
        goto after_30;
    // 0x800473CC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_30:
    // 0x800473D0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800473D4: nop

    // 0x800473D8: addiu       $a0, $t9, 0x28
    ctx->r4 = ADD32(ctx->r25, 0X28);
    // 0x800473DC: jal         0x800B1B04
    // 0x800473E0: addiu       $a1, $t9, 0x188
    ctx->r5 = ADD32(ctx->r25, 0X188);
    func_800B1B04(rdram, ctx);
        goto after_31;
    // 0x800473E0: addiu       $a1, $t9, 0x188
    ctx->r5 = ADD32(ctx->r25, 0X188);
    after_31:
    // 0x800473E4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800473E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800473EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800473F0: lui         $a2, 0x3D
    ctx->r6 = S32(0X3D << 16);
    // 0x800473F4: ori         $a2, $a2, 0x65
    ctx->r6 = ctx->r6 | 0X65;
    // 0x800473F8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x800473FC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80047400: addiu       $a0, $t0, 0x28
    ctx->r4 = ADD32(ctx->r8, 0X28);
    // 0x80047404: addiu       $a1, $t0, 0x188
    ctx->r5 = ADD32(ctx->r8, 0X188);
    // 0x80047408: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8004740C: jal         0x800B1F0C
    // 0x80047410: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_32;
    // 0x80047410: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_32:
    // 0x80047414: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80047418: nop

    // 0x8004741C: sh          $zero, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = 0;
    // 0x80047420: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80047424: nop

    // 0x80047428: lhu         $s1, 0x1C($t4)
    ctx->r17 = MEM_HU(ctx->r12, 0X1C);
    // 0x8004742C: nop

    // 0x80047430: sh          $s1, 0x20($t4)
    MEM_H(0X20, ctx->r12) = ctx->r17;
    // 0x80047434: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80047438: nop

    // 0x8004743C: sh          $s1, 0x1E($t2)
    MEM_H(0X1E, ctx->r10) = ctx->r17;
    // 0x80047440: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047444: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80047448: nop

    // 0x8004744C: swc1        $f10, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f10.u32l;
    // 0x80047450: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80047454: nop

    // 0x80047458: lwc1        $f16, 0x14($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X14);
    // 0x8004745C: nop

    // 0x80047460: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
    // 0x80047464: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80047468: addiu       $t3, $zero, 0x65
    ctx->r11 = ADD32(0, 0X65);
    // 0x8004746C: sw          $t3, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r11;
    // 0x80047470: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80047474: nop

    // 0x80047478: lw          $t9, 0xE8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XE8);
    // 0x8004747C: nop

    // 0x80047480: ori         $t0, $t9, 0x2004
    ctx->r8 = ctx->r25 | 0X2004;
    // 0x80047484: sw          $t0, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->r8;
    // 0x80047488: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8004748C: lwc1        $f18, -0x1134($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1134);
    // 0x80047490: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80047494: nop

    // 0x80047498: swc1        $f18, 0x124($t1)
    MEM_W(0X124, ctx->r9) = ctx->f18.u32l;
    // 0x8004749C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800474A0: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x800474A4: sh          $t4, 0xEC($t2)
    MEM_H(0XEC, ctx->r10) = ctx->r12;
    // 0x800474A8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800474AC: nop

    // 0x800474B0: addiu       $t7, $t6, 0x1D0
    ctx->r15 = ADD32(ctx->r14, 0X1D0);
    // 0x800474B4: sw          $t7, 0x1C8($t6)
    MEM_W(0X1C8, ctx->r14) = ctx->r15;
    // 0x800474B8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800474BC: nop

    // 0x800474C0: addiu       $t5, $t3, 0x6
    ctx->r13 = ADD32(ctx->r11, 0X6);
    // 0x800474C4: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x800474C8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800474CC: nop

    // 0x800474D0: addiu       $t0, $t9, 0x1D0
    ctx->r8 = ADD32(ctx->r25, 0X1D0);
    // 0x800474D4: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800474D8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800474DC: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800474E0: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800474E4: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800474E8: bne         $at, $zero, L_80047364
    if (ctx->r1 != 0) {
        // 0x800474EC: sw          $t1, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r9;
            goto L_80047364;
    }
    // 0x800474EC: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
L_800474F0:
    // 0x800474F0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800474F4: nop

    // 0x800474F8: sw          $zero, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = 0;
L_800474FC:
    // 0x800474FC: jal         0x800BC6EC
    // 0x80047500: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_33;
    // 0x80047500: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_33:
    // 0x80047504: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80047508: sw          $v0, 0x7284($at)
    MEM_W(0X7284, ctx->r1) = ctx->r2;
    // 0x8004750C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
L_80047510:
    // 0x80047510: jal         0x800BC6EC
    // 0x80047514: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_34;
    // 0x80047514: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_34:
    // 0x80047518: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8004751C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80047520: lw          $t7, 0x7284($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7284);
    // 0x80047524: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80047528: addu        $t5, $t7, $t3
    ctx->r13 = ADD32(ctx->r15, ctx->r11);
    // 0x8004752C: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x80047530: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80047534: nop

    // 0x80047538: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8004753C: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x80047540: bne         $at, $zero, L_80047510
    if (ctx->r1 != 0) {
        // 0x80047544: sw          $t0, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r8;
            goto L_80047510;
    }
    // 0x80047544: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x80047548: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8004754C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80047550: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80047554: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80047558: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x8004755C: jal         0x800BD1FC
    // 0x80047560: addiu       $a2, $a2, -0x1C90
    ctx->r6 = ADD32(ctx->r6, -0X1C90);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_35;
    // 0x80047560: addiu       $a2, $a2, -0x1C90
    ctx->r6 = ADD32(ctx->r6, -0X1C90);
    after_35:
    // 0x80047564: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80047568: lw          $t8, 0x7284($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7284);
    // 0x8004756C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80047570: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80047574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80047578: jal         0x800BD218
    // 0x8004757C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_36;
    // 0x8004757C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_36:
    // 0x80047580: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80047584: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80047588: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x8004758C: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80047590: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x80047594: jal         0x800BD1FC
    // 0x80047598: addiu       $a2, $a2, -0x1C78
    ctx->r6 = ADD32(ctx->r6, -0X1C78);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_37;
    // 0x80047598: addiu       $a2, $a2, -0x1C78
    ctx->r6 = ADD32(ctx->r6, -0X1C78);
    after_37:
    // 0x8004759C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800475A0: lw          $t1, 0x7284($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7284);
    // 0x800475A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800475A8: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    // 0x800475AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800475B0: jal         0x800BD218
    // 0x800475B4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_38;
    // 0x800475B4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_38:
    // 0x800475B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800475BC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800475C0: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800475C4: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800475C8: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x800475CC: jal         0x800BD1FC
    // 0x800475D0: addiu       $a2, $a2, -0x1C60
    ctx->r6 = ADD32(ctx->r6, -0X1C60);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_39;
    // 0x800475D0: addiu       $a2, $a2, -0x1C60
    ctx->r6 = ADD32(ctx->r6, -0X1C60);
    after_39:
    // 0x800475D4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800475D8: lw          $t4, 0x7284($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7284);
    // 0x800475DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800475E0: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x800475E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800475E8: jal         0x800BD218
    // 0x800475EC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_40;
    // 0x800475EC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_40:
    // 0x800475F0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800475F4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800475F8: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800475FC: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80047600: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x80047604: jal         0x800BD1FC
    // 0x80047608: addiu       $a2, $a2, -0x1C48
    ctx->r6 = ADD32(ctx->r6, -0X1C48);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_41;
    // 0x80047608: addiu       $a2, $a2, -0x1C48
    ctx->r6 = ADD32(ctx->r6, -0X1C48);
    after_41:
    // 0x8004760C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80047610: lw          $t2, 0x7284($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7284);
    // 0x80047614: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80047618: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x8004761C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80047620: jal         0x800BD218
    // 0x80047624: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_42;
    // 0x80047624: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_42:
    // 0x80047628: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8004762C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80047630: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x80047634: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80047638: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x8004763C: jal         0x800BD1FC
    // 0x80047640: addiu       $a2, $a2, -0x1C30
    ctx->r6 = ADD32(ctx->r6, -0X1C30);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_43;
    // 0x80047640: addiu       $a2, $a2, -0x1C30
    ctx->r6 = ADD32(ctx->r6, -0X1C30);
    after_43:
    // 0x80047644: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80047648: lw          $t6, 0x7284($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7284);
    // 0x8004764C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80047650: lw          $a1, 0x10($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X10);
    // 0x80047654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80047658: jal         0x800BD218
    // 0x8004765C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_44;
    // 0x8004765C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_44:
    // 0x80047660: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80047664: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80047668: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x8004766C: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x80047670: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x80047674: jal         0x800BD1FC
    // 0x80047678: addiu       $a2, $a2, -0x1C18
    ctx->r6 = ADD32(ctx->r6, -0X1C18);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_45;
    // 0x80047678: addiu       $a2, $a2, -0x1C18
    ctx->r6 = ADD32(ctx->r6, -0X1C18);
    after_45:
    // 0x8004767C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80047680: lw          $t7, 0x7284($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7284);
    // 0x80047684: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80047688: lw          $a1, 0x14($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X14);
    // 0x8004768C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80047690: jal         0x800BD218
    // 0x80047694: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_46;
    // 0x80047694: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_46:
    // 0x80047698: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8004769C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800476A0: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800476A4: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800476A8: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x800476AC: jal         0x800BD1FC
    // 0x800476B0: addiu       $a2, $a2, -0x1C00
    ctx->r6 = ADD32(ctx->r6, -0X1C00);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_47;
    // 0x800476B0: addiu       $a2, $a2, -0x1C00
    ctx->r6 = ADD32(ctx->r6, -0X1C00);
    after_47:
    // 0x800476B4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800476B8: lw          $t3, 0x7284($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7284);
    // 0x800476BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800476C0: lw          $a1, 0x18($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X18);
    // 0x800476C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800476C8: jal         0x800BD218
    // 0x800476CC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_48;
    // 0x800476CC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_48:
    // 0x800476D0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800476D4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800476D8: lw          $a1, -0x480($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X480);
    // 0x800476DC: lw          $a0, -0x488($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X488);
    // 0x800476E0: lui         $a2, 0x80A4
    ctx->r6 = S32(0X80A4 << 16);
    // 0x800476E4: jal         0x800BD1FC
    // 0x800476E8: addiu       $a2, $a2, -0x1BE8
    ctx->r6 = ADD32(ctx->r6, -0X1BE8);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_49;
    // 0x800476E8: addiu       $a2, $a2, -0x1BE8
    ctx->r6 = ADD32(ctx->r6, -0X1BE8);
    after_49:
    // 0x800476EC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800476F0: lw          $t5, 0x7284($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7284);
    // 0x800476F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800476F8: lw          $a1, 0x1C($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X1C);
    // 0x800476FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80047700: jal         0x800BD218
    // 0x80047704: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_DmaCopy(rdram, ctx);
        goto after_50;
    // 0x80047704: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_50:
    // 0x80047708: jal         0x800220F4
    // 0x8004770C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    func_800220F4(rdram, ctx);
        goto after_51;
    // 0x8004770C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_51:
    // 0x80047710: b           L_80047718
    // 0x80047714: nop

        goto L_80047718;
    // 0x80047714: nop

L_80047718:
    // 0x80047718: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8004771C: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80047720: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80047724: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80047728: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8004772C: jr          $ra
    // 0x80047730: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80047730: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_800675BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800675BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800675C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800675C4: nop

    // 0x800675C8: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x800675CC: nop

    // 0x800675D0: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800675D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800675D8: jr          $ra
    // 0x800675DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800675DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800675E0: jr          $ra
    // 0x800675E4: nop

    return;
    // 0x800675E4: nop

    // 0x800675E8: jr          $ra
    // 0x800675EC: nop

    return;
    // 0x800675EC: nop

;}
RECOMP_FUNC void func_8008D0CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D0CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008D0D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008D0D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008D0D8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8008D0DC: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x8008D0E0: nop

    // 0x8008D0E4: lh          $s0, 0x2($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X2);
    // 0x8008D0E8: nop

    // 0x8008D0EC: beq         $s0, $zero, L_8008D120
    if (ctx->r16 == 0) {
        // 0x8008D0F0: nop
    
            goto L_8008D120;
    }
    // 0x8008D0F0: nop

    // 0x8008D0F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D0F8: beq         $s0, $at, L_8008D13C
    if (ctx->r16 == ctx->r1) {
        // 0x8008D0FC: nop
    
            goto L_8008D13C;
    }
    // 0x8008D0FC: nop

    // 0x8008D100: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008D104: beq         $s0, $at, L_8008D158
    if (ctx->r16 == ctx->r1) {
        // 0x8008D108: nop
    
            goto L_8008D158;
    }
    // 0x8008D108: nop

    // 0x8008D10C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008D110: beq         $s0, $at, L_8008D174
    if (ctx->r16 == ctx->r1) {
        // 0x8008D114: nop
    
            goto L_8008D174;
    }
    // 0x8008D114: nop

    // 0x8008D118: b           L_8008D17C
    // 0x8008D11C: nop

        goto L_8008D17C;
    // 0x8008D11C: nop

L_8008D120:
    // 0x8008D120: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D124: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D128: jal         0x8008D45C
    // 0x8008D12C: nop

    func_8008D45C(rdram, ctx);
        goto after_0;
    // 0x8008D12C: nop

    after_0:
    // 0x8008D130: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8008D134: b           L_8008D17C
    // 0x8008D138: nop

        goto L_8008D17C;
    // 0x8008D138: nop

L_8008D13C:
    // 0x8008D13C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D140: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D144: jal         0x8008D728
    // 0x8008D148: nop

    func_8008D728(rdram, ctx);
        goto after_1;
    // 0x8008D148: nop

    after_1:
    // 0x8008D14C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8008D150: b           L_8008D17C
    // 0x8008D154: nop

        goto L_8008D17C;
    // 0x8008D154: nop

L_8008D158:
    // 0x8008D158: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D15C: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D160: jal         0x8008D9E4
    // 0x8008D164: nop

    func_8008D9E4(rdram, ctx);
        goto after_2;
    // 0x8008D164: nop

    after_2:
    // 0x8008D168: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8008D16C: b           L_8008D17C
    // 0x8008D170: nop

        goto L_8008D17C;
    // 0x8008D170: nop

L_8008D174:
    // 0x8008D174: b           L_8008D22C
    // 0x8008D178: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008D22C;
    // 0x8008D178: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8008D17C:
    // 0x8008D17C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8008D180: lw          $t7, -0x76BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76BC);
    // 0x8008D184: nop

    // 0x8008D188: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8008D18C: nop

    // 0x8008D190: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8008D194: beq         $t9, $zero, L_8008D1CC
    if (ctx->r25 == 0) {
        // 0x8008D198: nop
    
            goto L_8008D1CC;
    }
    // 0x8008D198: nop

    // 0x8008D19C: jal         0x800C1754
    // 0x8008D1A0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_3;
    // 0x8008D1A0: nop

    after_3:
    // 0x8008D1A4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D1A8: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D1AC: jal         0x8009A14C
    // 0x8008D1B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_8009A14C(rdram, ctx);
        goto after_4;
    // 0x8008D1B0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_4:
    // 0x8008D1B4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D1B8: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D1BC: jal         0x800997D8
    // 0x8008D1C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800997D8(rdram, ctx);
        goto after_5;
    // 0x8008D1C0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_5:
    // 0x8008D1C4: jal         0x800C1A28
    // 0x8008D1C8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x8008D1C8: nop

    after_6:
L_8008D1CC:
    // 0x8008D1CC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8008D1D0: lw          $t1, -0x76BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76BC);
    // 0x8008D1D4: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x8008D1D8: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8008D1DC: nop

    // 0x8008D1E0: beq         $t0, $t2, L_8008D20C
    if (ctx->r8 == ctx->r10) {
        // 0x8008D1E4: nop
    
            goto L_8008D20C;
    }
    // 0x8008D1E4: nop

    // 0x8008D1E8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8008D1EC: lw          $t4, -0x76BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76BC);
    // 0x8008D1F0: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x8008D1F4: nop

    // 0x8008D1F8: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x8008D1FC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D200: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D204: jal         0x8008D29C
    // 0x8008D208: nop

    func_8008D29C(rdram, ctx);
        goto after_7;
    // 0x8008D208: nop

    after_7:
L_8008D20C:
    // 0x8008D20C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8008D210: lw          $a0, -0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76BC);
    // 0x8008D214: jal         0x8008DB7C
    // 0x8008D218: nop

    func_8008DB7C(rdram, ctx);
        goto after_8;
    // 0x8008D218: nop

    after_8:
    // 0x8008D21C: b           L_8008D22C
    // 0x8008D220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D22C;
    // 0x8008D220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008D224: b           L_8008D22C
    // 0x8008D228: nop

        goto L_8008D22C;
    // 0x8008D228: nop

L_8008D22C:
    // 0x8008D22C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008D234: jr          $ra
    // 0x8008D238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008D238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80033D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033D78: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80033D7C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80033D80: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80033D84: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80033D88: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x80033D8C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80033D90: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80033D94: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80033D98: lw          $t6, 0x72B8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72B8);
    // 0x80033D9C: nop

    // 0x80033DA0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80033DA4: sh          $zero, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = 0;
L_80033DA8:
    // 0x80033DA8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80033DAC: nop

    // 0x80033DB0: lbu         $s0, 0x0($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0X0);
    // 0x80033DB4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80033DB8: sltiu       $t8, $s0, 0x1
    ctx->r24 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80033DBC: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80033DC0: beq         $s0, $zero, L_80033DD0
    if (ctx->r16 == 0) {
        // 0x80033DC4: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_80033DD0;
    }
    // 0x80033DC4: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80033DC8: b           L_80033DEC
    // 0x80033DCC: nop

        goto L_80033DEC;
    // 0x80033DCC: nop

L_80033DD0:
    // 0x80033DD0: lhu         $t0, 0x3E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3E);
    // 0x80033DD4: nop

    // 0x80033DD8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80033DDC: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80033DE0: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x80033DE4: bne         $at, $zero, L_80033DA8
    if (ctx->r1 != 0) {
        // 0x80033DE8: sh          $t1, 0x3E($sp)
        MEM_H(0X3E, ctx->r29) = ctx->r9;
            goto L_80033DA8;
    }
    // 0x80033DE8: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
L_80033DEC:
    // 0x80033DEC: lhu         $t3, 0x3E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3E);
    // 0x80033DF0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80033DF4: bne         $t3, $at, L_80033E04
    if (ctx->r11 != ctx->r1) {
        // 0x80033DF8: nop
    
            goto L_80033E04;
    }
    // 0x80033DF8: nop

    // 0x80033DFC: b           L_80033EEC
    // 0x80033E00: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80033EEC;
    // 0x80033E00: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80033E04:
    // 0x80033E04: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80033E08: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80033E0C: sb          $t4, -0x1($t5)
    MEM_B(-0X1, ctx->r13) = ctx->r12;
    // 0x80033E10: lhu         $t8, 0x3E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3E);
    // 0x80033E14: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80033E18: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80033E1C: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x80033E20: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80033E24: lw          $t6, 0x72B8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72B8);
    // 0x80033E28: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80033E2C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80033E30: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80033E34: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x80033E38: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80033E3C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80033E40: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80033E44: nop

    // 0x80033E48: swc1        $f4, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f4.u32l;
    // 0x80033E4C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80033E50: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80033E54: nop

    // 0x80033E58: swc1        $f6, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f6.u32l;
    // 0x80033E5C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80033E60: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80033E64: nop

    // 0x80033E68: swc1        $f8, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f8.u32l;
    // 0x80033E6C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80033E70: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80033E74: nop

    // 0x80033E78: swc1        $f10, 0xFC($t4)
    MEM_W(0XFC, ctx->r12) = ctx->f10.u32l;
    // 0x80033E7C: lhu         $t8, 0x3E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3E);
    // 0x80033E80: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80033E84: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80033E88: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80033E8C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80033E90: lw          $t5, 0x72B8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72B8);
    // 0x80033E94: lhu         $t7, 0x52($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X52);
    // 0x80033E98: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80033E9C: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x80033EA0: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80033EA4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80033EA8: lhu         $t1, 0x5E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X5E);
    // 0x80033EAC: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80033EB0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80033EB4: lhu         $a3, 0x5A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X5A);
    // 0x80033EB8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x80033EBC: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80033EC0: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    // 0x80033EC4: or          $a2, $t9, $t0
    ctx->r6 = ctx->r25 | ctx->r8;
    // 0x80033EC8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80033ECC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80033ED0: jal         0x800B1F0C
    // 0x80033ED4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_800B1F0C(rdram, ctx);
        goto after_0;
    // 0x80033ED4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x80033ED8: lh          $v0, 0x3E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X3E);
    // 0x80033EDC: b           L_80033EEC
    // 0x80033EE0: nop

        goto L_80033EEC;
    // 0x80033EE0: nop

    // 0x80033EE4: b           L_80033EEC
    // 0x80033EE8: nop

        goto L_80033EEC;
    // 0x80033EE8: nop

L_80033EEC:
    // 0x80033EEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80033EF0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80033EF4: jr          $ra
    // 0x80033EF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80033EF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80076BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076BB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80076BB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80076BBC: nop

    // 0x80076BC0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80076BC4: nop

    // 0x80076BC8: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x80076BCC: jr          $ra
    // 0x80076BD0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80076BD0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80076BD4: jr          $ra
    // 0x80076BD8: nop

    return;
    // 0x80076BD8: nop

    // 0x80076BDC: jr          $ra
    // 0x80076BE0: nop

    return;
    // 0x80076BE0: nop

;}
RECOMP_FUNC void AudioMgr_AudioThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8A7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B8A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8A84: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B8A88: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800B8A8C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800B8A90: nop

    // 0x800B8A94: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800B8A98: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800B8A9C: nop

    // 0x800B8AA0: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800B8AA4: nop

    // 0x800B8AA8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800B8AAC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800B8AB0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800B8AB4: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800B8AB8: addiu       $t1, $t1, 0x3DF8
    ctx->r9 = ADD32(ctx->r9, 0X3DF8);
    // 0x800B8ABC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800B8AC0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800B8AC4: nop

    // 0x800B8AC8: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x800B8ACC: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x800B8AD0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800B8AD4: nop

    // 0x800B8AD8: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x800B8ADC: jal         0x80098688
    // 0x800B8AE0: nop

    func_80098688(rdram, ctx);
        goto after_0;
    // 0x800B8AE0: nop

    after_0:
    // 0x800B8AE4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B8AE8: nop

    // 0x800B8AEC: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x800B8AF0: jal         0x80098894
    // 0x800B8AF4: nop

    func_80098894(rdram, ctx);
        goto after_1;
    // 0x800B8AF4: nop

    after_1:
L_800B8AF8:
    // 0x800B8AF8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B8AFC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800B8B00: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x800B8B04: jal         0x800C143C
    // 0x800B8B08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_2;
    // 0x800B8B08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800B8B0C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8B10: nop

    // 0x800B8B14: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800B8B18: nop

    // 0x800B8B1C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B8B20: sltiu       $at, $t8, 0xB
    ctx->r1 = ctx->r24 < 0XB ? 1 : 0;
    // 0x800B8B24: beq         $at, $zero, L_800B8C78
    if (ctx->r1 == 0) {
        // 0x800B8B28: nop
    
            goto L_800B8C78;
    }
    // 0x800B8B28: nop

    // 0x800B8B2C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B8B30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B8B34: addu        $at, $at, $t8
    gpr jr_addend_800B8B40 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B8B38: lw          $t8, -0x4A8($at)
    ctx->r24 = ADD32(ctx->r1, -0X4A8);
    // 0x800B8B3C: nop

    // 0x800B8B40: jr          $t8
    // 0x800B8B44: nop

    switch (jr_addend_800B8B40 >> 2) {
        case 0: goto L_800B8B48; break;
        case 1: goto L_800B8C78; break;
        case 2: goto L_800B8C78; break;
        case 3: goto L_800B8C58; break;
        case 4: goto L_800B8B48; break;
        case 5: goto L_800B8C78; break;
        case 6: goto L_800B8C78; break;
        case 7: goto L_800B8C78; break;
        case 8: goto L_800B8C78; break;
        case 9: goto L_800B8C68; break;
        case 10: goto L_800B8C70; break;
        default: switch_error(__func__, 0x800B8B40, 0x800EFB58);
    }
    // 0x800B8B44: nop

L_800B8B48:
    // 0x800B8B48: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B8B4C: nop

    // 0x800B8B50: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x800B8B54: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x800B8B58: nop

    // 0x800B8B5C: bne         $t0, $zero, L_800B8C38
    if (ctx->r8 != 0) {
        // 0x800B8B60: nop
    
            goto L_800B8C38;
    }
    // 0x800B8B60: nop

    // 0x800B8B64: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800B8B68: lw          $t1, -0x3364($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3364);
    // 0x800B8B6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B8B70: divu        $zero, $t1, $at
    lo = S32(U32(ctx->r9) / U32(ctx->r1)); hi = S32(U32(ctx->r9) % U32(ctx->r1));
    // 0x800B8B74: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B8B78: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B8B7C: mfhi        $t2
    ctx->r10 = hi;
    // 0x800B8B80: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B8B84: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x800B8B88: lw          $a0, -0x34A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34A8);
    // 0x800B8B8C: jal         0x800B8CA0
    // 0x800B8B90: nop

    AudioMgr_HandleFrameMsg(rdram, ctx);
        goto after_3;
    // 0x800B8B90: nop

    after_3:
    // 0x800B8B94: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800B8B98: jal         0x800BAD4C
    // 0x800B8B9C: nop

    AudioDriver_Update(rdram, ctx);
        goto after_4;
    // 0x800B8B9C: nop

    after_4:
    // 0x800B8BA0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800B8BA4: nop

    // 0x800B8BA8: beq         $t4, $zero, L_800B8C18
    if (ctx->r12 == 0) {
        // 0x800B8BAC: nop
    
            goto L_800B8C18;
    }
    // 0x800B8BAC: nop

    // 0x800B8BB0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800B8BB4: addiu       $a0, $a0, -0x34B0
    ctx->r4 = ADD32(ctx->r4, -0X34B0);
    // 0x800B8BB8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800B8BBC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800B8BC0: jal         0x800C1570
    // 0x800B8BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsg(rdram, ctx);
        goto after_5;
    // 0x800B8BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800B8BC8: jal         0x800C79B0
    // 0x800B8BCC: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_6;
    // 0x800B8BCC: nop

    after_6:
    // 0x800B8BD0: srl         $t5, $v0, 2
    ctx->r13 = S32(U32(ctx->r2) >> 2);
    // 0x800B8BD4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800B8BD8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800B8BDC: nop

    // 0x800B8BE0: bne         $t6, $zero, L_800B8C04
    if (ctx->r14 != 0) {
        // 0x800B8BE4: nop
    
            goto L_800B8C04;
    }
    // 0x800B8BE4: nop

    // 0x800B8BE8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800B8BEC: lw          $t7, -0x3464($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3464);
    // 0x800B8BF0: nop

    // 0x800B8BF4: bne         $t7, $zero, L_800B8C04
    if (ctx->r15 != 0) {
        // 0x800B8BF8: nop
    
            goto L_800B8C04;
    }
    // 0x800B8BF8: nop

    // 0x800B8BFC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800B8C00: sw          $zero, -0x3464($at)
    MEM_W(-0X3464, ctx->r1) = 0;
L_800B8C04:
    // 0x800B8C04: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8C08: nop

    // 0x800B8C0C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800B8C10: nop

    // 0x800B8C14: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800B8C18:
    // 0x800B8C18: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B8C1C: nop

    // 0x800B8C20: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x800B8C24: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x800B8C28: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x800B8C2C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B8C30: b           L_800B8C50
    // 0x800B8C34: sw          $t2, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r10;
        goto L_800B8C50;
    // 0x800B8C34: sw          $t2, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r10;
L_800B8C38:
    // 0x800B8C38: jal         0x800BAD4C
    // 0x800B8C3C: nop

    AudioDriver_Update(rdram, ctx);
        goto after_7;
    // 0x800B8C3C: nop

    after_7:
    // 0x800B8C40: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800B8C44: nop

    // 0x800B8C48: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x800B8C4C: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
L_800B8C50:
    // 0x800B8C50: b           L_800B8C80
    // 0x800B8C54: nop

        goto L_800B8C80;
    // 0x800B8C54: nop

L_800B8C58:
    // 0x800B8C58: b           L_800B8C58
    pause_self(rdram);
    // 0x800B8C5C: nop

    // 0x800B8C60: b           L_800B8C80
    // 0x800B8C64: nop

        goto L_800B8C80;
    // 0x800B8C64: nop

L_800B8C68:
    // 0x800B8C68: b           L_800B8C80
    // 0x800B8C6C: nop

        goto L_800B8C80;
    // 0x800B8C6C: nop

L_800B8C70:
    // 0x800B8C70: b           L_800B8C80
    // 0x800B8C74: nop

        goto L_800B8C80;
    // 0x800B8C74: nop

L_800B8C78:
    // 0x800B8C78: b           L_800B8C80
    // 0x800B8C7C: nop

        goto L_800B8C80;
    // 0x800B8C7C: nop

L_800B8C80:
    // 0x800B8C80: b           L_800B8AF8
    // 0x800B8C84: nop

        goto L_800B8AF8;
    // 0x800B8C84: nop

    // 0x800B8C88: b           L_800B8C90
    // 0x800B8C8C: nop

        goto L_800B8C90;
    // 0x800B8C8C: nop

L_800B8C90:
    // 0x800B8C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8C94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B8C98: jr          $ra
    // 0x800B8C9C: nop

    return;
    // 0x800B8C9C: nop

;}
RECOMP_FUNC void func_80067B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067B68: jal         0x80061488
    // 0x80067B6C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067B6C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_0:
    // 0x80067B70: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067B74: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067B78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067B7C: beq         $v0, $zero, L_80067BA4
    if (ctx->r2 == 0) {
        // 0x80067B80: nop
    
            goto L_80067BA4;
    }
    // 0x80067B80: nop

    // 0x80067B84: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80067B88: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80067B8C: nop

    // 0x80067B90: lh          $v0, 0xE($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XE);
    // 0x80067B94: nop

    // 0x80067B98: slti        $t8, $v0, 0x64
    ctx->r24 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80067B9C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067BA0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067BA4:
    // 0x80067BA4: b           L_80067BB4
    // 0x80067BA8: nop

        goto L_80067BB4;
    // 0x80067BA8: nop

    // 0x80067BAC: b           L_80067BB4
    // 0x80067BB0: nop

        goto L_80067BB4;
    // 0x80067BB0: nop

L_80067BB4:
    // 0x80067BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067BBC: jr          $ra
    // 0x80067BC0: nop

    return;
    // 0x80067BC0: nop

;}
RECOMP_FUNC void func_80070770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070778: jal         0x80061348
    // 0x8007077C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007077C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070780: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070784: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070788: beq         $v0, $zero, L_800707D8
    if (ctx->r2 == 0) {
        // 0x8007078C: nop
    
            goto L_800707D8;
    }
    // 0x8007078C: nop

    // 0x80070790: jal         0x80061348
    // 0x80070794: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070794: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070798: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007079C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800707A0: beq         $v0, $zero, L_800707D8
    if (ctx->r2 == 0) {
        // 0x800707A4: nop
    
            goto L_800707D8;
    }
    // 0x800707A4: nop

    // 0x800707A8: jal         0x80061348
    // 0x800707AC: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800707AC: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800707B0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800707B4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800707B8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800707BC: beq         $v0, $zero, L_800707D8
    if (ctx->r2 == 0) {
        // 0x800707C0: nop
    
            goto L_800707D8;
    }
    // 0x800707C0: nop

    // 0x800707C4: jal         0x80061348
    // 0x800707C8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800707C8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x800707CC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800707D0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800707D4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800707D8:
    // 0x800707D8: b           L_800707E8
    // 0x800707DC: nop

        goto L_800707E8;
    // 0x800707DC: nop

    // 0x800707E0: b           L_800707E8
    // 0x800707E4: nop

        goto L_800707E8;
    // 0x800707E4: nop

L_800707E8:
    // 0x800707E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800707EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800707F0: jr          $ra
    // 0x800707F4: nop

    return;
    // 0x800707F4: nop

;}
RECOMP_FUNC void ContPak_GetFindFileResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEBF4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AEBF8: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AEBFC: nop

    // 0x800AEC00: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x800AEC04: beq         $t7, $zero, L_800AEC14
    if (ctx->r15 == 0) {
        // 0x800AEC08: nop
    
            goto L_800AEC14;
    }
    // 0x800AEC08: nop

    // 0x800AEC0C: jr          $ra
    // 0x800AEC10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEC10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEC14:
    // 0x800AEC14: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AEC18: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AEC1C: nop

    // 0x800AEC20: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x800AEC24: beq         $t9, $zero, L_800AEC34
    if (ctx->r25 == 0) {
        // 0x800AEC28: nop
    
            goto L_800AEC34;
    }
    // 0x800AEC28: nop

    // 0x800AEC2C: jr          $ra
    // 0x800AEC30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AEC30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AEC34:
    // 0x800AEC34: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AEC38: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AEC3C: nop

    // 0x800AEC40: beq         $t0, $zero, L_800AEC60
    if (ctx->r8 == 0) {
        // 0x800AEC44: nop
    
            goto L_800AEC60;
    }
    // 0x800AEC44: nop

    // 0x800AEC48: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEC4C: lw          $v0, 0x1684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1684);
    // 0x800AEC50: nop

    // 0x800AEC54: ori         $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 | 0X1000;
    // 0x800AEC58: jr          $ra
    // 0x800AEC5C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800AEC5C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800AEC60:
    // 0x800AEC60: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800AEC64: lw          $v0, 0x167C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X167C);
    // 0x800AEC68: jr          $ra
    // 0x800AEC6C: nop

    return;
    // 0x800AEC6C: nop

    // 0x800AEC70: jr          $ra
    // 0x800AEC74: nop

    return;
    // 0x800AEC74: nop

    // 0x800AEC78: jr          $ra
    // 0x800AEC7C: nop

    return;
    // 0x800AEC7C: nop

;}
RECOMP_FUNC void func_80083700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80083704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083708: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008370C: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083710: nop

    // 0x80083714: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80083718: nop

    // 0x8008371C: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80083720: beq         $t8, $zero, L_8008375C
    if (ctx->r24 == 0) {
        // 0x80083724: nop
    
            goto L_8008375C;
    }
    // 0x80083724: nop

    // 0x80083728: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008372C: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083730: jal         0x80088F50
    // 0x80083734: nop

    func_80088F50(rdram, ctx);
        goto after_0;
    // 0x80083734: nop

    after_0:
    // 0x80083738: beq         $v0, $zero, L_8008375C
    if (ctx->r2 == 0) {
        // 0x8008373C: nop
    
            goto L_8008375C;
    }
    // 0x8008373C: nop

    // 0x80083740: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083744: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083748: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x8008374C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80083750: nop

    // 0x80083754: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80083758: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_8008375C:
    // 0x8008375C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083760: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083764: jal         0x8008AF5C
    // 0x80083768: nop

    func_8008AF5C(rdram, ctx);
        goto after_1;
    // 0x80083768: nop

    after_1:
    // 0x8008376C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083770: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083774: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80083778: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x8008377C: nop

    // 0x80083780: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80083784: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80083788: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8008378C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80083790: lw          $t5, 0x4538($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4538);
    // 0x80083794: nop

    // 0x80083798: beq         $t5, $zero, L_8008383C
    if (ctx->r13 == 0) {
        // 0x8008379C: nop
    
            goto L_8008383C;
    }
    // 0x8008379C: nop

    // 0x800837A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800837A4: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x800837A8: nop

    // 0x800837AC: lw          $a0, 0x728($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X728);
    // 0x800837B0: jal         0x8001ABEC
    // 0x800837B4: nop

    func_8001ABEC(rdram, ctx);
        goto after_2;
    // 0x800837B4: nop

    after_2:
    // 0x800837B8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800837BC: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800837C0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800837C4: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x800837C8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800837CC: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800837D0: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800837D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800837D8: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x800837DC: lw          $t9, 0x4538($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4538);
    // 0x800837E0: nop

    // 0x800837E4: jalr        $t9
    // 0x800837E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800837E8: nop

    after_3:
    // 0x800837EC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800837F0: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x800837F4: nop

    // 0x800837F8: lw          $t2, 0x728($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X728);
    // 0x800837FC: nop

    // 0x80083800: lw          $t3, 0x138($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X138);
    // 0x80083804: nop

    // 0x80083808: sh          $zero, 0x20($t3)
    MEM_H(0X20, ctx->r11) = 0;
    // 0x8008380C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083810: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083814: nop

    // 0x80083818: lw          $a0, 0x728($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X728);
    // 0x8008381C: jal         0x8001ACDC
    // 0x80083820: nop

    func_8001ACDC(rdram, ctx);
        goto after_4;
    // 0x80083820: nop

    after_4:
    // 0x80083824: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083828: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x8008382C: nop

    // 0x80083830: lw          $a0, 0x728($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X728);
    // 0x80083834: jal         0x8001ADBC
    // 0x80083838: nop

    func_8001ADBC(rdram, ctx);
        goto after_5;
    // 0x80083838: nop

    after_5:
L_8008383C:
    // 0x8008383C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083840: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083844: jal         0x8008CC08
    // 0x80083848: nop

    func_8008CC08(rdram, ctx);
        goto after_6;
    // 0x80083848: nop

    after_6:
    // 0x8008384C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083850: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083854: jal         0x80089BA4
    // 0x80083858: nop

    func_80089BA4(rdram, ctx);
        goto after_7;
    // 0x80083858: nop

    after_7:
    // 0x8008385C: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x80083860: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083864: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083868: nop

    // 0x8008386C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80083870: nop

    // 0x80083874: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80083878: bne         $t8, $zero, L_800838F4
    if (ctx->r24 != 0) {
        // 0x8008387C: nop
    
            goto L_800838F4;
    }
    // 0x8008387C: nop

    // 0x80083880: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80083884: lw          $t0, 0x7B4C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7B4C);
    // 0x80083888: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008388C: lh          $t9, 0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X4);
    // 0x80083890: nop

    // 0x80083894: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80083898: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8008389C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800838A0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800838A4: lw          $t2, 0x4534($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4534);
    // 0x800838A8: nop

    // 0x800838AC: beq         $t2, $zero, L_800838EC
    if (ctx->r10 == 0) {
        // 0x800838B0: nop
    
            goto L_800838EC;
    }
    // 0x800838B0: nop

    // 0x800838B4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800838B8: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x800838BC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800838C0: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x800838C4: lhu         $a1, 0x1C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1C);
    // 0x800838C8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800838CC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800838D0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800838D4: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800838D8: lw          $t9, 0x4534($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4534);
    // 0x800838DC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800838E0: jalr        $t9
    // 0x800838E4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800838E4: nop

    after_8:
    // 0x800838E8: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_800838EC:
    // 0x800838EC: b           L_8008390C
    // 0x800838F0: nop

        goto L_8008390C;
    // 0x800838F0: nop

L_800838F4:
    // 0x800838F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800838F8: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x800838FC: nop

    // 0x80083900: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x80083904: nop

    // 0x80083908: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
L_8008390C:
    // 0x8008390C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083910: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083914: jal         0x8008A808
    // 0x80083918: nop

    func_8008A808(rdram, ctx);
        goto after_9;
    // 0x80083918: nop

    after_9:
    // 0x8008391C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80083920: lw          $t8, 0x7B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B4C);
    // 0x80083924: nop

    // 0x80083928: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x8008392C: nop

    // 0x80083930: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x80083934: beq         $t1, $zero, L_8008394C
    if (ctx->r9 == 0) {
        // 0x80083938: nop
    
            goto L_8008394C;
    }
    // 0x80083938: nop

    // 0x8008393C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083940: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083944: jal         0x8008B108
    // 0x80083948: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_8008B108(rdram, ctx);
        goto after_10;
    // 0x80083948: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_10:
L_8008394C:
    // 0x8008394C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80083950: lw          $t2, 0x7B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7B4C);
    // 0x80083954: nop

    // 0x80083958: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8008395C: nop

    // 0x80083960: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80083964: beq         $t4, $zero, L_8008397C
    if (ctx->r12 == 0) {
        // 0x80083968: nop
    
            goto L_8008397C;
    }
    // 0x80083968: nop

    // 0x8008396C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083970: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083974: jal         0x8008B108
    // 0x80083978: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_8008B108(rdram, ctx);
        goto after_11;
    // 0x80083978: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_11:
L_8008397C:
    // 0x8008397C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083980: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083984: nop

    // 0x80083988: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x8008398C: nop

    // 0x80083990: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x80083994: beq         $t6, $zero, L_800839E4
    if (ctx->r14 == 0) {
        // 0x80083998: nop
    
            goto L_800839E4;
    }
    // 0x80083998: nop

    // 0x8008399C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800839A0:
    // 0x800839A0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800839A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800839A8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800839AC: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800839B0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800839B4: lw          $t7, 0x7B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B4C);
    // 0x800839B8: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800839BC: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x800839C0: addu        $a0, $t7, $t0
    ctx->r4 = ADD32(ctx->r15, ctx->r8);
    // 0x800839C4: jal         0x8008B18C
    // 0x800839C8: addiu       $a0, $a0, 0x1A8
    ctx->r4 = ADD32(ctx->r4, 0X1A8);
    func_8008B18C(rdram, ctx);
        goto after_12;
    // 0x800839C8: addiu       $a0, $a0, 0x1A8
    ctx->r4 = ADD32(ctx->r4, 0X1A8);
    after_12:
    // 0x800839CC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800839D0: nop

    // 0x800839D4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800839D8: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x800839DC: bne         $at, $zero, L_800839A0
    if (ctx->r1 != 0) {
        // 0x800839E0: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_800839A0;
    }
    // 0x800839E0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_800839E4:
    // 0x800839E4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800839E8: lw          $t3, 0x7B4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7B4C);
    // 0x800839EC: nop

    // 0x800839F0: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800839F4: nop

    // 0x800839F8: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800839FC: beq         $t5, $zero, L_80083A1C
    if (ctx->r13 == 0) {
        // 0x80083A00: nop
    
            goto L_80083A1C;
    }
    // 0x80083A00: nop

    // 0x80083A04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80083A08: lw          $t9, 0x7B4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B4C);
    // 0x80083A0C: nop

    // 0x80083A10: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80083A14: jal         0x8008B1D8
    // 0x80083A18: addiu       $a1, $t9, 0x48
    ctx->r5 = ADD32(ctx->r25, 0X48);
    func_8008B1D8(rdram, ctx);
        goto after_13;
    // 0x80083A18: addiu       $a1, $t9, 0x48
    ctx->r5 = ADD32(ctx->r25, 0X48);
    after_13:
L_80083A1C:
    // 0x80083A1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80083A20: lw          $t6, 0x7B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B4C);
    // 0x80083A24: nop

    // 0x80083A28: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80083A2C: nop

    // 0x80083A30: andi        $t7, $t8, 0x2
    ctx->r15 = ctx->r24 & 0X2;
    // 0x80083A34: beq         $t7, $zero, L_80083A4C
    if (ctx->r15 == 0) {
        // 0x80083A38: nop
    
            goto L_80083A4C;
    }
    // 0x80083A38: nop

    // 0x80083A3C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083A40: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083A44: jal         0x8008B108
    // 0x80083A48: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_8008B108(rdram, ctx);
        goto after_14;
    // 0x80083A48: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_14:
L_80083A4C:
    // 0x80083A4C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80083A50: lw          $t1, 0x7B4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7B4C);
    // 0x80083A54: lh          $t0, 0x1E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X1E);
    // 0x80083A58: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80083A5C: nop

    // 0x80083A60: beq         $t0, $t2, L_80083AB0
    if (ctx->r8 == ctx->r10) {
        // 0x80083A64: nop
    
            goto L_80083AB0;
    }
    // 0x80083A64: nop

    // 0x80083A68: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80083A6C: lw          $t4, 0x7B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7B4C);
    // 0x80083A70: lh          $t3, 0x1E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X1E);
    // 0x80083A74: nop

    // 0x80083A78: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x80083A7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80083A80: lw          $a0, 0x7B4C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7B4C);
    // 0x80083A84: jal         0x80088DF4
    // 0x80083A88: nop

    func_80088DF4(rdram, ctx);
        goto after_15;
    // 0x80083A88: nop

    after_15:
    // 0x80083A8C: bne         $v0, $zero, L_80083AB0
    if (ctx->r2 != 0) {
        // 0x80083A90: nop
    
            goto L_80083AB0;
    }
    // 0x80083A90: nop

    // 0x80083A94: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80083A98: lw          $t5, 0x7B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7B4C);
    // 0x80083A9C: nop

    // 0x80083AA0: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x80083AA4: nop

    // 0x80083AA8: ori         $t6, $t9, 0x40
    ctx->r14 = ctx->r25 | 0X40;
    // 0x80083AAC: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_80083AB0:
    // 0x80083AB0: b           L_80083AC0
    // 0x80083AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80083AC0;
    // 0x80083AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80083AB8: b           L_80083AC0
    // 0x80083ABC: nop

        goto L_80083AC0;
    // 0x80083ABC: nop

L_80083AC0:
    // 0x80083AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083AC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80083AC8: jr          $ra
    // 0x80083ACC: nop

    return;
    // 0x80083ACC: nop

;}
RECOMP_FUNC void func_80072A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072A74: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80072A78: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80072A7C: nop

    // 0x80072A80: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80072A84: nop

    // 0x80072A88: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80072A8C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80072A90: jr          $ra
    // 0x80072A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80072A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80072A98: jr          $ra
    // 0x80072A9C: nop

    return;
    // 0x80072A9C: nop

    // 0x80072AA0: jr          $ra
    // 0x80072AA4: nop

    return;
    // 0x80072AA4: nop

;}
RECOMP_FUNC void func_800B47A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B47A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B47A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B47A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B47AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B47B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B47B4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B47B8: nop

    // 0x800B47BC: lbu         $t8, 0x30($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X30);
    // 0x800B47C0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800B47C4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800B47C8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800B47CC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800B47D0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800B47D4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B47D8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800B47DC: nop

    // 0x800B47E0: lhu         $t2, 0xA($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XA);
    // 0x800B47E4: nop

    // 0x800B47E8: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x800B47EC: beq         $t3, $zero, L_800B480C
    if (ctx->r11 == 0) {
        // 0x800B47F0: nop
    
            goto L_800B480C;
    }
    // 0x800B47F0: nop

    // 0x800B47F4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B47F8: nop

    // 0x800B47FC: lhu         $t5, 0x3A($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X3A);
    // 0x800B4800: nop

    // 0x800B4804: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x800B4808: sh          $t6, 0x3A($t4)
    MEM_H(0X3A, ctx->r12) = ctx->r14;
L_800B480C:
    // 0x800B480C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4810: nop

    // 0x800B4814: lhu         $t7, 0xA($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0XA);
    // 0x800B4818: nop

    // 0x800B481C: andi        $t9, $t7, 0x80
    ctx->r25 = ctx->r15 & 0X80;
    // 0x800B4820: beq         $t9, $zero, L_800B4840
    if (ctx->r25 == 0) {
        // 0x800B4824: nop
    
            goto L_800B4840;
    }
    // 0x800B4824: nop

    // 0x800B4828: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B482C: nop

    // 0x800B4830: lhu         $t1, 0x3A($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X3A);
    // 0x800B4834: nop

    // 0x800B4838: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800B483C: sh          $t2, 0x3A($t0)
    MEM_H(0X3A, ctx->r8) = ctx->r10;
L_800B4840:
    // 0x800B4840: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4844: nop

    // 0x800B4848: lhu         $t5, 0xA($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0XA);
    // 0x800B484C: nop

    // 0x800B4850: andi        $t6, $t5, 0x100
    ctx->r14 = ctx->r13 & 0X100;
    // 0x800B4854: beq         $t6, $zero, L_800B4874
    if (ctx->r14 == 0) {
        // 0x800B4858: nop
    
            goto L_800B4874;
    }
    // 0x800B4858: nop

    // 0x800B485C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800B4860: nop

    // 0x800B4864: lhu         $t8, 0x3A($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X3A);
    // 0x800B4868: nop

    // 0x800B486C: ori         $t7, $t8, 0x4
    ctx->r15 = ctx->r24 | 0X4;
    // 0x800B4870: sh          $t7, 0x3A($t4)
    MEM_H(0X3A, ctx->r12) = ctx->r15;
L_800B4874:
    // 0x800B4874: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4878: nop

    // 0x800B487C: lhu         $t1, 0xA($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0XA);
    // 0x800B4880: nop

    // 0x800B4884: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x800B4888: beq         $t2, $zero, L_800B48C4
    if (ctx->r10 == 0) {
        // 0x800B488C: nop
    
            goto L_800B48C4;
    }
    // 0x800B488C: nop

    // 0x800B4890: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B4894: nop

    // 0x800B4898: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x800B489C: nop

    // 0x800B48A0: andi        $t5, $t3, 0x10
    ctx->r13 = ctx->r11 & 0X10;
    // 0x800B48A4: bne         $t5, $zero, L_800B48C4
    if (ctx->r13 != 0) {
        // 0x800B48A8: nop
    
            goto L_800B48C4;
    }
    // 0x800B48A8: nop

    // 0x800B48AC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800B48B0: nop

    // 0x800B48B4: lhu         $t8, 0x3A($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X3A);
    // 0x800B48B8: nop

    // 0x800B48BC: ori         $t7, $t8, 0x8
    ctx->r15 = ctx->r24 | 0X8;
    // 0x800B48C0: sh          $t7, 0x3A($t6)
    MEM_H(0X3A, ctx->r14) = ctx->r15;
L_800B48C4:
    // 0x800B48C4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B48C8: nop

    // 0x800B48CC: lhu         $t9, 0xA($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0XA);
    // 0x800B48D0: nop

    // 0x800B48D4: andi        $t1, $t9, 0x800
    ctx->r9 = ctx->r25 & 0X800;
    // 0x800B48D8: beq         $t1, $zero, L_800B4914
    if (ctx->r9 == 0) {
        // 0x800B48DC: nop
    
            goto L_800B4914;
    }
    // 0x800B48DC: nop

    // 0x800B48E0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B48E4: nop

    // 0x800B48E8: lbu         $t0, 0x0($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X0);
    // 0x800B48EC: nop

    // 0x800B48F0: andi        $t3, $t0, 0x4
    ctx->r11 = ctx->r8 & 0X4;
    // 0x800B48F4: beq         $t3, $zero, L_800B4914
    if (ctx->r11 == 0) {
        // 0x800B48F8: nop
    
            goto L_800B4914;
    }
    // 0x800B48F8: nop

    // 0x800B48FC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800B4900: nop

    // 0x800B4904: lhu         $t8, 0x3A($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X3A);
    // 0x800B4908: nop

    // 0x800B490C: ori         $t7, $t8, 0x80
    ctx->r15 = ctx->r24 | 0X80;
    // 0x800B4910: sh          $t7, 0x3A($t5)
    MEM_H(0X3A, ctx->r13) = ctx->r15;
L_800B4914:
    // 0x800B4914: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4918: nop

    // 0x800B491C: lhu         $t4, 0xA($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0XA);
    // 0x800B4920: nop

    // 0x800B4924: andi        $t9, $t4, 0x4
    ctx->r25 = ctx->r12 & 0X4;
    // 0x800B4928: bne         $t9, $zero, L_800B49A0
    if (ctx->r25 != 0) {
        // 0x800B492C: nop
    
            goto L_800B49A0;
    }
    // 0x800B492C: nop

    // 0x800B4930: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B4934: nop

    // 0x800B4938: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800B493C: nop

    // 0x800B4940: andi        $t0, $t2, 0x1
    ctx->r8 = ctx->r10 & 0X1;
    // 0x800B4944: bne         $t0, $zero, L_800B4978
    if (ctx->r8 != 0) {
        // 0x800B4948: nop
    
            goto L_800B4978;
    }
    // 0x800B4948: nop

    // 0x800B494C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4950: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800B4954: lb          $t8, 0xC($t3)
    ctx->r24 = MEM_B(ctx->r11, 0XC);
    // 0x800B4958: lwc1        $f8, 0xF4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x800B495C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B4960: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800B4964: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4968: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B496C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800B4970: b           L_800B49A0
    // 0x800B4974: swc1        $f18, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f18.u32l;
        goto L_800B49A0;
    // 0x800B4974: swc1        $f18, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f18.u32l;
L_800B4978:
    // 0x800B4978: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800B497C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800B4980: lb          $t6, 0xC($t5)
    ctx->r14 = MEM_B(ctx->r13, 0XC);
    // 0x800B4984: lwc1        $f8, 0xF4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XF4);
    // 0x800B4988: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B498C: lwc1        $f10, 0xCC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800B4990: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4994: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B4998: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B499C: swc1        $f18, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f18.u32l;
L_800B49A0:
    // 0x800B49A0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B49A4: nop

    // 0x800B49A8: lhu         $t1, 0xA($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0XA);
    // 0x800B49AC: nop

    // 0x800B49B0: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x800B49B4: bne         $t2, $zero, L_800B4A2C
    if (ctx->r10 != 0) {
        // 0x800B49B8: nop
    
            goto L_800B4A2C;
    }
    // 0x800B49B8: nop

    // 0x800B49BC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800B49C0: nop

    // 0x800B49C4: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x800B49C8: nop

    // 0x800B49CC: andi        $t8, $t3, 0x2
    ctx->r24 = ctx->r11 & 0X2;
    // 0x800B49D0: bne         $t8, $zero, L_800B4A04
    if (ctx->r24 != 0) {
        // 0x800B49D4: nop
    
            goto L_800B4A04;
    }
    // 0x800B49D4: nop

    // 0x800B49D8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B49DC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B49E0: lb          $t5, 0xD($t7)
    ctx->r13 = MEM_B(ctx->r15, 0XD);
    // 0x800B49E4: lwc1        $f8, 0xF8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XF8);
    // 0x800B49E8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800B49EC: lwc1        $f16, 0xD0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x800B49F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B49F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B49F8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800B49FC: b           L_800B4A2C
    // 0x800B4A00: swc1        $f18, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f18.u32l;
        goto L_800B4A2C;
    // 0x800B4A00: swc1        $f18, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f18.u32l;
L_800B4A04:
    // 0x800B4A04: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4A08: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800B4A0C: lb          $t9, 0xD($t4)
    ctx->r25 = MEM_B(ctx->r12, 0XD);
    // 0x800B4A10: lwc1        $f8, 0xF8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XF8);
    // 0x800B4A14: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B4A18: lwc1        $f10, 0xD0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x800B4A1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B4A20: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B4A24: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B4A28: swc1        $f18, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f18.u32l;
L_800B4A2C:
    // 0x800B4A2C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B4A30: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800B4A34: lbu         $t3, 0x4($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X4);
    // 0x800B4A38: lwc1        $f4, 0x34($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X34);
    // 0x800B4A3C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800B4A40: bgez        $t3, L_800B4A58
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B4A44: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800B4A58;
    }
    // 0x800B4A44: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B4A48: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B4A4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B4A50: nop

    // 0x800B4A54: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800B4A58:
    // 0x800B4A58: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B4A5C: swc1        $f16, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f16.u32l;
    // 0x800B4A60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B4A64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B4A68: jal         0x800B4AB4
    // 0x800B4A6C: nop

    func_800B4AB4(rdram, ctx);
        goto after_0;
    // 0x800B4A6C: nop

    after_0:
    // 0x800B4A70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B4A74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800B4A78: lhu         $a2, 0x2A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2A);
    // 0x800B4A7C: jal         0x800B4F68
    // 0x800B4A80: nop

    func_800B4F68(rdram, ctx);
        goto after_1;
    // 0x800B4A80: nop

    after_1:
    // 0x800B4A84: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800B4A88: addiu       $at, $zero, -0x2001
    ctx->r1 = ADD32(0, -0X2001);
    // 0x800B4A8C: lhu         $t7, 0x3A($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X3A);
    // 0x800B4A90: nop

    // 0x800B4A94: and         $t5, $t7, $at
    ctx->r13 = ctx->r15 & ctx->r1;
    // 0x800B4A98: sh          $t5, 0x3A($t8)
    MEM_H(0X3A, ctx->r24) = ctx->r13;
    // 0x800B4A9C: b           L_800B4AA4
    // 0x800B4AA0: nop

        goto L_800B4AA4;
    // 0x800B4AA0: nop

L_800B4AA4:
    // 0x800B4AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4AA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B4AAC: jr          $ra
    // 0x800B4AB0: nop

    return;
    // 0x800B4AB0: nop

;}
RECOMP_FUNC void func_80071574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071574: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071578: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007157C: nop

    // 0x80071580: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x80071584: nop

    // 0x80071588: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8007158C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80071590: jr          $ra
    // 0x80071594: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071594: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071598: jr          $ra
    // 0x8007159C: nop

    return;
    // 0x8007159C: nop

    // 0x800715A0: jr          $ra
    // 0x800715A4: nop

    return;
    // 0x800715A4: nop

;}
RECOMP_FUNC void func_80068E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E10: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80068E14: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80068E18: nop

    // 0x80068E1C: lh          $v0, 0x44($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X44);
    // 0x80068E20: nop

    // 0x80068E24: slti        $t7, $v0, 0x3E7
    ctx->r15 = SIGNED(ctx->r2) < 0X3E7 ? 1 : 0;
    // 0x80068E28: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80068E2C: jr          $ra
    // 0x80068E30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80068E30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80068E34: jr          $ra
    // 0x80068E38: nop

    return;
    // 0x80068E38: nop

    // 0x80068E3C: jr          $ra
    // 0x80068E40: nop

    return;
    // 0x80068E40: nop

;}
RECOMP_FUNC void func_80056274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056274: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80056278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005627C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80056280: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80056284: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80056288: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x8005628C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80056290: lw          $t7, 0x5C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X5C);
    // 0x80056294: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80056298: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8005629C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800562A0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800562A4: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x800562A8: lh          $a3, -0x28C0($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X28C0);
    // 0x800562AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800562B0: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800562B4: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800562B8: ori         $t1, $a3, 0x14B
    ctx->r9 = ctx->r7 | 0X14B;
    // 0x800562BC: jal         0x800B3230
    // 0x800562C0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    func_800B3230(rdram, ctx);
        goto after_0;
    // 0x800562C0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    after_0:
    // 0x800562C4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800562C8: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x800562CC: nop

    // 0x800562D0: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x800562D4: lwc1        $f4, 0xC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800562D8: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800562DC: nop

    // 0x800562E0: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800562E4: nop

    // 0x800562E8: bc1f        L_80056318
    if (!c1cs) {
        // 0x800562EC: nop
    
            goto L_80056318;
    }
    // 0x800562EC: nop

    // 0x800562F0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800562F4: nop

    // 0x800562F8: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800562FC: nop

    // 0x80056300: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80056304: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80056308: nop

    // 0x8005630C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80056310: b           L_80056338
    // 0x80056314: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
        goto L_80056338;
    // 0x80056314: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
L_80056318:
    // 0x80056318: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8005631C: nop

    // 0x80056320: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80056324: nop

    // 0x80056328: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8005632C: nop

    // 0x80056330: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80056334: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
L_80056338:
    // 0x80056338: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005633C: nop

    // 0x80056340: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80056344: nop

    // 0x80056348: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8005634C: nop

    // 0x80056350: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80056354: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80056358: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005635C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80056360: nop

    // 0x80056364: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80056368: nop

    // 0x8005636C: bc1f        L_80056388
    if (!c1cs) {
        // 0x80056370: nop
    
            goto L_80056388;
    }
    // 0x80056370: nop

    // 0x80056374: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80056378: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005637C: nop

    // 0x80056380: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80056384: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
L_80056388:
    // 0x80056388: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005638C: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80056390: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80056394: lw          $t2, 0x5C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X5C);
    // 0x80056398: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8005639C: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800563A0: nop

    // 0x800563A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800563A8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800563AC: nop

    // 0x800563B0: bc1f        L_800563C4
    if (!c1cs) {
        // 0x800563B4: nop
    
            goto L_800563C4;
    }
    // 0x800563B4: nop

    // 0x800563B8: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800563BC: b           L_800563E8
    // 0x800563C0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
        goto L_800563E8;
    // 0x800563C0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
L_800563C4:
    // 0x800563C4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800563C8: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800563CC: nop

    // 0x800563D0: lw          $t4, 0x5C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X5C);
    // 0x800563D4: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800563D8: lwc1        $f10, 0x8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800563DC: nop

    // 0x800563E0: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800563E4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
L_800563E8:
    // 0x800563E8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800563EC: lh          $t5, 0x7234($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7234);
    // 0x800563F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800563F4: bne         $t5, $at, L_80056430
    if (ctx->r13 != ctx->r1) {
        // 0x800563F8: nop
    
            goto L_80056430;
    }
    // 0x800563F8: nop

    // 0x800563FC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80056400: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x80056404: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80056408: bne         $t6, $at, L_80056430
    if (ctx->r14 != ctx->r1) {
        // 0x8005640C: nop
    
            goto L_80056430;
    }
    // 0x8005640C: nop

    // 0x80056410: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80056414: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80056418: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005641C: lw          $t8, 0x5C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X5C);
    // 0x80056420: nop

    // 0x80056424: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80056428: b           L_80056580
    // 0x8005642C: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
        goto L_80056580;
    // 0x8005642C: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
L_80056430:
    // 0x80056430: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80056434: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80056438: nop

    // 0x8005643C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80056440: nop

    // 0x80056444: bc1f        L_80056558
    if (!c1cs) {
        // 0x80056448: nop
    
            goto L_80056558;
    }
    // 0x80056448: nop

    // 0x8005644C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80056450: lw          $t9, 0xE64($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XE64);
    // 0x80056454: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80056458: lw          $t0, 0x5C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X5C);
    // 0x8005645C: nop

    // 0x80056460: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80056464: nop

    // 0x80056468: bne         $t1, $at, L_80056480
    if (ctx->r9 != ctx->r1) {
        // 0x8005646C: nop
    
            goto L_80056480;
    }
    // 0x8005646C: nop

    // 0x80056470: jal         0x8005A578
    // 0x80056474: nop

    func_8005A578(rdram, ctx);
        goto after_1;
    // 0x80056474: nop

    after_1:
    // 0x80056478: beq         $v0, $zero, L_80056558
    if (ctx->r2 == 0) {
        // 0x8005647C: nop
    
            goto L_80056558;
    }
    // 0x8005647C: nop

L_80056480:
    // 0x80056480: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80056484: lw          $t2, 0xE64($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XE64);
    // 0x80056488: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8005648C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80056490: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80056494: nop

    // 0x80056498: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8005649C: nop

    // 0x800564A0: bc1f        L_800564C4
    if (!c1cs) {
        // 0x800564A4: nop
    
            goto L_800564C4;
    }
    // 0x800564A4: nop

    // 0x800564A8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800564AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800564B0: nop

    // 0x800564B4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800564B8: nop

    // 0x800564BC: bc1t        L_80056558
    if (c1cs) {
        // 0x800564C0: nop
    
            goto L_80056558;
    }
    // 0x800564C0: nop

L_800564C4:
    // 0x800564C4: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800564C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800564CC: nop

    // 0x800564D0: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800564D4: nop

    // 0x800564D8: bc1f        L_80056504
    if (!c1cs) {
        // 0x800564DC: nop
    
            goto L_80056504;
    }
    // 0x800564DC: nop

    // 0x800564E0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800564E4: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x800564E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800564EC: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800564F0: nop

    // 0x800564F4: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800564F8: nop

    // 0x800564FC: bc1t        L_80056544
    if (c1cs) {
        // 0x80056500: nop
    
            goto L_80056544;
    }
    // 0x80056500: nop

L_80056504:
    // 0x80056504: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056508: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005650C: nop

    // 0x80056510: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80056514: nop

    // 0x80056518: bc1f        L_80056558
    if (!c1cs) {
        // 0x8005651C: nop
    
            goto L_80056558;
    }
    // 0x8005651C: nop

    // 0x80056520: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80056524: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80056528: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005652C: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80056530: nop

    // 0x80056534: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80056538: nop

    // 0x8005653C: bc1f        L_80056558
    if (!c1cs) {
        // 0x80056540: nop
    
            goto L_80056558;
    }
    // 0x80056540: nop

L_80056544:
    // 0x80056544: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80056548: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005654C: nop

    // 0x80056550: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80056554: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
L_80056558:
    // 0x80056558: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8005655C: lw          $t5, 0xE64($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XE64);
    // 0x80056560: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80056564: lw          $t6, 0x5C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X5C);
    // 0x80056568: nop

    // 0x8005656C: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80056570: b           L_80056580
    // 0x80056574: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
        goto L_80056580;
    // 0x80056574: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80056578: b           L_80056580
    // 0x8005657C: nop

        goto L_80056580;
    // 0x8005657C: nop

L_80056580:
    // 0x80056580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80056588: jr          $ra
    // 0x8005658C: nop

    return;
    // 0x8005658C: nop

;}
RECOMP_FUNC void func_8006620C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006620C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066214: jal         0x80061348
    // 0x80066218: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066218: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006621C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066220: b           L_80066230
    // 0x80066224: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066230;
    // 0x80066224: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066228: b           L_80066230
    // 0x8006622C: nop

        goto L_80066230;
    // 0x8006622C: nop

L_80066230:
    // 0x80066230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066238: jr          $ra
    // 0x8006623C: nop

    return;
    // 0x8006623C: nop

;}
RECOMP_FUNC void func_80076F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076F58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076F60: jal         0x80061488
    // 0x80076F64: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076F64: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076F68: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076F6C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076F70: b           L_80076F80
    // 0x80076F74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076F80;
    // 0x80076F74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076F78: b           L_80076F80
    // 0x80076F7C: nop

        goto L_80076F80;
    // 0x80076F7C: nop

L_80076F80:
    // 0x80076F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076F88: jr          $ra
    // 0x80076F8C: nop

    return;
    // 0x80076F8C: nop

;}
RECOMP_FUNC void func_80063AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063AC0: jal         0x8005F064
    // 0x80063AC4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063AC4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063AC8: b           L_80063AD8
    // 0x80063ACC: nop

        goto L_80063AD8;
    // 0x80063ACC: nop

    // 0x80063AD0: b           L_80063AD8
    // 0x80063AD4: nop

        goto L_80063AD8;
    // 0x80063AD4: nop

L_80063AD8:
    // 0x80063AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063AE0: jr          $ra
    // 0x80063AE4: nop

    return;
    // 0x80063AE4: nop

;}
RECOMP_FUNC void func_8006D498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D49C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D4A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D4A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D4A8: nop

    // 0x8006D4AC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D4B0: nop

    // 0x8006D4B4: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006D4B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D4BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D4C0: beq         $v0, $zero, L_8006D4F4
    if (ctx->r2 == 0) {
        // 0x8006D4C4: nop
    
            goto L_8006D4F4;
    }
    // 0x8006D4C4: nop

    // 0x8006D4C8: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x8006D4CC: nop

    // 0x8006D4D0: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006D4D4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006D4D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006D4DC: beq         $v0, $zero, L_8006D4F4
    if (ctx->r2 == 0) {
        // 0x8006D4E0: nop
    
            goto L_8006D4F4;
    }
    // 0x8006D4E0: nop

    // 0x8006D4E4: jal         0x8005F064
    // 0x8006D4E8: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006D4E8: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    after_0:
    // 0x8006D4EC: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006D4F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006D4F4:
    // 0x8006D4F4: b           L_8006D504
    // 0x8006D4F8: nop

        goto L_8006D504;
    // 0x8006D4F8: nop

    // 0x8006D4FC: b           L_8006D504
    // 0x8006D500: nop

        goto L_8006D504;
    // 0x8006D500: nop

L_8006D504:
    // 0x8006D504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D50C: jr          $ra
    // 0x8006D510: nop

    return;
    // 0x8006D510: nop

;}
