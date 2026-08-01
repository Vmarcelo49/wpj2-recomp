/*
 * WPJ2 Recomp - SDL2 Audio Backend implementation
 *
 * Uses SDL2's queue-based audio API. The game queues audio frames via
 * osAiSetNextBuffer_recomp -> ultramodern::queue_audio_buffer -> our
 * audio_queue_samples. We report remaining capacity via audio_get_frames_remaining
 * so the game knows when to queue more.
 *
 * Buffer sizing: we use ~50ms of buffer (3 frames at 60Hz) to avoid underruns
 * that cause crackling. The game-side AI DMA typically queues ~1 frame (16ms)
 * at a time, so having 3x headroom prevents the SDL queue from emptying
 * between game audio updates.
 */

#include "audio.hpp"

#include <SDL2/SDL.h>

#include <cstdio>
#include <cstring>
#include <mutex>
#include <atomic>

namespace wpj2 {

namespace {
    std::mutex g_audio_mtx;
    SDL_AudioDeviceID g_device = 0;
    SDL_AudioSpec g_spec{};
    std::atomic<uint32_t> g_freq{0};
    bool g_initialized = false;

    // Target buffer size: ~50ms of audio (3 frames at 60Hz).
    // Must be a power of 2 for SDL2's internal ring buffer efficiency.
    uint16_t calc_samples(uint32_t freq) {
        // 50ms = freq/20 frames
        uint32_t s = freq / 20;
        // Round up to next power of 2 (SDL prefers this)
        uint32_t pow2 = 1;
        while (pow2 < s) pow2 <<= 1;
        if (pow2 < 256) pow2 = 256;     // minimum 256 samples
        if (pow2 > 8192) pow2 = 8192;   // maximum 8192 samples
        return (uint16_t)pow2;
    }

    // Maximum queued audio before we start dropping (150ms).
    // This prevents unbounded latency if the game queues faster than
    // the hardware plays. 150ms gives 3x our buffer headroom.
    size_t max_queued_bytes() {
        return (size_t)(g_spec.freq * g_spec.channels * sizeof(int16_t)) * 3 / 20; // 150ms
    }

    void close_locked() {
        if (g_device != 0) {
            SDL_CloseAudioDevice(g_device);
            g_device = 0;
        }
        g_initialized = false;
    }
}

void audio_set_frequency(uint32_t freq) {
    std::lock_guard<std::mutex> lock(g_audio_mtx);
    if (g_freq.load() == freq && g_initialized) return;

    close_locked();

    SDL_AudioSpec want{};
    want.freq = (int)freq;
    want.format = AUDIO_S16SYS;
    want.channels = 2;
    want.samples = calc_samples(freq);
    want.callback = nullptr; // use SDL_QueueAudio

    g_device = SDL_OpenAudioDevice(nullptr, 0, &want, &g_spec, 0);
    if (g_device == 0) {
        fprintf(stderr, "[WPJ2/Audio] SDL_OpenAudioDevice(%u Hz) failed: %s\n",
                freq, SDL_GetError());
        g_freq.store(0);
        return;
    }

    SDL_PauseAudioDevice(g_device, 0); // unpause
    g_freq.store(freq);
    g_initialized = true;
    fprintf(stderr, "[WPJ2/Audio] Opened device: %u Hz, %u channels, buffer=%u samples (%.1fms)\n",
            (uint32_t)g_spec.freq, (uint32_t)g_spec.channels, (uint32_t)g_spec.samples,
            (float)g_spec.samples * 1000.0f / g_spec.freq);
}

void audio_queue_samples(int16_t* samples, size_t count) {
    if (!g_initialized) return;
    // count is in sample frames; SDL_QueueAudio expects bytes.
    size_t bytes = count * g_spec.channels * sizeof(int16_t);

    // If the queue is already at max capacity, drop the OLDEST samples by
    // dequeuing them, then queue the new ones. This prevents the game from
    // stalling on audio (which would cause a boot park) while keeping
    // latency bounded.
    size_t current = SDL_GetQueuedAudioSize(g_device);
    size_t max_bytes = max_queued_bytes();
    if (current + bytes > max_bytes) {
        // Drop enough old samples to make room
        size_t excess = (current + bytes) - max_bytes;
        // SDL_DequeueAudio consumes from the front (oldest) of the queue
        static thread_local uint8_t drop_buf[8192];
        while (excess > 0) {
            size_t to_read = std::min(excess, sizeof(drop_buf));
            SDL_DequeueAudio(g_device, drop_buf, (Uint32)to_read);
            excess -= to_read;
        }
    }

    if (SDL_QueueAudio(g_device, samples, (Uint32)bytes) < 0) {
        fprintf(stderr, "[WPJ2/Audio] SDL_QueueAudio failed: %s\n", SDL_GetError());
    }
}

size_t audio_get_frames_remaining() {
    if (!g_initialized) return 2048; // dummy
    Uint32 queued = SDL_GetQueuedAudioSize(g_device);
    size_t bytes_per_frame = g_spec.channels * sizeof(int16_t);
    size_t queued_frames = queued / bytes_per_frame;

    // Report how many more frames we can accept before hitting the cap.
    // The game uses this to decide if it should queue more audio.
    size_t max_frames = max_queued_bytes() / bytes_per_frame;
    if (queued_frames >= max_frames) return 0;
    return max_frames - queued_frames;
}

} // namespace wpj2
