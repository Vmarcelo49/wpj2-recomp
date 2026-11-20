#include "launcher_core.hpp"
#include "embedded_font.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <SDL.h>

namespace {

using wpj2_launcher::Config;
using wpj2_launcher::Variant;

using FontTexture = std::unique_ptr<SDL_Texture, void (*)(SDL_Texture*)>;

FontTexture create_font_texture(SDL_Renderer* renderer) {
    namespace font = wpj2_launcher::font;
    constexpr int glyph_count = font::last_char - font::first_char + 1;
    const int width = font::cell_width * glyph_count;

    std::vector<uint32_t> pixels(static_cast<size_t>(width) * font::cell_height);
    SDL_PixelFormat* format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
    if (format == nullptr) {
        std::cerr << "SDL_AllocFormat failed: " << SDL_GetError() << '\n';
        return {nullptr, SDL_DestroyTexture};
    }
    for (int glyph_index = 0; glyph_index < glyph_count; ++glyph_index) {
        const auto& glyph = font::glyphs[glyph_index];
        for (int row = 0; row < font::cell_height; ++row) {
            for (int col = 0; col < font::cell_width; ++col) {
                const uint8_t alpha = glyph.alpha[row * font::cell_width + col];
                const size_t dst = static_cast<size_t>(row) * width +
                                   glyph_index * font::cell_width + col;
                pixels[dst] = SDL_MapRGBA(format, 255, 255, 255, alpha);
            }
        }
    }
    SDL_FreeFormat(format);

    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(
        pixels.data(), width, font::cell_height, 32,
        width * static_cast<int>(sizeof(uint32_t)), SDL_PIXELFORMAT_RGBA8888);
    if (surface == nullptr) {
        std::cerr << "SDL_CreateRGBSurfaceWithFormatFrom failed: " << SDL_GetError() << '\n';
        return {nullptr, SDL_DestroyTexture};
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << '\n';
        return {nullptr, SDL_DestroyTexture};
    }
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    return {texture, SDL_DestroyTexture};
}

void draw_text(SDL_Renderer* renderer, SDL_Texture* font_texture,
               int x, int y, const std::string& text, int scale, SDL_Color color) {
    namespace font = wpj2_launcher::font;
    SDL_SetTextureColorMod(font_texture, color.r, color.g, color.b);
    SDL_SetTextureAlphaMod(font_texture, color.a);
    for (unsigned char raw : text) {
        if (raw < font::first_char || raw > font::last_char) continue;
        const int glyph_index = raw - font::first_char;
        const SDL_Rect src{glyph_index * font::cell_width, 0,
                           font::cell_width, font::cell_height};
        const SDL_Rect dst{x, y, font::cell_width * scale, font::cell_height * scale};
        SDL_RenderCopy(renderer, font_texture, &src, &dst);
        x += font::glyphs[glyph_index].advance * scale;
    }
}

std::string status_for_paths(const Config& config) {
    std::string jp = wpj2_launcher::verify_jp_rom(config.jp_rom, nullptr) ? "OK" : "INVALID";
    std::string en = wpj2_launcher::verify_en_rom(config.en_rom, nullptr) ? "OK" : "GENERATE";
    std::string game = config.variant == Variant::En ? config.game_en.string() : config.game_jp.string();
    std::error_code ec;
    std::string game_status = std::filesystem::exists(game, ec) ? "OK" : "MISSING";
    return "JP ROM: " + jp + "  EN ROM: " + en + "  GAME: " + game_status;
}

struct Button {
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
};

bool point_in_button(const Button& button, int x, int y) {
    return x >= button.x && x < button.x + button.width &&
           y >= button.y && y < button.y + button.height;
}

void render_rom_prompt(SDL_Renderer* renderer, SDL_Texture* font_texture,
                       const std::string& status, Button& button) {
    SDL_SetRenderDrawColor(renderer, 14, 16, 24, 255);
    SDL_RenderClear(renderer);

    const SDL_Color text{225, 230, 238, 255};
    const SDL_Color muted{150, 160, 175, 255};
    const SDL_Color border{120, 200, 255, 255};
    draw_text(renderer, font_texture, 40, 120,
              "ROM NOT DETECTED, PLEASE PLACE THE ROM", 1, text);
    draw_text(renderer, font_texture, 40, 150,
              "ON THE SAME FOLDER AS THE EXECUTABLE", 1, text);

    button = {40, 205, 220, 40};
    SDL_SetRenderDrawColor(renderer, 32, 38, 54, 255);
    const SDL_Rect fill{button.x, button.y, button.width, button.height};
    SDL_RenderFillRect(renderer, &fill);
    SDL_SetRenderDrawColor(renderer, border.r, border.g, border.b, 255);
    SDL_RenderDrawRect(renderer, &fill);
    draw_text(renderer, font_texture, button.x + 12, button.y + 10,
              "CHECK FOR ROM", 1, text);

    if (!status.empty() && status != "READY") {
        draw_text(renderer, font_texture, 40, 270, status, 1, muted);
    }
    SDL_RenderPresent(renderer);
}

void render_ui(SDL_Renderer* renderer, SDL_Texture* font_texture,
               const Config& config, int selected,
               const std::string& status, int /*width*/, int height) {
    SDL_SetRenderDrawColor(renderer, 14, 16, 24, 255);
    SDL_RenderClear(renderer);

    SDL_Color heading{120, 200, 255, 255};
    SDL_Color normal{225, 230, 238, 255};
    SDL_Color active{255, 215, 90, 255};
    SDL_Color muted{150, 160, 175, 255};

    draw_text(renderer, font_texture, 40, 30, "WONDER PROJECT J2 LAUNCHER", 2, heading);
    draw_text(renderer, font_texture, 40, 86, status_for_paths(config), 1, muted);

    const std::array<std::string, 7> labels = {
        "VARIANT: " + std::string(wpj2_launcher::variant_name(config.variant) == "jp" ? "JAPANESE" : "ENGLISH"),
        std::string("FULLSCREEN: ") + (config.fullscreen ? "ON" : "OFF"),
        std::string("INTEGER SCALING: ") + (config.integer_scaling ? "ON" : "OFF"),
        "AUDIO VOLUME: " + std::to_string(config.audio_volume),
        "ENTER - LAUNCH",
        "G - GENERATE EN ROM",
        "S - SAVE / ESC - QUIT",
    };

    for (int i = 0; i < static_cast<int>(labels.size()); ++i) {
        draw_text(renderer, font_texture, 60, 140 + i * 44, labels[i], 1,
                  i == selected ? active : normal);
    }

    draw_text(renderer, font_texture, 40, height - 70, "UP/DOWN SELECT  LEFT/RIGHT CHANGE", 1, muted);
    draw_text(renderer, font_texture, 40, height - 45, status, 1, normal);
    SDL_RenderPresent(renderer);
}

int run_ui(const std::filesystem::path& config_path, Config config) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << '\n';
        return 1;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_Window* window = SDL_CreateWindow("WPJ2 Launcher", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, 960, 600,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer failed: " << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    auto font_texture = create_font_texture(renderer);
    if (!font_texture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int selected = 0;
    std::string status = "READY";
    bool rom_ready = wpj2_launcher::discover_roms(config);
    wpj2_launcher::discover_patch(config);
    bool running = true;
    while (running) {
        int width = 960;
        int height = 600;
        SDL_GetWindowSize(window, &width, &height);
        Button rom_button;
        if (rom_ready) {
            render_ui(renderer, font_texture.get(), config, selected, status, width, height);
        } else {
            render_rom_prompt(renderer, font_texture.get(), status, rom_button);
        }

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (!rom_ready) {
                if (event.type == SDL_MOUSEBUTTONDOWN &&
                    event.button.button == SDL_BUTTON_LEFT &&
                    point_in_button(rom_button, event.button.x, event.button.y)) {
                    rom_ready = wpj2_launcher::discover_roms(config);
                    status = rom_ready ? "ROM READY" : "ROM STILL NOT DETECTED";
                } else if (event.type == SDL_KEYDOWN &&
                           (event.key.keysym.sym == SDLK_RETURN ||
                            event.key.keysym.sym == SDLK_SPACE)) {
                    rom_ready = wpj2_launcher::discover_roms(config);
                    status = rom_ready ? "ROM READY" : "ROM STILL NOT DETECTED";
                }
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                    case SDLK_UP:
                        selected = (selected + 6) % 7;
                        break;
                    case SDLK_DOWN:
                        selected = (selected + 1) % 7;
                        break;
                    case SDLK_LEFT:
                    case SDLK_RIGHT: {
                        const int delta = event.key.keysym.sym == SDLK_RIGHT ? 1 : -1;
                        if (selected == 0) {
                            config.variant = config.variant == Variant::Jp ? Variant::En : Variant::Jp;
                        } else if (selected == 1) {
                            config.fullscreen = !config.fullscreen;
                        } else if (selected == 2) {
                            config.integer_scaling = !config.integer_scaling;
                        } else if (selected == 3) {
                            config.audio_volume = std::clamp(config.audio_volume + delta * 5, 0, 100);
                        }
                        break;
                    }
                    case SDLK_RETURN: {
                        std::string error;
                        const auto plan = wpj2_launcher::make_plan(config, true, &error);
                        if (!error.empty()) {
                            status = error;
                        } else {
                            SDL_DestroyRenderer(renderer);
                            SDL_DestroyWindow(window);
                            SDL_Quit();
                            return wpj2_launcher::launch(plan, &error);
                        }
                        break;
                    }
                    case SDLK_g: {
                        std::string error;
                        if (wpj2_launcher::ensure_en_rom(config, true, &error)) {
                            status = "EN ROM READY";
                        } else {
                            status = error;
                        }
                        break;
                    }
                    case SDLK_s: {
                        std::string error;
                        if (wpj2_launcher::save_config(config_path, config, &error)) {
                            status = "CONFIG SAVED";
                        } else {
                            status = error;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        }
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void print_help() {
    std::cout <<
        "Usage: wpj2-launcher [options]\n"
        "\n"
        "Options:\n"
        "  --config PATH       Launcher config file (default ~/.config/wpj2-recomp/launcher.ini)\n"
        "  --variant jp|en     Select game variant\n"
        "  --jp-rom PATH       Original Japanese ROM\n"
        "  --en-rom PATH       Canonical English ROM (or generation target)\n"
        "  --ips PATH          English IPS patch\n"
        "  --game-jp PATH      Japanese recomp executable\n"
        "  --game-en PATH      English recomp executable\n"
        "  --fullscreen        Request fullscreen on launch\n"
        "  --windowed          Request windowed mode\n"
        "  --integer-scaling   Request integer scaling\n"
        "  --stretch           Request stretched scaling\n"
        "  --volume N          Audio volume 0..100\n"
        "  --make-en           Generate canonical EN ROM from JP + IPS when needed\n"
        "  --dry-run           Print the launch plan and exit\n"
        "  --save-config       Save overrides to the config file\n"
        "  --no-gui            Use the command-line flow instead of SDL UI\n"
        "  --help              Show this help\n";
}

bool needs_value(const std::string& arg) {
    return arg == "--config" || arg == "--variant" || arg == "--jp-rom" ||
           arg == "--en-rom" || arg == "--ips" || arg == "--game-jp" ||
           arg == "--game-en" || arg == "--volume";
}

} // namespace

int main(int argc, char** argv) {
    std::filesystem::path config_path = wpj2_launcher::default_config_file();
    // Pre-scan --config so the selected file is loaded before other overrides.
    for (int i = 1; i + 1 < argc; ++i) {
        if (std::string(argv[i]) == "--config") {
            config_path = argv[i + 1];
        }
    }
    std::string config_error;
    Config config = wpj2_launcher::load_config(config_path, &config_error);
    if (!config_error.empty()) {
        std::cerr << "Config warning: " << config_error << '\n';
        config_error.clear();
    }
    if (const char* rom_env = std::getenv("WPJ2_ROM")) {
        if (*rom_env != '\0') {
            const std::filesystem::path rom{rom_env};
            if (wpj2_launcher::verify_jp_rom(rom, nullptr)) {
                config.jp_rom = rom;
            } else if (wpj2_launcher::verify_en_rom(rom, nullptr)) {
                config.en_rom = rom;
            }
        }
    }

    bool no_gui = false;
    bool dry_run = false;
    bool save_config = false;
    bool generate_en = false;

    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];
        if (arg == "--help") {
            print_help();
            return 0;
        }
        if (arg == "--no-gui") {
            no_gui = true;
            continue;
        }
        if (arg == "--dry-run") {
            dry_run = true;
            continue;
        }
        if (arg == "--save-config") {
            save_config = true;
            continue;
        }
        if (arg == "--make-en") {
            generate_en = true;
            continue;
        }
        if (arg == "--fullscreen") {
            config.fullscreen = true;
            continue;
        }
        if (arg == "--windowed") {
            config.fullscreen = false;
            continue;
        }
        if (arg == "--integer-scaling") {
            config.integer_scaling = true;
            continue;
        }
        if (arg == "--stretch") {
            config.integer_scaling = false;
            continue;
        }
        if (!needs_value(arg)) {
            std::cerr << "Unknown option: " << arg << '\n';
            print_help();
            return 1;
        }
        if (i + 1 >= argc) {
            std::cerr << "Missing value for " << arg << '\n';
            return 1;
        }
        const std::string value = argv[++i];
        if (arg == "--config") config_path = value;
        else if (arg == "--variant") {
            if (value == "jp" || value == "Japanese") config.variant = Variant::Jp;
            else if (value == "en" || value == "English") config.variant = Variant::En;
            else {
                std::cerr << "Invalid variant: " << value << '\n';
                return 1;
            }
        }
        else if (arg == "--jp-rom") config.jp_rom = value;
        else if (arg == "--en-rom") config.en_rom = value;
        else if (arg == "--ips") config.ips_patch = value;
        else if (arg == "--game-jp") config.game_jp = value;
        else if (arg == "--game-en") config.game_en = value;
        else if (arg == "--volume") {
            try {
                config.audio_volume = std::clamp(std::stoi(value), 0, 100);
            } catch (...) {
                std::cerr << "Invalid volume: " << value << '\n';
                return 1;
            }
        }
    }

    wpj2_launcher::discover_roms(config);
    wpj2_launcher::discover_patch(config);

    if (save_config) {
        std::string error;
        if (!wpj2_launcher::save_config(config_path, config, &error)) {
            std::cerr << "Cannot save config: " << error << '\n';
            return 1;
        }
    }

    if (dry_run || no_gui) {
        std::string error;
        const auto plan = wpj2_launcher::make_plan(config, generate_en, &error);
        if (!error.empty()) {
            std::cerr << "Cannot prepare launch: " << error << '\n';
            return 1;
        }
        if (dry_run) {
            std::cout << wpj2_launcher::describe_plan(plan);
            return 0;
        }
        return wpj2_launcher::launch(plan, &error);
    }

    return run_ui(config_path, config);
}
