# 10 — Resource Inventory

> Software, hardware, references, and tools needed for the project.

---

## Hardware Requirements

| Item | Spec | Purpose |
|---|---|---|
| **CPU** | 4+ cores, x86_64 | Build + recompilation |
| **RAM** | 16 GB+ | Ghidra, parallel builds |
| **GPU** | Vulkan 1.2+ (Intel iGPU 11th gen+ / AMD RDNA / NVIDIA Turing+) | RT64 renderer |
| **Storage** | 20 GB free | Repos, build artifacts, ROMs |
| **Controller** | USB N64 controller (or any SDL2 gamepad) | Testing input |

**Tested on:** Ubuntu 22.04/24.04, Windows 10/11, macOS 13+ (Apple Silicon via Rosetta)

---

## Software Stack

### Core (Required)

| Tool | Version | Install |
|---|---|---|
| **CMake** | 3.24+ | `apt install cmake` / winget |
| **C++ Compiler** | GCC 12+ / Clang 15+ / MSVC 19.3+ | System |
| **Ninja** | 1.11+ | `apt install ninja-build` |
| **Git** | 2.40+ | System |
| **Python** | 3.10+ | System |
| **Vulkan SDK** | 1.3.250+ | `apt install libvulkan-dev vulkan-validationlayers-dev` |
| **SDL2** | 2.28+ | `apt install libsdl2-dev` |

### Decompilation Toolchain (Phase 0)

| Tool | Version | Install |
|---|---|---|
| **binutils-mips-linux-gnu** | 2.40+ | `apt install binutils-mips-linux-gnu` |
| **libpng-dev** | any | `apt install libpng-dev` |

### Reference Emulators (human use — on desktop PC, not server)

Emulators are for **human visual validation**, not agent use. No N64 emulator has headless screenshot automation suitable for AI agents.

- **Ares** — GUI-only, cycle-accurate. Issue #2277 requesting `--headless` still open.
- **cen64** — CLI but requires OpenGL/X11 to render.
- **Mupen64Plus** — has console UI but screenshots are via hotkey, not CLI arg.

**What agents use instead:**
- Our own recomp in headless mode (`WPJ2_HEADLESS_GFX=1`) — runs game logic without GPU, captures frame hashes
- Decomp ELF for symbol analysis (`readelf`, `objdump`)
- Static analysis tools (`strings`, `hexdump`, Python scripts)

**Install Ares/cen64 on your desktop PC** (where you have GUI + display) for manual visual comparison during Phase 6+.

### Ghidra (DEFERRED — not needed for Phase 0-5)

Ghidra is **not required** for the initial pipeline. The decomp (`LLONSIT-glitch/wonder`) provides the ELF with all symbols. Ghidra is only needed for supplementary reverse engineering.

**When to install:** Phase 6+ if deeper analysis is needed. Install on desktop PC (with GUI), not on headless server.

**Headless option:** [`ghidra-cli`](https://github.com/akiselev/ghidra-cli) — Rust CLI that bridges to Ghidra's JVM. JSON output, function listing, decompilation, xrefs — all from command line. Still requires Ghidra + JDK installed, but no GUI interaction.

| Tool | Purpose | When |
|---|---|---|
| **Ghidra 11+/12.x** | RE framework | Phase 6+ (desktop PC) |
| **ghidra-cli** | Headless Ghidra automation | Phase 6+ (optional) |
| **N64LoaderWV** | Ghidra N64 ROM loader plugin | Phase 6+ |
| **Ghidra-RSP** | Ghidra RSP microcode plugin | Phase 6+ |
| **n64_ghidra** | Ghidra companion scripts | Phase 6+ |

### Optional / Supplementary

| Tool | Purpose |
|---|---|
| **uCON64** | ROM header analysis |
| **hexdump / xxd** | Binary inspection |

---

## Repositories (Submodules)

```bash
# Core (Phase 0-1)
git submodule add https://github.com/N64Recomp/N64Recomp.git tools/N64Recomp
git submodule add https://github.com/N64Recomp/N64ModernRuntime.git lib/N64ModernRuntime
git submodule add https://github.com/rt64/rt64.git lib/RT64

# WPJ2 Decomp (primary symbol source — replaces Ghidra for symbol extraction)
git submodule add https://github.com/LLONSIT-glitch/wonder.git decomp/wonder

# WPJ2 SPI Tool (lightweight Rust CLI)
git submodule add https://github.com/Ruin0x11/josette.git tools/josette

# Ghidra plugins — DEFERRED to Phase 6+ (install on desktop PC with GUI)
# git submodule add https://github.com/zeroKilo/N64LoaderWV.git tools/N64LoaderWV
# git submodule add https://github.com/Random06457/Ghidra-RSP.git tools/Ghidra-RSP
# git submodule add https://github.com/blackgamma7/n64_ghidra.git tools/n64_ghidra
# Headless alternative: https://github.com/akiselev/ghidra-cli
```

---

## Reference Documentation

### N64Recomp Ecosystem

| Resource | URL |
|---|---|
| N64Recomp README | https://github.com/N64Recomp/N64Recomp |
| N64ModernRuntime | https://github.com/N64Recomp/N64ModernRuntime |
| RT64 README | https://github.com/rt64/rt64 |
| Zelda64Recomp (reference project) | https://github.com/Zelda64Recomp/Zelda64Recomp |
| Trouble Makers PC Recomp | https://github.com/ThiagoLira/trouble-makers-pc-recomp |

### WPJ2 Specific

| Resource | URL |
|---|---|
| LLONSIT-glitch/wonder (decomp) | https://github.com/LLONSIT-glitch/wonder |
| Ruin0x11/josette (SPI tool) | https://github.com/Ruin0x11/josette |
| Wikipedia: Wonder Project J2 | https://en.wikipedia.org/wiki/Wonder_Project_J2 |
| GameFAQs data | https://gamefaqs.gamespot.com/n64/199321-wonder-project-j2/data |
| Nintendo64EVER datasheet | https://www.nintendo64ever.com/Nintendo-64-Game-Data-Sheet,1014,Wonder-Project-J2.html |

### Technical References

| Topic | Resource |
|---|---|
| N64 RSP Microcode | http://ultra64.ca/files/documentation/ |
| Controller Pak Spec | https://www.retroreversing.com/N64ControllerPak |
| MIPS III / VR4300 | https://www.mips.com/documentation/ |
| Ghidra Scripting | https://github.com/HackOvert/GhidraSnippets |

---

## IA / AI Access

| Provider | Models | Access |
|---|---|---|
| **OpenRouter** | Claude Fable 5, GLM 5.2, GPT-5.6 | API key |
| **Ollama (local)** | qwen2.5-coder, codellama, deepseek-coder | Self-hosted |
| **Claude Code** | Sonnet 4 / Opus 4 | Subscription |

**Budget estimate:** $100-180 total (based on Thiago's $20 for 6 days; we have decomp advantage but more phases).

---

## File Structure (Target)

```
WPJ2-recomp/
├── README.md
├── docs/                    # This folder
├── input/
│   └── wpj2.j1.z64         # User-supplied ROM (gitignored)
├── symbols/
│   └── wpj2.j1.toml        # Generated symbols (optional if using decomp ELF)
├── prompts/                 # Versioned IA mission prompts
├── tools/
│   ├── N64Recomp/          # Submodule
│   ├── N64LoaderWV/        # Submodule (Ghidra plugin)
│   ├── Ghidra-RSP/         # Submodule
│   ├── n64_ghidra/         # Submodule
│   ├── josette/            # Submodule
│   └── spawn_worker.sh     # Worker launcher
├── decomp/
│   └── wonder/             # Submodule (LLONSIT-glitch/wonder)
├── lib/
│   ├── N64ModernRuntime/   # Submodule
│   └── RT64/               # Submodule
├── src/
│   ├── game/
│   │   └── generated/      # N64Recomp output
│   ├── rsp/
│   │   └── generated/      # RSPRecomp output
│   ├── graphics/
│   └── audio_input/
├── include/
│   ├── generated/          # N64Recomp headers
│   ├── ultra64.h
│   ├── os.h
│   ├── rcp.h
│   └── macros.h
├── patches/
│   ├── N64ModernRuntime/
│   └── rt64/
├── build/                  # CMake output (gitignored)
├── golden/                 # Regression golden masters
├── playtest/               # Playtest logs
└── docs/failed_attempts/   # Documented failures
```

---

## ROM Acquisition (Legal)

**You must dump your own cartridge.**

| Method | Tools |
|---|---|
| **Retrode 2** + N64 adapter | Hardware dumper |
| **N64 Gameshark / Doctor V64** | Parallel port / USB |
| **Everdrive 64 X7** + SD card | SD save → PC |
| **Arduino + custom PCB** | DIY (see n64dev.org) |

**Do NOT download ROMs.** Legal risk + checksum mismatch breaks decomp build.

**Verify your dump:**
```bash
md5sum wpj2.j1.z64
# Must match: 0ff1f8628d8fe69582db54572d2bea79
```

---

## Communication Channels

| Channel | Purpose |
|---|---|
| **GitHub Issues** | Bug tracking, feature requests |
| **GitHub Discussions** | Design decisions, questions |
| **Discord: N64 Recomp** | Community help (if exists) |
| **Discord: N64 Homebrew** | General N64 dev |
| **Reddit: r/n64** | Announcements, feedback |

---

## Credits & Attribution

- **N64Recomp team** — Core recompilation technology
- **Thiago Lira** — Trouble Makers PC Recomp methodology (driver+workers, phase-gated, race pattern)
- **LLONSIT-glitch** — Wonder Project J2 decompilation
- **Ruin0x11** — josette (SPI format research)
- **zeroKilo** — N64LoaderWV (Ghidra plugin)
- **RT64 team** — Vulkan renderer
- **N64ModernRuntime team** — Runtime library