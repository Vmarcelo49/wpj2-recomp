/*
 * WPJ2 Recomp - SDL2 Audio Backend implementation
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

    void close_locked() {
        if (g_device != 0) {
            SDL_CloseAudioDevice(g_device);
            g_device = 0;
        }
        g_initialized = false;
    }

    // SDL_AudioSpec expects "frames" = 1 sample for stereo s16 = 4 bytes.
    // For "samples" buffer size, we use 1/60th of a second worth of frames.
    uint16_t calc_samples(uint32_t freq) {
        // ~16ms of buffer (one frame at 60Hz)
        uint32_t s = freq / 60;
        if (s < 64) s = 64;
        if (s > 4096) s = 4096;
        return (uint16_t)s;
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
    fprintf(stderr, "[WPJ2/Audio] Opened device: %u Hz, %u channels, buffer=%u samples\n",
            (uint32_t)g_spec.freq, (uint32_t)g_spec.channels, (uint32_t)g_spec.samples);
}

void audio_queue_samples(int16_t* samples, size_t count) {
    if (!g_initialized) return;
    // count is in sample frames; SDL_QueueAudio expects bytes.
    size_t bytes = count * g_spec.channels * sizeof(int16_t);
    // To prevent unbounded queue growth (game running faster than hardware),
    // drop samples if the queue is already large (>200ms worth).
    size_t current = SDL_GetQueuedAudioSize(g_device);
    size_t cap = (g_spec.freq * g_spec.channels * sizeof(int16_t)) / 5; // 200ms
    if (current >= cap) {
        return; // drop
    }
    if (SDL_QueueAudio(g_device, samples, (Uint32)bytes) < 0) {
        fprintf(stderr, "[WPJ2/Audio] SDL_QueueAudio failed: %s\n", SDL_GetError());
    }
}

size_t audio_get_frames_remaining() {
    if (!g_initialized) return 1024; // dummy
    Uint32 queued = SDL_GetQueuedAudioSize(g_device);
    size_t bytes_per_frame = g_spec.channels * sizeof(int16_t);
    size_t total_frames = (g_spec.freq * g_spec.samples) / 60; // approx 1 frame of buffer
    size_t queued_frames = queued / bytes_per_frame;
    if (queued_frames >= total_frames) return 0;
    return total_frames - queued_frames;
}

} // namespace wpj2
