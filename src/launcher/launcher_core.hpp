#ifndef WPJ2_LAUNCHER_CORE_HPP
#define WPJ2_LAUNCHER_CORE_HPP

#include <cstdint>
#include <filesystem>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace wpj2_launcher {

enum class Variant { Jp, En };

struct Config {
    Variant variant = Variant::Jp;
    std::filesystem::path jp_rom = "input/wpj2.j1.z64";
    std::filesystem::path en_rom = "input/wpj2.en.z64";
    std::filesystem::path ips_patch = "patches/Wpj2e_v1_z64.ips";
    std::filesystem::path game_jp = "bin/wpj2-jp";
    std::filesystem::path game_en = "bin/wpj2-en";
    std::filesystem::path config_dir; // empty means ~/.config/wpj2-recomp/launcher
    bool fullscreen = false;
    bool integer_scaling = true;
    int audio_volume = 100;
    std::string graphics_api = "Auto";
    bool skip_launcher = false;
};

struct LaunchPlan {
    std::filesystem::path executable;
    std::vector<std::string> argv;
    std::vector<std::pair<std::string, std::string>> environment;
    Variant variant = Variant::Jp;
};

struct CicHash {
    uint32_t first = 0;
    uint32_t second = 0;
};

std::string variant_name(Variant variant);

std::filesystem::path default_config_file();

Config load_config(const std::filesystem::path& path, std::string* error = nullptr);
bool save_config(const std::filesystem::path& path, const Config& config, std::string* error = nullptr);

CicHash cic_hash(const std::filesystem::path& rom, std::string* error = nullptr);
bool verify_jp_rom(const std::filesystem::path& rom, std::string* error = nullptr);
bool verify_en_rom(const std::filesystem::path& rom, std::string* error = nullptr);

// Search beside the running executable and the user-facing AppImage/archive
// root for a valid Japanese or English ROM. Updates the config when found.
bool discover_roms(Config& config);

// Locate the bundled IPS patch in release layouts.
bool discover_patch(Config& config);

bool apply_ips(const std::filesystem::path& jp_rom,
               const std::filesystem::path& ips,
               const std::filesystem::path& output,
               std::string* error = nullptr);

// Ensures en_rom exists and is valid. If generate_missing is true, an invalid
// or missing English ROM is rebuilt from jp_rom plus the tracked IPS patch.
bool ensure_en_rom(const Config& config, bool generate_missing, std::string* error = nullptr);

LaunchPlan make_plan(const Config& config, bool generate_en, std::string* error = nullptr);
std::string describe_plan(const LaunchPlan& plan);
int launch(const LaunchPlan& plan, std::string* error = nullptr);

} // namespace wpj2_launcher

#endif
