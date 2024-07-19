#ifndef SOUND_H
#define SOUND_H

#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <atomic>

#pragma comment(lib, "winmm.lib")

class Sound {
public:
    Sound() : isPlaying(false) {}

    void playRainSound() {
        if (!isPlaying.exchange(true)) {
            std::thread([this]() {
                PlaySound(TEXT("rain.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                }).detach();
        }
    }

    void playThunderSound() {
        if (!isPlaying.exchange(true)) {
            std::thread([this]() {
                PlaySound(TEXT("thunder.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                }).detach();
        }
    }
    void playPortalSound() {
        if (!isPlaying.exchange(true)) {
            std::thread([this]() {
                PlaySound(TEXT("portal.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                }).detach();
        }
    }

    void stopSound() {
        if (isPlaying.exchange(false)) {
            PlaySound(0, 0, 0);
        }
    }

private:
    std::atomic<bool> isPlaying;
};

#endif // SOUND_H
