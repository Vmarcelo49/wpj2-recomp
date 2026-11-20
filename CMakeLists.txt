# WPJ2 Recompilation - Native Library Build
# Phase 2: Build libwpj2_recompiled.a from N64Recomp output
#
# === Build performance knobs ===
#   cmake -B build -DWPJ2_DEV=ON          # -Og, no LTO, fastest iteration
#   cmake -B build -DWPJ2_UNITY=ON        # unity-build the 50 funcs_*.c
#   cmake -B build -DWPJ2_PCH=ON          # precompile recomp.h+shims.h (default ON)
#   cmake -B build -DWPJ2_LINKER=mold     # default; falls back to ld if missing
#
# Both ccache and mold are auto-detected if installed.

cmake_minimum_required(VERSION 3.24)
project(wpj2_recomp LANGUAGES C CXX)

if(WIN32)
    enable_language(RC)
    set(WPJ2_ICON_RC "${CMAKE_CURRENT_BINARY_DIR}/wpj2-icon.rc")
    file(TO_CMAKE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/resources/wpj2.ico" WPJ2_ICON_PATH)
    string(REPLACE "\\" "\\\\" WPJ2_ICON_PATH "${WPJ2_ICON_PATH}")
    file(WRITE "${WPJ2_ICON_RC}" "1 ICON \"${WPJ2_ICON_PATH}\"\n")
endif()

# Prefer Ninja for local builds, but allow the generator to be selected by
# the caller (Windows CI uses Ninja explicitly).
if(NOT CMAKE_GENERATOR)
    set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "")
endif()

# C++20 / C17 standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ----------------------------------------------------------------------------
# Build type & dev mode
# ----------------------------------------------------------------------------
option(WPJ2_DEV "Developer build: -Og, no LTO, faster iteration" OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(WPJ2_DEV)
    # Override to a fast-iterating RelWithDebInfo-like profile
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "" FORCE)
    # Disable LTO even if added later
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF CACHE BOOL "" FORCE)
endif()

if(NOT WIN32)
    # ----------------------------------------------------------------------------
    # ccache integration (auto-detect, non-MSVC)
    # ----------------------------------------------------------------------------
    find_program(CCACHE_PROGRAM ccache)
    if(CCACHE_PROGRAM)
        set(CMAKE_C_COMPILER_LAUNCHER   ${CCACHE_PROGRAM})
        set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
        message(STATUS "ccache: ${CCACHE_PROGRAM}")
        # Default cache size: 2 GiB
        set(CCACHE_CACHE_DIR "$ENV{HOME}/.ccache" CACHE STRING "ccache directory")
        execute_process(COMMAND ${CCACHE_PROGRAM} -M 2G OUTPUT_QUIET ERROR_QUIET)
    else()
        message(STATUS "ccache: not found (install with: sudo apt install ccache)")
    endif()

    # ----------------------------------------------------------------------------
    # Linker selection (mold >> gold >> bfd)
    # ----------------------------------------------------------------------------
    set(WPJ2_LINKER "mold" CACHE STRING "Linker to use (mold/ld/gold/lld)")
    find_program(MOLD_PROGRAM mold)
    find_program(LD_PROGRAM   ld)
    find_program(LLD_PROGRAM  lld)
    find_program(GOLD_PROGRAM gold)

    function(pick_linker out)
        foreach(candidate ${WPJ2_LINKER} mold lld gold ld)
            if(candidate STREQUAL "mold" AND MOLD_PROGRAM)
                set(${out} ${MOLD_PROGRAM} PARENT_SCOPE)
                return()
            elseif(candidate STREQUAL "lld"  AND LLD_PROGRAM)
                set(${out} ${LLD_PROGRAM}  PARENT_SCOPE)
                return()
            elseif(candidate STREQUAL "gold" AND GOLD_PROGRAM)
                set(${out} ${GOLD_PROGRAM} PARENT_SCOPE)
                return()
            elseif(candidate STREQUAL "ld"   AND LD_PROGRAM)
                set(${out} ${LD_PROGRAM}   PARENT_SCOPE)
                return()
            endif()
        endforeach()
    endfunction()

    pick_linker(WPJ2_SELECTED_LINKER)
    if(WPJ2_SELECTED_LINKER)
        set(CMAKE_LINKER ${WPJ2_SELECTED_LINKER})
        set(CMAKE_C_LINKER   ${WPJ2_SELECTED_LINKER})
        set(CMAKE_CXX_LINKER ${WPJ2_SELECTED_LINKER})
        # Add -fuse-ld= flag for the chosen linker
        if(WPJ2_SELECTED_LINKER STREQUAL MOLD_PROGRAM)
            set(LINKER_FLAG "-fuse-ld=mold")
        elseif(WPJ2_SELECTED_LINKER STREQUAL LLD_PROGRAM)
            set(LINKER_FLAG "-fuse-ld=lld")
        elseif(WPJ2_SELECTED_LINKER STREQUAL GOLD_PROGRAM)
            set(LINKER_FLAG "-fuse-ld=gold")
        else()
            set(LINKER_FLAG "")
        endif()
        if(LINKER_FLAG)
            set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_FLAG}")
            set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${LINKER_FLAG}")
        endif()
        message(STATUS "linker: ${WPJ2_SELECTED_LINKER}")
    endif()

endif()

# ----------------------------------------------------------------------------
# Ninja parallelism: explicit -j to avoid runaway with ccache misses
# ----------------------------------------------------------------------------
if(CMAKE_GENERATOR STREQUAL "Ninja")
    include(ProcessorCount)
    ProcessorCount(N)
    if(N GREATER 0)
        # Leave 1 core free for system responsiveness
        math(EXPR WPJ2_JOBS "${N} - 1")
        set(CMAKE_JOB_POOLS "wpj2_pool=${WPJ2_JOBS}")
        set_property(GLOBAL APPEND PROPERTY JOB_POOLS "wpj2_pool=${WPJ2_JOBS}")
        message(STATUS "ninja jobs: ${WPJ2_JOBS} (of ${N} cores)")
    endif()
endif()

# ----------------------------------------------------------------------------
# CRITICAL: Hidden visibility on recompiled target
# Prevents game's 'send' symbol from colliding with libc send(2)
# ----------------------------------------------------------------------------
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

# CRITICAL: MIPS recompiled code breaks strict aliasing on GCC/Clang.
# MSVC does not accept GCC-style flags.
if(NOT MSVC)
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -fno-strict-aliasing")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing")
endif()

# Position independent code for shared library compatibility
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Always export compile_commands.json for clangd/IDE
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ----------------------------------------------------------------------------
# Include directories - MUST include N64Recomp's recomp.h location
# ----------------------------------------------------------------------------
set(WPJ2_GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/game/generated" CACHE PATH
    "N64Recomp CPU output for this ROM variant")
if(NOT EXISTS "${WPJ2_GENERATED_DIR}/recomp_overlays.inl" OR NOT EXISTS "${WPJ2_GENERATED_DIR}/lookup.cpp")
    message(FATAL_ERROR "Incomplete N64Recomp output: ${WPJ2_GENERATED_DIR}")
endif()
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/generated
    "${WPJ2_GENERATED_DIR}"
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/N64ModernRuntime/ultramodern/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/N64ModernRuntime/N64Recomp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/N64ModernRuntime/librecomp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src
)

# Subdirectories for dependencies
# RT64_SDL_WINDOW_VULKAN must be ON so RenderWindow = SDL_Window* on Linux
# (instead of X11 {Display*, Window} struct). This lets us pass our SDL_Window
# directly to RT64::Application::Core.window.
# RT64_STATIC must be ON so we can link RT64 symbols directly into wpj2
# (the default SHARED build hides visibility and we can't access Application).
# Keep the tracked runtime fix applied on fresh checkouts. The patch is not
# part of the upstream submodule, so configure applies it once when absent.
set(WPJ2_RUNTIME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/N64ModernRuntime")
set(WPJ2_RUNTIME_PATCH "${CMAKE_CURRENT_SOURCE_DIR}/patches/N64ModernRuntime/vi-null-mode.patch")
set(WPJ2_RUNTIME_EVENTS "${WPJ2_RUNTIME_DIR}/ultramodern/src/events.cpp")
if(NOT EXISTS "${WPJ2_RUNTIME_EVENTS}")
    message(FATAL_ERROR "N64ModernRuntime submodule is missing; run git submodule update --init --recursive")
endif()

file(READ "${WPJ2_RUNTIME_EVENTS}" wpj2_runtime_events_source)
string(FIND "${wpj2_runtime_events_source}" "ensure_next_mode" wpj2_patch_marker)
if(NOT wpj2_patch_marker EQUAL -1)
    message(STATUS "N64ModernRuntime VI patch already present")
elseif(EXISTS "${WPJ2_RUNTIME_PATCH}")
    if(EXISTS "${WPJ2_RUNTIME_DIR}/.git")
        execute_process(
            COMMAND git -C "${WPJ2_RUNTIME_DIR}" apply --check "${WPJ2_RUNTIME_PATCH}"
            RESULT_VARIABLE patch_can_apply
            OUTPUT_QUIET ERROR_QUIET)
        if(patch_can_apply EQUAL 0)
            execute_process(
                COMMAND git -C "${WPJ2_RUNTIME_DIR}" apply "${WPJ2_RUNTIME_PATCH}"
                RESULT_VARIABLE patch_result)
            if(NOT patch_result EQUAL 0)
                message(FATAL_ERROR "Applying ${WPJ2_RUNTIME_PATCH} failed")
            endif()
            message(STATUS "Applied N64ModernRuntime patch: vi-null-mode.patch")
        else()
            message(FATAL_ERROR "N64ModernRuntime has unexpected local changes; cannot apply vi-null-mode.patch")
        endif()
    else()
        find_program(PATCH_PROGRAM patch)
        if(PATCH_PROGRAM)
            execute_process(
                COMMAND "${PATCH_PROGRAM}" -p1 -i "${WPJ2_RUNTIME_PATCH}"
                WORKING_DIRECTORY "${WPJ2_RUNTIME_DIR}"
                RESULT_VARIABLE patch_result)
            if(NOT patch_result EQUAL 0)
                message(FATAL_ERROR "Applying ${WPJ2_RUNTIME_PATCH} with patch failed")
            endif()
            message(STATUS "Applied N64ModernRuntime patch: vi-null-mode.patch")
        else()
            message(FATAL_ERROR "Cannot apply ${WPJ2_RUNTIME_PATCH}: install patch or use a git checkout")
        endif()
    endif()
else()
    message(WARNING "Missing ${WPJ2_RUNTIME_PATCH}; VI startup may crash")
endif()

# Expose a ControllerPak device type to projects that need it.
set(WPJ2_RUNTIME_PAK_PATCH "${CMAKE_CURRENT_SOURCE_DIR}/patches/N64ModernRuntime/controller-pak-device.patch")
set(WPJ2_RUNTIME_INPUT_HEADER "${WPJ2_RUNTIME_DIR}/ultramodern/include/ultramodern/input.hpp")
file(READ "${WPJ2_RUNTIME_INPUT_HEADER}" wpj2_runtime_input_header)
string(FIND "${wpj2_runtime_input_header}" "ControllerPak," wpj2_pak_patch_marker)
if(wpj2_pak_patch_marker EQUAL -1)
    execute_process(
        COMMAND git -C "${WPJ2_RUNTIME_DIR}" apply --check "${WPJ2_RUNTIME_PAK_PATCH}"
        RESULT_VARIABLE pak_patch_can_apply
        OUTPUT_QUIET ERROR_QUIET)
    if(pak_patch_can_apply EQUAL 0)
        execute_process(
            COMMAND git -C "${WPJ2_RUNTIME_DIR}" apply "${WPJ2_RUNTIME_PAK_PATCH}"
            RESULT_VARIABLE pak_patch_result)
        if(NOT pak_patch_result EQUAL 0)
            message(FATAL_ERROR "Applying ${WPJ2_RUNTIME_PAK_PATCH} failed")
        endif()
        message(STATUS "Applied N64ModernRuntime patch: controller-pak-device.patch")
    else()
        message(FATAL_ERROR "Cannot apply ${WPJ2_RUNTIME_PAK_PATCH}; unexpected runtime changes")
    endif()
else()
    message(STATUS "N64ModernRuntime ControllerPak patch already present")
endif()

set(RT64_SDL_WINDOW_VULKAN ON CACHE BOOL "" FORCE)
set(RT64_STATIC ON CACHE BOOL "" FORCE)
# RT64 vendors zstd for static linking; its CLI tools are not release artifacts.
set(ZSTD_BUILD_PROGRAMS OFF CACHE BOOL "" FORCE)
set(ZSTD_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/N64ModernRuntime)
add_subdirectory(lib/RT64)

# ----------------------------------------------------------------------------
# Sources
# ----------------------------------------------------------------------------
file(GLOB GAME_GENERATED_SOURCES CONFIGURE_DEPENDS
    "${WPJ2_GENERATED_DIR}/funcs_*.c"
    "${WPJ2_GENERATED_DIR}/lookup.cpp"
)

# Do not recursively pull the Japanese generated functions into an English build.
set(SHIM_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/audio_input/controller_pak.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/manual_stubs.cpp"
)

# RSP recompiled code is C++ (uses C++ syntax like RSP rsp{} and includes .hpp)
file(GLOB_RECURSE RSP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/rsp/generated/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/rsp/generated/*.cpp"
)

# N64Recomp's RSP output requires x86 SIMD intrinsics. Other architectures
# still need a portable fallback target, even though no fallback exists yet.
if(NOT MSVC AND CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|AMD64|amd64|i.86)$")
    set(WPJ2_RSP_SIMD_FLAGS -mssse3 -msse4.1)
else()
    set(WPJ2_RSP_SIMD_FLAGS)
    message(WARNING "No portable RSP backend for ${CMAKE_SYSTEM_PROCESSOR}; audio may not work")
endif()

# ----------------------------------------------------------------------------
# Unity build option (joins all funcs_*.c into one TU for fewer compiler startups)
# ----------------------------------------------------------------------------
option(WPJ2_UNITY "Unity-build the 50 funcs_*.c files (faster, but may hit duplicate static symbols)" OFF)
if(WPJ2_UNITY)
    # Generate a single unity .c that #includes all funcs_*.c
    set(WPJ2_UNITY_FILE "${CMAKE_BINARY_DIR}/wpj2_unity_funcs.c")
    file(WRITE ${WPJ2_UNITY_FILE} "/* Auto-generated unity build */\n")
    foreach(src ${GAME_GENERATED_SOURCES})
        file(APPEND ${WPJ2_UNITY_FILE} "#include \"${src}\"\n")
    endforeach()
    set(GAME_GENERATED_SOURCES ${WPJ2_UNITY_FILE})
    message(STATUS "unity build: ON (${WPJ2_UNITY_FILE})")
endif()

# ----------------------------------------------------------------------------
# RSP object library (C++ with SSE flags)
# ----------------------------------------------------------------------------
add_library(wpj2_rsp OBJECT ${RSP_SOURCES})
target_compile_options(wpj2_rsp PRIVATE ${WPJ2_RSP_SIMD_FLAGS})
set_source_files_properties(${RSP_SOURCES} PROPERTIES LANGUAGE CXX)

# ----------------------------------------------------------------------------
# Main recompiled library target
# ----------------------------------------------------------------------------
add_library(wpj2_recompiled STATIC
    ${GAME_GENERATED_SOURCES}
    ${SHIM_SOURCES}
)

target_link_libraries(wpj2_recompiled PRIVATE wpj2_rsp)

set_target_properties(wpj2_recompiled PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    C_VISIBILITY_PRESET hidden
    POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(wpj2_recompiled PRIVATE
    ultramodern
    rt64
)

target_compile_options(wpj2_recompiled PRIVATE ${WPJ2_RSP_SIMD_FLAGS})
if(NOT MSVC)
    target_compile_options(wpj2_recompiled PRIVATE
        -fno-strict-aliasing
        -fvisibility=hidden
        -Wno-unused-parameter
        -Wno-missing-field-initializers
        -Wno-sign-compare
    )
endif()

# Precompiled header for the 50 generated .c files — they all include the
# same two headers, so a PCH saves parsing ~30k lines of system+lib headers
# 50 times over.
option(WPJ2_PCH "Precompile recomp.h+shims.h for generated funcs" ON)
if(WPJ2_PCH)
    target_precompile_headers(wpj2_recompiled PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/generated/wpj2_pch.h
    )
    message(STATUS "PCH: ON (include/generated/wpj2_pch.h)")
endif()

set_target_properties(wpj2_recompiled PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS wpj2_recompiled
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# ----------------------------------------------------------------------------
# Main executable target
# ----------------------------------------------------------------------------
if(WIN32)
    # RT64 vendors the MSVC SDL2 import library and headers. Use the same SDL2
    # for the executable instead of mixing in a vcpkg host/imported target.
    set(WPJ2_SDL2_INCLUDE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src/contrib/mupen64plus-win32-deps/SDL2-2.26.3/include")
    set(WPJ2_SDL2_LIBRARIES SDL2 SDL2main)
    link_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src/contrib/mupen64plus-win32-deps/SDL2-2.26.3/lib/x64")
else()
    find_package(SDL2 REQUIRED)
    set(WPJ2_SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS})
    set(WPJ2_SDL2_LIBRARIES SDL2::SDL2)
endif()

add_executable(wpj2
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/rt64_renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/audio_input/audio.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/audio_input/input.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/rsp/rsp_dispatch.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/game/register_overlays.cpp
    ${WPJ2_ICON_RC}
)

option(WPJ2_ENGLISH_BUILD "Use the English ROM with its matching generated CPU code" OFF)
if(WPJ2_ENGLISH_BUILD)
    file(REAL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/game/generated" jp_generated_real)
    file(REAL_PATH "${WPJ2_GENERATED_DIR}" en_generated_real)
    if(en_generated_real STREQUAL jp_generated_real)
        message(FATAL_ERROR "Select matching English CPU output with -DWPJ2_GENERATED_DIR=<path>")
    endif()
    target_compile_definitions(wpj2 PRIVATE WPJ2_ENGLISH_BUILD=1)
endif()

target_link_libraries(wpj2 PRIVATE
    wpj2_recompiled
    librecomp
    ultramodern
    rt64
    ${WPJ2_SDL2_LIBRARIES}
)

# Include dirs for WPJ2 integration modules (rt64_renderer.hpp, audio.hpp, ...)
target_include_directories(wpj2 PRIVATE
    ${WPJ2_SDL2_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/src/audio_input
    ${CMAKE_CURRENT_SOURCE_DIR}/src/rsp
    "${WPJ2_GENERATED_DIR}"
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src/hle
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src/contrib/plume
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src/contrib/hlslpp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src/contrib/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src/contrib
)

if(MSVC)
    target_compile_options(wpj2 PRIVATE /W3 /permissive-)
else()
    target_compile_options(wpj2 PRIVATE
        -fno-strict-aliasing
        -Wno-unused-parameter
        -Wno-missing-field-initializers
        -Wno-sign-compare
        -fpermissive
    )
endif()

# RT64 headers require these definitions to compile correctly outside
# of the RT64 CMake directory scope.
target_compile_definitions(wpj2 PRIVATE
    HLSL_CPU
    FFX_GCC
    IMGUI_IMPL_VULKAN_NO_PROTOTYPES
    PLUME_SDL_VULKAN_ENABLED
    RT64_SDL_WINDOW_VULKAN
)

# Reuse the PCH from wpj2_recompiled so main.cpp also benefits
if(WPJ2_PCH)
    target_precompile_headers(wpj2 REUSE_FROM wpj2_recompiled)
endif()

if(WPJ2_ENGLISH_BUILD)
    set(WPJ2_EXECUTABLE_NAME wpj2-en)
else()
    set(WPJ2_EXECUTABLE_NAME wpj2-jp)
endif()

set_target_properties(wpj2 PROPERTIES
    OUTPUT_NAME ${WPJ2_EXECUTABLE_NAME}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS wpj2
    RUNTIME DESTINATION bin
)
install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE"
    "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
    "${CMAKE_CURRENT_SOURCE_DIR}/VERSION"
    "${CMAKE_CURRENT_SOURCE_DIR}/resources/fonts/Roboto-OFL.txt"
    DESTINATION share/wpj2-recomp)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/docs/"
    DESTINATION share/wpj2-recomp/docs)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/patches/Wpj2e_v1_z64.ips"
    DESTINATION share/wpj2-recomp/patches)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/resources/wpj2.desktop")
    install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/resources/wpj2.desktop"
        DESTINATION share/applications)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/hicolor/128x128/apps/wpj2.png")
    install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/hicolor/128x128/apps/wpj2.png"
        DESTINATION share/icons/hicolor/128x128/apps)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/hicolor/256x256/apps/wpj2.png")
    install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/hicolor/256x256/apps/wpj2.png"
        DESTINATION share/icons/hicolor/256x256/apps)
endif()

# Startup launcher: selects JP/EN and passes settings to the matching binary.
option(WPJ2_BUILD_LAUNCHER "Build the startup language/settings launcher" ON)
if(WPJ2_BUILD_LAUNCHER)
    add_executable(wpj2-launcher
        "${CMAKE_CURRENT_SOURCE_DIR}/src/launcher/main.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/launcher/launcher_core.cpp"
        ${WPJ2_ICON_RC}
    )
    target_link_libraries(wpj2-launcher PRIVATE ${WPJ2_SDL2_LIBRARIES})
    target_include_directories(wpj2-launcher PRIVATE ${WPJ2_SDL2_INCLUDE_DIRS})
    set_target_properties(wpj2-launcher PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
    install(TARGETS wpj2-launcher RUNTIME DESTINATION bin)
endif()
