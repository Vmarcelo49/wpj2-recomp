/*
 * WPJ2 Recomp - SDL2 Input Backend implementation
 */

#include "input.hpp"

#include <SDL.h>

#include <cmath>
#include <cstdio>
#include <mutex>

namespace wpj2 {

namespace {
    // N64/libultra controller bits from os_cont.h.
    constexpr uint16_t BTN_A      = 0x8000;
    constexpr uint16_t BTN_B      = 0x4000;
    constexpr uint16_t BTN_Z      = 0x2000;
    constexpr uint16_t BTN_START  = 0x1000;
    constexpr uint16_t BTN_DU     = 0x0800;
    constexpr uint16_t BTN_DD     = 0x0400;
    constexpr uint16_t BTN_DL     = 0x0200;
    constexpr uint16_t BTN_DR     = 0x0100;
    constexpr uint16_t BTN_L      = 0x0020;
    constexpr uint16_t BTN_R      = 0x0010;
    constexpr uint16_t BTN_CU     = 0x0008;
    constexpr uint16_t BTN_CD     = 0x0004;
    constexpr uint16_t BTN_CL     = 0x0002;
    constexpr uint16_t BTN_CR     = 0x0001;

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
        if (kb[SDL_SCANCODE_Q])                            b |= BTN_L;
        if (kb[SDL_SCANCODE_E])                            b |= BTN_R;
        if (kb[SDL_SCANCODE_I])                            b |= BTN_CU;
        if (kb[SDL_SCANCODE_K])                            b |= BTN_CD;
        if (kb[SDL_SCANCODE_J])                            b |= BTN_CL;
        if (kb[SDL_SCANCODE_L])                            b |= BTN_CR;
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
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_LEFTSHOULDER))   b |= BTN_L;
        if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER))  b |= BTN_R;
        return b;
    }

    // SDL reports -32768..32767 with negative Y meaning "stick pushed up".
    // N64 OSContPad uses +127 for up. Invert Y and discard small drift, then
    // rescale the remaining range so full deflection still reaches 1.0.
    constexpr float ANALOG_DEADZONE = 0.12f;

    float apply_deadzone(float value) {
        if (std::fabs(value) < ANALOG_DEADZONE) return 0.0f;
        const float sign = value < 0.0f ? -1.0f : 1.0f;
        return sign * (std::fabs(value) - ANALOG_DEADZONE) / (1.0f - ANALOG_DEADZONE);
    }

    void gamepad_analog(SDL_GameController* pad, float* x, float* y) {
        Sint16 sx = SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTX);
        Sint16 sy = SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTY);
        constexpr float INV = 1.0f / 32768.0f;
        *x = apply_deadzone(sx * INV);
        *y = apply_deadzone(-sy * INV);
    }

    // Caller must hold g_input_mtx.
    ultramodern::input::connected_device_info_t device_info_locked(int controller_num) {
        if (controller_num < 0 || controller_num >= 4) {
            return {ultramodern::input::Device::None, ultramodern::input::Pak::None};
        }
        // WPJ2 needs a Controller Pak before it will initialise PFS. The
        // runtime sets CONT_CARD_ON for any Pak != None; osPfs* filesystem
        // operations are handled by our own Controller Pak shims.
        if (controller_num == 0 || g_pads[controller_num] != nullptr) {
            return {ultramodern::input::Device::Controller,
                    ultramodern::input::Pak::ControllerPak};
        }
        return {ultramodern::input::Device::None, ultramodern::input::Pak::None};
    }

    // Track which joystick indices are already assigned to avoid opening
    // the same physical device multiple times (common with wireless dongles
    // that expose multiple HID interfaces).
    int find_first_free_controller() {
        int n = SDL_NumJoysticks();
        for (int j = 0; j < n; j++) {
            if (!SDL_IsGameController(j)) continue;

            // Check if this joystick index is already opened in any slot
            bool already_open = false;
            for (int k = 0; k < 4; k++) {
                if (g_pads[k] == nullptr) continue;
                SDL_Joystick* opened_joy = SDL_GameControllerGetJoystick(g_pads[k]);
                if (opened_joy != nullptr) {
                    SDL_JoystickID opened_id = SDL_JoystickInstanceID(opened_joy);
                    // SDL_JoystickGetDeviceInstanceID returns the instance ID
                    // that a joystick WOULD get if opened. Compare to see if
                    // this device is already open.
                    SDL_JoystickID device_id = SDL_JoystickGetDeviceInstanceID(j);
                    if (device_id == opened_id) {
                        already_open = true;
                        break;
                    }
                }
            }
            if (!already_open) {
                return j;
            }
        }
        return -1;
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
            int j = find_first_free_controller();
            if (j >= 0) {
                g_pads[i] = SDL_GameControllerOpen(j);
                if (g_pads[i] != nullptr) {
                    fprintf(stderr, "[WPJ2/Input] P%d: opened '%s' (joystick %d)\n",
                            i + 1, SDL_GameControllerName(g_pads[i]), j);
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
    std::lock_guard<std::mutex> lock(g_input_mtx);
    // WPJ2 uses a synthetic Controller Pak, not physical rumble hardware.
    // Only vibrate when a real RumblePak is reported, so osMotorStart can
    // never make the emulated Pak rumble by accident.
    if (device_info_locked(controller_num).connected_pak !=
        ultramodern::input::Pak::RumblePak) {
        return;
    }
    if (g_pads[controller_num] == nullptr) return;
    SDL_GameControllerRumble(g_pads[controller_num],
                             rumble ? 0xFFFF : 0,
                             rumble ? 0xFFFF : 0,
                             200);
}

ultramodern::input::connected_device_info_t input_get_connected_device_info(int controller_num) {
    std::lock_guard<std::mutex> lock(g_input_mtx);
    return device_info_locked(controller_num);
}

} // namespace wpj2
