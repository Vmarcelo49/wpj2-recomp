# Wonder Project J2 — Recompiled

A native PC port of *Wonder Project J2: Koruro no Mori no Josette* (ワープロジェクトJ2),
the 1996 Enix/Givro adventure for Nintendo 64. It is a recompilation, not an
emulator: the game runs as a normal PC program, with a Vulkan renderer and PC
audio/input. Both the original Japanese text and a full English text fan
translation are playable.

This project was created with AI assistance (Z.ai GLM 5.2).

## Supported platforms

| Platform | Download | Requirements |
|---|---|---|
| Linux | AppImage (`WPJ2-Recomp-full-x86_64.AppImage`) | Vulkan-capable GPU and current graphics drivers |
| Windows 10/11 (64-bit) | ZIP (`wpj2-windows-x64-<version>.zip`) | Vulkan-capable GPU and current graphics drivers |

There is no macOS build. A reasonably modern PC (4+ CPU cores, 8+ GB RAM) is
recommended. The game runs at 60 FPS on tested hardware.

**No ROM is included.** You must supply your own legally obtained Japanese
copy of the game in `.z64` format.

## What you need

1. The release file for your platform (AppImage or Windows ZIP).
2. Your own Japanese Wonder Project J2 ROM (`.z64`). Its MD5 must be
   `0ff1f8628d8fe69582db54572d2bea79`.
3. A Vulkan-capable graphics card with up-to-date drivers (Intel, AMD or
   NVIDIA).

## Install and run

### Linux

1. Download the AppImage and make it executable:

   ```bash
   chmod +x WPJ2-Recomp-full-x86_64.AppImage
   ```

2. Put your Japanese `.z64` ROM **in the same folder** as the AppImage.
3. Run it by double-clicking, or from a terminal:

   ```bash
   ./WPJ2-Recomp-full-x86_64.AppImage
   ```

   If your system cannot mount AppImages (no FUSE), try
   `./WPJ2-Recomp-full-x86_64.AppImage --appimage-extract-and-run`.

### Windows

1. Download the ZIP and extract the **whole archive** into a folder (do not
   move the `.exe` on its own — it needs the DLLs beside it).
2. Put your Japanese `.z64` ROM **in the same folder** as
   `WPJ2-Recompiled.exe`.
3. Double-click `WPJ2-Recompiled.exe`.

The first launch may take a few seconds while the game prepares its files.

## ROM detection

On startup the launcher looks for a valid ROM in the folder containing the
executable (for AppImages, the folder containing the AppImage). If it cannot
find one, you will see:

> ROM NOT DETECTED, PLEASE PLACE THE ROM ON THE SAME FOLDER AS THE EXECUTABLE
> **CHECK FOR ROM**

Copy your ROM next to the executable and press the button (or Enter) to check
again. Once a valid ROM is found, the main launcher menu appears.

## Launcher and settings

The launcher is the first screen you see. Use **Up/Down** to pick a row and
**Left/Right** to change its value:

| Setting | Options |
|---|---|
| Variant | Japanese (original) or English (fan translation) |
| Fullscreen | On / Off |
| Integer scaling | On (sharp 4:3 with borders) / Off (fill window) |
| Audio volume | 0–100 |

Press **Enter** to start the game, **S** to save your settings, and **Esc** to
quit. Press **G** to generate the English ROM from your Japanese ROM and the
bundled translation patch; the game also does this automatically when needed.

Japanese and English use separate game files and separate save/config folders,
so your progress in one language does not affect the other.

## Playing

### Controls

| N64 button | Keyboard | Gamepad |
|---|---|---|
| A | Enter / Space | A |
| B | Left Shift / Right Shift / Z | B or Y |
| Z | X | X, L or R |
| Start | C / Backspace | Start or Back |
| D-pad | Arrow keys or WASD | D-pad |
| Analog stick | — | Left stick |

Gamepads are supported through SDL2 and can be plugged in while the game is
running.

### In-game hotkeys

| Key | Action |
|---|---|
| **F9** | Toggle integer scaling ↔ stretch to screen |
| **F11** | Toggle fullscreen |

### Saves

The original game uses a Controller Pak. The PC port emulates it automatically;
you do not need to configure anything. Use the game's own save menu to record
progress. Save files are stored per language in the launcher's config folder
under your user profile — keep them if you want to keep your progress, and do
not mix Japanese and English save folders.

## Troubleshooting

| Problem | What to try |
|---|---|
| "ROM NOT DETECTED" | Put the Japanese `.z64` beside the executable/AppImage, then press **Check for Rom**. The ROM must be the original Japanese game (MD5 above). |
| Black screen or Vulkan error | Update your graphics drivers. On Linux Wayland, try `SDL_VIDEODRIVER=wayland` before the executable name. |
| AppImage will not open | Give it execute permission, or install FUSE. Otherwise try `--appimage-extract-and-run`. |
| Windows says a DLL is missing | Re-extract the entire ZIP; the `.exe` must stay with its DLL files. |
| No sound | Check your system volume and the launcher's audio volume setting. |
| Gamepad not detected | Reconnect the controller; SDL2 supports hot-plug. Keyboard always works. |
| English text missing or patch error | Keep the bundled `Wpj2e_v1_z64.ips` with the release files and start from an unmodified Japanese ROM. |
| Saves not appearing | Save from inside the game. Progress is stored per language; check the `jp` / `en` config folder. |
| Poor performance | Update GPU drivers and close other demanding applications. |

## Legal note

The source code is released under the [MIT License](LICENSE). This project does
**not** include or distribute any ROM, game assets, or copyrighted game data.
You must provide your own legally obtained copy of Wonder Project J2. The
community English translation patch is included as data only. Software
recompilation is used here as a preservation technique; respect the rights of
the original copyright holders.

## More information

- [Building and packaging](docs/BUILDING.md) — source builds, toolchain, release scripts, tests
- [English translation details](docs/13-english-patch.md)
- [Launcher details](docs/17-launcher.md)
- [Technical profile](docs/01-technical-profile.md)
- [Save system](docs/05-save-system.md)
