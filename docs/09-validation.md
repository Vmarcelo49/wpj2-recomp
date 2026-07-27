# 09 — Validation Strategy

> How we verify correctness at every level. Continuous validation, not just at the end.

## Validation Layers

```
Layer 0: Unit/Compile          → Every commit
Layer 1: Headless Logic        → Phase 3+ (WPJ2_HEADLESS_GFX=1)
Layer 2: Visual Reference      → Phase 6+ (vs Ares/cen64)
Layer 3: Behavioral/Playtest   → Phase 7+ (human)
Layer 4: Regression Suite      → Phase 7+ (automated)
```

---

## Layer 0: Compile + Static Checks

**Every commit must pass:**

```bash
# 1. Clean build
cmake --build build --target wpj2_recompiled
cmake --build build --target wpj2_recomp

# 2. No warnings (or only known-safe)
# 3. clang-tidy / cppcheck (CI)
# 4. Format check
clang-format --dry-run --Werror src/
```

---

## Layer 1: Headless Logic Validation

**Run without GPU** — validates simulation logic, not rendering.

```bash
WPJ2_HEADLESS_GFX=1 ./build/wpj2_recomp --frames 770 --warp boot
```

**Checks:**
- [ ] 770+ frames processed (Thiago's boot park threshold)
- [ ] Threads: idle, main, graph, audio, SI all spawned
- [ ] Events: DP, SP, AI, VI, SI all firing
- [ ] Audio: aspMain executing, AI_LEN mirror updating
- [ ] Controller Pak: SI commands handled
- [ ] No segfaults, no asserts
- [ ] Deterministic: same frame count = same state hash

**Automation:** CI runs this on every PR.

---

## Layer 2: Visual Reference Comparison

**Against cycle-accurate emulators** (Ares preferred, cen64 alternative).

### Screenshot Comparison

```bash
# Reference emulator (Ares)
ares --headless --frames 300 --save-frames ref/ wpj2.j1.z64

# Recomp
./build/wpj2_recomp --frames 300 --save-frames out/

# Compare
python tools/compare_frames.py ref/ out/ --threshold 0.99
```

### Key Frames to Validate

| Frame | Scene | What to Check |
|---|---|---|
| 0-60 | Boot/logo | Enix/Givro logos, timing |
| 60-180 | Intro cutscene | Pre-rendered BG + 3D chars, text |
| 180-300 | Title screen | Menu, Josette idle anim, BG |
| 300+ | New game | First room, dialogue system |

### Tolerance

- **Exact match:** UI text, HUD, menus (pixel-perfect)
- **±1 pixel:** 3D character positions (FPU differences)
- **Color variance < 2/255:** Palette/gamma differences
- **Known acceptable:** Sprite interpolation (RT64 vs HLE), texture filtering

---

## Layer 3: Behavioral Playtesting

**Human-in-the-loop.** Not automatable.

### Test Scenarios (50+)

| Category | Scenarios |
|---|---|
| **Boot/Menu** | Cold boot, reset, controller plug/unplug, Pak insert/remove |
| **Dialogue** | Praise (A), scold (B), wait, choices, branching |
| **Movement** | Walk, run, interact, room transitions |
| **Minigames** | Any reaction/time-based sequences |
| **Save/Load** | New game, continue, overwrite, corrupt Pak |
| **Audio** | BGM loops, SFX triggers, silence during pause |
| **Edge cases** | Fast-forward, window focus loss, resize, alt-tab |

### Documentation

Each playtest → `playtest/YYYY-MM-DD.md`:
- Scenario
- Expected (emulator)
- Actual (recomp)
- Verdict: PASS / MINOR / MAJOR / BLOCKER
- Screenshot/video if issue

---

## Layer 4: Regression Suite

**Automated, runs in CI.** 50+ stages, headless.

```bash
# tools/test_regression.sh
#!/bin/bash
# Runs all test scenarios, compares frame hashes to golden master

SCENARIOS=(
    "boot:180"
    "intro:300"
    "title:120"
    "new_game_room1:240"
    "dialogue_praise:60"
    "dialogue_scold:60"
    "save_new:30"
    "load_continue:30"
    "fast_forward_3x:300"
    "window_resize:60"
    "focus_loss_gain:60"
)

for scenario in "${SCENARIOS[@]}"; do
    IFS=':' read -r name frames <<< "$scenario"
    WPJ2_HEADLESS_GFX=1 ./build/wpj2_recomp \
        --scenario "$name" \
        --frames "$frames" \
        --golden "golden/$name.sha256" \
        || exit 1
done

echo "ALL SCENARIOS PASSED"
```

### Golden Master Generation

```bash
# First run on reference emulator (Ares) → generates golden hashes
python tools/generate_golden.py --emulator ares --rom wpj2.j1.z64
```

### CI Integration

```yaml
# .github/workflows/regression.yml
- name: Run regression suite
  run: |
    ./tools/test_regression.sh
  timeout-minutes: 30
```

---

## Frame Hashing

**Per-frame SHA256 of RGBA buffer** (before present).

```cpp
// In renderer_context.cpp
void CaptureFrameHash(int frame_num) {
    std::vector<uint8_t> pixels = ReadFramebuffer();
    std::string hash = SHA256(pixels);
    golden_hashes[frame_num] = hash;
}
```

**Why SHA256:** Detects ANY pixel difference. More strict than SSIM.

---

## Warp System (for fast testing)

```bash
# Jump to specific scene
WPJ2_WARP=title_screen ./build/wpj2_recomp
WPJ2_WARP=room_joshua ./build/wpj2_recomp
WPJ2_WARP=minigame_01 ./build/wpj2_recomp
```

Implemented via `osSendMesg` to game's scene manager (find address in decomp).

---

## Audio Validation

Headless mode doesn't output audio. For audio:

```bash
# Record audio output
./build/wpj2_recomp --frames 1800 --record-audio audio_out.wav

# Compare spectral fingerprint
python tools/audio_compare.py ref_intro.wav audio_out.wav
```

**Checks:**
- Sample rate: 44100 Hz (or 48000 resampled)
- No buffer underruns (clicks/pops)
- BGM loops seamlessly
- SFX trigger at correct frames

---

## CI Pipeline

```mermaid
graph TD
    A[Push/PR] --> B[Layer 0: Build + Lint]
    B --> C[Layer 1: Headless 770 frames]
    C --> D[Layer 2: Visual (subset, 50 frames)]
    D --> E[Layer 4: Regression Suite]
    E --> F[Artifacts: screenshots, logs]
    F --> G[Gate: All PASS = mergeable]
```

**Nightly:** Full Layer 2 (300 frames all scenarios) + Layer 3 (manual trigger).

---

## Metrics Dashboard

Track over time:

| Metric | Target |
|---|---|
| Headless frames/sec | > 1000 (debug), > 3000 (release) |
| Visual pass rate | 100% on golden frames |
| Regression suite time | < 5 min |
| Blocker bugs open | 0 |
| Known issues documented | 100% |

---

## Validation Commands Quick Ref

```bash
# Phase 3 gate
WPJ2_HEADLESS_GFX=1 ./build/wpj2_recomp --frames 770 --verify-threads

# Phase 4 gate
WPJ2_HEADLESS_GFX=1 ./build/wpj2_recomp --frames 3590 --verify-audio

# Phase 5 gate
./build/wpj2_recomp --scenario intro --frames 1800 --save-frames out/

# Phase 6 gate
python tools/compare_frames.py golden/intro/ out/ --threshold 0.995

# Phase 7 gate
./tools/test_regression.sh

# Phase 8 gate
# CI Linux + Windows green
```