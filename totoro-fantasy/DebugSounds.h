#ifndef DEBUGSOUNDS_H
#define DEBUGSOUNDS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <AL/al.h>
#include <AL/alc.h>

class DebugSounds {
public:
    bool initializeOpenAL(ALCdevice*& device, ALCcontext*& context) {
        device = alcOpenDevice(nullptr); // Open default device
        if (!device) {
            std::cerr << "Failed to open default OpenAL device" << std::endl;
            return false;
        }
        std::cout << "OpenAL device opened successfully." << std::endl;

        context = alcCreateContext(device, nullptr);
        if (!alcMakeContextCurrent(context)) {
            std::cerr << "Failed to make OpenAL context current" << std::endl;
            return false;
        }
        std::cout << "OpenAL context created and made current." << std::endl;

        return true;
    }

    void cleanupOpenAL(ALCdevice*& device, ALCcontext*& context, std::map<std::string, ALuint>& buffers, std::map<std::string, ALuint>& sources) {
        for (auto& pair : buffers) {
            alDeleteBuffers(1, &pair.second);
        }
        for (auto& pair : sources) {
            alDeleteSources(1, &pair.second);
        }
        if (context) {
            alcDestroyContext(context);
        }
        if (device) {
            alcCloseDevice(device);
        }
    }

    void loadSound(const std::string& soundName, const std::string& filename, std::map<std::string, ALuint>& buffers, std::map<std::string, ALuint>& sources) {
        std::vector<char> bufferData;
        ALenum format;
        ALsizei freq;
        if (!loadWAVFile(filename, bufferData, format, freq)) {
            std::cerr << "Failed to load WAV file." << std::endl;
            return;
        }

        ALuint buffer;
        alGenBuffers(1, &buffer);
        checkOpenALError("alGenBuffers");

        alBufferData(buffer, format, bufferData.data(), static_cast<ALsizei>(bufferData.size()), freq);
        checkOpenALError("alBufferData");

        ALuint source;
        alGenSources(1, &source);
        checkOpenALError("alGenSources");

        alSourcei(source, AL_BUFFER, buffer);
        checkOpenALError("alSourcei");

        buffers[soundName] = buffer;
        sources[soundName] = source;
    }

    void checkOpenALError(const std::string& message) {
        ALenum error = alGetError();
        if (error != AL_NO_ERROR) {
            std::cerr << "OpenAL error (" << message << "): " << alGetString(error) << std::endl;
        } else {
            std::cout << "OpenAL (" << message << "): No error" << std::endl;
        }
    }

private:
    bool loadWAVFile(const std::string& filename, std::vector<char>& buffer, ALenum& format, ALsizei& freq) {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Failed to open WAV file: " << filename << std::endl;
            return false;
        }

        char chunkId[4];
        file.read(chunkId, 4);
        if (std::strncmp(chunkId, "RIFF", 4) != 0) {
            std::cerr << "Invalid WAV file: " << filename << std::endl;
            return false;
        }

        file.seekg(20);
        uint16_t audioFormat;
        file.read(reinterpret_cast<char*>(&audioFormat), sizeof(audioFormat));
        if (audioFormat != 1) { // PCM format
            std::cerr << "Unsupported WAV format: " << filename << std::endl;
            return false;
        }

        uint16_t numChannels;
        file.read(reinterpret_cast<char*>(&numChannels), sizeof(numChannels));
        std::cout << "Number of Channels: " << numChannels << std::endl;

        file.read(reinterpret_cast<char*>(&freq), sizeof(freq));
        std::cout << "Frequency: " << freq << " Hz" << std::endl;

        file.seekg(34);
        uint16_t bitsPerSample;
        file.read(reinterpret_cast<char*>(&bitsPerSample), sizeof(bitsPerSample));
        std::cout << "Bits per Sample: " << bitsPerSample << std::endl;

        file.seekg(40);
        uint32_t dataSize;
        file.read(reinterpret_cast<char*>(&dataSize), sizeof(dataSize));
        std::cout << "Data Size: " << dataSize << " bytes" << std::endl;

        // Sanity check for data size
        const uint32_t MAX_DATA_SIZE = 100000000; // 100 MB limit for sanity check
        if (dataSize > MAX_DATA_SIZE) {
            std::cerr << "Data size exceeds maximum allowed size: " << dataSize << " bytes" << std::endl;
            return false;
        }

        buffer.resize(dataSize);
        file.read(buffer.data(), dataSize);

        if (numChannels == 1) {
            format = (bitsPerSample == 8) ? AL_FORMAT_MONO8 : AL_FORMAT_MONO16;
        } else {
            format = (bitsPerSample == 8) ? AL_FORMAT_STEREO8 : AL_FORMAT_STEREO16;
        }

        return true;
    }
};

#endif // DEBUGSOUNDS_H
