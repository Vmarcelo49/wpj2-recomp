/*
 * WPJ2 Recomp - RSP microcode dispatcher
 *
 * ultramodern's rsp::run_task callback (registered via recomp::rsp::set_callbacks
 * inside recomp::start) calls our get_rsp_microcode(task) to obtain the
 * recompiled RSP function pointer for the given task type.
 *
 * WPJ2 uses:
 *   M_AUDTASK (2) -> aspMain (recompiled via RSPRecomp in src/rsp/generated/aspMain.c)
 *   M_GFXTASK (1) -> nullptr  (graphics tasks are HLE'd by RT64, not RSP-recompiled)
 *
 * Returning nullptr for graphics is correct: librecomp's run_task will print
 * an error and abort, but in our integration RT64 handles GFXTASK via the
 * SpTaskAction path in events.cpp -> send_dl -> RT64RendererContext::send_dl.
 * The RSP run_task callback is only invoked for non-graphics tasks because
 * the events.cpp SpTaskAction path calls sp_complete() BEFORE calling send_dl,
 * meaning the game sees "SP done" and only waits on "DP done" (which RT64
 * triggers via dp_complete()).
 *
 * However, the task_thread_func in events.cpp DOES call rsp::run_task for ALL
 * tasks submitted via submit_rsp_task. Looking at sp.cpp (librecomp), only
 * osSpTaskStartGo_recomp calls submit_rsp_task — so EVERY task goes through
 * rsp::run_task. We must therefore:
 *   - Return aspMain for M_AUDTASK
 *   - Return a dummy "do nothing and break" function for M_GFXTASK so that
 *     librecomp::rsp::run_task reports Broke and the SP message fires.
 *     The actual GFX work is then done by RT64 via send_dl.
 */

#ifndef WPJ2_RSP_DISPATCH_HPP
#define WPJ2_RSP_DISPATCH_HPP

// librecomp/rsp.hpp must be included explicitly because the PCH
// (include/generated/wpj2_pch.h) only pulls recomp.h + shims.h + macros.h.
#include "librecomp/rsp.hpp"
#include "ultramodern/ultra64.h"

namespace wpj2 {

// Returns the recompiled RSP ucode function for the given task, or nullptr
// if no ucode matches. Per recomp::rsp::callbacks_t contract, returning
// nullptr causes librecomp to print an error and exit.
RspUcodeFunc* get_rsp_microcode(const OSTask* task);

// Stub function used for M_GFXTASK: runs no RSP code and immediately returns
// RspExitReason::Broke so that librecomp::rsp::run_task is happy and fires
// the SP completion message. Actual GFX rendering is handled by RT64 via
// the RendererContext::send_dl path.
RspExitReason gfx_task_nop(uint8_t* rdram, uint32_t ucode_addr);

} // namespace wpj2

#endif // WPJ2_RSP_DISPATCH_HPP
