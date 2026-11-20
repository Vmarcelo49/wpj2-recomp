#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80066E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066EA0: jal         0x80061348
    // 0x80066EA4: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066EA4: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    after_0:
    // 0x80066EA8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066EAC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066EB0: b           L_80066EC0
    // 0x80066EB4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066EC0;
    // 0x80066EB4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066EB8: b           L_80066EC0
    // 0x80066EBC: nop

        goto L_80066EC0;
    // 0x80066EBC: nop

L_80066EC0:
    // 0x80066EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066EC8: jr          $ra
    // 0x80066ECC: nop

    return;
    // 0x80066ECC: nop

;}
RECOMP_FUNC void func_80066ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066ED8: jal         0x80061488
    // 0x80066EDC: addiu       $a0, $zero, 0x256
    ctx->r4 = ADD32(0, 0X256);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80066EDC: addiu       $a0, $zero, 0x256
    ctx->r4 = ADD32(0, 0X256);
    after_0:
    // 0x80066EE0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80066EE4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80066EE8: b           L_80066EF8
    // 0x80066EEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066EF8;
    // 0x80066EEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066EF0: b           L_80066EF8
    // 0x80066EF4: nop

        goto L_80066EF8;
    // 0x80066EF4: nop

L_80066EF8:
    // 0x80066EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066F00: jr          $ra
    // 0x80066F04: nop

    return;
    // 0x80066F04: nop

;}
RECOMP_FUNC void func_80066F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066F10: jal         0x80061348
    // 0x80066F14: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066F14: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_0:
    // 0x80066F18: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066F20: bne         $v0, $zero, L_80066F68
    if (ctx->r2 != 0) {
        // 0x80066F24: nop

            goto L_80066F68;
    }
    // 0x80066F24: nop

    // 0x80066F28: jal         0x80061348
    // 0x80066F2C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066F2C: addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    after_1:
    // 0x80066F30: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F34: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066F38: bne         $v0, $zero, L_80066F68
    if (ctx->r2 != 0) {
        // 0x80066F3C: nop

            goto L_80066F68;
    }
    // 0x80066F3C: nop

    // 0x80066F40: jal         0x80061348
    // 0x80066F44: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80066F44: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_2:
    // 0x80066F48: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F4C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80066F50: bne         $v0, $zero, L_80066F68
    if (ctx->r2 != 0) {
        // 0x80066F54: nop

            goto L_80066F68;
    }
    // 0x80066F54: nop

    // 0x80066F58: jal         0x80061348
    // 0x80066F5C: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80066F5C: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_3:
    // 0x80066F60: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F64: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80066F68:
    // 0x80066F68: b           L_80066F78
    // 0x80066F6C: nop

        goto L_80066F78;
    // 0x80066F6C: nop

    // 0x80066F70: b           L_80066F78
    // 0x80066F74: nop

        goto L_80066F78;
    // 0x80066F74: nop

L_80066F78:
    // 0x80066F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066F80: jr          $ra
    // 0x80066F84: nop

    return;
    // 0x80066F84: nop

;}
RECOMP_FUNC void func_80066F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066F90: jal         0x80061348
    // 0x80066F94: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066F94: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x80066F98: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066F9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066FA0: bne         $v0, $zero, L_80066FE8
    if (ctx->r2 != 0) {
        // 0x80066FA4: nop

            goto L_80066FE8;
    }
    // 0x80066FA4: nop

    // 0x80066FA8: jal         0x80061348
    // 0x80066FAC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066FAC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_1:
    // 0x80066FB0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066FB4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066FB8: bne         $v0, $zero, L_80066FE8
    if (ctx->r2 != 0) {
        // 0x80066FBC: nop

            goto L_80066FE8;
    }
    // 0x80066FBC: nop

    // 0x80066FC0: jal         0x80061348
    // 0x80066FC4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80066FC4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_2:
    // 0x80066FC8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066FCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80066FD0: bne         $v0, $zero, L_80066FE8
    if (ctx->r2 != 0) {
        // 0x80066FD4: nop

            goto L_80066FE8;
    }
    // 0x80066FD4: nop

    // 0x80066FD8: jal         0x80061348
    // 0x80066FDC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80066FDC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_3:
    // 0x80066FE0: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066FE4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80066FE8:
    // 0x80066FE8: b           L_80066FF8
    // 0x80066FEC: nop

        goto L_80066FF8;
    // 0x80066FEC: nop

    // 0x80066FF0: b           L_80066FF8
    // 0x80066FF4: nop

        goto L_80066FF8;
    // 0x80066FF4: nop

L_80066FF8:
    // 0x80066FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067000: jr          $ra
    // 0x80067004: nop

    return;
    // 0x80067004: nop

;}
RECOMP_FUNC void func_80067008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067008: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006700C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067010: nop

    // 0x80067014: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80067018: nop

    // 0x8006701C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067020: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067024: jr          $ra
    // 0x80067028: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067028: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006702C: jr          $ra
    // 0x80067030: nop

    return;
    // 0x80067030: nop

    // 0x80067034: jr          $ra
    // 0x80067038: nop

    return;
    // 0x80067038: nop

;}
RECOMP_FUNC void func_8006703C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006703C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067044: jal         0x80061488
    // 0x80067048: addiu       $a0, $zero, 0x264
    ctx->r4 = ADD32(0, 0X264);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067048: addiu       $a0, $zero, 0x264
    ctx->r4 = ADD32(0, 0X264);
    after_0:
    // 0x8006704C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067050: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067054: b           L_80067064
    // 0x80067058: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067064;
    // 0x80067058: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006705C: b           L_80067064
    // 0x80067060: nop

        goto L_80067064;
    // 0x80067060: nop

L_80067064:
    // 0x80067064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006706C: jr          $ra
    // 0x80067070: nop

    return;
    // 0x80067070: nop

;}
RECOMP_FUNC void func_80067074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067074: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067078: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006707C: nop

    // 0x80067080: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x80067084: nop

    // 0x80067088: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006708C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067090: jr          $ra
    // 0x80067094: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067094: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067098: jr          $ra
    // 0x8006709C: nop

    return;
    // 0x8006709C: nop

    // 0x800670A0: jr          $ra
    // 0x800670A4: nop

    return;
    // 0x800670A4: nop

;}
RECOMP_FUNC void func_800670A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800670A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800670AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800670B0: nop

    // 0x800670B4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800670B8: nop

    // 0x800670BC: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x800670C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800670C4: jr          $ra
    // 0x800670C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800670C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800670CC: jr          $ra
    // 0x800670D0: nop

    return;
    // 0x800670D0: nop

    // 0x800670D4: jr          $ra
    // 0x800670D8: nop

    return;
    // 0x800670D8: nop

;}
RECOMP_FUNC void func_800670DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800670DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800670E0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800670E4: nop

    // 0x800670E8: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800670EC: nop

    // 0x800670F0: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x800670F4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800670F8: jr          $ra
    // 0x800670FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800670FC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067100: jr          $ra
    // 0x80067104: nop

    return;
    // 0x80067104: nop

    // 0x80067108: jr          $ra
    // 0x8006710C: nop

    return;
    // 0x8006710C: nop

;}
RECOMP_FUNC void func_80067110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067110: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067114: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067118: nop

    // 0x8006711C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80067120: nop

    // 0x80067124: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80067128: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006712C: jr          $ra
    // 0x80067130: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067130: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067134: jr          $ra
    // 0x80067138: nop

    return;
    // 0x80067138: nop

    // 0x8006713C: jr          $ra
    // 0x80067140: nop

    return;
    // 0x80067140: nop

;}
RECOMP_FUNC void func_80067144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006714C: jal         0x80061488
    // 0x80067150: addiu       $a0, $zero, 0x2D9
    ctx->r4 = ADD32(0, 0X2D9);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067150: addiu       $a0, $zero, 0x2D9
    ctx->r4 = ADD32(0, 0X2D9);
    after_0:
    // 0x80067154: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80067158: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006715C: b           L_8006716C
    // 0x80067160: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006716C;
    // 0x80067160: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067164: b           L_8006716C
    // 0x80067168: nop

        goto L_8006716C;
    // 0x80067168: nop

L_8006716C:
    // 0x8006716C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067174: jr          $ra
    // 0x80067178: nop

    return;
    // 0x80067178: nop

;}
RECOMP_FUNC void func_8006717C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006717C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067184: jal         0x80061488
    // 0x80067188: addiu       $a0, $zero, 0x2D3
    ctx->r4 = ADD32(0, 0X2D3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067188: addiu       $a0, $zero, 0x2D3
    ctx->r4 = ADD32(0, 0X2D3);
    after_0:
    // 0x8006718C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80067190: b           L_800671A0
    // 0x80067194: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800671A0;
    // 0x80067194: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067198: b           L_800671A0
    // 0x8006719C: nop

        goto L_800671A0;
    // 0x8006719C: nop

L_800671A0:
    // 0x800671A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800671A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800671A8: jr          $ra
    // 0x800671AC: nop

    return;
    // 0x800671AC: nop

;}
RECOMP_FUNC void func_800671B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800671B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800671B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800671B8: jal         0x80061488
    // 0x800671BC: addiu       $a0, $zero, 0x2DD
    ctx->r4 = ADD32(0, 0X2DD);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800671BC: addiu       $a0, $zero, 0x2DD
    ctx->r4 = ADD32(0, 0X2DD);
    after_0:
    // 0x800671C0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800671C4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800671C8: b           L_800671D8
    // 0x800671CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800671D8;
    // 0x800671CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800671D0: b           L_800671D8
    // 0x800671D4: nop

        goto L_800671D8;
    // 0x800671D4: nop

L_800671D8:
    // 0x800671D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800671DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800671E0: jr          $ra
    // 0x800671E4: nop

    return;
    // 0x800671E4: nop

;}
RECOMP_FUNC void func_800671E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800671E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800671EC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800671F0: nop

    // 0x800671F4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x800671F8: nop

    // 0x800671FC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067200: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067204: jr          $ra
    // 0x80067208: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067208: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006720C: jr          $ra
    // 0x80067210: nop

    return;
    // 0x80067210: nop

    // 0x80067214: jr          $ra
    // 0x80067218: nop

    return;
    // 0x80067218: nop

;}
RECOMP_FUNC void func_8006721C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006721C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067224: jal         0x80061488
    // 0x80067228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8006722C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067230: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067234: b           L_80067244
    // 0x80067238: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067244;
    // 0x80067238: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006723C: b           L_80067244
    // 0x80067240: nop

        goto L_80067244;
    // 0x80067240: nop

L_80067244:
    // 0x80067244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006724C: jr          $ra
    // 0x80067250: nop

    return;
    // 0x80067250: nop

;}
RECOMP_FUNC void func_80067254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006725C: jal         0x80061488
    // 0x80067260: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067260: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80067264: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067268: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006726C: b           L_8006727C
    // 0x80067270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006727C;
    // 0x80067270: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067274: b           L_8006727C
    // 0x80067278: nop

        goto L_8006727C;
    // 0x80067278: nop

L_8006727C:
    // 0x8006727C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067284: jr          $ra
    // 0x80067288: nop

    return;
    // 0x80067288: nop

;}
RECOMP_FUNC void func_8006728C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006728C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067294: jal         0x80061488
    // 0x80067298: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067298: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x8006729C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800672A0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800672A4: b           L_800672B4
    // 0x800672A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800672B4;
    // 0x800672A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800672AC: b           L_800672B4
    // 0x800672B0: nop

        goto L_800672B4;
    // 0x800672B0: nop

L_800672B4:
    // 0x800672B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800672B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800672BC: jr          $ra
    // 0x800672C0: nop

    return;
    // 0x800672C0: nop

;}
RECOMP_FUNC void func_800672C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800672C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800672C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800672CC: jal         0x80061488
    // 0x800672D0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800672D0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x800672D4: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800672D8: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800672DC: b           L_800672EC
    // 0x800672E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800672EC;
    // 0x800672E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800672E4: b           L_800672EC
    // 0x800672E8: nop

        goto L_800672EC;
    // 0x800672E8: nop

L_800672EC:
    // 0x800672EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800672F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800672F4: jr          $ra
    // 0x800672F8: nop

    return;
    // 0x800672F8: nop

;}
RECOMP_FUNC void func_800672FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800672FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067304: jal         0x80061488
    // 0x80067308: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067308: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8006730C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067310: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067314: b           L_80067324
    // 0x80067318: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067324;
    // 0x80067318: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006731C: b           L_80067324
    // 0x80067320: nop

        goto L_80067324;
    // 0x80067320: nop

L_80067324:
    // 0x80067324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006732C: jr          $ra
    // 0x80067330: nop

    return;
    // 0x80067330: nop

;}
RECOMP_FUNC void func_80067334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067334: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067338: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006733C: nop

    // 0x80067340: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x80067344: nop

    // 0x80067348: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006734C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067350: jr          $ra
    // 0x80067354: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067354: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067358: jr          $ra
    // 0x8006735C: nop

    return;
    // 0x8006735C: nop

    // 0x80067360: jr          $ra
    // 0x80067364: nop

    return;
    // 0x80067364: nop

;}
RECOMP_FUNC void func_80067368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067368: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006736C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067370: nop

    // 0x80067374: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80067378: nop

    // 0x8006737C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067380: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067384: jr          $ra
    // 0x80067388: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067388: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006738C: jr          $ra
    // 0x80067390: nop

    return;
    // 0x80067390: nop

    // 0x80067394: jr          $ra
    // 0x80067398: nop

    return;
    // 0x80067398: nop

;}
RECOMP_FUNC void func_8006739C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006739C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800673A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800673A4: jal         0x80061488
    // 0x800673A8: addiu       $a0, $zero, 0x2E3
    ctx->r4 = ADD32(0, 0X2E3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800673A8: addiu       $a0, $zero, 0x2E3
    ctx->r4 = ADD32(0, 0X2E3);
    after_0:
    // 0x800673AC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800673B0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800673B4: b           L_800673C4
    // 0x800673B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800673C4;
    // 0x800673B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800673BC: b           L_800673C4
    // 0x800673C0: nop

        goto L_800673C4;
    // 0x800673C0: nop

L_800673C4:
    // 0x800673C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800673C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800673CC: jr          $ra
    // 0x800673D0: nop

    return;
    // 0x800673D0: nop

;}
RECOMP_FUNC void func_800673D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800673D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800673D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800673DC: nop

    // 0x800673E0: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x800673E4: nop

    // 0x800673E8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800673EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800673F0: jr          $ra
    // 0x800673F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800673F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800673F8: jr          $ra
    // 0x800673FC: nop

    return;
    // 0x800673FC: nop

    // 0x80067400: jr          $ra
    // 0x80067404: nop

    return;
    // 0x80067404: nop

;}
RECOMP_FUNC void func_80067408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067408: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006740C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067410: nop

    // 0x80067414: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x80067418: nop

    // 0x8006741C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067420: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067424: jr          $ra
    // 0x80067428: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067428: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006742C: jr          $ra
    // 0x80067430: nop

    return;
    // 0x80067430: nop

    // 0x80067434: jr          $ra
    // 0x80067438: nop

    return;
    // 0x80067438: nop

;}
RECOMP_FUNC void func_8006743C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006743C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067440: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067444: nop

    // 0x80067448: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006744C: nop

    // 0x80067450: slti        $t7, $v0, 0x258
    ctx->r15 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x80067454: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067458: jr          $ra
    // 0x8006745C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006745C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067460: jr          $ra
    // 0x80067464: nop

    return;
    // 0x80067464: nop

    // 0x80067468: jr          $ra
    // 0x8006746C: nop

    return;
    // 0x8006746C: nop

;}
RECOMP_FUNC void func_80067470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067478: jal         0x80061488
    // 0x8006747C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006747C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_0:
    // 0x80067480: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067484: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80067488: b           L_80067498
    // 0x8006748C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067498;
    // 0x8006748C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067490: b           L_80067498
    // 0x80067494: nop

        goto L_80067498;
    // 0x80067494: nop

L_80067498:
    // 0x80067498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006749C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800674A0: jr          $ra
    // 0x800674A4: nop

    return;
    // 0x800674A4: nop

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
RECOMP_FUNC void func_800674E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800674E0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800674E4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800674E8: nop

    // 0x800674EC: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x800674F0: nop

    // 0x800674F4: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x800674F8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800674FC: jr          $ra
    // 0x80067500: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067500: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067504: jr          $ra
    // 0x80067508: nop

    return;
    // 0x80067508: nop

    // 0x8006750C: jr          $ra
    // 0x80067510: nop

    return;
    // 0x80067510: nop

;}
RECOMP_FUNC void func_80067514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006751C: jal         0x80061488
    // 0x80067520: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067520: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80067524: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80067528: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006752C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067530: beq         $v0, $zero, L_80067548
    if (ctx->r2 == 0) {
        // 0x80067534: nop

            goto L_80067548;
    }
    // 0x80067534: nop

    // 0x80067538: jal         0x80061348
    // 0x8006753C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006753C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_1:
    // 0x80067540: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80067544: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80067548:
    // 0x80067548: b           L_80067558
    // 0x8006754C: nop

        goto L_80067558;
    // 0x8006754C: nop

    // 0x80067550: b           L_80067558
    // 0x80067554: nop

        goto L_80067558;
    // 0x80067554: nop

L_80067558:
    // 0x80067558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006755C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067560: jr          $ra
    // 0x80067564: nop

    return;
    // 0x80067564: nop

;}
RECOMP_FUNC void func_80067568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067568: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006756C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067570: nop

    // 0x80067574: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067578: nop

    // 0x8006757C: slti        $t7, $v0, 0x32
    ctx->r15 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x80067580: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067584: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067588: beq         $v0, $zero, L_800675A4
    if (ctx->r2 == 0) {
        // 0x8006758C: nop

            goto L_800675A4;
    }
    // 0x8006758C: nop

    // 0x80067590: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067594: nop

    // 0x80067598: slti        $t8, $v0, 0x32
    ctx->r24 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8006759C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800675A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800675A4:
    // 0x800675A4: jr          $ra
    // 0x800675A8: nop

    return;
    // 0x800675A8: nop

    // 0x800675AC: jr          $ra
    // 0x800675B0: nop

    return;
    // 0x800675B0: nop

    // 0x800675B4: jr          $ra
    // 0x800675B8: nop

    return;
    // 0x800675B8: nop

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
RECOMP_FUNC void func_80067624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006762C: jal         0x80061488
    // 0x80067630: addiu       $a0, $zero, 0x2F4
    ctx->r4 = ADD32(0, 0X2F4);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067630: addiu       $a0, $zero, 0x2F4
    ctx->r4 = ADD32(0, 0X2F4);
    after_0:
    // 0x80067634: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80067638: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006763C: b           L_8006764C
    // 0x80067640: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006764C;
    // 0x80067640: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067644: b           L_8006764C
    // 0x80067648: nop

        goto L_8006764C;
    // 0x80067648: nop

L_8006764C:
    // 0x8006764C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067654: jr          $ra
    // 0x80067658: nop

    return;
    // 0x80067658: nop

;}
RECOMP_FUNC void func_8006765C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006765C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067660: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067664: nop

    // 0x80067668: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x8006766C: nop

    // 0x80067670: slti        $t7, $v0, 0x96
    ctx->r15 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067674: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067678: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006767C: beq         $v0, $zero, L_80067698
    if (ctx->r2 == 0) {
        // 0x80067680: nop

            goto L_80067698;
    }
    // 0x80067680: nop

    // 0x80067684: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067688: nop

    // 0x8006768C: slti        $t8, $v0, 0x96
    ctx->r24 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067690: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80067694: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067698:
    // 0x80067698: jr          $ra
    // 0x8006769C: nop

    return;
    // 0x8006769C: nop

    // 0x800676A0: jr          $ra
    // 0x800676A4: nop

    return;
    // 0x800676A4: nop

    // 0x800676A8: jr          $ra
    // 0x800676AC: nop

    return;
    // 0x800676AC: nop

;}
RECOMP_FUNC void func_800676B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800676B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800676B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800676B8: nop

    // 0x800676BC: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800676C0: nop

    // 0x800676C4: slti        $t7, $v0, 0xC8
    ctx->r15 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x800676C8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800676CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800676D0: beq         $v0, $zero, L_800676EC
    if (ctx->r2 == 0) {
        // 0x800676D4: nop

            goto L_800676EC;
    }
    // 0x800676D4: nop

    // 0x800676D8: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800676DC: nop

    // 0x800676E0: slti        $t8, $v0, 0xC8
    ctx->r24 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x800676E4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800676E8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800676EC:
    // 0x800676EC: jr          $ra
    // 0x800676F0: nop

    return;
    // 0x800676F0: nop

    // 0x800676F4: jr          $ra
    // 0x800676F8: nop

    return;
    // 0x800676F8: nop

    // 0x800676FC: jr          $ra
    // 0x80067700: nop

    return;
    // 0x80067700: nop

;}
RECOMP_FUNC void func_80067704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067704: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067708: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006770C: nop

    // 0x80067710: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067714: nop

    // 0x80067718: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006771C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067720: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067724: beq         $v0, $zero, L_80067740
    if (ctx->r2 == 0) {
        // 0x80067728: nop

            goto L_80067740;
    }
    // 0x80067728: nop

    // 0x8006772C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067730: nop

    // 0x80067734: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067738: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006773C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067740:
    // 0x80067740: jr          $ra
    // 0x80067744: nop

    return;
    // 0x80067744: nop

    // 0x80067748: jr          $ra
    // 0x8006774C: nop

    return;
    // 0x8006774C: nop

    // 0x80067750: jr          $ra
    // 0x80067754: nop

    return;
    // 0x80067754: nop

;}
RECOMP_FUNC void func_80067758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006775C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067760: jal         0x80061348
    // 0x80067764: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067764: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80067768: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006776C: b           L_8006777C
    // 0x80067770: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006777C;
    // 0x80067770: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067774: b           L_8006777C
    // 0x80067778: nop

        goto L_8006777C;
    // 0x80067778: nop

L_8006777C:
    // 0x8006777C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067784: jr          $ra
    // 0x80067788: nop

    return;
    // 0x80067788: nop

;}
RECOMP_FUNC void func_8006778C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006778C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067794: jal         0x80061348
    // 0x80067798: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067798: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x8006779C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800677A0: b           L_800677B0
    // 0x800677A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800677B0;
    // 0x800677A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800677A8: b           L_800677B0
    // 0x800677AC: nop

        goto L_800677B0;
    // 0x800677AC: nop

L_800677B0:
    // 0x800677B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800677B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800677B8: jr          $ra
    // 0x800677BC: nop

    return;
    // 0x800677BC: nop

;}
RECOMP_FUNC void func_800677C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800677C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800677C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800677C8: jal         0x80061348
    // 0x800677CC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800677CC: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x800677D0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800677D4: b           L_800677E4
    // 0x800677D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800677E4;
    // 0x800677D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800677DC: b           L_800677E4
    // 0x800677E0: nop

        goto L_800677E4;
    // 0x800677E0: nop

L_800677E4:
    // 0x800677E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800677E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800677EC: jr          $ra
    // 0x800677F0: nop

    return;
    // 0x800677F0: nop

;}
RECOMP_FUNC void func_800677F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800677F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800677F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800677FC: jal         0x80061348
    // 0x80067800: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067800: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80067804: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80067808: b           L_80067818
    // 0x8006780C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80067818;
    // 0x8006780C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067810: b           L_80067818
    // 0x80067814: nop

        goto L_80067818;
    // 0x80067814: nop

L_80067818:
    // 0x80067818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006781C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067820: jr          $ra
    // 0x80067824: nop

    return;
    // 0x80067824: nop

;}
RECOMP_FUNC void func_80067828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006782C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067830: jal         0x80061348
    // 0x80067834: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80067834: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80067838: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006783C: b           L_8006784C
    // 0x80067840: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006784C;
    // 0x80067840: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80067844: b           L_8006784C
    // 0x80067848: nop

        goto L_8006784C;
    // 0x80067848: nop

L_8006784C:
    // 0x8006784C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067854: jr          $ra
    // 0x80067858: nop

    return;
    // 0x80067858: nop

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
RECOMP_FUNC void func_80067890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067898: jal         0x80061488
    // 0x8006789C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006789C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x800678A0: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x800678A4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800678A8: b           L_800678B8
    // 0x800678AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800678B8;
    // 0x800678AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800678B0: b           L_800678B8
    // 0x800678B4: nop

        goto L_800678B8;
    // 0x800678B4: nop

L_800678B8:
    // 0x800678B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800678BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800678C0: jr          $ra
    // 0x800678C4: nop

    return;
    // 0x800678C4: nop

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
RECOMP_FUNC void func_80067900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067900: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067904: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067908: nop

    // 0x8006790C: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80067910: nop

    // 0x80067914: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80067918: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006791C: jr          $ra
    // 0x80067920: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067920: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067924: jr          $ra
    // 0x80067928: nop

    return;
    // 0x80067928: nop

    // 0x8006792C: jr          $ra
    // 0x80067930: nop

    return;
    // 0x80067930: nop

;}
RECOMP_FUNC void func_80067934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067934: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067938: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006793C: nop

    // 0x80067940: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80067944: nop

    // 0x80067948: slti        $t7, $v0, 0x96
    ctx->r15 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x8006794C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067950: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067954: beq         $v0, $zero, L_80067970
    if (ctx->r2 == 0) {
        // 0x80067958: nop

            goto L_80067970;
    }
    // 0x80067958: nop

    // 0x8006795C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80067960: nop

    // 0x80067964: slti        $t8, $v0, 0x96
    ctx->r24 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80067968: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006796C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80067970:
    // 0x80067970: jr          $ra
    // 0x80067974: nop

    return;
    // 0x80067974: nop

    // 0x80067978: jr          $ra
    // 0x8006797C: nop

    return;
    // 0x8006797C: nop

    // 0x80067980: jr          $ra
    // 0x80067984: nop

    return;
    // 0x80067984: nop

;}
RECOMP_FUNC void func_80067988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006798C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067990: jal         0x80061488
    // 0x80067994: addiu       $a0, $zero, 0x309
    ctx->r4 = ADD32(0, 0X309);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80067994: addiu       $a0, $zero, 0x309
    ctx->r4 = ADD32(0, 0X309);
    after_0:
    // 0x80067998: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006799C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800679A0: b           L_800679B0
    // 0x800679A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800679B0;
    // 0x800679A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800679A8: b           L_800679B0
    // 0x800679AC: nop

        goto L_800679B0;
    // 0x800679AC: nop

L_800679B0:
    // 0x800679B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800679B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800679B8: jr          $ra
    // 0x800679BC: nop

    return;
    // 0x800679BC: nop

;}
RECOMP_FUNC void func_800679C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800679C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800679C8: nop

    // 0x800679CC: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800679D0: nop

    // 0x800679D4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800679D8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800679DC: jr          $ra
    // 0x800679E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800679E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800679E4: jr          $ra
    // 0x800679E8: nop

    return;
    // 0x800679E8: nop

    // 0x800679EC: jr          $ra
    // 0x800679F0: nop

    return;
    // 0x800679F0: nop

;}
RECOMP_FUNC void func_800679F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800679F8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800679FC: nop

    // 0x80067A00: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x80067A04: nop

    // 0x80067A08: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067A0C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067A10: jr          $ra
    // 0x80067A14: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067A14: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067A18: jr          $ra
    // 0x80067A1C: nop

    return;
    // 0x80067A1C: nop

    // 0x80067A20: jr          $ra
    // 0x80067A24: nop

    return;
    // 0x80067A24: nop

;}
RECOMP_FUNC void func_80067A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A28: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80067A2C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80067A30: nop

    // 0x80067A34: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80067A38: nop

    // 0x80067A3C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80067A40: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80067A44: jr          $ra
    // 0x80067A48: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80067A48: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80067A4C: jr          $ra
    // 0x80067A50: nop

    return;
    // 0x80067A50: nop

    // 0x80067A54: jr          $ra
    // 0x80067A58: nop

    return;
    // 0x80067A58: nop

;}
