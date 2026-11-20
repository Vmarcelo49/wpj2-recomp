/*
 * WPJ2 Recomp - SDL2 Audio Backend implementation
 *
 * Uses SDL2's queue-based audio API.
 *
 * IMPORTANT: ultramodern's queue_samples callback receives (int16_t* samples, size_t count)
 * where `count` is the TOTAL number of int16_t samples (L+R combined), NOT the number
 * of stereo frames. For stereo audio, 1 frame = 2 samples.
 *
 * get_frames_remaining must return the number of STEREO FRAMES remaining (not samples).
 * ultramodern multiplies this by 2*sizeof(int16_t) to get bytes.
 */

#include "audio.hpp"

#include <SDL2/SDL.h>

#include <cstdio>
#include <cstring>
#include <mutex>
#include <atomic>
#include <algorithm>
#include <vector>

namespace wpj2 {

namespace {
    std::mutex g_audio_mtx;
    SDL_AudioDeviceID g_device = 0;
    SDL_AudioSpec g_spec{};
    std::atomic<uint32_t> g_freq{0};
    std::atomic<int> g_volume{100};
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

    // count is the TOTAL number of int16_t samples (L+R combined).
    // For stereo: bytes = count * sizeof(int16_t)
    // (NOT count * channels * sizeof(int16_t) — that would double the data!)
    size_t bytes = count * sizeof(int16_t);

    // If the queue is over capacity, dequeue oldest samples to make room.
    size_t current = SDL_GetQueuedAudioSize(g_device);
    size_t max_bytes = max_queued_bytes();
    if (current + bytes > max_bytes) {
        size_t excess = (current + bytes) - max_bytes;
        static thread_local uint8_t drop_buf[8192];
        while (excess > 0) {
            size_t to_read = std::min(excess, sizeof(drop_buf));
            SDL_DequeueAudio(g_device, drop_buf, (Uint32)to_read);
            excess -= to_read;
        }
    }

    const int volume = g_volume.load();
    if (volume < 100) {
        std::vector<int16_t> scaled(count);
        const int numerator = std::clamp(volume, 0, 100);
        for (size_t i = 0; i < count; ++i) {
            scaled[i] = static_cast<int16_t>((int32_t(samples[i]) * numerator) / 100);
        }
        if (SDL_QueueAudio(g_device, scaled.data(), (Uint32)(scaled.size() * sizeof(int16_t))) < 0) {
            fprintf(stderr, "[WPJ2/Audio] SDL_QueueAudio failed: %s\n", SDL_GetError());
        }
        return;
    }

    if (SDL_QueueAudio(g_device, samples, (Uint32)bytes) < 0) {
        fprintf(stderr, "[WPJ2/Audio] SDL_QueueAudio failed: %s\n", SDL_GetError());
    }
}

void audio_set_volume(int volume) {
    g_volume.store(std::clamp(volume, 0, 100));
}

size_t audio_get_frames_remaining() {
    if (!g_initialized) return 2048;

    Uint32 queued = SDL_GetQueuedAudioSize(g_device);
    size_t bytes_per_frame = g_spec.channels * sizeof(int16_t); // 4 bytes per stereo frame
    size_t queued_frames = queued / bytes_per_frame;

    // Report remaining FRAMES (not samples) before hitting the cap.
    size_t max_frames = max_queued_bytes() / bytes_per_frame;
    if (queued_frames >= max_frames) return 0;
    return max_frames - queued_frames;
}

} // namespace wpj2
