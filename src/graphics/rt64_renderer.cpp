/*
 * WPJ2 Recomp - RT64 Renderer Context implementation
 *
 * Creates an RT64::Application and wires send_dl/update_screen to it.
 */

#include "rt64_renderer.hpp"

#include "ultramodern/renderer_context.hpp"
#include "ultramodern/ultra64.h"

// RT64 headers
#include "rt64_application.h"
#include "rt64_application_window.h"

// librecomp RSP (for dmem)
#include "librecomp/rsp.hpp"

#include <SDL2/SDL.h>

#include <cstdio>
#include <cstring>
#include <atomic>
#include <memory>

namespace wpj2 {

// ----------------------------------------------------------------------------
// Dummy hardware registers for RT64
// RT64 stores pointers to these in Core but only reads MI_INTR_REG (for
// interrupt signaling) and the VI_*_REG (for screen mode). DPC registers
// are stored but not read by RT64's own code — they exist for external
// plugin compatibility.
// ----------------------------------------------------------------------------
struct HardwareRegs {
    uint32_t MI_INTR_REG = 0;
    uint32_t DPC_START_REG = 0;
    uint32_t DPC_END_REG = 0;
    uint32_t DPC_CURRENT_REG = 0;
    uint32_t DPC_STATUS_REG = 0;
    uint32_t DPC_CLOCK_REG = 0;
    uint32_t DPC_BUFBUSY_REG = 0;
    uint32_t DPC_PIPEBUSY_REG = 0;
    uint32_t DPC_TMEM_REG = 0;
};

// Dummy IMEM (RSP is recompiled, not emulated; RT64 doesn't read IMEM)
static uint8_t g_dummy_imem[0x1000] = {};

// checkInterrupts callback — no-op because ultramodern handles SP/DP completion
// via message queues (sp_complete/dp_complete in events.cpp), not via MI_INTR_REG.
static void wpj2_check_interrupts() {
    // No-op: ultramodern's events.cpp already sends SP/DP completion messages
    // to the game's message queues after send_dl returns.
}

// ----------------------------------------------------------------------------
// Impl
// ----------------------------------------------------------------------------
struct RT64RendererContext::Impl {
    uint8_t* rdram = nullptr;
    SDL_Window* window = nullptr;
    bool developer_mode = false;

    HardwareRegs hw_regs;
    uint8_t header[0x40] = {};  // ROM header (0x40 bytes)

    std::unique_ptr<RT64::Application> app;
    RT64::Application::SetupResult setup_result = RT64::Application::SetupResult::Success;
    bool valid_ = false;
    bool initialized = false;

    std::atomic<uint64_t> dl_count{0};
    std::atomic<uint64_t> screen_count{0};
};

RT64RendererContext::RT64RendererContext(uint8_t* rdram,
                                         ultramodern::renderer::WindowHandle window_handle,
                                         bool developer_mode)
    : pimpl_(std::make_unique<Impl>())
{
    pimpl_->rdram = rdram;
    pimpl_->window = window_handle;  // On Linux, WindowHandle = SDL_Window*
    pimpl_->developer_mode = developer_mode;

    fprintf(stderr, "[WPJ2/RT64] Creating RT64 Application (rdram=%p, window=%p)\n",
            (void*)rdram, (void*)window_handle);

    // Build the RT64 Core struct
    RT64::Application::Core core{};

    // Window
    core.window = pimpl_->window;

    // Memory
    core.HEADER = pimpl_->header;
    core.RDRAM  = rdram;
    core.DMEM   = dmem;  // librecomp's global dmem[] array
    core.IMEM   = g_dummy_imem;

    // MI interrupt register
    core.MI_INTR_REG = &pimpl_->hw_regs.MI_INTR_REG;

    // DPC registers (dummy — RT64 stores but doesn't read them internally)
    core.DPC_START_REG    = &pimpl_->hw_regs.DPC_START_REG;
    core.DPC_END_REG      = &pimpl_->hw_regs.DPC_END_REG;
    core.DPC_CURRENT_REG  = &pimpl_->hw_regs.DPC_CURRENT_REG;
    core.DPC_STATUS_REG   = &pimpl_->hw_regs.DPC_STATUS_REG;
    core.DPC_CLOCK_REG    = &pimpl_->hw_regs.DPC_CLOCK_REG;
    core.DPC_BUFBUSY_REG  = &pimpl_->hw_regs.DPC_BUFBUSY_REG;
    core.DPC_PIPEBUSY_REG = &pimpl_->hw_regs.DPC_PIPEBUSY_REG;
    core.DPC_TMEM_REG     = &pimpl_->hw_regs.DPC_TMEM_REG;

    // VI registers — map to ultramodern's ViRegs struct
    ultramodern::renderer::ViRegs* vi_regs = ultramodern::renderer::get_vi_regs();
    if (vi_regs != nullptr) {
        core.VI_STATUS_REG        = &vi_regs->VI_STATUS_REG;
        core.VI_ORIGIN_REG        = &vi_regs->VI_ORIGIN_REG;
        core.VI_WIDTH_REG         = &vi_regs->VI_WIDTH_REG;
        core.VI_INTR_REG          = &vi_regs->VI_INTR_REG;
        core.VI_V_CURRENT_LINE_REG = &vi_regs->VI_V_CURRENT_LINE_REG;
        core.VI_TIMING_REG        = &vi_regs->VI_TIMING_REG;
        core.VI_V_SYNC_REG        = &vi_regs->VI_V_SYNC_REG;
        core.VI_H_SYNC_REG        = &vi_regs->VI_H_SYNC_REG;
        core.VI_LEAP_REG          = &vi_regs->VI_LEAP_REG;
        core.VI_H_START_REG       = &vi_regs->VI_H_START_REG;
        core.VI_V_START_REG       = &vi_regs->VI_V_START_REG;
        core.VI_V_BURST_REG       = &vi_regs->VI_V_BURST_REG;
        core.VI_X_SCALE_REG       = &vi_regs->VI_X_SCALE_REG;
        core.VI_Y_SCALE_REG       = &vi_regs->VI_Y_SCALE_REG;
    } else {
        fprintf(stderr, "[WPJ2/RT64] WARNING: get_vi_regs() returned null — VI won't work\n");
    }

    // Interrupt callback
    core.checkInterrupts = wpj2_check_interrupts;

    // Create the application
    RT64::ApplicationConfiguration app_config{};
    app_config.appId = "wpj2-recomp";
    app_config.detectDataPath = false;
    app_config.useConfigurationFile = false;

    pimpl_->app = std::make_unique<RT64::Application>(core, app_config);

    // Setup (creates Vulkan device, swapchain, etc.)
    uint32_t thread_id = 0;  // Current thread ID — RT64 uses this for profiling
    pimpl_->setup_result = pimpl_->app->setup(thread_id);

    if (pimpl_->setup_result == RT64::Application::SetupResult::Success) {
        // Tell RT64 that RDRAM is extended (8MB+). librecomp allocates
        // 512MB of RDRAM via mmap, so addresses above 0x7FFFFF are valid.
        // Without this, RT64 rejects texture uploads from extended RDRAM.
        pimpl_->app->state->setExtendedRDRAM(true);

        pimpl_->valid_ = true;
        pimpl_->initialized = true;
        fprintf(stderr, "[WPJ2/RT64] Application setup successful\n");
    } else {
        fprintf(stderr, "[WPJ2/RT64] Application setup FAILED (result=%d)\n",
                (int)pimpl_->setup_result);
        pimpl_->valid_ = false;
    }
}

RT64RendererContext::~RT64RendererContext() {
    fprintf(stderr, "[WPJ2/RT64] ~RendererContext (DLs=%lu, screens=%lu)\n",
            (unsigned long)pimpl_->dl_count.load(),
            (unsigned long)pimpl_->screen_count.load());
    // Application destructor handles cleanup
    pimpl_->app.reset();
}

bool RT64RendererContext::valid() {
    return pimpl_->valid_;
}

ultramodern::renderer::SetupResult RT64RendererContext::get_setup_result() const {
    switch (pimpl_->setup_result) {
        case RT64::Application::SetupResult::Success:
            return ultramodern::renderer::SetupResult::Success;
        case RT64::Application::SetupResult::DynamicLibrariesNotFound:
            return ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
        case RT64::Application::SetupResult::InvalidGraphicsAPI:
            return ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
        case RT64::Application::SetupResult::GraphicsAPINotFound:
            return ultramodern::renderer::SetupResult::GraphicsAPINotFound;
        case RT64::Application::SetupResult::GraphicsDeviceNotFound:
            return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
        default:
            return ultramodern::renderer::SetupResult::Success;
    }
}

ultramodern::renderer::GraphicsApi RT64RendererContext::get_chosen_api() const {
    return ultramodern::renderer::GraphicsApi::Vulkan;
}

bool RT64RendererContext::update_config(
    const ultramodern::renderer::GraphicsConfig&,
    const ultramodern::renderer::GraphicsConfig&)
{
    return true;
}

void RT64RendererContext::enable_instant_present() {
    // RT64 handles this internally via its present queue
}

void RT64RendererContext::send_dl(const OSTask* task) {
    uint64_t n = ++pimpl_->dl_count;

    if (!pimpl_->initialized || !pimpl_->app) {
        if (n <= 3) {
            fprintf(stderr, "[WPJ2/RT64] send_dl #%lu: SKIPPED (not initialized)\n",
                    (unsigned long)n);
        }
        return;
    }

    // The display list is in RDRAM at task->t.data_ptr (virtual address).
    // RT64's processDisplayLists expects the RDRAM-relative byte offset.
    // In recomp mode, virtual address 0x80XXXXXX maps to RDRAM offset
    // (vaddr - 0x80000000). RT64's loadUCodeGBI masks with 0xFFFFF8 which
    // also strips the 0x80 prefix, so we can pass the raw virtual address.
    uint32_t dl_start = (uint32_t)task->t.data_ptr - 0x80000000;
    uint32_t dl_end = dl_start + task->t.data_size;

    // Only log the first 3 display lists to avoid console spam.
    if (n <= 3) {
        fprintf(stderr, "[WPJ2/RT64] send_dl #%lu: type=%u start=0x%08X end=0x%08X size=%u\n",
                (unsigned long)n, task->t.type, dl_start, dl_end, task->t.data_size);
    }

    // Tell RT64 which GBI (F3D/F3DEX/F3DEX2) to use by reading the ucode
    // data from RDRAM. RT64 hashes the ucode to identify the microcode type.
    // Without this, hleGBI is null and the HLE display list parser crashes.
    // loadUCodeGBI is idempotent — it only re-detects when the ucode changes.
    uint32_t ucode_addr = (uint32_t)task->t.ucode;
    uint32_t ucode_data_addr = (uint32_t)task->t.ucode_data;
    pimpl_->app->interpreter->loadUCodeGBI(ucode_addr, ucode_data_addr, true);

    // processDisplayLists(memory, dlStartAddress, dlEndAddress, isHLE)
    // isHLE=true: RT64 interprets GBI display list commands (F3D/F3DEX2)
    // isHLE=false: RT64 interprets raw RDP commands (NOT what we want —
    //   the RSP graphics microcode is not recompiled, so the display list
    //   is still in GBI format, not RDP format)
    pimpl_->app->processDisplayLists(pimpl_->rdram, dl_start, dl_end, true);
}

void RT64RendererContext::update_screen() {
    uint64_t n = ++pimpl_->screen_count;

    if (!pimpl_->initialized || !pimpl_->app) {
        return;
    }

    if (n <= 3 || (n % 60) == 0) {
        fprintf(stderr, "[WPJ2/RT64] update_screen #%lu\n", (unsigned long)n);
    }

    pimpl_->app->updateScreen();
}

void RT64RendererContext::shutdown() {
    fprintf(stderr, "[WPJ2/RT64] shutdown\n");
    pimpl_->app.reset();
    pimpl_->initialized = false;
}

uint32_t RT64RendererContext::get_display_framerate() const {
    if (pimpl_->app && pimpl_->app->appWindow) {
        return pimpl_->app->appWindow->getRefreshRate();
    }
    return 60;
}

float RT64RendererContext::get_resolution_scale() const {
    return 1.0f;
}

std::unique_ptr<ultramodern::renderer::RendererContext>
create_rt64_render_context(uint8_t* rdram,
                           ultramodern::renderer::WindowHandle window_handle,
                           bool developer_mode)
{
    return std::make_unique<RT64RendererContext>(rdram, window_handle, developer_mode);
}

} // namespace wpj2
