#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8006F148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F150: jal         0x80061348
    // 0x8006F154: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F154: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    after_0:
    // 0x8006F158: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F15C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F160: b           L_8006F170
    // 0x8006F164: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F170;
    // 0x8006F164: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F168: b           L_8006F170
    // 0x8006F16C: nop

        goto L_8006F170;
    // 0x8006F16C: nop

L_8006F170:
    // 0x8006F170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F178: jr          $ra
    // 0x8006F17C: nop

    return;
    // 0x8006F17C: nop

;}
RECOMP_FUNC void func_8006F180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F188: jal         0x80061348
    // 0x8006F18C: addiu       $a0, $zero, 0x2CD
    ctx->r4 = ADD32(0, 0X2CD);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F18C: addiu       $a0, $zero, 0x2CD
    ctx->r4 = ADD32(0, 0X2CD);
    after_0:
    // 0x8006F190: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006F194: b           L_8006F1A4
    // 0x8006F198: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F1A4;
    // 0x8006F198: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F19C: b           L_8006F1A4
    // 0x8006F1A0: nop

        goto L_8006F1A4;
    // 0x8006F1A0: nop

L_8006F1A4:
    // 0x8006F1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F1A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F1AC: jr          $ra
    // 0x8006F1B0: nop

    return;
    // 0x8006F1B0: nop

;}
RECOMP_FUNC void func_8006F1B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F1B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F1B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F1BC: jal         0x80061348
    // 0x8006F1C0: addiu       $a0, $zero, 0x2CD
    ctx->r4 = ADD32(0, 0X2CD);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F1C0: addiu       $a0, $zero, 0x2CD
    ctx->r4 = ADD32(0, 0X2CD);
    after_0:
    // 0x8006F1C4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F1C8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F1CC: b           L_8006F1DC
    // 0x8006F1D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F1DC;
    // 0x8006F1D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F1D4: b           L_8006F1DC
    // 0x8006F1D8: nop

        goto L_8006F1DC;
    // 0x8006F1D8: nop

L_8006F1DC:
    // 0x8006F1DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F1E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F1E4: jr          $ra
    // 0x8006F1E8: nop

    return;
    // 0x8006F1E8: nop

;}
RECOMP_FUNC void func_8006F1EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F1EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F1F0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F1F4: nop

    // 0x8006F1F8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F1FC: nop

    // 0x8006F200: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F204: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F208: jr          $ra
    // 0x8006F20C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F20C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F210: jr          $ra
    // 0x8006F214: nop

    return;
    // 0x8006F214: nop

    // 0x8006F218: jr          $ra
    // 0x8006F21C: nop

    return;
    // 0x8006F21C: nop

;}
RECOMP_FUNC void func_8006F220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F220: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F224: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F228: nop

    // 0x8006F22C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F230: nop

    // 0x8006F234: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F238: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F23C: jr          $ra
    // 0x8006F240: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F240: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F244: jr          $ra
    // 0x8006F248: nop

    return;
    // 0x8006F248: nop

    // 0x8006F24C: jr          $ra
    // 0x8006F250: nop

    return;
    // 0x8006F250: nop

;}
RECOMP_FUNC void func_8006F254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F254: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F258: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F25C: nop

    // 0x8006F260: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F264: nop

    // 0x8006F268: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F26C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F270: jr          $ra
    // 0x8006F274: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F274: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F278: jr          $ra
    // 0x8006F27C: nop

    return;
    // 0x8006F27C: nop

    // 0x8006F280: jr          $ra
    // 0x8006F284: nop

    return;
    // 0x8006F284: nop

;}
RECOMP_FUNC void func_8006F288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F288: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F28C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F290: nop

    // 0x8006F294: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F298: nop

    // 0x8006F29C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F2A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F2A4: jr          $ra
    // 0x8006F2A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F2A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F2AC: jr          $ra
    // 0x8006F2B0: nop

    return;
    // 0x8006F2B0: nop

    // 0x8006F2B4: jr          $ra
    // 0x8006F2B8: nop

    return;
    // 0x8006F2B8: nop

;}
RECOMP_FUNC void func_8006F2BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F2BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F2C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F2C4: nop

    // 0x8006F2C8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F2CC: nop

    // 0x8006F2D0: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F2D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F2D8: jr          $ra
    // 0x8006F2DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F2DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F2E0: jr          $ra
    // 0x8006F2E4: nop

    return;
    // 0x8006F2E4: nop

    // 0x8006F2E8: jr          $ra
    // 0x8006F2EC: nop

    return;
    // 0x8006F2EC: nop

;}
RECOMP_FUNC void func_8006F2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F2F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F2F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F2F8: nop

    // 0x8006F2FC: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F300: nop

    // 0x8006F304: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F308: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F30C: jr          $ra
    // 0x8006F310: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F310: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F314: jr          $ra
    // 0x8006F318: nop

    return;
    // 0x8006F318: nop

    // 0x8006F31C: jr          $ra
    // 0x8006F320: nop

    return;
    // 0x8006F320: nop

;}
RECOMP_FUNC void func_8006F324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F324: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F328: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F32C: nop

    // 0x8006F330: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F334: nop

    // 0x8006F338: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F33C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F340: jr          $ra
    // 0x8006F344: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F344: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F348: jr          $ra
    // 0x8006F34C: nop

    return;
    // 0x8006F34C: nop

    // 0x8006F350: jr          $ra
    // 0x8006F354: nop

    return;
    // 0x8006F354: nop

;}
RECOMP_FUNC void func_8006F358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F358: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F35C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F360: nop

    // 0x8006F364: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F368: nop

    // 0x8006F36C: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006F370: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F374: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F378: beq         $v0, $zero, L_8006F390
    if (ctx->r2 == 0) {
        // 0x8006F37C: nop

            goto L_8006F390;
    }
    // 0x8006F37C: nop

    // 0x8006F380: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F384: nop

    // 0x8006F388: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F38C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006F390:
    // 0x8006F390: jr          $ra
    // 0x8006F394: nop

    return;
    // 0x8006F394: nop

    // 0x8006F398: jr          $ra
    // 0x8006F39C: nop

    return;
    // 0x8006F39C: nop

    // 0x8006F3A0: jr          $ra
    // 0x8006F3A4: nop

    return;
    // 0x8006F3A4: nop

;}
RECOMP_FUNC void func_8006F3A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F3A8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F3AC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F3B0: nop

    // 0x8006F3B4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F3B8: nop

    // 0x8006F3BC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006F3C0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F3C4: jr          $ra
    // 0x8006F3C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F3C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F3CC: jr          $ra
    // 0x8006F3D0: nop

    return;
    // 0x8006F3D0: nop

    // 0x8006F3D4: jr          $ra
    // 0x8006F3D8: nop

    return;
    // 0x8006F3D8: nop

;}
RECOMP_FUNC void func_8006F3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F3DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F3E0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F3E4: nop

    // 0x8006F3E8: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F3EC: nop

    // 0x8006F3F0: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006F3F4: jr          $ra
    // 0x8006F3F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F3F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F3FC: jr          $ra
    // 0x8006F400: nop

    return;
    // 0x8006F400: nop

    // 0x8006F404: jr          $ra
    // 0x8006F408: nop

    return;
    // 0x8006F408: nop

;}
RECOMP_FUNC void func_8006F40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F40C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F410: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F414: nop

    // 0x8006F418: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F41C: nop

    // 0x8006F420: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F424: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F428: jr          $ra
    // 0x8006F42C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F42C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F430: jr          $ra
    // 0x8006F434: nop

    return;
    // 0x8006F434: nop

    // 0x8006F438: jr          $ra
    // 0x8006F43C: nop

    return;
    // 0x8006F43C: nop

;}
RECOMP_FUNC void func_8006F440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F440: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F444: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F448: nop

    // 0x8006F44C: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F450: nop

    // 0x8006F454: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006F458: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F45C: jr          $ra
    // 0x8006F460: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F460: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F464: jr          $ra
    // 0x8006F468: nop

    return;
    // 0x8006F468: nop

    // 0x8006F46C: jr          $ra
    // 0x8006F470: nop

    return;
    // 0x8006F470: nop

;}
RECOMP_FUNC void func_8006F474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F474: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F478: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F47C: nop

    // 0x8006F480: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F484: nop

    // 0x8006F488: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F48C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F490: jr          $ra
    // 0x8006F494: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F494: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F498: jr          $ra
    // 0x8006F49C: nop

    return;
    // 0x8006F49C: nop

    // 0x8006F4A0: jr          $ra
    // 0x8006F4A4: nop

    return;
    // 0x8006F4A4: nop

;}
RECOMP_FUNC void func_8006F4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F4A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F4AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F4B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F4B4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F4B8: nop

    // 0x8006F4BC: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006F4C0: nop

    // 0x8006F4C4: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x8006F4C8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F4CC: beq         $v0, $zero, L_8006F4E8
    if (ctx->r2 == 0) {
        // 0x8006F4D0: nop

            goto L_8006F4E8;
    }
    // 0x8006F4D0: nop

    // 0x8006F4D4: jal         0x80061488
    // 0x8006F4D8: addiu       $a0, $zero, 0x575
    ctx->r4 = ADD32(0, 0X575);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006F4D8: addiu       $a0, $zero, 0x575
    ctx->r4 = ADD32(0, 0X575);
    after_0:
    // 0x8006F4DC: slti        $t8, $v0, 0x2
    ctx->r24 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006F4E0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006F4E4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006F4E8:
    // 0x8006F4E8: b           L_8006F4F8
    // 0x8006F4EC: nop

        goto L_8006F4F8;
    // 0x8006F4EC: nop

    // 0x8006F4F0: b           L_8006F4F8
    // 0x8006F4F4: nop

        goto L_8006F4F8;
    // 0x8006F4F4: nop

L_8006F4F8:
    // 0x8006F4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F500: jr          $ra
    // 0x8006F504: nop

    return;
    // 0x8006F504: nop

;}
RECOMP_FUNC void func_8006F508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F508: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F50C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F510: nop

    // 0x8006F514: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006F518: nop

    // 0x8006F51C: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x8006F520: jr          $ra
    // 0x8006F524: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F524: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F528: jr          $ra
    // 0x8006F52C: nop

    return;
    // 0x8006F52C: nop

    // 0x8006F530: jr          $ra
    // 0x8006F534: nop

    return;
    // 0x8006F534: nop

;}
RECOMP_FUNC void func_8006F538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F538: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F53C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F540: nop

    // 0x8006F544: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F548: nop

    // 0x8006F54C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006F550: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F554: jr          $ra
    // 0x8006F558: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F558: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F55C: jr          $ra
    // 0x8006F560: nop

    return;
    // 0x8006F560: nop

    // 0x8006F564: jr          $ra
    // 0x8006F568: nop

    return;
    // 0x8006F568: nop

;}
RECOMP_FUNC void func_8006F56C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F56C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F570: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F574: nop

    // 0x8006F578: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F57C: nop

    // 0x8006F580: slti        $t7, $v0, 0x385
    ctx->r15 = SIGNED(ctx->r2) < 0X385 ? 1 : 0;
    // 0x8006F584: jr          $ra
    // 0x8006F588: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F588: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F58C: jr          $ra
    // 0x8006F590: nop

    return;
    // 0x8006F590: nop

    // 0x8006F594: jr          $ra
    // 0x8006F598: nop

    return;
    // 0x8006F598: nop

;}
RECOMP_FUNC void func_8006F59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F59C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F5A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F5A4: jal         0x80061488
    // 0x8006F5A8: addiu       $a0, $zero, 0x3BB
    ctx->r4 = ADD32(0, 0X3BB);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006F5A8: addiu       $a0, $zero, 0x3BB
    ctx->r4 = ADD32(0, 0X3BB);
    after_0:
    // 0x8006F5AC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006F5B0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006F5B4: b           L_8006F5C4
    // 0x8006F5B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F5C4;
    // 0x8006F5B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F5BC: b           L_8006F5C4
    // 0x8006F5C0: nop

        goto L_8006F5C4;
    // 0x8006F5C0: nop

L_8006F5C4:
    // 0x8006F5C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F5C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F5CC: jr          $ra
    // 0x8006F5D0: nop

    return;
    // 0x8006F5D0: nop

;}
RECOMP_FUNC void func_8006F5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F5D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F5D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F5DC: nop

    // 0x8006F5E0: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x8006F5E4: nop

    // 0x8006F5E8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F5EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F5F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F5F4: bne         $v0, $zero, L_8006F648
    if (ctx->r2 != 0) {
        // 0x8006F5F8: nop

            goto L_8006F648;
    }
    // 0x8006F5F8: nop

    // 0x8006F5FC: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x8006F600: nop

    // 0x8006F604: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F608: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006F60C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006F610: bne         $v0, $zero, L_8006F648
    if (ctx->r2 != 0) {
        // 0x8006F614: nop

            goto L_8006F648;
    }
    // 0x8006F614: nop

    // 0x8006F618: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x8006F61C: nop

    // 0x8006F620: slti        $t9, $v0, 0x1F4
    ctx->r25 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F624: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x8006F628: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8006F62C: bne         $v0, $zero, L_8006F648
    if (ctx->r2 != 0) {
        // 0x8006F630: nop

            goto L_8006F648;
    }
    // 0x8006F630: nop

    // 0x8006F634: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x8006F638: nop

    // 0x8006F63C: slti        $t0, $v0, 0x1F4
    ctx->r8 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F640: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x8006F644: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006F648:
    // 0x8006F648: jr          $ra
    // 0x8006F64C: nop

    return;
    // 0x8006F64C: nop

    // 0x8006F650: jr          $ra
    // 0x8006F654: nop

    return;
    // 0x8006F654: nop

    // 0x8006F658: jr          $ra
    // 0x8006F65C: nop

    return;
    // 0x8006F65C: nop

;}
RECOMP_FUNC void func_8006F660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F660: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F664: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F668: nop

    // 0x8006F66C: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x8006F670: nop

    // 0x8006F674: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F678: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F67C: jr          $ra
    // 0x8006F680: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F680: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F684: jr          $ra
    // 0x8006F688: nop

    return;
    // 0x8006F688: nop

    // 0x8006F68C: jr          $ra
    // 0x8006F690: nop

    return;
    // 0x8006F690: nop

;}
RECOMP_FUNC void func_8006F694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F694: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F698: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F69C: nop

    // 0x8006F6A0: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x8006F6A4: nop

    // 0x8006F6A8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F6AC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F6B0: jr          $ra
    // 0x8006F6B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F6B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F6B8: jr          $ra
    // 0x8006F6BC: nop

    return;
    // 0x8006F6BC: nop

    // 0x8006F6C0: jr          $ra
    // 0x8006F6C4: nop

    return;
    // 0x8006F6C4: nop

;}
RECOMP_FUNC void func_8006F6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F6C8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F6CC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F6D0: nop

    // 0x8006F6D4: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x8006F6D8: nop

    // 0x8006F6DC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F6E0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F6E4: jr          $ra
    // 0x8006F6E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F6E8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F6EC: jr          $ra
    // 0x8006F6F0: nop

    return;
    // 0x8006F6F0: nop

    // 0x8006F6F4: jr          $ra
    // 0x8006F6F8: nop

    return;
    // 0x8006F6F8: nop

;}
RECOMP_FUNC void func_8006F6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F6FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F700: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F704: nop

    // 0x8006F708: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x8006F70C: nop

    // 0x8006F710: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F714: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F718: jr          $ra
    // 0x8006F71C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F71C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F720: jr          $ra
    // 0x8006F724: nop

    return;
    // 0x8006F724: nop

    // 0x8006F728: jr          $ra
    // 0x8006F72C: nop

    return;
    // 0x8006F72C: nop

;}
RECOMP_FUNC void func_8006F730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F738: jal         0x8005F064
    // 0x8006F73C: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006F73C: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    after_0:
    // 0x8006F740: b           L_8006F750
    // 0x8006F744: nop

        goto L_8006F750;
    // 0x8006F744: nop

    // 0x8006F748: b           L_8006F750
    // 0x8006F74C: nop

        goto L_8006F750;
    // 0x8006F74C: nop

L_8006F750:
    // 0x8006F750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F758: jr          $ra
    // 0x8006F75C: nop

    return;
    // 0x8006F75C: nop

;}
RECOMP_FUNC void func_8006F760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F768: jal         0x80061488
    // 0x8006F76C: addiu       $a0, $zero, 0x3C8
    ctx->r4 = ADD32(0, 0X3C8);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006F76C: addiu       $a0, $zero, 0x3C8
    ctx->r4 = ADD32(0, 0X3C8);
    after_0:
    // 0x8006F770: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006F774: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006F778: b           L_8006F788
    // 0x8006F77C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F788;
    // 0x8006F77C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F780: b           L_8006F788
    // 0x8006F784: nop

        goto L_8006F788;
    // 0x8006F784: nop

L_8006F788:
    // 0x8006F788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F78C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F790: jr          $ra
    // 0x8006F794: nop

    return;
    // 0x8006F794: nop

;}
RECOMP_FUNC void func_8006F798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F798: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F79C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F7A0: nop

    // 0x8006F7A4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006F7A8: nop

    // 0x8006F7AC: slti        $t7, $v0, 0x1F5
    ctx->r15 = SIGNED(ctx->r2) < 0X1F5 ? 1 : 0;
    // 0x8006F7B0: jr          $ra
    // 0x8006F7B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F7B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F7B8: jr          $ra
    // 0x8006F7BC: nop

    return;
    // 0x8006F7BC: nop

    // 0x8006F7C0: jr          $ra
    // 0x8006F7C4: nop

    return;
    // 0x8006F7C4: nop

;}
RECOMP_FUNC void func_8006F7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F7CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F7D0: jal         0x80061488
    // 0x8006F7D4: addiu       $a0, $zero, 0x3D3
    ctx->r4 = ADD32(0, 0X3D3);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006F7D4: addiu       $a0, $zero, 0x3D3
    ctx->r4 = ADD32(0, 0X3D3);
    after_0:
    // 0x8006F7D8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006F7DC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006F7E0: b           L_8006F7F0
    // 0x8006F7E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F7F0;
    // 0x8006F7E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F7E8: b           L_8006F7F0
    // 0x8006F7EC: nop

        goto L_8006F7F0;
    // 0x8006F7EC: nop

L_8006F7F0:
    // 0x8006F7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F7F8: jr          $ra
    // 0x8006F7FC: nop

    return;
    // 0x8006F7FC: nop

;}
RECOMP_FUNC void func_8006F800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F800: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F804: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F808: nop

    // 0x8006F80C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8006F810: nop

    // 0x8006F814: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8006F818: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F81C: jr          $ra
    // 0x8006F820: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006F820: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F824: jr          $ra
    // 0x8006F828: nop

    return;
    // 0x8006F828: nop

    // 0x8006F82C: jr          $ra
    // 0x8006F830: nop

    return;
    // 0x8006F830: nop

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
RECOMP_FUNC void func_8006F8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F8C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F8C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F8CC: jal         0x80061348
    // 0x8006F8D0: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F8D0: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006F8D4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F8D8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F8DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F8E0: beq         $v0, $zero, L_8006F934
    if (ctx->r2 == 0) {
        // 0x8006F8E4: nop

            goto L_8006F934;
    }
    // 0x8006F8E4: nop

    // 0x8006F8E8: jal         0x80061348
    // 0x8006F8EC: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006F8EC: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006F8F0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006F8F4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006F8F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F8FC: beq         $v0, $zero, L_8006F934
    if (ctx->r2 == 0) {
        // 0x8006F900: nop

            goto L_8006F934;
    }
    // 0x8006F900: nop

    // 0x8006F904: jal         0x80061348
    // 0x8006F908: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006F908: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006F90C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006F910: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006F914: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006F918: beq         $v0, $zero, L_8006F934
    if (ctx->r2 == 0) {
        // 0x8006F91C: nop

            goto L_8006F934;
    }
    // 0x8006F91C: nop

    // 0x8006F920: jal         0x80061348
    // 0x8006F924: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006F924: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006F928: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006F92C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006F930: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006F934:
    // 0x8006F934: b           L_8006F944
    // 0x8006F938: nop

        goto L_8006F944;
    // 0x8006F938: nop

    // 0x8006F93C: b           L_8006F944
    // 0x8006F940: nop

        goto L_8006F944;
    // 0x8006F940: nop

L_8006F944:
    // 0x8006F944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F94C: jr          $ra
    // 0x8006F950: nop

    return;
    // 0x8006F950: nop

;}
RECOMP_FUNC void func_8006F954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F954: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006F958: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006F95C: nop

    // 0x8006F960: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x8006F964: nop

    // 0x8006F968: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F96C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006F970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006F974: beq         $v0, $zero, L_8006F990
    if (ctx->r2 == 0) {
        // 0x8006F978: nop

            goto L_8006F990;
    }
    // 0x8006F978: nop

    // 0x8006F97C: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x8006F980: nop

    // 0x8006F984: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006F988: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006F98C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006F990:
    // 0x8006F990: jr          $ra
    // 0x8006F994: nop

    return;
    // 0x8006F994: nop

    // 0x8006F998: jr          $ra
    // 0x8006F99C: nop

    return;
    // 0x8006F99C: nop

    // 0x8006F9A0: jr          $ra
    // 0x8006F9A4: nop

    return;
    // 0x8006F9A4: nop

;}
RECOMP_FUNC void func_8006F9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F9B0: jal         0x80061348
    // 0x8006F9B4: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F9B4: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006F9B8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F9BC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F9C0: b           L_8006F9D0
    // 0x8006F9C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006F9D0;
    // 0x8006F9C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006F9C8: b           L_8006F9D0
    // 0x8006F9CC: nop

        goto L_8006F9D0;
    // 0x8006F9CC: nop

L_8006F9D0:
    // 0x8006F9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F9D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F9D8: jr          $ra
    // 0x8006F9DC: nop

    return;
    // 0x8006F9DC: nop

;}
RECOMP_FUNC void func_8006F9E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F9E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F9E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F9E8: jal         0x80061348
    // 0x8006F9EC: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006F9EC: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006F9F0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006F9F4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006F9F8: b           L_8006FA08
    // 0x8006F9FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006FA08;
    // 0x8006F9FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FA00: b           L_8006FA08
    // 0x8006FA04: nop

        goto L_8006FA08;
    // 0x8006FA04: nop

L_8006FA08:
    // 0x8006FA08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FA0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FA10: jr          $ra
    // 0x8006FA14: nop

    return;
    // 0x8006FA14: nop

;}
RECOMP_FUNC void func_8006FA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FA18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FA1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FA20: jal         0x80061348
    // 0x8006FA24: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FA24: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FA28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FA2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FA30: b           L_8006FA40
    // 0x8006FA34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006FA40;
    // 0x8006FA34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FA38: b           L_8006FA40
    // 0x8006FA3C: nop

        goto L_8006FA40;
    // 0x8006FA3C: nop

L_8006FA40:
    // 0x8006FA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FA44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FA48: jr          $ra
    // 0x8006FA4C: nop

    return;
    // 0x8006FA4C: nop

;}
RECOMP_FUNC void func_8006FA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FA50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FA54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FA58: jal         0x80061488
    // 0x8006FA5C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006FA5C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_0:
    // 0x8006FA60: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FA64: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FA68: b           L_8006FA78
    // 0x8006FA6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006FA78;
    // 0x8006FA6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FA70: b           L_8006FA78
    // 0x8006FA74: nop

        goto L_8006FA78;
    // 0x8006FA74: nop

L_8006FA78:
    // 0x8006FA78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FA7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FA80: jr          $ra
    // 0x8006FA84: nop

    return;
    // 0x8006FA84: nop

;}
RECOMP_FUNC void func_8006FA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FA88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FA90: jal         0x80061348
    // 0x8006FA94: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FA94: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FA98: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FA9C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FAA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FAA4: beq         $v0, $zero, L_8006FAF8
    if (ctx->r2 == 0) {
        // 0x8006FAA8: nop

            goto L_8006FAF8;
    }
    // 0x8006FAA8: nop

    // 0x8006FAAC: jal         0x80061348
    // 0x8006FAB0: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FAB0: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FAB4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FAB8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FABC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FAC0: beq         $v0, $zero, L_8006FAF8
    if (ctx->r2 == 0) {
        // 0x8006FAC4: nop

            goto L_8006FAF8;
    }
    // 0x8006FAC4: nop

    // 0x8006FAC8: jal         0x80061348
    // 0x8006FACC: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FACC: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FAD0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FAD4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FAD8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FADC: beq         $v0, $zero, L_8006FAF8
    if (ctx->r2 == 0) {
        // 0x8006FAE0: nop

            goto L_8006FAF8;
    }
    // 0x8006FAE0: nop

    // 0x8006FAE4: jal         0x80061348
    // 0x8006FAE8: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FAE8: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FAEC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FAF0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FAF4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FAF8:
    // 0x8006FAF8: b           L_8006FB08
    // 0x8006FAFC: nop

        goto L_8006FB08;
    // 0x8006FAFC: nop

    // 0x8006FB00: b           L_8006FB08
    // 0x8006FB04: nop

        goto L_8006FB08;
    // 0x8006FB04: nop

L_8006FB08:
    // 0x8006FB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FB0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FB10: jr          $ra
    // 0x8006FB14: nop

    return;
    // 0x8006FB14: nop

;}
RECOMP_FUNC void func_8006FB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FB1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FB20: jal         0x80061348
    // 0x8006FB24: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FB24: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FB28: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FB2C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FB30: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FB34: beq         $v0, $zero, L_8006FB88
    if (ctx->r2 == 0) {
        // 0x8006FB38: nop

            goto L_8006FB88;
    }
    // 0x8006FB38: nop

    // 0x8006FB3C: jal         0x80061348
    // 0x8006FB40: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FB40: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FB44: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FB48: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FB4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FB50: beq         $v0, $zero, L_8006FB88
    if (ctx->r2 == 0) {
        // 0x8006FB54: nop

            goto L_8006FB88;
    }
    // 0x8006FB54: nop

    // 0x8006FB58: jal         0x80061348
    // 0x8006FB5C: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FB5C: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FB60: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FB64: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FB68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FB6C: beq         $v0, $zero, L_8006FB88
    if (ctx->r2 == 0) {
        // 0x8006FB70: nop

            goto L_8006FB88;
    }
    // 0x8006FB70: nop

    // 0x8006FB74: jal         0x80061348
    // 0x8006FB78: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FB78: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FB7C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FB80: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FB84: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FB88:
    // 0x8006FB88: b           L_8006FB98
    // 0x8006FB8C: nop

        goto L_8006FB98;
    // 0x8006FB8C: nop

    // 0x8006FB90: b           L_8006FB98
    // 0x8006FB94: nop

        goto L_8006FB98;
    // 0x8006FB94: nop

L_8006FB98:
    // 0x8006FB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FB9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FBA0: jr          $ra
    // 0x8006FBA4: nop

    return;
    // 0x8006FBA4: nop

;}
RECOMP_FUNC void func_8006FBA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FBA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006FBAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006FBB0: nop

    // 0x8006FBB4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006FBB8: nop

    // 0x8006FBBC: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006FBC0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006FBC4: jr          $ra
    // 0x8006FBC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006FBC8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FBCC: jr          $ra
    // 0x8006FBD0: nop

    return;
    // 0x8006FBD0: nop

    // 0x8006FBD4: jr          $ra
    // 0x8006FBD8: nop

    return;
    // 0x8006FBD8: nop

;}
RECOMP_FUNC void func_8006FBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FBDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FBE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FBE4: jal         0x80061348
    // 0x8006FBE8: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FBE8: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FBEC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FBF0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FBF4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FBF8: beq         $v0, $zero, L_8006FC4C
    if (ctx->r2 == 0) {
        // 0x8006FBFC: nop

            goto L_8006FC4C;
    }
    // 0x8006FBFC: nop

    // 0x8006FC00: jal         0x80061348
    // 0x8006FC04: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FC04: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FC08: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FC0C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FC10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FC14: beq         $v0, $zero, L_8006FC4C
    if (ctx->r2 == 0) {
        // 0x8006FC18: nop

            goto L_8006FC4C;
    }
    // 0x8006FC18: nop

    // 0x8006FC1C: jal         0x80061348
    // 0x8006FC20: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FC20: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FC24: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FC28: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FC2C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FC30: beq         $v0, $zero, L_8006FC4C
    if (ctx->r2 == 0) {
        // 0x8006FC34: nop

            goto L_8006FC4C;
    }
    // 0x8006FC34: nop

    // 0x8006FC38: jal         0x80061348
    // 0x8006FC3C: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FC3C: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FC40: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FC44: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FC48: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FC4C:
    // 0x8006FC4C: b           L_8006FC5C
    // 0x8006FC50: nop

        goto L_8006FC5C;
    // 0x8006FC50: nop

    // 0x8006FC54: b           L_8006FC5C
    // 0x8006FC58: nop

        goto L_8006FC5C;
    // 0x8006FC58: nop

L_8006FC5C:
    // 0x8006FC5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FC60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FC64: jr          $ra
    // 0x8006FC68: nop

    return;
    // 0x8006FC68: nop

;}
RECOMP_FUNC void func_8006FC6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FC74: jal         0x80061348
    // 0x8006FC78: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FC78: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FC7C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FC80: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FC84: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FC88: beq         $v0, $zero, L_8006FCDC
    if (ctx->r2 == 0) {
        // 0x8006FC8C: nop

            goto L_8006FCDC;
    }
    // 0x8006FC8C: nop

    // 0x8006FC90: jal         0x80061348
    // 0x8006FC94: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FC94: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FC98: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FC9C: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FCA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FCA4: beq         $v0, $zero, L_8006FCDC
    if (ctx->r2 == 0) {
        // 0x8006FCA8: nop

            goto L_8006FCDC;
    }
    // 0x8006FCA8: nop

    // 0x8006FCAC: jal         0x80061348
    // 0x8006FCB0: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FCB0: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FCB4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FCB8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FCBC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FCC0: beq         $v0, $zero, L_8006FCDC
    if (ctx->r2 == 0) {
        // 0x8006FCC4: nop

            goto L_8006FCDC;
    }
    // 0x8006FCC4: nop

    // 0x8006FCC8: jal         0x80061348
    // 0x8006FCCC: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FCCC: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FCD0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FCD4: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FCD8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FCDC:
    // 0x8006FCDC: b           L_8006FCEC
    // 0x8006FCE0: nop

        goto L_8006FCEC;
    // 0x8006FCE0: nop

    // 0x8006FCE4: b           L_8006FCEC
    // 0x8006FCE8: nop

        goto L_8006FCEC;
    // 0x8006FCE8: nop

L_8006FCEC:
    // 0x8006FCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FCF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FCF4: jr          $ra
    // 0x8006FCF8: nop

    return;
    // 0x8006FCF8: nop

;}
RECOMP_FUNC void func_8006FCFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FCFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FD00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FD04: jal         0x80061488
    // 0x8006FD08: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006FD08: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    after_0:
    // 0x8006FD0C: slti        $t6, $v0, 0xA
    ctx->r14 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8006FD10: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006FD14: b           L_8006FD24
    // 0x8006FD18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006FD24;
    // 0x8006FD18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FD1C: b           L_8006FD24
    // 0x8006FD20: nop

        goto L_8006FD24;
    // 0x8006FD20: nop

L_8006FD24:
    // 0x8006FD24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FD28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FD2C: jr          $ra
    // 0x8006FD30: nop

    return;
    // 0x8006FD30: nop

;}
RECOMP_FUNC void func_8006FD34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FD34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FD3C: jal         0x80061348
    // 0x8006FD40: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FD40: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FD44: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FD48: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FD4C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FD50: beq         $v0, $zero, L_8006FDA4
    if (ctx->r2 == 0) {
        // 0x8006FD54: nop

            goto L_8006FDA4;
    }
    // 0x8006FD54: nop

    // 0x8006FD58: jal         0x80061348
    // 0x8006FD5C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FD5C: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FD60: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FD64: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FD68: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FD6C: beq         $v0, $zero, L_8006FDA4
    if (ctx->r2 == 0) {
        // 0x8006FD70: nop

            goto L_8006FDA4;
    }
    // 0x8006FD70: nop

    // 0x8006FD74: jal         0x80061348
    // 0x8006FD78: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FD78: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FD7C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FD80: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FD84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FD88: beq         $v0, $zero, L_8006FDA4
    if (ctx->r2 == 0) {
        // 0x8006FD8C: nop

            goto L_8006FDA4;
    }
    // 0x8006FD8C: nop

    // 0x8006FD90: jal         0x80061348
    // 0x8006FD94: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FD94: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FD98: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FD9C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FDA0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FDA4:
    // 0x8006FDA4: b           L_8006FDB4
    // 0x8006FDA8: nop

        goto L_8006FDB4;
    // 0x8006FDA8: nop

    // 0x8006FDAC: b           L_8006FDB4
    // 0x8006FDB0: nop

        goto L_8006FDB4;
    // 0x8006FDB0: nop

L_8006FDB4:
    // 0x8006FDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FDB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FDBC: jr          $ra
    // 0x8006FDC0: nop

    return;
    // 0x8006FDC0: nop

;}
RECOMP_FUNC void func_8006FDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FDC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FDC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FDCC: jal         0x80061348
    // 0x8006FDD0: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FDD0: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    after_0:
    // 0x8006FDD4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006FDD8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006FDDC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FDE0: beq         $v0, $zero, L_8006FE34
    if (ctx->r2 == 0) {
        // 0x8006FDE4: nop

            goto L_8006FE34;
    }
    // 0x8006FDE4: nop

    // 0x8006FDE8: jal         0x80061348
    // 0x8006FDEC: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FDEC: addiu       $a0, $zero, 0x3D6
    ctx->r4 = ADD32(0, 0X3D6);
    after_1:
    // 0x8006FDF0: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FDF4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FDF8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FDFC: beq         $v0, $zero, L_8006FE34
    if (ctx->r2 == 0) {
        // 0x8006FE00: nop

            goto L_8006FE34;
    }
    // 0x8006FE00: nop

    // 0x8006FE04: jal         0x80061348
    // 0x8006FE08: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8006FE08: addiu       $a0, $zero, 0x3D0
    ctx->r4 = ADD32(0, 0X3D0);
    after_2:
    // 0x8006FE0C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8006FE10: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x8006FE14: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8006FE18: beq         $v0, $zero, L_8006FE34
    if (ctx->r2 == 0) {
        // 0x8006FE1C: nop

            goto L_8006FE34;
    }
    // 0x8006FE1C: nop

    // 0x8006FE20: jal         0x80061348
    // 0x8006FE24: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006FE24: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_3:
    // 0x8006FE28: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8006FE2C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006FE30: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8006FE34:
    // 0x8006FE34: b           L_8006FE44
    // 0x8006FE38: nop

        goto L_8006FE44;
    // 0x8006FE38: nop

    // 0x8006FE3C: b           L_8006FE44
    // 0x8006FE40: nop

        goto L_8006FE44;
    // 0x8006FE40: nop

L_8006FE44:
    // 0x8006FE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FE48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FE4C: jr          $ra
    // 0x8006FE50: nop

    return;
    // 0x8006FE50: nop

;}
RECOMP_FUNC void func_8006FE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FE54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FE5C: jal         0x80061348
    // 0x8006FE60: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FE60: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    after_0:
    // 0x8006FE64: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006FE68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FE6C: bne         $v0, $zero, L_8006FE88
    if (ctx->r2 != 0) {
        // 0x8006FE70: nop

            goto L_8006FE88;
    }
    // 0x8006FE70: nop

    // 0x8006FE74: jal         0x80061348
    // 0x8006FE78: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FE78: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_1:
    // 0x8006FE7C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FE80: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FE84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006FE88:
    // 0x8006FE88: b           L_8006FE98
    // 0x8006FE8C: nop

        goto L_8006FE98;
    // 0x8006FE8C: nop

    // 0x8006FE90: b           L_8006FE98
    // 0x8006FE94: nop

        goto L_8006FE98;
    // 0x8006FE94: nop

L_8006FE98:
    // 0x8006FE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FE9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FEA0: jr          $ra
    // 0x8006FEA4: nop

    return;
    // 0x8006FEA4: nop

;}
RECOMP_FUNC void func_8006FEA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FEA8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006FEAC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006FEB0: nop

    // 0x8006FEB4: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006FEB8: nop

    // 0x8006FEBC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x8006FEC0: jr          $ra
    // 0x8006FEC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006FEC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FEC8: jr          $ra
    // 0x8006FECC: nop

    return;
    // 0x8006FECC: nop

    // 0x8006FED0: jr          $ra
    // 0x8006FED4: nop

    return;
    // 0x8006FED4: nop

;}
RECOMP_FUNC void func_8006FED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FEDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FEE0: jal         0x80061348
    // 0x8006FEE4: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FEE4: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    after_0:
    // 0x8006FEE8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006FEEC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FEF0: bne         $v0, $zero, L_8006FF0C
    if (ctx->r2 != 0) {
        // 0x8006FEF4: nop

            goto L_8006FF0C;
    }
    // 0x8006FEF4: nop

    // 0x8006FEF8: jal         0x80061348
    // 0x8006FEFC: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FEFC: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_1:
    // 0x8006FF00: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FF04: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FF08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006FF0C:
    // 0x8006FF0C: b           L_8006FF1C
    // 0x8006FF10: nop

        goto L_8006FF1C;
    // 0x8006FF10: nop

    // 0x8006FF14: b           L_8006FF1C
    // 0x8006FF18: nop

        goto L_8006FF1C;
    // 0x8006FF18: nop

L_8006FF1C:
    // 0x8006FF1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FF20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FF24: jr          $ra
    // 0x8006FF28: nop

    return;
    // 0x8006FF28: nop

;}
RECOMP_FUNC void func_8006FF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FF2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FF30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FF34: jal         0x80061348
    // 0x8006FF38: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FF38: addiu       $a0, $zero, 0x3D7
    ctx->r4 = ADD32(0, 0X3D7);
    after_0:
    // 0x8006FF3C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006FF40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006FF44: bne         $v0, $zero, L_8006FF60
    if (ctx->r2 != 0) {
        // 0x8006FF48: nop

            goto L_8006FF60;
    }
    // 0x8006FF48: nop

    // 0x8006FF4C: jal         0x80061348
    // 0x8006FF50: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006FF50: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_1:
    // 0x8006FF54: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x8006FF58: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8006FF5C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006FF60:
    // 0x8006FF60: b           L_8006FF70
    // 0x8006FF64: nop

        goto L_8006FF70;
    // 0x8006FF64: nop

    // 0x8006FF68: b           L_8006FF70
    // 0x8006FF6C: nop

        goto L_8006FF70;
    // 0x8006FF6C: nop

L_8006FF70:
    // 0x8006FF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FF74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FF78: jr          $ra
    // 0x8006FF7C: nop

    return;
    // 0x8006FF7C: nop

;}
