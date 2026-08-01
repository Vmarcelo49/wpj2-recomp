#include "librecomp/rsp.hpp"
#include "librecomp/rsp_vu_impl.hpp"
RspExitReason aspMain(uint8_t* rdram, [[maybe_unused]] uint32_t ucode_addr) {
    uint32_t           r1 = 0,  r2 = 0,  r3 = 0,  r4 = 0,  r5 = 0,  r6 = 0,  r7 = 0;
    uint32_t  r8 = 0,  r9 = 0, r10 = 0, r11 = 0, r12 = 0, r13 = 0, r14 = 0, r15 = 0;
    uint32_t r16 = 0, r17 = 0, r18 = 0, r19 = 0, r20 = 0, r21 = 0, r22 = 0, r23 = 0;
    uint32_t r24 = 0, r25 = 0, r26 = 0, r27 = 0, r28 = 0, r29 = 0, r30 = 0, r31 = 0;
    uint32_t dma_mem_address = 0, dma_dram_address = 0, jump_target = 0;
    const char * debug_file = NULL; int debug_line = 0;
    RSP rsp{};
    r1 = 0xFC0;
L_1080:
    // addi        $24, $zero, 0x360
    r24 = RSP_ADD32(0, 0X360);
L_1084:
    // addi        $23, $zero, 0xF90
    r23 = RSP_ADD32(0, 0XF90);
L_1088:
    // lw          $28, 0x30($1)
    r28 = RSP_MEM_W_LOAD(0X30, r1);
L_108C:
    // lw          $27, 0x34($1)
    r27 = RSP_MEM_W_LOAD(0X34, r1);
L_1090:
    // mfc0        $5, DPC_STATUS
    r5 = 0;
L_1094:
    // andi        $4, $5, 0x1
    r4 = r5 & 0X1;
L_1098:
    // beq         $4, $zero, L_10B4
    if (r4 == 0) {
        // andi        $4, $5, 0x100
        r4 = r5 & 0X100;
        goto L_10B4;
    }
L_109C:
    // andi        $4, $5, 0x100
    r4 = r5 & 0X100;
L_10A0:
    // beq         $4, $zero, L_10B4
    if (r4 == 0) {
        // nop
    
        goto L_10B4;
    }
L_10A4:
    // nop

L_10A8:
    // mfc0        $4, DPC_STATUS
    r4 = 0;
L_10AC:
    // andi        $4, $4, 0x100
    r4 = r4 & 0X100;
L_10B0:
    // bgtz        $4, L_10A8
    if (RSP_SIGNED(r4) > 0) {
        // nop
    
        goto L_10A8;
    }
L_10B4:
    // nop

L_10B8:
    // jal         0x1150
    r31 = 0x10C0;
    // nop

    goto L_1150;
L_10BC:
    // nop

L_10C0:
    // addi        $2, $zero, 0xF
    r2 = RSP_ADD32(0, 0XF);
L_10C4:
    // addi        $1, $zero, 0x320
    r1 = RSP_ADD32(0, 0X320);
L_10C8:
    // sw          $zero, 0x0($1)
    RSP_MEM_W_STORE(0X0, r1, 0);
L_10CC:
    // bgtz        $2, L_10C8
    if (RSP_SIGNED(r2) > 0) {
        // addi        $2, $2, -0x1
        r2 = RSP_ADD32(r2, -0X1);
        goto L_10C8;
    }
L_10D0:
    // addi        $2, $2, -0x1
    r2 = RSP_ADD32(r2, -0X1);
L_10D4:
    // mfc0        $2, SP_DMA_BUSY
    r2 = 0;
L_10D8:
    // bne         $2, $zero, L_10D4
    if (r2 != 0) {
        // addi        $29, $zero, 0x380
        r29 = RSP_ADD32(0, 0X380);
        goto L_10D4;
    }
L_10DC:
    // addi        $29, $zero, 0x380
    r29 = RSP_ADD32(0, 0X380);
L_10E0:
    // mtc0        $zero, SP_SEMAPHORE
L_10E4:
    // lw          $26, 0x0($29)
    r26 = RSP_MEM_W_LOAD(0X0, r29);
L_10E8:
    // lw          $25, 0x4($29)
    r25 = RSP_MEM_W_LOAD(0X4, r29);
L_10EC:
    // srl         $1, $26, 23
    r1 = S32(U32(r26) >> 23);
L_10F0:
    // andi        $1, $1, 0xFE
    r1 = r1 & 0XFE;
L_10F4:
    // addi        $28, $28, 0x8
    r28 = RSP_ADD32(r28, 0X8);
L_10F8:
    // addi        $27, $27, -0x8
    r27 = RSP_ADD32(r27, -0X8);
L_10FC:
    // addi        $29, $29, 0x8
    r29 = RSP_ADD32(r29, 0X8);
L_1100:
    // addi        $30, $30, -0x8
    r30 = RSP_ADD32(r30, -0X8);
L_1104:
    // add         $2, $zero, $1
    r2 = RSP_ADD32(0, r1);
L_1108:
    // lh          $2, 0x10($2)
    r2 = RSP_MEM_H_LOAD(0X10, r2);
L_110C:
    // jr          $2
    jump_target = r2;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
L_1110:
    // nop

L_1114:
    // break       0
    return RspExitReason::Broke;
L_1118:
    // bgtz        $30, L_10E4
    if (RSP_SIGNED(r30) > 0) {
        // nop
    
        goto L_10E4;
    }
L_111C:
    // nop

L_1120:
    // blez        $27, L_1138
    if (RSP_SIGNED(r27) <= 0) {
        // nop
    
        goto L_1138;
    }
L_1124:
    // nop

L_1128:
    // jal         0x1150
    r31 = 0x1130;
    // nop

    goto L_1150;
L_112C:
    // nop

L_1130:
    // j           L_10D4
    // nop

    goto L_10D4;
L_1134:
    // nop

L_1138:
    // ori         $1, $zero, 0x4000
    r1 = 0 | 0X4000;
L_113C:
    // mtc0        $1, SP_STATUS
L_1140:
    // break       0
    return RspExitReason::Broke;
L_1144:
    // nop

L_1148:
    // b           L_1148
    // nop

    goto L_1148;
L_114C:
    // nop

L_1150:
    // addi        $5, $ra, 0x0
    r5 = RSP_ADD32(r31, 0X0);
L_1154:
    // add         $2, $zero, $28
    r2 = RSP_ADD32(0, r28);
L_1158:
    // addi        $3, $27, 0x0
    r3 = RSP_ADD32(r27, 0X0);
L_115C:
    // addi        $4, $3, -0x140
    r4 = RSP_ADD32(r3, -0X140);
L_1160:
    // blez        $4, L_116C
    if (RSP_SIGNED(r4) <= 0) {
        // addi        $1, $zero, 0x380
        r1 = RSP_ADD32(0, 0X380);
        goto L_116C;
    }
L_1164:
    // addi        $1, $zero, 0x380
    r1 = RSP_ADD32(0, 0X380);
L_1168:
    // addi        $3, $zero, 0x140
    r3 = RSP_ADD32(0, 0X140);
L_116C:
    // addi        $30, $3, 0x0
    r30 = RSP_ADD32(r3, 0X0);
L_1170:
    // jal         0x1184
    r31 = 0x1178;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1184;
L_1174:
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1178:
    // addi        $29, $zero, 0x380
    r29 = RSP_ADD32(0, 0X380);
L_117C:
    // jr          $5
    jump_target = r5;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
L_1180:
    // nop

L_1184:
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_1188:
    // bne         $4, $zero, L_1184
    if (r4 != 0) {
        // nop
    
        goto L_1184;
    }
L_118C:
    // nop

L_1190:
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
L_1194:
    // bne         $4, $zero, L_1190
    if (r4 != 0) {
        // nop
    
        goto L_1190;
    }
L_1198:
    // nop

L_119C:
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
L_11A0:
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
L_11A4:
    // mtc0        $3, SP_RD_LEN
    DO_DMA_READ(r3);
L_11A8:
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
L_11AC:
    // nop

L_11B0:
    // mfc0        $4, SP_SEMAPHORE
    r4 = 0;
L_11B4:
    // bne         $4, $zero, L_11B0
    if (r4 != 0) {
        // nop
    
        goto L_11B0;
    }
L_11B8:
    // nop

L_11BC:
    // mfc0        $4, SP_DMA_FULL
    r4 = 0;
L_11C0:
    // bne         $4, $zero, L_11BC
    if (r4 != 0) {
        // nop
    
        goto L_11BC;
    }
L_11C4:
    // nop

L_11C8:
    // mtc0        $1, SP_MEM_ADDR
    SET_DMA_MEM(r1);
L_11CC:
    // mtc0        $2, SP_DRAM_ADDR
    SET_DMA_DRAM(r2);
L_11D0:
    // mtc0        $3, SP_WR_LEN
    DO_DMA_WRITE(r3);
L_11D4:
    // jr          $ra
    jump_target = r31;
    debug_file = __FILE__; debug_line = __LINE__;
    // nop

    goto do_indirect_jump;
L_11D8:
    // nop

L_11DC:
    // andi        $3, $25, 0xFFFF
    r3 = r25 & 0XFFFF;
L_11E0:
    // beq         $3, $zero, L_1118
    if (r3 == 0) {
        // addi        $4, $zero, 0x5C0
        r4 = RSP_ADD32(0, 0X5C0);
        goto L_1118;
    }
L_11E4:
    // addi        $4, $zero, 0x5C0
    r4 = RSP_ADD32(0, 0X5C0);
L_11E8:
    // andi        $2, $26, 0xFFFF
    r2 = r26 & 0XFFFF;
L_11EC:
    // add         $2, $2, $4
    r2 = RSP_ADD32(r2, r4);
L_11F0:
    // vxor        $v1, $v1, $v1
    rsp.VXOR<0>(rsp.vpu.r[1], rsp.vpu.r[1], rsp.vpu.r[1]);
L_11F4:
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
L_11F8:
    // sdv         $v1[0], 0x0($2)
    rsp.SDV<0>(rsp.vpu.r[1], r2, 0X0);
L_11FC:
    // sdv         $v1[0], 0x8($2)
    rsp.SDV<0>(rsp.vpu.r[1], r2, 0X1);
L_1200:
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
L_1204:
    // bgtz        $3, L_11F8
    if (RSP_SIGNED(r3) > 0) {
        // addi        $3, $3, -0x10
        r3 = RSP_ADD32(r3, -0X10);
        goto L_11F8;
    }
L_1208:
    // addi        $3, $3, -0x10
    r3 = RSP_ADD32(r3, -0X10);
L_120C:
    // j           L_1118
    // nop

    goto L_1118;
L_1210:
    // nop

L_1214:
    // lhu         $3, 0x4($24)
    r3 = RSP_MEM_HU_LOAD(0X4, r24);
L_1218:
    // beq         $3, $zero, L_1118
    if (r3 == 0) {
        // sll         $2, $25, 8
        r2 = S32(r25) << 8;
        goto L_1118;
    }
L_121C:
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
L_1220:
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
L_1224:
    // srl         $4, $25, 24
    r4 = S32(U32(r25) >> 24);
L_1228:
    // sll         $4, $4, 2
    r4 = S32(r4) << 2;
L_122C:
    // lw          $5, 0x320($4)
    r5 = RSP_MEM_W_LOAD(0X320, r4);
L_1230:
    // add         $2, $2, $5
    r2 = RSP_ADD32(r2, r5);
L_1234:
    // lhu         $1, 0x0($24)
    r1 = RSP_MEM_HU_LOAD(0X0, r24);
L_1238:
    // jal         0x1184
    r31 = 0x1240;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1184;
L_123C:
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1240:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_1244:
    // bne         $1, $zero, L_1240
    if (r1 != 0) {
        // nop
    
        goto L_1240;
    }
L_1248:
    // nop

L_124C:
    // j           L_1118
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1118;
L_1250:
    // mtc0        $zero, SP_SEMAPHORE
L_1254:
    // lhu         $3, 0x4($24)
    r3 = RSP_MEM_HU_LOAD(0X4, r24);
L_1258:
    // beq         $3, $zero, L_1118
    if (r3 == 0) {
        // sll         $2, $25, 8
        r2 = S32(r25) << 8;
        goto L_1118;
    }
L_125C:
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
L_1260:
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
L_1264:
    // srl         $4, $25, 24
    r4 = S32(U32(r25) >> 24);
L_1268:
    // sll         $4, $4, 2
    r4 = S32(r4) << 2;
L_126C:
    // lw          $5, 0x320($4)
    r5 = RSP_MEM_W_LOAD(0X320, r4);
L_1270:
    // add         $2, $2, $5
    r2 = RSP_ADD32(r2, r5);
L_1274:
    // lhu         $1, 0x2($24)
    r1 = RSP_MEM_HU_LOAD(0X2, r24);
L_1278:
    // jal         0x11B0
    r31 = 0x1280;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_11B0;
L_127C:
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_1280:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_1284:
    // bne         $1, $zero, L_1280
    if (r1 != 0) {
        // nop
    
        goto L_1280;
    }
L_1288:
    // nop

L_128C:
    // j           L_1118
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1118;
L_1290:
    // mtc0        $zero, SP_SEMAPHORE
L_1294:
    // sll         $2, $25, 8
    r2 = S32(r25) << 8;
L_1298:
    // srl         $2, $2, 8
    r2 = S32(U32(r2) >> 8);
L_129C:
    // srl         $4, $25, 24
    r4 = S32(U32(r25) >> 24);
L_12A0:
    // sll         $4, $4, 2
    r4 = S32(r4) << 2;
L_12A4:
    // lw          $5, 0x320($4)
    r5 = RSP_MEM_W_LOAD(0X320, r4);
L_12A8:
    // add         $2, $2, $5
    r2 = RSP_ADD32(r2, r5);
L_12AC:
    // addi        $1, $zero, 0x4C0
    r1 = RSP_ADD32(0, 0X4C0);
L_12B0:
    // andi        $3, $26, 0xFFFF
    r3 = r26 & 0XFFFF;
L_12B4:
    // jal         0x1184
    r31 = 0x12BC;
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
    goto L_1184;
L_12B8:
    // addi        $3, $3, -0x1
    r3 = RSP_ADD32(r3, -0X1);
L_12BC:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_12C0:
    // bne         $1, $zero, L_12BC
    if (r1 != 0) {
        // nop
    
        goto L_12BC;
    }
L_12C4:
    // nop

L_12C8:
    // j           L_1118
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1118;
L_12CC:
    // mtc0        $zero, SP_SEMAPHORE
L_12D0:
    // sll         $3, $25, 8
    r3 = S32(r25) << 8;
L_12D4:
    // srl         $3, $3, 8
    r3 = S32(U32(r3) >> 8);
L_12D8:
    // srl         $2, $25, 24
    r2 = S32(U32(r25) >> 24);
L_12DC:
    // sll         $2, $2, 2
    r2 = S32(r2) << 2;
L_12E0:
    // add         $4, $zero, $2
    r4 = RSP_ADD32(0, r2);
L_12E4:
    // j           L_1118
    // sw          $3, 0x320($4)
    RSP_MEM_W_STORE(0X320, r4, r3);
    goto L_1118;
L_12E8:
    // sw          $3, 0x320($4)
    RSP_MEM_W_STORE(0X320, r4, r3);
L_12EC:
    // addi        $1, $26, 0x5C0
    r1 = RSP_ADD32(r26, 0X5C0);
L_12F0:
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
L_12F4:
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
L_12F8:
    // srl         $4, $26, 16
    r4 = S32(U32(r26) >> 16);
L_12FC:
    // andi        $4, $4, 0x8
    r4 = r4 & 0X8;
L_1300:
    // bgtz        $4, L_1318
    if (RSP_SIGNED(r4) > 0) {
        // addi        $3, $25, 0x5C0
        r3 = RSP_ADD32(r25, 0X5C0);
        goto L_1318;
    }
L_1304:
    // addi        $3, $25, 0x5C0
    r3 = RSP_ADD32(r25, 0X5C0);
L_1308:
    // sh          $1, 0x0($24)
    RSP_MEM_H_STORE(0X0, r24, r1);
L_130C:
    // sh          $2, 0x2($24)
    RSP_MEM_H_STORE(0X2, r24, r2);
L_1310:
    // j           L_1118
    // sh          $25, 0x4($24)
    RSP_MEM_H_STORE(0X4, r24, r25);
    goto L_1118;
L_1314:
    // sh          $25, 0x4($24)
    RSP_MEM_H_STORE(0X4, r24, r25);
L_1318:
    // sh          $3, 0xE($24)
    RSP_MEM_H_STORE(0XE, r24, r3);
L_131C:
    // sh          $1, 0xA($24)
    RSP_MEM_H_STORE(0XA, r24, r1);
L_1320:
    // j           L_1118
    // sh          $2, 0xC($24)
    RSP_MEM_H_STORE(0XC, r24, r2);
    goto L_1118;
L_1324:
    // sh          $2, 0xC($24)
    RSP_MEM_H_STORE(0XC, r24, r2);
L_1328:
    // srl         $2, $26, 16
    r2 = S32(U32(r26) >> 16);
L_132C:
    // andi        $1, $2, 0x8
    r1 = r2 & 0X8;
L_1330:
    // beq         $1, $zero, L_1344
    if (r1 == 0) {
        // andi        $1, $2, 0x4
        r1 = r2 & 0X4;
        goto L_1344;
    }
L_1334:
    // andi        $1, $2, 0x4
    r1 = r2 & 0X4;
L_1338:
    // sh          $26, 0x1C($24)
    RSP_MEM_H_STORE(0X1C, r24, r26);
L_133C:
    // j           L_1118
    // sh          $25, 0x1E($24)
    RSP_MEM_H_STORE(0X1E, r24, r25);
    goto L_1118;
L_1340:
    // sh          $25, 0x1E($24)
    RSP_MEM_H_STORE(0X1E, r24, r25);
L_1344:
    // beq         $1, $zero, L_1364
    if (r1 == 0) {
        // andi        $1, $2, 0x2
        r1 = r2 & 0X2;
        goto L_1364;
    }
L_1348:
    // andi        $1, $2, 0x2
    r1 = r2 & 0X2;
L_134C:
    // beq         $1, $zero, L_135C
    if (r1 == 0) {
        // nop
    
        goto L_135C;
    }
L_1350:
    // nop

L_1354:
    // j           L_1118
    // sh          $26, 0x6($24)
    RSP_MEM_H_STORE(0X6, r24, r26);
    goto L_1118;
L_1358:
    // sh          $26, 0x6($24)
    RSP_MEM_H_STORE(0X6, r24, r26);
L_135C:
    // j           L_1118
    // sh          $26, 0x8($24)
    RSP_MEM_H_STORE(0X8, r24, r26);
    goto L_1118;
L_1360:
    // sh          $26, 0x8($24)
    RSP_MEM_H_STORE(0X8, r24, r26);
L_1364:
    // beq         $1, $zero, L_137C
    if (r1 == 0) {
        // srl         $1, $25, 16
        r1 = S32(U32(r25) >> 16);
        goto L_137C;
    }
L_1368:
    // srl         $1, $25, 16
    r1 = S32(U32(r25) >> 16);
L_136C:
    // sh          $26, 0x10($24)
    RSP_MEM_H_STORE(0X10, r24, r26);
L_1370:
    // sh          $1, 0x12($24)
    RSP_MEM_H_STORE(0X12, r24, r1);
L_1374:
    // j           L_1118
    // sh          $25, 0x14($24)
    RSP_MEM_H_STORE(0X14, r24, r25);
    goto L_1118;
L_1378:
    // sh          $25, 0x14($24)
    RSP_MEM_H_STORE(0X14, r24, r25);
L_137C:
    // sh          $26, 0x16($24)
    RSP_MEM_H_STORE(0X16, r24, r26);
L_1380:
    // sh          $1, 0x18($24)
    RSP_MEM_H_STORE(0X18, r24, r1);
L_1384:
    // j           L_1118
    // sh          $25, 0x1A($24)
    RSP_MEM_H_STORE(0X1A, r24, r25);
    goto L_1118;
L_1388:
    // sh          $25, 0x1A($24)
    RSP_MEM_H_STORE(0X1A, r24, r25);
L_138C:
    // lhu         $1, 0x4($24)
    r1 = RSP_MEM_HU_LOAD(0X4, r24);
L_1390:
    // lhu         $4, 0x2($24)
    r4 = RSP_MEM_HU_LOAD(0X2, r24);
L_1394:
    // beq         $1, $zero, L_1118
    if (r1 == 0) {
        // andi        $3, $25, 0xFFFF
        r3 = r25 & 0XFFFF;
        goto L_1118;
    }
L_1398:
    // andi        $3, $25, 0xFFFF
    r3 = r25 & 0XFFFF;
L_139C:
    // addi        $3, $3, 0x5C0
    r3 = RSP_ADD32(r3, 0X5C0);
L_13A0:
    // srl         $2, $25, 16
    r2 = S32(U32(r25) >> 16);
L_13A4:
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
L_13A8:
    // lqv         $v1[0], 0x0($2)
    rsp.LQV<0>(rsp.vpu.r[1], r2, 0X0);
L_13AC:
    // lqv         $v2[0], 0x0($3)
    rsp.LQV<0>(rsp.vpu.r[2], r3, 0X0);
L_13B0:
    // ssv         $v1[0], 0x0($4)
    rsp.SSV<0>(rsp.vpu.r[1], r4, 0X0);
L_13B4:
    // ssv         $v2[0], 0x2($4)
    rsp.SSV<0>(rsp.vpu.r[2], r4, 0X1);
L_13B8:
    // ssv         $v1[2], 0x4($4)
    rsp.SSV<2>(rsp.vpu.r[1], r4, 0X2);
L_13BC:
    // ssv         $v2[2], 0x6($4)
    rsp.SSV<2>(rsp.vpu.r[2], r4, 0X3);
L_13C0:
    // ssv         $v1[4], 0x8($4)
    rsp.SSV<4>(rsp.vpu.r[1], r4, 0X4);
L_13C4:
    // ssv         $v2[4], 0xA($4)
    rsp.SSV<4>(rsp.vpu.r[2], r4, 0X5);
L_13C8:
    // ssv         $v1[6], 0xC($4)
    rsp.SSV<6>(rsp.vpu.r[1], r4, 0X6);
L_13CC:
    // ssv         $v2[6], 0xE($4)
    rsp.SSV<6>(rsp.vpu.r[2], r4, 0X7);
L_13D0:
    // ssv         $v1[8], 0x10($4)
    rsp.SSV<8>(rsp.vpu.r[1], r4, 0X8);
L_13D4:
    // ssv         $v2[8], 0x12($4)
    rsp.SSV<8>(rsp.vpu.r[2], r4, 0X9);
L_13D8:
    // ssv         $v1[10], 0x14($4)
    rsp.SSV<10>(rsp.vpu.r[1], r4, 0XA);
L_13DC:
    // ssv         $v2[10], 0x16($4)
    rsp.SSV<10>(rsp.vpu.r[2], r4, 0XB);
L_13E0:
    // ssv         $v1[12], 0x18($4)
    rsp.SSV<12>(rsp.vpu.r[1], r4, 0XC);
L_13E4:
    // ssv         $v2[12], 0x1A($4)
    rsp.SSV<12>(rsp.vpu.r[2], r4, 0XD);
L_13E8:
    // ssv         $v1[14], 0x1C($4)
    rsp.SSV<14>(rsp.vpu.r[1], r4, 0XE);
L_13EC:
    // ssv         $v2[14], 0x1E($4)
    rsp.SSV<14>(rsp.vpu.r[2], r4, 0XF);
L_13F0:
    // addi        $1, $1, -0x10
    r1 = RSP_ADD32(r1, -0X10);
L_13F4:
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
L_13F8:
    // addi        $3, $3, 0x10
    r3 = RSP_ADD32(r3, 0X10);
L_13FC:
    // bgtz        $1, L_13A8
    if (RSP_SIGNED(r1) > 0) {
        // addi        $4, $4, 0x20
        r4 = RSP_ADD32(r4, 0X20);
        goto L_13A8;
    }
L_1400:
    // addi        $4, $4, 0x20
    r4 = RSP_ADD32(r4, 0X20);
L_1404:
    // j           L_1118
    // nop

    goto L_1118;
L_1408:
    // nop

L_140C:
    // andi        $1, $25, 0xFFFF
    r1 = r25 & 0XFFFF;
L_1410:
    // beq         $1, $zero, L_1118
    if (r1 == 0) {
        // andi        $2, $26, 0xFFFF
        r2 = r26 & 0XFFFF;
        goto L_1118;
    }
L_1414:
    // andi        $2, $26, 0xFFFF
    r2 = r26 & 0XFFFF;
L_1418:
    // addi        $2, $2, 0x5C0
    r2 = RSP_ADD32(r2, 0X5C0);
L_141C:
    // srl         $3, $25, 16
    r3 = S32(U32(r25) >> 16);
L_1420:
    // addi        $3, $3, 0x5C0
    r3 = RSP_ADD32(r3, 0X5C0);
L_1424:
    // ldv         $v1[0], 0x0($2)
    rsp.LDV<0>(rsp.vpu.r[1], r2, 0X0);
L_1428:
    // ldv         $v2[0], 0x8($2)
    rsp.LDV<0>(rsp.vpu.r[2], r2, 0X1);
L_142C:
    // addi        $1, $1, -0x10
    r1 = RSP_ADD32(r1, -0X10);
L_1430:
    // addi        $2, $2, 0x10
    r2 = RSP_ADD32(r2, 0X10);
L_1434:
    // sdv         $v1[0], 0x0($3)
    rsp.SDV<0>(rsp.vpu.r[1], r3, 0X0);
L_1438:
    // sdv         $v2[0], 0x8($3)
    rsp.SDV<0>(rsp.vpu.r[2], r3, 0X1);
L_143C:
    // bgtz        $1, L_1424
    if (RSP_SIGNED(r1) > 0) {
        // addi        $3, $3, 0x10
        r3 = RSP_ADD32(r3, 0X10);
        goto L_1424;
    }
L_1440:
    // addi        $3, $3, 0x10
    r3 = RSP_ADD32(r3, 0X10);
L_1444:
    // j           L_1118
    // nop

    goto L_1118;
L_1448:
    // nop

L_144C:
    // sll         $1, $25, 8
    r1 = S32(r25) << 8;
L_1450:
    // srl         $1, $1, 8
    r1 = S32(U32(r1) >> 8);
L_1454:
    // srl         $3, $25, 24
    r3 = S32(U32(r25) >> 24);
L_1458:
    // sll         $3, $3, 2
    r3 = S32(r3) << 2;
L_145C:
    // lw          $2, 0x320($3)
    r2 = RSP_MEM_W_LOAD(0X320, r3);
L_1460:
    // add         $1, $1, $2
    r1 = RSP_ADD32(r1, r2);
L_1464:
    // sw          $1, 0x10($24)
    RSP_MEM_W_STORE(0X10, r24, r1);
L_1468:
    // j           L_1118
    // nop

    goto L_1118;
L_146C:
    // nop

L_1470:
    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
L_1474:
    // vxor        $v27, $v27, $v27
    rsp.VXOR<0>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[27]);
L_1478:
    // lhu         $21, 0x0($24)
    r21 = RSP_MEM_HU_LOAD(0X0, r24);
L_147C:
    // vxor        $v25, $v25, $v25
    rsp.VXOR<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[25]);
L_1480:
    // vxor        $v24, $v24, $v24
    rsp.VXOR<0>(rsp.vpu.r[24], rsp.vpu.r[24], rsp.vpu.r[24]);
L_1484:
    // addi        $20, $21, 0x1
    r20 = RSP_ADD32(r21, 0X1);
L_1488:
    // lhu         $19, 0x2($24)
    r19 = RSP_MEM_HU_LOAD(0X2, r24);
L_148C:
    // vxor        $v13, $v13, $v13
    rsp.VXOR<0>(rsp.vpu.r[13], rsp.vpu.r[13], rsp.vpu.r[13]);
L_1490:
    // vxor        $v14, $v14, $v14
    rsp.VXOR<0>(rsp.vpu.r[14], rsp.vpu.r[14], rsp.vpu.r[14]);
L_1494:
    // lhu         $18, 0x4($24)
    r18 = RSP_MEM_HU_LOAD(0X4, r24);
L_1498:
    // vxor        $v15, $v15, $v15
    rsp.VXOR<0>(rsp.vpu.r[15], rsp.vpu.r[15], rsp.vpu.r[15]);
L_149C:
    // lui         $1, 0xFF
    r1 = S32(0XFF << 16);
L_14A0:
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
L_14A4:
    // ori         $1, $1, 0xFFFF
    r1 = r1 | 0XFFFF;
L_14A8:
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
L_14AC:
    // and         $17, $25, $1
    r17 = r25 & r1;
L_14B0:
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
L_14B4:
    // srl         $2, $25, 24
    r2 = S32(U32(r25) >> 24);
L_14B8:
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
L_14BC:
    // sll         $2, $2, 2
    r2 = S32(r2) << 2;
L_14C0:
    // lw          $3, 0x320($2)
    r3 = RSP_MEM_W_LOAD(0X320, r2);
L_14C4:
    // add         $17, $17, $3
    r17 = RSP_ADD32(r17, r3);
L_14C8:
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
L_14CC:
    // sqv         $v27[0], 0x10($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X1);
L_14D0:
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
L_14D4:
    // andi        $1, $1, 0x1
    r1 = r1 & 0X1;
L_14D8:
    // bgtz        $1, L_150C
    if (RSP_SIGNED(r1) > 0) {
        // srl         $1, $26, 16
        r1 = S32(U32(r26) >> 16);
        goto L_150C;
    }
L_14DC:
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
L_14E0:
    // andi        $1, $1, 0x2
    r1 = r1 & 0X2;
L_14E4:
    // beq         $zero, $1, L_14F0
    if (0 == r1) {
        // addi        $2, $17, 0x0
        r2 = RSP_ADD32(r17, 0X0);
        goto L_14F0;
    }
L_14E8:
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
L_14EC:
    // lw          $2, 0x10($24)
    r2 = RSP_MEM_W_LOAD(0X10, r24);
L_14F0:
    // addi        $1, $19, 0x0
    r1 = RSP_ADD32(r19, 0X0);
L_14F4:
    // jal         0x1184
    r31 = 0x14FC;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_1184;
L_14F8:
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_14FC:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1500:
    // bne         $5, $zero, L_14FC
    if (r5 != 0) {
        // nop
    
        goto L_14FC;
    }
L_1504:
    // nop

L_1508:
    // mtc0        $zero, SP_SEMAPHORE
L_150C:
    // addi        $16, $zero, 0x30
    r16 = RSP_ADD32(0, 0X30);
L_1510:
    // addi        $15, $zero, 0x4C0
    r15 = RSP_ADD32(0, 0X4C0);
L_1514:
    // ldv         $v25[0], 0x0($16)
    rsp.LDV<0>(rsp.vpu.r[25], r16, 0X0);
L_1518:
    // ldv         $v24[8], 0x0($16)
    rsp.LDV<8>(rsp.vpu.r[24], r16, 0X0);
L_151C:
    // ldv         $v23[0], 0x8($16)
    rsp.LDV<0>(rsp.vpu.r[23], r16, 0X1);
L_1520:
    // ldv         $v23[8], 0x8($16)
    rsp.LDV<8>(rsp.vpu.r[23], r16, 0X1);
L_1524:
    // lqv         $v27[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X1);
L_1528:
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
L_152C:
    // beq         $18, $zero, L_16E8
    if (r18 == 0) {
        // ldv         $v1[0], 0x0($20)
        rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
        goto L_16E8;
    }
L_1530:
    // ldv         $v1[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
L_1534:
    // lbu         $1, 0x0($21)
    r1 = RSP_MEM_BU(0X0, r21);
L_1538:
    // andi        $11, $1, 0xF
    r11 = r1 & 0XF;
L_153C:
    // sll         $11, $11, 5
    r11 = S32(r11) << 5;
L_1540:
    // vand        $v3, $v25, $v1[0]
    rsp.VAND<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[1]);
L_1544:
    // add         $13, $11, $15
    r13 = RSP_ADD32(r11, r15);
L_1548:
    // vand        $v4, $v24, $v1[1]
    rsp.VAND<9>(rsp.vpu.r[4], rsp.vpu.r[24], rsp.vpu.r[1]);
L_154C:
    // srl         $14, $1, 4
    r14 = S32(U32(r1) >> 4);
L_1550:
    // vand        $v5, $v25, $v1[2]
    rsp.VAND<10>(rsp.vpu.r[5], rsp.vpu.r[25], rsp.vpu.r[1]);
L_1554:
    // addi        $2, $zero, 0xC
    r2 = RSP_ADD32(0, 0XC);
L_1558:
    // vand        $v6, $v24, $v1[3]
    rsp.VAND<11>(rsp.vpu.r[6], rsp.vpu.r[24], rsp.vpu.r[1]);
L_155C:
    // sub         $14, $2, $14
    r14 = RSP_SUB32(r2, r14);
L_1560:
    // addi        $2, $14, -0x1
    r2 = RSP_ADD32(r14, -0X1);
L_1564:
    // addi        $3, $zero, 0x1
    r3 = RSP_ADD32(0, 0X1);
L_1568:
    // sll         $3, $3, 15
    r3 = S32(r3) << 15;
L_156C:
    // srlv        $4, $3, $2
    r4 = S32(U32(r3) >> (r2 & 31));
L_1570:
    // mtc2        $4, $v22[0]
    rsp.MTC2<0>(r4, rsp.vpu.r[22]);
L_1574:
    // lqv         $v21[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[21], r13, 0X0);
L_1578:
    // lqv         $v20[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[20], r13, 0X1);
L_157C:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_1580:
    // lrv         $v19[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[19], r13, 0X2);
L_1584:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_1588:
    // lrv         $v18[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[18], r13, 0X2);
L_158C:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_1590:
    // lrv         $v17[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[17], r13, 0X2);
L_1594:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_1598:
    // lrv         $v16[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[16], r13, 0X2);
L_159C:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_15A0:
    // lrv         $v15[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[15], r13, 0X2);
L_15A4:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_15A8:
    // lrv         $v14[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[14], r13, 0X2);
L_15AC:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_15B0:
    // lrv         $v13[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[13], r13, 0X2);
L_15B4:
    // addi        $20, $20, 0x9
    r20 = RSP_ADD32(r20, 0X9);
L_15B8:
    // vmudn       $v30, $v3, $v23
    rsp.VMUDN<0>(rsp.vpu.r[30], rsp.vpu.r[3], rsp.vpu.r[23]);
L_15BC:
    // addi        $21, $21, 0x9
    r21 = RSP_ADD32(r21, 0X9);
L_15C0:
    // vmadn       $v30, $v4, $v23
    rsp.VMADN<0>(rsp.vpu.r[30], rsp.vpu.r[4], rsp.vpu.r[23]);
L_15C4:
    // ldv         $v1[0], 0x0($20)
    rsp.LDV<0>(rsp.vpu.r[1], r20, 0X0);
L_15C8:
    // vmudn       $v29, $v5, $v23
    rsp.VMUDN<0>(rsp.vpu.r[29], rsp.vpu.r[5], rsp.vpu.r[23]);
L_15CC:
    // lbu         $1, 0x0($21)
    r1 = RSP_MEM_BU(0X0, r21);
L_15D0:
    // vmadn       $v29, $v6, $v23
    rsp.VMADN<0>(rsp.vpu.r[29], rsp.vpu.r[6], rsp.vpu.r[23]);
L_15D4:
    // blez        $14, L_15E4
    if (RSP_SIGNED(r14) <= 0) {
        // andi        $11, $1, 0xF
        r11 = r1 & 0XF;
        goto L_15E4;
    }
L_15D8:
    // andi        $11, $1, 0xF
    r11 = r1 & 0XF;
L_15DC:
    // vmudm       $v30, $v30, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[30], rsp.vpu.r[30], rsp.vpu.r[22]);
L_15E0:
    // vmudm       $v29, $v29, $v22[0]
    rsp.VMUDM<8>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[22]);
L_15E4:
    // sll         $11, $11, 5
    r11 = S32(r11) << 5;
L_15E8:
    // vand        $v3, $v25, $v1[0]
    rsp.VAND<8>(rsp.vpu.r[3], rsp.vpu.r[25], rsp.vpu.r[1]);
L_15EC:
    // add         $13, $11, $15
    r13 = RSP_ADD32(r11, r15);
L_15F0:
    // vand        $v4, $v24, $v1[1]
    rsp.VAND<9>(rsp.vpu.r[4], rsp.vpu.r[24], rsp.vpu.r[1]);
L_15F4:
    // vand        $v5, $v25, $v1[2]
    rsp.VAND<10>(rsp.vpu.r[5], rsp.vpu.r[25], rsp.vpu.r[1]);
L_15F8:
    // vand        $v6, $v24, $v1[3]
    rsp.VAND<11>(rsp.vpu.r[6], rsp.vpu.r[24], rsp.vpu.r[1]);
L_15FC:
    // srl         $14, $1, 4
    r14 = S32(U32(r1) >> 4);
L_1600:
    // vmudh       $v2, $v21, $v27[6]
    rsp.VMUDH<14>(rsp.vpu.r[2], rsp.vpu.r[21], rsp.vpu.r[27]);
L_1604:
    // addi        $2, $zero, 0xC
    r2 = RSP_ADD32(0, 0XC);
L_1608:
    // vmadh       $v2, $v20, $v27[7]
    rsp.VMADH<15>(rsp.vpu.r[2], rsp.vpu.r[20], rsp.vpu.r[27]);
L_160C:
    // sub         $14, $2, $14
    r14 = RSP_SUB32(r2, r14);
L_1610:
    // vmadh       $v2, $v19, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[2], rsp.vpu.r[19], rsp.vpu.r[30]);
L_1614:
    // addi        $2, $14, -0x1
    r2 = RSP_ADD32(r14, -0X1);
L_1618:
    // vmadh       $v2, $v18, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[2], rsp.vpu.r[18], rsp.vpu.r[30]);
L_161C:
    // addi        $3, $zero, 0x1
    r3 = RSP_ADD32(0, 0X1);
L_1620:
    // vmadh       $v2, $v17, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[2], rsp.vpu.r[17], rsp.vpu.r[30]);
L_1624:
    // sll         $3, $3, 15
    r3 = S32(r3) << 15;
L_1628:
    // vmadh       $v2, $v16, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[2], rsp.vpu.r[16], rsp.vpu.r[30]);
L_162C:
    // srlv        $4, $3, $2
    r4 = S32(U32(r3) >> (r2 & 31));
L_1630:
    // vmadh       $v28, $v15, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[15], rsp.vpu.r[30]);
L_1634:
    // mtc2        $4, $v22[0]
    rsp.MTC2<0>(r4, rsp.vpu.r[22]);
L_1638:
    // vmadh       $v2, $v14, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[14], rsp.vpu.r[30]);
L_163C:
    // vmadh       $v2, $v13, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[13], rsp.vpu.r[30]);
L_1640:
    // vmadh       $v2, $v30, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[30], rsp.vpu.r[31]);
L_1644:
    // vsar        $v26, $v7, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[7]);
L_1648:
    // vsar        $v28, $v7, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[7]);
L_164C:
    // vmudn       $v2, $v26, $v31[4]
    rsp.VMUDN<12>(rsp.vpu.r[2], rsp.vpu.r[26], rsp.vpu.r[31]);
L_1650:
    // vmadh       $v28, $v28, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[31]);
L_1654:
    // vmudh       $v2, $v19, $v29[0]
    rsp.VMUDH<8>(rsp.vpu.r[2], rsp.vpu.r[19], rsp.vpu.r[29]);
L_1658:
    // addi        $12, $13, -0x2
    r12 = RSP_ADD32(r13, -0X2);
L_165C:
    // vmadh       $v2, $v18, $v29[1]
    rsp.VMADH<9>(rsp.vpu.r[2], rsp.vpu.r[18], rsp.vpu.r[29]);
L_1660:
    // lrv         $v19[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[19], r12, 0X2);
L_1664:
    // vmadh       $v2, $v17, $v29[2]
    rsp.VMADH<10>(rsp.vpu.r[2], rsp.vpu.r[17], rsp.vpu.r[29]);
L_1668:
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
L_166C:
    // vmadh       $v2, $v16, $v29[3]
    rsp.VMADH<11>(rsp.vpu.r[2], rsp.vpu.r[16], rsp.vpu.r[29]);
L_1670:
    // lrv         $v18[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[18], r12, 0X2);
L_1674:
    // vmadh       $v2, $v15, $v29[4]
    rsp.VMADH<12>(rsp.vpu.r[2], rsp.vpu.r[15], rsp.vpu.r[29]);
L_1678:
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
L_167C:
    // vmadh       $v2, $v14, $v29[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[14], rsp.vpu.r[29]);
L_1680:
    // lrv         $v17[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[17], r12, 0X2);
L_1684:
    // vmadh       $v2, $v13, $v29[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[13], rsp.vpu.r[29]);
L_1688:
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
L_168C:
    // vmadh       $v2, $v29, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[2], rsp.vpu.r[29], rsp.vpu.r[31]);
L_1690:
    // lrv         $v16[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[16], r12, 0X2);
L_1694:
    // vmadh       $v2, $v21, $v28[6]
    rsp.VMADH<14>(rsp.vpu.r[2], rsp.vpu.r[21], rsp.vpu.r[28]);
L_1698:
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
L_169C:
    // vmadh       $v2, $v20, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[2], rsp.vpu.r[20], rsp.vpu.r[28]);
L_16A0:
    // lrv         $v15[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[15], r12, 0X2);
L_16A4:
    // vsar        $v26, $v7, $v27[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[7]);
L_16A8:
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
L_16AC:
    // vsar        $v27, $v7, $v27[0]
    rsp.VSAR<8>(rsp.vpu.r[27], rsp.vpu.r[7]);
L_16B0:
    // lrv         $v14[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[14], r12, 0X2);
L_16B4:
    // addi        $12, $12, -0x2
    r12 = RSP_ADD32(r12, -0X2);
L_16B8:
    // lrv         $v13[0], 0x20($12)
    rsp.LRV<0>(rsp.vpu.r[13], r12, 0X2);
L_16BC:
    // lqv         $v21[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[21], r13, 0X0);
L_16C0:
    // vmudn       $v2, $v26, $v31[4]
    rsp.VMUDN<12>(rsp.vpu.r[2], rsp.vpu.r[26], rsp.vpu.r[31]);
L_16C4:
    // lqv         $v20[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[20], r13, 0X1);
L_16C8:
    // vmadh       $v27, $v27, $v31[4]
    rsp.VMADH<12>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[31]);
L_16CC:
    // addi        $18, $18, -0x20
    r18 = RSP_ADD32(r18, -0X20);
L_16D0:
    // sdv         $v28[0], 0x0($19)
    rsp.SDV<0>(rsp.vpu.r[28], r19, 0X0);
L_16D4:
    // sdv         $v28[8], 0x8($19)
    rsp.SDV<8>(rsp.vpu.r[28], r19, 0X1);
L_16D8:
    // sdv         $v27[0], 0x10($19)
    rsp.SDV<0>(rsp.vpu.r[27], r19, 0X2);
L_16DC:
    // sdv         $v27[8], 0x18($19)
    rsp.SDV<8>(rsp.vpu.r[27], r19, 0X3);
L_16E0:
    // bgtz        $18, L_15B4
    if (RSP_SIGNED(r18) > 0) {
        // addi        $19, $19, 0x20
        r19 = RSP_ADD32(r19, 0X20);
        goto L_15B4;
    }
L_16E4:
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
L_16E8:
    // addi        $1, $19, -0x20
    r1 = RSP_ADD32(r19, -0X20);
L_16EC:
    // addi        $2, $17, 0x0
    r2 = RSP_ADD32(r17, 0X0);
L_16F0:
    // jal         0x11B0
    r31 = 0x16F8;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_11B0;
L_16F4:
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_16F8:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_16FC:
    // bne         $5, $zero, L_16F8
    if (r5 != 0) {
        // nop
    
        goto L_16F8;
    }
L_1700:
    // nop

L_1704:
    // j           L_1118
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1118;
L_1708:
    // mtc0        $zero, SP_SEMAPHORE
L_170C:
    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
L_1710:
    // vxor        $v28, $v28, $v28
    rsp.VXOR<0>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[28]);
L_1714:
    // lhu         $21, 0x0($24)
    r21 = RSP_MEM_HU_LOAD(0X0, r24);
L_1718:
    // vxor        $v17, $v17, $v17
    rsp.VXOR<0>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[17]);
L_171C:
    // lhu         $20, 0x2($24)
    r20 = RSP_MEM_HU_LOAD(0X2, r24);
L_1720:
    // vxor        $v18, $v18, $v18
    rsp.VXOR<0>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[18]);
L_1724:
    // lhu         $19, 0x4($24)
    r19 = RSP_MEM_HU_LOAD(0X4, r24);
L_1728:
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
L_172C:
    // beq         $19, $zero, L_1874
    if (r19 == 0) {
        // andi        $14, $26, 0xFFFF
        r14 = r26 & 0XFFFF;
        goto L_1874;
    }
L_1730:
    // andi        $14, $26, 0xFFFF
    r14 = r26 & 0XFFFF;
L_1734:
    // mtc2        $14, $v31[10]
    rsp.MTC2<10>(r14, rsp.vpu.r[31]);
L_1738:
    // sll         $14, $14, 2
    r14 = S32(r14) << 2;
L_173C:
    // mtc2        $14, $v16[0]
    rsp.MTC2<0>(r14, rsp.vpu.r[16]);
L_1740:
    // lui         $1, 0xFF
    r1 = S32(0XFF << 16);
L_1744:
    // vxor        $v20, $v20, $v20
    rsp.VXOR<0>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[20]);
L_1748:
    // ori         $1, $1, 0xFFFF
    r1 = r1 | 0XFFFF;
L_174C:
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
L_1750:
    // and         $18, $25, $1
    r18 = r25 & r1;
L_1754:
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
L_1758:
    // srl         $2, $25, 24
    r2 = S32(U32(r25) >> 24);
L_175C:
    // vxor        $v23, $v23, $v23
    rsp.VXOR<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[23]);
L_1760:
    // sll         $2, $2, 2
    r2 = S32(r2) << 2;
L_1764:
    // lw          $3, 0x320($2)
    r3 = RSP_MEM_W_LOAD(0X320, r2);
L_1768:
    // add         $18, $18, $3
    r18 = RSP_ADD32(r18, r3);
L_176C:
    // slv         $v28[0], 0x0($23)
    rsp.SLV<0>(rsp.vpu.r[28], r23, 0X0);
L_1770:
    // srl         $1, $26, 16
    r1 = S32(U32(r26) >> 16);
L_1774:
    // andi        $1, $1, 0x1
    r1 = r1 & 0X1;
L_1778:
    // bgtz        $1, L_17A0
    if (RSP_SIGNED(r1) > 0) {
        // nop
    
        goto L_17A0;
    }
L_177C:
    // nop

L_1780:
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
L_1784:
    // addi        $2, $18, 0x0
    r2 = RSP_ADD32(r18, 0X0);
L_1788:
    // jal         0x1184
    r31 = 0x1790;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    goto L_1184;
L_178C:
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
L_1790:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1794:
    // bne         $5, $zero, L_1790
    if (r5 != 0) {
        // nop
    
        goto L_1790;
    }
L_1798:
    // nop

L_179C:
    // mtc0        $zero, SP_SEMAPHORE
L_17A0:
    // addi        $13, $zero, 0x4C0
    r13 = RSP_ADD32(0, 0X4C0);
L_17A4:
    // addi        $1, $zero, 0x4
    r1 = RSP_ADD32(0, 0X4);
L_17A8:
    // mtc2        $1, $v14[0]
    rsp.MTC2<0>(r1, rsp.vpu.r[14]);
L_17AC:
    // lqv         $v24[0], 0x10($13)
    rsp.LQV<0>(rsp.vpu.r[24], r13, 0X1);
L_17B0:
    // vmudm       $v16, $v24, $v16[0]
    rsp.VMUDM<8>(rsp.vpu.r[16], rsp.vpu.r[24], rsp.vpu.r[16]);
L_17B4:
    // ldv         $v28[8], 0x0($23)
    rsp.LDV<8>(rsp.vpu.r[28], r23, 0X0);
L_17B8:
    // sqv         $v16[0], 0x10($13)
    rsp.SQV<0>(rsp.vpu.r[16], r13, 0X1);
L_17BC:
    // lqv         $v25[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[25], r13, 0X0);
L_17C0:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_17C4:
    // lrv         $v23[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[23], r13, 0X2);
L_17C8:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_17CC:
    // lrv         $v22[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[22], r13, 0X2);
L_17D0:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_17D4:
    // lrv         $v21[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[21], r13, 0X2);
L_17D8:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_17DC:
    // lrv         $v20[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[20], r13, 0X2);
L_17E0:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_17E4:
    // lrv         $v19[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[19], r13, 0X2);
L_17E8:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_17EC:
    // lrv         $v18[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[18], r13, 0X2);
L_17F0:
    // addi        $13, $13, -0x2
    r13 = RSP_ADD32(r13, -0X2);
L_17F4:
    // lrv         $v17[0], 0x20($13)
    rsp.LRV<0>(rsp.vpu.r[17], r13, 0X2);
L_17F8:
    // ldv         $v30[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[30], r21, 0X0);
L_17FC:
    // ldv         $v30[8], 0x8($21)
    rsp.LDV<8>(rsp.vpu.r[30], r21, 0X1);
L_1800:
    // vmudh       $v16, $v25, $v28[6]
    rsp.VMUDH<14>(rsp.vpu.r[16], rsp.vpu.r[25], rsp.vpu.r[28]);
L_1804:
    // addi        $21, $21, 0x10
    r21 = RSP_ADD32(r21, 0X10);
L_1808:
    // vmadh       $v16, $v24, $v28[7]
    rsp.VMADH<15>(rsp.vpu.r[16], rsp.vpu.r[24], rsp.vpu.r[28]);
L_180C:
    // addi        $19, $19, -0x10
    r19 = RSP_ADD32(r19, -0X10);
L_1810:
    // vmadh       $v16, $v23, $v30[0]
    rsp.VMADH<8>(rsp.vpu.r[16], rsp.vpu.r[23], rsp.vpu.r[30]);
L_1814:
    // vmadh       $v16, $v22, $v30[1]
    rsp.VMADH<9>(rsp.vpu.r[16], rsp.vpu.r[22], rsp.vpu.r[30]);
L_1818:
    // vmadh       $v16, $v21, $v30[2]
    rsp.VMADH<10>(rsp.vpu.r[16], rsp.vpu.r[21], rsp.vpu.r[30]);
L_181C:
    // vmadh       $v16, $v20, $v30[3]
    rsp.VMADH<11>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[30]);
L_1820:
    // vmadh       $v28, $v19, $v30[4]
    rsp.VMADH<12>(rsp.vpu.r[28], rsp.vpu.r[19], rsp.vpu.r[30]);
L_1824:
    // vmadh       $v16, $v18, $v30[5]
    rsp.VMADH<13>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[30]);
L_1828:
    // vmadh       $v16, $v17, $v30[6]
    rsp.VMADH<14>(rsp.vpu.r[16], rsp.vpu.r[17], rsp.vpu.r[30]);
L_182C:
    // vmadh       $v16, $v30, $v31[5]
    rsp.VMADH<13>(rsp.vpu.r[16], rsp.vpu.r[30], rsp.vpu.r[31]);
L_1830:
    // ldv         $v30[0], 0x0($21)
    rsp.LDV<0>(rsp.vpu.r[30], r21, 0X0);
L_1834:
    // vsar        $v26, $v15, $v28[1]
    rsp.VSAR<9>(rsp.vpu.r[26], rsp.vpu.r[15]);
L_1838:
    // ldv         $v30[8], 0x8($21)
    rsp.LDV<8>(rsp.vpu.r[30], r21, 0X1);
L_183C:
    // vsar        $v28, $v15, $v28[0]
    rsp.VSAR<8>(rsp.vpu.r[28], rsp.vpu.r[15]);
L_1840:
    // vmudn       $v16, $v26, $v14[0]
    rsp.VMUDN<8>(rsp.vpu.r[16], rsp.vpu.r[26], rsp.vpu.r[14]);
L_1844:
    // vmadh       $v28, $v28, $v14[0]
    rsp.VMADH<8>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[14]);
L_1848:
    // sdv         $v28[0], 0x0($20)
    rsp.SDV<0>(rsp.vpu.r[28], r20, 0X0);
L_184C:
    // sdv         $v28[8], 0x8($20)
    rsp.SDV<8>(rsp.vpu.r[28], r20, 0X1);
L_1850:
    // bgtz        $19, L_1800
    if (RSP_SIGNED(r19) > 0) {
        // addi        $20, $20, 0x10
        r20 = RSP_ADD32(r20, 0X10);
        goto L_1800;
    }
L_1854:
    // addi        $20, $20, 0x10
    r20 = RSP_ADD32(r20, 0X10);
L_1858:
    // addi        $1, $20, -0x8
    r1 = RSP_ADD32(r20, -0X8);
L_185C:
    // addi        $2, $18, 0x0
    r2 = RSP_ADD32(r18, 0X0);
L_1860:
    // jal         0x11B0
    r31 = 0x1868;
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
    goto L_11B0;
L_1864:
    // addi        $3, $zero, 0x7
    r3 = RSP_ADD32(0, 0X7);
L_1868:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_186C:
    // bne         $5, $zero, L_1868
    if (r5 != 0) {
        // nop
    
        goto L_1868;
    }
L_1870:
    // nop

L_1874:
    // j           L_1118
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1118;
L_1878:
    // mtc0        $zero, SP_SEMAPHORE
L_187C:
    // lh          $8, 0x0($24)
    r8 = RSP_MEM_H_LOAD(0X0, r24);
L_1880:
    // lh          $19, 0x2($24)
    r19 = RSP_MEM_H_LOAD(0X2, r24);
L_1884:
    // lh          $18, 0x4($24)
    r18 = RSP_MEM_H_LOAD(0X4, r24);
L_1888:
    // lui         $4, 0xFF
    r4 = S32(0XFF << 16);
L_188C:
    // ori         $4, $4, 0xFFFF
    r4 = r4 | 0XFFFF;
L_1890:
    // and         $2, $25, $4
    r2 = r25 & r4;
L_1894:
    // srl         $5, $25, 24
    r5 = S32(U32(r25) >> 24);
L_1898:
    // sll         $5, $5, 2
    r5 = S32(r5) << 2;
L_189C:
    // lw          $6, 0x320($5)
    r6 = RSP_MEM_W_LOAD(0X320, r5);
L_18A0:
    // add         $2, $2, $6
    r2 = RSP_ADD32(r2, r6);
L_18A4:
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
L_18A8:
    // sw          $2, 0x40($23)
    RSP_MEM_W_STORE(0X40, r23, r2);
L_18AC:
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_18B0:
    // srl         $7, $26, 16
    r7 = S32(U32(r26) >> 16);
L_18B4:
    // andi        $10, $7, 0x1
    r10 = r7 & 0X1;
L_18B8:
    // bgtz        $10, L_18DC
    if (RSP_SIGNED(r10) > 0) {
        // nop
    
        goto L_18DC;
    }
L_18BC:
    // nop

L_18C0:
    // jal         0x1184
    r31 = 0x18C8;
    // nop

    goto L_1184;
L_18C4:
    // nop

L_18C8:
    // mfc0        $1, SP_DMA_BUSY
    r1 = 0;
L_18CC:
    // bne         $1, $zero, L_18C8
    if (r1 != 0) {
        // nop
    
        goto L_18C8;
    }
L_18D0:
    // nop

L_18D4:
    // j           L_18E8
    // mtc0        $zero, SP_SEMAPHORE
    goto L_18E8;
L_18D8:
    // mtc0        $zero, SP_SEMAPHORE
L_18DC:
    // sh          $zero, 0x8($23)
    RSP_MEM_H_STORE(0X8, r23, 0);
L_18E0:
    // vxor        $v16, $v16, $v16
    rsp.VXOR<0>(rsp.vpu.r[16], rsp.vpu.r[16], rsp.vpu.r[16]);
L_18E4:
    // sdv         $v16[0], 0x0($23)
    rsp.SDV<0>(rsp.vpu.r[16], r23, 0X0);
L_18E8:
    // andi        $10, $7, 0x2
    r10 = r7 & 0X2;
L_18EC:
    // beq         $10, $zero, L_1908
    if (r10 == 0) {
        // nop
    
        goto L_1908;
    }
L_18F0:
    // nop

L_18F4:
    // lh          $11, 0xA($23)
    r11 = RSP_MEM_H_LOAD(0XA, r23);
L_18F8:
    // lqv         $v3[0], 0x10($23)
    rsp.LQV<0>(rsp.vpu.r[3], r23, 0X1);
L_18FC:
    // sdv         $v3[0], 0x3F0($8)
    rsp.SDV<0>(rsp.vpu.r[3], r8, -0X2);
L_1900:
    // sdv         $v3[8], 0x3F8($8)
    rsp.SDV<8>(rsp.vpu.r[3], r8, -0X1);
L_1904:
    // sub         $8, $8, $11
    r8 = RSP_SUB32(r8, r11);
L_1908:
    // addi        $8, $8, -0x8
    r8 = RSP_ADD32(r8, -0X8);
L_190C:
    // lsv         $v23[14], 0x8($23)
    rsp.LSV<14>(rsp.vpu.r[23], r23, 0X4);
L_1910:
    // ldv         $v16[0], 0x0($23)
    rsp.LDV<0>(rsp.vpu.r[16], r23, 0X0);
L_1914:
    // sdv         $v16[0], 0x0($8)
    rsp.SDV<0>(rsp.vpu.r[16], r8, 0X0);
L_1918:
    // mtc2        $8, $v18[4]
    rsp.MTC2<4>(r8, rsp.vpu.r[18]);
L_191C:
    // addi        $10, $zero, 0xC0
    r10 = RSP_ADD32(0, 0XC0);
L_1920:
    // mtc2        $10, $v18[6]
    rsp.MTC2<6>(r10, rsp.vpu.r[18]);
L_1924:
    // mtc2        $26, $v18[8]
    rsp.MTC2<8>(r26, rsp.vpu.r[18]);
L_1928:
    // addi        $10, $zero, 0x40
    r10 = RSP_ADD32(0, 0X40);
L_192C:
    // mtc2        $10, $v18[10]
    rsp.MTC2<10>(r10, rsp.vpu.r[18]);
L_1930:
    // addi        $9, $zero, 0x40
    r9 = RSP_ADD32(0, 0X40);
L_1934:
    // lqv         $v31[0], 0x10($9)
    rsp.LQV<0>(rsp.vpu.r[31], r9, 0X1);
L_1938:
    // lqv         $v25[0], 0x0($9)
    rsp.LQV<0>(rsp.vpu.r[25], r9, 0X0);
L_193C:
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
L_1940:
    // lqv         $v30[0], 0x20($9)
    rsp.LQV<0>(rsp.vpu.r[30], r9, 0X2);
L_1944:
    // lqv         $v29[0], 0x30($9)
    rsp.LQV<0>(rsp.vpu.r[29], r9, 0X3);
L_1948:
    // lqv         $v28[0], 0x40($9)
    rsp.LQV<0>(rsp.vpu.r[28], r9, 0X4);
L_194C:
    // lqv         $v27[0], 0x50($9)
    rsp.LQV<0>(rsp.vpu.r[27], r9, 0X5);
L_1950:
    // lqv         $v26[0], 0x60($9)
    rsp.LQV<0>(rsp.vpu.r[26], r9, 0X6);
L_1954:
    // vsub        $v25, $v25, $v31
    rsp.VSUB<0>(rsp.vpu.r[25], rsp.vpu.r[25], rsp.vpu.r[31]);
L_1958:
    // lqv         $v24[0], 0x70($9)
    rsp.LQV<0>(rsp.vpu.r[24], r9, 0X7);
L_195C:
    // addi        $21, $23, 0x20
    r21 = RSP_ADD32(r23, 0X20);
L_1960:
    // addi        $20, $23, 0x30
    r20 = RSP_ADD32(r23, 0X30);
L_1964:
    // vxor        $v22, $v22, $v22
    rsp.VXOR<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[22]);
L_1968:
    // vmudm       $v23, $v31, $v23[7]
    rsp.VMUDM<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[23]);
L_196C:
    // vmadm       $v22, $v25, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[22], rsp.vpu.r[25], rsp.vpu.r[18]);
L_1970:
    // vmadn       $v23, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[30]);
L_1974:
    // vmudn       $v21, $v31, $v18[2]
    rsp.VMUDN<10>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[18]);
L_1978:
    // vmadn       $v21, $v22, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[21], rsp.vpu.r[22], rsp.vpu.r[30]);
L_197C:
    // vmudl       $v17, $v23, $v18[5]
    rsp.VMUDL<13>(rsp.vpu.r[17], rsp.vpu.r[23], rsp.vpu.r[18]);
L_1980:
    // vmudn       $v17, $v17, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[30]);
L_1984:
    // vmadn       $v17, $v31, $v18[3]
    rsp.VMADN<11>(rsp.vpu.r[17], rsp.vpu.r[31], rsp.vpu.r[18]);
L_1988:
    // lqv         $v25[0], 0x0($9)
    rsp.LQV<0>(rsp.vpu.r[25], r9, 0X0);
L_198C:
    // sqv         $v21[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[21], r21, 0X0);
L_1990:
    // sqv         $v17[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[17], r20, 0X0);
L_1994:
    // ssv         $v23[7], 0x8($23)
    rsp.SSV<7>(rsp.vpu.r[23], r23, 0X4);
L_1998:
    // lh          $17, 0x0($21)
    r17 = RSP_MEM_H_LOAD(0X0, r21);
L_199C:
    // lh          $9, 0x0($20)
    r9 = RSP_MEM_H_LOAD(0X0, r20);
L_19A0:
    // lh          $13, 0x8($21)
    r13 = RSP_MEM_H_LOAD(0X8, r21);
L_19A4:
    // lh          $5, 0x8($20)
    r5 = RSP_MEM_H_LOAD(0X8, r20);
L_19A8:
    // lh          $16, 0x2($21)
    r16 = RSP_MEM_H_LOAD(0X2, r21);
L_19AC:
    // lh          $8, 0x2($20)
    r8 = RSP_MEM_H_LOAD(0X2, r20);
L_19B0:
    // lh          $12, 0xA($21)
    r12 = RSP_MEM_H_LOAD(0XA, r21);
L_19B4:
    // lh          $4, 0xA($20)
    r4 = RSP_MEM_H_LOAD(0XA, r20);
L_19B8:
    // lh          $15, 0x4($21)
    r15 = RSP_MEM_H_LOAD(0X4, r21);
L_19BC:
    // lh          $7, 0x4($20)
    r7 = RSP_MEM_H_LOAD(0X4, r20);
L_19C0:
    // lh          $11, 0xC($21)
    r11 = RSP_MEM_H_LOAD(0XC, r21);
L_19C4:
    // lh          $3, 0xC($20)
    r3 = RSP_MEM_H_LOAD(0XC, r20);
L_19C8:
    // lh          $14, 0x6($21)
    r14 = RSP_MEM_H_LOAD(0X6, r21);
L_19CC:
    // lh          $6, 0x6($20)
    r6 = RSP_MEM_H_LOAD(0X6, r20);
L_19D0:
    // lh          $10, 0xE($21)
    r10 = RSP_MEM_H_LOAD(0XE, r21);
L_19D4:
    // lh          $2, 0xE($20)
    r2 = RSP_MEM_H_LOAD(0XE, r20);
L_19D8:
    // ldv         $v16[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[16], r17, 0X0);
L_19DC:
    // vmudm       $v23, $v31, $v23[7]
    rsp.VMUDM<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[23]);
L_19E0:
    // ldv         $v15[0], 0x0($9)
    rsp.LDV<0>(rsp.vpu.r[15], r9, 0X0);
L_19E4:
    // vmadh       $v23, $v31, $v22[7]
    rsp.VMADH<15>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[22]);
L_19E8:
    // ldv         $v16[8], 0x0($13)
    rsp.LDV<8>(rsp.vpu.r[16], r13, 0X0);
L_19EC:
    // vmadm       $v22, $v25, $v18[4]
    rsp.VMADM<12>(rsp.vpu.r[22], rsp.vpu.r[25], rsp.vpu.r[18]);
L_19F0:
    // ldv         $v15[8], 0x0($5)
    rsp.LDV<8>(rsp.vpu.r[15], r5, 0X0);
L_19F4:
    // vmadn       $v23, $v31, $v30[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[30]);
L_19F8:
    // ldv         $v14[0], 0x0($16)
    rsp.LDV<0>(rsp.vpu.r[14], r16, 0X0);
L_19FC:
    // vmudn       $v21, $v31, $v18[2]
    rsp.VMUDN<10>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[18]);
L_1A00:
    // ldv         $v13[0], 0x0($8)
    rsp.LDV<0>(rsp.vpu.r[13], r8, 0X0);
L_1A04:
    // vmadn       $v21, $v22, $v30[2]
    rsp.VMADN<10>(rsp.vpu.r[21], rsp.vpu.r[22], rsp.vpu.r[30]);
L_1A08:
    // ldv         $v14[8], 0x0($12)
    rsp.LDV<8>(rsp.vpu.r[14], r12, 0X0);
L_1A0C:
    // vmudl       $v17, $v23, $v18[5]
    rsp.VMUDL<13>(rsp.vpu.r[17], rsp.vpu.r[23], rsp.vpu.r[18]);
L_1A10:
    // ldv         $v13[8], 0x0($4)
    rsp.LDV<8>(rsp.vpu.r[13], r4, 0X0);
L_1A14:
    // ldv         $v12[0], 0x0($15)
    rsp.LDV<0>(rsp.vpu.r[12], r15, 0X0);
L_1A18:
    // ldv         $v11[0], 0x0($7)
    rsp.LDV<0>(rsp.vpu.r[11], r7, 0X0);
L_1A1C:
    // ldv         $v12[8], 0x0($11)
    rsp.LDV<8>(rsp.vpu.r[12], r11, 0X0);
L_1A20:
    // vmudn       $v17, $v17, $v30[4]
    rsp.VMUDN<12>(rsp.vpu.r[17], rsp.vpu.r[17], rsp.vpu.r[30]);
L_1A24:
    // ldv         $v11[8], 0x0($3)
    rsp.LDV<8>(rsp.vpu.r[11], r3, 0X0);
L_1A28:
    // ldv         $v10[0], 0x0($14)
    rsp.LDV<0>(rsp.vpu.r[10], r14, 0X0);
L_1A2C:
    // ldv         $v9[0], 0x0($6)
    rsp.LDV<0>(rsp.vpu.r[9], r6, 0X0);
L_1A30:
    // vmadn       $v17, $v31, $v18[3]
    rsp.VMADN<11>(rsp.vpu.r[17], rsp.vpu.r[31], rsp.vpu.r[18]);
L_1A34:
    // ldv         $v10[8], 0x0($10)
    rsp.LDV<8>(rsp.vpu.r[10], r10, 0X0);
L_1A38:
    // vmulf       $v8, $v16, $v15
    rsp.VMULF<0>(rsp.vpu.r[8], rsp.vpu.r[16], rsp.vpu.r[15]);
L_1A3C:
    // ldv         $v9[8], 0x0($2)
    rsp.LDV<8>(rsp.vpu.r[9], r2, 0X0);
L_1A40:
    // vmulf       $v7, $v14, $v13
    rsp.VMULF<0>(rsp.vpu.r[7], rsp.vpu.r[14], rsp.vpu.r[13]);
L_1A44:
    // sqv         $v21[0], 0x0($21)
    rsp.SQV<0>(rsp.vpu.r[21], r21, 0X0);
L_1A48:
    // vmulf       $v6, $v12, $v11
    rsp.VMULF<0>(rsp.vpu.r[6], rsp.vpu.r[12], rsp.vpu.r[11]);
L_1A4C:
    // sqv         $v17[0], 0x0($20)
    rsp.SQV<0>(rsp.vpu.r[17], r20, 0X0);
L_1A50:
    // lh          $17, 0x0($21)
    r17 = RSP_MEM_H_LOAD(0X0, r21);
L_1A54:
    // vmulf       $v5, $v10, $v9
    rsp.VMULF<0>(rsp.vpu.r[5], rsp.vpu.r[10], rsp.vpu.r[9]);
L_1A58:
    // lh          $9, 0x0($20)
    r9 = RSP_MEM_H_LOAD(0X0, r20);
L_1A5C:
    // vadd        $v8, $v8, $v8[1q]
    rsp.VADD<3>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
L_1A60:
    // lh          $13, 0x8($21)
    r13 = RSP_MEM_H_LOAD(0X8, r21);
L_1A64:
    // vadd        $v7, $v7, $v7[1q]
    rsp.VADD<3>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[7]);
L_1A68:
    // lh          $5, 0x8($20)
    r5 = RSP_MEM_H_LOAD(0X8, r20);
L_1A6C:
    // vadd        $v6, $v6, $v6[1q]
    rsp.VADD<3>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[6]);
L_1A70:
    // lh          $16, 0x2($21)
    r16 = RSP_MEM_H_LOAD(0X2, r21);
L_1A74:
    // vadd        $v5, $v5, $v5[1q]
    rsp.VADD<3>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[5]);
L_1A78:
    // lh          $8, 0x2($20)
    r8 = RSP_MEM_H_LOAD(0X2, r20);
L_1A7C:
    // vadd        $v8, $v8, $v8[2h]
    rsp.VADD<6>(rsp.vpu.r[8], rsp.vpu.r[8], rsp.vpu.r[8]);
L_1A80:
    // lh          $12, 0xA($21)
    r12 = RSP_MEM_H_LOAD(0XA, r21);
L_1A84:
    // vadd        $v7, $v7, $v7[2h]
    rsp.VADD<6>(rsp.vpu.r[7], rsp.vpu.r[7], rsp.vpu.r[7]);
L_1A88:
    // lh          $4, 0xA($20)
    r4 = RSP_MEM_H_LOAD(0XA, r20);
L_1A8C:
    // vadd        $v6, $v6, $v6[2h]
    rsp.VADD<6>(rsp.vpu.r[6], rsp.vpu.r[6], rsp.vpu.r[6]);
L_1A90:
    // lh          $15, 0x4($21)
    r15 = RSP_MEM_H_LOAD(0X4, r21);
L_1A94:
    // vadd        $v5, $v5, $v5[2h]
    rsp.VADD<6>(rsp.vpu.r[5], rsp.vpu.r[5], rsp.vpu.r[5]);
L_1A98:
    // lh          $7, 0x4($20)
    r7 = RSP_MEM_H_LOAD(0X4, r20);
L_1A9C:
    // vmudn       $v4, $v29, $v8[0h]
    rsp.VMUDN<4>(rsp.vpu.r[4], rsp.vpu.r[29], rsp.vpu.r[8]);
L_1AA0:
    // lh          $11, 0xC($21)
    r11 = RSP_MEM_H_LOAD(0XC, r21);
L_1AA4:
    // vmadn       $v4, $v28, $v7[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[28], rsp.vpu.r[7]);
L_1AA8:
    // lh          $3, 0xC($20)
    r3 = RSP_MEM_H_LOAD(0XC, r20);
L_1AAC:
    // vmadn       $v4, $v27, $v6[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[27], rsp.vpu.r[6]);
L_1AB0:
    // lh          $14, 0x6($21)
    r14 = RSP_MEM_H_LOAD(0X6, r21);
L_1AB4:
    // vmadn       $v4, $v26, $v5[0h]
    rsp.VMADN<4>(rsp.vpu.r[4], rsp.vpu.r[26], rsp.vpu.r[5]);
L_1AB8:
    // lh          $6, 0x6($20)
    r6 = RSP_MEM_H_LOAD(0X6, r20);
L_1ABC:
    // lh          $10, 0xE($21)
    r10 = RSP_MEM_H_LOAD(0XE, r21);
L_1AC0:
    // addi        $18, $18, -0x10
    r18 = RSP_ADD32(r18, -0X10);
L_1AC4:
    // sqv         $v4[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[4], r19, 0X0);
L_1AC8:
    // blez        $18, L_1AD8
    if (RSP_SIGNED(r18) <= 0) {
        // lh          $2, 0xE($20)
        r2 = RSP_MEM_H_LOAD(0XE, r20);
        goto L_1AD8;
    }
L_1ACC:
    // lh          $2, 0xE($20)
    r2 = RSP_MEM_H_LOAD(0XE, r20);
L_1AD0:
    // j           L_19D8
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
    goto L_19D8;
L_1AD4:
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
L_1AD8:
    // ssv         $v23[0], 0x8($23)
    rsp.SSV<0>(rsp.vpu.r[23], r23, 0X4);
L_1ADC:
    // ldv         $v16[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[16], r17, 0X0);
L_1AE0:
    // sdv         $v16[0], 0x0($23)
    rsp.SDV<0>(rsp.vpu.r[16], r23, 0X0);
L_1AE4:
    // lh          $6, 0x0($24)
    r6 = RSP_MEM_H_LOAD(0X0, r24);
L_1AE8:
    // addi        $17, $17, 0x8
    r17 = RSP_ADD32(r17, 0X8);
L_1AEC:
    // sub         $5, $17, $6
    r5 = RSP_SUB32(r17, r6);
L_1AF0:
    // andi        $4, $5, 0xF
    r4 = r5 & 0XF;
L_1AF4:
    // sub         $17, $17, $4
    r17 = RSP_SUB32(r17, r4);
L_1AF8:
    // beq         $4, $zero, L_1B04
    if (r4 == 0) {
        // addi        $7, $zero, 0x10
        r7 = RSP_ADD32(0, 0X10);
        goto L_1B04;
    }
L_1AFC:
    // addi        $7, $zero, 0x10
    r7 = RSP_ADD32(0, 0X10);
L_1B00:
    // sub         $4, $7, $4
    r4 = RSP_SUB32(r7, r4);
L_1B04:
    // sh          $4, 0xA($23)
    RSP_MEM_H_STORE(0XA, r23, r4);
L_1B08:
    // ldv         $v3[0], 0x0($17)
    rsp.LDV<0>(rsp.vpu.r[3], r17, 0X0);
L_1B0C:
    // ldv         $v3[8], 0x8($17)
    rsp.LDV<8>(rsp.vpu.r[3], r17, 0X1);
L_1B10:
    // sqv         $v3[0], 0x10($23)
    rsp.SQV<0>(rsp.vpu.r[3], r23, 0X1);
L_1B14:
    // lw          $2, 0x40($23)
    r2 = RSP_MEM_W_LOAD(0X40, r23);
L_1B18:
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
L_1B1C:
    // jal         0x11B0
    r31 = 0x1B24;
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
    goto L_11B0;
L_1B20:
    // addi        $3, $zero, 0x1F
    r3 = RSP_ADD32(0, 0X1F);
L_1B24:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1B28:
    // bne         $5, $zero, L_1B24
    if (r5 != 0) {
        // nop
    
        goto L_1B24;
    }
L_1B2C:
    // nop

L_1B30:
    // j           L_1118
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1118;
L_1B34:
    // mtc0        $zero, SP_SEMAPHORE
L_1B38:
    // lui         $4, 0xFF
    r4 = S32(0XFF << 16);
L_1B3C:
    // ori         $4, $4, 0xFFFF
    r4 = r4 | 0XFFFF;
L_1B40:
    // and         $2, $25, $4
    r2 = r25 & r4;
L_1B44:
    // srl         $5, $25, 24
    r5 = S32(U32(r25) >> 24);
L_1B48:
    // sll         $5, $5, 2
    r5 = S32(r5) << 2;
L_1B4C:
    // lw          $6, 0x320($5)
    r6 = RSP_MEM_W_LOAD(0X320, r5);
L_1B50:
    // add         $2, $2, $6
    r2 = RSP_ADD32(r2, r6);
L_1B54:
    // addi        $1, $23, 0x0
    r1 = RSP_ADD32(r23, 0X0);
L_1B58:
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
L_1B5C:
    // vxor        $v0, $v0, $v0
    rsp.VXOR<0>(rsp.vpu.r[0], rsp.vpu.r[0], rsp.vpu.r[0]);
L_1B60:
    // addi        $11, $zero, 0x40
    r11 = RSP_ADD32(0, 0X40);
L_1B64:
    // lqv         $v31[0], 0x10($11)
    rsp.LQV<0>(rsp.vpu.r[31], r11, 0X1);
L_1B68:
    // lqv         $v10[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[10], 0, 0X0);
L_1B6C:
    // srl         $12, $26, 16
    r12 = S32(U32(r26) >> 16);
L_1B70:
    // andi        $10, $12, 0x1
    r10 = r12 & 0X1;
L_1B74:
    // beq         $10, $zero, L_1B84
    if (r10 == 0) {
        // lqv         $v24[0], 0x10($24)
        rsp.LQV<0>(rsp.vpu.r[24], r24, 0X1);
        goto L_1B84;
    }
L_1B78:
    // lqv         $v24[0], 0x10($24)
    rsp.LQV<0>(rsp.vpu.r[24], r24, 0X1);
L_1B7C:
    // j           L_1BB0
    // nop

    goto L_1BB0;
L_1B80:
    // nop

L_1B84:
    // jal         0x1184
    r31 = 0x1B8C;
    // nop

    goto L_1184;
L_1B88:
    // nop

L_1B8C:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1B90:
    // bne         $5, $zero, L_1B8C
    if (r5 != 0) {
        // nop
    
        goto L_1B8C;
    }
L_1B94:
    // nop

L_1B98:
    // mtc0        $zero, SP_SEMAPHORE
L_1B9C:
    // lqv         $v20[0], 0x0($23)
    rsp.LQV<0>(rsp.vpu.r[20], r23, 0X0);
L_1BA0:
    // lqv         $v21[0], 0x10($23)
    rsp.LQV<0>(rsp.vpu.r[21], r23, 0X1);
L_1BA4:
    // lqv         $v18[0], 0x20($23)
    rsp.LQV<0>(rsp.vpu.r[18], r23, 0X2);
L_1BA8:
    // lqv         $v19[0], 0x30($23)
    rsp.LQV<0>(rsp.vpu.r[19], r23, 0X3);
L_1BAC:
    // lqv         $v24[0], 0x40($23)
    rsp.LQV<0>(rsp.vpu.r[24], r23, 0X4);
L_1BB0:
    // lh          $13, 0x0($24)
    r13 = RSP_MEM_H_LOAD(0X0, r24);
L_1BB4:
    // lh          $19, 0x2($24)
    r19 = RSP_MEM_H_LOAD(0X2, r24);
L_1BB8:
    // lh          $18, 0xA($24)
    r18 = RSP_MEM_H_LOAD(0XA, r24);
L_1BBC:
    // lh          $17, 0xC($24)
    r17 = RSP_MEM_H_LOAD(0XC, r24);
L_1BC0:
    // lh          $16, 0xE($24)
    r16 = RSP_MEM_H_LOAD(0XE, r24);
L_1BC4:
    // lh          $14, 0x4($24)
    r14 = RSP_MEM_H_LOAD(0X4, r24);
L_1BC8:
    // addi        $15, $zero, 0x10
    r15 = RSP_ADD32(0, 0X10);
L_1BCC:
    // mfc2        $21, $v24[2]
    rsp.MFC2<2>(r21, rsp.vpu.r[24]);
L_1BD0:
    // mfc2        $20, $v24[8]
    rsp.MFC2<8>(r20, rsp.vpu.r[24]);
L_1BD4:
    // andi        $9, $12, 0x8
    r9 = r12 & 0X8;
L_1BD8:
    // bgtz        $9, L_1BEC
    if (RSP_SIGNED(r9) > 0) {
        // nop
    
        goto L_1BEC;
    }
L_1BDC:
    // nop

L_1BE0:
    // addi        $17, $23, 0x50
    r17 = RSP_ADD32(r23, 0X50);
L_1BE4:
    // add         $16, $zero, $17
    r16 = RSP_ADD32(0, r17);
L_1BE8:
    // addi        $15, $zero, 0x0
    r15 = RSP_ADD32(0, 0X0);
L_1BEC:
    // beq         $10, $zero, L_1CF0
    if (r10 == 0) {
        // lqv         $v30[0], 0x70($11)
        rsp.LQV<0>(rsp.vpu.r[30], r11, 0X7);
        goto L_1CF0;
    }
L_1BF0:
    // lqv         $v30[0], 0x70($11)
    rsp.LQV<0>(rsp.vpu.r[30], r11, 0X7);
L_1BF4:
    // lqv         $v17[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[17], r13, 0X0);
L_1BF8:
    // lqv         $v29[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[29], r19, 0X0);
L_1BFC:
    // lqv         $v27[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[27], r17, 0X0);
L_1C00:
    // vxor        $v21, $v21, $v21
    rsp.VXOR<0>(rsp.vpu.r[21], rsp.vpu.r[21], rsp.vpu.r[21]);
L_1C04:
    // lsv         $v20[14], 0x6($24)
    rsp.LSV<14>(rsp.vpu.r[20], r24, 0X3);
L_1C08:
    // vmudm       $v23, $v20, $v24[2]
    rsp.VMUDM<10>(rsp.vpu.r[23], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1C0C:
    // vmadh       $v22, $v20, $v24[1]
    rsp.VMADH<9>(rsp.vpu.r[22], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1C10:
    // vmadn       $v23, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1C14:
    // vsubc       $v23, $v23, $v21
    rsp.VSUBC<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[21]);
L_1C18:
    // vsub        $v22, $v22, $v20
    rsp.VSUB<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[20]);
L_1C1C:
    // vmudl       $v23, $v30, $v23[7]
    rsp.VMUDL<15>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[23]);
L_1C20:
    // vmadn       $v23, $v30, $v22[7]
    rsp.VMADN<15>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[22]);
L_1C24:
    // vmadm       $v22, $v31, $v0[0]
    rsp.VMADM<8>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1C28:
    // vmadm       $v21, $v31, $v21[7]
    rsp.VMADM<15>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[21]);
L_1C2C:
    // vmadh       $v20, $v31, $v20[7]
    rsp.VMADH<15>(rsp.vpu.r[20], rsp.vpu.r[31], rsp.vpu.r[20]);
L_1C30:
    // bgtz        $21, L_1C44
    if (RSP_SIGNED(r21) > 0) {
        // vmadn       $v21, $v31, $v0[0]
        rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
        goto L_1C44;
    }
L_1C34:
    // vmadn       $v21, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1C38:
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1C3C:
    // j           L_1C48
    // nop

    goto L_1C48;
L_1C40:
    // nop

L_1C44:
    // vcl         $v20, $v20, $v24[0]
    rsp.VCL<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1C48:
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1C4C:
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1C50:
    // vmulf       $v29, $v29, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
L_1C54:
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
L_1C58:
    // vmulf       $v27, $v27, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
L_1C5C:
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
L_1C60:
    // sqv         $v29[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[29], r19, 0X0);
L_1C64:
    // sqv         $v27[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[27], r17, 0X0);
L_1C68:
    // lqv         $v28[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[28], r18, 0X0);
L_1C6C:
    // lqv         $v26[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[26], r16, 0X0);
L_1C70:
    // vxor        $v19, $v19, $v19
    rsp.VXOR<0>(rsp.vpu.r[19], rsp.vpu.r[19], rsp.vpu.r[19]);
L_1C74:
    // lsv         $v18[14], 0x8($24)
    rsp.LSV<14>(rsp.vpu.r[18], r24, 0X4);
L_1C78:
    // vmudm       $v23, $v18, $v24[5]
    rsp.VMUDM<13>(rsp.vpu.r[23], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1C7C:
    // vmadh       $v22, $v18, $v24[4]
    rsp.VMADH<12>(rsp.vpu.r[22], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1C80:
    // vmadn       $v23, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[23], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1C84:
    // vsubc       $v23, $v23, $v19
    rsp.VSUBC<0>(rsp.vpu.r[23], rsp.vpu.r[23], rsp.vpu.r[19]);
L_1C88:
    // vsub        $v22, $v22, $v18
    rsp.VSUB<0>(rsp.vpu.r[22], rsp.vpu.r[22], rsp.vpu.r[18]);
L_1C8C:
    // vmudl       $v23, $v30, $v23[7]
    rsp.VMUDL<15>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[23]);
L_1C90:
    // vmadn       $v23, $v30, $v22[7]
    rsp.VMADN<15>(rsp.vpu.r[23], rsp.vpu.r[30], rsp.vpu.r[22]);
L_1C94:
    // vmadm       $v22, $v31, $v0[0]
    rsp.VMADM<8>(rsp.vpu.r[22], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1C98:
    // vmadm       $v19, $v31, $v19[7]
    rsp.VMADM<15>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[19]);
L_1C9C:
    // vmadh       $v18, $v31, $v18[7]
    rsp.VMADH<15>(rsp.vpu.r[18], rsp.vpu.r[31], rsp.vpu.r[18]);
L_1CA0:
    // bgtz        $20, L_1CB4
    if (RSP_SIGNED(r20) > 0) {
        // vmadn       $v19, $v31, $v0[0]
        rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
        goto L_1CB4;
    }
L_1CA4:
    // vmadn       $v19, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1CA8:
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1CAC:
    // j           L_1CB8
    // nop

    goto L_1CB8;
L_1CB0:
    // nop

L_1CB4:
    // vcl         $v18, $v18, $v24[3]
    rsp.VCL<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1CB8:
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1CBC:
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1CC0:
    // vmulf       $v28, $v28, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
L_1CC4:
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
L_1CC8:
    // vmulf       $v26, $v26, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
L_1CCC:
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
L_1CD0:
    // sqv         $v28[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[28], r18, 0X0);
L_1CD4:
    // sqv         $v26[0], 0x0($16)
    rsp.SQV<0>(rsp.vpu.r[26], r16, 0X0);
L_1CD8:
    // addi        $14, $14, -0x10
    r14 = RSP_ADD32(r14, -0X10);
L_1CDC:
    // addi        $13, $13, 0x10
    r13 = RSP_ADD32(r13, 0X10);
L_1CE0:
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
L_1CE4:
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
L_1CE8:
    // add         $17, $17, $15
    r17 = RSP_ADD32(r17, r15);
L_1CEC:
    // add         $16, $16, $15
    r16 = RSP_ADD32(r16, r15);
L_1CF0:
    // vmudl       $v23, $v21, $v24[2]
    rsp.VMUDL<10>(rsp.vpu.r[23], rsp.vpu.r[21], rsp.vpu.r[24]);
L_1CF4:
    // vmadm       $v23, $v20, $v24[2]
    rsp.VMADM<10>(rsp.vpu.r[23], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1CF8:
    // vmadn       $v23, $v21, $v24[1]
    rsp.VMADN<9>(rsp.vpu.r[23], rsp.vpu.r[21], rsp.vpu.r[24]);
L_1CFC:
    // vmadh       $v20, $v20, $v24[1]
    rsp.VMADH<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1D00:
    // vmadn       $v21, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1D04:
    // bgtz        $21, L_1D30
    if (RSP_SIGNED(r21) > 0) {
        // lqv         $v17[0], 0x0($13)
        rsp.LQV<0>(rsp.vpu.r[17], r13, 0X0);
        goto L_1D30;
    }
L_1D08:
    // lqv         $v17[0], 0x0($13)
    rsp.LQV<0>(rsp.vpu.r[17], r13, 0X0);
L_1D0C:
    // vge         $v20, $v20, $v24[0]
    rsp.VGE<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1D10:
    // vmudl       $v23, $v19, $v24[5]
    rsp.VMUDL<13>(rsp.vpu.r[23], rsp.vpu.r[19], rsp.vpu.r[24]);
L_1D14:
    // vmadm       $v23, $v18, $v24[5]
    rsp.VMADM<13>(rsp.vpu.r[23], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1D18:
    // vmadn       $v23, $v19, $v24[4]
    rsp.VMADN<12>(rsp.vpu.r[23], rsp.vpu.r[19], rsp.vpu.r[24]);
L_1D1C:
    // lqv         $v29[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[29], r19, 0X0);
L_1D20:
    // vmadh       $v18, $v18, $v24[4]
    rsp.VMADH<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1D24:
    // lqv         $v27[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[27], r17, 0X0);
L_1D28:
    // j           L_1D50
    // vmadn       $v19, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
    goto L_1D50;
L_1D2C:
    // vmadn       $v19, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1D30:
    // vcl         $v20, $v20, $v24[0]
    rsp.VCL<8>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1D34:
    // vmudl       $v23, $v19, $v24[5]
    rsp.VMUDL<13>(rsp.vpu.r[23], rsp.vpu.r[19], rsp.vpu.r[24]);
L_1D38:
    // vmadm       $v23, $v18, $v24[5]
    rsp.VMADM<13>(rsp.vpu.r[23], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1D3C:
    // vmadn       $v23, $v19, $v24[4]
    rsp.VMADN<12>(rsp.vpu.r[23], rsp.vpu.r[19], rsp.vpu.r[24]);
L_1D40:
    // lqv         $v29[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[29], r19, 0X0);
L_1D44:
    // vmadh       $v18, $v18, $v24[4]
    rsp.VMADH<12>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1D48:
    // lqv         $v27[0], 0x0($17)
    rsp.LQV<0>(rsp.vpu.r[27], r17, 0X0);
L_1D4C:
    // vmadn       $v19, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[19], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1D50:
    // vmulf       $v16, $v20, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1D54:
    // sqv         $v20[0], 0x0($23)
    rsp.SQV<0>(rsp.vpu.r[20], r23, 0X0);
L_1D58:
    // vmulf       $v15, $v20, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1D5C:
    // sqv         $v21[0], 0x10($23)
    rsp.SQV<0>(rsp.vpu.r[21], r23, 0X1);
L_1D60:
    // vmulf       $v29, $v29, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[29], rsp.vpu.r[29], rsp.vpu.r[10]);
L_1D64:
    // vmacf       $v29, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[29], rsp.vpu.r[17], rsp.vpu.r[16]);
L_1D68:
    // lqv         $v28[0], 0x0($18)
    rsp.LQV<0>(rsp.vpu.r[28], r18, 0X0);
L_1D6C:
    // vmulf       $v27, $v27, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[10]);
L_1D70:
    // lqv         $v26[0], 0x0($16)
    rsp.LQV<0>(rsp.vpu.r[26], r16, 0X0);
L_1D74:
    // vmacf       $v27, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[27], rsp.vpu.r[17], rsp.vpu.r[15]);
L_1D78:
    // bgtz        $20, L_1DA0
    if (RSP_SIGNED(r20) > 0) {
        // sqv         $v29[0], 0x0($19)
        rsp.SQV<0>(rsp.vpu.r[29], r19, 0X0);
        goto L_1DA0;
    }
L_1D7C:
    // sqv         $v29[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[29], r19, 0X0);
L_1D80:
    // vge         $v18, $v18, $v24[3]
    rsp.VGE<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1D84:
    // vmudl       $v23, $v21, $v24[2]
    rsp.VMUDL<10>(rsp.vpu.r[23], rsp.vpu.r[21], rsp.vpu.r[24]);
L_1D88:
    // sqv         $v27[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[27], r17, 0X0);
L_1D8C:
    // vmadm       $v23, $v20, $v24[2]
    rsp.VMADM<10>(rsp.vpu.r[23], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1D90:
    // vmadn       $v23, $v21, $v24[1]
    rsp.VMADN<9>(rsp.vpu.r[23], rsp.vpu.r[21], rsp.vpu.r[24]);
L_1D94:
    // vmadh       $v20, $v20, $v24[1]
    rsp.VMADH<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1D98:
    // j           L_1DBC
    // vmadn       $v21, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
    goto L_1DBC;
L_1D9C:
    // vmadn       $v21, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1DA0:
    // vcl         $v18, $v18, $v24[3]
    rsp.VCL<11>(rsp.vpu.r[18], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1DA4:
    // vmudl       $v23, $v21, $v24[2]
    rsp.VMUDL<10>(rsp.vpu.r[23], rsp.vpu.r[21], rsp.vpu.r[24]);
L_1DA8:
    // sqv         $v27[0], 0x0($17)
    rsp.SQV<0>(rsp.vpu.r[27], r17, 0X0);
L_1DAC:
    // vmadm       $v23, $v20, $v24[2]
    rsp.VMADM<10>(rsp.vpu.r[23], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1DB0:
    // vmadn       $v23, $v21, $v24[1]
    rsp.VMADN<9>(rsp.vpu.r[23], rsp.vpu.r[21], rsp.vpu.r[24]);
L_1DB4:
    // vmadh       $v20, $v20, $v24[1]
    rsp.VMADH<9>(rsp.vpu.r[20], rsp.vpu.r[20], rsp.vpu.r[24]);
L_1DB8:
    // vmadn       $v21, $v31, $v0[0]
    rsp.VMADN<8>(rsp.vpu.r[21], rsp.vpu.r[31], rsp.vpu.r[0]);
L_1DBC:
    // vmulf       $v16, $v18, $v24[6]
    rsp.VMULF<14>(rsp.vpu.r[16], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1DC0:
    // addi        $14, $14, -0x10
    r14 = RSP_ADD32(r14, -0X10);
L_1DC4:
    // vmulf       $v15, $v18, $v24[7]
    rsp.VMULF<15>(rsp.vpu.r[15], rsp.vpu.r[18], rsp.vpu.r[24]);
L_1DC8:
    // addi        $19, $19, 0x10
    r19 = RSP_ADD32(r19, 0X10);
L_1DCC:
    // vmulf       $v28, $v28, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[28], rsp.vpu.r[28], rsp.vpu.r[10]);
L_1DD0:
    // add         $17, $17, $15
    r17 = RSP_ADD32(r17, r15);
L_1DD4:
    // vmacf       $v28, $v17, $v16
    rsp.VMACF<0>(rsp.vpu.r[28], rsp.vpu.r[17], rsp.vpu.r[16]);
L_1DD8:
    // addi        $13, $13, 0x10
    r13 = RSP_ADD32(r13, 0X10);
L_1DDC:
    // vmulf       $v26, $v26, $v10[6]
    rsp.VMULF<14>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[10]);
L_1DE0:
    // vmacf       $v26, $v17, $v15
    rsp.VMACF<0>(rsp.vpu.r[26], rsp.vpu.r[17], rsp.vpu.r[15]);
L_1DE4:
    // sqv         $v28[0], 0x0($18)
    rsp.SQV<0>(rsp.vpu.r[28], r18, 0X0);
L_1DE8:
    // addi        $18, $18, 0x10
    r18 = RSP_ADD32(r18, 0X10);
L_1DEC:
    // blez        $14, L_1DFC
    if (RSP_SIGNED(r14) <= 0) {
        // sqv         $v26[0], 0x0($16)
        rsp.SQV<0>(rsp.vpu.r[26], r16, 0X0);
        goto L_1DFC;
    }
L_1DF0:
    // sqv         $v26[0], 0x0($16)
    rsp.SQV<0>(rsp.vpu.r[26], r16, 0X0);
L_1DF4:
    // j           L_1D04
    // add         $16, $16, $15
    r16 = RSP_ADD32(r16, r15);
    goto L_1D04;
L_1DF8:
    // add         $16, $16, $15
    r16 = RSP_ADD32(r16, r15);
L_1DFC:
    // sqv         $v18[0], 0x20($23)
    rsp.SQV<0>(rsp.vpu.r[18], r23, 0X2);
L_1E00:
    // sqv         $v19[0], 0x30($23)
    rsp.SQV<0>(rsp.vpu.r[19], r23, 0X3);
L_1E04:
    // sqv         $v24[0], 0x40($23)
    rsp.SQV<0>(rsp.vpu.r[24], r23, 0X4);
L_1E08:
    // jal         0x11B0
    r31 = 0x1E10;
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
    goto L_11B0;
L_1E0C:
    // addi        $3, $zero, 0x4F
    r3 = RSP_ADD32(0, 0X4F);
L_1E10:
    // mfc0        $5, SP_DMA_BUSY
    r5 = 0;
L_1E14:
    // bne         $5, $zero, L_1E10
    if (r5 != 0) {
        // nop
    
        goto L_1E10;
    }
L_1E18:
    // nop

L_1E1C:
    // j           L_1118
    // mtc0        $zero, SP_SEMAPHORE
    goto L_1118;
L_1E20:
    // mtc0        $zero, SP_SEMAPHORE
L_1E24:
    // lqv         $v31[0], 0x0($zero)
    rsp.LQV<0>(rsp.vpu.r[31], 0, 0X0);
L_1E28:
    // lhu         $18, 0x4($24)
    r18 = RSP_MEM_HU_LOAD(0X4, r24);
L_1E2C:
    // beq         $18, $zero, L_1E94
    if (r18 == 0) {
        // nop
    
        goto L_1E94;
    }
L_1E30:
    // nop

L_1E34:
    // andi        $19, $25, 0xFFFF
    r19 = r25 & 0XFFFF;
L_1E38:
    // addi        $19, $19, 0x5C0
    r19 = RSP_ADD32(r19, 0X5C0);
L_1E3C:
    // srl         $20, $25, 16
    r20 = S32(U32(r25) >> 16);
L_1E40:
    // addi        $20, $20, 0x5C0
    r20 = RSP_ADD32(r20, 0X5C0);
L_1E44:
    // andi        $17, $26, 0xFFFF
    r17 = r26 & 0XFFFF;
L_1E48:
    // mtc2        $17, $v30[0]
    rsp.MTC2<0>(r17, rsp.vpu.r[30]);
L_1E4C:
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
L_1E50:
    // lqv         $v29[0], 0x0($20)
    rsp.LQV<0>(rsp.vpu.r[29], r20, 0X0);
L_1E54:
    // lqv         $v26[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[26], r19, 0X1);
L_1E58:
    // lqv         $v28[0], 0x10($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X1);
L_1E5C:
    // vmulf       $v27, $v27, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[27], rsp.vpu.r[27], rsp.vpu.r[31]);
L_1E60:
    // addi        $18, $18, -0x20
    r18 = RSP_ADD32(r18, -0X20);
L_1E64:
    // vmacf       $v27, $v29, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[27], rsp.vpu.r[29], rsp.vpu.r[30]);
L_1E68:
    // addi        $20, $20, 0x20
    r20 = RSP_ADD32(r20, 0X20);
L_1E6C:
    // sqv         $v27[0], 0x0($19)
    rsp.SQV<0>(rsp.vpu.r[27], r19, 0X0);
L_1E70:
    // vmulf       $v26, $v26, $v31[6]
    rsp.VMULF<14>(rsp.vpu.r[26], rsp.vpu.r[26], rsp.vpu.r[31]);
L_1E74:
    // lqv         $v29[0], 0x0($20)
    rsp.LQV<0>(rsp.vpu.r[29], r20, 0X0);
L_1E78:
    // vmacf       $v26, $v28, $v30[0]
    rsp.VMACF<8>(rsp.vpu.r[26], rsp.vpu.r[28], rsp.vpu.r[30]);
L_1E7C:
    // lqv         $v28[0], 0x10($20)
    rsp.LQV<0>(rsp.vpu.r[28], r20, 0X1);
L_1E80:
    // sqv         $v26[0], 0x10($19)
    rsp.SQV<0>(rsp.vpu.r[26], r19, 0X1);
L_1E84:
    // addi        $19, $19, 0x20
    r19 = RSP_ADD32(r19, 0X20);
L_1E88:
    // lqv         $v27[0], 0x0($19)
    rsp.LQV<0>(rsp.vpu.r[27], r19, 0X0);
L_1E8C:
    // bgtz        $18, L_1E5C
    if (RSP_SIGNED(r18) > 0) {
        // lqv         $v26[0], 0x10($19)
        rsp.LQV<0>(rsp.vpu.r[26], r19, 0X1);
        goto L_1E5C;
    }
L_1E90:
    // lqv         $v26[0], 0x10($19)
    rsp.LQV<0>(rsp.vpu.r[26], r19, 0X1);
L_1E94:
    // j           L_1118
    // nop

    goto L_1118;
L_1E98:
    // nop

L_1E9C:
    // nop

    return RspExitReason::ImemOverrun;
do_indirect_jump:
    switch ((jump_target | 0x1000) & 0X1FFF) { 
        case 0x1E9C: goto L_1E9C;
        case 0x1E98: goto L_1E98;
        case 0x1E94: goto L_1E94;
        case 0x1E90: goto L_1E90;
        case 0x1E8C: goto L_1E8C;
        case 0x1E88: goto L_1E88;
        case 0x1E84: goto L_1E84;
        case 0x1E80: goto L_1E80;
        case 0x1E7C: goto L_1E7C;
        case 0x1E78: goto L_1E78;
        case 0x1E74: goto L_1E74;
        case 0x1E70: goto L_1E70;
        case 0x1E6C: goto L_1E6C;
        case 0x1E68: goto L_1E68;
        case 0x1E64: goto L_1E64;
        case 0x1E60: goto L_1E60;
        case 0x1E5C: goto L_1E5C;
        case 0x1E58: goto L_1E58;
        case 0x1E54: goto L_1E54;
        case 0x1E50: goto L_1E50;
        case 0x1E4C: goto L_1E4C;
        case 0x1E48: goto L_1E48;
        case 0x1E44: goto L_1E44;
        case 0x1E40: goto L_1E40;
        case 0x1E3C: goto L_1E3C;
        case 0x1E38: goto L_1E38;
        case 0x1E34: goto L_1E34;
        case 0x1E30: goto L_1E30;
        case 0x1E2C: goto L_1E2C;
        case 0x1E28: goto L_1E28;
        case 0x1E24: goto L_1E24;
        case 0x1E20: goto L_1E20;
        case 0x1E1C: goto L_1E1C;
        case 0x1E18: goto L_1E18;
        case 0x1E14: goto L_1E14;
        case 0x1E0C: goto L_1E0C;
        case 0x1E08: goto L_1E08;
        case 0x1E04: goto L_1E04;
        case 0x1E00: goto L_1E00;
        case 0x1DFC: goto L_1DFC;
        case 0x1DF8: goto L_1DF8;
        case 0x1DF4: goto L_1DF4;
        case 0x1DF0: goto L_1DF0;
        case 0x1DEC: goto L_1DEC;
        case 0x1DE8: goto L_1DE8;
        case 0x1DE4: goto L_1DE4;
        case 0x1DE0: goto L_1DE0;
        case 0x1DDC: goto L_1DDC;
        case 0x1DD8: goto L_1DD8;
        case 0x1DD4: goto L_1DD4;
        case 0x1DD0: goto L_1DD0;
        case 0x1DCC: goto L_1DCC;
        case 0x1DC8: goto L_1DC8;
        case 0x1DC4: goto L_1DC4;
        case 0x1DC0: goto L_1DC0;
        case 0x1DBC: goto L_1DBC;
        case 0x1DB8: goto L_1DB8;
        case 0x1DB4: goto L_1DB4;
        case 0x1DB0: goto L_1DB0;
        case 0x1DAC: goto L_1DAC;
        case 0x1DA8: goto L_1DA8;
        case 0x1DA4: goto L_1DA4;
        case 0x1DA0: goto L_1DA0;
        case 0x1D9C: goto L_1D9C;
        case 0x1D98: goto L_1D98;
        case 0x1D94: goto L_1D94;
        case 0x1D90: goto L_1D90;
        case 0x1D8C: goto L_1D8C;
        case 0x1D88: goto L_1D88;
        case 0x1D84: goto L_1D84;
        case 0x1D80: goto L_1D80;
        case 0x1D7C: goto L_1D7C;
        case 0x1D78: goto L_1D78;
        case 0x1D74: goto L_1D74;
        case 0x1D70: goto L_1D70;
        case 0x1D6C: goto L_1D6C;
        case 0x1D68: goto L_1D68;
        case 0x1D64: goto L_1D64;
        case 0x1D60: goto L_1D60;
        case 0x1D5C: goto L_1D5C;
        case 0x1D58: goto L_1D58;
        case 0x1D54: goto L_1D54;
        case 0x1D50: goto L_1D50;
        case 0x1D4C: goto L_1D4C;
        case 0x1D48: goto L_1D48;
        case 0x1D44: goto L_1D44;
        case 0x1D40: goto L_1D40;
        case 0x1D3C: goto L_1D3C;
        case 0x1D38: goto L_1D38;
        case 0x1D34: goto L_1D34;
        case 0x1D30: goto L_1D30;
        case 0x1D2C: goto L_1D2C;
        case 0x1D28: goto L_1D28;
        case 0x1D24: goto L_1D24;
        case 0x1D20: goto L_1D20;
        case 0x1D1C: goto L_1D1C;
        case 0x1D18: goto L_1D18;
        case 0x1D14: goto L_1D14;
        case 0x1D10: goto L_1D10;
        case 0x1D0C: goto L_1D0C;
        case 0x1D08: goto L_1D08;
        case 0x1D04: goto L_1D04;
        case 0x1D00: goto L_1D00;
        case 0x1CFC: goto L_1CFC;
        case 0x1CF8: goto L_1CF8;
        case 0x1CF4: goto L_1CF4;
        case 0x1CF0: goto L_1CF0;
        case 0x1CEC: goto L_1CEC;
        case 0x1CE8: goto L_1CE8;
        case 0x1CE4: goto L_1CE4;
        case 0x1CE0: goto L_1CE0;
        case 0x1CDC: goto L_1CDC;
        case 0x1CD8: goto L_1CD8;
        case 0x1CD4: goto L_1CD4;
        case 0x1CD0: goto L_1CD0;
        case 0x1CCC: goto L_1CCC;
        case 0x1CC8: goto L_1CC8;
        case 0x1CC4: goto L_1CC4;
        case 0x1CC0: goto L_1CC0;
        case 0x1CBC: goto L_1CBC;
        case 0x1CB8: goto L_1CB8;
        case 0x1CB4: goto L_1CB4;
        case 0x1CB0: goto L_1CB0;
        case 0x1CAC: goto L_1CAC;
        case 0x1CA8: goto L_1CA8;
        case 0x1CA4: goto L_1CA4;
        case 0x1CA0: goto L_1CA0;
        case 0x1C9C: goto L_1C9C;
        case 0x1C98: goto L_1C98;
        case 0x1C94: goto L_1C94;
        case 0x1C90: goto L_1C90;
        case 0x1C8C: goto L_1C8C;
        case 0x1C88: goto L_1C88;
        case 0x1C84: goto L_1C84;
        case 0x1C80: goto L_1C80;
        case 0x1C7C: goto L_1C7C;
        case 0x1C78: goto L_1C78;
        case 0x1C74: goto L_1C74;
        case 0x1C70: goto L_1C70;
        case 0x1C6C: goto L_1C6C;
        case 0x1C68: goto L_1C68;
        case 0x1C64: goto L_1C64;
        case 0x1C60: goto L_1C60;
        case 0x1C5C: goto L_1C5C;
        case 0x1C58: goto L_1C58;
        case 0x1C54: goto L_1C54;
        case 0x1C50: goto L_1C50;
        case 0x1C4C: goto L_1C4C;
        case 0x1C48: goto L_1C48;
        case 0x1C44: goto L_1C44;
        case 0x1C40: goto L_1C40;
        case 0x1C3C: goto L_1C3C;
        case 0x1C38: goto L_1C38;
        case 0x1C34: goto L_1C34;
        case 0x1C30: goto L_1C30;
        case 0x1C2C: goto L_1C2C;
        case 0x1C28: goto L_1C28;
        case 0x1C24: goto L_1C24;
        case 0x1C20: goto L_1C20;
        case 0x1C1C: goto L_1C1C;
        case 0x1C18: goto L_1C18;
        case 0x1C14: goto L_1C14;
        case 0x1C10: goto L_1C10;
        case 0x1C0C: goto L_1C0C;
        case 0x1C08: goto L_1C08;
        case 0x1C04: goto L_1C04;
        case 0x1C00: goto L_1C00;
        case 0x1BFC: goto L_1BFC;
        case 0x1BF8: goto L_1BF8;
        case 0x1BF4: goto L_1BF4;
        case 0x1BF0: goto L_1BF0;
        case 0x1BEC: goto L_1BEC;
        case 0x1BE8: goto L_1BE8;
        case 0x1BE4: goto L_1BE4;
        case 0x1BE0: goto L_1BE0;
        case 0x1BDC: goto L_1BDC;
        case 0x1BD8: goto L_1BD8;
        case 0x1BD4: goto L_1BD4;
        case 0x1BD0: goto L_1BD0;
        case 0x1BCC: goto L_1BCC;
        case 0x1BC8: goto L_1BC8;
        case 0x1BC4: goto L_1BC4;
        case 0x1BC0: goto L_1BC0;
        case 0x1BBC: goto L_1BBC;
        case 0x1BB8: goto L_1BB8;
        case 0x1BB4: goto L_1BB4;
        case 0x1BB0: goto L_1BB0;
        case 0x1BAC: goto L_1BAC;
        case 0x1BA8: goto L_1BA8;
        case 0x1BA4: goto L_1BA4;
        case 0x1BA0: goto L_1BA0;
        case 0x1B9C: goto L_1B9C;
        case 0x1B98: goto L_1B98;
        case 0x1B94: goto L_1B94;
        case 0x1B90: goto L_1B90;
        case 0x1B88: goto L_1B88;
        case 0x1B84: goto L_1B84;
        case 0x1B80: goto L_1B80;
        case 0x1B7C: goto L_1B7C;
        case 0x1B78: goto L_1B78;
        case 0x1B74: goto L_1B74;
        case 0x1B70: goto L_1B70;
        case 0x1B6C: goto L_1B6C;
        case 0x1B68: goto L_1B68;
        case 0x1B64: goto L_1B64;
        case 0x1B60: goto L_1B60;
        case 0x1B5C: goto L_1B5C;
        case 0x1B58: goto L_1B58;
        case 0x1B54: goto L_1B54;
        case 0x1B50: goto L_1B50;
        case 0x1B4C: goto L_1B4C;
        case 0x1B48: goto L_1B48;
        case 0x1B44: goto L_1B44;
        case 0x1B40: goto L_1B40;
        case 0x1B3C: goto L_1B3C;
        case 0x1B38: goto L_1B38;
        case 0x1B34: goto L_1B34;
        case 0x1B30: goto L_1B30;
        case 0x1B2C: goto L_1B2C;
        case 0x1B28: goto L_1B28;
        case 0x1B20: goto L_1B20;
        case 0x1B1C: goto L_1B1C;
        case 0x1B18: goto L_1B18;
        case 0x1B14: goto L_1B14;
        case 0x1B10: goto L_1B10;
        case 0x1B0C: goto L_1B0C;
        case 0x1B08: goto L_1B08;
        case 0x1B04: goto L_1B04;
        case 0x1B00: goto L_1B00;
        case 0x1AFC: goto L_1AFC;
        case 0x1AF8: goto L_1AF8;
        case 0x1AF4: goto L_1AF4;
        case 0x1AF0: goto L_1AF0;
        case 0x1AEC: goto L_1AEC;
        case 0x1AE8: goto L_1AE8;
        case 0x1AE4: goto L_1AE4;
        case 0x1AE0: goto L_1AE0;
        case 0x1ADC: goto L_1ADC;
        case 0x1AD8: goto L_1AD8;
        case 0x1AD4: goto L_1AD4;
        case 0x1AD0: goto L_1AD0;
        case 0x1ACC: goto L_1ACC;
        case 0x1AC8: goto L_1AC8;
        case 0x1AC4: goto L_1AC4;
        case 0x1AC0: goto L_1AC0;
        case 0x1ABC: goto L_1ABC;
        case 0x1AB8: goto L_1AB8;
        case 0x1AB4: goto L_1AB4;
        case 0x1AB0: goto L_1AB0;
        case 0x1AAC: goto L_1AAC;
        case 0x1AA8: goto L_1AA8;
        case 0x1AA4: goto L_1AA4;
        case 0x1AA0: goto L_1AA0;
        case 0x1A9C: goto L_1A9C;
        case 0x1A98: goto L_1A98;
        case 0x1A94: goto L_1A94;
        case 0x1A90: goto L_1A90;
        case 0x1A8C: goto L_1A8C;
        case 0x1A88: goto L_1A88;
        case 0x1A84: goto L_1A84;
        case 0x1A80: goto L_1A80;
        case 0x1A7C: goto L_1A7C;
        case 0x1A78: goto L_1A78;
        case 0x1A74: goto L_1A74;
        case 0x1A70: goto L_1A70;
        case 0x1A6C: goto L_1A6C;
        case 0x1A68: goto L_1A68;
        case 0x1A64: goto L_1A64;
        case 0x1A60: goto L_1A60;
        case 0x1A5C: goto L_1A5C;
        case 0x1A58: goto L_1A58;
        case 0x1A54: goto L_1A54;
        case 0x1A50: goto L_1A50;
        case 0x1A4C: goto L_1A4C;
        case 0x1A48: goto L_1A48;
        case 0x1A44: goto L_1A44;
        case 0x1A40: goto L_1A40;
        case 0x1A3C: goto L_1A3C;
        case 0x1A38: goto L_1A38;
        case 0x1A34: goto L_1A34;
        case 0x1A30: goto L_1A30;
        case 0x1A2C: goto L_1A2C;
        case 0x1A28: goto L_1A28;
        case 0x1A24: goto L_1A24;
        case 0x1A20: goto L_1A20;
        case 0x1A1C: goto L_1A1C;
        case 0x1A18: goto L_1A18;
        case 0x1A14: goto L_1A14;
        case 0x1A10: goto L_1A10;
        case 0x1A0C: goto L_1A0C;
        case 0x1A08: goto L_1A08;
        case 0x1A04: goto L_1A04;
        case 0x1A00: goto L_1A00;
        case 0x19FC: goto L_19FC;
        case 0x19F8: goto L_19F8;
        case 0x19F4: goto L_19F4;
        case 0x19F0: goto L_19F0;
        case 0x19EC: goto L_19EC;
        case 0x19E8: goto L_19E8;
        case 0x19E4: goto L_19E4;
        case 0x19E0: goto L_19E0;
        case 0x19DC: goto L_19DC;
        case 0x19D8: goto L_19D8;
        case 0x19D4: goto L_19D4;
        case 0x19D0: goto L_19D0;
        case 0x19CC: goto L_19CC;
        case 0x19C8: goto L_19C8;
        case 0x19C4: goto L_19C4;
        case 0x19C0: goto L_19C0;
        case 0x19BC: goto L_19BC;
        case 0x19B8: goto L_19B8;
        case 0x19B4: goto L_19B4;
        case 0x19B0: goto L_19B0;
        case 0x19AC: goto L_19AC;
        case 0x19A8: goto L_19A8;
        case 0x19A4: goto L_19A4;
        case 0x19A0: goto L_19A0;
        case 0x199C: goto L_199C;
        case 0x1998: goto L_1998;
        case 0x1994: goto L_1994;
        case 0x1990: goto L_1990;
        case 0x198C: goto L_198C;
        case 0x1988: goto L_1988;
        case 0x1984: goto L_1984;
        case 0x1980: goto L_1980;
        case 0x197C: goto L_197C;
        case 0x1978: goto L_1978;
        case 0x1974: goto L_1974;
        case 0x1970: goto L_1970;
        case 0x196C: goto L_196C;
        case 0x1968: goto L_1968;
        case 0x1964: goto L_1964;
        case 0x1960: goto L_1960;
        case 0x195C: goto L_195C;
        case 0x1958: goto L_1958;
        case 0x1954: goto L_1954;
        case 0x1950: goto L_1950;
        case 0x194C: goto L_194C;
        case 0x1948: goto L_1948;
        case 0x1944: goto L_1944;
        case 0x1940: goto L_1940;
        case 0x193C: goto L_193C;
        case 0x1938: goto L_1938;
        case 0x1934: goto L_1934;
        case 0x1930: goto L_1930;
        case 0x192C: goto L_192C;
        case 0x1928: goto L_1928;
        case 0x1924: goto L_1924;
        case 0x1920: goto L_1920;
        case 0x191C: goto L_191C;
        case 0x1918: goto L_1918;
        case 0x1914: goto L_1914;
        case 0x1910: goto L_1910;
        case 0x190C: goto L_190C;
        case 0x1908: goto L_1908;
        case 0x1904: goto L_1904;
        case 0x1900: goto L_1900;
        case 0x18FC: goto L_18FC;
        case 0x18F8: goto L_18F8;
        case 0x18F4: goto L_18F4;
        case 0x18F0: goto L_18F0;
        case 0x18EC: goto L_18EC;
        case 0x18E8: goto L_18E8;
        case 0x1460: goto L_1460;
        case 0x145C: goto L_145C;
        case 0x1458: goto L_1458;
        case 0x1454: goto L_1454;
        case 0x1450: goto L_1450;
        case 0x144C: goto L_144C;
        case 0x1448: goto L_1448;
        case 0x1444: goto L_1444;
        case 0x1440: goto L_1440;
        case 0x143C: goto L_143C;
        case 0x1438: goto L_1438;
        case 0x1434: goto L_1434;
        case 0x1430: goto L_1430;
        case 0x142C: goto L_142C;
        case 0x1428: goto L_1428;
        case 0x1424: goto L_1424;
        case 0x1420: goto L_1420;
        case 0x141C: goto L_141C;
        case 0x1418: goto L_1418;
        case 0x1414: goto L_1414;
        case 0x1410: goto L_1410;
        case 0x140C: goto L_140C;
        case 0x1408: goto L_1408;
        case 0x1404: goto L_1404;
        case 0x1400: goto L_1400;
        case 0x13FC: goto L_13FC;
        case 0x13F8: goto L_13F8;
        case 0x13F4: goto L_13F4;
        case 0x13F0: goto L_13F0;
        case 0x13EC: goto L_13EC;
        case 0x13E8: goto L_13E8;
        case 0x13E4: goto L_13E4;
        case 0x13E0: goto L_13E0;
        case 0x13DC: goto L_13DC;
        case 0x13D8: goto L_13D8;
        case 0x13D4: goto L_13D4;
        case 0x13D0: goto L_13D0;
        case 0x13CC: goto L_13CC;
        case 0x13C8: goto L_13C8;
        case 0x13C4: goto L_13C4;
        case 0x13C0: goto L_13C0;
        case 0x13BC: goto L_13BC;
        case 0x13B8: goto L_13B8;
        case 0x13B4: goto L_13B4;
        case 0x13B0: goto L_13B0;
        case 0x13AC: goto L_13AC;
        case 0x13A8: goto L_13A8;
        case 0x13A4: goto L_13A4;
        case 0x13A0: goto L_13A0;
        case 0x139C: goto L_139C;
        case 0x1398: goto L_1398;
        case 0x1394: goto L_1394;
        case 0x1390: goto L_1390;
        case 0x1388: goto L_1388;
        case 0x1380: goto L_1380;
        case 0x137C: goto L_137C;
        case 0x1378: goto L_1378;
        case 0x1374: goto L_1374;
        case 0x1370: goto L_1370;
        case 0x136C: goto L_136C;
        case 0x1368: goto L_1368;
        case 0x1364: goto L_1364;
        case 0x1360: goto L_1360;
        case 0x135C: goto L_135C;
        case 0x1358: goto L_1358;
        case 0x1354: goto L_1354;
        case 0x1350: goto L_1350;
        case 0x134C: goto L_134C;
        case 0x1348: goto L_1348;
        case 0x1344: goto L_1344;
        case 0x1340: goto L_1340;
        case 0x133C: goto L_133C;
        case 0x1338: goto L_1338;
        case 0x1334: goto L_1334;
        case 0x1330: goto L_1330;
        case 0x132C: goto L_132C;
        case 0x1328: goto L_1328;
        case 0x1324: goto L_1324;
        case 0x1320: goto L_1320;
        case 0x1318: goto L_1318;
        case 0x1B8C: goto L_1B8C;
        case 0x1314: goto L_1314;
        case 0x1310: goto L_1310;
        case 0x130C: goto L_130C;
        case 0x1308: goto L_1308;
        case 0x1304: goto L_1304;
        case 0x1300: goto L_1300;
        case 0x12FC: goto L_12FC;
        case 0x12F8: goto L_12F8;
        case 0x12F0: goto L_12F0;
        case 0x12EC: goto L_12EC;
        case 0x12E8: goto L_12E8;
        case 0x12E4: goto L_12E4;
        case 0x12E0: goto L_12E0;
        case 0x12DC: goto L_12DC;
        case 0x12D8: goto L_12D8;
        case 0x12D4: goto L_12D4;
        case 0x12D0: goto L_12D0;
        case 0x12CC: goto L_12CC;
        case 0x12C8: goto L_12C8;
        case 0x12C4: goto L_12C4;
        case 0x12C0: goto L_12C0;
        case 0x12B8: goto L_12B8;
        case 0x12B4: goto L_12B4;
        case 0x12B0: goto L_12B0;
        case 0x1B24: goto L_1B24;
        case 0x12AC: goto L_12AC;
        case 0x12A8: goto L_12A8;
        case 0x12A4: goto L_12A4;
        case 0x12A0: goto L_12A0;
        case 0x129C: goto L_129C;
        case 0x1298: goto L_1298;
        case 0x1294: goto L_1294;
        case 0x1290: goto L_1290;
        case 0x128C: goto L_128C;
        case 0x1288: goto L_1288;
        case 0x1284: goto L_1284;
        case 0x127C: goto L_127C;
        case 0x1278: goto L_1278;
        case 0x1274: goto L_1274;
        case 0x1270: goto L_1270;
        case 0x126C: goto L_126C;
        case 0x1268: goto L_1268;
        case 0x1264: goto L_1264;
        case 0x1260: goto L_1260;
        case 0x125C: goto L_125C;
        case 0x1258: goto L_1258;
        case 0x1254: goto L_1254;
        case 0x1138: goto L_1138;
        case 0x131C: goto L_131C;
        case 0x1134: goto L_1134;
        case 0x112C: goto L_112C;
        case 0x1124: goto L_1124;
        case 0x1120: goto L_1120;
        case 0x1118: goto L_1118;
        case 0x1114: goto L_1114;
        case 0x1110: goto L_1110;
        case 0x110C: goto L_110C;
        case 0x1104: goto L_1104;
        case 0x12F4: goto L_12F4;
        case 0x16F8: goto L_16F8;
        case 0x10FC: goto L_10FC;
        case 0x14FC: goto L_14FC;
        case 0x10F8: goto L_10F8;
        case 0x10F4: goto L_10F4;
        case 0x10F0: goto L_10F0;
        case 0x10EC: goto L_10EC;
        case 0x10E8: goto L_10E8;
        case 0x10E0: goto L_10E0;
        case 0x10DC: goto L_10DC;
        case 0x10D8: goto L_10D8;
        case 0x10D4: goto L_10D4;
        case 0x10D0: goto L_10D0;
        case 0x10CC: goto L_10CC;
        case 0x10C8: goto L_10C8;
        case 0x10C4: goto L_10C4;
        case 0x10BC: goto L_10BC;
        case 0x1108: goto L_1108;
        case 0x1868: goto L_1868;
        case 0x10B4: goto L_10B4;
        case 0x10E4: goto L_10E4;
        case 0x12BC: goto L_12BC;
        case 0x18C8: goto L_18C8;
        case 0x10C0: goto L_10C0;
        case 0x1128: goto L_1128;
        case 0x1228: goto L_1228;
        case 0x10A0: goto L_10A0;
        case 0x10B0: goto L_10B0;
        case 0x1240: goto L_1240;
        case 0x111C: goto L_111C;
        case 0x138C: goto L_138C;
        case 0x1790: goto L_1790;
        case 0x119C: goto L_119C;
        case 0x1090: goto L_1090;
        case 0x1384: goto L_1384;
        case 0x11A0: goto L_11A0;
        case 0x10AC: goto L_10AC;
        case 0x1100: goto L_1100;
        case 0x10B8: goto L_10B8;
        case 0x1130: goto L_1130;
        case 0x1080: goto L_1080;
        case 0x1084: goto L_1084;
        case 0x1280: goto L_1280;
        case 0x1088: goto L_1088;
        case 0x1178: goto L_1178;
        case 0x108C: goto L_108C;
        case 0x1094: goto L_1094;
        case 0x1098: goto L_1098;
        case 0x109C: goto L_109C;
        case 0x10A4: goto L_10A4;
        case 0x10A8: goto L_10A8;
        case 0x113C: goto L_113C;
        case 0x1140: goto L_1140;
        case 0x1144: goto L_1144;
        case 0x1148: goto L_1148;
        case 0x114C: goto L_114C;
        case 0x1150: goto L_1150;
        case 0x1154: goto L_1154;
        case 0x1158: goto L_1158;
        case 0x115C: goto L_115C;
        case 0x1160: goto L_1160;
        case 0x1164: goto L_1164;
        case 0x1168: goto L_1168;
        case 0x116C: goto L_116C;
        case 0x1170: goto L_1170;
        case 0x1174: goto L_1174;
        case 0x117C: goto L_117C;
        case 0x1180: goto L_1180;
        case 0x1184: goto L_1184;
        case 0x1188: goto L_1188;
        case 0x118C: goto L_118C;
        case 0x1190: goto L_1190;
        case 0x1194: goto L_1194;
        case 0x1198: goto L_1198;
        case 0x11A4: goto L_11A4;
        case 0x11A8: goto L_11A8;
        case 0x11AC: goto L_11AC;
        case 0x11B0: goto L_11B0;
        case 0x11B4: goto L_11B4;
        case 0x11B8: goto L_11B8;
        case 0x11BC: goto L_11BC;
        case 0x11C0: goto L_11C0;
        case 0x11C4: goto L_11C4;
        case 0x11C8: goto L_11C8;
        case 0x11CC: goto L_11CC;
        case 0x11D0: goto L_11D0;
        case 0x11D4: goto L_11D4;
        case 0x11D8: goto L_11D8;
        case 0x11DC: goto L_11DC;
        case 0x11E0: goto L_11E0;
        case 0x11E4: goto L_11E4;
        case 0x11E8: goto L_11E8;
        case 0x11EC: goto L_11EC;
        case 0x11F0: goto L_11F0;
        case 0x11F4: goto L_11F4;
        case 0x11F8: goto L_11F8;
        case 0x11FC: goto L_11FC;
        case 0x1200: goto L_1200;
        case 0x1E10: goto L_1E10;
        case 0x159C: goto L_159C;
        case 0x1204: goto L_1204;
        case 0x1208: goto L_1208;
        case 0x120C: goto L_120C;
        case 0x1210: goto L_1210;
        case 0x1214: goto L_1214;
        case 0x1218: goto L_1218;
        case 0x121C: goto L_121C;
        case 0x1220: goto L_1220;
        case 0x1224: goto L_1224;
        case 0x122C: goto L_122C;
        case 0x1230: goto L_1230;
        case 0x1234: goto L_1234;
        case 0x1238: goto L_1238;
        case 0x123C: goto L_123C;
        case 0x1244: goto L_1244;
        case 0x1248: goto L_1248;
        case 0x124C: goto L_124C;
        case 0x1250: goto L_1250;
        case 0x1464: goto L_1464;
        case 0x1468: goto L_1468;
        case 0x146C: goto L_146C;
        case 0x1470: goto L_1470;
        case 0x1474: goto L_1474;
        case 0x1478: goto L_1478;
        case 0x147C: goto L_147C;
        case 0x1480: goto L_1480;
        case 0x1484: goto L_1484;
        case 0x1488: goto L_1488;
        case 0x148C: goto L_148C;
        case 0x1490: goto L_1490;
        case 0x1494: goto L_1494;
        case 0x1498: goto L_1498;
        case 0x149C: goto L_149C;
        case 0x14A0: goto L_14A0;
        case 0x14A4: goto L_14A4;
        case 0x14A8: goto L_14A8;
        case 0x14AC: goto L_14AC;
        case 0x14B0: goto L_14B0;
        case 0x14B4: goto L_14B4;
        case 0x14B8: goto L_14B8;
        case 0x14BC: goto L_14BC;
        case 0x14C0: goto L_14C0;
        case 0x14C4: goto L_14C4;
        case 0x14C8: goto L_14C8;
        case 0x14CC: goto L_14CC;
        case 0x14D0: goto L_14D0;
        case 0x14D4: goto L_14D4;
        case 0x14D8: goto L_14D8;
        case 0x14DC: goto L_14DC;
        case 0x14E0: goto L_14E0;
        case 0x14E4: goto L_14E4;
        case 0x14E8: goto L_14E8;
        case 0x14EC: goto L_14EC;
        case 0x14F0: goto L_14F0;
        case 0x14F4: goto L_14F4;
        case 0x14F8: goto L_14F8;
        case 0x1500: goto L_1500;
        case 0x1504: goto L_1504;
        case 0x1508: goto L_1508;
        case 0x150C: goto L_150C;
        case 0x1510: goto L_1510;
        case 0x1514: goto L_1514;
        case 0x1518: goto L_1518;
        case 0x151C: goto L_151C;
        case 0x1520: goto L_1520;
        case 0x1524: goto L_1524;
        case 0x1528: goto L_1528;
        case 0x152C: goto L_152C;
        case 0x1530: goto L_1530;
        case 0x1534: goto L_1534;
        case 0x1538: goto L_1538;
        case 0x153C: goto L_153C;
        case 0x1540: goto L_1540;
        case 0x1544: goto L_1544;
        case 0x1548: goto L_1548;
        case 0x154C: goto L_154C;
        case 0x1550: goto L_1550;
        case 0x1554: goto L_1554;
        case 0x1558: goto L_1558;
        case 0x155C: goto L_155C;
        case 0x1560: goto L_1560;
        case 0x1564: goto L_1564;
        case 0x1568: goto L_1568;
        case 0x156C: goto L_156C;
        case 0x1570: goto L_1570;
        case 0x1574: goto L_1574;
        case 0x1578: goto L_1578;
        case 0x157C: goto L_157C;
        case 0x1580: goto L_1580;
        case 0x1584: goto L_1584;
        case 0x1588: goto L_1588;
        case 0x158C: goto L_158C;
        case 0x1590: goto L_1590;
        case 0x1594: goto L_1594;
        case 0x1598: goto L_1598;
        case 0x15A0: goto L_15A0;
        case 0x15A4: goto L_15A4;
        case 0x15A8: goto L_15A8;
        case 0x15AC: goto L_15AC;
        case 0x15B0: goto L_15B0;
        case 0x15B4: goto L_15B4;
        case 0x15B8: goto L_15B8;
        case 0x15BC: goto L_15BC;
        case 0x15C0: goto L_15C0;
        case 0x15C4: goto L_15C4;
        case 0x15C8: goto L_15C8;
        case 0x15CC: goto L_15CC;
        case 0x15D0: goto L_15D0;
        case 0x15D4: goto L_15D4;
        case 0x15D8: goto L_15D8;
        case 0x15DC: goto L_15DC;
        case 0x15E0: goto L_15E0;
        case 0x15E4: goto L_15E4;
        case 0x15E8: goto L_15E8;
        case 0x15EC: goto L_15EC;
        case 0x15F0: goto L_15F0;
        case 0x15F4: goto L_15F4;
        case 0x15F8: goto L_15F8;
        case 0x15FC: goto L_15FC;
        case 0x1600: goto L_1600;
        case 0x1604: goto L_1604;
        case 0x1608: goto L_1608;
        case 0x160C: goto L_160C;
        case 0x1610: goto L_1610;
        case 0x1614: goto L_1614;
        case 0x1618: goto L_1618;
        case 0x161C: goto L_161C;
        case 0x1620: goto L_1620;
        case 0x1624: goto L_1624;
        case 0x1628: goto L_1628;
        case 0x162C: goto L_162C;
        case 0x1630: goto L_1630;
        case 0x1634: goto L_1634;
        case 0x1638: goto L_1638;
        case 0x163C: goto L_163C;
        case 0x1640: goto L_1640;
        case 0x1644: goto L_1644;
        case 0x1648: goto L_1648;
        case 0x164C: goto L_164C;
        case 0x1650: goto L_1650;
        case 0x1654: goto L_1654;
        case 0x1658: goto L_1658;
        case 0x165C: goto L_165C;
        case 0x1660: goto L_1660;
        case 0x1664: goto L_1664;
        case 0x1668: goto L_1668;
        case 0x166C: goto L_166C;
        case 0x1670: goto L_1670;
        case 0x1674: goto L_1674;
        case 0x1678: goto L_1678;
        case 0x167C: goto L_167C;
        case 0x1680: goto L_1680;
        case 0x1684: goto L_1684;
        case 0x1688: goto L_1688;
        case 0x168C: goto L_168C;
        case 0x1690: goto L_1690;
        case 0x1694: goto L_1694;
        case 0x1698: goto L_1698;
        case 0x169C: goto L_169C;
        case 0x16A0: goto L_16A0;
        case 0x16A4: goto L_16A4;
        case 0x16A8: goto L_16A8;
        case 0x16AC: goto L_16AC;
        case 0x16B0: goto L_16B0;
        case 0x16B4: goto L_16B4;
        case 0x16B8: goto L_16B8;
        case 0x16BC: goto L_16BC;
        case 0x16C0: goto L_16C0;
        case 0x16C4: goto L_16C4;
        case 0x16C8: goto L_16C8;
        case 0x16CC: goto L_16CC;
        case 0x16D0: goto L_16D0;
        case 0x16D4: goto L_16D4;
        case 0x16D8: goto L_16D8;
        case 0x16DC: goto L_16DC;
        case 0x16E0: goto L_16E0;
        case 0x16E4: goto L_16E4;
        case 0x16E8: goto L_16E8;
        case 0x16EC: goto L_16EC;
        case 0x16F0: goto L_16F0;
        case 0x16F4: goto L_16F4;
        case 0x16FC: goto L_16FC;
        case 0x1700: goto L_1700;
        case 0x1704: goto L_1704;
        case 0x1708: goto L_1708;
        case 0x170C: goto L_170C;
        case 0x1710: goto L_1710;
        case 0x1714: goto L_1714;
        case 0x1718: goto L_1718;
        case 0x171C: goto L_171C;
        case 0x1720: goto L_1720;
        case 0x1724: goto L_1724;
        case 0x1728: goto L_1728;
        case 0x172C: goto L_172C;
        case 0x1730: goto L_1730;
        case 0x1734: goto L_1734;
        case 0x1738: goto L_1738;
        case 0x173C: goto L_173C;
        case 0x1740: goto L_1740;
        case 0x1744: goto L_1744;
        case 0x1748: goto L_1748;
        case 0x174C: goto L_174C;
        case 0x1750: goto L_1750;
        case 0x1754: goto L_1754;
        case 0x1758: goto L_1758;
        case 0x175C: goto L_175C;
        case 0x1760: goto L_1760;
        case 0x1764: goto L_1764;
        case 0x1768: goto L_1768;
        case 0x176C: goto L_176C;
        case 0x1770: goto L_1770;
        case 0x1774: goto L_1774;
        case 0x1778: goto L_1778;
        case 0x177C: goto L_177C;
        case 0x1780: goto L_1780;
        case 0x1784: goto L_1784;
        case 0x1788: goto L_1788;
        case 0x178C: goto L_178C;
        case 0x1794: goto L_1794;
        case 0x1798: goto L_1798;
        case 0x179C: goto L_179C;
        case 0x17A0: goto L_17A0;
        case 0x17A4: goto L_17A4;
        case 0x17A8: goto L_17A8;
        case 0x17AC: goto L_17AC;
        case 0x17B0: goto L_17B0;
        case 0x17B4: goto L_17B4;
        case 0x17B8: goto L_17B8;
        case 0x17BC: goto L_17BC;
        case 0x17C0: goto L_17C0;
        case 0x17C4: goto L_17C4;
        case 0x17C8: goto L_17C8;
        case 0x17CC: goto L_17CC;
        case 0x17D0: goto L_17D0;
        case 0x17D4: goto L_17D4;
        case 0x17D8: goto L_17D8;
        case 0x17DC: goto L_17DC;
        case 0x17E0: goto L_17E0;
        case 0x17E4: goto L_17E4;
        case 0x17E8: goto L_17E8;
        case 0x17EC: goto L_17EC;
        case 0x17F0: goto L_17F0;
        case 0x17F4: goto L_17F4;
        case 0x17F8: goto L_17F8;
        case 0x17FC: goto L_17FC;
        case 0x1800: goto L_1800;
        case 0x1804: goto L_1804;
        case 0x1808: goto L_1808;
        case 0x180C: goto L_180C;
        case 0x1810: goto L_1810;
        case 0x1814: goto L_1814;
        case 0x1818: goto L_1818;
        case 0x181C: goto L_181C;
        case 0x1820: goto L_1820;
        case 0x1824: goto L_1824;
        case 0x1828: goto L_1828;
        case 0x182C: goto L_182C;
        case 0x1830: goto L_1830;
        case 0x1834: goto L_1834;
        case 0x1838: goto L_1838;
        case 0x183C: goto L_183C;
        case 0x1840: goto L_1840;
        case 0x1844: goto L_1844;
        case 0x1848: goto L_1848;
        case 0x184C: goto L_184C;
        case 0x1850: goto L_1850;
        case 0x1854: goto L_1854;
        case 0x1858: goto L_1858;
        case 0x185C: goto L_185C;
        case 0x1860: goto L_1860;
        case 0x1864: goto L_1864;
        case 0x186C: goto L_186C;
        case 0x1870: goto L_1870;
        case 0x1874: goto L_1874;
        case 0x1878: goto L_1878;
        case 0x187C: goto L_187C;
        case 0x1880: goto L_1880;
        case 0x1884: goto L_1884;
        case 0x1888: goto L_1888;
        case 0x188C: goto L_188C;
        case 0x1890: goto L_1890;
        case 0x1894: goto L_1894;
        case 0x1898: goto L_1898;
        case 0x189C: goto L_189C;
        case 0x18A0: goto L_18A0;
        case 0x18A4: goto L_18A4;
        case 0x18A8: goto L_18A8;
        case 0x18AC: goto L_18AC;
        case 0x18B0: goto L_18B0;
        case 0x18B4: goto L_18B4;
        case 0x18B8: goto L_18B8;
        case 0x18BC: goto L_18BC;
        case 0x18C0: goto L_18C0;
        case 0x18C4: goto L_18C4;
        case 0x18CC: goto L_18CC;
        case 0x18D0: goto L_18D0;
        case 0x18D4: goto L_18D4;
        case 0x18D8: goto L_18D8;
        case 0x18DC: goto L_18DC;
        case 0x18E0: goto L_18E0;
        case 0x18E4: goto L_18E4;
    }
    printf("Unhandled jump target 0x%04X in microcode aspMain, coming from [%s:%d]\n", jump_target, debug_file, debug_line);
    printf("Register dump: r0  = %08X r1  = %08X r2  = %08X r3  = %08X r4  = %08X r5  = %08X r6  = %08X r7  = %08X\n"
           "               r8  = %08X r9  = %08X r10 = %08X r11 = %08X r12 = %08X r13 = %08X r14 = %08X r15 = %08X\n"
           "               r16 = %08X r17 = %08X r18 = %08X r19 = %08X r20 = %08X r21 = %08X r22 = %08X r23 = %08X\n"
           "               r24 = %08X r25 = %08X r26 = %08X r27 = %08X r28 = %08X r29 = %08X r30 = %08X r31 = %08X\n",
           0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16,
           r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31);
    return RspExitReason::UnhandledJumpTarget;
}
