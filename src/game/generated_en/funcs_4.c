#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void SoundDebugMenu_SfxOneShotTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021D8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80021D90: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80021D94: nop

    // 0x80021D98: bltz        $t6, L_80021E94
    if (SIGNED(ctx->r14) < 0) {
        // 0x80021D9C: nop

            goto L_80021E94;
    }
    // 0x80021D9C: nop

    // 0x80021DA0: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80021DA4: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80021DA8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80021DAC: lhu         $t9, 0xEEC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XEEC);
    // 0x80021DB0: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x80021DB4: nop

    // 0x80021DB8: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80021DBC: beq         $t0, $zero, L_80021DD8
    if (ctx->r8 == 0) {
        // 0x80021DC0: nop

            goto L_80021DD8;
    }
    // 0x80021DC0: nop

    // 0x80021DC4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80021DC8: lw          $t1, -0x33B8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X33B8);
    // 0x80021DCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021DD0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80021DD4: sw          $t2, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = ctx->r10;
L_80021DD8:
    // 0x80021DD8: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80021DDC: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x80021DE0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80021DE4: lhu         $t5, 0xEC0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XEC0);
    // 0x80021DE8: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x80021DEC: nop

    // 0x80021DF0: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80021DF4: beq         $t6, $zero, L_80021E10
    if (ctx->r14 == 0) {
        // 0x80021DF8: nop

            goto L_80021E10;
    }
    // 0x80021DF8: nop

    // 0x80021DFC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80021E00: lw          $t7, -0x33B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33B8);
    // 0x80021E04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021E08: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80021E0C: sw          $t8, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = ctx->r24;
L_80021E10:
    // 0x80021E10: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80021E14: lw          $t9, -0x33B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33B8);
    // 0x80021E18: nop

    // 0x80021E1C: bgez        $t9, L_80021E2C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80021E20: nop

            goto L_80021E2C;
    }
    // 0x80021E20: nop

    // 0x80021E24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021E28: sw          $zero, -0x33B8($at)
    MEM_W(-0X33B8, ctx->r1) = 0;
L_80021E2C:
    // 0x80021E2C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80021E30: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80021E34: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80021E38: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x80021E3C: lhu         $t1, 0x6($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X6);
    // 0x80021E40: nop

    // 0x80021E44: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80021E48: beq         $t3, $zero, L_80021E60
    if (ctx->r11 == 0) {
        // 0x80021E4C: nop

            goto L_80021E60;
    }
    // 0x80021E4C: nop

    // 0x80021E50: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80021E54: lw          $a0, -0x33B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33B8);
    // 0x80021E58: jal         0x800B9000
    // 0x80021E5C: nop

    func_800B9000(rdram, ctx);
        goto after_0;
    // 0x80021E5C: nop

    after_0:
L_80021E60:
    // 0x80021E60: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80021E64: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80021E68: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80021E6C: lhu         $t6, 0x101C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X101C);
    // 0x80021E70: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80021E74: nop

    // 0x80021E78: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x80021E7C: beq         $t7, $zero, L_80021E94
    if (ctx->r15 == 0) {
        // 0x80021E80: nop

            goto L_80021E94;
    }
    // 0x80021E80: nop

    // 0x80021E84: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80021E88: lw          $a0, -0x33B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33B8);
    // 0x80021E8C: jal         0x800220F4
    // 0x80021E90: nop

    func_800220F4(rdram, ctx);
        goto after_1;
    // 0x80021E90: nop

    after_1:
L_80021E94:
    // 0x80021E94: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80021E98: lw          $a1, -0x33B8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X33B8);
    // 0x80021E9C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80021EA0: jal         0x8008ECE4
    // 0x80021EA4: addiu       $a0, $a0, -0x1CF8
    ctx->r4 = ADD32(ctx->r4, -0X1CF8);
    func_8008ECE4(rdram, ctx);
        goto after_2;
    // 0x80021EA4: addiu       $a0, $a0, -0x1CF8
    ctx->r4 = ADD32(ctx->r4, -0X1CF8);
    after_2:
    // 0x80021EA8: b           L_80021EB8
    // 0x80021EAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80021EB8;
    // 0x80021EAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021EB0: b           L_80021EB8
    // 0x80021EB4: nop

        goto L_80021EB8;
    // 0x80021EB4: nop

L_80021EB8:
    // 0x80021EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021EC0: jr          $ra
    // 0x80021EC4: nop

    return;
    // 0x80021EC4: nop

;}
RECOMP_FUNC void func_80021EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021EC8: nop

    // 0x80021ECC: nop

;}
RECOMP_FUNC void AudioGeneral_PlayBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021ED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021EDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80021EE0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80021EE4: sw          $t6, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r14;
    // 0x80021EE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021EEC: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    // 0x80021EF0: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    // 0x80021EF4: jal         0x800BB52C
    // 0x80021EF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    AudioDriver_ConfigSeqPlayerVolume(rdram, ctx);
        goto after_0;
    // 0x80021EF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80021EFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80021F00: jal         0x800BB3D4
    // 0x80021F04: nop

    AudioDriver_UpdateSeqID(rdram, ctx);
        goto after_1;
    // 0x80021F04: nop

    after_1:
    // 0x80021F08: b           L_80021F10
    // 0x80021F0C: nop

        goto L_80021F10;
    // 0x80021F0C: nop

L_80021F10:
    // 0x80021F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021F14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021F18: jr          $ra
    // 0x80021F1C: nop

    return;
    // 0x80021F1C: nop

;}
RECOMP_FUNC void AudioGeneral_BGMFadeOut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021F28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021F2C: lhu         $t6, 0x1A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1A);
    // 0x80021F30: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80021F34: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x80021F38: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80021F3C: bne         $t6, $zero, L_80021F48
    if (ctx->r14 != 0) {
        // 0x80021F40: nop

            goto L_80021F48;
    }
    // 0x80021F40: nop

    // 0x80021F44: break       7
    do_break(2147622724);
L_80021F48:
    // 0x80021F48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021F4C: bne         $t6, $at, L_80021F60
    if (ctx->r14 != ctx->r1) {
        // 0x80021F50: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021F60;
    }
    // 0x80021F50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021F54: bne         $t7, $at, L_80021F60
    if (ctx->r15 != ctx->r1) {
        // 0x80021F58: nop

            goto L_80021F60;
    }
    // 0x80021F58: nop

    // 0x80021F5C: break       6
    do_break(2147622748);
L_80021F60:
    // 0x80021F60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80021F64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80021F68: mflo        $a1
    ctx->r5 = lo;
    // 0x80021F6C: jal         0x800BB52C
    // 0x80021F70: nop

    AudioDriver_ConfigSeqPlayerVolume(rdram, ctx);
        goto after_0;
    // 0x80021F70: nop

    after_0:
    // 0x80021F74: b           L_80021F7C
    // 0x80021F78: nop

        goto L_80021F7C;
    // 0x80021F78: nop

L_80021F7C:
    // 0x80021F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021F84: jr          $ra
    // 0x80021F88: nop

    return;
    // 0x80021F88: nop

;}
RECOMP_FUNC void AudioGeneral_BGMFadeIn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021F8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021F94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021F98: lhu         $t6, 0x1A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1A);
    // 0x80021F9C: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80021FA0: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x80021FA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80021FA8: bne         $t6, $zero, L_80021FB4
    if (ctx->r14 != 0) {
        // 0x80021FAC: nop

            goto L_80021FB4;
    }
    // 0x80021FAC: nop

    // 0x80021FB0: break       7
    do_break(2147622832);
L_80021FB4:
    // 0x80021FB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021FB8: bne         $t6, $at, L_80021FCC
    if (ctx->r14 != ctx->r1) {
        // 0x80021FBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021FCC;
    }
    // 0x80021FBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021FC0: bne         $t7, $at, L_80021FCC
    if (ctx->r15 != ctx->r1) {
        // 0x80021FC4: nop

            goto L_80021FCC;
    }
    // 0x80021FC4: nop

    // 0x80021FC8: break       6
    do_break(2147622856);
L_80021FCC:
    // 0x80021FCC: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    // 0x80021FD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80021FD4: mflo        $a1
    ctx->r5 = lo;
    // 0x80021FD8: jal         0x800BB52C
    // 0x80021FDC: nop

    AudioDriver_ConfigSeqPlayerVolume(rdram, ctx);
        goto after_0;
    // 0x80021FDC: nop

    after_0:
    // 0x80021FE0: b           L_80021FE8
    // 0x80021FE4: nop

        goto L_80021FE8;
    // 0x80021FE4: nop

L_80021FE8:
    // 0x80021FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021FF0: jr          $ra
    // 0x80021FF4: nop

    return;
    // 0x80021FF4: nop

;}
RECOMP_FUNC void func_80021FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80022004: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80022008: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002200C: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x80022010: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80022014: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x80022018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002201C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80022020: bne         $t6, $zero, L_8002202C
    if (ctx->r14 != 0) {
        // 0x80022024: nop

            goto L_8002202C;
    }
    // 0x80022024: nop

    // 0x80022028: break       7
    do_break(2147622952);
L_8002202C:
    // 0x8002202C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80022030: bne         $t6, $at, L_80022044
    if (ctx->r14 != ctx->r1) {
        // 0x80022034: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80022044;
    }
    // 0x80022034: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80022038: bne         $t7, $at, L_80022044
    if (ctx->r15 != ctx->r1) {
        // 0x8002203C: nop

            goto L_80022044;
    }
    // 0x8002203C: nop

    // 0x80022040: break       6
    do_break(2147622976);
L_80022044:
    // 0x80022044: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80022048: mflo        $a1
    ctx->r5 = lo;
    // 0x8002204C: jal         0x800BB52C
    // 0x80022050: nop

    AudioDriver_ConfigSeqPlayerVolume(rdram, ctx);
        goto after_0;
    // 0x80022050: nop

    after_0:
    // 0x80022054: b           L_8002205C
    // 0x80022058: nop

        goto L_8002205C;
    // 0x80022058: nop

L_8002205C:
    // 0x8002205C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022064: jr          $ra
    // 0x80022068: nop

    return;
    // 0x80022068: nop

;}
RECOMP_FUNC void func_8002206C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002206C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022074: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80022078: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002207C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80022080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80022084: jal         0x800BB448
    // 0x80022088: nop

    func_800BB448(rdram, ctx);
        goto after_0;
    // 0x80022088: nop

    after_0:
    // 0x8002208C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80022090: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80022094: nop

    // 0x80022098: bne         $t6, $zero, L_800220A8
    if (ctx->r14 != 0) {
        // 0x8002209C: nop

            goto L_800220A8;
    }
    // 0x8002209C: nop

    // 0x800220A0: b           L_800220E4
    // 0x800220A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800220E4;
    // 0x800220A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800220A8:
    // 0x800220A8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800220AC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800220B0: nop

    // 0x800220B4: sw          $t7, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r15;
    // 0x800220B8: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x800220BC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800220C0: nop

    // 0x800220C4: sb          $t9, 0x1A($t0)
    MEM_B(0X1A, ctx->r8) = ctx->r25;
    // 0x800220C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800220CC: jal         0x800BB4B4
    // 0x800220D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BB4B4(rdram, ctx);
        goto after_1;
    // 0x800220D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x800220D4: b           L_800220E4
    // 0x800220D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800220E4;
    // 0x800220D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800220DC: b           L_800220E4
    // 0x800220E0: nop

        goto L_800220E4;
    // 0x800220E0: nop

L_800220E4:
    // 0x800220E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800220E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800220EC: jr          $ra
    // 0x800220F0: nop

    return;
    // 0x800220F0: nop

;}
RECOMP_FUNC void func_800220F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800220F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800220F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800220FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80022100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80022104: jal         0x800BB4DC
    // 0x80022108: nop

    func_800BB4DC(rdram, ctx);
        goto after_0;
    // 0x80022108: nop

    after_0:
    // 0x8002210C: b           L_80022114
    // 0x80022110: nop

        goto L_80022114;
    // 0x80022110: nop

L_80022114:
    // 0x80022114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002211C: jr          $ra
    // 0x80022120: nop

    return;
    // 0x80022120: nop

;}
RECOMP_FUNC void func_80022124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002212C: jal         0x800BB4DC
    // 0x80022130: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_800BB4DC(rdram, ctx);
        goto after_0;
    // 0x80022130: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // 0x80022134: b           L_8002213C
    // 0x80022138: nop

        goto L_8002213C;
    // 0x80022138: nop

L_8002213C:
    // 0x8002213C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022144: jr          $ra
    // 0x80022148: nop

    return;
    // 0x80022148: nop

;}
RECOMP_FUNC void func_8002214C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002214C: nop

;}
RECOMP_FUNC void func_80022150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022150: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80022154: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80022158: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8002215C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80022160: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80022164: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80022168: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002216C: swc1        $f4, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f4.u32l;
    // 0x80022170: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80022174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022178: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002217C: swc1        $f6, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f6.u32l;
    // 0x80022180: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80022184: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022188: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002218C: swc1        $f8, 0xE6C($at)
    MEM_W(0XE6C, ctx->r1) = ctx->f8.u32l;
    // 0x80022190: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022194: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
    // 0x80022198: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002219C: sb          $zero, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = 0;
    // 0x800221A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221A4: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x800221A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221AC: sh          $zero, 0x654($at)
    MEM_H(0X654, ctx->r1) = 0;
    // 0x800221B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221B4: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
    // 0x800221B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221BC: sh          $zero, 0x67C($at)
    MEM_H(0X67C, ctx->r1) = 0;
    // 0x800221C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221C4: sb          $zero, 0xE54($at)
    MEM_B(0XE54, ctx->r1) = 0;
    // 0x800221C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221CC: sb          $zero, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = 0;
    // 0x800221D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800221D4: sh          $zero, 0x126E($at)
    MEM_H(0X126E, ctx->r1) = 0;
    // 0x800221D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800221DC: addiu       $t6, $t6, 0x1668
    ctx->r14 = ADD32(ctx->r14, 0X1668);
    // 0x800221E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800221E4: addiu       $t7, $t7, 0x1668
    ctx->r15 = ADD32(ctx->r15, 0X1668);
    // 0x800221E8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800221EC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800221F0: nop

    // 0x800221F4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800221F8: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x800221FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022200: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x80022204: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80022208: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002220C: swc1        $f10, 0xD58($at)
    MEM_W(0XD58, ctx->r1) = ctx->f10.u32l;
    // 0x80022210: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022214: swc1        $f10, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f10.u32l;
    // 0x80022218: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002221C: swc1        $f10, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f10.u32l;
    // 0x80022220: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022224: sw          $zero, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = 0;
    // 0x80022228: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002222C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80022230: lhu         $t1, 0x101C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X101C);
    // 0x80022234: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x80022238: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002223C: lhu         $t3, 0x11AC($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X11AC);
    // 0x80022240: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80022244: lhu         $t5, 0x1258($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1258);
    // 0x80022248: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002224C: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80022250: lhu         $t8, 0x1260($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1260);
    // 0x80022254: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80022258: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8002225C: lhu         $t9, 0x126C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X126C);
    // 0x80022260: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80022264: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80022268: lhu         $t1, 0x1042($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1042);
    // 0x8002226C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80022270: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80022274: lhu         $t3, 0x10F2($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X10F2);
    // 0x80022278: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8002227C: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80022280: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022284: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x80022288: sh          $t4, 0x6C8($at)
    MEM_H(0X6C8, ctx->r1) = ctx->r12;
    // 0x8002228C: jal         0x800BC6EC
    // 0x80022290: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80022290: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x80022294: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022298: sw          $v0, 0xCDC($at)
    MEM_W(0XCDC, ctx->r1) = ctx->r2;
    // 0x8002229C: jal         0x800BC6EC
    // 0x800222A0: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_1;
    // 0x800222A0: addiu       $a0, $zero, 0x640
    ctx->r4 = ADD32(0, 0X640);
    after_1:
    // 0x800222A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800222A8: sw          $v0, 0xCD0($at)
    MEM_W(0XCD0, ctx->r1) = ctx->r2;
    // 0x800222AC: jal         0x800BC6EC
    // 0x800222B0: addiu       $a0, $zero, 0x2C0
    ctx->r4 = ADD32(0, 0X2C0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800222B0: addiu       $a0, $zero, 0x2C0
    ctx->r4 = ADD32(0, 0X2C0);
    after_2:
    // 0x800222B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800222B8: sw          $v0, 0xCE8($at)
    MEM_W(0XCE8, ctx->r1) = ctx->r2;
    // 0x800222BC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800222C0: lw          $t5, 0xCE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE8);
    // 0x800222C4: nop

    // 0x800222C8: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800222CC: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
L_800222D0:
    // 0x800222D0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800222D4: jal         0x80099E2C
    // 0x800222D8: nop

    func_80099E2C(rdram, ctx);
        goto after_3;
    // 0x800222D8: nop

    after_3:
    // 0x800222DC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800222E0: addiu       $t6, $zero, -0x28
    ctx->r14 = ADD32(0, -0X28);
    // 0x800222E4: sw          $t6, 0x104($t8)
    MEM_W(0X104, ctx->r24) = ctx->r14;
    // 0x800222E8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800222EC: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x800222F0: sw          $t7, 0x108($t9)
    MEM_W(0X108, ctx->r25) = ctx->r15;
    // 0x800222F4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800222F8: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x800222FC: sw          $t0, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->r8;
    // 0x80022300: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80022304: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x80022308: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
    // 0x8002230C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80022310: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80022314: sh          $t4, 0xC4($t5)
    MEM_H(0XC4, ctx->r13) = ctx->r12;
    // 0x80022318: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002231C: nop

    // 0x80022320: addiu       $t8, $t6, 0x160
    ctx->r24 = ADD32(ctx->r14, 0X160);
    // 0x80022324: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80022328: lh          $t7, 0x4E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4E);
    // 0x8002232C: nop

    // 0x80022330: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80022334: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x80022338: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8002233C: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80022340: bne         $at, $zero, L_800222D0
    if (ctx->r1 != 0) {
        // 0x80022344: sh          $t9, 0x4E($sp)
        MEM_H(0X4E, ctx->r29) = ctx->r25;
            goto L_800222D0;
    }
    // 0x80022344: sh          $t9, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r25;
    // 0x80022348: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002234C: nop

    // 0x80022350: addiu       $t3, $t2, -0x160
    ctx->r11 = ADD32(ctx->r10, -0X160);
    // 0x80022354: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80022358: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002235C: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x80022360: sh          $t4, 0x100($t5)
    MEM_H(0X100, ctx->r13) = ctx->r12;
    // 0x80022364: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80022368: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002236C: sh          $t6, 0x102($t8)
    MEM_H(0X102, ctx->r24) = ctx->r14;
    // 0x80022370: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80022374: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80022378: addiu       $t7, $t7, -0x44B8
    ctx->r15 = ADD32(ctx->r15, -0X44B8);
    // 0x8002237C: sw          $t7, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r15;
    // 0x80022380: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80022384: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80022388: sh          $t0, 0x116($t1)
    MEM_H(0X116, ctx->r9) = ctx->r8;
    // 0x8002238C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80022390: addiu       $t2, $t2, 0x5B0
    ctx->r10 = ADD32(ctx->r10, 0X5B0);
    // 0x80022394: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80022398: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002239C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800223A0: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x800223A4: addiu       $a2, $a2, 0x3C30
    ctx->r6 = ADD32(ctx->r6, 0X3C30);
    // 0x800223A8: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800223AC: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800223B0: jal         0x800BD1FC
    // 0x800223B4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x800223B4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_4:
    // 0x800223B8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800223BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800223C0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800223C4: jal         0x800BD218
    // 0x800223C8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_5;
    // 0x800223C8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_5:
    // 0x800223CC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800223D0: nop

    // 0x800223D4: addiu       $t4, $t3, -0x160
    ctx->r12 = ADD32(ctx->r11, -0X160);
    // 0x800223D8: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800223DC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800223E0: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x800223E4: sh          $t5, 0x100($t6)
    MEM_H(0X100, ctx->r14) = ctx->r13;
    // 0x800223E8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800223EC: addiu       $t8, $zero, 0x1A
    ctx->r24 = ADD32(0, 0X1A);
    // 0x800223F0: sh          $t8, 0x102($t7)
    MEM_H(0X102, ctx->r15) = ctx->r24;
    // 0x800223F4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800223F8: lw          $t9, 0x1688($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1688);
    // 0x800223FC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80022400: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x80022404: nop

    // 0x80022408: sw          $t0, 0x138($t1)
    MEM_W(0X138, ctx->r9) = ctx->r8;
    // 0x8002240C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80022410: nop

    // 0x80022414: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x80022418: nop

    // 0x8002241C: ori         $t4, $t3, 0x100
    ctx->r12 = ctx->r11 | 0X100;
    // 0x80022420: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
    // 0x80022424: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80022428: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002242C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80022430: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80022434: lui         $t8, 0x809B
    ctx->r24 = S32(0X809B << 16);
    // 0x80022438: addiu       $t8, $t8, 0x1E10
    ctx->r24 = ADD32(ctx->r24, 0X1E10);
    // 0x8002243C: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x80022440: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x80022444: jal         0x800BD1FC
    // 0x80022448: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x80022448: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    after_6:
    // 0x8002244C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80022450: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80022454: jal         0x800BED70
    // 0x80022458: nop

    Spi_GetHeader(rdram, ctx);
        goto after_7;
    // 0x80022458: nop

    after_7:
    // 0x8002245C: sh          $v0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r2;
    // 0x80022460: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80022464: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x80022468: jal         0x800BC6EC
    // 0x8002246C: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x8002246C: nop

    after_8:
    // 0x80022470: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80022474: nop

    // 0x80022478: sw          $v0, 0x128($t7)
    MEM_W(0X128, ctx->r15) = ctx->r2;
    // 0x8002247C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80022480: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80022484: lh          $a1, 0x4C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4C);
    // 0x80022488: lw          $a2, 0x128($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X128);
    // 0x8002248C: jal         0x800BF0B4
    // 0x80022490: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_9;
    // 0x80022490: nop

    after_9:
    // 0x80022494: jal         0x800BC6EC
    // 0x80022498: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_10;
    // 0x80022498: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_10:
    // 0x8002249C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800224A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800224A4: sw          $s0, 0x20C($t0)
    MEM_W(0X20C, ctx->r8) = ctx->r16;
    // 0x800224A8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800224AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800224B0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800224B4: nop

    // 0x800224B8: swc1        $f16, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f16.u32l;
    // 0x800224BC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800224C0: nop

    // 0x800224C4: lwc1        $f18, 0x1C($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800224C8: nop

    // 0x800224CC: swc1        $f18, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f18.u32l;
    // 0x800224D0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800224D4: nop

    // 0x800224D8: sh          $zero, 0x22($t4)
    MEM_H(0X22, ctx->r12) = 0;
    // 0x800224DC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800224E0: nop

    // 0x800224E4: sh          $zero, 0x20($t2)
    MEM_H(0X20, ctx->r10) = 0;
    // 0x800224E8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800224EC: nop

    // 0x800224F0: lh          $t6, 0x20($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X20);
    // 0x800224F4: nop

    // 0x800224F8: sh          $t6, 0x24($t5)
    MEM_H(0X24, ctx->r13) = ctx->r14;
    // 0x800224FC: jal         0x800BC6EC
    // 0x80022500: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x80022500: addiu       $a0, $zero, 0x420
    ctx->r4 = ADD32(0, 0X420);
    after_11:
    // 0x80022504: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80022508: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002250C: sw          $s0, 0x210($t8)
    MEM_W(0X210, ctx->r24) = ctx->r16;
    // 0x80022510: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80022514: jal         0x800BC6EC
    // 0x80022518: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_12;
    // 0x80022518: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_12:
    // 0x8002251C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80022520: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80022524: sw          $s0, 0x214($t7)
    MEM_W(0X214, ctx->r15) = ctx->r16;
    // 0x80022528: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8002252C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80022530: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80022534: sw          $t9, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r25;
    // 0x80022538: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002253C: lwc1        $f4, 0xE60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x80022540: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80022544: nop

    // 0x80022548: swc1        $f4, 0x1B0($t1)
    MEM_W(0X1B0, ctx->r9) = ctx->f4.u32l;
    // 0x8002254C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022550: lwc1        $f6, 0xE6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE6C);
    // 0x80022554: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80022558: nop

    // 0x8002255C: swc1        $f6, 0x1B4($t3)
    MEM_W(0X1B4, ctx->r11) = ctx->f6.u32l;
    // 0x80022560: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
L_80022564:
    // 0x80022564: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80022568: jal         0x80099E2C
    // 0x8002256C: nop

    func_80099E2C(rdram, ctx);
        goto after_13;
    // 0x8002256C: nop

    after_13:
    // 0x80022570: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022574: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80022578: nop

    // 0x8002257C: swc1        $f8, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f8.u32l;
    // 0x80022580: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80022584: addiu       $t2, $zero, 0x48
    ctx->r10 = ADD32(0, 0X48);
    // 0x80022588: sw          $t2, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r10;
    // 0x8002258C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80022590: addiu       $t5, $zero, 0x5A
    ctx->r13 = ADD32(0, 0X5A);
    // 0x80022594: sw          $t5, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r13;
    // 0x80022598: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002259C: nop

    // 0x800225A0: sw          $zero, 0x140($t7)
    MEM_W(0X140, ctx->r15) = 0;
    // 0x800225A4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800225A8: nop

    // 0x800225AC: lw          $t0, 0x140($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X140);
    // 0x800225B0: nop

    // 0x800225B4: sw          $t0, 0x13C($t9)
    MEM_W(0X13C, ctx->r25) = ctx->r8;
    // 0x800225B8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800225BC: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800225C0: sh          $t1, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r9;
    // 0x800225C4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800225C8: nop

    // 0x800225CC: addiu       $t2, $t4, 0x160
    ctx->r10 = ADD32(ctx->r12, 0X160);
    // 0x800225D0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x800225D4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800225D8: nop

    // 0x800225DC: addiu       $t5, $t6, 0x40
    ctx->r13 = ADD32(ctx->r14, 0X40);
    // 0x800225E0: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800225E4: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x800225E8: nop

    // 0x800225EC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800225F0: sll         $t0, $t7, 16
    ctx->r8 = S32(ctx->r15 << 16);
    // 0x800225F4: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800225F8: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x800225FC: bne         $at, $zero, L_80022564
    if (ctx->r1 != 0) {
        // 0x80022600: sh          $t7, 0x4E($sp)
        MEM_H(0X4E, ctx->r29) = ctx->r15;
            goto L_80022564;
    }
    // 0x80022600: sh          $t7, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r15;
    // 0x80022604: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80022608: nop

    // 0x8002260C: addiu       $t3, $t1, -0x420
    ctx->r11 = ADD32(ctx->r9, -0X420);
    // 0x80022610: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80022614: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80022618: nop

    // 0x8002261C: addiu       $t2, $t4, -0xC0
    ctx->r10 = ADD32(ctx->r12, -0XC0);
    // 0x80022620: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80022624: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80022628: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8002262C: jal         0x800B1B3C
    // 0x80022630: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800B1B3C(rdram, ctx);
        goto after_14;
    // 0x80022630: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_14:
    // 0x80022634: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80022638: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002263C: lwc1        $f10, 0xE60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE60);
    // 0x80022640: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022644: lh          $a2, 0x22($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X22);
    // 0x80022648: lwc1        $f16, 0xE6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XE6C);
    // 0x8002264C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80022650: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80022654: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80022658: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8002265C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80022660: jal         0x800B202C
    // 0x80022664: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B202C(rdram, ctx);
        goto after_15;
    // 0x80022664: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x80022668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002266C: sh          $v0, 0x11A6($at)
    MEM_H(0X11A6, ctx->r1) = ctx->r2;
    // 0x80022670: b           L_80022680
    // 0x80022674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80022680;
    // 0x80022674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022678: b           L_80022680
    // 0x8002267C: nop

        goto L_80022680;
    // 0x8002267C: nop

L_80022680:
    // 0x80022680: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80022684: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80022688: jr          $ra
    // 0x8002268C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8002268C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80022690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022698: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002269C: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800226A0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800226A4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800226A8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800226AC: bne         $t0, $zero, L_800226D4
    if (ctx->r8 != 0) {
        // 0x800226B0: andi        $t1, $t9, 0x8000
        ctx->r9 = ctx->r25 & 0X8000;
            goto L_800226D4;
    }
    // 0x800226B0: andi        $t1, $t9, 0x8000
    ctx->r9 = ctx->r25 & 0X8000;
    // 0x800226B4: bne         $t1, $zero, L_800226D4
    if (ctx->r9 != 0) {
        // 0x800226B8: nop

            goto L_800226D4;
    }
    // 0x800226B8: nop

    // 0x800226BC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800226C0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800226C4: bne         $t2, $zero, L_800226D4
    if (ctx->r10 != 0) {
        // 0x800226C8: and         $t3, $t9, $at
        ctx->r11 = ctx->r25 & ctx->r1;
            goto L_800226D4;
    }
    // 0x800226C8: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x800226CC: beq         $t3, $zero, L_800226DC
    if (ctx->r11 == 0) {
        // 0x800226D0: nop

            goto L_800226DC;
    }
    // 0x800226D0: nop

L_800226D4:
    // 0x800226D4: jal         0x80055FB8
    // 0x800226D8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80055FB8(rdram, ctx);
        goto after_0;
    // 0x800226D8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
L_800226DC:
    // 0x800226DC: b           L_800226E4
    // 0x800226E0: nop

        goto L_800226E4;
    // 0x800226E0: nop

L_800226E4:
    // 0x800226E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800226E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800226EC: jr          $ra
    // 0x800226F0: nop

    return;
    // 0x800226F0: nop

;}
RECOMP_FUNC void func_800226F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800226F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800226F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800226FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80022700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022704: lwc1        $f4, 0xEF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x80022708: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8002270C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022710: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80022714: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80022718: nop

    // 0x8002271C: bc1f        L_80022770
    if (!c1cs) {
        // 0x80022720: nop

            goto L_80022770;
    }
    // 0x80022720: nop

    // 0x80022724: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022728: lwc1        $f10, 0xEF0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x8002272C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022730: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80022734: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80022738: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002273C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80022740: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80022744: c.le.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d <= ctx->f6.d;
    // 0x80022748: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002274C: bc1f        L_80022770
    if (!c1cs) {
        // 0x80022750: swc1        $f18, 0xEF0($at)
        MEM_W(0XEF0, ctx->r1) = ctx->f18.u32l;
            goto L_80022770;
    }
    // 0x80022750: swc1        $f18, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f18.u32l;
    // 0x80022754: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022758: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002275C: swc1        $f8, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f8.u32l;
    // 0x80022760: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022764: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80022768: b           L_80022898
    // 0x8002276C: nop

        goto L_80022898;
    // 0x8002276C: nop

L_80022770:
    // 0x80022770: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80022774: lh          $t6, 0x66C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X66C);
    // 0x80022778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002277C: bne         $t6, $at, L_80022890
    if (ctx->r14 != ctx->r1) {
        // 0x80022780: nop

            goto L_80022890;
    }
    // 0x80022780: nop

    // 0x80022784: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80022788: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8002278C: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x80022790: nop

    // 0x80022794: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    // 0x80022798: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8002279C: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x800227A0: lhu         $t9, 0x1E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1E);
    // 0x800227A4: nop

    // 0x800227A8: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800227AC: beq         $t1, $zero, L_80022818
    if (ctx->r9 == 0) {
        // 0x800227B0: nop

            goto L_80022818;
    }
    // 0x800227B0: nop

    // 0x800227B4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800227B8: lh          $t2, 0x6C0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X6C0);
    // 0x800227BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800227C0: beq         $t2, $at, L_80022818
    if (ctx->r10 == ctx->r1) {
        // 0x800227C4: nop

            goto L_80022818;
    }
    // 0x800227C4: nop

    // 0x800227C8: jal         0x80055FB8
    // 0x800227CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_0;
    // 0x800227CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800227D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800227D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800227D8: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x800227DC: lhu         $t4, 0x22($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X22);
    // 0x800227E0: nop

    // 0x800227E4: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800227E8: bgez        $t4, L_80022800
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800227EC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80022800;
    }
    // 0x800227EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800227F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800227F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800227F8: nop

    // 0x800227FC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80022800:
    // 0x80022800: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022804: swc1        $f16, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f16.u32l;
    // 0x80022808: jal         0x800B9000
    // 0x8002280C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800B9000(rdram, ctx);
        goto after_1;
    // 0x8002280C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80022810: b           L_80022890
    // 0x80022814: nop

        goto L_80022890;
    // 0x80022814: nop

L_80022818:
    // 0x80022818: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002281C: lhu         $t6, 0x101C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X101C);
    // 0x80022820: lhu         $t5, 0x1E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X1E);
    // 0x80022824: nop

    // 0x80022828: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8002282C: beq         $t7, $zero, L_80022890
    if (ctx->r15 == 0) {
        // 0x80022830: nop

            goto L_80022890;
    }
    // 0x80022830: nop

    // 0x80022834: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80022838: lh          $t8, 0x6C0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X6C0);
    // 0x8002283C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80022840: beq         $t8, $at, L_80022890
    if (ctx->r24 == ctx->r1) {
        // 0x80022844: nop

            goto L_80022890;
    }
    // 0x80022844: nop

    // 0x80022848: jal         0x80055FB8
    // 0x8002284C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_2;
    // 0x8002284C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80022850: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80022854: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022858: sh          $t9, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r25;
    // 0x8002285C: lhu         $t0, 0x22($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X22);
    // 0x80022860: nop

    // 0x80022864: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80022868: bgez        $t0, L_80022880
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8002286C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80022880;
    }
    // 0x8002286C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80022870: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80022874: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022878: nop

    // 0x8002287C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80022880:
    // 0x80022880: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022884: swc1        $f6, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f6.u32l;
    // 0x80022888: jal         0x800B9000
    // 0x8002288C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_3;
    // 0x8002288C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_3:
L_80022890:
    // 0x80022890: b           L_80022898
    // 0x80022894: nop

        goto L_80022898;
    // 0x80022894: nop

L_80022898:
    // 0x80022898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002289C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800228A0: jr          $ra
    // 0x800228A4: nop

    return;
    // 0x800228A4: nop

;}
RECOMP_FUNC void func_800228A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800228AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800228B0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800228B4: lbu         $t6, 0x11AE($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X11AE);
    // 0x800228B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800228BC: bne         $t6, $at, L_80022900
    if (ctx->r14 != ctx->r1) {
        // 0x800228C0: nop

            goto L_80022900;
    }
    // 0x800228C0: nop

    // 0x800228C4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800228C8: lw          $t7, 0x307C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X307C);
    // 0x800228CC: nop

    // 0x800228D0: beq         $t7, $zero, L_80022900
    if (ctx->r15 == 0) {
        // 0x800228D4: nop

            goto L_80022900;
    }
    // 0x800228D4: nop

    // 0x800228D8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800228DC: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    // 0x800228E0: jal         0x8002C270
    // 0x800228E4: nop

    func_8002C270(rdram, ctx);
        goto after_0;
    // 0x800228E4: nop

    after_0:
    // 0x800228E8: jal         0x800B0E08
    // 0x800228EC: nop

    func_800B0E08(rdram, ctx);
        goto after_1;
    // 0x800228EC: nop

    after_1:
    // 0x800228F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800228F4: sb          $zero, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = 0;
    // 0x800228F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800228FC: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
L_80022900:
    // 0x80022900: b           L_80022908
    // 0x80022904: nop

        goto L_80022908;
    // 0x80022904: nop

L_80022908:
    // 0x80022908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002290C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022910: jr          $ra
    // 0x80022914: nop

    return;
    // 0x80022914: nop

;}
RECOMP_FUNC void func_80022918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022918: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002291C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80022920: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80022924: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80022928: swc1        $f12, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f12.u32l;
    // 0x8002292C: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    // 0x80022930: swc1        $f29, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80022934: swc1        $f28, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f28.u32l;
    // 0x80022938: swc1        $f27, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002293C: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x80022940: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80022944: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x80022948: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002294C: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x80022950: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80022954: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80022958: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002295C: lbu         $t6, 0x11AE($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X11AE);
    // 0x80022960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80022964: bne         $t6, $at, L_80022974
    if (ctx->r14 != ctx->r1) {
        // 0x80022968: nop

            goto L_80022974;
    }
    // 0x80022968: nop

    // 0x8002296C: b           L_80022E14
    // 0x80022970: nop

        goto L_80022E14;
    // 0x80022970: nop

L_80022974:
    // 0x80022974: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80022978: lwc1        $f4, -0x7820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x8002297C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80022980: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022984: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80022988: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x8002298C: nop

    // 0x80022990: bc1f        L_80022A3C
    if (!c1cs) {
        // 0x80022994: nop

            goto L_80022A3C;
    }
    // 0x80022994: nop

    // 0x80022998: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002299C: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800229A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800229A4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800229A8: c.eq.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d == ctx->f18.d;
    // 0x800229AC: nop

    // 0x800229B0: bc1f        L_80022A3C
    if (!c1cs) {
        // 0x800229B4: nop

            goto L_80022A3C;
    }
    // 0x800229B4: nop

    // 0x800229B8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800229BC: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x800229C0: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x800229C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800229C8: nop

    // 0x800229CC: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800229D0: nop

    // 0x800229D4: bc1f        L_800229E4
    if (!c1cs) {
        // 0x800229D8: nop

            goto L_800229E4;
    }
    // 0x800229D8: nop

    // 0x800229DC: b           L_800229F8
    // 0x800229E0: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
        goto L_800229F8;
    // 0x800229E0: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
L_800229E4:
    // 0x800229E4: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800229E8: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x800229EC: lwc1        $f20, 0x10($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0X10);
    // 0x800229F0: nop

    // 0x800229F4: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f20.fl = -ctx->f20.fl;
L_800229F8:
    // 0x800229F8: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800229FC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80022A00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80022A04: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x80022A08: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80022A0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80022A10: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x80022A14: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x80022A18: nop

    // 0x80022A1C: bc1t        L_80022A3C
    if (c1cs) {
        // 0x80022A20: nop

            goto L_80022A3C;
    }
    // 0x80022A20: nop

    // 0x80022A24: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80022A28: lh          $t9, 0x2588($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X2588);
    // 0x80022A2C: nop

    // 0x80022A30: andi        $t0, $t9, 0x9
    ctx->r8 = ctx->r25 & 0X9;
    // 0x80022A34: beq         $t0, $zero, L_80022A4C
    if (ctx->r8 == 0) {
        // 0x80022A38: nop

            goto L_80022A4C;
    }
    // 0x80022A38: nop

L_80022A3C:
    // 0x80022A3C: jal         0x800228A8
    // 0x80022A40: nop

    func_800228A8(rdram, ctx);
        goto after_0;
    // 0x80022A40: nop

    after_0:
    // 0x80022A44: b           L_80022E14
    // 0x80022A48: nop

        goto L_80022E14;
    // 0x80022A48: nop

L_80022A4C:
    // 0x80022A4C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80022A50: lbu         $t1, 0x11AE($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X11AE);
    // 0x80022A54: nop

    // 0x80022A58: bne         $t1, $zero, L_80022AEC
    if (ctx->r9 != 0) {
        // 0x80022A5C: nop

            goto L_80022AEC;
    }
    // 0x80022A5C: nop

    // 0x80022A60: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80022A64: lw          $t2, 0x307C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X307C);
    // 0x80022A68: nop

    // 0x80022A6C: bne         $t2, $zero, L_80022AE4
    if (ctx->r10 != 0) {
        // 0x80022A70: nop

            goto L_80022AE4;
    }
    // 0x80022A70: nop

    // 0x80022A74: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80022A78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022A7C: sb          $t3, 0x11AE($at)
    MEM_B(0X11AE, ctx->r1) = ctx->r11;
    // 0x80022A80: lhu         $t4, 0xA6($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XA6);
    // 0x80022A84: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80022A88: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80022A8C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80022A90: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80022A94: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80022A98: lhu         $a0, -0x4772($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4772);
    // 0x80022A9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022AA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80022AA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80022AA8: jal         0x800AFB70
    // 0x80022AAC: sh          $t4, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r12;
    func_800AFB70(rdram, ctx);
        goto after_1;
    // 0x80022AAC: sh          $t4, 0x1644($at)
    MEM_H(0X1644, ctx->r1) = ctx->r12;
    after_1:
    // 0x80022AB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80022AB4: sw          $v0, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = ctx->r2;
    // 0x80022AB8: lhu         $a0, 0xA6($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XA6);
    // 0x80022ABC: jal         0x8002BB50
    // 0x80022AC0: nop

    func_8002BB50(rdram, ctx);
        goto after_2;
    // 0x80022AC0: nop

    after_2:
    // 0x80022AC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022AC8: swc1        $f0, 0x15D0($at)
    MEM_W(0X15D0, ctx->r1) = ctx->f0.u32l;
    // 0x80022ACC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80022AD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022AD4: swc1        $f6, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f6.u32l;
    // 0x80022AD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022ADC: b           L_80022AEC
    // 0x80022AE0: swc1        $f6, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f6.u32l;
        goto L_80022AEC;
    // 0x80022AE0: swc1        $f6, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f6.u32l;
L_80022AE4:
    // 0x80022AE4: b           L_80022E14
    // 0x80022AE8: nop

        goto L_80022E14;
    // 0x80022AE8: nop

L_80022AEC:
    // 0x80022AEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022AF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80022AF4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80022AF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022AFC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80022B00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022B04: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80022B08: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80022B0C: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80022B10: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x80022B14: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    // 0x80022B18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80022B1C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80022B20: jal         0x800B0E88
    // 0x80022B24: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    func_800B0E88(rdram, ctx);
        goto after_3;
    // 0x80022B24: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80022B28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022B2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80022B30: addiu       $t8, $sp, 0x68
    ctx->r24 = ADD32(ctx->r29, 0X68);
    // 0x80022B34: addiu       $t9, $sp, 0x68
    ctx->r25 = ADD32(ctx->r29, 0X68);
    // 0x80022B38: swc1        $f16, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f16.u32l;
    // 0x80022B3C: lwc1        $f20, 0x20($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0X20);
    // 0x80022B40: addiu       $t0, $sp, 0x68
    ctx->r8 = ADD32(ctx->r29, 0X68);
    // 0x80022B44: swc1        $f20, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f20.u32l;
    // 0x80022B48: swc1        $f20, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f20.u32l;
    // 0x80022B4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022B50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80022B54: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x80022B58: addiu       $t2, $sp, 0x68
    ctx->r10 = ADD32(ctx->r29, 0X68);
    // 0x80022B5C: swc1        $f18, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f18.u32l;
    // 0x80022B60: lwc1        $f6, 0x14($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80022B64: nop

    // 0x80022B68: swc1        $f6, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f6.u32l;
    // 0x80022B6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022B70: addiu       $t3, $sp, 0x68
    ctx->r11 = ADD32(ctx->r29, 0X68);
    // 0x80022B74: addiu       $t4, $sp, 0x68
    ctx->r12 = ADD32(ctx->r29, 0X68);
    // 0x80022B78: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x80022B7C: lwc1        $f28, 0x8($t4)
    ctx->f28.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80022B80: addiu       $t5, $sp, 0x68
    ctx->r13 = ADD32(ctx->r29, 0X68);
    // 0x80022B84: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x80022B88: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x80022B8C: swc1        $f28, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f28.u32l;
    // 0x80022B90: swc1        $f26, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f26.u32l;
    // 0x80022B94: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80022B98: addiu       $t6, $sp, 0x68
    ctx->r14 = ADD32(ctx->r29, 0X68);
    // 0x80022B9C: swc1        $f24, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f24.u32l;
    // 0x80022BA0: addiu       $t7, $sp, 0x68
    ctx->r15 = ADD32(ctx->r29, 0X68);
    // 0x80022BA4: swc1        $f22, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f22.u32l;
    // 0x80022BA8: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80022BAC: addiu       $t8, $sp, 0x68
    ctx->r24 = ADD32(ctx->r29, 0X68);
    // 0x80022BB0: swc1        $f20, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f20.u32l;
    // 0x80022BB4: addiu       $t9, $sp, 0x68
    ctx->r25 = ADD32(ctx->r29, 0X68);
    // 0x80022BB8: swc1        $f20, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f20.u32l;
    // 0x80022BBC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80022BC0: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    // 0x80022BC4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80022BC8: jal         0x800B1250
    // 0x80022BCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800B1250(rdram, ctx);
        goto after_4;
    // 0x80022BCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80022BD0: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80022BD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022BD8: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80022BDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022BE0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80022BE4: swc1        $f16, 0x1618($at)
    MEM_W(0X1618, ctx->r1) = ctx->f16.u32l;
    // 0x80022BE8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80022BEC: lw          $t0, 0x258C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X258C);
    // 0x80022BF0: nop

    // 0x80022BF4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80022BF8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80022BFC: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80022C00: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80022C04: bgez        $t1, L_80022C20
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80022C08: cvt.d.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
            goto L_80022C20;
    }
    // 0x80022C08: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x80022C0C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80022C10: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80022C14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022C18: nop

    // 0x80022C1C: add.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f6.d + ctx->f4.d;
L_80022C20:
    // 0x80022C20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022C24: lwc1        $f9, -0x1CD8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1CD8);
    // 0x80022C28: lwc1        $f8, -0x1CD4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1CD4);
    // 0x80022C2C: nop

    // 0x80022C30: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80022C34: jal         0x800C3070
    // 0x80022C38: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_5;
    // 0x80022C38: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    after_5:
    // 0x80022C3C: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x80022C40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80022C44: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80022C48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022C4C: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80022C50: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80022C54: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80022C58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022C5C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80022C60: swc1        $f10, 0x1624($at)
    MEM_W(0X1624, ctx->r1) = ctx->f10.u32l;
    // 0x80022C64: jal         0x800C1850
    // 0x80022C68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_6;
    // 0x80022C68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80022C6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022C70: lwc1        $f16, 0x1618($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1618);
    // 0x80022C74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022C78: lwc1        $f7, -0x1CD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1CD0);
    // 0x80022C7C: lwc1        $f6, -0x1CCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1CCC);
    // 0x80022C80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022C84: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1624);
    // 0x80022C88: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80022C8C: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80022C90: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80022C94: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80022C98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022C9C: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    // 0x80022CA0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80022CA4: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80022CA8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80022CAC: jal         0x800C2304
    // 0x80022CB0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_7;
    // 0x80022CB0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    after_7:
    // 0x80022CB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022CB8: lwc1        $f7, -0x1CC8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1CC8);
    // 0x80022CBC: lwc1        $f6, -0x1CC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1CC4);
    // 0x80022CC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022CC4: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80022CC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022CCC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80022CD0: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80022CD4: lwc1        $f16, 0x13C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x80022CD8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80022CDC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80022CE0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022CE4: sub.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f18.d - ctx->f10.d;
    // 0x80022CE8: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80022CEC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80022CF0: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x80022CF4: swc1        $f6, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f6.u32l;
    // 0x80022CF8: bc1f        L_80022D28
    if (!c1cs) {
        // 0x80022CFC: nop

            goto L_80022D28;
    }
    // 0x80022CFC: nop

    // 0x80022D00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D04: lwc1        $f18, 0x13C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x80022D08: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022D0C: lwc1        $f9, -0x1CC0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1CC0);
    // 0x80022D10: lwc1        $f8, -0x1CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1CBC);
    // 0x80022D14: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80022D18: add.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f6.d = ctx->f10.d + ctx->f8.d;
    // 0x80022D1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D20: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80022D24: swc1        $f4, 0x13C8($at)
    MEM_W(0X13C8, ctx->r1) = ctx->f4.u32l;
L_80022D28:
    // 0x80022D28: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80022D2C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80022D30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D34: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80022D38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022D3C: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x80022D40: mul.d       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80022D44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D48: lwc1        $f6, 0x1354($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x80022D4C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80022D50: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80022D54: sub.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = ctx->f4.d - ctx->f8.d;
    // 0x80022D58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80022D5C: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80022D60: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80022D64: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x80022D68: swc1        $f16, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f16.u32l;
    // 0x80022D6C: bc1f        L_80022D9C
    if (!c1cs) {
        // 0x80022D70: nop

            goto L_80022D9C;
    }
    // 0x80022D70: nop

    // 0x80022D74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D78: lwc1        $f4, 0x1354($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x80022D7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022D80: lwc1        $f19, -0x1CB8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1CB8);
    // 0x80022D84: lwc1        $f18, -0x1CB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1CB4);
    // 0x80022D88: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80022D8C: add.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = ctx->f8.d + ctx->f18.d;
    // 0x80022D90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022D94: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80022D98: swc1        $f10, 0x1354($at)
    MEM_W(0X1354, ctx->r1) = ctx->f10.u32l;
L_80022D9C:
    // 0x80022D9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022DA0: lwc1        $f12, 0x1354($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1354);
    // 0x80022DA4: jal         0x800C25B8
    // 0x80022DA8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_8;
    // 0x80022DA8: nop

    after_8:
    // 0x80022DAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022DB0: lwc1        $f6, 0x13C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X13C8);
    // 0x80022DB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80022DB8: lwc1        $f9, -0x1CB0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1CB0);
    // 0x80022DBC: lwc1        $f8, -0x1CAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1CAC);
    // 0x80022DC0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80022DC4: mul.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80022DC8: jal         0x800C3070
    // 0x80022DCC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_9;
    // 0x80022DCC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    after_9:
    // 0x80022DD0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80022DD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80022DD8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80022DDC: mul.s       $f12, $f20, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80022DE0: jal         0x800C2780
    // 0x80022DE4: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_10;
    // 0x80022DE4: nop

    after_10:
    // 0x80022DE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022DEC: lwc1        $f10, 0x15D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X15D0);
    // 0x80022DF0: nop

    // 0x80022DF4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80022DF8: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x80022DFC: jal         0x800C2948
    // 0x80022E00: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_11;
    // 0x80022E00: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
    after_11:
    // 0x80022E04: jal         0x8002D200
    // 0x80022E08: nop

    func_8002D200(rdram, ctx);
        goto after_12;
    // 0x80022E08: nop

    after_12:
    // 0x80022E0C: b           L_80022E14
    // 0x80022E10: nop

        goto L_80022E14;
    // 0x80022E10: nop

L_80022E14:
    // 0x80022E14: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80022E18: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80022E1C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80022E20: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80022E24: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022E28: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80022E2C: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80022E30: lwc1        $f27, 0x38($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80022E34: lwc1        $f26, 0x3C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80022E38: lwc1        $f29, 0x40($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80022E3C: lwc1        $f28, 0x44($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80022E40: jr          $ra
    // 0x80022E44: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80022E44: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80022E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022E50: sh          $zero, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = 0;
    // 0x80022E54: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80022E58: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80022E5C: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x80022E60: nop

    // 0x80022E64: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    // 0x80022E68: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80022E6C: lhu         $t9, 0x1258($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1258);
    // 0x80022E70: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x80022E74: nop

    // 0x80022E78: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80022E7C: bne         $t0, $zero, L_80022E9C
    if (ctx->r8 != 0) {
        // 0x80022E80: nop

            goto L_80022E9C;
    }
    // 0x80022E80: nop

    // 0x80022E84: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80022E88: lhu         $t1, 0x1042($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1042);
    // 0x80022E8C: nop

    // 0x80022E90: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x80022E94: beq         $t2, $zero, L_80022EC0
    if (ctx->r10 == 0) {
        // 0x80022E98: nop

            goto L_80022EC0;
    }
    // 0x80022E98: nop

L_80022E9C:
    // 0x80022E9C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80022EA0: lh          $t3, 0x66C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X66C);
    // 0x80022EA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80022EA8: bne         $t3, $at, L_80022EC0
    if (ctx->r11 != ctx->r1) {
        // 0x80022EAC: nop

            goto L_80022EC0;
    }
    // 0x80022EAC: nop

    // 0x80022EB0: jal         0x80055FB8
    // 0x80022EB4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80055FB8(rdram, ctx);
        goto after_0;
    // 0x80022EB4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x80022EB8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80022EBC: sh          $t4, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r12;
L_80022EC0:
    // 0x80022EC0: lh          $v0, 0x1C($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1C);
    // 0x80022EC4: b           L_80022ED4
    // 0x80022EC8: nop

        goto L_80022ED4;
    // 0x80022EC8: nop

    // 0x80022ECC: b           L_80022ED4
    // 0x80022ED0: nop

        goto L_80022ED4;
    // 0x80022ED0: nop

L_80022ED4:
    // 0x80022ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022ED8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022EDC: jr          $ra
    // 0x80022EE0: nop

    return;
    // 0x80022EE0: nop

;}
RECOMP_FUNC void func_80022EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022EE4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80022EE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80022EEC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80022EF0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80022EF4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80022EF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022EFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022F00: lwc1        $f4, 0x1264($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1264);
    // 0x80022F04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022F08: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80022F0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022F10: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80022F14: swc1        $f8, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->f8.u32l;
    // 0x80022F18: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80022F1C: lw          $t6, 0xCE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE8);
    // 0x80022F20: nop

    // 0x80022F24: addiu       $t7, $t6, 0x160
    ctx->r15 = ADD32(ctx->r14, 0X160);
    // 0x80022F28: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80022F2C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80022F30: lh          $t8, 0x654($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X654);
    // 0x80022F34: lh          $t9, 0x52($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X52);
    // 0x80022F38: nop

    // 0x80022F3C: beq         $t8, $t9, L_80023128
    if (ctx->r24 == ctx->r25) {
        // 0x80022F40: nop

            goto L_80023128;
    }
    // 0x80022F40: nop

    // 0x80022F44: jal         0x80096474
    // 0x80022F48: nop

    func_80096474(rdram, ctx);
        goto after_0;
    // 0x80022F48: nop

    after_0:
    // 0x80022F4C: jal         0x80090754
    // 0x80022F50: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_80090754(rdram, ctx);
        goto after_1;
    // 0x80022F50: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_1:
    // 0x80022F54: jal         0x80090728
    // 0x80022F58: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    func_80090728(rdram, ctx);
        goto after_2;
    // 0x80022F58: addiu       $a0, $zero, 0x410
    ctx->r4 = ADD32(0, 0X410);
    after_2:
    // 0x80022F5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022F60: jal         0x8008EAA8
    // 0x80022F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_3;
    // 0x80022F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80022F68: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80022F6C: lh          $t0, 0x67C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X67C);
    // 0x80022F70: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80022F74: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80022F78: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80022F7C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80022F80: lw          $t2, 0xCD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCD0);
    // 0x80022F84: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80022F88: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80022F8C: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80022F90: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x80022F94: sw          $s0, 0x128($t3)
    MEM_W(0X128, ctx->r11) = ctx->r16;
    // 0x80022F98: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80022F9C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80022FA0: lh          $t4, 0x67C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X67C);
    // 0x80022FA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80022FA8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80022FAC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80022FB0: sh          $t6, 0x67C($at)
    MEM_H(0X67C, ctx->r1) = ctx->r14;
    // 0x80022FB4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80022FB8: jal         0x8008ECCC
    // 0x80022FBC: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_4;
    // 0x80022FBC: nop

    after_4:
    // 0x80022FC0: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
L_80022FC4:
    // 0x80022FC4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80022FC8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80022FCC: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80022FD0: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80022FD4: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80022FD8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80022FDC: nop

    // 0x80022FE0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80022FE4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80022FE8: lh          $t2, 0x4E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4E);
    // 0x80022FEC: nop

    // 0x80022FF0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80022FF4: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80022FF8: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80022FFC: slti        $at, $t5, 0x64
    ctx->r1 = SIGNED(ctx->r13) < 0X64 ? 1 : 0;
    // 0x80023000: bne         $at, $zero, L_80022FC4
    if (ctx->r1 != 0) {
        // 0x80023004: sh          $t3, 0x4E($sp)
        MEM_H(0X4E, ctx->r29) = ctx->r11;
            goto L_80022FC4;
    }
    // 0x80023004: sh          $t3, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r11;
    // 0x80023008: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8002300C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80023010: sw          $t6, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r14;
    // 0x80023014: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80023018: sw          $zero, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = 0;
    // 0x8002301C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80023020: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80023024: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80023028: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002302C: jal         0x8008ECAC
    // 0x80023030: nop

    func_8008ECAC(rdram, ctx);
        goto after_5;
    // 0x80023030: nop

    after_5:
    // 0x80023034: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80023038: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002303C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80023040: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80023044: jal         0x8008EC8C
    // 0x80023048: nop

    func_8008EC8C(rdram, ctx);
        goto after_6;
    // 0x80023048: nop

    after_6:
    // 0x8002304C: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x80023050: nop

    // 0x80023054: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80023058: beq         $t9, $zero, L_80023070
    if (ctx->r25 == 0) {
        // 0x8002305C: nop

            goto L_80023070;
    }
    // 0x8002305C: nop

    // 0x80023060: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80023064: lw          $t7, 0x103C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X103C);
    // 0x80023068: b           L_8002308C
    // 0x8002306C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
        goto L_8002308C;
    // 0x8002306C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_80023070:
    // 0x80023070: lh          $t0, 0x52($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X52);
    // 0x80023074: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80023078: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002307C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80023080: lw          $t2, -0x41F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X41F8);
    // 0x80023084: nop

    // 0x80023088: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_8002308C:
    // 0x8002308C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80023090: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80023094: jal         0x8008ECE4
    // 0x80023098: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    func_8008ECE4(rdram, ctx);
        goto after_7;
    // 0x80023098: addiu       $a0, $a0, -0x1CE0
    ctx->r4 = ADD32(ctx->r4, -0X1CE0);
    after_7:
    // 0x8002309C: sh          $v0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r2;
    // 0x800230A0: lh          $t3, 0x4E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X4E);
    // 0x800230A4: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800230A8: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800230AC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800230B0: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x800230B4: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800230B8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800230BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800230C0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800230C4: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800230C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800230CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800230D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800230D4: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800230D8: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800230DC: swc1        $f10, 0xD58($at)
    MEM_W(0XD58, ctx->r1) = ctx->f10.u32l;
    // 0x800230E0: lh          $t6, 0x4E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4E);
    // 0x800230E4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800230E8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800230EC: lwc1        $f5, -0x1CA8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1CA8);
    // 0x800230F0: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800230F4: lwc1        $f4, -0x1CA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1CA4);
    // 0x800230F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800230FC: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80023100: lw          $t8, 0xCE8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XCE8);
    // 0x80023104: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80023108: swc1        $f8, 0xF4($t8)
    MEM_W(0XF4, ctx->r24) = ctx->f8.u32l;
    // 0x8002310C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023110: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
    // 0x80023114: lh          $t9, 0x52($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X52);
    // 0x80023118: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002311C: sh          $t9, 0x654($at)
    MEM_H(0X654, ctx->r1) = ctx->r25;
    // 0x80023120: jal         0x800967D8
    // 0x80023124: nop

    func_800967D8(rdram, ctx);
        goto after_8;
    // 0x80023124: nop

    after_8:
L_80023128:
    // 0x80023128: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002312C: lh          $t7, 0x65C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X65C);
    // 0x80023130: nop

    // 0x80023134: slti        $at, $t7, 0x78
    ctx->r1 = SIGNED(ctx->r15) < 0X78 ? 1 : 0;
    // 0x80023138: beq         $at, $zero, L_800234C0
    if (ctx->r1 == 0) {
        // 0x8002313C: nop

            goto L_800234C0;
    }
    // 0x8002313C: nop

    // 0x80023140: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023144: lwc1        $f10, 0x1264($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1264);
    // 0x80023148: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002314C: lwc1        $f19, -0x1CA0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1CA0);
    // 0x80023150: lwc1        $f18, -0x1C9C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1C9C);
    // 0x80023154: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80023158: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8002315C: jal         0x800C3070
    // 0x80023160: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_9;
    // 0x80023160: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_9:
    // 0x80023164: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80023168: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002316C: nop

    // 0x80023170: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80023174: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80023178: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002317C: lwc1        $f10, 0x1264($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1264);
    // 0x80023180: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80023184: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80023188: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002318C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80023190: lwc1        $f7, -0x1C98($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1C98);
    // 0x80023194: lwc1        $f6, -0x1C94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C94);
    // 0x80023198: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002319C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800231A0: jal         0x800C3070
    // 0x800231A4: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_10;
    // 0x800231A4: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_10:
    // 0x800231A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800231AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800231B0: nop

    // 0x800231B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800231B8: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x800231BC: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800231C0: nop

    // 0x800231C4: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800231C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800231CC: nop

    // 0x800231D0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800231D4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800231D8: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x800231DC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800231E0: lw          $t1, 0xC0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC0);
    // 0x800231E4: nop

    // 0x800231E8: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800231EC: sw          $t2, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r10;
    // 0x800231F0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800231F4: lh          $t4, 0x664($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X664);
    // 0x800231F8: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x800231FC: bne         $t4, $at, L_80023248
    if (ctx->r12 != ctx->r1) {
        // 0x80023200: nop

            goto L_80023248;
    }
    // 0x80023200: nop

    // 0x80023204: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80023208: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x8002320C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80023210: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023214: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80023218: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8002321C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80023220: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80023224: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80023228: lui         $at, 0x4050
    ctx->r1 = S32(0X4050 << 16);
    // 0x8002322C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80023230: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023234: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80023238: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8002323C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80023240: b           L_80023328
    // 0x80023244: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
        goto L_80023328;
    // 0x80023244: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
L_80023248:
    // 0x80023248: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002324C: lw          $t3, 0xCE8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XCE8);
    // 0x80023250: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80023254: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80023258: lwc1        $f18, 0xF4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XF4);
    // 0x8002325C: nop

    // 0x80023260: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80023264: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80023268: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002326C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80023270: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023274: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80023278: lwc1        $f5, -0x1C90($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1C90);
    // 0x8002327C: lwc1        $f4, -0x1C8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C8C);
    // 0x80023280: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80023284: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80023288: nop

    // 0x8002328C: bc1f        L_800232B0
    if (!c1cs) {
        // 0x80023290: nop

            goto L_800232B0;
    }
    // 0x80023290: nop

    // 0x80023294: lui         $at, 0xC302
    ctx->r1 = S32(0XC302 << 16);
    // 0x80023298: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002329C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800232A0: nop

    // 0x800232A4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800232A8: b           L_80023328
    // 0x800232AC: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
        goto L_80023328;
    // 0x800232AC: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
L_800232B0:
    // 0x800232B0: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800232B4: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800232B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800232BC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800232C0: lwc1        $f9, -0x1C88($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1C88);
    // 0x800232C4: lwc1        $f8, -0x1C84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1C84);
    // 0x800232C8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800232CC: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x800232D0: nop

    // 0x800232D4: bc1f        L_80023328
    if (!c1cs) {
        // 0x800232D8: nop

            goto L_80023328;
    }
    // 0x800232D8: nop

    // 0x800232DC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800232E0: lw          $t5, 0xCE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE8);
    // 0x800232E4: nop

    // 0x800232E8: lw          $t6, 0xC0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC0);
    // 0x800232EC: nop

    // 0x800232F0: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x800232F4: sw          $t8, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r24;
    // 0x800232F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800232FC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80023300: lwc1        $f11, -0x1C80($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1C80);
    // 0x80023304: lwc1        $f10, -0x1C7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1C7C);
    // 0x80023308: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8002330C: sub.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f10.d - ctx->f18.d;
    // 0x80023310: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80023314: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80023318: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8002331C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023320: nop

    // 0x80023324: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
L_80023328:
    // 0x80023328: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002332C: lwc1        $f10, 0xD58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XD58);
    // 0x80023330: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80023334: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80023338: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8002333C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80023340: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80023344: swc1        $f6, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f6.u32l;
    // 0x80023348: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002334C: lui         $at, 0x403F
    ctx->r1 = S32(0X403F << 16);
    // 0x80023350: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80023354: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023358: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002335C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80023360: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    // 0x80023364: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80023368: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002336C: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x80023370: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80023374: swc1        $f16, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f16.u32l;
    // 0x80023378: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8002337C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80023380: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80023384: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80023388: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8002338C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80023390: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x80023394: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80023398: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8002339C: add.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f10.d = ctx->f6.d + ctx->f16.d;
    // 0x800233A0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800233A4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800233A8: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x800233AC: lw          $t1, 0xCE8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XCE8);
    // 0x800233B0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800233B4: swc1        $f6, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f6.u32l;
    // 0x800233B8: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800233BC: lui         $at, 0x403C
    ctx->r1 = S32(0X403C << 16);
    // 0x800233C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800233C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800233C8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800233CC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800233D0: add.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = ctx->f4.d + ctx->f10.d;
    // 0x800233D4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800233D8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800233DC: add.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f16.d = ctx->f18.d + ctx->f6.d;
    // 0x800233E0: lw          $t2, 0xCE8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCE8);
    // 0x800233E4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x800233E8: swc1        $f4, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f4.u32l;
    // 0x800233EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800233F0: lwc1        $f10, 0x1264($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1264);
    // 0x800233F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800233F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800233FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023400: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80023404: lwc1        $f17, -0x1C78($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1C78);
    // 0x80023408: lwc1        $f16, -0x1C74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1C74);
    // 0x8002340C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80023410: mul.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80023414: jal         0x800C3070
    // 0x80023418: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    MathUtil_Sinf(rdram, ctx);
        goto after_11;
    // 0x80023418: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_11:
    // 0x8002341C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023420: lwc1        $f9, -0x1C70($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1C70);
    // 0x80023424: lwc1        $f8, -0x1C6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1C6C);
    // 0x80023428: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8002342C: mul.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80023430: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80023434: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80023438: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002343C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80023440: add.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f16.d = ctx->f18.d + ctx->f6.d;
    // 0x80023444: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x80023448: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8002344C: swc1        $f4, 0xFC($t0)
    MEM_W(0XFC, ctx->r8) = ctx->f4.u32l;
    // 0x80023450: jal         0x800C1850
    // 0x80023454: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_12;
    // 0x80023454: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80023458: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002345C: lw          $a0, 0xCE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE8);
    // 0x80023460: jal         0x8009A14C
    // 0x80023464: nop

    func_8009A14C(rdram, ctx);
        goto after_13;
    // 0x80023464: nop

    after_13:
    // 0x80023468: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8002346C: lw          $a0, 0xCE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XCE8);
    // 0x80023470: jal         0x800997D8
    // 0x80023474: nop

    func_800997D8(rdram, ctx);
        goto after_14;
    // 0x80023474: nop

    after_14:
    // 0x80023478: jal         0x800C1850
    // 0x8002347C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_15;
    // 0x8002347C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80023480: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80023484: jal         0x8009A14C
    // 0x80023488: nop

    func_8009A14C(rdram, ctx);
        goto after_16;
    // 0x80023488: nop

    after_16:
    // 0x8002348C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80023490: jal         0x800997D8
    // 0x80023494: nop

    func_800997D8(rdram, ctx);
        goto after_17;
    // 0x80023494: nop

    after_17:
    // 0x80023498: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002349C: lh          $t4, 0x65C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X65C);
    // 0x800234A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800234A4: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800234A8: sh          $t3, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = ctx->r11;
    // 0x800234AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800234B0: lbu         $t6, 0x125A($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X125A);
    // 0x800234B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800234B8: ori         $t8, $t6, 0x2
    ctx->r24 = ctx->r14 | 0X2;
    // 0x800234BC: sb          $t8, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = ctx->r24;
L_800234C0:
    // 0x800234C0: b           L_800234C8
    // 0x800234C4: nop

        goto L_800234C8;
    // 0x800234C4: nop

L_800234C8:
    // 0x800234C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800234CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800234D0: jr          $ra
    // 0x800234D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800234D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800234D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800234D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800234DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800234E0: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800234E4: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800234E8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800234EC: lw          $t7, 0xD70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD70);
    // 0x800234F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800234F4: sh          $t6, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r14;
    // 0x800234F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800234FC: lw          $t8, 0xD70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD70);
    // 0x80023500: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80023504: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x80023508: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002350C: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80023510: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80023514: lw          $t1, 0x24F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X24F0);
    // 0x80023518: nop

    // 0x8002351C: lh          $t2, 0x102($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X102);
    // 0x80023520: nop

    // 0x80023524: sw          $t2, 0x1B50($at)
    MEM_W(0X1B50, ctx->r1) = ctx->r10;
    // 0x80023528: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002352C: lw          $t3, 0xD70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD70);
    // 0x80023530: nop

    // 0x80023534: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80023538: nop

    // 0x8002353C: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80023540: lhu         $t5, 0x2E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2E);
    // 0x80023544: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80023548: beq         $t5, $at, L_8002355C
    if (ctx->r13 == ctx->r1) {
        // 0x8002354C: nop

            goto L_8002355C;
    }
    // 0x8002354C: nop

    // 0x80023550: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80023554: bne         $t5, $at, L_800235A8
    if (ctx->r13 != ctx->r1) {
        // 0x80023558: nop

            goto L_800235A8;
    }
    // 0x80023558: nop

L_8002355C:
    // 0x8002355C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80023560: lw          $t6, 0x1B50($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B50);
    // 0x80023564: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80023568: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8002356C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80023570: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80023574: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023578: nop

    // 0x8002357C: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80023580: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80023584: nop

    // 0x80023588: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002358C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80023590: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80023594: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80023598: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x8002359C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800235A0: swc1        $f16, 0x1B50($at)
    MEM_W(0X1B50, ctx->r1) = ctx->f16.u32l;
    // 0x800235A4: nop

L_800235A8:
    // 0x800235A8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800235AC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800235B0: lw          $t9, 0xD70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD70);
    // 0x800235B4: lw          $t8, 0x1B50($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1B50);
    // 0x800235B8: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800235BC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800235C0: lw          $a3, 0x8($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X8);
    // 0x800235C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800235C8: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800235CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800235D0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800235D4: addiu       $t0, $t0, 0xD78
    ctx->r8 = ADD32(ctx->r8, 0XD78);
    // 0x800235D8: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800235DC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800235E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800235E4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800235E8: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800235EC: jal         0x800C3D70
    // 0x800235F0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C3D70(rdram, ctx);
        goto after_0;
    // 0x800235F0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800235F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800235F8: lwc1        $f16, 0xD90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XD90);
    // 0x800235FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023600: lwc1        $f19, -0x1C68($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X1C68);
    // 0x80023604: lwc1        $f18, -0x1C64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1C64);
    // 0x80023608: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002360C: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80023610: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023614: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80023618: swc1        $f8, 0xD98($at)
    MEM_W(0XD98, ctx->r1) = ctx->f8.u32l;
    // 0x8002361C: b           L_80023624
    // 0x80023620: nop

        goto L_80023624;
    // 0x80023620: nop

L_80023624:
    // 0x80023624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80023628: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002362C: jr          $ra
    // 0x80023630: nop

    return;
    // 0x80023630: nop

;}
RECOMP_FUNC void func_80023634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023634: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80023638: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002363C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023640: swc1        $f4, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f4.u32l;
    // 0x80023644: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023648: swc1        $f4, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f4.u32l;
    // 0x8002364C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80023650: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x80023654: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80023658: nop

    // 0x8002365C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80023660: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80023664: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80023668: lwc1        $f8, 0x14($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X14);
    // 0x8002366C: nop

    // 0x80023670: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80023674: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80023678: nop

    // 0x8002367C: sh          $t8, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r24;
    // 0x80023680: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80023684: lh          $t9, 0x66C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X66C);
    // 0x80023688: nop

    // 0x8002368C: beq         $t9, $zero, L_800236B4
    if (ctx->r25 == 0) {
        // 0x80023690: nop

            goto L_800236B4;
    }
    // 0x80023690: nop

    // 0x80023694: lh          $t0, 0x12($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X12);
    // 0x80023698: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8002369C: beq         $t0, $at, L_800236B0
    if (ctx->r8 == ctx->r1) {
        // 0x800236A0: nop

            goto L_800236B0;
    }
    // 0x800236A0: nop

    // 0x800236A4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800236A8: bne         $t0, $at, L_800236B4
    if (ctx->r8 != ctx->r1) {
        // 0x800236AC: nop

            goto L_800236B4;
    }
    // 0x800236AC: nop

L_800236B0:
    // 0x800236B0: sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
L_800236B4:
    // 0x800236B4: lw          $t1, 0x20C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20C);
    // 0x800236B8: nop

    // 0x800236BC: lh          $t2, 0x24($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X24);
    // 0x800236C0: nop

    // 0x800236C4: sh          $t2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r10;
    // 0x800236C8: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800236CC: nop

    // 0x800236D0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800236D4: lwc1        $f10, 0x1B0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x800236D8: nop

    // 0x800236DC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800236E0: lwc1        $f16, 0x1B4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x800236E4: nop

    // 0x800236E8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800236EC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800236F0: lbu         $a3, 0x127D($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X127D);
    // 0x800236F4: nop

    // 0x800236F8: beq         $a3, $zero, L_80023720
    if (ctx->r7 == 0) {
        // 0x800236FC: nop

            goto L_80023720;
    }
    // 0x800236FC: nop

    // 0x80023700: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023704: beq         $a3, $at, L_80023738
    if (ctx->r7 == ctx->r1) {
        // 0x80023708: nop

            goto L_80023738;
    }
    // 0x80023708: nop

    // 0x8002370C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023710: beq         $a3, $at, L_80023750
    if (ctx->r7 == ctx->r1) {
        // 0x80023714: nop

            goto L_80023750;
    }
    // 0x80023714: nop

    // 0x80023718: b           L_80023768
    // 0x8002371C: nop

        goto L_80023768;
    // 0x8002371C: nop

L_80023720:
    // 0x80023720: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023724: lwc1        $f18, -0x1C60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1C60);
    // 0x80023728: nop

    // 0x8002372C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80023730: b           L_80023768
    // 0x80023734: nop

        goto L_80023768;
    // 0x80023734: nop

L_80023738:
    // 0x80023738: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002373C: lwc1        $f4, -0x1C5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C5C);
    // 0x80023740: nop

    // 0x80023744: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80023748: b           L_80023768
    // 0x8002374C: nop

        goto L_80023768;
    // 0x8002374C: nop

L_80023750:
    // 0x80023750: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80023754: lwc1        $f6, -0x1C58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C58);
    // 0x80023758: nop

    // 0x8002375C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80023760: b           L_80023768
    // 0x80023764: nop

        goto L_80023768;
    // 0x80023764: nop

L_80023768:
    // 0x80023768: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002376C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023770: nop

    // 0x80023774: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80023778: nop

    // 0x8002377C: bc1f        L_8002378C
    if (!c1cs) {
        // 0x80023780: nop

            goto L_8002378C;
    }
    // 0x80023780: nop

    // 0x80023784: b           L_80023798
    // 0x80023788: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
        goto L_80023798;
    // 0x80023788: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
L_8002378C:
    // 0x8002378C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80023790: nop

    // 0x80023794: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f12.fl = -ctx->f12.fl;
L_80023798:
    // 0x80023798: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8002379C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800237A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800237A4: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800237A8: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x800237AC: nop

    // 0x800237B0: bc1f        L_800238D8
    if (!c1cs) {
        // 0x800237B4: nop

            goto L_800238D8;
    }
    // 0x800237B4: nop

    // 0x800237B8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800237BC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800237C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800237C4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800237C8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800237CC: nop

    // 0x800237D0: bc1f        L_800237E0
    if (!c1cs) {
        // 0x800237D4: nop

            goto L_800237E0;
    }
    // 0x800237D4: nop

    // 0x800237D8: b           L_800237F4
    // 0x800237DC: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
        goto L_800237F4;
    // 0x800237DC: mov.s       $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = ctx->f10.fl;
L_800237E0:
    // 0x800237E0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800237E4: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800237E8: nop

    // 0x800237EC: mul.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800237F0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f14.fl = -ctx->f14.fl;
L_800237F4:
    // 0x800237F4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800237F8: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x800237FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80023800: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023804: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80023808: nop

    // 0x8002380C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80023810: cvt.d.s     $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f16.d = CVT_D_S(ctx->f14.fl);
    // 0x80023814: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023818: lwc1        $f4, 0x1020($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1020);
    // 0x8002381C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023820: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80023824: mul.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80023828: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002382C: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80023830: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80023834: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023838: swc1        $f12, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f12.u32l;
    // 0x8002383C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023840: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80023844: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x80023848: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8002384C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80023850: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80023854: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80023858: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8002385C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80023860: bc1f        L_80023888
    if (!c1cs) {
        // 0x80023864: nop

            goto L_80023888;
    }
    // 0x80023864: nop

    // 0x80023868: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8002386C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023870: nop

    // 0x80023874: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80023878: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002387C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023880: b           L_800238D8
    // 0x80023884: swc1        $f16, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f16.u32l;
        goto L_800238D8;
    // 0x80023884: swc1        $f16, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f16.u32l;
L_80023888:
    // 0x80023888: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002388C: lwc1        $f18, -0x71C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x80023890: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80023894: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80023898: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002389C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800238A0: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800238A4: nop

    // 0x800238A8: bc1f        L_800238D8
    if (!c1cs) {
        // 0x800238AC: nop

            goto L_800238D8;
    }
    // 0x800238AC: nop

    // 0x800238B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800238B4: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x800238B8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800238BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800238C0: nop

    // 0x800238C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800238C8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800238CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800238D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800238D4: swc1        $f6, 0xE48($at)
    MEM_W(0XE48, ctx->r1) = ctx->f6.u32l;
L_800238D8:
    // 0x800238D8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800238DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800238E0: nop

    // 0x800238E4: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800238E8: nop

    // 0x800238EC: bc1f        L_800238FC
    if (!c1cs) {
        // 0x800238F0: nop

            goto L_800238FC;
    }
    // 0x800238F0: nop

    // 0x800238F4: b           L_80023908
    // 0x800238F8: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
        goto L_80023908;
    // 0x800238F8: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
L_800238FC:
    // 0x800238FC: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023900: nop

    // 0x80023904: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f12.fl = -ctx->f12.fl;
L_80023908:
    // 0x80023908: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x8002390C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80023910: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80023914: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80023918: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x8002391C: nop

    // 0x80023920: bc1f        L_80023AC0
    if (!c1cs) {
        // 0x80023924: nop

            goto L_80023AC0;
    }
    // 0x80023924: nop

    // 0x80023928: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002392C: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80023930: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023934: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80023938: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8002393C: nop

    // 0x80023940: bc1f        L_80023950
    if (!c1cs) {
        // 0x80023944: nop

            goto L_80023950;
    }
    // 0x80023944: nop

    // 0x80023948: b           L_80023964
    // 0x8002394C: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
        goto L_80023964;
    // 0x8002394C: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
L_80023950:
    // 0x80023950: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023954: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80023958: nop

    // 0x8002395C: mul.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80023960: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f14.fl = -ctx->f14.fl;
L_80023964:
    // 0x80023964: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023968: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x8002396C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80023970: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023974: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80023978: nop

    // 0x8002397C: div.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f4.d);
    // 0x80023980: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80023984: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023988: lwc1        $f18, 0x1020($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1020);
    // 0x8002398C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023990: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80023994: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80023998: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002399C: mul.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x800239A0: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800239A4: swc1        $f12, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f12.u32l;
    // 0x800239A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800239AC: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800239B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800239B4: mul.s       $f18, $f12, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800239B8: lwc1        $f5, -0x1C50($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1C50);
    // 0x800239BC: lwc1        $f4, -0x1C4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C4C);
    // 0x800239C0: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800239C4: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x800239C8: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800239CC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800239D0: bc1f        L_800239F8
    if (!c1cs) {
        // 0x800239D4: nop

            goto L_800239F8;
    }
    // 0x800239D4: nop

    // 0x800239D8: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x800239DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800239E0: nop

    // 0x800239E4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800239E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800239EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800239F0: b           L_80023A38
    // 0x800239F4: swc1        $f10, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f10.u32l;
        goto L_80023A38;
    // 0x800239F4: swc1        $f10, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f10.u32l;
L_800239F8:
    // 0x800239F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800239FC: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80023A00: lwc1        $f7, -0x1C48($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1C48);
    // 0x80023A04: lwc1        $f6, -0x1C44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C44);
    // 0x80023A08: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80023A0C: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x80023A10: nop

    // 0x80023A14: bc1f        L_80023A38
    if (!c1cs) {
        // 0x80023A18: nop

            goto L_80023A38;
    }
    // 0x80023A18: nop

    // 0x80023A1C: lui         $at, 0xC302
    ctx->r1 = S32(0XC302 << 16);
    // 0x80023A20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80023A24: nop

    // 0x80023A28: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80023A2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023A30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023A34: swc1        $f8, 0xDA0($at)
    MEM_W(0XDA0, ctx->r1) = ctx->f8.u32l;
L_80023A38:
    // 0x80023A38: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023A3C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80023A40: nop

    // 0x80023A44: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80023A48: nop

    // 0x80023A4C: bc1f        L_80023A7C
    if (!c1cs) {
        // 0x80023A50: nop

            goto L_80023A7C;
    }
    // 0x80023A50: nop

    // 0x80023A54: lh          $t4, 0x10($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X10);
    // 0x80023A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023A5C: bne         $t4, $at, L_80023A7C
    if (ctx->r12 != ctx->r1) {
        // 0x80023A60: nop

            goto L_80023A7C;
    }
    // 0x80023A60: nop

    // 0x80023A64: sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    // 0x80023A68: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80023A6C: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80023A70: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80023A74: b           L_80023AC0
    // 0x80023A78: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
        goto L_80023AC0;
    // 0x80023A78: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
L_80023A7C:
    // 0x80023A7C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023A80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80023A84: nop

    // 0x80023A88: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80023A8C: nop

    // 0x80023A90: bc1f        L_80023AC0
    if (!c1cs) {
        // 0x80023A94: nop

            goto L_80023AC0;
    }
    // 0x80023A94: nop

    // 0x80023A98: lh          $t7, 0x10($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X10);
    // 0x80023A9C: nop

    // 0x80023AA0: bne         $t7, $zero, L_80023AC0
    if (ctx->r15 != 0) {
        // 0x80023AA4: nop

            goto L_80023AC0;
    }
    // 0x80023AA4: nop

    // 0x80023AA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80023AAC: sh          $t8, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r24;
    // 0x80023AB0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80023AB4: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80023AB8: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80023ABC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
L_80023AC0:
    // 0x80023AC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023AC4: lwc1        $f4, 0xDA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XDA0);
    // 0x80023AC8: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80023ACC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023AD0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80023AD4: c.eq.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d == ctx->f10.d;
    // 0x80023AD8: nop

    // 0x80023ADC: bc1f        L_80023B08
    if (!c1cs) {
        // 0x80023AE0: nop

            goto L_80023B08;
    }
    // 0x80023AE0: nop

    // 0x80023AE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023AE8: lwc1        $f18, 0xE48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XE48);
    // 0x80023AEC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80023AF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80023AF4: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80023AF8: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x80023AFC: nop

    // 0x80023B00: bc1t        L_80023B38
    if (c1cs) {
        // 0x80023B04: nop

            goto L_80023B38;
    }
    // 0x80023B04: nop

L_80023B08:
    // 0x80023B08: lh          $t1, 0x12($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X12);
    // 0x80023B0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023B10: beq         $t1, $at, L_80023B30
    if (ctx->r9 == ctx->r1) {
        // 0x80023B14: nop

            goto L_80023B30;
    }
    // 0x80023B14: nop

    // 0x80023B18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80023B1C: sh          $t2, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r10;
    // 0x80023B20: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x80023B24: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80023B28: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x80023B2C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
L_80023B30:
    // 0x80023B30: b           L_80023B94
    // 0x80023B34: nop

        goto L_80023B94;
    // 0x80023B34: nop

L_80023B38:
    // 0x80023B38: lh          $t5, 0x12($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X12);
    // 0x80023B3C: nop

    // 0x80023B40: beq         $t5, $zero, L_80023B94
    if (ctx->r13 == 0) {
        // 0x80023B44: nop

            goto L_80023B94;
    }
    // 0x80023B44: nop

    // 0x80023B48: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80023B4C: nop

    // 0x80023B50: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80023B54: bne         $t7, $zero, L_80023B94
    if (ctx->r15 != 0) {
        // 0x80023B58: nop

            goto L_80023B94;
    }
    // 0x80023B58: nop

    // 0x80023B5C: sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    // 0x80023B60: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80023B64: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80023B68: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80023B6C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80023B70: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80023B74: lh          $t0, 0x66C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X66C);
    // 0x80023B78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023B7C: bne         $t0, $at, L_80023B94
    if (ctx->r8 != ctx->r1) {
        // 0x80023B80: nop

            goto L_80023B94;
    }
    // 0x80023B80: nop

    // 0x80023B84: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80023B88: nop

    // 0x80023B8C: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80023B90: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
L_80023B94:
    // 0x80023B94: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80023B98: lh          $t3, 0x664($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X664);
    // 0x80023B9C: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80023BA0: bne         $t3, $at, L_80023BC4
    if (ctx->r11 != ctx->r1) {
        // 0x80023BA4: nop

            goto L_80023BC4;
    }
    // 0x80023BA4: nop

    // 0x80023BA8: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80023BAC: nop

    // 0x80023BB0: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80023BB4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80023BB8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80023BBC: b           L_80023C10
    // 0x80023BC0: sh          $t6, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r14;
        goto L_80023C10;
    // 0x80023BC0: sh          $t6, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r14;
L_80023BC4:
    // 0x80023BC4: lh          $t7, 0x12($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X12);
    // 0x80023BC8: nop

    // 0x80023BCC: bne         $t7, $zero, L_80023C10
    if (ctx->r15 != 0) {
        // 0x80023BD0: nop

            goto L_80023C10;
    }
    // 0x80023BD0: nop

    // 0x80023BD4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80023BD8: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x80023BDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023BE0: bne         $t8, $at, L_80023BF4
    if (ctx->r24 != ctx->r1) {
        // 0x80023BE4: nop

            goto L_80023BF4;
    }
    // 0x80023BE4: nop

    // 0x80023BE8: addiu       $t9, $zero, 0x12
    ctx->r25 = ADD32(0, 0X12);
    // 0x80023BEC: b           L_80023C10
    // 0x80023BF0: sh          $t9, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r25;
        goto L_80023C10;
    // 0x80023BF0: sh          $t9, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r25;
L_80023BF4:
    // 0x80023BF4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80023BF8: lh          $t0, 0x66C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X66C);
    // 0x80023BFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023C00: bne         $t0, $at, L_80023C10
    if (ctx->r8 != ctx->r1) {
        // 0x80023C04: nop

            goto L_80023C10;
    }
    // 0x80023C04: nop

    // 0x80023C08: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x80023C0C: sh          $t1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r9;
L_80023C10:
    // 0x80023C10: lh          $t2, 0x12($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X12);
    // 0x80023C14: nop

    // 0x80023C18: sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
    // 0x80023C1C: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x80023C20: nop

    // 0x80023C24: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80023C28: lh          $t4, 0x10($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X10);
    // 0x80023C2C: lw          $t5, 0x20C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X20C);
    // 0x80023C30: nop

    // 0x80023C34: sh          $t4, 0x24($t5)
    MEM_H(0X24, ctx->r13) = ctx->r12;
    // 0x80023C38: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80023C3C: nop

    // 0x80023C40: swc1        $f4, 0x1B0($a0)
    MEM_W(0X1B0, ctx->r4) = ctx->f4.u32l;
    // 0x80023C44: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80023C48: nop

    // 0x80023C4C: swc1        $f8, 0x1B4($a0)
    MEM_W(0X1B4, ctx->r4) = ctx->f8.u32l;
    // 0x80023C50: b           L_80023C58
    // 0x80023C54: nop

        goto L_80023C58;
    // 0x80023C54: nop

L_80023C58:
    // 0x80023C58: jr          $ra
    // 0x80023C5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80023C5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80023C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023C60: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80023C64: lh          $t6, 0xFF6($t6)
    ctx->r14 = MEM_H(ctx->r14, 0XFF6);
    // 0x80023C68: nop

    // 0x80023C6C: beq         $t6, $zero, L_80023C88
    if (ctx->r14 == 0) {
        // 0x80023C70: nop

            goto L_80023C88;
    }
    // 0x80023C70: nop

    // 0x80023C74: addiu       $t7, $zero, 0x3E7
    ctx->r15 = ADD32(0, 0X3E7);
    // 0x80023C78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023C7C: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x80023C80: jr          $ra
    // 0x80023C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80023C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80023C88:
    // 0x80023C88: jr          $ra
    // 0x80023C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80023C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80023C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023C90: jr          $ra
    // 0x80023C94: nop

    return;
    // 0x80023C94: nop

    // 0x80023C98: jr          $ra
    // 0x80023C9C: nop

    return;
    // 0x80023C9C: nop

;}
RECOMP_FUNC void func_80023CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023CA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80023CAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80023CB0: lh          $t6, 0x2588($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2588);
    // 0x80023CB4: addiu       $at, $zero, -0x25
    ctx->r1 = ADD32(0, -0X25);
    // 0x80023CB8: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80023CBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023CC0: sh          $t7, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r15;
    // 0x80023CC4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80023CC8: lh          $t8, 0x664($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X664);
    // 0x80023CCC: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x80023CD0: beq         $t8, $at, L_80023E38
    if (ctx->r24 == ctx->r1) {
        // 0x80023CD4: nop

            goto L_80023E38;
    }
    // 0x80023CD4: nop

    // 0x80023CD8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80023CDC: lhu         $t9, 0x126C($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X126C);
    // 0x80023CE0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80023CE4: nop

    // 0x80023CE8: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x80023CEC: beq         $t1, $zero, L_80023D60
    if (ctx->r9 == 0) {
        // 0x80023CF0: nop

            goto L_80023D60;
    }
    // 0x80023CF0: nop

    // 0x80023CF4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80023CF8: lh          $t2, 0x2588($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X2588);
    // 0x80023CFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023D00: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80023D04: sh          $t3, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r11;
    // 0x80023D08: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023D0C: lwc1        $f4, -0x7820($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80023D10: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80023D14: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023D18: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80023D1C: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x80023D20: nop

    // 0x80023D24: bc1f        L_80023D58
    if (!c1cs) {
        // 0x80023D28: nop

            goto L_80023D58;
    }
    // 0x80023D28: nop

    // 0x80023D2C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023D30: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80023D34: jal         0x8002A0F8
    // 0x80023D38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_0;
    // 0x80023D38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80023D3C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80023D40: bne         $at, $zero, L_80023D58
    if (ctx->r1 != 0) {
        // 0x80023D44: nop

            goto L_80023D58;
    }
    // 0x80023D44: nop

    // 0x80023D48: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80023D4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023D50: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023D54: swc1        $f10, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f10.u32l;
L_80023D58:
    // 0x80023D58: b           L_80023E38
    // 0x80023D5C: nop

        goto L_80023E38;
    // 0x80023D5C: nop

L_80023D60:
    // 0x80023D60: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80023D64: lhu         $t4, 0x1260($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1260);
    // 0x80023D68: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80023D6C: nop

    // 0x80023D70: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80023D74: beq         $t6, $zero, L_80023E38
    if (ctx->r14 == 0) {
        // 0x80023D78: nop

            goto L_80023E38;
    }
    // 0x80023D78: nop

    // 0x80023D7C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80023D80: lh          $t7, 0x2588($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2588);
    // 0x80023D84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80023D88: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80023D8C: sh          $t8, 0x2588($at)
    MEM_H(0X2588, ctx->r1) = ctx->r24;
    // 0x80023D90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023D94: lwc1        $f16, -0x7820($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80023D98: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80023D9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80023DA0: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80023DA4: c.eq.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d == ctx->f4.d;
    // 0x80023DA8: nop

    // 0x80023DAC: bc1f        L_80023E38
    if (!c1cs) {
        // 0x80023DB0: nop

            goto L_80023E38;
    }
    // 0x80023DB0: nop

    // 0x80023DB4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023DB8: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80023DBC: jal         0x8002A0F8
    // 0x80023DC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002A0F8(rdram, ctx);
        goto after_1;
    // 0x80023DC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80023DC4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80023DC8: bne         $at, $zero, L_80023E38
    if (ctx->r1 != 0) {
        // 0x80023DCC: nop

            goto L_80023E38;
    }
    // 0x80023DCC: nop

    // 0x80023DD0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023DD4: lwc1        $f6, -0x7820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80023DD8: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80023DDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80023DE0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80023DE4: c.eq.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d == ctx->f10.d;
    // 0x80023DE8: nop

    // 0x80023DEC: bc1f        L_80023E38
    if (!c1cs) {
        // 0x80023DF0: nop

            goto L_80023E38;
    }
    // 0x80023DF0: nop

    // 0x80023DF4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80023DF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80023DFC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80023E00: swc1        $f16, -0x7820($at)
    MEM_W(-0X7820, ctx->r1) = ctx->f16.u32l;
    // 0x80023E04: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80023E08: lw          $t9, 0x3074($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3074);
    // 0x80023E0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80023E10: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80023E14: nop

    // 0x80023E18: sw          $t0, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r8;
    // 0x80023E1C: jal         0x80029ED8
    // 0x80023E20: nop

    func_80029ED8(rdram, ctx);
        goto after_2;
    // 0x80023E20: nop

    after_2:
    // 0x80023E24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80023E28: jal         0x8002A22C
    // 0x80023E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002A22C(rdram, ctx);
        goto after_3;
    // 0x80023E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80023E30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80023E34: sw          $v0, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r2;
L_80023E38:
    // 0x80023E38: b           L_80023E40
    // 0x80023E3C: nop

        goto L_80023E40;
    // 0x80023E3C: nop

L_80023E40:
    // 0x80023E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023E48: jr          $ra
    // 0x80023E4C: nop

    return;
    // 0x80023E4C: nop

;}
RECOMP_FUNC void func_80023E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E50: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80023E54: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80023E58: lw          $t6, 0x306C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X306C);
    // 0x80023E5C: nop

    // 0x80023E60: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80023E64: nop

    // 0x80023E68: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80023E6C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80023E70: lh          $t8, 0x1B48($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X1B48);
    // 0x80023E74: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x80023E78: blez        $t8, L_80023EB8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80023E7C: nop

            goto L_80023EB8;
    }
    // 0x80023E7C: nop

L_80023E80:
    // 0x80023E80: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80023E84: nop

    // 0x80023E88: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x80023E8C: nop

    // 0x80023E90: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x80023E94: lh          $t1, 0x6($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6);
    // 0x80023E98: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80023E9C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80023EA0: lh          $t5, 0x1B48($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X1B48);
    // 0x80023EA4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80023EA8: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80023EAC: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80023EB0: bne         $at, $zero, L_80023E80
    if (ctx->r1 != 0) {
        // 0x80023EB4: sh          $t2, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r10;
            goto L_80023E80;
    }
    // 0x80023EB4: sh          $t2, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r10;
L_80023EB8:
    // 0x80023EB8: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80023EBC: b           L_80023ECC
    // 0x80023EC0: nop

        goto L_80023ECC;
    // 0x80023EC0: nop

    // 0x80023EC4: b           L_80023ECC
    // 0x80023EC8: nop

        goto L_80023ECC;
    // 0x80023EC8: nop

L_80023ECC:
    // 0x80023ECC: jr          $ra
    // 0x80023ED0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80023ED0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80023ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023ED4: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x80023ED8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80023EDC: sw          $a0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r4;
    // 0x80023EE0: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80023EE4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80023EE8: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80023EEC: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x80023EF0: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80023EF4: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80023EF8: sh          $zero, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = 0;
    // 0x80023EFC: sh          $zero, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = 0;
    // 0x80023F00: sw          $zero, 0x120($sp)
    MEM_W(0X120, ctx->r29) = 0;
    // 0x80023F04: jal         0x800C1680
    // 0x80023F08: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x80023F08: nop

    after_0:
    // 0x80023F0C: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x80023F10: nop

    // 0x80023F14: lwc1        $f4, 0x1B0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1B0);
    // 0x80023F18: nop

    // 0x80023F1C: swc1        $f4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f4.u32l;
    // 0x80023F20: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x80023F24: nop

    // 0x80023F28: lwc1        $f6, 0x1B4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1B4);
    // 0x80023F2C: nop

    // 0x80023F30: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80023F34: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x80023F38: nop

    // 0x80023F3C: lw          $t9, 0x20C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20C);
    // 0x80023F40: nop

    // 0x80023F44: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x80023F48: lw          $t0, 0x140($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X140);
    // 0x80023F4C: nop

    // 0x80023F50: lw          $t1, 0x210($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X210);
    // 0x80023F54: nop

    // 0x80023F58: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x80023F5C: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x80023F60: nop

    // 0x80023F64: lw          $t3, 0x214($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X214);
    // 0x80023F68: nop

    // 0x80023F6C: sw          $t3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r11;
    // 0x80023F70: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80023F74: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80023F78: jal         0x8002A0F8
    // 0x80023F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_1;
    // 0x80023F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80023F80: sh          $v0, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r2;
    // 0x80023F84: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80023F88: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80023F8C: lhu         $t5, 0x1042($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X1042);
    // 0x80023F90: lhu         $t4, 0x1258($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1258);
    // 0x80023F94: nop

    // 0x80023F98: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80023F9C: sh          $t6, 0x116($sp)
    MEM_H(0X116, ctx->r29) = ctx->r14;
    // 0x80023FA0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80023FA4: lhu         $t7, 0x126E($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X126E);
    // 0x80023FA8: nop

    // 0x80023FAC: beq         $t7, $zero, L_8002406C
    if (ctx->r15 == 0) {
        // 0x80023FB0: nop

            goto L_8002406C;
    }
    // 0x80023FB0: nop

    // 0x80023FB4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80023FB8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80023FBC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80023FC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80023FC4: nop

    // 0x80023FC8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80023FCC: swc1        $f8, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f8.u32l;
    // 0x80023FD0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80023FD4: swc1        $f8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f8.u32l;
    // 0x80023FD8: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80023FDC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80023FE0: beq         $t9, $zero, L_80024034
    if (ctx->r25 == 0) {
        // 0x80023FE4: nop

            goto L_80024034;
    }
    // 0x80023FE4: nop

    // 0x80023FE8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80023FEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023FF0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80023FF4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80023FF8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80023FFC: nop

    // 0x80024000: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80024004: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80024008: nop

    // 0x8002400C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80024010: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80024014: bne         $t9, $zero, L_8002402C
    if (ctx->r25 != 0) {
        // 0x80024018: nop

            goto L_8002402C;
    }
    // 0x80024018: nop

    // 0x8002401C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80024020: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024024: b           L_80024044
    // 0x80024028: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80024044;
    // 0x80024028: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8002402C:
    // 0x8002402C: b           L_80024044
    // 0x80024030: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80024044;
    // 0x80024030: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80024034:
    // 0x80024034: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80024038: nop

    // 0x8002403C: bltz        $t9, L_8002402C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80024040: nop

            goto L_8002402C;
    }
    // 0x80024040: nop

L_80024044:
    // 0x80024044: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80024048: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8002404C: sh          $t0, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r8;
    // 0x80024050: sh          $t9, 0x118($sp)
    MEM_H(0X118, ctx->r29) = ctx->r25;
    // 0x80024054: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80024058: lhu         $t1, 0x126E($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X126E);
    // 0x8002405C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024060: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80024064: b           L_800240E4
    // 0x80024068: sh          $t2, 0x126E($at)
    MEM_H(0X126E, ctx->r1) = ctx->r10;
        goto L_800240E4;
    // 0x80024068: sh          $t2, 0x126E($at)
    MEM_H(0X126E, ctx->r1) = ctx->r10;
L_8002406C:
    // 0x8002406C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80024070: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80024074: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80024078: nop

    // 0x8002407C: andi        $t5, $t4, 0x400
    ctx->r13 = ctx->r12 & 0X400;
    // 0x80024080: beq         $t5, $zero, L_80024094
    if (ctx->r13 == 0) {
        // 0x80024084: nop

            goto L_80024094;
    }
    // 0x80024084: nop

    // 0x80024088: sh          $zero, 0x118($sp)
    MEM_H(0X118, ctx->r29) = 0;
    // 0x8002408C: b           L_800240BC
    // 0x80024090: sh          $zero, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = 0;
        goto L_800240BC;
    // 0x80024090: sh          $zero, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = 0;
L_80024094:
    // 0x80024094: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80024098: addiu       $t6, $t6, 0x60F0
    ctx->r14 = ADD32(ctx->r14, 0X60F0);
    // 0x8002409C: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800240A0: nop

    // 0x800240A4: sh          $t7, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r15;
    // 0x800240A8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800240AC: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x800240B0: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x800240B4: nop

    // 0x800240B8: sh          $t9, 0x118($sp)
    MEM_H(0X118, ctx->r29) = ctx->r25;
L_800240BC:
    // 0x800240BC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800240C0: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x800240C4: lwc1        $f16, 0x10($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800240C8: nop

    // 0x800240CC: swc1        $f16, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f16.u32l;
    // 0x800240D0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800240D4: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x800240D8: lwc1        $f18, 0x14($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X14);
    // 0x800240DC: nop

    // 0x800240E0: swc1        $f18, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f18.u32l;
L_800240E4:
    // 0x800240E4: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x800240E8: nop

    // 0x800240EC: lh          $t3, 0x22($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X22);
    // 0x800240F0: nop

    // 0x800240F4: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x800240F8: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x800240FC: nop

    // 0x80024100: lwc1        $f4, 0x1C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80024104: nop

    // 0x80024108: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x8002410C: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80024110: nop

    // 0x80024114: lh          $t6, 0x24($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X24);
    // 0x80024118: nop

    // 0x8002411C: sh          $t6, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r14;
    // 0x80024120: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x80024124: nop

    // 0x80024128: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8002412C: nop

    // 0x80024130: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80024134: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x80024138: nop

    // 0x8002413C: lh          $t0, 0x28($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X28);
    // 0x80024140: nop

    // 0x80024144: sh          $t0, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r8;
    // 0x80024148: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8002414C: nop

    // 0x80024150: lh          $t2, 0x2C($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2C);
    // 0x80024154: nop

    // 0x80024158: sh          $t2, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r10;
    // 0x8002415C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80024160: lw          $t3, 0xE64($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XE64);
    // 0x80024164: nop

    // 0x80024168: beq         $t3, $zero, L_8002420C
    if (ctx->r11 == 0) {
        // 0x8002416C: nop

            goto L_8002420C;
    }
    // 0x8002416C: nop

    // 0x80024170: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80024174: lw          $t4, 0xE64($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XE64);
    // 0x80024178: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8002417C: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80024180: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80024184: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80024188: swc1        $f6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f6.u32l;
    // 0x8002418C: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80024190: nop

    // 0x80024194: bc1f        L_800241A4
    if (!c1cs) {
        // 0x80024198: nop

            goto L_800241A4;
    }
    // 0x80024198: nop

    // 0x8002419C: b           L_800241AC
    // 0x800241A0: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
        goto L_800241AC;
    // 0x800241A0: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
L_800241A4:
    // 0x800241A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800241A8: sh          $t5, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r13;
L_800241AC:
    // 0x800241AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800241B0: lw          $t6, 0xE64($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XE64);
    // 0x800241B4: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800241B8: addiu       $a1, $t6, 0x4C
    ctx->r5 = ADD32(ctx->r14, 0X4C);
    // 0x800241BC: jal         0x800B3A24
    // 0x800241C0: addiu       $a2, $t6, 0x50
    ctx->r6 = ADD32(ctx->r14, 0X50);
    func_800B3A24(rdram, ctx);
        goto after_2;
    // 0x800241C0: addiu       $a2, $t6, 0x50
    ctx->r6 = ADD32(ctx->r14, 0X50);
    after_2:
    // 0x800241C4: addiu       $t7, $sp, 0xD4
    ctx->r15 = ADD32(ctx->r29, 0XD4);
    // 0x800241C8: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800241CC: nop

    // 0x800241D0: swc1        $f18, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f18.u32l;
    // 0x800241D4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800241D8: lw          $t8, 0xE64($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XE64);
    // 0x800241DC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800241E0: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x800241E4: addiu       $s0, $zero, 0x0
    ctx->r16 = ADD32(0, 0X0);
    // 0x800241E8: addiu       $at, $zero, 0x0
    ctx->r1 = ADD32(0, 0X0);
    // 0x800241EC: andi        $t3, $t1, 0x8
    ctx->r11 = ctx->r9 & 0X8;
    // 0x800241F0: xor         $s0, $s0, $t3
    ctx->r16 = ctx->r16 ^ ctx->r11;
    // 0x800241F4: xor         $at, $at, $t2
    ctx->r1 = ctx->r1 ^ ctx->r10;
    // 0x800241F8: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
    // 0x800241FC: sltiu       $s0, $s0, 0x1
    ctx->r16 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80024200: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80024204: b           L_80024254
    // 0x80024208: sh          $s0, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = ctx->r16;
        goto L_80024254;
    // 0x80024208: sh          $s0, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = ctx->r16;
L_8002420C:
    // 0x8002420C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024210: sh          $zero, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = 0;
    // 0x80024214: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80024218: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002421C: swc1        $f8, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f8.u32l;
    // 0x80024220: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80024224: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80024228: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002422C: nop

    // 0x80024230: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80024234: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80024238: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002423C: sh          $t4, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r12;
    // 0x80024240: nop

    // 0x80024244: lui         $at, 0xC320
    ctx->r1 = S32(0XC320 << 16);
    // 0x80024248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002424C: nop

    // 0x80024250: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
L_80024254:
    // 0x80024254: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80024258: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8002425C: nop

    // 0x80024260: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80024264: nop

    // 0x80024268: beq         $t6, $zero, L_80024280
    if (ctx->r14 == 0) {
        // 0x8002426C: nop

            goto L_80024280;
    }
    // 0x8002426C: nop

    // 0x80024270: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x80024274: nop

    // 0x80024278: bne         $t7, $zero, L_80024288
    if (ctx->r15 != 0) {
        // 0x8002427C: nop

            goto L_80024288;
    }
    // 0x8002427C: nop

L_80024280:
    // 0x80024280: sh          $zero, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = 0;
    // 0x80024284: sh          $zero, 0x118($sp)
    MEM_H(0X118, ctx->r29) = 0;
L_80024288:
    // 0x80024288: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002428C: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x80024290: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80024294: bne         $t8, $at, L_800243DC
    if (ctx->r24 != ctx->r1) {
        // 0x80024298: nop

            goto L_800243DC;
    }
    // 0x80024298: nop

    // 0x8002429C: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x800242A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800242A4: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x800242A8: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800242AC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800242B0: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800242B4: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x800242B8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800242BC: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x800242C0: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800242C4: lwc1        $f18, 0xF8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800242C8: nop

    // 0x800242CC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800242D0: nop

    // 0x800242D4: bc1f        L_800242E8
    if (!c1cs) {
        // 0x800242D8: nop

            goto L_800242E8;
    }
    // 0x800242D8: nop

    // 0x800242DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800242E0: b           L_800242EC
    // 0x800242E4: sh          $t9, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r25;
        goto L_800242EC;
    // 0x800242E4: sh          $t9, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r25;
L_800242E8:
    // 0x800242E8: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_800242EC:
    // 0x800242EC: addiu       $t4, $sp, 0xD4
    ctx->r12 = ADD32(ctx->r29, 0XD4);
    // 0x800242F0: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800242F4: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800242F8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800242FC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80024300: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80024304: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80024308: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002430C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80024310: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80024314: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024318: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002431C: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024320: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80024324: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80024328: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8002432C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80024330: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x80024334: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80024338: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8002433C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80024340: jal         0x800C3D70
    // 0x80024344: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    func_800C3D70(rdram, ctx);
        goto after_3;
    // 0x80024344: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    after_3:
    // 0x80024348: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x8002434C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80024350: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80024354: nop

    // 0x80024358: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x8002435C: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80024360: nop

    // 0x80024364: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x80024368: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8002436C: nop

    // 0x80024370: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80024374: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x80024378: nop

    // 0x8002437C: sw          $t1, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r9;
    // 0x80024380: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80024384: nop

    // 0x80024388: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x8002438C: lw          $t1, 0x14($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X14);
    // 0x80024390: nop

    // 0x80024394: sw          $t1, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r9;
    // 0x80024398: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x8002439C: nop

    // 0x800243A0: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x800243A4: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800243A8: nop

    // 0x800243AC: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    // 0x800243B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800243B4: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800243B8: lwc1        $f9, -0x1C40($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1C40);
    // 0x800243BC: lwc1        $f8, -0x1C3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1C3C);
    // 0x800243C0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800243C4: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800243C8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800243CC: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x800243D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800243D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800243D8: sh          $t2, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r10;
L_800243DC:
    // 0x800243DC: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800243E0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800243E4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800243E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800243EC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800243F0: sub.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = ctx->f18.d - ctx->f4.d;
    // 0x800243F4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800243F8: nop

    // 0x800243FC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80024400: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80024404: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80024408: nop

    // 0x8002440C: cvt.w.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_D(ctx->f8.d);
    // 0x80024410: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80024414: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80024418: sh          $t9, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r25;
    // 0x8002441C: nop

    // 0x80024420: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024424: sw          $zero, 0x103C($at)
    MEM_W(0X103C, ctx->r1) = 0;
    // 0x80024428: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002442C: lh          $t4, 0x664($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X664);
    // 0x80024430: nop

    // 0x80024434: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80024438: beq         $at, $zero, L_800244B0
    if (ctx->r1 == 0) {
        // 0x8002443C: nop

            goto L_800244B0;
    }
    // 0x8002443C: nop

    // 0x80024440: lh          $t6, 0x13A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X13A);
    // 0x80024444: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80024448: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8002444C: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024450: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80024454: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80024458: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002445C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80024460: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80024464: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80024468: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8002446C: addiu       $a0, $a0, 0x10F8
    ctx->r4 = ADD32(ctx->r4, 0X10F8);
    // 0x80024470: jal         0x800782A8
    // 0x80024474: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800782A8(rdram, ctx);
        goto after_4;
    // 0x80024474: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80024478: beq         $v0, $zero, L_800244B0
    if (ctx->r2 == 0) {
        // 0x8002447C: nop

            goto L_800244B0;
    }
    // 0x8002447C: nop

    // 0x80024480: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80024484: lbu         $t8, 0x110E($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X110E);
    // 0x80024488: nop

    // 0x8002448C: ori         $t5, $t8, 0x8000
    ctx->r13 = ctx->r24 | 0X8000;
    // 0x80024490: sh          $t5, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r13;
    // 0x80024494: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80024498: lw          $t7, 0x1110($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1110);
    // 0x8002449C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800244A0: beq         $t7, $zero, L_800244B0
    if (ctx->r15 == 0) {
        // 0x800244A4: sw          $t7, 0x103C($at)
        MEM_W(0X103C, ctx->r1) = ctx->r15;
            goto L_800244B0;
    }
    // 0x800244A4: sw          $t7, 0x103C($at)
    MEM_W(0X103C, ctx->r1) = ctx->r15;
    // 0x800244A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800244AC: sh          $t1, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r9;
L_800244B0:
    // 0x800244B0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800244B4: lbu         $t2, 0xE54($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0XE54);
    // 0x800244B8: nop

    // 0x800244BC: bne         $t2, $zero, L_80024748
    if (ctx->r10 != 0) {
        // 0x800244C0: nop

            goto L_80024748;
    }
    // 0x800244C0: nop

    // 0x800244C4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800244C8: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x800244CC: nop

    // 0x800244D0: beq         $t3, $zero, L_80024740
    if (ctx->r11 == 0) {
        // 0x800244D4: nop

            goto L_80024740;
    }
    // 0x800244D4: nop

    // 0x800244D8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800244DC: addiu       $t9, $t9, 0x5B0
    ctx->r25 = ADD32(ctx->r25, 0X5B0);
    // 0x800244E0: sw          $t9, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r25;
    // 0x800244E4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800244E8: lh          $t4, 0x664($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X664);
    // 0x800244EC: nop

    // 0x800244F0: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x800244F4: beq         $at, $zero, L_80024504
    if (ctx->r1 == 0) {
        // 0x800244F8: nop

            goto L_80024504;
    }
    // 0x800244F8: nop

    // 0x800244FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024500: sw          $zero, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = 0;
L_80024504:
    // 0x80024504: jal         0x80023E50
    // 0x80024508: nop

    func_80023E50(rdram, ctx);
        goto after_5;
    // 0x80024508: nop

    after_5:
    // 0x8002450C: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80024510: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80024514: lh          $t6, 0x1B48($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1B48);
    // 0x80024518: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
    // 0x8002451C: blez        $t6, L_80024740
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80024520: nop

            goto L_80024740;
    }
    // 0x80024520: nop

L_80024524:
    // 0x80024524: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80024528: nop

    // 0x8002452C: lh          $t8, 0x6($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X6);
    // 0x80024530: nop

    // 0x80024534: bne         $t8, $zero, L_80024708
    if (ctx->r24 != 0) {
        // 0x80024538: nop

            goto L_80024708;
    }
    // 0x80024538: nop

    // 0x8002453C: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80024540: nop

    // 0x80024544: lbu         $t7, 0x10($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X10);
    // 0x80024548: nop

    // 0x8002454C: sh          $t7, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r15;
    // 0x80024550: lh          $t1, 0x13C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X13C);
    // 0x80024554: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80024558: addiu       $t3, $t3, 0x24D8
    ctx->r11 = ADD32(ctx->r11, 0X24D8);
    // 0x8002455C: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80024560: addu        $t9, $t2, $t3
    ctx->r25 = ADD32(ctx->r10, ctx->r11);
    // 0x80024564: lw          $a1, 0x18($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X18);
    // 0x80024568: lw          $a2, 0x1C($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X1C);
    // 0x8002456C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80024570: jal         0x800B35D4
    // 0x80024574: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800B35D4(rdram, ctx);
        goto after_6;
    // 0x80024574: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x80024578: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x8002457C: nop

    // 0x80024580: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80024584: nop

    // 0x80024588: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
    // 0x8002458C: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x80024590: nop

    // 0x80024594: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80024598: nop

    // 0x8002459C: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    // 0x800245A0: lui         $at, 0xC304
    ctx->r1 = S32(0XC304 << 16);
    // 0x800245A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800245A8: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800245AC: nop

    // 0x800245B0: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800245B4: nop

    // 0x800245B8: bc1f        L_800245F8
    if (!c1cs) {
        // 0x800245BC: nop

            goto L_800245F8;
    }
    // 0x800245BC: nop

    // 0x800245C0: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800245C4: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800245C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800245CC: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800245D0: lwc1        $f7, -0x1C38($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1C38);
    // 0x800245D4: lwc1        $f6, -0x1C34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C34);
    // 0x800245D8: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800245DC: sub.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = ctx->f6.d - ctx->f8.d;
    // 0x800245E0: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800245E4: swc1        $f10, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f10.u32l;
    // 0x800245E8: lui         $at, 0xC304
    ctx->r1 = S32(0XC304 << 16);
    // 0x800245EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800245F0: b           L_80024650
    // 0x800245F4: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
        goto L_80024650;
    // 0x800245F4: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_800245F8:
    // 0x800245F8: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x800245FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80024600: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80024604: nop

    // 0x80024608: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8002460C: nop

    // 0x80024610: bc1f        L_80024650
    if (!c1cs) {
        // 0x80024614: nop

            goto L_80024650;
    }
    // 0x80024614: nop

    // 0x80024618: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8002461C: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80024620: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024624: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80024628: lwc1        $f5, -0x1C30($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X1C30);
    // 0x8002462C: lwc1        $f4, -0x1C2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C2C);
    // 0x80024630: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80024634: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x80024638: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8002463C: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
    // 0x80024640: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x80024644: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80024648: nop

    // 0x8002464C: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
L_80024650:
    // 0x80024650: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80024654: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80024658: nop

    // 0x8002465C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80024660: nop

    // 0x80024664: bc1f        L_80024708
    if (!c1cs) {
        // 0x80024668: nop

            goto L_80024708;
    }
    // 0x80024668: nop

    // 0x8002466C: lh          $t8, 0x13A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13A);
    // 0x80024670: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x80024674: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80024678: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8002467C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80024680: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80024684: nop

    // 0x80024688: bc1f        L_80024708
    if (!c1cs) {
        // 0x8002468C: nop

            goto L_80024708;
    }
    // 0x8002468C: nop

    // 0x80024690: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80024694: nop

    // 0x80024698: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8002469C: nop

    // 0x800246A0: bc1f        L_80024708
    if (!c1cs) {
        // 0x800246A4: nop

            goto L_80024708;
    }
    // 0x800246A4: nop

    // 0x800246A8: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800246AC: nop

    // 0x800246B0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800246B4: nop

    // 0x800246B8: bc1f        L_80024708
    if (!c1cs) {
        // 0x800246BC: nop

            goto L_80024708;
    }
    // 0x800246BC: nop

    // 0x800246C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800246C4: sh          $t5, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r13;
    // 0x800246C8: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x800246CC: nop

    // 0x800246D0: lh          $t1, 0x0($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X0);
    // 0x800246D4: nop

    // 0x800246D8: sh          $t1, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r9;
    // 0x800246DC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800246E0: lh          $t2, 0x664($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X664);
    // 0x800246E4: nop

    // 0x800246E8: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800246EC: beq         $at, $zero, L_80024700
    if (ctx->r1 == 0) {
        // 0x800246F0: nop

            goto L_80024700;
    }
    // 0x800246F0: nop

    // 0x800246F4: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x800246F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800246FC: sw          $t3, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = ctx->r11;
L_80024700:
    // 0x80024700: b           L_80024740
    // 0x80024704: nop

        goto L_80024740;
    // 0x80024704: nop

L_80024708:
    // 0x80024708: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8002470C: nop

    // 0x80024710: lw          $t4, 0x14($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X14);
    // 0x80024714: nop

    // 0x80024718: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x8002471C: lh          $t6, 0x13E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X13E);
    // 0x80024720: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80024724: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80024728: lh          $t7, 0x1B48($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1B48);
    // 0x8002472C: sll         $t0, $t8, 16
    ctx->r8 = S32(ctx->r24 << 16);
    // 0x80024730: sra         $t5, $t0, 16
    ctx->r13 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80024734: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80024738: bne         $at, $zero, L_80024524
    if (ctx->r1 != 0) {
        // 0x8002473C: sh          $t8, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r24;
            goto L_80024524;
    }
    // 0x8002473C: sh          $t8, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r24;
L_80024740:
    // 0x80024740: b           L_8002475C
    // 0x80024744: nop

        goto L_8002475C;
    // 0x80024744: nop

L_80024748:
    // 0x80024748: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002474C: lbu         $t1, 0xE54($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XE54);
    // 0x80024750: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024754: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80024758: sb          $t2, 0xE54($at)
    MEM_B(0XE54, ctx->r1) = ctx->r10;
L_8002475C:
    // 0x8002475C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80024760: jal         0x800B2748
    // 0x80024764: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    func_800B2748(rdram, ctx);
        goto after_7;
    // 0x80024764: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    after_7:
    // 0x80024768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002476C: sh          $v0, 0x11A6($at)
    MEM_H(0X11A6, ctx->r1) = ctx->r2;
    // 0x80024770: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80024774: lh          $t3, 0x11A6($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X11A6);
    // 0x80024778: nop

    // 0x8002477C: bgez        $t3, L_8002479C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80024780: nop

            goto L_8002479C;
    }
    // 0x80024780: nop

    // 0x80024784: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80024788: sw          $t9, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r25;
    // 0x8002478C: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80024790: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80024794: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80024798: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
L_8002479C:
    // 0x8002479C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800247A0: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x800247A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800247A8: bne         $t8, $at, L_80024824
    if (ctx->r24 != ctx->r1) {
        // 0x800247AC: nop

            goto L_80024824;
    }
    // 0x800247AC: nop

    // 0x800247B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800247B4: lh          $t0, 0x6C0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6C0);
    // 0x800247B8: nop

    // 0x800247BC: bne         $t0, $zero, L_8002481C
    if (ctx->r8 != 0) {
        // 0x800247C0: nop

            goto L_8002481C;
    }
    // 0x800247C0: nop

    // 0x800247C4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800247C8: lh          $t5, 0x664($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X664);
    // 0x800247CC: nop

    // 0x800247D0: bne         $t5, $zero, L_8002481C
    if (ctx->r13 != 0) {
        // 0x800247D4: nop

            goto L_8002481C;
    }
    // 0x800247D4: nop

    // 0x800247D8: lh          $t7, 0x134($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X134);
    // 0x800247DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800247E0: beq         $t7, $at, L_8002481C
    if (ctx->r15 == ctx->r1) {
        // 0x800247E4: nop

            goto L_8002481C;
    }
    // 0x800247E4: nop

    // 0x800247E8: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800247EC: beq         $t7, $at, L_8002481C
    if (ctx->r15 == ctx->r1) {
        // 0x800247F0: nop

            goto L_8002481C;
    }
    // 0x800247F0: nop

    // 0x800247F4: addiu       $t1, $zero, 0x12
    ctx->r9 = ADD32(0, 0X12);
    // 0x800247F8: sh          $t1, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r9;
    // 0x800247FC: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80024800: nop

    // 0x80024804: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80024808: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x8002480C: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x80024810: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80024814: and         $t4, $t9, $at
    ctx->r12 = ctx->r25 & ctx->r1;
    // 0x80024818: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
L_8002481C:
    // 0x8002481C: b           L_80024850
    // 0x80024820: nop

        goto L_80024850;
    // 0x80024820: nop

L_80024824:
    // 0x80024824: lh          $t6, 0x134($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X134);
    // 0x80024828: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8002482C: bne         $t6, $at, L_80024850
    if (ctx->r14 != ctx->r1) {
        // 0x80024830: nop

            goto L_80024850;
    }
    // 0x80024830: nop

    // 0x80024834: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80024838: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002483C: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x80024840: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80024844: addiu       $at, $zero, -0xF
    ctx->r1 = ADD32(0, -0XF);
    // 0x80024848: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x8002484C: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
L_80024850:
    // 0x80024850: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80024854: lh          $t5, 0x66C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X66C);
    // 0x80024858: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002485C: bne         $t5, $at, L_800248D8
    if (ctx->r13 != ctx->r1) {
        // 0x80024860: nop

            goto L_800248D8;
    }
    // 0x80024860: nop

    // 0x80024864: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80024868: lh          $t7, 0x6C0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6C0);
    // 0x8002486C: nop

    // 0x80024870: bne         $t7, $zero, L_800248D0
    if (ctx->r15 != 0) {
        // 0x80024874: nop

            goto L_800248D0;
    }
    // 0x80024874: nop

    // 0x80024878: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002487C: lh          $t1, 0x664($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X664);
    // 0x80024880: nop

    // 0x80024884: bne         $t1, $zero, L_800248D0
    if (ctx->r9 != 0) {
        // 0x80024888: nop

            goto L_800248D0;
    }
    // 0x80024888: nop

    // 0x8002488C: lh          $t2, 0x134($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X134);
    // 0x80024890: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024894: beq         $t2, $at, L_800248D0
    if (ctx->r10 == ctx->r1) {
        // 0x80024898: nop

            goto L_800248D0;
    }
    // 0x80024898: nop

    // 0x8002489C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800248A0: beq         $t2, $at, L_800248D0
    if (ctx->r10 == ctx->r1) {
        // 0x800248A4: nop

            goto L_800248D0;
    }
    // 0x800248A4: nop

    // 0x800248A8: addiu       $t3, $zero, 0x1C
    ctx->r11 = ADD32(0, 0X1C);
    // 0x800248AC: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x800248B0: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800248B4: nop

    // 0x800248B8: ori         $t4, $t9, 0x14
    ctx->r12 = ctx->r25 | 0X14;
    // 0x800248BC: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
    // 0x800248C0: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x800248C4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800248C8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800248CC: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
L_800248D0:
    // 0x800248D0: b           L_80024904
    // 0x800248D4: nop

        goto L_80024904;
    // 0x800248D4: nop

L_800248D8:
    // 0x800248D8: lh          $t0, 0x134($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X134);
    // 0x800248DC: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800248E0: bne         $t0, $at, L_80024904
    if (ctx->r8 != ctx->r1) {
        // 0x800248E4: nop

            goto L_80024904;
    }
    // 0x800248E4: nop

    // 0x800248E8: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800248EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800248F0: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x800248F4: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x800248F8: addiu       $at, $zero, -0xF
    ctx->r1 = ADD32(0, -0XF);
    // 0x800248FC: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80024900: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
L_80024904:
    // 0x80024904: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024908: sh          $zero, 0xFF6($at)
    MEM_H(0XFF6, ctx->r1) = 0;
    // 0x8002490C: lhu         $t1, 0x118($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X118);
    // 0x80024910: nop

    // 0x80024914: bne         $t1, $zero, L_800249A0
    if (ctx->r9 != 0) {
        // 0x80024918: nop

            goto L_800249A0;
    }
    // 0x80024918: nop

    // 0x8002491C: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80024920: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80024924: nop

    // 0x80024928: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8002492C: nop

    // 0x80024930: bc1f        L_80024940
    if (!c1cs) {
        // 0x80024934: nop

            goto L_80024940;
    }
    // 0x80024934: nop

    // 0x80024938: b           L_8002494C
    // 0x8002493C: mov.s       $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = ctx->f6.fl;
        goto L_8002494C;
    // 0x8002493C: mov.s       $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = ctx->f6.fl;
L_80024940:
    // 0x80024940: lwc1        $f22, 0x10C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80024944: nop

    // 0x80024948: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl);
    ctx->f22.fl = -ctx->f22.fl;
L_8002494C:
    // 0x8002494C: lwc1        $f16, 0x108($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80024950: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024954: nop

    // 0x80024958: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8002495C: nop

    // 0x80024960: bc1f        L_80024970
    if (!c1cs) {
        // 0x80024964: nop

            goto L_80024970;
    }
    // 0x80024964: nop

    // 0x80024968: b           L_8002497C
    // 0x8002496C: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
        goto L_8002497C;
    // 0x8002496C: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
L_80024970:
    // 0x80024970: lwc1        $f20, 0x108($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80024974: nop

    // 0x80024978: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f20.fl = -ctx->f20.fl;
L_8002497C:
    // 0x8002497C: add.s       $f10, $f20, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl);
    ctx->f10.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80024980: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80024984: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80024988: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002498C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80024990: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x80024994: nop

    // 0x80024998: bc1f        L_80024A14
    if (!c1cs) {
        // 0x8002499C: nop

            goto L_80024A14;
    }
    // 0x8002499C: nop

L_800249A0:
    // 0x800249A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800249A4: lwc1        $f6, 0xEF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x800249A8: lui         $at, 0x4561
    ctx->r1 = S32(0X4561 << 16);
    // 0x800249AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800249B0: nop

    // 0x800249B4: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x800249B8: nop

    // 0x800249BC: bc1f        L_800249E8
    if (!c1cs) {
        // 0x800249C0: nop

            goto L_800249E8;
    }
    // 0x800249C0: nop

    // 0x800249C4: jal         0x8005618C
    // 0x800249C8: nop

    func_8005618C(rdram, ctx);
        goto after_8;
    // 0x800249C8: nop

    after_8:
    // 0x800249CC: bne         $v0, $zero, L_800249E8
    if (ctx->r2 != 0) {
        // 0x800249D0: nop

            goto L_800249E8;
    }
    // 0x800249D0: nop

    // 0x800249D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800249D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800249DC: sh          $t2, 0xFF6($at)
    MEM_H(0XFF6, ctx->r1) = ctx->r10;
    // 0x800249E0: jal         0x80055FB8
    // 0x800249E4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80055FB8(rdram, ctx);
        goto after_9;
    // 0x800249E4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_9:
L_800249E8:
    // 0x800249E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800249EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800249F0: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800249F4: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x800249F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800249FC: swc1        $f10, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f10.u32l;
    // 0x80024A00: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x80024A04: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80024A08: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80024A0C: b           L_80024A9C
    // 0x80024A10: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
        goto L_80024A9C;
    // 0x80024A10: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
L_80024A14:
    // 0x80024A14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A18: lwc1        $f8, 0xEF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x80024A1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A20: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80024A24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A28: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80024A2C: swc1        $f6, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f6.u32l;
    // 0x80024A30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024A34: lwc1        $f4, -0x1C28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C28);
    // 0x80024A38: nop

    // 0x80024A3C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80024A40: nop

    // 0x80024A44: bc1f        L_80024A5C
    if (!c1cs) {
        // 0x80024A48: nop

            goto L_80024A5C;
    }
    // 0x80024A48: nop

    // 0x80024A4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024A50: lwc1        $f16, -0x1C24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1C24);
    // 0x80024A54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A58: swc1        $f16, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f16.u32l;
L_80024A5C:
    // 0x80024A5C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80024A60: lh          $t4, 0x664($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X664);
    // 0x80024A64: nop

    // 0x80024A68: bne         $t4, $zero, L_80024A9C
    if (ctx->r12 != 0) {
        // 0x80024A6C: nop

            goto L_80024A9C;
    }
    // 0x80024A6C: nop

    // 0x80024A70: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80024A74: lw          $t6, 0x64C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X64C);
    // 0x80024A78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A7C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80024A80: sw          $t8, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = ctx->r24;
    // 0x80024A84: slti        $at, $t8, 0x2000
    ctx->r1 = SIGNED(ctx->r24) < 0X2000 ? 1 : 0;
    // 0x80024A88: bne         $at, $zero, L_80024A9C
    if (ctx->r1 != 0) {
        // 0x80024A8C: nop

            goto L_80024A9C;
    }
    // 0x80024A8C: nop

    // 0x80024A90: addiu       $t0, $zero, 0x1FFF
    ctx->r8 = ADD32(0, 0X1FFF);
    // 0x80024A94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024A98: sw          $t0, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = ctx->r8;
L_80024A9C:
    // 0x80024A9C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80024AA0: lw          $t5, 0x64C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X64C);
    // 0x80024AA4: nop

    // 0x80024AA8: slti        $at, $t5, 0x12D
    ctx->r1 = SIGNED(ctx->r13) < 0X12D ? 1 : 0;
    // 0x80024AAC: bne         $at, $zero, L_80024AC8
    if (ctx->r1 != 0) {
        // 0x80024AB0: nop

            goto L_80024AC8;
    }
    // 0x80024AB0: nop

    // 0x80024AB4: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x80024AB8: nop

    // 0x80024ABC: andi        $t1, $t7, 0x8
    ctx->r9 = ctx->r15 & 0X8;
    // 0x80024AC0: beq         $t1, $zero, L_80024AEC
    if (ctx->r9 == 0) {
        // 0x80024AC4: nop

            goto L_80024AEC;
    }
    // 0x80024AC4: nop

L_80024AC8:
    // 0x80024AC8: lw          $t2, 0x120($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X120);
    // 0x80024ACC: nop

    // 0x80024AD0: beq         $t2, $zero, L_80024B34
    if (ctx->r10 == 0) {
        // 0x80024AD4: nop

            goto L_80024B34;
    }
    // 0x80024AD4: nop

    // 0x80024AD8: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x80024ADC: nop

    // 0x80024AE0: andi        $t9, $t3, 0x8
    ctx->r25 = ctx->r11 & 0X8;
    // 0x80024AE4: beq         $t9, $zero, L_80024B34
    if (ctx->r25 == 0) {
        // 0x80024AE8: nop

            goto L_80024B34;
    }
    // 0x80024AE8: nop

L_80024AEC:
    // 0x80024AEC: sw          $zero, 0x120($sp)
    MEM_W(0X120, ctx->r29) = 0;
    // 0x80024AF0: jal         0x800C4240
    // 0x80024AF4: nop

    guRandom(rdram, ctx);
        goto after_10;
    // 0x80024AF4: nop

    after_10:
    // 0x80024AF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80024AFC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80024B00: mfhi        $t4
    ctx->r12 = hi;
    // 0x80024B04: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80024B08: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80024B0C: addiu       $t0, $t8, 0x13
    ctx->r8 = ADD32(ctx->r24, 0X13);
    // 0x80024B10: sh          $t0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r8;
    // 0x80024B14: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80024B18: nop

    // 0x80024B1C: ori         $t7, $t5, 0x8
    ctx->r15 = ctx->r13 | 0X8;
    // 0x80024B20: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
    // 0x80024B24: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x80024B28: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80024B2C: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80024B30: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
L_80024B34:
    // 0x80024B34: lw          $a3, 0x140($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X140);
    // 0x80024B38: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80024B3C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80024B40: addiu       $a1, $sp, 0xF8
    ctx->r5 = ADD32(ctx->r29, 0XF8);
    // 0x80024B44: addiu       $a2, $sp, 0xF4
    ctx->r6 = ADD32(ctx->r29, 0XF4);
    // 0x80024B48: addiu       $a3, $a3, 0x1B8
    ctx->r7 = ADD32(ctx->r7, 0X1B8);
    // 0x80024B4C: jal         0x800C3F2C
    // 0x80024B50: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C3F2C(rdram, ctx);
        goto after_11;
    // 0x80024B50: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80024B54: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80024B58: nop

    // 0x80024B5C: lwc1        $f8, 0x18($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80024B60: nop

    // 0x80024B64: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x80024B68: lhu         $a0, 0x11A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X11A);
    // 0x80024B6C: jal         0x80023CA0
    // 0x80024B70: nop

    func_80023CA0(rdram, ctx);
        goto after_12;
    // 0x80024B70: nop

    after_12:
    // 0x80024B74: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80024B78: lh          $s0, 0x664($s0)
    ctx->r16 = MEM_H(ctx->r16, 0X664);
    // 0x80024B7C: nop

    // 0x80024B80: slti        $at, $s0, 0x3E7
    ctx->r1 = SIGNED(ctx->r16) < 0X3E7 ? 1 : 0;
    // 0x80024B84: bne         $at, $zero, L_80024BA0
    if (ctx->r1 != 0) {
        // 0x80024B88: nop

            goto L_80024BA0;
    }
    // 0x80024B88: nop

    // 0x80024B8C: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x80024B90: beq         $s0, $at, L_80027F58
    if (ctx->r16 == ctx->r1) {
        // 0x80024B94: nop

            goto L_80027F58;
    }
    // 0x80024B94: nop

    // 0x80024B98: b           L_80028048
    // 0x80024B9C: nop

        goto L_80028048;
    // 0x80024B9C: nop

L_80024BA0:
    // 0x80024BA0: slti        $at, $s0, 0x66
    ctx->r1 = SIGNED(ctx->r16) < 0X66 ? 1 : 0;
    // 0x80024BA4: bne         $at, $zero, L_80024BC0
    if (ctx->r1 != 0) {
        // 0x80024BA8: nop

            goto L_80024BC0;
    }
    // 0x80024BA8: nop

    // 0x80024BAC: addiu       $at, $zero, 0x3E6
    ctx->r1 = ADD32(0, 0X3E6);
    // 0x80024BB0: beq         $s0, $at, L_80027E4C
    if (ctx->r16 == ctx->r1) {
        // 0x80024BB4: nop

            goto L_80027E4C;
    }
    // 0x80024BB4: nop

    // 0x80024BB8: b           L_80028048
    // 0x80024BBC: nop

        goto L_80028048;
    // 0x80024BBC: nop

L_80024BC0:
    // 0x80024BC0: sltiu       $at, $s0, 0x66
    ctx->r1 = ctx->r16 < 0X66 ? 1 : 0;
    // 0x80024BC4: beq         $at, $zero, L_80028048
    if (ctx->r1 == 0) {
        // 0x80024BC8: nop

            goto L_80028048;
    }
    // 0x80024BC8: nop

    // 0x80024BCC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80024BD0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024BD4: addu        $at, $at, $t9
    gpr jr_addend_80024BE0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80024BD8: lw          $t9, -0x1C20($at)
    ctx->r25 = ADD32(ctx->r1, -0X1C20);
    // 0x80024BDC: nop

    // 0x80024BE0: jr          $t9
    // 0x80024BE4: nop

    switch (jr_addend_80024BE0 >> 2) {
        case 0: goto L_80024BE8; break;
        case 1: goto L_80025294; break;
        case 2: goto L_800258B8; break;
        case 3: goto L_80025C1C; break;
        case 4: goto L_80028048; break;
        case 5: goto L_80025F6C; break;
        case 6: goto L_800260B0; break;
        case 7: goto L_80028048; break;
        case 8: goto L_80028048; break;
        case 9: goto L_80028048; break;
        case 10: goto L_800260F4; break;
        case 11: goto L_80028048; break;
        case 12: goto L_80028048; break;
        case 13: goto L_80028048; break;
        case 14: goto L_80028048; break;
        case 15: goto L_80026130; break;
        case 16: goto L_800260F4; break;
        case 17: goto L_80028048; break;
        case 18: goto L_80028048; break;
        case 19: goto L_80028048; break;
        case 20: goto L_8002760C; break;
        case 21: goto L_800276A4; break;
        case 22: goto L_80028048; break;
        case 23: goto L_80028048; break;
        case 24: goto L_80028048; break;
        case 25: goto L_80027894; break;
        case 26: goto L_800279B8; break;
        case 27: goto L_80028048; break;
        case 28: goto L_80028048; break;
        case 29: goto L_80028048; break;
        case 30: goto L_800279F4; break;
        case 31: goto L_80028048; break;
        case 32: goto L_80028048; break;
        case 33: goto L_80028048; break;
        case 34: goto L_80028048; break;
        case 35: goto L_80027ABC; break;
        case 36: goto L_80028048; break;
        case 37: goto L_80028048; break;
        case 38: goto L_80028048; break;
        case 39: goto L_80028048; break;
        case 40: goto L_80027B84; break;
        case 41: goto L_80027C14; break;
        case 42: goto L_80028048; break;
        case 43: goto L_80028048; break;
        case 44: goto L_80028048; break;
        case 45: goto L_80028048; break;
        case 46: goto L_80028048; break;
        case 47: goto L_80028048; break;
        case 48: goto L_80028048; break;
        case 49: goto L_80028048; break;
        case 50: goto L_80028048; break;
        case 51: goto L_80028048; break;
        case 52: goto L_80028048; break;
        case 53: goto L_80028048; break;
        case 54: goto L_80028048; break;
        case 55: goto L_80028048; break;
        case 56: goto L_80028048; break;
        case 57: goto L_80028048; break;
        case 58: goto L_80028048; break;
        case 59: goto L_80028048; break;
        case 60: goto L_800261CC; break;
        case 61: goto L_80028048; break;
        case 62: goto L_80028048; break;
        case 63: goto L_800262FC; break;
        case 64: goto L_80028048; break;
        case 65: goto L_80028048; break;
        case 66: goto L_80028048; break;
        case 67: goto L_80028048; break;
        case 68: goto L_80028048; break;
        case 69: goto L_80028048; break;
        case 70: goto L_80026B74; break;
        case 71: goto L_80028048; break;
        case 72: goto L_80028048; break;
        case 73: goto L_80028048; break;
        case 74: goto L_80028048; break;
        case 75: goto L_80026BA0; break;
        case 76: goto L_80026EF0; break;
        case 77: goto L_80026FBC; break;
        case 78: goto L_8002714C; break;
        case 79: goto L_80028048; break;
        case 80: goto L_80027184; break;
        case 81: goto L_80027328; break;
        case 82: goto L_80028048; break;
        case 83: goto L_80028048; break;
        case 84: goto L_80028048; break;
        case 85: goto L_80028048; break;
        case 86: goto L_80028048; break;
        case 87: goto L_80028048; break;
        case 88: goto L_80028048; break;
        case 89: goto L_80028048; break;
        case 90: goto L_800273CC; break;
        case 91: goto L_80027448; break;
        case 92: goto L_80028048; break;
        case 93: goto L_80028048; break;
        case 94: goto L_80028048; break;
        case 95: goto L_80027574; break;
        case 96: goto L_80028048; break;
        case 97: goto L_80028048; break;
        case 98: goto L_80028048; break;
        case 99: goto L_80028048; break;
        case 100: goto L_80027DA4; break;
        case 101: goto L_80027E44; break;
        default: switch_error(__func__, 0x80024BE0, 0x800EE3E0);
    }
    // 0x80024BE4: nop

L_80024BE8:
    // 0x80024BE8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80024BEC: lbu         $t4, 0x125A($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X125A);
    // 0x80024BF0: nop

    // 0x80024BF4: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80024BF8: beq         $t6, $zero, L_80024C14
    if (ctx->r14 == 0) {
        // 0x80024BFC: nop

            goto L_80024C14;
    }
    // 0x80024BFC: nop

    // 0x80024C00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80024C04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024C08: swc1        $f18, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f18.u32l;
    // 0x80024C0C: b           L_80028048
    // 0x80024C10: nop

        goto L_80028048;
    // 0x80024C10: nop

L_80024C14:
    // 0x80024C14: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    // 0x80024C18: addiu       $a1, $sp, 0x134
    ctx->r5 = ADD32(ctx->r29, 0X134);
    // 0x80024C1C: jal         0x80023634
    // 0x80024C20: addiu       $a2, $sp, 0x124
    ctx->r6 = ADD32(ctx->r29, 0X124);
    func_80023634(rdram, ctx);
        goto after_13;
    // 0x80024C20: addiu       $a2, $sp, 0x124
    ctx->r6 = ADD32(ctx->r29, 0X124);
    after_13:
    // 0x80024C24: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x80024C28: nop

    // 0x80024C2C: lwc1        $f6, 0x1B0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1B0);
    // 0x80024C30: nop

    // 0x80024C34: swc1        $f6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f6.u32l;
    // 0x80024C38: lw          $t0, 0x140($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X140);
    // 0x80024C3C: nop

    // 0x80024C40: lwc1        $f4, 0x1B4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1B4);
    // 0x80024C44: nop

    // 0x80024C48: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80024C4C: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80024C50: nop

    // 0x80024C54: lh          $t7, 0x24($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X24);
    // 0x80024C58: nop

    // 0x80024C5C: sh          $t7, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r15;
    // 0x80024C60: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80024C64: lw          $t1, 0xE64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XE64);
    // 0x80024C68: nop

    // 0x80024C6C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80024C70: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80024C74: andi        $t4, $t2, 0x4
    ctx->r12 = ctx->r10 & 0X4;
    // 0x80024C78: bne         $t4, $zero, L_80024C88
    if (ctx->r12 != 0) {
        // 0x80024C7C: andi        $t5, $t3, 0x0
        ctx->r13 = ctx->r11 & 0X0;
            goto L_80024C88;
    }
    // 0x80024C7C: andi        $t5, $t3, 0x0
    ctx->r13 = ctx->r11 & 0X0;
    // 0x80024C80: beq         $t5, $zero, L_80024E40
    if (ctx->r13 == 0) {
        // 0x80024C84: nop

            goto L_80024E40;
    }
    // 0x80024C84: nop

L_80024C88:
    // 0x80024C88: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024C8C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80024C90: nop

    // 0x80024C94: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80024C98: nop

    // 0x80024C9C: bc1f        L_80024CC0
    if (!c1cs) {
        // 0x80024CA0: nop

            goto L_80024CC0;
    }
    // 0x80024CA0: nop

    // 0x80024CA4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80024CA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80024CAC: lwc1        $f8, 0x100($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024CB0: nop

    // 0x80024CB4: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80024CB8: b           L_80024CD8
    // 0x80024CBC: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
        goto L_80024CD8;
    // 0x80024CBC: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
L_80024CC0:
    // 0x80024CC0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80024CC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80024CC8: lwc1        $f4, 0x100($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024CCC: nop

    // 0x80024CD0: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80024CD4: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
L_80024CD8:
    // 0x80024CD8: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024CDC: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80024CE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80024CE4: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80024CE8: c.eq.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d == ctx->f6.d;
    // 0x80024CEC: nop

    // 0x80024CF0: bc1f        L_80024D08
    if (!c1cs) {
        // 0x80024CF4: nop

            goto L_80024D08;
    }
    // 0x80024CF4: nop

    // 0x80024CF8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80024CFC: lwc1        $f4, -0x1A88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1A88);
    // 0x80024D00: nop

    // 0x80024D04: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
L_80024D08:
    // 0x80024D08: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024D0C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80024D10: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80024D14: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80024D18: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80024D1C: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x80024D20: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80024D24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80024D28: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80024D2C: jal         0x800C3D70
    // 0x80024D30: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C3D70(rdram, ctx);
        goto after_14;
    // 0x80024D30: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x80024D34: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x80024D38: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80024D3C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80024D40: nop

    // 0x80024D44: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80024D48: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80024D4C: nop

    // 0x80024D50: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80024D54: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80024D58: nop

    // 0x80024D5C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80024D60: lw          $t1, 0xC($t8)
    ctx->r9 = MEM_W(ctx->r24, 0XC);
    // 0x80024D64: nop

    // 0x80024D68: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x80024D6C: lw          $at, 0x10($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X10);
    // 0x80024D70: nop

    // 0x80024D74: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80024D78: lw          $t1, 0x14($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X14);
    // 0x80024D7C: nop

    // 0x80024D80: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x80024D84: lw          $at, 0x18($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X18);
    // 0x80024D88: nop

    // 0x80024D8C: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x80024D90: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80024D94: nop

    // 0x80024D98: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x80024D9C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80024DA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80024DA4: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80024DA8: nop

    // 0x80024DAC: div.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80024DB0: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x80024DB4: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80024DB8: addiu       $at, $zero, -0xB
    ctx->r1 = ADD32(0, -0XB);
    // 0x80024DBC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80024DC0: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x80024DC4: addiu       $t4, $zero, 0x11
    ctx->r12 = ADD32(0, 0X11);
    // 0x80024DC8: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x80024DCC: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x80024DD0: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80024DD4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80024DD8: nop

    // 0x80024DDC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80024DE0: nop

    // 0x80024DE4: bc1f        L_80024DF8
    if (!c1cs) {
        // 0x80024DE8: nop

            goto L_80024DF8;
    }
    // 0x80024DE8: nop

    // 0x80024DEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80024DF0: b           L_80024DFC
    // 0x80024DF4: sh          $t9, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r25;
        goto L_80024DFC;
    // 0x80024DF4: sh          $t9, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r25;
L_80024DF8:
    // 0x80024DF8: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80024DFC:
    // 0x80024DFC: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80024E00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E04: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x80024E08: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80024E0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E10: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80024E14: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x80024E18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E1C: swc1        $f18, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f18.u32l;
    // 0x80024E20: lwc1        $f6, 0xF8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80024E24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E28: swc1        $f6, 0xE78($at)
    MEM_W(0XE78, ctx->r1) = ctx->f6.u32l;
    // 0x80024E2C: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024E30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80024E34: swc1        $f4, 0xEC4($at)
    MEM_W(0XEC4, ctx->r1) = ctx->f4.u32l;
    // 0x80024E38: b           L_80028048
    // 0x80024E3C: nop

        goto L_80028048;
    // 0x80024E3C: nop

L_80024E40:
    // 0x80024E40: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80024E44: lh          $t0, 0xFF6($t0)
    ctx->r8 = MEM_H(ctx->r8, 0XFF6);
    // 0x80024E48: nop

    // 0x80024E4C: beq         $t0, $zero, L_80024E5C
    if (ctx->r8 == 0) {
        // 0x80024E50: nop

            goto L_80024E5C;
    }
    // 0x80024E50: nop

    // 0x80024E54: b           L_80028048
    // 0x80024E58: nop

        goto L_80028048;
    // 0x80024E58: nop

L_80024E5C:
    // 0x80024E5C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80024E60: lh          $t6, 0x66C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X66C);
    // 0x80024E64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024E68: beq         $t6, $at, L_80025250
    if (ctx->r14 == ctx->r1) {
        // 0x80024E6C: nop

            goto L_80025250;
    }
    // 0x80024E6C: nop

    // 0x80024E70: lh          $t8, 0xD2($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XD2);
    // 0x80024E74: nop

    // 0x80024E78: beq         $t8, $zero, L_80024F08
    if (ctx->r24 == 0) {
        // 0x80024E7C: nop

            goto L_80024F08;
    }
    // 0x80024E7C: nop

    // 0x80024E80: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x80024E84: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80024E88: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024E8C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80024E90: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80024E94: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80024E98: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80024E9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80024EA0: add.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = ctx->f10.d + ctx->f8.d;
    // 0x80024EA4: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x80024EA8: nop

    // 0x80024EAC: bc1f        L_80024EF8
    if (!c1cs) {
        // 0x80024EB0: nop

            goto L_80024EF8;
    }
    // 0x80024EB0: nop

    // 0x80024EB4: lwc1        $f16, 0x100($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024EB8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80024EBC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80024EC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024EC4: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80024EC8: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x80024ECC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80024ED0: nop

    // 0x80024ED4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80024ED8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80024EDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80024EE0: nop

    // 0x80024EE4: cvt.w.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_D(ctx->f8.d);
    // 0x80024EE8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80024EEC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80024EF0: b           L_80024F00
    // 0x80024EF4: sh          $t2, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r10;
        goto L_80024F00;
    // 0x80024EF4: sh          $t2, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r10;
L_80024EF8:
    // 0x80024EF8: addiu       $t3, $zero, 0x16
    ctx->r11 = ADD32(0, 0X16);
    // 0x80024EFC: sh          $t3, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r11;
L_80024F00:
    // 0x80024F00: b           L_80024F88
    // 0x80024F04: nop

        goto L_80024F88;
    // 0x80024F04: nop

L_80024F08:
    // 0x80024F08: lui         $at, 0x4036
    ctx->r1 = S32(0X4036 << 16);
    // 0x80024F0C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80024F10: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024F14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024F18: lui         $at, 0xC060
    ctx->r1 = S32(0XC060 << 16);
    // 0x80024F1C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80024F20: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80024F24: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80024F28: sub.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = ctx->f16.d - ctx->f4.d;
    // 0x80024F2C: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80024F30: nop

    // 0x80024F34: bc1f        L_80024F80
    if (!c1cs) {
        // 0x80024F38: nop

            goto L_80024F80;
    }
    // 0x80024F38: nop

    // 0x80024F3C: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024F40: lui         $at, 0xC060
    ctx->r1 = S32(0XC060 << 16);
    // 0x80024F44: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80024F48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80024F4C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80024F50: sub.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = ctx->f18.d - ctx->f16.d;
    // 0x80024F54: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80024F58: nop

    // 0x80024F5C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80024F60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80024F64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80024F68: nop

    // 0x80024F6C: cvt.w.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_D(ctx->f4.d);
    // 0x80024F70: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80024F74: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80024F78: b           L_80024F88
    // 0x80024F7C: sh          $t5, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r13;
        goto L_80024F88;
    // 0x80024F7C: sh          $t5, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r13;
L_80024F80:
    // 0x80024F80: addiu       $t9, $zero, -0x16
    ctx->r25 = ADD32(0, -0X16);
    // 0x80024F84: sh          $t9, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r25;
L_80024F88:
    // 0x80024F88: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80024F8C: lhu         $t0, 0xFF4($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XFF4);
    // 0x80024F90: lhu         $t7, 0x118($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X118);
    // 0x80024F94: nop

    // 0x80024F98: and         $t6, $t7, $t0
    ctx->r14 = ctx->r15 & ctx->r8;
    // 0x80024F9C: beq         $t6, $zero, L_800250EC
    if (ctx->r14 == 0) {
        // 0x80024FA0: nop

            goto L_800250EC;
    }
    // 0x80024FA0: nop

    // 0x80024FA4: lh          $t8, 0x13C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13C);
    // 0x80024FA8: lwc1        $f18, 0x100($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80024FAC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80024FB0: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80024FB4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80024FB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80024FBC: lwc1        $f14, 0xFC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80024FC0: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80024FC4: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x80024FC8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80024FCC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80024FD0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80024FD4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80024FD8: jal         0x800C3D70
    // 0x80024FDC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_15;
    // 0x80024FDC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x80024FE0: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80024FE4: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80024FE8: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80024FEC: nop

    // 0x80024FF0: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80024FF4: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80024FF8: nop

    // 0x80024FFC: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80025000: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80025004: nop

    // 0x80025008: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x8002500C: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    // 0x80025010: nop

    // 0x80025014: sw          $t9, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r25;
    // 0x80025018: lw          $at, 0x10($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X10);
    // 0x8002501C: nop

    // 0x80025020: sw          $at, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r1;
    // 0x80025024: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x80025028: nop

    // 0x8002502C: sw          $t9, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r25;
    // 0x80025030: lw          $at, 0x18($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X18);
    // 0x80025034: nop

    // 0x80025038: sw          $at, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r1;
    // 0x8002503C: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80025040: nop

    // 0x80025044: swc1        $f10, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f10.u32l;
    // 0x80025048: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x8002504C: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80025050: sh          $t7, 0x26($t0)
    MEM_H(0X26, ctx->r8) = ctx->r15;
    // 0x80025054: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80025058: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002505C: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80025060: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80025064: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80025068: sh          $t1, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r9;
    // 0x8002506C: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x80025070: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80025074: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80025078: nop

    // 0x8002507C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80025080: nop

    // 0x80025084: bc1f        L_80025098
    if (!c1cs) {
        // 0x80025088: nop

            goto L_80025098;
    }
    // 0x80025088: nop

    // 0x8002508C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80025090: b           L_8002509C
    // 0x80025094: sh          $t4, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r12;
        goto L_8002509C;
    // 0x80025094: sh          $t4, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r12;
L_80025098:
    // 0x80025098: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_8002509C:
    // 0x8002509C: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x800250A0: nop

    // 0x800250A4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x800250A8: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x800250AC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800250B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800250B4: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x800250B8: jal         0x80055FB8
    // 0x800250BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_16;
    // 0x800250BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_16:
    // 0x800250C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800250C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800250C8: sh          $t7, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r15;
    // 0x800250CC: lwc1        $f18, 0xF8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800250D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800250D4: swc1        $f18, 0xE78($at)
    MEM_W(0XE78, ctx->r1) = ctx->f18.u32l;
    // 0x800250D8: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800250DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800250E0: swc1        $f16, 0xEC4($at)
    MEM_W(0XEC4, ctx->r1) = ctx->f16.u32l;
    // 0x800250E4: b           L_80028048
    // 0x800250E8: nop

        goto L_80028048;
    // 0x800250E8: nop

L_800250EC:
    // 0x800250EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800250F0: lhu         $t6, 0x101C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X101C);
    // 0x800250F4: lhu         $t0, 0x118($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X118);
    // 0x800250F8: nop

    // 0x800250FC: and         $t8, $t0, $t6
    ctx->r24 = ctx->r8 & ctx->r14;
    // 0x80025100: beq         $t8, $zero, L_80025250
    if (ctx->r24 == 0) {
        // 0x80025104: nop

            goto L_80025250;
    }
    // 0x80025104: nop

    // 0x80025108: lh          $t1, 0x13C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X13C);
    // 0x8002510C: lwc1        $f8, 0x100($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80025110: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80025114: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025118: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002511C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80025120: lwc1        $f14, 0xFC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80025124: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80025128: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x8002512C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80025130: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80025134: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80025138: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8002513C: jal         0x800C3D70
    // 0x80025140: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800C3D70(rdram, ctx);
        goto after_17;
    // 0x80025140: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x80025144: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80025148: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8002514C: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80025150: nop

    // 0x80025154: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80025158: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x8002515C: nop

    // 0x80025160: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80025164: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80025168: nop

    // 0x8002516C: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x80025170: lw          $t7, 0xC($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XC);
    // 0x80025174: nop

    // 0x80025178: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
    // 0x8002517C: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x80025180: nop

    // 0x80025184: sw          $at, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r1;
    // 0x80025188: lw          $t7, 0x14($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X14);
    // 0x8002518C: nop

    // 0x80025190: sw          $t7, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r15;
    // 0x80025194: lw          $at, 0x18($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X18);
    // 0x80025198: nop

    // 0x8002519C: sw          $at, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r1;
    // 0x800251A0: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800251A4: nop

    // 0x800251A8: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    // 0x800251AC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800251B0: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800251B4: sh          $t0, 0x26($t6)
    MEM_H(0X26, ctx->r14) = ctx->r8;
    // 0x800251B8: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x800251BC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800251C0: and         $t1, $t8, $at
    ctx->r9 = ctx->r24 & ctx->r1;
    // 0x800251C4: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x800251C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800251CC: sh          $t5, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r13;
    // 0x800251D0: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x800251D4: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800251D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800251DC: nop

    // 0x800251E0: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800251E4: nop

    // 0x800251E8: bc1f        L_800251FC
    if (!c1cs) {
        // 0x800251EC: nop

            goto L_800251FC;
    }
    // 0x800251EC: nop

    // 0x800251F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800251F4: b           L_80025200
    // 0x800251F8: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
        goto L_80025200;
    // 0x800251F8: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
L_800251FC:
    // 0x800251FC: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80025200:
    // 0x80025200: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80025204: nop

    // 0x80025208: ori         $t2, $t4, 0x1
    ctx->r10 = ctx->r12 | 0X1;
    // 0x8002520C: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x80025210: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80025214: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025218: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x8002521C: jal         0x80055FB8
    // 0x80025220: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_18;
    // 0x80025220: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_18:
    // 0x80025224: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80025228: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002522C: sh          $t0, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r8;
    // 0x80025230: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025234: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025238: swc1        $f8, 0xE78($at)
    MEM_W(0XE78, ctx->r1) = ctx->f8.u32l;
    // 0x8002523C: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025244: swc1        $f6, 0xEC4($at)
    MEM_W(0XEC4, ctx->r1) = ctx->f6.u32l;
    // 0x80025248: b           L_80028048
    // 0x8002524C: nop

        goto L_80028048;
    // 0x8002524C: nop

L_80025250:
    // 0x80025250: jal         0x80022E48
    // 0x80025254: nop

    func_80022E48(rdram, ctx);
        goto after_19;
    // 0x80025254: nop

    after_19:
    // 0x80025258: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x8002525C: nop

    // 0x80025260: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80025264: bne         $t8, $zero, L_8002528C
    if (ctx->r24 != 0) {
        // 0x80025268: nop

            goto L_8002528C;
    }
    // 0x80025268: nop

    // 0x8002526C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80025270: lh          $t1, 0x66C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X66C);
    // 0x80025274: nop

    // 0x80025278: beq         $t1, $zero, L_80025294
    if (ctx->r9 == 0) {
        // 0x8002527C: nop

            goto L_80025294;
    }
    // 0x8002527C: nop

    // 0x80025280: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80025284: beq         $t1, $at, L_80025294
    if (ctx->r9 == ctx->r1) {
        // 0x80025288: nop

            goto L_80025294;
    }
    // 0x80025288: nop

L_8002528C:
    // 0x8002528C: b           L_80028048
    // 0x80025290: nop

        goto L_80028048;
    // 0x80025290: nop

L_80025294:
    // 0x80025294: lw          $t5, 0x120($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X120);
    // 0x80025298: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002529C: bne         $t5, $at, L_800252C0
    if (ctx->r13 != ctx->r1) {
        // 0x800252A0: nop

            goto L_800252C0;
    }
    // 0x800252A0: nop

    // 0x800252A4: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800252A8: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800252AC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800252B0: and         $t3, $t9, $at
    ctx->r11 = ctx->r25 & ctx->r1;
    // 0x800252B4: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x800252B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800252BC: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
L_800252C0:
    // 0x800252C0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800252C4: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x800252C8: lhu         $t4, 0x118($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X118);
    // 0x800252CC: nop

    // 0x800252D0: and         $t7, $t4, $t2
    ctx->r15 = ctx->r12 & ctx->r10;
    // 0x800252D4: beq         $t7, $zero, L_800255F0
    if (ctx->r15 == 0) {
        // 0x800252D8: nop

            goto L_800255F0;
    }
    // 0x800252D8: nop

    // 0x800252DC: lwc1        $f18, 0x108($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800252E0: lui         $at, 0xC054
    ctx->r1 = S32(0XC054 << 16);
    // 0x800252E4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800252E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800252EC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800252F0: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x800252F4: nop

    // 0x800252F8: bc1f        L_80025424
    if (!c1cs) {
        // 0x800252FC: nop

            goto L_80025424;
    }
    // 0x800252FC: nop

    // 0x80025300: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80025304: lw          $t0, 0xD70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XD70);
    // 0x80025308: nop

    // 0x8002530C: bne         $t0, $zero, L_80025424
    if (ctx->r8 != 0) {
        // 0x80025310: nop

            goto L_80025424;
    }
    // 0x80025310: nop

    // 0x80025314: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80025318: lbu         $t6, -0x6A00($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6A00);
    // 0x8002531C: nop

    // 0x80025320: bne         $t6, $zero, L_80025424
    if (ctx->r14 != 0) {
        // 0x80025324: nop

            goto L_80025424;
    }
    // 0x80025324: nop

    // 0x80025328: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002532C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80025330: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025334: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80025338: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8002533C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80025340: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80025344: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x80025348: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8002534C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80025350: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80025354: jal         0x800C3D70
    // 0x80025358: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800C3D70(rdram, ctx);
        goto after_20;
    // 0x80025358: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x8002535C: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x80025360: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80025364: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x80025368: nop

    // 0x8002536C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80025370: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x80025374: nop

    // 0x80025378: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8002537C: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x80025380: nop

    // 0x80025384: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80025388: lw          $t3, 0xC($t5)
    ctx->r11 = MEM_W(ctx->r13, 0XC);
    // 0x8002538C: nop

    // 0x80025390: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x80025394: lw          $at, 0x10($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X10);
    // 0x80025398: nop

    // 0x8002539C: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x800253A0: lw          $t3, 0x14($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X14);
    // 0x800253A4: nop

    // 0x800253A8: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x800253AC: lw          $at, 0x18($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X18);
    // 0x800253B0: nop

    // 0x800253B4: sw          $at, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r1;
    // 0x800253B8: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800253BC: nop

    // 0x800253C0: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x800253C4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800253C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800253CC: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800253D0: nop

    // 0x800253D4: div.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800253D8: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x800253DC: addiu       $t4, $zero, 0x11
    ctx->r12 = ADD32(0, 0X11);
    // 0x800253E0: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x800253E4: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x800253E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800253EC: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x800253F0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800253F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800253F8: sh          $t7, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r15;
    // 0x800253FC: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80025400: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025404: and         $t6, $t0, $at
    ctx->r14 = ctx->r8 & ctx->r1;
    // 0x80025408: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x8002540C: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80025410: nop

    // 0x80025414: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80025418: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x8002541C: b           L_80028048
    // 0x80025420: nop

        goto L_80028048;
    // 0x80025420: nop

L_80025424:
    // 0x80025424: lh          $t1, 0x12C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X12C);
    // 0x80025428: nop

    // 0x8002542C: andi        $t5, $t1, 0x8000
    ctx->r13 = ctx->r9 & 0X8000;
    // 0x80025430: beq         $t5, $zero, L_8002550C
    if (ctx->r13 == 0) {
        // 0x80025434: nop

            goto L_8002550C;
    }
    // 0x80025434: nop

    // 0x80025438: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002543C: lwc1        $f10, 0x10F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X10F8);
    // 0x80025440: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025444: lwc1        $f8, 0x1100($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1100);
    // 0x80025448: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002544C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80025450: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80025454: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80025458: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8002545C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80025460: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025464: nop

    // 0x80025468: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8002546C: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x80025470: nop

    // 0x80025474: bc1f        L_80025488
    if (!c1cs) {
        // 0x80025478: nop

            goto L_80025488;
    }
    // 0x80025478: nop

    // 0x8002547C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80025480: b           L_8002548C
    // 0x80025484: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
        goto L_8002548C;
    // 0x80025484: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
L_80025488:
    // 0x80025488: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_8002548C:
    // 0x8002548C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80025490: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x80025494: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80025498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002549C: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x800254A0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800254A4: addiu       $t0, $t0, 0x10F8
    ctx->r8 = ADD32(ctx->r8, 0X10F8);
    // 0x800254A8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800254AC: addiu       $t7, $t7, 0x1048
    ctx->r15 = ADD32(ctx->r15, 0X1048);
    // 0x800254B0: addiu       $t9, $t0, 0xA8
    ctx->r25 = ADD32(ctx->r8, 0XA8);
L_800254B4:
    // 0x800254B4: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800254B8: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800254BC: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800254C0: lw          $at, -0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X8);
    // 0x800254C4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800254C8: sw          $at, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r1;
    // 0x800254CC: lw          $at, -0x4($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X4);
    // 0x800254D0: bne         $t0, $t9, L_800254B4
    if (ctx->r8 != ctx->r25) {
        // 0x800254D4: sw          $at, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r1;
            goto L_800254B4;
    }
    // 0x800254D4: sw          $at, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r1;
    // 0x800254D8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800254DC: addiu       $t1, $t1, 0x1048
    ctx->r9 = ADD32(ctx->r9, 0X1048);
    // 0x800254E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800254E4: sw          $t1, 0x11A8($at)
    MEM_W(0X11A8, ctx->r1) = ctx->r9;
    // 0x800254E8: jal         0x80055FB8
    // 0x800254EC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_80055FB8(rdram, ctx);
        goto after_21;
    // 0x800254EC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_21:
    // 0x800254F0: lh          $a0, 0x12C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X12C);
    // 0x800254F4: nop

    // 0x800254F8: andi        $t5, $a0, 0x7FFF
    ctx->r13 = ctx->r4 & 0X7FFF;
    // 0x800254FC: jal         0x8008308C
    // 0x80025500: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_8008308C(rdram, ctx);
        goto after_22;
    // 0x80025500: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_22:
    // 0x80025504: b           L_800255C8
    // 0x80025508: nop

        goto L_800255C8;
    // 0x80025508: nop

L_8002550C:
    // 0x8002550C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80025510: lw          $t3, 0xD70($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD70);
    // 0x80025514: nop

    // 0x80025518: bne         $t3, $zero, L_80025568
    if (ctx->r11 != 0) {
        // 0x8002551C: nop

            goto L_80025568;
    }
    // 0x8002551C: nop

    // 0x80025520: jal         0x80055FB8
    // 0x80025524: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80055FB8(rdram, ctx);
        goto after_23;
    // 0x80025524: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_23:
    // 0x80025528: lh          $t4, 0x134($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X134);
    // 0x8002552C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80025530: beq         $t4, $at, L_80025558
    if (ctx->r12 == ctx->r1) {
        // 0x80025534: nop

            goto L_80025558;
    }
    // 0x80025534: nop

    // 0x80025538: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8002553C: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x80025540: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80025544: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025548: sh          $t8, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r24;
    // 0x8002554C: lh          $t6, 0x138($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X138);
    // 0x80025550: b           L_80025560
    // 0x80025554: sh          $t6, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r14;
        goto L_80025560;
    // 0x80025554: sh          $t6, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r14;
L_80025558:
    // 0x80025558: b           L_80028048
    // 0x8002555C: nop

        goto L_80028048;
    // 0x8002555C: nop

L_80025560:
    // 0x80025560: b           L_800255C8
    // 0x80025564: nop

        goto L_800255C8;
    // 0x80025564: nop

L_80025568:
    // 0x80025568: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002556C: lw          $t9, 0xD70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD70);
    // 0x80025570: lwc1        $f18, 0xF8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025574: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80025578: nop

    // 0x8002557C: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80025580: nop

    // 0x80025584: bc1f        L_80025598
    if (!c1cs) {
        // 0x80025588: nop

            goto L_80025598;
    }
    // 0x80025588: nop

    // 0x8002558C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80025590: b           L_8002559C
    // 0x80025594: sh          $t0, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r8;
        goto L_8002559C;
    // 0x80025594: sh          $t0, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r8;
L_80025598:
    // 0x80025598: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_8002559C:
    // 0x8002559C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800255A0: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x800255A4: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800255A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800255AC: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
    // 0x800255B0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800255B4: lw          $t5, 0xD70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XD70);
    // 0x800255B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800255BC: sw          $t5, 0x11A0($at)
    MEM_W(0X11A0, ctx->r1) = ctx->r13;
    // 0x800255C0: jal         0x80055FB8
    // 0x800255C4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80055FB8(rdram, ctx);
        goto after_24;
    // 0x800255C4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_24:
L_800255C8:
    // 0x800255C8: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x800255CC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800255D0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800255D4: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
    // 0x800255D8: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x800255DC: nop

    // 0x800255E0: ori         $t8, $t2, 0x1
    ctx->r24 = ctx->r10 | 0X1;
    // 0x800255E4: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x800255E8: b           L_80028048
    // 0x800255EC: nop

        goto L_80028048;
    // 0x800255EC: nop

L_800255F0:
    // 0x800255F0: lhu         $t6, 0x118($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X118);
    // 0x800255F4: lhu         $t9, 0x116($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X116);
    // 0x800255F8: nop

    // 0x800255FC: and         $t0, $t6, $t9
    ctx->r8 = ctx->r14 & ctx->r25;
    // 0x80025600: beq         $t0, $zero, L_80025800
    if (ctx->r8 == 0) {
        // 0x80025604: nop

            goto L_80025800;
    }
    // 0x80025604: nop

    // 0x80025608: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002560C: lw          $t7, 0xD70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD70);
    // 0x80025610: nop

    // 0x80025614: bne         $t7, $zero, L_800256A8
    if (ctx->r15 != 0) {
        // 0x80025618: nop

            goto L_800256A8;
    }
    // 0x80025618: nop

    // 0x8002561C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80025620: lh          $t1, 0x66C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X66C);
    // 0x80025624: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80025628: bne         $t1, $at, L_80025698
    if (ctx->r9 != ctx->r1) {
        // 0x8002562C: nop

            goto L_80025698;
    }
    // 0x8002562C: nop

    // 0x80025630: lh          $t5, 0x134($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X134);
    // 0x80025634: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80025638: beq         $t5, $at, L_80025698
    if (ctx->r13 == ctx->r1) {
        // 0x8002563C: nop

            goto L_80025698;
    }
    // 0x8002563C: nop

    // 0x80025640: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80025644: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x80025648: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002564C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025650: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
    // 0x80025654: lh          $t2, 0x138($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X138);
    // 0x80025658: nop

    // 0x8002565C: sh          $t2, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r10;
    // 0x80025660: jal         0x80055FB8
    // 0x80025664: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80055FB8(rdram, ctx);
        goto after_25;
    // 0x80025664: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_25:
    // 0x80025668: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8002566C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025670: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x80025674: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80025678: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x8002567C: nop

    // 0x80025680: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80025684: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x80025688: b           L_80028048
    // 0x8002568C: nop

        goto L_80028048;
    // 0x8002568C: nop

    // 0x80025690: b           L_800256A0
    // 0x80025694: nop

        goto L_800256A0;
    // 0x80025694: nop

L_80025698:
    // 0x80025698: b           L_80028048
    // 0x8002569C: nop

        goto L_80028048;
    // 0x8002569C: nop

L_800256A0:
    // 0x800256A0: b           L_800257D8
    // 0x800256A4: nop

        goto L_800257D8;
    // 0x800256A4: nop

L_800256A8:
    // 0x800256A8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800256AC: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x800256B0: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x800256B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800256B8: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
    // 0x800256BC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800256C0: lw          $t5, 0xD70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XD70);
    // 0x800256C4: nop

    // 0x800256C8: lh          $a0, 0x0($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X0);
    // 0x800256CC: jal         0x8002BB9C
    // 0x800256D0: nop

    func_8002BB9C(rdram, ctx);
        goto after_26;
    // 0x800256D0: nop

    after_26:
    // 0x800256D4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800256D8: lwc1        $f11, -0x1A80($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1A80);
    // 0x800256DC: lwc1        $f10, -0x1A7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A7C);
    // 0x800256E0: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl);
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800256E4: mul.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x800256E8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800256EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800256F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800256F4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800256F8: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x800256FC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80025700: swc1        $f18, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f18.u32l;
    // 0x80025704: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80025708: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002570C: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x80025710: jal         0x80022690
    // 0x80025714: nop

    func_80022690(rdram, ctx);
        goto after_27;
    // 0x80025714: nop

    after_27:
    // 0x80025718: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8002571C: lw          $t4, 0xD70($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XD70);
    // 0x80025720: nop

    // 0x80025724: lw          $t2, 0x18($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X18);
    // 0x80025728: nop

    // 0x8002572C: beq         $t2, $zero, L_800257C8
    if (ctx->r10 == 0) {
        // 0x80025730: sw          $t2, 0x9C($sp)
        MEM_W(0X9C, ctx->r29) = ctx->r10;
            goto L_800257C8;
    }
    // 0x80025730: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    // 0x80025734: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80025738: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x8002573C: lh          $t8, 0x2($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X2);
    // 0x80025740: nop

    // 0x80025744: bne         $t8, $t6, L_800257C8
    if (ctx->r24 != ctx->r14) {
        // 0x80025748: nop

            goto L_800257C8;
    }
    // 0x80025748: nop

    // 0x8002574C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80025750: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x80025754: lh          $t9, 0x4($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X4);
    // 0x80025758: nop

    // 0x8002575C: bne         $t9, $t0, L_800257C8
    if (ctx->r25 != ctx->r8) {
        // 0x80025760: nop

            goto L_800257C8;
    }
    // 0x80025760: nop

    // 0x80025764: jal         0x80023E50
    // 0x80025768: nop

    func_80023E50(rdram, ctx);
        goto after_28;
    // 0x80025768: nop

    after_28:
    // 0x8002576C: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80025770: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80025774: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80025778: lw          $t1, 0xD70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD70);
    // 0x8002577C: lw          $t7, 0x306C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X306C);
    // 0x80025780: nop

    // 0x80025784: bne         $t7, $t1, L_800257A4
    if (ctx->r15 != ctx->r9) {
        // 0x80025788: nop

            goto L_800257A4;
    }
    // 0x80025788: nop

    // 0x8002578C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80025790: lw          $t5, 0x306C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X306C);
    // 0x80025794: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80025798: lw          $t3, 0x18($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X18);
    // 0x8002579C: nop

    // 0x800257A0: sw          $t3, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = ctx->r11;
L_800257A4:
    // 0x800257A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800257A8: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800257AC: jal         0x80029394
    // 0x800257B0: nop

    func_80029394(rdram, ctx);
        goto after_29;
    // 0x800257B0: nop

    after_29:
    // 0x800257B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800257B8: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800257BC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x800257C0: jal         0x800291B4
    // 0x800257C4: nop

    func_800291B4(rdram, ctx);
        goto after_30;
    // 0x800257C4: nop

    after_30:
L_800257C8:
    // 0x800257C8: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800257CC: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800257D0: jal         0x800234D8
    // 0x800257D4: nop

    func_800234D8(rdram, ctx);
        goto after_31;
    // 0x800257D4: nop

    after_31:
L_800257D8:
    // 0x800257D8: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x800257DC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800257E0: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x800257E4: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x800257E8: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x800257EC: nop

    // 0x800257F0: ori         $t2, $t6, 0x1
    ctx->r10 = ctx->r14 | 0X1;
    // 0x800257F4: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x800257F8: b           L_80028048
    // 0x800257FC: nop

        goto L_80028048;
    // 0x800257FC: nop

L_80025800:
    // 0x80025800: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80025804: lhu         $t0, 0x11AC($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X11AC);
    // 0x80025808: lhu         $t9, 0x118($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X118);
    // 0x8002580C: nop

    // 0x80025810: and         $t7, $t9, $t0
    ctx->r15 = ctx->r25 & ctx->r8;
    // 0x80025814: beq         $t7, $zero, L_800258B0
    if (ctx->r15 == 0) {
        // 0x80025818: nop

            goto L_800258B0;
    }
    // 0x80025818: nop

    // 0x8002581C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80025820: lw          $t1, 0xD70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD70);
    // 0x80025824: nop

    // 0x80025828: beq         $t1, $zero, L_800258B0
    if (ctx->r9 == 0) {
        // 0x8002582C: nop

            goto L_800258B0;
    }
    // 0x8002582C: nop

    // 0x80025830: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80025834: lh          $t5, 0x1630($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X1630);
    // 0x80025838: nop

    // 0x8002583C: bne         $t5, $zero, L_800258B0
    if (ctx->r13 != 0) {
        // 0x80025840: nop

            goto L_800258B0;
    }
    // 0x80025840: nop

    // 0x80025844: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x80025848: lbu         $t3, -0x6A00($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X6A00);
    // 0x8002584C: nop

    // 0x80025850: bne         $t3, $zero, L_800258B0
    if (ctx->r11 != 0) {
        // 0x80025854: nop

            goto L_800258B0;
    }
    // 0x80025854: nop

    // 0x80025858: jal         0x80022690
    // 0x8002585C: nop

    func_80022690(rdram, ctx);
        goto after_32;
    // 0x8002585C: nop

    after_32:
    // 0x80025860: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025864: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025868: jal         0x800234D8
    // 0x8002586C: nop

    func_800234D8(rdram, ctx);
        goto after_33;
    // 0x8002586C: nop

    after_33:
    // 0x80025870: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80025874: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x80025878: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8002587C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025880: sh          $t8, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r24;
    // 0x80025884: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80025888: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002588C: sh          $t6, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r14;
    // 0x80025890: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80025894: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025898: and         $t9, $t2, $at
    ctx->r25 = ctx->r10 & ctx->r1;
    // 0x8002589C: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x800258A0: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x800258A4: nop

    // 0x800258A8: ori         $t7, $t0, 0x1
    ctx->r15 = ctx->r8 | 0X1;
    // 0x800258AC: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
L_800258B0:
    // 0x800258B0: b           L_80028048
    // 0x800258B4: nop

        goto L_80028048;
    // 0x800258B4: nop

L_800258B8:
    // 0x800258B8: jal         0x80022E48
    // 0x800258BC: nop

    func_80022E48(rdram, ctx);
        goto after_34;
    // 0x800258BC: nop

    after_34:
    // 0x800258C0: beq         $v0, $zero, L_8002591C
    if (ctx->r2 == 0) {
        // 0x800258C4: nop

            goto L_8002591C;
    }
    // 0x800258C4: nop

    // 0x800258C8: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800258CC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800258D0: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x800258D4: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x800258D8: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800258DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800258E0: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800258E4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800258E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800258EC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800258F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800258F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800258F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800258FC: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80025900: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    // 0x80025904: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80025908: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8002590C: sh          $t4, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r12;
    // 0x80025910: nop

    // 0x80025914: b           L_80028048
    // 0x80025918: nop

        goto L_80028048;
    // 0x80025918: nop

L_8002591C:
    // 0x8002591C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80025920: lhu         $t6, 0xFF4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XFF4);
    // 0x80025924: lhu         $t8, 0x118($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X118);
    // 0x80025928: nop

    // 0x8002592C: and         $t2, $t8, $t6
    ctx->r10 = ctx->r24 & ctx->r14;
    // 0x80025930: beq         $t2, $zero, L_8002599C
    if (ctx->r10 == 0) {
        // 0x80025934: nop

            goto L_8002599C;
    }
    // 0x80025934: nop

    // 0x80025938: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8002593C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025940: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x80025944: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80025948: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    // 0x8002594C: sh          $t0, 0x26($t7)
    MEM_H(0X26, ctx->r15) = ctx->r8;
    // 0x80025950: jal         0x80055FB8
    // 0x80025954: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_35;
    // 0x80025954: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_35:
    // 0x80025958: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8002595C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80025960: nop

    // 0x80025964: c.eq.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl == ctx->f4.fl;
    // 0x80025968: nop

    // 0x8002596C: bc1f        L_80025994
    if (!c1cs) {
        // 0x80025970: nop

            goto L_80025994;
    }
    // 0x80025970: nop

    // 0x80025974: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x80025978: sh          $t1, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r9;
    // 0x8002597C: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80025980: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025984: and         $t3, $t5, $at
    ctx->r11 = ctx->r13 & ctx->r1;
    // 0x80025988: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x8002598C: jal         0x800B9000
    // 0x80025990: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800B9000(rdram, ctx);
        goto after_36;
    // 0x80025990: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_36:
L_80025994:
    // 0x80025994: b           L_80028048
    // 0x80025998: nop

        goto L_80028048;
    // 0x80025998: nop

L_8002599C:
    // 0x8002599C: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800259A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800259A4: nop

    // 0x800259A8: c.eq.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl == ctx->f18.fl;
    // 0x800259AC: nop

    // 0x800259B0: bc1f        L_80025BA0
    if (!c1cs) {
        // 0x800259B4: nop

            goto L_80025BA0;
    }
    // 0x800259B4: nop

    // 0x800259B8: lh          $t4, 0x134($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X134);
    // 0x800259BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800259C0: beq         $t4, $at, L_80025B44
    if (ctx->r12 == ctx->r1) {
        // 0x800259C4: nop

            goto L_80025B44;
    }
    // 0x800259C4: nop

    // 0x800259C8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800259CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800259D0: sh          $t8, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r24;
    // 0x800259D4: lw          $t6, 0x120($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X120);
    // 0x800259D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800259DC: bne         $t6, $at, L_80025AE8
    if (ctx->r14 != ctx->r1) {
        // 0x800259E0: nop

            goto L_80025AE8;
    }
    // 0x800259E0: nop

    // 0x800259E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800259E8: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x800259EC: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800259F0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800259F4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800259F8: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x800259FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025A00: lwc1        $f10, 0xE78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80025A04: lwc1        $f16, 0xF8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025A08: nop

    // 0x80025A0C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80025A10: nop

    // 0x80025A14: bc1f        L_80025A24
    if (!c1cs) {
        // 0x80025A18: nop

            goto L_80025A24;
    }
    // 0x80025A18: nop

    // 0x80025A1C: b           L_80025A2C
    // 0x80025A20: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
        goto L_80025A2C;
    // 0x80025A20: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80025A24:
    // 0x80025A24: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80025A28: sh          $t7, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r15;
L_80025A2C:
    // 0x80025A2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025A30: lwc1        $f12, 0xE78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80025A34: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025A38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80025A3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025A40: lwc1        $f14, 0xEC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XEC4);
    // 0x80025A44: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80025A48: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x80025A4C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80025A50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80025A54: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80025A58: jal         0x800C3D70
    // 0x80025A5C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_37;
    // 0x80025A5C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_37:
    // 0x80025A60: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80025A64: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80025A68: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80025A6C: nop

    // 0x80025A70: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80025A74: lw          $t6, 0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4);
    // 0x80025A78: nop

    // 0x80025A7C: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x80025A80: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80025A84: nop

    // 0x80025A88: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80025A8C: lw          $t6, 0xC($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XC);
    // 0x80025A90: nop

    // 0x80025A94: sw          $t6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r14;
    // 0x80025A98: lw          $at, 0x10($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X10);
    // 0x80025A9C: nop

    // 0x80025AA0: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x80025AA4: lw          $t6, 0x14($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X14);
    // 0x80025AA8: nop

    // 0x80025AAC: sw          $t6, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r14;
    // 0x80025AB0: lw          $at, 0x18($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X18);
    // 0x80025AB4: nop

    // 0x80025AB8: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x80025ABC: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80025AC0: nop

    // 0x80025AC4: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x80025AC8: addiu       $t2, $zero, 0x5F
    ctx->r10 = ADD32(0, 0X5F);
    // 0x80025ACC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025AD0: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x80025AD4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80025AD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025ADC: sh          $t9, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r25;
    // 0x80025AE0: b           L_80028048
    // 0x80025AE4: nop

        goto L_80028048;
    // 0x80025AE4: nop

L_80025AE8:
    // 0x80025AE8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80025AEC: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x80025AF0: lhu         $t0, 0x118($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X118);
    // 0x80025AF4: nop

    // 0x80025AF8: and         $t1, $t0, $t7
    ctx->r9 = ctx->r8 & ctx->r15;
    // 0x80025AFC: beq         $t1, $zero, L_80025B3C
    if (ctx->r9 == 0) {
        // 0x80025B00: nop

            goto L_80025B3C;
    }
    // 0x80025B00: nop

    // 0x80025B04: lh          $t8, 0x134($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X134);
    // 0x80025B08: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80025B0C: bne         $t8, $at, L_80025B3C
    if (ctx->r24 != ctx->r1) {
        // 0x80025B10: nop

            goto L_80025B3C;
    }
    // 0x80025B10: nop

    // 0x80025B14: jal         0x80055FB8
    // 0x80025B18: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80055FB8(rdram, ctx);
        goto after_38;
    // 0x80025B18: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_38:
    // 0x80025B1C: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80025B20: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025B24: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80025B28: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x80025B2C: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80025B30: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x80025B34: jal         0x800B9000
    // 0x80025B38: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_39;
    // 0x80025B38: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_39:
L_80025B3C:
    // 0x80025B3C: b           L_80025B98
    // 0x80025B40: nop

        goto L_80025B98;
    // 0x80025B40: nop

L_80025B44:
    // 0x80025B44: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80025B48: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025B4C: and         $t2, $t6, $at
    ctx->r10 = ctx->r14 & ctx->r1;
    // 0x80025B50: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x80025B54: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x80025B58: nop

    // 0x80025B5C: lh          $t0, 0x26($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X26);
    // 0x80025B60: nop

    // 0x80025B64: sh          $t0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r8;
    // 0x80025B68: lh          $s0, 0xD2($sp)
    ctx->r16 = MEM_H(ctx->r29, 0XD2);
    // 0x80025B6C: nop

    // 0x80025B70: sltiu       $t7, $s0, 0x1
    ctx->r15 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80025B74: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80025B78: sh          $s0, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r16;
    // 0x80025B7C: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x80025B80: nop

    // 0x80025B84: lh          $t8, 0x26($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X26);
    // 0x80025B88: nop

    // 0x80025B8C: sh          $t8, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r24;
    // 0x80025B90: jal         0x800B9000
    // 0x80025B94: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_40;
    // 0x80025B94: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_40:
L_80025B98:
    // 0x80025B98: b           L_80025C14
    // 0x80025B9C: nop

        goto L_80025C14;
    // 0x80025B9C: nop

L_80025BA0:
    // 0x80025BA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80025BA4: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025BA8: lwc1        $f11, -0x1A78($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1A78);
    // 0x80025BAC: lwc1        $f10, -0x1A74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A74);
    // 0x80025BB0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80025BB4: mul.d       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80025BB8: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80025BBC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80025BC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80025BC4: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80025BC8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80025BCC: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x80025BD0: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x80025BD4: bc1f        L_80025BEC
    if (!c1cs) {
        // 0x80025BD8: nop

            goto L_80025BEC;
    }
    // 0x80025BD8: nop

    // 0x80025BDC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80025BE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80025BE4: nop

    // 0x80025BE8: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
L_80025BEC:
    // 0x80025BEC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80025BF0: lhu         $t5, 0x101C($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X101C);
    // 0x80025BF4: lhu         $t4, 0x118($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X118);
    // 0x80025BF8: nop

    // 0x80025BFC: and         $t3, $t4, $t5
    ctx->r11 = ctx->r12 & ctx->r13;
    // 0x80025C00: beq         $t3, $zero, L_80025C14
    if (ctx->r11 == 0) {
        // 0x80025C04: nop

            goto L_80025C14;
    }
    // 0x80025C04: nop

    // 0x80025C08: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80025C0C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80025C10: sh          $t6, 0x26($t2)
    MEM_H(0X26, ctx->r10) = ctx->r14;
L_80025C14:
    // 0x80025C14: b           L_80028048
    // 0x80025C18: nop

        goto L_80028048;
    // 0x80025C18: nop

L_80025C1C:
    // 0x80025C1C: jal         0x80022E48
    // 0x80025C20: nop

    func_80022E48(rdram, ctx);
        goto after_41;
    // 0x80025C20: nop

    after_41:
    // 0x80025C24: beq         $v0, $zero, L_80025C80
    if (ctx->r2 == 0) {
        // 0x80025C28: nop

            goto L_80025C80;
    }
    // 0x80025C28: nop

    // 0x80025C2C: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x80025C30: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80025C34: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80025C38: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x80025C3C: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80025C40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025C44: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x80025C48: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80025C4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80025C50: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80025C54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80025C58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80025C5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025C60: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80025C64: swc1        $f10, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f10.u32l;
    // 0x80025C68: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80025C6C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80025C70: sh          $t1, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r9;
    // 0x80025C74: nop

    // 0x80025C78: b           L_80028048
    // 0x80025C7C: nop

        goto L_80028048;
    // 0x80025C7C: nop

L_80025C80:
    // 0x80025C80: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80025C84: lhu         $t4, 0x101C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X101C);
    // 0x80025C88: lhu         $t8, 0x118($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X118);
    // 0x80025C8C: nop

    // 0x80025C90: and         $t5, $t8, $t4
    ctx->r13 = ctx->r24 & ctx->r12;
    // 0x80025C94: beq         $t5, $zero, L_80025D00
    if (ctx->r13 == 0) {
        // 0x80025C98: nop

            goto L_80025D00;
    }
    // 0x80025C98: nop

    // 0x80025C9C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80025CA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025CA4: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
    // 0x80025CA8: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80025CAC: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80025CB0: sh          $t6, 0x26($t2)
    MEM_H(0X26, ctx->r10) = ctx->r14;
    // 0x80025CB4: jal         0x80055FB8
    // 0x80025CB8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_42;
    // 0x80025CB8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_42:
    // 0x80025CBC: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025CC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80025CC4: nop

    // 0x80025CC8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80025CCC: nop

    // 0x80025CD0: bc1f        L_80025CF8
    if (!c1cs) {
        // 0x80025CD4: nop

            goto L_80025CF8;
    }
    // 0x80025CD4: nop

    // 0x80025CD8: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80025CDC: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
    // 0x80025CE0: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80025CE4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025CE8: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x80025CEC: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
    // 0x80025CF0: jal         0x800B9000
    // 0x80025CF4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_800B9000(rdram, ctx);
        goto after_43;
    // 0x80025CF4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_43:
L_80025CF8:
    // 0x80025CF8: b           L_80028048
    // 0x80025CFC: nop

        goto L_80028048;
    // 0x80025CFC: nop

L_80025D00:
    // 0x80025D00: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025D04: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80025D08: nop

    // 0x80025D0C: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x80025D10: nop

    // 0x80025D14: bc1f        L_80025EF0
    if (!c1cs) {
        // 0x80025D18: nop

            goto L_80025EF0;
    }
    // 0x80025D18: nop

    // 0x80025D1C: lh          $t1, 0x134($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X134);
    // 0x80025D20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80025D24: beq         $t1, $at, L_80025EA8
    if (ctx->r9 == ctx->r1) {
        // 0x80025D28: nop

            goto L_80025EA8;
    }
    // 0x80025D28: nop

    // 0x80025D2C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80025D30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025D34: sh          $t8, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r24;
    // 0x80025D38: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x80025D3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80025D40: bne         $t4, $at, L_80025E4C
    if (ctx->r12 != ctx->r1) {
        // 0x80025D44: nop

            goto L_80025E4C;
    }
    // 0x80025D44: nop

    // 0x80025D48: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80025D4C: sh          $t5, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r13;
    // 0x80025D50: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x80025D54: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80025D58: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x80025D5C: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80025D60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025D64: lwc1        $f8, 0xE78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80025D68: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80025D6C: nop

    // 0x80025D70: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80025D74: nop

    // 0x80025D78: bc1f        L_80025D88
    if (!c1cs) {
        // 0x80025D7C: nop

            goto L_80025D88;
    }
    // 0x80025D7C: nop

    // 0x80025D80: b           L_80025D90
    // 0x80025D84: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
        goto L_80025D90;
    // 0x80025D84: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80025D88:
    // 0x80025D88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80025D8C: sh          $t2, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r10;
L_80025D90:
    // 0x80025D90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025D94: lwc1        $f12, 0xE78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80025D98: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80025D9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80025DA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025DA4: lwc1        $f14, 0xEC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XEC4);
    // 0x80025DA8: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80025DAC: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x80025DB0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80025DB4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80025DB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80025DBC: jal         0x800C3D70
    // 0x80025DC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_44;
    // 0x80025DC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_44:
    // 0x80025DC4: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x80025DC8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80025DCC: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x80025DD0: nop

    // 0x80025DD4: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80025DD8: lw          $t4, 0x4($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X4);
    // 0x80025DDC: nop

    // 0x80025DE0: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80025DE4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80025DE8: nop

    // 0x80025DEC: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80025DF0: lw          $t4, 0xC($t7)
    ctx->r12 = MEM_W(ctx->r15, 0XC);
    // 0x80025DF4: nop

    // 0x80025DF8: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x80025DFC: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80025E00: nop

    // 0x80025E04: sw          $at, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r1;
    // 0x80025E08: lw          $t4, 0x14($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X14);
    // 0x80025E0C: nop

    // 0x80025E10: sw          $t4, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r12;
    // 0x80025E14: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x80025E18: nop

    // 0x80025E1C: sw          $at, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r1;
    // 0x80025E20: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80025E24: nop

    // 0x80025E28: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x80025E2C: addiu       $t5, $zero, 0x5F
    ctx->r13 = ADD32(0, 0X5F);
    // 0x80025E30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025E34: sh          $t5, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r13;
    // 0x80025E38: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80025E3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80025E40: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x80025E44: b           L_80028048
    // 0x80025E48: nop

        goto L_80028048;
    // 0x80025E48: nop

L_80025E4C:
    // 0x80025E4C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80025E50: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x80025E54: lhu         $t6, 0x118($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X118);
    // 0x80025E58: nop

    // 0x80025E5C: and         $t9, $t6, $t2
    ctx->r25 = ctx->r14 & ctx->r10;
    // 0x80025E60: beq         $t9, $zero, L_80025EA0
    if (ctx->r25 == 0) {
        // 0x80025E64: nop

            goto L_80025EA0;
    }
    // 0x80025E64: nop

    // 0x80025E68: lh          $t8, 0x134($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X134);
    // 0x80025E6C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80025E70: bne         $t8, $at, L_80025EA0
    if (ctx->r24 != ctx->r1) {
        // 0x80025E74: nop

            goto L_80025EA0;
    }
    // 0x80025E74: nop

    // 0x80025E78: jal         0x800B9000
    // 0x80025E7C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800B9000(rdram, ctx);
        goto after_45;
    // 0x80025E7C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_45:
    // 0x80025E80: jal         0x80055FB8
    // 0x80025E84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80055FB8(rdram, ctx);
        goto after_46;
    // 0x80025E84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_46:
    // 0x80025E88: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x80025E8C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025E90: and         $t0, $t1, $at
    ctx->r8 = ctx->r9 & ctx->r1;
    // 0x80025E94: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x80025E98: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80025E9C: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
L_80025EA0:
    // 0x80025EA0: b           L_80025EE8
    // 0x80025EA4: nop

        goto L_80025EE8;
    // 0x80025EA4: nop

L_80025EA8:
    // 0x80025EA8: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80025EAC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80025EB0: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80025EB4: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x80025EB8: lh          $s0, 0xD2($sp)
    ctx->r16 = MEM_H(ctx->r29, 0XD2);
    // 0x80025EBC: nop

    // 0x80025EC0: sltiu       $t3, $s0, 0x1
    ctx->r11 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80025EC4: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80025EC8: sh          $s0, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r16;
    // 0x80025ECC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80025ED0: nop

    // 0x80025ED4: lh          $t2, 0x26($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X26);
    // 0x80025ED8: nop

    // 0x80025EDC: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x80025EE0: jal         0x800B9000
    // 0x80025EE4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800B9000(rdram, ctx);
        goto after_47;
    // 0x80025EE4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_47:
L_80025EE8:
    // 0x80025EE8: b           L_80025F64
    // 0x80025EEC: nop

        goto L_80025F64;
    // 0x80025EEC: nop

L_80025EF0:
    // 0x80025EF0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80025EF4: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025EF8: lwc1        $f9, -0x1A70($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1A70);
    // 0x80025EFC: lwc1        $f8, -0x1A6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A6C);
    // 0x80025F00: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80025F04: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80025F08: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80025F0C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80025F10: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80025F14: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80025F18: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x80025F1C: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x80025F20: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x80025F24: bc1f        L_80025F3C
    if (!c1cs) {
        // 0x80025F28: nop

            goto L_80025F3C;
    }
    // 0x80025F28: nop

    // 0x80025F2C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80025F30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80025F34: nop

    // 0x80025F38: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
L_80025F3C:
    // 0x80025F3C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80025F40: lhu         $t8, 0xFF4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XFF4);
    // 0x80025F44: lhu         $t9, 0x118($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X118);
    // 0x80025F48: nop

    // 0x80025F4C: and         $t1, $t9, $t8
    ctx->r9 = ctx->r25 & ctx->r24;
    // 0x80025F50: beq         $t1, $zero, L_80025F64
    if (ctx->r9 == 0) {
        // 0x80025F54: nop

            goto L_80025F64;
    }
    // 0x80025F54: nop

    // 0x80025F58: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80025F5C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80025F60: sh          $t0, 0x26($t7)
    MEM_H(0X26, ctx->r15) = ctx->r8;
L_80025F64:
    // 0x80025F64: b           L_80028048
    // 0x80025F68: nop

        goto L_80028048;
    // 0x80025F68: nop

L_80025F6C:
    // 0x80025F6C: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80025F70: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80025F74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80025F78: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80025F7C: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80025F80: nop

    // 0x80025F84: bc1f        L_800260A8
    if (!c1cs) {
        // 0x80025F88: nop

            goto L_800260A8;
    }
    // 0x80025F88: nop

    // 0x80025F8C: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80025F90: addiu       $t4, $zero, 0x5A
    ctx->r12 = ADD32(0, 0X5A);
    // 0x80025F94: sw          $t4, 0xC8($t5)
    MEM_W(0XC8, ctx->r13) = ctx->r12;
    // 0x80025F98: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80025F9C: lw          $t6, 0xCE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE8);
    // 0x80025FA0: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x80025FA4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80025FA8: sw          $t3, 0x228($t6)
    MEM_W(0X228, ctx->r14) = ctx->r11;
    // 0x80025FAC: lw          $t2, 0xCE8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCE8);
    // 0x80025FB0: nop

    // 0x80025FB4: lw          $t9, 0x228($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X228);
    // 0x80025FB8: nop

    // 0x80025FBC: sw          $t9, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->r25;
    // 0x80025FC0: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
L_80025FC4:
    // 0x80025FC4: lh          $t0, 0x13E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X13E);
    // 0x80025FC8: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80025FCC: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80025FD0: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80025FD4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80025FD8: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80025FDC: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80025FE0: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80025FE4: addu        $t4, $t1, $t7
    ctx->r12 = ADD32(ctx->r9, ctx->r15);
    // 0x80025FE8: sh          $t8, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r24;
    // 0x80025FEC: lh          $t5, 0x13E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X13E);
    // 0x80025FF0: nop

    // 0x80025FF4: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x80025FF8: sll         $t6, $t3, 16
    ctx->r14 = S32(ctx->r11 << 16);
    // 0x80025FFC: sra         $t9, $t6, 16
    ctx->r25 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80026000: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80026004: bne         $at, $zero, L_80025FC4
    if (ctx->r1 != 0) {
        // 0x80026008: sh          $t3, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r11;
            goto L_80025FC4;
    }
    // 0x80026008: sh          $t3, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r11;
    // 0x8002600C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80026010: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x80026014: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80026018: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002601C: sh          $t2, 0x224($t0)
    MEM_H(0X224, ctx->r8) = ctx->r10;
    // 0x80026020: lw          $t1, 0xCE8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XCE8);
    // 0x80026024: nop

    // 0x80026028: lhu         $t7, 0x224($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X224);
    // 0x8002602C: nop

    // 0x80026030: sh          $t7, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r15;
    // 0x80026034: jal         0x800228A8
    // 0x80026038: nop

    func_800228A8(rdram, ctx);
        goto after_48;
    // 0x80026038: nop

    after_48:
    // 0x8002603C: jal         0x8003168C
    // 0x80026040: nop

    func_8003168C(rdram, ctx);
        goto after_49;
    // 0x80026040: nop

    after_49:
    // 0x80026044: beq         $v0, $zero, L_8002606C
    if (ctx->r2 == 0) {
        // 0x80026048: nop

            goto L_8002606C;
    }
    // 0x80026048: nop

    // 0x8002604C: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80026050: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80026054: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80026058: and         $t4, $t8, $at
    ctx->r12 = ctx->r24 & ctx->r1;
    // 0x8002605C: sw          $t4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r12;
    // 0x80026060: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026064: b           L_800260A8
    // 0x80026068: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
        goto L_800260A8;
    // 0x80026068: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
L_8002606C:
    // 0x8002606C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80026070: jal         0x800319B0
    // 0x80026074: addiu       $a0, $a0, -0x48A0
    ctx->r4 = ADD32(ctx->r4, -0X48A0);
    func_800319B0(rdram, ctx);
        goto after_50;
    // 0x80026074: addiu       $a0, $a0, -0x48A0
    ctx->r4 = ADD32(ctx->r4, -0X48A0);
    after_50:
    // 0x80026078: jal         0x80031B6C
    // 0x8002607C: nop

    func_80031B6C(rdram, ctx);
        goto after_51;
    // 0x8002607C: nop

    after_51:
    // 0x80026080: addiu       $t5, $zero, 0x12
    ctx->r13 = ADD32(0, 0X12);
    // 0x80026084: sh          $t5, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r13;
    // 0x80026088: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002608C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026090: sh          $t3, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = ctx->r11;
    // 0x80026094: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80026098: lh          $t6, 0x664($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X664);
    // 0x8002609C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800260A0: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800260A4: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
L_800260A8:
    // 0x800260A8: b           L_80028048
    // 0x800260AC: nop

        goto L_80028048;
    // 0x800260AC: nop

L_800260B0:
    // 0x800260B0: jal         0x80031AC8
    // 0x800260B4: nop

    func_80031AC8(rdram, ctx);
        goto after_52;
    // 0x800260B4: nop

    after_52:
    // 0x800260B8: bne         $v0, $zero, L_800260EC
    if (ctx->r2 != 0) {
        // 0x800260BC: nop

            goto L_800260EC;
    }
    // 0x800260BC: nop

    // 0x800260C0: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800260C4: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x800260C8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800260CC: and         $t0, $t2, $at
    ctx->r8 = ctx->r10 & ctx->r1;
    // 0x800260D0: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x800260D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800260D8: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800260DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800260E0: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
    // 0x800260E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800260E8: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_800260EC:
    // 0x800260EC: b           L_80028048
    // 0x800260F0: nop

        goto L_80028048;
    // 0x800260F0: nop

L_800260F4:
    // 0x800260F4: lw          $t7, 0x120($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X120);
    // 0x800260F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800260FC: bne         $t7, $at, L_80026128
    if (ctx->r15 != ctx->r1) {
        // 0x80026100: nop

            goto L_80026128;
    }
    // 0x80026100: nop

    // 0x80026104: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80026108: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x8002610C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80026110: and         $t8, $t1, $at
    ctx->r24 = ctx->r9 & ctx->r1;
    // 0x80026114: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80026118: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002611C: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x80026120: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026124: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_80026128:
    // 0x80026128: b           L_80028048
    // 0x8002612C: nop

        goto L_80028048;
    // 0x8002612C: nop

L_80026130:
    // 0x80026130: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80026134: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80026138: addiu       $t4, $t4, 0x5B0
    ctx->r12 = ADD32(ctx->r12, 0X5B0);
    // 0x8002613C: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x80026140: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80026144: lw          $t5, 0xD70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XD70);
    // 0x80026148: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002614C: lwc1        $f16, 0xD98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XD98);
    // 0x80026150: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80026154: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80026158: addiu       $a3, $a3, 0x5B0
    ctx->r7 = ADD32(ctx->r7, 0X5B0);
    // 0x8002615C: addiu       $a0, $a0, 0xD78
    ctx->r4 = ADD32(ctx->r4, 0XD78);
    // 0x80026160: addiu       $a1, $t5, 0x8
    ctx->r5 = ADD32(ctx->r13, 0X8);
    // 0x80026164: addiu       $a2, $t5, 0xC
    ctx->r6 = ADD32(ctx->r13, 0XC);
    // 0x80026168: jal         0x800C3F2C
    // 0x8002616C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C3F2C(rdram, ctx);
        goto after_53;
    // 0x8002616C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_53:
    // 0x80026170: lw          $t3, 0x120($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X120);
    // 0x80026174: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026178: bne         $t3, $at, L_800261C4
    if (ctx->r11 != ctx->r1) {
        // 0x8002617C: nop

            goto L_800261C4;
    }
    // 0x8002617C: nop

    // 0x80026180: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80026184: sh          $t6, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r14;
    // 0x80026188: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x8002618C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80026190: and         $t2, $t9, $at
    ctx->r10 = ctx->r25 & ctx->r1;
    // 0x80026194: sw          $t2, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r10;
    // 0x80026198: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8002619C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800261A0: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x800261A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800261A8: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800261AC: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x800261B0: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    // 0x800261B4: jal         0x8002C0FC
    // 0x800261B8: nop

    func_8002C0FC(rdram, ctx);
        goto after_54;
    // 0x800261B8: nop

    after_54:
    // 0x800261BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800261C0: sw          $zero, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = 0;
L_800261C4:
    // 0x800261C4: b           L_80028048
    // 0x800261C8: nop

        goto L_80028048;
    // 0x800261C8: nop

L_800261CC:
    // 0x800261CC: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800261D0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800261D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800261D8: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800261DC: c.eq.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d == ctx->f4.d;
    // 0x800261E0: nop

    // 0x800261E4: bc1f        L_800262F4
    if (!c1cs) {
        // 0x800261E8: nop

            goto L_800262F4;
    }
    // 0x800261E8: nop

    // 0x800261EC: lw          $t7, 0x120($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X120);
    // 0x800261F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800261F4: bne         $t7, $at, L_800262F4
    if (ctx->r15 != ctx->r1) {
        // 0x800261F8: nop

            goto L_800262F4;
    }
    // 0x800261F8: nop

    // 0x800261FC: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
    // 0x80026200: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80026208: nop

    // 0x8002620C: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80026210: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80026214: addiu       $t1, $zero, 0xDC
    ctx->r9 = ADD32(0, 0XDC);
    // 0x80026218: sw          $t1, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r9;
    // 0x8002621C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80026220: lw          $t5, 0xCE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE8);
    // 0x80026224: addiu       $t4, $zero, 0xD2
    ctx->r12 = ADD32(0, 0XD2);
    // 0x80026228: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002622C: sw          $t4, 0x228($t5)
    MEM_W(0X228, ctx->r13) = ctx->r12;
    // 0x80026230: lw          $t3, 0xCE8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XCE8);
    // 0x80026234: nop

    // 0x80026238: lw          $t6, 0x228($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X228);
    // 0x8002623C: nop

    // 0x80026240: sw          $t6, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r14;
    // 0x80026244: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
L_80026248:
    // 0x80026248: lh          $t0, 0x13E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X13E);
    // 0x8002624C: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x80026250: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80026254: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80026258: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002625C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80026260: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80026264: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80026268: addu        $t1, $t2, $t7
    ctx->r9 = ADD32(ctx->r10, ctx->r15);
    // 0x8002626C: sh          $t9, 0xC4($t1)
    MEM_H(0XC4, ctx->r9) = ctx->r25;
    // 0x80026270: lh          $t8, 0x13E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13E);
    // 0x80026274: nop

    // 0x80026278: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8002627C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80026280: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80026284: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80026288: bne         $at, $zero, L_80026248
    if (ctx->r1 != 0) {
        // 0x8002628C: sh          $t4, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r12;
            goto L_80026248;
    }
    // 0x8002628C: sh          $t4, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r12;
    // 0x80026290: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80026294: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x80026298: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8002629C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800262A0: sh          $t3, 0x224($t0)
    MEM_H(0X224, ctx->r8) = ctx->r11;
    // 0x800262A4: lw          $t2, 0xCE8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XCE8);
    // 0x800262A8: nop

    // 0x800262AC: lhu         $t7, 0x224($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X224);
    // 0x800262B0: nop

    // 0x800262B4: sh          $t7, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r15;
    // 0x800262B8: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800262BC: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
    // 0x800262C0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800262C4: sh          $t1, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r9;
    // 0x800262C8: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800262CC: sh          $t8, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r24;
    // 0x800262D0: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x800262D4: nop

    // 0x800262D8: sh          $zero, 0x2A($t4)
    MEM_H(0X2A, ctx->r12) = 0;
    // 0x800262DC: addiu       $t5, $zero, 0x3F
    ctx->r13 = ADD32(0, 0X3F);
    // 0x800262E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800262E4: sh          $t5, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r13;
    // 0x800262E8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800262EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800262F0: sh          $t6, 0x126E($at)
    MEM_H(0X126E, ctx->r1) = ctx->r14;
L_800262F4:
    // 0x800262F4: b           L_80028048
    // 0x800262F8: nop

        goto L_80028048;
    // 0x800262F8: nop

L_800262FC:
    // 0x800262FC: jal         0x80023C60
    // 0x80026300: nop

    func_80023C60(rdram, ctx);
        goto after_55;
    // 0x80026300: nop

    after_55:
    // 0x80026304: beq         $v0, $zero, L_80026314
    if (ctx->r2 == 0) {
        // 0x80026308: nop

            goto L_80026314;
    }
    // 0x80026308: nop

    // 0x8002630C: b           L_80028048
    // 0x80026310: nop

        goto L_80028048;
    // 0x80026310: nop

L_80026314:
    // 0x80026314: lh          $t3, 0x130($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X130);
    // 0x80026318: nop

    // 0x8002631C: sh          $t3, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r11;
    // 0x80026320: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x80026324: nop

    // 0x80026328: lh          $t7, 0x2A($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2A);
    // 0x8002632C: nop

    // 0x80026330: sh          $t7, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r15;
    // 0x80026334: lh          $t2, 0x13C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X13C);
    // 0x80026338: lh          $t1, 0x12A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X12A);
    // 0x8002633C: addiu       $t9, $t2, -0x2
    ctx->r25 = ADD32(ctx->r10, -0X2);
    // 0x80026340: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80026344: sra         $t4, $t8, 16
    ctx->r12 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026348: slt         $at, $t4, $t1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002634C: beq         $at, $zero, L_80026398
    if (ctx->r1 == 0) {
        // 0x80026350: sh          $t9, 0x136($sp)
        MEM_H(0X136, ctx->r29) = ctx->r25;
            goto L_80026398;
    }
    // 0x80026350: sh          $t9, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r25;
    // 0x80026354: lwc1        $f18, 0xF0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80026358: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002635C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80026360: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026364: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80026368: c.eq.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d == ctx->f10.d;
    // 0x8002636C: nop

    // 0x80026370: bc1f        L_80026398
    if (!c1cs) {
        // 0x80026374: nop

            goto L_80026398;
    }
    // 0x80026374: nop

    // 0x80026378: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002637C: sh          $t5, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r13;
    // 0x80026380: lh          $t6, 0x136($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X136);
    // 0x80026384: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x80026388: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8002638C: lbu         $t3, -0x6500($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X6500);
    // 0x80026390: nop

    // 0x80026394: sh          $t3, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r11;
L_80026398:
    // 0x80026398: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8002639C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800263A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800263A4: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800263A8: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x800263AC: nop

    // 0x800263B0: bc1f        L_8002642C
    if (!c1cs) {
        // 0x800263B4: nop

            goto L_8002642C;
    }
    // 0x800263B4: nop

    // 0x800263B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800263BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800263C0: nop

    // 0x800263C4: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x800263C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800263CC: sh          $t0, 0x112($sp)
    MEM_H(0X112, ctx->r29) = ctx->r8;
    // 0x800263D0: lhu         $t7, 0x114($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X114);
    // 0x800263D4: nop

    // 0x800263D8: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x800263DC: beq         $at, $zero, L_80026424
    if (ctx->r1 == 0) {
        // 0x800263E0: nop

            goto L_80026424;
    }
    // 0x800263E0: nop

    // 0x800263E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800263E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800263EC: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800263F0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800263F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800263F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800263FC: lhu         $t2, 0x114($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X114);
    // 0x80026400: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80026404: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80026408: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002640C: sll         $t1, $t8, 16
    ctx->r9 = S32(ctx->r24 << 16);
    // 0x80026410: sra         $t4, $t1, 16
    ctx->r12 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80026414: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80026418: sh          $t5, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r13;
    // 0x8002641C: b           L_80028048
    // 0x80026420: nop

        goto L_80028048;
    // 0x80026420: nop

L_80026424:
    // 0x80026424: b           L_80026430
    // 0x80026428: nop

        goto L_80026430;
    // 0x80026428: nop

L_8002642C:
    // 0x8002642C: sh          $zero, 0x112($sp)
    MEM_H(0X112, ctx->r29) = 0;
L_80026430:
    // 0x80026430: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80026434: lwc1        $f8, -0x7820($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80026438: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8002643C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026440: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80026444: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80026448: nop

    // 0x8002644C: bc1f        L_80026604
    if (!c1cs) {
        // 0x80026450: nop

            goto L_80026604;
    }
    // 0x80026450: nop

    // 0x80026454: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80026458: lhu         $t3, 0x126C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X126C);
    // 0x8002645C: lhu         $t6, 0x11A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X11A);
    // 0x80026460: nop

    // 0x80026464: and         $t0, $t6, $t3
    ctx->r8 = ctx->r14 & ctx->r11;
    // 0x80026468: beq         $t0, $zero, L_800264A4
    if (ctx->r8 == 0) {
        // 0x8002646C: nop

            goto L_800264A4;
    }
    // 0x8002646C: nop

    // 0x80026470: lh          $t7, 0x13C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13C);
    // 0x80026474: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80026478: beq         $t7, $at, L_800264A4
    if (ctx->r15 == ctx->r1) {
        // 0x8002647C: nop

            goto L_800264A4;
    }
    // 0x8002647C: nop

    // 0x80026480: lh          $t9, 0x12A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X12A);
    // 0x80026484: nop

    // 0x80026488: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002648C: bne         $at, $zero, L_800264A4
    if (ctx->r1 != 0) {
        // 0x80026490: nop

            goto L_800264A4;
    }
    // 0x80026490: nop

    // 0x80026494: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80026498: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002649C: b           L_80026604
    // 0x800264A0: swc1        $f18, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f18.u32l;
        goto L_80026604;
    // 0x800264A0: swc1        $f18, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f18.u32l;
L_800264A4:
    // 0x800264A4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800264A8: lhu         $t1, 0x1260($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1260);
    // 0x800264AC: lhu         $t8, 0x11A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X11A);
    // 0x800264B0: nop

    // 0x800264B4: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x800264B8: beq         $t2, $zero, L_80026604
    if (ctx->r10 == 0) {
        // 0x800264BC: nop

            goto L_80026604;
    }
    // 0x800264BC: nop

    // 0x800264C0: lh          $t4, 0x13C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X13C);
    // 0x800264C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800264C8: beq         $t4, $at, L_80026604
    if (ctx->r12 == ctx->r1) {
        // 0x800264CC: nop

            goto L_80026604;
    }
    // 0x800264CC: nop

    // 0x800264D0: lh          $t5, 0x12A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X12A);
    // 0x800264D4: nop

    // 0x800264D8: beq         $t5, $zero, L_80026604
    if (ctx->r13 == 0) {
        // 0x800264DC: nop

            goto L_80026604;
    }
    // 0x800264DC: nop

    // 0x800264E0: lh          $t6, 0x13C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X13C);
    // 0x800264E4: lh          $t3, 0x12A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X12A);
    // 0x800264E8: nop

    // 0x800264EC: subu        $t0, $t6, $t3
    ctx->r8 = SUB32(ctx->r14, ctx->r11);
    // 0x800264F0: addiu       $t9, $t0, -0x1
    ctx->r25 = ADD32(ctx->r8, -0X1);
    // 0x800264F4: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800264F8: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800264FC: blez        $t8, L_800265F4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80026500: sh          $t9, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r25;
            goto L_800265F4;
    }
    // 0x80026500: sh          $t9, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r25;
    // 0x80026504: lhu         $t1, 0x112($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X112);
    // 0x80026508: nop

    // 0x8002650C: beq         $t1, $zero, L_800265F4
    if (ctx->r9 == 0) {
        // 0x80026510: nop

            goto L_800265F4;
    }
    // 0x80026510: nop

    // 0x80026514: lh          $t2, 0x13E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X13E);
    // 0x80026518: lwc1        $f16, 0xF8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8002651C: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80026520: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80026524: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026528: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002652C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026530: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x80026534: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80026538: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8002653C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026540: sub.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f12.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80026544: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80026548: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x8002654C: jal         0x800C3D70
    // 0x80026550: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_56;
    // 0x80026550: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_56:
    // 0x80026554: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80026558: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8002655C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80026560: nop

    // 0x80026564: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80026568: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8002656C: nop

    // 0x80026570: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80026574: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80026578: nop

    // 0x8002657C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80026580: lw          $t9, 0xC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XC);
    // 0x80026584: nop

    // 0x80026588: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8002658C: lw          $at, 0x10($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X10);
    // 0x80026590: nop

    // 0x80026594: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80026598: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x8002659C: nop

    // 0x800265A0: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x800265A4: lw          $at, 0x18($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X18);
    // 0x800265A8: nop

    // 0x800265AC: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x800265B0: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800265B4: nop

    // 0x800265B8: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x800265BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800265C0: nop

    // 0x800265C4: swc1        $f10, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f10.u32l;
    // 0x800265C8: lh          $t7, 0x13C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13C);
    // 0x800265CC: lh          $t8, 0x13E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13E);
    // 0x800265D0: nop

    // 0x800265D4: subu        $t1, $t7, $t8
    ctx->r9 = SUB32(ctx->r15, ctx->r24);
    // 0x800265D8: sh          $t1, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r9;
    // 0x800265DC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800265E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800265E4: nop

    // 0x800265E8: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x800265EC: b           L_80026604
    // 0x800265F0: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
        goto L_80026604;
    // 0x800265F0: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
L_800265F4:
    // 0x800265F4: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x800265F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800265FC: nop

    // 0x80026600: swc1        $f16, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f16.u32l;
L_80026604:
    // 0x80026604: lh          $t2, 0x12E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X12E);
    // 0x80026608: nop

    // 0x8002660C: beq         $t2, $zero, L_80026638
    if (ctx->r10 == 0) {
        // 0x80026610: nop

            goto L_80026638;
    }
    // 0x80026610: nop

    // 0x80026614: lh          $t4, 0x136($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X136);
    // 0x80026618: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8002661C: addu        $a3, $a3, $t4
    ctx->r7 = ADD32(ctx->r7, ctx->r12);
    // 0x80026620: lbu         $a3, -0x6500($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X6500);
    // 0x80026624: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80026628: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8002662C: lw          $a2, 0x104($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X104);
    // 0x80026630: jal         0x80022918
    // 0x80026634: nop

    func_80022918(rdram, ctx);
        goto after_57;
    // 0x80026634: nop

    after_57:
L_80026638:
    // 0x80026638: sh          $zero, 0x136($sp)
    MEM_H(0X136, ctx->r29) = 0;
    // 0x8002663C: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026640: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80026644: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80026648: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002664C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80026650: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80026654: nop

    // 0x80026658: bc1f        L_800266A4
    if (!c1cs) {
        // 0x8002665C: nop

            goto L_800266A4;
    }
    // 0x8002665C: nop

    // 0x80026660: lh          $t5, 0x13A($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X13A);
    // 0x80026664: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026668: beq         $t5, $at, L_80026684
    if (ctx->r13 == ctx->r1) {
        // 0x8002666C: nop

            goto L_80026684;
    }
    // 0x8002666C: nop

    // 0x80026670: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80026674: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80026678: sh          $t6, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r14;
    // 0x8002667C: b           L_8002669C
    // 0x80026680: sh          $t0, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r8;
        goto L_8002669C;
    // 0x80026680: sh          $t0, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r8;
L_80026684:
    // 0x80026684: lhu         $t3, 0x112($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X112);
    // 0x80026688: nop

    // 0x8002668C: beq         $t3, $zero, L_8002669C
    if (ctx->r11 == 0) {
        // 0x80026690: nop

            goto L_8002669C;
    }
    // 0x80026690: nop

    // 0x80026694: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80026698: sh          $t9, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r25;
L_8002669C:
    // 0x8002669C: b           L_80026710
    // 0x800266A0: nop

        goto L_80026710;
    // 0x800266A0: nop

L_800266A4:
    // 0x800266A4: lwc1        $f10, 0x10C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800266A8: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800266AC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800266B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800266B4: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800266B8: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800266BC: nop

    // 0x800266C0: bc1f        L_8002670C
    if (!c1cs) {
        // 0x800266C4: nop

            goto L_8002670C;
    }
    // 0x800266C4: nop

    // 0x800266C8: lh          $t7, 0x13A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13A);
    // 0x800266CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800266D0: beq         $t7, $at, L_800266EC
    if (ctx->r15 == ctx->r1) {
        // 0x800266D4: nop

            goto L_800266EC;
    }
    // 0x800266D4: nop

    // 0x800266D8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800266DC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800266E0: sh          $t1, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r9;
    // 0x800266E4: b           L_80026704
    // 0x800266E8: sh          $t8, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r24;
        goto L_80026704;
    // 0x800266E8: sh          $t8, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r24;
L_800266EC:
    // 0x800266EC: lhu         $t2, 0x112($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X112);
    // 0x800266F0: nop

    // 0x800266F4: beq         $t2, $zero, L_80026704
    if (ctx->r10 == 0) {
        // 0x800266F8: nop

            goto L_80026704;
    }
    // 0x800266F8: nop

    // 0x800266FC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80026700: sh          $t4, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r12;
L_80026704:
    // 0x80026704: b           L_80026710
    // 0x80026708: nop

        goto L_80026710;
    // 0x80026708: nop

L_8002670C:
    // 0x8002670C: sh          $zero, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = 0;
L_80026710:
    // 0x80026710: lh          $t5, 0x136($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X136);
    // 0x80026714: nop

    // 0x80026718: beq         $t5, $zero, L_8002691C
    if (ctx->r13 == 0) {
        // 0x8002671C: nop

            goto L_8002691C;
    }
    // 0x8002671C: nop

    // 0x80026720: lhu         $t0, 0x112($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X112);
    // 0x80026724: nop

    // 0x80026728: beq         $t0, $zero, L_8002691C
    if (ctx->r8 == 0) {
        // 0x8002672C: nop

            goto L_8002691C;
    }
    // 0x8002672C: nop

    // 0x80026730: lh          $t6, 0x136($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X136);
    // 0x80026734: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026738: bne         $t6, $at, L_800267FC
    if (ctx->r14 != ctx->r1) {
        // 0x8002673C: nop

            goto L_800267FC;
    }
    // 0x8002673C: nop

    // 0x80026740: lh          $t3, 0x13C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X13C);
    // 0x80026744: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80026748: bne         $t3, $at, L_800267B0
    if (ctx->r11 != ctx->r1) {
        // 0x8002674C: nop

            goto L_800267B0;
    }
    // 0x8002674C: nop

    // 0x80026750: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80026754: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80026758: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8002675C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026760: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026764: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80026768: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x8002676C: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x80026770: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80026774: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026778: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002677C: jal         0x800C3D70
    // 0x80026780: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_58;
    // 0x80026780: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_58:
    // 0x80026784: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80026788: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002678C: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x80026790: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80026794: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80026798: nop

    // 0x8002679C: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x800267A0: jal         0x800228A8
    // 0x800267A4: nop

    func_800228A8(rdram, ctx);
        goto after_59;
    // 0x800267A4: nop

    after_59:
    // 0x800267A8: b           L_800267E8
    // 0x800267AC: nop

        goto L_800267E8;
    // 0x800267AC: nop

L_800267B0:
    // 0x800267B0: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800267B4: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800267B8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800267BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800267C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800267C4: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x800267C8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800267CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800267D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800267D4: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x800267D8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800267DC: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800267E0: jal         0x800C3D70
    // 0x800267E4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_60;
    // 0x800267E4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_60:
L_800267E8:
    // 0x800267E8: lh          $t1, 0x13C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X13C);
    // 0x800267EC: nop

    // 0x800267F0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800267F4: b           L_800268B4
    // 0x800267F8: sh          $t2, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r10;
        goto L_800268B4;
    // 0x800267F8: sh          $t2, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r10;
L_800267FC:
    // 0x800267FC: lh          $t4, 0x13C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X13C);
    // 0x80026800: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80026804: bne         $t4, $at, L_8002686C
    if (ctx->r12 != ctx->r1) {
        // 0x80026808: nop

            goto L_8002686C;
    }
    // 0x80026808: nop

    // 0x8002680C: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80026810: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80026814: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026818: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002681C: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026820: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80026824: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80026828: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x8002682C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80026830: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026834: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80026838: jal         0x800C3D70
    // 0x8002683C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800C3D70(rdram, ctx);
        goto after_61;
    // 0x8002683C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_61:
    // 0x80026840: addiu       $t0, $zero, 0x4B
    ctx->r8 = ADD32(0, 0X4B);
    // 0x80026844: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026848: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x8002684C: jal         0x800228A8
    // 0x80026850: nop

    func_800228A8(rdram, ctx);
        goto after_62;
    // 0x80026850: nop

    after_62:
    // 0x80026854: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80026858: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002685C: nop

    // 0x80026860: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x80026864: b           L_800268A4
    // 0x80026868: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
        goto L_800268A4;
    // 0x80026868: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
L_8002686C:
    // 0x8002686C: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80026870: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026874: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80026878: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002687C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026880: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x80026884: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80026888: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8002688C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026890: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x80026894: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80026898: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002689C: jal         0x800C3D70
    // 0x800268A0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_63;
    // 0x800268A0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_63:
L_800268A4:
    // 0x800268A4: lh          $t3, 0x13C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X13C);
    // 0x800268A8: nop

    // 0x800268AC: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x800268B0: sh          $t9, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r25;
L_800268B4:
    // 0x800268B4: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x800268B8: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800268BC: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x800268C0: nop

    // 0x800268C4: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800268C8: lw          $t4, 0x4($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X4);
    // 0x800268CC: nop

    // 0x800268D0: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x800268D4: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x800268D8: nop

    // 0x800268DC: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x800268E0: lw          $t4, 0xC($t8)
    ctx->r12 = MEM_W(ctx->r24, 0XC);
    // 0x800268E4: nop

    // 0x800268E8: sw          $t4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r12;
    // 0x800268EC: lw          $at, 0x10($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X10);
    // 0x800268F0: nop

    // 0x800268F4: sw          $at, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r1;
    // 0x800268F8: lw          $t4, 0x14($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X14);
    // 0x800268FC: nop

    // 0x80026900: sw          $t4, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r12;
    // 0x80026904: lw          $at, 0x18($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X18);
    // 0x80026908: nop

    // 0x8002690C: sw          $at, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r1;
    // 0x80026910: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80026914: nop

    // 0x80026918: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
L_8002691C:
    // 0x8002691C: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80026920: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80026924: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026928: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8002692C: c.eq.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d == ctx->f10.d;
    // 0x80026930: nop

    // 0x80026934: bc1f        L_80026B50
    if (!c1cs) {
        // 0x80026938: nop

            goto L_80026B50;
    }
    // 0x80026938: nop

    // 0x8002693C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80026940: lhu         $t0, 0x10F2($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X10F2);
    // 0x80026944: lhu         $t5, 0x118($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X118);
    // 0x80026948: nop

    // 0x8002694C: and         $t6, $t5, $t0
    ctx->r14 = ctx->r13 & ctx->r8;
    // 0x80026950: beq         $t6, $zero, L_8002698C
    if (ctx->r14 == 0) {
        // 0x80026954: nop

            goto L_8002698C;
    }
    // 0x80026954: nop

    // 0x80026958: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8002695C: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x80026960: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80026964: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80026968: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8002696C: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80026970: nop

    // 0x80026974: bc1f        L_8002698C
    if (!c1cs) {
        // 0x80026978: nop

            goto L_8002698C;
    }
    // 0x80026978: nop

    // 0x8002697C: addiu       $t3, $zero, 0x3E7
    ctx->r11 = ADD32(0, 0X3E7);
    // 0x80026980: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026984: b           L_80026B50
    // 0x80026988: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
        goto L_80026B50;
    // 0x80026988: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
L_8002698C:
    // 0x8002698C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80026990: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x80026994: lhu         $t9, 0x118($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X118);
    // 0x80026998: nop

    // 0x8002699C: and         $t1, $t9, $t2
    ctx->r9 = ctx->r25 & ctx->r10;
    // 0x800269A0: beq         $t1, $zero, L_80026B50
    if (ctx->r9 == 0) {
        // 0x800269A4: nop

            goto L_80026B50;
    }
    // 0x800269A4: nop

    // 0x800269A8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800269AC: lh          $t7, 0x1630($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1630);
    // 0x800269B0: nop

    // 0x800269B4: bne         $t7, $zero, L_80026B50
    if (ctx->r15 != 0) {
        // 0x800269B8: nop

            goto L_80026B50;
    }
    // 0x800269B8: nop

    // 0x800269BC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800269C0: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x800269C4: jal         0x8002A0F8
    // 0x800269C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_64;
    // 0x800269C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_64:
    // 0x800269CC: sh          $v0, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r2;
    // 0x800269D0: lh          $t4, 0x136($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X136);
    // 0x800269D4: lh          $t8, 0x13C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13C);
    // 0x800269D8: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x800269DC: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800269E0: beq         $at, $zero, L_80026B50
    if (ctx->r1 == 0) {
        // 0x800269E4: nop

            goto L_80026B50;
    }
    // 0x800269E4: nop

    // 0x800269E8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800269EC: lh          $t0, 0x1B48($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X1B48);
    // 0x800269F0: nop

    // 0x800269F4: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800269F8: beq         $at, $zero, L_80026A7C
    if (ctx->r1 == 0) {
        // 0x800269FC: nop

            goto L_80026A7C;
    }
    // 0x800269FC: nop

    // 0x80026A00: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80026A04: sh          $t6, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r14;
    // 0x80026A08: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x80026A0C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80026A10: and         $t9, $t3, $at
    ctx->r25 = ctx->r11 & ctx->r1;
    // 0x80026A14: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x80026A18: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x80026A1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026A20: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x80026A24: lh          $a1, 0x13C($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X13C);
    // 0x80026A28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80026A2C: jal         0x8002A22C
    // 0x80026A30: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_8002A22C(rdram, ctx);
        goto after_65;
    // 0x80026A30: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_65:
    // 0x80026A34: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80026A38: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80026A3C: nop

    // 0x80026A40: lh          $t7, 0x0($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X0);
    // 0x80026A44: nop

    // 0x80026A48: sh          $t7, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r15;
    // 0x80026A4C: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x80026A50: jal         0x800299C4
    // 0x80026A54: nop

    func_800299C4(rdram, ctx);
        goto after_66;
    // 0x80026A54: nop

    after_66:
    // 0x80026A58: lh          $a0, 0x13E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X13E);
    // 0x80026A5C: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x80026A60: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    // 0x80026A64: jal         0x8002C004
    // 0x80026A68: nop

    func_8002C004(rdram, ctx);
        goto after_67;
    // 0x80026A68: nop

    after_67:
    // 0x80026A6C: jal         0x80029ED8
    // 0x80026A70: nop

    func_80029ED8(rdram, ctx);
        goto after_68;
    // 0x80026A70: nop

    after_68:
    // 0x80026A74: b           L_80026B50
    // 0x80026A78: nop

        goto L_80026B50;
    // 0x80026A78: nop

L_80026A7C:
    // 0x80026A7C: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80026A80: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80026A84: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80026A88: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80026A8C: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80026A90: sh          $t5, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r13;
    // 0x80026A94: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80026A98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026A9C: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x80026AA0: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80026AA4: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026AA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026AAC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80026AB0: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x80026AB4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80026AB8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80026ABC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026AC0: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
    // 0x80026AC4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80026AC8: jal         0x800C3D70
    // 0x80026ACC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C3D70(rdram, ctx);
        goto after_69;
    // 0x80026ACC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_69:
    // 0x80026AD0: addiu       $t9, $sp, 0xB4
    ctx->r25 = ADD32(ctx->r29, 0XB4);
    // 0x80026AD4: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80026AD8: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80026ADC: nop

    // 0x80026AE0: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80026AE4: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80026AE8: nop

    // 0x80026AEC: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80026AF0: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x80026AF4: nop

    // 0x80026AF8: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x80026AFC: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x80026B00: nop

    // 0x80026B04: sw          $t7, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r15;
    // 0x80026B08: lw          $at, 0x10($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X10);
    // 0x80026B0C: nop

    // 0x80026B10: sw          $at, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r1;
    // 0x80026B14: lw          $t7, 0x14($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X14);
    // 0x80026B18: nop

    // 0x80026B1C: sw          $t7, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r15;
    // 0x80026B20: lw          $at, 0x18($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X18);
    // 0x80026B24: nop

    // 0x80026B28: sw          $at, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r1;
    // 0x80026B2C: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80026B30: nop

    // 0x80026B34: swc1        $f4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f4.u32l;
    // 0x80026B38: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80026B3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80026B40: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80026B44: nop

    // 0x80026B48: div.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80026B4C: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
L_80026B50:
    // 0x80026B50: lh          $t4, 0x13C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X13C);
    // 0x80026B54: nop

    // 0x80026B58: sh          $t4, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r12;
    // 0x80026B5C: lh          $t8, 0x13A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13A);
    // 0x80026B60: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80026B64: nop

    // 0x80026B68: sh          $t8, 0x2A($t5)
    MEM_H(0X2A, ctx->r13) = ctx->r24;
    // 0x80026B6C: b           L_80028048
    // 0x80026B70: nop

        goto L_80028048;
    // 0x80026B70: nop

L_80026B74:
    // 0x80026B74: lw          $t0, 0x120($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X120);
    // 0x80026B78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026B7C: bne         $t0, $at, L_80026B98
    if (ctx->r8 != ctx->r1) {
        // 0x80026B80: nop

            goto L_80026B98;
    }
    // 0x80026B80: nop

    // 0x80026B84: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80026B88: sh          $t6, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r14;
    // 0x80026B8C: addiu       $t1, $zero, 0x3F
    ctx->r9 = ADD32(0, 0X3F);
    // 0x80026B90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026B94: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
L_80026B98:
    // 0x80026B98: b           L_80028048
    // 0x80026B9C: nop

        goto L_80028048;
    // 0x80026B9C: nop

L_80026BA0:
    // 0x80026BA0: jal         0x80023C60
    // 0x80026BA4: nop

    func_80023C60(rdram, ctx);
        goto after_70;
    // 0x80026BA4: nop

    after_70:
    // 0x80026BA8: beq         $v0, $zero, L_80026BB8
    if (ctx->r2 == 0) {
        // 0x80026BAC: nop

            goto L_80026BB8;
    }
    // 0x80026BAC: nop

    // 0x80026BB0: b           L_80028048
    // 0x80026BB4: nop

        goto L_80028048;
    // 0x80026BB4: nop

L_80026BB8:
    // 0x80026BB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026BBC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80026BC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80026BC4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026BC8: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80026BCC: lhu         $t2, 0x114($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X114);
    // 0x80026BD0: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80026BD4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026BD8: nop

    // 0x80026BDC: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80026BE0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80026BE4: beq         $t9, $zero, L_80026C38
    if (ctx->r25 == 0) {
        // 0x80026BE8: nop

            goto L_80026C38;
    }
    // 0x80026BE8: nop

    // 0x80026BEC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80026BF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80026BF4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80026BF8: sub.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80026BFC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026C00: nop

    // 0x80026C04: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80026C08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026C0C: nop

    // 0x80026C10: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x80026C14: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80026C18: bne         $t9, $zero, L_80026C30
    if (ctx->r25 != 0) {
        // 0x80026C1C: nop

            goto L_80026C30;
    }
    // 0x80026C1C: nop

    // 0x80026C20: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80026C24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80026C28: b           L_80026C48
    // 0x80026C2C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80026C48;
    // 0x80026C2C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80026C30:
    // 0x80026C30: b           L_80026C48
    // 0x80026C34: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80026C48;
    // 0x80026C34: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80026C38:
    // 0x80026C38: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80026C3C: nop

    // 0x80026C40: bltz        $t9, L_80026C30
    if (SIGNED(ctx->r25) < 0) {
        // 0x80026C44: nop

            goto L_80026C30;
    }
    // 0x80026C44: nop

L_80026C48:
    // 0x80026C48: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x80026C4C: addu        $t4, $t2, $t7
    ctx->r12 = ADD32(ctx->r10, ctx->r15);
    // 0x80026C50: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x80026C54: slti        $at, $t8, 0x33
    ctx->r1 = SIGNED(ctx->r24) < 0X33 ? 1 : 0;
    // 0x80026C58: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80026C5C: bne         $at, $zero, L_80026C6C
    if (ctx->r1 != 0) {
        // 0x80026C60: sh          $t4, 0x114($sp)
        MEM_H(0X114, ctx->r29) = ctx->r12;
            goto L_80026C6C;
    }
    // 0x80026C60: sh          $t4, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r12;
    // 0x80026C64: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x80026C68: sh          $t5, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r13;
L_80026C6C:
    // 0x80026C6C: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80026C70: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80026C74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80026C78: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80026C7C: c.eq.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d == ctx->f18.d;
    // 0x80026C80: nop

    // 0x80026C84: bc1f        L_80026EE8
    if (!c1cs) {
        // 0x80026C88: nop

            goto L_80026EE8;
    }
    // 0x80026C88: nop

    // 0x80026C8C: lhu         $t0, 0x114($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X114);
    // 0x80026C90: nop

    // 0x80026C94: slti        $at, $t0, 0xF
    ctx->r1 = SIGNED(ctx->r8) < 0XF ? 1 : 0;
    // 0x80026C98: bne         $at, $zero, L_80026E58
    if (ctx->r1 != 0) {
        // 0x80026C9C: nop

            goto L_80026E58;
    }
    // 0x80026C9C: nop

    // 0x80026CA0: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026CA4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80026CA8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80026CAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026CB0: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80026CB4: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80026CB8: nop

    // 0x80026CBC: bc1f        L_80026D84
    if (!c1cs) {
        // 0x80026CC0: nop

            goto L_80026D84;
    }
    // 0x80026CC0: nop

    // 0x80026CC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80026CC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80026CCC: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026CD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026CD4: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026CD8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80026CDC: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80026CE0: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x80026CE4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80026CE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026CEC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80026CF0: jal         0x800C3D70
    // 0x80026CF4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_71;
    // 0x80026CF4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_71:
    // 0x80026CF8: addiu       $t3, $sp, 0xB4
    ctx->r11 = ADD32(ctx->r29, 0XB4);
    // 0x80026CFC: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80026D00: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x80026D04: nop

    // 0x80026D08: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80026D0C: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x80026D10: nop

    // 0x80026D14: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x80026D18: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80026D1C: nop

    // 0x80026D20: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80026D24: lw          $t2, 0xC($t3)
    ctx->r10 = MEM_W(ctx->r11, 0XC);
    // 0x80026D28: nop

    // 0x80026D2C: sw          $t2, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r10;
    // 0x80026D30: lw          $at, 0x10($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X10);
    // 0x80026D34: nop

    // 0x80026D38: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x80026D3C: lw          $t2, 0x14($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X14);
    // 0x80026D40: nop

    // 0x80026D44: sw          $t2, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r10;
    // 0x80026D48: lw          $at, 0x18($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X18);
    // 0x80026D4C: nop

    // 0x80026D50: sw          $at, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r1;
    // 0x80026D54: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80026D58: nop

    // 0x80026D5C: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x80026D60: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80026D64: sh          $t7, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r15;
    // 0x80026D68: addiu       $t4, $zero, 0x4E
    ctx->r12 = ADD32(0, 0X4E);
    // 0x80026D6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026D70: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
    // 0x80026D74: b           L_80028048
    // 0x80026D78: nop

        goto L_80028048;
    // 0x80026D78: nop

    // 0x80026D7C: b           L_80026E58
    // 0x80026D80: nop

        goto L_80026E58;
    // 0x80026D80: nop

L_80026D84:
    // 0x80026D84: lwc1        $f8, 0x10C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026D88: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x80026D8C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80026D90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026D94: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80026D98: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x80026D9C: nop

    // 0x80026DA0: bc1f        L_80026E58
    if (!c1cs) {
        // 0x80026DA4: nop

            goto L_80026E58;
    }
    // 0x80026DA4: nop

    // 0x80026DA8: lui         $at, 0xC230
    ctx->r1 = S32(0XC230 << 16);
    // 0x80026DAC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80026DB0: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80026DB4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026DB8: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x80026DBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80026DC0: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80026DC4: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x80026DC8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80026DCC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80026DD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80026DD4: jal         0x800C3D70
    // 0x80026DD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_72;
    // 0x80026DD8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_72:
    // 0x80026DDC: addiu       $t0, $sp, 0xB4
    ctx->r8 = ADD32(ctx->r29, 0XB4);
    // 0x80026DE0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80026DE4: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80026DE8: nop

    // 0x80026DEC: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80026DF0: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x80026DF4: nop

    // 0x80026DF8: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80026DFC: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80026E00: nop

    // 0x80026E04: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80026E08: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x80026E0C: nop

    // 0x80026E10: sw          $t9, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r25;
    // 0x80026E14: lw          $at, 0x10($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X10);
    // 0x80026E18: nop

    // 0x80026E1C: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x80026E20: lw          $t9, 0x14($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X14);
    // 0x80026E24: nop

    // 0x80026E28: sw          $t9, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r25;
    // 0x80026E2C: lw          $at, 0x18($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X18);
    // 0x80026E30: nop

    // 0x80026E34: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x80026E38: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80026E3C: nop

    // 0x80026E40: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x80026E44: addiu       $t1, $zero, 0x4D
    ctx->r9 = ADD32(0, 0X4D);
    // 0x80026E48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026E4C: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
    // 0x80026E50: b           L_80028048
    // 0x80026E54: nop

        goto L_80028048;
    // 0x80026E54: nop

L_80026E58:
    // 0x80026E58: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80026E5C: lhu         $t2, 0x10F2($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X10F2);
    // 0x80026E60: lhu         $t3, 0x118($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X118);
    // 0x80026E64: nop

    // 0x80026E68: and         $t7, $t3, $t2
    ctx->r15 = ctx->r11 & ctx->r10;
    // 0x80026E6C: beq         $t7, $zero, L_80026EE8
    if (ctx->r15 == 0) {
        // 0x80026E70: nop

            goto L_80026EE8;
    }
    // 0x80026E70: nop

    // 0x80026E74: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80026E78: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x80026E7C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80026E80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80026E84: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80026E88: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80026E8C: nop

    // 0x80026E90: bc1f        L_80026EA8
    if (!c1cs) {
        // 0x80026E94: nop

            goto L_80026EA8;
    }
    // 0x80026E94: nop

    // 0x80026E98: addiu       $t4, $zero, 0x3E7
    ctx->r12 = ADD32(0, 0X3E7);
    // 0x80026E9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026EA0: b           L_80026EE8
    // 0x80026EA4: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
        goto L_80026EE8;
    // 0x80026EA4: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
L_80026EA8:
    // 0x80026EA8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80026EAC: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80026EB0: jal         0x8002A0F8
    // 0x80026EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8002A0F8(rdram, ctx);
        goto after_73;
    // 0x80026EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_73:
    // 0x80026EB8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80026EBC: bne         $at, $zero, L_80026EE8
    if (ctx->r1 != 0) {
        // 0x80026EC0: nop

            goto L_80026EE8;
    }
    // 0x80026EC0: nop

    // 0x80026EC4: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x80026EC8: sh          $t8, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r24;
    // 0x80026ECC: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80026ED0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80026ED4: and         $t5, $t6, $at
    ctx->r13 = ctx->r14 & ctx->r1;
    // 0x80026ED8: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x80026EDC: addiu       $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
    // 0x80026EE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026EE4: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
L_80026EE8:
    // 0x80026EE8: b           L_80028048
    // 0x80026EEC: nop

        goto L_80028048;
    // 0x80026EEC: nop

L_80026EF0:
    // 0x80026EF0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80026EF4: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x80026EF8: lhu         $t9, 0x11A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X11A);
    // 0x80026EFC: nop

    // 0x80026F00: and         $t3, $t9, $t1
    ctx->r11 = ctx->r25 & ctx->r9;
    // 0x80026F04: beq         $t3, $zero, L_80026F1C
    if (ctx->r11 == 0) {
        // 0x80026F08: nop

            goto L_80026F1C;
    }
    // 0x80026F08: nop

    // 0x80026F0C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80026F10: lhu         $a0, 0x1260($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X1260);
    // 0x80026F14: jal         0x80023CA0
    // 0x80026F18: nop

    func_80023CA0(rdram, ctx);
        goto after_74;
    // 0x80026F18: nop

    after_74:
L_80026F1C:
    // 0x80026F1C: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026F20: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026F24: nop

    // 0x80026F28: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80026F2C: nop

    // 0x80026F30: bc1f        L_80026F40
    if (!c1cs) {
        // 0x80026F34: nop

            goto L_80026F40;
    }
    // 0x80026F34: nop

    // 0x80026F38: b           L_80026F4C
    // 0x80026F3C: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
        goto L_80026F4C;
    // 0x80026F3C: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
L_80026F40:
    // 0x80026F40: lwc1        $f20, 0x10C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026F44: nop

    // 0x80026F48: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f20.fl = -ctx->f20.fl;
L_80026F4C:
    // 0x80026F4C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80026F50: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80026F54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80026F58: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x80026F5C: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x80026F60: nop

    // 0x80026F64: bc1t        L_80026F90
    if (c1cs) {
        // 0x80026F68: nop

            goto L_80026F90;
    }
    // 0x80026F68: nop

    // 0x80026F6C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80026F70: lwc1        $f16, -0x7820($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80026F74: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80026F78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80026F7C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80026F80: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x80026F84: nop

    // 0x80026F88: bc1f        L_80026FB4
    if (!c1cs) {
        // 0x80026F8C: nop

            goto L_80026FB4;
    }
    // 0x80026F8C: nop

L_80026F90:
    // 0x80026F90: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80026F94: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x80026F98: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x80026F9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80026FA0: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x80026FA4: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80026FA8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80026FAC: and         $t8, $t4, $at
    ctx->r24 = ctx->r12 & ctx->r1;
    // 0x80026FB0: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
L_80026FB4:
    // 0x80026FB4: b           L_80028048
    // 0x80026FB8: nop

        goto L_80028048;
    // 0x80026FB8: nop

L_80026FBC:
    // 0x80026FBC: jal         0x80023C60
    // 0x80026FC0: nop

    func_80023C60(rdram, ctx);
        goto after_75;
    // 0x80026FC0: nop

    after_75:
    // 0x80026FC4: beq         $v0, $zero, L_80026FD4
    if (ctx->r2 == 0) {
        // 0x80026FC8: nop

            goto L_80026FD4;
    }
    // 0x80026FC8: nop

    // 0x80026FCC: b           L_80028048
    // 0x80026FD0: nop

        goto L_80028048;
    // 0x80026FD0: nop

L_80026FD4:
    // 0x80026FD4: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80026FD8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80026FDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80026FE0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80026FE4: c.eq.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d == ctx->f8.d;
    // 0x80026FE8: nop

    // 0x80026FEC: bc1f        L_80027144
    if (!c1cs) {
        // 0x80026FF0: nop

            goto L_80027144;
    }
    // 0x80026FF0: nop

    // 0x80026FF4: lwc1        $f16, 0x10C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80026FF8: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80026FFC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80027000: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027004: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80027008: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8002700C: nop

    // 0x80027010: bc1f        L_800270DC
    if (!c1cs) {
        // 0x80027014: nop

            goto L_800270DC;
    }
    // 0x80027014: nop

    // 0x80027018: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x8002701C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80027020: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80027024: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80027028: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x8002702C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80027030: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x80027034: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x80027038: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8002703C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80027040: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80027044: jal         0x800C3D70
    // 0x80027048: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800C3D70(rdram, ctx);
        goto after_76;
    // 0x80027048: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_76:
    // 0x8002704C: addiu       $t0, $sp, 0xB4
    ctx->r8 = ADD32(ctx->r29, 0XB4);
    // 0x80027050: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80027054: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80027058: nop

    // 0x8002705C: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80027060: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80027064: nop

    // 0x80027068: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x8002706C: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80027070: nop

    // 0x80027074: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80027078: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8002707C: nop

    // 0x80027080: sw          $t1, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r9;
    // 0x80027084: lw          $at, 0x10($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X10);
    // 0x80027088: nop

    // 0x8002708C: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x80027090: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x80027094: nop

    // 0x80027098: sw          $t1, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r9;
    // 0x8002709C: lw          $at, 0x18($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X18);
    // 0x800270A0: nop

    // 0x800270A4: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x800270A8: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800270AC: nop

    // 0x800270B0: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x800270B4: lh          $t3, 0x130($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X130);
    // 0x800270B8: nop

    // 0x800270BC: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x800270C0: sh          $t2, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r10;
    // 0x800270C4: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
    // 0x800270C8: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x800270CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800270D0: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
    // 0x800270D4: b           L_80028048
    // 0x800270D8: nop

        goto L_80028048;
    // 0x800270D8: nop

L_800270DC:
    // 0x800270DC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800270E0: lhu         $t8, 0x10F2($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X10F2);
    // 0x800270E4: lhu         $t4, 0x118($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X118);
    // 0x800270E8: nop

    // 0x800270EC: and         $t6, $t4, $t8
    ctx->r14 = ctx->r12 & ctx->r24;
    // 0x800270F0: beq         $t6, $zero, L_80027144
    if (ctx->r14 == 0) {
        // 0x800270F4: nop

            goto L_80027144;
    }
    // 0x800270F4: nop

    // 0x800270F8: lwc1        $f16, 0x108($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800270FC: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x80027100: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80027104: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027108: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8002710C: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80027110: nop

    // 0x80027114: bc1f        L_8002712C
    if (!c1cs) {
        // 0x80027118: nop

            goto L_8002712C;
    }
    // 0x80027118: nop

    // 0x8002711C: addiu       $t9, $zero, 0x3E7
    ctx->r25 = ADD32(0, 0X3E7);
    // 0x80027120: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027124: b           L_80027144
    // 0x80027128: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
        goto L_80027144;
    // 0x80027128: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
L_8002712C:
    // 0x8002712C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80027130: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80027134: lhu         $t0, 0x0($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X0);
    // 0x80027138: nop

    // 0x8002713C: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80027140: sh          $t1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r9;
L_80027144:
    // 0x80027144: b           L_80028048
    // 0x80027148: nop

        goto L_80028048;
    // 0x80027148: nop

L_8002714C:
    // 0x8002714C: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027150: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80027154: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80027158: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8002715C: c.eq.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d == ctx->f8.d;
    // 0x80027160: nop

    // 0x80027164: bc1f        L_8002717C
    if (!c1cs) {
        // 0x80027168: nop

            goto L_8002717C;
    }
    // 0x80027168: nop

    // 0x8002716C: addiu       $t3, $zero, 0x3F
    ctx->r11 = ADD32(0, 0X3F);
    // 0x80027170: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027174: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
    // 0x80027178: sh          $zero, 0x114($sp)
    MEM_H(0X114, ctx->r29) = 0;
L_8002717C:
    // 0x8002717C: b           L_80028048
    // 0x80027180: nop

        goto L_80028048;
    // 0x80027180: nop

L_80027184:
    // 0x80027184: jal         0x80023C60
    // 0x80027188: nop

    func_80023C60(rdram, ctx);
        goto after_77;
    // 0x80027188: nop

    after_77:
    // 0x8002718C: beq         $v0, $zero, L_8002719C
    if (ctx->r2 == 0) {
        // 0x80027190: nop

            goto L_8002719C;
    }
    // 0x80027190: nop

    // 0x80027194: b           L_80028048
    // 0x80027198: nop

        goto L_80028048;
    // 0x80027198: nop

L_8002719C:
    // 0x8002719C: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800271A0: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800271A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800271A8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800271AC: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x800271B0: nop

    // 0x800271B4: bc1f        L_80027320
    if (!c1cs) {
        // 0x800271B8: nop

            goto L_80027320;
    }
    // 0x800271B8: nop

    // 0x800271BC: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800271C0: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x800271C4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800271C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800271CC: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800271D0: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x800271D4: nop

    // 0x800271D8: bc1f        L_80027298
    if (!c1cs) {
        // 0x800271DC: nop

            goto L_80027298;
    }
    // 0x800271DC: nop

    // 0x800271E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800271E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800271E8: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800271EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800271F0: lui         $at, 0xC288
    ctx->r1 = S32(0XC288 << 16);
    // 0x800271F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800271F8: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x800271FC: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80027200: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80027204: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80027208: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002720C: jal         0x800C3D70
    // 0x80027210: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C3D70(rdram, ctx);
        goto after_78;
    // 0x80027210: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_78:
    // 0x80027214: addiu       $t4, $sp, 0xB4
    ctx->r12 = ADD32(ctx->r29, 0XB4);
    // 0x80027218: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x8002721C: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80027220: nop

    // 0x80027224: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80027228: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x8002722C: nop

    // 0x80027230: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80027234: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x80027238: nop

    // 0x8002723C: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x80027240: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x80027244: nop

    // 0x80027248: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
    // 0x8002724C: lw          $at, 0x10($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X10);
    // 0x80027250: nop

    // 0x80027254: sw          $at, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r1;
    // 0x80027258: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x8002725C: nop

    // 0x80027260: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    // 0x80027264: lw          $at, 0x18($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X18);
    // 0x80027268: nop

    // 0x8002726C: sw          $at, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r1;
    // 0x80027270: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80027274: nop

    // 0x80027278: swc1        $f6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f6.u32l;
    // 0x8002727C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80027280: sh          $t9, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r25;
    // 0x80027284: addiu       $t0, $zero, 0x4E
    ctx->r8 = ADD32(0, 0X4E);
    // 0x80027288: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002728C: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x80027290: b           L_80028048
    // 0x80027294: nop

        goto L_80028048;
    // 0x80027294: nop

L_80027298:
    // 0x80027298: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002729C: lhu         $t5, 0x10F2($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X10F2);
    // 0x800272A0: lhu         $t1, 0x118($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X118);
    // 0x800272A4: nop

    // 0x800272A8: and         $t3, $t1, $t5
    ctx->r11 = ctx->r9 & ctx->r13;
    // 0x800272AC: beq         $t3, $zero, L_80027320
    if (ctx->r11 == 0) {
        // 0x800272B0: nop

            goto L_80027320;
    }
    // 0x800272B0: nop

    // 0x800272B4: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800272B8: lui         $at, 0x4054
    ctx->r1 = S32(0X4054 << 16);
    // 0x800272BC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800272C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800272C4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800272C8: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x800272CC: nop

    // 0x800272D0: bc1f        L_800272E8
    if (!c1cs) {
        // 0x800272D4: nop

            goto L_800272E8;
    }
    // 0x800272D4: nop

    // 0x800272D8: addiu       $t2, $zero, 0x3E7
    ctx->r10 = ADD32(0, 0X3E7);
    // 0x800272DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800272E0: b           L_80027320
    // 0x800272E4: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
        goto L_80027320;
    // 0x800272E4: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
L_800272E8:
    // 0x800272E8: lh          $t8, 0x12A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X12A);
    // 0x800272EC: nop

    // 0x800272F0: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x800272F4: bne         $at, $zero, L_80027320
    if (ctx->r1 != 0) {
        // 0x800272F8: nop

            goto L_80027320;
    }
    // 0x800272F8: nop

    // 0x800272FC: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x80027300: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x80027304: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80027308: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002730C: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80027310: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80027314: addiu       $t9, $zero, 0x51
    ctx->r25 = ADD32(0, 0X51);
    // 0x80027318: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002731C: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
L_80027320:
    // 0x80027320: b           L_80028048
    // 0x80027324: nop

        goto L_80028048;
    // 0x80027324: nop

L_80027328:
    // 0x80027328: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8002732C: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x80027330: lhu         $t0, 0x11A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X11A);
    // 0x80027334: nop

    // 0x80027338: and         $t5, $t0, $t1
    ctx->r13 = ctx->r8 & ctx->r9;
    // 0x8002733C: beq         $t5, $zero, L_80027354
    if (ctx->r13 == 0) {
        // 0x80027340: nop

            goto L_80027354;
    }
    // 0x80027340: nop

    // 0x80027344: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80027348: lhu         $a0, 0x126C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X126C);
    // 0x8002734C: jal         0x80023CA0
    // 0x80027350: nop

    func_80023CA0(rdram, ctx);
        goto after_79;
    // 0x80027350: nop

    after_79:
L_80027354:
    // 0x80027354: lwc1        $f16, 0x10C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80027358: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8002735C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80027360: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80027364: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = -ctx->f16.fl;
    // 0x80027368: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8002736C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80027370: nop

    // 0x80027374: bc1t        L_800273A0
    if (c1cs) {
        // 0x80027378: nop

            goto L_800273A0;
    }
    // 0x80027378: nop

    // 0x8002737C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80027380: lwc1        $f18, -0x7820($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x80027384: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x80027388: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002738C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x80027390: c.eq.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d == ctx->f16.d;
    // 0x80027394: nop

    // 0x80027398: bc1f        L_800273C4
    if (!c1cs) {
        // 0x8002739C: nop

            goto L_800273C4;
    }
    // 0x8002739C: nop

L_800273A0:
    // 0x800273A0: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800273A4: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x800273A8: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x800273AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800273B0: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x800273B4: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x800273B8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800273BC: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x800273C0: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
L_800273C4:
    // 0x800273C4: b           L_80028048
    // 0x800273C8: nop

        goto L_80028048;
    // 0x800273C8: nop

L_800273CC:
    // 0x800273CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800273D0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800273D4: addiu       $t4, $t4, 0x5B0
    ctx->r12 = ADD32(ctx->r12, 0X5B0);
    // 0x800273D8: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800273DC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800273E0: lw          $t6, 0xD70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD70);
    // 0x800273E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800273E8: lwc1        $f6, 0xD98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XD98);
    // 0x800273EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800273F0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800273F4: addiu       $a3, $a3, 0x5B0
    ctx->r7 = ADD32(ctx->r7, 0X5B0);
    // 0x800273F8: addiu       $a0, $a0, 0xD78
    ctx->r4 = ADD32(ctx->r4, 0XD78);
    // 0x800273FC: addiu       $a1, $t6, 0x8
    ctx->r5 = ADD32(ctx->r14, 0X8);
    // 0x80027400: addiu       $a2, $t6, 0xC
    ctx->r6 = ADD32(ctx->r14, 0XC);
    // 0x80027404: jal         0x800C3F2C
    // 0x80027408: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C3F2C(rdram, ctx);
        goto after_80;
    // 0x80027408: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_80:
    // 0x8002740C: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x80027410: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027414: bne         $t9, $at, L_80027440
    if (ctx->r25 != ctx->r1) {
        // 0x80027418: nop

            goto L_80027440;
    }
    // 0x80027418: nop

    // 0x8002741C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80027420: sh          $t0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r8;
    // 0x80027424: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x80027428: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002742C: and         $t5, $t1, $at
    ctx->r13 = ctx->r9 & ctx->r1;
    // 0x80027430: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
    // 0x80027434: addiu       $t3, $zero, 0x5B
    ctx->r11 = ADD32(0, 0X5B);
    // 0x80027438: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002743C: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
L_80027440:
    // 0x80027440: b           L_80028048
    // 0x80027444: nop

        goto L_80028048;
    // 0x80027444: nop

L_80027448:
    // 0x80027448: lhu         $t2, 0x11A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X11A);
    // 0x8002744C: lhu         $t8, 0x116($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X116);
    // 0x80027450: nop

    // 0x80027454: and         $t7, $t2, $t8
    ctx->r15 = ctx->r10 & ctx->r24;
    // 0x80027458: beq         $t7, $zero, L_800274C8
    if (ctx->r15 == 0) {
        // 0x8002745C: nop

            goto L_800274C8;
    }
    // 0x8002745C: nop

    // 0x80027460: lw          $a0, 0x140($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X140);
    // 0x80027464: addiu       $a1, $sp, 0x134
    ctx->r5 = ADD32(ctx->r29, 0X134);
    // 0x80027468: jal         0x80023634
    // 0x8002746C: addiu       $a2, $sp, 0x124
    ctx->r6 = ADD32(ctx->r29, 0X124);
    func_80023634(rdram, ctx);
        goto after_81;
    // 0x8002746C: addiu       $a2, $sp, 0x124
    ctx->r6 = ADD32(ctx->r29, 0X124);
    after_81:
    // 0x80027470: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x80027474: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80027478: lwc1        $f4, 0x1B0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1B0);
    // 0x8002747C: lw          $t6, 0xD70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD70);
    // 0x80027480: swc1        $f4, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f4.u32l;
    // 0x80027484: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x80027488: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002748C: lw          $t0, 0x1B50($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B50);
    // 0x80027490: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x80027494: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80027498: lwc1        $f18, 0x1B4($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X1B4);
    // 0x8002749C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800274A0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800274A4: lw          $t1, 0xD70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD70);
    // 0x800274A8: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800274AC: swc1        $f18, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f18.u32l;
    // 0x800274B0: swc1        $f10, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f10.u32l;
    // 0x800274B4: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x800274B8: nop

    // 0x800274BC: lh          $t3, 0x24($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X24);
    // 0x800274C0: b           L_8002756C
    // 0x800274C4: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
        goto L_8002756C;
    // 0x800274C4: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
L_800274C8:
    // 0x800274C8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800274CC: lw          $t2, 0xD70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XD70);
    // 0x800274D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800274D4: lbu         $s1, 0x10($t2)
    ctx->r17 = MEM_BU(ctx->r10, 0X10);
    // 0x800274D8: lwc1        $f6, 0xDA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XDA0);
    // 0x800274DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800274E0: sll         $t8, $s1, 5
    ctx->r24 = S32(ctx->r17 << 5);
    // 0x800274E4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800274E8: sh          $s1, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r17;
    // 0x800274EC: swc1        $f6, 0x24D8($at)
    MEM_W(0X24D8, ctx->r1) = ctx->f6.u32l;
    // 0x800274F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800274F4: lwc1        $f4, 0xE48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE48);
    // 0x800274F8: lh          $t7, 0x13E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13E);
    // 0x800274FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80027500: sll         $t4, $t7, 5
    ctx->r12 = S32(ctx->r15 << 5);
    // 0x80027504: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80027508: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8002750C: swc1        $f8, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->f8.u32l;
    // 0x80027510: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80027514: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x80027518: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002751C: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x80027520: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x80027524: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027528: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x8002752C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027530: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80027534: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80027538: lw          $t0, 0xD70($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XD70);
    // 0x8002753C: nop

    // 0x80027540: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x80027544: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80027548: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002754C: sb          $t1, 0xE54($at)
    MEM_B(0XE54, ctx->r1) = ctx->r9;
    // 0x80027550: sh          $zero, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = 0;
    // 0x80027554: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027558: sw          $zero, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = 0;
    // 0x8002755C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027560: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027564: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027568: swc1        $f18, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f18.u32l;
L_8002756C:
    // 0x8002756C: b           L_80028048
    // 0x80027570: nop

        goto L_80028048;
    // 0x80027570: nop

L_80027574:
    // 0x80027574: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027578: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002757C: nop

    // 0x80027580: c.eq.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl == ctx->f10.fl;
    // 0x80027584: nop

    // 0x80027588: bc1f        L_800275B8
    if (!c1cs) {
        // 0x8002758C: nop

            goto L_800275B8;
    }
    // 0x8002758C: nop

    // 0x80027590: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80027594: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80027598: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002759C: and         $t3, $t5, $at
    ctx->r11 = ctx->r13 & ctx->r1;
    // 0x800275A0: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x800275A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800275A8: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800275AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800275B0: b           L_80027604
    // 0x800275B4: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
        goto L_80027604;
    // 0x800275B4: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_800275B8:
    // 0x800275B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800275BC: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800275C0: lwc1        $f9, -0x1A68($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1A68);
    // 0x800275C4: lwc1        $f8, -0x1A64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A64);
    // 0x800275C8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x800275CC: mul.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800275D0: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x800275D4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800275D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800275DC: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x800275E0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800275E4: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x800275E8: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
    // 0x800275EC: bc1f        L_80027604
    if (!c1cs) {
        // 0x800275F0: nop

            goto L_80027604;
    }
    // 0x800275F0: nop

    // 0x800275F4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800275F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800275FC: nop

    // 0x80027600: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
L_80027604:
    // 0x80027604: b           L_80028048
    // 0x80027608: nop

        goto L_80028048;
    // 0x80027608: nop

L_8002760C:
    // 0x8002760C: lw          $t2, 0x120($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X120);
    // 0x80027610: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027614: bne         $t2, $at, L_8002769C
    if (ctx->r10 != ctx->r1) {
        // 0x80027618: nop

            goto L_8002769C;
    }
    // 0x80027618: nop

    // 0x8002761C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80027620: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x80027624: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80027628: bne         $t8, $at, L_8002764C
    if (ctx->r24 != ctx->r1) {
        // 0x8002762C: nop

            goto L_8002764C;
    }
    // 0x8002762C: nop

    // 0x80027630: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x80027634: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x80027638: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x8002763C: nop

    // 0x80027640: ori         $t6, $t4, 0x10
    ctx->r14 = ctx->r12 | 0X10;
    // 0x80027644: b           L_80027654
    // 0x80027648: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
        goto L_80027654;
    // 0x80027648: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
L_8002764C:
    // 0x8002764C: addiu       $t9, $zero, 0x17
    ctx->r25 = ADD32(0, 0X17);
    // 0x80027650: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
L_80027654:
    // 0x80027654: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80027658: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002765C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80027660: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x80027664: addiu       $t5, $zero, 0x15
    ctx->r13 = ADD32(0, 0X15);
    // 0x80027668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002766C: sh          $t5, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r13;
    // 0x80027670: lwc1        $f8, 0x100($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X100);
    // 0x80027674: lwc1        $f18, 0xF8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80027678: nop

    // 0x8002767C: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80027680: nop

    // 0x80027684: bc1f        L_80027694
    if (!c1cs) {
        // 0x80027688: nop

            goto L_80027694;
    }
    // 0x80027688: nop

    // 0x8002768C: b           L_8002769C
    // 0x80027690: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
        goto L_8002769C;
    // 0x80027690: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_80027694:
    // 0x80027694: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80027698: sh          $t3, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r11;
L_8002769C:
    // 0x8002769C: b           L_80028048
    // 0x800276A0: nop

        goto L_80028048;
    // 0x800276A0: nop

L_800276A4:
    // 0x800276A4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800276A8: lh          $t2, 0x66C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X66C);
    // 0x800276AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800276B0: bne         $t2, $at, L_800276F4
    if (ctx->r10 != ctx->r1) {
        // 0x800276B4: nop

            goto L_800276F4;
    }
    // 0x800276B4: nop

    // 0x800276B8: lh          $t8, 0x134($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X134);
    // 0x800276BC: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800276C0: beq         $t8, $at, L_800276F4
    if (ctx->r24 == ctx->r1) {
        // 0x800276C4: nop

            goto L_800276F4;
    }
    // 0x800276C4: nop

    // 0x800276C8: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x800276CC: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x800276D0: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x800276D4: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800276D8: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x800276DC: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x800276E0: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800276E4: nop

    // 0x800276E8: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x800276EC: b           L_80027730
    // 0x800276F0: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
        goto L_80027730;
    // 0x800276F0: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
L_800276F4:
    // 0x800276F4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800276F8: lh          $t1, 0x66C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X66C);
    // 0x800276FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80027700: beq         $t1, $at, L_80027730
    if (ctx->r9 == ctx->r1) {
        // 0x80027704: nop

            goto L_80027730;
    }
    // 0x80027704: nop

    // 0x80027708: lh          $t5, 0x134($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X134);
    // 0x8002770C: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80027710: beq         $t5, $at, L_80027730
    if (ctx->r13 == ctx->r1) {
        // 0x80027714: nop

            goto L_80027730;
    }
    // 0x80027714: nop

    // 0x80027718: addiu       $t3, $zero, 0x17
    ctx->r11 = ADD32(0, 0X17);
    // 0x8002771C: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x80027720: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80027724: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027728: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x8002772C: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
L_80027730:
    // 0x80027730: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80027734: lw          $t7, 0xE64($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XE64);
    // 0x80027738: nop

    // 0x8002773C: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80027740: lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X4);
    // 0x80027744: andi        $t6, $t4, 0x4
    ctx->r14 = ctx->r12 & 0X4;
    // 0x80027748: bne         $t6, $zero, L_800277B8
    if (ctx->r14 != 0) {
        // 0x8002774C: andi        $t7, $t5, 0x0
        ctx->r15 = ctx->r13 & 0X0;
            goto L_800277B8;
    }
    // 0x8002774C: andi        $t7, $t5, 0x0
    ctx->r15 = ctx->r13 & 0X0;
    // 0x80027750: bne         $t7, $zero, L_800277B8
    if (ctx->r15 != 0) {
        // 0x80027754: nop

            goto L_800277B8;
    }
    // 0x80027754: nop

    // 0x80027758: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8002775C: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
    // 0x80027760: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80027764: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027768: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8002776C: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x80027770: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
    // 0x80027774: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027778: sh          $t3, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r11;
    // 0x8002777C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027780: lwc1        $f16, 0xE78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x80027784: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80027788: nop

    // 0x8002778C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80027790: nop

    // 0x80027794: bc1f        L_800277A4
    if (!c1cs) {
        // 0x80027798: nop

            goto L_800277A4;
    }
    // 0x80027798: nop

    // 0x8002779C: b           L_800277AC
    // 0x800277A0: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
        goto L_800277AC;
    // 0x800277A0: sh          $zero, 0x132($sp)
    MEM_H(0X132, ctx->r29) = 0;
L_800277A4:
    // 0x800277A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800277A8: sh          $t2, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r10;
L_800277AC:
    // 0x800277AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800277B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800277B4: swc1        $f6, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f6.u32l;
L_800277B8:
    // 0x800277B8: jal         0x80022E48
    // 0x800277BC: nop

    func_80022E48(rdram, ctx);
        goto after_82;
    // 0x800277BC: nop

    after_82:
    // 0x800277C0: bne         $v0, $zero, L_8002788C
    if (ctx->r2 != 0) {
        // 0x800277C4: nop

            goto L_8002788C;
    }
    // 0x800277C4: nop

    // 0x800277C8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800277CC: lh          $t8, 0x66C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X66C);
    // 0x800277D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800277D4: bne         $t8, $at, L_8002788C
    if (ctx->r24 != ctx->r1) {
        // 0x800277D8: nop

            goto L_8002788C;
    }
    // 0x800277D8: nop

    // 0x800277DC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800277E0: lhu         $t5, 0xFF4($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XFF4);
    // 0x800277E4: lhu         $t4, 0x118($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X118);
    // 0x800277E8: nop

    // 0x800277EC: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x800277F0: beq         $t6, $zero, L_80027838
    if (ctx->r14 == 0) {
        // 0x800277F4: nop

            goto L_80027838;
    }
    // 0x800277F4: nop

    // 0x800277F8: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x800277FC: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027800: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80027804: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x80027808: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    // 0x8002780C: sh          $t0, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r8;
    // 0x80027810: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x80027814: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027818: sh          $t1, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r9;
    // 0x8002781C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80027820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027824: sh          $t3, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r11;
    // 0x80027828: jal         0x80055FB8
    // 0x8002782C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_83;
    // 0x8002782C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_83:
    // 0x80027830: b           L_8002788C
    // 0x80027834: nop

        goto L_8002788C;
    // 0x80027834: nop

L_80027838:
    // 0x80027838: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002783C: lhu         $t8, 0x101C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X101C);
    // 0x80027840: lhu         $t2, 0x118($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X118);
    // 0x80027844: nop

    // 0x80027848: and         $t4, $t2, $t8
    ctx->r12 = ctx->r10 & ctx->r24;
    // 0x8002784C: beq         $t4, $zero, L_8002788C
    if (ctx->r12 == 0) {
        // 0x80027850: nop

            goto L_8002788C;
    }
    // 0x80027850: nop

    // 0x80027854: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80027858: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002785C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80027860: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80027864: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x80027868: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x8002786C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80027870: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027874: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x80027878: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8002787C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027880: sh          $t0, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = ctx->r8;
    // 0x80027884: jal         0x80055FB8
    // 0x80027888: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_84;
    // 0x80027888: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_84:
L_8002788C:
    // 0x8002788C: b           L_80028048
    // 0x80027890: nop

        goto L_80028048;
    // 0x80027890: nop

L_80027894:
    // 0x80027894: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027898: lwc1        $f4, 0x1020($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1020);
    // 0x8002789C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800278A0: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800278A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800278A8: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800278AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800278B0: swc1        $f18, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f18.u32l;
    // 0x800278B4: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x800278B8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800278BC: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800278C0: c.le.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d <= ctx->f16.d;
    // 0x800278C4: nop

    // 0x800278C8: bc1f        L_800279B0
    if (!c1cs) {
        // 0x800278CC: nop

            goto L_800279B0;
    }
    // 0x800278CC: nop

    // 0x800278D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800278D4: lwc1        $f12, 0xE78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XE78);
    // 0x800278D8: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800278DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800278E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800278E4: lwc1        $f14, 0xEC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XEC4);
    // 0x800278E8: lw          $a3, 0xF8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF8);
    // 0x800278EC: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x800278F0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800278F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800278F8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800278FC: jal         0x800C3D70
    // 0x80027900: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800C3D70(rdram, ctx);
        goto after_85;
    // 0x80027900: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_85:
    // 0x80027904: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80027908: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8002790C: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80027910: nop

    // 0x80027914: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80027918: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8002791C: nop

    // 0x80027920: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x80027924: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80027928: nop

    // 0x8002792C: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x80027930: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x80027934: nop

    // 0x80027938: sw          $t4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r12;
    // 0x8002793C: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x80027940: nop

    // 0x80027944: sw          $at, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r1;
    // 0x80027948: lw          $t4, 0x14($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X14);
    // 0x8002794C: nop

    // 0x80027950: sw          $t4, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r12;
    // 0x80027954: lw          $at, 0x18($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X18);
    // 0x80027958: nop

    // 0x8002795C: sw          $at, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r1;
    // 0x80027960: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80027964: nop

    // 0x80027968: swc1        $f8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f8.u32l;
    // 0x8002796C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80027970: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027974: lwc1        $f11, -0x1A60($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1A60);
    // 0x80027978: lwc1        $f10, -0x1A5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A5C);
    // 0x8002797C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80027980: mul.d       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x80027984: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80027988: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x8002798C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027990: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027994: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027998: swc1        $f8, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f8.u32l;
    // 0x8002799C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800279A0: lh          $t5, 0x664($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X664);
    // 0x800279A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800279A8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800279AC: sh          $t6, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r14;
L_800279B0:
    // 0x800279B0: b           L_80028048
    // 0x800279B4: nop

        goto L_80028048;
    // 0x800279B4: nop

L_800279B8:
    // 0x800279B8: lw          $t7, 0x120($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X120);
    // 0x800279BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800279C0: bne         $t7, $at, L_800279EC
    if (ctx->r15 != ctx->r1) {
        // 0x800279C4: nop

            goto L_800279EC;
    }
    // 0x800279C4: nop

    // 0x800279C8: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x800279CC: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800279D0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800279D4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800279D8: sw          $t0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r8;
    // 0x800279DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800279E0: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800279E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800279E8: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_800279EC:
    // 0x800279EC: b           L_80028048
    // 0x800279F0: nop

        goto L_80028048;
    // 0x800279F0: nop

L_800279F4:
    // 0x800279F4: jal         0x80022E48
    // 0x800279F8: nop

    func_80022E48(rdram, ctx);
        goto after_86;
    // 0x800279F8: nop

    after_86:
    // 0x800279FC: bne         $v0, $zero, L_80027A14
    if (ctx->r2 != 0) {
        // 0x80027A00: nop

            goto L_80027A14;
    }
    // 0x80027A00: nop

    // 0x80027A04: lw          $t1, 0x120($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X120);
    // 0x80027A08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027A0C: bne         $t1, $at, L_80027A4C
    if (ctx->r9 != ctx->r1) {
        // 0x80027A10: nop

            goto L_80027A4C;
    }
    // 0x80027A10: nop

L_80027A14:
    // 0x80027A14: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80027A18: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027A1C: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x80027A20: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x80027A24: addiu       $t2, $zero, 0x17
    ctx->r10 = ADD32(0, 0X17);
    // 0x80027A28: sh          $t2, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r10;
    // 0x80027A2C: addiu       $t4, $zero, 0x15
    ctx->r12 = ADD32(0, 0X15);
    // 0x80027A30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027A34: sh          $t4, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r12;
    // 0x80027A38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027A3C: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80027A40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027A44: b           L_80027AB4
    // 0x80027A48: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
        goto L_80027AB4;
    // 0x80027A48: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
L_80027A4C:
    // 0x80027A4C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80027A50: lh          $t5, 0x66C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X66C);
    // 0x80027A54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027A58: beq         $t5, $at, L_80027AB4
    if (ctx->r13 == ctx->r1) {
        // 0x80027A5C: nop

            goto L_80027AB4;
    }
    // 0x80027A5C: nop

    // 0x80027A60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80027A64: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x80027A68: lhu         $t6, 0x118($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X118);
    // 0x80027A6C: nop

    // 0x80027A70: and         $t9, $t6, $t7
    ctx->r25 = ctx->r14 & ctx->r15;
    // 0x80027A74: beq         $t9, $zero, L_80027AB4
    if (ctx->r25 == 0) {
        // 0x80027A78: nop

            goto L_80027AB4;
    }
    // 0x80027A78: nop

    // 0x80027A7C: addiu       $t0, $zero, 0x23
    ctx->r8 = ADD32(0, 0X23);
    // 0x80027A80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027A84: sh          $t0, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r8;
    // 0x80027A88: jal         0x80055FB8
    // 0x80027A8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80055FB8(rdram, ctx);
        goto after_87;
    // 0x80027A8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_87:
    // 0x80027A90: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    // 0x80027A94: sh          $t1, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r9;
    // 0x80027A98: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x80027A9C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027AA0: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x80027AA4: sw          $t3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r11;
    // 0x80027AA8: addiu       $t2, $zero, 0x23
    ctx->r10 = ADD32(0, 0X23);
    // 0x80027AAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027AB0: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
L_80027AB4:
    // 0x80027AB4: b           L_80028048
    // 0x80027AB8: nop

        goto L_80028048;
    // 0x80027AB8: nop

L_80027ABC:
    // 0x80027ABC: jal         0x80022E48
    // 0x80027AC0: nop

    func_80022E48(rdram, ctx);
        goto after_88;
    // 0x80027AC0: nop

    after_88:
    // 0x80027AC4: bne         $v0, $zero, L_80027ADC
    if (ctx->r2 != 0) {
        // 0x80027AC8: nop

            goto L_80027ADC;
    }
    // 0x80027AC8: nop

    // 0x80027ACC: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x80027AD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027AD4: bne         $t4, $at, L_80027B14
    if (ctx->r12 != ctx->r1) {
        // 0x80027AD8: nop

            goto L_80027B14;
    }
    // 0x80027AD8: nop

L_80027ADC:
    // 0x80027ADC: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80027AE0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027AE4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80027AE8: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80027AEC: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x80027AF0: sh          $t7, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r15;
    // 0x80027AF4: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x80027AF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027AFC: sh          $t9, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r25;
    // 0x80027B00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B04: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80027B08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B0C: b           L_80027B7C
    // 0x80027B10: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
        goto L_80027B7C;
    // 0x80027B10: sh          $zero, 0x66C($at)
    MEM_H(0X66C, ctx->r1) = 0;
L_80027B14:
    // 0x80027B14: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80027B18: lh          $t0, 0x66C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X66C);
    // 0x80027B1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027B20: beq         $t0, $at, L_80027B7C
    if (ctx->r8 == ctx->r1) {
        // 0x80027B24: nop

            goto L_80027B7C;
    }
    // 0x80027B24: nop

    // 0x80027B28: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80027B2C: lhu         $t8, 0x101C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X101C);
    // 0x80027B30: lhu         $t1, 0x118($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X118);
    // 0x80027B34: nop

    // 0x80027B38: and         $t3, $t1, $t8
    ctx->r11 = ctx->r9 & ctx->r24;
    // 0x80027B3C: beq         $t3, $zero, L_80027B7C
    if (ctx->r11 == 0) {
        // 0x80027B40: nop

            goto L_80027B7C;
    }
    // 0x80027B40: nop

    // 0x80027B44: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80027B48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B4C: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
    // 0x80027B50: jal         0x80055FB8
    // 0x80027B54: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80055FB8(rdram, ctx);
        goto after_89;
    // 0x80027B54: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_89:
    // 0x80027B58: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x80027B5C: sh          $t4, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r12;
    // 0x80027B60: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x80027B64: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027B68: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80027B6C: sw          $t6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r14;
    // 0x80027B70: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80027B74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B78: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
L_80027B7C:
    // 0x80027B7C: b           L_80028048
    // 0x80027B80: nop

        goto L_80028048;
    // 0x80027B80: nop

L_80027B84:
    // 0x80027B84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B88: lwc1        $f18, 0x1020($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1020);
    // 0x80027B8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027B90: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80027B94: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80027B98: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80027B9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80027BA0: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80027BA4: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80027BA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027BAC: bc1f        L_80027C0C
    if (!c1cs) {
        // 0x80027BB0: swc1        $f10, 0x1020($at)
        MEM_W(0X1020, ctx->r1) = ctx->f10.u32l;
            goto L_80027C0C;
    }
    // 0x80027BB0: swc1        $f10, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f10.u32l;
    // 0x80027BB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027BB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027BBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027BC0: swc1        $f8, 0x1020($at)
    MEM_W(0X1020, ctx->r1) = ctx->f8.u32l;
    // 0x80027BC4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80027BC8: lwc1        $f18, -0x1A58($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1A58);
    // 0x80027BCC: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80027BD0: nop

    // 0x80027BD4: swc1        $f18, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f18.u32l;
    // 0x80027BD8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80027BDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027BE0: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x80027BE4: nop

    // 0x80027BE8: swc1        $f16, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f16.u32l;
    // 0x80027BEC: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80027BF0: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80027BF4: sh          $t1, 0x11E($t8)
    MEM_H(0X11E, ctx->r24) = ctx->r9;
    // 0x80027BF8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80027BFC: lh          $t3, 0x664($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X664);
    // 0x80027C00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027C04: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80027C08: sh          $t2, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r10;
L_80027C0C:
    // 0x80027C0C: b           L_80028048
    // 0x80027C10: nop

        goto L_80028048;
    // 0x80027C10: nop

L_80027C14:
    // 0x80027C14: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
    // 0x80027C18: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x80027C1C: nop

    // 0x80027C20: lh          $t5, 0x11E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X11E);
    // 0x80027C24: nop

    // 0x80027C28: addiu       $t6, $t5, 0xF
    ctx->r14 = ADD32(ctx->r13, 0XF);
    // 0x80027C2C: sh          $t6, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = ctx->r14;
    // 0x80027C30: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80027C34: nop

    // 0x80027C38: lh          $t9, 0x11E($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X11E);
    // 0x80027C3C: nop

    // 0x80027C40: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80027C44: bne         $at, $zero, L_80027C68
    if (ctx->r1 != 0) {
        // 0x80027C48: nop

            goto L_80027C68;
    }
    // 0x80027C48: nop

    // 0x80027C4C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80027C50: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80027C54: sh          $t0, 0x11E($t1)
    MEM_H(0X11E, ctx->r9) = ctx->r8;
    // 0x80027C58: lh          $t8, 0x13E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13E);
    // 0x80027C5C: nop

    // 0x80027C60: ori         $t3, $t8, 0x1
    ctx->r11 = ctx->r24 | 0X1;
    // 0x80027C64: sh          $t3, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r11;
L_80027C68:
    // 0x80027C68: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80027C6C: lwc1        $f11, -0x1A50($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1A50);
    // 0x80027C70: lwc1        $f10, -0x1A4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A4C);
    // 0x80027C74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027C78: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80027C7C: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x80027C80: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80027C84: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80027C88: lwc1        $f18, 0xF4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XF4);
    // 0x80027C8C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80027C90: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80027C94: add.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d);
    ctx->f6.d = ctx->f16.d + ctx->f8.d;
    // 0x80027C98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80027C9C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80027CA0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80027CA4: swc1        $f10, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f10.u32l;
    // 0x80027CA8: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80027CAC: nop

    // 0x80027CB0: lwc1        $f4, 0xF4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XF4);
    // 0x80027CB4: nop

    // 0x80027CB8: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80027CBC: c.le.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d <= ctx->f18.d;
    // 0x80027CC0: nop

    // 0x80027CC4: bc1f        L_80027CF0
    if (!c1cs) {
        // 0x80027CC8: nop

            goto L_80027CF0;
    }
    // 0x80027CC8: nop

    // 0x80027CCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027CD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027CD4: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80027CD8: nop

    // 0x80027CDC: swc1        $f8, 0xF4($t6)
    MEM_W(0XF4, ctx->r14) = ctx->f8.u32l;
    // 0x80027CE0: lh          $t4, 0x13E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X13E);
    // 0x80027CE4: nop

    // 0x80027CE8: ori         $t7, $t4, 0x2
    ctx->r15 = ctx->r12 | 0X2;
    // 0x80027CEC: sh          $t7, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r15;
L_80027CF0:
    // 0x80027CF0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80027CF4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80027CF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027CFC: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80027D00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027D04: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80027D08: mul.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80027D0C: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80027D10: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80027D14: lwc1        $f16, 0xF8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x80027D18: nop

    // 0x80027D1C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80027D20: sub.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = ctx->f8.d - ctx->f18.d;
    // 0x80027D24: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80027D28: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80027D2C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80027D30: swc1        $f6, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f6.u32l;
    // 0x80027D34: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x80027D38: nop

    // 0x80027D3C: lwc1        $f4, 0xF8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x80027D40: nop

    // 0x80027D44: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80027D48: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x80027D4C: nop

    // 0x80027D50: bc1f        L_80027D7C
    if (!c1cs) {
        // 0x80027D54: nop

            goto L_80027D7C;
    }
    // 0x80027D54: nop

    // 0x80027D58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027D5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027D60: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80027D64: nop

    // 0x80027D68: swc1        $f18, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f18.u32l;
    // 0x80027D6C: lh          $t8, 0x13E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X13E);
    // 0x80027D70: nop

    // 0x80027D74: ori         $t3, $t8, 0x4
    ctx->r11 = ctx->r24 | 0X4;
    // 0x80027D78: sh          $t3, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r11;
L_80027D7C:
    // 0x80027D7C: lh          $t2, 0x13E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X13E);
    // 0x80027D80: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80027D84: bne         $t2, $at, L_80027D9C
    if (ctx->r10 != ctx->r1) {
        // 0x80027D88: nop

            goto L_80027D9C;
    }
    // 0x80027D88: nop

    // 0x80027D8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027D90: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x80027D94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027D98: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
L_80027D9C:
    // 0x80027D9C: b           L_80028048
    // 0x80027DA0: nop

        goto L_80028048;
    // 0x80027DA0: nop

L_80027DA4:
    // 0x80027DA4: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027DA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027DAC: nop

    // 0x80027DB0: c.eq.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl == ctx->f6.fl;
    // 0x80027DB4: nop

    // 0x80027DB8: bc1f        L_80027DF0
    if (!c1cs) {
        // 0x80027DBC: nop

            goto L_80027DF0;
    }
    // 0x80027DBC: nop

    // 0x80027DC0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80027DC4: lh          $t5, 0x664($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X664);
    // 0x80027DC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027DCC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80027DD0: sh          $t6, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r14;
    // 0x80027DD4: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x80027DD8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80027DDC: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x80027DE0: sw          $t7, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r15;
    // 0x80027DE4: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80027DE8: b           L_80027E3C
    // 0x80027DEC: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
        goto L_80027E3C;
    // 0x80027DEC: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
L_80027DF0:
    // 0x80027DF0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80027DF4: lwc1        $f4, 0x104($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027DF8: lwc1        $f9, -0x1A48($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1A48);
    // 0x80027DFC: lwc1        $f8, -0x1A44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A44);
    // 0x80027E00: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80027E04: mul.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x80027E08: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80027E0C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80027E10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80027E14: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x80027E18: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80027E1C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80027E20: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80027E24: bc1f        L_80027E3C
    if (!c1cs) {
        // 0x80027E28: nop

            goto L_80027E3C;
    }
    // 0x80027E28: nop

    // 0x80027E2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027E30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027E34: nop

    // 0x80027E38: swc1        $f16, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f16.u32l;
L_80027E3C:
    // 0x80027E3C: b           L_80028048
    // 0x80027E40: nop

        goto L_80028048;
    // 0x80027E40: nop

L_80027E44:
    // 0x80027E44: b           L_80028048
    // 0x80027E48: nop

        goto L_80028048;
    // 0x80027E48: nop

L_80027E4C:
    // 0x80027E4C: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80027E50: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80027E54: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80027E58: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80027E5C: c.eq.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d == ctx->f10.d;
    // 0x80027E60: nop

    // 0x80027E64: bc1f        L_80027F50
    if (!c1cs) {
        // 0x80027E68: nop

            goto L_80027F50;
    }
    // 0x80027E68: nop

    // 0x80027E6C: sh          $zero, 0x134($sp)
    MEM_H(0X134, ctx->r29) = 0;
    // 0x80027E70: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x80027E74: addiu       $at, $zero, -0xA
    ctx->r1 = ADD32(0, -0XA);
    // 0x80027E78: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80027E7C: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x80027E80: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027E84: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x80027E88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027E8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027E90: sw          $zero, 0x64C($at)
    MEM_W(0X64C, ctx->r1) = 0;
    // 0x80027E94: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027E98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027E9C: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80027EA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80027EA4: swc1        $f4, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f4.u32l;
    // 0x80027EA8: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    // 0x80027EAC: addiu       $t8, $zero, 0x5A
    ctx->r24 = ADD32(0, 0X5A);
    // 0x80027EB0: sw          $t8, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->r24;
    // 0x80027EB4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80027EB8: lw          $t5, 0xCE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XCE8);
    // 0x80027EBC: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x80027EC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80027EC4: sw          $t2, 0x228($t5)
    MEM_W(0X228, ctx->r13) = ctx->r10;
    // 0x80027EC8: lw          $t6, 0xCE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE8);
    // 0x80027ECC: nop

    // 0x80027ED0: lw          $t4, 0x228($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X228);
    // 0x80027ED4: nop

    // 0x80027ED8: sw          $t4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r12;
    // 0x80027EDC: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
L_80027EE0:
    // 0x80027EE0: lh          $t0, 0x13E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X13E);
    // 0x80027EE4: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80027EE8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80027EEC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80027EF0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80027EF4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80027EF8: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80027EFC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80027F00: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x80027F04: sh          $t7, 0xC4($t8)
    MEM_H(0XC4, ctx->r24) = ctx->r15;
    // 0x80027F08: lh          $t3, 0x13E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X13E);
    // 0x80027F0C: nop

    // 0x80027F10: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80027F14: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x80027F18: sra         $t4, $t5, 16
    ctx->r12 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80027F1C: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80027F20: bne         $at, $zero, L_80027EE0
    if (ctx->r1 != 0) {
        // 0x80027F24: sh          $t2, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r10;
            goto L_80027EE0;
    }
    // 0x80027F24: sh          $t2, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r10;
    // 0x80027F28: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80027F2C: lw          $t0, 0xCE8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE8);
    // 0x80027F30: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80027F34: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80027F38: sh          $t6, 0x224($t0)
    MEM_H(0X224, ctx->r8) = ctx->r14;
    // 0x80027F3C: lw          $t9, 0xCE8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XCE8);
    // 0x80027F40: nop

    // 0x80027F44: lhu         $t1, 0x224($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X224);
    // 0x80027F48: nop

    // 0x80027F4C: sh          $t1, 0xC4($t9)
    MEM_H(0XC4, ctx->r25) = ctx->r9;
L_80027F50:
    // 0x80027F50: b           L_80028048
    // 0x80027F54: nop

        goto L_80028048;
    // 0x80027F54: nop

L_80027F58:
    // 0x80027F58: jal         0x800228A8
    // 0x80027F5C: nop

    func_800228A8(rdram, ctx);
        goto after_90;
    // 0x80027F5C: nop

    after_90:
    // 0x80027F60: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x80027F64: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80027F68: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80027F6C: sw          $t8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r24;
    // 0x80027F70: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x80027F74: sh          $t3, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r11;
    // 0x80027F78: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80027F7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027F80: lwc1        $f16, 0xF8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80027F84: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80027F88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027F8C: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80027F90: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80027F94: addiu       $t2, $sp, 0xB4
    ctx->r10 = ADD32(ctx->r29, 0XB4);
    // 0x80027F98: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80027F9C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80027FA0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80027FA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80027FA8: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80027FAC: jal         0x800C3D70
    // 0x80027FB0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C3D70(rdram, ctx);
        goto after_91;
    // 0x80027FB0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_91:
    // 0x80027FB4: addiu       $t4, $sp, 0xB4
    ctx->r12 = ADD32(ctx->r29, 0XB4);
    // 0x80027FB8: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80027FBC: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80027FC0: nop

    // 0x80027FC4: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80027FC8: lw          $t1, 0x4($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X4);
    // 0x80027FCC: nop

    // 0x80027FD0: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x80027FD4: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x80027FD8: nop

    // 0x80027FDC: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x80027FE0: lw          $t1, 0xC($t4)
    ctx->r9 = MEM_W(ctx->r12, 0XC);
    // 0x80027FE4: nop

    // 0x80027FE8: sw          $t1, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r9;
    // 0x80027FEC: lw          $at, 0x10($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X10);
    // 0x80027FF0: nop

    // 0x80027FF4: sw          $at, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r1;
    // 0x80027FF8: lw          $t1, 0x14($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X14);
    // 0x80027FFC: nop

    // 0x80028000: sw          $t1, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r9;
    // 0x80028004: lw          $at, 0x18($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X18);
    // 0x80028008: nop

    // 0x8002800C: sw          $at, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r1;
    // 0x80028010: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80028014: nop

    // 0x80028018: swc1        $f4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f4.u32l;
    // 0x8002801C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80028020: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80028024: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80028028: nop

    // 0x8002802C: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80028030: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x80028034: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80028038: lh          $t9, 0x664($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X664);
    // 0x8002803C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028040: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x80028044: sh          $t7, 0x664($at)
    MEM_H(0X664, ctx->r1) = ctx->r15;
L_80028048:
    // 0x80028048: lw          $t8, 0x124($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X124);
    // 0x8002804C: nop

    // 0x80028050: andi        $t3, $t8, 0x2
    ctx->r11 = ctx->r24 & 0X2;
    // 0x80028054: bne         $t3, $zero, L_800280F8
    if (ctx->r11 != 0) {
        // 0x80028058: nop

            goto L_800280F8;
    }
    // 0x80028058: nop

    // 0x8002805C: lw          $t2, 0x124($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X124);
    // 0x80028060: nop

    // 0x80028064: andi        $t0, $t2, 0x10
    ctx->r8 = ctx->r10 & 0X10;
    // 0x80028068: beq         $t0, $zero, L_800280B4
    if (ctx->r8 == 0) {
        // 0x8002806C: nop

            goto L_800280B4;
    }
    // 0x8002806C: nop

    // 0x80028070: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80028074: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80028078: lh          $a2, 0x134($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X134);
    // 0x8002807C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80028080: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x80028084: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80028088: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8002808C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80028090: jal         0x800B202C
    // 0x80028094: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B202C(rdram, ctx);
        goto after_92;
    // 0x80028094: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_92:
    // 0x80028098: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002809C: sh          $v0, 0x11A6($at)
    MEM_H(0X11A6, ctx->r1) = ctx->r2;
    // 0x800280A0: lw          $t6, 0x124($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X124);
    // 0x800280A4: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800280A8: and         $t5, $t6, $at
    ctx->r13 = ctx->r14 & ctx->r1;
    // 0x800280AC: b           L_800280E8
    // 0x800280B0: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
        goto L_800280E8;
    // 0x800280B0: sw          $t5, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r13;
L_800280B4:
    // 0x800280B4: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800280B8: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800280BC: lh          $t4, 0x132($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X132);
    // 0x800280C0: lh          $a2, 0x134($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X134);
    // 0x800280C4: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800280C8: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x800280CC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800280D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800280D4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800280D8: jal         0x800B202C
    // 0x800280DC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_800B202C(rdram, ctx);
        goto after_93;
    // 0x800280DC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_93:
    // 0x800280E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800280E4: sh          $v0, 0x11A6($at)
    MEM_H(0X11A6, ctx->r1) = ctx->r2;
L_800280E8:
    // 0x800280E8: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800280EC: nop

    // 0x800280F0: ori         $t9, $t1, 0x2
    ctx->r25 = ctx->r9 | 0X2;
    // 0x800280F4: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
L_800280F8:
    // 0x800280F8: lwc1        $f8, 0xF8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800280FC: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80028100: nop

    // 0x80028104: swc1        $f8, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f8.u32l;
    // 0x80028108: lwc1        $f18, 0xF4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8002810C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80028110: nop

    // 0x80028114: swc1        $f18, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f18.u32l;
    // 0x80028118: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8002811C: lh          $t3, 0x664($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X664);
    // 0x80028120: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80028124: beq         $t3, $at, L_800281C8
    if (ctx->r11 == ctx->r1) {
        // 0x80028128: nop

            goto L_800281C8;
    }
    // 0x80028128: nop

    // 0x8002812C: jal         0x800C1850
    // 0x80028130: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_94;
    // 0x80028130: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_94:
    // 0x80028134: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x80028138: jal         0x8009A14C
    // 0x8002813C: nop

    func_8009A14C(rdram, ctx);
        goto after_95;
    // 0x8002813C: nop

    after_95:
    // 0x80028140: jal         0x800C1A84
    // 0x80028144: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_96;
    // 0x80028144: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_96:
    // 0x80028148: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8002814C: nop

    // 0x80028150: lw          $t0, 0xC8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0XC8);
    // 0x80028154: nop

    // 0x80028158: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    // 0x8002815C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80028160: lh          $t6, 0x11A6($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X11A6);
    // 0x80028164: sh          $zero, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = 0;
    // 0x80028168: blez        $t6, L_800281C8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002816C: nop

            goto L_800281C8;
    }
    // 0x8002816C: nop

L_80028170:
    // 0x80028170: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
    // 0x80028174: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x80028178: nop

    // 0x8002817C: sw          $t5, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r13;
    // 0x80028180: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x80028184: jal         0x800997D8
    // 0x80028188: nop

    func_800997D8(rdram, ctx);
        goto after_97;
    // 0x80028188: nop

    after_97:
    // 0x8002818C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80028190: nop

    // 0x80028194: addiu       $t9, $t1, 0x160
    ctx->r25 = ADD32(ctx->r9, 0X160);
    // 0x80028198: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
    // 0x8002819C: jal         0x800C1AF4
    // 0x800281A0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_98;
    // 0x800281A0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_98:
    // 0x800281A4: lh          $t7, 0x13E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X13E);
    // 0x800281A8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800281AC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800281B0: lh          $t0, 0x11A6($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X11A6);
    // 0x800281B4: sll         $t3, $t8, 16
    ctx->r11 = S32(ctx->r24 << 16);
    // 0x800281B8: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800281BC: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800281C0: bne         $at, $zero, L_80028170
    if (ctx->r1 != 0) {
        // 0x800281C4: sh          $t8, 0x13E($sp)
        MEM_H(0X13E, ctx->r29) = ctx->r24;
            goto L_80028170;
    }
    // 0x800281C4: sh          $t8, 0x13E($sp)
    MEM_H(0X13E, ctx->r29) = ctx->r24;
L_800281C8:
    // 0x800281C8: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x800281CC: jal         0x800B3434
    // 0x800281D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3434(rdram, ctx);
        goto after_99;
    // 0x800281D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_99:
    // 0x800281D4: sh          $v0, 0x110($sp)
    MEM_H(0X110, ctx->r29) = ctx->r2;
    // 0x800281D8: lhu         $t6, 0x110($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X110);
    // 0x800281DC: nop

    // 0x800281E0: andi        $t5, $t6, 0x4000
    ctx->r13 = ctx->r14 & 0X4000;
    // 0x800281E4: beq         $t5, $zero, L_80028204
    if (ctx->r13 == 0) {
        // 0x800281E8: nop

            goto L_80028204;
    }
    // 0x800281E8: nop

    // 0x800281EC: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x800281F0: jal         0x800B32E4
    // 0x800281F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B32E4(rdram, ctx);
        goto after_100;
    // 0x800281F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_100:
    // 0x800281F8: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x800281FC: jal         0x800B9000
    // 0x80028200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B9000(rdram, ctx);
        goto after_101;
    // 0x80028200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_101:
L_80028204:
    // 0x80028204: lhu         $t4, 0x110($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X110);
    // 0x80028208: nop

    // 0x8002820C: andi        $t1, $t4, 0x8000
    ctx->r9 = ctx->r12 & 0X8000;
    // 0x80028210: beq         $t1, $zero, L_80028230
    if (ctx->r9 == 0) {
        // 0x80028214: nop

            goto L_80028230;
    }
    // 0x80028214: nop

    // 0x80028218: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x8002821C: jal         0x800B32E4
    // 0x80028220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800B32E4(rdram, ctx);
        goto after_102;
    // 0x80028220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_102:
    // 0x80028224: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80028228: jal         0x800B9000
    // 0x8002822C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B9000(rdram, ctx);
        goto after_103;
    // 0x8002822C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_103:
L_80028230:
    // 0x80028230: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80028234: lbu         $t9, 0x125A($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X125A);
    // 0x80028238: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x8002823C: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80028240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028244: sb          $t7, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = ctx->r15;
    // 0x80028248: lh          $t8, 0x12C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X12C);
    // 0x8002824C: nop

    // 0x80028250: bne         $t8, $zero, L_80028260
    if (ctx->r24 != 0) {
        // 0x80028254: nop

            goto L_80028260;
    }
    // 0x80028254: nop

    // 0x80028258: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002825C: sh          $zero, 0x65C($at)
    MEM_H(0X65C, ctx->r1) = 0;
L_80028260:
    // 0x80028260: lh          $t3, 0x12E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X12E);
    // 0x80028264: nop

    // 0x80028268: beq         $t3, $zero, L_800282D0
    if (ctx->r11 == 0) {
        // 0x8002826C: nop

            goto L_800282D0;
    }
    // 0x8002826C: nop

    // 0x80028270: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80028274: lh          $t2, 0x66C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X66C);
    // 0x80028278: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002827C: beq         $t2, $at, L_800282D0
    if (ctx->r10 == ctx->r1) {
        // 0x80028280: nop

            goto L_800282D0;
    }
    // 0x80028280: nop

    // 0x80028284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80028288: beq         $t2, $at, L_800282D0
    if (ctx->r10 == ctx->r1) {
        // 0x8002828C: nop

            goto L_800282D0;
    }
    // 0x8002828C: nop

    // 0x80028290: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80028294: lh          $t0, 0x664($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X664);
    // 0x80028298: nop

    // 0x8002829C: beq         $t0, $zero, L_800282BC
    if (ctx->r8 == 0) {
        // 0x800282A0: nop

            goto L_800282BC;
    }
    // 0x800282A0: nop

    // 0x800282A4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800282A8: beq         $t0, $at, L_800282BC
    if (ctx->r8 == ctx->r1) {
        // 0x800282AC: nop

            goto L_800282BC;
    }
    // 0x800282AC: nop

    // 0x800282B0: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x800282B4: bne         $t0, $at, L_800282D0
    if (ctx->r8 != ctx->r1) {
        // 0x800282B8: nop

            goto L_800282D0;
    }
    // 0x800282B8: nop

L_800282BC:
    // 0x800282BC: lh          $a0, 0x12C($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X12C);
    // 0x800282C0: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x800282C4: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    // 0x800282C8: jal         0x80022EE4
    // 0x800282CC: nop

    func_80022EE4(rdram, ctx);
        goto after_104;
    // 0x800282CC: nop

    after_104:
L_800282D0:
    // 0x800282D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800282D4: lw          $t6, 0x103C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X103C);
    // 0x800282D8: nop

    // 0x800282DC: beq         $t6, $zero, L_800282F4
    if (ctx->r14 == 0) {
        // 0x800282E0: nop

            goto L_800282F4;
    }
    // 0x800282E0: nop

    // 0x800282E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800282E8: lw          $a0, 0x103C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X103C);
    // 0x800282EC: jal         0x800BC980
    // 0x800282F0: nop

    SysMem_Free(rdram, ctx);
        goto after_105;
    // 0x800282F0: nop

    after_105:
L_800282F4:
    // 0x800282F4: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x800282F8: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x800282FC: nop

    // 0x80028300: sw          $t5, 0x1A8($t4)
    MEM_W(0X1A8, ctx->r12) = ctx->r13;
    // 0x80028304: lwc1        $f10, 0xF8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80028308: lw          $t1, 0x140($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X140);
    // 0x8002830C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028310: swc1        $f10, 0x1B0($t1)
    MEM_W(0X1B0, ctx->r9) = ctx->f10.u32l;
    // 0x80028314: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x80028318: nop

    // 0x8002831C: lwc1        $f6, 0x1B0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1B0);
    // 0x80028320: nop

    // 0x80028324: swc1        $f6, 0xE60($at)
    MEM_W(0XE60, ctx->r1) = ctx->f6.u32l;
    // 0x80028328: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8002832C: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x80028330: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028334: swc1        $f4, 0x1B4($t7)
    MEM_W(0X1B4, ctx->r15) = ctx->f4.u32l;
    // 0x80028338: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8002833C: nop

    // 0x80028340: lwc1        $f16, 0x1B4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X1B4);
    // 0x80028344: nop

    // 0x80028348: swc1        $f16, 0xE6C($at)
    MEM_W(0XE6C, ctx->r1) = ctx->f16.u32l;
    // 0x8002834C: lh          $t3, 0x134($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X134);
    // 0x80028350: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80028354: nop

    // 0x80028358: sh          $t3, 0x22($t2)
    MEM_H(0X22, ctx->r10) = ctx->r11;
    // 0x8002835C: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x80028360: nop

    // 0x80028364: lh          $t6, 0x20($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X20);
    // 0x80028368: nop

    // 0x8002836C: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80028370: sh          $t5, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r13;
    // 0x80028374: lwc1        $f8, 0x104($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80028378: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x8002837C: nop

    // 0x80028380: swc1        $f8, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f8.u32l;
    // 0x80028384: lh          $t1, 0x132($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X132);
    // 0x80028388: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8002838C: nop

    // 0x80028390: sh          $t1, 0x24($t9)
    MEM_H(0X24, ctx->r25) = ctx->r9;
    // 0x80028394: lh          $t7, 0x130($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X130);
    // 0x80028398: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x8002839C: nop

    // 0x800283A0: sh          $t7, 0x28($t8)
    MEM_H(0X28, ctx->r24) = ctx->r15;
    // 0x800283A4: lwc1        $f18, 0xF0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800283A8: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800283AC: nop

    // 0x800283B0: swc1        $f18, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f18.u32l;
    // 0x800283B4: lhu         $t2, 0x114($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X114);
    // 0x800283B8: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800283BC: nop

    // 0x800283C0: sh          $t2, 0x2C($t6)
    MEM_H(0X2C, ctx->r14) = ctx->r10;
    // 0x800283C4: jal         0x800C1A28
    // 0x800283C8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_106;
    // 0x800283C8: nop

    after_106:
    // 0x800283CC: b           L_800283DC
    // 0x800283D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800283DC;
    // 0x800283D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800283D4: b           L_800283DC
    // 0x800283D8: nop

        goto L_800283DC;
    // 0x800283D8: nop

L_800283DC:
    // 0x800283DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800283E0: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800283E4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800283E8: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800283EC: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800283F0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800283F4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800283F8: jr          $ra
    // 0x800283FC: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x800283FC: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void func_80028400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028400: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80028404: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80028408: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002840C: lwc1        $f7, -0x1A40($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1A40);
    // 0x80028410: lwc1        $f6, -0x1A3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1A3C);
    // 0x80028414: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl);
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80028418: nop

    // 0x8002841C: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80028420: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl);
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80028424: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80028428: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8002842C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80028430: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80028434: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x80028438: bc1f        L_8002844C
    if (!c1cs) {
        // 0x8002843C: nop

            goto L_8002844C;
    }
    // 0x8002843C: nop

    // 0x80028440: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80028444: nop

    // 0x80028448: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
L_8002844C:
    // 0x8002844C: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80028450: b           L_80028460
    // 0x80028454: nop

        goto L_80028460;
    // 0x80028454: nop

    // 0x80028458: b           L_80028460
    // 0x8002845C: nop

        goto L_80028460;
    // 0x8002845C: nop

L_80028460:
    // 0x80028460: jr          $ra
    // 0x80028464: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80028464: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80028468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028468: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002846C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028470: sw          $zero, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = 0;
    // 0x80028474: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80028478: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x8002847C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028480: sw          $t6, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r14;
    // 0x80028484: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80028488: addiu       $t7, $t7, 0x2578
    ctx->r15 = ADD32(ctx->r15, 0X2578);
    // 0x8002848C: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x80028490: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80028494: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x80028498: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8002849C: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_800284A0:
    // 0x800284A0: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800284A4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800284A8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x800284AC: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800284B0: nop

    // 0x800284B4: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x800284B8: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800284BC: nop

    // 0x800284C0: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x800284C4: nop

    // 0x800284C8: sw          $t3, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r11;
    // 0x800284CC: lh          $t4, 0x6($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6);
    // 0x800284D0: lh          $t5, 0x6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6);
    // 0x800284D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800284D8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x800284DC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800284E0: sb          $zero, -0x6550($at)
    MEM_B(-0X6550, ctx->r1) = 0;
    // 0x800284E4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800284E8: lbu         $t6, -0x6550($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6550);
    // 0x800284EC: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800284F0: nop

    // 0x800284F4: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x800284F8: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800284FC: nop

    // 0x80028500: addiu       $t9, $t8, 0x28
    ctx->r25 = ADD32(ctx->r24, 0X28);
    // 0x80028504: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x80028508: lh          $t0, 0x6($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X6);
    // 0x8002850C: nop

    // 0x80028510: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80028514: sll         $t3, $t1, 16
    ctx->r11 = S32(ctx->r9 << 16);
    // 0x80028518: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8002851C: slti        $at, $t2, 0x46
    ctx->r1 = SIGNED(ctx->r10) < 0X46 ? 1 : 0;
    // 0x80028520: bne         $at, $zero, L_800284A0
    if (ctx->r1 != 0) {
        // 0x80028524: sh          $t1, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r9;
            goto L_800284A0;
    }
    // 0x80028524: sh          $t1, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r9;
    // 0x80028528: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8002852C:
    // 0x8002852C: lh          $t4, 0x6($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6);
    // 0x80028530: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028534: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80028538: sb          $zero, 0x1B18($at)
    MEM_B(0X1B18, ctx->r1) = 0;
    // 0x8002853C: lh          $t5, 0x6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6);
    // 0x80028540: nop

    // 0x80028544: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80028548: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8002854C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80028550: slti        $at, $t8, 0x29
    ctx->r1 = SIGNED(ctx->r24) < 0X29 ? 1 : 0;
    // 0x80028554: bne         $at, $zero, L_8002852C
    if (ctx->r1 != 0) {
        // 0x80028558: sh          $t6, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r14;
            goto L_8002852C;
    }
    // 0x80028558: sh          $t6, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r14;
    // 0x8002855C: b           L_80028564
    // 0x80028560: nop

        goto L_80028564;
    // 0x80028560: nop

L_80028564:
    // 0x80028564: jr          $ra
    // 0x80028568: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80028568: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8002856C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002856C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80028570: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80028574: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80028578: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002857C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80028580: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80028584: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80028588: addiu       $t7, $t7, -0x4834
    ctx->r15 = ADD32(ctx->r15, -0X4834);
    // 0x8002858C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80028590: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80028594: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80028598: lbu         $at, 0x8($t7)
    ctx->r1 = MEM_BU(ctx->r15, 0X8);
    // 0x8002859C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800285A0: sb          $at, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r1;
    // 0x800285A4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800285A8: lh          $s0, 0x5A($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X5A);
    // 0x800285AC: nop

    // 0x800285B0: beq         $s0, $zero, L_800285CC
    if (ctx->r16 == 0) {
        // 0x800285B4: nop

            goto L_800285CC;
    }
    // 0x800285B4: nop

    // 0x800285B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800285BC: beq         $s0, $at, L_8002863C
    if (ctx->r16 == ctx->r1) {
        // 0x800285C0: nop

            goto L_8002863C;
    }
    // 0x800285C0: nop

    // 0x800285C4: b           L_80028A00
    // 0x800285C8: nop

        goto L_80028A00;
    // 0x800285C8: nop

L_800285CC:
    // 0x800285CC: jal         0x80028468
    // 0x800285D0: nop

    func_80028468(rdram, ctx);
        goto after_0;
    // 0x800285D0: nop

    after_0:
    // 0x800285D4: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x800285D8: lh          $t0, 0x56($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X56);
    // 0x800285DC: nop

    // 0x800285E0: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x800285E4: lbu         $t1, 0x30($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X30);
    // 0x800285E8: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800285EC: sltu        $s0, $zero, $t1
    ctx->r16 = 0 < ctx->r9 ? 1 : 0;
    // 0x800285F0: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x800285F4: beq         $s0, $zero, L_8002862C
    if (ctx->r16 == 0) {
        // 0x800285F8: sh          $t1, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r9;
            goto L_8002862C;
    }
    // 0x800285F8: sh          $t1, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r9;
L_800285FC:
    // 0x800285FC: lh          $a0, 0x54($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X54);
    // 0x80028600: jal         0x80029C8C
    // 0x80028604: nop

    func_80029C8C(rdram, ctx);
        goto after_1;
    // 0x80028604: nop

    after_1:
    // 0x80028608: lh          $t3, 0x56($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X56);
    // 0x8002860C: nop

    // 0x80028610: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80028614: lbu         $t4, 0x30($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X30);
    // 0x80028618: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8002861C: sltu        $s0, $zero, $t4
    ctx->r16 = 0 < ctx->r12 ? 1 : 0;
    // 0x80028620: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
    // 0x80028624: bne         $s0, $zero, L_800285FC
    if (ctx->r16 != 0) {
        // 0x80028628: sh          $t4, 0x54($sp)
        MEM_H(0X54, ctx->r29) = ctx->r12;
            goto L_800285FC;
    }
    // 0x80028628: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
L_8002862C:
    // 0x8002862C: jal         0x80029ED8
    // 0x80028630: nop

    func_80029ED8(rdram, ctx);
        goto after_2;
    // 0x80028630: nop

    after_2:
    // 0x80028634: b           L_80028A00
    // 0x80028638: nop

        goto L_80028A00;
    // 0x80028638: nop

L_8002863C:
    // 0x8002863C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80028640: sh          $zero, 0x1630($at)
    MEM_H(0X1630, ctx->r1) = 0;
    // 0x80028644: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80028648: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x8002864C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80028650: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028654: sw          $zero, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = 0;
    // 0x80028658: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002865C: sw          $zero, 0x307C($at)
    MEM_W(0X307C, ctx->r1) = 0;
    // 0x80028660: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028664: sh          $zero, 0x1B48($at)
    MEM_H(0X1B48, ctx->r1) = 0;
    // 0x80028668: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002866C: nop

    // 0x80028670: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80028674: nop

    // 0x80028678: beq         $t7, $zero, L_800286E0
    if (ctx->r15 == 0) {
        // 0x8002867C: sw          $t7, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r15;
            goto L_800286E0;
    }
    // 0x8002867C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
L_80028680:
    // 0x80028680: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80028684: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80028688: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x8002868C: lh          $t1, 0x2($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X2);
    // 0x80028690: nop

    // 0x80028694: bne         $t1, $t0, L_800286C8
    if (ctx->r9 != ctx->r8) {
        // 0x80028698: nop

            goto L_800286C8;
    }
    // 0x80028698: nop

    // 0x8002869C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800286A0: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x800286A4: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x800286A8: nop

    // 0x800286AC: bne         $t2, $t4, L_800286C8
    if (ctx->r10 != ctx->r12) {
        // 0x800286B0: nop

            goto L_800286C8;
    }
    // 0x800286B0: nop

    // 0x800286B4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800286B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800286BC: sw          $t3, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = ctx->r11;
    // 0x800286C0: b           L_800286E0
    // 0x800286C4: nop

        goto L_800286E0;
    // 0x800286C4: nop

L_800286C8:
    // 0x800286C8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800286CC: nop

    // 0x800286D0: lw          $t8, 0x18($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X18);
    // 0x800286D4: nop

    // 0x800286D8: bne         $t8, $zero, L_80028680
    if (ctx->r24 != 0) {
        // 0x800286DC: sw          $t8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r24;
            goto L_80028680;
    }
    // 0x800286DC: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
L_800286E0:
    // 0x800286E0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800286E4: lw          $t6, 0x306C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X306C);
    // 0x800286E8: nop

    // 0x800286EC: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800286F0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800286F4: nop

    // 0x800286F8: beq         $t7, $zero, L_80028780
    if (ctx->r15 == 0) {
        // 0x800286FC: nop

            goto L_80028780;
    }
    // 0x800286FC: nop

L_80028700:
    // 0x80028700: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80028704: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80028708: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x8002870C: lh          $t0, 0x2($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2);
    // 0x80028710: nop

    // 0x80028714: bne         $t0, $t9, L_80028734
    if (ctx->r8 != ctx->r25) {
        // 0x80028718: nop

            goto L_80028734;
    }
    // 0x80028718: nop

    // 0x8002871C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80028720: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x80028724: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x80028728: nop

    // 0x8002872C: beq         $t2, $t4, L_8002873C
    if (ctx->r10 == ctx->r12) {
        // 0x80028730: nop

            goto L_8002873C;
    }
    // 0x80028730: nop

L_80028734:
    // 0x80028734: b           L_80028780
    // 0x80028738: nop

        goto L_80028780;
    // 0x80028738: nop

L_8002873C:
    // 0x8002873C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80028740: nop

    // 0x80028744: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x80028748: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002874C: lh          $t5, 0x1B48($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X1B48);
    // 0x80028750: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028754: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80028758: sh          $t8, 0x1B48($at)
    MEM_H(0X1B48, ctx->r1) = ctx->r24;
    // 0x8002875C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80028760: nop

    // 0x80028764: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80028768: nop

    // 0x8002876C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80028770: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80028774: nop

    // 0x80028778: bne         $t0, $zero, L_80028700
    if (ctx->r8 != 0) {
        // 0x8002877C: nop

            goto L_80028700;
    }
    // 0x8002877C: nop

L_80028780:
    // 0x80028780: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80028784: addiu       $t9, $t9, 0x2578
    ctx->r25 = ADD32(ctx->r25, 0X2578);
    // 0x80028788: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8002878C: nop

    // 0x80028790: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80028794: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80028798: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002879C: nop

    // 0x800287A0: beq         $t2, $zero, L_80028844
    if (ctx->r10 == 0) {
        // 0x800287A4: nop

            goto L_80028844;
    }
    // 0x800287A4: nop

L_800287A8:
    // 0x800287A8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800287AC: nop

    // 0x800287B0: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x800287B4: nop

    // 0x800287B8: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x800287BC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800287C0: nop

    // 0x800287C4: lh          $t8, 0x2($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X2);
    // 0x800287C8: nop

    // 0x800287CC: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x800287D0: bne         $at, $zero, L_80028828
    if (ctx->r1 != 0) {
        // 0x800287D4: nop

            goto L_80028828;
    }
    // 0x800287D4: nop

    // 0x800287D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800287DC: bne         $t8, $at, L_800287F4
    if (ctx->r24 != ctx->r1) {
        // 0x800287E0: nop

            goto L_800287F4;
    }
    // 0x800287E0: nop

    // 0x800287E4: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x800287E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800287EC: beq         $t6, $at, L_80028828
    if (ctx->r14 == ctx->r1) {
        // 0x800287F0: nop

            goto L_80028828;
    }
    // 0x800287F0: nop

L_800287F4:
    // 0x800287F4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800287F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800287FC: lh          $t0, 0x2($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X2);
    // 0x80028800: nop

    // 0x80028804: bne         $t0, $at, L_8002881C
    if (ctx->r8 != ctx->r1) {
        // 0x80028808: nop

            goto L_8002881C;
    }
    // 0x80028808: nop

    // 0x8002880C: lh          $t9, 0x4($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X4);
    // 0x80028810: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80028814: beq         $t9, $at, L_80028828
    if (ctx->r25 == ctx->r1) {
        // 0x80028818: nop

            goto L_80028828;
    }
    // 0x80028818: nop

L_8002881C:
    // 0x8002881C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80028820: jal         0x800299C4
    // 0x80028824: nop

    func_800299C4(rdram, ctx);
        goto after_3;
    // 0x80028824: nop

    after_3:
L_80028828:
    // 0x80028828: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8002882C: nop

    // 0x80028830: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80028834: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80028838: nop

    // 0x8002883C: bne         $t2, $zero, L_800287A8
    if (ctx->r10 != 0) {
        // 0x80028840: nop

            goto L_800287A8;
    }
    // 0x80028840: nop

L_80028844:
    // 0x80028844: jal         0x800BC6EC
    // 0x80028848: addiu       $a0, $zero, 0x6E0
    ctx->r4 = ADD32(0, 0X6E0);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_4;
    // 0x80028848: addiu       $a0, $zero, 0x6E0
    ctx->r4 = ADD32(0, 0X6E0);
    after_4:
    // 0x8002884C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80028850: jal         0x800BC6EC
    // 0x80028854: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_5;
    // 0x80028854: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_5:
    // 0x80028858: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8002885C: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
L_80028860:
    // 0x80028860: lh          $t4, 0x56($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X56);
    // 0x80028864: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80028868: addiu       $t8, $t8, 0x24D8
    ctx->r24 = ADD32(ctx->r24, 0X24D8);
    // 0x8002886C: sll         $t3, $t4, 5
    ctx->r11 = S32(ctx->r12 << 5);
    // 0x80028870: addu        $t5, $t3, $t8
    ctx->r13 = ADD32(ctx->r11, ctx->r24);
    // 0x80028874: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80028878: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002887C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80028880: nop

    // 0x80028884: sw          $t6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r14;
    // 0x80028888: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8002888C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80028890: lw          $a0, 0x18($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18);
    // 0x80028894: sw          $t9, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r25;
    // 0x80028898: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8002889C: nop

    // 0x800288A0: lw          $a1, 0x1C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1C);
    // 0x800288A4: jal         0x800B1B04
    // 0x800288A8: nop

    func_800B1B04(rdram, ctx);
        goto after_6;
    // 0x800288A8: nop

    after_6:
    // 0x800288AC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800288B0: jal         0x80099E2C
    // 0x800288B4: nop

    func_80099E2C(rdram, ctx);
        goto after_7;
    // 0x800288B4: nop

    after_7:
    // 0x800288B8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800288BC: addiu       $t2, $zero, 0x148
    ctx->r10 = ADD32(0, 0X148);
    // 0x800288C0: sw          $t2, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r10;
    // 0x800288C4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800288C8: addiu       $t3, $zero, 0x46
    ctx->r11 = ADD32(0, 0X46);
    // 0x800288CC: sw          $t3, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r11;
    // 0x800288D0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800288D4: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800288D8: sh          $t5, 0xC4($t6)
    MEM_H(0XC4, ctx->r14) = ctx->r13;
    // 0x800288DC: lh          $t0, 0x56($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X56);
    // 0x800288E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800288E4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800288E8: sb          $zero, 0x1B0C($at)
    MEM_B(0X1B0C, ctx->r1) = 0;
    // 0x800288EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800288F0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800288F4: nop

    // 0x800288F8: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x800288FC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80028900: nop

    // 0x80028904: lwc1        $f20, 0x8($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80028908: nop

    // 0x8002890C: swc1        $f20, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f20.u32l;
    // 0x80028910: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80028914: nop

    // 0x80028918: swc1        $f20, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f20.u32l;
    // 0x8002891C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80028920: nop

    // 0x80028924: addiu       $t4, $t2, 0x160
    ctx->r12 = ADD32(ctx->r10, 0X160);
    // 0x80028928: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x8002892C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80028930: nop

    // 0x80028934: addiu       $t8, $t3, 0x40
    ctx->r24 = ADD32(ctx->r11, 0X40);
    // 0x80028938: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8002893C: lh          $t5, 0x56($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X56);
    // 0x80028940: nop

    // 0x80028944: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80028948: sll         $t0, $t6, 16
    ctx->r8 = S32(ctx->r14 << 16);
    // 0x8002894C: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80028950: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80028954: bne         $at, $zero, L_80028860
    if (ctx->r1 != 0) {
        // 0x80028958: sh          $t6, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r14;
            goto L_80028860;
    }
    // 0x80028958: sh          $t6, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r14;
    // 0x8002895C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80028960: lw          $t7, 0x306C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X306C);
    // 0x80028964: nop

    // 0x80028968: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8002896C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80028970: lh          $t1, 0x1B48($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1B48);
    // 0x80028974: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x80028978: blez        $t1, L_800289F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002897C: nop

            goto L_800289F8;
    }
    // 0x8002897C: nop

L_80028980:
    // 0x80028980: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80028984: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80028988: swc1        $f6, -0x69E8($at)
    MEM_W(-0X69E8, ctx->r1) = ctx->f6.u32l;
    // 0x8002898C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80028990: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80028994: swc1        $f8, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f8.u32l;
    // 0x80028998: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002899C: nop

    // 0x800289A0: lh          $a0, 0x0($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X0);
    // 0x800289A4: jal         0x8002BB9C
    // 0x800289A8: nop

    func_8002BB9C(rdram, ctx);
        goto after_8;
    // 0x800289A8: nop

    after_8:
    // 0x800289AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800289B0: swc1        $f0, -0x69E0($at)
    MEM_W(-0X69E0, ctx->r1) = ctx->f0.u32l;
    // 0x800289B4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800289B8: jal         0x800296FC
    // 0x800289BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800296FC(rdram, ctx);
        goto after_9;
    // 0x800289BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800289C0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800289C4: nop

    // 0x800289C8: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x800289CC: nop

    // 0x800289D0: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x800289D4: lh          $t8, 0x56($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X56);
    // 0x800289D8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800289DC: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x800289E0: lh          $t9, 0x1B48($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X1B48);
    // 0x800289E4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800289E8: sra         $t0, $t6, 16
    ctx->r8 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800289EC: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800289F0: bne         $at, $zero, L_80028980
    if (ctx->r1 != 0) {
        // 0x800289F4: sh          $t5, 0x56($sp)
        MEM_H(0X56, ctx->r29) = ctx->r13;
            goto L_80028980;
    }
    // 0x800289F4: sh          $t5, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r13;
L_800289F8:
    // 0x800289F8: b           L_80028A00
    // 0x800289FC: nop

        goto L_80028A00;
    // 0x800289FC: nop

L_80028A00:
    // 0x80028A00: b           L_80028A08
    // 0x80028A04: nop

        goto L_80028A08;
    // 0x80028A04: nop

L_80028A08:
    // 0x80028A08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80028A0C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80028A10: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80028A14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80028A18: jr          $ra
    // 0x80028A1C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80028A1C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80028A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028A20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028A28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80028A2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80028A30: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80028A34: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80028A38: nop

    // 0x80028A3C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80028A40: nop

    // 0x80028A44: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80028A48: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80028A4C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80028A50: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80028A54: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80028A58: nop

    // 0x80028A5C: beq         $t9, $at, L_80028B5C
    if (ctx->r25 == ctx->r1) {
        // 0x80028A60: nop

            goto L_80028B5C;
    }
    // 0x80028A60: nop

    // 0x80028A64: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80028A68: nop

    // 0x80028A6C: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80028A70: nop

    // 0x80028A74: beq         $t1, $zero, L_80028B54
    if (ctx->r9 == 0) {
        // 0x80028A78: sb          $t1, 0x2D($sp)
        MEM_B(0X2D, ctx->r29) = ctx->r9;
            goto L_80028B54;
    }
    // 0x80028A78: sb          $t1, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r9;
L_80028A7C:
    // 0x80028A7C: lbu         $t2, 0x2D($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2D);
    // 0x80028A80: nop

    // 0x80028A84: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x80028A88: beq         $t3, $zero, L_80028AA8
    if (ctx->r11 == 0) {
        // 0x80028A8C: nop

            goto L_80028AA8;
    }
    // 0x80028A8C: nop

    // 0x80028A90: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80028A94: nop

    // 0x80028A98: beq         $t4, $zero, L_80028AA8
    if (ctx->r12 == 0) {
        // 0x80028A9C: nop

            goto L_80028AA8;
    }
    // 0x80028A9C: nop

    // 0x80028AA0: b           L_80028B54
    // 0x80028AA4: nop

        goto L_80028B54;
    // 0x80028AA4: nop

L_80028AA8:
    // 0x80028AA8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80028AAC: sh          $t5, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r13;
    // 0x80028AB0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80028AB4: nop

    // 0x80028AB8: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x80028ABC: nop

    // 0x80028AC0: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x80028AC4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80028AC8: sb          $t7, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r15;
    // 0x80028ACC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80028AD0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80028AD4: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x80028AD8: nop

    // 0x80028ADC: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x80028AE0: beq         $t0, $zero, L_80028B04
    if (ctx->r8 == 0) {
        // 0x80028AE4: nop

            goto L_80028B04;
    }
    // 0x80028AE4: nop

    // 0x80028AE8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80028AEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80028AF0: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80028AF4: nop

    // 0x80028AF8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80028AFC: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80028B00: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
L_80028B04:
    // 0x80028B04: lbu         $a2, 0x2D($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2D);
    // 0x80028B08: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80028B0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028B10: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80028B14: lh          $a1, 0x3A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3A);
    // 0x80028B18: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80028B1C: andi        $t1, $a2, 0x7F
    ctx->r9 = ctx->r6 & 0X7F;
    // 0x80028B20: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80028B24: jal         0x800298A4
    // 0x80028B28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800298A4(rdram, ctx);
        goto after_0;
    // 0x80028B28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80028B2C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80028B30: nop

    // 0x80028B34: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x80028B38: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80028B3C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80028B40: nop

    // 0x80028B44: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80028B48: nop

    // 0x80028B4C: bne         $t5, $zero, L_80028A7C
    if (ctx->r13 != 0) {
        // 0x80028B50: sb          $t5, 0x2D($sp)
        MEM_B(0X2D, ctx->r29) = ctx->r13;
            goto L_80028A7C;
    }
    // 0x80028B50: sb          $t5, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r13;
L_80028B54:
    // 0x80028B54: b           L_80028B6C
    // 0x80028B58: nop

        goto L_80028B6C;
    // 0x80028B58: nop

L_80028B5C:
    // 0x80028B5C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80028B60: nop

    // 0x80028B64: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80028B68: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80028B6C:
    // 0x80028B6C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80028B70: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80028B74: nop

    // 0x80028B78: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80028B7C: b           L_80028B84
    // 0x80028B80: nop

        goto L_80028B84;
    // 0x80028B80: nop

L_80028B84:
    // 0x80028B84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028B88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80028B8C: jr          $ra
    // 0x80028B90: nop

    return;
    // 0x80028B90: nop

;}
RECOMP_FUNC void func_80028B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028B94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028B9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80028BA0: jal         0x80028468
    // 0x80028BA4: nop

    func_80028468(rdram, ctx);
        goto after_0;
    // 0x80028BA4: nop

    after_0:
    // 0x80028BA8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80028BAC: nop

    // 0x80028BB0: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x80028BB4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80028BB8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80028BBC: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x80028BC0: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x80028BC4: nop

    // 0x80028BC8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80028BCC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80028BD0: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
    // 0x80028BD4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80028BD8: nop

    // 0x80028BDC: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80028BE0: nop

    // 0x80028BE4: beq         $t2, $zero, L_80028D38
    if (ctx->r10 == 0) {
        // 0x80028BE8: sh          $t2, 0x24($sp)
        MEM_H(0X24, ctx->r29) = ctx->r10;
            goto L_80028D38;
    }
    // 0x80028BE8: sh          $t2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r10;
L_80028BEC:
    // 0x80028BEC: lh          $t3, 0x24($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X24);
    // 0x80028BF0: nop

    // 0x80028BF4: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x80028BF8: beq         $t4, $zero, L_80028C08
    if (ctx->r12 == 0) {
        // 0x80028BFC: nop

            goto L_80028C08;
    }
    // 0x80028BFC: nop

    // 0x80028C00: b           L_80028D38
    // 0x80028C04: nop

        goto L_80028D38;
    // 0x80028C04: nop

L_80028C08:
    // 0x80028C08: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x80028C0C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80028C10: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80028C14: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80028C18: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80028C1C: addiu       $t7, $t7, 0x2578
    ctx->r15 = ADD32(ctx->r15, 0X2578);
    // 0x80028C20: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80028C24: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80028C28: lh          $t9, 0x24($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X24);
    // 0x80028C2C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80028C30: nop

    // 0x80028C34: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x80028C38: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80028C3C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80028C40: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
    // 0x80028C44: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80028C48: addiu       $t3, $zero, -0x2
    ctx->r11 = ADD32(0, -0X2);
    // 0x80028C4C: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x80028C50: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80028C54: nop

    // 0x80028C58: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x80028C5C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80028C60: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80028C64: nop

    // 0x80028C68: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x80028C6C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80028C70: nop

    // 0x80028C74: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80028C78: nop

    // 0x80028C7C: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x80028C80: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80028C84: nop

    // 0x80028C88: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x80028C8C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80028C90: nop

    // 0x80028C94: sw          $zero, 0x18($t9)
    MEM_W(0X18, ctx->r25) = 0;
    // 0x80028C98: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x80028C9C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80028CA0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80028CA4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80028CA8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80028CAC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80028CB0: addiu       $t2, $t1, -0x28
    ctx->r10 = ADD32(ctx->r9, -0X28);
    // 0x80028CB4: addiu       $t3, $t3, 0x2578
    ctx->r11 = ADD32(ctx->r11, 0X2578);
    // 0x80028CB8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80028CBC: sw          $t4, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r12;
    // 0x80028CC0: lh          $t6, 0x24($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X24);
    // 0x80028CC4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80028CC8: addiu       $t7, $t7, 0x1B18
    ctx->r15 = ADD32(ctx->r15, 0X1B18);
    // 0x80028CCC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80028CD0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80028CD4: nop

    // 0x80028CD8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80028CDC: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
    // 0x80028CE0: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x80028CE4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80028CE8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80028CEC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80028CF0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80028CF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80028CF8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80028CFC: sw          $t1, 0x2568($at)
    MEM_W(0X2568, ctx->r1) = ctx->r9;
    // 0x80028D00: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x80028D04: nop

    // 0x80028D08: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80028D0C: sh          $t5, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r13;
    // 0x80028D10: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80028D14: nop

    // 0x80028D18: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80028D1C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80028D20: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80028D24: nop

    // 0x80028D28: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x80028D2C: nop

    // 0x80028D30: bne         $t0, $zero, L_80028BEC
    if (ctx->r8 != 0) {
        // 0x80028D34: sh          $t0, 0x24($sp)
        MEM_H(0X24, ctx->r29) = ctx->r8;
            goto L_80028BEC;
    }
    // 0x80028D34: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
L_80028D38:
    // 0x80028D38: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x80028D3C: addiu       $t2, $t2, -0x6550
    ctx->r10 = ADD32(ctx->r10, -0X6550);
    // 0x80028D40: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80028D44: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x80028D48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80028D4C: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
L_80028D50:
    // 0x80028D50: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80028D54: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80028D58: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80028D5C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80028D60: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80028D64: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80028D68: lh          $t5, 0x2578($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2578);
    // 0x80028D6C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80028D70: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80028D74: sb          $t5, -0x6550($at)
    MEM_B(-0X6550, ctx->r1) = ctx->r13;
    // 0x80028D78: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x80028D7C: nop

    // 0x80028D80: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80028D84: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80028D88: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80028D8C: slti        $at, $t0, 0x46
    ctx->r1 = SIGNED(ctx->r8) < 0X46 ? 1 : 0;
    // 0x80028D90: bne         $at, $zero, L_80028D50
    if (ctx->r1 != 0) {
        // 0x80028D94: sh          $t7, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r15;
            goto L_80028D50;
    }
    // 0x80028D94: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x80028D98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80028D9C: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
L_80028DA0:
    // 0x80028DA0: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x80028DA4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80028DA8: jal         0x80028A20
    // 0x80028DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80028A20(rdram, ctx);
        goto after_1;
    // 0x80028DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80028DB0: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x80028DB4: nop

    // 0x80028DB8: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x80028DBC: sll         $t4, $t1, 16
    ctx->r12 = S32(ctx->r9 << 16);
    // 0x80028DC0: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80028DC4: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80028DC8: bne         $at, $zero, L_80028DA0
    if (ctx->r1 != 0) {
        // 0x80028DCC: sh          $t1, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r9;
            goto L_80028DA0;
    }
    // 0x80028DCC: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80028DD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80028DD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80028DD8: jal         0x80028A20
    // 0x80028DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80028A20(rdram, ctx);
        goto after_2;
    // 0x80028DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80028DE0: b           L_80028DE8
    // 0x80028DE4: nop

        goto L_80028DE8;
    // 0x80028DE4: nop

L_80028DE8:
    // 0x80028DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028DEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80028DF0: jr          $ra
    // 0x80028DF4: nop

    return;
    // 0x80028DF4: nop

;}
RECOMP_FUNC void func_80028DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028DF8: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80028DFC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80028E00: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80028E04: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80028E08: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80028E0C: nop

    // 0x80028E10: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80028E14: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80028E18: sb          $t7, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r15;
    // 0x80028E1C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80028E20: nop

    // 0x80028E24: beq         $t8, $zero, L_80028F28
    if (ctx->r24 == 0) {
        // 0x80028E28: nop

            goto L_80028F28;
    }
    // 0x80028E28: nop

L_80028E2C:
    // 0x80028E2C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80028E30: nop

    // 0x80028E34: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x80028E38: nop

    // 0x80028E3C: bne         $t0, $a3, L_80028E58
    if (ctx->r8 != ctx->r7) {
        // 0x80028E40: nop

            goto L_80028E58;
    }
    // 0x80028E40: nop

    // 0x80028E44: lh          $t1, 0x4($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X4);
    // 0x80028E48: lh          $t2, 0x1A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1A);
    // 0x80028E4C: nop

    // 0x80028E50: beq         $t1, $t2, L_80028E60
    if (ctx->r9 == ctx->r10) {
        // 0x80028E54: nop

            goto L_80028E60;
    }
    // 0x80028E54: nop

L_80028E58:
    // 0x80028E58: b           L_80028F28
    // 0x80028E5C: nop

        goto L_80028F28;
    // 0x80028E5C: nop

L_80028E60:
    // 0x80028E60: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x80028E64: lbu         $t5, 0x5($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X5);
    // 0x80028E68: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80028E6C: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x80028E70: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80028E74: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x80028E78: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80028E7C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80028E80: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80028E84: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028E88: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x80028E8C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028E90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028E94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028E98: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80028E9C: nop

    // 0x80028EA0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028EA4: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80028EA8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028EAC: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80028EB0: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80028EB4: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x80028EB8: bne         $at, $zero, L_80028ECC
    if (ctx->r1 != 0) {
        // 0x80028EBC: sh          $t1, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r9;
            goto L_80028ECC;
    }
    // 0x80028EBC: sh          $t1, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r9;
    // 0x80028EC0: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x80028EC4: b           L_80028EE8
    // 0x80028EC8: sh          $t4, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r12;
        goto L_80028EE8;
    // 0x80028EC8: sh          $t4, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r12;
L_80028ECC:
    // 0x80028ECC: lh          $t5, 0x6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6);
    // 0x80028ED0: nop

    // 0x80028ED4: slti        $at, $t5, -0x7F
    ctx->r1 = SIGNED(ctx->r13) < -0X7F ? 1 : 0;
    // 0x80028ED8: beq         $at, $zero, L_80028EE8
    if (ctx->r1 == 0) {
        // 0x80028EDC: nop

            goto L_80028EE8;
    }
    // 0x80028EDC: nop

    // 0x80028EE0: addiu       $t6, $zero, -0x7F
    ctx->r14 = ADD32(0, -0X7F);
    // 0x80028EE4: sh          $t6, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r14;
L_80028EE8:
    // 0x80028EE8: addu        $t8, $a0, $a1
    ctx->r24 = ADD32(ctx->r4, ctx->r5);
    // 0x80028EEC: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x80028EF0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80028EF4: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x80028EF8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80028EFC: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80028F00: sb          $zero, 0x5($sp)
    MEM_B(0X5, ctx->r29) = 0;
    // 0x80028F04: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80028F08: nop

    // 0x80028F0C: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x80028F10: nop

    // 0x80028F14: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x80028F18: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80028F1C: nop

    // 0x80028F20: bne         $t2, $zero, L_80028E2C
    if (ctx->r10 != 0) {
        // 0x80028F24: nop

            goto L_80028E2C;
    }
    // 0x80028F24: nop

L_80028F28:
    // 0x80028F28: lbu         $t3, 0x5($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X5);
    // 0x80028F2C: nop

    // 0x80028F30: beq         $t3, $zero, L_80028F50
    if (ctx->r11 == 0) {
        // 0x80028F34: nop

            goto L_80028F50;
    }
    // 0x80028F34: nop

    // 0x80028F38: addu        $t5, $a0, $a1
    ctx->r13 = ADD32(ctx->r4, ctx->r5);
    // 0x80028F3C: lbu         $t4, 0x5($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X5);
    // 0x80028F40: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80028F44: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80028F48: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80028F4C: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
L_80028F50:
    // 0x80028F50: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80028F54: nop

    // 0x80028F58: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80028F5C: b           L_80028F6C
    // 0x80028F60: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80028F6C;
    // 0x80028F60: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80028F64: b           L_80028F6C
    // 0x80028F68: nop

        goto L_80028F6C;
    // 0x80028F68: nop

L_80028F6C:
    // 0x80028F6C: jr          $ra
    // 0x80028F70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80028F70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80028F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028F74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028F78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028F7C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80028F80: sh          $zero, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = 0;
    // 0x80028F84: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80028F88: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x80028F8C: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80028F90: nop

    // 0x80028F94: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80028F98: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80028F9C: nop

    // 0x80028FA0: addiu       $t9, $t8, 0xA
    ctx->r25 = ADD32(ctx->r24, 0XA);
    // 0x80028FA4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80028FA8: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
L_80028FAC:
    // 0x80028FAC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80028FB0: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x80028FB4: nop

    // 0x80028FB8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80028FBC: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x80028FC0: lh          $t3, 0x2E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2E);
    // 0x80028FC4: nop

    // 0x80028FC8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80028FCC: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80028FD0: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80028FD4: slti        $at, $t6, 0x5A
    ctx->r1 = SIGNED(ctx->r14) < 0X5A ? 1 : 0;
    // 0x80028FD8: bne         $at, $zero, L_80028FAC
    if (ctx->r1 != 0) {
        // 0x80028FDC: sh          $t4, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r12;
            goto L_80028FAC;
    }
    // 0x80028FDC: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80028FE0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80028FE4: nop

    // 0x80028FE8: beq         $t7, $zero, L_8002906C
    if (ctx->r15 == 0) {
        // 0x80028FEC: nop

            goto L_8002906C;
    }
    // 0x80028FEC: nop

L_80028FF0:
    // 0x80028FF0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80028FF4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80028FF8: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80028FFC: nop

    // 0x80029000: bne         $t9, $at, L_80029018
    if (ctx->r25 != ctx->r1) {
        // 0x80029004: nop

            goto L_80029018;
    }
    // 0x80029004: nop

    // 0x80029008: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x8002900C: nop

    // 0x80029010: beq         $t0, $zero, L_80029020
    if (ctx->r8 == 0) {
        // 0x80029014: nop

            goto L_80029020;
    }
    // 0x80029014: nop

L_80029018:
    // 0x80029018: b           L_8002906C
    // 0x8002901C: nop

        goto L_8002906C;
    // 0x8002901C: nop

L_80029020:
    // 0x80029020: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80029024: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80029028: lhu         $t4, 0x2C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2C);
    // 0x8002902C: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80029030: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80029034: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x80029038: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x8002903C: nop

    // 0x80029040: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80029044: sh          $t7, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r15;
    // 0x80029048: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002904C: nop

    // 0x80029050: lw          $t8, 0x18($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X18);
    // 0x80029054: nop

    // 0x80029058: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8002905C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80029060: nop

    // 0x80029064: bne         $t0, $zero, L_80028FF0
    if (ctx->r8 != 0) {
        // 0x80029068: nop

            goto L_80028FF0;
    }
    // 0x80029068: nop

L_8002906C:
    // 0x8002906C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80029070: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
L_80029074:
    // 0x80029074: lh          $t3, 0x2E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X2E);
    // 0x80029078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002907C: lhu         $a1, 0x2C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2C);
    // 0x80029080: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80029084: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80029088: jal         0x80028DF8
    // 0x8002908C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_80028DF8(rdram, ctx);
        goto after_0;
    // 0x8002908C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x80029090: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x80029094: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80029098: nop

    // 0x8002909C: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x800290A0: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x800290A4: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800290A8: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x800290AC: bne         $at, $zero, L_80029074
    if (ctx->r1 != 0) {
        // 0x800290B0: sh          $t2, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r10;
            goto L_80029074;
    }
    // 0x800290B0: sh          $t2, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r10;
    // 0x800290B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800290B8: lhu         $a1, 0x2C($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2C);
    // 0x800290BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800290C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800290C4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800290C8: jal         0x80028DF8
    // 0x800290CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80028DF8(rdram, ctx);
        goto after_1;
    // 0x800290CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x800290D0: sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // 0x800290D4: b           L_800290DC
    // 0x800290D8: nop

        goto L_800290DC;
    // 0x800290D8: nop

L_800290DC:
    // 0x800290DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800290E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800290E4: jr          $ra
    // 0x800290E8: nop

    return;
    // 0x800290E8: nop

;}
RECOMP_FUNC void func_800290EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800290EC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800290F0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800290F4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800290F8: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x800290FC: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80029100: nop

    // 0x80029104: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80029108: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x8002910C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80029110: nop

    // 0x80029114: beq         $t8, $zero, L_80029198
    if (ctx->r24 == 0) {
        // 0x80029118: nop

            goto L_80029198;
    }
    // 0x80029118: nop

L_8002911C:
    // 0x8002911C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80029120: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029124: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x80029128: nop

    // 0x8002912C: bne         $t0, $at, L_80029144
    if (ctx->r8 != ctx->r1) {
        // 0x80029130: nop

            goto L_80029144;
    }
    // 0x80029130: nop

    // 0x80029134: lh          $t1, 0x4($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X4);
    // 0x80029138: nop

    // 0x8002913C: beq         $t1, $zero, L_8002914C
    if (ctx->r9 == 0) {
        // 0x80029140: nop

            goto L_8002914C;
    }
    // 0x80029140: nop

L_80029144:
    // 0x80029144: b           L_80029198
    // 0x80029148: nop

        goto L_80029198;
    // 0x80029148: nop

L_8002914C:
    // 0x8002914C: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80029150: nop

    // 0x80029154: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80029158: nop

    // 0x8002915C: bne         $t3, $a0, L_80029174
    if (ctx->r11 != ctx->r4) {
        // 0x80029160: nop

            goto L_80029174;
    }
    // 0x80029160: nop

    // 0x80029164: lh          $t4, 0x6($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6);
    // 0x80029168: nop

    // 0x8002916C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80029170: sh          $t5, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r13;
L_80029174:
    // 0x80029174: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80029178: nop

    // 0x8002917C: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80029180: nop

    // 0x80029184: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80029188: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8002918C: nop

    // 0x80029190: bne         $t8, $zero, L_8002911C
    if (ctx->r24 != 0) {
        // 0x80029194: nop

            goto L_8002911C;
    }
    // 0x80029194: nop

L_80029198:
    // 0x80029198: lhu         $v0, 0x6($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X6);
    // 0x8002919C: b           L_800291AC
    // 0x800291A0: nop

        goto L_800291AC;
    // 0x800291A0: nop

    // 0x800291A4: b           L_800291AC
    // 0x800291A8: nop

        goto L_800291AC;
    // 0x800291A8: nop

L_800291AC:
    // 0x800291AC: jr          $ra
    // 0x800291B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800291B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800291B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800291B4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800291B8: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x800291BC: nop

    // 0x800291C0: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800291C4: sw          $a0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r4;
    // 0x800291C8: sw          $a1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r5;
    // 0x800291CC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800291D0: nop

    // 0x800291D4: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x800291D8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800291DC: nop

    // 0x800291E0: beq         $t8, $zero, L_800291F4
    if (ctx->r24 == 0) {
        // 0x800291E4: nop

            goto L_800291F4;
    }
    // 0x800291E4: nop

    // 0x800291E8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800291EC: nop

    // 0x800291F0: sw          $a0, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r4;
L_800291F4:
    // 0x800291F4: b           L_800291FC
    // 0x800291F8: nop

        goto L_800291FC;
    // 0x800291F8: nop

L_800291FC:
    // 0x800291FC: jr          $ra
    // 0x80029200: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80029200: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
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
RECOMP_FUNC void func_800292B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800292B0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800292B4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800292B8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800292BC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800292C0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800292C4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800292C8: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x800292CC: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x800292D0: nop

    // 0x800292D4: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800292D8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800292DC: addiu       $t8, $t8, 0x2578
    ctx->r24 = ADD32(ctx->r24, 0X2578);
    // 0x800292E0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800292E4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800292E8: nop

    // 0x800292EC: beq         $t9, $zero, L_80029378
    if (ctx->r25 == 0) {
        // 0x800292F0: nop

            goto L_80029378;
    }
    // 0x800292F0: nop

L_800292F4:
    // 0x800292F4: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800292F8: nop

    // 0x800292FC: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80029300: nop

    // 0x80029304: sh          $t1, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r9;
    // 0x80029308: lh          $t2, 0xE($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XE);
    // 0x8002930C: nop

    // 0x80029310: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029314: bne         $at, $zero, L_80029340
    if (ctx->r1 != 0) {
        // 0x80029318: nop

            goto L_80029340;
    }
    // 0x80029318: nop

    // 0x8002931C: bne         $t2, $a0, L_80029348
    if (ctx->r10 != ctx->r4) {
        // 0x80029320: nop

            goto L_80029348;
    }
    // 0x80029320: nop

    // 0x80029324: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x80029328: nop

    // 0x8002932C: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80029330: nop

    // 0x80029334: slt         $at, $a1, $t4
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029338: beq         $at, $zero, L_80029348
    if (ctx->r1 == 0) {
        // 0x8002933C: nop

            goto L_80029348;
    }
    // 0x8002933C: nop

L_80029340:
    // 0x80029340: b           L_80029378
    // 0x80029344: nop

        goto L_80029378;
    // 0x80029344: nop

L_80029348:
    // 0x80029348: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8002934C: nop

    // 0x80029350: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80029354: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80029358: nop

    // 0x8002935C: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80029360: nop

    // 0x80029364: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80029368: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8002936C: nop

    // 0x80029370: bne         $t8, $zero, L_800292F4
    if (ctx->r24 != 0) {
        // 0x80029374: nop

            goto L_800292F4;
    }
    // 0x80029374: nop

L_80029378:
    // 0x80029378: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x8002937C: b           L_8002938C
    // 0x80029380: nop

        goto L_8002938C;
    // 0x80029380: nop

    // 0x80029384: b           L_8002938C
    // 0x80029388: nop

        goto L_8002938C;
    // 0x80029388: nop

L_8002938C:
    // 0x8002938C: jr          $ra
    // 0x80029390: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80029390: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80029394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029394: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80029398: lw          $a1, 0x14($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X14);
    // 0x8002939C: nop

    // 0x800293A0: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x800293A4: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x800293A8: nop

    // 0x800293AC: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x800293B0: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x800293B4: nop

    // 0x800293B8: sw          $t7, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r15;
    // 0x800293BC: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800293C0: nop

    // 0x800293C4: beq         $t8, $zero, L_800293DC
    if (ctx->r24 == 0) {
        // 0x800293C8: nop

            goto L_800293DC;
    }
    // 0x800293C8: nop

    // 0x800293CC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800293D0: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x800293D4: nop

    // 0x800293D8: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
L_800293DC:
    // 0x800293DC: b           L_800293E4
    // 0x800293E0: nop

        goto L_800293E4;
    // 0x800293E0: nop

L_800293E4:
    // 0x800293E4: jr          $ra
    // 0x800293E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800293E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800293EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800293EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800293F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800293F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800293F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800293FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80029400: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80029404: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    // 0x80029408: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8002940C: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x80029410: lh          $t7, 0x26($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X26);
    // 0x80029414: nop

    // 0x80029418: bne         $t7, $t8, L_800294B0
    if (ctx->r15 != ctx->r24) {
        // 0x8002941C: nop

            goto L_800294B0;
    }
    // 0x8002941C: nop

    // 0x80029420: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80029424: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x80029428: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x8002942C: nop

    // 0x80029430: bne         $t9, $t0, L_800294B0
    if (ctx->r25 != ctx->r8) {
        // 0x80029434: nop

            goto L_800294B0;
    }
    // 0x80029434: nop

    // 0x80029438: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8002943C: lh          $t1, 0x1B48($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X1B48);
    // 0x80029440: nop

    // 0x80029444: bne         $t1, $zero, L_80029458
    if (ctx->r9 != 0) {
        // 0x80029448: nop

            goto L_80029458;
    }
    // 0x80029448: nop

    // 0x8002944C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80029450: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029454: sw          $t2, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = ctx->r10;
L_80029458:
    // 0x80029458: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002945C: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x80029460: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029464: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80029468: sh          $t4, 0x1B48($at)
    MEM_H(0X1B48, ctx->r1) = ctx->r12;
    // 0x8002946C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80029470: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029474: swc1        $f4, -0x69E8($at)
    MEM_W(-0X69E8, ctx->r1) = ctx->f4.u32l;
    // 0x80029478: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002947C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029480: swc1        $f6, -0x69E4($at)
    MEM_W(-0X69E4, ctx->r1) = ctx->f6.u32l;
    // 0x80029484: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80029488: nop

    // 0x8002948C: lh          $a0, 0x0($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X0);
    // 0x80029490: jal         0x8002BB9C
    // 0x80029494: nop

    func_8002BB9C(rdram, ctx);
        goto after_0;
    // 0x80029494: nop

    after_0:
    // 0x80029498: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8002949C: swc1        $f0, -0x69E0($at)
    MEM_W(-0X69E0, ctx->r1) = ctx->f0.u32l;
    // 0x800294A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800294A4: jal         0x800296FC
    // 0x800294A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800296FC(rdram, ctx);
        goto after_1;
    // 0x800294A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800294AC: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
L_800294B0:
    // 0x800294B0: lh          $v0, 0x1E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1E);
    // 0x800294B4: b           L_800294C4
    // 0x800294B8: nop

        goto L_800294C4;
    // 0x800294B8: nop

    // 0x800294BC: b           L_800294C4
    // 0x800294C0: nop

        goto L_800294C4;
    // 0x800294C0: nop

L_800294C4:
    // 0x800294C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800294C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800294CC: jr          $ra
    // 0x800294D0: nop

    return;
    // 0x800294D0: nop

;}
RECOMP_FUNC void func_800294D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800294D4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800294D8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800294DC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800294E0: beq         $a0, $at, L_80029518
    if (ctx->r4 == ctx->r1) {
        // 0x800294E4: nop

            goto L_80029518;
    }
    // 0x800294E4: nop

    // 0x800294E8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x800294EC: beq         $a0, $at, L_80029518
    if (ctx->r4 == ctx->r1) {
        // 0x800294F0: nop

            goto L_80029518;
    }
    // 0x800294F0: nop

    // 0x800294F4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800294F8: beq         $a0, $at, L_80029518
    if (ctx->r4 == ctx->r1) {
        // 0x800294FC: nop

            goto L_80029518;
    }
    // 0x800294FC: nop

    // 0x80029500: slti        $at, $a0, 0x24
    ctx->r1 = SIGNED(ctx->r4) < 0X24 ? 1 : 0;
    // 0x80029504: bne         $at, $zero, L_80029520
    if (ctx->r1 != 0) {
        // 0x80029508: nop

            goto L_80029520;
    }
    // 0x80029508: nop

    // 0x8002950C: slti        $at, $a0, 0x28
    ctx->r1 = SIGNED(ctx->r4) < 0X28 ? 1 : 0;
    // 0x80029510: beq         $at, $zero, L_80029520
    if (ctx->r1 == 0) {
        // 0x80029514: nop

            goto L_80029520;
    }
    // 0x80029514: nop

L_80029518:
    // 0x80029518: jr          $ra
    // 0x8002951C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    return;
    // 0x8002951C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80029520:
    // 0x80029520: jr          $ra
    // 0x80029524: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x80029524: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
;}
RECOMP_FUNC void func_80029528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029528: jr          $ra
    // 0x8002952C: nop

    return;
    // 0x8002952C: nop

    // 0x80029530: jr          $ra
    // 0x80029534: nop

    return;
    // 0x80029534: nop

;}
RECOMP_FUNC void func_80029538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029538: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002953C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80029540: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80029544: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80029548: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8002954C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80029550: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80029554: sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // 0x80029558: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8002955C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80029560: lbu         $t7, 0x10($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X10);
    // 0x80029564: nop

    // 0x80029568: bne         $t7, $at, L_80029578
    if (ctx->r15 != ctx->r1) {
        // 0x8002956C: nop

            goto L_80029578;
    }
    // 0x8002956C: nop

    // 0x80029570: b           L_800296E8
    // 0x80029574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800296E8;
    // 0x80029574: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029578:
    // 0x80029578: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8002957C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80029580: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x80029584: addiu       $t1, $t1, 0x24D8
    ctx->r9 = ADD32(ctx->r9, 0X24D8);
    // 0x80029588: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8002958C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80029590: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80029594: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x80029598: nop

    // 0x8002959C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800295A0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800295A4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800295A8: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800295AC: nop

    // 0x800295B0: bne         $t5, $at, L_800295E4
    if (ctx->r13 != ctx->r1) {
        // 0x800295B4: nop

            goto L_800295E4;
    }
    // 0x800295B4: nop

    // 0x800295B8: lhu         $t6, 0x4E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4E);
    // 0x800295BC: addiu       $at, $zero, 0x164
    ctx->r1 = ADD32(0, 0X164);
    // 0x800295C0: bne         $t6, $at, L_800295E4
    if (ctx->r14 != ctx->r1) {
        // 0x800295C4: nop

            goto L_800295E4;
    }
    // 0x800295C4: nop

    // 0x800295C8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800295CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800295D0: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x800295D4: nop

    // 0x800295D8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800295DC: b           L_8002961C
    // 0x800295E0: sb          $t9, 0x3084($at)
    MEM_B(0X3084, ctx->r1) = ctx->r25;
        goto L_8002961C;
    // 0x800295E0: sb          $t9, 0x3084($at)
    MEM_B(0X3084, ctx->r1) = ctx->r25;
L_800295E4:
    // 0x800295E4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800295E8: lw          $t0, 0xE64($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XE64);
    // 0x800295EC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800295F0: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800295F4: addiu       $s0, $zero, 0x0
    ctx->r16 = ADD32(0, 0X0);
    // 0x800295F8: addiu       $at, $zero, 0x0
    ctx->r1 = ADD32(0, 0X0);
    // 0x800295FC: andi        $t5, $t3, 0x8
    ctx->r13 = ctx->r11 & 0X8;
    // 0x80029600: xor         $s0, $s0, $t5
    ctx->r16 = ctx->r16 ^ ctx->r13;
    // 0x80029604: xor         $at, $at, $t4
    ctx->r1 = ctx->r1 ^ ctx->r12;
    // 0x80029608: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
    // 0x8002960C: sltiu       $s0, $s0, 0x1
    ctx->r16 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80029610: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029614: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80029618: sb          $s0, 0x3084($at)
    MEM_B(0X3084, ctx->r1) = ctx->r16;
L_8002961C:
    // 0x8002961C: lhu         $t1, 0x52($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X52);
    // 0x80029620: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80029624: beq         $t1, $at, L_800296E0
    if (ctx->r9 == ctx->r1) {
        // 0x80029628: nop

            goto L_800296E0;
    }
    // 0x80029628: nop

    // 0x8002962C: lhu         $t6, 0x52($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X52);
    // 0x80029630: nop

    // 0x80029634: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80029638: beq         $t7, $zero, L_80029648
    if (ctx->r15 == 0) {
        // 0x8002963C: nop

            goto L_80029648;
    }
    // 0x8002963C: nop

    // 0x80029640: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80029644: sh          $t8, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r24;
L_80029648:
    // 0x80029648: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8002964C: nop

    // 0x80029650: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80029654: nop

    // 0x80029658: sh          $t0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r8;
    // 0x8002965C: lhu         $t2, 0x52($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X52);
    // 0x80029660: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80029664: andi        $t3, $t2, 0x7FFF
    ctx->r11 = ctx->r10 & 0X7FFF;
    // 0x80029668: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x8002966C: lhu         $a0, 0x46($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X46);
    // 0x80029670: jal         0x800294D4
    // 0x80029674: nop

    func_800294D4(rdram, ctx);
        goto after_0;
    // 0x80029674: nop

    after_0:
    // 0x80029678: lhu         $t6, 0x46($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X46);
    // 0x8002967C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80029680: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80029684: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80029688: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8002968C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80029690: lbu         $t7, -0x471D($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X471D);
    // 0x80029694: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80029698: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002969C: lw          $a1, 0x1C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1C);
    // 0x800296A0: lbu         $t3, 0x3084($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3084);
    // 0x800296A4: lhu         $t4, 0x44($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X44);
    // 0x800296A8: sra         $t5, $s1, 16
    ctx->r13 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800296AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800296B0: lhu         $t0, 0x4E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X4E);
    // 0x800296B4: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800296B8: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x800296BC: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x800296C0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800296C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800296C8: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800296CC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800296D0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800296D4: or          $a2, $t9, $t0
    ctx->r6 = ctx->r25 | ctx->r8;
    // 0x800296D8: jal         0x800B1F0C
    // 0x800296DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_1;
    // 0x800296DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
L_800296E0:
    // 0x800296E0: b           L_800296E8
    // 0x800296E4: nop

        goto L_800296E8;
    // 0x800296E4: nop

L_800296E8:
    // 0x800296E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800296EC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800296F0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800296F4: jr          $ra
    // 0x800296F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800296F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800296FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800296FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80029700: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80029704: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80029708: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8002970C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80029710: nop

    // 0x80029714: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80029718: nop

    // 0x8002971C: sh          $t7, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r15;
    // 0x80029720: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
L_80029724:
    // 0x80029724: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x80029728: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8002972C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80029730: lbu         $t9, 0x1B0C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1B0C);
    // 0x80029734: nop

    // 0x80029738: bne         $t9, $zero, L_80029748
    if (ctx->r25 != 0) {
        // 0x8002973C: nop

            goto L_80029748;
    }
    // 0x8002973C: nop

    // 0x80029740: b           L_80029768
    // 0x80029744: nop

        goto L_80029768;
    // 0x80029744: nop

L_80029748:
    // 0x80029748: lh          $t0, 0x36($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X36);
    // 0x8002974C: nop

    // 0x80029750: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80029754: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80029758: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8002975C: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x80029760: bne         $at, $zero, L_80029724
    if (ctx->r1 != 0) {
        // 0x80029764: sh          $t1, 0x36($sp)
        MEM_H(0X36, ctx->r29) = ctx->r9;
            goto L_80029724;
    }
    // 0x80029764: sh          $t1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r9;
L_80029768:
    // 0x80029768: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x8002976C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029770: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80029774: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80029778: sb          $t4, 0x1B0C($at)
    MEM_B(0X1B0C, ctx->r1) = ctx->r12;
    // 0x8002977C: lh          $t6, 0x36($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X36);
    // 0x80029780: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80029784: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80029788: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002978C: lw          $t8, 0x24F0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X24F0);
    // 0x80029790: nop

    // 0x80029794: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80029798: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8002979C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800297A0: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800297A4: nop

    // 0x800297A8: swc1        $f4, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f4.u32l;
    // 0x800297AC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800297B0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800297B4: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800297B8: nop

    // 0x800297BC: swc1        $f6, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f6.u32l;
    // 0x800297C0: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x800297C4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800297C8: nop

    // 0x800297CC: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
    // 0x800297D0: lh          $a0, 0x34($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X34);
    // 0x800297D4: jal         0x800294D4
    // 0x800297D8: nop

    func_800294D4(rdram, ctx);
        goto after_0;
    // 0x800297D8: nop

    after_0:
    // 0x800297DC: sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    // 0x800297E0: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x800297E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800297E8: lwc1        $f8, -0x69E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X69E8);
    // 0x800297EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800297F0: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800297F4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800297F8: swc1        $f8, 0x24D8($at)
    MEM_W(0X24D8, ctx->r1) = ctx->f8.u32l;
    // 0x800297FC: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x80029800: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029804: lwc1        $f10, -0x69E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X69E4);
    // 0x80029808: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8002980C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80029810: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80029814: swc1        $f10, 0x24DC($at)
    MEM_W(0X24DC, ctx->r1) = ctx->f10.u32l;
    // 0x80029818: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x8002981C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029820: lwc1        $f16, -0x69E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X69E0);
    // 0x80029824: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029828: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8002982C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80029830: swc1        $f16, 0x24E0($at)
    MEM_W(0X24E0, ctx->r1) = ctx->f16.u32l;
    // 0x80029834: lh          $t3, 0x34($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X34);
    // 0x80029838: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002983C: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80029840: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x80029844: lh          $t1, 0x36($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X36);
    // 0x80029848: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002984C: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x80029850: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80029854: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80029858: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002985C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80029860: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x80029864: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80029868: ori         $t5, $a2, 0x143
    ctx->r13 = ctx->r6 | 0X143;
    // 0x8002986C: lw          $a1, 0x24F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X24F4);
    // 0x80029870: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80029874: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x80029878: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8002987C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80029880: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80029884: jal         0x800B1F0C
    // 0x80029888: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_1;
    // 0x80029888: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8002988C: b           L_80029894
    // 0x80029890: nop

        goto L_80029894;
    // 0x80029890: nop

L_80029894:
    // 0x80029894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80029898: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8002989C: jr          $ra
    // 0x800298A0: nop

    return;
    // 0x800298A0: nop

;}
RECOMP_FUNC void func_800298A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800298A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800298A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800298AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800298B0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800298B4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800298B8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800298BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800298C0: jal         0x80029204
    // 0x800298C4: nop

    func_80029204(rdram, ctx);
        goto after_0;
    // 0x800298C4: nop

    after_0:
    // 0x800298C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800298CC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800298D0: nop

    // 0x800298D4: bne         $t6, $zero, L_800298E4
    if (ctx->r14 != 0) {
        // 0x800298D8: nop

            goto L_800298E4;
    }
    // 0x800298D8: nop

    // 0x800298DC: b           L_800299B4
    // 0x800298E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800299B4;
    // 0x800298E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800298E4:
    // 0x800298E4: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x800298E8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800298EC: nop

    // 0x800298F0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800298F4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800298F8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800298FC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80029900: lh          $t1, 0x32($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X32);
    // 0x80029904: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80029908: nop

    // 0x8002990C: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x80029910: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x80029914: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80029918: nop

    // 0x8002991C: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x80029920: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80029924: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80029928: nop

    // 0x8002992C: swc1        $f4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f4.u32l;
    // 0x80029930: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80029934: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80029938: nop

    // 0x8002993C: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
    // 0x80029940: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80029944: nop

    // 0x80029948: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x8002994C: lh          $t8, 0x3A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3A);
    // 0x80029950: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80029954: addiu       $t9, $t9, 0x1B18
    ctx->r25 = ADD32(ctx->r25, 0X1B18);
    // 0x80029958: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8002995C: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80029960: nop

    // 0x80029964: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80029968: sb          $t2, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r10;
    // 0x8002996C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80029970: lh          $a1, 0x32($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X32);
    // 0x80029974: lh          $a2, 0x36($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X36);
    // 0x80029978: jal         0x800293EC
    // 0x8002997C: nop

    func_800293EC(rdram, ctx);
        goto after_1;
    // 0x8002997C: nop

    after_1:
    // 0x80029980: lh          $a0, 0x32($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X32);
    // 0x80029984: lh          $a1, 0x36($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X36);
    // 0x80029988: jal         0x800292B0
    // 0x8002998C: nop

    func_800292B0(rdram, ctx);
        goto after_2;
    // 0x8002998C: nop

    after_2:
    // 0x80029990: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80029994: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80029998: jal         0x800291B4
    // 0x8002999C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800291B4(rdram, ctx);
        goto after_3;
    // 0x8002999C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800299A0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800299A4: b           L_800299B4
    // 0x800299A8: nop

        goto L_800299B4;
    // 0x800299A8: nop

    // 0x800299AC: b           L_800299B4
    // 0x800299B0: nop

        goto L_800299B4;
    // 0x800299B0: nop

L_800299B4:
    // 0x800299B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800299B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800299BC: jr          $ra
    // 0x800299C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800299C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800299C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800299C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800299C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800299CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800299D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800299D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800299D8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800299DC: nop

    // 0x800299E0: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800299E4: nop

    // 0x800299E8: sh          $t7, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r15;
    // 0x800299EC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800299F0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800299F4: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x800299F8: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800299FC: nop

    // 0x80029A00: bne         $t9, $t0, L_80029AA0
    if (ctx->r25 != ctx->r8) {
        // 0x80029A04: nop

            goto L_80029AA0;
    }
    // 0x80029A04: nop

    // 0x80029A08: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80029A0C: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x80029A10: lh          $t1, 0x4($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X4);
    // 0x80029A14: nop

    // 0x80029A18: bne         $t1, $t2, L_80029AA0
    if (ctx->r9 != ctx->r10) {
        // 0x80029A1C: nop

            goto L_80029AA0;
    }
    // 0x80029A1C: nop

    // 0x80029A20: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80029A24: lh          $t3, 0x1B48($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1B48);
    // 0x80029A28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029A2C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80029A30: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80029A34: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80029A38: bne         $t6, $zero, L_80029A4C
    if (ctx->r14 != 0) {
        // 0x80029A3C: sh          $t4, 0x1B48($at)
        MEM_H(0X1B48, ctx->r1) = ctx->r12;
            goto L_80029A4C;
    }
    // 0x80029A3C: sh          $t4, 0x1B48($at)
    MEM_H(0X1B48, ctx->r1) = ctx->r12;
    // 0x80029A40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029A44: b           L_80029A78
    // 0x80029A48: sw          $zero, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = 0;
        goto L_80029A78;
    // 0x80029A48: sw          $zero, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = 0;
L_80029A4C:
    // 0x80029A4C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80029A50: lw          $t9, 0x306C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X306C);
    // 0x80029A54: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80029A58: nop

    // 0x80029A5C: bne         $t7, $t9, L_80029A78
    if (ctx->r15 != ctx->r25) {
        // 0x80029A60: nop

            goto L_80029A78;
    }
    // 0x80029A60: nop

    // 0x80029A64: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80029A68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029A6C: lw          $t8, 0x18($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X18);
    // 0x80029A70: nop

    // 0x80029A74: sw          $t8, 0x306C($at)
    MEM_W(0X306C, ctx->r1) = ctx->r24;
L_80029A78:
    // 0x80029A78: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80029A7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029A80: lbu         $t2, 0x10($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X10);
    // 0x80029A84: nop

    // 0x80029A88: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80029A8C: sb          $zero, 0x1B0C($at)
    MEM_B(0X1B0C, ctx->r1) = 0;
    // 0x80029A90: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80029A94: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80029A98: b           L_80029AD0
    // 0x80029A9C: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
        goto L_80029AD0;
    // 0x80029A9C: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
L_80029AA0:
    // 0x80029AA0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80029AA4: lw          $t5, 0x3074($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3074);
    // 0x80029AA8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80029AAC: nop

    // 0x80029AB0: bne         $t5, $t6, L_80029AD0
    if (ctx->r13 != ctx->r14) {
        // 0x80029AB4: nop

            goto L_80029AD0;
    }
    // 0x80029AB4: nop

    // 0x80029AB8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80029ABC: lw          $t7, 0x3074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3074);
    // 0x80029AC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029AC4: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x80029AC8: nop

    // 0x80029ACC: sw          $t9, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r25;
L_80029AD0:
    // 0x80029AD0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029AD4: jal         0x80029394
    // 0x80029AD8: nop

    func_80029394(rdram, ctx);
        goto after_0;
    // 0x80029AD8: nop

    after_0:
    // 0x80029ADC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80029AE0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029AE4: lh          $t8, 0x2($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X2);
    // 0x80029AE8: nop

    // 0x80029AEC: bne         $t8, $at, L_80029BD4
    if (ctx->r24 != ctx->r1) {
        // 0x80029AF0: nop

            goto L_80029BD4;
    }
    // 0x80029AF0: nop

    // 0x80029AF4: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80029AF8: nop

    // 0x80029AFC: bne         $t1, $zero, L_80029BD4
    if (ctx->r9 != 0) {
        // 0x80029B00: nop

            goto L_80029BD4;
    }
    // 0x80029B00: nop

    // 0x80029B04: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80029B08: lw          $a0, 0x3074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3074);
    // 0x80029B0C: jal         0x8002A0F8
    // 0x80029B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_1;
    // 0x80029B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80029B14: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80029B18: beq         $at, $zero, L_80029BD4
    if (ctx->r1 == 0) {
        // 0x80029B1C: nop

            goto L_80029BD4;
    }
    // 0x80029B1C: nop

    // 0x80029B20: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80029B24: lw          $t2, 0x3074($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3074);
    // 0x80029B28: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029B2C: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x80029B30: nop

    // 0x80029B34: bne         $t3, $at, L_80029BD4
    if (ctx->r11 != ctx->r1) {
        // 0x80029B38: nop

            goto L_80029BD4;
    }
    // 0x80029B38: nop

    // 0x80029B3C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80029B40: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    // 0x80029B44: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80029B48: nop

    // 0x80029B4C: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x80029B50: nop

    // 0x80029B54: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80029B58: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80029B5C: nop

    // 0x80029B60: beq         $t7, $zero, L_80029B90
    if (ctx->r15 == 0) {
        // 0x80029B64: nop

            goto L_80029B90;
    }
    // 0x80029B64: nop

    // 0x80029B68: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x80029B6C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029B70: bne         $t9, $at, L_80029B90
    if (ctx->r25 != ctx->r1) {
        // 0x80029B74: nop

            goto L_80029B90;
    }
    // 0x80029B74: nop

    // 0x80029B78: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80029B7C: lhu         $t0, 0x2C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2C);
    // 0x80029B80: nop

    // 0x80029B84: bne         $t8, $t0, L_80029B90
    if (ctx->r24 != ctx->r8) {
        // 0x80029B88: nop

            goto L_80029B90;
    }
    // 0x80029B88: nop

    // 0x80029B8C: sh          $zero, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = 0;
L_80029B90:
    // 0x80029B90: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x80029B94: nop

    // 0x80029B98: beq         $t1, $zero, L_80029BD4
    if (ctx->r9 == 0) {
        // 0x80029B9C: nop

            goto L_80029BD4;
    }
    // 0x80029B9C: nop

    // 0x80029BA0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80029BA4: lhu         $t5, 0x2C($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2C);
    // 0x80029BA8: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80029BAC: nop

    // 0x80029BB0: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80029BB4: nop

    // 0x80029BB8: beq         $t4, $t5, L_80029BD4
    if (ctx->r12 == ctx->r13) {
        // 0x80029BBC: nop

            goto L_80029BD4;
    }
    // 0x80029BBC: nop

    // 0x80029BC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80029BC4: jal         0x8002A22C
    // 0x80029BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8002A22C(rdram, ctx);
        goto after_2;
    // 0x80029BC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80029BCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029BD0: sw          $v0, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r2;
L_80029BD4:
    // 0x80029BD4: lhu         $t6, 0x2C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2C);
    // 0x80029BD8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80029BDC: addiu       $t9, $t9, 0x1B18
    ctx->r25 = ADD32(ctx->r25, 0X1B18);
    // 0x80029BE0: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80029BE4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80029BE8: nop

    // 0x80029BEC: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x80029BF0: sb          $t0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r8;
    // 0x80029BF4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80029BF8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80029BFC: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
    // 0x80029C00: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80029C04: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x80029C08: lh          $s1, 0x4($t2)
    ctx->r17 = MEM_H(ctx->r10, 0X4);
    // 0x80029C0C: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80029C10: sh          $s1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r17;
    // 0x80029C14: sll         $s0, $s1, 16
    ctx->r16 = S32(ctx->r17 << 16);
    // 0x80029C18: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80029C1C: sra         $t3, $s0, 16
    ctx->r11 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80029C20: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80029C24: sh          $s0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r16;
    // 0x80029C28: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80029C2C: nop

    // 0x80029C30: subu        $t9, $t5, $t6
    ctx->r25 = SUB32(ctx->r13, ctx->r14);
    // 0x80029C34: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80029C38: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029C3C: mflo        $t8
    ctx->r24 = lo;
    // 0x80029C40: sll         $t0, $t8, 16
    ctx->r8 = S32(ctx->r24 << 16);
    // 0x80029C44: sra         $t7, $t0, 16
    ctx->r15 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80029C48: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80029C4C: sb          $s0, -0x6550($at)
    MEM_B(-0X6550, ctx->r1) = ctx->r16;
    // 0x80029C50: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80029C54: nop

    // 0x80029C58: sw          $zero, 0x18($t1)
    MEM_W(0X18, ctx->r9) = 0;
    // 0x80029C5C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80029C60: nop

    // 0x80029C64: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x80029C68: nop

    // 0x80029C6C: sw          $t3, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r11;
    // 0x80029C70: b           L_80029C78
    // 0x80029C74: nop

        goto L_80029C78;
    // 0x80029C74: nop

L_80029C78:
    // 0x80029C78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029C7C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80029C80: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80029C84: jr          $ra
    // 0x80029C88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80029C88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80029C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029C8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029C90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029C94: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80029C98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80029C9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80029CA0: sh          $t6, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r14;
    // 0x80029CA4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80029CA8: addiu       $t7, $t7, 0x2578
    ctx->r15 = ADD32(ctx->r15, 0X2578);
    // 0x80029CAC: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80029CB0: nop

    // 0x80029CB4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80029CB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80029CBC: nop

    // 0x80029CC0: beq         $t9, $zero, L_80029D94
    if (ctx->r25 == 0) {
        // 0x80029CC4: nop

            goto L_80029D94;
    }
    // 0x80029CC4: nop

L_80029CC8:
    // 0x80029CC8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80029CCC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029CD0: lh          $t1, 0x2($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2);
    // 0x80029CD4: nop

    // 0x80029CD8: bne         $t1, $at, L_80029CF0
    if (ctx->r9 != ctx->r1) {
        // 0x80029CDC: nop

            goto L_80029CF0;
    }
    // 0x80029CDC: nop

    // 0x80029CE0: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x80029CE4: nop

    // 0x80029CE8: beq         $t2, $zero, L_80029CF8
    if (ctx->r10 == 0) {
        // 0x80029CEC: nop

            goto L_80029CF8;
    }
    // 0x80029CEC: nop

L_80029CF0:
    // 0x80029CF0: b           L_80029D94
    // 0x80029CF4: nop

        goto L_80029D94;
    // 0x80029CF4: nop

L_80029CF8:
    // 0x80029CF8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80029CFC: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80029D00: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80029D04: nop

    // 0x80029D08: bne         $t4, $t5, L_80029D70
    if (ctx->r12 != ctx->r13) {
        // 0x80029D0C: nop

            goto L_80029D70;
    }
    // 0x80029D0C: nop

    // 0x80029D10: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80029D14: nop

    // 0x80029D18: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80029D1C: nop

    // 0x80029D20: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80029D24: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80029D28: lw          $t8, 0x3074($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3074);
    // 0x80029D2C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80029D30: nop

    // 0x80029D34: bne         $t8, $t9, L_80029D48
    if (ctx->r24 != ctx->r25) {
        // 0x80029D38: nop

            goto L_80029D48;
    }
    // 0x80029D38: nop

    // 0x80029D3C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80029D40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029D44: sw          $t1, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r9;
L_80029D48:
    // 0x80029D48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80029D4C: jal         0x800299C4
    // 0x80029D50: nop

    func_800299C4(rdram, ctx);
        goto after_0;
    // 0x80029D50: nop

    after_0:
    // 0x80029D54: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80029D58: nop

    // 0x80029D5C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80029D60: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x80029D64: nop

    // 0x80029D68: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80029D6C: sh          $t3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r11;
L_80029D70:
    // 0x80029D70: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80029D74: nop

    // 0x80029D78: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x80029D7C: nop

    // 0x80029D80: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80029D84: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80029D88: nop

    // 0x80029D8C: bne         $t6, $zero, L_80029CC8
    if (ctx->r14 != 0) {
        // 0x80029D90: nop

            goto L_80029CC8;
    }
    // 0x80029D90: nop

L_80029D94:
    // 0x80029D94: lh          $t7, 0x2C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2C);
    // 0x80029D98: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80029D9C: blez        $t7, L_80029E30
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80029DA0: nop

            goto L_80029E30;
    }
    // 0x80029DA0: nop

L_80029DA4:
    // 0x80029DA4: jal         0x80029204
    // 0x80029DA8: nop

    func_80029204(rdram, ctx);
        goto after_1;
    // 0x80029DA8: nop

    after_1:
    // 0x80029DAC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80029DB0: lh          $s0, 0x32($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X32);
    // 0x80029DB4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80029DB8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80029DBC: addiu       $t9, $t9, 0x1B18
    ctx->r25 = ADD32(ctx->r25, 0X1B18);
    // 0x80029DC0: addu        $t1, $s0, $t9
    ctx->r9 = ADD32(ctx->r16, ctx->r25);
    // 0x80029DC4: sh          $s0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r16;
    // 0x80029DC8: lbu         $t0, 0x0($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X0);
    // 0x80029DCC: addu        $t3, $s0, $t9
    ctx->r11 = ADD32(ctx->r16, ctx->r25);
    // 0x80029DD0: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80029DD4: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x80029DD8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80029DDC: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x80029DE0: sh          $t4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r12;
    // 0x80029DE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80029DE8: nop

    // 0x80029DEC: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x80029DF0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80029DF4: nop

    // 0x80029DF8: sh          $zero, 0x6($t7)
    MEM_H(0X6, ctx->r15) = 0;
    // 0x80029DFC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80029E00: lw          $a1, 0x3074($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3074);
    // 0x80029E04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80029E08: jal         0x800291B4
    // 0x80029E0C: nop

    func_800291B4(rdram, ctx);
        goto after_2;
    // 0x80029E0C: nop

    after_2:
    // 0x80029E10: lh          $t8, 0x2E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2E);
    // 0x80029E14: lh          $t2, 0x2C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2C);
    // 0x80029E18: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80029E1C: sll         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9 << 16);
    // 0x80029E20: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80029E24: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80029E28: bne         $at, $zero, L_80029DA4
    if (ctx->r1 != 0) {
        // 0x80029E2C: sh          $t1, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = ctx->r9;
            goto L_80029DA4;
    }
    // 0x80029E2C: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
L_80029E30:
    // 0x80029E30: b           L_80029E38
    // 0x80029E34: nop

        goto L_80029E38;
    // 0x80029E34: nop

L_80029E38:
    // 0x80029E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029E3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029E40: jr          $ra
    // 0x80029E44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80029E44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
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
RECOMP_FUNC void func_80029ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029ED8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80029EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029EE0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80029EE4: addiu       $a0, $a0, 0x2578
    ctx->r4 = ADD32(ctx->r4, 0X2578);
    // 0x80029EE8: jal         0x8002A0F8
    // 0x80029EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002A0F8(rdram, ctx);
        goto after_0;
    // 0x80029EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80029EF0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80029EF4: beq         $at, $zero, L_80029F0C
    if (ctx->r1 == 0) {
        // 0x80029EF8: nop

            goto L_80029F0C;
    }
    // 0x80029EF8: nop

    // 0x80029EFC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80029F00: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x80029F04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80029F08: sw          $t6, 0x3074($at)
    MEM_W(0X3074, ctx->r1) = ctx->r14;
L_80029F0C:
    // 0x80029F0C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80029F10: lw          $t7, 0x3074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3074);
    // 0x80029F14: nop

    // 0x80029F18: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80029F1C: nop

    // 0x80029F20: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80029F24: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
L_80029F28:
    // 0x80029F28: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80029F2C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029F30: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80029F34: sb          $zero, -0x6500($at)
    MEM_B(-0X6500, ctx->r1) = 0;
    // 0x80029F38: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x80029F3C: nop

    // 0x80029F40: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80029F44: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80029F48: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80029F4C: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x80029F50: bne         $at, $zero, L_80029F28
    if (ctx->r1 != 0) {
        // 0x80029F54: sh          $t1, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r9;
            goto L_80029F28;
    }
    // 0x80029F54: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80029F58: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x80029F5C: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x80029F60: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80029F64: nop

    // 0x80029F68: beq         $t4, $zero, L_8002A010
    if (ctx->r12 == 0) {
        // 0x80029F6C: nop

            goto L_8002A010;
    }
    // 0x80029F6C: nop

L_80029F70:
    // 0x80029F70: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80029F74: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80029F78: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x80029F7C: nop

    // 0x80029F80: bne         $t6, $at, L_80029FA8
    if (ctx->r14 != ctx->r1) {
        // 0x80029F84: nop

            goto L_80029FA8;
    }
    // 0x80029F84: nop

    // 0x80029F88: lh          $t7, 0x4($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X4);
    // 0x80029F8C: nop

    // 0x80029F90: bne         $t7, $zero, L_80029FA8
    if (ctx->r15 != 0) {
        // 0x80029F94: nop

            goto L_80029FA8;
    }
    // 0x80029F94: nop

    // 0x80029F98: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x80029F9C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80029FA0: bne         $t8, $at, L_80029FB0
    if (ctx->r24 != ctx->r1) {
        // 0x80029FA4: nop

            goto L_80029FB0;
    }
    // 0x80029FA4: nop

L_80029FA8:
    // 0x80029FA8: b           L_8002A010
    // 0x80029FAC: nop

        goto L_8002A010;
    // 0x80029FAC: nop

L_80029FB0:
    // 0x80029FB0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80029FB4: lh          $t1, 0x24($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X24);
    // 0x80029FB8: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80029FBC: nop

    // 0x80029FC0: beq         $t0, $t1, L_80029FEC
    if (ctx->r8 == ctx->r9) {
        // 0x80029FC4: sh          $t0, 0x22($sp)
        MEM_H(0X22, ctx->r29) = ctx->r8;
            goto L_80029FEC;
    }
    // 0x80029FC4: sh          $t0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r8;
    // 0x80029FC8: lh          $t2, 0x22($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X22);
    // 0x80029FCC: lh          $t3, 0x26($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X26);
    // 0x80029FD0: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x80029FD4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80029FD8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80029FDC: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80029FE0: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x80029FE4: sb          $t2, -0x6500($at)
    MEM_B(-0X6500, ctx->r1) = ctx->r10;
    // 0x80029FE8: sh          $t2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r10;
L_80029FEC:
    // 0x80029FEC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80029FF0: nop

    // 0x80029FF4: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x80029FF8: nop

    // 0x80029FFC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8002A000: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A004: nop

    // 0x8002A008: bne         $t8, $zero, L_80029F70
    if (ctx->r24 != 0) {
        // 0x8002A00C: nop

            goto L_80029F70;
    }
    // 0x8002A00C: nop

L_8002A010:
    // 0x8002A010: b           L_8002A018
    // 0x8002A014: nop

        goto L_8002A018;
    // 0x8002A014: nop

L_8002A018:
    // 0x8002A018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A01C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002A020: jr          $ra
    // 0x8002A024: nop

    return;
    // 0x8002A024: nop

;}
RECOMP_FUNC void func_8002A028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A028: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002A02C: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8002A030:
    // 0x8002A030: lh          $t6, 0x6($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6);
    // 0x8002A034: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002A038: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002A03C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002A040: lh          $t8, 0x2590($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2590);
    // 0x8002A044: nop

    // 0x8002A048: bne         $t8, $zero, L_8002A058
    if (ctx->r24 != 0) {
        // 0x8002A04C: sh          $t8, 0x2($sp)
        MEM_H(0X2, ctx->r29) = ctx->r24;
            goto L_8002A058;
    }
    // 0x8002A04C: sh          $t8, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r24;
    // 0x8002A050: b           L_8002A0DC
    // 0x8002A054: nop

        goto L_8002A0DC;
    // 0x8002A054: nop

L_8002A058:
    // 0x8002A058: sh          $zero, 0x4($sp)
    MEM_H(0X4, ctx->r29) = 0;
L_8002A05C:
    // 0x8002A05C: lh          $t9, 0x4($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4);
    // 0x8002A060: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8002A064: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002A068: lbu         $t0, -0x6500($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6500);
    // 0x8002A06C: lh          $t1, 0x2($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2);
    // 0x8002A070: nop

    // 0x8002A074: bne         $t0, $t1, L_8002A084
    if (ctx->r8 != ctx->r9) {
        // 0x8002A078: nop

            goto L_8002A084;
    }
    // 0x8002A078: nop

    // 0x8002A07C: b           L_8002A0A4
    // 0x8002A080: nop

        goto L_8002A0A4;
    // 0x8002A080: nop

L_8002A084:
    // 0x8002A084: lh          $t2, 0x4($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4);
    // 0x8002A088: nop

    // 0x8002A08C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8002A090: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8002A094: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8002A098: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x8002A09C: bne         $at, $zero, L_8002A05C
    if (ctx->r1 != 0) {
        // 0x8002A0A0: sh          $t3, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r11;
            goto L_8002A05C;
    }
    // 0x8002A0A0: sh          $t3, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r11;
L_8002A0A4:
    // 0x8002A0A4: lh          $t6, 0x4($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4);
    // 0x8002A0A8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002A0AC: bne         $t6, $at, L_8002A0BC
    if (ctx->r14 != ctx->r1) {
        // 0x8002A0B0: nop

            goto L_8002A0BC;
    }
    // 0x8002A0B0: nop

    // 0x8002A0B4: b           L_8002A0DC
    // 0x8002A0B8: nop

        goto L_8002A0DC;
    // 0x8002A0B8: nop

L_8002A0BC:
    // 0x8002A0BC: lh          $t7, 0x6($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X6);
    // 0x8002A0C0: nop

    // 0x8002A0C4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002A0C8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002A0CC: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002A0D0: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x8002A0D4: bne         $at, $zero, L_8002A030
    if (ctx->r1 != 0) {
        // 0x8002A0D8: sh          $t8, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r24;
            goto L_8002A030;
    }
    // 0x8002A0D8: sh          $t8, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r24;
L_8002A0DC:
    // 0x8002A0DC: lh          $v0, 0x6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X6);
    // 0x8002A0E0: b           L_8002A0F0
    // 0x8002A0E4: nop

        goto L_8002A0F0;
    // 0x8002A0E4: nop

    // 0x8002A0E8: b           L_8002A0F0
    // 0x8002A0EC: nop

        goto L_8002A0F0;
    // 0x8002A0EC: nop

L_8002A0F0:
    // 0x8002A0F0: jr          $ra
    // 0x8002A0F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002A0F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8002A0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A0F8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002A0FC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002A100: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002A104: bne         $a0, $zero, L_8002A144
    if (ctx->r4 != 0) {
        // 0x8002A108: nop

            goto L_8002A144;
    }
    // 0x8002A108: nop

    // 0x8002A10C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002A110: bne         $a1, $at, L_8002A128
    if (ctx->r5 != ctx->r1) {
        // 0x8002A114: nop

            goto L_8002A128;
    }
    // 0x8002A114: nop

    // 0x8002A118: b           L_8002A224
    // 0x8002A11C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002A224;
    // 0x8002A11C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A120: b           L_8002A13C
    // 0x8002A124: nop

        goto L_8002A13C;
    // 0x8002A124: nop

L_8002A128:
    // 0x8002A128: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002A12C: addiu       $t6, $t6, 0x2578
    ctx->r14 = ADD32(ctx->r14, 0X2578);
    // 0x8002A130: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x8002A134: nop

    // 0x8002A138: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_8002A13C:
    // 0x8002A13C: b           L_8002A150
    // 0x8002A140: nop

        goto L_8002A150;
    // 0x8002A140: nop

L_8002A144:
    // 0x8002A144: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8002A148: nop

    // 0x8002A14C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
L_8002A150:
    // 0x8002A150: sh          $zero, 0xA($sp)
    MEM_H(0XA, ctx->r29) = 0;
    // 0x8002A154: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8002A158: sh          $t9, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r25;
    // 0x8002A15C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8002A160: nop

    // 0x8002A164: beq         $t0, $zero, L_8002A210
    if (ctx->r8 == 0) {
        // 0x8002A168: nop

            goto L_8002A210;
    }
    // 0x8002A168: nop

L_8002A16C:
    // 0x8002A16C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8002A170: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002A174: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8002A178: nop

    // 0x8002A17C: bne         $t2, $at, L_8002A194
    if (ctx->r10 != ctx->r1) {
        // 0x8002A180: nop

            goto L_8002A194;
    }
    // 0x8002A180: nop

    // 0x8002A184: lh          $t3, 0x4($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X4);
    // 0x8002A188: nop

    // 0x8002A18C: beq         $t3, $zero, L_8002A19C
    if (ctx->r11 == 0) {
        // 0x8002A190: nop

            goto L_8002A19C;
    }
    // 0x8002A190: nop

L_8002A194:
    // 0x8002A194: b           L_8002A210
    // 0x8002A198: nop

        goto L_8002A210;
    // 0x8002A198: nop

L_8002A19C:
    // 0x8002A19C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8002A1A0: lh          $t6, 0xC($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XC);
    // 0x8002A1A4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8002A1A8: nop

    // 0x8002A1AC: beq         $t5, $t6, L_8002A1D0
    if (ctx->r13 == ctx->r14) {
        // 0x8002A1B0: sh          $t5, 0xE($sp)
        MEM_H(0XE, ctx->r29) = ctx->r13;
            goto L_8002A1D0;
    }
    // 0x8002A1B0: sh          $t5, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r13;
    // 0x8002A1B4: lh          $t7, 0xA($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XA);
    // 0x8002A1B8: nop

    // 0x8002A1BC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002A1C0: sh          $t8, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r24;
    // 0x8002A1C4: lh          $t9, 0xE($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XE);
    // 0x8002A1C8: nop

    // 0x8002A1CC: sh          $t9, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r25;
L_8002A1D0:
    // 0x8002A1D0: beq         $a1, $zero, L_8002A1EC
    if (ctx->r5 == 0) {
        // 0x8002A1D4: nop

            goto L_8002A1EC;
    }
    // 0x8002A1D4: nop

    // 0x8002A1D8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8002A1DC: nop

    // 0x8002A1E0: lw          $t2, 0x14($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X14);
    // 0x8002A1E4: b           L_8002A200
    // 0x8002A1E8: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
        goto L_8002A200;
    // 0x8002A1E8: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
L_8002A1EC:
    // 0x8002A1EC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8002A1F0: nop

    // 0x8002A1F4: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x8002A1F8: nop

    // 0x8002A1FC: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_8002A200:
    // 0x8002A200: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8002A204: nop

    // 0x8002A208: bne         $t4, $zero, L_8002A16C
    if (ctx->r12 != 0) {
        // 0x8002A20C: nop

            goto L_8002A16C;
    }
    // 0x8002A20C: nop

L_8002A210:
    // 0x8002A210: lh          $v0, 0xA($sp)
    ctx->r2 = MEM_H(ctx->r29, 0XA);
    // 0x8002A214: b           L_8002A224
    // 0x8002A218: nop

        goto L_8002A224;
    // 0x8002A218: nop

    // 0x8002A21C: b           L_8002A224
    // 0x8002A220: nop

        goto L_8002A224;
    // 0x8002A220: nop

L_8002A224:
    // 0x8002A224: jr          $ra
    // 0x8002A228: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002A228: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8002A22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A22C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002A230: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002A234: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002A238: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002A23C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002A240: bgtz        $a1, L_8002A258
    if (SIGNED(ctx->r5) > 0) {
        // 0x8002A244: nop

            goto L_8002A258;
    }
    // 0x8002A244: nop

    // 0x8002A248: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x8002A24C: lw          $v0, 0x3074($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3074);
    // 0x8002A250: b           L_8002A394
    // 0x8002A254: nop

        goto L_8002A394;
    // 0x8002A254: nop

L_8002A258:
    // 0x8002A258: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002A25C: lw          $t6, 0x3074($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3074);
    // 0x8002A260: nop

    // 0x8002A264: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8002A268: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002A26C: lw          $t7, 0x3074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3074);
    // 0x8002A270: nop

    // 0x8002A274: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8002A278: nop

    // 0x8002A27C: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8002A280: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8002A284: nop

    // 0x8002A288: sh          $t9, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r25;
    // 0x8002A28C: lw          $t0, 0x8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8);
    // 0x8002A290: nop

    // 0x8002A294: beq         $t0, $zero, L_8002A368
    if (ctx->r8 == 0) {
        // 0x8002A298: nop

            goto L_8002A368;
    }
    // 0x8002A298: nop

L_8002A29C:
    // 0x8002A29C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8002A2A0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8002A2A4: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8002A2A8: nop

    // 0x8002A2AC: bne         $t2, $at, L_8002A2C4
    if (ctx->r10 != ctx->r1) {
        // 0x8002A2B0: nop

            goto L_8002A2C4;
    }
    // 0x8002A2B0: nop

    // 0x8002A2B4: lh          $t3, 0x4($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X4);
    // 0x8002A2B8: nop

    // 0x8002A2BC: beq         $t3, $zero, L_8002A2CC
    if (ctx->r11 == 0) {
        // 0x8002A2C0: nop

            goto L_8002A2CC;
    }
    // 0x8002A2C0: nop

L_8002A2C4:
    // 0x8002A2C4: b           L_8002A368
    // 0x8002A2C8: nop

        goto L_8002A368;
    // 0x8002A2C8: nop

L_8002A2CC:
    // 0x8002A2CC: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8002A2D0: lh          $t4, 0xE($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XE);
    // 0x8002A2D4: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8002A2D8: nop

    // 0x8002A2DC: beq         $t4, $t6, L_8002A31C
    if (ctx->r12 == ctx->r14) {
        // 0x8002A2E0: nop

            goto L_8002A31C;
    }
    // 0x8002A2E0: nop

    // 0x8002A2E4: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8002A2E8: nop

    // 0x8002A2EC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002A2F0: nop

    // 0x8002A2F4: sh          $t8, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r24;
    // 0x8002A2F8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002A2FC: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x8002A300: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002A304: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002A308: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8002A30C: bgtz        $a1, L_8002A31C
    if (SIGNED(ctx->r5) > 0) {
        // 0x8002A310: nop

            goto L_8002A31C;
    }
    // 0x8002A310: nop

    // 0x8002A314: b           L_8002A368
    // 0x8002A318: nop

        goto L_8002A368;
    // 0x8002A318: nop

L_8002A31C:
    // 0x8002A31C: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8002A320: nop

    // 0x8002A324: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8002A328: beq         $a0, $zero, L_8002A344
    if (ctx->r4 == 0) {
        // 0x8002A32C: nop

            goto L_8002A344;
    }
    // 0x8002A32C: nop

    // 0x8002A330: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8002A334: nop

    // 0x8002A338: lw          $t3, 0x14($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X14);
    // 0x8002A33C: b           L_8002A358
    // 0x8002A340: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
        goto L_8002A358;
    // 0x8002A340: sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
L_8002A344:
    // 0x8002A344: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8002A348: nop

    // 0x8002A34C: lw          $t4, 0x18($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X18);
    // 0x8002A350: nop

    // 0x8002A354: sw          $t4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r12;
L_8002A358:
    // 0x8002A358: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8002A35C: nop

    // 0x8002A360: bne         $t6, $zero, L_8002A29C
    if (ctx->r14 != 0) {
        // 0x8002A364: nop

            goto L_8002A29C;
    }
    // 0x8002A364: nop

L_8002A368:
    // 0x8002A368: beq         $a0, $zero, L_8002A37C
    if (ctx->r4 == 0) {
        // 0x8002A36C: nop

            goto L_8002A37C;
    }
    // 0x8002A36C: nop

    // 0x8002A370: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8002A374: b           L_8002A384
    // 0x8002A378: nop

        goto L_8002A384;
    // 0x8002A378: nop

L_8002A37C:
    // 0x8002A37C: lw          $a2, 0x4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4);
    // 0x8002A380: nop

L_8002A384:
    // 0x8002A384: b           L_8002A394
    // 0x8002A388: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_8002A394;
    // 0x8002A388: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8002A38C: b           L_8002A394
    // 0x8002A390: nop

        goto L_8002A394;
    // 0x8002A390: nop

L_8002A394:
    // 0x8002A394: jr          $ra
    // 0x8002A398: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002A398: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8002A39C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A39C: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x8002A3A0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8002A3A4: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x8002A3A8: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x8002A3AC: swc1        $f31, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002A3B0: swc1        $f30, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f30.u32l;
    // 0x8002A3B4: swc1        $f29, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002A3B8: swc1        $f28, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f28.u32l;
    // 0x8002A3BC: swc1        $f27, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A3C0: swc1        $f26, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f26.u32l;
    // 0x8002A3C4: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A3C8: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x8002A3CC: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A3D0: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002A3D4: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A3D8: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002A3DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A3E0: nop

    // 0x8002A3E4: swc1        $f4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f4.u32l;
    // 0x8002A3E8: jal         0x800C1680
    // 0x8002A3EC: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x8002A3EC: nop

    after_0:
    // 0x8002A3F0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002A3F4: lw          $t6, 0x306C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X306C);
    // 0x8002A3F8: nop

    // 0x8002A3FC: sw          $t6, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r14;
    // 0x8002A400: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002A404: lh          $t7, 0x1B48($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1B48);
    // 0x8002A408: nop

    // 0x8002A40C: sh          $t7, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r15;
    // 0x8002A410: lh          $t8, 0x84($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X84);
    // 0x8002A414: sh          $zero, 0x18E($sp)
    MEM_H(0X18E, ctx->r29) = 0;
    // 0x8002A418: blez        $t8, L_8002BAB0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8002A41C: nop

            goto L_8002BAB0;
    }
    // 0x8002A41C: nop

L_8002A420:
    // 0x8002A420: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8002A424: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002A428: lbu         $t0, 0x10($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X10);
    // 0x8002A42C: nop

    // 0x8002A430: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x8002A434: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002A438: lw          $t2, 0x24F0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X24F0);
    // 0x8002A43C: sh          $t0, 0x18A($sp)
    MEM_H(0X18A, ctx->r29) = ctx->r8;
    // 0x8002A440: sw          $t2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r10;
    // 0x8002A444: lh          $t3, 0x18A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X18A);
    // 0x8002A448: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002A44C: addiu       $t5, $t5, 0x24D8
    ctx->r13 = ADD32(ctx->r13, 0X24D8);
    // 0x8002A450: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x8002A454: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8002A458: sw          $t6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r14;
    // 0x8002A45C: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x8002A460: nop

    // 0x8002A464: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x8002A468: nop

    // 0x8002A46C: sw          $t8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r24;
    // 0x8002A470: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8002A474: nop

    // 0x8002A478: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8002A47C: nop

    // 0x8002A480: sh          $t0, 0x188($sp)
    MEM_H(0X188, ctx->r29) = ctx->r8;
    // 0x8002A484: lw          $t1, 0x148($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X148);
    // 0x8002A488: nop

    // 0x8002A48C: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8002A490: nop

    // 0x8002A494: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
    // 0x8002A498: lw          $t2, 0x148($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X148);
    // 0x8002A49C: nop

    // 0x8002A4A0: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8002A4A4: nop

    // 0x8002A4A8: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002A4AC: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x8002A4B0: nop

    // 0x8002A4B4: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x8002A4B8: nop

    // 0x8002A4BC: sh          $t4, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r12;
    // 0x8002A4C0: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x8002A4C4: nop

    // 0x8002A4C8: lwc1        $f10, 0x8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8002A4CC: nop

    // 0x8002A4D0: swc1        $f10, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f10.u32l;
    // 0x8002A4D4: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002A4D8: jal         0x8002BBE8
    // 0x8002A4DC: nop

    func_8002BBE8(rdram, ctx);
        goto after_1;
    // 0x8002A4DC: nop

    after_1:
    // 0x8002A4E0: sh          $v0, 0x186($sp)
    MEM_H(0X186, ctx->r29) = ctx->r2;
    // 0x8002A4E4: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x8002A4E8: nop

    // 0x8002A4EC: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x8002A4F0: nop

    // 0x8002A4F4: sh          $t7, 0x184($sp)
    MEM_H(0X184, ctx->r29) = ctx->r15;
    // 0x8002A4F8: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8002A4FC: nop

    // 0x8002A500: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002A504: nop

    // 0x8002A508: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8002A50C: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x8002A510: nop

    // 0x8002A514: lwc1        $f18, 0x4($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8002A518: nop

    // 0x8002A51C: swc1        $f18, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f18.u32l;
    // 0x8002A520: lw          $t0, 0x140($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X140);
    // 0x8002A524: nop

    // 0x8002A528: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8002A52C: nop

    // 0x8002A530: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x8002A534: lw          $t1, 0x140($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X140);
    // 0x8002A538: nop

    // 0x8002A53C: lbu         $t2, 0x14($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X14);
    // 0x8002A540: nop

    // 0x8002A544: sb          $t2, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r10;
    // 0x8002A548: lhu         $t3, 0x180($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X180);
    // 0x8002A54C: nop

    // 0x8002A550: sltiu       $at, $t3, 0x38
    ctx->r1 = ctx->r11 < 0X38 ? 1 : 0;
    // 0x8002A554: beq         $at, $zero, L_8002B978
    if (ctx->r1 == 0) {
        // 0x8002A558: nop

            goto L_8002B978;
    }
    // 0x8002A558: nop

    // 0x8002A55C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002A560: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002A564: addu        $at, $at, $t3
    gpr jr_addend_8002A570 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8002A568: lw          $t3, -0x1A38($at)
    ctx->r11 = ADD32(ctx->r1, -0X1A38);
    // 0x8002A56C: nop

    // 0x8002A570: jr          $t3
    // 0x8002A574: nop

    switch (jr_addend_8002A570 >> 2) {
        case 0: goto L_8002A578; break;
        case 1: goto L_8002B044; break;
        case 2: goto L_8002B978; break;
        case 3: goto L_8002B978; break;
        case 4: goto L_8002B978; break;
        case 5: goto L_8002B06C; break;
        case 6: goto L_8002B084; break;
        case 7: goto L_8002B978; break;
        case 8: goto L_8002B978; break;
        case 9: goto L_8002B978; break;
        case 10: goto L_8002B06C; break;
        case 11: goto L_8002B150; break;
        case 12: goto L_8002B978; break;
        case 13: goto L_8002B978; break;
        case 14: goto L_8002B978; break;
        case 15: goto L_8002B830; break;
        case 16: goto L_8002B978; break;
        case 17: goto L_8002B978; break;
        case 18: goto L_8002B978; break;
        case 19: goto L_8002B978; break;
        case 20: goto L_8002B06C; break;
        case 21: goto L_8002B238; break;
        case 22: goto L_8002B978; break;
        case 23: goto L_8002B978; break;
        case 24: goto L_8002B978; break;
        case 25: goto L_8002B06C; break;
        case 26: goto L_8002B354; break;
        case 27: goto L_8002B978; break;
        case 28: goto L_8002B978; break;
        case 29: goto L_8002B978; break;
        case 30: goto L_8002B06C; break;
        case 31: goto L_8002B4AC; break;
        case 32: goto L_8002B588; break;
        case 33: goto L_8002B978; break;
        case 34: goto L_8002B978; break;
        case 35: goto L_8002B06C; break;
        case 36: goto L_8002B5D8; break;
        case 37: goto L_8002B978; break;
        case 38: goto L_8002B978; break;
        case 39: goto L_8002B978; break;
        case 40: goto L_8002B6F8; break;
        case 41: goto L_8002B978; break;
        case 42: goto L_8002B978; break;
        case 43: goto L_8002B978; break;
        case 44: goto L_8002B978; break;
        case 45: goto L_8002B06C; break;
        case 46: goto L_8002B770; break;
        case 47: goto L_8002B978; break;
        case 48: goto L_8002B978; break;
        case 49: goto L_8002B978; break;
        case 50: goto L_8002B7B0; break;
        case 51: goto L_8002B978; break;
        case 52: goto L_8002B978; break;
        case 53: goto L_8002B978; break;
        case 54: goto L_8002B978; break;
        case 55: goto L_8002B8F4; break;
        default: switch_error(__func__, 0x8002A570, 0x800EE5C8);
    }
    // 0x8002A574: nop

L_8002A578:
    // 0x8002A578: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002A57C: nop

    // 0x8002A580: swc1        $f6, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f6.u32l;
    // 0x8002A584: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8002A588: nop

    // 0x8002A58C: swc1        $f8, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f8.u32l;
    // 0x8002A590: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8002A594: nop

    // 0x8002A598: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x8002A59C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002A5A0: lwc1        $f18, -0x71C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002A5A4: lwc1        $f16, 0x15C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002A5A8: nop

    // 0x8002A5AC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8002A5B0: swc1        $f16, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f16.u32l;
    // 0x8002A5B4: bc1f        L_8002A720
    if (!c1cs) {
        // 0x8002A5B8: nop

            goto L_8002A720;
    }
    // 0x8002A5B8: nop

    // 0x8002A5BC: lh          $t4, 0x184($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X184);
    // 0x8002A5C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002A5C4: bne         $t4, $at, L_8002A618
    if (ctx->r12 != ctx->r1) {
        // 0x8002A5C8: nop

            goto L_8002A618;
    }
    // 0x8002A5C8: nop

    // 0x8002A5CC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8002A5D0: lw          $t5, 0x648($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X648);
    // 0x8002A5D4: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x8002A5D8: lh          $t6, 0xA($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XA);
    // 0x8002A5DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002A5E0: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8002A5E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002A5E8: lwc1        $f9, -0x1958($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1958);
    // 0x8002A5EC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8002A5F0: lwc1        $f8, -0x1954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1954);
    // 0x8002A5F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002A5F8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002A5FC: lwc1        $f17, -0x1950($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1950);
    // 0x8002A600: lwc1        $f16, -0x194C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X194C);
    // 0x8002A604: nop

    // 0x8002A608: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8002A60C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8002A610: b           L_8002A628
    // 0x8002A614: swc1        $f4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f4.u32l;
        goto L_8002A628;
    // 0x8002A614: swc1        $f4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f4.u32l;
L_8002A618:
    // 0x8002A618: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8002A61C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002A620: nop

    // 0x8002A624: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
L_8002A628:
    // 0x8002A628: lh          $t9, 0x184($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X184);
    // 0x8002A62C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002A630: bne         $t9, $at, L_8002A68C
    if (ctx->r25 != ctx->r1) {
        // 0x8002A634: nop

            goto L_8002A68C;
    }
    // 0x8002A634: nop

    // 0x8002A638: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002A63C: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002A640: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002A644: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002A648: c.lt.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d < ctx->f10.d;
    // 0x8002A64C: nop

    // 0x8002A650: bc1f        L_8002A674
    if (!c1cs) {
        // 0x8002A654: nop

            goto L_8002A674;
    }
    // 0x8002A654: nop

    // 0x8002A658: lw          $t0, 0x150($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X150);
    // 0x8002A65C: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002A660: lwc1        $f18, 0xF0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x8002A664: nop

    // 0x8002A668: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8002A66C: b           L_8002A68C
    // 0x8002A670: swc1        $f6, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f6.u32l;
        goto L_8002A68C;
    // 0x8002A670: swc1        $f6, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f6.u32l;
L_8002A674:
    // 0x8002A674: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x8002A678: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002A67C: lwc1        $f8, 0xF0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XF0);
    // 0x8002A680: nop

    // 0x8002A684: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002A688: swc1        $f16, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->f16.u32l;
L_8002A68C:
    // 0x8002A68C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002A690: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002A694: lwc1        $f18, 0x154($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8002A698: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002A69C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002A6A0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8002A6A4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002A6A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002A6AC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002A6B0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002A6B4: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x8002A6B8: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x8002A6BC: bc1f        L_8002A6D4
    if (!c1cs) {
        // 0x8002A6C0: nop

            goto L_8002A6D4;
    }
    // 0x8002A6C0: nop

    // 0x8002A6C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002A6C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A6CC: nop

    // 0x8002A6D0: swc1        $f4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f4.u32l;
L_8002A6D4:
    // 0x8002A6D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002A6D8: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002A6DC: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002A6E0: lwc1        $f16, 0x17C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8002A6E4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002A6E8: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8002A6EC: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002A6F0: swc1        $f18, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f18.u32l;
    // 0x8002A6F4: lwc1        $f4, 0x178($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002A6F8: nop

    // 0x8002A6FC: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8002A700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002A704: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002A708: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002A70C: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002A710: mul.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002A714: add.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f10.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8002A718: swc1        $f20, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f20.u32l;
    // 0x8002A71C: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_8002A720:
    // 0x8002A720: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8002A724: addiu       $t2, $t2, 0x5B0
    ctx->r10 = ADD32(ctx->r10, 0X5B0);
    // 0x8002A728: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    // 0x8002A72C: sh          $zero, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = 0;
L_8002A730:
    // 0x8002A730: lh          $t4, 0x18E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X18E);
    // 0x8002A734: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8002A738: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002A73C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002A740: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8002A744: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8002A748: lh          $t6, 0x18C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X18C);
    // 0x8002A74C: nop

    // 0x8002A750: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8002A754: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002A758: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002A75C: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8002A760: bne         $at, $zero, L_8002A730
    if (ctx->r1 != 0) {
        // 0x8002A764: sh          $t8, 0x18C($sp)
        MEM_H(0X18C, ctx->r29) = ctx->r24;
            goto L_8002A730;
    }
    // 0x8002A764: sh          $t8, 0x18C($sp)
    MEM_H(0X18C, ctx->r29) = ctx->r24;
    // 0x8002A768: lh          $t1, 0x18A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X18A);
    // 0x8002A76C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8002A770: addiu       $t4, $t4, 0x24D8
    ctx->r12 = ADD32(ctx->r12, 0X24D8);
    // 0x8002A774: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8002A778: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x8002A77C: lw          $a1, 0x18($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X18);
    // 0x8002A780: lw          $a2, 0x1C($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X1C);
    // 0x8002A784: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x8002A788: jal         0x800B35D4
    // 0x8002A78C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800B35D4(rdram, ctx);
        goto after_2;
    // 0x8002A78C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8002A790: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8002A794: lwc1        $f8, 0x164($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002A798: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8002A79C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002A7A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002A7A4: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A7A8: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8002A7AC: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
    // 0x8002A7B0: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8002A7B4: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002A7B8: lwc1        $f18, 0x8($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002A7BC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002A7C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002A7C4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8002A7C8: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8002A7CC: swc1        $f16, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f16.u32l;
    // 0x8002A7D0: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A7D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002A7D8: nop

    // 0x8002A7DC: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8002A7E0: nop

    // 0x8002A7E4: bc1f        L_8002A7F4
    if (!c1cs) {
        // 0x8002A7E8: nop

            goto L_8002A7F4;
    }
    // 0x8002A7E8: nop

    // 0x8002A7EC: b           L_8002A800
    // 0x8002A7F0: mov.s       $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = ctx->f10.fl;
        goto L_8002A800;
    // 0x8002A7F0: mov.s       $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = ctx->f10.fl;
L_8002A7F4:
    // 0x8002A7F4: lwc1        $f24, 0x16C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A7F8: nop

    // 0x8002A7FC: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl);
    ctx->f24.fl = -ctx->f24.fl;
L_8002A800:
    // 0x8002A800: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A804: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A808: nop

    // 0x8002A80C: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8002A810: nop

    // 0x8002A814: bc1f        L_8002A824
    if (!c1cs) {
        // 0x8002A818: nop

            goto L_8002A824;
    }
    // 0x8002A818: nop

    // 0x8002A81C: b           L_8002A830
    // 0x8002A820: mov.s       $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = ctx->f4.fl;
        goto L_8002A830;
    // 0x8002A820: mov.s       $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = ctx->f4.fl;
L_8002A824:
    // 0x8002A824: lwc1        $f22, 0x168($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A828: nop

    // 0x8002A82C: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl);
    ctx->f22.fl = -ctx->f22.fl;
L_8002A830:
    // 0x8002A830: sub.s       $f6, $f24, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl);
    ctx->f6.fl = ctx->f24.fl - ctx->f22.fl;
    // 0x8002A834: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002A838: nop

    // 0x8002A83C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8002A840: nop

    // 0x8002A844: bc1f        L_8002A8B4
    if (!c1cs) {
        // 0x8002A848: nop

            goto L_8002A8B4;
    }
    // 0x8002A848: nop

    // 0x8002A84C: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A850: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002A854: nop

    // 0x8002A858: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8002A85C: nop

    // 0x8002A860: bc1f        L_8002A870
    if (!c1cs) {
        // 0x8002A864: nop

            goto L_8002A870;
    }
    // 0x8002A864: nop

    // 0x8002A868: b           L_8002A87C
    // 0x8002A86C: mov.s       $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    ctx->f28.fl = ctx->f18.fl;
        goto L_8002A87C;
    // 0x8002A86C: mov.s       $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    ctx->f28.fl = ctx->f18.fl;
L_8002A870:
    // 0x8002A870: lwc1        $f28, 0x16C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A874: nop

    // 0x8002A878: neg.s       $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl);
    ctx->f28.fl = -ctx->f28.fl;
L_8002A87C:
    // 0x8002A87C: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A880: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A884: nop

    // 0x8002A888: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8002A88C: nop

    // 0x8002A890: bc1f        L_8002A8A0
    if (!c1cs) {
        // 0x8002A894: nop

            goto L_8002A8A0;
    }
    // 0x8002A894: nop

    // 0x8002A898: b           L_8002A8AC
    // 0x8002A89C: mov.s       $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    ctx->f26.fl = ctx->f8.fl;
        goto L_8002A8AC;
    // 0x8002A89C: mov.s       $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    ctx->f26.fl = ctx->f8.fl;
L_8002A8A0:
    // 0x8002A8A0: lwc1        $f26, 0x168($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A8A4: nop

    // 0x8002A8A8: neg.s       $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl);
    ctx->f26.fl = -ctx->f26.fl;
L_8002A8AC:
    // 0x8002A8AC: b           L_8002A928
    // 0x8002A8B0: sub.s       $f20, $f28, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl);
    ctx->f20.fl = ctx->f28.fl - ctx->f26.fl;
        goto L_8002A928;
    // 0x8002A8B0: sub.s       $f20, $f28, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl);
    ctx->f20.fl = ctx->f28.fl - ctx->f26.fl;
L_8002A8B4:
    // 0x8002A8B4: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A8B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002A8BC: nop

    // 0x8002A8C0: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8002A8C4: nop

    // 0x8002A8C8: bc1f        L_8002A8D8
    if (!c1cs) {
        // 0x8002A8CC: nop

            goto L_8002A8D8;
    }
    // 0x8002A8CC: nop

    // 0x8002A8D0: b           L_8002A8E8
    // 0x8002A8D4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
        goto L_8002A8E8;
    // 0x8002A8D4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
L_8002A8D8:
    // 0x8002A8D8: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8002A8DC: nop

    // 0x8002A8E0: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8002A8E4: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
L_8002A8E8:
    // 0x8002A8E8: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A8EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A8F0: nop

    // 0x8002A8F4: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8002A8F8: nop

    // 0x8002A8FC: bc1f        L_8002A90C
    if (!c1cs) {
        // 0x8002A900: nop

            goto L_8002A90C;
    }
    // 0x8002A900: nop

    // 0x8002A904: b           L_8002A918
    // 0x8002A908: mov.s       $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    ctx->f30.fl = ctx->f4.fl;
        goto L_8002A918;
    // 0x8002A908: mov.s       $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    ctx->f30.fl = ctx->f4.fl;
L_8002A90C:
    // 0x8002A90C: lwc1        $f30, 0x168($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002A910: nop

    // 0x8002A914: neg.s       $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl);
    ctx->f30.fl = -ctx->f30.fl;
L_8002A918:
    // 0x8002A918: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8002A91C: nop

    // 0x8002A920: sub.s       $f20, $f16, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl);
    ctx->f20.fl = ctx->f16.fl - ctx->f30.fl;
    // 0x8002A924: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f20.fl = -ctx->f20.fl;
L_8002A928:
    // 0x8002A928: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002A92C: lwc1        $f11, -0x1948($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X1948);
    // 0x8002A930: lwc1        $f10, -0x1944($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1944);
    // 0x8002A934: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x8002A938: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8002A93C: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8002A940: swc1        $f8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f8.u32l;
    // 0x8002A944: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A948: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x8002A94C: lw          $a3, 0x168($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X168);
    // 0x8002A950: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8002A954: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8002A958: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x8002A95C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002A960: jal         0x800782A8
    // 0x8002A964: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800782A8(rdram, ctx);
        goto after_3;
    // 0x8002A964: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8002A968: beq         $v0, $zero, L_8002AC08
    if (ctx->r2 == 0) {
        // 0x8002A96C: nop

            goto L_8002AC08;
    }
    // 0x8002A96C: nop

    // 0x8002A970: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002A974: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002A978: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002A97C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002A980: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8002A984: nop

    // 0x8002A988: bc1f        L_8002AABC
    if (!c1cs) {
        // 0x8002A98C: nop

            goto L_8002AABC;
    }
    // 0x8002A98C: nop

    // 0x8002A990: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002A994: lwc1        $f8, 0x154($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8002A998: nop

    // 0x8002A99C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8002A9A0: swc1        $f4, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f4.u32l;
    // 0x8002A9A4: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002A9A8: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8002A9AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002A9B0: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002A9B4: c.eq.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d == ctx->f10.d;
    // 0x8002A9B8: nop

    // 0x8002A9BC: bc1t        L_8002AA5C
    if (c1cs) {
        // 0x8002A9C0: nop

            goto L_8002AA5C;
    }
    // 0x8002A9C0: nop

    // 0x8002A9C4: lh          $t8, 0x188($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X188);
    // 0x8002A9C8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8002A9CC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002A9D0: lbu         $t9, -0x4861($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X4861);
    // 0x8002A9D4: nop

    // 0x8002A9D8: sh          $t9, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r25;
    // 0x8002A9DC: jal         0x800220F4
    // 0x8002A9E0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800220F4(rdram, ctx);
        goto after_4;
    // 0x8002A9E0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_4:
    // 0x8002A9E4: lh          $a0, 0x182($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X182);
    // 0x8002A9E8: jal         0x800B9000
    // 0x8002A9EC: nop

    func_800B9000(rdram, ctx);
        goto after_5;
    // 0x8002A9EC: nop

    after_5:
    // 0x8002A9F0: lwc1        $f18, 0x164($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002A9F4: nop

    // 0x8002A9F8: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
    // 0x8002A9FC: lh          $t0, 0x186($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X186);
    // 0x8002AA00: nop

    // 0x8002AA04: beq         $t0, $zero, L_8002AA48
    if (ctx->r8 == 0) {
        // 0x8002AA08: nop

            goto L_8002AA48;
    }
    // 0x8002AA08: nop

    // 0x8002AA0C: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AA10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002AA14: nop

    // 0x8002AA18: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8002AA1C: nop

    // 0x8002AA20: bc1f        L_8002AA30
    if (!c1cs) {
        // 0x8002AA24: nop

            goto L_8002AA30;
    }
    // 0x8002AA24: nop

    // 0x8002AA28: b           L_8002AA40
    // 0x8002AA2C: nop

        goto L_8002AA40;
    // 0x8002AA2C: nop

L_8002AA30:
    // 0x8002AA30: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AA34: nop

    // 0x8002AA38: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = -ctx->f16.fl;
    // 0x8002AA3C: swc1        $f6, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f6.u32l;
L_8002AA40:
    // 0x8002AA40: b           L_8002AA54
    // 0x8002AA44: nop

        goto L_8002AA54;
    // 0x8002AA44: nop

L_8002AA48:
    // 0x8002AA48: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002AA4C: nop

    // 0x8002AA50: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
L_8002AA54:
    // 0x8002AA54: b           L_8002AAB4
    // 0x8002AA58: nop

        goto L_8002AAB4;
    // 0x8002AA58: nop

L_8002AA5C:
    // 0x8002AA5C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8002AA60: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AA64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002AA68: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002AA6C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AA70: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AA74: mul.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8002AA78: lwc1        $f6, 0x160($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002AA7C: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002AA80: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002AA84: add.d       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f8.d = ctx->f10.d + ctx->f16.d;
    // 0x8002AA88: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8002AA8C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8002AA90: swc1        $f18, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f18.u32l;
    // 0x8002AA94: bc1f        L_8002AAA8
    if (!c1cs) {
        // 0x8002AA98: nop

            goto L_8002AAA8;
    }
    // 0x8002AA98: nop

    // 0x8002AA9C: lwc1        $f6, 0x164($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002AAA0: b           L_8002AAB4
    // 0x8002AAA4: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
        goto L_8002AAB4;
    // 0x8002AAA4: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
L_8002AAA8:
    // 0x8002AAA8: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002AAAC: nop

    // 0x8002AAB0: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_8002AAB4:
    // 0x8002AAB4: b           L_8002AC08
    // 0x8002AAB8: nop

        goto L_8002AC08;
    // 0x8002AAB8: nop

L_8002AABC:
    // 0x8002AABC: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002AAC0: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8002AAC4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AAC8: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002AACC: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8002AAD0: nop

    // 0x8002AAD4: bc1f        L_8002AC08
    if (!c1cs) {
        // 0x8002AAD8: nop

            goto L_8002AC08;
    }
    // 0x8002AAD8: nop

    // 0x8002AADC: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8002AAE0: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8002AAE4: nop

    // 0x8002AAE8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002AAEC: swc1        $f10, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f10.u32l;
    // 0x8002AAF0: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AAF4: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8002AAF8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AAFC: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002AB00: c.eq.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d == ctx->f18.d;
    // 0x8002AB04: nop

    // 0x8002AB08: bc1t        L_8002ABB0
    if (c1cs) {
        // 0x8002AB0C: nop

            goto L_8002ABB0;
    }
    // 0x8002AB0C: nop

    // 0x8002AB10: lh          $t1, 0x188($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X188);
    // 0x8002AB14: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8002AB18: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002AB1C: lbu         $t2, -0x4861($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X4861);
    // 0x8002AB20: nop

    // 0x8002AB24: sh          $t2, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r10;
    // 0x8002AB28: jal         0x800220F4
    // 0x8002AB2C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800220F4(rdram, ctx);
        goto after_6;
    // 0x8002AB2C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_6:
    // 0x8002AB30: lh          $a0, 0x182($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X182);
    // 0x8002AB34: jal         0x800B9000
    // 0x8002AB38: nop

    func_800B9000(rdram, ctx);
        goto after_7;
    // 0x8002AB38: nop

    after_7:
    // 0x8002AB3C: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002AB40: nop

    // 0x8002AB44: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8002AB48: lh          $t4, 0x186($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X186);
    // 0x8002AB4C: nop

    // 0x8002AB50: beq         $t4, $zero, L_8002AB9C
    if (ctx->r12 == 0) {
        // 0x8002AB54: nop

            goto L_8002AB9C;
    }
    // 0x8002AB54: nop

    // 0x8002AB58: lwc1        $f6, 0x170($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AB5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002AB60: nop

    // 0x8002AB64: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8002AB68: nop

    // 0x8002AB6C: bc1f        L_8002AB80
    if (!c1cs) {
        // 0x8002AB70: nop

            goto L_8002AB80;
    }
    // 0x8002AB70: nop

    // 0x8002AB74: neg.s       $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.fl = -ctx->f6.fl;
    // 0x8002AB78: b           L_8002AB94
    // 0x8002AB7C: swc1        $f16, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f16.u32l;
        goto L_8002AB94;
    // 0x8002AB7C: swc1        $f16, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f16.u32l;
L_8002AB80:
    // 0x8002AB80: lwc1        $f8, 0x170($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AB84: nop

    // 0x8002AB88: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f18.fl = -ctx->f8.fl;
    // 0x8002AB8C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8002AB90: swc1        $f4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f4.u32l;
L_8002AB94:
    // 0x8002AB94: b           L_8002ABA8
    // 0x8002AB98: nop

        goto L_8002ABA8;
    // 0x8002AB98: nop

L_8002AB9C:
    // 0x8002AB9C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002ABA0: nop

    // 0x8002ABA4: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
L_8002ABA8:
    // 0x8002ABA8: b           L_8002AC08
    // 0x8002ABAC: nop

        goto L_8002AC08;
    // 0x8002ABAC: nop

L_8002ABB0:
    // 0x8002ABB0: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x8002ABB4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002ABB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8002ABBC: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8002ABC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002ABC4: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002ABC8: mul.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002ABCC: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002ABD0: lwc1        $f8, 0x164($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002ABD4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002ABD8: sub.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = ctx->f10.d - ctx->f18.d;
    // 0x8002ABDC: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8002ABE0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8002ABE4: swc1        $f6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f6.u32l;
    // 0x8002ABE8: bc1f        L_8002ABFC
    if (!c1cs) {
        // 0x8002ABEC: nop

            goto L_8002ABFC;
    }
    // 0x8002ABEC: nop

    // 0x8002ABF0: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8002ABF4: b           L_8002AC08
    // 0x8002ABF8: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
        goto L_8002AC08;
    // 0x8002ABF8: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
L_8002ABFC:
    // 0x8002ABFC: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8002AC00: nop

    // 0x8002AC04: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_8002AC08:
    // 0x8002AC08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AC0C: lwc1        $f16, -0x71C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AC10: lwc1        $f18, 0x17C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8002AC14: nop

    // 0x8002AC18: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8002AC1C: nop

    // 0x8002AC20: bc1f        L_8002AC3C
    if (!c1cs) {
        // 0x8002AC24: nop

            goto L_8002AC3C;
    }
    // 0x8002AC24: nop

    // 0x8002AC28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AC2C: lwc1        $f6, -0x71C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AC30: nop

    // 0x8002AC34: swc1        $f6, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f6.u32l;
    // 0x8002AC38: swc1        $f6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f6.u32l;
L_8002AC3C:
    // 0x8002AC3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AC40: lwc1        $f4, -0x71C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AC44: lwc1        $f8, 0x17C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8002AC48: nop

    // 0x8002AC4C: c.eq.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl == ctx->f4.fl;
    // 0x8002AC50: nop

    // 0x8002AC54: bc1f        L_8002B024
    if (!c1cs) {
        // 0x8002AC58: nop

            goto L_8002B024;
    }
    // 0x8002AC58: nop

    // 0x8002AC5C: lwc1        $f10, 0x178($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002AC60: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002AC64: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8002AC68: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002AC6C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AC70: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8002AC74: nop

    // 0x8002AC78: bc1f        L_8002ACAC
    if (!c1cs) {
        // 0x8002AC7C: nop

            goto L_8002ACAC;
    }
    // 0x8002AC7C: nop

    // 0x8002AC80: lh          $t3, 0x188($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X188);
    // 0x8002AC84: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8002AC88: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8002AC8C: lbu         $t5, -0x4861($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4861);
    // 0x8002AC90: nop

    // 0x8002AC94: sh          $t5, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r13;
    // 0x8002AC98: jal         0x800220F4
    // 0x8002AC9C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800220F4(rdram, ctx);
        goto after_8;
    // 0x8002AC9C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_8:
    // 0x8002ACA0: lh          $a0, 0x182($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X182);
    // 0x8002ACA4: jal         0x800B9000
    // 0x8002ACA8: nop

    func_800B9000(rdram, ctx);
        goto after_9;
    // 0x8002ACA8: nop

    after_9:
L_8002ACAC:
    // 0x8002ACAC: lh          $t7, 0x184($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X184);
    // 0x8002ACB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002ACB4: bne         $t7, $at, L_8002AE94
    if (ctx->r15 != ctx->r1) {
        // 0x8002ACB8: nop

            goto L_8002AE94;
    }
    // 0x8002ACB8: nop

    // 0x8002ACBC: lwc1        $f6, 0x178($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002ACC0: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8002ACC4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002ACC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002ACCC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002ACD0: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8002ACD4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8002ACD8: swc1        $f18, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f18.u32l;
    // 0x8002ACDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002ACE0: lwc1        $f16, -0x71C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002ACE4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002ACE8: lwc1        $f9, -0x1940($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1940);
    // 0x8002ACEC: lwc1        $f8, -0x193C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X193C);
    // 0x8002ACF0: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002ACF4: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x8002ACF8: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8002ACFC: swc1        $f10, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f10.u32l;
    // 0x8002AD00: swc1        $f10, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f10.u32l;
    // 0x8002AD04: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002AD08: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002AD0C: lwc1        $f7, -0x1938($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1938);
    // 0x8002AD10: lwc1        $f6, -0x1934($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1934);
    // 0x8002AD14: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x8002AD18: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x8002AD1C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x8002AD20: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AD24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AD28: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8002AD2C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8002AD30: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8002AD34: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x8002AD38: bc1f        L_8002AD4C
    if (!c1cs) {
        // 0x8002AD3C: nop

            goto L_8002AD4C;
    }
    // 0x8002AD3C: nop

    // 0x8002AD40: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002AD44: jal         0x8009A2F4
    // 0x8002AD48: nop

    func_8009A2F4(rdram, ctx);
        goto after_10;
    // 0x8002AD48: nop

    after_10:
L_8002AD4C:
    // 0x8002AD4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002AD50: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AD54: lwc1        $f9, -0x1930($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X1930);
    // 0x8002AD58: lwc1        $f8, -0x192C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X192C);
    // 0x8002AD5C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002AD60: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8002AD64: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AD68: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8002AD6C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8002AD70: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
    // 0x8002AD74: bc1f        L_8002ADA0
    if (!c1cs) {
        // 0x8002AD78: nop

            goto L_8002ADA0;
    }
    // 0x8002AD78: nop

    // 0x8002AD7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002AD80: lwc1        $f7, -0x1928($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1928);
    // 0x8002AD84: lwc1        $f6, -0x1924($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1924);
    // 0x8002AD88: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AD8C: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x8002AD90: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8002AD94: swc1        $f4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f4.u32l;
    // 0x8002AD98: b           L_8002ADC4
    // 0x8002AD9C: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
        goto L_8002ADC4;
    // 0x8002AD9C: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
L_8002ADA0:
    // 0x8002ADA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002ADA4: lwc1        $f18, 0x170($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002ADA8: lwc1        $f17, -0x1920($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X1920);
    // 0x8002ADAC: lwc1        $f16, -0x191C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X191C);
    // 0x8002ADB0: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8002ADB4: mul.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8002ADB8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d);
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8002ADBC: swc1        $f8, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f8.u32l;
    // 0x8002ADC0: neg.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f20.fl = -ctx->f8.fl;
L_8002ADC4:
    // 0x8002ADC4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002ADC8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002ADCC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002ADD0: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x8002ADD4: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8002ADD8: nop

    // 0x8002ADDC: bc1f        L_8002AE8C
    if (!c1cs) {
        // 0x8002ADE0: nop

            goto L_8002AE8C;
    }
    // 0x8002ADE0: nop

    // 0x8002ADE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002ADE8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002ADEC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002ADF0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002ADF4: nop

    // 0x8002ADF8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002ADFC: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
    // 0x8002AE00: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002AE04: nop

    // 0x8002AE08: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8002AE0C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002AE10: beq         $t8, $zero, L_8002AE64
    if (ctx->r24 == 0) {
        // 0x8002AE14: nop

            goto L_8002AE64;
    }
    // 0x8002AE14: nop

    // 0x8002AE18: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002AE1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002AE20: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002AE24: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002AE28: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002AE2C: nop

    // 0x8002AE30: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002AE34: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002AE38: nop

    // 0x8002AE3C: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x8002AE40: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002AE44: bne         $t8, $zero, L_8002AE5C
    if (ctx->r24 != 0) {
        // 0x8002AE48: nop

            goto L_8002AE5C;
    }
    // 0x8002AE48: nop

    // 0x8002AE4C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8002AE50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002AE54: b           L_8002AE74
    // 0x8002AE58: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8002AE74;
    // 0x8002AE58: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8002AE5C:
    // 0x8002AE5C: b           L_8002AE74
    // 0x8002AE60: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8002AE74;
    // 0x8002AE60: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8002AE64:
    // 0x8002AE64: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8002AE68: nop

    // 0x8002AE6C: bltz        $t8, L_8002AE5C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8002AE70: nop

            goto L_8002AE5C;
    }
    // 0x8002AE70: nop

L_8002AE74:
    // 0x8002AE74: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002AE78: sb          $t8, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r24;
    // 0x8002AE7C: nop

    // 0x8002AE80: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002AE84: jal         0x8009A2F4
    // 0x8002AE88: nop

    func_8009A2F4(rdram, ctx);
        goto after_11;
    // 0x8002AE88: nop

    after_11:
L_8002AE8C:
    // 0x8002AE8C: b           L_8002B024
    // 0x8002AE90: nop

        goto L_8002B024;
    // 0x8002AE90: nop

L_8002AE94:
    // 0x8002AE94: lwc1        $f4, 0x158($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8002AE98: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AE9C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8002AEA0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002AEA4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8002AEA8: mul.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x8002AEAC: lwc1        $f6, 0x178($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002AEB0: nop

    // 0x8002AEB4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8002AEB8: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x8002AEBC: nop

    // 0x8002AEC0: bc1f        L_8002AF88
    if (!c1cs) {
        // 0x8002AEC4: nop

            goto L_8002AF88;
    }
    // 0x8002AEC4: nop

    // 0x8002AEC8: lh          $t9, 0x186($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X186);
    // 0x8002AECC: nop

    // 0x8002AED0: bne         $t9, $zero, L_8002AEE8
    if (ctx->r25 != 0) {
        // 0x8002AED4: nop

            goto L_8002AEE8;
    }
    // 0x8002AED4: nop

    // 0x8002AED8: lh          $t0, 0x184($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X184);
    // 0x8002AEDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AEE0: bne         $t0, $at, L_8002AF58
    if (ctx->r8 != ctx->r1) {
        // 0x8002AEE4: nop

            goto L_8002AF58;
    }
    // 0x8002AEE4: nop

L_8002AEE8:
    // 0x8002AEE8: lwc1        $f6, 0x178($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002AEEC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8002AEF0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AEF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AEF8: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8002AEFC: mul.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8002AF00: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8002AF04: swc1        $f8, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f8.u32l;
    // 0x8002AF08: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002AF0C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AF10: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002AF14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002AF18: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002AF1C: mul.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8002AF20: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8002AF24: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
    // 0x8002AF28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AF2C: lwc1        $f8, -0x71C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AF30: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002AF34: lwc1        $f7, -0x1918($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X1918);
    // 0x8002AF38: lwc1        $f6, -0x1914($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1914);
    // 0x8002AF3C: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AF40: add.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f4.d = ctx->f16.d + ctx->f6.d;
    // 0x8002AF44: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8002AF48: swc1        $f18, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f18.u32l;
    // 0x8002AF4C: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002AF50: b           L_8002AF80
    // 0x8002AF54: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
        goto L_8002AF80;
    // 0x8002AF54: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
L_8002AF58:
    // 0x8002AF58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002AF5C: nop

    // 0x8002AF60: swc1        $f10, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f10.u32l;
    // 0x8002AF64: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x8002AF68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002AF6C: lwc1        $f8, -0x71C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002AF70: nop

    // 0x8002AF74: swc1        $f8, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f8.u32l;
    // 0x8002AF78: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002AF7C: sb          $zero, 0x87($sp)
    MEM_B(0X87, ctx->r29) = 0;
L_8002AF80:
    // 0x8002AF80: b           L_8002B024
    // 0x8002AF84: nop

        goto L_8002B024;
    // 0x8002AF84: nop

L_8002AF88:
    // 0x8002AF88: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8002AF8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002AF90: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002AF94: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002AF98: nop

    // 0x8002AF9C: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002AFA0: swc1        $f16, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->f16.u32l;
    // 0x8002AFA4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002AFA8: swc1        $f16, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f16.u32l;
    // 0x8002AFAC: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8002AFB0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8002AFB4: beq         $t2, $zero, L_8002B008
    if (ctx->r10 == 0) {
        // 0x8002AFB8: nop

            goto L_8002B008;
    }
    // 0x8002AFB8: nop

    // 0x8002AFBC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002AFC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002AFC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002AFC8: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8002AFCC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002AFD0: nop

    // 0x8002AFD4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002AFD8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002AFDC: nop

    // 0x8002AFE0: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8002AFE4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8002AFE8: bne         $t2, $zero, L_8002B000
    if (ctx->r10 != 0) {
        // 0x8002AFEC: nop

            goto L_8002B000;
    }
    // 0x8002AFEC: nop

    // 0x8002AFF0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8002AFF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002AFF8: b           L_8002B018
    // 0x8002AFFC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8002B018;
    // 0x8002AFFC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8002B000:
    // 0x8002B000: b           L_8002B018
    // 0x8002B004: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8002B018;
    // 0x8002B004: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8002B008:
    // 0x8002B008: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8002B00C: nop

    // 0x8002B010: bltz        $t2, L_8002B000
    if (SIGNED(ctx->r10) < 0) {
        // 0x8002B014: nop

            goto L_8002B000;
    }
    // 0x8002B014: nop

L_8002B018:
    // 0x8002B018: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8002B01C: sb          $t2, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r10;
    // 0x8002B020: nop

L_8002B024:
    // 0x8002B024: lwc1        $f4, 0x170($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8002B028: nop

    // 0x8002B02C: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x8002B030: lwc1        $f18, 0x178($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X178);
    // 0x8002B034: nop

    // 0x8002B038: swc1        $f18, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f18.u32l;
    // 0x8002B03C: b           L_8002B978
    // 0x8002B040: nop

        goto L_8002B978;
    // 0x8002B040: nop

L_8002B044:
    // 0x8002B044: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B048: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B04C: nop

    // 0x8002B050: swc1        $f10, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f10.u32l;
    // 0x8002B054: lwc1        $f8, 0x15C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B058: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x8002B05C: nop

    // 0x8002B060: swc1        $f8, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f8.u32l;
    // 0x8002B064: b           L_8002B978
    // 0x8002B068: nop

        goto L_8002B978;
    // 0x8002B068: nop

L_8002B06C:
    // 0x8002B06C: lhu         $t5, 0x180($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X180);
    // 0x8002B070: nop

    // 0x8002B074: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8002B078: sh          $t7, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r15;
    // 0x8002B07C: b           L_8002B978
    // 0x8002B080: nop

        goto L_8002B978;
    // 0x8002B080: nop

L_8002B084:
    // 0x8002B084: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B088: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B08C: jal         0x800B26E0
    // 0x8002B090: nop

    func_800B26E0(rdram, ctx);
        goto after_12;
    // 0x8002B090: nop

    after_12:
    // 0x8002B094: bgez        $v0, L_8002B120
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B098: nop

            goto L_8002B120;
    }
    // 0x8002B098: nop

    // 0x8002B09C: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B0A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002B0A4: nop

    // 0x8002B0A8: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8002B0AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002B0B0: nop

    // 0x8002B0B4: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x8002B0B8: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B0BC: jal         0x800294D4
    // 0x8002B0C0: nop

    func_800294D4(rdram, ctx);
        goto after_13;
    // 0x8002B0C0: nop

    after_13:
    // 0x8002B0C4: lh          $t8, 0x188($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X188);
    // 0x8002B0C8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B0CC: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8002B0D0: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B0D4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B0D8: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B0DC: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x8002B0E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8002B0E4: lbu         $t1, 0x3084($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X3084);
    // 0x8002B0E8: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B0EC: lwc1        $f18, 0x15C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B0F0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8002B0F4: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B0F8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8002B0FC: ori         $t0, $a2, 0x143
    ctx->r8 = ctx->r6 | 0X143;
    // 0x8002B100: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B104: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B108: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8002B10C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B110: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8002B114: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002B118: jal         0x800B1F0C
    // 0x8002B11C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_14;
    // 0x8002B11C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_14:
L_8002B120:
    // 0x8002B120: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x8002B124: nop

    // 0x8002B128: lwc1        $f10, 0xCC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x8002B12C: nop

    // 0x8002B130: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
    // 0x8002B134: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B138: nop

    // 0x8002B13C: lwc1        $f8, 0xD0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8002B140: nop

    // 0x8002B144: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B148: b           L_8002B978
    // 0x8002B14C: nop

        goto L_8002B978;
    // 0x8002B14C: nop

L_8002B150:
    // 0x8002B150: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B154: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B158: jal         0x800B26E0
    // 0x8002B15C: nop

    func_800B26E0(rdram, ctx);
        goto after_15;
    // 0x8002B15C: nop

    after_15:
    // 0x8002B160: bgez        $v0, L_8002B208
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B164: nop

            goto L_8002B208;
    }
    // 0x8002B164: nop

    // 0x8002B168: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B16C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002B170: lbu         $t3, 0x3084($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3084);
    // 0x8002B174: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8002B178: sll         $t5, $t3, 5
    ctx->r13 = S32(ctx->r11 << 5);
    // 0x8002B17C: subu        $t6, $t7, $t5
    ctx->r14 = SUB32(ctx->r15, ctx->r13);
    // 0x8002B180: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8002B184: nop

    // 0x8002B188: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002B18C: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x8002B190: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002B194: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002B198: nop

    // 0x8002B19C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8002B1A0: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B1A4: jal         0x800294D4
    // 0x8002B1A8: nop

    func_800294D4(rdram, ctx);
        goto after_16;
    // 0x8002B1A8: nop

    after_16:
    // 0x8002B1AC: lh          $t9, 0x188($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X188);
    // 0x8002B1B0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B1B4: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8002B1B8: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B1BC: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B1C0: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B1C4: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8002B1C8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002B1CC: lbu         $t2, 0x3084($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X3084);
    // 0x8002B1D0: lwc1        $f18, 0x160($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B1D4: lwc1        $f10, 0x15C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B1D8: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8002B1DC: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B1E0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8002B1E4: ori         $t1, $a2, 0x143
    ctx->r9 = ctx->r6 | 0X143;
    // 0x8002B1E8: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B1EC: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B1F0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8002B1F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B1F8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8002B1FC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8002B200: jal         0x800B1F0C
    // 0x8002B204: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_17;
    // 0x8002B204: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_17:
L_8002B208:
    // 0x8002B208: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B20C: nop

    // 0x8002B210: lwc1        $f8, 0xCC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8002B214: nop

    // 0x8002B218: swc1        $f8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f8.u32l;
    // 0x8002B21C: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x8002B220: nop

    // 0x8002B224: lwc1        $f16, 0xD0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8002B228: nop

    // 0x8002B22C: swc1        $f16, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f16.u32l;
    // 0x8002B230: b           L_8002B978
    // 0x8002B234: nop

        goto L_8002B978;
    // 0x8002B234: nop

L_8002B238:
    // 0x8002B238: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B23C: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B240: jal         0x800B26E0
    // 0x8002B244: nop

    func_800B26E0(rdram, ctx);
        goto after_18;
    // 0x8002B244: nop

    after_18:
    // 0x8002B248: bgez        $v0, L_8002B324
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B24C: nop

            goto L_8002B324;
    }
    // 0x8002B24C: nop

    // 0x8002B250: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B254: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002B258: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8002B25C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002B260: lh          $t5, 0xA($t7)
    ctx->r13 = MEM_H(ctx->r15, 0XA);
    // 0x8002B264: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B268: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8002B26C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8002B270: jal         0x80028400
    // 0x8002B274: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_80028400(rdram, ctx);
        goto after_19;
    // 0x8002B274: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_19:
    // 0x8002B278: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002B27C: lbu         $t6, 0x3084($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3084);
    // 0x8002B280: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8002B284: beq         $t6, $zero, L_8002B294
    if (ctx->r14 == 0) {
        // 0x8002B288: nop

            goto L_8002B294;
    }
    // 0x8002B288: nop

    // 0x8002B28C: b           L_8002B298
    // 0x8002B290: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8002B298;
    // 0x8002B290: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002B294:
    // 0x8002B294: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8002B298:
    // 0x8002B298: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8002B29C: nop

    // 0x8002B2A0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002B2A4: mul.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8002B2A8: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    // 0x8002B2AC: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8002B2B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002B2B4: nop

    // 0x8002B2B8: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B2BC: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B2C0: jal         0x800294D4
    // 0x8002B2C4: nop

    func_800294D4(rdram, ctx);
        goto after_20;
    // 0x8002B2C4: nop

    after_20:
    // 0x8002B2C8: lh          $t9, 0x188($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X188);
    // 0x8002B2CC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B2D0: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8002B2D4: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B2D8: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B2DC: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B2E0: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8002B2E4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8002B2E8: lbu         $t2, 0x3084($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X3084);
    // 0x8002B2EC: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B2F0: lwc1        $f6, 0x15C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B2F4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8002B2F8: sra         $t8, $s0, 16
    ctx->r24 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B2FC: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8002B300: ori         $t1, $a2, 0x143
    ctx->r9 = ctx->r6 | 0X143;
    // 0x8002B304: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B308: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B30C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x8002B310: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B314: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8002B318: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002B31C: jal         0x800B1F0C
    // 0x8002B320: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_21;
    // 0x8002B320: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_21:
L_8002B324:
    // 0x8002B324: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B328: nop

    // 0x8002B32C: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8002B330: nop

    // 0x8002B334: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8002B338: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x8002B33C: nop

    // 0x8002B340: lwc1        $f18, 0xD0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8002B344: nop

    // 0x8002B348: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002B34C: b           L_8002B978
    // 0x8002B350: nop

        goto L_8002B978;
    // 0x8002B350: nop

L_8002B354:
    // 0x8002B354: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B358: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B35C: jal         0x800B26E0
    // 0x8002B360: nop

    func_800B26E0(rdram, ctx);
        goto after_22;
    // 0x8002B360: nop

    after_22:
    // 0x8002B364: bgez        $v0, L_8002B47C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B368: nop

            goto L_8002B47C;
    }
    // 0x8002B368: nop

    // 0x8002B36C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002B370: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002B374: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x8002B378: swc1        $f10, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f10.u32l;
    // 0x8002B37C: swc1        $f10, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f10.u32l;
    // 0x8002B380: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8002B384: lbu         $t5, 0x3084($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X3084);
    // 0x8002B388: nop

    // 0x8002B38C: beq         $t5, $zero, L_8002B3AC
    if (ctx->r13 == 0) {
        // 0x8002B390: nop

            goto L_8002B3AC;
    }
    // 0x8002B390: nop

    // 0x8002B394: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002B398: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8002B39C: nop

    // 0x8002B3A0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002B3A4: b           L_8002B3C0
    // 0x8002B3A8: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
        goto L_8002B3C0;
    // 0x8002B3A8: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
L_8002B3AC:
    // 0x8002B3AC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002B3B0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8002B3B4: nop

    // 0x8002B3B8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002B3BC: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
L_8002B3C0:
    // 0x8002B3C0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8002B3C4: lw          $t9, 0x648($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X648);
    // 0x8002B3C8: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8002B3CC: lh          $t0, 0xA($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XA);
    // 0x8002B3D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B3D4: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8002B3D8: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x8002B3DC: jal         0x80028400
    // 0x8002B3E0: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_80028400(rdram, ctx);
        goto after_23;
    // 0x8002B3E0: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_23:
    // 0x8002B3E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002B3E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002B3EC: nop

    // 0x8002B3F0: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8002B3F4: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B3F8: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B3FC: jal         0x800294D4
    // 0x8002B400: nop

    func_800294D4(rdram, ctx);
        goto after_24;
    // 0x8002B400: nop

    after_24:
    // 0x8002B404: lh          $t2, 0x188($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X188);
    // 0x8002B408: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B40C: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8002B410: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B414: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B418: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B41C: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x8002B420: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002B424: lbu         $t7, 0x3084($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3084);
    // 0x8002B428: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B42C: lwc1        $f6, 0x15C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B430: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8002B434: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B438: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8002B43C: ori         $t3, $a2, 0x143
    ctx->r11 = ctx->r6 | 0X143;
    // 0x8002B440: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B444: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B448: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8002B44C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B450: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8002B454: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002B458: jal         0x800B1F0C
    // 0x8002B45C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_25;
    // 0x8002B45C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_25:
    // 0x8002B460: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B464: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002B468: sb          $t5, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r13;
    // 0x8002B46C: jal         0x800B9000
    // 0x8002B470: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800B9000(rdram, ctx);
        goto after_26;
    // 0x8002B470: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_26:
    // 0x8002B474: b           L_8002B978
    // 0x8002B478: nop

        goto L_8002B978;
    // 0x8002B478: nop

L_8002B47C:
    // 0x8002B47C: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x8002B480: nop

    // 0x8002B484: lwc1        $f4, 0xCC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XCC);
    // 0x8002B488: nop

    // 0x8002B48C: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8002B490: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x8002B494: nop

    // 0x8002B498: lwc1        $f18, 0xD0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8002B49C: nop

    // 0x8002B4A0: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002B4A4: b           L_8002B978
    // 0x8002B4A8: nop

        goto L_8002B978;
    // 0x8002B4A8: nop

L_8002B4AC:
    // 0x8002B4AC: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B4B0: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B4B4: jal         0x800B26E0
    // 0x8002B4B8: nop

    func_800B26E0(rdram, ctx);
        goto after_27;
    // 0x8002B4B8: nop

    after_27:
    // 0x8002B4BC: bgez        $v0, L_8002B558
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B4C0: nop

            goto L_8002B558;
    }
    // 0x8002B4C0: nop

    // 0x8002B4C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8002B4C8: lwc1        $f10, -0x71C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8002B4CC: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x8002B4D0: swc1        $f10, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f10.u32l;
    // 0x8002B4D4: swc1        $f10, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f10.u32l;
    // 0x8002B4D8: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B4DC: jal         0x800294D4
    // 0x8002B4E0: nop

    func_800294D4(rdram, ctx);
        goto after_28;
    // 0x8002B4E0: nop

    after_28:
    // 0x8002B4E4: lh          $t1, 0x188($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X188);
    // 0x8002B4E8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B4EC: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8002B4F0: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B4F4: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B4F8: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B4FC: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x8002B500: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002B504: lbu         $t3, 0x3084($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3084);
    // 0x8002B508: lwc1        $f8, 0x160($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B50C: lwc1        $f16, 0x15C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B510: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x8002B514: sra         $t0, $s0, 16
    ctx->r8 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B518: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x8002B51C: ori         $t4, $a2, 0x14D
    ctx->r12 = ctx->r6 | 0X14D;
    // 0x8002B520: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B524: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B528: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8002B52C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B530: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8002B534: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8002B538: jal         0x800B1F0C
    // 0x8002B53C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_29;
    // 0x8002B53C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_29:
    // 0x8002B540: lhu         $t7, 0x180($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X180);
    // 0x8002B544: nop

    // 0x8002B548: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8002B54C: sh          $t5, 0x180($sp)
    MEM_H(0X180, ctx->r29) = ctx->r13;
    // 0x8002B550: b           L_8002B978
    // 0x8002B554: nop

        goto L_8002B978;
    // 0x8002B554: nop

L_8002B558:
    // 0x8002B558: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x8002B55C: nop

    // 0x8002B560: lwc1        $f6, 0xCC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XCC);
    // 0x8002B564: nop

    // 0x8002B568: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
    // 0x8002B56C: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x8002B570: nop

    // 0x8002B574: lwc1        $f4, 0xD0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8002B578: nop

    // 0x8002B57C: swc1        $f4, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f4.u32l;
    // 0x8002B580: b           L_8002B978
    // 0x8002B584: nop

        goto L_8002B978;
    // 0x8002B584: nop

L_8002B588:
    // 0x8002B588: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B58C: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B590: jal         0x800B26E0
    // 0x8002B594: nop

    func_800B26E0(rdram, ctx);
        goto after_30;
    // 0x8002B594: nop

    after_30:
    // 0x8002B598: bgez        $v0, L_8002B5D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B59C: nop

            goto L_8002B5D0;
    }
    // 0x8002B59C: nop

    // 0x8002B5A0: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x8002B5A4: lw          $t9, 0x148($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X148);
    // 0x8002B5A8: nop

    // 0x8002B5AC: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x8002B5B0: nop

    // 0x8002B5B4: sw          $t0, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r8;
    // 0x8002B5B8: lw          $a0, 0x148($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X148);
    // 0x8002B5BC: jal         0x800299C4
    // 0x8002B5C0: nop

    func_800299C4(rdram, ctx);
        goto after_31;
    // 0x8002B5C0: nop

    after_31:
    // 0x8002B5C4: lw          $t1, 0x144($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X144);
    // 0x8002B5C8: nop

    // 0x8002B5CC: sw          $t1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r9;
L_8002B5D0:
    // 0x8002B5D0: b           L_8002B978
    // 0x8002B5D4: nop

        goto L_8002B978;
    // 0x8002B5D4: nop

L_8002B5D8:
    // 0x8002B5D8: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B5DC: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B5E0: jal         0x800B26E0
    // 0x8002B5E4: nop

    func_800B26E0(rdram, ctx);
        goto after_32;
    // 0x8002B5E4: nop

    after_32:
    // 0x8002B5E8: bgez        $v0, L_8002B6C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B5EC: nop

            goto L_8002B6C8;
    }
    // 0x8002B5EC: nop

    // 0x8002B5F0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8002B5F4: lw          $t2, 0x648($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X648);
    // 0x8002B5F8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002B5FC: lh          $t4, 0xA($t2)
    ctx->r12 = MEM_H(ctx->r10, 0XA);
    // 0x8002B600: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B604: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8002B608: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x8002B60C: jal         0x80028400
    // 0x8002B610: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_80028400(rdram, ctx);
        goto after_33;
    // 0x8002B610: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_33:
    // 0x8002B614: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8002B618: lbu         $t3, 0x3084($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X3084);
    // 0x8002B61C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8002B620: beq         $t3, $zero, L_8002B630
    if (ctx->r11 == 0) {
        // 0x8002B624: nop

            goto L_8002B630;
    }
    // 0x8002B624: nop

    // 0x8002B628: b           L_8002B634
    // 0x8002B62C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8002B634;
    // 0x8002B62C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002B630:
    // 0x8002B630: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8002B634:
    // 0x8002B634: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x8002B638: nop

    // 0x8002B63C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002B640: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8002B644: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8002B648: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002B64C: nop

    // 0x8002B650: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x8002B654: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002B658: sb          $t7, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r15;
    // 0x8002B65C: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B660: jal         0x800294D4
    // 0x8002B664: nop

    func_800294D4(rdram, ctx);
        goto after_34;
    // 0x8002B664: nop

    after_34:
    // 0x8002B668: lh          $t6, 0x188($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X188);
    // 0x8002B66C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B670: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8002B674: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B678: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B67C: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B680: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002B684: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8002B688: lbu         $t0, 0x3084($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X3084);
    // 0x8002B68C: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B690: lwc1        $f18, 0x15C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B694: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002B698: sra         $t5, $s0, 16
    ctx->r13 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B69C: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x8002B6A0: ori         $t9, $a2, 0x143
    ctx->r25 = ctx->r6 | 0X143;
    // 0x8002B6A4: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B6A8: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B6AC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8002B6B0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B6B4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8002B6B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002B6BC: jal         0x800B1F0C
    // 0x8002B6C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_35;
    // 0x8002B6C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_35:
    // 0x8002B6C4: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
L_8002B6C8:
    // 0x8002B6C8: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x8002B6CC: nop

    // 0x8002B6D0: lwc1        $f10, 0xCC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8002B6D4: nop

    // 0x8002B6D8: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
    // 0x8002B6DC: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x8002B6E0: nop

    // 0x8002B6E4: lwc1        $f8, 0xD0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8002B6E8: nop

    // 0x8002B6EC: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B6F0: b           L_8002B978
    // 0x8002B6F4: nop

        goto L_8002B978;
    // 0x8002B6F4: nop

L_8002B6F8:
    // 0x8002B6F8: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B6FC: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B700: jal         0x800B26E0
    // 0x8002B704: nop

    func_800B26E0(rdram, ctx);
        goto after_36;
    // 0x8002B704: nop

    after_36:
    // 0x8002B708: bgez        $v0, L_8002B740
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B70C: nop

            goto L_8002B740;
    }
    // 0x8002B70C: nop

    // 0x8002B710: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x8002B714: lw          $t4, 0x148($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X148);
    // 0x8002B718: nop

    // 0x8002B71C: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x8002B720: nop

    // 0x8002B724: sw          $t3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r11;
    // 0x8002B728: lw          $a0, 0x148($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X148);
    // 0x8002B72C: jal         0x8002BE00
    // 0x8002B730: nop

    func_8002BE00(rdram, ctx);
        goto after_37;
    // 0x8002B730: nop

    after_37:
    // 0x8002B734: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8002B738: b           L_8002B768
    // 0x8002B73C: sw          $t7, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r15;
        goto L_8002B768;
    // 0x8002B73C: sw          $t7, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r15;
L_8002B740:
    // 0x8002B740: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x8002B744: nop

    // 0x8002B748: lwc1        $f16, 0xCC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8002B74C: nop

    // 0x8002B750: swc1        $f16, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f16.u32l;
    // 0x8002B754: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x8002B758: nop

    // 0x8002B75C: lwc1        $f6, 0xD0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8002B760: nop

    // 0x8002B764: swc1        $f6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f6.u32l;
L_8002B768:
    // 0x8002B768: b           L_8002B978
    // 0x8002B76C: nop

        goto L_8002B978;
    // 0x8002B76C: nop

L_8002B770:
    // 0x8002B770: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B774: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B778: jal         0x800B26E0
    // 0x8002B77C: nop

    func_800B26E0(rdram, ctx);
        goto after_38;
    // 0x8002B77C: nop

    after_38:
    // 0x8002B780: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x8002B784: nop

    // 0x8002B788: lwc1        $f4, 0xCC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x8002B78C: nop

    // 0x8002B790: swc1        $f4, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f4.u32l;
    // 0x8002B794: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x8002B798: nop

    // 0x8002B79C: lwc1        $f18, 0xD0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x8002B7A0: nop

    // 0x8002B7A4: swc1        $f18, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f18.u32l;
    // 0x8002B7A8: b           L_8002B978
    // 0x8002B7AC: nop

        goto L_8002B978;
    // 0x8002B7AC: nop

L_8002B7B0:
    // 0x8002B7B0: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B7B4: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B7B8: jal         0x800B26E0
    // 0x8002B7BC: nop

    func_800B26E0(rdram, ctx);
        goto after_39;
    // 0x8002B7BC: nop

    after_39:
    // 0x8002B7C0: bgez        $v0, L_8002B800
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B7C4: nop

            goto L_8002B800;
    }
    // 0x8002B7C4: nop

    // 0x8002B7C8: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x8002B7CC: lw          $t0, 0x148($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X148);
    // 0x8002B7D0: nop

    // 0x8002B7D4: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8002B7D8: nop

    // 0x8002B7DC: sw          $t1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r9;
    // 0x8002B7E0: lw          $a0, 0x148($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X148);
    // 0x8002B7E4: jal         0x800299C4
    // 0x8002B7E8: nop

    func_800299C4(rdram, ctx);
        goto after_40;
    // 0x8002B7E8: nop

    after_40:
    // 0x8002B7EC: lw          $t2, 0x144($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X144);
    // 0x8002B7F0: nop

    // 0x8002B7F4: sw          $t2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r10;
    // 0x8002B7F8: b           L_8002B978
    // 0x8002B7FC: nop

        goto L_8002B978;
    // 0x8002B7FC: nop

L_8002B800:
    // 0x8002B800: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x8002B804: nop

    // 0x8002B808: lwc1        $f10, 0xCC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8002B80C: nop

    // 0x8002B810: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
    // 0x8002B814: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x8002B818: nop

    // 0x8002B81C: lwc1        $f8, 0xD0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8002B820: nop

    // 0x8002B824: swc1        $f8, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B828: b           L_8002B978
    // 0x8002B82C: nop

        goto L_8002B978;
    // 0x8002B82C: nop

L_8002B830:
    // 0x8002B830: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002B834: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x8002B838: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8002B83C: lh          $t5, 0xC($t7)
    ctx->r13 = MEM_H(ctx->r15, 0XC);
    // 0x8002B840: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B844: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8002B848: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x8002B84C: jal         0x80028400
    // 0x8002B850: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    func_80028400(rdram, ctx);
        goto after_41;
    // 0x8002B850: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    after_41:
    // 0x8002B854: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8002B858: lbu         $t6, 0x3084($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3084);
    // 0x8002B85C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8002B860: beq         $t6, $zero, L_8002B870
    if (ctx->r14 == 0) {
        // 0x8002B864: nop

            goto L_8002B870;
    }
    // 0x8002B864: nop

    // 0x8002B868: b           L_8002B874
    // 0x8002B86C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8002B874;
    // 0x8002B86C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8002B870:
    // 0x8002B870: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8002B874:
    // 0x8002B874: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x8002B878: nop

    // 0x8002B87C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002B880: mul.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8002B884: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x8002B888: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002B88C: lw          $t8, 0x648($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X648);
    // 0x8002B890: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8002B894: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x8002B898: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002B89C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8002B8A0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    // 0x8002B8A4: jal         0x80028400
    // 0x8002B8A8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_80028400(rdram, ctx);
        goto after_42;
    // 0x8002B8A8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_42:
    // 0x8002B8AC: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8002B8B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002B8B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002B8B8: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8002B8BC: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8002B8C0: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8002B8C4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8002B8C8: sb          $t0, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r8;
    // 0x8002B8CC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8002B8D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002B8D4: nop

    // 0x8002B8D8: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x8002B8DC: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B8E0: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B8E4: jal         0x8009A2C4
    // 0x8002B8E8: nop

    func_8009A2C4(rdram, ctx);
        goto after_43;
    // 0x8002B8E8: nop

    after_43:
    // 0x8002B8EC: b           L_8002B978
    // 0x8002B8F0: nop

        goto L_8002B978;
    // 0x8002B8F0: nop

L_8002B8F4:
    // 0x8002B8F4: lh          $a0, 0x188($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X188);
    // 0x8002B8F8: jal         0x800294D4
    // 0x8002B8FC: nop

    func_800294D4(rdram, ctx);
        goto after_44;
    // 0x8002B8FC: nop

    after_44:
    // 0x8002B900: lh          $t2, 0x188($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X188);
    // 0x8002B904: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8002B908: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8002B90C: lbu         $a2, -0x471D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X471D);
    // 0x8002B910: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x8002B914: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8002B918: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x8002B91C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8002B920: lbu         $t7, 0x3084($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X3084);
    // 0x8002B924: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B928: lwc1        $f8, 0x15C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002B92C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8002B930: sra         $t1, $s0, 16
    ctx->r9 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002B934: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8002B938: ori         $t3, $a2, 0x143
    ctx->r11 = ctx->r6 | 0X143;
    // 0x8002B93C: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002B940: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x8002B944: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8002B948: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002B94C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8002B950: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8002B954: jal         0x800B1F0C
    // 0x8002B958: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_45;
    // 0x8002B958: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_45:
    // 0x8002B95C: sh          $zero, 0x180($sp)
    MEM_H(0X180, ctx->r29) = 0;
    // 0x8002B960: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002B964: nop

    // 0x8002B968: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x8002B96C: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x8002B970: b           L_8002B978
    // 0x8002B974: nop

        goto L_8002B978;
    // 0x8002B974: nop

L_8002B978:
    // 0x8002B978: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8002B97C: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x8002B980: nop

    // 0x8002B984: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x8002B988: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8002B98C: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x8002B990: nop

    // 0x8002B994: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x8002B998: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002B99C: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x8002B9A0: nop

    // 0x8002B9A4: swc1        $f18, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f18.u32l;
    // 0x8002B9A8: lbu         $t9, 0x87($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X87);
    // 0x8002B9AC: lw          $t0, 0x140($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X140);
    // 0x8002B9B0: nop

    // 0x8002B9B4: sb          $t9, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r25;
    // 0x8002B9B8: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x8002B9BC: nop

    // 0x8002B9C0: beq         $t1, $zero, L_8002BA60
    if (ctx->r9 == 0) {
        // 0x8002B9C4: nop

            goto L_8002BA60;
    }
    // 0x8002B9C4: nop

    // 0x8002B9C8: lhu         $t2, 0x180($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X180);
    // 0x8002B9CC: lw          $t4, 0x148($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X148);
    // 0x8002B9D0: nop

    // 0x8002B9D4: sh          $t2, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r10;
    // 0x8002B9D8: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8002B9DC: lw          $t3, 0x148($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X148);
    // 0x8002B9E0: nop

    // 0x8002B9E4: swc1        $f10, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f10.u32l;
    // 0x8002B9E8: lw          $t7, 0x148($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X148);
    // 0x8002B9EC: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x8002B9F0: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002B9F4: nop

    // 0x8002B9F8: swc1        $f8, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f8.u32l;
    // 0x8002B9FC: lwc1        $f16, 0x15C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8002BA00: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x8002BA04: nop

    // 0x8002BA08: swc1        $f16, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f16.u32l;
    // 0x8002BA0C: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x8002BA10: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x8002BA14: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8002BA18: nop

    // 0x8002BA1C: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    // 0x8002BA20: jal         0x800C1850
    // 0x8002BA24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_Identity(rdram, ctx);
        goto after_46;
    // 0x8002BA24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_46:
    // 0x8002BA28: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002BA2C: jal         0x8009A14C
    // 0x8002BA30: nop

    func_8009A14C(rdram, ctx);
        goto after_47;
    // 0x8002BA30: nop

    after_47:
    // 0x8002BA34: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002BA38: jal         0x8009A264
    // 0x8002BA3C: nop

    func_8009A264(rdram, ctx);
        goto after_48;
    // 0x8002BA3C: nop

    after_48:
    // 0x8002BA40: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    // 0x8002BA44: jal         0x800997D8
    // 0x8002BA48: nop

    func_800997D8(rdram, ctx);
        goto after_49;
    // 0x8002BA48: nop

    after_49:
    // 0x8002BA4C: lw          $t0, 0x148($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X148);
    // 0x8002BA50: nop

    // 0x8002BA54: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8002BA58: nop

    // 0x8002BA5C: sw          $t1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r9;
L_8002BA60:
    // 0x8002BA60: addiu       $a0, $sp, 0x14C
    ctx->r4 = ADD32(ctx->r29, 0X14C);
    // 0x8002BA64: jal         0x800B3434
    // 0x8002BA68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3434(rdram, ctx);
        goto after_50;
    // 0x8002BA68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_50:
    // 0x8002BA6C: andi        $t2, $v0, 0x4000
    ctx->r10 = ctx->r2 & 0X4000;
    // 0x8002BA70: beq         $t2, $zero, L_8002BA90
    if (ctx->r10 == 0) {
        // 0x8002BA74: nop

            goto L_8002BA90;
    }
    // 0x8002BA74: nop

    // 0x8002BA78: addiu       $a0, $sp, 0x14C
    ctx->r4 = ADD32(ctx->r29, 0X14C);
    // 0x8002BA7C: jal         0x800B32E4
    // 0x8002BA80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B32E4(rdram, ctx);
        goto after_51;
    // 0x8002BA80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x8002BA84: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x8002BA88: jal         0x800B9000
    // 0x8002BA8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B9000(rdram, ctx);
        goto after_52;
    // 0x8002BA8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
L_8002BA90:
    // 0x8002BA90: lh          $t4, 0x18E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X18E);
    // 0x8002BA94: lh          $t6, 0x84($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X84);
    // 0x8002BA98: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x8002BA9C: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x8002BAA0: sra         $t5, $t7, 16
    ctx->r13 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BAA4: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002BAA8: bne         $at, $zero, L_8002A420
    if (ctx->r1 != 0) {
        // 0x8002BAAC: sh          $t3, 0x18E($sp)
        MEM_H(0X18E, ctx->r29) = ctx->r11;
            goto L_8002A420;
    }
    // 0x8002BAAC: sh          $t3, 0x18E($sp)
    MEM_H(0X18E, ctx->r29) = ctx->r11;
L_8002BAB0:
    // 0x8002BAB0: jal         0x800C1A28
    // 0x8002BAB4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_53;
    // 0x8002BAB4: nop

    after_53:
    // 0x8002BAB8: b           L_8002BAC0
    // 0x8002BABC: nop

        goto L_8002BAC0;
    // 0x8002BABC: nop

L_8002BAC0:
    // 0x8002BAC0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8002BAC4: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002BAC8: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002BACC: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002BAD0: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002BAD4: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002BAD8: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002BADC: lwc1        $f27, 0x38($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002BAE0: lwc1        $f26, 0x3C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002BAE4: lwc1        $f29, 0x40($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002BAE8: lwc1        $f28, 0x44($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002BAEC: lwc1        $f31, 0x48($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8002BAF0: lwc1        $f30, 0x4C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002BAF4: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x8002BAF8: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x8002BAFC: jr          $ra
    // 0x8002BB00: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x8002BB00: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
