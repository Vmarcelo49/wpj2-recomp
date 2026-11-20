#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_8006FF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FF80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006FF84: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006FF88: nop

    // 0x8006FF8C: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x8006FF90: nop

    // 0x8006FF94: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x8006FF98: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006FF9C: jr          $ra
    // 0x8006FFA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006FFA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FFA4: jr          $ra
    // 0x8006FFA8: nop

    return;
    // 0x8006FFA8: nop

    // 0x8006FFAC: jr          $ra
    // 0x8006FFB0: nop

    return;
    // 0x8006FFB0: nop

;}
RECOMP_FUNC void func_8006FFB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FFB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006FFB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x8006FFBC: nop

    // 0x8006FFC0: lh          $v0, 0x2E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X2E);
    // 0x8006FFC4: nop

    // 0x8006FFC8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x8006FFCC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8006FFD0: jr          $ra
    // 0x8006FFD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006FFD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8006FFD8: jr          $ra
    // 0x8006FFDC: nop

    return;
    // 0x8006FFDC: nop

    // 0x8006FFE0: jr          $ra
    // 0x8006FFE4: nop

    return;
    // 0x8006FFE4: nop

;}
RECOMP_FUNC void func_8006FFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FFE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FFEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FFF0: jal         0x80061348
    // 0x8006FFF4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8006FFF4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x8006FFF8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006FFFC: b           L_8007000C
    // 0x80070000: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8007000C;
    // 0x80070000: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070004: b           L_8007000C
    // 0x80070008: nop

        goto L_8007000C;
    // 0x80070008: nop

L_8007000C:
    // 0x8007000C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070014: jr          $ra
    // 0x80070018: nop

    return;
    // 0x80070018: nop

;}
RECOMP_FUNC void func_8007001C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007001C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070024: jal         0x80061348
    // 0x80070028: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070028: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x8007002C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070030: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070034: beq         $v0, $zero, L_80070084
    if (ctx->r2 == 0) {
        // 0x80070038: nop

            goto L_80070084;
    }
    // 0x80070038: nop

    // 0x8007003C: jal         0x80061348
    // 0x80070040: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070040: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070044: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070048: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007004C: beq         $v0, $zero, L_80070084
    if (ctx->r2 == 0) {
        // 0x80070050: nop

            goto L_80070084;
    }
    // 0x80070050: nop

    // 0x80070054: jal         0x80061348
    // 0x80070058: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070058: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x8007005C: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070060: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070064: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070068: beq         $v0, $zero, L_80070084
    if (ctx->r2 == 0) {
        // 0x8007006C: nop

            goto L_80070084;
    }
    // 0x8007006C: nop

    // 0x80070070: jal         0x80061348
    // 0x80070074: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070074: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070078: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007007C: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070080: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070084:
    // 0x80070084: b           L_80070094
    // 0x80070088: nop

        goto L_80070094;
    // 0x80070088: nop

    // 0x8007008C: b           L_80070094
    // 0x80070090: nop

        goto L_80070094;
    // 0x80070090: nop

L_80070094:
    // 0x80070094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007009C: jr          $ra
    // 0x800700A0: nop

    return;
    // 0x800700A0: nop

;}
RECOMP_FUNC void func_800700A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800700A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800700A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800700AC: jal         0x80061348
    // 0x800700B0: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800700B0: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800700B4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800700B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800700BC: beq         $v0, $zero, L_8007010C
    if (ctx->r2 == 0) {
        // 0x800700C0: nop

            goto L_8007010C;
    }
    // 0x800700C0: nop

    // 0x800700C4: jal         0x80061348
    // 0x800700C8: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800700C8: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800700CC: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800700D0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800700D4: beq         $v0, $zero, L_8007010C
    if (ctx->r2 == 0) {
        // 0x800700D8: nop

            goto L_8007010C;
    }
    // 0x800700D8: nop

    // 0x800700DC: jal         0x80061348
    // 0x800700E0: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800700E0: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800700E4: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800700E8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800700EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800700F0: beq         $v0, $zero, L_8007010C
    if (ctx->r2 == 0) {
        // 0x800700F4: nop

            goto L_8007010C;
    }
    // 0x800700F4: nop

    // 0x800700F8: jal         0x80061348
    // 0x800700FC: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800700FC: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070100: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070104: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070108: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007010C:
    // 0x8007010C: b           L_8007011C
    // 0x80070110: nop

        goto L_8007011C;
    // 0x80070110: nop

    // 0x80070114: b           L_8007011C
    // 0x80070118: nop

        goto L_8007011C;
    // 0x80070118: nop

L_8007011C:
    // 0x8007011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070124: jr          $ra
    // 0x80070128: nop

    return;
    // 0x80070128: nop

;}
RECOMP_FUNC void func_8007012C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007012C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070134: jal         0x80061348
    // 0x80070138: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070138: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x8007013C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070140: b           L_80070150
    // 0x80070144: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80070150;
    // 0x80070144: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070148: b           L_80070150
    // 0x8007014C: nop

        goto L_80070150;
    // 0x8007014C: nop

L_80070150:
    // 0x80070150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070158: jr          $ra
    // 0x8007015C: nop

    return;
    // 0x8007015C: nop

;}
RECOMP_FUNC void func_80070160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070168: jal         0x80061348
    // 0x8007016C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007016C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070170: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070174: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070178: beq         $v0, $zero, L_800701C8
    if (ctx->r2 == 0) {
        // 0x8007017C: nop

            goto L_800701C8;
    }
    // 0x8007017C: nop

    // 0x80070180: jal         0x80061348
    // 0x80070184: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070184: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070188: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007018C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070190: beq         $v0, $zero, L_800701C8
    if (ctx->r2 == 0) {
        // 0x80070194: nop

            goto L_800701C8;
    }
    // 0x80070194: nop

    // 0x80070198: jal         0x80061348
    // 0x8007019C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007019C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800701A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800701A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800701A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800701AC: beq         $v0, $zero, L_800701C8
    if (ctx->r2 == 0) {
        // 0x800701B0: nop

            goto L_800701C8;
    }
    // 0x800701B0: nop

    // 0x800701B4: jal         0x80061348
    // 0x800701B8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800701B8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x800701BC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800701C0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800701C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800701C8:
    // 0x800701C8: b           L_800701D8
    // 0x800701CC: nop

        goto L_800701D8;
    // 0x800701CC: nop

    // 0x800701D0: b           L_800701D8
    // 0x800701D4: nop

        goto L_800701D8;
    // 0x800701D4: nop

L_800701D8:
    // 0x800701D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800701DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800701E0: jr          $ra
    // 0x800701E4: nop

    return;
    // 0x800701E4: nop

;}
RECOMP_FUNC void func_800701E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800701E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800701EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800701F0: jal         0x80061348
    // 0x800701F4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800701F4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800701F8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800701FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070200: beq         $v0, $zero, L_80070250
    if (ctx->r2 == 0) {
        // 0x80070204: nop

            goto L_80070250;
    }
    // 0x80070204: nop

    // 0x80070208: jal         0x80061348
    // 0x8007020C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007020C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070210: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070214: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070218: beq         $v0, $zero, L_80070250
    if (ctx->r2 == 0) {
        // 0x8007021C: nop

            goto L_80070250;
    }
    // 0x8007021C: nop

    // 0x80070220: jal         0x80061348
    // 0x80070224: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070224: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070228: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007022C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070230: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070234: beq         $v0, $zero, L_80070250
    if (ctx->r2 == 0) {
        // 0x80070238: nop

            goto L_80070250;
    }
    // 0x80070238: nop

    // 0x8007023C: jal         0x80061348
    // 0x80070240: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070240: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070244: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070248: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007024C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070250:
    // 0x80070250: b           L_80070260
    // 0x80070254: nop

        goto L_80070260;
    // 0x80070254: nop

    // 0x80070258: b           L_80070260
    // 0x8007025C: nop

        goto L_80070260;
    // 0x8007025C: nop

L_80070260:
    // 0x80070260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070268: jr          $ra
    // 0x8007026C: nop

    return;
    // 0x8007026C: nop

;}
RECOMP_FUNC void func_80070270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070278: jal         0x80061488
    // 0x8007027C: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    func_80061488(rdram, ctx);
        goto after_0;
    // 0x8007027C: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    after_0:
    // 0x80070280: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80070284: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x80070288: b           L_80070298
    // 0x8007028C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80070298;
    // 0x8007028C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070290: b           L_80070298
    // 0x80070294: nop

        goto L_80070298;
    // 0x80070294: nop

L_80070298:
    // 0x80070298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007029C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800702A0: jr          $ra
    // 0x800702A4: nop

    return;
    // 0x800702A4: nop

;}
RECOMP_FUNC void func_800702A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800702A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800702AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800702B0: jal         0x80061348
    // 0x800702B4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800702B4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800702B8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800702BC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800702C0: beq         $v0, $zero, L_80070310
    if (ctx->r2 == 0) {
        // 0x800702C4: nop

            goto L_80070310;
    }
    // 0x800702C4: nop

    // 0x800702C8: jal         0x80061348
    // 0x800702CC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800702CC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800702D0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800702D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800702D8: beq         $v0, $zero, L_80070310
    if (ctx->r2 == 0) {
        // 0x800702DC: nop

            goto L_80070310;
    }
    // 0x800702DC: nop

    // 0x800702E0: jal         0x80061348
    // 0x800702E4: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800702E4: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800702E8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800702EC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800702F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800702F4: beq         $v0, $zero, L_80070310
    if (ctx->r2 == 0) {
        // 0x800702F8: nop

            goto L_80070310;
    }
    // 0x800702F8: nop

    // 0x800702FC: jal         0x80061348
    // 0x80070300: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070300: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070304: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070308: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007030C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070310:
    // 0x80070310: b           L_80070320
    // 0x80070314: nop

        goto L_80070320;
    // 0x80070314: nop

    // 0x80070318: b           L_80070320
    // 0x8007031C: nop

        goto L_80070320;
    // 0x8007031C: nop

L_80070320:
    // 0x80070320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070328: jr          $ra
    // 0x8007032C: nop

    return;
    // 0x8007032C: nop

;}
RECOMP_FUNC void func_80070330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070338: jal         0x80061348
    // 0x8007033C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007033C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070340: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070344: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070348: beq         $v0, $zero, L_80070398
    if (ctx->r2 == 0) {
        // 0x8007034C: nop

            goto L_80070398;
    }
    // 0x8007034C: nop

    // 0x80070350: jal         0x80061348
    // 0x80070354: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070354: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070358: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007035C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070360: beq         $v0, $zero, L_80070398
    if (ctx->r2 == 0) {
        // 0x80070364: nop

            goto L_80070398;
    }
    // 0x80070364: nop

    // 0x80070368: jal         0x80061348
    // 0x8007036C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007036C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070370: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070374: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070378: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007037C: beq         $v0, $zero, L_80070398
    if (ctx->r2 == 0) {
        // 0x80070380: nop

            goto L_80070398;
    }
    // 0x80070380: nop

    // 0x80070384: jal         0x80061348
    // 0x80070388: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070388: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x8007038C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070390: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070394: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070398:
    // 0x80070398: b           L_800703A8
    // 0x8007039C: nop

        goto L_800703A8;
    // 0x8007039C: nop

    // 0x800703A0: b           L_800703A8
    // 0x800703A4: nop

        goto L_800703A8;
    // 0x800703A4: nop

L_800703A8:
    // 0x800703A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800703AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800703B0: jr          $ra
    // 0x800703B4: nop

    return;
    // 0x800703B4: nop

;}
RECOMP_FUNC void func_800703B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800703B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800703BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800703C0: jal         0x80061348
    // 0x800703C4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800703C4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800703C8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800703CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800703D0: beq         $v0, $zero, L_80070420
    if (ctx->r2 == 0) {
        // 0x800703D4: nop

            goto L_80070420;
    }
    // 0x800703D4: nop

    // 0x800703D8: jal         0x80061348
    // 0x800703DC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800703DC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800703E0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800703E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800703E8: beq         $v0, $zero, L_80070420
    if (ctx->r2 == 0) {
        // 0x800703EC: nop

            goto L_80070420;
    }
    // 0x800703EC: nop

    // 0x800703F0: jal         0x80061348
    // 0x800703F4: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800703F4: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800703F8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800703FC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070400: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070404: beq         $v0, $zero, L_80070420
    if (ctx->r2 == 0) {
        // 0x80070408: nop

            goto L_80070420;
    }
    // 0x80070408: nop

    // 0x8007040C: jal         0x80061348
    // 0x80070410: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070410: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070414: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070418: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007041C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070420:
    // 0x80070420: b           L_80070430
    // 0x80070424: nop

        goto L_80070430;
    // 0x80070424: nop

    // 0x80070428: b           L_80070430
    // 0x8007042C: nop

        goto L_80070430;
    // 0x8007042C: nop

L_80070430:
    // 0x80070430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070438: jr          $ra
    // 0x8007043C: nop

    return;
    // 0x8007043C: nop

;}
RECOMP_FUNC void func_80070440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070448: jal         0x80061348
    // 0x8007044C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007044C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070450: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070454: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070458: beq         $v0, $zero, L_800704A8
    if (ctx->r2 == 0) {
        // 0x8007045C: nop

            goto L_800704A8;
    }
    // 0x8007045C: nop

    // 0x80070460: jal         0x80061348
    // 0x80070464: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070464: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070468: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007046C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070470: beq         $v0, $zero, L_800704A8
    if (ctx->r2 == 0) {
        // 0x80070474: nop

            goto L_800704A8;
    }
    // 0x80070474: nop

    // 0x80070478: jal         0x80061348
    // 0x8007047C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007047C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070480: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070484: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070488: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007048C: beq         $v0, $zero, L_800704A8
    if (ctx->r2 == 0) {
        // 0x80070490: nop

            goto L_800704A8;
    }
    // 0x80070490: nop

    // 0x80070494: jal         0x80061348
    // 0x80070498: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070498: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x8007049C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800704A0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800704A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800704A8:
    // 0x800704A8: b           L_800704B8
    // 0x800704AC: nop

        goto L_800704B8;
    // 0x800704AC: nop

    // 0x800704B0: b           L_800704B8
    // 0x800704B4: nop

        goto L_800704B8;
    // 0x800704B4: nop

L_800704B8:
    // 0x800704B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800704BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800704C0: jr          $ra
    // 0x800704C4: nop

    return;
    // 0x800704C4: nop

;}
RECOMP_FUNC void func_800704C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800704C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800704CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800704D0: jal         0x80061348
    // 0x800704D4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800704D4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800704D8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800704DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800704E0: beq         $v0, $zero, L_80070530
    if (ctx->r2 == 0) {
        // 0x800704E4: nop

            goto L_80070530;
    }
    // 0x800704E4: nop

    // 0x800704E8: jal         0x80061348
    // 0x800704EC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800704EC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800704F0: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800704F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800704F8: beq         $v0, $zero, L_80070530
    if (ctx->r2 == 0) {
        // 0x800704FC: nop

            goto L_80070530;
    }
    // 0x800704FC: nop

    // 0x80070500: jal         0x80061348
    // 0x80070504: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070504: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070508: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007050C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070510: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070514: beq         $v0, $zero, L_80070530
    if (ctx->r2 == 0) {
        // 0x80070518: nop

            goto L_80070530;
    }
    // 0x80070518: nop

    // 0x8007051C: jal         0x80061348
    // 0x80070520: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070520: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070524: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070528: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007052C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070530:
    // 0x80070530: b           L_80070540
    // 0x80070534: nop

        goto L_80070540;
    // 0x80070534: nop

    // 0x80070538: b           L_80070540
    // 0x8007053C: nop

        goto L_80070540;
    // 0x8007053C: nop

L_80070540:
    // 0x80070540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070544: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070548: jr          $ra
    // 0x8007054C: nop

    return;
    // 0x8007054C: nop

;}
RECOMP_FUNC void func_80070550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070558: jal         0x80061348
    // 0x8007055C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007055C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070560: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070564: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070568: beq         $v0, $zero, L_800705B8
    if (ctx->r2 == 0) {
        // 0x8007056C: nop

            goto L_800705B8;
    }
    // 0x8007056C: nop

    // 0x80070570: jal         0x80061348
    // 0x80070574: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070574: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070578: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007057C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070580: beq         $v0, $zero, L_800705B8
    if (ctx->r2 == 0) {
        // 0x80070584: nop

            goto L_800705B8;
    }
    // 0x80070584: nop

    // 0x80070588: jal         0x80061348
    // 0x8007058C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007058C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070590: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070594: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070598: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007059C: beq         $v0, $zero, L_800705B8
    if (ctx->r2 == 0) {
        // 0x800705A0: nop

            goto L_800705B8;
    }
    // 0x800705A0: nop

    // 0x800705A4: jal         0x80061348
    // 0x800705A8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800705A8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x800705AC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800705B0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800705B4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800705B8:
    // 0x800705B8: b           L_800705C8
    // 0x800705BC: nop

        goto L_800705C8;
    // 0x800705BC: nop

    // 0x800705C0: b           L_800705C8
    // 0x800705C4: nop

        goto L_800705C8;
    // 0x800705C4: nop

L_800705C8:
    // 0x800705C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800705CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800705D0: jr          $ra
    // 0x800705D4: nop

    return;
    // 0x800705D4: nop

;}
RECOMP_FUNC void func_800705D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800705D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800705DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800705E0: jal         0x80061348
    // 0x800705E4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800705E4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800705E8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800705EC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800705F0: beq         $v0, $zero, L_80070640
    if (ctx->r2 == 0) {
        // 0x800705F4: nop

            goto L_80070640;
    }
    // 0x800705F4: nop

    // 0x800705F8: jal         0x80061348
    // 0x800705FC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800705FC: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070600: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070604: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070608: beq         $v0, $zero, L_80070640
    if (ctx->r2 == 0) {
        // 0x8007060C: nop

            goto L_80070640;
    }
    // 0x8007060C: nop

    // 0x80070610: jal         0x80061348
    // 0x80070614: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070614: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070618: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007061C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070620: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070624: beq         $v0, $zero, L_80070640
    if (ctx->r2 == 0) {
        // 0x80070628: nop

            goto L_80070640;
    }
    // 0x80070628: nop

    // 0x8007062C: jal         0x80061348
    // 0x80070630: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070630: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070634: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070638: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007063C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070640:
    // 0x80070640: b           L_80070650
    // 0x80070644: nop

        goto L_80070650;
    // 0x80070644: nop

    // 0x80070648: b           L_80070650
    // 0x8007064C: nop

        goto L_80070650;
    // 0x8007064C: nop

L_80070650:
    // 0x80070650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070658: jr          $ra
    // 0x8007065C: nop

    return;
    // 0x8007065C: nop

;}
RECOMP_FUNC void func_80070660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070668: jal         0x80061348
    // 0x8007066C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007066C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070670: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070674: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070678: beq         $v0, $zero, L_800706C8
    if (ctx->r2 == 0) {
        // 0x8007067C: nop

            goto L_800706C8;
    }
    // 0x8007067C: nop

    // 0x80070680: jal         0x80061348
    // 0x80070684: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070684: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070688: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007068C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070690: beq         $v0, $zero, L_800706C8
    if (ctx->r2 == 0) {
        // 0x80070694: nop

            goto L_800706C8;
    }
    // 0x80070694: nop

    // 0x80070698: jal         0x80061348
    // 0x8007069C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007069C: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800706A0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800706A4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800706A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800706AC: beq         $v0, $zero, L_800706C8
    if (ctx->r2 == 0) {
        // 0x800706B0: nop

            goto L_800706C8;
    }
    // 0x800706B0: nop

    // 0x800706B4: jal         0x80061348
    // 0x800706B8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800706B8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x800706BC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800706C0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800706C4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800706C8:
    // 0x800706C8: b           L_800706D8
    // 0x800706CC: nop

        goto L_800706D8;
    // 0x800706CC: nop

    // 0x800706D0: b           L_800706D8
    // 0x800706D4: nop

        goto L_800706D8;
    // 0x800706D4: nop

L_800706D8:
    // 0x800706D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800706DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800706E0: jr          $ra
    // 0x800706E4: nop

    return;
    // 0x800706E4: nop

;}
RECOMP_FUNC void func_800706E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800706E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800706EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800706F0: jal         0x80061348
    // 0x800706F4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800706F4: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x800706F8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800706FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070700: beq         $v0, $zero, L_80070750
    if (ctx->r2 == 0) {
        // 0x80070704: nop

            goto L_80070750;
    }
    // 0x80070704: nop

    // 0x80070708: jal         0x80061348
    // 0x8007070C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007070C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070710: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070714: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070718: beq         $v0, $zero, L_80070750
    if (ctx->r2 == 0) {
        // 0x8007071C: nop

            goto L_80070750;
    }
    // 0x8007071C: nop

    // 0x80070720: jal         0x80061348
    // 0x80070724: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070724: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070728: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007072C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070730: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070734: beq         $v0, $zero, L_80070750
    if (ctx->r2 == 0) {
        // 0x80070738: nop

            goto L_80070750;
    }
    // 0x80070738: nop

    // 0x8007073C: jal         0x80061348
    // 0x80070740: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070740: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070744: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070748: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007074C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070750:
    // 0x80070750: b           L_80070760
    // 0x80070754: nop

        goto L_80070760;
    // 0x80070754: nop

    // 0x80070758: b           L_80070760
    // 0x8007075C: nop

        goto L_80070760;
    // 0x8007075C: nop

L_80070760:
    // 0x80070760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070768: jr          $ra
    // 0x8007076C: nop

    return;
    // 0x8007076C: nop

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
RECOMP_FUNC void func_800707F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800707F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800707FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070800: jal         0x80061348
    // 0x80070804: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070804: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070808: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8007080C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070810: beq         $v0, $zero, L_80070860
    if (ctx->r2 == 0) {
        // 0x80070814: nop

            goto L_80070860;
    }
    // 0x80070814: nop

    // 0x80070818: jal         0x80061348
    // 0x8007081C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x8007081C: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x80070820: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070824: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070828: beq         $v0, $zero, L_80070860
    if (ctx->r2 == 0) {
        // 0x8007082C: nop

            goto L_80070860;
    }
    // 0x8007082C: nop

    // 0x80070830: jal         0x80061348
    // 0x80070834: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070834: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x80070838: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007083C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070840: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070844: beq         $v0, $zero, L_80070860
    if (ctx->r2 == 0) {
        // 0x80070848: nop

            goto L_80070860;
    }
    // 0x80070848: nop

    // 0x8007084C: jal         0x80061348
    // 0x80070850: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070850: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x80070854: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070858: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007085C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070860:
    // 0x80070860: b           L_80070870
    // 0x80070864: nop

        goto L_80070870;
    // 0x80070864: nop

    // 0x80070868: b           L_80070870
    // 0x8007086C: nop

        goto L_80070870;
    // 0x8007086C: nop

L_80070870:
    // 0x80070870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070878: jr          $ra
    // 0x8007087C: nop

    return;
    // 0x8007087C: nop

;}
RECOMP_FUNC void func_80070880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070888: jal         0x80061348
    // 0x8007088C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007088C: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_0:
    // 0x80070890: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80070894: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070898: beq         $v0, $zero, L_800708E8
    if (ctx->r2 == 0) {
        // 0x8007089C: nop

            goto L_800708E8;
    }
    // 0x8007089C: nop

    // 0x800708A0: jal         0x80061348
    // 0x800708A4: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800708A4: addiu       $a0, $zero, 0x425
    ctx->r4 = ADD32(0, 0X425);
    after_1:
    // 0x800708A8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800708AC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800708B0: beq         $v0, $zero, L_800708E8
    if (ctx->r2 == 0) {
        // 0x800708B4: nop

            goto L_800708E8;
    }
    // 0x800708B4: nop

    // 0x800708B8: jal         0x80061348
    // 0x800708BC: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800708BC: addiu       $a0, $zero, 0x41B
    ctx->r4 = ADD32(0, 0X41B);
    after_2:
    // 0x800708C0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800708C4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800708C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800708CC: beq         $v0, $zero, L_800708E8
    if (ctx->r2 == 0) {
        // 0x800708D0: nop

            goto L_800708E8;
    }
    // 0x800708D0: nop

    // 0x800708D4: jal         0x80061348
    // 0x800708D8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800708D8: addiu       $a0, $zero, 0x427
    ctx->r4 = ADD32(0, 0X427);
    after_3:
    // 0x800708DC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800708E0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800708E4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800708E8:
    // 0x800708E8: b           L_800708F8
    // 0x800708EC: nop

        goto L_800708F8;
    // 0x800708EC: nop

    // 0x800708F0: b           L_800708F8
    // 0x800708F4: nop

        goto L_800708F8;
    // 0x800708F4: nop

L_800708F8:
    // 0x800708F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800708FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070900: jr          $ra
    // 0x80070904: nop

    return;
    // 0x80070904: nop

;}
RECOMP_FUNC void func_80070908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007090C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070910: jal         0x80061348
    // 0x80070914: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070914: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x80070918: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8007091C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070920: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070924: beq         $v0, $zero, L_80070978
    if (ctx->r2 == 0) {
        // 0x80070928: nop

            goto L_80070978;
    }
    // 0x80070928: nop

    // 0x8007092C: jal         0x80061348
    // 0x80070930: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070930: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_1:
    // 0x80070934: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070938: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x8007093C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070940: beq         $v0, $zero, L_80070978
    if (ctx->r2 == 0) {
        // 0x80070944: nop

            goto L_80070978;
    }
    // 0x80070944: nop

    // 0x80070948: jal         0x80061348
    // 0x8007094C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x8007094C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070950: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070954: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070958: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8007095C: beq         $v0, $zero, L_80070978
    if (ctx->r2 == 0) {
        // 0x80070960: nop

            goto L_80070978;
    }
    // 0x80070960: nop

    // 0x80070964: jal         0x80061348
    // 0x80070968: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070968: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x8007096C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070970: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070974: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070978:
    // 0x80070978: b           L_80070988
    // 0x8007097C: nop

        goto L_80070988;
    // 0x8007097C: nop

    // 0x80070980: b           L_80070988
    // 0x80070984: nop

        goto L_80070988;
    // 0x80070984: nop

L_80070988:
    // 0x80070988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007098C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070990: jr          $ra
    // 0x80070994: nop

    return;
    // 0x80070994: nop

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
RECOMP_FUNC void func_80070A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070A30: jal         0x80061348
    // 0x80070A34: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070A34: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x80070A38: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070A3C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070A40: b           L_80070A50
    // 0x80070A44: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80070A50;
    // 0x80070A44: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070A48: b           L_80070A50
    // 0x80070A4C: nop

        goto L_80070A50;
    // 0x80070A4C: nop

L_80070A50:
    // 0x80070A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070A58: jr          $ra
    // 0x80070A5C: nop

    return;
    // 0x80070A5C: nop

;}
RECOMP_FUNC void func_80070A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070A68: jal         0x80061348
    // 0x80070A6C: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070A6C: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x80070A70: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070A74: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070A78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070A7C: beq         $v0, $zero, L_80070AD0
    if (ctx->r2 == 0) {
        // 0x80070A80: nop

            goto L_80070AD0;
    }
    // 0x80070A80: nop

    // 0x80070A84: jal         0x80061348
    // 0x80070A88: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070A88: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_1:
    // 0x80070A8C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070A90: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070A94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070A98: beq         $v0, $zero, L_80070AD0
    if (ctx->r2 == 0) {
        // 0x80070A9C: nop

            goto L_80070AD0;
    }
    // 0x80070A9C: nop

    // 0x80070AA0: jal         0x80061348
    // 0x80070AA4: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070AA4: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070AA8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070AAC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070AB0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070AB4: beq         $v0, $zero, L_80070AD0
    if (ctx->r2 == 0) {
        // 0x80070AB8: nop

            goto L_80070AD0;
    }
    // 0x80070AB8: nop

    // 0x80070ABC: jal         0x80061348
    // 0x80070AC0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070AC0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070AC4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070AC8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070ACC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070AD0:
    // 0x80070AD0: b           L_80070AE0
    // 0x80070AD4: nop

        goto L_80070AE0;
    // 0x80070AD4: nop

    // 0x80070AD8: b           L_80070AE0
    // 0x80070ADC: nop

        goto L_80070AE0;
    // 0x80070ADC: nop

L_80070AE0:
    // 0x80070AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070AE8: jr          $ra
    // 0x80070AEC: nop

    return;
    // 0x80070AEC: nop

;}
RECOMP_FUNC void func_80070AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070AF8: jal         0x80061348
    // 0x80070AFC: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070AFC: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x80070B00: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070B04: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070B08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070B0C: beq         $v0, $zero, L_80070B60
    if (ctx->r2 == 0) {
        // 0x80070B10: nop

            goto L_80070B60;
    }
    // 0x80070B10: nop

    // 0x80070B14: jal         0x80061348
    // 0x80070B18: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070B18: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_1:
    // 0x80070B1C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070B20: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070B24: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070B28: beq         $v0, $zero, L_80070B60
    if (ctx->r2 == 0) {
        // 0x80070B2C: nop

            goto L_80070B60;
    }
    // 0x80070B2C: nop

    // 0x80070B30: jal         0x80061348
    // 0x80070B34: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070B34: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070B38: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070B3C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070B40: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070B44: beq         $v0, $zero, L_80070B60
    if (ctx->r2 == 0) {
        // 0x80070B48: nop

            goto L_80070B60;
    }
    // 0x80070B48: nop

    // 0x80070B4C: jal         0x80061348
    // 0x80070B50: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070B50: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070B54: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070B58: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070B5C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070B60:
    // 0x80070B60: b           L_80070B70
    // 0x80070B64: nop

        goto L_80070B70;
    // 0x80070B64: nop

    // 0x80070B68: b           L_80070B70
    // 0x80070B6C: nop

        goto L_80070B70;
    // 0x80070B6C: nop

L_80070B70:
    // 0x80070B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070B78: jr          $ra
    // 0x80070B7C: nop

    return;
    // 0x80070B7C: nop

;}
RECOMP_FUNC void func_80070B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070B80: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80070B84: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80070B88: nop

    // 0x80070B8C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80070B90: nop

    // 0x80070B94: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80070B98: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80070B9C: jr          $ra
    // 0x80070BA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80070BA0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070BA4: jr          $ra
    // 0x80070BA8: nop

    return;
    // 0x80070BA8: nop

    // 0x80070BAC: jr          $ra
    // 0x80070BB0: nop

    return;
    // 0x80070BB0: nop

;}
RECOMP_FUNC void func_80070BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070BB4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80070BB8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80070BBC: nop

    // 0x80070BC0: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80070BC4: nop

    // 0x80070BC8: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80070BCC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80070BD0: jr          $ra
    // 0x80070BD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80070BD4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070BD8: jr          $ra
    // 0x80070BDC: nop

    return;
    // 0x80070BDC: nop

    // 0x80070BE0: jr          $ra
    // 0x80070BE4: nop

    return;
    // 0x80070BE4: nop

;}
RECOMP_FUNC void func_80070BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070BF0: jal         0x80061348
    // 0x80070BF4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070BF4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_0:
    // 0x80070BF8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070BFC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070C00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070C04: beq         $v0, $zero, L_80070C58
    if (ctx->r2 == 0) {
        // 0x80070C08: nop

            goto L_80070C58;
    }
    // 0x80070C08: nop

    // 0x80070C0C: jal         0x80061348
    // 0x80070C10: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070C10: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070C14: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070C18: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070C1C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070C20: beq         $v0, $zero, L_80070C58
    if (ctx->r2 == 0) {
        // 0x80070C24: nop

            goto L_80070C58;
    }
    // 0x80070C24: nop

    // 0x80070C28: jal         0x80061348
    // 0x80070C2C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070C2C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070C30: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070C34: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070C38: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070C3C: beq         $v0, $zero, L_80070C58
    if (ctx->r2 == 0) {
        // 0x80070C40: nop

            goto L_80070C58;
    }
    // 0x80070C40: nop

    // 0x80070C44: jal         0x80061348
    // 0x80070C48: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070C48: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070C4C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070C50: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070C54: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070C58:
    // 0x80070C58: b           L_80070C68
    // 0x80070C5C: nop

        goto L_80070C68;
    // 0x80070C5C: nop

    // 0x80070C60: b           L_80070C68
    // 0x80070C64: nop

        goto L_80070C68;
    // 0x80070C64: nop

L_80070C68:
    // 0x80070C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070C6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070C70: jr          $ra
    // 0x80070C74: nop

    return;
    // 0x80070C74: nop

;}
RECOMP_FUNC void func_80070C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070C80: jal         0x80061348
    // 0x80070C84: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070C84: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_0:
    // 0x80070C88: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070C8C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070C90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070C94: beq         $v0, $zero, L_80070CE8
    if (ctx->r2 == 0) {
        // 0x80070C98: nop

            goto L_80070CE8;
    }
    // 0x80070C98: nop

    // 0x80070C9C: jal         0x80061348
    // 0x80070CA0: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070CA0: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070CA4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070CA8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070CAC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070CB0: beq         $v0, $zero, L_80070CE8
    if (ctx->r2 == 0) {
        // 0x80070CB4: nop

            goto L_80070CE8;
    }
    // 0x80070CB4: nop

    // 0x80070CB8: jal         0x80061348
    // 0x80070CBC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070CBC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070CC0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070CC4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070CC8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070CCC: beq         $v0, $zero, L_80070CE8
    if (ctx->r2 == 0) {
        // 0x80070CD0: nop

            goto L_80070CE8;
    }
    // 0x80070CD0: nop

    // 0x80070CD4: jal         0x80061348
    // 0x80070CD8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070CD8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070CDC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070CE0: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070CE4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070CE8:
    // 0x80070CE8: b           L_80070CF8
    // 0x80070CEC: nop

        goto L_80070CF8;
    // 0x80070CEC: nop

    // 0x80070CF0: b           L_80070CF8
    // 0x80070CF4: nop

        goto L_80070CF8;
    // 0x80070CF4: nop

L_80070CF8:
    // 0x80070CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070D00: jr          $ra
    // 0x80070D04: nop

    return;
    // 0x80070D04: nop

;}
RECOMP_FUNC void func_80070D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070D10: jal         0x80061348
    // 0x80070D14: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070D14: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_0:
    // 0x80070D18: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070D1C: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070D20: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070D24: beq         $v0, $zero, L_80070D78
    if (ctx->r2 == 0) {
        // 0x80070D28: nop

            goto L_80070D78;
    }
    // 0x80070D28: nop

    // 0x80070D2C: jal         0x80061348
    // 0x80070D30: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070D30: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070D34: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070D38: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070D3C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070D40: beq         $v0, $zero, L_80070D78
    if (ctx->r2 == 0) {
        // 0x80070D44: nop

            goto L_80070D78;
    }
    // 0x80070D44: nop

    // 0x80070D48: jal         0x80061348
    // 0x80070D4C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070D4C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070D50: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070D54: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070D58: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070D5C: beq         $v0, $zero, L_80070D78
    if (ctx->r2 == 0) {
        // 0x80070D60: nop

            goto L_80070D78;
    }
    // 0x80070D60: nop

    // 0x80070D64: jal         0x80061348
    // 0x80070D68: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070D68: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070D6C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070D70: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070D74: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070D78:
    // 0x80070D78: b           L_80070D88
    // 0x80070D7C: nop

        goto L_80070D88;
    // 0x80070D7C: nop

    // 0x80070D80: b           L_80070D88
    // 0x80070D84: nop

        goto L_80070D88;
    // 0x80070D84: nop

L_80070D88:
    // 0x80070D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070D90: jr          $ra
    // 0x80070D94: nop

    return;
    // 0x80070D94: nop

;}
RECOMP_FUNC void func_80070D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070DA0: jal         0x80061348
    // 0x80070DA4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070DA4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_0:
    // 0x80070DA8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070DAC: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070DB0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070DB4: beq         $v0, $zero, L_80070E08
    if (ctx->r2 == 0) {
        // 0x80070DB8: nop

            goto L_80070E08;
    }
    // 0x80070DB8: nop

    // 0x80070DBC: jal         0x80061348
    // 0x80070DC0: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070DC0: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070DC4: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070DC8: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070DCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070DD0: beq         $v0, $zero, L_80070E08
    if (ctx->r2 == 0) {
        // 0x80070DD4: nop

            goto L_80070E08;
    }
    // 0x80070DD4: nop

    // 0x80070DD8: jal         0x80061348
    // 0x80070DDC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070DDC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80070DE0: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070DE4: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070DE8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070DEC: beq         $v0, $zero, L_80070E08
    if (ctx->r2 == 0) {
        // 0x80070DF0: nop

            goto L_80070E08;
    }
    // 0x80070DF0: nop

    // 0x80070DF4: jal         0x80061348
    // 0x80070DF8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070DF8: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070DFC: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070E00: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070E04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070E08:
    // 0x80070E08: b           L_80070E18
    // 0x80070E0C: nop

        goto L_80070E18;
    // 0x80070E0C: nop

    // 0x80070E10: b           L_80070E18
    // 0x80070E14: nop

        goto L_80070E18;
    // 0x80070E14: nop

L_80070E18:
    // 0x80070E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070E20: jr          $ra
    // 0x80070E24: nop

    return;
    // 0x80070E24: nop

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
RECOMP_FUNC void func_80070E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070E7C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80070E80: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80070E84: nop

    // 0x80070E88: lh          $v0, 0xE($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XE);
    // 0x80070E8C: nop

    // 0x80070E90: slti        $t7, $v0, 0x1F4
    ctx->r15 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80070E94: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x80070E98: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070E9C: beq         $v0, $zero, L_80070EB8
    if (ctx->r2 == 0) {
        // 0x80070EA0: nop

            goto L_80070EB8;
    }
    // 0x80070EA0: nop

    // 0x80070EA4: lh          $v0, 0x1E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1E);
    // 0x80070EA8: nop

    // 0x80070EAC: slti        $t8, $v0, 0x1F4
    ctx->r24 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80070EB0: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80070EB4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80070EB8:
    // 0x80070EB8: jr          $ra
    // 0x80070EBC: nop

    return;
    // 0x80070EBC: nop

    // 0x80070EC0: jr          $ra
    // 0x80070EC4: nop

    return;
    // 0x80070EC4: nop

    // 0x80070EC8: jr          $ra
    // 0x80070ECC: nop

    return;
    // 0x80070ECC: nop

;}
RECOMP_FUNC void func_80070ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070ED8: jal         0x80061348
    // 0x80070EDC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070EDC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_0:
    // 0x80070EE0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070EE4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070EE8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070EEC: beq         $v0, $zero, L_80070F40
    if (ctx->r2 == 0) {
        // 0x80070EF0: nop

            goto L_80070F40;
    }
    // 0x80070EF0: nop

    // 0x80070EF4: jal         0x80061348
    // 0x80070EF8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070EF8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070EFC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070F00: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070F04: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070F08: beq         $v0, $zero, L_80070F40
    if (ctx->r2 == 0) {
        // 0x80070F0C: nop

            goto L_80070F40;
    }
    // 0x80070F0C: nop

    // 0x80070F10: jal         0x80061348
    // 0x80070F14: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070F14: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_2:
    // 0x80070F18: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070F1C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070F20: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070F24: beq         $v0, $zero, L_80070F40
    if (ctx->r2 == 0) {
        // 0x80070F28: nop

            goto L_80070F40;
    }
    // 0x80070F28: nop

    // 0x80070F2C: jal         0x80061348
    // 0x80070F30: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070F30: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070F34: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070F38: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070F3C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070F40:
    // 0x80070F40: b           L_80070F50
    // 0x80070F44: nop

        goto L_80070F50;
    // 0x80070F44: nop

    // 0x80070F48: b           L_80070F50
    // 0x80070F4C: nop

        goto L_80070F50;
    // 0x80070F4C: nop

L_80070F50:
    // 0x80070F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070F58: jr          $ra
    // 0x80070F5C: nop

    return;
    // 0x80070F5C: nop

;}
RECOMP_FUNC void func_80070F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070F68: jal         0x80061348
    // 0x80070F6C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070F6C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_0:
    // 0x80070F70: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80070F74: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80070F78: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80070F7C: beq         $v0, $zero, L_80070FD0
    if (ctx->r2 == 0) {
        // 0x80070F80: nop

            goto L_80070FD0;
    }
    // 0x80070F80: nop

    // 0x80070F84: jal         0x80061348
    // 0x80070F88: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80070F88: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x80070F8C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80070F90: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80070F94: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80070F98: beq         $v0, $zero, L_80070FD0
    if (ctx->r2 == 0) {
        // 0x80070F9C: nop

            goto L_80070FD0;
    }
    // 0x80070F9C: nop

    // 0x80070FA0: jal         0x80061348
    // 0x80070FA4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80070FA4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_2:
    // 0x80070FA8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80070FAC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80070FB0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80070FB4: beq         $v0, $zero, L_80070FD0
    if (ctx->r2 == 0) {
        // 0x80070FB8: nop

            goto L_80070FD0;
    }
    // 0x80070FB8: nop

    // 0x80070FBC: jal         0x80061348
    // 0x80070FC0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80070FC0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80070FC4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80070FC8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80070FCC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80070FD0:
    // 0x80070FD0: b           L_80070FE0
    // 0x80070FD4: nop

        goto L_80070FE0;
    // 0x80070FD4: nop

    // 0x80070FD8: b           L_80070FE0
    // 0x80070FDC: nop

        goto L_80070FE0;
    // 0x80070FDC: nop

L_80070FE0:
    // 0x80070FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070FE8: jr          $ra
    // 0x80070FEC: nop

    return;
    // 0x80070FEC: nop

;}
RECOMP_FUNC void func_80070FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070FF8: jal         0x80061348
    // 0x80070FFC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80070FFC: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_0:
    // 0x80071000: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071004: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071008: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007100C: beq         $v0, $zero, L_80071060
    if (ctx->r2 == 0) {
        // 0x80071010: nop

            goto L_80071060;
    }
    // 0x80071010: nop

    // 0x80071014: jal         0x80061348
    // 0x80071018: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071018: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x8007101C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071020: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071024: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071028: beq         $v0, $zero, L_80071060
    if (ctx->r2 == 0) {
        // 0x8007102C: nop

            goto L_80071060;
    }
    // 0x8007102C: nop

    // 0x80071030: jal         0x80061348
    // 0x80071034: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071034: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_2:
    // 0x80071038: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007103C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071040: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071044: beq         $v0, $zero, L_80071060
    if (ctx->r2 == 0) {
        // 0x80071048: nop

            goto L_80071060;
    }
    // 0x80071048: nop

    // 0x8007104C: jal         0x80061348
    // 0x80071050: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071050: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x80071054: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071058: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007105C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071060:
    // 0x80071060: b           L_80071070
    // 0x80071064: nop

        goto L_80071070;
    // 0x80071064: nop

    // 0x80071068: b           L_80071070
    // 0x8007106C: nop

        goto L_80071070;
    // 0x8007106C: nop

L_80071070:
    // 0x80071070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071078: jr          $ra
    // 0x8007107C: nop

    return;
    // 0x8007107C: nop

;}
RECOMP_FUNC void func_80071080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071088: jal         0x80061348
    // 0x8007108C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007108C: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_0:
    // 0x80071090: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071094: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071098: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007109C: beq         $v0, $zero, L_800710F0
    if (ctx->r2 == 0) {
        // 0x800710A0: nop

            goto L_800710F0;
    }
    // 0x800710A0: nop

    // 0x800710A4: jal         0x80061348
    // 0x800710A8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800710A8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x800710AC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800710B0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800710B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800710B8: beq         $v0, $zero, L_800710F0
    if (ctx->r2 == 0) {
        // 0x800710BC: nop

            goto L_800710F0;
    }
    // 0x800710BC: nop

    // 0x800710C0: jal         0x80061348
    // 0x800710C4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800710C4: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_2:
    // 0x800710C8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800710CC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800710D0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800710D4: beq         $v0, $zero, L_800710F0
    if (ctx->r2 == 0) {
        // 0x800710D8: nop

            goto L_800710F0;
    }
    // 0x800710D8: nop

    // 0x800710DC: jal         0x80061348
    // 0x800710E0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800710E0: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_3:
    // 0x800710E4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800710E8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800710EC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800710F0:
    // 0x800710F0: b           L_80071100
    // 0x800710F4: nop

        goto L_80071100;
    // 0x800710F4: nop

    // 0x800710F8: b           L_80071100
    // 0x800710FC: nop

        goto L_80071100;
    // 0x800710FC: nop

L_80071100:
    // 0x80071100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071108: jr          $ra
    // 0x8007110C: nop

    return;
    // 0x8007110C: nop

;}
RECOMP_FUNC void func_80071110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071118: jal         0x80061348
    // 0x8007111C: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007111C: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_0:
    // 0x80071120: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071124: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071128: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007112C: beq         $v0, $zero, L_80071180
    if (ctx->r2 == 0) {
        // 0x80071130: nop

            goto L_80071180;
    }
    // 0x80071130: nop

    // 0x80071134: jal         0x80061348
    // 0x80071138: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071138: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x8007113C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071140: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071144: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071148: beq         $v0, $zero, L_80071180
    if (ctx->r2 == 0) {
        // 0x8007114C: nop

            goto L_80071180;
    }
    // 0x8007114C: nop

    // 0x80071150: jal         0x80061348
    // 0x80071154: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071154: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80071158: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007115C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071160: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071164: beq         $v0, $zero, L_80071180
    if (ctx->r2 == 0) {
        // 0x80071168: nop

            goto L_80071180;
    }
    // 0x80071168: nop

    // 0x8007116C: jal         0x80061348
    // 0x80071170: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071170: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_3:
    // 0x80071174: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071178: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007117C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071180:
    // 0x80071180: b           L_80071190
    // 0x80071184: nop

        goto L_80071190;
    // 0x80071184: nop

    // 0x80071188: b           L_80071190
    // 0x8007118C: nop

        goto L_80071190;
    // 0x8007118C: nop

L_80071190:
    // 0x80071190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071198: jr          $ra
    // 0x8007119C: nop

    return;
    // 0x8007119C: nop

;}
RECOMP_FUNC void func_800711A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800711A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800711A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800711A8: jal         0x80061348
    // 0x800711AC: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800711AC: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_0:
    // 0x800711B0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800711B4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800711B8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800711BC: beq         $v0, $zero, L_80071210
    if (ctx->r2 == 0) {
        // 0x800711C0: nop

            goto L_80071210;
    }
    // 0x800711C0: nop

    // 0x800711C4: jal         0x80061348
    // 0x800711C8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800711C8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x800711CC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800711D0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800711D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800711D8: beq         $v0, $zero, L_80071210
    if (ctx->r2 == 0) {
        // 0x800711DC: nop

            goto L_80071210;
    }
    // 0x800711DC: nop

    // 0x800711E0: jal         0x80061348
    // 0x800711E4: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x800711E4: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x800711E8: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x800711EC: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800711F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800711F4: beq         $v0, $zero, L_80071210
    if (ctx->r2 == 0) {
        // 0x800711F8: nop

            goto L_80071210;
    }
    // 0x800711F8: nop

    // 0x800711FC: jal         0x80061348
    // 0x80071200: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071200: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_3:
    // 0x80071204: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071208: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007120C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071210:
    // 0x80071210: b           L_80071220
    // 0x80071214: nop

        goto L_80071220;
    // 0x80071214: nop

    // 0x80071218: b           L_80071220
    // 0x8007121C: nop

        goto L_80071220;
    // 0x8007121C: nop

L_80071220:
    // 0x80071220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071228: jr          $ra
    // 0x8007122C: nop

    return;
    // 0x8007122C: nop

;}
RECOMP_FUNC void func_80071230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071238: jal         0x80061348
    // 0x8007123C: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007123C: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_0:
    // 0x80071240: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071244: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071248: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007124C: beq         $v0, $zero, L_800712A0
    if (ctx->r2 == 0) {
        // 0x80071250: nop

            goto L_800712A0;
    }
    // 0x80071250: nop

    // 0x80071254: jal         0x80061348
    // 0x80071258: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071258: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x8007125C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071260: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071264: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071268: beq         $v0, $zero, L_800712A0
    if (ctx->r2 == 0) {
        // 0x8007126C: nop

            goto L_800712A0;
    }
    // 0x8007126C: nop

    // 0x80071270: jal         0x80061348
    // 0x80071274: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071274: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80071278: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007127C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071280: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071284: beq         $v0, $zero, L_800712A0
    if (ctx->r2 == 0) {
        // 0x80071288: nop

            goto L_800712A0;
    }
    // 0x80071288: nop

    // 0x8007128C: jal         0x80061348
    // 0x80071290: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071290: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_3:
    // 0x80071294: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071298: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007129C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800712A0:
    // 0x800712A0: b           L_800712B0
    // 0x800712A4: nop

        goto L_800712B0;
    // 0x800712A4: nop

    // 0x800712A8: b           L_800712B0
    // 0x800712AC: nop

        goto L_800712B0;
    // 0x800712AC: nop

L_800712B0:
    // 0x800712B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800712B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800712B8: jr          $ra
    // 0x800712BC: nop

    return;
    // 0x800712BC: nop

;}
RECOMP_FUNC void func_800712C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800712C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800712C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800712C8: jal         0x80061348
    // 0x800712CC: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800712CC: addiu       $a0, $zero, 0x4B9
    ctx->r4 = ADD32(0, 0X4B9);
    after_0:
    // 0x800712D0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800712D4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800712D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800712DC: beq         $v0, $zero, L_80071330
    if (ctx->r2 == 0) {
        // 0x800712E0: nop

            goto L_80071330;
    }
    // 0x800712E0: nop

    // 0x800712E4: jal         0x80061348
    // 0x800712E8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x800712E8: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_1:
    // 0x800712EC: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800712F0: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800712F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800712F8: beq         $v0, $zero, L_80071330
    if (ctx->r2 == 0) {
        // 0x800712FC: nop

            goto L_80071330;
    }
    // 0x800712FC: nop

    // 0x80071300: jal         0x80061348
    // 0x80071304: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071304: addiu       $a0, $zero, 0x42E
    ctx->r4 = ADD32(0, 0X42E);
    after_2:
    // 0x80071308: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007130C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071310: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071314: beq         $v0, $zero, L_80071330
    if (ctx->r2 == 0) {
        // 0x80071318: nop

            goto L_80071330;
    }
    // 0x80071318: nop

    // 0x8007131C: jal         0x80061348
    // 0x80071320: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071320: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    after_3:
    // 0x80071324: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071328: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007132C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071330:
    // 0x80071330: b           L_80071340
    // 0x80071334: nop

        goto L_80071340;
    // 0x80071334: nop

    // 0x80071338: b           L_80071340
    // 0x8007133C: nop

        goto L_80071340;
    // 0x8007133C: nop

L_80071340:
    // 0x80071340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071348: jr          $ra
    // 0x8007134C: nop

    return;
    // 0x8007134C: nop

;}
RECOMP_FUNC void func_80071350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071358: jal         0x80061348
    // 0x8007135C: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x8007135C: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x80071360: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80071364: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80071368: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8007136C: beq         $v0, $zero, L_800713C0
    if (ctx->r2 == 0) {
        // 0x80071370: nop

            goto L_800713C0;
    }
    // 0x80071370: nop

    // 0x80071374: jal         0x80061348
    // 0x80071378: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071378: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x8007137C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071380: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071384: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071388: beq         $v0, $zero, L_800713C0
    if (ctx->r2 == 0) {
        // 0x8007138C: nop

            goto L_800713C0;
    }
    // 0x8007138C: nop

    // 0x80071390: jal         0x80061348
    // 0x80071394: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071394: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x80071398: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007139C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800713A0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800713A4: beq         $v0, $zero, L_800713C0
    if (ctx->r2 == 0) {
        // 0x800713A8: nop

            goto L_800713C0;
    }
    // 0x800713A8: nop

    // 0x800713AC: jal         0x80061348
    // 0x800713B0: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x800713B0: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x800713B4: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x800713B8: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800713BC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800713C0:
    // 0x800713C0: b           L_800713D0
    // 0x800713C4: nop

        goto L_800713D0;
    // 0x800713C4: nop

    // 0x800713C8: b           L_800713D0
    // 0x800713CC: nop

        goto L_800713D0;
    // 0x800713CC: nop

L_800713D0:
    // 0x800713D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800713D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800713D8: jr          $ra
    // 0x800713DC: nop

    return;
    // 0x800713DC: nop

;}
RECOMP_FUNC void func_800713E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800713E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800713E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800713E8: jal         0x80061348
    // 0x800713EC: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x800713EC: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_0:
    // 0x800713F0: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800713F4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800713F8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800713FC: beq         $v0, $zero, L_80071450
    if (ctx->r2 == 0) {
        // 0x80071400: nop

            goto L_80071450;
    }
    // 0x80071400: nop

    // 0x80071404: jal         0x80061348
    // 0x80071408: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_1;
    // 0x80071408: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_1:
    // 0x8007140C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80071410: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80071414: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071418: beq         $v0, $zero, L_80071450
    if (ctx->r2 == 0) {
        // 0x8007141C: nop

            goto L_80071450;
    }
    // 0x8007141C: nop

    // 0x80071420: jal         0x80061348
    // 0x80071424: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    func_80061348(rdram, ctx);
        goto after_2;
    // 0x80071424: addiu       $a0, $zero, 0x4BA
    ctx->r4 = ADD32(0, 0X4BA);
    after_2:
    // 0x80071428: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x8007142C: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80071430: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80071434: beq         $v0, $zero, L_80071450
    if (ctx->r2 == 0) {
        // 0x80071438: nop

            goto L_80071450;
    }
    // 0x80071438: nop

    // 0x8007143C: jal         0x80061348
    // 0x80071440: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    func_80061348(rdram, ctx);
        goto after_3;
    // 0x80071440: addiu       $a0, $zero, 0x4BB
    ctx->r4 = ADD32(0, 0X4BB);
    after_3:
    // 0x80071444: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80071448: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8007144C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80071450:
    // 0x80071450: b           L_80071460
    // 0x80071454: nop

        goto L_80071460;
    // 0x80071454: nop

    // 0x80071458: b           L_80071460
    // 0x8007145C: nop

        goto L_80071460;
    // 0x8007145C: nop

L_80071460:
    // 0x80071460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071468: jr          $ra
    // 0x8007146C: nop

    return;
    // 0x8007146C: nop

;}
RECOMP_FUNC void func_80071470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071470: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071474: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071478: nop

    // 0x8007147C: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x80071480: nop

    // 0x80071484: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x80071488: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007148C: jr          $ra
    // 0x80071490: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071490: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071494: jr          $ra
    // 0x80071498: nop

    return;
    // 0x80071498: nop

    // 0x8007149C: jr          $ra
    // 0x800714A0: nop

    return;
    // 0x800714A0: nop

;}
RECOMP_FUNC void func_800714A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800714A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800714A8: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800714AC: nop

    // 0x800714B0: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800714B4: nop

    // 0x800714B8: slti        $t7, $v0, 0x2BC
    ctx->r15 = SIGNED(ctx->r2) < 0X2BC ? 1 : 0;
    // 0x800714BC: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800714C0: jr          $ra
    // 0x800714C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800714C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800714C8: jr          $ra
    // 0x800714CC: nop

    return;
    // 0x800714CC: nop

    // 0x800714D0: jr          $ra
    // 0x800714D4: nop

    return;
    // 0x800714D4: nop

;}
RECOMP_FUNC void func_800714D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800714D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800714DC: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800714E0: nop

    // 0x800714E4: lh          $v0, 0xA($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XA);
    // 0x800714E8: nop

    // 0x800714EC: slti        $t7, $v0, 0x384
    ctx->r15 = SIGNED(ctx->r2) < 0X384 ? 1 : 0;
    // 0x800714F0: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x800714F4: jr          $ra
    // 0x800714F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x800714F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800714FC: jr          $ra
    // 0x80071500: nop

    return;
    // 0x80071500: nop

    // 0x80071504: jr          $ra
    // 0x80071508: nop

    return;
    // 0x80071508: nop

;}
RECOMP_FUNC void func_8007150C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007150C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071514: jal         0x80061348
    // 0x80071518: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    func_80061348(rdram, ctx);
        goto after_0;
    // 0x80071518: addiu       $a0, $zero, 0x43D
    ctx->r4 = ADD32(0, 0X43D);
    after_0:
    // 0x8007151C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80071520: b           L_80071530
    // 0x80071524: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80071530;
    // 0x80071524: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80071528: b           L_80071530
    // 0x8007152C: nop

        goto L_80071530;
    // 0x8007152C: nop

L_80071530:
    // 0x80071530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071538: jr          $ra
    // 0x8007153C: nop

    return;
    // 0x8007153C: nop

;}
RECOMP_FUNC void func_80071540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071540: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80071544: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x80071548: nop

    // 0x8007154C: lh          $v0, 0xC($t6)
    ctx->r2 = MEM_H(ctx->r14, 0XC);
    // 0x80071550: nop

    // 0x80071554: slti        $t7, $v0, 0x2BD
    ctx->r15 = SIGNED(ctx->r2) < 0X2BD ? 1 : 0;
    // 0x80071558: xori        $t7, $t7, 0x1
    ctx->r15 = ctx->r15 ^ 0X1;
    // 0x8007155C: jr          $ra
    // 0x80071560: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x80071560: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80071564: jr          $ra
    // 0x80071568: nop

    return;
    // 0x80071568: nop

    // 0x8007156C: jr          $ra
    // 0x80071570: nop

    return;
    // 0x80071570: nop

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
