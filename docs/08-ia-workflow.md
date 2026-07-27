# 08 — IA Workflow

> How we use AI agents: driver+workers, race pattern, prompt templates, cost tracking.

## Overview

**Driver = Human (you).** Reviews, integrates, decides.
**Workers = IA agents** (Claude, GLM, GPT via OpenRouter). Execute missions in parallel.

```
You
  ├── Write mission prompt → prompts/phaseN_*.md
  ├── Spawn workers in git worktrees
  ├── Review outputs line-by-line
  ├── Integrate best result
  ├── Verify phase gate
  └── Commit with attribution
```

## Worker Setup

### Git Worktrees

```bash
cd ~/repos/wpj2-pc-recomp
git worktree add ../wpj2-w1-game -b w1-game
git worktree add ../wpj2-w2-rsp -b w2-rsp
git worktree add ../wpj2-w3-graphics -b w3-graphics
git worktree add ../wpj2-w4-audio -b w4-audio
```

Each worker gets its own worktree/branch. No conflicts until integration.

### OpenRouter CLI

```bash
pip install --user openrouter-cli
export OPENROUTER_API_KEY=***
```

Models to use (cost/effectiveness):
- **Claude Fable 5** (or Sonnet 4) — best for code, ~$3-5/mission
- **GLM 5.2** — good alternative, ~$2-4/mission
- **GPT-5.6** — expensive, reserve for hard races

### Spawn Script

```bash
# tools/spawn_worker.sh
WORKER=$1
PROMPT=$2
MODEL=${3:-claude-fable-5}
WORKTREE=../wpj2-${WORKER}

cd $WORKTREE
nohup claude -p "$(cat $PROMPT)" --model $MODEL \
  --output-format text --max-tokens 8000 \
  > /tmp/${WORKER}_output.txt 2>&1 &
echo "Worker $WORKER started (PID: $!)"
```

## Phase 3: 4-Component Wave (Parallel Workers)

| Worker | Scope | Output Location |
|---|---|---|
| **w1-game** | `src/game/` — main.cpp, overlays.cpp, os_shims.cpp | `w1-game/src/game/` |
| **w2-rsp** | `src/rsp/` — aspMain integration | `w2-rsp/src/rsp/` |
| **w3-graphics** | `src/graphics/` — RT64 RendererContext | `w3-graphics/src/graphics/` |
| **w4-audio** | `src/audio_input/` — SDL2 audio, input, Controller Pak | `w4-audio/src/audio_input/` |

**Prompt each with:** `prompts/phase3_w{N}_*.md`

**Integration:**
```bash
# After all 4 complete
git checkout main
git merge w1-game --no-ff
git merge w2-rsp --no-ff
git merge w3-graphics --no-ff
git merge w4-audio --no-ff
# Resolve conflicts, test, commit
```

## Race Pattern (Phase 4: Boot Park)

For hard bugs, spawn 4 workers with **different approaches** to same problem.

```bash
./tools/spawn_worker.sh race-a prompts/phase4_race_a_full_disasm.md
./tools/spawn_worker.sh race-b prompts/phase4_race_b_event_trace.md
./tools/spawn_worker.sh race-c prompts/phase4_race_c_source_dive.md
./tools/spawn_worker.sh race-d prompts/phase4_race_d_compare_emul.md

# Wait for all
wait

# Review
for w in race-a race-b race-c race-d; do
  echo "=== $w ==="
  head -100 /tmp/${w}_output.txt
done

# Pick winner, integrate
git checkout main
git merge race-b --no-ff  # example
```

**Race winner gets credited in commit:**
```
git commit -m "Phase 4: Fixed boot park (race winner phase4_b, ~$7.65)

Root cause: Window occlusion on Wayland pauses DP events.
Fix: Added WPJ2_HEADLESS_GFX=1 mode + X11 fallback.

Co-Authored-By: GLM 5.2 <noreply@openrouter.ai>
Claude-Session: https://claude.ai/code/session_xxx
```

## Prompt Templates

### Implementation Mission

```markdown
# prompts/phaseN_worker_name.md

## Mission: <Title>

### Context
- Project: WPJ2 PC Recomp (N64 → native PC)
- Phase: N
- Worker: <name> in worktree <path>
- You are implementing <specific component>

### Objective
<Clear, verifiable goal. Example: "Implement Controller Pak MPK file I/O in src/audio_input/controller_pak.cpp">

### Inputs (read-only)
- ROM: input/wpj2.j1.z64
- Symbols: symbols/wpj2.j1.toml
- Recompiled C: src/game/generated/funcs.cpp
- Runtime: lib/N64ModernRuntime/
- Reference: Thiago's trouble-makers-pc-recomp commits <hashes>

### Constraints
- Do not modify files outside <scope>
- Follow existing code style (see adjacent files)
- No new dependencies without justification
- C++17, no exceptions, no RTTI

### Expected Output
- Files modified/created: <list>
- Verification command: <exact command to test>
- Gate criterion: <objective pass condition>

### References
- Design decisions: docs/02-methodology.md section X
- Patterns: trouble-makers-pc-recomp commit <hash>
- Lessons: docs/06-risks.md R<N>

### Budget
- Max tokens: 8000
- Max time: 30 min
- Estimated cost: ~$3-5

### After Completion
List:
1. Files modified
2. Decisions made (with justification)
3. Suggested next steps
4. Unresolved risks
```

### Race Mission

```markdown
# prompts/phase4_race_<approach>.md

## Race: Diagnose Boot Park

### Bug
After start, `build/wpj2_recomp` stops processing frames after ~3 frames.
No error logs. Game appears to hang in main loop.

### Your Approach: <approach name>
- **full_disasm**: Disassemble boot sequence, identify all osRecvMesg/osSendMesg, list queues/messages
- **event_trace**: Instrument runtime to log ALL OS events (DP, SP, AI, SI, VI). Find which never fires.
- **source_dive**: Read generated C in src/game/generated/funcs.cpp. Find main loop, identify wait queues.
- **compare_emul**: Run in Ares/cen64 with tracing. Compare event sequences to recomp.

### Output Required
1. Root cause (1-2 paragraphs)
2. Evidence (logs, disassembly, traces)
3. Proposed fix (1-3 lines of change)
4. Confidence: HIGH / MEDIUM / LOW

### Winning Criterion
First to present root cause with empirical evidence + compiling fix proposal.

### Reward
Credit in commit as "race winner phase4_<approach>".
```

## Cost Tracking

Every IA-involved commit must include cost:
```bash
git commit -m "Phase 3 w1: game bootstrap (Claude Fable 5, ~$4.20)

- main.cpp entry point
- overlay registration stub
- os_shims.cpp no-ops for rmonMain etc.

Co-Authored-By: Claude Fable 5 <noreply@openrouter.ai>
Claude-Session: https://claude.ai/code/session_abc123
```

**Budget estimate:** $100-180 total (based on Thiago's $20 for 6 days; we have more phases but decomp saves Phase 0.5).

## Quality Control

1. **Never auto-merge** — always review line-by-line
2. **Run gate test** before committing integration
3. **Reject hallucinated addresses** — verify every 0x80XXXXXX against Ghidra/decomp
4. **IA doesn't know WPJ2** — always specify: "Wonder Project J2, N64, 1996, Enix/Givro"
5. **Version prompts** — save every prompt in `prompts/`

## Models & When to Use

| Model | Best For | Cost |
|---|---|---|
| Claude Fable 5 / Sonnet 4 | General implementation, code review | $$ |
| GLM 5.2 | Race workers, alternative approaches | $ |
| GPT-5.6 | Hardest races, architecture decisions | $$$ |
| Local (Ollama) | Simple refactors, boilerplate | Free |

## Attribution Format

```gitcommit
Co-Authored-By: <Model Name> <noreply@openrouter.ai>
Claude-Session: <URL if using Claude Code>
OpenRouter-Request: <request-id if available>
```

## Anti-Patterns to Avoid

- ❌ "Fix this bug" without context
- ❌ Letting IA modify files outside scope
- ❌ Trusting IA memory addresses without verification
- ❌ Skipping gate verification because "IA said it works"
- ❌ Not versioning prompts (can't reproduce/debug later)