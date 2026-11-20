#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_80062FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062FE8: jal         0x8005F064
    // 0x80062FEC: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80062FEC: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_0:
    // 0x80062FF0: b           L_80063000
    // 0x80062FF4: nop

        goto L_80063000;
    // 0x80062FF4: nop

    // 0x80062FF8: b           L_80063000
    // 0x80062FFC: nop

        goto L_80063000;
    // 0x80062FFC: nop

L_80063000:
    // 0x80063000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063008: jr          $ra
    // 0x8006300C: nop

    return;
    // 0x8006300C: nop

;}
RECOMP_FUNC void func_80063010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063018: jal         0x8005F064
    // 0x8006301C: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006301C: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_0:
    // 0x80063020: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063024: b           L_80063034
    // 0x80063028: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063034;
    // 0x80063028: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006302C: b           L_80063034
    // 0x80063030: nop

        goto L_80063034;
    // 0x80063030: nop

L_80063034:
    // 0x80063034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006303C: jr          $ra
    // 0x80063040: nop

    return;
    // 0x80063040: nop

;}
RECOMP_FUNC void func_80063044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006304C: jal         0x8005F064
    // 0x80063050: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063050: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_0:
    // 0x80063054: b           L_80063064
    // 0x80063058: nop

        goto L_80063064;
    // 0x80063058: nop

    // 0x8006305C: b           L_80063064
    // 0x80063060: nop

        goto L_80063064;
    // 0x80063060: nop

L_80063064:
    // 0x80063064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006306C: jr          $ra
    // 0x80063070: nop

    return;
    // 0x80063070: nop

;}
RECOMP_FUNC void func_80063074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006307C: jal         0x80061488
    // 0x80063080: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063080: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_0:
    // 0x80063084: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80063088: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006308C: b           L_8006309C
    // 0x80063090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006309C;
    // 0x80063090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063094: b           L_8006309C
    // 0x80063098: nop

        goto L_8006309C;
    // 0x80063098: nop

L_8006309C:
    // 0x8006309C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800630A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800630A4: jr          $ra
    // 0x800630A8: nop

    return;
    // 0x800630A8: nop

;}
RECOMP_FUNC void func_800630AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800630AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800630B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800630B4: jal         0x8005F064
    // 0x800630B8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800630B8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_0:
    // 0x800630BC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800630C0: b           L_800630D0
    // 0x800630C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800630D0;
    // 0x800630C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800630C8: b           L_800630D0
    // 0x800630CC: nop

        goto L_800630D0;
    // 0x800630CC: nop

L_800630D0:
    // 0x800630D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800630D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800630D8: jr          $ra
    // 0x800630DC: nop

    return;
    // 0x800630DC: nop

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
RECOMP_FUNC void func_80063118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006311C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063120: jal         0x80061488
    // 0x80063124: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063124: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_0:
    // 0x80063128: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006312C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80063130: b           L_80063140
    // 0x80063134: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063140;
    // 0x80063134: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063138: b           L_80063140
    // 0x8006313C: nop

        goto L_80063140;
    // 0x8006313C: nop

L_80063140:
    // 0x80063140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063148: jr          $ra
    // 0x8006314C: nop

    return;
    // 0x8006314C: nop

;}
RECOMP_FUNC void func_80063150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063158: jal         0x80061488
    // 0x8006315C: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006315C: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_0:
    // 0x80063160: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063164: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063168: b           L_80063178
    // 0x8006316C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063178;
    // 0x8006316C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063170: b           L_80063178
    // 0x80063174: nop

        goto L_80063178;
    // 0x80063174: nop

L_80063178:
    // 0x80063178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006317C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063180: jr          $ra
    // 0x80063184: nop

    return;
    // 0x80063184: nop

;}
RECOMP_FUNC void func_80063188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006318C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063190: jal         0x80061488
    // 0x80063194: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063194: addiu       $a0, $zero, 0x621
    ctx->r4 = ADD32(0, 0X621);
    after_0:
    // 0x80063198: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006319C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800631A0: b           L_800631B0
    // 0x800631A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800631B0;
    // 0x800631A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800631A8: b           L_800631B0
    // 0x800631AC: nop

        goto L_800631B0;
    // 0x800631AC: nop

L_800631B0:
    // 0x800631B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800631B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800631B8: jr          $ra
    // 0x800631BC: nop

    return;
    // 0x800631BC: nop

;}
RECOMP_FUNC void func_800631C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800631C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800631C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800631C8: jal         0x80061488
    // 0x800631CC: addiu       $a0, $zero, 0x61A
    ctx->r4 = ADD32(0, 0X61A);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800631CC: addiu       $a0, $zero, 0x61A
    ctx->r4 = ADD32(0, 0X61A);
    after_0:
    // 0x800631D0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800631D4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800631D8: b           L_800631E8
    // 0x800631DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800631E8;
    // 0x800631DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800631E0: b           L_800631E8
    // 0x800631E4: nop

        goto L_800631E8;
    // 0x800631E4: nop

L_800631E8:
    // 0x800631E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800631EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800631F0: jr          $ra
    // 0x800631F4: nop

    return;
    // 0x800631F4: nop

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
RECOMP_FUNC void func_8006322C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006322C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063234: jal         0x80061488
    // 0x80063238: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063238: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    after_0:
    // 0x8006323C: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063240: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063244: b           L_80063254
    // 0x80063248: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063254;
    // 0x80063248: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006324C: b           L_80063254
    // 0x80063250: nop

        goto L_80063254;
    // 0x80063250: nop

L_80063254:
    // 0x80063254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006325C: jr          $ra
    // 0x80063260: nop

    return;
    // 0x80063260: nop

;}
RECOMP_FUNC void func_80063264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006326C: jal         0x80061488
    // 0x80063270: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063270: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    after_0:
    // 0x80063274: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063278: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006327C: b           L_8006328C
    // 0x80063280: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006328C;
    // 0x80063280: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063284: b           L_8006328C
    // 0x80063288: nop

        goto L_8006328C;
    // 0x80063288: nop

L_8006328C:
    // 0x8006328C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063294: jr          $ra
    // 0x80063298: nop

    return;
    // 0x80063298: nop

;}
RECOMP_FUNC void func_8006329C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006329C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800632A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800632A4: jal         0x80061488
    // 0x800632A8: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800632A8: addiu       $a0, $zero, 0x61C
    ctx->r4 = ADD32(0, 0X61C);
    after_0:
    // 0x800632AC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800632B0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800632B4: b           L_800632C4
    // 0x800632B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800632C4;
    // 0x800632B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800632BC: b           L_800632C4
    // 0x800632C0: nop

        goto L_800632C4;
    // 0x800632C0: nop

L_800632C4:
    // 0x800632C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800632C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800632CC: jr          $ra
    // 0x800632D0: nop

    return;
    // 0x800632D0: nop

;}
RECOMP_FUNC void func_800632D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800632D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800632D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800632DC: jal         0x8005F064
    // 0x800632E0: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800632E0: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_0:
    // 0x800632E4: b           L_800632F4
    // 0x800632E8: nop

        goto L_800632F4;
    // 0x800632E8: nop

    // 0x800632EC: b           L_800632F4
    // 0x800632F0: nop

        goto L_800632F4;
    // 0x800632F0: nop

L_800632F4:
    // 0x800632F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800632F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800632FC: jr          $ra
    // 0x80063300: nop

    return;
    // 0x80063300: nop

;}
RECOMP_FUNC void func_80063304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006330C: jal         0x8005F064
    // 0x80063310: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063310: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_0:
    // 0x80063314: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063318: b           L_80063328
    // 0x8006331C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063328;
    // 0x8006331C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063320: b           L_80063328
    // 0x80063324: nop

        goto L_80063328;
    // 0x80063324: nop

L_80063328:
    // 0x80063328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006332C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063330: jr          $ra
    // 0x80063334: nop

    return;
    // 0x80063334: nop

;}
RECOMP_FUNC void func_80063338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006333C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063340: jal         0x80061488
    // 0x80063344: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063344: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    after_0:
    // 0x80063348: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006334C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063350: b           L_80063360
    // 0x80063354: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063360;
    // 0x80063354: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063358: b           L_80063360
    // 0x8006335C: nop

        goto L_80063360;
    // 0x8006335C: nop

L_80063360:
    // 0x80063360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063368: jr          $ra
    // 0x8006336C: nop

    return;
    // 0x8006336C: nop

;}
RECOMP_FUNC void func_80063370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063378: jal         0x80061488
    // 0x8006337C: addiu       $a0, $zero, 0x612
    ctx->r4 = ADD32(0, 0X612);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006337C: addiu       $a0, $zero, 0x612
    ctx->r4 = ADD32(0, 0X612);
    after_0:
    // 0x80063380: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80063384: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063388: b           L_80063398
    // 0x8006338C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063398;
    // 0x8006338C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063390: b           L_80063398
    // 0x80063394: nop

        goto L_80063398;
    // 0x80063394: nop

L_80063398:
    // 0x80063398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006339C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800633A0: jr          $ra
    // 0x800633A4: nop

    return;
    // 0x800633A4: nop

;}
RECOMP_FUNC void func_800633A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800633A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800633AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800633B0: jal         0x8005F064
    // 0x800633B4: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800633B4: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_0:
    // 0x800633B8: b           L_800633C8
    // 0x800633BC: nop

        goto L_800633C8;
    // 0x800633BC: nop

    // 0x800633C0: b           L_800633C8
    // 0x800633C4: nop

        goto L_800633C8;
    // 0x800633C4: nop

L_800633C8:
    // 0x800633C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800633CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800633D0: jr          $ra
    // 0x800633D4: nop

    return;
    // 0x800633D4: nop

;}
RECOMP_FUNC void func_800633D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800633D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800633DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800633E0: jal         0x8005F064
    // 0x800633E4: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800633E4: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_0:
    // 0x800633E8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800633EC: b           L_800633FC
    // 0x800633F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800633FC;
    // 0x800633F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800633F4: b           L_800633FC
    // 0x800633F8: nop

        goto L_800633FC;
    // 0x800633F8: nop

L_800633FC:
    // 0x800633FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063404: jr          $ra
    // 0x80063408: nop

    return;
    // 0x80063408: nop

;}
RECOMP_FUNC void func_8006340C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006340C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063414: jal         0x8005F064
    // 0x80063418: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063418: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_0:
    // 0x8006341C: b           L_8006342C
    // 0x80063420: nop

        goto L_8006342C;
    // 0x80063420: nop

    // 0x80063424: b           L_8006342C
    // 0x80063428: nop

        goto L_8006342C;
    // 0x80063428: nop

L_8006342C:
    // 0x8006342C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063434: jr          $ra
    // 0x80063438: nop

    return;
    // 0x80063438: nop

;}
RECOMP_FUNC void func_8006343C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006343C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063444: jal         0x8005F064
    // 0x80063448: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063448: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_0:
    // 0x8006344C: b           L_8006345C
    // 0x80063450: nop

        goto L_8006345C;
    // 0x80063450: nop

    // 0x80063454: b           L_8006345C
    // 0x80063458: nop

        goto L_8006345C;
    // 0x80063458: nop

L_8006345C:
    // 0x8006345C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063464: jr          $ra
    // 0x80063468: nop

    return;
    // 0x80063468: nop

;}
RECOMP_FUNC void func_8006346C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006346C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063474: jal         0x80061348
    // 0x80063478: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80063478: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_0:
    // 0x8006347C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063480: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063484: bne         $v0, $zero, L_800634C4
    if (ctx->r2 != 0) {
        // 0x80063488: nop

            goto L_800634C4;
    }
    // 0x80063488: nop

    // 0x8006348C: jal         0x80061348
    // 0x80063490: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80063490: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_1:
    // 0x80063494: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063498: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006349C: bne         $v0, $zero, L_800634C4
    if (ctx->r2 != 0) {
        // 0x800634A0: nop

            goto L_800634C4;
    }
    // 0x800634A0: nop

    // 0x800634A4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800634A8: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x800634AC: nop

    // 0x800634B0: lh          $v0, 0x20($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X20);
    // 0x800634B4: nop

    // 0x800634B8: slti        $t9, $v0, 0x12C
    ctx->r25 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800634BC: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x800634C0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800634C4:
    // 0x800634C4: b           L_800634D4
    // 0x800634C8: nop

        goto L_800634D4;
    // 0x800634C8: nop

    // 0x800634CC: b           L_800634D4
    // 0x800634D0: nop

        goto L_800634D4;
    // 0x800634D0: nop

L_800634D4:
    // 0x800634D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800634D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800634DC: jr          $ra
    // 0x800634E0: nop

    return;
    // 0x800634E0: nop

;}
RECOMP_FUNC void func_800634E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800634E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800634E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800634EC: jal         0x80061488
    // 0x800634F0: addiu       $a0, $zero, 0x5E7
    ctx->r4 = ADD32(0, 0X5E7);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800634F0: addiu       $a0, $zero, 0x5E7
    ctx->r4 = ADD32(0, 0X5E7);
    after_0:
    // 0x800634F4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800634F8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800634FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063500: beq         $v0, $zero, L_80063564
    if (ctx->r2 == 0) {
        // 0x80063504: nop

            goto L_80063564;
    }
    // 0x80063504: nop

    // 0x80063508: jal         0x80061348
    // 0x8006350C: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006350C: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_1:
    // 0x80063510: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063514: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063518: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006351C: beq         $v0, $zero, L_80063564
    if (ctx->r2 == 0) {
        // 0x80063520: nop

            goto L_80063564;
    }
    // 0x80063520: nop

    // 0x80063524: jal         0x80061348
    // 0x80063528: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80063528: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_2:
    // 0x8006352C: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063530: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80063534: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063538: beq         $v0, $zero, L_80063564
    if (ctx->r2 == 0) {
        // 0x8006353C: nop

            goto L_80063564;
    }
    // 0x8006353C: nop

    // 0x80063540: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80063544: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x80063548: nop

    // 0x8006354C: lh          $v0, 0x20($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X20);
    // 0x80063550: nop

    // 0x80063554: slti        $t0, $v0, 0x12C
    ctx->r8 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80063558: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x8006355C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80063560: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80063564:
    // 0x80063564: b           L_80063574
    // 0x80063568: nop

        goto L_80063574;
    // 0x80063568: nop

    // 0x8006356C: b           L_80063574
    // 0x80063570: nop

        goto L_80063574;
    // 0x80063570: nop

L_80063574:
    // 0x80063574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006357C: jr          $ra
    // 0x80063580: nop

    return;
    // 0x80063580: nop

;}
RECOMP_FUNC void func_80063584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063584: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063588: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006358C: nop

    // 0x80063590: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x80063594: nop

    // 0x80063598: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006359C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800635A0: jr          $ra
    // 0x800635A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800635A4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800635A8: jr          $ra
    // 0x800635AC: nop

    return;
    // 0x800635AC: nop

    // 0x800635B0: jr          $ra
    // 0x800635B4: nop

    return;
    // 0x800635B4: nop

;}
RECOMP_FUNC void func_800635B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800635B8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800635BC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800635C0: nop

    // 0x800635C4: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x800635C8: nop

    // 0x800635CC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800635D0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800635D4: jr          $ra
    // 0x800635D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800635D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800635DC: jr          $ra
    // 0x800635E0: nop

    return;
    // 0x800635E0: nop

    // 0x800635E4: jr          $ra
    // 0x800635E8: nop

    return;
    // 0x800635E8: nop

;}
RECOMP_FUNC void func_800635EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800635EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800635F0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800635F4: nop

    // 0x800635F8: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x800635FC: nop

    // 0x80063600: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063604: jr          $ra
    // 0x80063608: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063608: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006360C: jr          $ra
    // 0x80063610: nop

    return;
    // 0x80063610: nop

    // 0x80063614: jr          $ra
    // 0x80063618: nop

    return;
    // 0x80063618: nop

;}
RECOMP_FUNC void func_8006361C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006361C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063620: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063624: nop

    // 0x80063628: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006362C: nop

    // 0x80063630: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80063634: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063638: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006363C: beq         $v0, $zero, L_80063658
    if (ctx->r2 == 0) {
        // 0x80063640: nop

            goto L_80063658;
    }
    // 0x80063640: nop

    // 0x80063644: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x80063648: nop

    // 0x8006364C: slti        $t8, $v0, 0x384
    ctx->r24 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80063650: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80063654: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80063658:
    // 0x80063658: jr          $ra
    // 0x8006365C: nop

    return;
    // 0x8006365C: nop

    // 0x80063660: jr          $ra
    // 0x80063664: nop

    return;
    // 0x80063664: nop

    // 0x80063668: jr          $ra
    // 0x8006366C: nop

    return;
    // 0x8006366C: nop

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
RECOMP_FUNC void func_800636A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800636A0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800636A4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800636A8: nop

    // 0x800636AC: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x800636B0: nop

    // 0x800636B4: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800636B8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800636BC: jr          $ra
    // 0x800636C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800636C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800636C4: jr          $ra
    // 0x800636C8: nop

    return;
    // 0x800636C8: nop

    // 0x800636CC: jr          $ra
    // 0x800636D0: nop

    return;
    // 0x800636D0: nop

;}
RECOMP_FUNC void func_800636D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800636D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800636D8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800636DC: nop

    // 0x800636E0: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x800636E4: nop

    // 0x800636E8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800636EC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800636F0: jr          $ra
    // 0x800636F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800636F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800636F8: jr          $ra
    // 0x800636FC: nop

    return;
    // 0x800636FC: nop

    // 0x80063700: jr          $ra
    // 0x80063704: nop

    return;
    // 0x80063704: nop

;}
RECOMP_FUNC void func_80063708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063708: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006370C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063710: nop

    // 0x80063714: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80063718: nop

    // 0x8006371C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80063720: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063724: jr          $ra
    // 0x80063728: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063728: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006372C: jr          $ra
    // 0x80063730: nop

    return;
    // 0x80063730: nop

    // 0x80063734: jr          $ra
    // 0x80063738: nop

    return;
    // 0x80063738: nop

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
RECOMP_FUNC void func_80063770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063778: jal         0x8005F064
    // 0x8006377C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006377C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063780: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063784: b           L_80063794
    // 0x80063788: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063794;
    // 0x80063788: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006378C: b           L_80063794
    // 0x80063790: nop

        goto L_80063794;
    // 0x80063790: nop

L_80063794:
    // 0x80063794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006379C: jr          $ra
    // 0x800637A0: nop

    return;
    // 0x800637A0: nop

;}
RECOMP_FUNC void func_800637A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800637A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800637A8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800637AC: nop

    // 0x800637B0: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800637B4: nop

    // 0x800637B8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800637BC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800637C0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800637C4: beq         $v0, $zero, L_800637E0
    if (ctx->r2 == 0) {
        // 0x800637C8: nop

            goto L_800637E0;
    }
    // 0x800637C8: nop

    // 0x800637CC: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x800637D0: nop

    // 0x800637D4: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800637D8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800637DC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800637E0:
    // 0x800637E0: jr          $ra
    // 0x800637E4: nop

    return;
    // 0x800637E4: nop

    // 0x800637E8: jr          $ra
    // 0x800637EC: nop

    return;
    // 0x800637EC: nop

    // 0x800637F0: jr          $ra
    // 0x800637F4: nop

    return;
    // 0x800637F4: nop

;}
RECOMP_FUNC void func_800637F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800637F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800637FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063800: jal         0x80061488
    // 0x80063804: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80063804: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    after_0:
    // 0x80063808: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006380C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80063810: b           L_80063820
    // 0x80063814: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063820;
    // 0x80063814: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063818: b           L_80063820
    // 0x8006381C: nop

        goto L_80063820;
    // 0x8006381C: nop

L_80063820:
    // 0x80063820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063828: jr          $ra
    // 0x8006382C: nop

    return;
    // 0x8006382C: nop

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
RECOMP_FUNC void func_80063868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006386C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063870: jal         0x8005F064
    // 0x80063874: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063874: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063878: b           L_80063888
    // 0x8006387C: nop

        goto L_80063888;
    // 0x8006387C: nop

    // 0x80063880: b           L_80063888
    // 0x80063884: nop

        goto L_80063888;
    // 0x80063884: nop

L_80063888:
    // 0x80063888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006388C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063890: jr          $ra
    // 0x80063894: nop

    return;
    // 0x80063894: nop

;}
RECOMP_FUNC void func_80063898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063898: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006389C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800638A0: nop

    // 0x800638A4: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800638A8: nop

    // 0x800638AC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800638B0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800638B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800638B8: beq         $v0, $zero, L_800638D4
    if (ctx->r2 == 0) {
        // 0x800638BC: nop

            goto L_800638D4;
    }
    // 0x800638BC: nop

    // 0x800638C0: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x800638C4: nop

    // 0x800638C8: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800638CC: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x800638D0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800638D4:
    // 0x800638D4: jr          $ra
    // 0x800638D8: nop

    return;
    // 0x800638D8: nop

    // 0x800638DC: jr          $ra
    // 0x800638E0: nop

    return;
    // 0x800638E0: nop

    // 0x800638E4: jr          $ra
    // 0x800638E8: nop

    return;
    // 0x800638E8: nop

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
RECOMP_FUNC void func_80063920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063920: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063924: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063928: nop

    // 0x8006392C: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80063930: nop

    // 0x80063934: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80063938: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006393C: jr          $ra
    // 0x80063940: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063940: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063944: jr          $ra
    // 0x80063948: nop

    return;
    // 0x80063948: nop

    // 0x8006394C: jr          $ra
    // 0x80063950: nop

    return;
    // 0x80063950: nop

;}
RECOMP_FUNC void func_80063954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063954: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063958: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006395C: nop

    // 0x80063960: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80063964: nop

    // 0x80063968: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006396C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063970: jr          $ra
    // 0x80063974: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063974: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063978: jr          $ra
    // 0x8006397C: nop

    return;
    // 0x8006397C: nop

    // 0x80063980: jr          $ra
    // 0x80063984: nop

    return;
    // 0x80063984: nop

;}
RECOMP_FUNC void func_80063988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063988: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006398C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80063990: nop

    // 0x80063994: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x80063998: nop

    // 0x8006399C: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800639A0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800639A4: jr          $ra
    // 0x800639A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800639A8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800639AC: jr          $ra
    // 0x800639B0: nop

    return;
    // 0x800639B0: nop

    // 0x800639B4: jr          $ra
    // 0x800639B8: nop

    return;
    // 0x800639B8: nop

;}
RECOMP_FUNC void func_800639BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800639BC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800639C0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800639C4: nop

    // 0x800639C8: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x800639CC: nop

    // 0x800639D0: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x800639D4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800639D8: jr          $ra
    // 0x800639DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800639DC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800639E0: jr          $ra
    // 0x800639E4: nop

    return;
    // 0x800639E4: nop

    // 0x800639E8: jr          $ra
    // 0x800639EC: nop

    return;
    // 0x800639EC: nop

;}
RECOMP_FUNC void func_800639F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800639F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800639F4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800639F8: nop

    // 0x800639FC: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x80063A00: nop

    // 0x80063A04: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80063A08: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80063A0C: jr          $ra
    // 0x80063A10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80063A10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80063A14: jr          $ra
    // 0x80063A18: nop

    return;
    // 0x80063A18: nop

    // 0x80063A1C: jr          $ra
    // 0x80063A20: nop

    return;
    // 0x80063A20: nop

;}
RECOMP_FUNC void func_80063A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063A2C: jal         0x8005F064
    // 0x80063A30: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063A30: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063A34: b           L_80063A44
    // 0x80063A38: nop

        goto L_80063A44;
    // 0x80063A38: nop

    // 0x80063A3C: b           L_80063A44
    // 0x80063A40: nop

        goto L_80063A44;
    // 0x80063A40: nop

L_80063A44:
    // 0x80063A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063A48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063A4C: jr          $ra
    // 0x80063A50: nop

    return;
    // 0x80063A50: nop

;}
RECOMP_FUNC void func_80063A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063A5C: jal         0x8005F064
    // 0x80063A60: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063A60: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063A64: b           L_80063A74
    // 0x80063A68: nop

        goto L_80063A74;
    // 0x80063A68: nop

    // 0x80063A6C: b           L_80063A74
    // 0x80063A70: nop

        goto L_80063A74;
    // 0x80063A70: nop

L_80063A74:
    // 0x80063A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063A78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063A7C: jr          $ra
    // 0x80063A80: nop

    return;
    // 0x80063A80: nop

;}
RECOMP_FUNC void func_80063A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063A88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063A8C: jal         0x8005F064
    // 0x80063A90: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063A90: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063A94: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80063A98: b           L_80063AA8
    // 0x80063A9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80063AA8;
    // 0x80063A9C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80063AA0: b           L_80063AA8
    // 0x80063AA4: nop

        goto L_80063AA8;
    // 0x80063AA4: nop

L_80063AA8:
    // 0x80063AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063AB0: jr          $ra
    // 0x80063AB4: nop

    return;
    // 0x80063AB4: nop

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
RECOMP_FUNC void func_80063AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063AF0: jal         0x8005F064
    // 0x80063AF4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80063AF4: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_0:
    // 0x80063AF8: b           L_80063B08
    // 0x80063AFC: nop

        goto L_80063B08;
    // 0x80063AFC: nop

    // 0x80063B00: b           L_80063B08
    // 0x80063B04: nop

        goto L_80063B08;
    // 0x80063B04: nop

L_80063B08:
    // 0x80063B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80063B10: jr          $ra
    // 0x80063B14: nop

    return;
    // 0x80063B14: nop

;}
