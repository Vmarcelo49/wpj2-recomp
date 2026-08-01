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

# Use Ninja for faster builds
set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "")

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

# ----------------------------------------------------------------------------
# ccache integration (auto-detect)
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

# CRITICAL: MIPS recompiled code breaks strict aliasing
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -fno-strict-aliasing")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing")

# Position independent code for shared library compatibility
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Always export compile_commands.json for clangd/IDE
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ----------------------------------------------------------------------------
# Include directories - MUST include N64Recomp's recomp.h location
# ----------------------------------------------------------------------------
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/generated
    ${CMAKE_CURRENT_SOURCE_DIR}/src/game/generated
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/N64ModernRuntime/ultramodern/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/N64ModernRuntime/N64Recomp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/N64ModernRuntime/librecomp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/RT64/src
)

# Subdirectories for dependencies
add_subdirectory(lib/N64ModernRuntime)
add_subdirectory(lib/RT64)

# ----------------------------------------------------------------------------
# Sources
# ----------------------------------------------------------------------------
file(GLOB_RECURSE GAME_GENERATED_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/generated/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/generated/*.cpp"
)

file(GLOB_RECURSE SHIM_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/audio_input/controller_pak.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/*.cpp"
)

# RSP recompiled code is C++ (uses C++ syntax like RSP rsp{} and includes .hpp)
file(GLOB_RECURSE RSP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/rsp/generated/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/rsp/generated/*.cpp"
)

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
target_compile_options(wpj2_rsp PRIVATE -mssse3 -msse4.1)
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

target_compile_options(wpj2_recompiled PRIVATE
    -mssse3
    -msse4.1
    -fno-strict-aliasing
    -fvisibility=hidden
    -Wno-unused-parameter
    -Wno-missing-field-initializers
    -Wno-sign-compare
)

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
find_package(SDL2 REQUIRED)

add_executable(wpj2
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/rt64_renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/audio_input/audio.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/audio_input/input.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/rsp/rsp_dispatch.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/game/register_overlays.cpp
)

target_link_libraries(wpj2 PRIVATE
    wpj2_recompiled
    librecomp
    ultramodern
    rt64
    SDL2::SDL2
)

# Include dirs for WPJ2 integration modules (rt64_renderer.hpp, audio.hpp, ...)
target_include_directories(wpj2 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/src/audio_input
    ${CMAKE_CURRENT_SOURCE_DIR}/src/rsp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/game/generated
)

target_compile_options(wpj2 PRIVATE
    -fno-strict-aliasing
    -Wno-unused-parameter
    -Wno-missing-field-initializers
    -Wno-sign-compare
)

# Reuse the PCH from wpj2_recompiled so main.cpp also benefits
if(WPJ2_PCH)
    target_precompile_headers(wpj2 REUSE_FROM wpj2_recompiled)
endif()

set_target_properties(wpj2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS wpj2
    RUNTIME DESTINATION bin
)
