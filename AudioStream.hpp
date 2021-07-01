#pragma once
#include <audioclient.h>
#include <stdint.h>
#include <vector>
class AudioStream {
    private:
        IAudioClient* audioClient;
        IAudioCaptureClient* captureClient;
    public:
        AudioStream();
        std::vector<int16_t> getFrame();
};

