# 06 — Risks Register

> Identified risks, probabilities, impacts, and mitigations.

## Risk Matrix

| ID | Risk | Prob | Impact | Mitigation | Trigger for Plan B |
|---|---|---|---|---|---|
| **R1** | Ucode gráfico custom não suportado pelo RT64 | Baixo | Crítico | Confirmar via `strings` na Fase 0. Se `gspFast3D` → ok. Se desconhecido → testar RT64 modo permissive. | Se inviável: software renderer fallback ou trocar de jogo |
| **R2** | Compressão de código na ROM | Médio | Alto | Decomp diz "single segment all game logic" → provável que só assets comprimidos. Verificar entropy no Fase 0. | Se código comprimido: callback de descompressão no N64Recomp (2-5 dias extras) |
| **R3** | Ghidra erra análise de funções (overlaps, gaps) | Alto | Médio | Iterar com feedback do N64Recomp (warnings). Se muitas iterações: usar ELF do decomp como fonte primária. | Se incontrolável: contratar RE ou usar IA p/ acelerar |
| **R4** | aspMain IMEM base diferente de 0x1080 | Baixo | Médio | Testar 0x1080 primeiro (padrão SDK 2.0). Se falhar, testar 0x1000. Analisar dispatch table interna. | Se nenhuma funciona: RE do microcode manual |
| **R5** | Window occlusion pausa DP events (Wayland) | Alto | Baixo | Testar com janela visível. Usar `WPJ2_HEADLESS_GFX=1` para validar lógica sem GPU. | Se persistir: rodar em X11 forçado |
| **R6** | Overlay não-registrado causa crash | Baixo | Médio | Decomp diz "single segment" → provável zero overlays. Confirmar na Fase 0. | Se houver: implementar callback registro (padrão Thiago Bug #11) |
| **R7** | Clang + libstdc++ 22.04 quebra u8string no CI | Médio | Baixo | Configurar CI Linux com `g++` default. Windows: clang-cl + libc++. | Se Windows quebrar: usar MSVC |
| **R8** | `autocrlf=true` no Windows CI quebra patches | Alto | Baixo | `git config --global core.autocrlf false` antes do checkout. `.gitattributes` com `-text` nos patches. | Se ainda falhar: debugar patch application step |
| **R9** | SP events lossy causa hang | Alto | Médio | Manter `requeue_sp=false`. Documentar como comportamento esperado. | Se jogo específico precisa SP confiável: implementar no runtime |
| **R10** | N64Recomp não suporta ROM + symbols.toml (sem ELF) nativamente | Médio | Médio | **Usar ELF do decomp** (caminho padrão). Thiago fez patches custom; evitar replicar. | Se ELF do decomp não buildar: investigar patches do Thiago no fork dele |
| **R11** | Controller Pak não implementado no N64ModernRuntime | Médio | Alto | Verificar suporte existente. Se ausente, implementar MPK file system (doc 05). | Se muito complexo: usar save state como workaround temporário |
| **R12** | Fan translation expande ROM → quebra offsets | Baixo | Baixo | Não aplicar translation no build. Translation é post-recomp (asset swap). | N/A |
| **R13** | Qualidade visual inferior ao emulador (Thiago criticado) | Médio | Médio | Validar visual vs Ares/cen64 em cada fase. Suite de regressão com screenshots. | Se insatisfatório: investir mais em Phase 6/7 |
| **R14** | i18n / texto japonês encoding custom | Baixo | Baixo | Recomp não decodifica texto — só passa IDs. Para translation futura: romhack separado. | N/A |
| **R15** | Problemas legais / DMCA | Muito Baixo | Crítico | Não distribuir ROM/assets. User brings own ROM. Código é reimplementação. | Se notificação: remover repo, manter local |

## Risk Categories

### Technical Risks (R1-R10)
Core recompilation pipeline. Most mitigated by Phase 0 validation.

### Runtime Risks (R11)
Controller Pak is the biggest unknown — N64ModernRuntime may not have it.

### Quality Risks (R13)
Thiago's project faced criticism for visual accuracy. We must validate continuously.

### Legal Risks (R15)
Standard for recomp projects. Mitigation: no ROM distribution, user-supplied ROM.

## Monitoring

- Review risks at each phase gate
- Add new risks as discovered
- Retire risks when mitigated (e.g., R2 confirmed assets-only after Phase 0)

## Plan B Summary

| If... | Then... |
|---|---|
| Ucode incompatível | Software renderer fallback; ou escolher outro jogo (Mario 64, OoT já têm recomp) |
| Decomp ELF não builda | Usar Ghidra + N64LoaderWV para gerar symbols.toml (path original do plano) |
| Controller Pak muito difícil | Save states como workaround; documentar limitação |
| Visual quality insatisfatório | Investir mais em Phase 6/7; widescreen pode ficar opcional |