#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800662A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800662AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800662B0: jal         0x80061348
    // 0x800662B4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800662B4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x800662B8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800662BC: b           L_800662CC
    // 0x800662C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800662CC;
    // 0x800662C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800662C4: b           L_800662CC
    // 0x800662C8: nop

        goto L_800662CC;
    // 0x800662C8: nop

L_800662CC:
    // 0x800662CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800662D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800662D4: jr          $ra
    // 0x800662D8: nop

    return;
    // 0x800662D8: nop

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
RECOMP_FUNC void func_80066310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066318: jal         0x80061348
    // 0x8006631C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006631C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066320: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066324: b           L_80066334
    // 0x80066328: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066334;
    // 0x80066328: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006632C: b           L_80066334
    // 0x80066330: nop

        goto L_80066334;
    // 0x80066330: nop

L_80066334:
    // 0x80066334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006633C: jr          $ra
    // 0x80066340: nop

    return;
    // 0x80066340: nop

;}
RECOMP_FUNC void func_80066344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006634C: jal         0x80061348
    // 0x80066350: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066350: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066354: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066358: b           L_80066368
    // 0x8006635C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066368;
    // 0x8006635C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066360: b           L_80066368
    // 0x80066364: nop

        goto L_80066368;
    // 0x80066364: nop

L_80066368:
    // 0x80066368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006636C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066370: jr          $ra
    // 0x80066374: nop

    return;
    // 0x80066374: nop

;}
RECOMP_FUNC void func_80066378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006637C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066380: jal         0x80061348
    // 0x80066384: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066384: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066388: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006638C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066390: beq         $v0, $zero, L_800663A8
    if (ctx->r2 == 0) {
        // 0x80066394: nop

            goto L_800663A8;
    }
    // 0x80066394: nop

    // 0x80066398: jal         0x80061348
    // 0x8006639C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006639C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x800663A0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800663A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800663A8:
    // 0x800663A8: b           L_800663B8
    // 0x800663AC: nop

        goto L_800663B8;
    // 0x800663AC: nop

    // 0x800663B0: b           L_800663B8
    // 0x800663B4: nop

        goto L_800663B8;
    // 0x800663B4: nop

L_800663B8:
    // 0x800663B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800663BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800663C0: jr          $ra
    // 0x800663C4: nop

    return;
    // 0x800663C4: nop

;}
RECOMP_FUNC void func_800663C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800663C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800663CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800663D0: jal         0x80061348
    // 0x800663D4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800663D4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x800663D8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800663DC: b           L_800663EC
    // 0x800663E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800663EC;
    // 0x800663E0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800663E4: b           L_800663EC
    // 0x800663E8: nop

        goto L_800663EC;
    // 0x800663E8: nop

L_800663EC:
    // 0x800663EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800663F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800663F4: jr          $ra
    // 0x800663F8: nop

    return;
    // 0x800663F8: nop

;}
RECOMP_FUNC void func_800663FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800663FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066404: jal         0x80061348
    // 0x80066408: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066408: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x8006640C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066410: b           L_80066420
    // 0x80066414: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066420;
    // 0x80066414: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066418: b           L_80066420
    // 0x8006641C: nop

        goto L_80066420;
    // 0x8006641C: nop

L_80066420:
    // 0x80066420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066428: jr          $ra
    // 0x8006642C: nop

    return;
    // 0x8006642C: nop

;}
RECOMP_FUNC void func_80066430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066438: jal         0x80061348
    // 0x8006643C: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006643C: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_0:
    // 0x80066440: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066444: b           L_80066454
    // 0x80066448: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066454;
    // 0x80066448: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006644C: b           L_80066454
    // 0x80066450: nop

        goto L_80066454;
    // 0x80066450: nop

L_80066454:
    // 0x80066454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006645C: jr          $ra
    // 0x80066460: nop

    return;
    // 0x80066460: nop

;}
RECOMP_FUNC void func_80066464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006646C: jal         0x80061348
    // 0x80066470: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066470: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066474: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066478: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006647C: beq         $v0, $zero, L_80066494
    if (ctx->r2 == 0) {
        // 0x80066480: nop

            goto L_80066494;
    }
    // 0x80066480: nop

    // 0x80066484: jal         0x80061348
    // 0x80066488: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066488: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006648C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066490: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066494:
    // 0x80066494: b           L_800664A4
    // 0x80066498: nop

        goto L_800664A4;
    // 0x80066498: nop

    // 0x8006649C: b           L_800664A4
    // 0x800664A0: nop

        goto L_800664A4;
    // 0x800664A0: nop

L_800664A4:
    // 0x800664A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800664A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800664AC: jr          $ra
    // 0x800664B0: nop

    return;
    // 0x800664B0: nop

;}
RECOMP_FUNC void func_800664B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800664B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800664B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800664BC: jal         0x80061348
    // 0x800664C0: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800664C0: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x800664C4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800664C8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800664CC: beq         $v0, $zero, L_800664E4
    if (ctx->r2 == 0) {
        // 0x800664D0: nop

            goto L_800664E4;
    }
    // 0x800664D0: nop

    // 0x800664D4: jal         0x80061348
    // 0x800664D8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800664D8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x800664DC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800664E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800664E4:
    // 0x800664E4: b           L_800664F4
    // 0x800664E8: nop

        goto L_800664F4;
    // 0x800664E8: nop

    // 0x800664EC: b           L_800664F4
    // 0x800664F0: nop

        goto L_800664F4;
    // 0x800664F0: nop

L_800664F4:
    // 0x800664F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800664F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800664FC: jr          $ra
    // 0x80066500: nop

    return;
    // 0x80066500: nop

;}
RECOMP_FUNC void func_80066504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006650C: jal         0x80061348
    // 0x80066510: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066510: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x80066514: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066518: b           L_80066528
    // 0x8006651C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066528;
    // 0x8006651C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066520: b           L_80066528
    // 0x80066524: nop

        goto L_80066528;
    // 0x80066524: nop

L_80066528:
    // 0x80066528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006652C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066530: jr          $ra
    // 0x80066534: nop

    return;
    // 0x80066534: nop

;}
RECOMP_FUNC void func_80066538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006653C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066540: jal         0x80061348
    // 0x80066544: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066544: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x80066548: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006654C: b           L_8006655C
    // 0x80066550: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006655C;
    // 0x80066550: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066554: b           L_8006655C
    // 0x80066558: nop

        goto L_8006655C;
    // 0x80066558: nop

L_8006655C:
    // 0x8006655C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066564: jr          $ra
    // 0x80066568: nop

    return;
    // 0x80066568: nop

;}
RECOMP_FUNC void func_8006656C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006656C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066574: jal         0x80061348
    // 0x80066578: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066578: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_0:
    // 0x8006657C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066580: b           L_80066590
    // 0x80066584: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066590;
    // 0x80066584: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066588: b           L_80066590
    // 0x8006658C: nop

        goto L_80066590;
    // 0x8006658C: nop

L_80066590:
    // 0x80066590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066598: jr          $ra
    // 0x8006659C: nop

    return;
    // 0x8006659C: nop

;}
RECOMP_FUNC void func_800665A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800665A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800665A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800665A8: jal         0x80061348
    // 0x800665AC: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800665AC: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x800665B0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800665B4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800665B8: beq         $v0, $zero, L_800665D0
    if (ctx->r2 == 0) {
        // 0x800665BC: nop

            goto L_800665D0;
    }
    // 0x800665BC: nop

    // 0x800665C0: jal         0x80061348
    // 0x800665C4: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800665C4: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x800665C8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800665CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800665D0:
    // 0x800665D0: b           L_800665E0
    // 0x800665D4: nop

        goto L_800665E0;
    // 0x800665D4: nop

    // 0x800665D8: b           L_800665E0
    // 0x800665DC: nop

        goto L_800665E0;
    // 0x800665DC: nop

L_800665E0:
    // 0x800665E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800665E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800665E8: jr          $ra
    // 0x800665EC: nop

    return;
    // 0x800665EC: nop

;}
RECOMP_FUNC void func_800665F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800665F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800665F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800665F8: jal         0x80061488
    // 0x800665FC: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800665FC: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    after_0:
    // 0x80066600: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80066604: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80066608: b           L_80066618
    // 0x8006660C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066618;
    // 0x8006660C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066610: b           L_80066618
    // 0x80066614: nop

        goto L_80066618;
    // 0x80066614: nop

L_80066618:
    // 0x80066618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006661C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066620: jr          $ra
    // 0x80066624: nop

    return;
    // 0x80066624: nop

;}
RECOMP_FUNC void func_80066628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006662C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066630: jal         0x80061348
    // 0x80066634: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066634: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_0:
    // 0x80066638: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006663C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066640: bne         $v0, $zero, L_80066688
    if (ctx->r2 != 0) {
        // 0x80066644: nop

            goto L_80066688;
    }
    // 0x80066644: nop

    // 0x80066648: jal         0x80061348
    // 0x8006664C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006664C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x80066650: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066654: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066658: bne         $v0, $zero, L_80066688
    if (ctx->r2 != 0) {
        // 0x8006665C: nop

            goto L_80066688;
    }
    // 0x8006665C: nop

    // 0x80066660: jal         0x80061348
    // 0x80066664: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80066664: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_2:
    // 0x80066668: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006666C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80066670: bne         $v0, $zero, L_80066688
    if (ctx->r2 != 0) {
        // 0x80066674: nop

            goto L_80066688;
    }
    // 0x80066674: nop

    // 0x80066678: jal         0x80061348
    // 0x8006667C: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x8006667C: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_3:
    // 0x80066680: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066684: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80066688:
    // 0x80066688: b           L_80066698
    // 0x8006668C: nop

        goto L_80066698;
    // 0x8006668C: nop

    // 0x80066690: b           L_80066698
    // 0x80066694: nop

        goto L_80066698;
    // 0x80066694: nop

L_80066698:
    // 0x80066698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006669C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800666A0: jr          $ra
    // 0x800666A4: nop

    return;
    // 0x800666A4: nop

;}
RECOMP_FUNC void func_800666A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800666A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800666AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800666B0: jal         0x80061348
    // 0x800666B4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800666B4: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    after_0:
    // 0x800666B8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800666BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800666C0: bne         $v0, $zero, L_80066708
    if (ctx->r2 != 0) {
        // 0x800666C4: nop

            goto L_80066708;
    }
    // 0x800666C4: nop

    // 0x800666C8: jal         0x80061348
    // 0x800666CC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800666CC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_1:
    // 0x800666D0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800666D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800666D8: bne         $v0, $zero, L_80066708
    if (ctx->r2 != 0) {
        // 0x800666DC: nop

            goto L_80066708;
    }
    // 0x800666DC: nop

    // 0x800666E0: jal         0x80061348
    // 0x800666E4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800666E4: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_2:
    // 0x800666E8: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800666EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800666F0: bne         $v0, $zero, L_80066708
    if (ctx->r2 != 0) {
        // 0x800666F4: nop

            goto L_80066708;
    }
    // 0x800666F4: nop

    // 0x800666F8: jal         0x80061348
    // 0x800666FC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800666FC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_3:
    // 0x80066700: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066704: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80066708:
    // 0x80066708: b           L_80066718
    // 0x8006670C: nop

        goto L_80066718;
    // 0x8006670C: nop

    // 0x80066710: b           L_80066718
    // 0x80066714: nop

        goto L_80066718;
    // 0x80066714: nop

L_80066718:
    // 0x80066718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006671C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066720: jr          $ra
    // 0x80066724: nop

    return;
    // 0x80066724: nop

;}
RECOMP_FUNC void func_80066728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006672C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066730: jal         0x80061348
    // 0x80066734: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066734: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x80066738: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006673C: b           L_8006674C
    // 0x80066740: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006674C;
    // 0x80066740: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066744: b           L_8006674C
    // 0x80066748: nop

        goto L_8006674C;
    // 0x80066748: nop

L_8006674C:
    // 0x8006674C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066754: jr          $ra
    // 0x80066758: nop

    return;
    // 0x80066758: nop

;}
RECOMP_FUNC void func_8006675C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006675C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066764: jal         0x80061348
    // 0x80066768: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066768: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x8006676C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066770: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066774: b           L_80066784
    // 0x80066778: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066784;
    // 0x80066778: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006677C: b           L_80066784
    // 0x80066780: nop

        goto L_80066784;
    // 0x80066780: nop

L_80066784:
    // 0x80066784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006678C: jr          $ra
    // 0x80066790: nop

    return;
    // 0x80066790: nop

;}
RECOMP_FUNC void func_80066794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006679C: jal         0x80061348
    // 0x800667A0: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800667A0: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x800667A4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800667A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800667AC: bne         $v0, $zero, L_800667C4
    if (ctx->r2 != 0) {
        // 0x800667B0: nop

            goto L_800667C4;
    }
    // 0x800667B0: nop

    // 0x800667B4: jal         0x80061348
    // 0x800667B8: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800667B8: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x800667BC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800667C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800667C4:
    // 0x800667C4: b           L_800667D4
    // 0x800667C8: nop

        goto L_800667D4;
    // 0x800667C8: nop

    // 0x800667CC: b           L_800667D4
    // 0x800667D0: nop

        goto L_800667D4;
    // 0x800667D0: nop

L_800667D4:
    // 0x800667D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800667D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800667DC: jr          $ra
    // 0x800667E0: nop

    return;
    // 0x800667E0: nop

;}
RECOMP_FUNC void func_800667E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800667E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800667E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800667EC: jal         0x80061348
    // 0x800667F0: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800667F0: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    after_0:
    // 0x800667F4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800667F8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800667FC: b           L_8006680C
    // 0x80066800: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006680C;
    // 0x80066800: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066804: b           L_8006680C
    // 0x80066808: nop

        goto L_8006680C;
    // 0x80066808: nop

L_8006680C:
    // 0x8006680C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066814: jr          $ra
    // 0x80066818: nop

    return;
    // 0x80066818: nop

;}
RECOMP_FUNC void func_8006681C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006681C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066824: jal         0x80061348
    // 0x80066828: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066828: addiu       $a0, $zero, 0x136
    ctx->r4 = ADD32(0, 0X136);
    after_0:
    // 0x8006682C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066830: b           L_80066840
    // 0x80066834: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066840;
    // 0x80066834: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066838: b           L_80066840
    // 0x8006683C: nop

        goto L_80066840;
    // 0x8006683C: nop

L_80066840:
    // 0x80066840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066848: jr          $ra
    // 0x8006684C: nop

    return;
    // 0x8006684C: nop

;}
RECOMP_FUNC void func_80066850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066858: jal         0x80061348
    // 0x8006685C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006685C: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_0:
    // 0x80066860: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066864: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066868: bne         $v0, $zero, L_80066880
    if (ctx->r2 != 0) {
        // 0x8006686C: nop

            goto L_80066880;
    }
    // 0x8006686C: nop

    // 0x80066870: jal         0x80061348
    // 0x80066874: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066874: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x80066878: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006687C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066880:
    // 0x80066880: b           L_80066890
    // 0x80066884: nop

        goto L_80066890;
    // 0x80066884: nop

    // 0x80066888: b           L_80066890
    // 0x8006688C: nop

        goto L_80066890;
    // 0x8006688C: nop

L_80066890:
    // 0x80066890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066898: jr          $ra
    // 0x8006689C: nop

    return;
    // 0x8006689C: nop

;}
RECOMP_FUNC void func_800668A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800668A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800668A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800668A8: jal         0x80061348
    // 0x800668AC: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800668AC: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_0:
    // 0x800668B0: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800668B4: b           L_800668C4
    // 0x800668B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800668C4;
    // 0x800668B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800668BC: b           L_800668C4
    // 0x800668C0: nop

        goto L_800668C4;
    // 0x800668C0: nop

L_800668C4:
    // 0x800668C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800668C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800668CC: jr          $ra
    // 0x800668D0: nop

    return;
    // 0x800668D0: nop

;}
RECOMP_FUNC void func_800668D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800668D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800668D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800668DC: jal         0x80061348
    // 0x800668E0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800668E0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x800668E4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800668E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800668EC: beq         $v0, $zero, L_80066904
    if (ctx->r2 == 0) {
        // 0x800668F0: nop

            goto L_80066904;
    }
    // 0x800668F0: nop

    // 0x800668F4: jal         0x80061348
    // 0x800668F8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800668F8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x800668FC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066900: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066904:
    // 0x80066904: b           L_80066914
    // 0x80066908: nop

        goto L_80066914;
    // 0x80066908: nop

    // 0x8006690C: b           L_80066914
    // 0x80066910: nop

        goto L_80066914;
    // 0x80066910: nop

L_80066914:
    // 0x80066914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006691C: jr          $ra
    // 0x80066920: nop

    return;
    // 0x80066920: nop

;}
RECOMP_FUNC void func_80066924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006692C: jal         0x80061348
    // 0x80066930: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066930: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80066934: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066938: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006693C: beq         $v0, $zero, L_80066954
    if (ctx->r2 == 0) {
        // 0x80066940: nop

            goto L_80066954;
    }
    // 0x80066940: nop

    // 0x80066944: jal         0x80061348
    // 0x80066948: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066948: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x8006694C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066950: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066954:
    // 0x80066954: b           L_80066964
    // 0x80066958: nop

        goto L_80066964;
    // 0x80066958: nop

    // 0x8006695C: b           L_80066964
    // 0x80066960: nop

        goto L_80066964;
    // 0x80066960: nop

L_80066964:
    // 0x80066964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006696C: jr          $ra
    // 0x80066970: nop

    return;
    // 0x80066970: nop

;}
RECOMP_FUNC void func_80066974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006697C: jal         0x80061348
    // 0x80066980: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066980: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    after_0:
    // 0x80066984: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066988: b           L_80066998
    // 0x8006698C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066998;
    // 0x8006698C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066990: b           L_80066998
    // 0x80066994: nop

        goto L_80066998;
    // 0x80066994: nop

L_80066998:
    // 0x80066998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006699C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800669A0: jr          $ra
    // 0x800669A4: nop

    return;
    // 0x800669A4: nop

;}
RECOMP_FUNC void func_800669A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800669A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800669AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800669B0: jal         0x80061348
    // 0x800669B4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800669B4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x800669B8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800669BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800669C0: beq         $v0, $zero, L_800669D8
    if (ctx->r2 == 0) {
        // 0x800669C4: nop

            goto L_800669D8;
    }
    // 0x800669C4: nop

    // 0x800669C8: jal         0x80061348
    // 0x800669CC: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800669CC: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_1:
    // 0x800669D0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800669D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800669D8:
    // 0x800669D8: b           L_800669E8
    // 0x800669DC: nop

        goto L_800669E8;
    // 0x800669DC: nop

    // 0x800669E0: b           L_800669E8
    // 0x800669E4: nop

        goto L_800669E8;
    // 0x800669E4: nop

L_800669E8:
    // 0x800669E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800669EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800669F0: jr          $ra
    // 0x800669F4: nop

    return;
    // 0x800669F4: nop

;}
RECOMP_FUNC void func_800669F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800669F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800669FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066A00: jal         0x80061348
    // 0x80066A04: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066A04: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80066A08: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066A0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066A10: beq         $v0, $zero, L_80066A28
    if (ctx->r2 == 0) {
        // 0x80066A14: nop

            goto L_80066A28;
    }
    // 0x80066A14: nop

    // 0x80066A18: jal         0x80061348
    // 0x80066A1C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80066A1C: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_1:
    // 0x80066A20: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066A24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80066A28:
    // 0x80066A28: b           L_80066A38
    // 0x80066A2C: nop

        goto L_80066A38;
    // 0x80066A2C: nop

    // 0x80066A30: b           L_80066A38
    // 0x80066A34: nop

        goto L_80066A38;
    // 0x80066A34: nop

L_80066A38:
    // 0x80066A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066A3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066A40: jr          $ra
    // 0x80066A44: nop

    return;
    // 0x80066A44: nop

;}
RECOMP_FUNC void func_80066A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066A50: jal         0x80061348
    // 0x80066A54: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066A54: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_0:
    // 0x80066A58: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066A5C: b           L_80066A6C
    // 0x80066A60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066A6C;
    // 0x80066A60: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066A64: b           L_80066A6C
    // 0x80066A68: nop

        goto L_80066A6C;
    // 0x80066A68: nop

L_80066A6C:
    // 0x80066A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066A74: jr          $ra
    // 0x80066A78: nop

    return;
    // 0x80066A78: nop

;}
RECOMP_FUNC void func_80066A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066A84: jal         0x80061348
    // 0x80066A88: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066A88: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_0:
    // 0x80066A8C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066A90: b           L_80066AA0
    // 0x80066A94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066AA0;
    // 0x80066A94: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066A98: b           L_80066AA0
    // 0x80066A9C: nop

        goto L_80066AA0;
    // 0x80066A9C: nop

L_80066AA0:
    // 0x80066AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066AA8: jr          $ra
    // 0x80066AAC: nop

    return;
    // 0x80066AAC: nop

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
RECOMP_FUNC void func_80066AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066AEC: jal         0x80061348
    // 0x80066AF0: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066AF0: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_0:
    // 0x80066AF4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066AF8: b           L_80066B08
    // 0x80066AFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066B08;
    // 0x80066AFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066B00: b           L_80066B08
    // 0x80066B04: nop

        goto L_80066B08;
    // 0x80066B04: nop

L_80066B08:
    // 0x80066B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066B10: jr          $ra
    // 0x80066B14: nop

    return;
    // 0x80066B14: nop

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
RECOMP_FUNC void func_80066B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066B54: jal         0x80061348
    // 0x80066B58: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066B58: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_0:
    // 0x80066B5C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066B60: b           L_80066B70
    // 0x80066B64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066B70;
    // 0x80066B64: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066B68: b           L_80066B70
    // 0x80066B6C: nop

        goto L_80066B70;
    // 0x80066B6C: nop

L_80066B70:
    // 0x80066B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066B78: jr          $ra
    // 0x80066B7C: nop

    return;
    // 0x80066B7C: nop

;}
RECOMP_FUNC void func_80066B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066B84: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80066B88: nop

    // 0x80066B8C: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80066B90: nop

    // 0x80066B94: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80066B98: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80066B9C: jr          $ra
    // 0x80066BA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80066BA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066BA4: jr          $ra
    // 0x80066BA8: nop

    return;
    // 0x80066BA8: nop

    // 0x80066BAC: jr          $ra
    // 0x80066BB0: nop

    return;
    // 0x80066BB0: nop

;}
RECOMP_FUNC void func_80066BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066BB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066BB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80066BBC: nop

    // 0x80066BC0: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80066BC4: nop

    // 0x80066BC8: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80066BCC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80066BD0: jr          $ra
    // 0x80066BD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80066BD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066BD8: jr          $ra
    // 0x80066BDC: nop

    return;
    // 0x80066BDC: nop

    // 0x80066BE0: jr          $ra
    // 0x80066BE4: nop

    return;
    // 0x80066BE4: nop

;}
RECOMP_FUNC void func_80066BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066BF0: jal         0x80061348
    // 0x80066BF4: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066BF4: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    after_0:
    // 0x80066BF8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066BFC: b           L_80066C0C
    // 0x80066C00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066C0C;
    // 0x80066C00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066C04: b           L_80066C0C
    // 0x80066C08: nop

        goto L_80066C0C;
    // 0x80066C08: nop

L_80066C0C:
    // 0x80066C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066C14: jr          $ra
    // 0x80066C18: nop

    return;
    // 0x80066C18: nop

;}
RECOMP_FUNC void func_80066C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066C24: jal         0x80061348
    // 0x80066C28: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066C28: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    after_0:
    // 0x80066C2C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066C30: b           L_80066C40
    // 0x80066C34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066C40;
    // 0x80066C34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066C38: b           L_80066C40
    // 0x80066C3C: nop

        goto L_80066C40;
    // 0x80066C3C: nop

L_80066C40:
    // 0x80066C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066C48: jr          $ra
    // 0x80066C4C: nop

    return;
    // 0x80066C4C: nop

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
RECOMP_FUNC void func_80066C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066C8C: jal         0x80061348
    // 0x80066C90: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066C90: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    after_0:
    // 0x80066C94: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066C98: b           L_80066CA8
    // 0x80066C9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066CA8;
    // 0x80066C9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066CA0: b           L_80066CA8
    // 0x80066CA4: nop

        goto L_80066CA8;
    // 0x80066CA4: nop

L_80066CA8:
    // 0x80066CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066CB0: jr          $ra
    // 0x80066CB4: nop

    return;
    // 0x80066CB4: nop

;}
RECOMP_FUNC void func_80066CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066CC0: jal         0x80061348
    // 0x80066CC4: addiu       $a0, $zero, 0x14F
    ctx->r4 = ADD32(0, 0X14F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066CC4: addiu       $a0, $zero, 0x14F
    ctx->r4 = ADD32(0, 0X14F);
    after_0:
    // 0x80066CC8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066CCC: b           L_80066CDC
    // 0x80066CD0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066CDC;
    // 0x80066CD0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066CD4: b           L_80066CDC
    // 0x80066CD8: nop

        goto L_80066CDC;
    // 0x80066CD8: nop

L_80066CDC:
    // 0x80066CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066CE4: jr          $ra
    // 0x80066CE8: nop

    return;
    // 0x80066CE8: nop

;}
RECOMP_FUNC void func_80066CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066CF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066CF4: jal         0x80061348
    // 0x80066CF8: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066CF8: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    after_0:
    // 0x80066CFC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066D00: b           L_80066D10
    // 0x80066D04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066D10;
    // 0x80066D04: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066D08: b           L_80066D10
    // 0x80066D0C: nop

        goto L_80066D10;
    // 0x80066D0C: nop

L_80066D10:
    // 0x80066D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066D14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066D18: jr          $ra
    // 0x80066D1C: nop

    return;
    // 0x80066D1C: nop

;}
RECOMP_FUNC void func_80066D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066D28: jal         0x80061348
    // 0x80066D2C: addiu       $a0, $zero, 0x153
    ctx->r4 = ADD32(0, 0X153);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066D2C: addiu       $a0, $zero, 0x153
    ctx->r4 = ADD32(0, 0X153);
    after_0:
    // 0x80066D30: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066D34: b           L_80066D44
    // 0x80066D38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066D44;
    // 0x80066D38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066D3C: b           L_80066D44
    // 0x80066D40: nop

        goto L_80066D44;
    // 0x80066D40: nop

L_80066D44:
    // 0x80066D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066D4C: jr          $ra
    // 0x80066D50: nop

    return;
    // 0x80066D50: nop

;}
RECOMP_FUNC void func_80066D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066D5C: jal         0x80061348
    // 0x80066D60: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066D60: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    after_0:
    // 0x80066D64: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066D68: b           L_80066D78
    // 0x80066D6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066D78;
    // 0x80066D6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066D70: b           L_80066D78
    // 0x80066D74: nop

        goto L_80066D78;
    // 0x80066D74: nop

L_80066D78:
    // 0x80066D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066D80: jr          $ra
    // 0x80066D84: nop

    return;
    // 0x80066D84: nop

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
RECOMP_FUNC void func_80066DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066DF8: jal         0x80061348
    // 0x80066DFC: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066DFC: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_0:
    // 0x80066E00: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066E04: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066E08: b           L_80066E18
    // 0x80066E0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066E18;
    // 0x80066E0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066E10: b           L_80066E18
    // 0x80066E14: nop

        goto L_80066E18;
    // 0x80066E14: nop

L_80066E18:
    // 0x80066E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066E20: jr          $ra
    // 0x80066E24: nop

    return;
    // 0x80066E24: nop

;}
RECOMP_FUNC void func_80066E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066E30: jal         0x80061348
    // 0x80066E34: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066E34: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_0:
    // 0x80066E38: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066E3C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066E40: b           L_80066E50
    // 0x80066E44: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066E50;
    // 0x80066E44: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066E48: b           L_80066E50
    // 0x80066E4C: nop

        goto L_80066E50;
    // 0x80066E4C: nop

L_80066E50:
    // 0x80066E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066E58: jr          $ra
    // 0x80066E5C: nop

    return;
    // 0x80066E5C: nop

;}
RECOMP_FUNC void func_80066E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066E68: jal         0x80061348
    // 0x80066E6C: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066E6C: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    after_0:
    // 0x80066E70: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80066E74: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80066E78: b           L_80066E88
    // 0x80066E7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066E88;
    // 0x80066E7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066E80: b           L_80066E88
    // 0x80066E84: nop

        goto L_80066E88;
    // 0x80066E84: nop

L_80066E88:
    // 0x80066E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066E90: jr          $ra
    // 0x80066E94: nop

    return;
    // 0x80066E94: nop

;}
