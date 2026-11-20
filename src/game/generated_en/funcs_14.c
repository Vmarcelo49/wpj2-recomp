#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800656E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800656E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800656EC: jal         0x8005F064
    // 0x800656F0: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800656F0: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x800656F4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800656F8: b           L_80065708
    // 0x800656FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065708;
    // 0x800656FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065700: b           L_80065708
    // 0x80065704: nop

        goto L_80065708;
    // 0x80065704: nop

L_80065708:
    // 0x80065708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006570C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065710: jr          $ra
    // 0x80065714: nop

    return;
    // 0x80065714: nop

;}
RECOMP_FUNC void func_80065718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006571C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065720: jal         0x8005F064
    // 0x80065724: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065724: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x80065728: b           L_80065738
    // 0x8006572C: nop

        goto L_80065738;
    // 0x8006572C: nop

    // 0x80065730: b           L_80065738
    // 0x80065734: nop

        goto L_80065738;
    // 0x80065734: nop

L_80065738:
    // 0x80065738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006573C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065740: jr          $ra
    // 0x80065744: nop

    return;
    // 0x80065744: nop

;}
RECOMP_FUNC void func_80065748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006574C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065750: jal         0x8005F064
    // 0x80065754: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065754: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
    after_0:
    // 0x80065758: b           L_80065768
    // 0x8006575C: nop

        goto L_80065768;
    // 0x8006575C: nop

    // 0x80065760: b           L_80065768
    // 0x80065764: nop

        goto L_80065768;
    // 0x80065764: nop

L_80065768:
    // 0x80065768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006576C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065770: jr          $ra
    // 0x80065774: nop

    return;
    // 0x80065774: nop

;}
RECOMP_FUNC void func_80065778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065778: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006577C: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065780: nop

    // 0x80065784: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80065788: nop

    // 0x8006578C: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80065790: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065794: jr          $ra
    // 0x80065798: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065798: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006579C: jr          $ra
    // 0x800657A0: nop

    return;
    // 0x800657A0: nop

    // 0x800657A4: jr          $ra
    // 0x800657A8: nop

    return;
    // 0x800657A8: nop

;}
RECOMP_FUNC void func_800657AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800657AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800657B0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800657B4: nop

    // 0x800657B8: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x800657BC: nop

    // 0x800657C0: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x800657C4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800657C8: jr          $ra
    // 0x800657CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800657CC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800657D0: jr          $ra
    // 0x800657D4: nop

    return;
    // 0x800657D4: nop

    // 0x800657D8: jr          $ra
    // 0x800657DC: nop

    return;
    // 0x800657DC: nop

;}
RECOMP_FUNC void func_800657E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800657E0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800657E4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800657E8: nop

    // 0x800657EC: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x800657F0: nop

    // 0x800657F4: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x800657F8: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800657FC: jr          $ra
    // 0x80065800: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065800: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065804: jr          $ra
    // 0x80065808: nop

    return;
    // 0x80065808: nop

    // 0x8006580C: jr          $ra
    // 0x80065810: nop

    return;
    // 0x80065810: nop

;}
RECOMP_FUNC void func_80065814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006581C: jal         0x80061488
    // 0x80065820: addiu       $a0, $zero, 0x5F1
    ctx->r4 = ADD32(0, 0X5F1);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065820: addiu       $a0, $zero, 0x5F1
    ctx->r4 = ADD32(0, 0X5F1);
    after_0:
    // 0x80065824: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80065828: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006582C: b           L_8006583C
    // 0x80065830: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006583C;
    // 0x80065830: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065834: b           L_8006583C
    // 0x80065838: nop

        goto L_8006583C;
    // 0x80065838: nop

L_8006583C:
    // 0x8006583C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065844: jr          $ra
    // 0x80065848: nop

    return;
    // 0x80065848: nop

;}
RECOMP_FUNC void func_8006584C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006584C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065850: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065854: nop

    // 0x80065858: lh          $v0, 0x24($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X24);
    // 0x8006585C: nop

    // 0x80065860: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80065864: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065868: jr          $ra
    // 0x8006586C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006586C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065870: jr          $ra
    // 0x80065874: nop

    return;
    // 0x80065874: nop

    // 0x80065878: jr          $ra
    // 0x8006587C: nop

    return;
    // 0x8006587C: nop

;}
RECOMP_FUNC void func_80065880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065880: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065884: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065888: nop

    // 0x8006588C: lh          $v0, 0x24($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X24);
    // 0x80065890: nop

    // 0x80065894: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065898: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006589C: jr          $ra
    // 0x800658A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800658A0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800658A4: jr          $ra
    // 0x800658A8: nop

    return;
    // 0x800658A8: nop

    // 0x800658AC: jr          $ra
    // 0x800658B0: nop

    return;
    // 0x800658B0: nop

;}
RECOMP_FUNC void func_800658B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800658B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800658BC: jal         0x8005F064
    // 0x800658C0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800658C0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_0:
    // 0x800658C4: b           L_800658D4
    // 0x800658C8: nop

        goto L_800658D4;
    // 0x800658C8: nop

    // 0x800658CC: b           L_800658D4
    // 0x800658D0: nop

        goto L_800658D4;
    // 0x800658D0: nop

L_800658D4:
    // 0x800658D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800658D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800658DC: jr          $ra
    // 0x800658E0: nop

    return;
    // 0x800658E0: nop

;}
RECOMP_FUNC void func_800658E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800658E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800658EC: jal         0x8005F064
    // 0x800658F0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x800658F0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_0:
    // 0x800658F4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800658F8: b           L_80065908
    // 0x800658FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065908;
    // 0x800658FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065900: b           L_80065908
    // 0x80065904: nop

        goto L_80065908;
    // 0x80065904: nop

L_80065908:
    // 0x80065908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006590C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065910: jr          $ra
    // 0x80065914: nop

    return;
    // 0x80065914: nop

;}
RECOMP_FUNC void func_80065918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006591C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065920: jal         0x80061488
    // 0x80065924: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065924: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    after_0:
    // 0x80065928: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8006592C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80065930: b           L_80065940
    // 0x80065934: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065940;
    // 0x80065934: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065938: b           L_80065940
    // 0x8006593C: nop

        goto L_80065940;
    // 0x8006593C: nop

L_80065940:
    // 0x80065940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065948: jr          $ra
    // 0x8006594C: nop

    return;
    // 0x8006594C: nop

;}
RECOMP_FUNC void func_80065950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065950: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065954: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065958: nop

    // 0x8006595C: lh          $v0, 0x20($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X20);
    // 0x80065960: nop

    // 0x80065964: slti        $t7, $v0, 0x12C
    ctx->r15 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x80065968: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006596C: jr          $ra
    // 0x80065970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065970: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065974: jr          $ra
    // 0x80065978: nop

    return;
    // 0x80065978: nop

    // 0x8006597C: jr          $ra
    // 0x80065980: nop

    return;
    // 0x80065980: nop

;}
RECOMP_FUNC void func_80065984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006598C: jal         0x80061488
    // 0x80065990: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065990: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    after_0:
    // 0x80065994: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80065998: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8006599C: b           L_800659AC
    // 0x800659A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800659AC;
    // 0x800659A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800659A4: b           L_800659AC
    // 0x800659A8: nop

        goto L_800659AC;
    // 0x800659A8: nop

L_800659AC:
    // 0x800659AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800659B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800659B4: jr          $ra
    // 0x800659B8: nop

    return;
    // 0x800659B8: nop

;}
RECOMP_FUNC void func_800659BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800659BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800659C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800659C4: jal         0x80061488
    // 0x800659C8: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x800659C8: addiu       $a0, $zero, 0x5A6
    ctx->r4 = ADD32(0, 0X5A6);
    after_0:
    // 0x800659CC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800659D0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800659D4: b           L_800659E4
    // 0x800659D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800659E4;
    // 0x800659D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800659DC: b           L_800659E4
    // 0x800659E0: nop

        goto L_800659E4;
    // 0x800659E0: nop

L_800659E4:
    // 0x800659E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800659E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800659EC: jr          $ra
    // 0x800659F0: nop

    return;
    // 0x800659F0: nop

;}
RECOMP_FUNC void func_800659F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800659F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800659F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800659FC: jal         0x80061488
    // 0x80065A00: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065A00: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065A04: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065A08: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065A0C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065A10: beq         $v0, $zero, L_80065A38
    if (ctx->r2 == 0) {
        // 0x80065A14: nop

            goto L_80065A38;
    }
    // 0x80065A14: nop

    // 0x80065A18: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80065A1C: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80065A20: nop

    // 0x80065A24: lh          $v0, 0x30($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X30);
    // 0x80065A28: nop

    // 0x80065A2C: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065A30: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80065A34: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065A38:
    // 0x80065A38: b           L_80065A48
    // 0x80065A3C: nop

        goto L_80065A48;
    // 0x80065A3C: nop

    // 0x80065A40: b           L_80065A48
    // 0x80065A44: nop

        goto L_80065A48;
    // 0x80065A44: nop

L_80065A48:
    // 0x80065A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065A50: jr          $ra
    // 0x80065A54: nop

    return;
    // 0x80065A54: nop

;}
RECOMP_FUNC void func_80065A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065A60: jal         0x80061488
    // 0x80065A64: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065A64: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065A68: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065A6C: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065A70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065A74: beq         $v0, $zero, L_80065A9C
    if (ctx->r2 == 0) {
        // 0x80065A78: nop

            goto L_80065A9C;
    }
    // 0x80065A78: nop

    // 0x80065A7C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80065A80: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80065A84: nop

    // 0x80065A88: lh          $v0, 0x32($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X32);
    // 0x80065A8C: nop

    // 0x80065A90: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065A94: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80065A98: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065A9C:
    // 0x80065A9C: b           L_80065AAC
    // 0x80065AA0: nop

        goto L_80065AAC;
    // 0x80065AA0: nop

    // 0x80065AA4: b           L_80065AAC
    // 0x80065AA8: nop

        goto L_80065AAC;
    // 0x80065AA8: nop

L_80065AAC:
    // 0x80065AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065AB4: jr          $ra
    // 0x80065AB8: nop

    return;
    // 0x80065AB8: nop

;}
RECOMP_FUNC void func_80065ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065ABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065AC4: jal         0x80061488
    // 0x80065AC8: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065AC8: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065ACC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065AD0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065AD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065AD8: beq         $v0, $zero, L_80065B00
    if (ctx->r2 == 0) {
        // 0x80065ADC: nop

            goto L_80065B00;
    }
    // 0x80065ADC: nop

    // 0x80065AE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80065AE4: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80065AE8: nop

    // 0x80065AEC: lh          $v0, 0x34($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X34);
    // 0x80065AF0: nop

    // 0x80065AF4: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065AF8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80065AFC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065B00:
    // 0x80065B00: b           L_80065B10
    // 0x80065B04: nop

        goto L_80065B10;
    // 0x80065B04: nop

    // 0x80065B08: b           L_80065B10
    // 0x80065B0C: nop

        goto L_80065B10;
    // 0x80065B0C: nop

L_80065B10:
    // 0x80065B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065B18: jr          $ra
    // 0x80065B1C: nop

    return;
    // 0x80065B1C: nop

;}
RECOMP_FUNC void func_80065B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065B28: jal         0x80061488
    // 0x80065B2C: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065B2C: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065B30: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065B34: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065B38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065B3C: beq         $v0, $zero, L_80065B64
    if (ctx->r2 == 0) {
        // 0x80065B40: nop

            goto L_80065B64;
    }
    // 0x80065B40: nop

    // 0x80065B44: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80065B48: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80065B4C: nop

    // 0x80065B50: lh          $v0, 0x36($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X36);
    // 0x80065B54: nop

    // 0x80065B58: slti        $t8, $v0, 0x2BC
    ctx->r24 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065B5C: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80065B60: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065B64:
    // 0x80065B64: b           L_80065B74
    // 0x80065B68: nop

        goto L_80065B74;
    // 0x80065B68: nop

    // 0x80065B6C: b           L_80065B74
    // 0x80065B70: nop

        goto L_80065B74;
    // 0x80065B70: nop

L_80065B74:
    // 0x80065B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065B7C: jr          $ra
    // 0x80065B80: nop

    return;
    // 0x80065B80: nop

;}
RECOMP_FUNC void func_80065B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065B8C: jal         0x80061488
    // 0x80065B90: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065B90: addiu       $a0, $zero, 0x59C
    ctx->r4 = ADD32(0, 0X59C);
    after_0:
    // 0x80065B94: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065B98: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065B9C: b           L_80065BAC
    // 0x80065BA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065BAC;
    // 0x80065BA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065BA4: b           L_80065BAC
    // 0x80065BA8: nop

        goto L_80065BAC;
    // 0x80065BA8: nop

L_80065BAC:
    // 0x80065BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065BB4: jr          $ra
    // 0x80065BB8: nop

    return;
    // 0x80065BB8: nop

;}
RECOMP_FUNC void func_80065BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BBC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065BC0: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065BC4: nop

    // 0x80065BC8: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80065BCC: nop

    // 0x80065BD0: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065BD4: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065BD8: jr          $ra
    // 0x80065BDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065BDC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065BE0: jr          $ra
    // 0x80065BE4: nop

    return;
    // 0x80065BE4: nop

    // 0x80065BE8: jr          $ra
    // 0x80065BEC: nop

    return;
    // 0x80065BEC: nop

;}
RECOMP_FUNC void func_80065BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BF0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065BF4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065BF8: nop

    // 0x80065BFC: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80065C00: nop

    // 0x80065C04: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065C08: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065C0C: jr          $ra
    // 0x80065C10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80065C10: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065C14: jr          $ra
    // 0x80065C18: nop

    return;
    // 0x80065C18: nop

    // 0x80065C1C: jr          $ra
    // 0x80065C20: nop

    return;
    // 0x80065C20: nop

;}
RECOMP_FUNC void func_80065C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065C2C: jal         0x80061488
    // 0x80065C30: addiu       $a0, $zero, 0x6CF
    ctx->r4 = ADD32(0, 0X6CF);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065C30: addiu       $a0, $zero, 0x6CF
    ctx->r4 = ADD32(0, 0X6CF);
    after_0:
    // 0x80065C34: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065C38: b           L_80065C48
    // 0x80065C3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065C48;
    // 0x80065C3C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065C40: b           L_80065C48
    // 0x80065C44: nop

        goto L_80065C48;
    // 0x80065C44: nop

L_80065C48:
    // 0x80065C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065C50: jr          $ra
    // 0x80065C54: nop

    return;
    // 0x80065C54: nop

;}
RECOMP_FUNC void func_80065C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065C60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065C64: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065C68: nop

    // 0x80065C6C: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80065C70: nop

    // 0x80065C74: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065C78: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065C7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065C80: beq         $v0, $zero, L_80065C98
    if (ctx->r2 == 0) {
        // 0x80065C84: nop

            goto L_80065C98;
    }
    // 0x80065C84: nop

    // 0x80065C88: jal         0x8005F064
    // 0x80065C8C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065C8C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_0:
    // 0x80065C90: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80065C94: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065C98:
    // 0x80065C98: b           L_80065CA8
    // 0x80065C9C: nop

        goto L_80065CA8;
    // 0x80065C9C: nop

    // 0x80065CA0: b           L_80065CA8
    // 0x80065CA4: nop

        goto L_80065CA8;
    // 0x80065CA4: nop

L_80065CA8:
    // 0x80065CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065CB0: jr          $ra
    // 0x80065CB4: nop

    return;
    // 0x80065CB4: nop

;}
RECOMP_FUNC void func_80065CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065CC0: jal         0x8005F064
    // 0x80065CC4: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80065CC4: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_0:
    // 0x80065CC8: b           L_80065CD8
    // 0x80065CCC: nop

        goto L_80065CD8;
    // 0x80065CCC: nop

    // 0x80065CD0: b           L_80065CD8
    // 0x80065CD4: nop

        goto L_80065CD8;
    // 0x80065CD4: nop

L_80065CD8:
    // 0x80065CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065CE0: jr          $ra
    // 0x80065CE4: nop

    return;
    // 0x80065CE4: nop

;}
RECOMP_FUNC void func_80065CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065CE8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065CEC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065CF0: nop

    // 0x80065CF4: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80065CF8: nop

    // 0x80065CFC: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80065D00: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065D04: beq         $v0, $zero, L_80065D1C
    if (ctx->r2 == 0) {
        // 0x80065D08: nop

            goto L_80065D1C;
    }
    // 0x80065D08: nop

    // 0x80065D0C: lh          $v0, 0x30($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X30);
    // 0x80065D10: nop

    // 0x80065D14: slti        $t8, $v0, 0x321
    ctx->r24 = SIGNED(ctx->r2) < 0X321 ? 1 : 0;
    // 0x80065D18: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065D1C:
    // 0x80065D1C: jr          $ra
    // 0x80065D20: nop

    return;
    // 0x80065D20: nop

    // 0x80065D24: jr          $ra
    // 0x80065D28: nop

    return;
    // 0x80065D28: nop

    // 0x80065D2C: jr          $ra
    // 0x80065D30: nop

    return;
    // 0x80065D30: nop

;}
RECOMP_FUNC void func_80065D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065D34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065D38: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065D3C: nop

    // 0x80065D40: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80065D44: nop

    // 0x80065D48: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065D4C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065D50: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065D54: beq         $v0, $zero, L_80065D6C
    if (ctx->r2 == 0) {
        // 0x80065D58: nop

            goto L_80065D6C;
    }
    // 0x80065D58: nop

    // 0x80065D5C: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80065D60: nop

    // 0x80065D64: slti        $t8, $v0, 0x321
    ctx->r24 = SIGNED(ctx->r2) < 0X321 ? 1 : 0;
    // 0x80065D68: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065D6C:
    // 0x80065D6C: jr          $ra
    // 0x80065D70: nop

    return;
    // 0x80065D70: nop

    // 0x80065D74: jr          $ra
    // 0x80065D78: nop

    return;
    // 0x80065D78: nop

    // 0x80065D7C: jr          $ra
    // 0x80065D80: nop

    return;
    // 0x80065D80: nop

;}
RECOMP_FUNC void func_80065D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065D84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065D88: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065D8C: nop

    // 0x80065D90: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80065D94: nop

    // 0x80065D98: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065D9C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065DA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065DA4: beq         $v0, $zero, L_80065DBC
    if (ctx->r2 == 0) {
        // 0x80065DA8: nop

            goto L_80065DBC;
    }
    // 0x80065DA8: nop

    // 0x80065DAC: lh          $v0, 0x34($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X34);
    // 0x80065DB0: nop

    // 0x80065DB4: slti        $t8, $v0, 0x321
    ctx->r24 = SIGNED(ctx->r2) < 0X321 ? 1 : 0;
    // 0x80065DB8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065DBC:
    // 0x80065DBC: jr          $ra
    // 0x80065DC0: nop

    return;
    // 0x80065DC0: nop

    // 0x80065DC4: jr          $ra
    // 0x80065DC8: nop

    return;
    // 0x80065DC8: nop

    // 0x80065DCC: jr          $ra
    // 0x80065DD0: nop

    return;
    // 0x80065DD0: nop

;}
RECOMP_FUNC void func_80065DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065DD4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80065DD8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80065DDC: nop

    // 0x80065DE0: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x80065DE4: nop

    // 0x80065DE8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x80065DEC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80065DF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80065DF4: beq         $v0, $zero, L_80065E0C
    if (ctx->r2 == 0) {
        // 0x80065DF8: nop

            goto L_80065E0C;
    }
    // 0x80065DF8: nop

    // 0x80065DFC: lh          $v0, 0x36($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X36);
    // 0x80065E00: nop

    // 0x80065E04: slti        $t8, $v0, 0x321
    ctx->r24 = SIGNED(ctx->r2) < 0X321 ? 1 : 0;
    // 0x80065E08: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80065E0C:
    // 0x80065E0C: jr          $ra
    // 0x80065E10: nop

    return;
    // 0x80065E10: nop

    // 0x80065E14: jr          $ra
    // 0x80065E18: nop

    return;
    // 0x80065E18: nop

    // 0x80065E1C: jr          $ra
    // 0x80065E20: nop

    return;
    // 0x80065E20: nop

;}
RECOMP_FUNC void func_80065E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065E2C: jal         0x80061488
    // 0x80065E30: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065E30: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_0:
    // 0x80065E34: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065E38: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065E3C: b           L_80065E4C
    // 0x80065E40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065E4C;
    // 0x80065E40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065E44: b           L_80065E4C
    // 0x80065E48: nop

        goto L_80065E4C;
    // 0x80065E48: nop

L_80065E4C:
    // 0x80065E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065E50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065E54: jr          $ra
    // 0x80065E58: nop

    return;
    // 0x80065E58: nop

;}
RECOMP_FUNC void func_80065E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065E60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065E64: jal         0x80061488
    // 0x80065E68: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065E68: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    after_0:
    // 0x80065E6C: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065E70: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065E74: b           L_80065E84
    // 0x80065E78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065E84;
    // 0x80065E78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065E7C: b           L_80065E84
    // 0x80065E80: nop

        goto L_80065E84;
    // 0x80065E80: nop

L_80065E84:
    // 0x80065E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065E88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065E8C: jr          $ra
    // 0x80065E90: nop

    return;
    // 0x80065E90: nop

;}
RECOMP_FUNC void func_80065E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065E9C: jal         0x80061348
    // 0x80065EA0: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065EA0: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80065EA4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065EA8: b           L_80065EB8
    // 0x80065EAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065EB8;
    // 0x80065EAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065EB0: b           L_80065EB8
    // 0x80065EB4: nop

        goto L_80065EB8;
    // 0x80065EB4: nop

L_80065EB8:
    // 0x80065EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065EC0: jr          $ra
    // 0x80065EC4: nop

    return;
    // 0x80065EC4: nop

;}
RECOMP_FUNC void func_80065EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065ED0: jal         0x80061348
    // 0x80065ED4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065ED4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80065ED8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065EDC: b           L_80065EEC
    // 0x80065EE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065EEC;
    // 0x80065EE0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065EE4: b           L_80065EEC
    // 0x80065EE8: nop

        goto L_80065EEC;
    // 0x80065EE8: nop

L_80065EEC:
    // 0x80065EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065EF4: jr          $ra
    // 0x80065EF8: nop

    return;
    // 0x80065EF8: nop

;}
RECOMP_FUNC void func_80065EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065F04: jal         0x80061348
    // 0x80065F08: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065F08: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80065F0C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065F10: b           L_80065F20
    // 0x80065F14: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065F20;
    // 0x80065F14: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065F18: b           L_80065F20
    // 0x80065F1C: nop

        goto L_80065F20;
    // 0x80065F1C: nop

L_80065F20:
    // 0x80065F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065F28: jr          $ra
    // 0x80065F2C: nop

    return;
    // 0x80065F2C: nop

;}
RECOMP_FUNC void func_80065F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065F38: jal         0x80061348
    // 0x80065F3C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065F3C: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80065F40: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065F44: b           L_80065F54
    // 0x80065F48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065F54;
    // 0x80065F48: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065F4C: b           L_80065F54
    // 0x80065F50: nop

        goto L_80065F54;
    // 0x80065F50: nop

L_80065F54:
    // 0x80065F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065F5C: jr          $ra
    // 0x80065F60: nop

    return;
    // 0x80065F60: nop

;}
RECOMP_FUNC void func_80065F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065F6C: jal         0x80061348
    // 0x80065F70: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065F70: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80065F74: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065F78: b           L_80065F88
    // 0x80065F7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065F88;
    // 0x80065F7C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065F80: b           L_80065F88
    // 0x80065F84: nop

        goto L_80065F88;
    // 0x80065F84: nop

L_80065F88:
    // 0x80065F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065F90: jr          $ra
    // 0x80065F94: nop

    return;
    // 0x80065F94: nop

;}
RECOMP_FUNC void func_80065F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065FA0: jal         0x80061348
    // 0x80065FA4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80065FA4: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80065FA8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80065FAC: b           L_80065FBC
    // 0x80065FB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065FBC;
    // 0x80065FB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065FB4: b           L_80065FBC
    // 0x80065FB8: nop

        goto L_80065FBC;
    // 0x80065FB8: nop

L_80065FBC:
    // 0x80065FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065FC4: jr          $ra
    // 0x80065FC8: nop

    return;
    // 0x80065FC8: nop

;}
RECOMP_FUNC void func_80065FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065FD4: jal         0x80061488
    // 0x80065FD8: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x80065FD8: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    after_0:
    // 0x80065FDC: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80065FE0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80065FE4: b           L_80065FF4
    // 0x80065FE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80065FF4;
    // 0x80065FE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065FEC: b           L_80065FF4
    // 0x80065FF0: nop

        goto L_80065FF4;
    // 0x80065FF0: nop

L_80065FF4:
    // 0x80065FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065FF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065FFC: jr          $ra
    // 0x80066000: nop

    return;
    // 0x80066000: nop

;}
RECOMP_FUNC void func_80066004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066004: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066008: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006600C: nop

    // 0x80066010: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80066014: nop

    // 0x80066018: slti        $t7, $v0, 0x259
    ctx->r15 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
    // 0x8006601C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80066020: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066024: beq         $v0, $zero, L_8006603C
    if (ctx->r2 == 0) {
        // 0x80066028: nop

            goto L_8006603C;
    }
    // 0x80066028: nop

    // 0x8006602C: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80066030: nop

    // 0x80066034: slti        $t8, $v0, 0x2BD
    ctx->r24 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80066038: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006603C:
    // 0x8006603C: jr          $ra
    // 0x80066040: nop

    return;
    // 0x80066040: nop

    // 0x80066044: jr          $ra
    // 0x80066048: nop

    return;
    // 0x80066048: nop

    // 0x8006604C: jr          $ra
    // 0x80066050: nop

    return;
    // 0x80066050: nop

;}
RECOMP_FUNC void func_80066054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066054: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066058: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006605C: nop

    // 0x80066060: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80066064: nop

    // 0x80066068: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006606C: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80066070: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80066074: beq         $v0, $zero, L_8006608C
    if (ctx->r2 == 0) {
        // 0x80066078: nop

            goto L_8006608C;
    }
    // 0x80066078: nop

    // 0x8006607C: lh          $v0, 0x32($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X32);
    // 0x80066080: nop

    // 0x80066084: slti        $t8, $v0, 0x259
    ctx->r24 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
    // 0x80066088: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8006608C:
    // 0x8006608C: jr          $ra
    // 0x80066090: nop

    return;
    // 0x80066090: nop

    // 0x80066094: jr          $ra
    // 0x80066098: nop

    return;
    // 0x80066098: nop

    // 0x8006609C: jr          $ra
    // 0x800660A0: nop

    return;
    // 0x800660A0: nop

;}
RECOMP_FUNC void func_800660A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800660A8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800660AC: nop

    // 0x800660B0: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800660B4: nop

    // 0x800660B8: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800660BC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800660C0: jr          $ra
    // 0x800660C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800660C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800660C8: jr          $ra
    // 0x800660CC: nop

    return;
    // 0x800660CC: nop

    // 0x800660D0: jr          $ra
    // 0x800660D4: nop

    return;
    // 0x800660D4: nop

;}
RECOMP_FUNC void func_800660D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800660DC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800660E0: nop

    // 0x800660E4: lh          $v0, 0x2C($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2C);
    // 0x800660E8: nop

    // 0x800660EC: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x800660F0: jr          $ra
    // 0x800660F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800660F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800660F8: jr          $ra
    // 0x800660FC: nop

    return;
    // 0x800660FC: nop

    // 0x80066100: jr          $ra
    // 0x80066104: nop

    return;
    // 0x80066104: nop

;}
RECOMP_FUNC void func_80066108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006610C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066110: jal         0x80061348
    // 0x80066114: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066114: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066118: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006611C: b           L_8006612C
    // 0x80066120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8006612C;
    // 0x80066120: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066124: b           L_8006612C
    // 0x80066128: nop

        goto L_8006612C;
    // 0x80066128: nop

L_8006612C:
    // 0x8006612C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066134: jr          $ra
    // 0x80066138: nop

    return;
    // 0x80066138: nop

;}
RECOMP_FUNC void func_8006613C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006613C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066144: jal         0x80061348
    // 0x80066148: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066148: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x8006614C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066150: b           L_80066160
    // 0x80066154: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066160;
    // 0x80066154: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066158: b           L_80066160
    // 0x8006615C: nop

        goto L_80066160;
    // 0x8006615C: nop

L_80066160:
    // 0x80066160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066168: jr          $ra
    // 0x8006616C: nop

    return;
    // 0x8006616C: nop

;}
RECOMP_FUNC void func_80066170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066178: jal         0x80061348
    // 0x8006617C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006617C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066180: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066184: b           L_80066194
    // 0x80066188: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066194;
    // 0x80066188: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006618C: b           L_80066194
    // 0x80066190: nop

        goto L_80066194;
    // 0x80066190: nop

L_80066194:
    // 0x80066194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006619C: jr          $ra
    // 0x800661A0: nop

    return;
    // 0x800661A0: nop

;}
RECOMP_FUNC void func_800661A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800661A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800661A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800661AC: jal         0x80061348
    // 0x800661B0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800661B0: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x800661B4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800661B8: b           L_800661C8
    // 0x800661BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800661C8;
    // 0x800661BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800661C0: b           L_800661C8
    // 0x800661C4: nop

        goto L_800661C8;
    // 0x800661C4: nop

L_800661C8:
    // 0x800661C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800661CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800661D0: jr          $ra
    // 0x800661D4: nop

    return;
    // 0x800661D4: nop

;}
RECOMP_FUNC void func_800661D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800661D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800661DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800661E0: jal         0x80061348
    // 0x800661E4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800661E4: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x800661E8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800661EC: b           L_800661FC
    // 0x800661F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800661FC;
    // 0x800661F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800661F4: b           L_800661FC
    // 0x800661F8: nop

        goto L_800661FC;
    // 0x800661F8: nop

L_800661FC:
    // 0x800661FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066204: jr          $ra
    // 0x80066208: nop

    return;
    // 0x80066208: nop

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
RECOMP_FUNC void func_80066240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066248: jal         0x80061348
    // 0x8006624C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006624C: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_0:
    // 0x80066250: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066254: b           L_80066264
    // 0x80066258: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066264;
    // 0x80066258: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8006625C: b           L_80066264
    // 0x80066260: nop

        goto L_80066264;
    // 0x80066260: nop

L_80066264:
    // 0x80066264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006626C: jr          $ra
    // 0x80066270: nop

    return;
    // 0x80066270: nop

;}
RECOMP_FUNC void func_80066274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006627C: jal         0x80061348
    // 0x80066280: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80066280: addiu       $a0, $zero, 0x12E
    ctx->r4 = ADD32(0, 0X12E);
    after_0:
    // 0x80066284: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80066288: b           L_80066298
    // 0x8006628C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80066298;
    // 0x8006628C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80066290: b           L_80066298
    // 0x80066294: nop

        goto L_80066298;
    // 0x80066294: nop

L_80066298:
    // 0x80066298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006629C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800662A0: jr          $ra
    // 0x800662A4: nop

    return;
    // 0x800662A4: nop

;}
