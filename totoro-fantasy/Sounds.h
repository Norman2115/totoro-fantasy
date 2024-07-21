#pragma once
#include <string>
#include <map>
#include <AL/al.h>
#include <AL/alc.h>
#include "DebugSounds.h"

class Sounds {
public:
    Sounds() {
        if (!debug.initializeOpenAL(device, context)) {
            throw std::runtime_error("Failed to initialize OpenAL");
        }
    }

    ~Sounds() {
        debug.cleanupOpenAL(device, context, buffers, sources);
    }

    void loadSound(const std::string& soundName, const std::string& filename) {
        debug.loadSound(soundName, filename, buffers, sources);
    }

    void playSound(const std::string& soundName, bool loop = false) {
        auto it = sources.find(soundName);
        if (it != sources.end()) {
            ALint state;
            alGetSourcei(it->second, AL_SOURCE_STATE, &state);
            if (state == AL_PLAYING) {
                std::cerr << "Sound " << soundName << " is already playing." << std::endl;
                return;
            }

            if (loop) {
                alSourcei(it->second, AL_LOOPING, AL_TRUE);
            }
            else {
                alSourcei(it->second, AL_LOOPING, AL_FALSE);
            }

            alSourcePlay(it->second);
            debug.checkOpenALError("alSourcePlay");

            alGetSourcei(it->second, AL_SOURCE_STATE, &state);
            if (state != AL_PLAYING) {
                std::cerr << "Sound " << soundName << " failed to play. Current state: " << state << std::endl;
            }
        }
        else {
            std::cerr << "Sound " << soundName << " not found!" << std::endl;
        }
    }

    void stopSound(const std::string& soundName) {
        auto it = sources.find(soundName);
        if (it != sources.end()) {
            alSourceStop(it->second);
            debug.checkOpenALError("alSourceStop");
        }
        else {
            std::cerr << "Sound " << soundName << " not found!" << std::endl;
        }
    }

    void playDoorOpening() {
        playSound("doorOpening");
    }

    void stopDoorOpening() {
        stopSound("doorOpening");
    }

    void playThunderStorm() {
        playSound("thunderStorm", true); // Loop the sound
    }

    void stopThunderStorm() {
        stopSound("thunderStorm");
    }

    void playRain() {
        playSound("raining");
    }

    void stopRain() {
        stopSound("raining");
    }

    void playTeleport() {
        playSound("teleport");
    }

    void stopTeleport() {
        stopSound("teleport");
    }

    void playLanding() {
        playSound("landing");
    }

    void stopLanding() {
        stopSound("landing");
    }

    void playCrying() {
        playSound("crying");
    }

    void stopCrying() {
        stopSound("crying");
    }

    void playRunning() {
        playSound("running");
    }

    void stopRunning() {
        stopSound("running");
    }

    void playWind() {
        playSound("wind");
    }

    void stopWind() {
        stopSound("wind");
    }

    void playBackground() {
        playSound("background", true); // Loop the background sound
    }

    void stopBackground() {
        stopSound("background");
    }

private:
    ALCdevice* device;
    ALCcontext* context;
    std::map<std::string, ALuint> buffers;
    std::map<std::string, ALuint> sources;
    DebugSounds debug;
};

