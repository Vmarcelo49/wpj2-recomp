# WPJ2-recomp — Worklog

## Phase 3+4+5 — SDL2 integration + boot park + RSP fix

### Summary

- **Phase 3 complete**: `main.cpp` rewritten to use SDL2 (not SDL3), `recomp::start()` integration pattern, all ultramodern callbacks wired.
- **Phase 4 (partial)**: `RT64RendererContext` is a stub that logs `send_dl`/`update_screen` calls. Real RT64 wiring deferred to Phase 6.
- **Phase 5**: SDL2 audio via `SDL_QueueAudio` (auto-reconfigures on frequency change). Keyboard + gamepad input.
- **RSP fix**: aspMain's indirect dispatch table (DMEM 0x10) requires 904 `extra_indirect_branch_targets` in `aspMain.j1.rsp.toml` to cover all possible jump targets.
- **ELF gaps**: 165 `manual_funcs` added to `wpj2.j1.toml` for functions without symbols. 6 were unrecompilable (data in code section) and got stubs in `src/game/manual_stubs.cpp`.
- **Bug fixed**: VI thread segfault on `mode == nullptr` — patched `events.cpp` to call `set_dummy_vi` when mode is null.
- **Bug fixed**: `entrypoint_address` must be cast through `(int64_t)(int32_t)` to sign-extend kseg0 addresses.
- **Bug fixed**: `recomp_overlays.inl` defines `section_table[]` but doesn't register it — created `src/game/register_overlays.cpp` with static initializer.

### Current state — GATE 4 + 5 ACHIEVED

Game boots fully and runs stably for 30+ seconds (clean shutdown on SIGTERM):
- **1771 display lists** (M_GFXTASK) sent to RT64 stub
- **1799 screen updates** (~30s at 60 FPS)
- Audio at 22050 Hz (game-set frequency)
- 8547 recompiled functions loaded
- No crashes

### Commits

```
b31727f Fix aspMain UnhandledJumpTarget — GATE 4 + 5 achieved
a54a4b2 Update .gitignore; remove backup files and build_tools
4d078d3 Add 165 manual_funcs + stubs for unrecompilable functions
2c9eac4 Phase 4+5: SDL2 audio/input + RT64 stub + boot park fix
e593e00 Add .gitignore; untrack build/
bac5472 Phase 3 complete: SDL2 main.cpp + build optimizations
c332c1a Phase 0-1 complete: Validation + N64Recomp translation
```

### What works

- N64Recomp translation (8547 functions)
- RSPRecomp aspMain (904 labels covering all IMEM addresses)
- Boot sequence (IPL3 → entrypoint → main thread)
- Audio (SDL2 queue-based, 22050 Hz)
- Input (keyboard + gamepad)
- VI scheduling (60 FPS stable)
- SP/DP message queues
- PI DMA (ROM reads)
- Controller Pak stubs (PFS_ERR_NOPACK)
- RSP audio task dispatch (aspMain)
- RSP graphics task dispatch (nop → RT64 handles via send_dl)

### What doesn't work yet

- **RT64 renderer** (Phase 6): `RT64RendererContext::send_dl` and `update_screen` are stubs. The game sends display lists but they're not rendered. Need to create `RT64::Application` with `Core{RDRAM, DMEM, IMEM, VI/DPC regs, window}` and call `processDisplayLists()` + `updateScreen()`.
- **Visual output**: Can't verify without a real Vulkan display (server is headless).
- **Controller Pak saves**: Stubs return PFS_ERR_NOPACK. Real CPK implementation needed for save persistence.

### Build

```bash
# One-time: build N64Recomp + RSPRecomp tools
cmake -B build_tools -S tools/N64Recomp -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build_tools --target N64RecompCLI RSPRecomp

# Regenerate recompiled sources (if wpj2.j1.toml or aspMain.j1.rsp.toml change)
./build_tools/N64Recomp wpj2.j1.toml
./build_tools/RSPRecomp aspMain.j1.rsp.toml

# Build the game
cmake -B build -G Ninja -DWPJ2_DEV=ON -DWPJ2_PCH=ON
cmake --build build --target wpj2
```

### Run

```bash
# Headless (no Vulkan window — for smoke testing)
SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy ./build/wpj2

# With display (requires Vulkan-capable GPU + X11/Wayland)
./build/wpj2
```

### Next steps (Phase 6 — RT64 renderer)

1. Study `lib/RT64/src/hle/rt64_application.h` — the `Core` struct needs:
   - `RDRAM` pointer (from ultramodern)
   - `DMEM` and `IMEM` buffers (4KB each, from librecomp's `dmem[]`)
   - `MI_INTR_REG`, `DPC_*_REG`, `VI_*_REG` pointers (from ultramodern's `get_vi_regs()`)
   - `checkInterrupts` callback
   - `window` (SDL_Window*)

2. In `RT64RendererContext` constructor:
   - Create `RT64::Application::Core` with the above
   - Instantiate `RT64::Application(core, appConfig)`
   - Call `app->setup(threadId)`

3. In `send_dl(task)`:
   - Call `app->processDisplayLists(rdram, task->t.data_ptr, task->t.data_ptr + task->t.data_size, false)`

4. In `update_screen()`:
   - Call `app->updateScreen()`

5. In `shutdown()`:
   - Destroy the `RT64::Application`

6. Test with a real Vulkan display to verify visual output.

### File structure

```
WPJ2-recomp/
├── src/
│   ├── main.cpp                      # SDL2 + recomp::start integration
│   ├── game/
│   │   ├── register_overlays.cpp     # Static-init registration of section_table
│   │   ├── manual_stubs.cpp          # Auto-generated stubs for unrecompilable funcs
│   │   └── generated/                # N64Recomp output (8547 funcs in 53 files)
│   ├── rsp/
│   │   ├── rsp_dispatch.cpp          # aspMain for M_AUDTASK, nop for M_GFXTASK
│   │   └── generated/aspMain.c       # RSPRecomp output (904 labels)
│   ├── graphics/
│   │   └── rt64_renderer.cpp         # RT64 stub (Phase 6: real RT64)
│   └── audio_input/
│       ├── audio.cpp                 # SDL2 audio backend
│       ├── input.cpp                 # SDL2 keyboard + gamepad
│       └── controller_pak.cpp        # CPK stubs
├── include/
│   ├── shims.h                       # _recomp function declarations
│   ├── macros.h                      # N64 type defs (PTR/RDRAM_ARG from ultramodern)
│   └── generated/wpj2_pch.h          # Precompiled header
├── lib/
│   ├── N64ModernRuntime/             # ultramodern + librecomp (submodule)
│   └── RT64/                         # RT64 renderer (submodule)
├── tools/
│   └── N64Recomp/                    # N64Recomp + RSPRecomp (submodule)
├── build_tools/                      # N64RecompCLI + RSPRecomp binaries
├── build/                            # wpj2 binary + libs
├── wpj2.j1.toml                      # N64Recomp config (165 manual_funcs)
├── aspMain.j1.rsp.toml               # RSPRecomp config (904 indirect targets)
├── CMakeLists.txt                    # Build config (ccache, PCH, mold)
└── WORKLOG.md                        # This file
```
