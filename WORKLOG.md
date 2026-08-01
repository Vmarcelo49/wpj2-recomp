# WPJ2-recomp — Worklog

## Phase 3+4+5 — SDL2 integration + boot park

### Summary

- **Phase 3 complete**: `main.cpp` rewritten to use SDL2 (not SDL3), `recomp::start()` integration pattern, all ultramodern callbacks wired.
- **Phase 4 (partial)**: `RT64RendererContext` is a stub that logs `send_dl`/`update_screen` calls. Real RT64 wiring deferred to Phase 6.
- **Phase 5**: SDL2 audio via `SDL_QueueAudio` (auto-reconfigures on frequency change). Keyboard + gamepad input.
- **Bug fixed**: VI thread segfault on `mode == nullptr` after `start_game()` but before `osViSetMode()` — patched `events.cpp` to call `set_dummy_vi` when mode is null.
- **Bug fixed**: `entrypoint_address` must be cast through `(int64_t)(int32_t)` to sign-extend kseg0 addresses; otherwise `MEM_B` computes wrong RDRAM offsets.
- **Missing piece**: `recomp_overlays.inl` defines `section_table[]` but doesn't register it. Created `src/game/register_overlays.cpp` that calls `recomp::overlays::register_overlays()` at static init time.
- **Result**: Game boots, runs IPL3, copies ROM to RDRAM, plays audio at 22050 Hz (game-set frequency), executes 2497 recompiled functions, performs multiple PI DMA reads from ROM.

### Current blocker

The game calls function at VRAM `0x800C98CC`, which is NOT in the ELF symbol table (gap between `alSndpDeallocate (0x800C97F0, size 0x50)` and `alSndpNew (0x800C9E14)`). N64Recomp skipped this region because it had no function symbols.

**Fix**: Re-run N64Recomp with `manual_funcs` in `wpj2.j1.toml` listing `0x800C98CC` and any other gaps. The decomp project may have these as static functions — need to check `decomp/wonder/` for symbols.

### Files modified (Phase 4+5)

- `src/main.cpp` — full rewrite (recomp::start pattern)
- `src/graphics/rt64_renderer.hpp` + `.cpp` — RT64 stub
- `src/audio_input/audio.hpp` + `.cpp` — SDL2 audio backend
- `src/audio_input/input.hpp` + `.cpp` — keyboard + gamepad
- `src/rsp/rsp_dispatch.hpp` + `.cpp` — RSP ucode dispatcher (aspMain for M_AUDTASK, nop for M_GFXTASK)
- `src/audio_input/controller_pak.cpp` — supplementary CPK stubs (only functions not in librecomp)
- `src/game/register_overlays.cpp` — static-init registration of section_table[]
- `lib/N64ModernRuntime/ultramodern/src/events.cpp` — patch: set_dummy_vi when mode==nullptr
- `CMakeLists.txt` — added new sources, include dirs, PCH support
- `include/macros.h` — removed PTR/RDRAM_ARG redefinitions (broke recomp mode)

### Files removed (Phase 4+5)

- `src/audio_input/thread_shim.c` — duplicated librecomp's `ultra_translation.cpp`
- `src/graphics/graphics_shim.cpp` — duplicated librecomp's `vi.cpp`/`sp.cpp`
- (old `src/audio_input/controller_pak.c`) — duplicated librecomp's `pak.cpp`/`cont.cpp`

### Build

```bash
cmake -B build -G Ninja -DWPJ2_DEV=ON -DWPJ2_PCH=ON
cmake --build build --target wpj2
```

### Run

```bash
export SDL_VIDEODRIVER=dummy  # headless test (no Vulkan window)
export SDL_AUDIODRIVER=dummy
./build/wpj2
```

On a desktop with Vulkan + display, just `./build/wpj2`.
