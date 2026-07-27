# 11 — Glossary

> Terms, acronyms, and abbreviations used across the project.

## A–E

| Term | Definition |
|---|---|
| **AI_LEN_REG** | Audio Interface Length Register (0xA4500004). Game reads directly to know how much audio data remains. Requires 1ms mirror thread. |
| **aspMain** | Standard N64 RSP audio microcode (SDK 2.0). Mounts at IMEM 0x04001080 (NOT 0x04001000). |
| **Boot park** | Game hangs after few frames, typically waiting for an OS event that never arrives. |
| **CI** | Continuous Integration (GitHub Actions). |
| **Controller Pak** | N64 memory card (32 KB) that plugs into controller. WPJ2 save device. Also called Mempak. |
| **Cull rect** | Clipping rectangle in Q16.16 format. Widescreen requires widening it. |
| **Decomp / Decompilation** | Reverse engineering a binary back to matching C source. LLONSIT-glitch/wonder is the WPJ2 decomp. |

## F–J

| Term | Definition |
|---|---|
| **Fast3D / gspFast3D** | Standard N64 RSP graphics microcode (full-featured). Used by WPJ2 for 3D. |
| **F3DEX / gspF3DEX** | Later graphics microcode (1997+). RT64 supports both. |
| **Gate** | Objective, measurable criterion that must pass before advancing to next phase. |
| **Ghidra** | NSA reverse engineering framework. Used with N64LoaderWV for N64 ROM analysis. |
| **Headless** | Running without GPU rendering (WPJ2_HEADLESS_GFX=1). Validates logic without display. |
| **HLE** | High-Level Emulation (emulates OS calls, not hardware). |
| **IMEM** | RSP Instruction Memory (4 KB at 0xA4001000). Where microcode executes. |
| **Josette** | Protagonist of WPJ2 (the Gijin/android puppet). |

## K–O

| Term | Definition |
|---|---|
| **LLE** | Low-Level Emulation (cycle-accurate hardware simulation). |
| **Manual funcs** | Functions not exported in ELF but referenced via function pointers (vtables, jump tables). Must be listed in N64Recomp config. |
| **Mempak** | Alternate name for Controller Pak. |
| **MPK** | Mempak file format (32 KB image with directory + file data). |
| **N64ModernRuntime** | Reimplementation of libultra (N64 OS) for host platforms. |
| **N64Recomp** | Static recompiler: N64 MIPS binary → portable C. |
| **N64LoaderWV** | Ghidra plugin for loading N64 ROMs correctly (zeroKilo/N64LoaderWV). |
| **Overlays** | Code segments loaded at runtime via PI DMA. WPJ2 likely has NONE (single code segment). |

## P–T

| Term | Definition |
|---|---|
| **Phase-gated** | Methodology: each phase has a gate (objective test) that must pass before next phase. |
| **PI DMA** | Peripheral Interface Direct Memory Access. How N64 copies data from cartridge to RDRAM. |
| **Race pattern** | Spawning 3-4 IA workers with different approaches to same bug. First with root cause wins. |
| **Recomp / Recompilation** | Static recompilation (N64Recomp), not dynamic/JIT. |
| **RDRAM** | Rambus DRAM (4 MB on N64). Main memory at 0x80000000–0x80800000. |
| **RSP** | Reality Signal Processor. N64's programmable vector unit (graphics + audio microcode). |
| **RSPRecomp** | Component of N64Recomp that recompiles RSP microcode (aspMain) to x86 SIMD. |
| **RT64** | Modern Vulkan-based N64 graphics renderer. Replays display lists natively. |
| **S2DEX / gspS2DEX** | Sprite/2D graphics microcode. WPJ2 uses for pre-rendered backgrounds. |
| **SI** | Serial Interface. Communicates with controllers, Controller Pak, Rumble Pak. |
| **SPI** | Custom LZSS compression format used by WPJ2 for sprites/textures. Three variants: SPI1, SPI0, SPIN. |
| **symbols.toml** | N64Recomp config file mapping ROM addresses → function names + sizes. |

## U–Z

| Term | Definition |
|---|---|
| **Ucode / Microcode** | RSP binary program (graphics or audio). Uploaded to IMEM by game. |
| **Vtable** | Virtual function table (C++). In N64 games, often C-style function pointer arrays. |
| **Widescreen** | Rendering at 16:9 instead of native 4:3. Hard for WPJ2 due to pre-rendered backgrounds. |
| **Worker** | IA agent executing a mission prompt in a git worktree. |
| **Driver** | Human directing the workers, reviewing output, integrating. |

## Project-Specific

| Term | Definition |
|---|---|
| **WPJ2** | Wonder Project J2 (this project) |
| **WPJ2_HEADLESS_GFX=1** | Env var to run recomp headless (validates logic without GPU) |
| **WPJ2_WARP=<scene>** | Env var to warp to specific scene (for testing) |
| **Phase N** | Execution plan phases (0–9) |
| **Gate N** | Validation gate for Phase N |
| **Race X** | Diagnostic race for bug X (e.g., Race 4 for boot park) |

## File Extensions

| Ext | Meaning |
|---|---|
| `.z64` | Big-endian N64 ROM (native MIPS byte order) |
| `.n64` | Byte-swapped ROM |
| `.v64` | Word-swapped ROM |
| `.elf` | Executable Linkable Format (decomp output, N64Recomp input) |
| `.toml` | Config format (N64Recomp, symbols, RSP) |
| `.mpk` | Controller Pak image (32 KB) |
| `.m64` | N64 music sequence format |
| `.yaml` | Decomp metadata (assets, symbols) |

---

## Quick Reference: Key Addresses

| Address | Description |
|---|---|
| 0x80000400 | Standard N64 entry point (IPL3 jump target) |
| 0x80000000–0x80800000 | RDRAM (4 MB) |
| 0xA4000000–0xA4001000 | RSP DMEM/IMEM |
| 0xA4001000 | IMEM base (microcode upload) |
| 0xA4001080 | **aspMain IMEM base (SDK 2.0) — CRITICAL** |
| 0xA4500000 | Audio Interface (AI) registers |
| 0xA4500004 | AI_LEN_REG (DMA remaining) |
| 0xA4600000 | Peripheral Interface (PI) registers |
| 0xA4700000 | RSP registers |
| 0xA4800000 | RDP registers |
| 0xA4900000 | Serial Interface (SI) registers |

---

## Key Commits (Thiago / Trouble Makers)

| Commit | Discovery |
|---|---|
| 75e2080a | aspMain IMEM base = 0x04001080 (not 0x1000) |
| 486f117b | Window occlusion pauses DP events |
| 305c821c | SP events are lossy (don't requeue) |
| 6aebc9f6 | Overlay DMA needs registration; AI_LEN mirror thread |
| ee5caab | Cut decomp dependency; ROM + symbols.toml only |
| f1b0a85 | Walking pointer off-by-five in widescreen |
| 6a54fcf | Shared draw functions break widescreen |
| fce17dc2 | Ambient wings for pre-rendered BG widescreen |