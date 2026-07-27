# 02 — Methodology

> How we work: driver+workers, phase-gated, document failures, IA-accelerated.

## Driver + Workers Pattern

Adapted from Thiago Lira's Trouble Makers PC Recomp. One human (driver) directs multiple IA agents (workers) in parallel.

```
Driver (human)
  ├── Reads ROM/decomp/notes → writes mission prompt
  ├── Saves prompt in prompts/phaseN_*.md (versioned)
  ├── Spawns N workers in parallel (git worktrees)
  │     ├── w1: src/game/
  │     ├── w2: src/rsp/
  │     ├── w3: src/graphics/
  │     └── w4: src/audio_input/
  ├── Reviews each worker output line-by-line
  ├── Integrates best results, resolves conflicts
  ├── Verifies phase gate (boots? N frames? suite passes?)
  └── Commits with Co-Authored-By + session link
```

**Key difference from Thiago:** We have a **public decomp** (`LLONSIT-glitch/wonder`), which Thiago didn't. This eliminates the most expensive part of his workflow (building symbols from scratch).

## Phase-Gated Execution

Each phase has an **objective gate** — a measurable criterion that must pass before advancing. No advancing without passing.

| Phase | Gate | See |
|---|---|---|
| 0 | Scaffold compiles | [Execution Plan](04-execution-plan.md) |
| 1 | ELF from decomp + N64Recomp translates ROM | — |
| 2 | `libwpj2_recompiled.a` builds | — |
| 3 | Threads initiate, aspMain executes | — |
| 4 | 770+ frames without parking | — |
| 5 | Intro plays with audio to press-start | — |
| 6 | Visual match with reference emulator | — |
| 7 | Features modern (widescreen, launcher, config) | — |
| 8 | CI Linux + Windows green | — |

## Race Pattern (for hard bugs)

For obscure bugs (boot park, audio hangs), spawn 3-4 workers with **different prompts** for the same problem. First to find root cause with evidence wins.

```
Worker A: full disassembly approach
Worker B: event trace approach  
Worker C: source dive approach
Worker D: compare with emulator approach
```

Typical cost: $7-10 per race (based on Thiago's data).

## Document Failures

Every abandoned attempt is recorded in `docs/failed_attempts/`:
- What was tried
- Why it failed (empirically)
- What hypothesis it refutes
- Where work is preserved (branch / reflog)

This prevents repeating dead ends and documents reasoning for future contributors.

## IA Cost Tracking

All IA usage is transparent and tracked in commit messages:
- "race winner phase4_a, ~$7.65"
- "w1_game implementation, ~$3.20"

See [IA Workflow](08-ia-workflow.md) for prompt templates and cost estimates.

## Versioned Prompts

Every IA mission is saved as `prompts/phaseN_*.md`. This allows:
- Reproducing results
- Iterating on prompts
- Tracking which approach worked
- Building a library of effective prompts

## Reference Project

**Thiago Lira's Trouble Makers PC Recomp** ([github.com/ThiagoLira/trouble-makers-pc-recomp](https://github.com/ThiagoLira/trouble-makers-pc-recomp)):
- 6 days, ~50 commits, ~$20 in IA
- Mischief Makers (N64) → native PC binary
- Same toolchain we'll use (N64Recomp + N64ModernRuntime + RT64 + RSPRecomp)

**Key lessons from Thiago (all apply to WPJ2):**
- aspMain IMEM base is `0x04001080`, not `0x04001000` (commit 75e2080a)
- SP events are lossy — never requeue (commit 305c821c)
- Window occlusion pauses DP events (commit 486f117b)
- AI_LEN_REG needs mirror thread (commit 6aebc9f6)
- `-fvisibility=hidden` on recompiled target (prevent send/libc collision)
- Use `N64RecompCLI` CMake target, not `N64Recomp`
- `core.autocrlf=false` prevents patch corruption on Windows CI

See [Toolchain](03-toolchain.md) for full detail.
