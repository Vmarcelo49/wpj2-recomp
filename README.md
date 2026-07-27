# Wonder Project J2 — PC Recompilation Project

> Native PC port of *Wonder Project J2* (ワープロジェクトJ2), Enix/Givro, 1996, N64.
> Based on the N64Recomp methodology, adapted for WPJ2's specific characteristics.

## Quick Links

- [Technical Profile](docs/01-technical-profile.md) — ROM specs, save type, ucode, confirmed facts
- [Methodology](docs/02-methodology.md) — Driver+workers, phase-gated, race pattern
- [Toolchain](docs/03-toolchain.md) — N64Recomp, N64ModernRuntime, RT64, RSPRecomp, Ghidra
- [Execution Plan](docs/04-execution-plan.md) — Phases 0–8 with gates and estimates
- [Save System](docs/05-save-system.md) — Controller Pak implementation (NOT EEPROM)
- [Risks Register](docs/06-risks.md) — Identified risks, probabilities, mitigations
- [WPJ2 Specifics](docs/07-wpj2-specifics.md) — Game-specific technical considerations
- [IA Workflow](docs/08-ia-workflow.md) — Prompts, race pattern, worker setup
- [Validation Strategy](docs/09-validation.md) — How we verify correctness
- [Resource Inventory](docs/10-resources.md) — Software, hardware, references
- [Glossary](docs/11-glossary.md) — Terms and acronyms

## Status

**Phase: Pre-planning** — Document validation and architecture review complete. Ready to start Phase 0 once ROM is obtained.

## Key Corrections from Original Plan

The original plan (July 2026) had several incorrect assumptions that have been corrected:

1. **Decomp exists** — `LLONSIT-glitch/wonder` is an active public decompilation. No need for Ghidra-only symbol extraction.
2. **Save type is Controller Pak** — NOT EEPROM. Requires MPK implementation, not EEPROM.
3. **Release date** — November 22, 1996 (not October).
4. **ROM size** — Confirmed 8 MiB exactly (not "8-12 MiB").
5. **Plugin name** — `zeroKilo/N64LoaderWV` (not "N64LoaderWW by KingGaron"). Ghidra itself is **deferred to Phase 6+** — the decomp provides all symbols needed initially. Headless option: [`ghidra-cli`](https://github.com/akiselev/ghidra-cli).
6. **Compression** — Confirmed SPI format (custom LZSS), already documented by decomp project.
7. **Overlays** — Likely none. Decomp reports "single segment containing all game logic."

## Project Structure

```
WPJ2-recomp/
├── README.md                  (this file)
├── docs/                      (planning + reference documents)
├── symbols/                   (symbols.toml — to be populated)
├── prompts/                   (versioned IA mission prompts)
├── tools/                     (helper scripts, josette, build tools)
├── src/                       (source code — to be populated)
├── patches/                   (runtime/renderer patches)
└── lib/                       (submodules: N64ModernRuntime, RT64)
```

## License & Legal

Project does not distribute ROMs or copyrighted assets. Users supply their own ROM. Recompilation is a fair-use preservation technique. No Nintendo/Enix/Square Enix assets are included.
