#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8006C5D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C5D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C5D8: jal         0x8005F064
    // 0x8006C5DC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C5DC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x8006C5E0: b           L_8006C5F0
    // 0x8006C5E4: nop

        goto L_8006C5F0;
    // 0x8006C5E4: nop

    // 0x8006C5E8: b           L_8006C5F0
    // 0x8006C5EC: nop

        goto L_8006C5F0;
    // 0x8006C5EC: nop

L_8006C5F0:
    // 0x8006C5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C5F8: jr          $ra
    // 0x8006C5FC: nop

    return;
    // 0x8006C5FC: nop

;}
RECOMP_FUNC void func_8006C600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C608: jal         0x8005F064
    // 0x8006C60C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C60C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_0:
    // 0x8006C610: b           L_8006C620
    // 0x8006C614: nop

        goto L_8006C620;
    // 0x8006C614: nop

    // 0x8006C618: b           L_8006C620
    // 0x8006C61C: nop

        goto L_8006C620;
    // 0x8006C61C: nop

L_8006C620:
    // 0x8006C620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C628: jr          $ra
    // 0x8006C62C: nop

    return;
    // 0x8006C62C: nop

;}
RECOMP_FUNC void func_8006C630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C638: jal         0x8005F064
    // 0x8006C63C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C63C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_0:
    // 0x8006C640: b           L_8006C650
    // 0x8006C644: nop

        goto L_8006C650;
    // 0x8006C644: nop

    // 0x8006C648: b           L_8006C650
    // 0x8006C64C: nop

        goto L_8006C650;
    // 0x8006C64C: nop

L_8006C650:
    // 0x8006C650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C658: jr          $ra
    // 0x8006C65C: nop

    return;
    // 0x8006C65C: nop

;}
RECOMP_FUNC void func_8006C660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C668: jal         0x8005F064
    // 0x8006C66C: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C66C: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_0:
    // 0x8006C670: b           L_8006C680
    // 0x8006C674: nop

        goto L_8006C680;
    // 0x8006C674: nop

    // 0x8006C678: b           L_8006C680
    // 0x8006C67C: nop

        goto L_8006C680;
    // 0x8006C67C: nop

L_8006C680:
    // 0x8006C680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C688: jr          $ra
    // 0x8006C68C: nop

    return;
    // 0x8006C68C: nop

;}
RECOMP_FUNC void func_8006C690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C698: jal         0x8005F064
    // 0x8006C69C: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C69C: addiu       $a0, $zero, 0xAF
    ctx->r4 = ADD32(0, 0XAF);
    after_0:
    // 0x8006C6A0: b           L_8006C6B0
    // 0x8006C6A4: nop

        goto L_8006C6B0;
    // 0x8006C6A4: nop

    // 0x8006C6A8: b           L_8006C6B0
    // 0x8006C6AC: nop

        goto L_8006C6B0;
    // 0x8006C6AC: nop

L_8006C6B0:
    // 0x8006C6B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C6B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C6B8: jr          $ra
    // 0x8006C6BC: nop

    return;
    // 0x8006C6BC: nop

;}
RECOMP_FUNC void func_8006C6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C6C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C6C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C6C8: jal         0x8005F064
    // 0x8006C6CC: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C6CC: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_0:
    // 0x8006C6D0: b           L_8006C6E0
    // 0x8006C6D4: nop

        goto L_8006C6E0;
    // 0x8006C6D4: nop

    // 0x8006C6D8: b           L_8006C6E0
    // 0x8006C6DC: nop

        goto L_8006C6E0;
    // 0x8006C6DC: nop

L_8006C6E0:
    // 0x8006C6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C6E8: jr          $ra
    // 0x8006C6EC: nop

    return;
    // 0x8006C6EC: nop

;}
RECOMP_FUNC void func_8006C6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C6F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C6F8: jal         0x8005F064
    // 0x8006C6FC: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C6FC: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_0:
    // 0x8006C700: b           L_8006C710
    // 0x8006C704: nop

        goto L_8006C710;
    // 0x8006C704: nop

    // 0x8006C708: b           L_8006C710
    // 0x8006C70C: nop

        goto L_8006C710;
    // 0x8006C70C: nop

L_8006C710:
    // 0x8006C710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C718: jr          $ra
    // 0x8006C71C: nop

    return;
    // 0x8006C71C: nop

;}
RECOMP_FUNC void func_8006C720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C728: jal         0x8005F064
    // 0x8006C72C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C72C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_0:
    // 0x8006C730: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006C734: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006C738: beq         $v0, $zero, L_8006C750
    if (ctx->r2 == 0) {
        // 0x8006C73C: nop

            goto L_8006C750;
    }
    // 0x8006C73C: nop

    // 0x8006C740: jal         0x80061348
    // 0x8006C744: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006C744: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_1:
    // 0x8006C748: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C74C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006C750:
    // 0x8006C750: b           L_8006C760
    // 0x8006C754: nop

        goto L_8006C760;
    // 0x8006C754: nop

    // 0x8006C758: b           L_8006C760
    // 0x8006C75C: nop

        goto L_8006C760;
    // 0x8006C75C: nop

L_8006C760:
    // 0x8006C760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C768: jr          $ra
    // 0x8006C76C: nop

    return;
    // 0x8006C76C: nop

;}
RECOMP_FUNC void func_8006C770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C778: jal         0x8005F064
    // 0x8006C77C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C77C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_0:
    // 0x8006C780: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006C784: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006C788: beq         $v0, $zero, L_8006C7A0
    if (ctx->r2 == 0) {
        // 0x8006C78C: nop

            goto L_8006C7A0;
    }
    // 0x8006C78C: nop

    // 0x8006C790: jal         0x80061348
    // 0x8006C794: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8006C794: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_1:
    // 0x8006C798: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C79C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8006C7A0:
    // 0x8006C7A0: b           L_8006C7B0
    // 0x8006C7A4: nop

        goto L_8006C7B0;
    // 0x8006C7A4: nop

    // 0x8006C7A8: b           L_8006C7B0
    // 0x8006C7AC: nop

        goto L_8006C7B0;
    // 0x8006C7AC: nop

L_8006C7B0:
    // 0x8006C7B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C7B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C7B8: jr          $ra
    // 0x8006C7BC: nop

    return;
    // 0x8006C7BC: nop

;}
RECOMP_FUNC void func_8006C7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C7C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C7C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C7C8: jal         0x8005F064
    // 0x8006C7CC: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C7CC: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_0:
    // 0x8006C7D0: b           L_8006C7E0
    // 0x8006C7D4: nop

        goto L_8006C7E0;
    // 0x8006C7D4: nop

    // 0x8006C7D8: b           L_8006C7E0
    // 0x8006C7DC: nop

        goto L_8006C7E0;
    // 0x8006C7DC: nop

L_8006C7E0:
    // 0x8006C7E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C7E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C7E8: jr          $ra
    // 0x8006C7EC: nop

    return;
    // 0x8006C7EC: nop

;}
RECOMP_FUNC void func_8006C7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C7F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C7F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C7F8: jal         0x8005F064
    // 0x8006C7FC: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C7FC: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    after_0:
    // 0x8006C800: b           L_8006C810
    // 0x8006C804: nop

        goto L_8006C810;
    // 0x8006C804: nop

    // 0x8006C808: b           L_8006C810
    // 0x8006C80C: nop

        goto L_8006C810;
    // 0x8006C80C: nop

L_8006C810:
    // 0x8006C810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C818: jr          $ra
    // 0x8006C81C: nop

    return;
    // 0x8006C81C: nop

;}
RECOMP_FUNC void func_8006C820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C828: jal         0x8005F064
    // 0x8006C82C: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C82C: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    after_0:
    // 0x8006C830: b           L_8006C840
    // 0x8006C834: nop

        goto L_8006C840;
    // 0x8006C834: nop

    // 0x8006C838: b           L_8006C840
    // 0x8006C83C: nop

        goto L_8006C840;
    // 0x8006C83C: nop

L_8006C840:
    // 0x8006C840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C848: jr          $ra
    // 0x8006C84C: nop

    return;
    // 0x8006C84C: nop

;}
RECOMP_FUNC void func_8006C850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C858: jal         0x8005F064
    // 0x8006C85C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C85C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x8006C860: b           L_8006C870
    // 0x8006C864: nop

        goto L_8006C870;
    // 0x8006C864: nop

    // 0x8006C868: b           L_8006C870
    // 0x8006C86C: nop

        goto L_8006C870;
    // 0x8006C86C: nop

L_8006C870:
    // 0x8006C870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C878: jr          $ra
    // 0x8006C87C: nop

    return;
    // 0x8006C87C: nop

;}
RECOMP_FUNC void func_8006C880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C888: jal         0x80061488
    // 0x8006C88C: addiu       $a0, $zero, 0x687
    ctx->r4 = ADD32(0, 0X687);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006C88C: addiu       $a0, $zero, 0x687
    ctx->r4 = ADD32(0, 0X687);
    after_0:
    // 0x8006C890: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006C894: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006C898: b           L_8006C8A8
    // 0x8006C89C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006C8A8;
    // 0x8006C89C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006C8A0: b           L_8006C8A8
    // 0x8006C8A4: nop

        goto L_8006C8A8;
    // 0x8006C8A4: nop

L_8006C8A8:
    // 0x8006C8A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C8AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C8B0: jr          $ra
    // 0x8006C8B4: nop

    return;
    // 0x8006C8B4: nop

;}
RECOMP_FUNC void func_8006C8B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C8B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C8BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C8C0: jal         0x8005F064
    // 0x8006C8C4: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C8C4: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    after_0:
    // 0x8006C8C8: b           L_8006C8D8
    // 0x8006C8CC: nop

        goto L_8006C8D8;
    // 0x8006C8CC: nop

    // 0x8006C8D0: b           L_8006C8D8
    // 0x8006C8D4: nop

        goto L_8006C8D8;
    // 0x8006C8D4: nop

L_8006C8D8:
    // 0x8006C8D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C8DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C8E0: jr          $ra
    // 0x8006C8E4: nop

    return;
    // 0x8006C8E4: nop

;}
RECOMP_FUNC void func_8006C8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C8E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C8EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C8F0: jal         0x8005F064
    // 0x8006C8F4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C8F4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_0:
    // 0x8006C8F8: b           L_8006C908
    // 0x8006C8FC: nop

        goto L_8006C908;
    // 0x8006C8FC: nop

    // 0x8006C900: b           L_8006C908
    // 0x8006C904: nop

        goto L_8006C908;
    // 0x8006C904: nop

L_8006C908:
    // 0x8006C908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C90C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C910: jr          $ra
    // 0x8006C914: nop

    return;
    // 0x8006C914: nop

;}
RECOMP_FUNC void func_8006C918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C91C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C920: jal         0x8005F064
    // 0x8006C924: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C924: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_0:
    // 0x8006C928: b           L_8006C938
    // 0x8006C92C: nop

        goto L_8006C938;
    // 0x8006C92C: nop

    // 0x8006C930: b           L_8006C938
    // 0x8006C934: nop

        goto L_8006C938;
    // 0x8006C934: nop

L_8006C938:
    // 0x8006C938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C93C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C940: jr          $ra
    // 0x8006C944: nop

    return;
    // 0x8006C944: nop

;}
RECOMP_FUNC void func_8006C948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C950: jal         0x8005F064
    // 0x8006C954: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C954: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    after_0:
    // 0x8006C958: b           L_8006C968
    // 0x8006C95C: nop

        goto L_8006C968;
    // 0x8006C95C: nop

    // 0x8006C960: b           L_8006C968
    // 0x8006C964: nop

        goto L_8006C968;
    // 0x8006C964: nop

L_8006C968:
    // 0x8006C968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C96C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C970: jr          $ra
    // 0x8006C974: nop

    return;
    // 0x8006C974: nop

;}
RECOMP_FUNC void func_8006C978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C97C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C980: jal         0x8005F064
    // 0x8006C984: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C984: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_0:
    // 0x8006C988: b           L_8006C998
    // 0x8006C98C: nop

        goto L_8006C998;
    // 0x8006C98C: nop

    // 0x8006C990: b           L_8006C998
    // 0x8006C994: nop

        goto L_8006C998;
    // 0x8006C994: nop

L_8006C998:
    // 0x8006C998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C99C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C9A0: jr          $ra
    // 0x8006C9A4: nop

    return;
    // 0x8006C9A4: nop

;}
RECOMP_FUNC void func_8006C9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C9B0: jal         0x8005F064
    // 0x8006C9B4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C9B4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_0:
    // 0x8006C9B8: b           L_8006C9C8
    // 0x8006C9BC: nop

        goto L_8006C9C8;
    // 0x8006C9BC: nop

    // 0x8006C9C0: b           L_8006C9C8
    // 0x8006C9C4: nop

        goto L_8006C9C8;
    // 0x8006C9C4: nop

L_8006C9C8:
    // 0x8006C9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C9CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C9D0: jr          $ra
    // 0x8006C9D4: nop

    return;
    // 0x8006C9D4: nop

;}
RECOMP_FUNC void func_8006C9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C9D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C9DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C9E0: jal         0x8005F064
    // 0x8006C9E4: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006C9E4: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_0:
    // 0x8006C9E8: b           L_8006C9F8
    // 0x8006C9EC: nop

        goto L_8006C9F8;
    // 0x8006C9EC: nop

    // 0x8006C9F0: b           L_8006C9F8
    // 0x8006C9F4: nop

        goto L_8006C9F8;
    // 0x8006C9F4: nop

L_8006C9F8:
    // 0x8006C9F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C9FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CA00: jr          $ra
    // 0x8006CA04: nop

    return;
    // 0x8006CA04: nop

;}
RECOMP_FUNC void func_8006CA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CA0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CA10: jal         0x8005F064
    // 0x8006CA14: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CA14: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    after_0:
    // 0x8006CA18: b           L_8006CA28
    // 0x8006CA1C: nop

        goto L_8006CA28;
    // 0x8006CA1C: nop

    // 0x8006CA20: b           L_8006CA28
    // 0x8006CA24: nop

        goto L_8006CA28;
    // 0x8006CA24: nop

L_8006CA28:
    // 0x8006CA28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CA2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CA30: jr          $ra
    // 0x8006CA34: nop

    return;
    // 0x8006CA34: nop

;}
RECOMP_FUNC void func_8006CA38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CA3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CA40: jal         0x8005F064
    // 0x8006CA44: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CA44: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    after_0:
    // 0x8006CA48: b           L_8006CA58
    // 0x8006CA4C: nop

        goto L_8006CA58;
    // 0x8006CA4C: nop

    // 0x8006CA50: b           L_8006CA58
    // 0x8006CA54: nop

        goto L_8006CA58;
    // 0x8006CA54: nop

L_8006CA58:
    // 0x8006CA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CA5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CA60: jr          $ra
    // 0x8006CA64: nop

    return;
    // 0x8006CA64: nop

;}
RECOMP_FUNC void func_8006CA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CA6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CA70: jal         0x8005F064
    // 0x8006CA74: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CA74: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_0:
    // 0x8006CA78: b           L_8006CA88
    // 0x8006CA7C: nop

        goto L_8006CA88;
    // 0x8006CA7C: nop

    // 0x8006CA80: b           L_8006CA88
    // 0x8006CA84: nop

        goto L_8006CA88;
    // 0x8006CA84: nop

L_8006CA88:
    // 0x8006CA88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CA8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CA90: jr          $ra
    // 0x8006CA94: nop

    return;
    // 0x8006CA94: nop

;}
RECOMP_FUNC void func_8006CA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CA98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CAA0: jal         0x8005F064
    // 0x8006CAA4: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CAA4: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    after_0:
    // 0x8006CAA8: b           L_8006CAB8
    // 0x8006CAAC: nop

        goto L_8006CAB8;
    // 0x8006CAAC: nop

    // 0x8006CAB0: b           L_8006CAB8
    // 0x8006CAB4: nop

        goto L_8006CAB8;
    // 0x8006CAB4: nop

L_8006CAB8:
    // 0x8006CAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CAC0: jr          $ra
    // 0x8006CAC4: nop

    return;
    // 0x8006CAC4: nop

;}
RECOMP_FUNC void func_8006CAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CAC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CAD0: jal         0x8005F064
    // 0x8006CAD4: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CAD4: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_0:
    // 0x8006CAD8: b           L_8006CAE8
    // 0x8006CADC: nop

        goto L_8006CAE8;
    // 0x8006CADC: nop

    // 0x8006CAE0: b           L_8006CAE8
    // 0x8006CAE4: nop

        goto L_8006CAE8;
    // 0x8006CAE4: nop

L_8006CAE8:
    // 0x8006CAE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CAEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CAF0: jr          $ra
    // 0x8006CAF4: nop

    return;
    // 0x8006CAF4: nop

;}
RECOMP_FUNC void func_8006CAF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CAF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CB00: jal         0x8005F064
    // 0x8006CB04: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CB04: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_0:
    // 0x8006CB08: b           L_8006CB18
    // 0x8006CB0C: nop

        goto L_8006CB18;
    // 0x8006CB0C: nop

    // 0x8006CB10: b           L_8006CB18
    // 0x8006CB14: nop

        goto L_8006CB18;
    // 0x8006CB14: nop

L_8006CB18:
    // 0x8006CB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CB1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CB20: jr          $ra
    // 0x8006CB24: nop

    return;
    // 0x8006CB24: nop

;}
RECOMP_FUNC void func_8006CB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CB2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CB30: jal         0x8005F064
    // 0x8006CB34: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CB34: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_0:
    // 0x8006CB38: b           L_8006CB48
    // 0x8006CB3C: nop

        goto L_8006CB48;
    // 0x8006CB3C: nop

    // 0x8006CB40: b           L_8006CB48
    // 0x8006CB44: nop

        goto L_8006CB48;
    // 0x8006CB44: nop

L_8006CB48:
    // 0x8006CB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CB4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CB50: jr          $ra
    // 0x8006CB54: nop

    return;
    // 0x8006CB54: nop

;}
RECOMP_FUNC void func_8006CB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CB60: jal         0x8005F064
    // 0x8006CB64: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CB64: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
    // 0x8006CB68: b           L_8006CB78
    // 0x8006CB6C: nop

        goto L_8006CB78;
    // 0x8006CB6C: nop

    // 0x8006CB70: b           L_8006CB78
    // 0x8006CB74: nop

        goto L_8006CB78;
    // 0x8006CB74: nop

L_8006CB78:
    // 0x8006CB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CB7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CB80: jr          $ra
    // 0x8006CB84: nop

    return;
    // 0x8006CB84: nop

;}
RECOMP_FUNC void func_8006CB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CB8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CB90: jal         0x8005F064
    // 0x8006CB94: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8006CB94: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    after_0:
    // 0x8006CB98: b           L_8006CBA8
    // 0x8006CB9C: nop

        goto L_8006CBA8;
    // 0x8006CB9C: nop

    // 0x8006CBA0: b           L_8006CBA8
    // 0x8006CBA4: nop

        goto L_8006CBA8;
    // 0x8006CBA4: nop

L_8006CBA8:
    // 0x8006CBA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CBAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CBB0: jr          $ra
    // 0x8006CBB4: nop

    return;
    // 0x8006CBB4: nop

;}
RECOMP_FUNC void func_8006CBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CBB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CBBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CBC0: jal         0x80061488
    // 0x8006CBC4: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006CBC4: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    after_0:
    // 0x8006CBC8: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006CBCC: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006CBD0: b           L_8006CBE0
    // 0x8006CBD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006CBE0;
    // 0x8006CBD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006CBD8: b           L_8006CBE0
    // 0x8006CBDC: nop

        goto L_8006CBE0;
    // 0x8006CBDC: nop

L_8006CBE0:
    // 0x8006CBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CBE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CBE8: jr          $ra
    // 0x8006CBEC: nop

    return;
    // 0x8006CBEC: nop

;}
RECOMP_FUNC void func_8006CBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CBF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CBF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CBF8: jal         0x80061488
    // 0x8006CBFC: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006CBFC: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    after_0:
    // 0x8006CC00: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006CC04: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006CC08: b           L_8006CC18
    // 0x8006CC0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006CC18;
    // 0x8006CC0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006CC10: b           L_8006CC18
    // 0x8006CC14: nop

        goto L_8006CC18;
    // 0x8006CC14: nop

L_8006CC18:
    // 0x8006CC18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CC1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CC20: jr          $ra
    // 0x8006CC24: nop

    return;
    // 0x8006CC24: nop

;}
RECOMP_FUNC void func_8006CC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CC2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CC30: jal         0x80061488
    // 0x8006CC34: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006CC34: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    after_0:
    // 0x8006CC38: slti        $t6, $v0, 0x3
    ctx->r14 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006CC3C: b           L_8006CC4C
    // 0x8006CC40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006CC4C;
    // 0x8006CC40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006CC44: b           L_8006CC4C
    // 0x8006CC48: nop

        goto L_8006CC4C;
    // 0x8006CC48: nop

L_8006CC4C:
    // 0x8006CC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CC54: jr          $ra
    // 0x8006CC58: nop

    return;
    // 0x8006CC58: nop

;}
RECOMP_FUNC void func_8006CC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CC60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CC64: jal         0x80061488
    // 0x8006CC68: addiu       $a0, $zero, 0x482
    ctx->r4 = ADD32(0, 0X482);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8006CC68: addiu       $a0, $zero, 0x482
    ctx->r4 = ADD32(0, 0X482);
    after_0:
    // 0x8006CC6C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8006CC70: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8006CC74: b           L_8006CC84
    // 0x8006CC78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006CC84;
    // 0x8006CC78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006CC7C: b           L_8006CC84
    // 0x8006CC80: nop

        goto L_8006CC84;
    // 0x8006CC80: nop

L_8006CC84:
    // 0x8006CC84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CC88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CC8C: jr          $ra
    // 0x8006CC90: nop

    return;
    // 0x8006CC90: nop

;}
RECOMP_FUNC void func_8006CC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC94: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CC98: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CC9C: nop

    // 0x8006CCA0: lh          $v0, 0x1C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1C);
    // 0x8006CCA4: nop

    // 0x8006CCA8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006CCAC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CCB0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CCB4: beq         $v0, $zero, L_8006CCD0
    if (ctx->r2 == 0) {
        // 0x8006CCB8: nop

            goto L_8006CCD0;
    }
    // 0x8006CCB8: nop

    // 0x8006CCBC: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x8006CCC0: nop

    // 0x8006CCC4: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006CCC8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006CCCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006CCD0:
    // 0x8006CCD0: jr          $ra
    // 0x8006CCD4: nop

    return;
    // 0x8006CCD4: nop

    // 0x8006CCD8: jr          $ra
    // 0x8006CCDC: nop

    return;
    // 0x8006CCDC: nop

    // 0x8006CCE0: jr          $ra
    // 0x8006CCE4: nop

    return;
    // 0x8006CCE4: nop

;}
RECOMP_FUNC void func_8006CCE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CCE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CCEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CCF0: nop

    // 0x8006CCF4: lh          $v0, 0x6($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X6);
    // 0x8006CCF8: nop

    // 0x8006CCFC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CD00: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CD04: jr          $ra
    // 0x8006CD08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CD08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CD0C: jr          $ra
    // 0x8006CD10: nop

    return;
    // 0x8006CD10: nop

    // 0x8006CD14: jr          $ra
    // 0x8006CD18: nop

    return;
    // 0x8006CD18: nop

;}
RECOMP_FUNC void func_8006CD1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CD20: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CD24: nop

    // 0x8006CD28: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x8006CD2C: nop

    // 0x8006CD30: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CD34: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CD38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CD3C: bne         $v0, $zero, L_8006CD58
    if (ctx->r2 != 0) {
        // 0x8006CD40: nop

            goto L_8006CD58;
    }
    // 0x8006CD40: nop

    // 0x8006CD44: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x8006CD48: nop

    // 0x8006CD4C: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CD50: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006CD54: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006CD58:
    // 0x8006CD58: jr          $ra
    // 0x8006CD5C: nop

    return;
    // 0x8006CD5C: nop

    // 0x8006CD60: jr          $ra
    // 0x8006CD64: nop

    return;
    // 0x8006CD64: nop

    // 0x8006CD68: jr          $ra
    // 0x8006CD6C: nop

    return;
    // 0x8006CD6C: nop

;}
RECOMP_FUNC void func_8006CD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CD74: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CD78: nop

    // 0x8006CD7C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x8006CD80: nop

    // 0x8006CD84: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CD88: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CD8C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CD90: bne         $v0, $zero, L_8006CDAC
    if (ctx->r2 != 0) {
        // 0x8006CD94: nop

            goto L_8006CDAC;
    }
    // 0x8006CD94: nop

    // 0x8006CD98: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006CD9C: nop

    // 0x8006CDA0: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CDA4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006CDA8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006CDAC:
    // 0x8006CDAC: jr          $ra
    // 0x8006CDB0: nop

    return;
    // 0x8006CDB0: nop

    // 0x8006CDB4: jr          $ra
    // 0x8006CDB8: nop

    return;
    // 0x8006CDB8: nop

    // 0x8006CDBC: jr          $ra
    // 0x8006CDC0: nop

    return;
    // 0x8006CDC0: nop

;}
RECOMP_FUNC void func_8006CDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CDC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CDC8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CDCC: nop

    // 0x8006CDD0: lh          $v0, 0x14($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X14);
    // 0x8006CDD4: nop

    // 0x8006CDD8: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006CDDC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CDE0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CDE4: bne         $v0, $zero, L_8006CE00
    if (ctx->r2 != 0) {
        // 0x8006CDE8: nop

            goto L_8006CE00;
    }
    // 0x8006CDE8: nop

    // 0x8006CDEC: lh          $v0, 0x16($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X16);
    // 0x8006CDF0: nop

    // 0x8006CDF4: slti        $t8, $v0, 0x12C
    ctx->r24 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006CDF8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8006CDFC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006CE00:
    // 0x8006CE00: jr          $ra
    // 0x8006CE04: nop

    return;
    // 0x8006CE04: nop

    // 0x8006CE08: jr          $ra
    // 0x8006CE0C: nop

    return;
    // 0x8006CE0C: nop

    // 0x8006CE10: jr          $ra
    // 0x8006CE14: nop

    return;
    // 0x8006CE14: nop

;}
RECOMP_FUNC void func_8006CE18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CE18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CE1C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CE20: nop

    // 0x8006CE24: lh          $v0, 0x18($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X18);
    // 0x8006CE28: nop

    // 0x8006CE2C: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CE30: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CE34: jr          $ra
    // 0x8006CE38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CE38: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CE3C: jr          $ra
    // 0x8006CE40: nop

    return;
    // 0x8006CE40: nop

    // 0x8006CE44: jr          $ra
    // 0x8006CE48: nop

    return;
    // 0x8006CE48: nop

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
RECOMP_FUNC void func_8006CEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CEB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CEB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CEBC: nop

    // 0x8006CEC0: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x8006CEC4: nop

    // 0x8006CEC8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CECC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CED0: jr          $ra
    // 0x8006CED4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CED4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CED8: jr          $ra
    // 0x8006CEDC: nop

    return;
    // 0x8006CEDC: nop

    // 0x8006CEE0: jr          $ra
    // 0x8006CEE4: nop

    return;
    // 0x8006CEE4: nop

;}
RECOMP_FUNC void func_8006CEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CEE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CEEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CEF0: nop

    // 0x8006CEF4: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x8006CEF8: nop

    // 0x8006CEFC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CF00: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CF04: jr          $ra
    // 0x8006CF08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CF08: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CF0C: jr          $ra
    // 0x8006CF10: nop

    return;
    // 0x8006CF10: nop

    // 0x8006CF14: jr          $ra
    // 0x8006CF18: nop

    return;
    // 0x8006CF18: nop

;}
RECOMP_FUNC void func_8006CF1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF1C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CF20: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CF24: nop

    // 0x8006CF28: lh          $v0, 0x22($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X22);
    // 0x8006CF2C: nop

    // 0x8006CF30: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CF34: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CF38: jr          $ra
    // 0x8006CF3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CF3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CF40: jr          $ra
    // 0x8006CF44: nop

    return;
    // 0x8006CF44: nop

    // 0x8006CF48: jr          $ra
    // 0x8006CF4C: nop

    return;
    // 0x8006CF4C: nop

;}
RECOMP_FUNC void func_8006CF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF50: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CF54: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CF58: nop

    // 0x8006CF5C: lh          $v0, 0x24($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X24);
    // 0x8006CF60: nop

    // 0x8006CF64: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CF68: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CF6C: jr          $ra
    // 0x8006CF70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CF70: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CF74: jr          $ra
    // 0x8006CF78: nop

    return;
    // 0x8006CF78: nop

    // 0x8006CF7C: jr          $ra
    // 0x8006CF80: nop

    return;
    // 0x8006CF80: nop

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
RECOMP_FUNC void func_8006CFB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CFB8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CFBC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CFC0: nop

    // 0x8006CFC4: lh          $v0, 0x28($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X28);
    // 0x8006CFC8: nop

    // 0x8006CFCC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006CFD0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006CFD4: jr          $ra
    // 0x8006CFD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006CFD8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006CFDC: jr          $ra
    // 0x8006CFE0: nop

    return;
    // 0x8006CFE0: nop

    // 0x8006CFE4: jr          $ra
    // 0x8006CFE8: nop

    return;
    // 0x8006CFE8: nop

;}
RECOMP_FUNC void func_8006CFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CFEC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006CFF0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006CFF4: nop

    // 0x8006CFF8: lh          $v0, 0x2A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2A);
    // 0x8006CFFC: nop

    // 0x8006D000: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006D004: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D008: jr          $ra
    // 0x8006D00C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D00C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D010: jr          $ra
    // 0x8006D014: nop

    return;
    // 0x8006D014: nop

    // 0x8006D018: jr          $ra
    // 0x8006D01C: nop

    return;
    // 0x8006D01C: nop

;}
RECOMP_FUNC void func_8006D020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D020: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006D024: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006D028: nop

    // 0x8006D02C: lh          $v0, 0x12($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X12);
    // 0x8006D030: nop

    // 0x8006D034: slti        $t7, $v0, 0x64
    ctx->r15 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8006D038: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006D03C: jr          $ra
    // 0x8006D040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006D040: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006D044: jr          $ra
    // 0x8006D048: nop

    return;
    // 0x8006D048: nop

    // 0x8006D04C: jr          $ra
    // 0x8006D050: nop

    return;
    // 0x8006D050: nop

;}
