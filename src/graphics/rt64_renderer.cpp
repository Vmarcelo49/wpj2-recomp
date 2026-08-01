/*
 * WPJ2 Recomp - RT64 Renderer Context (stub for Phase 4 bring-up)
 *
 * Real RT64 integration requires:
 *   1. RT64::Application with Core{ RDRAM, DMEM, IMEM, MI_INTR_REG, DPC_*_REG,
 *      VI_*_REG, checkInterrupts, window }
 *   2. setup(threadId) to create Vulkan device + swapchain
 *   3. processDisplayLists(rdram, dlStartAddr, dlEndAddr, isHLE=false)
 *   4. updateScreen() to present framebuffer
 *
 * For Phase 4 bring-up we use a stub that:
 *   - Logs every send_dl/update_screen call
 *   - Reports success so the game's boot sequence can proceed
 *   - Lets us verify the ultramodern scheduler + RSP dispatch work
 *
 * Real RT64 wiring follows in Phase 6 once boot park is fixed.
 */

#include "rt64_renderer.hpp"

#include <cstdio>
#include <atomic>

namespace wpj2 {

struct RT64RendererContext::Impl {
    uint8_t* rdram;
    ultramodern::renderer::WindowHandle window;
    bool developer_mode;
    std::atomic<uint64_t> dl_count{0};
    std::atomic<uint64_t> screen_count{0};
    bool valid_ = true;
};

RT64RendererContext::RT64RendererContext(uint8_t* rdram,
                                         ultramodern::renderer::WindowHandle window_handle,
                                         bool developer_mode)
    : pimpl_(std::make_unique<Impl>())
{
    pimpl_->rdram = rdram;
    pimpl_->window = window_handle;
    pimpl_->developer_mode = developer_mode;
    fprintf(stderr, "[WPJ2/RT64] RendererContext created (rdram=%p, window=%p, dev=%d)\n",
            (void*)rdram, (void*)window_handle, developer_mode);
}

RT64RendererContext::~RT64RendererContext() {
    fprintf(stderr, "[WPJ2/RT64] ~RendererContext (DLs=%lu, screens=%lu)\n",
            (unsigned long)pimpl_->dl_count.load(),
            (unsigned long)pimpl_->screen_count.load());
}

bool RT64RendererContext::valid() { return pimpl_->valid_; }

ultramodern::renderer::SetupResult RT64RendererContext::get_setup_result() const {
    return ultramodern::renderer::SetupResult::Success;
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
    // No-op for stub
}

void RT64RendererContext::send_dl(const OSTask* task) {
    uint64_t n = ++pimpl_->dl_count;
    if (n <= 5 || (n % 100) == 0) {
        fprintf(stderr, "[WPJ2/RT64] send_dl #%lu: type=%u data_ptr=0x%08X size=%u\n",
                (unsigned long)n, task->t.type,
                (uint32_t)task->t.data_ptr, task->t.data_size);
    }
    // TODO Phase 6: actually call rt64_app->processDisplayLists(rdram, ...).
    // For now we just report completion implicitly via dp_complete() being
    // called by ultramodern::events after this returns.
}

void RT64RendererContext::update_screen() {
    uint64_t n = ++pimpl_->screen_count;
    if (n <= 3 || (n % 60) == 0) {
        fprintf(stderr, "[WPJ2/RT64] update_screen #%lu\n", (unsigned long)n);
    }
    // TODO Phase 6: rt64_app->updateScreen()
}

void RT64RendererContext::shutdown() {
    fprintf(stderr, "[WPJ2/RT64] shutdown\n");
}

uint32_t RT64RendererContext::get_display_framerate() const { return 60; }
float    RT64RendererContext::get_resolution_scale() const { return 1.0f; }

std::unique_ptr<ultramodern::renderer::RendererContext>
create_rt64_render_context(uint8_t* rdram,
                           ultramodern::renderer::WindowHandle window_handle,
                           bool developer_mode)
{
    return std::make_unique<RT64RendererContext>(rdram, window_handle, developer_mode);
}

} // namespace wpj2
