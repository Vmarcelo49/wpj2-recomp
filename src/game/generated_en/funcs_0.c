#include "recomp.h"
#include "shims.h"
#include "funcs.h"

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000400: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x80000404: lui         $t1, 0xC
    ctx->r9 = S32(0XC << 16);
    // 0x80000408: addiu       $t0, $t0, 0x18E0
    ctx->r8 = ADD32(ctx->r8, 0X18E0);
    // 0x8000040C: ori         $t1, $t1, 0x7C0
    ctx->r9 = ctx->r9 | 0X7C0;
L_80000410:
    // 0x80000410: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80000414: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80000418: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8000041C: bne         $t1, $zero, L_80000410
    if (ctx->r9 != 0) {
        // 0x80000420: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80000410;
    }
    // 0x80000420: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80000424: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80000428: lui         $sp, 0x8018
    ctx->r29 = S32(0X8018 << 16);
    // 0x8000042C: addiu       $t2, $t2, -0x2910
    ctx->r10 = ADD32(ctx->r10, -0X2910);
    // 0x80000430: jr          $t2
    // 0x80000434: addiu       $sp, $sp, 0x49C0
    ctx->r29 = ADD32(ctx->r29, 0X49C0);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x80000434: addiu       $sp, $sp, 0x49C0
    ctx->r29 = ADD32(ctx->r29, 0X49C0);
;}
RECOMP_FUNC void SysMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000450: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x80000454: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80000458: sw          $a0, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r4;
    // 0x8000045C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80000460: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80000464: lw          $t6, 0x1E0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1E0);
    // 0x80000468: nop

    // 0x8000046C: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80000470: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80000474: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80000478: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8000047C: addiu       $t9, $t9, 0x3DF8
    ctx->r25 = ADD32(ctx->r25, 0X3DF8);
    // 0x80000480: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80000484: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80000488: nop

    // 0x8000048C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x80000490: nop

    // 0x80000494: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80000498: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000049C: jal         0x800983B0
    // 0x800004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    InitScheduler(rdram, ctx);
        goto after_0;
    // 0x800004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800004A4: jal         0x800AD800
    // 0x800004A8: nop

    ContThread_InitControllers(rdram, ctx);
        goto after_1;
    // 0x800004A8: nop

    after_1:
    // 0x800004AC: jal         0x800984B4
    // 0x800004B0: nop

    CreateSchedulerThread(rdram, ctx);
        goto after_2;
    // 0x800004B0: nop

    after_2:
    // 0x800004B4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800004B8: nop

    // 0x800004BC: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x800004C0: jal         0x800985BC
    // 0x800004C4: nop

    func_800985BC(rdram, ctx);
        goto after_3;
    // 0x800004C4: nop

    after_3:
    // 0x800004C8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800004CC: nop

    // 0x800004D0: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x800004D4: nop

    // 0x800004D8: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800004DC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800004E0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800004E4: addiu       $at, $t6, 0x7FFF
    ctx->r1 = ADD32(ctx->r14, 0X7FFF);
    // 0x800004E8: sh          $t5, 0xBD($at)
    MEM_H(0XBD, ctx->r1) = ctx->r13;
    // 0x800004EC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800004F0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800004F4: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x800004F8: sh          $t7, 0xDD($at)
    MEM_H(0XDD, ctx->r1) = ctx->r15;
    // 0x800004FC: lui         $t9, 0x8020
    ctx->r25 = S32(0X8020 << 16);
    // 0x80000500: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x80000504: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x80000508: addiu       $t0, $t0, 0x0
    ctx->r8 = ADD32(ctx->r8, 0X0);
    // 0x8000050C: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x80000510: lhu         $s1, 0x6($t0)
    ctx->r17 = MEM_HU(ctx->r8, 0X6);
    // 0x80000514: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x80000518: addiu       $t1, $t1, 0x0
    ctx->r9 = ADD32(ctx->r9, 0X0);
    // 0x8000051C: lui         $t2, 0x8020
    ctx->r10 = S32(0X8020 << 16);
    // 0x80000520: sh          $s1, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r17;
    // 0x80000524: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x80000528: sh          $s0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r16;
    // 0x8000052C: addiu       $t2, $t2, 0x0
    ctx->r10 = ADD32(ctx->r10, 0X0);
    // 0x80000530: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
    // 0x80000534: lui         $t3, 0x8020
    ctx->r11 = S32(0X8020 << 16);
    // 0x80000538: addiu       $t3, $t3, 0x0
    ctx->r11 = ADD32(ctx->r11, 0X0);
    // 0x8000053C: addiu       $a0, $t3, 0x8
    ctx->r4 = ADD32(ctx->r11, 0X8);
    // 0x80000540: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80000544: jal         0x800BD110
    // 0x80000548: addiu       $a2, $zero, 0x4AFF
    ctx->r6 = ADD32(0, 0X4AFF);
    SysMem_Copy64(rdram, ctx);
        goto after_4;
    // 0x80000548: addiu       $a2, $zero, 0x4AFF
    ctx->r6 = ADD32(0, 0X4AFF);
    after_4:
    // 0x8000054C: lui         $a0, 0x8020
    ctx->r4 = S32(0X8020 << 16);
    // 0x80000550: jal         0x800C4080
    // 0x80000554: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x80000554: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    after_5:
    // 0x80000558: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8000055C: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x80000560: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x80000564: addiu       $a0, $a0, -0x5800
    ctx->r4 = ADD32(ctx->r4, -0X5800);
    // 0x80000568: jal         0x800BD110
    // 0x8000056C: addiu       $a2, $zero, 0x4B00
    ctx->r6 = ADD32(0, 0X4B00);
    SysMem_Copy64(rdram, ctx);
        goto after_6;
    // 0x8000056C: addiu       $a2, $zero, 0x4B00
    ctx->r6 = ADD32(0, 0X4B00);
    after_6:
    // 0x80000570: jal         0x8008E5A0
    // 0x80000574: nop

    func_8008E5A0(rdram, ctx);
        goto after_7;
    // 0x80000574: nop

    after_7:
    // 0x80000578: jal         0x800B8A2C
    // 0x8000057C: nop

    AudioMgr_InitThread(rdram, ctx);
        goto after_8;
    // 0x8000057C: nop

    after_8:
    // 0x80000580: lui         $t4, 0xF
    ctx->r12 = S32(0XF << 16);
    // 0x80000584: addiu       $t4, $t4, 0x27E0
    ctx->r12 = ADD32(ctx->r12, 0X27E0);
    // 0x80000588: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000058C: sw          $t4, 0x3DF0($at)
    MEM_W(0X3DF0, ctx->r1) = ctx->r12;
    // 0x80000590: lui         $t5, 0x8040
    ctx->r13 = S32(0X8040 << 16);
    // 0x80000594: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x80000598: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000059C: sw          $t5, 0x3E28($at)
    MEM_W(0X3E28, ctx->r1) = ctx->r13;
    // 0x800005A0: lui         $t6, 0x49
    ctx->r14 = S32(0X49 << 16);
    // 0x800005A4: addiu       $t6, $t6, 0x2860
    ctx->r14 = ADD32(ctx->r14, 0X2860);
    // 0x800005A8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800005AC: sw          $t6, 0x3E2C($at)
    MEM_W(0X3E2C, ctx->r1) = ctx->r14;
    // 0x800005B0: lui         $t7, 0x807A
    ctx->r15 = S32(0X807A << 16);
    // 0x800005B4: addiu       $t7, $t7, 0x80
    ctx->r15 = ADD32(ctx->r15, 0X80);
    // 0x800005B8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800005BC: sw          $t7, 0x40D8($at)
    MEM_W(0X40D8, ctx->r1) = ctx->r15;
    // 0x800005C0: lui         $t8, 0x6A
    ctx->r24 = S32(0X6A << 16);
    // 0x800005C4: addiu       $t8, $t8, -0x5690
    ctx->r24 = ADD32(ctx->r24, -0X5690);
    // 0x800005C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800005CC: sw          $t8, 0x60E0($at)
    MEM_W(0X60E0, ctx->r1) = ctx->r24;
    // 0x800005D0: lui         $t9, 0x809B
    ctx->r25 = S32(0X809B << 16);
    // 0x800005D4: addiu       $t9, $t9, -0x7E70
    ctx->r25 = ADD32(ctx->r25, -0X7E70);
    // 0x800005D8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800005DC: sw          $t9, 0x60E8($at)
    MEM_W(0X60E8, ctx->r1) = ctx->r25;
    // 0x800005E0: lui         $t0, 0x8094
    ctx->r8 = S32(0X8094 << 16);
    // 0x800005E4: addiu       $t0, $t0, 0x7340
    ctx->r8 = ADD32(ctx->r8, 0X7340);
    // 0x800005E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800005EC: sw          $t0, 0x49C0($at)
    MEM_W(0X49C0, ctx->r1) = ctx->r8;
    // 0x800005F0: lui         $t1, 0x64
    ctx->r9 = S32(0X64 << 16);
    // 0x800005F4: addiu       $t1, $t1, -0x64E0
    ctx->r9 = ADD32(ctx->r9, -0X64E0);
    // 0x800005F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800005FC: sw          $t1, 0x29B8($at)
    MEM_W(0X29B8, ctx->r1) = ctx->r9;
    // 0x80000600: lui         $t2, 0x6E
    ctx->r10 = S32(0X6E << 16);
    // 0x80000604: addiu       $t2, $t2, 0x3A40
    ctx->r10 = ADD32(ctx->r10, 0X3A40);
    // 0x80000608: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000060C: sw          $t2, -0x488($at)
    MEM_W(-0X488, ctx->r1) = ctx->r10;
    // 0x80000610: lui         $t3, 0x809F
    ctx->r11 = S32(0X809F << 16);
    // 0x80000614: addiu       $t3, $t3, 0x1260
    ctx->r11 = ADD32(ctx->r11, 0X1260);
    // 0x80000618: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000061C: sw          $t3, -0x480($at)
    MEM_W(-0X480, ctx->r1) = ctx->r11;
    // 0x80000620: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80000624: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80000628: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x8000062C: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x80000630: lui         $a2, 0x807A
    ctx->r6 = S32(0X807A << 16);
    // 0x80000634: jal         0x800BD1FC
    // 0x80000638: addiu       $a2, $a2, 0x1A20
    ctx->r6 = ADD32(ctx->r6, 0X1A20);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_9;
    // 0x80000638: addiu       $a2, $a2, 0x1A20
    ctx->r6 = ADD32(ctx->r6, 0X1A20);
    after_9:
    // 0x8000063C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80000640: sw          $v0, 0x193C($at)
    MEM_W(0X193C, ctx->r1) = ctx->r2;
    // 0x80000644: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80000648: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000064C: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x80000650: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x80000654: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x80000658: jal         0x800BD1FC
    // 0x8000065C: addiu       $a2, $a2, -0x7DD0
    ctx->r6 = ADD32(ctx->r6, -0X7DD0);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_10;
    // 0x8000065C: addiu       $a2, $a2, -0x7DD0
    ctx->r6 = ADD32(ctx->r6, -0X7DD0);
    after_10:
    // 0x80000660: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000664: sw          $v0, 0x3DB0($at)
    MEM_W(0X3DB0, ctx->r1) = ctx->r2;
    // 0x80000668: lui         $t4, 0x8044
    ctx->r12 = S32(0X8044 << 16);
    // 0x8000066C: lui         $t5, 0x8045
    ctx->r13 = S32(0X8045 << 16);
    // 0x80000670: lui         $t6, 0x8079
    ctx->r14 = S32(0X8079 << 16);
    // 0x80000674: lui         $t7, 0x807A
    ctx->r15 = S32(0X807A << 16);
    // 0x80000678: lui         $t8, 0x807A
    ctx->r24 = S32(0X807A << 16);
    // 0x8000067C: addiu       $t8, $t8, -0x58D0
    ctx->r24 = ADD32(ctx->r24, -0X58D0);
    // 0x80000680: addiu       $t7, $t7, -0x6E40
    ctx->r15 = ADD32(ctx->r15, -0X6E40);
    // 0x80000684: addiu       $t6, $t6, -0x2E40
    ctx->r14 = ADD32(ctx->r14, -0X2E40);
    // 0x80000688: addiu       $t5, $t5, -0x5500
    ctx->r13 = ADD32(ctx->r13, -0X5500);
    // 0x8000068C: addiu       $t4, $t4, 0x12E0
    ctx->r12 = ADD32(ctx->r12, 0X12E0);
    // 0x80000690: lui         $a0, 0x8040
    ctx->r4 = S32(0X8040 << 16);
    // 0x80000694: lui         $a1, 0x8041
    ctx->r5 = S32(0X8041 << 16);
    // 0x80000698: lui         $a2, 0x8041
    ctx->r6 = S32(0X8041 << 16);
    // 0x8000069C: lui         $a3, 0x8041
    ctx->r7 = S32(0X8041 << 16);
    // 0x800006A0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800006A4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800006A8: addiu       $a3, $a3, 0x2A40
    ctx->r7 = ADD32(ctx->r7, 0X2A40);
    // 0x800006AC: addiu       $a2, $a2, -0x5660
    ctx->r6 = ADD32(ctx->r6, -0X5660);
    // 0x800006B0: addiu       $a1, $a1, -0x64C0
    ctx->r5 = ADD32(ctx->r5, -0X64C0);
    // 0x800006B4: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    // 0x800006B8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800006BC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800006C0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800006C4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800006C8: jal         0x800B1A50
    // 0x800006CC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_800B1A50(rdram, ctx);
        goto after_11;
    // 0x800006CC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_11:
    // 0x800006D0: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800006D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800006D8: sw          $t0, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r8;
    // 0x800006DC: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x800006E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800006E4: sw          $t1, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r9;
    // 0x800006E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800006EC: lwc1        $f4, -0x2ED0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2ED0);
    // 0x800006F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800006F4: swc1        $f4, 0x25D8($at)
    MEM_W(0X25D8, ctx->r1) = ctx->f4.u32l;
    // 0x800006F8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800006FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000704: swc1        $f6, 0x25D0($at)
    MEM_W(0X25D0, ctx->r1) = ctx->f6.u32l;
    // 0x80000708: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000070C: lwc1        $f8, 0x25D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x80000710: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000714: swc1        $f8, 0x25A0($at)
    MEM_W(0X25A0, ctx->r1) = ctx->f8.u32l;
    // 0x80000718: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8000071C: lw          $t2, -0x4CCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CCC);
    // 0x80000720: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000724: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80000728: nop

    // 0x8000072C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80000730: swc1        $f16, 0x25A8($at)
    MEM_W(0X25A8, ctx->r1) = ctx->f16.u32l;
    // 0x80000734: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80000738: lw          $t3, -0x4CC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CC4);
    // 0x8000073C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000740: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80000744: nop

    // 0x80000748: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000074C: swc1        $f4, 0x25B0($at)
    MEM_W(0X25B0, ctx->r1) = ctx->f4.u32l;
    // 0x80000750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000754: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000758: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000075C: swc1        $f6, 0x25B8($at)
    MEM_W(0X25B8, ctx->r1) = ctx->f6.u32l;
    // 0x80000760: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80000764: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80000768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000076C: swc1        $f8, 0x25C0($at)
    MEM_W(0X25C0, ctx->r1) = ctx->f8.u32l;
    // 0x80000770: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80000774: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80000778: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000077C: swc1        $f10, 0x25C8($at)
    MEM_W(0X25C8, ctx->r1) = ctx->f10.u32l;
    // 0x80000780: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80000784: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80000788: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8000078C: jal         0x800BDC70
    // 0x80000790: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BDC70(rdram, ctx);
        goto after_12;
    // 0x80000790: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x80000794: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000798: sw          $zero, 0x70E4($at)
    MEM_W(0X70E4, ctx->r1) = 0;
    // 0x8000079C: sw          $zero, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = 0;
L_800007A0:
    // 0x800007A0: lw          $a0, 0x1DC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1DC);
    // 0x800007A4: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800007A8: jal         0x800BECCC
    // 0x800007AC: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    Main_SetContRawStickScale(rdram, ctx);
        goto after_13;
    // 0x800007AC: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_13:
    // 0x800007B0: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x800007B4: nop

    // 0x800007B8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800007BC: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x800007C0: bne         $at, $zero, L_800007A0
    if (ctx->r1 != 0) {
        // 0x800007C4: sw          $t5, 0x1DC($sp)
        MEM_W(0X1DC, ctx->r29) = ctx->r13;
            goto L_800007A0;
    }
    // 0x800007C4: sw          $t5, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r13;
    // 0x800007C8: jal         0x80083EAC
    // 0x800007CC: nop

    func_80083EAC(rdram, ctx);
        goto after_14;
    // 0x800007CC: nop

    after_14:
    // 0x800007D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800007D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800007D8: sh          $t6, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r14;
    // 0x800007DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800007E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800007E4: sh          $t7, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r15;
    // 0x800007E8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800007EC: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800007F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800007F4: sh          $t8, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r24;
    // 0x800007F8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800007FC: lh          $t9, 0x723C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X723C);
    // 0x80000800: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000804: sh          $t9, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r25;
    // 0x80000808: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000080C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000810: sh          $t0, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r8;
    // 0x80000814: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80000818: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000081C: sh          $t1, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r9;
    // 0x80000820: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x80000824: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000828: sh          $t2, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r10;
    // 0x8000082C: addiu       $t3, $zero, -0x2
    ctx->r11 = ADD32(0, -0X2);
    // 0x80000830: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000834: sh          $t3, -0x73A8($at)
    MEM_H(-0X73A8, ctx->r1) = ctx->r11;
    // 0x80000838: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000083C: sh          $zero, -0x7280($at)
    MEM_H(-0X7280, ctx->r1) = 0;
    // 0x80000840: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000844: sh          $zero, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = 0;
    // 0x80000848: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000084C: sh          $zero, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = 0;
    // 0x80000850: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000854: sb          $zero, 0x7141($at)
    MEM_B(0X7141, ctx->r1) = 0;
    // 0x80000858: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000085C: sw          $zero, -0x2828($at)
    MEM_W(-0X2828, ctx->r1) = 0;
    // 0x80000860: sw          $zero, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = 0;
L_80000864:
    // 0x80000864: lw          $t4, 0x1DC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1DC);
    // 0x80000868: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000086C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80000870: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80000874: sh          $zero, -0x7278($at)
    MEM_H(-0X7278, ctx->r1) = 0;
    // 0x80000878: lw          $t6, 0x1DC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1DC);
    // 0x8000087C: nop

    // 0x80000880: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80000884: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x80000888: bne         $at, $zero, L_80000864
    if (ctx->r1 != 0) {
        // 0x8000088C: sw          $t7, 0x1DC($sp)
        MEM_W(0X1DC, ctx->r29) = ctx->r15;
            goto L_80000864;
    }
    // 0x8000088C: sw          $t7, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r15;
    // 0x80000890: jal         0x800044BC
    // 0x80000894: nop

    func_800044BC(rdram, ctx);
        goto after_15;
    // 0x80000894: nop

    after_15:
    // 0x80000898: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000089C: sw          $zero, 0x3080($at)
    MEM_W(0X3080, ctx->r1) = 0;
    // 0x800008A0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x800008A4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800008A8: sw          $t8, 0x18E4($at)
    MEM_W(0X18E4, ctx->r1) = ctx->r24;
    // 0x800008AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800008B0: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
    // 0x800008B4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800008B8: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x800008BC: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800008C0: nop

    // 0x800008C4: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x800008C8: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
    // 0x800008CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800008D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800008D4: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x800008D8: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x800008DC: lui         $a2, 0x809A
    ctx->r6 = S32(0X809A << 16);
    // 0x800008E0: jal         0x800BD1FC
    // 0x800008E4: addiu       $a2, $a2, -0x6560
    ctx->r6 = ADD32(ctx->r6, -0X6560);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_16;
    // 0x800008E4: addiu       $a2, $a2, -0x6560
    ctx->r6 = ADD32(ctx->r6, -0X6560);
    after_16:
    // 0x800008E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800008EC: sw          $v0, -0x780($at)
    MEM_W(-0X780, ctx->r1) = ctx->r2;
    // 0x800008F0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800008F4: lw          $a0, -0x780($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X780);
    // 0x800008F8: jal         0x800BED70
    // 0x800008FC: nop

    Spi_GetHeader(rdram, ctx);
        goto after_17;
    // 0x800008FC: nop

    after_17:
    // 0x80000900: sw          $v0, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r2;
    // 0x80000904: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80000908: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x8000090C: jal         0x800BC918
    // 0x80000910: nop

    SysMem_HeapAllocMark(rdram, ctx);
        goto after_18;
    // 0x80000910: nop

    after_18:
    // 0x80000914: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000918: sw          $v0, -0x78C($at)
    MEM_W(-0X78C, ctx->r1) = ctx->r2;
    // 0x8000091C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80000920: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80000924: lw          $a2, -0x78C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X78C);
    // 0x80000928: lw          $a0, -0x780($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X780);
    // 0x8000092C: lw          $a1, 0x1DC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1DC);
    // 0x80000930: jal         0x800BF0B4
    // 0x80000934: nop

    Spi_DecompressAsset(rdram, ctx);
        goto after_19;
    // 0x80000934: nop

    after_19:
    // 0x80000938: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8000093C: lw          $t2, -0x78C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X78C);
    // 0x80000940: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000944: sw          $t2, -0x780($at)
    MEM_W(-0X780, ctx->r1) = ctx->r10;
    // 0x80000948: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000094C: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80000950: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80000954: nop

    // 0x80000958: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x8000095C: sh          $t5, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r13;
    // 0x80000960: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000964: sw          $zero, 0x3DF4($at)
    MEM_W(0X3DF4, ctx->r1) = 0;
    // 0x80000968: jal         0x800BD620
    // 0x8000096C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BD620(rdram, ctx);
        goto after_20;
    // 0x8000096C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x80000970: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80000974: sw          $zero, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = 0;
    // 0x80000978: jal         0x8005D150
    // 0x8000097C: nop

    func_8005D150(rdram, ctx);
        goto after_21;
    // 0x8000097C: nop

    after_21:
    // 0x80000980: jal         0x8005F01C
    // 0x80000984: nop

    func_8005F01C(rdram, ctx);
        goto after_22;
    // 0x80000984: nop

    after_22:
    // 0x80000988: jal         0x8002856C
    // 0x8000098C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002856C(rdram, ctx);
        goto after_23;
    // 0x8000098C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x80000990: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80000994: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80000998: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8000099C: nop

    // 0x800009A0: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x800009A4: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x800009A8: addiu       $t0, $zero, 0x1388
    ctx->r8 = ADD32(0, 0X1388);
    // 0x800009AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800009B0: sw          $t0, 0x70E8($at)
    MEM_W(0X70E8, ctx->r1) = ctx->r8;
    // 0x800009B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800009B8: sw          $zero, 0x718C($at)
    MEM_W(0X718C, ctx->r1) = 0;
    // 0x800009BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800009C0: sw          $zero, -0x794($at)
    MEM_W(-0X794, ctx->r1) = 0;
    // 0x800009C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800009C8: sh          $zero, 0x72E4($at)
    MEM_H(0X72E4, ctx->r1) = 0;
    // 0x800009CC: addiu       $t1, $zero, 0x1A
    ctx->r9 = ADD32(0, 0X1A);
    // 0x800009D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800009D4: sh          $t1, -0x69F0($at)
    MEM_H(-0X69F0, ctx->r1) = ctx->r9;
    // 0x800009D8: addiu       $t9, $zero, -0x21
    ctx->r25 = ADD32(0, -0X21);
    // 0x800009DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800009E0: sh          $t9, -0x6558($at)
    MEM_H(-0X6558, ctx->r1) = ctx->r25;
    // 0x800009E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800009E8: sh          $zero, 0x72D4($at)
    MEM_H(0X72D4, ctx->r1) = 0;
    // 0x800009EC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800009F0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800009F4: addiu       $t4, $t4, -0x38B8
    ctx->r12 = ADD32(ctx->r12, -0X38B8);
    // 0x800009F8: addiu       $t2, $t2, -0x611C
    ctx->r10 = ADD32(ctx->r10, -0X611C);
    // 0x800009FC: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x80000A00: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80000A04: addiu       $t3, $t3, -0x38B8
    ctx->r11 = ADD32(ctx->r11, -0X38B8);
    // 0x80000A08: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80000A0C: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x80000A10: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80000A14: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80000A18: addiu       $t8, $t8, -0x38B8
    ctx->r24 = ADD32(ctx->r24, -0X38B8);
    // 0x80000A1C: addiu       $t7, $t7, -0x6110
    ctx->r15 = ADD32(ctx->r15, -0X6110);
    // 0x80000A20: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80000A24: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80000A28: addiu       $t0, $t0, -0x38B8
    ctx->r8 = ADD32(ctx->r8, -0X38B8);
    // 0x80000A2C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000A30: sw          $t6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r14;
    // 0x80000A34: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80000A38: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80000A3C: addiu       $t9, $t9, -0x38B8
    ctx->r25 = ADD32(ctx->r25, -0X38B8);
    // 0x80000A40: addiu       $t1, $t1, -0x794
    ctx->r9 = ADD32(ctx->r9, -0X794);
    // 0x80000A44: sw          $t1, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r9;
    // 0x80000A48: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80000A4C: addiu       $t4, $t4, -0x38B8
    ctx->r12 = ADD32(ctx->r12, -0X38B8);
    // 0x80000A50: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80000A54: sw          $t2, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r10;
    // 0x80000A58: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80000A5C: addiu       $t3, $t3, -0x38B8
    ctx->r11 = ADD32(ctx->r11, -0X38B8);
    // 0x80000A60: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80000A64: sw          $t5, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->r13;
    // 0x80000A68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000A6C: sh          $zero, 0x7294($at)
    MEM_H(0X7294, ctx->r1) = 0;
    // 0x80000A70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80000A74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000A78: sh          $t7, 0x72A0($at)
    MEM_H(0X72A0, ctx->r1) = ctx->r15;
    // 0x80000A7C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80000A80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000A84: sh          $t8, -0x7288($at)
    MEM_H(-0X7288, ctx->r1) = ctx->r24;
    // 0x80000A88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000A8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000A90: sh          $t6, -0x7290($at)
    MEM_H(-0X7290, ctx->r1) = ctx->r14;
    // 0x80000A94: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80000A98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80000A9C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AA0: swc1        $f16, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f16.u32l;
    // 0x80000AA4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AA8: sw          $zero, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = 0;
    // 0x80000AAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AB0: sw          $zero, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = 0;
    // 0x80000AB4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AB8: sw          $zero, -0x44FC($at)
    MEM_W(-0X44FC, ctx->r1) = 0;
    // 0x80000ABC: addiu       $t0, $zero, 0x140
    ctx->r8 = ADD32(0, 0X140);
    // 0x80000AC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AC4: sw          $t0, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r8;
    // 0x80000AC8: addiu       $t1, $zero, 0xA8
    ctx->r9 = ADD32(0, 0XA8);
    // 0x80000ACC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AD0: sw          $t1, -0x44F4($at)
    MEM_W(-0X44F4, ctx->r1) = ctx->r9;
    // 0x80000AD4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80000AD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000ADC: swc1        $f18, -0x44F0($at)
    MEM_W(-0X44F0, ctx->r1) = ctx->f18.u32l;
    // 0x80000AE0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80000AE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80000AE8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AEC: swc1        $f4, -0x44EC($at)
    MEM_W(-0X44EC, ctx->r1) = ctx->f4.u32l;
    // 0x80000AF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80000AF4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000AF8: swc1        $f6, -0x44E8($at)
    MEM_W(-0X44E8, ctx->r1) = ctx->f6.u32l;
    // 0x80000AFC: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x80000B00: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000B04: sw          $t9, -0x44E4($at)
    MEM_W(-0X44E4, ctx->r1) = ctx->r25;
    // 0x80000B08: addiu       $t2, $zero, 0x21
    ctx->r10 = ADD32(0, 0X21);
    // 0x80000B0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000B10: sh          $t2, -0x820($at)
    MEM_H(-0X820, ctx->r1) = ctx->r10;
    // 0x80000B14: lui         $a1, 0x4E4A
    ctx->r5 = S32(0X4E4A << 16);
    // 0x80000B18: ori         $a1, $a1, 0x324A
    ctx->r5 = ctx->r5 | 0X324A;
    // 0x80000B1C: jal         0x800AE0C0
    // 0x80000B20: addiu       $a0, $zero, 0x4234
    ctx->r4 = ADD32(0, 0X4234);
    ContPak_SetPfsCodes(rdram, ctx);
        goto after_24;
    // 0x80000B20: addiu       $a0, $zero, 0x4234
    ctx->r4 = ADD32(0, 0X4234);
    after_24:
L_80000B24:
    // 0x80000B24: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80000B28: nop

    // 0x80000B2C: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80000B30: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80000B34: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80000B38: jal         0x8000A2C0
    // 0x80000B3C: nop

    func_8000A2C0(rdram, ctx);
        goto after_25;
    // 0x80000B3C: nop

    after_25:
    // 0x80000B40: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80000B44: lw          $t5, -0x5B14($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B14);
    // 0x80000B48: nop

    // 0x80000B4C: beq         $t5, $zero, L_80000BD8
    if (ctx->r13 == 0) {
        // 0x80000B50: nop

            goto L_80000BD8;
    }
    // 0x80000B50: nop

    // 0x80000B54: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80000B58: nop

    // 0x80000B5C: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x80000B60: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80000B64: jal         0x80002F20
    // 0x80000B68: nop

    func_80002F20(rdram, ctx);
        goto after_26;
    // 0x80000B68: nop

    after_26:
    // 0x80000B6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000B70: sh          $zero, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = 0;
    // 0x80000B74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000B78: sh          $zero, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = 0;
    // 0x80000B7C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80000B80: jal         0x8001AFA0
    // 0x80000B84: nop

    func_8001AFA0(rdram, ctx);
        goto after_27;
    // 0x80000B84: nop

    after_27:
    // 0x80000B88: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80000B8C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80000B90: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x80000B94: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80000B98: nop

    // 0x80000B9C: bne         $t7, $t8, L_80000BD0
    if (ctx->r15 != ctx->r24) {
        // 0x80000BA0: nop

            goto L_80000BD0;
    }
    // 0x80000BA0: nop

    // 0x80000BA4: bne         $t7, $zero, L_80000BD0
    if (ctx->r15 != 0) {
        // 0x80000BA8: nop

            goto L_80000BD0;
    }
    // 0x80000BA8: nop

    // 0x80000BAC: addiu       $t6, $zero, 0x1F4
    ctx->r14 = ADD32(0, 0X1F4);
    // 0x80000BB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000BB4: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
    // 0x80000BB8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80000BBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000BC0: sh          $t0, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r8;
    // 0x80000BC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000BC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80000BCC: sh          $t1, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r9;
L_80000BD0:
    // 0x80000BD0: b           L_80000BE4
    // 0x80000BD4: nop

        goto L_80000BE4;
    // 0x80000BD4: nop

L_80000BD8:
    // 0x80000BD8: addiu       $t9, $zero, 0x1F4
    ctx->r25 = ADD32(0, 0X1F4);
    // 0x80000BDC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000BE0: sh          $t9, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r25;
L_80000BE4:
    // 0x80000BE4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80000BE8: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x80000BEC: nop

    // 0x80000BF0: bne         $t2, $zero, L_80000C04
    if (ctx->r10 != 0) {
        // 0x80000BF4: nop

            goto L_80000C04;
    }
    // 0x80000BF4: nop

    // 0x80000BF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80000BFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000C00: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
L_80000C04:
    // 0x80000C04: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80000C08: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80000C0C: nop

    // 0x80000C10: bne         $t5, $zero, L_80000C24
    if (ctx->r13 != 0) {
        // 0x80000C14: nop

            goto L_80000C24;
    }
    // 0x80000C14: nop

    // 0x80000C18: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80000C1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000C20: sh          $t3, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r11;
L_80000C24:
    // 0x80000C24: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80000C28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80000C2C: sw          $t8, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r24;
    // 0x80000C30: jal         0x80098820
    // 0x80000C34: nop

    func_80098820(rdram, ctx);
        goto after_28;
    // 0x80000C34: nop

    after_28:
    // 0x80000C38: jal         0x80098868
    // 0x80000C3C: nop

    func_80098868(rdram, ctx);
        goto after_29;
    // 0x80000C3C: nop

    after_29:
    // 0x80000C40: jal         0x800C0A40
    // 0x80000C44: nop

    func_800C0A40(rdram, ctx);
        goto after_30;
    // 0x80000C44: nop

    after_30:
    // 0x80000C48: jal         0x800BCB54
    // 0x80000C4C: nop

    func_800BCB54(rdram, ctx);
        goto after_31;
    // 0x80000C4C: nop

    after_31:
    // 0x80000C50: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80000C54: nop

    // 0x80000C58: addiu       $at, $t7, 0x7FFF
    ctx->r1 = ADD32(ctx->r15, 0X7FFF);
    // 0x80000C5C: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80000C60: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80000C64: jal         0x80000C90
    // 0x80000C68: nop

    func_80000C90(rdram, ctx);
        goto after_32;
    // 0x80000C68: nop

    after_32:
    // 0x80000C6C: b           L_80000B24
    // 0x80000C70: nop

        goto L_80000B24;
    // 0x80000C70: nop

    // 0x80000C74: b           L_80000C7C
    // 0x80000C78: nop

        goto L_80000C7C;
    // 0x80000C78: nop

L_80000C7C:
    // 0x80000C7C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80000C80: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80000C84: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80000C88: jr          $ra
    // 0x80000C8C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    return;
    // 0x80000C8C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
;}
RECOMP_FUNC void func_80000C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C90: addiu       $sp, $sp, -0x430
    ctx->r29 = ADD32(ctx->r29, -0X430);
    // 0x80000C94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000C98: sw          $a0, 0x430($sp)
    MEM_W(0X430, ctx->r29) = ctx->r4;
    // 0x80000C9C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80000CA0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000CA4: sw          $zero, 0x3DF4($at)
    MEM_W(0X3DF4, ctx->r1) = 0;
    // 0x80000CA8: lw          $t6, 0x430($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X430);
    // 0x80000CAC: nop

    // 0x80000CB0: sw          $t6, 0x414($sp)
    MEM_W(0X414, ctx->r29) = ctx->r14;
    // 0x80000CB4: lw          $t7, 0x414($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X414);
    // 0x80000CB8: nop

    // 0x80000CBC: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80000CC0: nop

    // 0x80000CC4: sw          $t8, 0x410($sp)
    MEM_W(0X410, ctx->r29) = ctx->r24;
    // 0x80000CC8: sw          $zero, 0x420($sp)
    MEM_W(0X420, ctx->r29) = 0;
    // 0x80000CCC: sw          $zero, 0x428($sp)
    MEM_W(0X428, ctx->r29) = 0;
    // 0x80000CD0: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80000CD4: sh          $t9, 0x3EC($sp)
    MEM_H(0X3EC, ctx->r29) = ctx->r25;
    // 0x80000CD8: addiu       $t0, $zero, 0x21
    ctx->r8 = ADD32(0, 0X21);
    // 0x80000CDC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80000CE0: sh          $t0, -0x820($at)
    MEM_H(-0X820, ctx->r1) = ctx->r8;
    // 0x80000CE4: jal         0x80098820
    // 0x80000CE8: nop

    func_80098820(rdram, ctx);
        goto after_0;
    // 0x80000CE8: nop

    after_0:
    // 0x80000CEC: jal         0x80098868
    // 0x80000CF0: nop

    func_80098868(rdram, ctx);
        goto after_1;
    // 0x80000CF0: nop

    after_1:
    // 0x80000CF4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80000CF8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80000CFC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80000D00: nop

    // 0x80000D04: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80000D08: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
    // 0x80000D0C: lw          $t4, 0x414($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X414);
    // 0x80000D10: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x80000D14: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x80000D18: jal         0x800C1264
    // 0x80000D1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_2;
    // 0x80000D1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80000D20: lw          $t5, 0x428($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X428);
    // 0x80000D24: nop

    // 0x80000D28: bne         $t5, $zero, L_80001F3C
    if (ctx->r13 != 0) {
        // 0x80000D2C: nop

            goto L_80001F3C;
    }
    // 0x80000D2C: nop

L_80000D30:
    // 0x80000D30: lw          $t6, 0x414($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X414);
    // 0x80000D34: addiu       $a1, $sp, 0x40C
    ctx->r5 = ADD32(ctx->r29, 0X40C);
    // 0x80000D38: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80000D3C: jal         0x800C143C
    // 0x80000D40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_3;
    // 0x80000D40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80000D44: lw          $t7, 0x40C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40C);
    // 0x80000D48: nop

    // 0x80000D4C: lh          $s0, 0x0($t7)
    ctx->r16 = MEM_H(ctx->r15, 0X0);
    // 0x80000D50: nop

    // 0x80000D54: slti        $at, $s0, 0x21
    ctx->r1 = SIGNED(ctx->r16) < 0X21 ? 1 : 0;
    // 0x80000D58: bne         $at, $zero, L_80000D74
    if (ctx->r1 != 0) {
        // 0x80000D5C: nop

            goto L_80000D74;
    }
    // 0x80000D5C: nop

    // 0x80000D60: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80000D64: beq         $s0, $at, L_80001DAC
    if (ctx->r16 == ctx->r1) {
        // 0x80000D68: nop

            goto L_80001DAC;
    }
    // 0x80000D68: nop

    // 0x80000D6C: b           L_80001F24
    // 0x80000D70: nop

        goto L_80001F24;
    // 0x80000D70: nop

L_80000D74:
    // 0x80000D74: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80000D78: bne         $at, $zero, L_80000D94
    if (ctx->r1 != 0) {
        // 0x80000D7C: nop

            goto L_80000D94;
    }
    // 0x80000D7C: nop

    // 0x80000D80: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80000D84: beq         $s0, $at, L_80000DC0
    if (ctx->r16 == ctx->r1) {
        // 0x80000D88: nop

            goto L_80000DC0;
    }
    // 0x80000D88: nop

    // 0x80000D8C: b           L_80001F24
    // 0x80000D90: nop

        goto L_80001F24;
    // 0x80000D90: nop

L_80000D94:
    // 0x80000D94: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x80000D98: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80000D9C: beq         $at, $zero, L_80001F24
    if (ctx->r1 == 0) {
        // 0x80000DA0: nop

            goto L_80001F24;
    }
    // 0x80000DA0: nop

    // 0x80000DA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80000DA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80000DAC: addu        $at, $at, $t8
    gpr jr_addend_80000DB8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80000DB0: lw          $t8, -0x2EC0($at)
    ctx->r24 = ADD32(ctx->r1, -0X2EC0);
    // 0x80000DB4: nop

    // 0x80000DB8: jr          $t8
    // 0x80000DBC: nop

    switch (jr_addend_80000DB8 >> 2) {
        case 0: goto L_800012FC; break;
        case 1: goto L_80001878; break;
        case 2: goto L_80001F1C; break;
        case 3: goto L_80001F04; break;
        case 4: goto L_800019A4; break;
        default: switch_error(__func__, 0x80000DB8, 0x800ED140);
    }
    // 0x80000DBC: nop

L_80000DC0:
    // 0x80000DC0: jal         0x80098BF4
    // 0x80000DC4: nop

    func_80098BF4(rdram, ctx);
        goto after_4;
    // 0x80000DC4: nop

    after_4:
    // 0x80000DC8: sw          $zero, 0x418($sp)
    MEM_W(0X418, ctx->r29) = 0;
L_80000DCC:
    // 0x80000DCC: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80000DD0: addiu       $a1, $sp, 0x40C
    ctx->r5 = ADD32(ctx->r29, 0X40C);
    // 0x80000DD4: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80000DD8: jal         0x800C143C
    // 0x80000DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_5;
    // 0x80000DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80000DE0: lw          $t0, 0x40C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40C);
    // 0x80000DE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000DE8: lh          $s0, 0x0($t0)
    ctx->r16 = MEM_H(ctx->r8, 0X0);
    // 0x80000DEC: nop

    // 0x80000DF0: beq         $s0, $at, L_80000E18
    if (ctx->r16 == ctx->r1) {
        // 0x80000DF4: nop

            goto L_80000E18;
    }
    // 0x80000DF4: nop

    // 0x80000DF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80000DFC: beq         $s0, $at, L_80000E30
    if (ctx->r16 == ctx->r1) {
        // 0x80000E00: nop

            goto L_80000E30;
    }
    // 0x80000E00: nop

    // 0x80000E04: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80000E08: beq         $s0, $at, L_80000E18
    if (ctx->r16 == ctx->r1) {
        // 0x80000E0C: nop

            goto L_80000E18;
    }
    // 0x80000E0C: nop

    // 0x80000E10: b           L_80000E60
    // 0x80000E14: nop

        goto L_80000E60;
    // 0x80000E14: nop

L_80000E18:
    // 0x80000E18: lw          $t2, 0x418($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X418);
    // 0x80000E1C: nop

    // 0x80000E20: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80000E24: sw          $t3, 0x418($sp)
    MEM_W(0X418, ctx->r29) = ctx->r11;
    // 0x80000E28: b           L_80000E60
    // 0x80000E2C: nop

        goto L_80000E60;
    // 0x80000E2C: nop

L_80000E30:
    // 0x80000E30: jal         0x80099520
    // 0x80000E34: nop

    func_80099520(rdram, ctx);
        goto after_6;
    // 0x80000E34: nop

    after_6:
    // 0x80000E38: lw          $t1, 0x410($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X410);
    // 0x80000E3C: nop

    // 0x80000E40: addiu       $t4, $t1, 0x7FFF
    ctx->r12 = ADD32(ctx->r9, 0X7FFF);
    // 0x80000E44: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x80000E48: addiu       $at, $t1, 0x7FFF
    ctx->r1 = ADD32(ctx->r9, 0X7FFF);
    // 0x80000E4C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80000E50: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
    // 0x80000E54: sw          $zero, 0x418($sp)
    MEM_W(0X418, ctx->r29) = 0;
    // 0x80000E58: b           L_80000E60
    // 0x80000E5C: nop

        goto L_80000E60;
    // 0x80000E5C: nop

L_80000E60:
    // 0x80000E60: lw          $t6, 0x418($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X418);
    // 0x80000E64: nop

    // 0x80000E68: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80000E6C: bne         $at, $zero, L_80000DCC
    if (ctx->r1 != 0) {
        // 0x80000E70: nop

            goto L_80000DCC;
    }
    // 0x80000E70: nop

    // 0x80000E74: jal         0x80098820
    // 0x80000E78: nop

    func_80098820(rdram, ctx);
        goto after_7;
    // 0x80000E78: nop

    after_7:
    // 0x80000E7C: jal         0x80098868
    // 0x80000E80: nop

    func_80098868(rdram, ctx);
        goto after_8;
    // 0x80000E80: nop

    after_8:
    // 0x80000E84: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80000E88: lw          $t7, 0x60E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X60E4);
    // 0x80000E8C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80000E90: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80000E94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000E98: sw          $t8, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r24;
    // 0x80000E9C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80000EA0: lw          $t9, 0x60E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X60E4);
    // 0x80000EA4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80000EA8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80000EAC: sw          $t0, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r8;
    // 0x80000EB0: sw          $zero, 0x420($sp)
    MEM_W(0X420, ctx->r29) = 0;
    // 0x80000EB4: jal         0x80002F20
    // 0x80000EB8: nop

    func_80002F20(rdram, ctx);
        goto after_9;
    // 0x80000EB8: nop

    after_9:
    // 0x80000EBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000EC0: bne         $v0, $at, L_80000ED0
    if (ctx->r2 != ctx->r1) {
        // 0x80000EC4: nop

            goto L_80000ED0;
    }
    // 0x80000EC4: nop

L_80000EC8:
    // 0x80000EC8: b           L_80000EC8
    pause_self(rdram);
    // 0x80000ECC: nop

L_80000ED0:
    // 0x80000ED0: addiu       $t2, $sp, 0x38
    ctx->r10 = ADD32(ctx->r29, 0X38);
    // 0x80000ED4: sw          $t2, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r10;
    // 0x80000ED8: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80000EDC: jal         0x80099E2C
    // 0x80000EE0: nop

    func_80099E2C(rdram, ctx);
        goto after_10;
    // 0x80000EE0: nop

    after_10:
    // 0x80000EE4: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80000EE8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80000EEC: jal         0x800B1B04
    // 0x80000EF0: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    func_800B1B04(rdram, ctx);
        goto after_11;
    // 0x80000EF0: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    after_11:
    // 0x80000EF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80000EF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80000EFC: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80000F00: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80000F04: lui         $a2, 0x69
    ctx->r6 = S32(0X69 << 16);
    // 0x80000F08: ori         $a2, $a2, 0x221
    ctx->r6 = ctx->r6 | 0X221;
    // 0x80000F0C: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    // 0x80000F10: addiu       $a3, $zero, 0x5F
    ctx->r7 = ADD32(0, 0X5F);
    // 0x80000F14: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80000F18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80000F1C: jal         0x800B1F0C
    // 0x80000F20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_12;
    // 0x80000F20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x80000F24: lw          $t3, 0x280($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X280);
    // 0x80000F28: nop

    // 0x80000F2C: lw          $t4, 0xC0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC0);
    // 0x80000F30: nop

    // 0x80000F34: ori         $t5, $t4, 0x208
    ctx->r13 = ctx->r12 | 0X208;
    // 0x80000F38: sw          $t5, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r13;
    // 0x80000F3C: lw          $t6, 0x280($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X280);
    // 0x80000F40: lui         $t1, 0x7FFF
    ctx->r9 = S32(0X7FFF << 16);
    // 0x80000F44: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80000F48: sw          $t1, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r9;
    // 0x80000F4C: jal         0x800AD774
    // 0x80000F50: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800AD774(rdram, ctx);
        goto after_13;
    // 0x80000F50: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80000F54: lw          $t7, 0x280($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X280);
    // 0x80000F58: nop

    // 0x80000F5C: sh          $v0, 0xC4($t7)
    MEM_H(0XC4, ctx->r15) = ctx->r2;
    // 0x80000F60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80000F64: sw          $t8, 0x420($sp)
    MEM_W(0X420, ctx->r29) = ctx->r24;
    // 0x80000F68: lw          $t9, 0x410($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X410);
    // 0x80000F6C: nop

    // 0x80000F70: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80000F74: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80000F78: jal         0x80098820
    // 0x80000F7C: nop

    func_80098820(rdram, ctx);
        goto after_14;
    // 0x80000F7C: nop

    after_14:
    // 0x80000F80: jal         0x80098868
    // 0x80000F84: nop

    func_80098868(rdram, ctx);
        goto after_15;
    // 0x80000F84: nop

    after_15:
    // 0x80000F88: lw          $t0, 0x414($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X414);
    // 0x80000F8C: nop

    // 0x80000F90: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80000F94: jal         0x800C13B8
    // 0x80000F98: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_16;
    // 0x80000F98: nop

    after_16:
    // 0x80000F9C: lw          $t2, 0x414($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X414);
    // 0x80000FA0: nop

    // 0x80000FA4: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x80000FA8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80000FAC: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80000FB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000FB4: sh          $t4, 0x7320($at)
    MEM_H(0X7320, ctx->r1) = ctx->r12;
    // 0x80000FB8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80000FBC: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80000FC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80000FC4: sh          $t5, 0x7338($at)
    MEM_H(0X7338, ctx->r1) = ctx->r13;
    // 0x80000FC8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80000FCC: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80000FD0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80000FD4: bne         $t3, $at, L_80000FF0
    if (ctx->r11 != ctx->r1) {
        // 0x80000FD8: nop

            goto L_80000FF0;
    }
    // 0x80000FD8: nop

    // 0x80000FDC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80000FE0: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x80000FE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000FE8: beq         $t1, $at, L_80001018
    if (ctx->r9 == ctx->r1) {
        // 0x80000FEC: nop

            goto L_80001018;
    }
    // 0x80000FEC: nop

L_80000FF0:
    // 0x80000FF0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80000FF4: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x80000FF8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80000FFC: bne         $t6, $at, L_8000105C
    if (ctx->r14 != ctx->r1) {
        // 0x80001000: nop

            goto L_8000105C;
    }
    // 0x80001000: nop

    // 0x80001004: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80001008: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x8000100C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001010: bne         $t7, $at, L_8000105C
    if (ctx->r15 != ctx->r1) {
        // 0x80001014: nop

            goto L_8000105C;
    }
    // 0x80001014: nop

L_80001018:
    // 0x80001018: jal         0x80098BF4
    // 0x8000101C: nop

    func_80098BF4(rdram, ctx);
        goto after_17;
    // 0x8000101C: nop

    after_17:
    // 0x80001020: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x80001024: jal         0x800077A0
    // 0x80001028: nop

    func_800077A0(rdram, ctx);
        goto after_18;
    // 0x80001028: nop

    after_18:
    // 0x8000102C: lw          $t8, 0x414($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X414);
    // 0x80001030: nop

    // 0x80001034: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80001038: jal         0x800C13B8
    // 0x8000103C: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_19;
    // 0x8000103C: nop

    after_19:
    // 0x80001040: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80001044: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x80001048: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x8000104C: jal         0x800C1264
    // 0x80001050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_20;
    // 0x80001050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x80001054: b           L_800012F4
    // 0x80001058: nop

        goto L_800012F4;
    // 0x80001058: nop

L_8000105C:
    // 0x8000105C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80001060: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x80001064: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80001068: bne         $t0, $at, L_8000118C
    if (ctx->r8 != ctx->r1) {
        // 0x8000106C: nop

            goto L_8000118C;
    }
    // 0x8000106C: nop

    // 0x80001070: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80001074: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x80001078: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8000107C: bne         $t2, $at, L_8000118C
    if (ctx->r10 != ctx->r1) {
        // 0x80001080: nop

            goto L_8000118C;
    }
    // 0x80001080: nop

    // 0x80001084: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80001088: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000108C: sh          $t4, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r12;
    // 0x80001090: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x80001094: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001098: sh          $t5, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r13;
    // 0x8000109C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800010A0: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x800010A4: lhu         $t1, 0x6($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X6);
    // 0x800010A8: nop

    // 0x800010AC: ori         $t6, $t1, 0x8000
    ctx->r14 = ctx->r9 | 0X8000;
    // 0x800010B0: sh          $t6, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r14;
    // 0x800010B4: jal         0x80098BF4
    // 0x800010B8: nop

    func_80098BF4(rdram, ctx);
        goto after_21;
    // 0x800010B8: nop

    after_21:
    // 0x800010BC: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x800010C0: jal         0x80005880
    // 0x800010C4: nop

    func_80005880(rdram, ctx);
        goto after_22;
    // 0x800010C4: nop

    after_22:
    // 0x800010C8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800010CC: lh          $t7, 0x7254($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7254);
    // 0x800010D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800010D4: andi        $t8, $t7, 0x7FFF
    ctx->r24 = ctx->r15 & 0X7FFF;
    // 0x800010D8: sh          $t8, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r24;
    // 0x800010DC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800010E0: lh          $t9, 0x725C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X725C);
    // 0x800010E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800010E8: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x800010EC: sh          $t0, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r8;
    // 0x800010F0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800010F4: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800010F8: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x800010FC: nop

    // 0x80001100: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80001104: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x80001108: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8000110C: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80001110: sh          $zero, 0x2($t1)
    MEM_H(0X2, ctx->r9) = 0;
    // 0x80001114: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80001118: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8000111C: lhu         $t3, 0x6($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0X6);
    // 0x80001120: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80001124: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80001128: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8000112C: sh          $t7, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r15;
    // 0x80001130: jal         0x80016074
    // 0x80001134: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_23;
    // 0x80001134: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_23:
    // 0x80001138: sw          $v0, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r2;
    // 0x8000113C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80001140: lw          $t8, 0x274($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X274);
    // 0x80001144: nop

    // 0x80001148: swc1        $f8, 0x1E8($t8)
    MEM_W(0X1E8, ctx->r24) = ctx->f8.u32l;
    // 0x8000114C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80001150: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001154: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001158: swc1        $f10, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f10.u32l;
    // 0x8000115C: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80001160: nop

    // 0x80001164: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80001168: jal         0x800C13B8
    // 0x8000116C: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_24;
    // 0x8000116C: nop

    after_24:
    // 0x80001170: lw          $t0, 0x414($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X414);
    // 0x80001174: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x80001178: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8000117C: jal         0x800C1264
    // 0x80001180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_25;
    // 0x80001180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_25:
    // 0x80001184: b           L_800012F4
    // 0x80001188: nop

        goto L_800012F4;
    // 0x80001188: nop

L_8000118C:
    // 0x8000118C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80001190: lh          $t4, 0x7234($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7234);
    // 0x80001194: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80001198: bne         $t4, $at, L_800012F4
    if (ctx->r12 != ctx->r1) {
        // 0x8000119C: nop

            goto L_800012F4;
    }
    // 0x8000119C: nop

    // 0x800011A0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800011A4: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x800011A8: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800011AC: bne         $t5, $at, L_800012F4
    if (ctx->r13 != ctx->r1) {
        // 0x800011B0: nop

            goto L_800012F4;
    }
    // 0x800011B0: nop

    // 0x800011B4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800011B8: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800011BC: lhu         $t1, 0x4($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X4);
    // 0x800011C0: nop

    // 0x800011C4: andi        $t3, $t1, 0x10
    ctx->r11 = ctx->r9 & 0X10;
    // 0x800011C8: bne         $t3, $zero, L_80001268
    if (ctx->r11 != 0) {
        // 0x800011CC: nop

            goto L_80001268;
    }
    // 0x800011CC: nop

    // 0x800011D0: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x800011D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800011D8: sh          $t7, 0x72AC($at)
    MEM_H(0X72AC, ctx->r1) = ctx->r15;
    // 0x800011DC: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x800011E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800011E4: sh          $t6, 0x72B4($at)
    MEM_H(0X72B4, ctx->r1) = ctx->r14;
    // 0x800011E8: jal         0x80098BF4
    // 0x800011EC: nop

    func_80098BF4(rdram, ctx);
        goto after_26;
    // 0x800011EC: nop

    after_26:
    // 0x800011F0: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x800011F4: jal         0x80005880
    // 0x800011F8: nop

    func_80005880(rdram, ctx);
        goto after_27;
    // 0x800011F8: nop

    after_27:
    // 0x800011FC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80001200: lh          $t8, 0x7254($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7254);
    // 0x80001204: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001208: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x8000120C: sh          $t9, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r25;
    // 0x80001210: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80001214: lh          $t0, 0x725C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X725C);
    // 0x80001218: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000121C: andi        $t4, $t0, 0x7FFF
    ctx->r12 = ctx->r8 & 0X7FFF;
    // 0x80001220: sh          $t4, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r12;
    // 0x80001224: jal         0x80016074
    // 0x80001228: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_28;
    // 0x80001228: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_28:
    // 0x8000122C: sw          $v0, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r2;
    // 0x80001230: lw          $t5, 0x274($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X274);
    // 0x80001234: nop

    // 0x80001238: beq         $t5, $zero, L_80001260
    if (ctx->r13 == 0) {
        // 0x8000123C: nop

            goto L_80001260;
    }
    // 0x8000123C: nop

    // 0x80001240: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80001244: lw          $t2, 0x274($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X274);
    // 0x80001248: nop

    // 0x8000124C: swc1        $f16, 0x1E8($t2)
    MEM_W(0X1E8, ctx->r10) = ctx->f16.u32l;
    // 0x80001250: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80001254: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80001258: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000125C: swc1        $f18, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f18.u32l;
L_80001260:
    // 0x80001260: b           L_800012A8
    // 0x80001264: nop

        goto L_800012A8;
    // 0x80001264: nop

L_80001268:
    // 0x80001268: jal         0x80083F28
    // 0x8000126C: nop

    func_80083F28(rdram, ctx);
        goto after_29;
    // 0x8000126C: nop

    after_29:
    // 0x80001270: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80001274: sh          $v0, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r2;
    // 0x80001278: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000127C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001280: sh          $t1, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r9;
    // 0x80001284: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001288: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000128C: sh          $t3, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r11;
    // 0x80001290: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80001294: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001298: sh          $t7, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r15;
    // 0x8000129C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800012A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800012A4: sh          $t6, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r14;
L_800012A8:
    // 0x800012A8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800012AC: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800012B0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800012B4: nop

    // 0x800012B8: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x800012BC: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x800012C0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800012C4: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x800012C8: sh          $zero, 0x2($t4)
    MEM_H(0X2, ctx->r12) = 0;
    // 0x800012CC: lw          $t5, 0x414($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X414);
    // 0x800012D0: nop

    // 0x800012D4: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x800012D8: jal         0x800C13B8
    // 0x800012DC: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_30;
    // 0x800012DC: nop

    after_30:
    // 0x800012E0: lw          $t2, 0x414($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X414);
    // 0x800012E4: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x800012E8: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x800012EC: jal         0x800C1264
    // 0x800012F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_31;
    // 0x800012F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
L_800012F4:
    // 0x800012F4: b           L_80001F2C
    // 0x800012F8: nop

        goto L_80001F2C;
    // 0x800012F8: nop

L_800012FC:
    // 0x800012FC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80001300: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80001304: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80001308: nop

    // 0x8000130C: andi        $t7, $t3, 0x2
    ctx->r15 = ctx->r11 & 0X2;
    // 0x80001310: bne         $t7, $zero, L_80001870
    if (ctx->r15 != 0) {
        // 0x80001314: nop

            goto L_80001870;
    }
    // 0x80001314: nop

    // 0x80001318: lw          $t6, 0x410($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X410);
    // 0x8000131C: nop

    // 0x80001320: addiu       $t9, $t6, 0x7FFF
    ctx->r25 = ADD32(ctx->r14, 0X7FFF);
    // 0x80001324: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x80001328: nop

    // 0x8000132C: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80001330: beq         $at, $zero, L_80001870
    if (ctx->r1 == 0) {
        // 0x80001334: nop

            goto L_80001870;
    }
    // 0x80001334: nop

    // 0x80001338: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000133C: lw          $t0, 0x60E4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X60E4);
    // 0x80001340: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80001344: and         $t8, $t0, $at
    ctx->r24 = ctx->r8 & ctx->r1;
    // 0x80001348: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000134C: sw          $t8, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r24;
    // 0x80001350: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80001354: lw          $t4, 0x60E4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X60E4);
    // 0x80001358: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000135C: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80001360: sw          $t5, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r13;
    // 0x80001364: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80001368: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000136C: sw          $t2, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = ctx->r10;
    // 0x80001370: jal         0x80032380
    // 0x80001374: nop

    func_80032380(rdram, ctx);
        goto after_32;
    // 0x80001374: nop

    after_32:
    // 0x80001378: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000137C: lw          $t1, 0x60E4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X60E4);
    // 0x80001380: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80001384: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x80001388: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000138C: sw          $t3, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r11;
    // 0x80001390: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80001394: lw          $t7, 0x60E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X60E4);
    // 0x80001398: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000139C: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x800013A0: sw          $t6, 0x60E4($at)
    MEM_W(0X60E4, ctx->r1) = ctx->r14;
    // 0x800013A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800013A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800013AC: sw          $t9, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = ctx->r25;
    // 0x800013B0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800013B4: lw          $t0, 0x258C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X258C);
    // 0x800013B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800013BC: sw          $t0, 0x30AC($at)
    MEM_W(0X30AC, ctx->r1) = ctx->r8;
    // 0x800013C0: jal         0x80099768
    // 0x800013C4: nop

    func_80099768(rdram, ctx);
        goto after_33;
    // 0x800013C4: nop

    after_33:
    // 0x800013C8: jal         0x800AFB28
    // 0x800013CC: nop

    func_800AFB28(rdram, ctx);
        goto after_34;
    // 0x800013CC: nop

    after_34:
    // 0x800013D0: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800013D4: lw          $t4, -0x4CC4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CC4);
    // 0x800013D8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800013DC: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800013E0: lw          $t8, -0x4CCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CCC);
    // 0x800013E4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800013E8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800013EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800013F0: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x800013F4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800013F8: jal         0x800BE510
    // 0x800013FC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800BE510(rdram, ctx);
        goto after_35;
    // 0x800013FC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_35:
    // 0x80001400: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80001404: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80001408: lw          $t2, -0x4CC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CC4);
    // 0x8000140C: lw          $t5, -0x4CCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4CCC);
    // 0x80001410: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80001414: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80001418: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000141C: jal         0x8009A04C
    // 0x80001420: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_8009A04C(rdram, ctx);
        goto after_36;
    // 0x80001420: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_36:
    // 0x80001424: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80001428: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000142C: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80001430: nop

    // 0x80001434: andi        $t7, $t3, 0x8
    ctx->r15 = ctx->r11 & 0X8;
    // 0x80001438: beq         $t7, $zero, L_80001448
    if (ctx->r15 == 0) {
        // 0x8000143C: nop

            goto L_80001448;
    }
    // 0x8000143C: nop

    // 0x80001440: jal         0x80033788
    // 0x80001444: nop

    func_80033788(rdram, ctx);
        goto after_37;
    // 0x80001444: nop

    after_37:
L_80001448:
    // 0x80001448: jal         0x80032604
    // 0x8000144C: nop

    func_80032604(rdram, ctx);
        goto after_38;
    // 0x8000144C: nop

    after_38:
    // 0x80001450: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80001454: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x80001458: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000145C: jal         0x8000262C
    // 0x80001460: addiu       $a1, $t6, 0x580
    ctx->r5 = ADD32(ctx->r14, 0X580);
    func_8000262C(rdram, ctx);
        goto after_39;
    // 0x80001460: addiu       $a1, $t6, 0x580
    ctx->r5 = ADD32(ctx->r14, 0X580);
    after_39:
    // 0x80001464: jal         0x80002824
    // 0x80001468: nop

    func_80002824(rdram, ctx);
        goto after_40;
    // 0x80001468: nop

    after_40:
    // 0x8000146C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80001470: lh          $t9, 0x721C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X721C);
    // 0x80001474: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001478: bne         $t9, $at, L_80001488
    if (ctx->r25 != ctx->r1) {
        // 0x8000147C: nop

            goto L_80001488;
    }
    // 0x8000147C: nop

    // 0x80001480: jal         0x80034310
    // 0x80001484: nop

    func_80034310(rdram, ctx);
        goto after_41;
    // 0x80001484: nop

    after_41:
L_80001488:
    // 0x80001488: jal         0x8004DEA4
    // 0x8000148C: nop

    func_8004DEA4(rdram, ctx);
        goto after_42;
    // 0x8000148C: nop

    after_42:
    // 0x80001490: jal         0x800305A4
    // 0x80001494: nop

    func_800305A4(rdram, ctx);
        goto after_43;
    // 0x80001494: nop

    after_43:
    // 0x80001498: jal         0x8002A39C
    // 0x8000149C: nop

    func_8002A39C(rdram, ctx);
        goto after_44;
    // 0x8000149C: nop

    after_44:
    // 0x800014A0: jal         0x80082958
    // 0x800014A4: nop

    func_80082958(rdram, ctx);
        goto after_45;
    // 0x800014A4: nop

    after_45:
    // 0x800014A8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800014AC: lw          $t0, -0x73AC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73AC);
    // 0x800014B0: nop

    // 0x800014B4: beq         $t0, $zero, L_80001508
    if (ctx->r8 == 0) {
        // 0x800014B8: sw          $t0, 0x284($sp)
        MEM_W(0X284, ctx->r29) = ctx->r8;
            goto L_80001508;
    }
    // 0x800014B8: sw          $t0, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r8;
L_800014BC:
    // 0x800014BC: jal         0x800C1754
    // 0x800014C0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_46;
    // 0x800014C0: nop

    after_46:
    // 0x800014C4: lw          $a0, 0x284($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X284);
    // 0x800014C8: jal         0x8009A14C
    // 0x800014CC: nop

    func_8009A14C(rdram, ctx);
        goto after_47;
    // 0x800014CC: nop

    after_47:
    // 0x800014D0: lw          $a0, 0x284($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X284);
    // 0x800014D4: jal         0x800997D8
    // 0x800014D8: nop

    func_800997D8(rdram, ctx);
        goto after_48;
    // 0x800014D8: nop

    after_48:
    // 0x800014DC: jal         0x800C1A28
    // 0x800014E0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_49;
    // 0x800014E0: nop

    after_49:
    // 0x800014E4: lw          $t8, 0x284($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X284);
    // 0x800014E8: nop

    // 0x800014EC: lw          $t4, 0x14C($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X14C);
    // 0x800014F0: nop

    // 0x800014F4: sw          $t4, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r12;
    // 0x800014F8: lw          $t5, 0x284($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X284);
    // 0x800014FC: nop

    // 0x80001500: bne         $t5, $zero, L_800014BC
    if (ctx->r13 != 0) {
        // 0x80001504: nop

            goto L_800014BC;
    }
    // 0x80001504: nop

L_80001508:
    // 0x80001508: sw          $zero, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = 0;
    // 0x8000150C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80001510: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80001514: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x80001518: nop

    // 0x8000151C: andi        $t3, $t1, 0x4000
    ctx->r11 = ctx->r9 & 0X4000;
    // 0x80001520: bne         $t3, $zero, L_800015D8
    if (ctx->r11 != 0) {
        // 0x80001524: nop

            goto L_800015D8;
    }
    // 0x80001524: nop

    // 0x80001528: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8000152C: lw          $t7, 0x72DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72DC);
    // 0x80001530: nop

    // 0x80001534: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x80001538: bne         $t6, $zero, L_800015D8
    if (ctx->r14 != 0) {
        // 0x8000153C: nop

            goto L_800015D8;
    }
    // 0x8000153C: nop

    // 0x80001540: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x80001544: nop

    // 0x80001548: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x8000154C: bne         $t0, $zero, L_800015D8
    if (ctx->r8 != 0) {
        // 0x80001550: nop

            goto L_800015D8;
    }
    // 0x80001550: nop

    // 0x80001554: andi        $t8, $t9, 0x400
    ctx->r24 = ctx->r25 & 0X400;
    // 0x80001558: bne         $t8, $zero, L_800015D8
    if (ctx->r24 != 0) {
        // 0x8000155C: nop

            goto L_800015D8;
    }
    // 0x8000155C: nop

    // 0x80001560: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80001564: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80001568: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8000156C: lhu         $t1, 0x11A4($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X11A4);
    // 0x80001570: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80001574: nop

    // 0x80001578: and         $t3, $t5, $t1
    ctx->r11 = ctx->r13 & ctx->r9;
    // 0x8000157C: beq         $t3, $zero, L_800015D8
    if (ctx->r11 == 0) {
        // 0x80001580: nop

            goto L_800015D8;
    }
    // 0x80001580: nop

    // 0x80001584: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80001588: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8000158C: nop

    // 0x80001590: bgez        $t7, L_800015AC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80001594: nop

            goto L_800015AC;
    }
    // 0x80001594: nop

    // 0x80001598: lw          $t6, 0x41C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X41C);
    // 0x8000159C: nop

    // 0x800015A0: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x800015A4: b           L_800015D8
    // 0x800015A8: sw          $t2, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r10;
        goto L_800015D8;
    // 0x800015A8: sw          $t2, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r10;
L_800015AC:
    // 0x800015AC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x800015B0: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x800015B4: lhu         $t9, 0x0($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X0);
    // 0x800015B8: nop

    // 0x800015BC: andi        $t8, $t9, 0x4000
    ctx->r24 = ctx->r25 & 0X4000;
    // 0x800015C0: beq         $t8, $zero, L_800015D8
    if (ctx->r24 == 0) {
        // 0x800015C4: nop

            goto L_800015D8;
    }
    // 0x800015C4: nop

    // 0x800015C8: lw          $t4, 0x41C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X41C);
    // 0x800015CC: nop

    // 0x800015D0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800015D4: sw          $t5, 0x41C($sp)
    MEM_W(0X41C, ctx->r29) = ctx->r13;
L_800015D8:
    // 0x800015D8: lw          $t1, 0x41C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X41C);
    // 0x800015DC: nop

    // 0x800015E0: beq         $t1, $zero, L_800016C4
    if (ctx->r9 == 0) {
        // 0x800015E4: nop

            goto L_800016C4;
    }
    // 0x800015E4: nop

    // 0x800015E8: jal         0x80098BB8
    // 0x800015EC: nop

    func_80098BB8(rdram, ctx);
        goto after_50;
    // 0x800015EC: nop

    after_50:
    // 0x800015F0: sw          $zero, 0x424($sp)
    MEM_W(0X424, ctx->r29) = 0;
    // 0x800015F4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800015F8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800015FC: jal         0x80021FF8
    // 0x80001600: addiu       $a2, $zero, 0x3FFF
    ctx->r6 = ADD32(0, 0X3FFF);
    func_80021FF8(rdram, ctx);
        goto after_51;
    // 0x80001600: addiu       $a2, $zero, 0x3FFF
    ctx->r6 = ADD32(0, 0X3FFF);
    after_51:
    // 0x80001604: addiu       $t3, $sp, 0x38
    ctx->r11 = ADD32(ctx->r29, 0X38);
    // 0x80001608: sw          $t3, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r11;
    // 0x8000160C: lw          $t7, 0x420($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X420);
    // 0x80001610: nop

    // 0x80001614: beq         $t7, $zero, L_80001634
    if (ctx->r15 == 0) {
        // 0x80001618: nop

            goto L_80001634;
    }
    // 0x80001618: nop

    // 0x8000161C: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80001620: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80001624: jal         0x800B1BC8
    // 0x80001628: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    func_800B1BC8(rdram, ctx);
        goto after_52;
    // 0x80001628: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    after_52:
    // 0x8000162C: b           L_80001640
    // 0x80001630: nop

        goto L_80001640;
    // 0x80001630: nop

L_80001634:
    // 0x80001634: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80001638: jal         0x80099E2C
    // 0x8000163C: nop

    func_80099E2C(rdram, ctx);
        goto after_53;
    // 0x8000163C: nop

    after_53:
L_80001640:
    // 0x80001640: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x80001644: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80001648: jal         0x800B1B04
    // 0x8000164C: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    func_800B1B04(rdram, ctx);
        goto after_54;
    // 0x8000164C: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    after_54:
    // 0x80001650: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80001654: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80001658: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x8000165C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80001660: lui         $a2, 0x69
    ctx->r6 = S32(0X69 << 16);
    // 0x80001664: ori         $a2, $a2, 0x221
    ctx->r6 = ctx->r6 | 0X221;
    // 0x80001668: addiu       $a1, $a1, 0x160
    ctx->r5 = ADD32(ctx->r5, 0X160);
    // 0x8000166C: addiu       $a3, $zero, 0x5F
    ctx->r7 = ADD32(0, 0X5F);
    // 0x80001670: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80001674: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80001678: jal         0x800B1F0C
    // 0x8000167C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_55;
    // 0x8000167C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_55:
    // 0x80001680: lw          $t6, 0x280($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X280);
    // 0x80001684: nop

    // 0x80001688: lw          $t2, 0xC0($t6)
    ctx->r10 = MEM_W(ctx->r14, 0XC0);
    // 0x8000168C: nop

    // 0x80001690: ori         $t0, $t2, 0x208
    ctx->r8 = ctx->r10 | 0X208;
    // 0x80001694: sw          $t0, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r8;
    // 0x80001698: lw          $t8, 0x280($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X280);
    // 0x8000169C: lui         $t9, 0x7FFF
    ctx->r25 = S32(0X7FFF << 16);
    // 0x800016A0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800016A4: sw          $t9, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r25;
    // 0x800016A8: jal         0x800AD774
    // 0x800016AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800AD774(rdram, ctx);
        goto after_56;
    // 0x800016AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_56:
    // 0x800016B0: lw          $t4, 0x280($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X280);
    // 0x800016B4: nop

    // 0x800016B8: sh          $v0, 0xC4($t4)
    MEM_H(0XC4, ctx->r12) = ctx->r2;
    // 0x800016BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800016C0: sw          $t5, 0x420($sp)
    MEM_W(0X420, ctx->r29) = ctx->r13;
L_800016C4:
    // 0x800016C4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800016C8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x800016CC: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x800016D0: nop

    // 0x800016D4: andi        $t7, $t3, 0x100
    ctx->r15 = ctx->r11 & 0X100;
    // 0x800016D8: bne         $t7, $zero, L_800016FC
    if (ctx->r15 != 0) {
        // 0x800016DC: nop

            goto L_800016FC;
    }
    // 0x800016DC: nop

    // 0x800016E0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800016E4: jal         0x8009A664
    // 0x800016E8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_57;
    // 0x800016E8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_57:
    // 0x800016EC: jal         0x8002C2F8
    // 0x800016F0: nop

    func_8002C2F8(rdram, ctx);
        goto after_58;
    // 0x800016F0: nop

    after_58:
    // 0x800016F4: b           L_80001710
    // 0x800016F8: nop

        goto L_80001710;
    // 0x800016F8: nop

L_800016FC:
    // 0x800016FC: jal         0x8002C2F8
    // 0x80001700: nop

    func_8002C2F8(rdram, ctx);
        goto after_59;
    // 0x80001700: nop

    after_59:
    // 0x80001704: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80001708: jal         0x8009A664
    // 0x8000170C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_60;
    // 0x8000170C: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_60:
L_80001710:
    // 0x80001710: jal         0x8001635C
    // 0x80001714: nop

    func_8001635C(rdram, ctx);
        goto after_61;
    // 0x80001714: nop

    after_61:
    // 0x80001718: jal         0x800BE684
    // 0x8000171C: nop

    func_800BE684(rdram, ctx);
        goto after_62;
    // 0x8000171C: nop

    after_62:
    // 0x80001720: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80001724: lw          $t2, 0x72DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X72DC);
    // 0x80001728: nop

    // 0x8000172C: andi        $t0, $t2, 0x1
    ctx->r8 = ctx->r10 & 0X1;
    // 0x80001730: beq         $t0, $zero, L_800017C0
    if (ctx->r8 == 0) {
        // 0x80001734: nop

            goto L_800017C0;
    }
    // 0x80001734: nop

    // 0x80001738: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8000173C: sw          $t6, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r14;
    // 0x80001740: jal         0x800C1754
    // 0x80001744: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_63;
    // 0x80001744: nop

    after_63:
    // 0x80001748: lui         $at, 0xC2B0
    ctx->r1 = S32(0XC2B0 << 16);
    // 0x8000174C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001750: lw          $t9, 0x280($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X280);
    // 0x80001754: nop

    // 0x80001758: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x8000175C: lui         $at, 0xC228
    ctx->r1 = S32(0XC228 << 16);
    // 0x80001760: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80001764: lw          $t8, 0x280($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X280);
    // 0x80001768: nop

    // 0x8000176C: swc1        $f6, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f6.u32l;
    // 0x80001770: jal         0x80031AC8
    // 0x80001774: nop

    func_80031AC8(rdram, ctx);
        goto after_64;
    // 0x80001774: nop

    after_64:
    // 0x80001778: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000177C: beq         $v0, $at, L_800017A0
    if (ctx->r2 == ctx->r1) {
        // 0x80001780: nop

            goto L_800017A0;
    }
    // 0x80001780: nop

    // 0x80001784: lw          $t4, 0x280($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X280);
    // 0x80001788: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8000178C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001790: lwc1        $f8, 0xD0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x80001794: nop

    // 0x80001798: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000179C: swc1        $f16, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f16.u32l;
L_800017A0:
    // 0x800017A0: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x800017A4: jal         0x8009A14C
    // 0x800017A8: nop

    func_8009A14C(rdram, ctx);
        goto after_65;
    // 0x800017A8: nop

    after_65:
    // 0x800017AC: lw          $a0, 0x280($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X280);
    // 0x800017B0: jal         0x800997D8
    // 0x800017B4: nop

    func_800997D8(rdram, ctx);
        goto after_66;
    // 0x800017B4: nop

    after_66:
    // 0x800017B8: jal         0x800C1A28
    // 0x800017BC: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_67;
    // 0x800017BC: nop

    after_67:
L_800017C0:
    // 0x800017C0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800017C4: jal         0x8009A664
    // 0x800017C8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_68;
    // 0x800017C8: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_68:
    // 0x800017CC: jal         0x800BE610
    // 0x800017D0: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_69;
    // 0x800017D0: nop

    after_69:
    // 0x800017D4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800017D8: lw          $t5, 0x1B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B4C);
    // 0x800017DC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800017E0: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x800017E4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800017E8: jal         0x8009908C
    // 0x800017EC: subu        $a1, $t1, $t5
    ctx->r5 = SUB32(ctx->r9, ctx->r13);
    CreateGfxTask(rdram, ctx);
        goto after_70;
    // 0x800017EC: subu        $a1, $t1, $t5
    ctx->r5 = SUB32(ctx->r9, ctx->r13);
    after_70:
    // 0x800017F0: lw          $t3, 0x414($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X414);
    // 0x800017F4: nop

    // 0x800017F8: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x800017FC: jal         0x80098D24
    // 0x80001800: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_71;
    // 0x80001800: nop

    after_71:
    // 0x80001804: jal         0x80099450
    // 0x80001808: nop

    func_80099450(rdram, ctx);
        goto after_72;
    // 0x80001808: nop

    after_72:
    // 0x8000180C: jal         0x80001F54
    // 0x80001810: nop

    func_80001F54(rdram, ctx);
        goto after_73;
    // 0x80001810: nop

    after_73:
    // 0x80001814: jal         0x800020A8
    // 0x80001818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800020A8(rdram, ctx);
        goto after_74;
    // 0x80001818: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_74:
    // 0x8000181C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001820: bne         $v0, $at, L_80001854
    if (ctx->r2 != ctx->r1) {
        // 0x80001824: nop

            goto L_80001854;
    }
    // 0x80001824: nop

    // 0x80001828: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000182C: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80001830: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x80001834: nop

    // 0x80001838: ori         $t0, $t2, 0x2
    ctx->r8 = ctx->r10 | 0X2;
    // 0x8000183C: sh          $t0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r8;
    // 0x80001840: lw          $t6, 0x414($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X414);
    // 0x80001844: addiu       $a1, $sp, 0x3EC
    ctx->r5 = ADD32(ctx->r29, 0X3EC);
    // 0x80001848: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8000184C: jal         0x800C1264
    // 0x80001850: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_SendMesgNoBlock(rdram, ctx);
        goto after_75;
    // 0x80001850: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_75:
L_80001854:
    // 0x80001854: lw          $t9, 0x410($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X410);
    // 0x80001858: nop

    // 0x8000185C: addiu       $t8, $t9, 0x7FFF
    ctx->r24 = ADD32(ctx->r25, 0X7FFF);
    // 0x80001860: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x80001864: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80001868: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x8000186C: sw          $t4, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r12;
L_80001870:
    // 0x80001870: b           L_80001F2C
    // 0x80001874: nop

        goto L_80001F2C;
    // 0x80001874: nop

L_80001878:
    // 0x80001878: lw          $t1, 0x410($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X410);
    // 0x8000187C: nop

    // 0x80001880: addiu       $t5, $t1, 0x7FFF
    ctx->r13 = ADD32(ctx->r9, 0X7FFF);
    // 0x80001884: lw          $t5, 0x2ED($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2ED);
    // 0x80001888: nop

    // 0x8000188C: beq         $t5, $zero, L_800018D0
    if (ctx->r13 == 0) {
        // 0x80001890: nop

            goto L_800018D0;
    }
    // 0x80001890: nop

    // 0x80001894: jal         0x80099520
    // 0x80001898: nop

    func_80099520(rdram, ctx);
        goto after_76;
    // 0x80001898: nop

    after_76:
    // 0x8000189C: lw          $t3, 0x410($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X410);
    // 0x800018A0: nop

    // 0x800018A4: addiu       $t2, $t3, 0x7FFF
    ctx->r10 = ADD32(ctx->r11, 0X7FFF);
    // 0x800018A8: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800018AC: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x800018B0: addiu       $t0, $t2, -0x1
    ctx->r8 = ADD32(ctx->r10, -0X1);
    // 0x800018B4: sw          $t0, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r8;
    // 0x800018B8: jal         0x800C40D0
    // 0x800018BC: nop

    osGetTime_recomp(rdram, ctx);
        goto after_77;
    // 0x800018BC: nop

    after_77:
    // 0x800018C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800018C4: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x800018C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800018CC: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
L_800018D0:
    // 0x800018D0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800018D4: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x800018D8: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800018DC: nop

    // 0x800018E0: andi        $t8, $t6, 0x4
    ctx->r24 = ctx->r14 & 0X4;
    // 0x800018E4: beq         $t8, $zero, L_80001954
    if (ctx->r24 == 0) {
        // 0x800018E8: nop

            goto L_80001954;
    }
    // 0x800018E8: nop

    // 0x800018EC: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x800018F0: jal         0x800065BC
    // 0x800018F4: nop

    func_800065BC(rdram, ctx);
        goto after_78;
    // 0x800018F4: nop

    after_78:
    // 0x800018F8: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x800018FC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80001900: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x80001904: lh          $t4, 0x7320($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7320);
    // 0x80001908: nop

    // 0x8000190C: bne         $t4, $t9, L_80001930
    if (ctx->r12 != ctx->r25) {
        // 0x80001910: nop

            goto L_80001930;
    }
    // 0x80001910: nop

    // 0x80001914: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80001918: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000191C: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80001920: lh          $t1, 0x7338($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7338);
    // 0x80001924: nop

    // 0x80001928: beq         $t1, $t5, L_80001954
    if (ctx->r9 == ctx->r13) {
        // 0x8000192C: nop

            goto L_80001954;
    }
    // 0x8000192C: nop

L_80001930:
    // 0x80001930: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80001934: lh          $t2, 0x7320($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7320);
    // 0x80001938: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000193C: ori         $t0, $t2, 0x8000
    ctx->r8 = ctx->r10 | 0X8000;
    // 0x80001940: sh          $t0, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r8;
    // 0x80001944: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80001948: lh          $t3, 0x7338($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7338);
    // 0x8000194C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001950: sh          $t3, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r11;
L_80001954:
    // 0x80001954: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80001958: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000195C: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x80001960: nop

    // 0x80001964: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x80001968: beq         $t8, $zero, L_8000199C
    if (ctx->r24 == 0) {
        // 0x8000196C: nop

            goto L_8000199C;
    }
    // 0x8000196C: nop

    // 0x80001970: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80001974: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80001978: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x8000197C: nop

    // 0x80001980: ori         $t1, $t9, 0x4
    ctx->r9 = ctx->r25 | 0X4;
    // 0x80001984: sh          $t1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r9;
    // 0x80001988: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x8000198C: jal         0x80005880
    // 0x80001990: nop

    func_80005880(rdram, ctx);
        goto after_79;
    // 0x80001990: nop

    after_79:
    // 0x80001994: b           L_80001F2C
    // 0x80001998: nop

        goto L_80001F2C;
    // 0x80001998: nop

L_8000199C:
    // 0x8000199C: b           L_80001F2C
    // 0x800019A0: nop

        goto L_80001F2C;
    // 0x800019A0: nop

L_800019A4:
    // 0x800019A4: jal         0x80032604
    // 0x800019A8: nop

    func_80032604(rdram, ctx);
        goto after_80;
    // 0x800019A8: nop

    after_80:
    // 0x800019AC: lw          $t5, 0x410($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X410);
    // 0x800019B0: nop

    // 0x800019B4: addiu       $t2, $t5, 0x7FFF
    ctx->r10 = ADD32(ctx->r13, 0X7FFF);
    // 0x800019B8: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800019BC: nop

    // 0x800019C0: bgtz        $t2, L_80001A4C
    if (SIGNED(ctx->r10) > 0) {
        // 0x800019C4: nop

            goto L_80001A4C;
    }
    // 0x800019C4: nop

    // 0x800019C8: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800019CC: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x800019D0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800019D4: lhu         $t7, 0x11A4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X11A4);
    // 0x800019D8: lhu         $t3, 0x6($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X6);
    // 0x800019DC: nop

    // 0x800019E0: and         $t6, $t3, $t7
    ctx->r14 = ctx->r11 & ctx->r15;
    // 0x800019E4: beq         $t6, $zero, L_80001A4C
    if (ctx->r14 == 0) {
        // 0x800019E8: nop

            goto L_80001A4C;
    }
    // 0x800019E8: nop

    // 0x800019EC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800019F0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800019F4: jal         0x80021FF8
    // 0x800019F8: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_80021FF8(rdram, ctx);
        goto after_81;
    // 0x800019F8: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_81:
    // 0x800019FC: jal         0x80098BF4
    // 0x80001A00: nop

    func_80098BF4(rdram, ctx);
        goto after_82;
    // 0x80001A00: nop

    after_82:
    // 0x80001A04: lw          $t8, 0x410($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X410);
    // 0x80001A08: nop

    // 0x80001A0C: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x80001A10: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80001A14: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80001A18: nop

    // 0x80001A1C: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80001A20: jal         0x800C13B8
    // 0x80001A24: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_83;
    // 0x80001A24: nop

    after_83:
    // 0x80001A28: jal         0x80098820
    // 0x80001A2C: nop

    func_80098820(rdram, ctx);
        goto after_84;
    // 0x80001A2C: nop

    after_84:
    // 0x80001A30: lw          $t1, 0x414($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X414);
    // 0x80001A34: nop

    // 0x80001A38: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80001A3C: jal         0x80098D24
    // 0x80001A40: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_85;
    // 0x80001A40: nop

    after_85:
    // 0x80001A44: b           L_80001F2C
    // 0x80001A48: nop

        goto L_80001F2C;
    // 0x80001A48: nop

L_80001A4C:
    // 0x80001A4C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80001A50: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80001A54: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80001A58: nop

    // 0x80001A5C: andi        $t2, $t5, 0x20
    ctx->r10 = ctx->r13 & 0X20;
    // 0x80001A60: beq         $t2, $zero, L_80001B0C
    if (ctx->r10 == 0) {
        // 0x80001A64: nop

            goto L_80001B0C;
    }
    // 0x80001A64: nop

    // 0x80001A68: jal         0x80096474
    // 0x80001A6C: nop

    func_80096474(rdram, ctx);
        goto after_86;
    // 0x80001A6C: nop

    after_86:
    // 0x80001A70: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80001A74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001A78: sw          $t0, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r8;
    // 0x80001A7C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80001A80: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001A84: sw          $t3, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r11;
    // 0x80001A88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001A8C: sh          $zero, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = 0;
    // 0x80001A90: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80001A94: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80001A98: sw          $t7, 0x6C08($at)
    MEM_W(0X6C08, ctx->r1) = ctx->r15;
    // 0x80001A9C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80001AA0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80001AA4: sw          $t6, 0x6BC0($at)
    MEM_W(0X6BC0, ctx->r1) = ctx->r14;
    // 0x80001AA8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80001AAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80001AB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001AB4: swc1        $f18, -0x4CBC($at)
    MEM_W(-0X4CBC, ctx->r1) = ctx->f18.u32l;
    // 0x80001AB8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80001ABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001AC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001AC4: swc1        $f4, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f4.u32l;
    // 0x80001AC8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80001ACC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80001AD0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001AD4: swc1        $f6, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = ctx->f6.u32l;
    // 0x80001AD8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80001ADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80001AE0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80001AE4: swc1        $f8, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->f8.u32l;
    // 0x80001AE8: jal         0x80090728
    // 0x80001AEC: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_80090728(rdram, ctx);
        goto after_87;
    // 0x80001AEC: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_87:
    // 0x80001AF0: jal         0x800C4160
    // 0x80001AF4: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_88;
    // 0x80001AF4: nop

    after_88:
    // 0x80001AF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80001AFC: jal         0x8008ECCC
    // 0x80001B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_89;
    // 0x80001B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
    // 0x80001B04: jal         0x800967D8
    // 0x80001B08: nop

    func_800967D8(rdram, ctx);
        goto after_90;
    // 0x80001B08: nop

    after_90:
L_80001B0C:
    // 0x80001B0C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80001B10: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80001B14: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80001B18: nop

    // 0x80001B1C: andi        $t1, $t9, 0x4000
    ctx->r9 = ctx->r25 & 0X4000;
    // 0x80001B20: beq         $t1, $zero, L_80001D90
    if (ctx->r9 == 0) {
        // 0x80001B24: nop

            goto L_80001D90;
    }
    // 0x80001B24: nop

    // 0x80001B28: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80001B2C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80001B30: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80001B34: lhu         $t2, 0x1038($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1038);
    // 0x80001B38: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80001B3C: nop

    // 0x80001B40: and         $t0, $t5, $t2
    ctx->r8 = ctx->r13 & ctx->r10;
    // 0x80001B44: beq         $t0, $zero, L_80001B84
    if (ctx->r8 == 0) {
        // 0x80001B48: nop

            goto L_80001B84;
    }
    // 0x80001B48: nop

    // 0x80001B4C: jal         0x80098868
    // 0x80001B50: nop

    func_80098868(rdram, ctx);
        goto after_91;
    // 0x80001B50: nop

    after_91:
    // 0x80001B54: jal         0x80098C1C
    // 0x80001B58: nop

    func_80098C1C(rdram, ctx);
        goto after_92;
    // 0x80001B58: nop

    after_92:
    // 0x80001B5C: jal         0x80098820
    // 0x80001B60: nop

    func_80098820(rdram, ctx);
        goto after_93;
    // 0x80001B60: nop

    after_93:
    // 0x80001B64: lw          $t3, 0x414($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X414);
    // 0x80001B68: nop

    // 0x80001B6C: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x80001B70: jal         0x80098D24
    // 0x80001B74: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_94;
    // 0x80001B74: nop

    after_94:
    // 0x80001B78: sw          $zero, 0x424($sp)
    MEM_W(0X424, ctx->r29) = 0;
    // 0x80001B7C: b           L_80001F2C
    // 0x80001B80: nop

        goto L_80001F2C;
    // 0x80001B80: nop

L_80001B84:
    // 0x80001B84: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80001B88: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80001B8C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80001B90: lhu         $t8, 0x1038($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1038);
    // 0x80001B94: lhu         $t6, 0x2C($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X2C);
    // 0x80001B98: nop

    // 0x80001B9C: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x80001BA0: beq         $t9, $zero, L_80001BF4
    if (ctx->r25 == 0) {
        // 0x80001BA4: nop

            goto L_80001BF4;
    }
    // 0x80001BA4: nop

    // 0x80001BA8: lw          $t1, 0x424($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X424);
    // 0x80001BAC: nop

    // 0x80001BB0: xori        $t4, $t1, 0x1
    ctx->r12 = ctx->r9 ^ 0X1;
    // 0x80001BB4: sw          $t4, 0x424($sp)
    MEM_W(0X424, ctx->r29) = ctx->r12;
    // 0x80001BB8: lw          $t5, 0x424($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X424);
    // 0x80001BBC: nop

    // 0x80001BC0: beq         $t5, $zero, L_80001BEC
    if (ctx->r13 == 0) {
        // 0x80001BC4: nop

            goto L_80001BEC;
    }
    // 0x80001BC4: nop

    // 0x80001BC8: jal         0x80098868
    // 0x80001BCC: nop

    func_80098868(rdram, ctx);
        goto after_95;
    // 0x80001BCC: nop

    after_95:
    // 0x80001BD0: jal         0x80098C1C
    // 0x80001BD4: nop

    func_80098C1C(rdram, ctx);
        goto after_96;
    // 0x80001BD4: nop

    after_96:
    // 0x80001BD8: lw          $t2, 0x414($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X414);
    // 0x80001BDC: nop

    // 0x80001BE0: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80001BE4: jal         0x80098D24
    // 0x80001BE8: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_97;
    // 0x80001BE8: nop

    after_97:
L_80001BEC:
    // 0x80001BEC: b           L_80001F2C
    // 0x80001BF0: nop

        goto L_80001F2C;
    // 0x80001BF0: nop

L_80001BF4:
    // 0x80001BF4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80001BF8: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80001BFC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80001C00: lhu         $t7, 0x1042($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1042);
    // 0x80001C04: lhu         $t3, 0x6($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X6);
    // 0x80001C08: nop

    // 0x80001C0C: and         $t6, $t3, $t7
    ctx->r14 = ctx->r11 & ctx->r15;
    // 0x80001C10: beq         $t6, $zero, L_80001D90
    if (ctx->r14 == 0) {
        // 0x80001C14: nop

            goto L_80001D90;
    }
    // 0x80001C14: nop

    // 0x80001C18: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80001C1C: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80001C20: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80001C24: nop

    // 0x80001C28: ori         $t1, $t9, 0x8004
    ctx->r9 = ctx->r25 | 0X8004;
    // 0x80001C2C: sh          $t1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r9;
    // 0x80001C30: jal         0x80098CD8
    // 0x80001C34: nop

    func_80098CD8(rdram, ctx);
        goto after_98;
    // 0x80001C34: nop

    after_98:
    // 0x80001C38: jal         0x80098BF4
    // 0x80001C3C: nop

    func_80098BF4(rdram, ctx);
        goto after_99;
    // 0x80001C3C: nop

    after_99:
    // 0x80001C40: jal         0x80098820
    // 0x80001C44: nop

    func_80098820(rdram, ctx);
        goto after_100;
    // 0x80001C44: nop

    after_100:
    // 0x80001C48: jal         0x80098868
    // 0x80001C4C: nop

    func_80098868(rdram, ctx);
        goto after_101;
    // 0x80001C4C: nop

    after_101:
    // 0x80001C50: lw          $t4, 0x410($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X410);
    // 0x80001C54: nop

    // 0x80001C58: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80001C5C: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80001C60: lw          $t5, 0x414($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X414);
    // 0x80001C64: nop

    // 0x80001C68: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80001C6C: jal         0x800C13B8
    // 0x80001C70: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_102;
    // 0x80001C70: nop

    after_102:
    // 0x80001C74: lw          $a0, 0x414($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X414);
    // 0x80001C78: jal         0x800065BC
    // 0x80001C7C: nop

    func_800065BC(rdram, ctx);
        goto after_103;
    // 0x80001C7C: nop

    after_103:
    // 0x80001C80: jal         0x80098CFC
    // 0x80001C84: nop

    func_80098CFC(rdram, ctx);
        goto after_104;
    // 0x80001C84: nop

    after_104:
    // 0x80001C88: jal         0x80098BB8
    // 0x80001C8C: nop

    func_80098BB8(rdram, ctx);
        goto after_105;
    // 0x80001C8C: nop

    after_105:
    // 0x80001C90: jal         0x80098C1C
    // 0x80001C94: nop

    func_80098C1C(rdram, ctx);
        goto after_106;
    // 0x80001C94: nop

    after_106:
    // 0x80001C98: jal         0x80098868
    // 0x80001C9C: nop

    func_80098868(rdram, ctx);
        goto after_107;
    // 0x80001C9C: nop

    after_107:
    // 0x80001CA0: jal         0x80098820
    // 0x80001CA4: nop

    func_80098820(rdram, ctx);
        goto after_108;
    // 0x80001CA4: nop

    after_108:
    // 0x80001CA8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80001CAC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80001CB0: lh          $t0, 0x7234($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7234);
    // 0x80001CB4: lh          $t2, 0x7320($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7320);
    // 0x80001CB8: nop

    // 0x80001CBC: bne         $t2, $t0, L_80001CE0
    if (ctx->r10 != ctx->r8) {
        // 0x80001CC0: nop

            goto L_80001CE0;
    }
    // 0x80001CC0: nop

    // 0x80001CC4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80001CC8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80001CCC: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x80001CD0: lh          $t3, 0x7338($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7338);
    // 0x80001CD4: nop

    // 0x80001CD8: beq         $t3, $t7, L_80001D1C
    if (ctx->r11 == ctx->r15) {
        // 0x80001CDC: nop

            goto L_80001D1C;
    }
    // 0x80001CDC: nop

L_80001CE0:
    // 0x80001CE0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80001CE4: lh          $t6, 0x7320($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7320);
    // 0x80001CE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001CEC: ori         $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 | 0X8000;
    // 0x80001CF0: sh          $t9, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r25;
    // 0x80001CF4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80001CF8: lh          $t1, 0x7338($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7338);
    // 0x80001CFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001D00: sh          $t1, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r9;
    // 0x80001D04: jal         0x80098BF4
    // 0x80001D08: nop

    func_80098BF4(rdram, ctx);
        goto after_109;
    // 0x80001D08: nop

    after_109:
    // 0x80001D0C: jal         0x80098820
    // 0x80001D10: nop

    func_80098820(rdram, ctx);
        goto after_110;
    // 0x80001D10: nop

    after_110:
    // 0x80001D14: b           L_80001D74
    // 0x80001D18: nop

        goto L_80001D74;
    // 0x80001D18: nop

L_80001D1C:
    // 0x80001D1C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80001D20: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80001D24: lhu         $t4, 0x0($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X0);
    // 0x80001D28: nop

    // 0x80001D2C: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80001D30: beq         $t5, $zero, L_80001D74
    if (ctx->r13 == 0) {
        // 0x80001D34: nop

            goto L_80001D74;
    }
    // 0x80001D34: nop

    // 0x80001D38: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80001D3C: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80001D40: lhu         $t0, 0x0($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0X0);
    // 0x80001D44: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80001D48: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x80001D4C: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x80001D50: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80001D54: lh          $t7, 0x7254($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7254);
    // 0x80001D58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001D5C: ori         $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 | 0X8000;
    // 0x80001D60: sh          $t6, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r14;
    // 0x80001D64: jal         0x80098BF4
    // 0x80001D68: nop

    func_80098BF4(rdram, ctx);
        goto after_111;
    // 0x80001D68: nop

    after_111:
    // 0x80001D6C: jal         0x80098820
    // 0x80001D70: nop

    func_80098820(rdram, ctx);
        goto after_112;
    // 0x80001D70: nop

    after_112:
L_80001D74:
    // 0x80001D74: lw          $t9, 0x414($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X414);
    // 0x80001D78: nop

    // 0x80001D7C: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80001D80: jal         0x80098D24
    // 0x80001D84: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_113;
    // 0x80001D84: nop

    after_113:
    // 0x80001D88: b           L_80001F2C
    // 0x80001D8C: nop

        goto L_80001F2C;
    // 0x80001D8C: nop

L_80001D90:
    // 0x80001D90: lw          $t1, 0x414($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X414);
    // 0x80001D94: nop

    // 0x80001D98: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80001D9C: jal         0x80098D24
    // 0x80001DA0: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_114;
    // 0x80001DA0: nop

    after_114:
    // 0x80001DA4: b           L_80001F2C
    // 0x80001DA8: nop

        goto L_80001F2C;
    // 0x80001DA8: nop

L_80001DAC:
    // 0x80001DAC: lw          $t8, 0x414($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X414);
    // 0x80001DB0: addiu       $a1, $sp, 0x40C
    ctx->r5 = ADD32(ctx->r29, 0X40C);
    // 0x80001DB4: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80001DB8: jal         0x800C143C
    // 0x80001DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_115;
    // 0x80001DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_115:
    // 0x80001DC0: lw          $t4, 0x40C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40C);
    // 0x80001DC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001DC8: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80001DCC: nop

    // 0x80001DD0: bne         $t5, $at, L_80001E0C
    if (ctx->r13 != ctx->r1) {
        // 0x80001DD4: nop

            goto L_80001E0C;
    }
    // 0x80001DD4: nop

    // 0x80001DD8: b           L_80001DE0
    // 0x80001DDC: nop

        goto L_80001DE0;
    // 0x80001DDC: nop

L_80001DE0:
    // 0x80001DE0: jal         0x80099520
    // 0x80001DE4: nop

    func_80099520(rdram, ctx);
        goto after_116;
    // 0x80001DE4: nop

    after_116:
    // 0x80001DE8: lw          $t0, 0x410($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X410);
    // 0x80001DEC: nop

    // 0x80001DF0: addiu       $t3, $t0, 0x7FFF
    ctx->r11 = ADD32(ctx->r8, 0X7FFF);
    // 0x80001DF4: lw          $t3, 0x2ED($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2ED);
    // 0x80001DF8: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x80001DFC: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x80001E00: sw          $t2, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r10;
    // 0x80001E04: b           L_80001E0C
    // 0x80001E08: nop

        goto L_80001E0C;
    // 0x80001E08: nop

L_80001E0C:
    // 0x80001E0C: lw          $t7, 0x410($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X410);
    // 0x80001E10: nop

    // 0x80001E14: addiu       $t6, $t7, 0x7FFF
    ctx->r14 = ADD32(ctx->r15, 0X7FFF);
    // 0x80001E18: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x80001E1C: nop

    // 0x80001E20: bne         $t6, $zero, L_80001E30
    if (ctx->r14 != 0) {
        // 0x80001E24: nop

            goto L_80001E30;
    }
    // 0x80001E24: nop

    // 0x80001E28: b           L_80001E38
    // 0x80001E2C: nop

        goto L_80001E38;
    // 0x80001E2C: nop

L_80001E30:
    // 0x80001E30: b           L_80001DAC
    // 0x80001E34: nop

        goto L_80001DAC;
    // 0x80001E34: nop

L_80001E38:
    // 0x80001E38: jal         0x80005460
    // 0x80001E3C: nop

    func_80005460(rdram, ctx);
        goto after_117;
    // 0x80001E3C: nop

    after_117:
    // 0x80001E40: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80001E44: lw          $a1, -0x73E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73E8);
    // 0x80001E48: addiu       $a0, $sp, 0x288
    ctx->r4 = ADD32(ctx->r29, 0X288);
    // 0x80001E4C: jal         0x800BCFCC
    // 0x80001E50: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    SysMem_Copy8(rdram, ctx);
        goto after_118;
    // 0x80001E50: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    after_118:
    // 0x80001E54: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80001E58: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80001E5C: lh          $a1, -0x73E4($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73E4);
    // 0x80001E60: lh          $a0, -0x73F0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X73F0);
    // 0x80001E64: jal         0x80005124
    // 0x80001E68: nop

    func_80005124(rdram, ctx);
        goto after_119;
    // 0x80001E68: nop

    after_119:
    // 0x80001E6C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80001E70: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x80001E74: lwc1        $f10, 0x354($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X354);
    // 0x80001E78: nop

    // 0x80001E7C: swc1        $f10, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f10.u32l;
    // 0x80001E80: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80001E84: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x80001E88: lwc1        $f16, 0x358($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X358);
    // 0x80001E8C: nop

    // 0x80001E90: swc1        $f16, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f16.u32l;
    // 0x80001E94: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80001E98: lh          $t8, -0x73F0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X73F0);
    // 0x80001E9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001EA0: sh          $t8, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r24;
    // 0x80001EA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001EA8: sh          $t8, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r24;
    // 0x80001EAC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80001EB0: lh          $t4, -0x73E4($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X73E4);
    // 0x80001EB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001EB8: sh          $t4, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r12;
    // 0x80001EBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80001EC0: sh          $t4, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r12;
    // 0x80001EC4: lw          $t5, 0x410($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X410);
    // 0x80001EC8: nop

    // 0x80001ECC: addiu       $at, $t5, 0x7FFF
    ctx->r1 = ADD32(ctx->r13, 0X7FFF);
    // 0x80001ED0: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80001ED4: lw          $t3, 0x414($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X414);
    // 0x80001ED8: nop

    // 0x80001EDC: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x80001EE0: jal         0x800C13B8
    // 0x80001EE4: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_120;
    // 0x80001EE4: nop

    after_120:
    // 0x80001EE8: jal         0x80098820
    // 0x80001EEC: nop

    func_80098820(rdram, ctx);
        goto after_121;
    // 0x80001EEC: nop

    after_121:
    // 0x80001EF0: lw          $t2, 0x414($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X414);
    // 0x80001EF4: nop

    // 0x80001EF8: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x80001EFC: b           L_80001F2C
    // 0x80001F00: nop

        goto L_80001F2C;
    // 0x80001F00: nop

L_80001F04:
    // 0x80001F04: jal         0x800029BC
    // 0x80001F08: nop

    func_800029BC(rdram, ctx);
        goto after_122;
    // 0x80001F08: nop

    after_122:
L_80001F0C:
    // 0x80001F0C: b           L_80001F0C
    pause_self(rdram);
    // 0x80001F10: nop

    // 0x80001F14: b           L_80001F2C
    // 0x80001F18: nop

        goto L_80001F2C;
    // 0x80001F18: nop

L_80001F1C:
    // 0x80001F1C: b           L_80001F2C
    // 0x80001F20: nop

        goto L_80001F2C;
    // 0x80001F20: nop

L_80001F24:
    // 0x80001F24: b           L_80001F2C
    // 0x80001F28: nop

        goto L_80001F2C;
    // 0x80001F28: nop

L_80001F2C:
    // 0x80001F2C: lw          $t0, 0x428($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X428);
    // 0x80001F30: nop

    // 0x80001F34: beq         $t0, $zero, L_80000D30
    if (ctx->r8 == 0) {
        // 0x80001F38: nop

            goto L_80000D30;
    }
    // 0x80001F38: nop

L_80001F3C:
    // 0x80001F3C: b           L_80001F44
    // 0x80001F40: nop

        goto L_80001F44;
    // 0x80001F40: nop

L_80001F44:
    // 0x80001F44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80001F48: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80001F4C: jr          $ra
    // 0x80001F50: addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
    return;
    // 0x80001F50: addiu       $sp, $sp, 0x430
    ctx->r29 = ADD32(ctx->r29, 0X430);
;}
RECOMP_FUNC void func_80001F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001F54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001F5C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80001F60: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80001F64: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80001F68: nop

    // 0x80001F6C: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80001F70: bne         $t8, $zero, L_80001FC8
    if (ctx->r24 != 0) {
        // 0x80001F74: nop

            goto L_80001FC8;
    }
    // 0x80001F74: nop

    // 0x80001F78: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x80001F7C: nop

    // 0x80001F80: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80001F84: beq         $t0, $zero, L_80001FC8
    if (ctx->r8 == 0) {
        // 0x80001F88: nop

            goto L_80001FC8;
    }
    // 0x80001F88: nop

    // 0x80001F8C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80001F90: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80001F94: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x80001F98: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80001F9C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80001FA0: sh          $t3, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r11;
    // 0x80001FA4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80001FA8: lw          $t4, -0x33BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X33BC);
    // 0x80001FAC: nop

    // 0x80001FB0: bltz        $t4, L_80001FC8
    if (SIGNED(ctx->r12) < 0) {
        // 0x80001FB4: nop

            goto L_80001FC8;
    }
    // 0x80001FB4: nop

    // 0x80001FB8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80001FBC: lw          $a0, -0x33BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33BC);
    // 0x80001FC0: jal         0x80021ED0
    // 0x80001FC4: nop

    AudioGeneral_PlayBGM(rdram, ctx);
        goto after_0;
    // 0x80001FC4: nop

    after_0:
L_80001FC8:
    // 0x80001FC8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80001FCC: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80001FD0: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x80001FD4: nop

    // 0x80001FD8: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x80001FDC: bne         $t8, $zero, L_80001FEC
    if (ctx->r24 != 0) {
        // 0x80001FE0: nop

            goto L_80001FEC;
    }
    // 0x80001FE0: nop

    // 0x80001FE4: b           L_80002098
    // 0x80001FE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80002098;
    // 0x80001FE8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80001FEC:
    // 0x80001FEC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80001FF0: lw          $t6, -0x73CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73CC);
    // 0x80001FF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80001FF8: bne         $t6, $at, L_80002020
    if (ctx->r14 != ctx->r1) {
        // 0x80001FFC: nop

            goto L_80002020;
    }
    // 0x80001FFC: nop

    // 0x80002000: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80002004: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80002008: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8000200C: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x80002010: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x80002014: sh          $t2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r10;
    // 0x80002018: b           L_80002098
    // 0x8000201C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80002098;
    // 0x8000201C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80002020:
    // 0x80002020: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80002024: lw          $a0, -0x73CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73CC);
    // 0x80002028: jal         0x80016074
    // 0x8000202C: nop

    func_80016074(rdram, ctx);
        goto after_1;
    // 0x8000202C: nop

    after_1:
    // 0x80002030: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80002034: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80002038: nop

    // 0x8000203C: bne         $t3, $zero, L_8000204C
    if (ctx->r11 != 0) {
        // 0x80002040: nop

            goto L_8000204C;
    }
    // 0x80002040: nop

    // 0x80002044: b           L_80002098
    // 0x80002048: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80002098;
    // 0x80002048: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000204C:
    // 0x8000204C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80002050: nop

    // 0x80002054: lw          $t4, 0x1A8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X1A8);
    // 0x80002058: nop

    // 0x8000205C: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x80002060: beq         $t5, $zero, L_80002070
    if (ctx->r13 == 0) {
        // 0x80002064: nop

            goto L_80002070;
    }
    // 0x80002064: nop

    // 0x80002068: b           L_80002098
    // 0x8000206C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80002098;
    // 0x8000206C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80002070:
    // 0x80002070: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80002074: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80002078: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000207C: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x80002080: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x80002084: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80002088: b           L_80002098
    // 0x8000208C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80002098;
    // 0x8000208C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002090: b           L_80002098
    // 0x80002094: nop

        goto L_80002098;
    // 0x80002094: nop

L_80002098:
    // 0x80002098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000209C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800020A0: jr          $ra
    // 0x800020A4: nop

    return;
    // 0x800020A4: nop

;}
RECOMP_FUNC void func_800020A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800020AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800020B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800020B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800020B8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800020BC: lw          $t6, -0x73CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73CC);
    // 0x800020C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800020C4: beq         $t6, $at, L_800020F8
    if (ctx->r14 == ctx->r1) {
        // 0x800020C8: nop

            goto L_800020F8;
    }
    // 0x800020C8: nop

    // 0x800020CC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800020D0: lw          $a0, -0x73CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73CC);
    // 0x800020D4: jal         0x80016074
    // 0x800020D8: nop

    func_80016074(rdram, ctx);
        goto after_0;
    // 0x800020D8: nop

    after_0:
    // 0x800020DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800020E0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800020E4: nop

    // 0x800020E8: bne         $t7, $zero, L_800020F8
    if (ctx->r15 != 0) {
        // 0x800020EC: nop

            goto L_800020F8;
    }
    // 0x800020EC: nop

    // 0x800020F0: b           L_8000261C
    // 0x800020F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000261C;
    // 0x800020F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800020F8:
    // 0x800020F8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800020FC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80002100: lh          $t9, 0x7254($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7254);
    // 0x80002104: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x80002108: nop

    // 0x8000210C: bne         $t8, $t9, L_8000214C
    if (ctx->r24 != ctx->r25) {
        // 0x80002110: nop

            goto L_8000214C;
    }
    // 0x80002110: nop

    // 0x80002114: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80002118: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8000211C: lh          $t1, 0x725C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X725C);
    // 0x80002120: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x80002124: nop

    // 0x80002128: bne         $t0, $t1, L_8000214C
    if (ctx->r8 != ctx->r9) {
        // 0x8000212C: nop

            goto L_8000214C;
    }
    // 0x8000212C: nop

    // 0x80002130: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80002134: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80002138: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000213C: nop

    // 0x80002140: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80002144: beq         $t4, $zero, L_8000260C
    if (ctx->r12 == 0) {
        // 0x80002148: nop

            goto L_8000260C;
    }
    // 0x80002148: nop

L_8000214C:
    // 0x8000214C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80002150: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80002154: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80002158: nop

    // 0x8000215C: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x80002160: bne         $t7, $zero, L_80002178
    if (ctx->r15 != 0) {
        // 0x80002164: nop

            goto L_80002178;
    }
    // 0x80002164: nop

    // 0x80002168: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8000216C: nop

    // 0x80002170: bne         $t8, $zero, L_800021A8
    if (ctx->r24 != 0) {
        // 0x80002174: nop

            goto L_800021A8;
    }
    // 0x80002174: nop

L_80002178:
    // 0x80002178: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8000217C: lh          $t9, 0x7254($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7254);
    // 0x80002180: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002184: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x80002188: sh          $t0, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r8;
    // 0x8000218C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80002190: lh          $t1, 0x725C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X725C);
    // 0x80002194: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002198: andi        $t2, $t1, 0x7FFF
    ctx->r10 = ctx->r9 & 0X7FFF;
    // 0x8000219C: sh          $t2, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r10;
    // 0x800021A0: b           L_8000261C
    // 0x800021A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000261C;
    // 0x800021A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800021A8:
    // 0x800021A8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800021AC: nop

    // 0x800021B0: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x800021B4: nop

    // 0x800021B8: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x800021BC: beq         $t5, $zero, L_8000225C
    if (ctx->r13 == 0) {
        // 0x800021C0: nop

            goto L_8000225C;
    }
    // 0x800021C0: nop

    // 0x800021C4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800021C8: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800021CC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800021D0: nop

    // 0x800021D4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800021D8: bne         $t8, $zero, L_8000220C
    if (ctx->r24 != 0) {
        // 0x800021DC: nop

            goto L_8000220C;
    }
    // 0x800021DC: nop

    // 0x800021E0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800021E4: lh          $t9, 0x7254($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7254);
    // 0x800021E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800021EC: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x800021F0: sh          $t0, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r8;
    // 0x800021F4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800021F8: lh          $t1, 0x725C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X725C);
    // 0x800021FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002200: andi        $t2, $t1, 0x7FFF
    ctx->r10 = ctx->r9 & 0X7FFF;
    // 0x80002204: b           L_8000224C
    // 0x80002208: sh          $t2, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r10;
        goto L_8000224C;
    // 0x80002208: sh          $t2, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r10;
L_8000220C:
    // 0x8000220C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80002210: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80002214: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002218: andi        $t4, $t3, 0x7FFF
    ctx->r12 = ctx->r11 & 0X7FFF;
    // 0x8000221C: sh          $t4, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r12;
    // 0x80002220: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80002224: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80002228: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000222C: andi        $t6, $t5, 0x7FFF
    ctx->r14 = ctx->r13 & 0X7FFF;
    // 0x80002230: sh          $t6, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r14;
    // 0x80002234: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80002238: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000223C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80002240: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80002244: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80002248: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
L_8000224C:
    // 0x8000224C: b           L_8000261C
    // 0x80002250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000261C;
    // 0x80002250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002254: b           L_8000260C
    // 0x80002258: nop

        goto L_8000260C;
    // 0x80002258: nop

L_8000225C:
    // 0x8000225C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80002260: nop

    // 0x80002264: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x80002268: nop

    // 0x8000226C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80002270: bne         $t2, $zero, L_8000260C
    if (ctx->r10 != 0) {
        // 0x80002274: nop

            goto L_8000260C;
    }
    // 0x80002274: nop

    // 0x80002278: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8000227C: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x80002280: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002284: sh          $t3, 0x7274($at)
    MEM_H(0X7274, ctx->r1) = ctx->r11;
    // 0x80002288: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8000228C: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x80002290: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002294: sh          $t4, 0x7280($at)
    MEM_H(0X7280, ctx->r1) = ctx->r12;
    // 0x80002298: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000229C: lh          $t5, 0x7248($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7248);
    // 0x800022A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800022A4: sh          $t5, 0x728C($at)
    MEM_H(0X728C, ctx->r1) = ctx->r13;
    // 0x800022A8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800022AC: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800022B0: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x800022B4: nop

    // 0x800022B8: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800022BC: beq         $t9, $zero, L_800022E4
    if (ctx->r25 == 0) {
        // 0x800022C0: nop

            goto L_800022E4;
    }
    // 0x800022C0: nop

    // 0x800022C4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800022C8: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x800022CC: lhu         $t0, 0x6($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X6);
    // 0x800022D0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800022D4: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800022D8: sh          $t1, 0x6($t7)
    MEM_H(0X6, ctx->r15) = ctx->r9;
    // 0x800022DC: jal         0x80021F20
    // 0x800022E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_1;
    // 0x800022E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
L_800022E4:
    // 0x800022E4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800022E8: lh          $t2, 0x7234($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7234);
    // 0x800022EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800022F0: andi        $t3, $t2, 0x7FFF
    ctx->r11 = ctx->r10 & 0X7FFF;
    // 0x800022F4: bne         $t3, $at, L_80002364
    if (ctx->r11 != ctx->r1) {
        // 0x800022F8: nop

            goto L_80002364;
    }
    // 0x800022F8: nop

    // 0x800022FC: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80002300: lh          $t4, 0x723C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X723C);
    // 0x80002304: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80002308: andi        $t5, $t4, 0x7FFF
    ctx->r13 = ctx->r12 & 0X7FFF;
    // 0x8000230C: bne         $t5, $at, L_80002364
    if (ctx->r13 != ctx->r1) {
        // 0x80002310: nop

            goto L_80002364;
    }
    // 0x80002310: nop

    // 0x80002314: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80002318: lh          $t6, 0x7254($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7254);
    // 0x8000231C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002320: andi        $t8, $t6, 0x7FFF
    ctx->r24 = ctx->r14 & 0X7FFF;
    // 0x80002324: bne         $t8, $at, L_80002364
    if (ctx->r24 != ctx->r1) {
        // 0x80002328: nop

            goto L_80002364;
    }
    // 0x80002328: nop

    // 0x8000232C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80002330: lh          $t9, 0x725C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X725C);
    // 0x80002334: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002338: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x8000233C: bne         $t0, $at, L_80002364
    if (ctx->r8 != ctx->r1) {
        // 0x80002340: nop

            goto L_80002364;
    }
    // 0x80002340: nop

    // 0x80002344: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80002348: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000234C: lhu         $t7, 0x6($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X6);
    // 0x80002350: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80002354: and         $t2, $t7, $at
    ctx->r10 = ctx->r15 & ctx->r1;
    // 0x80002358: sh          $t2, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r10;
    // 0x8000235C: jal         0x80021F20
    // 0x80002360: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_2;
    // 0x80002360: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_2:
L_80002364:
    // 0x80002364: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80002368: lh          $t3, 0x7234($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X7234);
    // 0x8000236C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002370: andi        $t4, $t3, 0x7FFF
    ctx->r12 = ctx->r11 & 0X7FFF;
    // 0x80002374: bne         $t4, $at, L_800023E4
    if (ctx->r12 != ctx->r1) {
        // 0x80002378: nop

            goto L_800023E4;
    }
    // 0x80002378: nop

    // 0x8000237C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80002380: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x80002384: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002388: andi        $t6, $t5, 0x7FFF
    ctx->r14 = ctx->r13 & 0X7FFF;
    // 0x8000238C: bne         $t6, $at, L_800023E4
    if (ctx->r14 != ctx->r1) {
        // 0x80002390: nop

            goto L_800023E4;
    }
    // 0x80002390: nop

    // 0x80002394: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80002398: lh          $t8, 0x7254($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7254);
    // 0x8000239C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800023A0: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x800023A4: bne         $t9, $at, L_800023E4
    if (ctx->r25 != ctx->r1) {
        // 0x800023A8: nop

            goto L_800023E4;
    }
    // 0x800023A8: nop

    // 0x800023AC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800023B0: lh          $t0, 0x725C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X725C);
    // 0x800023B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800023B8: andi        $t7, $t0, 0x7FFF
    ctx->r15 = ctx->r8 & 0X7FFF;
    // 0x800023BC: bne         $t7, $at, L_800023E4
    if (ctx->r15 != ctx->r1) {
        // 0x800023C0: nop

            goto L_800023E4;
    }
    // 0x800023C0: nop

    // 0x800023C4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800023C8: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800023CC: lhu         $t1, 0x6($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X6);
    // 0x800023D0: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800023D4: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x800023D8: sh          $t3, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r11;
    // 0x800023DC: jal         0x80021F20
    // 0x800023E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_3;
    // 0x800023E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_3:
L_800023E4:
    // 0x800023E4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800023E8: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x800023EC: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800023F0: nop

    // 0x800023F4: andi        $t6, $t5, 0x800
    ctx->r14 = ctx->r13 & 0X800;
    // 0x800023F8: beq         $t6, $zero, L_80002424
    if (ctx->r14 == 0) {
        // 0x800023FC: nop

            goto L_80002424;
    }
    // 0x800023FC: nop

    // 0x80002400: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80002404: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80002408: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x8000240C: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x80002410: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80002414: sh          $t0, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r8;
    // 0x80002418: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8000241C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80002420: sw          $t7, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r15;
L_80002424:
    // 0x80002424: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80002428: lw          $t1, -0x73CC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73CC);
    // 0x8000242C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80002430: bne         $t1, $at, L_80002510
    if (ctx->r9 != ctx->r1) {
        // 0x80002434: nop

            goto L_80002510;
    }
    // 0x80002434: nop

    // 0x80002438: b           L_80002440
    // 0x8000243C: nop

        goto L_80002440;
    // 0x8000243C: nop

L_80002440:
    // 0x80002440: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80002444: lwc1        $f4, -0x4508($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x80002448: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000244C: nop

    // 0x80002450: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80002454: nop

    // 0x80002458: bc1f        L_80002474
    if (!c1cs) {
        // 0x8000245C: nop

            goto L_80002474;
    }
    // 0x8000245C: nop

    // 0x80002460: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80002464: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80002468: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000246C: b           L_800024DC
    // 0x80002470: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
        goto L_800024DC;
    // 0x80002470: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
L_80002474:
    // 0x80002474: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80002478: lwc1        $f10, -0x4508($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x8000247C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80002480: nop

    // 0x80002484: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80002488: nop

    // 0x8000248C: bc1f        L_800024DC
    if (!c1cs) {
        // 0x80002490: nop

            goto L_800024DC;
    }
    // 0x80002490: nop

    // 0x80002494: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80002498: lwc1        $f18, -0x4508($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x8000249C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800024A0: nop

    // 0x800024A4: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800024A8: nop

    // 0x800024AC: bc1f        L_800024C4
    if (!c1cs) {
        // 0x800024B0: nop

            goto L_800024C4;
    }
    // 0x800024B0: nop

    // 0x800024B4: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = -ctx->f18.fl;
    // 0x800024B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800024BC: b           L_800024DC
    // 0x800024C0: swc1        $f6, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f6.u32l;
        goto L_800024DC;
    // 0x800024C0: swc1        $f6, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f6.u32l;
L_800024C4:
    // 0x800024C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800024C8: lwc1        $f8, -0x4508($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x800024CC: nop

    // 0x800024D0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800024D4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800024D8: swc1        $f16, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f16.u32l;
L_800024DC:
    // 0x800024DC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800024E0: jal         0x80016620
    // 0x800024E4: addiu       $a0, $a0, -0x4508
    ctx->r4 = ADD32(ctx->r4, -0X4508);
    func_80016620(rdram, ctx);
        goto after_4;
    // 0x800024E4: addiu       $a0, $a0, -0x4508
    ctx->r4 = ADD32(ctx->r4, -0X4508);
    after_4:
    // 0x800024E8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800024EC: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x800024F0: lhu         $t2, 0x0($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X0);
    // 0x800024F4: nop

    // 0x800024F8: ori         $t4, $t2, 0x400
    ctx->r12 = ctx->r10 | 0X400;
    // 0x800024FC: sh          $t4, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r12;
    // 0x80002500: b           L_8000261C
    // 0x80002504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000261C;
    // 0x80002504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002508: b           L_8000260C
    // 0x8000250C: nop

        goto L_8000260C;
    // 0x8000250C: nop

L_80002510:
    // 0x80002510: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80002514: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80002518: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8000251C: nop

    // 0x80002520: andi        $t9, $t6, 0x80
    ctx->r25 = ctx->r14 & 0X80;
    // 0x80002524: beq         $t9, $zero, L_8000255C
    if (ctx->r25 == 0) {
        // 0x80002528: nop

            goto L_8000255C;
    }
    // 0x80002528: nop

    // 0x8000252C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80002530: lh          $t0, 0x7254($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7254);
    // 0x80002534: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002538: andi        $t8, $t0, 0x7FFF
    ctx->r24 = ctx->r8 & 0X7FFF;
    // 0x8000253C: sh          $t8, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r24;
    // 0x80002540: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80002544: lh          $t7, 0x725C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X725C);
    // 0x80002548: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000254C: andi        $t1, $t7, 0x7FFF
    ctx->r9 = ctx->r15 & 0X7FFF;
    // 0x80002550: sh          $t1, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r9;
    // 0x80002554: b           L_8000261C
    // 0x80002558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000261C;
    // 0x80002558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000255C:
    // 0x8000255C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80002560: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80002564: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x80002568: nop

    // 0x8000256C: andi        $t3, $t4, 0x10
    ctx->r11 = ctx->r12 & 0X10;
    // 0x80002570: bne         $t3, $zero, L_800025A4
    if (ctx->r11 != 0) {
        // 0x80002574: nop

            goto L_800025A4;
    }
    // 0x80002574: nop

    // 0x80002578: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000257C: lh          $t5, 0x7254($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7254);
    // 0x80002580: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002584: andi        $t6, $t5, 0x7FFF
    ctx->r14 = ctx->r13 & 0X7FFF;
    // 0x80002588: sh          $t6, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r14;
    // 0x8000258C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80002590: lh          $t9, 0x725C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X725C);
    // 0x80002594: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80002598: andi        $t0, $t9, 0x7FFF
    ctx->r8 = ctx->r25 & 0X7FFF;
    // 0x8000259C: b           L_800025E4
    // 0x800025A0: sh          $t0, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r8;
        goto L_800025E4;
    // 0x800025A0: sh          $t0, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r8;
L_800025A4:
    // 0x800025A4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800025A8: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800025AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800025B0: andi        $t7, $t8, 0x7FFF
    ctx->r15 = ctx->r24 & 0X7FFF;
    // 0x800025B4: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
    // 0x800025B8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800025BC: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x800025C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800025C4: andi        $t2, $t1, 0x7FFF
    ctx->r10 = ctx->r9 & 0X7FFF;
    // 0x800025C8: sh          $t2, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r10;
    // 0x800025CC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800025D0: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x800025D4: lhu         $t3, 0x0($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X0);
    // 0x800025D8: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800025DC: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x800025E0: sh          $t5, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r13;
L_800025E4:
    // 0x800025E4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800025E8: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800025EC: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x800025F0: nop

    // 0x800025F4: ori         $t0, $t9, 0x400
    ctx->r8 = ctx->r25 | 0X400;
    // 0x800025F8: sh          $t0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r8;
    // 0x800025FC: b           L_8000261C
    // 0x80002600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000261C;
    // 0x80002600: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80002604: b           L_8000260C
    // 0x80002608: nop

        goto L_8000260C;
    // 0x80002608: nop

L_8000260C:
    // 0x8000260C: b           L_8000261C
    // 0x80002610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000261C;
    // 0x80002610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002614: b           L_8000261C
    // 0x80002618: nop

        goto L_8000261C;
    // 0x80002618: nop

L_8000261C:
    // 0x8000261C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002620: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002624: jr          $ra
    // 0x80002628: nop

    return;
    // 0x80002628: nop

;}
RECOMP_FUNC void func_8000262C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000262C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002634: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80002638: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000263C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80002640: nop

    // 0x80002644: beq         $t6, $zero, L_80002658
    if (ctx->r14 == 0) {
        // 0x80002648: nop

            goto L_80002658;
    }
    // 0x80002648: nop

    // 0x8000264C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80002650: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80002654: sw          $t7, -0x73E8($at)
    MEM_W(-0X73E8, ctx->r1) = ctx->r15;
L_80002658:
    // 0x80002658: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000265C: nop

    // 0x80002660: beq         $t8, $zero, L_80002674
    if (ctx->r24 == 0) {
        // 0x80002664: nop

            goto L_80002674;
    }
    // 0x80002664: nop

    // 0x80002668: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8000266C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80002670: sw          $t9, -0x73DC($at)
    MEM_W(-0X73DC, ctx->r1) = ctx->r25;
L_80002674:
    // 0x80002674: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80002678: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x8000267C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80002680: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_80002684:
    // 0x80002684: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80002688: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8000268C: lw          $t2, 0xC0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC0);
    // 0x80002690: nop

    // 0x80002694: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80002698: beq         $t3, $zero, L_80002704
    if (ctx->r11 == 0) {
        // 0x8000269C: nop

            goto L_80002704;
    }
    // 0x8000269C: nop

    // 0x800026A0: jal         0x800C1754
    // 0x800026A4: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_0;
    // 0x800026A4: nop

    after_0:
    // 0x800026A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800026AC: jal         0x800A7230
    // 0x800026B0: nop

    func_800A7230(rdram, ctx);
        goto after_1;
    // 0x800026B0: nop

    after_1:
    // 0x800026B4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800026B8: nop

    // 0x800026BC: lwc1        $f12, 0xF0($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x800026C0: jal         0x800C2780
    // 0x800026C4: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_2;
    // 0x800026C4: nop

    after_2:
    // 0x800026C8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800026CC: nop

    // 0x800026D0: lwc1        $f12, 0xEC($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XEC);
    // 0x800026D4: jal         0x800C25B8
    // 0x800026D8: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_3;
    // 0x800026D8: nop

    after_3:
    // 0x800026DC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800026E0: nop

    // 0x800026E4: lwc1        $f12, 0xE8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x800026E8: jal         0x800C23E8
    // 0x800026EC: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_4;
    // 0x800026EC: nop

    after_4:
    // 0x800026F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800026F4: jal         0x800997D8
    // 0x800026F8: nop

    func_800997D8(rdram, ctx);
        goto after_5;
    // 0x800026F8: nop

    after_5:
    // 0x800026FC: jal         0x800C1A28
    // 0x80002700: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_6;
    // 0x80002700: nop

    after_6:
L_80002704:
    // 0x80002704: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80002708: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8000270C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80002710: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80002714: addiu       $t0, $t9, 0x160
    ctx->r8 = ADD32(ctx->r25, 0X160);
    // 0x80002718: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8000271C: bne         $at, $zero, L_80002684
    if (ctx->r1 != 0) {
        // 0x80002720: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_80002684;
    }
    // 0x80002720: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80002724: jal         0x80016074
    // 0x80002728: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80016074(rdram, ctx);
        goto after_7;
    // 0x80002728: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_7:
    // 0x8000272C: beq         $v0, $zero, L_8000280C
    if (ctx->r2 == 0) {
        // 0x80002730: nop

            goto L_8000280C;
    }
    // 0x80002730: nop

    // 0x80002734: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80002738: lw          $t1, -0x4538($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4538);
    // 0x8000273C: nop

    // 0x80002740: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80002744: nop

    // 0x80002748: lw          $t3, 0x1A8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A8);
    // 0x8000274C: nop

    // 0x80002750: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80002754: beq         $t4, $zero, L_8000280C
    if (ctx->r12 == 0) {
        // 0x80002758: nop

            goto L_8000280C;
    }
    // 0x80002758: nop

    // 0x8000275C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80002760: lw          $t5, -0x73DC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73DC);
    // 0x80002764: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80002768: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
L_8000276C:
    // 0x8000276C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80002770: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80002774: lw          $t7, 0xC0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC0);
    // 0x80002778: nop

    // 0x8000277C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80002780: beq         $t9, $zero, L_800027EC
    if (ctx->r25 == 0) {
        // 0x80002784: nop

            goto L_800027EC;
    }
    // 0x80002784: nop

    // 0x80002788: jal         0x800C1754
    // 0x8000278C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_8;
    // 0x8000278C: nop

    after_8:
    // 0x80002790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80002794: jal         0x800A7230
    // 0x80002798: nop

    func_800A7230(rdram, ctx);
        goto after_9;
    // 0x80002798: nop

    after_9:
    // 0x8000279C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800027A0: nop

    // 0x800027A4: lwc1        $f12, 0xF0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x800027A8: jal         0x800C2780
    // 0x800027AC: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_10;
    // 0x800027AC: nop

    after_10:
    // 0x800027B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800027B4: nop

    // 0x800027B8: lwc1        $f12, 0xEC($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XEC);
    // 0x800027BC: jal         0x800C25B8
    // 0x800027C0: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_11;
    // 0x800027C0: nop

    after_11:
    // 0x800027C4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800027C8: nop

    // 0x800027CC: lwc1        $f12, 0xE8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XE8);
    // 0x800027D0: jal         0x800C23E8
    // 0x800027D4: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_12;
    // 0x800027D4: nop

    after_12:
    // 0x800027D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800027DC: jal         0x800997D8
    // 0x800027E0: nop

    func_800997D8(rdram, ctx);
        goto after_13;
    // 0x800027E0: nop

    after_13:
    // 0x800027E4: jal         0x800C1A28
    // 0x800027E8: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_14;
    // 0x800027E8: nop

    after_14:
L_800027EC:
    // 0x800027EC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800027F0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800027F4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800027F8: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x800027FC: addiu       $t5, $t4, 0x160
    ctx->r13 = ADD32(ctx->r12, 0X160);
    // 0x80002800: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80002804: bne         $at, $zero, L_8000276C
    if (ctx->r1 != 0) {
        // 0x80002808: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_8000276C;
    }
    // 0x80002808: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_8000280C:
    // 0x8000280C: b           L_80002814
    // 0x80002810: nop

        goto L_80002814;
    // 0x80002810: nop

L_80002814:
    // 0x80002814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002818: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000281C: jr          $ra
    // 0x80002820: nop

    return;
    // 0x80002820: nop

;}
RECOMP_FUNC void func_80002824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000282C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80002830:
    // 0x80002830: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80002834: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80002838: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8000283C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80002840: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80002844: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80002848: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000284C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80002850: lw          $t8, 0x6DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6DC0);
    // 0x80002854: nop

    // 0x80002858: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8000285C: beq         $t9, $zero, L_80002890
    if (ctx->r25 == 0) {
        // 0x80002860: nop

            goto L_80002890;
    }
    // 0x80002860: nop

    // 0x80002864: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80002868: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000286C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80002870: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80002874: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80002878: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8000287C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80002880: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80002884: sw          $zero, 0x6DC0($at)
    MEM_W(0X6DC0, ctx->r1) = 0;
    // 0x80002888: b           L_8000298C
    // 0x8000288C: nop

        goto L_8000298C;
    // 0x8000288C: nop

L_80002890:
    // 0x80002890: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80002894: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80002898: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8000289C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800028A0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800028A4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800028A8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800028AC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800028B0: lw          $t4, 0x6DC0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6DC0);
    // 0x800028B4: nop

    // 0x800028B8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800028BC: bne         $t5, $zero, L_800028CC
    if (ctx->r13 != 0) {
        // 0x800028C0: nop

            goto L_800028CC;
    }
    // 0x800028C0: nop

    // 0x800028C4: b           L_8000298C
    // 0x800028C8: nop

        goto L_8000298C;
    // 0x800028C8: nop

L_800028CC:
    // 0x800028CC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800028D0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800028D4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800028D8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800028DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800028E0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800028E4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800028E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800028EC: lw          $t8, 0x6DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6DC0);
    // 0x800028F0: nop

    // 0x800028F4: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x800028F8: beq         $t9, $zero, L_80002908
    if (ctx->r25 == 0) {
        // 0x800028FC: nop

            goto L_80002908;
    }
    // 0x800028FC: nop

    // 0x80002900: b           L_8000298C
    // 0x80002904: nop

        goto L_8000298C;
    // 0x80002904: nop

L_80002908:
    // 0x80002908: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000290C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80002910: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80002914: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80002918: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8000291C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80002920: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80002924: addiu       $t2, $t2, 0x6C20
    ctx->r10 = ADD32(ctx->r10, 0X6C20);
    // 0x80002928: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8000292C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80002930: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80002934: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002938: lw          $t5, 0x1A4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1A4);
    // 0x8000293C: nop

    // 0x80002940: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80002944: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80002948: lw          $t7, -0x248C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X248C);
    // 0x8000294C: nop

    // 0x80002950: bne         $t7, $zero, L_80002960
    if (ctx->r15 != 0) {
        // 0x80002954: nop

            goto L_80002960;
    }
    // 0x80002954: nop

    // 0x80002958: b           L_8000298C
    // 0x8000295C: nop

        goto L_8000298C;
    // 0x8000295C: nop

L_80002960:
    // 0x80002960: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80002964: nop

    // 0x80002968: lw          $t9, 0x1A4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A4);
    // 0x8000296C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80002970: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80002974: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80002978: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8000297C: lw          $t9, -0x248C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X248C);
    // 0x80002980: nop

    // 0x80002984: jalr        $t9
    // 0x80002988: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80002988: nop

    after_0:
L_8000298C:
    // 0x8000298C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80002990: nop

    // 0x80002994: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80002998: slti        $at, $t2, 0x20
    ctx->r1 = SIGNED(ctx->r10) < 0X20 ? 1 : 0;
    // 0x8000299C: bne         $at, $zero, L_80002830
    if (ctx->r1 != 0) {
        // 0x800029A0: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_80002830;
    }
    // 0x800029A0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800029A4: b           L_800029AC
    // 0x800029A8: nop

        goto L_800029AC;
    // 0x800029A8: nop

L_800029AC:
    // 0x800029AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800029B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800029B4: jr          $ra
    // 0x800029B8: nop

    return;
    // 0x800029B8: nop

;}
RECOMP_FUNC void func_800029BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800029BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800029C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800029C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800029C8: jal         0x800C41A0
    // 0x800029CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800029CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800029D0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800029D4: jal         0x800C4160
    // 0x800029D8: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x800029D8: nop

    after_1:
    // 0x800029DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800029E0: jal         0x800C4240
    // 0x800029E4: nop

    guRandom(rdram, ctx);
        goto after_2;
    // 0x800029E4: nop

    after_2:
    // 0x800029E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800029EC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800029F0: mfhi        $s0
    ctx->r16 = hi;
    // 0x800029F4: beq         $s0, $zero, L_80002A1C
    if (ctx->r16 == 0) {
        // 0x800029F8: nop

            goto L_80002A1C;
    }
    // 0x800029F8: nop

    // 0x800029FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002A00: beq         $s0, $at, L_80002B28
    if (ctx->r16 == ctx->r1) {
        // 0x80002A04: nop

            goto L_80002B28;
    }
    // 0x80002A04: nop

    // 0x80002A08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002A0C: beq         $s0, $at, L_80002E3C
    if (ctx->r16 == ctx->r1) {
        // 0x80002A10: nop

            goto L_80002E3C;
    }
    // 0x80002A10: nop

    // 0x80002A14: b           L_80002EFC
    // 0x80002A18: nop

        goto L_80002EFC;
    // 0x80002A18: nop

L_80002A1C:
    // 0x80002A1C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_80002A20:
    // 0x80002A20: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80002A24: nop

    // 0x80002A28: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80002A2C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80002A30: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80002A34: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80002A38: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80002A3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80002A40: sh          $t9, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r25;
    // 0x80002A44: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80002A48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002A4C: sh          $t1, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r9;
    // 0x80002A50: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80002A54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80002A58: sh          $t3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r11;
    // 0x80002A5C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80002A60: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80002A64: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80002A68: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80002A6C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80002A70: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80002A74: addiu       $a2, $a2, 0x4F
    ctx->r6 = ADD32(ctx->r6, 0X4F);
    // 0x80002A78: addiu       $a0, $t5, 0x8
    ctx->r4 = ADD32(ctx->r13, 0X8);
    // 0x80002A7C: jal         0x800BD110
    // 0x80002A80: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    SysMem_Copy64(rdram, ctx);
        goto after_3;
    // 0x80002A80: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_3:
    // 0x80002A84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80002A88: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_80002A8C:
    // 0x80002A8C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80002A90: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80002A94: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80002A98: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80002A9C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80002AA0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80002AA4: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80002AA8: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x80002AAC: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80002AB0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80002AB4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80002AB8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80002ABC: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x80002AC0: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x80002AC4: jal         0x800BD110
    // 0x80002AC8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    SysMem_Copy64(rdram, ctx);
        goto after_4;
    // 0x80002AC8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_4:
    // 0x80002ACC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80002AD0: nop

    // 0x80002AD4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80002AD8: slti        $at, $t5, 0xF
    ctx->r1 = SIGNED(ctx->r13) < 0XF ? 1 : 0;
    // 0x80002ADC: bne         $at, $zero, L_80002A8C
    if (ctx->r1 != 0) {
        // 0x80002AE0: sw          $t5, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r13;
            goto L_80002A8C;
    }
    // 0x80002AE0: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80002AE4: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x80002AE8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80002AEC:
    // 0x80002AEC: jal         0x800C4270
    // 0x80002AF0: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_5;
    // 0x80002AF0: nop

    after_5:
    // 0x80002AF4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80002AF8: nop

    // 0x80002AFC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80002B00: bgtz        $t8, L_80002AEC
    if (SIGNED(ctx->r24) > 0) {
        // 0x80002B04: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_80002AEC;
    }
    // 0x80002B04: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80002B08: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80002B0C: nop

    // 0x80002B10: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80002B14: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x80002B18: bne         $at, $zero, L_80002A20
    if (ctx->r1 != 0) {
        // 0x80002B1C: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_80002A20;
    }
    // 0x80002B1C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80002B20: b           L_80002EFC
    // 0x80002B24: nop

        goto L_80002EFC;
    // 0x80002B24: nop

L_80002B28:
    // 0x80002B28: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_80002B2C:
    // 0x80002B2C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80002B30: nop

    // 0x80002B34: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80002B38: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80002B3C:
    // 0x80002B3C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80002B40:
    // 0x80002B40: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80002B44: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80002B48: bltz        $t2, L_80002DC8
    if (SIGNED(ctx->r10) < 0) {
        // 0x80002B4C: nop

            goto L_80002DC8;
    }
    // 0x80002B4C: nop

L_80002B50:
    // 0x80002B50: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80002B54: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80002B58: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80002B5C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80002B60: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80002B64: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80002B68: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80002B6C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80002B70: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80002B74: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80002B78: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80002B7C: lhu         $t4, -0x6100($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X6100);
    // 0x80002B80: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80002B84: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80002B88: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80002B8C: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80002B90: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x80002B94: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80002B98: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x80002B9C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80002BA0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80002BA4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80002BA8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80002BAC: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80002BB0: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x80002BB4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80002BB8: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x80002BBC: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80002BC0: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80002BC4: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x80002BC8: lhu         $t7, -0x6100($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6100);
    // 0x80002BCC: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x80002BD0: sll         $t6, $t1, 1
    ctx->r14 = S32(ctx->r9 << 1);
    // 0x80002BD4: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x80002BD8: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x80002BDC: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x80002BE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80002BE4: sh          $t9, 0x10($t4)
    MEM_H(0X10, ctx->r12) = ctx->r25;
    // 0x80002BE8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80002BEC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80002BF0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80002BF4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80002BF8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80002BFC: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x80002C00: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80002C04: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x80002C08: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80002C0C: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80002C10: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x80002C14: lhu         $t5, -0x6100($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X6100);
    // 0x80002C18: sll         $t3, $t3, 6
    ctx->r11 = S32(ctx->r11 << 6);
    // 0x80002C1C: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x80002C20: addu        $t9, $t0, $t2
    ctx->r25 = ADD32(ctx->r8, ctx->r10);
    // 0x80002C24: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x80002C28: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80002C2C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002C30: sh          $t1, 0x20($t7)
    MEM_H(0X20, ctx->r15) = ctx->r9;
    // 0x80002C34: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80002C38: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80002C3C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80002C40: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80002C44: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80002C48: addu        $t6, $t0, $t4
    ctx->r14 = ADD32(ctx->r8, ctx->r12);
    // 0x80002C4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80002C50: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80002C54: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x80002C58: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80002C5C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80002C60: lhu         $t0, -0x6100($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X6100);
    // 0x80002C64: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80002C68: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x80002C6C: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x80002C70: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x80002C74: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80002C78: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80002C7C: sh          $t3, 0x30($t5)
    MEM_H(0X30, ctx->r13) = ctx->r11;
    // 0x80002C80: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80002C84: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80002C88: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80002C8C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80002C90: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x80002C94: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80002C98: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80002C9C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80002CA0: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x80002CA4: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80002CA8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80002CAC: lhu         $t6, -0x6100($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X6100);
    // 0x80002CB0: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x80002CB4: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x80002CB8: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80002CBC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80002CC0: addu        $t0, $t3, $t7
    ctx->r8 = ADD32(ctx->r11, ctx->r15);
    // 0x80002CC4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80002CC8: sh          $t9, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r25;
    // 0x80002CCC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80002CD0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80002CD4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80002CD8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80002CDC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80002CE0: addu        $t8, $t2, $t5
    ctx->r24 = ADD32(ctx->r10, ctx->r13);
    // 0x80002CE4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80002CE8: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80002CEC: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x80002CF0: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x80002CF4: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80002CF8: lhu         $t2, -0x6100($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X6100);
    // 0x80002CFC: sll         $t3, $t3, 6
    ctx->r11 = S32(ctx->r11 << 6);
    // 0x80002D00: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x80002D04: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80002D08: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80002D0C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80002D10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002D14: sh          $t1, 0x50($t6)
    MEM_H(0X50, ctx->r14) = ctx->r9;
    // 0x80002D18: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80002D1C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80002D20: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80002D24: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80002D28: sll         $t0, $t7, 1
    ctx->r8 = S32(ctx->r15 << 1);
    // 0x80002D2C: addu        $t4, $t8, $t0
    ctx->r12 = ADD32(ctx->r24, ctx->r8);
    // 0x80002D30: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80002D34: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80002D38: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80002D3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80002D40: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x80002D44: lhu         $t8, -0x6100($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6100);
    // 0x80002D48: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80002D4C: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x80002D50: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x80002D54: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80002D58: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80002D5C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80002D60: sh          $t3, 0x60($t2)
    MEM_H(0X60, ctx->r10) = ctx->r11;
    // 0x80002D64: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80002D68: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80002D6C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80002D70: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80002D74: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80002D78: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80002D7C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80002D80: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80002D84: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80002D88: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x80002D8C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80002D90: lhu         $t4, -0x6100($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X6100);
    // 0x80002D94: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x80002D98: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x80002D9C: addu        $t3, $t7, $t0
    ctx->r11 = ADD32(ctx->r15, ctx->r8);
    // 0x80002DA0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80002DA4: addu        $t8, $t3, $t6
    ctx->r24 = ADD32(ctx->r11, ctx->r14);
    // 0x80002DA8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80002DAC: sh          $t9, 0x70($t8)
    MEM_H(0X70, ctx->r24) = ctx->r25;
    // 0x80002DB0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80002DB4: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80002DB8: addiu       $t7, $t1, 0x1
    ctx->r15 = ADD32(ctx->r9, 0X1);
    // 0x80002DBC: slt         $at, $t0, $t7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80002DC0: beq         $at, $zero, L_80002B50
    if (ctx->r1 == 0) {
        // 0x80002DC4: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_80002B50;
    }
    // 0x80002DC4: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_80002DC8:
    // 0x80002DC8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80002DCC: nop

    // 0x80002DD0: addiu       $t5, $t2, 0x40
    ctx->r13 = ADD32(ctx->r10, 0X40);
    // 0x80002DD4: slti        $at, $t5, 0x140
    ctx->r1 = SIGNED(ctx->r13) < 0X140 ? 1 : 0;
    // 0x80002DD8: bne         $at, $zero, L_80002B40
    if (ctx->r1 != 0) {
        // 0x80002DDC: sw          $t5, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r13;
            goto L_80002B40;
    }
    // 0x80002DDC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80002DE0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80002DE4: nop

    // 0x80002DE8: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x80002DEC: slti        $at, $t3, 0xF0
    ctx->r1 = SIGNED(ctx->r11) < 0XF0 ? 1 : 0;
    // 0x80002DF0: bne         $at, $zero, L_80002B3C
    if (ctx->r1 != 0) {
        // 0x80002DF4: sw          $t3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r11;
            goto L_80002B3C;
    }
    // 0x80002DF4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x80002DF8: b           L_80002E1C
    // 0x80002DFC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
        goto L_80002E1C;
    // 0x80002DFC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80002E00:
    // 0x80002E00: jal         0x800C4270
    // 0x80002E04: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_6;
    // 0x80002E04: nop

    after_6:
    // 0x80002E08: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80002E0C: nop

    // 0x80002E10: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80002E14: bgtz        $t9, L_80002E00
    if (SIGNED(ctx->r25) > 0) {
        // 0x80002E18: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_80002E00;
    }
    // 0x80002E18: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80002E1C:
    // 0x80002E1C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80002E20: nop

    // 0x80002E24: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80002E28: slti        $at, $t1, 0x40
    ctx->r1 = SIGNED(ctx->r9) < 0X40 ? 1 : 0;
    // 0x80002E2C: bne         $at, $zero, L_80002B2C
    if (ctx->r1 != 0) {
        // 0x80002E30: sw          $t1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r9;
            goto L_80002B2C;
    }
    // 0x80002E30: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80002E34: b           L_80002EFC
    // 0x80002E38: nop

        goto L_80002EFC;
    // 0x80002E38: nop

L_80002E3C:
    // 0x80002E3C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_80002E40:
    // 0x80002E40: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80002E44: nop

    // 0x80002E48: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80002E4C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80002E50:
    // 0x80002E50: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80002E54: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80002E58: bltz        $t0, L_80002E90
    if (SIGNED(ctx->r8) < 0) {
        // 0x80002E5C: nop

            goto L_80002E90;
    }
    // 0x80002E5C: nop

L_80002E60:
    // 0x80002E60: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80002E64: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80002E68: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x80002E6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80002E70: addu        $t6, $t5, $t3
    ctx->r14 = ADD32(ctx->r13, ctx->r11);
    // 0x80002E74: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
    // 0x80002E78: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80002E7C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80002E80: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80002E84: slt         $at, $t1, $t8
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80002E88: beq         $at, $zero, L_80002E60
    if (ctx->r1 == 0) {
        // 0x80002E8C: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_80002E60;
    }
    // 0x80002E8C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_80002E90:
    // 0x80002E90: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80002E94: nop

    // 0x80002E98: addiu       $t0, $t7, 0xC
    ctx->r8 = ADD32(ctx->r15, 0XC);
    // 0x80002E9C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80002EA0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80002EA4: nop

    // 0x80002EA8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80002EAC: slti        $at, $t5, 0x3200
    ctx->r1 = SIGNED(ctx->r13) < 0X3200 ? 1 : 0;
    // 0x80002EB0: bne         $at, $zero, L_80002E50
    if (ctx->r1 != 0) {
        // 0x80002EB4: sw          $t5, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r13;
            goto L_80002E50;
    }
    // 0x80002EB4: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x80002EB8: addiu       $t3, $zero, 0x320
    ctx->r11 = ADD32(0, 0X320);
    // 0x80002EBC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80002EC0:
    // 0x80002EC0: jal         0x800C4270
    // 0x80002EC4: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_7;
    // 0x80002EC4: nop

    after_7:
    // 0x80002EC8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80002ECC: nop

    // 0x80002ED0: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x80002ED4: bgtz        $t6, L_80002EC0
    if (SIGNED(ctx->r14) > 0) {
        // 0x80002ED8: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80002EC0;
    }
    // 0x80002ED8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80002EDC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80002EE0: nop

    // 0x80002EE4: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80002EE8: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x80002EEC: bne         $at, $zero, L_80002E40
    if (ctx->r1 != 0) {
        // 0x80002EF0: sw          $t8, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r24;
            goto L_80002E40;
    }
    // 0x80002EF0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80002EF4: b           L_80002EFC
    // 0x80002EF8: nop

        goto L_80002EFC;
    // 0x80002EF8: nop

L_80002EFC:
    // 0x80002EFC: b           L_80002EFC
    pause_self(rdram);
    // 0x80002F00: nop

    // 0x80002F04: b           L_80002F0C
    // 0x80002F08: nop

        goto L_80002F0C;
    // 0x80002F08: nop

L_80002F0C:
    // 0x80002F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002F10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002F14: jr          $ra
    // 0x80002F18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80002F18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80002F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002F1C: nop

;}
RECOMP_FUNC void func_80002F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002F20: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80002F24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80002F28: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80002F2C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80002F30: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80002F34: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80002F38: nop

    // 0x80002F3C: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80002F40: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80002F44: jal         0x80098820
    // 0x80002F48: nop

    func_80098820(rdram, ctx);
        goto after_0;
    // 0x80002F48: nop

    after_0:
    // 0x80002F4C: jal         0x800C0A40
    // 0x80002F50: nop

    func_800C0A40(rdram, ctx);
        goto after_1;
    // 0x80002F50: nop

    after_1:
    // 0x80002F54: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80002F58: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80002F5C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80002F60: nop

    // 0x80002F64: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80002F68: bne         $t1, $zero, L_80002F84
    if (ctx->r9 != 0) {
        // 0x80002F6C: nop

            goto L_80002F84;
    }
    // 0x80002F6C: nop

    // 0x80002F70: lhu         $t2, 0x6($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X6);
    // 0x80002F74: nop

    // 0x80002F78: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x80002F7C: beq         $t3, $zero, L_80002FAC
    if (ctx->r11 == 0) {
        // 0x80002F80: nop

            goto L_80002FAC;
    }
    // 0x80002F80: nop

L_80002F84:
    // 0x80002F84: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80002F88: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80002F8C: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x80002F90: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80002F94: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80002F98: sh          $t7, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r15;
    // 0x80002F9C: jal         0x8000BB00
    // 0x80002FA0: nop

    func_8000BB00(rdram, ctx);
        goto after_2;
    // 0x80002FA0: nop

    after_2:
    // 0x80002FA4: b           L_80003230
    // 0x80002FA8: nop

        goto L_80003230;
    // 0x80002FA8: nop

L_80002FAC:
    // 0x80002FAC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80002FB0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80002FB4: lh          $t6, -0x73C0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X73C0);
    // 0x80002FB8: lh          $t8, -0x73A8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X73A8);
    // 0x80002FBC: nop

    // 0x80002FC0: beq         $t8, $t6, L_800030E4
    if (ctx->r24 == ctx->r14) {
        // 0x80002FC4: nop

            goto L_800030E4;
    }
    // 0x80002FC4: nop

    // 0x80002FC8: bltz        $t8, L_800030E4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80002FCC: nop

            goto L_800030E4;
    }
    // 0x80002FCC: nop

    // 0x80002FD0: bltz        $t6, L_800030E4
    if (SIGNED(ctx->r14) < 0) {
        // 0x80002FD4: nop

            goto L_800030E4;
    }
    // 0x80002FD4: nop

    // 0x80002FD8: jal         0x800045AC
    // 0x80002FDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_3;
    // 0x80002FDC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80002FE0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80002FE4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80002FE8: nop

    // 0x80002FEC: beq         $t0, $zero, L_800030DC
    if (ctx->r8 == 0) {
        // 0x80002FF0: nop

            goto L_800030DC;
    }
    // 0x80002FF0: nop

    // 0x80002FF4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80002FF8: lh          $t1, -0x73C0($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X73C0);
    // 0x80002FFC: nop

    // 0x80003000: sw          $t1, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r9;
    // 0x80003004: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80003008: jal         0x8000C3B0
    // 0x8000300C: nop

    func_8000C3B0(rdram, ctx);
        goto after_4;
    // 0x8000300C: nop

    after_4:
    // 0x80003010: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80003014: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80003018: lhu         $t2, 0x6($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X6);
    // 0x8000301C: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80003020: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80003024: sh          $t3, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r11;
    // 0x80003028: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8000302C: nop

    // 0x80003030: lw          $t7, 0x1A8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1A8);
    // 0x80003034: nop

    // 0x80003038: ori         $t4, $t7, 0x1
    ctx->r12 = ctx->r15 | 0X1;
    // 0x8000303C: sw          $t4, 0x1A8($t5)
    MEM_W(0X1A8, ctx->r13) = ctx->r12;
    // 0x80003040: jal         0x8000BB00
    // 0x80003044: nop

    func_8000BB00(rdram, ctx);
        goto after_5;
    // 0x80003044: nop

    after_5:
    // 0x80003048: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x8000304C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80003050: sh          $t8, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r24;
    // 0x80003054: jal         0x80016074
    // 0x80003058: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80016074(rdram, ctx);
        goto after_6;
    // 0x80003058: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_6:
    // 0x8000305C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80003060: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80003064: nop

    // 0x80003068: beq         $t6, $zero, L_80003098
    if (ctx->r14 == 0) {
        // 0x8000306C: nop

            goto L_80003098;
    }
    // 0x8000306C: nop

    // 0x80003070: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80003074: nop

    // 0x80003078: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8000307C: nop

    // 0x80003080: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x80003084: beq         $t2, $zero, L_80003098
    if (ctx->r10 == 0) {
        // 0x80003088: nop

            goto L_80003098;
    }
    // 0x80003088: nop

    // 0x8000308C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80003090: jal         0x80019F4C
    // 0x80003094: nop

    func_80019F4C(rdram, ctx);
        goto after_7;
    // 0x80003094: nop

    after_7:
L_80003098:
    // 0x80003098: jal         0x80016074
    // 0x8000309C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80016074(rdram, ctx);
        goto after_8;
    // 0x8000309C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_8:
    // 0x800030A0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800030A4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800030A8: nop

    // 0x800030AC: beq         $t3, $zero, L_800030DC
    if (ctx->r11 == 0) {
        // 0x800030B0: nop

            goto L_800030DC;
    }
    // 0x800030B0: nop

    // 0x800030B4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800030B8: nop

    // 0x800030BC: lw          $t7, 0x1A8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X1A8);
    // 0x800030C0: nop

    // 0x800030C4: andi        $t4, $t7, 0x7
    ctx->r12 = ctx->r15 & 0X7;
    // 0x800030C8: beq         $t4, $zero, L_800030DC
    if (ctx->r12 == 0) {
        // 0x800030CC: nop

            goto L_800030DC;
    }
    // 0x800030CC: nop

    // 0x800030D0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800030D4: jal         0x80019F4C
    // 0x800030D8: nop

    func_80019F4C(rdram, ctx);
        goto after_9;
    // 0x800030D8: nop

    after_9:
L_800030DC:
    // 0x800030DC: b           L_80003230
    // 0x800030E0: nop

        goto L_80003230;
    // 0x800030E0: nop

L_800030E4:
    // 0x800030E4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800030E8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800030EC: lh          $t8, -0x73C0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X73C0);
    // 0x800030F0: lh          $t5, -0x73A8($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X73A8);
    // 0x800030F4: nop

    // 0x800030F8: bne         $t5, $t8, L_80003230
    if (ctx->r13 != ctx->r24) {
        // 0x800030FC: nop

            goto L_80003230;
    }
    // 0x800030FC: nop

    // 0x80003100: bltz        $t8, L_80003230
    if (SIGNED(ctx->r24) < 0) {
        // 0x80003104: nop

            goto L_80003230;
    }
    // 0x80003104: nop

    // 0x80003108: jal         0x800045AC
    // 0x8000310C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_10;
    // 0x8000310C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x80003110: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80003114: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80003118: nop

    // 0x8000311C: beq         $t6, $zero, L_80003230
    if (ctx->r14 == 0) {
        // 0x80003120: nop

            goto L_80003230;
    }
    // 0x80003120: nop

    // 0x80003124: lw          $t0, 0x20C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X20C);
    // 0x80003128: nop

    // 0x8000312C: beq         $t0, $zero, L_80003230
    if (ctx->r8 == 0) {
        // 0x80003130: nop

            goto L_80003230;
    }
    // 0x80003130: nop

    // 0x80003134: lhu         $t1, 0x14($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X14);
    // 0x80003138: nop

    // 0x8000313C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80003140: beq         $t2, $zero, L_80003230
    if (ctx->r10 == 0) {
        // 0x80003144: nop

            goto L_80003230;
    }
    // 0x80003144: nop

    // 0x80003148: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000314C: lh          $t3, -0x73C0($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X73C0);
    // 0x80003150: nop

    // 0x80003154: sw          $t3, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r11;
    // 0x80003158: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000315C: jal         0x8000C3B0
    // 0x80003160: nop

    func_8000C3B0(rdram, ctx);
        goto after_11;
    // 0x80003160: nop

    after_11:
    // 0x80003164: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80003168: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8000316C: lhu         $t7, 0x6($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X6);
    // 0x80003170: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80003174: and         $t4, $t7, $at
    ctx->r12 = ctx->r15 & ctx->r1;
    // 0x80003178: sh          $t4, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r12;
    // 0x8000317C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80003180: nop

    // 0x80003184: lw          $t8, 0x1A8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1A8);
    // 0x80003188: nop

    // 0x8000318C: ori         $t6, $t8, 0x1
    ctx->r14 = ctx->r24 | 0X1;
    // 0x80003190: sw          $t6, 0x1A8($t5)
    MEM_W(0X1A8, ctx->r13) = ctx->r14;
    // 0x80003194: jal         0x8000BB00
    // 0x80003198: nop

    func_8000BB00(rdram, ctx);
        goto after_12;
    // 0x80003198: nop

    after_12:
    // 0x8000319C: lw          $t0, 0x100($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X100);
    // 0x800031A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800031A4: sh          $t0, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r8;
    // 0x800031A8: jal         0x80016074
    // 0x800031AC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80016074(rdram, ctx);
        goto after_13;
    // 0x800031AC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_13:
    // 0x800031B0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800031B4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800031B8: nop

    // 0x800031BC: beq         $t1, $zero, L_800031EC
    if (ctx->r9 == 0) {
        // 0x800031C0: nop

            goto L_800031EC;
    }
    // 0x800031C0: nop

    // 0x800031C4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800031C8: nop

    // 0x800031CC: lw          $t3, 0x1A8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A8);
    // 0x800031D0: nop

    // 0x800031D4: andi        $t7, $t3, 0x7
    ctx->r15 = ctx->r11 & 0X7;
    // 0x800031D8: beq         $t7, $zero, L_800031EC
    if (ctx->r15 == 0) {
        // 0x800031DC: nop

            goto L_800031EC;
    }
    // 0x800031DC: nop

    // 0x800031E0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800031E4: jal         0x80019F4C
    // 0x800031E8: nop

    func_80019F4C(rdram, ctx);
        goto after_14;
    // 0x800031E8: nop

    after_14:
L_800031EC:
    // 0x800031EC: jal         0x80016074
    // 0x800031F0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80016074(rdram, ctx);
        goto after_15;
    // 0x800031F0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_15:
    // 0x800031F4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800031F8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800031FC: nop

    // 0x80003200: beq         $t4, $zero, L_80003230
    if (ctx->r12 == 0) {
        // 0x80003204: nop

            goto L_80003230;
    }
    // 0x80003204: nop

    // 0x80003208: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8000320C: nop

    // 0x80003210: lw          $t8, 0x1A8($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X1A8);
    // 0x80003214: nop

    // 0x80003218: andi        $t6, $t8, 0x7
    ctx->r14 = ctx->r24 & 0X7;
    // 0x8000321C: beq         $t6, $zero, L_80003230
    if (ctx->r14 == 0) {
        // 0x80003220: nop

            goto L_80003230;
    }
    // 0x80003220: nop

    // 0x80003224: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80003228: jal         0x80019F4C
    // 0x8000322C: nop

    func_80019F4C(rdram, ctx);
        goto after_16;
    // 0x8000322C: nop

    after_16:
L_80003230:
    // 0x80003230: jal         0x800BCB54
    // 0x80003234: nop

    func_800BCB54(rdram, ctx);
        goto after_17;
    // 0x80003234: nop

    after_17:
    // 0x80003238: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000323C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80003240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003244: jal         0x800BDC70
    // 0x80003248: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BDC70(rdram, ctx);
        goto after_18;
    // 0x80003248: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_18:
    // 0x8000324C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003250: sw          $zero, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = 0;
    // 0x80003254: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80003258: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000325C: sw          $t5, 0x7244($at)
    MEM_W(0X7244, ctx->r1) = ctx->r13;
    // 0x80003260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80003264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80003268: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000326C: swc1        $f4, 0x727C($at)
    MEM_W(0X727C, ctx->r1) = ctx->f4.u32l;
    // 0x80003270: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003274: swc1        $f4, 0x7270($at)
    MEM_W(0X7270, ctx->r1) = ctx->f4.u32l;
    // 0x80003278: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000327C: swc1        $f4, 0x7264($at)
    MEM_W(0X7264, ctx->r1) = ctx->f4.u32l;
    // 0x80003280: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80003284: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80003288: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000328C: swc1        $f6, 0x25D0($at)
    MEM_W(0X25D0, ctx->r1) = ctx->f6.u32l;
    // 0x80003290: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80003294: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80003298: sw          $t0, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r8;
    // 0x8000329C: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x800032A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800032A4: sw          $t1, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r9;
    // 0x800032A8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800032AC: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800032B0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800032B4: addiu       $at, $zero, -0x1201
    ctx->r1 = ADD32(0, -0X1201);
    // 0x800032B8: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x800032BC: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
    // 0x800032C0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800032C4: lh          $t4, -0x73C0($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X73C0);
    // 0x800032C8: nop

    // 0x800032CC: bltz        $t4, L_800032E4
    if (SIGNED(ctx->r12) < 0) {
        // 0x800032D0: nop

            goto L_800032E4;
    }
    // 0x800032D0: nop

    // 0x800032D4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800032D8: lh          $t9, -0x73C0($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X73C0);
    // 0x800032DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800032E0: sh          $t9, -0x73A8($at)
    MEM_H(-0X73A8, ctx->r1) = ctx->r25;
L_800032E4:
    // 0x800032E4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800032E8: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800032EC: lh          $t6, 0x723C($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X723C);
    // 0x800032F0: lh          $t8, 0x7234($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7234);
    // 0x800032F4: nop

    // 0x800032F8: bne         $t8, $t6, L_80003340
    if (ctx->r24 != ctx->r14) {
        // 0x800032FC: nop

            goto L_80003340;
    }
    // 0x800032FC: nop

    // 0x80003300: bne         $t8, $zero, L_80003340
    if (ctx->r24 != 0) {
        // 0x80003304: nop

            goto L_80003340;
    }
    // 0x80003304: nop

    // 0x80003308: addiu       $t5, $zero, 0x1F4
    ctx->r13 = ADD32(0, 0X1F4);
    // 0x8000330C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80003310: sh          $t5, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r13;
    // 0x80003314: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80003318: lh          $t0, -0x73C0($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X73C0);
    // 0x8000331C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80003320: sh          $t0, -0x73A8($at)
    MEM_H(-0X73A8, ctx->r1) = ctx->r8;
    // 0x80003324: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80003328: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000332C: sh          $t1, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r9;
    // 0x80003330: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80003334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003338: b           L_80003390
    // 0x8000333C: sh          $t3, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r11;
        goto L_80003390;
    // 0x8000333C: sh          $t3, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r11;
L_80003340:
    // 0x80003340: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80003344: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80003348: lh          $t2, 0x723C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X723C);
    // 0x8000334C: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x80003350: nop

    // 0x80003354: bne         $t7, $t2, L_80003390
    if (ctx->r15 != ctx->r10) {
        // 0x80003358: nop

            goto L_80003390;
    }
    // 0x80003358: nop

    // 0x8000335C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80003360: bne         $t7, $at, L_80003390
    if (ctx->r15 != ctx->r1) {
        // 0x80003364: nop

            goto L_80003390;
    }
    // 0x80003364: nop

    // 0x80003368: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000336C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003370: sh          $t4, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r12;
    // 0x80003374: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003378: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000337C: sh          $t9, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r25;
    // 0x80003380: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80003384: lh          $t6, -0x73A8($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X73A8);
    // 0x80003388: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000338C: sh          $t6, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r14;
L_80003390:
    // 0x80003390: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80003394: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80003398: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000339C: jal         0x80099F90
    // 0x800033A0: nop

    func_80099F90(rdram, ctx);
        goto after_19;
    // 0x800033A0: nop

    after_19:
    // 0x800033A4: jal         0x80004510
    // 0x800033A8: nop

    func_80004510(rdram, ctx);
        goto after_20;
    // 0x800033A8: nop

    after_20:
    // 0x800033AC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800033B0: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800033B4: lhu         $t5, 0x0($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X0);
    // 0x800033B8: nop

    // 0x800033BC: andi        $t0, $t5, 0x80
    ctx->r8 = ctx->r13 & 0X80;
    // 0x800033C0: bne         $t0, $zero, L_800035E4
    if (ctx->r8 != 0) {
        // 0x800033C4: nop

            goto L_800035E4;
    }
    // 0x800033C4: nop

    // 0x800033C8: jal         0x80004654
    // 0x800033CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80004654(rdram, ctx);
        goto after_21;
    // 0x800033CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_21:
    // 0x800033D0: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800033D4: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x800033D8: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x800033DC: nop

    // 0x800033E0: andi        $t2, $t3, 0x200
    ctx->r10 = ctx->r11 & 0X200;
    // 0x800033E4: beq         $t2, $zero, L_800035E4
    if (ctx->r10 == 0) {
        // 0x800033E8: nop

            goto L_800035E4;
    }
    // 0x800033E8: nop

    // 0x800033EC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800033F0: addiu       $t7, $t7, 0x3DF8
    ctx->r15 = ADD32(ctx->r15, 0X3DF8);
    // 0x800033F4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800033F8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800033FC: jal         0x800C143C
    // 0x80003400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_22;
    // 0x80003400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x80003404: jal         0x80015E50
    // 0x80003408: nop

    func_80015E50(rdram, ctx);
        goto after_23;
    // 0x80003408: nop

    after_23:
    // 0x8000340C: jal         0x80015E94
    // 0x80003410: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80015E94(rdram, ctx);
        goto after_24;
    // 0x80003410: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_24:
    // 0x80003414: jal         0x80015E94
    // 0x80003418: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80015E94(rdram, ctx);
        goto after_25;
    // 0x80003418: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_25:
    // 0x8000341C: jal         0x80015E94
    // 0x80003420: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80015E94(rdram, ctx);
        goto after_26;
    // 0x80003420: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_26:
    // 0x80003424: jal         0x80015E94
    // 0x80003428: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80015E94(rdram, ctx);
        goto after_27;
    // 0x80003428: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_27:
    // 0x8000342C: jal         0x80015E94
    // 0x80003430: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80015E94(rdram, ctx);
        goto after_28;
    // 0x80003430: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_28:
    // 0x80003434: jal         0x800161E0
    // 0x80003438: nop

    func_800161E0(rdram, ctx);
        goto after_29;
    // 0x80003438: nop

    after_29:
    // 0x8000343C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80003440: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80003444: lhu         $t9, 0x2($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X2);
    // 0x80003448: nop

    // 0x8000344C: andi        $t6, $t9, 0x2
    ctx->r14 = ctx->r25 & 0X2;
    // 0x80003450: beq         $t6, $zero, L_8000346C
    if (ctx->r14 == 0) {
        // 0x80003454: nop

            goto L_8000346C;
    }
    // 0x80003454: nop

    // 0x80003458: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8000345C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80003460: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80003464: b           L_800034B8
    // 0x80003468: swc1        $f8, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f8.u32l;
        goto L_800034B8;
    // 0x80003468: swc1        $f8, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f8.u32l;
L_8000346C:
    // 0x8000346C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80003470: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80003474: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x80003478: nop

    // 0x8000347C: andi        $t0, $t5, 0x4
    ctx->r8 = ctx->r13 & 0X4;
    // 0x80003480: beq         $t0, $zero, L_800034B8
    if (ctx->r8 == 0) {
        // 0x80003484: nop

            goto L_800034B8;
    }
    // 0x80003484: nop

    // 0x80003488: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8000348C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80003490: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80003494: swc1        $f10, -0x44CC($at)
    MEM_W(-0X44CC, ctx->r1) = ctx->f10.u32l;
    // 0x80003498: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8000349C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800034A0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800034A4: swc1        $f16, -0x44C4($at)
    MEM_W(-0X44C4, ctx->r1) = ctx->f16.u32l;
    // 0x800034A8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800034AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800034B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800034B4: swc1        $f18, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f18.u32l;
L_800034B8:
    // 0x800034B8: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x800034BC: addiu       $t1, $t1, 0x3DF8
    ctx->r9 = ADD32(ctx->r9, 0X3DF8);
    // 0x800034C0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800034C4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800034C8: jal         0x800C143C
    // 0x800034CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_30;
    // 0x800034CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_30:
    // 0x800034D0: jal         0x800045AC
    // 0x800034D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_31;
    // 0x800034D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_31:
    // 0x800034D8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800034DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800034E0: jal         0x8000BDDC
    // 0x800034E4: nop

    func_8000BDDC(rdram, ctx);
        goto after_32;
    // 0x800034E4: nop

    after_32:
    // 0x800034E8: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800034EC: addiu       $t3, $t3, 0x3DF8
    ctx->r11 = ADD32(ctx->r11, 0X3DF8);
    // 0x800034F0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800034F4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800034F8: jal         0x800C143C
    // 0x800034FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_33;
    // 0x800034FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_33:
    // 0x80003500: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80003504: lh          $t2, 0x7254($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7254);
    // 0x80003508: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000350C: andi        $t7, $t2, 0x7FFF
    ctx->r15 = ctx->r10 & 0X7FFF;
    // 0x80003510: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
    // 0x80003514: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80003518: lh          $t4, 0x725C($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X725C);
    // 0x8000351C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003520: andi        $t9, $t4, 0x7FFF
    ctx->r25 = ctx->r12 & 0X7FFF;
    // 0x80003524: sh          $t9, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r25;
    // 0x80003528: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000352C: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80003530: lhu         $t8, 0x6($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X6);
    // 0x80003534: nop

    // 0x80003538: andi        $t5, $t8, 0x4000
    ctx->r13 = ctx->r24 & 0X4000;
    // 0x8000353C: bne         $t5, $zero, L_80003554
    if (ctx->r13 != 0) {
        // 0x80003540: nop

            goto L_80003554;
    }
    // 0x80003540: nop

    // 0x80003544: jal         0x8000BB00
    // 0x80003548: nop

    func_8000BB00(rdram, ctx);
        goto after_34;
    // 0x80003548: nop

    after_34:
    // 0x8000354C: b           L_80003594
    // 0x80003550: nop

        goto L_80003594;
    // 0x80003550: nop

L_80003554:
    // 0x80003554: jal         0x8000BC7C
    // 0x80003558: nop

    func_8000BC7C(rdram, ctx);
        goto after_35;
    // 0x80003558: nop

    after_35:
    // 0x8000355C: jal         0x80004510
    // 0x80003560: nop

    func_80004510(rdram, ctx);
        goto after_36;
    // 0x80003560: nop

    after_36:
    // 0x80003564: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80003568: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x8000356C: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x80003570: nop

    // 0x80003574: ori         $t3, $t1, 0x4
    ctx->r11 = ctx->r9 | 0X4;
    // 0x80003578: sh          $t3, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r11;
    // 0x8000357C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80003580: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80003584: lhu         $t7, 0x6($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X6);
    // 0x80003588: nop

    // 0x8000358C: ori         $t4, $t7, 0x800
    ctx->r12 = ctx->r15 | 0X800;
    // 0x80003590: sh          $t4, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r12;
L_80003594:
    // 0x80003594: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80003598: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x8000359C: lhu         $t6, 0x6($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X6);
    // 0x800035A0: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x800035A4: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800035A8: sh          $t8, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r24;
    // 0x800035AC: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800035B0: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x800035B4: lhu         $t1, 0x0($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X0);
    // 0x800035B8: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x800035BC: and         $t3, $t1, $at
    ctx->r11 = ctx->r9 & ctx->r1;
    // 0x800035C0: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
    // 0x800035C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800035C8: sh          $zero, 0x664($at)
    MEM_H(0X664, ctx->r1) = 0;
    // 0x800035CC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x800035D0: addiu       $t0, $t0, 0x3DF8
    ctx->r8 = ADD32(ctx->r8, 0X3DF8);
    // 0x800035D4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800035D8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800035DC: jal         0x800C143C
    // 0x800035E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_37;
    // 0x800035E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_37:
L_800035E4:
    // 0x800035E4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800035E8: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x800035EC: lhu         $t4, 0x6($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X6);
    // 0x800035F0: nop

    // 0x800035F4: andi        $t2, $t4, 0x2000
    ctx->r10 = ctx->r12 & 0X2000;
    // 0x800035F8: beq         $t2, $zero, L_80003618
    if (ctx->r10 == 0) {
        // 0x800035FC: nop

            goto L_80003618;
    }
    // 0x800035FC: nop

    // 0x80003600: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80003604: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80003608: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x8000360C: nop

    // 0x80003610: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80003614: sh          $t9, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r25;
L_80003618:
    // 0x80003618: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000361C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80003620: lh          $a1, 0x723C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X723C);
    // 0x80003624: lh          $a0, 0x7234($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7234);
    // 0x80003628: jal         0x80004410
    // 0x8000362C: nop

    func_80004410(rdram, ctx);
        goto after_38;
    // 0x8000362C: nop

    after_38:
    // 0x80003630: sw          $v0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r2;
    // 0x80003634: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x80003638: nop

    // 0x8000363C: bne         $t1, $zero, L_8000364C
    if (ctx->r9 != 0) {
        // 0x80003640: nop

            goto L_8000364C;
    }
    // 0x80003640: nop

    // 0x80003644: b           L_80004400
    // 0x80003648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80004400;
    // 0x80003648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000364C:
    // 0x8000364C: jal         0x800C4270
    // 0x80003650: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_39;
    // 0x80003650: nop

    after_39:
    // 0x80003654: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x80003658: nop

    // 0x8000365C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80003660: nop

    // 0x80003664: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x80003668: lw          $t0, 0xF4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XF4);
    // 0x8000366C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003670: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x80003674: addiu       $t4, $t0, 0x2
    ctx->r12 = ADD32(ctx->r8, 0X2);
    // 0x80003678: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    // 0x8000367C: sh          $t7, 0x721C($at)
    MEM_H(0X721C, ctx->r1) = ctx->r15;
    // 0x80003680: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80003684: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003688: lhu         $t8, 0x0($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X0);
    // 0x8000368C: addiu       $t9, $t2, 0x2
    ctx->r25 = ADD32(ctx->r10, 0X2);
    // 0x80003690: sw          $t9, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r25;
    // 0x80003694: sh          $t8, 0x72D4($at)
    MEM_H(0X72D4, ctx->r1) = ctx->r24;
    // 0x80003698: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8000369C: lh          $t6, 0x72D4($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X72D4);
    // 0x800036A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800036A4: bne         $t6, $at, L_800036B4
    if (ctx->r14 != ctx->r1) {
        // 0x800036A8: nop

            goto L_800036B4;
    }
    // 0x800036A8: nop

    // 0x800036AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800036B0: sh          $zero, 0x72D4($at)
    MEM_H(0X72D4, ctx->r1) = 0;
L_800036B4:
    // 0x800036B4: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    // 0x800036B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800036BC: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x800036C0: addiu       $t5, $t1, 0x2
    ctx->r13 = ADD32(ctx->r9, 0X2);
    // 0x800036C4: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x800036C8: sw          $t3, -0x71BC($at)
    MEM_W(-0X71BC, ctx->r1) = ctx->r11;
    // 0x800036CC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800036D0: lw          $t7, -0x71BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71BC);
    // 0x800036D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800036D8: bne         $t7, $at, L_800036EC
    if (ctx->r15 != ctx->r1) {
        // 0x800036DC: nop

            goto L_800036EC;
    }
    // 0x800036DC: nop

    // 0x800036E0: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x800036E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800036E8: sw          $t0, -0x71BC($at)
    MEM_W(-0X71BC, ctx->r1) = ctx->r8;
L_800036EC:
    // 0x800036EC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800036F0: lw          $t4, -0x33BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X33BC);
    // 0x800036F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800036F8: sw          $t4, 0x18EC($at)
    MEM_W(0X18EC, ctx->r1) = ctx->r12;
    // 0x800036FC: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x80003700: nop

    // 0x80003704: lh          $t2, 0x0($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X0);
    // 0x80003708: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8000370C: sw          $t9, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r25;
    // 0x80003710: sw          $t2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r10;
    // 0x80003714: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x80003718: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000371C: beq         $t6, $at, L_80003764
    if (ctx->r14 == ctx->r1) {
        // 0x80003720: nop

            goto L_80003764;
    }
    // 0x80003720: nop

    // 0x80003724: lw          $t3, 0x100($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X100);
    // 0x80003728: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000372C: sw          $t3, -0x33BC($at)
    MEM_W(-0X33BC, ctx->r1) = ctx->r11;
    // 0x80003730: jal         0x800BB578
    // 0x80003734: nop

    func_800BB578(rdram, ctx);
        goto after_40;
    // 0x80003734: nop

    after_40:
    // 0x80003738: andi        $t1, $v0, 0x7
    ctx->r9 = ctx->r2 & 0X7;
    // 0x8000373C: sw          $t1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r9;
    // 0x80003740: lw          $t5, 0x104($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X104);
    // 0x80003744: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80003748: beq         $t5, $at, L_80003764
    if (ctx->r13 == ctx->r1) {
        // 0x8000374C: nop

            goto L_80003764;
    }
    // 0x8000374C: nop

    // 0x80003750: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003754: lw          $t7, -0x33BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X33BC);
    // 0x80003758: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8000375C: nor         $t0, $t7, $zero
    ctx->r8 = ~(ctx->r15 | 0);
    // 0x80003760: sw          $t0, 0x18EC($at)
    MEM_W(0X18EC, ctx->r1) = ctx->r8;
L_80003764:
    // 0x80003764: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80003768: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000376C: lhu         $t2, 0x6($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X6);
    // 0x80003770: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80003774: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x80003778: sh          $t8, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r24;
    // 0x8000377C: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80003780: nop

    // 0x80003784: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x80003788: addiu       $t3, $t9, 0x2
    ctx->r11 = ADD32(ctx->r25, 0X2);
    // 0x8000378C: sw          $t3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r11;
    // 0x80003790: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x80003794: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x80003798: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000379C: beq         $t1, $at, L_800037BC
    if (ctx->r9 == ctx->r1) {
        // 0x800037A0: nop

            goto L_800037BC;
    }
    // 0x800037A0: nop

    // 0x800037A4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800037A8: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x800037AC: lhu         $t7, 0x6($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X6);
    // 0x800037B0: nop

    // 0x800037B4: ori         $t0, $t7, 0x2
    ctx->r8 = ctx->r15 | 0X2;
    // 0x800037B8: sh          $t0, 0x6($t5)
    MEM_H(0X6, ctx->r13) = ctx->r8;
L_800037BC:
    // 0x800037BC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800037C0: lh          $t2, 0x721C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X721C);
    // 0x800037C4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800037C8: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800037CC: and         $t8, $t2, $at
    ctx->r24 = ctx->r10 & ctx->r1;
    // 0x800037D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800037D4: sh          $t8, 0x721C($at)
    MEM_H(0X721C, ctx->r1) = ctx->r24;
    // 0x800037D8: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800037DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800037E0: sh          $t4, 0x7228($at)
    MEM_H(0X7228, ctx->r1) = ctx->r12;
    // 0x800037E4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800037E8: lh          $t6, 0x7228($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7228);
    // 0x800037EC: nop

    // 0x800037F0: beq         $t6, $zero, L_8000380C
    if (ctx->r14 == 0) {
        // 0x800037F4: nop

            goto L_8000380C;
    }
    // 0x800037F4: nop

    // 0x800037F8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800037FC: lw          $t9, 0x7238($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7238);
    // 0x80003800: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003804: ori         $t3, $t9, 0x8000
    ctx->r11 = ctx->r25 | 0X8000;
    // 0x80003808: sw          $t3, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r11;
L_8000380C:
    // 0x8000380C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80003810: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80003814: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x80003818: nop

    // 0x8000381C: andi        $t0, $t7, 0x80
    ctx->r8 = ctx->r15 & 0X80;
    // 0x80003820: beq         $t0, $zero, L_8000383C
    if (ctx->r8 == 0) {
        // 0x80003824: nop

            goto L_8000383C;
    }
    // 0x80003824: nop

    // 0x80003828: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8000382C: lh          $t5, 0x721C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X721C);
    // 0x80003830: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003834: addiu       $t2, $t5, 0x2
    ctx->r10 = ADD32(ctx->r13, 0X2);
    // 0x80003838: sh          $t2, 0x721C($at)
    MEM_H(0X721C, ctx->r1) = ctx->r10;
L_8000383C:
    // 0x8000383C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80003840: lh          $t8, 0x721C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X721C);
    // 0x80003844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003848: beq         $t8, $at, L_8000385C
    if (ctx->r24 == ctx->r1) {
        // 0x8000384C: nop

            goto L_8000385C;
    }
    // 0x8000384C: nop

    // 0x80003850: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80003854: bne         $t8, $at, L_80003878
    if (ctx->r24 != ctx->r1) {
        // 0x80003858: nop

            goto L_80003878;
    }
    // 0x80003858: nop

L_8000385C:
    // 0x8000385C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80003860: lw          $t4, 0x7238($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7238);
    // 0x80003864: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80003868: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8000386C: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x80003870: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003874: sw          $t6, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r14;
L_80003878:
    // 0x80003878: addiu       $a0, $sp, 0xF4
    ctx->r4 = ADD32(ctx->r29, 0XF4);
    // 0x8000387C: jal         0x80004CD4
    // 0x80003880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80004CD4(rdram, ctx);
        goto after_41;
    // 0x80003880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_41:
    // 0x80003884: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003888: bne         $v0, $at, L_80003898
    if (ctx->r2 != ctx->r1) {
        // 0x8000388C: nop

            goto L_80003898;
    }
    // 0x8000388C: nop

    // 0x80003890: b           L_80004400
    // 0x80003894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80004400;
    // 0x80003894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80003898:
    // 0x80003898: jal         0x80004ADC
    // 0x8000389C: nop

    func_80004ADC(rdram, ctx);
        goto after_42;
    // 0x8000389C: nop

    after_42:
    // 0x800038A0: lui         $t9, 0x809B
    ctx->r25 = S32(0X809B << 16);
    // 0x800038A4: lui         $t3, 0x809B
    ctx->r11 = S32(0X809B << 16);
    // 0x800038A8: addiu       $t3, $t3, -0x7E70
    ctx->r11 = ADD32(ctx->r11, -0X7E70);
    // 0x800038AC: addiu       $t9, $t9, -0x7DD0
    ctx->r25 = ADD32(ctx->r25, -0X7DD0);
    // 0x800038B0: subu        $a0, $t9, $t3
    ctx->r4 = SUB32(ctx->r25, ctx->r11);
    // 0x800038B4: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x800038B8: srl         $t1, $a0, 3
    ctx->r9 = S32(U32(ctx->r4) >> 3);
    // 0x800038BC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800038C0: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800038C4: jal         0x800BC6EC
    // 0x800038C8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_43;
    // 0x800038C8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_43:
    // 0x800038CC: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800038D0: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800038D4: nop

    // 0x800038D8: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x800038DC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800038E0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800038E4: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800038E8: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800038EC: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x800038F0: jal         0x800BD1FC
    // 0x800038F4: addiu       $a2, $a2, -0x7E70
    ctx->r6 = ADD32(ctx->r6, -0X7E70);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_44;
    // 0x800038F4: addiu       $a2, $a2, -0x7E70
    ctx->r6 = ADD32(ctx->r6, -0X7E70);
    after_44:
    // 0x800038F8: lui         $t5, 0x809B
    ctx->r13 = S32(0X809B << 16);
    // 0x800038FC: lui         $t2, 0x809B
    ctx->r10 = S32(0X809B << 16);
    // 0x80003900: addiu       $t2, $t2, -0x7E70
    ctx->r10 = ADD32(ctx->r10, -0X7E70);
    // 0x80003904: addiu       $t5, $t5, -0x7DD0
    ctx->r13 = ADD32(ctx->r13, -0X7DD0);
    // 0x80003908: subu        $a2, $t5, $t2
    ctx->r6 = SUB32(ctx->r13, ctx->r10);
    // 0x8000390C: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x80003910: srl         $t8, $a2, 3
    ctx->r24 = S32(U32(ctx->r6) >> 3);
    // 0x80003914: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80003918: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x8000391C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80003920: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80003928: jal         0x800BD218
    // 0x8000392C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_45;
    // 0x8000392C: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_45:
    // 0x80003930: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003934: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80003938: jal         0x800BCFCC
    // 0x8000393C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_46;
    // 0x8000393C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_46:
    // 0x80003940: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003944: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80003948: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8000394C: jal         0x800BCFCC
    // 0x80003950: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_47;
    // 0x80003950: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_47:
    // 0x80003954: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80003958: jal         0x800BC980
    // 0x8000395C: nop

    SysMem_Free(rdram, ctx);
        goto after_48;
    // 0x8000395C: nop

    after_48:
    // 0x80003960: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80003964: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80003968: lui         $t6, 0x4000
    ctx->r14 = S32(0X4000 << 16);
    // 0x8000396C: ori         $t6, $t6, 0x4C
    ctx->r14 = ctx->r14 | 0X4C;
    // 0x80003970: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x80003974: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80003978: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8000397C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80003980: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80003984: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80003988: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8000398C: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80003990: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80003994: jal         0x800A66EC
    // 0x80003998: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    func_800A66EC(rdram, ctx);
        goto after_49;
    // 0x80003998: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_49:
    // 0x8000399C: lui         $t1, 0x809B
    ctx->r9 = S32(0X809B << 16);
    // 0x800039A0: lui         $t7, 0x809B
    ctx->r15 = S32(0X809B << 16);
    // 0x800039A4: addiu       $t7, $t7, -0x7E70
    ctx->r15 = ADD32(ctx->r15, -0X7E70);
    // 0x800039A8: addiu       $t1, $t1, -0x7DD0
    ctx->r9 = ADD32(ctx->r9, -0X7DD0);
    // 0x800039AC: subu        $a0, $t1, $t7
    ctx->r4 = SUB32(ctx->r9, ctx->r15);
    // 0x800039B0: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x800039B4: srl         $t0, $a0, 3
    ctx->r8 = S32(U32(ctx->r4) >> 3);
    // 0x800039B8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800039BC: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800039C0: jal         0x800BC6EC
    // 0x800039C4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_50;
    // 0x800039C4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_50:
    // 0x800039C8: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800039CC: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x800039D0: nop

    // 0x800039D4: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x800039D8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800039DC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800039E0: lw          $a1, 0x60E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60E8);
    // 0x800039E4: lw          $a0, 0x60E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60E0);
    // 0x800039E8: lui         $a2, 0x809B
    ctx->r6 = S32(0X809B << 16);
    // 0x800039EC: jal         0x800BD1FC
    // 0x800039F0: addiu       $a2, $a2, -0x7E70
    ctx->r6 = ADD32(ctx->r6, -0X7E70);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_51;
    // 0x800039F0: addiu       $a2, $a2, -0x7E70
    ctx->r6 = ADD32(ctx->r6, -0X7E70);
    after_51:
    // 0x800039F4: lui         $t8, 0x809B
    ctx->r24 = S32(0X809B << 16);
    // 0x800039F8: lui         $t4, 0x809B
    ctx->r12 = S32(0X809B << 16);
    // 0x800039FC: addiu       $t4, $t4, -0x7E70
    ctx->r12 = ADD32(ctx->r12, -0X7E70);
    // 0x80003A00: addiu       $t8, $t8, -0x7DD0
    ctx->r24 = ADD32(ctx->r24, -0X7DD0);
    // 0x80003A04: subu        $a2, $t8, $t4
    ctx->r6 = SUB32(ctx->r24, ctx->r12);
    // 0x80003A08: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x80003A0C: srl         $t6, $a2, 3
    ctx->r14 = S32(U32(ctx->r6) >> 3);
    // 0x80003A10: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80003A14: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x80003A18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80003A1C: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80003A24: jal         0x800BD218
    // 0x80003A28: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_52;
    // 0x80003A28: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_52:
L_80003A2C:
    // 0x80003A2C: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80003A30: nop

    // 0x80003A34: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80003A38: nop

    // 0x80003A3C: bne         $t1, $zero, L_80003A58
    if (ctx->r9 != 0) {
        // 0x80003A40: nop

            goto L_80003A58;
    }
    // 0x80003A40: nop

    // 0x80003A44: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80003A48: jal         0x800BC980
    // 0x80003A4C: nop

    SysMem_Free(rdram, ctx);
        goto after_53;
    // 0x80003A4C: nop

    after_53:
    // 0x80003A50: b           L_80004400
    // 0x80003A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80004400;
    // 0x80003A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80003A58:
    // 0x80003A58: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80003A5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003A60: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x80003A64: nop

    // 0x80003A68: bne         $t0, $at, L_80003A88
    if (ctx->r8 != ctx->r1) {
        // 0x80003A6C: nop

            goto L_80003A88;
    }
    // 0x80003A6C: nop

    // 0x80003A70: lh          $t5, 0x2($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X2);
    // 0x80003A74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80003A78: bne         $t5, $at, L_80003A88
    if (ctx->r13 != ctx->r1) {
        // 0x80003A7C: nop

            goto L_80003A88;
    }
    // 0x80003A7C: nop

    // 0x80003A80: b           L_80003A9C
    // 0x80003A84: nop

        goto L_80003A9C;
    // 0x80003A84: nop

L_80003A88:
    // 0x80003A88: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x80003A8C: nop

    // 0x80003A90: addiu       $t8, $t2, 0x20
    ctx->r24 = ADD32(ctx->r10, 0X20);
    // 0x80003A94: b           L_80003A2C
    // 0x80003A98: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
        goto L_80003A2C;
    // 0x80003A98: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
L_80003A9C:
    // 0x80003A9C: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003AA0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80003AA4: jal         0x800BCFCC
    // 0x80003AA8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_54;
    // 0x80003AA8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_54:
    // 0x80003AAC: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80003AB0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80003AB4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80003AB8: jal         0x800BCFCC
    // 0x80003ABC: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_55;
    // 0x80003ABC: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_55:
    // 0x80003AC0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80003AC4: jal         0x800BC980
    // 0x80003AC8: nop

    SysMem_Free(rdram, ctx);
        goto after_56;
    // 0x80003AC8: nop

    after_56:
    // 0x80003ACC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80003AD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80003AD4: lui         $t4, 0x4000
    ctx->r12 = S32(0X4000 << 16);
    // 0x80003AD8: ori         $t4, $t4, 0x4C
    ctx->r12 = ctx->r12 | 0X4C;
    // 0x80003ADC: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x80003AE0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80003AE4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80003AE8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80003AEC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80003AF0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80003AF4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80003AF8: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80003AFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80003B00: jal         0x800A66EC
    // 0x80003B04: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_800A66EC(rdram, ctx);
        goto after_57;
    // 0x80003B04: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_57:
    // 0x80003B08: jal         0x8002856C
    // 0x80003B0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002856C(rdram, ctx);
        goto after_58;
    // 0x80003B0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_58:
    // 0x80003B10: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80003B14: lh          $a0, 0x72D4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X72D4);
    // 0x80003B18: jal         0x8002F5C4
    // 0x80003B1C: nop

    func_8002F5C4(rdram, ctx);
        goto after_59;
    // 0x80003B1C: nop

    after_59:
    // 0x80003B20: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80003B24: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80003B28: lhu         $t1, 0x0($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X0);
    // 0x80003B2C: nop

    // 0x80003B30: andi        $t0, $t1, 0x80
    ctx->r8 = ctx->r9 & 0X80;
    // 0x80003B34: bne         $t0, $zero, L_80003B90
    if (ctx->r8 != 0) {
        // 0x80003B38: nop

            goto L_80003B90;
    }
    // 0x80003B38: nop

    // 0x80003B3C: jal         0x80015E50
    // 0x80003B40: nop

    func_80015E50(rdram, ctx);
        goto after_60;
    // 0x80003B40: nop

    after_60:
    // 0x80003B44: jal         0x80015E94
    // 0x80003B48: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80015E94(rdram, ctx);
        goto after_61;
    // 0x80003B48: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_61:
    // 0x80003B4C: jal         0x80015E94
    // 0x80003B50: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80015E94(rdram, ctx);
        goto after_62;
    // 0x80003B50: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_62:
    // 0x80003B54: jal         0x80015E94
    // 0x80003B58: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80015E94(rdram, ctx);
        goto after_63;
    // 0x80003B58: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_63:
    // 0x80003B5C: jal         0x80015E94
    // 0x80003B60: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80015E94(rdram, ctx);
        goto after_64;
    // 0x80003B60: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_64:
    // 0x80003B64: jal         0x80015E94
    // 0x80003B68: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_80015E94(rdram, ctx);
        goto after_65;
    // 0x80003B68: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_65:
    // 0x80003B6C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003B70: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80003B74: lhu         $t5, 0x0($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X0);
    // 0x80003B78: nop

    // 0x80003B7C: andi        $t2, $t5, 0x200
    ctx->r10 = ctx->r13 & 0X200;
    // 0x80003B80: beq         $t2, $zero, L_80003B90
    if (ctx->r10 == 0) {
        // 0x80003B84: nop

            goto L_80003B90;
    }
    // 0x80003B84: nop

    // 0x80003B88: jal         0x800161E0
    // 0x80003B8C: nop

    func_800161E0(rdram, ctx);
        goto after_66;
    // 0x80003B8C: nop

    after_66:
L_80003B90:
    // 0x80003B90: jal         0x80015FB4
    // 0x80003B94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80015FB4(rdram, ctx);
        goto after_67;
    // 0x80003B94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_67:
    // 0x80003B98: jal         0x80015E94
    // 0x80003B9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80015E94(rdram, ctx);
        goto after_68;
    // 0x80003B9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_68:
    // 0x80003BA0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80003BA4: lh          $t8, 0x721C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X721C);
    // 0x80003BA8: nop

    // 0x80003BAC: bne         $t8, $zero, L_80003BF8
    if (ctx->r24 != 0) {
        // 0x80003BB0: nop

            goto L_80003BF8;
    }
    // 0x80003BB0: nop

    // 0x80003BB4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80003BB8: lhu         $t4, 0x72D4($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X72D4);
    // 0x80003BBC: nop

    // 0x80003BC0: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x80003BC4: beq         $at, $zero, L_80003BF8
    if (ctx->r1 == 0) {
        // 0x80003BC8: nop

            goto L_80003BF8;
    }
    // 0x80003BC8: nop

    // 0x80003BCC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80003BD0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80003BD4: addu        $at, $at, $t4
    gpr jr_addend_80003BE0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80003BD8: lw          $t4, -0x2EA0($at)
    ctx->r12 = ADD32(ctx->r1, -0X2EA0);
    // 0x80003BDC: nop

    // 0x80003BE0: jr          $t4
    // 0x80003BE4: nop

    switch (jr_addend_80003BE0 >> 2) {
        case 0: goto L_80003BE8; break;
        case 1: goto L_80003BE8; break;
        case 2: goto L_80003BF0; break;
        case 3: goto L_80003BF0; break;
        case 4: goto L_80003BF0; break;
        default: switch_error(__func__, 0x80003BE0, 0x800ED160);
    }
    // 0x80003BE4: nop

L_80003BE8:
    // 0x80003BE8: jal         0x80004654
    // 0x80003BEC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80004654(rdram, ctx);
        goto after_69;
    // 0x80003BEC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_69:
L_80003BF0:
    // 0x80003BF0: b           L_80003BF8
    // 0x80003BF4: nop

        goto L_80003BF8;
    // 0x80003BF4: nop

L_80003BF8:
    // 0x80003BF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80003BFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80003C00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80003C04: sh          $zero, 0x6C0($at)
    MEM_H(0X6C0, ctx->r1) = 0;
    // 0x80003C08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80003C0C: swc1        $f10, 0xEF0($at)
    MEM_W(0XEF0, ctx->r1) = ctx->f10.u32l;
    // 0x80003C10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80003C14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80003C18: sw          $t6, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = ctx->r14;
    // 0x80003C1C: jal         0x8005E19C
    // 0x80003C20: nop

    func_8005E19C(rdram, ctx);
        goto after_70;
    // 0x80003C20: nop

    after_70:
    // 0x80003C24: jal         0x8005D800
    // 0x80003C28: nop

    func_8005D800(rdram, ctx);
        goto after_71;
    // 0x80003C28: nop

    after_71:
    // 0x80003C2C: jal         0x8005E474
    // 0x80003C30: nop

    func_8005E474(rdram, ctx);
        goto after_72;
    // 0x80003C30: nop

    after_72:
    // 0x80003C34: jal         0x800821A0
    // 0x80003C38: nop

    func_800821A0(rdram, ctx);
        goto after_73;
    // 0x80003C38: nop

    after_73:
    // 0x80003C3C: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80003C40: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80003C44: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x80003C48: nop

    // 0x80003C4C: beq         $t3, $at, L_80003CC8
    if (ctx->r11 == ctx->r1) {
        // 0x80003C50: nop

            goto L_80003CC8;
    }
    // 0x80003C50: nop

L_80003C54:
    // 0x80003C54: lw          $t1, 0xF4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF4);
    // 0x80003C58: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80003C5C: lhu         $t0, 0x0($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X0);
    // 0x80003C60: nop

    // 0x80003C64: bne         $t0, $at, L_80003C98
    if (ctx->r8 != ctx->r1) {
        // 0x80003C68: nop

            goto L_80003C98;
    }
    // 0x80003C68: nop

    // 0x80003C6C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003C70: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x80003C74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80003C78: bne         $t7, $at, L_80003C98
    if (ctx->r15 != ctx->r1) {
        // 0x80003C7C: nop

            goto L_80003C98;
    }
    // 0x80003C7C: nop

    // 0x80003C80: lw          $t5, 0xF4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF4);
    // 0x80003C84: nop

    // 0x80003C88: addiu       $t2, $t5, 0x2
    ctx->r10 = ADD32(ctx->r13, 0X2);
    // 0x80003C8C: sw          $t2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r10;
    // 0x80003C90: b           L_80003CB0
    // 0x80003C94: nop

        goto L_80003CB0;
    // 0x80003C94: nop

L_80003C98:
    // 0x80003C98: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x80003C9C: nop

    // 0x80003CA0: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x80003CA4: addiu       $t4, $t8, 0x2
    ctx->r12 = ADD32(ctx->r24, 0X2);
    // 0x80003CA8: jal         0x80004654
    // 0x80003CAC: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    func_80004654(rdram, ctx);
        goto after_74;
    // 0x80003CAC: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    after_74:
L_80003CB0:
    // 0x80003CB0: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x80003CB4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80003CB8: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x80003CBC: nop

    // 0x80003CC0: bne         $t9, $at, L_80003C54
    if (ctx->r25 != ctx->r1) {
        // 0x80003CC4: nop

            goto L_80003C54;
    }
    // 0x80003CC4: nop

L_80003CC8:
    // 0x80003CC8: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x80003CCC: nop

    // 0x80003CD0: addiu       $t1, $t3, 0x2
    ctx->r9 = ADD32(ctx->r11, 0X2);
    // 0x80003CD4: sw          $t1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r9;
    // 0x80003CD8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80003CDC: lh          $t0, 0x721C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X721C);
    // 0x80003CE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003CE4: bne         $t0, $at, L_80003DE4
    if (ctx->r8 != ctx->r1) {
        // 0x80003CE8: nop

            goto L_80003DE4;
    }
    // 0x80003CE8: nop

    // 0x80003CEC: b           L_80003CF4
    // 0x80003CF0: nop

        goto L_80003CF4;
    // 0x80003CF0: nop

L_80003CF4:
    // 0x80003CF4: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
    // 0x80003CF8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80003CFC: lhu         $t5, 0x0($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X0);
    // 0x80003D00: nop

    // 0x80003D04: beq         $t5, $at, L_80003D3C
    if (ctx->r13 == ctx->r1) {
        // 0x80003D08: nop

            goto L_80003D3C;
    }
    // 0x80003D08: nop

    // 0x80003D0C: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80003D10: nop

    // 0x80003D14: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x80003D18: jal         0x80043DC0
    // 0x80003D1C: nop

    func_80043DC0(rdram, ctx);
        goto after_75;
    // 0x80003D1C: nop

    after_75:
    // 0x80003D20: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80003D24: lw          $t8, 0x7238($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7238);
    // 0x80003D28: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80003D2C: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80003D30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003D34: b           L_80003DDC
    // 0x80003D38: sw          $t4, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r12;
        goto L_80003DDC;
    // 0x80003D38: sw          $t4, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = ctx->r12;
L_80003D3C:
    // 0x80003D3C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80003D40: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80003D44: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x80003D48: nop

    // 0x80003D4C: andi        $t3, $t9, 0x200
    ctx->r11 = ctx->r25 & 0X200;
    // 0x80003D50: bne         $t3, $zero, L_80003D68
    if (ctx->r11 != 0) {
        // 0x80003D54: nop

            goto L_80003D68;
    }
    // 0x80003D54: nop

    // 0x80003D58: jal         0x800AF060
    // 0x80003D5C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800AF060(rdram, ctx);
        goto after_76;
    // 0x80003D5C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_76:
    // 0x80003D60: b           L_80003DDC
    // 0x80003D64: nop

        goto L_80003DDC;
    // 0x80003D64: nop

L_80003D68:
    // 0x80003D68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003D6C: sh          $zero, 0x7228($at)
    MEM_H(0X7228, ctx->r1) = 0;
    // 0x80003D70: jal         0x800AF060
    // 0x80003D74: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_800AF060(rdram, ctx);
        goto after_77;
    // 0x80003D74: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_77:
    // 0x80003D78: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
L_80003D7C:
    // 0x80003D7C: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x80003D80: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003D84: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80003D88: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80003D8C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80003D90: lw          $t7, -0x73D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73D0);
    // 0x80003D94: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80003D98: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80003D9C: addu        $t5, $t0, $t7
    ctx->r13 = ADD32(ctx->r8, ctx->r15);
    // 0x80003DA0: lw          $t2, 0xC0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0XC0);
    // 0x80003DA4: nop

    // 0x80003DA8: ori         $t8, $t2, 0x200
    ctx->r24 = ctx->r10 | 0X200;
    // 0x80003DAC: sw          $t8, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r24;
    // 0x80003DB0: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x80003DB4: nop

    // 0x80003DB8: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80003DBC: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80003DC0: bne         $at, $zero, L_80003D7C
    if (ctx->r1 != 0) {
        // 0x80003DC4: sw          $t6, 0x100($sp)
        MEM_W(0X100, ctx->r29) = ctx->r14;
            goto L_80003D7C;
    }
    // 0x80003DC4: sw          $t6, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r14;
    // 0x80003DC8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80003DCC: lh          $t9, 0x721C($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X721C);
    // 0x80003DD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003DD4: addiu       $t3, $t9, 0x2
    ctx->r11 = ADD32(ctx->r25, 0X2);
    // 0x80003DD8: sh          $t3, 0x721C($at)
    MEM_H(0X721C, ctx->r1) = ctx->r11;
L_80003DDC:
    // 0x80003DDC: b           L_80003E9C
    // 0x80003DE0: nop

        goto L_80003E9C;
    // 0x80003DE0: nop

L_80003DE4:
    // 0x80003DE4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80003DE8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80003DEC: lhu         $t0, 0x0($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X0);
    // 0x80003DF0: nop

    // 0x80003DF4: andi        $t7, $t0, 0x80
    ctx->r15 = ctx->r8 & 0X80;
    // 0x80003DF8: bne         $t7, $zero, L_80003E10
    if (ctx->r15 != 0) {
        // 0x80003DFC: nop

            goto L_80003E10;
    }
    // 0x80003DFC: nop

    // 0x80003E00: jal         0x800AF060
    // 0x80003E04: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800AF060(rdram, ctx);
        goto after_78;
    // 0x80003E04: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_78:
    // 0x80003E08: b           L_80003E94
    // 0x80003E0C: nop

        goto L_80003E94;
    // 0x80003E0C: nop

L_80003E10:
    // 0x80003E10: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80003E14: lh          $t2, 0x721C($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X721C);
    // 0x80003E18: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80003E1C: bne         $t2, $at, L_80003E8C
    if (ctx->r10 != ctx->r1) {
        // 0x80003E20: nop

            goto L_80003E8C;
    }
    // 0x80003E20: nop

    // 0x80003E24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003E28: sh          $zero, 0x7228($at)
    MEM_H(0X7228, ctx->r1) = 0;
    // 0x80003E2C: jal         0x800AF060
    // 0x80003E30: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_800AF060(rdram, ctx);
        goto after_79;
    // 0x80003E30: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_79:
    // 0x80003E34: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
L_80003E38:
    // 0x80003E38: lw          $t8, 0x100($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X100);
    // 0x80003E3C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80003E40: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80003E44: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x80003E48: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80003E4C: lw          $t4, -0x73D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73D0);
    // 0x80003E50: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x80003E54: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80003E58: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x80003E5C: lw          $t9, 0xC0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC0);
    // 0x80003E60: nop

    // 0x80003E64: ori         $t3, $t9, 0x200
    ctx->r11 = ctx->r25 | 0X200;
    // 0x80003E68: sw          $t3, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r11;
    // 0x80003E6C: lw          $t1, 0x100($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X100);
    // 0x80003E70: nop

    // 0x80003E74: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80003E78: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80003E7C: bne         $at, $zero, L_80003E38
    if (ctx->r1 != 0) {
        // 0x80003E80: sw          $t0, 0x100($sp)
        MEM_W(0X100, ctx->r29) = ctx->r8;
            goto L_80003E38;
    }
    // 0x80003E80: sw          $t0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r8;
    // 0x80003E84: b           L_80003E94
    // 0x80003E88: nop

        goto L_80003E94;
    // 0x80003E88: nop

L_80003E8C:
    // 0x80003E8C: jal         0x800AF060
    // 0x80003E90: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800AF060(rdram, ctx);
        goto after_80;
    // 0x80003E90: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_80:
L_80003E94:
    // 0x80003E94: b           L_80003E9C
    // 0x80003E98: nop

        goto L_80003E9C;
    // 0x80003E98: nop

L_80003E9C:
    // 0x80003E9C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80003EA0: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80003EA4: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x80003EA8: nop

    // 0x80003EAC: andi        $t8, $t2, 0x2000
    ctx->r24 = ctx->r10 & 0X2000;
    // 0x80003EB0: bne         $t8, $zero, L_80003F30
    if (ctx->r24 != 0) {
        // 0x80003EB4: nop

            goto L_80003F30;
    }
    // 0x80003EB4: nop

    // 0x80003EB8: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80003EBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80003EC0: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80003EC4: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x80003EC8: swc1        $f16, 0x72C($t5)
    MEM_W(0X72C, ctx->r13) = ctx->f16.u32l;
    // 0x80003ECC: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80003ED0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80003ED4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80003ED8: addiu       $t4, $t4, 0x61D8
    ctx->r12 = ADD32(ctx->r12, 0X61D8);
    // 0x80003EDC: swc1        $f18, 0x734($t4)
    MEM_W(0X734, ctx->r12) = ctx->f18.u32l;
    // 0x80003EE0: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80003EE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80003EE8: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80003EEC: addiu       $t9, $t9, 0x61D8
    ctx->r25 = ADD32(ctx->r25, 0X61D8);
    // 0x80003EF0: swc1        $f4, 0x864($t9)
    MEM_W(0X864, ctx->r25) = ctx->f4.u32l;
    // 0x80003EF4: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80003EF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80003EFC: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x80003F00: addiu       $t3, $t3, 0x61D8
    ctx->r11 = ADD32(ctx->r11, 0X61D8);
    // 0x80003F04: swc1        $f6, 0x86C($t3)
    MEM_W(0X86C, ctx->r11) = ctx->f6.u32l;
    // 0x80003F08: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80003F0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80003F10: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80003F14: addiu       $t6, $t6, 0x61D8
    ctx->r14 = ADD32(ctx->r14, 0X61D8);
    // 0x80003F18: swc1        $f8, 0x5F4($t6)
    MEM_W(0X5F4, ctx->r14) = ctx->f8.u32l;
    // 0x80003F1C: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80003F20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80003F24: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80003F28: addiu       $t1, $t1, 0x61D8
    ctx->r9 = ADD32(ctx->r9, 0X61D8);
    // 0x80003F2C: swc1        $f10, 0x5FC($t1)
    MEM_W(0X5FC, ctx->r9) = ctx->f10.u32l;
L_80003F30:
    // 0x80003F30: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80003F34: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80003F38: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x80003F3C: nop

    // 0x80003F40: andi        $t2, $t7, 0x200
    ctx->r10 = ctx->r15 & 0X200;
    // 0x80003F44: beq         $t2, $zero, L_80003F98
    if (ctx->r10 == 0) {
        // 0x80003F48: nop

            goto L_80003F98;
    }
    // 0x80003F48: nop

    // 0x80003F4C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80003F50: lwc1        $f16, 0x61C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80003F54: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003F58: lwc1        $f18, 0x7230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80003F5C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80003F60: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80003F64: addiu       $t8, $t8, 0x61D8
    ctx->r24 = ADD32(ctx->r24, 0X61D8);
    // 0x80003F68: swc1        $f4, 0x72C($t8)
    MEM_W(0X72C, ctx->r24) = ctx->f4.u32l;
    // 0x80003F6C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80003F70: lwc1        $f6, 0x61C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x80003F74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80003F78: lwc1        $f8, 0x7230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7230);
    // 0x80003F7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80003F80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80003F84: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80003F88: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80003F8C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80003F90: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x80003F94: swc1        $f18, 0x734($t5)
    MEM_W(0X734, ctx->r13) = ctx->f18.u32l;
L_80003F98:
    // 0x80003F98: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80003F9C: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80003FA0: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x80003FA4: nop

    // 0x80003FA8: andi        $t3, $t9, 0x80
    ctx->r11 = ctx->r25 & 0X80;
    // 0x80003FAC: bne         $t3, $zero, L_80004078
    if (ctx->r11 != 0) {
        // 0x80003FB0: nop

            goto L_80004078;
    }
    // 0x80003FB0: nop

    // 0x80003FB4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80003FB8: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80003FBC: lhu         $t1, 0x2($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X2);
    // 0x80003FC0: nop

    // 0x80003FC4: andi        $t0, $t1, 0x1
    ctx->r8 = ctx->r9 & 0X1;
    // 0x80003FC8: beq         $t0, $zero, L_80003FE0
    if (ctx->r8 == 0) {
        // 0x80003FCC: nop

            goto L_80003FE0;
    }
    // 0x80003FCC: nop

    // 0x80003FD0: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80003FD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80003FD8: b           L_80004070
    // 0x80003FDC: sw          $t7, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r15;
        goto L_80004070;
    // 0x80003FDC: sw          $t7, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r15;
L_80003FE0:
    // 0x80003FE0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80003FE4: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80003FE8: lhu         $t8, 0x2($t2)
    ctx->r24 = MEM_HU(ctx->r10, 0X2);
    // 0x80003FEC: nop

    // 0x80003FF0: andi        $t5, $t8, 0x2
    ctx->r13 = ctx->r24 & 0X2;
    // 0x80003FF4: beq         $t5, $zero, L_8000400C
    if (ctx->r13 == 0) {
        // 0x80003FF8: nop

            goto L_8000400C;
    }
    // 0x80003FF8: nop

    // 0x80003FFC: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80004000: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004004: b           L_80004070
    // 0x80004008: sw          $t4, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r12;
        goto L_80004070;
    // 0x80004008: sw          $t4, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r12;
L_8000400C:
    // 0x8000400C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80004010: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80004014: lhu         $t3, 0x2($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X2);
    // 0x80004018: nop

    // 0x8000401C: andi        $t6, $t3, 0x4
    ctx->r14 = ctx->r11 & 0X4;
    // 0x80004020: beq         $t6, $zero, L_80004038
    if (ctx->r14 == 0) {
        // 0x80004024: nop

            goto L_80004038;
    }
    // 0x80004024: nop

    // 0x80004028: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x8000402C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004030: b           L_80004070
    // 0x80004034: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
        goto L_80004070;
    // 0x80004034: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
L_80004038:
    // 0x80004038: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000403C: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80004040: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x80004044: nop

    // 0x80004048: andi        $t2, $t7, 0x8
    ctx->r10 = ctx->r15 & 0X8;
    // 0x8000404C: beq         $t2, $zero, L_80004064
    if (ctx->r10 == 0) {
        // 0x80004050: nop

            goto L_80004064;
    }
    // 0x80004050: nop

    // 0x80004054: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80004058: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000405C: b           L_80004070
    // 0x80004060: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
        goto L_80004070;
    // 0x80004060: sw          $t8, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r24;
L_80004064:
    // 0x80004064: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80004068: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000406C: sw          $t5, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r13;
L_80004070:
    // 0x80004070: b           L_80004124
    // 0x80004074: nop

        goto L_80004124;
    // 0x80004074: nop

L_80004078:
    // 0x80004078: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000407C: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80004080: lhu         $t9, 0x2($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X2);
    // 0x80004084: nop

    // 0x80004088: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x8000408C: beq         $t3, $zero, L_800040A4
    if (ctx->r11 == 0) {
        // 0x80004090: nop

            goto L_800040A4;
    }
    // 0x80004090: nop

    // 0x80004094: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80004098: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000409C: b           L_80004124
    // 0x800040A0: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
        goto L_80004124;
    // 0x800040A0: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
L_800040A4:
    // 0x800040A4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800040A8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x800040AC: lhu         $t0, 0x2($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X2);
    // 0x800040B0: nop

    // 0x800040B4: andi        $t7, $t0, 0x2
    ctx->r15 = ctx->r8 & 0X2;
    // 0x800040B8: beq         $t7, $zero, L_800040D0
    if (ctx->r15 == 0) {
        // 0x800040BC: nop

            goto L_800040D0;
    }
    // 0x800040BC: nop

    // 0x800040C0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800040C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800040C8: b           L_80004124
    // 0x800040CC: sw          $t2, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r10;
        goto L_80004124;
    // 0x800040CC: sw          $t2, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r10;
L_800040D0:
    // 0x800040D0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800040D4: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800040D8: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x800040DC: nop

    // 0x800040E0: andi        $t4, $t5, 0x4
    ctx->r12 = ctx->r13 & 0X4;
    // 0x800040E4: beq         $t4, $zero, L_800040FC
    if (ctx->r12 == 0) {
        // 0x800040E8: nop

            goto L_800040FC;
    }
    // 0x800040E8: nop

    // 0x800040EC: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x800040F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800040F4: b           L_80004124
    // 0x800040F8: sw          $t9, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r25;
        goto L_80004124;
    // 0x800040F8: sw          $t9, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r25;
L_800040FC:
    // 0x800040FC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80004100: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80004104: lhu         $t6, 0x2($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X2);
    // 0x80004108: nop

    // 0x8000410C: andi        $t1, $t6, 0x8
    ctx->r9 = ctx->r14 & 0X8;
    // 0x80004110: beq         $t1, $zero, L_80004124
    if (ctx->r9 == 0) {
        // 0x80004114: nop

            goto L_80004124;
    }
    // 0x80004114: nop

    // 0x80004118: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8000411C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004120: sw          $t0, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r8;
L_80004124:
    // 0x80004124: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80004128: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000412C: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x80004130: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80004134: lw          $s0, -0x73CC($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X73CC);
    // 0x80004138: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8000413C: beq         $s0, $at, L_800042F8
    if (ctx->r16 == ctx->r1) {
        // 0x80004140: nop

            goto L_800042F8;
    }
    // 0x80004140: nop

    // 0x80004144: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80004148: beq         $s0, $at, L_80004294
    if (ctx->r16 == ctx->r1) {
        // 0x8000414C: nop

            goto L_80004294;
    }
    // 0x8000414C: nop

    // 0x80004150: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80004154: beq         $s0, $at, L_80004164
    if (ctx->r16 == ctx->r1) {
        // 0x80004158: nop

            goto L_80004164;
    }
    // 0x80004158: nop

    // 0x8000415C: b           L_8000438C
    // 0x80004160: nop

        goto L_8000438C;
    // 0x80004160: nop

L_80004164:
    // 0x80004164: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004168: lwc1        $f4, -0x4508($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x8000416C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80004170: nop

    // 0x80004174: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80004178: nop

    // 0x8000417C: bc1f        L_80004198
    if (!c1cs) {
        // 0x80004180: nop

            goto L_80004198;
    }
    // 0x80004180: nop

    // 0x80004184: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80004188: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000418C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004190: b           L_800041F4
    // 0x80004194: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
        goto L_800041F4;
    // 0x80004194: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
L_80004198:
    // 0x80004198: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000419C: lwc1        $f10, -0x4508($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x800041A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800041A4: nop

    // 0x800041A8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800041AC: nop

    // 0x800041B0: bc1f        L_800041F4
    if (!c1cs) {
        // 0x800041B4: nop

            goto L_800041F4;
    }
    // 0x800041B4: nop

    // 0x800041B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800041BC: lwc1        $f18, -0x4508($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x800041C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800041C4: nop

    // 0x800041C8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800041CC: nop

    // 0x800041D0: bc1f        L_800041E0
    if (!c1cs) {
        // 0x800041D4: nop

            goto L_800041E0;
    }
    // 0x800041D4: nop

    // 0x800041D8: b           L_800041F4
    // 0x800041DC: nop

        goto L_800041F4;
    // 0x800041DC: nop

L_800041E0:
    // 0x800041E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800041E4: lwc1        $f6, -0x4508($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4508);
    // 0x800041E8: nop

    // 0x800041EC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800041F0: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
L_800041F4:
    // 0x800041F4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800041F8: jal         0x80016620
    // 0x800041FC: addiu       $a0, $a0, -0x4508
    ctx->r4 = ADD32(ctx->r4, -0X4508);
    func_80016620(rdram, ctx);
        goto after_81;
    // 0x800041FC: addiu       $a0, $a0, -0x4508
    ctx->r4 = ADD32(ctx->r4, -0X4508);
    after_81:
    // 0x80004200: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80004204: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80004208: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000420C: swc1        $f10, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f10.u32l;
    // 0x80004210: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004214: sw          $zero, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = 0;
    // 0x80004218: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000421C: sw          $zero, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = 0;
    // 0x80004220: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004224: sw          $zero, -0x44FC($at)
    MEM_W(-0X44FC, ctx->r1) = 0;
    // 0x80004228: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x8000422C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004230: sw          $t2, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r10;
    // 0x80004234: addiu       $t8, $zero, 0xA8
    ctx->r24 = ADD32(0, 0XA8);
    // 0x80004238: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000423C: sw          $t8, -0x44F4($at)
    MEM_W(-0X44F4, ctx->r1) = ctx->r24;
    // 0x80004240: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80004244: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004248: swc1        $f16, -0x44F0($at)
    MEM_W(-0X44F0, ctx->r1) = ctx->f16.u32l;
    // 0x8000424C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80004250: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80004254: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004258: swc1        $f18, -0x44EC($at)
    MEM_W(-0X44EC, ctx->r1) = ctx->f18.u32l;
    // 0x8000425C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80004260: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004264: swc1        $f4, -0x44E8($at)
    MEM_W(-0X44E8, ctx->r1) = ctx->f4.u32l;
    // 0x80004268: addiu       $t5, $zero, 0x3E8
    ctx->r13 = ADD32(0, 0X3E8);
    // 0x8000426C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004270: sw          $t5, -0x44E4($at)
    MEM_W(-0X44E4, ctx->r1) = ctx->r13;
    // 0x80004274: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80004278: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000427C: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x80004280: nop

    // 0x80004284: ori         $t3, $t9, 0x400
    ctx->r11 = ctx->r25 | 0X400;
    // 0x80004288: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8000428C: b           L_800043AC
    // 0x80004290: nop

        goto L_800043AC;
    // 0x80004290: nop

L_80004294:
    // 0x80004294: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80004298: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x8000429C: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x800042A0: nop

    // 0x800042A4: andi        $t0, $t1, 0x80
    ctx->r8 = ctx->r9 & 0X80;
    // 0x800042A8: bne         $t0, $zero, L_800042C0
    if (ctx->r8 != 0) {
        // 0x800042AC: nop

            goto L_800042C0;
    }
    // 0x800042AC: nop

    // 0x800042B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800042B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800042B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800042BC: swc1        $f6, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f6.u32l;
L_800042C0:
    // 0x800042C0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800042C4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800042C8: lw          $a1, -0x44D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X44D4);
    // 0x800042CC: lw          $a0, 0x18E4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18E4);
    // 0x800042D0: jal         0x80017B80
    // 0x800042D4: nop

    func_80017B80(rdram, ctx);
        goto after_82;
    // 0x800042D4: nop

    after_82:
    // 0x800042D8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x800042DC: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x800042E0: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x800042E4: nop

    // 0x800042E8: ori         $t8, $t2, 0x400
    ctx->r24 = ctx->r10 | 0X400;
    // 0x800042EC: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x800042F0: b           L_800043AC
    // 0x800042F4: nop

        goto L_800043AC;
    // 0x800042F4: nop

L_800042F8:
    // 0x800042F8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800042FC: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80004300: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x80004304: nop

    // 0x80004308: andi        $t3, $t9, 0x80
    ctx->r11 = ctx->r25 & 0X80;
    // 0x8000430C: bne         $t3, $zero, L_80004344
    if (ctx->r11 != 0) {
        // 0x80004310: nop

            goto L_80004344;
    }
    // 0x80004310: nop

    // 0x80004314: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80004318: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000431C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004320: swc1        $f8, -0x44CC($at)
    MEM_W(-0X44CC, ctx->r1) = ctx->f8.u32l;
    // 0x80004324: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80004328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000432C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004330: swc1        $f10, -0x44C4($at)
    MEM_W(-0X44C4, ctx->r1) = ctx->f10.u32l;
    // 0x80004334: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80004338: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000433C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004340: swc1        $f16, -0x44D4($at)
    MEM_W(-0X44D4, ctx->r1) = ctx->f16.u32l;
L_80004344:
    // 0x80004344: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80004348: lwc1        $f18, -0x44D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X44D4);
    // 0x8000434C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80004350: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x80004354: lw          $a3, -0x44C4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X44C4);
    // 0x80004358: lw          $a2, -0x44CC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X44CC);
    // 0x8000435C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80004360: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80004364: jal         0x8001A040
    // 0x80004368: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_8001A040(rdram, ctx);
        goto after_83;
    // 0x80004368: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_83:
    // 0x8000436C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80004370: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80004374: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x80004378: nop

    // 0x8000437C: ori         $t1, $t6, 0x400
    ctx->r9 = ctx->r14 | 0X400;
    // 0x80004380: sh          $t1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r9;
    // 0x80004384: b           L_800043AC
    // 0x80004388: nop

        goto L_800043AC;
    // 0x80004388: nop

L_8000438C:
    // 0x8000438C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80004390: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80004394: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x80004398: nop

    // 0x8000439C: ori         $t8, $t2, 0x400
    ctx->r24 = ctx->r10 | 0X400;
    // 0x800043A0: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x800043A4: b           L_800043AC
    // 0x800043A8: nop

        goto L_800043AC;
    // 0x800043A8: nop

L_800043AC:
    // 0x800043AC: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800043B0: lh          $t7, 0x7234($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7234);
    // 0x800043B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800043B8: sh          $t7, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r15;
    // 0x800043BC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x800043C0: lh          $t5, 0x723C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X723C);
    // 0x800043C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800043C8: sh          $t5, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r13;
    // 0x800043CC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800043D0: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x800043D4: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x800043D8: addiu       $at, $zero, -0x93
    ctx->r1 = ADD32(0, -0X93);
    // 0x800043DC: and         $t6, $t3, $at
    ctx->r14 = ctx->r11 & ctx->r1;
    // 0x800043E0: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x800043E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800043E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800043EC: sw          $t1, 0x6C4($at)
    MEM_W(0X6C4, ctx->r1) = ctx->r9;
    // 0x800043F0: b           L_80004400
    // 0x800043F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80004400;
    // 0x800043F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800043F8: b           L_80004400
    // 0x800043FC: nop

        goto L_80004400;
    // 0x800043FC: nop

L_80004400:
    // 0x80004400: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80004404: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80004408: jr          $ra
    // 0x8000440C: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x8000440C: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_80004410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004410: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80004414: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80004418: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8000441C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80004420: lw          $t6, 0x1148($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1148);
    // 0x80004424: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80004428: blez        $t6, L_800044A4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000442C: nop

            goto L_800044A4;
    }
    // 0x8000442C: nop

L_80004430:
    // 0x80004430: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80004434: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80004438: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8000443C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80004440: lw          $t9, 0x114C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X114C);
    // 0x80004444: nop

    // 0x80004448: bne         $t9, $a0, L_80004488
    if (ctx->r25 != ctx->r4) {
        // 0x8000444C: nop

            goto L_80004488;
    }
    // 0x8000444C: nop

    // 0x80004450: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80004454: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80004458: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8000445C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80004460: lw          $t2, 0x1150($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1150);
    // 0x80004464: nop

    // 0x80004468: bne         $t2, $a1, L_80004488
    if (ctx->r10 != ctx->r5) {
        // 0x8000446C: nop

            goto L_80004488;
    }
    // 0x8000446C: nop

    // 0x80004470: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80004474: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80004478: addiu       $t5, $t5, 0x114C
    ctx->r13 = ADD32(ctx->r13, 0X114C);
    // 0x8000447C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80004480: b           L_800044B4
    // 0x80004484: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
        goto L_800044B4;
    // 0x80004484: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_80004488:
    // 0x80004488: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8000448C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80004490: lw          $t8, 0x1148($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1148);
    // 0x80004494: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80004498: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000449C: bne         $at, $zero, L_80004430
    if (ctx->r1 != 0) {
        // 0x800044A0: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_80004430;
    }
    // 0x800044A0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
L_800044A4:
    // 0x800044A4: b           L_800044B4
    // 0x800044A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800044B4;
    // 0x800044A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800044AC: b           L_800044B4
    // 0x800044B0: nop

        goto L_800044B4;
    // 0x800044B0: nop

L_800044B4:
    // 0x800044B4: jr          $ra
    // 0x800044B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800044B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800044BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800044BC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800044C0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800044C4:
    // 0x800044C4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800044C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800044CC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800044D0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800044D4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800044D8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800044DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800044E0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800044E4: sw          $zero, 0x6DC0($at)
    MEM_W(0X6DC0, ctx->r1) = 0;
    // 0x800044E8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800044EC: nop

    // 0x800044F0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800044F4: slti        $at, $t9, 0x20
    ctx->r1 = SIGNED(ctx->r25) < 0X20 ? 1 : 0;
    // 0x800044F8: bne         $at, $zero, L_800044C4
    if (ctx->r1 != 0) {
        // 0x800044FC: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_800044C4;
    }
    // 0x800044FC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80004500: b           L_80004508
    // 0x80004504: nop

        goto L_80004508;
    // 0x80004504: nop

L_80004508:
    // 0x80004508: jr          $ra
    // 0x8000450C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000450C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80004510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004510: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80004514: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x80004518: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8000451C:
    // 0x8000451C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80004520: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80004524: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80004528: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000452C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004530: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80004534: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004538: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000453C: lw          $t8, 0x6DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6DC0);
    // 0x80004540: nop

    // 0x80004544: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80004548: bne         $t9, $zero, L_80004584
    if (ctx->r25 != 0) {
        // 0x8000454C: nop

            goto L_80004584;
    }
    // 0x8000454C: nop

    // 0x80004550: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80004554: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80004558: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8000455C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80004560: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80004564: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80004568: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8000456C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80004570: sw          $zero, 0x6DC0($at)
    MEM_W(0X6DC0, ctx->r1) = 0;
    // 0x80004574: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80004578: nop

    // 0x8000457C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80004580: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
L_80004584:
    // 0x80004584: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80004588: nop

    // 0x8000458C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80004590: slti        $at, $t5, 0x20
    ctx->r1 = SIGNED(ctx->r13) < 0X20 ? 1 : 0;
    // 0x80004594: bne         $at, $zero, L_8000451C
    if (ctx->r1 != 0) {
        // 0x80004598: sw          $t5, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r13;
            goto L_8000451C;
    }
    // 0x80004598: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x8000459C: b           L_800045A4
    // 0x800045A0: nop

        goto L_800045A4;
    // 0x800045A0: nop

L_800045A4:
    // 0x800045A4: jr          $ra
    // 0x800045A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800045A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800045AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800045AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800045B0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800045B4:
    // 0x800045B4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800045B8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x800045BC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800045C0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800045C4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800045C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800045CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800045D0: addiu       $t8, $t8, 0x6C20
    ctx->r24 = ADD32(ctx->r24, 0X6C20);
    // 0x800045D4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800045D8: lw          $t0, 0x1A0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1A0);
    // 0x800045DC: nop

    // 0x800045E0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800045E4: beq         $t1, $zero, L_80004624
    if (ctx->r9 == 0) {
        // 0x800045E8: nop

            goto L_80004624;
    }
    // 0x800045E8: nop

    // 0x800045EC: lw          $t2, 0x1A4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1A4);
    // 0x800045F0: nop

    // 0x800045F4: bne         $t2, $a0, L_80004624
    if (ctx->r10 != ctx->r4) {
        // 0x800045F8: nop

            goto L_80004624;
    }
    // 0x800045F8: nop

    // 0x800045FC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80004600: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80004604: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80004608: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8000460C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80004610: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80004614: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80004618: addiu       $t5, $t5, 0x6C20
    ctx->r13 = ADD32(ctx->r13, 0X6C20);
    // 0x8000461C: b           L_8000464C
    // 0x80004620: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
        goto L_8000464C;
    // 0x80004620: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_80004624:
    // 0x80004624: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80004628: nop

    // 0x8000462C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80004630: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x80004634: bne         $at, $zero, L_800045B4
    if (ctx->r1 != 0) {
        // 0x80004638: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800045B4;
    }
    // 0x80004638: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8000463C: b           L_8000464C
    // 0x80004640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000464C;
    // 0x80004640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004644: b           L_8000464C
    // 0x80004648: nop

        goto L_8000464C;
    // 0x80004648: nop

L_8000464C:
    // 0x8000464C: jr          $ra
    // 0x80004650: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80004650: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80004654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004654: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000465C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80004660: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_80004664:
    // 0x80004664: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80004668: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000466C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80004670: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80004674: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004678: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000467C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004680: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80004684: lw          $t8, 0x6DC0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6DC0);
    // 0x80004688: nop

    // 0x8000468C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80004690: bne         $t9, $zero, L_800046AC
    if (ctx->r25 != 0) {
        // 0x80004694: nop

            goto L_800046AC;
    }
    // 0x80004694: nop

    // 0x80004698: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x8000469C: bne         $t0, $zero, L_800046AC
    if (ctx->r8 != 0) {
        // 0x800046A0: nop

            goto L_800046AC;
    }
    // 0x800046A0: nop

    // 0x800046A4: b           L_800046C4
    // 0x800046A8: nop

        goto L_800046C4;
    // 0x800046A8: nop

L_800046AC:
    // 0x800046AC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800046B0: nop

    // 0x800046B4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800046B8: slti        $at, $t2, 0x20
    ctx->r1 = SIGNED(ctx->r10) < 0X20 ? 1 : 0;
    // 0x800046BC: bne         $at, $zero, L_80004664
    if (ctx->r1 != 0) {
        // 0x800046C0: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_80004664;
    }
    // 0x800046C0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_800046C4:
    // 0x800046C4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800046C8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800046CC: bne         $t3, $at, L_800046DC
    if (ctx->r11 != ctx->r1) {
        // 0x800046D0: nop

            goto L_800046DC;
    }
    // 0x800046D0: nop

    // 0x800046D4: b           L_800047B8
    // 0x800046D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800047B8;
    // 0x800046D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800046DC:
    // 0x800046DC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800046E0: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x800046E4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800046E8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800046EC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800046F0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800046F4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800046F8: addiu       $t6, $t6, 0x6C20
    ctx->r14 = ADD32(ctx->r14, 0X6C20);
    // 0x800046FC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80004700: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80004704: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80004708: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000470C: sw          $t9, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = ctx->r25;
    // 0x80004710: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80004714: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80004718: nop

    // 0x8000471C: sw          $t0, 0x1A4($t1)
    MEM_W(0X1A4, ctx->r9) = ctx->r8;
    // 0x80004720: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80004724: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80004728: lw          $t3, 0x1A4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A4);
    // 0x8000472C: nop

    // 0x80004730: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80004734: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80004738: lw          $t5, -0x2490($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2490);
    // 0x8000473C: nop

    // 0x80004740: bne         $t5, $zero, L_8000475C
    if (ctx->r13 != 0) {
        // 0x80004744: nop

            goto L_8000475C;
    }
    // 0x80004744: nop

    // 0x80004748: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000474C: nop

    // 0x80004750: sw          $zero, 0x1A0($t6)
    MEM_W(0X1A0, ctx->r14) = 0;
    // 0x80004754: b           L_800047B8
    // 0x80004758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800047B8;
    // 0x80004758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000475C:
    // 0x8000475C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80004760: nop

    // 0x80004764: lw          $t9, 0x1A4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1A4);
    // 0x80004768: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8000476C: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x80004770: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80004774: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80004778: lw          $t9, -0x2490($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2490);
    // 0x8000477C: nop

    // 0x80004780: jalr        $t9
    // 0x80004784: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80004784: nop

    after_0:
    // 0x80004788: bgez        $v0, L_8000479C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000478C: nop

            goto L_8000479C;
    }
    // 0x8000478C: nop

    // 0x80004790: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80004794: nop

    // 0x80004798: sw          $zero, 0x1A0($t0)
    MEM_W(0X1A0, ctx->r8) = 0;
L_8000479C:
    // 0x8000479C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800047A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800047A4: sw          $t1, 0x6C10($at)
    MEM_W(0X6C10, ctx->r1) = ctx->r9;
    // 0x800047A8: b           L_800047B8
    // 0x800047AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800047B8;
    // 0x800047AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800047B0: b           L_800047B8
    // 0x800047B4: nop

        goto L_800047B8;
    // 0x800047B4: nop

L_800047B8:
    // 0x800047B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800047BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800047C0: jr          $ra
    // 0x800047C4: nop

    return;
    // 0x800047C4: nop

;}
RECOMP_FUNC void func_800047C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800047C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800047CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800047D0: nop

    // 0x800047D4: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800047D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800047DC: nop

    // 0x800047E0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800047E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800047E8: nop

    // 0x800047EC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800047F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800047F4: nop

    // 0x800047F8: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x800047FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80004800: nop

    // 0x80004804: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80004808: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000480C: nop

    // 0x80004810: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80004814: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80004818: sh          $t6, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r14;
    // 0x8000481C: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x80004820: sh          $zero, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = 0;
    // 0x80004824: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80004828: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x8000482C: nop

    // 0x80004830: lw          $t8, 0x144($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X144);
    // 0x80004834: nop

    // 0x80004838: bne         $t8, $zero, L_80004848
    if (ctx->r24 != 0) {
        // 0x8000483C: sw          $t8, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r24;
            goto L_80004848;
    }
    // 0x8000483C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80004840: b           L_80004AD4
    // 0x80004844: nop

        goto L_80004AD4;
    // 0x80004844: nop

L_80004848:
    // 0x80004848: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8000484C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004850: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80004854: nop

    // 0x80004858: bne         $t0, $at, L_80004878
    if (ctx->r8 != ctx->r1) {
        // 0x8000485C: nop

            goto L_80004878;
    }
    // 0x8000485C: nop

    // 0x80004860: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x80004864: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004868: bne         $t1, $at, L_80004878
    if (ctx->r9 != ctx->r1) {
        // 0x8000486C: nop

            goto L_80004878;
    }
    // 0x8000486C: nop

    // 0x80004870: b           L_80004ACC
    // 0x80004874: nop

        goto L_80004ACC;
    // 0x80004874: nop

L_80004878:
    // 0x80004878: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8000487C: addiu       $t4, $sp, 0x4
    ctx->r12 = ADD32(ctx->r29, 0X4);
    // 0x80004880: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80004884: nop

    // 0x80004888: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8000488C: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80004890: nop

    // 0x80004894: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80004898: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8000489C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800048A0: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x800048A4: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800048A8: nop

    // 0x800048AC: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
    // 0x800048B0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800048B4: nop

    // 0x800048B8: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x800048BC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800048C0: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800048C4: addiu       $t4, $sp, 0x4
    ctx->r12 = ADD32(ctx->r29, 0X4);
    // 0x800048C8: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800048CC: nop

    // 0x800048D0: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x800048D4: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800048D8: nop

    // 0x800048DC: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x800048E0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800048E4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800048E8: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x800048EC: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800048F0: nop

    // 0x800048F4: sh          $t8, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r24;
    // 0x800048F8: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800048FC: nop

    // 0x80004900: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x80004904: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80004908: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8000490C: addiu       $t4, $sp, 0xC
    ctx->r12 = ADD32(ctx->r29, 0XC);
    // 0x80004910: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80004914: nop

    // 0x80004918: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8000491C: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80004920: nop

    // 0x80004924: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80004928: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8000492C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80004930: addiu       $t0, $sp, 0xC
    ctx->r8 = ADD32(ctx->r29, 0XC);
    // 0x80004934: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80004938: nop

    // 0x8000493C: sh          $t8, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r24;
    // 0x80004940: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80004944: nop

    // 0x80004948: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x8000494C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80004950: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80004954: addiu       $t4, $sp, 0xC
    ctx->r12 = ADD32(ctx->r29, 0XC);
    // 0x80004958: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8000495C: nop

    // 0x80004960: sh          $t3, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r11;
    // 0x80004964: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80004968: nop

    // 0x8000496C: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80004970: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80004974: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80004978: addiu       $t0, $sp, 0xC
    ctx->r8 = ADD32(ctx->r29, 0XC);
    // 0x8000497C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80004980: nop

    // 0x80004984: sh          $t8, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r24;
    // 0x80004988: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8000498C: nop

    // 0x80004990: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x80004994: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80004998: addiu       $t2, $sp, 0xC
    ctx->r10 = ADD32(ctx->r29, 0XC);
    // 0x8000499C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800049A0: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800049A4: andi        $t4, $t3, 0x7F00
    ctx->r12 = ctx->r11 & 0X7F00;
    // 0x800049A8: bne         $t4, $at, L_80004AC4
    if (ctx->r12 != ctx->r1) {
        // 0x800049AC: nop

            goto L_80004AC4;
    }
    // 0x800049AC: nop

    // 0x800049B0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x800049B4: lh          $t7, 0x7268($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7268);
    // 0x800049B8: sra         $t5, $t3, 2
    ctx->r13 = S32(SIGNED(ctx->r11) >> 2);
    // 0x800049BC: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x800049C0: bne         $t6, $t7, L_80004AC4
    if (ctx->r14 != ctx->r15) {
        // 0x800049C4: nop

            goto L_80004AC4;
    }
    // 0x800049C4: nop

    // 0x800049C8: addiu       $t8, $sp, 0x4
    ctx->r24 = ADD32(ctx->r29, 0X4);
    // 0x800049CC: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x800049D0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800049D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800049D8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x800049DC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800049E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800049E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800049E8: nop

    // 0x800049EC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800049F0: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800049F4: addiu       $t2, $sp, 0x4
    ctx->r10 = ADD32(ctx->r29, 0X4);
    // 0x800049F8: lh          $t4, 0x2($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X2);
    // 0x800049FC: nop

    // 0x80004A00: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80004A04: nop

    // 0x80004A08: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004A0C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80004A10: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x80004A14: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x80004A18: nop

    // 0x80004A1C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80004A20: nop

    // 0x80004A24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004A28: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80004A2C: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80004A30: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80004A34: nop

    // 0x80004A38: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80004A3C: nop

    // 0x80004A40: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80004A44: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x80004A48: addiu       $t8, $sp, 0x4
    ctx->r24 = ADD32(ctx->r29, 0X4);
    // 0x80004A4C: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x80004A50: nop

    // 0x80004A54: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80004A58: nop

    // 0x80004A5C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004A60: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80004A64: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    // 0x80004A68: lh          $t1, 0x6($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X6);
    // 0x80004A6C: nop

    // 0x80004A70: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80004A74: nop

    // 0x80004A78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004A7C: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80004A80: addiu       $t2, $sp, 0xC
    ctx->r10 = ADD32(ctx->r29, 0XC);
    // 0x80004A84: lhu         $t4, 0x2($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X2);
    // 0x80004A88: nop

    // 0x80004A8C: sh          $t4, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r12;
    // 0x80004A90: addiu       $t3, $sp, 0xC
    ctx->r11 = ADD32(ctx->r29, 0XC);
    // 0x80004A94: lhu         $t5, 0x4($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X4);
    // 0x80004A98: nop

    // 0x80004A9C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80004AA0: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x80004AA4: addiu       $t7, $sp, 0xC
    ctx->r15 = ADD32(ctx->r29, 0XC);
    // 0x80004AA8: lhu         $t8, 0x4($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X4);
    // 0x80004AAC: nop

    // 0x80004AB0: sra         $t0, $t8, 8
    ctx->r8 = S32(SIGNED(ctx->r24) >> 8);
    // 0x80004AB4: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x80004AB8: sh          $t9, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r25;
    // 0x80004ABC: b           L_80004ACC
    // 0x80004AC0: nop

        goto L_80004ACC;
    // 0x80004AC0: nop

L_80004AC4:
    // 0x80004AC4: b           L_80004848
    // 0x80004AC8: nop

        goto L_80004848;
    // 0x80004AC8: nop

L_80004ACC:
    // 0x80004ACC: b           L_80004AD4
    // 0x80004AD0: nop

        goto L_80004AD4;
    // 0x80004AD0: nop

L_80004AD4:
    // 0x80004AD4: jr          $ra
    // 0x80004AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004AE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80004AE4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004AE8: swc1        $f4, -0x71C8($at)
    MEM_W(-0X71C8, ctx->r1) = ctx->f4.u32l;
    // 0x80004AEC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80004AF0: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80004AF4: nop

    // 0x80004AF8: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x80004AFC: nop

    // 0x80004B00: bne         $t7, $zero, L_80004B10
    if (ctx->r15 != 0) {
        // 0x80004B04: sw          $t7, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r15;
            goto L_80004B10;
    }
    // 0x80004B04: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80004B08: b           L_80004CCC
    // 0x80004B0C: nop

        goto L_80004CCC;
    // 0x80004B0C: nop

L_80004B10:
    // 0x80004B10: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004B14: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004B18: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80004B1C: nop

    // 0x80004B20: bne         $t9, $at, L_80004B40
    if (ctx->r25 != ctx->r1) {
        // 0x80004B24: nop

            goto L_80004B40;
    }
    // 0x80004B24: nop

    // 0x80004B28: lhu         $t0, 0x2($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X2);
    // 0x80004B2C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80004B30: bne         $t0, $at, L_80004B40
    if (ctx->r8 != ctx->r1) {
        // 0x80004B34: nop

            goto L_80004B40;
    }
    // 0x80004B34: nop

    // 0x80004B38: b           L_80004CBC
    // 0x80004B3C: nop

        goto L_80004CBC;
    // 0x80004B3C: nop

L_80004B40:
    // 0x80004B40: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80004B44: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x80004B48: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004B4C: nop

    // 0x80004B50: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x80004B54: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80004B58: nop

    // 0x80004B5C: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80004B60: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80004B64: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80004B68: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    // 0x80004B6C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004B70: nop

    // 0x80004B74: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x80004B78: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004B7C: nop

    // 0x80004B80: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x80004B84: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80004B88: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80004B8C: addiu       $t3, $sp, 0x4
    ctx->r11 = ADD32(ctx->r29, 0X4);
    // 0x80004B90: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004B94: nop

    // 0x80004B98: sh          $t2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r10;
    // 0x80004B9C: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80004BA0: nop

    // 0x80004BA4: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80004BA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80004BAC: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80004BB0: addiu       $t9, $sp, 0x4
    ctx->r25 = ADD32(ctx->r29, 0X4);
    // 0x80004BB4: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004BB8: nop

    // 0x80004BBC: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x80004BC0: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004BC4: nop

    // 0x80004BC8: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x80004BCC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80004BD0: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80004BD4: addiu       $t3, $sp, 0xC
    ctx->r11 = ADD32(ctx->r29, 0XC);
    // 0x80004BD8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004BDC: nop

    // 0x80004BE0: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x80004BE4: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80004BE8: nop

    // 0x80004BEC: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80004BF0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80004BF4: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80004BF8: addiu       $t9, $sp, 0xC
    ctx->r25 = ADD32(ctx->r29, 0XC);
    // 0x80004BFC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004C00: nop

    // 0x80004C04: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x80004C08: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004C0C: nop

    // 0x80004C10: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x80004C14: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80004C18: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x80004C1C: addiu       $t3, $sp, 0xC
    ctx->r11 = ADD32(ctx->r29, 0XC);
    // 0x80004C20: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004C24: nop

    // 0x80004C28: sh          $t2, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r10;
    // 0x80004C2C: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80004C30: nop

    // 0x80004C34: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80004C38: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80004C3C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80004C40: addiu       $t9, $sp, 0xC
    ctx->r25 = ADD32(ctx->r29, 0XC);
    // 0x80004C44: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004C48: nop

    // 0x80004C4C: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x80004C50: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80004C54: nop

    // 0x80004C58: addiu       $t0, $t8, 0x2
    ctx->r8 = ADD32(ctx->r24, 0X2);
    // 0x80004C5C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80004C60: addiu       $t1, $sp, 0xC
    ctx->r9 = ADD32(ctx->r29, 0XC);
    // 0x80004C64: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004C68: addiu       $at, $zero, 0x300
    ctx->r1 = ADD32(0, 0X300);
    // 0x80004C6C: andi        $t3, $t2, 0x7F00
    ctx->r11 = ctx->r10 & 0X7F00;
    // 0x80004C70: beq         $t3, $at, L_80004C80
    if (ctx->r11 == ctx->r1) {
        // 0x80004C74: nop

            goto L_80004C80;
    }
    // 0x80004C74: nop

    // 0x80004C78: b           L_80004CB4
    // 0x80004C7C: nop

        goto L_80004CB4;
    // 0x80004C7C: nop

L_80004C80:
    // 0x80004C80: addiu       $t4, $sp, 0x4
    ctx->r12 = ADD32(ctx->r29, 0X4);
    // 0x80004C84: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x80004C88: lh          $t6, 0x2($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X2);
    // 0x80004C8C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80004C90: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80004C94: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80004C98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80004C9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80004CA0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80004CA4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80004CA8: swc1        $f16, -0x71C8($at)
    MEM_W(-0X71C8, ctx->r1) = ctx->f16.u32l;
    // 0x80004CAC: b           L_80004CBC
    // 0x80004CB0: nop

        goto L_80004CBC;
    // 0x80004CB0: nop

L_80004CB4:
    // 0x80004CB4: b           L_80004B10
    // 0x80004CB8: nop

        goto L_80004B10;
    // 0x80004CB8: nop

L_80004CBC:
    // 0x80004CBC: b           L_80004CCC
    // 0x80004CC0: nop

        goto L_80004CCC;
    // 0x80004CC0: nop

    // 0x80004CC4: b           L_80004CCC
    // 0x80004CC8: nop

        goto L_80004CCC;
    // 0x80004CC8: nop

L_80004CCC:
    // 0x80004CCC: jr          $ra
    // 0x80004CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80004CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80004CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004CD4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80004CD8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80004CDC: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80004CE0: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80004CE4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80004CE8: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80004CEC: nop

    // 0x80004CF0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80004CF4: nop

    // 0x80004CF8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80004CFC: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80004D00: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80004D04: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80004D08: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80004D0C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80004D10: beq         $t0, $at, L_80004EE4
    if (ctx->r8 == ctx->r1) {
        // 0x80004D14: nop

            goto L_80004EE4;
    }
    // 0x80004D14: nop

L_80004D18:
    // 0x80004D18: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80004D1C: nop

    // 0x80004D20: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80004D24: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x80004D28: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80004D2C: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80004D30: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80004D34: nop

    // 0x80004D38: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80004D3C: addiu       $t6, $t4, 0x2
    ctx->r14 = ADD32(ctx->r12, 0X2);
    // 0x80004D40: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80004D44: sh          $t5, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r13;
    // 0x80004D48: lui         $t7, 0x807A
    ctx->r15 = S32(0X807A << 16);
    // 0x80004D4C: lui         $t8, 0x807A
    ctx->r24 = S32(0X807A << 16);
    // 0x80004D50: addiu       $t8, $t8, 0x80
    ctx->r24 = ADD32(ctx->r24, 0X80);
    // 0x80004D54: addiu       $t7, $t7, 0x1A20
    ctx->r15 = ADD32(ctx->r15, 0X1A20);
    // 0x80004D58: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x80004D5C: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x80004D60: srl         $t9, $a0, 3
    ctx->r25 = S32(U32(ctx->r4) >> 3);
    // 0x80004D64: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80004D68: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x80004D6C: jal         0x800BC6EC
    // 0x80004D70: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_0;
    // 0x80004D70: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
    // 0x80004D74: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x80004D78: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x80004D7C: nop

    // 0x80004D80: sw          $t2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r10;
    // 0x80004D84: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80004D88: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80004D8C: lw          $a1, 0x40D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40D8);
    // 0x80004D90: lw          $a0, 0x3E2C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3E2C);
    // 0x80004D94: lui         $a2, 0x807A
    ctx->r6 = S32(0X807A << 16);
    // 0x80004D98: jal         0x800BD1FC
    // 0x80004D9C: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_1;
    // 0x80004D9C: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    after_1:
    // 0x80004DA0: lui         $t1, 0x807A
    ctx->r9 = S32(0X807A << 16);
    // 0x80004DA4: lui         $t3, 0x807A
    ctx->r11 = S32(0X807A << 16);
    // 0x80004DA8: addiu       $t3, $t3, 0x80
    ctx->r11 = ADD32(ctx->r11, 0X80);
    // 0x80004DAC: addiu       $t1, $t1, 0x1A20
    ctx->r9 = ADD32(ctx->r9, 0X1A20);
    // 0x80004DB0: subu        $a2, $t1, $t3
    ctx->r6 = SUB32(ctx->r9, ctx->r11);
    // 0x80004DB4: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x80004DB8: srl         $t5, $a2, 3
    ctx->r13 = S32(U32(ctx->r6) >> 3);
    // 0x80004DBC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80004DC0: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x80004DC4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80004DC8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80004DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004DD0: jal         0x800BD218
    // 0x80004DD4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    SysMem_DmaCopy(rdram, ctx);
        goto after_2;
    // 0x80004DD4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_2:
L_80004DD8:
    // 0x80004DD8: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80004DDC: nop

    // 0x80004DE0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80004DE4: nop

    // 0x80004DE8: bne         $t7, $zero, L_80004E04
    if (ctx->r15 != 0) {
        // 0x80004DEC: nop

            goto L_80004E04;
    }
    // 0x80004DEC: nop

    // 0x80004DF0: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80004DF4: jal         0x800BC980
    // 0x80004DF8: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x80004DF8: nop

    after_3:
    // 0x80004DFC: b           L_80005114
    // 0x80004E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80005114;
    // 0x80004E00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80004E04:
    // 0x80004E04: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80004E08: lhu         $t0, 0x42($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X42);
    // 0x80004E0C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80004E10: nop

    // 0x80004E14: bne         $t9, $t0, L_80004E38
    if (ctx->r25 != ctx->r8) {
        // 0x80004E18: nop

            goto L_80004E38;
    }
    // 0x80004E18: nop

    // 0x80004E1C: lh          $t2, 0x2($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X2);
    // 0x80004E20: lhu         $t1, 0x40($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X40);
    // 0x80004E24: nop

    // 0x80004E28: bne         $t2, $t1, L_80004E38
    if (ctx->r10 != ctx->r9) {
        // 0x80004E2C: nop

            goto L_80004E38;
    }
    // 0x80004E2C: nop

    // 0x80004E30: b           L_80004E4C
    // 0x80004E34: nop

        goto L_80004E4C;
    // 0x80004E34: nop

L_80004E38:
    // 0x80004E38: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x80004E3C: nop

    // 0x80004E40: addiu       $t5, $t3, 0x20
    ctx->r13 = ADD32(ctx->r11, 0X20);
    // 0x80004E44: b           L_80004DD8
    // 0x80004E48: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
        goto L_80004DD8;
    // 0x80004E48: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
L_80004E4C:
    // 0x80004E4C: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80004E50: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80004E54: jal         0x800BCFCC
    // 0x80004E58: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x80004E58: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_4:
    // 0x80004E5C: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80004E60: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80004E64: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80004E68: jal         0x800BCFCC
    // 0x80004E6C: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    SysMem_Copy8(rdram, ctx);
        goto after_5;
    // 0x80004E6C: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_5:
    // 0x80004E70: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80004E74: jal         0x800BC980
    // 0x80004E78: nop

    SysMem_Free(rdram, ctx);
        goto after_6;
    // 0x80004E78: nop

    after_6:
    // 0x80004E7C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80004E80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004E84: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80004E88: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80004E8C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80004E90: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80004E94: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80004E98: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x80004E9C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80004EA0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80004EA4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80004EA8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80004EAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80004EB0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80004EB4: jal         0x800A66EC
    // 0x80004EB8: subu        $a2, $t4, $t6
    ctx->r6 = SUB32(ctx->r12, ctx->r14);
    func_800A66EC(rdram, ctx);
        goto after_7;
    // 0x80004EB8: subu        $a2, $t4, $t6
    ctx->r6 = SUB32(ctx->r12, ctx->r14);
    after_7:
    // 0x80004EBC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80004EC0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80004EC4: addu        $t2, $t8, $s0
    ctx->r10 = ADD32(ctx->r24, ctx->r16);
    // 0x80004EC8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80004ECC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80004ED0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80004ED4: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80004ED8: nop

    // 0x80004EDC: bne         $t3, $at, L_80004D18
    if (ctx->r11 != ctx->r1) {
        // 0x80004EE0: nop

            goto L_80004D18;
    }
    // 0x80004EE0: nop

L_80004EE4:
    // 0x80004EE4: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80004EE8: nop

    // 0x80004EEC: addiu       $t4, $t5, 0x2
    ctx->r12 = ADD32(ctx->r13, 0X2);
    // 0x80004EF0: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80004EF4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80004EF8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80004EFC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80004F00: nop

    // 0x80004F04: beq         $t7, $at, L_800050E4
    if (ctx->r15 == ctx->r1) {
        // 0x80004F08: nop

            goto L_800050E4;
    }
    // 0x80004F08: nop

L_80004F0C:
    // 0x80004F0C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80004F10: nop

    // 0x80004F14: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80004F18: addiu       $t8, $t9, 0x2
    ctx->r24 = ADD32(ctx->r25, 0X2);
    // 0x80004F1C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80004F20: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x80004F24: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80004F28: nop

    // 0x80004F2C: lhu         $t1, 0x0($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X0);
    // 0x80004F30: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x80004F34: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80004F38: sh          $t1, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r9;
    // 0x80004F3C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80004F40: nop

    // 0x80004F44: lhu         $t4, 0x0($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X0);
    // 0x80004F48: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x80004F4C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80004F50: sh          $t4, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r12;
    // 0x80004F54: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80004F58: nop

    // 0x80004F5C: lhu         $t0, 0x0($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X0);
    // 0x80004F60: addiu       $t9, $t7, 0x2
    ctx->r25 = ADD32(ctx->r15, 0X2);
    // 0x80004F64: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80004F68: sh          $t0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r8;
    // 0x80004F6C: lhu         $t8, 0x3E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3E);
    // 0x80004F70: nop

    // 0x80004F74: bne         $t8, $zero, L_8000504C
    if (ctx->r24 != 0) {
        // 0x80004F78: nop

            goto L_8000504C;
    }
    // 0x80004F78: nop

    // 0x80004F7C: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x80004F80: nop

    // 0x80004F84: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80004F88: beq         $at, $zero, L_80004FEC
    if (ctx->r1 == 0) {
        // 0x80004F8C: nop

            goto L_80004FEC;
    }
    // 0x80004F8C: nop

    // 0x80004F90: lhu         $t4, 0x42($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X42);
    // 0x80004F94: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80004F98: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80004F9C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80004FA0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80004FA4: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x80004FA8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80004FAC: lhu         $t2, 0x40($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X40);
    // 0x80004FB0: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80004FB4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80004FB8: sw          $t2, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r10;
    // 0x80004FBC: lhu         $t9, 0x42($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X42);
    // 0x80004FC0: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80004FC4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80004FC8: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80004FCC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80004FD0: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x80004FD4: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80004FD8: lhu         $t0, 0x3C($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3C);
    // 0x80004FDC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80004FE0: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x80004FE4: b           L_80005044
    // 0x80004FE8: sh          $t0, 0x124($t1)
    MEM_H(0X124, ctx->r9) = ctx->r8;
        goto L_80005044;
    // 0x80004FE8: sh          $t0, 0x124($t1)
    MEM_H(0X124, ctx->r9) = ctx->r8;
L_80004FEC:
    // 0x80004FEC: lhu         $t5, 0x42($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X42);
    // 0x80004FF0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80004FF4: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x80004FF8: subu        $t2, $t2, $t5
    ctx->r10 = SUB32(ctx->r10, ctx->r13);
    // 0x80004FFC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80005000: lw          $t3, -0x73DC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73DC);
    // 0x80005004: subu        $t2, $t2, $t5
    ctx->r10 = SUB32(ctx->r10, ctx->r13);
    // 0x80005008: lhu         $t4, 0x40($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X40);
    // 0x8000500C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80005010: addu        $t6, $t3, $t2
    ctx->r14 = ADD32(ctx->r11, ctx->r10);
    // 0x80005014: sw          $t4, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->r12;
    // 0x80005018: lhu         $t8, 0x42($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X42);
    // 0x8000501C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80005020: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80005024: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80005028: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8000502C: lw          $t7, -0x73DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73DC);
    // 0x80005030: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80005034: lhu         $t9, 0x3C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3C);
    // 0x80005038: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8000503C: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80005040: sh          $t9, 0x124($t1)
    MEM_H(0X124, ctx->r9) = ctx->r25;
L_80005044:
    // 0x80005044: b           L_800050CC
    // 0x80005048: nop

        goto L_800050CC;
    // 0x80005048: nop

L_8000504C:
    // 0x8000504C: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80005050: nop

    // 0x80005054: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80005058: beq         $at, $zero, L_80005098
    if (ctx->r1 == 0) {
        // 0x8000505C: nop

            goto L_80005098;
    }
    // 0x8000505C: nop

    // 0x80005060: lhu         $t3, 0x42($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X42);
    // 0x80005064: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80005068: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8000506C: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80005070: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80005074: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x80005078: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8000507C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80005080: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x80005084: lw          $t8, 0xC0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC0);
    // 0x80005088: nop

    // 0x8000508C: ori         $t7, $t8, 0x80
    ctx->r15 = ctx->r24 | 0X80;
    // 0x80005090: b           L_800050CC
    // 0x80005094: sw          $t7, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r15;
        goto L_800050CC;
    // 0x80005094: sw          $t7, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->r15;
L_80005098:
    // 0x80005098: lhu         $t0, 0x42($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X42);
    // 0x8000509C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800050A0: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800050A4: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x800050A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800050AC: lw          $t1, -0x73DC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73DC);
    // 0x800050B0: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x800050B4: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800050B8: addu        $t5, $t9, $t1
    ctx->r13 = ADD32(ctx->r25, ctx->r9);
    // 0x800050BC: lw          $t3, 0xC0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0XC0);
    // 0x800050C0: nop

    // 0x800050C4: ori         $t2, $t3, 0x80
    ctx->r10 = ctx->r11 | 0X80;
    // 0x800050C8: sw          $t2, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r10;
L_800050CC:
    // 0x800050CC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800050D0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800050D4: lhu         $t8, 0x0($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X0);
    // 0x800050D8: nop

    // 0x800050DC: bne         $t8, $at, L_80004F0C
    if (ctx->r24 != ctx->r1) {
        // 0x800050E0: nop

            goto L_80004F0C;
    }
    // 0x800050E0: nop

L_800050E4:
    // 0x800050E4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800050E8: nop

    // 0x800050EC: addiu       $t6, $t7, 0x2
    ctx->r14 = ADD32(ctx->r15, 0X2);
    // 0x800050F0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800050F4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800050F8: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800050FC: nop

    // 0x80005100: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x80005104: b           L_80005114
    // 0x80005108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005114;
    // 0x80005108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000510C: b           L_80005114
    // 0x80005110: nop

        goto L_80005114;
    // 0x80005110: nop

L_80005114:
    // 0x80005114: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80005118: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000511C: jr          $ra
    // 0x80005120: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80005120: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80005124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005124: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000512C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80005130: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80005134: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    // 0x80005138: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x8000513C: jal         0x80004410
    // 0x80005140: nop

    func_80004410(rdram, ctx);
        goto after_0;
    // 0x80005140: nop

    after_0:
    // 0x80005144: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80005148: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000514C: nop

    // 0x80005150: bne         $t6, $zero, L_80005160
    if (ctx->r14 != 0) {
        // 0x80005154: nop

            goto L_80005160;
    }
    // 0x80005154: nop

    // 0x80005158: b           L_800051C4
    // 0x8000515C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800051C4;
    // 0x8000515C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005160:
    // 0x80005160: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80005164: nop

    // 0x80005168: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8000516C: nop

    // 0x80005170: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80005174: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80005178: nop

    // 0x8000517C: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x80005180: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80005184: jal         0x800C4270
    // 0x80005188: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x80005188: nop

    after_1:
    // 0x8000518C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80005190: jal         0x80004CD4
    // 0x80005194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80004CD4(rdram, ctx);
        goto after_2;
    // 0x80005194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80005198: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000519C: bne         $v0, $at, L_800051B4
    if (ctx->r2 != ctx->r1) {
        // 0x800051A0: nop

            goto L_800051B4;
    }
    // 0x800051A0: nop

    // 0x800051A4: jal         0x80005460
    // 0x800051A8: nop

    func_80005460(rdram, ctx);
        goto after_3;
    // 0x800051A8: nop

    after_3:
    // 0x800051AC: b           L_800051C4
    // 0x800051B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800051C4;
    // 0x800051B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800051B4:
    // 0x800051B4: b           L_800051C4
    // 0x800051B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800051C4;
    // 0x800051B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800051BC: b           L_800051C4
    // 0x800051C0: nop

        goto L_800051C4;
    // 0x800051C0: nop

L_800051C4:
    // 0x800051C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800051C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800051CC: jr          $ra
    // 0x800051D0: nop

    return;
    // 0x800051D0: nop

;}
RECOMP_FUNC void func_800051D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800051D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800051D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800051DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800051E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800051E4: lhu         $a0, 0x2A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X2A);
    // 0x800051E8: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x800051EC: jal         0x80004410
    // 0x800051F0: nop

    func_80004410(rdram, ctx);
        goto after_0;
    // 0x800051F0: nop

    after_0:
    // 0x800051F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800051F8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800051FC: nop

    // 0x80005200: bne         $t6, $zero, L_80005210
    if (ctx->r14 != 0) {
        // 0x80005204: nop

            goto L_80005210;
    }
    // 0x80005204: nop

    // 0x80005208: b           L_80005274
    // 0x8000520C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80005274;
    // 0x8000520C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005210:
    // 0x80005210: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80005214: nop

    // 0x80005218: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8000521C: nop

    // 0x80005220: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80005224: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80005228: nop

    // 0x8000522C: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x80005230: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80005234: jal         0x800C4270
    // 0x80005238: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x80005238: nop

    after_1:
    // 0x8000523C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80005240: jal         0x80004CD4
    // 0x80005244: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80004CD4(rdram, ctx);
        goto after_2;
    // 0x80005244: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80005248: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000524C: bne         $v0, $at, L_80005264
    if (ctx->r2 != ctx->r1) {
        // 0x80005250: nop

            goto L_80005264;
    }
    // 0x80005250: nop

    // 0x80005254: jal         0x800055DC
    // 0x80005258: nop

    func_800055DC(rdram, ctx);
        goto after_3;
    // 0x80005258: nop

    after_3:
    // 0x8000525C: b           L_80005274
    // 0x80005260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80005274;
    // 0x80005260: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005264:
    // 0x80005264: b           L_80005274
    // 0x80005268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005274;
    // 0x80005268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000526C: b           L_80005274
    // 0x80005270: nop

        goto L_80005274;
    // 0x80005270: nop

L_80005274:
    // 0x80005274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005278: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000527C: jr          $ra
    // 0x80005280: nop

    return;
    // 0x80005280: nop

;}
RECOMP_FUNC void func_80005284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005284: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x80005288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000528C: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
    // 0x80005290: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
L_80005294:
    // 0x80005294: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x80005298: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000529C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800052A0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800052A4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800052A8: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x800052AC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800052B0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800052B4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800052B8: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x800052BC: lw          $t1, 0x17C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X17C);
    // 0x800052C0: nop

    // 0x800052C4: or          $t2, $t1, $t0
    ctx->r10 = ctx->r9 | ctx->r8;
    // 0x800052C8: sw          $t2, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r10;
    // 0x800052CC: lw          $t3, 0x178($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X178);
    // 0x800052D0: nop

    // 0x800052D4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800052D8: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800052DC: bne         $at, $zero, L_80005294
    if (ctx->r1 != 0) {
        // 0x800052E0: sw          $t4, 0x178($sp)
        MEM_W(0X178, ctx->r29) = ctx->r12;
            goto L_80005294;
    }
    // 0x800052E0: sw          $t4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r12;
    // 0x800052E4: lw          $t5, 0x17C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X17C);
    // 0x800052E8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800052EC: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800052F0: bne         $t7, $zero, L_80005300
    if (ctx->r15 != 0) {
        // 0x800052F4: nop

            goto L_80005300;
    }
    // 0x800052F4: nop

    // 0x800052F8: b           L_80005450
    // 0x800052FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80005450;
    // 0x800052FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005300:
    // 0x80005300: sw          $zero, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = 0;
    // 0x80005304: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
L_80005308:
    // 0x80005308: lw          $t8, 0x178($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X178);
    // 0x8000530C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005310: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80005314: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80005318: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000531C: lw          $t6, -0x73DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73DC);
    // 0x80005320: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80005324: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80005328: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x8000532C: lw          $t0, 0xC0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0XC0);
    // 0x80005330: lw          $t2, 0x17C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X17C);
    // 0x80005334: nop

    // 0x80005338: or          $t3, $t2, $t0
    ctx->r11 = ctx->r10 | ctx->r8;
    // 0x8000533C: sw          $t3, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r11;
    // 0x80005340: lw          $t4, 0x178($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X178);
    // 0x80005344: nop

    // 0x80005348: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000534C: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80005350: bne         $at, $zero, L_80005308
    if (ctx->r1 != 0) {
        // 0x80005354: sw          $t5, 0x178($sp)
        MEM_W(0X178, ctx->r29) = ctx->r13;
            goto L_80005308;
    }
    // 0x80005354: sw          $t5, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r13;
    // 0x80005358: lw          $t7, 0x17C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X17C);
    // 0x8000535C: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80005360: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80005364: bne         $t8, $zero, L_80005374
    if (ctx->r24 != 0) {
        // 0x80005368: nop

            goto L_80005374;
    }
    // 0x80005368: nop

    // 0x8000536C: b           L_80005450
    // 0x80005370: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
        goto L_80005450;
    // 0x80005370: addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_80005374:
    // 0x80005374: sw          $zero, 0x178($sp)
    MEM_W(0X178, ctx->r29) = 0;
L_80005378:
    // 0x80005378: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x8000537C: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80005380: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80005384: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80005388: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000538C: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x80005390: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80005394: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x80005398: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8000539C: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    // 0x800053A0: jal         0x800BCFCC
    // 0x800053A4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    SysMem_Copy8(rdram, ctx);
        goto after_0;
    // 0x800053A4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_0:
    // 0x800053A8: jal         0x800C4270
    // 0x800053AC: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x800053AC: nop

    after_1:
    // 0x800053B0: lw          $t2, 0x178($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X178);
    // 0x800053B4: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800053B8: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x800053BC: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x800053C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800053C4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x800053C8: lw          $t4, -0x73DC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73DC);
    // 0x800053CC: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x800053D0: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x800053D4: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x800053D8: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    // 0x800053DC: addu        $a1, $t0, $t4
    ctx->r5 = ADD32(ctx->r8, ctx->r12);
    // 0x800053E0: jal         0x800BCFCC
    // 0x800053E4: addu        $a0, $t0, $t3
    ctx->r4 = ADD32(ctx->r8, ctx->r11);
    SysMem_Copy8(rdram, ctx);
        goto after_2;
    // 0x800053E4: addu        $a0, $t0, $t3
    ctx->r4 = ADD32(ctx->r8, ctx->r11);
    after_2:
    // 0x800053E8: jal         0x800C4270
    // 0x800053EC: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_3;
    // 0x800053EC: nop

    after_3:
    // 0x800053F0: lw          $t5, 0x178($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X178);
    // 0x800053F4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800053F8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800053FC: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80005400: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80005404: lw          $t8, -0x73DC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73DC);
    // 0x80005408: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8000540C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80005410: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80005414: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    // 0x80005418: jal         0x800BCFCC
    // 0x8000541C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    SysMem_Copy8(rdram, ctx);
        goto after_4;
    // 0x8000541C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80005420: jal         0x800C4270
    // 0x80005424: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_5;
    // 0x80005424: nop

    after_5:
    // 0x80005428: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x8000542C: nop

    // 0x80005430: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80005434: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80005438: bne         $at, $zero, L_80005378
    if (ctx->r1 != 0) {
        // 0x8000543C: sw          $t9, 0x178($sp)
        MEM_W(0X178, ctx->r29) = ctx->r25;
            goto L_80005378;
    }
    // 0x8000543C: sw          $t9, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r25;
    // 0x80005440: b           L_80005450
    // 0x80005444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005450;
    // 0x80005444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005448: b           L_80005450
    // 0x8000544C: nop

        goto L_80005450;
    // 0x8000544C: nop

L_80005450:
    // 0x80005450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005454: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    // 0x80005458: jr          $ra
    // 0x8000545C: nop

    return;
    // 0x8000545C: nop

;}
RECOMP_FUNC void func_80005460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005468: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000546C: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80005470: nop

    // 0x80005474: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80005478: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8000547C:
    // 0x8000547C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80005480: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80005484: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x80005488: nop

    // 0x8000548C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80005490: beq         $t9, $zero, L_80005558
    if (ctx->r25 == 0) {
        // 0x80005494: nop

            goto L_80005558;
    }
    // 0x80005494: nop

    // 0x80005498: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x8000549C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x800054A0: beq         $t0, $zero, L_80005558
    if (ctx->r8 == 0) {
        // 0x800054A4: nop

            goto L_80005558;
    }
    // 0x800054A4: nop

    // 0x800054A8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800054AC: nop

    // 0x800054B0: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x800054B4: nop

    // 0x800054B8: beq         $t2, $zero, L_800054D4
    if (ctx->r10 == 0) {
        // 0x800054BC: nop

            goto L_800054D4;
    }
    // 0x800054BC: nop

    // 0x800054C0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800054C4: nop

    // 0x800054C8: lw          $a0, 0x138($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X138);
    // 0x800054CC: jal         0x800BC980
    // 0x800054D0: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x800054D0: nop

    after_0:
L_800054D4:
    // 0x800054D4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800054D8: nop

    // 0x800054DC: lw          $t5, 0x12C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X12C);
    // 0x800054E0: nop

    // 0x800054E4: beq         $t5, $zero, L_80005500
    if (ctx->r13 == 0) {
        // 0x800054E8: nop

            goto L_80005500;
    }
    // 0x800054E8: nop

    // 0x800054EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800054F0: nop

    // 0x800054F4: lw          $a0, 0x12C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X12C);
    // 0x800054F8: jal         0x800BC980
    // 0x800054FC: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x800054FC: nop

    after_1:
L_80005500:
    // 0x80005500: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80005504: nop

    // 0x80005508: lw          $t9, 0x130($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X130);
    // 0x8000550C: nop

    // 0x80005510: beq         $t9, $zero, L_8000552C
    if (ctx->r25 == 0) {
        // 0x80005514: nop

            goto L_8000552C;
    }
    // 0x80005514: nop

    // 0x80005518: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000551C: nop

    // 0x80005520: lw          $a0, 0x130($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X130);
    // 0x80005524: jal         0x800BC980
    // 0x80005528: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x80005528: nop

    after_2:
L_8000552C:
    // 0x8000552C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80005530: nop

    // 0x80005534: lw          $t1, 0x144($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X144);
    // 0x80005538: nop

    // 0x8000553C: beq         $t1, $zero, L_80005558
    if (ctx->r9 == 0) {
        // 0x80005540: nop

            goto L_80005558;
    }
    // 0x80005540: nop

    // 0x80005544: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80005548: nop

    // 0x8000554C: lw          $a0, 0x144($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X144);
    // 0x80005550: jal         0x800BC980
    // 0x80005554: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x80005554: nop

    after_3:
L_80005558:
    // 0x80005558: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x8000555C: nop

    // 0x80005560: sw          $zero, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = 0;
    // 0x80005564: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80005568: nop

    // 0x8000556C: sw          $zero, 0x138($t4)
    MEM_W(0X138, ctx->r12) = 0;
    // 0x80005570: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80005574: nop

    // 0x80005578: sw          $zero, 0x12C($t5)
    MEM_W(0X12C, ctx->r13) = 0;
    // 0x8000557C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80005580: nop

    // 0x80005584: sw          $zero, 0x130($t6)
    MEM_W(0X130, ctx->r14) = 0;
    // 0x80005588: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000558C: nop

    // 0x80005590: sw          $zero, 0x144($t7)
    MEM_W(0X144, ctx->r15) = 0;
    // 0x80005594: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80005598: nop

    // 0x8000559C: addiu       $t8, $t9, 0x160
    ctx->r24 = ADD32(ctx->r25, 0X160);
    // 0x800055A0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800055A4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800055A8: nop

    // 0x800055AC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800055B0: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x800055B4: bne         $at, $zero, L_8000547C
    if (ctx->r1 != 0) {
        // 0x800055B8: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8000547C;
    }
    // 0x800055B8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800055BC: b           L_800055CC
    // 0x800055C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800055CC;
    // 0x800055C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800055C4: b           L_800055CC
    // 0x800055C8: nop

        goto L_800055CC;
    // 0x800055C8: nop

L_800055CC:
    // 0x800055CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800055D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800055D4: jr          $ra
    // 0x800055D8: nop

    return;
    // 0x800055D8: nop

;}
RECOMP_FUNC void func_800055DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800055DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800055E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800055E4: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800055E8: lw          $t6, -0x73DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73DC);
    // 0x800055EC: nop

    // 0x800055F0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800055F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800055F8:
    // 0x800055F8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800055FC: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x80005600: lw          $t8, 0xC0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC0);
    // 0x80005604: nop

    // 0x80005608: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000560C: beq         $t9, $zero, L_800056D4
    if (ctx->r25 == 0) {
        // 0x80005610: nop

            goto L_800056D4;
    }
    // 0x80005610: nop

    // 0x80005614: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x80005618: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x8000561C: beq         $t0, $zero, L_800056D4
    if (ctx->r8 == 0) {
        // 0x80005620: nop

            goto L_800056D4;
    }
    // 0x80005620: nop

    // 0x80005624: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80005628: nop

    // 0x8000562C: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x80005630: nop

    // 0x80005634: beq         $t2, $zero, L_80005650
    if (ctx->r10 == 0) {
        // 0x80005638: nop

            goto L_80005650;
    }
    // 0x80005638: nop

    // 0x8000563C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80005640: nop

    // 0x80005644: lw          $a0, 0x138($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X138);
    // 0x80005648: jal         0x800BC980
    // 0x8000564C: nop

    SysMem_Free(rdram, ctx);
        goto after_0;
    // 0x8000564C: nop

    after_0:
L_80005650:
    // 0x80005650: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80005654: nop

    // 0x80005658: lw          $t5, 0x12C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X12C);
    // 0x8000565C: nop

    // 0x80005660: beq         $t5, $zero, L_8000567C
    if (ctx->r13 == 0) {
        // 0x80005664: nop

            goto L_8000567C;
    }
    // 0x80005664: nop

    // 0x80005668: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8000566C: nop

    // 0x80005670: lw          $a0, 0x12C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X12C);
    // 0x80005674: jal         0x800BC980
    // 0x80005678: nop

    SysMem_Free(rdram, ctx);
        goto after_1;
    // 0x80005678: nop

    after_1:
L_8000567C:
    // 0x8000567C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80005680: nop

    // 0x80005684: lw          $t9, 0x130($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X130);
    // 0x80005688: nop

    // 0x8000568C: beq         $t9, $zero, L_800056A8
    if (ctx->r25 == 0) {
        // 0x80005690: nop

            goto L_800056A8;
    }
    // 0x80005690: nop

    // 0x80005694: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80005698: nop

    // 0x8000569C: lw          $a0, 0x130($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X130);
    // 0x800056A0: jal         0x800BC980
    // 0x800056A4: nop

    SysMem_Free(rdram, ctx);
        goto after_2;
    // 0x800056A4: nop

    after_2:
L_800056A8:
    // 0x800056A8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800056AC: nop

    // 0x800056B0: lw          $t1, 0x144($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X144);
    // 0x800056B4: nop

    // 0x800056B8: beq         $t1, $zero, L_800056D4
    if (ctx->r9 == 0) {
        // 0x800056BC: nop

            goto L_800056D4;
    }
    // 0x800056BC: nop

    // 0x800056C0: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800056C4: nop

    // 0x800056C8: lw          $a0, 0x144($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X144);
    // 0x800056CC: jal         0x800BC980
    // 0x800056D0: nop

    SysMem_Free(rdram, ctx);
        goto after_3;
    // 0x800056D0: nop

    after_3:
L_800056D4:
    // 0x800056D4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800056D8: nop

    // 0x800056DC: sw          $zero, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = 0;
    // 0x800056E0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800056E4: nop

    // 0x800056E8: sw          $zero, 0x138($t4)
    MEM_W(0X138, ctx->r12) = 0;
    // 0x800056EC: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800056F0: nop

    // 0x800056F4: sw          $zero, 0x12C($t5)
    MEM_W(0X12C, ctx->r13) = 0;
    // 0x800056F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800056FC: nop

    // 0x80005700: sw          $zero, 0x130($t6)
    MEM_W(0X130, ctx->r14) = 0;
    // 0x80005704: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80005708: nop

    // 0x8000570C: sw          $zero, 0x144($t7)
    MEM_W(0X144, ctx->r15) = 0;
    // 0x80005710: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80005714: nop

    // 0x80005718: addiu       $t8, $t9, 0x160
    ctx->r24 = ADD32(ctx->r25, 0X160);
    // 0x8000571C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80005720: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80005724: nop

    // 0x80005728: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000572C: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80005730: bne         $at, $zero, L_800055F8
    if (ctx->r1 != 0) {
        // 0x80005734: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_800055F8;
    }
    // 0x80005734: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80005738: b           L_80005748
    // 0x8000573C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005748;
    // 0x8000573C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005740: b           L_80005748
    // 0x80005744: nop

        goto L_80005748;
    // 0x80005744: nop

L_80005748:
    // 0x80005748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000574C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80005750: jr          $ra
    // 0x80005754: nop

    return;
    // 0x80005754: nop

;}
RECOMP_FUNC void func_80005758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005758: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000575C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x80005760: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_80005764:
    // 0x80005764: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80005768: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000576C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80005770: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80005774: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80005778: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x8000577C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80005780: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80005784: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80005788: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x8000578C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80005790: nop

    // 0x80005794: or          $t2, $t1, $t0
    ctx->r10 = ctx->r9 | ctx->r8;
    // 0x80005798: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8000579C: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800057A0: nop

    // 0x800057A4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800057A8: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800057AC: bne         $at, $zero, L_80005764
    if (ctx->r1 != 0) {
        // 0x800057B0: sw          $t4, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r12;
            goto L_80005764;
    }
    // 0x800057B0: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x800057B4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800057B8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800057BC: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800057C0: bne         $t7, $zero, L_800057D0
    if (ctx->r15 != 0) {
        // 0x800057C4: nop

            goto L_800057D0;
    }
    // 0x800057C4: nop

    // 0x800057C8: b           L_800057E0
    // 0x800057CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800057E0;
    // 0x800057CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800057D0:
    // 0x800057D0: b           L_800057E0
    // 0x800057D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800057E0;
    // 0x800057D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800057D8: b           L_800057E0
    // 0x800057DC: nop

        goto L_800057E0;
    // 0x800057DC: nop

L_800057E0:
    // 0x800057E0: jr          $ra
    // 0x800057E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800057E4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800057E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800057E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800057EC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800057F0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800057F4:
    // 0x800057F4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800057F8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800057FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80005800: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80005804: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80005808: lw          $t6, -0x73DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73DC);
    // 0x8000580C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80005810: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80005814: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80005818: lw          $t0, 0xC0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC0);
    // 0x8000581C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80005820: nop

    // 0x80005824: or          $t2, $t1, $t0
    ctx->r10 = ctx->r9 | ctx->r8;
    // 0x80005828: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8000582C: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x80005830: nop

    // 0x80005834: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80005838: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x8000583C: bne         $at, $zero, L_800057F4
    if (ctx->r1 != 0) {
        // 0x80005840: sw          $t4, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r12;
            goto L_800057F4;
    }
    // 0x80005840: sw          $t4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r12;
    // 0x80005844: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80005848: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x8000584C: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x80005850: bne         $t7, $zero, L_80005860
    if (ctx->r15 != 0) {
        // 0x80005854: nop

            goto L_80005860;
    }
    // 0x80005854: nop

    // 0x80005858: b           L_80005870
    // 0x8000585C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80005870;
    // 0x8000585C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80005860:
    // 0x80005860: b           L_80005870
    // 0x80005864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005870;
    // 0x80005864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005868: b           L_80005870
    // 0x8000586C: nop

        goto L_80005870;
    // 0x8000586C: nop

L_80005870:
    // 0x80005870: jr          $ra
    // 0x80005874: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80005874: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80005878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005878: nop

    // 0x8000587C: nop

;}
RECOMP_FUNC void func_80005880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005880: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x80005884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005888: sw          $a0, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r4;
    // 0x8000588C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005890: lw          $t6, 0x1E0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1E0);
    // 0x80005894: nop

    // 0x80005898: sw          $t6, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r14;
    // 0x8000589C: lw          $t7, 0x1CC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1CC);
    // 0x800058A0: nop

    // 0x800058A4: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800058A8: nop

    // 0x800058AC: sw          $t8, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->r24;
    // 0x800058B0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800058B4: lh          $t9, 0x72AC($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X72AC);
    // 0x800058B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800058BC: bne         $t9, $at, L_80005900
    if (ctx->r25 != ctx->r1) {
        // 0x800058C0: nop

            goto L_80005900;
    }
    // 0x800058C0: nop

    // 0x800058C4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800058C8: lh          $t0, 0x72B4($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X72B4);
    // 0x800058CC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800058D0: beq         $t0, $at, L_800058E4
    if (ctx->r8 == ctx->r1) {
        // 0x800058D4: nop

            goto L_800058E4;
    }
    // 0x800058D4: nop

    // 0x800058D8: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x800058DC: bne         $t0, $at, L_80005900
    if (ctx->r8 != ctx->r1) {
        // 0x800058E0: nop

            goto L_80005900;
    }
    // 0x800058E0: nop

L_800058E4:
    // 0x800058E4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800058E8: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x800058EC: lhu         $t2, 0x4($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X4);
    // 0x800058F0: nop

    // 0x800058F4: ori         $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 | 0X8000;
    // 0x800058F8: b           L_8000591C
    // 0x800058FC: sh          $t3, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r11;
        goto L_8000591C;
    // 0x800058FC: sh          $t3, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r11;
L_80005900:
    // 0x80005900: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80005904: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80005908: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x8000590C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80005910: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80005914: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80005918: sh          $t6, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r14;
L_8000591C:
    // 0x8000591C: lw          $t7, 0x1C8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005920: nop

    // 0x80005924: addiu       $t8, $t7, 0x7FFF
    ctx->r24 = ADD32(ctx->r15, 0X7FFF);
    // 0x80005928: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x8000592C: nop

    // 0x80005930: blez        $t8, L_800059B4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80005934: nop

            goto L_800059B4;
    }
    // 0x80005934: nop

L_80005938:
    // 0x80005938: lw          $t9, 0x1CC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1CC);
    // 0x8000593C: addiu       $a1, $sp, 0x1C4
    ctx->r5 = ADD32(ctx->r29, 0X1C4);
    // 0x80005940: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x80005944: jal         0x800C143C
    // 0x80005948: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_0;
    // 0x80005948: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8000594C: lw          $t0, 0x1C4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C4);
    // 0x80005950: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80005954: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x80005958: nop

    // 0x8000595C: bne         $t2, $at, L_80005998
    if (ctx->r10 != ctx->r1) {
        // 0x80005960: nop

            goto L_80005998;
    }
    // 0x80005960: nop

    // 0x80005964: b           L_8000596C
    // 0x80005968: nop

        goto L_8000596C;
    // 0x80005968: nop

L_8000596C:
    // 0x8000596C: jal         0x80099520
    // 0x80005970: nop

    func_80099520(rdram, ctx);
        goto after_1;
    // 0x80005970: nop

    after_1:
    // 0x80005974: lw          $t3, 0x1C8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005978: nop

    // 0x8000597C: addiu       $t1, $t3, 0x7FFF
    ctx->r9 = ADD32(ctx->r11, 0X7FFF);
    // 0x80005980: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x80005984: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x80005988: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x8000598C: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
    // 0x80005990: b           L_80005998
    // 0x80005994: nop

        goto L_80005998;
    // 0x80005994: nop

L_80005998:
    // 0x80005998: lw          $t6, 0x1C8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C8);
    // 0x8000599C: nop

    // 0x800059A0: addiu       $t4, $t6, 0x7FFF
    ctx->r12 = ADD32(ctx->r14, 0X7FFF);
    // 0x800059A4: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x800059A8: nop

    // 0x800059AC: bgtz        $t4, L_80005938
    if (SIGNED(ctx->r12) > 0) {
        // 0x800059B0: nop

            goto L_80005938;
    }
    // 0x800059B0: nop

L_800059B4:
    // 0x800059B4: jal         0x80098820
    // 0x800059B8: nop

    func_80098820(rdram, ctx);
        goto after_2;
    // 0x800059B8: nop

    after_2:
    // 0x800059BC: jal         0x80098868
    // 0x800059C0: nop

    func_80098868(rdram, ctx);
        goto after_3;
    // 0x800059C0: nop

    after_3:
    // 0x800059C4: sw          $zero, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = 0;
L_800059C8:
    // 0x800059C8: lw          $t7, 0x1DC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1DC);
    // 0x800059CC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800059D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800059D4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800059D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800059DC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800059E0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800059E4: addiu       $t9, $t9, -0x71B0
    ctx->r25 = ADD32(ctx->r25, -0X71B0);
    // 0x800059E8: jal         0x80099E2C
    // 0x800059EC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    func_80099E2C(rdram, ctx);
        goto after_4;
    // 0x800059EC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x800059F0: lw          $t0, 0x1DC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1DC);
    // 0x800059F4: nop

    // 0x800059F8: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800059FC: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x80005A00: bne         $at, $zero, L_800059C8
    if (ctx->r1 != 0) {
        // 0x80005A04: sw          $t2, 0x1DC($sp)
        MEM_W(0X1DC, ctx->r29) = ctx->r10;
            goto L_800059C8;
    }
    // 0x80005A04: sw          $t2, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->r10;
    // 0x80005A08: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005A0C: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80005A10: jal         0x800A6670
    // 0x80005A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_5;
    // 0x80005A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80005A18: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005A1C: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80005A20: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80005A24: jal         0x800A6670
    // 0x80005A28: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_6;
    // 0x80005A28: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_6:
    // 0x80005A2C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005A30: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80005A34: lh          $a1, 0x72B4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X72B4);
    // 0x80005A38: lh          $a0, 0x72AC($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X72AC);
    // 0x80005A3C: jal         0x80005124
    // 0x80005A40: nop

    func_80005124(rdram, ctx);
        goto after_7;
    // 0x80005A40: nop

    after_7:
    // 0x80005A44: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
    // 0x80005A48: lw          $t1, 0x1D0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D0);
    // 0x80005A4C: nop

    // 0x80005A50: bne         $t1, $zero, L_80005A64
    if (ctx->r9 != 0) {
        // 0x80005A54: nop

            goto L_80005A64;
    }
    // 0x80005A54: nop

    // 0x80005A58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80005A5C: jal         0x800A6F20
    // 0x80005A60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800A6F20(rdram, ctx);
        goto after_8;
    // 0x80005A60: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_8:
L_80005A64:
    // 0x80005A64: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80005A68: lbu         $t5, 0x125A($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X125A);
    // 0x80005A6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80005A70: ori         $t3, $t5, 0x1
    ctx->r11 = ctx->r13 | 0X1;
    // 0x80005A74: sb          $t3, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = ctx->r11;
    // 0x80005A78: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005A7C: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80005A80: lhu         $t4, 0x4($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X4);
    // 0x80005A84: nop

    // 0x80005A88: andi        $t7, $t4, 0x8000
    ctx->r15 = ctx->r12 & 0X8000;
    // 0x80005A8C: beq         $t7, $zero, L_80005AA4
    if (ctx->r15 == 0) {
        // 0x80005A90: nop

            goto L_80005AA4;
    }
    // 0x80005A90: nop

    // 0x80005A94: jal         0x800831E0
    // 0x80005A98: nop

    func_800831E0(rdram, ctx);
        goto after_9;
    // 0x80005A98: nop

    after_9:
    // 0x80005A9C: b           L_80005AAC
    // 0x80005AA0: nop

        goto L_80005AAC;
    // 0x80005AA0: nop

L_80005AA4:
    // 0x80005AA4: jal         0x80079910
    // 0x80005AA8: nop

    func_80079910(rdram, ctx);
        goto after_10;
    // 0x80005AA8: nop

    after_10:
L_80005AAC:
    // 0x80005AAC: sw          $zero, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = 0;
    // 0x80005AB0: lw          $t8, 0x1CC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1CC);
    // 0x80005AB4: nop

    // 0x80005AB8: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80005ABC: jal         0x800C13B8
    // 0x80005AC0: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_11;
    // 0x80005AC0: nop

    after_11:
    // 0x80005AC4: jal         0x80098820
    // 0x80005AC8: nop

    func_80098820(rdram, ctx);
        goto after_12;
    // 0x80005AC8: nop

    after_12:
    // 0x80005ACC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80005AD0: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80005AD4: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80005AD8: nop

    // 0x80005ADC: andi        $t2, $t0, 0x40
    ctx->r10 = ctx->r8 & 0X40;
    // 0x80005AE0: beq         $t2, $zero, L_80005AF8
    if (ctx->r10 == 0) {
        // 0x80005AE4: nop

            goto L_80005AF8;
    }
    // 0x80005AE4: nop

    // 0x80005AE8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80005AEC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80005AF0: jal         0x80021FF8
    // 0x80005AF4: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_80021FF8(rdram, ctx);
        goto after_13;
    // 0x80005AF4: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_13:
L_80005AF8:
    // 0x80005AF8: jal         0x80098BF4
    // 0x80005AFC: nop

    func_80098BF4(rdram, ctx);
        goto after_14;
    // 0x80005AFC: nop

    after_14:
    // 0x80005B00: lw          $t1, 0x1D8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D8);
    // 0x80005B04: nop

    // 0x80005B08: bne         $t1, $zero, L_80006114
    if (ctx->r9 != 0) {
        // 0x80005B0C: nop

            goto L_80006114;
    }
    // 0x80005B0C: nop

L_80005B10:
    // 0x80005B10: lw          $t5, 0x1CC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1CC);
    // 0x80005B14: addiu       $a1, $sp, 0x1C4
    ctx->r5 = ADD32(ctx->r29, 0X1C4);
    // 0x80005B18: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80005B1C: jal         0x800C143C
    // 0x80005B20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_15;
    // 0x80005B20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80005B24: lw          $t3, 0x1C4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C4);
    // 0x80005B28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005B2C: lh          $s0, 0x0($t3)
    ctx->r16 = MEM_H(ctx->r11, 0X0);
    // 0x80005B30: nop

    // 0x80005B34: beq         $s0, $at, L_80005B74
    if (ctx->r16 == ctx->r1) {
        // 0x80005B38: nop

            goto L_80005B74;
    }
    // 0x80005B38: nop

    // 0x80005B3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80005B40: beq         $s0, $at, L_80005EB0
    if (ctx->r16 == ctx->r1) {
        // 0x80005B44: nop

            goto L_80005EB0;
    }
    // 0x80005B44: nop

    // 0x80005B48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80005B4C: beq         $s0, $at, L_800060F4
    if (ctx->r16 == ctx->r1) {
        // 0x80005B50: nop

            goto L_800060F4;
    }
    // 0x80005B50: nop

    // 0x80005B54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80005B58: beq         $s0, $at, L_800060DC
    if (ctx->r16 == ctx->r1) {
        // 0x80005B5C: nop

            goto L_800060DC;
    }
    // 0x80005B5C: nop

    // 0x80005B60: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80005B64: beq         $s0, $at, L_80005F10
    if (ctx->r16 == ctx->r1) {
        // 0x80005B68: nop

            goto L_80005F10;
    }
    // 0x80005B68: nop

    // 0x80005B6C: b           L_800060FC
    // 0x80005B70: nop

        goto L_800060FC;
    // 0x80005B70: nop

L_80005B74:
    // 0x80005B74: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005B78: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80005B7C: lhu         $t4, 0x0($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X0);
    // 0x80005B80: nop

    // 0x80005B84: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80005B88: bne         $t7, $zero, L_80005EA8
    if (ctx->r15 != 0) {
        // 0x80005B8C: nop

            goto L_80005EA8;
    }
    // 0x80005B8C: nop

    // 0x80005B90: lw          $t8, 0x1C8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005B94: nop

    // 0x80005B98: addiu       $t9, $t8, 0x7FFF
    ctx->r25 = ADD32(ctx->r24, 0X7FFF);
    // 0x80005B9C: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x80005BA0: nop

    // 0x80005BA4: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80005BA8: beq         $at, $zero, L_80005EA8
    if (ctx->r1 == 0) {
        // 0x80005BAC: nop

            goto L_80005EA8;
    }
    // 0x80005BAC: nop

    // 0x80005BB0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80005BB4: lw          $t0, 0x258C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X258C);
    // 0x80005BB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80005BBC: sw          $t0, 0x30AC($at)
    MEM_W(0X30AC, ctx->r1) = ctx->r8;
    // 0x80005BC0: jal         0x80099768
    // 0x80005BC4: nop

    func_80099768(rdram, ctx);
        goto after_16;
    // 0x80005BC4: nop

    after_16:
    // 0x80005BC8: jal         0x800AFB28
    // 0x80005BCC: nop

    func_800AFB28(rdram, ctx);
        goto after_17;
    // 0x80005BCC: nop

    after_17:
    // 0x80005BD0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80005BD4: lw          $t1, -0x4CC4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4CC4);
    // 0x80005BD8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80005BDC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80005BE0: lw          $t2, -0x4CCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CCC);
    // 0x80005BE4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005BE8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80005BEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80005BF0: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x80005BF4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80005BF8: jal         0x800BE510
    // 0x80005BFC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800BE510(rdram, ctx);
        goto after_18;
    // 0x80005BFC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_18:
    // 0x80005C00: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80005C04: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80005C08: lw          $t3, -0x4CC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CC4);
    // 0x80005C0C: lw          $t5, -0x4CCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4CCC);
    // 0x80005C10: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80005C14: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80005C18: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80005C1C: jal         0x8009A04C
    // 0x80005C20: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_8009A04C(rdram, ctx);
        goto after_19;
    // 0x80005C20: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_19:
    // 0x80005C24: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005C28: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80005C2C: lhu         $t4, 0x0($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X0);
    // 0x80005C30: nop

    // 0x80005C34: andi        $t7, $t4, 0x8
    ctx->r15 = ctx->r12 & 0X8;
    // 0x80005C38: beq         $t7, $zero, L_80005C48
    if (ctx->r15 == 0) {
        // 0x80005C3C: nop

            goto L_80005C48;
    }
    // 0x80005C3C: nop

    // 0x80005C40: jal         0x80033788
    // 0x80005C44: nop

    func_80033788(rdram, ctx);
        goto after_20;
    // 0x80005C44: nop

    after_20:
L_80005C48:
    // 0x80005C48: jal         0x80032604
    // 0x80005C4C: nop

    func_80032604(rdram, ctx);
        goto after_21;
    // 0x80005C4C: nop

    after_21:
    // 0x80005C50: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80005C54: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80005C58: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x80005C5C: nop

    // 0x80005C60: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80005C64: beq         $t0, $zero, L_80005CA8
    if (ctx->r8 == 0) {
        // 0x80005C68: nop

            goto L_80005CA8;
    }
    // 0x80005C68: nop

    // 0x80005C6C: jal         0x80083700
    // 0x80005C70: nop

    func_80083700(rdram, ctx);
        goto after_22;
    // 0x80005C70: nop

    after_22:
    // 0x80005C74: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80005C78: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80005C7C: lhu         $t1, 0x4($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X4);
    // 0x80005C80: nop

    // 0x80005C84: andi        $t5, $t1, 0x8
    ctx->r13 = ctx->r9 & 0X8;
    // 0x80005C88: beq         $t5, $zero, L_80005CA0
    if (ctx->r13 == 0) {
        // 0x80005C8C: nop

            goto L_80005CA0;
    }
    // 0x80005C8C: nop

    // 0x80005C90: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80005C94: sw          $t3, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r11;
    // 0x80005C98: b           L_80006104
    // 0x80005C9C: nop

        goto L_80006104;
    // 0x80005C9C: nop

L_80005CA0:
    // 0x80005CA0: b           L_80005CD4
    // 0x80005CA4: nop

        goto L_80005CD4;
    // 0x80005CA4: nop

L_80005CA8:
    // 0x80005CA8: jal         0x80079CCC
    // 0x80005CAC: nop

    func_80079CCC(rdram, ctx);
        goto after_23;
    // 0x80005CAC: nop

    after_23:
    // 0x80005CB0: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80005CB4: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80005CB8: lhu         $t4, 0x4($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X4);
    // 0x80005CBC: nop

    // 0x80005CC0: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80005CC4: beq         $t7, $zero, L_80005CD4
    if (ctx->r15 == 0) {
        // 0x80005CC8: nop

            goto L_80005CD4;
    }
    // 0x80005CC8: nop

    // 0x80005CCC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80005CD0: sw          $t8, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r24;
L_80005CD4:
    // 0x80005CD4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80005CD8: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80005CDC: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x80005CE0: nop

    // 0x80005CE4: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x80005CE8: bne         $t2, $zero, L_80005D00
    if (ctx->r10 != 0) {
        // 0x80005CEC: nop

            goto L_80005D00;
    }
    // 0x80005CEC: nop

    // 0x80005CF0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005CF4: addiu       $a0, $a0, 0x7340
    ctx->r4 = ADD32(ctx->r4, 0X7340);
    // 0x80005CF8: jal         0x8000262C
    // 0x80005CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000262C(rdram, ctx);
        goto after_24;
    // 0x80005CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
L_80005D00:
    // 0x80005D00: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80005D04: addiu       $a0, $a0, -0x71B0
    ctx->r4 = ADD32(ctx->r4, -0X71B0);
    // 0x80005D08: jal         0x8000262C
    // 0x80005D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000262C(rdram, ctx);
        goto after_25;
    // 0x80005D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80005D10: jal         0x80002824
    // 0x80005D14: nop

    func_80002824(rdram, ctx);
        goto after_26;
    // 0x80005D14: nop

    after_26:
    // 0x80005D18: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80005D1C: lh          $t1, 0x721C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X721C);
    // 0x80005D20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005D24: beq         $t1, $at, L_80005D38
    if (ctx->r9 == ctx->r1) {
        // 0x80005D28: nop

            goto L_80005D38;
    }
    // 0x80005D28: nop

    // 0x80005D2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80005D30: bne         $t1, $at, L_80005D40
    if (ctx->r9 != ctx->r1) {
        // 0x80005D34: nop

            goto L_80005D40;
    }
    // 0x80005D34: nop

L_80005D38:
    // 0x80005D38: jal         0x80034310
    // 0x80005D3C: nop

    func_80034310(rdram, ctx);
        goto after_27;
    // 0x80005D3C: nop

    after_27:
L_80005D40:
    // 0x80005D40: jal         0x800305A4
    // 0x80005D44: nop

    func_800305A4(rdram, ctx);
        goto after_28;
    // 0x80005D44: nop

    after_28:
    // 0x80005D48: jal         0x8002A39C
    // 0x80005D4C: nop

    func_8002A39C(rdram, ctx);
        goto after_29;
    // 0x80005D4C: nop

    after_29:
    // 0x80005D50: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80005D54: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80005D58: lhu         $t3, 0x6($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X6);
    // 0x80005D5C: nop

    // 0x80005D60: andi        $t6, $t3, 0x8000
    ctx->r14 = ctx->r11 & 0X8000;
    // 0x80005D64: bne         $t6, $zero, L_80005D7C
    if (ctx->r14 != 0) {
        // 0x80005D68: nop

            goto L_80005D7C;
    }
    // 0x80005D68: nop

    // 0x80005D6C: jal         0x8004DEA4
    // 0x80005D70: nop

    func_8004DEA4(rdram, ctx);
        goto after_30;
    // 0x80005D70: nop

    after_30:
    // 0x80005D74: jal         0x80082958
    // 0x80005D78: nop

    func_80082958(rdram, ctx);
        goto after_31;
    // 0x80005D78: nop

    after_31:
L_80005D7C:
    // 0x80005D7C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80005D80: lw          $t4, -0x73AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73AC);
    // 0x80005D84: nop

    // 0x80005D88: beq         $t4, $zero, L_80005DDC
    if (ctx->r12 == 0) {
        // 0x80005D8C: sw          $t4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r12;
            goto L_80005DDC;
    }
    // 0x80005D8C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80005D90:
    // 0x80005D90: jal         0x800C1754
    // 0x80005D94: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_32;
    // 0x80005D94: nop

    after_32:
    // 0x80005D98: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80005D9C: jal         0x8009A14C
    // 0x80005DA0: nop

    func_8009A14C(rdram, ctx);
        goto after_33;
    // 0x80005DA0: nop

    after_33:
    // 0x80005DA4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80005DA8: jal         0x800997D8
    // 0x80005DAC: nop

    func_800997D8(rdram, ctx);
        goto after_34;
    // 0x80005DAC: nop

    after_34:
    // 0x80005DB0: jal         0x800C1A28
    // 0x80005DB4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_35;
    // 0x80005DB4: nop

    after_35:
    // 0x80005DB8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80005DBC: nop

    // 0x80005DC0: lw          $t8, 0x14C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14C);
    // 0x80005DC4: nop

    // 0x80005DC8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80005DCC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80005DD0: nop

    // 0x80005DD4: bne         $t9, $zero, L_80005D90
    if (ctx->r25 != 0) {
        // 0x80005DD8: nop

            goto L_80005D90;
    }
    // 0x80005DD8: nop

L_80005DDC:
    // 0x80005DDC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80005DE0: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80005DE4: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    // 0x80005DE8: nop

    // 0x80005DEC: andi        $t1, $t2, 0x100
    ctx->r9 = ctx->r10 & 0X100;
    // 0x80005DF0: bne         $t1, $zero, L_80005E14
    if (ctx->r9 != 0) {
        // 0x80005DF4: nop

            goto L_80005E14;
    }
    // 0x80005DF4: nop

    // 0x80005DF8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005DFC: jal         0x8009A664
    // 0x80005E00: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_36;
    // 0x80005E00: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_36:
    // 0x80005E04: jal         0x8002C2F8
    // 0x80005E08: nop

    func_8002C2F8(rdram, ctx);
        goto after_37;
    // 0x80005E08: nop

    after_37:
    // 0x80005E0C: b           L_80005E28
    // 0x80005E10: nop

        goto L_80005E28;
    // 0x80005E10: nop

L_80005E14:
    // 0x80005E14: jal         0x8002C2F8
    // 0x80005E18: nop

    func_8002C2F8(rdram, ctx);
        goto after_38;
    // 0x80005E18: nop

    after_38:
    // 0x80005E1C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005E20: jal         0x8009A664
    // 0x80005E24: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_39;
    // 0x80005E24: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_39:
L_80005E28:
    // 0x80005E28: jal         0x8001635C
    // 0x80005E2C: nop

    func_8001635C(rdram, ctx);
        goto after_40;
    // 0x80005E2C: nop

    after_40:
    // 0x80005E30: jal         0x800BE684
    // 0x80005E34: nop

    func_800BE684(rdram, ctx);
        goto after_41;
    // 0x80005E34: nop

    after_41:
    // 0x80005E38: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80005E3C: jal         0x8009A664
    // 0x80005E40: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_42;
    // 0x80005E40: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_42:
    // 0x80005E44: jal         0x800BE610
    // 0x80005E48: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_43;
    // 0x80005E48: nop

    after_43:
    // 0x80005E4C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80005E50: lw          $t5, 0x1B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1B4C);
    // 0x80005E54: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80005E58: lw          $t3, 0x1B44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1B44);
    // 0x80005E5C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80005E60: jal         0x8009908C
    // 0x80005E64: subu        $a1, $t3, $t5
    ctx->r5 = SUB32(ctx->r11, ctx->r13);
    CreateGfxTask(rdram, ctx);
        goto after_44;
    // 0x80005E64: subu        $a1, $t3, $t5
    ctx->r5 = SUB32(ctx->r11, ctx->r13);
    after_44:
    // 0x80005E68: lw          $t6, 0x1CC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1CC);
    // 0x80005E6C: nop

    // 0x80005E70: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80005E74: jal         0x80098D24
    // 0x80005E78: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_45;
    // 0x80005E78: nop

    after_45:
    // 0x80005E7C: jal         0x80099450
    // 0x80005E80: nop

    func_80099450(rdram, ctx);
        goto after_46;
    // 0x80005E80: nop

    after_46:
    // 0x80005E84: jal         0x80001F54
    // 0x80005E88: nop

    func_80001F54(rdram, ctx);
        goto after_47;
    // 0x80005E88: nop

    after_47:
    // 0x80005E8C: lw          $t4, 0x1C8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005E90: nop

    // 0x80005E94: addiu       $t7, $t4, 0x7FFF
    ctx->r15 = ADD32(ctx->r12, 0X7FFF);
    // 0x80005E98: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x80005E9C: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80005EA0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80005EA4: sw          $t8, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r24;
L_80005EA8:
    // 0x80005EA8: b           L_80006104
    // 0x80005EAC: nop

        goto L_80006104;
    // 0x80005EAC: nop

L_80005EB0:
    // 0x80005EB0: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005EB4: nop

    // 0x80005EB8: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x80005EBC: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x80005EC0: nop

    // 0x80005EC4: beq         $t0, $zero, L_80005F08
    if (ctx->r8 == 0) {
        // 0x80005EC8: nop

            goto L_80005F08;
    }
    // 0x80005EC8: nop

    // 0x80005ECC: jal         0x80099520
    // 0x80005ED0: nop

    func_80099520(rdram, ctx);
        goto after_48;
    // 0x80005ED0: nop

    after_48:
    // 0x80005ED4: lw          $t2, 0x1C8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005ED8: nop

    // 0x80005EDC: addiu       $t1, $t2, 0x7FFF
    ctx->r9 = ADD32(ctx->r10, 0X7FFF);
    // 0x80005EE0: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x80005EE4: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x80005EE8: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x80005EEC: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x80005EF0: jal         0x800C40D0
    // 0x80005EF4: nop

    osGetTime_recomp(rdram, ctx);
        goto after_49;
    // 0x80005EF4: nop

    after_49:
    // 0x80005EF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80005EFC: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x80005F00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80005F04: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
L_80005F08:
    // 0x80005F08: b           L_80006104
    // 0x80005F0C: nop

        goto L_80006104;
    // 0x80005F0C: nop

L_80005F10:
    // 0x80005F10: lw          $t5, 0x1C8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005F14: nop

    // 0x80005F18: addiu       $t6, $t5, 0x7FFF
    ctx->r14 = ADD32(ctx->r13, 0X7FFF);
    // 0x80005F1C: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x80005F20: nop

    // 0x80005F24: blez        $t6, L_80005FA8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80005F28: nop

            goto L_80005FA8;
    }
    // 0x80005F28: nop

L_80005F2C:
    // 0x80005F2C: lw          $t7, 0x1CC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1CC);
    // 0x80005F30: addiu       $a1, $sp, 0x1C4
    ctx->r5 = ADD32(ctx->r29, 0X1C4);
    // 0x80005F34: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80005F38: jal         0x800C143C
    // 0x80005F3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_50;
    // 0x80005F3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_50:
    // 0x80005F40: lw          $t8, 0x1C4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C4);
    // 0x80005F44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80005F48: lh          $t4, 0x0($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X0);
    // 0x80005F4C: nop

    // 0x80005F50: bne         $t4, $at, L_80005F8C
    if (ctx->r12 != ctx->r1) {
        // 0x80005F54: nop

            goto L_80005F8C;
    }
    // 0x80005F54: nop

    // 0x80005F58: b           L_80005F60
    // 0x80005F5C: nop

        goto L_80005F60;
    // 0x80005F5C: nop

L_80005F60:
    // 0x80005F60: jal         0x80099520
    // 0x80005F64: nop

    func_80099520(rdram, ctx);
        goto after_51;
    // 0x80005F64: nop

    after_51:
    // 0x80005F68: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005F6C: nop

    // 0x80005F70: addiu       $t0, $t9, 0x7FFF
    ctx->r8 = ADD32(ctx->r25, 0X7FFF);
    // 0x80005F74: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x80005F78: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80005F7C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80005F80: sw          $t1, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r9;
    // 0x80005F84: b           L_80005F8C
    // 0x80005F88: nop

        goto L_80005F8C;
    // 0x80005F88: nop

L_80005F8C:
    // 0x80005F8C: lw          $t3, 0x1C8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C8);
    // 0x80005F90: nop

    // 0x80005F94: addiu       $t2, $t3, 0x7FFF
    ctx->r10 = ADD32(ctx->r11, 0X7FFF);
    // 0x80005F98: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x80005F9C: nop

    // 0x80005FA0: bgtz        $t2, L_80005F2C
    if (SIGNED(ctx->r10) > 0) {
        // 0x80005FA4: nop

            goto L_80005F2C;
    }
    // 0x80005FA4: nop

L_80005FA8:
    // 0x80005FA8: jal         0x80098820
    // 0x80005FAC: nop

    func_80098820(rdram, ctx);
        goto after_52;
    // 0x80005FAC: nop

    after_52:
    // 0x80005FB0: jal         0x80098868
    // 0x80005FB4: nop

    func_80098868(rdram, ctx);
        goto after_53;
    // 0x80005FB4: nop

    after_53:
    // 0x80005FB8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005FBC: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80005FC0: jal         0x800A6670
    // 0x80005FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_54;
    // 0x80005FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
    // 0x80005FC8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005FCC: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80005FD0: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80005FD4: jal         0x800A6670
    // 0x80005FD8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_55;
    // 0x80005FD8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_55:
    // 0x80005FDC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80005FE0: lw          $a1, -0x73E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73E8);
    // 0x80005FE4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80005FE8: jal         0x800BCFCC
    // 0x80005FEC: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    SysMem_Copy8(rdram, ctx);
        goto after_56;
    // 0x80005FEC: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    after_56:
    // 0x80005FF0: lw          $t5, 0x1D0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D0);
    // 0x80005FF4: nop

    // 0x80005FF8: bne         $t5, $zero, L_80006008
    if (ctx->r13 != 0) {
        // 0x80005FFC: nop

            goto L_80006008;
    }
    // 0x80005FFC: nop

    // 0x80006000: jal         0x80005460
    // 0x80006004: nop

    func_80005460(rdram, ctx);
        goto after_57;
    // 0x80006004: nop

    after_57:
L_80006008:
    // 0x80006008: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000600C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80006010: lh          $a1, 0x72B4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X72B4);
    // 0x80006014: lh          $a0, 0x72AC($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X72AC);
    // 0x80006018: jal         0x80005124
    // 0x8000601C: nop

    func_80005124(rdram, ctx);
        goto after_58;
    // 0x8000601C: nop

    after_58:
    // 0x80006020: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
    // 0x80006024: lw          $t6, 0x1D0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D0);
    // 0x80006028: nop

    // 0x8000602C: bne         $t6, $zero, L_80006040
    if (ctx->r14 != 0) {
        // 0x80006030: nop

            goto L_80006040;
    }
    // 0x80006030: nop

    // 0x80006034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80006038: jal         0x800A6F20
    // 0x8000603C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800A6F20(rdram, ctx);
        goto after_59;
    // 0x8000603C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_59:
L_80006040:
    // 0x80006040: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80006044: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x80006048: lwc1        $f16, 0x104($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8000604C: nop

    // 0x80006050: swc1        $f16, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f16.u32l;
    // 0x80006054: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80006058: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8000605C: lwc1        $f18, 0x108($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80006060: nop

    // 0x80006064: swc1        $f18, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f18.u32l;
    // 0x80006068: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000606C: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80006070: lhu         $t0, 0x4($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0X4);
    // 0x80006074: nop

    // 0x80006078: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x8000607C: beq         $t1, $zero, L_80006094
    if (ctx->r9 == 0) {
        // 0x80006080: nop

            goto L_80006094;
    }
    // 0x80006080: nop

    // 0x80006084: jal         0x80083E28
    // 0x80006088: nop

    func_80083E28(rdram, ctx);
        goto after_60;
    // 0x80006088: nop

    after_60:
    // 0x8000608C: b           L_8000609C
    // 0x80006090: nop

        goto L_8000609C;
    // 0x80006090: nop

L_80006094:
    // 0x80006094: jal         0x8007A0B0
    // 0x80006098: nop

    func_8007A0B0(rdram, ctx);
        goto after_61;
    // 0x80006098: nop

    after_61:
L_8000609C:
    // 0x8000609C: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x800060A0: nop

    // 0x800060A4: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x800060A8: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x800060AC: lw          $t3, 0x1CC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1CC);
    // 0x800060B0: nop

    // 0x800060B4: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x800060B8: jal         0x800C13B8
    // 0x800060BC: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_62;
    // 0x800060BC: nop

    after_62:
    // 0x800060C0: jal         0x80098820
    // 0x800060C4: nop

    func_80098820(rdram, ctx);
        goto after_63;
    // 0x800060C4: nop

    after_63:
    // 0x800060C8: lw          $t2, 0x1CC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1CC);
    // 0x800060CC: nop

    // 0x800060D0: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800060D4: b           L_80006104
    // 0x800060D8: nop

        goto L_80006104;
    // 0x800060D8: nop

L_800060DC:
    // 0x800060DC: jal         0x800029BC
    // 0x800060E0: nop

    func_800029BC(rdram, ctx);
        goto after_64;
    // 0x800060E0: nop

    after_64:
L_800060E4:
    // 0x800060E4: b           L_800060E4
    pause_self(rdram);
    // 0x800060E8: nop

    // 0x800060EC: b           L_80006104
    // 0x800060F0: nop

        goto L_80006104;
    // 0x800060F0: nop

L_800060F4:
    // 0x800060F4: b           L_80006104
    // 0x800060F8: nop

        goto L_80006104;
    // 0x800060F8: nop

L_800060FC:
    // 0x800060FC: b           L_80006104
    // 0x80006100: nop

        goto L_80006104;
    // 0x80006100: nop

L_80006104:
    // 0x80006104: lw          $t5, 0x1D8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D8);
    // 0x80006108: nop

    // 0x8000610C: beq         $t5, $zero, L_80005B10
    if (ctx->r13 == 0) {
        // 0x80006110: nop

            goto L_80005B10;
    }
    // 0x80006110: nop

L_80006114:
    // 0x80006114: lw          $t6, 0x1C8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C8);
    // 0x80006118: nop

    // 0x8000611C: addiu       $t7, $t6, 0x7FFF
    ctx->r15 = ADD32(ctx->r14, 0X7FFF);
    // 0x80006120: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x80006124: nop

    // 0x80006128: blez        $t7, L_800061AC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000612C: nop

            goto L_800061AC;
    }
    // 0x8000612C: nop

L_80006130:
    // 0x80006130: lw          $t8, 0x1CC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1CC);
    // 0x80006134: addiu       $a1, $sp, 0x1C4
    ctx->r5 = ADD32(ctx->r29, 0X1C4);
    // 0x80006138: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8000613C: jal         0x800C143C
    // 0x80006140: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_65;
    // 0x80006140: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_65:
    // 0x80006144: lw          $t4, 0x1C4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000614C: lh          $t0, 0x0($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X0);
    // 0x80006150: nop

    // 0x80006154: bne         $t0, $at, L_80006190
    if (ctx->r8 != ctx->r1) {
        // 0x80006158: nop

            goto L_80006190;
    }
    // 0x80006158: nop

    // 0x8000615C: b           L_80006164
    // 0x80006160: nop

        goto L_80006164;
    // 0x80006160: nop

L_80006164:
    // 0x80006164: jal         0x80099520
    // 0x80006168: nop

    func_80099520(rdram, ctx);
        goto after_66;
    // 0x80006168: nop

    after_66:
    // 0x8000616C: lw          $t1, 0x1C8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C8);
    // 0x80006170: nop

    // 0x80006174: addiu       $t9, $t1, 0x7FFF
    ctx->r25 = ADD32(ctx->r9, 0X7FFF);
    // 0x80006178: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x8000617C: addiu       $at, $t1, 0x7FFF
    ctx->r1 = ADD32(ctx->r9, 0X7FFF);
    // 0x80006180: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80006184: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x80006188: b           L_80006190
    // 0x8000618C: nop

        goto L_80006190;
    // 0x8000618C: nop

L_80006190:
    // 0x80006190: lw          $t2, 0x1C8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C8);
    // 0x80006194: nop

    // 0x80006198: addiu       $t5, $t2, 0x7FFF
    ctx->r13 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000619C: lw          $t5, 0x2ED($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2ED);
    // 0x800061A0: nop

    // 0x800061A4: bgtz        $t5, L_80006130
    if (SIGNED(ctx->r13) > 0) {
        // 0x800061A8: nop

            goto L_80006130;
    }
    // 0x800061A8: nop

L_800061AC:
    // 0x800061AC: jal         0x80098820
    // 0x800061B0: nop

    func_80098820(rdram, ctx);
        goto after_67;
    // 0x800061B0: nop

    after_67:
    // 0x800061B4: jal         0x80098868
    // 0x800061B8: nop

    func_80098868(rdram, ctx);
        goto after_68;
    // 0x800061B8: nop

    after_68:
    // 0x800061BC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x800061C0: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x800061C4: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x800061C8: nop

    // 0x800061CC: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x800061D0: beq         $t8, $zero, L_800061E8
    if (ctx->r24 == 0) {
        // 0x800061D4: nop

            goto L_800061E8;
    }
    // 0x800061D4: nop

    // 0x800061D8: jal         0x80083AD0
    // 0x800061DC: nop

    func_80083AD0(rdram, ctx);
        goto after_69;
    // 0x800061DC: nop

    after_69:
    // 0x800061E0: b           L_800061F0
    // 0x800061E4: nop

        goto L_800061F0;
    // 0x800061E4: nop

L_800061E8:
    // 0x800061E8: jal         0x80079F34
    // 0x800061EC: nop

    func_80079F34(rdram, ctx);
        goto after_70;
    // 0x800061EC: nop

    after_70:
L_800061F0:
    // 0x800061F0: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800061F4: lbu         $t4, 0x125A($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X125A);
    // 0x800061F8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800061FC: and         $t0, $t4, $at
    ctx->r8 = ctx->r12 & ctx->r1;
    // 0x80006200: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80006204: sb          $t0, 0x125A($at)
    MEM_B(0X125A, ctx->r1) = ctx->r8;
    // 0x80006208: lw          $t9, 0x1D0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D0);
    // 0x8000620C: nop

    // 0x80006210: bne         $t9, $zero, L_80006244
    if (ctx->r25 != 0) {
        // 0x80006214: nop

            goto L_80006244;
    }
    // 0x80006214: nop

    // 0x80006218: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000621C: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80006220: jal         0x800A6670
    // 0x80006224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_71;
    // 0x80006224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_71:
    // 0x80006228: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000622C: addiu       $a1, $a1, -0x71B0
    ctx->r5 = ADD32(ctx->r5, -0X71B0);
    // 0x80006230: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80006234: jal         0x800A6670
    // 0x80006238: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_72;
    // 0x80006238: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_72:
    // 0x8000623C: jal         0x80005460
    // 0x80006240: nop

    func_80005460(rdram, ctx);
        goto after_73;
    // 0x80006240: nop

    after_73:
L_80006244:
    // 0x80006244: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80006248: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x8000624C: jal         0x800A6670
    // 0x80006250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_74;
    // 0x80006250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_74:
    // 0x80006254: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80006258: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x8000625C: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80006260: jal         0x800A6670
    // 0x80006264: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_75;
    // 0x80006264: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_75:
    // 0x80006268: lw          $t3, 0x1CC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1CC);
    // 0x8000626C: nop

    // 0x80006270: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x80006274: jal         0x800C13B8
    // 0x80006278: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_76;
    // 0x80006278: nop

    after_76:
    // 0x8000627C: jal         0x80098820
    // 0x80006280: nop

    func_80098820(rdram, ctx);
        goto after_77;
    // 0x80006280: nop

    after_77:
    // 0x80006284: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80006288: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000628C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80006290: addiu       $at, $zero, -0x45
    ctx->r1 = ADD32(0, -0X45);
    // 0x80006294: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x80006298: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
    // 0x8000629C: b           L_800062A4
    // 0x800062A0: nop

        goto L_800062A4;
    // 0x800062A0: nop

L_800062A4:
    // 0x800062A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800062A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800062AC: jr          $ra
    // 0x800062B0: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    return;
    // 0x800062B0: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    // 0x800062B4: nop

    // 0x800062B8: nop

    // 0x800062BC: nop

;}
RECOMP_FUNC void func_800062C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800062C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800062C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800062C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800062CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800062D0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800062D4: lw          $t6, 0x648($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X648);
    // 0x800062D8: nop

    // 0x800062DC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800062E0: jal         0x80096474
    // 0x800062E4: nop

    func_80096474(rdram, ctx);
        goto after_0;
    // 0x800062E4: nop

    after_0:
    // 0x800062E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800062EC: nop

    // 0x800062F0: lw          $a0, 0x128($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X128);
    // 0x800062F4: jal         0x8008ECCC
    // 0x800062F8: nop

    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_1;
    // 0x800062F8: nop

    after_1:
    // 0x800062FC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80006300: nop

    // 0x80006304: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x80006308: lh          $t0, 0x102($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X102);
    // 0x8000630C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80006310: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80006314: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006318: jal         0x8008EC8C
    // 0x8000631C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_8008EC8C(rdram, ctx);
        goto after_2;
    // 0x8000631C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_2:
    // 0x80006320: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80006324: nop

    // 0x80006328: lh          $t2, 0x100($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X100);
    // 0x8000632C: lh          $t3, 0x102($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X102);
    // 0x80006330: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80006334: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80006338: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000633C: jal         0x8008ECAC
    // 0x80006340: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_8008ECAC(rdram, ctx);
        goto after_3;
    // 0x80006340: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_3:
    // 0x80006344: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80006348: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000634C: sw          $t4, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r12;
    // 0x80006350: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80006354: lw          $t6, -0x4CE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CE0);
    // 0x80006358: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000635C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80006360: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80006364: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80006368: sh          $t5, -0x44B8($at)
    MEM_H(-0X44B8, ctx->r1) = ctx->r13;
    // 0x8000636C: jal         0x80090754
    // 0x80006370: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    func_80090754(rdram, ctx);
        goto after_4;
    // 0x80006370: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    after_4:
    // 0x80006374: jal         0x80090728
    // 0x80006378: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    func_80090728(rdram, ctx);
        goto after_5;
    // 0x80006378: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_5:
    // 0x8000637C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80006380:
    // 0x80006380: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80006384: nop

    // 0x80006388: bne         $t9, $zero, L_800063A4
    if (ctx->r25 != 0) {
        // 0x8000638C: nop

            goto L_800063A4;
    }
    // 0x8000638C: nop

    // 0x80006390: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006394: jal         0x8008EAA8
    // 0x80006398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008EAA8(rdram, ctx);
        goto after_6;
    // 0x80006398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8000639C: b           L_80006470
    // 0x800063A0: nop

        goto L_80006470;
    // 0x800063A0: nop

L_800063A4:
    // 0x800063A4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800063A8: nop

    // 0x800063AC: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800063B0: bne         $at, $zero, L_800063DC
    if (ctx->r1 != 0) {
        // 0x800063B4: nop

            goto L_800063DC;
    }
    // 0x800063B4: nop

    // 0x800063B8: slti        $at, $t8, 0xC
    ctx->r1 = SIGNED(ctx->r24) < 0XC ? 1 : 0;
    // 0x800063BC: beq         $at, $zero, L_800063DC
    if (ctx->r1 == 0) {
        // 0x800063C0: nop

            goto L_800063DC;
    }
    // 0x800063C0: nop

    // 0x800063C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800063C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800063CC: jal         0x8008EAA8
    // 0x800063D0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    func_8008EAA8(rdram, ctx);
        goto after_7;
    // 0x800063D0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_7:
    // 0x800063D4: b           L_80006470
    // 0x800063D8: nop

        goto L_80006470;
    // 0x800063D8: nop

L_800063DC:
    // 0x800063DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800063E0: nop

    // 0x800063E4: slti        $at, $t0, 0xC
    ctx->r1 = SIGNED(ctx->r8) < 0XC ? 1 : 0;
    // 0x800063E8: bne         $at, $zero, L_80006414
    if (ctx->r1 != 0) {
        // 0x800063EC: nop

            goto L_80006414;
    }
    // 0x800063EC: nop

    // 0x800063F0: slti        $at, $t0, 0x18
    ctx->r1 = SIGNED(ctx->r8) < 0X18 ? 1 : 0;
    // 0x800063F4: beq         $at, $zero, L_80006414
    if (ctx->r1 == 0) {
        // 0x800063F8: nop

            goto L_80006414;
    }
    // 0x800063F8: nop

    // 0x800063FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80006400: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80006404: jal         0x8008EAA8
    // 0x80006408: addiu       $a1, $a1, -0x7
    ctx->r5 = ADD32(ctx->r5, -0X7);
    func_8008EAA8(rdram, ctx);
        goto after_8;
    // 0x80006408: addiu       $a1, $a1, -0x7
    ctx->r5 = ADD32(ctx->r5, -0X7);
    after_8:
    // 0x8000640C: b           L_80006470
    // 0x80006410: nop

        goto L_80006470;
    // 0x80006410: nop

L_80006414:
    // 0x80006414: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80006418: nop

    // 0x8000641C: slti        $at, $t2, 0x18
    ctx->r1 = SIGNED(ctx->r10) < 0X18 ? 1 : 0;
    // 0x80006420: bne         $at, $zero, L_8000644C
    if (ctx->r1 != 0) {
        // 0x80006424: nop

            goto L_8000644C;
    }
    // 0x80006424: nop

    // 0x80006428: slti        $at, $t2, 0x1C
    ctx->r1 = SIGNED(ctx->r10) < 0X1C ? 1 : 0;
    // 0x8000642C: beq         $at, $zero, L_8000644C
    if (ctx->r1 == 0) {
        // 0x80006430: nop

            goto L_8000644C;
    }
    // 0x80006430: nop

    // 0x80006434: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80006438: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8000643C: jal         0x8008EAA8
    // 0x80006440: addiu       $a1, $a1, -0x13
    ctx->r5 = ADD32(ctx->r5, -0X13);
    func_8008EAA8(rdram, ctx);
        goto after_9;
    // 0x80006440: addiu       $a1, $a1, -0x13
    ctx->r5 = ADD32(ctx->r5, -0X13);
    after_9:
    // 0x80006444: b           L_80006470
    // 0x80006448: nop

        goto L_80006470;
    // 0x80006448: nop

L_8000644C:
    // 0x8000644C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80006450: nop

    // 0x80006454: slti        $at, $t1, 0x1C
    ctx->r1 = SIGNED(ctx->r9) < 0X1C ? 1 : 0;
    // 0x80006458: bne         $at, $zero, L_80006470
    if (ctx->r1 != 0) {
        // 0x8000645C: nop

            goto L_80006470;
    }
    // 0x8000645C: nop

    // 0x80006460: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80006464: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80006468: jal         0x8008EAA8
    // 0x8000646C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    func_8008EAA8(rdram, ctx);
        goto after_10;
    // 0x8000646C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    after_10:
L_80006470:
    // 0x80006470: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80006474: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80006478: lw          $t9, -0x6080($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6080);
    // 0x8000647C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80006480: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80006484: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80006488: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8000648C: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80006490: lh          $t0, 0x0($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X0);
    // 0x80006494: nop

    // 0x80006498: bne         $t7, $t0, L_800064CC
    if (ctx->r15 != ctx->r8) {
        // 0x8000649C: nop

            goto L_800064CC;
    }
    // 0x8000649C: nop

    // 0x800064A0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800064A4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800064A8: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x800064AC: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x800064B0: lh          $a2, 0x0($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X0);
    // 0x800064B4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800064B8: addiu       $a0, $a0, -0x2E80
    ctx->r4 = ADD32(ctx->r4, -0X2E80);
    // 0x800064BC: jal         0x8008ECE4
    // 0x800064C0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8008ECE4(rdram, ctx);
        goto after_11;
    // 0x800064C0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_11:
    // 0x800064C4: b           L_80006550
    // 0x800064C8: nop

        goto L_80006550;
    // 0x800064C8: nop

L_800064CC:
    // 0x800064CC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800064D0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800064D4: lw          $t5, -0x6080($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6080);
    // 0x800064D8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800064DC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800064E0: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800064E4: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x800064E8: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x800064EC: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x800064F0: nop

    // 0x800064F4: slt         $at, $t7, $t2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800064F8: beq         $at, $zero, L_8000652C
    if (ctx->r1 == 0) {
        // 0x800064FC: nop

            goto L_8000652C;
    }
    // 0x800064FC: nop

    // 0x80006500: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80006504: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80006508: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x8000650C: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x80006510: lh          $a2, 0x0($t5)
    ctx->r6 = MEM_H(ctx->r13, 0X0);
    // 0x80006514: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80006518: addiu       $a0, $a0, -0x2E74
    ctx->r4 = ADD32(ctx->r4, -0X2E74);
    // 0x8000651C: jal         0x8008ECE4
    // 0x80006520: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8008ECE4(rdram, ctx);
        goto after_12;
    // 0x80006520: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_12:
    // 0x80006524: b           L_80006550
    // 0x80006528: nop

        goto L_80006550;
    // 0x80006528: nop

L_8000652C:
    // 0x8000652C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80006530: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80006534: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x80006538: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x8000653C: lh          $a2, 0x0($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X0);
    // 0x80006540: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80006544: addiu       $a0, $a0, -0x2E68
    ctx->r4 = ADD32(ctx->r4, -0X2E68);
    // 0x80006548: jal         0x8008ECE4
    // 0x8000654C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8008ECE4(rdram, ctx);
        goto after_13;
    // 0x8000654C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
L_80006550:
    // 0x80006550: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80006554: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80006558: nop

    // 0x8000655C: bne         $t7, $t2, L_80006578
    if (ctx->r15 != ctx->r10) {
        // 0x80006560: nop

            goto L_80006578;
    }
    // 0x80006560: nop

    // 0x80006564: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80006568: jal         0x8008ECE4
    // 0x8000656C: addiu       $a0, $a0, -0x2E5C
    ctx->r4 = ADD32(ctx->r4, -0X2E5C);
    func_8008ECE4(rdram, ctx);
        goto after_14;
    // 0x8000656C: addiu       $a0, $a0, -0x2E5C
    ctx->r4 = ADD32(ctx->r4, -0X2E5C);
    after_14:
    // 0x80006570: b           L_80006584
    // 0x80006574: nop

        goto L_80006584;
    // 0x80006574: nop

L_80006578:
    // 0x80006578: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000657C: jal         0x8008ECE4
    // 0x80006580: addiu       $a0, $a0, -0x2E58
    ctx->r4 = ADD32(ctx->r4, -0X2E58);
    func_8008ECE4(rdram, ctx);
        goto after_15;
    // 0x80006580: addiu       $a0, $a0, -0x2E58
    ctx->r4 = ADD32(ctx->r4, -0X2E58);
    after_15:
L_80006584:
    // 0x80006584: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80006588: nop

    // 0x8000658C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80006590: slti        $at, $t4, 0x2A
    ctx->r1 = SIGNED(ctx->r12) < 0X2A ? 1 : 0;
    // 0x80006594: bne         $at, $zero, L_80006380
    if (ctx->r1 != 0) {
        // 0x80006598: sw          $t4, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r12;
            goto L_80006380;
    }
    // 0x80006598: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8000659C: jal         0x800967D8
    // 0x800065A0: nop

    func_800967D8(rdram, ctx);
        goto after_16;
    // 0x800065A0: nop

    after_16:
    // 0x800065A4: b           L_800065AC
    // 0x800065A8: nop

        goto L_800065AC;
    // 0x800065A8: nop

L_800065AC:
    // 0x800065AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800065B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800065B4: jr          $ra
    // 0x800065B8: nop

    return;
    // 0x800065B8: nop

;}
RECOMP_FUNC void func_800065BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800065BC: addiu       $sp, $sp, -0x1D8
    ctx->r29 = ADD32(ctx->r29, -0X1D8);
    // 0x800065C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800065C4: sw          $a0, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->r4;
    // 0x800065C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800065CC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800065D0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800065D4: lw          $t6, 0x1D8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D8);
    // 0x800065D8: nop

    // 0x800065DC: sw          $t6, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r14;
    // 0x800065E0: lw          $t7, 0x1B8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1B8);
    // 0x800065E4: nop

    // 0x800065E8: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800065EC: nop

    // 0x800065F0: sw          $t8, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r24;
    // 0x800065F4: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800065F8: lwc1        $f4, 0x6190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6190);
    // 0x800065FC: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80006600: addiu       $t9, $t9, -0x5B58
    ctx->r25 = ADD32(ctx->r25, -0X5B58);
    // 0x80006604: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x80006608: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000660C: lwc1        $f6, 0x6194($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6194);
    // 0x80006610: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80006614: addiu       $t0, $t0, -0x5B58
    ctx->r8 = ADD32(ctx->r8, -0X5B58);
    // 0x80006618: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8000661C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80006620: lwc1        $f8, 0x6198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6198);
    // 0x80006624: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80006628: addiu       $t1, $t1, -0x5B58
    ctx->r9 = ADD32(ctx->r9, -0X5B58);
    // 0x8000662C: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x80006630: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80006634: lwc1        $f10, 0x619C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X619C);
    // 0x80006638: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8000663C: addiu       $t2, $t2, -0x5B58
    ctx->r10 = ADD32(ctx->r10, -0X5B58);
    // 0x80006640: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x80006644: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80006648: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8000664C: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x80006650: jal         0x800AC0A4
    // 0x80006654: addiu       $a3, $zero, 0xE1
    ctx->r7 = ADD32(0, 0XE1);
    func_800AC0A4(rdram, ctx);
        goto after_0;
    // 0x80006654: addiu       $a3, $zero, 0xE1
    ctx->r7 = ADD32(0, 0XE1);
    after_0:
    // 0x80006658: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000665C: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80006660: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80006664: nop

    // 0x80006668: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8000666C: beq         $t5, $zero, L_800068BC
    if (ctx->r13 == 0) {
        // 0x80006670: nop

            goto L_800068BC;
    }
    // 0x80006670: nop

    // 0x80006674: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80006678: addiu       $t6, $t6, 0x7340
    ctx->r14 = ADD32(ctx->r14, 0X7340);
    // 0x8000667C: addiu       $t7, $t6, 0x1080
    ctx->r15 = ADD32(ctx->r14, 0X1080);
    // 0x80006680: sw          $t7, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r15;
    // 0x80006684: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80006688: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000668C: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006690: nop

    // 0x80006694: swc1        $f16, 0xE8($t8)
    MEM_W(0XE8, ctx->r24) = ctx->f16.u32l;
    // 0x80006698: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8000669C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800066A0: lw          $t9, 0x1A8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A8);
    // 0x800066A4: nop

    // 0x800066A8: swc1        $f18, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->f18.u32l;
    // 0x800066AC: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x800066B0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800066B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800066B8: lwc1        $f4, 0xE8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x800066BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800066C0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800066C4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800066C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800066CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800066D0: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x800066D4: cvt.s.d     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f20.fl = CVT_S_D(ctx->f18.d);
    // 0x800066D8: swc1        $f20, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f20.u32l;
    // 0x800066DC: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x800066E0: nop

    // 0x800066E4: swc1        $f20, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f20.u32l;
    // 0x800066E8: lw          $t2, 0x1A8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A8);
    // 0x800066EC: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x800066F0: lw          $t3, 0xC0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC0);
    // 0x800066F4: nop

    // 0x800066F8: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800066FC: sw          $t4, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r12;
    // 0x80006700: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006704: nop

    // 0x80006708: lw          $t6, 0xC0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC0);
    // 0x8000670C: nop

    // 0x80006710: ori         $t7, $t6, 0x810
    ctx->r15 = ctx->r14 | 0X810;
    // 0x80006714: sw          $t7, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r15;
    // 0x80006718: addiu       $t8, $sp, 0x40
    ctx->r24 = ADD32(ctx->r29, 0X40);
    // 0x8000671C: sw          $t8, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r24;
    // 0x80006720: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x80006724: jal         0x80099E2C
    // 0x80006728: nop

    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x80006728: nop

    after_1:
    // 0x8000672C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80006730: nop

    // 0x80006734: swc1        $f4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f4.u32l;
    // 0x80006738: swc1        $f4, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f4.u32l;
    // 0x8000673C: swc1        $f4, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f4.u32l;
    // 0x80006740: sw          $zero, 0x148($sp)
    MEM_W(0X148, ctx->r29) = 0;
    // 0x80006744: sw          $zero, 0x144($sp)
    MEM_W(0X144, ctx->r29) = 0;
    // 0x80006748: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000674C: nop

    // 0x80006750: swc1        $f6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f6.u32l;
    // 0x80006754: swc1        $f6, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f6.u32l;
    // 0x80006758: swc1        $f6, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f6.u32l;
    // 0x8000675C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006760: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006764: nop

    // 0x80006768: swc1        $f8, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f8.u32l;
    // 0x8000676C: swc1        $f8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f8.u32l;
    // 0x80006770: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80006774: sh          $t9, 0x15E($sp)
    MEM_H(0X15E, ctx->r29) = ctx->r25;
    // 0x80006778: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000677C: sh          $t0, 0x156($sp)
    MEM_H(0X156, ctx->r29) = ctx->r8;
    // 0x80006780: addiu       $t1, $zero, 0x814
    ctx->r9 = ADD32(0, 0X814);
    // 0x80006784: sw          $t1, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r9;
    // 0x80006788: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8000678C: sh          $t3, 0x154($sp)
    MEM_H(0X154, ctx->r29) = ctx->r11;
    // 0x80006790: lw          $t4, 0x1A8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006794: nop

    // 0x80006798: lw          $t2, 0xC8($t4)
    ctx->r10 = MEM_W(ctx->r12, 0XC8);
    // 0x8000679C: nop

    // 0x800067A0: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x800067A4: sw          $t6, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r14;
    // 0x800067A8: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x800067AC: sh          $t7, 0x140($sp)
    MEM_H(0X140, ctx->r29) = ctx->r15;
    // 0x800067B0: addiu       $t5, $zero, 0xB0
    ctx->r13 = ADD32(0, 0XB0);
    // 0x800067B4: sh          $t5, 0x142($sp)
    MEM_H(0X142, ctx->r29) = ctx->r13;
    // 0x800067B8: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800067BC: nop

    // 0x800067C0: lh          $t9, 0x100($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X100);
    // 0x800067C4: lh          $t0, 0x102($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X102);
    // 0x800067C8: nop

    // 0x800067CC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800067D0: mflo        $a0
    ctx->r4 = lo;
    // 0x800067D4: jal         0x800BC6EC
    // 0x800067D8: nop

    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x800067D8: nop

    after_2:
    // 0x800067DC: sw          $v0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r2;
    // 0x800067E0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800067E4: addiu       $t1, $t1, -0x44B8
    ctx->r9 = ADD32(ctx->r9, -0X44B8);
    // 0x800067E8: sw          $t1, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r9;
    // 0x800067EC: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x800067F0: nop

    // 0x800067F4: sw          $t3, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r11;
    // 0x800067F8: lh          $t4, 0x140($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X140);
    // 0x800067FC: lh          $t2, 0x142($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X142);
    // 0x80006800: sw          $zero, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = 0;
    // 0x80006804: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006808: mflo        $t6
    ctx->r14 = lo;
    // 0x8000680C: blez        $t6, L_80006850
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80006810: nop

            goto L_80006850;
    }
    // 0x80006810: nop

L_80006814:
    // 0x80006814: lw          $t7, 0x1AC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1AC);
    // 0x80006818: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x8000681C: nop

    // 0x80006820: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x80006824: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80006828: lh          $t1, 0x140($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X140);
    // 0x8000682C: lh          $t3, 0x142($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X142);
    // 0x80006830: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x80006834: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006838: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8000683C: sw          $t0, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r8;
    // 0x80006840: mflo        $t4
    ctx->r12 = lo;
    // 0x80006844: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80006848: bne         $at, $zero, L_80006814
    if (ctx->r1 != 0) {
        // 0x8000684C: nop

            goto L_80006814;
    }
    // 0x8000684C: nop

L_80006850:
    // 0x80006850: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80006854: lw          $t2, -0x6080($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6080);
    // 0x80006858: nop

    // 0x8000685C: bne         $t2, $zero, L_8000688C
    if (ctx->r10 != 0) {
        // 0x80006860: nop

            goto L_8000688C;
    }
    // 0x80006860: nop

    // 0x80006864: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80006868: addiu       $t6, $t6, -0x66B0
    ctx->r14 = ADD32(ctx->r14, -0X66B0);
    // 0x8000686C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006870: sw          $t6, -0x6080($at)
    MEM_W(-0X6080, ctx->r1) = ctx->r14;
    // 0x80006874: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006878: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000687C: lw          $a1, 0x648($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X648);
    // 0x80006880: lw          $a0, -0x6080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6080);
    // 0x80006884: jal         0x800BCFCC
    // 0x80006888: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    SysMem_Copy8(rdram, ctx);
        goto after_3;
    // 0x80006888: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    after_3:
L_8000688C:
    // 0x8000688C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80006890: lw          $t7, 0x648($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X648);
    // 0x80006894: nop

    // 0x80006898: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8000689C: sw          $zero, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = 0;
    // 0x800068A0: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x800068A4: lw          $a1, 0x1C4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C4);
    // 0x800068A8: jal         0x800062C0
    // 0x800068AC: nop

    func_800062C0(rdram, ctx);
        goto after_4;
    // 0x800068AC: nop

    after_4:
    // 0x800068B0: sw          $zero, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = 0;
    // 0x800068B4: b           L_80006A1C
    // 0x800068B8: sw          $zero, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = 0;
        goto L_80006A1C;
    // 0x800068B8: sw          $zero, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = 0;
L_800068BC:
    // 0x800068BC: lw          $t5, 0x1B4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B4);
    // 0x800068C0: nop

    // 0x800068C4: addiu       $t8, $t5, 0x7FFF
    ctx->r24 = ADD32(ctx->r13, 0X7FFF);
    // 0x800068C8: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x800068CC: nop

    // 0x800068D0: blez        $t8, L_80006954
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800068D4: nop

            goto L_80006954;
    }
    // 0x800068D4: nop

L_800068D8:
    // 0x800068D8: lw          $t9, 0x1B8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1B8);
    // 0x800068DC: addiu       $a1, $sp, 0x1B0
    ctx->r5 = ADD32(ctx->r29, 0X1B0);
    // 0x800068E0: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    // 0x800068E4: jal         0x800C143C
    // 0x800068E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_5;
    // 0x800068E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800068EC: lw          $t1, 0x1B0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B0);
    // 0x800068F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800068F4: lh          $t3, 0x0($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X0);
    // 0x800068F8: nop

    // 0x800068FC: bne         $t3, $at, L_80006938
    if (ctx->r11 != ctx->r1) {
        // 0x80006900: nop

            goto L_80006938;
    }
    // 0x80006900: nop

    // 0x80006904: b           L_8000690C
    // 0x80006908: nop

        goto L_8000690C;
    // 0x80006908: nop

L_8000690C:
    // 0x8000690C: jal         0x80099520
    // 0x80006910: nop

    func_80099520(rdram, ctx);
        goto after_6;
    // 0x80006910: nop

    after_6:
    // 0x80006914: lw          $t0, 0x1B4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1B4);
    // 0x80006918: nop

    // 0x8000691C: addiu       $t4, $t0, 0x7FFF
    ctx->r12 = ADD32(ctx->r8, 0X7FFF);
    // 0x80006920: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x80006924: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x80006928: addiu       $t2, $t4, -0x1
    ctx->r10 = ADD32(ctx->r12, -0X1);
    // 0x8000692C: sw          $t2, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r10;
    // 0x80006930: b           L_80006938
    // 0x80006934: nop

        goto L_80006938;
    // 0x80006934: nop

L_80006938:
    // 0x80006938: lw          $t6, 0x1B4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1B4);
    // 0x8000693C: nop

    // 0x80006940: addiu       $t7, $t6, 0x7FFF
    ctx->r15 = ADD32(ctx->r14, 0X7FFF);
    // 0x80006944: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x80006948: nop

    // 0x8000694C: bgtz        $t7, L_800068D8
    if (SIGNED(ctx->r15) > 0) {
        // 0x80006950: nop

            goto L_800068D8;
    }
    // 0x80006950: nop

L_80006954:
    // 0x80006954: jal         0x80098820
    // 0x80006958: nop

    func_80098820(rdram, ctx);
        goto after_7;
    // 0x80006958: nop

    after_7:
    // 0x8000695C: jal         0x80098868
    // 0x80006960: nop

    func_80098868(rdram, ctx);
        goto after_8;
    // 0x80006960: nop

    after_8:
    // 0x80006964: sw          $zero, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = 0;
L_80006968:
    // 0x80006968: lw          $t5, 0x1D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D4);
    // 0x8000696C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80006970: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80006974: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x80006978: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000697C: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x80006980: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80006984: addiu       $t9, $t9, -0x6658
    ctx->r25 = ADD32(ctx->r25, -0X6658);
    // 0x80006988: jal         0x80099E2C
    // 0x8000698C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    func_80099E2C(rdram, ctx);
        goto after_9;
    // 0x8000698C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x80006990: lw          $t1, 0x1D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1D4);
    // 0x80006994: nop

    // 0x80006998: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8000699C: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x800069A0: bne         $at, $zero, L_80006968
    if (ctx->r1 != 0) {
        // 0x800069A4: sw          $t3, 0x1D4($sp)
        MEM_W(0X1D4, ctx->r29) = ctx->r11;
            goto L_80006968;
    }
    // 0x800069A4: sw          $t3, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r11;
    // 0x800069A8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800069AC: addiu       $a1, $a1, -0x6658
    ctx->r5 = ADD32(ctx->r5, -0X6658);
    // 0x800069B0: jal         0x800A6670
    // 0x800069B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_10;
    // 0x800069B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x800069B8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800069BC: addiu       $a1, $a1, -0x6658
    ctx->r5 = ADD32(ctx->r5, -0X6658);
    // 0x800069C0: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x800069C4: jal         0x800A6670
    // 0x800069C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_11;
    // 0x800069C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_11:
    // 0x800069CC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x800069D0: jal         0x80005124
    // 0x800069D4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_80005124(rdram, ctx);
        goto after_12;
    // 0x800069D4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_12:
    // 0x800069D8: sw          $v0, 0x1BC($sp)
    MEM_W(0X1BC, ctx->r29) = ctx->r2;
    // 0x800069DC: lw          $t4, 0x1BC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1BC);
    // 0x800069E0: nop

    // 0x800069E4: bne         $t4, $zero, L_800069F8
    if (ctx->r12 != 0) {
        // 0x800069E8: nop

            goto L_800069F8;
    }
    // 0x800069E8: nop

    // 0x800069EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800069F0: jal         0x800A6F20
    // 0x800069F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800A6F20(rdram, ctx);
        goto after_13;
    // 0x800069F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
L_800069F8:
    // 0x800069F8: jal         0x8008CE90
    // 0x800069FC: nop

    func_8008CE90(rdram, ctx);
        goto after_14;
    // 0x800069FC: nop

    after_14:
    // 0x80006A00: lw          $t2, 0x1B8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B8);
    // 0x80006A04: nop

    // 0x80006A08: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80006A0C: jal         0x800C13B8
    // 0x80006A10: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_15;
    // 0x80006A10: nop

    after_15:
    // 0x80006A14: jal         0x80098820
    // 0x80006A18: nop

    func_80098820(rdram, ctx);
        goto after_16;
    // 0x80006A18: nop

    after_16:
L_80006A1C:
    // 0x80006A1C: sw          $zero, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = 0;
    // 0x80006A20: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80006A24: addiu       $t0, $t0, -0x7278
    ctx->r8 = ADD32(ctx->r8, -0X7278);
    // 0x80006A28: lhu         $t6, 0x0($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X0);
    // 0x80006A2C: nop

    // 0x80006A30: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x80006A34: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x80006A38: lw          $t5, 0x1D0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D0);
    // 0x80006A3C: nop

    // 0x80006A40: bne         $t5, $zero, L_80007580
    if (ctx->r13 != 0) {
        // 0x80006A44: nop

            goto L_80007580;
    }
    // 0x80006A44: nop

L_80006A48:
    // 0x80006A48: lw          $t8, 0x1B8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B8);
    // 0x80006A4C: addiu       $a1, $sp, 0x1B0
    ctx->r5 = ADD32(ctx->r29, 0X1B0);
    // 0x80006A50: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80006A54: jal         0x800C143C
    // 0x80006A58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_17;
    // 0x80006A58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80006A5C: lw          $t9, 0x1B0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1B0);
    // 0x80006A60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006A64: lh          $s0, 0x0($t9)
    ctx->r16 = MEM_H(ctx->r25, 0X0);
    // 0x80006A68: nop

    // 0x80006A6C: beq         $s0, $at, L_80006A94
    if (ctx->r16 == ctx->r1) {
        // 0x80006A70: nop

            goto L_80006A94;
    }
    // 0x80006A70: nop

    // 0x80006A74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80006A78: beq         $s0, $at, L_80007368
    if (ctx->r16 == ctx->r1) {
        // 0x80006A7C: nop

            goto L_80007368;
    }
    // 0x80006A7C: nop

    // 0x80006A80: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80006A84: beq         $s0, $at, L_80007558
    if (ctx->r16 == ctx->r1) {
        // 0x80006A88: nop

            goto L_80007558;
    }
    // 0x80006A88: nop

    // 0x80006A8C: b           L_80007568
    // 0x80006A90: nop

        goto L_80007568;
    // 0x80006A90: nop

L_80006A94:
    // 0x80006A94: lw          $t1, 0x1B4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B4);
    // 0x80006A98: nop

    // 0x80006A9C: addiu       $t3, $t1, 0x7FFF
    ctx->r11 = ADD32(ctx->r9, 0X7FFF);
    // 0x80006AA0: lw          $t3, 0x2ED($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2ED);
    // 0x80006AA4: nop

    // 0x80006AA8: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80006AAC: beq         $at, $zero, L_80007360
    if (ctx->r1 == 0) {
        // 0x80006AB0: nop

            goto L_80007360;
    }
    // 0x80006AB0: nop

    // 0x80006AB4: jal         0x80099768
    // 0x80006AB8: nop

    func_80099768(rdram, ctx);
        goto after_18;
    // 0x80006AB8: nop

    after_18:
    // 0x80006ABC: jal         0x800AFB28
    // 0x80006AC0: nop

    func_800AFB28(rdram, ctx);
        goto after_19;
    // 0x80006AC0: nop

    after_19:
    // 0x80006AC4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80006AC8: lw          $t2, -0x4CC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CC4);
    // 0x80006ACC: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80006AD0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80006AD4: lw          $t4, -0x4CCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CCC);
    // 0x80006AD8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80006ADC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80006AE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80006AE4: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x80006AE8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80006AEC: jal         0x800BE510
    // 0x80006AF0: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    func_800BE510(rdram, ctx);
        goto after_20;
    // 0x80006AF0: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    after_20:
    // 0x80006AF4: jal         0x80032604
    // 0x80006AF8: nop

    func_80032604(rdram, ctx);
        goto after_21;
    // 0x80006AF8: nop

    after_21:
    // 0x80006AFC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80006B00: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80006B04: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80006B08: nop

    // 0x80006B0C: andi        $t0, $t7, 0x8000
    ctx->r8 = ctx->r15 & 0X8000;
    // 0x80006B10: beq         $t0, $zero, L_800072D0
    if (ctx->r8 == 0) {
        // 0x80006B14: nop

            goto L_800072D0;
    }
    // 0x80006B14: nop

    // 0x80006B18: sw          $zero, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = 0;
    // 0x80006B1C: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80006B20: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x80006B24: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80006B28: lhu         $t9, 0xE74($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XE74);
    // 0x80006B2C: lhu         $t8, 0x8($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X8);
    // 0x80006B30: nop

    // 0x80006B34: and         $t1, $t8, $t9
    ctx->r9 = ctx->r24 & ctx->r25;
    // 0x80006B38: bne         $t1, $zero, L_80006B58
    if (ctx->r9 != 0) {
        // 0x80006B3C: nop

            goto L_80006B58;
    }
    // 0x80006B3C: nop

    // 0x80006B40: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80006B44: lhu         $t3, 0xEEC($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XEEC);
    // 0x80006B48: nop

    // 0x80006B4C: and         $t4, $t8, $t3
    ctx->r12 = ctx->r24 & ctx->r11;
    // 0x80006B50: beq         $t4, $zero, L_80006B78
    if (ctx->r12 == 0) {
        // 0x80006B54: nop

            goto L_80006B78;
    }
    // 0x80006B54: nop

L_80006B58:
    // 0x80006B58: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006B5C: nop

    // 0x80006B60: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x80006B64: sw          $t6, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r14;
    // 0x80006B68: lw          $t7, 0x1C0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006B6C: nop

    // 0x80006B70: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80006B74: sw          $t0, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r8;
L_80006B78:
    // 0x80006B78: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80006B7C: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x80006B80: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80006B84: lhu         $t1, 0xE68($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0XE68);
    // 0x80006B88: lhu         $t9, 0x8($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X8);
    // 0x80006B8C: nop

    // 0x80006B90: and         $t8, $t9, $t1
    ctx->r24 = ctx->r25 & ctx->r9;
    // 0x80006B94: bne         $t8, $zero, L_80006BB4
    if (ctx->r24 != 0) {
        // 0x80006B98: nop

            goto L_80006BB4;
    }
    // 0x80006B98: nop

    // 0x80006B9C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80006BA0: lhu         $t3, 0xEC0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XEC0);
    // 0x80006BA4: nop

    // 0x80006BA8: and         $t4, $t9, $t3
    ctx->r12 = ctx->r25 & ctx->r11;
    // 0x80006BAC: beq         $t4, $zero, L_80006BD4
    if (ctx->r12 == 0) {
        // 0x80006BB0: nop

            goto L_80006BD4;
    }
    // 0x80006BB0: nop

L_80006BB4:
    // 0x80006BB4: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006BB8: nop

    // 0x80006BBC: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x80006BC0: sw          $t6, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r14;
    // 0x80006BC4: lw          $t7, 0x1C0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006BC8: nop

    // 0x80006BCC: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80006BD0: sw          $t0, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r8;
L_80006BD4:
    // 0x80006BD4: lw          $t5, 0x1C4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006BD8: nop

    // 0x80006BDC: bgez        $t5, L_80006BE8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80006BE0: nop

            goto L_80006BE8;
    }
    // 0x80006BE0: nop

    // 0x80006BE4: sw          $zero, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = 0;
L_80006BE8:
    // 0x80006BE8: lw          $t1, 0x1C4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006BEC: nop

    // 0x80006BF0: slti        $at, $t1, 0x2A
    ctx->r1 = SIGNED(ctx->r9) < 0X2A ? 1 : 0;
    // 0x80006BF4: bne         $at, $zero, L_80006C04
    if (ctx->r1 != 0) {
        // 0x80006BF8: nop

            goto L_80006C04;
    }
    // 0x80006BF8: nop

    // 0x80006BFC: addiu       $t8, $zero, 0x29
    ctx->r24 = ADD32(0, 0X29);
    // 0x80006C00: sw          $t8, 0x1C4($sp)
    MEM_W(0X1C4, ctx->r29) = ctx->r24;
L_80006C04:
    // 0x80006C04: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80006C08: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80006C0C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80006C10: lhu         $t4, 0xFF4($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0XFF4);
    // 0x80006C14: lhu         $t3, 0x8($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X8);
    // 0x80006C18: nop

    // 0x80006C1C: and         $t2, $t3, $t4
    ctx->r10 = ctx->r11 & ctx->r12;
    // 0x80006C20: beq         $t2, $zero, L_80006C58
    if (ctx->r10 == 0) {
        // 0x80006C24: nop

            goto L_80006C58;
    }
    // 0x80006C24: nop

    // 0x80006C28: lw          $t7, 0x1C4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006C2C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80006C30: sll         $t0, $t7, 1
    ctx->r8 = S32(ctx->r15 << 1);
    // 0x80006C34: addu        $t5, $t6, $t0
    ctx->r13 = ADD32(ctx->r14, ctx->r8);
    // 0x80006C38: lh          $t1, 0x0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X0);
    // 0x80006C3C: nop

    // 0x80006C40: addiu       $t8, $t1, 0x1
    ctx->r24 = ADD32(ctx->r9, 0X1);
    // 0x80006C44: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
    // 0x80006C48: lw          $t9, 0x1C0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006C4C: nop

    // 0x80006C50: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80006C54: sw          $t3, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r11;
L_80006C58:
    // 0x80006C58: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80006C5C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80006C60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80006C64: lhu         $t7, 0x101C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X101C);
    // 0x80006C68: lhu         $t2, 0x8($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X8);
    // 0x80006C6C: nop

    // 0x80006C70: and         $t6, $t2, $t7
    ctx->r14 = ctx->r10 & ctx->r15;
    // 0x80006C74: beq         $t6, $zero, L_80006CAC
    if (ctx->r14 == 0) {
        // 0x80006C78: nop

            goto L_80006CAC;
    }
    // 0x80006C78: nop

    // 0x80006C7C: lw          $t1, 0x1C4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006C80: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80006C84: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x80006C88: addu        $t5, $t0, $t8
    ctx->r13 = ADD32(ctx->r8, ctx->r24);
    // 0x80006C8C: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x80006C90: nop

    // 0x80006C94: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80006C98: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
    // 0x80006C9C: lw          $t4, 0x1C0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006CA0: nop

    // 0x80006CA4: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x80006CA8: sw          $t2, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r10;
L_80006CAC:
    // 0x80006CAC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80006CB0: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80006CB4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80006CB8: lhu         $t1, 0x1258($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X1258);
    // 0x80006CBC: lhu         $t6, 0x8($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X8);
    // 0x80006CC0: nop

    // 0x80006CC4: and         $t0, $t6, $t1
    ctx->r8 = ctx->r14 & ctx->r9;
    // 0x80006CC8: beq         $t0, $zero, L_80006D00
    if (ctx->r8 == 0) {
        // 0x80006CCC: nop

            goto L_80006D00;
    }
    // 0x80006CCC: nop

    // 0x80006CD0: lw          $t9, 0x1C4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006CD4: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80006CD8: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x80006CDC: addu        $t5, $t8, $t3
    ctx->r13 = ADD32(ctx->r24, ctx->r11);
    // 0x80006CE0: lh          $t4, 0x0($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X0);
    // 0x80006CE4: nop

    // 0x80006CE8: addiu       $t2, $t4, 0xA
    ctx->r10 = ADD32(ctx->r12, 0XA);
    // 0x80006CEC: sh          $t2, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r10;
    // 0x80006CF0: lw          $t7, 0x1C0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006CF4: nop

    // 0x80006CF8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80006CFC: sw          $t6, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r14;
L_80006D00:
    // 0x80006D00: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80006D04: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x80006D08: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80006D0C: lhu         $t9, 0x1260($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1260);
    // 0x80006D10: lhu         $t0, 0x8($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X8);
    // 0x80006D14: nop

    // 0x80006D18: and         $t8, $t0, $t9
    ctx->r24 = ctx->r8 & ctx->r25;
    // 0x80006D1C: beq         $t8, $zero, L_80006D54
    if (ctx->r24 == 0) {
        // 0x80006D20: nop

            goto L_80006D54;
    }
    // 0x80006D20: nop

    // 0x80006D24: lw          $t4, 0x1C4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006D28: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80006D2C: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x80006D30: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x80006D34: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80006D38: nop

    // 0x80006D3C: addiu       $t6, $t7, -0xA
    ctx->r14 = ADD32(ctx->r15, -0XA);
    // 0x80006D40: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
    // 0x80006D44: lw          $t1, 0x1C0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006D48: nop

    // 0x80006D4C: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x80006D50: sw          $t0, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r8;
L_80006D54:
    // 0x80006D54: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80006D58: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80006D5C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80006D60: lhu         $t4, 0x126C($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X126C);
    // 0x80006D64: lhu         $t8, 0x8($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X8);
    // 0x80006D68: nop

    // 0x80006D6C: and         $t3, $t8, $t4
    ctx->r11 = ctx->r24 & ctx->r12;
    // 0x80006D70: beq         $t3, $zero, L_80006DA8
    if (ctx->r11 == 0) {
        // 0x80006D74: nop

            goto L_80006DA8;
    }
    // 0x80006D74: nop

    // 0x80006D78: lw          $t7, 0x1C4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006D7C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80006D80: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80006D84: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x80006D88: lh          $t1, 0x0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X0);
    // 0x80006D8C: nop

    // 0x80006D90: addiu       $t0, $t1, 0x64
    ctx->r8 = ADD32(ctx->r9, 0X64);
    // 0x80006D94: sh          $t0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r8;
    // 0x80006D98: lw          $t9, 0x1C0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006D9C: nop

    // 0x80006DA0: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80006DA4: sw          $t8, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r24;
L_80006DA8:
    // 0x80006DA8: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80006DAC: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80006DB0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80006DB4: lhu         $t7, 0x11AC($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X11AC);
    // 0x80006DB8: lhu         $t3, 0x8($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X8);
    // 0x80006DBC: nop

    // 0x80006DC0: and         $t2, $t3, $t7
    ctx->r10 = ctx->r11 & ctx->r15;
    // 0x80006DC4: beq         $t2, $zero, L_80006DFC
    if (ctx->r10 == 0) {
        // 0x80006DC8: nop

            goto L_80006DFC;
    }
    // 0x80006DC8: nop

    // 0x80006DCC: lw          $t1, 0x1C4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006DD0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80006DD4: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x80006DD8: addu        $t5, $t6, $t0
    ctx->r13 = ADD32(ctx->r14, ctx->r8);
    // 0x80006DDC: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x80006DE0: nop

    // 0x80006DE4: addiu       $t8, $t9, -0x64
    ctx->r24 = ADD32(ctx->r25, -0X64);
    // 0x80006DE8: sh          $t8, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r24;
    // 0x80006DEC: lw          $t4, 0x1C0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006DF0: nop

    // 0x80006DF4: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80006DF8: sw          $t3, 0x1C0($sp)
    MEM_W(0X1C0, ctx->r29) = ctx->r11;
L_80006DFC:
    // 0x80006DFC: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E00: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80006E04: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x80006E08: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x80006E0C: lh          $t0, 0x0($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X0);
    // 0x80006E10: nop

    // 0x80006E14: bgez        $t0, L_80006E30
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80006E18: nop

            goto L_80006E30;
    }
    // 0x80006E18: nop

    // 0x80006E1C: lw          $t8, 0x1C4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E20: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80006E24: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x80006E28: addu        $t4, $t9, $t5
    ctx->r12 = ADD32(ctx->r25, ctx->r13);
    // 0x80006E2C: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
L_80006E30:
    // 0x80006E30: lw          $t2, 0x1C4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E34: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80006E38: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x80006E3C: addu        $t1, $t3, $t7
    ctx->r9 = ADD32(ctx->r11, ctx->r15);
    // 0x80006E40: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80006E44: nop

    // 0x80006E48: slti        $at, $t6, 0x3E8
    ctx->r1 = SIGNED(ctx->r14) < 0X3E8 ? 1 : 0;
    // 0x80006E4C: bne         $at, $zero, L_80006E6C
    if (ctx->r1 != 0) {
        // 0x80006E50: nop

            goto L_80006E6C;
    }
    // 0x80006E50: nop

    // 0x80006E54: lw          $t9, 0x1C4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E58: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80006E5C: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x80006E60: addiu       $t0, $zero, 0x3E7
    ctx->r8 = ADD32(0, 0X3E7);
    // 0x80006E64: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x80006E68: sh          $t0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r8;
L_80006E6C:
    // 0x80006E6C: lw          $t2, 0x1C0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C0);
    // 0x80006E70: nop

    // 0x80006E74: beq         $t2, $zero, L_80006E8C
    if (ctx->r10 == 0) {
        // 0x80006E78: nop

            goto L_80006E8C;
    }
    // 0x80006E78: nop

    // 0x80006E7C: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x80006E80: lw          $a1, 0x1C4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C4);
    // 0x80006E84: jal         0x800062C0
    // 0x80006E88: nop

    func_800062C0(rdram, ctx);
        goto after_22;
    // 0x80006E88: nop

    after_22:
L_80006E8C:
    // 0x80006E8C: addiu       $t3, $sp, 0x40
    ctx->r11 = ADD32(ctx->r29, 0X40);
    // 0x80006E90: sw          $t3, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r11;
    // 0x80006E94: jal         0x800C1754
    // 0x80006E98: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_23;
    // 0x80006E98: nop

    after_23:
    // 0x80006E9C: lw          $a0, 0x1A8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006EA0: jal         0x8009A14C
    // 0x80006EA4: nop

    func_8009A14C(rdram, ctx);
        goto after_24;
    // 0x80006EA4: nop

    after_24:
    // 0x80006EA8: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006EAC: nop

    // 0x80006EB0: lw          $t1, 0xC0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC0);
    // 0x80006EB4: nop

    // 0x80006EB8: andi        $t6, $t1, 0x8
    ctx->r14 = ctx->r9 & 0X8;
    // 0x80006EBC: bne         $t6, $zero, L_8000726C
    if (ctx->r14 != 0) {
        // 0x80006EC0: nop

            goto L_8000726C;
    }
    // 0x80006EC0: nop

    // 0x80006EC4: lw          $t9, 0x1C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C8);
    // 0x80006EC8: nop

    // 0x80006ECC: bne         $t9, $zero, L_800070A4
    if (ctx->r25 != 0) {
        // 0x80006ED0: nop

            goto L_800070A4;
    }
    // 0x80006ED0: nop

    // 0x80006ED4: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006ED8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80006EDC: lwc1        $f18, 0xE8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x80006EE0: nop

    // 0x80006EE4: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80006EE8: nop

    // 0x80006EEC: bc1f        L_80006FC8
    if (!c1cs) {
        // 0x80006EF0: nop

            goto L_80006FC8;
    }
    // 0x80006EF0: nop

    // 0x80006EF4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80006EF8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80006EFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80006F00: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80006F04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80006F08: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80006F0C: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80006F10: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006F14: nop

    // 0x80006F18: lwc1        $f18, 0xE8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XE8);
    // 0x80006F1C: nop

    // 0x80006F20: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80006F24: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d);
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x80006F28: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80006F2C: swc1        $f6, 0xE8($t5)
    MEM_W(0XE8, ctx->r13) = ctx->f6.u32l;
    // 0x80006F30: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80006F34: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80006F38: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80006F3C: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80006F40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80006F44: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80006F48: mul.d       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80006F4C: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006F50: nop

    // 0x80006F54: lwc1        $f8, 0xF0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x80006F58: nop

    // 0x80006F5C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80006F60: sub.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = ctx->f6.d - ctx->f10.d;
    // 0x80006F64: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80006F68: swc1        $f16, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = ctx->f16.u32l;
    // 0x80006F6C: lw          $t4, 0x1A8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006F70: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80006F74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006F78: lwc1        $f4, 0xE8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XE8);
    // 0x80006F7C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80006F80: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80006F84: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80006F88: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80006F8C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80006F90: sub.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f18.d - ctx->f10.d;
    // 0x80006F94: cvt.s.d     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f20.fl = CVT_S_D(ctx->f16.d);
    // 0x80006F98: swc1        $f20, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->f20.u32l;
    // 0x80006F9C: lw          $t2, 0x1A8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FA0: nop

    // 0x80006FA4: swc1        $f20, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f20.u32l;
    // 0x80006FA8: lw          $t3, 0x1A8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FAC: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x80006FB0: lwc1        $f20, 0xF4($t3)
    ctx->f20.u32l = MEM_W(ctx->r11, 0XF4);
    // 0x80006FB4: nop

    // 0x80006FB8: swc1        $f20, 0xF8($t7)
    MEM_W(0XF8, ctx->r15) = ctx->f20.u32l;
    // 0x80006FBC: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x80006FC0: b           L_8000709C
    // 0x80006FC4: swc1        $f20, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f20.u32l;
        goto L_8000709C;
    // 0x80006FC4: swc1        $f20, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->f20.u32l;
L_80006FC8:
    // 0x80006FC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80006FCC: lw          $t6, 0x1A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FD0: nop

    // 0x80006FD4: swc1        $f4, 0xF0($t6)
    MEM_W(0XF0, ctx->r14) = ctx->f4.u32l;
    // 0x80006FD8: lw          $t9, 0x1A8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FDC: nop

    // 0x80006FE0: lwc1        $f8, 0xF0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x80006FE4: nop

    // 0x80006FE8: swc1        $f8, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f8.u32l;
    // 0x80006FEC: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80006FF0: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80006FF4: lw          $t5, 0xC0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0XC0);
    // 0x80006FF8: nop

    // 0x80006FFC: and         $t0, $t5, $at
    ctx->r8 = ctx->r13 & ctx->r1;
    // 0x80007000: sw          $t0, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r8;
    // 0x80007004: lw          $t4, 0x1A8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007008: nop

    // 0x8000700C: lw          $t2, 0xC0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0XC0);
    // 0x80007010: nop

    // 0x80007014: ori         $t3, $t2, 0x48
    ctx->r11 = ctx->r10 | 0X48;
    // 0x80007018: sw          $t3, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r11;
    // 0x8000701C: lw          $t7, 0x1A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007020: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80007024: lw          $t1, 0xC0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC0);
    // 0x80007028: nop

    // 0x8000702C: and         $t6, $t1, $at
    ctx->r14 = ctx->r9 & ctx->r1;
    // 0x80007030: sw          $t6, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = ctx->r14;
    // 0x80007034: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007038: nop

    // 0x8000703C: lw          $t5, 0xC0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC0);
    // 0x80007040: nop

    // 0x80007044: ori         $t0, $t5, 0x48
    ctx->r8 = ctx->r13 | 0X48;
    // 0x80007048: sw          $t0, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->r8;
    // 0x8000704C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80007054: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007058: nop

    // 0x8000705C: swc1        $f6, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f6.u32l;
    // 0x80007060: lw          $t2, 0x1A8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007064: nop

    // 0x80007068: lwc1        $f18, 0xF8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XF8);
    // 0x8000706C: nop

    // 0x80007070: swc1        $f18, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f18.u32l;
    // 0x80007074: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007078: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000707C: lw          $t3, 0x1A4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007080: nop

    // 0x80007084: swc1        $f10, 0xF8($t3)
    MEM_W(0XF8, ctx->r11) = ctx->f10.u32l;
    // 0x80007088: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x8000708C: nop

    // 0x80007090: lwc1        $f16, 0xF8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XF8);
    // 0x80007094: nop

    // 0x80007098: swc1        $f16, 0xF4($t4)
    MEM_W(0XF4, ctx->r12) = ctx->f16.u32l;
L_8000709C:
    // 0x8000709C: b           L_8000726C
    // 0x800070A0: nop

        goto L_8000726C;
    // 0x800070A0: nop

L_800070A4:
    // 0x800070A4: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x800070A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800070AC: lwc1        $f4, 0xE8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XE8);
    // 0x800070B0: nop

    // 0x800070B4: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800070B8: nop

    // 0x800070BC: bc1t        L_80007198
    if (c1cs) {
        // 0x800070C0: nop

            goto L_80007198;
    }
    // 0x800070C0: nop

    // 0x800070C4: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x800070C8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800070CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800070D0: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800070D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800070D8: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x800070DC: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800070E0: lw          $t6, 0x1A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1A8);
    // 0x800070E4: nop

    // 0x800070E8: lwc1        $f4, 0xE8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x800070EC: nop

    // 0x800070F0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800070F4: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d);
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x800070F8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x800070FC: swc1        $f6, 0xE8($t6)
    MEM_W(0XE8, ctx->r14) = ctx->f6.u32l;
    // 0x80007100: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80007104: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80007108: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000710C: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80007110: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80007114: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80007118: mul.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x8000711C: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007120: nop

    // 0x80007124: lwc1        $f18, 0xF0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XF0);
    // 0x80007128: nop

    // 0x8000712C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80007130: sub.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = ctx->f6.d - ctx->f16.d;
    // 0x80007134: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80007138: swc1        $f10, 0xF0($t7)
    MEM_W(0XF0, ctx->r15) = ctx->f10.u32l;
    // 0x8000713C: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007140: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80007144: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80007148: lwc1        $f8, 0xE8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XE8);
    // 0x8000714C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80007150: div.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80007154: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80007158: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000715C: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80007160: sub.d       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d);
    ctx->f10.d = ctx->f4.d - ctx->f16.d;
    // 0x80007164: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x80007168: swc1        $f20, 0xF8($t5)
    MEM_W(0XF8, ctx->r13) = ctx->f20.u32l;
    // 0x8000716C: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007170: nop

    // 0x80007174: swc1        $f20, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->f20.u32l;
    // 0x80007178: lw          $t9, 0x1A8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A8);
    // 0x8000717C: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007180: lwc1        $f20, 0xF4($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XF4);
    // 0x80007184: nop

    // 0x80007188: swc1        $f20, 0xF8($t8)
    MEM_W(0XF8, ctx->r24) = ctx->f20.u32l;
    // 0x8000718C: lw          $t2, 0x1A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007190: b           L_8000726C
    // 0x80007194: swc1        $f20, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f20.u32l;
        goto L_8000726C;
    // 0x80007194: swc1        $f20, 0xF4($t2)
    MEM_W(0XF4, ctx->r10) = ctx->f20.u32l;
L_80007198:
    // 0x80007198: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000719C: lw          $t3, 0x1A8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A8);
    // 0x800071A0: nop

    // 0x800071A4: swc1        $f8, 0xF0($t3)
    MEM_W(0XF0, ctx->r11) = ctx->f8.u32l;
    // 0x800071A8: lw          $t4, 0x1A8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A8);
    // 0x800071AC: nop

    // 0x800071B0: lwc1        $f18, 0xF0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XF0);
    // 0x800071B4: nop

    // 0x800071B8: swc1        $f18, 0xE8($t4)
    MEM_W(0XE8, ctx->r12) = ctx->f18.u32l;
    // 0x800071BC: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x800071C0: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800071C4: lw          $t6, 0xC0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XC0);
    // 0x800071C8: nop

    // 0x800071CC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800071D0: sw          $t7, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r15;
    // 0x800071D4: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x800071D8: nop

    // 0x800071DC: lw          $t0, 0xC0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC0);
    // 0x800071E0: nop

    // 0x800071E4: ori         $t9, $t0, 0x8
    ctx->r25 = ctx->r8 | 0X8;
    // 0x800071E8: sw          $t9, 0xC0($t5)
    MEM_W(0XC0, ctx->r13) = ctx->r25;
    // 0x800071EC: lw          $t8, 0x1A4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A4);
    // 0x800071F0: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x800071F4: lw          $t2, 0xC0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0XC0);
    // 0x800071F8: nop

    // 0x800071FC: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80007200: sw          $t3, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r11;
    // 0x80007204: lw          $t4, 0x1A4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007208: nop

    // 0x8000720C: lw          $t6, 0xC0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC0);
    // 0x80007210: nop

    // 0x80007214: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80007218: sw          $t7, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r15;
    // 0x8000721C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80007224: lw          $t1, 0x1A8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007228: nop

    // 0x8000722C: swc1        $f6, 0xF8($t1)
    MEM_W(0XF8, ctx->r9) = ctx->f6.u32l;
    // 0x80007230: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007234: nop

    // 0x80007238: lwc1        $f4, 0xF8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XF8);
    // 0x8000723C: nop

    // 0x80007240: swc1        $f4, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->f4.u32l;
    // 0x80007244: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80007248: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000724C: lw          $t9, 0x1A4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007250: nop

    // 0x80007254: swc1        $f16, 0xF8($t9)
    MEM_W(0XF8, ctx->r25) = ctx->f16.u32l;
    // 0x80007258: lw          $t5, 0x1A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A4);
    // 0x8000725C: nop

    // 0x80007260: lwc1        $f10, 0xF8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XF8);
    // 0x80007264: nop

    // 0x80007268: swc1        $f10, 0xF4($t5)
    MEM_W(0XF4, ctx->r13) = ctx->f10.u32l;
L_8000726C:
    // 0x8000726C: lw          $t2, 0x1A8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007270: nop

    // 0x80007274: lwc1        $f12, 0xF0($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XF0);
    // 0x80007278: jal         0x800C2780
    // 0x8000727C: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_25;
    // 0x8000727C: nop

    after_25:
    // 0x80007280: lw          $t3, 0x1A8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007284: nop

    // 0x80007288: lwc1        $f12, 0xEC($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0XEC);
    // 0x8000728C: jal         0x800C25B8
    // 0x80007290: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_26;
    // 0x80007290: nop

    after_26:
    // 0x80007294: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007298: nop

    // 0x8000729C: lwc1        $f12, 0xE8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x800072A0: jal         0x800C23E8
    // 0x800072A4: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_27;
    // 0x800072A4: nop

    after_27:
    // 0x800072A8: lw          $a0, 0x1A8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A8);
    // 0x800072AC: jal         0x800997D8
    // 0x800072B0: nop

    func_800997D8(rdram, ctx);
        goto after_28;
    // 0x800072B0: nop

    after_28:
    // 0x800072B4: lw          $a0, 0x1A4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1A4);
    // 0x800072B8: jal         0x800997D8
    // 0x800072BC: nop

    func_800997D8(rdram, ctx);
        goto after_29;
    // 0x800072BC: nop

    after_29:
    // 0x800072C0: jal         0x800C1A28
    // 0x800072C4: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_30;
    // 0x800072C4: nop

    after_30:
    // 0x800072C8: b           L_800072E8
    // 0x800072CC: nop

        goto L_800072E8;
    // 0x800072CC: nop

L_800072D0:
    // 0x800072D0: jal         0x8008D0CC
    // 0x800072D4: nop

    func_8008D0CC(rdram, ctx);
        goto after_31;
    // 0x800072D4: nop

    after_31:
    // 0x800072D8: beq         $v0, $zero, L_800072E8
    if (ctx->r2 == 0) {
        // 0x800072DC: nop

            goto L_800072E8;
    }
    // 0x800072DC: nop

    // 0x800072E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800072E4: sw          $t6, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r14;
L_800072E8:
    // 0x800072E8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800072EC: addiu       $a0, $a0, -0x6658
    ctx->r4 = ADD32(ctx->r4, -0X6658);
    // 0x800072F0: jal         0x8000262C
    // 0x800072F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000262C(rdram, ctx);
        goto after_32;
    // 0x800072F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x800072F8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x800072FC: jal         0x8009A664
    // 0x80007300: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_33;
    // 0x80007300: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_33:
    // 0x80007304: jal         0x800BE610
    // 0x80007308: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_34;
    // 0x80007308: nop

    after_34:
    // 0x8000730C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80007310: lw          $t7, 0x1B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1B4C);
    // 0x80007314: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80007318: lw          $t4, 0x1B44($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1B44);
    // 0x8000731C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80007320: jal         0x8009908C
    // 0x80007324: subu        $a1, $t4, $t7
    ctx->r5 = SUB32(ctx->r12, ctx->r15);
    CreateGfxTask(rdram, ctx);
        goto after_35;
    // 0x80007324: subu        $a1, $t4, $t7
    ctx->r5 = SUB32(ctx->r12, ctx->r15);
    after_35:
    // 0x80007328: lw          $t1, 0x1B8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B8);
    // 0x8000732C: nop

    // 0x80007330: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    // 0x80007334: jal         0x80098D24
    // 0x80007338: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_36;
    // 0x80007338: nop

    after_36:
    // 0x8000733C: jal         0x80099450
    // 0x80007340: nop

    func_80099450(rdram, ctx);
        goto after_37;
    // 0x80007340: nop

    after_37:
    // 0x80007344: lw          $t0, 0x1B4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1B4);
    // 0x80007348: nop

    // 0x8000734C: addiu       $t9, $t0, 0x7FFF
    ctx->r25 = ADD32(ctx->r8, 0X7FFF);
    // 0x80007350: lw          $t9, 0x2ED($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2ED);
    // 0x80007354: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x80007358: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8000735C: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
L_80007360:
    // 0x80007360: b           L_80007570
    // 0x80007364: nop

        goto L_80007570;
    // 0x80007364: nop

L_80007368:
    // 0x80007368: jal         0x80099520
    // 0x8000736C: nop

    func_80099520(rdram, ctx);
        goto after_38;
    // 0x8000736C: nop

    after_38:
    // 0x80007370: lw          $t2, 0x1B4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1B4);
    // 0x80007374: nop

    // 0x80007378: addiu       $t3, $t2, 0x7FFF
    ctx->r11 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000737C: lw          $t3, 0x2ED($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2ED);
    // 0x80007380: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x80007384: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x80007388: sw          $t8, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r24;
    // 0x8000738C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80007390: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80007394: lhu         $t4, 0x0($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X0);
    // 0x80007398: nop

    // 0x8000739C: andi        $t7, $t4, 0x8000
    ctx->r15 = ctx->r12 & 0X8000;
    // 0x800073A0: beq         $t7, $zero, L_80007550
    if (ctx->r15 == 0) {
        // 0x800073A4: nop

            goto L_80007550;
    }
    // 0x800073A4: nop

    // 0x800073A8: lw          $t1, 0x1CC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1CC);
    // 0x800073AC: nop

    // 0x800073B0: bne         $t1, $zero, L_800074C0
    if (ctx->r9 != 0) {
        // 0x800073B4: nop

            goto L_800074C0;
    }
    // 0x800073B4: nop

    // 0x800073B8: lw          $t9, 0x1A8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A8);
    // 0x800073BC: nop

    // 0x800073C0: lw          $t5, 0xC0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC0);
    // 0x800073C4: nop

    // 0x800073C8: andi        $t0, $t5, 0x8
    ctx->r8 = ctx->r13 & 0X8;
    // 0x800073CC: beq         $t0, $zero, L_800074B8
    if (ctx->r8 == 0) {
        // 0x800073D0: nop

            goto L_800074B8;
    }
    // 0x800073D0: nop

    // 0x800073D4: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x800073D8: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x800073DC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800073E0: lhu         $t2, 0x11A4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X11A4);
    // 0x800073E4: lhu         $t8, 0x6($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X6);
    // 0x800073E8: nop

    // 0x800073EC: and         $t6, $t8, $t2
    ctx->r14 = ctx->r24 & ctx->r10;
    // 0x800073F0: bne         $t6, $zero, L_80007410
    if (ctx->r14 != 0) {
        // 0x800073F4: nop

            goto L_80007410;
    }
    // 0x800073F4: nop

    // 0x800073F8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800073FC: lhu         $t4, 0x10F2($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X10F2);
    // 0x80007400: nop

    // 0x80007404: and         $t7, $t8, $t4
    ctx->r15 = ctx->r24 & ctx->r12;
    // 0x80007408: beq         $t7, $zero, L_800074B8
    if (ctx->r15 == 0) {
        // 0x8000740C: nop

            goto L_800074B8;
    }
    // 0x8000740C: nop

L_80007410:
    // 0x80007410: lw          $t1, 0x1CC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1CC);
    // 0x80007414: nop

    // 0x80007418: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8000741C: sw          $t9, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r25;
    // 0x80007420: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80007424: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80007428: lw          $t5, 0x1A8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1A8);
    // 0x8000742C: nop

    // 0x80007430: swc1        $f8, 0xF0($t5)
    MEM_W(0XF0, ctx->r13) = ctx->f8.u32l;
    // 0x80007434: lw          $t0, 0x1A8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007438: nop

    // 0x8000743C: lwc1        $f18, 0xF0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF0);
    // 0x80007440: nop

    // 0x80007444: swc1        $f18, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f18.u32l;
    // 0x80007448: lw          $t3, 0x1A8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1A8);
    // 0x8000744C: addiu       $at, $zero, -0x49
    ctx->r1 = ADD32(0, -0X49);
    // 0x80007450: lw          $t2, 0xC0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0XC0);
    // 0x80007454: nop

    // 0x80007458: and         $t6, $t2, $at
    ctx->r14 = ctx->r10 & ctx->r1;
    // 0x8000745C: sw          $t6, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r14;
    // 0x80007460: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x80007464: nop

    // 0x80007468: lw          $t4, 0xC0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0XC0);
    // 0x8000746C: nop

    // 0x80007470: ori         $t7, $t4, 0x10
    ctx->r15 = ctx->r12 | 0X10;
    // 0x80007474: sw          $t7, 0xC0($t8)
    MEM_W(0XC0, ctx->r24) = ctx->r15;
    // 0x80007478: lw          $t1, 0x1A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1A4);
    // 0x8000747C: addiu       $at, $zero, -0x49
    ctx->r1 = ADD32(0, -0X49);
    // 0x80007480: lw          $t9, 0xC0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC0);
    // 0x80007484: nop

    // 0x80007488: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x8000748C: sw          $t5, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->r13;
    // 0x80007490: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x80007494: nop

    // 0x80007498: lw          $t2, 0xC0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC0);
    // 0x8000749C: nop

    // 0x800074A0: ori         $t6, $t2, 0x10
    ctx->r14 = ctx->r10 | 0X10;
    // 0x800074A4: sw          $t6, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r14;
    // 0x800074A8: lw          $t3, 0x1C8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C8);
    // 0x800074AC: nop

    // 0x800074B0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800074B4: sw          $t4, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->r12;
L_800074B8:
    // 0x800074B8: b           L_80007520
    // 0x800074BC: nop

        goto L_80007520;
    // 0x800074BC: nop

L_800074C0:
    // 0x800074C0: lw          $t7, 0x1A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1A8);
    // 0x800074C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800074C8: lwc1        $f6, 0xE8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XE8);
    // 0x800074CC: nop

    // 0x800074D0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800074D4: nop

    // 0x800074D8: bc1f        L_800074E8
    if (!c1cs) {
        // 0x800074DC: nop

            goto L_800074E8;
    }
    // 0x800074DC: nop

    // 0x800074E0: b           L_800074FC
    // 0x800074E4: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
        goto L_800074FC;
    // 0x800074E4: mov.s       $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = ctx->f6.fl;
L_800074E8:
    // 0x800074E8: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x800074EC: nop

    // 0x800074F0: lwc1        $f20, 0xE8($t8)
    ctx->f20.u32l = MEM_W(ctx->r24, 0XE8);
    // 0x800074F4: nop

    // 0x800074F8: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl);
    ctx->f20.fl = -ctx->f20.fl;
L_800074FC:
    // 0x800074FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80007500: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80007504: nop

    // 0x80007508: c.le.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl <= ctx->f20.fl;
    // 0x8000750C: nop

    // 0x80007510: bc1f        L_80007520
    if (!c1cs) {
        // 0x80007514: nop

            goto L_80007520;
    }
    // 0x80007514: nop

    // 0x80007518: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000751C: sw          $t9, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r25;
L_80007520:
    // 0x80007520: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80007524: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x80007528: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8000752C: lhu         $t2, 0x1038($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1038);
    // 0x80007530: lhu         $t1, 0x6($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X6);
    // 0x80007534: nop

    // 0x80007538: and         $t6, $t1, $t2
    ctx->r14 = ctx->r9 & ctx->r10;
    // 0x8000753C: beq         $t6, $zero, L_80007550
    if (ctx->r14 == 0) {
        // 0x80007540: nop

            goto L_80007550;
    }
    // 0x80007540: nop

    // 0x80007544: lw          $a0, 0x1B8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1B8);
    // 0x80007548: jal         0x8001AFA0
    // 0x8000754C: nop

    func_8001AFA0(rdram, ctx);
        goto after_39;
    // 0x8000754C: nop

    after_39:
L_80007550:
    // 0x80007550: b           L_80007570
    // 0x80007554: nop

        goto L_80007570;
    // 0x80007554: nop

L_80007558:
    // 0x80007558: b           L_80007558
    pause_self(rdram);
    // 0x8000755C: nop

    // 0x80007560: b           L_80007570
    // 0x80007564: nop

        goto L_80007570;
    // 0x80007564: nop

L_80007568:
    // 0x80007568: b           L_80007570
    // 0x8000756C: nop

        goto L_80007570;
    // 0x8000756C: nop

L_80007570:
    // 0x80007570: lw          $t0, 0x1D0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D0);
    // 0x80007574: nop

    // 0x80007578: beq         $t0, $zero, L_80006A48
    if (ctx->r8 == 0) {
        // 0x8000757C: nop

            goto L_80006A48;
    }
    // 0x8000757C: nop

L_80007580:
    // 0x80007580: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80007584: addiu       $t3, $t3, -0x7278
    ctx->r11 = ADD32(ctx->r11, -0X7278);
    // 0x80007588: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8000758C: nop

    // 0x80007590: andi        $t7, $t4, 0x8000
    ctx->r15 = ctx->r12 & 0X8000;
    // 0x80007594: beq         $t7, $zero, L_800075E0
    if (ctx->r15 == 0) {
        // 0x80007598: nop

            goto L_800075E0;
    }
    // 0x80007598: nop

    // 0x8000759C: lw          $a0, 0x168($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X168);
    // 0x800075A0: jal         0x800BC980
    // 0x800075A4: nop

    SysMem_Free(rdram, ctx);
        goto after_40;
    // 0x800075A4: nop

    after_40:
    // 0x800075A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800075AC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800075B0: lw          $a1, 0x648($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X648);
    // 0x800075B4: lw          $a0, -0x6080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6080);
    // 0x800075B8: jal         0x800BCFCC
    // 0x800075BC: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    SysMem_Copy8(rdram, ctx);
        goto after_41;
    // 0x800075BC: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    after_41:
    // 0x800075C0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x800075C4: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x800075C8: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800075CC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800075D0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800075D4: and         $t5, $t9, $at
    ctx->r13 = ctx->r25 & ctx->r1;
    // 0x800075D8: b           L_800076F0
    // 0x800075DC: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
        goto L_800076F0;
    // 0x800075DC: sh          $t5, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r13;
L_800075E0:
    // 0x800075E0: jal         0x8008D23C
    // 0x800075E4: nop

    func_8008D23C(rdram, ctx);
        goto after_42;
    // 0x800075E4: nop

    after_42:
    // 0x800075E8: lw          $t1, 0x1B4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1B4);
    // 0x800075EC: nop

    // 0x800075F0: addiu       $t2, $t1, 0x7FFF
    ctx->r10 = ADD32(ctx->r9, 0X7FFF);
    // 0x800075F4: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800075F8: nop

    // 0x800075FC: blez        $t2, L_80007680
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80007600: nop

            goto L_80007680;
    }
    // 0x80007600: nop

L_80007604:
    // 0x80007604: lw          $t6, 0x1B8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1B8);
    // 0x80007608: addiu       $a1, $sp, 0x1B0
    ctx->r5 = ADD32(ctx->r29, 0X1B0);
    // 0x8000760C: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80007610: jal         0x800C143C
    // 0x80007614: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_43;
    // 0x80007614: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_43:
    // 0x80007618: lw          $t0, 0x1B0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1B0);
    // 0x8000761C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80007620: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80007624: nop

    // 0x80007628: bne         $t3, $at, L_80007664
    if (ctx->r11 != ctx->r1) {
        // 0x8000762C: nop

            goto L_80007664;
    }
    // 0x8000762C: nop

    // 0x80007630: b           L_80007638
    // 0x80007634: nop

        goto L_80007638;
    // 0x80007634: nop

L_80007638:
    // 0x80007638: jal         0x80099520
    // 0x8000763C: nop

    func_80099520(rdram, ctx);
        goto after_44;
    // 0x8000763C: nop

    after_44:
    // 0x80007640: lw          $t4, 0x1B4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1B4);
    // 0x80007644: nop

    // 0x80007648: addiu       $t7, $t4, 0x7FFF
    ctx->r15 = ADD32(ctx->r12, 0X7FFF);
    // 0x8000764C: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x80007650: addiu       $at, $t4, 0x7FFF
    ctx->r1 = ADD32(ctx->r12, 0X7FFF);
    // 0x80007654: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80007658: sw          $t9, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r25;
    // 0x8000765C: b           L_80007664
    // 0x80007660: nop

        goto L_80007664;
    // 0x80007660: nop

L_80007664:
    // 0x80007664: lw          $t5, 0x1B4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B4);
    // 0x80007668: nop

    // 0x8000766C: addiu       $t8, $t5, 0x7FFF
    ctx->r24 = ADD32(ctx->r13, 0X7FFF);
    // 0x80007670: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x80007674: nop

    // 0x80007678: bgtz        $t8, L_80007604
    if (SIGNED(ctx->r24) > 0) {
        // 0x8000767C: nop

            goto L_80007604;
    }
    // 0x8000767C: nop

L_80007680:
    // 0x80007680: jal         0x80098820
    // 0x80007684: nop

    func_80098820(rdram, ctx);
        goto after_45;
    // 0x80007684: nop

    after_45:
    // 0x80007688: jal         0x80098868
    // 0x8000768C: nop

    func_80098868(rdram, ctx);
        goto after_46;
    // 0x8000768C: nop

    after_46:
    // 0x80007690: lw          $t1, 0x1BC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1BC);
    // 0x80007694: nop

    // 0x80007698: bne         $t1, $zero, L_800076CC
    if (ctx->r9 != 0) {
        // 0x8000769C: nop

            goto L_800076CC;
    }
    // 0x8000769C: nop

    // 0x800076A0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800076A4: addiu       $a1, $a1, -0x6658
    ctx->r5 = ADD32(ctx->r5, -0X6658);
    // 0x800076A8: jal         0x800A6670
    // 0x800076AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_47;
    // 0x800076AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_47:
    // 0x800076B0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800076B4: addiu       $a1, $a1, -0x6658
    ctx->r5 = ADD32(ctx->r5, -0X6658);
    // 0x800076B8: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x800076BC: jal         0x800A6670
    // 0x800076C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_48;
    // 0x800076C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_48:
    // 0x800076C4: jal         0x80005460
    // 0x800076C8: nop

    func_80005460(rdram, ctx);
        goto after_49;
    // 0x800076C8: nop

    after_49:
L_800076CC:
    // 0x800076CC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x800076D0: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x800076D4: jal         0x800A6670
    // 0x800076D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A6670(rdram, ctx);
        goto after_50;
    // 0x800076D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_50:
    // 0x800076DC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x800076E0: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x800076E4: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x800076E8: jal         0x800A6670
    // 0x800076EC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800A6670(rdram, ctx);
        goto after_51;
    // 0x800076EC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_51:
L_800076F0:
    // 0x800076F0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x800076F4: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x800076F8: lhu         $t6, 0x0($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X0);
    // 0x800076FC: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80007700: and         $t0, $t6, $at
    ctx->r8 = ctx->r14 & ctx->r1;
    // 0x80007704: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x80007708: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000770C: addiu       $t3, $t3, -0x5B58
    ctx->r11 = ADD32(ctx->r11, -0X5B58);
    // 0x80007710: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80007714: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007718: swc1        $f10, 0x6190($at)
    MEM_W(0X6190, ctx->r1) = ctx->f10.u32l;
    // 0x8000771C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80007720: addiu       $t7, $t7, -0x5B58
    ctx->r15 = ADD32(ctx->r15, -0X5B58);
    // 0x80007724: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80007728: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000772C: swc1        $f8, 0x6194($at)
    MEM_W(0X6194, ctx->r1) = ctx->f8.u32l;
    // 0x80007730: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80007734: addiu       $t9, $t9, -0x5B58
    ctx->r25 = ADD32(ctx->r25, -0X5B58);
    // 0x80007738: lwc1        $f18, 0x8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8000773C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007740: swc1        $f18, 0x6198($at)
    MEM_W(0X6198, ctx->r1) = ctx->f18.u32l;
    // 0x80007744: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80007748: addiu       $t4, $t4, -0x5B58
    ctx->r12 = ADD32(ctx->r12, -0X5B58);
    // 0x8000774C: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80007750: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007754: swc1        $f4, 0x619C($at)
    MEM_W(0X619C, ctx->r1) = ctx->f4.u32l;
    // 0x80007758: lw          $t5, 0x1B8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1B8);
    // 0x8000775C: nop

    // 0x80007760: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80007764: jal         0x800C13B8
    // 0x80007768: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_52;
    // 0x80007768: nop

    after_52:
    // 0x8000776C: jal         0x80098820
    // 0x80007770: nop

    func_80098820(rdram, ctx);
        goto after_53;
    // 0x80007770: nop

    after_53:
    // 0x80007774: b           L_8000777C
    // 0x80007778: nop

        goto L_8000777C;
    // 0x80007778: nop

L_8000777C:
    // 0x8000777C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80007780: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80007784: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80007788: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000778C: jr          $ra
    // 0x80007790: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
    return;
    // 0x80007790: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
;}
RECOMP_FUNC void func_80007794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007794: nop

    // 0x80007798: nop

    // 0x8000779C: nop

;}
RECOMP_FUNC void func_800077A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800077A0: addiu       $sp, $sp, -0x500
    ctx->r29 = ADD32(ctx->r29, -0X500);
    // 0x800077A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800077A8: sw          $a0, 0x500($sp)
    MEM_W(0X500, ctx->r29) = ctx->r4;
    // 0x800077AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800077B0: lw          $t6, 0x500($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X500);
    // 0x800077B4: nop

    // 0x800077B8: sw          $t6, 0x4F0($sp)
    MEM_W(0X4F0, ctx->r29) = ctx->r14;
    // 0x800077BC: lw          $t7, 0x4F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4F0);
    // 0x800077C0: nop

    // 0x800077C4: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x800077C8: nop

    // 0x800077CC: sw          $t8, 0x4EC($sp)
    MEM_W(0X4EC, ctx->r29) = ctx->r24;
    // 0x800077D0: jal         0x800045AC
    // 0x800077D4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800045AC(rdram, ctx);
        goto after_0;
    // 0x800077D4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x800077D8: sw          $v0, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r2;
    // 0x800077DC: lw          $t9, 0x378($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X378);
    // 0x800077E0: nop

    // 0x800077E4: beq         $t9, $zero, L_80007804
    if (ctx->r25 == 0) {
        // 0x800077E8: nop

            goto L_80007804;
    }
    // 0x800077E8: nop

    // 0x800077EC: lw          $t0, 0x378($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X378);
    // 0x800077F0: nop

    // 0x800077F4: lw          $t1, 0x1A0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A0);
    // 0x800077F8: nop

    // 0x800077FC: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80007800: sw          $t2, 0x1A0($t0)
    MEM_W(0X1A0, ctx->r8) = ctx->r10;
L_80007804:
    // 0x80007804: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80007808: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x8000780C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007810: bne         $t3, $at, L_8000784C
    if (ctx->r11 != ctx->r1) {
        // 0x80007814: nop

            goto L_8000784C;
    }
    // 0x80007814: nop

    // 0x80007818: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8000781C: addiu       $t4, $t4, -0x6070
    ctx->r12 = ADD32(ctx->r12, -0X6070);
    // 0x80007820: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007824: sw          $t4, -0x5B34($at)
    MEM_W(-0X5B34, ctx->r1) = ctx->r12;
    // 0x80007828: lui         $t5, 0x8099
    ctx->r13 = S32(0X8099 << 16);
    // 0x8000782C: addiu       $t5, $t5, 0x75C0
    ctx->r13 = ADD32(ctx->r13, 0X75C0);
    // 0x80007830: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007834: sw          $t5, -0x5B3C($at)
    MEM_W(-0X5B3C, ctx->r1) = ctx->r13;
    // 0x80007838: lui         $t6, 0x8099
    ctx->r14 = S32(0X8099 << 16);
    // 0x8000783C: addiu       $t6, $t6, 0x7600
    ctx->r14 = ADD32(ctx->r14, 0X7600);
    // 0x80007840: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007844: b           L_80007890
    // 0x80007848: sw          $t6, -0x5B38($at)
    MEM_W(-0X5B38, ctx->r1) = ctx->r14;
        goto L_80007890;
    // 0x80007848: sw          $t6, -0x5B38($at)
    MEM_W(-0X5B38, ctx->r1) = ctx->r14;
L_8000784C:
    // 0x8000784C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80007850: lh          $t7, 0x723C($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X723C);
    // 0x80007854: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80007858: bne         $t7, $at, L_80007890
    if (ctx->r15 != ctx->r1) {
        // 0x8000785C: nop

            goto L_80007890;
    }
    // 0x8000785C: nop

    // 0x80007860: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80007864: addiu       $t8, $t8, -0x5DD0
    ctx->r24 = ADD32(ctx->r24, -0X5DD0);
    // 0x80007868: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000786C: sw          $t8, -0x5B34($at)
    MEM_W(-0X5B34, ctx->r1) = ctx->r24;
    // 0x80007870: lui         $t9, 0x8099
    ctx->r25 = S32(0X8099 << 16);
    // 0x80007874: addiu       $t9, $t9, 0x7740
    ctx->r25 = ADD32(ctx->r25, 0X7740);
    // 0x80007878: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000787C: sw          $t9, -0x5B3C($at)
    MEM_W(-0X5B3C, ctx->r1) = ctx->r25;
    // 0x80007880: lui         $t1, 0x8099
    ctx->r9 = S32(0X8099 << 16);
    // 0x80007884: addiu       $t1, $t1, 0x7770
    ctx->r9 = ADD32(ctx->r9, 0X7770);
    // 0x80007888: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000788C: sw          $t1, -0x5B38($at)
    MEM_W(-0X5B38, ctx->r1) = ctx->r9;
L_80007890:
    // 0x80007890: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007894: sw          $zero, -0x5B40($at)
    MEM_W(-0X5B40, ctx->r1) = 0;
    // 0x80007898: sw          $zero, 0x374($sp)
    MEM_W(0X374, ctx->r29) = 0;
    // 0x8000789C: sw          $zero, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = 0;
    // 0x800078A0: sw          $zero, 0x370($sp)
    MEM_W(0X370, ctx->r29) = 0;
    // 0x800078A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800078A8: nop

    // 0x800078AC: swc1        $f4, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->f4.u32l;
    // 0x800078B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800078B4: nop

    // 0x800078B8: swc1        $f6, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->f6.u32l;
    // 0x800078BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800078C0: nop

    // 0x800078C4: swc1        $f8, 0x35C($sp)
    MEM_W(0X35C, ctx->r29) = ctx->f8.u32l;
    // 0x800078C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800078CC: nop

    // 0x800078D0: swc1        $f10, 0x360($sp)
    MEM_W(0X360, ctx->r29) = ctx->f10.u32l;
    // 0x800078D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800078D8: nop

    // 0x800078DC: swc1        $f16, 0x364($sp)
    MEM_W(0X364, ctx->r29) = ctx->f16.u32l;
    // 0x800078E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800078E4: nop

    // 0x800078E8: swc1        $f18, 0x368($sp)
    MEM_W(0X368, ctx->r29) = ctx->f18.u32l;
    // 0x800078EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800078F0: jal         0x80099E2C
    // 0x800078F4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_80099E2C(rdram, ctx);
        goto after_1;
    // 0x800078F4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_1:
    // 0x800078F8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x800078FC: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x80007900: lh          $a2, 0x7280($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7280);
    // 0x80007904: lh          $a1, 0x7274($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7274);
    // 0x80007908: jal         0x80008FF0
    // 0x8000790C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_80008FF0(rdram, ctx);
        goto after_2;
    // 0x8000790C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80007910: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80007914: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x80007918: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000791C: lw          $t0, 0x138($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X138);
    // 0x80007920: nop

    // 0x80007924: sw          $t0, -0x5B2C($at)
    MEM_W(-0X5B2C, ctx->r1) = ctx->r8;
    // 0x80007928: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000792C: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x80007930: nop

    // 0x80007934: lh          $a0, 0x122($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X122);
    // 0x80007938: nop

    // 0x8000793C: sll         $t4, $a0, 8
    ctx->r12 = S32(ctx->r4 << 8);
    // 0x80007940: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80007944: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x80007948: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8000794C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80007950: jal         0x800BC6EC
    // 0x80007954: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    SysMem_HeapAlloc(rdram, ctx);
        goto after_3;
    // 0x80007954: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x80007958: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000795C: lw          $t7, -0x73E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X73E8);
    // 0x80007960: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80007964: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007968: sw          $s0, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r16;
    // 0x8000796C: sw          $s0, -0x5B30($at)
    MEM_W(-0X5B30, ctx->r1) = ctx->r16;
    // 0x80007970: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80007974: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x80007978: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8000797C: lh          $a2, 0x122($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X122);
    // 0x80007980: lw          $a1, -0x5B2C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5B2C);
    // 0x80007984: lw          $a0, 0x138($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X138);
    // 0x80007988: sll         $t9, $a2, 8
    ctx->r25 = S32(ctx->r6 << 8);
    // 0x8000798C: jal         0x800BD038
    // 0x80007990: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    SysMem_Copy16(rdram, ctx);
        goto after_4;
    // 0x80007990: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_4:
    // 0x80007994: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80007998: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8000799C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800079A0: lh          $t0, 0x122($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X122);
    // 0x800079A4: lw          $t2, 0x138($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X138);
    // 0x800079A8: sll         $t3, $t0, 8
    ctx->r11 = S32(ctx->r8 << 8);
    // 0x800079AC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800079B0: lw          $a1, -0x5B2C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5B2C);
    // 0x800079B4: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800079B8: jal         0x800BD038
    // 0x800079BC: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    SysMem_Copy16(rdram, ctx);
        goto after_5;
    // 0x800079BC: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    after_5:
    // 0x800079C0: sw          $zero, 0x4FC($sp)
    MEM_W(0X4FC, ctx->r29) = 0;
L_800079C4:
    // 0x800079C4: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800079C8: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x800079CC: lw          $t6, 0x4FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4FC);
    // 0x800079D0: lh          $t0, 0x122($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X122);
    // 0x800079D4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x800079D8: lw          $t5, -0x5B30($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B30);
    // 0x800079DC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800079E0: sll         $t2, $t0, 8
    ctx->r10 = S32(ctx->r8 << 8);
    // 0x800079E4: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x800079E8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800079EC: lhu         $t9, 0x1D0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1D0);
    // 0x800079F0: addu        $t3, $t5, $t4
    ctx->r11 = ADD32(ctx->r13, ctx->r12);
    // 0x800079F4: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x800079F8: sh          $t9, 0x1E0($t6)
    MEM_H(0X1E0, ctx->r14) = ctx->r25;
    // 0x800079FC: lw          $t8, 0x4FC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4FC);
    // 0x80007A00: nop

    // 0x80007A04: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80007A08: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x80007A0C: bne         $at, $zero, L_800079C4
    if (ctx->r1 != 0) {
        // 0x80007A10: sw          $t1, 0x4FC($sp)
        MEM_W(0X4FC, ctx->r29) = ctx->r9;
            goto L_800079C4;
    }
    // 0x80007A10: sw          $t1, 0x4FC($sp)
    MEM_W(0X4FC, ctx->r29) = ctx->r9;
    // 0x80007A14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007A18: sw          $zero, -0x5B28($at)
    MEM_W(-0X5B28, ctx->r1) = 0;
    // 0x80007A1C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80007A20: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80007A24: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x80007A28: lw          $t0, -0x5B30($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5B30);
    // 0x80007A2C: nop

    // 0x80007A30: sw          $t0, 0x138($t2)
    MEM_W(0X138, ctx->r10) = ctx->r8;
    // 0x80007A34: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80007A38: lw          $a0, -0x5B34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B34);
    // 0x80007A3C: jal         0x80009D34
    // 0x80007A40: nop

    func_80009D34(rdram, ctx);
        goto after_6;
    // 0x80007A40: nop

    after_6:
    // 0x80007A44: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80007A48: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x80007A4C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80007A50: lh          $t4, 0x122($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X122);
    // 0x80007A54: lw          $t9, -0x5B30($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B30);
    // 0x80007A58: sll         $t3, $t4, 8
    ctx->r11 = S32(ctx->r12 << 8);
    // 0x80007A5C: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x80007A60: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80007A64: sw          $t6, 0x138($t5)
    MEM_W(0X138, ctx->r13) = ctx->r14;
    // 0x80007A68: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80007A6C: lw          $a0, -0x5B34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B34);
    // 0x80007A70: jal         0x80009D34
    // 0x80007A74: nop

    func_80009D34(rdram, ctx);
        goto after_7;
    // 0x80007A74: nop

    after_7:
    // 0x80007A78: jal         0x80009E5C
    // 0x80007A7C: nop

    func_80009E5C(rdram, ctx);
        goto after_8;
    // 0x80007A7C: nop

    after_8:
    // 0x80007A80: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80007A84: sw          $zero, -0x5B28($at)
    MEM_W(-0X5B28, ctx->r1) = 0;
    // 0x80007A88: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x80007A8C: addiu       $t1, $t8, 0x1C8
    ctx->r9 = ADD32(ctx->r24, 0X1C8);
    // 0x80007A90: sw          $t1, 0x380($sp)
    MEM_W(0X380, ctx->r29) = ctx->r9;
    // 0x80007A94: lw          $a0, 0x380($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X380);
    // 0x80007A98: jal         0x80099E2C
    // 0x80007A9C: nop

    func_80099E2C(rdram, ctx);
        goto after_9;
    // 0x80007A9C: nop

    after_9:
    // 0x80007AA0: lw          $t0, 0x380($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X380);
    // 0x80007AA4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80007AA8: lw          $t2, 0xC0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0XC0);
    // 0x80007AAC: nop

    // 0x80007AB0: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x80007AB4: sw          $t4, 0xC0($t0)
    MEM_W(0XC0, ctx->r8) = ctx->r12;
    // 0x80007AB8: lw          $t7, 0x380($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X380);
    // 0x80007ABC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80007AC0: sh          $t3, 0x116($t7)
    MEM_H(0X116, ctx->r15) = ctx->r11;
    // 0x80007AC4: lw          $t6, 0x380($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X380);
    // 0x80007AC8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80007ACC: sh          $t9, 0x114($t6)
    MEM_H(0X114, ctx->r14) = ctx->r25;
    // 0x80007AD0: lw          $t8, 0x380($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X380);
    // 0x80007AD4: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x80007AD8: sw          $t5, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->r13;
    // 0x80007ADC: lw          $t2, 0x380($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X380);
    // 0x80007AE0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80007AE4: sh          $t1, 0x100($t2)
    MEM_H(0X100, ctx->r10) = ctx->r9;
    // 0x80007AE8: lw          $t0, 0x380($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X380);
    // 0x80007AEC: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80007AF0: sh          $t4, 0x102($t0)
    MEM_H(0X102, ctx->r8) = ctx->r12;
    // 0x80007AF4: lw          $t7, 0x380($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X380);
    // 0x80007AF8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80007AFC: sh          $t3, 0x118($t7)
    MEM_H(0X118, ctx->r15) = ctx->r11;
    // 0x80007B00: lw          $t6, 0x380($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X380);
    // 0x80007B04: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80007B08: sh          $t9, 0x11A($t6)
    MEM_H(0X11A, ctx->r14) = ctx->r25;
    // 0x80007B0C: lw          $t8, 0x380($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X380);
    // 0x80007B10: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80007B14: sh          $t5, 0x11C($t8)
    MEM_H(0X11C, ctx->r24) = ctx->r13;
    // 0x80007B18: lw          $t2, 0x380($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X380);
    // 0x80007B1C: addiu       $t1, $zero, 0xAF
    ctx->r9 = ADD32(0, 0XAF);
    // 0x80007B20: sh          $t1, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r9;
    // 0x80007B24: lw          $t0, 0x380($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X380);
    // 0x80007B28: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x80007B2C: sh          $t4, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r12;
    // 0x80007B30: sw          $zero, 0x4F8($sp)
    MEM_W(0X4F8, ctx->r29) = 0;
    // 0x80007B34: lw          $t3, 0x4F8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4F8);
    // 0x80007B38: nop

    // 0x80007B3C: bne         $t3, $zero, L_800083D4
    if (ctx->r11 != 0) {
        // 0x80007B40: nop

            goto L_800083D4;
    }
    // 0x80007B40: nop

L_80007B44:
    // 0x80007B44: lw          $t7, 0x4F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007B48: addiu       $a1, $sp, 0x4E8
    ctx->r5 = ADD32(ctx->r29, 0X4E8);
    // 0x80007B4C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80007B50: jal         0x800C143C
    // 0x80007B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_10;
    // 0x80007B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80007B58: lw          $t9, 0x4E8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4E8);
    // 0x80007B5C: nop

    // 0x80007B60: lh          $s0, 0x0($t9)
    ctx->r16 = MEM_H(ctx->r25, 0X0);
    // 0x80007B64: nop

    // 0x80007B68: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80007B6C: bne         $at, $zero, L_80007B88
    if (ctx->r1 != 0) {
        // 0x80007B70: nop

            goto L_80007B88;
    }
    // 0x80007B70: nop

    // 0x80007B74: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80007B78: beq         $s0, $at, L_80008244
    if (ctx->r16 == ctx->r1) {
        // 0x80007B7C: nop

            goto L_80008244;
    }
    // 0x80007B7C: nop

    // 0x80007B80: b           L_800083BC
    // 0x80007B84: nop

        goto L_800083BC;
    // 0x80007B84: nop

L_80007B88:
    // 0x80007B88: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x80007B8C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80007B90: beq         $at, $zero, L_800083BC
    if (ctx->r1 == 0) {
        // 0x80007B94: nop

            goto L_800083BC;
    }
    // 0x80007B94: nop

    // 0x80007B98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80007B9C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80007BA0: addu        $at, $at, $t6
    gpr jr_addend_80007BAC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80007BA4: lw          $t6, -0x2E44($at)
    ctx->r14 = ADD32(ctx->r1, -0X2E44);
    // 0x80007BA8: nop

    // 0x80007BAC: jr          $t6
    // 0x80007BB0: nop

    switch (jr_addend_80007BAC >> 2) {
        case 0: goto L_80007BB4; break;
        case 1: goto L_80007E34; break;
        case 2: goto L_800083B4; break;
        case 3: goto L_8000839C; break;
        case 4: goto L_80007F18; break;
        default: switch_error(__func__, 0x80007BAC, 0x800ED1BC);
    }
    // 0x80007BB0: nop

L_80007BB4:
    // 0x80007BB4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80007BB8: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80007BBC: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x80007BC0: nop

    // 0x80007BC4: andi        $t1, $t8, 0x2
    ctx->r9 = ctx->r24 & 0X2;
    // 0x80007BC8: bne         $t1, $zero, L_80007E2C
    if (ctx->r9 != 0) {
        // 0x80007BCC: nop

            goto L_80007E2C;
    }
    // 0x80007BCC: nop

    // 0x80007BD0: lw          $t2, 0x4EC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007BD4: nop

    // 0x80007BD8: addiu       $t4, $t2, 0x7FFF
    ctx->r12 = ADD32(ctx->r10, 0X7FFF);
    // 0x80007BDC: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x80007BE0: nop

    // 0x80007BE4: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80007BE8: beq         $at, $zero, L_80007E2C
    if (ctx->r1 == 0) {
        // 0x80007BEC: nop

            goto L_80007E2C;
    }
    // 0x80007BEC: nop

    // 0x80007BF0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80007BF4: lw          $t0, 0x258C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X258C);
    // 0x80007BF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80007BFC: sw          $t0, 0x30AC($at)
    MEM_W(0X30AC, ctx->r1) = ctx->r8;
    // 0x80007C00: jal         0x80099768
    // 0x80007C04: nop

    func_80099768(rdram, ctx);
        goto after_11;
    // 0x80007C04: nop

    after_11:
    // 0x80007C08: jal         0x800AFB28
    // 0x80007C0C: nop

    func_800AFB28(rdram, ctx);
        goto after_12;
    // 0x80007C0C: nop

    after_12:
    // 0x80007C10: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80007C14: lw          $t7, -0x4CC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CC4);
    // 0x80007C18: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80007C1C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80007C20: lw          $t3, -0x4CCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4CCC);
    // 0x80007C24: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80007C28: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80007C2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80007C30: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x80007C34: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80007C38: jal         0x800BE510
    // 0x80007C3C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800BE510(rdram, ctx);
        goto after_13;
    // 0x80007C3C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_13:
    // 0x80007C40: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80007C44: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80007C48: lw          $t6, -0x4CC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CC4);
    // 0x80007C4C: lw          $t9, -0x4CCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CCC);
    // 0x80007C50: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80007C54: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80007C58: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80007C5C: jal         0x8009A04C
    // 0x80007C60: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_8009A04C(rdram, ctx);
        goto after_14;
    // 0x80007C60: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_14:
    // 0x80007C64: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80007C68: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80007C6C: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x80007C70: nop

    // 0x80007C74: andi        $t1, $t8, 0x8
    ctx->r9 = ctx->r24 & 0X8;
    // 0x80007C78: beq         $t1, $zero, L_80007C88
    if (ctx->r9 == 0) {
        // 0x80007C7C: nop

            goto L_80007C88;
    }
    // 0x80007C7C: nop

    // 0x80007C80: jal         0x80033788
    // 0x80007C84: nop

    func_80033788(rdram, ctx);
        goto after_15;
    // 0x80007C84: nop

    after_15:
L_80007C88:
    // 0x80007C88: jal         0x80032604
    // 0x80007C8C: nop

    func_80032604(rdram, ctx);
        goto after_16;
    // 0x80007C8C: nop

    after_16:
    // 0x80007C90: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80007C94: addiu       $t2, $t2, 0x7340
    ctx->r10 = ADD32(ctx->r10, 0X7340);
    // 0x80007C98: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80007C9C: jal         0x8000262C
    // 0x80007CA0: addiu       $a1, $t2, 0x580
    ctx->r5 = ADD32(ctx->r10, 0X580);
    func_8000262C(rdram, ctx);
        goto after_17;
    // 0x80007CA0: addiu       $a1, $t2, 0x580
    ctx->r5 = ADD32(ctx->r10, 0X580);
    after_17:
    // 0x80007CA4: jal         0x80002824
    // 0x80007CA8: nop

    func_80002824(rdram, ctx);
        goto after_18;
    // 0x80007CA8: nop

    after_18:
    // 0x80007CAC: jal         0x8000849C
    // 0x80007CB0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8000849C(rdram, ctx);
        goto after_19;
    // 0x80007CB0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_19:
    // 0x80007CB4: jal         0x800305A4
    // 0x80007CB8: nop

    func_800305A4(rdram, ctx);
        goto after_20;
    // 0x80007CB8: nop

    after_20:
    // 0x80007CBC: jal         0x8002A39C
    // 0x80007CC0: nop

    func_8002A39C(rdram, ctx);
        goto after_21;
    // 0x80007CC0: nop

    after_21:
    // 0x80007CC4: jal         0x80082958
    // 0x80007CC8: nop

    func_80082958(rdram, ctx);
        goto after_22;
    // 0x80007CC8: nop

    after_22:
    // 0x80007CCC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80007CD0: lw          $t4, -0x73AC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73AC);
    // 0x80007CD4: nop

    // 0x80007CD8: beq         $t4, $zero, L_80007D2C
    if (ctx->r12 == 0) {
        // 0x80007CDC: sw          $t4, 0x384($sp)
        MEM_W(0X384, ctx->r29) = ctx->r12;
            goto L_80007D2C;
    }
    // 0x80007CDC: sw          $t4, 0x384($sp)
    MEM_W(0X384, ctx->r29) = ctx->r12;
L_80007CE0:
    // 0x80007CE0: jal         0x800C1754
    // 0x80007CE4: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_23;
    // 0x80007CE4: nop

    after_23:
    // 0x80007CE8: lw          $a0, 0x384($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X384);
    // 0x80007CEC: jal         0x8009A14C
    // 0x80007CF0: nop

    func_8009A14C(rdram, ctx);
        goto after_24;
    // 0x80007CF0: nop

    after_24:
    // 0x80007CF4: lw          $a0, 0x384($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X384);
    // 0x80007CF8: jal         0x800997D8
    // 0x80007CFC: nop

    func_800997D8(rdram, ctx);
        goto after_25;
    // 0x80007CFC: nop

    after_25:
    // 0x80007D00: jal         0x800C1A28
    // 0x80007D04: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_26;
    // 0x80007D04: nop

    after_26:
    // 0x80007D08: lw          $t0, 0x384($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X384);
    // 0x80007D0C: nop

    // 0x80007D10: lw          $t3, 0x14C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X14C);
    // 0x80007D14: nop

    // 0x80007D18: sw          $t3, 0x384($sp)
    MEM_W(0X384, ctx->r29) = ctx->r11;
    // 0x80007D1C: lw          $t7, 0x384($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X384);
    // 0x80007D20: nop

    // 0x80007D24: bne         $t7, $zero, L_80007CE0
    if (ctx->r15 != 0) {
        // 0x80007D28: nop

            goto L_80007CE0;
    }
    // 0x80007D28: nop

L_80007D2C:
    // 0x80007D2C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80007D30: addiu       $t9, $t9, -0x7278
    ctx->r25 = ADD32(ctx->r25, -0X7278);
    // 0x80007D34: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x80007D38: nop

    // 0x80007D3C: andi        $t5, $t6, 0x100
    ctx->r13 = ctx->r14 & 0X100;
    // 0x80007D40: bne         $t5, $zero, L_80007D64
    if (ctx->r13 != 0) {
        // 0x80007D44: nop

            goto L_80007D64;
    }
    // 0x80007D44: nop

    // 0x80007D48: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80007D4C: jal         0x8009A664
    // 0x80007D50: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_27;
    // 0x80007D50: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_27:
    // 0x80007D54: jal         0x8002C2F8
    // 0x80007D58: nop

    func_8002C2F8(rdram, ctx);
        goto after_28;
    // 0x80007D58: nop

    after_28:
    // 0x80007D5C: b           L_80007D78
    // 0x80007D60: nop

        goto L_80007D78;
    // 0x80007D60: nop

L_80007D64:
    // 0x80007D64: jal         0x8002C2F8
    // 0x80007D68: nop

    func_8002C2F8(rdram, ctx);
        goto after_29;
    // 0x80007D68: nop

    after_29:
    // 0x80007D6C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80007D70: jal         0x8009A664
    // 0x80007D74: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_30;
    // 0x80007D74: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_30:
L_80007D78:
    // 0x80007D78: jal         0x8001635C
    // 0x80007D7C: nop

    func_8001635C(rdram, ctx);
        goto after_31;
    // 0x80007D7C: nop

    after_31:
    // 0x80007D80: jal         0x800BE684
    // 0x80007D84: nop

    func_800BE684(rdram, ctx);
        goto after_32;
    // 0x80007D84: nop

    after_32:
    // 0x80007D88: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80007D8C: jal         0x8009A664
    // 0x80007D90: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_33;
    // 0x80007D90: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_33:
    // 0x80007D94: jal         0x800BE610
    // 0x80007D98: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_34;
    // 0x80007D98: nop

    after_34:
    // 0x80007D9C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80007DA0: lw          $t8, 0x1B4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1B4C);
    // 0x80007DA4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80007DA8: lw          $t1, 0x1B44($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1B44);
    // 0x80007DAC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80007DB0: jal         0x8009908C
    // 0x80007DB4: subu        $a1, $t1, $t8
    ctx->r5 = SUB32(ctx->r9, ctx->r24);
    CreateGfxTask(rdram, ctx);
        goto after_35;
    // 0x80007DB4: subu        $a1, $t1, $t8
    ctx->r5 = SUB32(ctx->r9, ctx->r24);
    after_35:
    // 0x80007DB8: lw          $t2, 0x4F0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007DBC: nop

    // 0x80007DC0: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80007DC4: jal         0x80098D24
    // 0x80007DC8: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_36;
    // 0x80007DC8: nop

    after_36:
    // 0x80007DCC: jal         0x80099450
    // 0x80007DD0: nop

    func_80099450(rdram, ctx);
        goto after_37;
    // 0x80007DD0: nop

    after_37:
    // 0x80007DD4: jal         0x80001F54
    // 0x80007DD8: nop

    func_80001F54(rdram, ctx);
        goto after_38;
    // 0x80007DD8: nop

    after_38:
    // 0x80007DDC: jal         0x800020A8
    // 0x80007DE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800020A8(rdram, ctx);
        goto after_39;
    // 0x80007DE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_39:
    // 0x80007DE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007DE8: bne         $v0, $at, L_80007E10
    if (ctx->r2 != ctx->r1) {
        // 0x80007DEC: nop

            goto L_80007E10;
    }
    // 0x80007DEC: nop

    // 0x80007DF0: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80007DF4: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80007DF8: lhu         $t0, 0x0($t4)
    ctx->r8 = MEM_HU(ctx->r12, 0X0);
    // 0x80007DFC: nop

    // 0x80007E00: ori         $t3, $t0, 0x2
    ctx->r11 = ctx->r8 | 0X2;
    // 0x80007E04: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x80007E08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80007E0C: sw          $t7, 0x4F8($sp)
    MEM_W(0X4F8, ctx->r29) = ctx->r15;
L_80007E10:
    // 0x80007E10: lw          $t9, 0x4EC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007E14: nop

    // 0x80007E18: addiu       $t6, $t9, 0x7FFF
    ctx->r14 = ADD32(ctx->r25, 0X7FFF);
    // 0x80007E1C: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x80007E20: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80007E24: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80007E28: sw          $t5, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r13;
L_80007E2C:
    // 0x80007E2C: b           L_800083C4
    // 0x80007E30: nop

        goto L_800083C4;
    // 0x80007E30: nop

L_80007E34:
    // 0x80007E34: lw          $t1, 0x4EC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007E38: nop

    // 0x80007E3C: addiu       $t8, $t1, 0x7FFF
    ctx->r24 = ADD32(ctx->r9, 0X7FFF);
    // 0x80007E40: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x80007E44: nop

    // 0x80007E48: beq         $t8, $zero, L_80007E8C
    if (ctx->r24 == 0) {
        // 0x80007E4C: nop

            goto L_80007E8C;
    }
    // 0x80007E4C: nop

    // 0x80007E50: jal         0x80099520
    // 0x80007E54: nop

    func_80099520(rdram, ctx);
        goto after_40;
    // 0x80007E54: nop

    after_40:
    // 0x80007E58: lw          $t2, 0x4EC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007E5C: nop

    // 0x80007E60: addiu       $t0, $t2, 0x7FFF
    ctx->r8 = ADD32(ctx->r10, 0X7FFF);
    // 0x80007E64: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x80007E68: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x80007E6C: addiu       $t3, $t0, -0x1
    ctx->r11 = ADD32(ctx->r8, -0X1);
    // 0x80007E70: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x80007E74: jal         0x800C40D0
    // 0x80007E78: nop

    osGetTime_recomp(rdram, ctx);
        goto after_41;
    // 0x80007E78: nop

    after_41:
    // 0x80007E7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80007E80: sw          $v0, 0x19A8($at)
    MEM_W(0X19A8, ctx->r1) = ctx->r2;
    // 0x80007E84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80007E88: sw          $v1, 0x19AC($at)
    MEM_W(0X19AC, ctx->r1) = ctx->r3;
L_80007E8C:
    // 0x80007E8C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80007E90: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x80007E94: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x80007E98: nop

    // 0x80007E9C: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x80007EA0: beq         $t6, $zero, L_80007F10
    if (ctx->r14 == 0) {
        // 0x80007EA4: nop

            goto L_80007F10;
    }
    // 0x80007EA4: nop

    // 0x80007EA8: lw          $a0, 0x4F0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007EAC: jal         0x800065BC
    // 0x80007EB0: nop

    func_800065BC(rdram, ctx);
        goto after_42;
    // 0x80007EB0: nop

    after_42:
    // 0x80007EB4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80007EB8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80007EBC: lh          $t9, 0x7234($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7234);
    // 0x80007EC0: lh          $t5, 0x7320($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7320);
    // 0x80007EC4: nop

    // 0x80007EC8: bne         $t5, $t9, L_80007EEC
    if (ctx->r13 != ctx->r25) {
        // 0x80007ECC: nop

            goto L_80007EEC;
    }
    // 0x80007ECC: nop

    // 0x80007ED0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80007ED4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80007ED8: lh          $t8, 0x723C($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X723C);
    // 0x80007EDC: lh          $t1, 0x7338($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7338);
    // 0x80007EE0: nop

    // 0x80007EE4: beq         $t1, $t8, L_80007F10
    if (ctx->r9 == ctx->r24) {
        // 0x80007EE8: nop

            goto L_80007F10;
    }
    // 0x80007EE8: nop

L_80007EEC:
    // 0x80007EEC: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80007EF0: lh          $t0, 0x7320($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X7320);
    // 0x80007EF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80007EF8: ori         $t3, $t0, 0x8000
    ctx->r11 = ctx->r8 | 0X8000;
    // 0x80007EFC: sh          $t3, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r11;
    // 0x80007F00: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80007F04: lh          $t2, 0x7338($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7338);
    // 0x80007F08: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80007F0C: sh          $t2, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r10;
L_80007F10:
    // 0x80007F10: b           L_800083C4
    // 0x80007F14: nop

        goto L_800083C4;
    // 0x80007F14: nop

L_80007F18:
    // 0x80007F18: jal         0x80032604
    // 0x80007F1C: nop

    func_80032604(rdram, ctx);
        goto after_43;
    // 0x80007F1C: nop

    after_43:
    // 0x80007F20: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80007F24: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x80007F28: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80007F2C: lhu         $t6, 0x11A4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X11A4);
    // 0x80007F30: lhu         $t7, 0x6($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X6);
    // 0x80007F34: nop

    // 0x80007F38: and         $t5, $t7, $t6
    ctx->r13 = ctx->r15 & ctx->r14;
    // 0x80007F3C: bne         $t5, $zero, L_80007F58
    if (ctx->r13 != 0) {
        // 0x80007F40: nop

            goto L_80007F58;
    }
    // 0x80007F40: nop

    // 0x80007F44: lhu         $t9, 0x2E($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X2E);
    // 0x80007F48: nop

    // 0x80007F4C: and         $t1, $t9, $t6
    ctx->r9 = ctx->r25 & ctx->r14;
    // 0x80007F50: beq         $t1, $zero, L_80007FA8
    if (ctx->r9 == 0) {
        // 0x80007F54: nop

            goto L_80007FA8;
    }
    // 0x80007F54: nop

L_80007F58:
    // 0x80007F58: jal         0x80098BF4
    // 0x80007F5C: nop

    func_80098BF4(rdram, ctx);
        goto after_44;
    // 0x80007F5C: nop

    after_44:
    // 0x80007F60: lw          $t8, 0x4EC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4EC);
    // 0x80007F64: nop

    // 0x80007F68: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x80007F6C: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80007F70: lw          $t0, 0x4F0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007F74: nop

    // 0x80007F78: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80007F7C: jal         0x800C13B8
    // 0x80007F80: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_45;
    // 0x80007F80: nop

    after_45:
    // 0x80007F84: jal         0x80098820
    // 0x80007F88: nop

    func_80098820(rdram, ctx);
        goto after_46;
    // 0x80007F88: nop

    after_46:
    // 0x80007F8C: lw          $t3, 0x4F0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4F0);
    // 0x80007F90: nop

    // 0x80007F94: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    // 0x80007F98: jal         0x80098D24
    // 0x80007F9C: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_47;
    // 0x80007F9C: nop

    after_47:
    // 0x80007FA0: b           L_800083C4
    // 0x80007FA4: nop

        goto L_800083C4;
    // 0x80007FA4: nop

L_80007FA8:
    // 0x80007FA8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80007FAC: addiu       $t2, $t2, -0x7278
    ctx->r10 = ADD32(ctx->r10, -0X7278);
    // 0x80007FB0: lhu         $t7, 0x0($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X0);
    // 0x80007FB4: nop

    // 0x80007FB8: andi        $t5, $t7, 0x20
    ctx->r13 = ctx->r15 & 0X20;
    // 0x80007FBC: beq         $t5, $zero, L_80008080
    if (ctx->r13 == 0) {
        // 0x80007FC0: nop

            goto L_80008080;
    }
    // 0x80007FC0: nop

    // 0x80007FC4: jal         0x80096474
    // 0x80007FC8: nop

    func_80096474(rdram, ctx);
        goto after_48;
    // 0x80007FC8: nop

    after_48:
    // 0x80007FCC: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80007FD0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80007FD4: sw          $t4, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r12;
    // 0x80007FD8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80007FDC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80007FE0: sw          $t9, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r25;
    // 0x80007FE4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80007FE8: sh          $zero, -0x4CC8($at)
    MEM_H(-0X4CC8, ctx->r1) = 0;
    // 0x80007FEC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80007FF0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007FF4: sw          $t6, 0x6C08($at)
    MEM_W(0X6C08, ctx->r1) = ctx->r14;
    // 0x80007FF8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80007FFC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80008000: sw          $t1, 0x6BC0($at)
    MEM_W(0X6BC0, ctx->r1) = ctx->r9;
    // 0x80008004: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80008008: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000800C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80008010: swc1        $f16, -0x4CBC($at)
    MEM_W(-0X4CBC, ctx->r1) = ctx->f16.u32l;
    // 0x80008014: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80008018: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000801C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80008020: swc1        $f18, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f18.u32l;
    // 0x80008024: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80008028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000802C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80008030: swc1        $f4, -0x4510($at)
    MEM_W(-0X4510, ctx->r1) = ctx->f4.u32l;
    // 0x80008034: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80008038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000803C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80008040: swc1        $f6, -0x44D8($at)
    MEM_W(-0X44D8, ctx->r1) = ctx->f6.u32l;
    // 0x80008044: jal         0x80090728
    // 0x80008048: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_80090728(rdram, ctx);
        goto after_49;
    // 0x80008048: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_49:
    // 0x8000804C: jal         0x800C4160
    // 0x80008050: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_50;
    // 0x80008050: nop

    after_50:
    // 0x80008054: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80008058: jal         0x8008ECCC
    // 0x8000805C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Sys_SwapFrameBuffer(rdram, ctx);
        goto after_51;
    // 0x8000805C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80008060: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80008064: jal         0x8008EAA8
    // 0x80008068: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8008EAA8(rdram, ctx);
        goto after_52;
    // 0x80008068: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_52:
    // 0x8000806C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80008070: jal         0x8008ECE4
    // 0x80008074: addiu       $a0, $a0, -0x2E50
    ctx->r4 = ADD32(ctx->r4, -0X2E50);
    func_8008ECE4(rdram, ctx);
        goto after_53;
    // 0x80008074: addiu       $a0, $a0, -0x2E50
    ctx->r4 = ADD32(ctx->r4, -0X2E50);
    after_53:
    // 0x80008078: jal         0x800967D8
    // 0x8000807C: nop

    func_800967D8(rdram, ctx);
        goto after_54;
    // 0x8000807C: nop

    after_54:
L_80008080:
    // 0x80008080: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80008084: addiu       $t8, $t8, 0x60F0
    ctx->r24 = ADD32(ctx->r24, 0X60F0);
    // 0x80008088: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000808C: lhu         $t3, 0x1038($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1038);
    // 0x80008090: lhu         $t0, 0x6($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X6);
    // 0x80008094: nop

    // 0x80008098: and         $t2, $t0, $t3
    ctx->r10 = ctx->r8 & ctx->r11;
    // 0x8000809C: beq         $t2, $zero, L_800080DC
    if (ctx->r10 == 0) {
        // 0x800080A0: nop

            goto L_800080DC;
    }
    // 0x800080A0: nop

    // 0x800080A4: jal         0x80098868
    // 0x800080A8: nop

    func_80098868(rdram, ctx);
        goto after_55;
    // 0x800080A8: nop

    after_55:
    // 0x800080AC: jal         0x80098C1C
    // 0x800080B0: nop

    func_80098C1C(rdram, ctx);
        goto after_56;
    // 0x800080B0: nop

    after_56:
    // 0x800080B4: jal         0x80098820
    // 0x800080B8: nop

    func_80098820(rdram, ctx);
        goto after_57;
    // 0x800080B8: nop

    after_57:
    // 0x800080BC: lw          $t7, 0x4F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4F0);
    // 0x800080C0: nop

    // 0x800080C4: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x800080C8: jal         0x80098D24
    // 0x800080CC: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_58;
    // 0x800080CC: nop

    after_58:
    // 0x800080D0: sw          $zero, 0x4F4($sp)
    MEM_W(0X4F4, ctx->r29) = 0;
    // 0x800080D4: b           L_800083C4
    // 0x800080D8: nop

        goto L_800083C4;
    // 0x800080D8: nop

L_800080DC:
    // 0x800080DC: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800080E0: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x800080E4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800080E8: lhu         $t9, 0x1042($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X1042);
    // 0x800080EC: lhu         $t4, 0x6($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X6);
    // 0x800080F0: nop

    // 0x800080F4: and         $t6, $t4, $t9
    ctx->r14 = ctx->r12 & ctx->r25;
    // 0x800080F8: beq         $t6, $zero, L_80008228
    if (ctx->r14 == 0) {
        // 0x800080FC: nop

            goto L_80008228;
    }
    // 0x800080FC: nop

    // 0x80008100: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80008104: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x80008108: lhu         $t8, 0x0($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X0);
    // 0x8000810C: nop

    // 0x80008110: ori         $t0, $t8, 0x4
    ctx->r8 = ctx->r24 | 0X4;
    // 0x80008114: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x80008118: jal         0x80098CD8
    // 0x8000811C: nop

    func_80098CD8(rdram, ctx);
        goto after_59;
    // 0x8000811C: nop

    after_59:
    // 0x80008120: jal         0x80098BF4
    // 0x80008124: nop

    func_80098BF4(rdram, ctx);
        goto after_60;
    // 0x80008124: nop

    after_60:
    // 0x80008128: jal         0x80098820
    // 0x8000812C: nop

    func_80098820(rdram, ctx);
        goto after_61;
    // 0x8000812C: nop

    after_61:
    // 0x80008130: jal         0x80098868
    // 0x80008134: nop

    func_80098868(rdram, ctx);
        goto after_62;
    // 0x80008134: nop

    after_62:
    // 0x80008138: lw          $t3, 0x4EC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4EC);
    // 0x8000813C: nop

    // 0x80008140: addiu       $at, $t3, 0x7FFF
    ctx->r1 = ADD32(ctx->r11, 0X7FFF);
    // 0x80008144: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x80008148: lw          $t2, 0x4F0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4F0);
    // 0x8000814C: nop

    // 0x80008150: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x80008154: jal         0x800C13B8
    // 0x80008158: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_63;
    // 0x80008158: nop

    after_63:
    // 0x8000815C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80008160: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x80008164: lhu         $t5, 0x0($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X0);
    // 0x80008168: nop

    // 0x8000816C: ori         $t4, $t5, 0x8000
    ctx->r12 = ctx->r13 | 0X8000;
    // 0x80008170: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
    // 0x80008174: lw          $a0, 0x4F0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4F0);
    // 0x80008178: jal         0x800065BC
    // 0x8000817C: nop

    func_800065BC(rdram, ctx);
        goto after_64;
    // 0x8000817C: nop

    after_64:
    // 0x80008180: jal         0x80098CFC
    // 0x80008184: nop

    func_80098CFC(rdram, ctx);
        goto after_65;
    // 0x80008184: nop

    after_65:
    // 0x80008188: jal         0x80098BB8
    // 0x8000818C: nop

    func_80098BB8(rdram, ctx);
        goto after_66;
    // 0x8000818C: nop

    after_66:
    // 0x80008190: jal         0x80098C1C
    // 0x80008194: nop

    func_80098C1C(rdram, ctx);
        goto after_67;
    // 0x80008194: nop

    after_67:
    // 0x80008198: jal         0x80098868
    // 0x8000819C: nop

    func_80098868(rdram, ctx);
        goto after_68;
    // 0x8000819C: nop

    after_68:
    // 0x800081A0: jal         0x80098820
    // 0x800081A4: nop

    func_80098820(rdram, ctx);
        goto after_69;
    // 0x800081A4: nop

    after_69:
    // 0x800081A8: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x800081AC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x800081B0: lh          $t6, 0x7234($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7234);
    // 0x800081B4: lh          $t9, 0x7320($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X7320);
    // 0x800081B8: nop

    // 0x800081BC: bne         $t9, $t6, L_800081E0
    if (ctx->r25 != ctx->r14) {
        // 0x800081C0: nop

            goto L_800081E0;
    }
    // 0x800081C0: nop

    // 0x800081C4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x800081C8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x800081CC: lh          $t0, 0x723C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X723C);
    // 0x800081D0: lh          $t8, 0x7338($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7338);
    // 0x800081D4: nop

    // 0x800081D8: beq         $t8, $t0, L_8000820C
    if (ctx->r24 == ctx->r8) {
        // 0x800081DC: nop

            goto L_8000820C;
    }
    // 0x800081DC: nop

L_800081E0:
    // 0x800081E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x800081E4: lh          $t1, 0x7320($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X7320);
    // 0x800081E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800081EC: ori         $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 | 0X8000;
    // 0x800081F0: sh          $t3, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r11;
    // 0x800081F4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x800081F8: lh          $t2, 0x7338($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X7338);
    // 0x800081FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008200: sh          $t2, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r10;
    // 0x80008204: jal         0x80098BF4
    // 0x80008208: nop

    func_80098BF4(rdram, ctx);
        goto after_70;
    // 0x80008208: nop

    after_70:
L_8000820C:
    // 0x8000820C: lw          $t5, 0x4F0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4F0);
    // 0x80008210: nop

    // 0x80008214: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x80008218: jal         0x80098D24
    // 0x8000821C: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_71;
    // 0x8000821C: nop

    after_71:
    // 0x80008220: b           L_800083C4
    // 0x80008224: nop

        goto L_800083C4;
    // 0x80008224: nop

L_80008228:
    // 0x80008228: lw          $t4, 0x4F0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4F0);
    // 0x8000822C: nop

    // 0x80008230: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    // 0x80008234: jal         0x80098D24
    // 0x80008238: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_72;
    // 0x80008238: nop

    after_72:
    // 0x8000823C: b           L_800083C4
    // 0x80008240: nop

        goto L_800083C4;
    // 0x80008240: nop

L_80008244:
    // 0x80008244: lw          $t7, 0x4F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4F0);
    // 0x80008248: addiu       $a1, $sp, 0x4E8
    ctx->r5 = ADD32(ctx->r29, 0X4E8);
    // 0x8000824C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80008250: jal         0x800C143C
    // 0x80008254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_73;
    // 0x80008254: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_73:
    // 0x80008258: lw          $t9, 0x4E8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4E8);
    // 0x8000825C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80008260: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x80008264: nop

    // 0x80008268: bne         $t6, $at, L_800082A4
    if (ctx->r14 != ctx->r1) {
        // 0x8000826C: nop

            goto L_800082A4;
    }
    // 0x8000826C: nop

    // 0x80008270: b           L_80008278
    // 0x80008274: nop

        goto L_80008278;
    // 0x80008274: nop

L_80008278:
    // 0x80008278: jal         0x80099520
    // 0x8000827C: nop

    func_80099520(rdram, ctx);
        goto after_74;
    // 0x8000827C: nop

    after_74:
    // 0x80008280: lw          $t8, 0x4EC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4EC);
    // 0x80008284: nop

    // 0x80008288: addiu       $t0, $t8, 0x7FFF
    ctx->r8 = ADD32(ctx->r24, 0X7FFF);
    // 0x8000828C: lw          $t0, 0x2ED($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2ED);
    // 0x80008290: addiu       $at, $t8, 0x7FFF
    ctx->r1 = ADD32(ctx->r24, 0X7FFF);
    // 0x80008294: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80008298: sw          $t1, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r9;
    // 0x8000829C: b           L_800082A4
    // 0x800082A0: nop

        goto L_800082A4;
    // 0x800082A0: nop

L_800082A4:
    // 0x800082A4: lw          $t3, 0x4EC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4EC);
    // 0x800082A8: nop

    // 0x800082AC: addiu       $t2, $t3, 0x7FFF
    ctx->r10 = ADD32(ctx->r11, 0X7FFF);
    // 0x800082B0: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800082B4: nop

    // 0x800082B8: bne         $t2, $zero, L_800082C8
    if (ctx->r10 != 0) {
        // 0x800082BC: nop

            goto L_800082C8;
    }
    // 0x800082BC: nop

    // 0x800082C0: b           L_800082D0
    // 0x800082C4: nop

        goto L_800082D0;
    // 0x800082C4: nop

L_800082C8:
    // 0x800082C8: b           L_80008244
    // 0x800082CC: nop

        goto L_80008244;
    // 0x800082CC: nop

L_800082D0:
    // 0x800082D0: jal         0x80005460
    // 0x800082D4: nop

    func_80005460(rdram, ctx);
        goto after_75;
    // 0x800082D4: nop

    after_75:
    // 0x800082D8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800082DC: lw          $a1, -0x73E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X73E8);
    // 0x800082E0: addiu       $a0, $sp, 0x388
    ctx->r4 = ADD32(ctx->r29, 0X388);
    // 0x800082E4: jal         0x800BCFCC
    // 0x800082E8: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    SysMem_Copy8(rdram, ctx);
        goto after_76;
    // 0x800082E8: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    after_76:
    // 0x800082EC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800082F0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x800082F4: lh          $a1, -0x73E4($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X73E4);
    // 0x800082F8: lh          $a0, -0x73F0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X73F0);
    // 0x800082FC: jal         0x80005124
    // 0x80008300: nop

    func_80005124(rdram, ctx);
        goto after_77;
    // 0x80008300: nop

    after_77:
    // 0x80008304: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80008308: lw          $t5, -0x73E8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X73E8);
    // 0x8000830C: lwc1        $f8, 0x454($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X454);
    // 0x80008310: nop

    // 0x80008314: swc1        $f8, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f8.u32l;
    // 0x80008318: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000831C: lw          $t4, -0x73E8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X73E8);
    // 0x80008320: lwc1        $f10, 0x458($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X458);
    // 0x80008324: nop

    // 0x80008328: swc1        $f10, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f10.u32l;
    // 0x8000832C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80008330: lh          $t7, -0x73F0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73F0);
    // 0x80008334: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008338: sh          $t7, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r15;
    // 0x8000833C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008340: sh          $t7, 0x7234($at)
    MEM_H(0X7234, ctx->r1) = ctx->r15;
    // 0x80008344: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80008348: lh          $t9, -0x73E4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X73E4);
    // 0x8000834C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008350: sh          $t9, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r25;
    // 0x80008354: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008358: sh          $t9, 0x723C($at)
    MEM_H(0X723C, ctx->r1) = ctx->r25;
    // 0x8000835C: lw          $t6, 0x4EC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4EC);
    // 0x80008360: nop

    // 0x80008364: addiu       $at, $t6, 0x7FFF
    ctx->r1 = ADD32(ctx->r14, 0X7FFF);
    // 0x80008368: sw          $zero, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = 0;
    // 0x8000836C: lw          $t0, 0x4F0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4F0);
    // 0x80008370: nop

    // 0x80008374: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x80008378: jal         0x800C13B8
    // 0x8000837C: nop

    Thread_ResetMqValidCount(rdram, ctx);
        goto after_78;
    // 0x8000837C: nop

    after_78:
    // 0x80008380: jal         0x80098820
    // 0x80008384: nop

    func_80098820(rdram, ctx);
        goto after_79;
    // 0x80008384: nop

    after_79:
    // 0x80008388: lw          $t1, 0x4F0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4F0);
    // 0x8000838C: nop

    // 0x80008390: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
    // 0x80008394: b           L_800083C4
    // 0x80008398: nop

        goto L_800083C4;
    // 0x80008398: nop

L_8000839C:
    // 0x8000839C: jal         0x800029BC
    // 0x800083A0: nop

    func_800029BC(rdram, ctx);
        goto after_80;
    // 0x800083A0: nop

    after_80:
L_800083A4:
    // 0x800083A4: b           L_800083A4
    pause_self(rdram);
    // 0x800083A8: nop

    // 0x800083AC: b           L_800083C4
    // 0x800083B0: nop

        goto L_800083C4;
    // 0x800083B0: nop

L_800083B4:
    // 0x800083B4: b           L_800083C4
    // 0x800083B8: nop

        goto L_800083C4;
    // 0x800083B8: nop

L_800083BC:
    // 0x800083BC: b           L_800083C4
    // 0x800083C0: nop

        goto L_800083C4;
    // 0x800083C0: nop

L_800083C4:
    // 0x800083C4: lw          $t8, 0x4F8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4F8);
    // 0x800083C8: nop

    // 0x800083CC: beq         $t8, $zero, L_80007B44
    if (ctx->r24 == 0) {
        // 0x800083D0: nop

            goto L_80007B44;
    }
    // 0x800083D0: nop

L_800083D4:
    // 0x800083D4: lw          $t3, 0x4EC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4EC);
    // 0x800083D8: nop

    // 0x800083DC: addiu       $t2, $t3, 0x7FFF
    ctx->r10 = ADD32(ctx->r11, 0X7FFF);
    // 0x800083E0: lw          $t2, 0x2ED($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2ED);
    // 0x800083E4: nop

    // 0x800083E8: blez        $t2, L_8000846C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800083EC: nop

            goto L_8000846C;
    }
    // 0x800083EC: nop

L_800083F0:
    // 0x800083F0: lw          $t5, 0x4F0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4F0);
    // 0x800083F4: addiu       $a1, $sp, 0x4E8
    ctx->r5 = ADD32(ctx->r29, 0X4E8);
    // 0x800083F8: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    // 0x800083FC: jal         0x800C143C
    // 0x80008400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_81;
    // 0x80008400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_81:
    // 0x80008404: lw          $t4, 0x4E8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4E8);
    // 0x80008408: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000840C: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x80008410: nop

    // 0x80008414: bne         $t7, $at, L_80008450
    if (ctx->r15 != ctx->r1) {
        // 0x80008418: nop

            goto L_80008450;
    }
    // 0x80008418: nop

    // 0x8000841C: b           L_80008424
    // 0x80008420: nop

        goto L_80008424;
    // 0x80008420: nop

L_80008424:
    // 0x80008424: jal         0x80099520
    // 0x80008428: nop

    func_80099520(rdram, ctx);
        goto after_82;
    // 0x80008428: nop

    after_82:
    // 0x8000842C: lw          $t9, 0x4EC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4EC);
    // 0x80008430: nop

    // 0x80008434: addiu       $t6, $t9, 0x7FFF
    ctx->r14 = ADD32(ctx->r25, 0X7FFF);
    // 0x80008438: lw          $t6, 0x2ED($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2ED);
    // 0x8000843C: addiu       $at, $t9, 0x7FFF
    ctx->r1 = ADD32(ctx->r25, 0X7FFF);
    // 0x80008440: addiu       $t0, $t6, -0x1
    ctx->r8 = ADD32(ctx->r14, -0X1);
    // 0x80008444: sw          $t0, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r8;
    // 0x80008448: b           L_80008450
    // 0x8000844C: nop

        goto L_80008450;
    // 0x8000844C: nop

L_80008450:
    // 0x80008450: lw          $t1, 0x4EC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4EC);
    // 0x80008454: nop

    // 0x80008458: addiu       $t8, $t1, 0x7FFF
    ctx->r24 = ADD32(ctx->r9, 0X7FFF);
    // 0x8000845C: lw          $t8, 0x2ED($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2ED);
    // 0x80008460: nop

    // 0x80008464: bgtz        $t8, L_800083F0
    if (SIGNED(ctx->r24) > 0) {
        // 0x80008468: nop

            goto L_800083F0;
    }
    // 0x80008468: nop

L_8000846C:
    // 0x8000846C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80008470: lw          $a0, -0x5B30($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B30);
    // 0x80008474: jal         0x800BC980
    // 0x80008478: nop

    SysMem_Free(rdram, ctx);
        goto after_83;
    // 0x80008478: nop

    after_83:
    // 0x8000847C: jal         0x80009F10
    // 0x80008480: nop

    func_80009F10(rdram, ctx);
        goto after_84;
    // 0x80008480: nop

    after_84:
    // 0x80008484: b           L_8000848C
    // 0x80008488: nop

        goto L_8000848C;
    // 0x80008488: nop

L_8000848C:
    // 0x8000848C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80008490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008494: jr          $ra
    // 0x80008498: addiu       $sp, $sp, 0x500
    ctx->r29 = ADD32(ctx->r29, 0X500);
    return;
    // 0x80008498: addiu       $sp, $sp, 0x500
    ctx->r29 = ADD32(ctx->r29, 0X500);
;}
RECOMP_FUNC void func_8000849C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000849C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800084A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800084A4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800084A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800084AC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800084B0: nop

    // 0x800084B4: addiu       $t7, $t6, 0x1C8
    ctx->r15 = ADD32(ctx->r14, 0X1C8);
    // 0x800084B8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800084BC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800084C0: nop

    // 0x800084C4: lw          $t9, 0x34C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34C);
    // 0x800084C8: nop

    // 0x800084CC: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800084D0: bne         $t0, $zero, L_80008BCC
    if (ctx->r8 != 0) {
        // 0x800084D4: nop

            goto L_80008BCC;
    }
    // 0x800084D4: nop

    // 0x800084D8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800084DC: nop

    // 0x800084E0: lw          $t2, 0x34C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34C);
    // 0x800084E4: nop

    // 0x800084E8: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x800084EC: beq         $t3, $zero, L_800087CC
    if (ctx->r11 == 0) {
        // 0x800084F0: nop

            goto L_800087CC;
    }
    // 0x800084F0: nop

    // 0x800084F4: andi        $t4, $t2, 0x1
    ctx->r12 = ctx->r10 & 0X1;
    // 0x800084F8: bne         $t4, $zero, L_800087CC
    if (ctx->r12 != 0) {
        // 0x800084FC: nop

            goto L_800087CC;
    }
    // 0x800084FC: nop

    // 0x80008500: andi        $t5, $t2, 0x2
    ctx->r13 = ctx->r10 & 0X2;
    // 0x80008504: bne         $t5, $zero, L_800087CC
    if (ctx->r13 != 0) {
        // 0x80008508: nop

            goto L_800087CC;
    }
    // 0x80008508: nop

    // 0x8000850C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80008510: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80008514: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80008518: nop

    // 0x8000851C: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x80008520: bne         $t8, $zero, L_800087CC
    if (ctx->r24 != 0) {
        // 0x80008524: nop

            goto L_800087CC;
    }
    // 0x80008524: nop

    // 0x80008528: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000852C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80008530: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80008534: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x80008538: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8000853C: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80008540: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80008544: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80008548: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000854C: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80008550: nop

    // 0x80008554: bc1f        L_80008564
    if (!c1cs) {
        // 0x80008558: nop

            goto L_80008564;
    }
    // 0x80008558: nop

    // 0x8000855C: b           L_80008598
    // 0x80008560: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
        goto L_80008598;
    // 0x80008560: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80008564:
    // 0x80008564: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x80008568: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8000856C: lwc1        $f10, 0x14($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X14);
    // 0x80008570: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x80008574: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80008578: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000857C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80008580: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80008584: nop

    // 0x80008588: bc1f        L_80008598
    if (!c1cs) {
        // 0x8000858C: nop

            goto L_80008598;
    }
    // 0x8000858C: nop

    // 0x80008590: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80008594: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_80008598:
    // 0x80008598: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000859C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x800085A0: lwc1        $f4, 0x10($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800085A4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800085A8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800085AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800085B0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800085B4: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x800085B8: nop

    // 0x800085BC: bc1f        L_8000860C
    if (!c1cs) {
        // 0x800085C0: nop

            goto L_8000860C;
    }
    // 0x800085C0: nop

    // 0x800085C4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800085C8: nop

    // 0x800085CC: bne         $t2, $zero, L_800085E0
    if (ctx->r10 != 0) {
        // 0x800085D0: nop

            goto L_800085E0;
    }
    // 0x800085D0: nop

    // 0x800085D4: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x800085D8: b           L_80008604
    // 0x800085DC: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_80008604;
    // 0x800085DC: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_800085E0:
    // 0x800085E0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800085E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800085E8: bne         $t6, $at, L_800085FC
    if (ctx->r14 != ctx->r1) {
        // 0x800085EC: nop

            goto L_800085FC;
    }
    // 0x800085EC: nop

    // 0x800085F0: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x800085F4: b           L_80008604
    // 0x800085F8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
        goto L_80008604;
    // 0x800085F8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800085FC:
    // 0x800085FC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80008600: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80008604:
    // 0x80008604: b           L_80008678
    // 0x80008608: nop

        goto L_80008678;
    // 0x80008608: nop

L_8000860C:
    // 0x8000860C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80008610: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x80008614: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80008618: lui         $at, 0xC049
    ctx->r1 = S32(0XC049 << 16);
    // 0x8000861C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80008620: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80008624: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80008628: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x8000862C: nop

    // 0x80008630: bc1f        L_80008678
    if (!c1cs) {
        // 0x80008634: nop

            goto L_80008678;
    }
    // 0x80008634: nop

    // 0x80008638: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8000863C: nop

    // 0x80008640: bne         $t0, $zero, L_80008654
    if (ctx->r8 != 0) {
        // 0x80008644: nop

            goto L_80008654;
    }
    // 0x80008644: nop

    // 0x80008648: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8000864C: b           L_80008678
    // 0x80008650: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_80008678;
    // 0x80008650: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80008654:
    // 0x80008654: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80008658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000865C: bne         $t3, $at, L_80008670
    if (ctx->r11 != ctx->r1) {
        // 0x80008660: nop

            goto L_80008670;
    }
    // 0x80008660: nop

    // 0x80008664: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80008668: b           L_80008678
    // 0x8000866C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_80008678;
    // 0x8000866C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80008670:
    // 0x80008670: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80008674: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_80008678:
    // 0x80008678: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8000867C: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x80008680: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80008684: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80008688: beq         $t6, $at, L_8000869C
    if (ctx->r14 == ctx->r1) {
        // 0x8000868C: nop

            goto L_8000869C;
    }
    // 0x8000868C: nop

    // 0x80008690: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80008694: nop

    // 0x80008698: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_8000869C:
    // 0x8000869C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800086A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800086A4: beq         $t8, $at, L_800087CC
    if (ctx->r24 == ctx->r1) {
        // 0x800086A8: nop

            goto L_800087CC;
    }
    // 0x800086A8: nop

    // 0x800086AC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800086B0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x800086B4: lw          $t0, 0x344($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X344);
    // 0x800086B8: lw          $t3, -0x5B34($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5B34);
    // 0x800086BC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800086C0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800086C4: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800086C8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800086CC: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800086D0: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x800086D4: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800086D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800086DC: beq         $t6, $at, L_800087CC
    if (ctx->r14 == ctx->r1) {
        // 0x800086E0: nop

            goto L_800087CC;
    }
    // 0x800086E0: nop

    // 0x800086E4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800086E8: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x800086EC: lw          $t9, 0x344($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X344);
    // 0x800086F0: lw          $t1, -0x5B34($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5B34);
    // 0x800086F4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800086F8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800086FC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80008700: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80008704: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80008708: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8000870C: addu        $t2, $t3, $t4
    ctx->r10 = ADD32(ctx->r11, ctx->r12);
    // 0x80008710: lw          $t5, 0x10($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X10);
    // 0x80008714: nop

    // 0x80008718: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8000871C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80008720: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80008724: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80008728: lw          $t9, -0x5B34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B34);
    // 0x8000872C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80008730: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80008734: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80008738: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000873C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80008740: beq         $t1, $at, L_80008760
    if (ctx->r9 == ctx->r1) {
        // 0x80008744: nop

            goto L_80008760;
    }
    // 0x80008744: nop

    // 0x80008748: jal         0x8005F064
    // 0x8000874C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x8000874C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_0:
    // 0x80008750: bne         $v0, $zero, L_80008760
    if (ctx->r2 != 0) {
        // 0x80008754: nop

            goto L_80008760;
    }
    // 0x80008754: nop

    // 0x80008758: b           L_800087CC
    // 0x8000875C: nop

        goto L_800087CC;
    // 0x8000875C: nop

L_80008760:
    // 0x80008760: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80008764: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80008768: nop

    // 0x8000876C: sw          $t8, 0x348($t3)
    MEM_W(0X348, ctx->r11) = ctx->r24;
    // 0x80008770: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80008774: nop

    // 0x80008778: lw          $t2, 0x34C($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X34C);
    // 0x8000877C: nop

    // 0x80008780: ori         $t5, $t2, 0x3
    ctx->r13 = ctx->r10 | 0X3;
    // 0x80008784: sw          $t5, 0x34C($t4)
    MEM_W(0X34C, ctx->r12) = ctx->r13;
    // 0x80008788: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000878C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80008790: jal         0x80008FF0
    // 0x80008794: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_80008FF0(rdram, ctx);
        goto after_1;
    // 0x80008794: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_1:
    // 0x80008798: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000879C: lw          $t6, -0x5B40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5B40);
    // 0x800087A0: nop

    // 0x800087A4: beq         $t6, $zero, L_800087CC
    if (ctx->r14 == 0) {
        // 0x800087A8: nop

            goto L_800087CC;
    }
    // 0x800087A8: nop

    // 0x800087AC: jal         0x80031BB0
    // 0x800087B0: nop

    func_80031BB0(rdram, ctx);
        goto after_2;
    // 0x800087B0: nop

    after_2:
    // 0x800087B4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800087B8: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800087BC: lw          $t9, 0x34C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X34C);
    // 0x800087C0: nop

    // 0x800087C4: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800087C8: sw          $t0, 0x34C($t7)
    MEM_W(0X34C, ctx->r15) = ctx->r8;
L_800087CC:
    // 0x800087CC: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800087D0: nop

    // 0x800087D4: lw          $t8, 0x344($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X344);
    // 0x800087D8: lw          $t3, 0x348($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X348);
    // 0x800087DC: nop

    // 0x800087E0: beq         $t8, $t3, L_800089F0
    if (ctx->r24 == ctx->r11) {
        // 0x800087E4: nop

            goto L_800089F0;
    }
    // 0x800087E4: nop

    // 0x800087E8: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800087EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800087F0: lwc1        $f4, 0x328($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X328);
    // 0x800087F4: nop

    // 0x800087F8: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800087FC: nop

    // 0x80008800: bc1f        L_800088FC
    if (!c1cs) {
        // 0x80008804: nop

            goto L_800088FC;
    }
    // 0x80008804: nop

    // 0x80008808: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000880C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008810: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80008814: lwc1        $f8, 0x33C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X33C);
    // 0x80008818: lwc1        $f18, 0x32C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X32C);
    // 0x8000881C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80008820: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80008824: swc1        $f4, 0x32C($t5)
    MEM_W(0X32C, ctx->r13) = ctx->f4.u32l;
    // 0x80008828: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8000882C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008830: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80008834: lwc1        $f6, 0x340($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X340);
    // 0x80008838: lwc1        $f18, 0x330($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X330);
    // 0x8000883C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80008840: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80008844: swc1        $f16, 0x330($t4)
    MEM_W(0X330, ctx->r12) = ctx->f16.u32l;
    // 0x80008848: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8000884C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80008850: lw          $t9, 0x34C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X34C);
    // 0x80008854: nop

    // 0x80008858: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8000885C: beq         $t0, $zero, L_800088BC
    if (ctx->r8 == 0) {
        // 0x80008860: nop

            goto L_800088BC;
    }
    // 0x80008860: nop

    // 0x80008864: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80008868: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8000886C: lwc1        $f4, 0x328($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X328);
    // 0x80008870: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80008874: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80008878: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000887C: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80008880: nop

    // 0x80008884: bc1f        L_800088BC
    if (!c1cs) {
        // 0x80008888: nop

            goto L_800088BC;
    }
    // 0x80008888: nop

    // 0x8000888C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008890: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80008894: lw          $t8, 0x34C($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X34C);
    // 0x80008898: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000889C: and         $t3, $t8, $at
    ctx->r11 = ctx->r24 & ctx->r1;
    // 0x800088A0: sw          $t3, 0x34C($t1)
    MEM_W(0X34C, ctx->r9) = ctx->r11;
    // 0x800088A4: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800088A8: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800088AC: lw          $t5, 0x34C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X34C);
    // 0x800088B0: nop

    // 0x800088B4: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800088B8: sw          $t4, 0x34C($t2)
    MEM_W(0X34C, ctx->r10) = ctx->r12;
L_800088BC:
    // 0x800088BC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800088C0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800088C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800088C8: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800088CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800088D0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl);
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800088D4: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d);
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800088D8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800088DC: nop

    // 0x800088E0: lwc1        $f6, 0x328($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X328);
    // 0x800088E4: nop

    // 0x800088E8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800088EC: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d);
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x800088F0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800088F4: b           L_800089F0
    // 0x800088F8: swc1        $f18, 0x328($t6)
    MEM_W(0X328, ctx->r14) = ctx->f18.u32l;
        goto L_800089F0;
    // 0x800088F8: swc1        $f18, 0x328($t6)
    MEM_W(0X328, ctx->r14) = ctx->f18.u32l;
L_800088FC:
    // 0x800088FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80008900: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80008904: nop

    // 0x80008908: swc1        $f16, 0x328($t9)
    MEM_W(0X328, ctx->r25) = ctx->f16.u32l;
    // 0x8000890C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80008910: nop

    // 0x80008914: lwc1        $f6, 0x334($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X334);
    // 0x80008918: nop

    // 0x8000891C: swc1        $f6, 0x32C($t0)
    MEM_W(0X32C, ctx->r8) = ctx->f6.u32l;
    // 0x80008920: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80008924: nop

    // 0x80008928: lwc1        $f8, 0x338($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X338);
    // 0x8000892C: nop

    // 0x80008930: swc1        $f8, 0x330($t7)
    MEM_W(0X330, ctx->r15) = ctx->f8.u32l;
    // 0x80008934: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80008938: nop

    // 0x8000893C: lw          $t3, 0x348($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X348);
    // 0x80008940: nop

    // 0x80008944: sw          $t3, 0x344($t8)
    MEM_W(0X344, ctx->r24) = ctx->r11;
    // 0x80008948: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8000894C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80008950: lw          $t5, 0x34C($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X34C);
    // 0x80008954: nop

    // 0x80008958: and         $t4, $t5, $at
    ctx->r12 = ctx->r13 & ctx->r1;
    // 0x8000895C: sw          $t4, 0x34C($t1)
    MEM_W(0X34C, ctx->r9) = ctx->r12;
    // 0x80008960: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80008964: lw          $a1, -0x5B34($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5B34);
    // 0x80008968: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8000896C: jal         0x80009484
    // 0x80008970: nop

    func_80009484(rdram, ctx);
        goto after_3;
    // 0x80008970: nop

    after_3:
    // 0x80008974: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80008978: lw          $t2, -0x5B40($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5B40);
    // 0x8000897C: nop

    // 0x80008980: beq         $t2, $zero, L_80008998
    if (ctx->r10 == 0) {
        // 0x80008984: nop

            goto L_80008998;
    }
    // 0x80008984: nop

    // 0x80008988: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8000898C: lw          $a0, -0x5B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B40);
    // 0x80008990: jal         0x800BC980
    // 0x80008994: nop

    SysMem_Free(rdram, ctx);
        goto after_4;
    // 0x80008994: nop

    after_4:
L_80008998:
    // 0x80008998: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8000899C: nop

    // 0x800089A0: lw          $a0, 0x344($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X344);
    // 0x800089A4: jal         0x80009C64
    // 0x800089A8: nop

    func_80009C64(rdram, ctx);
        goto after_5;
    // 0x800089A8: nop

    after_5:
    // 0x800089AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x800089B0: sw          $v0, -0x5B40($at)
    MEM_W(-0X5B40, ctx->r1) = ctx->r2;
    // 0x800089B4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x800089B8: lw          $t9, -0x5B40($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B40);
    // 0x800089BC: nop

    // 0x800089C0: beq         $t9, $zero, L_800089F0
    if (ctx->r25 == 0) {
        // 0x800089C4: nop

            goto L_800089F0;
    }
    // 0x800089C4: nop

    // 0x800089C8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x800089CC: lw          $a0, -0x5B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B40);
    // 0x800089D0: jal         0x800319B0
    // 0x800089D4: nop

    func_800319B0(rdram, ctx);
        goto after_6;
    // 0x800089D4: nop

    after_6:
    // 0x800089D8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800089DC: nop

    // 0x800089E0: lw          $t7, 0x34C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X34C);
    // 0x800089E4: nop

    // 0x800089E8: ori         $t3, $t7, 0x4
    ctx->r11 = ctx->r15 | 0X4;
    // 0x800089EC: sw          $t3, 0x34C($t0)
    MEM_W(0X34C, ctx->r8) = ctx->r11;
L_800089F0:
    // 0x800089F0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800089F4: nop

    // 0x800089F8: lw          $t5, 0x34C($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X34C);
    // 0x800089FC: nop

    // 0x80008A00: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x80008A04: bne         $t4, $zero, L_80008A34
    if (ctx->r12 != 0) {
        // 0x80008A08: nop

            goto L_80008A34;
    }
    // 0x80008A08: nop

    // 0x80008A0C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80008A10: and         $t1, $t5, $at
    ctx->r9 = ctx->r13 & ctx->r1;
    // 0x80008A14: bne         $t1, $zero, L_80008A34
    if (ctx->r9 != 0) {
        // 0x80008A18: nop

            goto L_80008A34;
    }
    // 0x80008A18: nop

    // 0x80008A1C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008A20: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80008A24: lw          $t6, 0x34C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X34C);
    // 0x80008A28: nop

    // 0x80008A2C: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x80008A30: sw          $t9, 0x34C($t2)
    MEM_W(0X34C, ctx->r10) = ctx->r25;
L_80008A34:
    // 0x80008A34: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80008A38: nop

    // 0x80008A3C: lw          $t3, 0x34C($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X34C);
    // 0x80008A40: nop

    // 0x80008A44: andi        $t0, $t3, 0x8
    ctx->r8 = ctx->r11 & 0X8;
    // 0x80008A48: bne         $t0, $zero, L_80008ADC
    if (ctx->r8 != 0) {
        // 0x80008A4C: nop

            goto L_80008ADC;
    }
    // 0x80008A4C: nop

    // 0x80008A50: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80008A54: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80008A58: lhu         $t4, 0x0($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X0);
    // 0x80008A5C: nop

    // 0x80008A60: andi        $t5, $t4, 0x400
    ctx->r13 = ctx->r12 & 0X400;
    // 0x80008A64: bne         $t5, $zero, L_80008ADC
    if (ctx->r13 != 0) {
        // 0x80008A68: nop

            goto L_80008ADC;
    }
    // 0x80008A68: nop

    // 0x80008A6C: jal         0x80031874
    // 0x80008A70: nop

    func_80031874(rdram, ctx);
        goto after_7;
    // 0x80008A70: nop

    after_7:
    // 0x80008A74: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80008A78: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x80008A7C: lh          $a2, 0x7280($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X7280);
    // 0x80008A80: lh          $a1, 0x7274($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7274);
    // 0x80008A84: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008A88: jal         0x80008FF0
    // 0x80008A8C: nop

    func_80008FF0(rdram, ctx);
        goto after_8;
    // 0x80008A8C: nop

    after_8:
    // 0x80008A90: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008A94: nop

    // 0x80008A98: lw          $s0, 0x348($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X348);
    // 0x80008A9C: nop

    // 0x80008AA0: sltiu       $t6, $s0, 0x1
    ctx->r14 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x80008AA4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80008AA8: sw          $s0, 0x344($t1)
    MEM_W(0X344, ctx->r9) = ctx->r16;
    // 0x80008AAC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80008AB0: nop

    // 0x80008AB4: lw          $t2, 0x34C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X34C);
    // 0x80008AB8: nop

    // 0x80008ABC: ori         $t7, $t2, 0x3
    ctx->r15 = ctx->r10 | 0X3;
    // 0x80008AC0: sw          $t7, 0x34C($t9)
    MEM_W(0X34C, ctx->r25) = ctx->r15;
    // 0x80008AC4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80008AC8: nop

    // 0x80008ACC: lw          $t0, 0x34C($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X34C);
    // 0x80008AD0: nop

    // 0x80008AD4: ori         $t8, $t0, 0x8
    ctx->r24 = ctx->r8 | 0X8;
    // 0x80008AD8: sw          $t8, 0x34C($t3)
    MEM_W(0X34C, ctx->r11) = ctx->r24;
L_80008ADC:
    // 0x80008ADC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80008AE0: nop

    // 0x80008AE4: lw          $t5, 0x34C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34C);
    // 0x80008AE8: nop

    // 0x80008AEC: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x80008AF0: beq         $t6, $zero, L_80008B04
    if (ctx->r14 == 0) {
        // 0x80008AF4: nop

            goto L_80008B04;
    }
    // 0x80008AF4: nop

    // 0x80008AF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80008AFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008B00: swc1        $f4, 0x2530($at)
    MEM_W(0X2530, ctx->r1) = ctx->f4.u32l;
L_80008B04:
    // 0x80008B04: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008B08: lui         $at, 0xC
    ctx->r1 = S32(0XC << 16);
    // 0x80008B0C: lw          $t2, 0x34C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34C);
    // 0x80008B10: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80008B14: and         $t7, $t2, $at
    ctx->r15 = ctx->r10 & ctx->r1;
    // 0x80008B18: bne         $t7, $zero, L_80008BC4
    if (ctx->r15 != 0) {
        // 0x80008B1C: nop

            goto L_80008BC4;
    }
    // 0x80008B1C: nop

    // 0x80008B20: lw          $t9, 0x344($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X344);
    // 0x80008B24: lw          $t0, 0x348($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X348);
    // 0x80008B28: nop

    // 0x80008B2C: bne         $t9, $t0, L_80008BC4
    if (ctx->r25 != ctx->r8) {
        // 0x80008B30: nop

            goto L_80008BC4;
    }
    // 0x80008B30: nop

    // 0x80008B34: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80008B38: addiu       $t8, $t8, -0x7278
    ctx->r24 = ADD32(ctx->r24, -0X7278);
    // 0x80008B3C: lhu         $t3, 0x0($t8)
    ctx->r11 = MEM_HU(ctx->r24, 0X0);
    // 0x80008B40: nop

    // 0x80008B44: andi        $t4, $t3, 0x400
    ctx->r12 = ctx->r11 & 0X400;
    // 0x80008B48: bne         $t4, $zero, L_80008BC4
    if (ctx->r12 != 0) {
        // 0x80008B4C: nop

            goto L_80008BC4;
    }
    // 0x80008B4C: nop

    // 0x80008B50: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80008B54: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80008B58: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80008B5C: lhu         $t6, 0xFF4($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0XFF4);
    // 0x80008B60: lhu         $t5, 0x10F2($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X10F2);
    // 0x80008B64: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x80008B68: lhu         $t1, 0x6($t7)
    ctx->r9 = MEM_HU(ctx->r15, 0X6);
    // 0x80008B6C: or          $t2, $t5, $t6
    ctx->r10 = ctx->r13 | ctx->r14;
    // 0x80008B70: and         $t9, $t1, $t2
    ctx->r25 = ctx->r9 & ctx->r10;
    // 0x80008B74: beq         $t9, $zero, L_80008BC4
    if (ctx->r25 == 0) {
        // 0x80008B78: nop

            goto L_80008BC4;
    }
    // 0x80008B78: nop

    // 0x80008B7C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80008B80: nop

    // 0x80008B84: lw          $t8, 0x34C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X34C);
    // 0x80008B88: nop

    // 0x80008B8C: ori         $t3, $t8, 0x8000
    ctx->r11 = ctx->r24 | 0X8000;
    // 0x80008B90: sw          $t3, 0x34C($t0)
    MEM_W(0X34C, ctx->r8) = ctx->r11;
    // 0x80008B94: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80008B98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80008B9C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80008BA0: nop

    // 0x80008BA4: swc1        $f10, 0x328($t4)
    MEM_W(0X328, ctx->r12) = ctx->f10.u32l;
    // 0x80008BA8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008BAC: jal         0x8000975C
    // 0x80008BB0: nop

    func_8000975C(rdram, ctx);
        goto after_9;
    // 0x80008BB0: nop

    after_9:
    // 0x80008BB4: jal         0x80031BB0
    // 0x80008BB8: nop

    func_80031BB0(rdram, ctx);
        goto after_10;
    // 0x80008BB8: nop

    after_10:
    // 0x80008BBC: jal         0x80031728
    // 0x80008BC0: nop

    func_80031728(rdram, ctx);
        goto after_11;
    // 0x80008BC0: nop

    after_11:
L_80008BC4:
    // 0x80008BC4: b           L_80008D60
    // 0x80008BC8: nop

        goto L_80008D60;
    // 0x80008BC8: nop

L_80008BCC:
    // 0x80008BCC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80008BD0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80008BD4: lwc1        $f18, 0x328($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X328);
    // 0x80008BD8: nop

    // 0x80008BDC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80008BE0: nop

    // 0x80008BE4: bc1f        L_80008C88
    if (!c1cs) {
        // 0x80008BE8: nop

            goto L_80008C88;
    }
    // 0x80008BE8: nop

    // 0x80008BEC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80008BF0: lui         $at, 0x402A
    ctx->r1 = S32(0X402A << 16);
    // 0x80008BF4: lwc1        $f6, 0x328($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X328);
    // 0x80008BF8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80008BFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80008C00: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80008C04: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x80008C08: nop

    // 0x80008C0C: bc1f        L_80008C48
    if (!c1cs) {
        // 0x80008C10: nop

            goto L_80008C48;
    }
    // 0x80008C10: nop

    // 0x80008C14: jal         0x80031914
    // 0x80008C18: nop

    func_80031914(rdram, ctx);
        goto after_12;
    // 0x80008C18: nop

    after_12:
    // 0x80008C1C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80008C20: lw          $t7, -0x5B40($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5B40);
    // 0x80008C24: nop

    // 0x80008C28: beq         $t7, $zero, L_80008C40
    if (ctx->r15 == 0) {
        // 0x80008C2C: nop

            goto L_80008C40;
    }
    // 0x80008C2C: nop

    // 0x80008C30: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80008C34: lw          $a0, -0x5B40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B40);
    // 0x80008C38: jal         0x800BC980
    // 0x80008C3C: nop

    SysMem_Free(rdram, ctx);
        goto after_13;
    // 0x80008C3C: nop

    after_13:
L_80008C40:
    // 0x80008C40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80008C44: sw          $zero, -0x5B40($at)
    MEM_W(-0X5B40, ctx->r1) = 0;
L_80008C48:
    // 0x80008C48: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80008C4C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80008C50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008C54: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80008C58: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80008C5C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80008C60: mul.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d);
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80008C64: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008C68: nop

    // 0x80008C6C: lwc1        $f8, 0x328($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X328);
    // 0x80008C70: nop

    // 0x80008C74: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80008C78: sub.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f18.d = ctx->f4.d - ctx->f6.d;
    // 0x80008C7C: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d);
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x80008C80: b           L_80008D60
    // 0x80008C84: swc1        $f10, 0x328($t1)
    MEM_W(0X328, ctx->r9) = ctx->f10.u32l;
        goto L_80008D60;
    // 0x80008C84: swc1        $f10, 0x328($t1)
    MEM_W(0X328, ctx->r9) = ctx->f10.u32l;
L_80008C88:
    // 0x80008C88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80008C8C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008C90: nop

    // 0x80008C94: swc1        $f16, 0x328($t2)
    MEM_W(0X328, ctx->r10) = ctx->f16.u32l;
    // 0x80008C98: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80008C9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008CA0: lw          $t8, 0x344($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X344);
    // 0x80008CA4: nop

    // 0x80008CA8: sh          $t8, 0x7294($at)
    MEM_H(0X7294, ctx->r1) = ctx->r24;
    // 0x80008CAC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80008CB0: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x80008CB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008CB8: sh          $t3, 0x72A0($at)
    MEM_H(0X72A0, ctx->r1) = ctx->r11;
    // 0x80008CBC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008CC0: jal         0x80008F58
    // 0x80008CC4: nop

    func_80008F58(rdram, ctx);
        goto after_14;
    // 0x80008CC4: nop

    after_14:
    // 0x80008CC8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80008CCC: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80008CD0: lw          $t4, 0x344($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X344);
    // 0x80008CD4: lw          $t6, -0x5B34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5B34);
    // 0x80008CD8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80008CDC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80008CE0: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80008CE4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80008CE8: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x80008CEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80008CF0: beq         $t1, $at, L_80008D24
    if (ctx->r9 == ctx->r1) {
        // 0x80008CF4: nop

            goto L_80008D24;
    }
    // 0x80008CF4: nop

    // 0x80008CF8: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008CFC: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80008D00: lw          $t9, 0x344($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X344);
    // 0x80008D04: lw          $t3, -0x5B34($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5B34);
    // 0x80008D08: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80008D0C: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80008D10: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80008D14: addu        $t0, $t8, $t3
    ctx->r8 = ADD32(ctx->r24, ctx->r11);
    // 0x80008D18: lw          $t4, 0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0XC);
    // 0x80008D1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80008D20: sh          $t4, -0x73C0($at)
    MEM_H(-0X73C0, ctx->r1) = ctx->r12;
L_80008D24:
    // 0x80008D24: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80008D28: addiu       $t5, $t5, -0x7278
    ctx->r13 = ADD32(ctx->r13, -0X7278);
    // 0x80008D2C: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x80008D30: nop

    // 0x80008D34: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x80008D38: sh          $t7, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r15;
    // 0x80008D3C: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x80008D40: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80008D44: sw          $t1, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r9;
    // 0x80008D48: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008D4C: nop

    // 0x80008D50: lw          $t9, 0x100($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X100);
    // 0x80008D54: nop

    // 0x80008D58: ori         $t8, $t9, 0x8
    ctx->r24 = ctx->r25 | 0X8;
    // 0x80008D5C: sw          $t8, 0x100($t2)
    MEM_W(0X100, ctx->r10) = ctx->r24;
L_80008D60:
    // 0x80008D60: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80008D64: lh          $t3, 0x723C($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X723C);
    // 0x80008D68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008D6C: bne         $t3, $at, L_80008D8C
    if (ctx->r11 != ctx->r1) {
        // 0x80008D70: nop

            goto L_80008D8C;
    }
    // 0x80008D70: nop

    // 0x80008D74: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80008D78: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x80008D7C: nop

    // 0x80008D80: addiu       $t4, $t0, 0x2C0
    ctx->r12 = ADD32(ctx->r8, 0X2C0);
    // 0x80008D84: b           L_80008DA0
    // 0x80008D88: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
        goto L_80008DA0;
    // 0x80008D88: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80008D8C:
    // 0x80008D8C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80008D90: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80008D94: nop

    // 0x80008D98: addiu       $t7, $t6, 0x160
    ctx->r15 = ADD32(ctx->r14, 0X160);
    // 0x80008D9C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80008DA0:
    // 0x80008DA0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80008DA4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80008DA8: lh          $t1, 0x120($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X120);
    // 0x80008DAC: lh          $t9, 0x11E($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X11E);
    // 0x80008DB0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80008DB4: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80008DB8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80008DBC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80008DC0: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80008DC4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80008DC8: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80008DCC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80008DD0: nop

    // 0x80008DD4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80008DD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008DDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008DE0: nop

    // 0x80008DE4: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80008DE8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80008DEC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80008DF0: sh          $t2, 0x11E($t5)
    MEM_H(0X11E, ctx->r13) = ctx->r10;
    // 0x80008DF4: nop

    // 0x80008DF8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80008DFC: nop

    // 0x80008E00: lh          $t0, 0x11E($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X11E);
    // 0x80008E04: nop

    // 0x80008E08: bgez        $t0, L_80008E30
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80008E0C: nop

            goto L_80008E30;
    }
    // 0x80008E0C: nop

    // 0x80008E10: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80008E14: nop

    // 0x80008E18: sh          $zero, 0x11E($t4)
    MEM_H(0X11E, ctx->r12) = 0;
    // 0x80008E1C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80008E20: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80008E24: sh          $t6, 0x120($t7)
    MEM_H(0X120, ctx->r15) = ctx->r14;
    // 0x80008E28: jal         0x80009E5C
    // 0x80008E2C: nop

    func_80009E5C(rdram, ctx);
        goto after_15;
    // 0x80008E2C: nop

    after_15:
L_80008E30:
    // 0x80008E30: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80008E34: nop

    // 0x80008E38: lh          $t9, 0x11E($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X11E);
    // 0x80008E3C: nop

    // 0x80008E40: slti        $at, $t9, 0xB0
    ctx->r1 = SIGNED(ctx->r25) < 0XB0 ? 1 : 0;
    // 0x80008E44: bne         $at, $zero, L_80008E64
    if (ctx->r1 != 0) {
        // 0x80008E48: nop

            goto L_80008E64;
    }
    // 0x80008E48: nop

    // 0x80008E4C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80008E50: addiu       $t8, $zero, 0xAF
    ctx->r24 = ADD32(0, 0XAF);
    // 0x80008E54: sh          $t8, 0x11E($t2)
    MEM_H(0X11E, ctx->r10) = ctx->r24;
    // 0x80008E58: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80008E5C: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
    // 0x80008E60: sh          $t5, 0x120($t3)
    MEM_H(0X120, ctx->r11) = ctx->r13;
L_80008E64:
    // 0x80008E64: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80008E68: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80008E6C: lwc1        $f6, 0x32C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X32C);
    // 0x80008E70: nop

    // 0x80008E74: swc1        $f6, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f6.u32l;
    // 0x80008E78: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80008E7C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80008E80: lwc1        $f10, 0x330($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X330);
    // 0x80008E84: nop

    // 0x80008E88: swc1        $f10, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f10.u32l;
    // 0x80008E8C: jal         0x800C1754
    // 0x80008E90: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_16;
    // 0x80008E90: nop

    after_16:
    // 0x80008E94: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80008E98: jal         0x8009A14C
    // 0x80008E9C: nop

    func_8009A14C(rdram, ctx);
        goto after_17;
    // 0x80008E9C: nop

    after_17:
    // 0x80008EA0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80008EA4: jal         0x800997D8
    // 0x80008EA8: nop

    func_800997D8(rdram, ctx);
        goto after_18;
    // 0x80008EA8: nop

    after_18:
    // 0x80008EAC: jal         0x800C1A28
    // 0x80008EB0: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_19;
    // 0x80008EB0: nop

    after_19:
    // 0x80008EB4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80008EB8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80008EBC: lw          $t9, 0x34C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X34C);
    // 0x80008EC0: nop

    // 0x80008EC4: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80008EC8: beq         $t8, $zero, L_80008F40
    if (ctx->r24 == 0) {
        // 0x80008ECC: nop

            goto L_80008F40;
    }
    // 0x80008ECC: nop

    // 0x80008ED0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008ED4: jal         0x800098F0
    // 0x80008ED8: nop

    func_800098F0(rdram, ctx);
        goto after_20;
    // 0x80008ED8: nop

    after_20:
    // 0x80008EDC: jal         0x800C1754
    // 0x80008EE0: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_21;
    // 0x80008EE0: nop

    after_21:
    // 0x80008EE4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008EE8: jal         0x8009A14C
    // 0x80008EEC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_8009A14C(rdram, ctx);
        goto after_22;
    // 0x80008EEC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_22:
    // 0x80008EF0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80008EF4: nop

    // 0x80008EF8: lwc1        $f12, 0x130($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X130);
    // 0x80008EFC: jal         0x800C2780
    // 0x80008F00: nop

    MtxUtil_RotateZ(rdram, ctx);
        goto after_23;
    // 0x80008F00: nop

    after_23:
    // 0x80008F04: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80008F08: nop

    // 0x80008F0C: lwc1        $f12, 0x12C($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X12C);
    // 0x80008F10: jal         0x800C25B8
    // 0x80008F14: nop

    MtxUtil_RotateY(rdram, ctx);
        goto after_24;
    // 0x80008F14: nop

    after_24:
    // 0x80008F18: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80008F1C: nop

    // 0x80008F20: lwc1        $f12, 0x128($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X128);
    // 0x80008F24: jal         0x800C23E8
    // 0x80008F28: nop

    MtxUtil_RotateX(rdram, ctx);
        goto after_25;
    // 0x80008F28: nop

    after_25:
    // 0x80008F2C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80008F30: jal         0x800997D8
    // 0x80008F34: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    func_800997D8(rdram, ctx);
        goto after_26;
    // 0x80008F34: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_26:
    // 0x80008F38: jal         0x800C1A28
    // 0x80008F3C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_27;
    // 0x80008F3C: nop

    after_27:
L_80008F40:
    // 0x80008F40: b           L_80008F48
    // 0x80008F44: nop

        goto L_80008F48;
    // 0x80008F44: nop

L_80008F48:
    // 0x80008F48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80008F4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008F50: jr          $ra
    // 0x80008F54: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80008F54: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80008F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008F58: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80008F5C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80008F60: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80008F64: nop

    // 0x80008F68: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x80008F6C: nop

    // 0x80008F70: beq         $t7, $zero, L_80008FD8
    if (ctx->r15 == 0) {
        // 0x80008F74: nop

            goto L_80008FD8;
    }
    // 0x80008F74: nop

    // 0x80008F78: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80008F7C: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x80008F80: lw          $t0, 0x344($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X344);
    // 0x80008F84: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x80008F88: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80008F8C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80008F90: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80008F94: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80008F98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008F9C: lhu         $t4, 0xA($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XA);
    // 0x80008FA0: nop

    // 0x80008FA4: sh          $t4, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r12;
    // 0x80008FA8: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80008FAC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008FB0: lhu         $t6, 0xC($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0XC);
    // 0x80008FB4: nop

    // 0x80008FB8: sh          $t6, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r14;
    // 0x80008FBC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80008FC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80008FC4: lhu         $t8, 0xE($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XE);
    // 0x80008FC8: nop

    // 0x80008FCC: sh          $t8, 0x7268($at)
    MEM_H(0X7268, ctx->r1) = ctx->r24;
    // 0x80008FD0: b           L_80008FE8
    // 0x80008FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80008FE8;
    // 0x80008FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80008FD8:
    // 0x80008FD8: b           L_80008FE8
    // 0x80008FDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80008FE8;
    // 0x80008FDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80008FE0: b           L_80008FE8
    // 0x80008FE4: nop

        goto L_80008FE8;
    // 0x80008FE4: nop

L_80008FE8:
    // 0x80008FE8: jr          $ra
    // 0x80008FEC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80008FEC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80008FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008FF0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80008FF4: bne         $a1, $a2, L_80009104
    if (ctx->r5 != ctx->r6) {
        // 0x80008FF8: nop

            goto L_80009104;
    }
    // 0x80008FF8: nop

    // 0x80008FFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009000: bne         $a1, $at, L_80009104
    if (ctx->r5 != ctx->r1) {
        // 0x80009004: nop

            goto L_80009104;
    }
    // 0x80009004: nop

    // 0x80009008: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8000900C: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80009010: nop

    // 0x80009014: lw          $t7, 0x144($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X144);
    // 0x80009018: nop

    // 0x8000901C: beq         $t7, $zero, L_800090FC
    if (ctx->r15 == 0) {
        // 0x80009020: nop

            goto L_800090FC;
    }
    // 0x80009020: nop

    // 0x80009024: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80009028: lw          $t8, -0x73E8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X73E8);
    // 0x8000902C: lw          $t0, 0x348($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X348);
    // 0x80009030: lw          $t9, 0x144($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X144);
    // 0x80009034: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80009038: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000903C: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x80009040: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80009044: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009048: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x8000904C: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x80009050: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80009054: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80009058: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8000905C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80009060: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80009064: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80009068: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8000906C: swc1        $f16, 0x334($a0)
    MEM_W(0X334, ctx->r4) = ctx->f16.u32l;
    // 0x80009070: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80009074: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009078: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x8000907C: lh          $t0, 0x2($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X2);
    // 0x80009080: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80009084: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80009088: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8000908C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009090: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80009094: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80009098: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8000909C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800090A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800090A4: nop

    // 0x800090A8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800090AC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800090B0: swc1        $f18, 0x338($a0)
    MEM_W(0X338, ctx->r4) = ctx->f18.u32l;
    // 0x800090B4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800090B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800090BC: nop

    // 0x800090C0: swc1        $f4, 0x328($a0)
    MEM_W(0X328, ctx->r4) = ctx->f4.u32l;
    // 0x800090C4: lwc1        $f6, 0x334($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X334);
    // 0x800090C8: lwc1        $f8, 0x32C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X32C);
    // 0x800090CC: lwc1        $f16, 0x328($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X328);
    // 0x800090D0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800090D4: nop

    // 0x800090D8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800090DC: swc1        $f18, 0x33C($a0)
    MEM_W(0X33C, ctx->r4) = ctx->f18.u32l;
    // 0x800090E0: lwc1        $f4, 0x338($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X338);
    // 0x800090E4: lwc1        $f6, 0x330($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X330);
    // 0x800090E8: lwc1        $f10, 0x328($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X328);
    // 0x800090EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800090F0: nop

    // 0x800090F4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800090F8: swc1        $f16, 0x340($a0)
    MEM_W(0X340, ctx->r4) = ctx->f16.u32l;
L_800090FC:
    // 0x800090FC: b           L_80009474
    // 0x80009100: nop

        goto L_80009474;
    // 0x80009100: nop

L_80009104:
    // 0x80009104: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80009108: lw          $t1, -0x73E8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X73E8);
    // 0x8000910C: nop

    // 0x80009110: lw          $t2, 0x144($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X144);
    // 0x80009114: nop

    // 0x80009118: beq         $t2, $zero, L_80009474
    if (ctx->r10 == 0) {
        // 0x8000911C: nop

            goto L_80009474;
    }
    // 0x8000911C: nop

    // 0x80009120: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80009124: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x80009128: nop

    // 0x8000912C: lw          $t4, 0x144($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X144);
    // 0x80009130: nop

    // 0x80009134: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80009138: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8000913C: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x80009140: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80009144: nop

    // 0x80009148: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8000914C: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x80009150: nop

    // 0x80009154: bne         $t6, $t7, L_8000916C
    if (ctx->r14 != ctx->r15) {
        // 0x80009158: nop

            goto L_8000916C;
    }
    // 0x80009158: nop

    // 0x8000915C: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x80009160: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80009164: beq         $t8, $at, L_80009304
    if (ctx->r24 == ctx->r1) {
        // 0x80009168: nop

            goto L_80009304;
    }
    // 0x80009168: nop

L_8000916C:
    // 0x8000916C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009170: nop

    // 0x80009174: lhu         $t9, 0xA($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0XA);
    // 0x80009178: nop

    // 0x8000917C: bne         $t9, $a1, L_800092B8
    if (ctx->r25 != ctx->r5) {
        // 0x80009180: nop

            goto L_800092B8;
    }
    // 0x80009180: nop

    // 0x80009184: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x80009188: nop

    // 0x8000918C: bne         $t1, $a2, L_800092B8
    if (ctx->r9 != ctx->r6) {
        // 0x80009190: nop

            goto L_800092B8;
    }
    // 0x80009190: nop

    // 0x80009194: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80009198: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8000919C: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x800091A0: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x800091A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800091A8: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800091AC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800091B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800091B4: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800091B8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800091BC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800091C0: swc1        $f10, 0x32C($a0)
    MEM_W(0X32C, ctx->r4) = ctx->f10.u32l;
    // 0x800091C4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800091C8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800091CC: lh          $t5, 0x6($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X6);
    // 0x800091D0: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800091D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800091D8: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800091DC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800091E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800091E4: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800091E8: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x800091EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800091F0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800091F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800091F8: nop

    // 0x800091FC: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80009200: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80009204: swc1        $f16, 0x330($a0)
    MEM_W(0X330, ctx->r4) = ctx->f16.u32l;
    // 0x80009208: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8000920C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009210: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80009214: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x80009218: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8000921C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80009220: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80009224: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009228: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x8000922C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80009230: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80009234: swc1        $f10, 0x334($a0)
    MEM_W(0X334, ctx->r4) = ctx->f10.u32l;
    // 0x80009238: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8000923C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009240: lh          $t6, 0x6($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X6);
    // 0x80009244: lh          $t7, 0x2($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2);
    // 0x80009248: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8000924C: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x80009250: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80009254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80009258: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8000925C: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80009260: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80009264: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d);
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80009268: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000926C: nop

    // 0x80009270: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80009274: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80009278: swc1        $f16, 0x338($a0)
    MEM_W(0X338, ctx->r4) = ctx->f16.u32l;
    // 0x8000927C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80009280: nop

    // 0x80009284: swc1        $f18, 0x328($a0)
    MEM_W(0X328, ctx->r4) = ctx->f18.u32l;
    // 0x80009288: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8000928C: nop

    // 0x80009290: sw          $t8, 0x344($a0)
    MEM_W(0X344, ctx->r4) = ctx->r24;
    // 0x80009294: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x80009298: nop

    // 0x8000929C: sw          $t9, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r25;
    // 0x800092A0: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800092A4: nop

    // 0x800092A8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800092AC: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800092B0: b           L_80009304
    // 0x800092B4: nop

        goto L_80009304;
    // 0x800092B4: nop

L_800092B8:
    // 0x800092B8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800092BC: nop

    // 0x800092C0: addiu       $t3, $t2, 0x10
    ctx->r11 = ADD32(ctx->r10, 0X10);
    // 0x800092C4: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800092C8: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x800092CC: nop

    // 0x800092D0: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800092D4: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x800092D8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800092DC: nop

    // 0x800092E0: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x800092E4: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800092E8: nop

    // 0x800092EC: bne         $t5, $t8, L_8000916C
    if (ctx->r13 != ctx->r24) {
        // 0x800092F0: nop

            goto L_8000916C;
    }
    // 0x800092F0: nop

    // 0x800092F4: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800092F8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800092FC: bne         $t9, $at, L_8000916C
    if (ctx->r25 != ctx->r1) {
        // 0x80009300: nop

            goto L_8000916C;
    }
    // 0x80009300: nop

L_80009304:
    // 0x80009304: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x80009308: nop

    // 0x8000930C: bne         $t0, $zero, L_8000946C
    if (ctx->r8 != 0) {
        // 0x80009310: nop

            goto L_8000946C;
    }
    // 0x80009310: nop

    // 0x80009314: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80009318: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8000931C: lh          $t2, 0x72A0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X72A0);
    // 0x80009320: lh          $t1, 0x723C($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X723C);
    // 0x80009324: nop

    // 0x80009328: beq         $t1, $t2, L_80009338
    if (ctx->r9 == ctx->r10) {
        // 0x8000932C: nop

            goto L_80009338;
    }
    // 0x8000932C: nop

    // 0x80009330: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80009334: sh          $zero, 0x7294($at)
    MEM_H(0X7294, ctx->r1) = 0;
L_80009338:
    // 0x80009338: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000933C: lw          $t3, -0x73E8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X73E8);
    // 0x80009340: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80009344: lh          $t6, 0x7294($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7294);
    // 0x80009348: lw          $t4, 0x144($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X144);
    // 0x8000934C: sll         $t5, $t6, 4
    ctx->r13 = S32(ctx->r14 << 4);
    // 0x80009350: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x80009354: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80009358: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8000935C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009360: lh          $t9, 0x4($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X4);
    // 0x80009364: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x80009368: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8000936C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80009370: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80009374: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80009378: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8000937C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80009380: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80009384: swc1        $f16, 0x32C($a0)
    MEM_W(0X32C, ctx->r4) = ctx->f16.u32l;
    // 0x80009388: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8000938C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009390: lh          $t3, 0x6($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6);
    // 0x80009394: lh          $t6, 0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X2);
    // 0x80009398: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8000939C: addu        $t4, $t3, $t6
    ctx->r12 = ADD32(ctx->r11, ctx->r14);
    // 0x800093A0: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800093A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800093A8: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800093AC: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x800093B0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800093B4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800093B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800093BC: nop

    // 0x800093C0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800093C4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800093C8: swc1        $f18, 0x330($a0)
    MEM_W(0X330, ctx->r4) = ctx->f18.u32l;
    // 0x800093CC: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800093D0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800093D4: lh          $t8, 0x4($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X4);
    // 0x800093D8: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800093DC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800093E0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800093E4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800093E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800093EC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800093F0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d);
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800093F4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d);
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800093F8: swc1        $f16, 0x334($a0)
    MEM_W(0X334, ctx->r4) = ctx->f16.u32l;
    // 0x800093FC: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009400: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80009404: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x80009408: lh          $t2, 0x2($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X2);
    // 0x8000940C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80009410: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80009414: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80009418: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000941C: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80009420: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80009424: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80009428: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8000942C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80009430: nop

    // 0x80009434: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80009438: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8000943C: swc1        $f18, 0x338($a0)
    MEM_W(0X338, ctx->r4) = ctx->f18.u32l;
    // 0x80009440: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80009444: nop

    // 0x80009448: swc1        $f4, 0x328($a0)
    MEM_W(0X328, ctx->r4) = ctx->f4.u32l;
    // 0x8000944C: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80009450: lh          $t6, 0x7294($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7294);
    // 0x80009454: nop

    // 0x80009458: sw          $t6, 0x344($a0)
    MEM_W(0X344, ctx->r4) = ctx->r14;
    // 0x8000945C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80009460: lh          $t4, 0x7294($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7294);
    // 0x80009464: nop

    // 0x80009468: sw          $t4, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r12;
L_8000946C:
    // 0x8000946C: b           L_8000947C
    // 0x80009470: nop

        goto L_8000947C;
    // 0x80009470: nop

L_80009474:
    // 0x80009474: b           L_8000947C
    // 0x80009478: nop

        goto L_8000947C;
    // 0x80009478: nop

L_8000947C:
    // 0x8000947C: jr          $ra
    // 0x80009480: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80009480: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80009484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009484: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80009488: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000948C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80009490: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80009494: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80009498: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8000949C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800094A0: nop

    // 0x800094A4: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x800094A8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800094AC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800094B0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800094B4: lw          $t9, 0x34C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34C);
    // 0x800094B8: nop

    // 0x800094BC: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800094C0: beq         $t0, $zero, L_800094F0
    if (ctx->r8 == 0) {
        // 0x800094C4: nop

            goto L_800094F0;
    }
    // 0x800094C4: nop

    // 0x800094C8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800094CC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800094D0: jal         0x800B1BC8
    // 0x800094D4: nop

    func_800B1BC8(rdram, ctx);
        goto after_0;
    // 0x800094D4: nop

    after_0:
    // 0x800094D8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800094DC: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x800094E0: lw          $t2, 0x34C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34C);
    // 0x800094E4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800094E8: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x800094EC: sw          $t3, 0x34C($t1)
    MEM_W(0X34C, ctx->r9) = ctx->r11;
L_800094F0:
    // 0x800094F0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800094F4: nop

    // 0x800094F8: bne         $t4, $zero, L_80009508
    if (ctx->r12 != 0) {
        // 0x800094FC: nop

            goto L_80009508;
    }
    // 0x800094FC: nop

    // 0x80009500: b           L_80009748
    // 0x80009504: nop

        goto L_80009748;
    // 0x80009504: nop

L_80009508:
    // 0x80009508: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8000950C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80009510: lw          $t6, 0x344($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X344);
    // 0x80009514: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009518: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000951C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80009520: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80009524: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80009528: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8000952C: nop

    // 0x80009530: beq         $t0, $at, L_80009740
    if (ctx->r8 == ctx->r1) {
        // 0x80009534: nop

            goto L_80009740;
    }
    // 0x80009534: nop

    // 0x80009538: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000953C: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x80009540: lw          $t3, 0x34C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34C);
    // 0x80009544: nop

    // 0x80009548: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8000954C: sw          $t1, 0x34C($t2)
    MEM_W(0X34C, ctx->r10) = ctx->r9;
    // 0x80009550: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80009554: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80009558: jal         0x800B1B04
    // 0x8000955C: nop

    func_800B1B04(rdram, ctx);
        goto after_1;
    // 0x8000955C: nop

    after_1:
    // 0x80009560: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80009564: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80009568: lw          $t5, 0x344($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X344);
    // 0x8000956C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80009570: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80009574: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80009578: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8000957C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80009580: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x80009584: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x80009588: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x8000958C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009590: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80009594: ori         $t0, $a2, 0x245
    ctx->r8 = ctx->r6 | 0X245;
    // 0x80009598: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8000959C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800095A0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800095A4: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800095A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800095AC: jal         0x800B1F0C
    // 0x800095B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B1F0C(rdram, ctx);
        goto after_2;
    // 0x800095B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800095B4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800095B8: addiu       $at, $zero, -0x849
    ctx->r1 = ADD32(0, -0X849);
    // 0x800095BC: lw          $t1, 0xC0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0XC0);
    // 0x800095C0: nop

    // 0x800095C4: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x800095C8: sw          $t2, 0xC0($t3)
    MEM_W(0XC0, ctx->r11) = ctx->r10;
    // 0x800095CC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800095D0: nop

    // 0x800095D4: lw          $t5, 0xC0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC0);
    // 0x800095D8: nop

    // 0x800095DC: ori         $t6, $t5, 0x14
    ctx->r14 = ctx->r13 | 0X14;
    // 0x800095E0: sw          $t6, 0xC0($t4)
    MEM_W(0XC0, ctx->r12) = ctx->r14;
    // 0x800095E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800095E8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800095EC: nop

    // 0x800095F0: swc1        $f8, 0xF0($t7)
    MEM_W(0XF0, ctx->r15) = ctx->f8.u32l;
    // 0x800095F4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800095F8: nop

    // 0x800095FC: lwc1        $f20, 0xF0($t9)
    ctx->f20.u32l = MEM_W(ctx->r25, 0XF0);
    // 0x80009600: nop

    // 0x80009604: swc1        $f20, 0xEC($t9)
    MEM_W(0XEC, ctx->r25) = ctx->f20.u32l;
    // 0x80009608: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8000960C: nop

    // 0x80009610: swc1        $f20, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f20.u32l;
    // 0x80009614: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80009618: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8000961C: sw          $t8, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->r24;
    // 0x80009620: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80009624: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80009628: sh          $t2, 0xC4($t3)
    MEM_H(0XC4, ctx->r11) = ctx->r10;
    // 0x8000962C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80009630: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80009634: lwc1        $f10, 0x32C($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X32C);
    // 0x80009638: nop

    // 0x8000963C: swc1        $f10, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f10.u32l;
    // 0x80009640: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80009644: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80009648: lwc1        $f16, 0x330($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X330);
    // 0x8000964C: nop

    // 0x80009650: swc1        $f16, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f16.u32l;
    // 0x80009654: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80009658: nop

    // 0x8000965C: lwc1        $f18, 0x32C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X32C);
    // 0x80009660: nop

    // 0x80009664: swc1        $f18, 0x1A4($t9)
    MEM_W(0X1A4, ctx->r25) = ctx->f18.u32l;
    // 0x80009668: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8000966C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80009670: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80009674: lwc1        $f4, 0x330($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X330);
    // 0x80009678: nop

    // 0x8000967C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80009680: swc1        $f8, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->f8.u32l;
    // 0x80009684: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80009688: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000968C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80009690: nop

    // 0x80009694: swc1        $f10, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = ctx->f10.u32l;
    // 0x80009698: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8000969C: nop

    // 0x800096A0: lwc1        $f16, 0x1A4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X1A4);
    // 0x800096A4: lwc1        $f18, 0x32C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X32C);
    // 0x800096A8: lwc1        $f6, 0x1A0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X1A0);
    // 0x800096AC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800096B0: nop

    // 0x800096B4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800096B8: swc1        $f8, 0x1AC($t1)
    MEM_W(0X1AC, ctx->r9) = ctx->f8.u32l;
    // 0x800096BC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800096C0: nop

    // 0x800096C4: lwc1        $f10, 0x1A8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X1A8);
    // 0x800096C8: lwc1        $f16, 0x330($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X330);
    // 0x800096CC: lwc1        $f4, 0x1A0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X1A0);
    // 0x800096D0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800096D4: nop

    // 0x800096D8: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800096DC: swc1        $f6, 0x1B0($t2)
    MEM_W(0X1B0, ctx->r10) = ctx->f6.u32l;
    // 0x800096E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800096E4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800096E8: nop

    // 0x800096EC: swc1        $f8, 0xFC($t3)
    MEM_W(0XFC, ctx->r11) = ctx->f8.u32l;
    // 0x800096F0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800096F4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800096F8: lwc1        $f16, 0x1A0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X1A0);
    // 0x800096FC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80009700: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80009704: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80009708: nop

    // 0x8000970C: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x80009710: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80009714: swc1        $f6, 0x1B4($t5)
    MEM_W(0X1B4, ctx->r13) = ctx->f6.u32l;
    // 0x80009718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000971C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009720: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80009724: nop

    // 0x80009728: swc1        $f8, 0x1B8($t6)
    MEM_W(0X1B8, ctx->r14) = ctx->f8.u32l;
    // 0x8000972C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009730: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80009734: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80009738: nop

    // 0x8000973C: swc1        $f16, 0x1BC($t4)
    MEM_W(0X1BC, ctx->r12) = ctx->f16.u32l;
L_80009740:
    // 0x80009740: b           L_80009748
    // 0x80009744: nop

        goto L_80009748;
    // 0x80009744: nop

L_80009748:
    // 0x80009748: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000974C: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80009750: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80009754: jr          $ra
    // 0x80009758: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80009758: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8000975C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000975C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80009760: addiu       $t6, $a0, 0x40
    ctx->r14 = ADD32(ctx->r4, 0X40);
    // 0x80009764: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80009768: lw          $t7, 0x34C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34C);
    // 0x8000976C: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80009770: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80009774: sw          $t8, 0x34C($a0)
    MEM_W(0X34C, ctx->r4) = ctx->r24;
    // 0x80009778: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000977C: nop

    // 0x80009780: swc1        $f4, 0x1A4($a0)
    MEM_W(0X1A4, ctx->r4) = ctx->f4.u32l;
    // 0x80009784: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80009788: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000978C: nop

    // 0x80009790: swc1        $f6, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->f6.u32l;
    // 0x80009794: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80009798: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000979C: nop

    // 0x800097A0: swc1        $f8, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f8.u32l;
    // 0x800097A4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800097A8: lwc1        $f10, 0x1A4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1A4);
    // 0x800097AC: lwc1        $f16, 0xCC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x800097B0: lwc1        $f4, 0x1A0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800097B4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800097B8: nop

    // 0x800097BC: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800097C0: swc1        $f6, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = ctx->f6.u32l;
    // 0x800097C4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800097C8: lwc1        $f8, 0x1A8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1A8);
    // 0x800097CC: lwc1        $f10, 0xD0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x800097D0: lwc1        $f18, 0x1A0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800097D4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800097D8: nop

    // 0x800097DC: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800097E0: swc1        $f4, 0x1B0($a0)
    MEM_W(0X1B0, ctx->r4) = ctx->f4.u32l;
    // 0x800097E4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800097E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800097EC: lwc1        $f8, 0xFC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XFC);
    // 0x800097F0: lwc1        $f7, -0x2E30($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X2E30);
    // 0x800097F4: lwc1        $f6, -0x2E2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E2C);
    // 0x800097F8: lwc1        $f18, 0x1A0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800097FC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80009800: sub.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f16.d = ctx->f6.d - ctx->f10.d;
    // 0x80009804: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl);
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80009808: nop

    // 0x8000980C: div.d       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d);
    ctx->f8.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x80009810: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80009814: swc1        $f6, 0x1B4($a0)
    MEM_W(0X1B4, ctx->r4) = ctx->f6.u32l;
    // 0x80009818: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8000981C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80009820: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80009824: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009828: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000982C: lwc1        $f10, 0xE8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XE8);
    // 0x80009830: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x80009834: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80009838: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8000983C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80009840: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x80009844: mfhi        $t5
    ctx->r13 = hi;
    // 0x80009848: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8000984C: nop

    // 0x80009850: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009854: swc1        $f4, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f4.u32l;
    // 0x80009858: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000985C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80009860: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80009864: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009868: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000986C: lwc1        $f8, 0xEC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XEC);
    // 0x80009870: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x80009874: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80009878: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8000987C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80009880: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80009884: mfhi        $t9
    ctx->r25 = hi;
    // 0x80009888: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8000988C: nop

    // 0x80009890: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009894: swc1        $f18, 0xEC($t6)
    MEM_W(0XEC, ctx->r14) = ctx->f18.u32l;
    // 0x80009898: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8000989C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800098A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800098A4: lwc1        $f4, 0xE8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x800098A8: lwc1        $f6, 0x1A0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800098AC: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800098B0: nop

    // 0x800098B4: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800098B8: swc1        $f10, 0x1B8($a0)
    MEM_W(0X1B8, ctx->r4) = ctx->f10.u32l;
    // 0x800098BC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800098C0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800098C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800098C8: lwc1        $f16, 0xEC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XEC);
    // 0x800098CC: lwc1        $f8, 0x1A0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800098D0: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800098D4: nop

    // 0x800098D8: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800098DC: swc1        $f6, 0x1BC($a0)
    MEM_W(0X1BC, ctx->r4) = ctx->f6.u32l;
    // 0x800098E0: b           L_800098E8
    // 0x800098E4: nop

        goto L_800098E8;
    // 0x800098E4: nop

L_800098E8:
    // 0x800098E8: jr          $ra
    // 0x800098EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800098EC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800098F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800098F0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800098F4: addiu       $t6, $a0, 0x40
    ctx->r14 = ADD32(ctx->r4, 0X40);
    // 0x800098F8: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800098FC: lw          $t7, 0x34C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34C);
    // 0x80009900: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80009904: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80009908: beq         $t8, $zero, L_80009A30
    if (ctx->r24 == 0) {
        // 0x8000990C: nop

            goto L_80009A30;
    }
    // 0x8000990C: nop

    // 0x80009910: lwc1        $f4, 0x1A0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009914: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009918: nop

    // 0x8000991C: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80009920: nop

    // 0x80009924: bc1f        L_800099D0
    if (!c1cs) {
        // 0x80009928: nop

            goto L_800099D0;
    }
    // 0x80009928: nop

    // 0x8000992C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009930: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009934: lwc1        $f8, 0x1AC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1AC);
    // 0x80009938: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8000993C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80009940: lwc1        $f18, 0xCC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x80009944: nop

    // 0x80009948: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8000994C: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x80009950: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009954: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009958: lwc1        $f6, 0x1B0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x8000995C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009960: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80009964: lwc1        $f18, 0xD0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80009968: nop

    // 0x8000996C: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80009970: swc1        $f16, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f16.u32l;
    // 0x80009974: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009978: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x8000997C: lwc1        $f4, 0x1B4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x80009980: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80009984: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80009988: lwc1        $f18, 0xFC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XFC);
    // 0x8000998C: nop

    // 0x80009990: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80009994: swc1        $f10, 0xFC($t1)
    MEM_W(0XFC, ctx->r9) = ctx->f10.u32l;
    // 0x80009998: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8000999C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800099A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800099A4: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x800099A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800099AC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800099B0: mul.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d);
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x800099B4: lwc1        $f8, 0x1A0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800099B8: nop

    // 0x800099BC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800099C0: sub.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d);
    ctx->f4.d = ctx->f10.d - ctx->f18.d;
    // 0x800099C4: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d);
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x800099C8: b           L_80009A28
    // 0x800099CC: swc1        $f16, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f16.u32l;
        goto L_80009A28;
    // 0x800099CC: swc1        $f16, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f16.u32l;
L_800099D0:
    // 0x800099D0: lwc1        $f6, 0x1A4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1A4);
    // 0x800099D4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800099D8: nop

    // 0x800099DC: swc1        $f6, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f6.u32l;
    // 0x800099E0: lwc1        $f8, 0x1A8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1A8);
    // 0x800099E4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800099E8: nop

    // 0x800099EC: swc1        $f8, 0xD0($t3)
    MEM_W(0XD0, ctx->r11) = ctx->f8.u32l;
    // 0x800099F0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800099F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800099F8: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800099FC: nop

    // 0x80009A00: swc1        $f10, 0xFC($t4)
    MEM_W(0XFC, ctx->r12) = ctx->f10.u32l;
    // 0x80009A04: lw          $t5, 0x34C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X34C);
    // 0x80009A08: lui         $at, 0xFFFB
    ctx->r1 = S32(0XFFFB << 16);
    // 0x80009A0C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009A10: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80009A14: sw          $t6, 0x34C($a0)
    MEM_W(0X34C, ctx->r4) = ctx->r14;
    // 0x80009A18: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80009A1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80009A20: nop

    // 0x80009A24: swc1        $f18, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f18.u32l;
L_80009A28:
    // 0x80009A28: b           L_80009C54
    // 0x80009A2C: nop

        goto L_80009C54;
    // 0x80009A2C: nop

L_80009A30:
    // 0x80009A30: lw          $t7, 0x34C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34C);
    // 0x80009A34: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80009A38: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80009A3C: beq         $t8, $zero, L_80009BB8
    if (ctx->r24 == 0) {
        // 0x80009A40: nop

            goto L_80009BB8;
    }
    // 0x80009A40: nop

    // 0x80009A44: lwc1        $f4, 0x1A0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009A48: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80009A4C: nop

    // 0x80009A50: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80009A54: nop

    // 0x80009A58: bc1f        L_80009B4C
    if (!c1cs) {
        // 0x80009A5C: nop

            goto L_80009B4C;
    }
    // 0x80009A5C: nop

    // 0x80009A60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009A64: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009A68: lwc1        $f6, 0x1AC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1AC);
    // 0x80009A6C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80009A70: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80009A74: lwc1        $f18, 0xCC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x80009A78: nop

    // 0x80009A7C: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80009A80: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x80009A84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009A88: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009A8C: lwc1        $f16, 0x1B0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1B0);
    // 0x80009A90: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009A94: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80009A98: lwc1        $f18, 0xD0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80009A9C: nop

    // 0x80009AA0: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80009AA4: swc1        $f10, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f10.u32l;
    // 0x80009AA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009AAC: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009AB0: lwc1        $f4, 0x1B8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1B8);
    // 0x80009AB4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80009AB8: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80009ABC: lwc1        $f18, 0xE8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XE8);
    // 0x80009AC0: nop

    // 0x80009AC4: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80009AC8: swc1        $f8, 0xE8($t1)
    MEM_W(0XE8, ctx->r9) = ctx->f8.u32l;
    // 0x80009ACC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009AD0: lwc1        $f4, 0x257C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009AD4: lwc1        $f10, 0x1BC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1BC);
    // 0x80009AD8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80009ADC: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80009AE0: lwc1        $f18, 0xEC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XEC);
    // 0x80009AE4: nop

    // 0x80009AE8: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80009AEC: swc1        $f6, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f6.u32l;
    // 0x80009AF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009AF4: lwc1        $f10, 0x257C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009AF8: lwc1        $f8, 0x1B4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1B4);
    // 0x80009AFC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80009B00: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80009B04: lwc1        $f18, 0xFC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XFC);
    // 0x80009B08: nop

    // 0x80009B0C: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl);
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80009B10: swc1        $f16, 0xFC($t3)
    MEM_W(0XFC, ctx->r11) = ctx->f16.u32l;
    // 0x80009B14: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80009B18: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80009B1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009B20: lwc1        $f8, 0x257C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009B24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80009B28: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl);
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80009B2C: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d);
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80009B30: lwc1        $f4, 0x1A0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009B34: nop

    // 0x80009B38: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl);
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80009B3C: sub.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = ctx->f16.d - ctx->f18.d;
    // 0x80009B40: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d);
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80009B44: b           L_80009BB0
    // 0x80009B48: swc1        $f6, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f6.u32l;
        goto L_80009BB0;
    // 0x80009B48: swc1        $f6, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f6.u32l;
L_80009B4C:
    // 0x80009B4C: lwc1        $f10, 0x1A4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1A4);
    // 0x80009B50: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80009B54: nop

    // 0x80009B58: swc1        $f10, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f10.u32l;
    // 0x80009B5C: lwc1        $f4, 0x1A8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1A8);
    // 0x80009B60: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80009B64: nop

    // 0x80009B68: swc1        $f4, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f4.u32l;
    // 0x80009B6C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80009B70: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80009B74: nop

    // 0x80009B78: swc1        $f16, 0xE8($t6)
    MEM_W(0XE8, ctx->r14) = ctx->f16.u32l;
    // 0x80009B7C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80009B80: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80009B84: nop

    // 0x80009B88: swc1        $f18, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f18.u32l;
    // 0x80009B8C: lw          $t8, 0x34C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34C);
    // 0x80009B90: lui         $at, 0xFFF7
    ctx->r1 = S32(0XFFF7 << 16);
    // 0x80009B94: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009B98: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80009B9C: sw          $t9, 0x34C($a0)
    MEM_W(0X34C, ctx->r4) = ctx->r25;
    // 0x80009BA0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80009BA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009BA8: nop

    // 0x80009BAC: swc1        $f8, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f8.u32l;
L_80009BB0:
    // 0x80009BB0: b           L_80009C54
    // 0x80009BB4: nop

        goto L_80009C54;
    // 0x80009BB4: nop

L_80009BB8:
    // 0x80009BB8: lwc1        $f6, 0x1A0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009BBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80009BC0: nop

    // 0x80009BC4: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80009BC8: nop

    // 0x80009BCC: bc1f        L_80009C0C
    if (!c1cs) {
        // 0x80009BD0: nop

            goto L_80009C0C;
    }
    // 0x80009BD0: nop

    // 0x80009BD4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80009BD8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80009BDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009BE0: lwc1        $f16, 0x257C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009BE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80009BE8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl);
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80009BEC: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d);
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80009BF0: lwc1        $f6, 0x1A0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x80009BF4: nop

    // 0x80009BF8: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl);
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80009BFC: sub.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d);
    ctx->f16.d = ctx->f10.d - ctx->f8.d;
    // 0x80009C00: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d);
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80009C04: b           L_80009C54
    // 0x80009C08: swc1        $f4, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f4.u32l;
        goto L_80009C54;
    // 0x80009C08: swc1        $f4, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f4.u32l;
L_80009C0C:
    // 0x80009C0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009C10: lwc1        $f6, 0x257C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009C14: lwc1        $f18, 0x1B8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1B8);
    // 0x80009C18: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80009C1C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80009C20: lwc1        $f8, 0xE8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XE8);
    // 0x80009C24: nop

    // 0x80009C28: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl);
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80009C2C: swc1        $f16, 0xE8($t0)
    MEM_W(0XE8, ctx->r8) = ctx->f16.u32l;
    // 0x80009C30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80009C34: lwc1        $f18, 0x257C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X257C);
    // 0x80009C38: lwc1        $f4, 0x1BC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1BC);
    // 0x80009C3C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80009C40: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80009C44: lwc1        $f8, 0xEC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XEC);
    // 0x80009C48: nop

    // 0x80009C4C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl);
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80009C50: swc1        $f10, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->f10.u32l;
L_80009C54:
    // 0x80009C54: b           L_80009C5C
    // 0x80009C58: nop

        goto L_80009C5C;
    // 0x80009C58: nop

L_80009C5C:
    // 0x80009C5C: jr          $ra
    // 0x80009C60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80009C60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80009C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009C64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80009C68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009C6C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80009C70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009C74: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80009C78: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80009C7C: lw          $t8, -0x5B3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B3C);
    // 0x80009C80: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80009C84: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80009C88: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80009C8C: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80009C90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80009C94: jal         0x800BD1FC
    // 0x80009C98: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_0;
    // 0x80009C98: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80009C9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80009CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009CA4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80009CA8: jal         0x800BD218
    // 0x80009CAC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    SysMem_DmaCopy(rdram, ctx);
        goto after_1;
    // 0x80009CAC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80009CB0: addiu       $t9, $sp, 0x28
    ctx->r25 = ADD32(ctx->r29, 0X28);
    // 0x80009CB4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80009CB8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80009CBC: jal         0x800BC6EC
    // 0x80009CC0: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    SysMem_HeapAlloc(rdram, ctx);
        goto after_2;
    // 0x80009CC0: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    after_2:
    // 0x80009CC4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80009CC8: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x80009CCC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80009CD0: lw          $t4, -0x5B38($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5B38);
    // 0x80009CD4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80009CD8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80009CDC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80009CE0: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x80009CE4: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x80009CE8: jal         0x800BD1FC
    // 0x80009CEC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_3;
    // 0x80009CEC: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80009CF0: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x80009CF4: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80009CF8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80009CFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80009D00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80009D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80009D08: jal         0x800BD218
    // 0x80009D0C: subu        $a2, $t6, $t7
    ctx->r6 = SUB32(ctx->r14, ctx->r15);
    SysMem_DmaCopy(rdram, ctx);
        goto after_4;
    // 0x80009D0C: subu        $a2, $t6, $t7
    ctx->r6 = SUB32(ctx->r14, ctx->r15);
    after_4:
    // 0x80009D10: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80009D14: b           L_80009D24
    // 0x80009D18: nop

        goto L_80009D24;
    // 0x80009D18: nop

    // 0x80009D1C: b           L_80009D24
    // 0x80009D20: nop

        goto L_80009D24;
    // 0x80009D20: nop

L_80009D24:
    // 0x80009D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009D28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009D2C: jr          $ra
    // 0x80009D30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80009D30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80009D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009D3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009D40: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80009D44: nop

    // 0x80009D48: bne         $t6, $zero, L_80009D58
    if (ctx->r14 != 0) {
        // 0x80009D4C: nop

            goto L_80009D58;
    }
    // 0x80009D4C: nop

    // 0x80009D50: b           L_80009E4C
    // 0x80009D54: nop

        goto L_80009E4C;
    // 0x80009D54: nop

L_80009D58:
    // 0x80009D58: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80009D5C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80009D60: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80009D64: nop

    // 0x80009D68: beq         $t8, $at, L_80009E44
    if (ctx->r24 == ctx->r1) {
        // 0x80009D6C: nop

            goto L_80009E44;
    }
    // 0x80009D6C: nop

L_80009D70:
    // 0x80009D70: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80009D74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009D78: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80009D7C: nop

    // 0x80009D80: beq         $t0, $at, L_80009E24
    if (ctx->r8 == ctx->r1) {
        // 0x80009D84: nop

            goto L_80009E24;
    }
    // 0x80009D84: nop

    // 0x80009D88: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80009D8C: nop

    // 0x80009D90: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80009D94: jal         0x8005F064
    // 0x80009D98: nop

    func_8005F064(rdram, ctx);
        goto after_0;
    // 0x80009D98: nop

    after_0:
    // 0x80009D9C: bne         $v0, $zero, L_80009DE4
    if (ctx->r2 != 0) {
        // 0x80009DA0: nop

            goto L_80009DE4;
    }
    // 0x80009DA0: nop

    // 0x80009DA4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80009DA8:
    // 0x80009DA8: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80009DAC: lw          $t2, -0x73E8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X73E8);
    // 0x80009DB0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80009DB4: lw          $t3, 0x138($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X138);
    // 0x80009DB8: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80009DBC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80009DC0: sh          $zero, 0x1F0($t6)
    MEM_H(0X1F0, ctx->r14) = 0;
    // 0x80009DC4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80009DC8: nop

    // 0x80009DCC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80009DD0: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x80009DD4: bne         $at, $zero, L_80009DA8
    if (ctx->r1 != 0) {
        // 0x80009DD8: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80009DA8;
    }
    // 0x80009DD8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80009DDC: b           L_80009E24
    // 0x80009DE0: nop

        goto L_80009E24;
    // 0x80009DE0: nop

L_80009DE4:
    // 0x80009DE4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80009DE8:
    // 0x80009DE8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80009DEC: lw          $t9, -0x73E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X73E8);
    // 0x80009DF0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80009DF4: lw          $t0, 0x138($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X138);
    // 0x80009DF8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80009DFC: addu        $t4, $t0, $t2
    ctx->r12 = ADD32(ctx->r8, ctx->r10);
    // 0x80009E00: lhu         $t3, 0x1E0($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X1E0);
    // 0x80009E04: nop

    // 0x80009E08: sh          $t3, 0x1F0($t4)
    MEM_H(0X1F0, ctx->r12) = ctx->r11;
    // 0x80009E0C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80009E10: nop

    // 0x80009E14: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80009E18: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80009E1C: bne         $at, $zero, L_80009DE8
    if (ctx->r1 != 0) {
        // 0x80009E20: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_80009DE8;
    }
    // 0x80009E20: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80009E24:
    // 0x80009E24: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80009E28: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80009E2C: addiu       $t8, $t7, 0x30
    ctx->r24 = ADD32(ctx->r15, 0X30);
    // 0x80009E30: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80009E34: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80009E38: nop

    // 0x80009E3C: bne         $t9, $at, L_80009D70
    if (ctx->r25 != ctx->r1) {
        // 0x80009E40: nop

            goto L_80009D70;
    }
    // 0x80009E40: nop

L_80009E44:
    // 0x80009E44: b           L_80009E4C
    // 0x80009E48: nop

        goto L_80009E4C;
    // 0x80009E48: nop

L_80009E4C:
    // 0x80009E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80009E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009E54: jr          $ra
    // 0x80009E58: nop

    return;
    // 0x80009E58: nop

;}
RECOMP_FUNC void func_80009E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009E5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80009E60: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80009E64: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80009E68: nop

    // 0x80009E6C: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80009E70: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80009E74:
    // 0x80009E74: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80009E78: lw          $t7, -0x5B28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5B28);
    // 0x80009E7C: nop

    // 0x80009E80: bne         $t7, $zero, L_80009E9C
    if (ctx->r15 != 0) {
        // 0x80009E84: nop

            goto L_80009E9C;
    }
    // 0x80009E84: nop

    // 0x80009E88: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80009E8C: lw          $t8, -0x5B30($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B30);
    // 0x80009E90: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80009E94: b           L_80009EC4
    // 0x80009E98: sw          $t8, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r24;
        goto L_80009EC4;
    // 0x80009E98: sw          $t8, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r24;
L_80009E9C:
    // 0x80009E9C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80009EA0: lw          $t0, -0x73E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X73E8);
    // 0x80009EA4: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x80009EA8: lh          $t1, 0x122($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X122);
    // 0x80009EAC: lw          $t4, -0x5B30($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5B30);
    // 0x80009EB0: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80009EB4: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80009EB8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80009EBC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80009EC0: sw          $t5, 0x138($t6)
    MEM_W(0X138, ctx->r14) = ctx->r13;
L_80009EC4:
    // 0x80009EC4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80009EC8: nop

    // 0x80009ECC: addiu       $t8, $t7, 0x160
    ctx->r24 = ADD32(ctx->r15, 0X160);
    // 0x80009ED0: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80009ED4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80009ED8: nop

    // 0x80009EDC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80009EE0: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80009EE4: bne         $at, $zero, L_80009E74
    if (ctx->r1 != 0) {
        // 0x80009EE8: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_80009E74;
    }
    // 0x80009EE8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80009EEC: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80009EF0: lw          $t1, -0x5B28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5B28);
    // 0x80009EF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80009EF8: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x80009EFC: sw          $t2, -0x5B28($at)
    MEM_W(-0X5B28, ctx->r1) = ctx->r10;
    // 0x80009F00: b           L_80009F08
    // 0x80009F04: nop

        goto L_80009F08;
    // 0x80009F04: nop

L_80009F08:
    // 0x80009F08: jr          $ra
    // 0x80009F0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80009F0C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80009F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009F10: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80009F14: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80009F18: lw          $t6, -0x73E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73E8);
    // 0x80009F1C: nop

    // 0x80009F20: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x80009F24: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80009F28:
    // 0x80009F28: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x80009F2C: lw          $t7, -0x5B2C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5B2C);
    // 0x80009F30: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80009F34: nop

    // 0x80009F38: sw          $t7, 0x138($t8)
    MEM_W(0X138, ctx->r24) = ctx->r15;
    // 0x80009F3C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80009F40: nop

    // 0x80009F44: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80009F48: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80009F4C: bne         $at, $zero, L_80009F28
    if (ctx->r1 != 0) {
        // 0x80009F50: sw          $t0, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r8;
            goto L_80009F28;
    }
    // 0x80009F50: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80009F54: b           L_80009F5C
    // 0x80009F58: nop

        goto L_80009F5C;
    // 0x80009F58: nop

L_80009F5C:
    // 0x80009F5C: jr          $ra
    // 0x80009F60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80009F60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80009F64: nop

    // 0x80009F68: nop

    // 0x80009F6C: nop

;}
RECOMP_FUNC void func_80009F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009F70: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80009F74: addiu       $t6, $t6, -0x7278
    ctx->r14 = ADD32(ctx->r14, -0X7278);
    // 0x80009F78: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80009F7C: nop

    // 0x80009F80: ori         $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 | 0X1000;
    // 0x80009F84: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x80009F88: sw          $zero, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = 0;
    // 0x80009F8C: jr          $ra
    // 0x80009F90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80009F90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80009F94: jr          $ra
    // 0x80009F98: nop

    return;
    // 0x80009F98: nop

    // 0x80009F9C: jr          $ra
    // 0x80009FA0: nop

    return;
    // 0x80009FA0: nop

;}
RECOMP_FUNC void func_80009FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009FA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009FA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009FAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80009FB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009FB4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80009FB8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x80009FBC: lw          $t6, -0x73CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X73CC);
    // 0x80009FC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009FC4: beq         $t6, $at, L_80009FE0
    if (ctx->r14 == ctx->r1) {
        // 0x80009FC8: nop

            goto L_80009FE0;
    }
    // 0x80009FC8: nop

    // 0x80009FCC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80009FD0: lw          $a0, -0x73CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X73CC);
    // 0x80009FD4: jal         0x80016074
    // 0x80009FD8: nop

    func_80016074(rdram, ctx);
        goto after_0;
    // 0x80009FD8: nop

    after_0:
    // 0x80009FDC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80009FE0:
    // 0x80009FE0: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80009FE4: lh          $s0, -0x73A8($s0)
    ctx->r16 = MEM_H(ctx->r16, -0X73A8);
    // 0x80009FE8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80009FEC: beq         $s0, $at, L_8000A020
    if (ctx->r16 == ctx->r1) {
        // 0x80009FF0: nop

            goto L_8000A020;
    }
    // 0x80009FF0: nop

    // 0x80009FF4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80009FF8: beq         $s0, $at, L_8000A020
    if (ctx->r16 == ctx->r1) {
        // 0x80009FFC: nop

            goto L_8000A020;
    }
    // 0x80009FFC: nop

    // 0x8000A000: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x8000A004: beq         $s0, $at, L_8000A028
    if (ctx->r16 == ctx->r1) {
        // 0x8000A008: nop

            goto L_8000A028;
    }
    // 0x8000A008: nop

    // 0x8000A00C: addiu       $at, $zero, 0x1F6
    ctx->r1 = ADD32(0, 0X1F6);
    // 0x8000A010: beq         $s0, $at, L_8000A020
    if (ctx->r16 == ctx->r1) {
        // 0x8000A014: nop

            goto L_8000A020;
    }
    // 0x8000A014: nop

    // 0x8000A018: b           L_8000A25C
    // 0x8000A01C: nop

        goto L_8000A25C;
    // 0x8000A01C: nop

L_8000A020:
    // 0x8000A020: b           L_8000A25C
    // 0x8000A024: nop

        goto L_8000A25C;
    // 0x8000A024: nop

L_8000A028:
    // 0x8000A028: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000A02C: nop

    // 0x8000A030: beq         $t7, $zero, L_8000A04C
    if (ctx->r15 == 0) {
        // 0x8000A034: nop

            goto L_8000A04C;
    }
    // 0x8000A034: nop

    // 0x8000A038: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8000A03C: nop

    // 0x8000A040: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000A044: bne         $t9, $zero, L_8000A25C
    if (ctx->r25 != 0) {
        // 0x8000A048: nop

            goto L_8000A25C;
    }
    // 0x8000A048: nop

L_8000A04C:
    // 0x8000A04C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000A050: nop

    // 0x8000A054: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8000A058: nop

    // 0x8000A05C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8000A060: bne         $t2, $zero, L_8000A254
    if (ctx->r10 != 0) {
        // 0x8000A064: nop

            goto L_8000A254;
    }
    // 0x8000A064: nop

    // 0x8000A068: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000A06C: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8000A070: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8000A074: lhu         $t5, 0x11A4($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X11A4);
    // 0x8000A078: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8000A07C: nop

    // 0x8000A080: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x8000A084: beq         $t6, $zero, L_8000A254
    if (ctx->r14 == 0) {
        // 0x8000A088: nop

            goto L_8000A254;
    }
    // 0x8000A088: nop

    // 0x8000A08C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000A090: jal         0x800198F8
    // 0x8000A094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800198F8(rdram, ctx);
        goto after_1;
    // 0x8000A094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8000A098: jal         0x800045AC
    // 0x8000A09C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_2;
    // 0x8000A09C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8000A0A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8000A0A4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000A0A8: nop

    // 0x8000A0AC: beq         $t7, $zero, L_8000A0E0
    if (ctx->r15 == 0) {
        // 0x8000A0B0: nop

            goto L_8000A0E0;
    }
    // 0x8000A0B0: nop

    // 0x8000A0B4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8000A0B8: nop

    // 0x8000A0BC: lw          $t9, 0x1A8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1A8);
    // 0x8000A0C0: nop

    // 0x8000A0C4: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8000A0C8: sw          $t0, 0x1A8($t8)
    MEM_W(0X1A8, ctx->r24) = ctx->r8;
    // 0x8000A0CC: jal         0x8000BB00
    // 0x8000A0D0: nop

    func_8000BB00(rdram, ctx);
        goto after_3;
    // 0x8000A0D0: nop

    after_3:
    // 0x8000A0D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8000A0D8: jal         0x8000C3B0
    // 0x8000A0DC: nop

    func_8000C3B0(rdram, ctx);
        goto after_4;
    // 0x8000A0DC: nop

    after_4:
L_8000A0E0:
    // 0x8000A0E0: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x8000A0E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A0E8: sh          $t1, 0x7254($at)
    MEM_H(0X7254, ctx->r1) = ctx->r9;
    // 0x8000A0EC: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x8000A0F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A0F4: sh          $t2, 0x725C($at)
    MEM_H(0X725C, ctx->r1) = ctx->r10;
    // 0x8000A0F8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8000A0FC: nop

    // 0x8000A100: lw          $t4, 0x1A8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1A8);
    // 0x8000A104: nop

    // 0x8000A108: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x8000A10C: sw          $t5, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = ctx->r13;
    // 0x8000A110: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8000A114: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A118: sw          $t6, -0x73CC($at)
    MEM_W(-0X73CC, ctx->r1) = ctx->r14;
    // 0x8000A11C: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000A120: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000A124: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x8000A128: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8000A12C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000A130: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A134: swc1        $f4, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f4.u32l;
    // 0x8000A138: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x8000A13C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A140: sw          $t9, -0x44F8($at)
    MEM_W(-0X44F8, ctx->r1) = ctx->r25;
    // 0x8000A144: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x8000A148: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A14C: sw          $t0, -0x44F4($at)
    MEM_W(-0X44F4, ctx->r1) = ctx->r8;
    // 0x8000A150: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000A154: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A158: swc1        $f6, -0x44F0($at)
    MEM_W(-0X44F0, ctx->r1) = ctx->f6.u32l;
    // 0x8000A15C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8000A160: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000A164: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A168: swc1        $f8, -0x44EC($at)
    MEM_W(-0X44EC, ctx->r1) = ctx->f8.u32l;
    // 0x8000A16C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000A170: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A174: swc1        $f10, -0x44E8($at)
    MEM_W(-0X44E8, ctx->r1) = ctx->f10.u32l;
    // 0x8000A178: jal         0x80022124
    // 0x8000A17C: nop

    func_80022124(rdram, ctx);
        goto after_5;
    // 0x8000A17C: nop

    after_5:
    // 0x8000A180: jal         0x80021F20
    // 0x8000A184: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    AudioGeneral_BGMFadeOut(rdram, ctx);
        goto after_6;
    // 0x8000A184: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_6:
    // 0x8000A188: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8000A18C: lui         $t8, 0x7FFF
    ctx->r24 = S32(0X7FFF << 16);
    // 0x8000A190: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8000A194: sw          $t8, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->r24;
    // 0x8000A198: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000A19C: nop

    // 0x8000A1A0: lw          $t4, 0xC0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC0);
    // 0x8000A1A4: nop

    // 0x8000A1A8: ori         $t5, $t4, 0x48
    ctx->r13 = ctx->r12 | 0X48;
    // 0x8000A1AC: sw          $t5, 0xC0($t2)
    MEM_W(0XC0, ctx->r10) = ctx->r13;
    // 0x8000A1B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000A1B4: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8000A1B8: sh          $t3, 0xC4($t6)
    MEM_H(0XC4, ctx->r14) = ctx->r11;
    // 0x8000A1BC: jal         0x80016074
    // 0x8000A1C0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80016074(rdram, ctx);
        goto after_7;
    // 0x8000A1C0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_7:
    // 0x8000A1C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8000A1C8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000A1CC: nop

    // 0x8000A1D0: beq         $t7, $zero, L_8000A1E4
    if (ctx->r15 == 0) {
        // 0x8000A1D4: nop

            goto L_8000A1E4;
    }
    // 0x8000A1D4: nop

    // 0x8000A1D8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000A1DC: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8000A1E0: sh          $t9, 0xC4($t0)
    MEM_H(0XC4, ctx->r8) = ctx->r25;
L_8000A1E4:
    // 0x8000A1E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000A1E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000A1EC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000A1F0: addiu       $t8, $t8, 0x61D8
    ctx->r24 = ADD32(ctx->r24, 0X61D8);
    // 0x8000A1F4: swc1        $f16, 0x5F4($t8)
    MEM_W(0X5F4, ctx->r24) = ctx->f16.u32l;
    // 0x8000A1F8: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x8000A1FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000A200: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000A204: addiu       $t1, $t1, 0x61D8
    ctx->r9 = ADD32(ctx->r9, 0X61D8);
    // 0x8000A208: swc1        $f18, 0x5FC($t1)
    MEM_W(0X5FC, ctx->r9) = ctx->f18.u32l;
    // 0x8000A20C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000A210: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000A214: addiu       $t4, $t4, 0x61D8
    ctx->r12 = ADD32(ctx->r12, 0X61D8);
    // 0x8000A218: swc1        $f4, 0x72C($t4)
    MEM_W(0X72C, ctx->r12) = ctx->f4.u32l;
    // 0x8000A21C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000A220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000A224: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000A228: addiu       $t5, $t5, 0x61D8
    ctx->r13 = ADD32(ctx->r13, 0X61D8);
    // 0x8000A22C: swc1        $f6, 0x734($t5)
    MEM_W(0X734, ctx->r13) = ctx->f6.u32l;
    // 0x8000A230: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8000A234: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000A238: addiu       $t2, $t2, 0x61D8
    ctx->r10 = ADD32(ctx->r10, 0X61D8);
    // 0x8000A23C: swc1        $f8, 0x4BC($t2)
    MEM_W(0X4BC, ctx->r10) = ctx->f8.u32l;
    // 0x8000A240: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000A244: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A248: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000A24C: addiu       $t3, $t3, 0x61D8
    ctx->r11 = ADD32(ctx->r11, 0X61D8);
    // 0x8000A250: swc1        $f10, 0x4C4($t3)
    MEM_W(0X4C4, ctx->r11) = ctx->f10.u32l;
L_8000A254:
    // 0x8000A254: b           L_8000A25C
    // 0x8000A258: nop

        goto L_8000A25C;
    // 0x8000A258: nop

L_8000A25C:
    // 0x8000A25C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000A260: nop

    // 0x8000A264: lw          $t7, 0x1A8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A8);
    // 0x8000A268: nop

    // 0x8000A26C: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x8000A270: beq         $t9, $zero, L_8000A2A0
    if (ctx->r25 == 0) {
        // 0x8000A274: nop

            goto L_8000A2A0;
    }
    // 0x8000A274: nop

    // 0x8000A278: jal         0x800C1754
    // 0x8000A27C: nop

    MtxUtil_PushIdentity(rdram, ctx);
        goto after_8;
    // 0x8000A27C: nop

    after_8:
    // 0x8000A280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000A284: jal         0x8009A14C
    // 0x8000A288: nop

    func_8009A14C(rdram, ctx);
        goto after_9;
    // 0x8000A288: nop

    after_9:
    // 0x8000A28C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000A290: jal         0x800997D8
    // 0x8000A294: nop

    func_800997D8(rdram, ctx);
        goto after_10;
    // 0x8000A294: nop

    after_10:
    // 0x8000A298: jal         0x800C1A28
    // 0x8000A29C: nop

    MtxUtil_Pop(rdram, ctx);
        goto after_11;
    // 0x8000A29C: nop

    after_11:
L_8000A2A0:
    // 0x8000A2A0: b           L_8000A2B0
    // 0x8000A2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000A2B0;
    // 0x8000A2A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000A2A8: b           L_8000A2B0
    // 0x8000A2AC: nop

        goto L_8000A2B0;
    // 0x8000A2AC: nop

L_8000A2B0:
    // 0x8000A2B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A2B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000A2B8: jr          $ra
    // 0x8000A2BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000A2BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000A2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2C0: addiu       $sp, $sp, -0x2C8
    ctx->r29 = ADD32(ctx->r29, -0X2C8);
    // 0x8000A2C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000A2C8: sw          $a0, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = ctx->r4;
    // 0x8000A2CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000A2D0: lw          $t6, 0x2C8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C8);
    // 0x8000A2D4: nop

    // 0x8000A2D8: sw          $t6, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r14;
    // 0x8000A2DC: lw          $t7, 0x284($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X284);
    // 0x8000A2E0: nop

    // 0x8000A2E4: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x8000A2E8: nop

    // 0x8000A2EC: sw          $t8, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->r24;
    // 0x8000A2F0: sw          $zero, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = 0;
    // 0x8000A2F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000A2F8: nop

    // 0x8000A2FC: swc1        $f4, 0x290($sp)
    MEM_W(0X290, ctx->r29) = ctx->f4.u32l;
    // 0x8000A300: sw          $zero, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = 0;
    // 0x8000A304: sw          $zero, 0x2A4($sp)
    MEM_W(0X2A4, ctx->r29) = 0;
    // 0x8000A308: sw          $zero, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = 0;
    // 0x8000A30C: sw          $zero, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = 0;
    // 0x8000A310: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000A314: sw          $t9, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r25;
    // 0x8000A318: sw          $zero, 0x294($sp)
    MEM_W(0X294, ctx->r29) = 0;
    // 0x8000A31C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A320: sw          $zero, -0x5B18($at)
    MEM_W(-0X5B18, ctx->r1) = 0;
    // 0x8000A324: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A328: sw          $zero, -0x5B14($at)
    MEM_W(-0X5B14, ctx->r1) = 0;
    // 0x8000A32C: jal         0x800BCB54
    // 0x8000A330: nop

    func_800BCB54(rdram, ctx);
        goto after_0;
    // 0x8000A330: nop

    after_0:
    // 0x8000A334: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A338: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8000A33C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8000A340: jal         0x800BDC70
    // 0x8000A344: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BDC70(rdram, ctx);
        goto after_1;
    // 0x8000A344: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8000A348: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8000A34C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000A350: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000A354: jal         0x80099F90
    // 0x8000A358: nop

    func_80099F90(rdram, ctx);
        goto after_2;
    // 0x8000A358: nop

    after_2:
    // 0x8000A35C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A360: sw          $zero, 0x7238($at)
    MEM_W(0X7238, ctx->r1) = 0;
    // 0x8000A364: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8000A368: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A36C: sw          $t0, 0x7244($at)
    MEM_W(0X7244, ctx->r1) = ctx->r8;
    // 0x8000A370: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000A374: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000A378: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A37C: swc1        $f6, 0x727C($at)
    MEM_W(0X727C, ctx->r1) = ctx->f6.u32l;
    // 0x8000A380: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A384: swc1        $f6, 0x7270($at)
    MEM_W(0X7270, ctx->r1) = ctx->f6.u32l;
    // 0x8000A388: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000A38C: swc1        $f6, 0x7264($at)
    MEM_W(0X7264, ctx->r1) = ctx->f6.u32l;
    // 0x8000A390: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000A394: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000A398: lwc1        $f8, 0x25A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X25A8);
    // 0x8000A39C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8000A3A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A3A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A3A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A3AC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000A3B0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x8000A3B4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000A3B8: sw          $t2, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r10;
    // 0x8000A3BC: nop

    // 0x8000A3C0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8000A3C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000A3C8: lwc1        $f16, 0x25B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X25B0);
    // 0x8000A3CC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8000A3D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000A3D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000A3D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A3DC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000A3E0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8000A3E4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8000A3E8: sw          $t4, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r12;
    // 0x8000A3EC: nop

    // 0x8000A3F0: jal         0x80015E50
    // 0x8000A3F4: nop

    func_80015E50(rdram, ctx);
        goto after_3;
    // 0x8000A3F4: nop

    after_3:
    // 0x8000A3F8: jal         0x80015E94
    // 0x8000A3FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80015E94(rdram, ctx);
        goto after_4;
    // 0x8000A3FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8000A400: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8000A404: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000A408: nop

    // 0x8000A40C: swc1        $f4, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->f4.u32l;
    // 0x8000A410: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8000A414: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000A418: nop

    // 0x8000A41C: swc1        $f6, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->f6.u32l;
    // 0x8000A420: jal         0x8001A690
    // 0x8000A424: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001A690(rdram, ctx);
        goto after_5;
    // 0x8000A424: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x8000A428: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8000A42C: sh          $t5, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r13;
    // 0x8000A430: jal         0x800ACE50
    // 0x8000A434: nop

    func_800ACE50(rdram, ctx);
        goto after_6;
    // 0x8000A434: nop

    after_6:
    // 0x8000A438: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8000A43C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000A440: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000A444: addiu       $t6, $t6, 0x61D8
    ctx->r14 = ADD32(ctx->r14, 0X61D8);
    // 0x8000A448: swc1        $f8, 0x5F4($t6)
    MEM_W(0X5F4, ctx->r14) = ctx->f8.u32l;
    // 0x8000A44C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000A450: addiu       $t7, $t7, 0x61D8
    ctx->r15 = ADD32(ctx->r15, 0X61D8);
    // 0x8000A454: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8000A458: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000A45C: lwc1        $f10, 0x5F4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X5F4);
    // 0x8000A460: nop

    // 0x8000A464: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8000A468: swc1        $f18, 0x5FC($t7)
    MEM_W(0X5FC, ctx->r15) = ctx->f18.u32l;
    // 0x8000A46C: lui         $at, 0x43A8
    ctx->r1 = S32(0X43A8 << 16);
    // 0x8000A470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000A474: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000A478: addiu       $t8, $t8, 0x61D8
    ctx->r24 = ADD32(ctx->r24, 0X61D8);
    // 0x8000A47C: swc1        $f4, 0x5DC($t8)
    MEM_W(0X5DC, ctx->r24) = ctx->f4.u32l;
    // 0x8000A480: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A484: sw          $zero, -0x5B20($at)
    MEM_W(-0X5B20, ctx->r1) = 0;
    // 0x8000A488: sw          $zero, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = 0;
    // 0x8000A48C: sw          $zero, 0x264($sp)
    MEM_W(0X264, ctx->r29) = 0;
    // 0x8000A490: jal         0x800AE348
    // 0x8000A494: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    ContPak_SetPakInitializationAttempts(rdram, ctx);
        goto after_7;
    // 0x8000A494: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x8000A498: jal         0x80098820
    // 0x8000A49C: nop

    func_80098820(rdram, ctx);
        goto after_8;
    // 0x8000A49C: nop

    after_8:
    // 0x8000A4A0: jal         0x80098868
    // 0x8000A4A4: nop

    func_80098868(rdram, ctx);
        goto after_9;
    // 0x8000A4A4: nop

    after_9:
    // 0x8000A4A8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8000A4AC: lw          $t9, -0x5B20($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B20);
    // 0x8000A4B0: nop

    // 0x8000A4B4: bne         $t9, $zero, L_8000B0C4
    if (ctx->r25 != 0) {
        // 0x8000A4B8: nop

            goto L_8000B0C4;
    }
    // 0x8000A4B8: nop

L_8000A4BC:
    // 0x8000A4BC: lw          $t0, 0x284($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X284);
    // 0x8000A4C0: addiu       $a1, $sp, 0x27C
    ctx->r5 = ADD32(ctx->r29, 0X27C);
    // 0x8000A4C4: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    // 0x8000A4C8: jal         0x800C143C
    // 0x8000A4CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_10;
    // 0x8000A4CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x8000A4D0: lw          $t1, 0x27C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X27C);
    // 0x8000A4D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A4D8: lh          $s0, 0x0($t1)
    ctx->r16 = MEM_H(ctx->r9, 0X0);
    // 0x8000A4DC: nop

    // 0x8000A4E0: beq         $s0, $at, L_8000A508
    if (ctx->r16 == ctx->r1) {
        // 0x8000A4E4: nop

            goto L_8000A508;
    }
    // 0x8000A4E4: nop

    // 0x8000A4E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A4EC: beq         $s0, $at, L_8000B064
    if (ctx->r16 == ctx->r1) {
        // 0x8000A4F0: nop

            goto L_8000B064;
    }
    // 0x8000A4F0: nop

    // 0x8000A4F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000A4F8: beq         $s0, $at, L_8000B090
    if (ctx->r16 == ctx->r1) {
        // 0x8000A4FC: nop

            goto L_8000B090;
    }
    // 0x8000A4FC: nop

    // 0x8000A500: b           L_8000B0A8
    // 0x8000A504: nop

        goto L_8000B0A8;
    // 0x8000A504: nop

L_8000A508:
    // 0x8000A508: lw          $t2, 0x280($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X280);
    // 0x8000A50C: nop

    // 0x8000A510: addiu       $t3, $t2, 0x7FFF
    ctx->r11 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000A514: lw          $t3, 0x2ED($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2ED);
    // 0x8000A518: nop

    // 0x8000A51C: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8000A520: beq         $at, $zero, L_8000B05C
    if (ctx->r1 == 0) {
        // 0x8000A524: nop

            goto L_8000B05C;
    }
    // 0x8000A524: nop

    // 0x8000A528: jal         0x80099768
    // 0x8000A52C: nop

    func_80099768(rdram, ctx);
        goto after_11;
    // 0x8000A52C: nop

    after_11:
    // 0x8000A530: jal         0x800AFB28
    // 0x8000A534: nop

    func_800AFB28(rdram, ctx);
        goto after_12;
    // 0x8000A534: nop

    after_12:
    // 0x8000A538: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8000A53C: lw          $t5, -0x4CC4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4CC4);
    // 0x8000A540: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8000A544: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8000A548: lw          $t4, -0x4CCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CCC);
    // 0x8000A54C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000A550: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8000A554: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8000A558: lwc1        $f12, 0x25D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X25D0);
    // 0x8000A55C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8000A560: jal         0x800BE510
    // 0x8000A564: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800BE510(rdram, ctx);
        goto after_13;
    // 0x8000A564: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_13:
    // 0x8000A568: jal         0x80032604
    // 0x8000A56C: nop

    func_80032604(rdram, ctx);
        goto after_14;
    // 0x8000A56C: nop

    after_14:
    // 0x8000A570: lw          $t6, 0x2B0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000A574: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A578: bne         $t6, $at, L_8000AF74
    if (ctx->r14 != ctx->r1) {
        // 0x8000A57C: nop

            goto L_8000AF74;
    }
    // 0x8000A57C: nop

    // 0x8000A580: jal         0x8001AB84
    // 0x8000A584: nop

    func_8001AB84(rdram, ctx);
        goto after_15;
    // 0x8000A584: nop

    after_15:
    // 0x8000A588: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000A58C: addiu       $t7, $t7, -0x5AC0
    ctx->r15 = ADD32(ctx->r15, -0X5AC0);
    // 0x8000A590: sw          $t7, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r15;
    // 0x8000A594: sw          $zero, 0x288($sp)
    MEM_W(0X288, ctx->r29) = 0;
    // 0x8000A598: sw          $zero, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = 0;
    // 0x8000A59C: sw          $zero, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = 0;
L_8000A5A0:
    // 0x8000A5A0: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A5A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A5A8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8000A5AC: nop

    // 0x8000A5B0: bne         $t9, $at, L_8000A5C0
    if (ctx->r25 != ctx->r1) {
        // 0x8000A5B4: nop

            goto L_8000A5C0;
    }
    // 0x8000A5B4: nop

    // 0x8000A5B8: b           L_8000A820
    // 0x8000A5BC: nop

        goto L_8000A820;
    // 0x8000A5BC: nop

L_8000A5C0:
    // 0x8000A5C0: lw          $t0, 0x26C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A5C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000A5C8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8000A5CC: nop

    // 0x8000A5D0: beq         $t1, $at, L_8000A60C
    if (ctx->r9 == ctx->r1) {
        // 0x8000A5D4: nop

            goto L_8000A60C;
    }
    // 0x8000A5D4: nop

    // 0x8000A5D8: lw          $t2, 0x26C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A5DC: nop

    // 0x8000A5E0: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    // 0x8000A5E4: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x8000A5E8: jal         0x8008EAA8
    // 0x8000A5EC: nop

    func_8008EAA8(rdram, ctx);
        goto after_16;
    // 0x8000A5EC: nop

    after_16:
    // 0x8000A5F0: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A5F4: nop

    // 0x8000A5F8: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8000A5FC: nop

    // 0x8000A600: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000A604: b           L_8000A628
    // 0x8000A608: sw          $t5, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r13;
        goto L_8000A628;
    // 0x8000A608: sw          $t5, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r13;
L_8000A60C:
    // 0x8000A60C: lw          $t6, 0x26C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A610: lw          $t7, 0x2B4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2B4);
    // 0x8000A614: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8000A618: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000A61C: sw          $t8, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r24;
    // 0x8000A620: jal         0x8008EAA8
    // 0x8000A624: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_17;
    // 0x8000A624: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_17:
L_8000A628:
    // 0x8000A628: lw          $t9, 0x26C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A62C: nop

    // 0x8000A630: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8000A634: nop

    // 0x8000A638: beq         $t0, $zero, L_8000A7C0
    if (ctx->r8 == 0) {
        // 0x8000A63C: nop

            goto L_8000A7C0;
    }
    // 0x8000A63C: nop

    // 0x8000A640: lw          $t1, 0x2BC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000A644: lw          $t2, 0x2B8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2B8);
    // 0x8000A648: nop

    // 0x8000A64C: bne         $t1, $t2, L_8000A75C
    if (ctx->r9 != ctx->r10) {
        // 0x8000A650: nop

            goto L_8000A75C;
    }
    // 0x8000A650: nop

    // 0x8000A654: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A658: nop

    // 0x8000A65C: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8000A660: nop

    // 0x8000A664: beq         $t4, $zero, L_8000A688
    if (ctx->r12 == 0) {
        // 0x8000A668: nop

            goto L_8000A688;
    }
    // 0x8000A668: nop

    // 0x8000A66C: lw          $t5, 0x26C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000A674: lw          $t9, 0x14($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X14);
    // 0x8000A678: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8000A67C: jalr        $t9
    // 0x8000A680: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_18;
    // 0x8000A680: nop

    after_18:
    // 0x8000A684: sw          $v0, 0x288($sp)
    MEM_W(0X288, ctx->r29) = ctx->r2;
L_8000A688:
    // 0x8000A688: lw          $t6, 0x26C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A68C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A690: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000A694: nop

    // 0x8000A698: bne         $t7, $at, L_8000A6D4
    if (ctx->r15 != ctx->r1) {
        // 0x8000A69C: nop

            goto L_8000A6D4;
    }
    // 0x8000A69C: nop

    // 0x8000A6A0: lw          $t8, 0x288($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X288);
    // 0x8000A6A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000A6A8: bne         $t8, $at, L_8000A6D4
    if (ctx->r24 != ctx->r1) {
        // 0x8000A6AC: nop

            goto L_8000A6D4;
    }
    // 0x8000A6AC: nop

    // 0x8000A6B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A6B4: sw          $t0, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r8;
    // 0x8000A6B8: lw          $t1, 0x26C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A6BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A6C0: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    // 0x8000A6C4: jal         0x8008ECE4
    // 0x8000A6C8: addiu       $a0, $a0, -0x2DA8
    ctx->r4 = ADD32(ctx->r4, -0X2DA8);
    func_8008ECE4(rdram, ctx);
        goto after_19;
    // 0x8000A6C8: addiu       $a0, $a0, -0x2DA8
    ctx->r4 = ADD32(ctx->r4, -0X2DA8);
    after_19:
    // 0x8000A6CC: b           L_8000A74C
    // 0x8000A6D0: nop

        goto L_8000A74C;
    // 0x8000A6D0: nop

L_8000A6D4:
    // 0x8000A6D4: lw          $t2, 0x26C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A6D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A6DC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8000A6E0: nop

    // 0x8000A6E4: bne         $t3, $at, L_8000A72C
    if (ctx->r11 != ctx->r1) {
        // 0x8000A6E8: nop

            goto L_8000A72C;
    }
    // 0x8000A6E8: nop

    // 0x8000A6EC: lw          $t4, 0x288($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X288);
    // 0x8000A6F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A6F4: bne         $t4, $at, L_8000A72C
    if (ctx->r12 != ctx->r1) {
        // 0x8000A6F8: nop

            goto L_8000A72C;
    }
    // 0x8000A6F8: nop

    // 0x8000A6FC: lw          $t5, 0x2A4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2A4);
    // 0x8000A700: nop

    // 0x8000A704: bne         $t5, $zero, L_8000A724
    if (ctx->r13 != 0) {
        // 0x8000A708: nop

            goto L_8000A724;
    }
    // 0x8000A708: nop

    // 0x8000A70C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000A710: sw          $t9, 0x2A4($sp)
    MEM_W(0X2A4, ctx->r29) = ctx->r25;
    // 0x8000A714: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A718: sw          $t6, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = ctx->r14;
    // 0x8000A71C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A720: sw          $zero, -0x5B1C($at)
    MEM_W(-0X5B1C, ctx->r1) = 0;
L_8000A724:
    // 0x8000A724: b           L_8000A74C
    // 0x8000A728: nop

        goto L_8000A74C;
    // 0x8000A728: nop

L_8000A72C:
    // 0x8000A72C: addiu       $t7, $zero, 0xF4
    ctx->r15 = ADD32(0, 0XF4);
    // 0x8000A730: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A734: sw          $t7, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r15;
    // 0x8000A738: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A73C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A740: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x8000A744: jal         0x8008ECE4
    // 0x8000A748: addiu       $a0, $a0, -0x2DA4
    ctx->r4 = ADD32(ctx->r4, -0X2DA4);
    func_8008ECE4(rdram, ctx);
        goto after_20;
    // 0x8000A748: addiu       $a0, $a0, -0x2DA4
    ctx->r4 = ADD32(ctx->r4, -0X2DA4);
    after_20:
L_8000A74C:
    // 0x8000A74C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8000A750: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A754: b           L_8000A7AC
    // 0x8000A758: sw          $t0, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r8;
        goto L_8000A7AC;
    // 0x8000A758: sw          $t0, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r8;
L_8000A75C:
    // 0x8000A75C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8000A760: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A764: sw          $t1, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r9;
    // 0x8000A768: lw          $t2, 0x26C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A76C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A770: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    // 0x8000A774: jal         0x8008ECE4
    // 0x8000A778: addiu       $a0, $a0, -0x2DA0
    ctx->r4 = ADD32(ctx->r4, -0X2DA0);
    func_8008ECE4(rdram, ctx);
        goto after_21;
    // 0x8000A778: addiu       $a0, $a0, -0x2DA0
    ctx->r4 = ADD32(ctx->r4, -0X2DA0);
    after_21:
    // 0x8000A77C: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A780: nop

    // 0x8000A784: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x8000A788: nop

    // 0x8000A78C: beq         $t4, $zero, L_8000A7AC
    if (ctx->r12 == 0) {
        // 0x8000A790: nop

            goto L_8000A7AC;
    }
    // 0x8000A790: nop

    // 0x8000A794: lw          $t5, 0x26C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A798: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000A79C: lw          $t9, 0x14($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X14);
    // 0x8000A7A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8000A7A4: jalr        $t9
    // 0x8000A7A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_22;
    // 0x8000A7A8: nop

    after_22:
L_8000A7AC:
    // 0x8000A7AC: lw          $t6, 0x2B8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2B8);
    // 0x8000A7B0: nop

    // 0x8000A7B4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000A7B8: b           L_8000A804
    // 0x8000A7BC: sw          $t7, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->r15;
        goto L_8000A804;
    // 0x8000A7BC: sw          $t7, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->r15;
L_8000A7C0:
    // 0x8000A7C0: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A7C4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A7C8: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x8000A7CC: jal         0x8008ECE4
    // 0x8000A7D0: addiu       $a0, $a0, -0x2D9C
    ctx->r4 = ADD32(ctx->r4, -0X2D9C);
    func_8008ECE4(rdram, ctx);
        goto after_23;
    // 0x8000A7D0: addiu       $a0, $a0, -0x2D9C
    ctx->r4 = ADD32(ctx->r4, -0X2D9C);
    after_23:
    // 0x8000A7D4: lw          $t0, 0x26C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A7D8: nop

    // 0x8000A7DC: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x8000A7E0: nop

    // 0x8000A7E4: beq         $t1, $zero, L_8000A804
    if (ctx->r9 == 0) {
        // 0x8000A7E8: nop

            goto L_8000A804;
    }
    // 0x8000A7E8: nop

    // 0x8000A7EC: lw          $t2, 0x26C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A7F0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000A7F4: lw          $t9, 0x14($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X14);
    // 0x8000A7F8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8000A7FC: jalr        $t9
    // 0x8000A800: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_24;
    // 0x8000A800: nop

    after_24:
L_8000A804:
    // 0x8000A804: lw          $t3, 0x2C4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C4);
    // 0x8000A808: lw          $t5, 0x26C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X26C);
    // 0x8000A80C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000A810: addiu       $t6, $t5, 0x28
    ctx->r14 = ADD32(ctx->r13, 0X28);
    // 0x8000A814: sw          $t6, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r14;
    // 0x8000A818: b           L_8000A5A0
    // 0x8000A81C: sw          $t4, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->r12;
        goto L_8000A5A0;
    // 0x8000A81C: sw          $t4, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->r12;
L_8000A820:
    // 0x8000A820: lw          $t7, 0x2A4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2A4);
    // 0x8000A824: nop

    // 0x8000A828: beq         $t7, $zero, L_8000A9D4
    if (ctx->r15 == 0) {
        // 0x8000A82C: nop

            goto L_8000A9D4;
    }
    // 0x8000A82C: nop

    // 0x8000A830: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000A834: lw          $t8, -0x5B1C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B1C);
    // 0x8000A838: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000A83C: bne         $t8, $at, L_8000A9D4
    if (ctx->r24 != ctx->r1) {
        // 0x8000A840: nop

            goto L_8000A9D4;
    }
    // 0x8000A840: nop

    // 0x8000A844: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A848: jal         0x8008EAA8
    // 0x8000A84C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8008EAA8(rdram, ctx);
        goto after_25;
    // 0x8000A84C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_25:
    // 0x8000A850: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A854: jal         0x8008ECE4
    // 0x8000A858: addiu       $a0, $a0, -0x2D98
    ctx->r4 = ADD32(ctx->r4, -0X2D98);
    func_8008ECE4(rdram, ctx);
        goto after_26;
    // 0x8000A858: addiu       $a0, $a0, -0x2D98
    ctx->r4 = ADD32(ctx->r4, -0X2D98);
    after_26:
    // 0x8000A85C: lw          $t0, 0x298($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X298);
    // 0x8000A860: nop

    // 0x8000A864: bne         $t0, $zero, L_8000A878
    if (ctx->r8 != 0) {
        // 0x8000A868: nop

            goto L_8000A878;
    }
    // 0x8000A868: nop

    // 0x8000A86C: addiu       $t1, $zero, 0xF4
    ctx->r9 = ADD32(0, 0XF4);
    // 0x8000A870: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A874: sw          $t1, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r9;
L_8000A878:
    // 0x8000A878: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A87C: jal         0x8008ECE4
    // 0x8000A880: addiu       $a0, $a0, -0x2D84
    ctx->r4 = ADD32(ctx->r4, -0X2D84);
    func_8008ECE4(rdram, ctx);
        goto after_27;
    // 0x8000A880: addiu       $a0, $a0, -0x2D84
    ctx->r4 = ADD32(ctx->r4, -0X2D84);
    after_27:
    // 0x8000A884: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8000A888: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A88C: sw          $t2, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r10;
    // 0x8000A890: lw          $t9, 0x298($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X298);
    // 0x8000A894: nop

    // 0x8000A898: beq         $t9, $zero, L_8000A8AC
    if (ctx->r25 == 0) {
        // 0x8000A89C: nop

            goto L_8000A8AC;
    }
    // 0x8000A89C: nop

    // 0x8000A8A0: addiu       $t3, $zero, 0xF4
    ctx->r11 = ADD32(0, 0XF4);
    // 0x8000A8A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A8A8: sw          $t3, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r11;
L_8000A8AC:
    // 0x8000A8AC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A8B0: jal         0x8008ECE4
    // 0x8000A8B4: addiu       $a0, $a0, -0x2D7C
    ctx->r4 = ADD32(ctx->r4, -0X2D7C);
    func_8008ECE4(rdram, ctx);
        goto after_28;
    // 0x8000A8B4: addiu       $a0, $a0, -0x2D7C
    ctx->r4 = ADD32(ctx->r4, -0X2D7C);
    after_28:
    // 0x8000A8B8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000A8BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000A8C0: sw          $t4, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r12;
    // 0x8000A8C4: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000A8C8: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8000A8CC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000A8D0: lhu         $t7, 0xEC0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XEC0);
    // 0x8000A8D4: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8000A8D8: nop

    // 0x8000A8DC: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8000A8E0: beq         $t8, $zero, L_8000A8F8
    if (ctx->r24 == 0) {
        // 0x8000A8E4: nop

            goto L_8000A8F8;
    }
    // 0x8000A8E4: nop

    // 0x8000A8E8: lw          $t0, 0x298($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X298);
    // 0x8000A8EC: nop

    // 0x8000A8F0: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000A8F4: sw          $t1, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r9;
L_8000A8F8:
    // 0x8000A8F8: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000A8FC: addiu       $t2, $t2, 0x60F0
    ctx->r10 = ADD32(ctx->r10, 0X60F0);
    // 0x8000A900: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000A904: lhu         $t3, 0xEEC($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XEEC);
    // 0x8000A908: lhu         $t9, 0x8($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X8);
    // 0x8000A90C: nop

    // 0x8000A910: and         $t4, $t9, $t3
    ctx->r12 = ctx->r25 & ctx->r11;
    // 0x8000A914: beq         $t4, $zero, L_8000A92C
    if (ctx->r12 == 0) {
        // 0x8000A918: nop

            goto L_8000A92C;
    }
    // 0x8000A918: nop

    // 0x8000A91C: lw          $t5, 0x298($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X298);
    // 0x8000A920: nop

    // 0x8000A924: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000A928: sw          $t6, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r14;
L_8000A92C:
    // 0x8000A92C: lw          $t7, 0x298($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X298);
    // 0x8000A930: nop

    // 0x8000A934: bgez        $t7, L_8000A940
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000A938: nop

            goto L_8000A940;
    }
    // 0x8000A938: nop

    // 0x8000A93C: sw          $zero, 0x298($sp)
    MEM_W(0X298, ctx->r29) = 0;
L_8000A940:
    // 0x8000A940: lw          $t8, 0x298($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X298);
    // 0x8000A944: nop

    // 0x8000A948: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8000A94C: bne         $at, $zero, L_8000A95C
    if (ctx->r1 != 0) {
        // 0x8000A950: nop

            goto L_8000A95C;
    }
    // 0x8000A950: nop

    // 0x8000A954: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A958: sw          $t0, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r8;
L_8000A95C:
    // 0x8000A95C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8000A960: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8000A964: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000A968: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x8000A96C: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x8000A970: addiu       $t3, $t3, 0x60F0
    ctx->r11 = ADD32(ctx->r11, 0X60F0);
    // 0x8000A974: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8000A978: or          $t9, $t1, $t2
    ctx->r25 = ctx->r9 | ctx->r10;
    // 0x8000A97C: and         $t5, $t4, $t9
    ctx->r13 = ctx->r12 & ctx->r25;
    // 0x8000A980: beq         $t5, $zero, L_8000A9D4
    if (ctx->r13 == 0) {
        // 0x8000A984: nop

            goto L_8000A9D4;
    }
    // 0x8000A984: nop

    // 0x8000A988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A98C: jal         0x8008EAA8
    // 0x8000A990: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8008EAA8(rdram, ctx);
        goto after_29;
    // 0x8000A990: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_29:
    // 0x8000A994: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A998: jal         0x8008ECE4
    // 0x8000A99C: addiu       $a0, $a0, -0x2D74
    ctx->r4 = ADD32(ctx->r4, -0X2D74);
    func_8008ECE4(rdram, ctx);
        goto after_30;
    // 0x8000A99C: addiu       $a0, $a0, -0x2D74
    ctx->r4 = ADD32(ctx->r4, -0X2D74);
    after_30:
    // 0x8000A9A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000A9A4: sw          $zero, -0x5B1C($at)
    MEM_W(-0X5B1C, ctx->r1) = 0;
    // 0x8000A9A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A9AC: sw          $t6, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = ctx->r14;
    // 0x8000A9B0: lw          $t7, 0x298($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X298);
    // 0x8000A9B4: nop

    // 0x8000A9B8: bne         $t7, $zero, L_8000A9D4
    if (ctx->r15 != 0) {
        // 0x8000A9BC: nop

            goto L_8000A9D4;
    }
    // 0x8000A9BC: nop

    // 0x8000A9C0: lw          $a0, 0x2AC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000A9C4: jal         0x800AE5F0
    // 0x8000A9C8: nop

    ContPak_SetFileDeleteParams(rdram, ctx);
        goto after_31;
    // 0x8000A9C8: nop

    after_31:
    // 0x8000A9CC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000A9D0: sw          $t8, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->r24;
L_8000A9D4:
    // 0x8000A9D4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8000A9D8: lw          $t0, 0x129C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X129C);
    // 0x8000A9DC: nop

    // 0x8000A9E0: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x8000A9E4: beq         $t1, $zero, L_8000AA0C
    if (ctx->r9 == 0) {
        // 0x8000A9E8: nop

            goto L_8000AA0C;
    }
    // 0x8000A9E8: nop

    // 0x8000A9EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A9F0: jal         0x8008EAA8
    // 0x8000A9F4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8008EAA8(rdram, ctx);
        goto after_32;
    // 0x8000A9F4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_32:
    // 0x8000A9F8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000A9FC: jal         0x8008ECE4
    // 0x8000AA00: addiu       $a0, $a0, -0x2D54
    ctx->r4 = ADD32(ctx->r4, -0X2D54);
    func_8008ECE4(rdram, ctx);
        goto after_33;
    // 0x8000AA00: addiu       $a0, $a0, -0x2D54
    ctx->r4 = ADD32(ctx->r4, -0X2D54);
    after_33:
    // 0x8000AA04: b           L_8000AA44
    // 0x8000AA08: nop

        goto L_8000AA44;
    // 0x8000AA08: nop

L_8000AA0C:
    // 0x8000AA0C: lw          $t2, 0x294($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X294);
    // 0x8000AA10: nop

    // 0x8000AA14: beq         $t2, $zero, L_8000AA44
    if (ctx->r10 == 0) {
        // 0x8000AA18: nop

            goto L_8000AA44;
    }
    // 0x8000AA18: nop

    // 0x8000AA1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000AA20: jal         0x8008EAA8
    // 0x8000AA24: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8008EAA8(rdram, ctx);
        goto after_34;
    // 0x8000AA24: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_34:
    // 0x8000AA28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000AA2C: jal         0x8008ECE4
    // 0x8000AA30: addiu       $a0, $a0, -0x2D40
    ctx->r4 = ADD32(ctx->r4, -0X2D40);
    func_8008ECE4(rdram, ctx);
        goto after_35;
    // 0x8000AA30: addiu       $a0, $a0, -0x2D40
    ctx->r4 = ADD32(ctx->r4, -0X2D40);
    after_35:
    // 0x8000AA34: lw          $t3, 0x294($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X294);
    // 0x8000AA38: nop

    // 0x8000AA3C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000AA40: sw          $t4, 0x294($sp)
    MEM_W(0X294, ctx->r29) = ctx->r12;
L_8000AA44:
    // 0x8000AA44: jal         0x8001AC74
    // 0x8000AA48: nop

    func_8001AC74(rdram, ctx);
        goto after_36;
    // 0x8000AA48: nop

    after_36:
    // 0x8000AA4C: jal         0x8001ABEC
    // 0x8000AA50: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001ABEC(rdram, ctx);
        goto after_37;
    // 0x8000AA50: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_37:
    // 0x8000AA54: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8000AA58: lw          $t9, -0x5B1C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5B1C);
    // 0x8000AA5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AA60: beq         $t9, $at, L_8000AD7C
    if (ctx->r25 == ctx->r1) {
        // 0x8000AA64: nop

            goto L_8000AD7C;
    }
    // 0x8000AA64: nop

    // 0x8000AA68: addiu       $t5, $sp, 0x28
    ctx->r13 = ADD32(ctx->r29, 0X28);
    // 0x8000AA6C: sw          $t5, 0x278($sp)
    MEM_W(0X278, ctx->r29) = ctx->r13;
    // 0x8000AA70: lw          $t6, 0x278($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X278);
    // 0x8000AA74: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8000AA78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000AA7C: lwc1        $f10, 0xD0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8000AA80: nop

    // 0x8000AA84: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl);
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000AA88: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000AA8C: nop

    // 0x8000AA90: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000AA94: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000AA98: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000AA9C: nop

    // 0x8000AAA0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000AAA4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8000AAA8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000AAAC: sw          $t8, 0x2C0($sp)
    MEM_W(0X2C0, ctx->r29) = ctx->r24;
    // 0x8000AAB0: nop

    // 0x8000AAB4: lw          $t0, 0x2C0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C0);
    // 0x8000AAB8: lw          $t1, 0x2AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AABC: nop

    // 0x8000AAC0: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000AAC4: beq         $at, $zero, L_8000AAEC
    if (ctx->r1 == 0) {
        // 0x8000AAC8: nop

            goto L_8000AAEC;
    }
    // 0x8000AAC8: nop

    // 0x8000AACC: lw          $t2, 0x278($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X278);
    // 0x8000AAD0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8000AAD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000AAD8: lwc1        $f6, 0xD0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8000AADC: nop

    // 0x8000AAE0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl);
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000AAE4: b           L_8000AB28
    // 0x8000AAE8: swc1        $f10, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f10.u32l;
        goto L_8000AB28;
    // 0x8000AAE8: swc1        $f10, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f10.u32l;
L_8000AAEC:
    // 0x8000AAEC: lw          $t3, 0x2AC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AAF0: lw          $t4, 0x2C0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C0);
    // 0x8000AAF4: nop

    // 0x8000AAF8: subu        $t9, $t3, $t4
    ctx->r25 = SUB32(ctx->r11, ctx->r12);
    // 0x8000AAFC: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8000AB00: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x8000AB04: bne         $at, $zero, L_8000AB28
    if (ctx->r1 != 0) {
        // 0x8000AB08: nop

            goto L_8000AB28;
    }
    // 0x8000AB08: nop

    // 0x8000AB0C: lw          $t6, 0x278($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X278);
    // 0x8000AB10: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8000AB14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000AB18: lwc1        $f16, 0xD0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x8000AB1C: nop

    // 0x8000AB20: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl);
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000AB24: swc1        $f4, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f4.u32l;
L_8000AB28:
    // 0x8000AB28: jal         0x80090754
    // 0x8000AB2C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80090754(rdram, ctx);
        goto after_38;
    // 0x8000AB2C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_38:
    // 0x8000AB30: jal         0x80090728
    // 0x8000AB34: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_80090728(rdram, ctx);
        goto after_39;
    // 0x8000AB34: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_39:
    // 0x8000AB38: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000AB3C: addiu       $t7, $t7, -0x59F8
    ctx->r15 = ADD32(ctx->r15, -0X59F8);
    // 0x8000AB40: sw          $t7, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r15;
    // 0x8000AB44: sw          $zero, 0x288($sp)
    MEM_W(0X288, ctx->r29) = 0;
    // 0x8000AB48: sw          $zero, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = 0;
    // 0x8000AB4C: sw          $zero, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = 0;
L_8000AB50:
    // 0x8000AB50: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AB54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000AB58: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8000AB5C: nop

    // 0x8000AB60: bne         $t0, $at, L_8000AB70
    if (ctx->r8 != ctx->r1) {
        // 0x8000AB64: nop

            goto L_8000AB70;
    }
    // 0x8000AB64: nop

    // 0x8000AB68: b           L_8000AD7C
    // 0x8000AB6C: nop

        goto L_8000AD7C;
    // 0x8000AB6C: nop

L_8000AB70:
    // 0x8000AB70: lw          $t1, 0x26C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AB74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000AB78: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8000AB7C: nop

    // 0x8000AB80: beq         $t2, $at, L_8000ABBC
    if (ctx->r10 == ctx->r1) {
        // 0x8000AB84: nop

            goto L_8000ABBC;
    }
    // 0x8000AB84: nop

    // 0x8000AB88: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AB8C: nop

    // 0x8000AB90: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    // 0x8000AB94: lw          $a1, 0xC($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC);
    // 0x8000AB98: jal         0x8008EAA8
    // 0x8000AB9C: nop

    func_8008EAA8(rdram, ctx);
        goto after_40;
    // 0x8000AB9C: nop

    after_40:
    // 0x8000ABA0: lw          $t4, 0x26C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ABA4: nop

    // 0x8000ABA8: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x8000ABAC: nop

    // 0x8000ABB0: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8000ABB4: b           L_8000ABD8
    // 0x8000ABB8: sw          $t5, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r13;
        goto L_8000ABD8;
    // 0x8000ABB8: sw          $t5, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r13;
L_8000ABBC:
    // 0x8000ABBC: lw          $t6, 0x26C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ABC0: lw          $t7, 0x2B4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2B4);
    // 0x8000ABC4: lw          $a0, 0x8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X8);
    // 0x8000ABC8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000ABCC: sw          $t8, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r24;
    // 0x8000ABD0: jal         0x8008EAA8
    // 0x8000ABD4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8008EAA8(rdram, ctx);
        goto after_41;
    // 0x8000ABD4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_41:
L_8000ABD8:
    // 0x8000ABD8: lw          $t0, 0x26C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ABDC: nop

    // 0x8000ABE0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x8000ABE4: nop

    // 0x8000ABE8: beq         $t1, $zero, L_8000AD4C
    if (ctx->r9 == 0) {
        // 0x8000ABEC: nop

            goto L_8000AD4C;
    }
    // 0x8000ABEC: nop

    // 0x8000ABF0: lw          $t2, 0x2A4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2A4);
    // 0x8000ABF4: nop

    // 0x8000ABF8: beq         $t2, $zero, L_8000ACE8
    if (ctx->r10 == 0) {
        // 0x8000ABFC: nop

            goto L_8000ACE8;
    }
    // 0x8000ABFC: nop

    // 0x8000AC00: lw          $t3, 0x2AC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AC04: lw          $t4, 0x2A0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2A0);
    // 0x8000AC08: nop

    // 0x8000AC0C: bne         $t3, $t4, L_8000ACE8
    if (ctx->r11 != ctx->r12) {
        // 0x8000AC10: nop

            goto L_8000ACE8;
    }
    // 0x8000AC10: nop

    // 0x8000AC14: addiu       $t9, $zero, 0xF4
    ctx->r25 = ADD32(0, 0XF4);
    // 0x8000AC18: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000AC1C: sw          $t9, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r25;
    // 0x8000AC20: lw          $t5, 0x26C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AC24: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000AC28: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x8000AC2C: jal         0x8008ECE4
    // 0x8000AC30: addiu       $a0, $a0, -0x2D2C
    ctx->r4 = ADD32(ctx->r4, -0X2D2C);
    func_8008ECE4(rdram, ctx);
        goto after_42;
    // 0x8000AC30: addiu       $a0, $a0, -0x2D2C
    ctx->r4 = ADD32(ctx->r4, -0X2D2C);
    after_42:
    // 0x8000AC34: lw          $t6, 0x26C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AC38: nop

    // 0x8000AC3C: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8000AC40: nop

    // 0x8000AC44: beq         $t7, $zero, L_8000ACD8
    if (ctx->r15 == 0) {
        // 0x8000AC48: nop

            goto L_8000ACD8;
    }
    // 0x8000AC48: nop

    // 0x8000AC4C: lw          $t8, 0x28C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28C);
    // 0x8000AC50: nop

    // 0x8000AC54: bne         $t8, $zero, L_8000ACBC
    if (ctx->r24 != 0) {
        // 0x8000AC58: nop

            goto L_8000ACBC;
    }
    // 0x8000AC58: nop

    // 0x8000AC5C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000AC60: lw          $t0, -0x5B1C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5B1C);
    // 0x8000AC64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AC68: beq         $t0, $at, L_8000AC9C
    if (ctx->r8 == ctx->r1) {
        // 0x8000AC6C: nop

            goto L_8000AC9C;
    }
    // 0x8000AC6C: nop

    // 0x8000AC70: lw          $t1, 0x26C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AC74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000AC78: lw          $t9, 0x14($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X14);
    // 0x8000AC7C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8000AC80: jalr        $t9
    // 0x8000AC84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_43;
    // 0x8000AC84: nop

    after_43:
    // 0x8000AC88: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000AC8C: sw          $v0, -0x5B1C($at)
    MEM_W(-0X5B1C, ctx->r1) = ctx->r2;
    // 0x8000AC90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000AC94: b           L_8000ACB4
    // 0x8000AC98: sw          $t2, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r10;
        goto L_8000ACB4;
    // 0x8000AC98: sw          $t2, 0x298($sp)
    MEM_W(0X298, ctx->r29) = ctx->r10;
L_8000AC9C:
    // 0x8000AC9C: lw          $t3, 0x26C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ACA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000ACA4: lw          $t9, 0x14($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X14);
    // 0x8000ACA8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8000ACAC: jalr        $t9
    // 0x8000ACB0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_44;
    // 0x8000ACB0: nop

    after_44:
L_8000ACB4:
    // 0x8000ACB4: b           L_8000ACD8
    // 0x8000ACB8: nop

        goto L_8000ACD8;
    // 0x8000ACB8: nop

L_8000ACBC:
    // 0x8000ACBC: lw          $t4, 0x26C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ACC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000ACC4: lw          $t9, 0x14($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X14);
    // 0x8000ACC8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8000ACCC: jalr        $t9
    // 0x8000ACD0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_45;
    // 0x8000ACD0: nop

    after_45:
    // 0x8000ACD4: sw          $zero, 0x28C($sp)
    MEM_W(0X28C, ctx->r29) = 0;
L_8000ACD8:
    // 0x8000ACD8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8000ACDC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000ACE0: b           L_8000AD38
    // 0x8000ACE4: sw          $t5, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r13;
        goto L_8000AD38;
    // 0x8000ACE4: sw          $t5, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r13;
L_8000ACE8:
    // 0x8000ACE8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8000ACEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000ACF0: sw          $t6, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->r14;
    // 0x8000ACF4: lw          $t7, 0x26C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X26C);
    // 0x8000ACF8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000ACFC: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    // 0x8000AD00: jal         0x8008ECE4
    // 0x8000AD04: addiu       $a0, $a0, -0x2D28
    ctx->r4 = ADD32(ctx->r4, -0X2D28);
    func_8008ECE4(rdram, ctx);
        goto after_46;
    // 0x8000AD04: addiu       $a0, $a0, -0x2D28
    ctx->r4 = ADD32(ctx->r4, -0X2D28);
    after_46:
    // 0x8000AD08: lw          $t8, 0x26C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AD0C: nop

    // 0x8000AD10: lw          $t0, 0x14($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X14);
    // 0x8000AD14: nop

    // 0x8000AD18: beq         $t0, $zero, L_8000AD38
    if (ctx->r8 == 0) {
        // 0x8000AD1C: nop

            goto L_8000AD38;
    }
    // 0x8000AD1C: nop

    // 0x8000AD20: lw          $t1, 0x26C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AD24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000AD28: lw          $t9, 0x14($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X14);
    // 0x8000AD2C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8000AD30: jalr        $t9
    // 0x8000AD34: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_47;
    // 0x8000AD34: nop

    after_47:
L_8000AD38:
    // 0x8000AD38: lw          $t2, 0x2A0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2A0);
    // 0x8000AD3C: nop

    // 0x8000AD40: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000AD44: b           L_8000AD60
    // 0x8000AD48: sw          $t3, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = ctx->r11;
        goto L_8000AD60;
    // 0x8000AD48: sw          $t3, 0x2A0($sp)
    MEM_W(0X2A0, ctx->r29) = ctx->r11;
L_8000AD4C:
    // 0x8000AD4C: lw          $t4, 0x26C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AD50: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000AD54: lw          $a1, 0x4($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X4);
    // 0x8000AD58: jal         0x8008ECE4
    // 0x8000AD5C: addiu       $a0, $a0, -0x2D24
    ctx->r4 = ADD32(ctx->r4, -0X2D24);
    func_8008ECE4(rdram, ctx);
        goto after_48;
    // 0x8000AD5C: addiu       $a0, $a0, -0x2D24
    ctx->r4 = ADD32(ctx->r4, -0X2D24);
    after_48:
L_8000AD60:
    // 0x8000AD60: lw          $t5, 0x2C4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C4);
    // 0x8000AD64: lw          $t7, 0x26C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X26C);
    // 0x8000AD68: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000AD6C: addiu       $t8, $t7, 0x28
    ctx->r24 = ADD32(ctx->r15, 0X28);
    // 0x8000AD70: sw          $t8, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r24;
    // 0x8000AD74: b           L_8000AB50
    // 0x8000AD78: sw          $t6, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->r14;
        goto L_8000AB50;
    // 0x8000AD78: sw          $t6, 0x2C4($sp)
    MEM_W(0X2C4, ctx->r29) = ctx->r14;
L_8000AD7C:
    // 0x8000AD7C: jal         0x8001ACDC
    // 0x8000AD80: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001ACDC(rdram, ctx);
        goto after_49;
    // 0x8000AD80: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_49:
    // 0x8000AD84: jal         0x8001ADBC
    // 0x8000AD88: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001ADBC(rdram, ctx);
        goto after_50;
    // 0x8000AD88: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_50:
    // 0x8000AD8C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8000AD90: lw          $t0, -0x5B1C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5B1C);
    // 0x8000AD94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000AD98: bne         $t0, $at, L_8000ADA4
    if (ctx->r8 != ctx->r1) {
        // 0x8000AD9C: nop

            goto L_8000ADA4;
    }
    // 0x8000AD9C: nop

    // 0x8000ADA0: sw          $zero, 0x2A4($sp)
    MEM_W(0X2A4, ctx->r29) = 0;
L_8000ADA4:
    // 0x8000ADA4: lw          $t1, 0x2A4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2A4);
    // 0x8000ADA8: nop

    // 0x8000ADAC: bne         $t1, $zero, L_8000AE60
    if (ctx->r9 != 0) {
        // 0x8000ADB0: nop

            goto L_8000AE60;
    }
    // 0x8000ADB0: nop

    // 0x8000ADB4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000ADB8: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8000ADBC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000ADC0: lhu         $t3, 0xE68($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0XE68);
    // 0x8000ADC4: lhu         $t2, 0x8($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X8);
    // 0x8000ADC8: nop

    // 0x8000ADCC: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8000ADD0: beq         $t4, $zero, L_8000ADE8
    if (ctx->r12 == 0) {
        // 0x8000ADD4: nop

            goto L_8000ADE8;
    }
    // 0x8000ADD4: nop

    // 0x8000ADD8: lw          $t5, 0x2BC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000ADDC: nop

    // 0x8000ADE0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8000ADE4: sw          $t6, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r14;
L_8000ADE8:
    // 0x8000ADE8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000ADEC: addiu       $t7, $t7, 0x60F0
    ctx->r15 = ADD32(ctx->r15, 0X60F0);
    // 0x8000ADF0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8000ADF4: lhu         $t0, 0xE74($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0XE74);
    // 0x8000ADF8: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8000ADFC: nop

    // 0x8000AE00: and         $t1, $t8, $t0
    ctx->r9 = ctx->r24 & ctx->r8;
    // 0x8000AE04: beq         $t1, $zero, L_8000AE1C
    if (ctx->r9 == 0) {
        // 0x8000AE08: nop

            goto L_8000AE1C;
    }
    // 0x8000AE08: nop

    // 0x8000AE0C: lw          $t9, 0x2BC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000AE10: nop

    // 0x8000AE14: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8000AE18: sw          $t2, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r10;
L_8000AE1C:
    // 0x8000AE1C: lw          $t3, 0x2BC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000AE20: nop

    // 0x8000AE24: bgez        $t3, L_8000AE30
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000AE28: nop

            goto L_8000AE30;
    }
    // 0x8000AE28: nop

    // 0x8000AE2C: sw          $zero, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = 0;
L_8000AE30:
    // 0x8000AE30: lw          $t4, 0x2BC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2BC);
    // 0x8000AE34: lw          $t5, 0x2B8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2B8);
    // 0x8000AE38: nop

    // 0x8000AE3C: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000AE40: bne         $at, $zero, L_8000AE58
    if (ctx->r1 != 0) {
        // 0x8000AE44: nop

            goto L_8000AE58;
    }
    // 0x8000AE44: nop

    // 0x8000AE48: lw          $t6, 0x2B8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2B8);
    // 0x8000AE4C: nop

    // 0x8000AE50: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000AE54: sw          $t7, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r15;
L_8000AE58:
    // 0x8000AE58: b           L_8000AF18
    // 0x8000AE5C: nop

        goto L_8000AF18;
    // 0x8000AE5C: nop

L_8000AE60:
    // 0x8000AE60: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000AE64: lw          $t8, -0x5B1C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B1C);
    // 0x8000AE68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000AE6C: beq         $t8, $at, L_8000AF18
    if (ctx->r24 == ctx->r1) {
        // 0x8000AE70: nop

            goto L_8000AF18;
    }
    // 0x8000AE70: nop

    // 0x8000AE74: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000AE78: addiu       $t0, $t0, 0x60F0
    ctx->r8 = ADD32(ctx->r8, 0X60F0);
    // 0x8000AE7C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8000AE80: lhu         $t9, 0xE68($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0XE68);
    // 0x8000AE84: lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X8);
    // 0x8000AE88: nop

    // 0x8000AE8C: and         $t2, $t1, $t9
    ctx->r10 = ctx->r9 & ctx->r25;
    // 0x8000AE90: beq         $t2, $zero, L_8000AEA8
    if (ctx->r10 == 0) {
        // 0x8000AE94: nop

            goto L_8000AEA8;
    }
    // 0x8000AE94: nop

    // 0x8000AE98: lw          $t3, 0x2AC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AE9C: nop

    // 0x8000AEA0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000AEA4: sw          $t4, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r12;
L_8000AEA8:
    // 0x8000AEA8: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000AEAC: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8000AEB0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000AEB4: lhu         $t7, 0xE74($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XE74);
    // 0x8000AEB8: lhu         $t6, 0x8($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X8);
    // 0x8000AEBC: nop

    // 0x8000AEC0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8000AEC4: beq         $t8, $zero, L_8000AEDC
    if (ctx->r24 == 0) {
        // 0x8000AEC8: nop

            goto L_8000AEDC;
    }
    // 0x8000AEC8: nop

    // 0x8000AECC: lw          $t0, 0x2AC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AED0: nop

    // 0x8000AED4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000AED8: sw          $t1, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r9;
L_8000AEDC:
    // 0x8000AEDC: lw          $t9, 0x2AC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AEE0: lw          $t2, 0x29C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X29C);
    // 0x8000AEE4: nop

    // 0x8000AEE8: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000AEEC: bne         $at, $zero, L_8000AF04
    if (ctx->r1 != 0) {
        // 0x8000AEF0: nop

            goto L_8000AF04;
    }
    // 0x8000AEF0: nop

    // 0x8000AEF4: lw          $t3, 0x29C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X29C);
    // 0x8000AEF8: nop

    // 0x8000AEFC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000AF00: sw          $t4, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r12;
L_8000AF04:
    // 0x8000AF04: lw          $t5, 0x2AC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2AC);
    // 0x8000AF08: nop

    // 0x8000AF0C: bgez        $t5, L_8000AF18
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8000AF10: nop

            goto L_8000AF18;
    }
    // 0x8000AF10: nop

    // 0x8000AF14: sw          $zero, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = 0;
L_8000AF18:
    // 0x8000AF18: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8000AF1C: sw          $t6, 0x29C($sp)
    MEM_W(0X29C, ctx->r29) = ctx->r14;
    // 0x8000AF20: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000AF24: addiu       $t7, $t7, -0x7278
    ctx->r15 = ADD32(ctx->r15, -0X7278);
    // 0x8000AF28: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000AF2C: nop

    // 0x8000AF30: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x8000AF34: sh          $t0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r8;
    // 0x8000AF38: jal         0x80002824
    // 0x8000AF3C: nop

    func_80002824(rdram, ctx);
        goto after_51;
    // 0x8000AF3C: nop

    after_51:
    // 0x8000AF40: jal         0x8001635C
    // 0x8000AF44: nop

    func_8001635C(rdram, ctx);
        goto after_52;
    // 0x8000AF44: nop

    after_52:
    // 0x8000AF48: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8000AF4C: addiu       $t1, $t1, -0x7278
    ctx->r9 = ADD32(ctx->r9, -0X7278);
    // 0x8000AF50: lhu         $t9, 0x0($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X0);
    // 0x8000AF54: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8000AF58: and         $t2, $t9, $at
    ctx->r10 = ctx->r25 & ctx->r1;
    // 0x8000AF5C: sh          $t2, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r10;
    // 0x8000AF60: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000AF64: jal         0x8009A664
    // 0x8000AF68: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    func_8009A664(rdram, ctx);
        goto after_53;
    // 0x8000AF68: addiu       $a0, $a0, 0x1B44
    ctx->r4 = ADD32(ctx->r4, 0X1B44);
    after_53:
    // 0x8000AF6C: b           L_8000B000
    // 0x8000AF70: nop

        goto L_8000B000;
    // 0x8000AF70: nop

L_8000AF74:
    // 0x8000AF74: lw          $t3, 0x2B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000AF78: nop

    // 0x8000AF7C: slti        $at, $t3, 0x15
    ctx->r1 = SIGNED(ctx->r11) < 0X15 ? 1 : 0;
    // 0x8000AF80: bne         $at, $zero, L_8000AFC4
    if (ctx->r1 != 0) {
        // 0x8000AF84: nop

            goto L_8000AFC4;
    }
    // 0x8000AF84: nop

    // 0x8000AF88: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000AF8C: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8000AF90: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000AF94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000AF98: beq         $t5, $at, L_8000AFC4
    if (ctx->r13 == ctx->r1) {
        // 0x8000AF9C: nop

            goto L_8000AFC4;
    }
    // 0x8000AF9C: nop

    // 0x8000AFA0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8000AFA4: lhu         $t8, 0x11A4($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X11A4);
    // 0x8000AFA8: lhu         $t6, 0x4($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X4);
    // 0x8000AFAC: nop

    // 0x8000AFB0: and         $t0, $t6, $t8
    ctx->r8 = ctx->r14 & ctx->r24;
    // 0x8000AFB4: beq         $t0, $zero, L_8000AFC4
    if (ctx->r8 == 0) {
        // 0x8000AFB8: nop

            goto L_8000AFC4;
    }
    // 0x8000AFB8: nop

    // 0x8000AFBC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000AFC0: sw          $t7, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = ctx->r15;
L_8000AFC4:
    // 0x8000AFC4: lw          $t9, 0x2B0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000AFC8: nop

    // 0x8000AFCC: bltz        $t9, L_8000AFE4
    if (SIGNED(ctx->r25) < 0) {
        // 0x8000AFD0: nop

            goto L_8000AFE4;
    }
    // 0x8000AFD0: nop

    // 0x8000AFD4: lw          $t2, 0x2B0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000AFD8: nop

    // 0x8000AFDC: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8000AFE0: sw          $t1, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = ctx->r9;
L_8000AFE4:
    // 0x8000AFE4: lw          $t3, 0x2B0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2B0);
    // 0x8000AFE8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8000AFEC: bne         $t3, $at, L_8000B000
    if (ctx->r11 != ctx->r1) {
        // 0x8000AFF0: nop

            goto L_8000B000;
    }
    // 0x8000AFF0: nop

    // 0x8000AFF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000AFF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000AFFC: sw          $t5, -0x5B20($at)
    MEM_W(-0X5B20, ctx->r1) = ctx->r13;
L_8000B000:
    // 0x8000B000: jal         0x800BE610
    // 0x8000B004: nop

    Main_GfxFullSync(rdram, ctx);
        goto after_54;
    // 0x8000B004: nop

    after_54:
    // 0x8000B008: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8000B00C: lw          $t4, 0x1B4C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1B4C);
    // 0x8000B010: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8000B014: lw          $t6, 0x1B44($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1B44);
    // 0x8000B018: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8000B01C: jal         0x8009908C
    // 0x8000B020: subu        $a1, $t6, $t4
    ctx->r5 = SUB32(ctx->r14, ctx->r12);
    CreateGfxTask(rdram, ctx);
        goto after_55;
    // 0x8000B020: subu        $a1, $t6, $t4
    ctx->r5 = SUB32(ctx->r14, ctx->r12);
    after_55:
    // 0x8000B024: lw          $t8, 0x284($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X284);
    // 0x8000B028: nop

    // 0x8000B02C: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8000B030: jal         0x80098D24
    // 0x8000B034: nop

    Update_ControllerRaw(rdram, ctx);
        goto after_56;
    // 0x8000B034: nop

    after_56:
    // 0x8000B038: jal         0x80099450
    // 0x8000B03C: nop

    func_80099450(rdram, ctx);
        goto after_57;
    // 0x8000B03C: nop

    after_57:
    // 0x8000B040: lw          $t0, 0x280($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X280);
    // 0x8000B044: nop

    // 0x8000B048: addiu       $t7, $t0, 0x7FFF
    ctx->r15 = ADD32(ctx->r8, 0X7FFF);
    // 0x8000B04C: lw          $t7, 0x2ED($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2ED);
    // 0x8000B050: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x8000B054: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000B058: sw          $t9, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r25;
L_8000B05C:
    // 0x8000B05C: b           L_8000B0B0
    // 0x8000B060: nop

        goto L_8000B0B0;
    // 0x8000B060: nop

L_8000B064:
    // 0x8000B064: jal         0x80099520
    // 0x8000B068: nop

    func_80099520(rdram, ctx);
        goto after_58;
    // 0x8000B068: nop

    after_58:
    // 0x8000B06C: lw          $t2, 0x280($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X280);
    // 0x8000B070: nop

    // 0x8000B074: addiu       $t1, $t2, 0x7FFF
    ctx->r9 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000B078: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x8000B07C: addiu       $at, $t2, 0x7FFF
    ctx->r1 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000B080: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8000B084: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x8000B088: b           L_8000B0B0
    // 0x8000B08C: nop

        goto L_8000B0B0;
    // 0x8000B08C: nop

L_8000B090:
    // 0x8000B090: jal         0x800029BC
    // 0x8000B094: nop

    func_800029BC(rdram, ctx);
        goto after_59;
    // 0x8000B094: nop

    after_59:
L_8000B098:
    // 0x8000B098: b           L_8000B098
    pause_self(rdram);
    // 0x8000B09C: nop

    // 0x8000B0A0: b           L_8000B0B0
    // 0x8000B0A4: nop

        goto L_8000B0B0;
    // 0x8000B0A4: nop

L_8000B0A8:
    // 0x8000B0A8: b           L_8000B0B0
    // 0x8000B0AC: nop

        goto L_8000B0B0;
    // 0x8000B0AC: nop

L_8000B0B0:
    // 0x8000B0B0: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8000B0B4: lw          $t5, -0x5B20($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B20);
    // 0x8000B0B8: nop

    // 0x8000B0BC: beq         $t5, $zero, L_8000A4BC
    if (ctx->r13 == 0) {
        // 0x8000B0C0: nop

            goto L_8000A4BC;
    }
    // 0x8000B0C0: nop

L_8000B0C4:
    // 0x8000B0C4: lw          $t6, 0x280($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X280);
    // 0x8000B0C8: nop

    // 0x8000B0CC: addiu       $t4, $t6, 0x7FFF
    ctx->r12 = ADD32(ctx->r14, 0X7FFF);
    // 0x8000B0D0: lw          $t4, 0x2ED($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2ED);
    // 0x8000B0D4: nop

    // 0x8000B0D8: blez        $t4, L_8000B15C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000B0DC: nop

            goto L_8000B15C;
    }
    // 0x8000B0DC: nop

L_8000B0E0:
    // 0x8000B0E0: lw          $t8, 0x284($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X284);
    // 0x8000B0E4: addiu       $a1, $sp, 0x27C
    ctx->r5 = ADD32(ctx->r29, 0X27C);
    // 0x8000B0E8: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8000B0EC: jal         0x800C143C
    // 0x8000B0F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Thread_ReceiveMsgInThread(rdram, ctx);
        goto after_60;
    // 0x8000B0F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_60:
    // 0x8000B0F4: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8000B0F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B0FC: lh          $t9, 0x0($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X0);
    // 0x8000B100: nop

    // 0x8000B104: bne         $t9, $at, L_8000B140
    if (ctx->r25 != ctx->r1) {
        // 0x8000B108: nop

            goto L_8000B140;
    }
    // 0x8000B108: nop

    // 0x8000B10C: b           L_8000B114
    // 0x8000B110: nop

        goto L_8000B114;
    // 0x8000B110: nop

L_8000B114:
    // 0x8000B114: jal         0x80099520
    // 0x8000B118: nop

    func_80099520(rdram, ctx);
        goto after_61;
    // 0x8000B118: nop

    after_61:
    // 0x8000B11C: lw          $t0, 0x280($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X280);
    // 0x8000B120: nop

    // 0x8000B124: addiu       $t1, $t0, 0x7FFF
    ctx->r9 = ADD32(ctx->r8, 0X7FFF);
    // 0x8000B128: lw          $t1, 0x2ED($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2ED);
    // 0x8000B12C: addiu       $at, $t0, 0x7FFF
    ctx->r1 = ADD32(ctx->r8, 0X7FFF);
    // 0x8000B130: addiu       $t3, $t1, -0x1
    ctx->r11 = ADD32(ctx->r9, -0X1);
    // 0x8000B134: sw          $t3, 0x2ED($at)
    MEM_W(0X2ED, ctx->r1) = ctx->r11;
    // 0x8000B138: b           L_8000B140
    // 0x8000B13C: nop

        goto L_8000B140;
    // 0x8000B13C: nop

L_8000B140:
    // 0x8000B140: lw          $t2, 0x280($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X280);
    // 0x8000B144: nop

    // 0x8000B148: addiu       $t5, $t2, 0x7FFF
    ctx->r13 = ADD32(ctx->r10, 0X7FFF);
    // 0x8000B14C: lw          $t5, 0x2ED($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2ED);
    // 0x8000B150: nop

    // 0x8000B154: bgtz        $t5, L_8000B0E0
    if (SIGNED(ctx->r13) > 0) {
        // 0x8000B158: nop

            goto L_8000B0E0;
    }
    // 0x8000B158: nop

L_8000B15C:
    // 0x8000B15C: jal         0x80098820
    // 0x8000B160: nop

    func_80098820(rdram, ctx);
        goto after_62;
    // 0x8000B160: nop

    after_62:
    // 0x8000B164: jal         0x80098868
    // 0x8000B168: nop

    func_80098868(rdram, ctx);
        goto after_63;
    // 0x8000B168: nop

    after_63:
    // 0x8000B16C: jal         0x8001AE90
    // 0x8000B170: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001AE90(rdram, ctx);
        goto after_64;
    // 0x8000B170: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_64:
    // 0x8000B174: b           L_8000B184
    // 0x8000B178: nop

        goto L_8000B184;
    // 0x8000B178: nop

    // 0x8000B17C: b           L_8000B184
    // 0x8000B180: nop

        goto L_8000B184;
    // 0x8000B180: nop

L_8000B184:
    // 0x8000B184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000B18C: jr          $ra
    // 0x8000B190: addiu       $sp, $sp, 0x2C8
    ctx->r29 = ADD32(ctx->r29, 0X2C8);
    return;
    // 0x8000B190: addiu       $sp, $sp, 0x2C8
    ctx->r29 = ADD32(ctx->r29, 0X2C8);
;}
RECOMP_FUNC void func_8000B194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B19C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000B1A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000B1A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B1A8: nop

    // 0x8000B1AC: bltz        $t6, L_8000B240
    if (SIGNED(ctx->r14) < 0) {
        // 0x8000B1B0: nop

            goto L_8000B240;
    }
    // 0x8000B1B0: nop

    // 0x8000B1B4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000B1B8: lw          $t7, 0x129C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X129C);
    // 0x8000B1BC: nop

    // 0x8000B1C0: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8000B1C4: bne         $t8, $zero, L_8000B1D4
    if (ctx->r24 != 0) {
        // 0x8000B1C8: nop

            goto L_8000B1D4;
    }
    // 0x8000B1C8: nop

    // 0x8000B1CC: b           L_8000B250
    // 0x8000B1D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000B250;
    // 0x8000B1D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000B1D4:
    // 0x8000B1D4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8000B1D8: lbu         $t9, 0x127C($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X127C);
    // 0x8000B1DC: nop

    // 0x8000B1E0: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8000B1E4: bne         $t0, $zero, L_8000B1F4
    if (ctx->r8 != 0) {
        // 0x8000B1E8: nop

            goto L_8000B1F4;
    }
    // 0x8000B1E8: nop

    // 0x8000B1EC: b           L_8000B250
    // 0x8000B1F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000B250;
    // 0x8000B1F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000B1F4:
    // 0x8000B1F4: jal         0x800AE580
    // 0x8000B1F8: nop

    ContPak_GetAvailableSlots(rdram, ctx);
        goto after_0;
    // 0x8000B1F8: nop

    after_0:
    // 0x8000B1FC: bne         $v0, $zero, L_8000B20C
    if (ctx->r2 != 0) {
        // 0x8000B200: nop

            goto L_8000B20C;
    }
    // 0x8000B200: nop

    // 0x8000B204: b           L_8000B250
    // 0x8000B208: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000B250;
    // 0x8000B208: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000B20C:
    // 0x8000B20C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8000B210: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8000B214: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000B218: lhu         $t2, 0xFF4($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0XFF4);
    // 0x8000B21C: lhu         $t1, 0x10F2($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X10F2);
    // 0x8000B220: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8000B224: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8000B228: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8000B22C: and         $t6, $t5, $t3
    ctx->r14 = ctx->r13 & ctx->r11;
    // 0x8000B230: beq         $t6, $zero, L_8000B240
    if (ctx->r14 == 0) {
        // 0x8000B234: nop

            goto L_8000B240;
    }
    // 0x8000B234: nop

    // 0x8000B238: b           L_8000B250
    // 0x8000B23C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000B250;
    // 0x8000B23C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000B240:
    // 0x8000B240: b           L_8000B250
    // 0x8000B244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B250;
    // 0x8000B244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000B248: b           L_8000B250
    // 0x8000B24C: nop

        goto L_8000B250;
    // 0x8000B24C: nop

L_8000B250:
    // 0x8000B250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B258: jr          $ra
    // 0x8000B25C: nop

    return;
    // 0x8000B25C: nop

;}
RECOMP_FUNC void func_8000B260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B268: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000B26C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000B270: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8000B274: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x8000B278: nop

    // 0x8000B27C: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8000B280: beq         $t7, $zero, L_8000B2B0
    if (ctx->r15 == 0) {
        // 0x8000B284: nop

            goto L_8000B2B0;
    }
    // 0x8000B284: nop

    // 0x8000B288: andi        $t8, $t6, 0x4
    ctx->r24 = ctx->r14 & 0X4;
    // 0x8000B28C: beq         $t8, $zero, L_8000B2B0
    if (ctx->r24 == 0) {
        // 0x8000B290: nop

            goto L_8000B2B0;
    }
    // 0x8000B290: nop

    // 0x8000B294: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B298: lw          $a1, 0x1638($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1638);
    // 0x8000B29C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000B2A0: jal         0x8008ECE4
    // 0x8000B2A4: addiu       $a0, $a0, -0x2D20
    ctx->r4 = ADD32(ctx->r4, -0X2D20);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8000B2A4: addiu       $a0, $a0, -0x2D20
    ctx->r4 = ADD32(ctx->r4, -0X2D20);
    after_0:
    // 0x8000B2A8: b           L_8000B2BC
    // 0x8000B2AC: nop

        goto L_8000B2BC;
    // 0x8000B2AC: nop

L_8000B2B0:
    // 0x8000B2B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000B2B4: jal         0x8008ECE4
    // 0x8000B2B8: addiu       $a0, $a0, -0x2D08
    ctx->r4 = ADD32(ctx->r4, -0X2D08);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8000B2B8: addiu       $a0, $a0, -0x2D08
    ctx->r4 = ADD32(ctx->r4, -0X2D08);
    after_1:
L_8000B2BC:
    // 0x8000B2BC: b           L_8000B2CC
    // 0x8000B2C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B2CC;
    // 0x8000B2C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000B2C4: b           L_8000B2CC
    // 0x8000B2C8: nop

        goto L_8000B2CC;
    // 0x8000B2C8: nop

L_8000B2CC:
    // 0x8000B2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B2D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B2D4: jr          $ra
    // 0x8000B2D8: nop

    return;
    // 0x8000B2D8: nop

;}
RECOMP_FUNC void func_8000B2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B2DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000B2E0: bltz        $a1, L_8000B328
    if (SIGNED(ctx->r5) < 0) {
        // 0x8000B2E4: nop

            goto L_8000B328;
    }
    // 0x8000B2E4: nop

    // 0x8000B2E8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8000B2EC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000B2F0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000B2F4: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x8000B2F8: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8000B2FC: addiu       $t9, $t9, 0x60F0
    ctx->r25 = ADD32(ctx->r25, 0X60F0);
    // 0x8000B300: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x8000B304: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000B308: and         $t1, $t0, $t8
    ctx->r9 = ctx->r8 & ctx->r24;
    // 0x8000B30C: beq         $t1, $zero, L_8000B328
    if (ctx->r9 == 0) {
        // 0x8000B310: nop

            goto L_8000B328;
    }
    // 0x8000B310: nop

    // 0x8000B314: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000B318: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000B31C: sw          $t2, -0x5B20($at)
    MEM_W(-0X5B20, ctx->r1) = ctx->r10;
    // 0x8000B320: b           L_8000B338
    // 0x8000B324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000B338;
    // 0x8000B324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000B328:
    // 0x8000B328: b           L_8000B338
    // 0x8000B32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B338;
    // 0x8000B32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000B330: b           L_8000B338
    // 0x8000B334: nop

        goto L_8000B338;
    // 0x8000B334: nop

L_8000B338:
    // 0x8000B338: jr          $ra
    // 0x8000B33C: nop

    return;
    // 0x8000B33C: nop

;}
RECOMP_FUNC void func_8000B340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B340: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000B344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B348: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8000B34C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8000B350: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8000B354: nop

    // 0x8000B358: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000B35C: nop

    // 0x8000B360: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8000B364: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8000B368: lw          $t8, 0x129C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X129C);
    // 0x8000B36C: nop

    // 0x8000B370: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8000B374: beq         $t9, $zero, L_8000B638
    if (ctx->r25 == 0) {
        // 0x8000B378: nop

            goto L_8000B638;
    }
    // 0x8000B378: nop

    // 0x8000B37C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8000B380: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8000B384: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000B388: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8000B38C: lw          $t2, 0x15D8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X15D8);
    // 0x8000B390: nop

    // 0x8000B394: bne         $t2, $zero, L_8000B638
    if (ctx->r10 != 0) {
        // 0x8000B398: nop

            goto L_8000B638;
    }
    // 0x8000B398: nop

    // 0x8000B39C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8000B3A0: addiu       $t3, $sp, 0x18
    ctx->r11 = ADD32(ctx->r29, 0X18);
    // 0x8000B3A4: sb          $zero, 0x0($t3)
    MEM_B(0X0, ctx->r11) = 0;
    // 0x8000B3A8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8000B3AC: nop

    // 0x8000B3B0: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8000B3B4: beq         $at, $zero, L_8000B460
    if (ctx->r1 == 0) {
        // 0x8000B3B8: nop

            goto L_8000B460;
    }
    // 0x8000B3B8: nop

L_8000B3BC:
    // 0x8000B3BC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8000B3C0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8000B3C4: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8000B3C8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8000B3CC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000B3D0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8000B3D4: lbu         $t9, 0x13DE($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X13DE);
    // 0x8000B3D8: nop

    // 0x8000B3DC: bne         $t9, $zero, L_8000B3EC
    if (ctx->r25 != 0) {
        // 0x8000B3E0: sb          $t9, 0x3F($sp)
        MEM_B(0X3F, ctx->r29) = ctx->r25;
            goto L_8000B3EC;
    }
    // 0x8000B3E0: sb          $t9, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r25;
    // 0x8000B3E4: b           L_8000B460
    // 0x8000B3E8: nop

        goto L_8000B460;
    // 0x8000B3E8: nop

L_8000B3EC:
    // 0x8000B3EC: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B3F0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8000B3F4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8000B3F8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8000B3FC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8000B400: lbu         $t2, -0x5BF0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X5BF0);
    // 0x8000B404: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8000B408: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x8000B40C: sb          $t2, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r10;
    // 0x8000B410: lbu         $t6, 0x3F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B414: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8000B418: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000B41C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000B420: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000B424: lbu         $t8, -0x5BEF($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X5BEF);
    // 0x8000B428: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8000B42C: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x8000B430: sb          $t8, 0x19($t1)
    MEM_B(0X19, ctx->r9) = ctx->r24;
    // 0x8000B434: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8000B438: nop

    // 0x8000B43C: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x8000B440: addu        $t4, $sp, $t2
    ctx->r12 = ADD32(ctx->r29, ctx->r10);
    // 0x8000B444: sb          $zero, 0x1A($t4)
    MEM_B(0X1A, ctx->r12) = 0;
    // 0x8000B448: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8000B44C: nop

    // 0x8000B450: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000B454: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8000B458: bne         $at, $zero, L_8000B3BC
    if (ctx->r1 != 0) {
        // 0x8000B45C: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8000B3BC;
    }
    // 0x8000B45C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_8000B460:
    // 0x8000B460: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8000B464: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8000B468: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x8000B46C: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8000B470: lbu         $t8, 0x13DA($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X13DA);
    // 0x8000B474: nop

    // 0x8000B478: beq         $t8, $zero, L_8000B57C
    if (ctx->r24 == 0) {
        // 0x8000B47C: nop

            goto L_8000B57C;
    }
    // 0x8000B47C: nop

    // 0x8000B480: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8000B484: sb          $t0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r8;
    // 0x8000B488: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B48C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8000B490: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8000B494: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x8000B498: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8000B49C: lbu         $t2, -0x5BF0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X5BF0);
    // 0x8000B4A0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8000B4A4: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8000B4A8: sb          $t2, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r10;
    // 0x8000B4AC: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B4B0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8000B4B4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000B4B8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8000B4BC: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8000B4C0: lbu         $t8, -0x5BEF($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X5BEF);
    // 0x8000B4C4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8000B4C8: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x8000B4CC: sb          $t8, 0x19($t3)
    MEM_B(0X19, ctx->r11) = ctx->r24;
    // 0x8000B4D0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8000B4D4: nop

    // 0x8000B4D8: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8000B4DC: addu        $t5, $sp, $t2
    ctx->r13 = ADD32(ctx->r29, ctx->r10);
    // 0x8000B4E0: sb          $zero, 0x1A($t5)
    MEM_B(0X1A, ctx->r13) = 0;
    // 0x8000B4E4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000B4E8: nop

    // 0x8000B4EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000B4F0: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8000B4F4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8000B4F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8000B4FC: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8000B500: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x8000B504: lbu         $t8, 0x13DA($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X13DA);
    // 0x8000B508: nop

    // 0x8000B50C: sb          $t8, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r24;
    // 0x8000B510: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B514: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000B518: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8000B51C: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x8000B520: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8000B524: lbu         $t4, -0x5BF0($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X5BF0);
    // 0x8000B528: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x8000B52C: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8000B530: sb          $t4, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r12;
    // 0x8000B534: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B538: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8000B53C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8000B540: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8000B544: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8000B548: lbu         $t0, -0x5BEF($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X5BEF);
    // 0x8000B54C: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8000B550: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x8000B554: sb          $t0, 0x19($t3)
    MEM_B(0X19, ctx->r11) = ctx->r8;
    // 0x8000B558: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000B55C: nop

    // 0x8000B560: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8000B564: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x8000B568: sb          $zero, 0x1A($t5)
    MEM_B(0X1A, ctx->r13) = 0;
    // 0x8000B56C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8000B570: nop

    // 0x8000B574: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000B578: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_8000B57C:
    // 0x8000B57C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8000B580: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8000B584: slti        $at, $t8, 0x10
    ctx->r1 = SIGNED(ctx->r24) < 0X10 ? 1 : 0;
    // 0x8000B588: beq         $at, $zero, L_8000B604
    if (ctx->r1 == 0) {
        // 0x8000B58C: sb          $t9, 0x3F($sp)
        MEM_B(0X3F, ctx->r29) = ctx->r25;
            goto L_8000B604;
    }
    // 0x8000B58C: sb          $t9, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r25;
L_8000B590:
    // 0x8000B590: lbu         $t0, 0x3F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B594: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000B598: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8000B59C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8000B5A0: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8000B5A4: lbu         $t3, -0x5BF0($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X5BF0);
    // 0x8000B5A8: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x8000B5AC: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x8000B5B0: sb          $t3, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r11;
    // 0x8000B5B4: lbu         $t6, 0x3F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3F);
    // 0x8000B5B8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8000B5BC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000B5C0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000B5C4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8000B5C8: lbu         $t9, -0x5BEF($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X5BEF);
    // 0x8000B5CC: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8000B5D0: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x8000B5D4: sb          $t9, 0x19($t1)
    MEM_B(0X19, ctx->r9) = ctx->r25;
    // 0x8000B5D8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8000B5DC: nop

    // 0x8000B5E0: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8000B5E4: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x8000B5E8: sb          $zero, 0x1A($t4)
    MEM_B(0X1A, ctx->r12) = 0;
    // 0x8000B5EC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8000B5F0: nop

    // 0x8000B5F4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000B5F8: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x8000B5FC: bne         $at, $zero, L_8000B590
    if (ctx->r1 != 0) {
        // 0x8000B600: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8000B590;
    }
    // 0x8000B600: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_8000B604:
    // 0x8000B604: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8000B608: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8000B60C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8000B610: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8000B614: lw          $a2, 0x13D0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X13D0);
    // 0x8000B618: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000B61C: srl         $t9, $a2, 8
    ctx->r25 = S32(U32(ctx->r6) >> 8);
    // 0x8000B620: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8000B624: addiu       $a0, $a0, -0x2CF0
    ctx->r4 = ADD32(ctx->r4, -0X2CF0);
    // 0x8000B628: jal         0x8008ECE4
    // 0x8000B62C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8008ECE4(rdram, ctx);
        goto after_0;
    // 0x8000B62C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8000B630: b           L_8000B644
    // 0x8000B634: nop

        goto L_8000B644;
    // 0x8000B634: nop

L_8000B638:
    // 0x8000B638: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8000B63C: jal         0x8008ECE4
    // 0x8000B640: addiu       $a0, $a0, -0x2CE8
    ctx->r4 = ADD32(ctx->r4, -0X2CE8);
    func_8008ECE4(rdram, ctx);
        goto after_1;
    // 0x8000B640: addiu       $a0, $a0, -0x2CE8
    ctx->r4 = ADD32(ctx->r4, -0X2CE8);
    after_1:
L_8000B644:
    // 0x8000B644: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8000B648: nop

    // 0x8000B64C: bltz        $t0, L_8000B774
    if (SIGNED(ctx->r8) < 0) {
        // 0x8000B650: nop

            goto L_8000B774;
    }
    // 0x8000B650: nop

    // 0x8000B654: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000B658: addiu       $t1, $t1, 0x60F0
    ctx->r9 = ADD32(ctx->r9, 0X60F0);
    // 0x8000B65C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000B660: lhu         $t3, 0x101C($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X101C);
    // 0x8000B664: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8000B668: nop

    // 0x8000B66C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8000B670: beq         $t4, $zero, L_8000B680
    if (ctx->r12 == 0) {
        // 0x8000B674: nop

            goto L_8000B680;
    }
    // 0x8000B674: nop

    // 0x8000B678: b           L_8000B784
    // 0x8000B67C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000B784;
    // 0x8000B67C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000B680:
    // 0x8000B680: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x8000B684: addiu       $t5, $t5, 0x60F0
    ctx->r13 = ADD32(ctx->r13, 0X60F0);
    // 0x8000B688: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8000B68C: lhu         $t7, 0xFF4($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0XFF4);
    // 0x8000B690: lhu         $t6, 0x6($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X6);
    // 0x8000B694: nop

    // 0x8000B698: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8000B69C: beq         $t8, $zero, L_8000B6E4
    if (ctx->r24 == 0) {
        // 0x8000B6A0: nop

            goto L_8000B6E4;
    }
    // 0x8000B6A0: nop

    // 0x8000B6A4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8000B6A8: lw          $t9, 0x129C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X129C);
    // 0x8000B6AC: nop

    // 0x8000B6B0: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8000B6B4: beq         $t0, $zero, L_8000B6E4
    if (ctx->r8 == 0) {
        // 0x8000B6B8: nop

            goto L_8000B6E4;
    }
    // 0x8000B6B8: nop

    // 0x8000B6BC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8000B6C0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8000B6C4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000B6C8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8000B6CC: lw          $t3, 0x15D8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X15D8);
    // 0x8000B6D0: nop

    // 0x8000B6D4: bne         $t3, $zero, L_8000B6E4
    if (ctx->r11 != 0) {
        // 0x8000B6D8: nop

            goto L_8000B6E4;
    }
    // 0x8000B6D8: nop

    // 0x8000B6DC: b           L_8000B784
    // 0x8000B6E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000B784;
    // 0x8000B6E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000B6E4:
    // 0x8000B6E4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8000B6E8: addiu       $t4, $t4, 0x60F0
    ctx->r12 = ADD32(ctx->r12, 0X60F0);
    // 0x8000B6EC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8000B6F0: lhu         $t6, 0x10F2($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X10F2);
    // 0x8000B6F4: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8000B6F8: nop

    // 0x8000B6FC: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8000B700: beq         $t7, $zero, L_8000B774
    if (ctx->r15 == 0) {
        // 0x8000B704: nop

            goto L_8000B774;
    }
    // 0x8000B704: nop

    // 0x8000B708: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8000B70C: lw          $t8, -0x5B18($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5B18);
    // 0x8000B710: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8000B714: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000B718: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8000B71C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8000B720: lw          $t0, -0x5750($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5750);
    // 0x8000B724: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000B728: bne         $t0, $t2, L_8000B744
    if (ctx->r8 != ctx->r10) {
        // 0x8000B72C: nop

            goto L_8000B744;
    }
    // 0x8000B72C: nop

    // 0x8000B730: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8000B734: lw          $t3, -0x5B18($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5B18);
    // 0x8000B738: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000B73C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000B740: sw          $t4, -0x5B18($at)
    MEM_W(-0X5B18, ctx->r1) = ctx->r12;
L_8000B744:
    // 0x8000B744: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8000B748: lw          $t5, -0x5B18($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B18);
    // 0x8000B74C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8000B750: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8000B754: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000B758: lw          $t7, -0x5750($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5750);
    // 0x8000B75C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B760: bne         $t7, $at, L_8000B774
    if (ctx->r15 != ctx->r1) {
        // 0x8000B764: nop

            goto L_8000B774;
    }
    // 0x8000B764: nop

    // 0x8000B768: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000B76C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8000B770: sw          $t8, -0x5B14($at)
    MEM_W(-0X5B14, ctx->r1) = ctx->r24;
L_8000B774:
    // 0x8000B774: b           L_8000B784
    // 0x8000B778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B784;
    // 0x8000B778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000B77C: b           L_8000B784
    // 0x8000B780: nop

        goto L_8000B784;
    // 0x8000B780: nop

L_8000B784:
    // 0x8000B784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B788: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000B78C: jr          $ra
    // 0x8000B790: nop

    return;
    // 0x8000B790: nop

    // 0x8000B794: nop

    // 0x8000B798: nop

    // 0x8000B79C: nop

;}
RECOMP_FUNC void func_8000B7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B7A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000B7A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000B7A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000B7AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000B7B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000B7B4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000B7B8: lw          $t7, 0x1A0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A0);
    // 0x8000B7BC: nop

    // 0x8000B7C0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8000B7C4: sw          $t8, 0x1A0($t6)
    MEM_W(0X1A0, ctx->r14) = ctx->r24;
    // 0x8000B7C8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8000B7CC: nop

    // 0x8000B7D0: lw          $a0, 0x1A4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1A4);
    // 0x8000B7D4: jal         0x800045AC
    // 0x8000B7D8: nop

    func_800045AC(rdram, ctx);
        goto after_0;
    // 0x8000B7D8: nop

    after_0:
    // 0x8000B7DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8000B7E0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B7E4: nop

    // 0x8000B7E8: beq         $t0, $zero, L_8000B7FC
    if (ctx->r8 == 0) {
        // 0x8000B7EC: nop

            goto L_8000B7FC;
    }
    // 0x8000B7EC: nop

    // 0x8000B7F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B7F4: b           L_8000B820
    // 0x8000B7F8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
        goto L_8000B820;
    // 0x8000B7F8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_8000B7FC:
    // 0x8000B7FC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000B800: nop

    // 0x8000B804: lw          $t3, 0x1A0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1A0);
    // 0x8000B808: nop

    // 0x8000B80C: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x8000B810: sw          $t4, 0x1A0($t2)
    MEM_W(0X1A0, ctx->r10) = ctx->r12;
    // 0x8000B814: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8000B818: nop

    // 0x8000B81C: sw          $zero, 0x1A8($t5)
    MEM_W(0X1A8, ctx->r13) = 0;
L_8000B820:
    // 0x8000B820: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8000B824: lh          $t7, -0x73C0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X73C0);
    // 0x8000B828: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000B82C: bne         $t7, $at, L_8000B83C
    if (ctx->r15 != ctx->r1) {
        // 0x8000B830: nop

            goto L_8000B83C;
    }
    // 0x8000B830: nop

    // 0x8000B834: b           L_8000BAF0
    // 0x8000B838: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000BAF0;
    // 0x8000B838: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000B83C:
    // 0x8000B83C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8000B840: lw          $t8, -0x2828($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2828);
    // 0x8000B844: nop

    // 0x8000B848: bne         $t8, $zero, L_8000B994
    if (ctx->r24 != 0) {
        // 0x8000B84C: nop

            goto L_8000B994;
    }
    // 0x8000B84C: nop

    // 0x8000B850: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8000B854: jal         0x800BC918
    // 0x8000B858: ori         $a0, $a0, 0x5000
    ctx->r4 = ctx->r4 | 0X5000;
    SysMem_HeapAllocMark(rdram, ctx);
        goto after_1;
    // 0x8000B858: ori         $a0, $a0, 0x5000
    ctx->r4 = ctx->r4 | 0X5000;
    after_1:
    // 0x8000B85C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000B860: sw          $v0, -0x2828($at)
    MEM_W(-0X2828, ctx->r1) = ctx->r2;
    // 0x8000B864: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B868: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
    // 0x8000B86C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B870: sw          $zero, 0x3070($at)
    MEM_W(0X3070, ctx->r1) = 0;
    // 0x8000B874: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B878: sw          $zero, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = 0;
    // 0x8000B87C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B880: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B884: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000B888: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000B88C: lui         $a2, 0x80B3
    ctx->r6 = S32(0X80B3 << 16);
    // 0x8000B890: jal         0x800BD1FC
    // 0x8000B894: addiu       $a2, $a2, 0x2210
    ctx->r6 = ADD32(ctx->r6, 0X2210);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_2;
    // 0x8000B894: addiu       $a2, $a2, 0x2210
    ctx->r6 = ADD32(ctx->r6, 0X2210);
    after_2:
    // 0x8000B898: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B89C: jal         0x800BED70
    // 0x8000B8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Spi_GetHeader(rdram, ctx);
        goto after_3;
    // 0x8000B8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000B8A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8000B8A8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000B8AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B8B0: beq         $t6, $at, L_8000B904
    if (ctx->r14 == ctx->r1) {
        // 0x8000B8B4: nop

            goto L_8000B904;
    }
    // 0x8000B8B4: nop

    // 0x8000B8B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000B8BC: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x8000B8C0: jal         0x800BC918
    // 0x8000B8C4: nop

    SysMem_HeapAllocMark(rdram, ctx);
        goto after_4;
    // 0x8000B8C4: nop

    after_4:
    // 0x8000B8C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B8CC: sw          $v0, 0x3070($at)
    MEM_W(0X3070, ctx->r1) = ctx->r2;
    // 0x8000B8D0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B8D4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B8D8: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000B8DC: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000B8E0: lui         $a2, 0x80B3
    ctx->r6 = S32(0X80B3 << 16);
    // 0x8000B8E4: jal         0x800BD1FC
    // 0x8000B8E8: addiu       $a2, $a2, 0x2210
    ctx->r6 = ADD32(ctx->r6, 0X2210);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_5;
    // 0x8000B8E8: addiu       $a2, $a2, 0x2210
    ctx->r6 = ADD32(ctx->r6, 0X2210);
    after_5:
    // 0x8000B8EC: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8000B8F0: lw          $a2, 0x3070($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3070);
    // 0x8000B8F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B8F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8000B8FC: jal         0x800BF0B4
    // 0x8000B900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Spi_DecompressAsset(rdram, ctx);
        goto after_6;
    // 0x8000B900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_8000B904:
    // 0x8000B904: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B908: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B90C: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000B910: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000B914: lui         $a2, 0x80B0
    ctx->r6 = S32(0X80B0 << 16);
    // 0x8000B918: jal         0x800BD1FC
    // 0x8000B91C: addiu       $a2, $a2, 0x4E40
    ctx->r6 = ADD32(ctx->r6, 0X4E40);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_7;
    // 0x8000B91C: addiu       $a2, $a2, 0x4E40
    ctx->r6 = ADD32(ctx->r6, 0X4E40);
    after_7:
    // 0x8000B920: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B924: jal         0x800BED70
    // 0x8000B928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Spi_GetHeader(rdram, ctx);
        goto after_8;
    // 0x8000B928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8000B92C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8000B930: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8000B934: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B938: beq         $t9, $at, L_8000B98C
    if (ctx->r25 == ctx->r1) {
        // 0x8000B93C: nop

            goto L_8000B98C;
    }
    // 0x8000B93C: nop

    // 0x8000B940: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000B944: lw          $a0, 0x494($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X494);
    // 0x8000B948: jal         0x800BC918
    // 0x8000B94C: nop

    SysMem_HeapAllocMark(rdram, ctx);
        goto after_9;
    // 0x8000B94C: nop

    after_9:
    // 0x8000B950: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B954: sw          $v0, 0x3078($at)
    MEM_W(0X3078, ctx->r1) = ctx->r2;
    // 0x8000B958: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8000B95C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8000B960: lw          $a1, 0x49C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X49C0);
    // 0x8000B964: lw          $a0, 0x29B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X29B8);
    // 0x8000B968: lui         $a2, 0x80B0
    ctx->r6 = S32(0X80B0 << 16);
    // 0x8000B96C: jal         0x800BD1FC
    // 0x8000B970: addiu       $a2, $a2, 0x4E40
    ctx->r6 = ADD32(ctx->r6, 0X4E40);
    SysMem_GetPhysicalAddressFromVirtual(rdram, ctx);
        goto after_10;
    // 0x8000B970: addiu       $a2, $a2, 0x4E40
    ctx->r6 = ADD32(ctx->r6, 0X4E40);
    after_10:
    // 0x8000B974: lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // 0x8000B978: lw          $a2, 0x3078($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3078);
    // 0x8000B97C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B980: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8000B984: jal         0x800BF0B4
    // 0x8000B988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Spi_DecompressAsset(rdram, ctx);
        goto after_11;
    // 0x8000B988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_8000B98C:
    // 0x8000B98C: b           L_8000BA08
    // 0x8000B990: nop

        goto L_8000BA08;
    // 0x8000B990: nop

L_8000B994:
    // 0x8000B994: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000B998: nop

    // 0x8000B99C: lw          $t1, 0x20C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20C);
    // 0x8000B9A0: nop

    // 0x8000B9A4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8000B9A8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8000B9AC: nop

    // 0x8000B9B0: beq         $t3, $zero, L_8000BA08
    if (ctx->r11 == 0) {
        // 0x8000B9B4: nop

            goto L_8000BA08;
    }
    // 0x8000B9B4: nop

    // 0x8000B9B8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8000B9BC: nop

    // 0x8000B9C0: beq         $t4, $zero, L_8000BA08
    if (ctx->r12 == 0) {
        // 0x8000B9C4: nop

            goto L_8000BA08;
    }
    // 0x8000B9C4: nop

    // 0x8000B9C8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000B9CC: lw          $a0, 0x3068($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3068);
    // 0x8000B9D0: jal         0x8000D390
    // 0x8000B9D4: nop

    TempHeap_Free(rdram, ctx);
        goto after_12;
    // 0x8000B9D4: nop

    after_12:
    // 0x8000B9D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000B9DC: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
    // 0x8000B9E0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000B9E4: nop

    // 0x8000B9E8: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8000B9EC: nop

    // 0x8000B9F0: sw          $zero, 0x1A8($t5)
    MEM_W(0X1A8, ctx->r13) = 0;
    // 0x8000B9F4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000B9F8: nop

    // 0x8000B9FC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000BA00: nop

    // 0x8000BA04: sw          $zero, 0x1A0($t8)
    MEM_W(0X1A0, ctx->r24) = 0;
L_8000BA08:
    // 0x8000BA08: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8000BA0C: lw          $a0, -0x2828($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2828);
    // 0x8000BA10: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8000BA14: jal         0x8000D0E0
    // 0x8000BA18: ori         $a1, $a1, 0x5000
    ctx->r5 = ctx->r5 | 0X5000;
    TempHeap_Init(rdram, ctx);
        goto after_13;
    // 0x8000BA18: ori         $a1, $a1, 0x5000
    ctx->r5 = ctx->r5 | 0X5000;
    after_13:
    // 0x8000BA1C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8000BA20:
    // 0x8000BA20: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8000BA24: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000BA28: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8000BA2C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8000BA30: sw          $zero, -0x7E8($at)
    MEM_W(-0X7E8, ctx->r1) = 0;
    // 0x8000BA34: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8000BA38: nop

    // 0x8000BA3C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000BA40: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x8000BA44: bne         $at, $zero, L_8000BA20
    if (ctx->r1 != 0) {
        // 0x8000BA48: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_8000BA20;
    }
    // 0x8000BA48: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8000BA4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8000BA50: sw          $zero, -0x7FC($at)
    MEM_W(-0X7FC, ctx->r1) = 0;
    // 0x8000BA54: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8000BA58: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8000BA5C: sw          $t3, 0x1A0($t4)
    MEM_W(0X1A0, ctx->r12) = ctx->r11;
    // 0x8000BA60: jal         0x8000D164
    // 0x8000BA64: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    TempHeap_Alloc(rdram, ctx);
        goto after_14;
    // 0x8000BA64: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_14:
    // 0x8000BA68: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000BA6C: nop

    // 0x8000BA70: sw          $v0, 0x20C($t2)
    MEM_W(0X20C, ctx->r10) = ctx->r2;
    // 0x8000BA74: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8000BA78: nop

    // 0x8000BA7C: lw          $t7, 0x20C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X20C);
    // 0x8000BA80: nop

    // 0x8000BA84: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8000BA88: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8000BA8C: nop

    // 0x8000BA90: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8000BA94: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000BA98: nop

    // 0x8000BA9C: sh          $zero, 0x14($t6)
    MEM_H(0X14, ctx->r14) = 0;
    // 0x8000BAA0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000BAA4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000BAA8: sh          $t9, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r25;
    // 0x8000BAAC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8000BAB0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8000BAB4: sh          $t1, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = ctx->r9;
    // 0x8000BAB8: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8000BABC: addiu       $t4, $t4, -0x7278
    ctx->r12 = ADD32(ctx->r12, -0X7278);
    // 0x8000BAC0: lhu         $t2, 0x0($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X0);
    // 0x8000BAC4: nop

    // 0x8000BAC8: ori         $t5, $t2, 0x200
    ctx->r13 = ctx->r10 | 0X200;
    // 0x8000BACC: sh          $t5, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r13;
    // 0x8000BAD0: jal         0x8005F268
    // 0x8000BAD4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_8005F268(rdram, ctx);
        goto after_15;
    // 0x8000BAD4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_15:
    // 0x8000BAD8: jal         0x80059D48
    // 0x8000BADC: nop

    func_80059D48(rdram, ctx);
        goto after_16;
    // 0x8000BADC: nop

    after_16:
    // 0x8000BAE0: b           L_8000BAF0
    // 0x8000BAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000BAF0;
    // 0x8000BAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000BAE8: b           L_8000BAF0
    // 0x8000BAEC: nop

        goto L_8000BAF0;
    // 0x8000BAEC: nop

L_8000BAF0:
    // 0x8000BAF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BAF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000BAF8: jr          $ra
    // 0x8000BAFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000BAFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000BB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BB00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BB04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BB08: jal         0x800045AC
    // 0x8000BB0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800045AC(rdram, ctx);
        goto after_0;
    // 0x8000BB0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8000BB10: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000BB14: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BB18: nop

    // 0x8000BB1C: bne         $t6, $zero, L_8000BB2C
    if (ctx->r14 != 0) {
        // 0x8000BB20: nop

            goto L_8000BB2C;
    }
    // 0x8000BB20: nop

    // 0x8000BB24: b           L_8000BC6C
    // 0x8000BB28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000BC6C;
    // 0x8000BB28: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000BB2C:
    // 0x8000BB2C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BB30: nop

    // 0x8000BB34: lw          $t8, 0x1A8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1A8);
    // 0x8000BB38: nop

    // 0x8000BB3C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000BB40: beq         $t9, $zero, L_8000BB50
    if (ctx->r25 == 0) {
        // 0x8000BB44: nop

            goto L_8000BB50;
    }
    // 0x8000BB44: nop

    // 0x8000BB48: jal         0x800B81B4
    // 0x8000BB4C: nop

    func_800B81B4(rdram, ctx);
        goto after_1;
    // 0x8000BB4C: nop

    after_1:
L_8000BB50:
    // 0x8000BB50: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BB54: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8000BB58: lw          $t1, 0x1A8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1A8);
    // 0x8000BB5C: nop

    // 0x8000BB60: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8000BB64: sw          $t2, 0x1A8($t0)
    MEM_W(0X1A8, ctx->r8) = ctx->r10;
    // 0x8000BB68: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BB6C: nop

    // 0x8000BB70: lw          $t4, 0x20C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20C);
    // 0x8000BB74: nop

    // 0x8000BB78: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8000BB7C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8000BB80: nop

    // 0x8000BB84: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8000BB88: nop

    // 0x8000BB8C: bne         $t6, $zero, L_8000BBDC
    if (ctx->r14 != 0) {
        // 0x8000BB90: nop

            goto L_8000BBDC;
    }
    // 0x8000BB90: nop

    // 0x8000BB94: jal         0x80004654
    // 0x8000BB98: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80004654(rdram, ctx);
        goto after_2;
    // 0x8000BB98: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8000BB9C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000BBA0: lw          $t7, 0x6C10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C10);
    // 0x8000BBA4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000BBA8: nop

    // 0x8000BBAC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8000BBB0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8000BBB4: lw          $t9, 0x3068($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3068);
    // 0x8000BBB8: nop

    // 0x8000BBBC: beq         $t9, $zero, L_8000BBD4
    if (ctx->r25 == 0) {
        // 0x8000BBC0: nop

            goto L_8000BBD4;
    }
    // 0x8000BBC0: nop

    // 0x8000BBC4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8000BBC8: lw          $t1, 0x3068($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3068);
    // 0x8000BBCC: nop

    // 0x8000BBD0: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
L_8000BBD4:
    // 0x8000BBD4: b           L_8000BC3C
    // 0x8000BBD8: nop

        goto L_8000BC3C;
    // 0x8000BBD8: nop

L_8000BBDC:
    // 0x8000BBDC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8000BBE0: lw          $t2, 0x3068($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3068);
    // 0x8000BBE4: nop

    // 0x8000BBE8: beq         $t2, $zero, L_8000BC08
    if (ctx->r10 == 0) {
        // 0x8000BBEC: nop

            goto L_8000BC08;
    }
    // 0x8000BBEC: nop

    // 0x8000BBF0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8000BBF4: lw          $a0, 0x3068($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3068);
    // 0x8000BBF8: jal         0x8000D390
    // 0x8000BBFC: nop

    TempHeap_Free(rdram, ctx);
        goto after_3;
    // 0x8000BBFC: nop

    after_3:
    // 0x8000BC00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8000BC04: sw          $zero, 0x3068($at)
    MEM_W(0X3068, ctx->r1) = 0;
L_8000BC08:
    // 0x8000BC08: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000BC0C: nop

    // 0x8000BC10: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8000BC14: nop

    // 0x8000BC18: sw          $zero, 0x1A8($t3)
    MEM_W(0X1A8, ctx->r11) = 0;
    // 0x8000BC1C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8000BC20: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8000BC24: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000BC28: nop

    // 0x8000BC2C: lw          $t6, 0x1A0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1A0);
    // 0x8000BC30: nop

    // 0x8000BC34: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8000BC38: sw          $t7, 0x1A0($t5)
    MEM_W(0X1A0, ctx->r13) = ctx->r15;
L_8000BC3C:
    // 0x8000BC3C: jal         0x8005F064
    // 0x8000BC40: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_8005F064(rdram, ctx);
        goto after_4;
    // 0x8000BC40: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_4:
    // 0x8000BC44: bne         $v0, $zero, L_8000BC54
    if (ctx->r2 != 0) {
        // 0x8000BC48: nop

            goto L_8000BC54;
    }
    // 0x8000BC48: nop

    // 0x8000BC4C: jal         0x80022124
    // 0x8000BC50: nop

    func_80022124(rdram, ctx);
        goto after_5;
    // 0x8000BC50: nop

    after_5:
L_8000BC54:
    // 0x8000BC54: jal         0x8005F268
    // 0x8000BC58: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_8005F268(rdram, ctx);
        goto after_6;
    // 0x8000BC58: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_6:
    // 0x8000BC5C: b           L_8000BC6C
    // 0x8000BC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000BC6C;
    // 0x8000BC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000BC64: b           L_8000BC6C
    // 0x8000BC68: nop

        goto L_8000BC6C;
    // 0x8000BC68: nop

L_8000BC6C:
    // 0x8000BC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BC70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BC74: jr          $ra
    // 0x8000BC78: nop

    return;
    // 0x8000BC78: nop

;}
