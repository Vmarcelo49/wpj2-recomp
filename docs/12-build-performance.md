# WPJ2-recomp — Build Performance Guide

## TL;DR

| Cenário | Tempo | Quando acontece |
|---|---|---|
| Build frio total (sem ccache, sem PCH) | ~3 min | Primeira vez na máquina |
| Build frio (DEV+PCH, sem ccache) | ~3 min | Após `rm -rf ~/.cache/ccache build` |
| **Clean build + ccache warm** | **~17 s** | Após qualquer `rm -rf build` no dia a dia |
| Incremental (1 `.c` gerado) | <1 s | Editou um arquivo |
| Incremental (`main.cpp`) | ~2.5 s | Editou só o main |

Speedup real de **~10x** no ciclo de desenvolvimento.

---

## Otimizações aplicadas

1. **ccache 4.12** — Cache de compilações. Sobrevive a `rm -rf build`. Tamanho default 2 GiB em `~/.cache/ccache`.
2. **mold 2.40** — Linker ~5x mais rápido que `ld.bfd`. Auto-detectado.
3. **PCH (Precompiled Header)** — `include/generated/wpj2_pch.h` agrega `recomp.h` + `shims.h` + `macros.h`. Pré-compilado uma vez, reusado pelos 50 `funcs_*.c` e `main.cpp`.
4. **Ninja jobs = N-1** — Deixa 1 core livre para o sistema (8 cores → 7 jobs).
5. **CMAKE_EXPORT_COMPILE_COMMANDS=ON** — Gera `compile_commands.json` para clangd/IDE.

## Como usar

```bash
# Configuração padrão (DEV + PCH, ideal para desenvolvimento)
cmake -B build -G Ninja -DWPJ2_DEV=ON -DWPJ2_PCH=ON

# Build
cmake --build build                # ou: ninja -C build

# Apenas o binário
cmake --build build --target wpj2

# Apenas a biblioteca recompilada
cmake --build build --target wpj2_recompiled
```

## Opções do CMake

| Opção | Default | Descrição |
|---|---|---|
| `WPJ2_DEV` | OFF | ON = RelWithDebInfo (-O2 -g), sem LTO. Mais rápido para iterar. |
| `WPJ2_PCH` | ON | Precompile `recomp.h`+`shims.h` em `.gch`. 50 arquivos `.c` se beneficiam. |
| `WPJ2_UNITY` | OFF | Juntar os 50 `funcs_*.c` num único TU. **NÃO RECOMENDADO** — perde paralelismo. |
| `WPJ2_LINKER` | `mold` | Linker: `mold` / `lld` / `gold` / `ld`. Auto-detecta disponibilidade. |

## Estatísticas do ccache

```bash
ccache -s              # Ver hits/misses
ccache -z              # Zerar stats
ccache -C              # Limpar cache
ccache -M 5G           # Aumentar cache para 5 GiB
```

## Troubleshooting

### "fatal error: recomp.h: No such file or directory" no PCH

O PCH está em `include/generated/wpj2_pch.h` e referencia `recomp.h` (do N64ModernRuntime) e `shims.h` (nosso). Ambos precisam estar no include path. Se quebrar, confira `include_directories(...)` no `CMakeLists.txt`.

### `macros.h` redefine `PTR(x)`

NÃO adicione de volta `#define PTR(x) x*` em `include/macros.h`. O `ultramodern/ultra64.h` define `PTR(x) = int32_t` (modo recomp). Redefinir quebra todas as assinaturas `_recomp` e a API do `ultramodern`.

### Build frio continua lento (>3 min)

Confira se ccache está rodando:
```bash
cmake -B build -G Ninja ... 2>&1 | grep ccache
# -- ccache: /usr/bin/ccache
```
Se não aparece, instale: `sudo apt install ccache`.

### Erro de "rdram not declared" ou modo nativo

Você provavelmente incluiu um header que redefine `PTR`/`RDRAM_ARG` em modo nativo. Procure:
```bash
grep -rn "^#define PTR\\|^#define RDRAM_ARG" include/ lib/
```
Tudo que aparecer deve ser removido — o `ultramodern/ultra64.h` é a única fonte de verdade.

## O que não foi feito (mas poderia)

- **clang** em vez de gcc — não está instalado. Costuma ser ~20% mais rápido para C++.
- **distcc** — Distribuir build entre máquinas. Só vale a pena se houver várias máquinas.
- **LTO** — Off em DEV. Ligado em Release (mas CMakeLists não habilita hoje). Para produção, vale testar `-flto=auto`.
- **PCH para RT64** — O target `rt64` é do upstream, mexer no CMakeLists dele é frágil. Em vez disso, conta com ccache.
