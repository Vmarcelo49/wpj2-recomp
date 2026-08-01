/*
 * WPJ2 Recomp - rcp.h shim
 * RCP (Reality Coprocessor) register definitions
 */

#ifndef WPJ2_RCP_H
#define WPJ2_RCP_H

#include "macros.h"

// RCP Memory Map (Physical Addresses)
#define SP_BASE          0x04000000
#define SP_IMEM_BASE     0x04000000
#define SP_IMEM_SIZE     0x1000
#define SP_DMEM_BASE     0x04001000
#define SP_DMEM_SIZE     0x1000

#define DPC_BASE         0x04100000
#define DPS_BASE         0x0410000C

#define MI_BASE          0x04300000
#define VI_BASE          0x04400000
#define AI_BASE          0x04500000
#define PI_BASE          0x04600000
#define RI_BASE          0x04700000
#define SI_BASE          0x04800000

// SP Registers
#define SP_MEM_ADDR_REG      (SP_BASE + 0x00)
#define SP_DRAM_ADDR_REG     (SP_BASE + 0x04)
#define SP_RD_LEN_REG        (SP_BASE + 0x08)
#define SP_WR_LEN_REG        (SP_BASE + 0x0C)
#define SP_STATUS_REG        (SP_BASE + 0x10)
#define SP_DMA_FULL_REG      (SP_BASE + 0x14)
#define SP_DMA_BUSY_REG      (SP_BASE + 0x18)
#define SP_SEMAPHORE_REG     (SP_BASE + 0x1C)

#define SP_CLR_HALT          0x00001
#define SP_SET_HALT          0x00002
#define SP_CLR_BROKE         0x00004
#define SP_CLR_INTR          0x00008
#define SP_SET_INTR          0x00010
#define SP_CLR_SSTEP         0x00020
#define SP_SET_SSTEP         0x00040
#define SP_CLR_INTR_BREAK    0x00080
#define SP_SET_INTR_BREAK    0x00100
#define SP_CLR_SIG0          0x00200
#define SP_SET_SIG0          0x00400
#define SP_CLR_SIG1          0x00800
#define SP_SET_SIG1          0x01000
#define SP_CLR_SIG2          0x02000
#define SP_SET_SIG2          0x04000
#define SP_CLR_SIG3          0x08000
#define SP_SET_SIG3          0x10000
#define SP_CLR_SIG4          0x20000
#define SP_SET_SIG4          0x40000
#define SP_CLR_SIG5          0x80000
#define SP_SET_SIG5          0x100000
#define SP_CLR_SIG6          0x200000
#define SP_SET_SIG6          0x400000
#define SP_CLR_SIG7          0x800000
#define SP_SET_SIG7          0x1000000

// DPC Registers
#define DPC_START_REG        (DPC_BASE + 0x00)
#define DPC_END_REG          (DPC_BASE + 0x04)
#define DPC_CURRENT_REG      (DPC_BASE + 0x08)
#define DPC_STATUS_REG       (DPC_BASE + 0x0C)
#define DPC_CLOCK_REG        (DPC_BASE + 0x10)
#define DPC_BUFBUSY_REG      (DPC_BASE + 0x14)
#define DPC_PIPEBUSY_REG     (DPC_BASE + 0x18)
#define DPC_TMEM_REG         (DPC_BASE + 0x1C)

#define DPC_CLR_XBUS_DMEM_DMA  0x0001
#define DPC_SET_XBUS_DMEM_DMA  0x0002
#define DPC_CLR_FREEZE         0x0004
#define DPC_SET_FREEZE         0x0008
#define DPC_CLR_FLUSH          0x0010
#define DPC_SET_FLUSH          0x0020
#define DPC_CLR_TMEM_CTR       0x0040
#define DPC_CLR_PIPE_CTR       0x0080
#define DPC_CLR_CMD_CTR        0x0100
#define DPC_CLR_CLOCK_CTR      0x0200

// MI Registers
#define MI_MODE_REG          (MI_BASE + 0x00)
#define MI_VERSION_REG       (MI_BASE + 0x04)
#define MI_INTR_REG          (MI_BASE + 0x08)
#define MI_INTR_MASK_REG     (MI_BASE + 0x0C)

#define MI_CLR_INIT          0x0080
#define MI_SET_INIT          0x0100
#define MI_CLR_EBUS          0x0200
#define MI_SET_EBUS          0x0400
#define MI_CLR_DP_INTR       0x0800
#define MI_CLR_RDRAM         0x1000
#define MI_SET_RDRAM         0x2000

#define MI_INTR_DP           0x0020
#define MI_INTR_SP           0x0040
#define MI_INTR_SI           0x0080
#define MI_INTR_AI           0x0100
#define MI_INTR_VI           0x0200
#define MI_INTR_PI           0x0400

// VI Registers
#define VI_CTRL_REG          (VI_BASE + 0x00)
#define VI_ORIGIN_REG        (VI_BASE + 0x04)
#define VI_WIDTH_REG         (VI_BASE + 0x08)
#define VI_INTR_REG          (VI_BASE + 0x0C)
#define VI_CURRENT_REG       (VI_BASE + 0x10)
#define VI_BURST_REG         (VI_BASE + 0x14)
#define VI_V_SYNC_REG        (VI_BASE + 0x18)
#define VI_H_SYNC_REG        (VI_BASE + 0x1C)
#define VI_LEAP_REG          (VI_BASE + 0x20)
#define VI_H_START_REG       (VI_BASE + 0x24)
#define VI_V_START_REG       (VI_BASE + 0x28)
#define VI_V_BURST_REG       (VI_BASE + 0x2C)
#define VI_X_SCALE_REG       (VI_BASE + 0x30)
#define VI_Y_SCALE_REG       (VI_BASE + 0x34)

// AI Registers
#define AI_DRAM_ADDR_REG     (AI_BASE + 0x00)
#define AI_LEN_REG           (AI_BASE + 0x04)
#define AI_CONTROL_REG       (AI_BASE + 0x08)
#define AI_STATUS_REG        (AI_BASE + 0x0C)
#define AI_DACRATE_REG       (AI_BASE + 0x10)
#define AI_BITRATE_REG       (AI_BASE + 0x14)

#define AI_CONTROL_DMA_ON    0x0001
#define AI_CONTROL_DMA_OFF   0x0002

// PI Registers
#define PI_DRAM_ADDR_REG     (PI_BASE + 0x00)
#define PI_CART_ADDR_REG     (PI_BASE + 0x04)
#define PI_WR_LEN_REG        (PI_BASE + 0x08)
#define PI_RD_LEN_REG        (PI_BASE + 0x0C)
#define PI_STATUS_REG        (PI_BASE + 0x10)
#define PI_BSD_DOM1_LAT_REG  (PI_BASE + 0x14)
#define PI_BSD_DOM1_PWD_REG  (PI_BASE + 0x18)
#define PI_BSD_DOM1_PGS_REG  (PI_BASE + 0x1C)
#define PI_BSD_DOM1_RLS_REG  (PI_BASE + 0x20)
#define PI_BSD_DOM2_LAT_REG  (PI_BASE + 0x24)
#define PI_BSD_DOM2_PWD_REG  (PI_BASE + 0x28)
#define PI_BSD_DOM2_PGS_REG  (PI_BASE + 0x2C)
#define PI_BSD_DOM2_RLS_REG  (PI_BASE + 0x30)

#define PI_STATUS_DMA_BUSY   0x01
#define PI_STATUS_IO_BUSY    0x02
#define PI_STATUS_ERROR      0x04

// SI Registers
#define SI_DRAM_ADDR_REG     (SI_BASE + 0x00)
#define SI_PIF_ADDR_RD64B_REG (SI_BASE + 0x04)
#define SI_PIF_ADDR_WR64B_REG (SI_BASE + 0x08)
#define SI_STATUS_REG        (SI_BASE + 0x0C)

#define SI_STATUS_DMA_BUSY   0x0001
#define SI_STATUS_IO_BUSY    0x0002
#define SI_STATUS_DMA_ERROR  0x0008
#define SI_STATUS_INTERRUPT  0x0010

// RDRAM Registers
#define RI_MODE_REG          (RI_BASE + 0x00)
#define RI_CONFIG_REG        (RI_BASE + 0x04)
#define RI_CURRENT_LOAD_REG  (RI_BASE + 0x08)
#define RI_SELECT_REG        (RI_BASE + 0x0C)
#define RI_REFRESH_REG       (RI_BASE + 0x10)
#define RI_LATENCY_REG       (RI_BASE + 0x14)
#define RI_RERROR_REG        (RI_BASE + 0x18)
#define RI_WERROR_REG        (RI_BASE + 0x1C)

// I/O Access Macros
#define IO_READ(addr)        (*(volatile u32*)(addr))
#define IO_WRITE(addr, val)  (*(volatile u32*)(addr) = (val))

// Physical to virtual address conversion (N64 uses 0x80000000-0xBFFFFFFF for RDRAM)
#define PHYS_TO_K0(phys)     ((void*)((phys) | 0x80000000))
#define PHYS_TO_K1(phys)     ((void*)((phys) | 0xA0000000))

// SP IMEM/DMEM access (for RSP microcode)
#define SP_IMEM_START        0x04000000
#define SP_IMEM_END          0x04001000
#define SP_DMEM_START        0x04001000
#define SP_DMEM_END          0x04002000

// WPJ2-specific: aspMain IMEM base (SDK 2.0)
#define ASPMAIN_IMEM_BASE    0x04001080  // CRITICAL: NOT 0x04001000!

#endif // WPJ2_RCP_H
