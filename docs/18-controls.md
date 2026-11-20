# 18 — Controls

Wonder Project J2 was designed for the Nintendo 64 controller. The native port
accepts a keyboard or up to four SDL2 gamepads.

## Keyboard (Player 1)

| N64 button | Keyboard |
|---|---|
| A (confirm / action) | Enter or Space |
| B (cancel) | Left Shift, Right Shift, or Z |
| Z (talk / contextual) | X |
| Start (menu) | C or Backspace |
| D-pad Up | Up arrow or W |
| D-pad Down | Down arrow or S |
| D-pad Left | Left arrow or A |
| D-pad Right | Right arrow or D |
| L shoulder | Q |
| R shoulder | E |
| C-up | I |
| C-down | K |
| C-left | J |
| C-right | L |

The keyboard is always available as Player 1. If a gamepad is also connected
on port 1, its buttons are merged with the keyboard.

## Gamepad

| N64 button | SDL gamepad |
|---|---|
| A | A (south) |
| B | B (east) or Y (north) |
| Z | X (west) |
| L shoulder | L (left shoulder) |
| R shoulder | R (right shoulder) |
| Start | Start or Back |
| D-pad | D-pad |
| Analog stick | Left stick |

Gamepads are detected automatically, including hot-plug. The first gamepad
becomes Player 1, the next Player 2, and so on, up to four players.

The left stick drives the N64 analog stick. A small dead zone removes drift,
and the vertical axis is inverted to match the N64 convention (pushing the
stick **up** produces a positive Y value).

## Controller Pak (saves)

WPJ2 saves exclusively to a Controller Pak; it has no EEPROM or FlashRAM.

Port 1 always reports a Controller Pak so the game will boot and initialise
its save filesystem. The Pak is stored on disk as
`controller_pak_0.bin` inside the active config directory. Additional numbered
Pak files are used for other ports.

Because the reported Pak is synthetic, rumble commands from the game never
vibrate a physical controller. WPJ2 does not use rumble for gameplay.

## Scaling hotkey

Press **F9** to toggle integer scaling and stretch-to-screen. The older `S`
hotkey conflicted with D-pad Down and was removed.

## Graphics API

The launcher can choose **Auto**, **D3D12**, or **Vulkan**. Auto selects D3D12 on Windows and Vulkan on other platforms. If a backend fails to initialize, try a different option. The choice is exported as `WPJ2_GRAPHICS_API` to the game.
