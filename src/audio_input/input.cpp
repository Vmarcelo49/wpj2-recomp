/*
 * WPJ2 Recomp - SDL2 Input Backend implementation
 */

#include "input.hpp"

#include <SDL2/SDL.h>

#include <cstdio>
#include <cstring>
#include <mutex>

namespace wpj2 {

namespace {
    // N64 button bitmask (matches the libultra ordering used by ultramodern):
    // bit 15: A          bit 14: B
    // bit 13: Z          bit 12: Start
    // bit 11: U  bit 10: D  bit 9: L  bit 8: R  (D-pad)
    // bits 7..0: C-pad + reserved (C-up=0x20, C-down=0x10, C-left=0x08, C-right=0x04)
    // We just match the constants used by libultra / recomp:
    // 0x8000=A, 0x4000=B, 0x2000=Z, 0x1000=Start,
    // 0x0800=DU, 0x0400=DD, 0x0200=DL, 0x0100=DR
    // (C-buttons usually 0x0020..0x0008, unused by WPJ2 main gameplay.)
    constexpr uint16_t BTN_A      = 0x8000;
    constexpr uint16_t BTN_B      = 0x4000;
    constexpr uint16_t BTN_Z      = 0x2000;
    constexpr uint16_t BTN_START  = 0x1000;
    constexpr uint16_t BTN_DU     = 0x0800;
    constexpr uint16_t BTN_DD     = 0x0400;
    constexpr uint16_t BTN_DL     = 0x0200;
    constexpr uint16_t BTN_DR     = 0x0100;

    std::mutex g_input_mtx;
    SDL_GameController* g_pads[4] = {nullptr, nullptr, nullptr, nullptr};

    uint16_t keyboard_to_n64(const Uint8* kb) {
        uint16_t b = 0;
        if (kb[SDL_SCANCODE_RETURN]  || kb[SDL_SCANCODE_SPACE])  b |= BTN_A;
        if (kb[SDL_SCANCODE_LSHIFT]  || kb[SDL_SCANCODE_RSHIFT]) b |= BTN_B;
        if (kb[SDL_SCANCODE_Z])                                  b |= BTN_B; // alt
        if (kb[SDL_SCANCODE_X])                                  b |= BTN_Z;
        if (kb[SDL_SCANCODE_C] || kb[SDL_SCANCODE_BACKSPACE])   b |= BTN_START;
        if (kb[SDL_SCANCODE_UP]    || kb[SDL_SCANCODE_W]) b |= BTN_DU;
        if (kb[SDL_SCANCODE_DOWN]  || kb[SDL_SCANCODE_S]) b |= BTN_DD;
        if (kb[SDL_SCANCODE_LEFT]  || kb[SDL_SCANCODE_A]) b |= BTN_DL;
        if (kb[SDL_SCANCODE_RIGHT] || kb[SDL_SCANCODE_D]) b |= BTN_DR;
        return b;
    }

    uint16_t gamepad_to_n64(SDL_GameController* pad) {
        uint16_t b = 0;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_A))              b |= BTN_A;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_B))              b |= BTN_B;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_X))              b |= BTN_Z;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_Y))              b |= BTN_B;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_START))          b |= BTN_START;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_BACK))           b |= BTN_START;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_DPAD_UP))        b |= BTN_DU;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_DPAD_DOWN))      b |= BTN_DD;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_DPAD_LEFT))      b |= BTN_DL;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_DPAD_RIGHT))     b |= BTN_DR;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_LEFTSHOULDER))   b |= BTN_Z;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER))  b |= BTN_Z;
        return b;
    }

    void gamepad_analog(SDL_GameController* pad, float* x, float* y) {
        Sint16 sx = SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTX);
        Sint16 sy = SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTY);
        constexpr float INV = 1.0f / 32768.0f;
        *x = sx * INV;
        *y = sy * INV;
    }
}

void input_poll() {
    std::lock_guard<std::mutex> lock(g_input_mtx);
    SDL_PumpEvents();

    // Hot-plug: scan for newly attached controllers in slots 0..3
    for (int i = 0; i < 4; i++) {
        if (g_pads[i] != nullptr) {
            if (!SDL_GameControllerGetAttached(g_pads[i])) {
                SDL_GameControllerClose(g_pads[i]);
                g_pads[i] = nullptr;
            }
        } else {
            // Find first unattached joystick that is a game controller
            int n = SDL_NumJoysticks();
            for (int j = 0; j < n; j++) {
                bool used = false;
                for (int k = 0; k < 4; k++) {
                    if (g_pads[k] != nullptr && SDL_JoystickGetDeviceGUID(j).data == SDL_JoystickGetGUID(SDL_GameControllerGetJoystick(g_pads[k])).data) {
                        used = true;
                        break;
                    }
                }
                if (!used && SDL_IsGameController(j)) {
                    g_pads[i] = SDL_GameControllerOpen(j);
                    if (g_pads[i] != nullptr) {
                        fprintf(stderr, "[WPJ2/Input] P%d: opened '%s'\n",
                                i + 1, SDL_GameControllerName(g_pads[i]));
                    }
                    break;
                }
            }
        }
    }
}

bool input_get(int controller_num, uint16_t* buttons, float* x, float* y) {
    if (controller_num < 0 || controller_num >= 4) return false;

    std::lock_guard<std::mutex> lock(g_input_mtx);
    uint16_t b = 0;
    float ax = 0.0f, ay = 0.0f;

    if (controller_num == 0) {
        // P1: keyboard OR gamepad if attached
        const Uint8* kb = SDL_GetKeyboardState(nullptr);
        b = keyboard_to_n64(kb);
        if (g_pads[0] != nullptr) {
            b |= gamepad_to_n64(g_pads[0]);
            gamepad_analog(g_pads[0], &ax, &ay);
        }
    } else if (controller_num < 4 && g_pads[controller_num] != nullptr) {
        b = gamepad_to_n64(g_pads[controller_num]);
        gamepad_analog(g_pads[controller_num], &ax, &ay);
    }

    *buttons = b;
    *x = ax;
    *y = ay;
    return true;
}

void input_set_rumble(int controller_num, bool rumble) {
    if (controller_num < 0 || controller_num >= 4) return;
    std::lock_guard<std::mutex> lock(g_input_mtx);
    if (g_pads[controller_num] == nullptr) return;
    SDL_GameControllerRumble(g_pads[controller_num],
                             rumble ? 0xFFFF : 0,
                             rumble ? 0xFFFF : 0,
                             200);
}

ultramodern::input::connected_device_info_t input_get_connected_device_info(int controller_num) {
    if (controller_num < 0 || controller_num >= 4) {
        return {ultramodern::input::Device::None, ultramodern::input::Pak::None};
    }
    // WPJ2 uses Controller Pak (MPK) for saves. ultramodern's input::Pak
    // enum doesn't expose ControllerPak yet, so we report None here —
    // the MPK save path is handled separately by librecomp.
    std::lock_guard<std::mutex> lock(g_input_mtx);
    if (controller_num == 0 || g_pads[controller_num] != nullptr) {
        return {ultramodern::input::Device::Controller, ultramodern::input::Pak::None};
    }
    return {ultramodern::input::Device::None, ultramodern::input::Pak::None};
}

} // namespace wpj2
