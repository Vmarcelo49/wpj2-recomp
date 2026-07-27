# 04 — Execution Plan (Condensed)

> Phase-by-phase with gates. See [Methodology](02-methodology.md) for pattern, [WPJ2 Specifics](07-wpj2-specifics.md) for game details.

---

## Phase 0: Validation (1-2 days) — **CRITICAL PATH**

| Step | Command | Success Criteria |
|---|---|---|
| 0.1 ROM hash | `md5sum input/wpj2.j1.z64` | Matches `0ff1f8628d8fe69582db54572d2bea79` |
| 0.2 Ucode check | `strings input/wpj2.j1.z64 \| grep -i gsp` | SPI markers visible (confirm via decomp) |
| 0.3 Decomp build | `cd decomp/wonder && make extract && make` | `build/wonderprojectj2.jp.z64: OK` |
| 0.4 Ref emulation | Run in Ares (or cen64) | Game boots, controllable, saves to CPK |
| 0.5 ELF check | `readelf -h decomp/wonder/build/*.elf` | Valid ELF with MIPS symbols |

**Ghidra is NOT needed here** — the decomp provides the ELF with all symbols.

**GATE 0** — All 5 pass. If ANY fail → **STOP**, reassess.

---

## Phase 1: N64Recomp Translation (1 day)

| Step | Action |
|---|---|
| 1.1 | Scaffold repo with submodules (N64Recomp, N64ModernRuntime, RT64) |
| 1.2 | Copy ELF from decomp: `cp wonder/build/*.elf tools/input/` |
| 1.3 | Write `wpj2.j1.toml` (base on Zelda64Recomp/us.rev1.toml) |
| 1.4 | Run `N64RecompCLI wpj2.j1.toml` |
| 1.5 | Run `RSPRecomp aspMain.j1.rsp.toml` with `imem_base=0x04001080` |

**GATE 1** — `src/game/generated/funcs.cpp` exists (30-50 MB), no fatal errors.

---

## Phase 2: Native Library (0.5 day)

| Step | Action |
|---|---|
| 2.1 | CMakeLists.txt with hidden visibility, `-fno-strict-aliasing` |
| 2.2 | Shim headers in `include/` (ultra64.h, os.h, rcp.h, macros.h) |
| 2.3 | `cmake -B build && cmake --build build --target wpj2_recompiled` |

**GATE 2** — `build/libwpj2_recompiled.a` created, no compile errors.

---

## Phase 3: 4-Component Integration (2-3 days)

**Parallel workers (w1-w4):**

| Worker | Scope | Key Deliverables |
|---|---|---|
| **w1** | `src/game/` | `main.cpp`, `overlays.cpp` (stub — likely no overlays), `os_shims.cpp` |
| **w2** | `src/rsp/` | aspMain dispatch, RSP context |
| **w3** | `src/graphics/` | RT64 RendererContext bridge, Vulkan init |
| **w4** | `src/audio_input/` | SDL2 audio, AI_LEN mirror thread (1ms), input mapping, **Controller Pak MPK** |

**GATE 3** — Binary runs, threads start, aspMain executes, window opens (black OK).

---

## Phase 4: Boot Park Fix (1-2 days)

**Race pattern (4 workers):**
- A: Full disassembly of boot sequence
- B: Event trace (DP, SP, AI, SI, VI)
- C: Source dive in generated C
- D: Compare with Ares/cen64 trace

**Known likely causes (from Thiago):**
1. Window occlusion (Wayland) → DP event never fires
2. AI_LEN_REG not mirrored → audio thread parks
3. Overlay not registered (if any exist)
4. SP event lossy semantics

**GATE 4** — 770+ frames without parking.

---

## Phase 5: Audio + Streaming (1-2 days)

| Task | Detail |
|---|---|
| 5.1 | AI_LEN mirror thread working (from w4) |
| 5.2 | Verify aspMain audio output (not silence) |
| 5.3 | Overlay callback (only if decomp reveals overlays — unlikely) |
| 5.4 | Controller Pak read/write tested |

**GATE 5** — Intro plays with audio to "Press Start" (or JP equivalent). 60s headless = 3590+ frames.

---

## Phase 6: Renderer (2-4 days)

| Task | Detail |
|---|---|
| 6.1 | RT64 replays display lists correctly |
| 6.2 | Visual compare: recomp vs Ares (screenshots at checkpoints) |
| 6.3 | Fix microcode issues if any (gspFast3D expected) |
| 6.4 | 5+ min gameplay, no visual glitches |

**GATE 6** — Visual match at 5+ checkpoints, 30+ FPS.

---

## Phase 7: Modern Features (3-7 days)

| Priority | Feature |
|---|---|
| 1 | High-res rendering (--window WxH, --fullscreen, --ssaa) |
| 2 | F11 fullscreen toggle |
| 3 | Tab fast-forward (3×) |
| 4 | Config persistence (`~/.config/wpj2-recomp/`) |
| 5 | Widescreen (HARD — pre-rendered backgrounds don't stretch) |
| 6 | Launcher UI (ImGui, ROM select, options) |

**GATE 7** — 52-stage regression suite passes (adapt Thiago's `test_widescreen_playable.sh`).

---

## Phase 8: Polish & Distribution (2-3 days)

| Platform | Tasks |
|---|---|
| Linux | CI (Ubuntu 22.04, g++), AppImage via linuxdeploy |
| Windows | CI (Windows 2022, VS2022, `core.autocrlf=false`), SDL2 VC fetch |
| Both | Versioned releases, checksums, README |

**GATE 8** — CI green both platforms, AppImage/.exe run on clean VMs.

---

## Phase 9: Long Tail (ongoing)

- Bug numbering (Bug #1, #2... with root cause + fix commit)
- `KNOWN_ISSUES.md` maintained
- Playtest checklist (50+ scenarios)
- Regression suite in CI

---

## Timeline Summary

| Phase | Days | Cumulative |
|---|---|---|
| 0 Validation | 1-2 | 2 |
| 1 Translation | 1 | 3 |
| 2 Library | 0.5 | 3.5 |
| 3 Integration | 2-3 | 6.5 |
| 4 Boot Park | 1-2 | 8.5 |
| 5 Audio | 1-2 | 10.5 |
| 6 Renderer | 2-4 | 14.5 |
| 7 Features | 3-7 | 21.5 |
| 8 Distribution | 2-3 | 24.5 |
| **Total** | **~3.5 weeks** | |

**Buffer:** +1 week for unexpected issues = **~1 month**.

---

## Dependencies Between Phases

```
0 → 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
                    ↘     ↘
                     (7 can start after 5 partially)
```

Phase 7 (features) can begin once Phase 5 (audio + basic render) works — renderer improvements and features are somewhat independent.

---

## Go/No-Go Decision Points

1. **After Phase 0** — If ucode unsupported or decomp broken → pivot game or abort
2. **After Phase 3** — If binary crashes irrecoverably → check N64ModernRuntime compatibility
3. **After Phase 6** — If visual glitches unfixable → document as known issues, ship anyway