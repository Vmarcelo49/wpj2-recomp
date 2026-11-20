# 07 — WPJ2 Specific Technical Considerations

> Game-specific quirks, architecture, and challenges unique to Wonder Project J2.

## Game Architecture

### Threading Model

WPJ2 is an early N64 title (Nov 1996). Likely threading:

```
Boot Thread (idle)
  └── Main Thread
        ├── Graphics Thread (display lists → RSP)
        ├── Audio Thread (aspMain → RSP)
        ├── Controller/SI Thread
        └── Game Logic Thread (or combined with Main)
```

**Difference from later games:** May not use libultra's scheduler thread (`osScheduler`). Many launch-window games ran everything in 1-2 threads.

**Action:** In decomp/Ghidra, find `osCreateThread` calls. Map all threads.

### Graphics: Pre-rendered Backgrounds + 3D Characters

WPJ2 mixes:
- **Pre-rendered backgrounds** (2D, likely `gspS2DEX` sprite microcode)
- **3D characters** (Josette, objects) — `gspFast3D`

**Implications:**
- RT64 must support BOTH ucodes simultaneously (display list switches)
- Widescreen: backgrounds CANNOT stretch — pillarbox or "ambient wings" (mirror edges)
- Character 3D models CAN widescreen (cull rect adjustment)

**Reference:** Thiago's widescreen work on Mischief Makers (also 2D/3D mix) — commits fce17dc2, f1b0a85, 6a54fcf.

### Audio

- **Microcode:** `aspMain` (SDK 2.0) — almost certain
- **Format:** M64 sequences + instrument banks (standard)
- **AI_LEN_REG direct read:** Very likely — game reads `0xA4500004` directly (Thiago Bug #12 pattern)
- **Mirror thread needed:** 1ms thread mirroring AI_LEN_REG

### SPI Compression Format

ROM contains sections compressed with **SPI**, a custom LZSS variant. Three versions:

| Variant | Type | Header Size | Notes |
|---|---|---|---|
| SPI1 | Encoded | 0x14 | Difference from SPI0 unknown |
| SPI0 | Encoded | 0x14 | Difference from SPI1 unknown |
| SPIN | Uncompressed | 0x8 | Small RGBA32/RGBA16 textures |

**Tool:** [`Ruin0x11/josette`](https://github.com/Ruin0x11/josette) — Rust tool that decodes SPI and analyzes sprite/object segments.

**Impact on recomp:** Likely **assets only**, not code. Decomp says "single segment containing all game logic" — if code were compressed, decomp would need decompression step to build.

### ROM Layout (per decomp)

```
ROM Layout:
├── Single code segment (ALL game logic)
├── Sprite/texture segments (SPI-compressed)
├── Audio data segments (banks, sequences)
└── System data
```

**No overlays detected.** Decomp describes "quite simple" layout. This eliminates:
- Overlay registration callback (Thiago Bug #11)
- Complex overlay symbol management
- Multiple code segments to track

### Controller Pak Save System

**NOT EEPROM. NOT SRAM. NOT FlashRAM.**

Exclusively **Controller Pak** (Mempak) — 32KB, 123 pages. Game bundled with themed Controller Pak in Japan.

**Implementation required:**
- MPK file format (directory + file data, page-aligned)
- SI command handlers: 0x00 (status), 0x04 (read page), 0x05 (write page)
- Host file: `~/.local/share/wpj2-recomp/controller_pak.mpk`
- Game refuses to start without Pak detected

See [Save System](05-save-system.md) for full spec.

### Japanese Text

- Encoding: Likely Shift-JIS or custom
- Font: Bitmap font loaded from ROM (not system font)
- **For recomp:** Irrelevant — code just manipulates character IDs. Text rendering is display lists.
- **For translation:** The fan patch changes both text data and executable code. Regenerate the CPU from the translated ROM; see [English Translation](13-english-patch.md).

### Peripheral Interactions (from parallel-n64 #358)

- **Controller Pak required** to boot past start screen
- **Rumble Pak causes text display failure** if selected in core options
- Game detects pak type and behaves differently

**Implication:** SI device detection logic is sensitive. Must correctly report Controller Pak in slot 1, not Rumble Pak.

### iOS Port (2010, Japan-only)

Released on iOS April 2010, delisted long ago. No assets recoverable. **Discarded as resource.**

### PlayStation Port (Announced 1997, Cancelled)

Announced with "additional animated sequences." Never released. Concept art may exist but not accessible.

---

## Emulation Issues (Reference Behavior)

From parallel-n64 issue #358 and community reports:

| Emulator | Status | Notes |
|---|---|---|
| Ares | ✅ Best | Cycle-accurate, reference for validation |
| cen64 | ✅ Good | Cycle-accurate, slower |
| parallel-n64 | ⚠️ Issues | Needs Controller Pak core option; Rumble breaks text |
| Mupen64Plus | ⚠️ Issues | HLE RSP problems |
| Project64 | ⚠️ Issues | HLE RSP problems |

**For validation:** Use **Ares** as primary reference. cen64 as secondary.

---

## Known Unknowns (to resolve in Phase 0)

1. **Exact microcode** — `strings` check on ROM
2. **Thread count/structure** — decomp `osCreateThread` analysis
3. **AI_LEN direct read confirmation** — search for `0xA4500004` in decomp
4. **Display list ucode switching** — find `gspS2DEX` references
5. **Save data structure** — how many pages, what format, checksum algorithm
6. **Random number usage** — for Josette behavior system (determinism matters for replays)

---

## Advantages vs. Trouble Makers

| Aspect | Trouble Makers | WPJ2 |
|---|---|---|
| Decomp | Private (~12% matched) | **Public, active** (LLONSIT-glitch/wonder) |
| Overlays | 5 slots | **Likely 0** |
| Save | EEPROM 4Kbit | **Controller Pak** (different impl) |
| Compression | Unknown | **SPI documented** (josette tool) |
| Ucode | gspFast3D (confirmed) | **Likely gspFast3D + S2DEX** |
| Graphics | Full 3D | **2D/3D hybrid** (widescreen harder) |

**Net:** WPJ2 has BETTER starting position (public decomp) but HARDER widescreen (pre-rendered BG) and DIFFERENT save system.