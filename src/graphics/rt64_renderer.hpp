/*
 * WPJ2 Recomp - RT64 Renderer Context
 *
 * Bridges ultramodern::renderer::RendererContext to RT64::Application.
 *
 * Phase 4+6 implementation:
 *   - send_dl    -> Application::processDisplayLists
 *   - update_screen -> Application::updateScreen
 *   - shutdown   -> Application destructor chain
 *
 * NOTE: This is a minimal stub that creates the RT64 Application on first
 * send_dl. Full RT64 init (Vulkan device, swapchain) requires the SDL window
 * to be passed in via ApplicationWindow::setup. We use core.window = our
 * SDL_Window* and let RT64 handle device creation.
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
