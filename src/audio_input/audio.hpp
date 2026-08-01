/*
 * WPJ2 Recomp - SDL2 Audio Backend
 *
 * Implements ultramodern::audio_callbacks_t using SDL2's queue-based audio.
 * - set_frequency  -> reconfigure SDL_AudioSpec (closes + reopens device)
 * - queue_samples  -> SDL_QueueAudio (blocking semantics emulated via size cap)
 * - get_frames_remaining -> SDL_GetQueuedAudioSize / 4 (stereo s16)
 *
 * Phase 5 baseline: single-threaded, no resampling (assumes game freq matches
 * hardware or SDL resamples internally — SDL_AudioCVT not used yet).
 */

#ifndef WPJ2_AUDIO_HPP
#define WPJ2_AUDIO_HPP

#include <cstdint>
#include <cstddef>

#include "ultramodern/ultramodern.hpp"

namespace wpj2 {

void audio_set_frequency(uint32_t freq);
void audio_queue_samples(int16_t* samples, size_t count);
size_t audio_get_frames_remaining();

} // namespace wpj2

#endif // WPJ2_AUDIO_HPP
