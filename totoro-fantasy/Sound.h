#ifndef SOUND_H
#define SOUND_H

#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <atomic>
#include <map>
#include <string>
#include <mutex>
#include <chrono>

#pragma comment(lib, "winmm.lib")

using namespace std;

class Sound {
public:
    Sound() {}

    ~Sound() {
        stopAllSounds();
    }

    void playRainSound() {
        playSoundWithDelay("rain.wav", "rain", 0);
    }

    void playThunderSound() {
        playSoundWithDelay("thunder.wav", "thunder", 0);
    }

    void playPortalSound() {
        playSoundWithDelay("portal.wav", "portal", 0);
    }

    void playDoorSound() {
        playSoundWithDelay("door.wav", "door", 0);
    }

    void playRainSoundWithDelay(int delaySeconds) {
        playSoundWithDelay("rain.wav", "rain", delaySeconds);
    }

    void playThunderSoundWithDelay(int delaySeconds) {
        playSoundWithDelay("thunder.wav", "thunder", delaySeconds);
    }

    void playPortalSoundWithDelay(int delaySeconds) {
        playSoundWithDelay("portal.wav", "portal", delaySeconds);
    }

    void playDoorSoundWithDelay(int delaySeconds) {
        playSoundWithDelay("door.wav", "door", delaySeconds);
    }

    void playRainSoundForDuration(int durationSeconds) {
        playSoundForDuration("rain.wav", "rain", durationSeconds);
    }

    void playPortalSoundForDuration(int durationSeconds) {
        playSoundForDuration("portal.wav", "portal", durationSeconds);
    }

    void stopRainSound() {
        stopSound("rain");
    }

    void stopThunderSound() {
        stopSound("thunder");
    }

    void stopPortalSound() {
        stopSound("portal");
    }

    void stopDoorSound() {
        stopSound("door");
    }

    void stopAllSounds() {
        lock_guard<mutex> lock(mtx);
        for (auto& pair : soundThreads) {
            if (pair.second.joinable()) {
                pair.second.detach();
            }
        }
        PlaySound(0, 0, 0); // Stops all sounds
        soundThreads.clear();
    }

private:
    map<string, thread> soundThreads;
    mutex mtx;

    static wstring stringToWString(const string& str) {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
        wstring wstrTo(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
        return wstrTo;
    }

    static void playSoundHelper(const string& filename) {
        wstring wFilename = stringToWString(filename);
        PlaySound(wFilename.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }

    static void playSoundHelperWithDelay(const string& filename, int delaySeconds) {
        if (delaySeconds > 0) {
            this_thread::sleep_for(chrono::seconds(delaySeconds));
        }
        playSoundHelper(filename);
    }

    static void playSoundForDurationHelper(const string& filename, int durationSeconds) {
        playSoundHelper(filename);
        if (durationSeconds > 0) {
            this_thread::sleep_for(chrono::seconds(durationSeconds));
            PlaySound(0, 0, 0); // Stop sound after duration
        }
    }

    void playSoundWithDelay(const string& filename, const string& key, int delaySeconds) {
        lock_guard<mutex> lock(mtx);
        if (soundThreads.find(key) == soundThreads.end()) {
            soundThreads[key] = thread(playSoundHelperWithDelay, filename, delaySeconds);
        }
    }

    void playSoundForDuration(const string& filename, const string& key, int durationSeconds) {
        lock_guard<mutex> lock(mtx);
        if (soundThreads.find(key) == soundThreads.end()) {
            soundThreads[key] = thread(playSoundForDurationHelper, filename, durationSeconds);
        }
    }

    void stopSound(const string& key) {
        lock_guard<mutex> lock(mtx);
        auto it = soundThreads.find(key);
        if (it != soundThreads.end()) {
            PlaySound(0, 0, 0); // This stops all sounds. To stop a specific sound, you need a more advanced library.
            if (it->second.joinable()) {
                it->second.detach();
            }
            soundThreads.erase(it);
        }
    }
};

#endif // SOUND_H
