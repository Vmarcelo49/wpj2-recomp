# 01 — Technical Profile: Wonder Project J2

> Confirmed facts about the game and its ROM. All data verified against multiple sources.

## Game Identity

| Property | Value | Source |
|---|---|---|
| **Title** | Wonder Project J2: Koruro no Mori no Josette | Wikipedia, GameFAQs |
| **Japanese** | ワープロジェクトJ2 | — |
| **Developer** | Givro Corporation | Wikipedia |
| **Publisher** | Enix Corporation | Wikipedia |
| **Director** | Takashi Yoneda | Wikipedia |
| **Release** | November 22, 1996 (Japan) | Wikipedia, GameFAQs, NintendoLife |
| **Platform** | Nintendo 64 | — |
| **Genre** | Life simulation / adventure | — |
| **Regions** | Japan only (NTSC-J) | Never released in US/PAL |
| **NUS Code** | NUS-NJ2J-JPN | NESWorld |
| **Cart Serial** | NUS-006 (JPN) | Nintendo64EVER |

## ROM Specifications

| Property | Value | How Confirmed |
|---|---|---|
| **Size** | 8,388,608 bytes (8 MiB / 64 Mbit) | Nintendo64EVER, decomp repo |
| **MD5** | `0ff1f8628d8fe69582db54572d2bea79` | LLONSIT-glitch/wonder README |
| **CRC32** | `5E8FC436` (.z64 format) | Vimm's ROM hacking database |
| **Format** | .z64 (big-endian) preferred | Standard for N64Recomp |
| **Revision** | V1.0 | Only known revision |

## Save Type: Controller Pak (CONFIRMED)

**NOT EEPROM. NOT SRAM. NOT FlashRAM.**

WPJ2 saves exclusively to **Controller Pak** (32KB = 32,768 bytes, 123 pages). The game was originally bundled with a special WPJ2-themed Controller Pak in Japan.

**Sources:**
- Wikipedia: "packaged with a game-themed Controller Pak"
- OCDReproductions: "Game saves using a controller Pak"
- Reddit r/n64: users confirm Controller Pak required to save and pass start screen
- Internet Archive: high-res scans of bundled Controller Pak
- Everdrive community: confirms need for memory pak

**Impact on project:**
- Cannot use N64ModernRuntime's EEPROM implementation
- Must implement MPK (Mempak) file system support
- Save file: `~/.local/share/wpj2-recomp/controller_pak.mpk` (Linux) or equivalent
- See [Save System](05-save-system.md) for implementation details

## Microcode (RSP)

**Status: UNCONFIRMED — likely gspFast3D**

No public documentation specifies which microcode WPJ2 uses. Being a November 1996 title (3 months after Japanese N64 launch), it almost certainly uses an early SDK ucode.

**Evidence pointing to gspFast3D:**
- Standard ucode for launch-window N64 games
- Game is primarily 2D sprites / pre-rendered backgrounds (not heavy 3D)
- Parallel-n64 bug report (#358) shows HLE RSP issues but LLE works — suggests standard but possibly non-standard usage

**To confirm before starting:**
```bash
strings input/wpj2.j1.z64 | grep -iE "gsp|asp|f3d|fast3d"
```

If `gspFast3D` appears → RT64 supports it ✅
If custom/unknown ucode appears → see [Risks](06-risks.md) R1

**Compression: SPI format (confirmed)**

The ROM contains sections compressed with **SPI**, a custom LZSS variant. Three versions exist:
- **SPI1**: encoded variant, header size 0x14
- **SPI0**: encoded variant, header size 0x14  
- **SPIN**: uncompressed variant, header size 0x8

Tool: [`Ruin0x11/josette`](https://github.com/Ruin0x11/josette) (Rust) already decodes SPI format.

**Likely compression of assets only, not code.** The decomp reports a "single segment containing all game logic" — if code were compressed, the decomp would need a decompression step to build. Confirmed: the decomp's `make extract` handles this.

## ROM Layout

Per the decompilation project:

```
ROM Layout (simplified):
├── Single code segment (all game logic)
├── Sprite/texture segments (SPI-compressed)
├── Audio data segments (banks, sequences)
└── System data
```

**No overlays detected.** The decomp describes "quite simple" layout with a single code segment. This simplifies the recomp significantly — no overlay registration callback needed (unlike Trouble Makers).

## Decompilation Project

**Repo:** [LLONSIT-glitch/wonder](https://github.com/LLONSIT-glitch/wonder)
**Status:** Work in progress, actively maintained
**Build:** `wonderprojectj2.jp.z64` (matching MD5 confirmed)
**Structure:**
```
├── assets/       (sprites, textures, yaml)
├── bins/         (unidentified binary blobs)
├── include/      (headers)
├── src/
│   ├── audio/    (audio code)
│   ├── code/     (main code segment)
│   ├── libultra/ (N64 SDK library code)
│   ├── sprites/  (sprite binary blobs)
│   └── sys/      (system code)
└── tools/        (decompilation utilities)
```

**Companion tool:** [Ruin0x11/josette](https://github.com/Ruin0x11/josette) — Rust tool for SPI compression format and sprite/object segment analysis.

## Fan Translation

A fan translation to English exists (patch at Vimm's ROM hacking, entry #1074). The patch expands the ROM to ~8.5MB and changes executable code as well as data. The native recomp therefore needs CPU sources regenerated from the translated ROM; a runtime-only asset swap stalls. See [English Translation](13-english-patch.md).

## Emulation Issues

From parallel-n64 issue #358:
- Game requires Controller Pak core option enabled
- Rumble Pak core option causes text display failure
- HLE RSP plugins have issues; LLE (angrylion/ParaLLEI) works better
- Game interacts with peripheral detection in non-standard ways

**For reference emulation:** Ares or cen64 recommended (cycle-accurate). See [Validation](09-validation.md).
