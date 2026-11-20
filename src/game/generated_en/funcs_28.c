#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80073020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073020: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073024: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073028: nop

    // 0x8007302C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073030: nop

    // 0x80073034: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80073038: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007303C: jr          $ra
    // 0x80073040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073044: jr          $ra
    // 0x80073048: nop

    return;
    // 0x80073048: nop

    // 0x8007304C: jr          $ra
    // 0x80073050: nop

    return;
    // 0x80073050: nop

;}
RECOMP_FUNC void func_80073054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073054: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073058: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007305C: nop

    // 0x80073060: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073064: nop

    // 0x80073068: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8007306C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073070: jr          $ra
    // 0x80073074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073074: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073078: jr          $ra
    // 0x8007307C: nop

    return;
    // 0x8007307C: nop

    // 0x80073080: jr          $ra
    // 0x80073084: nop

    return;
    // 0x80073084: nop

;}
RECOMP_FUNC void func_80073088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073088: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007308C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073090: nop

    // 0x80073094: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073098: nop

    // 0x8007309C: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x800730A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800730A4: jr          $ra
    // 0x800730A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800730A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800730AC: jr          $ra
    // 0x800730B0: nop

    return;
    // 0x800730B0: nop

    // 0x800730B4: jr          $ra
    // 0x800730B8: nop

    return;
    // 0x800730B8: nop

;}
RECOMP_FUNC void func_800730BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800730BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800730C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800730C4: nop

    // 0x800730C8: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800730CC: nop

    // 0x800730D0: slti        $t7, $v0, 0x320
    ctx->r15 = SIGNED(ctx->r2) < 0X320 ? 1 : 0;
    // 0x800730D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800730D8: jr          $ra
    // 0x800730DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800730DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800730E0: jr          $ra
    // 0x800730E4: nop

    return;
    // 0x800730E4: nop

    // 0x800730E8: jr          $ra
    // 0x800730EC: nop

    return;
    // 0x800730EC: nop

;}
RECOMP_FUNC void func_800730F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800730F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800730F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800730F8: nop

    // 0x800730FC: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073100: nop

    // 0x80073104: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073108: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007310C: jr          $ra
    // 0x80073110: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073110: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073114: jr          $ra
    // 0x80073118: nop

    return;
    // 0x80073118: nop

    // 0x8007311C: jr          $ra
    // 0x80073120: nop

    return;
    // 0x80073120: nop

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
RECOMP_FUNC void func_80073158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073158: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007315C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073160: nop

    // 0x80073164: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073168: nop

    // 0x8007316C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073170: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073174: jr          $ra
    // 0x80073178: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073178: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007317C: jr          $ra
    // 0x80073180: nop

    return;
    // 0x80073180: nop

    // 0x80073184: jr          $ra
    // 0x80073188: nop

    return;
    // 0x80073188: nop

;}
RECOMP_FUNC void func_8007318C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007318C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073190: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073194: nop

    // 0x80073198: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8007319C: nop

    // 0x800731A0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800731A4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800731A8: jr          $ra
    // 0x800731AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800731AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800731B0: jr          $ra
    // 0x800731B4: nop

    return;
    // 0x800731B4: nop

    // 0x800731B8: jr          $ra
    // 0x800731BC: nop

    return;
    // 0x800731BC: nop

;}
RECOMP_FUNC void func_800731C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800731C0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800731C4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800731C8: nop

    // 0x800731CC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800731D0: nop

    // 0x800731D4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800731D8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800731DC: jr          $ra
    // 0x800731E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800731E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800731E4: jr          $ra
    // 0x800731E8: nop

    return;
    // 0x800731E8: nop

    // 0x800731EC: jr          $ra
    // 0x800731F0: nop

    return;
    // 0x800731F0: nop

;}
RECOMP_FUNC void func_800731F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800731F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800731F8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800731FC: nop

    // 0x80073200: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80073204: nop

    // 0x80073208: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007320C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073210: jr          $ra
    // 0x80073214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073218: jr          $ra
    // 0x8007321C: nop

    return;
    // 0x8007321C: nop

    // 0x80073220: jr          $ra
    // 0x80073224: nop

    return;
    // 0x80073224: nop

;}
RECOMP_FUNC void func_80073228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073228: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007322C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073230: nop

    // 0x80073234: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80073238: nop

    // 0x8007323C: slti        $t7, $v0, 0x1AE
    ctx->r15 = SIGNED(ctx->r2) < 0X1AE ? 1 : 0;
    // 0x80073240: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073244: jr          $ra
    // 0x80073248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007324C: jr          $ra
    // 0x80073250: nop

    return;
    // 0x80073250: nop

    // 0x80073254: jr          $ra
    // 0x80073258: nop

    return;
    // 0x80073258: nop

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
RECOMP_FUNC void func_80073290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073290: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073294: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073298: nop

    // 0x8007329C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x800732A0: nop

    // 0x800732A4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800732A8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800732AC: jr          $ra
    // 0x800732B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800732B0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800732B4: jr          $ra
    // 0x800732B8: nop

    return;
    // 0x800732B8: nop

    // 0x800732BC: jr          $ra
    // 0x800732C0: nop

    return;
    // 0x800732C0: nop

;}
RECOMP_FUNC void func_800732C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800732C4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800732C8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800732CC: nop

    // 0x800732D0: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800732D4: nop

    // 0x800732D8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800732DC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800732E0: jr          $ra
    // 0x800732E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800732E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800732E8: jr          $ra
    // 0x800732EC: nop

    return;
    // 0x800732EC: nop

    // 0x800732F0: jr          $ra
    // 0x800732F4: nop

    return;
    // 0x800732F4: nop

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
RECOMP_FUNC void func_8007332C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007332C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073334: jal         0x80061488
    // 0x80073338: addiu       $a0, $zero, 0x518
    ctx->r4 = ADD32(0, 0X518);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073338: addiu       $a0, $zero, 0x518
    ctx->r4 = ADD32(0, 0X518);
    after_0:
    // 0x8007333C: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80073340: b           L_80073350
    // 0x80073344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073350;
    // 0x80073344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073348: b           L_80073350
    // 0x8007334C: nop

        goto L_80073350;
    // 0x8007334C: nop

L_80073350:
    // 0x80073350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073358: jr          $ra
    // 0x8007335C: nop

    return;
    // 0x8007335C: nop

;}
RECOMP_FUNC void func_80073360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073368: jal         0x8005F064
    // 0x8007336C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8007336C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_0:
    // 0x80073370: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80073374: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073378: bne         $v0, $zero, L_80073390
    if (ctx->r2 != 0) {
        // 0x8007337C: nop

            goto L_80073390;
    }
    // 0x8007337C: nop

    // 0x80073380: jal         0x80061488
    // 0x80073384: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    func_80061488(rdram, ctx);
        goto after_1;
    // 0x80073384: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    after_1:
    // 0x80073388: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007338C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80073390:
    // 0x80073390: b           L_800733A0
    // 0x80073394: nop

        goto L_800733A0;
    // 0x80073394: nop

    // 0x80073398: b           L_800733A0
    // 0x8007339C: nop

        goto L_800733A0;
    // 0x8007339C: nop

L_800733A0:
    // 0x800733A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800733A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800733A8: jr          $ra
    // 0x800733AC: nop

    return;
    // 0x800733AC: nop

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
RECOMP_FUNC void func_80073400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073408: jal         0x80061488
    // 0x8007340C: addiu       $a0, $zero, 0x63E
    ctx->r4 = ADD32(0, 0X63E);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007340C: addiu       $a0, $zero, 0x63E
    ctx->r4 = ADD32(0, 0X63E);
    after_0:
    // 0x80073410: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073414: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073418: b           L_80073428
    // 0x8007341C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073428;
    // 0x8007341C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073420: b           L_80073428
    // 0x80073424: nop

        goto L_80073428;
    // 0x80073424: nop

L_80073428:
    // 0x80073428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007342C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073430: jr          $ra
    // 0x80073434: nop

    return;
    // 0x80073434: nop

;}
RECOMP_FUNC void func_80073438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007343C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073440: jal         0x80061488
    // 0x80073444: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073444: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_0:
    // 0x80073448: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8007344C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80073450: b           L_80073460
    // 0x80073454: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073460;
    // 0x80073454: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073458: b           L_80073460
    // 0x8007345C: nop

        goto L_80073460;
    // 0x8007345C: nop

L_80073460:
    // 0x80073460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073468: jr          $ra
    // 0x8007346C: nop

    return;
    // 0x8007346C: nop

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
RECOMP_FUNC void func_800734C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800734C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800734C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800734C8: jal         0x80061488
    // 0x800734CC: addiu       $a0, $zero, 0x63F
    ctx->r4 = ADD32(0, 0X63F);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800734CC: addiu       $a0, $zero, 0x63F
    ctx->r4 = ADD32(0, 0X63F);
    after_0:
    // 0x800734D0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800734D4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800734D8: b           L_800734E8
    // 0x800734DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800734E8;
    // 0x800734DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800734E0: b           L_800734E8
    // 0x800734E4: nop

        goto L_800734E8;
    // 0x800734E4: nop

L_800734E8:
    // 0x800734E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800734EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800734F0: jr          $ra
    // 0x800734F4: nop

    return;
    // 0x800734F4: nop

;}
RECOMP_FUNC void func_800734F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800734F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800734FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073500: jal         0x8005F064
    // 0x80073504: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80073504: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_0:
    // 0x80073508: b           L_80073518
    // 0x8007350C: nop

        goto L_80073518;
    // 0x8007350C: nop

    // 0x80073510: b           L_80073518
    // 0x80073514: nop

        goto L_80073518;
    // 0x80073514: nop

L_80073518:
    // 0x80073518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007351C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073520: jr          $ra
    // 0x80073524: nop

    return;
    // 0x80073524: nop

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
RECOMP_FUNC void func_8007355C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007355C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073564: jal         0x80061488
    // 0x80073568: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073568: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    after_0:
    // 0x8007356C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80073570: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073574: b           L_80073584
    // 0x80073578: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073584;
    // 0x80073578: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007357C: b           L_80073584
    // 0x80073580: nop

        goto L_80073584;
    // 0x80073580: nop

L_80073584:
    // 0x80073584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007358C: jr          $ra
    // 0x80073590: nop

    return;
    // 0x80073590: nop

;}
RECOMP_FUNC void func_80073594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007359C: jal         0x8005F064
    // 0x800735A0: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800735A0: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_0:
    // 0x800735A4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800735A8: b           L_800735B8
    // 0x800735AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800735B8;
    // 0x800735AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800735B0: b           L_800735B8
    // 0x800735B4: nop

        goto L_800735B8;
    // 0x800735B4: nop

L_800735B8:
    // 0x800735B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800735BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800735C0: jr          $ra
    // 0x800735C4: nop

    return;
    // 0x800735C4: nop

;}
RECOMP_FUNC void func_800735C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800735C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800735CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800735D0: jal         0x80061488
    // 0x800735D4: addiu       $a0, $zero, 0x643
    ctx->r4 = ADD32(0, 0X643);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800735D4: addiu       $a0, $zero, 0x643
    ctx->r4 = ADD32(0, 0X643);
    after_0:
    // 0x800735D8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800735DC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800735E0: b           L_800735F0
    // 0x800735E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800735F0;
    // 0x800735E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800735E8: b           L_800735F0
    // 0x800735EC: nop

        goto L_800735F0;
    // 0x800735EC: nop

L_800735F0:
    // 0x800735F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800735F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800735F8: jr          $ra
    // 0x800735FC: nop

    return;
    // 0x800735FC: nop

;}
RECOMP_FUNC void func_80073600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073600: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073604: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073608: nop

    // 0x8007360C: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x80073610: nop

    // 0x80073614: slti        $t7, $v0, 0x82
    ctx->r15 = SIGNED(ctx->r2) < 0X82 ? 1 : 0;
    // 0x80073618: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007361C: jr          $ra
    // 0x80073620: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073620: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073624: jr          $ra
    // 0x80073628: nop

    return;
    // 0x80073628: nop

    // 0x8007362C: jr          $ra
    // 0x80073630: nop

    return;
    // 0x80073630: nop

;}
RECOMP_FUNC void func_80073634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073634: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073638: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007363C: nop

    // 0x80073640: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073644: nop

    // 0x80073648: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007364C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073650: jr          $ra
    // 0x80073654: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073654: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073658: jr          $ra
    // 0x8007365C: nop

    return;
    // 0x8007365C: nop

    // 0x80073660: jr          $ra
    // 0x80073664: nop

    return;
    // 0x80073664: nop

;}
RECOMP_FUNC void func_80073668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073668: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007366C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073670: nop

    // 0x80073674: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073678: nop

    // 0x8007367C: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073680: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073684: jr          $ra
    // 0x80073688: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073688: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007368C: jr          $ra
    // 0x80073690: nop

    return;
    // 0x80073690: nop

    // 0x80073694: jr          $ra
    // 0x80073698: nop

    return;
    // 0x80073698: nop

;}
RECOMP_FUNC void func_8007369C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007369C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800736A0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800736A4: nop

    // 0x800736A8: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800736AC: nop

    // 0x800736B0: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800736B4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800736B8: jr          $ra
    // 0x800736BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800736BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800736C0: jr          $ra
    // 0x800736C4: nop

    return;
    // 0x800736C4: nop

    // 0x800736C8: jr          $ra
    // 0x800736CC: nop

    return;
    // 0x800736CC: nop

;}
RECOMP_FUNC void func_800736D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800736D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800736D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800736D8: nop

    // 0x800736DC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800736E0: nop

    // 0x800736E4: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800736E8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800736EC: jr          $ra
    // 0x800736F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800736F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800736F4: jr          $ra
    // 0x800736F8: nop

    return;
    // 0x800736F8: nop

    // 0x800736FC: jr          $ra
    // 0x80073700: nop

    return;
    // 0x80073700: nop

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
RECOMP_FUNC void func_80073738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073738: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007373C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073740: nop

    // 0x80073744: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073748: nop

    // 0x8007374C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80073750: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073754: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073758: beq         $v0, $zero, L_80073770
    if (ctx->r2 == 0) {
        // 0x8007375C: nop

            goto L_80073770;
    }
    // 0x8007375C: nop

    // 0x80073760: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073764: nop

    // 0x80073768: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8007376C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80073770:
    // 0x80073770: jr          $ra
    // 0x80073774: nop

    return;
    // 0x80073774: nop

    // 0x80073778: jr          $ra
    // 0x8007377C: nop

    return;
    // 0x8007377C: nop

    // 0x80073780: jr          $ra
    // 0x80073784: nop

    return;
    // 0x80073784: nop

;}
RECOMP_FUNC void func_80073788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073788: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007378C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073790: nop

    // 0x80073794: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073798: nop

    // 0x8007379C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800737A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800737A4: jr          $ra
    // 0x800737A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800737A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800737AC: jr          $ra
    // 0x800737B0: nop

    return;
    // 0x800737B0: nop

    // 0x800737B4: jr          $ra
    // 0x800737B8: nop

    return;
    // 0x800737B8: nop

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
RECOMP_FUNC void func_800737F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800737F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800737F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800737F8: nop

    // 0x800737FC: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x80073800: nop

    // 0x80073804: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80073808: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007380C: jr          $ra
    // 0x80073810: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073810: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073814: jr          $ra
    // 0x80073818: nop

    return;
    // 0x80073818: nop

    // 0x8007381C: jr          $ra
    // 0x80073820: nop

    return;
    // 0x80073820: nop

;}
RECOMP_FUNC void func_80073824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007382C: jal         0x80061488
    // 0x80073830: addiu       $a0, $zero, 0x538
    ctx->r4 = ADD32(0, 0X538);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073830: addiu       $a0, $zero, 0x538
    ctx->r4 = ADD32(0, 0X538);
    after_0:
    // 0x80073834: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80073838: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8007383C: b           L_8007384C
    // 0x80073840: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007384C;
    // 0x80073840: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073844: b           L_8007384C
    // 0x80073848: nop

        goto L_8007384C;
    // 0x80073848: nop

L_8007384C:
    // 0x8007384C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073854: jr          $ra
    // 0x80073858: nop

    return;
    // 0x80073858: nop

;}
RECOMP_FUNC void func_8007385C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007385C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073860: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073864: nop

    // 0x80073868: lh          $v0, 0x2($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2);
    // 0x8007386C: nop

    // 0x80073870: slti        $t7, $v0, 0x14A
    ctx->r15 = SIGNED(ctx->r2) < 0X14A ? 1 : 0;
    // 0x80073874: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073878: jr          $ra
    // 0x8007387C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007387C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073880: jr          $ra
    // 0x80073884: nop

    return;
    // 0x80073884: nop

    // 0x80073888: jr          $ra
    // 0x8007388C: nop

    return;
    // 0x8007388C: nop

;}
RECOMP_FUNC void func_80073890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073898: jal         0x80061488
    // 0x8007389C: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007389C: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x800738A0: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800738A4: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x800738A8: b           L_800738B8
    // 0x800738AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800738B8;
    // 0x800738AC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800738B0: b           L_800738B8
    // 0x800738B4: nop

        goto L_800738B8;
    // 0x800738B4: nop

L_800738B8:
    // 0x800738B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800738BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800738C0: jr          $ra
    // 0x800738C4: nop

    return;
    // 0x800738C4: nop

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
RECOMP_FUNC void func_8007391C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007391C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073920: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073924: nop

    // 0x80073928: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8007392C: nop

    // 0x80073930: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073934: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80073938: jr          $ra
    // 0x8007393C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8007393C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073940: jr          $ra
    // 0x80073944: nop

    return;
    // 0x80073944: nop

    // 0x80073948: jr          $ra
    // 0x8007394C: nop

    return;
    // 0x8007394C: nop

;}
RECOMP_FUNC void func_80073950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073950: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073954: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80073958: nop

    // 0x8007395C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80073960: nop

    // 0x80073964: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80073968: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007396C: jr          $ra
    // 0x80073970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80073970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073974: jr          $ra
    // 0x80073978: nop

    return;
    // 0x80073978: nop

    // 0x8007397C: jr          $ra
    // 0x80073980: nop

    return;
    // 0x80073980: nop

;}
RECOMP_FUNC void func_80073984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073984: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80073988: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8007398C: nop

    // 0x80073990: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80073994: nop

    // 0x80073998: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8007399C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800739A0: jr          $ra
    // 0x800739A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800739A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800739A8: jr          $ra
    // 0x800739AC: nop

    return;
    // 0x800739AC: nop

    // 0x800739B0: jr          $ra
    // 0x800739B4: nop

    return;
    // 0x800739B4: nop

;}
RECOMP_FUNC void func_800739B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800739B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800739BC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800739C0: nop

    // 0x800739C4: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x800739C8: nop

    // 0x800739CC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x800739D0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800739D4: jr          $ra
    // 0x800739D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800739D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800739DC: jr          $ra
    // 0x800739E0: nop

    return;
    // 0x800739E0: nop

    // 0x800739E4: jr          $ra
    // 0x800739E8: nop

    return;
    // 0x800739E8: nop

;}
RECOMP_FUNC void func_800739EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800739EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800739F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800739F4: jal         0x80061488
    // 0x800739F8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800739F8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x800739FC: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x80073A00: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073A04: b           L_80073A14
    // 0x80073A08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073A14;
    // 0x80073A08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073A0C: b           L_80073A14
    // 0x80073A10: nop

        goto L_80073A14;
    // 0x80073A10: nop

L_80073A14:
    // 0x80073A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073A1C: jr          $ra
    // 0x80073A20: nop

    return;
    // 0x80073A20: nop

;}
RECOMP_FUNC void func_80073A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073A2C: jal         0x80061488
    // 0x80073A30: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073A30: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073A34: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x80073A38: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073A3C: b           L_80073A4C
    // 0x80073A40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073A4C;
    // 0x80073A40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073A44: b           L_80073A4C
    // 0x80073A48: nop

        goto L_80073A4C;
    // 0x80073A48: nop

L_80073A4C:
    // 0x80073A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073A54: jr          $ra
    // 0x80073A58: nop

    return;
    // 0x80073A58: nop

;}
RECOMP_FUNC void func_80073A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073A64: jal         0x80061488
    // 0x80073A68: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073A68: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073A6C: xori        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 ^ 0X4;
    // 0x80073A70: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073A74: b           L_80073A84
    // 0x80073A78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073A84;
    // 0x80073A78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073A7C: b           L_80073A84
    // 0x80073A80: nop

        goto L_80073A84;
    // 0x80073A80: nop

L_80073A84:
    // 0x80073A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073A8C: jr          $ra
    // 0x80073A90: nop

    return;
    // 0x80073A90: nop

;}
RECOMP_FUNC void func_80073A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073A9C: jal         0x80061488
    // 0x80073AA0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073AA0: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073AA4: xori        $t6, $v0, 0x5
    ctx->r14 = ctx->r2 ^ 0X5;
    // 0x80073AA8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80073AAC: b           L_80073ABC
    // 0x80073AB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073ABC;
    // 0x80073AB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073AB4: b           L_80073ABC
    // 0x80073AB8: nop

        goto L_80073ABC;
    // 0x80073AB8: nop

L_80073ABC:
    // 0x80073ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073AC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073AC4: jr          $ra
    // 0x80073AC8: nop

    return;
    // 0x80073AC8: nop

;}
RECOMP_FUNC void func_80073ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80073AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80073AD4: jal         0x80061488
    // 0x80073AD8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80073AD8: addiu       $a0, $zero, 0x456
    ctx->r4 = ADD32(0, 0X456);
    after_0:
    // 0x80073ADC: slti        $t6, $v0, 0x6
    ctx->r14 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80073AE0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80073AE4: b           L_80073AF4
    // 0x80073AE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80073AF4;
    // 0x80073AE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80073AEC: b           L_80073AF4
    // 0x80073AF0: nop

        goto L_80073AF4;
    // 0x80073AF0: nop

L_80073AF4:
    // 0x80073AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073AFC: jr          $ra
    // 0x80073B00: nop

    return;
    // 0x80073B00: nop

;}
