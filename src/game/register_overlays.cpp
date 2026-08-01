/*
 * WPJ2 Recomp - Overlay registration
 *
 * Includes the auto-generated recomp_overlays.inl (which defines
 * section_table[] and overlay_sections_by_index[]) and registers them
 * with librecomp::overlays at static init time.
 *
 * Without this, sections_info stays empty and get_function() always fails
 * because no function entries are loaded into func_map.
 */

#include "recomp.h"
#include "shims.h"
#include "funcs.h"
#include "librecomp/sections.h"
#include "librecomp/overlays.hpp"

// Include the generated arrays:
//   static SectionTableEntry section_table[];
//   const size_t num_sections;
//   static int overlay_sections_by_index[];
#include "recomp_overlays.inl"

// Static initializer that registers the overlay table at program start.
// This runs before main(), so by the time recomp::start() is called the
// sections are already known.
namespace {
struct OverlayRegistrar {
    OverlayRegistrar() {
        recomp::overlays::overlay_section_table_data_t sections{};
        sections.code_sections = section_table;
        sections.num_code_sections = ARRLEN(section_table);
        sections.total_num_sections = num_sections;

        recomp::overlays::overlays_by_index_t overlays{};
        overlays.table = overlay_sections_by_index;
        overlays.len = ARRLEN(overlay_sections_by_index);

        recomp::overlays::register_overlays(sections, overlays);
    }
};
static OverlayRegistrar g_overlays_registrar;
}
