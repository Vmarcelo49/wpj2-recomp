#include "launcher_core.hpp"

#include <algorithm>
#include <array>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <map>
#include <sstream>

#if defined(_WIN32)
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace wpj2_launcher {
namespace {

constexpr uint64_t JP_ROM_SIZE = 8 * 1024 * 1024;
constexpr uint64_t EN_ROM_SIZE = 8912896;
constexpr CicHash EXPECTED_JP_CIC{0xe43c9765u, 0x05b1c1beu};
constexpr CicHash EXPECTED_EN_CIC{0x4f1e88f7u, 0x4a5a3f96u};
constexpr uint32_t CIC_START = 0x1000;
constexpr uint32_t CIC_LENGTH = 0x100000;
constexpr uint32_t CIC_MASK = 0xFFFFFFFFu;

void set_error(std::string* error, const std::string& message) {
    if (error != nullptr) {
        *error = message;
    }
}

std::filesystem::path current_exe_dir();

std::filesystem::path resolve_executable(const std::filesystem::path& configured, Variant variant) {
    std::error_code ec;
    if (std::filesystem::exists(configured, ec)) {
        return std::filesystem::absolute(configured);
    }

    const char* name = variant == Variant::En ? "wpj2-en" : "wpj2-jp";
    const auto exe_dir = current_exe_dir();
    if (!exe_dir.empty()) {
        const auto siblings = {
            exe_dir / name,
            exe_dir / "bin" / name,
            exe_dir.parent_path() / "bin" / name,
            exe_dir.parent_path() / name,
        };
        for (const auto& path : siblings) {
            if (std::filesystem::exists(path, ec)) {
                return std::filesystem::absolute(path);
            }
        }
    }

    const auto candidates = {
        std::filesystem::path("bin") / name,
        std::filesystem::path(name),
        std::filesystem::path("..") / "bin" / name,
    };
    for (const auto& path : candidates) {
        if (std::filesystem::exists(path, ec)) {
            return std::filesystem::absolute(path);
        }
    }
    return configured;
}

std::filesystem::path current_exe_dir() {
    std::error_code ec;
#if defined(_WIN32)
    std::vector<wchar_t> buffer(4096);
    const DWORD length = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
    if (length == 0 || length >= buffer.size()) return {};
    return std::filesystem::path(std::wstring(buffer.data(), length)).parent_path();
#else
    std::vector<char> buffer(4096);
    const ssize_t length = readlink("/proc/self/exe", buffer.data(), buffer.size() - 1);
    if (length <= 0) return {};
    buffer[static_cast<size_t>(length)] = '\0';
    return std::filesystem::path(buffer.data()).parent_path();
#endif
}

#if defined(_WIN32)
bool quote_windows_arg(const std::string& arg, std::string& out) {
    out.push_back('"');
    for (char c : arg) {
        if (c == '"') {
            out += "\\\"";
        } else if (c == '\\') {
            out += "\\\\";
        } else {
            out.push_back(c);
        }
    }
    out.push_back('"');
    return true;
}
#endif

bool read_file(const std::filesystem::path& path, std::vector<uint8_t>& out, std::string* error) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        set_error(error, "cannot open " + path.string());
        return false;
    }
    file.seekg(0, std::ios::end);
    const auto size = file.tellg();
    if (size < 0) {
        set_error(error, "cannot determine size of " + path.string());
        return false;
    }
    out.resize(static_cast<size_t>(size));
    file.seekg(0, std::ios::beg);
    if (!out.empty() && !file.read(reinterpret_cast<char*>(out.data()), out.size())) {
        set_error(error, "cannot read " + path.string());
        return false;
    }
    return true;
}

bool write_file_atomic(const std::filesystem::path& path,
                       const std::vector<uint8_t>& data,
                       std::string* error) {
    const auto parent = path.parent_path();
    if (!parent.empty()) {
        std::error_code ec;
        std::filesystem::create_directories(parent, ec);
        if (ec) {
            set_error(error, "cannot create " + parent.string() + ": " + ec.message());
            return false;
        }
    }
    const auto temp = path.string() + ".tmp";
    {
        std::ofstream file(temp, std::ios::binary | std::ios::trunc);
        if (!file) {
            set_error(error, "cannot write " + temp);
            return false;
        }
        if (!data.empty()) {
            file.write(reinterpret_cast<const char*>(data.data()), data.size());
        }
        if (!file) {
            set_error(error, "cannot write " + temp);
            return false;
        }
    }
    std::error_code ec;
    std::filesystem::rename(temp, path, ec);
    if (ec) {
        set_error(error, "cannot replace " + path.string() + ": " + ec.message());
        return false;
    }
    return true;
}

uint32_t be32(const uint8_t* p) {
    return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) |
           (uint32_t(p[2]) << 8) | uint32_t(p[3]);
}

std::string hex32(uint32_t value) {
    std::ostringstream out;
    out << std::hex << std::setw(8) << std::setfill('0') << value;
    return out.str();
}

bool parse_ini(const std::filesystem::path& path,
               std::map<std::string, std::string>& values,
               std::string* error) {
    std::ifstream file(path);
    if (!file) {
        return false; // Missing config is not an error.
    }
    std::string line;
    int line_number = 0;
    while (std::getline(file, line)) {
        ++line_number;
        if (line.empty() || line[0] == '#' || line[0] == ';') {
            continue;
        }
        const auto equals = line.find('=');
        if (equals == std::string::npos) {
            set_error(error, path.string() + ":" + std::to_string(line_number) + ": expected key=value");
            return false;
        }
        auto key = line.substr(0, equals);
        auto value = line.substr(equals + 1);
        while (!key.empty() && (key.back() == ' ' || key.back() == '\t')) key.pop_back();
        while (!value.empty() && (value.front() == ' ' || value.front() == '\t')) value.erase(value.begin());
        while (!value.empty() && (value.back() == ' ' || value.back() == '\t')) value.pop_back();
        if (!key.empty()) {
            values[key] = value;
        }
    }
    return true;
}

std::string get_or(const std::map<std::string, std::string>& values,
                   const std::string& key,
                   const std::string& fallback) {
    const auto it = values.find(key);
    return it == values.end() ? fallback : it->second;
}

bool parse_bool(const std::string& text, bool fallback, std::string* error, const char* key) {
    if (text.empty()) return fallback;
    if (text == "1" || text == "true" || text == "yes" || text == "on") return true;
    if (text == "0" || text == "false" || text == "no" || text == "off") return false;
    set_error(error, std::string("invalid ") + key + ": " + text);
    return fallback;
}

std::filesystem::path home_dir() {
#if defined(_WIN32)
    const char* home = std::getenv("USERPROFILE");
    return home == nullptr ? std::filesystem::path{} : std::filesystem::path(home);
#else
    const char* home = std::getenv("HOME");
    return home == nullptr ? std::filesystem::path{} : std::filesystem::path(home);
#endif
}


} // namespace

std::string variant_name(Variant variant) {
    return variant == Variant::En ? "en" : "jp";
}

std::filesystem::path default_config_file() {
    const auto home = home_dir();
    if (home.empty()) {
        return "wpj2-launcher.ini";
    }
    return home / ".config" / "wpj2-recomp" / "launcher.ini";
}

Config load_config(const std::filesystem::path& path, std::string* error) {
    Config config;
    std::map<std::string, std::string> values;
    if (!parse_ini(path, values, error)) {
        return config;
    }

    const auto variant = get_or(values, "variant", "jp");
    if (variant == "en" || variant == "EN" || variant == "English") {
        config.variant = Variant::En;
    } else if (variant != "jp" && variant != "JP" && variant != "Japanese") {
        set_error(error, "invalid variant: " + variant);
    }

    config.jp_rom = get_or(values, "jp_rom", config.jp_rom.string());
    config.en_rom = get_or(values, "en_rom", config.en_rom.string());
    config.ips_patch = get_or(values, "ips_patch", config.ips_patch.string());
    config.game_jp = get_or(values, "game_jp", config.game_jp.string());
    config.game_en = get_or(values, "game_en", config.game_en.string());
    config.config_dir = get_or(values, "config_dir", "");
    config.fullscreen = parse_bool(get_or(values, "fullscreen", "0"), false, error, "fullscreen");
    config.integer_scaling = parse_bool(get_or(values, "integer_scaling", "1"), true, error, "integer_scaling");
    config.skip_launcher = parse_bool(get_or(values, "skip_launcher", "0"), false, error, "skip_launcher");

    const auto volume = get_or(values, "audio_volume", "100");
    try {
        config.audio_volume = std::stoi(volume);
    } catch (...) {
        set_error(error, "invalid audio_volume: " + volume);
    }
    config.audio_volume = std::clamp(config.audio_volume, 0, 100);

    const auto api = get_or(values, "graphics_api", config.graphics_api);
    if (api == "Auto" || api == "auto" || api == "D3D12" || api == "d3d12" ||
        api == "Vulkan" || api == "vulkan" || api == "Metal" || api == "metal") {
        config.graphics_api = api;
    } else {
        set_error(error, "invalid graphics_api: " + api);
    }
    return config;
}

bool save_config(const std::filesystem::path& path, const Config& config, std::string* error) {
    const auto parent = path.parent_path();
    if (!parent.empty()) {
        std::error_code ec;
        std::filesystem::create_directories(parent, ec);
        if (ec) {
            set_error(error, "cannot create " + parent.string() + ": " + ec.message());
            return false;
        }
    }
    std::ofstream file(path, std::ios::trunc);
    if (!file) {
        set_error(error, "cannot write " + path.string());
        return false;
    }
    file << "# WPJ2 launcher configuration\n"
         << "variant=" << variant_name(config.variant) << "\n"
         << "jp_rom=" << config.jp_rom.string() << "\n"
         << "en_rom=" << config.en_rom.string() << "\n"
         << "ips_patch=" << config.ips_patch.string() << "\n"
         << "game_jp=" << config.game_jp.string() << "\n"
         << "game_en=" << config.game_en.string() << "\n"
         << "config_dir=" << config.config_dir.string() << "\n"
         << "fullscreen=" << (config.fullscreen ? 1 : 0) << "\n"
         << "integer_scaling=" << (config.integer_scaling ? 1 : 0) << "\n"
         << "audio_volume=" << config.audio_volume << "\n"
         << "graphics_api=" << config.graphics_api << "\n"
         << "skip_launcher=" << (config.skip_launcher ? 1 : 0) << "\n";
    return bool(file);
}

CicHash cic_hash(const std::filesystem::path& rom, std::string* error) {
    CicHash result{};
    std::vector<uint8_t> data;
    if (!read_file(rom, data, error)) {
        return result;
    }
    if (data.size() < CIC_START + CIC_LENGTH) {
        set_error(error, "ROM is too small for CIC checksum: " + rom.string());
        return result;
    }

    uint32_t a = 0xF8CA4DDCu, b = a, c = a, d = a, e = a, f = a;
    const uint8_t* p = data.data() + CIC_START;
    for (uint32_t i = 0; i < CIC_LENGTH; i += 4) {
        const uint32_t x = be32(p + i);
        const uint32_t old_f = f;
        f = (f + x) & CIC_MASK;
        d = (d + (f < old_f ? 1u : 0u)) & CIC_MASK;
        c ^= x;
        const uint32_t shift = x % 32;
        const uint32_t rot = shift == 0 ? x : ((x << shift) | (x >> (32 - shift)));
        const uint32_t old_b = b;
        b ^= (old_b > x) ? rot : (f ^ x);
        e = (e + rot) & CIC_MASK;
        a = (a + (e ^ x)) & CIC_MASK;
    }
    result.first = (f ^ d ^ c) & CIC_MASK;
    result.second = (e ^ b ^ a) & CIC_MASK;
    return result;
}

bool verify_jp_rom(const std::filesystem::path& rom, std::string* error) {
    std::error_code ec;
    if (!std::filesystem::exists(rom, ec) || std::filesystem::file_size(rom, ec) != JP_ROM_SIZE) {
        set_error(error, "Japanese ROM missing or wrong size: " + rom.string());
        return false;
    }
    const auto hash = cic_hash(rom, error);
    if (error != nullptr && !error->empty()) return false;
    if (hash.first != EXPECTED_JP_CIC.first || hash.second != EXPECTED_JP_CIC.second) {
        set_error(error, "Japanese ROM CIC mismatch: " + hex32(hash.first) + " " + hex32(hash.second));
        return false;
    }
    return true;
}

bool verify_en_rom(const std::filesystem::path& rom, std::string* error) {
    std::error_code ec;
    if (!std::filesystem::exists(rom, ec) || std::filesystem::file_size(rom, ec) != EN_ROM_SIZE) {
        set_error(error, "English ROM missing or wrong size: " + rom.string());
        return false;
    }
    const auto hash = cic_hash(rom, error);
    if (error != nullptr && !error->empty()) return false;
    if (hash.first != EXPECTED_EN_CIC.first || hash.second != EXPECTED_EN_CIC.second) {
        set_error(error, "English ROM CIC mismatch: " + hex32(hash.first) + " " + hex32(hash.second));
        return false;
    }
    return true;
}

bool discover_roms(Config& config) {
    std::vector<std::filesystem::path> directories;
    if (const char* override = std::getenv("WPJ2_LAUNCH_DIR")) {
        if (*override != '\0') directories.emplace_back(override);
    }
    const auto exe_dir = current_exe_dir();
    if (!exe_dir.empty()) {
        directories.push_back(exe_dir);
        directories.push_back(exe_dir.parent_path());
    }
    directories.emplace_back(".");

    const auto candidates = {
        "wpj2.j1.z64",
        "Wonder Project J2 - Koruro no Mori no Josette (Japan).z64",
        "Wonder Project J2 - Koruro no Mori no Jozet (Japan).z64",
        "wpj2.en.z64",
        "english.z64",
    };

    bool found = false;
    if (verify_jp_rom(config.jp_rom, nullptr)) found = true;
    if (verify_en_rom(config.en_rom, nullptr)) found = true;

    for (const auto& dir : directories) {
        std::error_code ec;
        if (!std::filesystem::is_directory(dir, ec)) continue;

        for (const char* name : candidates) {
            const auto path = dir / name;
            if (!verify_jp_rom(config.jp_rom, nullptr) && verify_jp_rom(path, nullptr)) {
                config.jp_rom = path;
                found = true;
            }
            if (!verify_en_rom(config.en_rom, nullptr) && verify_en_rom(path, nullptr)) {
                config.en_rom = path;
                found = true;
            }
        }

        for (const auto& entry : std::filesystem::directory_iterator(dir, ec)) {
            if (ec) break;
            if (!entry.is_regular_file(ec)) continue;
            const auto ext = entry.path().extension().string();
            if (ext != ".z64" && ext != ".n64" && ext != ".v64") continue;
            if (!verify_jp_rom(config.jp_rom, nullptr) && verify_jp_rom(entry.path(), nullptr)) {
                config.jp_rom = entry.path();
                found = true;
            }
            if (!verify_en_rom(config.en_rom, nullptr) && verify_en_rom(entry.path(), nullptr)) {
                config.en_rom = entry.path();
                found = true;
            }
        }
    }
    // If only a Japanese ROM was found, pre-fill the expected English ROM path
    // in the same folder, but never replace an explicitly supplied path.
    if (found && !verify_jp_rom(config.jp_rom, nullptr) &&
        !verify_en_rom(config.en_rom, nullptr)) {
        config.en_rom = config.jp_rom.parent_path() / "wpj2.en.z64";
    }
    return found;
}

bool discover_patch(Config& config) {
    std::error_code existing_ec;
    if (std::filesystem::is_regular_file(config.ips_patch, existing_ec)) {
        return true;
    }

    std::vector<std::filesystem::path> directories;
    if (const char* override = std::getenv("WPJ2_PATCH_DIR")) {
        if (*override != '\0') directories.emplace_back(override);
    }
    const auto exe_dir = current_exe_dir();
    if (!exe_dir.empty()) {
        directories.push_back(exe_dir);
        directories.push_back(exe_dir.parent_path());
    }
    directories.emplace_back(".");

    for (const auto& dir : directories) {
        const auto candidates = {
            dir / "Wpj2e_v1_z64.ips",
            dir / "patches" / "Wpj2e_v1_z64.ips",
            dir / "share" / "wpj2-recomp" / "patches" / "Wpj2e_v1_z64.ips",
        };
        for (const auto& path : candidates) {
            std::error_code ec;
            if (std::filesystem::is_regular_file(path, ec)) {
                config.ips_patch = path;
                return true;
            }
        }
    }
    return false;
}

bool apply_ips(const std::filesystem::path& jp_rom,
               const std::filesystem::path& ips,
               const std::filesystem::path& output,
               std::string* error) {
    std::vector<uint8_t> patch_data;
    if (!read_file(ips, patch_data, error)) return false;
    if (patch_data.size() < 8 ||
        patch_data[0] != 'P' || patch_data[1] != 'A' || patch_data[2] != 'T' ||
        patch_data[3] != 'C' || patch_data[4] != 'H') {
        set_error(error, "not an IPS patch: " + ips.string());
        return false;
    }

    std::vector<uint8_t> rom;
    if (!read_file(jp_rom, rom, error)) return false;
    if (!verify_jp_rom(jp_rom, error)) return false;

    size_t pos = 5;
    uint64_t max_end = 0;
    struct Record { uint64_t offset; std::vector<uint8_t> data; };
    std::vector<Record> records;
    while (pos < patch_data.size()) {
        if (pos + 3 <= patch_data.size() &&
            patch_data[pos] == 'E' && patch_data[pos + 1] == 'O' && patch_data[pos + 2] == 'F') {
            pos += 3;
            break;
        }
        if (pos + 5 > patch_data.size()) {
            set_error(error, "truncated IPS record");
            return false;
        }
        const uint64_t offset = (uint64_t(patch_data[pos]) << 16) |
                                (uint64_t(patch_data[pos + 1]) << 8) |
                                uint64_t(patch_data[pos + 2]);
        pos += 3;
        const uint64_t size = (uint64_t(patch_data[pos]) << 8) | uint64_t(patch_data[pos + 1]);
        pos += 2;
        Record record;
        record.offset = offset;
        if (size == 0) {
            if (pos + 3 > patch_data.size()) {
                set_error(error, "truncated IPS RLE record");
                return false;
            }
            // IPS RLE: two-byte big-endian COUNT, then one VALUE byte.
            const uint64_t count = (uint64_t(patch_data[pos]) << 8) | uint64_t(patch_data[pos + 1]);
            const uint8_t value = patch_data[pos + 2];
            pos += 3;
            if (count == 0) {
                set_error(error, "zero-length IPS RLE record");
                return false;
            }
            record.data.assign(static_cast<size_t>(count), value);
        } else {
            if (pos + size > patch_data.size()) {
                set_error(error, "truncated IPS record");
                return false;
            }
            record.data.assign(patch_data.begin() + pos, patch_data.begin() + pos + size);
            pos += static_cast<size_t>(size);
        }
        max_end = std::max(max_end, record.offset + record.data.size());
        records.push_back(std::move(record));
    }
    if (max_end != EN_ROM_SIZE) {
        set_error(error, "IPS output size " + std::to_string(max_end) +
                         " does not match canonical English ROM");
        return false;
    }

    if (rom.size() < max_end) {
        rom.resize(static_cast<size_t>(max_end), 0);
    }
    for (const auto& record : records) {
        std::copy(record.data.begin(), record.data.end(),
                  rom.begin() + static_cast<std::ptrdiff_t>(record.offset));
    }
    if (!write_file_atomic(output, rom, error)) return false;
    if (!verify_en_rom(output, error)) return false;
    return true;
}

bool ensure_en_rom(const Config& config, bool generate_missing, std::string* error) {
    if (verify_en_rom(config.en_rom, nullptr)) {
        return true;
    }
    if (!generate_missing) {
        set_error(error, "English ROM is invalid; use --make-en or the Generate button");
        return false;
    }
    const auto parent = config.en_rom.parent_path();
    if (!parent.empty()) {
        std::error_code ec;
        std::filesystem::create_directories(parent, ec);
        if (ec) {
            set_error(error, "cannot create " + parent.string() + ": " + ec.message());
            return false;
        }
    }
    return apply_ips(config.jp_rom, config.ips_patch, config.en_rom, error);
}

LaunchPlan make_plan(const Config& config, bool generate_en, std::string* error) {
    LaunchPlan plan;
    plan.variant = config.variant;

    std::filesystem::path rom;
    std::filesystem::path executable;
    if (config.variant == Variant::Jp) {
        if (!verify_jp_rom(config.jp_rom, error)) return plan;
        rom = std::filesystem::absolute(config.jp_rom);
        executable = config.game_jp;
    } else {
        if (!ensure_en_rom(config, generate_en, error)) return plan;
        rom = std::filesystem::absolute(config.en_rom);
        executable = config.game_en;
    }

    plan.executable = resolve_executable(executable, config.variant);
    std::error_code ec;
    if (!std::filesystem::exists(plan.executable, ec)) {
        set_error(error, "game executable not found: " + plan.executable.string());
        return plan;
    }
    plan.argv.push_back(plan.executable.string());

    auto base_config = config.config_dir;
    if (base_config.empty()) {
        const auto home = home_dir();
        if (home.empty()) {
            set_error(error, "set config_dir or HOME");
            return plan;
        }
        base_config = home / ".config" / "wpj2-recomp" / "launcher";
    }
    const auto game_config = base_config / variant_name(config.variant);

    plan.environment.emplace_back("WPJ2_LAUNCHER", "1");
    plan.environment.emplace_back("WPJ2_VARIANT", variant_name(config.variant));
    plan.environment.emplace_back("WPJ2_ROM", rom.string());
    plan.environment.emplace_back("WPJ2_CONFIG_DIR", game_config.string());
    plan.environment.emplace_back("WPJ2_FULLSCREEN", config.fullscreen ? "1" : "0");
    plan.environment.emplace_back("WPJ2_INTEGER_SCALING", config.integer_scaling ? "1" : "0");
    plan.environment.emplace_back("WPJ2_AUDIO_VOLUME", std::to_string(config.audio_volume));
    plan.environment.emplace_back("WPJ2_GRAPHICS_API", config.graphics_api);
    return plan;
}

std::string describe_plan(const LaunchPlan& plan) {
    std::ostringstream out;
    out << "variant=" << variant_name(plan.variant) << "\n";
    for (const auto& [key, value] : plan.environment) {
        out << key << "=" << value << "\n";
    }
    out << "exec=" << plan.executable.string() << "\n";
    return out.str();
}

int launch(const LaunchPlan& plan, std::string* error) {
#if defined(_WIN32)
    std::string command_line;
    for (const auto& arg : plan.argv) {
        if (!command_line.empty()) command_line.push_back(' ');
        quote_windows_arg(arg, command_line);
    }
    std::string environment_block;
    for (const auto& [key, value] : plan.environment) {
        environment_block += key + "=" + value + '\0';
    }
    environment_block.push_back('\0');

    STARTUPINFOA startup_info{};
    PROCESS_INFORMATION process_info{};
    startup_info.cb = sizeof(startup_info);
    std::vector<char> mutable_command(command_line.begin(), command_line.end());
    mutable_command.push_back('\0');

    BOOL ok = CreateProcessA(nullptr, mutable_command.data(), nullptr, nullptr, FALSE, 0,
                             environment_block.data(), nullptr, &startup_info, &process_info);
    if (!ok) {
        set_error(error, "CreateProcessA failed");
        return 1;
    }
    CloseHandle(process_info.hThread);
    WaitForSingleObject(process_info.hProcess, INFINITE);
    DWORD code = 0;
    GetExitCodeProcess(process_info.hProcess, &code);
    CloseHandle(process_info.hProcess);
    return static_cast<int>(code);
#else
    for (const auto& [key, value] : plan.environment) {
        setenv(key.c_str(), value.c_str(), 1);
    }
    std::vector<char*> args;
    args.reserve(plan.argv.size());
    for (const auto& arg : plan.argv) {
        args.push_back(const_cast<char*>(arg.c_str()));
    }
    args.push_back(nullptr);
    execvp(args[0], args.data());
    set_error(error, std::string("execvp failed: ") + std::strerror(errno));
    return 1;
#endif
}

} // namespace wpj2_launcher
