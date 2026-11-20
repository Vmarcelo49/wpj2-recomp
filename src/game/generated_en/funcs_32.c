#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80076EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076EE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076EF0: jal         0x80061488
    // 0x80076EF4: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076EF4: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076EF8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076EFC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076F00: b           L_80076F10
    // 0x80076F04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076F10;
    // 0x80076F04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076F08: b           L_80076F10
    // 0x80076F0C: nop

        goto L_80076F10;
    // 0x80076F0C: nop

L_80076F10:
    // 0x80076F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076F18: jr          $ra
    // 0x80076F1C: nop

    return;
    // 0x80076F1C: nop

;}
RECOMP_FUNC void func_80076F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076F28: jal         0x80061488
    // 0x80076F2C: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076F2C: addiu       $a0, $zero, 0x653
    ctx->r4 = ADD32(0, 0X653);
    after_0:
    // 0x80076F30: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80076F34: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80076F38: b           L_80076F48
    // 0x80076F3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076F48;
    // 0x80076F3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076F40: b           L_80076F48
    // 0x80076F44: nop

        goto L_80076F48;
    // 0x80076F44: nop

L_80076F48:
    // 0x80076F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076F50: jr          $ra
    // 0x80076F54: nop

    return;
    // 0x80076F54: nop

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
RECOMP_FUNC void func_80076F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076F98: jal         0x80061488
    // 0x80076F9C: addiu       $a0, $zero, 0x492
    ctx->r4 = ADD32(0, 0X492);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80076F9C: addiu       $a0, $zero, 0x492
    ctx->r4 = ADD32(0, 0X492);
    after_0:
    // 0x80076FA0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80076FA4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80076FA8: b           L_80076FB8
    // 0x80076FAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076FB8;
    // 0x80076FAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076FB0: b           L_80076FB8
    // 0x80076FB4: nop

        goto L_80076FB8;
    // 0x80076FB4: nop

L_80076FB8:
    // 0x80076FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076FC0: jr          $ra
    // 0x80076FC4: nop

    return;
    // 0x80076FC4: nop

;}
RECOMP_FUNC void func_80076FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076FC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076FD0: jal         0x80061348
    // 0x80076FD4: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80076FD4: addiu       $a0, $zero, 0x457
    ctx->r4 = ADD32(0, 0X457);
    after_0:
    // 0x80076FD8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80076FDC: b           L_80076FEC
    // 0x80076FE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80076FEC;
    // 0x80076FE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80076FE4: b           L_80076FEC
    // 0x80076FE8: nop

        goto L_80076FEC;
    // 0x80076FE8: nop

L_80076FEC:
    // 0x80076FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076FF4: jr          $ra
    // 0x80076FF8: nop

    return;
    // 0x80076FF8: nop

;}
RECOMP_FUNC void func_80076FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076FFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077004: jal         0x80061488
    // 0x80077008: addiu       $a0, $zero, 0x557
    ctx->r4 = ADD32(0, 0X557);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077008: addiu       $a0, $zero, 0x557
    ctx->r4 = ADD32(0, 0X557);
    after_0:
    // 0x8007700C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80077010: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077014: b           L_80077024
    // 0x80077018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077024;
    // 0x80077018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007701C: b           L_80077024
    // 0x80077020: nop

        goto L_80077024;
    // 0x80077020: nop

L_80077024:
    // 0x80077024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007702C: jr          $ra
    // 0x80077030: nop

    return;
    // 0x80077030: nop

;}
RECOMP_FUNC void func_80077034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007703C: jal         0x80061348
    // 0x80077040: addiu       $a0, $zero, 0x494
    ctx->r4 = ADD32(0, 0X494);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80077040: addiu       $a0, $zero, 0x494
    ctx->r4 = ADD32(0, 0X494);
    after_0:
    // 0x80077044: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80077048: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8007704C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077050: b           L_80077060
    // 0x80077054: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
        goto L_80077060;
    // 0x80077054: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077058: b           L_80077060
    // 0x8007705C: nop

        goto L_80077060;
    // 0x8007705C: nop

L_80077060:
    // 0x80077060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077068: jr          $ra
    // 0x8007706C: nop

    return;
    // 0x8007706C: nop

;}
RECOMP_FUNC void func_80077070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077078: jal         0x8005F064
    // 0x8007707C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8007707C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_0:
    // 0x80077080: b           L_80077090
    // 0x80077084: nop

        goto L_80077090;
    // 0x80077084: nop

    // 0x80077088: b           L_80077090
    // 0x8007708C: nop

        goto L_80077090;
    // 0x8007708C: nop

L_80077090:
    // 0x80077090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077098: jr          $ra
    // 0x8007709C: nop

    return;
    // 0x8007709C: nop

;}
RECOMP_FUNC void func_800770A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800770A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800770A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800770A8: jal         0x8005F064
    // 0x800770AC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800770AC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_0:
    // 0x800770B0: b           L_800770C0
    // 0x800770B4: nop

        goto L_800770C0;
    // 0x800770B4: nop

    // 0x800770B8: b           L_800770C0
    // 0x800770BC: nop

        goto L_800770C0;
    // 0x800770BC: nop

L_800770C0:
    // 0x800770C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800770C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800770C8: jr          $ra
    // 0x800770CC: nop

    return;
    // 0x800770CC: nop

;}
RECOMP_FUNC void func_800770D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800770D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800770D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800770D8: nop

    // 0x800770DC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800770E0: nop

    // 0x800770E4: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800770E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800770EC: jr          $ra
    // 0x800770F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800770F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800770F4: jr          $ra
    // 0x800770F8: nop

    return;
    // 0x800770F8: nop

    // 0x800770FC: jr          $ra
    // 0x80077100: nop

    return;
    // 0x80077100: nop

;}
RECOMP_FUNC void func_80077104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007710C: jal         0x80061488
    // 0x80077110: addiu       $a0, $zero, 0x55C
    ctx->r4 = ADD32(0, 0X55C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077110: addiu       $a0, $zero, 0x55C
    ctx->r4 = ADD32(0, 0X55C);
    after_0:
    // 0x80077114: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077118: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007711C: b           L_8007712C
    // 0x80077120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007712C;
    // 0x80077120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077124: b           L_8007712C
    // 0x80077128: nop

        goto L_8007712C;
    // 0x80077128: nop

L_8007712C:
    // 0x8007712C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077134: jr          $ra
    // 0x80077138: nop

    return;
    // 0x80077138: nop

;}
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
RECOMP_FUNC void func_80077174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077174: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077178: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007717C: nop

    // 0x80077180: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80077184: nop

    // 0x80077188: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8007718C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077190: jr          $ra
    // 0x80077194: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077194: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077198: jr          $ra
    // 0x8007719C: nop

    return;
    // 0x8007719C: nop

    // 0x800771A0: jr          $ra
    // 0x800771A4: nop

    return;
    // 0x800771A4: nop

;}
RECOMP_FUNC void func_800771A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800771A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800771AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800771B0: nop

    // 0x800771B4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800771B8: nop

    // 0x800771BC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800771C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800771C4: jr          $ra
    // 0x800771C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800771C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800771CC: jr          $ra
    // 0x800771D0: nop

    return;
    // 0x800771D0: nop

    // 0x800771D4: jr          $ra
    // 0x800771D8: nop

    return;
    // 0x800771D8: nop

;}
RECOMP_FUNC void func_800771DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800771DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800771E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800771E4: jal         0x80061488
    // 0x800771E8: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800771E8: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    after_0:
    // 0x800771EC: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800771F0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800771F4: b           L_80077204
    // 0x800771F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077204;
    // 0x800771F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800771FC: b           L_80077204
    // 0x80077200: nop

        goto L_80077204;
    // 0x80077200: nop

L_80077204:
    // 0x80077204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007720C: jr          $ra
    // 0x80077210: nop

    return;
    // 0x80077210: nop

;}
RECOMP_FUNC void func_80077214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007721C: jal         0x80061488
    // 0x80077220: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077220: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    after_0:
    // 0x80077224: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077228: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007722C: b           L_8007723C
    // 0x80077230: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007723C;
    // 0x80077230: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077234: b           L_8007723C
    // 0x80077238: nop

        goto L_8007723C;
    // 0x80077238: nop

L_8007723C:
    // 0x8007723C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077244: jr          $ra
    // 0x80077248: nop

    return;
    // 0x80077248: nop

;}
RECOMP_FUNC void func_8007724C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007724C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077254: jal         0x80061488
    // 0x80077258: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077258: addiu       $a0, $zero, 0x651
    ctx->r4 = ADD32(0, 0X651);
    after_0:
    // 0x8007725C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077260: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077264: b           L_80077274
    // 0x80077268: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077274;
    // 0x80077268: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007726C: b           L_80077274
    // 0x80077270: nop

        goto L_80077274;
    // 0x80077270: nop

L_80077274:
    // 0x80077274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007727C: jr          $ra
    // 0x80077280: nop

    return;
    // 0x80077280: nop

;}
RECOMP_FUNC void func_80077284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007728C: jal         0x80061488
    // 0x80077290: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077290: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x80077294: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077298: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007729C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800772A0: beq         $v0, $zero, L_800772C8
    if (ctx->r2 == 0) {
        // 0x800772A4: nop

            goto L_800772C8;
    }
    // 0x800772A4: nop

    // 0x800772A8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800772AC: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800772B0: nop

    // 0x800772B4: lh          $v0, 0x30($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X30);
    // 0x800772B8: nop

    // 0x800772BC: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800772C0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800772C4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800772C8:
    // 0x800772C8: b           L_800772D8
    // 0x800772CC: nop

        goto L_800772D8;
    // 0x800772CC: nop

    // 0x800772D0: b           L_800772D8
    // 0x800772D4: nop

        goto L_800772D8;
    // 0x800772D4: nop

L_800772D8:
    // 0x800772D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800772DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800772E0: jr          $ra
    // 0x800772E4: nop

    return;
    // 0x800772E4: nop

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
RECOMP_FUNC void func_8007734C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007734C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077354: jal         0x80061488
    // 0x80077358: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077358: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x8007735C: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077360: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80077364: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077368: beq         $v0, $zero, L_80077390
    if (ctx->r2 == 0) {
        // 0x8007736C: nop

            goto L_80077390;
    }
    // 0x8007736C: nop

    // 0x80077370: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80077374: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80077378: nop

    // 0x8007737C: lh          $v0, 0x34($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X34);
    // 0x80077380: nop

    // 0x80077384: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077388: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8007738C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80077390:
    // 0x80077390: b           L_800773A0
    // 0x80077394: nop

        goto L_800773A0;
    // 0x80077394: nop

    // 0x80077398: b           L_800773A0
    // 0x8007739C: nop

        goto L_800773A0;
    // 0x8007739C: nop

L_800773A0:
    // 0x800773A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800773A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800773A8: jr          $ra
    // 0x800773AC: nop

    return;
    // 0x800773AC: nop

;}
RECOMP_FUNC void func_800773B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800773B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800773B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800773B8: jal         0x80061488
    // 0x800773BC: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800773BC: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x800773C0: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800773C4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800773C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800773CC: beq         $v0, $zero, L_800773F4
    if (ctx->r2 == 0) {
        // 0x800773D0: nop

            goto L_800773F4;
    }
    // 0x800773D0: nop

    // 0x800773D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800773D8: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x800773DC: nop

    // 0x800773E0: lh          $v0, 0x36($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X36);
    // 0x800773E4: nop

    // 0x800773E8: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800773EC: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800773F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800773F4:
    // 0x800773F4: b           L_80077404
    // 0x800773F8: nop

        goto L_80077404;
    // 0x800773F8: nop

    // 0x800773FC: b           L_80077404
    // 0x80077400: nop

        goto L_80077404;
    // 0x80077400: nop

L_80077404:
    // 0x80077404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007740C: jr          $ra
    // 0x80077410: nop

    return;
    // 0x80077410: nop

;}
RECOMP_FUNC void func_80077414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007741C: jal         0x80061488
    // 0x80077420: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077420: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x80077424: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80077428: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007742C: b           L_8007743C
    // 0x80077430: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007743C;
    // 0x80077430: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077434: b           L_8007743C
    // 0x80077438: nop

        goto L_8007743C;
    // 0x80077438: nop

L_8007743C:
    // 0x8007743C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077444: jr          $ra
    // 0x80077448: nop

    return;
    // 0x80077448: nop

;}
RECOMP_FUNC void func_8007744C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007744C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077454: jal         0x80061488
    // 0x80077458: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077458: addiu       $a0, $zero, 0x55D
    ctx->r4 = ADD32(0, 0X55D);
    after_0:
    // 0x8007745C: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80077460: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80077464: b           L_80077474
    // 0x80077468: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077474;
    // 0x80077468: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007746C: b           L_80077474
    // 0x80077470: nop

        goto L_80077474;
    // 0x80077470: nop

L_80077474:
    // 0x80077474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007747C: jr          $ra
    // 0x80077480: nop

    return;
    // 0x80077480: nop

;}
RECOMP_FUNC void func_80077484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007748C: jal         0x80061348
    // 0x80077490: addiu       $a0, $zero, 0x493
    ctx->r4 = ADD32(0, 0X493);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80077490: addiu       $a0, $zero, 0x493
    ctx->r4 = ADD32(0, 0X493);
    after_0:
    // 0x80077494: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077498: b           L_800774A8
    // 0x8007749C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800774A8;
    // 0x8007749C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800774A0: b           L_800774A8
    // 0x800774A4: nop

        goto L_800774A8;
    // 0x800774A4: nop

L_800774A8:
    // 0x800774A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800774AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800774B0: jr          $ra
    // 0x800774B4: nop

    return;
    // 0x800774B4: nop

;}
RECOMP_FUNC void func_800774B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800774B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800774BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800774C0: jal         0x80061348
    // 0x800774C4: addiu       $a0, $zero, 0x6B0
    ctx->r4 = ADD32(0, 0X6B0);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800774C4: addiu       $a0, $zero, 0x6B0
    ctx->r4 = ADD32(0, 0X6B0);
    after_0:
    // 0x800774C8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800774CC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800774D0: b           L_800774E0
    // 0x800774D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800774E0;
    // 0x800774D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800774D8: b           L_800774E0
    // 0x800774DC: nop

        goto L_800774E0;
    // 0x800774DC: nop

L_800774E0:
    // 0x800774E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800774E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800774E8: jr          $ra
    // 0x800774EC: nop

    return;
    // 0x800774EC: nop

;}
RECOMP_FUNC void func_800774F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800774F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800774F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800774F8: jal         0x80061488
    // 0x800774FC: addiu       $a0, $zero, 0x496
    ctx->r4 = ADD32(0, 0X496);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800774FC: addiu       $a0, $zero, 0x496
    ctx->r4 = ADD32(0, 0X496);
    after_0:
    // 0x80077500: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80077504: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80077508: b           L_80077518
    // 0x8007750C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077518;
    // 0x8007750C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077510: b           L_80077518
    // 0x80077514: nop

        goto L_80077518;
    // 0x80077514: nop

L_80077518:
    // 0x80077518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007751C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077520: jr          $ra
    // 0x80077524: nop

    return;
    // 0x80077524: nop

;}
RECOMP_FUNC void func_80077528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077528: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007752C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077530: nop

    // 0x80077534: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x80077538: nop

    // 0x8007753C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077540: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077544: jr          $ra
    // 0x80077548: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077548: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007754C: jr          $ra
    // 0x80077550: nop

    return;
    // 0x80077550: nop

    // 0x80077554: jr          $ra
    // 0x80077558: nop

    return;
    // 0x80077558: nop

;}
RECOMP_FUNC void func_8007755C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007755C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077560: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077564: nop

    // 0x80077568: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x8007756C: nop

    // 0x80077570: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077574: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077578: jr          $ra
    // 0x8007757C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007757C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077580: jr          $ra
    // 0x80077584: nop

    return;
    // 0x80077584: nop

    // 0x80077588: jr          $ra
    // 0x8007758C: nop

    return;
    // 0x8007758C: nop

;}
RECOMP_FUNC void func_80077590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077590: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077594: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077598: nop

    // 0x8007759C: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x800775A0: nop

    // 0x800775A4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800775A8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800775AC: jr          $ra
    // 0x800775B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800775B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800775B4: jr          $ra
    // 0x800775B8: nop

    return;
    // 0x800775B8: nop

    // 0x800775BC: jr          $ra
    // 0x800775C0: nop

    return;
    // 0x800775C0: nop

;}
RECOMP_FUNC void func_800775C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800775C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800775C8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800775CC: nop

    // 0x800775D0: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x800775D4: nop

    // 0x800775D8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800775DC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800775E0: jr          $ra
    // 0x800775E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800775E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800775E8: jr          $ra
    // 0x800775EC: nop

    return;
    // 0x800775EC: nop

    // 0x800775F0: jr          $ra
    // 0x800775F4: nop

    return;
    // 0x800775F4: nop

;}
RECOMP_FUNC void func_800775F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800775F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800775FC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077600: nop

    // 0x80077604: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80077608: nop

    // 0x8007760C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077610: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077614: jr          $ra
    // 0x80077618: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077618: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007761C: jr          $ra
    // 0x80077620: nop

    return;
    // 0x80077620: nop

    // 0x80077624: jr          $ra
    // 0x80077628: nop

    return;
    // 0x80077628: nop

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
RECOMP_FUNC void func_80077694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077694: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077698: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007769C: nop

    // 0x800776A0: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x800776A4: nop

    // 0x800776A8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800776AC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800776B0: jr          $ra
    // 0x800776B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800776B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800776B8: jr          $ra
    // 0x800776BC: nop

    return;
    // 0x800776BC: nop

    // 0x800776C0: jr          $ra
    // 0x800776C4: nop

    return;
    // 0x800776C4: nop

;}
RECOMP_FUNC void func_800776C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800776C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800776CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800776D0: jal         0x80061488
    // 0x800776D4: addiu       $a0, $zero, 0x6CE
    ctx->r4 = ADD32(0, 0X6CE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800776D4: addiu       $a0, $zero, 0x6CE
    ctx->r4 = ADD32(0, 0X6CE);
    after_0:
    // 0x800776D8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800776DC: b           L_800776EC
    // 0x800776E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800776EC;
    // 0x800776E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800776E4: b           L_800776EC
    // 0x800776E8: nop

        goto L_800776EC;
    // 0x800776E8: nop

L_800776EC:
    // 0x800776EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800776F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800776F4: jr          $ra
    // 0x800776F8: nop

    return;
    // 0x800776F8: nop

;}
RECOMP_FUNC void func_800776FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800776FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077704: jal         0x80061488
    // 0x80077708: addiu       $a0, $zero, 0x6CE
    ctx->r4 = ADD32(0, 0X6CE);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80077708: addiu       $a0, $zero, 0x6CE
    ctx->r4 = ADD32(0, 0X6CE);
    after_0:
    // 0x8007770C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80077710: b           L_80077720
    // 0x80077714: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80077720;
    // 0x80077714: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80077718: b           L_80077720
    // 0x8007771C: nop

        goto L_80077720;
    // 0x8007771C: nop

L_80077720:
    // 0x80077720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077728: jr          $ra
    // 0x8007772C: nop

    return;
    // 0x8007772C: nop

;}
RECOMP_FUNC void func_80077730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077730: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077734: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077738: nop

    // 0x8007773C: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80077740: nop

    // 0x80077744: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077748: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007774C: jr          $ra
    // 0x80077750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077750: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077754: jr          $ra
    // 0x80077758: nop

    return;
    // 0x80077758: nop

    // 0x8007775C: jr          $ra
    // 0x80077760: nop

    return;
    // 0x80077760: nop

;}
RECOMP_FUNC void func_80077764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077764: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077768: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007776C: nop

    // 0x80077770: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80077774: nop

    // 0x80077778: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007777C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077780: jr          $ra
    // 0x80077784: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077784: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077788: jr          $ra
    // 0x8007778C: nop

    return;
    // 0x8007778C: nop

    // 0x80077790: jr          $ra
    // 0x80077794: nop

    return;
    // 0x80077794: nop

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
RECOMP_FUNC void func_800777CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800777CC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800777D0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800777D4: nop

    // 0x800777D8: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x800777DC: nop

    // 0x800777E0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800777E4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800777E8: jr          $ra
    // 0x800777EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800777EC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800777F0: jr          $ra
    // 0x800777F4: nop

    return;
    // 0x800777F4: nop

    // 0x800777F8: jr          $ra
    // 0x800777FC: nop

    return;
    // 0x800777FC: nop

;}
RECOMP_FUNC void func_80077800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077800: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077804: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077808: nop

    // 0x8007780C: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80077810: nop

    // 0x80077814: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077818: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007781C: jr          $ra
    // 0x80077820: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077820: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077824: jr          $ra
    // 0x80077828: nop

    return;
    // 0x80077828: nop

    // 0x8007782C: jr          $ra
    // 0x80077830: nop

    return;
    // 0x80077830: nop

;}
RECOMP_FUNC void func_80077834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077834: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077838: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007783C: nop

    // 0x80077840: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80077844: nop

    // 0x80077848: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007784C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077850: jr          $ra
    // 0x80077854: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077854: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077858: jr          $ra
    // 0x8007785C: nop

    return;
    // 0x8007785C: nop

    // 0x80077860: jr          $ra
    // 0x80077864: nop

    return;
    // 0x80077864: nop

;}
RECOMP_FUNC void func_80077868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077868: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007786C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077870: nop

    // 0x80077874: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80077878: nop

    // 0x8007787C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077880: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077884: jr          $ra
    // 0x80077888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077888: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007788C: jr          $ra
    // 0x80077890: nop

    return;
    // 0x80077890: nop

    // 0x80077894: jr          $ra
    // 0x80077898: nop

    return;
    // 0x80077898: nop

;}
RECOMP_FUNC void func_8007789C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007789C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800778A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800778A4: nop

    // 0x800778A8: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x800778AC: nop

    // 0x800778B0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800778B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800778B8: jr          $ra
    // 0x800778BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800778BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800778C0: jr          $ra
    // 0x800778C4: nop

    return;
    // 0x800778C4: nop

    // 0x800778C8: jr          $ra
    // 0x800778CC: nop

    return;
    // 0x800778CC: nop

;}
RECOMP_FUNC void func_800778D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800778D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800778D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800778D8: nop

    // 0x800778DC: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x800778E0: nop

    // 0x800778E4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800778E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800778EC: jr          $ra
    // 0x800778F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800778F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800778F4: jr          $ra
    // 0x800778F8: nop

    return;
    // 0x800778F8: nop

    // 0x800778FC: jr          $ra
    // 0x80077900: nop

    return;
    // 0x80077900: nop

;}
RECOMP_FUNC void func_80077904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077904: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80077908: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007790C: nop

    // 0x80077910: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80077914: nop

    // 0x80077918: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007791C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077920: jr          $ra
    // 0x80077924: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077924: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80077928: jr          $ra
    // 0x8007792C: nop

    return;
    // 0x8007792C: nop

    // 0x80077930: jr          $ra
    // 0x80077934: nop

    return;
    // 0x80077934: nop

;}
RECOMP_FUNC void func_80077938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077938: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007793C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80077940: nop

    // 0x80077944: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80077948: nop

    // 0x8007794C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80077950: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80077954: jr          $ra
    // 0x80077958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80077958: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007795C: jr          $ra
    // 0x80077960: nop

    return;
    // 0x80077960: nop

    // 0x80077964: jr          $ra
    // 0x80077968: nop

    return;
    // 0x80077968: nop

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
RECOMP_FUNC void func_800779A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800779A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800779A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800779A8: nop

    // 0x800779AC: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x800779B0: nop

    // 0x800779B4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800779B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800779BC: jr          $ra
    // 0x800779C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800779C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800779C4: jr          $ra
    // 0x800779C8: nop

    return;
    // 0x800779C8: nop

    // 0x800779CC: jr          $ra
    // 0x800779D0: nop

    return;
    // 0x800779D0: nop

;}
RECOMP_FUNC void func_800779D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800779D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800779D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800779DC: nop

    // 0x800779E0: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x800779E4: nop

    // 0x800779E8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800779EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800779F0: jr          $ra
    // 0x800779F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800779F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800779F8: jr          $ra
    // 0x800779FC: nop

    return;
    // 0x800779FC: nop

    // 0x80077A00: jr          $ra
    // 0x80077A04: nop

    return;
    // 0x80077A04: nop

;}
