/*
 * WPJ2 Recomp - SDL2 Input Backend
 *
 * Keyboard fallback for P1 (no gamepad required):
 *   Arrow keys / WASD  -> D-pad
 *   Enter / Space      -> A button
 *   L-Shift / Z        -> B button
 *   X                  -> Z (trigger)
 *   C / Backspace      -> Start
 *
 * Gamepad support via SDL_GameController (auto-detect).
 *
 * WPJ2 in-game controls (N64 controller):
 *   A: confirm / action
 *   B: cancel / secondary action
 *   Z: contextual (talk to NPC, etc.)
 *   Start: menu
 *   Analog: movement (we don't have analog on keyboard, so D-pad doubles)
 */

#ifndef WPJ2_INPUT_HPP
#define WPJ2_INPUT_HPP

#include "ultramodern/input.hpp"

namespace wpj2 {

void input_poll();
bool input_get(int controller_num, uint16_t* buttons, float* x, float* y);
void input_set_rumble(int controller_num, bool rumble);
ultramodern::input::connected_device_info_t input_get_connected_device_info(int controller_num);

} // namespace wpj2

#endif // WPJ2_INPUT_HPP
