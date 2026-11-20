# WPJ2 standalone launcher

Minimal SDL2 launcher that selects the Japanese or English native build,
validates/prepares the matching ROM, and starts the correct executable with an
explicit environment.

```bash
./src/launcher/build.sh ./build/wpj2-launcher
./src/launcher/test.sh
./build/wpj2-launcher --help
./build/wpj2-launcher --no-gui --dry-run --variant jp
```

The launcher is for manually built, `VERSION`-gated releases. It does not
build, publish, or upload anything. A manual release should build both game
binaries and the launcher from the same source revision, verify the bundled
translation patch, and install them as `bin/wpj2-jp`, `bin/wpj2-en`, and
`bin/wpj2-launcher`.

See [docs/17-launcher.md](../../docs/17-launcher.md) for architecture,
research notes, the environment contract, and the required integration into
`CMakeLists.txt` and `src/main.cpp`.
