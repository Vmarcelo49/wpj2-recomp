#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void func_800A4ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4ED8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800A4EDC: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800A4EE0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A4EE4: nop

    // 0x800A4EE8: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800A4EEC: lw          $t7, 0xC0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC0);
    // 0x800A4EF0: nop

    // 0x800A4EF4: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x800A4EF8: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4EFC: nop

    // 0x800A4F00: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A4F04: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800A4F08: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x800A4F0C: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x800A4F10: lui         $t0, 0x104
    ctx->r8 = S32(0X104 << 16);
    // 0x800A4F14: ori         $t0, $t0, 0x40
    ctx->r8 = ctx->r8 | 0X40;
    // 0x800A4F18: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A4F1C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A4F20: lw          $t2, 0x70E4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70E4);
    // 0x800A4F24: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A4F28: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x800A4F2C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800A4F30: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x800A4F34: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A4F38: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800A4F3C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A4F40: lw          $t7, 0xDC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XDC);
    // 0x800A4F44: nop

    // 0x800A4F48: beq         $t7, $zero, L_800A4F88
    if (ctx->r15 == 0) {
        // 0x800A4F4C: nop

            goto L_800A4F88;
    }
    // 0x800A4F4C: nop

    // 0x800A4F50: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4F54: nop

    // 0x800A4F58: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A4F5C: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800A4F60: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x800A4F64: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800A4F68: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x800A4F6C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A4F70: lw          $t2, 0xDC($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XDC);
    // 0x800A4F74: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A4F78: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800A4F7C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A4F80: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800A4F84: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_800A4F88:
    // 0x800A4F88: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4F8C: nop

    // 0x800A4F90: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A4F94: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800A4F98: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x800A4F9C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4FA0: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x800A4FA4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A4FA8: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800A4FAC: addiu       $t9, $zero, 0x2205
    ctx->r25 = ADD32(0, 0X2205);
    // 0x800A4FB0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A4FB4: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800A4FB8: nop

    // 0x800A4FBC: andi        $t2, $t1, 0x800
    ctx->r10 = ctx->r9 & 0X800;
    // 0x800A4FC0: beq         $t2, $zero, L_800A4FF4
    if (ctx->r10 == 0) {
        // 0x800A4FC4: nop

            goto L_800A4FF4;
    }
    // 0x800A4FC4: nop

    // 0x800A4FC8: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4FCC: nop

    // 0x800A4FD0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A4FD4: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x800A4FD8: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x800A4FDC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800A4FE0: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x800A4FE4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A4FE8: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800A4FEC: addiu       $t7, $zero, 0x3000
    ctx->r15 = ADD32(0, 0X3000);
    // 0x800A4FF0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_800A4FF4:
    // 0x800A4FF4: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A4FF8: nop

    // 0x800A4FFC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A5000: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800A5004: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800A5008: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800A500C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x800A5010: ori         $t1, $t1, 0x201
    ctx->r9 = ctx->r9 | 0X201;
    // 0x800A5014: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A5018: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800A501C: nop

    // 0x800A5020: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A5024: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x800A5028: nop

    // 0x800A502C: andi        $t5, $t4, 0x2000
    ctx->r13 = ctx->r12 & 0X2000;
    // 0x800A5030: bne         $t5, $zero, L_800A5240
    if (ctx->r13 != 0) {
        // 0x800A5034: nop

            goto L_800A5240;
    }
    // 0x800A5034: nop

    // 0x800A5038: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A503C: nop

    // 0x800A5040: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A5044: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A5048: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800A504C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800A5050: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800A5054: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x800A5058: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A505C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800A5060: nop

    // 0x800A5064: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800A5068: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x800A506C: nop

    // 0x800A5070: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x800A5074: bne         $t2, $zero, L_800A51D0
    if (ctx->r10 != 0) {
        // 0x800A5078: nop

            goto L_800A51D0;
    }
    // 0x800A5078: nop

    // 0x800A507C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x800A5080: nop

    // 0x800A5084: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x800A5088: bne         $t4, $zero, L_800A5100
    if (ctx->r12 != 0) {
        // 0x800A508C: nop

            goto L_800A5100;
    }
    // 0x800A508C: nop

    // 0x800A5090: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5094: nop

    // 0x800A5098: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A509C: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800A50A0: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x800A50A4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800A50A8: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x800A50AC: ori         $t7, $t7, 0xFE24
    ctx->r15 = ctx->r15 | 0XFE24;
    // 0x800A50B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A50B4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800A50B8: lui         $t9, 0xFF30
    ctx->r25 = S32(0XFF30 << 16);
    // 0x800A50BC: ori         $t9, $t9, 0xF3FF
    ctx->r25 = ctx->r25 | 0XF3FF;
    // 0x800A50C0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A50C4: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800A50C8: nop

    // 0x800A50CC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A50D0: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x800A50D4: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x800A50D8: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800A50DC: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x800A50E0: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x800A50E4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A50E8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800A50EC: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x800A50F0: ori         $t5, $t5, 0x2078
    ctx->r13 = ctx->r13 | 0X2078;
    // 0x800A50F4: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A50F8: b           L_800A51C8
    // 0x800A50FC: nop

        goto L_800A51C8;
    // 0x800A50FC: nop

L_800A5100:
    // 0x800A5100: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5104: nop

    // 0x800A5108: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A510C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x800A5110: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800A5114: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800A5118: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800A511C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5120: lh          $t1, 0xCC($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XCC);
    // 0x800A5124: lh          $t4, 0xCE($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XCE);
    // 0x800A5128: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800A512C: lh          $t8, 0xD0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XD0);
    // 0x800A5130: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x800A5134: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A5138: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800A513C: lh          $t2, 0xD2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XD2);
    // 0x800A5140: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800A5144: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800A5148: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x800A514C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800A5150: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x800A5154: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x800A5158: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x800A515C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800A5160: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5164: nop

    // 0x800A5168: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x800A516C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x800A5170: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x800A5174: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A5178: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800A517C: ori         $t9, $t9, 0x97FF
    ctx->r25 = ctx->r25 | 0X97FF;
    // 0x800A5180: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800A5184: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800A5188: lui         $t0, 0xFF2C
    ctx->r8 = S32(0XFF2C << 16);
    // 0x800A518C: ori         $t0, $t0, 0xFE7F
    ctx->r8 = ctx->r8 | 0XFE7F;
    // 0x800A5190: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x800A5194: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5198: nop

    // 0x800A519C: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x800A51A0: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x800A51A4: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800A51A8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A51AC: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x800A51B0: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x800A51B4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800A51B8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800A51BC: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x800A51C0: ori         $t6, $t6, 0x4A50
    ctx->r14 = ctx->r14 | 0X4A50;
    // 0x800A51C4: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
L_800A51C8:
    // 0x800A51C8: b           L_800A5238
    // 0x800A51CC: nop

        goto L_800A5238;
    // 0x800A51CC: nop

L_800A51D0:
    // 0x800A51D0: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A51D4: nop

    // 0x800A51D8: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x800A51DC: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A51E0: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x800A51E4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800A51E8: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x800A51EC: ori         $t0, $t0, 0xFE24
    ctx->r8 = ctx->r8 | 0XFE24;
    // 0x800A51F0: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800A51F4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800A51F8: lui         $t1, 0xFF30
    ctx->r9 = S32(0XFF30 << 16);
    // 0x800A51FC: ori         $t1, $t1, 0xF3FF
    ctx->r9 = ctx->r9 | 0XF3FF;
    // 0x800A5200: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800A5204: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5208: nop

    // 0x800A520C: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x800A5210: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800A5214: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x800A5218: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800A521C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x800A5220: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x800A5224: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800A5228: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A522C: lui         $t9, 0xF0A
    ctx->r25 = S32(0XF0A << 16);
    // 0x800A5230: ori         $t9, $t9, 0x233
    ctx->r25 = ctx->r25 | 0X233;
    // 0x800A5234: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_800A5238:
    // 0x800A5238: b           L_800A5474
    // 0x800A523C: nop

        goto L_800A5474;
    // 0x800A523C: nop

L_800A5240:
    // 0x800A5240: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5244: nop

    // 0x800A5248: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x800A524C: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x800A5250: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800A5254: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800A5258: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x800A525C: ori         $t1, $t1, 0x1402
    ctx->r9 = ctx->r9 | 0X1402;
    // 0x800A5260: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800A5264: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A5268: lui         $t5, 0x10
    ctx->r13 = S32(0X10 << 16);
    // 0x800A526C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800A5270: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800A5274: nop

    // 0x800A5278: andi        $t8, $t6, 0x8000
    ctx->r24 = ctx->r14 & 0X8000;
    // 0x800A527C: bne         $t8, $zero, L_800A5380
    if (ctx->r24 != 0) {
        // 0x800A5280: nop

            goto L_800A5380;
    }
    // 0x800A5280: nop

    // 0x800A5284: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5288: nop

    // 0x800A528C: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x800A5290: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A5294: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800A5298: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800A529C: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x800A52A0: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800A52A4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800A52A8: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x800A52AC: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800A52B0: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800A52B4: nop

    // 0x800A52B8: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x800A52BC: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800A52C0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800A52C4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800A52C8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A52CC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800A52D0: lh          $t9, 0xCC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XCC);
    // 0x800A52D4: lh          $t2, 0xCE($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XCE);
    // 0x800A52D8: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800A52DC: lh          $t3, 0xD0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XD0);
    // 0x800A52E0: sll         $t0, $t7, 24
    ctx->r8 = S32(ctx->r15 << 24);
    // 0x800A52E4: andi        $t1, $t2, 0xFF
    ctx->r9 = ctx->r10 & 0XFF;
    // 0x800A52E8: sll         $t4, $t1, 16
    ctx->r12 = S32(ctx->r9 << 16);
    // 0x800A52EC: lh          $t7, 0xD2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XD2);
    // 0x800A52F0: or          $t5, $t0, $t4
    ctx->r13 = ctx->r8 | ctx->r12;
    // 0x800A52F4: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x800A52F8: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800A52FC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800A5300: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x800A5304: andi        $t2, $t7, 0xFF
    ctx->r10 = ctx->r15 & 0XFF;
    // 0x800A5308: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x800A530C: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x800A5310: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5314: nop

    // 0x800A5318: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x800A531C: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800A5320: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x800A5324: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800A5328: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x800A532C: ori         $t6, $t6, 0x18C3
    ctx->r14 = ctx->r14 | 0X18C3;
    // 0x800A5330: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x800A5334: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800A5338: lui         $t8, 0xFFCF
    ctx->r24 = S32(0XFFCF << 16);
    // 0x800A533C: ori         $t8, $t8, 0xFE38
    ctx->r24 = ctx->r24 | 0XFE38;
    // 0x800A5340: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x800A5344: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5348: nop

    // 0x800A534C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800A5350: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x800A5354: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A5358: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A535C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x800A5360: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x800A5364: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800A5368: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800A536C: lui         $t4, 0xC811
    ctx->r12 = S32(0XC811 << 16);
    // 0x800A5370: ori         $t4, $t4, 0x2078
    ctx->r12 = ctx->r12 | 0X2078;
    // 0x800A5374: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A5378: b           L_800A5474
    // 0x800A537C: nop

        goto L_800A5474;
    // 0x800A537C: nop

L_800A5380:
    // 0x800A5380: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5384: nop

    // 0x800A5388: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x800A538C: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800A5390: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800A5394: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5398: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x800A539C: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800A53A0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800A53A4: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800A53A8: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800A53AC: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800A53B0: nop

    // 0x800A53B4: addiu       $t0, $t1, 0x8
    ctx->r8 = ADD32(ctx->r9, 0X8);
    // 0x800A53B8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800A53BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800A53C0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A53C4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800A53C8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A53CC: lh          $t6, 0xCC($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XCC);
    // 0x800A53D0: lh          $t7, 0xCE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XCE);
    // 0x800A53D4: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x800A53D8: lh          $t0, 0xD0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XD0);
    // 0x800A53DC: sll         $t8, $t5, 24
    ctx->r24 = S32(ctx->r13 << 24);
    // 0x800A53E0: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800A53E4: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800A53E8: lh          $t5, 0xD2($a1)
    ctx->r13 = MEM_H(ctx->r5, 0XD2);
    // 0x800A53EC: or          $t1, $t8, $t2
    ctx->r9 = ctx->r24 | ctx->r10;
    // 0x800A53F0: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x800A53F4: sll         $t3, $t4, 8
    ctx->r11 = S32(ctx->r12 << 8);
    // 0x800A53F8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800A53FC: or          $t6, $t1, $t3
    ctx->r14 = ctx->r9 | ctx->r11;
    // 0x800A5400: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x800A5404: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800A5408: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800A540C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5410: nop

    // 0x800A5414: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A5418: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800A541C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800A5420: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800A5424: lui         $t4, 0xFC12
    ctx->r12 = S32(0XFC12 << 16);
    // 0x800A5428: ori         $t4, $t4, 0x18C3
    ctx->r12 = ctx->r12 | 0X18C3;
    // 0x800A542C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800A5430: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800A5434: lui         $t3, 0xFFCF
    ctx->r11 = S32(0XFFCF << 16);
    // 0x800A5438: ori         $t3, $t3, 0xFE38
    ctx->r11 = ctx->r11 | 0XFE38;
    // 0x800A543C: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x800A5440: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5444: nop

    // 0x800A5448: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A544C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A5450: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800A5454: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A5458: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x800A545C: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x800A5460: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x800A5464: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A5468: lui         $t2, 0xC810
    ctx->r10 = S32(0XC810 << 16);
    // 0x800A546C: ori         $t2, $t2, 0x4A50
    ctx->r10 = ctx->r10 | 0X4A50;
    // 0x800A5470: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
L_800A5474:
    // 0x800A5474: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5478: nop

    // 0x800A547C: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x800A5480: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800A5484: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A5488: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800A548C: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A5490: ori         $t3, $t3, 0x1301
    ctx->r11 = ctx->r11 | 0X1301;
    // 0x800A5494: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800A5498: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A549C: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800A54A0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A54A4: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800A54A8: nop

    // 0x800A54AC: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800A54B0: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x800A54B4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A54B8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800A54BC: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x800A54C0: ori         $t2, $t2, 0x1102
    ctx->r10 = ctx->r10 | 0X1102;
    // 0x800A54C4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A54C8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A54CC: lui         $t4, 0x4
    ctx->r12 = S32(0X4 << 16);
    // 0x800A54D0: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x800A54D4: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800A54D8: nop

    // 0x800A54DC: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x800A54E0: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800A54E4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A54E8: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800A54EC: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x800A54F0: ori         $t6, $t6, 0x1001
    ctx->r14 = ctx->r14 | 0X1001;
    // 0x800A54F4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A54F8: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800A54FC: nop

    // 0x800A5500: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A5504: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5508: nop

    // 0x800A550C: addiu       $t2, $t8, 0x8
    ctx->r10 = ADD32(ctx->r24, 0X8);
    // 0x800A5510: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x800A5514: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A5518: lw          $t4, 0x10($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10);
    // 0x800A551C: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x800A5520: ori         $t0, $t0, 0xE02
    ctx->r8 = ctx->r8 | 0XE02;
    // 0x800A5524: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800A5528: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x800A552C: nop

    // 0x800A5530: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A5534: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5538: nop

    // 0x800A553C: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x800A5540: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800A5544: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x800A5548: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800A554C: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x800A5550: ori         $t6, $t6, 0xC02
    ctx->r14 = ctx->r14 | 0XC02;
    // 0x800A5554: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A5558: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800A555C: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800A5560: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800A5564: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5568: nop

    // 0x800A556C: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A5570: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800A5574: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
    // 0x800A5578: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800A557C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800A5580: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800A5584: lw          $t3, 0xD8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XD8);
    // 0x800A5588: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A558C: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800A5590: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5594: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800A5598: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A559C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800A55A0: nop

    // 0x800A55A4: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800A55A8: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800A55AC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800A55B0: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800A55B4: lui         $t8, 0xBD00
    ctx->r24 = S32(0XBD00 << 16);
    // 0x800A55B8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800A55BC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800A55C0: nop

    // 0x800A55C4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800A55C8: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800A55CC: nop

    // 0x800A55D0: addiu       $t1, $t4, 0x8
    ctx->r9 = ADD32(ctx->r12, 0X8);
    // 0x800A55D4: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800A55D8: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x800A55DC: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800A55E0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800A55E4: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800A55E8: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800A55EC: nop

    // 0x800A55F0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A55F4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800A55F8: nop

    // 0x800A55FC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A5600: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800A5604: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5608: sw          $t9, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = ctx->r25;
    // 0x800A560C: b           L_800A561C
    // 0x800A5610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A561C;
    // 0x800A5610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A5614: b           L_800A561C
    // 0x800A5618: nop

        goto L_800A561C;
    // 0x800A5618: nop

L_800A561C:
    // 0x800A561C: jr          $ra
    // 0x800A5620: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800A5620: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_800A5624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5624: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A5628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A562C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A5630: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A5634: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A5638: nop

    // 0x800A563C: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800A5640: bne         $at, $zero, L_800A5650
    if (ctx->r1 != 0) {
        // 0x800A5644: nop

            goto L_800A5650;
    }
    // 0x800A5644: nop

    // 0x800A5648: b           L_800A57B4
    // 0x800A564C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A57B4;
    // 0x800A564C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A5650:
    // 0x800A5650: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800A5654: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5658: sw          $t7, -0x7268($at)
    MEM_W(-0X7268, ctx->r1) = ctx->r15;
    // 0x800A565C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A5660: lw          $t8, -0x7268($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7268);
    // 0x800A5664: nop

    // 0x800A5668: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x800A566C: beq         $at, $zero, L_800A5790
    if (ctx->r1 == 0) {
        // 0x800A5670: nop

            goto L_800A5790;
    }
    // 0x800A5670: nop

    // 0x800A5674: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A5678: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A567C: addu        $at, $at, $t8
    gpr jr_addend_800A5688 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800A5680: lw          $t8, -0x798($at)
    ctx->r24 = ADD32(ctx->r1, -0X798);
    // 0x800A5684: nop

    // 0x800A5688: jr          $t8
    // 0x800A568C: nop

    switch (jr_addend_800A5688 >> 2) {
        case 0: goto L_800A5690; break;
        case 1: goto L_800A56B0; break;
        case 2: goto L_800A56D0; break;
        case 3: goto L_800A56F0; break;
        case 4: goto L_800A5710; break;
        case 5: goto L_800A5730; break;
        case 6: goto L_800A5750; break;
        case 7: goto L_800A5770; break;
        default: switch_error(__func__, 0x800A5688, 0x800EF868);
    }
    // 0x800A568C: nop

L_800A5690:
    // 0x800A5690: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5694: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5698: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A569C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A56A0: jal         0x800BCFCC
    // 0x800A56A4: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x800A56A4: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x800A56A8: b           L_800A5790
    // 0x800A56AC: nop

        goto L_800A5790;
    // 0x800A56AC: nop

L_800A56B0:
    // 0x800A56B0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A56B4: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A56B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A56BC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A56C0: jal         0x800BCFCC
    // 0x800A56C4: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    SysMem_Copy8(rdram, ctx);
        goto after_1;
    // 0x800A56C4: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_1:
    // 0x800A56C8: b           L_800A5790
    // 0x800A56CC: nop

        goto L_800A5790;
    // 0x800A56CC: nop

L_800A56D0:
    // 0x800A56D0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A56D4: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A56D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A56DC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A56E0: jal         0x800BCFCC
    // 0x800A56E4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x800A56E4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_2:
    // 0x800A56E8: b           L_800A5790
    // 0x800A56EC: nop

        goto L_800A5790;
    // 0x800A56EC: nop

L_800A56F0:
    // 0x800A56F0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A56F4: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A56F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A56FC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5700: jal         0x800BCFCC
    // 0x800A5704: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x800A5704: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_3:
    // 0x800A5708: b           L_800A5790
    // 0x800A570C: nop

        goto L_800A5790;
    // 0x800A570C: nop

L_800A5710:
    // 0x800A5710: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5714: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5718: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A571C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5720: jal         0x800BCFCC
    // 0x800A5724: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x800A5724: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_4:
    // 0x800A5728: b           L_800A5790
    // 0x800A572C: nop

        goto L_800A5790;
    // 0x800A572C: nop

L_800A5730:
    // 0x800A5730: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5734: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5738: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A573C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5740: jal         0x800BCFCC
    // 0x800A5744: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x800A5744: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    after_5:
    // 0x800A5748: b           L_800A5790
    // 0x800A574C: nop

        goto L_800A5790;
    // 0x800A574C: nop

L_800A5750:
    // 0x800A5750: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5754: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5758: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A575C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5760: jal         0x800BCFCC
    // 0x800A5764: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    SysMem_Copy8(rdram, ctx);
        goto after_6;
    // 0x800A5764: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    after_6:
    // 0x800A5768: b           L_800A5790
    // 0x800A576C: nop

        goto L_800A5790;
    // 0x800A576C: nop

L_800A5770:
    // 0x800A5770: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800A5774: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x800A5778: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A577C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A5780: jal         0x800BCFCC
    // 0x800A5784: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    SysMem_Copy8(rdram, ctx);
        goto after_7;
    // 0x800A5784: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_7:
    // 0x800A5788: b           L_800A5790
    // 0x800A578C: nop

        goto L_800A5790;
    // 0x800A578C: nop

L_800A5790:
    // 0x800A5790: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A5794: lw          $t9, -0x71D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X71D0);
    // 0x800A5798: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A579C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800A57A0: sw          $t0, -0x71D0($at)
    MEM_W(-0X71D0, ctx->r1) = ctx->r8;
    // 0x800A57A4: b           L_800A57B4
    // 0x800A57A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A57B4;
    // 0x800A57A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A57AC: b           L_800A57B4
    // 0x800A57B0: nop

        goto L_800A57B4;
    // 0x800A57B0: nop

L_800A57B4:
    // 0x800A57B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A57B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A57BC: jr          $ra
    // 0x800A57C0: nop

    return;
    // 0x800A57C0: nop

;}
RECOMP_FUNC void func_800A57C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A57C4: slti        $at, $a0, 0x3E8
    ctx->r1 = SIGNED(ctx->r4) < 0X3E8 ? 1 : 0;
    // 0x800A57C8: bne         $at, $zero, L_800A57D4
    if (ctx->r1 != 0) {
        // 0x800A57CC: nop

            goto L_800A57D4;
    }
    // 0x800A57CC: nop

    // 0x800A57D0: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
L_800A57D4:
    // 0x800A57D4: slti        $at, $a1, 0x3E8
    ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
    // 0x800A57D8: bne         $at, $zero, L_800A57E4
    if (ctx->r1 != 0) {
        // 0x800A57DC: nop

            goto L_800A57E4;
    }
    // 0x800A57DC: nop

    // 0x800A57E0: addiu       $a1, $zero, 0x3E7
    ctx->r5 = ADD32(0, 0X3E7);
L_800A57E4:
    // 0x800A57E4: bne         $a0, $a1, L_800A57F0
    if (ctx->r4 != ctx->r5) {
        // 0x800A57E8: nop

            goto L_800A57F0;
    }
    // 0x800A57E8: nop

    // 0x800A57EC: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
L_800A57F0:
    // 0x800A57F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A57F4: sw          $a0, -0x71E8($at)
    MEM_W(-0X71E8, ctx->r1) = ctx->r4;
    // 0x800A57F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A57FC: sw          $a1, -0x71E4($at)
    MEM_W(-0X71E4, ctx->r1) = ctx->r5;
    // 0x800A5800: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5804: sw          $a2, -0x71E0($at)
    MEM_W(-0X71E0, ctx->r1) = ctx->r6;
    // 0x800A5808: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A580C: sw          $a3, -0x71DC($at)
    MEM_W(-0X71DC, ctx->r1) = ctx->r7;
    // 0x800A5810: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800A5814: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5818: sw          $t6, -0x71D8($at)
    MEM_W(-0X71D8, ctx->r1) = ctx->r14;
    // 0x800A581C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800A5820: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5824: sw          $t7, -0x71D4($at)
    MEM_W(-0X71D4, ctx->r1) = ctx->r15;
    // 0x800A5828: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A582C: lw          $t8, -0x71D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X71D0);
    // 0x800A5830: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A5834: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x800A5838: sw          $t9, -0x71D0($at)
    MEM_W(-0X71D0, ctx->r1) = ctx->r25;
    // 0x800A583C: jr          $ra
    // 0x800A5840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A5840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800A5844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5844: jr          $ra
    // 0x800A5848: nop

    return;
    // 0x800A5848: nop

    // 0x800A584C: jr          $ra
    // 0x800A5850: nop

    return;
    // 0x800A5850: nop

;}
RECOMP_FUNC void func_800A5854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5854: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800A5858: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A585C: nop

    // 0x800A5860: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A5864: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5868: lw          $t7, -0x71D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71D0);
    // 0x800A586C: nop

    // 0x800A5870: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800A5874: beq         $t8, $zero, L_800A62A8
    if (ctx->r24 == 0) {
        // 0x800A5878: nop

            goto L_800A62A8;
    }
    // 0x800A5878: nop

    // 0x800A587C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A5880: lw          $t9, -0x7268($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7268);
    // 0x800A5884: nop

    // 0x800A5888: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x800A588C: beq         $at, $zero, L_800A62A8
    if (ctx->r1 == 0) {
        // 0x800A5890: nop

            goto L_800A62A8;
    }
    // 0x800A5890: nop

    // 0x800A5894: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A5898: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A589C: addu        $at, $at, $t9
    gpr jr_addend_800A58A8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A58A0: lw          $t9, -0x778($at)
    ctx->r25 = ADD32(ctx->r1, -0X778);
    // 0x800A58A4: nop

    // 0x800A58A8: jr          $t9
    // 0x800A58AC: nop

    switch (jr_addend_800A58A8 >> 2) {
        case 0: goto L_800A58B0; break;
        case 1: goto L_800A595C; break;
        case 2: goto L_800A5A08; break;
        case 3: goto L_800A5AEC; break;
        case 4: goto L_800A5C08; break;
        case 5: goto L_800A5D5C; break;
        case 6: goto L_800A5EE8; break;
        case 7: goto L_800A60AC; break;
        default: switch_error(__func__, 0x800A58A8, 0x800EF888);
    }
    // 0x800A58AC: nop

L_800A58B0:
    // 0x800A58B0: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A58B4: nop

    // 0x800A58B8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A58BC: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A58C0: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x800A58C4: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x800A58C8: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800A58CC: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800A58D0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A58D4: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x800A58D8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A58DC: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x800A58E0: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A58E4: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A58E8: nop

    // 0x800A58EC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A58F0: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A58F4: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x800A58F8: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x800A58FC: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x800A5900: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A5904: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A5908: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A590C: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x800A5910: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A5914: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800A5918: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A591C: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5920: nop

    // 0x800A5924: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5928: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A592C: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
    // 0x800A5930: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x800A5934: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x800A5938: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A593C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5940: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5944: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800A5948: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A594C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5950: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5954: b           L_800A62A8
    // 0x800A5958: nop

        goto L_800A62A8;
    // 0x800A5958: nop

L_800A595C:
    // 0x800A595C: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5960: nop

    // 0x800A5964: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5968: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A596C: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x800A5970: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800A5974: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800A5978: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800A597C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5980: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x800A5984: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A5988: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x800A598C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A5990: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5994: nop

    // 0x800A5998: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A599C: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A59A0: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x800A59A4: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800A59A8: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x800A59AC: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A59B0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A59B4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A59B8: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800A59BC: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A59C0: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800A59C4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A59C8: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A59CC: nop

    // 0x800A59D0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A59D4: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A59D8: sw          $t3, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r11;
    // 0x800A59DC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x800A59E0: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x800A59E4: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A59E8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A59EC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A59F0: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x800A59F4: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A59F8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A59FC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5A00: b           L_800A62A8
    // 0x800A5A04: nop

        goto L_800A62A8;
    // 0x800A5A04: nop

L_800A5A08:
    // 0x800A5A08: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5A0C: nop

    // 0x800A5A10: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5A14: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5A18: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    // 0x800A5A1C: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x800A5A20: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800A5A24: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800A5A28: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5A2C: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x800A5A30: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A5A34: ori         $t4, $t4, 0x60
    ctx->r12 = ctx->r12 | 0X60;
    // 0x800A5A38: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A5A3C: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5A40: nop

    // 0x800A5A44: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A5A48: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A5A4C: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x800A5A50: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800A5A54: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x800A5A58: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A5A5C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A5A60: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A5A64: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A5A68: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A5A6C: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800A5A70: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A5A74: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5A78: nop

    // 0x800A5A7C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5A80: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A5A84: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x800A5A88: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x800A5A8C: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x800A5A90: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A5A94: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5A98: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5A9C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x800A5AA0: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A5AA4: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x800A5AA8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5AAC: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5AB0: nop

    // 0x800A5AB4: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5AB8: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5ABC: sw          $t0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r8;
    // 0x800A5AC0: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x800A5AC4: lui         $t2, 0x38A
    ctx->r10 = S32(0X38A << 16);
    // 0x800A5AC8: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x800A5ACC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5AD0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A5AD4: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800A5AD8: addiu       $t4, $t4, -0x7268
    ctx->r12 = ADD32(ctx->r12, -0X7268);
    // 0x800A5ADC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A5AE0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A5AE4: b           L_800A62A8
    // 0x800A5AE8: nop

        goto L_800A62A8;
    // 0x800A5AE8: nop

L_800A5AEC:
    // 0x800A5AEC: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5AF0: nop

    // 0x800A5AF4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5AF8: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800A5AFC: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x800A5B00: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x800A5B04: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800A5B08: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x800A5B0C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5B10: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800A5B14: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800A5B18: ori         $t1, $t1, 0x80
    ctx->r9 = ctx->r9 | 0X80;
    // 0x800A5B1C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A5B20: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5B24: nop

    // 0x800A5B28: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5B2C: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A5B30: sw          $t3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r11;
    // 0x800A5B34: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800A5B38: lui         $t5, 0x386
    ctx->r13 = S32(0X386 << 16);
    // 0x800A5B3C: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A5B40: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5B44: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5B48: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800A5B4C: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A5B50: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x800A5B54: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5B58: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5B5C: nop

    // 0x800A5B60: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5B64: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5B68: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x800A5B6C: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x800A5B70: lui         $t2, 0x388
    ctx->r10 = S32(0X388 << 16);
    // 0x800A5B74: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x800A5B78: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5B7C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A5B80: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x800A5B84: addiu       $t4, $t4, -0x7268
    ctx->r12 = ADD32(ctx->r12, -0X7268);
    // 0x800A5B88: addiu       $t5, $t4, 0x20
    ctx->r13 = ADD32(ctx->r12, 0X20);
    // 0x800A5B8C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A5B90: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5B94: nop

    // 0x800A5B98: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5B9C: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800A5BA0: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
    // 0x800A5BA4: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x800A5BA8: lui         $t9, 0x38A
    ctx->r25 = S32(0X38A << 16);
    // 0x800A5BAC: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800A5BB0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5BB4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800A5BB8: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800A5BBC: addiu       $t1, $t1, -0x7268
    ctx->r9 = ADD32(ctx->r9, -0X7268);
    // 0x800A5BC0: addiu       $t2, $t1, 0x30
    ctx->r10 = ADD32(ctx->r9, 0X30);
    // 0x800A5BC4: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A5BC8: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5BCC: nop

    // 0x800A5BD0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A5BD4: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A5BD8: sw          $t4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r12;
    // 0x800A5BDC: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x800A5BE0: lui         $t6, 0x38C
    ctx->r14 = S32(0X38C << 16);
    // 0x800A5BE4: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x800A5BE8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A5BEC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A5BF0: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800A5BF4: addiu       $t8, $t8, -0x7268
    ctx->r24 = ADD32(ctx->r24, -0X7268);
    // 0x800A5BF8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A5BFC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A5C00: b           L_800A62A8
    // 0x800A5C04: nop

        goto L_800A62A8;
    // 0x800A5C04: nop

L_800A5C08:
    // 0x800A5C08: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5C0C: nop

    // 0x800A5C10: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A5C14: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800A5C18: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x800A5C1C: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800A5C20: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x800A5C24: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x800A5C28: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A5C2C: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800A5C30: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800A5C34: ori         $t5, $t5, 0xA0
    ctx->r13 = ctx->r13 | 0XA0;
    // 0x800A5C38: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A5C3C: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5C40: nop

    // 0x800A5C44: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5C48: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800A5C4C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x800A5C50: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5C54: lui         $t9, 0x386
    ctx->r25 = S32(0X386 << 16);
    // 0x800A5C58: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800A5C5C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5C60: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800A5C64: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800A5C68: addiu       $t1, $t1, -0x7268
    ctx->r9 = ADD32(ctx->r9, -0X7268);
    // 0x800A5C6C: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x800A5C70: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A5C74: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5C78: nop

    // 0x800A5C7C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A5C80: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A5C84: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
    // 0x800A5C88: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800A5C8C: lui         $t6, 0x388
    ctx->r14 = S32(0X388 << 16);
    // 0x800A5C90: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x800A5C94: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A5C98: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A5C9C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800A5CA0: addiu       $t8, $t8, -0x7268
    ctx->r24 = ADD32(ctx->r24, -0X7268);
    // 0x800A5CA4: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800A5CA8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A5CAC: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5CB0: nop

    // 0x800A5CB4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A5CB8: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800A5CBC: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x800A5CC0: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800A5CC4: lui         $t3, 0x38A
    ctx->r11 = S32(0X38A << 16);
    // 0x800A5CC8: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x800A5CCC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A5CD0: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800A5CD4: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800A5CD8: addiu       $t5, $t5, -0x7268
    ctx->r13 = ADD32(ctx->r13, -0X7268);
    // 0x800A5CDC: addiu       $t6, $t5, 0x30
    ctx->r14 = ADD32(ctx->r13, 0X30);
    // 0x800A5CE0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A5CE4: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5CE8: nop

    // 0x800A5CEC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A5CF0: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x800A5CF4: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x800A5CF8: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800A5CFC: lui         $t0, 0x38C
    ctx->r8 = S32(0X38C << 16);
    // 0x800A5D00: ori         $t0, $t0, 0x10
    ctx->r8 = ctx->r8 | 0X10;
    // 0x800A5D04: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A5D08: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800A5D0C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800A5D10: addiu       $t2, $t2, -0x7268
    ctx->r10 = ADD32(ctx->r10, -0X7268);
    // 0x800A5D14: addiu       $t3, $t2, 0x40
    ctx->r11 = ADD32(ctx->r10, 0X40);
    // 0x800A5D18: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A5D1C: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5D20: nop

    // 0x800A5D24: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A5D28: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A5D2C: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x800A5D30: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800A5D34: lui         $t7, 0x38E
    ctx->r15 = S32(0X38E << 16);
    // 0x800A5D38: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800A5D3C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A5D40: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A5D44: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800A5D48: addiu       $t9, $t9, -0x7268
    ctx->r25 = ADD32(ctx->r25, -0X7268);
    // 0x800A5D4C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A5D50: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A5D54: b           L_800A62A8
    // 0x800A5D58: nop

        goto L_800A62A8;
    // 0x800A5D58: nop

L_800A5D5C:
    // 0x800A5D5C: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5D60: nop

    // 0x800A5D64: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A5D68: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    // 0x800A5D6C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x800A5D70: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800A5D74: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x800A5D78: ori         $t4, $t4, 0x2
    ctx->r12 = ctx->r12 | 0X2;
    // 0x800A5D7C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A5D80: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800A5D84: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A5D88: ori         $t6, $t6, 0xC0
    ctx->r14 = ctx->r14 | 0XC0;
    // 0x800A5D8C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A5D90: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5D94: nop

    // 0x800A5D98: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A5D9C: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x800A5DA0: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x800A5DA4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800A5DA8: lui         $t0, 0x386
    ctx->r8 = S32(0X386 << 16);
    // 0x800A5DAC: ori         $t0, $t0, 0x10
    ctx->r8 = ctx->r8 | 0X10;
    // 0x800A5DB0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A5DB4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800A5DB8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800A5DBC: addiu       $t2, $t2, -0x7268
    ctx->r10 = ADD32(ctx->r10, -0X7268);
    // 0x800A5DC0: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800A5DC4: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A5DC8: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5DCC: nop

    // 0x800A5DD0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A5DD4: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A5DD8: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x800A5DDC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800A5DE0: lui         $t7, 0x388
    ctx->r15 = S32(0X388 << 16);
    // 0x800A5DE4: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800A5DE8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A5DEC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A5DF0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800A5DF4: addiu       $t9, $t9, -0x7268
    ctx->r25 = ADD32(ctx->r25, -0X7268);
    // 0x800A5DF8: addiu       $t0, $t9, 0x20
    ctx->r8 = ADD32(ctx->r25, 0X20);
    // 0x800A5DFC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A5E00: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5E04: nop

    // 0x800A5E08: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A5E0C: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    // 0x800A5E10: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x800A5E14: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800A5E18: lui         $t4, 0x38A
    ctx->r12 = S32(0X38A << 16);
    // 0x800A5E1C: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x800A5E20: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A5E24: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A5E28: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800A5E2C: addiu       $t6, $t6, -0x7268
    ctx->r14 = ADD32(ctx->r14, -0X7268);
    // 0x800A5E30: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x800A5E34: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A5E38: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5E3C: nop

    // 0x800A5E40: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A5E44: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A5E48: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x800A5E4C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800A5E50: lui         $t1, 0x38C
    ctx->r9 = S32(0X38C << 16);
    // 0x800A5E54: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x800A5E58: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A5E5C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800A5E60: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800A5E64: addiu       $t3, $t3, -0x7268
    ctx->r11 = ADD32(ctx->r11, -0X7268);
    // 0x800A5E68: addiu       $t4, $t3, 0x40
    ctx->r12 = ADD32(ctx->r11, 0X40);
    // 0x800A5E6C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A5E70: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5E74: nop

    // 0x800A5E78: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A5E7C: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A5E80: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x800A5E84: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800A5E88: lui         $t8, 0x38E
    ctx->r24 = S32(0X38E << 16);
    // 0x800A5E8C: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A5E90: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A5E94: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A5E98: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800A5E9C: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A5EA0: addiu       $t1, $t0, 0x50
    ctx->r9 = ADD32(ctx->r8, 0X50);
    // 0x800A5EA4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A5EA8: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5EAC: nop

    // 0x800A5EB0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5EB4: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A5EB8: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x800A5EBC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800A5EC0: lui         $t5, 0x390
    ctx->r13 = S32(0X390 << 16);
    // 0x800A5EC4: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A5EC8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5ECC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5ED0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800A5ED4: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A5ED8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5EDC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5EE0: b           L_800A62A8
    // 0x800A5EE4: nop

        goto L_800A62A8;
    // 0x800A5EE4: nop

L_800A5EE8:
    // 0x800A5EE8: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5EEC: nop

    // 0x800A5EF0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5EF4: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5EF8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800A5EFC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A5F00: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x800A5F04: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800A5F08: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5F0C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A5F10: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A5F14: ori         $t4, $t4, 0xE0
    ctx->r12 = ctx->r12 | 0XE0;
    // 0x800A5F18: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A5F1C: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5F20: nop

    // 0x800A5F24: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A5F28: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A5F2C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x800A5F30: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800A5F34: lui         $t8, 0x386
    ctx->r24 = S32(0X386 << 16);
    // 0x800A5F38: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A5F3C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A5F40: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A5F44: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800A5F48: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A5F4C: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x800A5F50: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A5F54: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5F58: nop

    // 0x800A5F5C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A5F60: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A5F64: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800A5F68: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A5F6C: lui         $t5, 0x388
    ctx->r13 = S32(0X388 << 16);
    // 0x800A5F70: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A5F74: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A5F78: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A5F7C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800A5F80: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A5F84: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x800A5F88: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A5F8C: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5F90: nop

    // 0x800A5F94: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A5F98: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A5F9C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800A5FA0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A5FA4: lui         $t2, 0x38A
    ctx->r10 = S32(0X38A << 16);
    // 0x800A5FA8: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x800A5FAC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A5FB0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A5FB4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800A5FB8: addiu       $t4, $t4, -0x7268
    ctx->r12 = ADD32(ctx->r12, -0X7268);
    // 0x800A5FBC: addiu       $t5, $t4, 0x30
    ctx->r13 = ADD32(ctx->r12, 0X30);
    // 0x800A5FC0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A5FC4: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800A5FC8: nop

    // 0x800A5FCC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A5FD0: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800A5FD4: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800A5FD8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A5FDC: lui         $t9, 0x38C
    ctx->r25 = S32(0X38C << 16);
    // 0x800A5FE0: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800A5FE4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5FE8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800A5FEC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800A5FF0: addiu       $t1, $t1, -0x7268
    ctx->r9 = ADD32(ctx->r9, -0X7268);
    // 0x800A5FF4: addiu       $t2, $t1, 0x40
    ctx->r10 = ADD32(ctx->r9, 0X40);
    // 0x800A5FF8: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A5FFC: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6000: nop

    // 0x800A6004: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A6008: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A600C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800A6010: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A6014: lui         $t6, 0x38E
    ctx->r14 = S32(0X38E << 16);
    // 0x800A6018: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x800A601C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800A6020: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A6024: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800A6028: addiu       $t8, $t8, -0x7268
    ctx->r24 = ADD32(ctx->r24, -0X7268);
    // 0x800A602C: addiu       $t9, $t8, 0x50
    ctx->r25 = ADD32(ctx->r24, 0X50);
    // 0x800A6030: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A6034: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6038: nop

    // 0x800A603C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A6040: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800A6044: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800A6048: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800A604C: lui         $t3, 0x390
    ctx->r11 = S32(0X390 << 16);
    // 0x800A6050: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x800A6054: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A6058: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800A605C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800A6060: addiu       $t5, $t5, -0x7268
    ctx->r13 = ADD32(ctx->r13, -0X7268);
    // 0x800A6064: addiu       $t6, $t5, 0x60
    ctx->r14 = ADD32(ctx->r13, 0X60);
    // 0x800A6068: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A606C: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6070: nop

    // 0x800A6074: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A6078: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x800A607C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800A6080: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A6084: lui         $t0, 0x392
    ctx->r8 = S32(0X392 << 16);
    // 0x800A6088: ori         $t0, $t0, 0x10
    ctx->r8 = ctx->r8 | 0X10;
    // 0x800A608C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A6090: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800A6094: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A6098: addiu       $t2, $t2, -0x7268
    ctx->r10 = ADD32(ctx->r10, -0X7268);
    // 0x800A609C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A60A0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A60A4: b           L_800A62A8
    // 0x800A60A8: nop

        goto L_800A62A8;
    // 0x800A60A8: nop

L_800A60AC:
    // 0x800A60AC: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A60B0: nop

    // 0x800A60B4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A60B8: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A60BC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800A60C0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800A60C4: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x800A60C8: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800A60CC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A60D0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800A60D4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800A60D8: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x800A60DC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A60E0: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x800A60E4: nop

    // 0x800A60E8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A60EC: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800A60F0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800A60F4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800A60F8: lui         $t3, 0x386
    ctx->r11 = S32(0X386 << 16);
    // 0x800A60FC: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x800A6100: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A6104: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800A6108: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A610C: addiu       $t5, $t5, -0x7268
    ctx->r13 = ADD32(ctx->r13, -0X7268);
    // 0x800A6110: addiu       $t6, $t5, 0x10
    ctx->r14 = ADD32(ctx->r13, 0X10);
    // 0x800A6114: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A6118: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A611C: nop

    // 0x800A6120: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A6124: sw          $t9, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r25;
    // 0x800A6128: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800A612C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800A6130: lui         $t0, 0x388
    ctx->r8 = S32(0X388 << 16);
    // 0x800A6134: ori         $t0, $t0, 0x10
    ctx->r8 = ctx->r8 | 0X10;
    // 0x800A6138: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A613C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800A6140: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800A6144: addiu       $t2, $t2, -0x7268
    ctx->r10 = ADD32(ctx->r10, -0X7268);
    // 0x800A6148: addiu       $t3, $t2, 0x20
    ctx->r11 = ADD32(ctx->r10, 0X20);
    // 0x800A614C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A6150: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6154: nop

    // 0x800A6158: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A615C: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800A6160: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800A6164: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A6168: lui         $t7, 0x38A
    ctx->r15 = S32(0X38A << 16);
    // 0x800A616C: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800A6170: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A6174: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800A6178: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800A617C: addiu       $t9, $t9, -0x7268
    ctx->r25 = ADD32(ctx->r25, -0X7268);
    // 0x800A6180: addiu       $t0, $t9, 0x30
    ctx->r8 = ADD32(ctx->r25, 0X30);
    // 0x800A6184: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800A6188: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800A618C: nop

    // 0x800A6190: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800A6194: sw          $t3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r11;
    // 0x800A6198: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A619C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800A61A0: lui         $t4, 0x38C
    ctx->r12 = S32(0X38C << 16);
    // 0x800A61A4: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x800A61A8: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A61AC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A61B0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A61B4: addiu       $t6, $t6, -0x7268
    ctx->r14 = ADD32(ctx->r14, -0X7268);
    // 0x800A61B8: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x800A61BC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A61C0: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800A61C4: nop

    // 0x800A61C8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A61CC: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A61D0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A61D4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800A61D8: lui         $t1, 0x38E
    ctx->r9 = S32(0X38E << 16);
    // 0x800A61DC: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x800A61E0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A61E4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800A61E8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A61EC: addiu       $t3, $t3, -0x7268
    ctx->r11 = ADD32(ctx->r11, -0X7268);
    // 0x800A61F0: addiu       $t4, $t3, 0x50
    ctx->r12 = ADD32(ctx->r11, 0X50);
    // 0x800A61F4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800A61F8: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800A61FC: nop

    // 0x800A6200: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A6204: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x800A6208: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A620C: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800A6210: lui         $t8, 0x390
    ctx->r24 = S32(0X390 << 16);
    // 0x800A6214: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800A6218: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A621C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A6220: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800A6224: addiu       $t0, $t0, -0x7268
    ctx->r8 = ADD32(ctx->r8, -0X7268);
    // 0x800A6228: addiu       $t1, $t0, 0x60
    ctx->r9 = ADD32(ctx->r8, 0X60);
    // 0x800A622C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800A6230: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6234: nop

    // 0x800A6238: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A623C: sw          $t4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r12;
    // 0x800A6240: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A6244: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800A6248: lui         $t5, 0x392
    ctx->r13 = S32(0X392 << 16);
    // 0x800A624C: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x800A6250: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A6254: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A6258: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x800A625C: addiu       $t7, $t7, -0x7268
    ctx->r15 = ADD32(ctx->r15, -0X7268);
    // 0x800A6260: addiu       $t8, $t7, 0x70
    ctx->r24 = ADD32(ctx->r15, 0X70);
    // 0x800A6264: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800A6268: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800A626C: nop

    // 0x800A6270: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A6274: sw          $t1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r9;
    // 0x800A6278: sw          $t0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r8;
    // 0x800A627C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800A6280: lui         $t2, 0x394
    ctx->r10 = S32(0X394 << 16);
    // 0x800A6284: ori         $t2, $t2, 0x10
    ctx->r10 = ctx->r10 | 0X10;
    // 0x800A6288: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800A628C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A6290: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800A6294: addiu       $t4, $t4, -0x7268
    ctx->r12 = ADD32(ctx->r12, -0X7268);
    // 0x800A6298: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800A629C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A62A0: b           L_800A62A8
    // 0x800A62A4: nop

        goto L_800A62A8;
    // 0x800A62A4: nop

L_800A62A8:
    // 0x800A62A8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A62AC: lw          $t7, -0x71D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71D0);
    // 0x800A62B0: nop

    // 0x800A62B4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800A62B8: beq         $t8, $zero, L_800A63F0
    if (ctx->r24 == 0) {
        // 0x800A62BC: nop

            goto L_800A63F0;
    }
    // 0x800A62BC: nop

    // 0x800A62C0: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800A62C4: nop

    // 0x800A62C8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A62CC: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A62D0: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800A62D4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800A62D8: lui         $t1, 0xBC00
    ctx->r9 = S32(0XBC00 << 16);
    // 0x800A62DC: ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
    // 0x800A62E0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A62E4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800A62E8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A62EC: lw          $t4, -0x71E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X71E8);
    // 0x800A62F0: lw          $t3, -0x71E4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X71E4);
    // 0x800A62F4: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800A62F8: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800A62FC: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800A6300: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x800A6304: negu        $t0, $t4
    ctx->r8 = SUB32(0, ctx->r12);
    // 0x800A6308: bne         $t5, $zero, L_800A6314
    if (ctx->r13 != 0) {
        // 0x800A630C: nop

            goto L_800A6314;
    }
    // 0x800A630C: nop

    // 0x800A6310: break       7
    do_break(2148164368);
L_800A6314:
    // 0x800A6314: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A6318: bne         $t5, $at, L_800A632C
    if (ctx->r13 != ctx->r1) {
        // 0x800A631C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A632C;
    }
    // 0x800A631C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A6320: bne         $t6, $at, L_800A632C
    if (ctx->r14 != ctx->r1) {
        // 0x800A6324: nop

            goto L_800A632C;
    }
    // 0x800A6324: nop

    // 0x800A6328: break       6
    do_break(2148164392);
L_800A632C:
    // 0x800A632C: addu        $at, $t6, $zero
    ctx->r1 = ADD32(ctx->r14, 0);
    // 0x800A6330: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800A6334: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800A6338: mflo        $t7
    ctx->r15 = lo;
    // 0x800A633C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800A6340: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800A6344: div         $zero, $t2, $t5
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r13)));
    // 0x800A6348: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800A634C: bne         $t5, $zero, L_800A6358
    if (ctx->r13 != 0) {
        // 0x800A6350: nop

            goto L_800A6358;
    }
    // 0x800A6350: nop

    // 0x800A6354: break       7
    do_break(2148164436);
L_800A6358:
    // 0x800A6358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A635C: bne         $t5, $at, L_800A6370
    if (ctx->r13 != ctx->r1) {
        // 0x800A6360: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A6370;
    }
    // 0x800A6360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A6364: bne         $t2, $at, L_800A6370
    if (ctx->r10 != ctx->r1) {
        // 0x800A6368: nop

            goto L_800A6370;
    }
    // 0x800A6368: nop

    // 0x800A636C: break       6
    do_break(2148164460);
L_800A6370:
    // 0x800A6370: mflo        $t3
    ctx->r11 = lo;
    // 0x800A6374: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800A6378: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800A637C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A6380: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6384: nop

    // 0x800A6388: addiu       $t0, $t4, 0x8
    ctx->r8 = ADD32(ctx->r12, 0X8);
    // 0x800A638C: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A6390: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800A6394: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800A6398: lui         $t1, 0xF800
    ctx->r9 = S32(0XF800 << 16);
    // 0x800A639C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A63A0: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800A63A4: lw          $t5, -0x71E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X71E0);
    // 0x800A63A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A63AC: lw          $t6, -0x71DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71DC);
    // 0x800A63B0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A63B4: andi        $t3, $t5, 0xFF
    ctx->r11 = ctx->r13 & 0XFF;
    // 0x800A63B8: lw          $t0, -0x71D8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X71D8);
    // 0x800A63BC: sll         $t9, $t3, 24
    ctx->r25 = S32(ctx->r11 << 24);
    // 0x800A63C0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A63C4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800A63C8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800A63CC: lw          $t3, -0x71D4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X71D4);
    // 0x800A63D0: or          $t4, $t9, $t8
    ctx->r12 = ctx->r25 | ctx->r24;
    // 0x800A63D4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800A63D8: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800A63DC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800A63E0: or          $t5, $t4, $t2
    ctx->r13 = ctx->r12 | ctx->r10;
    // 0x800A63E4: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x800A63E8: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800A63EC: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
L_800A63F0:
    // 0x800A63F0: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800A63F4: nop

    // 0x800A63F8: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x800A63FC: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    // 0x800A6400: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x800A6404: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800A6408: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x800A640C: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800A6410: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800A6414: nop

    // 0x800A6418: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800A641C: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x800A6420: nop

    // 0x800A6424: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800A6428: b           L_800A6438
    // 0x800A642C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A6438;
    // 0x800A642C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A6430: b           L_800A6438
    // 0x800A6434: nop

        goto L_800A6438;
    // 0x800A6434: nop

L_800A6438:
    // 0x800A6438: jr          $ra
    // 0x800A643C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800A643C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_800A6440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A6444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6448: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800A644C:
    // 0x800A644C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6450: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A6454: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A6458: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A645C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A6460: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A6464: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800A6468: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A646C: sw          $zero, 0x7400($at)
    MEM_W(0X7400, ctx->r1) = 0;
    // 0x800A6470: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6474: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A6478: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A647C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800A6480: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6484: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800A6488: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800A648C: addiu       $t0, $t0, 0x7340
    ctx->r8 = ADD32(ctx->r8, 0X7340);
    // 0x800A6490: jal         0x80099E2C
    // 0x800A6494: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x800A6494: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_0:
    // 0x800A6498: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A649C: nop

    // 0x800A64A0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800A64A4: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x800A64A8: bne         $at, $zero, L_800A644C
    if (ctx->r1 != 0) {
        // 0x800A64AC: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_800A644C;
    }
    // 0x800A64AC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A64B0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A64B4: addiu       $t3, $t3, 0x7340
    ctx->r11 = ADD32(ctx->r11, 0X7340);
    // 0x800A64B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A64BC: sw          $t3, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = ctx->r11;
    // 0x800A64C0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A64C4: addiu       $t4, $t4, 0x7340
    ctx->r12 = ADD32(ctx->r12, 0X7340);
    // 0x800A64C8: addiu       $t5, $t4, 0x580
    ctx->r13 = ADD32(ctx->r12, 0X580);
    // 0x800A64CC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A64D0: sw          $t5, -0x73DC($at)
    MEM_W(-0X73DC, ctx->r1) = ctx->r13;
    // 0x800A64D4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A64D8: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x800A64DC: addiu       $t7, $t6, 0xB00
    ctx->r15 = ADD32(ctx->r14, 0XB00);
    // 0x800A64E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A64E4: sw          $t7, -0x73D0($at)
    MEM_W(-0X73D0, ctx->r1) = ctx->r15;
    // 0x800A64E8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A64EC: addiu       $t8, $t8, 0x7340
    ctx->r24 = ADD32(ctx->r24, 0X7340);
    // 0x800A64F0: addiu       $t9, $t8, 0x1080
    ctx->r25 = ADD32(ctx->r24, 0X1080);
    // 0x800A64F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A64F8: sw          $t9, -0x73C4($at)
    MEM_W(-0X73C4, ctx->r1) = ctx->r25;
    // 0x800A64FC: b           L_800A6504
    // 0x800A6500: nop

        goto L_800A6504;
    // 0x800A6500: nop

L_800A6504:
    // 0x800A6504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A650C: jr          $ra
    // 0x800A6510: nop

    return;
    // 0x800A6510: nop

;}
RECOMP_FUNC void func_800A6514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6514: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A6518: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A651C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A6520: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A6524: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A6528: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A652C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800A6530: jal         0x80099E2C
    // 0x800A6534: nop

    func_80099E2C(rdram, ctx);
        goto after_0;
    // 0x800A6534: nop

    after_0:
    // 0x800A6538: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800A653C: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A6540: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800A6544: nop

    // 0x800A6548: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800A654C: sw          $t8, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r24;
    // 0x800A6550: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A6554: nop

    // 0x800A6558: sw          $zero, 0x128($t9)
    MEM_W(0X128, ctx->r25) = 0;
    // 0x800A655C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A6560: nop

    // 0x800A6564: sw          $zero, 0x138($t0)
    MEM_W(0X138, ctx->r8) = 0;
    // 0x800A6568: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A656C: nop

    // 0x800A6570: sw          $zero, 0x13C($t1)
    MEM_W(0X13C, ctx->r9) = 0;
    // 0x800A6574: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A6578: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A657C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A6580: nop

    // 0x800A6584: swc1        $f4, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f4.u32l;
    // 0x800A6588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A658C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6590: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800A6594: nop

    // 0x800A6598: swc1        $f6, 0xF8($t3)
    MEM_W(0XF8, ctx->r11) = ctx->f6.u32l;
    // 0x800A659C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A65A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A65A4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A65A8: nop

    // 0x800A65AC: swc1        $f8, 0xFC($t4)
    MEM_W(0XFC, ctx->r12) = ctx->f8.u32l;
    // 0x800A65B0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A65B4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A65B8: sh          $t5, 0x11E($t7)
    MEM_H(0X11E, ctx->r15) = ctx->r13;
    // 0x800A65BC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800A65C0: nop

    // 0x800A65C4: sh          $zero, 0x11C($t8)
    MEM_H(0X11C, ctx->r24) = 0;
    // 0x800A65C8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800A65CC: nop

    // 0x800A65D0: lh          $s0, 0x11C($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X11C);
    // 0x800A65D4: nop

    // 0x800A65D8: sh          $s0, 0x11A($t6)
    MEM_H(0X11A, ctx->r14) = ctx->r16;
    // 0x800A65DC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A65E0: nop

    // 0x800A65E4: sh          $s0, 0x118($t9)
    MEM_H(0X118, ctx->r25) = ctx->r16;
    // 0x800A65E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A65EC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A65F0: nop

    // 0x800A65F4: swc1        $f10, 0xD4($t0)
    MEM_W(0XD4, ctx->r8) = ctx->f10.u32l;
    // 0x800A65F8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A65FC: nop

    // 0x800A6600: lwc1        $f20, 0xD4($t1)
    ctx->f20.u32l = MEM_W(ctx->r9, 0XD4);
    // 0x800A6604: nop

    // 0x800A6608: swc1        $f20, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f20.u32l;
    // 0x800A660C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A6610: nop

    // 0x800A6614: swc1        $f20, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f20.u32l;
    // 0x800A6618: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A661C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800A6620: nop

    // 0x800A6624: swc1        $f16, 0xF0($t3)
    MEM_W(0XF0, ctx->r11) = ctx->f16.u32l;
    // 0x800A6628: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A662C: nop

    // 0x800A6630: lwc1        $f20, 0xF0($t4)
    ctx->f20.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x800A6634: nop

    // 0x800A6638: swc1        $f20, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f20.u32l;
    // 0x800A663C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800A6640: nop

    // 0x800A6644: swc1        $f20, 0xE8($t5)
    MEM_W(0XE8, ctx->r13) = ctx->f20.u32l;
    // 0x800A6648: b           L_800A6658
    // 0x800A664C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A6658;
    // 0x800A664C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A6650: b           L_800A6658
    // 0x800A6654: nop

        goto L_800A6658;
    // 0x800A6654: nop

L_800A6658:
    // 0x800A6658: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A665C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A6660: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A6664: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A6668: jr          $ra
    // 0x800A666C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A666C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800A6670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6670: bne         $a0, $zero, L_800A6684
    if (ctx->r4 != 0) {
        // 0x800A6674: nop

            goto L_800A6684;
    }
    // 0x800A6674: nop

    // 0x800A6678: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A667C: b           L_800A66D4
    // 0x800A6680: sw          $a1, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = ctx->r5;
        goto L_800A66D4;
    // 0x800A6680: sw          $a1, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = ctx->r5;
L_800A6684:
    // 0x800A6684: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A6688: bne         $a0, $at, L_800A669C
    if (ctx->r4 != ctx->r1) {
        // 0x800A668C: nop

            goto L_800A669C;
    }
    // 0x800A668C: nop

    // 0x800A6690: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A6694: b           L_800A66D4
    // 0x800A6698: sw          $a1, -0x73DC($at)
    MEM_W(-0X73DC, ctx->r1) = ctx->r5;
        goto L_800A66D4;
    // 0x800A6698: sw          $a1, -0x73DC($at)
    MEM_W(-0X73DC, ctx->r1) = ctx->r5;
L_800A669C:
    // 0x800A669C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A66A0: bne         $a0, $at, L_800A66B4
    if (ctx->r4 != ctx->r1) {
        // 0x800A66A4: nop

            goto L_800A66B4;
    }
    // 0x800A66A4: nop

    // 0x800A66A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A66AC: b           L_800A66D4
    // 0x800A66B0: sw          $a1, -0x73D0($at)
    MEM_W(-0X73D0, ctx->r1) = ctx->r5;
        goto L_800A66D4;
    // 0x800A66B0: sw          $a1, -0x73D0($at)
    MEM_W(-0X73D0, ctx->r1) = ctx->r5;
L_800A66B4:
    // 0x800A66B4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800A66B8: bne         $a0, $at, L_800A66CC
    if (ctx->r4 != ctx->r1) {
        // 0x800A66BC: nop

            goto L_800A66CC;
    }
    // 0x800A66BC: nop

    // 0x800A66C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800A66C4: b           L_800A66D4
    // 0x800A66C8: sw          $a1, -0x73C4($at)
    MEM_W(-0X73C4, ctx->r1) = ctx->r5;
        goto L_800A66D4;
    // 0x800A66C8: sw          $a1, -0x73C4($at)
    MEM_W(-0X73C4, ctx->r1) = ctx->r5;
L_800A66CC:
    // 0x800A66CC: jr          $ra
    // 0x800A66D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800A66D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A66D4:
    // 0x800A66D4: jr          $ra
    // 0x800A66D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A66D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800A66DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A66DC: jr          $ra
    // 0x800A66E0: nop

    return;
    // 0x800A66E0: nop

    // 0x800A66E4: jr          $ra
    // 0x800A66E8: nop

    return;
    // 0x800A66E8: nop

;}
RECOMP_FUNC void func_800A66EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A66EC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A66F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A66F4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800A66F8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800A66FC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800A6700: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800A6704: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A6708: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A670C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800A6710: nop

    // 0x800A6714: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800A6718: nop

    // 0x800A671C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x800A6720: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800A6724: nop

    // 0x800A6728: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800A672C: jal         0x800BC6EC
    // 0x800A6730: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x800A6730: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x800A6734: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800A6738: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A673C: nop

    // 0x800A6740: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A6744: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A6748: nop

    // 0x800A674C: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800A6750: beq         $at, $zero, L_800A6788
    if (ctx->r1 == 0) {
        // 0x800A6754: nop

            goto L_800A6788;
    }
    // 0x800A6754: nop

    // 0x800A6758: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800A675C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800A6760: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800A6764: lw          $t3, 0x193C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X193C);
    // 0x800A6768: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800A676C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800A6770: sll         $t4, $a2, 1
    ctx->r12 = S32(ctx->r6 << 1);
    // 0x800A6774: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800A6778: jal         0x800BD218
    // 0x800A677C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x800A677C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x800A6780: b           L_800A67B0
    // 0x800A6784: nop

        goto L_800A67B0;
    // 0x800A6784: nop

L_800A6788:
    // 0x800A6788: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800A678C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800A6790: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800A6794: lw          $t7, 0x3DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3DB0);
    // 0x800A6798: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800A679C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800A67A0: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800A67A4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800A67A8: jal         0x800BD218
    // 0x800A67AC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x800A67AC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_2:
L_800A67B0:
    // 0x800A67B0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A67B4: nop

    // 0x800A67B8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800A67BC: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x800A67C0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800A67C4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800A67C8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800A67CC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800A67D0: blez        $t2, L_800A6EF8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800A67D4: nop

            goto L_800A6EF8;
    }
    // 0x800A67D4: nop

L_800A67D8:
    // 0x800A67D8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800A67DC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800A67E0: nop

    // 0x800A67E4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A67E8: slti        $at, $t5, 0x10
    ctx->r1 = SIGNED(ctx->r13) < 0X10 ? 1 : 0;
    // 0x800A67EC: bne         $at, $zero, L_800A67FC
    if (ctx->r1 != 0) {
        // 0x800A67F0: nop

            goto L_800A67FC;
    }
    // 0x800A67F0: nop

    // 0x800A67F4: b           L_800A6F0C
    // 0x800A67F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A6F0C;
    // 0x800A67F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A67FC:
    // 0x800A67FC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800A6800: nop

    // 0x800A6804: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x800A6808: beq         $at, $zero, L_800A6858
    if (ctx->r1 == 0) {
        // 0x800A680C: nop

            goto L_800A6858;
    }
    // 0x800A680C: nop

    // 0x800A6810: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A6814: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A6818: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A681C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A6820: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A6824: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A6828: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A682C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A6830: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x800A6834: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A6838: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A683C: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800A6840: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A6844: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x800A6848: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800A684C: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800A6850: b           L_800A6960
    // 0x800A6854: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
        goto L_800A6960;
    // 0x800A6854: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
L_800A6858:
    // 0x800A6858: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800A685C: nop

    // 0x800A6860: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x800A6864: beq         $at, $zero, L_800A68B8
    if (ctx->r1 == 0) {
        // 0x800A6868: nop

            goto L_800A68B8;
    }
    // 0x800A6868: nop

    // 0x800A686C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800A6870: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800A6874: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A6878: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800A687C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800A6880: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A6884: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A6888: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800A688C: lw          $t7, -0x73DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73DC);
    // 0x800A6890: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800A6894: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800A6898: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800A689C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800A68A0: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800A68A4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A68A8: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x800A68AC: addiu       $t2, $t9, -0x580
    ctx->r10 = ADD32(ctx->r25, -0X580);
    // 0x800A68B0: b           L_800A6960
    // 0x800A68B4: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
        goto L_800A6960;
    // 0x800A68B4: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_800A68B8:
    // 0x800A68B8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800A68BC: nop

    // 0x800A68C0: slti        $at, $t3, 0xC
    ctx->r1 = SIGNED(ctx->r11) < 0XC ? 1 : 0;
    // 0x800A68C4: beq         $at, $zero, L_800A6918
    if (ctx->r1 == 0) {
        // 0x800A68C8: nop

            goto L_800A6918;
    }
    // 0x800A68C8: nop

    // 0x800A68CC: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800A68D0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800A68D4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800A68D8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800A68DC: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800A68E0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A68E4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800A68E8: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800A68EC: lw          $t6, -0x73D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73D0);
    // 0x800A68F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A68F4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800A68F8: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x800A68FC: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x800A6900: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800A6904: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800A6908: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x800A690C: addiu       $t9, $t1, -0xB00
    ctx->r25 = ADD32(ctx->r9, -0XB00);
    // 0x800A6910: b           L_800A6960
    // 0x800A6914: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
        goto L_800A6960;
    // 0x800A6914: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_800A6918:
    // 0x800A6918: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800A691C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A6920: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A6924: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800A6928: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x800A692C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A6930: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A6934: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x800A6938: lw          $t4, -0x73C4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73C4);
    // 0x800A693C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800A6940: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800A6944: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800A6948: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x800A694C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x800A6950: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A6954: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x800A6958: addiu       $t8, $t7, -0x1080
    ctx->r24 = ADD32(ctx->r15, -0X1080);
    // 0x800A695C: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
L_800A6960:
    // 0x800A6960: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6964: jal         0x800A6514
    // 0x800A6968: nop

    func_800A6514(rdram, ctx);
        goto after_3;
    // 0x800A6968: nop

    after_3:
    // 0x800A696C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A6970: nop

    // 0x800A6974: bne         $t1, $zero, L_800A6CEC
    if (ctx->r9 != 0) {
        // 0x800A6978: nop

            goto L_800A6CEC;
    }
    // 0x800A6978: nop

    // 0x800A697C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A6980: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6984: lhu         $t2, 0x4($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X4);
    // 0x800A6988: nop

    // 0x800A698C: sh          $t2, 0x10C($t3)
    MEM_H(0X10C, ctx->r11) = ctx->r10;
    // 0x800A6990: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A6994: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6998: lhu         $t6, 0x6($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X6);
    // 0x800A699C: nop

    // 0x800A69A0: sh          $t6, 0x10E($t5)
    MEM_H(0X10E, ctx->r13) = ctx->r14;
    // 0x800A69A4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A69A8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800A69AC: lhu         $t7, 0x8($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X8);
    // 0x800A69B0: nop

    // 0x800A69B4: sw          $t7, 0x110($t8)
    MEM_W(0X110, ctx->r24) = ctx->r15;
    // 0x800A69B8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800A69BC: nop

    // 0x800A69C0: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x800A69C4: beq         $at, $zero, L_800A6A3C
    if (ctx->r1 == 0) {
        // 0x800A69C8: nop

            goto L_800A6A3C;
    }
    // 0x800A69C8: nop

    // 0x800A69CC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800A69D0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A69D4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800A69D8: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x800A69DC: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x800A69E0: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x800A69E4: jal         0x800BD1FC
    // 0x800A69E8: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_4;
    // 0x800A69E8: nop

    after_4:
    // 0x800A69EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A69F0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800A69F4: nop

    // 0x800A69F8: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800A69FC: nop

    // 0x800A6A00: beq         $t3, $zero, L_800A6A30
    if (ctx->r11 == 0) {
        // 0x800A6A04: nop

            goto L_800A6A30;
    }
    // 0x800A6A04: nop

    // 0x800A6A08: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800A6A0C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A6A10: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800A6A14: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x800A6A18: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x800A6A1C: lw          $a2, 0x8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X8);
    // 0x800A6A20: jal         0x800BD1FC
    // 0x800A6A24: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x800A6A24: nop

    after_5:
    // 0x800A6A28: b           L_800A6A34
    // 0x800A6A2C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_800A6A34;
    // 0x800A6A2C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_800A6A30:
    // 0x800A6A30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A6A34:
    // 0x800A6A34: b           L_800A6AA4
    // 0x800A6A38: nop

        goto L_800A6AA4;
    // 0x800A6A38: nop

L_800A6A3C:
    // 0x800A6A3C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800A6A40: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A6A44: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800A6A48: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800A6A4C: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800A6A50: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x800A6A54: jal         0x800BD1FC
    // 0x800A6A58: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_6;
    // 0x800A6A58: nop

    after_6:
    // 0x800A6A5C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A6A60: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800A6A64: nop

    // 0x800A6A68: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x800A6A6C: nop

    // 0x800A6A70: beq         $t0, $zero, L_800A6AA0
    if (ctx->r8 == 0) {
        // 0x800A6A74: nop

            goto L_800A6AA0;
    }
    // 0x800A6A74: nop

    // 0x800A6A78: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800A6A7C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A6A80: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800A6A84: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800A6A88: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800A6A8C: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    // 0x800A6A90: jal         0x800BD1FC
    // 0x800A6A94: nop

    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_7;
    // 0x800A6A94: nop

    after_7:
    // 0x800A6A98: b           L_800A6AA4
    // 0x800A6A9C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_800A6AA4;
    // 0x800A6A9C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_800A6AA0:
    // 0x800A6AA0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_800A6AA4:
    // 0x800A6AA4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800A6AA8: nop

    // 0x800A6AAC: beq         $t8, $zero, L_800A6BAC
    if (ctx->r24 == 0) {
        // 0x800A6AB0: nop

            goto L_800A6BAC;
    }
    // 0x800A6AB0: nop

    // 0x800A6AB4: jal         0x800BC6EC
    // 0x800A6AB8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_8;
    // 0x800A6AB8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_8:
    // 0x800A6ABC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6AC0: nop

    // 0x800A6AC4: sw          $v0, 0x144($t1)
    MEM_W(0X144, ctx->r9) = ctx->r2;
    // 0x800A6AC8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800A6ACC:
    // 0x800A6ACC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800A6AD0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6AD4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800A6AD8: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800A6ADC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800A6AE0: lw          $a1, 0x144($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X144);
    // 0x800A6AE4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800A6AE8: jal         0x800BD218
    // 0x800A6AEC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    SysMem_DmaCopy(rdram, ctx);
        goto after_9;
    // 0x800A6AEC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_9:
    // 0x800A6AF0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6AF4: nop

    // 0x800A6AF8: lw          $t0, 0x144($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X144);
    // 0x800A6AFC: nop

    // 0x800A6B00: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x800A6B04: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x800A6B08: nop

    // 0x800A6B0C: bne         $t7, $t8, L_800A6B28
    if (ctx->r15 != ctx->r24) {
        // 0x800A6B10: nop

            goto L_800A6B28;
    }
    // 0x800A6B10: nop

    // 0x800A6B14: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800A6B18: bne         $t8, $at, L_800A6B28
    if (ctx->r24 != ctx->r1) {
        // 0x800A6B1C: nop

            goto L_800A6B28;
    }
    // 0x800A6B1C: nop

    // 0x800A6B20: b           L_800A6B3C
    // 0x800A6B24: nop

        goto L_800A6B3C;
    // 0x800A6B24: nop

L_800A6B28:
    // 0x800A6B28: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800A6B2C: nop

    // 0x800A6B30: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x800A6B34: b           L_800A6ACC
    // 0x800A6B38: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
        goto L_800A6ACC;
    // 0x800A6B38: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_800A6B3C:
    // 0x800A6B3C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6B40: nop

    // 0x800A6B44: lw          $a0, 0x144($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X144);
    // 0x800A6B48: jal         0x800BC980
    // 0x800A6B4C: nop

    SysMem_Free(rdram, ctx);
        goto after_10;
    // 0x800A6B4C: nop

    after_10:
    // 0x800A6B50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800A6B54: nop

    // 0x800A6B58: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x800A6B5C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800A6B60: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x800A6B64: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800A6B68: jal         0x800BC6EC
    // 0x800A6B6C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_11;
    // 0x800A6B6C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_11:
    // 0x800A6B70: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6B74: nop

    // 0x800A6B78: sw          $v0, 0x144($t6)
    MEM_W(0X144, ctx->r14) = ctx->r2;
    // 0x800A6B7C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800A6B80: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6B84: sll         $t0, $a2, 3
    ctx->r8 = S32(ctx->r6 << 3);
    // 0x800A6B88: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800A6B8C: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800A6B90: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800A6B94: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A6B98: lw          $a1, 0x144($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X144);
    // 0x800A6B9C: jal         0x800BD218
    // 0x800A6BA0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    SysMem_DmaCopy(rdram, ctx);
        goto after_12;
    // 0x800A6BA0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_12:
    // 0x800A6BA4: b           L_800A6BB8
    // 0x800A6BA8: nop

        goto L_800A6BB8;
    // 0x800A6BA8: nop

L_800A6BAC:
    // 0x800A6BAC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6BB0: nop

    // 0x800A6BB4: sw          $zero, 0x144($t8)
    MEM_W(0X144, ctx->r24) = 0;
L_800A6BB8:
    // 0x800A6BB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A6BBC: jal         0x800BED70
    // 0x800A6BC0: nop

    Spi_GetHeader(rdram, ctx);
        goto after_13;
    // 0x800A6BC0: nop

    after_13:
    // 0x800A6BC4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800A6BC8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800A6BCC: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x800A6BD0: jal         0x800BC6EC
    // 0x800A6BD4: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_14;
    // 0x800A6BD4: nop

    after_14:
    // 0x800A6BD8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6BDC: nop

    // 0x800A6BE0: sw          $v0, 0x128($t1)
    MEM_W(0X128, ctx->r9) = ctx->r2;
    // 0x800A6BE4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6BE8: nop

    // 0x800A6BEC: lw          $t2, 0x128($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X128);
    // 0x800A6BF0: nop

    // 0x800A6BF4: sw          $t2, 0x12C($t9)
    MEM_W(0X12C, ctx->r25) = ctx->r10;
    // 0x800A6BF8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6BFC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A6C00: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800A6C04: lw          $a2, 0x128($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X128);
    // 0x800A6C08: jal         0x800BF0B4
    // 0x800A6C0C: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_15;
    // 0x800A6C0C: nop

    after_15:
    // 0x800A6C10: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800A6C14: nop

    // 0x800A6C18: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800A6C1C: nop

    // 0x800A6C20: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x800A6C24: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800A6C28: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x800A6C2C: jal         0x800BC6EC
    // 0x800A6C30: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_16;
    // 0x800A6C30: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_16:
    // 0x800A6C34: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C38: nop

    // 0x800A6C3C: sw          $v0, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->r2;
    // 0x800A6C40: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800A6C44: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C48: lw          $a2, 0xC($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XC);
    // 0x800A6C4C: lw          $a1, 0x128($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X128);
    // 0x800A6C50: sll         $t1, $a2, 8
    ctx->r9 = S32(ctx->r6 << 8);
    // 0x800A6C54: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800A6C58: jal         0x800AC7F8
    // 0x800A6C5C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800AC7F8(rdram, ctx);
        goto after_17;
    // 0x800A6C5C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_17:
    // 0x800A6C60: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800A6C64: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C68: lw          $t9, 0xC($t2)
    ctx->r25 = MEM_W(ctx->r10, 0XC);
    // 0x800A6C6C: nop

    // 0x800A6C70: sh          $t9, 0x122($t3)
    MEM_H(0X122, ctx->r11) = ctx->r25;
    // 0x800A6C74: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800A6C78: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C7C: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x800A6C80: lw          $t6, 0x128($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X128);
    // 0x800A6C84: sll         $t7, $t0, 8
    ctx->r15 = S32(ctx->r8 << 8);
    // 0x800A6C88: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800A6C8C: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x800A6C90: sw          $t1, 0x128($t4)
    MEM_W(0X128, ctx->r12) = ctx->r9;
    // 0x800A6C94: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A6C98: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6C9C: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x800A6CA0: lw          $t7, 0x128($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X128);
    // 0x800A6CA4: sll         $t3, $t9, 6
    ctx->r11 = S32(ctx->r25 << 6);
    // 0x800A6CA8: sll         $t5, $t3, 5
    ctx->r13 = S32(ctx->r11 << 5);
    // 0x800A6CAC: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x800A6CB0: sw          $t6, 0x140($t0)
    MEM_W(0X140, ctx->r8) = ctx->r14;
    // 0x800A6CB4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800A6CB8: nop

    // 0x800A6CBC: addiu       $t1, $t8, 0xA
    ctx->r9 = ADD32(ctx->r24, 0XA);
    // 0x800A6CC0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800A6CC4: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6CC8: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x800A6CCC: lw          $t2, 0xC0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0XC0);
    // 0x800A6CD0: nop

    // 0x800A6CD4: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800A6CD8: sw          $t9, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r25;
    // 0x800A6CDC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A6CE0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6CE4: b           L_800A6D94
    // 0x800A6CE8: sw          $t3, 0x130($t5)
    MEM_W(0X130, ctx->r13) = ctx->r11;
        goto L_800A6D94;
    // 0x800A6CE8: sw          $t3, 0x130($t5)
    MEM_W(0X130, ctx->r13) = ctx->r11;
L_800A6CEC:
    // 0x800A6CEC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A6CF0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6CF4: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800A6CF8: nop

    // 0x800A6CFC: sh          $t6, 0x10C($t0)
    MEM_H(0X10C, ctx->r8) = ctx->r14;
    // 0x800A6D00: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800A6D04: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D08: lhu         $t1, 0x2($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X2);
    // 0x800A6D0C: nop

    // 0x800A6D10: sh          $t1, 0x10E($t2)
    MEM_H(0X10E, ctx->r10) = ctx->r9;
    // 0x800A6D14: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D18: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D1C: lw          $t4, 0x110($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X110);
    // 0x800A6D20: nop

    // 0x800A6D24: sw          $t4, 0x110($t3)
    MEM_W(0X110, ctx->r11) = ctx->r12;
    // 0x800A6D28: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D2C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D30: lw          $t7, 0x128($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X128);
    // 0x800A6D34: nop

    // 0x800A6D38: sw          $t7, 0x128($t6)
    MEM_W(0X128, ctx->r14) = ctx->r15;
    // 0x800A6D3C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D40: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D44: lw          $t8, 0x138($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X138);
    // 0x800A6D48: nop

    // 0x800A6D4C: sw          $t8, 0x138($t1)
    MEM_W(0X138, ctx->r9) = ctx->r24;
    // 0x800A6D50: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D54: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D58: lh          $t9, 0x122($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X122);
    // 0x800A6D5C: nop

    // 0x800A6D60: sh          $t9, 0x122($t4)
    MEM_H(0X122, ctx->r12) = ctx->r25;
    // 0x800A6D64: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800A6D68: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D6C: lw          $t5, 0x140($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X140);
    // 0x800A6D70: nop

    // 0x800A6D74: sw          $t5, 0x140($t7)
    MEM_W(0X140, ctx->r15) = ctx->r13;
    // 0x800A6D78: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D7C: nop

    // 0x800A6D80: sw          $zero, 0x144($t6)
    MEM_W(0X144, ctx->r14) = 0;
    // 0x800A6D84: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800A6D88: nop

    // 0x800A6D8C: addiu       $t8, $t0, 0x4
    ctx->r24 = ADD32(ctx->r8, 0X4);
    // 0x800A6D90: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800A6D94:
    // 0x800A6D94: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800A6D98: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6D9C: nop

    // 0x800A6DA0: sw          $t1, 0x13C($t2)
    MEM_W(0X13C, ctx->r10) = ctx->r9;
    // 0x800A6DA4: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A6DA8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DAC: nop

    // 0x800A6DB0: sh          $t9, 0x116($t4)
    MEM_H(0X116, ctx->r12) = ctx->r25;
    // 0x800A6DB4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DB8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800A6DBC: sh          $t3, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r11;
    // 0x800A6DC0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DC4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800A6DC8: lw          $t6, 0xC0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC0);
    // 0x800A6DCC: nop

    // 0x800A6DD0: or          $t8, $t6, $t0
    ctx->r24 = ctx->r14 | ctx->r8;
    // 0x800A6DD4: sw          $t8, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r24;
    // 0x800A6DD8: lhu         $t1, 0x6E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X6E);
    // 0x800A6DDC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DE0: nop

    // 0x800A6DE4: sh          $t1, 0xC4($t2)
    MEM_H(0XC4, ctx->r10) = ctx->r9;
    // 0x800A6DE8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800A6DEC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6DF0: nop

    // 0x800A6DF4: sw          $t9, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->r25;
    // 0x800A6DF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A6DFC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E00: nop

    // 0x800A6E04: swc1        $f4, 0xD4($t3)
    MEM_W(0XD4, ctx->r11) = ctx->f4.u32l;
    // 0x800A6E08: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E0C: nop

    // 0x800A6E10: lwc1        $f20, 0xD4($t5)
    ctx->f20.u32l = MEM_W(ctx->r13, 0XD4);
    // 0x800A6E14: nop

    // 0x800A6E18: swc1        $f20, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f20.u32l;
    // 0x800A6E1C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E20: nop

    // 0x800A6E24: swc1        $f20, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f20.u32l;
    // 0x800A6E28: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E2C: nop

    // 0x800A6E30: sw          $zero, 0xE0($t0)
    MEM_W(0XE0, ctx->r8) = 0;
    // 0x800A6E34: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E38: nop

    // 0x800A6E3C: lw          $t7, 0xE0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XE0);
    // 0x800A6E40: nop

    // 0x800A6E44: sw          $t7, 0xDC($t8)
    MEM_W(0XDC, ctx->r24) = ctx->r15;
    // 0x800A6E48: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800A6E4C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E50: nop

    // 0x800A6E54: swc1        $f6, 0xE4($t1)
    MEM_W(0XE4, ctx->r9) = ctx->f6.u32l;
    // 0x800A6E58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A6E5C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E60: nop

    // 0x800A6E64: swc1        $f8, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f8.u32l;
    // 0x800A6E68: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E6C: nop

    // 0x800A6E70: lwc1        $f20, 0xF0($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x800A6E74: nop

    // 0x800A6E78: swc1        $f20, 0xEC($t9)
    MEM_W(0XEC, ctx->r25) = ctx->f20.u32l;
    // 0x800A6E7C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E80: nop

    // 0x800A6E84: swc1        $f20, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f20.u32l;
    // 0x800A6E88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A6E8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A6E90: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6E94: nop

    // 0x800A6E98: swc1        $f10, 0xF8($t3)
    MEM_W(0XF8, ctx->r11) = ctx->f10.u32l;
    // 0x800A6E9C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6EA0: nop

    // 0x800A6EA4: lwc1        $f16, 0xF8($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x800A6EA8: nop

    // 0x800A6EAC: swc1        $f16, 0xF4($t5)
    MEM_W(0XF4, ctx->r13) = ctx->f16.u32l;
    // 0x800A6EB0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6EB4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A6EB8: lh          $t0, 0x10C($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X10C);
    // 0x800A6EBC: lh          $t7, 0x10E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10E);
    // 0x800A6EC0: nop

    // 0x800A6EC4: multu       $t0, $t7
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A6EC8: mflo        $t8
    ctx->r24 = lo;
    // 0x800A6ECC: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x800A6ED0: addu        $t9, $t2, $t1
    ctx->r25 = ADD32(ctx->r10, ctx->r9);
    // 0x800A6ED4: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800A6ED8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800A6EDC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800A6EE0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A6EE4: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800A6EE8: slt         $at, $t3, $t6
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800A6EEC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800A6EF0: bne         $at, $zero, L_800A67D8
    if (ctx->r1 != 0) {
        // 0x800A6EF4: sw          $t5, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r13;
            goto L_800A67D8;
    }
    // 0x800A6EF4: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
L_800A6EF8:
    // 0x800A6EF8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800A6EFC: b           L_800A6F0C
    // 0x800A6F00: nop

        goto L_800A6F0C;
    // 0x800A6F00: nop

    // 0x800A6F04: b           L_800A6F0C
    // 0x800A6F08: nop

        goto L_800A6F0C;
    // 0x800A6F08: nop

L_800A6F0C:
    // 0x800A6F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6F10: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800A6F14: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A6F18: jr          $ra
    // 0x800A6F1C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A6F1C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800A6F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6F20: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800A6F24: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800A6F28: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x800A6F2C: beq         $at, $zero, L_800A6F5C
    if (ctx->r1 == 0) {
        // 0x800A6F30: nop

            goto L_800A6F5C;
    }
    // 0x800A6F30: nop

    // 0x800A6F34: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A6F38: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A6F3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A6F40: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800A6F44: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x800A6F48: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A6F4C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800A6F50: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A6F54: b           L_800A6FF4
    // 0x800A6F58: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
        goto L_800A6FF4;
    // 0x800A6F58: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
L_800A6F5C:
    // 0x800A6F5C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800A6F60: beq         $at, $zero, L_800A6F94
    if (ctx->r1 == 0) {
        // 0x800A6F64: nop

            goto L_800A6F94;
    }
    // 0x800A6F64: nop

    // 0x800A6F68: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800A6F6C: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800A6F70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6F74: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800A6F78: lw          $t0, -0x73DC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73DC);
    // 0x800A6F7C: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800A6F80: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800A6F84: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800A6F88: addiu       $t2, $t1, -0x580
    ctx->r10 = ADD32(ctx->r9, -0X580);
    // 0x800A6F8C: b           L_800A6FF4
    // 0x800A6F90: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
        goto L_800A6FF4;
    // 0x800A6F90: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_800A6F94:
    // 0x800A6F94: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x800A6F98: beq         $at, $zero, L_800A6FCC
    if (ctx->r1 == 0) {
        // 0x800A6F9C: nop

            goto L_800A6FCC;
    }
    // 0x800A6F9C: nop

    // 0x800A6FA0: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x800A6FA4: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800A6FA8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A6FAC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800A6FB0: lw          $t4, -0x73D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73D0);
    // 0x800A6FB4: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800A6FB8: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800A6FBC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A6FC0: addiu       $t6, $t5, -0xB00
    ctx->r14 = ADD32(ctx->r13, -0XB00);
    // 0x800A6FC4: b           L_800A6FF4
    // 0x800A6FC8: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
        goto L_800A6FF4;
    // 0x800A6FC8: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
L_800A6FCC:
    // 0x800A6FCC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A6FD0: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A6FD4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A6FD8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800A6FDC: lw          $t8, -0x73C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73C4);
    // 0x800A6FE0: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A6FE4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800A6FE8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A6FEC: addiu       $t0, $t9, -0x1080
    ctx->r8 = ADD32(ctx->r25, -0X1080);
    // 0x800A6FF0: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
L_800A6FF4:
    // 0x800A6FF4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800A6FF8:
    // 0x800A6FF8: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800A6FFC: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A7000: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x800A7004: nop

    // 0x800A7008: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800A700C: beq         $t3, $zero, L_800A7020
    if (ctx->r11 == 0) {
        // 0x800A7010: nop

            goto L_800A7020;
    }
    // 0x800A7010: nop

    // 0x800A7014: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x800A7018: nop

    // 0x800A701C: sh          $a1, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r5;
L_800A7020:
    // 0x800A7020: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800A7024: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800A7028: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A702C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800A7030: addiu       $t6, $t5, 0x160
    ctx->r14 = ADD32(ctx->r13, 0X160);
    // 0x800A7034: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800A7038: bne         $at, $zero, L_800A6FF8
    if (ctx->r1 != 0) {
        // 0x800A703C: sw          $t8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r24;
            goto L_800A6FF8;
    }
    // 0x800A703C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800A7040: b           L_800A7048
    // 0x800A7044: nop

        goto L_800A7048;
    // 0x800A7044: nop

L_800A7048:
    // 0x800A7048: jr          $ra
    // 0x800A704C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800A704C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800A7050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7050: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800A7054: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x800A7058: bne         $at, $zero, L_800A7068
    if (ctx->r1 != 0) {
        // 0x800A705C: nop

            goto L_800A7068;
    }
    // 0x800A705C: nop

    // 0x800A7060: b           L_800A70D0
    // 0x800A7064: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A70D0;
    // 0x800A7064: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A7068:
    // 0x800A7068: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A706C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A7070: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A7074: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A7078: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A707C: addiu       $t7, $t7, 0x7340
    ctx->r15 = ADD32(ctx->r15, 0X7340);
    // 0x800A7080: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800A7084: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A7088: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800A708C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800A7090: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A7094: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800A7098: nop

    // 0x800A709C: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800A70A0: bne         $t1, $zero, L_800A70B0
    if (ctx->r9 != 0) {
        // 0x800A70A4: nop

            goto L_800A70B0;
    }
    // 0x800A70A4: nop

    // 0x800A70A8: b           L_800A70D0
    // 0x800A70AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A70D0;
    // 0x800A70AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A70B0:
    // 0x800A70B0: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800A70B4: nop

    // 0x800A70B8: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800A70BC: nop

    // 0x800A70C0: or          $t4, $t3, $a1
    ctx->r12 = ctx->r11 | ctx->r5;
    // 0x800A70C4: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
    // 0x800A70C8: b           L_800A70D0
    // 0x800A70CC: nop

        goto L_800A70D0;
    // 0x800A70CC: nop

L_800A70D0:
    // 0x800A70D0: jr          $ra
    // 0x800A70D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800A70D4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800A70D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A70D8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800A70DC: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x800A70E0: bne         $at, $zero, L_800A70F0
    if (ctx->r1 != 0) {
        // 0x800A70E4: nop

            goto L_800A70F0;
    }
    // 0x800A70E4: nop

    // 0x800A70E8: b           L_800A7158
    // 0x800A70EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A7158;
    // 0x800A70EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A70F0:
    // 0x800A70F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A70F4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A70F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A70FC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A7100: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A7104: addiu       $t7, $t7, 0x7340
    ctx->r15 = ADD32(ctx->r15, 0X7340);
    // 0x800A7108: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800A710C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A7110: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800A7114: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800A7118: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A711C: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800A7120: nop

    // 0x800A7124: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800A7128: bne         $t1, $zero, L_800A7138
    if (ctx->r9 != 0) {
        // 0x800A712C: nop

            goto L_800A7138;
    }
    // 0x800A712C: nop

    // 0x800A7130: b           L_800A7158
    // 0x800A7134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A7158;
    // 0x800A7134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A7138:
    // 0x800A7138: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800A713C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7140: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800A7144: xor         $t4, $a1, $at
    ctx->r12 = ctx->r5 ^ ctx->r1;
    // 0x800A7148: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x800A714C: sw          $t5, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r13;
    // 0x800A7150: b           L_800A7158
    // 0x800A7154: nop

        goto L_800A7158;
    // 0x800A7154: nop

L_800A7158:
    // 0x800A7158: jr          $ra
    // 0x800A715C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800A715C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800A7160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7160: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A7164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7168: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A716C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A7170: nop

    // 0x800A7174: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x800A7178: bne         $at, $zero, L_800A7188
    if (ctx->r1 != 0) {
        // 0x800A717C: nop

            goto L_800A7188;
    }
    // 0x800A717C: nop

    // 0x800A7180: b           L_800A7220
    // 0x800A7184: nop

        goto L_800A7220;
    // 0x800A7184: nop

L_800A7188:
    // 0x800A7188: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800A718C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A7190: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A7194: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A7198: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A719C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A71A0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800A71A4: addiu       $t9, $t9, 0x7340
    ctx->r25 = ADD32(ctx->r25, 0X7340);
    // 0x800A71A8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800A71AC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A71B0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A71B4: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A71B8: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x800A71BC: nop

    // 0x800A71C0: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800A71C4: bne         $t3, $zero, L_800A71D4
    if (ctx->r11 != 0) {
        // 0x800A71C8: nop

            goto L_800A71D4;
    }
    // 0x800A71C8: nop

    // 0x800A71CC: b           L_800A7220
    // 0x800A71D0: nop

        goto L_800A7220;
    // 0x800A71D0: nop

L_800A71D4:
    // 0x800A71D4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800A71D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A71DC: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800A71E0: lwc1        $f4, 0xCC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x800A71E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A71E8: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800A71EC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A71F0: lwc1        $f8, 0xD0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x800A71F4: lwc1        $f10, 0xE4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XE4);
    // 0x800A71F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A71FC: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A7200: lwc1        $f4, 0xD4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XD4);
    // 0x800A7204: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A7208: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A720C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800A7210: jal         0x800C2304
    // 0x800A7214: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_0;
    // 0x800A7214: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x800A7218: b           L_800A7220
    // 0x800A721C: nop

        goto L_800A7220;
    // 0x800A721C: nop

L_800A7220:
    // 0x800A7220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7224: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7228: jr          $ra
    // 0x800A722C: nop

    return;
    // 0x800A722C: nop

;}
RECOMP_FUNC void func_800A7230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7238: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A723C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A7240: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A7244: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800A7248: nop

    // 0x800A724C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800A7250: bne         $t8, $zero, L_800A7260
    if (ctx->r24 != 0) {
        // 0x800A7254: nop

            goto L_800A7260;
    }
    // 0x800A7254: nop

    // 0x800A7258: b           L_800A72AC
    // 0x800A725C: nop

        goto L_800A72AC;
    // 0x800A725C: nop

L_800A7260:
    // 0x800A7260: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800A7264: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A7268: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800A726C: lwc1        $f4, 0xCC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800A7270: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A7274: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800A7278: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A727C: lwc1        $f8, 0xD0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x800A7280: lwc1        $f10, 0xE4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XE4);
    // 0x800A7284: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A7288: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A728C: lwc1        $f4, 0xD4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XD4);
    // 0x800A7290: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A7294: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A7298: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800A729C: jal         0x800C2304
    // 0x800A72A0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    MtxUtil_TranslateLocal(rdram, ctx);
        goto after_0;
    // 0x800A72A0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x800A72A4: b           L_800A72AC
    // 0x800A72A8: nop

        goto L_800A72AC;
    // 0x800A72A8: nop

L_800A72AC:
    // 0x800A72AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A72B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A72B4: jr          $ra
    // 0x800A72B8: nop

    return;
    // 0x800A72B8: nop

;}
RECOMP_FUNC void func_800A72BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A72BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A72C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A72C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A72C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A72CC: nop

    // 0x800A72D0: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x800A72D4: bne         $at, $zero, L_800A72E4
    if (ctx->r1 != 0) {
        // 0x800A72D8: nop

            goto L_800A72E4;
    }
    // 0x800A72D8: nop

    // 0x800A72DC: b           L_800A734C
    // 0x800A72E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A734C;
    // 0x800A72E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A72E4:
    // 0x800A72E4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800A72E8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A72EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A72F0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A72F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A72F8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A72FC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800A7300: addiu       $t9, $t9, 0x7340
    ctx->r25 = ADD32(ctx->r25, 0X7340);
    // 0x800A7304: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800A7308: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A730C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7310: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800A7314: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x800A7318: nop

    // 0x800A731C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800A7320: bne         $t3, $zero, L_800A7330
    if (ctx->r11 != 0) {
        // 0x800A7324: nop

            goto L_800A7330;
    }
    // 0x800A7324: nop

    // 0x800A7328: b           L_800A734C
    // 0x800A732C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800A734C;
    // 0x800A732C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A7330:
    // 0x800A7330: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7334: jal         0x800997D8
    // 0x800A7338: nop

    func_800997D8(rdram, ctx);
        goto after_0;
    // 0x800A7338: nop

    after_0:
    // 0x800A733C: b           L_800A734C
    // 0x800A7340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A734C;
    // 0x800A7340: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A7344: b           L_800A734C
    // 0x800A7348: nop

        goto L_800A734C;
    // 0x800A7348: nop

L_800A734C:
    // 0x800A734C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7354: jr          $ra
    // 0x800A7358: nop

    return;
    // 0x800A7358: nop

;}
RECOMP_FUNC void func_800A735C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A735C: addiu       $sp, $sp, -0x1A0
    ctx->r29 = ADD32(ctx->r29, -0X1A0);
    // 0x800A7360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7364: sw          $a0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r4;
    // 0x800A7368: sw          $a1, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r5;
    // 0x800A736C: sw          $a2, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r6;
    // 0x800A7370: lw          $t6, 0x1A0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A0);
    // 0x800A7374: nop

    // 0x800A7378: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800A737C: nop

    // 0x800A7380: sw          $t7, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r15;
    // 0x800A7384: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7388: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A738C: lw          $t0, 0x7250($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7250);
    // 0x800A7390: lw          $t9, 0xC0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC0);
    // 0x800A7394: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A7398: lw          $t2, 0x7258($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7258);
    // 0x800A739C: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800A73A0: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x800A73A4: sw          $t3, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r11;
    // 0x800A73A8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A73AC: sw          $t4, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r12;
    // 0x800A73B0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A73B4: lw          $t6, 0x70E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70E4);
    // 0x800A73B8: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x800A73BC: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800A73C0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800A73C4: sw          $t8, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r24;
    // 0x800A73C8: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A73CC: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x800A73D0: lh          $t0, 0x11E($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X11E);
    // 0x800A73D4: lwc1        $f8, 0xE8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XE8);
    // 0x800A73D8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A73DC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A73E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A73E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A73E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A73EC: nop

    // 0x800A73F0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A73F4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A73F8: nop

    // 0x800A73FC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A7400: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7404: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7408: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A740C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A7410: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800A7414: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A7418: sh          $t3, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r11;
    // 0x800A741C: nop

    // 0x800A7420: lw          $t4, 0x178($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X178);
    // 0x800A7424: nop

    // 0x800A7428: andi        $t6, $t4, 0x40
    ctx->r14 = ctx->r12 & 0X40;
    // 0x800A742C: bne         $t6, $zero, L_800A7470
    if (ctx->r14 != 0) {
        // 0x800A7430: nop

            goto L_800A7470;
    }
    // 0x800A7430: nop

    // 0x800A7434: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7438: nop

    // 0x800A743C: lwc1        $f6, 0xF4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XF4);
    // 0x800A7440: lwc1        $f8, 0xFC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XFC);
    // 0x800A7444: nop

    // 0x800A7448: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A744C: swc1        $f10, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f10.u32l;
    // 0x800A7450: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7454: nop

    // 0x800A7458: lwc1        $f16, 0xF8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XF8);
    // 0x800A745C: lwc1        $f18, 0xFC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x800A7460: nop

    // 0x800A7464: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A7468: b           L_800A74C8
    // 0x800A746C: swc1        $f4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f4.u32l;
        goto L_800A74C8;
    // 0x800A746C: swc1        $f4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f4.u32l;
L_800A7470:
    // 0x800A7470: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7474: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A7478: lwc1        $f6, 0xF4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x800A747C: lwc1        $f8, 0xFC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XFC);
    // 0x800A7480: lwc1        $f16, 0xB8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XB8);
    // 0x800A7484: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A7488: lwc1        $f4, 0x7218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A748C: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800A7490: nop

    // 0x800A7494: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A7498: swc1        $f6, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f6.u32l;
    // 0x800A749C: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A74A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A74A4: lwc1        $f8, 0xF8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x800A74A8: lwc1        $f16, 0xFC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XFC);
    // 0x800A74AC: lwc1        $f18, 0xB8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XB8);
    // 0x800A74B0: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A74B4: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A74B8: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800A74BC: nop

    // 0x800A74C0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A74C4: swc1        $f8, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f8.u32l;
L_800A74C8:
    // 0x800A74C8: jal         0x800C1754
    // 0x800A74CC: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x800A74CC: nop

    after_0:
    // 0x800A74D0: lw          $a0, 0x13C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X13C);
    // 0x800A74D4: jal         0x800C2B20
    // 0x800A74D8: nop

    MtxUtil_SetCurrentFromMtx(rdram, ctx);
        goto after_1;
    // 0x800A74D8: nop

    after_1:
    // 0x800A74DC: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A74E0: jal         0x800C1D44
    // 0x800A74E4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_2;
    // 0x800A74E4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_2:
    // 0x800A74E8: lw          $t0, 0x178($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X178);
    // 0x800A74EC: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x800A74F0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800A74F4: beq         $t1, $zero, L_800A7540
    if (ctx->r9 == 0) {
        // 0x800A74F8: nop

            goto L_800A7540;
    }
    // 0x800A74F8: nop

    // 0x800A74FC: jal         0x800C1680
    // 0x800A7500: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_3;
    // 0x800A7500: nop

    after_3:
    // 0x800A7504: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7508: jal         0x800C1AF4
    // 0x800A750C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_4;
    // 0x800A750C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_4:
    // 0x800A7510: jal         0x800C1908
    // 0x800A7514: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_ClearTranslation(rdram, ctx);
        goto after_5;
    // 0x800A7514: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x800A7518: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A751C: jal         0x800C1A84
    // 0x800A7520: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_6;
    // 0x800A7520: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_6:
    // 0x800A7524: jal         0x800C1A28
    // 0x800A7528: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_7;
    // 0x800A7528: nop

    after_7:
    // 0x800A752C: jal         0x800C197C
    // 0x800A7530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    MtxUtil_ClearRotation(rdram, ctx);
        goto after_8;
    // 0x800A7530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800A7534: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A7538: jal         0x800C1D44
    // 0x800A753C: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    func_800C1D44(rdram, ctx);
        goto after_9;
    // 0x800A753C: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_9:
L_800A7540:
    // 0x800A7540: lwc1        $f12, 0x144($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A7544: lwc1        $f14, 0x140($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A7548: jal         0x800C2948
    // 0x800A754C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    MtxUtil_ScaleAxes(rdram, ctx);
        goto after_10;
    // 0x800A754C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_10:
    // 0x800A7550: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A7554: lw          $t3, 0x70E4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X70E4);
    // 0x800A7558: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A755C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x800A7560: jal         0x800C2AE8
    // 0x800A7564: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_11;
    // 0x800A7564: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    after_11:
    // 0x800A7568: jal         0x800C1A28
    // 0x800A756C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_12;
    // 0x800A756C: nop

    after_12:
    // 0x800A7570: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7574: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A7578: nop

    // 0x800A757C: swc1        $f16, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f16.u32l;
    // 0x800A7580: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7584: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A7588: nop

    // 0x800A758C: swc1        $f18, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f18.u32l;
    // 0x800A7590: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7594: nop

    // 0x800A7598: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x800A759C: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A75A0: sw          $t6, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r14;
    // 0x800A75A4: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x800A75A8: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A75AC: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x800A75B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A75B4: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x800A75B8: nop

    // 0x800A75BC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A75C0: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A75C4: nop

    // 0x800A75C8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A75CC: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A75D0: sw          $t0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r8;
    // 0x800A75D4: lw          $t2, 0x134($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X134);
    // 0x800A75D8: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x800A75DC: ori         $t3, $t3, 0x201
    ctx->r11 = ctx->r11 | 0X201;
    // 0x800A75E0: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A75E4: lw          $t4, 0x134($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X134);
    // 0x800A75E8: nop

    // 0x800A75EC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800A75F0: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A75F4: nop

    // 0x800A75F8: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x800A75FC: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A7600: sw          $t6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r14;
    // 0x800A7604: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x800A7608: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x800A760C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A7610: lw          $t0, 0x130($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X130);
    // 0x800A7614: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800A7618: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A761C: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7620: nop

    // 0x800A7624: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A7628: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A762C: sw          $t1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r9;
    // 0x800A7630: lw          $t4, 0x12C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X12C);
    // 0x800A7634: lui         $t2, 0x106
    ctx->r10 = S32(0X106 << 16);
    // 0x800A7638: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x800A763C: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800A7640: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A7644: lw          $t5, 0x70E4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70E4);
    // 0x800A7648: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A764C: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A7650: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x800A7654: lw          $t0, 0x12C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X12C);
    // 0x800A7658: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A765C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A7660: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800A7664: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A7668: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A766C: nop

    // 0x800A7670: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A7674: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A7678: sw          $t1, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r9;
    // 0x800A767C: lw          $t4, 0x128($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X128);
    // 0x800A7680: lui         $t2, 0xBB00
    ctx->r10 = S32(0XBB00 << 16);
    // 0x800A7684: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x800A7688: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800A768C: lw          $t6, 0x128($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X128);
    // 0x800A7690: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800A7694: ori         $t5, $t5, 0x8000
    ctx->r13 = ctx->r13 | 0X8000;
    // 0x800A7698: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A769C: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x800A76A0: nop

    // 0x800A76A4: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x800A76A8: beq         $t8, $zero, L_800A7720
    if (ctx->r24 == 0) {
        // 0x800A76AC: nop

            goto L_800A7720;
    }
    // 0x800A76AC: nop

    // 0x800A76B0: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A76B4: nop

    // 0x800A76B8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A76BC: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A76C0: sw          $t9, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r25;
    // 0x800A76C4: lw          $t3, 0x124($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X124);
    // 0x800A76C8: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x800A76CC: ori         $t1, $t1, 0xFE24
    ctx->r9 = ctx->r9 | 0XFE24;
    // 0x800A76D0: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A76D4: lw          $t4, 0x124($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X124);
    // 0x800A76D8: lui         $t2, 0xFF30
    ctx->r10 = S32(0XFF30 << 16);
    // 0x800A76DC: ori         $t2, $t2, 0xF3FF
    ctx->r10 = ctx->r10 | 0XF3FF;
    // 0x800A76E0: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800A76E4: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A76E8: nop

    // 0x800A76EC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A76F0: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A76F4: sw          $t5, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r13;
    // 0x800A76F8: lw          $t8, 0x120($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X120);
    // 0x800A76FC: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x800A7700: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x800A7704: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A7708: lw          $t0, 0x120($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X120);
    // 0x800A770C: lui         $t9, 0xF0A
    ctx->r25 = S32(0XF0A << 16);
    // 0x800A7710: ori         $t9, $t9, 0x233
    ctx->r25 = ctx->r25 | 0X233;
    // 0x800A7714: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A7718: b           L_800A780C
    // 0x800A771C: nop

        goto L_800A780C;
    // 0x800A771C: nop

L_800A7720:
    // 0x800A7720: lw          $t1, 0x178($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X178);
    // 0x800A7724: nop

    // 0x800A7728: andi        $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 & 0X8000;
    // 0x800A772C: beq         $t3, $zero, L_800A77A4
    if (ctx->r11 == 0) {
        // 0x800A7730: nop

            goto L_800A77A4;
    }
    // 0x800A7730: nop

    // 0x800A7734: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7738: nop

    // 0x800A773C: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x800A7740: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A7744: sw          $t2, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r10;
    // 0x800A7748: lw          $t6, 0x11C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X11C);
    // 0x800A774C: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x800A7750: ori         $t5, $t5, 0xFE24
    ctx->r13 = ctx->r13 | 0XFE24;
    // 0x800A7754: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A7758: lw          $t8, 0x11C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X11C);
    // 0x800A775C: lui         $t7, 0xFF30
    ctx->r15 = S32(0XFF30 << 16);
    // 0x800A7760: ori         $t7, $t7, 0xF3FF
    ctx->r15 = ctx->r15 | 0XF3FF;
    // 0x800A7764: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A7768: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A776C: nop

    // 0x800A7770: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A7774: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A7778: sw          $t9, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r25;
    // 0x800A777C: lw          $t3, 0x118($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X118);
    // 0x800A7780: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x800A7784: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x800A7788: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A778C: lw          $t4, 0x118($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X118);
    // 0x800A7790: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x800A7794: ori         $t2, $t2, 0x4A50
    ctx->r10 = ctx->r10 | 0X4A50;
    // 0x800A7798: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800A779C: b           L_800A780C
    // 0x800A77A0: nop

        goto L_800A780C;
    // 0x800A77A0: nop

L_800A77A4:
    // 0x800A77A4: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A77A8: nop

    // 0x800A77AC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A77B0: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A77B4: sw          $t5, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r13;
    // 0x800A77B8: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x800A77BC: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x800A77C0: ori         $t7, $t7, 0xFE24
    ctx->r15 = ctx->r15 | 0XFE24;
    // 0x800A77C4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A77C8: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800A77CC: lui         $t9, 0xFF30
    ctx->r25 = S32(0XFF30 << 16);
    // 0x800A77D0: ori         $t9, $t9, 0xF3FF
    ctx->r25 = ctx->r25 | 0XF3FF;
    // 0x800A77D4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A77D8: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A77DC: nop

    // 0x800A77E0: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A77E4: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A77E8: sw          $t1, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r9;
    // 0x800A77EC: lw          $t4, 0x110($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X110);
    // 0x800A77F0: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x800A77F4: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x800A77F8: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800A77FC: lw          $t6, 0x110($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X110);
    // 0x800A7800: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x800A7804: ori         $t5, $t5, 0x3078
    ctx->r13 = ctx->r13 | 0X3078;
    // 0x800A7808: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
L_800A780C:
    // 0x800A780C: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x800A7810: nop

    // 0x800A7814: andi        $t8, $t7, 0x800
    ctx->r24 = ctx->r15 & 0X800;
    // 0x800A7818: bne         $t8, $zero, L_800A7854
    if (ctx->r24 != 0) {
        // 0x800A781C: nop

            goto L_800A7854;
    }
    // 0x800A781C: nop

    // 0x800A7820: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7824: nop

    // 0x800A7828: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A782C: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A7830: sw          $t9, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r25;
    // 0x800A7834: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    // 0x800A7838: lui         $t1, 0xB700
    ctx->r9 = S32(0XB700 << 16);
    // 0x800A783C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A7840: lw          $t4, 0x10C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10C);
    // 0x800A7844: addiu       $t2, $zero, 0x205
    ctx->r10 = ADD32(0, 0X205);
    // 0x800A7848: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800A784C: b           L_800A7880
    // 0x800A7850: nop

        goto L_800A7880;
    // 0x800A7850: nop

L_800A7854:
    // 0x800A7854: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7858: nop

    // 0x800A785C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A7860: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A7864: sw          $t5, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r13;
    // 0x800A7868: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x800A786C: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x800A7870: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A7874: lw          $t0, 0x108($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X108);
    // 0x800A7878: addiu       $t9, $zero, 0x2205
    ctx->r25 = ADD32(0, 0X2205);
    // 0x800A787C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_800A7880:
    // 0x800A7880: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7884: nop

    // 0x800A7888: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A788C: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A7890: sw          $t1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r9;
    // 0x800A7894: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x800A7898: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x800A789C: ori         $t2, $t2, 0x1301
    ctx->r10 = ctx->r10 | 0X1301;
    // 0x800A78A0: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x800A78A4: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800A78A8: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x800A78AC: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A78B0: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A78B4: nop

    // 0x800A78B8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A78BC: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A78C0: sw          $t7, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r15;
    // 0x800A78C4: lw          $t0, 0x100($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X100);
    // 0x800A78C8: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800A78CC: ori         $t9, $t9, 0x1102
    ctx->r25 = ctx->r25 | 0X1102;
    // 0x800A78D0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A78D4: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x800A78D8: nop

    // 0x800A78DC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A78E0: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A78E4: nop

    // 0x800A78E8: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A78EC: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A78F0: sw          $t3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r11;
    // 0x800A78F4: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x800A78F8: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x800A78FC: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x800A7900: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800A7904: lw          $t6, 0xFC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XFC);
    // 0x800A7908: nop

    // 0x800A790C: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A7910: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7914: nop

    // 0x800A7918: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A791C: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A7920: sw          $t7, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r15;
    // 0x800A7924: lw          $t0, 0xF8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF8);
    // 0x800A7928: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800A792C: ori         $t9, $t9, 0x903
    ctx->r25 = ctx->r25 | 0X903;
    // 0x800A7930: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A7934: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x800A7938: addiu       $t1, $zero, 0xC00
    ctx->r9 = ADD32(0, 0XC00);
    // 0x800A793C: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800A7940: lw          $t2, 0x178($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X178);
    // 0x800A7944: nop

    // 0x800A7948: andi        $t4, $t2, 0x4
    ctx->r12 = ctx->r10 & 0X4;
    // 0x800A794C: bne         $t4, $zero, L_800A798C
    if (ctx->r12 != 0) {
        // 0x800A7950: nop

            goto L_800A798C;
    }
    // 0x800A7950: nop

    // 0x800A7954: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7958: nop

    // 0x800A795C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A7960: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A7964: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x800A7968: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x800A796C: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A7970: ori         $t7, $t7, 0xC02
    ctx->r15 = ctx->r15 | 0XC02;
    // 0x800A7974: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A7978: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x800A797C: nop

    // 0x800A7980: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A7984: b           L_800A79BC
    // 0x800A7988: nop

        goto L_800A79BC;
    // 0x800A7988: nop

L_800A798C:
    // 0x800A798C: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7990: nop

    // 0x800A7994: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800A7998: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A799C: sw          $t0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r8;
    // 0x800A79A0: lw          $t2, 0xF0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF0);
    // 0x800A79A4: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A79A8: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x800A79AC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A79B0: lw          $t5, 0xF0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF0);
    // 0x800A79B4: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x800A79B8: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
L_800A79BC:
    // 0x800A79BC: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A79C0: nop

    // 0x800A79C4: lh          $t7, 0x10C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10C);
    // 0x800A79C8: nop

    // 0x800A79CC: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x800A79D0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800A79D4: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800A79D8: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A79DC: nop

    // 0x800A79E0: lh          $t1, 0x10E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10E);
    // 0x800A79E4: nop

    // 0x800A79E8: sll         $t3, $t1, 8
    ctx->r11 = S32(ctx->r9 << 8);
    // 0x800A79EC: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x800A79F0: sw          $t2, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r10;
    // 0x800A79F4: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A79F8: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x800A79FC: lwc1        $f10, 0xB0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XB0);
    // 0x800A7A00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A7A04: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800A7A08: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A7A0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A7A10: nop

    // 0x800A7A14: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A7A18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7A1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7A20: nop

    // 0x800A7A24: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A7A28: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800A7A2C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A7A30: sw          $t6, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r14;
    // 0x800A7A34: nop

    // 0x800A7A38: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7A3C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800A7A40: lh          $t8, 0x10C($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X10C);
    // 0x800A7A44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A7A48: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800A7A4C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A7A50: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A7A54: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A7A58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7A5C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A7A60: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A7A64: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800A7A68: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A7A6C: nop

    // 0x800A7A70: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A7A74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7A78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7A7C: nop

    // 0x800A7A80: cvt.w.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_D(ctx->f18.d);
    // 0x800A7A84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A7A88: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
    // 0x800A7A8C: nop

    // 0x800A7A90: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800A7A94: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x800A7A98: nop

    // 0x800A7A9C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800A7AA0: addiu       $t2, $t3, -0x3F
    ctx->r10 = ADD32(ctx->r11, -0X3F);
    // 0x800A7AA4: bgez        $t2, L_800A7AB4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A7AA8: sra         $t4, $t2, 6
        ctx->r12 = S32(SIGNED(ctx->r10) >> 6);
            goto L_800A7AB4;
    }
    // 0x800A7AA8: sra         $t4, $t2, 6
    ctx->r12 = S32(SIGNED(ctx->r10) >> 6);
    // 0x800A7AAC: addiu       $at, $t2, 0x3F
    ctx->r1 = ADD32(ctx->r10, 0X3F);
    // 0x800A7AB0: sra         $t4, $at, 6
    ctx->r12 = S32(SIGNED(ctx->r1) >> 6);
L_800A7AB4:
    // 0x800A7AB4: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800A7AB8: sw          $t5, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r13;
    // 0x800A7ABC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A7AC0: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7AC4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A7AC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7ACC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7AD0: lwc1        $f4, 0xB4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XB4);
    // 0x800A7AD4: nop

    // 0x800A7AD8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A7ADC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800A7AE0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A7AE4: addiu       $t9, $t8, -0x80
    ctx->r25 = ADD32(ctx->r24, -0X80);
    // 0x800A7AE8: sw          $t9, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r25;
    // 0x800A7AEC: lw          $t0, 0x180($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X180);
    // 0x800A7AF0: nop

    // 0x800A7AF4: bgez        $t0, L_800A7B04
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800A7AF8: sra         $t1, $t0, 5
        ctx->r9 = S32(SIGNED(ctx->r8) >> 5);
            goto L_800A7B04;
    }
    // 0x800A7AF8: sra         $t1, $t0, 5
    ctx->r9 = S32(SIGNED(ctx->r8) >> 5);
    // 0x800A7AFC: addiu       $at, $t0, 0x1F
    ctx->r1 = ADD32(ctx->r8, 0X1F);
    // 0x800A7B00: sra         $t1, $at, 5
    ctx->r9 = S32(SIGNED(ctx->r1) >> 5);
L_800A7B04:
    // 0x800A7B04: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x800A7B08: addiu       $t2, $t3, -0x20
    ctx->r10 = ADD32(ctx->r11, -0X20);
    // 0x800A7B0C: sw          $t2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r10;
    // 0x800A7B10: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7B14: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800A7B18: lh          $t5, 0x10E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X10E);
    // 0x800A7B1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A7B20: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800A7B24: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A7B28: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A7B2C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A7B30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A7B34: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A7B38: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800A7B3C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800A7B40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A7B44: nop

    // 0x800A7B48: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A7B4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7B50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7B54: nop

    // 0x800A7B58: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A7B5C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A7B60: swc1        $f16, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f16.u32l;
    // 0x800A7B64: nop

    // 0x800A7B68: sw          $zero, 0x160($sp)
    MEM_W(0X160, ctx->r29) = 0;
L_800A7B6C:
    // 0x800A7B6C: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800A7B70: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800A7B74: nop

    // 0x800A7B78: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A7B7C: beq         $at, $zero, L_800A7B8C
    if (ctx->r1 == 0) {
        // 0x800A7B80: nop

            goto L_800A7B8C;
    }
    // 0x800A7B80: nop

    // 0x800A7B84: b           L_800A94BC
    // 0x800A7B88: nop

        goto L_800A94BC;
    // 0x800A7B88: nop

L_800A7B8C:
    // 0x800A7B8C: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800A7B90: nop

    // 0x800A7B94: bgez        $t9, L_800A7BA4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A7B98: nop

            goto L_800A7BA4;
    }
    // 0x800A7B98: nop

    // 0x800A7B9C: b           L_800A94BC
    // 0x800A7BA0: nop

        goto L_800A94BC;
    // 0x800A7BA0: nop

L_800A7BA4:
    // 0x800A7BA4: sw          $zero, 0x154($sp)
    MEM_W(0X154, ctx->r29) = 0;
    // 0x800A7BA8: lw          $t0, 0x180($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X180);
    // 0x800A7BAC: lw          $t1, 0x168($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X168);
    // 0x800A7BB0: sw          $zero, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = 0;
    // 0x800A7BB4: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x800A7BB8: sw          $t3, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r11;
L_800A7BBC:
    // 0x800A7BBC: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x800A7BC0: lw          $t4, 0x188($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X188);
    // 0x800A7BC4: nop

    // 0x800A7BC8: slt         $at, $t4, $t2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A7BCC: beq         $at, $zero, L_800A7BDC
    if (ctx->r1 == 0) {
        // 0x800A7BD0: nop

            goto L_800A7BDC;
    }
    // 0x800A7BD0: nop

    // 0x800A7BD4: b           L_800A8FD8
    // 0x800A7BD8: nop

        goto L_800A8FD8;
    // 0x800A7BD8: nop

L_800A7BDC:
    // 0x800A7BDC: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800A7BE0: nop

    // 0x800A7BE4: bgez        $t5, L_800A7BF4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A7BE8: nop

            goto L_800A7BF4;
    }
    // 0x800A7BE8: nop

    // 0x800A7BEC: b           L_800A8FD8
    // 0x800A7BF0: nop

        goto L_800A8FD8;
    // 0x800A7BF0: nop

L_800A7BF4:
    // 0x800A7BF4: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7BF8: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x800A7BFC: lh          $t9, 0x10C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X10C);
    // 0x800A7C00: bgez        $t6, L_800A7C10
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800A7C04: sra         $t7, $t6, 8
        ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
            goto L_800A7C10;
    }
    // 0x800A7C04: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800A7C08: addiu       $at, $t6, 0xFF
    ctx->r1 = ADD32(ctx->r14, 0XFF);
    // 0x800A7C0C: sra         $t7, $at, 8
    ctx->r15 = S32(SIGNED(ctx->r1) >> 8);
L_800A7C10:
    // 0x800A7C10: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7C14: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x800A7C18: mflo        $t0
    ctx->r8 = lo;
    // 0x800A7C1C: bgez        $t1, L_800A7C2C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800A7C20: sra         $t3, $t1, 6
        ctx->r11 = S32(SIGNED(ctx->r9) >> 6);
            goto L_800A7C2C;
    }
    // 0x800A7C20: sra         $t3, $t1, 6
    ctx->r11 = S32(SIGNED(ctx->r9) >> 6);
    // 0x800A7C24: addiu       $at, $t1, 0x3F
    ctx->r1 = ADD32(ctx->r9, 0X3F);
    // 0x800A7C28: sra         $t3, $at, 6
    ctx->r11 = S32(SIGNED(ctx->r1) >> 6);
L_800A7C2C:
    // 0x800A7C2C: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x800A7C30: sw          $t2, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r10;
    // 0x800A7C34: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7C38: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A7C3C: lw          $t5, 0x13C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X13C);
    // 0x800A7C40: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800A7C44: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800A7C48: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800A7C4C: lh          $t3, 0x124($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X124);
    // 0x800A7C50: bgez        $t9, L_800A7C60
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A7C54: sra         $t1, $t9, 12
        ctx->r9 = S32(SIGNED(ctx->r25) >> 12);
            goto L_800A7C60;
    }
    // 0x800A7C54: sra         $t1, $t9, 12
    ctx->r9 = S32(SIGNED(ctx->r25) >> 12);
    // 0x800A7C58: addiu       $at, $t9, 0xFFF
    ctx->r1 = ADD32(ctx->r25, 0XFFF);
    // 0x800A7C5C: sra         $t1, $at, 12
    ctx->r9 = S32(SIGNED(ctx->r1) >> 12);
L_800A7C60:
    // 0x800A7C60: andi        $t0, $t1, 0x7
    ctx->r8 = ctx->r9 & 0X7;
    // 0x800A7C64: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x800A7C68: sw          $t2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r10;
    // 0x800A7C6C: lw          $t8, 0x164($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X164);
    // 0x800A7C70: lw          $t6, 0x1A4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7C74: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800A7C78: lw          $t5, 0x13C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X13C);
    // 0x800A7C7C: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x800A7C80: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800A7C84: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x800A7C88: lw          $t9, 0x140($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X140);
    // 0x800A7C8C: andi        $t4, $t1, 0xFFF
    ctx->r12 = ctx->r9 & 0XFFF;
    // 0x800A7C90: sll         $t0, $t4, 3
    ctx->r8 = S32(ctx->r12 << 3);
    // 0x800A7C94: bgez        $t3, L_800A7CA8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A7C98: andi        $t2, $t3, 0xFF
        ctx->r10 = ctx->r11 & 0XFF;
            goto L_800A7CA8;
    }
    // 0x800A7C98: andi        $t2, $t3, 0xFF
    ctx->r10 = ctx->r11 & 0XFF;
    // 0x800A7C9C: beq         $t2, $zero, L_800A7CA8
    if (ctx->r10 == 0) {
        // 0x800A7CA0: nop

            goto L_800A7CA8;
    }
    // 0x800A7CA0: nop

    // 0x800A7CA4: addiu       $t2, $t2, -0x100
    ctx->r10 = ADD32(ctx->r10, -0X100);
L_800A7CA8:
    // 0x800A7CA8: bgez        $t2, L_800A7CB8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A7CAC: sra         $t8, $t2, 5
        ctx->r24 = S32(SIGNED(ctx->r10) >> 5);
            goto L_800A7CB8;
    }
    // 0x800A7CAC: sra         $t8, $t2, 5
    ctx->r24 = S32(SIGNED(ctx->r10) >> 5);
    // 0x800A7CB0: addiu       $at, $t2, 0x1F
    ctx->r1 = ADD32(ctx->r10, 0X1F);
    // 0x800A7CB4: sra         $t8, $at, 5
    ctx->r24 = S32(SIGNED(ctx->r1) >> 5);
L_800A7CB8:
    // 0x800A7CB8: addu        $t5, $t0, $t8
    ctx->r13 = ADD32(ctx->r8, ctx->r24);
    // 0x800A7CBC: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800A7CC0: addu        $t1, $t9, $t7
    ctx->r9 = ADD32(ctx->r25, ctx->r15);
    // 0x800A7CC4: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x800A7CC8: nop

    // 0x800A7CCC: sh          $t4, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r12;
    // 0x800A7CD0: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7CD4: lhu         $t0, 0x14A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A7CD8: lw          $t2, 0x110($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X110);
    // 0x800A7CDC: nop

    // 0x800A7CE0: bne         $t2, $t0, L_800A7CF0
    if (ctx->r10 != ctx->r8) {
        // 0x800A7CE4: nop

            goto L_800A7CF0;
    }
    // 0x800A7CE4: nop

    // 0x800A7CE8: b           L_800A8FD8
    // 0x800A7CEC: nop

        goto L_800A8FD8;
    // 0x800A7CEC: nop

L_800A7CF0:
    // 0x800A7CF0: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7CF4: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A7CF8: lw          $t5, 0x13C($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X13C);
    // 0x800A7CFC: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800A7D00: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x800A7D04: lhu         $t1, 0x0($t7)
    ctx->r9 = MEM_HU(ctx->r15, 0X0);
    // 0x800A7D08: nop

    // 0x800A7D0C: andi        $t4, $t1, 0x8000
    ctx->r12 = ctx->r9 & 0X8000;
    // 0x800A7D10: sw          $t4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r12;
    // 0x800A7D14: lhu         $t3, 0x14A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A7D18: lw          $t0, 0x170($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X170);
    // 0x800A7D1C: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7D20: bgez        $t3, L_800A7D30
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A7D24: sra         $t2, $t3, 12
        ctx->r10 = S32(SIGNED(ctx->r11) >> 12);
            goto L_800A7D30;
    }
    // 0x800A7D24: sra         $t2, $t3, 12
    ctx->r10 = S32(SIGNED(ctx->r11) >> 12);
    // 0x800A7D28: addiu       $at, $t3, 0xFFF
    ctx->r1 = ADD32(ctx->r11, 0XFFF);
    // 0x800A7D2C: sra         $t2, $at, 12
    ctx->r10 = S32(SIGNED(ctx->r1) >> 12);
L_800A7D30:
    // 0x800A7D30: lh          $t9, 0x122($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X122);
    // 0x800A7D34: addu        $t8, $t2, $t0
    ctx->r24 = ADD32(ctx->r10, ctx->r8);
    // 0x800A7D38: andi        $t6, $t8, 0x7
    ctx->r14 = ctx->r24 & 0X7;
    // 0x800A7D3C: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A7D40: beq         $at, $zero, L_800A7D50
    if (ctx->r1 == 0) {
        // 0x800A7D44: nop

            goto L_800A7D50;
    }
    // 0x800A7D44: nop

    // 0x800A7D48: b           L_800A7D68
    // 0x800A7D4C: sw          $t6, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r14;
        goto L_800A7D68;
    // 0x800A7D4C: sw          $t6, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r14;
L_800A7D50:
    // 0x800A7D50: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7D54: nop

    // 0x800A7D58: lh          $t1, 0x122($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X122);
    // 0x800A7D5C: nop

    // 0x800A7D60: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x800A7D64: sw          $t4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r12;
L_800A7D68:
    // 0x800A7D68: lhu         $t3, 0x14A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A7D6C: nop

    // 0x800A7D70: andi        $t2, $t3, 0xFFF
    ctx->r10 = ctx->r11 & 0XFFF;
    // 0x800A7D74: sh          $t2, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r10;
    // 0x800A7D78: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800A7D7C: nop

    // 0x800A7D80: bne         $t0, $zero, L_800A7D98
    if (ctx->r8 != 0) {
        // 0x800A7D84: nop

            goto L_800A7D98;
    }
    // 0x800A7D84: nop

    // 0x800A7D88: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A7D8C: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A7D90: nop

    // 0x800A7D94: sw          $t8, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r24;
L_800A7D98:
    // 0x800A7D98: lw          $t5, 0x174($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X174);
    // 0x800A7D9C: lw          $t9, 0x170($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X170);
    // 0x800A7DA0: nop

    // 0x800A7DA4: beq         $t5, $t9, L_800A80CC
    if (ctx->r13 == ctx->r25) {
        // 0x800A7DA8: nop

            goto L_800A80CC;
    }
    // 0x800A7DA8: nop

    // 0x800A7DAC: lw          $t6, 0x170($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X170);
    // 0x800A7DB0: nop

    // 0x800A7DB4: sw          $t6, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r14;
    // 0x800A7DB8: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7DBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A7DC0: lh          $t1, 0x116($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X116);
    // 0x800A7DC4: nop

    // 0x800A7DC8: beq         $t1, $at, L_800A8070
    if (ctx->r9 == ctx->r1) {
        // 0x800A7DCC: nop

            goto L_800A8070;
    }
    // 0x800A7DCC: nop

    // 0x800A7DD0: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7DD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7DD8: lh          $t3, 0x116($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X116);
    // 0x800A7DDC: nop

    // 0x800A7DE0: bne         $t3, $at, L_800A7F14
    if (ctx->r11 != ctx->r1) {
        // 0x800A7DE4: nop

            goto L_800A7F14;
    }
    // 0x800A7DE4: nop

    // 0x800A7DE8: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7DEC: nop

    // 0x800A7DF0: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A7DF4: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A7DF8: sw          $t2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r10;
    // 0x800A7DFC: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x800A7E00: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800A7E04: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800A7E08: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7E0C: lw          $t7, 0x174($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X174);
    // 0x800A7E10: lw          $t6, 0x138($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X138);
    // 0x800A7E14: sll         $t1, $t7, 8
    ctx->r9 = S32(ctx->r15 << 8);
    // 0x800A7E18: lw          $t2, 0xEC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XEC);
    // 0x800A7E1C: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x800A7E20: addu        $t3, $t6, $t4
    ctx->r11 = ADD32(ctx->r14, ctx->r12);
    // 0x800A7E24: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x800A7E28: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7E2C: nop

    // 0x800A7E30: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A7E34: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A7E38: sw          $t0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r8;
    // 0x800A7E3C: lw          $t9, 0xE8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE8);
    // 0x800A7E40: lui         $t5, 0xE800
    ctx->r13 = S32(0XE800 << 16);
    // 0x800A7E44: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800A7E48: lw          $t7, 0xE8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE8);
    // 0x800A7E4C: nop

    // 0x800A7E50: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A7E54: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7E58: nop

    // 0x800A7E5C: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x800A7E60: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A7E64: sw          $t1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r9;
    // 0x800A7E68: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x800A7E6C: lui         $t4, 0xF500
    ctx->r12 = S32(0XF500 << 16);
    // 0x800A7E70: ori         $t4, $t4, 0x100
    ctx->r12 = ctx->r12 | 0X100;
    // 0x800A7E74: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A7E78: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x800A7E7C: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x800A7E80: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800A7E84: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7E88: nop

    // 0x800A7E8C: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x800A7E90: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A7E94: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    // 0x800A7E98: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x800A7E9C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800A7EA0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800A7EA4: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x800A7EA8: nop

    // 0x800A7EAC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A7EB0: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7EB4: nop

    // 0x800A7EB8: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x800A7EBC: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A7EC0: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x800A7EC4: lw          $t2, 0xDC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XDC);
    // 0x800A7EC8: lui         $t3, 0xF000
    ctx->r11 = S32(0XF000 << 16);
    // 0x800A7ECC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A7ED0: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800A7ED4: lui         $t0, 0x73F
    ctx->r8 = S32(0X73F << 16);
    // 0x800A7ED8: ori         $t0, $t0, 0xC000
    ctx->r8 = ctx->r8 | 0XC000;
    // 0x800A7EDC: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x800A7EE0: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7EE4: nop

    // 0x800A7EE8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800A7EEC: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A7EF0: sw          $t5, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r13;
    // 0x800A7EF4: lw          $t1, 0xD8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD8);
    // 0x800A7EF8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800A7EFC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800A7F00: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x800A7F04: nop

    // 0x800A7F08: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A7F0C: b           L_800A8038
    // 0x800A7F10: nop

        goto L_800A8038;
    // 0x800A7F10: nop

L_800A7F14:
    // 0x800A7F14: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7F18: nop

    // 0x800A7F1C: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x800A7F20: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A7F24: sw          $t4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r12;
    // 0x800A7F28: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x800A7F2C: lui         $t2, 0xFD10
    ctx->r10 = S32(0XFD10 << 16);
    // 0x800A7F30: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A7F34: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A7F38: lw          $t9, 0x174($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X174);
    // 0x800A7F3C: lw          $t5, 0x138($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X138);
    // 0x800A7F40: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800A7F44: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x800A7F48: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x800A7F4C: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x800A7F50: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800A7F54: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7F58: nop

    // 0x800A7F5C: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A7F60: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A7F64: sw          $t3, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r11;
    // 0x800A7F68: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800A7F6C: lui         $t0, 0xE800
    ctx->r8 = S32(0XE800 << 16);
    // 0x800A7F70: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x800A7F74: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800A7F78: nop

    // 0x800A7F7C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A7F80: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7F84: nop

    // 0x800A7F88: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800A7F8C: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A7F90: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x800A7F94: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x800A7F98: lui         $t1, 0xF500
    ctx->r9 = S32(0XF500 << 16);
    // 0x800A7F9C: ori         $t1, $t1, 0x100
    ctx->r9 = ctx->r9 | 0X100;
    // 0x800A7FA0: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x800A7FA4: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x800A7FA8: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x800A7FAC: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A7FB0: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7FB4: nop

    // 0x800A7FB8: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A7FBC: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A7FC0: sw          $t2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r10;
    // 0x800A7FC4: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800A7FC8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800A7FCC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A7FD0: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x800A7FD4: nop

    // 0x800A7FD8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A7FDC: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A7FE0: nop

    // 0x800A7FE4: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x800A7FE8: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A7FEC: sw          $t5, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r13;
    // 0x800A7FF0: lw          $t4, 0xC4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC4);
    // 0x800A7FF4: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x800A7FF8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800A7FFC: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800A8000: lui         $t3, 0x703
    ctx->r11 = S32(0X703 << 16);
    // 0x800A8004: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x800A8008: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x800A800C: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8010: nop

    // 0x800A8014: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A8018: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A801C: sw          $t0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r8;
    // 0x800A8020: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800A8024: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800A8028: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800A802C: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x800A8030: nop

    // 0x800A8034: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
L_800A8038:
    // 0x800A8038: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A803C: nop

    // 0x800A8040: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x800A8044: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A8048: sw          $t1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r9;
    // 0x800A804C: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x800A8050: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x800A8054: ori         $t4, $t4, 0xE02
    ctx->r12 = ctx->r12 | 0XE02;
    // 0x800A8058: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800A805C: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800A8060: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800A8064: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800A8068: b           L_800A80A0
    // 0x800A806C: nop

        goto L_800A80A0;
    // 0x800A806C: nop

L_800A8070:
    // 0x800A8070: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8074: nop

    // 0x800A8078: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A807C: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A8080: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x800A8084: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800A8088: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A808C: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x800A8090: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800A8094: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x800A8098: nop

    // 0x800A809C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
L_800A80A0:
    // 0x800A80A0: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A80A4: nop

    // 0x800A80A8: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x800A80AC: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A80B0: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x800A80B4: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x800A80B8: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800A80BC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A80C0: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800A80C4: nop

    // 0x800A80C8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
L_800A80CC:
    // 0x800A80CC: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x800A80D0: nop

    // 0x800A80D4: bne         $t8, $zero, L_800A85E4
    if (ctx->r24 != 0) {
        // 0x800A80D8: nop

            goto L_800A85E4;
    }
    // 0x800A80D8: nop

    // 0x800A80DC: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800A80E0: lw          $t7, 0x16C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X16C);
    // 0x800A80E4: lwc1        $f4, 0x144($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A80E8: subu        $t5, $t9, $t7
    ctx->r13 = SUB32(ctx->r25, ctx->r15);
    // 0x800A80EC: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800A80F0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A80F4: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A80F8: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A80FC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A8100: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A8104: nop

    // 0x800A8108: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A810C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8110: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8114: nop

    // 0x800A8118: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A811C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800A8120: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A8124: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x800A8128: nop

    // 0x800A812C: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x800A8130: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8134: lwc1        $f10, 0x140($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A8138: subu        $t0, $t3, $t2
    ctx->r8 = SUB32(ctx->r11, ctx->r10);
    // 0x800A813C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A8140: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8144: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8148: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A814C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800A8150: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A8154: nop

    // 0x800A8158: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A815C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8160: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8164: nop

    // 0x800A8168: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A816C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800A8170: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8174: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x800A8178: nop

    // 0x800A817C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A8180: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8184: lhu         $t5, 0x14A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A8188: nop

    // 0x800A818C: sh          $t5, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r13;
    // 0x800A8190: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A8194: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8198: nop

    // 0x800A819C: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800A81A0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A81A4: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A81A8: nop

    // 0x800A81AC: sh          $zero, 0xA($t4)
    MEM_H(0XA, ctx->r12) = 0;
    // 0x800A81B0: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A81B4: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A81B8: nop

    // 0x800A81BC: sh          $zero, 0x6($t3)
    MEM_H(0X6, ctx->r11) = 0;
    // 0x800A81C0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A81C4: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A81C8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A81CC: sb          $t2, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r10;
    // 0x800A81D0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A81D4: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A81D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A81DC: sb          $t8, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r24;
    // 0x800A81E0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A81E4: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A81E8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A81EC: sb          $t7, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r15;
    // 0x800A81F0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800A81F4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A81F8: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A81FC: lh          $t1, -0x4CDC($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CDC);
    // 0x800A8200: nop

    // 0x800A8204: sb          $t1, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r9;
    // 0x800A8208: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A820C: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A8210: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A8214: addiu       $t3, $t4, 0x10
    ctx->r11 = ADD32(ctx->r12, 0X10);
    // 0x800A8218: sw          $t3, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r11;
    // 0x800A821C: lw          $t2, 0x184($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X184);
    // 0x800A8220: lw          $t0, 0x16C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8224: lwc1        $f18, 0x144($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A8228: subu        $t8, $t2, $t0
    ctx->r24 = SUB32(ctx->r10, ctx->r8);
    // 0x800A822C: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x800A8230: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800A8234: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A8238: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A823C: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8240: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A8244: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A8248: nop

    // 0x800A824C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A8250: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8254: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8258: nop

    // 0x800A825C: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A8260: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800A8264: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A8268: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
    // 0x800A826C: nop

    // 0x800A8270: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x800A8274: lw          $t4, 0x17C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8278: lwc1        $f16, 0x140($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A827C: subu        $t3, $t6, $t4
    ctx->r11 = SUB32(ctx->r14, ctx->r12);
    // 0x800A8280: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A8284: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8288: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A828C: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8290: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A8294: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A8298: nop

    // 0x800A829C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A82A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A82A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A82A8: nop

    // 0x800A82AC: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A82B0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800A82B4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A82B8: sh          $t0, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r8;
    // 0x800A82BC: nop

    // 0x800A82C0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A82C4: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A82C8: nop

    // 0x800A82CC: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
    // 0x800A82D0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A82D4: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A82D8: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x800A82DC: sh          $t7, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r15;
    // 0x800A82E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A82E4: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A82E8: nop

    // 0x800A82EC: sh          $zero, 0xA($t1)
    MEM_H(0XA, ctx->r9) = 0;
    // 0x800A82F0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A82F4: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A82F8: nop

    // 0x800A82FC: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    // 0x800A8300: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8304: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8308: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A830C: sb          $t4, 0xC($t3)
    MEM_B(0XC, ctx->r11) = ctx->r12;
    // 0x800A8310: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A8314: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8318: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A831C: sb          $t2, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r10;
    // 0x800A8320: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A8324: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A8328: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A832C: sb          $t8, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r24;
    // 0x800A8330: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800A8334: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A8338: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A833C: lh          $t7, -0x4CDC($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4CDC);
    // 0x800A8340: nop

    // 0x800A8344: sb          $t7, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r15;
    // 0x800A8348: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A834C: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8350: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A8354: addiu       $t6, $t1, 0x10
    ctx->r14 = ADD32(ctx->r9, 0X10);
    // 0x800A8358: sw          $t6, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r14;
    // 0x800A835C: lw          $t4, 0x184($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X184);
    // 0x800A8360: lw          $t3, 0x16C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8364: lwc1        $f8, 0x144($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A8368: subu        $t2, $t4, $t3
    ctx->r10 = SUB32(ctx->r12, ctx->r11);
    // 0x800A836C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A8370: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A8374: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8378: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A837C: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A8380: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A8384: nop

    // 0x800A8388: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A838C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8390: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8394: nop

    // 0x800A8398: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A839C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800A83A0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A83A4: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x800A83A8: nop

    // 0x800A83AC: lw          $t7, 0x168($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X168);
    // 0x800A83B0: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800A83B4: lwc1        $f6, 0x140($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A83B8: subu        $t1, $t7, $t5
    ctx->r9 = SUB32(ctx->r15, ctx->r13);
    // 0x800A83BC: addiu       $t6, $t1, -0x20
    ctx->r14 = ADD32(ctx->r9, -0X20);
    // 0x800A83C0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800A83C4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A83C8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A83CC: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A83D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A83D4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A83D8: nop

    // 0x800A83DC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A83E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A83E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A83E8: nop

    // 0x800A83EC: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A83F0: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800A83F4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A83F8: sh          $t3, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r11;
    // 0x800A83FC: nop

    // 0x800A8400: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A8404: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8408: nop

    // 0x800A840C: sh          $zero, 0x4($t0)
    MEM_H(0X4, ctx->r8) = 0;
    // 0x800A8410: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8414: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8418: nop

    // 0x800A841C: sh          $zero, 0x8($t8)
    MEM_H(0X8, ctx->r24) = 0;
    // 0x800A8420: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8424: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8428: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x800A842C: sh          $t9, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r25;
    // 0x800A8430: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A8434: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A8438: nop

    // 0x800A843C: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800A8440: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A8444: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8448: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A844C: sb          $t1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r9;
    // 0x800A8450: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8454: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8458: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A845C: sb          $t4, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r12;
    // 0x800A8460: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A8464: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8468: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A846C: sb          $t2, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r10;
    // 0x800A8470: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800A8474: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A8478: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A847C: lh          $t8, -0x4CDC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CDC);
    // 0x800A8480: nop

    // 0x800A8484: sb          $t8, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r24;
    // 0x800A8488: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A848C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8490: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A8494: addiu       $t5, $t7, 0x10
    ctx->r13 = ADD32(ctx->r15, 0X10);
    // 0x800A8498: sw          $t5, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r13;
    // 0x800A849C: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x800A84A0: lw          $t6, 0x16C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X16C);
    // 0x800A84A4: lwc1        $f4, 0x144($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A84A8: subu        $t4, $t1, $t6
    ctx->r12 = SUB32(ctx->r9, ctx->r14);
    // 0x800A84AC: addiu       $t3, $t4, 0x40
    ctx->r11 = ADD32(ctx->r12, 0X40);
    // 0x800A84B0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800A84B4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A84B8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A84BC: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A84C0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A84C4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A84C8: nop

    // 0x800A84CC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A84D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A84D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A84D8: nop

    // 0x800A84DC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A84E0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800A84E4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A84E8: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x800A84EC: nop

    // 0x800A84F0: lw          $t9, 0x168($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X168);
    // 0x800A84F4: lw          $t7, 0x17C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X17C);
    // 0x800A84F8: lwc1        $f10, 0x140($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A84FC: subu        $t5, $t9, $t7
    ctx->r13 = SUB32(ctx->r25, ctx->r15);
    // 0x800A8500: addiu       $t1, $t5, -0x20
    ctx->r9 = ADD32(ctx->r13, -0X20);
    // 0x800A8504: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800A8508: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A850C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8510: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8514: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800A8518: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A851C: nop

    // 0x800A8520: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A8524: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8528: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A852C: nop

    // 0x800A8530: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A8534: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800A8538: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A853C: sh          $t4, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r12;
    // 0x800A8540: nop

    // 0x800A8544: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A8548: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A854C: nop

    // 0x800A8550: sh          $zero, 0x4($t2)
    MEM_H(0X4, ctx->r10) = 0;
    // 0x800A8554: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8558: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A855C: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x800A8560: sh          $t0, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r8;
    // 0x800A8564: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8568: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A856C: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x800A8570: sh          $t9, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r25;
    // 0x800A8574: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A8578: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A857C: nop

    // 0x800A8580: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800A8584: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A8588: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A858C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A8590: sb          $t1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r9;
    // 0x800A8594: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8598: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A859C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A85A0: sb          $t4, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r12;
    // 0x800A85A4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A85A8: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A85AC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A85B0: sb          $t2, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r10;
    // 0x800A85B4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800A85B8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A85BC: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A85C0: lh          $t8, -0x4CDC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4CDC);
    // 0x800A85C4: nop

    // 0x800A85C8: sb          $t8, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r24;
    // 0x800A85CC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A85D0: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A85D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A85D8: addiu       $t5, $t7, 0x10
    ctx->r13 = ADD32(ctx->r15, 0X10);
    // 0x800A85DC: b           L_800A8AE8
    // 0x800A85E0: sw          $t5, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r13;
        goto L_800A8AE8;
    // 0x800A85E0: sw          $t5, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r13;
L_800A85E4:
    // 0x800A85E4: lw          $t1, 0x184($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X184);
    // 0x800A85E8: lw          $t6, 0x16C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X16C);
    // 0x800A85EC: lwc1        $f18, 0x144($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A85F0: subu        $t4, $t1, $t6
    ctx->r12 = SUB32(ctx->r9, ctx->r14);
    // 0x800A85F4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800A85F8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A85FC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A8600: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8604: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A8608: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A860C: nop

    // 0x800A8610: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A8614: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8618: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A861C: nop

    // 0x800A8620: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A8624: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800A8628: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A862C: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x800A8630: nop

    // 0x800A8634: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800A8638: lw          $t9, 0x17C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X17C);
    // 0x800A863C: lwc1        $f16, 0x140($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A8640: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x800A8644: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800A8648: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A864C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A8650: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8654: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A8658: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A865C: nop

    // 0x800A8660: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A8664: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8668: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A866C: nop

    // 0x800A8670: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8674: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800A8678: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A867C: sh          $t1, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r9;
    // 0x800A8680: nop

    // 0x800A8684: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8688: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A868C: lhu         $t4, 0x14A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A8690: nop

    // 0x800A8694: sh          $t4, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r12;
    // 0x800A8698: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A869C: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A86A0: addiu       $t2, $zero, 0x1000
    ctx->r10 = ADD32(0, 0X1000);
    // 0x800A86A4: sh          $t2, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r10;
    // 0x800A86A8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A86AC: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A86B0: nop

    // 0x800A86B4: sh          $zero, 0xA($t8)
    MEM_H(0XA, ctx->r24) = 0;
    // 0x800A86B8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A86BC: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A86C0: nop

    // 0x800A86C4: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x800A86C8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A86CC: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A86D0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A86D4: sb          $t7, 0xC($t5)
    MEM_B(0XC, ctx->r13) = ctx->r15;
    // 0x800A86D8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A86DC: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A86E0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A86E4: sb          $t1, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r9;
    // 0x800A86E8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A86EC: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A86F0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A86F4: sb          $t4, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r12;
    // 0x800A86F8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800A86FC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A8700: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8704: lh          $t2, -0x4CDC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4CDC);
    // 0x800A8708: nop

    // 0x800A870C: sb          $t2, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r10;
    // 0x800A8710: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8714: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8718: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A871C: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x800A8720: sw          $t9, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r25;
    // 0x800A8724: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800A8728: lw          $t5, 0x16C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X16C);
    // 0x800A872C: lwc1        $f8, 0x144($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A8730: subu        $t1, $t7, $t5
    ctx->r9 = SUB32(ctx->r15, ctx->r13);
    // 0x800A8734: addiu       $t6, $t1, 0x40
    ctx->r14 = ADD32(ctx->r9, 0X40);
    // 0x800A8738: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A873C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A8740: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8744: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A8748: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A874C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A8750: nop

    // 0x800A8754: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A8758: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A875C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8760: nop

    // 0x800A8764: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A8768: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800A876C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A8770: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x800A8774: nop

    // 0x800A8778: lw          $t0, 0x168($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X168);
    // 0x800A877C: lw          $t8, 0x17C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8780: lwc1        $f6, 0x140($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A8784: subu        $t9, $t0, $t8
    ctx->r25 = SUB32(ctx->r8, ctx->r24);
    // 0x800A8788: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A878C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A8790: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A8794: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8798: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A879C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A87A0: nop

    // 0x800A87A4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A87A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A87AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A87B0: nop

    // 0x800A87B4: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A87B8: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800A87BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A87C0: sh          $t5, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r13;
    // 0x800A87C4: nop

    // 0x800A87C8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A87CC: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A87D0: nop

    // 0x800A87D4: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x800A87D8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A87DC: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A87E0: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x800A87E4: sh          $t4, 0x8($t3)
    MEM_H(0X8, ctx->r11) = ctx->r12;
    // 0x800A87E8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A87EC: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A87F0: nop

    // 0x800A87F4: sh          $zero, 0xA($t2)
    MEM_H(0XA, ctx->r10) = 0;
    // 0x800A87F8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A87FC: lw          $t0, 0x30B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30B0);
    // 0x800A8800: nop

    // 0x800A8804: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x800A8808: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800A880C: lw          $t9, 0x30B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30B0);
    // 0x800A8810: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A8814: sb          $t8, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r24;
    // 0x800A8818: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A881C: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A8820: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A8824: sb          $t7, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r15;
    // 0x800A8828: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A882C: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8830: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A8834: sb          $t1, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r9;
    // 0x800A8838: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800A883C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8840: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8844: lh          $t4, -0x4CDC($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CDC);
    // 0x800A8848: nop

    // 0x800A884C: sb          $t4, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r12;
    // 0x800A8850: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A8854: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A8858: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A885C: addiu       $t0, $t2, 0x10
    ctx->r8 = ADD32(ctx->r10, 0X10);
    // 0x800A8860: sw          $t0, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r8;
    // 0x800A8864: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x800A8868: lw          $t9, 0x16C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X16C);
    // 0x800A886C: lwc1        $f4, 0x144($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A8870: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x800A8874: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800A8878: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A887C: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A8880: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8884: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800A8888: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A888C: nop

    // 0x800A8890: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A8894: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8898: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A889C: nop

    // 0x800A88A0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A88A4: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800A88A8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A88AC: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x800A88B0: nop

    // 0x800A88B4: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x800A88B8: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x800A88BC: lwc1        $f10, 0x140($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A88C0: subu        $t2, $t4, $t3
    ctx->r10 = SUB32(ctx->r12, ctx->r11);
    // 0x800A88C4: addiu       $t0, $t2, -0x20
    ctx->r8 = ADD32(ctx->r10, -0X20);
    // 0x800A88C8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800A88CC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A88D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A88D4: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A88D8: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800A88DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A88E0: nop

    // 0x800A88E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A88E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A88EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A88F0: nop

    // 0x800A88F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A88F8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800A88FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8900: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x800A8904: nop

    // 0x800A8908: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A890C: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A8910: nop

    // 0x800A8914: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800A8918: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A891C: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8920: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x800A8924: sh          $t1, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r9;
    // 0x800A8928: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A892C: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8930: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x800A8934: sh          $t4, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r12;
    // 0x800A8938: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A893C: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A8940: nop

    // 0x800A8944: sh          $zero, 0x6($t2)
    MEM_H(0X6, ctx->r10) = 0;
    // 0x800A8948: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A894C: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8950: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A8954: sb          $t0, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r8;
    // 0x800A8958: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A895C: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8960: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A8964: sb          $t9, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r25;
    // 0x800A8968: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A896C: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8970: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A8974: sb          $t5, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r13;
    // 0x800A8978: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800A897C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A8980: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A8984: lh          $t6, -0x4CDC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CDC);
    // 0x800A8988: nop

    // 0x800A898C: sb          $t6, 0xF($t4)
    MEM_B(0XF, ctx->r12) = ctx->r14;
    // 0x800A8990: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8994: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8998: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A899C: addiu       $t2, $t3, 0x10
    ctx->r10 = ADD32(ctx->r11, 0X10);
    // 0x800A89A0: sw          $t2, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r10;
    // 0x800A89A4: lw          $t0, 0x184($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X184);
    // 0x800A89A8: lw          $t8, 0x16C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X16C);
    // 0x800A89AC: lwc1        $f18, 0x144($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800A89B0: subu        $t9, $t0, $t8
    ctx->r25 = SUB32(ctx->r8, ctx->r24);
    // 0x800A89B4: addiu       $t7, $t9, 0x40
    ctx->r15 = ADD32(ctx->r25, 0X40);
    // 0x800A89B8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A89BC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A89C0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A89C4: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A89C8: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A89CC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A89D0: nop

    // 0x800A89D4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A89D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A89DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A89E0: nop

    // 0x800A89E4: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A89E8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800A89EC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A89F0: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x800A89F4: nop

    // 0x800A89F8: lw          $t4, 0x168($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X168);
    // 0x800A89FC: lw          $t3, 0x17C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8A00: lwc1        $f16, 0x140($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800A8A04: subu        $t2, $t4, $t3
    ctx->r10 = SUB32(ctx->r12, ctx->r11);
    // 0x800A8A08: addiu       $t0, $t2, -0x20
    ctx->r8 = ADD32(ctx->r10, -0X20);
    // 0x800A8A0C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800A8A10: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8A14: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A8A18: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8A1C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A8A20: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A8A24: nop

    // 0x800A8A28: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A8A2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8A30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8A34: nop

    // 0x800A8A38: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8A3C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800A8A40: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8A44: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x800A8A48: nop

    // 0x800A8A4C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800A8A50: lw          $t5, 0x30B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30B0);
    // 0x800A8A54: nop

    // 0x800A8A58: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800A8A5C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800A8A60: lw          $t6, 0x30B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30B0);
    // 0x800A8A64: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x800A8A68: sh          $t1, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r9;
    // 0x800A8A6C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8A70: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8A74: addiu       $t4, $zero, 0x800
    ctx->r12 = ADD32(0, 0X800);
    // 0x800A8A78: sh          $t4, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r12;
    // 0x800A8A7C: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800A8A80: lw          $t2, 0x30B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X30B0);
    // 0x800A8A84: nop

    // 0x800A8A88: sh          $zero, 0x6($t2)
    MEM_H(0X6, ctx->r10) = 0;
    // 0x800A8A8C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A8A90: lw          $t8, 0x30B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30B0);
    // 0x800A8A94: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A8A98: sb          $t0, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r8;
    // 0x800A8A9C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800A8AA0: lw          $t7, 0x30B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30B0);
    // 0x800A8AA4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A8AA8: sb          $t9, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r25;
    // 0x800A8AAC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800A8AB0: lw          $t1, 0x30B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30B0);
    // 0x800A8AB4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800A8AB8: sb          $t5, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r13;
    // 0x800A8ABC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800A8AC0: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800A8AC4: lw          $t4, 0x30B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30B0);
    // 0x800A8AC8: lh          $t6, -0x4CDC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4CDC);
    // 0x800A8ACC: nop

    // 0x800A8AD0: sb          $t6, 0xF($t4)
    MEM_B(0XF, ctx->r12) = ctx->r14;
    // 0x800A8AD4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x800A8AD8: lw          $t3, 0x30B0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X30B0);
    // 0x800A8ADC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A8AE0: addiu       $t2, $t3, 0x10
    ctx->r10 = ADD32(ctx->r11, 0X10);
    // 0x800A8AE4: sw          $t2, 0x30B0($at)
    MEM_W(0X30B0, ctx->r1) = ctx->r10;
L_800A8AE8:
    // 0x800A8AE8: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800A8AEC: nop

    // 0x800A8AF0: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x800A8AF4: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
    // 0x800A8AF8: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x800A8AFC: nop

    // 0x800A8B00: slti        $at, $t9, 0x9
    ctx->r1 = SIGNED(ctx->r25) < 0X9 ? 1 : 0;
    // 0x800A8B04: beq         $at, $zero, L_800A8B28
    if (ctx->r1 == 0) {
        // 0x800A8B08: nop

            goto L_800A8B28;
    }
    // 0x800A8B08: nop

    // 0x800A8B0C: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800A8B10: nop

    // 0x800A8B14: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800A8B18: beq         $at, $zero, L_800A8B28
    if (ctx->r1 == 0) {
        // 0x800A8B1C: nop

            goto L_800A8B28;
    }
    // 0x800A8B1C: nop

    // 0x800A8B20: b           L_800A8FD8
    // 0x800A8B24: nop

        goto L_800A8FD8;
    // 0x800A8B24: nop

L_800A8B28:
    // 0x800A8B28: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8B2C: nop

    // 0x800A8B30: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x800A8B34: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A8B38: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    // 0x800A8B3C: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800A8B40: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800A8B44: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x800A8B48: addiu       $t3, $t4, -0x1
    ctx->r11 = ADD32(ctx->r12, -0X1);
    // 0x800A8B4C: sll         $t2, $t3, 4
    ctx->r10 = S32(ctx->r11 << 4);
    // 0x800A8B50: andi        $t0, $t2, 0xFF
    ctx->r8 = ctx->r10 & 0XFF;
    // 0x800A8B54: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x800A8B58: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x800A8B5C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800A8B60: andi        $t5, $t7, 0xFFFF
    ctx->r13 = ctx->r15 & 0XFFFF;
    // 0x800A8B64: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800A8B68: or          $t1, $t9, $t5
    ctx->r9 = ctx->r25 | ctx->r13;
    // 0x800A8B6C: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x800A8B70: lw          $t3, 0x198($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X198);
    // 0x800A8B74: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x800A8B78: nop

    // 0x800A8B7C: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x800A8B80: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800A8B84: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x800A8B88: blez        $t0, L_800A8FD4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800A8B8C: nop

            goto L_800A8FD4;
    }
    // 0x800A8B8C: nop

L_800A8B90:
    // 0x800A8B90: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800A8B94: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x800A8B98: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x800A8B9C: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800A8BA0: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800A8BA4: lh          $t1, 0x4($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X4);
    // 0x800A8BA8: nop

    // 0x800A8BAC: sh          $t1, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r9;
    // 0x800A8BB0: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800A8BB4: lw          $t6, 0x198($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X198);
    // 0x800A8BB8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x800A8BBC: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x800A8BC0: addu        $t4, $t6, $t0
    ctx->r12 = ADD32(ctx->r14, ctx->r8);
    // 0x800A8BC4: sh          $zero, 0x4($t4)
    MEM_H(0X4, ctx->r12) = 0;
    // 0x800A8BC8: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A8BCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A8BD0: lh          $t8, 0x116($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X116);
    // 0x800A8BD4: nop

    // 0x800A8BD8: bne         $t8, $at, L_800A8D50
    if (ctx->r24 != ctx->r1) {
        // 0x800A8BDC: nop

            goto L_800A8D50;
    }
    // 0x800A8BDC: nop

    // 0x800A8BE0: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8BE4: nop

    // 0x800A8BE8: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800A8BEC: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A8BF0: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x800A8BF4: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x800A8BF8: lui         $t1, 0xFD50
    ctx->r9 = S32(0XFD50 << 16);
    // 0x800A8BFC: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A8C00: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A8C04: lhu         $t0, 0x14A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A8C08: lw          $t6, 0x128($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X128);
    // 0x800A8C0C: sll         $t4, $t0, 6
    ctx->r12 = S32(ctx->r8 << 6);
    // 0x800A8C10: sll         $t7, $t4, 5
    ctx->r15 = S32(ctx->r12 << 5);
    // 0x800A8C14: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A8C18: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x800A8C1C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A8C20: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A8C24: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800A8C28: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x800A8C2C: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8C30: nop

    // 0x800A8C34: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800A8C38: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A8C3C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A8C40: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x800A8C44: lui         $t2, 0xF550
    ctx->r10 = S32(0XF550 << 16);
    // 0x800A8C48: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A8C4C: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x800A8C50: lui         $t4, 0x709
    ctx->r12 = S32(0X709 << 16);
    // 0x800A8C54: ori         $t4, $t4, 0x4160
    ctx->r12 = ctx->r12 | 0X4160;
    // 0x800A8C58: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x800A8C5C: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8C60: nop

    // 0x800A8C64: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A8C68: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A8C6C: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
    // 0x800A8C70: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x800A8C74: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800A8C78: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A8C7C: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x800A8C80: nop

    // 0x800A8C84: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A8C88: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8C8C: nop

    // 0x800A8C90: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A8C94: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A8C98: sw          $t3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r11;
    // 0x800A8C9C: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800A8CA0: lui         $t0, 0xF300
    ctx->r8 = S32(0XF300 << 16);
    // 0x800A8CA4: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800A8CA8: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x800A8CAC: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x800A8CB0: ori         $t6, $t6, 0xF100
    ctx->r14 = ctx->r14 | 0XF100;
    // 0x800A8CB4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A8CB8: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8CBC: nop

    // 0x800A8CC0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A8CC4: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A8CC8: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x800A8CCC: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x800A8CD0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800A8CD4: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800A8CD8: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x800A8CDC: nop

    // 0x800A8CE0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A8CE4: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8CE8: nop

    // 0x800A8CEC: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A8CF0: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A8CF4: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800A8CF8: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800A8CFC: lui         $t4, 0xF548
    ctx->r12 = S32(0XF548 << 16);
    // 0x800A8D00: ori         $t4, $t4, 0x1000
    ctx->r12 = ctx->r12 | 0X1000;
    // 0x800A8D04: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800A8D08: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A8D0C: lui         $t7, 0x9
    ctx->r15 = S32(0X9 << 16);
    // 0x800A8D10: ori         $t7, $t7, 0x4160
    ctx->r15 = ctx->r15 | 0X4160;
    // 0x800A8D14: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A8D18: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8D1C: nop

    // 0x800A8D20: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800A8D24: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A8D28: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x800A8D2C: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x800A8D30: lui         $t1, 0xF200
    ctx->r9 = S32(0XF200 << 16);
    // 0x800A8D34: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800A8D38: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x800A8D3C: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x800A8D40: ori         $t2, $t2, 0xC07C
    ctx->r10 = ctx->r10 | 0XC07C;
    // 0x800A8D44: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800A8D48: b           L_800A8EC8
    // 0x800A8D4C: nop

        goto L_800A8EC8;
    // 0x800A8D4C: nop

L_800A8D50:
    // 0x800A8D50: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A8D54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8D58: lh          $t6, 0x116($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X116);
    // 0x800A8D5C: nop

    // 0x800A8D60: bne         $t6, $at, L_800A8EC8
    if (ctx->r14 != ctx->r1) {
        // 0x800A8D64: nop

            goto L_800A8EC8;
    }
    // 0x800A8D64: nop

    // 0x800A8D68: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8D6C: nop

    // 0x800A8D70: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A8D74: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A8D78: sw          $t7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r15;
    // 0x800A8D7C: lw          $t5, 0x90($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X90);
    // 0x800A8D80: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x800A8D84: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A8D88: lhu         $t2, 0x14A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A8D8C: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A8D90: sll         $t0, $t2, 6
    ctx->r8 = S32(ctx->r10 << 6);
    // 0x800A8D94: lw          $t3, 0x128($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X128);
    // 0x800A8D98: sll         $t4, $t0, 5
    ctx->r12 = S32(ctx->r8 << 5);
    // 0x800A8D9C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800A8DA0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800A8DA4: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800A8DA8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800A8DAC: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8DB0: nop

    // 0x800A8DB4: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800A8DB8: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A8DBC: sw          $t9, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r25;
    // 0x800A8DC0: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x800A8DC4: lui         $t1, 0xF510
    ctx->r9 = S32(0XF510 << 16);
    // 0x800A8DC8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800A8DCC: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x800A8DD0: lui         $t0, 0x709
    ctx->r8 = S32(0X709 << 16);
    // 0x800A8DD4: ori         $t0, $t0, 0x4160
    ctx->r8 = ctx->r8 | 0X4160;
    // 0x800A8DD8: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x800A8DDC: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8DE0: nop

    // 0x800A8DE4: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800A8DE8: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A8DEC: sw          $t3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r11;
    // 0x800A8DF0: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x800A8DF4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800A8DF8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A8DFC: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800A8E00: nop

    // 0x800A8E04: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A8E08: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8E0C: nop

    // 0x800A8E10: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x800A8E14: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A8E18: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    // 0x800A8E1C: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800A8E20: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x800A8E24: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A8E28: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x800A8E2C: lui         $t4, 0x77F
    ctx->r12 = S32(0X77F << 16);
    // 0x800A8E30: ori         $t4, $t4, 0xF080
    ctx->r12 = ctx->r12 | 0XF080;
    // 0x800A8E34: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800A8E38: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8E3C: nop

    // 0x800A8E40: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A8E44: sw          $t7, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r15;
    // 0x800A8E48: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x800A8E4C: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800A8E50: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A8E54: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A8E58: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x800A8E5C: nop

    // 0x800A8E60: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A8E64: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8E68: nop

    // 0x800A8E6C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800A8E70: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A8E74: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800A8E78: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800A8E7C: lui         $t0, 0xF510
    ctx->r8 = S32(0XF510 << 16);
    // 0x800A8E80: ori         $t0, $t0, 0x2000
    ctx->r8 = ctx->r8 | 0X2000;
    // 0x800A8E84: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800A8E88: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800A8E8C: lui         $t3, 0x9
    ctx->r11 = S32(0X9 << 16);
    // 0x800A8E90: ori         $t3, $t3, 0x4160
    ctx->r11 = ctx->r11 | 0X4160;
    // 0x800A8E94: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800A8E98: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8E9C: nop

    // 0x800A8EA0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800A8EA4: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A8EA8: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x800A8EAC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800A8EB0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800A8EB4: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A8EB8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800A8EBC: lui         $t1, 0xF
    ctx->r9 = S32(0XF << 16);
    // 0x800A8EC0: ori         $t1, $t1, 0xC07C
    ctx->r9 = ctx->r9 | 0XC07C;
    // 0x800A8EC4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_800A8EC8:
    // 0x800A8EC8: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8ECC: nop

    // 0x800A8ED0: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800A8ED4: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A8ED8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x800A8EDC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800A8EE0: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
    // 0x800A8EE4: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800A8EE8: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800A8EEC: nop

    // 0x800A8EF0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A8EF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A8EF8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A8EFC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800A8F00: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x800A8F04: addiu       $t2, $t9, 0x1E
    ctx->r10 = ADD32(ctx->r25, 0X1E);
    // 0x800A8F08: andi        $t0, $t2, 0xFF
    ctx->r8 = ctx->r10 & 0XFF;
    // 0x800A8F0C: sll         $t1, $t5, 16
    ctx->r9 = S32(ctx->r13 << 16);
    // 0x800A8F10: sll         $t4, $t0, 8
    ctx->r12 = S32(ctx->r8 << 8);
    // 0x800A8F14: addiu       $t6, $t9, 0xA
    ctx->r14 = ADD32(ctx->r25, 0XA);
    // 0x800A8F18: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x800A8F1C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800A8F20: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x800A8F24: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x800A8F28: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x800A8F2C: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8F30: nop

    // 0x800A8F34: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x800A8F38: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A8F3C: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x800A8F40: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800A8F44: lui         $t1, 0xBF00
    ctx->r9 = S32(0XBF00 << 16);
    // 0x800A8F48: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800A8F4C: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x800A8F50: nop

    // 0x800A8F54: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800A8F58: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800A8F5C: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x800A8F60: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800A8F64: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x800A8F68: addiu       $t5, $t3, 0x14
    ctx->r13 = ADD32(ctx->r11, 0X14);
    // 0x800A8F6C: andi        $t2, $t5, 0xFF
    ctx->r10 = ctx->r13 & 0XFF;
    // 0x800A8F70: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800A8F74: sll         $t0, $t2, 8
    ctx->r8 = S32(ctx->r10 << 8);
    // 0x800A8F78: addiu       $t4, $t3, 0x1E
    ctx->r12 = ADD32(ctx->r11, 0X1E);
    // 0x800A8F7C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800A8F80: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800A8F84: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800A8F88: or          $t6, $t1, $t9
    ctx->r14 = ctx->r9 | ctx->r25;
    // 0x800A8F8C: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800A8F90: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A8F94: nop

    // 0x800A8F98: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x800A8F9C: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A8FA0: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x800A8FA4: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800A8FA8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A8FAC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800A8FB0: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800A8FB4: nop

    // 0x800A8FB8: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A8FBC: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800A8FC0: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x800A8FC4: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x800A8FC8: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A8FCC: bne         $at, $zero, L_800A8B90
    if (ctx->r1 != 0) {
        // 0x800A8FD0: sw          $t1, 0x150($sp)
        MEM_W(0X150, ctx->r29) = ctx->r9;
            goto L_800A8B90;
    }
    // 0x800A8FD0: sw          $t1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r9;
L_800A8FD4:
    // 0x800A8FD4: sw          $zero, 0x154($sp)
    MEM_W(0X154, ctx->r29) = 0;
L_800A8FD8:
    // 0x800A8FD8: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x800A8FDC: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800A8FE0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A8FE4: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x800A8FE8: addiu       $t2, $t5, 0x20
    ctx->r10 = ADD32(ctx->r13, 0X20);
    // 0x800A8FEC: sw          $t2, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r10;
    // 0x800A8FF0: bne         $at, $zero, L_800A7BBC
    if (ctx->r1 != 0) {
        // 0x800A8FF4: sw          $t7, 0x15C($sp)
        MEM_W(0X15C, ctx->r29) = ctx->r15;
            goto L_800A7BBC;
    }
    // 0x800A8FF4: sw          $t7, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r15;
    // 0x800A8FF8: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x800A8FFC: nop

    // 0x800A9000: beq         $t8, $zero, L_800A94BC
    if (ctx->r24 == 0) {
        // 0x800A9004: nop

            goto L_800A94BC;
    }
    // 0x800A9004: nop

    // 0x800A9008: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A900C: nop

    // 0x800A9010: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800A9014: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A9018: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800A901C: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x800A9020: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800A9024: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x800A9028: addiu       $t9, $t1, -0x1
    ctx->r25 = ADD32(ctx->r9, -0X1);
    // 0x800A902C: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x800A9030: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x800A9034: sll         $t2, $t5, 16
    ctx->r10 = S32(ctx->r13 << 16);
    // 0x800A9038: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x800A903C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800A9040: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800A9044: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x800A9048: or          $t3, $t7, $t0
    ctx->r11 = ctx->r15 | ctx->r8;
    // 0x800A904C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A9050: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x800A9054: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800A9058: nop

    // 0x800A905C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800A9060: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x800A9064: sw          $zero, 0x150($sp)
    MEM_W(0X150, ctx->r29) = 0;
    // 0x800A9068: blez        $t5, L_800A94BC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A906C: nop

            goto L_800A94BC;
    }
    // 0x800A906C: nop

L_800A9070:
    // 0x800A9070: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800A9074: nop

    // 0x800A9078: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x800A907C: sw          $t1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r9;
    // 0x800A9080: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800A9084: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x800A9088: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x800A908C: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x800A9090: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800A9094: lh          $t9, 0x4($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X4);
    // 0x800A9098: nop

    // 0x800A909C: sh          $t9, 0x14A($sp)
    MEM_H(0X14A, ctx->r29) = ctx->r25;
    // 0x800A90A0: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800A90A4: lw          $t6, 0x198($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X198);
    // 0x800A90A8: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x800A90AC: sll         $t1, $t2, 4
    ctx->r9 = S32(ctx->r10 << 4);
    // 0x800A90B0: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x800A90B4: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x800A90B8: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A90BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A90C0: lh          $t8, 0x116($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X116);
    // 0x800A90C4: nop

    // 0x800A90C8: bne         $t8, $at, L_800A9240
    if (ctx->r24 != ctx->r1) {
        // 0x800A90CC: nop

            goto L_800A9240;
    }
    // 0x800A90CC: nop

    // 0x800A90D0: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A90D4: nop

    // 0x800A90D8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A90DC: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A90E0: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x800A90E4: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800A90E8: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x800A90EC: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A90F0: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A90F4: lhu         $t1, 0x14A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A90F8: lw          $t6, 0x128($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X128);
    // 0x800A90FC: sll         $t7, $t1, 6
    ctx->r15 = S32(ctx->r9 << 6);
    // 0x800A9100: sll         $t0, $t7, 5
    ctx->r8 = S32(ctx->r15 << 5);
    // 0x800A9104: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800A9108: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800A910C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A9110: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x800A9114: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x800A9118: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800A911C: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A9120: nop

    // 0x800A9124: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800A9128: sw          $t5, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r13;
    // 0x800A912C: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x800A9130: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800A9134: lui         $t2, 0xF550
    ctx->r10 = S32(0XF550 << 16);
    // 0x800A9138: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800A913C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800A9140: lui         $t7, 0x709
    ctx->r15 = S32(0X709 << 16);
    // 0x800A9144: ori         $t7, $t7, 0x4160
    ctx->r15 = ctx->r15 | 0X4160;
    // 0x800A9148: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800A914C: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A9150: nop

    // 0x800A9154: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A9158: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A915C: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x800A9160: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800A9164: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x800A9168: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A916C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A9170: nop

    // 0x800A9174: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800A9178: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A917C: nop

    // 0x800A9180: addiu       $t2, $t5, 0x8
    ctx->r10 = ADD32(ctx->r13, 0X8);
    // 0x800A9184: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A9188: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x800A918C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800A9190: lui         $t1, 0xF300
    ctx->r9 = S32(0XF300 << 16);
    // 0x800A9194: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x800A9198: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800A919C: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x800A91A0: ori         $t6, $t6, 0xF100
    ctx->r14 = ctx->r14 | 0XF100;
    // 0x800A91A4: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800A91A8: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800A91AC: nop

    // 0x800A91B0: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x800A91B4: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A91B8: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x800A91BC: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800A91C0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800A91C4: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x800A91C8: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800A91CC: nop

    // 0x800A91D0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A91D4: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800A91D8: nop

    // 0x800A91DC: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x800A91E0: sw          $t1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r9;
    // 0x800A91E4: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x800A91E8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800A91EC: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x800A91F0: ori         $t7, $t7, 0x1000
    ctx->r15 = ctx->r15 | 0X1000;
    // 0x800A91F4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x800A91F8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800A91FC: lui         $t0, 0x9
    ctx->r8 = S32(0X9 << 16);
    // 0x800A9200: ori         $t0, $t0, 0x4160
    ctx->r8 = ctx->r8 | 0X4160;
    // 0x800A9204: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x800A9208: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A920C: nop

    // 0x800A9210: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A9214: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A9218: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x800A921C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800A9220: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800A9224: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800A9228: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800A922C: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x800A9230: ori         $t2, $t2, 0xC07C
    ctx->r10 = ctx->r10 | 0XC07C;
    // 0x800A9234: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x800A9238: b           L_800A93B8
    // 0x800A923C: nop

        goto L_800A93B8;
    // 0x800A923C: nop

L_800A9240:
    // 0x800A9240: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A9244: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9248: lh          $t6, 0x116($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X116);
    // 0x800A924C: nop

    // 0x800A9250: bne         $t6, $at, L_800A93B8
    if (ctx->r14 != ctx->r1) {
        // 0x800A9254: nop

            goto L_800A93B8;
    }
    // 0x800A9254: nop

    // 0x800A9258: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A925C: nop

    // 0x800A9260: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A9264: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A9268: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x800A926C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800A9270: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x800A9274: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A9278: lhu         $t2, 0x14A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X14A);
    // 0x800A927C: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x800A9280: sll         $t1, $t2, 6
    ctx->r9 = S32(ctx->r10 << 6);
    // 0x800A9284: lw          $t5, 0x128($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X128);
    // 0x800A9288: sll         $t7, $t1, 5
    ctx->r15 = S32(ctx->r9 << 5);
    // 0x800A928C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800A9290: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800A9294: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x800A9298: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x800A929C: lw          $t3, 0x19C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X19C);
    // 0x800A92A0: nop

    // 0x800A92A4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A92A8: sw          $t4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r12;
    // 0x800A92AC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800A92B0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A92B4: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x800A92B8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800A92BC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A92C0: lui         $t1, 0x709
    ctx->r9 = S32(0X709 << 16);
    // 0x800A92C4: ori         $t1, $t1, 0x4160
    ctx->r9 = ctx->r9 | 0X4160;
    // 0x800A92C8: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x800A92CC: lw          $t5, 0x19C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X19C);
    // 0x800A92D0: nop

    // 0x800A92D4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800A92D8: sw          $t6, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r14;
    // 0x800A92DC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800A92E0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800A92E4: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x800A92E8: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x800A92EC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A92F0: nop

    // 0x800A92F4: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800A92F8: lw          $t4, 0x19C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X19C);
    // 0x800A92FC: nop

    // 0x800A9300: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x800A9304: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A9308: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x800A930C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800A9310: lui         $t2, 0xF300
    ctx->r10 = S32(0XF300 << 16);
    // 0x800A9314: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800A9318: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A931C: lui         $t7, 0x77F
    ctx->r15 = S32(0X77F << 16);
    // 0x800A9320: ori         $t7, $t7, 0xF080
    ctx->r15 = ctx->r15 | 0XF080;
    // 0x800A9324: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800A9328: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A932C: nop

    // 0x800A9330: addiu       $t0, $t6, 0x8
    ctx->r8 = ADD32(ctx->r14, 0X8);
    // 0x800A9334: sw          $t0, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r8;
    // 0x800A9338: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800A933C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800A9340: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A9344: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800A9348: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800A934C: nop

    // 0x800A9350: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800A9354: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A9358: nop

    // 0x800A935C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800A9360: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A9364: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800A9368: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800A936C: lui         $t1, 0xF510
    ctx->r9 = S32(0XF510 << 16);
    // 0x800A9370: ori         $t1, $t1, 0x2000
    ctx->r9 = ctx->r9 | 0X2000;
    // 0x800A9374: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x800A9378: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800A937C: lui         $t5, 0x9
    ctx->r13 = S32(0X9 << 16);
    // 0x800A9380: ori         $t5, $t5, 0x4160
    ctx->r13 = ctx->r13 | 0X4160;
    // 0x800A9384: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800A9388: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A938C: nop

    // 0x800A9390: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A9394: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A9398: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800A939C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A93A0: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x800A93A4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A93A8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800A93AC: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x800A93B0: ori         $t9, $t9, 0xC07C
    ctx->r25 = ctx->r25 | 0XC07C;
    // 0x800A93B4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
L_800A93B8:
    // 0x800A93B8: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A93BC: nop

    // 0x800A93C0: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800A93C4: sw          $t7, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r15;
    // 0x800A93C8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800A93CC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800A93D0: lui         $t5, 0xBF00
    ctx->r13 = S32(0XBF00 << 16);
    // 0x800A93D4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A93D8: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800A93DC: nop

    // 0x800A93E0: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800A93E4: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x800A93E8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800A93EC: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x800A93F0: addiu       $t9, $t8, 0x1E
    ctx->r25 = ADD32(ctx->r24, 0X1E);
    // 0x800A93F4: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x800A93F8: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800A93FC: sll         $t1, $t2, 8
    ctx->r9 = S32(ctx->r10 << 8);
    // 0x800A9400: addiu       $t5, $t8, 0xA
    ctx->r13 = ADD32(ctx->r24, 0XA);
    // 0x800A9404: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800A9408: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800A940C: or          $t7, $t4, $t1
    ctx->r15 = ctx->r12 | ctx->r9;
    // 0x800A9410: or          $t0, $t7, $t6
    ctx->r8 = ctx->r15 | ctx->r14;
    // 0x800A9414: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800A9418: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x800A941C: nop

    // 0x800A9420: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800A9424: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800A9428: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800A942C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A9430: lui         $t4, 0xBF00
    ctx->r12 = S32(0XBF00 << 16);
    // 0x800A9434: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800A9438: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800A943C: nop

    // 0x800A9440: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x800A9444: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x800A9448: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800A944C: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x800A9450: addiu       $t0, $t5, 0x14
    ctx->r8 = ADD32(ctx->r13, 0X14);
    // 0x800A9454: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x800A9458: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800A945C: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x800A9460: addiu       $t4, $t5, 0x1E
    ctx->r12 = ADD32(ctx->r13, 0X1E);
    // 0x800A9464: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800A9468: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x800A946C: or          $t2, $t6, $t9
    ctx->r10 = ctx->r14 | ctx->r25;
    // 0x800A9470: or          $t8, $t2, $t1
    ctx->r24 = ctx->r10 | ctx->r9;
    // 0x800A9474: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x800A9478: lw          $t0, 0x19C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X19C);
    // 0x800A947C: nop

    // 0x800A9480: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800A9484: sw          $t3, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r11;
    // 0x800A9488: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800A948C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800A9490: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800A9494: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800A9498: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800A949C: nop

    // 0x800A94A0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800A94A4: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800A94A8: lw          $t1, 0x154($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X154);
    // 0x800A94AC: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x800A94B0: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A94B4: bne         $at, $zero, L_800A9070
    if (ctx->r1 != 0) {
        // 0x800A94B8: sw          $t2, 0x150($sp)
        MEM_W(0X150, ctx->r29) = ctx->r10;
            goto L_800A9070;
    }
    // 0x800A94B8: sw          $t2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r10;
L_800A94BC:
    // 0x800A94BC: lw          $t8, 0x160($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X160);
    // 0x800A94C0: lw          $t0, 0x184($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X184);
    // 0x800A94C4: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800A94C8: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x800A94CC: addiu       $t3, $t0, 0x40
    ctx->r11 = ADD32(ctx->r8, 0X40);
    // 0x800A94D0: sw          $t3, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r11;
    // 0x800A94D4: bne         $at, $zero, L_800A7B6C
    if (ctx->r1 != 0) {
        // 0x800A94D8: sw          $t7, 0x160($sp)
        MEM_W(0X160, ctx->r29) = ctx->r15;
            goto L_800A7B6C;
    }
    // 0x800A94D8: sw          $t7, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r15;
    // 0x800A94DC: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A94E0: nop

    // 0x800A94E4: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800A94E8: sw          $t9, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r25;
    // 0x800A94EC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800A94F0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800A94F4: lui         $t5, 0xBD00
    ctx->r13 = S32(0XBD00 << 16);
    // 0x800A94F8: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A94FC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800A9500: nop

    // 0x800A9504: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800A9508: lw          $t1, 0x19C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X19C);
    // 0x800A950C: nop

    // 0x800A9510: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x800A9514: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
    // 0x800A9518: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A951C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800A9520: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800A9524: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x800A9528: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A952C: nop

    // 0x800A9530: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A9534: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800A9538: lw          $t9, 0x1A0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A0);
    // 0x800A953C: nop

    // 0x800A9540: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800A9544: b           L_800A9554
    // 0x800A9548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A9554;
    // 0x800A9548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A954C: b           L_800A9554
    // 0x800A9550: nop

        goto L_800A9554;
    // 0x800A9550: nop

L_800A9554:
    // 0x800A9554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9558: addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
    // 0x800A955C: jr          $ra
    // 0x800A9560: nop

    return;
    // 0x800A9560: nop

;}
RECOMP_FUNC void func_800A9564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9564: addiu       $sp, $sp, -0x1D8
    ctx->r29 = ADD32(ctx->r29, -0X1D8);
    // 0x800A9568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A956C: sw          $a0, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r4;
    // 0x800A9570: sw          $a1, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r5;
    // 0x800A9574: sw          $a2, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r6;
    // 0x800A9578: sw          $a3, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r7;
    // 0x800A957C: jal         0x800C1680
    // 0x800A9580: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x800A9580: nop

    after_0:
    // 0x800A9584: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800A9588: jal         0x800C1AF4
    // 0x800A958C: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_1;
    // 0x800A958C: addiu       $a0, $a0, 0x1E0
    ctx->r4 = ADD32(ctx->r4, 0X1E0);
    after_1:
    // 0x800A9590: jal         0x800C1B64
    // 0x800A9594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C1B64(rdram, ctx);
        goto after_2;
    // 0x800A9594: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800A9598: lw          $a0, 0x1F0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1F0);
    // 0x800A959C: jal         0x800C1D44
    // 0x800A95A0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    func_800C1D44(rdram, ctx);
        goto after_3;
    // 0x800A95A0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_3:
    // 0x800A95A4: lw          $a0, 0x1DC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A95A8: jal         0x800C1D44
    // 0x800A95AC: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_4;
    // 0x800A95AC: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_4:
    // 0x800A95B0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A95B4: jal         0x800C1A84
    // 0x800A95B8: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_5;
    // 0x800A95B8: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_5:
    // 0x800A95BC: jal         0x800C1A28
    // 0x800A95C0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x800A95C0: nop

    after_6:
    // 0x800A95C4: lw          $t6, 0x1DC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A95C8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800A95CC: lw          $t8, 0x7250($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7250);
    // 0x800A95D0: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800A95D4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800A95D8: lw          $t0, 0x7258($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7258);
    // 0x800A95DC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800A95E0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800A95E4: sw          $t1, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r9;
    // 0x800A95E8: lw          $t2, 0x1B4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A95EC: nop

    // 0x800A95F0: andi        $t3, $t2, 0x200
    ctx->r11 = ctx->r10 & 0X200;
    // 0x800A95F4: bne         $t3, $zero, L_800A9634
    if (ctx->r11 != 0) {
        // 0x800A95F8: nop

            goto L_800A9634;
    }
    // 0x800A95F8: nop

    // 0x800A95FC: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800A9600: addiu       $t4, $t4, 0x6BC8
    ctx->r12 = ADD32(ctx->r12, 0X6BC8);
    // 0x800A9604: lwc1        $f4, 0x38($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X38);
    // 0x800A9608: lw          $a0, 0x1D8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1D8);
    // 0x800A960C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A9610: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A9614: jal         0x8009A084
    // 0x800A9618: nop

    func_8009A084(rdram, ctx);
        goto after_7;
    // 0x800A9618: nop

    after_7:
    // 0x800A961C: bgez        $v0, L_800A962C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A9620: nop

            goto L_800A962C;
    }
    // 0x800A9620: nop

    // 0x800A9624: b           L_800ABAB8
    // 0x800A9628: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ABAB8;
    // 0x800A9628: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A962C:
    // 0x800A962C: b           L_800A96D4
    // 0x800A9630: nop

        goto L_800A96D4;
    // 0x800A9630: nop

L_800A9634:
    // 0x800A9634: lw          $t5, 0x1B4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9638: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800A963C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800A9640: beq         $t6, $zero, L_800A9680
    if (ctx->r14 == 0) {
        // 0x800A9644: nop

            goto L_800A9680;
    }
    // 0x800A9644: nop

    // 0x800A9648: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800A964C: addiu       $t7, $t7, 0x6BC8
    ctx->r15 = ADD32(ctx->r15, 0X6BC8);
    // 0x800A9650: lwc1        $f8, 0x38($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X38);
    // 0x800A9654: lw          $a0, 0x1D8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1D8);
    // 0x800A9658: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A965C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A9660: jal         0x8009A084
    // 0x800A9664: nop

    func_8009A084(rdram, ctx);
        goto after_8;
    // 0x800A9664: nop

    after_8:
    // 0x800A9668: bgez        $v0, L_800A9678
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A966C: nop

            goto L_800A9678;
    }
    // 0x800A966C: nop

    // 0x800A9670: b           L_800ABAB8
    // 0x800A9674: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ABAB8;
    // 0x800A9674: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A9678:
    // 0x800A9678: b           L_800A96D4
    // 0x800A967C: nop

        goto L_800A96D4;
    // 0x800A967C: nop

L_800A9680:
    // 0x800A9680: lw          $t8, 0x1B4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9684: nop

    // 0x800A9688: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x800A968C: beq         $t9, $zero, L_800A96D4
    if (ctx->r25 == 0) {
        // 0x800A9690: nop

            goto L_800A96D4;
    }
    // 0x800A9690: nop

    // 0x800A9694: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A9698: lwc1        $f16, 0x25A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25A8);
    // 0x800A969C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800A96A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A96A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A96A8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A96AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A96B0: lw          $a0, 0x1D8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1D8);
    // 0x800A96B4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A96B8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A96BC: jal         0x8009A084
    // 0x800A96C0: nop

    func_8009A084(rdram, ctx);
        goto after_9;
    // 0x800A96C0: nop

    after_9:
    // 0x800A96C4: bgez        $v0, L_800A96D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A96C8: nop

            goto L_800A96D4;
    }
    // 0x800A96C8: nop

    // 0x800A96CC: b           L_800ABAB8
    // 0x800A96D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ABAB8;
    // 0x800A96D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800A96D4:
    // 0x800A96D4: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A96D8: lw          $t2, 0x1F0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1F0);
    // 0x800A96DC: lh          $t1, 0x11E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X11E);
    // 0x800A96E0: lwc1        $f18, 0xE8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XE8);
    // 0x800A96E4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A96E8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A96EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A96F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A96F4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A96F8: nop

    // 0x800A96FC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A9700: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A9704: nop

    // 0x800A9708: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A970C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9710: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9714: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A9718: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A971C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A9720: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A9724: sh          $t4, -0x4CDC($at)
    MEM_H(-0X4CDC, ctx->r1) = ctx->r12;
    // 0x800A9728: nop

    // 0x800A972C: jal         0x800C1680
    // 0x800A9730: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_10;
    // 0x800A9730: nop

    after_10:
    // 0x800A9734: lw          $a0, 0x1F0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1F0);
    // 0x800A9738: jal         0x800C1AF4
    // 0x800A973C: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_SetCurrent(rdram, ctx);
        goto after_11;
    // 0x800A973C: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_11:
    // 0x800A9740: lw          $a0, 0x1DC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9744: jal         0x800C1D44
    // 0x800A9748: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    func_800C1D44(rdram, ctx);
        goto after_12;
    // 0x800A9748: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_12:
    // 0x800A974C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800A9750: jal         0x800C1A84
    // 0x800A9754: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_13;
    // 0x800A9754: addiu       $a0, $a0, 0x6BC8
    ctx->r4 = ADD32(ctx->r4, 0X6BC8);
    after_13:
    // 0x800A9758: jal         0x800C1A28
    // 0x800A975C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_14;
    // 0x800A975C: nop

    after_14:
    // 0x800A9760: lw          $t5, 0x1D8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D8);
    // 0x800A9764: nop

    // 0x800A9768: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A976C: nop

    // 0x800A9770: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800A9774: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A9778: sw          $t7, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r15;
    // 0x800A977C: lwc1        $f16, 0x1E8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x800A9780: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A9784: nop

    // 0x800A9788: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A978C: nop

    // 0x800A9790: bc1f        L_800A97A8
    if (!c1cs) {
        // 0x800A9794: nop

            goto L_800A97A8;
    }
    // 0x800A9794: nop

    // 0x800A9798: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A979C: lwc1        $f4, -0x750($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X750);
    // 0x800A97A0: nop

    // 0x800A97A4: swc1        $f4, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->f4.u32l;
L_800A97A8:
    // 0x800A97A8: lwc1        $f6, 0x1EC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1EC);
    // 0x800A97AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A97B0: nop

    // 0x800A97B4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800A97B8: nop

    // 0x800A97BC: bc1f        L_800A97D4
    if (!c1cs) {
        // 0x800A97C0: nop

            goto L_800A97D4;
    }
    // 0x800A97C0: nop

    // 0x800A97C4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A97C8: lwc1        $f10, -0x74C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X74C);
    // 0x800A97CC: nop

    // 0x800A97D0: swc1        $f10, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->f10.u32l;
L_800A97D4:
    // 0x800A97D4: lw          $t8, 0x1DC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A97D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A97DC: lwc1        $f16, 0xF4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF4);
    // 0x800A97E0: lwc1        $f18, 0xFC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XFC);
    // 0x800A97E4: lwc1        $f6, 0x7218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A97E8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A97EC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800A97F0: addiu       $t9, $t9, 0x6BC8
    ctx->r25 = ADD32(ctx->r25, 0X6BC8);
    // 0x800A97F4: lwc1        $f10, 0x38($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X38);
    // 0x800A97F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A97FC: nop

    // 0x800A9800: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A9804: swc1        $f16, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f16.u32l;
    // 0x800A9808: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A980C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A9810: lwc1        $f18, 0xF8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x800A9814: lwc1        $f4, 0xFC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XFC);
    // 0x800A9818: lwc1        $f8, 0x7218($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A981C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A9820: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800A9824: addiu       $t1, $t1, 0x6BC8
    ctx->r9 = ADD32(ctx->r9, 0X6BC8);
    // 0x800A9828: lwc1        $f16, 0x38($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X38);
    // 0x800A982C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A9830: nop

    // 0x800A9834: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A9838: swc1        $f18, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f18.u32l;
    // 0x800A983C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800A9840: addiu       $t2, $t2, 0x6BC8
    ctx->r10 = ADD32(ctx->r10, 0X6BC8);
    // 0x800A9844: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800A9848: lwc1        $f4, 0x7218($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7218);
    // 0x800A984C: lwc1        $f6, 0x38($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X38);
    // 0x800A9850: nop

    // 0x800A9854: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A9858: swc1        $f8, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f8.u32l;
    // 0x800A985C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A9860: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A9864: lwc1        $f19, -0x748($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X748);
    // 0x800A9868: lwc1        $f18, -0x744($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X744);
    // 0x800A986C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800A9870: c.lt.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d < ctx->f16.d;
    // 0x800A9874: nop

    // 0x800A9878: bc1f        L_800A98B0
    if (!c1cs) {
        // 0x800A987C: nop

            goto L_800A98B0;
    }
    // 0x800A987C: nop

    // 0x800A9880: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A9884: lwc1        $f5, -0x740($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X740);
    // 0x800A9888: lwc1        $f4, -0x73C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73C);
    // 0x800A988C: nop

    // 0x800A9890: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x800A9894: nop

    // 0x800A9898: bc1f        L_800A98B0
    if (!c1cs) {
        // 0x800A989C: nop

            goto L_800A98B0;
    }
    // 0x800A989C: nop

    // 0x800A98A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A98A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A98A8: nop

    // 0x800A98AC: swc1        $f6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f6.u32l;
L_800A98B0:
    // 0x800A98B0: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800A98B4: addiu       $t3, $t3, 0x6BC8
    ctx->r11 = ADD32(ctx->r11, 0X6BC8);
    // 0x800A98B8: lwc1        $f8, 0x30($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X30);
    // 0x800A98BC: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A98C0: lwc1        $f16, 0x1E8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x800A98C4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A98C8: nop

    // 0x800A98CC: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800A98D0: swc1        $f4, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->f4.u32l;
    // 0x800A98D4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800A98D8: addiu       $t4, $t4, 0x6BC8
    ctx->r12 = ADD32(ctx->r12, 0X6BC8);
    // 0x800A98DC: lwc1        $f6, 0x34($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X34);
    // 0x800A98E0: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800A98E4: lwc1        $f18, 0x1EC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1EC);
    // 0x800A98E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A98EC: nop

    // 0x800A98F0: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A98F4: swc1        $f16, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->f16.u32l;
    // 0x800A98F8: lw          $t5, 0x1B4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A98FC: nop

    // 0x800A9900: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x800A9904: beq         $t6, $zero, L_800A9944
    if (ctx->r14 == 0) {
        // 0x800A9908: nop

            goto L_800A9944;
    }
    // 0x800A9908: nop

    // 0x800A990C: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9910: nop

    // 0x800A9914: lwc1        $f4, 0xF4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XF4);
    // 0x800A9918: lwc1        $f6, 0xFC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x800A991C: nop

    // 0x800A9920: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A9924: swc1        $f8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f8.u32l;
    // 0x800A9928: lw          $t8, 0x1DC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A992C: nop

    // 0x800A9930: lwc1        $f10, 0xF8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x800A9934: lwc1        $f18, 0xFC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XFC);
    // 0x800A9938: nop

    // 0x800A993C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A9940: swc1        $f16, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f16.u32l;
L_800A9944:
    // 0x800A9944: lwc1        $f4, 0x14C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800A9948: lwc1        $f6, 0x1E8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x800A994C: nop

    // 0x800A9950: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A9954: swc1        $f8, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->f8.u32l;
    // 0x800A9958: lwc1        $f10, 0x148($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800A995C: lwc1        $f18, 0x1EC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1EC);
    // 0x800A9960: nop

    // 0x800A9964: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A9968: swc1        $f16, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->f16.u32l;
    // 0x800A996C: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800A9970: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A9974: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A9978: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A997C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A9980: nop

    // 0x800A9984: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800A9988: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x800A998C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800A9990: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A9994: nop

    // 0x800A9998: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800A999C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A99A0: nop

    // 0x800A99A4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A99A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A99AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A99B0: nop

    // 0x800A99B4: cvt.w.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_D(ctx->f16.d);
    // 0x800A99B8: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800A99BC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A99C0: sh          $t0, 0x152($sp)
    MEM_H(0X152, ctx->r29) = ctx->r8;
    // 0x800A99C4: nop

    // 0x800A99C8: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800A99CC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A99D0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A99D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A99D8: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800A99DC: nop

    // 0x800A99E0: div.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800A99E4: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x800A99E8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A99EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A99F0: nop

    // 0x800A99F4: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800A99F8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A99FC: nop

    // 0x800A9A00: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A9A04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9A08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9A0C: nop

    // 0x800A9A10: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800A9A14: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x800A9A18: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A9A1C: sh          $t2, 0x150($sp)
    MEM_H(0X150, ctx->r29) = ctx->r10;
    // 0x800A9A20: nop

    // 0x800A9A24: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9A28: nop

    // 0x800A9A2C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800A9A30: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800A9A34: sw          $t3, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r11;
    // 0x800A9A38: lw          $t6, 0x138($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X138);
    // 0x800A9A3C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800A9A40: ori         $t5, $t5, 0x1402
    ctx->r13 = ctx->r13 | 0X1402;
    // 0x800A9A44: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A9A48: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x800A9A4C: nop

    // 0x800A9A50: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A9A54: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9A58: nop

    // 0x800A9A5C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A9A60: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800A9A64: sw          $t8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r24;
    // 0x800A9A68: lw          $t1, 0x134($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X134);
    // 0x800A9A6C: lui         $t0, 0xBB00
    ctx->r8 = S32(0XBB00 << 16);
    // 0x800A9A70: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x800A9A74: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800A9A78: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x800A9A7C: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800A9A80: ori         $t2, $t2, 0x8000
    ctx->r10 = ctx->r10 | 0X8000;
    // 0x800A9A84: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800A9A88: lw          $t4, 0x1B4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9A8C: nop

    // 0x800A9A90: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x800A9A94: beq         $t5, $zero, L_800A9B78
    if (ctx->r13 == 0) {
        // 0x800A9A98: nop

            goto L_800A9B78;
    }
    // 0x800A9A98: nop

    // 0x800A9A9C: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9AA0: nop

    // 0x800A9AA4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800A9AA8: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800A9AAC: sw          $t6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r14;
    // 0x800A9AB0: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x800A9AB4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800A9AB8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800A9ABC: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9AC0: nop

    // 0x800A9AC4: lh          $t4, 0x11A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X11A);
    // 0x800A9AC8: lh          $t1, 0x118($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X118);
    // 0x800A9ACC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A9AD0: lh          $t8, 0x11C($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X11C);
    // 0x800A9AD4: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800A9AD8: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x800A9ADC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800A9AE0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800A9AE4: lh          $t4, -0x4CDC($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4CDC);
    // 0x800A9AE8: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800A9AEC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800A9AF0: sll         $t1, $t9, 8
    ctx->r9 = S32(ctx->r25 << 8);
    // 0x800A9AF4: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x800A9AF8: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x800A9AFC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A9B00: or          $t3, $t2, $t5
    ctx->r11 = ctx->r10 | ctx->r13;
    // 0x800A9B04: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800A9B08: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9B0C: nop

    // 0x800A9B10: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800A9B14: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800A9B18: sw          $t0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r8;
    // 0x800A9B1C: lw          $t7, 0x12C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X12C);
    // 0x800A9B20: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800A9B24: ori         $t9, $t9, 0x97FF
    ctx->r25 = ctx->r25 | 0X97FF;
    // 0x800A9B28: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800A9B2C: lw          $t4, 0x12C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X12C);
    // 0x800A9B30: lui         $t1, 0xFF2C
    ctx->r9 = S32(0XFF2C << 16);
    // 0x800A9B34: ori         $t1, $t1, 0xFE7F
    ctx->r9 = ctx->r9 | 0XFE7F;
    // 0x800A9B38: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800A9B3C: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9B40: nop

    // 0x800A9B44: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800A9B48: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800A9B4C: sw          $t2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r10;
    // 0x800A9B50: lw          $t6, 0x128($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X128);
    // 0x800A9B54: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x800A9B58: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x800A9B5C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800A9B60: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
    // 0x800A9B64: lui         $t0, 0xF0A
    ctx->r8 = S32(0XF0A << 16);
    // 0x800A9B68: ori         $t0, $t0, 0x233
    ctx->r8 = ctx->r8 | 0X233;
    // 0x800A9B6C: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x800A9B70: b           L_800A9CD0
    // 0x800A9B74: nop

        goto L_800A9CD0;
    // 0x800A9B74: nop

L_800A9B78:
    // 0x800A9B78: lw          $t9, 0x1B4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9B7C: nop

    // 0x800A9B80: andi        $t7, $t9, 0x8000
    ctx->r15 = ctx->r25 & 0X8000;
    // 0x800A9B84: beq         $t7, $zero, L_800A9C68
    if (ctx->r15 == 0) {
        // 0x800A9B88: nop

            goto L_800A9C68;
    }
    // 0x800A9B88: nop

    // 0x800A9B8C: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9B90: nop

    // 0x800A9B94: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x800A9B98: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800A9B9C: sw          $t1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r9;
    // 0x800A9BA0: lw          $t5, 0x124($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X124);
    // 0x800A9BA4: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800A9BA8: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800A9BAC: lw          $t3, 0x1DC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9BB0: nop

    // 0x800A9BB4: lh          $t9, 0x11A($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X11A);
    // 0x800A9BB8: lh          $t6, 0x118($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X118);
    // 0x800A9BBC: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800A9BC0: lh          $t2, 0x11C($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X11C);
    // 0x800A9BC4: andi        $t0, $t6, 0xFF
    ctx->r8 = ctx->r14 & 0XFF;
    // 0x800A9BC8: sll         $t8, $t0, 24
    ctx->r24 = S32(ctx->r8 << 24);
    // 0x800A9BCC: sll         $t1, $t7, 16
    ctx->r9 = S32(ctx->r15 << 16);
    // 0x800A9BD0: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800A9BD4: lh          $t9, -0x4CDC($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4CDC);
    // 0x800A9BD8: or          $t4, $t8, $t1
    ctx->r12 = ctx->r24 | ctx->r9;
    // 0x800A9BDC: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x800A9BE0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800A9BE4: lw          $t1, 0x124($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X124);
    // 0x800A9BE8: or          $t0, $t4, $t6
    ctx->r8 = ctx->r12 | ctx->r14;
    // 0x800A9BEC: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800A9BF0: or          $t8, $t0, $t7
    ctx->r24 = ctx->r8 | ctx->r15;
    // 0x800A9BF4: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x800A9BF8: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9BFC: nop

    // 0x800A9C00: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A9C04: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800A9C08: sw          $t3, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r11;
    // 0x800A9C0C: lw          $t4, 0x120($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X120);
    // 0x800A9C10: lui         $t5, 0xFCFF
    ctx->r13 = S32(0XFCFF << 16);
    // 0x800A9C14: ori         $t5, $t5, 0x97FF
    ctx->r13 = ctx->r13 | 0X97FF;
    // 0x800A9C18: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A9C1C: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x800A9C20: lui         $t6, 0xFF2C
    ctx->r14 = S32(0XFF2C << 16);
    // 0x800A9C24: ori         $t6, $t6, 0xFE7F
    ctx->r14 = ctx->r14 | 0XFE7F;
    // 0x800A9C28: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x800A9C2C: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9C30: nop

    // 0x800A9C34: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800A9C38: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800A9C3C: sw          $t0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r8;
    // 0x800A9C40: lw          $t1, 0x11C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X11C);
    // 0x800A9C44: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x800A9C48: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x800A9C4C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800A9C50: lw          $t2, 0x11C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X11C);
    // 0x800A9C54: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x800A9C58: ori         $t3, $t3, 0x4A50
    ctx->r11 = ctx->r11 | 0X4A50;
    // 0x800A9C5C: sw          $t3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r11;
    // 0x800A9C60: b           L_800A9CD0
    // 0x800A9C64: nop

        goto L_800A9CD0;
    // 0x800A9C64: nop

L_800A9C68:
    // 0x800A9C68: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9C6C: nop

    // 0x800A9C70: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x800A9C74: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800A9C78: sw          $t5, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r13;
    // 0x800A9C7C: lw          $t9, 0x118($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X118);
    // 0x800A9C80: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800A9C84: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800A9C88: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800A9C8C: lw          $t7, 0x118($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X118);
    // 0x800A9C90: lui         $t0, 0xFFFC
    ctx->r8 = S32(0XFFFC << 16);
    // 0x800A9C94: ori         $t0, $t0, 0xF279
    ctx->r8 = ctx->r8 | 0XF279;
    // 0x800A9C98: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x800A9C9C: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9CA0: nop

    // 0x800A9CA4: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x800A9CA8: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800A9CAC: sw          $t8, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r24;
    // 0x800A9CB0: lw          $t2, 0x114($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X114);
    // 0x800A9CB4: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x800A9CB8: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x800A9CBC: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A9CC0: lw          $t4, 0x114($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X114);
    // 0x800A9CC4: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x800A9CC8: ori         $t5, $t5, 0x3078
    ctx->r13 = ctx->r13 | 0X3078;
    // 0x800A9CCC: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
L_800A9CD0:
    // 0x800A9CD0: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9CD4: nop

    // 0x800A9CD8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800A9CDC: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800A9CE0: sw          $t6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r14;
    // 0x800A9CE4: lw          $t7, 0x110($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X110);
    // 0x800A9CE8: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x800A9CEC: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x800A9CF0: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
    // 0x800A9CF4: addiu       $t8, $zero, 0x205
    ctx->r24 = ADD32(0, 0X205);
    // 0x800A9CF8: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x800A9CFC: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9D00: nop

    // 0x800A9D04: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A9D08: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800A9D0C: sw          $t3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r11;
    // 0x800A9D10: lw          $t4, 0x10C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10C);
    // 0x800A9D14: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800A9D18: ori         $t5, $t5, 0x1301
    ctx->r13 = ctx->r13 | 0X1301;
    // 0x800A9D1C: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A9D20: lw          $t6, 0x10C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10C);
    // 0x800A9D24: nop

    // 0x800A9D28: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A9D2C: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9D30: nop

    // 0x800A9D34: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A9D38: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800A9D3C: sw          $t9, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r25;
    // 0x800A9D40: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x800A9D44: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A9D48: ori         $t7, $t7, 0x1102
    ctx->r15 = ctx->r15 | 0X1102;
    // 0x800A9D4C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A9D50: lw          $t1, 0x108($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X108);
    // 0x800A9D54: nop

    // 0x800A9D58: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800A9D5C: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9D60: nop

    // 0x800A9D64: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800A9D68: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800A9D6C: sw          $t3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r11;
    // 0x800A9D70: lw          $t4, 0x104($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X104);
    // 0x800A9D74: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x800A9D78: ori         $t5, $t5, 0x1001
    ctx->r13 = ctx->r13 | 0X1001;
    // 0x800A9D7C: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800A9D80: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800A9D84: nop

    // 0x800A9D88: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800A9D8C: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9D90: nop

    // 0x800A9D94: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800A9D98: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800A9D9C: sw          $t9, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r25;
    // 0x800A9DA0: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x800A9DA4: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800A9DA8: ori         $t7, $t7, 0x903
    ctx->r15 = ctx->r15 | 0X903;
    // 0x800A9DAC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A9DB0: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x800A9DB4: addiu       $t1, $zero, 0xC00
    ctx->r9 = ADD32(0, 0XC00);
    // 0x800A9DB8: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800A9DBC: lw          $t2, 0x1B4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B4);
    // 0x800A9DC0: nop

    // 0x800A9DC4: andi        $t5, $t2, 0x4
    ctx->r13 = ctx->r10 & 0X4;
    // 0x800A9DC8: bne         $t5, $zero, L_800A9E08
    if (ctx->r13 != 0) {
        // 0x800A9DCC: nop

            goto L_800A9E08;
    }
    // 0x800A9DCC: nop

    // 0x800A9DD0: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9DD4: nop

    // 0x800A9DD8: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x800A9DDC: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800A9DE0: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
    // 0x800A9DE4: lw          $t0, 0xFC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XFC);
    // 0x800A9DE8: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800A9DEC: ori         $t9, $t9, 0xC02
    ctx->r25 = ctx->r25 | 0XC02;
    // 0x800A9DF0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A9DF4: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x800A9DF8: nop

    // 0x800A9DFC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800A9E00: b           L_800A9E38
    // 0x800A9E04: nop

        goto L_800A9E38;
    // 0x800A9E04: nop

L_800A9E08:
    // 0x800A9E08: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800A9E0C: nop

    // 0x800A9E10: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x800A9E14: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800A9E18: sw          $t8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r24;
    // 0x800A9E1C: lw          $t2, 0xF8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF8);
    // 0x800A9E20: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A9E24: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x800A9E28: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800A9E2C: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x800A9E30: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x800A9E34: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
L_800A9E38:
    // 0x800A9E38: lw          $t6, 0x1DC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9E3C: nop

    // 0x800A9E40: lh          $t9, 0x10C($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X10C);
    // 0x800A9E44: nop

    // 0x800A9E48: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x800A9E4C: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x800A9E50: sw          $t7, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->r15;
    // 0x800A9E54: lw          $t8, 0x1DC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9E58: nop

    // 0x800A9E5C: lh          $t1, 0x10E($t8)
    ctx->r9 = MEM_H(ctx->r24, 0X10E);
    // 0x800A9E60: nop

    // 0x800A9E64: sll         $t3, $t1, 8
    ctx->r11 = S32(ctx->r9 << 8);
    // 0x800A9E68: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x800A9E6C: sw          $t2, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r10;
    // 0x800A9E70: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800A9E74: addiu       $t5, $t5, 0x6BC8
    ctx->r13 = ADD32(ctx->r13, 0X6BC8);
    // 0x800A9E78: lwc1        $f4, 0x30($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X30);
    // 0x800A9E7C: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x800A9E80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A9E84: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800A9E88: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A9E8C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A9E90: nop

    // 0x800A9E94: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A9E98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9E9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9EA0: nop

    // 0x800A9EA4: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A9EA8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800A9EAC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A9EB0: sw          $t6, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r14;
    // 0x800A9EB4: nop

    // 0x800A9EB8: lw          $t9, 0x1DC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9EBC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800A9EC0: lh          $t0, 0x10C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10C);
    // 0x800A9EC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9EC8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800A9ECC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A9ED0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9ED4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A9ED8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A9EDC: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800A9EE0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800A9EE4: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x800A9EE8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9EEC: nop

    // 0x800A9EF0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A9EF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9EF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9EFC: nop

    // 0x800A9F00: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A9F04: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9F08: swc1        $f4, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->f4.u32l;
    // 0x800A9F0C: nop

    // 0x800A9F10: lw          $t8, 0x1A0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A0);
    // 0x800A9F14: lw          $t1, 0x1C0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C0);
    // 0x800A9F18: nop

    // 0x800A9F1C: addu        $t3, $t8, $t1
    ctx->r11 = ADD32(ctx->r24, ctx->r9);
    // 0x800A9F20: addiu       $t2, $t3, -0x3F
    ctx->r10 = ADD32(ctx->r11, -0X3F);
    // 0x800A9F24: bgez        $t2, L_800A9F34
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A9F28: sra         $t5, $t2, 6
        ctx->r13 = S32(SIGNED(ctx->r10) >> 6);
            goto L_800A9F34;
    }
    // 0x800A9F28: sra         $t5, $t2, 6
    ctx->r13 = S32(SIGNED(ctx->r10) >> 6);
    // 0x800A9F2C: addiu       $at, $t2, 0x3F
    ctx->r1 = ADD32(ctx->r10, 0X3F);
    // 0x800A9F30: sra         $t5, $at, 6
    ctx->r13 = S32(SIGNED(ctx->r1) >> 6);
L_800A9F34:
    // 0x800A9F34: sll         $t4, $t5, 6
    ctx->r12 = S32(ctx->r13 << 6);
    // 0x800A9F38: sw          $t4, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r12;
    // 0x800A9F3C: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800A9F40: addiu       $t6, $t6, 0x6BC8
    ctx->r14 = ADD32(ctx->r14, 0X6BC8);
    // 0x800A9F44: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800A9F48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A9F4C: lwc1        $f10, 0x34($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X34);
    // 0x800A9F50: nop

    // 0x800A9F54: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A9F58: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A9F5C: nop

    // 0x800A9F60: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A9F64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9F68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9F6C: nop

    // 0x800A9F70: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A9F74: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800A9F78: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A9F7C: sw          $t0, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->r8;
    // 0x800A9F80: nop

    // 0x800A9F84: lw          $t7, 0x1BC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1BC);
    // 0x800A9F88: nop

    // 0x800A9F8C: bgez        $t7, L_800A9F9C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800A9F90: sra         $t8, $t7, 5
        ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
            goto L_800A9F9C;
    }
    // 0x800A9F90: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x800A9F94: addiu       $at, $t7, 0x1F
    ctx->r1 = ADD32(ctx->r15, 0X1F);
    // 0x800A9F98: sra         $t8, $at, 5
    ctx->r24 = S32(SIGNED(ctx->r1) >> 5);
L_800A9F9C:
    // 0x800A9F9C: sll         $t1, $t8, 5
    ctx->r9 = S32(ctx->r24 << 5);
    // 0x800A9FA0: addiu       $t3, $t1, -0x20
    ctx->r11 = ADD32(ctx->r9, -0X20);
    // 0x800A9FA4: sw          $t3, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->r11;
    // 0x800A9FA8: lw          $t2, 0x1DC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1DC);
    // 0x800A9FAC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800A9FB0: lh          $t5, 0x10E($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X10E);
    // 0x800A9FB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9FB8: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800A9FBC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A9FC0: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9FC4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A9FC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A9FCC: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800A9FD0: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800A9FD4: mul.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x800A9FD8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A9FDC: nop

    // 0x800A9FE0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A9FE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9FE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9FEC: nop

    // 0x800A9FF0: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A9FF4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A9FF8: swc1        $f4, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->f4.u32l;
    // 0x800A9FFC: nop

    // 0x800AA000: sw          $zero, 0x194($sp)
    MEM_W(0X194, ctx->r29) = 0;
L_800AA004:
    // 0x800AA004: lw          $t6, 0x1C0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AA008: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x800AA00C: nop

    // 0x800AA010: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AA014: beq         $at, $zero, L_800AA024
    if (ctx->r1 == 0) {
        // 0x800AA018: nop

            goto L_800AA024;
    }
    // 0x800AA018: nop

    // 0x800AA01C: b           L_800ABA20
    // 0x800AA020: nop

        goto L_800ABA20;
    // 0x800AA020: nop

L_800AA024:
    // 0x800AA024: lw          $t0, 0x1C0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AA028: nop

    // 0x800AA02C: bgez        $t0, L_800AA03C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AA030: nop

            goto L_800AA03C;
    }
    // 0x800AA030: nop

    // 0x800AA034: b           L_800ABA20
    // 0x800AA038: nop

        goto L_800ABA20;
    // 0x800AA038: nop

L_800AA03C:
    // 0x800AA03C: sw          $zero, 0x188($sp)
    MEM_W(0X188, ctx->r29) = 0;
    // 0x800AA040: lw          $t7, 0x1BC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1BC);
    // 0x800AA044: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x800AA048: sw          $zero, 0x190($sp)
    MEM_W(0X190, ctx->r29) = 0;
    // 0x800AA04C: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x800AA050: sw          $t1, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r9;
L_800AA054:
    // 0x800AA054: lw          $t3, 0x1B8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA058: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x800AA05C: nop

    // 0x800AA060: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800AA064: beq         $at, $zero, L_800AA074
    if (ctx->r1 == 0) {
        // 0x800AA068: nop

            goto L_800AA074;
    }
    // 0x800AA068: nop

    // 0x800AA06C: b           L_800ABA00
    // 0x800AA070: nop

        goto L_800ABA00;
    // 0x800AA070: nop

L_800AA074:
    // 0x800AA074: lw          $t5, 0x1B8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA078: nop

    // 0x800AA07C: bgez        $t5, L_800AA08C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800AA080: nop

            goto L_800AA08C;
    }
    // 0x800AA080: nop

    // 0x800AA084: b           L_800ABA00
    // 0x800AA088: nop

        goto L_800ABA00;
    // 0x800AA088: nop

L_800AA08C:
    // 0x800AA08C: lw          $t9, 0x1DC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA090: lw          $t4, 0x1B8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA094: lh          $t0, 0x10C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10C);
    // 0x800AA098: bgez        $t4, L_800AA0A8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800AA09C: sra         $t6, $t4, 8
        ctx->r14 = S32(SIGNED(ctx->r12) >> 8);
            goto L_800AA0A8;
    }
    // 0x800AA09C: sra         $t6, $t4, 8
    ctx->r14 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800AA0A0: addiu       $at, $t4, 0xFF
    ctx->r1 = ADD32(ctx->r12, 0XFF);
    // 0x800AA0A4: sra         $t6, $at, 8
    ctx->r14 = S32(SIGNED(ctx->r1) >> 8);
L_800AA0A8:
    // 0x800AA0A8: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AA0AC: lw          $t8, 0x1C0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AA0B0: mflo        $t7
    ctx->r15 = lo;
    // 0x800AA0B4: bgez        $t8, L_800AA0C4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800AA0B8: sra         $t1, $t8, 6
        ctx->r9 = S32(SIGNED(ctx->r24) >> 6);
            goto L_800AA0C4;
    }
    // 0x800AA0B8: sra         $t1, $t8, 6
    ctx->r9 = S32(SIGNED(ctx->r24) >> 6);
    // 0x800AA0BC: addiu       $at, $t8, 0x3F
    ctx->r1 = ADD32(ctx->r24, 0X3F);
    // 0x800AA0C0: sra         $t1, $at, 6
    ctx->r9 = S32(SIGNED(ctx->r1) >> 6);
L_800AA0C4:
    // 0x800AA0C4: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x800AA0C8: sw          $t3, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r11;
    // 0x800AA0CC: lw          $t2, 0x1DC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA0D0: lw          $t4, 0x198($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X198);
    // 0x800AA0D4: lw          $t5, 0x13C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X13C);
    // 0x800AA0D8: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x800AA0DC: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x800AA0E0: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x800AA0E4: lh          $t1, 0x124($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X124);
    // 0x800AA0E8: bgez        $t0, L_800AA0F8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AA0EC: sra         $t8, $t0, 12
        ctx->r24 = S32(SIGNED(ctx->r8) >> 12);
            goto L_800AA0F8;
    }
    // 0x800AA0EC: sra         $t8, $t0, 12
    ctx->r24 = S32(SIGNED(ctx->r8) >> 12);
    // 0x800AA0F0: addiu       $at, $t0, 0xFFF
    ctx->r1 = ADD32(ctx->r8, 0XFFF);
    // 0x800AA0F4: sra         $t8, $at, 12
    ctx->r24 = S32(SIGNED(ctx->r1) >> 12);
L_800AA0F8:
    // 0x800AA0F8: andi        $t7, $t8, 0x7
    ctx->r15 = ctx->r24 & 0X7;
    // 0x800AA0FC: addu        $t3, $t7, $t1
    ctx->r11 = ADD32(ctx->r15, ctx->r9);
    // 0x800AA100: sw          $t3, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r11;
    // 0x800AA104: lw          $t9, 0x198($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X198);
    // 0x800AA108: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA10C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800AA110: lw          $t5, 0x13C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X13C);
    // 0x800AA114: lw          $t1, 0x1B8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA118: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x800AA11C: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x800AA120: lw          $t0, 0x140($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X140);
    // 0x800AA124: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x800AA128: sll         $t7, $t2, 3
    ctx->r15 = S32(ctx->r10 << 3);
    // 0x800AA12C: bgez        $t1, L_800AA140
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800AA130: andi        $t3, $t1, 0xFF
        ctx->r11 = ctx->r9 & 0XFF;
            goto L_800AA140;
    }
    // 0x800AA130: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x800AA134: beq         $t3, $zero, L_800AA140
    if (ctx->r11 == 0) {
        // 0x800AA138: nop

            goto L_800AA140;
    }
    // 0x800AA138: nop

    // 0x800AA13C: addiu       $t3, $t3, -0x100
    ctx->r11 = ADD32(ctx->r11, -0X100);
L_800AA140:
    // 0x800AA140: bgez        $t3, L_800AA150
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800AA144: sra         $t9, $t3, 5
        ctx->r25 = S32(SIGNED(ctx->r11) >> 5);
            goto L_800AA150;
    }
    // 0x800AA144: sra         $t9, $t3, 5
    ctx->r25 = S32(SIGNED(ctx->r11) >> 5);
    // 0x800AA148: addiu       $at, $t3, 0x1F
    ctx->r1 = ADD32(ctx->r11, 0X1F);
    // 0x800AA14C: sra         $t9, $at, 5
    ctx->r25 = S32(SIGNED(ctx->r1) >> 5);
L_800AA150:
    // 0x800AA150: addu        $t5, $t7, $t9
    ctx->r13 = ADD32(ctx->r15, ctx->r25);
    // 0x800AA154: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800AA158: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x800AA15C: lhu         $t2, 0x0($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X0);
    // 0x800AA160: nop

    // 0x800AA164: sh          $t2, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r10;
    // 0x800AA168: lw          $t1, 0x1DC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA16C: lhu         $t7, 0x182($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X182);
    // 0x800AA170: lw          $t3, 0x110($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X110);
    // 0x800AA174: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800AA178: bne         $t3, $t9, L_800AA188
    if (ctx->r11 != ctx->r25) {
        // 0x800AA17C: nop

            goto L_800AA188;
    }
    // 0x800AA17C: nop

    // 0x800AA180: b           L_800ABA00
    // 0x800AA184: nop

        goto L_800ABA00;
    // 0x800AA184: nop

L_800AA188:
    // 0x800AA188: lw          $t5, 0x1DC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA18C: lw          $t0, 0x198($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X198);
    // 0x800AA190: lw          $t4, 0x13C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X13C);
    // 0x800AA194: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800AA198: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x800AA19C: lhu         $t2, 0x0($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X0);
    // 0x800AA1A0: nop

    // 0x800AA1A4: andi        $t1, $t2, 0x8000
    ctx->r9 = ctx->r10 & 0X8000;
    // 0x800AA1A8: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800AA1AC: lhu         $t3, 0x182($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X182);
    // 0x800AA1B0: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800AA1B4: andi        $t9, $t3, 0x8000
    ctx->r25 = ctx->r11 & 0X8000;
    // 0x800AA1B8: xor         $t5, $t7, $t9
    ctx->r13 = ctx->r15 ^ ctx->r25;
    // 0x800AA1BC: sw          $t5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r13;
    // 0x800AA1C0: lhu         $t0, 0x182($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X182);
    // 0x800AA1C4: lw          $t6, 0x1AC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1AC);
    // 0x800AA1C8: lw          $t1, 0x1DC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA1CC: bgez        $t0, L_800AA1DC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AA1D0: sra         $t4, $t0, 12
        ctx->r12 = S32(SIGNED(ctx->r8) >> 12);
            goto L_800AA1DC;
    }
    // 0x800AA1D0: sra         $t4, $t0, 12
    ctx->r12 = S32(SIGNED(ctx->r8) >> 12);
    // 0x800AA1D4: addiu       $at, $t0, 0xFFF
    ctx->r1 = ADD32(ctx->r8, 0XFFF);
    // 0x800AA1D8: sra         $t4, $at, 12
    ctx->r12 = S32(SIGNED(ctx->r1) >> 12);
L_800AA1DC:
    // 0x800AA1DC: lh          $t3, 0x122($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X122);
    // 0x800AA1E0: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x800AA1E4: andi        $t2, $t8, 0x7
    ctx->r10 = ctx->r24 & 0X7;
    // 0x800AA1E8: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800AA1EC: beq         $at, $zero, L_800AA1FC
    if (ctx->r1 == 0) {
        // 0x800AA1F0: nop

            goto L_800AA1FC;
    }
    // 0x800AA1F0: nop

    // 0x800AA1F4: b           L_800AA214
    // 0x800AA1F8: sw          $t2, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r10;
        goto L_800AA214;
    // 0x800AA1F8: sw          $t2, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r10;
L_800AA1FC:
    // 0x800AA1FC: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA200: nop

    // 0x800AA204: lh          $t9, 0x122($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X122);
    // 0x800AA208: nop

    // 0x800AA20C: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800AA210: sw          $t5, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r13;
L_800AA214:
    // 0x800AA214: lhu         $t0, 0x182($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X182);
    // 0x800AA218: nop

    // 0x800AA21C: andi        $t4, $t0, 0xFFF
    ctx->r12 = ctx->r8 & 0XFFF;
    // 0x800AA220: sh          $t4, 0x182($sp)
    MEM_H(0X182, ctx->r29) = ctx->r12;
    // 0x800AA224: lw          $t6, 0x1B0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1B0);
    // 0x800AA228: lw          $t8, 0x1AC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1AC);
    // 0x800AA22C: nop

    // 0x800AA230: beq         $t6, $t8, L_800AA558
    if (ctx->r14 == ctx->r24) {
        // 0x800AA234: nop

            goto L_800AA558;
    }
    // 0x800AA234: nop

    // 0x800AA238: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x800AA23C: nop

    // 0x800AA240: sw          $t1, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r9;
    // 0x800AA244: lw          $t3, 0x1DC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA248: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AA24C: lh          $t2, 0x116($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X116);
    // 0x800AA250: nop

    // 0x800AA254: beq         $t2, $at, L_800AA4FC
    if (ctx->r10 == ctx->r1) {
        // 0x800AA258: nop

            goto L_800AA4FC;
    }
    // 0x800AA258: nop

    // 0x800AA25C: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA260: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AA264: lh          $t9, 0x116($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X116);
    // 0x800AA268: nop

    // 0x800AA26C: bne         $t9, $at, L_800AA3A0
    if (ctx->r25 != ctx->r1) {
        // 0x800AA270: nop

            goto L_800AA3A0;
    }
    // 0x800AA270: nop

    // 0x800AA274: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA278: nop

    // 0x800AA27C: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800AA280: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800AA284: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x800AA288: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x800AA28C: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
    // 0x800AA290: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800AA294: lw          $t8, 0x1DC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA298: lw          $t3, 0x1B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B0);
    // 0x800AA29C: lw          $t1, 0x138($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X138);
    // 0x800AA2A0: sll         $t2, $t3, 8
    ctx->r10 = S32(ctx->r11 << 8);
    // 0x800AA2A4: lw          $t5, 0xF4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF4);
    // 0x800AA2A8: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x800AA2AC: addu        $t9, $t1, $t7
    ctx->r25 = ADD32(ctx->r9, ctx->r15);
    // 0x800AA2B0: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x800AA2B4: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA2B8: nop

    // 0x800AA2BC: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800AA2C0: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800AA2C4: sw          $t0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r8;
    // 0x800AA2C8: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x800AA2CC: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x800AA2D0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800AA2D4: lw          $t3, 0xF0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF0);
    // 0x800AA2D8: nop

    // 0x800AA2DC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800AA2E0: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA2E4: nop

    // 0x800AA2E8: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x800AA2EC: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800AA2F0: sw          $t2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r10;
    // 0x800AA2F4: lw          $t9, 0xEC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XEC);
    // 0x800AA2F8: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x800AA2FC: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x800AA300: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800AA304: lw          $t0, 0xEC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XEC);
    // 0x800AA308: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x800AA30C: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800AA310: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA314: nop

    // 0x800AA318: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x800AA31C: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AA320: sw          $t4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r12;
    // 0x800AA324: lw          $t3, 0xE8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE8);
    // 0x800AA328: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800AA32C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800AA330: lw          $t2, 0xE8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE8);
    // 0x800AA334: nop

    // 0x800AA338: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800AA33C: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA340: nop

    // 0x800AA344: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800AA348: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AA34C: sw          $t1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r9;
    // 0x800AA350: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x800AA354: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x800AA358: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800AA35C: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x800AA360: lui         $t0, 0x73F
    ctx->r8 = S32(0X73F << 16);
    // 0x800AA364: ori         $t0, $t0, 0xC000
    ctx->r8 = ctx->r8 | 0XC000;
    // 0x800AA368: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x800AA36C: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA370: nop

    // 0x800AA374: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x800AA378: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AA37C: sw          $t6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r14;
    // 0x800AA380: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x800AA384: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800AA388: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800AA38C: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x800AA390: nop

    // 0x800AA394: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AA398: b           L_800AA4C4
    // 0x800AA39C: nop

        goto L_800AA4C4;
    // 0x800AA39C: nop

L_800AA3A0:
    // 0x800AA3A0: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA3A4: nop

    // 0x800AA3A8: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800AA3AC: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800AA3B0: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x800AA3B4: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800AA3B8: lui         $t5, 0xFD10
    ctx->r13 = S32(0XFD10 << 16);
    // 0x800AA3BC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AA3C0: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AA3C4: lw          $t8, 0x1B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B0);
    // 0x800AA3C8: lw          $t6, 0x138($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X138);
    // 0x800AA3CC: sll         $t3, $t8, 8
    ctx->r11 = S32(ctx->r24 << 8);
    // 0x800AA3D0: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x800AA3D4: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x800AA3D8: addu        $t1, $t6, $t2
    ctx->r9 = ADD32(ctx->r14, ctx->r10);
    // 0x800AA3DC: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x800AA3E0: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA3E4: nop

    // 0x800AA3E8: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x800AA3EC: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AA3F0: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
    // 0x800AA3F4: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x800AA3F8: lui         $t0, 0xE800
    ctx->r8 = S32(0XE800 << 16);
    // 0x800AA3FC: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x800AA400: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x800AA404: nop

    // 0x800AA408: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800AA40C: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA410: nop

    // 0x800AA414: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800AA418: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AA41C: sw          $t3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r11;
    // 0x800AA420: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x800AA424: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x800AA428: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x800AA42C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800AA430: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x800AA434: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x800AA438: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800AA43C: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA440: nop

    // 0x800AA444: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800AA448: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800AA44C: sw          $t5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r13;
    // 0x800AA450: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800AA454: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800AA458: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x800AA45C: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x800AA460: nop

    // 0x800AA464: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800AA468: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA46C: nop

    // 0x800AA470: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x800AA474: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800AA478: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800AA47C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800AA480: lui         $t1, 0xF000
    ctx->r9 = S32(0XF000 << 16);
    // 0x800AA484: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x800AA488: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x800AA48C: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x800AA490: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x800AA494: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x800AA498: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA49C: nop

    // 0x800AA4A0: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800AA4A4: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800AA4A8: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x800AA4AC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800AA4B0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AA4B4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800AA4B8: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800AA4BC: nop

    // 0x800AA4C0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
L_800AA4C4:
    // 0x800AA4C4: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA4C8: nop

    // 0x800AA4CC: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x800AA4D0: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800AA4D4: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x800AA4D8: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800AA4DC: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800AA4E0: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x800AA4E4: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800AA4E8: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x800AA4EC: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x800AA4F0: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800AA4F4: b           L_800AA52C
    // 0x800AA4F8: nop

        goto L_800AA52C;
    // 0x800AA4F8: nop

L_800AA4FC:
    // 0x800AA4FC: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA500: nop

    // 0x800AA504: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800AA508: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AA50C: sw          $t4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r12;
    // 0x800AA510: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800AA514: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800AA518: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x800AA51C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AA520: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x800AA524: nop

    // 0x800AA528: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
L_800AA52C:
    // 0x800AA52C: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AA530: nop

    // 0x800AA534: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800AA538: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AA53C: sw          $t1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r9;
    // 0x800AA540: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x800AA544: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800AA548: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800AA54C: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800AA550: nop

    // 0x800AA554: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
L_800AA558:
    // 0x800AA558: lw          $t4, 0x18C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18C);
    // 0x800AA55C: nop

    // 0x800AA560: bne         $t4, $zero, L_800AAFBC
    if (ctx->r12 != 0) {
        // 0x800AA564: nop

            goto L_800AAFBC;
    }
    // 0x800AA564: nop

    // 0x800AA568: lw          $t8, 0x1C0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AA56C: lw          $t3, 0x1A0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A0);
    // 0x800AA570: nop

    // 0x800AA574: subu        $t6, $t8, $t3
    ctx->r14 = SUB32(ctx->r24, ctx->r11);
    // 0x800AA578: sw          $t6, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r14;
    // 0x800AA57C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800AA580: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA584: nop

    // 0x800AA588: swc1        $f10, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->f10.u32l;
    // 0x800AA58C: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800AA590: lw          $t1, 0x1B8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AA594: nop

    // 0x800AA598: subu        $t7, $t2, $t1
    ctx->r15 = SUB32(ctx->r10, ctx->r9);
    // 0x800AA59C: sw          $t7, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r15;
    // 0x800AA5A0: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AA5A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA5A8: nop

    // 0x800AA5AC: swc1        $f18, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->f18.u32l;
    // 0x800AA5B0: lw          $t9, 0x1D0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D0);
    // 0x800AA5B4: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AA5B8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800AA5BC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800AA5C0: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AA5C4: lwc1        $f16, 0x1E0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1E0);
    // 0x800AA5C8: lwc1        $f10, 0x144($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800AA5CC: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AA5D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA5D4: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AA5D8: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800AA5DC: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800AA5E0: swc1        $f4, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f4.u32l;
    // 0x800AA5E4: lwc1        $f10, 0x1A8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x800AA5E8: lwc1        $f16, 0x14C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AA5EC: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA5F0: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AA5F4: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800AA5F8: swc1        $f8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f8.u32l;
    // 0x800AA5FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AA600: nop

    // 0x800AA604: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
    // 0x800AA608: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA60C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800AA610: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AA614: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800AA618: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x800AA61C: nop

    // 0x800AA620: bc1f        L_800AA64C
    if (!c1cs) {
        // 0x800AA624: nop

            goto L_800AA64C;
    }
    // 0x800AA624: nop

    // 0x800AA628: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA62C: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AA630: nop

    // 0x800AA634: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AA638: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800AA63C: swc1        $f10, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f10.u32l;
    // 0x800AA640: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AA644: b           L_800AA6A0
    // 0x800AA648: swc1        $f16, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f16.u32l;
        goto L_800AA6A0;
    // 0x800AA648: swc1        $f16, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f16.u32l;
L_800AA64C:
    // 0x800AA64C: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA650: lui         $at, 0x4074
    ctx->r1 = S32(0X4074 << 16);
    // 0x800AA654: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800AA658: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AA65C: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800AA660: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x800AA664: nop

    // 0x800AA668: bc1f        L_800AA6A0
    if (!c1cs) {
        // 0x800AA66C: nop

            goto L_800AA6A0;
    }
    // 0x800AA66C: nop

    // 0x800AA670: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AA674: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA678: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA67C: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AA680: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800AA684: nop

    // 0x800AA688: div.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AA68C: swc1        $f18, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f18.u32l;
    // 0x800AA690: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AA694: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA698: nop

    // 0x800AA69C: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
L_800AA6A0:
    // 0x800AA6A0: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AA6A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AA6A8: nop

    // 0x800AA6AC: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800AA6B0: nop

    // 0x800AA6B4: bc1f        L_800AA6C8
    if (!c1cs) {
        // 0x800AA6B8: nop

            goto L_800AA6C8;
    }
    // 0x800AA6B8: nop

    // 0x800AA6BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AA6C0: b           L_800AA6F8
    // 0x800AA6C4: swc1        $f16, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f16.u32l;
        goto L_800AA6F8;
    // 0x800AA6C4: swc1        $f16, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f16.u32l;
L_800AA6C8:
    // 0x800AA6C8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AA6CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA6D0: lwc1        $f6, 0x164($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AA6D4: nop

    // 0x800AA6D8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800AA6DC: nop

    // 0x800AA6E0: bc1f        L_800AA6F8
    if (!c1cs) {
        // 0x800AA6E4: nop

            goto L_800AA6F8;
    }
    // 0x800AA6E4: nop

    // 0x800AA6E8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AA6EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA6F0: nop

    // 0x800AA6F4: swc1        $f8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f8.u32l;
L_800AA6F8:
    // 0x800AA6F8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA6FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA700: lwc1        $f4, 0x16C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AA704: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800AA708: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AA70C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AA710: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AA714: nop

    // 0x800AA718: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AA71C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AA720: nop

    // 0x800AA724: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x800AA728: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800AA72C: beq         $t0, $zero, L_800AA780
    if (ctx->r8 == 0) {
        // 0x800AA730: nop

            goto L_800AA780;
    }
    // 0x800AA730: nop

    // 0x800AA734: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AA738: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA73C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800AA740: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AA744: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AA748: nop

    // 0x800AA74C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AA750: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AA754: nop

    // 0x800AA758: andi        $at, $t0, 0x4
    ctx->r1 = ctx->r8 & 0X4;
    // 0x800AA75C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800AA760: bne         $t0, $zero, L_800AA778
    if (ctx->r8 != 0) {
        // 0x800AA764: nop

            goto L_800AA778;
    }
    // 0x800AA764: nop

    // 0x800AA768: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800AA76C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA770: b           L_800AA790
    // 0x800AA774: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800AA790;
    // 0x800AA774: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800AA778:
    // 0x800AA778: b           L_800AA790
    // 0x800AA77C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800AA790;
    // 0x800AA77C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800AA780:
    // 0x800AA780: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800AA784: nop

    // 0x800AA788: bltz        $t0, L_800AA778
    if (SIGNED(ctx->r8) < 0) {
        // 0x800AA78C: nop

            goto L_800AA778;
    }
    // 0x800AA78C: nop

L_800AA790:
    // 0x800AA790: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AA794: sw          $t0, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r8;
    // 0x800AA798: nop

    // 0x800AA79C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA7A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA7A4: lwc1        $f18, 0x164($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AA7A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800AA7AC: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AA7B0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AA7B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AA7B8: nop

    // 0x800AA7BC: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AA7C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AA7C4: nop

    // 0x800AA7C8: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800AA7CC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800AA7D0: beq         $t8, $zero, L_800AA824
    if (ctx->r24 == 0) {
        // 0x800AA7D4: nop

            goto L_800AA824;
    }
    // 0x800AA7D4: nop

    // 0x800AA7D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AA7DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA7E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800AA7E4: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800AA7E8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AA7EC: nop

    // 0x800AA7F0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AA7F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AA7F8: nop

    // 0x800AA7FC: andi        $at, $t8, 0x4
    ctx->r1 = ctx->r24 & 0X4;
    // 0x800AA800: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800AA804: bne         $t8, $zero, L_800AA81C
    if (ctx->r24 != 0) {
        // 0x800AA808: nop

            goto L_800AA81C;
    }
    // 0x800AA808: nop

    // 0x800AA80C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800AA810: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA814: b           L_800AA834
    // 0x800AA818: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800AA834;
    // 0x800AA818: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800AA81C:
    // 0x800AA81C: b           L_800AA834
    // 0x800AA820: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800AA834;
    // 0x800AA820: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800AA824:
    // 0x800AA824: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800AA828: nop

    // 0x800AA82C: bltz        $t8, L_800AA81C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800AA830: nop

            goto L_800AA81C;
    }
    // 0x800AA830: nop

L_800AA834:
    // 0x800AA834: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AA838: sw          $t8, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r24;
    // 0x800AA83C: nop

    // 0x800AA840: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AA844: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA848: lwc1        $f16, 0x158($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X158);
    // 0x800AA84C: nop

    // 0x800AA850: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AA854: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AA858: nop

    // 0x800AA85C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AA860: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AA864: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AA868: nop

    // 0x800AA86C: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AA870: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800AA874: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AA878: sh          $t6, 0x15E($sp)
    MEM_H(0X15E, ctx->r29) = ctx->r14;
    // 0x800AA87C: nop

    // 0x800AA880: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x800AA884: lw          $t1, 0x174($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X174);
    // 0x800AA888: nop

    // 0x800AA88C: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
    // 0x800AA890: beq         $at, $zero, L_800AAFB4
    if (ctx->r1 == 0) {
        // 0x800AA894: nop

            goto L_800AAFB4;
    }
    // 0x800AA894: nop

    // 0x800AA898: lw          $t7, 0x1CC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1CC);
    // 0x800AA89C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800AA8A0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800AA8A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA8A8: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AA8AC: lwc1        $f10, 0x1E4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1E4);
    // 0x800AA8B0: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AA8B4: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800AA8B8: lwc1        $f10, 0x140($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800AA8BC: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AA8C0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AA8C4: sub.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AA8C8: swc1        $f18, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f18.u32l;
    // 0x800AA8CC: lwc1        $f8, 0x1A4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1A4);
    // 0x800AA8D0: lwc1        $f4, 0x148($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AA8D4: lwc1        $f16, 0x168($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA8D8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AA8DC: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AA8E0: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
    // 0x800AA8E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AA8E8: nop

    // 0x800AA8EC: swc1        $f18, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f18.u32l;
    // 0x800AA8F0: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA8F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AA8F8: nop

    // 0x800AA8FC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800AA900: nop

    // 0x800AA904: bc1f        L_800AA930
    if (!c1cs) {
        // 0x800AA908: nop

            goto L_800AA930;
    }
    // 0x800AA908: nop

    // 0x800AA90C: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA910: lwc1        $f6, 0x148($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AA914: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800AA918: nop

    // 0x800AA91C: div.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AA920: swc1        $f18, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f18.u32l;
    // 0x800AA924: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AA928: b           L_800AA980
    // 0x800AA92C: swc1        $f8, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f8.u32l;
        goto L_800AA980;
    // 0x800AA92C: swc1        $f8, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f8.u32l;
L_800AA930:
    // 0x800AA930: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA934: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA938: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA93C: nop

    // 0x800AA940: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800AA944: nop

    // 0x800AA948: bc1f        L_800AA980
    if (!c1cs) {
        // 0x800AA94C: nop

            goto L_800AA980;
    }
    // 0x800AA94C: nop

    // 0x800AA950: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA954: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AA958: lwc1        $f6, 0x168($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA95C: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AA960: sub.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AA964: nop

    // 0x800AA968: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AA96C: swc1        $f4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f4.u32l;
    // 0x800AA970: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA974: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA978: nop

    // 0x800AA97C: swc1        $f10, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f10.u32l;
L_800AA980:
    // 0x800AA980: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AA984: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AA988: nop

    // 0x800AA98C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800AA990: nop

    // 0x800AA994: bc1f        L_800AA9A8
    if (!c1cs) {
        // 0x800AA998: nop

            goto L_800AA9A8;
    }
    // 0x800AA998: nop

    // 0x800AA99C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AA9A0: b           L_800AA9D8
    // 0x800AA9A4: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
        goto L_800AA9D8;
    // 0x800AA9A4: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
L_800AA9A8:
    // 0x800AA9A8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA9AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA9B0: lwc1        $f8, 0x160($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AA9B4: nop

    // 0x800AA9B8: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800AA9BC: nop

    // 0x800AA9C0: bc1f        L_800AA9D8
    if (!c1cs) {
        // 0x800AA9C4: nop

            goto L_800AA9D8;
    }
    // 0x800AA9C4: nop

    // 0x800AA9C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AA9CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AA9D0: nop

    // 0x800AA9D4: swc1        $f10, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f10.u32l;
L_800AA9D8:
    // 0x800AA9D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA9DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA9E0: lwc1        $f16, 0x168($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AA9E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AA9E8: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AA9EC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AA9F0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AA9F4: nop

    // 0x800AA9F8: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AA9FC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AAA00: nop

    // 0x800AAA04: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800AAA08: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800AAA0C: beq         $t5, $zero, L_800AAA60
    if (ctx->r13 == 0) {
        // 0x800AAA10: nop

            goto L_800AAA60;
    }
    // 0x800AAA10: nop

    // 0x800AAA14: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AAA18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AAA1C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AAA20: sub.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f8.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800AAA24: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AAA28: nop

    // 0x800AAA2C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AAA30: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AAA34: nop

    // 0x800AAA38: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800AAA3C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800AAA40: bne         $t5, $zero, L_800AAA58
    if (ctx->r13 != 0) {
        // 0x800AAA44: nop

            goto L_800AAA58;
    }
    // 0x800AAA44: nop

    // 0x800AAA48: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800AAA4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AAA50: b           L_800AAA70
    // 0x800AAA54: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800AAA70;
    // 0x800AAA54: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800AAA58:
    // 0x800AAA58: b           L_800AAA70
    // 0x800AAA5C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800AAA70;
    // 0x800AAA5C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_800AAA60:
    // 0x800AAA60: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800AAA64: nop

    // 0x800AAA68: bltz        $t5, L_800AAA58
    if (SIGNED(ctx->r13) < 0) {
        // 0x800AAA6C: nop

            goto L_800AAA58;
    }
    // 0x800AAA6C: nop

L_800AAA70:
    // 0x800AAA70: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AAA74: sw          $t5, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r13;
    // 0x800AAA78: nop

    // 0x800AAA7C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AAA80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AAA84: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AAA88: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800AAA8C: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AAA90: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AAA94: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AAA98: nop

    // 0x800AAA9C: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AAAA0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AAAA4: nop

    // 0x800AAAA8: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x800AAAAC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800AAAB0: beq         $t4, $zero, L_800AAB04
    if (ctx->r12 == 0) {
        // 0x800AAAB4: nop

            goto L_800AAB04;
    }
    // 0x800AAAB4: nop

    // 0x800AAAB8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AAABC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AAAC0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800AAAC4: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AAAC8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AAACC: nop

    // 0x800AAAD0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AAAD4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AAAD8: nop

    // 0x800AAADC: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x800AAAE0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800AAAE4: bne         $t4, $zero, L_800AAAFC
    if (ctx->r12 != 0) {
        // 0x800AAAE8: nop

            goto L_800AAAFC;
    }
    // 0x800AAAE8: nop

    // 0x800AAAEC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800AAAF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AAAF4: b           L_800AAB14
    // 0x800AAAF8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800AAB14;
    // 0x800AAAF8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800AAAFC:
    // 0x800AAAFC: b           L_800AAB14
    // 0x800AAB00: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800AAB14;
    // 0x800AAB00: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800AAB04:
    // 0x800AAB04: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800AAB08: nop

    // 0x800AAB0C: bltz        $t4, L_800AAAFC
    if (SIGNED(ctx->r12) < 0) {
        // 0x800AAB10: nop

            goto L_800AAAFC;
    }
    // 0x800AAB10: nop

L_800AAB14:
    // 0x800AAB14: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AAB18: sw          $t4, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r12;
    // 0x800AAB1C: nop

    // 0x800AAB20: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AAB24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AAB28: lwc1        $f18, 0x154($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800AAB2C: nop

    // 0x800AAB30: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AAB34: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AAB38: nop

    // 0x800AAB3C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AAB40: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AAB44: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AAB48: nop

    // 0x800AAB4C: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AAB50: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800AAB54: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AAB58: sh          $t3, 0x15C($sp)
    MEM_H(0X15C, ctx->r29) = ctx->r11;
    // 0x800AAB5C: nop

    // 0x800AAB60: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x800AAB64: lw          $t2, 0x170($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X170);
    // 0x800AAB68: nop

    // 0x800AAB6C: sltu        $at, $t6, $t2
    ctx->r1 = ctx->r14 < ctx->r10 ? 1 : 0;
    // 0x800AAB70: bne         $at, $zero, L_800AABAC
    if (ctx->r1 != 0) {
        // 0x800AAB74: nop

            goto L_800AABAC;
    }
    // 0x800AAB74: nop

    // 0x800AAB78: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAB7C: nop

    // 0x800AAB80: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800AAB84: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AAB88: sw          $t1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r9;
    // 0x800AAB8C: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800AAB90: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800AAB94: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800AAB98: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800AAB9C: nop

    // 0x800AABA0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800AABA4: b           L_800AAFB4
    // 0x800AABA8: nop

        goto L_800AAFB4;
    // 0x800AABA8: nop

L_800AABAC:
    // 0x800AABAC: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AABB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AABB4: lh          $t8, 0x116($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X116);
    // 0x800AABB8: nop

    // 0x800AABBC: bne         $t8, $at, L_800AAD34
    if (ctx->r24 != ctx->r1) {
        // 0x800AABC0: nop

            goto L_800AAD34;
    }
    // 0x800AABC0: nop

    // 0x800AABC4: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AABC8: nop

    // 0x800AABCC: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800AABD0: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AABD4: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
    // 0x800AABD8: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x800AABDC: lui         $t2, 0xFD50
    ctx->r10 = S32(0XFD50 << 16);
    // 0x800AABE0: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800AABE4: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AABE8: lhu         $t5, 0x182($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X182);
    // 0x800AABEC: lw          $t9, 0x128($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X128);
    // 0x800AABF0: sll         $t0, $t5, 6
    ctx->r8 = S32(ctx->r13 << 6);
    // 0x800AABF4: sll         $t4, $t0, 5
    ctx->r12 = S32(ctx->r8 << 5);
    // 0x800AABF8: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800AABFC: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x800AAC00: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800AAC04: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x800AAC08: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x800AAC0C: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x800AAC10: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAC14: nop

    // 0x800AAC18: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x800AAC1C: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800AAC20: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x800AAC24: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x800AAC28: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x800AAC2C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AAC30: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x800AAC34: lui         $t0, 0x709
    ctx->r8 = S32(0X709 << 16);
    // 0x800AAC38: ori         $t0, $t0, 0x4160
    ctx->r8 = ctx->r8 | 0X4160;
    // 0x800AAC3C: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800AAC40: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAC44: nop

    // 0x800AAC48: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800AAC4C: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AAC50: sw          $t4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r12;
    // 0x800AAC54: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800AAC58: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x800AAC5C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AAC60: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800AAC64: nop

    // 0x800AAC68: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800AAC6C: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAC70: nop

    // 0x800AAC74: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800AAC78: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AAC7C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800AAC80: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x800AAC84: lui         $t5, 0xF300
    ctx->r13 = S32(0XF300 << 16);
    // 0x800AAC88: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AAC8C: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x800AAC90: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x800AAC94: ori         $t9, $t9, 0xF100
    ctx->r25 = ctx->r25 | 0XF100;
    // 0x800AAC98: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x800AAC9C: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AACA0: nop

    // 0x800AACA4: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x800AACA8: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800AACAC: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x800AACB0: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x800AACB4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800AACB8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800AACBC: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x800AACC0: nop

    // 0x800AACC4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AACC8: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AACCC: nop

    // 0x800AACD0: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AACD4: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AACD8: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x800AACDC: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800AACE0: lui         $t0, 0xF548
    ctx->r8 = S32(0XF548 << 16);
    // 0x800AACE4: ori         $t0, $t0, 0x1000
    ctx->r8 = ctx->r8 | 0X1000;
    // 0x800AACE8: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800AACEC: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800AACF0: lui         $t4, 0x9
    ctx->r12 = S32(0X9 << 16);
    // 0x800AACF4: ori         $t4, $t4, 0x4160
    ctx->r12 = ctx->r12 | 0X4160;
    // 0x800AACF8: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x800AACFC: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAD00: nop

    // 0x800AAD04: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800AAD08: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AAD0C: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x800AAD10: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x800AAD14: lui         $t2, 0xF200
    ctx->r10 = S32(0XF200 << 16);
    // 0x800AAD18: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800AAD1C: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x800AAD20: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x800AAD24: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x800AAD28: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800AAD2C: b           L_800AAEAC
    // 0x800AAD30: nop

        goto L_800AAEAC;
    // 0x800AAD30: nop

L_800AAD34:
    // 0x800AAD34: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AAD38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AAD3C: lh          $t9, 0x116($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X116);
    // 0x800AAD40: nop

    // 0x800AAD44: bne         $t9, $at, L_800AAEAC
    if (ctx->r25 != ctx->r1) {
        // 0x800AAD48: nop

            goto L_800AAEAC;
    }
    // 0x800AAD48: nop

    // 0x800AAD4C: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAD50: nop

    // 0x800AAD54: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800AAD58: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AAD5C: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x800AAD60: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800AAD64: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x800AAD68: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AAD6C: lhu         $t7, 0x182($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X182);
    // 0x800AAD70: lw          $t2, 0x1DC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AAD74: sll         $t5, $t7, 6
    ctx->r13 = S32(ctx->r15 << 6);
    // 0x800AAD78: lw          $t1, 0x128($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X128);
    // 0x800AAD7C: sll         $t0, $t5, 5
    ctx->r8 = S32(ctx->r13 << 5);
    // 0x800AAD80: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800AAD84: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x800AAD88: addu        $t4, $t1, $t9
    ctx->r12 = ADD32(ctx->r9, ctx->r25);
    // 0x800AAD8C: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x800AAD90: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAD94: nop

    // 0x800AAD98: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x800AAD9C: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AADA0: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x800AADA4: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x800AADA8: lui         $t2, 0xF510
    ctx->r10 = S32(0XF510 << 16);
    // 0x800AADAC: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800AADB0: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x800AADB4: lui         $t5, 0x705
    ctx->r13 = S32(0X705 << 16);
    // 0x800AADB8: ori         $t5, $t5, 0x4160
    ctx->r13 = ctx->r13 | 0X4160;
    // 0x800AADBC: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800AADC0: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AADC4: nop

    // 0x800AADC8: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x800AADCC: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800AADD0: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x800AADD4: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800AADD8: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800AADDC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x800AADE0: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800AADE4: nop

    // 0x800AADE8: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800AADEC: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AADF0: nop

    // 0x800AADF4: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x800AADF8: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800AADFC: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x800AAE00: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x800AAE04: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800AAE08: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AAE0C: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800AAE10: lui         $t0, 0x77F
    ctx->r8 = S32(0X77F << 16);
    // 0x800AAE14: ori         $t0, $t0, 0xF080
    ctx->r8 = ctx->r8 | 0XF080;
    // 0x800AAE18: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800AAE1C: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAE20: nop

    // 0x800AAE24: addiu       $t4, $t9, 0x8
    ctx->r12 = ADD32(ctx->r25, 0X8);
    // 0x800AAE28: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800AAE2C: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x800AAE30: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800AAE34: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AAE38: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x800AAE3C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800AAE40: nop

    // 0x800AAE44: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800AAE48: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAE4C: nop

    // 0x800AAE50: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800AAE54: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AAE58: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x800AAE5C: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800AAE60: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x800AAE64: ori         $t5, $t5, 0x2000
    ctx->r13 = ctx->r13 | 0X2000;
    // 0x800AAE68: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AAE6C: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x800AAE70: lui         $t1, 0x5
    ctx->r9 = S32(0X5 << 16);
    // 0x800AAE74: ori         $t1, $t1, 0x4160
    ctx->r9 = ctx->r9 | 0X4160;
    // 0x800AAE78: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x800AAE7C: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAE80: nop

    // 0x800AAE84: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x800AAE88: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AAE8C: sw          $t4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r12;
    // 0x800AAE90: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800AAE94: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x800AAE98: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AAE9C: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x800AAEA0: lui         $t2, 0xF
    ctx->r10 = S32(0XF << 16);
    // 0x800AAEA4: ori         $t2, $t2, 0xC07C
    ctx->r10 = ctx->r10 | 0XC07C;
    // 0x800AAEA8: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
L_800AAEAC:
    // 0x800AAEAC: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAEB0: nop

    // 0x800AAEB4: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800AAEB8: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800AAEBC: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800AAEC0: lw          $t1, 0x174($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X174);
    // 0x800AAEC4: lw          $t3, 0x170($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X170);
    // 0x800AAEC8: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x800AAECC: sll         $t4, $t9, 12
    ctx->r12 = S32(ctx->r25 << 12);
    // 0x800AAED0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800AAED4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800AAED8: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x800AAEDC: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x800AAEE0: or          $t2, $t8, $t6
    ctx->r10 = ctx->r24 | ctx->r14;
    // 0x800AAEE4: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800AAEE8: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800AAEEC: lw          $t9, 0x178($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X178);
    // 0x800AAEF0: andi        $t0, $t5, 0xFFF
    ctx->r8 = ctx->r13 & 0XFFF;
    // 0x800AAEF4: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800AAEF8: sll         $t1, $t0, 12
    ctx->r9 = S32(ctx->r8 << 12);
    // 0x800AAEFC: andi        $t4, $t9, 0xFFF
    ctx->r12 = ctx->r25 & 0XFFF;
    // 0x800AAF00: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x800AAF04: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x800AAF08: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAF0C: nop

    // 0x800AAF10: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x800AAF14: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800AAF18: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x800AAF1C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800AAF20: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x800AAF24: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AAF28: lh          $t0, 0x15E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X15E);
    // 0x800AAF2C: lh          $t4, 0x15C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X15C);
    // 0x800AAF30: andi        $t9, $t0, 0xFFFF
    ctx->r25 = ctx->r8 & 0XFFFF;
    // 0x800AAF34: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800AAF38: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x800AAF3C: andi        $t3, $t4, 0xFFFF
    ctx->r11 = ctx->r12 & 0XFFFF;
    // 0x800AAF40: or          $t8, $t1, $t3
    ctx->r24 = ctx->r9 | ctx->r11;
    // 0x800AAF44: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x800AAF48: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAF4C: nop

    // 0x800AAF50: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800AAF54: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AAF58: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x800AAF5C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800AAF60: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x800AAF64: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AAF68: lh          $t9, 0x152($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X152);
    // 0x800AAF6C: lh          $t3, 0x150($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X150);
    // 0x800AAF70: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800AAF74: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x800AAF78: sll         $t1, $t4, 16
    ctx->r9 = S32(ctx->r12 << 16);
    // 0x800AAF7C: andi        $t8, $t3, 0xFFFF
    ctx->r24 = ctx->r11 & 0XFFFF;
    // 0x800AAF80: or          $t6, $t1, $t8
    ctx->r14 = ctx->r9 | ctx->r24;
    // 0x800AAF84: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x800AAF88: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AAF8C: nop

    // 0x800AAF90: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AAF94: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AAF98: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x800AAF9C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800AAFA0: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800AAFA4: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800AAFA8: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800AAFAC: nop

    // 0x800AAFB0: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
L_800AAFB4:
    // 0x800AAFB4: b           L_800ABA00
    // 0x800AAFB8: nop

        goto L_800ABA00;
    // 0x800AAFB8: nop

L_800AAFBC:
    // 0x800AAFBC: lw          $t3, 0x1C0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C0);
    // 0x800AAFC0: lw          $t1, 0x1A0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A0);
    // 0x800AAFC4: nop

    // 0x800AAFC8: subu        $t8, $t3, $t1
    ctx->r24 = SUB32(ctx->r11, ctx->r9);
    // 0x800AAFCC: sw          $t8, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r24;
    // 0x800AAFD0: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800AAFD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AAFD8: nop

    // 0x800AAFDC: swc1        $f16, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->f16.u32l;
    // 0x800AAFE0: lw          $t6, 0x19C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X19C);
    // 0x800AAFE4: lw          $t2, 0x1B8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B8);
    // 0x800AAFE8: nop

    // 0x800AAFEC: subu        $t7, $t6, $t2
    ctx->r15 = SUB32(ctx->r14, ctx->r10);
    // 0x800AAFF0: sw          $t7, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r15;
    // 0x800AAFF4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AAFF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AAFFC: nop

    // 0x800AB000: swc1        $f6, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->f6.u32l;
    // 0x800AB004: lw          $t5, 0x1D0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D0);
    // 0x800AB008: lwc1        $f4, 0x14C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AB00C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800AB010: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800AB014: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AB018: lwc1        $f18, 0x1E0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1E0);
    // 0x800AB01C: lwc1        $f16, 0x144($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800AB020: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800AB024: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AB028: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AB02C: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800AB030: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AB034: swc1        $f10, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f10.u32l;
    // 0x800AB038: lwc1        $f16, 0x1A8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x800AB03C: lwc1        $f18, 0x14C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AB040: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB044: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AB048: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AB04C: swc1        $f4, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f4.u32l;
    // 0x800AB050: lwc1        $f10, 0x1A8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x800AB054: nop

    // 0x800AB058: swc1        $f10, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f10.u32l;
    // 0x800AB05C: lwc1        $f16, 0x16C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB060: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800AB064: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AB068: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AB06C: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x800AB070: nop

    // 0x800AB074: bc1f        L_800AB0A0
    if (!c1cs) {
        // 0x800AB078: nop

            goto L_800AB0A0;
    }
    // 0x800AB078: nop

    // 0x800AB07C: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB080: lwc1        $f4, 0x14C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AB084: lwc1        $f16, 0x1A8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x800AB088: div.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AB08C: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800AB090: swc1        $f18, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f18.u32l;
    // 0x800AB094: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AB098: b           L_800AB0F4
    // 0x800AB09C: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
        goto L_800AB0F4;
    // 0x800AB09C: swc1        $f8, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f8.u32l;
L_800AB0A0:
    // 0x800AB0A0: lwc1        $f6, 0x16C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB0A4: lui         $at, 0x4074
    ctx->r1 = S32(0X4074 << 16);
    // 0x800AB0A8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800AB0AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AB0B0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x800AB0B4: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x800AB0B8: nop

    // 0x800AB0BC: bc1f        L_800AB0F4
    if (!c1cs) {
        // 0x800AB0C0: nop

            goto L_800AB0F4;
    }
    // 0x800AB0C0: nop

    // 0x800AB0C4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AB0C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AB0CC: lwc1        $f18, 0x16C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB0D0: lwc1        $f6, 0x14C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800AB0D4: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AB0D8: nop

    // 0x800AB0DC: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AB0E0: swc1        $f4, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f4.u32l;
    // 0x800AB0E4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AB0E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB0EC: nop

    // 0x800AB0F0: swc1        $f16, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->f16.u32l;
L_800AB0F4:
    // 0x800AB0F4: lwc1        $f10, 0x164($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AB0F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AB0FC: nop

    // 0x800AB100: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x800AB104: nop

    // 0x800AB108: bc1f        L_800AB11C
    if (!c1cs) {
        // 0x800AB10C: nop

            goto L_800AB11C;
    }
    // 0x800AB10C: nop

    // 0x800AB110: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AB114: b           L_800AB14C
    // 0x800AB118: swc1        $f8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f8.u32l;
        goto L_800AB14C;
    // 0x800AB118: swc1        $f8, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f8.u32l;
L_800AB11C:
    // 0x800AB11C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AB120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB124: lwc1        $f6, 0x164($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AB128: nop

    // 0x800AB12C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800AB130: nop

    // 0x800AB134: bc1f        L_800AB14C
    if (!c1cs) {
        // 0x800AB138: nop

            goto L_800AB14C;
    }
    // 0x800AB138: nop

    // 0x800AB13C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AB140: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB144: nop

    // 0x800AB148: swc1        $f16, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->f16.u32l;
L_800AB14C:
    // 0x800AB14C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AB150: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB154: lwc1        $f10, 0x16C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x800AB158: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AB15C: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AB160: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AB164: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AB168: nop

    // 0x800AB16C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AB170: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AB174: nop

    // 0x800AB178: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800AB17C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AB180: beq         $t9, $zero, L_800AB1D4
    if (ctx->r25 == 0) {
        // 0x800AB184: nop

            goto L_800AB1D4;
    }
    // 0x800AB184: nop

    // 0x800AB188: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AB18C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AB190: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AB194: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AB198: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AB19C: nop

    // 0x800AB1A0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AB1A4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AB1A8: nop

    // 0x800AB1AC: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800AB1B0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AB1B4: bne         $t9, $zero, L_800AB1CC
    if (ctx->r25 != 0) {
        // 0x800AB1B8: nop

            goto L_800AB1CC;
    }
    // 0x800AB1B8: nop

    // 0x800AB1BC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800AB1C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AB1C4: b           L_800AB1E4
    // 0x800AB1C8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800AB1E4;
    // 0x800AB1C8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800AB1CC:
    // 0x800AB1CC: b           L_800AB1E4
    // 0x800AB1D0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800AB1E4;
    // 0x800AB1D0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800AB1D4:
    // 0x800AB1D4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800AB1D8: nop

    // 0x800AB1DC: bltz        $t9, L_800AB1CC
    if (SIGNED(ctx->r25) < 0) {
        // 0x800AB1E0: nop

            goto L_800AB1CC;
    }
    // 0x800AB1E0: nop

L_800AB1E4:
    // 0x800AB1E4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AB1E8: sw          $t9, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r25;
    // 0x800AB1EC: nop

    // 0x800AB1F0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AB1F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB1F8: lwc1        $f4, 0x164($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X164);
    // 0x800AB1FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB200: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800AB204: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AB208: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB20C: nop

    // 0x800AB210: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AB214: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB218: nop

    // 0x800AB21C: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800AB220: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AB224: beq         $t3, $zero, L_800AB278
    if (ctx->r11 == 0) {
        // 0x800AB228: nop

            goto L_800AB278;
    }
    // 0x800AB228: nop

    // 0x800AB22C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AB230: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB234: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB238: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AB23C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB240: nop

    // 0x800AB244: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AB248: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB24C: nop

    // 0x800AB250: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800AB254: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AB258: bne         $t3, $zero, L_800AB270
    if (ctx->r11 != 0) {
        // 0x800AB25C: nop

            goto L_800AB270;
    }
    // 0x800AB25C: nop

    // 0x800AB260: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800AB264: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AB268: b           L_800AB288
    // 0x800AB26C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800AB288;
    // 0x800AB26C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800AB270:
    // 0x800AB270: b           L_800AB288
    // 0x800AB274: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800AB288;
    // 0x800AB274: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800AB278:
    // 0x800AB278: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800AB27C: nop

    // 0x800AB280: bltz        $t3, L_800AB270
    if (SIGNED(ctx->r11) < 0) {
        // 0x800AB284: nop

            goto L_800AB270;
    }
    // 0x800AB284: nop

L_800AB288:
    // 0x800AB288: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AB28C: sw          $t3, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r11;
    // 0x800AB290: nop

    // 0x800AB294: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AB298: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AB29C: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x800AB2A0: nop

    // 0x800AB2A4: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AB2A8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AB2AC: nop

    // 0x800AB2B0: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AB2B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB2B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB2BC: nop

    // 0x800AB2C0: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AB2C4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800AB2C8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AB2CC: sh          $t8, 0x15E($sp)
    MEM_H(0X15E, ctx->r29) = ctx->r24;
    // 0x800AB2D0: nop

    // 0x800AB2D4: lw          $t6, 0x17C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X17C);
    // 0x800AB2D8: lw          $t2, 0x174($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X174);
    // 0x800AB2DC: nop

    // 0x800AB2E0: sltu        $at, $t6, $t2
    ctx->r1 = ctx->r14 < ctx->r10 ? 1 : 0;
    // 0x800AB2E4: beq         $at, $zero, L_800ABA00
    if (ctx->r1 == 0) {
        // 0x800AB2E8: nop

            goto L_800ABA00;
    }
    // 0x800AB2E8: nop

    // 0x800AB2EC: lw          $t7, 0x1CC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1CC);
    // 0x800AB2F0: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AB2F4: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800AB2F8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800AB2FC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800AB300: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AB304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AB308: lwc1        $f4, 0x140($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X140);
    // 0x800AB30C: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800AB310: lwc1        $f18, 0x1E4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1E4);
    // 0x800AB314: sub.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AB318: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AB31C: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800AB320: swc1        $f6, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f6.u32l;
    // 0x800AB324: lwc1        $f4, 0x1A4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1A4);
    // 0x800AB328: lwc1        $f10, 0x148($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AB32C: lwc1        $f16, 0x168($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB330: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800AB334: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AB338: swc1        $f8, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f8.u32l;
    // 0x800AB33C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AB340: nop

    // 0x800AB344: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
    // 0x800AB348: lwc1        $f4, 0x168($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB34C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800AB350: nop

    // 0x800AB354: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800AB358: nop

    // 0x800AB35C: bc1f        L_800AB388
    if (!c1cs) {
        // 0x800AB360: nop

            goto L_800AB388;
    }
    // 0x800AB360: nop

    // 0x800AB364: lwc1        $f18, 0x168($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB368: lwc1        $f8, 0x148($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AB36C: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = -ctx->f18.fl;
    // 0x800AB370: nop

    // 0x800AB374: div.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AB378: swc1        $f6, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f6.u32l;
    // 0x800AB37C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AB380: b           L_800AB3D8
    // 0x800AB384: swc1        $f4, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f4.u32l;
        goto L_800AB3D8;
    // 0x800AB384: swc1        $f4, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f4.u32l;
L_800AB388:
    // 0x800AB388: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB38C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB390: lwc1        $f10, 0x168($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB394: nop

    // 0x800AB398: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x800AB39C: nop

    // 0x800AB3A0: bc1f        L_800AB3D8
    if (!c1cs) {
        // 0x800AB3A4: nop

            goto L_800AB3D8;
    }
    // 0x800AB3A4: nop

    // 0x800AB3A8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB3AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AB3B0: lwc1        $f8, 0x168($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB3B4: lwc1        $f4, 0x148($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X148);
    // 0x800AB3B8: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800AB3BC: nop

    // 0x800AB3C0: div.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AB3C4: swc1        $f10, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f10.u32l;
    // 0x800AB3C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB3CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB3D0: nop

    // 0x800AB3D4: swc1        $f18, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->f18.u32l;
L_800AB3D8:
    // 0x800AB3D8: lwc1        $f16, 0x160($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AB3DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AB3E0: nop

    // 0x800AB3E4: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800AB3E8: nop

    // 0x800AB3EC: bc1f        L_800AB400
    if (!c1cs) {
        // 0x800AB3F0: nop

            goto L_800AB400;
    }
    // 0x800AB3F0: nop

    // 0x800AB3F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AB3F8: b           L_800AB430
    // 0x800AB3FC: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
        goto L_800AB430;
    // 0x800AB3FC: swc1        $f6, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f6.u32l;
L_800AB400:
    // 0x800AB400: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB404: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AB408: lwc1        $f4, 0x160($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AB40C: nop

    // 0x800AB410: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800AB414: nop

    // 0x800AB418: bc1f        L_800AB430
    if (!c1cs) {
        // 0x800AB41C: nop

            goto L_800AB430;
    }
    // 0x800AB41C: nop

    // 0x800AB420: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AB424: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB428: nop

    // 0x800AB42C: swc1        $f18, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->f18.u32l;
L_800AB430:
    // 0x800AB430: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AB434: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AB438: lwc1        $f16, 0x168($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X168);
    // 0x800AB43C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AB440: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AB444: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AB448: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AB44C: nop

    // 0x800AB450: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AB454: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AB458: nop

    // 0x800AB45C: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800AB460: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AB464: beq         $t9, $zero, L_800AB4B8
    if (ctx->r25 == 0) {
        // 0x800AB468: nop

            goto L_800AB4B8;
    }
    // 0x800AB468: nop

    // 0x800AB46C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AB470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB474: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AB478: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AB47C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AB480: nop

    // 0x800AB484: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AB488: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AB48C: nop

    // 0x800AB490: andi        $at, $t9, 0x4
    ctx->r1 = ctx->r25 & 0X4;
    // 0x800AB494: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800AB498: bne         $t9, $zero, L_800AB4B0
    if (ctx->r25 != 0) {
        // 0x800AB49C: nop

            goto L_800AB4B0;
    }
    // 0x800AB49C: nop

    // 0x800AB4A0: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800AB4A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AB4A8: b           L_800AB4C8
    // 0x800AB4AC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800AB4C8;
    // 0x800AB4AC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800AB4B0:
    // 0x800AB4B0: b           L_800AB4C8
    // 0x800AB4B4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800AB4C8;
    // 0x800AB4B4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800AB4B8:
    // 0x800AB4B8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800AB4BC: nop

    // 0x800AB4C0: bltz        $t9, L_800AB4B0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800AB4C4: nop

            goto L_800AB4B0;
    }
    // 0x800AB4C4: nop

L_800AB4C8:
    // 0x800AB4C8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AB4CC: sw          $t9, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r25;
    // 0x800AB4D0: nop

    // 0x800AB4D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AB4D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AB4DC: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x800AB4E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB4E4: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AB4E8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AB4EC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB4F0: nop

    // 0x800AB4F4: cvt.w.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AB4F8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB4FC: nop

    // 0x800AB500: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800AB504: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AB508: beq         $t3, $zero, L_800AB55C
    if (ctx->r11 == 0) {
        // 0x800AB50C: nop

            goto L_800AB55C;
    }
    // 0x800AB50C: nop

    // 0x800AB510: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AB514: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AB518: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AB51C: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800AB520: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AB524: nop

    // 0x800AB528: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AB52C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AB530: nop

    // 0x800AB534: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800AB538: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800AB53C: bne         $t3, $zero, L_800AB554
    if (ctx->r11 != 0) {
        // 0x800AB540: nop

            goto L_800AB554;
    }
    // 0x800AB540: nop

    // 0x800AB544: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800AB548: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AB54C: b           L_800AB56C
    // 0x800AB550: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800AB56C;
    // 0x800AB550: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800AB554:
    // 0x800AB554: b           L_800AB56C
    // 0x800AB558: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800AB56C;
    // 0x800AB558: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800AB55C:
    // 0x800AB55C: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800AB560: nop

    // 0x800AB564: bltz        $t3, L_800AB554
    if (SIGNED(ctx->r11) < 0) {
        // 0x800AB568: nop

            goto L_800AB554;
    }
    // 0x800AB568: nop

L_800AB56C:
    // 0x800AB56C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AB570: sw          $t3, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r11;
    // 0x800AB574: nop

    // 0x800AB578: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800AB57C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AB580: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x800AB584: nop

    // 0x800AB588: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AB58C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AB590: nop

    // 0x800AB594: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AB598: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AB59C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AB5A0: nop

    // 0x800AB5A4: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AB5A8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800AB5AC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AB5B0: sh          $t8, 0x15C($sp)
    MEM_H(0X15C, ctx->r29) = ctx->r24;
    // 0x800AB5B4: nop

    // 0x800AB5B8: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x800AB5BC: lw          $t2, 0x170($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X170);
    // 0x800AB5C0: nop

    // 0x800AB5C4: sltu        $at, $t6, $t2
    ctx->r1 = ctx->r14 < ctx->r10 ? 1 : 0;
    // 0x800AB5C8: bne         $at, $zero, L_800AB604
    if (ctx->r1 != 0) {
        // 0x800AB5CC: nop

            goto L_800AB604;
    }
    // 0x800AB5CC: nop

    // 0x800AB5D0: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB5D4: nop

    // 0x800AB5D8: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AB5DC: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AB5E0: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x800AB5E4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800AB5E8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x800AB5EC: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x800AB5F0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x800AB5F4: nop

    // 0x800AB5F8: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800AB5FC: b           L_800ABA00
    // 0x800AB600: nop

        goto L_800ABA00;
    // 0x800AB600: nop

L_800AB604:
    // 0x800AB604: lw          $t3, 0x1DC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AB608: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB60C: lh          $t1, 0x116($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X116);
    // 0x800AB610: nop

    // 0x800AB614: bne         $t1, $at, L_800AB780
    if (ctx->r9 != ctx->r1) {
        // 0x800AB618: nop

            goto L_800AB780;
    }
    // 0x800AB618: nop

    // 0x800AB61C: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB620: nop

    // 0x800AB624: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800AB628: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AB62C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800AB630: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AB634: lui         $t2, 0xFD50
    ctx->r10 = S32(0XFD50 << 16);
    // 0x800AB638: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800AB63C: lw          $t5, 0x1DC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AB640: lhu         $t9, 0x182($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X182);
    // 0x800AB644: lw          $t0, 0x128($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X128);
    // 0x800AB648: sll         $t4, $t9, 6
    ctx->r12 = S32(ctx->r25 << 6);
    // 0x800AB64C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800AB650: sll         $t3, $t4, 5
    ctx->r11 = S32(ctx->r12 << 5);
    // 0x800AB654: addu        $t1, $t0, $t3
    ctx->r9 = ADD32(ctx->r8, ctx->r11);
    // 0x800AB658: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x800AB65C: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB660: nop

    // 0x800AB664: addiu       $t2, $t6, 0x8
    ctx->r10 = ADD32(ctx->r14, 0X8);
    // 0x800AB668: sw          $t2, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r10;
    // 0x800AB66C: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x800AB670: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800AB674: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x800AB678: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AB67C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x800AB680: lui         $t9, 0x709
    ctx->r25 = S32(0X709 << 16);
    // 0x800AB684: ori         $t9, $t9, 0x4160
    ctx->r25 = ctx->r25 | 0X4160;
    // 0x800AB688: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x800AB68C: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB690: nop

    // 0x800AB694: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AB698: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800AB69C: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x800AB6A0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800AB6A4: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x800AB6A8: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x800AB6AC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800AB6B0: nop

    // 0x800AB6B4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800AB6B8: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB6BC: nop

    // 0x800AB6C0: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800AB6C4: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AB6C8: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x800AB6CC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800AB6D0: lui         $t5, 0xF300
    ctx->r13 = S32(0XF300 << 16);
    // 0x800AB6D4: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800AB6D8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800AB6DC: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x800AB6E0: ori         $t4, $t4, 0xF100
    ctx->r12 = ctx->r12 | 0XF100;
    // 0x800AB6E4: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x800AB6E8: lw          $t3, 0x1D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB6EC: nop

    // 0x800AB6F0: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x800AB6F4: sw          $t1, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r9;
    // 0x800AB6F8: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x800AB6FC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800AB700: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AB704: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800AB708: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800AB70C: nop

    // 0x800AB710: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800AB714: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB718: nop

    // 0x800AB71C: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AB720: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AB724: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800AB728: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800AB72C: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x800AB730: ori         $t9, $t9, 0x1000
    ctx->r25 = ctx->r25 | 0X1000;
    // 0x800AB734: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800AB738: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800AB73C: lui         $t0, 0x9
    ctx->r8 = S32(0X9 << 16);
    // 0x800AB740: ori         $t0, $t0, 0x4160
    ctx->r8 = ctx->r8 | 0X4160;
    // 0x800AB744: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800AB748: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB74C: nop

    // 0x800AB750: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x800AB754: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AB758: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800AB75C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800AB760: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800AB764: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800AB768: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800AB76C: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x800AB770: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x800AB774: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800AB778: b           L_800AB8F8
    // 0x800AB77C: nop

        goto L_800AB8F8;
    // 0x800AB77C: nop

L_800AB780:
    // 0x800AB780: lw          $t9, 0x1DC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AB784: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AB788: lh          $t4, 0x116($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X116);
    // 0x800AB78C: nop

    // 0x800AB790: bne         $t4, $at, L_800AB8F8
    if (ctx->r12 != ctx->r1) {
        // 0x800AB794: nop

            goto L_800AB8F8;
    }
    // 0x800AB794: nop

    // 0x800AB798: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB79C: nop

    // 0x800AB7A0: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AB7A4: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800AB7A8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800AB7AC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800AB7B0: lui         $t1, 0xFD10
    ctx->r9 = S32(0XFD10 << 16);
    // 0x800AB7B4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x800AB7B8: lhu         $t7, 0x182($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X182);
    // 0x800AB7BC: lw          $t6, 0x1DC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1DC);
    // 0x800AB7C0: sll         $t5, $t7, 6
    ctx->r13 = S32(ctx->r15 << 6);
    // 0x800AB7C4: lw          $t2, 0x128($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X128);
    // 0x800AB7C8: sll         $t9, $t5, 5
    ctx->r25 = S32(ctx->r13 << 5);
    // 0x800AB7CC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800AB7D0: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800AB7D4: addu        $t0, $t2, $t4
    ctx->r8 = ADD32(ctx->r10, ctx->r12);
    // 0x800AB7D8: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800AB7DC: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB7E0: nop

    // 0x800AB7E4: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x800AB7E8: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800AB7EC: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800AB7F0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800AB7F4: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x800AB7F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AB7FC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800AB800: lui         $t5, 0x705
    ctx->r13 = S32(0X705 << 16);
    // 0x800AB804: ori         $t5, $t5, 0x4160
    ctx->r13 = ctx->r13 | 0X4160;
    // 0x800AB808: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x800AB80C: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB810: nop

    // 0x800AB814: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x800AB818: sw          $t4, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r12;
    // 0x800AB81C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x800AB820: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800AB824: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x800AB828: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x800AB82C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800AB830: nop

    // 0x800AB834: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AB838: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB83C: nop

    // 0x800AB840: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800AB844: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AB848: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800AB84C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800AB850: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800AB854: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AB858: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800AB85C: lui         $t9, 0x77F
    ctx->r25 = S32(0X77F << 16);
    // 0x800AB860: ori         $t9, $t9, 0xF080
    ctx->r25 = ctx->r25 | 0XF080;
    // 0x800AB864: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800AB868: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB86C: nop

    // 0x800AB870: addiu       $t0, $t4, 0x8
    ctx->r8 = ADD32(ctx->r12, 0X8);
    // 0x800AB874: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800AB878: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x800AB87C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800AB880: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800AB884: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x800AB888: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800AB88C: nop

    // 0x800AB890: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800AB894: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB898: nop

    // 0x800AB89C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800AB8A0: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AB8A4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800AB8A8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800AB8AC: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x800AB8B0: ori         $t5, $t5, 0x2000
    ctx->r13 = ctx->r13 | 0X2000;
    // 0x800AB8B4: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800AB8B8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800AB8BC: lui         $t2, 0x5
    ctx->r10 = S32(0X5 << 16);
    // 0x800AB8C0: ori         $t2, $t2, 0x4160
    ctx->r10 = ctx->r10 | 0X4160;
    // 0x800AB8C4: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x800AB8C8: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB8CC: nop

    // 0x800AB8D0: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AB8D4: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800AB8D8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800AB8DC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800AB8E0: lui         $t1, 0xF200
    ctx->r9 = S32(0XF200 << 16);
    // 0x800AB8E4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x800AB8E8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800AB8EC: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x800AB8F0: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x800AB8F4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
L_800AB8F8:
    // 0x800AB8F8: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB8FC: nop

    // 0x800AB900: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800AB904: sw          $t9, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r25;
    // 0x800AB908: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800AB90C: lw          $t2, 0x174($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X174);
    // 0x800AB910: lw          $t1, 0x170($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X170);
    // 0x800AB914: andi        $t4, $t2, 0xFFF
    ctx->r12 = ctx->r10 & 0XFFF;
    // 0x800AB918: sll         $t0, $t4, 12
    ctx->r8 = S32(ctx->r12 << 12);
    // 0x800AB91C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800AB920: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800AB924: or          $t3, $t0, $at
    ctx->r11 = ctx->r8 | ctx->r1;
    // 0x800AB928: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x800AB92C: or          $t6, $t3, $t8
    ctx->r14 = ctx->r11 | ctx->r24;
    // 0x800AB930: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AB934: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800AB938: lw          $t4, 0x178($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X178);
    // 0x800AB93C: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x800AB940: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800AB944: sll         $t2, $t9, 12
    ctx->r10 = S32(ctx->r25 << 12);
    // 0x800AB948: andi        $t0, $t4, 0xFFF
    ctx->r8 = ctx->r12 & 0XFFF;
    // 0x800AB94C: or          $t1, $t2, $t0
    ctx->r9 = ctx->r10 | ctx->r8;
    // 0x800AB950: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x800AB954: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB958: nop

    // 0x800AB95C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800AB960: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800AB964: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800AB968: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800AB96C: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x800AB970: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800AB974: lh          $t9, 0x15E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X15E);
    // 0x800AB978: lh          $t0, 0x15C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X15C);
    // 0x800AB97C: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800AB980: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800AB984: sll         $t2, $t4, 16
    ctx->r10 = S32(ctx->r12 << 16);
    // 0x800AB988: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x800AB98C: or          $t3, $t2, $t1
    ctx->r11 = ctx->r10 | ctx->r9;
    // 0x800AB990: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x800AB994: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB998: nop

    // 0x800AB99C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800AB9A0: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800AB9A4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800AB9A8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800AB9AC: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x800AB9B0: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800AB9B4: lh          $t4, 0x152($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X152);
    // 0x800AB9B8: lh          $t1, 0x150($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X150);
    // 0x800AB9BC: andi        $t0, $t4, 0xFFFF
    ctx->r8 = ctx->r12 & 0XFFFF;
    // 0x800AB9C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800AB9C4: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x800AB9C8: andi        $t3, $t1, 0xFFFF
    ctx->r11 = ctx->r9 & 0XFFFF;
    // 0x800AB9CC: or          $t8, $t2, $t3
    ctx->r24 = ctx->r10 | ctx->r11;
    // 0x800AB9D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x800AB9D4: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800AB9D8: nop

    // 0x800AB9DC: addiu       $t5, $t7, 0x8
    ctx->r13 = ADD32(ctx->r15, 0X8);
    // 0x800AB9E0: sw          $t5, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r13;
    // 0x800AB9E4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x800AB9E8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800AB9EC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800AB9F0: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800AB9F4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800AB9F8: nop

    // 0x800AB9FC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
L_800ABA00:
    // 0x800ABA00: lw          $t1, 0x190($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X190);
    // 0x800ABA04: lw          $t3, 0x1B8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B8);
    // 0x800ABA08: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800ABA0C: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x800ABA10: addiu       $t8, $t3, 0x20
    ctx->r24 = ADD32(ctx->r11, 0X20);
    // 0x800ABA14: sw          $t8, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r24;
    // 0x800ABA18: bne         $at, $zero, L_800AA054
    if (ctx->r1 != 0) {
        // 0x800ABA1C: sw          $t2, 0x190($sp)
        MEM_W(0X190, ctx->r29) = ctx->r10;
            goto L_800AA054;
    }
    // 0x800ABA1C: sw          $t2, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r10;
L_800ABA20:
    // 0x800ABA20: lw          $t6, 0x194($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X194);
    // 0x800ABA24: lw          $t5, 0x1C0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C0);
    // 0x800ABA28: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800ABA2C: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x800ABA30: addiu       $t9, $t5, 0x40
    ctx->r25 = ADD32(ctx->r13, 0X40);
    // 0x800ABA34: sw          $t9, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r25;
    // 0x800ABA38: bne         $at, $zero, L_800AA004
    if (ctx->r1 != 0) {
        // 0x800ABA3C: sw          $t7, 0x194($sp)
        MEM_W(0X194, ctx->r29) = ctx->r15;
            goto L_800AA004;
    }
    // 0x800ABA3C: sw          $t7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r15;
    // 0x800ABA40: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800ABA44: nop

    // 0x800ABA48: addiu       $t0, $t4, 0x8
    ctx->r8 = ADD32(ctx->r12, 0X8);
    // 0x800ABA4C: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x800ABA50: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800ABA54: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800ABA58: lui         $t1, 0xBB00
    ctx->r9 = S32(0XBB00 << 16);
    // 0x800ABA5C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x800ABA60: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800ABA64: nop

    // 0x800ABA68: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800ABA6C: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800ABA70: nop

    // 0x800ABA74: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x800ABA78: sw          $t6, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r14;
    // 0x800ABA7C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800ABA80: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABA84: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800ABA88: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800ABA8C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABA90: nop

    // 0x800ABA94: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800ABA98: lw          $t4, 0x1D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1D4);
    // 0x800ABA9C: lw          $t0, 0x1D8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D8);
    // 0x800ABAA0: nop

    // 0x800ABAA4: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800ABAA8: b           L_800ABAB8
    // 0x800ABAAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ABAB8;
    // 0x800ABAAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ABAB0: b           L_800ABAB8
    // 0x800ABAB4: nop

        goto L_800ABAB8;
    // 0x800ABAB4: nop

L_800ABAB8:
    // 0x800ABAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ABABC: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
    // 0x800ABAC0: jr          $ra
    // 0x800ABAC4: nop

    return;
    // 0x800ABAC4: nop

;}
RECOMP_FUNC void func_800ABAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABAC8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800ABACC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800ABAD0:
    // 0x800ABAD0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800ABAD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABAD8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800ABADC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800ABAE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800ABAE4: sh          $t6, -0x4CB8($at)
    MEM_H(-0X4CB8, ctx->r1) = ctx->r14;
    // 0x800ABAE8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800ABAEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABAF0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800ABAF4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800ABAF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ABAFC: sh          $t9, -0x4CB6($at)
    MEM_H(-0X4CB6, ctx->r1) = ctx->r25;
    // 0x800ABB00: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800ABB04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABB08: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800ABB0C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800ABB10: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800ABB14: sh          $t2, -0x4CB4($at)
    MEM_H(-0X4CB4, ctx->r1) = ctx->r10;
    // 0x800ABB18: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800ABB1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABB20: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800ABB24: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800ABB28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ABB2C: sh          $t5, -0x4CB2($at)
    MEM_H(-0X4CB2, ctx->r1) = ctx->r13;
    // 0x800ABB30: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800ABB34: nop

    // 0x800ABB38: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800ABB3C: slti        $at, $t0, 0xF0
    ctx->r1 = SIGNED(ctx->r8) < 0XF0 ? 1 : 0;
    // 0x800ABB40: bne         $at, $zero, L_800ABAD0
    if (ctx->r1 != 0) {
        // 0x800ABB44: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_800ABAD0;
    }
    // 0x800ABB44: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800ABB48: b           L_800ABB50
    // 0x800ABB4C: nop

        goto L_800ABB50;
    // 0x800ABB4C: nop

L_800ABB50:
    // 0x800ABB50: jr          $ra
    // 0x800ABB54: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800ABB54: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800ABB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABB58: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800ABB5C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x800ABB60: slti        $at, $a0, 0xF1
    ctx->r1 = SIGNED(ctx->r4) < 0XF1 ? 1 : 0;
    // 0x800ABB64: bne         $at, $zero, L_800ABB74
    if (ctx->r1 != 0) {
        // 0x800ABB68: nop

            goto L_800ABB74;
    }
    // 0x800ABB68: nop

    // 0x800ABB6C: b           L_800ABC28
    // 0x800ABB70: nop

        goto L_800ABC28;
    // 0x800ABB70: nop

L_800ABB74:
    // 0x800ABB74: slti        $at, $a1, 0xF1
    ctx->r1 = SIGNED(ctx->r5) < 0XF1 ? 1 : 0;
    // 0x800ABB78: bne         $at, $zero, L_800ABB88
    if (ctx->r1 != 0) {
        // 0x800ABB7C: nop

            goto L_800ABB88;
    }
    // 0x800ABB7C: nop

    // 0x800ABB80: b           L_800ABC28
    // 0x800ABB84: nop

        goto L_800ABC28;
    // 0x800ABB84: nop

L_800ABB88:
    // 0x800ABB88: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x800ABB8C: slti        $at, $t6, 0xF1
    ctx->r1 = SIGNED(ctx->r14) < 0XF1 ? 1 : 0;
    // 0x800ABB90: bne         $at, $zero, L_800ABBA0
    if (ctx->r1 != 0) {
        // 0x800ABB94: nop

            goto L_800ABBA0;
    }
    // 0x800ABB94: nop

    // 0x800ABB98: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x800ABB9C: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
L_800ABBA0:
    // 0x800ABBA0: blez        $a1, L_800ABC20
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800ABBA4: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_800ABC20;
    }
    // 0x800ABBA4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800ABBA8:
    // 0x800ABBA8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800ABBAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABBB0: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800ABBB4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800ABBB8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800ABBBC: sh          $a2, -0x4CB8($at)
    MEM_H(-0X4CB8, ctx->r1) = ctx->r6;
    // 0x800ABBC0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800ABBC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABBC8: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800ABBCC: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800ABBD0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800ABBD4: sh          $a2, -0x4CB6($at)
    MEM_H(-0X4CB6, ctx->r1) = ctx->r6;
    // 0x800ABBD8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800ABBDC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABBE0: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x800ABBE4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800ABBE8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800ABBEC: sh          $a2, -0x4CB4($at)
    MEM_H(-0X4CB4, ctx->r1) = ctx->r6;
    // 0x800ABBF0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800ABBF4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800ABBF8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800ABBFC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800ABC00: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800ABC04: sh          $a2, -0x4CB2($at)
    MEM_H(-0X4CB2, ctx->r1) = ctx->r6;
    // 0x800ABC08: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800ABC0C: nop

    // 0x800ABC10: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800ABC14: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800ABC18: bne         $at, $zero, L_800ABBA8
    if (ctx->r1 != 0) {
        // 0x800ABC1C: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_800ABBA8;
    }
    // 0x800ABC1C: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_800ABC20:
    // 0x800ABC20: b           L_800ABC28
    // 0x800ABC24: nop

        goto L_800ABC28;
    // 0x800ABC24: nop

L_800ABC28:
    // 0x800ABC28: jr          $ra
    // 0x800ABC2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800ABC2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800ABC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABC30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ABC34: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ABC38: nop

    // 0x800ABC3C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800ABC40: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABC44: nop

    // 0x800ABC48: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800ABC4C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800ABC50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800ABC54: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800ABC58: lui         $t9, 0xFF10
    ctx->r25 = S32(0XFF10 << 16);
    // 0x800ABC5C: ori         $t9, $t9, 0x13F
    ctx->r25 = ctx->r25 | 0X13F;
    // 0x800ABC60: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800ABC64: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800ABC68: lw          $t1, 0x24DC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X24DC);
    // 0x800ABC6C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x800ABC70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ABC74: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800ABC78: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800ABC7C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABC80: nop

    // 0x800ABC84: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800ABC88: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800ABC8C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800ABC90: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800ABC94: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x800ABC98: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x800ABC9C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800ABCA0: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800ABCA4: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x800ABCA8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800ABCAC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_800ABCB0:
    // 0x800ABCB0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABCB4: nop

    // 0x800ABCB8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800ABCBC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800ABCC0: sw          $t0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r8;
    // 0x800ABCC4: lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8);
    // 0x800ABCC8: lui         $t2, 0xF700
    ctx->r10 = S32(0XF700 << 16);
    // 0x800ABCCC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800ABCD0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800ABCD4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800ABCD8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800ABCDC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800ABCE0: lhu         $t6, -0x4CB8($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4CB8);
    // 0x800ABCE4: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800ABCE8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800ABCEC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800ABCF0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800ABCF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800ABCF8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800ABCFC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800ABD00: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD04: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800ABD08: addiu       $t5, $t5, -0x4CB8
    ctx->r13 = ADD32(ctx->r13, -0X4CB8);
    // 0x800ABD0C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800ABD10: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800ABD14: sll         $t8, $t1, 3
    ctx->r24 = S32(ctx->r9 << 3);
    // 0x800ABD18: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800ABD1C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800ABD20: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800ABD24: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800ABD28: nop

    // 0x800ABD2C: bne         $t7, $t0, L_800ABDA0
    if (ctx->r15 != ctx->r8) {
        // 0x800ABD30: nop

            goto L_800ABDA0;
    }
    // 0x800ABD30: nop

L_800ABD34:
    // 0x800ABD34: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800ABD38: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD3C: nop

    // 0x800ABD40: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800ABD44: slti        $at, $t4, 0xEF
    ctx->r1 = SIGNED(ctx->r12) < 0XEF ? 1 : 0;
    // 0x800ABD48: bne         $at, $zero, L_800ABD58
    if (ctx->r1 != 0) {
        // 0x800ABD4C: nop

            goto L_800ABD58;
    }
    // 0x800ABD4C: nop

    // 0x800ABD50: b           L_800ABDA0
    // 0x800ABD54: nop

        goto L_800ABDA0;
    // 0x800ABD54: nop

L_800ABD58:
    // 0x800ABD58: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD5C: nop

    // 0x800ABD60: addiu       $t1, $t6, 0x1
    ctx->r9 = ADD32(ctx->r14, 0X1);
    // 0x800ABD64: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800ABD68: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800ABD6C: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800ABD70: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800ABD74: addiu       $t0, $t0, -0x4CB8
    ctx->r8 = ADD32(ctx->r8, -0X4CB8);
    // 0x800ABD78: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800ABD7C: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800ABD80: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x800ABD84: addu        $t6, $t4, $t0
    ctx->r14 = ADD32(ctx->r12, ctx->r8);
    // 0x800ABD88: addu        $t2, $t7, $t0
    ctx->r10 = ADD32(ctx->r15, ctx->r8);
    // 0x800ABD8C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800ABD90: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x800ABD94: nop

    // 0x800ABD98: beq         $t3, $t1, L_800ABD34
    if (ctx->r11 == ctx->r9) {
        // 0x800ABD9C: nop

            goto L_800ABD34;
    }
    // 0x800ABD9C: nop

L_800ABDA0:
    // 0x800ABDA0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABDA4: nop

    // 0x800ABDA8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800ABDAC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800ABDB0: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x800ABDB4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800ABDB8: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800ABDBC: lui         $at, 0xF64F
    ctx->r1 = S32(0XF64F << 16);
    // 0x800ABDC0: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x800ABDC4: andi        $t4, $t8, 0x3FF
    ctx->r12 = ctx->r24 & 0X3FF;
    // 0x800ABDC8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800ABDCC: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x800ABDD0: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x800ABDD4: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x800ABDD8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800ABDDC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800ABDE0: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800ABDE4: andi        $t5, $t1, 0x3FF
    ctx->r13 = ctx->r9 & 0X3FF;
    // 0x800ABDE8: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800ABDEC: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800ABDF0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABDF4: nop

    // 0x800ABDF8: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x800ABDFC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800ABE00: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x800ABE04: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800ABE08: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800ABE0C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800ABE10: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800ABE14: nop

    // 0x800ABE18: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800ABE1C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800ABE20: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800ABE24: nop

    // 0x800ABE28: addu        $t5, $t3, $t1
    ctx->r13 = ADD32(ctx->r11, ctx->r9);
    // 0x800ABE2C: slti        $at, $t5, 0xEF
    ctx->r1 = SIGNED(ctx->r13) < 0XEF ? 1 : 0;
    // 0x800ABE30: bne         $at, $zero, L_800ABCB0
    if (ctx->r1 != 0) {
        // 0x800ABE34: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_800ABCB0;
    }
    // 0x800ABE34: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800ABE38: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABE3C: nop

    // 0x800ABE40: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800ABE44: b           L_800ABE4C
    // 0x800ABE48: nop

        goto L_800ABE4C;
    // 0x800ABE48: nop

L_800ABE4C:
    // 0x800ABE4C: jr          $ra
    // 0x800ABE50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800ABE50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800ABE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABE54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800ABE58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE5C: swc1        $f4, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f4.u32l;
    // 0x800ABE60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800ABE64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE68: swc1        $f6, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f6.u32l;
    // 0x800ABE6C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800ABE70: lwc1        $f8, -0x738($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X738);
    // 0x800ABE74: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE78: swc1        $f8, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f8.u32l;
    // 0x800ABE7C: lui         $at, 0x436F
    ctx->r1 = S32(0X436F << 16);
    // 0x800ABE80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ABE84: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE88: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
    // 0x800ABE8C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800ABE90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800ABE94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABE98: swc1        $f16, 0x61C0($at)
    MEM_W(0X61C0, ctx->r1) = ctx->f16.u32l;
    // 0x800ABE9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800ABEA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ABEA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEA8: swc1        $f18, 0x61C4($at)
    MEM_W(0X61C4, ctx->r1) = ctx->f18.u32l;
    // 0x800ABEAC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800ABEB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ABEB4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEB8: swc1        $f4, 0x61C8($at)
    MEM_W(0X61C8, ctx->r1) = ctx->f4.u32l;
    // 0x800ABEBC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800ABEC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ABEC4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEC8: swc1        $f6, 0x61D0($at)
    MEM_W(0X61D0, ctx->r1) = ctx->f6.u32l;
    // 0x800ABECC: jr          $ra
    // 0x800ABED0: nop

    return;
    // 0x800ABED0: nop

    // 0x800ABED4: jr          $ra
    // 0x800ABED8: nop

    return;
    // 0x800ABED8: nop

;}
RECOMP_FUNC void func_800ABEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABEDC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800ABEE0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800ABEE4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEE8: swc1        $f12, 0x61C0($at)
    MEM_W(0X61C0, ctx->r1) = ctx->f12.u32l;
    // 0x800ABEEC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEF0: swc1        $f14, 0x61C4($at)
    MEM_W(0X61C4, ctx->r1) = ctx->f14.u32l;
    // 0x800ABEF4: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ABEF8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABEFC: swc1        $f4, 0x61C8($at)
    MEM_W(0X61C8, ctx->r1) = ctx->f4.u32l;
    // 0x800ABF00: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800ABF04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF08: swc1        $f6, 0x61D0($at)
    MEM_W(0X61D0, ctx->r1) = ctx->f6.u32l;
    // 0x800ABF0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF10: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800ABF14: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF18: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x800ABF1C: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x800ABF20: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF24: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800ABF28: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ABF2C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF30: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ABF34: swc1        $f4, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f4.u32l;
    // 0x800ABF38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF3C: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800ABF40: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF44: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x800ABF48: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
    // 0x800ABF4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF50: lwc1        $f16, 0x7230($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800ABF54: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800ABF58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF5C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800ABF60: swc1        $f18, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f18.u32l;
    // 0x800ABF64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF68: lwc1        $f4, 0x6190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800ABF6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF70: lwc1        $f6, 0x61C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800ABF74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABF78: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800ABF7C: nop

    // 0x800ABF80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800ABF84: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800ABF88: nop

    // 0x800ABF8C: bc1f        L_800ABFB0
    if (!c1cs) {
        // 0x800ABF90: nop

            goto L_800ABFB0;
    }
    // 0x800ABF90: nop

    // 0x800ABF94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABF98: lwc1        $f16, 0x61C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800ABF9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABFA0: lwc1        $f18, 0x7224($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800ABFA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFA8: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ABFAC: swc1        $f6, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f6.u32l;
L_800ABFB0:
    // 0x800ABFB0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFB4: lwc1        $f8, 0x6194($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800ABFB8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFBC: lwc1        $f4, 0x61C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x800ABFC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABFC4: lwc1        $f10, 0x7230($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800ABFC8: nop

    // 0x800ABFCC: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800ABFD0: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800ABFD4: nop

    // 0x800ABFD8: bc1f        L_800ABFFC
    if (!c1cs) {
        // 0x800ABFDC: nop

            goto L_800ABFFC;
    }
    // 0x800ABFDC: nop

    // 0x800ABFE0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFE4: lwc1        $f18, 0x61C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x800ABFE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800ABFEC: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800ABFF0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ABFF4: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800ABFF8: swc1        $f4, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f4.u32l;
L_800ABFFC:
    // 0x800ABFFC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC000: lwc1        $f10, 0x6198($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC004: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC008: lwc1        $f8, 0x61C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x800AC00C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC010: lwc1        $f16, 0x7224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC014: nop

    // 0x800AC018: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AC01C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x800AC020: nop

    // 0x800AC024: bc1f        L_800AC048
    if (!c1cs) {
        // 0x800AC028: nop

            goto L_800AC048;
    }
    // 0x800AC028: nop

    // 0x800AC02C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC030: lwc1        $f6, 0x61C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x800AC034: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC038: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC03C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC040: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AC044: swc1        $f8, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f8.u32l;
L_800AC048:
    // 0x800AC048: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC04C: lwc1        $f16, 0x619C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC050: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC054: lwc1        $f10, 0x61D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800AC058: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC05C: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC060: nop

    // 0x800AC064: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AC068: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800AC06C: nop

    // 0x800AC070: bc1f        L_800AC094
    if (!c1cs) {
        // 0x800AC074: nop

            goto L_800AC094;
    }
    // 0x800AC074: nop

    // 0x800AC078: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC07C: lwc1        $f4, 0x61D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800AC080: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC084: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC088: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC08C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800AC090: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
L_800AC094:
    // 0x800AC094: b           L_800AC09C
    // 0x800AC098: nop

        goto L_800AC09C;
    // 0x800AC098: nop

L_800AC09C:
    // 0x800AC09C: jr          $ra
    // 0x800AC0A0: nop

    return;
    // 0x800AC0A0: nop

;}
RECOMP_FUNC void func_800AC0A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC0A4: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800AC0A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC0AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC0B0: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC0B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC0B8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AC0BC: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x800AC0C0: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800AC0C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC0C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AC0CC: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC0D0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC0D4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AC0D8: swc1        $f6, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f6.u32l;
    // 0x800AC0DC: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800AC0E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC0E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AC0E8: lwc1        $f16, 0x7230($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC0EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC0F0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800AC0F4: swc1        $f18, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f18.u32l;
    // 0x800AC0F8: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800AC0FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC100: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC104: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC108: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC10C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AC110: swc1        $f10, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f10.u32l;
    // 0x800AC114: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC118: lwc1        $f16, 0x6190($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC11C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC120: lwc1        $f18, 0x61C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800AC124: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC128: lwc1        $f4, 0x7224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC12C: nop

    // 0x800AC130: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AC134: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800AC138: nop

    // 0x800AC13C: bc1f        L_800AC160
    if (!c1cs) {
        // 0x800AC140: nop

            goto L_800AC160;
    }
    // 0x800AC140: nop

    // 0x800AC144: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC148: lwc1        $f8, 0x61C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800AC14C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC150: lwc1        $f10, 0x7224($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC154: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC158: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AC15C: swc1        $f18, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f18.u32l;
L_800AC160:
    // 0x800AC160: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC164: lwc1        $f4, 0x6194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC168: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC16C: lwc1        $f16, 0x61C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x800AC170: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC174: lwc1        $f6, 0x7230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC178: nop

    // 0x800AC17C: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AC180: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800AC184: nop

    // 0x800AC188: bc1f        L_800AC1AC
    if (!c1cs) {
        // 0x800AC18C: nop

            goto L_800AC1AC;
    }
    // 0x800AC18C: nop

    // 0x800AC190: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC194: lwc1        $f10, 0x61C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x800AC198: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC19C: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC1A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1A4: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800AC1A8: swc1        $f16, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f16.u32l;
L_800AC1AC:
    // 0x800AC1AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1B0: lwc1        $f6, 0x6198($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC1B4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1B8: lwc1        $f4, 0x61C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x800AC1BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC1C0: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC1C4: nop

    // 0x800AC1C8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AC1CC: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800AC1D0: nop

    // 0x800AC1D4: bc1f        L_800AC1F8
    if (!c1cs) {
        // 0x800AC1D8: nop

            goto L_800AC1F8;
    }
    // 0x800AC1D8: nop

    // 0x800AC1DC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1E0: lwc1        $f18, 0x61C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X61C8);
    // 0x800AC1E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC1E8: lwc1        $f16, 0x7224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC1EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1F0: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AC1F4: swc1        $f4, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f4.u32l;
L_800AC1F8:
    // 0x800AC1F8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC1FC: lwc1        $f8, 0x619C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC200: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC204: lwc1        $f6, 0x61D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800AC208: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC20C: lwc1        $f10, 0x7230($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC210: nop

    // 0x800AC214: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800AC218: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x800AC21C: nop

    // 0x800AC220: bc1f        L_800AC244
    if (!c1cs) {
        // 0x800AC224: nop

            goto L_800AC244;
    }
    // 0x800AC224: nop

    // 0x800AC228: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC22C: lwc1        $f16, 0x61D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61D0);
    // 0x800AC230: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC234: lwc1        $f4, 0x7230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC238: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC23C: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800AC240: swc1        $f6, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f6.u32l;
L_800AC244:
    // 0x800AC244: jr          $ra
    // 0x800AC248: nop

    return;
    // 0x800AC248: nop

    // 0x800AC24C: jr          $ra
    // 0x800AC250: nop

    return;
    // 0x800AC250: nop

;}
RECOMP_FUNC void func_800AC254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC254: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800AC258: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC25C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800AC260: lwc1        $f8, 0x7224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC264: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC268: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AC26C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AC270: nop

    // 0x800AC274: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AC278: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC27C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC280: nop

    // 0x800AC284: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AC288: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800AC28C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AC290: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800AC294: nop

    // 0x800AC298: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800AC29C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC2A0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800AC2A4: lwc1        $f6, 0x7224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7224);
    // 0x800AC2A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AC2AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AC2B0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AC2B4: nop

    // 0x800AC2B8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800AC2BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC2C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC2C4: nop

    // 0x800AC2C8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC2CC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800AC2D0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AC2D4: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800AC2D8: nop

    // 0x800AC2DC: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800AC2E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC2E4: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800AC2E8: lwc1        $f4, 0x7230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC2EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AC2F0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800AC2F4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AC2F8: nop

    // 0x800AC2FC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AC300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC308: nop

    // 0x800AC30C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC310: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800AC314: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AC318: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800AC31C: nop

    // 0x800AC320: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC324: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800AC328: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800AC32C: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x800AC330: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC334: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AC338: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AC33C: nop

    // 0x800AC340: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AC344: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC348: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC34C: nop

    // 0x800AC350: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AC354: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800AC358: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AC35C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800AC360: nop

    // 0x800AC364: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800AC368: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC36C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800AC370: lwc1        $f16, 0x6190($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC374: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AC378: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800AC37C: nop

    // 0x800AC380: bc1f        L_800AC3B8
    if (!c1cs) {
        // 0x800AC384: nop

            goto L_800AC3B8;
    }
    // 0x800AC384: nop

    // 0x800AC388: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AC38C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC390: lwc1        $f18, 0x6190($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC394: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AC398: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC39C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC3A0: nop

    // 0x800AC3A4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AC3A8: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800AC3AC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AC3B0: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800AC3B4: nop

L_800AC3B8:
    // 0x800AC3B8: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800AC3BC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC3C0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800AC3C4: lwc1        $f10, 0x6194($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC3C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AC3CC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800AC3D0: nop

    // 0x800AC3D4: bc1f        L_800AC40C
    if (!c1cs) {
        // 0x800AC3D8: nop

            goto L_800AC40C;
    }
    // 0x800AC3D8: nop

    // 0x800AC3DC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AC3E0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC3E4: lwc1        $f16, 0x6194($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC3E8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AC3EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC3F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC3F4: nop

    // 0x800AC3F8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AC3FC: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800AC400: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AC404: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800AC408: nop

L_800AC40C:
    // 0x800AC40C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800AC410: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC414: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800AC418: lwc1        $f8, 0x6198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC41C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC420: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800AC424: nop

    // 0x800AC428: bc1f        L_800AC460
    if (!c1cs) {
        // 0x800AC42C: nop

            goto L_800AC460;
    }
    // 0x800AC42C: nop

    // 0x800AC430: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AC434: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC438: lwc1        $f10, 0x6198($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC43C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AC440: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC444: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC448: nop

    // 0x800AC44C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AC450: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800AC454: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AC458: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AC45C: nop

L_800AC460:
    // 0x800AC460: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800AC464: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC468: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800AC46C: lwc1        $f6, 0x619C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC470: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AC474: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800AC478: nop

    // 0x800AC47C: bc1f        L_800AC4B4
    if (!c1cs) {
        // 0x800AC480: nop

            goto L_800AC4B4;
    }
    // 0x800AC480: nop

    // 0x800AC484: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AC488: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC48C: lwc1        $f8, 0x619C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC490: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AC494: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC498: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC49C: nop

    // 0x800AC4A0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC4A4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AC4A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AC4AC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800AC4B0: nop

L_800AC4B4:
    // 0x800AC4B4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800AC4B8: nop

    // 0x800AC4BC: bgez        $t0, L_800AC4C8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800AC4C0: nop

            goto L_800AC4C8;
    }
    // 0x800AC4C0: nop

    // 0x800AC4C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800AC4C8:
    // 0x800AC4C8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800AC4CC: nop

    // 0x800AC4D0: slti        $at, $t1, 0x141
    ctx->r1 = SIGNED(ctx->r9) < 0X141 ? 1 : 0;
    // 0x800AC4D4: bne         $at, $zero, L_800AC4E4
    if (ctx->r1 != 0) {
        // 0x800AC4D8: nop

            goto L_800AC4E4;
    }
    // 0x800AC4D8: nop

    // 0x800AC4DC: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x800AC4E0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_800AC4E4:
    // 0x800AC4E4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800AC4E8: nop

    // 0x800AC4EC: bgez        $t3, L_800AC4F8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800AC4F0: nop

            goto L_800AC4F8;
    }
    // 0x800AC4F0: nop

    // 0x800AC4F4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800AC4F8:
    // 0x800AC4F8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800AC4FC: nop

    // 0x800AC500: slti        $at, $t4, 0xF1
    ctx->r1 = SIGNED(ctx->r12) < 0XF1 ? 1 : 0;
    // 0x800AC504: bne         $at, $zero, L_800AC514
    if (ctx->r1 != 0) {
        // 0x800AC508: nop

            goto L_800AC514;
    }
    // 0x800AC508: nop

    // 0x800AC50C: addiu       $t5, $zero, 0xF0
    ctx->r13 = ADD32(0, 0XF0);
    // 0x800AC510: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_800AC514:
    // 0x800AC514: jr          $ra
    // 0x800AC518: nop

    return;
    // 0x800AC518: nop

    // 0x800AC51C: jr          $ra
    // 0x800AC520: nop

    return;
    // 0x800AC520: nop

;}
RECOMP_FUNC void func_800AC524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC524: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800AC528: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800AC52C: nop

    // 0x800AC530: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800AC534: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC538: lwc1        $f4, 0x6190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC53C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AC540: nop

    // 0x800AC544: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800AC548: nop

    // 0x800AC54C: bc1f        L_800AC560
    if (!c1cs) {
        // 0x800AC550: nop

            goto L_800AC560;
    }
    // 0x800AC550: nop

    // 0x800AC554: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AC558: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC55C: swc1        $f8, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f8.u32l;
L_800AC560:
    // 0x800AC560: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC564: lwc1        $f10, 0x6198($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC568: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AC56C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AC570: nop

    // 0x800AC574: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800AC578: nop

    // 0x800AC57C: bc1f        L_800AC594
    if (!c1cs) {
        // 0x800AC580: nop

            goto L_800AC594;
    }
    // 0x800AC580: nop

    // 0x800AC584: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800AC588: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AC58C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC590: swc1        $f18, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f18.u32l;
L_800AC594:
    // 0x800AC594: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC598: lwc1        $f4, 0x6194($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC59C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AC5A0: nop

    // 0x800AC5A4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800AC5A8: nop

    // 0x800AC5AC: bc1f        L_800AC5C0
    if (!c1cs) {
        // 0x800AC5B0: nop

            goto L_800AC5C0;
    }
    // 0x800AC5B0: nop

    // 0x800AC5B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800AC5B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC5BC: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
L_800AC5C0:
    // 0x800AC5C0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC5C4: lwc1        $f10, 0x619C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC5C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AC5CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AC5D0: nop

    // 0x800AC5D4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800AC5D8: nop

    // 0x800AC5DC: bc1f        L_800AC5F4
    if (!c1cs) {
        // 0x800AC5E0: nop

            goto L_800AC5F4;
    }
    // 0x800AC5E0: nop

    // 0x800AC5E4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800AC5E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AC5EC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC5F0: swc1        $f18, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f18.u32l;
L_800AC5F4:
    // 0x800AC5F4: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800AC5F8: nop

    // 0x800AC5FC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AC600: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800AC604: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800AC608: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AC60C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC610: lwc1        $f4, 0x6190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800AC614: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AC618: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC61C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC620: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AC624: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AC628: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AC62C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800AC630: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AC634: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800AC638: nop

    // 0x800AC63C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AC640: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AC644: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AC648: nop

    // 0x800AC64C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AC650: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC654: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC658: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800AC65C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AC660: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800AC664: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AC668: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800AC66C: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x800AC670: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800AC674: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AC678: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC67C: lwc1        $f6, 0x6194($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x800AC680: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AC684: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC688: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC68C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AC690: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC694: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AC698: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800AC69C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AC6A0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800AC6A4: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x800AC6A8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC6AC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AC6B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AC6B4: nop

    // 0x800AC6B8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AC6BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC6C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC6C4: nop

    // 0x800AC6C8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AC6CC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800AC6D0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AC6D4: andi        $t0, $t9, 0xFFF
    ctx->r8 = ctx->r25 & 0XFFF;
    // 0x800AC6D8: or          $t1, $t5, $t0
    ctx->r9 = ctx->r13 | ctx->r8;
    // 0x800AC6DC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800AC6E0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AC6E4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC6E8: lwc1        $f8, 0x6198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x800AC6EC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AC6F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC6F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC6F8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AC6FC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC700: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AC704: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800AC708: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AC70C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800AC710: nop

    // 0x800AC714: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AC718: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AC71C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AC720: nop

    // 0x800AC724: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AC728: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC72C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC730: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800AC734: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC738: lwc1        $f10, 0x619C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x800AC73C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AC740: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800AC744: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800AC748: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AC74C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800AC750: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AC754: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC758: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC75C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AC760: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AC764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AC768: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x800AC76C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AC770: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800AC774: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800AC778: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AC77C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AC780: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AC784: nop

    // 0x800AC788: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AC78C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC790: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC794: nop

    // 0x800AC798: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC79C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800AC7A0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AC7A4: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800AC7A8: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x800AC7AC: sw          $t4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r12;
    // 0x800AC7B0: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800AC7B4: nop

    // 0x800AC7B8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AC7BC: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800AC7C0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800AC7C4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800AC7C8: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800AC7CC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800AC7D0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800AC7D4: nop

    // 0x800AC7D8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800AC7DC: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800AC7E0: nop

    // 0x800AC7E4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800AC7E8: b           L_800AC7F0
    // 0x800AC7EC: nop

        goto L_800AC7F0;
    // 0x800AC7EC: nop

L_800AC7F0:
    // 0x800AC7F0: jr          $ra
    // 0x800AC7F4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800AC7F4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800AC7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC7F8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AC7FC: blez        $a2, L_800AC880
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800AC800: sw          $zero, 0x4($sp)
        MEM_W(0X4, ctx->r29) = 0;
            goto L_800AC880;
    }
    // 0x800AC800: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800AC804:
    // 0x800AC804: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800AC808: nop

    // 0x800AC80C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800AC810: bne         $t7, $zero, L_800AC840
    if (ctx->r15 != 0) {
        // 0x800AC814: nop

            goto L_800AC840;
    }
    // 0x800AC814: nop

    // 0x800AC818: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800AC81C: lw          $t4, 0x138($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X138);
    // 0x800AC820: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC824: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x800AC828: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x800AC82C: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x800AC830: andi        $t2, $t1, 0x7FFF
    ctx->r10 = ctx->r9 & 0X7FFF;
    // 0x800AC834: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800AC838: b           L_800AC868
    // 0x800AC83C: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
        goto L_800AC868;
    // 0x800AC83C: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
L_800AC840:
    // 0x800AC840: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800AC844: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x800AC848: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800AC84C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800AC850: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x800AC854: addu        $t3, $t9, $t7
    ctx->r11 = ADD32(ctx->r25, ctx->r15);
    // 0x800AC858: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x800AC85C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800AC860: ori         $t4, $t2, 0x1
    ctx->r12 = ctx->r10 | 0X1;
    // 0x800AC864: sh          $t4, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r12;
L_800AC868:
    // 0x800AC868: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800AC86C: nop

    // 0x800AC870: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800AC874: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AC878: bne         $at, $zero, L_800AC804
    if (ctx->r1 != 0) {
        // 0x800AC87C: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_800AC804;
    }
    // 0x800AC87C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
L_800AC880:
    // 0x800AC880: b           L_800AC888
    // 0x800AC884: nop

        goto L_800AC888;
    // 0x800AC884: nop

L_800AC888:
    // 0x800AC888: jr          $ra
    // 0x800AC88C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800AC88C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800AC890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC890: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AC894: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800AC898:
    // 0x800AC898: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800AC89C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC8A0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800AC8A4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AC8A8: sw          $zero, -0x7384($at)
    MEM_W(-0X7384, ctx->r1) = 0;
    // 0x800AC8AC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800AC8B0: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800AC8B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800AC8B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC8BC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800AC8C0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800AC8C4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800AC8C8: addiu       $t2, $t2, -0x7390
    ctx->r10 = ADD32(ctx->r10, -0X7390);
    // 0x800AC8CC: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800AC8D0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800AC8D4: swc1        $f4, -0x7388($at)
    MEM_W(-0X7388, ctx->r1) = ctx->f4.u32l;
    // 0x800AC8D8: lwc1        $f12, 0x8($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800AC8DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC8E0: swc1        $f12, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f12.u32l;
    // 0x800AC8E4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800AC8E8: nop

    // 0x800AC8EC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800AC8F0: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800AC8F4: swc1        $f12, -0x7390($at)
    MEM_W(-0X7390, ctx->r1) = ctx->f12.u32l;
    // 0x800AC8F8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800AC8FC: nop

    // 0x800AC900: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800AC904: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x800AC908: bne         $at, $zero, L_800AC898
    if (ctx->r1 != 0) {
        // 0x800AC90C: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800AC898;
    }
    // 0x800AC90C: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800AC910: b           L_800AC918
    // 0x800AC914: nop

        goto L_800AC918;
    // 0x800AC914: nop

L_800AC918:
    // 0x800AC918: jr          $ra
    // 0x800AC91C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800AC91C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800AC920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC920: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800AC924: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800AC928: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800AC92C: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800AC930: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800AC934: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC938: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AC93C: swc1        $f4, -0x7390($at)
    MEM_W(-0X7390, ctx->r1) = ctx->f4.u32l;
    // 0x800AC940: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800AC944: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800AC948: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC94C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AC950: swc1        $f6, -0x738C($at)
    MEM_W(-0X738C, ctx->r1) = ctx->f6.u32l;
    // 0x800AC954: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800AC958: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800AC95C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800AC960: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800AC964: swc1        $f8, -0x7388($at)
    MEM_W(-0X7388, ctx->r1) = ctx->f8.u32l;
    // 0x800AC968: b           L_800AC970
    // 0x800AC96C: nop

        goto L_800AC970;
    // 0x800AC96C: nop

L_800AC970:
    // 0x800AC970: jr          $ra
    // 0x800AC974: nop

    return;
    // 0x800AC974: nop

;}
RECOMP_FUNC void func_800AC978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC978: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800AC97C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800AC980: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800AC984: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AC988: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800AC98C: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x800AC990: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800AC994: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800AC998: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AC99C: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x800AC9A0: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800AC9A4: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800AC9A8: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800AC9AC: nop

    // 0x800AC9B0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800AC9B4: bne         $t1, $zero, L_800AC9C4
    if (ctx->r9 != 0) {
        // 0x800AC9B8: nop

            goto L_800AC9C4;
    }
    // 0x800AC9B8: nop

    // 0x800AC9BC: b           L_800ACB40
    // 0x800AC9C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ACB40;
    // 0x800AC9C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AC9C4:
    // 0x800AC9C4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800AC9C8: addiu       $t3, $t3, -0x7390
    ctx->r11 = ADD32(ctx->r11, -0X7390);
    // 0x800AC9CC: sll         $t2, $a0, 4
    ctx->r10 = S32(ctx->r4 << 4);
    // 0x800AC9D0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AC9D4: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x800AC9D8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800AC9DC: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800AC9E0: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x800AC9E4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800AC9E8: sw          $t6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r14;
    // 0x800AC9EC: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800AC9F0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800AC9F4: lh          $t0, 0x10C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10C);
    // 0x800AC9F8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800AC9FC: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x800ACA00: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800ACA04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800ACA08: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800ACA0C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800ACA10: lwc1        $f17, -0x730($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X730);
    // 0x800ACA14: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800ACA18: lwc1        $f16, -0x72C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X72C);
    // 0x800ACA1C: nop

    // 0x800ACA20: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x800ACA24: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800ACA28: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
    // 0x800ACA2C: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800ACA30: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800ACA34: lh          $t4, 0x10C($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X10C);
    // 0x800ACA38: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800ACA3C: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800ACA40: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800ACA44: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800ACA48: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800ACA4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800ACA50: lwc1        $f19, -0x728($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X728);
    // 0x800ACA54: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800ACA58: lwc1        $f18, -0x724($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X724);
    // 0x800ACA5C: nop

    // 0x800ACA60: sub.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f10.d - ctx->f18.d;
    // 0x800ACA64: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800ACA68: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800ACA6C: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800ACA70: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ACA74: lwc1        $f8, 0xCC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x800ACA78: nop

    // 0x800ACA7C: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800ACA80: nop

    // 0x800ACA84: bc1f        L_800ACAC4
    if (!c1cs) {
        // 0x800ACA88: nop

            goto L_800ACAC4;
    }
    // 0x800ACA88: nop

    // 0x800ACA8C: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800ACA90: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800ACA94: nop

    // 0x800ACA98: swc1        $f10, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f10.u32l;
    // 0x800ACA9C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800ACAA0: addiu       $t8, $t8, -0x7390
    ctx->r24 = ADD32(ctx->r24, -0X7390);
    // 0x800ACAA4: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800ACAA8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800ACAAC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x800ACAB0: sll         $t2, $a0, 4
    ctx->r10 = S32(ctx->r4 << 4);
    // 0x800ACAB4: addu        $t4, $t2, $t8
    ctx->r12 = ADD32(ctx->r10, ctx->r24);
    // 0x800ACAB8: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x800ACABC: b           L_800ACB18
    // 0x800ACAC0: sw          $t1, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r9;
        goto L_800ACB18;
    // 0x800ACAC0: sw          $t1, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r9;
L_800ACAC4:
    // 0x800ACAC4: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x800ACAC8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800ACACC: lwc1        $f18, 0xCC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x800ACAD0: nop

    // 0x800ACAD4: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800ACAD8: nop

    // 0x800ACADC: bc1f        L_800ACB18
    if (!c1cs) {
        // 0x800ACAE0: nop

            goto L_800ACB18;
    }
    // 0x800ACAE0: nop

    // 0x800ACAE4: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800ACAE8: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800ACAEC: nop

    // 0x800ACAF0: swc1        $f6, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f6.u32l;
    // 0x800ACAF4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800ACAF8: addiu       $t6, $t6, -0x7390
    ctx->r14 = ADD32(ctx->r14, -0X7390);
    // 0x800ACAFC: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x800ACB00: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x800ACB04: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x800ACB08: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800ACB0C: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x800ACB10: ori         $t2, $t0, 0x1
    ctx->r10 = ctx->r8 | 0X1;
    // 0x800ACB14: sw          $t2, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r10;
L_800ACB18:
    // 0x800ACB18: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x800ACB1C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x800ACB20: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800ACB24: lw          $v0, -0x7384($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7384);
    // 0x800ACB28: nop

    // 0x800ACB2C: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x800ACB30: b           L_800ACB40
    // 0x800ACB34: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800ACB40;
    // 0x800ACB34: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800ACB38: b           L_800ACB40
    // 0x800ACB3C: nop

        goto L_800ACB40;
    // 0x800ACB3C: nop

L_800ACB40:
    // 0x800ACB40: jr          $ra
    // 0x800ACB44: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800ACB44: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800ACB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACB48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ACB4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACB50: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800ACB54: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x800ACB58: nop

    // 0x800ACB5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800ACB60: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800ACB64:
    // 0x800ACB64: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800ACB68: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800ACB6C: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x800ACB70: nop

    // 0x800ACB74: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800ACB78: beq         $t9, $zero, L_800ACC04
    if (ctx->r25 == 0) {
        // 0x800ACB7C: nop

            goto L_800ACC04;
    }
    // 0x800ACB7C: nop

    // 0x800ACB80: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACB84: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800ACB88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACB8C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800ACB90: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800ACB94: lwc1        $f6, -0x7390($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7390);
    // 0x800ACB98: lwc1        $f4, 0xCC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x800ACB9C: nop

    // 0x800ACBA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ACBA4: swc1        $f8, 0xCC($t0)
    MEM_W(0XCC, ctx->r8) = ctx->f8.u32l;
    // 0x800ACBA8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACBAC: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800ACBB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACBB4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800ACBB8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800ACBBC: lwc1        $f16, -0x738C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X738C);
    // 0x800ACBC0: lwc1        $f10, 0xD0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x800ACBC4: nop

    // 0x800ACBC8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ACBCC: swc1        $f18, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f18.u32l;
    // 0x800ACBD0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACBD4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800ACBD8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACBDC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800ACBE0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800ACBE4: lwc1        $f6, -0x7388($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7388);
    // 0x800ACBE8: lwc1        $f4, 0xD4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XD4);
    // 0x800ACBEC: nop

    // 0x800ACBF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ACBF4: swc1        $f8, 0xD4($t6)
    MEM_W(0XD4, ctx->r14) = ctx->f8.u32l;
    // 0x800ACBF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACBFC: jal         0x800AC978
    // 0x800ACC00: nop

    func_800AC978(rdram, ctx);
        goto after_0;
    // 0x800ACC00: nop

    after_0:
L_800ACC04:
    // 0x800ACC04: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACC08: nop

    // 0x800ACC0C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800ACC10: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x800ACC14: bne         $at, $zero, L_800ACB64
    if (ctx->r1 != 0) {
        // 0x800ACC18: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_800ACB64;
    }
    // 0x800ACC18: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800ACC1C: b           L_800ACC24
    // 0x800ACC20: nop

        goto L_800ACC24;
    // 0x800ACC20: nop

L_800ACC24:
    // 0x800ACC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ACC28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800ACC2C: jr          $ra
    // 0x800ACC30: nop

    return;
    // 0x800ACC30: nop

;}
RECOMP_FUNC void func_800ACC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACC34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ACC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACC3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800ACC40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800ACC44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800ACC48: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800ACC4C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800ACC50: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800ACC54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800ACC58: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800ACC5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800ACC60: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x800ACC64: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800ACC68: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800ACC6C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800ACC70: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800ACC74: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800ACC78: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800ACC7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACC80: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800ACC84: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800ACC88: swc1        $f4, -0x7390($at)
    MEM_W(-0X7390, ctx->r1) = ctx->f4.u32l;
    // 0x800ACC8C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800ACC90: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800ACC94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACC98: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800ACC9C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800ACCA0: swc1        $f6, -0x738C($at)
    MEM_W(-0X738C, ctx->r1) = ctx->f6.u32l;
    // 0x800ACCA4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800ACCA8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800ACCAC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACCB0: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800ACCB4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800ACCB8: swc1        $f8, -0x7388($at)
    MEM_W(-0X7388, ctx->r1) = ctx->f8.u32l;
    // 0x800ACCBC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACCC0: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800ACCC4: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x800ACCC8: nop

    // 0x800ACCCC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800ACCD0: beq         $t8, $zero, L_800ACD64
    if (ctx->r24 == 0) {
        // 0x800ACCD4: nop

            goto L_800ACD64;
    }
    // 0x800ACCD4: nop

    // 0x800ACCD8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800ACCDC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACCE0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACCE4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800ACCE8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800ACCEC: lwc1        $f16, -0x7390($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7390);
    // 0x800ACCF0: lwc1        $f10, 0xCC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800ACCF4: nop

    // 0x800ACCF8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ACCFC: swc1        $f18, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f18.u32l;
    // 0x800ACD00: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800ACD04: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACD08: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACD0C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x800ACD10: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800ACD14: lwc1        $f6, -0x738C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X738C);
    // 0x800ACD18: lwc1        $f4, 0xD0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x800ACD1C: nop

    // 0x800ACD20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ACD24: swc1        $f8, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f8.u32l;
    // 0x800ACD28: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800ACD2C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACD30: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800ACD34: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800ACD38: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800ACD3C: lwc1        $f16, -0x7388($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7388);
    // 0x800ACD40: lwc1        $f10, 0xD4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD4);
    // 0x800ACD44: nop

    // 0x800ACD48: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ACD4C: swc1        $f18, 0xD4($t5)
    MEM_W(0XD4, ctx->r13) = ctx->f18.u32l;
    // 0x800ACD50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800ACD54: jal         0x800AC978
    // 0x800ACD58: nop

    func_800AC978(rdram, ctx);
        goto after_0;
    // 0x800ACD58: nop

    after_0:
    // 0x800ACD5C: b           L_800ACD6C
    // 0x800ACD60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_800ACD6C;
    // 0x800ACD60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_800ACD64:
    // 0x800ACD64: b           L_800ACD80
    // 0x800ACD68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ACD80;
    // 0x800ACD68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800ACD6C:
    // 0x800ACD6C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800ACD70: b           L_800ACD80
    // 0x800ACD74: nop

        goto L_800ACD80;
    // 0x800ACD74: nop

    // 0x800ACD78: b           L_800ACD80
    // 0x800ACD7C: nop

        goto L_800ACD80;
    // 0x800ACD7C: nop

L_800ACD80:
    // 0x800ACD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ACD84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800ACD88: jr          $ra
    // 0x800ACD8C: nop

    return;
    // 0x800ACD8C: nop

;}
RECOMP_FUNC void func_800ACD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACD90: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800ACD94: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800ACD98: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800ACD9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800ACDA0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800ACDA4: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x800ACDA8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800ACDAC: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800ACDB0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800ACDB4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800ACDB8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800ACDBC: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800ACDC0: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800ACDC4: nop

    // 0x800ACDC8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800ACDCC: beq         $t1, $zero, L_800ACE30
    if (ctx->r9 == 0) {
        // 0x800ACDD0: nop

            goto L_800ACE30;
    }
    // 0x800ACDD0: nop

    // 0x800ACDD4: beq         $a1, $zero, L_800ACDF0
    if (ctx->r5 == 0) {
        // 0x800ACDD8: nop

            goto L_800ACDF0;
    }
    // 0x800ACDD8: nop

    // 0x800ACDDC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800ACDE0: nop

    // 0x800ACDE4: lwc1        $f4, 0xCC($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x800ACDE8: nop

    // 0x800ACDEC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_800ACDF0:
    // 0x800ACDF0: beq         $a2, $zero, L_800ACE0C
    if (ctx->r6 == 0) {
        // 0x800ACDF4: nop

            goto L_800ACE0C;
    }
    // 0x800ACDF4: nop

    // 0x800ACDF8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800ACDFC: nop

    // 0x800ACE00: lwc1        $f6, 0xD0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x800ACE04: nop

    // 0x800ACE08: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_800ACE0C:
    // 0x800ACE0C: beq         $a3, $zero, L_800ACE28
    if (ctx->r7 == 0) {
        // 0x800ACE10: nop

            goto L_800ACE28;
    }
    // 0x800ACE10: nop

    // 0x800ACE14: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800ACE18: nop

    // 0x800ACE1C: lwc1        $f8, 0xD4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD4);
    // 0x800ACE20: nop

    // 0x800ACE24: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_800ACE28:
    // 0x800ACE28: b           L_800ACE38
    // 0x800ACE2C: nop

        goto L_800ACE38;
    // 0x800ACE2C: nop

L_800ACE30:
    // 0x800ACE30: b           L_800ACE48
    // 0x800ACE34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800ACE48;
    // 0x800ACE34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800ACE38:
    // 0x800ACE38: b           L_800ACE48
    // 0x800ACE3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800ACE48;
    // 0x800ACE3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800ACE40: b           L_800ACE48
    // 0x800ACE44: nop

        goto L_800ACE48;
    // 0x800ACE44: nop

L_800ACE48:
    // 0x800ACE48: jr          $ra
    // 0x800ACE4C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800ACE4C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800ACE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACE50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ACE54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ACE58: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800ACE5C: lw          $t6, 0x6BA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA4);
    // 0x800ACE60: nop

    // 0x800ACE64: bne         $t6, $zero, L_800ACE74
    if (ctx->r14 != 0) {
        // 0x800ACE68: nop

            goto L_800ACE74;
    }
    // 0x800ACE68: nop

    // 0x800ACE6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800ACE70: sw          $zero, 0x6B9C($at)
    MEM_W(0X6B9C, ctx->r1) = 0;
L_800ACE74:
    // 0x800ACE74: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800ACE78: addiu       $t7, $t7, 0x61D8
    ctx->r15 = ADD32(ctx->r15, 0X61D8);
    // 0x800ACE7C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800ACE80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ACE84: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800ACE88: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800ACE8C:
    // 0x800ACE8C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800ACE90:
    // 0x800ACE90: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800ACE94: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACE98: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800ACE9C: addiu       $t9, $zero, 0x280
    ctx->r25 = ADD32(0, 0X280);
    // 0x800ACEA0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800ACEA4: sh          $t9, 0x80($t3)
    MEM_H(0X80, ctx->r11) = ctx->r25;
    // 0x800ACEA8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800ACEAC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACEB0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800ACEB4: addiu       $t4, $zero, 0x1E0
    ctx->r12 = ADD32(0, 0X1E0);
    // 0x800ACEB8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800ACEBC: sh          $t4, 0x82($t8)
    MEM_H(0X82, ctx->r24) = ctx->r12;
    // 0x800ACEC0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800ACEC4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACEC8: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x800ACECC: addiu       $t1, $zero, 0x1FF
    ctx->r9 = ADD32(0, 0X1FF);
    // 0x800ACED0: addu        $t3, $t0, $t9
    ctx->r11 = ADD32(ctx->r8, ctx->r25);
    // 0x800ACED4: sh          $t1, 0x84($t3)
    MEM_H(0X84, ctx->r11) = ctx->r9;
    // 0x800ACED8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800ACEDC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACEE0: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x800ACEE4: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x800ACEE8: sh          $zero, 0x86($t4)
    MEM_H(0X86, ctx->r12) = 0;
    // 0x800ACEEC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800ACEF0: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACEF4: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x800ACEF8: addiu       $t8, $zero, 0x280
    ctx->r24 = ADD32(0, 0X280);
    // 0x800ACEFC: addu        $t1, $t2, $t9
    ctx->r9 = ADD32(ctx->r10, ctx->r25);
    // 0x800ACF00: sh          $t8, 0x88($t1)
    MEM_H(0X88, ctx->r9) = ctx->r24;
    // 0x800ACF04: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800ACF08: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF0C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800ACF10: addiu       $t3, $zero, 0x1E0
    ctx->r11 = ADD32(0, 0X1E0);
    // 0x800ACF14: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x800ACF18: sh          $t3, 0x8A($t4)
    MEM_H(0X8A, ctx->r12) = ctx->r11;
    // 0x800ACF1C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800ACF20: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF24: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x800ACF28: addiu       $t0, $zero, 0x1FF
    ctx->r8 = ADD32(0, 0X1FF);
    // 0x800ACF2C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800ACF30: sh          $t0, 0x8C($t1)
    MEM_H(0X8C, ctx->r9) = ctx->r8;
    // 0x800ACF34: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800ACF38: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF3C: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x800ACF40: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x800ACF44: sh          $zero, 0x8E($t3)
    MEM_H(0X8E, ctx->r11) = 0;
    // 0x800ACF48: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800ACF4C: nop

    // 0x800ACF50: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x800ACF54: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x800ACF58: bne         $at, $zero, L_800ACE90
    if (ctx->r1 != 0) {
        // 0x800ACF5C: sw          $t9, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r25;
            goto L_800ACE90;
    }
    // 0x800ACF5C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800ACF60: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800ACF64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ACF68: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF6C: nop

    // 0x800ACF70: swc1        $f4, 0xF8($t2)
    MEM_W(0XF8, ctx->r10) = ctx->f4.u32l;
    // 0x800ACF74: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800ACF78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ACF7C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF80: nop

    // 0x800ACF84: swc1        $f6, 0xFC($t8)
    MEM_W(0XFC, ctx->r24) = ctx->f6.u32l;
    // 0x800ACF88: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800ACF8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800ACF90: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACF94: nop

    // 0x800ACF98: swc1        $f8, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->f8.u32l;
    // 0x800ACF9C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800ACFA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800ACFA4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFA8: nop

    // 0x800ACFAC: swc1        $f10, 0x104($t1)
    MEM_W(0X104, ctx->r9) = ctx->f10.u32l;
    // 0x800ACFB0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800ACFB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800ACFB8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFBC: nop

    // 0x800ACFC0: swc1        $f16, 0x108($t5)
    MEM_W(0X108, ctx->r13) = ctx->f16.u32l;
    // 0x800ACFC4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800ACFC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ACFCC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFD0: nop

    // 0x800ACFD4: swc1        $f18, 0x10C($t6)
    MEM_W(0X10C, ctx->r14) = ctx->f18.u32l;
    // 0x800ACFD8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800ACFDC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFE0: nop

    // 0x800ACFE4: sw          $t7, 0xE4($t3)
    MEM_W(0XE4, ctx->r11) = ctx->r15;
    // 0x800ACFE8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFEC: nop

    // 0x800ACFF0: sw          $zero, 0xF0($t4)
    MEM_W(0XF0, ctx->r12) = 0;
    // 0x800ACFF4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800ACFF8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800ACFFC: sw          $t9, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->r25;
    // 0x800AD000: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800AD004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD008: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD00C: nop

    // 0x800AD010: swc1        $f4, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f4.u32l;
    // 0x800AD014: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800AD018: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD01C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD020: nop

    // 0x800AD024: swc1        $f6, 0xEC($t0)
    MEM_W(0XEC, ctx->r8) = ctx->f6.u32l;
    // 0x800AD028: jal         0x800C1754
    // 0x800AD02C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x800AD02C: nop

    after_0:
    // 0x800AD030: jal         0x800C1B64
    // 0x800AD034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C1B64(rdram, ctx);
        goto after_1;
    // 0x800AD034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800AD038: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800AD03C:
    // 0x800AD03C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800AD040: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD044: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x800AD048: jal         0x800C2AE8
    // 0x800AD04C: addu        $a0, $t1, $t6
    ctx->r4 = ADD32(ctx->r9, ctx->r14);
    MtxUtil_GetCurrentFromMtxF(rdram, ctx);
        goto after_2;
    // 0x800AD04C: addu        $a0, $t1, $t6
    ctx->r4 = ADD32(ctx->r9, ctx->r14);
    after_2:
    // 0x800AD050: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AD054: nop

    // 0x800AD058: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x800AD05C: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800AD060: bne         $at, $zero, L_800AD03C
    if (ctx->r1 != 0) {
        // 0x800AD064: sw          $t3, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r11;
            goto L_800AD03C;
    }
    // 0x800AD064: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800AD068: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD06C: jal         0x800C1A84
    // 0x800AD070: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_3;
    // 0x800AD070: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_3:
    // 0x800AD074: jal         0x800C1A28
    // 0x800AD078: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_4;
    // 0x800AD078: nop

    after_4:
    // 0x800AD07C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD080: nop

    // 0x800AD084: sw          $zero, 0xE0($t4)
    MEM_W(0XE0, ctx->r12) = 0;
    // 0x800AD088: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD08C: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x800AD090: sw          $t9, 0x120($t2)
    MEM_W(0X120, ctx->r10) = ctx->r25;
    // 0x800AD094: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD098: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800AD09C: sw          $t8, 0x124($t0)
    MEM_W(0X124, ctx->r8) = ctx->r24;
    // 0x800AD0A0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0A4: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x800AD0A8: sw          $t5, 0x128($t1)
    MEM_W(0X128, ctx->r9) = ctx->r13;
    // 0x800AD0AC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0B0: addiu       $t6, $zero, 0xE1
    ctx->r14 = ADD32(0, 0XE1);
    // 0x800AD0B4: sw          $t6, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = ctx->r14;
    // 0x800AD0B8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800AD0BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AD0C0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0C4: nop

    // 0x800AD0C8: swc1        $f8, 0x110($t3)
    MEM_W(0X110, ctx->r11) = ctx->f8.u32l;
    // 0x800AD0CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800AD0D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AD0D4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0D8: nop

    // 0x800AD0DC: swc1        $f10, 0x114($t4)
    MEM_W(0X114, ctx->r12) = ctx->f10.u32l;
    // 0x800AD0E0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800AD0E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AD0E8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD0EC: nop

    // 0x800AD0F0: swc1        $f16, 0x118($t9)
    MEM_W(0X118, ctx->r25) = ctx->f16.u32l;
    // 0x800AD0F4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800AD0F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AD0FC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD100: nop

    // 0x800AD104: swc1        $f18, 0x11C($t2)
    MEM_W(0X11C, ctx->r10) = ctx->f18.u32l;
    // 0x800AD108: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD10C: nop

    // 0x800AD110: addiu       $t0, $t8, 0x138
    ctx->r8 = ADD32(ctx->r24, 0X138);
    // 0x800AD114: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800AD118: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800AD11C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800AD120: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x800AD124: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x800AD128: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800AD12C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800AD130: bne         $at, $zero, L_800ACE8C
    if (ctx->r1 != 0) {
        // 0x800AD134: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_800ACE8C;
    }
    // 0x800AD134: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800AD138: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x800AD13C: addiu       $t4, $t4, 0x6BB0
    ctx->r12 = ADD32(ctx->r12, 0X6BB0);
    // 0x800AD140: addiu       $t3, $zero, 0x280
    ctx->r11 = ADD32(0, 0X280);
    // 0x800AD144: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x800AD148: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800AD14C: addiu       $t2, $t2, 0x6BB0
    ctx->r10 = ADD32(ctx->r10, 0X6BB0);
    // 0x800AD150: addiu       $t9, $zero, 0x1E0
    ctx->r25 = ADD32(0, 0X1E0);
    // 0x800AD154: sh          $t9, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r25;
    // 0x800AD158: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800AD15C: addiu       $t0, $t0, 0x6BB0
    ctx->r8 = ADD32(ctx->r8, 0X6BB0);
    // 0x800AD160: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x800AD164: sh          $t8, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r24;
    // 0x800AD168: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800AD16C: addiu       $t5, $t5, 0x6BB0
    ctx->r13 = ADD32(ctx->r13, 0X6BB0);
    // 0x800AD170: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800AD174: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800AD178: addiu       $t7, $t7, 0x6BB0
    ctx->r15 = ADD32(ctx->r15, 0X6BB0);
    // 0x800AD17C: addiu       $t6, $zero, 0x280
    ctx->r14 = ADD32(0, 0X280);
    // 0x800AD180: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x800AD184: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800AD188: addiu       $t3, $t3, 0x6BB0
    ctx->r11 = ADD32(ctx->r11, 0X6BB0);
    // 0x800AD18C: addiu       $t1, $zero, 0x1E0
    ctx->r9 = ADD32(0, 0X1E0);
    // 0x800AD190: sh          $t1, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r9;
    // 0x800AD194: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800AD198: addiu       $t9, $t9, 0x6BB0
    ctx->r25 = ADD32(ctx->r25, 0X6BB0);
    // 0x800AD19C: addiu       $t4, $zero, 0x1FF
    ctx->r12 = ADD32(0, 0X1FF);
    // 0x800AD1A0: sh          $t4, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r12;
    // 0x800AD1A4: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x800AD1A8: addiu       $t2, $t2, 0x6BB0
    ctx->r10 = ADD32(ctx->r10, 0X6BB0);
    // 0x800AD1AC: sh          $zero, 0xE($t2)
    MEM_H(0XE, ctx->r10) = 0;
    // 0x800AD1B0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800AD1B4: jal         0x80099E2C
    // 0x800AD1B8: addiu       $a0, $a0, -0x76B0
    ctx->r4 = ADD32(ctx->r4, -0X76B0);
    func_80099E2C(rdram, ctx);
        goto after_5;
    // 0x800AD1B8: addiu       $a0, $a0, -0x76B0
    ctx->r4 = ADD32(ctx->r4, -0X76B0);
    after_5:
    // 0x800AD1BC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800AD1C0: addiu       $a0, $a0, -0x76B0
    ctx->r4 = ADD32(ctx->r4, -0X76B0);
    // 0x800AD1C4: jal         0x80099E2C
    // 0x800AD1C8: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    func_80099E2C(rdram, ctx);
        goto after_6;
    // 0x800AD1C8: addiu       $a0, $a0, 0x160
    ctx->r4 = ADD32(ctx->r4, 0X160);
    after_6:
    // 0x800AD1CC: b           L_800AD1D4
    // 0x800AD1D0: nop

        goto L_800AD1D4;
    // 0x800AD1D0: nop

L_800AD1D4:
    // 0x800AD1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD1D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800AD1DC: jr          $ra
    // 0x800AD1E0: nop

    return;
    // 0x800AD1E0: nop

;}
RECOMP_FUNC void func_800AD1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD1E4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AD1E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AD1EC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800AD1F0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800AD1F4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800AD1F8: nop

    // 0x800AD1FC: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800AD200: bne         $at, $zero, L_800AD210
    if (ctx->r1 != 0) {
        // 0x800AD204: nop

            goto L_800AD210;
    }
    // 0x800AD204: nop

    // 0x800AD208: b           L_800AD5DC
    // 0x800AD20C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AD5DC;
    // 0x800AD20C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AD210:
    // 0x800AD210: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800AD214: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800AD218: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AD21C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800AD220: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD224: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800AD228: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD22C: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x800AD230: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD234: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800AD238: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800AD23C: nop

    // 0x800AD240: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800AD244: nop

    // 0x800AD248: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800AD24C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AD250: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800AD254: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AD258: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD25C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD260: lwc1        $f4, 0x100($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X100);
    // 0x800AD264: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800AD268: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD26C: lw          $t7, 0x70E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X70E4);
    // 0x800AD270: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800AD274: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800AD278: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AD27C: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x800AD280: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800AD284: sh          $t6, 0x80($t9)
    MEM_H(0X80, ctx->r25) = ctx->r14;
    // 0x800AD288: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AD28C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800AD290: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AD294: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD298: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD29C: lwc1        $f8, 0x104($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X104);
    // 0x800AD2A0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800AD2A4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AD2A8: lw          $t5, 0x70E4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70E4);
    // 0x800AD2AC: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800AD2B0: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x800AD2B4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AD2B8: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x800AD2BC: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x800AD2C0: sh          $t4, 0x82($t3)
    MEM_H(0X82, ctx->r11) = ctx->r12;
    // 0x800AD2C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AD2C8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800AD2CC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AD2D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD2D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD2D8: lwc1        $f16, 0xF8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XF8);
    // 0x800AD2DC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800AD2E0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AD2E4: lw          $t2, 0x70E4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X70E4);
    // 0x800AD2E8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800AD2EC: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x800AD2F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AD2F4: addu        $t0, $t8, $t5
    ctx->r8 = ADD32(ctx->r24, ctx->r13);
    // 0x800AD2F8: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800AD2FC: sh          $t1, 0x88($t0)
    MEM_H(0X88, ctx->r8) = ctx->r9;
    // 0x800AD300: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800AD304: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800AD308: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800AD30C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD310: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD314: lwc1        $f4, 0xFC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XFC);
    // 0x800AD318: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800AD31C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD320: lw          $t9, 0x70E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X70E4);
    // 0x800AD324: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800AD328: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x800AD32C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800AD330: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x800AD334: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800AD338: sh          $t6, 0x8A($t8)
    MEM_H(0X8A, ctx->r24) = ctx->r14;
    // 0x800AD33C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800AD340: lw          $t1, 0x70E4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X70E4);
    // 0x800AD344: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800AD348: sll         $t0, $t1, 6
    ctx->r8 = S32(ctx->r9 << 6);
    // 0x800AD34C: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    // 0x800AD350: jal         0x800C2D6C
    // 0x800AD354: addiu       $a0, $t5, 0xA0
    ctx->r4 = ADD32(ctx->r13, 0XA0);
    MtxUtil_MtxFToMtx(rdram, ctx);
        goto after_0;
    // 0x800AD354: addiu       $a0, $t5, 0xA0
    ctx->r4 = ADD32(ctx->r13, 0XA0);
    after_0:
    // 0x800AD358: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD35C: nop

    // 0x800AD360: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x800AD364: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800AD368: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x800AD36C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800AD370: lui         $t9, 0x380
    ctx->r25 = S32(0X380 << 16);
    // 0x800AD374: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x800AD378: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800AD37C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800AD380: lw          $t6, 0x70E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X70E4);
    // 0x800AD384: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800AD388: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800AD38C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800AD390: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800AD394: addiu       $t5, $t1, 0x80
    ctx->r13 = ADD32(ctx->r9, 0X80);
    // 0x800AD398: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800AD39C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AD3A0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800AD3A4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AD3A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD3AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD3B0: lwc1        $f8, 0x110($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X110);
    // 0x800AD3B4: addiu       $a0, $t4, 0x120
    ctx->r4 = ADD32(ctx->r12, 0X120);
    // 0x800AD3B8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AD3BC: addiu       $a1, $t4, 0x124
    ctx->r5 = ADD32(ctx->r12, 0X124);
    // 0x800AD3C0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AD3C4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AD3C8: addiu       $a2, $t4, 0x128
    ctx->r6 = ADD32(ctx->r12, 0X128);
    // 0x800AD3CC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AD3D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AD3D4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AD3D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD3DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD3E0: lwc1        $f16, 0x114($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X114);
    // 0x800AD3E4: addiu       $a3, $t4, 0x12C
    ctx->r7 = ADD32(ctx->r12, 0X12C);
    // 0x800AD3E8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AD3EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AD3F0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800AD3F4: nop

    // 0x800AD3F8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AD3FC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800AD400: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AD404: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD408: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD40C: lwc1        $f4, 0x118($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X118);
    // 0x800AD410: nop

    // 0x800AD414: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD418: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AD41C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800AD420: nop

    // 0x800AD424: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800AD428: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800AD42C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800AD430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD438: lwc1        $f8, 0x11C($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X11C);
    // 0x800AD43C: nop

    // 0x800AD440: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AD444: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800AD448: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800AD44C: jal         0x800AC254
    // 0x800AD450: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    func_800AC254(rdram, ctx);
        goto after_1;
    // 0x800AD450: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_1:
    // 0x800AD454: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD458: nop

    // 0x800AD45C: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AD460: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800AD464: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800AD468: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800AD46C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AD470: lw          $t7, 0x120($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X120);
    // 0x800AD474: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD478: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AD47C: lw          $t5, 0x124($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X124);
    // 0x800AD480: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AD484: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800AD488: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AD48C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AD490: nop

    // 0x800AD494: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AD498: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD49C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD4A0: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800AD4A4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AD4A8: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x800AD4AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AD4B0: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x800AD4B4: sll         $t4, $t8, 12
    ctx->r12 = S32(ctx->r24 << 12);
    // 0x800AD4B8: or          $t1, $t4, $at
    ctx->r9 = ctx->r12 | ctx->r1;
    // 0x800AD4BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AD4C0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AD4C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AD4C8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800AD4CC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AD4D0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AD4D4: nop

    // 0x800AD4D8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800AD4DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD4E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD4E4: nop

    // 0x800AD4E8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD4EC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800AD4F0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AD4F4: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x800AD4F8: or          $t6, $t1, $t7
    ctx->r14 = ctx->r9 | ctx->r15;
    // 0x800AD4FC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800AD500: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800AD504: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AD508: lw          $t4, 0x128($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X128);
    // 0x800AD50C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AD510: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800AD514: lw          $t1, 0x12C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X12C);
    // 0x800AD518: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AD51C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800AD520: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AD524: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AD528: nop

    // 0x800AD52C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AD530: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD534: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD538: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AD53C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AD540: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AD544: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AD548: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800AD54C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AD550: andi        $t0, $t5, 0xFFF
    ctx->r8 = ctx->r13 & 0XFFF;
    // 0x800AD554: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800AD558: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AD55C: sll         $t3, $t0, 12
    ctx->r11 = S32(ctx->r8 << 12);
    // 0x800AD560: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AD564: nop

    // 0x800AD568: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AD56C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD570: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD574: nop

    // 0x800AD578: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AD57C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800AD580: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AD584: andi        $t2, $t6, 0xFFF
    ctx->r10 = ctx->r14 & 0XFFF;
    // 0x800AD588: or          $t4, $t3, $t2
    ctx->r12 = ctx->r11 | ctx->r10;
    // 0x800AD58C: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x800AD590: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD594: nop

    // 0x800AD598: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800AD59C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800AD5A0: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800AD5A4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800AD5A8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AD5AC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800AD5B0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800AD5B4: nop

    // 0x800AD5B8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800AD5BC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD5C0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800AD5C4: nop

    // 0x800AD5C8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800AD5CC: b           L_800AD5DC
    // 0x800AD5D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD5DC;
    // 0x800AD5D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD5D4: b           L_800AD5DC
    // 0x800AD5D8: nop

        goto L_800AD5DC;
    // 0x800AD5D8: nop

L_800AD5DC:
    // 0x800AD5DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AD5E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800AD5E4: jr          $ra
    // 0x800AD5E8: nop

    return;
    // 0x800AD5E8: nop

;}
RECOMP_FUNC void func_800AD5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD5EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AD5F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD5F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AD5F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800AD5FC: nop

    // 0x800AD600: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800AD604: bne         $at, $zero, L_800AD614
    if (ctx->r1 != 0) {
        // 0x800AD608: nop

            goto L_800AD614;
    }
    // 0x800AD608: nop

    // 0x800AD60C: b           L_800AD670
    // 0x800AD610: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AD670;
    // 0x800AD610: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AD614:
    // 0x800AD614: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AD618: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800AD61C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AD620: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800AD624: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD628: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800AD62C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD630: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x800AD634: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD638: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800AD63C: jal         0x800C1680
    // 0x800AD640: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x800AD640: nop

    after_0:
    // 0x800AD644: jal         0x800C1B64
    // 0x800AD648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C1B64(rdram, ctx);
        goto after_1;
    // 0x800AD648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800AD64C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD650: jal         0x800C1A84
    // 0x800AD654: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_2;
    // 0x800AD654: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_2:
    // 0x800AD658: jal         0x800C1A28
    // 0x800AD65C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_3;
    // 0x800AD65C: nop

    after_3:
    // 0x800AD660: b           L_800AD670
    // 0x800AD664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD670;
    // 0x800AD664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD668: b           L_800AD670
    // 0x800AD66C: nop

        goto L_800AD670;
    // 0x800AD66C: nop

L_800AD670:
    // 0x800AD670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AD678: jr          $ra
    // 0x800AD67C: nop

    return;
    // 0x800AD67C: nop

;}
RECOMP_FUNC void func_800AD680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AD684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD688: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AD68C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800AD690: nop

    // 0x800AD694: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x800AD698: bne         $at, $zero, L_800AD6A8
    if (ctx->r1 != 0) {
        // 0x800AD69C: nop

            goto L_800AD6A8;
    }
    // 0x800AD69C: nop

    // 0x800AD6A0: b           L_800AD6FC
    // 0x800AD6A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AD6FC;
    // 0x800AD6A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AD6A8:
    // 0x800AD6A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800AD6AC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x800AD6B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800AD6B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800AD6B8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD6BC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800AD6C0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800AD6C4: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x800AD6C8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AD6CC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800AD6D0: jal         0x800C1680
    // 0x800AD6D4: nop

    MtxUtil_PushCopy(rdram, ctx);
        goto after_0;
    // 0x800AD6D4: nop

    after_0:
    // 0x800AD6D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD6DC: jal         0x800C1A84
    // 0x800AD6E0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    MtxUtil_CopyCurrent(rdram, ctx);
        goto after_1;
    // 0x800AD6E0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_1:
    // 0x800AD6E4: jal         0x800C1A28
    // 0x800AD6E8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_2;
    // 0x800AD6E8: nop

    after_2:
    // 0x800AD6EC: b           L_800AD6FC
    // 0x800AD6F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD6FC;
    // 0x800AD6F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD6F4: b           L_800AD6FC
    // 0x800AD6F8: nop

        goto L_800AD6FC;
    // 0x800AD6F8: nop

L_800AD6FC:
    // 0x800AD6FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AD704: jr          $ra
    // 0x800AD708: nop

    return;
    // 0x800AD708: nop

;}
RECOMP_FUNC void func_800AD70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD70C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AD710: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AD714: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800AD718: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800AD71C:
    // 0x800AD71C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800AD720: nop

    // 0x800AD724: and         $t8, $t7, $a0
    ctx->r24 = ctx->r15 & ctx->r4;
    // 0x800AD728: beq         $t8, $zero, L_800AD73C
    if (ctx->r24 == 0) {
        // 0x800AD72C: nop

            goto L_800AD73C;
    }
    // 0x800AD72C: nop

    // 0x800AD730: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800AD734: b           L_800AD76C
    // 0x800AD738: nop

        goto L_800AD76C;
    // 0x800AD738: nop

L_800AD73C:
    // 0x800AD73C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800AD740: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800AD744: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800AD748: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x800AD74C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800AD750: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x800AD754: bne         $at, $zero, L_800AD71C
    if (ctx->r1 != 0) {
        // 0x800AD758: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_800AD71C;
    }
    // 0x800AD758: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800AD75C: b           L_800AD76C
    // 0x800AD760: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800AD76C;
    // 0x800AD760: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800AD764: b           L_800AD76C
    // 0x800AD768: nop

        goto L_800AD76C;
    // 0x800AD768: nop

L_800AD76C:
    // 0x800AD76C: jr          $ra
    // 0x800AD770: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800AD770: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800AD774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD774: sltiu       $at, $a0, 0x8
    ctx->r1 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x800AD778: beq         $at, $zero, L_800AD7DC
    if (ctx->r1 == 0) {
        // 0x800AD77C: nop

            goto L_800AD7DC;
    }
    // 0x800AD77C: nop

    // 0x800AD780: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800AD784: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AD788: addu        $at, $at, $t6
    gpr jr_addend_800AD794 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AD78C: lw          $t6, -0x720($at)
    ctx->r14 = ADD32(ctx->r1, -0X720);
    // 0x800AD790: nop

    // 0x800AD794: jr          $t6
    // 0x800AD798: nop

    switch (jr_addend_800AD794 >> 2) {
        case 0: goto L_800AD79C; break;
        case 1: goto L_800AD7A4; break;
        case 2: goto L_800AD7AC; break;
        case 3: goto L_800AD7B4; break;
        case 4: goto L_800AD7BC; break;
        case 5: goto L_800AD7C4; break;
        case 6: goto L_800AD7CC; break;
        case 7: goto L_800AD7D4; break;
        default: switch_error(__func__, 0x800AD794, 0x800EF8E0);
    }
    // 0x800AD798: nop

L_800AD79C:
    // 0x800AD79C: jr          $ra
    // 0x800AD7A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800AD7A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD7A4:
    // 0x800AD7A4: jr          $ra
    // 0x800AD7A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800AD7A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800AD7AC:
    // 0x800AD7AC: jr          $ra
    // 0x800AD7B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800AD7B0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800AD7B4:
    // 0x800AD7B4: jr          $ra
    // 0x800AD7B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x800AD7B8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_800AD7BC:
    // 0x800AD7BC: jr          $ra
    // 0x800AD7C0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x800AD7C0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800AD7C4:
    // 0x800AD7C4: jr          $ra
    // 0x800AD7C8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x800AD7C8: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_800AD7CC:
    // 0x800AD7CC: jr          $ra
    // 0x800AD7D0: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    return;
    // 0x800AD7D0: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_800AD7D4:
    // 0x800AD7D4: jr          $ra
    // 0x800AD7D8: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    return;
    // 0x800AD7D8: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_800AD7DC:
    // 0x800AD7DC: jr          $ra
    // 0x800AD7E0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x800AD7E0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800AD7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD7E4: jr          $ra
    // 0x800AD7E8: nop

    return;
    // 0x800AD7E8: nop

    // 0x800AD7EC: jr          $ra
    // 0x800AD7F0: nop

    return;
    // 0x800AD7F0: nop

    // 0x800AD7F4: nop

    // 0x800AD7F8: nop

    // 0x800AD7FC: nop

;}
RECOMP_FUNC void ContThread_InitControllers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD800: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800AD804: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AD808: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AD80C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AD810: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AD814: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD818: sw          $zero, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = 0;
    // 0x800AD81C: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x800AD820: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD824: sh          $t6, 0xE68($at)
    MEM_H(0XE68, ctx->r1) = ctx->r14;
    // 0x800AD828: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x800AD82C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD830: sh          $t7, 0xE74($at)
    MEM_H(0XE74, ctx->r1) = ctx->r15;
    // 0x800AD834: addiu       $t8, $zero, 0x200
    ctx->r24 = ADD32(0, 0X200);
    // 0x800AD838: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD83C: sh          $t8, 0xEC0($at)
    MEM_H(0XEC0, ctx->r1) = ctx->r24;
    // 0x800AD840: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x800AD844: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD848: sh          $t9, 0xEEC($at)
    MEM_H(0XEEC, ctx->r1) = ctx->r25;
    // 0x800AD84C: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x800AD850: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD854: sh          $t0, 0xFF4($at)
    MEM_H(0XFF4, ctx->r1) = ctx->r8;
    // 0x800AD858: addiu       $t1, $zero, 0x4000
    ctx->r9 = ADD32(0, 0X4000);
    // 0x800AD85C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD860: sh          $t1, 0x101C($at)
    MEM_H(0X101C, ctx->r1) = ctx->r9;
    // 0x800AD864: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x800AD868: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD86C: sh          $t2, 0x1038($at)
    MEM_H(0X1038, ctx->r1) = ctx->r10;
    // 0x800AD870: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x800AD874: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD878: sh          $t3, 0x1042($at)
    MEM_H(0X1042, ctx->r1) = ctx->r11;
    // 0x800AD87C: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x800AD880: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD884: sh          $t4, 0x10F2($at)
    MEM_H(0X10F2, ctx->r1) = ctx->r12;
    // 0x800AD888: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x800AD88C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD890: sh          $t5, 0x11A4($at)
    MEM_H(0X11A4, ctx->r1) = ctx->r13;
    // 0x800AD894: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800AD898: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD89C: sh          $t6, 0x11AC($at)
    MEM_H(0X11AC, ctx->r1) = ctx->r14;
    // 0x800AD8A0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800AD8A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8A8: sh          $t7, 0x1258($at)
    MEM_H(0X1258, ctx->r1) = ctx->r15;
    // 0x800AD8AC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800AD8B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8B4: sh          $t8, 0x1260($at)
    MEM_H(0X1260, ctx->r1) = ctx->r24;
    // 0x800AD8B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AD8BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8C0: sh          $t9, 0x126C($at)
    MEM_H(0X126C, ctx->r1) = ctx->r25;
    // 0x800AD8C4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800AD8C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD8CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8D0: swc1        $f4, 0xE50($at)
    MEM_W(0XE50, ctx->r1) = ctx->f4.u32l;
    // 0x800AD8D4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800AD8D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD8DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8E0: swc1        $f6, 0xE5C($at)
    MEM_W(0XE5C, ctx->r1) = ctx->f6.u32l;
    // 0x800AD8E4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800AD8E8:
    // 0x800AD8E8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800AD8EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD8F0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800AD8F4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800AD8F8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800AD8FC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800AD900: sw          $zero, 0xDA8($at)
    MEM_W(0XDA8, ctx->r1) = 0;
    // 0x800AD904: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800AD908: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD90C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800AD910: lwc1        $f8, 0xE50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XE50);
    // 0x800AD914: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800AD918: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800AD91C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD920: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800AD924: swc1        $f8, 0xDC0($at)
    MEM_W(0XDC0, ctx->r1) = ctx->f8.u32l;
    // 0x800AD928: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800AD92C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD930: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AD934: lwc1        $f10, 0xE5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE5C);
    // 0x800AD938: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800AD93C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800AD940: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD944: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800AD948: swc1        $f10, 0xDC4($at)
    MEM_W(0XDC4, ctx->r1) = ctx->f10.u32l;
    // 0x800AD94C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800AD950: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800AD954: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AD958: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800AD95C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AD960: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800AD964: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800AD968: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AD96C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AD970: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800AD974: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800AD978: addiu       $t0, $t0, 0xDA8
    ctx->r8 = ADD32(ctx->r8, 0XDA8);
    // 0x800AD97C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AD980: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800AD984: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AD988: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800AD98C: swc1        $f16, 0xDB4($at)
    MEM_W(0XDB4, ctx->r1) = ctx->f16.u32l;
    // 0x800AD990: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800AD994: lwc1        $f18, 0xC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800AD998: nop

    // 0x800AD99C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800AD9A0: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x800AD9A4: nop

    // 0x800AD9A8: andi        $at, $s2, 0x4
    ctx->r1 = ctx->r18 & 0X4;
    // 0x800AD9AC: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x800AD9B0: beq         $s2, $zero, L_800ADA04
    if (ctx->r18 == 0) {
        // 0x800AD9B4: nop

            goto L_800ADA04;
    }
    // 0x800AD9B4: nop

    // 0x800AD9B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800AD9BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AD9C0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800AD9C4: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800AD9C8: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800AD9CC: nop

    // 0x800AD9D0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AD9D4: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x800AD9D8: nop

    // 0x800AD9DC: andi        $at, $s2, 0x4
    ctx->r1 = ctx->r18 & 0X4;
    // 0x800AD9E0: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x800AD9E4: bne         $s2, $zero, L_800AD9FC
    if (ctx->r18 != 0) {
        // 0x800AD9E8: nop

            goto L_800AD9FC;
    }
    // 0x800AD9E8: nop

    // 0x800AD9EC: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x800AD9F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD9F4: b           L_800ADA14
    // 0x800AD9F8: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
        goto L_800ADA14;
    // 0x800AD9F8: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
L_800AD9FC:
    // 0x800AD9FC: b           L_800ADA14
    // 0x800ADA00: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
        goto L_800ADA14;
    // 0x800ADA00: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800ADA04:
    // 0x800ADA04: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x800ADA08: nop

    // 0x800ADA0C: bltz        $s2, L_800AD9FC
    if (SIGNED(ctx->r18) < 0) {
        // 0x800ADA10: nop

            goto L_800AD9FC;
    }
    // 0x800ADA10: nop

L_800ADA14:
    // 0x800ADA14: andi        $t3, $s2, 0xFFFF
    ctx->r11 = ctx->r18 & 0XFFFF;
    // 0x800ADA18: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x800ADA1C: sh          $s2, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r18;
    // 0x800ADA20: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA24: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA28: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800ADA2C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800ADA30: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800ADA34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADA38: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800ADA3C: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x800ADA40: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800ADA44: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA48: sh          $s1, 0xDB0($at)
    MEM_H(0XDB0, ctx->r1) = ctx->r17;
    // 0x800ADA4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800ADA50: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800ADA54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADA58: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800ADA5C: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x800ADA60: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800ADA64: sh          $s0, 0xDAE($at)
    MEM_H(0XDAE, ctx->r1) = ctx->r16;
    // 0x800ADA68: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800ADA6C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800ADA70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADA74: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800ADA78: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800ADA7C: sh          $s0, 0xDAC($at)
    MEM_H(0XDAC, ctx->r1) = ctx->r16;
    // 0x800ADA80: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA84: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800ADA88: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x800ADA8C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x800ADA90: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x800ADA94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800ADA98: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800ADA9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADAA0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800ADAA4: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x800ADAA8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800ADAAC: addiu       $t4, $t4, 0xDA8
    ctx->r12 = ADD32(ctx->r12, 0XDA8);
    // 0x800ADAB0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800ADAB4: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800ADAB8: swc1        $f6, 0xDBC($at)
    MEM_W(0XDBC, ctx->r1) = ctx->f6.u32l;
    // 0x800ADABC: lwc1        $f8, 0x14($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800ADAC0: nop

    // 0x800ADAC4: swc1        $f8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f8.u32l;
    // 0x800ADAC8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800ADACC: nop

    // 0x800ADAD0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800ADAD4: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800ADAD8: bne         $at, $zero, L_800AD8E8
    if (ctx->r1 != 0) {
        // 0x800ADADC: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_800AD8E8;
    }
    // 0x800ADADC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800ADAE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ADAE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADAE8: sw          $t8, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = ctx->r24;
    // 0x800ADAEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADAF0: sw          $zero, 0x128C($at)
    MEM_W(0X128C, ctx->r1) = 0;
    // 0x800ADAF4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800ADAF8: addiu       $a0, $a0, -0x23B0
    ctx->r4 = ADD32(ctx->r4, -0X23B0);
    // 0x800ADAFC: jal         0x800C0780
    // 0x800ADB00: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    Thread_CreateExtended(rdram, ctx);
        goto after_0;
    // 0x800ADB00: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x800ADB04: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800ADB08: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADB0C: nop

    // 0x800ADB10: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x800ADB14: nop

    // 0x800ADB18: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800ADB1C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADB20: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800ADB24: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800ADB28: addiu       $t1, $t1, 0x3DF8
    ctx->r9 = ADD32(ctx->r9, 0X3DF8);
    // 0x800ADB2C: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x800ADB30: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800ADB34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADB38: sh          $t4, 0x16A0($at)
    MEM_H(0X16A0, ctx->r1) = ctx->r12;
    // 0x800ADB3C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800ADB40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADB44: sh          $t5, 0x16C8($at)
    MEM_H(0X16C8, ctx->r1) = ctx->r13;
    // 0x800ADB48: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800ADB4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADB50: sh          $t6, 0x19B0($at)
    MEM_H(0X19B0, ctx->r1) = ctx->r14;
    // 0x800ADB54: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADB58: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800ADB5C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x800ADB60: jal         0x800C1154
    // 0x800ADB64: nop

    func_800C1154(rdram, ctx);
        goto after_1;
    // 0x800ADB64: nop

    after_1:
    // 0x800ADB68: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800ADB6C: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADB70: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800ADB74: addiu       $a2, $a2, 0x16A0
    ctx->r6 = ADD32(ctx->r6, 0X16A0);
    // 0x800ADB78: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800ADB7C: jal         0x800C4720
    // 0x800ADB80: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800ADB80: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    after_2:
    // 0x800ADB84: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800ADB88: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADB8C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800ADB90: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800ADB94: addiu       $a2, $a2, 0x2540
    ctx->r6 = ADD32(ctx->r6, 0X2540);
    // 0x800ADB98: addiu       $a1, $a1, 0x127C
    ctx->r5 = ADD32(ctx->r5, 0X127C);
    // 0x800ADB9C: jal         0x800C51D0
    // 0x800ADBA0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    osContInit_recomp(rdram, ctx);
        goto after_3;
    // 0x800ADBA0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_3:
    // 0x800ADBA4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800ADBA8: addiu       $t8, $t8, 0x2540
    ctx->r24 = ADD32(ctx->r24, 0X2540);
    // 0x800ADBAC: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x800ADBB0: nop

    // 0x800ADBB4: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800ADBB8: beq         $t0, $zero, L_800ADC1C
    if (ctx->r8 == 0) {
        // 0x800ADBBC: nop

            goto L_800ADC1C;
    }
    // 0x800ADBBC: nop

    // 0x800ADBC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADBC4: sw          $zero, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = 0;
    // 0x800ADBC8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800ADBCC: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADBD0: jal         0x800C5590
    // 0x800ADBD4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    osContStartReadData_recomp(rdram, ctx);
        goto after_4;
    // 0x800ADBD4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_4:
    // 0x800ADBD8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADBDC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800ADBE0: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x800ADBE4: jal         0x800C143C
    // 0x800ADBE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_5;
    // 0x800ADBE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800ADBEC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800ADBF0: jal         0x800C5654
    // 0x800ADBF4: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    osContGetReadData_recomp(rdram, ctx);
        goto after_6;
    // 0x800ADBF4: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    after_6:
    // 0x800ADBF8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800ADBFC: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADC00: jal         0x800AE0EC
    // 0x800ADC04: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    ContPak_InitializePak(rdram, ctx);
        goto after_7;
    // 0x800ADC04: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_7:
    // 0x800ADC08: jal         0x800AE40C
    // 0x800ADC0C: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_8;
    // 0x800ADC0C: nop

    after_8:
    // 0x800ADC10: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800ADC14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADC18: sw          $t3, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = ctx->r11;
L_800ADC1C:
    // 0x800ADC1C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800ADC20: nop

    // 0x800ADC24: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x800ADC28: jal         0x800C0C8C
    // 0x800ADC2C: nop

    Thread_Start(rdram, ctx);
        goto after_9;
    // 0x800ADC2C: nop

    after_9:
    // 0x800ADC30: b           L_800ADC38
    // 0x800ADC34: nop

        goto L_800ADC38;
    // 0x800ADC34: nop

L_800ADC38:
    // 0x800ADC38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800ADC3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ADC40: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADC44: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800ADC48: jr          $ra
    // 0x800ADC4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800ADC4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ContThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADC50: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800ADC54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ADC58: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800ADC5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ADC60: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800ADC64: addiu       $t7, $t7, -0x700
    ctx->r15 = ADD32(ctx->r15, -0X700);
    // 0x800ADC68: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800ADC6C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x800ADC70: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x800ADC74: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800ADC78: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800ADC7C: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x800ADC80: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800ADC84: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x800ADC88: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800ADC8C: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x800ADC90: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x800ADC94: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x800ADC98: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x800ADC9C: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x800ADCA0: lw          $at, 0x18($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X18);
    // 0x800ADCA4: sw          $t9, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r25;
    // 0x800ADCA8: sw          $at, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r1;
    // 0x800ADCAC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800ADCB0: nop

    // 0x800ADCB4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x800ADCB8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800ADCBC: nop

    // 0x800ADCC0: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x800ADCC4: nop

    // 0x800ADCC8: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_800ADCCC:
    // 0x800ADCCC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800ADCD0: lw          $t3, 0x24D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X24D4);
    // 0x800ADCD4: nop

    // 0x800ADCD8: beq         $t3, $zero, L_800ADDEC
    if (ctx->r11 == 0) {
        // 0x800ADCDC: nop

            goto L_800ADDEC;
    }
    // 0x800ADCDC: nop

    // 0x800ADCE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADCE4: sw          $zero, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = 0;
    // 0x800ADCE8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800ADCEC: lw          $t4, 0x1350($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1350);
    // 0x800ADCF0: nop

    // 0x800ADCF4: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800ADCF8: beq         $t5, $zero, L_800ADD20
    if (ctx->r13 == 0) {
        // 0x800ADCFC: nop

            goto L_800ADD20;
    }
    // 0x800ADCFC: nop

    // 0x800ADD00: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800ADD04: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADD08: jal         0x800AE0EC
    // 0x800ADD0C: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    ContPak_InitializePak(rdram, ctx);
        goto after_0;
    // 0x800ADD0C: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_0:
    // 0x800ADD10: jal         0x800AE40C
    // 0x800ADD14: nop

    ContPak_UpdateFilesState(rdram, ctx);
        goto after_1;
    // 0x800ADD14: nop

    after_1:
    // 0x800ADD18: b           L_800ADDE0
    // 0x800ADD1C: nop

        goto L_800ADDE0;
    // 0x800ADD1C: nop

L_800ADD20:
    // 0x800ADD20: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800ADD24: lw          $t8, 0x1350($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1350);
    // 0x800ADD28: nop

    // 0x800ADD2C: andi        $t6, $t8, 0x10
    ctx->r14 = ctx->r24 & 0X10;
    // 0x800ADD30: beq         $t6, $zero, L_800ADD48
    if (ctx->r14 == 0) {
        // 0x800ADD34: nop

            goto L_800ADD48;
    }
    // 0x800ADD34: nop

    // 0x800ADD38: jal         0x800AE664
    // 0x800ADD3C: nop

    ContPak_DeleteFile(rdram, ctx);
        goto after_2;
    // 0x800ADD3C: nop

    after_2:
    // 0x800ADD40: b           L_800ADDE0
    // 0x800ADD44: nop

        goto L_800ADDE0;
    // 0x800ADD44: nop

L_800ADD48:
    // 0x800ADD48: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800ADD4C: lw          $t7, 0x1350($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1350);
    // 0x800ADD50: nop

    // 0x800ADD54: andi        $t9, $t7, 0x20
    ctx->r25 = ctx->r15 & 0X20;
    // 0x800ADD58: beq         $t9, $zero, L_800ADD70
    if (ctx->r25 == 0) {
        // 0x800ADD5C: nop

            goto L_800ADD70;
    }
    // 0x800ADD5C: nop

    // 0x800ADD60: jal         0x800AE904
    // 0x800ADD64: nop

    ContPak_OpenFile(rdram, ctx);
        goto after_3;
    // 0x800ADD64: nop

    after_3:
    // 0x800ADD68: b           L_800ADDE0
    // 0x800ADD6C: nop

        goto L_800ADDE0;
    // 0x800ADD6C: nop

L_800ADD70:
    // 0x800ADD70: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800ADD74: lw          $t0, 0x1350($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1350);
    // 0x800ADD78: nop

    // 0x800ADD7C: andi        $t1, $t0, 0x100
    ctx->r9 = ctx->r8 & 0X100;
    // 0x800ADD80: beq         $t1, $zero, L_800ADD98
    if (ctx->r9 == 0) {
        // 0x800ADD84: nop

            goto L_800ADD98;
    }
    // 0x800ADD84: nop

    // 0x800ADD88: jal         0x800AEB14
    // 0x800ADD8C: nop

    ContPak_FindFile(rdram, ctx);
        goto after_4;
    // 0x800ADD8C: nop

    after_4:
    // 0x800ADD90: b           L_800ADDE0
    // 0x800ADD94: nop

        goto L_800ADDE0;
    // 0x800ADD94: nop

L_800ADD98:
    // 0x800ADD98: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800ADD9C: lw          $t2, 0x1350($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1350);
    // 0x800ADDA0: nop

    // 0x800ADDA4: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x800ADDA8: beq         $t3, $zero, L_800ADDC0
    if (ctx->r11 == 0) {
        // 0x800ADDAC: nop

            goto L_800ADDC0;
    }
    // 0x800ADDAC: nop

    // 0x800ADDB0: jal         0x800AED0C
    // 0x800ADDB4: nop

    ContPak_WriteFile(rdram, ctx);
        goto after_5;
    // 0x800ADDB4: nop

    after_5:
    // 0x800ADDB8: b           L_800ADDE0
    // 0x800ADDBC: nop

        goto L_800ADDE0;
    // 0x800ADDBC: nop

L_800ADDC0:
    // 0x800ADDC0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800ADDC4: lw          $t4, 0x1350($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1350);
    // 0x800ADDC8: nop

    // 0x800ADDCC: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x800ADDD0: beq         $t5, $zero, L_800ADDE0
    if (ctx->r13 == 0) {
        // 0x800ADDD4: nop

            goto L_800ADDE0;
    }
    // 0x800ADDD4: nop

    // 0x800ADDD8: jal         0x800AEEF8
    // 0x800ADDDC: nop

    ContPak_ReadFile(rdram, ctx);
        goto after_6;
    // 0x800ADDDC: nop

    after_6:
L_800ADDE0:
    // 0x800ADDE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ADDE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADDE8: sw          $t8, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = ctx->r24;
L_800ADDEC:
    // 0x800ADDEC: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800ADDF0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800ADDF4: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x800ADDF8: jal         0x800C143C
    // 0x800ADDFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_7;
    // 0x800ADDFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800ADE00: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800ADE04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800ADE08: lh          $s0, 0x0($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X0);
    // 0x800ADE0C: nop

    // 0x800ADE10: beq         $s0, $at, L_800ADE58
    if (ctx->r16 == ctx->r1) {
        // 0x800ADE14: nop

            goto L_800ADE58;
    }
    // 0x800ADE14: nop

    // 0x800ADE18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800ADE1C: beq         $s0, $at, L_800ADE38
    if (ctx->r16 == ctx->r1) {
        // 0x800ADE20: nop

            goto L_800ADE38;
    }
    // 0x800ADE20: nop

    // 0x800ADE24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800ADE28: beq         $s0, $at, L_800ADE78
    if (ctx->r16 == ctx->r1) {
        // 0x800ADE2C: nop

            goto L_800ADE78;
    }
    // 0x800ADE2C: nop

    // 0x800ADE30: b           L_800ADE9C
    // 0x800ADE34: nop

        goto L_800ADE9C;
    // 0x800ADE34: nop

L_800ADE38:
    // 0x800ADE38: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800ADE3C: jal         0x800C5654
    // 0x800ADE40: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    osContGetReadData_recomp(rdram, ctx);
        goto after_8;
    // 0x800ADE40: addiu       $a0, $a0, 0x2558
    ctx->r4 = ADD32(ctx->r4, 0X2558);
    after_8:
    // 0x800ADE44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800ADE48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADE4C: sw          $t9, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = ctx->r25;
    // 0x800ADE50: b           L_800ADEA4
    // 0x800ADE54: nop

        goto L_800ADEA4;
    // 0x800ADE54: nop

L_800ADE58:
    // 0x800ADE58: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800ADE5C: ori         $at, $zero, 0x82D0
    ctx->r1 = 0 | 0X82D0;
    // 0x800ADE60: jal         0x800C5590
    // 0x800ADE64: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    osContStartReadData_recomp(rdram, ctx);
        goto after_9;
    // 0x800ADE64: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    after_9:
    // 0x800ADE68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800ADE6C: sw          $zero, 0x24D4($at)
    MEM_W(0X24D4, ctx->r1) = 0;
    // 0x800ADE70: b           L_800ADEA4
    // 0x800ADE74: nop

        goto L_800ADEA4;
    // 0x800ADE74: nop

L_800ADE78:
    // 0x800ADE78: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800ADE7C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800ADE80: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x800ADE84: jal         0x800C143C
    // 0x800ADE88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_10;
    // 0x800ADE88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x800ADE8C: b           L_800ADE78
    // 0x800ADE90: nop

        goto L_800ADE78;
    // 0x800ADE90: nop

    // 0x800ADE94: b           L_800ADEA4
    // 0x800ADE98: nop

        goto L_800ADEA4;
    // 0x800ADE98: nop

L_800ADE9C:
    // 0x800ADE9C: b           L_800ADEA4
    // 0x800ADEA0: nop

        goto L_800ADEA4;
    // 0x800ADEA0: nop

L_800ADEA4:
    // 0x800ADEA4: b           L_800ADCCC
    // 0x800ADEA8: nop

        goto L_800ADCCC;
    // 0x800ADEA8: nop

    // 0x800ADEAC: b           L_800ADEB4
    // 0x800ADEB0: nop

        goto L_800ADEB4;
    // 0x800ADEB0: nop

L_800ADEB4:
    // 0x800ADEB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADEB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ADEBC: jr          $ra
    // 0x800ADEC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800ADEC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800ADEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADEC4: nop

    // 0x800ADEC8: nop

    // 0x800ADECC: nop

;}
RECOMP_FUNC void ContPak_FindPfsSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADED0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ADED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ADED8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800ADEDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800ADEE0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800ADEE4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800ADEE8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800ADEEC:
    // 0x800ADEEC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADEF0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800ADEF4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800ADEF8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800ADEFC: lw          $t8, 0x15D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X15D8);
    // 0x800ADF00: nop

    // 0x800ADF04: bne         $t8, $zero, L_800ADFE4
    if (ctx->r24 != 0) {
        // 0x800ADF08: nop

            goto L_800ADFE4;
    }
    // 0x800ADF08: nop

    // 0x800ADF0C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADF10: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800ADF14: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x800ADF18: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800ADF1C: lhu         $t1, 0x13D8($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X13D8);
    // 0x800ADF20: lhu         $t2, 0x26($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X26);
    // 0x800ADF24: nop

    // 0x800ADF28: beq         $t1, $t2, L_800ADF38
    if (ctx->r9 == ctx->r10) {
        // 0x800ADF2C: nop

            goto L_800ADF38;
    }
    // 0x800ADF2C: nop

    // 0x800ADF30: b           L_800ADFE4
    // 0x800ADF34: nop

        goto L_800ADFE4;
    // 0x800ADF34: nop

L_800ADF38:
    // 0x800ADF38: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADF3C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800ADF40: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800ADF44: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800ADF48: lw          $t5, 0x13D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X13D4);
    // 0x800ADF4C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800ADF50: nop

    // 0x800ADF54: beq         $t5, $t6, L_800ADF64
    if (ctx->r13 == ctx->r14) {
        // 0x800ADF58: nop

            goto L_800ADF64;
    }
    // 0x800ADF58: nop

    // 0x800ADF5C: b           L_800ADFE4
    // 0x800ADF60: nop

        goto L_800ADFE4;
    // 0x800ADF60: nop

L_800ADF64:
    // 0x800ADF64: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADF68: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800ADF6C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800ADF70: addiu       $t9, $t8, 0xE
    ctx->r25 = ADD32(ctx->r24, 0XE);
    // 0x800ADF74: addiu       $t0, $t0, 0x13D0
    ctx->r8 = ADD32(ctx->r8, 0X13D0);
    // 0x800ADF78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800ADF7C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800ADF80: jal         0x800BD180
    // 0x800ADF84: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    SysMem_Bcmp(rdram, ctx);
        goto after_0;
    // 0x800ADF84: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x800ADF88: beq         $v0, $zero, L_800ADF98
    if (ctx->r2 == 0) {
        // 0x800ADF8C: nop

            goto L_800ADF98;
    }
    // 0x800ADF8C: nop

    // 0x800ADF90: b           L_800ADFE4
    // 0x800ADF94: nop

        goto L_800ADFE4;
    // 0x800ADF94: nop

L_800ADF98:
    // 0x800ADF98: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADF9C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800ADFA0: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800ADFA4: addiu       $t3, $t2, 0xA
    ctx->r11 = ADD32(ctx->r10, 0XA);
    // 0x800ADFA8: addiu       $t4, $t4, 0x13D0
    ctx->r12 = ADD32(ctx->r12, 0X13D0);
    // 0x800ADFAC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800ADFB0: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x800ADFB4: jal         0x800BD180
    // 0x800ADFB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    SysMem_Bcmp(rdram, ctx);
        goto after_1;
    // 0x800ADFB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800ADFBC: beq         $v0, $zero, L_800ADFCC
    if (ctx->r2 == 0) {
        // 0x800ADFC0: nop

            goto L_800ADFCC;
    }
    // 0x800ADFC0: nop

    // 0x800ADFC4: b           L_800ADFE4
    // 0x800ADFC8: nop

        goto L_800ADFE4;
    // 0x800ADFC8: nop

L_800ADFCC:
    // 0x800ADFCC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADFD0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800ADFD4: nop

    // 0x800ADFD8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800ADFDC: b           L_800AE00C
    // 0x800ADFE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE00C;
    // 0x800ADFE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ADFE4:
    // 0x800ADFE4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADFE8: nop

    // 0x800ADFEC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800ADFF0: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x800ADFF4: bne         $at, $zero, L_800ADEEC
    if (ctx->r1 != 0) {
        // 0x800ADFF8: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800ADEEC;
    }
    // 0x800ADFF8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800ADFFC: b           L_800AE00C
    // 0x800AE000: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800AE00C;
    // 0x800AE000: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800AE004: b           L_800AE00C
    // 0x800AE008: nop

        goto L_800AE00C;
    // 0x800AE008: nop

L_800AE00C:
    // 0x800AE00C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE010: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE014: jr          $ra
    // 0x800AE018: nop

    return;
    // 0x800AE018: nop

;}
RECOMP_FUNC void ContPak_GetPfsFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE01C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AE020: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AE024: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800AE028: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800AE02C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800AE030: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800AE034: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800AE038: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800AE03C: lhu         $a1, 0x36($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X36);
    // 0x800AE040: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800AE044: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE048: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x800AE04C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800AE050: jal         0x800ADED0
    // 0x800AE054: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    ContPak_FindPfsSlot(rdram, ctx);
        goto after_0;
    // 0x800AE054: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800AE058: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800AE05C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE060: nop

    // 0x800AE064: bne         $t8, $zero, L_800AE074
    if (ctx->r24 != 0) {
        // 0x800AE068: nop

            goto L_800AE074;
    }
    // 0x800AE068: nop

    // 0x800AE06C: b           L_800AE0B0
    // 0x800AE070: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_800AE0B0;
    // 0x800AE070: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800AE074:
    // 0x800AE074: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800AE078: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800AE07C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800AE080: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800AE084: lhu         $a1, 0x36($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X36);
    // 0x800AE088: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800AE08C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE090: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800AE094: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800AE098: jal         0x800C57F0
    // 0x800AE09C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_1;
    // 0x800AE09C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_1:
    // 0x800AE0A0: b           L_800AE0B0
    // 0x800AE0A4: nop

        goto L_800AE0B0;
    // 0x800AE0A4: nop

    // 0x800AE0A8: b           L_800AE0B0
    // 0x800AE0AC: nop

        goto L_800AE0B0;
    // 0x800AE0AC: nop

L_800AE0B0:
    // 0x800AE0B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AE0B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AE0B8: jr          $ra
    // 0x800AE0BC: nop

    return;
    // 0x800AE0BC: nop

;}
RECOMP_FUNC void ContPak_SetPfsCodes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE0C0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800AE0C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE0C8: sh          $a0, 0x1646($at)
    MEM_H(0X1646, ctx->r1) = ctx->r4;
    // 0x800AE0CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE0D0: sw          $a1, 0x164C($at)
    MEM_W(0X164C, ctx->r1) = ctx->r5;
    // 0x800AE0D4: jr          $ra
    // 0x800AE0D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE0D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE0DC: jr          $ra
    // 0x800AE0E0: nop

    return;
    // 0x800AE0E0: nop

    // 0x800AE0E4: jr          $ra
    // 0x800AE0E8: nop

    return;
    // 0x800AE0E8: nop

;}
RECOMP_FUNC void ContPak_InitializePak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE0EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE0F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE0F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AE0F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE0FC: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE100: nop

    // 0x800AE104: andi        $t7, $t6, 0x1D8
    ctx->r15 = ctx->r14 & 0X1D8;
    // 0x800AE108: beq         $t7, $zero, L_800AE118
    if (ctx->r15 == 0) {
        // 0x800AE10C: nop

            goto L_800AE118;
    }
    // 0x800AE10C: nop

    // 0x800AE110: b           L_800AE338
    // 0x800AE114: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE114: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE118:
    // 0x800AE118: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE11C: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE120: nop

    // 0x800AE124: andi        $t9, $t8, 0x3E0
    ctx->r25 = ctx->r24 & 0X3E0;
    // 0x800AE128: beq         $t9, $zero, L_800AE138
    if (ctx->r25 == 0) {
        // 0x800AE12C: nop

            goto L_800AE138;
    }
    // 0x800AE12C: nop

    // 0x800AE130: b           L_800AE338
    // 0x800AE134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE134: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE138:
    // 0x800AE138: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE13C: lw          $t0, 0x1690($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1690);
    // 0x800AE140: nop

    // 0x800AE144: bne         $t0, $zero, L_800AE15C
    if (ctx->r8 != 0) {
        // 0x800AE148: nop

            goto L_800AE15C;
    }
    // 0x800AE148: nop

    // 0x800AE14C: b           L_800AE338
    // 0x800AE150: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE150: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800AE154: b           L_800AE170
    // 0x800AE158: nop

        goto L_800AE170;
    // 0x800AE158: nop

L_800AE15C:
    // 0x800AE15C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE160: lw          $t1, 0x1690($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1690);
    // 0x800AE164: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE168: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800AE16C: sw          $t2, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = ctx->r10;
L_800AE170:
    // 0x800AE170: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AE174: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE178: jal         0x800C5FA0
    // 0x800AE17C: addiu       $a1, $a1, 0x2540
    ctx->r5 = ADD32(ctx->r5, 0X2540);
    osContReset_recomp(rdram, ctx);
        goto after_0;
    // 0x800AE17C: addiu       $a1, $a1, 0x2540
    ctx->r5 = ADD32(ctx->r5, 0X2540);
    after_0:
    // 0x800AE180: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE184: addiu       $t3, $t3, 0x2540
    ctx->r11 = ADD32(ctx->r11, 0X2540);
    // 0x800AE188: lbu         $t4, 0x2($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X2);
    // 0x800AE18C: nop

    // 0x800AE190: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800AE194: bne         $t5, $zero, L_800AE1DC
    if (ctx->r13 != 0) {
        // 0x800AE198: nop

            goto L_800AE1DC;
    }
    // 0x800AE198: nop

    // 0x800AE19C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE1A0: lw          $t6, 0x1690($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1690);
    // 0x800AE1A4: nop

    // 0x800AE1A8: bne         $t6, $zero, L_800AE1CC
    if (ctx->r14 != 0) {
        // 0x800AE1AC: nop

            goto L_800AE1CC;
    }
    // 0x800AE1AC: nop

    // 0x800AE1B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AE1B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE1B8: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE1BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE1C0: sb          $zero, 0x127C($at)
    MEM_B(0X127C, ctx->r1) = 0;
    // 0x800AE1C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE1C8: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
L_800AE1CC:
    // 0x800AE1CC: b           L_800AE338
    // 0x800AE1D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE1D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800AE1D4: b           L_800AE22C
    // 0x800AE1D8: nop

        goto L_800AE22C;
    // 0x800AE1D8: nop

L_800AE1DC:
    // 0x800AE1DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AE1E0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE1E4: jal         0x800C6120
    // 0x800AE1E8: addiu       $a1, $a1, 0x127C
    ctx->r5 = ADD32(ctx->r5, 0X127C);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_1;
    // 0x800AE1E8: addiu       $a1, $a1, 0x127C
    ctx->r5 = ADD32(ctx->r5, 0X127C);
    after_1:
    // 0x800AE1EC: bgez        $v0, L_800AE22C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AE1F0: nop

            goto L_800AE22C;
    }
    // 0x800AE1F0: nop

    // 0x800AE1F4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE1F8: lw          $t8, 0x1690($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1690);
    // 0x800AE1FC: nop

    // 0x800AE200: bne         $t8, $zero, L_800AE224
    if (ctx->r24 != 0) {
        // 0x800AE204: nop

            goto L_800AE224;
    }
    // 0x800AE204: nop

    // 0x800AE208: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AE20C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE210: sw          $t9, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r25;
    // 0x800AE214: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE218: sb          $zero, 0x127C($at)
    MEM_B(0X127C, ctx->r1) = 0;
    // 0x800AE21C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE220: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
L_800AE224:
    // 0x800AE224: b           L_800AE338
    // 0x800AE228: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE338;
    // 0x800AE228: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE22C:
    // 0x800AE22C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE230: lbu         $t0, 0x127C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X127C);
    // 0x800AE234: nop

    // 0x800AE238: beq         $t0, $zero, L_800AE258
    if (ctx->r8 == 0) {
        // 0x800AE23C: nop

            goto L_800AE258;
    }
    // 0x800AE23C: nop

    // 0x800AE240: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE244: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE248: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE24C: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800AE250: b           L_800AE270
    // 0x800AE254: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
        goto L_800AE270;
    // 0x800AE254: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
L_800AE258:
    // 0x800AE258: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE25C: lw          $t3, 0x129C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X129C);
    // 0x800AE260: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800AE264: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800AE268: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE26C: sw          $t4, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r12;
L_800AE270:
    // 0x800AE270: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE274: lbu         $t5, 0x127C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X127C);
    // 0x800AE278: nop

    // 0x800AE27C: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x800AE280: beq         $t6, $zero, L_800AE2A0
    if (ctx->r14 == 0) {
        // 0x800AE284: nop

            goto L_800AE2A0;
    }
    // 0x800AE284: nop

    // 0x800AE288: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800AE28C: lw          $t7, 0x129C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X129C);
    // 0x800AE290: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE294: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x800AE298: b           L_800AE2B8
    // 0x800AE29C: sw          $t8, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r24;
        goto L_800AE2B8;
    // 0x800AE29C: sw          $t8, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r24;
L_800AE2A0:
    // 0x800AE2A0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800AE2A4: lw          $t9, 0x129C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X129C);
    // 0x800AE2A8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800AE2AC: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800AE2B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE2B4: sw          $t0, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r8;
L_800AE2B8:
    // 0x800AE2B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE2BC: lbu         $t1, 0x127C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X127C);
    // 0x800AE2C0: nop

    // 0x800AE2C4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800AE2C8: beq         $t2, $zero, L_800AE2E4
    if (ctx->r10 == 0) {
        // 0x800AE2CC: nop

            goto L_800AE2E4;
    }
    // 0x800AE2CC: nop

    // 0x800AE2D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AE2D4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE2D8: addiu       $a1, $a1, 0x1360
    ctx->r5 = ADD32(ctx->r5, 0X1360);
    // 0x800AE2DC: jal         0x800C6490
    // 0x800AE2E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_2;
    // 0x800AE2E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_800AE2E4:
    // 0x800AE2E4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800AE2E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE2EC: sw          $t3, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r11;
    // 0x800AE2F0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800AE2F4: lw          $t4, 0x1350($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1350);
    // 0x800AE2F8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800AE2FC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800AE300: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE304: sw          $t5, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r13;
    // 0x800AE308: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE30C: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x800AE310: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800AE314: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE318: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE31C: sw          $t7, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r15;
    // 0x800AE320: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE324: sw          $zero, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = 0;
    // 0x800AE328: b           L_800AE338
    // 0x800AE32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE338;
    // 0x800AE32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE330: b           L_800AE338
    // 0x800AE334: nop

        goto L_800AE338;
    // 0x800AE334: nop

L_800AE338:
    // 0x800AE338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE33C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE340: jr          $ra
    // 0x800AE344: nop

    return;
    // 0x800AE344: nop

;}
RECOMP_FUNC void ContPak_SetPakInitializationAttempts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE348: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE34C: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE350: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE354: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x800AE358: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE35C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE360: lw          $t8, 0x1350($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1350);
    // 0x800AE364: addiu       $at, $zero, -0x6
    ctx->r1 = ADD32(0, -0X6);
    // 0x800AE368: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800AE36C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE370: sw          $t9, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r25;
    // 0x800AE374: bgez        $a0, L_800AE380
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800AE378: nop

            goto L_800AE380;
    }
    // 0x800AE378: nop

    // 0x800AE37C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800AE380:
    // 0x800AE380: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE384: sw          $a0, 0x1690($at)
    MEM_W(0X1690, ctx->r1) = ctx->r4;
    // 0x800AE388: jr          $ra
    // 0x800AE38C: nop

    return;
    // 0x800AE38C: nop

    // 0x800AE390: jr          $ra
    // 0x800AE394: nop

    return;
    // 0x800AE394: nop

;}
RECOMP_FUNC void ContPak_GetPakInitilizationResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE398: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE39C: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE3A0: nop

    // 0x800AE3A4: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800AE3A8: beq         $t7, $zero, L_800AE3B8
    if (ctx->r15 == 0) {
        // 0x800AE3AC: nop

            goto L_800AE3B8;
    }
    // 0x800AE3AC: nop

    // 0x800AE3B0: jr          $ra
    // 0x800AE3B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800AE3B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AE3B8:
    // 0x800AE3B8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE3BC: lw          $t8, 0x1350($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1350);
    // 0x800AE3C0: nop

    // 0x800AE3C4: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800AE3C8: beq         $t9, $zero, L_800AE3D8
    if (ctx->r25 == 0) {
        // 0x800AE3CC: nop

            goto L_800AE3D8;
    }
    // 0x800AE3CC: nop

    // 0x800AE3D0: jr          $ra
    // 0x800AE3D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800AE3D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE3D8:
    // 0x800AE3D8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE3DC: lw          $t0, 0x1690($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1690);
    // 0x800AE3E0: nop

    // 0x800AE3E4: beq         $t0, $zero, L_800AE3F4
    if (ctx->r8 == 0) {
        // 0x800AE3E8: nop

            goto L_800AE3F4;
    }
    // 0x800AE3E8: nop

    // 0x800AE3EC: jr          $ra
    // 0x800AE3F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800AE3F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AE3F4:
    // 0x800AE3F4: jr          $ra
    // 0x800AE3F8: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    return;
    // 0x800AE3F8: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // 0x800AE3FC: jr          $ra
    // 0x800AE400: nop

    return;
    // 0x800AE400: nop

    // 0x800AE404: jr          $ra
    // 0x800AE408: nop

    return;
    // 0x800AE408: nop

;}
RECOMP_FUNC void ContPak_UpdateFilesState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE40C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE414: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800AE418: lw          $t6, 0x1350($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1350);
    // 0x800AE41C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800AE420: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800AE424: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE428: sw          $t7, 0x1350($at)
    MEM_W(0X1350, ctx->r1) = ctx->r15;
    // 0x800AE42C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800AE430: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x800AE434: addiu       $at, $zero, -0x1D
    ctx->r1 = ADD32(0, -0X1D);
    // 0x800AE438: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800AE43C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE440: sw          $t9, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r25;
    // 0x800AE444: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE448: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE44C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800AE450: addiu       $a2, $a2, 0x1620
    ctx->r6 = ADD32(ctx->r6, 0X1620);
    // 0x800AE454: addiu       $a1, $a1, 0x162C
    ctx->r5 = ADD32(ctx->r5, 0X162C);
    // 0x800AE458: jal         0x800C6650
    // 0x800AE45C: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_0;
    // 0x800AE45C: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    after_0:
    // 0x800AE460: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE464: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AE468: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE46C: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AE470: nop

    // 0x800AE474: beq         $t0, $zero, L_800AE498
    if (ctx->r8 == 0) {
        // 0x800AE478: nop

            goto L_800AE498;
    }
    // 0x800AE478: nop

    // 0x800AE47C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE480: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE484: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE488: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x800AE48C: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
    // 0x800AE490: b           L_800AE570
    // 0x800AE494: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE570;
    // 0x800AE494: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE498:
    // 0x800AE498: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800AE49C:
    // 0x800AE49C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE4A0: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE4A4: addiu       $t5, $t5, 0x13D0
    ctx->r13 = ADD32(ctx->r13, 0X13D0);
    // 0x800AE4A8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE4AC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x800AE4B0: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800AE4B4: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    // 0x800AE4B8: jal         0x800C67A0
    // 0x800AE4BC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    osPfsFileState_recomp(rdram, ctx);
        goto after_1;
    // 0x800AE4BC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800AE4C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE4C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE4C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AE4CC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800AE4D0: sw          $v0, 0x15D8($at)
    MEM_W(0X15D8, ctx->r1) = ctx->r2;
    // 0x800AE4D4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE4D8: nop

    // 0x800AE4DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800AE4E0: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x800AE4E4: bne         $at, $zero, L_800AE49C
    if (ctx->r1 != 0) {
        // 0x800AE4E8: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_800AE49C;
    }
    // 0x800AE4E8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800AE4EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800AE4F0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800AE4F4: addiu       $a1, $a1, 0x1638
    ctx->r5 = ADD32(ctx->r5, 0X1638);
    // 0x800AE4F8: jal         0x800C6A90
    // 0x800AE4FC: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_2;
    // 0x800AE4FC: addiu       $a0, $a0, 0x1360
    ctx->r4 = ADD32(ctx->r4, 0X1360);
    after_2:
    // 0x800AE500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE504: sw          $v0, 0x1684($at)
    MEM_W(0X1684, ctx->r1) = ctx->r2;
    // 0x800AE508: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AE50C: lw          $t0, 0x1684($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1684);
    // 0x800AE510: nop

    // 0x800AE514: beq         $t0, $zero, L_800AE538
    if (ctx->r8 == 0) {
        // 0x800AE518: nop

            goto L_800AE538;
    }
    // 0x800AE518: nop

    // 0x800AE51C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800AE520: lw          $t1, 0x129C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X129C);
    // 0x800AE524: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE528: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x800AE52C: sw          $t2, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r10;
    // 0x800AE530: b           L_800AE570
    // 0x800AE534: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800AE570;
    // 0x800AE534: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800AE538:
    // 0x800AE538: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800AE53C: lw          $t3, 0x1638($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1638);
    // 0x800AE540: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE544: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800AE548: sw          $t4, 0x1638($at)
    MEM_W(0X1638, ctx->r1) = ctx->r12;
    // 0x800AE54C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AE550: lw          $t5, 0x129C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X129C);
    // 0x800AE554: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800AE558: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x800AE55C: sw          $t6, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = ctx->r14;
    // 0x800AE560: b           L_800AE570
    // 0x800AE564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE570;
    // 0x800AE564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE568: b           L_800AE570
    // 0x800AE56C: nop

        goto L_800AE570;
    // 0x800AE56C: nop

L_800AE570:
    // 0x800AE570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE574: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE578: jr          $ra
    // 0x800AE57C: nop

    return;
    // 0x800AE57C: nop

;}
