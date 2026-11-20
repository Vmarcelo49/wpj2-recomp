/*
 * WPJ2 Recomp - RT64 Renderer Context
 *
 * Bridges ultramodern::renderer::RendererContext to RT64::Application.
 *
 * Phase 6 implementation:
 *   - Constructor creates RT64::Application with Core{RDRAM, DMEM, IMEM, regs, window}
 *   - send_dl    -> Application::processDisplayLists
 *   - update_screen -> Application::updateScreen
 *   - shutdown   -> Application destructor
 *
 * Register mapping:
 *   ultramodern::renderer::ViRegs*  -> RT64 Core's VI_*_REG pointers
 *   DPC registers are dummy (RT64 stores them but doesn't read them internally)
 *   MI_INTR_REG is a dummy (ultramodern handles SP/DP completion via message queues)
 *   checkInterrupts is a no-op (ultramodern handles interrupt dispatch)
 */

#ifndef WPJ2_RT64_RENDERER_HPP
#define WPJ2_RT64_RENDERER_HPP

#include "ultramodern/renderer_context.hpp"
#include "ultramodern/ultra64.h"

#include <memory>

namespace wpj2 {

class RT64RendererContext : public ultramodern::renderer::RendererContext {
public:
    RT64RendererContext(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode);
    ~RT64RendererContext() override;

    bool valid() override;
    ultramodern::renderer::SetupResult get_setup_result() const override;
    ultramodern::renderer::GraphicsApi get_chosen_api() const override;

    bool update_config(const ultramodern::renderer::GraphicsConfig& old_config,
                       const ultramodern::renderer::GraphicsConfig& new_config) override;
    void enable_instant_present() override;
    void send_dl(const OSTask* task) override;
    void update_screen() override;
    void shutdown() override;
    uint32_t get_display_framerate() const override;
    float get_resolution_scale() const override;

    // Toggle between integer scaling (default) and stretch-to-screen.
    // Returns true if integer scaling is now active, false if stretch.
    bool toggle_scaling();

    // Apply scaling mode selected by the launcher before the first frame.
    void set_scaling(bool integer_scaling);

private:
    struct Impl;
    std::unique_ptr<Impl> pimpl_;
};

std::unique_ptr<ultramodern::renderer::RendererContext>
create_rt64_render_context(uint8_t* rdram,
                           ultramodern::renderer::WindowHandle window_handle,
                           bool developer_mode);

} // namespace wpj2

#endif // WPJ2_RT64_RENDERER_HPP
